static void eukrea_mbimx27_bl_set_intensity(int intensity)
{
if (intensity)
gpio_direction_output(GPIO_PORTE | 5, 1);
else
gpio_direction_output(GPIO_PORTE | 5, 0);
}
static void eukrea_mbimx27_lcd_power_set(struct plat_lcd_data *pd,
unsigned int power)
{
if (power)
gpio_direction_output(GPIO_PORTA | 25, 1);
else
gpio_direction_output(GPIO_PORTA | 25, 0);
}
static void __maybe_unused ads7846_dev_init(void)
{
if (gpio_request(ADS7846_PENDOWN, "ADS7846 pendown") < 0) {
printk(KERN_ERR "can't get ads746 pen down GPIO\n");
return;
}
gpio_direction_input(ADS7846_PENDOWN);
}
static int ads7846_get_pendown_state(void)
{
return !gpio_get_value(ADS7846_PENDOWN);
}
void __init eukrea_mbimx27_baseboard_init(void)
{
mxc_gpio_setup_multiple_pins(eukrea_mbimx27_pins,
ARRAY_SIZE(eukrea_mbimx27_pins), "MBIMX27");
imx27_add_imx_uart1(&uart_pdata);
imx27_add_imx_uart2(&uart_pdata);
#if !defined(MACH_EUKREA_CPUIMX27_USEUART4)
imx27_add_imx_uart3(&uart_pdata);
#endif
imx27_add_imx_fb(&eukrea_mbimx27_fb_data);
imx27_add_mxc_mmc(0, &sdhc_pdata);
i2c_register_board_info(0, eukrea_mbimx27_i2c_devices,
ARRAY_SIZE(eukrea_mbimx27_i2c_devices));
imx27_add_imx_ssi(0, &eukrea_mbimx27_ssi_pdata);
#if defined(CONFIG_TOUCHSCREEN_ADS7846) \
|| defined(CONFIG_TOUCHSCREEN_ADS7846_MODULE)
mxc_gpio_mode(GPIO_PORTD | 25 | GPIO_GPIO | GPIO_IN);
ads7846_dev_init();
#endif
mxc_gpio_mode(GPIO_PORTD | 28 | GPIO_GPIO | GPIO_OUT);
imx27_add_spi_imx0(&eukrea_mbimx27_spi0_data);
spi_register_board_info(eukrea_mbimx27_spi_board_info,
ARRAY_SIZE(eukrea_mbimx27_spi_board_info));
mxc_gpio_mode(GPIO_PORTF | 16 | GPIO_GPIO | GPIO_OUT);
mxc_gpio_mode(GPIO_PORTF | 19 | GPIO_GPIO | GPIO_OUT);
mxc_gpio_mode(GPIO_PORTE | 5 | GPIO_GPIO | GPIO_OUT);
gpio_request(GPIO_PORTE | 5, "backlight");
platform_device_register(&eukrea_mbimx27_bl_dev);
mxc_gpio_mode(GPIO_PORTA | 25 | GPIO_GPIO | GPIO_OUT);
gpio_request(GPIO_PORTA | 25, "lcd_enable");
platform_device_register(&eukrea_mbimx27_lcd_powerdev);
imx27_add_imx_keypad(&eukrea_mbimx27_keymap_data);
gpio_led_register_device(-1, &eukrea_mbimx27_gpio_led_info);
}
