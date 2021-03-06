static int fintek_8250_enter_key(u16 base_port, u8 key)
{
if (!request_muxed_region(base_port, 2, "8250_fintek"))
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
static int find_base_port(struct fintek_8250 *pdata, u16 io_address)
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
pdata->key = keys[j];
pdata->base_port = addr[i];
pdata->index = k;
return 0;
}
fintek_8250_exit_key(addr[i]);
}
}
return -ENODEV;
}
int fintek_8250_probe(struct uart_8250_port *uart)
{
struct fintek_8250 *pdata;
struct fintek_8250 probe_data;
if (find_base_port(&probe_data, uart->port.iobase))
return -ENODEV;
pdata = devm_kzalloc(uart->port.dev, sizeof(*pdata), GFP_KERNEL);
if (!pdata)
return -ENOMEM;
memcpy(pdata, &probe_data, sizeof(probe_data));
uart->port.rs485_config = fintek_8250_rs485_config;
uart->port.private_data = pdata;
return 0;
}
