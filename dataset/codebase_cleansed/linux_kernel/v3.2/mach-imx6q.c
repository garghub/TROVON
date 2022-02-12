static void __init imx6q_init_machine(void)
{
of_platform_populate(NULL, of_default_bus_match_table, NULL, NULL);
imx6q_pm_init();
}
static void __init imx6q_map_io(void)
{
imx_lluart_map_io();
imx_scu_map_io();
imx6q_clock_map_io();
}
static int __init imx6q_gpio_add_irq_domain(struct device_node *np,
struct device_node *interrupt_parent)
{
static int gpio_irq_base = MXC_GPIO_IRQ_START + ARCH_NR_GPIOS;
gpio_irq_base -= 32;
irq_domain_add_simple(np, gpio_irq_base);
return 0;
}
static void __init imx6q_init_irq(void)
{
l2x0_of_init(0, ~0UL);
imx_src_init();
imx_gpc_init();
of_irq_init(imx6q_irq_match);
}
static void __init imx6q_timer_init(void)
{
mx6q_clocks_init();
}
