static void __init gic_init_irq(void)
{
of_irq_init(irq_match);
}
static void socfpga_cyclone5_restart(char mode, const char *cmd)
{
}
static void __init socfpga_cyclone5_init(void)
{
l2x0_of_init(0, ~0UL);
of_platform_populate(NULL, of_default_bus_match_table, NULL, NULL);
socfpga_init_clocks();
}
