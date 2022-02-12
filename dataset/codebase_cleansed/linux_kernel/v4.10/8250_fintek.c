static u8 sio_read_reg(struct fintek_8250 *pdata, u8 reg)
{
outb(reg, pdata->base_port + ADDR_PORT);
return inb(pdata->base_port + DATA_PORT);
}
static void sio_write_reg(struct fintek_8250 *pdata, u8 reg, u8 data)
{
outb(reg, pdata->base_port + ADDR_PORT);
outb(data, pdata->base_port + DATA_PORT);
}
static void sio_write_mask_reg(struct fintek_8250 *pdata, u8 reg, u8 mask,
u8 data)
{
u8 tmp;
tmp = (sio_read_reg(pdata, reg) & ~mask) | (mask & data);
sio_write_reg(pdata, reg, tmp);
}
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
static int fintek_8250_check_id(struct fintek_8250 *pdata)
{
u16 chip;
if (sio_read_reg(pdata, VENDOR_ID1) != VENDOR_ID1_VAL)
return -ENODEV;
if (sio_read_reg(pdata, VENDOR_ID2) != VENDOR_ID2_VAL)
return -ENODEV;
chip = sio_read_reg(pdata, CHIP_ID1);
chip |= sio_read_reg(pdata, CHIP_ID2) << 8;
switch (chip) {
case CHIP_ID_F81865:
case CHIP_ID_F81866:
case CHIP_ID_F81216AD:
case CHIP_ID_F81216H:
case CHIP_ID_F81216:
break;
default:
return -ENODEV;
}
pdata->pid = chip;
return 0;
}
static int fintek_8250_get_ldn_range(struct fintek_8250 *pdata, int *min,
int *max)
{
switch (pdata->pid) {
case CHIP_ID_F81865:
case CHIP_ID_F81866:
*min = F81866_LDN_LOW;
*max = F81866_LDN_HIGH;
return 0;
case CHIP_ID_F81216AD:
case CHIP_ID_F81216H:
case CHIP_ID_F81216:
*min = F81216_LDN_LOW;
*max = F81216_LDN_HIGH;
return 0;
}
return -ENODEV;
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
sio_write_reg(pdata, LDN, pdata->index);
sio_write_reg(pdata, RS485, config);
fintek_8250_exit_key(pdata->base_port);
port->rs485 = *rs485;
return 0;
}
static void fintek_8250_set_irq_mode(struct fintek_8250 *pdata, bool is_level)
{
sio_write_reg(pdata, LDN, pdata->index);
switch (pdata->pid) {
case CHIP_ID_F81866:
sio_write_mask_reg(pdata, F81866_FIFO_CTRL, F81866_IRQ_MODE1,
0);
case CHIP_ID_F81865:
sio_write_mask_reg(pdata, F81866_IRQ_MODE, F81866_IRQ_SHARE,
F81866_IRQ_SHARE);
sio_write_mask_reg(pdata, F81866_IRQ_MODE, F81866_IRQ_MODE0,
is_level ? 0 : F81866_IRQ_MODE0);
break;
case CHIP_ID_F81216AD:
case CHIP_ID_F81216H:
case CHIP_ID_F81216:
sio_write_mask_reg(pdata, FINTEK_IRQ_MODE, IRQ_SHARE,
IRQ_SHARE);
sio_write_mask_reg(pdata, FINTEK_IRQ_MODE, IRQ_MODE_MASK,
is_level ? IRQ_LEVEL_LOW : IRQ_EDGE_HIGH);
break;
}
}
static void fintek_8250_set_max_fifo(struct fintek_8250 *pdata)
{
switch (pdata->pid) {
case CHIP_ID_F81216H:
case CHIP_ID_F81866:
sio_write_mask_reg(pdata, FIFO_CTRL,
FIFO_MODE_MASK | RXFTHR_MODE_MASK,
FIFO_MODE_128 | RXFTHR_MODE_4X);
break;
default:
break;
}
}
static int probe_setup_port(struct fintek_8250 *pdata, u16 io_address,
unsigned int irq)
{
static const u16 addr[] = {0x4e, 0x2e};
static const u8 keys[] = {0x77, 0xa0, 0x87, 0x67};
struct irq_data *irq_data;
bool level_mode = false;
int i, j, k, min, max;
for (i = 0; i < ARRAY_SIZE(addr); i++) {
for (j = 0; j < ARRAY_SIZE(keys); j++) {
pdata->base_port = addr[i];
pdata->key = keys[j];
if (fintek_8250_enter_key(addr[i], keys[j]))
continue;
if (fintek_8250_check_id(pdata) ||
fintek_8250_get_ldn_range(pdata, &min, &max)) {
fintek_8250_exit_key(addr[i]);
continue;
}
for (k = min; k < max; k++) {
u16 aux;
sio_write_reg(pdata, LDN, k);
aux = sio_read_reg(pdata, IO_ADDR1);
aux |= sio_read_reg(pdata, IO_ADDR2) << 8;
if (aux != io_address)
continue;
pdata->index = k;
irq_data = irq_get_irq_data(irq);
if (irq_data)
level_mode =
irqd_is_level_type(irq_data);
fintek_8250_set_irq_mode(pdata, level_mode);
fintek_8250_set_max_fifo(pdata);
fintek_8250_exit_key(addr[i]);
return 0;
}
fintek_8250_exit_key(addr[i]);
}
}
return -ENODEV;
}
static void fintek_8250_set_rs485_handler(struct uart_8250_port *uart)
{
struct fintek_8250 *pdata = uart->port.private_data;
switch (pdata->pid) {
case CHIP_ID_F81216AD:
case CHIP_ID_F81216H:
case CHIP_ID_F81866:
case CHIP_ID_F81865:
uart->port.rs485_config = fintek_8250_rs485_config;
break;
default:
break;
}
}
int fintek_8250_probe(struct uart_8250_port *uart)
{
struct fintek_8250 *pdata;
struct fintek_8250 probe_data;
if (probe_setup_port(&probe_data, uart->port.iobase, uart->port.irq))
return -ENODEV;
pdata = devm_kzalloc(uart->port.dev, sizeof(*pdata), GFP_KERNEL);
if (!pdata)
return -ENOMEM;
memcpy(pdata, &probe_data, sizeof(probe_data));
uart->port.private_data = pdata;
fintek_8250_set_rs485_handler(uart);
return 0;
}
