static int m62332_set_value(struct iio_dev *indio_dev, u8 val, int channel)
{
struct m62332_data *data = iio_priv(indio_dev);
struct i2c_client *client = data->client;
u8 outbuf[2];
int res;
if (val == data->raw[channel])
return 0;
outbuf[0] = channel;
outbuf[1] = val;
mutex_lock(&data->mutex);
if (val) {
res = regulator_enable(data->vcc);
if (res)
goto out;
}
res = i2c_master_send(client, outbuf, ARRAY_SIZE(outbuf));
if (res >= 0 && res != ARRAY_SIZE(outbuf))
res = -EIO;
if (res < 0)
goto out;
data->raw[channel] = val;
if (!val)
regulator_disable(data->vcc);
mutex_unlock(&data->mutex);
return 0;
out:
mutex_unlock(&data->mutex);
return res;
}
static int m62332_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val,
int *val2,
long mask)
{
struct m62332_data *data = iio_priv(indio_dev);
int ret;
switch (mask) {
case IIO_CHAN_INFO_SCALE:
ret = regulator_get_voltage(data->vcc);
if (ret < 0)
return ret;
*val = ret / 1000;
*val2 = 8;
return IIO_VAL_FRACTIONAL_LOG2;
case IIO_CHAN_INFO_RAW:
*val = data->raw[chan->channel];
return IIO_VAL_INT;
case IIO_CHAN_INFO_OFFSET:
*val = 1;
return IIO_VAL_INT;
default:
break;
}
return -EINVAL;
}
static int m62332_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan, int val, int val2,
long mask)
{
switch (mask) {
case IIO_CHAN_INFO_RAW:
if (val < 0 || val > 255)
return -EINVAL;
return m62332_set_value(indio_dev, val, chan->channel);
default:
break;
}
return -EINVAL;
}
static int m62332_suspend(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct iio_dev *indio_dev = i2c_get_clientdata(client);
struct m62332_data *data = iio_priv(indio_dev);
int ret;
data->save[0] = data->raw[0];
data->save[1] = data->raw[1];
ret = m62332_set_value(indio_dev, 0, 0);
if (ret < 0)
return ret;
return m62332_set_value(indio_dev, 0, 1);
}
static int m62332_resume(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct iio_dev *indio_dev = i2c_get_clientdata(client);
struct m62332_data *data = iio_priv(indio_dev);
int ret;
ret = m62332_set_value(indio_dev, data->save[0], 0);
if (ret < 0)
return ret;
return m62332_set_value(indio_dev, data->save[1], 1);
}
static int m62332_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct m62332_data *data;
struct iio_dev *indio_dev;
int ret;
indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*data));
if (!indio_dev)
return -ENOMEM;
data = iio_priv(indio_dev);
i2c_set_clientdata(client, indio_dev);
data->client = client;
mutex_init(&data->mutex);
data->vcc = devm_regulator_get(&client->dev, "VCC");
if (IS_ERR(data->vcc))
return PTR_ERR(data->vcc);
indio_dev->dev.parent = &client->dev;
indio_dev->num_channels = ARRAY_SIZE(m62332_channels);
indio_dev->channels = m62332_channels;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->info = &m62332_info;
ret = iio_map_array_register(indio_dev, client->dev.platform_data);
if (ret < 0)
return ret;
ret = iio_device_register(indio_dev);
if (ret < 0)
goto err;
return 0;
err:
iio_map_array_unregister(indio_dev);
return ret;
}
static int m62332_remove(struct i2c_client *client)
{
struct iio_dev *indio_dev = i2c_get_clientdata(client);
iio_device_unregister(indio_dev);
iio_map_array_unregister(indio_dev);
m62332_set_value(indio_dev, 0, 0);
m62332_set_value(indio_dev, 0, 1);
return 0;
}
