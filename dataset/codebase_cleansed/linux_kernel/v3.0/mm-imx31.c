void __init mx31_map_io(void)
{
iotable_init(mx31_io_desc, ARRAY_SIZE(mx31_io_desc));
}
void __init imx31_init_early(void)
{
mxc_set_cpu_type(MXC_CPU_MX31);
mxc_arch_reset_init(MX31_IO_ADDRESS(MX31_WDOG_BASE_ADDR));
}
void __init mx31_init_irq(void)
{
mxc_init_irq(MX31_IO_ADDRESS(MX31_AVIC_BASE_ADDR));
mxc_gpio_init(imx31_gpio_ports, ARRAY_SIZE(imx31_gpio_ports));
}
