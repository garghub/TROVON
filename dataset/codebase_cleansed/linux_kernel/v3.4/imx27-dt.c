static int __init imx27_avic_add_irq_domain(struct device_node *np,
struct device_node *interrupt_parent)
{
irq_domain_add_legacy(np, 64, 0, 0, &irq_domain_simple_ops, NULL);
return 0;
}
static int __init imx27_gpio_add_irq_domain(struct device_node *np,
struct device_node *interrupt_parent)
{
static int gpio_irq_base = MXC_GPIO_IRQ_START + ARCH_NR_GPIOS;
gpio_irq_base -= 32;
irq_domain_add_legacy(np, 32, gpio_irq_base, 0, &irq_domain_simple_ops,
NULL);
return 0;
}
static void __init imx27_dt_init(void)
{
of_irq_init(imx27_irq_match);
of_platform_populate(NULL, of_default_bus_match_table,
imx27_auxdata_lookup, NULL);
}
static void __init imx27_timer_init(void)
{
mx27_clocks_init_dt();
}
