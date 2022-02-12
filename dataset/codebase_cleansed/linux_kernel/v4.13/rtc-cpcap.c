static void cpcap2rtc_time(struct rtc_time *rtc, struct cpcap_time *cpcap)
{
unsigned long int tod;
unsigned long int time;
tod = (cpcap->tod1 & TOD1_MASK) | ((cpcap->tod2 & TOD2_MASK) << 8);
time = tod + ((cpcap->day & DAY_MASK) * SECS_PER_DAY);
rtc_time_to_tm(time, rtc);
}
static void rtc2cpcap_time(struct cpcap_time *cpcap, struct rtc_time *rtc)
{
unsigned long time;
rtc_tm_to_time(rtc, &time);
cpcap->day = time / SECS_PER_DAY;
time %= SECS_PER_DAY;
cpcap->tod2 = (time >> 8) & TOD2_MASK;
cpcap->tod1 = time & TOD1_MASK;
}
static int cpcap_rtc_alarm_irq_enable(struct device *dev, unsigned int enabled)
{
struct cpcap_rtc *rtc = dev_get_drvdata(dev);
if (rtc->alarm_enabled == enabled)
return 0;
if (enabled)
enable_irq(rtc->alarm_irq);
else
disable_irq(rtc->alarm_irq);
rtc->alarm_enabled = !!enabled;
return 0;
}
static int cpcap_rtc_read_time(struct device *dev, struct rtc_time *tm)
{
struct cpcap_rtc *rtc;
struct cpcap_time cpcap_tm;
int temp_tod2;
int ret;
rtc = dev_get_drvdata(dev);
ret = regmap_read(rtc->regmap, CPCAP_REG_TOD2, &temp_tod2);
ret |= regmap_read(rtc->regmap, CPCAP_REG_DAY, &cpcap_tm.day);
ret |= regmap_read(rtc->regmap, CPCAP_REG_TOD1, &cpcap_tm.tod1);
ret |= regmap_read(rtc->regmap, CPCAP_REG_TOD2, &cpcap_tm.tod2);
if (temp_tod2 > cpcap_tm.tod2)
ret |= regmap_read(rtc->regmap, CPCAP_REG_DAY, &cpcap_tm.day);
if (ret) {
dev_err(dev, "Failed to read time\n");
return -EIO;
}
cpcap2rtc_time(tm, &cpcap_tm);
return rtc_valid_tm(tm);
}
static int cpcap_rtc_set_time(struct device *dev, struct rtc_time *tm)
{
struct cpcap_rtc *rtc;
struct cpcap_time cpcap_tm;
int ret = 0;
rtc = dev_get_drvdata(dev);
rtc2cpcap_time(&cpcap_tm, tm);
if (rtc->alarm_enabled)
disable_irq(rtc->alarm_irq);
if (rtc->update_enabled)
disable_irq(rtc->update_irq);
if (rtc->vendor == CPCAP_VENDOR_ST) {
ret |= regmap_update_bits(rtc->regmap, CPCAP_REG_TOD1,
TOD1_MASK, cpcap_tm.tod1);
ret |= regmap_update_bits(rtc->regmap, CPCAP_REG_TOD2,
TOD2_MASK, cpcap_tm.tod2);
ret |= regmap_update_bits(rtc->regmap, CPCAP_REG_DAY,
DAY_MASK, cpcap_tm.day);
} else {
ret |= regmap_update_bits(rtc->regmap, CPCAP_REG_TOD1,
TOD1_MASK, 0);
ret |= regmap_update_bits(rtc->regmap, CPCAP_REG_DAY,
DAY_MASK, cpcap_tm.day);
ret |= regmap_update_bits(rtc->regmap, CPCAP_REG_TOD2,
TOD2_MASK, cpcap_tm.tod2);
ret |= regmap_update_bits(rtc->regmap, CPCAP_REG_TOD1,
TOD1_MASK, cpcap_tm.tod1);
}
if (rtc->update_enabled)
enable_irq(rtc->update_irq);
if (rtc->alarm_enabled)
enable_irq(rtc->alarm_irq);
return ret;
}
static int cpcap_rtc_read_alarm(struct device *dev, struct rtc_wkalrm *alrm)
{
struct cpcap_rtc *rtc;
struct cpcap_time cpcap_tm;
int ret;
rtc = dev_get_drvdata(dev);
alrm->enabled = rtc->alarm_enabled;
ret = regmap_read(rtc->regmap, CPCAP_REG_DAYA, &cpcap_tm.day);
ret |= regmap_read(rtc->regmap, CPCAP_REG_TODA2, &cpcap_tm.tod2);
ret |= regmap_read(rtc->regmap, CPCAP_REG_TODA1, &cpcap_tm.tod1);
if (ret) {
dev_err(dev, "Failed to read time\n");
return -EIO;
}
cpcap2rtc_time(&alrm->time, &cpcap_tm);
return rtc_valid_tm(&alrm->time);
}
static int cpcap_rtc_set_alarm(struct device *dev, struct rtc_wkalrm *alrm)
{
struct cpcap_rtc *rtc;
struct cpcap_time cpcap_tm;
int ret;
rtc = dev_get_drvdata(dev);
rtc2cpcap_time(&cpcap_tm, &alrm->time);
if (rtc->alarm_enabled)
disable_irq(rtc->alarm_irq);
ret = regmap_update_bits(rtc->regmap, CPCAP_REG_DAYA, DAY_MASK,
cpcap_tm.day);
ret |= regmap_update_bits(rtc->regmap, CPCAP_REG_TODA2, TOD2_MASK,
cpcap_tm.tod2);
ret |= regmap_update_bits(rtc->regmap, CPCAP_REG_TODA1, TOD1_MASK,
cpcap_tm.tod1);
if (!ret) {
enable_irq(rtc->alarm_irq);
rtc->alarm_enabled = true;
}
return ret;
}
static irqreturn_t cpcap_rtc_alarm_irq(int irq, void *data)
{
struct cpcap_rtc *rtc = data;
rtc_update_irq(rtc->rtc_dev, 1, RTC_AF | RTC_IRQF);
return IRQ_HANDLED;
}
static irqreturn_t cpcap_rtc_update_irq(int irq, void *data)
{
struct cpcap_rtc *rtc = data;
rtc_update_irq(rtc->rtc_dev, 1, RTC_UF | RTC_IRQF);
return IRQ_HANDLED;
}
static int cpcap_rtc_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct cpcap_rtc *rtc;
int err;
rtc = devm_kzalloc(dev, sizeof(*rtc), GFP_KERNEL);
if (!rtc)
return -ENOMEM;
rtc->regmap = dev_get_regmap(dev->parent, NULL);
if (!rtc->regmap)
return -ENODEV;
platform_set_drvdata(pdev, rtc);
rtc->rtc_dev = devm_rtc_device_register(dev, "cpcap_rtc",
&cpcap_rtc_ops, THIS_MODULE);
if (IS_ERR(rtc->rtc_dev))
return PTR_ERR(rtc->rtc_dev);
err = cpcap_get_vendor(dev, rtc->regmap, &rtc->vendor);
if (err)
return err;
rtc->alarm_irq = platform_get_irq(pdev, 0);
err = devm_request_threaded_irq(dev, rtc->alarm_irq, NULL,
cpcap_rtc_alarm_irq, IRQF_TRIGGER_NONE,
"rtc_alarm", rtc);
if (err) {
dev_err(dev, "Could not request alarm irq: %d\n", err);
return err;
}
disable_irq(rtc->alarm_irq);
rtc->update_irq = platform_get_irq(pdev, 1);
err = devm_request_threaded_irq(dev, rtc->update_irq, NULL,
cpcap_rtc_update_irq, IRQF_TRIGGER_NONE,
"rtc_1hz", rtc);
if (err) {
dev_err(dev, "Could not request update irq: %d\n", err);
return err;
}
disable_irq(rtc->update_irq);
err = device_init_wakeup(dev, 1);
if (err) {
dev_err(dev, "wakeup initialization failed (%d)\n", err);
}
return 0;
}
