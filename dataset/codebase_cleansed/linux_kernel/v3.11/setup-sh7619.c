static int __init sh7619_devices_setup(void)
{
return platform_add_devices(sh7619_devices,
ARRAY_SIZE(sh7619_devices));
}
void __init plat_irq_setup(void)
{
register_intc_controller(&intc_desc);
}
void __init plat_early_device_setup(void)
{
__raw_writeb(__raw_readb(STBCR3) & ~0x10, STBCR3);
early_platform_add_devices(sh7619_early_devices,
ARRAY_SIZE(sh7619_early_devices));
}
