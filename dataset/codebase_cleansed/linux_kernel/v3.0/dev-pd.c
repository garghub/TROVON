static int exynos4_pd_enable(struct device *dev)
{
struct samsung_pd_info *pdata = dev->platform_data;
u32 timeout;
__raw_writel(S5P_INT_LOCAL_PWR_EN, pdata->base);
timeout = 10;
while ((__raw_readl(pdata->base + 0x4) & S5P_INT_LOCAL_PWR_EN)
!= S5P_INT_LOCAL_PWR_EN) {
if (timeout == 0) {
printk(KERN_ERR "Power domain %s enable failed.\n",
dev_name(dev));
return -ETIMEDOUT;
}
timeout--;
udelay(100);
}
return 0;
}
static int exynos4_pd_disable(struct device *dev)
{
struct samsung_pd_info *pdata = dev->platform_data;
u32 timeout;
__raw_writel(0, pdata->base);
timeout = 10;
while (__raw_readl(pdata->base + 0x4) & S5P_INT_LOCAL_PWR_EN) {
if (timeout == 0) {
printk(KERN_ERR "Power domain %s disable failed.\n",
dev_name(dev));
return -ETIMEDOUT;
}
timeout--;
udelay(100);
}
return 0;
}
