static void __init rx51_init(void)
{
struct omap_sdrc_params *sdrc_params;
omap3_mux_init(board_mux, OMAP_PACKAGE_CBB);
omap_serial_init();
sdrc_params = nokia_get_sdram_timings();
omap_sdrc_init(sdrc_params, sdrc_params);
usb_bind_phy("musb-hdrc.0.auto", 0, "twl4030_usb");
usb_musb_init(&musb_board_data);
rx51_peripherals_init();
if (omap_type() == OMAP2_DEVICE_TYPE_SEC) {
#ifdef CONFIG_ARM_ERRATA_430973
pr_info("RX-51: Enabling ARM errata 430973 workaround\n");
rx51_secure_update_aux_cr(BIT(6), 0);
#endif
}
omap_mux_init_signal("sdrc_cke0", OMAP_PIN_OUTPUT);
omap_mux_init_signal("sdrc_cke1", OMAP_PIN_OUTPUT);
platform_device_register(&leds_gpio);
}
static void __init rx51_reserve(void)
{
omap_reserve();
}
