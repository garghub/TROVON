static int __init serial_init(void)
{
unsigned char iotype;
iotype = uart8250_data[mips_machtype][0].iotype;
if (UPIO_MEM == iotype)
uart8250_data[mips_machtype][0].membase =
(void __iomem *)_loongson_uart_base;
else if (UPIO_PORT == iotype)
uart8250_data[mips_machtype][0].iobase =
loongson_uart_base - LOONGSON_PCIIO_BASE;
uart8250_device.dev.platform_data = uart8250_data[mips_machtype];
return platform_device_register(&uart8250_device);
}
