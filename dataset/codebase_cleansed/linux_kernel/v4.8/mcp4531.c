static int mcp4531_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2, long mask)
{
struct mcp4531_data *data = iio_priv(indio_dev);
int address = chan->channel << MCP4531_WIPER_SHIFT;
s32 ret;
switch (mask) {
case IIO_CHAN_INFO_RAW:
ret = i2c_smbus_read_word_swapped(data->client,
MCP4531_READ | address);
if (ret < 0)
return ret;
*val = ret;
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
*val = 1000 * data->cfg->kohms;
*val2 = data->cfg->max_pos;
return IIO_VAL_FRACTIONAL;
}
return -EINVAL;
}
static int mcp4531_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int val, int val2, long mask)
{
struct mcp4531_data *data = iio_priv(indio_dev);
int address = chan->channel << MCP4531_WIPER_SHIFT;
switch (mask) {
case IIO_CHAN_INFO_RAW:
if (val > data->cfg->max_pos || val < 0)
return -EINVAL;
break;
default:
return -EINVAL;
}
return i2c_smbus_write_byte_data(data->client,
MCP4531_WRITE | address | (val >> 8),
val & 0xff);
}
static int mcp4531_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct device *dev = &client->dev;
struct mcp4531_data *data;
struct iio_dev *indio_dev;
const struct of_device_id *match;
if (!i2c_check_functionality(client->adapter,
I2C_FUNC_SMBUS_WORD_DATA)) {
dev_err(dev, "SMBUS Word Data not supported\n");
return -EOPNOTSUPP;
}
indio_dev = devm_iio_device_alloc(dev, sizeof(*data));
if (!indio_dev)
return -ENOMEM;
data = iio_priv(indio_dev);
i2c_set_clientdata(client, indio_dev);
data->client = client;
match = of_match_device(of_match_ptr(mcp4531_of_match), dev);
if (match)
data->cfg = of_device_get_match_data(dev);
else
data->cfg = &mcp4531_cfg[id->driver_data];
indio_dev->dev.parent = dev;
indio_dev->info = &mcp4531_info;
indio_dev->channels = mcp4531_channels;
indio_dev->num_channels = data->cfg->wipers;
indio_dev->name = client->name;
return devm_iio_device_register(dev, indio_dev);
}
