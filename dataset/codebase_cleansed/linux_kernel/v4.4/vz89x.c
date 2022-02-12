static int vz89x_measurement_is_valid(struct vz89x_data *data)
{
if (data->buffer[VZ89X_VOC_SHORT_IDX] == 0)
return 1;
return !!(data->buffer[VZ89X_REG_MEASUREMENT_SIZE - 1] > 0);
}
static int vz89x_get_measurement(struct vz89x_data *data)
{
int ret;
int i;
if (!time_after(jiffies, data->last_update + HZ))
return 0;
ret = i2c_smbus_write_word_data(data->client,
VZ89X_REG_MEASUREMENT, 0);
if (ret < 0)
return ret;
for (i = 0; i < VZ89X_REG_MEASUREMENT_SIZE; i++) {
ret = i2c_smbus_read_byte(data->client);
if (ret < 0)
return ret;
data->buffer[i] = ret;
}
ret = vz89x_measurement_is_valid(data);
if (ret)
return -EAGAIN;
data->last_update = jiffies;
return 0;
}
static int vz89x_get_resistance_reading(struct vz89x_data *data)
{
u8 *buf = &data->buffer[VZ89X_VOC_RESISTANCE_IDX];
return buf[0] | (buf[1] << 8);
}
static int vz89x_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan, int *val,
int *val2, long mask)
{
struct vz89x_data *data = iio_priv(indio_dev);
int ret = -EINVAL;
switch (mask) {
case IIO_CHAN_INFO_RAW:
mutex_lock(&data->lock);
ret = vz89x_get_measurement(data);
mutex_unlock(&data->lock);
if (ret)
return ret;
switch (chan->address) {
case VZ89X_VOC_CO2_IDX:
case VZ89X_VOC_SHORT_IDX:
case VZ89X_VOC_TVOC_IDX:
*val = data->buffer[chan->address];
return IIO_VAL_INT;
case VZ89X_VOC_RESISTANCE_IDX:
*val = vz89x_get_resistance_reading(data);
return IIO_VAL_INT;
default:
return -EINVAL;
}
break;
case IIO_CHAN_INFO_SCALE:
switch (chan->type) {
case IIO_RESISTANCE:
*val = 10;
return IIO_VAL_INT;
default:
return -EINVAL;
}
break;
case IIO_CHAN_INFO_OFFSET:
switch (chan->address) {
case VZ89X_VOC_CO2_IDX:
*val = 44;
*val2 = 250000;
return IIO_VAL_INT_PLUS_MICRO;
case VZ89X_VOC_TVOC_IDX:
*val = -13;
return IIO_VAL_INT;
default:
return -EINVAL;
}
}
return ret;
}
static int vz89x_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct iio_dev *indio_dev;
struct vz89x_data *data;
if (!i2c_check_functionality(client->adapter, I2C_FUNC_SMBUS_WORD_DATA |
I2C_FUNC_SMBUS_BYTE))
return -ENODEV;
indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*data));
if (!indio_dev)
return -ENOMEM;
data = iio_priv(indio_dev);
i2c_set_clientdata(client, indio_dev);
data->client = client;
data->last_update = jiffies - HZ;
mutex_init(&data->lock);
indio_dev->dev.parent = &client->dev;
indio_dev->info = &vz89x_info,
indio_dev->name = dev_name(&client->dev);
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->channels = vz89x_channels;
indio_dev->num_channels = ARRAY_SIZE(vz89x_channels);
return devm_iio_device_register(&client->dev, indio_dev);
}
