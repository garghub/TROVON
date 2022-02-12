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
omap_display_init(&overo_dss_data);
if (!overo_use_lcd35)
platform_device_register(&overo_lcd43_device);
platform_device_register(&overo_tfp410_device);
platform_device_register(&overo_dvi_connector_device);
platform_device_register(&overo_tv_connector_device);
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
if (overo_use_lcd35) {
spi_register_board_info(overo_spi_board_info,
ARRAY_SIZE(overo_spi_board_info));
}
return 0;
}
static void __init overo_init(void)
{
int ret;
if (strstr(boot_command_line, "omapdss.def_disp=lcd35"))
overo_use_lcd35 = true;
regulator_register_fixed(0, dummy_supplies, ARRAY_SIZE(dummy_supplies));
omap3_mux_init(board_mux, OMAP_PACKAGE_CBB);
overo_i2c_init();
omap_hsmmc_init(mmc);
omap_serial_init();
omap_sdrc_init(mt46h32m32lf6_sdrc_params,
mt46h32m32lf6_sdrc_params);
board_nand_init(overo_nand_partitions,
ARRAY_SIZE(overo_nand_partitions), NAND_CS, 0, NULL);
usb_bind_phy("musb-hdrc.0.auto", 0, "twl4030_usb");
usb_musb_init(NULL);
usbhs_init_phys(phy_data, ARRAY_SIZE(phy_data));
usbhs_init(&usbhs_bdata);
overo_spi_init();
overo_init_smsc911x();
overo_init_led();
overo_init_keys();
omap_twl4030_audio_init("overo", NULL);
overo_display_init();
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
pr_err("could not obtain gpio for OVERO_GPIO_W2W_NRESET\n");
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
pr_err("could not obtain gpio for OVERO_GPIO_USBH_CPEN\n");
}
