static void pandora_wl1251_init_card(struct mmc_card *card)
{
card->quirks |= MMC_QUIRK_NONSTD_SDIO;
card->cccr.wide_bus = 1;
card->cis.vendor = 0x104c;
card->cis.device = 0x9066;
card->cis.blksize = 512;
card->cis.max_dtr = 20000000;
}
static int omap3pandora_twl_gpio_setup(struct device *dev,
unsigned gpio, unsigned ngpio)
{
int ret, gpio_32khz;
omap3pandora_mmc[0].gpio_cd = gpio + 0;
omap3pandora_mmc[1].gpio_cd = gpio + 1;
omap2_hsmmc_init(omap3pandora_mmc);
gpio_32khz = gpio + 13;
ret = gpio_request_one(gpio_32khz, GPIOF_OUT_INIT_HIGH, "wifi 32kHz");
if (ret < 0) {
pr_err("Cannot get GPIO line %d, ret=%d\n", gpio_32khz, ret);
return -ENODEV;
}
return 0;
}
static int __init omap3pandora_i2c_init(void)
{
omap3_pmic_get_config(&omap3pandora_twldata,
TWL_COMMON_PDATA_USB | TWL_COMMON_PDATA_AUDIO,
TWL_COMMON_REGULATOR_VDAC | TWL_COMMON_REGULATOR_VPLL2);
omap3pandora_twldata.vdac->constraints.apply_uV = true;
omap3pandora_twldata.vpll2->constraints.apply_uV = true;
omap3pandora_twldata.vpll2->num_consumer_supplies =
ARRAY_SIZE(pandora_vdds_supplies);
omap3pandora_twldata.vpll2->consumer_supplies = pandora_vdds_supplies;
omap3_pmic_init("tps65950", &omap3pandora_twldata);
omap_register_i2c_bus(3, 100, omap3pandora_i2c3_boardinfo,
ARRAY_SIZE(omap3pandora_i2c3_boardinfo));
return 0;
}
static void __init pandora_wl1251_init(void)
{
struct wl12xx_platform_data pandora_wl1251_pdata;
int ret;
memset(&pandora_wl1251_pdata, 0, sizeof(pandora_wl1251_pdata));
ret = gpio_request_one(PANDORA_WIFI_IRQ_GPIO, GPIOF_IN, "wl1251 irq");
if (ret < 0)
goto fail;
pandora_wl1251_pdata.irq = gpio_to_irq(PANDORA_WIFI_IRQ_GPIO);
if (pandora_wl1251_pdata.irq < 0)
goto fail_irq;
pandora_wl1251_pdata.use_eeprom = true;
ret = wl12xx_set_platform_data(&pandora_wl1251_pdata);
if (ret < 0)
goto fail_irq;
return;
fail_irq:
gpio_free(PANDORA_WIFI_IRQ_GPIO);
fail:
printk(KERN_ERR "wl1251 board initialisation failed\n");
}
static void __init omap3pandora_init(void)
{
omap3_mux_init(board_mux, OMAP_PACKAGE_CBB);
omap3pandora_i2c_init();
pandora_wl1251_init();
platform_add_devices(omap3pandora_devices,
ARRAY_SIZE(omap3pandora_devices));
omap_display_init(&pandora_dss_data);
omap_serial_init();
omap_sdrc_init(mt46h32m32lf6_sdrc_params,
mt46h32m32lf6_sdrc_params);
spi_register_board_info(omap3pandora_spi_board_info,
ARRAY_SIZE(omap3pandora_spi_board_info));
omap_ads7846_init(1, OMAP3_PANDORA_TS_GPIO, 0, NULL);
usbhs_init(&usbhs_bdata);
usb_musb_init(NULL);
gpmc_nand_init(&pandora_nand_data);
omap_mux_init_signal("sdrc_cke0", OMAP_PIN_OUTPUT);
omap_mux_init_signal("sdrc_cke1", OMAP_PIN_OUTPUT);
}
