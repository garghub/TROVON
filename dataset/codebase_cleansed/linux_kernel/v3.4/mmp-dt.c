static int __init mmp_intc_add_irq_domain(struct device_node *np,
struct device_node *parent)
{
irq_domain_add_simple(np, 0);
return 0;
}
static int __init mmp_gpio_add_irq_domain(struct device_node *np,
struct device_node *parent)
{
irq_domain_add_simple(np, IRQ_GPIO_START);
return 0;
}
static void __init mmp_dt_init(void)
{
of_irq_init(mmp_irq_match);
of_platform_populate(NULL, of_default_bus_match_table,
mmp_auxdata_lookup, NULL);
}
