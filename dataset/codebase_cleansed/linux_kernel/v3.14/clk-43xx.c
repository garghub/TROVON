int __init am43xx_dt_clk_init(void)
{
ti_dt_clocks_register(am43xx_clks);
omap2_clk_disable_autoidle_all();
return 0;
}
