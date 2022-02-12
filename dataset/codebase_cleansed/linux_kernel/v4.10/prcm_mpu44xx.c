u32 omap4_prcm_mpu_read_inst_reg(s16 inst, u16 reg)
{
return readl_relaxed(OMAP44XX_PRCM_MPU_REGADDR(inst, reg));
}
void omap4_prcm_mpu_write_inst_reg(u32 val, s16 inst, u16 reg)
{
writel_relaxed(val, OMAP44XX_PRCM_MPU_REGADDR(inst, reg));
}
u32 omap4_prcm_mpu_rmw_inst_reg_bits(u32 mask, u32 bits, s16 inst, s16 reg)
{
u32 v;
v = omap4_prcm_mpu_read_inst_reg(inst, reg);
v &= ~mask;
v |= bits;
omap4_prcm_mpu_write_inst_reg(v, inst, reg);
return v;
}
void __init omap2_set_globals_prcm_mpu(void __iomem *prcm_mpu)
{
prcm_mpu_base = prcm_mpu;
}
