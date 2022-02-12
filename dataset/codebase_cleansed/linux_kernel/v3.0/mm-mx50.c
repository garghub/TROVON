void __init mx50_map_io(void)
{
iotable_init(mx50_io_desc, ARRAY_SIZE(mx50_io_desc));
}
void __init imx50_init_early(void)
{
mxc_set_cpu_type(MXC_CPU_MX50);
mxc_iomux_v3_init(MX50_IO_ADDRESS(MX50_IOMUXC_BASE_ADDR));
mxc_arch_reset_init(MX50_IO_ADDRESS(MX50_WDOG_BASE_ADDR));
}
void __init mx50_init_irq(void)
{
tzic_init_irq(MX50_IO_ADDRESS(MX50_TZIC_BASE_ADDR));
mxc_gpio_init(imx50_gpio_ports, ARRAY_SIZE(imx50_gpio_ports));
}
