static void __init imx27_dt_init(void)
{
struct platform_device_info devinfo = { .name = "cpufreq-cpu0", };
mxc_arch_reset_init_dt();
of_platform_populate(NULL, of_default_bus_match_table, NULL, NULL);
platform_device_register_full(&devinfo);
}
static void __init imx27_timer_init(void)
{
mx27_clocks_init_dt();
}
