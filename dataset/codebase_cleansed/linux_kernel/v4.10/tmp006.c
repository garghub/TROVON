static int tmp006_read_measurement(struct tmp006_data *data, u8 reg)
{
s32 ret;
int tries = 50;
while (tries-- > 0) {
ret = i2c_smbus_read_word_swapped(data->client,
TMP006_CONFIG);
if (ret < 0)
return ret;
if (ret & TMP006_CONFIG_DRDY)
break;
msleep(100);
}
if (tries < 0)
return -EIO;
return i2c_smbus_read_word_swapped(data->client, reg);
}
static int tmp006_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *channel, int *val,
int *val2, long mask)
{
struct tmp006_data *data = iio_priv(indio_dev);
s32 ret;
int cr;
switch (mask) {
case IIO_CHAN_INFO_RAW:
if (channel->type == IIO_VOLTAGE) {
ret = tmp006_read_measurement(data, TMP006_VOBJECT);
if (ret < 0)
return ret;
*val = sign_extend32(ret, 15);
} else if (channel->type == IIO_TEMP) {
ret = tmp006_read_measurement(data, TMP006_TAMBIENT);
if (ret < 0)
return ret;
*val = sign_extend32(ret, 15) >> TMP006_TAMBIENT_SHIFT;
} else {
break;
}
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
if (channel->type == IIO_VOLTAGE) {
*val = 0;
*val2 = 156250;
} else if (channel->type == IIO_TEMP) {
*val = 31;
*val2 = 250000;
} else {
break;
}
return IIO_VAL_INT_PLUS_MICRO;
case IIO_CHAN_INFO_SAMP_FREQ:
cr = (data->config & TMP006_CONFIG_CR_MASK)
>> TMP006_CONFIG_CR_SHIFT;
*val = tmp006_freqs[cr][0];
*val2 = tmp006_freqs[cr][1];
return IIO_VAL_INT_PLUS_MICRO;
default:
break;
}
return -EINVAL;
}
static int tmp006_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int val,
int val2,
long mask)
{
struct tmp006_data *data = iio_priv(indio_dev);
int i;
if (mask != IIO_CHAN_INFO_SAMP_FREQ)
return -EINVAL;
for (i = 0; i < ARRAY_SIZE(tmp006_freqs); i++)
if ((val == tmp006_freqs[i][0]) &&
(val2 == tmp006_freqs[i][1])) {
data->config &= ~TMP006_CONFIG_CR_MASK;
data->config |= i << TMP006_CONFIG_CR_SHIFT;
return i2c_smbus_write_word_swapped(data->client,
TMP006_CONFIG,
data->config);
}
return -EINVAL;
}
static bool tmp006_check_identification(struct i2c_client *client)
{
int mid, did;
mid = i2c_smbus_read_word_swapped(client, TMP006_MANUFACTURER_ID);
if (mid < 0)
return false;
did = i2c_smbus_read_word_swapped(client, TMP006_DEVICE_ID);
if (did < 0)
return false;
return mid == TMP006_MANUFACTURER_MAGIC && did == TMP006_DEVICE_MAGIC;
}
static int tmp006_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct iio_dev *indio_dev;
struct tmp006_data *data;
int ret;
if (!i2c_check_functionality(client->adapter, I2C_FUNC_SMBUS_WORD_DATA))
return -EOPNOTSUPP;
if (!tmp006_check_identification(client)) {
dev_err(&client->dev, "no TMP006 sensor\n");
return -ENODEV;
}
indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*data));
if (!indio_dev)
return -ENOMEM;
data = iio_priv(indio_dev);
i2c_set_clientdata(client, indio_dev);
data->client = client;
indio_dev->dev.parent = &client->dev;
indio_dev->name = dev_name(&client->dev);
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->info = &tmp006_info;
indio_dev->channels = tmp006_channels;
indio_dev->num_channels = ARRAY_SIZE(tmp006_channels);
ret = i2c_smbus_read_word_swapped(data->client, TMP006_CONFIG);
if (ret < 0)
return ret;
data->config = ret;
return iio_device_register(indio_dev);
}
static int tmp006_powerdown(struct tmp006_data *data)
{
return i2c_smbus_write_word_swapped(data->client, TMP006_CONFIG,
data->config & ~TMP006_CONFIG_MOD_MASK);
}
static int tmp006_remove(struct i2c_client *client)
{
struct iio_dev *indio_dev = i2c_get_clientdata(client);
iio_device_unregister(indio_dev);
tmp006_powerdown(iio_priv(indio_dev));
return 0;
}
static int tmp006_suspend(struct device *dev)
{
struct iio_dev *indio_dev = i2c_get_clientdata(to_i2c_client(dev));
return tmp006_powerdown(iio_priv(indio_dev));
}
static int tmp006_resume(struct device *dev)
{
struct tmp006_data *data = iio_priv(i2c_get_clientdata(
to_i2c_client(dev)));
return i2c_smbus_write_word_swapped(data->client, TMP006_CONFIG,
data->config | TMP006_CONFIG_MOD_MASK);
}
