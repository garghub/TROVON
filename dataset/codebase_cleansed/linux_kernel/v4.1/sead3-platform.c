static int __init sead3_platforms_device_init(void)
{
if (gic_present) {
uart8250_data[0].irq = MIPS_GIC_IRQ_BASE + GIC_INT_UART0;
uart8250_data[1].irq = MIPS_GIC_IRQ_BASE + GIC_INT_UART1;
ehci_resources[1].start = MIPS_GIC_IRQ_BASE + GIC_INT_EHCI;
sead3_net_resources[1].start = MIPS_GIC_IRQ_BASE + GIC_INT_NET;
} else {
uart8250_data[0].irq = MIPS_CPU_IRQ_BASE + CPU_INT_UART0;
uart8250_data[1].irq = MIPS_CPU_IRQ_BASE + CPU_INT_UART1;
ehci_resources[1].start = MIPS_CPU_IRQ_BASE + CPU_INT_EHCI;
sead3_net_resources[1].start = MIPS_CPU_IRQ_BASE + CPU_INT_NET;
}
return platform_add_devices(sead3_platform_devices,
ARRAY_SIZE(sead3_platform_devices));
}
