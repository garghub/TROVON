static void __init vf610_init_machine(void)
{
mxc_arch_reset_init_dt();
of_platform_populate(NULL, of_default_bus_match_table, NULL, NULL);
}
static void __init vf610_init_irq(void)
{
l2x0_of_init(0, ~0UL);
irqchip_init();
}
static void __init vf610_init_time(void)
{
of_clk_init(NULL);
clocksource_of_init();
}
