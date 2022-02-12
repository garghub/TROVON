static void __init vision_map_io(void)
{
ep93xx_map_io();
iotable_init(vision_io_desc, ARRAY_SIZE(vision_io_desc));
}
static int vision_lcd_setup(struct platform_device *pdev)
{
int err;
err = gpio_request_one(VISION_LCD_ENABLE, GPIOF_INIT_HIGH,
dev_name(&pdev->dev));
if (err)
return err;
ep93xx_devcfg_clear_bits(EP93XX_SYSCON_DEVCFG_RAS |
EP93XX_SYSCON_DEVCFG_RASONP3 |
EP93XX_SYSCON_DEVCFG_EXVC);
return 0;
}
static void vision_lcd_teardown(struct platform_device *pdev)
{
gpio_free(VISION_LCD_ENABLE);
}
static void vision_lcd_blank(int blank_mode, struct fb_info *info)
{
if (blank_mode)
gpio_set_value(VISION_LCD_ENABLE, 0);
else
gpio_set_value(VISION_LCD_ENABLE, 1);
}
static void __init vision_register_i2s(void)
{
ep93xx_register_i2s();
platform_device_register(&vision_audio_device);
}
static void __init vision_init_machine(void)
{
ep93xx_init_devices();
ep93xx_register_flash(2, EP93XX_CS6_PHYS_BASE, SZ_64M);
ep93xx_register_eth(&vision_eth_data, 1);
ep93xx_register_fb(&ep93xxfb_info);
ep93xx_register_pwm(1, 0);
if (gpio_request_one(EP93XX_GPIO_LINE_F(7), GPIOF_DIR_IN,
"pca9539:74"))
pr_warn("cannot request interrupt gpio for pca9539:74\n");
vision_i2c_info[1].irq = gpio_to_irq(EP93XX_GPIO_LINE_F(7));
ep93xx_register_i2c(&vision_i2c_gpio_data, vision_i2c_info,
ARRAY_SIZE(vision_i2c_info));
ep93xx_register_spi(&vision_spi_master, vision_spi_board_info,
ARRAY_SIZE(vision_spi_board_info));
vision_register_i2s();
}
