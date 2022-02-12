static void __init omap4_panda_init_early(void)
{
omap2_init_common_infrastructure();
omap2_init_common_devices(NULL, NULL);
}
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
clk_enable(phy_ref_clk);
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
static int omap4_twl6030_hsmmc_late_init(struct device *dev)
{
int ret = 0;
struct platform_device *pdev = container_of(dev,
struct platform_device, dev);
struct omap_mmc_platform_data *pdata = dev->platform_data;
if (!pdata) {
dev_err(dev, "%s: NULL platform data\n", __func__);
return -EINVAL;
}
if (pdev->id == 0) {
ret = twl6030_mmc_card_detect_config();
if (ret)
dev_err(dev, "%s: Error card detect config(%d)\n",
__func__, ret);
else
pdata->slots[0].card_detect = twl6030_mmc_card_detect;
}
return ret;
}
static __init void omap4_twl6030_hsmmc_set_late_init(struct device *dev)
{
struct omap_mmc_platform_data *pdata;
if (!dev) {
pr_err("Failed omap4_twl6030_hsmmc_set_late_init\n");
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
static int __init omap4_panda_i2c_init(void)
{
omap4_pmic_init("twl6030", &omap4_panda_twldata);
omap_register_i2c_bus(2, 400, NULL, 0);
omap_register_i2c_bus(3, 100, panda_i2c_eeprom,
ARRAY_SIZE(panda_i2c_eeprom));
omap_register_i2c_bus(4, 400, NULL, 0);
return 0;
}
static inline void board_serial_init(void)
{
struct omap_board_data bdata;
bdata.flags = 0;
bdata.pads = NULL;
bdata.pads_cnt = 0;
bdata.id = 0;
omap_serial_init_port(&bdata);
omap_serial_init_port(&serial2_data);
omap_serial_init_port(&serial3_data);
omap_serial_init_port(&serial4_data);
}
static inline void board_serial_init(void)
{
omap_serial_init();
}
static int omap4_panda_enable_dvi(struct omap_dss_device *dssdev)
{
gpio_set_value(dssdev->reset_gpio, 1);
return 0;
}
static void omap4_panda_disable_dvi(struct omap_dss_device *dssdev)
{
gpio_set_value(dssdev->reset_gpio, 0);
}
int __init omap4_panda_dvi_init(void)
{
int r;
r = gpio_request_one(omap4_panda_dvi_device.reset_gpio,
GPIOF_OUT_INIT_LOW, "DVI PD");
if (r)
pr_err("Failed to get DVI powerdown GPIO\n");
return r;
}
static void omap4_panda_hdmi_mux_init(void)
{
omap_mux_init_signal("hdmi_hpd",
OMAP_PIN_INPUT_PULLUP);
omap_mux_init_signal("hdmi_cec",
OMAP_PIN_INPUT_PULLUP);
omap_mux_init_signal("hdmi_ddc_scl",
OMAP_PIN_INPUT_PULLUP);
omap_mux_init_signal("hdmi_ddc_sda",
OMAP_PIN_INPUT_PULLUP);
}
static int omap4_panda_panel_enable_hdmi(struct omap_dss_device *dssdev)
{
int status;
status = gpio_request_array(panda_hdmi_gpios,
ARRAY_SIZE(panda_hdmi_gpios));
if (status)
pr_err("Cannot request HDMI GPIOs\n");
return status;
}
static void omap4_panda_panel_disable_hdmi(struct omap_dss_device *dssdev)
{
gpio_free(HDMI_GPIO_LS_OE);
gpio_free(HDMI_GPIO_HPD);
}
void omap4_panda_display_init(void)
{
int r;
r = omap4_panda_dvi_init();
if (r)
pr_err("error initializing panda DVI\n");
omap4_panda_hdmi_mux_init();
omap_display_init(&omap4_panda_dss_data);
}
static void __init omap4_panda_init(void)
{
int package = OMAP_PACKAGE_CBS;
if (omap_rev() == OMAP4430_REV_ES1_0)
package = OMAP_PACKAGE_CBL;
omap4_mux_init(board_mux, NULL, package);
if (wl12xx_set_platform_data(&omap_panda_wlan_data))
pr_err("error setting wl12xx data\n");
omap4_panda_i2c_init();
platform_add_devices(panda_devices, ARRAY_SIZE(panda_devices));
platform_device_register(&omap_vwlan_device);
board_serial_init();
omap4_twl6030_hsmmc_init(mmc);
omap4_ehci_init();
usb_musb_init(&musb_board_data);
omap4_panda_display_init();
}
static void __init omap4_panda_map_io(void)
{
omap2_set_globals_443x();
omap44xx_map_common_io();
}
