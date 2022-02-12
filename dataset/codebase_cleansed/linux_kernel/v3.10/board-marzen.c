static int usb_power_on(struct platform_device *pdev)
{
if (IS_ERR(phy))
return PTR_ERR(phy);
pm_runtime_enable(&pdev->dev);
pm_runtime_get_sync(&pdev->dev);
usb_phy_init(phy);
return 0;
}
static void usb_power_off(struct platform_device *pdev)
{
if (IS_ERR(phy))
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
pinctrl_register_mappings(marzen_pinctrl_map,
ARRAY_SIZE(marzen_pinctrl_map));
r8a7779_pinmux_init();
r8a7779_add_standard_devices();
platform_add_devices(marzen_devices, ARRAY_SIZE(marzen_devices));
}
