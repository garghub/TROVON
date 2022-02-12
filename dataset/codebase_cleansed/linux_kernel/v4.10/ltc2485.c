static void ltc2485_wait_conv(struct ltc2485_data *data)
{
const unsigned int conv_time = 147;
unsigned int time_elapsed;
time_elapsed = ktime_ms_delta(ktime_get(), data->time_prev);
if (time_elapsed < conv_time)
msleep(conv_time - time_elapsed);
}
static int ltc2485_read(struct ltc2485_data *data, int *val)
{
struct i2c_client *client = data->client;
__be32 buf = 0;
int ret;
ltc2485_wait_conv(data);
ret = i2c_master_recv(client, (char *)&buf, 4);
if (ret < 0) {
dev_err(&client->dev, "i2c_master_recv failed\n");
return ret;
}
data->time_prev = ktime_get();
*val = sign_extend32(be32_to_cpu(buf) >> 6, 24);
return ret;
}
static int ltc2485_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2, long mask)
{
struct ltc2485_data *data = iio_priv(indio_dev);
int ret;
if (mask == IIO_CHAN_INFO_RAW) {
ret = ltc2485_read(data, val);
if (ret < 0)
return ret;
return IIO_VAL_INT;
} else if (mask == IIO_CHAN_INFO_SCALE) {
*val = 5000;
*val2 = 25;
return IIO_VAL_FRACTIONAL_LOG2;
} else {
return -EINVAL;
}
}
static int ltc2485_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct iio_dev *indio_dev;
struct ltc2485_data *data;
int ret;
if (!i2c_check_functionality(client->adapter, I2C_FUNC_I2C |
I2C_FUNC_SMBUS_WRITE_BYTE))
return -EOPNOTSUPP;
indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*data));
if (!indio_dev)
return -ENOMEM;
data = iio_priv(indio_dev);
i2c_set_clientdata(client, indio_dev);
data->client = client;
indio_dev->dev.parent = &client->dev;
indio_dev->name = id->name;
indio_dev->info = &ltc2485_info;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->channels = ltc2485_channel;
indio_dev->num_channels = ARRAY_SIZE(ltc2485_channel);
ret = i2c_smbus_write_byte(data->client, LTC2485_CONFIG_DEFAULT);
if (ret < 0)
return ret;
data->time_prev = ktime_get();
return devm_iio_device_register(&client->dev, indio_dev);
}
