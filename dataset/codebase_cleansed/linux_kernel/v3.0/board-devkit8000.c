static int devkit8000_panel_enable_lcd(struct omap_dss_device *dssdev)
{
if (gpio_is_valid(dssdev->reset_gpio))
gpio_set_value_cansleep(dssdev->reset_gpio, 1);
return 0;
}
static void devkit8000_panel_disable_lcd(struct omap_dss_device *dssdev)
{
if (gpio_is_valid(dssdev->reset_gpio))
gpio_set_value_cansleep(dssdev->reset_gpio, 0);
}
static int devkit8000_panel_enable_dvi(struct omap_dss_device *dssdev)
{
if (gpio_is_valid(dssdev->reset_gpio))
gpio_set_value_cansleep(dssdev->reset_gpio, 1);
return 0;
}
static void devkit8000_panel_disable_dvi(struct omap_dss_device *dssdev)
{
if (gpio_is_valid(dssdev->reset_gpio))
gpio_set_value_cansleep(dssdev->reset_gpio, 0);
}
static int devkit8000_twl_gpio_setup(struct device *dev,
unsigned gpio, unsigned ngpio)
{
int ret;
omap_mux_init_gpio(29, OMAP_PIN_INPUT);
mmc[0].gpio_cd = gpio + 0;
omap2_hsmmc_init(mmc);
gpio_leds[2].gpio = gpio + TWL4030_GPIO_MAX + 1;
devkit8000_lcd_device.reset_gpio = gpio + TWL4030_GPIO_MAX + 0;
ret = gpio_request_one(devkit8000_lcd_device.reset_gpio,
GPIOF_OUT_INIT_LOW, "LCD_PWREN");
if (ret < 0) {
devkit8000_lcd_device.reset_gpio = -EINVAL;
printk(KERN_ERR "Failed to request GPIO for LCD_PWRN\n");
}
devkit8000_dvi_device.reset_gpio = gpio + 7;
ret = gpio_request_one(devkit8000_dvi_device.reset_gpio,
GPIOF_OUT_INIT_LOW, "DVI PowerDown");
if (ret < 0) {
devkit8000_dvi_device.reset_gpio = -EINVAL;
printk(KERN_ERR "Failed to request GPIO for DVI PowerDown\n");
}
return 0;
}
static int __init devkit8000_i2c_init(void)
{
omap3_pmic_init("tps65930", &devkit8000_twldata);
omap_register_i2c_bus(3, 400, NULL, 0);
return 0;
}
static void __init devkit8000_init_early(void)
{
omap2_init_common_infrastructure();
omap2_init_common_devices(mt46h32m32lf6_sdrc_params,
mt46h32m32lf6_sdrc_params);
}
static void __init devkit8000_init_irq(void)
{
omap_init_irq();
#ifdef CONFIG_OMAP_32K_TIMER
omap2_gp_clockevent_set_gptimer(12);
#endif
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
omap_dm9000_init();
devkit8000_i2c_init();
platform_add_devices(devkit8000_devices,
ARRAY_SIZE(devkit8000_devices));
omap_display_init(&devkit8000_dss_data);
omap_ads7846_init(2, OMAP3_DEVKIT_TS_GPIO, 0, NULL);
usb_musb_init(NULL);
usbhs_init(&usbhs_bdata);
omap_nand_flash_init(NAND_BUSWIDTH_16, devkit8000_nand_partitions,
ARRAY_SIZE(devkit8000_nand_partitions));
omap_mux_init_signal("sdrc_cke0", OMAP_PIN_OUTPUT);
omap_mux_init_signal("sdrc_cke1", OMAP_PIN_OUTPUT);
}
