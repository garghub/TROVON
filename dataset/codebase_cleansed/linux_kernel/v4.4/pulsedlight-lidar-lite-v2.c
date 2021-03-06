static int lidar_read_byte(struct lidar_data *data, int reg)
{
struct i2c_client *client = data->client;
int ret;
ret = i2c_smbus_write_byte(client, reg);
if (ret < 0) {
dev_err(&client->dev, "cannot write addr value");
return ret;
}
ret = i2c_smbus_read_byte(client);
if (ret < 0)
dev_err(&client->dev, "cannot read data value");
return ret;
}
static inline int lidar_write_control(struct lidar_data *data, int val)
{
return i2c_smbus_write_byte_data(data->client, LIDAR_REG_CONTROL, val);
}
static int lidar_read_measurement(struct lidar_data *data, u16 *reg)
{
int ret;
int val;
ret = lidar_read_byte(data, LIDAR_REG_DATA_HBYTE);
if (ret < 0)
return ret;
val = ret << 8;
ret = lidar_read_byte(data, LIDAR_REG_DATA_LBYTE);
if (ret < 0)
return ret;
val |= ret;
*reg = val;
return 0;
}
static int lidar_get_measurement(struct lidar_data *data, u16 *reg)
{
struct i2c_client *client = data->client;
int tries = 10;
int ret;
ret = lidar_write_control(data, LIDAR_REG_CONTROL_ACQUIRE);
if (ret < 0) {
dev_err(&client->dev, "cannot send start measurement command");
return ret;
}
while (tries--) {
usleep_range(1000, 2000);
ret = lidar_read_byte(data, LIDAR_REG_STATUS);
if (ret < 0)
break;
if (ret & LIDAR_REG_STATUS_INVALID) {
*reg = 0;
ret = -EINVAL;
break;
}
if (!(ret & LIDAR_REG_STATUS_READY)) {
ret = lidar_read_measurement(data, reg);
break;
}
ret = -EIO;
}
return ret;
}
static int lidar_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2, long mask)
{
struct lidar_data *data = iio_priv(indio_dev);
int ret = -EINVAL;
mutex_lock(&indio_dev->mlock);
if (iio_buffer_enabled(indio_dev) && mask == IIO_CHAN_INFO_RAW) {
ret = -EBUSY;
goto error_busy;
}
switch (mask) {
case IIO_CHAN_INFO_RAW: {
u16 reg;
ret = lidar_get_measurement(data, &reg);
if (!ret) {
*val = reg;
ret = IIO_VAL_INT;
}
break;
}
case IIO_CHAN_INFO_SCALE:
*val = 0;
*val2 = 10000;
ret = IIO_VAL_INT_PLUS_MICRO;
break;
}
error_busy:
mutex_unlock(&indio_dev->mlock);
return ret;
}
static irqreturn_t lidar_trigger_handler(int irq, void *private)
{
struct iio_poll_func *pf = private;
struct iio_dev *indio_dev = pf->indio_dev;
struct lidar_data *data = iio_priv(indio_dev);
int ret;
ret = lidar_get_measurement(data, data->buffer);
if (!ret) {
iio_push_to_buffers_with_timestamp(indio_dev, data->buffer,
iio_get_time_ns());
} else if (ret != -EINVAL) {
dev_err(&data->client->dev, "cannot read LIDAR measurement");
}
iio_trigger_notify_done(indio_dev->trig);
return IRQ_HANDLED;
}
static int lidar_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct lidar_data *data;
struct iio_dev *indio_dev;
int ret;
indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*data));
if (!indio_dev)
return -ENOMEM;
indio_dev->info = &lidar_info;
indio_dev->name = LIDAR_DRV_NAME;
indio_dev->channels = lidar_channels;
indio_dev->num_channels = ARRAY_SIZE(lidar_channels);
indio_dev->modes = INDIO_DIRECT_MODE;
data = iio_priv(indio_dev);
i2c_set_clientdata(client, indio_dev);
data->client = client;
data->indio_dev = indio_dev;
ret = iio_triggered_buffer_setup(indio_dev, NULL,
lidar_trigger_handler, NULL);
if (ret)
return ret;
ret = iio_device_register(indio_dev);
if (ret)
goto error_unreg_buffer;
return 0;
error_unreg_buffer:
iio_triggered_buffer_cleanup(indio_dev);
return ret;
}
static int lidar_remove(struct i2c_client *client)
{
struct iio_dev *indio_dev = i2c_get_clientdata(client);
iio_device_unregister(indio_dev);
iio_triggered_buffer_cleanup(indio_dev);
return 0;
}
