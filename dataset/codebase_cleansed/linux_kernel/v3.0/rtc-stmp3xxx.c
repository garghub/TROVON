static void stmp3xxx_wait_time(struct stmp3xxx_rtc_data *rtc_data)
{
while (__raw_readl(rtc_data->io + HW_RTC_STAT) &
BF(0x80, RTC_STAT_STALE_REGS))
cpu_relax();
}
static int stmp3xxx_rtc_gettime(struct device *dev, struct rtc_time *rtc_tm)
{
struct stmp3xxx_rtc_data *rtc_data = dev_get_drvdata(dev);
stmp3xxx_wait_time(rtc_data);
rtc_time_to_tm(__raw_readl(rtc_data->io + HW_RTC_SECONDS), rtc_tm);
return 0;
}
static int stmp3xxx_rtc_set_mmss(struct device *dev, unsigned long t)
{
struct stmp3xxx_rtc_data *rtc_data = dev_get_drvdata(dev);
__raw_writel(t, rtc_data->io + HW_RTC_SECONDS);
stmp3xxx_wait_time(rtc_data);
return 0;
}
static irqreturn_t stmp3xxx_rtc_interrupt(int irq, void *dev_id)
{
struct stmp3xxx_rtc_data *rtc_data = dev_get_drvdata(dev_id);
u32 status;
u32 events = 0;
status = __raw_readl(rtc_data->io + HW_RTC_CTRL) &
(BM_RTC_CTRL_ALARM_IRQ | BM_RTC_CTRL_ONEMSEC_IRQ);
if (status & BM_RTC_CTRL_ALARM_IRQ) {
stmp3xxx_clearl(BM_RTC_CTRL_ALARM_IRQ,
rtc_data->io + HW_RTC_CTRL);
events |= RTC_AF | RTC_IRQF;
}
if (status & BM_RTC_CTRL_ONEMSEC_IRQ) {
stmp3xxx_clearl(BM_RTC_CTRL_ONEMSEC_IRQ,
rtc_data->io + HW_RTC_CTRL);
if (++rtc_data->irq_count % 1000 == 0) {
events |= RTC_UF | RTC_IRQF;
rtc_data->irq_count = 0;
}
}
if (events)
rtc_update_irq(rtc_data->rtc, 1, events);
return IRQ_HANDLED;
}
static int stmp3xxx_alarm_irq_enable(struct device *dev, unsigned int enabled)
{
struct stmp3xxx_rtc_data *rtc_data = dev_get_drvdata(dev);
void __iomem *p = rtc_data->io + HW_RTC_PERSISTENT0,
*ctl = rtc_data->io + HW_RTC_CTRL;
if (enabled) {
stmp3xxx_setl(BM_RTC_PERSISTENT0_ALARM_EN |
BM_RTC_PERSISTENT0_ALARM_WAKE_EN, p);
stmp3xxx_setl(BM_RTC_CTRL_ALARM_IRQ_EN, ctl);
} else {
stmp3xxx_clearl(BM_RTC_PERSISTENT0_ALARM_EN |
BM_RTC_PERSISTENT0_ALARM_WAKE_EN, p);
stmp3xxx_clearl(BM_RTC_CTRL_ALARM_IRQ_EN, ctl);
}
return 0;
}
static int stmp3xxx_rtc_read_alarm(struct device *dev, struct rtc_wkalrm *alm)
{
struct stmp3xxx_rtc_data *rtc_data = dev_get_drvdata(dev);
rtc_time_to_tm(__raw_readl(rtc_data->io + HW_RTC_ALARM), &alm->time);
return 0;
}
static int stmp3xxx_rtc_set_alarm(struct device *dev, struct rtc_wkalrm *alm)
{
unsigned long t;
struct stmp3xxx_rtc_data *rtc_data = dev_get_drvdata(dev);
rtc_tm_to_time(&alm->time, &t);
__raw_writel(t, rtc_data->io + HW_RTC_ALARM);
return 0;
}
static int stmp3xxx_rtc_remove(struct platform_device *pdev)
{
struct stmp3xxx_rtc_data *rtc_data = platform_get_drvdata(pdev);
if (!rtc_data)
return 0;
stmp3xxx_clearl(BM_RTC_CTRL_ONEMSEC_IRQ_EN | BM_RTC_CTRL_ALARM_IRQ_EN,
rtc_data->io + HW_RTC_CTRL);
free_irq(rtc_data->irq_alarm, &pdev->dev);
free_irq(rtc_data->irq_1msec, &pdev->dev);
rtc_device_unregister(rtc_data->rtc);
iounmap(rtc_data->io);
kfree(rtc_data);
return 0;
}
static int stmp3xxx_rtc_probe(struct platform_device *pdev)
{
struct stmp3xxx_rtc_data *rtc_data;
struct resource *r;
int err;
rtc_data = kzalloc(sizeof *rtc_data, GFP_KERNEL);
if (!rtc_data)
return -ENOMEM;
r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!r) {
dev_err(&pdev->dev, "failed to get resource\n");
err = -ENXIO;
goto out_free;
}
rtc_data->io = ioremap(r->start, resource_size(r));
if (!rtc_data->io) {
dev_err(&pdev->dev, "ioremap failed\n");
err = -EIO;
goto out_free;
}
rtc_data->irq_alarm = platform_get_irq(pdev, 0);
rtc_data->irq_1msec = platform_get_irq(pdev, 1);
if (!(__raw_readl(HW_RTC_STAT + rtc_data->io) &
BM_RTC_STAT_RTC_PRESENT)) {
dev_err(&pdev->dev, "no device onboard\n");
err = -ENODEV;
goto out_remap;
}
stmp3xxx_reset_block(rtc_data->io, true);
stmp3xxx_clearl(BM_RTC_PERSISTENT0_ALARM_EN |
BM_RTC_PERSISTENT0_ALARM_WAKE_EN |
BM_RTC_PERSISTENT0_ALARM_WAKE,
rtc_data->io + HW_RTC_PERSISTENT0);
rtc_data->rtc = rtc_device_register(pdev->name, &pdev->dev,
&stmp3xxx_rtc_ops, THIS_MODULE);
if (IS_ERR(rtc_data->rtc)) {
err = PTR_ERR(rtc_data->rtc);
goto out_remap;
}
rtc_data->irq_count = 0;
err = request_irq(rtc_data->irq_alarm, stmp3xxx_rtc_interrupt,
IRQF_DISABLED, "RTC alarm", &pdev->dev);
if (err) {
dev_err(&pdev->dev, "Cannot claim IRQ%d\n",
rtc_data->irq_alarm);
goto out_irq_alarm;
}
err = request_irq(rtc_data->irq_1msec, stmp3xxx_rtc_interrupt,
IRQF_DISABLED, "RTC tick", &pdev->dev);
if (err) {
dev_err(&pdev->dev, "Cannot claim IRQ%d\n",
rtc_data->irq_1msec);
goto out_irq1;
}
platform_set_drvdata(pdev, rtc_data);
return 0;
out_irq1:
free_irq(rtc_data->irq_alarm, &pdev->dev);
out_irq_alarm:
stmp3xxx_clearl(BM_RTC_CTRL_ONEMSEC_IRQ_EN | BM_RTC_CTRL_ALARM_IRQ_EN,
rtc_data->io + HW_RTC_CTRL);
rtc_device_unregister(rtc_data->rtc);
out_remap:
iounmap(rtc_data->io);
out_free:
kfree(rtc_data);
return err;
}
static int stmp3xxx_rtc_suspend(struct platform_device *dev, pm_message_t state)
{
return 0;
}
static int stmp3xxx_rtc_resume(struct platform_device *dev)
{
struct stmp3xxx_rtc_data *rtc_data = platform_get_drvdata(dev);
stmp3xxx_reset_block(rtc_data->io, true);
stmp3xxx_clearl(BM_RTC_PERSISTENT0_ALARM_EN |
BM_RTC_PERSISTENT0_ALARM_WAKE_EN |
BM_RTC_PERSISTENT0_ALARM_WAKE,
rtc_data->io + HW_RTC_PERSISTENT0);
return 0;
}
static int __init stmp3xxx_rtc_init(void)
{
return platform_driver_register(&stmp3xxx_rtcdrv);
}
static void __exit stmp3xxx_rtc_exit(void)
{
platform_driver_unregister(&stmp3xxx_rtcdrv);
}
