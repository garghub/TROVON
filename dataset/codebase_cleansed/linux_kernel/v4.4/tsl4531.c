static int tsl4531_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2, long mask)
{
struct tsl4531_data *data = iio_priv(indio_dev);
int ret;
switch (mask) {
case IIO_CHAN_INFO_RAW:
ret = i2c_smbus_read_word_data(data->client,
TSL4531_DATA);
if (ret < 0)
return ret;
*val = ret;
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
*val = 1 << data->int_time;
return IIO_VAL_INT;
case IIO_CHAN_INFO_INT_TIME:
if (data->int_time == 0)
*val2 = 400000;
else if (data->int_time == 1)
*val2 = 200000;
else if (data->int_time == 2)
*val2 = 100000;
else
return -EINVAL;
*val = 0;
return IIO_VAL_INT_PLUS_MICRO;
default:
return -EINVAL;
}
}
static int tsl4531_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int val, int val2, long mask)
{
struct tsl4531_data *data = iio_priv(indio_dev);
int int_time, ret;
switch (mask) {
case IIO_CHAN_INFO_INT_TIME:
if (val != 0)
return -EINVAL;
if (val2 == 400000)
int_time = 0;
else if (val2 == 200000)
int_time = 1;
else if (val2 == 100000)
int_time = 2;
else
return -EINVAL;
mutex_lock(&data->lock);
ret = i2c_smbus_write_byte_data(data->client,
TSL4531_CONFIG, int_time);
if (ret >= 0)
data->int_time = int_time;
mutex_unlock(&data->lock);
return ret;
default:
return -EINVAL;
}
}
static int tsl4531_check_id(struct i2c_client *client)
{
int ret = i2c_smbus_read_byte_data(client, TSL4531_ID);
if (ret < 0)
return ret;
switch (ret >> TSL4531_ID_SHIFT) {
case TSL45311_ID:
case TSL45313_ID:
case TSL45315_ID:
case TSL45317_ID:
return 0;
default:
return -ENODEV;
}
}
static int tsl4531_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct tsl4531_data *data;
struct iio_dev *indio_dev;
int ret;
indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*data));
if (!indio_dev)
return -ENOMEM;
data = iio_priv(indio_dev);
i2c_set_clientdata(client, indio_dev);
data->client = client;
mutex_init(&data->lock);
ret = tsl4531_check_id(client);
if (ret) {
dev_err(&client->dev, "no TSL4531 sensor\n");
return ret;
}
ret = i2c_smbus_write_byte_data(data->client, TSL4531_CONTROL,
TSL4531_MODE_NORMAL);
if (ret < 0)
return ret;
ret = i2c_smbus_write_byte_data(data->client, TSL4531_CONFIG,
TSL4531_TCNTRL_400MS);
if (ret < 0)
return ret;
indio_dev->dev.parent = &client->dev;
indio_dev->info = &tsl4531_info;
indio_dev->channels = tsl4531_channels;
indio_dev->num_channels = ARRAY_SIZE(tsl4531_channels);
indio_dev->name = TSL4531_DRV_NAME;
indio_dev->modes = INDIO_DIRECT_MODE;
return iio_device_register(indio_dev);
}
static int tsl4531_powerdown(struct i2c_client *client)
{
return i2c_smbus_write_byte_data(client, TSL4531_CONTROL,
TSL4531_MODE_POWERDOWN);
}
static int tsl4531_remove(struct i2c_client *client)
{
iio_device_unregister(i2c_get_clientdata(client));
tsl4531_powerdown(client);
return 0;
}
static int tsl4531_suspend(struct device *dev)
{
return tsl4531_powerdown(to_i2c_client(dev));
}
static int tsl4531_resume(struct device *dev)
{
return i2c_smbus_write_byte_data(to_i2c_client(dev), TSL4531_CONTROL,
TSL4531_MODE_NORMAL);
}
