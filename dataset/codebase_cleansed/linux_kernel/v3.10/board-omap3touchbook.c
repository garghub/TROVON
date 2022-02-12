static int touchbook_twl_gpio_setup(struct device *dev,
unsigned gpio, unsigned ngpio)
{
mmc[0].gpio_cd = gpio + 0;
omap_hsmmc_late_init(mmc);
gpio_request_one(gpio + 1, GPIOF_IN, "EHCI_nOC");
gpio_request_one(gpio + TWL4030_GPIO_MAX, GPIOF_OUT_INIT_LOW,
"nEN_USB_PWR");
gpio_leds[2].gpio = gpio + TWL4030_GPIO_MAX + 1;
return 0;
}
static int __init omap3_touchbook_i2c_init(void)
{
omap3_pmic_get_config(&touchbook_twldata,
TWL_COMMON_PDATA_USB | TWL_COMMON_PDATA_AUDIO,
TWL_COMMON_REGULATOR_VDAC | TWL_COMMON_REGULATOR_VPLL2);
touchbook_twldata.vdac->num_consumer_supplies =
ARRAY_SIZE(touchbook_vdac_supply);
touchbook_twldata.vdac->consumer_supplies = touchbook_vdac_supply;
touchbook_twldata.vpll2->constraints.name = "VDVI";
touchbook_twldata.vpll2->num_consumer_supplies =
ARRAY_SIZE(touchbook_vdvi_supply);
touchbook_twldata.vpll2->consumer_supplies = touchbook_vdvi_supply;
omap3_pmic_init("twl4030", &touchbook_twldata);
omap_register_i2c_bus(3, 100, touchBook_i2c_boardinfo,
ARRAY_SIZE(touchBook_i2c_boardinfo));
return 0;
}
static void omap3_touchbook_poweroff(void)
{
int pwr_off = TB_KILL_POWER_GPIO;
if (gpio_request_one(pwr_off, GPIOF_OUT_INIT_LOW, "DVI reset") < 0)
printk(KERN_ERR "Unable to get kill power GPIO\n");
}
static int __init early_touchbook_revision(char *p)
{
if (!p)
return 0;
return strict_strtoul(p, 10, &touchbook_revision);
}
static void __init omap3_touchbook_init(void)
{
omap3_mux_init(board_mux, OMAP_PACKAGE_CBB);
pm_power_off = omap3_touchbook_poweroff;
if (system_rev >= 0x20 && system_rev <= 0x34301000) {
omap_mux_init_gpio(23, OMAP_PIN_INPUT);
mmc[0].gpio_wp = 23;
} else {
omap_mux_init_gpio(29, OMAP_PIN_INPUT);
}
omap_hsmmc_init(mmc);
omap3_touchbook_i2c_init();
platform_add_devices(omap3_touchbook_devices,
ARRAY_SIZE(omap3_touchbook_devices));
omap_serial_init();
omap_sdrc_init(mt46h32m32lf6_sdrc_params,
mt46h32m32lf6_sdrc_params);
omap_mux_init_gpio(170, OMAP_PIN_INPUT);
gpio_request_one(176, GPIOF_OUT_INIT_HIGH, "DVI_nPD");
omap_ads7846_init(4, OMAP3_TS_GPIO, 310, &ads7846_pdata);
usb_bind_phy("musb-hdrc.0.auto", 0, "twl4030_usb");
usb_musb_init(NULL);
usbhs_init_phys(phy_data, ARRAY_SIZE(phy_data));
usbhs_init(&usbhs_bdata);
board_nand_init(omap3touchbook_nand_partitions,
ARRAY_SIZE(omap3touchbook_nand_partitions), NAND_CS,
NAND_BUSWIDTH_16, NULL);
omap_mux_init_signal("sdrc_cke0", OMAP_PIN_OUTPUT);
omap_mux_init_signal("sdrc_cke1", OMAP_PIN_OUTPUT);
}
