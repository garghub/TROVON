static void lsxl_power_off(void)
{
kirkwood_restart('h', NULL);
}
void __init lsxl_init(void)
{
kirkwood_mpp_conf(lsxl_mpp_config);
gpio_set_value(LSXL_GPIO_USB_POWER, 1);
gpio_set_value(LSXL_GPIO_HDD_POWER, 1);
kirkwood_ehci_init();
kirkwood_ge00_init(&lsxl_ge00_data);
kirkwood_ge01_init(&lsxl_ge01_data);
platform_device_register(&lsxl_fan_device);
pm_power_off = lsxl_power_off;
}
