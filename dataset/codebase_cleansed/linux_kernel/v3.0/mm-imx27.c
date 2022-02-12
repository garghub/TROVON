void __init mx27_map_io(void)
{
iotable_init(imx27_io_desc, ARRAY_SIZE(imx27_io_desc));
}
void __init imx27_init_early(void)
{
mxc_set_cpu_type(MXC_CPU_MX27);
mxc_arch_reset_init(MX27_IO_ADDRESS(MX27_WDOG_BASE_ADDR));
imx_iomuxv1_init(MX27_IO_ADDRESS(MX27_GPIO_BASE_ADDR),
MX27_NUM_GPIO_PORT);
}
void __init mx27_init_irq(void)
{
mxc_init_irq(MX27_IO_ADDRESS(MX27_AVIC_BASE_ADDR));
mxc_gpio_init(imx27_gpio_ports, ARRAY_SIZE(imx27_gpio_ports));
}
