static bool vz89x_measurement_is_valid(struct vz89x_data *data)
{
if (data->buffer[VZ89X_VOC_SHORT_IDX] == 0)
return true;
return !!(data->buffer[data->chip->read_size - 1] > 0);
}
static bool vz89te_measurement_is_valid(struct vz89x_data *data)
{
u8 crc = 0;
int i, sum = 0;
for (i = 0; i < (data->chip->read_size - 1); i++) {
sum = crc + data->buffer[i];
crc = sum;
crc += sum / 256;
}
return !((0xff - crc) == data->buffer[data->chip->read_size - 1]);
}
static int vz89x_i2c_xfer(struct vz89x_data *data, u8 cmd)
{
const struct vz89x_chip_data *chip = data->chip;
struct i2c_client *client = data->client;
struct i2c_msg msg[2];
int ret;
u8 buf[6] = { cmd, 0, 0, 0, 0, 0xf3 };
msg[0].addr = client->addr;
msg[0].flags = client->flags;
msg[0].len = chip->write_size;
msg[0].buf = (char *) &buf;
msg[1].addr = client->addr;
msg[1].flags = client->flags | I2C_M_RD;
msg[1].len = chip->read_size;
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
for (i = 0; i < data->chip->read_size; i++) {
ret = i2c_smbus_read_byte(client);
if (ret < 0)
return ret;
data->buffer[i] = ret;
}
return 0;
}
static int vz89x_get_measurement(struct vz89x_data *data)
{
const struct vz89x_chip_data *chip = data->chip;
int ret;
if (!time_after(jiffies, data->last_update + HZ))
return data->is_valid ? 0 : -EAGAIN;
data->is_valid = false;
data->last_update = jiffies;
ret = data->xfer(data, chip->cmd);
if (ret < 0)
return ret;
ret = chip->valid(data);
if (ret)
return -EAGAIN;
data->is_valid = true;
return 0;
}
static int vz89x_get_resistance_reading(struct vz89x_data *data,
struct iio_chan_spec const *chan,
int *val)
{
u8 *tmp = (u8 *) &data->buffer[chan->address];
switch (chan->scan_type.endianness) {
case IIO_LE:
*val = le32_to_cpup((__le32 *) tmp) & GENMASK(23, 0);
break;
case IIO_BE:
*val = be32_to_cpup((__be32 *) tmp) >> 8;
break;
default:
return -EINVAL;
}
return 0;
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
switch (chan->type) {
case IIO_CONCENTRATION:
*val = data->buffer[chan->address];
return IIO_VAL_INT;
case IIO_RESISTANCE:
ret = vz89x_get_resistance_reading(data, chan, val);
if (!ret)
return IIO_VAL_INT;
break;
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
switch (chan->channel2) {
case IIO_MOD_CO2:
*val = 44;
*val2 = 250000;
return IIO_VAL_INT_PLUS_MICRO;
case IIO_MOD_VOC:
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
const struct of_device_id *of_id;
int chip_id;
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
of_id = of_match_device(vz89x_dt_ids, &client->dev);
if (!of_id)
chip_id = id->driver_data;
else
chip_id = (unsigned long)of_id->data;
i2c_set_clientdata(client, indio_dev);
data->client = client;
data->chip = &vz89x_chips[chip_id];
data->last_update = jiffies - HZ;
mutex_init(&data->lock);
indio_dev->dev.parent = &client->dev;
indio_dev->info = &vz89x_info;
indio_dev->name = dev_name(&client->dev);
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->channels = data->chip->channels;
indio_dev->num_channels = data->chip->num_channels;
return devm_iio_device_register(&client->dev, indio_dev);
}
