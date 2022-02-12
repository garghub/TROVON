static int ltc2471_get_value(struct i2c_client *client)
{
int ret;
__be16 buf;
ret = i2c_master_recv(client, (char *)&buf, sizeof(buf));
if (ret < 0)
return ret;
if (ret != sizeof(buf))
return -EIO;
return be16_to_cpu(buf);
}
static int ltc2471_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2, long info)
{
struct ltc2471_data *data = iio_priv(indio_dev);
int ret;
switch (info) {
case IIO_CHAN_INFO_RAW:
ret = ltc2471_get_value(data->client);
if (ret < 0)
return ret;
*val = ret;
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
if (chan->differential)
*val = 2 * LTC2471_VREF;
else
*val = LTC2471_VREF;
*val2 = 16;
return IIO_VAL_FRACTIONAL_LOG2;
case IIO_CHAN_INFO_OFFSET:
*val = -LTC2471_VREF;
return IIO_VAL_INT;
default:
return -EINVAL;
}
}
static int ltc2471_i2c_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct iio_dev *indio_dev;
struct ltc2471_data *data;
int ret;
if (!i2c_check_functionality(client->adapter, I2C_FUNC_I2C))
return -EOPNOTSUPP;
indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*data));
if (!indio_dev)
return -ENOMEM;
data = iio_priv(indio_dev);
data->client = client;
indio_dev->dev.parent = &client->dev;
indio_dev->name = id->name;
indio_dev->info = &ltc2471_info;
indio_dev->modes = INDIO_DIRECT_MODE;
if (id->driver_data == ltc2473)
indio_dev->channels = ltc2473_channel;
else
indio_dev->channels = ltc2471_channel;
indio_dev->num_channels = 1;
ret = ltc2471_get_value(client);
if (ret < 0) {
dev_err(&client->dev, "Cannot read from device.\n");
return ret;
}
return devm_iio_device_register(&client->dev, indio_dev);
}
