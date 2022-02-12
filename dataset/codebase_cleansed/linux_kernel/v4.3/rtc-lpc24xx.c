static int lpc24xx_rtc_set_time(struct device *dev, struct rtc_time *tm)
{
struct lpc24xx_rtc *rtc = dev_get_drvdata(dev);
rtc_writel(rtc, LPC24XX_CCR, LPC178X_CCALEN);
rtc_writel(rtc, LPC24XX_SEC, tm->tm_sec);
rtc_writel(rtc, LPC24XX_MIN, tm->tm_min);
rtc_writel(rtc, LPC24XX_HOUR, tm->tm_hour);
rtc_writel(rtc, LPC24XX_DOW, tm->tm_wday);
rtc_writel(rtc, LPC24XX_DOM, tm->tm_mday);
rtc_writel(rtc, LPC24XX_DOY, tm->tm_yday);
rtc_writel(rtc, LPC24XX_MONTH, tm->tm_mon);
rtc_writel(rtc, LPC24XX_YEAR, tm->tm_year);
rtc_writel(rtc, LPC24XX_CCR, LPC24XX_CLKEN | LPC178X_CCALEN);
return 0;
}
static int lpc24xx_rtc_read_time(struct device *dev, struct rtc_time *tm)
{
struct lpc24xx_rtc *rtc = dev_get_drvdata(dev);
u32 ct0, ct1, ct2;
ct0 = rtc_readl(rtc, LPC24XX_CTIME0);
ct1 = rtc_readl(rtc, LPC24XX_CTIME1);
ct2 = rtc_readl(rtc, LPC24XX_CTIME2);
tm->tm_sec = CT0_SECS(ct0);
tm->tm_min = CT0_MINS(ct0);
tm->tm_hour = CT0_HOURS(ct0);
tm->tm_wday = CT0_DOW(ct0);
tm->tm_mon = CT1_MONTH(ct1);
tm->tm_mday = CT1_DOM(ct1);
tm->tm_year = CT1_YEAR(ct1);
tm->tm_yday = CT2_DOY(ct2);
return rtc_valid_tm(tm);
}
static int lpc24xx_rtc_read_alarm(struct device *dev, struct rtc_wkalrm *wkalrm)
{
struct lpc24xx_rtc *rtc = dev_get_drvdata(dev);
struct rtc_time *tm = &wkalrm->time;
tm->tm_sec = rtc_readl(rtc, LPC24XX_ALSEC);
tm->tm_min = rtc_readl(rtc, LPC24XX_ALMIN);
tm->tm_hour = rtc_readl(rtc, LPC24XX_ALHOUR);
tm->tm_mday = rtc_readl(rtc, LPC24XX_ALDOM);
tm->tm_wday = rtc_readl(rtc, LPC24XX_ALDOW);
tm->tm_yday = rtc_readl(rtc, LPC24XX_ALDOY);
tm->tm_mon = rtc_readl(rtc, LPC24XX_ALMON);
tm->tm_year = rtc_readl(rtc, LPC24XX_ALYEAR);
wkalrm->enabled = rtc_readl(rtc, LPC24XX_AMR) == 0;
wkalrm->pending = !!(rtc_readl(rtc, LPC24XX_ILR) & LPC24XX_RTCCIF);
return rtc_valid_tm(&wkalrm->time);
}
static int lpc24xx_rtc_set_alarm(struct device *dev, struct rtc_wkalrm *wkalrm)
{
struct lpc24xx_rtc *rtc = dev_get_drvdata(dev);
struct rtc_time *tm = &wkalrm->time;
rtc_writel(rtc, LPC24XX_AMR, LPC24XX_ALARM_DISABLE);
rtc_writel(rtc, LPC24XX_ALSEC, tm->tm_sec);
rtc_writel(rtc, LPC24XX_ALMIN, tm->tm_min);
rtc_writel(rtc, LPC24XX_ALHOUR, tm->tm_hour);
rtc_writel(rtc, LPC24XX_ALDOM, tm->tm_mday);
rtc_writel(rtc, LPC24XX_ALDOW, tm->tm_wday);
rtc_writel(rtc, LPC24XX_ALDOY, tm->tm_yday);
rtc_writel(rtc, LPC24XX_ALMON, tm->tm_mon);
rtc_writel(rtc, LPC24XX_ALYEAR, tm->tm_year);
if (wkalrm->enabled)
rtc_writel(rtc, LPC24XX_AMR, 0);
return 0;
}
static int lpc24xx_rtc_alarm_irq_enable(struct device *dev, unsigned int enable)
{
struct lpc24xx_rtc *rtc = dev_get_drvdata(dev);
if (enable)
rtc_writel(rtc, LPC24XX_AMR, 0);
else
rtc_writel(rtc, LPC24XX_AMR, LPC24XX_ALARM_DISABLE);
return 0;
}
static irqreturn_t lpc24xx_rtc_interrupt(int irq, void *data)
{
unsigned long events = RTC_IRQF;
struct lpc24xx_rtc *rtc = data;
u32 rtc_iir;
rtc_iir = rtc_readl(rtc, LPC24XX_ILR);
if (rtc_iir & LPC24XX_RTCALF) {
events |= RTC_AF;
rtc_writel(rtc, LPC24XX_AMR, LPC24XX_ALARM_DISABLE);
}
rtc_writel(rtc, LPC24XX_ILR, rtc_iir);
rtc_update_irq(rtc->rtc, 1, events);
return IRQ_HANDLED;
}
static int lpc24xx_rtc_probe(struct platform_device *pdev)
{
struct lpc24xx_rtc *rtc;
struct resource *res;
int irq, ret;
rtc = devm_kzalloc(&pdev->dev, sizeof(*rtc), GFP_KERNEL);
if (!rtc)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
rtc->rtc_base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(rtc->rtc_base))
return PTR_ERR(rtc->rtc_base);
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_warn(&pdev->dev, "can't get interrupt resource\n");
return irq;
}
rtc->clk_rtc = devm_clk_get(&pdev->dev, "rtc");
if (IS_ERR(rtc->clk_rtc)) {
dev_err(&pdev->dev, "error getting rtc clock\n");
return PTR_ERR(rtc->clk_rtc);
}
rtc->clk_reg = devm_clk_get(&pdev->dev, "reg");
if (IS_ERR(rtc->clk_reg)) {
dev_err(&pdev->dev, "error getting reg clock\n");
return PTR_ERR(rtc->clk_reg);
}
ret = clk_prepare_enable(rtc->clk_rtc);
if (ret) {
dev_err(&pdev->dev, "unable to enable rtc clock\n");
return ret;
}
ret = clk_prepare_enable(rtc->clk_reg);
if (ret) {
dev_err(&pdev->dev, "unable to enable reg clock\n");
goto disable_rtc_clk;
}
platform_set_drvdata(pdev, rtc);
rtc_writel(rtc, LPC24XX_ILR, LPC24XX_RTCCIF | LPC24XX_RTCALF);
rtc_writel(rtc, LPC24XX_CCR, LPC24XX_CLKEN | LPC178X_CCALEN);
ret = devm_request_irq(&pdev->dev, irq, lpc24xx_rtc_interrupt, 0,
pdev->name, rtc);
if (ret < 0) {
dev_warn(&pdev->dev, "can't request interrupt\n");
goto disable_clks;
}
rtc->rtc = devm_rtc_device_register(&pdev->dev, "lpc24xx-rtc",
&lpc24xx_rtc_ops, THIS_MODULE);
if (IS_ERR(rtc->rtc)) {
dev_err(&pdev->dev, "can't register rtc device\n");
ret = PTR_ERR(rtc->rtc);
goto disable_clks;
}
return 0;
disable_clks:
clk_disable_unprepare(rtc->clk_reg);
disable_rtc_clk:
clk_disable_unprepare(rtc->clk_rtc);
return ret;
}
static int lpc24xx_rtc_remove(struct platform_device *pdev)
{
struct lpc24xx_rtc *rtc = platform_get_drvdata(pdev);
rtc_writel(rtc, LPC24XX_AMR, LPC24XX_ALARM_DISABLE);
rtc_writel(rtc, LPC24XX_CIIR, 0);
rtc_writel(rtc, LPC24XX_CCR, LPC178X_CCALEN);
clk_disable_unprepare(rtc->clk_rtc);
clk_disable_unprepare(rtc->clk_reg);
return 0;
}
