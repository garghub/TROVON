void __init mx25_map_io(void)
{
iotable_init(mx25_io_desc, ARRAY_SIZE(mx25_io_desc));
}
void __init imx25_init_early(void)
{
mxc_set_cpu_type(MXC_CPU_MX25);
mxc_iomux_v3_init(MX25_IO_ADDRESS(MX25_IOMUXC_BASE_ADDR));
mxc_arch_reset_init(MX25_IO_ADDRESS(MX25_WDOG_BASE_ADDR));
}
void __init mx25_init_irq(void)
{
mxc_init_irq(MX25_IO_ADDRESS(MX25_AVIC_BASE_ADDR));
mxc_gpio_init(imx25_gpio_ports, ARRAY_SIZE(imx25_gpio_ports));
}
