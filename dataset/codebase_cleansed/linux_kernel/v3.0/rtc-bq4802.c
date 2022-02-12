static u8 bq4802_read_io(struct bq4802 *p, int off)
{
return inb(p->ioport + off);
}
static void bq4802_write_io(struct bq4802 *p, int off, u8 val)
{
outb(val, p->ioport + off);
}
static u8 bq4802_read_mem(struct bq4802 *p, int off)
{
return readb(p->regs + off);
}
static void bq4802_write_mem(struct bq4802 *p, int off, u8 val)
{
writeb(val, p->regs + off);
}
static int bq4802_read_time(struct device *dev, struct rtc_time *tm)
{
struct platform_device *pdev = to_platform_device(dev);
struct bq4802 *p = platform_get_drvdata(pdev);
unsigned long flags;
unsigned int century;
u8 val;
spin_lock_irqsave(&p->lock, flags);
val = p->read(p, 0x0e);
p->write(p, 0xe, val | 0x08);
tm->tm_sec = p->read(p, 0x00);
tm->tm_min = p->read(p, 0x02);
tm->tm_hour = p->read(p, 0x04);
tm->tm_mday = p->read(p, 0x06);
tm->tm_mon = p->read(p, 0x09);
tm->tm_year = p->read(p, 0x0a);
tm->tm_wday = p->read(p, 0x08);
century = p->read(p, 0x0f);
p->write(p, 0x0e, val);
spin_unlock_irqrestore(&p->lock, flags);
tm->tm_sec = bcd2bin(tm->tm_sec);
tm->tm_min = bcd2bin(tm->tm_min);
tm->tm_hour = bcd2bin(tm->tm_hour);
tm->tm_mday = bcd2bin(tm->tm_mday);
tm->tm_mon = bcd2bin(tm->tm_mon);
tm->tm_year = bcd2bin(tm->tm_year);
tm->tm_wday = bcd2bin(tm->tm_wday);
century = bcd2bin(century);
tm->tm_year += (century * 100);
tm->tm_year -= 1900;
tm->tm_mon--;
return 0;
}
static int bq4802_set_time(struct device *dev, struct rtc_time *tm)
{
struct platform_device *pdev = to_platform_device(dev);
struct bq4802 *p = platform_get_drvdata(pdev);
u8 sec, min, hrs, day, mon, yrs, century, val;
unsigned long flags;
unsigned int year;
year = tm->tm_year + 1900;
century = year / 100;
yrs = year % 100;
mon = tm->tm_mon + 1;
day = tm->tm_mday;
hrs = tm->tm_hour;
min = tm->tm_min;
sec = tm->tm_sec;
sec = bin2bcd(sec);
min = bin2bcd(min);
hrs = bin2bcd(hrs);
day = bin2bcd(day);
mon = bin2bcd(mon);
yrs = bin2bcd(yrs);
century = bin2bcd(century);
spin_lock_irqsave(&p->lock, flags);
val = p->read(p, 0x0e);
p->write(p, 0x0e, val | 0x08);
p->write(p, 0x00, sec);
p->write(p, 0x02, min);
p->write(p, 0x04, hrs);
p->write(p, 0x06, day);
p->write(p, 0x09, mon);
p->write(p, 0x0a, yrs);
p->write(p, 0x0f, century);
p->write(p, 0x0e, val);
spin_unlock_irqrestore(&p->lock, flags);
return 0;
}
static int __devinit bq4802_probe(struct platform_device *pdev)
{
struct bq4802 *p = kzalloc(sizeof(*p), GFP_KERNEL);
int err = -ENOMEM;
if (!p)
goto out;
spin_lock_init(&p->lock);
p->r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!p->r) {
p->r = platform_get_resource(pdev, IORESOURCE_IO, 0);
err = -EINVAL;
if (!p->r)
goto out_free;
}
if (p->r->flags & IORESOURCE_IO) {
p->ioport = p->r->start;
p->read = bq4802_read_io;
p->write = bq4802_write_io;
} else if (p->r->flags & IORESOURCE_MEM) {
p->regs = ioremap(p->r->start, resource_size(p->r));
p->read = bq4802_read_mem;
p->write = bq4802_write_mem;
} else {
err = -EINVAL;
goto out_free;
}
platform_set_drvdata(pdev, p);
p->rtc = rtc_device_register("bq4802", &pdev->dev,
&bq4802_ops, THIS_MODULE);
if (IS_ERR(p->rtc)) {
err = PTR_ERR(p->rtc);
goto out_iounmap;
}
err = 0;
out:
return err;
out_iounmap:
if (p->r->flags & IORESOURCE_MEM)
iounmap(p->regs);
out_free:
kfree(p);
goto out;
}
static int __devexit bq4802_remove(struct platform_device *pdev)
{
struct bq4802 *p = platform_get_drvdata(pdev);
rtc_device_unregister(p->rtc);
if (p->r->flags & IORESOURCE_MEM)
iounmap(p->regs);
platform_set_drvdata(pdev, NULL);
kfree(p);
return 0;
}
static int __init bq4802_init(void)
{
return platform_driver_register(&bq4802_driver);
}
static void __exit bq4802_exit(void)
{
platform_driver_unregister(&bq4802_driver);
}
