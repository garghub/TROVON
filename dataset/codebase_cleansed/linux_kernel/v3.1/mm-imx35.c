void __init mx35_map_io(void)
{
iotable_init(mx35_io_desc, ARRAY_SIZE(mx35_io_desc));
}
void __init imx35_init_early(void)
{
mxc_set_cpu_type(MXC_CPU_MX35);
mxc_iomux_v3_init(MX35_IO_ADDRESS(MX35_IOMUXC_BASE_ADDR));
mxc_arch_reset_init(MX35_IO_ADDRESS(MX35_WDOG_BASE_ADDR));
}
void __init mx35_init_irq(void)
{
mxc_init_irq(MX35_IO_ADDRESS(MX35_AVIC_BASE_ADDR));
}
void __init imx35_soc_init(void)
{
int to_version = mx35_revision() >> 4;
mxc_register_gpio("imx31-gpio", 0, MX35_GPIO1_BASE_ADDR, SZ_16K, MX35_INT_GPIO1, 0);
mxc_register_gpio("imx31-gpio", 1, MX35_GPIO2_BASE_ADDR, SZ_16K, MX35_INT_GPIO2, 0);
mxc_register_gpio("imx31-gpio", 2, MX35_GPIO3_BASE_ADDR, SZ_16K, MX35_INT_GPIO3, 0);
if (to_version == 1) {
strncpy(imx35_sdma_pdata.fw_name, "sdma-imx35-to1.bin",
strlen(imx35_sdma_pdata.fw_name));
imx35_sdma_pdata.script_addrs = &imx35_to1_sdma_script;
}
imx_add_imx_sdma("imx35-sdma", MX35_SDMA_BASE_ADDR, MX35_INT_SDMA, &imx35_sdma_pdata);
}
