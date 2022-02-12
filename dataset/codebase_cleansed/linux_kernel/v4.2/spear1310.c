static void __init spear1310_dt_init(void)
{
of_platform_populate(NULL, of_default_bus_match_table, NULL, NULL);
platform_device_register_simple("spear-cpufreq", -1, NULL, 0);
}
static void __init spear1310_map_io(void)
{
iotable_init(spear1310_io_desc, ARRAY_SIZE(spear1310_io_desc));
spear13xx_map_io();
}
