static int __init serial_init_chip(struct parisc_device *dev)
{
struct uart_port port;
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
memset(&port, 0, sizeof(port));
port.iotype = UPIO_MEM;
port.uartclk = 7272727;
port.mapbase = address;
port.membase = ioremap_nocache(address, 16);
port.irq = dev->irq;
port.flags = UPF_BOOT_AUTOCONF;
port.dev = &dev->dev;
err = serial8250_register_port(&port);
if (err < 0) {
printk(KERN_WARNING
"serial8250_register_port returned error %d\n", err);
iounmap(port.membase);
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
