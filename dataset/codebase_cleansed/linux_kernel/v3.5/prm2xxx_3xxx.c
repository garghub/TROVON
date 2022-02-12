u32 omap2_prm_read_mod_reg(s16 module, u16 idx)
{
return __raw_readl(prm_base + module + idx);
}
void omap2_prm_write_mod_reg(u32 val, s16 module, u16 idx)
{
__raw_writel(val, prm_base + module + idx);
}
u32 omap2_prm_rmw_mod_reg_bits(u32 mask, u32 bits, s16 module, s16 idx)
{
u32 v;
v = omap2_prm_read_mod_reg(module, idx);
v &= ~mask;
v |= bits;
omap2_prm_write_mod_reg(v, module, idx);
return v;
}
u32 omap2_prm_read_mod_bits_shift(s16 domain, s16 idx, u32 mask)
{
u32 v;
v = omap2_prm_read_mod_reg(domain, idx);
v &= mask;
v >>= __ffs(mask);
return v;
}
u32 omap2_prm_set_mod_reg_bits(u32 bits, s16 module, s16 idx)
{
return omap2_prm_rmw_mod_reg_bits(bits, bits, module, idx);
}
u32 omap2_prm_clear_mod_reg_bits(u32 bits, s16 module, s16 idx)
{
return omap2_prm_rmw_mod_reg_bits(bits, 0x0, module, idx);
}
int omap2_prm_is_hardreset_asserted(s16 prm_mod, u8 shift)
{
if (!(cpu_is_omap24xx() || cpu_is_omap34xx()))
return -EINVAL;
return omap2_prm_read_mod_bits_shift(prm_mod, OMAP2_RM_RSTCTRL,
(1 << shift));
}
int omap2_prm_assert_hardreset(s16 prm_mod, u8 shift)
{
u32 mask;
if (!(cpu_is_omap24xx() || cpu_is_omap34xx()))
return -EINVAL;
mask = 1 << shift;
omap2_prm_rmw_mod_reg_bits(mask, mask, prm_mod, OMAP2_RM_RSTCTRL);
return 0;
}
int omap2_prm_deassert_hardreset(s16 prm_mod, u8 rst_shift, u8 st_shift)
{
u32 rst, st;
int c;
if (!(cpu_is_omap24xx() || cpu_is_omap34xx()))
return -EINVAL;
rst = 1 << rst_shift;
st = 1 << st_shift;
if (omap2_prm_read_mod_bits_shift(prm_mod, OMAP2_RM_RSTCTRL, rst) == 0)
return -EEXIST;
omap2_prm_rmw_mod_reg_bits(0xffffffff, st, prm_mod, OMAP2_RM_RSTST);
omap2_prm_rmw_mod_reg_bits(rst, 0, prm_mod, OMAP2_RM_RSTCTRL);
omap_test_timeout(omap2_prm_read_mod_bits_shift(prm_mod, OMAP2_RM_RSTST,
st),
MAX_MODULE_HARDRESET_WAIT, c);
return (c == MAX_MODULE_HARDRESET_WAIT) ? -EBUSY : 0;
}
u32 omap3_prm_vp_check_txdone(u8 vp_id)
{
struct omap3_vp *vp = &omap3_vp[vp_id];
u32 irqstatus;
irqstatus = omap2_prm_read_mod_reg(OCP_MOD,
OMAP3_PRM_IRQSTATUS_MPU_OFFSET);
return irqstatus & vp->tranxdone_status;
}
void omap3_prm_vp_clear_txdone(u8 vp_id)
{
struct omap3_vp *vp = &omap3_vp[vp_id];
omap2_prm_write_mod_reg(vp->tranxdone_status,
OCP_MOD, OMAP3_PRM_IRQSTATUS_MPU_OFFSET);
}
u32 omap3_prm_vcvp_read(u8 offset)
{
return omap2_prm_read_mod_reg(OMAP3430_GR_MOD, offset);
}
void omap3_prm_vcvp_write(u32 val, u8 offset)
{
omap2_prm_write_mod_reg(val, OMAP3430_GR_MOD, offset);
}
u32 omap3_prm_vcvp_rmw(u32 mask, u32 bits, u8 offset)
{
return omap2_prm_rmw_mod_reg_bits(mask, bits, OMAP3430_GR_MOD, offset);
}
void omap3xxx_prm_read_pending_irqs(unsigned long *events)
{
u32 mask, st;
mask = omap2_prm_read_mod_reg(OCP_MOD, OMAP3_PRM_IRQENABLE_MPU_OFFSET);
st = omap2_prm_read_mod_reg(OCP_MOD, OMAP3_PRM_IRQSTATUS_MPU_OFFSET);
events[0] = mask & st;
}
void omap3xxx_prm_ocp_barrier(void)
{
omap2_prm_read_mod_reg(OCP_MOD, OMAP3_PRM_REVISION_OFFSET);
}
void omap3xxx_prm_save_and_clear_irqen(u32 *saved_mask)
{
saved_mask[0] = omap2_prm_read_mod_reg(OCP_MOD,
OMAP3_PRM_IRQENABLE_MPU_OFFSET);
omap2_prm_write_mod_reg(0, OCP_MOD, OMAP3_PRM_IRQENABLE_MPU_OFFSET);
omap2_prm_read_mod_reg(OCP_MOD, OMAP3_PRM_REVISION_OFFSET);
}
void omap3xxx_prm_restore_irqen(u32 *saved_mask)
{
omap2_prm_write_mod_reg(saved_mask[0], OCP_MOD,
OMAP3_PRM_IRQENABLE_MPU_OFFSET);
}
static int __init omap3xxx_prcm_init(void)
{
int ret = 0;
if (cpu_is_omap34xx()) {
ret = omap_prcm_register_chain_handler(&omap3_prcm_irq_setup);
if (!ret)
irq_set_status_flags(omap_prcm_event_to_irq("io"),
IRQ_NOAUTOEN);
}
return ret;
}
