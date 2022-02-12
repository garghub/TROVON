static int __init serial_init(void)
{
int i;
unsigned char iotype;
iotype = uart8250_data[mips_machtype][0].iotype;
if (UPIO_MEM == iotype) {
uart8250_data[mips_machtype][0].mapbase =
loongson_uart_base[0];
uart8250_data[mips_machtype][0].membase =
(void __iomem *)_loongson_uart_base[0];
}
else if (UPIO_PORT == iotype)
uart8250_data[mips_machtype][0].iobase =
loongson_uart_base[0] - LOONGSON_PCIIO_BASE;
if (loongson_sysconf.uarts[0].uartclk)
uart8250_data[mips_machtype][0].uartclk =
loongson_sysconf.uarts[0].uartclk;
for (i = 1; i < loongson_sysconf.nr_uarts; i++) {
iotype = loongson_sysconf.uarts[i].iotype;
uart8250_data[mips_machtype][i].iotype = iotype;
loongson_uart_base[i] = loongson_sysconf.uarts[i].uart_base;
if (UPIO_MEM == iotype) {
uart8250_data[mips_machtype][i].irq =
MIPS_CPU_IRQ_BASE + loongson_sysconf.uarts[i].int_offset;
uart8250_data[mips_machtype][i].mapbase =
loongson_uart_base[i];
uart8250_data[mips_machtype][i].membase =
ioremap_nocache(loongson_uart_base[i], 8);
} else if (UPIO_PORT == iotype) {
uart8250_data[mips_machtype][i].irq =
loongson_sysconf.uarts[i].int_offset;
uart8250_data[mips_machtype][i].iobase =
loongson_uart_base[i] - LOONGSON_PCIIO_BASE;
}
uart8250_data[mips_machtype][i].uartclk =
loongson_sysconf.uarts[i].uartclk;
uart8250_data[mips_machtype][i].flags =
UPF_BOOT_AUTOCONF | UPF_SKIP_TEST;
}
memset(&uart8250_data[mips_machtype][loongson_sysconf.nr_uarts],
0, sizeof(struct plat_serial8250_port));
uart8250_device.dev.platform_data = uart8250_data[mips_machtype];
return platform_device_register(&uart8250_device);
}
