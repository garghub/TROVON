void __init emev2_map_io(void)
{
iotable_init(emev2_io_desc, ARRAY_SIZE(emev2_io_desc));
}
void __init emev2_init_delay(void)
{
shmobile_setup_delay(533, 1, 3);
}
static void __init emev2_add_standard_devices_dt(void)
{
#ifdef CONFIG_COMMON_CLK
of_clk_init(NULL);
#else
emev2_clock_init();
#endif
of_platform_populate(NULL, of_default_bus_match_table, NULL, NULL);
}
