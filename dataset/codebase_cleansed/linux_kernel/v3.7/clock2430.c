static void omap2430_clk_i2chs_find_idlest(struct clk *clk,
void __iomem **idlest_reg,
u8 *idlest_bit,
u8 *idlest_val)
{
*idlest_reg = OMAP2430_CM_REGADDR(CORE_MOD, CM_IDLEST);
*idlest_bit = clk->enable_bit;
*idlest_val = OMAP24XX_CM_IDLEST_VAL;
}
