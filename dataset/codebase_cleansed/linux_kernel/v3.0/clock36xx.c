static int omap36xx_pwrdn_clk_enable_with_hsdiv_restore(struct clk *clk)
{
u32 dummy_v, orig_v, clksel_shift;
int ret;
ret = omap2_dflt_clk_enable(clk);
if (!ret) {
clksel_shift = __ffs(clk->parent->clksel_mask);
orig_v = __raw_readl(clk->parent->clksel_reg);
dummy_v = orig_v;
dummy_v ^= (1 << clksel_shift);
__raw_writel(dummy_v, clk->parent->clksel_reg);
__raw_writel(orig_v, clk->parent->clksel_reg);
}
return ret;
}
