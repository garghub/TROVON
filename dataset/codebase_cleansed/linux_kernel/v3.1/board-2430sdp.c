static void __init board_smc91x_init(void)
{
omap_mux_init_gpio(149, OMAP_PIN_INPUT);
gpmc_smc91x_init(&board_smc91x_data);
}
static inline void board_smc91x_init(void)
{
}
static void __init omap_2430sdp_init_early(void)
{
omap2_init_common_infrastructure();
omap2_init_common_devices(NULL, NULL);
}
static int __init omap2430_i2c_init(void)
{
omap_register_i2c_bus(1, 100, sdp2430_i2c1_boardinfo,
ARRAY_SIZE(sdp2430_i2c1_boardinfo));
omap_pmic_init(2, 100, "twl4030", INT_24XX_SYS_NIRQ,
&sdp2430_twldata);
return 0;
}
static void __init omap_2430sdp_init(void)
{
omap2430_mux_init(board_mux, OMAP_PACKAGE_ZAC);
omap_board_config = sdp2430_config;
omap_board_config_size = ARRAY_SIZE(sdp2430_config);
omap2430_i2c_init();
platform_add_devices(sdp2430_devices, ARRAY_SIZE(sdp2430_devices));
omap_serial_init();
omap2_hsmmc_init(mmc);
omap2_usbfs_init(&sdp2430_usb_config);
omap_mux_init_signal("usb0hs_stp", OMAP_PULL_ENA | OMAP_PULL_UP);
usb_musb_init(NULL);
board_smc91x_init();
gpio_request_one(SECONDARY_LCD_GPIO, GPIOF_OUT_INIT_LOW,
"Secondary LCD backlight");
}
static void __init omap_2430sdp_map_io(void)
{
omap2_set_globals_243x();
omap243x_map_common_io();
}
