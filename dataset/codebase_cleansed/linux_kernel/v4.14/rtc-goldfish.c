static int goldfish_rtc_read_alarm(struct device *dev,
struct rtc_wkalrm *alrm)
{
u64 rtc_alarm;
u64 rtc_alarm_low;
u64 rtc_alarm_high;
void __iomem *base;
struct goldfish_rtc *rtcdrv;
rtcdrv = dev_get_drvdata(dev);
base = rtcdrv->base;
rtc_alarm_low = readl(base + TIMER_ALARM_LOW);
rtc_alarm_high = readl(base + TIMER_ALARM_HIGH);
rtc_alarm = (rtc_alarm_high << 32) | rtc_alarm_low;
do_div(rtc_alarm, NSEC_PER_SEC);
memset(alrm, 0, sizeof(struct rtc_wkalrm));
rtc_time_to_tm(rtc_alarm, &alrm->time);
if (readl(base + TIMER_ALARM_STATUS))
alrm->enabled = 1;
else
alrm->enabled = 0;
return 0;
}
static int goldfish_rtc_set_alarm(struct device *dev,
struct rtc_wkalrm *alrm)
{
struct goldfish_rtc *rtcdrv;
unsigned long rtc_alarm;
u64 rtc_alarm64;
u64 rtc_status_reg;
void __iomem *base;
int ret = 0;
rtcdrv = dev_get_drvdata(dev);
base = rtcdrv->base;
if (alrm->enabled) {
ret = rtc_tm_to_time(&alrm->time, &rtc_alarm);
if (ret != 0)
return ret;
rtc_alarm64 = rtc_alarm * NSEC_PER_SEC;
writel((rtc_alarm64 >> 32), base + TIMER_ALARM_HIGH);
writel(rtc_alarm64, base + TIMER_ALARM_LOW);
} else {
rtc_status_reg = readl(base + TIMER_ALARM_STATUS);
if (rtc_status_reg)
writel(1, base + TIMER_CLEAR_ALARM);
}
return ret;
}
static int goldfish_rtc_alarm_irq_enable(struct device *dev,
unsigned int enabled)
{
void __iomem *base;
struct goldfish_rtc *rtcdrv;
rtcdrv = dev_get_drvdata(dev);
base = rtcdrv->base;
if (enabled)
writel(1, base + TIMER_IRQ_ENABLED);
else
writel(0, base + TIMER_IRQ_ENABLED);
return 0;
}
static irqreturn_t goldfish_rtc_interrupt(int irq, void *dev_id)
{
struct goldfish_rtc *rtcdrv = dev_id;
void __iomem *base = rtcdrv->base;
writel(1, base + TIMER_CLEAR_INTERRUPT);
rtc_update_irq(rtcdrv->rtc, 1, RTC_IRQF | RTC_AF);
return IRQ_HANDLED;
}
static int goldfish_rtc_read_time(struct device *dev, struct rtc_time *tm)
{
struct goldfish_rtc *rtcdrv;
void __iomem *base;
u64 time_high;
u64 time_low;
u64 time;
rtcdrv = dev_get_drvdata(dev);
base = rtcdrv->base;
time_low = readl(base + TIMER_TIME_LOW);
time_high = readl(base + TIMER_TIME_HIGH);
time = (time_high << 32) | time_low;
do_div(time, NSEC_PER_SEC);
rtc_time_to_tm(time, tm);
return 0;
}
static int goldfish_rtc_set_time(struct device *dev, struct rtc_time *tm)
{
struct goldfish_rtc *rtcdrv;
void __iomem *base;
unsigned long now;
u64 now64;
int ret;
rtcdrv = dev_get_drvdata(dev);
base = rtcdrv->base;
ret = rtc_tm_to_time(tm, &now);
if (ret == 0) {
now64 = now * NSEC_PER_SEC;
writel((now64 >> 32), base + TIMER_TIME_HIGH);
writel(now64, base + TIMER_TIME_LOW);
}
return ret;
}
static int goldfish_rtc_probe(struct platform_device *pdev)
{
struct goldfish_rtc *rtcdrv;
struct resource *r;
int err;
rtcdrv = devm_kzalloc(&pdev->dev, sizeof(*rtcdrv), GFP_KERNEL);
if (!rtcdrv)
return -ENOMEM;
platform_set_drvdata(pdev, rtcdrv);
r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!r)
return -ENODEV;
rtcdrv->base = devm_ioremap_resource(&pdev->dev, r);
if (IS_ERR(rtcdrv->base))
return -ENODEV;
rtcdrv->irq = platform_get_irq(pdev, 0);
if (rtcdrv->irq < 0)
return -ENODEV;
rtcdrv->rtc = devm_rtc_device_register(&pdev->dev, pdev->name,
&goldfish_rtc_ops,
THIS_MODULE);
if (IS_ERR(rtcdrv->rtc))
return PTR_ERR(rtcdrv->rtc);
err = devm_request_irq(&pdev->dev, rtcdrv->irq,
goldfish_rtc_interrupt,
0, pdev->name, rtcdrv);
if (err)
return err;
return 0;
}
