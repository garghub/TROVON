static void am35xx_clk_find_idlest(struct clk *clk,
void __iomem **idlest_reg,
u8 *idlest_bit,
u8 *idlest_val)
{
*idlest_reg = (__force void __iomem *)(clk->enable_reg);
*idlest_bit = clk->enable_bit + AM35XX_IPSS_ICK_EN_ACK_OFFSET;
*idlest_val = AM35XX_IPSS_CLK_IDLEST_VAL;
}
static void am35xx_clk_find_companion(struct clk *clk, void __iomem **other_reg,
u8 *other_bit)
{
*other_reg = (__force void __iomem *)(clk->enable_reg);
if (clk->enable_bit & AM35XX_IPSS_ICK_MASK)
*other_bit = clk->enable_bit + AM35XX_IPSS_ICK_FCK_OFFSET;
else
*other_bit = clk->enable_bit - AM35XX_IPSS_ICK_FCK_OFFSET;
}
static void am35xx_clk_ipss_find_idlest(struct clk *clk,
void __iomem **idlest_reg,
u8 *idlest_bit,
u8 *idlest_val)
{
u32 r;
r = (((__force u32)clk->enable_reg & ~0xf0) | 0x20);
*idlest_reg = (__force void __iomem *)r;
*idlest_bit = AM35XX_ST_IPSS_SHIFT;
*idlest_val = OMAP34XX_CM_IDLEST_VAL;
}
