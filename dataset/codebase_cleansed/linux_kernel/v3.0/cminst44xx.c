u32 omap4_cminst_read_inst_reg(u8 part, s16 inst, u16 idx)
{
BUG_ON(part >= OMAP4_MAX_PRCM_PARTITIONS ||
part == OMAP4430_INVALID_PRCM_PARTITION ||
!_cm_bases[part]);
return __raw_readl(OMAP2_L4_IO_ADDRESS(_cm_bases[part] + inst + idx));
}
void omap4_cminst_write_inst_reg(u32 val, u8 part, s16 inst, u16 idx)
{
BUG_ON(part >= OMAP4_MAX_PRCM_PARTITIONS ||
part == OMAP4430_INVALID_PRCM_PARTITION ||
!_cm_bases[part]);
__raw_writel(val, OMAP2_L4_IO_ADDRESS(_cm_bases[part] + inst + idx));
}
u32 omap4_cminst_rmw_inst_reg_bits(u32 mask, u32 bits, u8 part, s16 inst,
s16 idx)
{
u32 v;
v = omap4_cminst_read_inst_reg(part, inst, idx);
v &= ~mask;
v |= bits;
omap4_cminst_write_inst_reg(v, part, inst, idx);
return v;
}
u32 omap4_cminst_set_inst_reg_bits(u32 bits, u8 part, s16 inst, s16 idx)
{
return omap4_cminst_rmw_inst_reg_bits(bits, bits, part, inst, idx);
}
u32 omap4_cminst_clear_inst_reg_bits(u32 bits, u8 part, s16 inst, s16 idx)
{
return omap4_cminst_rmw_inst_reg_bits(bits, 0x0, part, inst, idx);
}
u32 omap4_cminst_read_inst_reg_bits(u8 part, u16 inst, s16 idx, u32 mask)
{
u32 v;
v = omap4_cminst_read_inst_reg(part, inst, idx);
v &= mask;
v >>= __ffs(mask);
return v;
}
static void _clktrctrl_write(u8 c, u8 part, s16 inst, u16 cdoffs)
{
u32 v;
v = omap4_cminst_read_inst_reg(part, inst, cdoffs + OMAP4_CM_CLKSTCTRL);
v &= ~OMAP4430_CLKTRCTRL_MASK;
v |= c << OMAP4430_CLKTRCTRL_SHIFT;
omap4_cminst_write_inst_reg(v, part, inst, cdoffs + OMAP4_CM_CLKSTCTRL);
}
bool omap4_cminst_is_clkdm_in_hwsup(u8 part, s16 inst, u16 cdoffs)
{
u32 v;
v = omap4_cminst_read_inst_reg(part, inst, cdoffs + OMAP4_CM_CLKSTCTRL);
v &= OMAP4430_CLKTRCTRL_MASK;
v >>= OMAP4430_CLKTRCTRL_SHIFT;
return (v == OMAP34XX_CLKSTCTRL_ENABLE_AUTO) ? true : false;
}
void omap4_cminst_clkdm_enable_hwsup(u8 part, s16 inst, u16 cdoffs)
{
_clktrctrl_write(OMAP34XX_CLKSTCTRL_ENABLE_AUTO, part, inst, cdoffs);
}
void omap4_cminst_clkdm_disable_hwsup(u8 part, s16 inst, u16 cdoffs)
{
_clktrctrl_write(OMAP34XX_CLKSTCTRL_DISABLE_AUTO, part, inst, cdoffs);
}
void omap4_cminst_clkdm_force_sleep(u8 part, s16 inst, u16 cdoffs)
{
_clktrctrl_write(OMAP34XX_CLKSTCTRL_FORCE_SLEEP, part, inst, cdoffs);
}
void omap4_cminst_clkdm_force_wakeup(u8 part, s16 inst, u16 cdoffs)
{
_clktrctrl_write(OMAP34XX_CLKSTCTRL_FORCE_WAKEUP, part, inst, cdoffs);
}
int omap4_cm_wait_module_ready(void __iomem *clkctrl_reg)
{
int i = 0;
if (!clkctrl_reg)
return 0;
omap_test_timeout((
((__raw_readl(clkctrl_reg) & OMAP4430_IDLEST_MASK) == 0) ||
(((__raw_readl(clkctrl_reg) & OMAP4430_IDLEST_MASK) >>
OMAP4430_IDLEST_SHIFT) == 0x2)),
MAX_MODULE_READY_TIME, i);
return (i < MAX_MODULE_READY_TIME) ? 0 : -EBUSY;
}
