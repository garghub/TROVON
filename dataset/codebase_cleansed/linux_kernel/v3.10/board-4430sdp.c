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
TWL_COMMON_REGULATOR_CLK32KG |
TWL_COMMON_REGULATOR_V1V8 |
TWL_COMMON_REGULATOR_V2V1);
omap4_pmic_init("twl6030", &sdp4430_twldata, sdp4430_i2c_1_boardinfo,
ARRAY_SIZE(sdp4430_i2c_1_boardinfo));
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
omap4_sdp4430_wlan_data.irq = gpio_to_irq(GPIO_WIFI_IRQ);
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
regulator_register_always_on(0, "backlight-enable",
&backlight_supply, 1, 0);
platform_add_devices(sdp4430_devices, ARRAY_SIZE(sdp4430_devices));
omap_serial_init();
omap_sdrc_init(NULL, NULL);
omap4_sdp4430_wifi_init();
omap4_twl6030_hsmmc_init(mmc);
usb_bind_phy("musb-hdrc.2.auto", 0, "omap-usb2.3.auto");
usb_musb_init(&musb_board_data);
status = omap_ethernet_init();
if (status) {
pr_err("Ethernet initialization failed: %d\n", status);
} else {
sdp4430_spi_board_info[0].irq = gpio_to_irq(ETH_KS8851_IRQ);
spi_register_board_info(sdp4430_spi_board_info,
ARRAY_SIZE(sdp4430_spi_board_info));
}
pwm_add_table(sdp4430_pwm_lookup, ARRAY_SIZE(sdp4430_pwm_lookup));
status = omap4_keyboard_init(&sdp4430_keypad_data, &keypad_data);
if (status)
pr_err("Keypad initialization failed: %d\n", status);
omap_4430sdp_display_init();
}
