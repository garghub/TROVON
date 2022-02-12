static noinline void
rtc_write(uint8_t val, uint32_t reg)
{
writeb(val, ds1511_base + (reg * reg_spacing));
}
static inline void
rtc_write_alarm(uint8_t val, enum ds1511reg reg)
{
rtc_write((val | 0x80), reg);
}
static noinline uint8_t
rtc_read(enum ds1511reg reg)
{
return readb(ds1511_base + (reg * reg_spacing));
}
static inline void
rtc_disable_update(void)
{
rtc_write((rtc_read(RTC_CMD) & ~RTC_TE), RTC_CMD);
}
static void
rtc_enable_update(void)
{
rtc_write((rtc_read(RTC_CMD) | RTC_TE), RTC_CMD);
}
void
ds1511_wdog_set(unsigned long deciseconds)
{
deciseconds %= 10000;
rtc_write(bin2bcd(deciseconds % 100), DS1511_WD_MSEC);
rtc_write(bin2bcd(deciseconds / 100), DS1511_WD_SEC);
rtc_write(DS1511_WDE | DS1511_WDS, RTC_CMD);
}
void
ds1511_wdog_disable(void)
{
rtc_write(rtc_read(RTC_CMD) & ~(DS1511_WDE | DS1511_WDS), RTC_CMD);
rtc_write(0, DS1511_WD_MSEC);
rtc_write(0, DS1511_WD_SEC);
}
static int ds1511_rtc_set_time(struct device *dev, struct rtc_time *rtc_tm)
{
u8 mon, day, dow, hrs, min, sec, yrs, cen;
unsigned long flags;
if (rtc_tm->tm_year < 1900)
rtc_tm->tm_year += 1900;
if (rtc_tm->tm_year < 1970)
return -EINVAL;
yrs = rtc_tm->tm_year % 100;
cen = rtc_tm->tm_year / 100;
mon = rtc_tm->tm_mon + 1;
day = rtc_tm->tm_mday;
dow = rtc_tm->tm_wday & 0x7;
hrs = rtc_tm->tm_hour;
min = rtc_tm->tm_min;
sec = rtc_tm->tm_sec;
if ((mon > 12) || (day == 0))
return -EINVAL;
if (day > rtc_month_days(rtc_tm->tm_mon, rtc_tm->tm_year))
return -EINVAL;
if ((hrs >= 24) || (min >= 60) || (sec >= 60))
return -EINVAL;
sec = bin2bcd(sec) & 0x7f;
min = bin2bcd(min) & 0x7f;
hrs = bin2bcd(hrs) & 0x3f;
day = bin2bcd(day) & 0x3f;
mon = bin2bcd(mon) & 0x1f;
yrs = bin2bcd(yrs) & 0xff;
cen = bin2bcd(cen) & 0xff;
spin_lock_irqsave(&ds1511_lock, flags);
rtc_disable_update();
rtc_write(cen, RTC_CENTURY);
rtc_write(yrs, RTC_YEAR);
rtc_write((rtc_read(RTC_MON) & 0xe0) | mon, RTC_MON);
rtc_write(day, RTC_DOM);
rtc_write(hrs, RTC_HOUR);
rtc_write(min, RTC_MIN);
rtc_write(sec, RTC_SEC);
rtc_write(dow, RTC_DOW);
rtc_enable_update();
spin_unlock_irqrestore(&ds1511_lock, flags);
return 0;
}
static int ds1511_rtc_read_time(struct device *dev, struct rtc_time *rtc_tm)
{
unsigned int century;
unsigned long flags;
spin_lock_irqsave(&ds1511_lock, flags);
rtc_disable_update();
rtc_tm->tm_sec = rtc_read(RTC_SEC) & 0x7f;
rtc_tm->tm_min = rtc_read(RTC_MIN) & 0x7f;
rtc_tm->tm_hour = rtc_read(RTC_HOUR) & 0x3f;
rtc_tm->tm_mday = rtc_read(RTC_DOM) & 0x3f;
rtc_tm->tm_wday = rtc_read(RTC_DOW) & 0x7;
rtc_tm->tm_mon = rtc_read(RTC_MON) & 0x1f;
rtc_tm->tm_year = rtc_read(RTC_YEAR) & 0x7f;
century = rtc_read(RTC_CENTURY);
rtc_enable_update();
spin_unlock_irqrestore(&ds1511_lock, flags);
rtc_tm->tm_sec = bcd2bin(rtc_tm->tm_sec);
rtc_tm->tm_min = bcd2bin(rtc_tm->tm_min);
rtc_tm->tm_hour = bcd2bin(rtc_tm->tm_hour);
rtc_tm->tm_mday = bcd2bin(rtc_tm->tm_mday);
rtc_tm->tm_wday = bcd2bin(rtc_tm->tm_wday);
rtc_tm->tm_mon = bcd2bin(rtc_tm->tm_mon);
rtc_tm->tm_year = bcd2bin(rtc_tm->tm_year);
century = bcd2bin(century) * 100;
century += rtc_tm->tm_year;
rtc_tm->tm_year = century - 1900;
rtc_tm->tm_mon--;
if (rtc_valid_tm(rtc_tm) < 0) {
dev_err(dev, "retrieved date/time is not valid.\n");
rtc_time_to_tm(0, rtc_tm);
}
return 0;
}
static void
ds1511_rtc_update_alarm(struct rtc_plat_data *pdata)
{
unsigned long flags;
spin_lock_irqsave(&pdata->lock, flags);
rtc_write(pdata->alrm_mday < 0 || (pdata->irqen & RTC_UF) ?
0x80 : bin2bcd(pdata->alrm_mday) & 0x3f,
RTC_ALARM_DATE);
rtc_write(pdata->alrm_hour < 0 || (pdata->irqen & RTC_UF) ?
0x80 : bin2bcd(pdata->alrm_hour) & 0x3f,
RTC_ALARM_HOUR);
rtc_write(pdata->alrm_min < 0 || (pdata->irqen & RTC_UF) ?
0x80 : bin2bcd(pdata->alrm_min) & 0x7f,
RTC_ALARM_MIN);
rtc_write(pdata->alrm_sec < 0 || (pdata->irqen & RTC_UF) ?
0x80 : bin2bcd(pdata->alrm_sec) & 0x7f,
RTC_ALARM_SEC);
rtc_write(rtc_read(RTC_CMD) | (pdata->irqen ? RTC_TIE : 0), RTC_CMD);
rtc_read(RTC_CMD1);
spin_unlock_irqrestore(&pdata->lock, flags);
}
static int
ds1511_rtc_set_alarm(struct device *dev, struct rtc_wkalrm *alrm)
{
struct platform_device *pdev = to_platform_device(dev);
struct rtc_plat_data *pdata = platform_get_drvdata(pdev);
if (pdata->irq <= 0)
return -EINVAL;
pdata->alrm_mday = alrm->time.tm_mday;
pdata->alrm_hour = alrm->time.tm_hour;
pdata->alrm_min = alrm->time.tm_min;
pdata->alrm_sec = alrm->time.tm_sec;
if (alrm->enabled)
pdata->irqen |= RTC_AF;
ds1511_rtc_update_alarm(pdata);
return 0;
}
static int
ds1511_rtc_read_alarm(struct device *dev, struct rtc_wkalrm *alrm)
{
struct platform_device *pdev = to_platform_device(dev);
struct rtc_plat_data *pdata = platform_get_drvdata(pdev);
if (pdata->irq <= 0)
return -EINVAL;
alrm->time.tm_mday = pdata->alrm_mday < 0 ? 0 : pdata->alrm_mday;
alrm->time.tm_hour = pdata->alrm_hour < 0 ? 0 : pdata->alrm_hour;
alrm->time.tm_min = pdata->alrm_min < 0 ? 0 : pdata->alrm_min;
alrm->time.tm_sec = pdata->alrm_sec < 0 ? 0 : pdata->alrm_sec;
alrm->enabled = (pdata->irqen & RTC_AF) ? 1 : 0;
return 0;
}
static irqreturn_t
ds1511_interrupt(int irq, void *dev_id)
{
struct platform_device *pdev = dev_id;
struct rtc_plat_data *pdata = platform_get_drvdata(pdev);
unsigned long events = 0;
spin_lock(&pdata->lock);
if (rtc_read(RTC_CMD1) & DS1511_IRQF) {
events = RTC_IRQF;
if (rtc_read(RTC_ALARM_SEC) & 0x80)
events |= RTC_UF;
else
events |= RTC_AF;
if (likely(pdata->rtc))
rtc_update_irq(pdata->rtc, 1, events);
}
spin_unlock(&pdata->lock);
return events ? IRQ_HANDLED : IRQ_NONE;
}
static int ds1511_rtc_alarm_irq_enable(struct device *dev, unsigned int enabled)
{
struct platform_device *pdev = to_platform_device(dev);
struct rtc_plat_data *pdata = platform_get_drvdata(pdev);
if (pdata->irq <= 0)
return -EINVAL;
if (enabled)
pdata->irqen |= RTC_AF;
else
pdata->irqen &= ~RTC_AF;
ds1511_rtc_update_alarm(pdata);
return 0;
}
static ssize_t
ds1511_nvram_read(struct file *filp, struct kobject *kobj,
struct bin_attribute *ba,
char *buf, loff_t pos, size_t size)
{
ssize_t count;
if (size > 1)
rtc_write((rtc_read(RTC_CMD) | DS1511_BME), RTC_CMD);
if (pos > DS1511_RAM_MAX)
pos = DS1511_RAM_MAX;
if (size + pos > DS1511_RAM_MAX + 1)
size = DS1511_RAM_MAX - pos + 1;
rtc_write(pos, DS1511_RAMADDR_LSB);
for (count = 0; size > 0; count++, size--)
*buf++ = rtc_read(DS1511_RAMDATA);
if (count > 1)
rtc_write((rtc_read(RTC_CMD) & ~DS1511_BME), RTC_CMD);
return count;
}
static ssize_t
ds1511_nvram_write(struct file *filp, struct kobject *kobj,
struct bin_attribute *bin_attr,
char *buf, loff_t pos, size_t size)
{
ssize_t count;
if (size > 1)
rtc_write((rtc_read(RTC_CMD) | DS1511_BME), RTC_CMD);
if (pos > DS1511_RAM_MAX)
pos = DS1511_RAM_MAX;
if (size + pos > DS1511_RAM_MAX + 1)
size = DS1511_RAM_MAX - pos + 1;
rtc_write(pos, DS1511_RAMADDR_LSB);
for (count = 0; size > 0; count++, size--)
rtc_write(*buf++, DS1511_RAMDATA);
if (count > 1)
rtc_write((rtc_read(RTC_CMD) & ~DS1511_BME), RTC_CMD);
return count;
}
static int ds1511_rtc_probe(struct platform_device *pdev)
{
struct rtc_device *rtc;
struct resource *res;
struct rtc_plat_data *pdata;
int ret = 0;
pdata = devm_kzalloc(&pdev->dev, sizeof(*pdata), GFP_KERNEL);
if (!pdata)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
ds1511_base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(ds1511_base))
return PTR_ERR(ds1511_base);
pdata->ioaddr = ds1511_base;
pdata->irq = platform_get_irq(pdev, 0);
rtc_write(0, RTC_CMD);
rtc_write(0, RTC_CMD1);
rtc_write(0, DS1511_WD_MSEC);
rtc_write(0, DS1511_WD_SEC);
rtc_enable_update();
if (rtc_read(RTC_CMD1) & DS1511_BLF1)
dev_warn(&pdev->dev, "voltage-low detected.\n");
spin_lock_init(&pdata->lock);
platform_set_drvdata(pdev, pdata);
if (pdata->irq > 0) {
rtc_read(RTC_CMD1);
if (devm_request_irq(&pdev->dev, pdata->irq, ds1511_interrupt,
IRQF_SHARED, pdev->name, pdev) < 0) {
dev_warn(&pdev->dev, "interrupt not available.\n");
pdata->irq = 0;
}
}
rtc = devm_rtc_device_register(&pdev->dev, pdev->name, &ds1511_rtc_ops,
THIS_MODULE);
if (IS_ERR(rtc))
return PTR_ERR(rtc);
pdata->rtc = rtc;
ret = sysfs_create_bin_file(&pdev->dev.kobj, &ds1511_nvram_attr);
return ret;
}
static int ds1511_rtc_remove(struct platform_device *pdev)
{
struct rtc_plat_data *pdata = platform_get_drvdata(pdev);
sysfs_remove_bin_file(&pdev->dev.kobj, &ds1511_nvram_attr);
if (pdata->irq > 0) {
rtc_write(rtc_read(RTC_CMD) & ~RTC_TIE, RTC_CMD);
rtc_read(RTC_CMD1);
}
return 0;
}
