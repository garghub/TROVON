static int omap2_clkdm_add_wkdep(struct clockdomain *clkdm1,
struct clockdomain *clkdm2)
{
omap2_prm_set_mod_reg_bits((1 << clkdm2->dep_bit),
clkdm1->pwrdm.ptr->prcm_offs, PM_WKDEP);
return 0;
}
static int omap2_clkdm_del_wkdep(struct clockdomain *clkdm1,
struct clockdomain *clkdm2)
{
omap2_prm_clear_mod_reg_bits((1 << clkdm2->dep_bit),
clkdm1->pwrdm.ptr->prcm_offs, PM_WKDEP);
return 0;
}
static int omap2_clkdm_read_wkdep(struct clockdomain *clkdm1,
struct clockdomain *clkdm2)
{
return omap2_prm_read_mod_bits_shift(clkdm1->pwrdm.ptr->prcm_offs,
PM_WKDEP, (1 << clkdm2->dep_bit));
}
static int omap2_clkdm_clear_all_wkdeps(struct clockdomain *clkdm)
{
struct clkdm_dep *cd;
u32 mask = 0;
for (cd = clkdm->wkdep_srcs; cd && cd->clkdm_name; cd++) {
if (!cd->clkdm)
continue;
mask |= 1 << cd->clkdm->dep_bit;
atomic_set(&cd->wkdep_usecount, 0);
}
omap2_prm_clear_mod_reg_bits(mask, clkdm->pwrdm.ptr->prcm_offs,
PM_WKDEP);
return 0;
}
static int omap3_clkdm_add_sleepdep(struct clockdomain *clkdm1,
struct clockdomain *clkdm2)
{
omap2_cm_set_mod_reg_bits((1 << clkdm2->dep_bit),
clkdm1->pwrdm.ptr->prcm_offs,
OMAP3430_CM_SLEEPDEP);
return 0;
}
static int omap3_clkdm_del_sleepdep(struct clockdomain *clkdm1,
struct clockdomain *clkdm2)
{
omap2_cm_clear_mod_reg_bits((1 << clkdm2->dep_bit),
clkdm1->pwrdm.ptr->prcm_offs,
OMAP3430_CM_SLEEPDEP);
return 0;
}
static int omap3_clkdm_read_sleepdep(struct clockdomain *clkdm1,
struct clockdomain *clkdm2)
{
return omap2_prm_read_mod_bits_shift(clkdm1->pwrdm.ptr->prcm_offs,
OMAP3430_CM_SLEEPDEP, (1 << clkdm2->dep_bit));
}
static int omap3_clkdm_clear_all_sleepdeps(struct clockdomain *clkdm)
{
struct clkdm_dep *cd;
u32 mask = 0;
for (cd = clkdm->sleepdep_srcs; cd && cd->clkdm_name; cd++) {
if (!cd->clkdm)
continue;
mask |= 1 << cd->clkdm->dep_bit;
atomic_set(&cd->sleepdep_usecount, 0);
}
omap2_prm_clear_mod_reg_bits(mask, clkdm->pwrdm.ptr->prcm_offs,
OMAP3430_CM_SLEEPDEP);
return 0;
}
static int omap2_clkdm_sleep(struct clockdomain *clkdm)
{
omap2_cm_set_mod_reg_bits(OMAP24XX_FORCESTATE_MASK,
clkdm->pwrdm.ptr->prcm_offs,
OMAP2_PM_PWSTCTRL);
return 0;
}
static int omap2_clkdm_wakeup(struct clockdomain *clkdm)
{
omap2_cm_clear_mod_reg_bits(OMAP24XX_FORCESTATE_MASK,
clkdm->pwrdm.ptr->prcm_offs,
OMAP2_PM_PWSTCTRL);
return 0;
}
static void omap2_clkdm_allow_idle(struct clockdomain *clkdm)
{
if (atomic_read(&clkdm->usecount) > 0)
_clkdm_add_autodeps(clkdm);
omap2xxx_cm_clkdm_enable_hwsup(clkdm->pwrdm.ptr->prcm_offs,
clkdm->clktrctrl_mask);
}
static void omap2_clkdm_deny_idle(struct clockdomain *clkdm)
{
omap2xxx_cm_clkdm_disable_hwsup(clkdm->pwrdm.ptr->prcm_offs,
clkdm->clktrctrl_mask);
if (atomic_read(&clkdm->usecount) > 0)
_clkdm_del_autodeps(clkdm);
}
static void _enable_hwsup(struct clockdomain *clkdm)
{
if (cpu_is_omap24xx())
omap2xxx_cm_clkdm_enable_hwsup(clkdm->pwrdm.ptr->prcm_offs,
clkdm->clktrctrl_mask);
else if (cpu_is_omap34xx())
omap3xxx_cm_clkdm_enable_hwsup(clkdm->pwrdm.ptr->prcm_offs,
clkdm->clktrctrl_mask);
}
static void _disable_hwsup(struct clockdomain *clkdm)
{
if (cpu_is_omap24xx())
omap2xxx_cm_clkdm_disable_hwsup(clkdm->pwrdm.ptr->prcm_offs,
clkdm->clktrctrl_mask);
else if (cpu_is_omap34xx())
omap3xxx_cm_clkdm_disable_hwsup(clkdm->pwrdm.ptr->prcm_offs,
clkdm->clktrctrl_mask);
}
static int omap2_clkdm_clk_enable(struct clockdomain *clkdm)
{
bool hwsup = false;
if (!clkdm->clktrctrl_mask)
return 0;
hwsup = omap2_cm_is_clkdm_in_hwsup(clkdm->pwrdm.ptr->prcm_offs,
clkdm->clktrctrl_mask);
if (hwsup) {
_disable_hwsup(clkdm);
_clkdm_add_autodeps(clkdm);
_enable_hwsup(clkdm);
} else {
if (clkdm->flags & CLKDM_CAN_FORCE_WAKEUP)
omap2_clkdm_wakeup(clkdm);
}
return 0;
}
static int omap2_clkdm_clk_disable(struct clockdomain *clkdm)
{
bool hwsup = false;
if (!clkdm->clktrctrl_mask)
return 0;
hwsup = omap2_cm_is_clkdm_in_hwsup(clkdm->pwrdm.ptr->prcm_offs,
clkdm->clktrctrl_mask);
if (hwsup) {
_disable_hwsup(clkdm);
_clkdm_del_autodeps(clkdm);
_enable_hwsup(clkdm);
} else {
if (clkdm->flags & CLKDM_CAN_FORCE_SLEEP)
omap2_clkdm_sleep(clkdm);
}
return 0;
}
static int omap3_clkdm_sleep(struct clockdomain *clkdm)
{
omap3xxx_cm_clkdm_force_sleep(clkdm->pwrdm.ptr->prcm_offs,
clkdm->clktrctrl_mask);
return 0;
}
static int omap3_clkdm_wakeup(struct clockdomain *clkdm)
{
omap3xxx_cm_clkdm_force_wakeup(clkdm->pwrdm.ptr->prcm_offs,
clkdm->clktrctrl_mask);
return 0;
}
static void omap3_clkdm_allow_idle(struct clockdomain *clkdm)
{
if (atomic_read(&clkdm->usecount) > 0)
_clkdm_add_autodeps(clkdm);
omap3xxx_cm_clkdm_enable_hwsup(clkdm->pwrdm.ptr->prcm_offs,
clkdm->clktrctrl_mask);
}
static void omap3_clkdm_deny_idle(struct clockdomain *clkdm)
{
omap3xxx_cm_clkdm_disable_hwsup(clkdm->pwrdm.ptr->prcm_offs,
clkdm->clktrctrl_mask);
if (atomic_read(&clkdm->usecount) > 0)
_clkdm_del_autodeps(clkdm);
}
static int omap3xxx_clkdm_clk_enable(struct clockdomain *clkdm)
{
bool hwsup = false;
if (!clkdm->clktrctrl_mask)
return 0;
hwsup = omap2_cm_is_clkdm_in_hwsup(clkdm->pwrdm.ptr->prcm_offs,
clkdm->clktrctrl_mask);
if (hwsup) {
_disable_hwsup(clkdm);
_clkdm_add_autodeps(clkdm);
_enable_hwsup(clkdm);
} else {
if (clkdm->flags & CLKDM_CAN_FORCE_WAKEUP)
omap3_clkdm_wakeup(clkdm);
}
return 0;
}
static int omap3xxx_clkdm_clk_disable(struct clockdomain *clkdm)
{
bool hwsup = false;
if (!clkdm->clktrctrl_mask)
return 0;
hwsup = omap2_cm_is_clkdm_in_hwsup(clkdm->pwrdm.ptr->prcm_offs,
clkdm->clktrctrl_mask);
if (hwsup) {
_disable_hwsup(clkdm);
_clkdm_del_autodeps(clkdm);
_enable_hwsup(clkdm);
} else {
if (clkdm->flags & CLKDM_CAN_FORCE_SLEEP)
omap3_clkdm_sleep(clkdm);
}
return 0;
}
