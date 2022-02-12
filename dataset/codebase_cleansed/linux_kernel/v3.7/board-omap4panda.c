static void __init omap4_ehci_init(void)
{
int ret;
struct clk *phy_ref_clk;
phy_ref_clk = clk_get(NULL, "auxclk3_ck");
if (IS_ERR(phy_ref_clk)) {
pr_err("Cannot request auxclk3\n");
return;
}
clk_set_rate(phy_ref_clk, 19200000);
clk_prepare_enable(phy_ref_clk);
ret = gpio_request_array(panda_ehci_gpios,
ARRAY_SIZE(panda_ehci_gpios));
if (ret) {
pr_err("Unable to initialize EHCI power/reset\n");
return;
}
gpio_export(GPIO_HUB_POWER, 0);
gpio_export(GPIO_HUB_NRESET, 0);
gpio_set_value(GPIO_HUB_NRESET, 1);
usbhs_init(&usbhs_bdata);
gpio_set_value(GPIO_HUB_POWER, 1);
}
static int __init omap4_panda_i2c_init(void)
{
omap4_pmic_get_config(&omap4_panda_twldata, TWL_COMMON_PDATA_USB,
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
omap4_pmic_init("twl6030", &omap4_panda_twldata, panda_i2c_1_boardinfo,
ARRAY_SIZE(panda_i2c_1_boardinfo));
omap_register_i2c_bus(2, 400, NULL, 0);
omap_register_i2c_bus(3, 100, panda_i2c_eeprom,
ARRAY_SIZE(panda_i2c_eeprom));
omap_register_i2c_bus(4, 400, NULL, 0);
return 0;
}
static void __init omap4_panda_display_init(void)
{
omap_display_init(&omap4_panda_dss_data);
if (cpu_is_omap446x() || omap_rev() > OMAP4430_REV_ES2_2)
omap_hdmi_init(OMAP_HDMI_SDA_SCL_EXTERNAL_PULLUP);
else
omap_hdmi_init(0);
omap_mux_init_gpio(HDMI_GPIO_LS_OE, OMAP_PIN_OUTPUT);
omap_mux_init_gpio(HDMI_GPIO_CT_CP_HPD, OMAP_PIN_OUTPUT);
omap_mux_init_gpio(HDMI_GPIO_HPD, OMAP_PIN_INPUT_PULLDOWN);
}
static void omap4_panda_init_rev(void)
{
if (cpu_is_omap443x()) {
panda_abe_audio_data.card_name = "PandaBoard";
panda_abe_audio_data.has_hsmic = 1;
} else {
panda_abe_audio_data.card_name = "PandaBoardES";
}
}
static void __init omap4_panda_init(void)
{
int package = OMAP_PACKAGE_CBS;
int ret;
if (omap_rev() == OMAP4430_REV_ES1_0)
package = OMAP_PACKAGE_CBL;
omap4_mux_init(board_mux, NULL, package);
omap_panda_wlan_data.irq = gpio_to_irq(GPIO_WIFI_IRQ);
ret = wl12xx_set_platform_data(&omap_panda_wlan_data);
if (ret)
pr_err("error setting wl12xx data: %d\n", ret);
omap4_panda_init_rev();
omap4_panda_i2c_init();
platform_add_devices(panda_devices, ARRAY_SIZE(panda_devices));
platform_device_register(&omap_vwlan_device);
omap_serial_init();
omap_sdrc_init(NULL, NULL);
omap4_twl6030_hsmmc_init(mmc);
omap4_ehci_init();
usb_musb_init(&musb_board_data);
omap4_panda_display_init();
}
