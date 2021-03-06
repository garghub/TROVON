static inline void spear_rtc_clear_interrupt(struct spear_rtc_config *config)
{
unsigned int val;
unsigned long flags;
spin_lock_irqsave(&config->lock, flags);
val = readl(config->ioaddr + STATUS_REG);
val |= RTC_INT_MASK;
writel(val, config->ioaddr + STATUS_REG);
spin_unlock_irqrestore(&config->lock, flags);
}
static inline void spear_rtc_enable_interrupt(struct spear_rtc_config *config)
{
unsigned int val;
val = readl(config->ioaddr + CTRL_REG);
if (!(val & INT_ENABLE)) {
spear_rtc_clear_interrupt(config);
val |= INT_ENABLE;
writel(val, config->ioaddr + CTRL_REG);
}
}
static inline void spear_rtc_disable_interrupt(struct spear_rtc_config *config)
{
unsigned int val;
val = readl(config->ioaddr + CTRL_REG);
if (val & INT_ENABLE) {
val &= ~INT_ENABLE;
writel(val, config->ioaddr + CTRL_REG);
}
}
static inline int is_write_complete(struct spear_rtc_config *config)
{
int ret = 0;
unsigned long flags;
spin_lock_irqsave(&config->lock, flags);
if ((readl(config->ioaddr + STATUS_REG)) & STATUS_FAIL)
ret = -EIO;
spin_unlock_irqrestore(&config->lock, flags);
return ret;
}
static void rtc_wait_not_busy(struct spear_rtc_config *config)
{
int status, count = 0;
unsigned long flags;
for (count = 0; count < 80; count++) {
spin_lock_irqsave(&config->lock, flags);
status = readl(config->ioaddr + STATUS_REG);
spin_unlock_irqrestore(&config->lock, flags);
if ((status & STATUS_BUSY) == 0)
break;
msleep(1);
}
}
static irqreturn_t spear_rtc_irq(int irq, void *dev_id)
{
struct rtc_device *rtc = (struct rtc_device *)dev_id;
struct spear_rtc_config *config = dev_get_drvdata(&rtc->dev);
unsigned long flags, events = 0;
unsigned int irq_data;
spin_lock_irqsave(&config->lock, flags);
irq_data = readl(config->ioaddr + STATUS_REG);
spin_unlock_irqrestore(&config->lock, flags);
if ((irq_data & RTC_INT_MASK)) {
spear_rtc_clear_interrupt(config);
events = RTC_IRQF | RTC_AF;
rtc_update_irq(rtc, 1, events);
return IRQ_HANDLED;
} else
return IRQ_NONE;
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
tm->tm_year = bin2bcd(tm->tm_year);
return 0;
}
static void bcd2tm(struct rtc_time *tm)
{
tm->tm_sec = bcd2bin(tm->tm_sec);
tm->tm_min = bcd2bin(tm->tm_min);
tm->tm_hour = bcd2bin(tm->tm_hour);
tm->tm_mday = bcd2bin(tm->tm_mday);
tm->tm_mon = bcd2bin(tm->tm_mon) - 1;
tm->tm_year = bcd2bin(tm->tm_year);
}
static int spear_rtc_read_time(struct device *dev, struct rtc_time *tm)
{
struct platform_device *pdev = to_platform_device(dev);
struct rtc_device *rtc = platform_get_drvdata(pdev);
struct spear_rtc_config *config = dev_get_drvdata(&rtc->dev);
unsigned int time, date;
rtc_wait_not_busy(config);
time = readl(config->ioaddr + TIME_REG);
date = readl(config->ioaddr + DATE_REG);
tm->tm_sec = (time >> SECOND_SHIFT) & SECOND_MASK;
tm->tm_min = (time >> MINUTE_SHIFT) & MIN_MASK;
tm->tm_hour = (time >> HOUR_SHIFT) & HOUR_MASK;
tm->tm_mday = (date >> MDAY_SHIFT) & DAY_MASK;
tm->tm_mon = (date >> MONTH_SHIFT) & MONTH_MASK;
tm->tm_year = (date >> YEAR_SHIFT) & YEAR_MASK;
bcd2tm(tm);
return 0;
}
static int spear_rtc_set_time(struct device *dev, struct rtc_time *tm)
{
struct platform_device *pdev = to_platform_device(dev);
struct rtc_device *rtc = platform_get_drvdata(pdev);
struct spear_rtc_config *config = dev_get_drvdata(&rtc->dev);
unsigned int time, date, err = 0;
if (tm2bcd(tm) < 0)
return -EINVAL;
rtc_wait_not_busy(config);
time = (tm->tm_sec << SECOND_SHIFT) | (tm->tm_min << MINUTE_SHIFT) |
(tm->tm_hour << HOUR_SHIFT);
date = (tm->tm_mday << MDAY_SHIFT) | (tm->tm_mon << MONTH_SHIFT) |
(tm->tm_year << YEAR_SHIFT);
writel(time, config->ioaddr + TIME_REG);
writel(date, config->ioaddr + DATE_REG);
err = is_write_complete(config);
if (err < 0)
return err;
return 0;
}
static int spear_rtc_read_alarm(struct device *dev, struct rtc_wkalrm *alm)
{
struct platform_device *pdev = to_platform_device(dev);
struct rtc_device *rtc = platform_get_drvdata(pdev);
struct spear_rtc_config *config = dev_get_drvdata(&rtc->dev);
unsigned int time, date;
rtc_wait_not_busy(config);
time = readl(config->ioaddr + ALARM_TIME_REG);
date = readl(config->ioaddr + ALARM_DATE_REG);
alm->time.tm_sec = (time >> SECOND_SHIFT) & SECOND_MASK;
alm->time.tm_min = (time >> MINUTE_SHIFT) & MIN_MASK;
alm->time.tm_hour = (time >> HOUR_SHIFT) & HOUR_MASK;
alm->time.tm_mday = (date >> MDAY_SHIFT) & DAY_MASK;
alm->time.tm_mon = (date >> MONTH_SHIFT) & MONTH_MASK;
alm->time.tm_year = (date >> YEAR_SHIFT) & YEAR_MASK;
bcd2tm(&alm->time);
alm->enabled = readl(config->ioaddr + CTRL_REG) & INT_ENABLE;
return 0;
}
static int spear_rtc_set_alarm(struct device *dev, struct rtc_wkalrm *alm)
{
struct platform_device *pdev = to_platform_device(dev);
struct rtc_device *rtc = platform_get_drvdata(pdev);
struct spear_rtc_config *config = dev_get_drvdata(&rtc->dev);
unsigned int time, date, err = 0;
if (tm2bcd(&alm->time) < 0)
return -EINVAL;
rtc_wait_not_busy(config);
time = (alm->time.tm_sec << SECOND_SHIFT) | (alm->time.tm_min <<
MINUTE_SHIFT) | (alm->time.tm_hour << HOUR_SHIFT);
date = (alm->time.tm_mday << MDAY_SHIFT) | (alm->time.tm_mon <<
MONTH_SHIFT) | (alm->time.tm_year << YEAR_SHIFT);
writel(time, config->ioaddr + ALARM_TIME_REG);
writel(date, config->ioaddr + ALARM_DATE_REG);
err = is_write_complete(config);
if (err < 0)
return err;
if (alm->enabled)
spear_rtc_enable_interrupt(config);
else
spear_rtc_disable_interrupt(config);
return 0;
}
static int __devinit spear_rtc_probe(struct platform_device *pdev)
{
struct resource *res;
struct rtc_device *rtc;
struct spear_rtc_config *config;
unsigned int status = 0;
int irq;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(&pdev->dev, "no resource defined\n");
return -EBUSY;
}
if (!request_mem_region(res->start, resource_size(res), pdev->name)) {
dev_err(&pdev->dev, "rtc region already claimed\n");
return -EBUSY;
}
config = kzalloc(sizeof(*config), GFP_KERNEL);
if (!config) {
dev_err(&pdev->dev, "out of memory\n");
status = -ENOMEM;
goto err_release_region;
}
config->clk = clk_get(&pdev->dev, NULL);
if (IS_ERR(config->clk)) {
status = PTR_ERR(config->clk);
goto err_kfree;
}
status = clk_enable(config->clk);
if (status < 0)
goto err_clk_put;
config->ioaddr = ioremap(res->start, resource_size(res));
if (!config->ioaddr) {
dev_err(&pdev->dev, "ioremap fail\n");
status = -ENOMEM;
goto err_disable_clock;
}
spin_lock_init(&config->lock);
rtc = rtc_device_register(pdev->name, &pdev->dev, &spear_rtc_ops,
THIS_MODULE);
if (IS_ERR(rtc)) {
dev_err(&pdev->dev, "can't register RTC device, err %ld\n",
PTR_ERR(rtc));
status = PTR_ERR(rtc);
goto err_iounmap;
}
platform_set_drvdata(pdev, rtc);
dev_set_drvdata(&rtc->dev, config);
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_err(&pdev->dev, "no update irq?\n");
status = irq;
goto err_clear_platdata;
}
status = request_irq(irq, spear_rtc_irq, 0, pdev->name, rtc);
if (status) {
dev_err(&pdev->dev, "Alarm interrupt IRQ%d already \
claimed\n", irq);
goto err_clear_platdata;
}
if (!device_can_wakeup(&pdev->dev))
device_init_wakeup(&pdev->dev, 1);
return 0;
err_clear_platdata:
platform_set_drvdata(pdev, NULL);
dev_set_drvdata(&rtc->dev, NULL);
rtc_device_unregister(rtc);
err_iounmap:
iounmap(config->ioaddr);
err_disable_clock:
clk_disable(config->clk);
err_clk_put:
clk_put(config->clk);
err_kfree:
kfree(config);
err_release_region:
release_mem_region(res->start, resource_size(res));
return status;
}
static int __devexit spear_rtc_remove(struct platform_device *pdev)
{
struct rtc_device *rtc = platform_get_drvdata(pdev);
struct spear_rtc_config *config = dev_get_drvdata(&rtc->dev);
int irq;
struct resource *res;
spear_rtc_disable_interrupt(config);
device_init_wakeup(&pdev->dev, 0);
irq = platform_get_irq(pdev, 0);
if (irq)
free_irq(irq, pdev);
clk_disable(config->clk);
clk_put(config->clk);
iounmap(config->ioaddr);
kfree(config);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (res)
release_mem_region(res->start, resource_size(res));
platform_set_drvdata(pdev, NULL);
dev_set_drvdata(&rtc->dev, NULL);
rtc_device_unregister(rtc);
return 0;
}
static int spear_rtc_suspend(struct platform_device *pdev, pm_message_t state)
{
struct rtc_device *rtc = platform_get_drvdata(pdev);
struct spear_rtc_config *config = dev_get_drvdata(&rtc->dev);
int irq;
irq = platform_get_irq(pdev, 0);
if (device_may_wakeup(&pdev->dev))
enable_irq_wake(irq);
else {
spear_rtc_disable_interrupt(config);
clk_disable(config->clk);
}
return 0;
}
static int spear_rtc_resume(struct platform_device *pdev)
{
struct rtc_device *rtc = platform_get_drvdata(pdev);
struct spear_rtc_config *config = dev_get_drvdata(&rtc->dev);
int irq;
irq = platform_get_irq(pdev, 0);
if (device_may_wakeup(&pdev->dev))
disable_irq_wake(irq);
else {
clk_enable(config->clk);
spear_rtc_enable_interrupt(config);
}
return 0;
}
static void spear_rtc_shutdown(struct platform_device *pdev)
{
struct rtc_device *rtc = platform_get_drvdata(pdev);
struct spear_rtc_config *config = dev_get_drvdata(&rtc->dev);
spear_rtc_disable_interrupt(config);
clk_disable(config->clk);
}
