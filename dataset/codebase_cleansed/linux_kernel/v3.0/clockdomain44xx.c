static int omap4_clkdm_add_wkup_sleep_dep(struct clockdomain *clkdm1,
struct clockdomain *clkdm2)
{
omap4_cminst_set_inst_reg_bits((1 << clkdm2->dep_bit),
clkdm1->prcm_partition,
clkdm1->cm_inst, clkdm1->clkdm_offs +
OMAP4_CM_STATICDEP);
return 0;
}
static int omap4_clkdm_del_wkup_sleep_dep(struct clockdomain *clkdm1,
struct clockdomain *clkdm2)
{
omap4_cminst_clear_inst_reg_bits((1 << clkdm2->dep_bit),
clkdm1->prcm_partition,
clkdm1->cm_inst, clkdm1->clkdm_offs +
OMAP4_CM_STATICDEP);
return 0;
}
static int omap4_clkdm_read_wkup_sleep_dep(struct clockdomain *clkdm1,
struct clockdomain *clkdm2)
{
return omap4_cminst_read_inst_reg_bits(clkdm1->prcm_partition,
clkdm1->cm_inst, clkdm1->clkdm_offs +
OMAP4_CM_STATICDEP,
(1 << clkdm2->dep_bit));
}
static int omap4_clkdm_clear_all_wkup_sleep_deps(struct clockdomain *clkdm)
{
struct clkdm_dep *cd;
u32 mask = 0;
for (cd = clkdm->wkdep_srcs; cd && cd->clkdm_name; cd++) {
if (!omap_chip_is(cd->omap_chip))
continue;
if (!cd->clkdm)
continue;
mask |= 1 << cd->clkdm->dep_bit;
atomic_set(&cd->wkdep_usecount, 0);
}
omap4_cminst_clear_inst_reg_bits(mask, clkdm->prcm_partition,
clkdm->cm_inst, clkdm->clkdm_offs +
OMAP4_CM_STATICDEP);
return 0;
}
static int omap4_clkdm_sleep(struct clockdomain *clkdm)
{
omap4_cminst_clkdm_force_sleep(clkdm->prcm_partition,
clkdm->cm_inst, clkdm->clkdm_offs);
return 0;
}
static int omap4_clkdm_wakeup(struct clockdomain *clkdm)
{
omap4_cminst_clkdm_force_wakeup(clkdm->prcm_partition,
clkdm->cm_inst, clkdm->clkdm_offs);
return 0;
}
static void omap4_clkdm_allow_idle(struct clockdomain *clkdm)
{
omap4_cminst_clkdm_enable_hwsup(clkdm->prcm_partition,
clkdm->cm_inst, clkdm->clkdm_offs);
}
static void omap4_clkdm_deny_idle(struct clockdomain *clkdm)
{
omap4_cminst_clkdm_disable_hwsup(clkdm->prcm_partition,
clkdm->cm_inst, clkdm->clkdm_offs);
}
static int omap4_clkdm_clk_enable(struct clockdomain *clkdm)
{
bool hwsup = false;
hwsup = omap4_cminst_is_clkdm_in_hwsup(clkdm->prcm_partition,
clkdm->cm_inst, clkdm->clkdm_offs);
if (!hwsup)
clkdm_wakeup(clkdm);
return 0;
}
static int omap4_clkdm_clk_disable(struct clockdomain *clkdm)
{
bool hwsup = false;
hwsup = omap4_cminst_is_clkdm_in_hwsup(clkdm->prcm_partition,
clkdm->cm_inst, clkdm->clkdm_offs);
if (!hwsup)
clkdm_sleep(clkdm);
return 0;
}
