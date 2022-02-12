static void __init board_smc91x_init(void)
{
omap_mux_init_gpio(149, OMAP_PIN_INPUT);
gpmc_smc91x_init(&board_smc91x_data);
}
static inline void board_smc91x_init(void)
{
}
static int __init omap2430_i2c_init(void)
{
sdp2430_i2c1_boardinfo[0].irq = gpio_to_irq(78);
omap_register_i2c_bus(1, 100, sdp2430_i2c1_boardinfo,
ARRAY_SIZE(sdp2430_i2c1_boardinfo));
omap_pmic_init(2, 100, "twl4030", 7 + OMAP_INTC_START,
&sdp2430_twldata);
return 0;
}
static void __init omap_2430sdp_init(void)
{
omap2430_mux_init(board_mux, OMAP_PACKAGE_ZAC);
omap2430_i2c_init();
platform_add_devices(sdp2430_devices, ARRAY_SIZE(sdp2430_devices));
omap_serial_init();
omap_sdrc_init(NULL, NULL);
omap_hsmmc_init(mmc);
omap_mux_init_signal("usb0hs_stp", OMAP_PULL_ENA | OMAP_PULL_UP);
usb_bind_phy("musb-hdrc.0.auto", 0, "twl4030_usb");
usb_musb_init(NULL);
board_smc91x_init();
gpio_request_one(SECONDARY_LCD_GPIO, GPIOF_OUT_INIT_LOW,
"Secondary LCD backlight");
omap_display_init(&sdp2430_dss_data);
}
