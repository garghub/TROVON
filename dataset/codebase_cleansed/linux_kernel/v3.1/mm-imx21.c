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
}
void __init imx21_soc_init(void)
{
mxc_register_gpio("imx21-gpio", 0, MX21_GPIO1_BASE_ADDR, SZ_256, MX21_INT_GPIO, 0);
mxc_register_gpio("imx21-gpio", 1, MX21_GPIO2_BASE_ADDR, SZ_256, MX21_INT_GPIO, 0);
mxc_register_gpio("imx21-gpio", 2, MX21_GPIO3_BASE_ADDR, SZ_256, MX21_INT_GPIO, 0);
mxc_register_gpio("imx21-gpio", 3, MX21_GPIO4_BASE_ADDR, SZ_256, MX21_INT_GPIO, 0);
mxc_register_gpio("imx21-gpio", 4, MX21_GPIO5_BASE_ADDR, SZ_256, MX21_INT_GPIO, 0);
mxc_register_gpio("imx21-gpio", 5, MX21_GPIO6_BASE_ADDR, SZ_256, MX21_INT_GPIO, 0);
imx_add_imx_dma();
}
