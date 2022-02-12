static void imx5_idle(void)
{
if (gpc_dvfs_clk == NULL) {
gpc_dvfs_clk = clk_get(NULL, "gpc_dvfs");
if (IS_ERR(gpc_dvfs_clk))
return;
clk_prepare(gpc_dvfs_clk);
}
clk_enable(gpc_dvfs_clk);
mx5_cpu_lp_set(WAIT_UNCLOCKED_POWER_OFF);
if (!tzic_enable_wake())
cpu_do_idle();
clk_disable(gpc_dvfs_clk);
}
void __init mx50_map_io(void)
{
iotable_init(mx50_io_desc, ARRAY_SIZE(mx50_io_desc));
}
void __init mx51_map_io(void)
{
iotable_init(mx51_io_desc, ARRAY_SIZE(mx51_io_desc));
}
void __init mx53_map_io(void)
{
iotable_init(mx53_io_desc, ARRAY_SIZE(mx53_io_desc));
}
void __init imx50_init_early(void)
{
mxc_set_cpu_type(MXC_CPU_MX50);
mxc_iomux_v3_init(MX50_IO_ADDRESS(MX50_IOMUXC_BASE_ADDR));
mxc_arch_reset_init(MX50_IO_ADDRESS(MX50_WDOG_BASE_ADDR));
}
void __init imx51_init_early(void)
{
mxc_set_cpu_type(MXC_CPU_MX51);
mxc_iomux_v3_init(MX51_IO_ADDRESS(MX51_IOMUXC_BASE_ADDR));
mxc_arch_reset_init(MX51_IO_ADDRESS(MX51_WDOG1_BASE_ADDR));
arm_pm_idle = imx5_idle;
}
void __init imx53_init_early(void)
{
mxc_set_cpu_type(MXC_CPU_MX53);
mxc_iomux_v3_init(MX53_IO_ADDRESS(MX53_IOMUXC_BASE_ADDR));
mxc_arch_reset_init(MX53_IO_ADDRESS(MX53_WDOG1_BASE_ADDR));
}
void __init mx50_init_irq(void)
{
tzic_init_irq(MX50_IO_ADDRESS(MX50_TZIC_BASE_ADDR));
}
void __init mx51_init_irq(void)
{
tzic_init_irq(MX51_IO_ADDRESS(MX51_TZIC_BASE_ADDR));
}
void __init mx53_init_irq(void)
{
tzic_init_irq(MX53_IO_ADDRESS(MX53_TZIC_BASE_ADDR));
}
void __init imx50_soc_init(void)
{
mxc_register_gpio("imx31-gpio", 0, MX50_GPIO1_BASE_ADDR, SZ_16K, MX50_INT_GPIO1_LOW, MX50_INT_GPIO1_HIGH);
mxc_register_gpio("imx31-gpio", 1, MX50_GPIO2_BASE_ADDR, SZ_16K, MX50_INT_GPIO2_LOW, MX50_INT_GPIO2_HIGH);
mxc_register_gpio("imx31-gpio", 2, MX50_GPIO3_BASE_ADDR, SZ_16K, MX50_INT_GPIO3_LOW, MX50_INT_GPIO3_HIGH);
mxc_register_gpio("imx31-gpio", 3, MX50_GPIO4_BASE_ADDR, SZ_16K, MX50_INT_GPIO4_LOW, MX50_INT_GPIO4_HIGH);
mxc_register_gpio("imx31-gpio", 4, MX50_GPIO5_BASE_ADDR, SZ_16K, MX50_INT_GPIO5_LOW, MX50_INT_GPIO5_HIGH);
mxc_register_gpio("imx31-gpio", 5, MX50_GPIO6_BASE_ADDR, SZ_16K, MX50_INT_GPIO6_LOW, MX50_INT_GPIO6_HIGH);
platform_device_register_simple("imx31-audmux", 0, imx50_audmux_res,
ARRAY_SIZE(imx50_audmux_res));
}
void __init imx51_soc_init(void)
{
mxc_register_gpio("imx31-gpio", 0, MX51_GPIO1_BASE_ADDR, SZ_16K, MX51_INT_GPIO1_LOW, MX51_INT_GPIO1_HIGH);
mxc_register_gpio("imx31-gpio", 1, MX51_GPIO2_BASE_ADDR, SZ_16K, MX51_INT_GPIO2_LOW, MX51_INT_GPIO2_HIGH);
mxc_register_gpio("imx31-gpio", 2, MX51_GPIO3_BASE_ADDR, SZ_16K, MX51_INT_GPIO3_LOW, MX51_INT_GPIO3_HIGH);
mxc_register_gpio("imx31-gpio", 3, MX51_GPIO4_BASE_ADDR, SZ_16K, MX51_INT_GPIO4_LOW, MX51_INT_GPIO4_HIGH);
pinctrl_provide_dummies();
imx_add_imx_sdma("imx35-sdma", MX51_SDMA_BASE_ADDR, MX51_INT_SDMA, &imx51_sdma_pdata);
imx_set_aips(MX51_IO_ADDRESS(MX51_AIPS1_BASE_ADDR));
imx_set_aips(MX51_IO_ADDRESS(MX51_AIPS2_BASE_ADDR));
platform_device_register_simple("imx31-audmux", 0, imx51_audmux_res,
ARRAY_SIZE(imx51_audmux_res));
}
void __init imx53_soc_init(void)
{
mxc_register_gpio("imx31-gpio", 0, MX53_GPIO1_BASE_ADDR, SZ_16K, MX53_INT_GPIO1_LOW, MX53_INT_GPIO1_HIGH);
mxc_register_gpio("imx31-gpio", 1, MX53_GPIO2_BASE_ADDR, SZ_16K, MX53_INT_GPIO2_LOW, MX53_INT_GPIO2_HIGH);
mxc_register_gpio("imx31-gpio", 2, MX53_GPIO3_BASE_ADDR, SZ_16K, MX53_INT_GPIO3_LOW, MX53_INT_GPIO3_HIGH);
mxc_register_gpio("imx31-gpio", 3, MX53_GPIO4_BASE_ADDR, SZ_16K, MX53_INT_GPIO4_LOW, MX53_INT_GPIO4_HIGH);
mxc_register_gpio("imx31-gpio", 4, MX53_GPIO5_BASE_ADDR, SZ_16K, MX53_INT_GPIO5_LOW, MX53_INT_GPIO5_HIGH);
mxc_register_gpio("imx31-gpio", 5, MX53_GPIO6_BASE_ADDR, SZ_16K, MX53_INT_GPIO6_LOW, MX53_INT_GPIO6_HIGH);
mxc_register_gpio("imx31-gpio", 6, MX53_GPIO7_BASE_ADDR, SZ_16K, MX53_INT_GPIO7_LOW, MX53_INT_GPIO7_HIGH);
pinctrl_provide_dummies();
imx_add_imx_sdma("imx35-sdma", MX53_SDMA_BASE_ADDR, MX53_INT_SDMA, &imx53_sdma_pdata);
imx_set_aips(MX53_IO_ADDRESS(MX53_AIPS1_BASE_ADDR));
imx_set_aips(MX53_IO_ADDRESS(MX53_AIPS2_BASE_ADDR));
platform_device_register_simple("imx31-audmux", 0, imx53_audmux_res,
ARRAY_SIZE(imx53_audmux_res));
}
void __init imx51_init_late(void)
{
mx51_neon_fixup();
}
