static int fintek_8250_enter_key(u16 base_port, u8 key)
{
if (!request_muxed_region(base_port, 2, DRIVER_NAME))
return -EBUSY;
outb(key, base_port + ADDR_PORT);
outb(key, base_port + ADDR_PORT);
return 0;
}
static void fintek_8250_exit_key(u16 base_port)
{
outb(EXIT_KEY, base_port + ADDR_PORT);
release_region(base_port + ADDR_PORT, 2);
}
static int fintek_8250_check_id(u16 base_port)
{
u16 chip;
outb(VENDOR_ID1, base_port + ADDR_PORT);
if (inb(base_port + DATA_PORT) != VENDOR_ID1_VAL)
return -ENODEV;
outb(VENDOR_ID2, base_port + ADDR_PORT);
if (inb(base_port + DATA_PORT) != VENDOR_ID2_VAL)
return -ENODEV;
outb(CHIP_ID1, base_port + ADDR_PORT);
chip = inb(base_port + DATA_PORT);
outb(CHIP_ID2, base_port + ADDR_PORT);
chip |= inb(base_port + DATA_PORT) << 8;
if (chip != CHIP_ID_0 && chip != CHIP_ID_1)
return -ENODEV;
return 0;
}
static int fintek_8250_rs485_config(struct uart_port *port,
struct serial_rs485 *rs485)
{
uint8_t config = 0;
struct fintek_8250 *pdata = port->private_data;
if (!pdata)
return -EINVAL;
if (rs485->flags & SER_RS485_ENABLED)
memset(rs485->padding, 0, sizeof(rs485->padding));
else
memset(rs485, 0, sizeof(*rs485));
rs485->flags &= SER_RS485_ENABLED | SER_RS485_RTS_ON_SEND |
SER_RS485_RTS_AFTER_SEND;
if (rs485->delay_rts_before_send) {
rs485->delay_rts_before_send = 1;
config |= TXW4C_IRA;
}
if (rs485->delay_rts_after_send) {
rs485->delay_rts_after_send = 1;
config |= RXW4C_IRA;
}
if ((!!(rs485->flags & SER_RS485_RTS_ON_SEND)) ==
(!!(rs485->flags & SER_RS485_RTS_AFTER_SEND)))
rs485->flags &= SER_RS485_ENABLED;
else
config |= RS485_URA;
if (rs485->flags & SER_RS485_RTS_ON_SEND)
config |= RTS_INVERT;
if (fintek_8250_enter_key(pdata->base_port, pdata->key))
return -EBUSY;
outb(LDN, pdata->base_port + ADDR_PORT);
outb(pdata->index, pdata->base_port + DATA_PORT);
outb(RS485, pdata->base_port + ADDR_PORT);
outb(config, pdata->base_port + DATA_PORT);
fintek_8250_exit_key(pdata->base_port);
port->rs485 = *rs485;
return 0;
}
static int fintek_8250_base_port(u16 io_address, u8 *key, u8 *index)
{
static const u16 addr[] = {0x4e, 0x2e};
static const u8 keys[] = {0x77, 0xa0, 0x87, 0x67};
int i, j, k;
for (i = 0; i < ARRAY_SIZE(addr); i++) {
for (j = 0; j < ARRAY_SIZE(keys); j++) {
if (fintek_8250_enter_key(addr[i], keys[j]))
continue;
if (fintek_8250_check_id(addr[i])) {
fintek_8250_exit_key(addr[i]);
continue;
}
for (k = 0; k < 4; k++) {
u16 aux;
outb(LDN, addr[i] + ADDR_PORT);
outb(k, addr[i] + DATA_PORT);
outb(IO_ADDR1, addr[i] + ADDR_PORT);
aux = inb(addr[i] + DATA_PORT);
outb(IO_ADDR2, addr[i] + ADDR_PORT);
aux |= inb(addr[i] + DATA_PORT) << 8;
if (aux != io_address)
continue;
fintek_8250_exit_key(addr[i]);
*key = keys[j];
*index = k;
return addr[i];
}
fintek_8250_exit_key(addr[i]);
}
}
return -ENODEV;
}
static int
fintek_8250_probe(struct pnp_dev *dev, const struct pnp_device_id *dev_id)
{
struct uart_8250_port uart;
struct fintek_8250 *pdata;
int base_port;
u8 key;
u8 index;
if (!pnp_port_valid(dev, 0))
return -ENODEV;
base_port = fintek_8250_base_port(pnp_port_start(dev, 0), &key, &index);
if (base_port < 0)
return -ENODEV;
memset(&uart, 0, sizeof(uart));
pdata = devm_kzalloc(&dev->dev, sizeof(*pdata), GFP_KERNEL);
if (!pdata)
return -ENOMEM;
uart.port.private_data = pdata;
if (!pnp_irq_valid(dev, 0))
return -ENODEV;
uart.port.irq = pnp_irq(dev, 0);
uart.port.iobase = pnp_port_start(dev, 0);
uart.port.iotype = UPIO_PORT;
uart.port.rs485_config = fintek_8250_rs485_config;
uart.port.flags |= UPF_SKIP_TEST | UPF_BOOT_AUTOCONF;
if (pnp_irq_flags(dev, 0) & IORESOURCE_IRQ_SHAREABLE)
uart.port.flags |= UPF_SHARE_IRQ;
uart.port.uartclk = 1843200;
uart.port.dev = &dev->dev;
pdata->key = key;
pdata->base_port = base_port;
pdata->index = index;
pdata->line = serial8250_register_8250_port(&uart);
if (pdata->line < 0)
return -ENODEV;
pnp_set_drvdata(dev, pdata);
return 0;
}
static void fintek_8250_remove(struct pnp_dev *dev)
{
struct fintek_8250 *pdata = pnp_get_drvdata(dev);
if (pdata)
serial8250_unregister_port(pdata->line);
}
static int fintek_8250_suspend(struct pnp_dev *dev, pm_message_t state)
{
struct fintek_8250 *pdata = pnp_get_drvdata(dev);
if (!pdata)
return -ENODEV;
serial8250_suspend_port(pdata->line);
return 0;
}
static int fintek_8250_resume(struct pnp_dev *dev)
{
struct fintek_8250 *pdata = pnp_get_drvdata(dev);
if (!pdata)
return -ENODEV;
serial8250_resume_port(pdata->line);
return 0;
}
