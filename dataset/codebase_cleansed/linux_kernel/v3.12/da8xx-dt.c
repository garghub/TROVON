static void __init da8xx_init_irq(void)
{
of_irq_init(da8xx_irq_match);
}
static void __init da850_init_machine(void)
{
of_platform_populate(NULL, of_default_bus_match_table,
da850_auxdata_lookup, NULL);
}
