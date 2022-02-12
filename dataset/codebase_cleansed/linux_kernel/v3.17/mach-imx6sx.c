static void __init imx6sx_init_machine(void)
{
struct device *parent;
mxc_arch_reset_init_dt();
parent = imx_soc_device_init();
if (parent == NULL)
pr_warn("failed to initialize soc device\n");
of_platform_populate(NULL, of_default_bus_match_table, NULL, parent);
imx_anatop_init();
imx6sx_pm_init();
}
static void __init imx6sx_init_irq(void)
{
imx_init_revision_from_anatop();
imx_init_l2cache();
imx_src_init();
imx_gpc_init();
irqchip_init();
}
static void __init imx6sx_init_late(void)
{
imx6q_cpuidle_init();
}
