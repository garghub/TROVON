void omap2_clkt_iclk_allow_idle(struct clk *clk)
{
u32 v, r;
r = ((__force u32)clk->enable_reg ^ (CM_AUTOIDLE ^ CM_ICLKEN));
v = __raw_readl((__force void __iomem *)r);
v |= (1 << clk->enable_bit);
__raw_writel(v, (__force void __iomem *)r);
}
void omap2_clkt_iclk_deny_idle(struct clk *clk)
{
u32 v, r;
r = ((__force u32)clk->enable_reg ^ (CM_AUTOIDLE ^ CM_ICLKEN));
v = __raw_readl((__force void __iomem *)r);
v &= ~(1 << clk->enable_bit);
__raw_writel(v, (__force void __iomem *)r);
}
