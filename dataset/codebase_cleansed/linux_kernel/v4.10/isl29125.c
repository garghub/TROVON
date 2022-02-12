static int isl29125_read_data(struct isl29125_data *data, int si)
{
int tries = 5;
int ret;
ret = i2c_smbus_write_byte_data(data->client, ISL29125_CONF1,
data->conf1 | isl29125_regs[si].mode);
if (ret < 0)
return ret;
msleep(101);
while (tries--) {
ret = i2c_smbus_read_byte_data(data->client, ISL29125_STATUS);
if (ret < 0)
goto fail;
if (ret & ISL29125_STATUS_CONV)
break;
msleep(20);
}
if (tries < 0) {
dev_err(&data->client->dev, "data not ready\n");
ret = -EIO;
goto fail;
}
ret = i2c_smbus_read_word_data(data->client, isl29125_regs[si].data);
fail:
i2c_smbus_write_byte_data(data->client, ISL29125_CONF1, data->conf1);
return ret;
}
static int isl29125_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2, long mask)
{
struct isl29125_data *data = iio_priv(indio_dev);
int ret;
switch (mask) {
case IIO_CHAN_INFO_RAW:
ret = iio_device_claim_direct_mode(indio_dev);
if (ret)
return ret;
ret = isl29125_read_data(data, chan->scan_index);
iio_device_release_direct_mode(indio_dev);
if (ret < 0)
return ret;
*val = ret;
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
*val = 0;
if (data->conf1 & ISL29125_MODE_RANGE)
*val2 = ISL29125_SENSING_RANGE_1;
else
*val2 = ISL29125_SENSING_RANGE_0;
return IIO_VAL_INT_PLUS_MICRO;
}
return -EINVAL;
}
static int isl29125_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int val, int val2, long mask)
{
struct isl29125_data *data = iio_priv(indio_dev);
switch (mask) {
case IIO_CHAN_INFO_SCALE:
if (val != 0)
return -EINVAL;
if (val2 == ISL29125_SENSING_RANGE_1)
data->conf1 |= ISL29125_MODE_RANGE;
else if (val2 == ISL29125_SENSING_RANGE_0)
data->conf1 &= ~ISL29125_MODE_RANGE;
else
return -EINVAL;
return i2c_smbus_write_byte_data(data->client, ISL29125_CONF1,
data->conf1);
default:
return -EINVAL;
}
}
static irqreturn_t isl29125_trigger_handler(int irq, void *p)
{
struct iio_poll_func *pf = p;
struct iio_dev *indio_dev = pf->indio_dev;
struct isl29125_data *data = iio_priv(indio_dev);
int i, j = 0;
for_each_set_bit(i, indio_dev->active_scan_mask,
indio_dev->masklength) {
int ret = i2c_smbus_read_word_data(data->client,
isl29125_regs[i].data);
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
static int isl29125_buffer_preenable(struct iio_dev *indio_dev)
{
struct isl29125_data *data = iio_priv(indio_dev);
data->conf1 |= ISL29125_MODE_RGB;
return i2c_smbus_write_byte_data(data->client, ISL29125_CONF1,
data->conf1);
}
static int isl29125_buffer_predisable(struct iio_dev *indio_dev)
{
struct isl29125_data *data = iio_priv(indio_dev);
int ret;
ret = iio_triggered_buffer_predisable(indio_dev);
if (ret < 0)
return ret;
data->conf1 &= ~ISL29125_MODE_MASK;
data->conf1 |= ISL29125_MODE_PD;
return i2c_smbus_write_byte_data(data->client, ISL29125_CONF1,
data->conf1);
}
static int isl29125_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct isl29125_data *data;
struct iio_dev *indio_dev;
int ret;
indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*data));
if (indio_dev == NULL)
return -ENOMEM;
data = iio_priv(indio_dev);
i2c_set_clientdata(client, indio_dev);
data->client = client;
indio_dev->dev.parent = &client->dev;
indio_dev->info = &isl29125_info;
indio_dev->name = ISL29125_DRV_NAME;
indio_dev->channels = isl29125_channels;
indio_dev->num_channels = ARRAY_SIZE(isl29125_channels);
indio_dev->modes = INDIO_DIRECT_MODE;
ret = i2c_smbus_read_byte_data(data->client, ISL29125_DEVICE_ID);
if (ret < 0)
return ret;
if (ret != ISL29125_ID)
return -ENODEV;
data->conf1 = ISL29125_MODE_PD | ISL29125_MODE_RANGE;
ret = i2c_smbus_write_byte_data(data->client, ISL29125_CONF1,
data->conf1);
if (ret < 0)
return ret;
ret = i2c_smbus_write_byte_data(data->client, ISL29125_STATUS, 0);
if (ret < 0)
return ret;
ret = iio_triggered_buffer_setup(indio_dev, NULL,
isl29125_trigger_handler, &isl29125_buffer_setup_ops);
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
static int isl29125_powerdown(struct isl29125_data *data)
{
return i2c_smbus_write_byte_data(data->client, ISL29125_CONF1,
(data->conf1 & ~ISL29125_MODE_MASK) | ISL29125_MODE_PD);
}
static int isl29125_remove(struct i2c_client *client)
{
struct iio_dev *indio_dev = i2c_get_clientdata(client);
iio_device_unregister(indio_dev);
iio_triggered_buffer_cleanup(indio_dev);
isl29125_powerdown(iio_priv(indio_dev));
return 0;
}
static int isl29125_suspend(struct device *dev)
{
struct isl29125_data *data = iio_priv(i2c_get_clientdata(
to_i2c_client(dev)));
return isl29125_powerdown(data);
}
static int isl29125_resume(struct device *dev)
{
struct isl29125_data *data = iio_priv(i2c_get_clientdata(
to_i2c_client(dev)));
return i2c_smbus_write_byte_data(data->client, ISL29125_CONF1,
data->conf1);
}
