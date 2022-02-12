static s32 hmc5843_set_mode(struct hmc5843_data *data, u8 operating_mode)
{
int ret;
mutex_lock(&data->lock);
ret = i2c_smbus_write_byte_data(data->client, HMC5843_MODE_REG,
operating_mode & HMC5843_MODE_MASK);
if (ret >= 0)
data->operating_mode = operating_mode;
mutex_unlock(&data->lock);
return ret;
}
static int hmc5843_wait_measurement(struct hmc5843_data *data)
{
s32 result;
int tries = 150;
while (tries-- > 0) {
result = i2c_smbus_read_byte_data(data->client,
HMC5843_STATUS_REG);
if (result < 0)
return result;
if (result & HMC5843_DATA_READY)
break;
msleep(20);
}
if (tries < 0) {
dev_err(&data->client->dev, "data not ready\n");
return -EIO;
}
return 0;
}
static int hmc5843_read_measurement(struct hmc5843_data *data,
int idx, int *val)
{
s32 result;
__be16 values[3];
mutex_lock(&data->lock);
result = hmc5843_wait_measurement(data);
if (result < 0) {
mutex_unlock(&data->lock);
return result;
}
result = i2c_smbus_read_i2c_block_data(data->client,
HMC5843_DATA_OUT_MSB_REGS, sizeof(values), (u8 *) values);
mutex_unlock(&data->lock);
if (result < 0)
return -EINVAL;
*val = sign_extend32(be16_to_cpu(values[idx]), 15);
return IIO_VAL_INT;
}
static s32 hmc5843_set_meas_conf(struct hmc5843_data *data, u8 meas_conf)
{
int ret;
mutex_lock(&data->lock);
ret = i2c_smbus_write_byte_data(data->client, HMC5843_CONFIG_REG_A,
(meas_conf & HMC5843_MEAS_CONF_MASK) |
(data->rate << HMC5843_RATE_OFFSET));
if (ret >= 0)
data->meas_conf = meas_conf;
mutex_unlock(&data->lock);
return ret;
}
static ssize_t hmc5843_show_measurement_configuration(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct hmc5843_data *data = iio_priv(dev_to_iio_dev(dev));
return sprintf(buf, "%d\n", data->meas_conf);
}
static ssize_t hmc5843_set_measurement_configuration(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t count)
{
struct hmc5843_data *data = iio_priv(dev_to_iio_dev(dev));
unsigned long meas_conf = 0;
int ret;
ret = kstrtoul(buf, 10, &meas_conf);
if (ret)
return ret;
if (meas_conf >= HMC5843_MEAS_CONF_MASK)
return -EINVAL;
ret = hmc5843_set_meas_conf(data, meas_conf);
return (ret < 0) ? ret : count;
}
static ssize_t hmc5843_show_samp_freq_avail(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct hmc5843_data *data = iio_priv(dev_to_iio_dev(dev));
size_t len = 0;
int i;
for (i = 0; i < HMC5843_RATES; i++)
len += scnprintf(buf + len, PAGE_SIZE - len,
"%d.%d ", data->variant->regval_to_samp_freq[i][0],
data->variant->regval_to_samp_freq[i][1]);
buf[len - 1] = '\n';
return len;
}
static int hmc5843_set_samp_freq(struct hmc5843_data *data, u8 rate)
{
int ret;
mutex_lock(&data->lock);
ret = i2c_smbus_write_byte_data(data->client, HMC5843_CONFIG_REG_A,
data->meas_conf | (rate << HMC5843_RATE_OFFSET));
if (ret >= 0)
data->rate = rate;
mutex_unlock(&data->lock);
return ret;
}
static int hmc5843_get_samp_freq_index(struct hmc5843_data *data,
int val, int val2)
{
int i;
for (i = 0; i < HMC5843_RATES; i++)
if (val == data->variant->regval_to_samp_freq[i][0] &&
val2 == data->variant->regval_to_samp_freq[i][1])
return i;
return -EINVAL;
}
static int hmc5843_set_range_gain(struct hmc5843_data *data, u8 range)
{
int ret;
mutex_lock(&data->lock);
ret = i2c_smbus_write_byte_data(data->client, HMC5843_CONFIG_REG_B,
range << HMC5843_RANGE_GAIN_OFFSET);
if (ret >= 0)
data->range = range;
mutex_unlock(&data->lock);
return ret;
}
static ssize_t hmc5843_show_scale_avail(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct hmc5843_data *data = iio_priv(dev_to_iio_dev(dev));
size_t len = 0;
int i;
for (i = 0; i < HMC5843_RANGE_GAINS; i++)
len += scnprintf(buf + len, PAGE_SIZE - len,
"0.%09d ", data->variant->regval_to_nanoscale[i]);
buf[len - 1] = '\n';
return len;
}
static int hmc5843_get_scale_index(struct hmc5843_data *data, int val, int val2)
{
int i;
if (val != 0)
return -EINVAL;
for (i = 0; i < HMC5843_RANGE_GAINS; i++)
if (val2 == data->variant->regval_to_nanoscale[i])
return i;
return -EINVAL;
}
static int hmc5843_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2, long mask)
{
struct hmc5843_data *data = iio_priv(indio_dev);
switch (mask) {
case IIO_CHAN_INFO_RAW:
return hmc5843_read_measurement(data, chan->scan_index, val);
case IIO_CHAN_INFO_SCALE:
*val = 0;
*val2 = data->variant->regval_to_nanoscale[data->range];
return IIO_VAL_INT_PLUS_NANO;
case IIO_CHAN_INFO_SAMP_FREQ:
*val = data->variant->regval_to_samp_freq[data->rate][0];
*val2 = data->variant->regval_to_samp_freq[data->rate][1];
return IIO_VAL_INT_PLUS_MICRO;
}
return -EINVAL;
}
static int hmc5843_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int val, int val2, long mask)
{
struct hmc5843_data *data = iio_priv(indio_dev);
int rate, range;
switch (mask) {
case IIO_CHAN_INFO_SAMP_FREQ:
rate = hmc5843_get_samp_freq_index(data, val, val2);
if (rate < 0)
return -EINVAL;
return hmc5843_set_samp_freq(data, rate);
case IIO_CHAN_INFO_SCALE:
range = hmc5843_get_scale_index(data, val, val2);
if (range < 0)
return -EINVAL;
return hmc5843_set_range_gain(data, range);
default:
return -EINVAL;
}
}
static int hmc5843_write_raw_get_fmt(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan, long mask)
{
switch (mask) {
case IIO_CHAN_INFO_SAMP_FREQ:
return IIO_VAL_INT_PLUS_MICRO;
case IIO_CHAN_INFO_SCALE:
return IIO_VAL_INT_PLUS_NANO;
default:
return -EINVAL;
}
}
static irqreturn_t hmc5843_trigger_handler(int irq, void *p)
{
struct iio_poll_func *pf = p;
struct iio_dev *indio_dev = pf->indio_dev;
struct hmc5843_data *data = iio_priv(indio_dev);
int ret;
mutex_lock(&data->lock);
ret = hmc5843_wait_measurement(data);
if (ret < 0) {
mutex_unlock(&data->lock);
goto done;
}
ret = i2c_smbus_read_i2c_block_data(data->client,
HMC5843_DATA_OUT_MSB_REGS, 3 * sizeof(__be16),
(u8 *) data->buffer);
mutex_unlock(&data->lock);
if (ret < 0)
goto done;
iio_push_to_buffers_with_timestamp(indio_dev, data->buffer,
iio_get_time_ns());
done:
iio_trigger_notify_done(indio_dev->trig);
return IRQ_HANDLED;
}
static int hmc5843_init(struct hmc5843_data *data)
{
int ret;
u8 id[3];
ret = i2c_smbus_read_i2c_block_data(data->client, HMC5843_ID_REG,
sizeof(id), id);
if (ret < 0)
return ret;
if (id[0] != 'H' || id[1] != '4' || id[2] != '3') {
dev_err(&data->client->dev, "no HMC5843/5883/5883L sensor\n");
return -ENODEV;
}
ret = hmc5843_set_meas_conf(data, HMC5843_MEAS_CONF_NORMAL);
if (ret < 0)
return ret;
ret = hmc5843_set_samp_freq(data, HMC5843_RATE_DEFAULT);
if (ret < 0)
return ret;
ret = hmc5843_set_range_gain(data, HMC5843_RANGE_GAIN_DEFAULT);
if (ret < 0)
return ret;
return hmc5843_set_mode(data, HMC5843_MODE_CONVERSION_CONTINUOUS);
}
static int hmc5843_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct hmc5843_data *data;
struct iio_dev *indio_dev;
int ret;
indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*data));
if (indio_dev == NULL)
return -ENOMEM;
data = iio_priv(indio_dev);
data->client = client;
data->variant = &hmc5843_chip_info_tbl[id->driver_data];
mutex_init(&data->lock);
i2c_set_clientdata(client, indio_dev);
indio_dev->info = &hmc5843_info;
indio_dev->name = id->name;
indio_dev->dev.parent = &client->dev;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->channels = data->variant->channels;
indio_dev->num_channels = 4;
indio_dev->available_scan_masks = hmc5843_scan_masks;
ret = hmc5843_init(data);
if (ret < 0)
return ret;
ret = iio_triggered_buffer_setup(indio_dev, NULL,
hmc5843_trigger_handler, NULL);
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
static int hmc5843_remove(struct i2c_client *client)
{
struct iio_dev *indio_dev = i2c_get_clientdata(client);
iio_device_unregister(indio_dev);
iio_triggered_buffer_cleanup(indio_dev);
hmc5843_set_mode(iio_priv(indio_dev), HMC5843_MODE_SLEEP);
return 0;
}
static int hmc5843_suspend(struct device *dev)
{
struct hmc5843_data *data = iio_priv(i2c_get_clientdata(
to_i2c_client(dev)));
return hmc5843_set_mode(data, HMC5843_MODE_SLEEP);
}
static int hmc5843_resume(struct device *dev)
{
struct hmc5843_data *data = iio_priv(i2c_get_clientdata(
to_i2c_client(dev)));
return hmc5843_set_mode(data, HMC5843_MODE_CONVERSION_CONTINUOUS);
}
