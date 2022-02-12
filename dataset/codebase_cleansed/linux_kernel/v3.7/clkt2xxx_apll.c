static int omap2_clk_apll_enable(struct clk *clk, u32 status_mask)
{
u32 cval, apll_mask;
apll_mask = EN_APLL_LOCKED << clk->enable_bit;
cval = omap2_cm_read_mod_reg(PLL_MOD, CM_CLKEN);
if ((cval & apll_mask) == apll_mask)
return 0;
cval &= ~apll_mask;
cval |= apll_mask;
omap2_cm_write_mod_reg(cval, PLL_MOD, CM_CLKEN);
omap2_cm_wait_idlest(cm_idlest_pll, status_mask,
OMAP24XX_CM_IDLEST_VAL, __clk_get_name(clk));
return 0;
}
static int omap2_clk_apll96_enable(struct clk *clk)
{
return omap2_clk_apll_enable(clk, OMAP24XX_ST_96M_APLL_MASK);
}
static int omap2_clk_apll54_enable(struct clk *clk)
{
return omap2_clk_apll_enable(clk, OMAP24XX_ST_54M_APLL_MASK);
}
static void _apll96_allow_idle(struct clk *clk)
{
omap2xxx_cm_set_apll96_auto_low_power_stop();
}
static void _apll96_deny_idle(struct clk *clk)
{
omap2xxx_cm_set_apll96_disable_autoidle();
}
static void _apll54_allow_idle(struct clk *clk)
{
omap2xxx_cm_set_apll54_auto_low_power_stop();
}
static void _apll54_deny_idle(struct clk *clk)
{
omap2xxx_cm_set_apll54_disable_autoidle();
}
static void omap2_clk_apll_disable(struct clk *clk)
{
u32 cval;
cval = omap2_cm_read_mod_reg(PLL_MOD, CM_CLKEN);
cval &= ~(EN_APLL_LOCKED << clk->enable_bit);
omap2_cm_write_mod_reg(cval, PLL_MOD, CM_CLKEN);
}
u32 omap2xxx_get_apll_clkin(void)
{
u32 aplls, srate = 0;
aplls = omap2_cm_read_mod_reg(PLL_MOD, CM_CLKSEL1);
aplls &= OMAP24XX_APLLS_CLKIN_MASK;
aplls >>= OMAP24XX_APLLS_CLKIN_SHIFT;
if (aplls == APLLS_CLKIN_19_2MHZ)
srate = 19200000;
else if (aplls == APLLS_CLKIN_13MHZ)
srate = 13000000;
else if (aplls == APLLS_CLKIN_12MHZ)
srate = 12000000;
return srate;
}
