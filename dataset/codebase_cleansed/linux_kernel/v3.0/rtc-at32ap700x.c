static int at32_rtc_readtime(struct device *dev, struct rtc_time *tm)
{
struct rtc_at32ap700x *rtc = dev_get_drvdata(dev);
unsigned long now;
now = rtc_readl(rtc, VAL);
rtc_time_to_tm(now, tm);
return 0;
}
static int at32_rtc_settime(struct device *dev, struct rtc_time *tm)
{
struct rtc_at32ap700x *rtc = dev_get_drvdata(dev);
unsigned long now;
int ret;
ret = rtc_tm_to_time(tm, &now);
if (ret == 0)
rtc_writel(rtc, VAL, now);
return ret;
}
static int at32_rtc_readalarm(struct device *dev, struct rtc_wkalrm *alrm)
{
struct rtc_at32ap700x *rtc = dev_get_drvdata(dev);
spin_lock_irq(&rtc->lock);
rtc_time_to_tm(rtc->alarm_time, &alrm->time);
alrm->enabled = rtc_readl(rtc, IMR) & RTC_BIT(IMR_TOPI) ? 1 : 0;
alrm->pending = rtc_readl(rtc, ISR) & RTC_BIT(ISR_TOPI) ? 1 : 0;
spin_unlock_irq(&rtc->lock);
return 0;
}
static int at32_rtc_setalarm(struct device *dev, struct rtc_wkalrm *alrm)
{
struct rtc_at32ap700x *rtc = dev_get_drvdata(dev);
unsigned long rtc_unix_time;
unsigned long alarm_unix_time;
int ret;
rtc_unix_time = rtc_readl(rtc, VAL);
ret = rtc_tm_to_time(&alrm->time, &alarm_unix_time);
if (ret)
return ret;
if (alarm_unix_time < rtc_unix_time)
return -EINVAL;
spin_lock_irq(&rtc->lock);
rtc->alarm_time = alarm_unix_time;
rtc_writel(rtc, TOP, rtc->alarm_time);
if (alrm->enabled)
rtc_writel(rtc, CTRL, rtc_readl(rtc, CTRL)
| RTC_BIT(CTRL_TOPEN));
else
rtc_writel(rtc, CTRL, rtc_readl(rtc, CTRL)
& ~RTC_BIT(CTRL_TOPEN));
spin_unlock_irq(&rtc->lock);
return ret;
}
static int at32_rtc_alarm_irq_enable(struct device *dev, unsigned int enabled)
{
struct rtc_at32ap700x *rtc = dev_get_drvdata(dev);
int ret = 0;
spin_lock_irq(&rtc->lock);
if(enabled) {
if (rtc_readl(rtc, VAL) > rtc->alarm_time) {
ret = -EINVAL;
goto out;
}
rtc_writel(rtc, CTRL, rtc_readl(rtc, CTRL)
| RTC_BIT(CTRL_TOPEN));
rtc_writel(rtc, ICR, RTC_BIT(ICR_TOPI));
rtc_writel(rtc, IER, RTC_BIT(IER_TOPI));
} else {
rtc_writel(rtc, CTRL, rtc_readl(rtc, CTRL)
& ~RTC_BIT(CTRL_TOPEN));
rtc_writel(rtc, IDR, RTC_BIT(IDR_TOPI));
rtc_writel(rtc, ICR, RTC_BIT(ICR_TOPI));
}
out:
spin_unlock_irq(&rtc->lock);
return ret;
}
static irqreturn_t at32_rtc_interrupt(int irq, void *dev_id)
{
struct rtc_at32ap700x *rtc = (struct rtc_at32ap700x *)dev_id;
unsigned long isr = rtc_readl(rtc, ISR);
unsigned long events = 0;
int ret = IRQ_NONE;
spin_lock(&rtc->lock);
if (isr & RTC_BIT(ISR_TOPI)) {
rtc_writel(rtc, ICR, RTC_BIT(ICR_TOPI));
rtc_writel(rtc, IDR, RTC_BIT(IDR_TOPI));
rtc_writel(rtc, CTRL, rtc_readl(rtc, CTRL)
& ~RTC_BIT(CTRL_TOPEN));
rtc_writel(rtc, VAL, rtc->alarm_time);
events = RTC_AF | RTC_IRQF;
rtc_update_irq(rtc->rtc, 1, events);
ret = IRQ_HANDLED;
}
spin_unlock(&rtc->lock);
return ret;
}
static int __init at32_rtc_probe(struct platform_device *pdev)
{
struct resource *regs;
struct rtc_at32ap700x *rtc;
int irq;
int ret;
rtc = kzalloc(sizeof(struct rtc_at32ap700x), GFP_KERNEL);
if (!rtc) {
dev_dbg(&pdev->dev, "out of memory\n");
return -ENOMEM;
}
regs = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!regs) {
dev_dbg(&pdev->dev, "no mmio resource defined\n");
ret = -ENXIO;
goto out;
}
irq = platform_get_irq(pdev, 0);
if (irq <= 0) {
dev_dbg(&pdev->dev, "could not get irq\n");
ret = -ENXIO;
goto out;
}
rtc->irq = irq;
rtc->regs = ioremap(regs->start, regs->end - regs->start + 1);
if (!rtc->regs) {
ret = -ENOMEM;
dev_dbg(&pdev->dev, "could not map I/O memory\n");
goto out;
}
spin_lock_init(&rtc->lock);
if (!(rtc_readl(rtc, CTRL) & RTC_BIT(CTRL_EN))) {
rtc_writel(rtc, CTRL, RTC_BIT(CTRL_PCLR));
rtc_writel(rtc, IDR, RTC_BIT(IDR_TOPI));
rtc_writel(rtc, CTRL, RTC_BF(CTRL_PSEL, 0xe)
| RTC_BIT(CTRL_EN));
}
ret = request_irq(irq, at32_rtc_interrupt, IRQF_SHARED, "rtc", rtc);
if (ret) {
dev_dbg(&pdev->dev, "could not request irq %d\n", irq);
goto out_iounmap;
}
platform_set_drvdata(pdev, rtc);
rtc->rtc = rtc_device_register(pdev->name, &pdev->dev,
&at32_rtc_ops, THIS_MODULE);
if (IS_ERR(rtc->rtc)) {
dev_dbg(&pdev->dev, "could not register rtc device\n");
ret = PTR_ERR(rtc->rtc);
goto out_free_irq;
}
device_init_wakeup(&pdev->dev, 1);
dev_info(&pdev->dev, "Atmel RTC for AT32AP700x at %08lx irq %ld\n",
(unsigned long)rtc->regs, rtc->irq);
return 0;
out_free_irq:
platform_set_drvdata(pdev, NULL);
free_irq(irq, rtc);
out_iounmap:
iounmap(rtc->regs);
out:
kfree(rtc);
return ret;
}
static int __exit at32_rtc_remove(struct platform_device *pdev)
{
struct rtc_at32ap700x *rtc = platform_get_drvdata(pdev);
device_init_wakeup(&pdev->dev, 0);
free_irq(rtc->irq, rtc);
iounmap(rtc->regs);
rtc_device_unregister(rtc->rtc);
kfree(rtc);
platform_set_drvdata(pdev, NULL);
return 0;
}
static int __init at32_rtc_init(void)
{
return platform_driver_probe(&at32_rtc_driver, at32_rtc_probe);
}
static void __exit at32_rtc_exit(void)
{
platform_driver_unregister(&at32_rtc_driver);
}
