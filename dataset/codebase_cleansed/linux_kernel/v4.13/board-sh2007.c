static int __init sh2007_io_init(void)
{
regulator_register_fixed(0, dummy_supplies, ARRAY_SIZE(dummy_supplies));
platform_add_devices(sh2007_devices, ARRAY_SIZE(sh2007_devices));
return 0;
}
static void __init sh2007_init_irq(void)
{
plat_irq_setup_pins(IRQ_MODE_IRQ);
}
static void __init sh2007_setup(char **cmdline_p)
{
printk(KERN_INFO "SH-2007 Setup...");
__raw_writel(CS5BCR_D, CS5BCR);
__raw_writel(CS5WCR_D, CS5WCR);
__raw_writel(CS5PCR_D, CS5PCR);
printk(KERN_INFO " done.\n");
}
