int __init am33xx_clk_init(void)
{
if (soc_is_am33xx())
cpu_mask = RATE_IN_AM33XX;
omap_clocks_register(am33xx_clks, ARRAY_SIZE(am33xx_clks));
omap2_clk_disable_autoidle_all();
omap2_clk_enable_init_clocks(enable_init_clks,
ARRAY_SIZE(enable_init_clks));
clk_set_parent(&timer3_fck, &sys_clkin_ck);
clk_set_parent(&timer6_fck, &sys_clkin_ck);
clk_set_parent(&wdt1_fck, &clkdiv32k_ick);
return 0;
}
