static void __init imx27_dt_init(void)
{
of_platform_populate(NULL, of_default_bus_match_table,
imx27_auxdata_lookup, NULL);
}
static void __init imx27_timer_init(void)
{
mx27_clocks_init_dt();
}
