static int us5182d_get_als(struct us5182d_data *data)
{
int ret;
unsigned long result;
ret = i2c_smbus_read_word_data(data->client,
US5182D_REG_ADL);
if (ret < 0)
return ret;
result = ret * data->ga / US5182D_GA_RESOLUTION;
if (result > 0xffff)
result = 0xffff;
return result;
}
static int us5182d_set_opmode(struct us5182d_data *data, u8 mode)
{
int ret;
ret = i2c_smbus_read_byte_data(data->client, US5182D_REG_CFG0);
if (ret < 0)
return ret;
ret = ret | US5182D_CFG0_ONESHOT_EN;
ret = ret & ~US5182D_OPMODE_MASK;
ret = ret | (mode << US5182D_OPMODE_SHIFT);
ret = i2c_smbus_write_byte_data(data->client, US5182D_REG_CFG0, ret);
if (ret < 0)
return ret;
if (mode == data->opmode)
return 0;
ret = i2c_smbus_write_byte_data(data->client, US5182D_REG_MODE_STORE,
US5182D_STORE_MODE);
if (ret < 0)
return ret;
data->opmode = mode;
msleep(US5182D_OPSTORE_SLEEP_TIME);
return 0;
}
static int us5182d_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan, int *val,
int *val2, long mask)
{
struct us5182d_data *data = iio_priv(indio_dev);
int ret;
switch (mask) {
case IIO_CHAN_INFO_RAW:
switch (chan->type) {
case IIO_LIGHT:
mutex_lock(&data->lock);
ret = us5182d_set_opmode(data, US5182D_OPMODE_ALS);
if (ret < 0)
goto out_err;
ret = us5182d_get_als(data);
if (ret < 0)
goto out_err;
mutex_unlock(&data->lock);
*val = ret;
return IIO_VAL_INT;
case IIO_PROXIMITY:
mutex_lock(&data->lock);
ret = us5182d_set_opmode(data, US5182D_OPMODE_PX);
if (ret < 0)
goto out_err;
ret = i2c_smbus_read_word_data(data->client,
US5182D_REG_PDL);
if (ret < 0)
goto out_err;
mutex_unlock(&data->lock);
*val = ret;
return IIO_VAL_INT;
default:
return -EINVAL;
}
case IIO_CHAN_INFO_SCALE:
ret = i2c_smbus_read_byte_data(data->client, US5182D_REG_CFG1);
if (ret < 0)
return ret;
*val = 0;
*val2 = us5182d_scales[ret & US5182D_AGAIN_MASK];
return IIO_VAL_INT_PLUS_MICRO;
default:
return -EINVAL;
}
return -EINVAL;
out_err:
mutex_unlock(&data->lock);
return ret;
}
static int us5182d_update_dark_th(struct us5182d_data *data, int index)
{
__be16 dark_th = cpu_to_be16(data->us5182d_dark_ths[index]);
int ret;
ret = i2c_smbus_write_byte_data(data->client, US5182D_REG_UDARK_TH,
((u8 *)&dark_th)[0]);
if (ret < 0)
return ret;
return i2c_smbus_write_byte_data(data->client, US5182D_REG_UDARK_TH + 1,
((u8 *)&dark_th)[1]);
}
static int us5182d_apply_scale(struct us5182d_data *data, int index)
{
int ret;
ret = i2c_smbus_read_byte_data(data->client, US5182D_REG_CFG1);
if (ret < 0)
return ret;
ret = ret & (~US5182D_AGAIN_MASK);
ret |= index;
ret = i2c_smbus_write_byte_data(data->client, US5182D_REG_CFG1, ret);
if (ret < 0)
return ret;
return us5182d_update_dark_th(data, index);
}
static int us5182d_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan, int val,
int val2, long mask)
{
struct us5182d_data *data = iio_priv(indio_dev);
int ret, i;
switch (mask) {
case IIO_CHAN_INFO_SCALE:
if (val != 0)
return -EINVAL;
for (i = 0; i < ARRAY_SIZE(us5182d_scales); i++)
if (val2 == us5182d_scales[i]) {
mutex_lock(&data->lock);
ret = us5182d_apply_scale(data, i);
mutex_unlock(&data->lock);
return ret;
}
break;
default:
return -EINVAL;
}
return -EINVAL;
}
static int us5182d_reset(struct iio_dev *indio_dev)
{
struct us5182d_data *data = iio_priv(indio_dev);
return i2c_smbus_write_byte_data(data->client, US5182D_REG_CFG3,
US5182D_RESET_CHIP);
}
static int us5182d_init(struct iio_dev *indio_dev)
{
struct us5182d_data *data = iio_priv(indio_dev);
int i, ret;
ret = us5182d_reset(indio_dev);
if (ret < 0)
return ret;
data->opmode = 0;
for (i = 0; i < ARRAY_SIZE(us5182d_regvals); i++) {
ret = i2c_smbus_write_byte_data(data->client,
us5182d_regvals[i].reg,
us5182d_regvals[i].val);
if (ret < 0)
return ret;
}
return 0;
}
static void us5182d_get_platform_data(struct iio_dev *indio_dev)
{
struct us5182d_data *data = iio_priv(indio_dev);
if (device_property_read_u32(&data->client->dev, "upisemi,glass-coef",
&data->ga))
data->ga = US5182D_GA_RESOLUTION;
if (device_property_read_u16_array(&data->client->dev,
"upisemi,dark-ths",
data->us5182d_dark_ths,
ARRAY_SIZE(us5182d_dark_ths_vals)))
data->us5182d_dark_ths = us5182d_dark_ths_vals;
if (device_property_read_u8(&data->client->dev,
"upisemi,upper-dark-gain",
&data->upper_dark_gain))
data->upper_dark_gain = US5182D_REG_AUTO_HDARK_GAIN_DEFAULT;
if (device_property_read_u8(&data->client->dev,
"upisemi,lower-dark-gain",
&data->lower_dark_gain))
data->lower_dark_gain = US5182D_REG_AUTO_LDARK_GAIN_DEFAULT;
}
static int us5182d_dark_gain_config(struct iio_dev *indio_dev)
{
struct us5182d_data *data = iio_priv(indio_dev);
int ret;
ret = us5182d_update_dark_th(data, US5182D_CFG1_AGAIN_DEFAULT);
if (ret < 0)
return ret;
ret = i2c_smbus_write_byte_data(data->client,
US5182D_REG_AUTO_LDARK_GAIN,
data->lower_dark_gain);
if (ret < 0)
return ret;
ret = i2c_smbus_write_byte_data(data->client,
US5182D_REG_AUTO_HDARK_GAIN,
data->upper_dark_gain);
if (ret < 0)
return ret;
return i2c_smbus_write_byte_data(data->client, US5182D_REG_DARK_AUTO_EN,
US5182D_REG_DARK_AUTO_EN_DEFAULT);
}
static int us5182d_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct us5182d_data *data;
struct iio_dev *indio_dev;
int ret;
indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*data));
if (!indio_dev)
return -ENOMEM;
data = iio_priv(indio_dev);
i2c_set_clientdata(client, indio_dev);
data->client = client;
mutex_init(&data->lock);
indio_dev->dev.parent = &client->dev;
indio_dev->info = &us5182d_info;
indio_dev->name = US5182D_DRV_NAME;
indio_dev->channels = us5182d_channels;
indio_dev->num_channels = ARRAY_SIZE(us5182d_channels);
indio_dev->modes = INDIO_DIRECT_MODE;
ret = i2c_smbus_read_byte_data(data->client, US5182D_REG_CHIPID);
if (ret != US5182D_CHIPID) {
dev_err(&data->client->dev,
"Failed to detect US5182 light chip\n");
return (ret < 0) ? ret : -ENODEV;
}
us5182d_get_platform_data(indio_dev);
ret = us5182d_init(indio_dev);
if (ret < 0)
return ret;
ret = us5182d_dark_gain_config(indio_dev);
if (ret < 0)
return ret;
return iio_device_register(indio_dev);
}
static int us5182d_remove(struct i2c_client *client)
{
iio_device_unregister(i2c_get_clientdata(client));
return i2c_smbus_write_byte_data(client, US5182D_REG_CFG0,
US5182D_CFG0_SHUTDOWN_EN);
}
