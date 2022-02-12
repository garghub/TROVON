static irqreturn_t sa1100_rtc_interrupt(int irq, void *dev_id)
{
struct sa1100_rtc *info = dev_get_drvdata(dev_id);
struct rtc_device *rtc = info->rtc;
unsigned int rtsr;
unsigned long events = 0;
spin_lock(&info->lock);
rtsr = readl_relaxed(info->rtsr);
writel_relaxed(0, info->rtsr);
if (rtsr & (RTSR_ALE | RTSR_HZE)) {
writel_relaxed((RTSR_AL | RTSR_HZ) & (rtsr >> 2), info->rtsr);
} else {
writel_relaxed(RTSR_AL | RTSR_HZ, info->rtsr);
}
if (rtsr & RTSR_AL)
rtsr &= ~RTSR_ALE;
writel_relaxed(rtsr & (RTSR_ALE | RTSR_HZE), info->rtsr);
if (rtsr & RTSR_AL)
events |= RTC_AF | RTC_IRQF;
if (rtsr & RTSR_HZ)
events |= RTC_UF | RTC_IRQF;
rtc_update_irq(rtc, 1, events);
spin_unlock(&info->lock);
return IRQ_HANDLED;
}
static int sa1100_rtc_open(struct device *dev)
{
struct sa1100_rtc *info = dev_get_drvdata(dev);
struct rtc_device *rtc = info->rtc;
int ret;
ret = request_irq(info->irq_1hz, sa1100_rtc_interrupt, 0, "rtc 1Hz", dev);
if (ret) {
dev_err(dev, "IRQ %d already in use.\n", info->irq_1hz);
goto fail_ui;
}
ret = request_irq(info->irq_alarm, sa1100_rtc_interrupt, 0, "rtc Alrm", dev);
if (ret) {
dev_err(dev, "IRQ %d already in use.\n", info->irq_alarm);
goto fail_ai;
}
rtc->max_user_freq = RTC_FREQ;
rtc_irq_set_freq(rtc, NULL, RTC_FREQ);
return 0;
fail_ai:
free_irq(info->irq_1hz, dev);
fail_ui:
clk_disable_unprepare(info->clk);
return ret;
}
static void sa1100_rtc_release(struct device *dev)
{
struct sa1100_rtc *info = dev_get_drvdata(dev);
spin_lock_irq(&info->lock);
writel_relaxed(0, info->rtsr);
spin_unlock_irq(&info->lock);
free_irq(info->irq_alarm, dev);
free_irq(info->irq_1hz, dev);
}
static int sa1100_rtc_alarm_irq_enable(struct device *dev, unsigned int enabled)
{
u32 rtsr;
struct sa1100_rtc *info = dev_get_drvdata(dev);
spin_lock_irq(&info->lock);
rtsr = readl_relaxed(info->rtsr);
if (enabled)
rtsr |= RTSR_ALE;
else
rtsr &= ~RTSR_ALE;
writel_relaxed(rtsr, info->rtsr);
spin_unlock_irq(&info->lock);
return 0;
}
static int sa1100_rtc_read_time(struct device *dev, struct rtc_time *tm)
{
struct sa1100_rtc *info = dev_get_drvdata(dev);
rtc_time_to_tm(readl_relaxed(info->rcnr), tm);
return 0;
}
static int sa1100_rtc_set_time(struct device *dev, struct rtc_time *tm)
{
struct sa1100_rtc *info = dev_get_drvdata(dev);
unsigned long time;
int ret;
ret = rtc_tm_to_time(tm, &time);
if (ret == 0)
writel_relaxed(time, info->rcnr);
return ret;
}
static int sa1100_rtc_read_alarm(struct device *dev, struct rtc_wkalrm *alrm)
{
u32 rtsr;
struct sa1100_rtc *info = dev_get_drvdata(dev);
rtsr = readl_relaxed(info->rtsr);
alrm->enabled = (rtsr & RTSR_ALE) ? 1 : 0;
alrm->pending = (rtsr & RTSR_AL) ? 1 : 0;
return 0;
}
static int sa1100_rtc_set_alarm(struct device *dev, struct rtc_wkalrm *alrm)
{
struct sa1100_rtc *info = dev_get_drvdata(dev);
unsigned long time;
int ret;
spin_lock_irq(&info->lock);
ret = rtc_tm_to_time(&alrm->time, &time);
if (ret != 0)
goto out;
writel_relaxed(readl_relaxed(info->rtsr) &
(RTSR_HZE | RTSR_ALE | RTSR_AL), info->rtsr);
writel_relaxed(time, info->rtar);
if (alrm->enabled)
writel_relaxed(readl_relaxed(info->rtsr) | RTSR_ALE, info->rtsr);
else
writel_relaxed(readl_relaxed(info->rtsr) & ~RTSR_ALE, info->rtsr);
out:
spin_unlock_irq(&info->lock);
return ret;
}
static int sa1100_rtc_proc(struct device *dev, struct seq_file *seq)
{
struct sa1100_rtc *info = dev_get_drvdata(dev);
seq_printf(seq, "trim/divider\t\t: 0x%08x\n", readl_relaxed(info->rttr));
seq_printf(seq, "RTSR\t\t\t: 0x%08x\n", readl_relaxed(info->rtsr));
return 0;
}
int sa1100_rtc_init(struct platform_device *pdev, struct sa1100_rtc *info)
{
struct rtc_device *rtc;
int ret;
spin_lock_init(&info->lock);
info->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(info->clk)) {
dev_err(&pdev->dev, "failed to find rtc clock source\n");
return PTR_ERR(info->clk);
}
ret = clk_prepare_enable(info->clk);
if (ret)
return ret;
if (readl_relaxed(info->rttr) == 0) {
writel_relaxed(RTC_DEF_DIVIDER + (RTC_DEF_TRIM << 16), info->rttr);
dev_warn(&pdev->dev, "warning: "
"initializing default clock divider/trim value\n");
writel_relaxed(0, info->rcnr);
}
rtc = devm_rtc_device_register(&pdev->dev, pdev->name, &sa1100_rtc_ops,
THIS_MODULE);
if (IS_ERR(rtc)) {
clk_disable_unprepare(info->clk);
return PTR_ERR(rtc);
}
info->rtc = rtc;
writel_relaxed(RTSR_AL | RTSR_HZ, info->rtsr);
return 0;
}
static int sa1100_rtc_probe(struct platform_device *pdev)
{
struct sa1100_rtc *info;
struct resource *iores;
void __iomem *base;
int irq_1hz, irq_alarm;
irq_1hz = platform_get_irq_byname(pdev, "rtc 1Hz");
irq_alarm = platform_get_irq_byname(pdev, "rtc alarm");
if (irq_1hz < 0 || irq_alarm < 0)
return -ENODEV;
info = devm_kzalloc(&pdev->dev, sizeof(struct sa1100_rtc), GFP_KERNEL);
if (!info)
return -ENOMEM;
info->irq_1hz = irq_1hz;
info->irq_alarm = irq_alarm;
iores = platform_get_resource(pdev, IORESOURCE_MEM, 0);
base = devm_ioremap_resource(&pdev->dev, iores);
if (IS_ERR(base))
return PTR_ERR(base);
if (IS_ENABLED(CONFIG_ARCH_SA1100) ||
of_device_is_compatible(pdev->dev.of_node, "mrvl,sa1100-rtc")) {
info->rcnr = base + 0x04;
info->rtsr = base + 0x10;
info->rtar = base + 0x00;
info->rttr = base + 0x08;
} else {
info->rcnr = base + 0x0;
info->rtsr = base + 0x8;
info->rtar = base + 0x4;
info->rttr = base + 0xc;
}
platform_set_drvdata(pdev, info);
device_init_wakeup(&pdev->dev, 1);
return sa1100_rtc_init(pdev, info);
}
static int sa1100_rtc_remove(struct platform_device *pdev)
{
struct sa1100_rtc *info = platform_get_drvdata(pdev);
if (info)
clk_disable_unprepare(info->clk);
return 0;
}
static int sa1100_rtc_suspend(struct device *dev)
{
struct sa1100_rtc *info = dev_get_drvdata(dev);
if (device_may_wakeup(dev))
enable_irq_wake(info->irq_alarm);
return 0;
}
static int sa1100_rtc_resume(struct device *dev)
{
struct sa1100_rtc *info = dev_get_drvdata(dev);
if (device_may_wakeup(dev))
disable_irq_wake(info->irq_alarm);
return 0;
}
