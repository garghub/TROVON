static void __init imx53_qsb_init(void)
{
struct clk *clk;
clk = clk_get_sys(NULL, "ssi_ext1");
if (IS_ERR(clk)) {
pr_err("failed to get clk ssi_ext1\n");
return;
}
clk_register_clkdev(clk, NULL, "0-000a");
}
static void __init imx53_dt_init(void)
{
if (of_machine_is_compatible("fsl,imx53-qsb"))
imx53_qsb_init();
of_platform_populate(NULL, of_default_bus_match_table,
imx53_auxdata_lookup, NULL);
}
static void __init imx53_timer_init(void)
{
mx53_clocks_init_dt();
}
