static void rtc_wait_not_busy(void)
{
int count = 0;
u8 status;
for (count = 0; count < 50; count++) {
status = rtc_read(OMAP_RTC_STATUS_REG);
if ((status & (u8)OMAP_RTC_STATUS_BUSY) == 0)
break;
udelay(1);
}
}
static irqreturn_t rtc_irq(int irq, void *rtc)
{
unsigned long events = 0;
u8 irq_data;
irq_data = rtc_read(OMAP_RTC_STATUS_REG);
if (irq_data & OMAP_RTC_STATUS_ALARM) {
rtc_write(OMAP_RTC_STATUS_ALARM, OMAP_RTC_STATUS_REG);
events |= RTC_IRQF | RTC_AF;
}
if (irq_data & OMAP_RTC_STATUS_1S_EVENT)
events |= RTC_IRQF | RTC_UF;
rtc_update_irq(rtc, 1, events);
return IRQ_HANDLED;
}
static int omap_rtc_alarm_irq_enable(struct device *dev, unsigned int enabled)
{
u8 reg, irqwake_reg = 0;
struct platform_device *pdev = to_platform_device(dev);
const struct platform_device_id *id_entry =
platform_get_device_id(pdev);
local_irq_disable();
rtc_wait_not_busy();
reg = rtc_read(OMAP_RTC_INTERRUPTS_REG);
if (id_entry->driver_data & OMAP_RTC_HAS_IRQWAKEEN)
irqwake_reg = rtc_read(OMAP_RTC_IRQWAKEEN);
if (enabled) {
reg |= OMAP_RTC_INTERRUPTS_IT_ALARM;
irqwake_reg |= OMAP_RTC_IRQWAKEEN_ALARM_WAKEEN;
} else {
reg &= ~OMAP_RTC_INTERRUPTS_IT_ALARM;
irqwake_reg &= ~OMAP_RTC_IRQWAKEEN_ALARM_WAKEEN;
}
rtc_wait_not_busy();
rtc_write(reg, OMAP_RTC_INTERRUPTS_REG);
if (id_entry->driver_data & OMAP_RTC_HAS_IRQWAKEEN)
rtc_write(irqwake_reg, OMAP_RTC_IRQWAKEEN);
local_irq_enable();
return 0;
}
static int tm2bcd(struct rtc_time *tm)
{
if (rtc_valid_tm(tm) != 0)
return -EINVAL;
tm->tm_sec = bin2bcd(tm->tm_sec);
tm->tm_min = bin2bcd(tm->tm_min);
tm->tm_hour = bin2bcd(tm->tm_hour);
tm->tm_mday = bin2bcd(tm->tm_mday);
tm->tm_mon = bin2bcd(tm->tm_mon + 1);
if (tm->tm_year < 100 || tm->tm_year > 199)
return -EINVAL;
tm->tm_year = bin2bcd(tm->tm_year - 100);
return 0;
}
static void bcd2tm(struct rtc_time *tm)
{
tm->tm_sec = bcd2bin(tm->tm_sec);
tm->tm_min = bcd2bin(tm->tm_min);
tm->tm_hour = bcd2bin(tm->tm_hour);
tm->tm_mday = bcd2bin(tm->tm_mday);
tm->tm_mon = bcd2bin(tm->tm_mon) - 1;
tm->tm_year = bcd2bin(tm->tm_year) + 100;
}
static int omap_rtc_read_time(struct device *dev, struct rtc_time *tm)
{
local_irq_disable();
rtc_wait_not_busy();
tm->tm_sec = rtc_read(OMAP_RTC_SECONDS_REG);
tm->tm_min = rtc_read(OMAP_RTC_MINUTES_REG);
tm->tm_hour = rtc_read(OMAP_RTC_HOURS_REG);
tm->tm_mday = rtc_read(OMAP_RTC_DAYS_REG);
tm->tm_mon = rtc_read(OMAP_RTC_MONTHS_REG);
tm->tm_year = rtc_read(OMAP_RTC_YEARS_REG);
local_irq_enable();
bcd2tm(tm);
return 0;
}
static int omap_rtc_set_time(struct device *dev, struct rtc_time *tm)
{
if (tm2bcd(tm) < 0)
return -EINVAL;
local_irq_disable();
rtc_wait_not_busy();
rtc_write(tm->tm_year, OMAP_RTC_YEARS_REG);
rtc_write(tm->tm_mon, OMAP_RTC_MONTHS_REG);
rtc_write(tm->tm_mday, OMAP_RTC_DAYS_REG);
rtc_write(tm->tm_hour, OMAP_RTC_HOURS_REG);
rtc_write(tm->tm_min, OMAP_RTC_MINUTES_REG);
rtc_write(tm->tm_sec, OMAP_RTC_SECONDS_REG);
local_irq_enable();
return 0;
}
static int omap_rtc_read_alarm(struct device *dev, struct rtc_wkalrm *alm)
{
local_irq_disable();
rtc_wait_not_busy();
alm->time.tm_sec = rtc_read(OMAP_RTC_ALARM_SECONDS_REG);
alm->time.tm_min = rtc_read(OMAP_RTC_ALARM_MINUTES_REG);
alm->time.tm_hour = rtc_read(OMAP_RTC_ALARM_HOURS_REG);
alm->time.tm_mday = rtc_read(OMAP_RTC_ALARM_DAYS_REG);
alm->time.tm_mon = rtc_read(OMAP_RTC_ALARM_MONTHS_REG);
alm->time.tm_year = rtc_read(OMAP_RTC_ALARM_YEARS_REG);
local_irq_enable();
bcd2tm(&alm->time);
alm->enabled = !!(rtc_read(OMAP_RTC_INTERRUPTS_REG)
& OMAP_RTC_INTERRUPTS_IT_ALARM);
return 0;
}
static int omap_rtc_set_alarm(struct device *dev, struct rtc_wkalrm *alm)
{
u8 reg, irqwake_reg = 0;
struct platform_device *pdev = to_platform_device(dev);
const struct platform_device_id *id_entry =
platform_get_device_id(pdev);
if (tm2bcd(&alm->time) < 0)
return -EINVAL;
local_irq_disable();
rtc_wait_not_busy();
rtc_write(alm->time.tm_year, OMAP_RTC_ALARM_YEARS_REG);
rtc_write(alm->time.tm_mon, OMAP_RTC_ALARM_MONTHS_REG);
rtc_write(alm->time.tm_mday, OMAP_RTC_ALARM_DAYS_REG);
rtc_write(alm->time.tm_hour, OMAP_RTC_ALARM_HOURS_REG);
rtc_write(alm->time.tm_min, OMAP_RTC_ALARM_MINUTES_REG);
rtc_write(alm->time.tm_sec, OMAP_RTC_ALARM_SECONDS_REG);
reg = rtc_read(OMAP_RTC_INTERRUPTS_REG);
if (id_entry->driver_data & OMAP_RTC_HAS_IRQWAKEEN)
irqwake_reg = rtc_read(OMAP_RTC_IRQWAKEEN);
if (alm->enabled) {
reg |= OMAP_RTC_INTERRUPTS_IT_ALARM;
irqwake_reg |= OMAP_RTC_IRQWAKEEN_ALARM_WAKEEN;
} else {
reg &= ~OMAP_RTC_INTERRUPTS_IT_ALARM;
irqwake_reg &= ~OMAP_RTC_IRQWAKEEN_ALARM_WAKEEN;
}
rtc_write(reg, OMAP_RTC_INTERRUPTS_REG);
if (id_entry->driver_data & OMAP_RTC_HAS_IRQWAKEEN)
rtc_write(irqwake_reg, OMAP_RTC_IRQWAKEEN);
local_irq_enable();
return 0;
}
static int __init omap_rtc_probe(struct platform_device *pdev)
{
struct resource *res;
struct rtc_device *rtc;
u8 reg, new_ctrl;
const struct platform_device_id *id_entry;
const struct of_device_id *of_id;
of_id = of_match_device(omap_rtc_of_match, &pdev->dev);
if (of_id)
pdev->id_entry = of_id->data;
id_entry = platform_get_device_id(pdev);
if (!id_entry) {
dev_err(&pdev->dev, "no matching device entry\n");
return -ENODEV;
}
omap_rtc_timer = platform_get_irq(pdev, 0);
if (omap_rtc_timer <= 0) {
pr_debug("%s: no update irq?\n", pdev->name);
return -ENOENT;
}
omap_rtc_alarm = platform_get_irq(pdev, 1);
if (omap_rtc_alarm <= 0) {
pr_debug("%s: no alarm irq?\n", pdev->name);
return -ENOENT;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
rtc_base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(rtc_base))
return PTR_ERR(rtc_base);
pm_runtime_enable(&pdev->dev);
pm_runtime_get_sync(&pdev->dev);
if (id_entry->driver_data & OMAP_RTC_HAS_KICKER) {
rtc_writel(KICK0_VALUE, OMAP_RTC_KICK0_REG);
rtc_writel(KICK1_VALUE, OMAP_RTC_KICK1_REG);
}
rtc = devm_rtc_device_register(&pdev->dev, pdev->name,
&omap_rtc_ops, THIS_MODULE);
if (IS_ERR(rtc)) {
pr_debug("%s: can't register RTC device, err %ld\n",
pdev->name, PTR_ERR(rtc));
goto fail0;
}
platform_set_drvdata(pdev, rtc);
rtc_write(0, OMAP_RTC_INTERRUPTS_REG);
if (id_entry->driver_data & OMAP_RTC_HAS_32KCLK_EN)
rtc_writel(OMAP_RTC_OSC_32KCLK_EN, OMAP_RTC_OSC_REG);
reg = rtc_read(OMAP_RTC_STATUS_REG);
if (reg & (u8) OMAP_RTC_STATUS_POWER_UP) {
pr_info("%s: RTC power up reset detected\n",
pdev->name);
rtc_write(OMAP_RTC_STATUS_POWER_UP, OMAP_RTC_STATUS_REG);
}
if (reg & (u8) OMAP_RTC_STATUS_ALARM)
rtc_write(OMAP_RTC_STATUS_ALARM, OMAP_RTC_STATUS_REG);
if (devm_request_irq(&pdev->dev, omap_rtc_timer, rtc_irq, 0,
dev_name(&rtc->dev), rtc)) {
pr_debug("%s: RTC timer interrupt IRQ%d already claimed\n",
pdev->name, omap_rtc_timer);
goto fail0;
}
if ((omap_rtc_timer != omap_rtc_alarm) &&
(devm_request_irq(&pdev->dev, omap_rtc_alarm, rtc_irq, 0,
dev_name(&rtc->dev), rtc))) {
pr_debug("%s: RTC alarm interrupt IRQ%d already claimed\n",
pdev->name, omap_rtc_alarm);
goto fail0;
}
reg = rtc_read(OMAP_RTC_CTRL_REG);
if (reg & (u8) OMAP_RTC_CTRL_STOP)
pr_info("%s: already running\n", pdev->name);
new_ctrl = reg & (OMAP_RTC_CTRL_SPLIT|OMAP_RTC_CTRL_AUTO_COMP);
new_ctrl |= OMAP_RTC_CTRL_STOP;
device_init_wakeup(&pdev->dev, true);
if (new_ctrl & (u8) OMAP_RTC_CTRL_SPLIT)
pr_info("%s: split power mode\n", pdev->name);
if (reg != new_ctrl)
rtc_write(new_ctrl, OMAP_RTC_CTRL_REG);
return 0;
fail0:
if (id_entry->driver_data & OMAP_RTC_HAS_KICKER)
rtc_writel(0, OMAP_RTC_KICK0_REG);
pm_runtime_put_sync(&pdev->dev);
pm_runtime_disable(&pdev->dev);
return -EIO;
}
static int __exit omap_rtc_remove(struct platform_device *pdev)
{
const struct platform_device_id *id_entry =
platform_get_device_id(pdev);
device_init_wakeup(&pdev->dev, 0);
rtc_write(0, OMAP_RTC_INTERRUPTS_REG);
if (id_entry->driver_data & OMAP_RTC_HAS_KICKER)
rtc_writel(0, OMAP_RTC_KICK0_REG);
pm_runtime_put_sync(&pdev->dev);
pm_runtime_disable(&pdev->dev);
return 0;
}
static int omap_rtc_suspend(struct device *dev)
{
irqstat = rtc_read(OMAP_RTC_INTERRUPTS_REG);
if (device_may_wakeup(dev))
enable_irq_wake(omap_rtc_alarm);
else
rtc_write(0, OMAP_RTC_INTERRUPTS_REG);
pm_runtime_put_sync(dev);
return 0;
}
static int omap_rtc_resume(struct device *dev)
{
pm_runtime_get_sync(dev);
if (device_may_wakeup(dev))
disable_irq_wake(omap_rtc_alarm);
else
rtc_write(irqstat, OMAP_RTC_INTERRUPTS_REG);
return 0;
}
static void omap_rtc_shutdown(struct platform_device *pdev)
{
rtc_write(0, OMAP_RTC_INTERRUPTS_REG);
}
