static irqreturn_t gemini_rtc_interrupt(int irq, void *dev)
{
return IRQ_HANDLED;
}
static int gemini_rtc_read_time(struct device *dev, struct rtc_time *tm)
{
struct gemini_rtc *rtc = dev_get_drvdata(dev);
unsigned int days, hour, min, sec;
unsigned long offset, time;
sec = readl(rtc->rtc_base + GEMINI_RTC_SECOND);
min = readl(rtc->rtc_base + GEMINI_RTC_MINUTE);
hour = readl(rtc->rtc_base + GEMINI_RTC_HOUR);
days = readl(rtc->rtc_base + GEMINI_RTC_DAYS);
offset = readl(rtc->rtc_base + GEMINI_RTC_RECORD);
time = offset + days * 86400 + hour * 3600 + min * 60 + sec;
rtc_time_to_tm(time, tm);
return 0;
}
static int gemini_rtc_set_time(struct device *dev, struct rtc_time *tm)
{
struct gemini_rtc *rtc = dev_get_drvdata(dev);
unsigned int sec, min, hour, day;
unsigned long offset, time;
if (tm->tm_year >= 2148)
return -EINVAL;
rtc_tm_to_time(tm, &time);
sec = readl(rtc->rtc_base + GEMINI_RTC_SECOND);
min = readl(rtc->rtc_base + GEMINI_RTC_MINUTE);
hour = readl(rtc->rtc_base + GEMINI_RTC_HOUR);
day = readl(rtc->rtc_base + GEMINI_RTC_DAYS);
offset = time - (day * 86400 + hour * 3600 + min * 60 + sec);
writel(offset, rtc->rtc_base + GEMINI_RTC_RECORD);
writel(0x01, rtc->rtc_base + GEMINI_RTC_CR);
return 0;
}
static int gemini_rtc_probe(struct platform_device *pdev)
{
struct gemini_rtc *rtc;
struct device *dev = &pdev->dev;
struct resource *res;
int ret;
rtc = devm_kzalloc(&pdev->dev, sizeof(*rtc), GFP_KERNEL);
if (unlikely(!rtc))
return -ENOMEM;
platform_set_drvdata(pdev, rtc);
res = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
if (!res)
return -ENODEV;
rtc->rtc_irq = res->start;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res)
return -ENODEV;
rtc->rtc_base = devm_ioremap(dev, res->start,
resource_size(res));
ret = devm_request_irq(dev, rtc->rtc_irq, gemini_rtc_interrupt,
IRQF_SHARED, pdev->name, dev);
if (unlikely(ret))
return ret;
rtc->rtc_dev = rtc_device_register(pdev->name, dev,
&gemini_rtc_ops, THIS_MODULE);
if (likely(IS_ERR(rtc->rtc_dev)))
return PTR_ERR(rtc->rtc_dev);
return 0;
}
static int gemini_rtc_remove(struct platform_device *pdev)
{
struct gemini_rtc *rtc = platform_get_drvdata(pdev);
rtc_device_unregister(rtc->rtc_dev);
platform_set_drvdata(pdev, NULL);
return 0;
}
