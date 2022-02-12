static int si7020_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan, int *val,
int *val2, long mask)
{
struct i2c_client **client = iio_priv(indio_dev);
int ret;
switch (mask) {
case IIO_CHAN_INFO_RAW:
ret = i2c_smbus_read_word_swapped(*client,
chan->type == IIO_TEMP ?
SI7020CMD_TEMP_HOLD :
SI7020CMD_RH_HOLD);
if (ret < 0)
return ret;
*val = ret >> 2;
if (chan->type == IIO_HUMIDITYRELATIVE)
*val = clamp_val(*val, 786, 13893);
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
if (chan->type == IIO_TEMP)
*val = 175720;
else
*val = 125 * 1000;
*val2 = 65536 >> 2;
return IIO_VAL_FRACTIONAL;
case IIO_CHAN_INFO_OFFSET:
if (chan->type == IIO_TEMP)
*val = -4368;
else
*val = -786;
return IIO_VAL_INT;
default:
break;
}
return -EINVAL;
}
static int si7020_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct iio_dev *indio_dev;
struct i2c_client **data;
int ret;
if (!i2c_check_functionality(client->adapter,
I2C_FUNC_SMBUS_WRITE_BYTE |
I2C_FUNC_SMBUS_READ_WORD_DATA))
return -EOPNOTSUPP;
ret = i2c_smbus_write_byte(client, SI7020CMD_RESET);
if (ret < 0)
return ret;
msleep(15);
indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*data));
if (!indio_dev)
return -ENOMEM;
data = iio_priv(indio_dev);
*data = client;
indio_dev->dev.parent = &client->dev;
indio_dev->name = dev_name(&client->dev);
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->info = &si7020_info;
indio_dev->channels = si7020_channels;
indio_dev->num_channels = ARRAY_SIZE(si7020_channels);
return devm_iio_device_register(&client->dev, indio_dev);
}
