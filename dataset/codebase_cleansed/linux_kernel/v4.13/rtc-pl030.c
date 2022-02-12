static irqreturn_t pl030_interrupt(int irq, void *dev_id)
{
struct pl030_rtc *rtc = dev_id;
writel(0, rtc->base + RTC_EOI);
return IRQ_HANDLED;
}
static int pl030_read_alarm(struct device *dev, struct rtc_wkalrm *alrm)
{
struct pl030_rtc *rtc = dev_get_drvdata(dev);
rtc_time_to_tm(readl(rtc->base + RTC_MR), &alrm->time);
return 0;
}
static int pl030_set_alarm(struct device *dev, struct rtc_wkalrm *alrm)
{
struct pl030_rtc *rtc = dev_get_drvdata(dev);
unsigned long time;
int ret;
ret = rtc_valid_tm(&alrm->time);
if (ret == 0)
ret = rtc_tm_to_time(&alrm->time, &time);
if (ret == 0)
writel(time, rtc->base + RTC_MR);
return ret;
}
static int pl030_read_time(struct device *dev, struct rtc_time *tm)
{
struct pl030_rtc *rtc = dev_get_drvdata(dev);
rtc_time_to_tm(readl(rtc->base + RTC_DR), tm);
return 0;
}
static int pl030_set_time(struct device *dev, struct rtc_time *tm)
{
struct pl030_rtc *rtc = dev_get_drvdata(dev);
unsigned long time;
int ret;
ret = rtc_tm_to_time(tm, &time);
if (ret == 0)
writel(time + 1, rtc->base + RTC_LR);
return ret;
}
static int pl030_probe(struct amba_device *dev, const struct amba_id *id)
{
struct pl030_rtc *rtc;
int ret;
ret = amba_request_regions(dev, NULL);
if (ret)
goto err_req;
rtc = devm_kzalloc(&dev->dev, sizeof(*rtc), GFP_KERNEL);
if (!rtc) {
ret = -ENOMEM;
goto err_rtc;
}
rtc->base = ioremap(dev->res.start, resource_size(&dev->res));
if (!rtc->base) {
ret = -ENOMEM;
goto err_rtc;
}
__raw_writel(0, rtc->base + RTC_CR);
__raw_writel(0, rtc->base + RTC_EOI);
amba_set_drvdata(dev, rtc);
ret = request_irq(dev->irq[0], pl030_interrupt, 0,
"rtc-pl030", rtc);
if (ret)
goto err_irq;
rtc->rtc = rtc_device_register("pl030", &dev->dev, &pl030_ops,
THIS_MODULE);
if (IS_ERR(rtc->rtc)) {
ret = PTR_ERR(rtc->rtc);
goto err_reg;
}
return 0;
err_reg:
free_irq(dev->irq[0], rtc);
err_irq:
iounmap(rtc->base);
err_rtc:
amba_release_regions(dev);
err_req:
return ret;
}
static int pl030_remove(struct amba_device *dev)
{
struct pl030_rtc *rtc = amba_get_drvdata(dev);
writel(0, rtc->base + RTC_CR);
free_irq(dev->irq[0], rtc);
rtc_device_unregister(rtc->rtc);
iounmap(rtc->base);
amba_release_regions(dev);
return 0;
}
