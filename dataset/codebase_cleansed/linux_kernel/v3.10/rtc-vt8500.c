static irqreturn_t vt8500_rtc_irq(int irq, void *dev_id)
{
struct vt8500_rtc *vt8500_rtc = dev_id;
u32 isr;
unsigned long events = 0;
spin_lock(&vt8500_rtc->lock);
isr = readl(vt8500_rtc->regbase + VT8500_RTC_IS);
writel(isr, vt8500_rtc->regbase + VT8500_RTC_IS);
spin_unlock(&vt8500_rtc->lock);
if (isr & VT8500_RTC_IS_ALARM)
events |= RTC_AF | RTC_IRQF;
rtc_update_irq(vt8500_rtc->rtc, 1, events);
return IRQ_HANDLED;
}
static int vt8500_rtc_read_time(struct device *dev, struct rtc_time *tm)
{
struct vt8500_rtc *vt8500_rtc = dev_get_drvdata(dev);
u32 date, time;
date = readl(vt8500_rtc->regbase + VT8500_RTC_DR);
time = readl(vt8500_rtc->regbase + VT8500_RTC_TR);
tm->tm_sec = bcd2bin(time & TIME_SEC_MASK);
tm->tm_min = bcd2bin((time & TIME_MIN_MASK) >> TIME_MIN_S);
tm->tm_hour = bcd2bin((time & TIME_HOUR_MASK) >> TIME_HOUR_S);
tm->tm_mday = bcd2bin(date & DATE_DAY_MASK);
tm->tm_mon = bcd2bin((date & DATE_MONTH_MASK) >> DATE_MONTH_S) - 1;
tm->tm_year = bcd2bin((date & DATE_YEAR_MASK) >> DATE_YEAR_S)
+ ((date >> DATE_CENTURY_S) & 1 ? 200 : 100);
tm->tm_wday = (time & TIME_DOW_MASK) >> TIME_DOW_S;
return 0;
}
static int vt8500_rtc_set_time(struct device *dev, struct rtc_time *tm)
{
struct vt8500_rtc *vt8500_rtc = dev_get_drvdata(dev);
if (tm->tm_year < 100) {
dev_warn(dev, "Only years 2000-2199 are supported by the "
"hardware!\n");
return -EINVAL;
}
writel((bin2bcd(tm->tm_year % 100) << DATE_YEAR_S)
| (bin2bcd(tm->tm_mon + 1) << DATE_MONTH_S)
| (bin2bcd(tm->tm_mday))
| ((tm->tm_year >= 200) << DATE_CENTURY_S),
vt8500_rtc->regbase + VT8500_RTC_DS);
writel((bin2bcd(tm->tm_wday) << TIME_DOW_S)
| (bin2bcd(tm->tm_hour) << TIME_HOUR_S)
| (bin2bcd(tm->tm_min) << TIME_MIN_S)
| (bin2bcd(tm->tm_sec)),
vt8500_rtc->regbase + VT8500_RTC_TS);
return 0;
}
static int vt8500_rtc_read_alarm(struct device *dev, struct rtc_wkalrm *alrm)
{
struct vt8500_rtc *vt8500_rtc = dev_get_drvdata(dev);
u32 isr, alarm;
alarm = readl(vt8500_rtc->regbase + VT8500_RTC_AS);
isr = readl(vt8500_rtc->regbase + VT8500_RTC_IS);
alrm->time.tm_mday = bcd2bin((alarm & ALARM_DAY_MASK) >> ALARM_DAY_S);
alrm->time.tm_hour = bcd2bin((alarm & TIME_HOUR_MASK) >> TIME_HOUR_S);
alrm->time.tm_min = bcd2bin((alarm & TIME_MIN_MASK) >> TIME_MIN_S);
alrm->time.tm_sec = bcd2bin((alarm & TIME_SEC_MASK));
alrm->enabled = (alarm & ALARM_ENABLE_MASK) ? 1 : 0;
alrm->pending = (isr & VT8500_RTC_IS_ALARM) ? 1 : 0;
return rtc_valid_tm(&alrm->time);
}
static int vt8500_rtc_set_alarm(struct device *dev, struct rtc_wkalrm *alrm)
{
struct vt8500_rtc *vt8500_rtc = dev_get_drvdata(dev);
writel((alrm->enabled ? ALARM_ENABLE_MASK : 0)
| (bin2bcd(alrm->time.tm_mday) << ALARM_DAY_S)
| (bin2bcd(alrm->time.tm_hour) << TIME_HOUR_S)
| (bin2bcd(alrm->time.tm_min) << TIME_MIN_S)
| (bin2bcd(alrm->time.tm_sec)),
vt8500_rtc->regbase + VT8500_RTC_AS);
return 0;
}
static int vt8500_alarm_irq_enable(struct device *dev, unsigned int enabled)
{
struct vt8500_rtc *vt8500_rtc = dev_get_drvdata(dev);
unsigned long tmp = readl(vt8500_rtc->regbase + VT8500_RTC_AS);
if (enabled)
tmp |= ALARM_ENABLE_MASK;
else
tmp &= ~ALARM_ENABLE_MASK;
writel(tmp, vt8500_rtc->regbase + VT8500_RTC_AS);
return 0;
}
static int vt8500_rtc_probe(struct platform_device *pdev)
{
struct vt8500_rtc *vt8500_rtc;
int ret;
vt8500_rtc = devm_kzalloc(&pdev->dev,
sizeof(struct vt8500_rtc), GFP_KERNEL);
if (!vt8500_rtc)
return -ENOMEM;
spin_lock_init(&vt8500_rtc->lock);
platform_set_drvdata(pdev, vt8500_rtc);
vt8500_rtc->res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!vt8500_rtc->res) {
dev_err(&pdev->dev, "No I/O memory resource defined\n");
return -ENXIO;
}
vt8500_rtc->irq_alarm = platform_get_irq(pdev, 0);
if (vt8500_rtc->irq_alarm < 0) {
dev_err(&pdev->dev, "No alarm IRQ resource defined\n");
return -ENXIO;
}
vt8500_rtc->res = devm_request_mem_region(&pdev->dev,
vt8500_rtc->res->start,
resource_size(vt8500_rtc->res),
"vt8500-rtc");
if (vt8500_rtc->res == NULL) {
dev_err(&pdev->dev, "failed to request I/O memory\n");
return -EBUSY;
}
vt8500_rtc->regbase = devm_ioremap(&pdev->dev, vt8500_rtc->res->start,
resource_size(vt8500_rtc->res));
if (!vt8500_rtc->regbase) {
dev_err(&pdev->dev, "Unable to map RTC I/O memory\n");
ret = -EBUSY;
goto err_return;
}
writel(VT8500_RTC_CR_ENABLE,
vt8500_rtc->regbase + VT8500_RTC_CR);
vt8500_rtc->rtc = devm_rtc_device_register(&pdev->dev, "vt8500-rtc",
&vt8500_rtc_ops, THIS_MODULE);
if (IS_ERR(vt8500_rtc->rtc)) {
ret = PTR_ERR(vt8500_rtc->rtc);
dev_err(&pdev->dev,
"Failed to register RTC device -> %d\n", ret);
goto err_return;
}
ret = devm_request_irq(&pdev->dev, vt8500_rtc->irq_alarm,
vt8500_rtc_irq, 0, "rtc alarm", vt8500_rtc);
if (ret < 0) {
dev_err(&pdev->dev, "can't get irq %i, err %d\n",
vt8500_rtc->irq_alarm, ret);
goto err_return;
}
return 0;
err_return:
return ret;
}
static int vt8500_rtc_remove(struct platform_device *pdev)
{
struct vt8500_rtc *vt8500_rtc = platform_get_drvdata(pdev);
writel(0, vt8500_rtc->regbase + VT8500_RTC_IS);
platform_set_drvdata(pdev, NULL);
return 0;
}
