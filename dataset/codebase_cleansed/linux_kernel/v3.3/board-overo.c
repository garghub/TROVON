static void __init overo_ads7846_init(void)
{
omap_ads7846_init(1, OVERO_GPIO_PENDOWN, 0, NULL);
platform_device_register(&vads7846_device);
}
static inline void __init overo_ads7846_init(void) { return; }
static void __init overo_init_smsc911x(void)
{
gpmc_smsc911x_init(&smsc911x_cfg);
gpmc_smsc911x_init(&smsc911x2_cfg);
}
static inline void __init overo_init_smsc911x(void) { return; }
static void __init overo_display_init(void)
{
if (gpio_request_array(overo_dss_gpios, ARRAY_SIZE(overo_dss_gpios))) {
printk(KERN_ERR "could not obtain DSS control GPIOs\n");
return;
}
gpio_export(OVERO_GPIO_LCD_EN, 0);
gpio_export(OVERO_GPIO_LCD_BL, 0);
}
static int overo_panel_enable_dvi(struct omap_dss_device *dssdev)
{
if (lcd_enabled) {
printk(KERN_ERR "cannot enable DVI, LCD is enabled\n");
return -EINVAL;
}
dvi_enabled = 1;
return 0;
}
static void overo_panel_disable_dvi(struct omap_dss_device *dssdev)
{
dvi_enabled = 0;
}
static int overo_panel_enable_lcd(struct omap_dss_device *dssdev)
{
if (dvi_enabled) {
printk(KERN_ERR "cannot enable LCD, DVI is enabled\n");
return -EINVAL;
}
gpio_set_value(OVERO_GPIO_LCD_EN, 1);
gpio_set_value(OVERO_GPIO_LCD_BL, 1);
lcd_enabled = 1;
return 0;
}
static void overo_panel_disable_lcd(struct omap_dss_device *dssdev)
{
gpio_set_value(OVERO_GPIO_LCD_EN, 0);
gpio_set_value(OVERO_GPIO_LCD_BL, 0);
lcd_enabled = 0;
}
static void __init overo_init_led(void)
{
platform_device_register(&gpio_leds_device);
}
static inline void __init overo_init_led(void) { return; }
static void __init overo_init_keys(void)
{
platform_device_register(&gpio_keys_device);
}
static inline void __init overo_init_keys(void) { return; }
static int overo_twl_gpio_setup(struct device *dev,
unsigned gpio, unsigned ngpio)
{
omap2_hsmmc_init(mmc);
#if defined(CONFIG_LEDS_GPIO) || defined(CONFIG_LEDS_GPIO_MODULE)
gpio_leds[2].gpio = gpio + TWL4030_GPIO_MAX + 1;
#endif
return 0;
}
static int __init overo_i2c_init(void)
{
omap3_pmic_get_config(&overo_twldata,
TWL_COMMON_PDATA_USB | TWL_COMMON_PDATA_AUDIO,
TWL_COMMON_REGULATOR_VDAC | TWL_COMMON_REGULATOR_VPLL2);
overo_twldata.vpll2->constraints.name = "VDVI";
omap3_pmic_init("tps65950", &overo_twldata);
omap_register_i2c_bus(3, 400, NULL, 0);
return 0;
}
static int __init overo_spi_init(void)
{
overo_ads7846_init();
spi_register_board_info(overo_spi_board_info,
ARRAY_SIZE(overo_spi_board_info));
return 0;
}
static void __init overo_init(void)
{
int ret;
omap3_mux_init(board_mux, OMAP_PACKAGE_CBB);
overo_i2c_init();
omap_display_init(&overo_dss_data);
omap_serial_init();
omap_sdrc_init(mt46h32m32lf6_sdrc_params,
mt46h32m32lf6_sdrc_params);
omap_nand_flash_init(0, overo_nand_partitions,
ARRAY_SIZE(overo_nand_partitions));
usb_musb_init(NULL);
usbhs_init(&usbhs_bdata);
overo_spi_init();
overo_init_smsc911x();
overo_display_init();
overo_init_led();
overo_init_keys();
omap_mux_init_signal("sdrc_cke0", OMAP_PIN_OUTPUT);
omap_mux_init_signal("sdrc_cke1", OMAP_PIN_OUTPUT);
ret = gpio_request_one(OVERO_GPIO_W2W_NRESET, GPIOF_OUT_INIT_HIGH,
"OVERO_GPIO_W2W_NRESET");
if (ret == 0) {
gpio_export(OVERO_GPIO_W2W_NRESET, 0);
gpio_set_value(OVERO_GPIO_W2W_NRESET, 0);
udelay(10);
gpio_set_value(OVERO_GPIO_W2W_NRESET, 1);
} else {
printk(KERN_ERR "could not obtain gpio for "
"OVERO_GPIO_W2W_NRESET\n");
}
ret = gpio_request_array(overo_bt_gpios, ARRAY_SIZE(overo_bt_gpios));
if (ret) {
pr_err("%s: could not obtain BT gpios\n", __func__);
} else {
gpio_export(OVERO_GPIO_BT_XGATE, 0);
gpio_export(OVERO_GPIO_BT_NRESET, 0);
gpio_set_value(OVERO_GPIO_BT_NRESET, 0);
mdelay(6);
gpio_set_value(OVERO_GPIO_BT_NRESET, 1);
}
ret = gpio_request_one(OVERO_GPIO_USBH_CPEN, GPIOF_OUT_INIT_HIGH,
"OVERO_GPIO_USBH_CPEN");
if (ret == 0)
gpio_export(OVERO_GPIO_USBH_CPEN, 0);
else
printk(KERN_ERR "could not obtain gpio for "
"OVERO_GPIO_USBH_CPEN\n");
}
