int __init am33xx_dt_clk_init(void)
{
struct clk *clk1, *clk2;
ti_dt_clocks_register(am33xx_clks);
omap2_clk_disable_autoidle_all();
omap2_clk_enable_init_clocks(enable_init_clks,
ARRAY_SIZE(enable_init_clks));
clk1 = clk_get_sys(NULL, "sys_clkin_ck");
clk2 = clk_get_sys(NULL, "timer3_fck");
clk_set_parent(clk2, clk1);
clk2 = clk_get_sys(NULL, "timer6_fck");
clk_set_parent(clk2, clk1);
clk1 = clk_get_sys(NULL, "wdt1_fck");
clk2 = clk_get_sys(NULL, "clkdiv32k_ick");
clk_set_parent(clk1, clk2);
return 0;
}
