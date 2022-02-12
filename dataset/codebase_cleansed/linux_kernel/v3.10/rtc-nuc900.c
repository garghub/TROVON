static irqreturn_t nuc900_rtc_interrupt(int irq, void *_rtc)
{
struct nuc900_rtc *rtc = _rtc;
unsigned long events = 0, rtc_irq;
rtc_irq = __raw_readl(rtc->rtc_reg + REG_RTC_RIIR);
if (rtc_irq & ALARMINTENB) {
rtc_irq &= ~ALARMINTENB;
__raw_writel(rtc_irq, rtc->rtc_reg + REG_RTC_RIIR);
events |= RTC_AF | RTC_IRQF;
}
if (rtc_irq & TICKINTENB) {
rtc_irq &= ~TICKINTENB;
__raw_writel(rtc_irq, rtc->rtc_reg + REG_RTC_RIIR);
events |= RTC_UF | RTC_IRQF;
}
rtc_update_irq(rtc->rtcdev, 1, events);
return IRQ_HANDLED;
}
static int *check_rtc_access_enable(struct nuc900_rtc *nuc900_rtc)
{
unsigned int timeout = 0x1000;
__raw_writel(INIRRESET, nuc900_rtc->rtc_reg + REG_RTC_INIR);
mdelay(10);
__raw_writel(AERPOWERON, nuc900_rtc->rtc_reg + REG_RTC_AER);
while (!(__raw_readl(nuc900_rtc->rtc_reg + REG_RTC_AER) & AERRWENB)
&& timeout--)
mdelay(1);
if (!timeout)
return ERR_PTR(-EPERM);
return 0;
}
static int nuc900_rtc_bcd2bin(unsigned int timereg,
unsigned int calreg, struct rtc_time *tm)
{
tm->tm_mday = bcd2bin(calreg >> 0);
tm->tm_mon = bcd2bin(calreg >> 8);
tm->tm_year = bcd2bin(calreg >> 16) + 100;
tm->tm_sec = bcd2bin(timereg >> 0);
tm->tm_min = bcd2bin(timereg >> 8);
tm->tm_hour = bcd2bin(timereg >> 16);
return rtc_valid_tm(tm);
}
static void nuc900_rtc_bin2bcd(struct device *dev, struct rtc_time *settm,
struct nuc900_bcd_time *gettm)
{
gettm->bcd_mday = bin2bcd(settm->tm_mday) << 0;
gettm->bcd_mon = bin2bcd(settm->tm_mon) << 8;
if (settm->tm_year < 100) {
dev_warn(dev, "The year will be between 1970-1999, right?\n");
gettm->bcd_year = bin2bcd(settm->tm_year) << 16;
} else {
gettm->bcd_year = bin2bcd(settm->tm_year - 100) << 16;
}
gettm->bcd_sec = bin2bcd(settm->tm_sec) << 0;
gettm->bcd_min = bin2bcd(settm->tm_min) << 8;
gettm->bcd_hour = bin2bcd(settm->tm_hour) << 16;
}
static int nuc900_alarm_irq_enable(struct device *dev, unsigned int enabled)
{
struct nuc900_rtc *rtc = dev_get_drvdata(dev);
if (enabled)
__raw_writel(__raw_readl(rtc->rtc_reg + REG_RTC_RIER)|
(ALARMINTENB), rtc->rtc_reg + REG_RTC_RIER);
else
__raw_writel(__raw_readl(rtc->rtc_reg + REG_RTC_RIER)&
(~ALARMINTENB), rtc->rtc_reg + REG_RTC_RIER);
return 0;
}
static int nuc900_rtc_read_time(struct device *dev, struct rtc_time *tm)
{
struct nuc900_rtc *rtc = dev_get_drvdata(dev);
unsigned int timeval, clrval;
timeval = __raw_readl(rtc->rtc_reg + REG_RTC_TLR);
clrval = __raw_readl(rtc->rtc_reg + REG_RTC_CLR);
return nuc900_rtc_bcd2bin(timeval, clrval, tm);
}
static int nuc900_rtc_set_time(struct device *dev, struct rtc_time *tm)
{
struct nuc900_rtc *rtc = dev_get_drvdata(dev);
struct nuc900_bcd_time gettm;
unsigned long val;
int *err;
nuc900_rtc_bin2bcd(dev, tm, &gettm);
err = check_rtc_access_enable(rtc);
if (IS_ERR(err))
return PTR_ERR(err);
val = gettm.bcd_mday | gettm.bcd_mon | gettm.bcd_year;
__raw_writel(val, rtc->rtc_reg + REG_RTC_CLR);
val = gettm.bcd_sec | gettm.bcd_min | gettm.bcd_hour;
__raw_writel(val, rtc->rtc_reg + REG_RTC_TLR);
return 0;
}
static int nuc900_rtc_read_alarm(struct device *dev, struct rtc_wkalrm *alrm)
{
struct nuc900_rtc *rtc = dev_get_drvdata(dev);
unsigned int timeval, carval;
timeval = __raw_readl(rtc->rtc_reg + REG_RTC_TAR);
carval = __raw_readl(rtc->rtc_reg + REG_RTC_CAR);
return nuc900_rtc_bcd2bin(timeval, carval, &alrm->time);
}
static int nuc900_rtc_set_alarm(struct device *dev, struct rtc_wkalrm *alrm)
{
struct nuc900_rtc *rtc = dev_get_drvdata(dev);
struct nuc900_bcd_time tm;
unsigned long val;
int *err;
nuc900_rtc_bin2bcd(dev, &alrm->time, &tm);
err = check_rtc_access_enable(rtc);
if (IS_ERR(err))
return PTR_ERR(err);
val = tm.bcd_mday | tm.bcd_mon | tm.bcd_year;
__raw_writel(val, rtc->rtc_reg + REG_RTC_CAR);
val = tm.bcd_sec | tm.bcd_min | tm.bcd_hour;
__raw_writel(val, rtc->rtc_reg + REG_RTC_TAR);
return 0;
}
static int __init nuc900_rtc_probe(struct platform_device *pdev)
{
struct resource *res;
struct nuc900_rtc *nuc900_rtc;
nuc900_rtc = devm_kzalloc(&pdev->dev, sizeof(struct nuc900_rtc),
GFP_KERNEL);
if (!nuc900_rtc) {
dev_err(&pdev->dev, "kzalloc nuc900_rtc failed\n");
return -ENOMEM;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
nuc900_rtc->rtc_reg = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(nuc900_rtc->rtc_reg))
return PTR_ERR(nuc900_rtc->rtc_reg);
platform_set_drvdata(pdev, nuc900_rtc);
nuc900_rtc->rtcdev = devm_rtc_device_register(&pdev->dev, pdev->name,
&nuc900_rtc_ops, THIS_MODULE);
if (IS_ERR(nuc900_rtc->rtcdev)) {
dev_err(&pdev->dev, "rtc device register failed\n");
return PTR_ERR(nuc900_rtc->rtcdev);
}
__raw_writel(__raw_readl(nuc900_rtc->rtc_reg + REG_RTC_TSSR) | MODE24,
nuc900_rtc->rtc_reg + REG_RTC_TSSR);
nuc900_rtc->irq_num = platform_get_irq(pdev, 0);
if (devm_request_irq(&pdev->dev, nuc900_rtc->irq_num,
nuc900_rtc_interrupt, 0, "nuc900rtc", nuc900_rtc)) {
dev_err(&pdev->dev, "NUC900 RTC request irq failed\n");
return -EBUSY;
}
return 0;
}
static int __exit nuc900_rtc_remove(struct platform_device *pdev)
{
platform_set_drvdata(pdev, NULL);
return 0;
}
