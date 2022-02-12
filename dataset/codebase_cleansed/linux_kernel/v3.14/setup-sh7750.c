static int __init sh7750_devices_setup(void)
{
if (mach_is_rts7751r2d()) {
platform_device_register(&scif_device);
} else {
platform_device_register(&sci_device);
platform_device_register(&scif_device);
}
return platform_add_devices(sh7750_devices,
ARRAY_SIZE(sh7750_devices));
}
void __init plat_early_device_setup(void)
{
struct platform_device *dev[1];
if (mach_is_rts7751r2d()) {
scif_platform_data.scscr |= SCSCR_CKE1;
dev[0] = &scif_device;
early_platform_add_devices(dev, 1);
} else {
dev[0] = &sci_device;
early_platform_add_devices(dev, 1);
dev[0] = &scif_device;
early_platform_add_devices(dev, 1);
}
early_platform_add_devices(sh7750_early_devices,
ARRAY_SIZE(sh7750_early_devices));
}
void __init plat_irq_setup(void)
{
register_intc_controller(&intc_desc);
register_intc_controller(&intc_desc_dma4);
}
void __init plat_irq_setup(void)
{
register_intc_controller(&intc_desc);
register_intc_controller(&intc_desc_dma8);
register_intc_controller(&intc_desc_tmu34);
}
void __init plat_irq_setup(void)
{
register_intc_controller(&intc_desc);
register_intc_controller(&intc_desc_dma4);
register_intc_controller(&intc_desc_tmu34);
register_intc_controller(&intc_desc_pci);
}
void __init plat_irq_setup(void)
{
register_intc_controller(&intc_desc);
register_intc_controller(&intc_desc_dma8);
register_intc_controller(&intc_desc_tmu34);
register_intc_controller(&intc_desc_pci);
}
void __init plat_irq_setup_pins(int mode)
{
#if defined(CONFIG_CPU_SUBTYPE_SH7750) || defined(CONFIG_CPU_SUBTYPE_SH7091)
BUG();
return;
#endif
switch (mode) {
case IRQ_MODE_IRQ:
__raw_writew(__raw_readw(INTC_ICR) | INTC_ICR_IRLM, INTC_ICR);
register_intc_controller(&intc_desc_irlm);
break;
default:
BUG();
}
}
