int omap36xx_pwrdn_clk_enable_with_hsdiv_restore(struct clk_hw *clk)
{
struct clk_divider *parent;
struct clk_hw *parent_hw;
u32 dummy_v, orig_v;
struct clk_hw_omap *omap_clk = to_clk_hw_omap(clk);
int ret;
ret = omap2_dflt_clk_enable(clk);
parent_hw = __clk_get_hw(__clk_get_parent(clk->clk));
parent = to_clk_divider(parent_hw);
if (!ret) {
orig_v = omap2_clk_readl(omap_clk, parent->reg);
dummy_v = orig_v;
dummy_v ^= (1 << parent->shift);
omap2_clk_writel(dummy_v, omap_clk, parent->reg);
omap2_clk_writel(orig_v, omap_clk, parent->reg);
}
return ret;
}
