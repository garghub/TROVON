int omap2_prm_is_hardreset_asserted(s16 prm_mod, u8 shift)
{
return omap2_prm_read_mod_bits_shift(prm_mod, OMAP2_RM_RSTCTRL,
(1 << shift));
}
int omap2_prm_assert_hardreset(s16 prm_mod, u8 shift)
{
u32 mask;
mask = 1 << shift;
omap2_prm_rmw_mod_reg_bits(mask, mask, prm_mod, OMAP2_RM_RSTCTRL);
return 0;
}
int omap2_prm_deassert_hardreset(s16 prm_mod, u8 rst_shift, u8 st_shift)
{
u32 rst, st;
int c;
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
int omap2_pwrdm_set_mem_onst(struct powerdomain *pwrdm, u8 bank,
u8 pwrst)
{
u32 m;
m = omap2_pwrdm_get_mem_bank_onstate_mask(bank);
omap2_prm_rmw_mod_reg_bits(m, (pwrst << __ffs(m)), pwrdm->prcm_offs,
OMAP2_PM_PWSTCTRL);
return 0;
}
int omap2_pwrdm_set_mem_retst(struct powerdomain *pwrdm, u8 bank,
u8 pwrst)
{
u32 m;
m = omap2_pwrdm_get_mem_bank_retst_mask(bank);
omap2_prm_rmw_mod_reg_bits(m, (pwrst << __ffs(m)), pwrdm->prcm_offs,
OMAP2_PM_PWSTCTRL);
return 0;
}
int omap2_pwrdm_read_mem_pwrst(struct powerdomain *pwrdm, u8 bank)
{
u32 m;
m = omap2_pwrdm_get_mem_bank_stst_mask(bank);
return omap2_prm_read_mod_bits_shift(pwrdm->prcm_offs, OMAP2_PM_PWSTST,
m);
}
int omap2_pwrdm_read_mem_retst(struct powerdomain *pwrdm, u8 bank)
{
u32 m;
m = omap2_pwrdm_get_mem_bank_retst_mask(bank);
return omap2_prm_read_mod_bits_shift(pwrdm->prcm_offs,
OMAP2_PM_PWSTCTRL, m);
}
int omap2_pwrdm_set_logic_retst(struct powerdomain *pwrdm, u8 pwrst)
{
u32 v;
v = pwrst << __ffs(OMAP_LOGICRETSTATE_MASK);
omap2_prm_rmw_mod_reg_bits(OMAP_LOGICRETSTATE_MASK, v, pwrdm->prcm_offs,
OMAP2_PM_PWSTCTRL);
return 0;
}
int omap2_pwrdm_wait_transition(struct powerdomain *pwrdm)
{
u32 c = 0;
while ((omap2_prm_read_mod_reg(pwrdm->prcm_offs, OMAP2_PM_PWSTST) &
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
int omap2_clkdm_add_wkdep(struct clockdomain *clkdm1,
struct clockdomain *clkdm2)
{
omap2_prm_set_mod_reg_bits((1 << clkdm2->dep_bit),
clkdm1->pwrdm.ptr->prcm_offs, PM_WKDEP);
return 0;
}
int omap2_clkdm_del_wkdep(struct clockdomain *clkdm1,
struct clockdomain *clkdm2)
{
omap2_prm_clear_mod_reg_bits((1 << clkdm2->dep_bit),
clkdm1->pwrdm.ptr->prcm_offs, PM_WKDEP);
return 0;
}
int omap2_clkdm_read_wkdep(struct clockdomain *clkdm1,
struct clockdomain *clkdm2)
{
return omap2_prm_read_mod_bits_shift(clkdm1->pwrdm.ptr->prcm_offs,
PM_WKDEP, (1 << clkdm2->dep_bit));
}
int omap2_clkdm_clear_all_wkdeps(struct clockdomain *clkdm)
{
struct clkdm_dep *cd;
u32 mask = 0;
for (cd = clkdm->wkdep_srcs; cd && cd->clkdm_name; cd++) {
if (!cd->clkdm)
continue;
mask |= 1 << cd->clkdm->dep_bit;
cd->wkdep_usecount = 0;
}
omap2_prm_clear_mod_reg_bits(mask, clkdm->pwrdm.ptr->prcm_offs,
PM_WKDEP);
return 0;
}
