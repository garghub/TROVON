int __init hp300_setup_serial_console(void)
{
int scode;
struct uart_port port;
memset(&port, 0, sizeof(port));
if (hp300_uart_scode < 0 || hp300_uart_scode > DIO_SCMAX)
return 0;
if (DIO_SCINHOLE(hp300_uart_scode))
return 0;
scode = hp300_uart_scode;
port.iotype = UPIO_MEM;
port.flags = UPF_SKIP_TEST | UPF_SHARE_IRQ | UPF_BOOT_AUTOCONF;
port.type = PORT_UNKNOWN;
if (scode == 256) {
#ifdef CONFIG_HPAPCI
printk(KERN_INFO "Serial console is HP APCI 1\n");
port.uartclk = HPAPCI_BAUD_BASE * 16;
port.mapbase = (FRODO_BASE + FRODO_APCI_OFFSET(1));
port.membase = (char *)(port.mapbase + DIO_VIRADDRBASE);
port.regshift = 2;
add_preferred_console("ttyS", port.line, "9600n8");
#else
printk(KERN_WARNING "Serial console is APCI but support is disabled (CONFIG_HPAPCI)!\n");
return 0;
#endif
} else {
#ifdef CONFIG_HPDCA
unsigned long pa = dio_scodetophysaddr(scode);
if (!pa)
return 0;
printk(KERN_INFO "Serial console is HP DCA at select code %d\n", scode);
port.uartclk = HPDCA_BAUD_BASE * 16;
port.mapbase = (pa + UART_OFFSET);
port.membase = (char *)(port.mapbase + DIO_VIRADDRBASE);
port.regshift = 1;
port.irq = DIO_IPL(pa + DIO_VIRADDRBASE);
out_8(pa + DIO_VIRADDRBASE + DCA_IC, DCA_IC_IE);
if (DIO_ID(pa + DIO_VIRADDRBASE) & 0x80)
add_preferred_console("ttyS", port.line, "9600n8");
#else
printk(KERN_WARNING "Serial console is DCA but support is disabled (CONFIG_HPDCA)!\n");
return 0;
#endif
}
if (early_serial_setup(&port) < 0)
printk(KERN_WARNING "hp300_setup_serial_console(): early_serial_setup() failed.\n");
return 0;
}
static int hpdca_init_one(struct dio_dev *d,
const struct dio_device_id *ent)
{
struct uart_8250_port uart;
int line;
#ifdef CONFIG_SERIAL_8250_CONSOLE
if (hp300_uart_scode == d->scode) {
return 0;
}
#endif
memset(&uart, 0, sizeof(uart));
uart.port.iotype = UPIO_MEM;
uart.port.flags = UPF_SKIP_TEST | UPF_SHARE_IRQ | UPF_BOOT_AUTOCONF;
uart.port.irq = d->ipl;
uart.port.uartclk = HPDCA_BAUD_BASE * 16;
uart.port.mapbase = (d->resource.start + UART_OFFSET);
uart.port.membase = (char *)(uart.port.mapbase + DIO_VIRADDRBASE);
uart.port.regshift = 1;
uart.port.dev = &d->dev;
line = serial8250_register_8250_port(&uart);
if (line < 0) {
printk(KERN_NOTICE "8250_hp300: register_serial() DCA scode %d"
" irq %d failed\n", d->scode, uart.port.irq);
return -ENOMEM;
}
out_8(d->resource.start + DIO_VIRADDRBASE + DCA_IC, DCA_IC_IE);
dio_set_drvdata(d, (void *)line);
out_8(d->resource.start + DIO_VIRADDRBASE + DCA_ID, 0xff);
udelay(100);
num_ports++;
return 0;
}
static int __init hp300_8250_init(void)
{
static int called;
#ifdef CONFIG_HPAPCI
int line;
unsigned long base;
struct uart_8250_port uart;
struct hp300_port *port;
int i;
#endif
if (called)
return -ENODEV;
called = 1;
if (!MACH_IS_HP300)
return -ENODEV;
#ifdef CONFIG_HPDCA
dio_register_driver(&hpdca_driver);
#endif
#ifdef CONFIG_HPAPCI
if (hp300_model < HP_400) {
if (!num_ports)
return -ENODEV;
return 0;
}
for (i = 1; i < 4; i++) {
#ifdef CONFIG_SERIAL_8250_CONSOLE
if (i == 1)
continue;
#endif
port = kmalloc(sizeof(struct hp300_port), GFP_KERNEL);
if (!port)
return -ENOMEM;
memset(&uart, 0, sizeof(uart));
base = (FRODO_BASE + FRODO_APCI_OFFSET(i));
uart.port.iotype = UPIO_MEM;
uart.port.flags = UPF_SKIP_TEST | UPF_SHARE_IRQ \
| UPF_BOOT_AUTOCONF;
uart.port.irq = 0;
uart.port.uartclk = HPAPCI_BAUD_BASE * 16;
uart.port.mapbase = base;
uart.port.membase = (char *)(base + DIO_VIRADDRBASE);
uart.port.regshift = 2;
line = serial8250_register_8250_port(&uart);
if (line < 0) {
printk(KERN_NOTICE "8250_hp300: register_serial() APCI"
" %d irq %d failed\n", i, uart.port.irq);
kfree(port);
continue;
}
port->line = line;
port->next = hp300_ports;
hp300_ports = port;
num_ports++;
}
#endif
if (!num_ports)
return -ENODEV;
return 0;
}
static void hpdca_remove_one(struct dio_dev *d)
{
int line;
line = (int) dio_get_drvdata(d);
if (d->resource.start) {
out_8(d->resource.start + DIO_VIRADDRBASE + DCA_IC, 0);
}
serial8250_unregister_port(line);
}
static void __exit hp300_8250_exit(void)
{
#ifdef CONFIG_HPAPCI
struct hp300_port *port, *to_free;
for (port = hp300_ports; port; ) {
serial8250_unregister_port(port->line);
to_free = port;
port = port->next;
kfree(to_free);
}
hp300_ports = NULL;
#endif
#ifdef CONFIG_HPDCA
dio_unregister_driver(&hpdca_driver);
#endif
}
