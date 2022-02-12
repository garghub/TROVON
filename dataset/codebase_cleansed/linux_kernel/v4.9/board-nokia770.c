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
nokia770_mipid_platform_data.nreset_gpio = 13;
nokia770_mipid_platform_data.data_lines = 16;
omapfb_set_lcd_config(&nokia770_lcd_config);
}
static void __init hwa742_dev_init(void)
{
clk_add_alias("hwa_sys_ck", NULL, "bclk", NULL);
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
static void __init nokia770_cbus_init(void)
{
const int retu_irq_gpio = 62;
const int tahvo_irq_gpio = 40;
if (gpio_request_one(retu_irq_gpio, GPIOF_IN, "Retu IRQ"))
return;
if (gpio_request_one(tahvo_irq_gpio, GPIOF_IN, "Tahvo IRQ")) {
gpio_free(retu_irq_gpio);
return;
}
irq_set_irq_type(gpio_to_irq(retu_irq_gpio), IRQ_TYPE_EDGE_RISING);
irq_set_irq_type(gpio_to_irq(tahvo_irq_gpio), IRQ_TYPE_EDGE_RISING);
nokia770_i2c_board_info_2[0].irq = gpio_to_irq(retu_irq_gpio);
nokia770_i2c_board_info_2[1].irq = gpio_to_irq(tahvo_irq_gpio);
i2c_register_board_info(2, nokia770_i2c_board_info_2,
ARRAY_SIZE(nokia770_i2c_board_info_2));
platform_device_register(&nokia770_cbus_device);
}
static void __init nokia770_cbus_init(void)
{
}
static void __init omap_nokia770_init(void)
{
omap_writew((omap_readw(0xfffb5008) & ~2), 0xfffb5008);
omap_writew((omap_readw(0xfffb5004) & ~2), 0xfffb5004);
platform_add_devices(nokia770_devices, ARRAY_SIZE(nokia770_devices));
nokia770_spi_board_info[1].irq = gpio_to_irq(15);
spi_register_board_info(nokia770_spi_board_info,
ARRAY_SIZE(nokia770_spi_board_info));
omap_serial_init();
omap_register_i2c_bus(1, 100, NULL, 0);
hwa742_dev_init();
mipid_dev_init();
omap1_usb_init(&nokia770_usb_config);
nokia770_mmc_init();
nokia770_cbus_init();
}
