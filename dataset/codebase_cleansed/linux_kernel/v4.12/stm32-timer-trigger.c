static int stm32_timer_start(struct stm32_timer_trigger *priv,
unsigned int frequency)
{
unsigned long long prd, div;
int prescaler = 0;
u32 ccer, cr1;
div = (unsigned long long)clk_get_rate(priv->clk);
do_div(div, frequency);
prd = div;
while (div > priv->max_arr) {
prescaler++;
div = prd;
do_div(div, (prescaler + 1));
}
prd = div;
if (prescaler > MAX_TIM_PSC) {
dev_err(priv->dev, "prescaler exceeds the maximum value\n");
return -EINVAL;
}
regmap_read(priv->regmap, TIM_CCER, &ccer);
if (ccer & TIM_CCER_CCXE)
return -EBUSY;
regmap_read(priv->regmap, TIM_CR1, &cr1);
if (!(cr1 & TIM_CR1_CEN))
clk_enable(priv->clk);
regmap_write(priv->regmap, TIM_PSC, prescaler);
regmap_write(priv->regmap, TIM_ARR, prd - 1);
regmap_update_bits(priv->regmap, TIM_CR1, TIM_CR1_ARPE, TIM_CR1_ARPE);
regmap_update_bits(priv->regmap, TIM_CR2, TIM_CR2_MMS, 0x20);
regmap_update_bits(priv->regmap, TIM_EGR, TIM_EGR_UG, TIM_EGR_UG);
regmap_update_bits(priv->regmap, TIM_CR1, TIM_CR1_CEN, TIM_CR1_CEN);
return 0;
}
static void stm32_timer_stop(struct stm32_timer_trigger *priv)
{
u32 ccer, cr1;
regmap_read(priv->regmap, TIM_CCER, &ccer);
if (ccer & TIM_CCER_CCXE)
return;
regmap_read(priv->regmap, TIM_CR1, &cr1);
if (cr1 & TIM_CR1_CEN)
clk_disable(priv->clk);
regmap_update_bits(priv->regmap, TIM_CR1, TIM_CR1_CEN, 0);
regmap_write(priv->regmap, TIM_PSC, 0);
regmap_write(priv->regmap, TIM_ARR, 0);
regmap_update_bits(priv->regmap, TIM_EGR, TIM_EGR_UG, TIM_EGR_UG);
}
static ssize_t stm32_tt_store_frequency(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t len)
{
struct iio_trigger *trig = to_iio_trigger(dev);
struct stm32_timer_trigger *priv = iio_trigger_get_drvdata(trig);
unsigned int freq;
int ret;
ret = kstrtouint(buf, 10, &freq);
if (ret)
return ret;
if (freq == 0) {
stm32_timer_stop(priv);
} else {
ret = stm32_timer_start(priv, freq);
if (ret)
return ret;
}
return len;
}
static ssize_t stm32_tt_read_frequency(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct iio_trigger *trig = to_iio_trigger(dev);
struct stm32_timer_trigger *priv = iio_trigger_get_drvdata(trig);
u32 psc, arr, cr1;
unsigned long long freq = 0;
regmap_read(priv->regmap, TIM_CR1, &cr1);
regmap_read(priv->regmap, TIM_PSC, &psc);
regmap_read(priv->regmap, TIM_ARR, &arr);
if (cr1 & TIM_CR1_CEN) {
freq = (unsigned long long)clk_get_rate(priv->clk);
do_div(freq, psc + 1);
do_div(freq, arr + 1);
}
return sprintf(buf, "%d\n", (unsigned int)freq);
}
static ssize_t stm32_tt_show_master_mode(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct stm32_timer_trigger *priv = dev_get_drvdata(dev);
u32 cr2;
regmap_read(priv->regmap, TIM_CR2, &cr2);
cr2 = (cr2 & TIM_CR2_MMS) >> TIM_CR2_MMS_SHIFT;
return snprintf(buf, PAGE_SIZE, "%s\n", master_mode_table[cr2]);
}
static ssize_t stm32_tt_store_master_mode(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t len)
{
struct stm32_timer_trigger *priv = dev_get_drvdata(dev);
int i;
for (i = 0; i < ARRAY_SIZE(master_mode_table); i++) {
if (!strncmp(master_mode_table[i], buf,
strlen(master_mode_table[i]))) {
regmap_update_bits(priv->regmap, TIM_CR2,
TIM_CR2_MMS, i << TIM_CR2_MMS_SHIFT);
regmap_update_bits(priv->regmap, TIM_EGR,
TIM_EGR_UG, TIM_EGR_UG);
return len;
}
}
return -EINVAL;
}
static int stm32_setup_iio_triggers(struct stm32_timer_trigger *priv)
{
int ret;
const char * const *cur = priv->triggers;
while (cur && *cur) {
struct iio_trigger *trig;
trig = devm_iio_trigger_alloc(priv->dev, "%s", *cur);
if (!trig)
return -ENOMEM;
trig->dev.parent = priv->dev->parent;
trig->ops = &timer_trigger_ops;
if (cur == priv->triggers)
trig->dev.groups = stm32_trigger_attr_groups;
iio_trigger_set_drvdata(trig, priv);
ret = devm_iio_trigger_register(priv->dev, trig);
if (ret)
return ret;
cur++;
}
return 0;
}
static int stm32_counter_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2, long mask)
{
struct stm32_timer_trigger *priv = iio_priv(indio_dev);
switch (mask) {
case IIO_CHAN_INFO_RAW:
{
u32 cnt;
regmap_read(priv->regmap, TIM_CNT, &cnt);
*val = cnt;
return IIO_VAL_INT;
}
case IIO_CHAN_INFO_SCALE:
{
u32 smcr;
regmap_read(priv->regmap, TIM_SMCR, &smcr);
smcr &= TIM_SMCR_SMS;
*val = 1;
*val2 = 0;
if (smcr == 3)
*val2 = 2;
return IIO_VAL_FRACTIONAL_LOG2;
}
}
return -EINVAL;
}
static int stm32_counter_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int val, int val2, long mask)
{
struct stm32_timer_trigger *priv = iio_priv(indio_dev);
switch (mask) {
case IIO_CHAN_INFO_RAW:
regmap_write(priv->regmap, TIM_CNT, val);
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
return -EINVAL;
}
return -EINVAL;
}
static int stm32_enable_mode2sms(int mode)
{
switch (mode) {
case 0:
return 0;
case 1:
return 5;
case 2:
return 6;
}
return -EINVAL;
}
static int stm32_set_enable_mode(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan,
unsigned int mode)
{
struct stm32_timer_trigger *priv = iio_priv(indio_dev);
int sms = stm32_enable_mode2sms(mode);
if (sms < 0)
return sms;
regmap_update_bits(priv->regmap, TIM_SMCR, TIM_SMCR_SMS, sms);
return 0;
}
static int stm32_sms2enable_mode(int mode)
{
switch (mode) {
case 0:
return 0;
case 5:
return 1;
case 6:
return 2;
}
return -EINVAL;
}
static int stm32_get_enable_mode(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan)
{
struct stm32_timer_trigger *priv = iio_priv(indio_dev);
u32 smcr;
regmap_read(priv->regmap, TIM_SMCR, &smcr);
smcr &= TIM_SMCR_SMS;
return stm32_sms2enable_mode(smcr);
}
static int stm32_set_quadrature_mode(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan,
unsigned int mode)
{
struct stm32_timer_trigger *priv = iio_priv(indio_dev);
regmap_update_bits(priv->regmap, TIM_SMCR, TIM_SMCR_SMS, mode + 1);
return 0;
}
static int stm32_get_quadrature_mode(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan)
{
struct stm32_timer_trigger *priv = iio_priv(indio_dev);
u32 smcr;
regmap_read(priv->regmap, TIM_SMCR, &smcr);
smcr &= TIM_SMCR_SMS;
return smcr - 1;
}
static int stm32_set_count_direction(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan,
unsigned int mode)
{
struct stm32_timer_trigger *priv = iio_priv(indio_dev);
regmap_update_bits(priv->regmap, TIM_CR1, TIM_CR1_DIR, mode);
return 0;
}
static int stm32_get_count_direction(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan)
{
struct stm32_timer_trigger *priv = iio_priv(indio_dev);
u32 cr1;
regmap_read(priv->regmap, TIM_CR1, &cr1);
return (cr1 & TIM_CR1_DIR);
}
static ssize_t stm32_count_get_preset(struct iio_dev *indio_dev,
uintptr_t private,
const struct iio_chan_spec *chan,
char *buf)
{
struct stm32_timer_trigger *priv = iio_priv(indio_dev);
u32 arr;
regmap_read(priv->regmap, TIM_ARR, &arr);
return snprintf(buf, PAGE_SIZE, "%u\n", arr);
}
static ssize_t stm32_count_set_preset(struct iio_dev *indio_dev,
uintptr_t private,
const struct iio_chan_spec *chan,
const char *buf, size_t len)
{
struct stm32_timer_trigger *priv = iio_priv(indio_dev);
unsigned int preset;
int ret;
ret = kstrtouint(buf, 0, &preset);
if (ret)
return ret;
regmap_write(priv->regmap, TIM_ARR, preset);
regmap_update_bits(priv->regmap, TIM_CR1, TIM_CR1_ARPE, TIM_CR1_ARPE);
return len;
}
static struct stm32_timer_trigger *stm32_setup_counter_device(struct device *dev)
{
struct iio_dev *indio_dev;
int ret;
indio_dev = devm_iio_device_alloc(dev,
sizeof(struct stm32_timer_trigger));
if (!indio_dev)
return NULL;
indio_dev->name = dev_name(dev);
indio_dev->dev.parent = dev;
indio_dev->info = &stm32_trigger_info;
indio_dev->num_channels = 1;
indio_dev->channels = &stm32_trigger_channel;
indio_dev->dev.of_node = dev->of_node;
ret = devm_iio_device_register(dev, indio_dev);
if (ret)
return NULL;
return iio_priv(indio_dev);
}
bool is_stm32_timer_trigger(struct iio_trigger *trig)
{
return (trig->ops == &timer_trigger_ops);
}
static int stm32_timer_trigger_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct stm32_timer_trigger *priv;
struct stm32_timers *ddata = dev_get_drvdata(pdev->dev.parent);
unsigned int index;
int ret;
if (of_property_read_u32(dev->of_node, "reg", &index))
return -EINVAL;
if (index >= ARRAY_SIZE(triggers_table) ||
index >= ARRAY_SIZE(valids_table))
return -EINVAL;
if (*valids_table[index])
priv = stm32_setup_counter_device(dev);
else
priv = devm_kzalloc(dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
priv->dev = dev;
priv->regmap = ddata->regmap;
priv->clk = ddata->clk;
priv->max_arr = ddata->max_arr;
priv->triggers = triggers_table[index];
priv->valids = valids_table[index];
ret = stm32_setup_iio_triggers(priv);
if (ret)
return ret;
platform_set_drvdata(pdev, priv);
return 0;
}
