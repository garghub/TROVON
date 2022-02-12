static int usb_power_on(struct platform_device *pdev)
{
if (!phy)
return -EIO;
pm_runtime_enable(&pdev->dev);
pm_runtime_get_sync(&pdev->dev);
usb_phy_init(phy);
return 0;
}
static void usb_power_off(struct platform_device *pdev)
{
if (!phy)
return;
usb_phy_shutdown(phy);
pm_runtime_put_sync(&pdev->dev);
pm_runtime_disable(&pdev->dev);
}
void __init marzen_init_late(void)
{
phy = usb_get_phy(USB_PHY_TYPE_USB2);
shmobile_init_late();
platform_add_devices(marzen_late_devices,
ARRAY_SIZE(marzen_late_devices));
}
static void __init marzen_init(void)
{
regulator_register_always_on(0, "fixed-3.3V", fixed3v3_power_consumers,
ARRAY_SIZE(fixed3v3_power_consumers), 3300000);
regulator_register_fixed(1, dummy_supplies,
ARRAY_SIZE(dummy_supplies));
r8a7779_pinmux_init();
gpio_request(GPIO_FN_TX2_C, NULL);
gpio_request(GPIO_FN_RX2_C, NULL);
gpio_request(GPIO_FN_TX4, NULL);
gpio_request(GPIO_FN_RX4, NULL);
gpio_request(GPIO_FN_EX_CS0, NULL);
gpio_request(GPIO_FN_IRQ1_B, NULL);
gpio_request(GPIO_FN_SD0_CLK, NULL);
gpio_request(GPIO_FN_SD0_CMD, NULL);
gpio_request(GPIO_FN_SD0_DAT0, NULL);
gpio_request(GPIO_FN_SD0_DAT1, NULL);
gpio_request(GPIO_FN_SD0_DAT2, NULL);
gpio_request(GPIO_FN_SD0_DAT3, NULL);
gpio_request(GPIO_FN_SD0_CD, NULL);
gpio_request(GPIO_FN_SD0_WP, NULL);
gpio_request(GPIO_FN_HSPI_CLK0, NULL);
gpio_request(GPIO_FN_HSPI_CS0, NULL);
gpio_request(GPIO_FN_HSPI_TX0, NULL);
gpio_request(GPIO_FN_HSPI_RX0, NULL);
gpio_request(GPIO_FN_USB_OVC0, NULL);
gpio_request(GPIO_FN_USB_OVC1, NULL);
gpio_request(GPIO_FN_USB_OVC2, NULL);
gpio_request(GPIO_FN_USB_PENC2, NULL);
r8a7779_add_standard_devices();
platform_add_devices(marzen_devices, ARRAY_SIZE(marzen_devices));
}
