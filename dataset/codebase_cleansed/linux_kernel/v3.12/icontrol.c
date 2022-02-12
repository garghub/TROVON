static void __init icontrol_can_init(void)
{
pxa3xx_mfp_config(ARRAY_AND_SIZE(mfp_can_cfg));
platform_add_devices(ARRAY_AND_SIZE(icontrol_spi_devices));
spi_register_board_info(ARRAY_AND_SIZE(mcp251x_board_info));
}
static void __init icontrol_init(void)
{
mxm_8x10_barebones_init();
mxm_8x10_usb_host_init();
mxm_8x10_mmc_init();
icontrol_can_init();
}
