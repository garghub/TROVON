static int mpl3115_request(struct mpl3115_data *data)
{
int ret, tries = 15;
ret = i2c_smbus_write_byte_data(data->client, MPL3115_CTRL_REG1,
data->ctrl_reg1 | MPL3115_CTRL_OST);
if (ret < 0)
return ret;
while (tries-- > 0) {
ret = i2c_smbus_read_byte_data(data->client, MPL3115_CTRL_REG1);
if (ret < 0)
return ret;
if (!(ret & MPL3115_CTRL_OST))
break;
msleep(20);
}
if (tries < 0) {
dev_err(&data->client->dev, "data not ready\n");
return -EIO;
}
return 0;
}
static int mpl3115_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2, long mask)
{
struct mpl3115_data *data = iio_priv(indio_dev);
s32 tmp = 0;
int ret;
switch (mask) {
case IIO_CHAN_INFO_RAW:
if (iio_buffer_enabled(indio_dev))
return -EBUSY;
switch (chan->type) {
case IIO_PRESSURE:
mutex_lock(&data->lock);
ret = mpl3115_request(data);
if (ret < 0) {
mutex_unlock(&data->lock);
return ret;
}
ret = i2c_smbus_read_i2c_block_data(data->client,
MPL3115_OUT_PRESS, 3, (u8 *) &tmp);
mutex_unlock(&data->lock);
if (ret < 0)
return ret;
*val = sign_extend32(be32_to_cpu(tmp) >> 12, 23);
return IIO_VAL_INT;
case IIO_TEMP:
mutex_lock(&data->lock);
ret = mpl3115_request(data);
if (ret < 0) {
mutex_unlock(&data->lock);
return ret;
}
ret = i2c_smbus_read_i2c_block_data(data->client,
MPL3115_OUT_TEMP, 2, (u8 *) &tmp);
mutex_unlock(&data->lock);
if (ret < 0)
return ret;
*val = sign_extend32(be32_to_cpu(tmp) >> 20, 15);
return IIO_VAL_INT;
default:
return -EINVAL;
}
case IIO_CHAN_INFO_SCALE:
switch (chan->type) {
case IIO_PRESSURE:
*val = 0;
*val2 = 250;
return IIO_VAL_INT_PLUS_MICRO;
case IIO_TEMP:
*val = 0;
*val2 = 62500;
return IIO_VAL_INT_PLUS_MICRO;
default:
return -EINVAL;
}
}
return -EINVAL;
}
static irqreturn_t mpl3115_trigger_handler(int irq, void *p)
{
struct iio_poll_func *pf = p;
struct iio_dev *indio_dev = pf->indio_dev;
struct mpl3115_data *data = iio_priv(indio_dev);
u8 buffer[16];
int ret, pos = 0;
mutex_lock(&data->lock);
ret = mpl3115_request(data);
if (ret < 0) {
mutex_unlock(&data->lock);
goto done;
}
memset(buffer, 0, sizeof(buffer));
if (test_bit(0, indio_dev->active_scan_mask)) {
ret = i2c_smbus_read_i2c_block_data(data->client,
MPL3115_OUT_PRESS, 3, &buffer[pos]);
if (ret < 0) {
mutex_unlock(&data->lock);
goto done;
}
pos += 4;
}
if (test_bit(1, indio_dev->active_scan_mask)) {
ret = i2c_smbus_read_i2c_block_data(data->client,
MPL3115_OUT_TEMP, 2, &buffer[pos]);
if (ret < 0) {
mutex_unlock(&data->lock);
goto done;
}
}
mutex_unlock(&data->lock);
iio_push_to_buffers_with_timestamp(indio_dev, buffer,
iio_get_time_ns());
done:
iio_trigger_notify_done(indio_dev->trig);
return IRQ_HANDLED;
}
static int mpl3115_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct mpl3115_data *data;
struct iio_dev *indio_dev;
int ret;
ret = i2c_smbus_read_byte_data(client, MPL3115_WHO_AM_I);
if (ret < 0)
return ret;
if (ret != MPL3115_DEVICE_ID)
return -ENODEV;
indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*data));
if (!indio_dev)
return -ENOMEM;
data = iio_priv(indio_dev);
data->client = client;
mutex_init(&data->lock);
i2c_set_clientdata(client, indio_dev);
indio_dev->info = &mpl3115_info;
indio_dev->name = id->name;
indio_dev->dev.parent = &client->dev;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->channels = mpl3115_channels;
indio_dev->num_channels = ARRAY_SIZE(mpl3115_channels);
i2c_smbus_write_byte_data(client, MPL3115_CTRL_REG1,
MPL3115_CTRL_RESET);
msleep(50);
data->ctrl_reg1 = MPL3115_CTRL_OS_258MS;
ret = i2c_smbus_write_byte_data(client, MPL3115_CTRL_REG1,
data->ctrl_reg1);
if (ret < 0)
return ret;
ret = iio_triggered_buffer_setup(indio_dev, NULL,
mpl3115_trigger_handler, NULL);
if (ret < 0)
return ret;
ret = iio_device_register(indio_dev);
if (ret < 0)
goto buffer_cleanup;
return 0;
buffer_cleanup:
iio_triggered_buffer_cleanup(indio_dev);
return ret;
}
static int mpl3115_standby(struct mpl3115_data *data)
{
return i2c_smbus_write_byte_data(data->client, MPL3115_CTRL_REG1,
data->ctrl_reg1 & ~MPL3115_CTRL_ACTIVE);
}
static int mpl3115_remove(struct i2c_client *client)
{
struct iio_dev *indio_dev = i2c_get_clientdata(client);
iio_device_unregister(indio_dev);
iio_triggered_buffer_cleanup(indio_dev);
mpl3115_standby(iio_priv(indio_dev));
return 0;
}
static int mpl3115_suspend(struct device *dev)
{
return mpl3115_standby(iio_priv(i2c_get_clientdata(
to_i2c_client(dev))));
}
static int mpl3115_resume(struct device *dev)
{
struct mpl3115_data *data = iio_priv(i2c_get_clientdata(
to_i2c_client(dev)));
return i2c_smbus_write_byte_data(data->client, MPL3115_CTRL_REG1,
data->ctrl_reg1);
}
