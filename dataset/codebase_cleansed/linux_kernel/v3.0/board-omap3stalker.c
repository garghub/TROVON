static inline void __init omap3stalker_init_eth(void)
{
struct clk *l3ck;
unsigned int rate;
l3ck = clk_get(NULL, "l3_ck");
if (IS_ERR(l3ck))
rate = 100000000;
else
rate = clk_get_rate(l3ck);
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
static int omap3_stalker_enable_lcd(struct omap_dss_device *dssdev)
{
if (dvi_enabled) {
printk(KERN_ERR "cannot enable LCD, DVI is enabled\n");
return -EINVAL;
}
gpio_set_value(DSS_ENABLE_GPIO, 1);
gpio_set_value(LCD_PANEL_BKLIGHT_GPIO, 1);
lcd_enabled = 1;
return 0;
}
static void omap3_stalker_disable_lcd(struct omap_dss_device *dssdev)
{
gpio_set_value(DSS_ENABLE_GPIO, 0);
gpio_set_value(LCD_PANEL_BKLIGHT_GPIO, 0);
lcd_enabled = 0;
}
static int omap3_stalker_enable_tv(struct omap_dss_device *dssdev)
{
return 0;
}
static void omap3_stalker_disable_tv(struct omap_dss_device *dssdev)
{
}
static int omap3_stalker_enable_dvi(struct omap_dss_device *dssdev)
{
if (lcd_enabled) {
printk(KERN_ERR "cannot enable DVI, LCD is enabled\n");
return -EINVAL;
}
gpio_set_value(DSS_ENABLE_GPIO, 1);
dvi_enabled = 1;
return 0;
}
static void omap3_stalker_disable_dvi(struct omap_dss_device *dssdev)
{
gpio_set_value(DSS_ENABLE_GPIO, 0);
dvi_enabled = 0;
}
static int
omap3stalker_twl_gpio_setup(struct device *dev,
unsigned gpio, unsigned ngpio)
{
omap_mux_init_gpio(23, OMAP_PIN_INPUT);
mmc[0].gpio_cd = gpio + 0;
omap2_hsmmc_init(mmc);
omap3stalker_vmmc1_supply.dev = mmc[0].dev;
omap3stalker_vsim_supply.dev = mmc[0].dev;
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
omap3_pmic_init("twl4030", &omap3stalker_twldata);
omap_register_i2c_bus(2, 400, NULL, 0);
omap_register_i2c_bus(3, 400, omap3stalker_i2c_boardinfo3,
ARRAY_SIZE(omap3stalker_i2c_boardinfo3));
return 0;
}
static void __init omap3_stalker_init_early(void)
{
omap2_init_common_infrastructure();
omap2_init_common_devices(mt46h32m32lf6_sdrc_params, NULL);
}
static void __init omap3_stalker_init_irq(void)
{
omap_init_irq();
#ifdef CONFIG_OMAP_32K_TIMER
omap2_gp_clockevent_set_gptimer(12);
#endif
}
static void __init omap3_stalker_init(void)
{
omap3_mux_init(board_mux, OMAP_PACKAGE_CUS);
omap_board_config = omap3_stalker_config;
omap_board_config_size = ARRAY_SIZE(omap3_stalker_config);
omap3_stalker_i2c_init();
platform_add_devices(omap3_stalker_devices,
ARRAY_SIZE(omap3_stalker_devices));
omap_display_init(&omap3_stalker_dss_data);
omap_serial_init();
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
