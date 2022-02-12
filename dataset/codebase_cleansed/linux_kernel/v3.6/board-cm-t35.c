static void __init cm_t35_init_ethernet(void)
{
regulator_register_fixed(0, cm_t35_smsc911x_supplies,
ARRAY_SIZE(cm_t35_smsc911x_supplies));
regulator_register_fixed(1, sb_t35_smsc911x_supplies,
ARRAY_SIZE(sb_t35_smsc911x_supplies));
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
msleep(50);
gpio_set_value(CM_T35_LCD_EN_GPIO, 1);
err = omap_display_init(&cm_t35_dss_data);
if (err) {
pr_err("CM-T35: failed to register DSS device\n");
gpio_free_array(cm_t35_dss_gpios, ARRAY_SIZE(cm_t35_dss_gpios));
}
}
static void __init cm_t35_init_usbh(void)
{
int err;
err = gpio_request_one(SB_T35_USB_HUB_RESET_GPIO,
GPIOF_OUT_INIT_LOW, "usb hub rst");
if (err) {
pr_err("SB-T35: usb hub rst gpio request failed: %d\n", err);
} else {
udelay(10);
gpio_set_value(SB_T35_USB_HUB_RESET_GPIO, 1);
msleep(1);
}
usbhs_init(&usbhs_bdata);
}
static int cm_t35_twl_gpio_setup(struct device *dev, unsigned gpio,
unsigned ngpio)
{
int wlan_rst = gpio + 2;
if (gpio_request_one(wlan_rst, GPIOF_OUT_INIT_HIGH, "WLAN RST") == 0) {
gpio_export(wlan_rst, 0);
udelay(10);
gpio_set_value_cansleep(wlan_rst, 0);
udelay(10);
gpio_set_value_cansleep(wlan_rst, 1);
} else {
pr_err("CM-T35: could not obtain gpio for WiFi reset\n");
}
mmc[0].gpio_cd = gpio + 0;
omap_hsmmc_late_init(mmc);
return 0;
}
static void __init cm_t35_init_camera(void)
{
if (omap3_init_camera(&cm_t35_isp_pdata) < 0)
pr_warn("CM-T3x: Failed registering camera device!\n");
}
static inline void cm_t35_init_camera(void) {}
static void __init cm_t35_init_i2c(void)
{
omap3_pmic_get_config(&cm_t35_twldata, TWL_COMMON_PDATA_USB,
TWL_COMMON_REGULATOR_VDAC |
TWL_COMMON_PDATA_AUDIO);
omap3_pmic_init("tps65930", &cm_t35_twldata);
omap_register_i2c_bus(3, 400, NULL, 0);
}
static void __init cm_t3x_common_dss_mux_init(int mux_mode)
{
omap_mux_init_signal("dss_data18", mux_mode);
omap_mux_init_signal("dss_data19", mux_mode);
omap_mux_init_signal("dss_data20", mux_mode);
omap_mux_init_signal("dss_data21", mux_mode);
omap_mux_init_signal("dss_data22", mux_mode);
omap_mux_init_signal("dss_data23", mux_mode);
}
static void __init cm_t35_init_mux(void)
{
int mux_mode = OMAP_MUX_MODE0 | OMAP_PIN_OUTPUT;
omap_mux_init_signal("dss_data0.dss_data0", mux_mode);
omap_mux_init_signal("dss_data1.dss_data1", mux_mode);
omap_mux_init_signal("dss_data2.dss_data2", mux_mode);
omap_mux_init_signal("dss_data3.dss_data3", mux_mode);
omap_mux_init_signal("dss_data4.dss_data4", mux_mode);
omap_mux_init_signal("dss_data5.dss_data5", mux_mode);
cm_t3x_common_dss_mux_init(mux_mode);
}
static void __init cm_t3730_init_mux(void)
{
int mux_mode = OMAP_MUX_MODE3 | OMAP_PIN_OUTPUT;
omap_mux_init_signal("sys_boot0", mux_mode);
omap_mux_init_signal("sys_boot1", mux_mode);
omap_mux_init_signal("sys_boot3", mux_mode);
omap_mux_init_signal("sys_boot4", mux_mode);
omap_mux_init_signal("sys_boot5", mux_mode);
omap_mux_init_signal("sys_boot6", mux_mode);
cm_t3x_common_dss_mux_init(mux_mode);
}
static inline void cm_t35_init_mux(void) {}
static inline void cm_t3730_init_mux(void) {}
static void __init cm_t3x_common_init(void)
{
omap_board_config = cm_t35_config;
omap_board_config_size = ARRAY_SIZE(cm_t35_config);
omap3_mux_init(board_mux, OMAP_PACKAGE_CUS);
omap_serial_init();
omap_sdrc_init(mt46h32m32lf6_sdrc_params,
mt46h32m32lf6_sdrc_params);
omap_hsmmc_init(mmc);
cm_t35_init_i2c();
omap_ads7846_init(1, CM_T35_GPIO_PENDOWN, 0, NULL);
cm_t35_init_ethernet();
cm_t35_init_led();
cm_t35_init_display();
usb_musb_init(NULL);
cm_t35_init_usbh();
cm_t35_init_camera();
}
static void __init cm_t35_init(void)
{
cm_t3x_common_init();
cm_t35_init_mux();
cm_t35_init_nand();
}
static void __init cm_t3730_init(void)
{
cm_t3x_common_init();
cm_t3730_init_mux();
}
