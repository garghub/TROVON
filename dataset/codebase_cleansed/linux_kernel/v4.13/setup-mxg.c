static int __init mxg_devices_setup(void)
{
return platform_add_devices(mxg_devices,
ARRAY_SIZE(mxg_devices));
}
void __init plat_irq_setup(void)
{
register_intc_controller(&intc_desc);
}
void __init plat_early_device_setup(void)
{
early_platform_add_devices(mxg_early_devices,
ARRAY_SIZE(mxg_early_devices));
}
