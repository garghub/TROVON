static void __init cm_t35_init_ethernet(void)
{
gpmc_smsc911x_init(&cm_t35_smsc911x_cfg);
gpmc_smsc911x_init(&sb_t35_smsc911x_cfg);
}
static inline void __init cm_t35_init_ethernet(void) { return; }
static void __init cm_t35_init_led(void)
{
platform_device_register(&cm_t35_led_device);
}
static inline void cm_t35_init_led(void) {}
static void __init cm_t35_init_nand(void)
{
if (gpmc_nand_init(&cm_t35_nand_data) < 0)
pr_err("CM-T35: Unable to register NAND device\n");
}
static inline void cm_t35_init_nand(void) {}
static int cm_t35_panel_enable_lcd(struct omap_dss_device *dssdev)
{
if (dvi_enabled) {
printk(KERN_ERR "cannot enable LCD, DVI is enabled\n");
return -EINVAL;
}
gpio_set_value(CM_T35_LCD_EN_GPIO, 1);
gpio_set_value(CM_T35_LCD_BL_GPIO, 1);
lcd_enabled = 1;
return 0;
}
static void cm_t35_panel_disable_lcd(struct omap_dss_device *dssdev)
{
lcd_enabled = 0;
gpio_set_value(CM_T35_LCD_BL_GPIO, 0);
gpio_set_value(CM_T35_LCD_EN_GPIO, 0);
}
static int cm_t35_panel_enable_dvi(struct omap_dss_device *dssdev)
{
if (lcd_enabled) {
printk(KERN_ERR "cannot enable DVI, LCD is enabled\n");
return -EINVAL;
}
gpio_set_value(CM_T35_DVI_EN_GPIO, 0);
dvi_enabled = 1;
return 0;
}
static void cm_t35_panel_disable_dvi(struct omap_dss_device *dssdev)
{
gpio_set_value(CM_T35_DVI_EN_GPIO, 1);
dvi_enabled = 0;
}
static int cm_t35_panel_enable_tv(struct omap_dss_device *dssdev)
{
return 0;
}
static void cm_t35_panel_disable_tv(struct omap_dss_device *dssdev)
{
}
static void __init cm_t35_init_display(void)
{
int err;
spi_register_board_info(cm_t35_lcd_spi_board_info,
ARRAY_SIZE(cm_t35_lcd_spi_board_info));
err = gpio_request_array(cm_t35_dss_gpios,
ARRAY_SIZE(cm_t35_dss_gpios));
if (err) {
pr_err("CM-T35: failed to request DSS control GPIOs\n");
return;
}
gpio_export(CM_T35_LCD_EN_GPIO, 0);
gpio_export(CM_T35_LCD_BL_GPIO, 0);
gpio_export(CM_T35_DVI_EN_GPIO, 0);
msleep(50);
gpio_set_value(CM_T35_LCD_EN_GPIO, 1);
err = omap_display_init(&cm_t35_dss_data);
if (err) {
pr_err("CM-T35: failed to register DSS device\n");
gpio_free_array(cm_t35_dss_gpios, ARRAY_SIZE(cm_t35_dss_gpios));
}
}
static int cm_t35_twl_gpio_setup(struct device *dev, unsigned gpio,
unsigned ngpio)
{
int wlan_rst = gpio + 2;
if (gpio_request_one(wlan_rst, GPIOF_OUT_INIT_HIGH, "WLAN RST") == 0) {
gpio_export(wlan_rst, 0);
udelay(10);
gpio_set_value(wlan_rst, 0);
udelay(10);
gpio_set_value(wlan_rst, 1);
} else {
pr_err("CM-T35: could not obtain gpio for WiFi reset\n");
}
mmc[0].gpio_cd = gpio + 0;
omap2_hsmmc_init(mmc);
cm_t35_vmmc1_supply.dev = mmc[0].dev;
cm_t35_vsim_supply.dev = mmc[0].dev;
return 0;
}
static void __init cm_t35_init_i2c(void)
{
omap3_pmic_init("tps65930", &cm_t35_twldata);
}
static void __init cm_t35_init_early(void)
{
omap2_init_common_infrastructure();
omap2_init_common_devices(mt46h32m32lf6_sdrc_params,
mt46h32m32lf6_sdrc_params);
}
static void __init cm_t35_init(void)
{
omap_board_config = cm_t35_config;
omap_board_config_size = ARRAY_SIZE(cm_t35_config);
omap3_mux_init(board_mux, OMAP_PACKAGE_CUS);
omap_serial_init();
cm_t35_init_i2c();
cm_t35_init_nand();
omap_ads7846_init(1, CM_T35_GPIO_PENDOWN, 0, NULL);
cm_t35_init_ethernet();
cm_t35_init_led();
cm_t35_init_display();
usb_musb_init(NULL);
usbhs_init(&usbhs_bdata);
}
