static void st_rtc_set_hw_alarm(struct st_rtc *rtc,
unsigned long msb, unsigned long lsb)
{
unsigned long flags;
spin_lock_irqsave(&rtc->lock, flags);
writel_relaxed(1, rtc->ioaddr + LPC_WDT_OFF);
writel_relaxed(msb, rtc->ioaddr + LPC_LPA_MSB_OFF);
writel_relaxed(lsb, rtc->ioaddr + LPC_LPA_LSB_OFF);
writel_relaxed(1, rtc->ioaddr + LPC_LPA_START_OFF);
writel_relaxed(0, rtc->ioaddr + LPC_WDT_OFF);
spin_unlock_irqrestore(&rtc->lock, flags);
}
static irqreturn_t st_rtc_handler(int this_irq, void *data)
{
struct st_rtc *rtc = (struct st_rtc *)data;
rtc_update_irq(rtc->rtc_dev, 1, RTC_AF);
return IRQ_HANDLED;
}
static int st_rtc_read_time(struct device *dev, struct rtc_time *tm)
{
struct st_rtc *rtc = dev_get_drvdata(dev);
unsigned long lpt_lsb, lpt_msb;
unsigned long long lpt;
unsigned long flags;
spin_lock_irqsave(&rtc->lock, flags);
do {
lpt_msb = readl_relaxed(rtc->ioaddr + LPC_LPT_MSB_OFF);
lpt_lsb = readl_relaxed(rtc->ioaddr + LPC_LPT_LSB_OFF);
} while (readl_relaxed(rtc->ioaddr + LPC_LPT_MSB_OFF) != lpt_msb);
spin_unlock_irqrestore(&rtc->lock, flags);
lpt = ((unsigned long long)lpt_msb << 32) | lpt_lsb;
do_div(lpt, rtc->clkrate);
rtc_time64_to_tm(lpt, tm);
return 0;
}
static int st_rtc_set_time(struct device *dev, struct rtc_time *tm)
{
struct st_rtc *rtc = dev_get_drvdata(dev);
unsigned long long lpt, secs;
unsigned long flags;
secs = rtc_tm_to_time64(tm);
lpt = (unsigned long long)secs * rtc->clkrate;
spin_lock_irqsave(&rtc->lock, flags);
writel_relaxed(lpt >> 32, rtc->ioaddr + LPC_LPT_MSB_OFF);
writel_relaxed(lpt, rtc->ioaddr + LPC_LPT_LSB_OFF);
writel_relaxed(1, rtc->ioaddr + LPC_LPT_START_OFF);
spin_unlock_irqrestore(&rtc->lock, flags);
return 0;
}
static int st_rtc_read_alarm(struct device *dev, struct rtc_wkalrm *wkalrm)
{
struct st_rtc *rtc = dev_get_drvdata(dev);
unsigned long flags;
spin_lock_irqsave(&rtc->lock, flags);
memcpy(wkalrm, &rtc->alarm, sizeof(struct rtc_wkalrm));
spin_unlock_irqrestore(&rtc->lock, flags);
return 0;
}
static int st_rtc_alarm_irq_enable(struct device *dev, unsigned int enabled)
{
struct st_rtc *rtc = dev_get_drvdata(dev);
if (enabled && !rtc->irq_enabled) {
enable_irq(rtc->irq);
rtc->irq_enabled = true;
} else if (!enabled && rtc->irq_enabled) {
disable_irq(rtc->irq);
rtc->irq_enabled = false;
}
return 0;
}
static int st_rtc_set_alarm(struct device *dev, struct rtc_wkalrm *t)
{
struct st_rtc *rtc = dev_get_drvdata(dev);
struct rtc_time now;
unsigned long long now_secs;
unsigned long long alarm_secs;
unsigned long long lpa;
st_rtc_read_time(dev, &now);
now_secs = rtc_tm_to_time64(&now);
alarm_secs = rtc_tm_to_time64(&t->time);
if (now_secs > alarm_secs)
return -EINVAL;
memcpy(&rtc->alarm, t, sizeof(struct rtc_wkalrm));
alarm_secs -= now_secs;
lpa = (unsigned long long)alarm_secs * rtc->clkrate;
st_rtc_set_hw_alarm(rtc, lpa >> 32, lpa);
st_rtc_alarm_irq_enable(dev, t->enabled);
return 0;
}
static int st_rtc_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct st_rtc *rtc;
struct resource *res;
struct rtc_time tm_check;
uint32_t mode;
int ret = 0;
ret = of_property_read_u32(np, "st,lpc-mode", &mode);
if (ret) {
dev_err(&pdev->dev, "An LPC mode must be provided\n");
return -EINVAL;
}
if (mode != ST_LPC_MODE_RTC)
return -ENODEV;
rtc = devm_kzalloc(&pdev->dev, sizeof(struct st_rtc), GFP_KERNEL);
if (!rtc)
return -ENOMEM;
spin_lock_init(&rtc->lock);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
rtc->ioaddr = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(rtc->ioaddr))
return PTR_ERR(rtc->ioaddr);
rtc->irq = irq_of_parse_and_map(np, 0);
if (!rtc->irq) {
dev_err(&pdev->dev, "IRQ missing or invalid\n");
return -EINVAL;
}
ret = devm_request_irq(&pdev->dev, rtc->irq, st_rtc_handler, 0,
pdev->name, rtc);
if (ret) {
dev_err(&pdev->dev, "Failed to request irq %i\n", rtc->irq);
return ret;
}
enable_irq_wake(rtc->irq);
disable_irq(rtc->irq);
rtc->clk = clk_get(&pdev->dev, NULL);
if (IS_ERR(rtc->clk)) {
dev_err(&pdev->dev, "Unable to request clock\n");
return PTR_ERR(rtc->clk);
}
clk_prepare_enable(rtc->clk);
rtc->clkrate = clk_get_rate(rtc->clk);
if (!rtc->clkrate) {
dev_err(&pdev->dev, "Unable to fetch clock rate\n");
return -EINVAL;
}
device_set_wakeup_capable(&pdev->dev, 1);
platform_set_drvdata(pdev, rtc);
st_rtc_read_time(&pdev->dev, &tm_check);
if (tm_check.tm_year >= (2038 - 1900)) {
memset(&tm_check, 0, sizeof(tm_check));
tm_check.tm_year = 100;
tm_check.tm_mday = 1;
st_rtc_set_time(&pdev->dev, &tm_check);
}
rtc->rtc_dev = rtc_device_register("st-lpc-rtc", &pdev->dev,
&st_rtc_ops, THIS_MODULE);
if (IS_ERR(rtc->rtc_dev)) {
clk_disable_unprepare(rtc->clk);
return PTR_ERR(rtc->rtc_dev);
}
return 0;
}
static int st_rtc_remove(struct platform_device *pdev)
{
struct st_rtc *rtc = platform_get_drvdata(pdev);
if (likely(rtc->rtc_dev))
rtc_device_unregister(rtc->rtc_dev);
return 0;
}
static int st_rtc_suspend(struct device *dev)
{
struct st_rtc *rtc = dev_get_drvdata(dev);
if (device_may_wakeup(dev))
return 0;
writel_relaxed(1, rtc->ioaddr + LPC_WDT_OFF);
writel_relaxed(0, rtc->ioaddr + LPC_LPA_START_OFF);
writel_relaxed(0, rtc->ioaddr + LPC_WDT_OFF);
return 0;
}
static int st_rtc_resume(struct device *dev)
{
struct st_rtc *rtc = dev_get_drvdata(dev);
rtc_alarm_irq_enable(rtc->rtc_dev, 0);
memset(&rtc->alarm, 0, sizeof(struct rtc_wkalrm));
writel_relaxed(0, rtc->ioaddr + LPC_LPA_MSB_OFF);
writel_relaxed(0, rtc->ioaddr + LPC_LPA_LSB_OFF);
writel_relaxed(1, rtc->ioaddr + LPC_WDT_OFF);
writel_relaxed(1, rtc->ioaddr + LPC_LPA_START_OFF);
writel_relaxed(0, rtc->ioaddr + LPC_WDT_OFF);
return 0;
}
