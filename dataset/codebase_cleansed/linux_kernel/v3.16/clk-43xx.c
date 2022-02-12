int __init am43xx_dt_clk_init(void)
{
struct clk *clk1, *clk2;
ti_dt_clocks_register(am43xx_clks);
omap2_clk_disable_autoidle_all();
clk1 = clk_get_sys(NULL, "cpsw_cpts_rft_clk");
clk2 = clk_get_sys(NULL, "dpll_core_m5_ck");
clk_set_parent(clk1, clk2);
return 0;
}
