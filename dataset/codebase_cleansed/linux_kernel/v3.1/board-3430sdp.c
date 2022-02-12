static void __init sdp3430_display_init(void)
{
int r;
r = gpio_request_array(sdp3430_dss_gpios,
ARRAY_SIZE(sdp3430_dss_gpios));
if (r)
printk(KERN_ERR "failed to get LCD control GPIOs\n");
}
static int sdp3430_panel_enable_lcd(struct omap_dss_device *dssdev)
{
if (dvi_enabled) {
printk(KERN_ERR "cannot enable LCD, DVI is enabled\n");
return -EINVAL;
}
gpio_direction_output(SDP3430_LCD_PANEL_ENABLE_GPIO, 1);
gpio_direction_output(SDP3430_LCD_PANEL_BACKLIGHT_GPIO, 1);
lcd_enabled = 1;
return 0;
}
static void sdp3430_panel_disable_lcd(struct omap_dss_device *dssdev)
{
lcd_enabled = 0;
gpio_direction_output(SDP3430_LCD_PANEL_ENABLE_GPIO, 0);
gpio_direction_output(SDP3430_LCD_PANEL_BACKLIGHT_GPIO, 0);
}
static int sdp3430_panel_enable_dvi(struct omap_dss_device *dssdev)
{
if (lcd_enabled) {
printk(KERN_ERR "cannot enable DVI, LCD is enabled\n");
return -EINVAL;
}
dvi_enabled = 1;
return 0;
}
static void sdp3430_panel_disable_dvi(struct omap_dss_device *dssdev)
{
dvi_enabled = 0;
}
static int sdp3430_panel_enable_tv(struct omap_dss_device *dssdev)
{
return 0;
}
static void sdp3430_panel_disable_tv(struct omap_dss_device *dssdev)
{
}
static void __init omap_3430sdp_init_early(void)
{
omap2_init_common_infrastructure();
omap2_init_common_devices(hyb18m512160af6_sdrc_params, NULL);
}
static int sdp3430_twl_gpio_setup(struct device *dev,
unsigned gpio, unsigned ngpio)
{
mmc[0].gpio_cd = gpio + 0;
mmc[1].gpio_cd = gpio + 1;
omap2_hsmmc_init(mmc);
gpio_request_one(gpio + 7, GPIOF_OUT_INIT_LOW, "sub_lcd_en_bkl");
gpio_request_one(gpio + 15, GPIOF_OUT_INIT_LOW, "sub_lcd_nRST");
return 0;
}
static int __init omap3430_i2c_init(void)
{
omap3_pmic_get_config(&sdp3430_twldata,
TWL_COMMON_PDATA_USB | TWL_COMMON_PDATA_BCI |
TWL_COMMON_PDATA_MADC | TWL_COMMON_PDATA_AUDIO,
TWL_COMMON_REGULATOR_VDAC | TWL_COMMON_REGULATOR_VPLL2);
sdp3430_twldata.vdac->constraints.apply_uV = true;
sdp3430_twldata.vpll2->constraints.apply_uV = true;
sdp3430_twldata.vpll2->constraints.name = "VDVI";
omap3_pmic_init("twl4030", &sdp3430_twldata);
omap_register_i2c_bus(2, 400, NULL, 0);
omap_register_i2c_bus(3, 400, NULL, 0);
return 0;
}
static void __init board_smc91x_init(void)
{
if (omap_rev() > OMAP3430_REV_ES1_0)
board_smc91x_data.gpio_irq = 6;
else
board_smc91x_data.gpio_irq = 29;
gpmc_smc91x_init(&board_smc91x_data);
}
static inline void board_smc91x_init(void)
{
}
static void enable_board_wakeup_source(void)
{
omap_mux_init_signal("sys_nirq",
OMAP_WAKEUP_EN | OMAP_PIN_INPUT_PULLUP);
}
static inline void board_serial_init(void)
{
omap_serial_init_port(&serial1_data);
omap_serial_init_port(&serial2_data);
omap_serial_init_port(&serial3_data);
}
static inline void board_serial_init(void)
{
omap_serial_init();
}
static void __init omap_3430sdp_init(void)
{
int gpio_pendown;
omap3_mux_init(board_mux, OMAP_PACKAGE_CBB);
omap_board_config = sdp3430_config;
omap_board_config_size = ARRAY_SIZE(sdp3430_config);
omap3430_i2c_init();
omap_display_init(&sdp3430_dss_data);
if (omap_rev() > OMAP3430_REV_ES1_0)
gpio_pendown = SDP3430_TS_GPIO_IRQ_SDPV2;
else
gpio_pendown = SDP3430_TS_GPIO_IRQ_SDPV1;
omap_ads7846_init(1, gpio_pendown, 310, NULL);
board_serial_init();
usb_musb_init(NULL);
board_smc91x_init();
board_flash_init(sdp_flash_partitions, chip_sel_3430, 0);
sdp3430_display_init();
enable_board_wakeup_source();
usbhs_init(&usbhs_bdata);
}
