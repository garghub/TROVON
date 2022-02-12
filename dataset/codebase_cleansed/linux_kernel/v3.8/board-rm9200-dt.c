static void __init at91rm9200_dt_init_irq(void)
{
of_irq_init(irq_of_match);
}
static void __init at91rm9200_dt_device_init(void)
{
of_platform_populate(NULL, of_default_bus_match_table, NULL, NULL);
}
