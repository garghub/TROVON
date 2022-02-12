int __init dm816x_dt_clk_init(void)
{
ti_dt_clocks_register(dm816x_clks);
omap2_clk_disable_autoidle_all();
omap2_clk_enable_init_clocks(enable_init_clks,
ARRAY_SIZE(enable_init_clks));
return 0;
}
