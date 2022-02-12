static int da280_enable(struct i2c_client *client, bool enable)
{
u8 data = enable ? DA280_MODE_ENABLE : DA280_MODE_DISABLE;
return i2c_smbus_write_byte_data(client, DA280_REG_MODE_BW, data);
}
static int da280_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2, long mask)
{
struct da280_data *data = iio_priv(indio_dev);
int ret;
switch (mask) {
case IIO_CHAN_INFO_RAW:
ret = i2c_smbus_read_word_data(data->client, chan->address);
if (ret < 0)
return ret;
*val = (short)ret >> 2;
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
*val = 0;
*val2 = da280_nscale;
return IIO_VAL_INT_PLUS_NANO;
default:
return -EINVAL;
}
}
static int da280_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
int ret;
struct iio_dev *indio_dev;
struct da280_data *data;
ret = i2c_smbus_read_byte_data(client, DA280_REG_CHIP_ID);
if (ret != DA280_CHIP_ID)
return (ret < 0) ? ret : -ENODEV;
indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*data));
if (!indio_dev)
return -ENOMEM;
data = iio_priv(indio_dev);
data->client = client;
i2c_set_clientdata(client, indio_dev);
indio_dev->dev.parent = &client->dev;
indio_dev->info = &da280_info;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->channels = da280_channels;
if (id->driver_data == da226) {
indio_dev->name = "da226";
indio_dev->num_channels = 2;
} else {
indio_dev->name = "da280";
indio_dev->num_channels = 3;
}
ret = da280_enable(client, true);
if (ret < 0)
return ret;
ret = iio_device_register(indio_dev);
if (ret < 0) {
dev_err(&client->dev, "device_register failed\n");
da280_enable(client, false);
}
return ret;
}
static int da280_remove(struct i2c_client *client)
{
struct iio_dev *indio_dev = i2c_get_clientdata(client);
iio_device_unregister(indio_dev);
return da280_enable(client, false);
}
static int da280_suspend(struct device *dev)
{
return da280_enable(to_i2c_client(dev), false);
}
static int da280_resume(struct device *dev)
{
return da280_enable(to_i2c_client(dev), true);
}
