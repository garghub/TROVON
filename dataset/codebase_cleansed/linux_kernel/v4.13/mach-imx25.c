static void __init imx25_init_early(void)
{
mxc_set_cpu_type(MXC_CPU_MX25);
}
static void __init imx25_dt_init(void)
{
imx_aips_allow_unprivileged_access("fsl,imx25-aips");
}
static void __init mx25_init_irq(void)
{
struct device_node *np;
void __iomem *avic_base;
np = of_find_compatible_node(NULL, NULL, "fsl,avic");
avic_base = of_iomap(np, 0);
BUG_ON(!avic_base);
mxc_init_irq(avic_base);
}
