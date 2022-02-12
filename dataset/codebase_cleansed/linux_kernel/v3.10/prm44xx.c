u32 omap4_prm_read_inst_reg(s16 inst, u16 reg)
{
return __raw_readl(prm_base + inst + reg);
}
void omap4_prm_write_inst_reg(u32 val, s16 inst, u16 reg)
{
__raw_writel(val, prm_base + inst + reg);
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
u32 omap4_prm_vp_check_txdone(u8 vp_id)
{
struct omap4_vp *vp = &omap4_vp[vp_id];
u32 irqstatus;
irqstatus = omap4_prminst_read_inst_reg(OMAP4430_PRM_PARTITION,
OMAP4430_PRM_OCP_SOCKET_INST,
vp->irqstatus_mpu);
return irqstatus & vp->tranxdone_status;
}
void omap4_prm_vp_clear_txdone(u8 vp_id)
{
struct omap4_vp *vp = &omap4_vp[vp_id];
omap4_prminst_write_inst_reg(vp->tranxdone_status,
OMAP4430_PRM_PARTITION,
OMAP4430_PRM_OCP_SOCKET_INST,
vp->irqstatus_mpu);
}
u32 omap4_prm_vcvp_read(u8 offset)
{
return omap4_prminst_read_inst_reg(OMAP4430_PRM_PARTITION,
OMAP4430_PRM_DEVICE_INST, offset);
}
void omap4_prm_vcvp_write(u32 val, u8 offset)
{
omap4_prminst_write_inst_reg(val, OMAP4430_PRM_PARTITION,
OMAP4430_PRM_DEVICE_INST, offset);
}
u32 omap4_prm_vcvp_rmw(u32 mask, u32 bits, u8 offset)
{
return omap4_prminst_rmw_inst_reg_bits(mask, bits,
OMAP4430_PRM_PARTITION,
OMAP4430_PRM_DEVICE_INST,
offset);
}
static inline u32 _read_pending_irq_reg(u16 irqen_offs, u16 irqst_offs)
{
u32 mask, st;
mask = omap4_prm_read_inst_reg(OMAP4430_PRM_OCP_SOCKET_INST,
irqen_offs);
st = omap4_prm_read_inst_reg(OMAP4430_PRM_OCP_SOCKET_INST, irqst_offs);
return mask & st;
}
void omap44xx_prm_read_pending_irqs(unsigned long *events)
{
events[0] = _read_pending_irq_reg(OMAP4_PRM_IRQENABLE_MPU_OFFSET,
OMAP4_PRM_IRQSTATUS_MPU_OFFSET);
events[1] = _read_pending_irq_reg(OMAP4_PRM_IRQENABLE_MPU_2_OFFSET,
OMAP4_PRM_IRQSTATUS_MPU_2_OFFSET);
}
void omap44xx_prm_ocp_barrier(void)
{
omap4_prm_read_inst_reg(OMAP4430_PRM_OCP_SOCKET_INST,
OMAP4_REVISION_PRM_OFFSET);
}
void omap44xx_prm_save_and_clear_irqen(u32 *saved_mask)
{
saved_mask[0] =
omap4_prm_read_inst_reg(OMAP4430_PRM_OCP_SOCKET_INST,
OMAP4_PRM_IRQSTATUS_MPU_OFFSET);
saved_mask[1] =
omap4_prm_read_inst_reg(OMAP4430_PRM_OCP_SOCKET_INST,
OMAP4_PRM_IRQSTATUS_MPU_2_OFFSET);
omap4_prm_write_inst_reg(0, OMAP4430_PRM_OCP_SOCKET_INST,
OMAP4_PRM_IRQENABLE_MPU_OFFSET);
omap4_prm_write_inst_reg(0, OMAP4430_PRM_OCP_SOCKET_INST,
OMAP4_PRM_IRQENABLE_MPU_2_OFFSET);
omap4_prm_read_inst_reg(OMAP4430_PRM_OCP_SOCKET_INST,
OMAP4_REVISION_PRM_OFFSET);
}
void omap44xx_prm_restore_irqen(u32 *saved_mask)
{
omap4_prm_write_inst_reg(saved_mask[0], OMAP4430_PRM_OCP_SOCKET_INST,
OMAP4_PRM_IRQENABLE_MPU_OFFSET);
omap4_prm_write_inst_reg(saved_mask[1], OMAP4430_PRM_OCP_SOCKET_INST,
OMAP4_PRM_IRQENABLE_MPU_2_OFFSET);
}
void omap44xx_prm_reconfigure_io_chain(void)
{
int i = 0;
omap4_prm_rmw_inst_reg_bits(OMAP4430_WUCLK_CTRL_MASK,
OMAP4430_WUCLK_CTRL_MASK,
OMAP4430_PRM_DEVICE_INST,
OMAP4_PRM_IO_PMCTRL_OFFSET);
omap_test_timeout(
(((omap4_prm_read_inst_reg(OMAP4430_PRM_DEVICE_INST,
OMAP4_PRM_IO_PMCTRL_OFFSET) &
OMAP4430_WUCLK_STATUS_MASK) >>
OMAP4430_WUCLK_STATUS_SHIFT) == 1),
MAX_IOPAD_LATCH_TIME, i);
if (i == MAX_IOPAD_LATCH_TIME)
pr_warn("PRM: I/O chain clock line assertion timed out\n");
omap4_prm_rmw_inst_reg_bits(OMAP4430_WUCLK_CTRL_MASK, 0x0,
OMAP4430_PRM_DEVICE_INST,
OMAP4_PRM_IO_PMCTRL_OFFSET);
omap_test_timeout(
(((omap4_prm_read_inst_reg(OMAP4430_PRM_DEVICE_INST,
OMAP4_PRM_IO_PMCTRL_OFFSET) &
OMAP4430_WUCLK_STATUS_MASK) >>
OMAP4430_WUCLK_STATUS_SHIFT) == 0),
MAX_IOPAD_LATCH_TIME, i);
if (i == MAX_IOPAD_LATCH_TIME)
pr_warn("PRM: I/O chain clock line deassertion timed out\n");
return;
}
static void __init omap44xx_prm_enable_io_wakeup(void)
{
omap4_prm_rmw_inst_reg_bits(OMAP4430_GLOBAL_WUEN_MASK,
OMAP4430_GLOBAL_WUEN_MASK,
OMAP4430_PRM_DEVICE_INST,
OMAP4_PRM_IO_PMCTRL_OFFSET);
}
static u32 omap44xx_prm_read_reset_sources(void)
{
struct prm_reset_src_map *p;
u32 r = 0;
u32 v;
v = omap4_prm_read_inst_reg(OMAP4430_PRM_DEVICE_INST,
OMAP4_RM_RSTST);
p = omap44xx_prm_reset_src_map;
while (p->reg_shift >= 0 && p->std_shift >= 0) {
if (v & (1 << p->reg_shift))
r |= 1 << p->std_shift;
p++;
}
return r;
}
static bool omap44xx_prm_was_any_context_lost_old(u8 part, s16 inst, u16 idx)
{
return (omap4_prminst_read_inst_reg(part, inst, idx)) ? 1 : 0;
}
static void omap44xx_prm_clear_context_loss_flags_old(u8 part, s16 inst,
u16 idx)
{
omap4_prminst_write_inst_reg(0xffffffff, part, inst, idx);
}
static int omap4_pwrdm_set_next_pwrst(struct powerdomain *pwrdm, u8 pwrst)
{
omap4_prminst_rmw_inst_reg_bits(OMAP_POWERSTATE_MASK,
(pwrst << OMAP_POWERSTATE_SHIFT),
pwrdm->prcm_partition,
pwrdm->prcm_offs, OMAP4_PM_PWSTCTRL);
return 0;
}
static int omap4_pwrdm_read_next_pwrst(struct powerdomain *pwrdm)
{
u32 v;
v = omap4_prminst_read_inst_reg(pwrdm->prcm_partition, pwrdm->prcm_offs,
OMAP4_PM_PWSTCTRL);
v &= OMAP_POWERSTATE_MASK;
v >>= OMAP_POWERSTATE_SHIFT;
return v;
}
static int omap4_pwrdm_read_pwrst(struct powerdomain *pwrdm)
{
u32 v;
v = omap4_prminst_read_inst_reg(pwrdm->prcm_partition, pwrdm->prcm_offs,
OMAP4_PM_PWSTST);
v &= OMAP_POWERSTATEST_MASK;
v >>= OMAP_POWERSTATEST_SHIFT;
return v;
}
static int omap4_pwrdm_read_prev_pwrst(struct powerdomain *pwrdm)
{
u32 v;
v = omap4_prminst_read_inst_reg(pwrdm->prcm_partition, pwrdm->prcm_offs,
OMAP4_PM_PWSTST);
v &= OMAP4430_LASTPOWERSTATEENTERED_MASK;
v >>= OMAP4430_LASTPOWERSTATEENTERED_SHIFT;
return v;
}
static int omap4_pwrdm_set_lowpwrstchange(struct powerdomain *pwrdm)
{
omap4_prminst_rmw_inst_reg_bits(OMAP4430_LOWPOWERSTATECHANGE_MASK,
(1 << OMAP4430_LOWPOWERSTATECHANGE_SHIFT),
pwrdm->prcm_partition,
pwrdm->prcm_offs, OMAP4_PM_PWSTCTRL);
return 0;
}
static int omap4_pwrdm_clear_all_prev_pwrst(struct powerdomain *pwrdm)
{
omap4_prminst_rmw_inst_reg_bits(OMAP4430_LASTPOWERSTATEENTERED_MASK,
OMAP4430_LASTPOWERSTATEENTERED_MASK,
pwrdm->prcm_partition,
pwrdm->prcm_offs, OMAP4_PM_PWSTST);
return 0;
}
static int omap4_pwrdm_set_logic_retst(struct powerdomain *pwrdm, u8 pwrst)
{
u32 v;
v = pwrst << __ffs(OMAP4430_LOGICRETSTATE_MASK);
omap4_prminst_rmw_inst_reg_bits(OMAP4430_LOGICRETSTATE_MASK, v,
pwrdm->prcm_partition, pwrdm->prcm_offs,
OMAP4_PM_PWSTCTRL);
return 0;
}
static int omap4_pwrdm_set_mem_onst(struct powerdomain *pwrdm, u8 bank,
u8 pwrst)
{
u32 m;
m = omap2_pwrdm_get_mem_bank_onstate_mask(bank);
omap4_prminst_rmw_inst_reg_bits(m, (pwrst << __ffs(m)),
pwrdm->prcm_partition, pwrdm->prcm_offs,
OMAP4_PM_PWSTCTRL);
return 0;
}
static int omap4_pwrdm_set_mem_retst(struct powerdomain *pwrdm, u8 bank,
u8 pwrst)
{
u32 m;
m = omap2_pwrdm_get_mem_bank_retst_mask(bank);
omap4_prminst_rmw_inst_reg_bits(m, (pwrst << __ffs(m)),
pwrdm->prcm_partition, pwrdm->prcm_offs,
OMAP4_PM_PWSTCTRL);
return 0;
}
static int omap4_pwrdm_read_logic_pwrst(struct powerdomain *pwrdm)
{
u32 v;
v = omap4_prminst_read_inst_reg(pwrdm->prcm_partition, pwrdm->prcm_offs,
OMAP4_PM_PWSTST);
v &= OMAP4430_LOGICSTATEST_MASK;
v >>= OMAP4430_LOGICSTATEST_SHIFT;
return v;
}
static int omap4_pwrdm_read_logic_retst(struct powerdomain *pwrdm)
{
u32 v;
v = omap4_prminst_read_inst_reg(pwrdm->prcm_partition, pwrdm->prcm_offs,
OMAP4_PM_PWSTCTRL);
v &= OMAP4430_LOGICRETSTATE_MASK;
v >>= OMAP4430_LOGICRETSTATE_SHIFT;
return v;
}
static int omap4_pwrdm_read_prev_logic_pwrst(struct powerdomain *pwrdm)
{
int state;
state = omap4_pwrdm_read_prev_pwrst(pwrdm);
if (state == PWRDM_POWER_OFF)
return PWRDM_POWER_OFF;
if (state != PWRDM_POWER_RET)
return PWRDM_POWER_RET;
return omap4_pwrdm_read_logic_retst(pwrdm);
}
static int omap4_pwrdm_read_mem_pwrst(struct powerdomain *pwrdm, u8 bank)
{
u32 m, v;
m = omap2_pwrdm_get_mem_bank_stst_mask(bank);
v = omap4_prminst_read_inst_reg(pwrdm->prcm_partition, pwrdm->prcm_offs,
OMAP4_PM_PWSTST);
v &= m;
v >>= __ffs(m);
return v;
}
static int omap4_pwrdm_read_mem_retst(struct powerdomain *pwrdm, u8 bank)
{
u32 m, v;
m = omap2_pwrdm_get_mem_bank_retst_mask(bank);
v = omap4_prminst_read_inst_reg(pwrdm->prcm_partition, pwrdm->prcm_offs,
OMAP4_PM_PWSTCTRL);
v &= m;
v >>= __ffs(m);
return v;
}
static int omap4_pwrdm_read_prev_mem_pwrst(struct powerdomain *pwrdm, u8 bank)
{
int state;
state = omap4_pwrdm_read_prev_pwrst(pwrdm);
if (state == PWRDM_POWER_OFF)
return PWRDM_POWER_OFF;
if (state != PWRDM_POWER_RET)
return PWRDM_POWER_RET;
return omap4_pwrdm_read_mem_retst(pwrdm, bank);
}
static int omap4_pwrdm_wait_transition(struct powerdomain *pwrdm)
{
u32 c = 0;
while ((omap4_prminst_read_inst_reg(pwrdm->prcm_partition,
pwrdm->prcm_offs,
OMAP4_PM_PWSTST) &
OMAP_INTRANSITION_MASK) &&
(c++ < PWRDM_TRANSITION_BAILOUT))
udelay(1);
if (c > PWRDM_TRANSITION_BAILOUT) {
pr_err("powerdomain: %s: waited too long to complete transition\n",
pwrdm->name);
return -EAGAIN;
}
pr_debug("powerdomain: completed transition in %d loops\n", c);
return 0;
}
int __init omap44xx_prm_init(void)
{
if (!cpu_is_omap44xx() && !soc_is_omap54xx())
return 0;
return prm_register(&omap44xx_prm_ll_data);
}
static int __init omap44xx_prm_late_init(void)
{
if (!cpu_is_omap44xx())
return 0;
omap44xx_prm_enable_io_wakeup();
return omap_prcm_register_chain_handler(&omap4_prcm_irq_setup);
}
static void __exit omap44xx_prm_exit(void)
{
if (!cpu_is_omap44xx())
return;
WARN(prm_unregister(&omap44xx_prm_ll_data),
"%s: prm_ll_data function pointer mismatch\n", __func__);
}
