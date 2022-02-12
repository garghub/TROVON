static void _write_clktrctrl(u8 c, s16 module, u32 mask)
{
u32 v;
v = omap2_cm_read_mod_reg(module, OMAP2_CM_CLKSTCTRL);
v &= ~mask;
v |= c << __ffs(mask);
omap2_cm_write_mod_reg(v, module, OMAP2_CM_CLKSTCTRL);
}
bool omap3xxx_cm_is_clkdm_in_hwsup(s16 module, u32 mask)
{
u32 v;
v = omap2_cm_read_mod_reg(module, OMAP2_CM_CLKSTCTRL);
v &= mask;
v >>= __ffs(mask);
return (v == OMAP34XX_CLKSTCTRL_ENABLE_AUTO) ? 1 : 0;
}
void omap3xxx_cm_clkdm_enable_hwsup(s16 module, u32 mask)
{
_write_clktrctrl(OMAP34XX_CLKSTCTRL_ENABLE_AUTO, module, mask);
}
void omap3xxx_cm_clkdm_disable_hwsup(s16 module, u32 mask)
{
_write_clktrctrl(OMAP34XX_CLKSTCTRL_DISABLE_AUTO, module, mask);
}
void omap3xxx_cm_clkdm_force_sleep(s16 module, u32 mask)
{
_write_clktrctrl(OMAP34XX_CLKSTCTRL_FORCE_SLEEP, module, mask);
}
void omap3xxx_cm_clkdm_force_wakeup(s16 module, u32 mask)
{
_write_clktrctrl(OMAP34XX_CLKSTCTRL_FORCE_WAKEUP, module, mask);
}
int omap3xxx_cm_wait_module_ready(s16 prcm_mod, u8 idlest_id, u8 idlest_shift)
{
int ena = 0, i = 0;
u8 cm_idlest_reg;
u32 mask;
if (!idlest_id || (idlest_id > ARRAY_SIZE(omap3xxx_cm_idlest_offs)))
return -EINVAL;
cm_idlest_reg = omap3xxx_cm_idlest_offs[idlest_id - 1];
mask = 1 << idlest_shift;
ena = 0;
omap_test_timeout(((omap2_cm_read_mod_reg(prcm_mod, cm_idlest_reg) &
mask) == ena), MAX_MODULE_READY_TIME, i);
return (i < MAX_MODULE_READY_TIME) ? 0 : -EBUSY;
}
int omap3xxx_cm_split_idlest_reg(void __iomem *idlest_reg, s16 *prcm_inst,
u8 *idlest_reg_id)
{
unsigned long offs;
u8 idlest_offs;
int i;
if (idlest_reg < (cm_base + OMAP3430_IVA2_MOD) ||
idlest_reg > (cm_base + 0x1ffff))
return -EINVAL;
idlest_offs = (unsigned long)idlest_reg & 0xff;
for (i = 0; i < ARRAY_SIZE(omap3xxx_cm_idlest_offs); i++) {
if (idlest_offs == omap3xxx_cm_idlest_offs[i]) {
*idlest_reg_id = i + 1;
break;
}
}
if (i == ARRAY_SIZE(omap3xxx_cm_idlest_offs))
return -EINVAL;
offs = idlest_reg - cm_base;
offs &= 0xff00;
*prcm_inst = offs;
return 0;
}
static int omap3xxx_clkdm_add_sleepdep(struct clockdomain *clkdm1,
struct clockdomain *clkdm2)
{
omap2_cm_set_mod_reg_bits((1 << clkdm2->dep_bit),
clkdm1->pwrdm.ptr->prcm_offs,
OMAP3430_CM_SLEEPDEP);
return 0;
}
static int omap3xxx_clkdm_del_sleepdep(struct clockdomain *clkdm1,
struct clockdomain *clkdm2)
{
omap2_cm_clear_mod_reg_bits((1 << clkdm2->dep_bit),
clkdm1->pwrdm.ptr->prcm_offs,
OMAP3430_CM_SLEEPDEP);
return 0;
}
static int omap3xxx_clkdm_read_sleepdep(struct clockdomain *clkdm1,
struct clockdomain *clkdm2)
{
return omap2_cm_read_mod_bits_shift(clkdm1->pwrdm.ptr->prcm_offs,
OMAP3430_CM_SLEEPDEP,
(1 << clkdm2->dep_bit));
}
static int omap3xxx_clkdm_clear_all_sleepdeps(struct clockdomain *clkdm)
{
struct clkdm_dep *cd;
u32 mask = 0;
for (cd = clkdm->sleepdep_srcs; cd && cd->clkdm_name; cd++) {
if (!cd->clkdm)
continue;
mask |= 1 << cd->clkdm->dep_bit;
cd->sleepdep_usecount = 0;
}
omap2_cm_clear_mod_reg_bits(mask, clkdm->pwrdm.ptr->prcm_offs,
OMAP3430_CM_SLEEPDEP);
return 0;
}
static int omap3xxx_clkdm_sleep(struct clockdomain *clkdm)
{
omap3xxx_cm_clkdm_force_sleep(clkdm->pwrdm.ptr->prcm_offs,
clkdm->clktrctrl_mask);
return 0;
}
static int omap3xxx_clkdm_wakeup(struct clockdomain *clkdm)
{
omap3xxx_cm_clkdm_force_wakeup(clkdm->pwrdm.ptr->prcm_offs,
clkdm->clktrctrl_mask);
return 0;
}
static void omap3xxx_clkdm_allow_idle(struct clockdomain *clkdm)
{
if (clkdm->usecount > 0)
clkdm_add_autodeps(clkdm);
omap3xxx_cm_clkdm_enable_hwsup(clkdm->pwrdm.ptr->prcm_offs,
clkdm->clktrctrl_mask);
}
static void omap3xxx_clkdm_deny_idle(struct clockdomain *clkdm)
{
omap3xxx_cm_clkdm_disable_hwsup(clkdm->pwrdm.ptr->prcm_offs,
clkdm->clktrctrl_mask);
if (clkdm->usecount > 0)
clkdm_del_autodeps(clkdm);
}
static int omap3xxx_clkdm_clk_enable(struct clockdomain *clkdm)
{
bool hwsup = false;
if (!clkdm->clktrctrl_mask)
return 0;
if ((clkdm->flags & CLKDM_MISSING_IDLE_REPORTING) &&
(clkdm->flags & CLKDM_CAN_FORCE_WAKEUP)) {
omap3xxx_clkdm_wakeup(clkdm);
return 0;
}
hwsup = omap3xxx_cm_is_clkdm_in_hwsup(clkdm->pwrdm.ptr->prcm_offs,
clkdm->clktrctrl_mask);
if (hwsup) {
omap3xxx_cm_clkdm_disable_hwsup(clkdm->pwrdm.ptr->prcm_offs,
clkdm->clktrctrl_mask);
clkdm_add_autodeps(clkdm);
omap3xxx_cm_clkdm_enable_hwsup(clkdm->pwrdm.ptr->prcm_offs,
clkdm->clktrctrl_mask);
} else {
if (clkdm->flags & CLKDM_CAN_FORCE_WAKEUP)
omap3xxx_clkdm_wakeup(clkdm);
}
return 0;
}
static int omap3xxx_clkdm_clk_disable(struct clockdomain *clkdm)
{
bool hwsup = false;
if (!clkdm->clktrctrl_mask)
return 0;
if (clkdm->flags & CLKDM_MISSING_IDLE_REPORTING &&
!(clkdm->flags & CLKDM_CAN_FORCE_SLEEP)) {
omap3xxx_cm_clkdm_enable_hwsup(clkdm->pwrdm.ptr->prcm_offs,
clkdm->clktrctrl_mask);
return 0;
}
hwsup = omap3xxx_cm_is_clkdm_in_hwsup(clkdm->pwrdm.ptr->prcm_offs,
clkdm->clktrctrl_mask);
if (hwsup) {
omap3xxx_cm_clkdm_disable_hwsup(clkdm->pwrdm.ptr->prcm_offs,
clkdm->clktrctrl_mask);
clkdm_del_autodeps(clkdm);
omap3xxx_cm_clkdm_enable_hwsup(clkdm->pwrdm.ptr->prcm_offs,
clkdm->clktrctrl_mask);
} else {
if (clkdm->flags & CLKDM_CAN_FORCE_SLEEP)
omap3xxx_clkdm_sleep(clkdm);
}
return 0;
}
void omap3_cm_save_context(void)
{
cm_context.iva2_cm_clksel1 =
omap2_cm_read_mod_reg(OMAP3430_IVA2_MOD, CM_CLKSEL1);
cm_context.iva2_cm_clksel2 =
omap2_cm_read_mod_reg(OMAP3430_IVA2_MOD, CM_CLKSEL2);
cm_context.cm_sysconfig = __raw_readl(OMAP3430_CM_SYSCONFIG);
cm_context.sgx_cm_clksel =
omap2_cm_read_mod_reg(OMAP3430ES2_SGX_MOD, CM_CLKSEL);
cm_context.dss_cm_clksel =
omap2_cm_read_mod_reg(OMAP3430_DSS_MOD, CM_CLKSEL);
cm_context.cam_cm_clksel =
omap2_cm_read_mod_reg(OMAP3430_CAM_MOD, CM_CLKSEL);
cm_context.per_cm_clksel =
omap2_cm_read_mod_reg(OMAP3430_PER_MOD, CM_CLKSEL);
cm_context.emu_cm_clksel =
omap2_cm_read_mod_reg(OMAP3430_EMU_MOD, CM_CLKSEL1);
cm_context.emu_cm_clkstctrl =
omap2_cm_read_mod_reg(OMAP3430_EMU_MOD, OMAP2_CM_CLKSTCTRL);
cm_context.pll_cm_autoidle =
omap2_cm_read_mod_reg(PLL_MOD, CM_AUTOIDLE);
cm_context.pll_cm_autoidle2 =
omap2_cm_read_mod_reg(PLL_MOD, CM_AUTOIDLE2);
cm_context.pll_cm_clksel4 =
omap2_cm_read_mod_reg(PLL_MOD, OMAP3430ES2_CM_CLKSEL4);
cm_context.pll_cm_clksel5 =
omap2_cm_read_mod_reg(PLL_MOD, OMAP3430ES2_CM_CLKSEL5);
cm_context.pll_cm_clken2 =
omap2_cm_read_mod_reg(PLL_MOD, OMAP3430ES2_CM_CLKEN2);
cm_context.cm_polctrl = __raw_readl(OMAP3430_CM_POLCTRL);
cm_context.iva2_cm_fclken =
omap2_cm_read_mod_reg(OMAP3430_IVA2_MOD, CM_FCLKEN);
cm_context.iva2_cm_clken_pll =
omap2_cm_read_mod_reg(OMAP3430_IVA2_MOD, OMAP3430_CM_CLKEN_PLL);
cm_context.core_cm_fclken1 =
omap2_cm_read_mod_reg(CORE_MOD, CM_FCLKEN1);
cm_context.core_cm_fclken3 =
omap2_cm_read_mod_reg(CORE_MOD, OMAP3430ES2_CM_FCLKEN3);
cm_context.sgx_cm_fclken =
omap2_cm_read_mod_reg(OMAP3430ES2_SGX_MOD, CM_FCLKEN);
cm_context.wkup_cm_fclken =
omap2_cm_read_mod_reg(WKUP_MOD, CM_FCLKEN);
cm_context.dss_cm_fclken =
omap2_cm_read_mod_reg(OMAP3430_DSS_MOD, CM_FCLKEN);
cm_context.cam_cm_fclken =
omap2_cm_read_mod_reg(OMAP3430_CAM_MOD, CM_FCLKEN);
cm_context.per_cm_fclken =
omap2_cm_read_mod_reg(OMAP3430_PER_MOD, CM_FCLKEN);
cm_context.usbhost_cm_fclken =
omap2_cm_read_mod_reg(OMAP3430ES2_USBHOST_MOD, CM_FCLKEN);
cm_context.core_cm_iclken1 =
omap2_cm_read_mod_reg(CORE_MOD, CM_ICLKEN1);
cm_context.core_cm_iclken2 =
omap2_cm_read_mod_reg(CORE_MOD, CM_ICLKEN2);
cm_context.core_cm_iclken3 =
omap2_cm_read_mod_reg(CORE_MOD, CM_ICLKEN3);
cm_context.sgx_cm_iclken =
omap2_cm_read_mod_reg(OMAP3430ES2_SGX_MOD, CM_ICLKEN);
cm_context.wkup_cm_iclken =
omap2_cm_read_mod_reg(WKUP_MOD, CM_ICLKEN);
cm_context.dss_cm_iclken =
omap2_cm_read_mod_reg(OMAP3430_DSS_MOD, CM_ICLKEN);
cm_context.cam_cm_iclken =
omap2_cm_read_mod_reg(OMAP3430_CAM_MOD, CM_ICLKEN);
cm_context.per_cm_iclken =
omap2_cm_read_mod_reg(OMAP3430_PER_MOD, CM_ICLKEN);
cm_context.usbhost_cm_iclken =
omap2_cm_read_mod_reg(OMAP3430ES2_USBHOST_MOD, CM_ICLKEN);
cm_context.iva2_cm_autoidle2 =
omap2_cm_read_mod_reg(OMAP3430_IVA2_MOD, CM_AUTOIDLE2);
cm_context.mpu_cm_autoidle2 =
omap2_cm_read_mod_reg(MPU_MOD, CM_AUTOIDLE2);
cm_context.iva2_cm_clkstctrl =
omap2_cm_read_mod_reg(OMAP3430_IVA2_MOD, OMAP2_CM_CLKSTCTRL);
cm_context.mpu_cm_clkstctrl =
omap2_cm_read_mod_reg(MPU_MOD, OMAP2_CM_CLKSTCTRL);
cm_context.core_cm_clkstctrl =
omap2_cm_read_mod_reg(CORE_MOD, OMAP2_CM_CLKSTCTRL);
cm_context.sgx_cm_clkstctrl =
omap2_cm_read_mod_reg(OMAP3430ES2_SGX_MOD, OMAP2_CM_CLKSTCTRL);
cm_context.dss_cm_clkstctrl =
omap2_cm_read_mod_reg(OMAP3430_DSS_MOD, OMAP2_CM_CLKSTCTRL);
cm_context.cam_cm_clkstctrl =
omap2_cm_read_mod_reg(OMAP3430_CAM_MOD, OMAP2_CM_CLKSTCTRL);
cm_context.per_cm_clkstctrl =
omap2_cm_read_mod_reg(OMAP3430_PER_MOD, OMAP2_CM_CLKSTCTRL);
cm_context.neon_cm_clkstctrl =
omap2_cm_read_mod_reg(OMAP3430_NEON_MOD, OMAP2_CM_CLKSTCTRL);
cm_context.usbhost_cm_clkstctrl =
omap2_cm_read_mod_reg(OMAP3430ES2_USBHOST_MOD,
OMAP2_CM_CLKSTCTRL);
cm_context.core_cm_autoidle1 =
omap2_cm_read_mod_reg(CORE_MOD, CM_AUTOIDLE1);
cm_context.core_cm_autoidle2 =
omap2_cm_read_mod_reg(CORE_MOD, CM_AUTOIDLE2);
cm_context.core_cm_autoidle3 =
omap2_cm_read_mod_reg(CORE_MOD, CM_AUTOIDLE3);
cm_context.wkup_cm_autoidle =
omap2_cm_read_mod_reg(WKUP_MOD, CM_AUTOIDLE);
cm_context.dss_cm_autoidle =
omap2_cm_read_mod_reg(OMAP3430_DSS_MOD, CM_AUTOIDLE);
cm_context.cam_cm_autoidle =
omap2_cm_read_mod_reg(OMAP3430_CAM_MOD, CM_AUTOIDLE);
cm_context.per_cm_autoidle =
omap2_cm_read_mod_reg(OMAP3430_PER_MOD, CM_AUTOIDLE);
cm_context.usbhost_cm_autoidle =
omap2_cm_read_mod_reg(OMAP3430ES2_USBHOST_MOD, CM_AUTOIDLE);
cm_context.sgx_cm_sleepdep =
omap2_cm_read_mod_reg(OMAP3430ES2_SGX_MOD,
OMAP3430_CM_SLEEPDEP);
cm_context.dss_cm_sleepdep =
omap2_cm_read_mod_reg(OMAP3430_DSS_MOD, OMAP3430_CM_SLEEPDEP);
cm_context.cam_cm_sleepdep =
omap2_cm_read_mod_reg(OMAP3430_CAM_MOD, OMAP3430_CM_SLEEPDEP);
cm_context.per_cm_sleepdep =
omap2_cm_read_mod_reg(OMAP3430_PER_MOD, OMAP3430_CM_SLEEPDEP);
cm_context.usbhost_cm_sleepdep =
omap2_cm_read_mod_reg(OMAP3430ES2_USBHOST_MOD,
OMAP3430_CM_SLEEPDEP);
cm_context.cm_clkout_ctrl =
omap2_cm_read_mod_reg(OMAP3430_CCR_MOD,
OMAP3_CM_CLKOUT_CTRL_OFFSET);
}
void omap3_cm_restore_context(void)
{
omap2_cm_write_mod_reg(cm_context.iva2_cm_clksel1, OMAP3430_IVA2_MOD,
CM_CLKSEL1);
omap2_cm_write_mod_reg(cm_context.iva2_cm_clksel2, OMAP3430_IVA2_MOD,
CM_CLKSEL2);
__raw_writel(cm_context.cm_sysconfig, OMAP3430_CM_SYSCONFIG);
omap2_cm_write_mod_reg(cm_context.sgx_cm_clksel, OMAP3430ES2_SGX_MOD,
CM_CLKSEL);
omap2_cm_write_mod_reg(cm_context.dss_cm_clksel, OMAP3430_DSS_MOD,
CM_CLKSEL);
omap2_cm_write_mod_reg(cm_context.cam_cm_clksel, OMAP3430_CAM_MOD,
CM_CLKSEL);
omap2_cm_write_mod_reg(cm_context.per_cm_clksel, OMAP3430_PER_MOD,
CM_CLKSEL);
omap2_cm_write_mod_reg(cm_context.emu_cm_clksel, OMAP3430_EMU_MOD,
CM_CLKSEL1);
omap2_cm_write_mod_reg(cm_context.emu_cm_clkstctrl, OMAP3430_EMU_MOD,
OMAP2_CM_CLKSTCTRL);
omap2_cm_write_mod_reg(cm_context.pll_cm_autoidle, PLL_MOD,
CM_AUTOIDLE);
omap2_cm_write_mod_reg(cm_context.pll_cm_autoidle2, PLL_MOD,
CM_AUTOIDLE2);
omap2_cm_write_mod_reg(cm_context.pll_cm_clksel4, PLL_MOD,
OMAP3430ES2_CM_CLKSEL4);
omap2_cm_write_mod_reg(cm_context.pll_cm_clksel5, PLL_MOD,
OMAP3430ES2_CM_CLKSEL5);
omap2_cm_write_mod_reg(cm_context.pll_cm_clken2, PLL_MOD,
OMAP3430ES2_CM_CLKEN2);
__raw_writel(cm_context.cm_polctrl, OMAP3430_CM_POLCTRL);
omap2_cm_write_mod_reg(cm_context.iva2_cm_fclken, OMAP3430_IVA2_MOD,
CM_FCLKEN);
omap2_cm_write_mod_reg(cm_context.iva2_cm_clken_pll, OMAP3430_IVA2_MOD,
OMAP3430_CM_CLKEN_PLL);
omap2_cm_write_mod_reg(cm_context.core_cm_fclken1, CORE_MOD,
CM_FCLKEN1);
omap2_cm_write_mod_reg(cm_context.core_cm_fclken3, CORE_MOD,
OMAP3430ES2_CM_FCLKEN3);
omap2_cm_write_mod_reg(cm_context.sgx_cm_fclken, OMAP3430ES2_SGX_MOD,
CM_FCLKEN);
omap2_cm_write_mod_reg(cm_context.wkup_cm_fclken, WKUP_MOD, CM_FCLKEN);
omap2_cm_write_mod_reg(cm_context.dss_cm_fclken, OMAP3430_DSS_MOD,
CM_FCLKEN);
omap2_cm_write_mod_reg(cm_context.cam_cm_fclken, OMAP3430_CAM_MOD,
CM_FCLKEN);
omap2_cm_write_mod_reg(cm_context.per_cm_fclken, OMAP3430_PER_MOD,
CM_FCLKEN);
omap2_cm_write_mod_reg(cm_context.usbhost_cm_fclken,
OMAP3430ES2_USBHOST_MOD, CM_FCLKEN);
omap2_cm_write_mod_reg(cm_context.core_cm_iclken1, CORE_MOD,
CM_ICLKEN1);
omap2_cm_write_mod_reg(cm_context.core_cm_iclken2, CORE_MOD,
CM_ICLKEN2);
omap2_cm_write_mod_reg(cm_context.core_cm_iclken3, CORE_MOD,
CM_ICLKEN3);
omap2_cm_write_mod_reg(cm_context.sgx_cm_iclken, OMAP3430ES2_SGX_MOD,
CM_ICLKEN);
omap2_cm_write_mod_reg(cm_context.wkup_cm_iclken, WKUP_MOD, CM_ICLKEN);
omap2_cm_write_mod_reg(cm_context.dss_cm_iclken, OMAP3430_DSS_MOD,
CM_ICLKEN);
omap2_cm_write_mod_reg(cm_context.cam_cm_iclken, OMAP3430_CAM_MOD,
CM_ICLKEN);
omap2_cm_write_mod_reg(cm_context.per_cm_iclken, OMAP3430_PER_MOD,
CM_ICLKEN);
omap2_cm_write_mod_reg(cm_context.usbhost_cm_iclken,
OMAP3430ES2_USBHOST_MOD, CM_ICLKEN);
omap2_cm_write_mod_reg(cm_context.iva2_cm_autoidle2, OMAP3430_IVA2_MOD,
CM_AUTOIDLE2);
omap2_cm_write_mod_reg(cm_context.mpu_cm_autoidle2, MPU_MOD,
CM_AUTOIDLE2);
omap2_cm_write_mod_reg(cm_context.iva2_cm_clkstctrl, OMAP3430_IVA2_MOD,
OMAP2_CM_CLKSTCTRL);
omap2_cm_write_mod_reg(cm_context.mpu_cm_clkstctrl, MPU_MOD,
OMAP2_CM_CLKSTCTRL);
omap2_cm_write_mod_reg(cm_context.core_cm_clkstctrl, CORE_MOD,
OMAP2_CM_CLKSTCTRL);
omap2_cm_write_mod_reg(cm_context.sgx_cm_clkstctrl, OMAP3430ES2_SGX_MOD,
OMAP2_CM_CLKSTCTRL);
omap2_cm_write_mod_reg(cm_context.dss_cm_clkstctrl, OMAP3430_DSS_MOD,
OMAP2_CM_CLKSTCTRL);
omap2_cm_write_mod_reg(cm_context.cam_cm_clkstctrl, OMAP3430_CAM_MOD,
OMAP2_CM_CLKSTCTRL);
omap2_cm_write_mod_reg(cm_context.per_cm_clkstctrl, OMAP3430_PER_MOD,
OMAP2_CM_CLKSTCTRL);
omap2_cm_write_mod_reg(cm_context.neon_cm_clkstctrl, OMAP3430_NEON_MOD,
OMAP2_CM_CLKSTCTRL);
omap2_cm_write_mod_reg(cm_context.usbhost_cm_clkstctrl,
OMAP3430ES2_USBHOST_MOD, OMAP2_CM_CLKSTCTRL);
omap2_cm_write_mod_reg(cm_context.core_cm_autoidle1, CORE_MOD,
CM_AUTOIDLE1);
omap2_cm_write_mod_reg(cm_context.core_cm_autoidle2, CORE_MOD,
CM_AUTOIDLE2);
omap2_cm_write_mod_reg(cm_context.core_cm_autoidle3, CORE_MOD,
CM_AUTOIDLE3);
omap2_cm_write_mod_reg(cm_context.wkup_cm_autoidle, WKUP_MOD,
CM_AUTOIDLE);
omap2_cm_write_mod_reg(cm_context.dss_cm_autoidle, OMAP3430_DSS_MOD,
CM_AUTOIDLE);
omap2_cm_write_mod_reg(cm_context.cam_cm_autoidle, OMAP3430_CAM_MOD,
CM_AUTOIDLE);
omap2_cm_write_mod_reg(cm_context.per_cm_autoidle, OMAP3430_PER_MOD,
CM_AUTOIDLE);
omap2_cm_write_mod_reg(cm_context.usbhost_cm_autoidle,
OMAP3430ES2_USBHOST_MOD, CM_AUTOIDLE);
omap2_cm_write_mod_reg(cm_context.sgx_cm_sleepdep, OMAP3430ES2_SGX_MOD,
OMAP3430_CM_SLEEPDEP);
omap2_cm_write_mod_reg(cm_context.dss_cm_sleepdep, OMAP3430_DSS_MOD,
OMAP3430_CM_SLEEPDEP);
omap2_cm_write_mod_reg(cm_context.cam_cm_sleepdep, OMAP3430_CAM_MOD,
OMAP3430_CM_SLEEPDEP);
omap2_cm_write_mod_reg(cm_context.per_cm_sleepdep, OMAP3430_PER_MOD,
OMAP3430_CM_SLEEPDEP);
omap2_cm_write_mod_reg(cm_context.usbhost_cm_sleepdep,
OMAP3430ES2_USBHOST_MOD, OMAP3430_CM_SLEEPDEP);
omap2_cm_write_mod_reg(cm_context.cm_clkout_ctrl, OMAP3430_CCR_MOD,
OMAP3_CM_CLKOUT_CTRL_OFFSET);
}
void omap3_cm_save_scratchpad_contents(u32 *ptr)
{
*ptr++ = omap2_cm_read_mod_reg(CORE_MOD, CM_CLKSEL);
*ptr++ = omap2_cm_read_mod_reg(WKUP_MOD, CM_CLKSEL);
*ptr++ = omap2_cm_read_mod_reg(PLL_MOD, CM_CLKEN);
*ptr++ = omap2_cm_read_mod_reg(PLL_MOD, CM_AUTOIDLE) &
~OMAP3430_AUTO_PERIPH_DPLL_MASK;
*ptr++ = omap2_cm_read_mod_reg(PLL_MOD, OMAP3430_CM_CLKSEL1_PLL);
*ptr++ = omap2_cm_read_mod_reg(PLL_MOD, OMAP3430_CM_CLKSEL2_PLL);
*ptr++ = omap2_cm_read_mod_reg(PLL_MOD, OMAP3430_CM_CLKSEL3);
*ptr++ = omap2_cm_read_mod_reg(MPU_MOD, OMAP3430_CM_CLKEN_PLL);
*ptr++ = omap2_cm_read_mod_reg(MPU_MOD, OMAP3430_CM_AUTOIDLE_PLL);
*ptr++ = omap2_cm_read_mod_reg(MPU_MOD, OMAP3430_CM_CLKSEL1_PLL);
*ptr++ = omap2_cm_read_mod_reg(MPU_MOD, OMAP3430_CM_CLKSEL2_PLL);
}
int __init omap3xxx_cm_init(void)
{
if (!cpu_is_omap34xx())
return 0;
return cm_register(&omap3xxx_cm_ll_data);
}
static void __exit omap3xxx_cm_exit(void)
{
if (!cpu_is_omap34xx())
return;
WARN(cm_unregister(&omap3xxx_cm_ll_data),
"%s: cm_ll_data function pointer mismatch\n", __func__);
}
