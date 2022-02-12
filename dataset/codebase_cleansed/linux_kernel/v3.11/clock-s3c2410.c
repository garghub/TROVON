int s3c2410_clkcon_enable(struct clk *clk, int enable)
{
unsigned int clocks = clk->ctrlbit;
unsigned long clkcon;
clkcon = __raw_readl(S3C2410_CLKCON);
if (enable)
clkcon |= clocks;
else
clkcon &= ~clocks;
clkcon &= ~(S3C2410_CLKCON_IDLE|S3C2410_CLKCON_POWER);
__raw_writel(clkcon, S3C2410_CLKCON);
return 0;
}
static int s3c2410_upll_enable(struct clk *clk, int enable)
{
unsigned long clkslow = __raw_readl(S3C2410_CLKSLOW);
unsigned long orig = clkslow;
if (enable)
clkslow &= ~S3C2410_CLKSLOW_UCLK_OFF;
else
clkslow |= S3C2410_CLKSLOW_UCLK_OFF;
__raw_writel(clkslow, S3C2410_CLKSLOW);
if (enable && (orig & S3C2410_CLKSLOW_UCLK_OFF))
udelay(200);
return 0;
}
int __init s3c2410_baseclk_add(void)
{
unsigned long clkslow = __raw_readl(S3C2410_CLKSLOW);
unsigned long clkcon = __raw_readl(S3C2410_CLKCON);
struct clk *xtal;
int ret;
int ptr;
clk_upll.enable = s3c2410_upll_enable;
if (s3c24xx_register_clock(&clk_usb_bus) < 0)
printk(KERN_ERR "failed to register usb bus clock\n");
for (ptr = 0; ptr < ARRAY_SIZE(init_clocks); ptr++) {
struct clk *clkp = init_clocks[ptr];
clkp->usage = clkcon & clkp->ctrlbit ? 1 : 0;
ret = s3c24xx_register_clock(clkp);
if (ret < 0) {
printk(KERN_ERR "Failed to register clock %s (%d)\n",
clkp->name, ret);
}
}
s3c_register_clocks(init_clocks_off, ARRAY_SIZE(init_clocks_off));
s3c_disable_clocks(init_clocks_off, ARRAY_SIZE(init_clocks_off));
xtal = clk_get(NULL, "xtal");
printk("CLOCK: Slow mode (%ld.%ld MHz), %s, MPLL %s, UPLL %s\n",
print_mhz(clk_get_rate(xtal) /
( 2 * S3C2410_CLKSLOW_GET_SLOWVAL(clkslow))),
(clkslow & S3C2410_CLKSLOW_SLOW) ? "slow" : "fast",
(clkslow & S3C2410_CLKSLOW_MPLL_OFF) ? "off" : "on",
(clkslow & S3C2410_CLKSLOW_UCLK_OFF) ? "off" : "on");
s3c_pwmclk_init();
return 0;
}
