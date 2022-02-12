static int ltr501_drdy(struct ltr501_data *data, u8 drdy_mask)
{
int tries = 100;
int ret;
while (tries--) {
ret = i2c_smbus_read_byte_data(data->client,
LTR501_ALS_PS_STATUS);
if (ret < 0)
return ret;
if ((ret & drdy_mask) == drdy_mask)
return 0;
msleep(25);
}
dev_err(&data->client->dev, "ltr501_drdy() failed, data not ready\n");
return -EIO;
}
static int ltr501_read_als(struct ltr501_data *data, __le16 buf[2])
{
int ret = ltr501_drdy(data, LTR501_STATUS_ALS_RDY);
if (ret < 0)
return ret;
return i2c_smbus_read_i2c_block_data(data->client,
LTR501_ALS_DATA1, 2 * sizeof(__le16), (u8 *) buf);
}
static int ltr501_read_ps(struct ltr501_data *data)
{
int ret = ltr501_drdy(data, LTR501_STATUS_PS_RDY);
if (ret < 0)
return ret;
return i2c_smbus_read_word_data(data->client, LTR501_PS_DATA);
}
static int ltr501_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2, long mask)
{
struct ltr501_data *data = iio_priv(indio_dev);
__le16 buf[2];
int ret, i;
switch (mask) {
case IIO_CHAN_INFO_RAW:
if (iio_buffer_enabled(indio_dev))
return -EBUSY;
switch (chan->type) {
case IIO_INTENSITY:
mutex_lock(&data->lock_als);
ret = ltr501_read_als(data, buf);
mutex_unlock(&data->lock_als);
if (ret < 0)
return ret;
*val = le16_to_cpu(chan->address == LTR501_ALS_DATA1 ?
buf[0] : buf[1]);
return IIO_VAL_INT;
case IIO_PROXIMITY:
mutex_lock(&data->lock_ps);
ret = ltr501_read_ps(data);
mutex_unlock(&data->lock_ps);
if (ret < 0)
return ret;
*val = ret & LTR501_PS_DATA_MASK;
return IIO_VAL_INT;
default:
return -EINVAL;
}
case IIO_CHAN_INFO_SCALE:
switch (chan->type) {
case IIO_INTENSITY:
if (data->als_contr & LTR501_CONTR_ALS_GAIN_MASK) {
*val = 0;
*val2 = 5000;
return IIO_VAL_INT_PLUS_MICRO;
} else {
*val = 1;
*val2 = 0;
return IIO_VAL_INT;
}
case IIO_PROXIMITY:
i = (data->ps_contr & LTR501_CONTR_PS_GAIN_MASK) >>
LTR501_CONTR_PS_GAIN_SHIFT;
*val = ltr501_ps_gain[i][0];
*val2 = ltr501_ps_gain[i][1];
return IIO_VAL_INT_PLUS_MICRO;
default:
return -EINVAL;
}
}
return -EINVAL;
}
static int ltr501_get_ps_gain_index(int val, int val2)
{
int i;
for (i = 0; i < ARRAY_SIZE(ltr501_ps_gain); i++)
if (val == ltr501_ps_gain[i][0] && val2 == ltr501_ps_gain[i][1])
return i;
return -1;
}
static int ltr501_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int val, int val2, long mask)
{
struct ltr501_data *data = iio_priv(indio_dev);
int i;
if (iio_buffer_enabled(indio_dev))
return -EBUSY;
switch (mask) {
case IIO_CHAN_INFO_SCALE:
switch (chan->type) {
case IIO_INTENSITY:
if (val == 0 && val2 == 5000)
data->als_contr |= LTR501_CONTR_ALS_GAIN_MASK;
else if (val == 1 && val2 == 0)
data->als_contr &= ~LTR501_CONTR_ALS_GAIN_MASK;
else
return -EINVAL;
return i2c_smbus_write_byte_data(data->client,
LTR501_ALS_CONTR, data->als_contr);
case IIO_PROXIMITY:
i = ltr501_get_ps_gain_index(val, val2);
if (i < 0)
return -EINVAL;
data->ps_contr &= ~LTR501_CONTR_PS_GAIN_MASK;
data->ps_contr |= i << LTR501_CONTR_PS_GAIN_SHIFT;
return i2c_smbus_write_byte_data(data->client,
LTR501_PS_CONTR, data->ps_contr);
default:
return -EINVAL;
}
}
return -EINVAL;
}
static int ltr501_write_contr(struct i2c_client *client, u8 als_val, u8 ps_val)
{
int ret = i2c_smbus_write_byte_data(client, LTR501_ALS_CONTR, als_val);
if (ret < 0)
return ret;
return i2c_smbus_write_byte_data(client, LTR501_PS_CONTR, ps_val);
}
static irqreturn_t ltr501_trigger_handler(int irq, void *p)
{
struct iio_poll_func *pf = p;
struct iio_dev *indio_dev = pf->indio_dev;
struct ltr501_data *data = iio_priv(indio_dev);
u16 buf[8];
__le16 als_buf[2];
u8 mask = 0;
int j = 0;
int ret;
memset(buf, 0, sizeof(buf));
if (test_bit(0, indio_dev->active_scan_mask) ||
test_bit(1, indio_dev->active_scan_mask))
mask |= LTR501_STATUS_ALS_RDY;
if (test_bit(2, indio_dev->active_scan_mask))
mask |= LTR501_STATUS_PS_RDY;
ret = ltr501_drdy(data, mask);
if (ret < 0)
goto done;
if (mask & LTR501_STATUS_ALS_RDY) {
ret = i2c_smbus_read_i2c_block_data(data->client,
LTR501_ALS_DATA1, sizeof(als_buf), (u8 *) als_buf);
if (ret < 0)
return ret;
if (test_bit(0, indio_dev->active_scan_mask))
buf[j++] = le16_to_cpu(als_buf[1]);
if (test_bit(1, indio_dev->active_scan_mask))
buf[j++] = le16_to_cpu(als_buf[0]);
}
if (mask & LTR501_STATUS_PS_RDY) {
ret = i2c_smbus_read_word_data(data->client, LTR501_PS_DATA);
if (ret < 0)
goto done;
buf[j++] = ret & LTR501_PS_DATA_MASK;
}
iio_push_to_buffers_with_timestamp(indio_dev, buf,
iio_get_time_ns());
done:
iio_trigger_notify_done(indio_dev->trig);
return IRQ_HANDLED;
}
static int ltr501_init(struct ltr501_data *data)
{
int ret;
ret = i2c_smbus_read_byte_data(data->client, LTR501_ALS_CONTR);
if (ret < 0)
return ret;
data->als_contr = ret | LTR501_CONTR_ACTIVE;
ret = i2c_smbus_read_byte_data(data->client, LTR501_PS_CONTR);
if (ret < 0)
return ret;
data->ps_contr = ret | LTR501_CONTR_ACTIVE;
return ltr501_write_contr(data->client, data->als_contr,
data->ps_contr);
}
static int ltr501_powerdown(struct ltr501_data *data)
{
return ltr501_write_contr(data->client,
data->als_contr & ~LTR501_CONTR_ACTIVE,
data->ps_contr & ~LTR501_CONTR_ACTIVE);
}
static int ltr501_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct ltr501_data *data;
struct iio_dev *indio_dev;
int ret;
indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*data));
if (!indio_dev)
return -ENOMEM;
data = iio_priv(indio_dev);
i2c_set_clientdata(client, indio_dev);
data->client = client;
mutex_init(&data->lock_als);
mutex_init(&data->lock_ps);
ret = i2c_smbus_read_byte_data(data->client, LTR501_PART_ID);
if (ret < 0)
return ret;
if ((ret >> 4) != 0x8)
return -ENODEV;
indio_dev->dev.parent = &client->dev;
indio_dev->info = &ltr501_info;
indio_dev->channels = ltr501_channels;
indio_dev->num_channels = ARRAY_SIZE(ltr501_channels);
indio_dev->name = LTR501_DRV_NAME;
indio_dev->modes = INDIO_DIRECT_MODE;
ret = ltr501_init(data);
if (ret < 0)
return ret;
ret = iio_triggered_buffer_setup(indio_dev, NULL,
ltr501_trigger_handler, NULL);
if (ret)
goto powerdown_on_error;
ret = iio_device_register(indio_dev);
if (ret)
goto error_unreg_buffer;
return 0;
error_unreg_buffer:
iio_triggered_buffer_cleanup(indio_dev);
powerdown_on_error:
ltr501_powerdown(data);
return ret;
}
static int ltr501_remove(struct i2c_client *client)
{
struct iio_dev *indio_dev = i2c_get_clientdata(client);
iio_device_unregister(indio_dev);
iio_triggered_buffer_cleanup(indio_dev);
ltr501_powerdown(iio_priv(indio_dev));
return 0;
}
static int ltr501_suspend(struct device *dev)
{
struct ltr501_data *data = iio_priv(i2c_get_clientdata(
to_i2c_client(dev)));
return ltr501_powerdown(data);
}
static int ltr501_resume(struct device *dev)
{
struct ltr501_data *data = iio_priv(i2c_get_clientdata(
to_i2c_client(dev)));
return ltr501_write_contr(data->client, data->als_contr,
data->ps_contr);
}
