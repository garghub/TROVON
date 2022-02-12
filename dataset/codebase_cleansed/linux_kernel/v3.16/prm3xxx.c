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
void omap3xxx_prm_dpll3_reset(void)
{
omap2_prm_set_mod_reg_bits(OMAP_RST_DPLL3_MASK, OMAP3430_GR_MOD,
OMAP2_RM_RSTCTRL);
omap2_prm_read_mod_reg(OMAP3430_GR_MOD, OMAP2_RM_RSTCTRL);
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
void omap3xxx_prm_reconfigure_io_chain(void)
{
int i = 0;
omap2_prm_set_mod_reg_bits(OMAP3430_EN_IO_CHAIN_MASK, WKUP_MOD,
PM_WKEN);
omap_test_timeout(omap2_prm_read_mod_reg(WKUP_MOD, PM_WKST) &
OMAP3430_ST_IO_CHAIN_MASK,
MAX_IOPAD_LATCH_TIME, i);
if (i == MAX_IOPAD_LATCH_TIME)
pr_warn("PRM: I/O chain clock line assertion timed out\n");
omap2_prm_clear_mod_reg_bits(OMAP3430_EN_IO_CHAIN_MASK, WKUP_MOD,
PM_WKEN);
omap2_prm_set_mod_reg_bits(OMAP3430_ST_IO_CHAIN_MASK, WKUP_MOD,
PM_WKST);
omap2_prm_read_mod_reg(WKUP_MOD, PM_WKST);
}
static void __init omap3xxx_prm_enable_io_wakeup(void)
{
if (prm_features & PRM_HAS_IO_WAKEUP)
omap2_prm_set_mod_reg_bits(OMAP3430_EN_IO_MASK, WKUP_MOD,
PM_WKEN);
}
static u32 omap3xxx_prm_read_reset_sources(void)
{
struct prm_reset_src_map *p;
u32 r = 0;
u32 v;
v = omap2_prm_read_mod_reg(WKUP_MOD, OMAP2_RM_RSTST);
p = omap3xxx_prm_reset_src_map;
while (p->reg_shift >= 0 && p->std_shift >= 0) {
if (v & (1 << p->reg_shift))
r |= 1 << p->std_shift;
p++;
}
return r;
}
static int omap3_pwrdm_set_next_pwrst(struct powerdomain *pwrdm, u8 pwrst)
{
omap2_prm_rmw_mod_reg_bits(OMAP_POWERSTATE_MASK,
(pwrst << OMAP_POWERSTATE_SHIFT),
pwrdm->prcm_offs, OMAP2_PM_PWSTCTRL);
return 0;
}
static int omap3_pwrdm_read_next_pwrst(struct powerdomain *pwrdm)
{
return omap2_prm_read_mod_bits_shift(pwrdm->prcm_offs,
OMAP2_PM_PWSTCTRL,
OMAP_POWERSTATE_MASK);
}
static int omap3_pwrdm_read_pwrst(struct powerdomain *pwrdm)
{
return omap2_prm_read_mod_bits_shift(pwrdm->prcm_offs,
OMAP2_PM_PWSTST,
OMAP_POWERSTATEST_MASK);
}
static int omap3_pwrdm_read_prev_pwrst(struct powerdomain *pwrdm)
{
return omap2_prm_read_mod_bits_shift(pwrdm->prcm_offs,
OMAP3430_PM_PREPWSTST,
OMAP3430_LASTPOWERSTATEENTERED_MASK);
}
static int omap3_pwrdm_read_logic_pwrst(struct powerdomain *pwrdm)
{
return omap2_prm_read_mod_bits_shift(pwrdm->prcm_offs,
OMAP2_PM_PWSTST,
OMAP3430_LOGICSTATEST_MASK);
}
static int omap3_pwrdm_read_logic_retst(struct powerdomain *pwrdm)
{
return omap2_prm_read_mod_bits_shift(pwrdm->prcm_offs,
OMAP2_PM_PWSTCTRL,
OMAP3430_LOGICSTATEST_MASK);
}
static int omap3_pwrdm_read_prev_logic_pwrst(struct powerdomain *pwrdm)
{
return omap2_prm_read_mod_bits_shift(pwrdm->prcm_offs,
OMAP3430_PM_PREPWSTST,
OMAP3430_LASTLOGICSTATEENTERED_MASK);
}
static int omap3_get_mem_bank_lastmemst_mask(u8 bank)
{
switch (bank) {
case 0:
return OMAP3430_LASTMEM1STATEENTERED_MASK;
case 1:
return OMAP3430_LASTMEM2STATEENTERED_MASK;
case 2:
return OMAP3430_LASTSHAREDL2CACHEFLATSTATEENTERED_MASK;
case 3:
return OMAP3430_LASTL2FLATMEMSTATEENTERED_MASK;
default:
WARN_ON(1);
return -EEXIST;
}
return 0;
}
static int omap3_pwrdm_read_prev_mem_pwrst(struct powerdomain *pwrdm, u8 bank)
{
u32 m;
m = omap3_get_mem_bank_lastmemst_mask(bank);
return omap2_prm_read_mod_bits_shift(pwrdm->prcm_offs,
OMAP3430_PM_PREPWSTST, m);
}
static int omap3_pwrdm_clear_all_prev_pwrst(struct powerdomain *pwrdm)
{
omap2_prm_write_mod_reg(0, pwrdm->prcm_offs, OMAP3430_PM_PREPWSTST);
return 0;
}
static int omap3_pwrdm_enable_hdwr_sar(struct powerdomain *pwrdm)
{
return omap2_prm_rmw_mod_reg_bits(0,
1 << OMAP3430ES2_SAVEANDRESTORE_SHIFT,
pwrdm->prcm_offs, OMAP2_PM_PWSTCTRL);
}
static int omap3_pwrdm_disable_hdwr_sar(struct powerdomain *pwrdm)
{
return omap2_prm_rmw_mod_reg_bits(1 << OMAP3430ES2_SAVEANDRESTORE_SHIFT,
0, pwrdm->prcm_offs,
OMAP2_PM_PWSTCTRL);
}
int __init omap3xxx_prm_init(void)
{
if (omap3_has_io_wakeup())
prm_features |= PRM_HAS_IO_WAKEUP;
return prm_register(&omap3xxx_prm_ll_data);
}
static int omap3xxx_prm_late_init(void)
{
int ret;
if (!(prm_features & PRM_HAS_IO_WAKEUP))
return 0;
omap3xxx_prm_enable_io_wakeup();
ret = omap_prcm_register_chain_handler(&omap3_prcm_irq_setup);
if (!ret)
irq_set_status_flags(omap_prcm_event_to_irq("io"),
IRQ_NOAUTOEN);
return ret;
}
static void __exit omap3xxx_prm_exit(void)
{
prm_unregister(&omap3xxx_prm_ll_data);
}
