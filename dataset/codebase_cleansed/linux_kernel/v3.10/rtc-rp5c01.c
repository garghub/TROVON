static inline unsigned int rp5c01_read(struct rp5c01_priv *priv,
unsigned int reg)
{
return __raw_readl(&priv->regs[reg]) & 0xf;
}
static inline void rp5c01_write(struct rp5c01_priv *priv, unsigned int val,
unsigned int reg)
{
__raw_writel(val, &priv->regs[reg]);
}
static void rp5c01_lock(struct rp5c01_priv *priv)
{
rp5c01_write(priv, RP5C01_MODE_MODE00, RP5C01_MODE);
}
static void rp5c01_unlock(struct rp5c01_priv *priv)
{
rp5c01_write(priv, RP5C01_MODE_TIMER_EN | RP5C01_MODE_MODE01,
RP5C01_MODE);
}
static int rp5c01_read_time(struct device *dev, struct rtc_time *tm)
{
struct rp5c01_priv *priv = dev_get_drvdata(dev);
spin_lock_irq(&priv->lock);
rp5c01_lock(priv);
tm->tm_sec = rp5c01_read(priv, RP5C01_10_SECOND) * 10 +
rp5c01_read(priv, RP5C01_1_SECOND);
tm->tm_min = rp5c01_read(priv, RP5C01_10_MINUTE) * 10 +
rp5c01_read(priv, RP5C01_1_MINUTE);
tm->tm_hour = rp5c01_read(priv, RP5C01_10_HOUR) * 10 +
rp5c01_read(priv, RP5C01_1_HOUR);
tm->tm_mday = rp5c01_read(priv, RP5C01_10_DAY) * 10 +
rp5c01_read(priv, RP5C01_1_DAY);
tm->tm_wday = rp5c01_read(priv, RP5C01_DAY_OF_WEEK);
tm->tm_mon = rp5c01_read(priv, RP5C01_10_MONTH) * 10 +
rp5c01_read(priv, RP5C01_1_MONTH) - 1;
tm->tm_year = rp5c01_read(priv, RP5C01_10_YEAR) * 10 +
rp5c01_read(priv, RP5C01_1_YEAR);
if (tm->tm_year <= 69)
tm->tm_year += 100;
rp5c01_unlock(priv);
spin_unlock_irq(&priv->lock);
return rtc_valid_tm(tm);
}
static int rp5c01_set_time(struct device *dev, struct rtc_time *tm)
{
struct rp5c01_priv *priv = dev_get_drvdata(dev);
spin_lock_irq(&priv->lock);
rp5c01_lock(priv);
rp5c01_write(priv, tm->tm_sec / 10, RP5C01_10_SECOND);
rp5c01_write(priv, tm->tm_sec % 10, RP5C01_1_SECOND);
rp5c01_write(priv, tm->tm_min / 10, RP5C01_10_MINUTE);
rp5c01_write(priv, tm->tm_min % 10, RP5C01_1_MINUTE);
rp5c01_write(priv, tm->tm_hour / 10, RP5C01_10_HOUR);
rp5c01_write(priv, tm->tm_hour % 10, RP5C01_1_HOUR);
rp5c01_write(priv, tm->tm_mday / 10, RP5C01_10_DAY);
rp5c01_write(priv, tm->tm_mday % 10, RP5C01_1_DAY);
if (tm->tm_wday != -1)
rp5c01_write(priv, tm->tm_wday, RP5C01_DAY_OF_WEEK);
rp5c01_write(priv, (tm->tm_mon + 1) / 10, RP5C01_10_MONTH);
rp5c01_write(priv, (tm->tm_mon + 1) % 10, RP5C01_1_MONTH);
if (tm->tm_year >= 100)
tm->tm_year -= 100;
rp5c01_write(priv, tm->tm_year / 10, RP5C01_10_YEAR);
rp5c01_write(priv, tm->tm_year % 10, RP5C01_1_YEAR);
rp5c01_unlock(priv);
spin_unlock_irq(&priv->lock);
return 0;
}
static ssize_t rp5c01_nvram_read(struct file *filp, struct kobject *kobj,
struct bin_attribute *bin_attr,
char *buf, loff_t pos, size_t size)
{
struct device *dev = container_of(kobj, struct device, kobj);
struct rp5c01_priv *priv = dev_get_drvdata(dev);
ssize_t count;
spin_lock_irq(&priv->lock);
for (count = 0; size > 0 && pos < RP5C01_MODE; count++, size--) {
u8 data;
rp5c01_write(priv,
RP5C01_MODE_TIMER_EN | RP5C01_MODE_RAM_BLOCK10,
RP5C01_MODE);
data = rp5c01_read(priv, pos) << 4;
rp5c01_write(priv,
RP5C01_MODE_TIMER_EN | RP5C01_MODE_RAM_BLOCK11,
RP5C01_MODE);
data |= rp5c01_read(priv, pos++);
rp5c01_write(priv, RP5C01_MODE_TIMER_EN | RP5C01_MODE_MODE01,
RP5C01_MODE);
*buf++ = data;
}
spin_unlock_irq(&priv->lock);
return count;
}
static ssize_t rp5c01_nvram_write(struct file *filp, struct kobject *kobj,
struct bin_attribute *bin_attr,
char *buf, loff_t pos, size_t size)
{
struct device *dev = container_of(kobj, struct device, kobj);
struct rp5c01_priv *priv = dev_get_drvdata(dev);
ssize_t count;
spin_lock_irq(&priv->lock);
for (count = 0; size > 0 && pos < RP5C01_MODE; count++, size--) {
u8 data = *buf++;
rp5c01_write(priv,
RP5C01_MODE_TIMER_EN | RP5C01_MODE_RAM_BLOCK10,
RP5C01_MODE);
rp5c01_write(priv, data >> 4, pos);
rp5c01_write(priv,
RP5C01_MODE_TIMER_EN | RP5C01_MODE_RAM_BLOCK11,
RP5C01_MODE);
rp5c01_write(priv, data & 0xf, pos++);
rp5c01_write(priv, RP5C01_MODE_TIMER_EN | RP5C01_MODE_MODE01,
RP5C01_MODE);
}
spin_unlock_irq(&priv->lock);
return count;
}
static int __init rp5c01_rtc_probe(struct platform_device *dev)
{
struct resource *res;
struct rp5c01_priv *priv;
struct rtc_device *rtc;
int error;
res = platform_get_resource(dev, IORESOURCE_MEM, 0);
if (!res)
return -ENODEV;
priv = devm_kzalloc(&dev->dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
priv->regs = devm_ioremap(&dev->dev, res->start, resource_size(res));
if (!priv->regs)
return -ENOMEM;
sysfs_bin_attr_init(&priv->nvram_attr);
priv->nvram_attr.attr.name = "nvram";
priv->nvram_attr.attr.mode = S_IRUGO | S_IWUSR;
priv->nvram_attr.read = rp5c01_nvram_read;
priv->nvram_attr.write = rp5c01_nvram_write;
priv->nvram_attr.size = RP5C01_MODE;
spin_lock_init(&priv->lock);
platform_set_drvdata(dev, priv);
rtc = devm_rtc_device_register(&dev->dev, "rtc-rp5c01", &rp5c01_rtc_ops,
THIS_MODULE);
if (IS_ERR(rtc)) {
error = PTR_ERR(rtc);
goto out;
}
priv->rtc = rtc;
error = sysfs_create_bin_file(&dev->dev.kobj, &priv->nvram_attr);
if (error)
goto out;
return 0;
out:
platform_set_drvdata(dev, NULL);
return error;
}
static int __exit rp5c01_rtc_remove(struct platform_device *dev)
{
struct rp5c01_priv *priv = platform_get_drvdata(dev);
sysfs_remove_bin_file(&dev->dev.kobj, &priv->nvram_attr);
return 0;
}
