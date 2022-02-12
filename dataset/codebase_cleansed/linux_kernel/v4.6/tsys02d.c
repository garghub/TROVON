static int tsys02d_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *channel, int *val,
int *val2, long mask)
{
int ret;
s32 temperature;
struct ms_ht_dev *dev_data = iio_priv(indio_dev);
switch (mask) {
case IIO_CHAN_INFO_PROCESSED:
switch (channel->type) {
case IIO_TEMP:
ret = ms_sensors_ht_read_temperature(dev_data,
&temperature);
if (ret)
return ret;
*val = temperature;
return IIO_VAL_INT;
default:
return -EINVAL;
}
case IIO_CHAN_INFO_SAMP_FREQ:
*val = tsys02d_samp_freq[dev_data->res_index];
return IIO_VAL_INT;
default:
return -EINVAL;
}
}
static int tsys02d_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int val, int val2, long mask)
{
struct ms_ht_dev *dev_data = iio_priv(indio_dev);
int i, ret;
switch (mask) {
case IIO_CHAN_INFO_SAMP_FREQ:
i = ARRAY_SIZE(tsys02d_samp_freq);
while (i-- > 0)
if (val == tsys02d_samp_freq[i])
break;
if (i < 0)
return -EINVAL;
mutex_lock(&dev_data->lock);
dev_data->res_index = i;
ret = ms_sensors_write_resolution(dev_data, i);
mutex_unlock(&dev_data->lock);
return ret;
default:
return -EINVAL;
}
}
static ssize_t tsys02_read_battery_low(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct ms_ht_dev *dev_data = iio_priv(indio_dev);
return ms_sensors_show_battery_low(dev_data, buf);
}
static int tsys02d_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct ms_ht_dev *dev_data;
struct iio_dev *indio_dev;
int ret;
u64 serial_number;
if (!i2c_check_functionality(client->adapter,
I2C_FUNC_SMBUS_WRITE_BYTE_DATA |
I2C_FUNC_SMBUS_WRITE_BYTE |
I2C_FUNC_SMBUS_READ_I2C_BLOCK)) {
dev_err(&client->dev,
"Adapter does not support some i2c transaction\n");
return -EOPNOTSUPP;
}
indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*dev_data));
if (!indio_dev)
return -ENOMEM;
dev_data = iio_priv(indio_dev);
dev_data->client = client;
dev_data->res_index = 0;
mutex_init(&dev_data->lock);
indio_dev->info = &tsys02d_info;
indio_dev->name = id->name;
indio_dev->dev.parent = &client->dev;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->channels = tsys02d_channels;
indio_dev->num_channels = ARRAY_SIZE(tsys02d_channels);
i2c_set_clientdata(client, indio_dev);
ret = ms_sensors_reset(client, TSYS02D_RESET, 15000);
if (ret)
return ret;
ret = ms_sensors_read_serial(client, &serial_number);
if (ret)
return ret;
dev_info(&client->dev, "Serial number : %llx", serial_number);
return devm_iio_device_register(&client->dev, indio_dev);
}
