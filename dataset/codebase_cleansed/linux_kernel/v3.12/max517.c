static int max517_set_value(struct iio_dev *indio_dev,
long val, int channel)
{
struct max517_data *data = iio_priv(indio_dev);
struct i2c_client *client = data->client;
u8 outbuf[2];
int res;
if (val < 0 || val > 255)
return -EINVAL;
outbuf[0] = channel;
outbuf[1] = val;
res = i2c_master_send(client, outbuf, 2);
if (res < 0)
return res;
else if (res != 2)
return -EIO;
else
return 0;
}
static int max517_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val,
int *val2,
long m)
{
struct max517_data *data = iio_priv(indio_dev);
unsigned int scale_uv;
switch (m) {
case IIO_CHAN_INFO_SCALE:
scale_uv = (data->vref_mv[chan->channel] * 1000) >> 8;
*val = scale_uv / 1000000;
*val2 = scale_uv % 1000000;
return IIO_VAL_INT_PLUS_MICRO;
default:
break;
}
return -EINVAL;
}
static int max517_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan, int val, int val2, long mask)
{
int ret;
switch (mask) {
case IIO_CHAN_INFO_RAW:
ret = max517_set_value(indio_dev, val, chan->channel);
break;
default:
ret = -EINVAL;
break;
}
return ret;
}
static int max517_suspend(struct device *dev)
{
u8 outbuf = COMMAND_PD;
return i2c_master_send(to_i2c_client(dev), &outbuf, 1);
}
static int max517_resume(struct device *dev)
{
u8 outbuf = 0;
return i2c_master_send(to_i2c_client(dev), &outbuf, 1);
}
static int max517_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct max517_data *data;
struct iio_dev *indio_dev;
struct max517_platform_data *platform_data = client->dev.platform_data;
int err;
indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*data));
if (!indio_dev)
return -ENOMEM;
data = iio_priv(indio_dev);
i2c_set_clientdata(client, indio_dev);
data->client = client;
indio_dev->dev.parent = &client->dev;
if (id->driver_data == ID_MAX517)
indio_dev->num_channels = 1;
else
indio_dev->num_channels = 2;
indio_dev->channels = max517_channels;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->info = &max517_info;
if (id->driver_data == ID_MAX518 || !platform_data) {
data->vref_mv[0] = data->vref_mv[1] = 5000;
} else {
data->vref_mv[0] = platform_data->vref_mv[0];
data->vref_mv[1] = platform_data->vref_mv[1];
}
err = iio_device_register(indio_dev);
if (err)
return err;
dev_info(&client->dev, "DAC registered\n");
return 0;
}
static int max517_remove(struct i2c_client *client)
{
iio_device_unregister(i2c_get_clientdata(client));
return 0;
}
