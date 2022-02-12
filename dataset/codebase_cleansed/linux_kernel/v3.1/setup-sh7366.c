static int __init sh7366_devices_setup(void)
{
platform_resource_setup_memory(&vpu_device, "vpu", 2 << 20);
platform_resource_setup_memory(&veu0_device, "veu0", 2 << 20);
platform_resource_setup_memory(&veu1_device, "veu1", 2 << 20);
return platform_add_devices(sh7366_devices,
ARRAY_SIZE(sh7366_devices));
}
void __init plat_early_device_setup(void)
{
early_platform_add_devices(sh7366_early_devices,
ARRAY_SIZE(sh7366_early_devices));
}
void __init plat_irq_setup(void)
{
register_intc_controller(&intc_desc);
}
void __init plat_mem_setup(void)
{
}
