static int __init sh7710_devices_setup(void)
{
return platform_add_devices(sh7710_devices,
ARRAY_SIZE(sh7710_devices));
}
void __init plat_early_device_setup(void)
{
early_platform_add_devices(sh7710_early_devices,
ARRAY_SIZE(sh7710_early_devices));
}
void __init plat_irq_setup(void)
{
register_intc_controller(&intc_desc);
plat_irq_setup_sh3();
}
