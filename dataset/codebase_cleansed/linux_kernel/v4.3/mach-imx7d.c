static void __init imx7d_init_machine(void)
{
struct device *parent;
parent = imx_soc_device_init();
if (parent == NULL)
pr_warn("failed to initialize soc device\n");
of_platform_populate(NULL, of_default_bus_match_table, NULL, NULL);
imx_anatop_init();
}
static void __init imx7d_init_irq(void)
{
imx_init_revision_from_anatop();
imx_src_init();
irqchip_init();
}
