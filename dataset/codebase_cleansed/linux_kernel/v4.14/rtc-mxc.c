static inline int is_imx1_rtc(struct rtc_plat_data *data)
{
return data->devtype == IMX1_RTC;
}
static time64_t get_alarm_or_time(struct device *dev, int time_alarm)
{
struct platform_device *pdev = to_platform_device(dev);
struct rtc_plat_data *pdata = platform_get_drvdata(pdev);
void __iomem *ioaddr = pdata->ioaddr;
u32 day = 0, hr = 0, min = 0, sec = 0, hr_min = 0;
switch (time_alarm) {
case MXC_RTC_TIME:
day = readw(ioaddr + RTC_DAYR);
hr_min = readw(ioaddr + RTC_HOURMIN);
sec = readw(ioaddr + RTC_SECOND);
break;
case MXC_RTC_ALARM:
day = readw(ioaddr + RTC_DAYALARM);
hr_min = readw(ioaddr + RTC_ALRM_HM) & 0xffff;
sec = readw(ioaddr + RTC_ALRM_SEC);
break;
}
hr = hr_min >> 8;
min = hr_min & 0xff;
return ((((time64_t)day * 24 + hr) * 60) + min) * 60 + sec;
}
static void set_alarm_or_time(struct device *dev, int time_alarm, time64_t time)
{
u32 tod, day, hr, min, sec, temp;
struct platform_device *pdev = to_platform_device(dev);
struct rtc_plat_data *pdata = platform_get_drvdata(pdev);
void __iomem *ioaddr = pdata->ioaddr;
day = div_s64_rem(time, 86400, &tod);
hr = tod / 3600;
tod -= hr * 3600;
min = tod / 60;
sec = tod - min * 60;
temp = (hr << 8) + min;
switch (time_alarm) {
case MXC_RTC_TIME:
writew(day, ioaddr + RTC_DAYR);
writew(sec, ioaddr + RTC_SECOND);
writew(temp, ioaddr + RTC_HOURMIN);
break;
case MXC_RTC_ALARM:
writew(day, ioaddr + RTC_DAYALARM);
writew(sec, ioaddr + RTC_ALRM_SEC);
writew(temp, ioaddr + RTC_ALRM_HM);
break;
}
}
static void rtc_update_alarm(struct device *dev, struct rtc_time *alrm)
{
time64_t time;
struct platform_device *pdev = to_platform_device(dev);
struct rtc_plat_data *pdata = platform_get_drvdata(pdev);
void __iomem *ioaddr = pdata->ioaddr;
time = rtc_tm_to_time64(alrm);
writew(readw(ioaddr + RTC_RTCISR), ioaddr + RTC_RTCISR);
set_alarm_or_time(dev, MXC_RTC_ALARM, time);
}
static void mxc_rtc_irq_enable(struct device *dev, unsigned int bit,
unsigned int enabled)
{
struct platform_device *pdev = to_platform_device(dev);
struct rtc_plat_data *pdata = platform_get_drvdata(pdev);
void __iomem *ioaddr = pdata->ioaddr;
u32 reg;
spin_lock_irq(&pdata->rtc->irq_lock);
reg = readw(ioaddr + RTC_RTCIENR);
if (enabled)
reg |= bit;
else
reg &= ~bit;
writew(reg, ioaddr + RTC_RTCIENR);
spin_unlock_irq(&pdata->rtc->irq_lock);
}
static irqreturn_t mxc_rtc_interrupt(int irq, void *dev_id)
{
struct platform_device *pdev = dev_id;
struct rtc_plat_data *pdata = platform_get_drvdata(pdev);
void __iomem *ioaddr = pdata->ioaddr;
unsigned long flags;
u32 status;
u32 events = 0;
spin_lock_irqsave(&pdata->rtc->irq_lock, flags);
status = readw(ioaddr + RTC_RTCISR) & readw(ioaddr + RTC_RTCIENR);
writew(status, ioaddr + RTC_RTCISR);
if (status & RTC_ALM_BIT) {
events |= (RTC_AF | RTC_IRQF);
mxc_rtc_irq_enable(&pdev->dev, RTC_ALM_BIT, 0);
}
if (status & PIT_ALL_ON)
events |= (RTC_PF | RTC_IRQF);
rtc_update_irq(pdata->rtc, 1, events);
spin_unlock_irqrestore(&pdata->rtc->irq_lock, flags);
return IRQ_HANDLED;
}
static int mxc_rtc_alarm_irq_enable(struct device *dev, unsigned int enabled)
{
mxc_rtc_irq_enable(dev, RTC_ALM_BIT, enabled);
return 0;
}
static int mxc_rtc_read_time(struct device *dev, struct rtc_time *tm)
{
time64_t val;
do {
val = get_alarm_or_time(dev, MXC_RTC_TIME);
} while (val != get_alarm_or_time(dev, MXC_RTC_TIME));
rtc_time64_to_tm(val, tm);
return 0;
}
static int mxc_rtc_set_mmss(struct device *dev, time64_t time)
{
struct platform_device *pdev = to_platform_device(dev);
struct rtc_plat_data *pdata = platform_get_drvdata(pdev);
if (is_imx1_rtc(pdata)) {
struct rtc_time tm;
rtc_time64_to_tm(time, &tm);
tm.tm_year = 70;
time = rtc_tm_to_time64(&tm);
}
do {
set_alarm_or_time(dev, MXC_RTC_TIME, time);
} while (time != get_alarm_or_time(dev, MXC_RTC_TIME));
return 0;
}
static int mxc_rtc_read_alarm(struct device *dev, struct rtc_wkalrm *alrm)
{
struct platform_device *pdev = to_platform_device(dev);
struct rtc_plat_data *pdata = platform_get_drvdata(pdev);
void __iomem *ioaddr = pdata->ioaddr;
rtc_time64_to_tm(get_alarm_or_time(dev, MXC_RTC_ALARM), &alrm->time);
alrm->pending = ((readw(ioaddr + RTC_RTCISR) & RTC_ALM_BIT)) ? 1 : 0;
return 0;
}
static int mxc_rtc_set_alarm(struct device *dev, struct rtc_wkalrm *alrm)
{
struct platform_device *pdev = to_platform_device(dev);
struct rtc_plat_data *pdata = platform_get_drvdata(pdev);
rtc_update_alarm(dev, &alrm->time);
memcpy(&pdata->g_rtc_alarm, &alrm->time, sizeof(struct rtc_time));
mxc_rtc_irq_enable(dev, RTC_ALM_BIT, alrm->enabled);
return 0;
}
static int mxc_rtc_probe(struct platform_device *pdev)
{
struct resource *res;
struct rtc_device *rtc;
struct rtc_plat_data *pdata = NULL;
u32 reg;
unsigned long rate;
int ret;
const struct of_device_id *of_id;
pdata = devm_kzalloc(&pdev->dev, sizeof(*pdata), GFP_KERNEL);
if (!pdata)
return -ENOMEM;
of_id = of_match_device(imx_rtc_dt_ids, &pdev->dev);
if (of_id)
pdata->devtype = (enum imx_rtc_type)of_id->data;
else
pdata->devtype = pdev->id_entry->driver_data;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
pdata->ioaddr = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(pdata->ioaddr))
return PTR_ERR(pdata->ioaddr);
pdata->clk_ipg = devm_clk_get(&pdev->dev, "ipg");
if (IS_ERR(pdata->clk_ipg)) {
dev_err(&pdev->dev, "unable to get ipg clock!\n");
return PTR_ERR(pdata->clk_ipg);
}
ret = clk_prepare_enable(pdata->clk_ipg);
if (ret)
return ret;
pdata->clk_ref = devm_clk_get(&pdev->dev, "ref");
if (IS_ERR(pdata->clk_ref)) {
dev_err(&pdev->dev, "unable to get ref clock!\n");
ret = PTR_ERR(pdata->clk_ref);
goto exit_put_clk_ipg;
}
ret = clk_prepare_enable(pdata->clk_ref);
if (ret)
goto exit_put_clk_ipg;
rate = clk_get_rate(pdata->clk_ref);
if (rate == 32768)
reg = RTC_INPUT_CLK_32768HZ;
else if (rate == 32000)
reg = RTC_INPUT_CLK_32000HZ;
else if (rate == 38400)
reg = RTC_INPUT_CLK_38400HZ;
else {
dev_err(&pdev->dev, "rtc clock is not valid (%lu)\n", rate);
ret = -EINVAL;
goto exit_put_clk_ref;
}
reg |= RTC_ENABLE_BIT;
writew(reg, (pdata->ioaddr + RTC_RTCCTL));
if (((readw(pdata->ioaddr + RTC_RTCCTL)) & RTC_ENABLE_BIT) == 0) {
dev_err(&pdev->dev, "hardware module can't be enabled!\n");
ret = -EIO;
goto exit_put_clk_ref;
}
platform_set_drvdata(pdev, pdata);
pdata->irq = platform_get_irq(pdev, 0);
if (pdata->irq >= 0 &&
devm_request_irq(&pdev->dev, pdata->irq, mxc_rtc_interrupt,
IRQF_SHARED, pdev->name, pdev) < 0) {
dev_warn(&pdev->dev, "interrupt not available.\n");
pdata->irq = -1;
}
if (pdata->irq >= 0)
device_init_wakeup(&pdev->dev, 1);
rtc = devm_rtc_device_register(&pdev->dev, pdev->name, &mxc_rtc_ops,
THIS_MODULE);
if (IS_ERR(rtc)) {
ret = PTR_ERR(rtc);
goto exit_put_clk_ref;
}
pdata->rtc = rtc;
return 0;
exit_put_clk_ref:
clk_disable_unprepare(pdata->clk_ref);
exit_put_clk_ipg:
clk_disable_unprepare(pdata->clk_ipg);
return ret;
}
static int mxc_rtc_remove(struct platform_device *pdev)
{
struct rtc_plat_data *pdata = platform_get_drvdata(pdev);
clk_disable_unprepare(pdata->clk_ref);
clk_disable_unprepare(pdata->clk_ipg);
return 0;
}
static int mxc_rtc_suspend(struct device *dev)
{
struct rtc_plat_data *pdata = dev_get_drvdata(dev);
if (device_may_wakeup(dev))
enable_irq_wake(pdata->irq);
return 0;
}
static int mxc_rtc_resume(struct device *dev)
{
struct rtc_plat_data *pdata = dev_get_drvdata(dev);
if (device_may_wakeup(dev))
disable_irq_wake(pdata->irq);
return 0;
}
