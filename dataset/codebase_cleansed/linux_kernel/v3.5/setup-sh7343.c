static int __init sh7343_devices_setup(void)
{
platform_resource_setup_memory(&vpu_device, "vpu", 1 << 20);
platform_resource_setup_memory(&veu_device, "veu", 2 << 20);
platform_resource_setup_memory(&jpu_device, "jpu", 2 << 20);
return platform_add_devices(sh7343_devices,
ARRAY_SIZE(sh7343_devices));
}
void __init plat_early_device_setup(void)
{
early_platform_add_devices(sh7343_early_devices,
ARRAY_SIZE(sh7343_early_devices));
}
void __init plat_irq_setup(void)
{
register_intc_controller(&intc_desc);
}
