static void __init lager_add_standard_devices(void)
{
r8a7790_clock_init();
r8a7790_add_dt_devices();
of_platform_populate(NULL, of_default_bus_match_table, NULL, NULL);
}
