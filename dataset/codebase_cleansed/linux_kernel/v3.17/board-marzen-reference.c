static void __init marzen_init_timer(void)
{
r8a7779_clocks_init(r8a7779_read_mode_pins());
clocksource_of_init();
}
static void __init marzen_init(void)
{
shmobile_clk_workaround(clk_names, ARRAY_SIZE(clk_names), false);
r8a7779_add_standard_devices_dt();
of_platform_populate(NULL, of_default_bus_match_table, NULL, NULL);
r8a7779_init_irq_extpin_dt(1);
}
