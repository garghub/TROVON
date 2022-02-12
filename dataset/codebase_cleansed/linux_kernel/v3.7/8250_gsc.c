static int __init serial_init_chip(struct parisc_device *dev)
{
struct uart_8250_port uart;
unsigned long address;
int err;
if (!dev->irq) {
if (parisc_parent(dev)->id.hw_type != HPHW_IOA)
printk(KERN_INFO
"Serial: device 0x%llx not configured.\n"
"Enable support for Wax, Lasi, Asp or Dino.\n",
(unsigned long long)dev->hpa.start);
return -ENODEV;
}
address = dev->hpa.start;
if (dev->id.sversion != 0x8d)
address += 0x800;
memset(&uart, 0, sizeof(uart));
uart.port.iotype = UPIO_MEM;
uart.port.uartclk = 7272727;
uart.port.mapbase = address;
uart.port.membase = ioremap_nocache(address, 16);
uart.port.irq = dev->irq;
uart.port.flags = UPF_BOOT_AUTOCONF;
uart.port.dev = &dev->dev;
err = serial8250_register_8250_port(&uart);
if (err < 0) {
printk(KERN_WARNING
"serial8250_register_8250_port returned error %d\n", err);
iounmap(uart.port.membase);
return err;
}
return 0;
}
static int __init probe_serial_gsc(void)
{
register_parisc_driver(&lasi_driver);
register_parisc_driver(&serial_driver);
return 0;
}
