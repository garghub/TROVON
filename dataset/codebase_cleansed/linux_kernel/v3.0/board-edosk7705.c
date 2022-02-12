static void __init sh_edosk7705_init_irq(void)
{
make_imask_irq(ETHERNET_IRQ);
}
static int __init init_edosk7705_devices(void)
{
return platform_add_devices(edosk7705_devices,
ARRAY_SIZE(edosk7705_devices));
}
