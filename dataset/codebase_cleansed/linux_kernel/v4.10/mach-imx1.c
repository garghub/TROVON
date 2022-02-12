static void __init imx1_init_early(void)
{
mxc_set_cpu_type(MXC_CPU_MX1);
}
static void __init imx1_init_irq(void)
{
void __iomem *avic_addr;
avic_addr = ioremap(MX1_AVIC_ADDR, SZ_4K);
WARN_ON(!avic_addr);
mxc_init_irq(avic_addr);
}
