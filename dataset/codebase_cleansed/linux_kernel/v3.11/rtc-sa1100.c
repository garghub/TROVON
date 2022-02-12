static irqreturn_t sa1100_rtc_interrupt(int irq, void *dev_id)
{
struct sa1100_rtc *info = dev_get_drvdata(dev_id);
struct rtc_device *rtc = info->rtc;
unsigned int rtsr;
unsigned long events = 0;
spin_lock(&info->lock);
rtsr = RTSR;
RTSR = 0;
if (rtsr & (RTSR_ALE | RTSR_HZE)) {
RTSR = (RTSR_AL | RTSR_HZ) & (rtsr >> 2);
} else {
RTSR = RTSR_AL | RTSR_HZ;
}
if (rtsr & RTSR_AL)
rtsr &= ~RTSR_ALE;
RTSR = rtsr & (RTSR_ALE | RTSR_HZE);
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
RTSR = 0;
spin_unlock_irq(&info->lock);
free_irq(info->irq_alarm, dev);
free_irq(info->irq_1hz, dev);
}
static int sa1100_rtc_alarm_irq_enable(struct device *dev, unsigned int enabled)
{
struct sa1100_rtc *info = dev_get_drvdata(dev);
spin_lock_irq(&info->lock);
if (enabled)
RTSR |= RTSR_ALE;
else
RTSR &= ~RTSR_ALE;
spin_unlock_irq(&info->lock);
return 0;
}
static int sa1100_rtc_read_time(struct device *dev, struct rtc_time *tm)
{
rtc_time_to_tm(RCNR, tm);
return 0;
}
static int sa1100_rtc_set_time(struct device *dev, struct rtc_time *tm)
{
unsigned long time;
int ret;
ret = rtc_tm_to_time(tm, &time);
if (ret == 0)
RCNR = time;
return ret;
}
static int sa1100_rtc_read_alarm(struct device *dev, struct rtc_wkalrm *alrm)
{
u32 rtsr;
rtsr = RTSR;
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
RTSR = RTSR & (RTSR_HZE|RTSR_ALE|RTSR_AL);
RTAR = time;
if (alrm->enabled)
RTSR |= RTSR_ALE;
else
RTSR &= ~RTSR_ALE;
out:
spin_unlock_irq(&info->lock);
return ret;
}
static int sa1100_rtc_proc(struct device *dev, struct seq_file *seq)
{
seq_printf(seq, "trim/divider\t\t: 0x%08x\n", (u32) RTTR);
seq_printf(seq, "RTSR\t\t\t: 0x%08x\n", (u32)RTSR);
return 0;
}
static int sa1100_rtc_probe(struct platform_device *pdev)
{
struct rtc_device *rtc;
struct sa1100_rtc *info;
int irq_1hz, irq_alarm, ret = 0;
irq_1hz = platform_get_irq_byname(pdev, "rtc 1Hz");
irq_alarm = platform_get_irq_byname(pdev, "rtc alarm");
if (irq_1hz < 0 || irq_alarm < 0)
return -ENODEV;
info = devm_kzalloc(&pdev->dev, sizeof(struct sa1100_rtc), GFP_KERNEL);
if (!info)
return -ENOMEM;
info->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(info->clk)) {
dev_err(&pdev->dev, "failed to find rtc clock source\n");
return PTR_ERR(info->clk);
}
info->irq_1hz = irq_1hz;
info->irq_alarm = irq_alarm;
spin_lock_init(&info->lock);
platform_set_drvdata(pdev, info);
ret = clk_prepare_enable(info->clk);
if (ret)
return ret;
if (RTTR == 0) {
RTTR = RTC_DEF_DIVIDER + (RTC_DEF_TRIM << 16);
dev_warn(&pdev->dev, "warning: "
"initializing default clock divider/trim value\n");
RCNR = 0;
}
device_init_wakeup(&pdev->dev, 1);
rtc = devm_rtc_device_register(&pdev->dev, pdev->name, &sa1100_rtc_ops,
THIS_MODULE);
if (IS_ERR(rtc)) {
ret = PTR_ERR(rtc);
goto err_dev;
}
info->rtc = rtc;
RTSR = RTSR_AL | RTSR_HZ;
return 0;
err_dev:
clk_disable_unprepare(info->clk);
return ret;
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
