static int ms5637_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *channel, int *val,
int *val2, long mask)
{
int ret;
int temperature;
unsigned int pressure;
struct ms_tp_dev *dev_data = iio_priv(indio_dev);
switch (mask) {
case IIO_CHAN_INFO_PROCESSED:
ret = ms_sensors_read_temp_and_pressure(dev_data,
&temperature,
&pressure);
if (ret)
return ret;
switch (channel->type) {
case IIO_TEMP:
*val = temperature;
return IIO_VAL_INT;
case IIO_PRESSURE:
*val = pressure / 1000;
*val2 = (pressure % 1000) * 1000;
return IIO_VAL_INT_PLUS_MICRO;
default:
return -EINVAL;
}
case IIO_CHAN_INFO_SAMP_FREQ:
*val = ms5637_samp_freq[dev_data->res_index];
return IIO_VAL_INT;
default:
return -EINVAL;
}
}
static int ms5637_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int val, int val2, long mask)
{
struct ms_tp_dev *dev_data = iio_priv(indio_dev);
int i;
switch (mask) {
case IIO_CHAN_INFO_SAMP_FREQ:
i = ARRAY_SIZE(ms5637_samp_freq);
while (i-- > 0)
if (val == ms5637_samp_freq[i])
break;
if (i < 0)
return -EINVAL;
dev_data->res_index = i;
return 0;
default:
return -EINVAL;
}
}
static int ms5637_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct ms_tp_dev *dev_data;
struct iio_dev *indio_dev;
int ret;
if (!i2c_check_functionality(client->adapter,
I2C_FUNC_SMBUS_READ_WORD_DATA |
I2C_FUNC_SMBUS_WRITE_BYTE |
I2C_FUNC_SMBUS_READ_I2C_BLOCK)) {
dev_err(&client->dev,
"Adapter does not support some i2c transaction\n");
return -ENODEV;
}
indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*dev_data));
if (!indio_dev)
return -ENOMEM;
dev_data = iio_priv(indio_dev);
dev_data->client = client;
dev_data->res_index = 5;
mutex_init(&dev_data->lock);
indio_dev->info = &ms5637_info;
indio_dev->name = id->name;
indio_dev->dev.parent = &client->dev;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->channels = ms5637_channels;
indio_dev->num_channels = ARRAY_SIZE(ms5637_channels);
i2c_set_clientdata(client, indio_dev);
ret = ms_sensors_reset(client, 0x1E, 3000);
if (ret)
return ret;
ret = ms_sensors_tp_read_prom(dev_data);
if (ret)
return ret;
return devm_iio_device_register(&client->dev, indio_dev);
}
