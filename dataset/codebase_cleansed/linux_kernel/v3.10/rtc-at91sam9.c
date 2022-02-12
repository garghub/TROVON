static int at91_rtc_readtime(struct device *dev, struct rtc_time *tm)
{
struct sam9_rtc *rtc = dev_get_drvdata(dev);
u32 secs, secs2;
u32 offset;
offset = gpbr_readl(rtc);
if (offset == 0)
return -EILSEQ;
secs = rtt_readl(rtc, VR);
secs2 = rtt_readl(rtc, VR);
if (secs != secs2)
secs = rtt_readl(rtc, VR);
rtc_time_to_tm(offset + secs, tm);
dev_dbg(dev, "%s: %4d-%02d-%02d %02d:%02d:%02d\n", "readtime",
1900 + tm->tm_year, tm->tm_mon, tm->tm_mday,
tm->tm_hour, tm->tm_min, tm->tm_sec);
return 0;
}
static int at91_rtc_settime(struct device *dev, struct rtc_time *tm)
{
struct sam9_rtc *rtc = dev_get_drvdata(dev);
int err;
u32 offset, alarm, mr;
unsigned long secs;
dev_dbg(dev, "%s: %4d-%02d-%02d %02d:%02d:%02d\n", "settime",
1900 + tm->tm_year, tm->tm_mon, tm->tm_mday,
tm->tm_hour, tm->tm_min, tm->tm_sec);
err = rtc_tm_to_time(tm, &secs);
if (err != 0)
return err;
mr = rtt_readl(rtc, MR);
rtt_writel(rtc, MR, mr & ~(AT91_RTT_ALMIEN | AT91_RTT_RTTINCIEN));
offset = gpbr_readl(rtc);
secs += 1;
gpbr_writel(rtc, secs);
alarm = rtt_readl(rtc, AR);
if (alarm != ALARM_DISABLED) {
if (offset > secs) {
alarm += (offset - secs);
} else if ((alarm + offset) > secs) {
alarm -= (secs - offset);
} else {
alarm = ALARM_DISABLED;
mr &= ~AT91_RTT_ALMIEN;
}
rtt_writel(rtc, AR, alarm);
}
rtt_writel(rtc, MR, mr | AT91_RTT_RTTRST);
return 0;
}
static int at91_rtc_readalarm(struct device *dev, struct rtc_wkalrm *alrm)
{
struct sam9_rtc *rtc = dev_get_drvdata(dev);
struct rtc_time *tm = &alrm->time;
u32 alarm = rtt_readl(rtc, AR);
u32 offset;
offset = gpbr_readl(rtc);
if (offset == 0)
return -EILSEQ;
memset(alrm, 0, sizeof(*alrm));
if (alarm != ALARM_DISABLED && offset != 0) {
rtc_time_to_tm(offset + alarm, tm);
dev_dbg(dev, "%s: %4d-%02d-%02d %02d:%02d:%02d\n", "readalarm",
1900 + tm->tm_year, tm->tm_mon, tm->tm_mday,
tm->tm_hour, tm->tm_min, tm->tm_sec);
if (rtt_readl(rtc, MR) & AT91_RTT_ALMIEN)
alrm->enabled = 1;
}
return 0;
}
static int at91_rtc_setalarm(struct device *dev, struct rtc_wkalrm *alrm)
{
struct sam9_rtc *rtc = dev_get_drvdata(dev);
struct rtc_time *tm = &alrm->time;
unsigned long secs;
u32 offset;
u32 mr;
int err;
err = rtc_tm_to_time(tm, &secs);
if (err != 0)
return err;
offset = gpbr_readl(rtc);
if (offset == 0) {
return -EILSEQ;
}
mr = rtt_readl(rtc, MR);
rtt_writel(rtc, MR, mr & ~AT91_RTT_ALMIEN);
if (secs <= offset) {
rtt_writel(rtc, AR, ALARM_DISABLED);
return 0;
}
rtt_writel(rtc, AR, secs - offset);
if (alrm->enabled)
rtt_writel(rtc, MR, mr | AT91_RTT_ALMIEN);
dev_dbg(dev, "%s: %4d-%02d-%02d %02d:%02d:%02d\n", "setalarm",
tm->tm_year, tm->tm_mon, tm->tm_mday, tm->tm_hour,
tm->tm_min, tm->tm_sec);
return 0;
}
static int at91_rtc_alarm_irq_enable(struct device *dev, unsigned int enabled)
{
struct sam9_rtc *rtc = dev_get_drvdata(dev);
u32 mr = rtt_readl(rtc, MR);
dev_dbg(dev, "alarm_irq_enable: enabled=%08x, mr %08x\n", enabled, mr);
if (enabled)
rtt_writel(rtc, MR, mr | AT91_RTT_ALMIEN);
else
rtt_writel(rtc, MR, mr & ~AT91_RTT_ALMIEN);
return 0;
}
static int at91_rtc_proc(struct device *dev, struct seq_file *seq)
{
struct sam9_rtc *rtc = dev_get_drvdata(dev);
u32 mr = mr = rtt_readl(rtc, MR);
seq_printf(seq, "update_IRQ\t: %s\n",
(mr & AT91_RTT_RTTINCIEN) ? "yes" : "no");
return 0;
}
static irqreturn_t at91_rtc_interrupt(int irq, void *_rtc)
{
struct sam9_rtc *rtc = _rtc;
u32 sr, mr;
unsigned long events = 0;
mr = rtt_readl(rtc, MR) & (AT91_RTT_ALMIEN | AT91_RTT_RTTINCIEN);
sr = rtt_readl(rtc, SR) & (mr >> 16);
if (!sr)
return IRQ_NONE;
if (sr & AT91_RTT_ALMS)
events |= (RTC_AF | RTC_IRQF);
if (sr & AT91_RTT_RTTINC)
events |= (RTC_UF | RTC_IRQF);
rtc_update_irq(rtc->rtcdev, 1, events);
pr_debug("%s: num=%ld, events=0x%02lx\n", __func__,
events >> 8, events & 0x000000FF);
return IRQ_HANDLED;
}
static int at91_rtc_probe(struct platform_device *pdev)
{
struct resource *r, *r_gpbr;
struct sam9_rtc *rtc;
int ret, irq;
u32 mr;
r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
r_gpbr = platform_get_resource(pdev, IORESOURCE_MEM, 1);
if (!r || !r_gpbr) {
dev_err(&pdev->dev, "need 2 ressources\n");
return -ENODEV;
}
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_err(&pdev->dev, "failed to get interrupt resource\n");
return irq;
}
rtc = devm_kzalloc(&pdev->dev, sizeof(*rtc), GFP_KERNEL);
if (!rtc)
return -ENOMEM;
rtc->irq = irq;
if (!device_can_wakeup(&pdev->dev))
device_init_wakeup(&pdev->dev, 1);
platform_set_drvdata(pdev, rtc);
rtc->rtt = devm_ioremap(&pdev->dev, r->start, resource_size(r));
if (!rtc->rtt) {
dev_err(&pdev->dev, "failed to map registers, aborting.\n");
ret = -ENOMEM;
goto fail;
}
rtc->gpbr = devm_ioremap(&pdev->dev, r_gpbr->start,
resource_size(r_gpbr));
if (!rtc->gpbr) {
dev_err(&pdev->dev, "failed to map gpbr registers, aborting.\n");
ret = -ENOMEM;
goto fail;
}
mr = rtt_readl(rtc, MR);
if ((mr & AT91_RTT_RTPRES) != AT91_SLOW_CLOCK) {
mr = AT91_RTT_RTTRST | (AT91_SLOW_CLOCK & AT91_RTT_RTPRES);
gpbr_writel(rtc, 0);
}
mr &= ~(AT91_RTT_ALMIEN | AT91_RTT_RTTINCIEN);
rtt_writel(rtc, MR, mr);
rtc->rtcdev = devm_rtc_device_register(&pdev->dev, pdev->name,
&at91_rtc_ops, THIS_MODULE);
if (IS_ERR(rtc->rtcdev)) {
ret = PTR_ERR(rtc->rtcdev);
goto fail;
}
ret = devm_request_irq(&pdev->dev, rtc->irq, at91_rtc_interrupt,
IRQF_SHARED, dev_name(&rtc->rtcdev->dev), rtc);
if (ret) {
dev_dbg(&pdev->dev, "can't share IRQ %d?\n", rtc->irq);
goto fail;
}
if (gpbr_readl(rtc) == 0)
dev_warn(&pdev->dev, "%s: SET TIME!\n",
dev_name(&rtc->rtcdev->dev));
return 0;
fail:
platform_set_drvdata(pdev, NULL);
return ret;
}
static int at91_rtc_remove(struct platform_device *pdev)
{
struct sam9_rtc *rtc = platform_get_drvdata(pdev);
u32 mr = rtt_readl(rtc, MR);
rtt_writel(rtc, MR, mr & ~(AT91_RTT_ALMIEN | AT91_RTT_RTTINCIEN));
platform_set_drvdata(pdev, NULL);
return 0;
}
static void at91_rtc_shutdown(struct platform_device *pdev)
{
struct sam9_rtc *rtc = platform_get_drvdata(pdev);
u32 mr = rtt_readl(rtc, MR);
rtc->imr = mr & (AT91_RTT_ALMIEN | AT91_RTT_RTTINCIEN);
rtt_writel(rtc, MR, mr & ~rtc->imr);
}
static int at91_rtc_suspend(struct device *dev)
{
struct sam9_rtc *rtc = dev_get_drvdata(dev);
u32 mr = rtt_readl(rtc, MR);
rtc->imr = mr & (AT91_RTT_ALMIEN | AT91_RTT_RTTINCIEN);
if (rtc->imr) {
if (device_may_wakeup(dev) && (mr & AT91_RTT_ALMIEN)) {
enable_irq_wake(rtc->irq);
if (mr & AT91_RTT_RTTINCIEN)
rtt_writel(rtc, MR, mr & ~AT91_RTT_RTTINCIEN);
} else
rtt_writel(rtc, MR, mr & ~rtc->imr);
}
return 0;
}
static int at91_rtc_resume(struct device *dev)
{
struct sam9_rtc *rtc = dev_get_drvdata(dev);
u32 mr;
if (rtc->imr) {
if (device_may_wakeup(dev))
disable_irq_wake(rtc->irq);
mr = rtt_readl(rtc, MR);
rtt_writel(rtc, MR, mr | rtc->imr);
}
return 0;
}
