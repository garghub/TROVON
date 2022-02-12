static void at91_rtc_write_ier(u32 mask)
{
unsigned long flags;
spin_lock_irqsave(&at91_rtc_lock, flags);
at91_rtc_shadow_imr |= mask;
at91_rtc_write(AT91_RTC_IER, mask);
spin_unlock_irqrestore(&at91_rtc_lock, flags);
}
static void at91_rtc_write_idr(u32 mask)
{
unsigned long flags;
spin_lock_irqsave(&at91_rtc_lock, flags);
at91_rtc_write(AT91_RTC_IDR, mask);
at91_rtc_read(AT91_RTC_SR);
at91_rtc_shadow_imr &= ~mask;
spin_unlock_irqrestore(&at91_rtc_lock, flags);
}
static u32 at91_rtc_read_imr(void)
{
unsigned long flags;
u32 mask;
if (at91_rtc_config->use_shadow_imr) {
spin_lock_irqsave(&at91_rtc_lock, flags);
mask = at91_rtc_shadow_imr;
spin_unlock_irqrestore(&at91_rtc_lock, flags);
} else {
mask = at91_rtc_read(AT91_RTC_IMR);
}
return mask;
}
static void at91_rtc_decodetime(unsigned int timereg, unsigned int calreg,
struct rtc_time *tm)
{
unsigned int time, date;
do {
time = at91_rtc_read(timereg);
date = at91_rtc_read(calreg);
} while ((time != at91_rtc_read(timereg)) ||
(date != at91_rtc_read(calreg)));
tm->tm_sec = bcd2bin((time & AT91_RTC_SEC) >> 0);
tm->tm_min = bcd2bin((time & AT91_RTC_MIN) >> 8);
tm->tm_hour = bcd2bin((time & AT91_RTC_HOUR) >> 16);
tm->tm_year = bcd2bin(date & AT91_RTC_CENT) * 100;
tm->tm_year += bcd2bin((date & AT91_RTC_YEAR) >> 8);
tm->tm_wday = bcd2bin((date & AT91_RTC_DAY) >> 21) - 1;
tm->tm_mon = bcd2bin((date & AT91_RTC_MONTH) >> 16) - 1;
tm->tm_mday = bcd2bin((date & AT91_RTC_DATE) >> 24);
}
static int at91_rtc_readtime(struct device *dev, struct rtc_time *tm)
{
at91_rtc_decodetime(AT91_RTC_TIMR, AT91_RTC_CALR, tm);
tm->tm_yday = rtc_year_days(tm->tm_mday, tm->tm_mon, tm->tm_year);
tm->tm_year = tm->tm_year - 1900;
dev_dbg(dev, "%s(): %4d-%02d-%02d %02d:%02d:%02d\n", __func__,
1900 + tm->tm_year, tm->tm_mon, tm->tm_mday,
tm->tm_hour, tm->tm_min, tm->tm_sec);
return 0;
}
static int at91_rtc_settime(struct device *dev, struct rtc_time *tm)
{
unsigned long cr;
dev_dbg(dev, "%s(): %4d-%02d-%02d %02d:%02d:%02d\n", __func__,
1900 + tm->tm_year, tm->tm_mon, tm->tm_mday,
tm->tm_hour, tm->tm_min, tm->tm_sec);
wait_for_completion(&at91_rtc_upd_rdy);
cr = at91_rtc_read(AT91_RTC_CR);
at91_rtc_write(AT91_RTC_CR, cr | AT91_RTC_UPDCAL | AT91_RTC_UPDTIM);
at91_rtc_write_ier(AT91_RTC_ACKUPD);
wait_for_completion(&at91_rtc_updated);
at91_rtc_write_idr(AT91_RTC_ACKUPD);
at91_rtc_write(AT91_RTC_TIMR,
bin2bcd(tm->tm_sec) << 0
| bin2bcd(tm->tm_min) << 8
| bin2bcd(tm->tm_hour) << 16);
at91_rtc_write(AT91_RTC_CALR,
bin2bcd((tm->tm_year + 1900) / 100)
| bin2bcd(tm->tm_year % 100) << 8
| bin2bcd(tm->tm_mon + 1) << 16
| bin2bcd(tm->tm_wday + 1) << 21
| bin2bcd(tm->tm_mday) << 24);
cr = at91_rtc_read(AT91_RTC_CR);
at91_rtc_write(AT91_RTC_SCCR, AT91_RTC_SECEV);
at91_rtc_write(AT91_RTC_CR, cr & ~(AT91_RTC_UPDCAL | AT91_RTC_UPDTIM));
at91_rtc_write_ier(AT91_RTC_SECEV);
return 0;
}
static int at91_rtc_readalarm(struct device *dev, struct rtc_wkalrm *alrm)
{
struct rtc_time *tm = &alrm->time;
at91_rtc_decodetime(AT91_RTC_TIMALR, AT91_RTC_CALALR, tm);
tm->tm_yday = rtc_year_days(tm->tm_mday, tm->tm_mon, tm->tm_year);
tm->tm_year = at91_alarm_year - 1900;
alrm->enabled = (at91_rtc_read_imr() & AT91_RTC_ALARM)
? 1 : 0;
dev_dbg(dev, "%s(): %4d-%02d-%02d %02d:%02d:%02d\n", __func__,
1900 + tm->tm_year, tm->tm_mon, tm->tm_mday,
tm->tm_hour, tm->tm_min, tm->tm_sec);
return 0;
}
static int at91_rtc_setalarm(struct device *dev, struct rtc_wkalrm *alrm)
{
struct rtc_time tm;
at91_rtc_decodetime(AT91_RTC_TIMR, AT91_RTC_CALR, &tm);
at91_alarm_year = tm.tm_year;
tm.tm_mon = alrm->time.tm_mon;
tm.tm_mday = alrm->time.tm_mday;
tm.tm_hour = alrm->time.tm_hour;
tm.tm_min = alrm->time.tm_min;
tm.tm_sec = alrm->time.tm_sec;
at91_rtc_write_idr(AT91_RTC_ALARM);
at91_rtc_write(AT91_RTC_TIMALR,
bin2bcd(tm.tm_sec) << 0
| bin2bcd(tm.tm_min) << 8
| bin2bcd(tm.tm_hour) << 16
| AT91_RTC_HOUREN | AT91_RTC_MINEN | AT91_RTC_SECEN);
at91_rtc_write(AT91_RTC_CALALR,
bin2bcd(tm.tm_mon + 1) << 16
| bin2bcd(tm.tm_mday) << 24
| AT91_RTC_DATEEN | AT91_RTC_MTHEN);
if (alrm->enabled) {
at91_rtc_write(AT91_RTC_SCCR, AT91_RTC_ALARM);
at91_rtc_write_ier(AT91_RTC_ALARM);
}
dev_dbg(dev, "%s(): %4d-%02d-%02d %02d:%02d:%02d\n", __func__,
at91_alarm_year, tm.tm_mon, tm.tm_mday, tm.tm_hour,
tm.tm_min, tm.tm_sec);
return 0;
}
static int at91_rtc_alarm_irq_enable(struct device *dev, unsigned int enabled)
{
dev_dbg(dev, "%s(): cmd=%08x\n", __func__, enabled);
if (enabled) {
at91_rtc_write(AT91_RTC_SCCR, AT91_RTC_ALARM);
at91_rtc_write_ier(AT91_RTC_ALARM);
} else
at91_rtc_write_idr(AT91_RTC_ALARM);
return 0;
}
static int at91_rtc_proc(struct device *dev, struct seq_file *seq)
{
unsigned long imr = at91_rtc_read_imr();
seq_printf(seq, "update_IRQ\t: %s\n",
(imr & AT91_RTC_ACKUPD) ? "yes" : "no");
seq_printf(seq, "periodic_IRQ\t: %s\n",
(imr & AT91_RTC_SECEV) ? "yes" : "no");
return 0;
}
static irqreturn_t at91_rtc_interrupt(int irq, void *dev_id)
{
struct platform_device *pdev = dev_id;
struct rtc_device *rtc = platform_get_drvdata(pdev);
unsigned int rtsr;
unsigned long events = 0;
int ret = IRQ_NONE;
spin_lock(&suspended_lock);
rtsr = at91_rtc_read(AT91_RTC_SR) & at91_rtc_read_imr();
if (rtsr) {
if (rtsr & AT91_RTC_ALARM)
events |= (RTC_AF | RTC_IRQF);
if (rtsr & AT91_RTC_SECEV) {
complete(&at91_rtc_upd_rdy);
at91_rtc_write_idr(AT91_RTC_SECEV);
}
if (rtsr & AT91_RTC_ACKUPD)
complete(&at91_rtc_updated);
at91_rtc_write(AT91_RTC_SCCR, rtsr);
if (!suspended) {
rtc_update_irq(rtc, 1, events);
dev_dbg(&pdev->dev, "%s(): num=%ld, events=0x%02lx\n",
__func__, events >> 8, events & 0x000000FF);
} else {
cached_events |= events;
at91_rtc_write_idr(at91_rtc_imr);
pm_system_wakeup();
}
ret = IRQ_HANDLED;
}
spin_unlock(&suspended_lock);
return ret;
}
static const struct at91_rtc_config *
at91_rtc_get_config(struct platform_device *pdev)
{
const struct of_device_id *match;
if (pdev->dev.of_node) {
match = of_match_node(at91_rtc_dt_ids, pdev->dev.of_node);
if (!match)
return NULL;
return (const struct at91_rtc_config *)match->data;
}
return &at91rm9200_config;
}
static int __init at91_rtc_probe(struct platform_device *pdev)
{
struct rtc_device *rtc;
struct resource *regs;
int ret = 0;
at91_rtc_config = at91_rtc_get_config(pdev);
if (!at91_rtc_config)
return -ENODEV;
regs = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!regs) {
dev_err(&pdev->dev, "no mmio resource defined\n");
return -ENXIO;
}
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_err(&pdev->dev, "no irq resource defined\n");
return -ENXIO;
}
at91_rtc_regs = devm_ioremap(&pdev->dev, regs->start,
resource_size(regs));
if (!at91_rtc_regs) {
dev_err(&pdev->dev, "failed to map registers, aborting.\n");
return -ENOMEM;
}
rtc = devm_rtc_allocate_device(&pdev->dev);
if (IS_ERR(rtc))
return PTR_ERR(rtc);
platform_set_drvdata(pdev, rtc);
sclk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(sclk))
return PTR_ERR(sclk);
ret = clk_prepare_enable(sclk);
if (ret) {
dev_err(&pdev->dev, "Could not enable slow clock\n");
return ret;
}
at91_rtc_write(AT91_RTC_CR, 0);
at91_rtc_write(AT91_RTC_MR, 0);
at91_rtc_write_idr(AT91_RTC_ACKUPD | AT91_RTC_ALARM |
AT91_RTC_SECEV | AT91_RTC_TIMEV |
AT91_RTC_CALEV);
ret = devm_request_irq(&pdev->dev, irq, at91_rtc_interrupt,
IRQF_SHARED | IRQF_COND_SUSPEND,
"at91_rtc", pdev);
if (ret) {
dev_err(&pdev->dev, "IRQ %d already in use.\n", irq);
goto err_clk;
}
if (!device_can_wakeup(&pdev->dev))
device_init_wakeup(&pdev->dev, 1);
rtc->ops = &at91_rtc_ops;
ret = rtc_register_device(rtc);
if (ret)
goto err_clk;
at91_rtc_write_ier(AT91_RTC_SECEV);
dev_info(&pdev->dev, "AT91 Real Time Clock driver.\n");
return 0;
err_clk:
clk_disable_unprepare(sclk);
return ret;
}
static int __exit at91_rtc_remove(struct platform_device *pdev)
{
at91_rtc_write_idr(AT91_RTC_ACKUPD | AT91_RTC_ALARM |
AT91_RTC_SECEV | AT91_RTC_TIMEV |
AT91_RTC_CALEV);
clk_disable_unprepare(sclk);
return 0;
}
static void at91_rtc_shutdown(struct platform_device *pdev)
{
at91_rtc_write(AT91_RTC_IDR, AT91_RTC_ACKUPD | AT91_RTC_ALARM |
AT91_RTC_SECEV | AT91_RTC_TIMEV |
AT91_RTC_CALEV);
}
static int at91_rtc_suspend(struct device *dev)
{
at91_rtc_write(AT91_RTC_SCCR, AT91_RTC_ALARM);
at91_rtc_imr = at91_rtc_read_imr()
& (AT91_RTC_ALARM|AT91_RTC_SECEV);
if (at91_rtc_imr) {
if (device_may_wakeup(dev)) {
unsigned long flags;
enable_irq_wake(irq);
spin_lock_irqsave(&suspended_lock, flags);
suspended = true;
spin_unlock_irqrestore(&suspended_lock, flags);
} else {
at91_rtc_write_idr(at91_rtc_imr);
}
}
return 0;
}
static int at91_rtc_resume(struct device *dev)
{
struct rtc_device *rtc = dev_get_drvdata(dev);
if (at91_rtc_imr) {
if (device_may_wakeup(dev)) {
unsigned long flags;
spin_lock_irqsave(&suspended_lock, flags);
if (cached_events) {
rtc_update_irq(rtc, 1, cached_events);
cached_events = 0;
}
suspended = false;
spin_unlock_irqrestore(&suspended_lock, flags);
disable_irq_wake(irq);
}
at91_rtc_write_ier(at91_rtc_imr);
}
return 0;
}
