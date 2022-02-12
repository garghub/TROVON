static int __init imx51_tzic_add_irq_domain(struct device_node *np,
struct device_node *interrupt_parent)
{
irq_domain_add_legacy(np, 128, 0, 0, &irq_domain_simple_ops, NULL);
return 0;
}
static int __init imx51_gpio_add_irq_domain(struct device_node *np,
struct device_node *interrupt_parent)
{
static int gpio_irq_base = MXC_GPIO_IRQ_START + ARCH_NR_GPIOS;
gpio_irq_base -= 32;
irq_domain_add_legacy(np, 32, gpio_irq_base, 0, &irq_domain_simple_ops, NULL);
return 0;
}
static void __init imx51_dt_init(void)
{
struct device_node *node;
const struct of_device_id *of_id;
void (*func)(void);
of_irq_init(imx51_irq_match);
pinctrl_provide_dummies();
node = of_find_matching_node(NULL, imx51_iomuxc_of_match);
if (node) {
of_id = of_match_node(imx51_iomuxc_of_match, node);
func = of_id->data;
func();
of_node_put(node);
}
of_platform_populate(NULL, of_default_bus_match_table,
imx51_auxdata_lookup, NULL);
}
static void __init imx51_timer_init(void)
{
mx51_clocks_init_dt();
}
