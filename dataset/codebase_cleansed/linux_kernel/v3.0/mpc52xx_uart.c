static inline void mpc52xx_set_divisor(struct mpc52xx_psc __iomem *psc,
u16 prescaler, unsigned int divisor)
{
out_be16(&psc->mpc52xx_psc_clock_select, prescaler);
out_8(&psc->ctur, divisor >> 8);
out_8(&psc->ctlr, divisor & 0xff);
}
static void mpc52xx_psc_fifo_init(struct uart_port *port)
{
struct mpc52xx_psc __iomem *psc = PSC(port);
struct mpc52xx_psc_fifo __iomem *fifo = FIFO_52xx(port);
out_8(&fifo->rfcntl, 0x00);
out_be16(&fifo->rfalarm, 0x1ff);
out_8(&fifo->tfcntl, 0x07);
out_be16(&fifo->tfalarm, 0x80);
port->read_status_mask |= MPC52xx_PSC_IMR_RXRDY | MPC52xx_PSC_IMR_TXRDY;
out_be16(&psc->mpc52xx_psc_imr, port->read_status_mask);
}
static int mpc52xx_psc_raw_rx_rdy(struct uart_port *port)
{
return in_be16(&PSC(port)->mpc52xx_psc_status)
& MPC52xx_PSC_SR_RXRDY;
}
static int mpc52xx_psc_raw_tx_rdy(struct uart_port *port)
{
return in_be16(&PSC(port)->mpc52xx_psc_status)
& MPC52xx_PSC_SR_TXRDY;
}
static int mpc52xx_psc_rx_rdy(struct uart_port *port)
{
return in_be16(&PSC(port)->mpc52xx_psc_isr)
& port->read_status_mask
& MPC52xx_PSC_IMR_RXRDY;
}
static int mpc52xx_psc_tx_rdy(struct uart_port *port)
{
return in_be16(&PSC(port)->mpc52xx_psc_isr)
& port->read_status_mask
& MPC52xx_PSC_IMR_TXRDY;
}
static int mpc52xx_psc_tx_empty(struct uart_port *port)
{
return in_be16(&PSC(port)->mpc52xx_psc_status)
& MPC52xx_PSC_SR_TXEMP;
}
static void mpc52xx_psc_start_tx(struct uart_port *port)
{
port->read_status_mask |= MPC52xx_PSC_IMR_TXRDY;
out_be16(&PSC(port)->mpc52xx_psc_imr, port->read_status_mask);
}
static void mpc52xx_psc_stop_tx(struct uart_port *port)
{
port->read_status_mask &= ~MPC52xx_PSC_IMR_TXRDY;
out_be16(&PSC(port)->mpc52xx_psc_imr, port->read_status_mask);
}
static void mpc52xx_psc_stop_rx(struct uart_port *port)
{
port->read_status_mask &= ~MPC52xx_PSC_IMR_RXRDY;
out_be16(&PSC(port)->mpc52xx_psc_imr, port->read_status_mask);
}
static void mpc52xx_psc_rx_clr_irq(struct uart_port *port)
{
}
static void mpc52xx_psc_tx_clr_irq(struct uart_port *port)
{
}
static void mpc52xx_psc_write_char(struct uart_port *port, unsigned char c)
{
out_8(&PSC(port)->mpc52xx_psc_buffer_8, c);
}
static unsigned char mpc52xx_psc_read_char(struct uart_port *port)
{
return in_8(&PSC(port)->mpc52xx_psc_buffer_8);
}
static void mpc52xx_psc_cw_disable_ints(struct uart_port *port)
{
out_be16(&PSC(port)->mpc52xx_psc_imr, 0);
}
static void mpc52xx_psc_cw_restore_ints(struct uart_port *port)
{
out_be16(&PSC(port)->mpc52xx_psc_imr, port->read_status_mask);
}
static unsigned int mpc5200_psc_set_baudrate(struct uart_port *port,
struct ktermios *new,
struct ktermios *old)
{
unsigned int baud;
unsigned int divisor;
baud = uart_get_baud_rate(port, new, old,
port->uartclk / (32 * 0xffff) + 1,
port->uartclk / 32);
divisor = (port->uartclk + 16 * baud) / (32 * baud);
mpc52xx_set_divisor(PSC(port), 0xdd00, divisor);
return baud;
}
static unsigned int mpc5200b_psc_set_baudrate(struct uart_port *port,
struct ktermios *new,
struct ktermios *old)
{
unsigned int baud;
unsigned int divisor;
u16 prescaler;
baud = uart_get_baud_rate(port, new, old,
port->uartclk / (32 * 0xffff) + 1,
port->uartclk / 4);
divisor = (port->uartclk + 2 * baud) / (4 * baud);
if (divisor > 0xffff) {
divisor = (divisor + 4) / 8;
prescaler = 0xdd00;
} else
prescaler = 0xff00;
mpc52xx_set_divisor(PSC(port), prescaler, divisor);
return baud;
}
static void mpc52xx_psc_get_irq(struct uart_port *port, struct device_node *np)
{
port->irqflags = IRQF_DISABLED;
port->irq = irq_of_parse_and_map(np, 0);
}
static irqreturn_t mpc52xx_psc_handle_irq(struct uart_port *port)
{
return mpc5xxx_uart_process_int(port);
}
static void mpc512x_psc_fifo_init(struct uart_port *port)
{
out_be16(&PSC(port)->mpc52xx_psc_clock_select, 0xdd00);
out_be32(&FIFO_512x(port)->txcmd, MPC512x_PSC_FIFO_RESET_SLICE);
out_be32(&FIFO_512x(port)->txcmd, MPC512x_PSC_FIFO_ENABLE_SLICE);
out_be32(&FIFO_512x(port)->txalarm, 1);
out_be32(&FIFO_512x(port)->tximr, 0);
out_be32(&FIFO_512x(port)->rxcmd, MPC512x_PSC_FIFO_RESET_SLICE);
out_be32(&FIFO_512x(port)->rxcmd, MPC512x_PSC_FIFO_ENABLE_SLICE);
out_be32(&FIFO_512x(port)->rxalarm, 1);
out_be32(&FIFO_512x(port)->rximr, 0);
out_be32(&FIFO_512x(port)->tximr, MPC512x_PSC_FIFO_ALARM);
out_be32(&FIFO_512x(port)->rximr, MPC512x_PSC_FIFO_ALARM);
}
static int mpc512x_psc_raw_rx_rdy(struct uart_port *port)
{
return !(in_be32(&FIFO_512x(port)->rxsr) & MPC512x_PSC_FIFO_EMPTY);
}
static int mpc512x_psc_raw_tx_rdy(struct uart_port *port)
{
return !(in_be32(&FIFO_512x(port)->txsr) & MPC512x_PSC_FIFO_FULL);
}
static int mpc512x_psc_rx_rdy(struct uart_port *port)
{
return in_be32(&FIFO_512x(port)->rxsr)
& in_be32(&FIFO_512x(port)->rximr)
& MPC512x_PSC_FIFO_ALARM;
}
static int mpc512x_psc_tx_rdy(struct uart_port *port)
{
return in_be32(&FIFO_512x(port)->txsr)
& in_be32(&FIFO_512x(port)->tximr)
& MPC512x_PSC_FIFO_ALARM;
}
static int mpc512x_psc_tx_empty(struct uart_port *port)
{
return in_be32(&FIFO_512x(port)->txsr)
& MPC512x_PSC_FIFO_EMPTY;
}
static void mpc512x_psc_stop_rx(struct uart_port *port)
{
unsigned long rx_fifo_imr;
rx_fifo_imr = in_be32(&FIFO_512x(port)->rximr);
rx_fifo_imr &= ~MPC512x_PSC_FIFO_ALARM;
out_be32(&FIFO_512x(port)->rximr, rx_fifo_imr);
}
static void mpc512x_psc_start_tx(struct uart_port *port)
{
unsigned long tx_fifo_imr;
tx_fifo_imr = in_be32(&FIFO_512x(port)->tximr);
tx_fifo_imr |= MPC512x_PSC_FIFO_ALARM;
out_be32(&FIFO_512x(port)->tximr, tx_fifo_imr);
}
static void mpc512x_psc_stop_tx(struct uart_port *port)
{
unsigned long tx_fifo_imr;
tx_fifo_imr = in_be32(&FIFO_512x(port)->tximr);
tx_fifo_imr &= ~MPC512x_PSC_FIFO_ALARM;
out_be32(&FIFO_512x(port)->tximr, tx_fifo_imr);
}
static void mpc512x_psc_rx_clr_irq(struct uart_port *port)
{
out_be32(&FIFO_512x(port)->rxisr, in_be32(&FIFO_512x(port)->rxisr));
}
static void mpc512x_psc_tx_clr_irq(struct uart_port *port)
{
out_be32(&FIFO_512x(port)->txisr, in_be32(&FIFO_512x(port)->txisr));
}
static void mpc512x_psc_write_char(struct uart_port *port, unsigned char c)
{
out_8(&FIFO_512x(port)->txdata_8, c);
}
static unsigned char mpc512x_psc_read_char(struct uart_port *port)
{
return in_8(&FIFO_512x(port)->rxdata_8);
}
static void mpc512x_psc_cw_disable_ints(struct uart_port *port)
{
port->read_status_mask =
in_be32(&FIFO_512x(port)->tximr) << 16 |
in_be32(&FIFO_512x(port)->rximr);
out_be32(&FIFO_512x(port)->tximr, 0);
out_be32(&FIFO_512x(port)->rximr, 0);
}
static void mpc512x_psc_cw_restore_ints(struct uart_port *port)
{
out_be32(&FIFO_512x(port)->tximr,
(port->read_status_mask >> 16) & 0x7f);
out_be32(&FIFO_512x(port)->rximr, port->read_status_mask & 0x7f);
}
static unsigned int mpc512x_psc_set_baudrate(struct uart_port *port,
struct ktermios *new,
struct ktermios *old)
{
unsigned int baud;
unsigned int divisor;
baud = uart_get_baud_rate(port, new, old,
port->uartclk / (16 * 0xffff) + 1,
port->uartclk / 16);
divisor = (port->uartclk + 8 * baud) / (16 * baud);
mpc52xx_set_divisor(PSC(port), 0xdd00, divisor);
return baud;
}
static int __init mpc512x_psc_fifoc_init(void)
{
struct device_node *np;
np = of_find_compatible_node(NULL, NULL,
"fsl,mpc5121-psc-fifo");
if (!np) {
pr_err("%s: Can't find FIFOC node\n", __func__);
return -ENODEV;
}
psc_fifoc = of_iomap(np, 0);
if (!psc_fifoc) {
pr_err("%s: Can't map FIFOC\n", __func__);
of_node_put(np);
return -ENODEV;
}
psc_fifoc_irq = irq_of_parse_and_map(np, 0);
of_node_put(np);
if (psc_fifoc_irq == NO_IRQ) {
pr_err("%s: Can't get FIFOC irq\n", __func__);
iounmap(psc_fifoc);
return -ENODEV;
}
return 0;
}
static void __exit mpc512x_psc_fifoc_uninit(void)
{
iounmap(psc_fifoc);
}
static irqreturn_t mpc512x_psc_handle_irq(struct uart_port *port)
{
unsigned long fifoc_int;
int psc_num;
fifoc_int = in_be32(&psc_fifoc->fifoc_int);
psc_num = (port->mapbase & 0xf00) >> 8;
if (test_bit(psc_num, &fifoc_int) ||
test_bit(psc_num + 16, &fifoc_int))
return mpc5xxx_uart_process_int(port);
return IRQ_NONE;
}
static int mpc512x_psc_clock(struct uart_port *port, int enable)
{
struct clk *psc_clk;
int psc_num;
char clk_name[10];
if (uart_console(port))
return 0;
psc_num = (port->mapbase & 0xf00) >> 8;
snprintf(clk_name, sizeof(clk_name), "psc%d_clk", psc_num);
psc_clk = clk_get(port->dev, clk_name);
if (IS_ERR(psc_clk)) {
dev_err(port->dev, "Failed to get PSC clock entry!\n");
return -ENODEV;
}
dev_dbg(port->dev, "%s %sable\n", clk_name, enable ? "en" : "dis");
if (enable)
clk_enable(psc_clk);
else
clk_disable(psc_clk);
return 0;
}
static void mpc512x_psc_get_irq(struct uart_port *port, struct device_node *np)
{
port->irqflags = IRQF_SHARED;
port->irq = psc_fifoc_irq;
}
static unsigned int
mpc52xx_uart_tx_empty(struct uart_port *port)
{
return psc_ops->tx_empty(port) ? TIOCSER_TEMT : 0;
}
static void
mpc52xx_uart_set_mctrl(struct uart_port *port, unsigned int mctrl)
{
if (mctrl & TIOCM_RTS)
out_8(&PSC(port)->op1, MPC52xx_PSC_OP_RTS);
else
out_8(&PSC(port)->op0, MPC52xx_PSC_OP_RTS);
}
static unsigned int
mpc52xx_uart_get_mctrl(struct uart_port *port)
{
unsigned int ret = TIOCM_DSR;
u8 status = in_8(&PSC(port)->mpc52xx_psc_ipcr);
if (!(status & MPC52xx_PSC_CTS))
ret |= TIOCM_CTS;
if (!(status & MPC52xx_PSC_DCD))
ret |= TIOCM_CAR;
return ret;
}
static void
mpc52xx_uart_stop_tx(struct uart_port *port)
{
psc_ops->stop_tx(port);
}
static void
mpc52xx_uart_start_tx(struct uart_port *port)
{
psc_ops->start_tx(port);
}
static void
mpc52xx_uart_send_xchar(struct uart_port *port, char ch)
{
unsigned long flags;
spin_lock_irqsave(&port->lock, flags);
port->x_char = ch;
if (ch) {
psc_ops->start_tx(port);
}
spin_unlock_irqrestore(&port->lock, flags);
}
static void
mpc52xx_uart_stop_rx(struct uart_port *port)
{
psc_ops->stop_rx(port);
}
static void
mpc52xx_uart_enable_ms(struct uart_port *port)
{
struct mpc52xx_psc __iomem *psc = PSC(port);
in_8(&psc->mpc52xx_psc_ipcr);
out_8(&psc->mpc52xx_psc_acr, MPC52xx_PSC_IEC_CTS | MPC52xx_PSC_IEC_DCD);
port->read_status_mask |= MPC52xx_PSC_IMR_IPC;
out_be16(&psc->mpc52xx_psc_imr, port->read_status_mask);
}
static void
mpc52xx_uart_break_ctl(struct uart_port *port, int ctl)
{
unsigned long flags;
spin_lock_irqsave(&port->lock, flags);
if (ctl == -1)
out_8(&PSC(port)->command, MPC52xx_PSC_START_BRK);
else
out_8(&PSC(port)->command, MPC52xx_PSC_STOP_BRK);
spin_unlock_irqrestore(&port->lock, flags);
}
static int
mpc52xx_uart_startup(struct uart_port *port)
{
struct mpc52xx_psc __iomem *psc = PSC(port);
int ret;
if (psc_ops->clock) {
ret = psc_ops->clock(port, 1);
if (ret)
return ret;
}
ret = request_irq(port->irq, mpc52xx_uart_int,
port->irqflags, "mpc52xx_psc_uart", port);
if (ret)
return ret;
out_8(&psc->command, MPC52xx_PSC_RST_RX);
out_8(&psc->command, MPC52xx_PSC_RST_TX);
out_be32(&psc->sicr, 0);
psc_ops->fifo_init(port);
out_8(&psc->command, MPC52xx_PSC_TX_ENABLE);
out_8(&psc->command, MPC52xx_PSC_RX_ENABLE);
return 0;
}
static void
mpc52xx_uart_shutdown(struct uart_port *port)
{
struct mpc52xx_psc __iomem *psc = PSC(port);
out_8(&psc->command, MPC52xx_PSC_RST_RX);
if (!uart_console(port))
out_8(&psc->command, MPC52xx_PSC_RST_TX);
port->read_status_mask = 0;
out_be16(&psc->mpc52xx_psc_imr, port->read_status_mask);
if (psc_ops->clock)
psc_ops->clock(port, 0);
free_irq(port->irq, port);
}
static void
mpc52xx_uart_set_termios(struct uart_port *port, struct ktermios *new,
struct ktermios *old)
{
struct mpc52xx_psc __iomem *psc = PSC(port);
unsigned long flags;
unsigned char mr1, mr2;
unsigned int j;
unsigned int baud;
mr1 = 0;
switch (new->c_cflag & CSIZE) {
case CS5: mr1 |= MPC52xx_PSC_MODE_5_BITS;
break;
case CS6: mr1 |= MPC52xx_PSC_MODE_6_BITS;
break;
case CS7: mr1 |= MPC52xx_PSC_MODE_7_BITS;
break;
case CS8:
default: mr1 |= MPC52xx_PSC_MODE_8_BITS;
}
if (new->c_cflag & PARENB) {
mr1 |= (new->c_cflag & PARODD) ?
MPC52xx_PSC_MODE_PARODD : MPC52xx_PSC_MODE_PAREVEN;
} else
mr1 |= MPC52xx_PSC_MODE_PARNONE;
mr2 = 0;
if (new->c_cflag & CSTOPB)
mr2 |= MPC52xx_PSC_MODE_TWO_STOP;
else
mr2 |= ((new->c_cflag & CSIZE) == CS5) ?
MPC52xx_PSC_MODE_ONE_STOP_5_BITS :
MPC52xx_PSC_MODE_ONE_STOP;
if (new->c_cflag & CRTSCTS) {
mr1 |= MPC52xx_PSC_MODE_RXRTS;
mr2 |= MPC52xx_PSC_MODE_TXCTS;
}
spin_lock_irqsave(&port->lock, flags);
j = 5000000;
while (!mpc52xx_uart_tx_empty(port) && --j)
udelay(1);
if (!j)
printk(KERN_ERR "mpc52xx_uart.c: "
"Unable to flush RX & TX fifos in-time in set_termios."
"Some chars may have been lost.\n");
out_8(&psc->command, MPC52xx_PSC_RST_RX);
out_8(&psc->command, MPC52xx_PSC_RST_TX);
out_8(&psc->command, MPC52xx_PSC_SEL_MODE_REG_1);
out_8(&psc->mode, mr1);
out_8(&psc->mode, mr2);
baud = psc_ops->set_baudrate(port, new, old);
uart_update_timeout(port, new->c_cflag, baud);
if (UART_ENABLE_MS(port, new->c_cflag))
mpc52xx_uart_enable_ms(port);
out_8(&psc->command, MPC52xx_PSC_TX_ENABLE);
out_8(&psc->command, MPC52xx_PSC_RX_ENABLE);
spin_unlock_irqrestore(&port->lock, flags);
}
static const char *
mpc52xx_uart_type(struct uart_port *port)
{
return port->type == PORT_MPC52xx ? "MPC5xxx PSC" : NULL;
}
static void
mpc52xx_uart_release_port(struct uart_port *port)
{
if (port->flags & UPF_IOREMAP) {
iounmap(port->membase);
port->membase = NULL;
}
release_mem_region(port->mapbase, sizeof(struct mpc52xx_psc));
}
static int
mpc52xx_uart_request_port(struct uart_port *port)
{
int err;
if (port->flags & UPF_IOREMAP)
port->membase = ioremap(port->mapbase,
sizeof(struct mpc52xx_psc));
if (!port->membase)
return -EINVAL;
err = request_mem_region(port->mapbase, sizeof(struct mpc52xx_psc),
"mpc52xx_psc_uart") != NULL ? 0 : -EBUSY;
if (err && (port->flags & UPF_IOREMAP)) {
iounmap(port->membase);
port->membase = NULL;
}
return err;
}
static void
mpc52xx_uart_config_port(struct uart_port *port, int flags)
{
if ((flags & UART_CONFIG_TYPE)
&& (mpc52xx_uart_request_port(port) == 0))
port->type = PORT_MPC52xx;
}
static int
mpc52xx_uart_verify_port(struct uart_port *port, struct serial_struct *ser)
{
if (ser->type != PORT_UNKNOWN && ser->type != PORT_MPC52xx)
return -EINVAL;
if ((ser->irq != port->irq) ||
(ser->io_type != UPIO_MEM) ||
(ser->baud_base != port->uartclk) ||
(ser->iomem_base != (void *)port->mapbase) ||
(ser->hub6 != 0))
return -EINVAL;
return 0;
}
static inline int
mpc52xx_uart_int_rx_chars(struct uart_port *port)
{
struct tty_struct *tty = port->state->port.tty;
unsigned char ch, flag;
unsigned short status;
while (psc_ops->raw_rx_rdy(port)) {
ch = psc_ops->read_char(port);
#ifdef SUPPORT_SYSRQ
if (uart_handle_sysrq_char(port, ch)) {
port->sysrq = 0;
continue;
}
#endif
flag = TTY_NORMAL;
port->icount.rx++;
status = in_be16(&PSC(port)->mpc52xx_psc_status);
if (status & (MPC52xx_PSC_SR_PE |
MPC52xx_PSC_SR_FE |
MPC52xx_PSC_SR_RB)) {
if (status & MPC52xx_PSC_SR_RB) {
flag = TTY_BREAK;
uart_handle_break(port);
port->icount.brk++;
} else if (status & MPC52xx_PSC_SR_PE) {
flag = TTY_PARITY;
port->icount.parity++;
}
else if (status & MPC52xx_PSC_SR_FE) {
flag = TTY_FRAME;
port->icount.frame++;
}
out_8(&PSC(port)->command, MPC52xx_PSC_RST_ERR_STAT);
}
tty_insert_flip_char(tty, ch, flag);
if (status & MPC52xx_PSC_SR_OE) {
tty_insert_flip_char(tty, 0, TTY_OVERRUN);
port->icount.overrun++;
}
}
spin_unlock(&port->lock);
tty_flip_buffer_push(tty);
spin_lock(&port->lock);
return psc_ops->raw_rx_rdy(port);
}
static inline int
mpc52xx_uart_int_tx_chars(struct uart_port *port)
{
struct circ_buf *xmit = &port->state->xmit;
if (port->x_char) {
psc_ops->write_char(port, port->x_char);
port->icount.tx++;
port->x_char = 0;
return 1;
}
if (uart_circ_empty(xmit) || uart_tx_stopped(port)) {
mpc52xx_uart_stop_tx(port);
return 0;
}
while (psc_ops->raw_tx_rdy(port)) {
psc_ops->write_char(port, xmit->buf[xmit->tail]);
xmit->tail = (xmit->tail + 1) & (UART_XMIT_SIZE - 1);
port->icount.tx++;
if (uart_circ_empty(xmit))
break;
}
if (uart_circ_chars_pending(xmit) < WAKEUP_CHARS)
uart_write_wakeup(port);
if (uart_circ_empty(xmit)) {
mpc52xx_uart_stop_tx(port);
return 0;
}
return 1;
}
static irqreturn_t
mpc5xxx_uart_process_int(struct uart_port *port)
{
unsigned long pass = ISR_PASS_LIMIT;
unsigned int keepgoing;
u8 status;
do {
keepgoing = 0;
psc_ops->rx_clr_irq(port);
if (psc_ops->rx_rdy(port))
keepgoing |= mpc52xx_uart_int_rx_chars(port);
psc_ops->tx_clr_irq(port);
if (psc_ops->tx_rdy(port))
keepgoing |= mpc52xx_uart_int_tx_chars(port);
status = in_8(&PSC(port)->mpc52xx_psc_ipcr);
if (status & MPC52xx_PSC_D_DCD)
uart_handle_dcd_change(port, !(status & MPC52xx_PSC_DCD));
if (status & MPC52xx_PSC_D_CTS)
uart_handle_cts_change(port, !(status & MPC52xx_PSC_CTS));
if (!(--pass))
keepgoing = 0;
} while (keepgoing);
return IRQ_HANDLED;
}
static irqreturn_t
mpc52xx_uart_int(int irq, void *dev_id)
{
struct uart_port *port = dev_id;
irqreturn_t ret;
spin_lock(&port->lock);
ret = psc_ops->handle_irq(port);
spin_unlock(&port->lock);
return ret;
}
static void __init
mpc52xx_console_get_options(struct uart_port *port,
int *baud, int *parity, int *bits, int *flow)
{
struct mpc52xx_psc __iomem *psc = PSC(port);
unsigned char mr1;
pr_debug("mpc52xx_console_get_options(port=%p)\n", port);
out_8(&psc->command, MPC52xx_PSC_SEL_MODE_REG_1);
mr1 = in_8(&psc->mode);
*baud = CONFIG_SERIAL_MPC52xx_CONSOLE_BAUD;
switch (mr1 & MPC52xx_PSC_MODE_BITS_MASK) {
case MPC52xx_PSC_MODE_5_BITS:
*bits = 5;
break;
case MPC52xx_PSC_MODE_6_BITS:
*bits = 6;
break;
case MPC52xx_PSC_MODE_7_BITS:
*bits = 7;
break;
case MPC52xx_PSC_MODE_8_BITS:
default:
*bits = 8;
}
if (mr1 & MPC52xx_PSC_MODE_PARNONE)
*parity = 'n';
else
*parity = mr1 & MPC52xx_PSC_MODE_PARODD ? 'o' : 'e';
}
static void
mpc52xx_console_write(struct console *co, const char *s, unsigned int count)
{
struct uart_port *port = &mpc52xx_uart_ports[co->index];
unsigned int i, j;
psc_ops->cw_disable_ints(port);
j = 5000000;
while (!mpc52xx_uart_tx_empty(port) && --j)
udelay(1);
for (i = 0; i < count; i++, s++) {
if (*s == '\n')
psc_ops->write_char(port, '\r');
psc_ops->write_char(port, *s);
j = 20000;
while (!mpc52xx_uart_tx_empty(port) && --j)
udelay(1);
}
psc_ops->cw_restore_ints(port);
}
static int __init
mpc52xx_console_setup(struct console *co, char *options)
{
struct uart_port *port = &mpc52xx_uart_ports[co->index];
struct device_node *np = mpc52xx_uart_nodes[co->index];
unsigned int uartclk;
struct resource res;
int ret;
int baud = CONFIG_SERIAL_MPC52xx_CONSOLE_BAUD;
int bits = 8;
int parity = 'n';
int flow = 'n';
pr_debug("mpc52xx_console_setup co=%p, co->index=%i, options=%s\n",
co, co->index, options);
if ((co->index < 0) || (co->index >= MPC52xx_PSC_MAXNUM)) {
pr_debug("PSC%x out of range\n", co->index);
return -EINVAL;
}
if (!np) {
pr_debug("PSC%x not found in device tree\n", co->index);
return -EINVAL;
}
pr_debug("Console on ttyPSC%x is %s\n",
co->index, mpc52xx_uart_nodes[co->index]->full_name);
ret = of_address_to_resource(np, 0, &res);
if (ret) {
pr_debug("Could not get resources for PSC%x\n", co->index);
return ret;
}
uartclk = mpc5xxx_get_bus_frequency(np);
if (uartclk == 0) {
pr_debug("Could not find uart clock frequency!\n");
return -EINVAL;
}
spin_lock_init(&port->lock);
port->uartclk = uartclk;
port->ops = &mpc52xx_uart_ops;
port->mapbase = res.start;
port->membase = ioremap(res.start, sizeof(struct mpc52xx_psc));
port->irq = irq_of_parse_and_map(np, 0);
if (port->membase == NULL)
return -EINVAL;
pr_debug("mpc52xx-psc uart at %p, mapped to %p, irq=%x, freq=%i\n",
(void *)port->mapbase, port->membase,
port->irq, port->uartclk);
if (options)
uart_parse_options(options, &baud, &parity, &bits, &flow);
else
mpc52xx_console_get_options(port, &baud, &parity, &bits, &flow);
pr_debug("Setting console parameters: %i %i%c1 flow=%c\n",
baud, bits, parity, flow);
return uart_set_options(port, co, baud, parity, bits, flow);
}
static int __init
mpc52xx_console_init(void)
{
mpc52xx_uart_of_enumerate();
register_console(&mpc52xx_console);
return 0;
}
static int __devinit mpc52xx_uart_of_probe(struct platform_device *op)
{
int idx = -1;
unsigned int uartclk;
struct uart_port *port = NULL;
struct resource res;
int ret;
for (idx = 0; idx < MPC52xx_PSC_MAXNUM; idx++)
if (mpc52xx_uart_nodes[idx] == op->dev.of_node)
break;
if (idx >= MPC52xx_PSC_MAXNUM)
return -EINVAL;
pr_debug("Found %s assigned to ttyPSC%x\n",
mpc52xx_uart_nodes[idx]->full_name, idx);
uartclk = mpc5xxx_get_bus_frequency(op->dev.of_node);
if (uartclk == 0) {
dev_dbg(&op->dev, "Could not find uart clock frequency!\n");
return -EINVAL;
}
port = &mpc52xx_uart_ports[idx];
spin_lock_init(&port->lock);
port->uartclk = uartclk;
port->fifosize = 512;
port->iotype = UPIO_MEM;
port->flags = UPF_BOOT_AUTOCONF |
(uart_console(port) ? 0 : UPF_IOREMAP);
port->line = idx;
port->ops = &mpc52xx_uart_ops;
port->dev = &op->dev;
ret = of_address_to_resource(op->dev.of_node, 0, &res);
if (ret)
return ret;
port->mapbase = res.start;
if (!port->mapbase) {
dev_dbg(&op->dev, "Could not allocate resources for PSC\n");
return -EINVAL;
}
psc_ops->get_irq(port, op->dev.of_node);
if (port->irq == NO_IRQ) {
dev_dbg(&op->dev, "Could not get irq\n");
return -EINVAL;
}
dev_dbg(&op->dev, "mpc52xx-psc uart at %p, irq=%x, freq=%i\n",
(void *)port->mapbase, port->irq, port->uartclk);
ret = uart_add_one_port(&mpc52xx_uart_driver, port);
if (ret)
return ret;
dev_set_drvdata(&op->dev, (void *)port);
return 0;
}
static int
mpc52xx_uart_of_remove(struct platform_device *op)
{
struct uart_port *port = dev_get_drvdata(&op->dev);
dev_set_drvdata(&op->dev, NULL);
if (port)
uart_remove_one_port(&mpc52xx_uart_driver, port);
return 0;
}
static int
mpc52xx_uart_of_suspend(struct platform_device *op, pm_message_t state)
{
struct uart_port *port = (struct uart_port *) dev_get_drvdata(&op->dev);
if (port)
uart_suspend_port(&mpc52xx_uart_driver, port);
return 0;
}
static int
mpc52xx_uart_of_resume(struct platform_device *op)
{
struct uart_port *port = (struct uart_port *) dev_get_drvdata(&op->dev);
if (port)
uart_resume_port(&mpc52xx_uart_driver, port);
return 0;
}
static void
mpc52xx_uart_of_assign(struct device_node *np)
{
int i;
for (i = 0; i < MPC52xx_PSC_MAXNUM; i++) {
if (mpc52xx_uart_nodes[i] == NULL) {
of_node_get(np);
mpc52xx_uart_nodes[i] = np;
return;
}
}
}
static void
mpc52xx_uart_of_enumerate(void)
{
static int enum_done;
struct device_node *np;
const struct of_device_id *match;
int i;
if (enum_done)
return;
for_each_matching_node(np, mpc52xx_uart_of_match) {
match = of_match_node(mpc52xx_uart_of_match, np);
psc_ops = match->data;
mpc52xx_uart_of_assign(np);
}
enum_done = 1;
for (i = 0; i < MPC52xx_PSC_MAXNUM; i++) {
if (mpc52xx_uart_nodes[i])
pr_debug("%s assigned to ttyPSC%x\n",
mpc52xx_uart_nodes[i]->full_name, i);
}
}
static int __init
mpc52xx_uart_init(void)
{
int ret;
printk(KERN_INFO "Serial: MPC52xx PSC UART driver\n");
ret = uart_register_driver(&mpc52xx_uart_driver);
if (ret) {
printk(KERN_ERR "%s: uart_register_driver failed (%i)\n",
__FILE__, ret);
return ret;
}
mpc52xx_uart_of_enumerate();
if (psc_ops && psc_ops->fifoc_init) {
ret = psc_ops->fifoc_init();
if (ret)
return ret;
}
ret = platform_driver_register(&mpc52xx_uart_of_driver);
if (ret) {
printk(KERN_ERR "%s: platform_driver_register failed (%i)\n",
__FILE__, ret);
uart_unregister_driver(&mpc52xx_uart_driver);
return ret;
}
return 0;
}
static void __exit
mpc52xx_uart_exit(void)
{
if (psc_ops->fifoc_uninit)
psc_ops->fifoc_uninit();
platform_driver_unregister(&mpc52xx_uart_of_driver);
uart_unregister_driver(&mpc52xx_uart_driver);
}
