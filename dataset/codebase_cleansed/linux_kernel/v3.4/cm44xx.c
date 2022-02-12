u32 omap4_cm1_read_inst_reg(s16 inst, u16 reg)
{
return __raw_readl(OMAP44XX_CM1_REGADDR(inst, reg));
}
void omap4_cm1_write_inst_reg(u32 val, s16 inst, u16 reg)
{
__raw_writel(val, OMAP44XX_CM1_REGADDR(inst, reg));
}
u32 omap4_cm2_read_inst_reg(s16 inst, u16 reg)
{
return __raw_readl(OMAP44XX_CM2_REGADDR(inst, reg));
}
void omap4_cm2_write_inst_reg(u32 val, s16 inst, u16 reg)
{
__raw_writel(val, OMAP44XX_CM2_REGADDR(inst, reg));
}
