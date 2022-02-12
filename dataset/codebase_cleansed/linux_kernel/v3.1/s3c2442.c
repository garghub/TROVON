static unsigned long s3c2442_camif_upll_round(struct clk *clk,
unsigned long rate)
{
unsigned long parent_rate = clk_get_rate(clk->parent);
int div;
if (rate > parent_rate)
return parent_rate;
div = parent_rate / rate;
if (div == 3)
return parent_rate / 3;
div /= 2;
if (div < 1)
div = 1;
else if (div > 16)
div = 16;
return parent_rate / (div * 2);
}
static int s3c2442_camif_upll_setrate(struct clk *clk, unsigned long rate)
{
unsigned long parent_rate = clk_get_rate(clk->parent);
unsigned long camdivn = __raw_readl(S3C2440_CAMDIVN);
rate = s3c2442_camif_upll_round(clk, rate);
camdivn &= ~S3C2442_CAMDIVN_CAMCLK_DIV3;
if (rate == parent_rate) {
camdivn &= ~S3C2440_CAMDIVN_CAMCLK_SEL;
} else if ((parent_rate / rate) == 3) {
camdivn |= S3C2440_CAMDIVN_CAMCLK_SEL;
camdivn |= S3C2442_CAMDIVN_CAMCLK_DIV3;
} else {
camdivn &= ~S3C2440_CAMDIVN_CAMCLK_MASK;
camdivn |= S3C2440_CAMDIVN_CAMCLK_SEL;
camdivn |= (((parent_rate / rate) / 2) - 1);
}
__raw_writel(camdivn, S3C2440_CAMDIVN);
return 0;
}
static int s3c2442_clk_add(struct sys_device *sysdev)
{
struct clk *clock_upll;
struct clk *clock_h;
struct clk *clock_p;
clock_p = clk_get(NULL, "pclk");
clock_h = clk_get(NULL, "hclk");
clock_upll = clk_get(NULL, "upll");
if (IS_ERR(clock_p) || IS_ERR(clock_h) || IS_ERR(clock_upll)) {
printk(KERN_ERR "S3C2442: Failed to get parent clocks\n");
return -EINVAL;
}
s3c2442_clk_cam.parent = clock_h;
s3c2442_clk_cam_upll.parent = clock_upll;
s3c24xx_register_clock(&s3c2442_clk_cam);
s3c24xx_register_clock(&s3c2442_clk_cam_upll);
clk_disable(&s3c2442_clk_cam);
return 0;
}
static __init int s3c2442_clk_init(void)
{
return sysdev_driver_register(&s3c2442_sysclass, &s3c2442_clk_driver);
}
int __init s3c2442_init(void)
{
printk("S3C2442: Initialising architecture\n");
#ifdef CONFIG_PM
register_syscore_ops(&s3c2410_pm_syscore_ops);
#endif
register_syscore_ops(&s3c244x_pm_syscore_ops);
register_syscore_ops(&s3c24xx_irq_syscore_ops);
return sysdev_register(&s3c2442_sysdev);
}
void __init s3c2442_map_io(void)
{
s3c244x_map_io();
s3c24xx_gpiocfg_default.set_pull = s3c_gpio_setpull_1down;
s3c24xx_gpiocfg_default.get_pull = s3c_gpio_getpull_1down;
}
