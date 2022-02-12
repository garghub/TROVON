int omap36xx_pwrdn_clk_enable_with_hsdiv_restore(struct clk_hw *clk)
{
struct clk_hw_omap *parent;
struct clk_hw *parent_hw;
u32 dummy_v, orig_v, clksel_shift;
int ret;
ret = omap2_dflt_clk_enable(clk);
parent_hw = __clk_get_hw(__clk_get_parent(clk->clk));
parent = to_clk_hw_omap(parent_hw);
if (!ret) {
clksel_shift = __ffs(parent->clksel_mask);
orig_v = __raw_readl(parent->clksel_reg);
dummy_v = orig_v;
dummy_v ^= (1 << clksel_shift);
__raw_writel(dummy_v, parent->clksel_reg);
__raw_writel(orig_v, parent->clksel_reg);
}
return ret;
}
