static inline unsigned int serial_in(struct uart_port *port, int offset)
{
return readl_relaxed(port->membase + offset);
}
static inline void serial_out(struct uart_port *port, int offset, int value)
{
writel_relaxed(value, port->membase + offset);
}
static unsigned int sprd_tx_empty(struct uart_port *port)
{
if (serial_in(port, SPRD_STS1) & 0xff00)
return 0;
else
return TIOCSER_TEMT;
}
static unsigned int sprd_get_mctrl(struct uart_port *port)
{
return TIOCM_DSR | TIOCM_CTS;
}
static void sprd_set_mctrl(struct uart_port *port, unsigned int mctrl)
{
}
static void sprd_stop_tx(struct uart_port *port)
{
unsigned int ien, iclr;
iclr = serial_in(port, SPRD_ICLR);
ien = serial_in(port, SPRD_IEN);
iclr |= SPRD_IEN_TX_EMPTY;
ien &= ~SPRD_IEN_TX_EMPTY;
serial_out(port, SPRD_ICLR, iclr);
serial_out(port, SPRD_IEN, ien);
}
static void sprd_start_tx(struct uart_port *port)
{
unsigned int ien;
ien = serial_in(port, SPRD_IEN);
if (!(ien & SPRD_IEN_TX_EMPTY)) {
ien |= SPRD_IEN_TX_EMPTY;
serial_out(port, SPRD_IEN, ien);
}
}
static void sprd_stop_rx(struct uart_port *port)
{
unsigned int ien, iclr;
iclr = serial_in(port, SPRD_ICLR);
ien = serial_in(port, SPRD_IEN);
ien &= ~(SPRD_IEN_RX_FULL | SPRD_IEN_BREAK_DETECT);
iclr |= SPRD_IEN_RX_FULL | SPRD_IEN_BREAK_DETECT;
serial_out(port, SPRD_IEN, ien);
serial_out(port, SPRD_ICLR, iclr);
}
static void sprd_break_ctl(struct uart_port *port, int break_state)
{
}
static int handle_lsr_errors(struct uart_port *port,
unsigned int *flag,
unsigned int *lsr)
{
int ret = 0;
if (*lsr & SPRD_LSR_BI) {
*lsr &= ~(SPRD_LSR_FE | SPRD_LSR_PE);
port->icount.brk++;
ret = uart_handle_break(port);
if (ret)
return ret;
} else if (*lsr & SPRD_LSR_PE)
port->icount.parity++;
else if (*lsr & SPRD_LSR_FE)
port->icount.frame++;
if (*lsr & SPRD_LSR_OE)
port->icount.overrun++;
*lsr &= port->read_status_mask;
if (*lsr & SPRD_LSR_BI)
*flag = TTY_BREAK;
else if (*lsr & SPRD_LSR_PE)
*flag = TTY_PARITY;
else if (*lsr & SPRD_LSR_FE)
*flag = TTY_FRAME;
return ret;
}
static inline void sprd_rx(struct uart_port *port)
{
struct tty_port *tty = &port->state->port;
unsigned int ch, flag, lsr, max_count = SPRD_TIMEOUT;
while ((serial_in(port, SPRD_STS1) & 0x00ff) && max_count--) {
lsr = serial_in(port, SPRD_LSR);
ch = serial_in(port, SPRD_RXD);
flag = TTY_NORMAL;
port->icount.rx++;
if (lsr & (SPRD_LSR_BI | SPRD_LSR_PE |
SPRD_LSR_FE | SPRD_LSR_OE))
if (handle_lsr_errors(port, &lsr, &flag))
continue;
if (uart_handle_sysrq_char(port, ch))
continue;
uart_insert_char(port, lsr, SPRD_LSR_OE, ch, flag);
}
tty_flip_buffer_push(tty);
}
static inline void sprd_tx(struct uart_port *port)
{
struct circ_buf *xmit = &port->state->xmit;
int count;
if (port->x_char) {
serial_out(port, SPRD_TXD, port->x_char);
port->icount.tx++;
port->x_char = 0;
return;
}
if (uart_circ_empty(xmit) || uart_tx_stopped(port)) {
sprd_stop_tx(port);
return;
}
count = THLD_TX_EMPTY;
do {
serial_out(port, SPRD_TXD, xmit->buf[xmit->tail]);
xmit->tail = (xmit->tail + 1) & (UART_XMIT_SIZE - 1);
port->icount.tx++;
if (uart_circ_empty(xmit))
break;
} while (--count > 0);
if (uart_circ_chars_pending(xmit) < WAKEUP_CHARS)
uart_write_wakeup(port);
if (uart_circ_empty(xmit))
sprd_stop_tx(port);
}
static irqreturn_t sprd_handle_irq(int irq, void *dev_id)
{
struct uart_port *port = dev_id;
unsigned int ims;
spin_lock(&port->lock);
ims = serial_in(port, SPRD_IMSR);
if (!ims) {
spin_unlock(&port->lock);
return IRQ_NONE;
}
serial_out(port, SPRD_ICLR, ~0);
if (ims & (SPRD_IMSR_RX_FIFO_FULL |
SPRD_IMSR_BREAK_DETECT | SPRD_IMSR_TIMEOUT))
sprd_rx(port);
if (ims & SPRD_IMSR_TX_FIFO_EMPTY)
sprd_tx(port);
spin_unlock(&port->lock);
return IRQ_HANDLED;
}
static int sprd_startup(struct uart_port *port)
{
int ret = 0;
unsigned int ien, fc;
unsigned int timeout;
struct sprd_uart_port *sp;
unsigned long flags;
serial_out(port, SPRD_CTL2, ((THLD_TX_EMPTY << 8) | THLD_RX_FULL));
timeout = SPRD_TIMEOUT;
while (timeout-- && serial_in(port, SPRD_STS1) & 0x00ff)
serial_in(port, SPRD_RXD);
timeout = SPRD_TIMEOUT;
while (timeout-- && serial_in(port, SPRD_STS1) & 0xff00)
cpu_relax();
serial_out(port, SPRD_IEN, 0);
serial_out(port, SPRD_ICLR, ~0);
sp = container_of(port, struct sprd_uart_port, port);
snprintf(sp->name, sizeof(sp->name), "sprd_serial%d", port->line);
ret = devm_request_irq(port->dev, port->irq, sprd_handle_irq,
IRQF_SHARED, sp->name, port);
if (ret) {
dev_err(port->dev, "fail to request serial irq %d, ret=%d\n",
port->irq, ret);
return ret;
}
fc = serial_in(port, SPRD_CTL1);
fc |= RX_TOUT_THLD_DEF | RX_HFC_THLD_DEF;
serial_out(port, SPRD_CTL1, fc);
spin_lock_irqsave(&port->lock, flags);
ien = serial_in(port, SPRD_IEN);
ien |= SPRD_IEN_RX_FULL | SPRD_IEN_BREAK_DETECT | SPRD_IEN_TIMEOUT;
serial_out(port, SPRD_IEN, ien);
spin_unlock_irqrestore(&port->lock, flags);
return 0;
}
static void sprd_shutdown(struct uart_port *port)
{
serial_out(port, SPRD_IEN, 0);
serial_out(port, SPRD_ICLR, ~0);
devm_free_irq(port->dev, port->irq, port);
}
static void sprd_set_termios(struct uart_port *port,
struct ktermios *termios,
struct ktermios *old)
{
unsigned int baud, quot;
unsigned int lcr = 0, fc;
unsigned long flags;
baud = uart_get_baud_rate(port, termios, old, 0, SPRD_BAUD_IO_LIMIT);
quot = (unsigned int)((port->uartclk + baud / 2) / baud);
switch (termios->c_cflag & CSIZE) {
case CS5:
lcr |= SPRD_LCR_DATA_LEN5;
break;
case CS6:
lcr |= SPRD_LCR_DATA_LEN6;
break;
case CS7:
lcr |= SPRD_LCR_DATA_LEN7;
break;
case CS8:
default:
lcr |= SPRD_LCR_DATA_LEN8;
break;
}
lcr &= ~(SPRD_LCR_STOP_1BIT | SPRD_LCR_STOP_2BIT);
if (termios->c_cflag & CSTOPB)
lcr |= SPRD_LCR_STOP_2BIT;
else
lcr |= SPRD_LCR_STOP_1BIT;
lcr &= ~SPRD_LCR_PARITY;
termios->c_cflag &= ~CMSPAR;
if (termios->c_cflag & PARENB) {
lcr |= SPRD_LCR_PARITY_EN;
if (termios->c_cflag & PARODD)
lcr |= SPRD_LCR_ODD_PAR;
else
lcr |= SPRD_LCR_EVEN_PAR;
}
spin_lock_irqsave(&port->lock, flags);
uart_update_timeout(port, termios->c_cflag, baud);
port->read_status_mask = SPRD_LSR_OE;
if (termios->c_iflag & INPCK)
port->read_status_mask |= SPRD_LSR_FE | SPRD_LSR_PE;
if (termios->c_iflag & (IGNBRK | BRKINT | PARMRK))
port->read_status_mask |= SPRD_LSR_BI;
port->ignore_status_mask = 0;
if (termios->c_iflag & IGNPAR)
port->ignore_status_mask |= SPRD_LSR_PE | SPRD_LSR_FE;
if (termios->c_iflag & IGNBRK) {
port->ignore_status_mask |= SPRD_LSR_BI;
if (termios->c_iflag & IGNPAR)
port->ignore_status_mask |= SPRD_LSR_OE;
}
fc = serial_in(port, SPRD_CTL1);
fc &= ~(RX_HW_FLOW_CTL_THLD | RX_HW_FLOW_CTL_EN | TX_HW_FLOW_CTL_EN);
if (termios->c_cflag & CRTSCTS) {
fc |= RX_HW_FLOW_CTL_THLD;
fc |= RX_HW_FLOW_CTL_EN;
fc |= TX_HW_FLOW_CTL_EN;
}
serial_out(port, SPRD_CLKD0, quot & 0xffff);
serial_out(port, SPRD_CLKD1, (quot & 0x1f0000) >> 16);
serial_out(port, SPRD_LCR, lcr);
fc |= RX_TOUT_THLD_DEF | RX_HFC_THLD_DEF;
serial_out(port, SPRD_CTL1, fc);
spin_unlock_irqrestore(&port->lock, flags);
if (tty_termios_baud_rate(termios))
tty_termios_encode_baud_rate(termios, baud, baud);
}
static const char *sprd_type(struct uart_port *port)
{
return "SPX";
}
static void sprd_release_port(struct uart_port *port)
{
}
static int sprd_request_port(struct uart_port *port)
{
return 0;
}
static void sprd_config_port(struct uart_port *port, int flags)
{
if (flags & UART_CONFIG_TYPE)
port->type = PORT_SPRD;
}
static int sprd_verify_port(struct uart_port *port,
struct serial_struct *ser)
{
if (ser->type != PORT_SPRD)
return -EINVAL;
if (port->irq != ser->irq)
return -EINVAL;
return 0;
}
static inline void wait_for_xmitr(struct uart_port *port)
{
unsigned int status, tmout = 10000;
do {
status = serial_in(port, SPRD_STS1);
if (--tmout == 0)
break;
udelay(1);
} while (status & 0xff00);
}
static void sprd_console_putchar(struct uart_port *port, int ch)
{
wait_for_xmitr(port);
serial_out(port, SPRD_TXD, ch);
}
static void sprd_console_write(struct console *co, const char *s,
unsigned int count)
{
struct uart_port *port = &sprd_port[co->index]->port;
int locked = 1;
unsigned long flags;
if (port->sysrq)
locked = 0;
else if (oops_in_progress)
locked = spin_trylock_irqsave(&port->lock, flags);
else
spin_lock_irqsave(&port->lock, flags);
uart_console_write(port, s, count, sprd_console_putchar);
wait_for_xmitr(port);
if (locked)
spin_unlock_irqrestore(&port->lock, flags);
}
static int __init sprd_console_setup(struct console *co, char *options)
{
struct uart_port *port;
int baud = 115200;
int bits = 8;
int parity = 'n';
int flow = 'n';
if (co->index >= UART_NR_MAX || co->index < 0)
co->index = 0;
port = &sprd_port[co->index]->port;
if (port == NULL) {
pr_info("serial port %d not yet initialized\n", co->index);
return -ENODEV;
}
if (options)
uart_parse_options(options, &baud, &parity, &bits, &flow);
return uart_set_options(port, co, baud, parity, bits, flow);
}
static void sprd_putc(struct uart_port *port, int c)
{
unsigned int timeout = SPRD_TIMEOUT;
while (timeout-- &&
!(readl(port->membase + SPRD_LSR) & SPRD_LSR_TX_OVER))
cpu_relax();
writeb(c, port->membase + SPRD_TXD);
}
static void sprd_early_write(struct console *con, const char *s,
unsigned n)
{
struct earlycon_device *dev = con->data;
uart_console_write(&dev->port, s, n, sprd_putc);
}
static int __init sprd_early_console_setup(
struct earlycon_device *device,
const char *opt)
{
if (!device->port.membase)
return -ENODEV;
device->con->write = sprd_early_write;
return 0;
}
static int sprd_probe_dt_alias(int index, struct device *dev)
{
struct device_node *np;
int ret = index;
if (!IS_ENABLED(CONFIG_OF))
return ret;
np = dev->of_node;
if (!np)
return ret;
ret = of_alias_get_id(np, "serial");
if (IS_ERR_VALUE(ret))
ret = index;
else if (ret >= ARRAY_SIZE(sprd_port) || sprd_port[ret] != NULL) {
dev_warn(dev, "requested serial port %d not available.\n", ret);
ret = index;
}
return ret;
}
static int sprd_remove(struct platform_device *dev)
{
struct sprd_uart_port *sup = platform_get_drvdata(dev);
if (sup) {
uart_remove_one_port(&sprd_uart_driver, &sup->port);
sprd_port[sup->port.line] = NULL;
sprd_ports_num--;
}
if (!sprd_ports_num)
uart_unregister_driver(&sprd_uart_driver);
return 0;
}
static int sprd_probe(struct platform_device *pdev)
{
struct resource *res;
struct uart_port *up;
struct clk *clk;
int irq;
int index;
int ret;
for (index = 0; index < ARRAY_SIZE(sprd_port); index++)
if (sprd_port[index] == NULL)
break;
if (index == ARRAY_SIZE(sprd_port))
return -EBUSY;
index = sprd_probe_dt_alias(index, &pdev->dev);
sprd_port[index] = devm_kzalloc(&pdev->dev,
sizeof(*sprd_port[index]), GFP_KERNEL);
if (!sprd_port[index])
return -ENOMEM;
up = &sprd_port[index]->port;
up->dev = &pdev->dev;
up->line = index;
up->type = PORT_SPRD;
up->iotype = SERIAL_IO_PORT;
up->uartclk = SPRD_DEF_RATE;
up->fifosize = SPRD_FIFO_SIZE;
up->ops = &serial_sprd_ops;
up->flags = UPF_BOOT_AUTOCONF;
clk = devm_clk_get(&pdev->dev, NULL);
if (!IS_ERR(clk))
up->uartclk = clk_get_rate(clk);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(&pdev->dev, "not provide mem resource\n");
return -ENODEV;
}
up->mapbase = res->start;
up->membase = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(up->membase))
return PTR_ERR(up->membase);
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_err(&pdev->dev, "not provide irq resource\n");
return -ENODEV;
}
up->irq = irq;
if (!sprd_ports_num) {
ret = uart_register_driver(&sprd_uart_driver);
if (ret < 0) {
pr_err("Failed to register SPRD-UART driver\n");
return ret;
}
}
sprd_ports_num++;
ret = uart_add_one_port(&sprd_uart_driver, up);
if (ret) {
sprd_port[index] = NULL;
sprd_remove(pdev);
}
platform_set_drvdata(pdev, up);
return ret;
}
static int sprd_suspend(struct device *dev)
{
struct sprd_uart_port *sup = dev_get_drvdata(dev);
uart_suspend_port(&sprd_uart_driver, &sup->port);
return 0;
}
static int sprd_resume(struct device *dev)
{
struct sprd_uart_port *sup = dev_get_drvdata(dev);
uart_resume_port(&sprd_uart_driver, &sup->port);
return 0;
}
