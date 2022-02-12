static int __init sh7760_devices_setup(void)
{
return platform_add_devices(sh7760_devices,
ARRAY_SIZE(sh7760_devices));
}
void __init plat_early_device_setup(void)
{
early_platform_add_devices(sh7760_early_devices,
ARRAY_SIZE(sh7760_early_devices));
}
void __init plat_irq_setup_pins(int mode)
{
switch (mode) {
case IRQ_MODE_IRQ:
__raw_writew(__raw_readw(INTC_ICR) | INTC_ICR_IRLM, INTC_ICR);
register_intc_controller(&intc_desc_irq);
break;
default:
BUG();
}
}
void __init plat_irq_setup(void)
{
register_intc_controller(&intc_desc);
}
