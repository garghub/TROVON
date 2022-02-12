static int s3c2440_setparent_armclk(struct clk *clk, struct clk *parent)
{
unsigned long camdivn;
unsigned long dvs;
if (parent == &clk_f)
dvs = 0;
else if (parent == &clk_h)
dvs = S3C2440_CAMDIVN_DVSEN;
else
return -EINVAL;
clk->parent = parent;
camdivn = __raw_readl(S3C2440_CAMDIVN);
camdivn &= ~S3C2440_CAMDIVN_DVSEN;
camdivn |= dvs;
__raw_writel(camdivn, S3C2440_CAMDIVN);
return 0;
}
static int s3c244x_clk_add(struct sys_device *sysdev)
{
unsigned long camdivn = __raw_readl(S3C2440_CAMDIVN);
unsigned long clkdivn;
struct clk *clock_upll;
int ret;
printk("S3C244X: Clock Support, DVS %s\n",
(camdivn & S3C2440_CAMDIVN_DVSEN) ? "on" : "off");
clk_arm.parent = (camdivn & S3C2440_CAMDIVN_DVSEN) ? &clk_h : &clk_f;
ret = s3c24xx_register_clock(&clk_arm);
if (ret < 0) {
printk(KERN_ERR "S3C24XX: Failed to add armclk (%d)\n", ret);
return ret;
}
clock_upll = clk_get(NULL, "upll");
if (IS_ERR(clock_upll)) {
printk(KERN_ERR "S3C244X: Failed to get upll clock\n");
return -ENOENT;
}
if (clk_get_rate(clock_upll) > (94 * MHZ)) {
clk_usb_bus.rate = clk_get_rate(clock_upll) / 2;
spin_lock(&clocks_lock);
clkdivn = __raw_readl(S3C2410_CLKDIVN);
clkdivn |= S3C2440_CLKDIVN_UCLK;
__raw_writel(clkdivn, S3C2410_CLKDIVN);
spin_unlock(&clocks_lock);
}
return 0;
}
static int s3c2440_clk_init(void)
{
return sysdev_driver_register(&s3c2440_sysclass, &s3c2440_clk_driver);
}
static int s3c2442_clk_init(void)
{
return sysdev_driver_register(&s3c2442_sysclass, &s3c2442_clk_driver);
}
