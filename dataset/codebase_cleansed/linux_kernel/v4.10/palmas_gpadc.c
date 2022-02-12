static int palmas_disable_auto_conversion(struct palmas_gpadc *adc)
{
int ret;
ret = palmas_update_bits(adc->palmas, PALMAS_GPADC_BASE,
PALMAS_GPADC_CTRL1,
PALMAS_GPADC_CTRL1_GPADC_FORCE,
PALMAS_GPADC_CTRL1_GPADC_FORCE);
if (ret < 0) {
dev_err(adc->dev, "GPADC_CTRL1 update failed: %d\n", ret);
return ret;
}
ret = palmas_update_bits(adc->palmas, PALMAS_GPADC_BASE,
PALMAS_GPADC_AUTO_CTRL,
PALMAS_GPADC_AUTO_CTRL_SHUTDOWN_CONV1 |
PALMAS_GPADC_AUTO_CTRL_SHUTDOWN_CONV0,
0);
if (ret < 0) {
dev_err(adc->dev, "AUTO_CTRL update failed: %d\n", ret);
return ret;
}
udelay(100);
ret = palmas_update_bits(adc->palmas, PALMAS_GPADC_BASE,
PALMAS_GPADC_CTRL1,
PALMAS_GPADC_CTRL1_GPADC_FORCE, 0);
if (ret < 0)
dev_err(adc->dev, "GPADC_CTRL1 update failed: %d\n", ret);
return ret;
}
static irqreturn_t palmas_gpadc_irq(int irq, void *data)
{
struct palmas_gpadc *adc = data;
complete(&adc->conv_completion);
return IRQ_HANDLED;
}
static irqreturn_t palmas_gpadc_irq_auto(int irq, void *data)
{
struct palmas_gpadc *adc = data;
dev_dbg(adc->dev, "Threshold interrupt %d occurs\n", irq);
palmas_disable_auto_conversion(adc);
return IRQ_HANDLED;
}
static int palmas_gpadc_start_mask_interrupt(struct palmas_gpadc *adc,
bool mask)
{
int ret;
if (!mask)
ret = palmas_update_bits(adc->palmas, PALMAS_INTERRUPT_BASE,
PALMAS_INT3_MASK,
PALMAS_INT3_MASK_GPADC_EOC_SW, 0);
else
ret = palmas_update_bits(adc->palmas, PALMAS_INTERRUPT_BASE,
PALMAS_INT3_MASK,
PALMAS_INT3_MASK_GPADC_EOC_SW,
PALMAS_INT3_MASK_GPADC_EOC_SW);
if (ret < 0)
dev_err(adc->dev, "GPADC INT MASK update failed: %d\n", ret);
return ret;
}
static int palmas_gpadc_enable(struct palmas_gpadc *adc, int adc_chan,
int enable)
{
unsigned int mask, val;
int ret;
if (enable) {
val = (adc->extended_delay
<< PALMAS_GPADC_RT_CTRL_EXTEND_DELAY_SHIFT);
ret = palmas_update_bits(adc->palmas, PALMAS_GPADC_BASE,
PALMAS_GPADC_RT_CTRL,
PALMAS_GPADC_RT_CTRL_EXTEND_DELAY, val);
if (ret < 0) {
dev_err(adc->dev, "RT_CTRL update failed: %d\n", ret);
return ret;
}
mask = (PALMAS_GPADC_CTRL1_CURRENT_SRC_CH0_MASK |
PALMAS_GPADC_CTRL1_CURRENT_SRC_CH3_MASK |
PALMAS_GPADC_CTRL1_GPADC_FORCE);
val = (adc->ch0_current
<< PALMAS_GPADC_CTRL1_CURRENT_SRC_CH0_SHIFT);
val |= (adc->ch3_current
<< PALMAS_GPADC_CTRL1_CURRENT_SRC_CH3_SHIFT);
val |= PALMAS_GPADC_CTRL1_GPADC_FORCE;
ret = palmas_update_bits(adc->palmas, PALMAS_GPADC_BASE,
PALMAS_GPADC_CTRL1, mask, val);
if (ret < 0) {
dev_err(adc->dev,
"Failed to update current setting: %d\n", ret);
return ret;
}
mask = (PALMAS_GPADC_SW_SELECT_SW_CONV0_SEL_MASK |
PALMAS_GPADC_SW_SELECT_SW_CONV_EN);
val = (adc_chan | PALMAS_GPADC_SW_SELECT_SW_CONV_EN);
ret = palmas_update_bits(adc->palmas, PALMAS_GPADC_BASE,
PALMAS_GPADC_SW_SELECT, mask, val);
if (ret < 0) {
dev_err(adc->dev, "SW_SELECT update failed: %d\n", ret);
return ret;
}
} else {
ret = palmas_write(adc->palmas, PALMAS_GPADC_BASE,
PALMAS_GPADC_SW_SELECT, 0);
if (ret < 0)
dev_err(adc->dev, "SW_SELECT write failed: %d\n", ret);
ret = palmas_update_bits(adc->palmas, PALMAS_GPADC_BASE,
PALMAS_GPADC_CTRL1,
PALMAS_GPADC_CTRL1_GPADC_FORCE, 0);
if (ret < 0) {
dev_err(adc->dev, "CTRL1 update failed: %d\n", ret);
return ret;
}
}
return ret;
}
static int palmas_gpadc_read_prepare(struct palmas_gpadc *adc, int adc_chan)
{
int ret;
ret = palmas_gpadc_enable(adc, adc_chan, true);
if (ret < 0)
return ret;
return palmas_gpadc_start_mask_interrupt(adc, 0);
}
static void palmas_gpadc_read_done(struct palmas_gpadc *adc, int adc_chan)
{
palmas_gpadc_start_mask_interrupt(adc, 1);
palmas_gpadc_enable(adc, adc_chan, false);
}
static int palmas_gpadc_calibrate(struct palmas_gpadc *adc, int adc_chan)
{
int k;
int d1;
int d2;
int ret;
int gain;
int x1 = adc->adc_info[adc_chan].x1;
int x2 = adc->adc_info[adc_chan].x2;
int v1 = adc->adc_info[adc_chan].v1;
int v2 = adc->adc_info[adc_chan].v2;
ret = palmas_read(adc->palmas, PALMAS_TRIM_GPADC_BASE,
adc->adc_info[adc_chan].trim1_reg, &d1);
if (ret < 0) {
dev_err(adc->dev, "TRIM read failed: %d\n", ret);
goto scrub;
}
ret = palmas_read(adc->palmas, PALMAS_TRIM_GPADC_BASE,
adc->adc_info[adc_chan].trim2_reg, &d2);
if (ret < 0) {
dev_err(adc->dev, "TRIM read failed: %d\n", ret);
goto scrub;
}
k = (1000 + (1000 * (d2 - d1)) / (x2 - x1));
gain = ((v2 - v1) * 1000) / (x2 - x1);
adc->adc_info[adc_chan].gain_error = k;
adc->adc_info[adc_chan].gain = gain;
adc->adc_info[adc_chan].offset = (d1 * 1000) - ((k - 1000) * x1);
scrub:
return ret;
}
static int palmas_gpadc_start_conversion(struct palmas_gpadc *adc, int adc_chan)
{
unsigned int val;
int ret;
init_completion(&adc->conv_completion);
ret = palmas_update_bits(adc->palmas, PALMAS_GPADC_BASE,
PALMAS_GPADC_SW_SELECT,
PALMAS_GPADC_SW_SELECT_SW_START_CONV0,
PALMAS_GPADC_SW_SELECT_SW_START_CONV0);
if (ret < 0) {
dev_err(adc->dev, "SELECT_SW_START write failed: %d\n", ret);
return ret;
}
ret = wait_for_completion_timeout(&adc->conv_completion,
PALMAS_ADC_CONVERSION_TIMEOUT);
if (ret == 0) {
dev_err(adc->dev, "conversion not completed\n");
return -ETIMEDOUT;
}
ret = palmas_bulk_read(adc->palmas, PALMAS_GPADC_BASE,
PALMAS_GPADC_SW_CONV0_LSB, &val, 2);
if (ret < 0) {
dev_err(adc->dev, "SW_CONV0_LSB read failed: %d\n", ret);
return ret;
}
ret = val & 0xFFF;
return ret;
}
static int palmas_gpadc_get_calibrated_code(struct palmas_gpadc *adc,
int adc_chan, int val)
{
if (!adc->adc_info[adc_chan].is_uncalibrated)
val = (val*1000 - adc->adc_info[adc_chan].offset) /
adc->adc_info[adc_chan].gain_error;
if (val < 0) {
dev_err(adc->dev, "Mismatch with calibration\n");
return 0;
}
val = (val * adc->adc_info[adc_chan].gain) / 1000;
return val;
}
static int palmas_gpadc_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan, int *val, int *val2, long mask)
{
struct palmas_gpadc *adc = iio_priv(indio_dev);
int adc_chan = chan->channel;
int ret = 0;
if (adc_chan > PALMAS_ADC_CH_MAX)
return -EINVAL;
mutex_lock(&indio_dev->mlock);
switch (mask) {
case IIO_CHAN_INFO_RAW:
case IIO_CHAN_INFO_PROCESSED:
ret = palmas_gpadc_read_prepare(adc, adc_chan);
if (ret < 0)
goto out;
ret = palmas_gpadc_start_conversion(adc, adc_chan);
if (ret < 0) {
dev_err(adc->dev,
"ADC start conversion failed\n");
goto out;
}
if (mask == IIO_CHAN_INFO_PROCESSED)
ret = palmas_gpadc_get_calibrated_code(
adc, adc_chan, ret);
*val = ret;
ret = IIO_VAL_INT;
goto out;
}
mutex_unlock(&indio_dev->mlock);
return ret;
out:
palmas_gpadc_read_done(adc, adc_chan);
mutex_unlock(&indio_dev->mlock);
return ret;
}
static int palmas_gpadc_get_adc_dt_data(struct platform_device *pdev,
struct palmas_gpadc_platform_data **gpadc_pdata)
{
struct device_node *np = pdev->dev.of_node;
struct palmas_gpadc_platform_data *gp_data;
int ret;
u32 pval;
gp_data = devm_kzalloc(&pdev->dev, sizeof(*gp_data), GFP_KERNEL);
if (!gp_data)
return -ENOMEM;
ret = of_property_read_u32(np, "ti,channel0-current-microamp", &pval);
if (!ret)
gp_data->ch0_current = pval;
ret = of_property_read_u32(np, "ti,channel3-current-microamp", &pval);
if (!ret)
gp_data->ch3_current = pval;
gp_data->extended_delay = of_property_read_bool(np,
"ti,enable-extended-delay");
*gpadc_pdata = gp_data;
return 0;
}
static int palmas_gpadc_probe(struct platform_device *pdev)
{
struct palmas_gpadc *adc;
struct palmas_platform_data *pdata;
struct palmas_gpadc_platform_data *gpadc_pdata = NULL;
struct iio_dev *indio_dev;
int ret, i;
pdata = dev_get_platdata(pdev->dev.parent);
if (pdata && pdata->gpadc_pdata)
gpadc_pdata = pdata->gpadc_pdata;
if (!gpadc_pdata && pdev->dev.of_node) {
ret = palmas_gpadc_get_adc_dt_data(pdev, &gpadc_pdata);
if (ret < 0)
return ret;
}
if (!gpadc_pdata)
return -EINVAL;
indio_dev = devm_iio_device_alloc(&pdev->dev, sizeof(*adc));
if (!indio_dev) {
dev_err(&pdev->dev, "iio_device_alloc failed\n");
return -ENOMEM;
}
adc = iio_priv(indio_dev);
adc->dev = &pdev->dev;
adc->palmas = dev_get_drvdata(pdev->dev.parent);
adc->adc_info = palmas_gpadc_info;
init_completion(&adc->conv_completion);
dev_set_drvdata(&pdev->dev, indio_dev);
adc->auto_conversion_period = gpadc_pdata->auto_conversion_period_ms;
adc->irq = palmas_irq_get_virq(adc->palmas, PALMAS_GPADC_EOC_SW_IRQ);
if (adc->irq < 0) {
dev_err(adc->dev,
"get virq failed: %d\n", adc->irq);
ret = adc->irq;
goto out;
}
ret = request_threaded_irq(adc->irq, NULL,
palmas_gpadc_irq,
IRQF_ONESHOT, dev_name(adc->dev),
adc);
if (ret < 0) {
dev_err(adc->dev,
"request irq %d failed: %d\n", adc->irq, ret);
goto out;
}
if (gpadc_pdata->adc_wakeup1_data) {
memcpy(&adc->wakeup1_data, gpadc_pdata->adc_wakeup1_data,
sizeof(adc->wakeup1_data));
adc->wakeup1_enable = true;
adc->irq_auto_0 = platform_get_irq(pdev, 1);
ret = request_threaded_irq(adc->irq_auto_0, NULL,
palmas_gpadc_irq_auto,
IRQF_ONESHOT,
"palmas-adc-auto-0", adc);
if (ret < 0) {
dev_err(adc->dev, "request auto0 irq %d failed: %d\n",
adc->irq_auto_0, ret);
goto out_irq_free;
}
}
if (gpadc_pdata->adc_wakeup2_data) {
memcpy(&adc->wakeup2_data, gpadc_pdata->adc_wakeup2_data,
sizeof(adc->wakeup2_data));
adc->wakeup2_enable = true;
adc->irq_auto_1 = platform_get_irq(pdev, 2);
ret = request_threaded_irq(adc->irq_auto_1, NULL,
palmas_gpadc_irq_auto,
IRQF_ONESHOT,
"palmas-adc-auto-1", adc);
if (ret < 0) {
dev_err(adc->dev, "request auto1 irq %d failed: %d\n",
adc->irq_auto_1, ret);
goto out_irq_auto0_free;
}
}
if (gpadc_pdata->ch0_current <= 1)
adc->ch0_current = PALMAS_ADC_CH0_CURRENT_SRC_0;
else if (gpadc_pdata->ch0_current <= 5)
adc->ch0_current = PALMAS_ADC_CH0_CURRENT_SRC_5;
else if (gpadc_pdata->ch0_current <= 15)
adc->ch0_current = PALMAS_ADC_CH0_CURRENT_SRC_15;
else
adc->ch0_current = PALMAS_ADC_CH0_CURRENT_SRC_20;
if (gpadc_pdata->ch3_current <= 1)
adc->ch3_current = PALMAS_ADC_CH3_CURRENT_SRC_0;
else if (gpadc_pdata->ch3_current <= 10)
adc->ch3_current = PALMAS_ADC_CH3_CURRENT_SRC_10;
else if (gpadc_pdata->ch3_current <= 400)
adc->ch3_current = PALMAS_ADC_CH3_CURRENT_SRC_400;
else
adc->ch3_current = PALMAS_ADC_CH3_CURRENT_SRC_800;
adc->extended_delay = gpadc_pdata->extended_delay;
indio_dev->name = MOD_NAME;
indio_dev->dev.parent = &pdev->dev;
indio_dev->info = &palmas_gpadc_iio_info;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->channels = palmas_gpadc_iio_channel;
indio_dev->num_channels = ARRAY_SIZE(palmas_gpadc_iio_channel);
ret = iio_device_register(indio_dev);
if (ret < 0) {
dev_err(adc->dev, "iio_device_register() failed: %d\n", ret);
goto out_irq_auto1_free;
}
device_set_wakeup_capable(&pdev->dev, 1);
for (i = 0; i < PALMAS_ADC_CH_MAX; i++) {
if (!(adc->adc_info[i].is_uncalibrated))
palmas_gpadc_calibrate(adc, i);
}
if (adc->wakeup1_enable || adc->wakeup2_enable)
device_wakeup_enable(&pdev->dev);
return 0;
out_irq_auto1_free:
if (gpadc_pdata->adc_wakeup2_data)
free_irq(adc->irq_auto_1, adc);
out_irq_auto0_free:
if (gpadc_pdata->adc_wakeup1_data)
free_irq(adc->irq_auto_0, adc);
out_irq_free:
free_irq(adc->irq, adc);
out:
return ret;
}
static int palmas_gpadc_remove(struct platform_device *pdev)
{
struct iio_dev *indio_dev = dev_to_iio_dev(&pdev->dev);
struct palmas_gpadc *adc = iio_priv(indio_dev);
if (adc->wakeup1_enable || adc->wakeup2_enable)
device_wakeup_disable(&pdev->dev);
iio_device_unregister(indio_dev);
free_irq(adc->irq, adc);
if (adc->wakeup1_enable)
free_irq(adc->irq_auto_0, adc);
if (adc->wakeup2_enable)
free_irq(adc->irq_auto_1, adc);
return 0;
}
static int palmas_adc_wakeup_configure(struct palmas_gpadc *adc)
{
int adc_period, conv;
int i;
int ch0 = 0, ch1 = 0;
int thres;
int ret;
adc_period = adc->auto_conversion_period;
for (i = 0; i < 16; ++i) {
if (((1000 * (1 << i)) / 32) < adc_period)
continue;
}
if (i > 0)
i--;
adc_period = i;
ret = palmas_update_bits(adc->palmas, PALMAS_GPADC_BASE,
PALMAS_GPADC_AUTO_CTRL,
PALMAS_GPADC_AUTO_CTRL_COUNTER_CONV_MASK,
adc_period);
if (ret < 0) {
dev_err(adc->dev, "AUTO_CTRL write failed: %d\n", ret);
return ret;
}
conv = 0;
if (adc->wakeup1_enable) {
int polarity;
ch0 = adc->wakeup1_data.adc_channel_number;
conv |= PALMAS_GPADC_AUTO_CTRL_AUTO_CONV0_EN;
if (adc->wakeup1_data.adc_high_threshold > 0) {
thres = adc->wakeup1_data.adc_high_threshold;
polarity = 0;
} else {
thres = adc->wakeup1_data.adc_low_threshold;
polarity = PALMAS_GPADC_THRES_CONV0_MSB_THRES_CONV0_POL;
}
ret = palmas_write(adc->palmas, PALMAS_GPADC_BASE,
PALMAS_GPADC_THRES_CONV0_LSB, thres & 0xFF);
if (ret < 0) {
dev_err(adc->dev,
"THRES_CONV0_LSB write failed: %d\n", ret);
return ret;
}
ret = palmas_write(adc->palmas, PALMAS_GPADC_BASE,
PALMAS_GPADC_THRES_CONV0_MSB,
((thres >> 8) & 0xF) | polarity);
if (ret < 0) {
dev_err(adc->dev,
"THRES_CONV0_MSB write failed: %d\n", ret);
return ret;
}
}
if (adc->wakeup2_enable) {
int polarity;
ch1 = adc->wakeup2_data.adc_channel_number;
conv |= PALMAS_GPADC_AUTO_CTRL_AUTO_CONV1_EN;
if (adc->wakeup2_data.adc_high_threshold > 0) {
thres = adc->wakeup2_data.adc_high_threshold;
polarity = 0;
} else {
thres = adc->wakeup2_data.adc_low_threshold;
polarity = PALMAS_GPADC_THRES_CONV1_MSB_THRES_CONV1_POL;
}
ret = palmas_write(adc->palmas, PALMAS_GPADC_BASE,
PALMAS_GPADC_THRES_CONV1_LSB, thres & 0xFF);
if (ret < 0) {
dev_err(adc->dev,
"THRES_CONV1_LSB write failed: %d\n", ret);
return ret;
}
ret = palmas_write(adc->palmas, PALMAS_GPADC_BASE,
PALMAS_GPADC_THRES_CONV1_MSB,
((thres >> 8) & 0xF) | polarity);
if (ret < 0) {
dev_err(adc->dev,
"THRES_CONV1_MSB write failed: %d\n", ret);
return ret;
}
}
ret = palmas_write(adc->palmas, PALMAS_GPADC_BASE,
PALMAS_GPADC_AUTO_SELECT, (ch1 << 4) | ch0);
if (ret < 0) {
dev_err(adc->dev, "AUTO_SELECT write failed: %d\n", ret);
return ret;
}
ret = palmas_update_bits(adc->palmas, PALMAS_GPADC_BASE,
PALMAS_GPADC_AUTO_CTRL,
PALMAS_GPADC_AUTO_CTRL_AUTO_CONV1_EN |
PALMAS_GPADC_AUTO_CTRL_AUTO_CONV0_EN, conv);
if (ret < 0)
dev_err(adc->dev, "AUTO_CTRL write failed: %d\n", ret);
return ret;
}
static int palmas_adc_wakeup_reset(struct palmas_gpadc *adc)
{
int ret;
ret = palmas_write(adc->palmas, PALMAS_GPADC_BASE,
PALMAS_GPADC_AUTO_SELECT, 0);
if (ret < 0) {
dev_err(adc->dev, "AUTO_SELECT write failed: %d\n", ret);
return ret;
}
ret = palmas_disable_auto_conversion(adc);
if (ret < 0)
dev_err(adc->dev, "Disable auto conversion failed: %d\n", ret);
return ret;
}
static int palmas_gpadc_suspend(struct device *dev)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct palmas_gpadc *adc = iio_priv(indio_dev);
int wakeup = adc->wakeup1_enable || adc->wakeup2_enable;
int ret;
if (!device_may_wakeup(dev) || !wakeup)
return 0;
ret = palmas_adc_wakeup_configure(adc);
if (ret < 0)
return ret;
if (adc->wakeup1_enable)
enable_irq_wake(adc->irq_auto_0);
if (adc->wakeup2_enable)
enable_irq_wake(adc->irq_auto_1);
return 0;
}
static int palmas_gpadc_resume(struct device *dev)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct palmas_gpadc *adc = iio_priv(indio_dev);
int wakeup = adc->wakeup1_enable || adc->wakeup2_enable;
int ret;
if (!device_may_wakeup(dev) || !wakeup)
return 0;
ret = palmas_adc_wakeup_reset(adc);
if (ret < 0)
return ret;
if (adc->wakeup1_enable)
disable_irq_wake(adc->irq_auto_0);
if (adc->wakeup2_enable)
disable_irq_wake(adc->irq_auto_1);
return 0;
}
static int __init palmas_gpadc_init(void)
{
return platform_driver_register(&palmas_gpadc_driver);
}
static void __exit palmas_gpadc_exit(void)
{
platform_driver_unregister(&palmas_gpadc_driver);
}
