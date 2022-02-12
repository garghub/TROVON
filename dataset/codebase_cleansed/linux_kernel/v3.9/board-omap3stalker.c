static inline void __init omap3stalker_init_eth(void)
{
omap_mux_init_gpio(19, OMAP_PIN_INPUT_PULLUP);
gpmc_smsc911x_init(&smsc911x_cfg);
}
static inline void __init omap3stalker_init_eth(void)
{
return;
}
static void __init omap3_stalker_display_init(void)
{
return;
}
static int omap3_stalker_enable_tv(struct omap_dss_device *dssdev)
{
return 0;
}
static void omap3_stalker_disable_tv(struct omap_dss_device *dssdev)
{
}
static int
omap3stalker_twl_gpio_setup(struct device *dev,
unsigned gpio, unsigned ngpio)
{
mmc[0].gpio_cd = gpio + 0;
omap_hsmmc_late_init(mmc);
gpio_request_one(gpio + TWL4030_GPIO_MAX, GPIOF_OUT_INIT_LOW,
"EN_LCD_BKL");
gpio_request_one(gpio + 7, GPIOF_OUT_INIT_LOW, "EN_DVI");
gpio_leds[2].gpio = gpio + TWL4030_GPIO_MAX + 1;
gpio_leds[3].gpio = gpio + 13;
platform_device_register(&leds_gpio);
return 0;
}
static int __init omap3_stalker_i2c_init(void)
{
omap3_pmic_get_config(&omap3stalker_twldata,
TWL_COMMON_PDATA_USB | TWL_COMMON_PDATA_MADC |
TWL_COMMON_PDATA_AUDIO,
TWL_COMMON_REGULATOR_VDAC | TWL_COMMON_REGULATOR_VPLL2);
omap3stalker_twldata.vdac->constraints.apply_uV = true;
omap3stalker_twldata.vpll2->constraints.apply_uV = true;
omap3stalker_twldata.vpll2->constraints.name = "VDVI";
omap3_pmic_init("twl4030", &omap3stalker_twldata);
omap_register_i2c_bus(2, 400, NULL, 0);
omap_register_i2c_bus(3, 400, omap3stalker_i2c_boardinfo3,
ARRAY_SIZE(omap3stalker_i2c_boardinfo3));
return 0;
}
static void __init omap3_stalker_init(void)
{
regulator_register_fixed(0, dummy_supplies, ARRAY_SIZE(dummy_supplies));
omap3_mux_init(board_mux, OMAP_PACKAGE_CUS);
omap_mux_init_gpio(23, OMAP_PIN_INPUT);
omap_hsmmc_init(mmc);
omap3_stalker_i2c_init();
platform_add_devices(omap3_stalker_devices,
ARRAY_SIZE(omap3_stalker_devices));
omap_display_init(&omap3_stalker_dss_data);
omap_serial_init();
omap_sdrc_init(mt46h32m32lf6_sdrc_params, NULL);
usb_bind_phy("musb-hdrc.0.auto", 0, "twl4030_usb");
usb_musb_init(NULL);
usbhs_init(&usbhs_bdata);
omap_ads7846_init(1, OMAP3_STALKER_TS_GPIO, 310, NULL);
omap_mux_init_gpio(21, OMAP_PIN_OUTPUT);
omap_mux_init_gpio(18, OMAP_PIN_INPUT_PULLUP);
omap3stalker_init_eth();
omap3_stalker_display_init();
omap_mux_init_signal("sdr_cke0", OMAP_PIN_OUTPUT);
omap_mux_init_signal("sdr_cke1", OMAP_PIN_OUTPUT);
}
