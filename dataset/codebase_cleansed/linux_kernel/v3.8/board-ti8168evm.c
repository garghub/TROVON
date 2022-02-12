static void __init ti81xx_evm_init(void)
{
omap_serial_init();
omap_sdrc_init(NULL, NULL);
usb_musb_init(&musb_board_data);
}
