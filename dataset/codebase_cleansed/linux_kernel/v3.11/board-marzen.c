static void __init marzen_init(void)
{
regulator_register_always_on(0, "fixed-3.3V", fixed3v3_power_consumers,
ARRAY_SIZE(fixed3v3_power_consumers), 3300000);
regulator_register_fixed(1, dummy_supplies,
ARRAY_SIZE(dummy_supplies));
pinctrl_register_mappings(marzen_pinctrl_map,
ARRAY_SIZE(marzen_pinctrl_map));
r8a7779_pinmux_init();
r8a7779_init_irq_extpin(1);
r8a7779_add_standard_devices();
r8a7779_add_usb_phy_device(&usb_phy_platform_data);
platform_add_devices(marzen_devices, ARRAY_SIZE(marzen_devices));
}
