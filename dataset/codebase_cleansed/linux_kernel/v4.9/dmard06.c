static int dmard06_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2, long mask)
{
struct dmard06_data *dmard06 = iio_priv(indio_dev);
int ret;
switch (mask) {
case IIO_CHAN_INFO_RAW:
ret = i2c_smbus_read_byte_data(dmard06->client,
chan->address);
if (ret < 0) {
dev_err(&dmard06->client->dev,
"Error reading data: %d\n", ret);
return ret;
}
*val = sign_extend32(ret, DMARD06_SIGN_BIT);
if (dmard06->chip_id == DMARD06_CHIP_ID)
*val = *val >> 1;
switch (chan->type) {
case IIO_ACCEL:
return IIO_VAL_INT;
case IIO_TEMP:
if (dmard06->chip_id != DMARD06_CHIP_ID)
*val = *val / 2;
return IIO_VAL_INT;
default:
return -EINVAL;
}
case IIO_CHAN_INFO_OFFSET:
switch (chan->type) {
case IIO_TEMP:
*val = DMARD06_TEMP_CENTER_VAL;
return IIO_VAL_INT;
default:
return -EINVAL;
}
case IIO_CHAN_INFO_SCALE:
switch (chan->type) {
case IIO_ACCEL:
*val = 0;
if (dmard06->chip_id == DMARD06_CHIP_ID)
*val2 = DMARD06_AXIS_SCALE_VAL;
else
*val2 = DMARD05_AXIS_SCALE_VAL;
return IIO_VAL_INT_PLUS_MICRO;
default:
return -EINVAL;
}
default:
return -EINVAL;
}
}
static int dmard06_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
int ret;
struct iio_dev *indio_dev;
struct dmard06_data *dmard06;
if (!i2c_check_functionality(client->adapter, I2C_FUNC_I2C)) {
dev_err(&client->dev, "I2C check functionality failed\n");
return -ENXIO;
}
indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*dmard06));
if (!indio_dev) {
dev_err(&client->dev, "Failed to allocate iio device\n");
return -ENOMEM;
}
dmard06 = iio_priv(indio_dev);
dmard06->client = client;
ret = i2c_smbus_read_byte_data(dmard06->client, DMARD06_CHIP_ID_REG);
if (ret < 0) {
dev_err(&client->dev, "Error reading chip id: %d\n", ret);
return ret;
}
if (ret != DMARD05_CHIP_ID && ret != DMARD06_CHIP_ID &&
ret != DMARD07_CHIP_ID) {
dev_err(&client->dev, "Invalid chip id: %02d\n", ret);
return -ENODEV;
}
dmard06->chip_id = ret;
i2c_set_clientdata(client, indio_dev);
indio_dev->dev.parent = &client->dev;
indio_dev->name = DMARD06_DRV_NAME;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->channels = dmard06_channels;
indio_dev->num_channels = ARRAY_SIZE(dmard06_channels);
indio_dev->info = &dmard06_info;
return devm_iio_device_register(&client->dev, indio_dev);
}
static int dmard06_suspend(struct device *dev)
{
struct iio_dev *indio_dev = i2c_get_clientdata(to_i2c_client(dev));
struct dmard06_data *dmard06 = iio_priv(indio_dev);
int ret;
ret = i2c_smbus_write_byte_data(dmard06->client, DMARD06_CTRL1_REG,
DMARD06_MODE_POWERDOWN);
if (ret < 0)
return ret;
return 0;
}
static int dmard06_resume(struct device *dev)
{
struct iio_dev *indio_dev = i2c_get_clientdata(to_i2c_client(dev));
struct dmard06_data *dmard06 = iio_priv(indio_dev);
int ret;
ret = i2c_smbus_write_byte_data(dmard06->client, DMARD06_CTRL1_REG,
DMARD06_MODE_NORMAL);
if (ret < 0)
return ret;
return 0;
}
