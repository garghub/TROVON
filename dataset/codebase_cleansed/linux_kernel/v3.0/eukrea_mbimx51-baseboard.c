static int tsc2007_get_pendown_state(void)
{
return !gpio_get_value(MBIMX51_TSC2007_GPIO);
}
void __init eukrea_mbimx51_baseboard_init(void)
{
mxc_iomux_v3_setup_multiple_pads(mbimx51_pads,
ARRAY_SIZE(mbimx51_pads));
imx51_add_imx_uart(1, NULL);
imx51_add_imx_uart(2, &uart_pdata);
gpio_request(MBIMX51_LED0, "LED0");
gpio_direction_output(MBIMX51_LED0, 1);
gpio_free(MBIMX51_LED0);
gpio_request(MBIMX51_LED1, "LED1");
gpio_direction_output(MBIMX51_LED1, 1);
gpio_free(MBIMX51_LED1);
gpio_request(MBIMX51_LED2, "LED2");
gpio_direction_output(MBIMX51_LED2, 1);
gpio_free(MBIMX51_LED2);
gpio_request(MBIMX51_LED3, "LED3");
gpio_direction_output(MBIMX51_LED3, 1);
gpio_free(MBIMX51_LED3);
platform_add_devices(devices, ARRAY_SIZE(devices));
imx51_add_imx_keypad(&mbimx51_map_data);
gpio_request(MBIMX51_TSC2007_GPIO, "tsc2007_irq");
gpio_direction_input(MBIMX51_TSC2007_GPIO);
irq_set_irq_type(MBIMX51_TSC2007_IRQ, IRQF_TRIGGER_FALLING);
i2c_register_board_info(1, mbimx51_i2c_devices,
ARRAY_SIZE(mbimx51_i2c_devices));
imx51_add_sdhci_esdhc_imx(0, NULL);
imx51_add_sdhci_esdhc_imx(1, NULL);
}
