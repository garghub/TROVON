static int omap3_mcbsp_force_ick_on(struct clk *clk, bool force_on)
{
if (!clk)
return 0;
if (force_on)
return omap2_clk_deny_idle(clk);
else
return omap2_clk_allow_idle(clk);
}
void __init omap3_mcbsp_init_pdata_callback(
struct omap_mcbsp_platform_data *pdata)
{
if (!pdata)
return;
pdata->force_ick_on = omap3_mcbsp_force_ick_on;
}
