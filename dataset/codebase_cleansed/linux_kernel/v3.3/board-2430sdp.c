static int sdp2430_panel_enable_lcd(struct omap_dss_device *dssdev)
{
gpio_direction_output(SDP2430_LCD_PANEL_ENABLE_GPIO, 1);
gpio_direction_output(SDP2430_LCD_PANEL_BACKLIGHT_GPIO, 1);
return 0;
}
static void sdp2430_panel_disable_lcd(struct omap_dss_device *dssdev)
{
gpio_direction_output(SDP2430_LCD_PANEL_ENABLE_GPIO, 0);
gpio_direction_output(SDP2430_LCD_PANEL_BACKLIGHT_GPIO, 0);
}
static void __init sdp2430_display_init(void)
{
int r;
static struct gpio gpios[] __initdata = {
{ SDP2430_LCD_PANEL_ENABLE_GPIO, GPIOF_OUT_INIT_LOW,
"LCD reset" },
{ SDP2430_LCD_PANEL_BACKLIGHT_GPIO, GPIOF_OUT_INIT_LOW,
"LCD Backlight" },
};
r = gpio_request_array(gpios, ARRAY_SIZE(gpios));
if (r) {
pr_err("Cannot request LCD GPIOs, error %d\n", r);
return;
}
omap_display_init(&sdp2430_dss_data);
}
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
omap_register_i2c_bus(1, 100, sdp2430_i2c1_boardinfo,
ARRAY_SIZE(sdp2430_i2c1_boardinfo));
omap_pmic_init(2, 100, "twl4030", INT_24XX_SYS_NIRQ,
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
omap2_hsmmc_init(mmc);
omap2_usbfs_init(&sdp2430_usb_config);
omap_mux_init_signal("usb0hs_stp", OMAP_PULL_ENA | OMAP_PULL_UP);
usb_musb_init(NULL);
board_smc91x_init();
gpio_request_one(SECONDARY_LCD_GPIO, GPIOF_OUT_INIT_LOW,
"Secondary LCD backlight");
sdp2430_display_init();
}
