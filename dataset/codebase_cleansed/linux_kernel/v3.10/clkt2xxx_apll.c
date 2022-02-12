static bool omap2xxx_clk_apll_locked(struct clk_hw *hw)
{
struct clk_hw_omap *clk = to_clk_hw_omap(hw);
u32 r, apll_mask;
apll_mask = EN_APLL_LOCKED << clk->enable_bit;
r = omap2_cm_read_mod_reg(PLL_MOD, CM_CLKEN);
return ((r & apll_mask) == apll_mask) ? true : false;
}
int omap2_clk_apll96_enable(struct clk_hw *hw)
{
return omap2xxx_cm_apll96_enable();
}
int omap2_clk_apll54_enable(struct clk_hw *hw)
{
return omap2xxx_cm_apll54_enable();
}
static void _apll96_allow_idle(struct clk_hw_omap *clk)
{
omap2xxx_cm_set_apll96_auto_low_power_stop();
}
static void _apll96_deny_idle(struct clk_hw_omap *clk)
{
omap2xxx_cm_set_apll96_disable_autoidle();
}
static void _apll54_allow_idle(struct clk_hw_omap *clk)
{
omap2xxx_cm_set_apll54_auto_low_power_stop();
}
static void _apll54_deny_idle(struct clk_hw_omap *clk)
{
omap2xxx_cm_set_apll54_disable_autoidle();
}
void omap2_clk_apll96_disable(struct clk_hw *hw)
{
omap2xxx_cm_apll96_disable();
}
void omap2_clk_apll54_disable(struct clk_hw *hw)
{
omap2xxx_cm_apll54_disable();
}
unsigned long omap2_clk_apll54_recalc(struct clk_hw *hw,
unsigned long parent_rate)
{
return (omap2xxx_clk_apll_locked(hw)) ? 54000000 : 0;
}
unsigned long omap2_clk_apll96_recalc(struct clk_hw *hw,
unsigned long parent_rate)
{
return (omap2xxx_clk_apll_locked(hw)) ? 96000000 : 0;
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
