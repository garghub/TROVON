static int s3c2443_setparent_hsmmc(struct clk *clk, struct clk *parent)
{
unsigned long clksrc = __raw_readl(S3C2443_SCLKCON);
clksrc &= ~(S3C2443_SCLKCON_HSMMCCLK_EXT |
S3C2443_SCLKCON_HSMMCCLK_EPLL);
if (parent == &clk_epll)
clksrc |= S3C2443_SCLKCON_HSMMCCLK_EPLL;
else if (parent == &clk_ext)
clksrc |= S3C2443_SCLKCON_HSMMCCLK_EXT;
else
return -EINVAL;
if (clk->usage > 0) {
__raw_writel(clksrc, S3C2443_SCLKCON);
}
clk->parent = parent;
return 0;
}
static int s3c2443_enable_hsmmc(struct clk *clk, int enable)
{
return s3c2443_setparent_hsmmc(clk, clk->parent);
}
void __init s3c2443_init_clocks(int xtal)
{
unsigned long epllcon = __raw_readl(S3C2443_EPLLCON);
int ptr;
clk_epll.rate = s3c2443_get_epll(epllcon, xtal);
clk_epll.parent = &clk_epllref.clk;
s3c2443_common_init_clocks(xtal, s3c2443_get_mpll,
armdiv, ARRAY_SIZE(armdiv),
S3C2443_CLKDIV0_ARMDIV_MASK);
s3c24xx_register_clocks(clks, ARRAY_SIZE(clks));
for (ptr = 0; ptr < ARRAY_SIZE(clksrcs); ptr++)
s3c_register_clksrc(clksrcs[ptr], 1);
s3c_register_clocks(init_clocks_off, ARRAY_SIZE(init_clocks_off));
s3c_disable_clocks(init_clocks_off, ARRAY_SIZE(init_clocks_off));
clkdev_add_table(s3c2443_clk_lookup, ARRAY_SIZE(s3c2443_clk_lookup));
s3c_pwmclk_init();
}
