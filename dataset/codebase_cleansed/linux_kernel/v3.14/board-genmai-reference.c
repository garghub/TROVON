static void __init genmai_add_standard_devices(void)
{
#ifdef CONFIG_COMMON_CLK
of_clk_init(NULL);
#else
r7s72100_clock_init();
#endif
r7s72100_add_dt_devices();
of_platform_populate(NULL, of_default_bus_match_table, NULL, NULL);
}
