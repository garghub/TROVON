void __init mx31_map_io(void)
{
iotable_init(mx31_io_desc, ARRAY_SIZE(mx31_io_desc));
}
void __init imx31_init_early(void)
{
mxc_set_cpu_type(MXC_CPU_MX31);
mxc_arch_reset_init(MX31_IO_ADDRESS(MX31_WDOG_BASE_ADDR));
}
void __init mx31_init_irq(void)
{
mxc_init_irq(MX31_IO_ADDRESS(MX31_AVIC_BASE_ADDR));
}
void __init imx31_soc_init(void)
{
int to_version = mx31_revision() >> 4;
mxc_register_gpio("imx31-gpio", 0, MX31_GPIO1_BASE_ADDR, SZ_16K, MX31_INT_GPIO1, 0);
mxc_register_gpio("imx31-gpio", 1, MX31_GPIO2_BASE_ADDR, SZ_16K, MX31_INT_GPIO2, 0);
mxc_register_gpio("imx31-gpio", 2, MX31_GPIO3_BASE_ADDR, SZ_16K, MX31_INT_GPIO3, 0);
if (to_version == 1) {
strncpy(imx31_sdma_pdata.fw_name, "sdma-imx31-to1.bin",
strlen(imx31_sdma_pdata.fw_name));
imx31_sdma_pdata.script_addrs = &imx31_to1_sdma_script;
}
imx_add_imx_sdma("imx31-sdma", MX31_SDMA_BASE_ADDR, MX31_INT_SDMA, &imx31_sdma_pdata);
}
