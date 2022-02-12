static void __init rx51_init(void)
{
struct omap_sdrc_params *sdrc_params;
omap3_mux_init(board_mux, OMAP_PACKAGE_CBB);
omap3_pm_init_cpuidle(rx51_cpuidle_params);
omap_serial_init();
sdrc_params = nokia_get_sdram_timings();
omap_sdrc_init(sdrc_params, sdrc_params);
usb_musb_init(&musb_board_data);
rx51_peripherals_init();
omap_mux_init_signal("sdrc_cke0", OMAP_PIN_OUTPUT);
omap_mux_init_signal("sdrc_cke1", OMAP_PIN_OUTPUT);
platform_device_register(&leds_gpio);
}
static void __init rx51_reserve(void)
{
rx51_video_mem_init();
omap_reserve();
}
