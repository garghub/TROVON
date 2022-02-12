static void __init imx51_dt_init(void)
{
struct platform_device_info devinfo = { .name = "cpufreq-cpu0", };
of_platform_populate(NULL, of_default_bus_match_table, NULL, NULL);
platform_device_register_full(&devinfo);
}
static void __init imx51_timer_init(void)
{
mx51_clocks_init_dt();
}
