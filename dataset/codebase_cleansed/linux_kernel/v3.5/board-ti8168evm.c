static void __init ti81xx_evm_init(void)
{
omap_serial_init();
omap_sdrc_init(NULL, NULL);
omap_board_config = ti81xx_evm_config;
omap_board_config_size = ARRAY_SIZE(ti81xx_evm_config);
usb_musb_init(&musb_board_data);
}
