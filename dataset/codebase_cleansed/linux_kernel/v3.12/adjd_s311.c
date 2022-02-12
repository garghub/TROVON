static int adjd_s311_req_data(struct iio_dev *indio_dev)
{
struct adjd_s311_data *data = iio_priv(indio_dev);
int tries = 10;
int ret = i2c_smbus_write_byte_data(data->client, ADJD_S311_CTRL,
ADJD_S311_CTRL_GSSR);
if (ret < 0)
return ret;
while (tries--) {
ret = i2c_smbus_read_byte_data(data->client, ADJD_S311_CTRL);
if (ret < 0)
return ret;
if (!(ret & ADJD_S311_CTRL_GSSR))
break;
msleep(20);
}
if (tries < 0) {
dev_err(&data->client->dev,
"adjd_s311_req_data() failed, data not ready\n");
return -EIO;
}
return 0;
}
static int adjd_s311_read_data(struct iio_dev *indio_dev, u8 reg, int *val)
{
struct adjd_s311_data *data = iio_priv(indio_dev);
int ret = adjd_s311_req_data(indio_dev);
if (ret < 0)
return ret;
ret = i2c_smbus_read_word_data(data->client, reg);
if (ret < 0)
return ret;
*val = ret & ADJD_S311_DATA_MASK;
return 0;
}
static ssize_t adjd_s311_read_int_time(struct iio_dev *indio_dev,
uintptr_t private, const struct iio_chan_spec *chan, char *buf)
{
struct adjd_s311_data *data = iio_priv(indio_dev);
s32 ret;
ret = i2c_smbus_read_word_data(data->client,
ADJD_S311_INT_REG(chan->address));
if (ret < 0)
return ret;
return sprintf(buf, "%d\n", ret & ADJD_S311_INT_MASK);
}
static ssize_t adjd_s311_write_int_time(struct iio_dev *indio_dev,
uintptr_t private, const struct iio_chan_spec *chan, const char *buf,
size_t len)
{
struct adjd_s311_data *data = iio_priv(indio_dev);
unsigned long int_time;
int ret;
ret = kstrtoul(buf, 10, &int_time);
if (ret)
return ret;
if (int_time > ADJD_S311_INT_MASK)
return -EINVAL;
ret = i2c_smbus_write_word_data(data->client,
ADJD_S311_INT_REG(chan->address), int_time);
if (ret < 0)
return ret;
return len;
}
static irqreturn_t adjd_s311_trigger_handler(int irq, void *p)
{
struct iio_poll_func *pf = p;
struct iio_dev *indio_dev = pf->indio_dev;
struct adjd_s311_data *data = iio_priv(indio_dev);
s64 time_ns = iio_get_time_ns();
int len = 0;
int i, j = 0;
int ret = adjd_s311_req_data(indio_dev);
if (ret < 0)
goto done;
for_each_set_bit(i, indio_dev->active_scan_mask,
indio_dev->masklength) {
ret = i2c_smbus_read_word_data(data->client,
ADJD_S311_DATA_REG(i));
if (ret < 0)
goto done;
data->buffer[j++] = ret & ADJD_S311_DATA_MASK;
len += 2;
}
if (indio_dev->scan_timestamp)
*(s64 *)((u8 *)data->buffer + ALIGN(len, sizeof(s64)))
= time_ns;
iio_push_to_buffers(indio_dev, (u8 *)data->buffer);
done:
iio_trigger_notify_done(indio_dev->trig);
return IRQ_HANDLED;
}
static int adjd_s311_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2, long mask)
{
struct adjd_s311_data *data = iio_priv(indio_dev);
int ret;
switch (mask) {
case IIO_CHAN_INFO_RAW:
ret = adjd_s311_read_data(indio_dev,
ADJD_S311_DATA_REG(chan->address), val);
if (ret < 0)
return ret;
return IIO_VAL_INT;
case IIO_CHAN_INFO_HARDWAREGAIN:
ret = i2c_smbus_read_byte_data(data->client,
ADJD_S311_CAP_REG(chan->address));
if (ret < 0)
return ret;
*val = ret & ADJD_S311_CAP_MASK;
return IIO_VAL_INT;
}
return -EINVAL;
}
static int adjd_s311_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int val, int val2, long mask)
{
struct adjd_s311_data *data = iio_priv(indio_dev);
int ret;
switch (mask) {
case IIO_CHAN_INFO_HARDWAREGAIN:
if (val < 0 || val > ADJD_S311_CAP_MASK)
return -EINVAL;
ret = i2c_smbus_write_byte_data(data->client,
ADJD_S311_CAP_REG(chan->address), val);
return ret;
}
return -EINVAL;
}
static int adjd_s311_update_scan_mode(struct iio_dev *indio_dev,
const unsigned long *scan_mask)
{
struct adjd_s311_data *data = iio_priv(indio_dev);
kfree(data->buffer);
data->buffer = kmalloc(indio_dev->scan_bytes, GFP_KERNEL);
if (data->buffer == NULL)
return -ENOMEM;
return 0;
}
static int adjd_s311_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct adjd_s311_data *data;
struct iio_dev *indio_dev;
int err;
indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*data));
if (indio_dev == NULL)
return -ENOMEM;
data = iio_priv(indio_dev);
i2c_set_clientdata(client, indio_dev);
data->client = client;
indio_dev->dev.parent = &client->dev;
indio_dev->info = &adjd_s311_info;
indio_dev->name = ADJD_S311_DRV_NAME;
indio_dev->channels = adjd_s311_channels;
indio_dev->num_channels = ARRAY_SIZE(adjd_s311_channels);
indio_dev->modes = INDIO_DIRECT_MODE;
err = iio_triggered_buffer_setup(indio_dev, NULL,
adjd_s311_trigger_handler, NULL);
if (err < 0)
return err;
err = iio_device_register(indio_dev);
if (err)
goto exit_unreg_buffer;
dev_info(&client->dev, "ADJD-S311 color sensor registered\n");
return 0;
exit_unreg_buffer:
iio_triggered_buffer_cleanup(indio_dev);
return err;
}
static int adjd_s311_remove(struct i2c_client *client)
{
struct iio_dev *indio_dev = i2c_get_clientdata(client);
struct adjd_s311_data *data = iio_priv(indio_dev);
iio_device_unregister(indio_dev);
iio_triggered_buffer_cleanup(indio_dev);
kfree(data->buffer);
return 0;
}
