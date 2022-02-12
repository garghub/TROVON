static irqreturn_t coh901331_interrupt(int irq, void *data)
{
struct coh901331_port *rtap = data;
clk_enable(rtap->clk);
writel(1, rtap->virtbase + COH901331_IRQ_EVENT);
writel(0, rtap->virtbase + COH901331_IRQ_MASK);
clk_disable(rtap->clk);
rtc_update_irq(rtap->rtc, 1, RTC_AF);
return IRQ_HANDLED;
}
static int coh901331_read_time(struct device *dev, struct rtc_time *tm)
{
struct coh901331_port *rtap = dev_get_drvdata(dev);
clk_enable(rtap->clk);
if (readl(rtap->virtbase + COH901331_VALID)) {
rtc_time_to_tm(readl(rtap->virtbase + COH901331_CUR_TIME), tm);
clk_disable(rtap->clk);
return rtc_valid_tm(tm);
}
clk_disable(rtap->clk);
return -EINVAL;
}
static int coh901331_set_mmss(struct device *dev, unsigned long secs)
{
struct coh901331_port *rtap = dev_get_drvdata(dev);
clk_enable(rtap->clk);
writel(secs, rtap->virtbase + COH901331_SET_TIME);
clk_disable(rtap->clk);
return 0;
}
static int coh901331_read_alarm(struct device *dev, struct rtc_wkalrm *alarm)
{
struct coh901331_port *rtap = dev_get_drvdata(dev);
clk_enable(rtap->clk);
rtc_time_to_tm(readl(rtap->virtbase + COH901331_ALARM), &alarm->time);
alarm->pending = readl(rtap->virtbase + COH901331_IRQ_EVENT) & 1U;
alarm->enabled = readl(rtap->virtbase + COH901331_IRQ_MASK) & 1U;
clk_disable(rtap->clk);
return 0;
}
static int coh901331_set_alarm(struct device *dev, struct rtc_wkalrm *alarm)
{
struct coh901331_port *rtap = dev_get_drvdata(dev);
unsigned long time;
rtc_tm_to_time(&alarm->time, &time);
clk_enable(rtap->clk);
writel(time, rtap->virtbase + COH901331_ALARM);
writel(alarm->enabled, rtap->virtbase + COH901331_IRQ_MASK);
clk_disable(rtap->clk);
return 0;
}
static int coh901331_alarm_irq_enable(struct device *dev, unsigned int enabled)
{
struct coh901331_port *rtap = dev_get_drvdata(dev);
clk_enable(rtap->clk);
if (enabled)
writel(1, rtap->virtbase + COH901331_IRQ_MASK);
else
writel(0, rtap->virtbase + COH901331_IRQ_MASK);
clk_disable(rtap->clk);
return 0;
}
static int __exit coh901331_remove(struct platform_device *pdev)
{
struct coh901331_port *rtap = dev_get_drvdata(&pdev->dev);
if (rtap) {
rtc_device_unregister(rtap->rtc);
clk_unprepare(rtap->clk);
clk_put(rtap->clk);
platform_set_drvdata(pdev, NULL);
}
return 0;
}
static int __init coh901331_probe(struct platform_device *pdev)
{
int ret;
struct coh901331_port *rtap;
struct resource *res;
rtap = devm_kzalloc(&pdev->dev,
sizeof(struct coh901331_port), GFP_KERNEL);
if (!rtap)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res)
return -ENOENT;
rtap->phybase = res->start;
rtap->physize = resource_size(res);
if (devm_request_mem_region(&pdev->dev, rtap->phybase, rtap->physize,
"rtc-coh901331") == NULL)
return -EBUSY;
rtap->virtbase = devm_ioremap(&pdev->dev, rtap->phybase, rtap->physize);
if (!rtap->virtbase)
return -ENOMEM;
rtap->irq = platform_get_irq(pdev, 0);
if (devm_request_irq(&pdev->dev, rtap->irq, coh901331_interrupt, 0,
"RTC COH 901 331 Alarm", rtap))
return -EIO;
rtap->clk = clk_get(&pdev->dev, NULL);
if (IS_ERR(rtap->clk)) {
ret = PTR_ERR(rtap->clk);
dev_err(&pdev->dev, "could not get clock\n");
return ret;
}
ret = clk_prepare_enable(rtap->clk);
if (ret) {
dev_err(&pdev->dev, "could not enable clock\n");
goto out_no_clk_prepenable;
}
clk_disable(rtap->clk);
platform_set_drvdata(pdev, rtap);
rtap->rtc = rtc_device_register("coh901331", &pdev->dev, &coh901331_ops,
THIS_MODULE);
if (IS_ERR(rtap->rtc)) {
ret = PTR_ERR(rtap->rtc);
goto out_no_rtc;
}
return 0;
out_no_rtc:
platform_set_drvdata(pdev, NULL);
clk_unprepare(rtap->clk);
out_no_clk_prepenable:
clk_put(rtap->clk);
return ret;
}
static int coh901331_suspend(struct platform_device *pdev, pm_message_t state)
{
struct coh901331_port *rtap = dev_get_drvdata(&pdev->dev);
if (device_may_wakeup(&pdev->dev)) {
enable_irq_wake(rtap->irq);
} else {
clk_enable(rtap->clk);
rtap->irqmaskstore = readl(rtap->virtbase + COH901331_IRQ_MASK);
writel(0, rtap->virtbase + COH901331_IRQ_MASK);
clk_disable(rtap->clk);
}
clk_unprepare(rtap->clk);
return 0;
}
static int coh901331_resume(struct platform_device *pdev)
{
struct coh901331_port *rtap = dev_get_drvdata(&pdev->dev);
clk_prepare(rtap->clk);
if (device_may_wakeup(&pdev->dev)) {
disable_irq_wake(rtap->irq);
} else {
clk_enable(rtap->clk);
writel(rtap->irqmaskstore, rtap->virtbase + COH901331_IRQ_MASK);
clk_disable(rtap->clk);
}
return 0;
}
static void coh901331_shutdown(struct platform_device *pdev)
{
struct coh901331_port *rtap = dev_get_drvdata(&pdev->dev);
clk_enable(rtap->clk);
writel(0, rtap->virtbase + COH901331_IRQ_MASK);
clk_disable(rtap->clk);
clk_unprepare(rtap->clk);
}
static int __init coh901331_init(void)
{
return platform_driver_probe(&coh901331_driver, coh901331_probe);
}
static void __exit coh901331_exit(void)
{
platform_driver_unregister(&coh901331_driver);
}
