static void rtc_delayed_write(u32 val, struct armada38x_rtc *rtc, int offset)
{
writel(val, rtc->regs + offset);
udelay(5);
}
static int armada38x_rtc_read_time(struct device *dev, struct rtc_time *tm)
{
struct armada38x_rtc *rtc = dev_get_drvdata(dev);
unsigned long time, time_check, flags;
spin_lock_irqsave(&rtc->lock, flags);
time = readl(rtc->regs + RTC_TIME);
time_check = readl(rtc->regs + RTC_TIME);
if ((time_check - time) > 1)
time_check = readl(rtc->regs + RTC_TIME);
spin_unlock_irqrestore(&rtc->lock, flags);
rtc_time_to_tm(time_check, tm);
return 0;
}
static int armada38x_rtc_set_time(struct device *dev, struct rtc_time *tm)
{
struct armada38x_rtc *rtc = dev_get_drvdata(dev);
int ret = 0;
unsigned long time, flags;
ret = rtc_tm_to_time(tm, &time);
if (ret)
goto out;
spin_lock_irqsave(&rtc->lock, flags);
rtc_delayed_write(0, rtc, RTC_STATUS);
spin_unlock_irqrestore(&rtc->lock, flags);
msleep(100);
spin_lock_irqsave(&rtc->lock, flags);
rtc_delayed_write(time, rtc, RTC_TIME);
spin_unlock_irqrestore(&rtc->lock, flags);
out:
return ret;
}
static int armada38x_rtc_read_alarm(struct device *dev, struct rtc_wkalrm *alrm)
{
struct armada38x_rtc *rtc = dev_get_drvdata(dev);
unsigned long time, flags;
u32 val;
spin_lock_irqsave(&rtc->lock, flags);
time = readl(rtc->regs + RTC_ALARM1);
val = readl(rtc->regs + RTC_IRQ1_CONF) & RTC_IRQ1_AL_EN;
spin_unlock_irqrestore(&rtc->lock, flags);
alrm->enabled = val ? 1 : 0;
rtc_time_to_tm(time, &alrm->time);
return 0;
}
static int armada38x_rtc_set_alarm(struct device *dev, struct rtc_wkalrm *alrm)
{
struct armada38x_rtc *rtc = dev_get_drvdata(dev);
unsigned long time, flags;
int ret = 0;
u32 val;
ret = rtc_tm_to_time(&alrm->time, &time);
if (ret)
goto out;
spin_lock_irqsave(&rtc->lock, flags);
rtc_delayed_write(time, rtc, RTC_ALARM1);
if (alrm->enabled) {
rtc_delayed_write(RTC_IRQ1_AL_EN, rtc, RTC_IRQ1_CONF);
val = readl(rtc->regs_soc + SOC_RTC_INTERRUPT);
writel(val | SOC_RTC_ALARM1_MASK,
rtc->regs_soc + SOC_RTC_INTERRUPT);
}
spin_unlock_irqrestore(&rtc->lock, flags);
out:
return ret;
}
static int armada38x_rtc_alarm_irq_enable(struct device *dev,
unsigned int enabled)
{
struct armada38x_rtc *rtc = dev_get_drvdata(dev);
unsigned long flags;
spin_lock_irqsave(&rtc->lock, flags);
if (enabled)
rtc_delayed_write(RTC_IRQ1_AL_EN, rtc, RTC_IRQ1_CONF);
else
rtc_delayed_write(0, rtc, RTC_IRQ1_CONF);
spin_unlock_irqrestore(&rtc->lock, flags);
return 0;
}
static irqreturn_t armada38x_rtc_alarm_irq(int irq, void *data)
{
struct armada38x_rtc *rtc = data;
u32 val;
int event = RTC_IRQF | RTC_AF;
dev_dbg(&rtc->rtc_dev->dev, "%s:irq(%d)\n", __func__, irq);
spin_lock(&rtc->lock);
val = readl(rtc->regs_soc + SOC_RTC_INTERRUPT);
writel(val & ~SOC_RTC_ALARM1, rtc->regs_soc + SOC_RTC_INTERRUPT);
val = readl(rtc->regs + RTC_IRQ1_CONF);
rtc_delayed_write(0, rtc, RTC_IRQ1_CONF);
rtc_delayed_write(RTC_STATUS_ALARM1, rtc, RTC_STATUS);
spin_unlock(&rtc->lock);
if (val & RTC_IRQ1_FREQ_EN) {
if (val & RTC_IRQ1_FREQ_1HZ)
event |= RTC_UF;
else
event |= RTC_PF;
}
rtc_update_irq(rtc->rtc_dev, 1, event);
return IRQ_HANDLED;
}
static __init int armada38x_rtc_probe(struct platform_device *pdev)
{
struct resource *res;
struct armada38x_rtc *rtc;
int ret;
rtc = devm_kzalloc(&pdev->dev, sizeof(struct armada38x_rtc),
GFP_KERNEL);
if (!rtc)
return -ENOMEM;
spin_lock_init(&rtc->lock);
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "rtc");
rtc->regs = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(rtc->regs))
return PTR_ERR(rtc->regs);
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "rtc-soc");
rtc->regs_soc = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(rtc->regs_soc))
return PTR_ERR(rtc->regs_soc);
rtc->irq = platform_get_irq(pdev, 0);
if (rtc->irq < 0) {
dev_err(&pdev->dev, "no irq\n");
return rtc->irq;
}
if (devm_request_irq(&pdev->dev, rtc->irq, armada38x_rtc_alarm_irq,
0, pdev->name, rtc) < 0) {
dev_warn(&pdev->dev, "Interrupt not available.\n");
rtc->irq = -1;
armada38x_rtc_ops.set_alarm = NULL;
armada38x_rtc_ops.alarm_irq_enable = NULL;
}
platform_set_drvdata(pdev, rtc);
if (rtc->irq != -1)
device_init_wakeup(&pdev->dev, 1);
rtc->rtc_dev = devm_rtc_device_register(&pdev->dev, pdev->name,
&armada38x_rtc_ops, THIS_MODULE);
if (IS_ERR(rtc->rtc_dev)) {
ret = PTR_ERR(rtc->rtc_dev);
dev_err(&pdev->dev, "Failed to register RTC device: %d\n", ret);
return ret;
}
return 0;
}
static int armada38x_rtc_suspend(struct device *dev)
{
if (device_may_wakeup(dev)) {
struct armada38x_rtc *rtc = dev_get_drvdata(dev);
return enable_irq_wake(rtc->irq);
}
return 0;
}
static int armada38x_rtc_resume(struct device *dev)
{
if (device_may_wakeup(dev)) {
struct armada38x_rtc *rtc = dev_get_drvdata(dev);
return disable_irq_wake(rtc->irq);
}
return 0;
}
