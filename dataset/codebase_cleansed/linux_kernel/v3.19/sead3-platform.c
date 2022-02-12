static int __init uart8250_init(void)
{
if (gic_present) {
uart8250_data[0].irq = MIPS_GIC_IRQ_BASE + GIC_INT_UART0;
uart8250_data[1].irq = MIPS_GIC_IRQ_BASE + GIC_INT_UART1;
} else {
uart8250_data[0].irq = MIPS_CPU_IRQ_BASE + CPU_INT_UART0;
uart8250_data[1].irq = MIPS_CPU_IRQ_BASE + CPU_INT_UART1;
}
return platform_device_register(&uart8250_device);
}
