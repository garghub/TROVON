static void __init cns3420_early_serial_setup(void)
{
#ifdef CONFIG_SERIAL_8250_CONSOLE
static struct uart_port cns3420_serial_port = {
.membase = (void __iomem *)CNS3XXX_UART0_BASE_VIRT,
.mapbase = CNS3XXX_UART0_BASE,
.irq = IRQ_CNS3XXX_UART0,
.iotype = UPIO_MEM,
.flags = UPF_BOOT_AUTOCONF | UPF_FIXED_TYPE,
.regshift = 2,
.uartclk = 24000000,
.line = 0,
.type = PORT_16550A,
.fifosize = 16,
};
early_serial_setup(&cns3420_serial_port);
#endif
}
static void __init cns3420_init(void)
{
platform_add_devices(cns3420_pdevs, ARRAY_SIZE(cns3420_pdevs));
cns3xxx_ahci_init();
cns3xxx_sdhci_init();
pm_power_off = cns3xxx_power_off;
}
static void __init cns3420_map_io(void)
{
cns3xxx_map_io();
iotable_init(cns3420_io_desc, ARRAY_SIZE(cns3420_io_desc));
cns3420_early_serial_setup();
}
