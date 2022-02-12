static void __init imx53_dt_init(void)
{
mxc_arch_reset_init_dt();
of_platform_populate(NULL, of_default_bus_match_table, NULL, NULL);
}
static void __init imx53_timer_init(void)
{
mx53_clocks_init_dt();
}
