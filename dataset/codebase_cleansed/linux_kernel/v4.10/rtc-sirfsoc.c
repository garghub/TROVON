static u32 sirfsoc_rtc_readl(struct sirfsoc_rtc_drv *rtcdrv, u32 offset)
{
u32 val;
regmap_read(rtcdrv->regmap, rtcdrv->rtc_base + offset, &val);
return val;
}
static void sirfsoc_rtc_writel(struct sirfsoc_rtc_drv *rtcdrv,
u32 offset, u32 val)
{
regmap_write(rtcdrv->regmap, rtcdrv->rtc_base + offset, val);
}
static int sirfsoc_rtc_read_alarm(struct device *dev,
struct rtc_wkalrm *alrm)
{
unsigned long rtc_alarm, rtc_count;
struct sirfsoc_rtc_drv *rtcdrv;
rtcdrv = dev_get_drvdata(dev);
spin_lock_irq(&rtcdrv->lock);
rtc_count = sirfsoc_rtc_readl(rtcdrv, RTC_CN);
rtc_alarm = sirfsoc_rtc_readl(rtcdrv, RTC_ALARM0);
memset(alrm, 0, sizeof(struct rtc_wkalrm));
if (rtc_count > rtc_alarm)
rtc_time_to_tm((rtcdrv->overflow_rtc + 1)
<< (BITS_PER_LONG - RTC_SHIFT)
| rtc_alarm >> RTC_SHIFT, &(alrm->time));
else
rtc_time_to_tm(rtcdrv->overflow_rtc
<< (BITS_PER_LONG - RTC_SHIFT)
| rtc_alarm >> RTC_SHIFT, &(alrm->time));
if (sirfsoc_rtc_readl(rtcdrv, RTC_STATUS) & SIRFSOC_RTC_AL0E)
alrm->enabled = 1;
spin_unlock_irq(&rtcdrv->lock);
return 0;
}
static int sirfsoc_rtc_set_alarm(struct device *dev,
struct rtc_wkalrm *alrm)
{
unsigned long rtc_status_reg, rtc_alarm;
struct sirfsoc_rtc_drv *rtcdrv;
rtcdrv = dev_get_drvdata(dev);
if (alrm->enabled) {
rtc_tm_to_time(&(alrm->time), &rtc_alarm);
spin_lock_irq(&rtcdrv->lock);
rtc_status_reg = sirfsoc_rtc_readl(rtcdrv, RTC_STATUS);
if (rtc_status_reg & SIRFSOC_RTC_AL0E) {
dev_info(dev, "An old alarm was set, will be replaced by a new one\n");
}
sirfsoc_rtc_writel(rtcdrv, RTC_ALARM0, rtc_alarm << RTC_SHIFT);
rtc_status_reg &= ~0x07;
rtc_status_reg |= SIRFSOC_RTC_AL0;
rtc_status_reg |= SIRFSOC_RTC_AL0E;
sirfsoc_rtc_writel(rtcdrv, RTC_STATUS, rtc_status_reg);
spin_unlock_irq(&rtcdrv->lock);
} else {
spin_lock_irq(&rtcdrv->lock);
rtc_status_reg = sirfsoc_rtc_readl(rtcdrv, RTC_STATUS);
if (rtc_status_reg & SIRFSOC_RTC_AL0E) {
rtc_status_reg &= ~0x07;
rtc_status_reg |= (SIRFSOC_RTC_AL0);
rtc_status_reg &= ~(SIRFSOC_RTC_AL0E);
sirfsoc_rtc_writel(rtcdrv, RTC_STATUS,
rtc_status_reg);
}
spin_unlock_irq(&rtcdrv->lock);
}
return 0;
}
static int sirfsoc_rtc_read_time(struct device *dev,
struct rtc_time *tm)
{
unsigned long tmp_rtc = 0;
struct sirfsoc_rtc_drv *rtcdrv;
rtcdrv = dev_get_drvdata(dev);
do {
tmp_rtc = sirfsoc_rtc_readl(rtcdrv, RTC_CN);
cpu_relax();
} while (tmp_rtc != sirfsoc_rtc_readl(rtcdrv, RTC_CN));
rtc_time_to_tm(rtcdrv->overflow_rtc << (BITS_PER_LONG - RTC_SHIFT) |
tmp_rtc >> RTC_SHIFT, tm);
return 0;
}
static int sirfsoc_rtc_set_time(struct device *dev,
struct rtc_time *tm)
{
unsigned long rtc_time;
struct sirfsoc_rtc_drv *rtcdrv;
rtcdrv = dev_get_drvdata(dev);
rtc_tm_to_time(tm, &rtc_time);
rtcdrv->overflow_rtc = rtc_time >> (BITS_PER_LONG - RTC_SHIFT);
sirfsoc_rtc_writel(rtcdrv, RTC_SW_VALUE, rtcdrv->overflow_rtc);
sirfsoc_rtc_writel(rtcdrv, RTC_CN, rtc_time << RTC_SHIFT);
return 0;
}
static int sirfsoc_rtc_ioctl(struct device *dev, unsigned int cmd,
unsigned long arg)
{
switch (cmd) {
case RTC_PIE_ON:
case RTC_PIE_OFF:
case RTC_UIE_ON:
case RTC_UIE_OFF:
case RTC_AIE_ON:
case RTC_AIE_OFF:
return 0;
default:
return -ENOIOCTLCMD;
}
}
static int sirfsoc_rtc_alarm_irq_enable(struct device *dev,
unsigned int enabled)
{
unsigned long rtc_status_reg = 0x0;
struct sirfsoc_rtc_drv *rtcdrv;
rtcdrv = dev_get_drvdata(dev);
spin_lock_irq(&rtcdrv->lock);
rtc_status_reg = sirfsoc_rtc_readl(rtcdrv, RTC_STATUS);
if (enabled)
rtc_status_reg |= SIRFSOC_RTC_AL0E;
else
rtc_status_reg &= ~SIRFSOC_RTC_AL0E;
sirfsoc_rtc_writel(rtcdrv, RTC_STATUS, rtc_status_reg);
spin_unlock_irq(&rtcdrv->lock);
return 0;
}
static irqreturn_t sirfsoc_rtc_irq_handler(int irq, void *pdata)
{
struct sirfsoc_rtc_drv *rtcdrv = pdata;
unsigned long rtc_status_reg = 0x0;
unsigned long events = 0x0;
spin_lock(&rtcdrv->lock);
rtc_status_reg = sirfsoc_rtc_readl(rtcdrv, RTC_STATUS);
if (rtc_status_reg & SIRFSOC_RTC_AL0) {
rtc_status_reg &= ~0x07;
rtc_status_reg |= (SIRFSOC_RTC_AL0);
rtc_status_reg &= ~(SIRFSOC_RTC_AL0E);
}
sirfsoc_rtc_writel(rtcdrv, RTC_STATUS, rtc_status_reg);
spin_unlock(&rtcdrv->lock);
events |= RTC_IRQF | RTC_AF;
rtc_update_irq(rtcdrv->rtc, 1, events);
return IRQ_HANDLED;
}
static int sirfsoc_rtc_probe(struct platform_device *pdev)
{
int err;
unsigned long rtc_div;
struct sirfsoc_rtc_drv *rtcdrv;
struct device_node *np = pdev->dev.of_node;
rtcdrv = devm_kzalloc(&pdev->dev,
sizeof(struct sirfsoc_rtc_drv), GFP_KERNEL);
if (rtcdrv == NULL)
return -ENOMEM;
spin_lock_init(&rtcdrv->lock);
err = of_property_read_u32(np, "reg", &rtcdrv->rtc_base);
if (err) {
dev_err(&pdev->dev, "unable to find base address of rtc node in dtb\n");
return err;
}
platform_set_drvdata(pdev, rtcdrv);
device_init_wakeup(&pdev->dev, 1);
rtcdrv->regmap = devm_regmap_init_iobg(&pdev->dev,
&sysrtc_regmap_config);
if (IS_ERR(rtcdrv->regmap)) {
err = PTR_ERR(rtcdrv->regmap);
dev_err(&pdev->dev, "Failed to allocate register map: %d\n",
err);
return err;
}
rtc_div = ((32768 / RTC_HZ) / 2) - 1;
sirfsoc_rtc_writel(rtcdrv, RTC_DIV, rtc_div);
sirfsoc_rtc_writel(rtcdrv, RTC_CLOCK_SWITCH, SIRFSOC_RTC_CLK);
sirfsoc_rtc_writel(rtcdrv, RTC_ALARM0, 0x0);
sirfsoc_rtc_writel(rtcdrv, RTC_ALARM1, 0x0);
rtcdrv->overflow_rtc =
sirfsoc_rtc_readl(rtcdrv, RTC_SW_VALUE);
rtcdrv->rtc = devm_rtc_device_register(&pdev->dev, pdev->name,
&sirfsoc_rtc_ops, THIS_MODULE);
if (IS_ERR(rtcdrv->rtc)) {
err = PTR_ERR(rtcdrv->rtc);
dev_err(&pdev->dev, "can't register RTC device\n");
return err;
}
rtcdrv->irq = platform_get_irq(pdev, 0);
err = devm_request_irq(
&pdev->dev,
rtcdrv->irq,
sirfsoc_rtc_irq_handler,
IRQF_SHARED,
pdev->name,
rtcdrv);
if (err) {
dev_err(&pdev->dev, "Unable to register for the SiRF SOC RTC IRQ\n");
return err;
}
return 0;
}
static int sirfsoc_rtc_remove(struct platform_device *pdev)
{
device_init_wakeup(&pdev->dev, 0);
return 0;
}
static int sirfsoc_rtc_suspend(struct device *dev)
{
struct sirfsoc_rtc_drv *rtcdrv = dev_get_drvdata(dev);
rtcdrv->overflow_rtc =
sirfsoc_rtc_readl(rtcdrv, RTC_SW_VALUE);
rtcdrv->saved_counter =
sirfsoc_rtc_readl(rtcdrv, RTC_CN);
rtcdrv->saved_overflow_rtc = rtcdrv->overflow_rtc;
if (device_may_wakeup(dev) && !enable_irq_wake(rtcdrv->irq))
rtcdrv->irq_wake = 1;
return 0;
}
static int sirfsoc_rtc_resume(struct device *dev)
{
u32 tmp;
struct sirfsoc_rtc_drv *rtcdrv = dev_get_drvdata(dev);
if (SIRFSOC_RTC_CLK != sirfsoc_rtc_readl(rtcdrv, RTC_CLOCK_SWITCH)) {
u32 rtc_div;
sirfsoc_rtc_writel(rtcdrv, RTC_CLOCK_SWITCH, SIRFSOC_RTC_CLK);
rtc_div = ((32768 / RTC_HZ) / 2) - 1;
sirfsoc_rtc_writel(rtcdrv, RTC_DIV, rtc_div);
sirfsoc_rtc_writel(rtcdrv, RTC_ALARM0, 0x0);
sirfsoc_rtc_writel(rtcdrv, RTC_ALARM1, 0x0);
}
rtcdrv->overflow_rtc = rtcdrv->saved_overflow_rtc;
tmp = sirfsoc_rtc_readl(rtcdrv, RTC_CN);
if (tmp <= rtcdrv->saved_counter)
rtcdrv->overflow_rtc++;
sirfsoc_rtc_writel(rtcdrv, RTC_SW_VALUE, rtcdrv->overflow_rtc);
if (device_may_wakeup(dev) && rtcdrv->irq_wake) {
disable_irq_wake(rtcdrv->irq);
rtcdrv->irq_wake = 0;
}
return 0;
}
