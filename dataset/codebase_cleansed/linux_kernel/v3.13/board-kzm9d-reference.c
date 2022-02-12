static void __init kzm9d_add_standard_devices(void)
{
if (!IS_ENABLED(CONFIG_COMMON_CLK))
emev2_clock_init();
of_platform_populate(NULL, of_default_bus_match_table, NULL, NULL);
}
