void __init mx51_map_io(void)
{
iotable_init(mx51_io_desc, ARRAY_SIZE(mx51_io_desc));
}
void __init mx53_map_io(void)
{
iotable_init(mx53_io_desc, ARRAY_SIZE(mx53_io_desc));
}
static void __init imx51_ipu_mipi_setup(void)
{
void __iomem *hsc_addr;
hsc_addr = MX51_IO_ADDRESS(MX51_MIPI_HSC_BASE_ADDR);
__raw_writel(0xf00, hsc_addr);
__raw_writel(__raw_readl(hsc_addr + 0x800) | 0x30ff,
hsc_addr + 0x800);
}
void __init imx51_init_early(void)
{
imx51_ipu_mipi_setup();
mxc_set_cpu_type(MXC_CPU_MX51);
mxc_iomux_v3_init(MX51_IO_ADDRESS(MX51_IOMUXC_BASE_ADDR));
mxc_arch_reset_init(MX51_IO_ADDRESS(MX51_WDOG1_BASE_ADDR));
}
void __init imx53_init_early(void)
{
mxc_set_cpu_type(MXC_CPU_MX53);
mxc_iomux_v3_init(MX53_IO_ADDRESS(MX53_IOMUXC_BASE_ADDR));
mxc_arch_reset_init(MX53_IO_ADDRESS(MX53_WDOG1_BASE_ADDR));
}
void __init mx51_init_irq(void)
{
tzic_init_irq(MX51_IO_ADDRESS(MX51_TZIC_BASE_ADDR));
}
void __init mx53_init_irq(void)
{
tzic_init_irq(MX53_IO_ADDRESS(MX53_TZIC_BASE_ADDR));
}
void __init imx51_soc_init(void)
{
mxc_device_init();
mxc_register_gpio("imx35-gpio", 0, MX51_GPIO1_BASE_ADDR, SZ_16K, MX51_INT_GPIO1_LOW, MX51_INT_GPIO1_HIGH);
mxc_register_gpio("imx35-gpio", 1, MX51_GPIO2_BASE_ADDR, SZ_16K, MX51_INT_GPIO2_LOW, MX51_INT_GPIO2_HIGH);
mxc_register_gpio("imx35-gpio", 2, MX51_GPIO3_BASE_ADDR, SZ_16K, MX51_INT_GPIO3_LOW, MX51_INT_GPIO3_HIGH);
mxc_register_gpio("imx35-gpio", 3, MX51_GPIO4_BASE_ADDR, SZ_16K, MX51_INT_GPIO4_LOW, MX51_INT_GPIO4_HIGH);
pinctrl_provide_dummies();
imx_add_imx_sdma("imx35-sdma", MX51_SDMA_BASE_ADDR, MX51_INT_SDMA, &imx51_sdma_pdata);
imx_set_aips(MX51_IO_ADDRESS(MX51_AIPS1_BASE_ADDR));
imx_set_aips(MX51_IO_ADDRESS(MX51_AIPS2_BASE_ADDR));
platform_device_register_simple("imx31-audmux", 0, imx51_audmux_res,
ARRAY_SIZE(imx51_audmux_res));
}
void __init imx51_init_late(void)
{
mx51_neon_fixup();
imx51_pm_init();
}
void __init imx53_init_late(void)
{
imx53_pm_init();
}
