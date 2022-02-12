static void eukrea_mbimxsd_lcd_power_set(struct plat_lcd_data *pd,
unsigned int power)
{
if (power)
gpio_direction_output(GPIO_LCDPWR, 1);
else
gpio_direction_output(GPIO_LCDPWR, 0);
}
void __init eukrea_mbimxsd35_baseboard_init(void)
{
if (mxc_iomux_v3_setup_multiple_pads(eukrea_mbimxsd_pads,
ARRAY_SIZE(eukrea_mbimxsd_pads)))
printk(KERN_ERR "error setting mbimxsd pads !\n");
imx35_add_imx_uart1(&uart_pdata);
imx35_add_ipu_core(&mx3_ipu_data);
imx35_add_mx3_sdc_fb(&mx3fb_pdata);
imx35_add_imx_ssi(0, &eukrea_mbimxsd_ssi_pdata);
imx35_add_flexcan1(NULL);
imx35_add_sdhci_esdhc_imx(0, &sd1_pdata);
gpio_request(GPIO_LED1, "LED1");
gpio_direction_output(GPIO_LED1, 1);
gpio_free(GPIO_LED1);
gpio_request(GPIO_SWITCH1, "SWITCH1");
gpio_direction_input(GPIO_SWITCH1);
gpio_free(GPIO_SWITCH1);
gpio_request(GPIO_LCDPWR, "LCDPWR");
gpio_direction_output(GPIO_LCDPWR, 1);
i2c_register_board_info(0, eukrea_mbimxsd_i2c_devices,
ARRAY_SIZE(eukrea_mbimxsd_i2c_devices));
platform_add_devices(platform_devices, ARRAY_SIZE(platform_devices));
gpio_led_register_device(-1, &eukrea_mbimxsd_led_info);
imx_add_gpio_keys(&eukrea_mbimxsd_button_data);
}
