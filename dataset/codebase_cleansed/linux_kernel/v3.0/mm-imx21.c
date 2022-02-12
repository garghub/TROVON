void __init mx21_map_io(void)
{
iotable_init(imx21_io_desc, ARRAY_SIZE(imx21_io_desc));
}
void __init imx21_init_early(void)
{
mxc_set_cpu_type(MXC_CPU_MX21);
mxc_arch_reset_init(MX21_IO_ADDRESS(MX21_WDOG_BASE_ADDR));
imx_iomuxv1_init(MX21_IO_ADDRESS(MX21_GPIO_BASE_ADDR),
MX21_NUM_GPIO_PORT);
}
void __init mx21_init_irq(void)
{
mxc_init_irq(MX21_IO_ADDRESS(MX21_AVIC_BASE_ADDR));
mxc_gpio_init(imx21_gpio_ports, ARRAY_SIZE(imx21_gpio_ports));
}
