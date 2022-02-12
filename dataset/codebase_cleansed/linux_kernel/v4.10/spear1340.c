static void __init spear1340_dt_init(void)
{
platform_device_register_simple("spear-cpufreq", -1, NULL, 0);
}
