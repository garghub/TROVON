static inline void __init ldp_init_smsc911x(void)
{
gpmc_smsc911x_init(&smsc911x_cfg);
}
static int ldp_panel_enable_lcd(struct omap_dss_device *dssdev)
{
if (gpio_is_valid(ldp_lcd_enable_gpio))
gpio_direction_output(ldp_lcd_enable_gpio, 1);
if (gpio_is_valid(ldp_backlight_gpio))
gpio_direction_output(ldp_backlight_gpio, 1);
return 0;
}
static void ldp_panel_disable_lcd(struct omap_dss_device *dssdev)
{
if (gpio_is_valid(ldp_lcd_enable_gpio))
gpio_direction_output(ldp_lcd_enable_gpio, 0);
if (gpio_is_valid(ldp_backlight_gpio))
gpio_direction_output(ldp_backlight_gpio, 0);
}
static void __init ldp_display_init(void)
{
int r;
static struct gpio gpios[] __initdata = {
{LCD_PANEL_RESET_GPIO, GPIOF_OUT_INIT_HIGH, "LCD RESET"},
{LCD_PANEL_QVGA_GPIO, GPIOF_OUT_INIT_HIGH, "LCD QVGA"},
};
r = gpio_request_array(gpios, ARRAY_SIZE(gpios));
if (r) {
pr_err("Cannot request LCD GPIOs, error %d\n", r);
return;
}
omap_display_init(&ldp_dss_data);
}
static int ldp_twl_gpio_setup(struct device *dev, unsigned gpio, unsigned ngpio)
{
int r;
struct gpio gpios[] = {
{gpio + 7 , GPIOF_OUT_INIT_LOW, "LCD ENABLE"},
{gpio + 15, GPIOF_OUT_INIT_LOW, "LCD BACKLIGHT"},
};
r = gpio_request_array(gpios, ARRAY_SIZE(gpios));
if (r) {
pr_err("Cannot request LCD GPIOs, error %d\n", r);
ldp_backlight_gpio = -EINVAL;
ldp_lcd_enable_gpio = -EINVAL;
return r;
}
ldp_backlight_gpio = gpio + 15;
ldp_lcd_enable_gpio = gpio + 7;
return 0;
}
static int __init omap_i2c_init(void)
{
omap3_pmic_get_config(&ldp_twldata,
TWL_COMMON_PDATA_USB | TWL_COMMON_PDATA_MADC, 0);
omap3_pmic_init("twl4030", &ldp_twldata);
omap_register_i2c_bus(2, 400, NULL, 0);
omap_register_i2c_bus(3, 400, NULL, 0);
return 0;
}
static void __init omap_ldp_init(void)
{
regulator_register_fixed(0, dummy_supplies, ARRAY_SIZE(dummy_supplies));
omap3_mux_init(board_mux, OMAP_PACKAGE_CBB);
ldp_init_smsc911x();
omap_i2c_init();
platform_add_devices(ldp_devices, ARRAY_SIZE(ldp_devices));
omap_ads7846_init(1, 54, 310, NULL);
omap_serial_init();
omap_sdrc_init(NULL, NULL);
usb_musb_init(NULL);
board_nand_init(ldp_nand_partitions,
ARRAY_SIZE(ldp_nand_partitions), ZOOM_NAND_CS, 0);
omap_hsmmc_init(mmc);
ldp_display_init();
}
