static void __init rx51_init_early(void)
{
struct omap_sdrc_params *sdrc_params;
omap2_init_common_infrastructure();
sdrc_params = nokia_get_sdram_timings();
omap2_init_common_devices(sdrc_params, sdrc_params);
}
static void __init rx51_init(void)
{
omap3_mux_init(board_mux, OMAP_PACKAGE_CBB);
omap_board_config = rx51_config;
omap_board_config_size = ARRAY_SIZE(rx51_config);
omap3_pm_init_cpuidle(rx51_cpuidle_params);
omap_serial_init();
usb_musb_init(&musb_board_data);
rx51_peripherals_init();
omap_mux_init_signal("sdrc_cke0", OMAP_PIN_OUTPUT);
omap_mux_init_signal("sdrc_cke1", OMAP_PIN_OUTPUT);
platform_device_register(&leds_gpio);
}
static void __init rx51_map_io(void)
{
omap2_set_globals_3xxx();
omap34xx_map_common_io();
}
static void __init rx51_reserve(void)
{
rx51_video_mem_init();
omap_reserve();
}
