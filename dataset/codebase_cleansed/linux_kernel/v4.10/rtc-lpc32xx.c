static int lpc32xx_rtc_read_time(struct device *dev, struct rtc_time *time)
{
unsigned long elapsed_sec;
struct lpc32xx_rtc *rtc = dev_get_drvdata(dev);
elapsed_sec = rtc_readl(rtc, LPC32XX_RTC_UCOUNT);
rtc_time_to_tm(elapsed_sec, time);
return rtc_valid_tm(time);
}
static int lpc32xx_rtc_set_mmss(struct device *dev, unsigned long secs)
{
struct lpc32xx_rtc *rtc = dev_get_drvdata(dev);
u32 tmp;
spin_lock_irq(&rtc->lock);
tmp = rtc_readl(rtc, LPC32XX_RTC_CTRL);
rtc_writel(rtc, LPC32XX_RTC_CTRL, tmp | LPC32XX_RTC_CTRL_CNTR_DIS);
rtc_writel(rtc, LPC32XX_RTC_UCOUNT, secs);
rtc_writel(rtc, LPC32XX_RTC_DCOUNT, 0xFFFFFFFF - secs);
rtc_writel(rtc, LPC32XX_RTC_CTRL, tmp &= ~LPC32XX_RTC_CTRL_CNTR_DIS);
spin_unlock_irq(&rtc->lock);
return 0;
}
static int lpc32xx_rtc_read_alarm(struct device *dev,
struct rtc_wkalrm *wkalrm)
{
struct lpc32xx_rtc *rtc = dev_get_drvdata(dev);
rtc_time_to_tm(rtc_readl(rtc, LPC32XX_RTC_MATCH0), &wkalrm->time);
wkalrm->enabled = rtc->alarm_enabled;
wkalrm->pending = !!(rtc_readl(rtc, LPC32XX_RTC_INTSTAT) &
LPC32XX_RTC_INTSTAT_MATCH0);
return rtc_valid_tm(&wkalrm->time);
}
static int lpc32xx_rtc_set_alarm(struct device *dev,
struct rtc_wkalrm *wkalrm)
{
struct lpc32xx_rtc *rtc = dev_get_drvdata(dev);
unsigned long alarmsecs;
u32 tmp;
int ret;
ret = rtc_tm_to_time(&wkalrm->time, &alarmsecs);
if (ret < 0) {
dev_warn(dev, "Failed to convert time: %d\n", ret);
return ret;
}
spin_lock_irq(&rtc->lock);
tmp = rtc_readl(rtc, LPC32XX_RTC_CTRL);
rtc_writel(rtc, LPC32XX_RTC_CTRL, tmp & ~LPC32XX_RTC_CTRL_MATCH0);
rtc_writel(rtc, LPC32XX_RTC_MATCH0, alarmsecs);
rtc->alarm_enabled = wkalrm->enabled;
if (wkalrm->enabled) {
rtc_writel(rtc, LPC32XX_RTC_INTSTAT,
LPC32XX_RTC_INTSTAT_MATCH0);
rtc_writel(rtc, LPC32XX_RTC_CTRL, tmp |
LPC32XX_RTC_CTRL_MATCH0);
}
spin_unlock_irq(&rtc->lock);
return 0;
}
static int lpc32xx_rtc_alarm_irq_enable(struct device *dev,
unsigned int enabled)
{
struct lpc32xx_rtc *rtc = dev_get_drvdata(dev);
u32 tmp;
spin_lock_irq(&rtc->lock);
tmp = rtc_readl(rtc, LPC32XX_RTC_CTRL);
if (enabled) {
rtc->alarm_enabled = 1;
tmp |= LPC32XX_RTC_CTRL_MATCH0;
} else {
rtc->alarm_enabled = 0;
tmp &= ~LPC32XX_RTC_CTRL_MATCH0;
}
rtc_writel(rtc, LPC32XX_RTC_CTRL, tmp);
spin_unlock_irq(&rtc->lock);
return 0;
}
static irqreturn_t lpc32xx_rtc_alarm_interrupt(int irq, void *dev)
{
struct lpc32xx_rtc *rtc = dev;
spin_lock(&rtc->lock);
rtc_writel(rtc, LPC32XX_RTC_CTRL,
rtc_readl(rtc, LPC32XX_RTC_CTRL) &
~LPC32XX_RTC_CTRL_MATCH0);
rtc->alarm_enabled = 0;
rtc_writel(rtc, LPC32XX_RTC_MATCH0, 0xFFFFFFFF);
rtc_writel(rtc, LPC32XX_RTC_INTSTAT, LPC32XX_RTC_INTSTAT_MATCH0);
spin_unlock(&rtc->lock);
rtc_update_irq(rtc->rtc, 1, RTC_IRQF | RTC_AF);
return IRQ_HANDLED;
}
static int lpc32xx_rtc_probe(struct platform_device *pdev)
{
struct resource *res;
struct lpc32xx_rtc *rtc;
int rtcirq;
u32 tmp;
rtcirq = platform_get_irq(pdev, 0);
if (rtcirq < 0) {
dev_warn(&pdev->dev, "Can't get interrupt resource\n");
rtcirq = -1;
}
rtc = devm_kzalloc(&pdev->dev, sizeof(*rtc), GFP_KERNEL);
if (unlikely(!rtc))
return -ENOMEM;
rtc->irq = rtcirq;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
rtc->rtc_base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(rtc->rtc_base))
return PTR_ERR(rtc->rtc_base);
spin_lock_init(&rtc->lock);
tmp = rtc_readl(rtc, LPC32XX_RTC_CTRL);
if (rtc_readl(rtc, LPC32XX_RTC_KEY) != LPC32XX_RTC_KEY_ONSW_LOADVAL) {
tmp &= ~(LPC32XX_RTC_CTRL_SW_RESET |
LPC32XX_RTC_CTRL_CNTR_DIS |
LPC32XX_RTC_CTRL_MATCH0 |
LPC32XX_RTC_CTRL_MATCH1 |
LPC32XX_RTC_CTRL_ONSW_MATCH0 |
LPC32XX_RTC_CTRL_ONSW_MATCH1 |
LPC32XX_RTC_CTRL_ONSW_FORCE_HI);
rtc_writel(rtc, LPC32XX_RTC_CTRL, tmp);
rtc_writel(rtc, LPC32XX_RTC_MATCH0, 0xFFFFFFFF);
rtc_writel(rtc, LPC32XX_RTC_INTSTAT,
LPC32XX_RTC_INTSTAT_MATCH0 |
LPC32XX_RTC_INTSTAT_MATCH1 |
LPC32XX_RTC_INTSTAT_ONSW);
rtc_writel(rtc, LPC32XX_RTC_KEY,
LPC32XX_RTC_KEY_ONSW_LOADVAL);
} else {
rtc_writel(rtc, LPC32XX_RTC_CTRL,
tmp & ~LPC32XX_RTC_CTRL_MATCH0);
}
platform_set_drvdata(pdev, rtc);
rtc->rtc = devm_rtc_device_register(&pdev->dev, RTC_NAME,
&lpc32xx_rtc_ops, THIS_MODULE);
if (IS_ERR(rtc->rtc)) {
dev_err(&pdev->dev, "Can't get RTC\n");
return PTR_ERR(rtc->rtc);
}
if (rtc->irq >= 0) {
if (devm_request_irq(&pdev->dev, rtc->irq,
lpc32xx_rtc_alarm_interrupt,
0, pdev->name, rtc) < 0) {
dev_warn(&pdev->dev, "Can't request interrupt.\n");
rtc->irq = -1;
} else {
device_init_wakeup(&pdev->dev, 1);
}
}
return 0;
}
static int lpc32xx_rtc_remove(struct platform_device *pdev)
{
struct lpc32xx_rtc *rtc = platform_get_drvdata(pdev);
if (rtc->irq >= 0)
device_init_wakeup(&pdev->dev, 0);
return 0;
}
static int lpc32xx_rtc_suspend(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct lpc32xx_rtc *rtc = platform_get_drvdata(pdev);
if (rtc->irq >= 0) {
if (device_may_wakeup(&pdev->dev))
enable_irq_wake(rtc->irq);
else
disable_irq_wake(rtc->irq);
}
return 0;
}
static int lpc32xx_rtc_resume(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct lpc32xx_rtc *rtc = platform_get_drvdata(pdev);
if (rtc->irq >= 0 && device_may_wakeup(&pdev->dev))
disable_irq_wake(rtc->irq);
return 0;
}
static int lpc32xx_rtc_freeze(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct lpc32xx_rtc *rtc = platform_get_drvdata(pdev);
spin_lock_irq(&rtc->lock);
rtc_writel(rtc, LPC32XX_RTC_CTRL,
rtc_readl(rtc, LPC32XX_RTC_CTRL) &
~LPC32XX_RTC_CTRL_MATCH0);
spin_unlock_irq(&rtc->lock);
return 0;
}
static int lpc32xx_rtc_thaw(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct lpc32xx_rtc *rtc = platform_get_drvdata(pdev);
if (rtc->alarm_enabled) {
spin_lock_irq(&rtc->lock);
rtc_writel(rtc, LPC32XX_RTC_CTRL,
rtc_readl(rtc, LPC32XX_RTC_CTRL) |
LPC32XX_RTC_CTRL_MATCH0);
spin_unlock_irq(&rtc->lock);
}
return 0;
}
