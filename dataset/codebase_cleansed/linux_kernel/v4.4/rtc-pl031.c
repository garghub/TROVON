static int pl031_alarm_irq_enable(struct device *dev,
unsigned int enabled)
{
struct pl031_local *ldata = dev_get_drvdata(dev);
unsigned long imsc;
writel(RTC_BIT_AI, ldata->base + RTC_ICR);
imsc = readl(ldata->base + RTC_IMSC);
if (enabled == 1)
writel(imsc | RTC_BIT_AI, ldata->base + RTC_IMSC);
else
writel(imsc & ~RTC_BIT_AI, ldata->base + RTC_IMSC);
return 0;
}
static int pl031_stv2_tm_to_time(struct device *dev,
struct rtc_time *tm, unsigned long *st_time,
unsigned long *bcd_year)
{
int year = tm->tm_year + 1900;
int wday = tm->tm_wday;
if (wday < -1 || wday > 6) {
dev_err(dev, "invalid wday value %d\n", tm->tm_wday);
return -EINVAL;
} else if (wday == -1) {
unsigned long time;
struct rtc_time calc_tm;
rtc_tm_to_time(tm, &time);
rtc_time_to_tm(time, &calc_tm);
wday = calc_tm.tm_wday;
}
*bcd_year = (bin2bcd(year % 100) | bin2bcd(year / 100) << 8);
*st_time = ((tm->tm_mon + 1) << RTC_MON_SHIFT)
| (tm->tm_mday << RTC_MDAY_SHIFT)
| ((wday + 1) << RTC_WDAY_SHIFT)
| (tm->tm_hour << RTC_HOUR_SHIFT)
| (tm->tm_min << RTC_MIN_SHIFT)
| (tm->tm_sec << RTC_SEC_SHIFT);
return 0;
}
static int pl031_stv2_time_to_tm(unsigned long st_time, unsigned long bcd_year,
struct rtc_time *tm)
{
tm->tm_year = bcd2bin(bcd_year) + (bcd2bin(bcd_year >> 8) * 100);
tm->tm_mon = ((st_time & RTC_MON_MASK) >> RTC_MON_SHIFT) - 1;
tm->tm_mday = ((st_time & RTC_MDAY_MASK) >> RTC_MDAY_SHIFT);
tm->tm_wday = ((st_time & RTC_WDAY_MASK) >> RTC_WDAY_SHIFT) - 1;
tm->tm_hour = ((st_time & RTC_HOUR_MASK) >> RTC_HOUR_SHIFT);
tm->tm_min = ((st_time & RTC_MIN_MASK) >> RTC_MIN_SHIFT);
tm->tm_sec = ((st_time & RTC_SEC_MASK) >> RTC_SEC_SHIFT);
tm->tm_yday = rtc_year_days(tm->tm_mday, tm->tm_mon, tm->tm_year);
tm->tm_year -= 1900;
return 0;
}
static int pl031_stv2_read_time(struct device *dev, struct rtc_time *tm)
{
struct pl031_local *ldata = dev_get_drvdata(dev);
pl031_stv2_time_to_tm(readl(ldata->base + RTC_DR),
readl(ldata->base + RTC_YDR), tm);
return 0;
}
static int pl031_stv2_set_time(struct device *dev, struct rtc_time *tm)
{
unsigned long time;
unsigned long bcd_year;
struct pl031_local *ldata = dev_get_drvdata(dev);
int ret;
ret = pl031_stv2_tm_to_time(dev, tm, &time, &bcd_year);
if (ret == 0) {
writel(bcd_year, ldata->base + RTC_YLR);
writel(time, ldata->base + RTC_LR);
}
return ret;
}
static int pl031_stv2_read_alarm(struct device *dev, struct rtc_wkalrm *alarm)
{
struct pl031_local *ldata = dev_get_drvdata(dev);
int ret;
ret = pl031_stv2_time_to_tm(readl(ldata->base + RTC_MR),
readl(ldata->base + RTC_YMR), &alarm->time);
alarm->pending = readl(ldata->base + RTC_RIS) & RTC_BIT_AI;
alarm->enabled = readl(ldata->base + RTC_IMSC) & RTC_BIT_AI;
return ret;
}
static int pl031_stv2_set_alarm(struct device *dev, struct rtc_wkalrm *alarm)
{
struct pl031_local *ldata = dev_get_drvdata(dev);
unsigned long time;
unsigned long bcd_year;
int ret;
ret = rtc_valid_tm(&alarm->time);
if (ret == 0) {
ret = pl031_stv2_tm_to_time(dev, &alarm->time,
&time, &bcd_year);
if (ret == 0) {
writel(bcd_year, ldata->base + RTC_YMR);
writel(time, ldata->base + RTC_MR);
pl031_alarm_irq_enable(dev, alarm->enabled);
}
}
return ret;
}
static irqreturn_t pl031_interrupt(int irq, void *dev_id)
{
struct pl031_local *ldata = dev_id;
unsigned long rtcmis;
unsigned long events = 0;
rtcmis = readl(ldata->base + RTC_MIS);
if (rtcmis & RTC_BIT_AI) {
writel(RTC_BIT_AI, ldata->base + RTC_ICR);
events |= (RTC_AF | RTC_IRQF);
rtc_update_irq(ldata->rtc, 1, events);
return IRQ_HANDLED;
}
return IRQ_NONE;
}
static int pl031_read_time(struct device *dev, struct rtc_time *tm)
{
struct pl031_local *ldata = dev_get_drvdata(dev);
rtc_time_to_tm(readl(ldata->base + RTC_DR), tm);
return 0;
}
static int pl031_set_time(struct device *dev, struct rtc_time *tm)
{
unsigned long time;
struct pl031_local *ldata = dev_get_drvdata(dev);
int ret;
ret = rtc_tm_to_time(tm, &time);
if (ret == 0)
writel(time, ldata->base + RTC_LR);
return ret;
}
static int pl031_read_alarm(struct device *dev, struct rtc_wkalrm *alarm)
{
struct pl031_local *ldata = dev_get_drvdata(dev);
rtc_time_to_tm(readl(ldata->base + RTC_MR), &alarm->time);
alarm->pending = readl(ldata->base + RTC_RIS) & RTC_BIT_AI;
alarm->enabled = readl(ldata->base + RTC_IMSC) & RTC_BIT_AI;
return 0;
}
static int pl031_set_alarm(struct device *dev, struct rtc_wkalrm *alarm)
{
struct pl031_local *ldata = dev_get_drvdata(dev);
unsigned long time;
int ret;
ret = rtc_valid_tm(&alarm->time);
if (ret == 0) {
ret = rtc_tm_to_time(&alarm->time, &time);
if (ret == 0) {
writel(time, ldata->base + RTC_MR);
pl031_alarm_irq_enable(dev, alarm->enabled);
}
}
return ret;
}
static int pl031_remove(struct amba_device *adev)
{
struct pl031_local *ldata = dev_get_drvdata(&adev->dev);
dev_pm_clear_wake_irq(&adev->dev);
device_init_wakeup(&adev->dev, false);
free_irq(adev->irq[0], ldata);
rtc_device_unregister(ldata->rtc);
iounmap(ldata->base);
kfree(ldata);
amba_release_regions(adev);
return 0;
}
static int pl031_probe(struct amba_device *adev, const struct amba_id *id)
{
int ret;
struct pl031_local *ldata;
struct pl031_vendor_data *vendor = id->data;
struct rtc_class_ops *ops = &vendor->ops;
unsigned long time, data;
ret = amba_request_regions(adev, NULL);
if (ret)
goto err_req;
ldata = kzalloc(sizeof(struct pl031_local), GFP_KERNEL);
if (!ldata) {
ret = -ENOMEM;
goto out;
}
ldata->vendor = vendor;
ldata->base = ioremap(adev->res.start, resource_size(&adev->res));
if (!ldata->base) {
ret = -ENOMEM;
goto out_no_remap;
}
amba_set_drvdata(adev, ldata);
dev_dbg(&adev->dev, "designer ID = 0x%02x\n", amba_manf(adev));
dev_dbg(&adev->dev, "revision = 0x%01x\n", amba_rev(adev));
data = readl(ldata->base + RTC_CR);
if (vendor->clockwatch)
data |= RTC_CR_CWEN;
else
data |= RTC_CR_EN;
writel(data, ldata->base + RTC_CR);
if (vendor->st_weekday) {
if (readl(ldata->base + RTC_YDR) == 0x2000) {
time = readl(ldata->base + RTC_DR);
if ((time &
(RTC_MON_MASK | RTC_MDAY_MASK | RTC_WDAY_MASK))
== 0x02120000) {
time = time | (0x7 << RTC_WDAY_SHIFT);
writel(0x2000, ldata->base + RTC_YLR);
writel(time, ldata->base + RTC_LR);
}
}
}
device_init_wakeup(&adev->dev, true);
ldata->rtc = rtc_device_register("pl031", &adev->dev, ops,
THIS_MODULE);
if (IS_ERR(ldata->rtc)) {
ret = PTR_ERR(ldata->rtc);
goto out_no_rtc;
}
if (request_irq(adev->irq[0], pl031_interrupt,
vendor->irqflags, "rtc-pl031", ldata)) {
ret = -EIO;
goto out_no_irq;
}
dev_pm_set_wake_irq(&adev->dev, adev->irq[0]);
return 0;
out_no_irq:
rtc_device_unregister(ldata->rtc);
out_no_rtc:
iounmap(ldata->base);
out_no_remap:
kfree(ldata);
out:
amba_release_regions(adev);
err_req:
return ret;
}
