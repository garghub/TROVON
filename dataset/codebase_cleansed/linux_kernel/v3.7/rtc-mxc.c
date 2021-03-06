static u32 get_alarm_or_time(struct device *dev, int time_alarm)
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
return (((day * 24 + hr) * 60) + min) * 60 + sec;
}
static void set_alarm_or_time(struct device *dev, int time_alarm, u32 time)
{
u32 day, hr, min, sec, temp;
struct platform_device *pdev = to_platform_device(dev);
struct rtc_plat_data *pdata = platform_get_drvdata(pdev);
void __iomem *ioaddr = pdata->ioaddr;
day = time / 86400;
time -= day * 86400;
hr = time / 3600;
time -= hr * 3600;
min = time / 60;
sec = time - min * 60;
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
static int rtc_update_alarm(struct device *dev, struct rtc_time *alrm)
{
struct rtc_time alarm_tm, now_tm;
unsigned long now, time;
struct platform_device *pdev = to_platform_device(dev);
struct rtc_plat_data *pdata = platform_get_drvdata(pdev);
void __iomem *ioaddr = pdata->ioaddr;
now = get_alarm_or_time(dev, MXC_RTC_TIME);
rtc_time_to_tm(now, &now_tm);
alarm_tm.tm_year = now_tm.tm_year;
alarm_tm.tm_mon = now_tm.tm_mon;
alarm_tm.tm_mday = now_tm.tm_mday;
alarm_tm.tm_hour = alrm->tm_hour;
alarm_tm.tm_min = alrm->tm_min;
alarm_tm.tm_sec = alrm->tm_sec;
rtc_tm_to_time(&alarm_tm, &time);
writew(readw(ioaddr + RTC_RTCISR), ioaddr + RTC_RTCISR);
set_alarm_or_time(dev, MXC_RTC_ALARM, time);
return 0;
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
if (status & RTC_1HZ_BIT)
events |= (RTC_UF | RTC_IRQF);
if (status & PIT_ALL_ON)
events |= (RTC_PF | RTC_IRQF);
rtc_update_irq(pdata->rtc, 1, events);
spin_unlock_irqrestore(&pdata->rtc->irq_lock, flags);
return IRQ_HANDLED;
}
static void mxc_rtc_release(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct rtc_plat_data *pdata = platform_get_drvdata(pdev);
void __iomem *ioaddr = pdata->ioaddr;
spin_lock_irq(&pdata->rtc->irq_lock);
writew(0, ioaddr + RTC_RTCIENR);
writew(0xffffffff, ioaddr + RTC_RTCISR);
spin_unlock_irq(&pdata->rtc->irq_lock);
}
static int mxc_rtc_alarm_irq_enable(struct device *dev, unsigned int enabled)
{
mxc_rtc_irq_enable(dev, RTC_ALM_BIT, enabled);
return 0;
}
static int mxc_rtc_read_time(struct device *dev, struct rtc_time *tm)
{
u32 val;
do {
val = get_alarm_or_time(dev, MXC_RTC_TIME);
} while (val != get_alarm_or_time(dev, MXC_RTC_TIME));
rtc_time_to_tm(val, tm);
return 0;
}
static int mxc_rtc_set_mmss(struct device *dev, unsigned long time)
{
if (cpu_is_mx1()) {
struct rtc_time tm;
rtc_time_to_tm(time, &tm);
tm.tm_year = 70;
rtc_tm_to_time(&tm, &time);
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
rtc_time_to_tm(get_alarm_or_time(dev, MXC_RTC_ALARM), &alrm->time);
alrm->pending = ((readw(ioaddr + RTC_RTCISR) & RTC_ALM_BIT)) ? 1 : 0;
return 0;
}
static int mxc_rtc_set_alarm(struct device *dev, struct rtc_wkalrm *alrm)
{
struct platform_device *pdev = to_platform_device(dev);
struct rtc_plat_data *pdata = platform_get_drvdata(pdev);
int ret;
ret = rtc_update_alarm(dev, &alrm->time);
if (ret)
return ret;
memcpy(&pdata->g_rtc_alarm, &alrm->time, sizeof(struct rtc_time));
mxc_rtc_irq_enable(dev, RTC_ALM_BIT, alrm->enabled);
return 0;
}
static int __devinit mxc_rtc_probe(struct platform_device *pdev)
{
struct resource *res;
struct rtc_device *rtc;
struct rtc_plat_data *pdata = NULL;
u32 reg;
unsigned long rate;
int ret;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res)
return -ENODEV;
pdata = devm_kzalloc(&pdev->dev, sizeof(*pdata), GFP_KERNEL);
if (!pdata)
return -ENOMEM;
if (!devm_request_mem_region(&pdev->dev, res->start,
resource_size(res), pdev->name))
return -EBUSY;
pdata->ioaddr = devm_ioremap(&pdev->dev, res->start,
resource_size(res));
pdata->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(pdata->clk)) {
dev_err(&pdev->dev, "unable to get clock!\n");
ret = PTR_ERR(pdata->clk);
goto exit_free_pdata;
}
clk_prepare_enable(pdata->clk);
rate = clk_get_rate(pdata->clk);
if (rate == 32768)
reg = RTC_INPUT_CLK_32768HZ;
else if (rate == 32000)
reg = RTC_INPUT_CLK_32000HZ;
else if (rate == 38400)
reg = RTC_INPUT_CLK_38400HZ;
else {
dev_err(&pdev->dev, "rtc clock is not valid (%lu)\n", rate);
ret = -EINVAL;
goto exit_put_clk;
}
reg |= RTC_ENABLE_BIT;
writew(reg, (pdata->ioaddr + RTC_RTCCTL));
if (((readw(pdata->ioaddr + RTC_RTCCTL)) & RTC_ENABLE_BIT) == 0) {
dev_err(&pdev->dev, "hardware module can't be enabled!\n");
ret = -EIO;
goto exit_put_clk;
}
platform_set_drvdata(pdev, pdata);
pdata->irq = platform_get_irq(pdev, 0);
if (pdata->irq >= 0 &&
devm_request_irq(&pdev->dev, pdata->irq, mxc_rtc_interrupt,
IRQF_SHARED, pdev->name, pdev) < 0) {
dev_warn(&pdev->dev, "interrupt not available.\n");
pdata->irq = -1;
}
if (pdata->irq >=0)
device_init_wakeup(&pdev->dev, 1);
rtc = rtc_device_register(pdev->name, &pdev->dev, &mxc_rtc_ops,
THIS_MODULE);
if (IS_ERR(rtc)) {
ret = PTR_ERR(rtc);
goto exit_clr_drvdata;
}
pdata->rtc = rtc;
return 0;
exit_clr_drvdata:
platform_set_drvdata(pdev, NULL);
exit_put_clk:
clk_disable_unprepare(pdata->clk);
exit_free_pdata:
return ret;
}
static int __devexit mxc_rtc_remove(struct platform_device *pdev)
{
struct rtc_plat_data *pdata = platform_get_drvdata(pdev);
rtc_device_unregister(pdata->rtc);
clk_disable_unprepare(pdata->clk);
platform_set_drvdata(pdev, NULL);
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
