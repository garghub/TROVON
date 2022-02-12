static void omap3430es2_clk_ssi_find_idlest(struct clk *clk,
void __iomem **idlest_reg,
u8 *idlest_bit,
u8 *idlest_val)
{
u32 r;
r = (((__force u32)clk->enable_reg & ~0xf0) | 0x20);
*idlest_reg = (__force void __iomem *)r;
*idlest_bit = OMAP3430ES2_ST_SSI_IDLE_SHIFT;
*idlest_val = OMAP34XX_CM_IDLEST_VAL;
}
static void omap3430es2_clk_dss_usbhost_find_idlest(struct clk *clk,
void __iomem **idlest_reg,
u8 *idlest_bit,
u8 *idlest_val)
{
u32 r;
r = (((__force u32)clk->enable_reg & ~0xf0) | 0x20);
*idlest_reg = (__force void __iomem *)r;
*idlest_bit = OMAP3430ES2_ST_DSS_IDLE_SHIFT;
*idlest_val = OMAP34XX_CM_IDLEST_VAL;
}
static void omap3430es2_clk_hsotgusb_find_idlest(struct clk *clk,
void __iomem **idlest_reg,
u8 *idlest_bit,
u8 *idlest_val)
{
u32 r;
r = (((__force u32)clk->enable_reg & ~0xf0) | 0x20);
*idlest_reg = (__force void __iomem *)r;
*idlest_bit = OMAP3430ES2_ST_HSOTGUSB_IDLE_SHIFT;
*idlest_val = OMAP34XX_CM_IDLEST_VAL;
}
