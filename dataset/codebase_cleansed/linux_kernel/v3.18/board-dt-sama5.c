static void __init sama5_dt_device_init(void)
{
of_platform_populate(NULL, of_default_bus_match_table, NULL, NULL);
}
