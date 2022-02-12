void __init eukrea_mbimxsd51_baseboard_init(void)
{
if (mxc_iomux_v3_setup_multiple_pads(eukrea_mbimxsd_pads,
ARRAY_SIZE(eukrea_mbimxsd_pads)))
printk(KERN_ERR "error setting mbimxsd pads !\n");
imx51_add_imx_uart(1, NULL);
imx51_add_imx_uart(2, &uart_pdata);
imx51_add_sdhci_esdhc_imx(0, NULL);
gpio_request(GPIO_LED1, "LED1");
gpio_direction_output(GPIO_LED1, 1);
gpio_free(GPIO_LED1);
gpio_request(GPIO_SWITCH1, "SWITCH1");
gpio_direction_input(GPIO_SWITCH1);
gpio_free(GPIO_SWITCH1);
i2c_register_board_info(0, eukrea_mbimxsd_i2c_devices,
ARRAY_SIZE(eukrea_mbimxsd_i2c_devices));
gpio_led_register_device(-1, &eukrea_mbimxsd_led_info);
imx_add_gpio_keys(&eukrea_mbimxsd_button_data);
}
