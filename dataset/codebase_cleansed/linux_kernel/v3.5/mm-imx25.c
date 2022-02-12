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
}
void __init imx25_soc_init(void)
{
mxc_register_gpio("imx31-gpio", 0, MX25_GPIO1_BASE_ADDR, SZ_16K, MX25_INT_GPIO1, 0);
mxc_register_gpio("imx31-gpio", 1, MX25_GPIO2_BASE_ADDR, SZ_16K, MX25_INT_GPIO2, 0);
mxc_register_gpio("imx31-gpio", 2, MX25_GPIO3_BASE_ADDR, SZ_16K, MX25_INT_GPIO3, 0);
mxc_register_gpio("imx31-gpio", 3, MX25_GPIO4_BASE_ADDR, SZ_16K, MX25_INT_GPIO4, 0);
pinctrl_provide_dummies();
imx_add_imx_sdma("imx35-sdma", MX25_SDMA_BASE_ADDR, MX25_INT_SDMA, &imx25_sdma_pdata);
platform_device_register_simple("imx31-audmux", 0, imx25_audmux_res,
ARRAY_SIZE(imx25_audmux_res));
}
