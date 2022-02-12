static int lm3533_als_get_adc(struct iio_dev *indio_dev, bool average,
int *adc)
{
struct lm3533_als *als = iio_priv(indio_dev);
u8 reg;
u8 val;
int ret;
if (average)
reg = LM3533_REG_ALS_READ_ADC_AVERAGE;
else
reg = LM3533_REG_ALS_READ_ADC_RAW;
ret = lm3533_read(als->lm3533, reg, &val);
if (ret) {
dev_err(&indio_dev->dev, "failed to read adc\n");
return ret;
}
*adc = val;
return 0;
}
static int _lm3533_als_get_zone(struct iio_dev *indio_dev, u8 *zone)
{
struct lm3533_als *als = iio_priv(indio_dev);
u8 val;
int ret;
ret = lm3533_read(als->lm3533, LM3533_REG_ALS_ZONE_INFO, &val);
if (ret) {
dev_err(&indio_dev->dev, "failed to read zone\n");
return ret;
}
val = (val & LM3533_ALS_ZONE_MASK) >> LM3533_ALS_ZONE_SHIFT;
*zone = min_t(u8, val, LM3533_ALS_ZONE_MAX);
return 0;
}
static int lm3533_als_get_zone(struct iio_dev *indio_dev, u8 *zone)
{
struct lm3533_als *als = iio_priv(indio_dev);
int ret;
if (test_bit(LM3533_ALS_FLAG_INT_ENABLED, &als->flags)) {
*zone = atomic_read(&als->zone);
} else {
ret = _lm3533_als_get_zone(indio_dev, zone);
if (ret)
return ret;
}
return 0;
}
static inline u8 lm3533_als_get_target_reg(unsigned channel, unsigned zone)
{
return LM3533_REG_ALS_TARGET_BASE + 5 * channel + zone;
}
static int lm3533_als_get_target(struct iio_dev *indio_dev, unsigned channel,
unsigned zone, u8 *val)
{
struct lm3533_als *als = iio_priv(indio_dev);
u8 reg;
int ret;
if (channel > LM3533_ALS_CHANNEL_CURRENT_MAX)
return -EINVAL;
if (zone > LM3533_ALS_ZONE_MAX)
return -EINVAL;
reg = lm3533_als_get_target_reg(channel, zone);
ret = lm3533_read(als->lm3533, reg, val);
if (ret)
dev_err(&indio_dev->dev, "failed to get target current\n");
return ret;
}
static int lm3533_als_set_target(struct iio_dev *indio_dev, unsigned channel,
unsigned zone, u8 val)
{
struct lm3533_als *als = iio_priv(indio_dev);
u8 reg;
int ret;
if (channel > LM3533_ALS_CHANNEL_CURRENT_MAX)
return -EINVAL;
if (zone > LM3533_ALS_ZONE_MAX)
return -EINVAL;
reg = lm3533_als_get_target_reg(channel, zone);
ret = lm3533_write(als->lm3533, reg, val);
if (ret)
dev_err(&indio_dev->dev, "failed to set target current\n");
return ret;
}
static int lm3533_als_get_current(struct iio_dev *indio_dev, unsigned channel,
int *val)
{
u8 zone;
u8 target;
int ret;
ret = lm3533_als_get_zone(indio_dev, &zone);
if (ret)
return ret;
ret = lm3533_als_get_target(indio_dev, channel, zone, &target);
if (ret)
return ret;
*val = target;
return 0;
}
static int lm3533_als_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2, long mask)
{
int ret;
switch (mask) {
case 0:
switch (chan->type) {
case IIO_LIGHT:
ret = lm3533_als_get_adc(indio_dev, false, val);
break;
case IIO_CURRENT:
ret = lm3533_als_get_current(indio_dev, chan->channel,
val);
break;
default:
return -EINVAL;
}
break;
case IIO_CHAN_INFO_AVERAGE_RAW:
ret = lm3533_als_get_adc(indio_dev, true, val);
break;
default:
return -EINVAL;
}
if (ret)
return ret;
return IIO_VAL_INT;
}
static irqreturn_t lm3533_als_isr(int irq, void *dev_id)
{
struct iio_dev *indio_dev = dev_id;
struct lm3533_als *als = iio_priv(indio_dev);
u8 zone;
int ret;
ret = _lm3533_als_get_zone(indio_dev, &zone);
if (ret)
goto out;
atomic_set(&als->zone, zone);
iio_push_event(indio_dev,
IIO_UNMOD_EVENT_CODE(IIO_LIGHT,
0,
IIO_EV_TYPE_THRESH,
IIO_EV_DIR_EITHER),
iio_get_time_ns());
out:
return IRQ_HANDLED;
}
static int lm3533_als_set_int_mode(struct iio_dev *indio_dev, int enable)
{
struct lm3533_als *als = iio_priv(indio_dev);
u8 mask = LM3533_ALS_INT_ENABLE_MASK;
u8 val;
int ret;
if (enable)
val = mask;
else
val = 0;
ret = lm3533_update(als->lm3533, LM3533_REG_ALS_ZONE_INFO, val, mask);
if (ret) {
dev_err(&indio_dev->dev, "failed to set int mode %d\n",
enable);
return ret;
}
return 0;
}
static int lm3533_als_get_int_mode(struct iio_dev *indio_dev, int *enable)
{
struct lm3533_als *als = iio_priv(indio_dev);
u8 mask = LM3533_ALS_INT_ENABLE_MASK;
u8 val;
int ret;
ret = lm3533_read(als->lm3533, LM3533_REG_ALS_ZONE_INFO, &val);
if (ret) {
dev_err(&indio_dev->dev, "failed to get int mode\n");
return ret;
}
*enable = !!(val & mask);
return 0;
}
static inline u8 lm3533_als_get_threshold_reg(unsigned nr, bool raising)
{
u8 offset = !raising;
return LM3533_REG_ALS_BOUNDARY_BASE + 2 * nr + offset;
}
static int lm3533_als_get_threshold(struct iio_dev *indio_dev, unsigned nr,
bool raising, u8 *val)
{
struct lm3533_als *als = iio_priv(indio_dev);
u8 reg;
int ret;
if (nr > LM3533_ALS_THRESH_MAX)
return -EINVAL;
reg = lm3533_als_get_threshold_reg(nr, raising);
ret = lm3533_read(als->lm3533, reg, val);
if (ret)
dev_err(&indio_dev->dev, "failed to get threshold\n");
return ret;
}
static int lm3533_als_set_threshold(struct iio_dev *indio_dev, unsigned nr,
bool raising, u8 val)
{
struct lm3533_als *als = iio_priv(indio_dev);
u8 val2;
u8 reg, reg2;
int ret;
if (nr > LM3533_ALS_THRESH_MAX)
return -EINVAL;
reg = lm3533_als_get_threshold_reg(nr, raising);
reg2 = lm3533_als_get_threshold_reg(nr, !raising);
mutex_lock(&als->thresh_mutex);
ret = lm3533_read(als->lm3533, reg2, &val2);
if (ret) {
dev_err(&indio_dev->dev, "failed to get threshold\n");
goto out;
}
if ((raising && (val < val2)) || (!raising && (val > val2))) {
ret = -EINVAL;
goto out;
}
ret = lm3533_write(als->lm3533, reg, val);
if (ret) {
dev_err(&indio_dev->dev, "failed to set threshold\n");
goto out;
}
out:
mutex_unlock(&als->thresh_mutex);
return ret;
}
static int lm3533_als_get_hysteresis(struct iio_dev *indio_dev, unsigned nr,
u8 *val)
{
struct lm3533_als *als = iio_priv(indio_dev);
u8 falling;
u8 raising;
int ret;
if (nr > LM3533_ALS_THRESH_MAX)
return -EINVAL;
mutex_lock(&als->thresh_mutex);
ret = lm3533_als_get_threshold(indio_dev, nr, false, &falling);
if (ret)
goto out;
ret = lm3533_als_get_threshold(indio_dev, nr, true, &raising);
if (ret)
goto out;
*val = raising - falling;
out:
mutex_unlock(&als->thresh_mutex);
return ret;
}
static ssize_t show_thresh_either_en(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct lm3533_als *als = iio_priv(indio_dev);
int enable;
int ret;
if (als->irq) {
ret = lm3533_als_get_int_mode(indio_dev, &enable);
if (ret)
return ret;
} else {
enable = 0;
}
return scnprintf(buf, PAGE_SIZE, "%u\n", enable);
}
static ssize_t store_thresh_either_en(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t len)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct lm3533_als *als = iio_priv(indio_dev);
unsigned long enable;
bool int_enabled;
u8 zone;
int ret;
if (!als->irq)
return -EBUSY;
if (kstrtoul(buf, 0, &enable))
return -EINVAL;
int_enabled = test_bit(LM3533_ALS_FLAG_INT_ENABLED, &als->flags);
if (enable && !int_enabled) {
ret = lm3533_als_get_zone(indio_dev, &zone);
if (ret)
return ret;
atomic_set(&als->zone, zone);
set_bit(LM3533_ALS_FLAG_INT_ENABLED, &als->flags);
}
ret = lm3533_als_set_int_mode(indio_dev, enable);
if (ret) {
if (!int_enabled)
clear_bit(LM3533_ALS_FLAG_INT_ENABLED, &als->flags);
return ret;
}
if (!enable)
clear_bit(LM3533_ALS_FLAG_INT_ENABLED, &als->flags);
return len;
}
static ssize_t show_zone(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
u8 zone;
int ret;
ret = lm3533_als_get_zone(indio_dev, &zone);
if (ret)
return ret;
return scnprintf(buf, PAGE_SIZE, "%u\n", zone);
}
static inline struct lm3533_als_attribute *
to_lm3533_als_attr(struct device_attribute *attr)
{
return container_of(attr, struct lm3533_als_attribute, dev_attr);
}
static ssize_t show_als_attr(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct lm3533_als_attribute *als_attr = to_lm3533_als_attr(attr);
u8 val;
int ret;
switch (als_attr->type) {
case LM3533_ATTR_TYPE_HYSTERESIS:
ret = lm3533_als_get_hysteresis(indio_dev, als_attr->val1,
&val);
break;
case LM3533_ATTR_TYPE_TARGET:
ret = lm3533_als_get_target(indio_dev, als_attr->val1,
als_attr->val2, &val);
break;
case LM3533_ATTR_TYPE_THRESH_FALLING:
ret = lm3533_als_get_threshold(indio_dev, als_attr->val1,
false, &val);
break;
case LM3533_ATTR_TYPE_THRESH_RAISING:
ret = lm3533_als_get_threshold(indio_dev, als_attr->val1,
true, &val);
break;
default:
ret = -ENXIO;
}
if (ret)
return ret;
return scnprintf(buf, PAGE_SIZE, "%u\n", val);
}
static ssize_t store_als_attr(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t len)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct lm3533_als_attribute *als_attr = to_lm3533_als_attr(attr);
u8 val;
int ret;
if (kstrtou8(buf, 0, &val))
return -EINVAL;
switch (als_attr->type) {
case LM3533_ATTR_TYPE_TARGET:
ret = lm3533_als_set_target(indio_dev, als_attr->val1,
als_attr->val2, val);
break;
case LM3533_ATTR_TYPE_THRESH_FALLING:
ret = lm3533_als_set_threshold(indio_dev, als_attr->val1,
false, val);
break;
case LM3533_ATTR_TYPE_THRESH_RAISING:
ret = lm3533_als_set_threshold(indio_dev, als_attr->val1,
true, val);
break;
default:
ret = -ENXIO;
}
if (ret)
return ret;
return len;
}
static int lm3533_als_set_input_mode(struct lm3533_als *als, bool pwm_mode)
{
u8 mask = LM3533_ALS_INPUT_MODE_MASK;
u8 val;
int ret;
if (pwm_mode)
val = mask;
else
val = 0;
ret = lm3533_update(als->lm3533, LM3533_REG_ALS_CONF, val, mask);
if (ret) {
dev_err(&als->pdev->dev, "failed to set input mode %d\n",
pwm_mode);
return ret;
}
return 0;
}
static int lm3533_als_set_resistor(struct lm3533_als *als, u8 val)
{
int ret;
if (val < LM3533_ALS_RESISTOR_MIN || val > LM3533_ALS_RESISTOR_MAX)
return -EINVAL;
ret = lm3533_write(als->lm3533, LM3533_REG_ALS_RESISTOR_SELECT, val);
if (ret) {
dev_err(&als->pdev->dev, "failed to set resistor\n");
return ret;
}
return 0;
}
static int lm3533_als_setup(struct lm3533_als *als,
struct lm3533_als_platform_data *pdata)
{
int ret;
ret = lm3533_als_set_input_mode(als, pdata->pwm_mode);
if (ret)
return ret;
if (!pdata->pwm_mode) {
ret = lm3533_als_set_resistor(als, pdata->r_select);
if (ret)
return ret;
}
return 0;
}
static int lm3533_als_setup_irq(struct lm3533_als *als, void *dev)
{
u8 mask = LM3533_ALS_INT_ENABLE_MASK;
int ret;
ret = lm3533_update(als->lm3533, LM3533_REG_ALS_ZONE_INFO, 0, mask);
if (ret) {
dev_err(&als->pdev->dev, "failed to disable interrupts\n");
return ret;
}
ret = request_threaded_irq(als->irq, NULL, lm3533_als_isr,
IRQF_TRIGGER_LOW | IRQF_ONESHOT,
dev_name(&als->pdev->dev), dev);
if (ret) {
dev_err(&als->pdev->dev, "failed to request irq %d\n",
als->irq);
return ret;
}
return 0;
}
static int lm3533_als_enable(struct lm3533_als *als)
{
u8 mask = LM3533_ALS_ENABLE_MASK;
int ret;
ret = lm3533_update(als->lm3533, LM3533_REG_ALS_CONF, mask, mask);
if (ret)
dev_err(&als->pdev->dev, "failed to enable ALS\n");
return ret;
}
static int lm3533_als_disable(struct lm3533_als *als)
{
u8 mask = LM3533_ALS_ENABLE_MASK;
int ret;
ret = lm3533_update(als->lm3533, LM3533_REG_ALS_CONF, 0, mask);
if (ret)
dev_err(&als->pdev->dev, "failed to disable ALS\n");
return ret;
}
static int lm3533_als_probe(struct platform_device *pdev)
{
struct lm3533 *lm3533;
struct lm3533_als_platform_data *pdata;
struct lm3533_als *als;
struct iio_dev *indio_dev;
int ret;
lm3533 = dev_get_drvdata(pdev->dev.parent);
if (!lm3533)
return -EINVAL;
pdata = pdev->dev.platform_data;
if (!pdata) {
dev_err(&pdev->dev, "no platform data\n");
return -EINVAL;
}
indio_dev = iio_device_alloc(sizeof(*als));
if (!indio_dev)
return -ENOMEM;
indio_dev->info = &lm3533_als_info;
indio_dev->channels = lm3533_als_channels;
indio_dev->num_channels = ARRAY_SIZE(lm3533_als_channels);
indio_dev->name = dev_name(&pdev->dev);
indio_dev->dev.parent = pdev->dev.parent;
indio_dev->modes = INDIO_DIRECT_MODE;
als = iio_priv(indio_dev);
als->lm3533 = lm3533;
als->pdev = pdev;
als->irq = lm3533->irq;
atomic_set(&als->zone, 0);
mutex_init(&als->thresh_mutex);
platform_set_drvdata(pdev, indio_dev);
if (als->irq) {
ret = lm3533_als_setup_irq(als, indio_dev);
if (ret)
goto err_free_dev;
}
ret = lm3533_als_setup(als, pdata);
if (ret)
goto err_free_irq;
ret = lm3533_als_enable(als);
if (ret)
goto err_free_irq;
ret = iio_device_register(indio_dev);
if (ret) {
dev_err(&pdev->dev, "failed to register ALS\n");
goto err_disable;
}
return 0;
err_disable:
lm3533_als_disable(als);
err_free_irq:
if (als->irq)
free_irq(als->irq, indio_dev);
err_free_dev:
iio_device_free(indio_dev);
return ret;
}
static int lm3533_als_remove(struct platform_device *pdev)
{
struct iio_dev *indio_dev = platform_get_drvdata(pdev);
struct lm3533_als *als = iio_priv(indio_dev);
lm3533_als_set_int_mode(indio_dev, false);
iio_device_unregister(indio_dev);
lm3533_als_disable(als);
if (als->irq)
free_irq(als->irq, indio_dev);
iio_device_free(indio_dev);
return 0;
}
