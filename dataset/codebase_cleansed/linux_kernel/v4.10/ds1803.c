static int ds1803_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2, long mask)
{
struct ds1803_data *data = iio_priv(indio_dev);
int pot = chan->channel;
int ret;
u8 result[indio_dev->num_channels];
switch (mask) {
case IIO_CHAN_INFO_RAW:
ret = i2c_master_recv(data->client, result,
indio_dev->num_channels);
if (ret < 0)
return ret;
*val = result[pot];
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
*val = 1000 * data->cfg->kohms;
*val2 = DS1803_MAX_POS;
return IIO_VAL_FRACTIONAL;
}
return -EINVAL;
}
static int ds1803_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int val, int val2, long mask)
{
struct ds1803_data *data = iio_priv(indio_dev);
int pot = chan->channel;
if (val2 != 0)
return -EINVAL;
switch (mask) {
case IIO_CHAN_INFO_RAW:
if (val > DS1803_MAX_POS || val < 0)
return -EINVAL;
break;
default:
return -EINVAL;
}
return i2c_smbus_write_byte_data(data->client, DS1803_WRITE(pot), val);
}
static int ds1803_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct device *dev = &client->dev;
struct ds1803_data *data;
struct iio_dev *indio_dev;
indio_dev = devm_iio_device_alloc(dev, sizeof(*data));
if (!indio_dev)
return -ENOMEM;
i2c_set_clientdata(client, indio_dev);
data = iio_priv(indio_dev);
data->client = client;
data->cfg = &ds1803_cfg[id->driver_data];
indio_dev->dev.parent = dev;
indio_dev->info = &ds1803_info;
indio_dev->channels = ds1803_channels;
indio_dev->num_channels = ARRAY_SIZE(ds1803_channels);
indio_dev->name = client->name;
return devm_iio_device_register(dev, indio_dev);
}
