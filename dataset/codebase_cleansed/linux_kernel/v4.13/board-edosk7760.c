static int __init init_edosk7760_devices(void)
{
plat_irq_setup_pins(IRQ_MODE_IRQ);
return platform_add_devices(edosk7760_devices,
ARRAY_SIZE(edosk7760_devices));
}
