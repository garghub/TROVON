static int ltc2497_wait_conv(struct ltc2497_st *st)
{
s64 time_elapsed;
time_elapsed = ktime_ms_delta(ktime_get(), st->time_prev);
if (time_elapsed < LTC2497_CONVERSION_TIME_MS) {
if (msleep_interruptible(
LTC2497_CONVERSION_TIME_MS - time_elapsed))
return -ERESTARTSYS;
return 0;
}
if (time_elapsed - LTC2497_CONVERSION_TIME_MS <= 0) {
return 0;
}
return 1;
}
static int ltc2497_read(struct ltc2497_st *st, u8 address, int *val)
{
struct i2c_client *client = st->client;
int ret;
ret = ltc2497_wait_conv(st);
if (ret < 0)
return ret;
if (ret || st->addr_prev != address) {
ret = i2c_smbus_write_byte(st->client,
LTC2497_ENABLE | address);
if (ret < 0)
return ret;
st->addr_prev = address;
if (msleep_interruptible(LTC2497_CONVERSION_TIME_MS))
return -ERESTARTSYS;
}
ret = i2c_master_recv(client, (char *)&st->buf, 3);
if (ret < 0) {
dev_err(&client->dev, "i2c_master_recv failed\n");
return ret;
}
st->time_prev = ktime_get();
*val = (be32_to_cpu(st->buf) >> 14) - (1 << 17);
return ret;
}
static int ltc2497_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2, long mask)
{
struct ltc2497_st *st = iio_priv(indio_dev);
int ret;
switch (mask) {
case IIO_CHAN_INFO_RAW:
mutex_lock(&indio_dev->mlock);
ret = ltc2497_read(st, chan->address, val);
mutex_unlock(&indio_dev->mlock);
if (ret < 0)
return ret;
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
ret = regulator_get_voltage(st->ref);
if (ret < 0)
return ret;
*val = ret / 1000;
*val2 = 17;
return IIO_VAL_FRACTIONAL_LOG2;
default:
return -EINVAL;
}
}
static int ltc2497_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct iio_dev *indio_dev;
struct ltc2497_st *st;
int ret;
if (!i2c_check_functionality(client->adapter, I2C_FUNC_I2C |
I2C_FUNC_SMBUS_WRITE_BYTE))
return -EOPNOTSUPP;
indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*st));
if (!indio_dev)
return -ENOMEM;
st = iio_priv(indio_dev);
i2c_set_clientdata(client, indio_dev);
st->client = client;
indio_dev->dev.parent = &client->dev;
indio_dev->name = id->name;
indio_dev->info = &ltc2497_info;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->channels = ltc2497_channel;
indio_dev->num_channels = ARRAY_SIZE(ltc2497_channel);
st->ref = devm_regulator_get(&client->dev, "vref");
if (IS_ERR(st->ref))
return PTR_ERR(st->ref);
ret = regulator_enable(st->ref);
if (ret < 0)
return ret;
ret = i2c_smbus_write_byte(st->client, LTC2497_CONFIG_DEFAULT);
if (ret < 0)
goto err_regulator_disable;
st->addr_prev = LTC2497_CONFIG_DEFAULT;
st->time_prev = ktime_get();
ret = iio_device_register(indio_dev);
if (ret < 0)
goto err_regulator_disable;
return 0;
err_regulator_disable:
regulator_disable(st->ref);
return ret;
}
static int ltc2497_remove(struct i2c_client *client)
{
struct iio_dev *indio_dev = i2c_get_clientdata(client);
struct ltc2497_st *st = iio_priv(indio_dev);
iio_device_unregister(indio_dev);
regulator_disable(st->ref);
return 0;
}
