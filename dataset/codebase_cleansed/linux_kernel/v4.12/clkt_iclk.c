void omap2_clkt_iclk_allow_idle(struct clk_hw_omap *clk)
{
u32 v;
struct clk_omap_reg r;
memcpy(&r, &clk->enable_reg, sizeof(r));
r.offset ^= (CM_AUTOIDLE ^ CM_ICLKEN);
v = ti_clk_ll_ops->clk_readl(&r);
v |= (1 << clk->enable_bit);
ti_clk_ll_ops->clk_writel(v, &r);
}
void omap2_clkt_iclk_deny_idle(struct clk_hw_omap *clk)
{
u32 v;
struct clk_omap_reg r;
memcpy(&r, &clk->enable_reg, sizeof(r));
r.offset ^= (CM_AUTOIDLE ^ CM_ICLKEN);
v = ti_clk_ll_ops->clk_readl(&r);
v &= ~(1 << clk->enable_bit);
ti_clk_ll_ops->clk_writel(v, &r);
}
static void omap2430_clk_i2chs_find_idlest(struct clk_hw_omap *clk,
struct clk_omap_reg *idlest_reg,
u8 *idlest_bit,
u8 *idlest_val)
{
memcpy(idlest_reg, &clk->enable_reg, sizeof(*idlest_reg));
idlest_reg->offset ^= (OMAP24XX_CM_FCLKEN2 ^ CM_IDLEST);
*idlest_bit = clk->enable_bit;
*idlest_val = OMAP24XX_CM_IDLEST_VAL;
}
