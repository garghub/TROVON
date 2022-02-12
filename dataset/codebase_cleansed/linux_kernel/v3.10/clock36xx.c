int omap36xx_pwrdn_clk_enable_with_hsdiv_restore(struct clk_hw *clk)
{
struct clk_divider *parent;
struct clk_hw *parent_hw;
u32 dummy_v, orig_v;
int ret;
ret = omap2_dflt_clk_enable(clk);
parent_hw = __clk_get_hw(__clk_get_parent(clk->clk));
parent = to_clk_divider(parent_hw);
if (!ret) {
orig_v = __raw_readl(parent->reg);
dummy_v = orig_v;
dummy_v ^= (1 << parent->shift);
__raw_writel(dummy_v, parent->reg);
__raw_writel(orig_v, parent->reg);
}
return ret;
}
