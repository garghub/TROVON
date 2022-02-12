static int __devinit check_name(char *name)
{
char **tmp;
for (tmp = modem_names; *tmp; tmp++)
if (strstr(name, *tmp))
return 1;
return 0;
}
static int __devinit check_resources(struct pnp_dev *dev)
{
resource_size_t base[] = {0x2f8, 0x3f8, 0x2e8, 0x3e8};
int i;
for (i = 0; i < ARRAY_SIZE(base); i++) {
if (pnp_possible_config(dev, IORESOURCE_IO, base[i], 8))
return 1;
}
return 0;
}
static int __devinit serial_pnp_guess_board(struct pnp_dev *dev, int *flags)
{
if (!(check_name(pnp_dev_name(dev)) ||
(dev->card && check_name(dev->card->name))))
return -ENODEV;
if (check_resources(dev))
return 0;
return -ENODEV;
}
static int __devinit
serial_pnp_probe(struct pnp_dev *dev, const struct pnp_device_id *dev_id)
{
struct uart_port port;
int ret, line, flags = dev_id->driver_data;
if (flags & UNKNOWN_DEV) {
ret = serial_pnp_guess_board(dev, &flags);
if (ret < 0)
return ret;
}
memset(&port, 0, sizeof(struct uart_port));
if (pnp_irq_valid(dev, 0))
port.irq = pnp_irq(dev, 0);
if (pnp_port_valid(dev, 0)) {
port.iobase = pnp_port_start(dev, 0);
port.iotype = UPIO_PORT;
} else if (pnp_mem_valid(dev, 0)) {
port.mapbase = pnp_mem_start(dev, 0);
port.iotype = UPIO_MEM;
port.flags = UPF_IOREMAP;
} else
return -ENODEV;
#ifdef SERIAL_DEBUG_PNP
printk(KERN_DEBUG
"Setup PNP port: port %x, mem 0x%lx, irq %d, type %d\n",
port.iobase, port.mapbase, port.irq, port.iotype);
#endif
port.flags |= UPF_SKIP_TEST | UPF_BOOT_AUTOCONF;
if (pnp_irq_flags(dev, 0) & IORESOURCE_IRQ_SHAREABLE)
port.flags |= UPF_SHARE_IRQ;
port.uartclk = 1843200;
port.dev = &dev->dev;
line = serial8250_register_port(&port);
if (line < 0)
return -ENODEV;
pnp_set_drvdata(dev, (void *)((long)line + 1));
return 0;
}
static void __devexit serial_pnp_remove(struct pnp_dev *dev)
{
long line = (long)pnp_get_drvdata(dev);
if (line)
serial8250_unregister_port(line - 1);
}
static int serial_pnp_suspend(struct pnp_dev *dev, pm_message_t state)
{
long line = (long)pnp_get_drvdata(dev);
if (!line)
return -ENODEV;
serial8250_suspend_port(line - 1);
return 0;
}
static int serial_pnp_resume(struct pnp_dev *dev)
{
long line = (long)pnp_get_drvdata(dev);
if (!line)
return -ENODEV;
serial8250_resume_port(line - 1);
return 0;
}
static int __init serial8250_pnp_init(void)
{
return pnp_register_driver(&serial_pnp_driver);
}
static void __exit serial8250_pnp_exit(void)
{
pnp_unregister_driver(&serial_pnp_driver);
}
