static void __init sunxi_dt_cpufreq_init(void)
{
platform_device_register_simple("cpufreq-dt", -1, NULL, 0);
}
static void __init sun6i_timer_init(void)
{
of_clk_init(NULL);
if (IS_ENABLED(CONFIG_RESET_CONTROLLER))
sun6i_reset_init();
clocksource_of_init();
}
