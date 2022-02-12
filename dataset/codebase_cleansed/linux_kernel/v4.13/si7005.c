static int si7005_read_measurement(struct si7005_data *data, bool temp)
{
int tries = 50;
int ret;
mutex_lock(&data->lock);
ret = i2c_smbus_write_byte_data(data->client, SI7005_CONFIG,
data->config | SI7005_CONFIG_START |
(temp ? SI7005_CONFIG_TEMP : 0));
if (ret < 0)
goto done;
while (tries-- > 0) {
msleep(20);
ret = i2c_smbus_read_byte_data(data->client, SI7005_STATUS);
if (ret < 0)
goto done;
if (!(ret & SI7005_STATUS_NRDY))
break;
}
if (tries < 0) {
ret = -EIO;
goto done;
}
ret = i2c_smbus_read_word_swapped(data->client, SI7005_DATA);
done:
mutex_unlock(&data->lock);
return ret;
}
static int si7005_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan, int *val,
int *val2, long mask)
{
struct si7005_data *data = iio_priv(indio_dev);
int ret;
switch (mask) {
case IIO_CHAN_INFO_RAW:
ret = si7005_read_measurement(data, chan->type == IIO_TEMP);
if (ret < 0)
return ret;
*val = ret;
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
if (chan->type == IIO_TEMP) {
*val = 7;
*val2 = 812500;
} else {
*val = 3;
*val2 = 906250;
}
return IIO_VAL_INT_PLUS_MICRO;
case IIO_CHAN_INFO_OFFSET:
if (chan->type == IIO_TEMP)
*val = -50 * 32 * 4;
else
*val = -24 * 16 * 16;
return IIO_VAL_INT;
default:
break;
}
return -EINVAL;
}
static int si7005_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct iio_dev *indio_dev;
struct si7005_data *data;
int ret;
if (!i2c_check_functionality(client->adapter, I2C_FUNC_SMBUS_WORD_DATA))
return -EOPNOTSUPP;
indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*data));
if (!indio_dev)
return -ENOMEM;
data = iio_priv(indio_dev);
i2c_set_clientdata(client, indio_dev);
data->client = client;
mutex_init(&data->lock);
indio_dev->dev.parent = &client->dev;
indio_dev->name = dev_name(&client->dev);
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->info = &si7005_info;
indio_dev->channels = si7005_channels;
indio_dev->num_channels = ARRAY_SIZE(si7005_channels);
ret = i2c_smbus_read_byte_data(client, SI7005_ID);
if (ret < 0)
return ret;
if (ret != SI7005_ID_7005 && ret != SI7005_ID_7015)
return -ENODEV;
ret = i2c_smbus_read_byte_data(client, SI7005_CONFIG);
if (ret < 0)
return ret;
data->config = ret;
return devm_iio_device_register(&client->dev, indio_dev);
}
