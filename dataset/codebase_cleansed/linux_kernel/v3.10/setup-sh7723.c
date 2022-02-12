static int __init sh7723_devices_setup(void)
{
platform_resource_setup_memory(&vpu_device, "vpu", 2 << 20);
platform_resource_setup_memory(&veu0_device, "veu0", 2 << 20);
platform_resource_setup_memory(&veu1_device, "veu1", 2 << 20);
return platform_add_devices(sh7723_devices,
ARRAY_SIZE(sh7723_devices));
}
void __init plat_early_device_setup(void)
{
early_platform_add_devices(sh7723_early_devices,
ARRAY_SIZE(sh7723_early_devices));
}
void l2_cache_init(void)
{
__raw_writel(L2_CACHE_ENABLE, RAMCR);
}
void __init plat_irq_setup(void)
{
register_intc_controller(&intc_desc);
}
