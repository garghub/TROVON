static int __init mxs_icoll_add_irq_domain(struct device_node *np,
struct device_node *interrupt_parent)
{
irq_domain_add_legacy(np, 128, 0, 0, &irq_domain_simple_ops, NULL);
return 0;
}
static int __init mxs_gpio_add_irq_domain(struct device_node *np,
struct device_node *interrupt_parent)
{
static int gpio_irq_base = MXS_GPIO_IRQ_START;
irq_domain_add_legacy(np, 32, gpio_irq_base, 0, &irq_domain_simple_ops, NULL);
gpio_irq_base += 32;
return 0;
}
static void __init mxs_dt_init_irq(void)
{
icoll_init_irq();
of_irq_init(mxs_irq_match);
}
static void __init imx23_timer_init(void)
{
mx23_clocks_init();
}
static void __init imx28_timer_init(void)
{
mx28_clocks_init();
}
static void __init imx28_evk_init(void)
{
struct clk *clk;
clk = clk_get_sys("enet_out", NULL);
if (!IS_ERR(clk))
clk_prepare_enable(clk);
}
static void __init mxs_machine_init(void)
{
if (of_machine_is_compatible("fsl,imx28-evk"))
imx28_evk_init();
of_platform_populate(NULL, of_default_bus_match_table,
NULL, NULL);
}
