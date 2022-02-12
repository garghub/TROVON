static int omap_prox_activate(struct device *dev)
{
gpio_set_value(OMAP4_SFH7741_ENABLE_GPIO , 1);
return 0;
}
static void omap_prox_deactivate(struct device *dev)
{
gpio_set_value(OMAP4_SFH7741_ENABLE_GPIO , 0);
}
static int __init omap_ethernet_init(void)
{
int status;
status = gpio_request_array(sdp4430_eth_gpios,
ARRAY_SIZE(sdp4430_eth_gpios));
if (status)
pr_err("Cannot request ETH GPIOs\n");
return status;
}
static int omap4_twl6030_hsmmc_late_init(struct device *dev)
{
int ret = 0;
struct platform_device *pdev = container_of(dev,
struct platform_device, dev);
struct omap_mmc_platform_data *pdata = dev->platform_data;
if (pdev->id == 0) {
ret = twl6030_mmc_card_detect_config();
if (ret)
pr_err("Failed configuring MMC1 card detect\n");
pdata->slots[0].card_detect_irq = TWL6030_IRQ_BASE +
MMCDETECT_INTR_OFFSET;
pdata->slots[0].card_detect = twl6030_mmc_card_detect;
}
return ret;
}
static __init void omap4_twl6030_hsmmc_set_late_init(struct device *dev)
{
struct omap_mmc_platform_data *pdata;
if (!dev) {
pr_err("Failed %s\n", __func__);
return;
}
pdata = dev->platform_data;
pdata->init = omap4_twl6030_hsmmc_late_init;
}
static int __init omap4_twl6030_hsmmc_init(struct omap2_hsmmc_info *controllers)
{
struct omap2_hsmmc_info *c;
omap2_hsmmc_init(controllers);
for (c = controllers; c->mmc; c++)
omap4_twl6030_hsmmc_set_late_init(c->dev);
return 0;
}
static int __init omap4_i2c_init(void)
{
omap4_pmic_get_config(&sdp4430_twldata, TWL_COMMON_PDATA_USB,
TWL_COMMON_REGULATOR_VDAC |
TWL_COMMON_REGULATOR_VAUX2 |
TWL_COMMON_REGULATOR_VAUX3 |
TWL_COMMON_REGULATOR_VMMC |
TWL_COMMON_REGULATOR_VPP |
TWL_COMMON_REGULATOR_VANA |
TWL_COMMON_REGULATOR_VCXIO |
TWL_COMMON_REGULATOR_VUSB |
TWL_COMMON_REGULATOR_CLK32KG);
omap4_pmic_init("twl6030", &sdp4430_twldata);
omap_register_i2c_bus(2, 400, NULL, 0);
omap_register_i2c_bus(3, 400, sdp4430_i2c_3_boardinfo,
ARRAY_SIZE(sdp4430_i2c_3_boardinfo));
omap_register_i2c_bus(4, 400, sdp4430_i2c_4_boardinfo,
ARRAY_SIZE(sdp4430_i2c_4_boardinfo));
return 0;
}
static void __init omap_sfh7741prox_init(void)
{
int error;
error = gpio_request_one(OMAP4_SFH7741_ENABLE_GPIO,
GPIOF_OUT_INIT_LOW, "sfh7741");
if (error < 0)
pr_err("%s:failed to request GPIO %d, error %d\n",
__func__, OMAP4_SFH7741_ENABLE_GPIO, error);
}
static int sdp4430_panel_enable_hdmi(struct omap_dss_device *dssdev)
{
int status;
status = gpio_request_array(sdp4430_hdmi_gpios,
ARRAY_SIZE(sdp4430_hdmi_gpios));
if (status)
pr_err("%s: Cannot request HDMI GPIOs\n", __func__);
return status;
}
static void sdp4430_panel_disable_hdmi(struct omap_dss_device *dssdev)
{
gpio_free_array(sdp4430_hdmi_gpios, ARRAY_SIZE(sdp4430_hdmi_gpios));
}
static void sdp4430_lcd_init(void)
{
int r;
r = gpio_request_one(dsi1_panel.reset_gpio, GPIOF_DIR_OUT,
"lcd1_reset_gpio");
if (r)
pr_err("%s: Could not get lcd1_reset_gpio\n", __func__);
r = gpio_request_one(dsi2_panel.reset_gpio, GPIOF_DIR_OUT,
"lcd2_reset_gpio");
if (r)
pr_err("%s: Could not get lcd2_reset_gpio\n", __func__);
}
static void sdp4430_picodlp_init(void)
{
int r;
const struct gpio picodlp_gpios[] = {
{DLP_POWER_ON_GPIO, GPIOF_OUT_INIT_LOW,
"DLP POWER ON"},
{sdp4430_picodlp_pdata.emu_done_gpio, GPIOF_IN,
"DLP EMU DONE"},
{sdp4430_picodlp_pdata.pwrgood_gpio, GPIOF_OUT_INIT_LOW,
"DLP PWRGOOD"},
};
r = gpio_request_array(picodlp_gpios, ARRAY_SIZE(picodlp_gpios));
if (r)
pr_err("Cannot request PicoDLP GPIOs, error %d\n", r);
}
static int sdp4430_panel_enable_picodlp(struct omap_dss_device *dssdev)
{
gpio_set_value(DISPLAY_SEL_GPIO, 0);
gpio_set_value(DLP_POWER_ON_GPIO, 1);
return 0;
}
static void sdp4430_panel_disable_picodlp(struct omap_dss_device *dssdev)
{
gpio_set_value(DLP_POWER_ON_GPIO, 0);
gpio_set_value(DISPLAY_SEL_GPIO, 1);
}
static void __init omap_4430sdp_display_init(void)
{
int r;
r = gpio_request_one(DISPLAY_SEL_GPIO, GPIOF_OUT_INIT_HIGH,
"display_sel");
if (r)
pr_err("%s: Could not get display_sel GPIO\n", __func__);
sdp4430_lcd_init();
sdp4430_picodlp_init();
omap_display_init(&sdp4430_dss_data);
if (cpu_is_omap446x() || omap_rev() > OMAP4430_REV_ES2_2)
omap_hdmi_init(OMAP_HDMI_SDA_SCL_EXTERNAL_PULLUP);
else
omap_hdmi_init(0);
omap_mux_init_gpio(HDMI_GPIO_LS_OE, OMAP_PIN_OUTPUT);
omap_mux_init_gpio(HDMI_GPIO_CT_CP_HPD, OMAP_PIN_OUTPUT);
omap_mux_init_gpio(HDMI_GPIO_HPD, OMAP_PIN_INPUT_PULLDOWN);
}
static void __init omap4_sdp4430_wifi_mux_init(void)
{
omap_mux_init_gpio(GPIO_WIFI_IRQ, OMAP_PIN_INPUT |
OMAP_PIN_OFF_WAKEUPENABLE);
omap_mux_init_gpio(GPIO_WIFI_PMENA, OMAP_PIN_OUTPUT);
omap_mux_init_signal("sdmmc5_cmd.sdmmc5_cmd",
OMAP_MUX_MODE0 | OMAP_PIN_INPUT_PULLUP);
omap_mux_init_signal("sdmmc5_clk.sdmmc5_clk",
OMAP_MUX_MODE0 | OMAP_PIN_INPUT_PULLUP);
omap_mux_init_signal("sdmmc5_dat0.sdmmc5_dat0",
OMAP_MUX_MODE0 | OMAP_PIN_INPUT_PULLUP);
omap_mux_init_signal("sdmmc5_dat1.sdmmc5_dat1",
OMAP_MUX_MODE0 | OMAP_PIN_INPUT_PULLUP);
omap_mux_init_signal("sdmmc5_dat2.sdmmc5_dat2",
OMAP_MUX_MODE0 | OMAP_PIN_INPUT_PULLUP);
omap_mux_init_signal("sdmmc5_dat3.sdmmc5_dat3",
OMAP_MUX_MODE0 | OMAP_PIN_INPUT_PULLUP);
}
static void __init omap4_sdp4430_wifi_init(void)
{
int ret;
omap4_sdp4430_wifi_mux_init();
ret = wl12xx_set_platform_data(&omap4_sdp4430_wlan_data);
if (ret)
pr_err("Error setting wl12xx data: %d\n", ret);
ret = platform_device_register(&omap_vwlan_device);
if (ret)
pr_err("Error registering wl12xx device: %d\n", ret);
}
static void __init omap_4430sdp_init(void)
{
int status;
int package = OMAP_PACKAGE_CBS;
if (omap_rev() == OMAP4430_REV_ES1_0)
package = OMAP_PACKAGE_CBL;
omap4_mux_init(board_mux, NULL, package);
omap4_i2c_init();
omap_sfh7741prox_init();
platform_add_devices(sdp4430_devices, ARRAY_SIZE(sdp4430_devices));
omap_serial_init();
omap_sdrc_init(NULL, NULL);
omap4_sdp4430_wifi_init();
omap4_twl6030_hsmmc_init(mmc);
usb_musb_init(&musb_board_data);
status = omap_ethernet_init();
if (status) {
pr_err("Ethernet initialization failed: %d\n", status);
} else {
sdp4430_spi_board_info[0].irq = gpio_to_irq(ETH_KS8851_IRQ);
spi_register_board_info(sdp4430_spi_board_info,
ARRAY_SIZE(sdp4430_spi_board_info));
}
status = omap4_keyboard_init(&sdp4430_keypad_data, &keypad_data);
if (status)
pr_err("Keypad initialization failed: %d\n", status);
omap_4430sdp_display_init();
}
