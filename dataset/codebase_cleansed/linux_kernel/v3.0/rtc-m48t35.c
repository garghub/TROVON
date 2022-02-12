static int m48t35_read_time(struct device *dev, struct rtc_time *tm)
{
struct m48t35_priv *priv = dev_get_drvdata(dev);
u8 control;
spin_lock_irq(&priv->lock);
control = readb(&priv->reg->control);
writeb(control | M48T35_RTC_READ, &priv->reg->control);
tm->tm_sec = readb(&priv->reg->sec);
tm->tm_min = readb(&priv->reg->min);
tm->tm_hour = readb(&priv->reg->hour);
tm->tm_mday = readb(&priv->reg->date);
tm->tm_mon = readb(&priv->reg->month);
tm->tm_year = readb(&priv->reg->year);
writeb(control, &priv->reg->control);
spin_unlock_irq(&priv->lock);
tm->tm_sec = bcd2bin(tm->tm_sec);
tm->tm_min = bcd2bin(tm->tm_min);
tm->tm_hour = bcd2bin(tm->tm_hour);
tm->tm_mday = bcd2bin(tm->tm_mday);
tm->tm_mon = bcd2bin(tm->tm_mon);
tm->tm_year = bcd2bin(tm->tm_year);
tm->tm_year += 70;
if (tm->tm_year <= 69)
tm->tm_year += 100;
tm->tm_mon--;
return rtc_valid_tm(tm);
}
static int m48t35_set_time(struct device *dev, struct rtc_time *tm)
{
struct m48t35_priv *priv = dev_get_drvdata(dev);
unsigned char mon, day, hrs, min, sec;
unsigned int yrs;
u8 control;
yrs = tm->tm_year + 1900;
mon = tm->tm_mon + 1;
day = tm->tm_mday;
hrs = tm->tm_hour;
min = tm->tm_min;
sec = tm->tm_sec;
if (yrs < 1970)
return -EINVAL;
yrs -= 1970;
if (yrs > 255)
return -EINVAL;
if (yrs > 169)
return -EINVAL;
if (yrs >= 100)
yrs -= 100;
sec = bin2bcd(sec);
min = bin2bcd(min);
hrs = bin2bcd(hrs);
day = bin2bcd(day);
mon = bin2bcd(mon);
yrs = bin2bcd(yrs);
spin_lock_irq(&priv->lock);
control = readb(&priv->reg->control);
writeb(control | M48T35_RTC_SET, &priv->reg->control);
writeb(yrs, &priv->reg->year);
writeb(mon, &priv->reg->month);
writeb(day, &priv->reg->date);
writeb(hrs, &priv->reg->hour);
writeb(min, &priv->reg->min);
writeb(sec, &priv->reg->sec);
writeb(control, &priv->reg->control);
spin_unlock_irq(&priv->lock);
return 0;
}
static int __devinit m48t35_probe(struct platform_device *pdev)
{
struct resource *res;
struct m48t35_priv *priv;
int ret = 0;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res)
return -ENODEV;
priv = kzalloc(sizeof(struct m48t35_priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
priv->size = res->end - res->start + 1;
#ifndef CONFIG_SGI_IP27
if (!request_mem_region(res->start, priv->size, pdev->name)) {
ret = -EBUSY;
goto out;
}
#endif
priv->baseaddr = res->start;
priv->reg = ioremap(priv->baseaddr, priv->size);
if (!priv->reg) {
ret = -ENOMEM;
goto out;
}
spin_lock_init(&priv->lock);
platform_set_drvdata(pdev, priv);
priv->rtc = rtc_device_register("m48t35", &pdev->dev,
&m48t35_ops, THIS_MODULE);
if (IS_ERR(priv->rtc)) {
ret = PTR_ERR(priv->rtc);
goto out;
}
return 0;
out:
if (priv->reg)
iounmap(priv->reg);
if (priv->baseaddr)
release_mem_region(priv->baseaddr, priv->size);
kfree(priv);
return ret;
}
static int __devexit m48t35_remove(struct platform_device *pdev)
{
struct m48t35_priv *priv = platform_get_drvdata(pdev);
rtc_device_unregister(priv->rtc);
iounmap(priv->reg);
#ifndef CONFIG_SGI_IP27
release_mem_region(priv->baseaddr, priv->size);
#endif
kfree(priv);
return 0;
}
static int __init m48t35_init(void)
{
return platform_driver_register(&m48t35_platform_driver);
}
static void __exit m48t35_exit(void)
{
platform_driver_unregister(&m48t35_platform_driver);
}
