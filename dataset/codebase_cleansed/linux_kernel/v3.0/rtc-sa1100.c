static inline int rtc_periodic_alarm(struct rtc_time *tm)
{
return (tm->tm_year == -1) ||
((unsigned)tm->tm_mon >= 12) ||
((unsigned)(tm->tm_mday - 1) >= 31) ||
((unsigned)tm->tm_hour > 23) ||
((unsigned)tm->tm_min > 59) ||
((unsigned)tm->tm_sec > 59);
}
static void rtc_next_alarm_time(struct rtc_time *next, struct rtc_time *now,
struct rtc_time *alrm)
{
unsigned long next_time;
unsigned long now_time;
next->tm_year = now->tm_year;
next->tm_mon = now->tm_mon;
next->tm_mday = now->tm_mday;
next->tm_hour = alrm->tm_hour;
next->tm_min = alrm->tm_min;
next->tm_sec = alrm->tm_sec;
rtc_tm_to_time(now, &now_time);
rtc_tm_to_time(next, &next_time);
if (next_time < now_time) {
next_time += 60 * 60 * 24;
rtc_time_to_tm(next_time, next);
}
}
static int rtc_update_alarm(struct rtc_time *alrm)
{
struct rtc_time alarm_tm, now_tm;
unsigned long now, time;
int ret;
do {
now = RCNR;
rtc_time_to_tm(now, &now_tm);
rtc_next_alarm_time(&alarm_tm, &now_tm, alrm);
ret = rtc_tm_to_time(&alarm_tm, &time);
if (ret != 0)
break;
RTSR = RTSR & (RTSR_HZE|RTSR_ALE|RTSR_AL);
RTAR = time;
} while (now != RCNR);
return ret;
}
static irqreturn_t sa1100_rtc_interrupt(int irq, void *dev_id)
{
struct platform_device *pdev = to_platform_device(dev_id);
struct rtc_device *rtc = platform_get_drvdata(pdev);
unsigned int rtsr;
unsigned long events = 0;
spin_lock(&sa1100_rtc_lock);
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
if (rtsr & RTSR_AL && rtc_periodic_alarm(&rtc_alarm))
rtc_update_alarm(&rtc_alarm);
spin_unlock(&sa1100_rtc_lock);
return IRQ_HANDLED;
}
static int sa1100_rtc_open(struct device *dev)
{
int ret;
struct platform_device *plat_dev = to_platform_device(dev);
struct rtc_device *rtc = platform_get_drvdata(plat_dev);
ret = request_irq(IRQ_RTC1Hz, sa1100_rtc_interrupt, IRQF_DISABLED,
"rtc 1Hz", dev);
if (ret) {
dev_err(dev, "IRQ %d already in use.\n", IRQ_RTC1Hz);
goto fail_ui;
}
ret = request_irq(IRQ_RTCAlrm, sa1100_rtc_interrupt, IRQF_DISABLED,
"rtc Alrm", dev);
if (ret) {
dev_err(dev, "IRQ %d already in use.\n", IRQ_RTCAlrm);
goto fail_ai;
}
rtc->max_user_freq = RTC_FREQ;
rtc_irq_set_freq(rtc, NULL, RTC_FREQ);
return 0;
fail_ai:
free_irq(IRQ_RTC1Hz, dev);
fail_ui:
return ret;
}
static void sa1100_rtc_release(struct device *dev)
{
spin_lock_irq(&sa1100_rtc_lock);
RTSR = 0;
OIER &= ~OIER_E1;
OSSR = OSSR_M1;
spin_unlock_irq(&sa1100_rtc_lock);
free_irq(IRQ_RTCAlrm, dev);
free_irq(IRQ_RTC1Hz, dev);
}
static int sa1100_rtc_alarm_irq_enable(struct device *dev, unsigned int enabled)
{
spin_lock_irq(&sa1100_rtc_lock);
if (enabled)
RTSR |= RTSR_ALE;
else
RTSR &= ~RTSR_ALE;
spin_unlock_irq(&sa1100_rtc_lock);
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
memcpy(&alrm->time, &rtc_alarm, sizeof(struct rtc_time));
rtsr = RTSR;
alrm->enabled = (rtsr & RTSR_ALE) ? 1 : 0;
alrm->pending = (rtsr & RTSR_AL) ? 1 : 0;
return 0;
}
static int sa1100_rtc_set_alarm(struct device *dev, struct rtc_wkalrm *alrm)
{
int ret;
spin_lock_irq(&sa1100_rtc_lock);
ret = rtc_update_alarm(&alrm->time);
if (ret == 0) {
if (alrm->enabled)
RTSR |= RTSR_ALE;
else
RTSR &= ~RTSR_ALE;
}
spin_unlock_irq(&sa1100_rtc_lock);
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
if (RTTR == 0) {
RTTR = RTC_DEF_DIVIDER + (RTC_DEF_TRIM << 16);
dev_warn(&pdev->dev, "warning: "
"initializing default clock divider/trim value\n");
RCNR = 0;
}
device_init_wakeup(&pdev->dev, 1);
rtc = rtc_device_register(pdev->name, &pdev->dev, &sa1100_rtc_ops,
THIS_MODULE);
if (IS_ERR(rtc))
return PTR_ERR(rtc);
platform_set_drvdata(pdev, rtc);
RTSR = RTSR_AL | RTSR_HZ;
return 0;
}
static int sa1100_rtc_remove(struct platform_device *pdev)
{
struct rtc_device *rtc = platform_get_drvdata(pdev);
if (rtc)
rtc_device_unregister(rtc);
return 0;
}
static int sa1100_rtc_suspend(struct device *dev)
{
if (device_may_wakeup(dev))
enable_irq_wake(IRQ_RTCAlrm);
return 0;
}
static int sa1100_rtc_resume(struct device *dev)
{
if (device_may_wakeup(dev))
disable_irq_wake(IRQ_RTCAlrm);
return 0;
}
static int __init sa1100_rtc_init(void)
{
return platform_driver_register(&sa1100_rtc_driver);
}
static void __exit sa1100_rtc_exit(void)
{
platform_driver_unregister(&sa1100_rtc_driver);
}
