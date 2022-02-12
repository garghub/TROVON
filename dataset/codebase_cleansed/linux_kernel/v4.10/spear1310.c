static void __init spear1310_dt_init(void)
{
platform_device_register_simple("spear-cpufreq", -1, NULL, 0);
}
static void __init spear1310_map_io(void)
{
iotable_init(spear1310_io_desc, ARRAY_SIZE(spear1310_io_desc));
spear13xx_map_io();
}
