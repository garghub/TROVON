static void __init omap3_beagle_init_rev(void)
{
int ret;
u16 beagle_rev = 0;
omap_mux_init_gpio(171, OMAP_PIN_INPUT_PULLUP);
omap_mux_init_gpio(172, OMAP_PIN_INPUT_PULLUP);
omap_mux_init_gpio(173, OMAP_PIN_INPUT_PULLUP);
ret = gpio_request_array(omap3_beagle_rev_gpios,
ARRAY_SIZE(omap3_beagle_rev_gpios));
if (ret < 0) {
printk(KERN_ERR "Unable to get revision detection GPIO pins\n");
omap3_beagle_version = OMAP3BEAGLE_BOARD_UNKN;
return;
}
beagle_rev = gpio_get_value(171) | (gpio_get_value(172) << 1)
| (gpio_get_value(173) << 2);
gpio_free_array(omap3_beagle_rev_gpios,
ARRAY_SIZE(omap3_beagle_rev_gpios));
switch (beagle_rev) {
case 7:
printk(KERN_INFO "OMAP3 Beagle Rev: Ax/Bx\n");
omap3_beagle_version = OMAP3BEAGLE_BOARD_AXBX;
beagle_config.mmc1_gpio_wp = 29;
beagle_config.reset_gpio = 170;
beagle_config.usr_button_gpio = 7;
break;
case 6:
printk(KERN_INFO "OMAP3 Beagle Rev: C1/C2/C3\n");
omap3_beagle_version = OMAP3BEAGLE_BOARD_C1_3;
beagle_config.mmc1_gpio_wp = 23;
beagle_config.reset_gpio = 170;
beagle_config.usr_button_gpio = 7;
break;
case 5:
printk(KERN_INFO "OMAP3 Beagle Rev: C4\n");
omap3_beagle_version = OMAP3BEAGLE_BOARD_C4;
beagle_config.mmc1_gpio_wp = 23;
beagle_config.reset_gpio = 170;
beagle_config.usr_button_gpio = 7;
break;
case 0:
printk(KERN_INFO "OMAP3 Beagle Rev: xM Ax/Bx\n");
omap3_beagle_version = OMAP3BEAGLE_BOARD_XM;
beagle_config.usb_pwr_level = GPIOF_OUT_INIT_HIGH;
break;
case 2:
printk(KERN_INFO "OMAP3 Beagle Rev: xM C\n");
omap3_beagle_version = OMAP3BEAGLE_BOARD_XMC;
break;
default:
printk(KERN_INFO "OMAP3 Beagle Rev: unknown %hd\n", beagle_rev);
omap3_beagle_version = OMAP3BEAGLE_BOARD_UNKN;
}
}
static int beagle_enable_dvi(struct omap_dss_device *dssdev)
{
if (gpio_is_valid(dssdev->reset_gpio))
gpio_set_value(dssdev->reset_gpio, 1);
return 0;
}
static void beagle_disable_dvi(struct omap_dss_device *dssdev)
{
if (gpio_is_valid(dssdev->reset_gpio))
gpio_set_value(dssdev->reset_gpio, 0);
}
static void __init beagle_display_init(void)
{
int r;
r = gpio_request_one(beagle_dvi_device.reset_gpio, GPIOF_OUT_INIT_LOW,
"DVI reset");
if (r < 0)
printk(KERN_ERR "Unable to get DVI reset GPIO\n");
}
static int beagle_twl_gpio_setup(struct device *dev,
unsigned gpio, unsigned ngpio)
{
int r;
mmc[0].gpio_wp = beagle_config.mmc1_gpio_wp;
mmc[0].gpio_cd = gpio + 0;
omap_hsmmc_late_init(mmc);
if (cpu_is_omap3630()) {
r = gpio_request_one(gpio + 1, GPIOF_OUT_INIT_LOW,
"nDVI_PWR_EN");
if (r)
pr_err("%s: unable to configure nDVI_PWR_EN\n",
__func__);
r = gpio_request_one(gpio + 2, GPIOF_OUT_INIT_HIGH,
"DVI_LDO_EN");
if (r)
pr_err("%s: unable to configure DVI_LDO_EN\n",
__func__);
} else {
if (gpio_request_one(gpio + 1, GPIOF_IN, "EHCI_nOC"))
pr_err("%s: unable to configure EHCI_nOC\n", __func__);
}
beagle_dvi_device.reset_gpio = beagle_config.reset_gpio;
gpio_request_one(gpio + TWL4030_GPIO_MAX, beagle_config.usb_pwr_level,
"nEN_USB_PWR");
gpio_leds[2].gpio = gpio + TWL4030_GPIO_MAX + 1;
return 0;
}
static int __init omap3_beagle_i2c_init(void)
{
omap3_pmic_get_config(&beagle_twldata,
TWL_COMMON_PDATA_USB | TWL_COMMON_PDATA_MADC |
TWL_COMMON_PDATA_AUDIO,
TWL_COMMON_REGULATOR_VDAC | TWL_COMMON_REGULATOR_VPLL2);
beagle_twldata.vpll2->constraints.name = "VDVI";
omap3_pmic_init("twl4030", &beagle_twldata);
omap_register_i2c_bus(3, 100, beagle_i2c_eeprom, ARRAY_SIZE(beagle_i2c_eeprom));
return 0;
}
static void __init beagle_opp_init(void)
{
int r = 0;
if (omap3_opp_init()) {
pr_err("%s: opp default init failed\n", __func__);
return;
}
if (cpu_is_omap3630()) {
struct device *mpu_dev, *iva_dev;
mpu_dev = omap_device_get_by_hwmod_name("mpu");
iva_dev = omap_device_get_by_hwmod_name("iva");
if (!mpu_dev || !iva_dev) {
pr_err("%s: Aiee.. no mpu/dsp devices? %p %p\n",
__func__, mpu_dev, iva_dev);
return;
}
r = opp_enable(mpu_dev, 800000000);
r |= opp_enable(iva_dev, 660000000);
if (r) {
pr_err("%s: failed to enable higher opp %d\n",
__func__, r);
opp_disable(mpu_dev, 800000000);
opp_disable(iva_dev, 660000000);
}
}
return;
}
static void __init omap3_beagle_init(void)
{
omap3_mux_init(board_mux, OMAP_PACKAGE_CBB);
omap3_beagle_init_rev();
if (beagle_config.mmc1_gpio_wp != -EINVAL)
omap_mux_init_gpio(beagle_config.mmc1_gpio_wp, OMAP_PIN_INPUT);
omap_hsmmc_init(mmc);
omap3_beagle_i2c_init();
gpio_buttons[0].gpio = beagle_config.usr_button_gpio;
platform_add_devices(omap3_beagle_devices,
ARRAY_SIZE(omap3_beagle_devices));
omap_display_init(&beagle_dss_data);
omap_serial_init();
omap_sdrc_init(mt46h32m32lf6_sdrc_params,
mt46h32m32lf6_sdrc_params);
omap_mux_init_gpio(170, OMAP_PIN_INPUT);
gpio_request_one(170, GPIOF_OUT_INIT_HIGH, "DVI_nPD");
usb_musb_init(NULL);
usbhs_init(&usbhs_bdata);
omap_nand_flash_init(NAND_BUSWIDTH_16, omap3beagle_nand_partitions,
ARRAY_SIZE(omap3beagle_nand_partitions));
omap_mux_init_signal("sys_drm_msecure", OMAP_PIN_OFF_OUTPUT_HIGH);
omap_mux_init_signal("sdrc_cke0", OMAP_PIN_OUTPUT);
omap_mux_init_signal("sdrc_cke1", OMAP_PIN_OUTPUT);
beagle_display_init();
beagle_opp_init();
}
