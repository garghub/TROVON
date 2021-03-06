static void ds1216_read(u8 __iomem *ioaddr, u8 *buf)
{
unsigned char c;
int i, j;
for (i = 0; i < 8; i++) {
c = 0;
for (j = 0; j < 8; j++)
c |= (readb(ioaddr) & 0x1) << j;
buf[i] = c;
}
}
static void ds1216_write(u8 __iomem *ioaddr, const u8 *buf)
{
unsigned char c;
int i, j;
for (i = 0; i < 8; i++) {
c = buf[i];
for (j = 0; j < 8; j++) {
writeb(c, ioaddr);
c = c >> 1;
}
}
}
static void ds1216_switch_ds_to_clock(u8 __iomem *ioaddr)
{
readb(ioaddr);
ds1216_write(ioaddr, magic);
}
static int ds1216_rtc_read_time(struct device *dev, struct rtc_time *tm)
{
struct platform_device *pdev = to_platform_device(dev);
struct ds1216_priv *priv = platform_get_drvdata(pdev);
struct ds1216_regs regs;
ds1216_switch_ds_to_clock(priv->ioaddr);
ds1216_read(priv->ioaddr, (u8 *)&regs);
tm->tm_sec = bcd2bin(regs.sec);
tm->tm_min = bcd2bin(regs.min);
if (regs.hour & DS1216_HOUR_1224) {
tm->tm_hour = bcd2bin(regs.hour & 0x1f);
if (regs.hour & DS1216_HOUR_AMPM)
tm->tm_hour += 12;
} else
tm->tm_hour = bcd2bin(regs.hour & 0x3f);
tm->tm_wday = (regs.wday & 7) - 1;
tm->tm_mday = bcd2bin(regs.mday & 0x3f);
tm->tm_mon = bcd2bin(regs.month & 0x1f);
tm->tm_year = bcd2bin(regs.year);
if (tm->tm_year < 70)
tm->tm_year += 100;
return rtc_valid_tm(tm);
}
static int ds1216_rtc_set_time(struct device *dev, struct rtc_time *tm)
{
struct platform_device *pdev = to_platform_device(dev);
struct ds1216_priv *priv = platform_get_drvdata(pdev);
struct ds1216_regs regs;
ds1216_switch_ds_to_clock(priv->ioaddr);
ds1216_read(priv->ioaddr, (u8 *)&regs);
regs.tsec = 0;
regs.sec = bin2bcd(tm->tm_sec);
regs.min = bin2bcd(tm->tm_min);
regs.hour &= DS1216_HOUR_1224;
if (regs.hour && tm->tm_hour > 12) {
regs.hour |= DS1216_HOUR_AMPM;
tm->tm_hour -= 12;
}
regs.hour |= bin2bcd(tm->tm_hour);
regs.wday &= ~7;
regs.wday |= tm->tm_wday;
regs.mday = bin2bcd(tm->tm_mday);
regs.month = bin2bcd(tm->tm_mon);
regs.year = bin2bcd(tm->tm_year % 100);
ds1216_switch_ds_to_clock(priv->ioaddr);
ds1216_write(priv->ioaddr, (u8 *)&regs);
return 0;
}
static int __init ds1216_rtc_probe(struct platform_device *pdev)
{
struct resource *res;
struct ds1216_priv *priv;
int ret = 0;
u8 dummy[8];
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res)
return -ENODEV;
priv = kzalloc(sizeof *priv, GFP_KERNEL);
if (!priv)
return -ENOMEM;
platform_set_drvdata(pdev, priv);
priv->size = resource_size(res);
if (!request_mem_region(res->start, priv->size, pdev->name)) {
ret = -EBUSY;
goto out;
}
priv->baseaddr = res->start;
priv->ioaddr = ioremap(priv->baseaddr, priv->size);
if (!priv->ioaddr) {
ret = -ENOMEM;
goto out;
}
priv->rtc = rtc_device_register("ds1216", &pdev->dev,
&ds1216_rtc_ops, THIS_MODULE);
if (IS_ERR(priv->rtc)) {
ret = PTR_ERR(priv->rtc);
goto out;
}
ds1216_read(priv->ioaddr, dummy);
return 0;
out:
if (priv->ioaddr)
iounmap(priv->ioaddr);
if (priv->baseaddr)
release_mem_region(priv->baseaddr, priv->size);
kfree(priv);
return ret;
}
static int __exit ds1216_rtc_remove(struct platform_device *pdev)
{
struct ds1216_priv *priv = platform_get_drvdata(pdev);
rtc_device_unregister(priv->rtc);
iounmap(priv->ioaddr);
release_mem_region(priv->baseaddr, priv->size);
kfree(priv);
return 0;
}
static int __init ds1216_rtc_init(void)
{
return platform_driver_probe(&ds1216_rtc_platform_driver, ds1216_rtc_probe);
}
static void __exit ds1216_rtc_exit(void)
{
platform_driver_unregister(&ds1216_rtc_platform_driver);
}
