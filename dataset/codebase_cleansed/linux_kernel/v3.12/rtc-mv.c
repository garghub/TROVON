static int mv_rtc_set_time(struct device *dev, struct rtc_time *tm)
{
struct rtc_plat_data *pdata = dev_get_drvdata(dev);
void __iomem *ioaddr = pdata->ioaddr;
u32 rtc_reg;
rtc_reg = (bin2bcd(tm->tm_sec) << RTC_SECONDS_OFFS) |
(bin2bcd(tm->tm_min) << RTC_MINUTES_OFFS) |
(bin2bcd(tm->tm_hour) << RTC_HOURS_OFFS) |
(bin2bcd(tm->tm_wday) << RTC_WDAY_OFFS);
writel(rtc_reg, ioaddr + RTC_TIME_REG_OFFS);
rtc_reg = (bin2bcd(tm->tm_mday) << RTC_MDAY_OFFS) |
(bin2bcd(tm->tm_mon + 1) << RTC_MONTH_OFFS) |
(bin2bcd(tm->tm_year % 100) << RTC_YEAR_OFFS);
writel(rtc_reg, ioaddr + RTC_DATE_REG_OFFS);
return 0;
}
static int mv_rtc_read_time(struct device *dev, struct rtc_time *tm)
{
struct rtc_plat_data *pdata = dev_get_drvdata(dev);
void __iomem *ioaddr = pdata->ioaddr;
u32 rtc_time, rtc_date;
unsigned int year, month, day, hour, minute, second, wday;
rtc_time = readl(ioaddr + RTC_TIME_REG_OFFS);
rtc_date = readl(ioaddr + RTC_DATE_REG_OFFS);
second = rtc_time & 0x7f;
minute = (rtc_time >> RTC_MINUTES_OFFS) & 0x7f;
hour = (rtc_time >> RTC_HOURS_OFFS) & 0x3f;
wday = (rtc_time >> RTC_WDAY_OFFS) & 0x7;
day = rtc_date & 0x3f;
month = (rtc_date >> RTC_MONTH_OFFS) & 0x3f;
year = (rtc_date >> RTC_YEAR_OFFS) & 0xff;
tm->tm_sec = bcd2bin(second);
tm->tm_min = bcd2bin(minute);
tm->tm_hour = bcd2bin(hour);
tm->tm_mday = bcd2bin(day);
tm->tm_wday = bcd2bin(wday);
tm->tm_mon = bcd2bin(month) - 1;
tm->tm_year = bcd2bin(year) + 100;
return rtc_valid_tm(tm);
}
static int mv_rtc_read_alarm(struct device *dev, struct rtc_wkalrm *alm)
{
struct rtc_plat_data *pdata = dev_get_drvdata(dev);
void __iomem *ioaddr = pdata->ioaddr;
u32 rtc_time, rtc_date;
unsigned int year, month, day, hour, minute, second, wday;
rtc_time = readl(ioaddr + RTC_ALARM_TIME_REG_OFFS);
rtc_date = readl(ioaddr + RTC_ALARM_DATE_REG_OFFS);
second = rtc_time & 0x7f;
minute = (rtc_time >> RTC_MINUTES_OFFS) & 0x7f;
hour = (rtc_time >> RTC_HOURS_OFFS) & 0x3f;
wday = (rtc_time >> RTC_WDAY_OFFS) & 0x7;
day = rtc_date & 0x3f;
month = (rtc_date >> RTC_MONTH_OFFS) & 0x3f;
year = (rtc_date >> RTC_YEAR_OFFS) & 0xff;
alm->time.tm_sec = bcd2bin(second);
alm->time.tm_min = bcd2bin(minute);
alm->time.tm_hour = bcd2bin(hour);
alm->time.tm_mday = bcd2bin(day);
alm->time.tm_wday = bcd2bin(wday);
alm->time.tm_mon = bcd2bin(month) - 1;
alm->time.tm_year = bcd2bin(year) + 100;
if (rtc_valid_tm(&alm->time) < 0) {
dev_err(dev, "retrieved alarm date/time is not valid.\n");
rtc_time_to_tm(0, &alm->time);
}
alm->enabled = !!readl(ioaddr + RTC_ALARM_INTERRUPT_MASK_REG_OFFS);
return 0;
}
static int mv_rtc_set_alarm(struct device *dev, struct rtc_wkalrm *alm)
{
struct rtc_plat_data *pdata = dev_get_drvdata(dev);
void __iomem *ioaddr = pdata->ioaddr;
u32 rtc_reg = 0;
if (alm->time.tm_sec >= 0)
rtc_reg |= (RTC_ALARM_VALID | bin2bcd(alm->time.tm_sec))
<< RTC_SECONDS_OFFS;
if (alm->time.tm_min >= 0)
rtc_reg |= (RTC_ALARM_VALID | bin2bcd(alm->time.tm_min))
<< RTC_MINUTES_OFFS;
if (alm->time.tm_hour >= 0)
rtc_reg |= (RTC_ALARM_VALID | bin2bcd(alm->time.tm_hour))
<< RTC_HOURS_OFFS;
writel(rtc_reg, ioaddr + RTC_ALARM_TIME_REG_OFFS);
if (alm->time.tm_mday >= 0)
rtc_reg = (RTC_ALARM_VALID | bin2bcd(alm->time.tm_mday))
<< RTC_MDAY_OFFS;
else
rtc_reg = 0;
if (alm->time.tm_mon >= 0)
rtc_reg |= (RTC_ALARM_VALID | bin2bcd(alm->time.tm_mon + 1))
<< RTC_MONTH_OFFS;
if (alm->time.tm_year >= 0)
rtc_reg |= (RTC_ALARM_VALID | bin2bcd(alm->time.tm_year % 100))
<< RTC_YEAR_OFFS;
writel(rtc_reg, ioaddr + RTC_ALARM_DATE_REG_OFFS);
writel(0, ioaddr + RTC_ALARM_INTERRUPT_CASUE_REG_OFFS);
writel(alm->enabled ? 1 : 0,
ioaddr + RTC_ALARM_INTERRUPT_MASK_REG_OFFS);
return 0;
}
static int mv_rtc_alarm_irq_enable(struct device *dev, unsigned int enabled)
{
struct platform_device *pdev = to_platform_device(dev);
struct rtc_plat_data *pdata = platform_get_drvdata(pdev);
void __iomem *ioaddr = pdata->ioaddr;
if (pdata->irq < 0)
return -EINVAL;
if (enabled)
writel(1, ioaddr + RTC_ALARM_INTERRUPT_MASK_REG_OFFS);
else
writel(0, ioaddr + RTC_ALARM_INTERRUPT_MASK_REG_OFFS);
return 0;
}
static irqreturn_t mv_rtc_interrupt(int irq, void *data)
{
struct rtc_plat_data *pdata = data;
void __iomem *ioaddr = pdata->ioaddr;
if (!readl(ioaddr + RTC_ALARM_INTERRUPT_CASUE_REG_OFFS))
return IRQ_NONE;
writel(0, ioaddr + RTC_ALARM_INTERRUPT_CASUE_REG_OFFS);
rtc_update_irq(pdata->rtc, 1, RTC_IRQF | RTC_AF);
return IRQ_HANDLED;
}
static int __init mv_rtc_probe(struct platform_device *pdev)
{
struct resource *res;
struct rtc_plat_data *pdata;
u32 rtc_time;
int ret = 0;
pdata = devm_kzalloc(&pdev->dev, sizeof(*pdata), GFP_KERNEL);
if (!pdata)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
pdata->ioaddr = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(pdata->ioaddr))
return PTR_ERR(pdata->ioaddr);
pdata->clk = devm_clk_get(&pdev->dev, NULL);
if (!IS_ERR(pdata->clk))
clk_prepare_enable(pdata->clk);
rtc_time = readl(pdata->ioaddr + RTC_TIME_REG_OFFS);
if (rtc_time & RTC_HOURS_12H_MODE) {
dev_err(&pdev->dev, "24 Hours mode not supported.\n");
ret = -EINVAL;
goto out;
}
if (rtc_time == 0x01000000) {
ssleep(1);
rtc_time = readl(pdata->ioaddr + RTC_TIME_REG_OFFS);
if (rtc_time == 0x01000000) {
dev_err(&pdev->dev, "internal RTC not ticking\n");
ret = -ENODEV;
goto out;
}
}
pdata->irq = platform_get_irq(pdev, 0);
platform_set_drvdata(pdev, pdata);
if (pdata->irq >= 0) {
device_init_wakeup(&pdev->dev, 1);
pdata->rtc = devm_rtc_device_register(&pdev->dev, pdev->name,
&mv_rtc_alarm_ops,
THIS_MODULE);
} else {
pdata->rtc = devm_rtc_device_register(&pdev->dev, pdev->name,
&mv_rtc_ops, THIS_MODULE);
}
if (IS_ERR(pdata->rtc)) {
ret = PTR_ERR(pdata->rtc);
goto out;
}
if (pdata->irq >= 0) {
writel(0, pdata->ioaddr + RTC_ALARM_INTERRUPT_MASK_REG_OFFS);
if (devm_request_irq(&pdev->dev, pdata->irq, mv_rtc_interrupt,
IRQF_SHARED,
pdev->name, pdata) < 0) {
dev_warn(&pdev->dev, "interrupt not available.\n");
pdata->irq = -1;
}
}
return 0;
out:
if (!IS_ERR(pdata->clk))
clk_disable_unprepare(pdata->clk);
return ret;
}
static int __exit mv_rtc_remove(struct platform_device *pdev)
{
struct rtc_plat_data *pdata = platform_get_drvdata(pdev);
if (pdata->irq >= 0)
device_init_wakeup(&pdev->dev, 0);
if (!IS_ERR(pdata->clk))
clk_disable_unprepare(pdata->clk);
return 0;
}
