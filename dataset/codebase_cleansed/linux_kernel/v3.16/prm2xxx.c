static u32 omap2xxx_prm_read_reset_sources(void)
{
struct prm_reset_src_map *p;
u32 r = 0;
u32 v;
v = omap2_prm_read_mod_reg(WKUP_MOD, OMAP2_RM_RSTST);
p = omap2xxx_prm_reset_src_map;
while (p->reg_shift >= 0 && p->std_shift >= 0) {
if (v & (1 << p->reg_shift))
r |= 1 << p->std_shift;
p++;
}
return r;
}
static int omap2xxx_pwrst_to_common_pwrst(u8 omap2xxx_pwrst)
{
u8 pwrst;
switch (omap2xxx_pwrst) {
case OMAP24XX_PWRDM_POWER_OFF:
pwrst = PWRDM_POWER_OFF;
break;
case OMAP24XX_PWRDM_POWER_RET:
pwrst = PWRDM_POWER_RET;
break;
case OMAP24XX_PWRDM_POWER_ON:
pwrst = PWRDM_POWER_ON;
break;
default:
return -EINVAL;
}
return pwrst;
}
void omap2xxx_prm_dpll_reset(void)
{
omap2_prm_set_mod_reg_bits(OMAP_RST_DPLL3_MASK, WKUP_MOD,
OMAP2_RM_RSTCTRL);
omap2_prm_read_mod_reg(WKUP_MOD, OMAP2_RM_RSTCTRL);
}
int omap2xxx_clkdm_sleep(struct clockdomain *clkdm)
{
omap2_prm_set_mod_reg_bits(OMAP24XX_FORCESTATE_MASK,
clkdm->pwrdm.ptr->prcm_offs,
OMAP2_PM_PWSTCTRL);
return 0;
}
int omap2xxx_clkdm_wakeup(struct clockdomain *clkdm)
{
omap2_prm_clear_mod_reg_bits(OMAP24XX_FORCESTATE_MASK,
clkdm->pwrdm.ptr->prcm_offs,
OMAP2_PM_PWSTCTRL);
return 0;
}
static int omap2xxx_pwrdm_set_next_pwrst(struct powerdomain *pwrdm, u8 pwrst)
{
u8 omap24xx_pwrst;
switch (pwrst) {
case PWRDM_POWER_OFF:
omap24xx_pwrst = OMAP24XX_PWRDM_POWER_OFF;
break;
case PWRDM_POWER_RET:
omap24xx_pwrst = OMAP24XX_PWRDM_POWER_RET;
break;
case PWRDM_POWER_ON:
omap24xx_pwrst = OMAP24XX_PWRDM_POWER_ON;
break;
default:
return -EINVAL;
}
omap2_prm_rmw_mod_reg_bits(OMAP_POWERSTATE_MASK,
(omap24xx_pwrst << OMAP_POWERSTATE_SHIFT),
pwrdm->prcm_offs, OMAP2_PM_PWSTCTRL);
return 0;
}
static int omap2xxx_pwrdm_read_next_pwrst(struct powerdomain *pwrdm)
{
u8 omap2xxx_pwrst;
omap2xxx_pwrst = omap2_prm_read_mod_bits_shift(pwrdm->prcm_offs,
OMAP2_PM_PWSTCTRL,
OMAP_POWERSTATE_MASK);
return omap2xxx_pwrst_to_common_pwrst(omap2xxx_pwrst);
}
static int omap2xxx_pwrdm_read_pwrst(struct powerdomain *pwrdm)
{
u8 omap2xxx_pwrst;
omap2xxx_pwrst = omap2_prm_read_mod_bits_shift(pwrdm->prcm_offs,
OMAP2_PM_PWSTST,
OMAP_POWERSTATEST_MASK);
return omap2xxx_pwrst_to_common_pwrst(omap2xxx_pwrst);
}
int __init omap2xxx_prm_init(void)
{
return prm_register(&omap2xxx_prm_ll_data);
}
static void __exit omap2xxx_prm_exit(void)
{
prm_unregister(&omap2xxx_prm_ll_data);
}
