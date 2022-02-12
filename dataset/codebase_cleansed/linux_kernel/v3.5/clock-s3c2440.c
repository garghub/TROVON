static unsigned long s3c2440_camif_upll_round(struct clk *clk,
unsigned long rate)
{
unsigned long parent_rate = clk_get_rate(clk->parent);
int div;
if (rate > parent_rate)
return parent_rate;
div = (parent_rate / rate) / 2;
if (div < 1)
div = 1;
else if (div > 16)
div = 16;
return parent_rate / (div * 2);
}
static int s3c2440_camif_upll_setrate(struct clk *clk, unsigned long rate)
{
unsigned long parent_rate = clk_get_rate(clk->parent);
unsigned long camdivn = __raw_readl(S3C2440_CAMDIVN);
rate = s3c2440_camif_upll_round(clk, rate);
camdivn &= ~(S3C2440_CAMDIVN_CAMCLK_SEL | S3C2440_CAMDIVN_CAMCLK_MASK);
if (rate != parent_rate) {
camdivn |= S3C2440_CAMDIVN_CAMCLK_SEL;
camdivn |= (((parent_rate / rate) / 2) - 1);
}
__raw_writel(camdivn, S3C2440_CAMDIVN);
return 0;
}
static unsigned long s3c2440_fclk_n_getrate(struct clk *clk)
{
unsigned long ucon0, ucon1, ucon2, divisor;
ucon0 = __raw_readl(S3C24XX_VA_UART0 + S3C2410_UCON);
ucon1 = __raw_readl(S3C24XX_VA_UART1 + S3C2410_UCON);
ucon2 = __raw_readl(S3C24XX_VA_UART2 + S3C2410_UCON);
ucon0 &= S3C2440_UCON0_DIVMASK;
ucon1 &= S3C2440_UCON1_DIVMASK;
ucon2 &= S3C2440_UCON2_DIVMASK;
if (ucon0 != 0)
divisor = (ucon0 >> S3C2440_UCON_DIVSHIFT) + 6;
else if (ucon1 != 0)
divisor = (ucon1 >> S3C2440_UCON_DIVSHIFT) + 21;
else if (ucon2 != 0)
divisor = (ucon2 >> S3C2440_UCON_DIVSHIFT) + 36;
else
divisor = 9;
return clk_get_rate(clk->parent) / divisor;
}
static int s3c2440_clk_add(struct device *dev, struct subsys_interface *sif)
{
struct clk *clock_upll;
struct clk *clock_h;
struct clk *clock_p;
clock_p = clk_get(NULL, "pclk");
clock_h = clk_get(NULL, "hclk");
clock_upll = clk_get(NULL, "upll");
if (IS_ERR(clock_p) || IS_ERR(clock_h) || IS_ERR(clock_upll)) {
printk(KERN_ERR "S3C2440: Failed to get parent clocks\n");
return -EINVAL;
}
s3c2440_clk_cam.parent = clock_h;
s3c2440_clk_ac97.parent = clock_p;
s3c2440_clk_cam_upll.parent = clock_upll;
s3c24xx_register_clock(&s3c2440_clk_fclk_n);
s3c24xx_register_clock(&s3c2440_clk_ac97);
s3c24xx_register_clock(&s3c2440_clk_cam);
s3c24xx_register_clock(&s3c2440_clk_cam_upll);
clkdev_add_table(s3c2440_clk_lookup, ARRAY_SIZE(s3c2440_clk_lookup));
clk_disable(&s3c2440_clk_ac97);
clk_disable(&s3c2440_clk_cam);
return 0;
}
static __init int s3c24xx_clk_init(void)
{
return subsys_interface_register(&s3c2440_clk_interface);
}
