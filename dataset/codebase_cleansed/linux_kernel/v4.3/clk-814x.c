int __init dm814x_dt_clk_init(void)
{
ti_dt_clocks_register(dm814_clks);
omap2_clk_disable_autoidle_all();
omap2_clk_enable_init_clocks(NULL, 0);
return 0;
}
