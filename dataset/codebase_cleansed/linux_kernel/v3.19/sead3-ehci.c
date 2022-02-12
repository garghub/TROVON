static int __init ehci_init(void)
{
if (gic_present)
ehci_resources[1].start = MIPS_GIC_IRQ_BASE + GIC_INT_EHCI;
else
ehci_resources[1].start = MIPS_CPU_IRQ_BASE + CPU_INT_EHCI;
return platform_device_register(&ehci_device);
}
