static int fintek_8250_enter_key(void){
if (!request_muxed_region(ADDR_PORT, 2, DRIVER_NAME))
return -EBUSY;
outb(ENTRY_KEY, ADDR_PORT);
outb(ENTRY_KEY, ADDR_PORT);
return 0;
}
static void fintek_8250_exit_key(void){
outb(EXIT_KEY, ADDR_PORT);
release_region(ADDR_PORT, 2);
}
static int fintek_8250_get_index(resource_size_t base_addr)
{
resource_size_t base[] = {0x3f8, 0x2f8, 0x3e8, 0x2e8};
int i;
for (i = 0; i < ARRAY_SIZE(base); i++)
if (base_addr == base[i])
return i;
return -ENODEV;
}
static int fintek_8250_check_id(void)
{
outb(CHIP_ID1, ADDR_PORT);
if (inb(DATA_PORT) != CHIP_ID1_VAL)
return -ENODEV;
outb(CHIP_ID2, ADDR_PORT);
if (inb(DATA_PORT) != CHIP_ID2_VAL)
return -ENODEV;
outb(VENDOR_ID1, ADDR_PORT);
if (inb(DATA_PORT) != VENDOR_ID1_VAL)
return -ENODEV;
outb(VENDOR_ID2, ADDR_PORT);
if (inb(DATA_PORT) != VENDOR_ID2_VAL)
return -ENODEV;
return 0;
}
static int fintek_8250_rs485_config(struct uart_port *port,
struct serial_rs485 *rs485)
{
uint8_t config = 0;
int index = fintek_8250_get_index(port->iobase);
if (index < 0)
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
if (fintek_8250_enter_key())
return -EBUSY;
outb(LDN, ADDR_PORT);
outb(index, DATA_PORT);
outb(RS485, ADDR_PORT);
outb(config, DATA_PORT);
fintek_8250_exit_key();
port->rs485 = *rs485;
return 0;
}
static int
fintek_8250_probe(struct pnp_dev *dev, const struct pnp_device_id *dev_id)
{
int line;
struct uart_8250_port uart;
int ret;
if (!pnp_port_valid(dev, 0))
return -ENODEV;
if (fintek_8250_get_index(pnp_port_start(dev, 0)) < 0)
return -ENODEV;
if (fintek_8250_enter_key())
return -EBUSY;
ret = fintek_8250_check_id();
fintek_8250_exit_key();
if (ret)
return ret;
memset(&uart, 0, sizeof(uart));
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
line = serial8250_register_8250_port(&uart);
if (line < 0)
return -ENODEV;
pnp_set_drvdata(dev, (void *)((long)line + 1));
return 0;
}
static void fintek_8250_remove(struct pnp_dev *dev)
{
long line = (long)pnp_get_drvdata(dev);
if (line)
serial8250_unregister_port(line - 1);
}
static int fintek_8250_suspend(struct pnp_dev *dev, pm_message_t state)
{
long line = (long)pnp_get_drvdata(dev);
if (!line)
return -ENODEV;
serial8250_suspend_port(line - 1);
return 0;
}
static int fintek_8250_resume(struct pnp_dev *dev)
{
long line = (long)pnp_get_drvdata(dev);
if (!line)
return -ENODEV;
serial8250_resume_port(line - 1);
return 0;
}
static int fintek_8250_init(void)
{
return pnp_register_driver(&fintek_8250_driver);
}
static void fintek_8250_exit(void)
{
pnp_unregister_driver(&fintek_8250_driver);
}
