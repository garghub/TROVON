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
}
void __init imx27_soc_init(void)
{
mxc_register_gpio("imx21-gpio", 0, MX27_GPIO1_BASE_ADDR, SZ_256, MX27_INT_GPIO, 0);
mxc_register_gpio("imx21-gpio", 1, MX27_GPIO2_BASE_ADDR, SZ_256, MX27_INT_GPIO, 0);
mxc_register_gpio("imx21-gpio", 2, MX27_GPIO3_BASE_ADDR, SZ_256, MX27_INT_GPIO, 0);
mxc_register_gpio("imx21-gpio", 3, MX27_GPIO4_BASE_ADDR, SZ_256, MX27_INT_GPIO, 0);
mxc_register_gpio("imx21-gpio", 4, MX27_GPIO5_BASE_ADDR, SZ_256, MX27_INT_GPIO, 0);
mxc_register_gpio("imx21-gpio", 5, MX27_GPIO6_BASE_ADDR, SZ_256, MX27_INT_GPIO, 0);
imx_add_imx_dma();
platform_device_register_simple("imx21-audmux", 0, imx27_audmux_res,
ARRAY_SIZE(imx27_audmux_res));
}
