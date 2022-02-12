static inline u8 ds1286_rtc_read(struct ds1286_priv *priv, int reg)
{
return __raw_readl(&priv->rtcregs[reg]) & 0xff;
}
static inline void ds1286_rtc_write(struct ds1286_priv *priv, u8 data, int reg)
{
__raw_writel(data, &priv->rtcregs[reg]);
}
static int ds1286_alarm_irq_enable(struct device *dev, unsigned int enabled)
{
struct ds1286_priv *priv = dev_get_drvdata(dev);
unsigned long flags;
unsigned char val;
spin_lock_irqsave(&priv->lock, flags);
val = ds1286_rtc_read(priv, RTC_CMD);
if (enabled)
val &= ~RTC_TDM;
else
val |= RTC_TDM;
ds1286_rtc_write(priv, val, RTC_CMD);
spin_unlock_irqrestore(&priv->lock, flags);
return 0;
}
static int ds1286_ioctl(struct device *dev, unsigned int cmd, unsigned long arg)
{
struct ds1286_priv *priv = dev_get_drvdata(dev);
unsigned long flags;
unsigned char val;
switch (cmd) {
case RTC_WIE_OFF:
spin_lock_irqsave(&priv->lock, flags);
val = ds1286_rtc_read(priv, RTC_CMD);
val |= RTC_WAM;
ds1286_rtc_write(priv, val, RTC_CMD);
spin_unlock_irqrestore(&priv->lock, flags);
break;
case RTC_WIE_ON:
spin_lock_irqsave(&priv->lock, flags);
val = ds1286_rtc_read(priv, RTC_CMD);
val &= ~RTC_WAM;
ds1286_rtc_write(priv, val, RTC_CMD);
spin_unlock_irqrestore(&priv->lock, flags);
break;
default:
return -ENOIOCTLCMD;
}
return 0;
}
static int ds1286_proc(struct device *dev, struct seq_file *seq)
{
struct ds1286_priv *priv = dev_get_drvdata(dev);
unsigned char month, cmd, amode;
const char *s;
month = ds1286_rtc_read(priv, RTC_MONTH);
seq_printf(seq,
"oscillator\t: %s\n"
"square_wave\t: %s\n",
(month & RTC_EOSC) ? "disabled" : "enabled",
(month & RTC_ESQW) ? "disabled" : "enabled");
amode = ((ds1286_rtc_read(priv, RTC_MINUTES_ALARM) & 0x80) >> 5) |
((ds1286_rtc_read(priv, RTC_HOURS_ALARM) & 0x80) >> 6) |
((ds1286_rtc_read(priv, RTC_DAY_ALARM) & 0x80) >> 7);
switch (amode) {
case 7:
s = "each minute";
break;
case 3:
s = "minutes match";
break;
case 1:
s = "hours and minutes match";
break;
case 0:
s = "days, hours and minutes match";
break;
default:
s = "invalid";
break;
}
seq_printf(seq, "alarm_mode\t: %s\n", s);
cmd = ds1286_rtc_read(priv, RTC_CMD);
seq_printf(seq,
"alarm_enable\t: %s\n"
"wdog_alarm\t: %s\n"
"alarm_mask\t: %s\n"
"wdog_alarm_mask\t: %s\n"
"interrupt_mode\t: %s\n"
"INTB_mode\t: %s_active\n"
"interrupt_pins\t: %s\n",
(cmd & RTC_TDF) ? "yes" : "no",
(cmd & RTC_WAF) ? "yes" : "no",
(cmd & RTC_TDM) ? "disabled" : "enabled",
(cmd & RTC_WAM) ? "disabled" : "enabled",
(cmd & RTC_PU_LVL) ? "pulse" : "level",
(cmd & RTC_IBH_LO) ? "low" : "high",
(cmd & RTC_IPSW) ? "unswapped" : "swapped");
return 0;
}
static int ds1286_read_time(struct device *dev, struct rtc_time *tm)
{
struct ds1286_priv *priv = dev_get_drvdata(dev);
unsigned char save_control;
unsigned long flags;
unsigned long uip_watchdog = jiffies;
if (ds1286_rtc_read(priv, RTC_CMD) & RTC_TE)
while (time_before(jiffies, uip_watchdog + 2*HZ/100))
barrier();
spin_lock_irqsave(&priv->lock, flags);
save_control = ds1286_rtc_read(priv, RTC_CMD);
ds1286_rtc_write(priv, (save_control|RTC_TE), RTC_CMD);
tm->tm_sec = ds1286_rtc_read(priv, RTC_SECONDS);
tm->tm_min = ds1286_rtc_read(priv, RTC_MINUTES);
tm->tm_hour = ds1286_rtc_read(priv, RTC_HOURS) & 0x3f;
tm->tm_mday = ds1286_rtc_read(priv, RTC_DATE);
tm->tm_mon = ds1286_rtc_read(priv, RTC_MONTH) & 0x1f;
tm->tm_year = ds1286_rtc_read(priv, RTC_YEAR);
ds1286_rtc_write(priv, save_control, RTC_CMD);
spin_unlock_irqrestore(&priv->lock, flags);
tm->tm_sec = bcd2bin(tm->tm_sec);
tm->tm_min = bcd2bin(tm->tm_min);
tm->tm_hour = bcd2bin(tm->tm_hour);
tm->tm_mday = bcd2bin(tm->tm_mday);
tm->tm_mon = bcd2bin(tm->tm_mon);
tm->tm_year = bcd2bin(tm->tm_year);
if (tm->tm_year < 45)
tm->tm_year += 30;
tm->tm_year += 40;
if (tm->tm_year < 70)
tm->tm_year += 100;
tm->tm_mon--;
return rtc_valid_tm(tm);
}
static int ds1286_set_time(struct device *dev, struct rtc_time *tm)
{
struct ds1286_priv *priv = dev_get_drvdata(dev);
unsigned char mon, day, hrs, min, sec;
unsigned char save_control;
unsigned int yrs;
unsigned long flags;
yrs = tm->tm_year + 1900;
mon = tm->tm_mon + 1;
day = tm->tm_mday;
hrs = tm->tm_hour;
min = tm->tm_min;
sec = tm->tm_sec;
if (yrs < 1970)
return -EINVAL;
yrs -= 1940;
if (yrs > 255)
return -EINVAL;
if (yrs >= 100)
yrs -= 100;
sec = bin2bcd(sec);
min = bin2bcd(min);
hrs = bin2bcd(hrs);
day = bin2bcd(day);
mon = bin2bcd(mon);
yrs = bin2bcd(yrs);
spin_lock_irqsave(&priv->lock, flags);
save_control = ds1286_rtc_read(priv, RTC_CMD);
ds1286_rtc_write(priv, (save_control|RTC_TE), RTC_CMD);
ds1286_rtc_write(priv, yrs, RTC_YEAR);
ds1286_rtc_write(priv, mon, RTC_MONTH);
ds1286_rtc_write(priv, day, RTC_DATE);
ds1286_rtc_write(priv, hrs, RTC_HOURS);
ds1286_rtc_write(priv, min, RTC_MINUTES);
ds1286_rtc_write(priv, sec, RTC_SECONDS);
ds1286_rtc_write(priv, 0, RTC_HUNDREDTH_SECOND);
ds1286_rtc_write(priv, save_control, RTC_CMD);
spin_unlock_irqrestore(&priv->lock, flags);
return 0;
}
static int ds1286_read_alarm(struct device *dev, struct rtc_wkalrm *alm)
{
struct ds1286_priv *priv = dev_get_drvdata(dev);
unsigned char cmd;
unsigned long flags;
spin_lock_irqsave(&priv->lock, flags);
alm->time.tm_min = ds1286_rtc_read(priv, RTC_MINUTES_ALARM) & 0x7f;
alm->time.tm_hour = ds1286_rtc_read(priv, RTC_HOURS_ALARM) & 0x1f;
alm->time.tm_wday = ds1286_rtc_read(priv, RTC_DAY_ALARM) & 0x07;
cmd = ds1286_rtc_read(priv, RTC_CMD);
spin_unlock_irqrestore(&priv->lock, flags);
alm->time.tm_min = bcd2bin(alm->time.tm_min);
alm->time.tm_hour = bcd2bin(alm->time.tm_hour);
alm->time.tm_sec = 0;
return 0;
}
static int ds1286_set_alarm(struct device *dev, struct rtc_wkalrm *alm)
{
struct ds1286_priv *priv = dev_get_drvdata(dev);
unsigned char hrs, min, sec;
hrs = alm->time.tm_hour;
min = alm->time.tm_min;
sec = alm->time.tm_sec;
if (hrs >= 24)
hrs = 0xff;
if (min >= 60)
min = 0xff;
if (sec != 0)
return -EINVAL;
min = bin2bcd(min);
hrs = bin2bcd(hrs);
spin_lock(&priv->lock);
ds1286_rtc_write(priv, hrs, RTC_HOURS_ALARM);
ds1286_rtc_write(priv, min, RTC_MINUTES_ALARM);
spin_unlock(&priv->lock);
return 0;
}
static int __devinit ds1286_probe(struct platform_device *pdev)
{
struct rtc_device *rtc;
struct resource *res;
struct ds1286_priv *priv;
int ret = 0;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res)
return -ENODEV;
priv = kzalloc(sizeof(struct ds1286_priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
priv->size = resource_size(res);
if (!request_mem_region(res->start, priv->size, pdev->name)) {
ret = -EBUSY;
goto out;
}
priv->baseaddr = res->start;
priv->rtcregs = ioremap(priv->baseaddr, priv->size);
if (!priv->rtcregs) {
ret = -ENOMEM;
goto out;
}
spin_lock_init(&priv->lock);
platform_set_drvdata(pdev, priv);
rtc = rtc_device_register("ds1286", &pdev->dev,
&ds1286_ops, THIS_MODULE);
if (IS_ERR(rtc)) {
ret = PTR_ERR(rtc);
goto out;
}
priv->rtc = rtc;
return 0;
out:
if (priv->rtc)
rtc_device_unregister(priv->rtc);
if (priv->rtcregs)
iounmap(priv->rtcregs);
if (priv->baseaddr)
release_mem_region(priv->baseaddr, priv->size);
kfree(priv);
return ret;
}
static int __devexit ds1286_remove(struct platform_device *pdev)
{
struct ds1286_priv *priv = platform_get_drvdata(pdev);
rtc_device_unregister(priv->rtc);
iounmap(priv->rtcregs);
release_mem_region(priv->baseaddr, priv->size);
kfree(priv);
return 0;
}
static int __init ds1286_init(void)
{
return platform_driver_register(&ds1286_platform_driver);
}
static void __exit ds1286_exit(void)
{
platform_driver_unregister(&ds1286_platform_driver);
}
