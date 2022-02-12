static void __init genmai_add_standard_devices(void)
{
shmobile_clk_workaround(clk_names, ARRAY_SIZE(clk_names), true);
r7s72100_add_dt_devices();
of_platform_populate(NULL, of_default_bus_match_table, NULL, NULL);
}
