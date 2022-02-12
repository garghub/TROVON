static int visstrim_m10_sdhc1_init(struct device *dev,
irq_handler_t detect_irq, void *data)
{
int ret;
ret = request_irq(SDHC1_IRQ, detect_irq, IRQF_TRIGGER_FALLING,
"mmc-detect", data);
return ret;
}
static void visstrim_m10_sdhc1_exit(struct device *dev, void *data)
{
free_irq(SDHC1_IRQ, data);
}
static int otg_phy_init(struct platform_device *pdev)
{
gpio_set_value(OTG_PHY_CS_GPIO, 0);
mdelay(10);
return mx27_initialize_usb_hw(pdev->id, MXC_EHCI_POWER_PINS_ENABLED);
}
static void __init visstrim_m10_board_init(void)
{
int ret;
imx27_soc_init();
ret = mxc_gpio_setup_multiple_pins(visstrim_m10_pins,
ARRAY_SIZE(visstrim_m10_pins), "VISSTRIM_M10");
if (ret)
pr_err("Failed to setup pins (%d)\n", ret);
imx27_add_imx_ssi(0, &visstrim_m10_ssi_pdata);
imx27_add_imx_uart0(&uart_pdata);
i2c_register_board_info(0, visstrim_m10_i2c_devices,
ARRAY_SIZE(visstrim_m10_i2c_devices));
imx27_add_imx_i2c(0, &visstrim_m10_i2c_data);
imx27_add_imx_i2c(1, &visstrim_m10_i2c_data);
imx27_add_mxc_mmc(0, &visstrim_m10_sdhc_pdata);
imx27_add_mxc_ehci_otg(&visstrim_m10_usbotg_pdata);
imx27_add_fec(NULL);
imx_add_gpio_keys(&visstrim_gpio_keys_platform_data);
platform_add_devices(platform_devices, ARRAY_SIZE(platform_devices));
}
static void __init visstrim_m10_timer_init(void)
{
mx27_clocks_init((unsigned long)25000000);
}
