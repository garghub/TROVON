void omap2_clkt_iclk_allow_idle(struct clk_hw_omap *clk)
{
u32 v;
void __iomem *r;
r = (__force void __iomem *)
((__force u32)clk->enable_reg ^ (CM_AUTOIDLE ^ CM_ICLKEN));
v = omap2_clk_readl(clk, r);
v |= (1 << clk->enable_bit);
omap2_clk_writel(v, clk, r);
}
void omap2_clkt_iclk_deny_idle(struct clk_hw_omap *clk)
{
u32 v;
void __iomem *r;
r = (__force void __iomem *)
((__force u32)clk->enable_reg ^ (CM_AUTOIDLE ^ CM_ICLKEN));
v = omap2_clk_readl(clk, r);
v &= ~(1 << clk->enable_bit);
omap2_clk_writel(v, clk, r);
}
