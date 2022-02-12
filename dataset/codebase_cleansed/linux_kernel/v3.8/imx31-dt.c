static void __init imx31_dt_init(void)
{
of_platform_populate(NULL, of_default_bus_match_table,
imx31_auxdata_lookup, NULL);
}
static void __init imx31_timer_init(void)
{
mx31_clocks_init_dt();
}
