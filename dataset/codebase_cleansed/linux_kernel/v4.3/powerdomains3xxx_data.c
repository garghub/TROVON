static int ti81xx_pwrdm_set_next_pwrst(struct powerdomain *pwrdm, u8 pwrst)
{
omap2_prm_rmw_mod_reg_bits(OMAP_POWERSTATE_MASK,
(pwrst << OMAP_POWERSTATE_SHIFT),
pwrdm->prcm_offs, TI81XX_PM_PWSTCTRL);
return 0;
}
static int ti81xx_pwrdm_read_next_pwrst(struct powerdomain *pwrdm)
{
return omap2_prm_read_mod_bits_shift(pwrdm->prcm_offs,
TI81XX_PM_PWSTCTRL,
OMAP_POWERSTATE_MASK);
}
static int ti81xx_pwrdm_read_pwrst(struct powerdomain *pwrdm)
{
return omap2_prm_read_mod_bits_shift(pwrdm->prcm_offs,
(pwrdm->prcm_offs == TI814X_PRM_GFX_MOD) ? TI81XX_RM_RSTCTRL :
TI81XX_PM_PWSTST,
OMAP_POWERSTATEST_MASK);
}
static int ti81xx_pwrdm_read_logic_pwrst(struct powerdomain *pwrdm)
{
return omap2_prm_read_mod_bits_shift(pwrdm->prcm_offs,
(pwrdm->prcm_offs == TI814X_PRM_GFX_MOD) ? TI81XX_RM_RSTCTRL :
TI81XX_PM_PWSTST,
OMAP3430_LOGICSTATEST_MASK);
}
static int ti81xx_pwrdm_wait_transition(struct powerdomain *pwrdm)
{
u32 c = 0;
while ((omap2_prm_read_mod_reg(pwrdm->prcm_offs,
(pwrdm->prcm_offs == TI814X_PRM_GFX_MOD) ? TI81XX_RM_RSTCTRL :
TI81XX_PM_PWSTST) &
OMAP_INTRANSITION_MASK) &&
(c++ < PWRDM_TRANSITION_BAILOUT))
udelay(1);
if (c > PWRDM_TRANSITION_BAILOUT) {
pr_err("powerdomain: %s timeout waiting for transition\n",
pwrdm->name);
return -EAGAIN;
}
pr_debug("powerdomain: completed transition in %d loops\n", c);
return 0;
}
void __init omap3xxx_powerdomains_init(void)
{
unsigned int rev;
if (!cpu_is_omap34xx() && !cpu_is_ti81xx())
return;
if (!cpu_is_ti81xx())
pwrdm_register_platform_funcs(&omap3_pwrdm_operations);;
rev = omap_rev();
if (rev == AM35XX_REV_ES1_0 || rev == AM35XX_REV_ES1_1) {
pwrdm_register_pwrdms(powerdomains_am35x);
} else if (rev == TI8148_REV_ES1_0 || rev == TI8148_REV_ES2_0 ||
rev == TI8148_REV_ES2_1) {
pwrdm_register_platform_funcs(&ti81xx_pwrdm_operations);
pwrdm_register_pwrdms(powerdomains_ti814x);
} else if (rev == TI8168_REV_ES1_0 || rev == TI8168_REV_ES1_1
|| rev == TI8168_REV_ES2_0 || rev == TI8168_REV_ES2_1) {
pwrdm_register_platform_funcs(&ti81xx_pwrdm_operations);
pwrdm_register_pwrdms(powerdomains_ti816x);
} else {
pwrdm_register_pwrdms(powerdomains_omap3430_common);
switch (rev) {
case OMAP3430_REV_ES1_0:
pwrdm_register_pwrdms(powerdomains_omap3430es1);
break;
case OMAP3430_REV_ES2_0:
case OMAP3430_REV_ES2_1:
case OMAP3430_REV_ES3_0:
case OMAP3630_REV_ES1_0:
pwrdm_register_pwrdms(powerdomains_omap3430es2_es3_0);
break;
case OMAP3430_REV_ES3_1:
case OMAP3430_REV_ES3_1_2:
case OMAP3630_REV_ES1_1:
case OMAP3630_REV_ES1_2:
pwrdm_register_pwrdms(powerdomains_omap3430es3_1plus);
break;
default:
WARN(1, "OMAP3 powerdomain init: unknown chip type\n");
}
}
pwrdm_complete_init();
}
