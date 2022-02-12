struct ab8500_gpadc *ab8500_gpadc_get(char *name)
{
struct ab8500_gpadc *gpadc;
list_for_each_entry(gpadc, &ab8500_gpadc_list, node) {
if (!strcmp(name, dev_name(gpadc->dev)))
return gpadc;
}
return ERR_PTR(-ENOENT);
}
int ab8500_gpadc_ad_to_voltage(struct ab8500_gpadc *gpadc, u8 channel,
int ad_value)
{
int res;
switch (channel) {
case MAIN_CHARGER_V:
if (!gpadc->cal_data[ADC_INPUT_VMAIN].gain) {
res = ADC_CH_CHG_V_MIN + (ADC_CH_CHG_V_MAX -
ADC_CH_CHG_V_MIN) * ad_value /
ADC_RESOLUTION;
break;
}
res = (int) (ad_value * gpadc->cal_data[ADC_INPUT_VMAIN].gain +
gpadc->cal_data[ADC_INPUT_VMAIN].offset) / CALIB_SCALE;
break;
case BAT_CTRL:
case BTEMP_BALL:
case ACC_DETECT1:
case ADC_AUX1:
case ADC_AUX2:
if (!gpadc->cal_data[ADC_INPUT_BTEMP].gain) {
res = ADC_CH_BTEMP_MIN + (ADC_CH_BTEMP_MAX -
ADC_CH_BTEMP_MIN) * ad_value /
ADC_RESOLUTION;
break;
}
res = (int) (ad_value * gpadc->cal_data[ADC_INPUT_BTEMP].gain +
gpadc->cal_data[ADC_INPUT_BTEMP].offset) / CALIB_SCALE;
break;
case MAIN_BAT_V:
if (!gpadc->cal_data[ADC_INPUT_VBAT].gain) {
res = ADC_CH_VBAT_MIN + (ADC_CH_VBAT_MAX -
ADC_CH_VBAT_MIN) * ad_value /
ADC_RESOLUTION;
break;
}
res = (int) (ad_value * gpadc->cal_data[ADC_INPUT_VBAT].gain +
gpadc->cal_data[ADC_INPUT_VBAT].offset) / CALIB_SCALE;
break;
case DIE_TEMP:
res = ADC_CH_DIETEMP_MIN +
(ADC_CH_DIETEMP_MAX - ADC_CH_DIETEMP_MIN) * ad_value /
ADC_RESOLUTION;
break;
case ACC_DETECT2:
res = ADC_CH_ACCDET2_MIN +
(ADC_CH_ACCDET2_MAX - ADC_CH_ACCDET2_MIN) * ad_value /
ADC_RESOLUTION;
break;
case VBUS_V:
res = ADC_CH_CHG_V_MIN +
(ADC_CH_CHG_V_MAX - ADC_CH_CHG_V_MIN) * ad_value /
ADC_RESOLUTION;
break;
case MAIN_CHARGER_C:
case USB_CHARGER_C:
res = ADC_CH_CHG_I_MIN +
(ADC_CH_CHG_I_MAX - ADC_CH_CHG_I_MIN) * ad_value /
ADC_RESOLUTION;
break;
case BK_BAT_V:
res = ADC_CH_BKBAT_MIN +
(ADC_CH_BKBAT_MAX - ADC_CH_BKBAT_MIN) * ad_value /
ADC_RESOLUTION;
break;
default:
dev_err(gpadc->dev,
"unknown channel, not possible to convert\n");
res = -EINVAL;
break;
}
return res;
}
int ab8500_gpadc_convert(struct ab8500_gpadc *gpadc, u8 channel)
{
int ad_value;
int voltage;
ad_value = ab8500_gpadc_read_raw(gpadc, channel);
if (ad_value < 0) {
dev_err(gpadc->dev, "GPADC raw value failed ch: %d\n", channel);
return ad_value;
}
voltage = ab8500_gpadc_ad_to_voltage(gpadc, channel, ad_value);
if (voltage < 0)
dev_err(gpadc->dev, "GPADC to voltage conversion failed ch:"
" %d AD: 0x%x\n", channel, ad_value);
return voltage;
}
int ab8500_gpadc_read_raw(struct ab8500_gpadc *gpadc, u8 channel)
{
int ret;
int looplimit = 0;
u8 val, low_data, high_data;
if (!gpadc)
return -ENODEV;
mutex_lock(&gpadc->ab8500_gpadc_lock);
pm_runtime_get_sync(gpadc->dev);
do {
ret = abx500_get_register_interruptible(gpadc->dev,
AB8500_GPADC, AB8500_GPADC_STAT_REG, &val);
if (ret < 0)
goto out;
if (!(val & GPADC_BUSY))
break;
msleep(10);
} while (++looplimit < 10);
if (looplimit >= 10 && (val & GPADC_BUSY)) {
dev_err(gpadc->dev, "gpadc_conversion: GPADC busy");
ret = -EINVAL;
goto out;
}
ret = abx500_mask_and_set_register_interruptible(gpadc->dev,
AB8500_GPADC, AB8500_GPADC_CTRL1_REG, EN_GPADC, EN_GPADC);
if (ret < 0) {
dev_err(gpadc->dev, "gpadc_conversion: enable gpadc failed\n");
goto out;
}
ret = abx500_set_register_interruptible(gpadc->dev, AB8500_GPADC,
AB8500_GPADC_CTRL2_REG, (channel | SW_AVG_16));
if (ret < 0) {
dev_err(gpadc->dev,
"gpadc_conversion: set avg samples failed\n");
goto out;
}
switch (channel) {
case MAIN_CHARGER_C:
case USB_CHARGER_C:
ret = abx500_mask_and_set_register_interruptible(gpadc->dev,
AB8500_GPADC, AB8500_GPADC_CTRL1_REG,
EN_BUF | EN_ICHAR,
EN_BUF | EN_ICHAR);
break;
case BTEMP_BALL:
if (!is_ab8500_2p0_or_earlier(gpadc->parent)) {
ret = abx500_mask_and_set_register_interruptible(
gpadc->dev,
AB8500_GPADC, AB8500_GPADC_CTRL1_REG,
EN_BUF | BTEMP_PULL_UP,
EN_BUF | BTEMP_PULL_UP);
usleep_range(1000, 1000);
break;
}
default:
ret = abx500_mask_and_set_register_interruptible(gpadc->dev,
AB8500_GPADC, AB8500_GPADC_CTRL1_REG, EN_BUF, EN_BUF);
break;
}
if (ret < 0) {
dev_err(gpadc->dev,
"gpadc_conversion: select falling edge failed\n");
goto out;
}
ret = abx500_mask_and_set_register_interruptible(gpadc->dev,
AB8500_GPADC, AB8500_GPADC_CTRL1_REG, ADC_SW_CONV, ADC_SW_CONV);
if (ret < 0) {
dev_err(gpadc->dev,
"gpadc_conversion: start s/w conversion failed\n");
goto out;
}
if (!wait_for_completion_timeout(&gpadc->ab8500_gpadc_complete,
msecs_to_jiffies(CONVERSION_TIME))) {
dev_err(gpadc->dev,
"timeout: didn't receive GPADC conversion interrupt\n");
ret = -EINVAL;
goto out;
}
ret = abx500_get_register_interruptible(gpadc->dev, AB8500_GPADC,
AB8500_GPADC_MANDATAL_REG, &low_data);
if (ret < 0) {
dev_err(gpadc->dev, "gpadc_conversion: read low data failed\n");
goto out;
}
ret = abx500_get_register_interruptible(gpadc->dev, AB8500_GPADC,
AB8500_GPADC_MANDATAH_REG, &high_data);
if (ret < 0) {
dev_err(gpadc->dev,
"gpadc_conversion: read high data failed\n");
goto out;
}
ret = abx500_set_register_interruptible(gpadc->dev, AB8500_GPADC,
AB8500_GPADC_CTRL1_REG, DIS_GPADC);
if (ret < 0) {
dev_err(gpadc->dev, "gpadc_conversion: disable gpadc failed\n");
goto out;
}
pm_runtime_mark_last_busy(gpadc->dev);
pm_runtime_put_autosuspend(gpadc->dev);
mutex_unlock(&gpadc->ab8500_gpadc_lock);
return (high_data << 8) | low_data;
out:
(void) abx500_set_register_interruptible(gpadc->dev, AB8500_GPADC,
AB8500_GPADC_CTRL1_REG, DIS_GPADC);
pm_runtime_put(gpadc->dev);
mutex_unlock(&gpadc->ab8500_gpadc_lock);
dev_err(gpadc->dev,
"gpadc_conversion: Failed to AD convert channel %d\n", channel);
return ret;
}
static irqreturn_t ab8500_bm_gpswadcconvend_handler(int irq, void *_gpadc)
{
struct ab8500_gpadc *gpadc = _gpadc;
complete(&gpadc->ab8500_gpadc_complete);
return IRQ_HANDLED;
}
static void ab8500_gpadc_read_calibration_data(struct ab8500_gpadc *gpadc)
{
int i;
int ret[ARRAY_SIZE(otp_cal_regs)];
u8 gpadc_cal[ARRAY_SIZE(otp_cal_regs)];
int vmain_high, vmain_low;
int btemp_high, btemp_low;
int vbat_high, vbat_low;
for (i = 0; i < ARRAY_SIZE(otp_cal_regs); i++) {
ret[i] = abx500_get_register_interruptible(gpadc->dev,
AB8500_OTP_EMUL, otp_cal_regs[i], &gpadc_cal[i]);
if (ret[i] < 0)
dev_err(gpadc->dev, "%s: read otp reg 0x%02x failed\n",
__func__, otp_cal_regs[i]);
}
if (!(ret[0] < 0 || ret[1] < 0 || ret[2] < 0)) {
vmain_high = (((gpadc_cal[0] & 0x03) << 8) |
((gpadc_cal[1] & 0x3F) << 2) |
((gpadc_cal[2] & 0xC0) >> 6));
vmain_low = ((gpadc_cal[2] & 0x3E) >> 1);
gpadc->cal_data[ADC_INPUT_VMAIN].gain = CALIB_SCALE *
(19500 - 315) / (vmain_high - vmain_low);
gpadc->cal_data[ADC_INPUT_VMAIN].offset = CALIB_SCALE * 19500 -
(CALIB_SCALE * (19500 - 315) /
(vmain_high - vmain_low)) * vmain_high;
} else {
gpadc->cal_data[ADC_INPUT_VMAIN].gain = 0;
}
if (!(ret[2] < 0 || ret[3] < 0 || ret[4] < 0)) {
btemp_high = (((gpadc_cal[2] & 0x01) << 9) |
(gpadc_cal[3] << 1) |
((gpadc_cal[4] & 0x80) >> 7));
btemp_low = ((gpadc_cal[4] & 0x7C) >> 2);
gpadc->cal_data[ADC_INPUT_BTEMP].gain =
CALIB_SCALE * (1300 - 21) / (btemp_high - btemp_low);
gpadc->cal_data[ADC_INPUT_BTEMP].offset = CALIB_SCALE * 1300 -
(CALIB_SCALE * (1300 - 21) /
(btemp_high - btemp_low)) * btemp_high;
} else {
gpadc->cal_data[ADC_INPUT_BTEMP].gain = 0;
}
if (!(ret[4] < 0 || ret[5] < 0 || ret[6] < 0)) {
vbat_high = (((gpadc_cal[4] & 0x03) << 8) | gpadc_cal[5]);
vbat_low = ((gpadc_cal[6] & 0xFC) >> 2);
gpadc->cal_data[ADC_INPUT_VBAT].gain = CALIB_SCALE *
(4700 - 2380) / (vbat_high - vbat_low);
gpadc->cal_data[ADC_INPUT_VBAT].offset = CALIB_SCALE * 4700 -
(CALIB_SCALE * (4700 - 2380) /
(vbat_high - vbat_low)) * vbat_high;
} else {
gpadc->cal_data[ADC_INPUT_VBAT].gain = 0;
}
dev_dbg(gpadc->dev, "VMAIN gain %llu offset %llu\n",
gpadc->cal_data[ADC_INPUT_VMAIN].gain,
gpadc->cal_data[ADC_INPUT_VMAIN].offset);
dev_dbg(gpadc->dev, "BTEMP gain %llu offset %llu\n",
gpadc->cal_data[ADC_INPUT_BTEMP].gain,
gpadc->cal_data[ADC_INPUT_BTEMP].offset);
dev_dbg(gpadc->dev, "VBAT gain %llu offset %llu\n",
gpadc->cal_data[ADC_INPUT_VBAT].gain,
gpadc->cal_data[ADC_INPUT_VBAT].offset);
}
static int ab8500_gpadc_runtime_suspend(struct device *dev)
{
struct ab8500_gpadc *gpadc = dev_get_drvdata(dev);
regulator_disable(gpadc->regu);
return 0;
}
static int ab8500_gpadc_runtime_resume(struct device *dev)
{
struct ab8500_gpadc *gpadc = dev_get_drvdata(dev);
int ret;
ret = regulator_enable(gpadc->regu);
if (ret)
dev_err(dev, "Failed to enable vtvout LDO: %d\n", ret);
return ret;
}
static int ab8500_gpadc_runtime_idle(struct device *dev)
{
pm_runtime_suspend(dev);
return 0;
}
static int ab8500_gpadc_probe(struct platform_device *pdev)
{
int ret = 0;
struct ab8500_gpadc *gpadc;
gpadc = kzalloc(sizeof(struct ab8500_gpadc), GFP_KERNEL);
if (!gpadc) {
dev_err(&pdev->dev, "Error: No memory\n");
return -ENOMEM;
}
gpadc->irq = platform_get_irq_byname(pdev, "SW_CONV_END");
if (gpadc->irq < 0) {
dev_err(&pdev->dev, "failed to get platform irq-%d\n",
gpadc->irq);
ret = gpadc->irq;
goto fail;
}
gpadc->dev = &pdev->dev;
gpadc->parent = dev_get_drvdata(pdev->dev.parent);
mutex_init(&gpadc->ab8500_gpadc_lock);
init_completion(&gpadc->ab8500_gpadc_complete);
ret = request_threaded_irq(gpadc->irq, NULL,
ab8500_bm_gpswadcconvend_handler,
IRQF_ONESHOT | IRQF_NO_SUSPEND | IRQF_SHARED,
"ab8500-gpadc", gpadc);
if (ret < 0) {
dev_err(gpadc->dev, "Failed to register interrupt, irq: %d\n",
gpadc->irq);
goto fail;
}
gpadc->regu = devm_regulator_get(&pdev->dev, "vddadc");
if (IS_ERR(gpadc->regu)) {
ret = PTR_ERR(gpadc->regu);
dev_err(gpadc->dev, "failed to get vtvout LDO\n");
goto fail_irq;
}
platform_set_drvdata(pdev, gpadc);
ret = regulator_enable(gpadc->regu);
if (ret) {
dev_err(gpadc->dev, "Failed to enable vtvout LDO: %d\n", ret);
goto fail_enable;
}
pm_runtime_set_autosuspend_delay(gpadc->dev, GPADC_AUDOSUSPEND_DELAY);
pm_runtime_use_autosuspend(gpadc->dev);
pm_runtime_set_active(gpadc->dev);
pm_runtime_enable(gpadc->dev);
ab8500_gpadc_read_calibration_data(gpadc);
list_add_tail(&gpadc->node, &ab8500_gpadc_list);
dev_dbg(gpadc->dev, "probe success\n");
return 0;
fail_enable:
fail_irq:
free_irq(gpadc->irq, gpadc);
fail:
kfree(gpadc);
gpadc = NULL;
return ret;
}
static int ab8500_gpadc_remove(struct platform_device *pdev)
{
struct ab8500_gpadc *gpadc = platform_get_drvdata(pdev);
list_del(&gpadc->node);
free_irq(gpadc->irq, gpadc);
pm_runtime_get_sync(gpadc->dev);
pm_runtime_disable(gpadc->dev);
regulator_disable(gpadc->regu);
pm_runtime_set_suspended(gpadc->dev);
pm_runtime_put_noidle(gpadc->dev);
kfree(gpadc);
gpadc = NULL;
return 0;
}
static int __init ab8500_gpadc_init(void)
{
return platform_driver_register(&ab8500_gpadc_driver);
}
static void __exit ab8500_gpadc_exit(void)
{
platform_driver_unregister(&ab8500_gpadc_driver);
}
