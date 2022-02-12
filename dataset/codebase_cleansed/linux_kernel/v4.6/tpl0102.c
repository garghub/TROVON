static int tpl0102_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2, long mask)
{
struct tpl0102_data *data = iio_priv(indio_dev);
switch (mask) {
case IIO_CHAN_INFO_RAW: {
int ret = regmap_read(data->regmap, chan->channel, val);
return ret ? ret : IIO_VAL_INT;
}
case IIO_CHAN_INFO_SCALE:
*val = 1000 * tpl0102_cfg[data->devid].kohms;
*val2 = tpl0102_cfg[data->devid].max_pos;
return IIO_VAL_FRACTIONAL;
}
return -EINVAL;
}
static int tpl0102_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int val, int val2, long mask)
{
struct tpl0102_data *data = iio_priv(indio_dev);
if (mask != IIO_CHAN_INFO_RAW)
return -EINVAL;
if (val >= tpl0102_cfg[data->devid].max_pos || val < 0)
return -EINVAL;
return regmap_write(data->regmap, chan->channel, val);
}
static int tpl0102_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct device *dev = &client->dev;
struct tpl0102_data *data;
struct iio_dev *indio_dev;
if (!i2c_check_functionality(client->adapter,
I2C_FUNC_SMBUS_WORD_DATA))
return -ENOTSUPP;
indio_dev = devm_iio_device_alloc(dev, sizeof(*data));
if (!indio_dev)
return -ENOMEM;
data = iio_priv(indio_dev);
i2c_set_clientdata(client, indio_dev);
data->devid = id->driver_data;
data->regmap = devm_regmap_init_i2c(client, &tpl0102_regmap_config);
if (IS_ERR(data->regmap)) {
dev_err(dev, "regmap initialization failed\n");
return PTR_ERR(data->regmap);
}
indio_dev->dev.parent = dev;
indio_dev->info = &tpl0102_info;
indio_dev->channels = tpl0102_channels;
indio_dev->num_channels = tpl0102_cfg[data->devid].wipers;
indio_dev->name = client->name;
return devm_iio_device_register(dev, indio_dev);
}
