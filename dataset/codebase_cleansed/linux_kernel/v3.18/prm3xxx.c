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
int omap3xxx_prm_clear_mod_irqs(s16 module, u8 regs, u32 ignore_bits)
{
u32 wkst, fclk, iclk, clken;
u16 wkst_off = (regs == 3) ? OMAP3430ES2_PM_WKST3 : PM_WKST1;
u16 fclk_off = (regs == 3) ? OMAP3430ES2_CM_FCLKEN3 : CM_FCLKEN1;
u16 iclk_off = (regs == 3) ? CM_ICLKEN3 : CM_ICLKEN1;
u16 grpsel_off = (regs == 3) ?
OMAP3430ES2_PM_MPUGRPSEL3 : OMAP3430_PM_MPUGRPSEL;
int c = 0;
wkst = omap2_prm_read_mod_reg(module, wkst_off);
wkst &= omap2_prm_read_mod_reg(module, grpsel_off);
wkst &= ~ignore_bits;
if (wkst) {
iclk = omap2_cm_read_mod_reg(module, iclk_off);
fclk = omap2_cm_read_mod_reg(module, fclk_off);
while (wkst) {
clken = wkst;
omap2_cm_set_mod_reg_bits(clken, module, iclk_off);
if (module == OMAP3430ES2_USBHOST_MOD)
clken |= 1 << OMAP3430ES2_EN_USBHOST2_SHIFT;
omap2_cm_set_mod_reg_bits(clken, module, fclk_off);
omap2_prm_write_mod_reg(wkst, module, wkst_off);
wkst = omap2_prm_read_mod_reg(module, wkst_off);
wkst &= ~ignore_bits;
c++;
}
omap2_cm_write_mod_reg(iclk, module, iclk_off);
omap2_cm_write_mod_reg(fclk, module, fclk_off);
}
return c;
}
void __init omap3_prm_reset_modem(void)
{
omap2_prm_write_mod_reg(
OMAP3430_RM_RSTCTRL_CORE_MODEM_SW_RSTPWRON_MASK |
OMAP3430_RM_RSTCTRL_CORE_MODEM_SW_RST_MASK,
CORE_MOD, OMAP2_RM_RSTCTRL);
omap2_prm_write_mod_reg(0, CORE_MOD, OMAP2_RM_RSTCTRL);
}
void __init omap3_prm_init_pm(bool has_uart4, bool has_iva)
{
u32 en_uart4_mask;
u32 grpsel_uart4_mask;
omap2_prm_rmw_mod_reg_bits(OMAP_AUTOEXTCLKMODE_MASK,
1 << OMAP_AUTOEXTCLKMODE_SHIFT,
OMAP3430_GR_MOD,
OMAP3_PRM_CLKSRC_CTRL_OFFSET);
omap2_prm_write_mod_reg(OMAP3430_EN_IO_MASK | OMAP3430_EN_GPIO1_MASK |
OMAP3430_EN_GPT1_MASK | OMAP3430_EN_GPT12_MASK,
WKUP_MOD, PM_WKEN);
omap2_prm_write_mod_reg(OMAP3430_GRPSEL_GPIO1_MASK |
OMAP3430_GRPSEL_GPT1_MASK |
OMAP3430_GRPSEL_GPT12_MASK,
WKUP_MOD, OMAP3430_PM_MPUGRPSEL);
omap2_prm_write_mod_reg(OMAP3430_PM_WKEN_DSS_EN_DSS_MASK,
OMAP3430_DSS_MOD, PM_WKEN);
if (has_uart4) {
en_uart4_mask = OMAP3630_EN_UART4_MASK;
grpsel_uart4_mask = OMAP3630_GRPSEL_UART4_MASK;
}
omap2_prm_write_mod_reg(en_uart4_mask |
OMAP3430_EN_GPIO2_MASK |
OMAP3430_EN_GPIO3_MASK |
OMAP3430_EN_GPIO4_MASK |
OMAP3430_EN_GPIO5_MASK |
OMAP3430_EN_GPIO6_MASK |
OMAP3430_EN_UART3_MASK |
OMAP3430_EN_MCBSP2_MASK |
OMAP3430_EN_MCBSP3_MASK |
OMAP3430_EN_MCBSP4_MASK,
OMAP3430_PER_MOD, PM_WKEN);
omap2_prm_write_mod_reg(grpsel_uart4_mask |
OMAP3430_GRPSEL_GPIO2_MASK |
OMAP3430_GRPSEL_GPIO3_MASK |
OMAP3430_GRPSEL_GPIO4_MASK |
OMAP3430_GRPSEL_GPIO5_MASK |
OMAP3430_GRPSEL_GPIO6_MASK |
OMAP3430_GRPSEL_UART3_MASK |
OMAP3430_GRPSEL_MCBSP2_MASK |
OMAP3430_GRPSEL_MCBSP3_MASK |
OMAP3430_GRPSEL_MCBSP4_MASK,
OMAP3430_PER_MOD, OMAP3430_PM_MPUGRPSEL);
if (has_iva) {
omap2_prm_write_mod_reg(0, WKUP_MOD, OMAP3430_PM_IVAGRPSEL);
omap2_prm_write_mod_reg(0, CORE_MOD, OMAP3430_PM_IVAGRPSEL1);
omap2_prm_write_mod_reg(0, CORE_MOD, OMAP3430ES2_PM_IVAGRPSEL3);
omap2_prm_write_mod_reg(0, OMAP3430_PER_MOD,
OMAP3430_PM_IVAGRPSEL);
}
omap2_prm_write_mod_reg(0xffffffff, MPU_MOD, OMAP2_RM_RSTST);
omap2_prm_write_mod_reg(0xffffffff, CORE_MOD, OMAP2_RM_RSTST);
omap2_prm_write_mod_reg(0xffffffff, OMAP3430_PER_MOD, OMAP2_RM_RSTST);
omap2_prm_write_mod_reg(0xffffffff, OMAP3430_EMU_MOD, OMAP2_RM_RSTST);
omap2_prm_write_mod_reg(0xffffffff, OMAP3430_NEON_MOD, OMAP2_RM_RSTST);
omap2_prm_write_mod_reg(0xffffffff, OMAP3430_DSS_MOD, OMAP2_RM_RSTST);
omap2_prm_write_mod_reg(0xffffffff, OMAP3430ES2_USBHOST_MOD,
OMAP2_RM_RSTST);
omap2_prm_write_mod_reg(0, OCP_MOD, OMAP3_PRM_IRQSTATUS_MPU_OFFSET);
omap3xxx_prm_iva_idle();
omap3_prm_reset_modem();
}
void omap3430_pre_es3_1_reconfigure_io_chain(void)
{
omap2_prm_clear_mod_reg_bits(OMAP3430_EN_IO_MASK, WKUP_MOD,
PM_WKEN);
omap2_prm_set_mod_reg_bits(OMAP3430_EN_IO_MASK, WKUP_MOD,
PM_WKEN);
omap2_prm_read_mod_reg(WKUP_MOD, PM_WKEN);
}
void omap3_prm_reconfigure_io_chain(void)
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
void omap3xxx_prm_reconfigure_io_chain(void)
{
if (omap3_prcm_irq_setup.reconfigure_io_chain)
omap3_prcm_irq_setup.reconfigure_io_chain();
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
void omap3xxx_prm_iva_idle(void)
{
omap2_cm_write_mod_reg(0, OMAP3430_IVA2_MOD, CM_FCLKEN);
if (!(omap2_cm_read_mod_reg(OMAP3430_IVA2_MOD, OMAP3430_CM_CLKSTST) &
OMAP3430_CLKACTIVITY_IVA2_MASK))
return;
omap2_prm_write_mod_reg(OMAP3430_RST1_IVA2_MASK |
OMAP3430_RST2_IVA2_MASK |
OMAP3430_RST3_IVA2_MASK,
OMAP3430_IVA2_MOD, OMAP2_RM_RSTCTRL);
omap2_cm_write_mod_reg(OMAP3430_CM_FCLKEN_IVA2_EN_IVA2_MASK,
OMAP3430_IVA2_MOD, CM_FCLKEN);
omap2_prm_write_mod_reg(0, OMAP3430_IVA2_MOD, OMAP2_RM_RSTCTRL);
omap2_cm_write_mod_reg(0, OMAP3430_IVA2_MOD, CM_FCLKEN);
omap2_prm_write_mod_reg(OMAP3430_RST1_IVA2_MASK |
OMAP3430_RST2_IVA2_MASK |
OMAP3430_RST3_IVA2_MASK,
OMAP3430_IVA2_MOD, OMAP2_RM_RSTCTRL);
}
int omap3xxx_prm_clear_global_cold_reset(void)
{
if (omap2_prm_read_mod_reg(OMAP3430_GR_MOD, OMAP3_PRM_RSTST_OFFSET) &
OMAP3430_GLOBAL_COLD_RST_MASK) {
omap2_prm_set_mod_reg_bits(OMAP3430_GLOBAL_COLD_RST_MASK,
OMAP3430_GR_MOD,
OMAP3_PRM_RSTST_OFFSET);
return 1;
}
return 0;
}
void omap3_prm_save_scratchpad_contents(u32 *ptr)
{
*ptr++ = omap2_prm_read_mod_reg(OMAP3430_GR_MOD,
OMAP3_PRM_CLKSRC_CTRL_OFFSET);
*ptr++ = omap2_prm_read_mod_reg(OMAP3430_GR_MOD,
OMAP3_PRM_CLKSEL_OFFSET);
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
if (omap3_has_io_chain_ctrl())
omap3_prcm_irq_setup.reconfigure_io_chain =
omap3_prm_reconfigure_io_chain;
else
omap3_prcm_irq_setup.reconfigure_io_chain =
omap3430_pre_es3_1_reconfigure_io_chain;
if (of_have_populated_dt()) {
struct device_node *np;
int irq_num;
np = of_find_matching_node(NULL, omap3_prm_dt_match_table);
if (np) {
irq_num = of_irq_get(np, 0);
if (irq_num >= 0)
omap3_prcm_irq_setup.irq = irq_num;
}
}
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
