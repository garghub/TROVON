static void pic32_rtc_alarm_clk_enable(struct pic32_rtc_dev *pdata,
bool enable)
{
unsigned long flags;
spin_lock_irqsave(&pdata->alarm_lock, flags);
if (enable) {
if (!pdata->alarm_clk_enabled) {
clk_enable(pdata->clk);
pdata->alarm_clk_enabled = true;
}
} else {
if (pdata->alarm_clk_enabled) {
clk_disable(pdata->clk);
pdata->alarm_clk_enabled = false;
}
}
spin_unlock_irqrestore(&pdata->alarm_lock, flags);
}
static irqreturn_t pic32_rtc_alarmirq(int irq, void *id)
{
struct pic32_rtc_dev *pdata = (struct pic32_rtc_dev *)id;
clk_enable(pdata->clk);
rtc_update_irq(pdata->rtc, 1, RTC_AF | RTC_IRQF);
clk_disable(pdata->clk);
pic32_rtc_alarm_clk_enable(pdata, false);
return IRQ_HANDLED;
}
static int pic32_rtc_setaie(struct device *dev, unsigned int enabled)
{
struct pic32_rtc_dev *pdata = dev_get_drvdata(dev);
void __iomem *base = pdata->reg_base;
clk_enable(pdata->clk);
writel(PIC32_RTCALRM_ALRMEN,
base + (enabled ? PIC32_SET(PIC32_RTCALRM) :
PIC32_CLR(PIC32_RTCALRM)));
clk_disable(pdata->clk);
pic32_rtc_alarm_clk_enable(pdata, enabled);
return 0;
}
static int pic32_rtc_setfreq(struct device *dev, int freq)
{
struct pic32_rtc_dev *pdata = dev_get_drvdata(dev);
void __iomem *base = pdata->reg_base;
clk_enable(pdata->clk);
writel(PIC32_RTCALRM_AMASK, base + PIC32_CLR(PIC32_RTCALRM));
writel(freq << 8, base + PIC32_SET(PIC32_RTCALRM));
writel(PIC32_RTCALRM_CHIME, base + PIC32_SET(PIC32_RTCALRM));
clk_disable(pdata->clk);
return 0;
}
static int pic32_rtc_gettime(struct device *dev, struct rtc_time *rtc_tm)
{
struct pic32_rtc_dev *pdata = dev_get_drvdata(dev);
void __iomem *base = pdata->reg_base;
unsigned int tries = 0;
clk_enable(pdata->clk);
do {
rtc_tm->tm_hour = readb(base + PIC32_RTCHOUR);
rtc_tm->tm_min = readb(base + PIC32_RTCMIN);
rtc_tm->tm_mon = readb(base + PIC32_RTCMON);
rtc_tm->tm_mday = readb(base + PIC32_RTCDAY);
rtc_tm->tm_year = readb(base + PIC32_RTCYEAR);
rtc_tm->tm_sec = readb(base + PIC32_RTCSEC);
tries += 1;
} while (rtc_tm->tm_sec == 0 && tries < 2);
rtc_tm->tm_sec = bcd2bin(rtc_tm->tm_sec);
rtc_tm->tm_min = bcd2bin(rtc_tm->tm_min);
rtc_tm->tm_hour = bcd2bin(rtc_tm->tm_hour);
rtc_tm->tm_mday = bcd2bin(rtc_tm->tm_mday);
rtc_tm->tm_mon = bcd2bin(rtc_tm->tm_mon) - 1;
rtc_tm->tm_year = bcd2bin(rtc_tm->tm_year);
rtc_tm->tm_year += 100;
dev_dbg(dev, "read time %04d.%02d.%02d %02d:%02d:%02d\n",
1900 + rtc_tm->tm_year, rtc_tm->tm_mon, rtc_tm->tm_mday,
rtc_tm->tm_hour, rtc_tm->tm_min, rtc_tm->tm_sec);
clk_disable(pdata->clk);
return rtc_valid_tm(rtc_tm);
}
static int pic32_rtc_settime(struct device *dev, struct rtc_time *tm)
{
struct pic32_rtc_dev *pdata = dev_get_drvdata(dev);
void __iomem *base = pdata->reg_base;
int year = tm->tm_year - 100;
dev_dbg(dev, "set time %04d.%02d.%02d %02d:%02d:%02d\n",
1900 + tm->tm_year, tm->tm_mon, tm->tm_mday,
tm->tm_hour, tm->tm_min, tm->tm_sec);
if (year < 0 || year >= 100) {
dev_err(dev, "rtc only supports 100 years\n");
return -EINVAL;
}
clk_enable(pdata->clk);
writeb(bin2bcd(tm->tm_sec), base + PIC32_RTCSEC);
writeb(bin2bcd(tm->tm_min), base + PIC32_RTCMIN);
writeb(bin2bcd(tm->tm_hour), base + PIC32_RTCHOUR);
writeb(bin2bcd(tm->tm_mday), base + PIC32_RTCDAY);
writeb(bin2bcd(tm->tm_mon + 1), base + PIC32_RTCMON);
writeb(bin2bcd(year), base + PIC32_RTCYEAR);
clk_disable(pdata->clk);
return 0;
}
static int pic32_rtc_getalarm(struct device *dev, struct rtc_wkalrm *alrm)
{
struct pic32_rtc_dev *pdata = dev_get_drvdata(dev);
struct rtc_time *alm_tm = &alrm->time;
void __iomem *base = pdata->reg_base;
unsigned int alm_en;
clk_enable(pdata->clk);
alm_tm->tm_sec = readb(base + PIC32_ALRMSEC);
alm_tm->tm_min = readb(base + PIC32_ALRMMIN);
alm_tm->tm_hour = readb(base + PIC32_ALRMHOUR);
alm_tm->tm_mon = readb(base + PIC32_ALRMMON);
alm_tm->tm_mday = readb(base + PIC32_ALRMDAY);
alm_tm->tm_year = readb(base + PIC32_ALRMYEAR);
alm_en = readb(base + PIC32_RTCALRM);
alrm->enabled = (alm_en & PIC32_RTCALRM_ALRMEN) ? 1 : 0;
dev_dbg(dev, "getalarm: %d, %04d.%02d.%02d %02d:%02d:%02d\n",
alm_en,
1900 + alm_tm->tm_year, alm_tm->tm_mon, alm_tm->tm_mday,
alm_tm->tm_hour, alm_tm->tm_min, alm_tm->tm_sec);
alm_tm->tm_sec = bcd2bin(alm_tm->tm_sec);
alm_tm->tm_min = bcd2bin(alm_tm->tm_min);
alm_tm->tm_hour = bcd2bin(alm_tm->tm_hour);
alm_tm->tm_mday = bcd2bin(alm_tm->tm_mday);
alm_tm->tm_mon = bcd2bin(alm_tm->tm_mon) - 1;
alm_tm->tm_year = bcd2bin(alm_tm->tm_year);
clk_disable(pdata->clk);
return 0;
}
static int pic32_rtc_setalarm(struct device *dev, struct rtc_wkalrm *alrm)
{
struct pic32_rtc_dev *pdata = dev_get_drvdata(dev);
struct rtc_time *tm = &alrm->time;
void __iomem *base = pdata->reg_base;
clk_enable(pdata->clk);
dev_dbg(dev, "setalarm: %d, %04d.%02d.%02d %02d:%02d:%02d\n",
alrm->enabled,
1900 + tm->tm_year, tm->tm_mon + 1, tm->tm_mday,
tm->tm_hour, tm->tm_min, tm->tm_sec);
writel(0x00, base + PIC32_ALRMTIME);
writel(0x00, base + PIC32_ALRMDATE);
pic32_rtc_setaie(dev, alrm->enabled);
clk_disable(pdata->clk);
return 0;
}
static int pic32_rtc_proc(struct device *dev, struct seq_file *seq)
{
struct pic32_rtc_dev *pdata = dev_get_drvdata(dev);
void __iomem *base = pdata->reg_base;
unsigned int repeat;
clk_enable(pdata->clk);
repeat = readw(base + PIC32_RTCALRM);
repeat &= PIC32_RTCALRM_ARPT;
seq_printf(seq, "periodic_IRQ\t: %s\n", repeat ? "yes" : "no");
clk_disable(pdata->clk);
return 0;
}
static void pic32_rtc_enable(struct pic32_rtc_dev *pdata, int en)
{
void __iomem *base = pdata->reg_base;
if (!base)
return;
clk_enable(pdata->clk);
if (!en) {
writel(PIC32_RTCCON_ON, base + PIC32_CLR(PIC32_RTCCON));
} else {
pic32_syskey_unlock();
writel(PIC32_RTCCON_RTCWREN, base + PIC32_SET(PIC32_RTCCON));
writel(3 << 9, base + PIC32_CLR(PIC32_RTCCON));
if (!(readl(base + PIC32_RTCCON) & PIC32_RTCCON_ON))
writel(PIC32_RTCCON_ON, base + PIC32_SET(PIC32_RTCCON));
}
clk_disable(pdata->clk);
}
static int pic32_rtc_remove(struct platform_device *pdev)
{
struct pic32_rtc_dev *pdata = platform_get_drvdata(pdev);
pic32_rtc_setaie(&pdev->dev, 0);
clk_unprepare(pdata->clk);
pdata->clk = NULL;
return 0;
}
static int pic32_rtc_probe(struct platform_device *pdev)
{
struct pic32_rtc_dev *pdata;
struct resource *res;
int ret;
pdata = devm_kzalloc(&pdev->dev, sizeof(*pdata), GFP_KERNEL);
if (!pdata)
return -ENOMEM;
platform_set_drvdata(pdev, pdata);
pdata->alarm_irq = platform_get_irq(pdev, 0);
if (pdata->alarm_irq < 0) {
dev_err(&pdev->dev, "no irq for alarm\n");
return pdata->alarm_irq;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
pdata->reg_base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(pdata->reg_base))
return PTR_ERR(pdata->reg_base);
pdata->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(pdata->clk)) {
dev_err(&pdev->dev, "failed to find rtc clock source\n");
ret = PTR_ERR(pdata->clk);
pdata->clk = NULL;
return ret;
}
spin_lock_init(&pdata->alarm_lock);
clk_prepare_enable(pdata->clk);
pic32_rtc_enable(pdata, 1);
device_init_wakeup(&pdev->dev, 1);
pdata->rtc = devm_rtc_device_register(&pdev->dev, pdev->name,
&pic32_rtcops,
THIS_MODULE);
if (IS_ERR(pdata->rtc)) {
ret = PTR_ERR(pdata->rtc);
goto err_nortc;
}
pdata->rtc->max_user_freq = 128;
pic32_rtc_setfreq(&pdev->dev, 1);
ret = devm_request_irq(&pdev->dev, pdata->alarm_irq,
pic32_rtc_alarmirq, 0,
dev_name(&pdev->dev), pdata);
if (ret) {
dev_err(&pdev->dev,
"IRQ %d error %d\n", pdata->alarm_irq, ret);
goto err_nortc;
}
clk_disable(pdata->clk);
return 0;
err_nortc:
pic32_rtc_enable(pdata, 0);
clk_disable_unprepare(pdata->clk);
return ret;
}
