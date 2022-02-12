static int tmp007_read_temperature(struct tmp007_data *data, u8 reg)
{
s32 ret;
int tries = 50;
while (tries-- > 0) {
ret = i2c_smbus_read_word_swapped(data->client,
TMP007_STATUS);
if (ret < 0)
return ret;
if ((ret & TMP007_STATUS_CONV_READY) &&
!(ret & TMP007_STATUS_DATA_VALID))
break;
msleep(100);
}
if (tries < 0)
return -EIO;
return i2c_smbus_read_word_swapped(data->client, reg);
}
static int tmp007_powerdown(struct tmp007_data *data)
{
return i2c_smbus_write_word_swapped(data->client, TMP007_CONFIG,
data->config & ~TMP007_CONFIG_CONV_EN);
}
static int tmp007_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *channel, int *val,
int *val2, long mask)
{
struct tmp007_data *data = iio_priv(indio_dev);
s32 ret;
int conv_rate;
switch (mask) {
case IIO_CHAN_INFO_RAW:
switch (channel->channel2) {
case IIO_MOD_TEMP_AMBIENT:
ret = i2c_smbus_read_word_swapped(data->client, TMP007_TDIE);
if (ret < 0)
return ret;
break;
case IIO_MOD_TEMP_OBJECT:
ret = tmp007_read_temperature(data, TMP007_TOBJECT);
if (ret < 0)
return ret;
break;
default:
return -EINVAL;
}
*val = sign_extend32(ret, 15) >> TMP007_TEMP_SHIFT;
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
*val = 31;
*val2 = 250000;
return IIO_VAL_INT_PLUS_MICRO;
case IIO_CHAN_INFO_SAMP_FREQ:
conv_rate = (data->config & TMP007_CONFIG_CR_MASK)
>> TMP007_CONFIG_CR_SHIFT;
*val = tmp007_avgs[conv_rate][0];
*val2 = tmp007_avgs[conv_rate][1];
return IIO_VAL_INT_PLUS_MICRO;
default:
return -EINVAL;
}
}
static int tmp007_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *channel, int val,
int val2, long mask)
{
struct tmp007_data *data = iio_priv(indio_dev);
int i;
u16 tmp;
if (mask == IIO_CHAN_INFO_SAMP_FREQ) {
for (i = 0; i < ARRAY_SIZE(tmp007_avgs); i++) {
if ((val == tmp007_avgs[i][0]) &&
(val2 == tmp007_avgs[i][1])) {
tmp = data->config & ~TMP007_CONFIG_CR_MASK;
tmp |= (i << TMP007_CONFIG_CR_SHIFT);
return i2c_smbus_write_word_swapped(data->client,
TMP007_CONFIG,
data->config = tmp);
}
}
}
return -EINVAL;
}
static bool tmp007_identify(struct i2c_client *client)
{
int manf_id, dev_id;
manf_id = i2c_smbus_read_word_swapped(client, TMP007_MANUFACTURER_ID);
if (manf_id < 0)
return false;
dev_id = i2c_smbus_read_word_swapped(client, TMP007_DEVICE_ID);
if (dev_id < 0)
return false;
return (manf_id == TMP007_MANUFACTURER_MAGIC && dev_id == TMP007_DEVICE_MAGIC);
}
static int tmp007_probe(struct i2c_client *client,
const struct i2c_device_id *tmp007_id)
{
struct tmp007_data *data;
struct iio_dev *indio_dev;
int ret;
u16 status;
if (!i2c_check_functionality(client->adapter, I2C_FUNC_SMBUS_WORD_DATA))
return -EOPNOTSUPP;
if (!tmp007_identify(client)) {
dev_err(&client->dev, "TMP007 not found\n");
return -ENODEV;
}
indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*data));
if (!indio_dev)
return -ENOMEM;
data = iio_priv(indio_dev);
i2c_set_clientdata(client, indio_dev);
data->client = client;
indio_dev->dev.parent = &client->dev;
indio_dev->name = "tmp007";
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->info = &tmp007_info;
indio_dev->channels = tmp007_channels;
indio_dev->num_channels = ARRAY_SIZE(tmp007_channels);
ret = i2c_smbus_read_word_swapped(data->client, TMP007_CONFIG);
if (ret < 0)
return ret;
data->config = ret;
data->config |= (TMP007_CONFIG_CONV_EN | TMP007_CONFIG_COMP_EN | TMP007_CONFIG_TC_EN);
ret = i2c_smbus_write_word_swapped(data->client, TMP007_CONFIG,
data->config);
if (ret < 0)
return ret;
ret = i2c_smbus_read_word_swapped(data->client, TMP007_STATUS_MASK);
if (ret < 0)
goto error_powerdown;
status = ret;
status |= (TMP007_STATUS_CONV_READY | TMP007_STATUS_DATA_VALID);
ret = i2c_smbus_write_word_swapped(data->client, TMP007_STATUS_MASK, status);
if (ret < 0)
goto error_powerdown;
return iio_device_register(indio_dev);
error_powerdown:
tmp007_powerdown(data);
return ret;
}
static int tmp007_remove(struct i2c_client *client)
{
struct iio_dev *indio_dev = i2c_get_clientdata(client);
struct tmp007_data *data = iio_priv(indio_dev);
iio_device_unregister(indio_dev);
tmp007_powerdown(data);
return 0;
}
static int tmp007_suspend(struct device *dev)
{
struct tmp007_data *data = iio_priv(i2c_get_clientdata(
to_i2c_client(dev)));
return tmp007_powerdown(data);
}
static int tmp007_resume(struct device *dev)
{
struct tmp007_data *data = iio_priv(i2c_get_clientdata(
to_i2c_client(dev)));
return i2c_smbus_write_word_swapped(data->client, TMP007_CONFIG,
data->config | TMP007_CONFIG_CONV_EN);
}
