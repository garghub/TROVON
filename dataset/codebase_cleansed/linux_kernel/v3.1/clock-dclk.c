static int s3c24xx_dclk_enable(struct clk *clk, int enable)
{
unsigned long dclkcon = __raw_readl(S3C24XX_DCLKCON);
if (enable)
dclkcon |= clk->ctrlbit;
else
dclkcon &= ~clk->ctrlbit;
__raw_writel(dclkcon, S3C24XX_DCLKCON);
return 0;
}
static int s3c24xx_dclk_setparent(struct clk *clk, struct clk *parent)
{
unsigned long dclkcon;
unsigned int uclk;
if (parent == &clk_upll)
uclk = 1;
else if (parent == &clk_p)
uclk = 0;
else
return -EINVAL;
clk->parent = parent;
dclkcon = __raw_readl(S3C24XX_DCLKCON);
if (clk->ctrlbit == S3C2410_DCLKCON_DCLK0EN) {
if (uclk)
dclkcon |= S3C2410_DCLKCON_DCLK0_UCLK;
else
dclkcon &= ~S3C2410_DCLKCON_DCLK0_UCLK;
} else {
if (uclk)
dclkcon |= S3C2410_DCLKCON_DCLK1_UCLK;
else
dclkcon &= ~S3C2410_DCLKCON_DCLK1_UCLK;
}
__raw_writel(dclkcon, S3C24XX_DCLKCON);
return 0;
}
static unsigned long s3c24xx_calc_div(struct clk *clk, unsigned long rate)
{
unsigned long div;
if ((rate == 0) || !clk->parent)
return 0;
div = clk_get_rate(clk->parent) / rate;
if (div < 2)
div = 2;
else if (div > 16)
div = 16;
return div;
}
static unsigned long s3c24xx_round_dclk_rate(struct clk *clk,
unsigned long rate)
{
unsigned long div = s3c24xx_calc_div(clk, rate);
if (div == 0)
return 0;
return clk_get_rate(clk->parent) / div;
}
static int s3c24xx_set_dclk_rate(struct clk *clk, unsigned long rate)
{
unsigned long mask, data, div = s3c24xx_calc_div(clk, rate);
if (div == 0)
return -EINVAL;
if (clk == &s3c24xx_dclk0) {
mask = S3C2410_DCLKCON_DCLK0_DIV_MASK |
S3C2410_DCLKCON_DCLK0_CMP_MASK;
data = S3C2410_DCLKCON_DCLK0_DIV(div) |
S3C2410_DCLKCON_DCLK0_CMP((div + 1) / 2);
} else if (clk == &s3c24xx_dclk1) {
mask = S3C2410_DCLKCON_DCLK1_DIV_MASK |
S3C2410_DCLKCON_DCLK1_CMP_MASK;
data = S3C2410_DCLKCON_DCLK1_DIV(div) |
S3C2410_DCLKCON_DCLK1_CMP((div + 1) / 2);
} else
return -EINVAL;
clk->rate = clk_get_rate(clk->parent) / div;
__raw_writel(((__raw_readl(S3C24XX_DCLKCON) & ~mask) | data),
S3C24XX_DCLKCON);
return clk->rate;
}
static int s3c24xx_clkout_setparent(struct clk *clk, struct clk *parent)
{
unsigned long mask;
unsigned long source;
if (parent == &clk_mpll)
source = S3C2410_MISCCR_CLK0_MPLL;
else if (parent == &clk_upll)
source = S3C2410_MISCCR_CLK0_UPLL;
else if (parent == &clk_f)
source = S3C2410_MISCCR_CLK0_FCLK;
else if (parent == &clk_h)
source = S3C2410_MISCCR_CLK0_HCLK;
else if (parent == &clk_p)
source = S3C2410_MISCCR_CLK0_PCLK;
else if (clk == &s3c24xx_clkout0 && parent == &s3c24xx_dclk0)
source = S3C2410_MISCCR_CLK0_DCLK0;
else if (clk == &s3c24xx_clkout1 && parent == &s3c24xx_dclk1)
source = S3C2410_MISCCR_CLK0_DCLK0;
else
return -EINVAL;
clk->parent = parent;
if (clk == &s3c24xx_clkout0)
mask = S3C2410_MISCCR_CLK0_MASK;
else {
source <<= 4;
mask = S3C2410_MISCCR_CLK1_MASK;
}
s3c2410_modify_misccr(mask, source);
return 0;
}
