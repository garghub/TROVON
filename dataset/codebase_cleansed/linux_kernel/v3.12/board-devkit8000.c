static int devkit8000_twl_gpio_setup(struct device *dev,
unsigned gpio, unsigned ngpio)
{
mmc[0].gpio_cd = gpio + 0;
omap_hsmmc_late_init(mmc);
gpio_leds[2].gpio = gpio + TWL4030_GPIO_MAX + 1;
devkit8000_lcd_pdata.enable_gpio = gpio + TWL4030_GPIO_MAX + 0;
devkit8000_tfp410_pdata.power_down_gpio = gpio + 7;
return 0;
}
static int __init devkit8000_i2c_init(void)
{
omap3_pmic_get_config(&devkit8000_twldata,
TWL_COMMON_PDATA_USB | TWL_COMMON_PDATA_AUDIO,
TWL_COMMON_REGULATOR_VDAC);
omap3_pmic_init("tps65930", &devkit8000_twldata);
omap_register_i2c_bus(3, 400, NULL, 0);
return 0;
}
static void __init omap_dm9000_init(void)
{
unsigned char *eth_addr = omap_dm9000_platdata.dev_addr;
struct omap_die_id odi;
int ret;
ret = gpio_request_one(OMAP_DM9000_GPIO_IRQ, GPIOF_IN, "dm9000 irq");
if (ret < 0) {
printk(KERN_ERR "Failed to request GPIO%d for dm9000 IRQ\n",
OMAP_DM9000_GPIO_IRQ);
return;
}
omap_get_die_id(&odi);
eth_addr[0] = 0x02;
eth_addr[1] = odi.id_1 & 0xff;
eth_addr[2] = (odi.id_0 & 0xff000000) >> 24;
eth_addr[3] = (odi.id_0 & 0x00ff0000) >> 16;
eth_addr[4] = (odi.id_0 & 0x0000ff00) >> 8;
eth_addr[5] = (odi.id_0 & 0x000000ff);
}
static void __init devkit8000_init(void)
{
omap3_mux_init(board_mux, OMAP_PACKAGE_CUS);
omap_serial_init();
omap_sdrc_init(mt46h32m32lf6_sdrc_params,
mt46h32m32lf6_sdrc_params);
omap_dm9000_init();
omap_hsmmc_init(mmc);
devkit8000_i2c_init();
omap_dm9000_resources[2].start = gpio_to_irq(OMAP_DM9000_GPIO_IRQ);
platform_add_devices(devkit8000_devices,
ARRAY_SIZE(devkit8000_devices));
omap_display_init(&devkit8000_dss_data);
omap_ads7846_init(2, OMAP3_DEVKIT_TS_GPIO, 0, NULL);
usb_bind_phy("musb-hdrc.0.auto", 0, "twl4030_usb");
usb_musb_init(NULL);
usbhs_init(&usbhs_bdata);
board_nand_init(devkit8000_nand_partitions,
ARRAY_SIZE(devkit8000_nand_partitions), NAND_CS,
NAND_BUSWIDTH_16, NULL);
omap_twl4030_audio_init("omap3beagle", NULL);
omap_mux_init_signal("sdrc_cke0", OMAP_PIN_OUTPUT);
omap_mux_init_signal("sdrc_cke1", OMAP_PIN_OUTPUT);
}
