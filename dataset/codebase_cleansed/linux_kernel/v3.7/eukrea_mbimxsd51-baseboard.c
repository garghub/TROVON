static void eukrea_mbimxsd51_lcd_power_set(struct plat_lcd_data *pd,
unsigned int power)
{
if (power)
gpio_direction_output(GPIO_LCDRST, 1);
else
gpio_direction_output(GPIO_LCDRST, 0);
}
static void eukrea_mbimxsd51_bl_set_intensity(int intensity)
{
if (intensity)
gpio_direction_output(GPIO_LCDBL, 1);
else
gpio_direction_output(GPIO_LCDBL, 0);
}
static int __init eukrea_mbimxsd51_screen_type(char *options)
{
if (!strcmp(options, "dvi"))
screen_type = 1;
else if (!strcmp(options, "tft"))
screen_type = 0;
return 0;
}
void __init eukrea_mbimxsd51_baseboard_init(void)
{
if (mxc_iomux_v3_setup_multiple_pads(eukrea_mbimxsd51_pads,
ARRAY_SIZE(eukrea_mbimxsd51_pads)))
printk(KERN_ERR "error setting mbimxsd pads !\n");
imx51_add_imx_uart(1, NULL);
imx51_add_imx_uart(2, &uart_pdata);
imx51_add_sdhci_esdhc_imx(0, NULL);
imx51_add_imx_ssi(0, &eukrea_mbimxsd51_ssi_pdata);
gpio_request(GPIO_LED1, "LED1");
gpio_direction_output(GPIO_LED1, 1);
gpio_free(GPIO_LED1);
gpio_request(GPIO_SWITCH1, "SWITCH1");
gpio_direction_input(GPIO_SWITCH1);
gpio_free(GPIO_SWITCH1);
gpio_request(GPIO_LCDRST, "LCDRST");
gpio_direction_output(GPIO_LCDRST, 0);
gpio_request(GPIO_LCDBL, "LCDBL");
gpio_direction_output(GPIO_LCDBL, 0);
if (!screen_type) {
platform_device_register(&eukrea_mbimxsd51_bl_dev);
platform_device_register(&eukrea_mbimxsd51_lcd_powerdev);
} else {
gpio_free(GPIO_LCDRST);
gpio_free(GPIO_LCDBL);
}
i2c_register_board_info(0, eukrea_mbimxsd51_i2c_devices,
ARRAY_SIZE(eukrea_mbimxsd51_i2c_devices));
gpio_led_register_device(-1, &eukrea_mbimxsd51_led_info);
imx_add_gpio_keys(&eukrea_mbimxsd51_button_data);
imx_add_platform_device("eukrea_tlv320", 0, NULL, 0, NULL, 0);
}
