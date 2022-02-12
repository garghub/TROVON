static void __init spear1340_dt_init(void)
{
of_platform_populate(NULL, of_default_bus_match_table, NULL, NULL);
platform_device_register_simple("spear-cpufreq", -1, NULL, 0);
}
