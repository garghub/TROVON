unsigned char
pcf8563_readreg(int reg)
{
unsigned char res = rtc_read(reg);
switch (reg) {
case RTC_SECONDS:
case RTC_MINUTES:
res &= 0x7F;
break;
case RTC_HOURS:
case RTC_DAY_OF_MONTH:
res &= 0x3F;
break;
case RTC_WEEKDAY:
res &= 0x07;
break;
case RTC_MONTH:
res &= 0x1F;
break;
case RTC_CONTROL1:
res &= 0xA8;
break;
case RTC_CONTROL2:
res &= 0x1F;
break;
case RTC_CLOCKOUT_FREQ:
case RTC_TIMER_CONTROL:
res &= 0x83;
break;
}
return res;
}
void
pcf8563_writereg(int reg, unsigned char val)
{
rtc_write(reg, val);
}
void
get_rtc_time(struct rtc_time *tm)
{
tm->tm_sec = rtc_read(RTC_SECONDS);
tm->tm_min = rtc_read(RTC_MINUTES);
tm->tm_hour = rtc_read(RTC_HOURS);
tm->tm_mday = rtc_read(RTC_DAY_OF_MONTH);
tm->tm_wday = rtc_read(RTC_WEEKDAY);
tm->tm_mon = rtc_read(RTC_MONTH);
tm->tm_year = rtc_read(RTC_YEAR);
if (tm->tm_sec & 0x80) {
printk(KERN_ERR "%s: RTC Voltage Low - reliable date/time "
"information is no longer guaranteed!\n", PCF8563_NAME);
}
tm->tm_year = bcd2bin(tm->tm_year) +
((tm->tm_mon & 0x80) ? 100 : 0);
tm->tm_sec &= 0x7F;
tm->tm_min &= 0x7F;
tm->tm_hour &= 0x3F;
tm->tm_mday &= 0x3F;
tm->tm_wday &= 0x07;
tm->tm_mon &= 0x1F;
tm->tm_sec = bcd2bin(tm->tm_sec);
tm->tm_min = bcd2bin(tm->tm_min);
tm->tm_hour = bcd2bin(tm->tm_hour);
tm->tm_mday = bcd2bin(tm->tm_mday);
tm->tm_mon = bcd2bin(tm->tm_mon);
tm->tm_mon--;
}
int __init
pcf8563_init(void)
{
static int res;
static int first = 1;
if (!first)
return res;
first = 0;
res = i2c_init();
if (res < 0) {
printk(KERN_CRIT "pcf8563_init: Failed to init i2c.\n");
return res;
}
if (rtc_write(RTC_CONTROL1, 0x00) < 0)
goto err;
if (rtc_write(RTC_CONTROL2, 0x00) < 0)
goto err;
if (rtc_write(RTC_CLOCKOUT_FREQ, 0x00) < 0)
goto err;
if (rtc_write(RTC_TIMER_CONTROL, 0x03) < 0)
goto err;
if (rtc_write(RTC_MINUTE_ALARM, 0x80) < 0)
goto err;
if (rtc_write(RTC_HOUR_ALARM, 0x80) < 0)
goto err;
if (rtc_write(RTC_DAY_ALARM, 0x80) < 0)
goto err;
if (rtc_write(RTC_WEEKDAY_ALARM, 0x80) < 0)
goto err;
if (rtc_read(RTC_SECONDS) & 0x80) {
voltage_low = 1;
printk(KERN_WARNING "%s: RTC Voltage Low - reliable "
"date/time information is no longer guaranteed!\n",
PCF8563_NAME);
}
return res;
err:
printk(KERN_INFO "%s: Error initializing chip.\n", PCF8563_NAME);
res = -1;
return res;
}
void __exit
pcf8563_exit(void)
{
unregister_chrdev(PCF8563_MAJOR, DEVICE_NAME);
}
static int pcf8563_ioctl(struct file *filp, unsigned int cmd, unsigned long arg)
{
if (_IOC_TYPE(cmd) != RTC_MAGIC)
return -ENOTTY;
if (_IOC_NR(cmd) > RTC_MAX_IOCTL)
return -ENOTTY;
switch (cmd) {
case RTC_RD_TIME:
{
struct rtc_time tm;
mutex_lock(&rtc_lock);
memset(&tm, 0, sizeof tm);
get_rtc_time(&tm);
if (copy_to_user((struct rtc_time *) arg, &tm,
sizeof tm)) {
mutex_unlock(&rtc_lock);
return -EFAULT;
}
mutex_unlock(&rtc_lock);
return 0;
}
case RTC_SET_TIME:
{
int leap;
int year;
int century;
struct rtc_time tm;
memset(&tm, 0, sizeof tm);
if (!capable(CAP_SYS_TIME))
return -EPERM;
if (copy_from_user(&tm, (struct rtc_time *) arg, sizeof tm))
return -EFAULT;
tm.tm_year += 1900;
tm.tm_mon += 1;
year = tm.tm_year;
leap = (tm.tm_mon == 2) &&
((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
if ((tm.tm_year < 1970) ||
(tm.tm_mon > 12) ||
(tm.tm_mday == 0) ||
(tm.tm_mday > days_in_month[tm.tm_mon] + leap) ||
(tm.tm_wday >= 7) ||
(tm.tm_hour >= 24) ||
(tm.tm_min >= 60) ||
(tm.tm_sec >= 60))
return -EINVAL;
century = (tm.tm_year >= 2000) ? 0x80 : 0;
tm.tm_year = tm.tm_year % 100;
tm.tm_year = bin2bcd(tm.tm_year);
tm.tm_mon = bin2bcd(tm.tm_mon);
tm.tm_mday = bin2bcd(tm.tm_mday);
tm.tm_hour = bin2bcd(tm.tm_hour);
tm.tm_min = bin2bcd(tm.tm_min);
tm.tm_sec = bin2bcd(tm.tm_sec);
tm.tm_mon |= century;
mutex_lock(&rtc_lock);
rtc_write(RTC_YEAR, tm.tm_year);
rtc_write(RTC_MONTH, tm.tm_mon);
rtc_write(RTC_WEEKDAY, tm.tm_wday);
rtc_write(RTC_DAY_OF_MONTH, tm.tm_mday);
rtc_write(RTC_HOURS, tm.tm_hour);
rtc_write(RTC_MINUTES, tm.tm_min);
rtc_write(RTC_SECONDS, tm.tm_sec);
mutex_unlock(&rtc_lock);
return 0;
}
case RTC_VL_READ:
if (voltage_low) {
printk(KERN_ERR "%s: RTC Voltage Low - "
"reliable date/time information is no "
"longer guaranteed!\n", PCF8563_NAME);
}
if (copy_to_user((int *) arg, &voltage_low, sizeof(int)))
return -EFAULT;
return 0;
case RTC_VL_CLR:
{
int ret = rtc_read(RTC_SECONDS);
rtc_write(RTC_SECONDS, (ret & 0x7F));
voltage_low = 0;
return 0;
}
default:
return -ENOTTY;
}
return 0;
}
static long pcf8563_unlocked_ioctl(struct file *filp, unsigned int cmd, unsigned long arg)
{
int ret;
mutex_lock(&pcf8563_mutex);
ret = pcf8563_ioctl(filp, cmd, arg);
mutex_unlock(&pcf8563_mutex);
return ret;
}
static int __init pcf8563_register(void)
{
if (pcf8563_init() < 0) {
printk(KERN_INFO "%s: Unable to initialize Real-Time Clock "
"Driver, %s\n", PCF8563_NAME, DRIVER_VERSION);
return -1;
}
if (register_chrdev(PCF8563_MAJOR, DEVICE_NAME, &pcf8563_fops) < 0) {
printk(KERN_INFO "%s: Unable to get major number %d for RTC device.\n",
PCF8563_NAME, PCF8563_MAJOR);
return -1;
}
printk(KERN_INFO "%s Real-Time Clock Driver, %s\n", PCF8563_NAME,
DRIVER_VERSION);
if (voltage_low) {
printk(KERN_WARNING "%s: RTC Voltage Low - reliable date/time "
"information is no longer guaranteed!\n", PCF8563_NAME);
}
return 0;
}
