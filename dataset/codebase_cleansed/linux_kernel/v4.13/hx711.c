static int hx711_get_gain_to_pulse(int gain)
{
int i;
for (i = 0; i < HX711_GAIN_MAX; i++)
if (hx711_gain_to_scale[i].gain == gain)
return hx711_gain_to_scale[i].gain_pulse;
return 1;
}
static int hx711_get_gain_to_scale(int gain)
{
int i;
for (i = 0; i < HX711_GAIN_MAX; i++)
if (hx711_gain_to_scale[i].gain == gain)
return hx711_gain_to_scale[i].scale;
return 0;
}
static int hx711_get_scale_to_gain(int scale)
{
int i;
for (i = 0; i < HX711_GAIN_MAX; i++)
if (hx711_gain_to_scale[i].scale == scale)
return hx711_gain_to_scale[i].gain;
return -EINVAL;
}
static int hx711_cycle(struct hx711_data *hx711_data)
{
int val;
preempt_disable();
gpiod_set_value(hx711_data->gpiod_pd_sck, 1);
val = gpiod_get_value(hx711_data->gpiod_dout);
gpiod_set_value(hx711_data->gpiod_pd_sck, 0);
preempt_enable();
return val;
}
static int hx711_read(struct hx711_data *hx711_data)
{
int i, ret;
int value = 0;
int val = gpiod_get_value(hx711_data->gpiod_dout);
if (val)
return -EIO;
for (i = 0; i < 24; i++) {
value <<= 1;
ret = hx711_cycle(hx711_data);
if (ret)
value++;
}
value ^= 0x800000;
for (i = 0; i < hx711_get_gain_to_pulse(hx711_data->gain_set); i++)
hx711_cycle(hx711_data);
return value;
}
static int hx711_wait_for_ready(struct hx711_data *hx711_data)
{
int i, val;
for (i = 0; i < 100; i++) {
val = gpiod_get_value(hx711_data->gpiod_dout);
if (!val)
break;
msleep(1);
}
if (val)
return -EIO;
return 0;
}
static int hx711_reset(struct hx711_data *hx711_data)
{
int ret;
int val = gpiod_get_value(hx711_data->gpiod_dout);
if (val) {
gpiod_set_value(hx711_data->gpiod_pd_sck, 1);
msleep(10);
gpiod_set_value(hx711_data->gpiod_pd_sck, 0);
ret = hx711_wait_for_ready(hx711_data);
if (ret)
return ret;
ret = hx711_read(hx711_data);
if (ret < 0)
return ret;
ret = hx711_wait_for_ready(hx711_data);
if (ret)
return ret;
}
return val;
}
static int hx711_set_gain_for_channel(struct hx711_data *hx711_data, int chan)
{
int ret;
if (chan == 0) {
if (hx711_data->gain_set == 32) {
hx711_data->gain_set = hx711_data->gain_chan_a;
ret = hx711_read(hx711_data);
if (ret < 0)
return ret;
ret = hx711_wait_for_ready(hx711_data);
if (ret)
return ret;
}
} else {
if (hx711_data->gain_set != 32) {
hx711_data->gain_set = 32;
ret = hx711_read(hx711_data);
if (ret < 0)
return ret;
ret = hx711_wait_for_ready(hx711_data);
if (ret)
return ret;
}
}
return 0;
}
static int hx711_read_raw(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan,
int *val, int *val2, long mask)
{
struct hx711_data *hx711_data = iio_priv(indio_dev);
int ret;
switch (mask) {
case IIO_CHAN_INFO_RAW:
mutex_lock(&hx711_data->lock);
if (hx711_reset(hx711_data)) {
mutex_unlock(&hx711_data->lock);
dev_err(hx711_data->dev, "reset failed!");
return -EIO;
}
ret = hx711_set_gain_for_channel(hx711_data, chan->channel);
if (ret < 0) {
mutex_unlock(&hx711_data->lock);
return ret;
}
*val = hx711_read(hx711_data);
mutex_unlock(&hx711_data->lock);
if (*val < 0)
return *val;
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
*val = 0;
mutex_lock(&hx711_data->lock);
*val2 = hx711_get_gain_to_scale(hx711_data->gain_set);
mutex_unlock(&hx711_data->lock);
return IIO_VAL_INT_PLUS_NANO;
default:
return -EINVAL;
}
}
static int hx711_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int val,
int val2,
long mask)
{
struct hx711_data *hx711_data = iio_priv(indio_dev);
int ret;
int gain;
switch (mask) {
case IIO_CHAN_INFO_SCALE:
if (val != 0)
return -EINVAL;
mutex_lock(&hx711_data->lock);
gain = hx711_get_scale_to_gain(val2);
if (gain < 0) {
mutex_unlock(&hx711_data->lock);
return gain;
}
if (gain != hx711_data->gain_set) {
hx711_data->gain_set = gain;
if (gain != 32)
hx711_data->gain_chan_a = gain;
ret = hx711_read(hx711_data);
if (ret < 0) {
mutex_unlock(&hx711_data->lock);
return ret;
}
}
mutex_unlock(&hx711_data->lock);
return 0;
default:
return -EINVAL;
}
return 0;
}
static int hx711_write_raw_get_fmt(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
long mask)
{
return IIO_VAL_INT_PLUS_NANO;
}
static ssize_t hx711_scale_available_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev_attr *iio_attr = to_iio_dev_attr(attr);
int channel = iio_attr->address;
int i, len = 0;
for (i = 0; i < HX711_GAIN_MAX; i++)
if (hx711_gain_to_scale[i].channel == channel)
len += sprintf(buf + len, "0.%09d ",
hx711_gain_to_scale[i].scale);
len += sprintf(buf + len, "\n");
return len;
}
static int hx711_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct hx711_data *hx711_data;
struct iio_dev *indio_dev;
int ret;
int i;
indio_dev = devm_iio_device_alloc(dev, sizeof(struct hx711_data));
if (!indio_dev) {
dev_err(dev, "failed to allocate IIO device\n");
return -ENOMEM;
}
hx711_data = iio_priv(indio_dev);
hx711_data->dev = dev;
mutex_init(&hx711_data->lock);
hx711_data->gpiod_pd_sck = devm_gpiod_get(dev, "sck", GPIOD_OUT_LOW);
if (IS_ERR(hx711_data->gpiod_pd_sck)) {
dev_err(dev, "failed to get sck-gpiod: err=%ld\n",
PTR_ERR(hx711_data->gpiod_pd_sck));
return PTR_ERR(hx711_data->gpiod_pd_sck);
}
hx711_data->gpiod_dout = devm_gpiod_get(dev, "dout", GPIOD_IN);
if (IS_ERR(hx711_data->gpiod_dout)) {
dev_err(dev, "failed to get dout-gpiod: err=%ld\n",
PTR_ERR(hx711_data->gpiod_dout));
return PTR_ERR(hx711_data->gpiod_dout);
}
hx711_data->reg_avdd = devm_regulator_get(dev, "avdd");
if (IS_ERR(hx711_data->reg_avdd))
return PTR_ERR(hx711_data->reg_avdd);
ret = regulator_enable(hx711_data->reg_avdd);
if (ret < 0)
return ret;
ret = regulator_get_voltage(hx711_data->reg_avdd);
if (ret < 0) {
regulator_disable(hx711_data->reg_avdd);
return ret;
}
ret *= 100;
for (i = 0; i < HX711_GAIN_MAX; i++)
hx711_gain_to_scale[i].scale =
ret / hx711_gain_to_scale[i].gain / 1678;
hx711_data->gain_set = 128;
hx711_data->gain_chan_a = 128;
platform_set_drvdata(pdev, indio_dev);
indio_dev->name = "hx711";
indio_dev->dev.parent = &pdev->dev;
indio_dev->info = &hx711_iio_info;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->channels = hx711_chan_spec;
indio_dev->num_channels = ARRAY_SIZE(hx711_chan_spec);
ret = iio_device_register(indio_dev);
if (ret < 0) {
dev_err(dev, "Couldn't register the device\n");
regulator_disable(hx711_data->reg_avdd);
}
return ret;
}
static int hx711_remove(struct platform_device *pdev)
{
struct hx711_data *hx711_data;
struct iio_dev *indio_dev;
indio_dev = platform_get_drvdata(pdev);
hx711_data = iio_priv(indio_dev);
iio_device_unregister(indio_dev);
regulator_disable(hx711_data->reg_avdd);
return 0;
}
