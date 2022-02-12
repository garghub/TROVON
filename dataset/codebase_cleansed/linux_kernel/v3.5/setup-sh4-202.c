static int __init sh4202_devices_setup(void)
{
return platform_add_devices(sh4202_devices,
ARRAY_SIZE(sh4202_devices));
}
void __init plat_early_device_setup(void)
{
early_platform_add_devices(sh4202_early_devices,
ARRAY_SIZE(sh4202_early_devices));
}
void __init plat_irq_setup(void)
{
register_intc_controller(&intc_desc);
}
void __init plat_irq_setup_pins(int mode)
{
switch (mode) {
case IRQ_MODE_IRQ:
__raw_writew(__raw_readw(INTC_ICR) | INTC_ICR_IRLM, INTC_ICR);
register_intc_controller(&intc_desc_irlm);
break;
default:
BUG();
}
}
