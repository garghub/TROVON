static void __init imx25_dt_init(void)
{
of_platform_populate(NULL, of_default_bus_match_table, NULL, NULL);
}
static void __init imx25_timer_init(void)
{
mx25_clocks_init_dt();
}
