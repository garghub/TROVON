static int tcs3472_req_data(struct tcs3472_data *data)
{
int tries = 50;
int ret;
while (tries--) {
ret = i2c_smbus_read_byte_data(data->client, TCS3472_STATUS);
if (ret < 0)
return ret;
if (ret & TCS3472_STATUS_AVALID)
break;
msleep(20);
}
if (tries < 0) {
dev_err(&data->client->dev, "data not ready\n");
return -EIO;
}
return 0;
}
static int tcs3472_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2, long mask)
{
struct tcs3472_data *data = iio_priv(indio_dev);
int ret;
switch (mask) {
case IIO_CHAN_INFO_RAW:
ret = iio_device_claim_direct_mode(indio_dev);
if (ret)
return ret;
ret = tcs3472_req_data(data);
if (ret < 0) {
iio_device_release_direct_mode(indio_dev);
return ret;
}
ret = i2c_smbus_read_word_data(data->client, chan->address);
iio_device_release_direct_mode(indio_dev);
if (ret < 0)
return ret;
*val = ret;
return IIO_VAL_INT;
case IIO_CHAN_INFO_CALIBSCALE:
*val = tcs3472_agains[data->control &
TCS3472_CONTROL_AGAIN_MASK];
return IIO_VAL_INT;
case IIO_CHAN_INFO_INT_TIME:
*val = 0;
*val2 = (256 - data->atime) * 2400;
return IIO_VAL_INT_PLUS_MICRO;
}
return -EINVAL;
}
static int tcs3472_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int val, int val2, long mask)
{
struct tcs3472_data *data = iio_priv(indio_dev);
int i;
switch (mask) {
case IIO_CHAN_INFO_CALIBSCALE:
if (val2 != 0)
return -EINVAL;
for (i = 0; i < ARRAY_SIZE(tcs3472_agains); i++) {
if (val == tcs3472_agains[i]) {
data->control &= ~TCS3472_CONTROL_AGAIN_MASK;
data->control |= i;
return i2c_smbus_write_byte_data(
data->client, TCS3472_CONTROL,
data->control);
}
}
return -EINVAL;
case IIO_CHAN_INFO_INT_TIME:
if (val != 0)
return -EINVAL;
for (i = 0; i < 256; i++) {
if (val2 == (256 - i) * 2400) {
data->atime = i;
return i2c_smbus_write_byte_data(
data->client, TCS3472_ATIME,
data->atime);
}
}
return -EINVAL;
}
return -EINVAL;
}
static irqreturn_t tcs3472_trigger_handler(int irq, void *p)
{
struct iio_poll_func *pf = p;
struct iio_dev *indio_dev = pf->indio_dev;
struct tcs3472_data *data = iio_priv(indio_dev);
int i, j = 0;
int ret = tcs3472_req_data(data);
if (ret < 0)
goto done;
for_each_set_bit(i, indio_dev->active_scan_mask,
indio_dev->masklength) {
ret = i2c_smbus_read_word_data(data->client,
TCS3472_CDATA + 2*i);
if (ret < 0)
goto done;
data->buffer[j++] = ret;
}
iio_push_to_buffers_with_timestamp(indio_dev, data->buffer,
iio_get_time_ns(indio_dev));
done:
iio_trigger_notify_done(indio_dev->trig);
return IRQ_HANDLED;
}
static ssize_t tcs3472_show_int_time_available(struct device *dev,
struct device_attribute *attr,
char *buf)
{
size_t len = 0;
int i;
for (i = 1; i <= 256; i++)
len += scnprintf(buf + len, PAGE_SIZE - len, "0.%06d ",
2400 * i);
buf[len - 1] = '\n';
return len;
}
static int tcs3472_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct tcs3472_data *data;
struct iio_dev *indio_dev;
int ret;
indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*data));
if (indio_dev == NULL)
return -ENOMEM;
data = iio_priv(indio_dev);
i2c_set_clientdata(client, indio_dev);
data->client = client;
indio_dev->dev.parent = &client->dev;
indio_dev->info = &tcs3472_info;
indio_dev->name = TCS3472_DRV_NAME;
indio_dev->channels = tcs3472_channels;
indio_dev->num_channels = ARRAY_SIZE(tcs3472_channels);
indio_dev->modes = INDIO_DIRECT_MODE;
ret = i2c_smbus_read_byte_data(data->client, TCS3472_ID);
if (ret < 0)
return ret;
if (ret == 0x44)
dev_info(&client->dev, "TCS34721/34725 found\n");
else if (ret == 0x4d)
dev_info(&client->dev, "TCS34723/34727 found\n");
else
return -ENODEV;
ret = i2c_smbus_read_byte_data(data->client, TCS3472_CONTROL);
if (ret < 0)
return ret;
data->control = ret;
ret = i2c_smbus_read_byte_data(data->client, TCS3472_ATIME);
if (ret < 0)
return ret;
data->atime = ret;
ret = i2c_smbus_read_byte_data(data->client, TCS3472_ENABLE);
if (ret < 0)
return ret;
data->enable = ret | TCS3472_ENABLE_PON | TCS3472_ENABLE_AEN;
ret = i2c_smbus_write_byte_data(data->client, TCS3472_ENABLE,
data->enable);
if (ret < 0)
return ret;
ret = iio_triggered_buffer_setup(indio_dev, NULL,
tcs3472_trigger_handler, NULL);
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
static int tcs3472_powerdown(struct tcs3472_data *data)
{
return i2c_smbus_write_byte_data(data->client, TCS3472_ENABLE,
data->enable & ~(TCS3472_ENABLE_AEN | TCS3472_ENABLE_PON));
}
static int tcs3472_remove(struct i2c_client *client)
{
struct iio_dev *indio_dev = i2c_get_clientdata(client);
iio_device_unregister(indio_dev);
iio_triggered_buffer_cleanup(indio_dev);
tcs3472_powerdown(iio_priv(indio_dev));
return 0;
}
static int tcs3472_suspend(struct device *dev)
{
struct tcs3472_data *data = iio_priv(i2c_get_clientdata(
to_i2c_client(dev)));
return tcs3472_powerdown(data);
}
static int tcs3472_resume(struct device *dev)
{
struct tcs3472_data *data = iio_priv(i2c_get_clientdata(
to_i2c_client(dev)));
return i2c_smbus_write_byte_data(data->client, TCS3472_ENABLE,
data->enable | (TCS3472_ENABLE_AEN | TCS3472_ENABLE_PON));
}
