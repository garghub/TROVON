int __init dra7xx_dt_clk_init(void)
{
int rc;
struct clk *abe_dpll_mux, *sys_clkin2, *dpll_ck;
ti_dt_clocks_register(dra7xx_clks);
omap2_clk_disable_autoidle_all();
abe_dpll_mux = clk_get_sys(NULL, "abe_dpll_sys_clk_mux");
sys_clkin2 = clk_get_sys(NULL, "sys_clkin2");
dpll_ck = clk_get_sys(NULL, "dpll_abe_ck");
rc = clk_set_parent(abe_dpll_mux, sys_clkin2);
if (!rc)
rc = clk_set_rate(dpll_ck, DRA7_DPLL_ABE_DEFFREQ);
if (rc)
pr_err("%s: failed to configure ABE DPLL!\n", __func__);
dpll_ck = clk_get_sys(NULL, "dpll_abe_m2x2_ck");
rc = clk_set_rate(dpll_ck, DRA7_DPLL_ABE_DEFFREQ * 2);
if (rc)
pr_err("%s: failed to configure ABE DPLL m2x2!\n", __func__);
dpll_ck = clk_get_sys(NULL, "dpll_gmac_ck");
rc = clk_set_rate(dpll_ck, DRA7_DPLL_GMAC_DEFFREQ);
if (rc)
pr_err("%s: failed to configure GMAC DPLL!\n", __func__);
return rc;
}
