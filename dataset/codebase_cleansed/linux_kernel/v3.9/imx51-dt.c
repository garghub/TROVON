static void __init imx51_dt_init(void)
{
of_platform_populate(NULL, of_default_bus_match_table, NULL, NULL);
}
static void __init imx51_timer_init(void)
{
mx51_clocks_init_dt();
}
