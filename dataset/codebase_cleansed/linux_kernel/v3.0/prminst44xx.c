u32 omap4_prminst_read_inst_reg(u8 part, s16 inst, u16 idx)
{
BUG_ON(part >= OMAP4_MAX_PRCM_PARTITIONS ||
part == OMAP4430_INVALID_PRCM_PARTITION ||
!_prm_bases[part]);
return __raw_readl(OMAP2_L4_IO_ADDRESS(_prm_bases[part] + inst +
idx));
}
void omap4_prminst_write_inst_reg(u32 val, u8 part, s16 inst, u16 idx)
{
BUG_ON(part >= OMAP4_MAX_PRCM_PARTITIONS ||
part == OMAP4430_INVALID_PRCM_PARTITION ||
!_prm_bases[part]);
__raw_writel(val, OMAP2_L4_IO_ADDRESS(_prm_bases[part] + inst + idx));
}
u32 omap4_prminst_rmw_inst_reg_bits(u32 mask, u32 bits, u8 part, s16 inst,
s16 idx)
{
u32 v;
v = omap4_prminst_read_inst_reg(part, inst, idx);
v &= ~mask;
v |= bits;
omap4_prminst_write_inst_reg(v, part, inst, idx);
return v;
}
