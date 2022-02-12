void omap_prm_base_init(void)
{
_prm_bases[OMAP4430_PRM_PARTITION] = prm_base;
_prm_bases[OMAP4430_PRCM_MPU_PARTITION] = prcm_mpu_base;
}
s32 omap4_prmst_get_prm_dev_inst(void)
{
return prm_dev_inst;
}
void omap4_prminst_set_prm_dev_inst(s32 dev_inst)
{
prm_dev_inst = dev_inst;
}
u32 omap4_prminst_read_inst_reg(u8 part, s16 inst, u16 idx)
{
BUG_ON(part >= OMAP4_MAX_PRCM_PARTITIONS ||
part == OMAP4430_INVALID_PRCM_PARTITION ||
!_prm_bases[part]);
return readl_relaxed(_prm_bases[part] + inst + idx);
}
void omap4_prminst_write_inst_reg(u32 val, u8 part, s16 inst, u16 idx)
{
BUG_ON(part >= OMAP4_MAX_PRCM_PARTITIONS ||
part == OMAP4430_INVALID_PRCM_PARTITION ||
!_prm_bases[part]);
writel_relaxed(val, _prm_bases[part] + inst + idx);
}
u32 omap4_prminst_rmw_inst_reg_bits(u32 mask, u32 bits, u8 part, s16 inst,
u16 idx)
{
u32 v;
v = omap4_prminst_read_inst_reg(part, inst, idx);
v &= ~mask;
v |= bits;
omap4_prminst_write_inst_reg(v, part, inst, idx);
return v;
}
int omap4_prminst_is_hardreset_asserted(u8 shift, u8 part, s16 inst,
u16 rstctrl_offs)
{
u32 v;
v = omap4_prminst_read_inst_reg(part, inst, rstctrl_offs);
v &= 1 << shift;
v >>= shift;
return v;
}
int omap4_prminst_assert_hardreset(u8 shift, u8 part, s16 inst,
u16 rstctrl_offs)
{
u32 mask = 1 << shift;
omap4_prminst_rmw_inst_reg_bits(mask, mask, part, inst, rstctrl_offs);
return 0;
}
int omap4_prminst_deassert_hardreset(u8 shift, u8 st_shift, u8 part, s16 inst,
u16 rstctrl_offs, u16 rstst_offs)
{
int c;
u32 mask = 1 << shift;
u32 st_mask = 1 << st_shift;
if (omap4_prminst_is_hardreset_asserted(shift, part, inst,
rstctrl_offs) == 0)
return -EEXIST;
omap4_prminst_rmw_inst_reg_bits(0xffffffff, st_mask, part, inst,
rstst_offs);
omap4_prminst_rmw_inst_reg_bits(mask, 0, part, inst, rstctrl_offs);
omap_test_timeout(omap4_prminst_is_hardreset_asserted(st_shift, part,
inst, rstst_offs),
MAX_MODULE_HARDRESET_WAIT, c);
return (c == MAX_MODULE_HARDRESET_WAIT) ? -EBUSY : 0;
}
void omap4_prminst_global_warm_sw_reset(void)
{
u32 v;
s32 inst = omap4_prmst_get_prm_dev_inst();
if (inst == PRM_INSTANCE_UNKNOWN)
return;
v = omap4_prminst_read_inst_reg(OMAP4430_PRM_PARTITION, inst,
OMAP4_PRM_RSTCTRL_OFFSET);
v |= OMAP4430_RST_GLOBAL_WARM_SW_MASK;
omap4_prminst_write_inst_reg(v, OMAP4430_PRM_PARTITION,
inst, OMAP4_PRM_RSTCTRL_OFFSET);
v = omap4_prminst_read_inst_reg(OMAP4430_PRM_PARTITION,
inst, OMAP4_PRM_RSTCTRL_OFFSET);
}
