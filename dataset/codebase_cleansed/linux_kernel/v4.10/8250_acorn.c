static int
serial_card_probe(struct expansion_card *ec, const struct ecard_id *id)
{
struct serial_card_info *info;
struct serial_card_type *type = id->data;
struct uart_8250_port uart;
unsigned long bus_addr;
unsigned int i;
info = kzalloc(sizeof(struct serial_card_info), GFP_KERNEL);
if (!info)
return -ENOMEM;
info->num_ports = type->num_ports;
bus_addr = ecard_resource_start(ec, type->type);
info->vaddr = ecardm_iomap(ec, type->type, 0, 0);
if (!info->vaddr) {
kfree(info);
return -ENOMEM;
}
ecard_set_drvdata(ec, info);
memset(&uart, 0, sizeof(struct uart_8250_port));
uart.port.irq = ec->irq;
uart.port.flags = UPF_BOOT_AUTOCONF | UPF_SHARE_IRQ;
uart.port.uartclk = type->uartclk;
uart.port.iotype = UPIO_MEM;
uart.port.regshift = 2;
uart.port.dev = &ec->dev;
for (i = 0; i < info->num_ports; i++) {
uart.port.membase = info->vaddr + type->offset[i];
uart.port.mapbase = bus_addr + type->offset[i];
info->ports[i] = serial8250_register_8250_port(&uart);
}
return 0;
}
static void serial_card_remove(struct expansion_card *ec)
{
struct serial_card_info *info = ecard_get_drvdata(ec);
int i;
ecard_set_drvdata(ec, NULL);
for (i = 0; i < info->num_ports; i++)
if (info->ports[i] > 0)
serial8250_unregister_port(info->ports[i]);
kfree(info);
}
static int __init serial_card_init(void)
{
return ecard_register_driver(&serial_card_driver);
}
static void __exit serial_card_exit(void)
{
ecard_remove_driver(&serial_card_driver);
}
