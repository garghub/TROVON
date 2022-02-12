u32 omap4_prm_read_inst_reg(s16 inst, u16 reg)
{
return __raw_readl(OMAP44XX_PRM_REGADDR(inst, reg));
}
void omap4_prm_write_inst_reg(u32 val, s16 inst, u16 reg)
{
__raw_writel(val, OMAP44XX_PRM_REGADDR(inst, reg));
}
u32 omap4_prm_rmw_inst_reg_bits(u32 mask, u32 bits, s16 inst, s16 reg)
{
u32 v;
v = omap4_prm_read_inst_reg(inst, reg);
v &= ~mask;
v |= bits;
omap4_prm_write_inst_reg(v, inst, reg);
return v;
}
u32 omap4_prm_read_bits_shift(void __iomem *reg, u32 mask)
{
u32 v;
v = __raw_readl(reg);
v &= mask;
v >>= __ffs(mask);
return v;
}
u32 omap4_prm_rmw_reg_bits(u32 mask, u32 bits, void __iomem *reg)
{
u32 v;
v = __raw_readl(reg);
v &= ~mask;
v |= bits;
__raw_writel(v, reg);
return v;
}
u32 omap4_prm_set_inst_reg_bits(u32 bits, s16 inst, s16 reg)
{
return omap4_prm_rmw_inst_reg_bits(bits, bits, inst, reg);
}
u32 omap4_prm_clear_inst_reg_bits(u32 bits, s16 inst, s16 reg)
{
return omap4_prm_rmw_inst_reg_bits(bits, 0x0, inst, reg);
}
int omap4_prm_is_hardreset_asserted(void __iomem *rstctrl_reg, u8 shift)
{
if (!cpu_is_omap44xx() || !rstctrl_reg)
return -EINVAL;
return omap4_prm_read_bits_shift(rstctrl_reg, (1 << shift));
}
int omap4_prm_assert_hardreset(void __iomem *rstctrl_reg, u8 shift)
{
u32 mask;
if (!cpu_is_omap44xx() || !rstctrl_reg)
return -EINVAL;
mask = 1 << shift;
omap4_prm_rmw_reg_bits(mask, mask, rstctrl_reg);
return 0;
}
int omap4_prm_deassert_hardreset(void __iomem *rstctrl_reg, u8 shift)
{
u32 mask;
void __iomem *rstst_reg;
int c;
if (!cpu_is_omap44xx() || !rstctrl_reg)
return -EINVAL;
rstst_reg = rstctrl_reg + OMAP4_RST_CTRL_ST_OFFSET;
mask = 1 << shift;
if (omap4_prm_read_bits_shift(rstctrl_reg, mask) == 0)
return -EEXIST;
omap4_prm_rmw_reg_bits(0xffffffff, mask, rstst_reg);
omap4_prm_rmw_reg_bits(mask, 0, rstctrl_reg);
omap_test_timeout(omap4_prm_read_bits_shift(rstst_reg, mask),
MAX_MODULE_HARDRESET_WAIT, c);
return (c == MAX_MODULE_HARDRESET_WAIT) ? -EBUSY : 0;
}
void omap4_prm_global_warm_sw_reset(void)
{
u32 v;
v = omap4_prm_read_inst_reg(OMAP4430_PRM_DEVICE_INST,
OMAP4_RM_RSTCTRL);
v |= OMAP4430_RST_GLOBAL_WARM_SW_MASK;
omap4_prm_write_inst_reg(v, OMAP4430_PRM_DEVICE_INST,
OMAP4_RM_RSTCTRL);
v = omap4_prm_read_inst_reg(OMAP4430_PRM_DEVICE_INST,
OMAP4_RM_RSTCTRL);
}
