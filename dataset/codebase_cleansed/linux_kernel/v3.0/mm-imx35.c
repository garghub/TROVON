void __init mx35_map_io(void)
{
iotable_init(mx35_io_desc, ARRAY_SIZE(mx35_io_desc));
}
void __init imx35_init_early(void)
{
mxc_set_cpu_type(MXC_CPU_MX35);
mxc_iomux_v3_init(MX35_IO_ADDRESS(MX35_IOMUXC_BASE_ADDR));
mxc_arch_reset_init(MX35_IO_ADDRESS(MX35_WDOG_BASE_ADDR));
}
void __init mx35_init_irq(void)
{
mxc_init_irq(MX35_IO_ADDRESS(MX35_AVIC_BASE_ADDR));
mxc_gpio_init(imx35_gpio_ports, ARRAY_SIZE(imx35_gpio_ports));
}
