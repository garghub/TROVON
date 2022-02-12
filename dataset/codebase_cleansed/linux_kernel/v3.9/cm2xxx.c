static void _write_clktrctrl(u8 c, s16 module, u32 mask)
{
u32 v;
v = omap2_cm_read_mod_reg(module, OMAP2_CM_CLKSTCTRL);
v &= ~mask;
v |= c << __ffs(mask);
omap2_cm_write_mod_reg(v, module, OMAP2_CM_CLKSTCTRL);
}
bool omap2xxx_cm_is_clkdm_in_hwsup(s16 module, u32 mask)
{
u32 v;
v = omap2_cm_read_mod_reg(module, OMAP2_CM_CLKSTCTRL);
v &= mask;
v >>= __ffs(mask);
return (v == OMAP24XX_CLKSTCTRL_ENABLE_AUTO) ? 1 : 0;
}
void omap2xxx_cm_clkdm_enable_hwsup(s16 module, u32 mask)
{
_write_clktrctrl(OMAP24XX_CLKSTCTRL_ENABLE_AUTO, module, mask);
}
void omap2xxx_cm_clkdm_disable_hwsup(s16 module, u32 mask)
{
_write_clktrctrl(OMAP24XX_CLKSTCTRL_DISABLE_AUTO, module, mask);
}
static void _omap2xxx_set_dpll_autoidle(u8 m)
{
u32 v;
v = omap2_cm_read_mod_reg(PLL_MOD, CM_AUTOIDLE);
v &= ~OMAP24XX_AUTO_DPLL_MASK;
v |= m << OMAP24XX_AUTO_DPLL_SHIFT;
omap2_cm_write_mod_reg(v, PLL_MOD, CM_AUTOIDLE);
}
void omap2xxx_cm_set_dpll_disable_autoidle(void)
{
_omap2xxx_set_dpll_autoidle(OMAP2XXX_DPLL_AUTOIDLE_LOW_POWER_STOP);
}
void omap2xxx_cm_set_dpll_auto_low_power_stop(void)
{
_omap2xxx_set_dpll_autoidle(DPLL_AUTOIDLE_DISABLE);
}
static void _omap2xxx_set_apll_autoidle(u8 m, u32 mask)
{
u32 v;
v = omap2_cm_read_mod_reg(PLL_MOD, CM_AUTOIDLE);
v &= ~mask;
v |= m << __ffs(mask);
omap2_cm_write_mod_reg(v, PLL_MOD, CM_AUTOIDLE);
}
void omap2xxx_cm_set_apll54_disable_autoidle(void)
{
_omap2xxx_set_apll_autoidle(OMAP2XXX_APLL_AUTOIDLE_LOW_POWER_STOP,
OMAP24XX_AUTO_54M_MASK);
}
void omap2xxx_cm_set_apll54_auto_low_power_stop(void)
{
_omap2xxx_set_apll_autoidle(OMAP2XXX_APLL_AUTOIDLE_DISABLE,
OMAP24XX_AUTO_54M_MASK);
}
void omap2xxx_cm_set_apll96_disable_autoidle(void)
{
_omap2xxx_set_apll_autoidle(OMAP2XXX_APLL_AUTOIDLE_LOW_POWER_STOP,
OMAP24XX_AUTO_96M_MASK);
}
void omap2xxx_cm_set_apll96_auto_low_power_stop(void)
{
_omap2xxx_set_apll_autoidle(OMAP2XXX_APLL_AUTOIDLE_DISABLE,
OMAP24XX_AUTO_96M_MASK);
}
static int _omap2xxx_apll_enable(u8 enable_bit, u8 status_bit)
{
u32 v, m;
m = EN_APLL_LOCKED << enable_bit;
v = omap2_cm_read_mod_reg(PLL_MOD, CM_CLKEN);
if (v & m)
return 0;
v |= m;
omap2_cm_write_mod_reg(v, PLL_MOD, CM_CLKEN);
omap2xxx_cm_wait_module_ready(PLL_MOD, 1, status_bit);
return 0;
}
static void _omap2xxx_apll_disable(u8 enable_bit)
{
u32 v;
v = omap2_cm_read_mod_reg(PLL_MOD, CM_CLKEN);
v &= ~(EN_APLL_LOCKED << enable_bit);
omap2_cm_write_mod_reg(v, PLL_MOD, CM_CLKEN);
}
int omap2xxx_cm_apll54_enable(void)
{
return _omap2xxx_apll_enable(OMAP24XX_EN_54M_PLL_SHIFT,
OMAP24XX_ST_54M_APLL_SHIFT);
}
int omap2xxx_cm_apll96_enable(void)
{
return _omap2xxx_apll_enable(OMAP24XX_EN_96M_PLL_SHIFT,
OMAP24XX_ST_96M_APLL_SHIFT);
}
void omap2xxx_cm_apll54_disable(void)
{
_omap2xxx_apll_disable(OMAP24XX_EN_54M_PLL_SHIFT);
}
void omap2xxx_cm_apll96_disable(void)
{
_omap2xxx_apll_disable(OMAP24XX_EN_96M_PLL_SHIFT);
}
int omap2xxx_cm_split_idlest_reg(void __iomem *idlest_reg, s16 *prcm_inst,
u8 *idlest_reg_id)
{
unsigned long offs;
u8 idlest_offs;
int i;
if (idlest_reg < cm_base || idlest_reg > (cm_base + 0x0fff))
return -EINVAL;
idlest_offs = (unsigned long)idlest_reg & 0xff;
for (i = 0; i < ARRAY_SIZE(omap2xxx_cm_idlest_offs); i++) {
if (idlest_offs == omap2xxx_cm_idlest_offs[i]) {
*idlest_reg_id = i + 1;
break;
}
}
if (i == ARRAY_SIZE(omap2xxx_cm_idlest_offs))
return -EINVAL;
offs = idlest_reg - cm_base;
offs &= 0xff00;
*prcm_inst = offs;
return 0;
}
int omap2xxx_cm_wait_module_ready(s16 prcm_mod, u8 idlest_id, u8 idlest_shift)
{
int ena = 0, i = 0;
u8 cm_idlest_reg;
u32 mask;
if (!idlest_id || (idlest_id > ARRAY_SIZE(omap2xxx_cm_idlest_offs)))
return -EINVAL;
cm_idlest_reg = omap2xxx_cm_idlest_offs[idlest_id - 1];
mask = 1 << idlest_shift;
ena = mask;
omap_test_timeout(((omap2_cm_read_mod_reg(prcm_mod, cm_idlest_reg) &
mask) == ena), MAX_MODULE_READY_TIME, i);
return (i < MAX_MODULE_READY_TIME) ? 0 : -EBUSY;
}
static void omap2xxx_clkdm_allow_idle(struct clockdomain *clkdm)
{
omap2xxx_cm_clkdm_enable_hwsup(clkdm->pwrdm.ptr->prcm_offs,
clkdm->clktrctrl_mask);
}
static void omap2xxx_clkdm_deny_idle(struct clockdomain *clkdm)
{
omap2xxx_cm_clkdm_disable_hwsup(clkdm->pwrdm.ptr->prcm_offs,
clkdm->clktrctrl_mask);
}
static int omap2xxx_clkdm_clk_enable(struct clockdomain *clkdm)
{
bool hwsup = false;
if (!clkdm->clktrctrl_mask)
return 0;
hwsup = omap2xxx_cm_is_clkdm_in_hwsup(clkdm->pwrdm.ptr->prcm_offs,
clkdm->clktrctrl_mask);
if (!hwsup && clkdm->flags & CLKDM_CAN_FORCE_WAKEUP)
omap2xxx_clkdm_wakeup(clkdm);
return 0;
}
static int omap2xxx_clkdm_clk_disable(struct clockdomain *clkdm)
{
bool hwsup = false;
if (!clkdm->clktrctrl_mask)
return 0;
hwsup = omap2xxx_cm_is_clkdm_in_hwsup(clkdm->pwrdm.ptr->prcm_offs,
clkdm->clktrctrl_mask);
if (!hwsup && clkdm->flags & CLKDM_CAN_FORCE_SLEEP)
omap2xxx_clkdm_sleep(clkdm);
return 0;
}
int __init omap2xxx_cm_init(void)
{
if (!cpu_is_omap24xx())
return 0;
return cm_register(&omap2xxx_cm_ll_data);
}
static void __exit omap2xxx_cm_exit(void)
{
if (!cpu_is_omap24xx())
return;
WARN(cm_unregister(&omap2xxx_cm_ll_data),
"%s: cm_ll_data function pointer mismatch\n", __func__);
}
