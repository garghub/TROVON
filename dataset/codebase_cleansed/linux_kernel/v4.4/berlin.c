static void __init berlin_init_late(void)
{
platform_device_register_simple("cpufreq-dt", -1, NULL, 0);
}
