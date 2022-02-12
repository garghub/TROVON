static void mipid_shutdown(struct mipid_platform_data *pdata)
{
if (pdata->nreset_gpio != -1) {
printk(KERN_INFO "shutdown LCD\n");
gpio_set_value(pdata->nreset_gpio, 0);
msleep(120);
}
}
static void __init mipid_dev_init(void)
{
const struct omap_lcd_config *conf;
conf = omap_get_config(OMAP_TAG_LCD, struct omap_lcd_config);
if (conf != NULL) {
nokia770_mipid_platform_data.nreset_gpio = conf->nreset_gpio;
nokia770_mipid_platform_data.data_lines = conf->data_lines;
}
}
static void __init ads7846_dev_init(void)
{
if (gpio_request(ADS7846_PENDOWN_GPIO, "ADS7846 pendown") < 0)
printk(KERN_ERR "can't get ads7846 pen down GPIO\n");
}
static int ads7846_get_pendown_state(void)
{
return !gpio_get_value(ADS7846_PENDOWN_GPIO);
}
static void __init hwa742_dev_init(void)
{
clk_add_alias("hwa_sys_ck", NULL, "bclk", NULL);
omapfb_set_ctrl_platform_data(&nokia770_hwa742_platform_data);
}
static int nokia770_mmc_set_power(struct device *dev, int slot, int power_on,
int vdd)
{
gpio_set_value(NOKIA770_GPIO_MMC_POWER, power_on);
return 0;
}
static int nokia770_mmc_get_cover_state(struct device *dev, int slot)
{
return gpio_get_value(NOKIA770_GPIO_MMC_SWITCH);
}
static void __init nokia770_mmc_init(void)
{
int ret;
ret = gpio_request(NOKIA770_GPIO_MMC_POWER, "MMC power");
if (ret < 0)
return;
gpio_direction_output(NOKIA770_GPIO_MMC_POWER, 0);
ret = gpio_request(NOKIA770_GPIO_MMC_SWITCH, "MMC cover");
if (ret < 0) {
gpio_free(NOKIA770_GPIO_MMC_POWER);
return;
}
gpio_direction_input(NOKIA770_GPIO_MMC_SWITCH);
nokia770_mmc_data[1] = &nokia770_mmc2_data;
omap1_init_mmc(nokia770_mmc_data, OMAP16XX_NR_MMC);
}
static inline void nokia770_mmc_init(void)
{
}
static void __init omap_nokia770_init(void)
{
omap_writew((omap_readw(0xfffb5008) & ~2), 0xfffb5008);
omap_writew((omap_readw(0xfffb5004) & ~2), 0xfffb5004);
platform_add_devices(nokia770_devices, ARRAY_SIZE(nokia770_devices));
spi_register_board_info(nokia770_spi_board_info,
ARRAY_SIZE(nokia770_spi_board_info));
omap_serial_init();
omap_register_i2c_bus(1, 100, NULL, 0);
hwa742_dev_init();
ads7846_dev_init();
mipid_dev_init();
omap1_usb_init(&nokia770_usb_config);
nokia770_mmc_init();
}
