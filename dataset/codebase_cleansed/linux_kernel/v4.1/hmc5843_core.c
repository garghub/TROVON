static s32 hmc5843_set_mode(struct hmc5843_data *data, u8 operating_mode)
{
int ret;
mutex_lock(&data->lock);
ret = regmap_update_bits(data->regmap, HMC5843_MODE_REG,
HMC5843_MODE_MASK, operating_mode);
mutex_unlock(&data->lock);
return ret;
}
static int hmc5843_wait_measurement(struct hmc5843_data *data)
{
int tries = 150;
unsigned int val;
int ret;
while (tries-- > 0) {
ret = regmap_read(data->regmap, HMC5843_STATUS_REG, &val);
if (ret < 0)
return ret;
if (val & HMC5843_DATA_READY)
break;
msleep(20);
}
if (tries < 0) {
dev_err(data->dev, "data not ready\n");
return -EIO;
}
return 0;
}
static int hmc5843_read_measurement(struct hmc5843_data *data,
int idx, int *val)
{
__be16 values[3];
int ret;
mutex_lock(&data->lock);
ret = hmc5843_wait_measurement(data);
if (ret < 0) {
mutex_unlock(&data->lock);
return ret;
}
ret = regmap_bulk_read(data->regmap, HMC5843_DATA_OUT_MSB_REGS,
values, sizeof(values));
mutex_unlock(&data->lock);
if (ret < 0)
return ret;
*val = sign_extend32(be16_to_cpu(values[idx]), 15);
return IIO_VAL_INT;
}
static int hmc5843_set_meas_conf(struct hmc5843_data *data, u8 meas_conf)
{
int ret;
mutex_lock(&data->lock);
ret = regmap_update_bits(data->regmap, HMC5843_CONFIG_REG_A,
HMC5843_MEAS_CONF_MASK, meas_conf);
mutex_unlock(&data->lock);
return ret;
}
static
ssize_t hmc5843_show_measurement_configuration(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct hmc5843_data *data = iio_priv(dev_to_iio_dev(dev));
unsigned int val;
int ret;
ret = regmap_read(data->regmap, HMC5843_CONFIG_REG_A, &val);
if (ret)
return ret;
val &= HMC5843_MEAS_CONF_MASK;
return sprintf(buf, "%d\n", val);
}
static
ssize_t hmc5843_set_measurement_configuration(struct device *dev,
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
static
ssize_t hmc5843_show_samp_freq_avail(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct hmc5843_data *data = iio_priv(dev_to_iio_dev(dev));
size_t len = 0;
int i;
for (i = 0; i < data->variant->n_regval_to_samp_freq; i++)
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
ret = regmap_update_bits(data->regmap, HMC5843_CONFIG_REG_A,
HMC5843_RATE_MASK,
rate << HMC5843_RATE_OFFSET);
mutex_unlock(&data->lock);
return ret;
}
static int hmc5843_get_samp_freq_index(struct hmc5843_data *data,
int val, int val2)
{
int i;
for (i = 0; i < data->variant->n_regval_to_samp_freq; i++)
if (val == data->variant->regval_to_samp_freq[i][0] &&
val2 == data->variant->regval_to_samp_freq[i][1])
return i;
return -EINVAL;
}
static int hmc5843_set_range_gain(struct hmc5843_data *data, u8 range)
{
int ret;
mutex_lock(&data->lock);
ret = regmap_update_bits(data->regmap, HMC5843_CONFIG_REG_B,
HMC5843_RANGE_GAIN_MASK,
range << HMC5843_RANGE_GAIN_OFFSET);
mutex_unlock(&data->lock);
return ret;
}
static ssize_t hmc5843_show_scale_avail(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct hmc5843_data *data = iio_priv(dev_to_iio_dev(dev));
size_t len = 0;
int i;
for (i = 0; i < data->variant->n_regval_to_nanoscale; i++)
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
for (i = 0; i < data->variant->n_regval_to_nanoscale; i++)
if (val2 == data->variant->regval_to_nanoscale[i])
return i;
return -EINVAL;
}
static int hmc5843_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2, long mask)
{
struct hmc5843_data *data = iio_priv(indio_dev);
unsigned int rval;
int ret;
switch (mask) {
case IIO_CHAN_INFO_RAW:
return hmc5843_read_measurement(data, chan->scan_index, val);
case IIO_CHAN_INFO_SCALE:
ret = regmap_read(data->regmap, HMC5843_CONFIG_REG_B, &rval);
if (ret < 0)
return ret;
rval >>= HMC5843_RANGE_GAIN_OFFSET;
*val = 0;
*val2 = data->variant->regval_to_nanoscale[rval];
return IIO_VAL_INT_PLUS_NANO;
case IIO_CHAN_INFO_SAMP_FREQ:
ret = regmap_read(data->regmap, HMC5843_CONFIG_REG_A, &rval);
if (ret < 0)
return ret;
rval >>= HMC5843_RATE_OFFSET;
*val = data->variant->regval_to_samp_freq[rval][0];
*val2 = data->variant->regval_to_samp_freq[rval][1];
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
struct iio_chan_spec const *chan,
long mask)
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
ret = regmap_bulk_read(data->regmap, HMC5843_DATA_OUT_MSB_REGS,
data->buffer, 3 * sizeof(__be16));
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
ret = regmap_bulk_read(data->regmap, HMC5843_ID_REG,
id, ARRAY_SIZE(id));
if (ret < 0)
return ret;
if (id[0] != 'H' || id[1] != '4' || id[2] != '3') {
dev_err(data->dev, "no HMC5843/5883/5883L/5983 sensor\n");
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
int hmc5843_common_suspend(struct device *dev)
{
return hmc5843_set_mode(iio_priv(dev_get_drvdata(dev)),
HMC5843_MODE_CONVERSION_CONTINUOUS);
}
int hmc5843_common_resume(struct device *dev)
{
return hmc5843_set_mode(iio_priv(dev_get_drvdata(dev)),
HMC5843_MODE_SLEEP);
}
int hmc5843_common_probe(struct device *dev, struct regmap *regmap,
enum hmc5843_ids id)
{
struct hmc5843_data *data;
struct iio_dev *indio_dev;
int ret;
indio_dev = devm_iio_device_alloc(dev, sizeof(*data));
if (!indio_dev)
return -ENOMEM;
dev_set_drvdata(dev, indio_dev);
data = iio_priv(indio_dev);
data->dev = dev;
data->regmap = regmap;
data->variant = &hmc5843_chip_info_tbl[id];
mutex_init(&data->lock);
indio_dev->dev.parent = dev;
indio_dev->name = dev->driver->name;
indio_dev->info = &hmc5843_info;
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
goto buffer_setup_err;
ret = iio_device_register(indio_dev);
if (ret < 0)
goto buffer_cleanup;
return 0;
buffer_cleanup:
iio_triggered_buffer_cleanup(indio_dev);
buffer_setup_err:
hmc5843_set_mode(iio_priv(indio_dev), HMC5843_MODE_SLEEP);
return ret;
}
int hmc5843_common_remove(struct device *dev)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
iio_device_unregister(indio_dev);
iio_triggered_buffer_cleanup(indio_dev);
hmc5843_set_mode(iio_priv(indio_dev), HMC5843_MODE_SLEEP);
return 0;
}
