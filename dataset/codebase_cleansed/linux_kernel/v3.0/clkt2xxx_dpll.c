static void _allow_idle(struct clk *clk)
{
if (!clk || !clk->dpll_data)
return;
omap2xxx_cm_set_dpll_auto_low_power_stop();
}
static void _deny_idle(struct clk *clk)
{
if (!clk || !clk->dpll_data)
return;
omap2xxx_cm_set_dpll_disable_autoidle();
}
