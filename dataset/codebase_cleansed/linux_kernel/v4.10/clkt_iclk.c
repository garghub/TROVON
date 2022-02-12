void omap2_clkt_iclk_allow_idle(struct clk_hw_omap *clk)
{
u32 v;
void __iomem *r;
r = (__force void __iomem *)
((__force u32)clk->enable_reg ^ (CM_AUTOIDLE ^ CM_ICLKEN));
v = ti_clk_ll_ops->clk_readl(r);
v |= (1 << clk->enable_bit);
ti_clk_ll_ops->clk_writel(v, r);
}
void omap2_clkt_iclk_deny_idle(struct clk_hw_omap *clk)
{
u32 v;
void __iomem *r;
r = (__force void __iomem *)
((__force u32)clk->enable_reg ^ (CM_AUTOIDLE ^ CM_ICLKEN));
v = ti_clk_ll_ops->clk_readl(r);
v &= ~(1 << clk->enable_bit);
ti_clk_ll_ops->clk_writel(v, r);
}
static void omap2430_clk_i2chs_find_idlest(struct clk_hw_omap *clk,
void __iomem **idlest_reg,
u8 *idlest_bit,
u8 *idlest_val)
{
u32 r;
r = ((__force u32)clk->enable_reg ^ (OMAP24XX_CM_FCLKEN2 ^ CM_IDLEST));
*idlest_reg = (__force void __iomem *)r;
*idlest_bit = clk->enable_bit;
*idlest_val = OMAP24XX_CM_IDLEST_VAL;
}
