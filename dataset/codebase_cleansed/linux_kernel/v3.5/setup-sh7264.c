static void usb_port_power(int port, int power)
{
__raw_writew(0x200 , 0xffffc0c2) ;
}
static int __init sh7264_devices_setup(void)
{
return platform_add_devices(sh7264_devices,
ARRAY_SIZE(sh7264_devices));
}
void __init plat_irq_setup(void)
{
register_intc_controller(&intc_desc);
}
void __init plat_early_device_setup(void)
{
early_platform_add_devices(sh7264_early_devices,
ARRAY_SIZE(sh7264_early_devices));
}
