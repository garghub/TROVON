static inline unsigned int msm6242_read(struct msm6242_priv *priv,
unsigned int reg)
{
return __raw_readl(&priv->regs[reg]) & 0xf;
}
static inline void msm6242_write(struct msm6242_priv *priv, unsigned int val,
unsigned int reg)
{
__raw_writel(val, &priv->regs[reg]);
}
static inline void msm6242_set(struct msm6242_priv *priv, unsigned int val,
unsigned int reg)
{
msm6242_write(priv, msm6242_read(priv, reg) | val, reg);
}
static inline void msm6242_clear(struct msm6242_priv *priv, unsigned int val,
unsigned int reg)
{
msm6242_write(priv, msm6242_read(priv, reg) & ~val, reg);
}
static void msm6242_lock(struct msm6242_priv *priv)
{
int cnt = 5;
msm6242_set(priv, MSM6242_CD_HOLD, MSM6242_CD);
while ((msm6242_read(priv, MSM6242_CD) & MSM6242_CD_BUSY) && cnt) {
msm6242_clear(priv, MSM6242_CD_HOLD, MSM6242_CD);
udelay(70);
msm6242_set(priv, MSM6242_CD_HOLD, MSM6242_CD);
cnt--;
}
if (!cnt)
pr_warning("msm6242: timed out waiting for RTC (0x%x)\n",
msm6242_read(priv, MSM6242_CD));
}
static void msm6242_unlock(struct msm6242_priv *priv)
{
msm6242_clear(priv, MSM6242_CD_HOLD, MSM6242_CD);
}
static int msm6242_read_time(struct device *dev, struct rtc_time *tm)
{
struct msm6242_priv *priv = dev_get_drvdata(dev);
msm6242_lock(priv);
tm->tm_sec = msm6242_read(priv, MSM6242_SECOND10) * 10 +
msm6242_read(priv, MSM6242_SECOND1);
tm->tm_min = msm6242_read(priv, MSM6242_MINUTE10) * 10 +
msm6242_read(priv, MSM6242_MINUTE1);
tm->tm_hour = (msm6242_read(priv, MSM6242_HOUR10 & 3)) * 10 +
msm6242_read(priv, MSM6242_HOUR1);
tm->tm_mday = msm6242_read(priv, MSM6242_DAY10) * 10 +
msm6242_read(priv, MSM6242_DAY1);
tm->tm_wday = msm6242_read(priv, MSM6242_WEEK);
tm->tm_mon = msm6242_read(priv, MSM6242_MONTH10) * 10 +
msm6242_read(priv, MSM6242_MONTH1) - 1;
tm->tm_year = msm6242_read(priv, MSM6242_YEAR10) * 10 +
msm6242_read(priv, MSM6242_YEAR1);
if (tm->tm_year <= 69)
tm->tm_year += 100;
if (!(msm6242_read(priv, MSM6242_CF) & MSM6242_CF_24H)) {
unsigned int pm = msm6242_read(priv, MSM6242_HOUR10) &
MSM6242_HOUR10_PM;
if (!pm && tm->tm_hour == 12)
tm->tm_hour = 0;
else if (pm && tm->tm_hour != 12)
tm->tm_hour += 12;
}
msm6242_unlock(priv);
return rtc_valid_tm(tm);
}
static int msm6242_set_time(struct device *dev, struct rtc_time *tm)
{
struct msm6242_priv *priv = dev_get_drvdata(dev);
msm6242_lock(priv);
msm6242_write(priv, tm->tm_sec / 10, MSM6242_SECOND10);
msm6242_write(priv, tm->tm_sec % 10, MSM6242_SECOND1);
msm6242_write(priv, tm->tm_min / 10, MSM6242_MINUTE10);
msm6242_write(priv, tm->tm_min % 10, MSM6242_MINUTE1);
if (msm6242_read(priv, MSM6242_CF) & MSM6242_CF_24H)
msm6242_write(priv, tm->tm_hour / 10, MSM6242_HOUR10);
else if (tm->tm_hour >= 12)
msm6242_write(priv, MSM6242_HOUR10_PM + (tm->tm_hour - 12) / 10,
MSM6242_HOUR10);
else
msm6242_write(priv, tm->tm_hour / 10, MSM6242_HOUR10);
msm6242_write(priv, tm->tm_hour % 10, MSM6242_HOUR1);
msm6242_write(priv, tm->tm_mday / 10, MSM6242_DAY10);
msm6242_write(priv, tm->tm_mday % 10, MSM6242_DAY1);
if (tm->tm_wday != -1)
msm6242_write(priv, tm->tm_wday, MSM6242_WEEK);
msm6242_write(priv, (tm->tm_mon + 1) / 10, MSM6242_MONTH10);
msm6242_write(priv, (tm->tm_mon + 1) % 10, MSM6242_MONTH1);
if (tm->tm_year >= 100)
tm->tm_year -= 100;
msm6242_write(priv, tm->tm_year / 10, MSM6242_YEAR10);
msm6242_write(priv, tm->tm_year % 10, MSM6242_YEAR1);
msm6242_unlock(priv);
return 0;
}
static int __init msm6242_rtc_probe(struct platform_device *dev)
{
struct resource *res;
struct msm6242_priv *priv;
struct rtc_device *rtc;
int error;
res = platform_get_resource(dev, IORESOURCE_MEM, 0);
if (!res)
return -ENODEV;
priv = kzalloc(sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
priv->regs = ioremap(res->start, resource_size(res));
if (!priv->regs) {
error = -ENOMEM;
goto out_free_priv;
}
platform_set_drvdata(dev, priv);
rtc = rtc_device_register("rtc-msm6242", &dev->dev, &msm6242_rtc_ops,
THIS_MODULE);
if (IS_ERR(rtc)) {
error = PTR_ERR(rtc);
goto out_unmap;
}
priv->rtc = rtc;
return 0;
out_unmap:
platform_set_drvdata(dev, NULL);
iounmap(priv->regs);
out_free_priv:
kfree(priv);
return error;
}
static int __exit msm6242_rtc_remove(struct platform_device *dev)
{
struct msm6242_priv *priv = platform_get_drvdata(dev);
rtc_device_unregister(priv->rtc);
iounmap(priv->regs);
kfree(priv);
return 0;
}
static int __init msm6242_rtc_init(void)
{
return platform_driver_probe(&msm6242_rtc_driver, msm6242_rtc_probe);
}
static void __exit msm6242_rtc_fini(void)
{
platform_driver_unregister(&msm6242_rtc_driver);
}
