int omap3_dpll4_set_rate(struct clk *clk, unsigned long rate)
{
if (omap_rev() == OMAP3430_REV_ES1_0) {
pr_err("clock: DPLL4 cannot change rate due to "
"silicon 'Limitation 2.5' on 3430ES1.\n");
return -EINVAL;
}
return omap3_noncore_dpll_set_rate(clk, rate);
}
void __init omap3_clk_lock_dpll5(void)
{
struct clk *dpll5_clk;
struct clk *dpll5_m2_clk;
dpll5_clk = clk_get(NULL, "dpll5_ck");
clk_set_rate(dpll5_clk, DPLL5_FREQ_FOR_USBHOST);
clk_enable(dpll5_clk);
dpll5_m2_clk = clk_get(NULL, "dpll5_m2_ck");
clk_enable(dpll5_m2_clk);
clk_set_rate(dpll5_m2_clk, DPLL5_FREQ_FOR_USBHOST);
clk_disable(dpll5_m2_clk);
clk_disable(dpll5_clk);
return;
}
static int __init omap3xxx_clk_arch_init(void)
{
int ret;
if (!cpu_is_omap34xx())
return 0;
ret = omap2_clk_switch_mpurate_at_boot("dpll1_ck");
if (!ret)
omap2_clk_print_new_rates("osc_sys_ck", "core_ck", "arm_fck");
return ret;
}
