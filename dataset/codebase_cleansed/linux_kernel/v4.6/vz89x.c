static int vz89x_measurement_is_valid(struct vz89x_data *data)
{
if (data->buffer[VZ89X_VOC_SHORT_IDX] == 0)
return 1;
return !!(data->buffer[VZ89X_REG_MEASUREMENT_SIZE - 1] > 0);
}
static int vz89x_i2c_xfer(struct vz89x_data *data, u8 cmd)
{
struct i2c_client *client = data->client;
struct i2c_msg msg[2];
int ret;
u8 buf[3] = { cmd, 0, 0};
msg[0].addr = client->addr;
msg[0].flags = client->flags;
msg[0].len = 3;
msg[0].buf = (char *) &buf;
msg[1].addr = client->addr;
msg[1].flags = client->flags | I2C_M_RD;
msg[1].len = VZ89X_REG_MEASUREMENT_SIZE;
msg[1].buf = (char *) &data->buffer;
ret = i2c_transfer(client->adapter, msg, 2);
return (ret == 2) ? 0 : ret;
}
static int vz89x_smbus_xfer(struct vz89x_data *data, u8 cmd)
{
struct i2c_client *client = data->client;
int ret;
int i;
ret = i2c_smbus_write_word_data(client, cmd, 0);
if (ret < 0)
return ret;
for (i = 0; i < VZ89X_REG_MEASUREMENT_SIZE; i++) {
ret = i2c_smbus_read_byte(client);
if (ret < 0)
return ret;
data->buffer[i] = ret;
}
return 0;
}
static int vz89x_get_measurement(struct vz89x_data *data)
{
int ret;
if (!time_after(jiffies, data->last_update + HZ))
return 0;
ret = data->xfer(data, VZ89X_REG_MEASUREMENT);
if (ret < 0)
return ret;
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
indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*data));
if (!indio_dev)
return -ENOMEM;
data = iio_priv(indio_dev);
if (i2c_check_functionality(client->adapter, I2C_FUNC_I2C))
data->xfer = vz89x_i2c_xfer;
else if (i2c_check_functionality(client->adapter,
I2C_FUNC_SMBUS_WORD_DATA | I2C_FUNC_SMBUS_BYTE))
data->xfer = vz89x_smbus_xfer;
else
return -EOPNOTSUPP;
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
