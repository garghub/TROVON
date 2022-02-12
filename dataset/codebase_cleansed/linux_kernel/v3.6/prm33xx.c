u32 am33xx_prm_read_reg(s16 inst, u16 idx)
{
return __raw_readl(prm_base + inst + idx);
}
void am33xx_prm_write_reg(u32 val, s16 inst, u16 idx)
{
__raw_writel(val, prm_base + inst + idx);
}
u32 am33xx_prm_rmw_reg_bits(u32 mask, u32 bits, s16 inst, s16 idx)
{
u32 v;
v = am33xx_prm_read_reg(inst, idx);
v &= ~mask;
v |= bits;
am33xx_prm_write_reg(v, inst, idx);
return v;
}
int am33xx_prm_is_hardreset_asserted(u8 shift, s16 inst, u16 rstctrl_offs)
{
u32 v;
v = am33xx_prm_read_reg(inst, rstctrl_offs);
v &= 1 << shift;
v >>= shift;
return v;
}
int am33xx_prm_assert_hardreset(u8 shift, s16 inst, u16 rstctrl_offs)
{
u32 mask = 1 << shift;
am33xx_prm_rmw_reg_bits(mask, mask, inst, rstctrl_offs);
return 0;
}
int am33xx_prm_deassert_hardreset(u8 shift, s16 inst,
u16 rstctrl_offs, u16 rstst_offs)
{
int c;
u32 mask = 1 << shift;
if (am33xx_prm_is_hardreset_asserted(shift, inst, rstctrl_offs) == 0)
return -EEXIST;
am33xx_prm_rmw_reg_bits(0xffffffff, mask, inst, rstst_offs);
am33xx_prm_rmw_reg_bits(mask, 0, inst, rstctrl_offs);
omap_test_timeout(am33xx_prm_is_hardreset_asserted(shift, inst,
rstst_offs),
MAX_MODULE_HARDRESET_WAIT, c);
return (c == MAX_MODULE_HARDRESET_WAIT) ? -EBUSY : 0;
}
