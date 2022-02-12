static void pcf2rtc_time(struct rtc_time *rtc, struct pcf50633_time *pcf)
{
rtc->tm_sec = bcd2bin(pcf->time[PCF50633_TI_SEC]);
rtc->tm_min = bcd2bin(pcf->time[PCF50633_TI_MIN]);
rtc->tm_hour = bcd2bin(pcf->time[PCF50633_TI_HOUR]);
rtc->tm_wday = bcd2bin(pcf->time[PCF50633_TI_WKDAY]);
rtc->tm_mday = bcd2bin(pcf->time[PCF50633_TI_DAY]);
rtc->tm_mon = bcd2bin(pcf->time[PCF50633_TI_MONTH]) - 1;
rtc->tm_year = bcd2bin(pcf->time[PCF50633_TI_YEAR]) + 100;
}
static void rtc2pcf_time(struct pcf50633_time *pcf, struct rtc_time *rtc)
{
pcf->time[PCF50633_TI_SEC] = bin2bcd(rtc->tm_sec);
pcf->time[PCF50633_TI_MIN] = bin2bcd(rtc->tm_min);
pcf->time[PCF50633_TI_HOUR] = bin2bcd(rtc->tm_hour);
pcf->time[PCF50633_TI_WKDAY] = bin2bcd(rtc->tm_wday);
pcf->time[PCF50633_TI_DAY] = bin2bcd(rtc->tm_mday);
pcf->time[PCF50633_TI_MONTH] = bin2bcd(rtc->tm_mon + 1);
pcf->time[PCF50633_TI_YEAR] = bin2bcd(rtc->tm_year % 100);
}
static int
pcf50633_rtc_alarm_irq_enable(struct device *dev, unsigned int enabled)
{
struct pcf50633_rtc *rtc = dev_get_drvdata(dev);
int err;
if (enabled)
err = pcf50633_irq_unmask(rtc->pcf, PCF50633_IRQ_ALARM);
else
err = pcf50633_irq_mask(rtc->pcf, PCF50633_IRQ_ALARM);
if (err < 0)
return err;
rtc->alarm_enabled = enabled;
return 0;
}
static int pcf50633_rtc_read_time(struct device *dev, struct rtc_time *tm)
{
struct pcf50633_rtc *rtc;
struct pcf50633_time pcf_tm;
int ret;
rtc = dev_get_drvdata(dev);
ret = pcf50633_read_block(rtc->pcf, PCF50633_REG_RTCSC,
PCF50633_TI_EXTENT,
&pcf_tm.time[0]);
if (ret != PCF50633_TI_EXTENT) {
dev_err(dev, "Failed to read time\n");
return -EIO;
}
dev_dbg(dev, "PCF_TIME: %02x.%02x.%02x %02x:%02x:%02x\n",
pcf_tm.time[PCF50633_TI_DAY],
pcf_tm.time[PCF50633_TI_MONTH],
pcf_tm.time[PCF50633_TI_YEAR],
pcf_tm.time[PCF50633_TI_HOUR],
pcf_tm.time[PCF50633_TI_MIN],
pcf_tm.time[PCF50633_TI_SEC]);
pcf2rtc_time(tm, &pcf_tm);
dev_dbg(dev, "RTC_TIME: %u.%u.%u %u:%u:%u\n",
tm->tm_mday, tm->tm_mon, tm->tm_year,
tm->tm_hour, tm->tm_min, tm->tm_sec);
return rtc_valid_tm(tm);
}
static int pcf50633_rtc_set_time(struct device *dev, struct rtc_time *tm)
{
struct pcf50633_rtc *rtc;
struct pcf50633_time pcf_tm;
int alarm_masked, ret = 0;
rtc = dev_get_drvdata(dev);
dev_dbg(dev, "RTC_TIME: %u.%u.%u %u:%u:%u\n",
tm->tm_mday, tm->tm_mon, tm->tm_year,
tm->tm_hour, tm->tm_min, tm->tm_sec);
rtc2pcf_time(&pcf_tm, tm);
dev_dbg(dev, "PCF_TIME: %02x.%02x.%02x %02x:%02x:%02x\n",
pcf_tm.time[PCF50633_TI_DAY],
pcf_tm.time[PCF50633_TI_MONTH],
pcf_tm.time[PCF50633_TI_YEAR],
pcf_tm.time[PCF50633_TI_HOUR],
pcf_tm.time[PCF50633_TI_MIN],
pcf_tm.time[PCF50633_TI_SEC]);
alarm_masked = pcf50633_irq_mask_get(rtc->pcf, PCF50633_IRQ_ALARM);
if (!alarm_masked)
pcf50633_irq_mask(rtc->pcf, PCF50633_IRQ_ALARM);
ret = pcf50633_write_block(rtc->pcf, PCF50633_REG_RTCSC,
PCF50633_TI_EXTENT,
&pcf_tm.time[0]);
if (!alarm_masked)
pcf50633_irq_unmask(rtc->pcf, PCF50633_IRQ_ALARM);
return ret;
}
static int pcf50633_rtc_read_alarm(struct device *dev, struct rtc_wkalrm *alrm)
{
struct pcf50633_rtc *rtc;
struct pcf50633_time pcf_tm;
int ret = 0;
rtc = dev_get_drvdata(dev);
alrm->enabled = rtc->alarm_enabled;
alrm->pending = rtc->alarm_pending;
ret = pcf50633_read_block(rtc->pcf, PCF50633_REG_RTCSCA,
PCF50633_TI_EXTENT, &pcf_tm.time[0]);
if (ret != PCF50633_TI_EXTENT) {
dev_err(dev, "Failed to read time\n");
return -EIO;
}
pcf2rtc_time(&alrm->time, &pcf_tm);
return rtc_valid_tm(&alrm->time);
}
static int pcf50633_rtc_set_alarm(struct device *dev, struct rtc_wkalrm *alrm)
{
struct pcf50633_rtc *rtc;
struct pcf50633_time pcf_tm;
int alarm_masked, ret = 0;
rtc = dev_get_drvdata(dev);
rtc2pcf_time(&pcf_tm, &alrm->time);
pcf_tm.time[PCF50633_TI_WKDAY] = 7;
alarm_masked = pcf50633_irq_mask_get(rtc->pcf, PCF50633_IRQ_ALARM);
if (!alarm_masked)
pcf50633_irq_mask(rtc->pcf, PCF50633_IRQ_ALARM);
ret = pcf50633_write_block(rtc->pcf, PCF50633_REG_RTCSCA,
PCF50633_TI_EXTENT, &pcf_tm.time[0]);
if (!alrm->enabled)
rtc->alarm_pending = 0;
if (!alarm_masked || alrm->enabled)
pcf50633_irq_unmask(rtc->pcf, PCF50633_IRQ_ALARM);
rtc->alarm_enabled = alrm->enabled;
return ret;
}
static void pcf50633_rtc_irq(int irq, void *data)
{
struct pcf50633_rtc *rtc = data;
rtc_update_irq(rtc->rtc_dev, 1, RTC_AF | RTC_IRQF);
rtc->alarm_pending = 1;
}
static int pcf50633_rtc_probe(struct platform_device *pdev)
{
struct pcf50633_rtc *rtc;
rtc = devm_kzalloc(&pdev->dev, sizeof(*rtc), GFP_KERNEL);
if (!rtc)
return -ENOMEM;
rtc->pcf = dev_to_pcf50633(pdev->dev.parent);
platform_set_drvdata(pdev, rtc);
rtc->rtc_dev = devm_rtc_device_register(&pdev->dev, "pcf50633-rtc",
&pcf50633_rtc_ops, THIS_MODULE);
if (IS_ERR(rtc->rtc_dev))
return PTR_ERR(rtc->rtc_dev);
pcf50633_register_irq(rtc->pcf, PCF50633_IRQ_ALARM,
pcf50633_rtc_irq, rtc);
return 0;
}
static int pcf50633_rtc_remove(struct platform_device *pdev)
{
struct pcf50633_rtc *rtc;
rtc = platform_get_drvdata(pdev);
pcf50633_free_irq(rtc->pcf, PCF50633_IRQ_ALARM);
return 0;
}
