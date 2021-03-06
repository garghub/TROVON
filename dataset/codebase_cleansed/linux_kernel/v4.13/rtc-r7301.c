static u8 rtc7301_read(struct rtc7301_priv *priv, unsigned int reg)
{
int reg_stride = regmap_get_reg_stride(priv->regmap);
unsigned int val;
regmap_read(priv->regmap, reg_stride * reg, &val);
return val & 0xf;
}
static void rtc7301_write(struct rtc7301_priv *priv, u8 val, unsigned int reg)
{
int reg_stride = regmap_get_reg_stride(priv->regmap);
regmap_write(priv->regmap, reg_stride * reg, val);
}
static void rtc7301_update_bits(struct rtc7301_priv *priv, unsigned int reg,
u8 mask, u8 val)
{
int reg_stride = regmap_get_reg_stride(priv->regmap);
regmap_update_bits(priv->regmap, reg_stride * reg, mask, val);
}
static int rtc7301_wait_while_busy(struct rtc7301_priv *priv)
{
int retries = 100;
while (retries-- > 0) {
u8 val;
val = rtc7301_read(priv, RTC7301_CONTROL);
if (!(val & RTC7301_CONTROL_BUSY))
return 0;
usleep_range(200, 300);
}
return -ETIMEDOUT;
}
static void rtc7301_stop(struct rtc7301_priv *priv)
{
rtc7301_update_bits(priv, RTC7301_CONTROL, RTC7301_CONTROL_STOP,
RTC7301_CONTROL_STOP);
}
static void rtc7301_start(struct rtc7301_priv *priv)
{
rtc7301_update_bits(priv, RTC7301_CONTROL, RTC7301_CONTROL_STOP, 0);
}
static void rtc7301_select_bank(struct rtc7301_priv *priv, u8 bank)
{
u8 val = 0;
if (bank == priv->bank)
return;
if (bank & BIT(0))
val |= RTC7301_CONTROL_BANK_SEL_0;
if (bank & BIT(1))
val |= RTC7301_CONTROL_BANK_SEL_1;
rtc7301_update_bits(priv, RTC7301_CONTROL,
RTC7301_CONTROL_BANK_SEL_0 |
RTC7301_CONTROL_BANK_SEL_1, val);
priv->bank = bank;
}
static void rtc7301_get_time(struct rtc7301_priv *priv, struct rtc_time *tm,
bool alarm)
{
int year;
tm->tm_sec = rtc7301_read(priv, RTC7301_1_SEC);
tm->tm_sec += (rtc7301_read(priv, RTC7301_10_SEC) & ~RTC7301_AE) * 10;
tm->tm_min = rtc7301_read(priv, RTC7301_1_MIN);
tm->tm_min += (rtc7301_read(priv, RTC7301_10_MIN) & ~RTC7301_AE) * 10;
tm->tm_hour = rtc7301_read(priv, RTC7301_1_HOUR);
tm->tm_hour += (rtc7301_read(priv, RTC7301_10_HOUR) & ~RTC7301_AE) * 10;
tm->tm_mday = rtc7301_read(priv, RTC7301_1_DAY);
tm->tm_mday += (rtc7301_read(priv, RTC7301_10_DAY) & ~RTC7301_AE) * 10;
if (alarm) {
tm->tm_wday = -1;
tm->tm_mon = -1;
tm->tm_year = -1;
tm->tm_yday = -1;
tm->tm_isdst = -1;
return;
}
tm->tm_wday = (rtc7301_read(priv, RTC7301_DAY_OF_WEEK) & ~RTC7301_AE);
tm->tm_mon = rtc7301_read(priv, RTC7301_10_MONTH) * 10 +
rtc7301_read(priv, RTC7301_1_MONTH) - 1;
year = rtc7301_read(priv, RTC7301_1000_YEAR) * 1000 +
rtc7301_read(priv, RTC7301_100_YEAR) * 100 +
rtc7301_read(priv, RTC7301_10_YEAR) * 10 +
rtc7301_read(priv, RTC7301_1_YEAR);
tm->tm_year = year - 1900;
}
static void rtc7301_write_time(struct rtc7301_priv *priv, struct rtc_time *tm,
bool alarm)
{
int year;
rtc7301_write(priv, tm->tm_sec % 10, RTC7301_1_SEC);
rtc7301_write(priv, tm->tm_sec / 10, RTC7301_10_SEC);
rtc7301_write(priv, tm->tm_min % 10, RTC7301_1_MIN);
rtc7301_write(priv, tm->tm_min / 10, RTC7301_10_MIN);
rtc7301_write(priv, tm->tm_hour % 10, RTC7301_1_HOUR);
rtc7301_write(priv, tm->tm_hour / 10, RTC7301_10_HOUR);
rtc7301_write(priv, tm->tm_mday % 10, RTC7301_1_DAY);
rtc7301_write(priv, tm->tm_mday / 10, RTC7301_10_DAY);
rtc7301_write(priv, alarm ? RTC7301_AE : tm->tm_wday,
RTC7301_DAY_OF_WEEK);
if (alarm)
return;
rtc7301_write(priv, (tm->tm_mon + 1) % 10, RTC7301_1_MONTH);
rtc7301_write(priv, (tm->tm_mon + 1) / 10, RTC7301_10_MONTH);
year = tm->tm_year + 1900;
rtc7301_write(priv, year % 10, RTC7301_1_YEAR);
rtc7301_write(priv, (year / 10) % 10, RTC7301_10_YEAR);
rtc7301_write(priv, (year / 100) % 10, RTC7301_100_YEAR);
rtc7301_write(priv, year / 1000, RTC7301_1000_YEAR);
}
static void rtc7301_alarm_irq(struct rtc7301_priv *priv, unsigned int enabled)
{
rtc7301_update_bits(priv, RTC7301_ALARM_CONTROL,
RTC7301_ALARM_CONTROL_AF |
RTC7301_ALARM_CONTROL_AIE,
enabled ? RTC7301_ALARM_CONTROL_AIE : 0);
}
static int rtc7301_read_time(struct device *dev, struct rtc_time *tm)
{
struct rtc7301_priv *priv = dev_get_drvdata(dev);
unsigned long flags;
int err;
spin_lock_irqsave(&priv->lock, flags);
rtc7301_select_bank(priv, 0);
err = rtc7301_wait_while_busy(priv);
if (!err)
rtc7301_get_time(priv, tm, false);
spin_unlock_irqrestore(&priv->lock, flags);
return err ? err : rtc_valid_tm(tm);
}
static int rtc7301_set_time(struct device *dev, struct rtc_time *tm)
{
struct rtc7301_priv *priv = dev_get_drvdata(dev);
unsigned long flags;
spin_lock_irqsave(&priv->lock, flags);
rtc7301_stop(priv);
usleep_range(200, 300);
rtc7301_select_bank(priv, 0);
rtc7301_write_time(priv, tm, false);
rtc7301_start(priv);
spin_unlock_irqrestore(&priv->lock, flags);
return 0;
}
static int rtc7301_read_alarm(struct device *dev, struct rtc_wkalrm *alarm)
{
struct rtc7301_priv *priv = dev_get_drvdata(dev);
unsigned long flags;
u8 alrm_ctrl;
if (priv->irq <= 0)
return -EINVAL;
spin_lock_irqsave(&priv->lock, flags);
rtc7301_select_bank(priv, 1);
rtc7301_get_time(priv, &alarm->time, true);
alrm_ctrl = rtc7301_read(priv, RTC7301_ALARM_CONTROL);
alarm->enabled = !!(alrm_ctrl & RTC7301_ALARM_CONTROL_AIE);
alarm->pending = !!(alrm_ctrl & RTC7301_ALARM_CONTROL_AF);
spin_unlock_irqrestore(&priv->lock, flags);
return 0;
}
static int rtc7301_set_alarm(struct device *dev, struct rtc_wkalrm *alarm)
{
struct rtc7301_priv *priv = dev_get_drvdata(dev);
unsigned long flags;
if (priv->irq <= 0)
return -EINVAL;
spin_lock_irqsave(&priv->lock, flags);
rtc7301_select_bank(priv, 1);
rtc7301_write_time(priv, &alarm->time, true);
rtc7301_alarm_irq(priv, alarm->enabled);
spin_unlock_irqrestore(&priv->lock, flags);
return 0;
}
static int rtc7301_alarm_irq_enable(struct device *dev, unsigned int enabled)
{
struct rtc7301_priv *priv = dev_get_drvdata(dev);
unsigned long flags;
if (priv->irq <= 0)
return -EINVAL;
spin_lock_irqsave(&priv->lock, flags);
rtc7301_select_bank(priv, 1);
rtc7301_alarm_irq(priv, enabled);
spin_unlock_irqrestore(&priv->lock, flags);
return 0;
}
static irqreturn_t rtc7301_irq_handler(int irq, void *dev_id)
{
struct rtc_device *rtc = dev_id;
struct rtc7301_priv *priv = dev_get_drvdata(rtc->dev.parent);
unsigned long flags;
irqreturn_t ret = IRQ_NONE;
u8 alrm_ctrl;
spin_lock_irqsave(&priv->lock, flags);
rtc7301_select_bank(priv, 1);
alrm_ctrl = rtc7301_read(priv, RTC7301_ALARM_CONTROL);
if (alrm_ctrl & RTC7301_ALARM_CONTROL_AF) {
ret = IRQ_HANDLED;
rtc7301_alarm_irq(priv, false);
rtc_update_irq(rtc, 1, RTC_IRQF | RTC_AF);
}
spin_unlock_irqrestore(&priv->lock, flags);
return ret;
}
static void rtc7301_init(struct rtc7301_priv *priv)
{
unsigned long flags;
spin_lock_irqsave(&priv->lock, flags);
rtc7301_select_bank(priv, 2);
rtc7301_write(priv, 0, RTC7301_TIMER_CONTROL);
spin_unlock_irqrestore(&priv->lock, flags);
}
static int __init rtc7301_rtc_probe(struct platform_device *dev)
{
struct resource *res;
void __iomem *regs;
struct rtc7301_priv *priv;
struct rtc_device *rtc;
int ret;
res = platform_get_resource(dev, IORESOURCE_MEM, 0);
if (!res)
return -ENODEV;
priv = devm_kzalloc(&dev->dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
regs = devm_ioremap_resource(&dev->dev, res);
if (IS_ERR(regs))
return PTR_ERR(regs);
priv->regmap = devm_regmap_init_mmio(&dev->dev, regs,
&rtc7301_regmap_config);
if (IS_ERR(priv->regmap))
return PTR_ERR(priv->regmap);
priv->irq = platform_get_irq(dev, 0);
spin_lock_init(&priv->lock);
priv->bank = -1;
rtc7301_init(priv);
platform_set_drvdata(dev, priv);
rtc = devm_rtc_device_register(&dev->dev, DRV_NAME, &rtc7301_rtc_ops,
THIS_MODULE);
if (IS_ERR(rtc))
return PTR_ERR(rtc);
if (priv->irq > 0) {
ret = devm_request_irq(&dev->dev, priv->irq,
rtc7301_irq_handler, IRQF_SHARED,
dev_name(&dev->dev), rtc);
if (ret) {
priv->irq = 0;
dev_err(&dev->dev, "unable to request IRQ\n");
} else {
device_set_wakeup_capable(&dev->dev, true);
}
}
return 0;
}
static int rtc7301_suspend(struct device *dev)
{
struct rtc7301_priv *priv = dev_get_drvdata(dev);
if (device_may_wakeup(dev))
enable_irq_wake(priv->irq);
return 0;
}
static int rtc7301_resume(struct device *dev)
{
struct rtc7301_priv *priv = dev_get_drvdata(dev);
if (device_may_wakeup(dev))
disable_irq_wake(priv->irq);
return 0;
}
