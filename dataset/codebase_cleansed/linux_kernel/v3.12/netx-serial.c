static void netx_stop_tx(struct uart_port *port)
{
unsigned int val;
val = readl(port->membase + UART_CR);
writel(val & ~CR_TIE, port->membase + UART_CR);
}
static void netx_stop_rx(struct uart_port *port)
{
unsigned int val;
val = readl(port->membase + UART_CR);
writel(val & ~CR_RIE, port->membase + UART_CR);
}
static void netx_enable_ms(struct uart_port *port)
{
unsigned int val;
val = readl(port->membase + UART_CR);
writel(val | CR_MSIE, port->membase + UART_CR);
}
static inline void netx_transmit_buffer(struct uart_port *port)
{
struct circ_buf *xmit = &port->state->xmit;
if (port->x_char) {
writel(port->x_char, port->membase + UART_DR);
port->icount.tx++;
port->x_char = 0;
return;
}
if (uart_tx_stopped(port) || uart_circ_empty(xmit)) {
netx_stop_tx(port);
return;
}
do {
writel(xmit->buf[xmit->tail], port->membase + UART_DR);
xmit->tail = (xmit->tail + 1) &
(UART_XMIT_SIZE - 1);
port->icount.tx++;
if (uart_circ_empty(xmit))
break;
} while (!(readl(port->membase + UART_FR) & FR_TXFF));
if (uart_circ_empty(xmit))
netx_stop_tx(port);
}
static void netx_start_tx(struct uart_port *port)
{
writel(
readl(port->membase + UART_CR) | CR_TIE, port->membase + UART_CR);
if (!(readl(port->membase + UART_FR) & FR_TXFF))
netx_transmit_buffer(port);
}
static unsigned int netx_tx_empty(struct uart_port *port)
{
return readl(port->membase + UART_FR) & FR_BUSY ? 0 : TIOCSER_TEMT;
}
static void netx_txint(struct uart_port *port)
{
struct circ_buf *xmit = &port->state->xmit;
if (uart_circ_empty(xmit) || uart_tx_stopped(port)) {
netx_stop_tx(port);
return;
}
netx_transmit_buffer(port);
if (uart_circ_chars_pending(xmit) < WAKEUP_CHARS)
uart_write_wakeup(port);
}
static void netx_rxint(struct uart_port *port, unsigned long *flags)
{
unsigned char rx, flg, status;
while (!(readl(port->membase + UART_FR) & FR_RXFE)) {
rx = readl(port->membase + UART_DR);
flg = TTY_NORMAL;
port->icount.rx++;
status = readl(port->membase + UART_SR);
if (status & SR_BE) {
writel(0, port->membase + UART_SR);
if (uart_handle_break(port))
continue;
}
if (unlikely(status & (SR_FE | SR_PE | SR_OE))) {
if (status & SR_PE)
port->icount.parity++;
else if (status & SR_FE)
port->icount.frame++;
if (status & SR_OE)
port->icount.overrun++;
status &= port->read_status_mask;
if (status & SR_BE)
flg = TTY_BREAK;
else if (status & SR_PE)
flg = TTY_PARITY;
else if (status & SR_FE)
flg = TTY_FRAME;
}
if (uart_handle_sysrq_char(port, rx))
continue;
uart_insert_char(port, status, SR_OE, rx, flg);
}
spin_unlock_irqrestore(&port->lock, *flags);
tty_flip_buffer_push(&port->state->port);
spin_lock_irqsave(&port->lock, *flags);
}
static irqreturn_t netx_int(int irq, void *dev_id)
{
struct uart_port *port = dev_id;
unsigned long flags;
unsigned char status;
spin_lock_irqsave(&port->lock,flags);
status = readl(port->membase + UART_IIR) & IIR_MASK;
while (status) {
if (status & IIR_RIS)
netx_rxint(port, &flags);
if (status & IIR_TIS)
netx_txint(port);
if (status & IIR_MIS) {
if (readl(port->membase + UART_FR) & FR_CTS)
uart_handle_cts_change(port, 1);
else
uart_handle_cts_change(port, 0);
}
writel(0, port->membase + UART_IIR);
status = readl(port->membase + UART_IIR) & IIR_MASK;
}
spin_unlock_irqrestore(&port->lock,flags);
return IRQ_HANDLED;
}
static unsigned int netx_get_mctrl(struct uart_port *port)
{
unsigned int ret = TIOCM_DSR | TIOCM_CAR;
if (readl(port->membase + UART_FR) & FR_CTS)
ret |= TIOCM_CTS;
return ret;
}
static void netx_set_mctrl(struct uart_port *port, unsigned int mctrl)
{
unsigned int val;
if (mctrl & TIOCM_RTS) {
val = readl(port->membase + UART_RTS_CR);
writel(val | RTS_CR_RTS, port->membase + UART_RTS_CR);
}
}
static void netx_break_ctl(struct uart_port *port, int break_state)
{
unsigned int line_cr;
spin_lock_irq(&port->lock);
line_cr = readl(port->membase + UART_LINE_CR);
if (break_state != 0)
line_cr |= LINE_CR_BRK;
else
line_cr &= ~LINE_CR_BRK;
writel(line_cr, port->membase + UART_LINE_CR);
spin_unlock_irq(&port->lock);
}
static int netx_startup(struct uart_port *port)
{
int ret;
ret = request_irq(port->irq, netx_int, 0,
DRIVER_NAME, port);
if (ret) {
dev_err(port->dev, "unable to grab irq%d\n",port->irq);
goto exit;
}
writel(readl(port->membase + UART_LINE_CR) | LINE_CR_FEN,
port->membase + UART_LINE_CR);
writel(CR_MSIE | CR_RIE | CR_TIE | CR_RTIE | CR_UART_EN,
port->membase + UART_CR);
exit:
return ret;
}
static void netx_shutdown(struct uart_port *port)
{
writel(0, port->membase + UART_CR) ;
free_irq(port->irq, port);
}
static void
netx_set_termios(struct uart_port *port, struct ktermios *termios,
struct ktermios *old)
{
unsigned int baud, quot;
unsigned char old_cr;
unsigned char line_cr = LINE_CR_FEN;
unsigned char rts_cr = 0;
switch (termios->c_cflag & CSIZE) {
case CS5:
line_cr |= LINE_CR_5BIT;
break;
case CS6:
line_cr |= LINE_CR_6BIT;
break;
case CS7:
line_cr |= LINE_CR_7BIT;
break;
case CS8:
line_cr |= LINE_CR_8BIT;
break;
}
if (termios->c_cflag & CSTOPB)
line_cr |= LINE_CR_STP2;
if (termios->c_cflag & PARENB) {
line_cr |= LINE_CR_PEN;
if (!(termios->c_cflag & PARODD))
line_cr |= LINE_CR_EPS;
}
if (termios->c_cflag & CRTSCTS)
rts_cr = RTS_CR_AUTO | RTS_CR_CTS_CTR | RTS_CR_RTS_POL;
baud = uart_get_baud_rate(port, termios, old, 0, port->uartclk/16);
quot = baud * 4096;
quot /= 1000;
quot *= 256;
quot /= 100000;
spin_lock_irq(&port->lock);
uart_update_timeout(port, termios->c_cflag, baud);
old_cr = readl(port->membase + UART_CR);
writel(old_cr & ~(CR_MSIE | CR_RIE | CR_TIE | CR_RTIE),
port->membase + UART_CR);
while (readl(port->membase + UART_FR) & FR_BUSY);
writel(old_cr & ~CR_UART_EN, port->membase + UART_CR);
old_cr &= ~CR_MSIE;
if (UART_ENABLE_MS(port, termios->c_cflag))
old_cr |= CR_MSIE;
writel((quot>>8) & 0xff, port->membase + UART_BAUDDIV_MSB);
writel(quot & 0xff, port->membase + UART_BAUDDIV_LSB);
writel(line_cr, port->membase + UART_LINE_CR);
writel(rts_cr, port->membase + UART_RTS_CR);
port->ignore_status_mask = 0;
if (termios->c_iflag & IGNPAR)
port->ignore_status_mask |= SR_PE;
if (termios->c_iflag & IGNBRK) {
port->ignore_status_mask |= SR_BE;
if (termios->c_iflag & IGNPAR)
port->ignore_status_mask |= SR_PE;
}
port->read_status_mask = 0;
if (termios->c_iflag & (BRKINT | PARMRK))
port->read_status_mask |= SR_BE;
if (termios->c_iflag & INPCK)
port->read_status_mask |= SR_PE | SR_FE;
writel(old_cr, port->membase + UART_CR);
spin_unlock_irq(&port->lock);
}
static const char *netx_type(struct uart_port *port)
{
return port->type == PORT_NETX ? "NETX" : NULL;
}
static void netx_release_port(struct uart_port *port)
{
release_mem_region(port->mapbase, UART_PORT_SIZE);
}
static int netx_request_port(struct uart_port *port)
{
return request_mem_region(port->mapbase, UART_PORT_SIZE,
DRIVER_NAME) != NULL ? 0 : -EBUSY;
}
static void netx_config_port(struct uart_port *port, int flags)
{
if (flags & UART_CONFIG_TYPE && netx_request_port(port) == 0)
port->type = PORT_NETX;
}
static int
netx_verify_port(struct uart_port *port, struct serial_struct *ser)
{
int ret = 0;
if (ser->type != PORT_UNKNOWN && ser->type != PORT_NETX)
ret = -EINVAL;
return ret;
}
static void netx_console_putchar(struct uart_port *port, int ch)
{
while (readl(port->membase + UART_FR) & FR_BUSY);
writel(ch, port->membase + UART_DR);
}
static void
netx_console_write(struct console *co, const char *s, unsigned int count)
{
struct uart_port *port = &netx_ports[co->index].port;
unsigned char cr_save;
cr_save = readl(port->membase + UART_CR);
writel(cr_save | CR_UART_EN, port->membase + UART_CR);
uart_console_write(port, s, count, netx_console_putchar);
while (readl(port->membase + UART_FR) & FR_BUSY);
writel(cr_save, port->membase + UART_CR);
}
static void __init
netx_console_get_options(struct uart_port *port, int *baud,
int *parity, int *bits, int *flow)
{
unsigned char line_cr;
*baud = (readl(port->membase + UART_BAUDDIV_MSB) << 8) |
readl(port->membase + UART_BAUDDIV_LSB);
*baud *= 1000;
*baud /= 4096;
*baud *= 1000;
*baud /= 256;
*baud *= 100;
line_cr = readl(port->membase + UART_LINE_CR);
*parity = 'n';
if (line_cr & LINE_CR_PEN) {
if (line_cr & LINE_CR_EPS)
*parity = 'e';
else
*parity = 'o';
}
switch (line_cr & LINE_CR_BITS_MASK) {
case LINE_CR_8BIT:
*bits = 8;
break;
case LINE_CR_7BIT:
*bits = 7;
break;
case LINE_CR_6BIT:
*bits = 6;
break;
case LINE_CR_5BIT:
*bits = 5;
break;
}
if (readl(port->membase + UART_RTS_CR) & RTS_CR_AUTO)
*flow = 'r';
}
static int __init
netx_console_setup(struct console *co, char *options)
{
struct netx_port *sport;
int baud = 9600;
int bits = 8;
int parity = 'n';
int flow = 'n';
if (co->index == -1 || co->index >= ARRAY_SIZE(netx_ports))
co->index = 0;
sport = &netx_ports[co->index];
if (options) {
uart_parse_options(options, &baud, &parity, &bits, &flow);
} else {
if (readl(sport->port.membase + UART_CR) & CR_UART_EN) {
netx_console_get_options(&sport->port, &baud,
&parity, &bits, &flow);
}
}
return uart_set_options(&sport->port, co, baud, parity, bits, flow);
}
static int __init netx_console_init(void)
{
register_console(&netx_console);
return 0;
}
static int serial_netx_suspend(struct platform_device *pdev, pm_message_t state)
{
struct netx_port *sport = platform_get_drvdata(pdev);
if (sport)
uart_suspend_port(&netx_reg, &sport->port);
return 0;
}
static int serial_netx_resume(struct platform_device *pdev)
{
struct netx_port *sport = platform_get_drvdata(pdev);
if (sport)
uart_resume_port(&netx_reg, &sport->port);
return 0;
}
static int serial_netx_probe(struct platform_device *pdev)
{
struct uart_port *port = &netx_ports[pdev->id].port;
dev_info(&pdev->dev, "initialising\n");
port->dev = &pdev->dev;
writel(1, port->membase + UART_RXFIFO_IRQLEVEL);
uart_add_one_port(&netx_reg, &netx_ports[pdev->id].port);
platform_set_drvdata(pdev, &netx_ports[pdev->id]);
return 0;
}
static int serial_netx_remove(struct platform_device *pdev)
{
struct netx_port *sport = platform_get_drvdata(pdev);
if (sport)
uart_remove_one_port(&netx_reg, &sport->port);
return 0;
}
static int __init netx_serial_init(void)
{
int ret;
printk(KERN_INFO "Serial: NetX driver\n");
ret = uart_register_driver(&netx_reg);
if (ret)
return ret;
ret = platform_driver_register(&serial_netx_driver);
if (ret != 0)
uart_unregister_driver(&netx_reg);
return 0;
}
static void __exit netx_serial_exit(void)
{
platform_driver_unregister(&serial_netx_driver);
uart_unregister_driver(&netx_reg);
}
