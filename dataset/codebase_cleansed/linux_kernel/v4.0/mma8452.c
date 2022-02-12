static int mma8452_drdy(struct mma8452_data *data)
{
int tries = 150;
while (tries-- > 0) {
int ret = i2c_smbus_read_byte_data(data->client,
MMA8452_STATUS);
if (ret < 0)
return ret;
if ((ret & MMA8452_STATUS_DRDY) == MMA8452_STATUS_DRDY)
return 0;
msleep(20);
}
dev_err(&data->client->dev, "data not ready\n");
return -EIO;
}
static int mma8452_read(struct mma8452_data *data, __be16 buf[3])
{
int ret = mma8452_drdy(data);
if (ret < 0)
return ret;
return i2c_smbus_read_i2c_block_data(data->client,
MMA8452_OUT_X, 3 * sizeof(__be16), (u8 *) buf);
}
static ssize_t mma8452_show_samp_freq_avail(struct device *dev,
struct device_attribute *attr, char *buf)
{
return mma8452_show_int_plus_micros(buf, mma8452_samp_freq,
ARRAY_SIZE(mma8452_samp_freq));
}
static ssize_t mma8452_show_scale_avail(struct device *dev,
struct device_attribute *attr, char *buf)
{
return mma8452_show_int_plus_micros(buf, mma8452_scales,
ARRAY_SIZE(mma8452_scales));
}
static int mma8452_get_samp_freq_index(struct mma8452_data *data,
int val, int val2)
{
return mma8452_get_int_plus_micros_index(mma8452_samp_freq,
ARRAY_SIZE(mma8452_samp_freq), val, val2);
}
static int mma8452_get_scale_index(struct mma8452_data *data,
int val, int val2)
{
return mma8452_get_int_plus_micros_index(mma8452_scales,
ARRAY_SIZE(mma8452_scales), val, val2);
}
static int mma8452_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2, long mask)
{
struct mma8452_data *data = iio_priv(indio_dev);
__be16 buffer[3];
int i, ret;
switch (mask) {
case IIO_CHAN_INFO_RAW:
if (iio_buffer_enabled(indio_dev))
return -EBUSY;
mutex_lock(&data->lock);
ret = mma8452_read(data, buffer);
mutex_unlock(&data->lock);
if (ret < 0)
return ret;
*val = sign_extend32(
be16_to_cpu(buffer[chan->scan_index]) >> 4, 11);
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
i = data->data_cfg & MMA8452_DATA_CFG_FS_MASK;
*val = mma8452_scales[i][0];
*val2 = mma8452_scales[i][1];
return IIO_VAL_INT_PLUS_MICRO;
case IIO_CHAN_INFO_SAMP_FREQ:
i = (data->ctrl_reg1 & MMA8452_CTRL_DR_MASK) >>
MMA8452_CTRL_DR_SHIFT;
*val = mma8452_samp_freq[i][0];
*val2 = mma8452_samp_freq[i][1];
return IIO_VAL_INT_PLUS_MICRO;
case IIO_CHAN_INFO_CALIBBIAS:
ret = i2c_smbus_read_byte_data(data->client, MMA8452_OFF_X +
chan->scan_index);
if (ret < 0)
return ret;
*val = sign_extend32(ret, 7);
return IIO_VAL_INT;
}
return -EINVAL;
}
static int mma8452_standby(struct mma8452_data *data)
{
return i2c_smbus_write_byte_data(data->client, MMA8452_CTRL_REG1,
data->ctrl_reg1 & ~MMA8452_CTRL_ACTIVE);
}
static int mma8452_active(struct mma8452_data *data)
{
return i2c_smbus_write_byte_data(data->client, MMA8452_CTRL_REG1,
data->ctrl_reg1);
}
static int mma8452_change_config(struct mma8452_data *data, u8 reg, u8 val)
{
int ret;
mutex_lock(&data->lock);
ret = mma8452_standby(data);
if (ret < 0)
goto fail;
ret = i2c_smbus_write_byte_data(data->client, reg, val);
if (ret < 0)
goto fail;
ret = mma8452_active(data);
if (ret < 0)
goto fail;
ret = 0;
fail:
mutex_unlock(&data->lock);
return ret;
}
static int mma8452_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int val, int val2, long mask)
{
struct mma8452_data *data = iio_priv(indio_dev);
int i;
if (iio_buffer_enabled(indio_dev))
return -EBUSY;
switch (mask) {
case IIO_CHAN_INFO_SAMP_FREQ:
i = mma8452_get_samp_freq_index(data, val, val2);
if (i < 0)
return -EINVAL;
data->ctrl_reg1 &= ~MMA8452_CTRL_DR_MASK;
data->ctrl_reg1 |= i << MMA8452_CTRL_DR_SHIFT;
return mma8452_change_config(data, MMA8452_CTRL_REG1,
data->ctrl_reg1);
case IIO_CHAN_INFO_SCALE:
i = mma8452_get_scale_index(data, val, val2);
if (i < 0)
return -EINVAL;
data->data_cfg &= ~MMA8452_DATA_CFG_FS_MASK;
data->data_cfg |= i;
return mma8452_change_config(data, MMA8452_DATA_CFG,
data->data_cfg);
case IIO_CHAN_INFO_CALIBBIAS:
if (val < -128 || val > 127)
return -EINVAL;
return mma8452_change_config(data, MMA8452_OFF_X +
chan->scan_index, val);
default:
return -EINVAL;
}
}
static irqreturn_t mma8452_trigger_handler(int irq, void *p)
{
struct iio_poll_func *pf = p;
struct iio_dev *indio_dev = pf->indio_dev;
struct mma8452_data *data = iio_priv(indio_dev);
u8 buffer[16];
int ret;
ret = mma8452_read(data, (__be16 *) buffer);
if (ret < 0)
goto done;
iio_push_to_buffers_with_timestamp(indio_dev, buffer,
iio_get_time_ns());
done:
iio_trigger_notify_done(indio_dev->trig);
return IRQ_HANDLED;
}
static int mma8452_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct mma8452_data *data;
struct iio_dev *indio_dev;
int ret;
ret = i2c_smbus_read_byte_data(client, MMA8452_WHO_AM_I);
if (ret < 0)
return ret;
if (ret != MMA8452_DEVICE_ID)
return -ENODEV;
indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*data));
if (!indio_dev)
return -ENOMEM;
data = iio_priv(indio_dev);
data->client = client;
mutex_init(&data->lock);
i2c_set_clientdata(client, indio_dev);
indio_dev->info = &mma8452_info;
indio_dev->name = id->name;
indio_dev->dev.parent = &client->dev;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->channels = mma8452_channels;
indio_dev->num_channels = ARRAY_SIZE(mma8452_channels);
indio_dev->available_scan_masks = mma8452_scan_masks;
data->ctrl_reg1 = MMA8452_CTRL_ACTIVE |
(MMA8452_CTRL_DR_DEFAULT << MMA8452_CTRL_DR_SHIFT);
ret = i2c_smbus_write_byte_data(client, MMA8452_CTRL_REG1,
data->ctrl_reg1);
if (ret < 0)
return ret;
data->data_cfg = MMA8452_DATA_CFG_FS_2G;
ret = i2c_smbus_write_byte_data(client, MMA8452_DATA_CFG,
data->data_cfg);
if (ret < 0)
return ret;
ret = iio_triggered_buffer_setup(indio_dev, NULL,
mma8452_trigger_handler, NULL);
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
static int mma8452_remove(struct i2c_client *client)
{
struct iio_dev *indio_dev = i2c_get_clientdata(client);
iio_device_unregister(indio_dev);
iio_triggered_buffer_cleanup(indio_dev);
mma8452_standby(iio_priv(indio_dev));
return 0;
}
static int mma8452_suspend(struct device *dev)
{
return mma8452_standby(iio_priv(i2c_get_clientdata(
to_i2c_client(dev))));
}
static int mma8452_resume(struct device *dev)
{
return mma8452_active(iio_priv(i2c_get_clientdata(
to_i2c_client(dev))));
}
