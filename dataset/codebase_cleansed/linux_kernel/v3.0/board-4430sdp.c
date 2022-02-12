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
static void __init omap_4430sdp_init_early(void)
{
omap2_init_common_infrastructure();
omap2_init_common_devices(NULL, NULL);
#ifdef CONFIG_OMAP_32K_TIMER
omap2_gp_clockevent_set_gptimer(1);
#endif
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
static void sdp4430_hdmi_mux_init(void)
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
gpio_free(HDMI_GPIO_LS_OE);
gpio_free(HDMI_GPIO_HPD);
}
void omap_4430sdp_display_init(void)
{
sdp4430_hdmi_mux_init();
omap_display_init(&sdp4430_dss_data);
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
static void __init omap_4430sdp_init(void)
{
int status;
int package = OMAP_PACKAGE_CBS;
if (omap_rev() == OMAP4430_REV_ES1_0)
package = OMAP_PACKAGE_CBL;
omap4_mux_init(board_mux, NULL, package);
omap_board_config = sdp4430_config;
omap_board_config_size = ARRAY_SIZE(sdp4430_config);
omap4_i2c_init();
omap_sfh7741prox_init();
platform_add_devices(sdp4430_devices, ARRAY_SIZE(sdp4430_devices));
board_serial_init();
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
status = omap4_keyboard_init(&sdp4430_keypad_data);
if (status)
pr_err("Keypad initialization failed: %d\n", status);
omap_4430sdp_display_init();
}
static void __init omap_4430sdp_map_io(void)
{
omap2_set_globals_443x();
omap44xx_map_common_io();
}
