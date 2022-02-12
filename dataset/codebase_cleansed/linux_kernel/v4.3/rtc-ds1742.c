static int ds1742_rtc_set_time(struct device *dev, struct rtc_time *tm)
{
struct platform_device *pdev = to_platform_device(dev);
struct rtc_plat_data *pdata = platform_get_drvdata(pdev);
void __iomem *ioaddr = pdata->ioaddr_rtc;
u8 century;
century = bin2bcd((tm->tm_year + 1900) / 100);
writeb(RTC_WRITE, ioaddr + RTC_CONTROL);
writeb(bin2bcd(tm->tm_year % 100), ioaddr + RTC_YEAR);
writeb(bin2bcd(tm->tm_mon + 1), ioaddr + RTC_MONTH);
writeb(bin2bcd(tm->tm_wday) & RTC_DAY_MASK, ioaddr + RTC_DAY);
writeb(bin2bcd(tm->tm_mday), ioaddr + RTC_DATE);
writeb(bin2bcd(tm->tm_hour), ioaddr + RTC_HOURS);
writeb(bin2bcd(tm->tm_min), ioaddr + RTC_MINUTES);
writeb(bin2bcd(tm->tm_sec) & RTC_SECONDS_MASK, ioaddr + RTC_SECONDS);
writeb(RTC_WRITE | (century & RTC_CENTURY_MASK), ioaddr + RTC_CENTURY);
writeb(century & RTC_CENTURY_MASK, ioaddr + RTC_CONTROL);
return 0;
}
static int ds1742_rtc_read_time(struct device *dev, struct rtc_time *tm)
{
struct platform_device *pdev = to_platform_device(dev);
struct rtc_plat_data *pdata = platform_get_drvdata(pdev);
void __iomem *ioaddr = pdata->ioaddr_rtc;
unsigned int year, month, day, hour, minute, second, week;
unsigned int century;
if (pdata->last_jiffies == jiffies)
msleep(1);
pdata->last_jiffies = jiffies;
writeb(RTC_READ, ioaddr + RTC_CONTROL);
second = readb(ioaddr + RTC_SECONDS) & RTC_SECONDS_MASK;
minute = readb(ioaddr + RTC_MINUTES);
hour = readb(ioaddr + RTC_HOURS);
day = readb(ioaddr + RTC_DATE);
week = readb(ioaddr + RTC_DAY) & RTC_DAY_MASK;
month = readb(ioaddr + RTC_MONTH);
year = readb(ioaddr + RTC_YEAR);
century = readb(ioaddr + RTC_CENTURY) & RTC_CENTURY_MASK;
writeb(0, ioaddr + RTC_CONTROL);
tm->tm_sec = bcd2bin(second);
tm->tm_min = bcd2bin(minute);
tm->tm_hour = bcd2bin(hour);
tm->tm_mday = bcd2bin(day);
tm->tm_wday = bcd2bin(week);
tm->tm_mon = bcd2bin(month) - 1;
tm->tm_year = bcd2bin(year) + bcd2bin(century) * 100 - 1900;
return rtc_valid_tm(tm);
}
static ssize_t ds1742_nvram_read(struct file *filp, struct kobject *kobj,
struct bin_attribute *bin_attr,
char *buf, loff_t pos, size_t size)
{
struct device *dev = container_of(kobj, struct device, kobj);
struct platform_device *pdev = to_platform_device(dev);
struct rtc_plat_data *pdata = platform_get_drvdata(pdev);
void __iomem *ioaddr = pdata->ioaddr_nvram;
ssize_t count;
for (count = 0; count < size; count++)
*buf++ = readb(ioaddr + pos++);
return count;
}
static ssize_t ds1742_nvram_write(struct file *filp, struct kobject *kobj,
struct bin_attribute *bin_attr,
char *buf, loff_t pos, size_t size)
{
struct device *dev = container_of(kobj, struct device, kobj);
struct platform_device *pdev = to_platform_device(dev);
struct rtc_plat_data *pdata = platform_get_drvdata(pdev);
void __iomem *ioaddr = pdata->ioaddr_nvram;
ssize_t count;
for (count = 0; count < size; count++)
writeb(*buf++, ioaddr + pos++);
return count;
}
static int ds1742_rtc_probe(struct platform_device *pdev)
{
struct rtc_device *rtc;
struct resource *res;
unsigned int cen, sec;
struct rtc_plat_data *pdata;
void __iomem *ioaddr;
int ret = 0;
pdata = devm_kzalloc(&pdev->dev, sizeof(*pdata), GFP_KERNEL);
if (!pdata)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
ioaddr = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(ioaddr))
return PTR_ERR(ioaddr);
pdata->ioaddr_nvram = ioaddr;
pdata->size_nvram = resource_size(res) - RTC_SIZE;
pdata->ioaddr_rtc = ioaddr + pdata->size_nvram;
sysfs_bin_attr_init(&pdata->nvram_attr);
pdata->nvram_attr.attr.name = "nvram";
pdata->nvram_attr.attr.mode = S_IRUGO | S_IWUSR;
pdata->nvram_attr.read = ds1742_nvram_read;
pdata->nvram_attr.write = ds1742_nvram_write;
pdata->nvram_attr.size = pdata->size_nvram;
ioaddr = pdata->ioaddr_rtc;
sec = readb(ioaddr + RTC_SECONDS);
if (sec & RTC_STOP) {
sec &= RTC_SECONDS_MASK;
cen = readb(ioaddr + RTC_CENTURY) & RTC_CENTURY_MASK;
writeb(RTC_WRITE, ioaddr + RTC_CONTROL);
writeb(sec, ioaddr + RTC_SECONDS);
writeb(cen & RTC_CENTURY_MASK, ioaddr + RTC_CONTROL);
}
if (!(readb(ioaddr + RTC_DAY) & RTC_BATT_FLAG))
dev_warn(&pdev->dev, "voltage-low detected.\n");
pdata->last_jiffies = jiffies;
platform_set_drvdata(pdev, pdata);
rtc = devm_rtc_device_register(&pdev->dev, pdev->name,
&ds1742_rtc_ops, THIS_MODULE);
if (IS_ERR(rtc))
return PTR_ERR(rtc);
ret = sysfs_create_bin_file(&pdev->dev.kobj, &pdata->nvram_attr);
if (ret)
dev_err(&pdev->dev, "Unable to create sysfs entry: %s\n",
pdata->nvram_attr.attr.name);
return 0;
}
static int ds1742_rtc_remove(struct platform_device *pdev)
{
struct rtc_plat_data *pdata = platform_get_drvdata(pdev);
sysfs_remove_bin_file(&pdev->dev.kobj, &pdata->nvram_attr);
return 0;
}
