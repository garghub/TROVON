u32 omap4_cm1_read_inst_reg(s16 inst, u16 reg)
{
return readl_relaxed(cm_base + inst + reg);
}
void omap4_cm1_write_inst_reg(u32 val, s16 inst, u16 reg)
{
writel_relaxed(val, cm_base + inst + reg);
}
u32 omap4_cm2_read_inst_reg(s16 inst, u16 reg)
{
return readl_relaxed(cm2_base + inst + reg);
}
void omap4_cm2_write_inst_reg(u32 val, s16 inst, u16 reg)
{
writel_relaxed(val, cm2_base + inst + reg);
}
