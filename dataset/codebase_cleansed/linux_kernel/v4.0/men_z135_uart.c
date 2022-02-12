static inline void men_z135_reg_set(struct men_z135_port *uart,
u32 addr, u32 val)
{
struct uart_port *port = &uart->port;
unsigned long flags;
u32 reg;
spin_lock_irqsave(&uart->lock, flags);
reg = ioread32(port->membase + addr);
reg |= val;
iowrite32(reg, port->membase + addr);
spin_unlock_irqrestore(&uart->lock, flags);
}
static inline void men_z135_reg_clr(struct men_z135_port *uart,
u32 addr, u32 val)
{
struct uart_port *port = &uart->port;
unsigned long flags;
u32 reg;
spin_lock_irqsave(&uart->lock, flags);
reg = ioread32(port->membase + addr);
reg &= ~val;
iowrite32(reg, port->membase + addr);
spin_unlock_irqrestore(&uart->lock, flags);
}
static void men_z135_handle_modem_status(struct men_z135_port *uart)
{
u8 msr;
msr = (uart->stat_reg >> 8) & 0xff;
if (msr & MEN_Z135_MSR_DDCD)
uart_handle_dcd_change(&uart->port,
msr & MEN_Z135_MSR_DCD);
if (msr & MEN_Z135_MSR_DCTS)
uart_handle_cts_change(&uart->port,
msr & MEN_Z135_MSR_CTS);
}
static void men_z135_handle_lsr(struct men_z135_port *uart)
{
struct uart_port *port = &uart->port;
u8 lsr;
lsr = (uart->stat_reg >> 16) & 0xff;
if (lsr & MEN_Z135_LSR_OE)
port->icount.overrun++;
if (lsr & MEN_Z135_LSR_PE)
port->icount.parity++;
if (lsr & MEN_Z135_LSR_FE)
port->icount.frame++;
if (lsr & MEN_Z135_LSR_BI) {
port->icount.brk++;
uart_handle_break(port);
}
}
static u16 get_rx_fifo_content(struct men_z135_port *uart)
{
struct uart_port *port = &uart->port;
u32 stat_reg;
u16 rxc;
u8 rxc_lo;
u8 rxc_hi;
stat_reg = ioread32(port->membase + MEN_Z135_STAT_REG);
rxc_lo = stat_reg >> 24;
rxc_hi = (stat_reg & 0xC0) >> 6;
rxc = rxc_lo | (rxc_hi << 8);
return rxc;
}
static void men_z135_handle_rx(struct men_z135_port *uart)
{
struct uart_port *port = &uart->port;
struct tty_port *tport = &port->state->port;
int copied;
u16 size;
int room;
size = get_rx_fifo_content(uart);
if (size == 0)
return;
if (size > MEN_Z135_FIFO_WATERMARK)
size = MEN_Z135_FIFO_WATERMARK;
room = tty_buffer_request_room(tport, size);
if (room != size)
dev_warn(&uart->mdev->dev,
"Not enough room in flip buffer, truncating to %d\n",
room);
if (room == 0)
return;
memcpy_fromio(uart->rxbuf, port->membase + MEN_Z135_RX_RAM, room);
mb();
iowrite32(room, port->membase + MEN_Z135_RX_CTRL);
copied = tty_insert_flip_string(tport, uart->rxbuf, room);
if (copied != room)
dev_warn(&uart->mdev->dev,
"Only copied %d instead of %d bytes\n",
copied, room);
port->icount.rx += copied;
tty_flip_buffer_push(tport);
}
static void men_z135_handle_tx(struct men_z135_port *uart)
{
struct uart_port *port = &uart->port;
struct circ_buf *xmit = &port->state->xmit;
u32 txc;
u32 wptr;
int qlen;
int n;
int txfree;
int head;
int tail;
int s;
if (uart_circ_empty(xmit))
goto out;
if (uart_tx_stopped(port))
goto out;
if (port->x_char)
goto out;
qlen = uart_circ_chars_pending(xmit);
if (qlen <= 0)
goto out;
wptr = ioread32(port->membase + MEN_Z135_TX_CTRL);
txc = (wptr >> 16) & 0x3ff;
wptr &= 0x3ff;
if (txc > MEN_Z135_FIFO_WATERMARK)
txc = MEN_Z135_FIFO_WATERMARK;
txfree = MEN_Z135_FIFO_WATERMARK - txc;
if (txfree <= 0) {
dev_err(&uart->mdev->dev,
"Not enough room in TX FIFO have %d, need %d\n",
txfree, qlen);
goto irq_en;
}
if (align && qlen >= 3 && BYTES_TO_ALIGN(wptr))
n = 4 - BYTES_TO_ALIGN(wptr);
else if (qlen > txfree)
n = txfree;
else
n = qlen;
if (n <= 0)
goto irq_en;
head = xmit->head & (UART_XMIT_SIZE - 1);
tail = xmit->tail & (UART_XMIT_SIZE - 1);
s = ((head >= tail) ? head : UART_XMIT_SIZE) - tail;
n = min(n, s);
memcpy_toio(port->membase + MEN_Z135_TX_RAM, &xmit->buf[xmit->tail], n);
xmit->tail = (xmit->tail + n) & (UART_XMIT_SIZE - 1);
mmiowb();
iowrite32(n & 0x3ff, port->membase + MEN_Z135_TX_CTRL);
port->icount.tx += n;
if (uart_circ_chars_pending(xmit) < WAKEUP_CHARS)
uart_write_wakeup(port);
irq_en:
if (!uart_circ_empty(xmit))
men_z135_reg_set(uart, MEN_Z135_CONF_REG, MEN_Z135_IER_TXCIEN);
else
men_z135_reg_clr(uart, MEN_Z135_CONF_REG, MEN_Z135_IER_TXCIEN);
out:
return;
}
static irqreturn_t men_z135_intr(int irq, void *data)
{
struct men_z135_port *uart = (struct men_z135_port *)data;
struct uart_port *port = &uart->port;
bool handled = false;
unsigned long flags;
int irq_id;
uart->stat_reg = ioread32(port->membase + MEN_Z135_STAT_REG);
irq_id = IRQ_ID(uart->stat_reg);
if (!irq_id)
goto out;
spin_lock_irqsave(&port->lock, flags);
iowrite8(irq_id, port->membase + MEN_Z135_STAT_REG);
if (irq_id & MEN_Z135_IRQ_ID_RLS) {
men_z135_handle_lsr(uart);
handled = true;
}
if (irq_id & (MEN_Z135_IRQ_ID_RDA | MEN_Z135_IRQ_ID_CTI)) {
if (irq_id & MEN_Z135_IRQ_ID_CTI)
dev_dbg(&uart->mdev->dev, "Character Timeout Indication\n");
men_z135_handle_rx(uart);
handled = true;
}
if (irq_id & MEN_Z135_IRQ_ID_TSA) {
men_z135_handle_tx(uart);
handled = true;
}
if (irq_id & MEN_Z135_IRQ_ID_MST) {
men_z135_handle_modem_status(uart);
handled = true;
}
spin_unlock_irqrestore(&port->lock, flags);
out:
return IRQ_RETVAL(handled);
}
static int men_z135_request_irq(struct men_z135_port *uart)
{
struct device *dev = &uart->mdev->dev;
struct uart_port *port = &uart->port;
int err = 0;
err = request_irq(port->irq, men_z135_intr, IRQF_SHARED,
"men_z135_intr", uart);
if (err)
dev_err(dev, "Error %d getting interrupt\n", err);
return err;
}
static unsigned int men_z135_tx_empty(struct uart_port *port)
{
u32 wptr;
u16 txc;
wptr = ioread32(port->membase + MEN_Z135_TX_CTRL);
txc = (wptr >> 16) & 0x3ff;
if (txc == 0)
return TIOCSER_TEMT;
else
return 0;
}
static void men_z135_set_mctrl(struct uart_port *port, unsigned int mctrl)
{
u32 old;
u32 conf_reg;
conf_reg = old = ioread32(port->membase + MEN_Z135_CONF_REG);
if (mctrl & TIOCM_RTS)
conf_reg |= MEN_Z135_MCR_RTS;
else
conf_reg &= ~MEN_Z135_MCR_RTS;
if (mctrl & TIOCM_DTR)
conf_reg |= MEN_Z135_MCR_DTR;
else
conf_reg &= ~MEN_Z135_MCR_DTR;
if (mctrl & TIOCM_OUT1)
conf_reg |= MEN_Z135_MCR_OUT1;
else
conf_reg &= ~MEN_Z135_MCR_OUT1;
if (mctrl & TIOCM_OUT2)
conf_reg |= MEN_Z135_MCR_OUT2;
else
conf_reg &= ~MEN_Z135_MCR_OUT2;
if (mctrl & TIOCM_LOOP)
conf_reg |= MEN_Z135_MCR_LOOP;
else
conf_reg &= ~MEN_Z135_MCR_LOOP;
if (conf_reg != old)
iowrite32(conf_reg, port->membase + MEN_Z135_CONF_REG);
}
static unsigned int men_z135_get_mctrl(struct uart_port *port)
{
unsigned int mctrl = 0;
u8 msr;
msr = ioread8(port->membase + MEN_Z135_STAT_REG + 1);
if (msr & MEN_Z135_MSR_CTS)
mctrl |= TIOCM_CTS;
if (msr & MEN_Z135_MSR_DSR)
mctrl |= TIOCM_DSR;
if (msr & MEN_Z135_MSR_RI)
mctrl |= TIOCM_RI;
if (msr & MEN_Z135_MSR_DCD)
mctrl |= TIOCM_CAR;
return mctrl;
}
static void men_z135_stop_tx(struct uart_port *port)
{
struct men_z135_port *uart = to_men_z135(port);
men_z135_reg_clr(uart, MEN_Z135_CONF_REG, MEN_Z135_IER_TXCIEN);
}
static void men_z135_disable_ms(struct uart_port *port)
{
struct men_z135_port *uart = to_men_z135(port);
men_z135_reg_clr(uart, MEN_Z135_CONF_REG, MEN_Z135_IER_MSIEN);
}
static void men_z135_start_tx(struct uart_port *port)
{
struct men_z135_port *uart = to_men_z135(port);
if (uart->automode)
men_z135_disable_ms(port);
men_z135_handle_tx(uart);
}
static void men_z135_stop_rx(struct uart_port *port)
{
struct men_z135_port *uart = to_men_z135(port);
men_z135_reg_clr(uart, MEN_Z135_CONF_REG, MEN_Z135_IER_RXCIEN);
}
static void men_z135_enable_ms(struct uart_port *port)
{
struct men_z135_port *uart = to_men_z135(port);
men_z135_reg_set(uart, MEN_Z135_CONF_REG, MEN_Z135_IER_MSIEN);
}
static int men_z135_startup(struct uart_port *port)
{
struct men_z135_port *uart = to_men_z135(port);
int err;
u32 conf_reg = 0;
err = men_z135_request_irq(uart);
if (err)
return -ENODEV;
conf_reg = ioread32(port->membase + MEN_Z135_CONF_REG);
conf_reg |= MEN_Z135_ALL_IRQS & ~MEN_Z135_IER_TXCIEN;
conf_reg &= ~(0xff << 16);
conf_reg |= (txlvl << 16);
conf_reg |= (rxlvl << 20);
iowrite32(conf_reg, port->membase + MEN_Z135_CONF_REG);
if (rx_timeout)
iowrite32(rx_timeout, port->membase + MEN_Z135_TIMEOUT);
return 0;
}
static void men_z135_shutdown(struct uart_port *port)
{
struct men_z135_port *uart = to_men_z135(port);
u32 conf_reg = 0;
conf_reg |= MEN_Z135_ALL_IRQS;
men_z135_reg_clr(uart, MEN_Z135_CONF_REG, conf_reg);
free_irq(uart->port.irq, uart);
}
static void men_z135_set_termios(struct uart_port *port,
struct ktermios *termios,
struct ktermios *old)
{
struct men_z135_port *uart = to_men_z135(port);
unsigned int baud;
u32 conf_reg;
u32 bd_reg;
u32 uart_freq;
u8 lcr;
conf_reg = ioread32(port->membase + MEN_Z135_CONF_REG);
lcr = LCR(conf_reg);
switch (termios->c_cflag & CSIZE) {
case CS5:
lcr |= MEN_Z135_WL5;
break;
case CS6:
lcr |= MEN_Z135_WL6;
break;
case CS7:
lcr |= MEN_Z135_WL7;
break;
case CS8:
lcr |= MEN_Z135_WL8;
break;
}
if (termios->c_cflag & CSTOPB)
lcr |= MEN_Z135_NSTB2 << MEN_Z135_STB_SHIFT;
if (termios->c_cflag & PARENB) {
lcr |= MEN_Z135_PAR_ENA << MEN_Z135_PEN_SHIFT;
if (termios->c_cflag & PARODD)
lcr |= MEN_Z135_PTY_ODD << MEN_Z135_PTY_SHIFT;
else
lcr |= MEN_Z135_PTY_EVN << MEN_Z135_PTY_SHIFT;
} else
lcr |= MEN_Z135_PAR_DIS << MEN_Z135_PEN_SHIFT;
conf_reg |= MEN_Z135_IER_MSIEN;
if (termios->c_cflag & CRTSCTS) {
conf_reg |= MEN_Z135_MCR_RCFC;
uart->automode = true;
termios->c_cflag &= ~CLOCAL;
} else {
conf_reg &= ~MEN_Z135_MCR_RCFC;
uart->automode = false;
}
termios->c_cflag &= ~CMSPAR;
conf_reg |= lcr << MEN_Z135_LCR_SHIFT;
iowrite32(conf_reg, port->membase + MEN_Z135_CONF_REG);
uart_freq = ioread32(port->membase + MEN_Z135_UART_FREQ);
if (uart_freq == 0)
uart_freq = MEN_Z135_BASECLK;
baud = uart_get_baud_rate(port, termios, old, 0, uart_freq / 16);
spin_lock(&port->lock);
if (tty_termios_baud_rate(termios))
tty_termios_encode_baud_rate(termios, baud, baud);
bd_reg = uart_freq / (4 * baud);
iowrite32(bd_reg, port->membase + MEN_Z135_BAUD_REG);
uart_update_timeout(port, termios->c_cflag, baud);
spin_unlock(&port->lock);
}
static const char *men_z135_type(struct uart_port *port)
{
return KBUILD_MODNAME;
}
static void men_z135_release_port(struct uart_port *port)
{
iounmap(port->membase);
port->membase = NULL;
release_mem_region(port->mapbase, MEN_Z135_MEM_SIZE);
}
static int men_z135_request_port(struct uart_port *port)
{
int size = MEN_Z135_MEM_SIZE;
if (!request_mem_region(port->mapbase, size, "men_z135_port"))
return -EBUSY;
port->membase = ioremap(port->mapbase, MEN_Z135_MEM_SIZE);
if (port->membase == NULL) {
release_mem_region(port->mapbase, MEN_Z135_MEM_SIZE);
return -ENOMEM;
}
return 0;
}
static void men_z135_config_port(struct uart_port *port, int type)
{
port->type = PORT_MEN_Z135;
men_z135_request_port(port);
}
static int men_z135_verify_port(struct uart_port *port,
struct serial_struct *serinfo)
{
return -EINVAL;
}
static int men_z135_probe(struct mcb_device *mdev,
const struct mcb_device_id *id)
{
struct men_z135_port *uart;
struct resource *mem;
struct device *dev;
int err;
dev = &mdev->dev;
uart = devm_kzalloc(dev, sizeof(struct men_z135_port), GFP_KERNEL);
if (!uart)
return -ENOMEM;
uart->rxbuf = (unsigned char *)__get_free_page(GFP_KERNEL);
if (!uart->rxbuf)
return -ENOMEM;
mem = &mdev->mem;
mcb_set_drvdata(mdev, uart);
uart->port.uartclk = MEN_Z135_BASECLK * 16;
uart->port.fifosize = MEN_Z135_FIFO_SIZE;
uart->port.iotype = UPIO_MEM;
uart->port.ops = &men_z135_ops;
uart->port.irq = mcb_get_irq(mdev);
uart->port.iotype = UPIO_MEM;
uart->port.flags = UPF_BOOT_AUTOCONF | UPF_IOREMAP;
uart->port.line = line++;
uart->port.dev = dev;
uart->port.type = PORT_MEN_Z135;
uart->port.mapbase = mem->start;
uart->port.membase = NULL;
uart->mdev = mdev;
spin_lock_init(&uart->port.lock);
spin_lock_init(&uart->lock);
err = uart_add_one_port(&men_z135_driver, &uart->port);
if (err)
goto err;
return 0;
err:
free_page((unsigned long) uart->rxbuf);
dev_err(dev, "Failed to add UART: %d\n", err);
return err;
}
static void men_z135_remove(struct mcb_device *mdev)
{
struct men_z135_port *uart = mcb_get_drvdata(mdev);
line--;
uart_remove_one_port(&men_z135_driver, &uart->port);
free_page((unsigned long) uart->rxbuf);
}
static int __init men_z135_init(void)
{
int err;
err = uart_register_driver(&men_z135_driver);
if (err) {
pr_err("Failed to register UART: %d\n", err);
return err;
}
err = mcb_register_driver(&mcb_driver);
if (err) {
pr_err("Failed to register MCB driver: %d\n", err);
uart_unregister_driver(&men_z135_driver);
return err;
}
return 0;
}
static void __exit men_z135_exit(void)
{
mcb_unregister_driver(&mcb_driver);
uart_unregister_driver(&men_z135_driver);
}
