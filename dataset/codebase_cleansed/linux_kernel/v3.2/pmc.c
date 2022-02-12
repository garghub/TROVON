static void pmc_swift_idle(void)
{
#ifdef PMC_DEBUG_LED
set_auxio(0x00, AUXIO_LED);
#endif
pmc_writeb(pmc_readb(PMC_IDLE_REG) | PMC_IDLE_ON, PMC_IDLE_REG);
#ifdef PMC_DEBUG_LED
set_auxio(AUXIO_LED, 0x00);
#endif
}
static int __devinit pmc_probe(struct platform_device *op)
{
regs = of_ioremap(&op->resource[0], 0,
resource_size(&op->resource[0]), PMC_OBPNAME);
if (!regs) {
printk(KERN_ERR "%s: unable to map registers\n", PMC_DEVNAME);
return -ENODEV;
}
#ifndef PMC_NO_IDLE
pm_idle = pmc_swift_idle;
#endif
printk(KERN_INFO "%s: power management initialized\n", PMC_DEVNAME);
return 0;
}
static int __init pmc_init(void)
{
return platform_driver_register(&pmc_driver);
}
