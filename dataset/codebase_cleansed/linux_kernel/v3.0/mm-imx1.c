void __init mx1_map_io(void)
{
iotable_init(imx_io_desc, ARRAY_SIZE(imx_io_desc));
}
void __init imx1_init_early(void)
{
mxc_set_cpu_type(MXC_CPU_MX1);
mxc_arch_reset_init(MX1_IO_ADDRESS(MX1_WDT_BASE_ADDR));
imx_iomuxv1_init(MX1_IO_ADDRESS(MX1_GPIO_BASE_ADDR),
MX1_NUM_GPIO_PORT);
}
void __init mx1_init_irq(void)
{
mxc_init_irq(MX1_IO_ADDRESS(MX1_AVIC_BASE_ADDR));
mxc_gpio_init(imx1_gpio_ports, ARRAY_SIZE(imx1_gpio_ports));
}
