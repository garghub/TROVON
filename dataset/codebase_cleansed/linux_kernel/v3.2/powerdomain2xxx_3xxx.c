static int omap2_pwrdm_set_next_pwrst(struct powerdomain *pwrdm, u8 pwrst)
{
omap2_prm_rmw_mod_reg_bits(OMAP_POWERSTATE_MASK,
(pwrst << OMAP_POWERSTATE_SHIFT),
pwrdm->prcm_offs, OMAP2_PM_PWSTCTRL);
return 0;
}
static int omap2_pwrdm_read_next_pwrst(struct powerdomain *pwrdm)
{
return omap2_prm_read_mod_bits_shift(pwrdm->prcm_offs,
OMAP2_PM_PWSTCTRL,
OMAP_POWERSTATE_MASK);
}
static int omap2_pwrdm_read_pwrst(struct powerdomain *pwrdm)
{
return omap2_prm_read_mod_bits_shift(pwrdm->prcm_offs,
OMAP2_PM_PWSTST,
OMAP_POWERSTATEST_MASK);
}
static int omap2_pwrdm_set_mem_onst(struct powerdomain *pwrdm, u8 bank,
u8 pwrst)
{
u32 m;
m = omap2_pwrdm_get_mem_bank_onstate_mask(bank);
omap2_prm_rmw_mod_reg_bits(m, (pwrst << __ffs(m)), pwrdm->prcm_offs,
OMAP2_PM_PWSTCTRL);
return 0;
}
static int omap2_pwrdm_set_mem_retst(struct powerdomain *pwrdm, u8 bank,
u8 pwrst)
{
u32 m;
m = omap2_pwrdm_get_mem_bank_retst_mask(bank);
omap2_prm_rmw_mod_reg_bits(m, (pwrst << __ffs(m)), pwrdm->prcm_offs,
OMAP2_PM_PWSTCTRL);
return 0;
}
static int omap2_pwrdm_read_mem_pwrst(struct powerdomain *pwrdm, u8 bank)
{
u32 m;
m = omap2_pwrdm_get_mem_bank_stst_mask(bank);
return omap2_prm_read_mod_bits_shift(pwrdm->prcm_offs, OMAP2_PM_PWSTST,
m);
}
static int omap2_pwrdm_read_mem_retst(struct powerdomain *pwrdm, u8 bank)
{
u32 m;
m = omap2_pwrdm_get_mem_bank_retst_mask(bank);
return omap2_prm_read_mod_bits_shift(pwrdm->prcm_offs,
OMAP2_PM_PWSTCTRL, m);
}
static int omap2_pwrdm_set_logic_retst(struct powerdomain *pwrdm, u8 pwrst)
{
u32 v;
v = pwrst << __ffs(OMAP3430_LOGICL1CACHERETSTATE_MASK);
omap2_prm_rmw_mod_reg_bits(OMAP3430_LOGICL1CACHERETSTATE_MASK, v,
pwrdm->prcm_offs, OMAP2_PM_PWSTCTRL);
return 0;
}
static int omap2_pwrdm_wait_transition(struct powerdomain *pwrdm)
{
u32 c = 0;
while ((omap2_prm_read_mod_reg(pwrdm->prcm_offs, OMAP2_PM_PWSTST) &
OMAP_INTRANSITION_MASK) &&
(c++ < PWRDM_TRANSITION_BAILOUT))
udelay(1);
if (c > PWRDM_TRANSITION_BAILOUT) {
printk(KERN_ERR "powerdomain: waited too long for "
"powerdomain %s to complete transition\n", pwrdm->name);
return -EAGAIN;
}
pr_debug("powerdomain: completed transition in %d loops\n", c);
return 0;
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
