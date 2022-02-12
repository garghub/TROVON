static unsigned int bfin_serial_get_mctrl(struct uart_port *port)
{
struct bfin_serial_port *uart = (struct bfin_serial_port *)port;
if (uart->cts_pin < 0)
return TIOCM_CTS | TIOCM_DSR | TIOCM_CAR;
if (UART_GET_CTS(uart))
return TIOCM_CTS | TIOCM_DSR | TIOCM_CAR;
else
return TIOCM_DSR | TIOCM_CAR;
}
static void bfin_serial_set_mctrl(struct uart_port *port, unsigned int mctrl)
{
struct bfin_serial_port *uart = (struct bfin_serial_port *)port;
if (uart->rts_pin < 0)
return;
if (mctrl & TIOCM_RTS)
UART_ENABLE_RTS(uart);
else
UART_DISABLE_RTS(uart);
}
static irqreturn_t bfin_serial_mctrl_cts_int(int irq, void *dev_id)
{
struct bfin_serial_port *uart = dev_id;
unsigned int status;
status = bfin_serial_get_mctrl(&uart->port);
uart_handle_cts_change(&uart->port, status & TIOCM_CTS);
#ifdef CONFIG_SERIAL_BFIN_HARD_CTSRTS
uart->scts = 1;
UART_CLEAR_SCTS(uart);
UART_CLEAR_IER(uart, EDSSI);
#endif
return IRQ_HANDLED;
}
static unsigned int bfin_serial_get_mctrl(struct uart_port *port)
{
return TIOCM_CTS | TIOCM_DSR | TIOCM_CAR;
}
static void bfin_serial_set_mctrl(struct uart_port *port, unsigned int mctrl)
{
}
static void bfin_serial_stop_tx(struct uart_port *port)
{
struct bfin_serial_port *uart = (struct bfin_serial_port *)port;
#ifdef CONFIG_SERIAL_BFIN_DMA
struct circ_buf *xmit = &uart->port.state->xmit;
#endif
while (!(UART_GET_LSR(uart) & TEMT))
cpu_relax();
#ifdef CONFIG_SERIAL_BFIN_DMA
disable_dma(uart->tx_dma_channel);
xmit->tail = (xmit->tail + uart->tx_count) & (UART_XMIT_SIZE - 1);
uart->port.icount.tx += uart->tx_count;
uart->tx_count = 0;
uart->tx_done = 1;
#else
#ifdef CONFIG_BF54x
UART_PUT_LSR(uart, TFI);
#endif
UART_CLEAR_IER(uart, ETBEI);
#endif
}
static void bfin_serial_start_tx(struct uart_port *port)
{
struct bfin_serial_port *uart = (struct bfin_serial_port *)port;
struct tty_struct *tty = uart->port.state->port.tty;
#ifdef CONFIG_SERIAL_BFIN_HARD_CTSRTS
if (uart->scts && !(bfin_serial_get_mctrl(&uart->port) & TIOCM_CTS)) {
uart->scts = 0;
uart_handle_cts_change(&uart->port, uart->scts);
}
#endif
if (tty->termios->c_line == N_IRDA)
bfin_serial_reset_irda(port);
#ifdef CONFIG_SERIAL_BFIN_DMA
if (uart->tx_done)
bfin_serial_dma_tx_chars(uart);
#else
UART_SET_IER(uart, ETBEI);
bfin_serial_tx_chars(uart);
#endif
}
static void bfin_serial_stop_rx(struct uart_port *port)
{
struct bfin_serial_port *uart = (struct bfin_serial_port *)port;
UART_CLEAR_IER(uart, ERBFI);
}
static void bfin_serial_enable_ms(struct uart_port *port)
{
}
static void bfin_serial_rx_chars(struct bfin_serial_port *uart)
{
struct tty_struct *tty = NULL;
unsigned int status, ch, flg;
static struct timeval anomaly_start = { .tv_sec = 0 };
status = UART_GET_LSR(uart);
UART_CLEAR_LSR(uart);
ch = UART_GET_CHAR(uart);
uart->port.icount.rx++;
#if defined(CONFIG_KGDB_SERIAL_CONSOLE) || \
defined(CONFIG_KGDB_SERIAL_CONSOLE_MODULE)
if (kgdb_connected && kgdboc_port_line == uart->port.line
&& kgdboc_break_enabled)
if (ch == 0x3) {
kgdb_breakpoint();
return;
}
if (!uart->port.state || !uart->port.state->port.tty)
return;
#endif
tty = uart->port.state->port.tty;
if (ANOMALY_05000363) {
if (anomaly_start.tv_sec) {
struct timeval curr;
suseconds_t usecs;
if ((~ch & (~ch + 1)) & 0xff)
goto known_good_char;
do_gettimeofday(&curr);
if (curr.tv_sec - anomaly_start.tv_sec > 1)
goto known_good_char;
usecs = 0;
if (curr.tv_sec != anomaly_start.tv_sec)
usecs += USEC_PER_SEC;
usecs += curr.tv_usec - anomaly_start.tv_usec;
if (usecs > UART_GET_ANOMALY_THRESHOLD(uart))
goto known_good_char;
if (ch)
anomaly_start.tv_sec = 0;
else
anomaly_start = curr;
return;
known_good_char:
status &= ~BI;
anomaly_start.tv_sec = 0;
}
}
if (status & BI) {
if (ANOMALY_05000363)
if (bfin_revid() < 5)
do_gettimeofday(&anomaly_start);
uart->port.icount.brk++;
if (uart_handle_break(&uart->port))
goto ignore_char;
status &= ~(PE | FE);
}
if (status & PE)
uart->port.icount.parity++;
if (status & OE)
uart->port.icount.overrun++;
if (status & FE)
uart->port.icount.frame++;
status &= uart->port.read_status_mask;
if (status & BI)
flg = TTY_BREAK;
else if (status & PE)
flg = TTY_PARITY;
else if (status & FE)
flg = TTY_FRAME;
else
flg = TTY_NORMAL;
if (uart_handle_sysrq_char(&uart->port, ch))
goto ignore_char;
uart_insert_char(&uart->port, status, OE, ch, flg);
ignore_char:
tty_flip_buffer_push(tty);
}
static void bfin_serial_tx_chars(struct bfin_serial_port *uart)
{
struct circ_buf *xmit = &uart->port.state->xmit;
if (uart_circ_empty(xmit) || uart_tx_stopped(&uart->port)) {
#ifdef CONFIG_BF54x
UART_PUT_LSR(uart, TFI);
#endif
UART_CLEAR_IER(uart, ETBEI);
return;
}
if (uart->port.x_char) {
UART_PUT_CHAR(uart, uart->port.x_char);
uart->port.icount.tx++;
uart->port.x_char = 0;
}
while ((UART_GET_LSR(uart) & THRE) && xmit->tail != xmit->head) {
UART_PUT_CHAR(uart, xmit->buf[xmit->tail]);
xmit->tail = (xmit->tail + 1) & (UART_XMIT_SIZE - 1);
uart->port.icount.tx++;
}
if (uart_circ_chars_pending(xmit) < WAKEUP_CHARS)
uart_write_wakeup(&uart->port);
}
static irqreturn_t bfin_serial_rx_int(int irq, void *dev_id)
{
struct bfin_serial_port *uart = dev_id;
while (UART_GET_LSR(uart) & DR)
bfin_serial_rx_chars(uart);
return IRQ_HANDLED;
}
static irqreturn_t bfin_serial_tx_int(int irq, void *dev_id)
{
struct bfin_serial_port *uart = dev_id;
#ifdef CONFIG_SERIAL_BFIN_HARD_CTSRTS
if (uart->scts && !(bfin_serial_get_mctrl(&uart->port) & TIOCM_CTS)) {
uart->scts = 0;
uart_handle_cts_change(&uart->port, uart->scts);
}
#endif
spin_lock(&uart->port.lock);
if (UART_GET_LSR(uart) & THRE)
bfin_serial_tx_chars(uart);
spin_unlock(&uart->port.lock);
return IRQ_HANDLED;
}
static void bfin_serial_dma_tx_chars(struct bfin_serial_port *uart)
{
struct circ_buf *xmit = &uart->port.state->xmit;
uart->tx_done = 0;
if (uart_circ_empty(xmit) || uart_tx_stopped(&uart->port)) {
uart->tx_count = 0;
uart->tx_done = 1;
return;
}
if (uart->port.x_char) {
UART_PUT_CHAR(uart, uart->port.x_char);
uart->port.icount.tx++;
uart->port.x_char = 0;
}
uart->tx_count = CIRC_CNT(xmit->head, xmit->tail, UART_XMIT_SIZE);
if (uart->tx_count > (UART_XMIT_SIZE - xmit->tail))
uart->tx_count = UART_XMIT_SIZE - xmit->tail;
blackfin_dcache_flush_range((unsigned long)(xmit->buf+xmit->tail),
(unsigned long)(xmit->buf+xmit->tail+uart->tx_count));
set_dma_config(uart->tx_dma_channel,
set_bfin_dma_config(DIR_READ, DMA_FLOW_STOP,
INTR_ON_BUF,
DIMENSION_LINEAR,
DATA_SIZE_8,
DMA_SYNC_RESTART));
set_dma_start_addr(uart->tx_dma_channel, (unsigned long)(xmit->buf+xmit->tail));
set_dma_x_count(uart->tx_dma_channel, uart->tx_count);
set_dma_x_modify(uart->tx_dma_channel, 1);
SSYNC();
enable_dma(uart->tx_dma_channel);
UART_SET_IER(uart, ETBEI);
}
static void bfin_serial_dma_rx_chars(struct bfin_serial_port *uart)
{
struct tty_struct *tty = uart->port.state->port.tty;
int i, flg, status;
status = UART_GET_LSR(uart);
UART_CLEAR_LSR(uart);
uart->port.icount.rx +=
CIRC_CNT(uart->rx_dma_buf.head, uart->rx_dma_buf.tail,
UART_XMIT_SIZE);
if (status & BI) {
uart->port.icount.brk++;
if (uart_handle_break(&uart->port))
goto dma_ignore_char;
status &= ~(PE | FE);
}
if (status & PE)
uart->port.icount.parity++;
if (status & OE)
uart->port.icount.overrun++;
if (status & FE)
uart->port.icount.frame++;
status &= uart->port.read_status_mask;
if (status & BI)
flg = TTY_BREAK;
else if (status & PE)
flg = TTY_PARITY;
else if (status & FE)
flg = TTY_FRAME;
else
flg = TTY_NORMAL;
for (i = uart->rx_dma_buf.tail; ; i++) {
if (i >= UART_XMIT_SIZE)
i = 0;
if (i == uart->rx_dma_buf.head)
break;
if (!uart_handle_sysrq_char(&uart->port, uart->rx_dma_buf.buf[i]))
uart_insert_char(&uart->port, status, OE,
uart->rx_dma_buf.buf[i], flg);
}
dma_ignore_char:
tty_flip_buffer_push(tty);
}
void bfin_serial_rx_dma_timeout(struct bfin_serial_port *uart)
{
int x_pos, pos;
dma_disable_irq_nosync(uart->rx_dma_channel);
spin_lock_bh(&uart->rx_lock);
uart->rx_dma_nrows = get_dma_curr_ycount(uart->rx_dma_channel);
x_pos = get_dma_curr_xcount(uart->rx_dma_channel);
uart->rx_dma_nrows = DMA_RX_YCOUNT - uart->rx_dma_nrows;
if (uart->rx_dma_nrows == DMA_RX_YCOUNT || x_pos == 0)
uart->rx_dma_nrows = 0;
x_pos = DMA_RX_XCOUNT - x_pos;
if (x_pos == DMA_RX_XCOUNT)
x_pos = 0;
pos = uart->rx_dma_nrows * DMA_RX_XCOUNT + x_pos;
if (pos > uart->rx_dma_buf.tail ||
uart->rx_dma_nrows < (uart->rx_dma_buf.tail/DMA_RX_XCOUNT)) {
uart->rx_dma_buf.head = pos;
bfin_serial_dma_rx_chars(uart);
uart->rx_dma_buf.tail = uart->rx_dma_buf.head;
}
spin_unlock_bh(&uart->rx_lock);
dma_enable_irq(uart->rx_dma_channel);
mod_timer(&(uart->rx_dma_timer), jiffies + DMA_RX_FLUSH_JIFFIES);
}
static irqreturn_t bfin_serial_dma_tx_int(int irq, void *dev_id)
{
struct bfin_serial_port *uart = dev_id;
struct circ_buf *xmit = &uart->port.state->xmit;
#ifdef CONFIG_SERIAL_BFIN_HARD_CTSRTS
if (uart->scts && !(bfin_serial_get_mctrl(&uart->port)&TIOCM_CTS)) {
uart->scts = 0;
uart_handle_cts_change(&uart->port, uart->scts);
}
#endif
spin_lock(&uart->port.lock);
if (!(get_dma_curr_irqstat(uart->tx_dma_channel)&DMA_RUN)) {
disable_dma(uart->tx_dma_channel);
clear_dma_irqstat(uart->tx_dma_channel);
UART_CLEAR_IER(uart, ETBEI);
xmit->tail = (xmit->tail + uart->tx_count) & (UART_XMIT_SIZE - 1);
uart->port.icount.tx += uart->tx_count;
if (uart_circ_chars_pending(xmit) < WAKEUP_CHARS)
uart_write_wakeup(&uart->port);
bfin_serial_dma_tx_chars(uart);
}
spin_unlock(&uart->port.lock);
return IRQ_HANDLED;
}
static irqreturn_t bfin_serial_dma_rx_int(int irq, void *dev_id)
{
struct bfin_serial_port *uart = dev_id;
unsigned short irqstat;
int x_pos, pos;
spin_lock(&uart->rx_lock);
irqstat = get_dma_curr_irqstat(uart->rx_dma_channel);
clear_dma_irqstat(uart->rx_dma_channel);
uart->rx_dma_nrows = get_dma_curr_ycount(uart->rx_dma_channel);
x_pos = get_dma_curr_xcount(uart->rx_dma_channel);
uart->rx_dma_nrows = DMA_RX_YCOUNT - uart->rx_dma_nrows;
if (uart->rx_dma_nrows == DMA_RX_YCOUNT || x_pos == 0)
uart->rx_dma_nrows = 0;
pos = uart->rx_dma_nrows * DMA_RX_XCOUNT;
if (pos > uart->rx_dma_buf.tail ||
uart->rx_dma_nrows < (uart->rx_dma_buf.tail/DMA_RX_XCOUNT)) {
uart->rx_dma_buf.head = pos;
bfin_serial_dma_rx_chars(uart);
uart->rx_dma_buf.tail = uart->rx_dma_buf.head;
}
spin_unlock(&uart->rx_lock);
return IRQ_HANDLED;
}
static unsigned int bfin_serial_tx_empty(struct uart_port *port)
{
struct bfin_serial_port *uart = (struct bfin_serial_port *)port;
unsigned short lsr;
lsr = UART_GET_LSR(uart);
if (lsr & TEMT)
return TIOCSER_TEMT;
else
return 0;
}
static void bfin_serial_break_ctl(struct uart_port *port, int break_state)
{
struct bfin_serial_port *uart = (struct bfin_serial_port *)port;
u16 lcr = UART_GET_LCR(uart);
if (break_state)
lcr |= SB;
else
lcr &= ~SB;
UART_PUT_LCR(uart, lcr);
SSYNC();
}
static int bfin_serial_startup(struct uart_port *port)
{
struct bfin_serial_port *uart = (struct bfin_serial_port *)port;
#ifdef CONFIG_SERIAL_BFIN_DMA
dma_addr_t dma_handle;
if (request_dma(uart->rx_dma_channel, "BFIN_UART_RX") < 0) {
printk(KERN_NOTICE "Unable to attach Blackfin UART RX DMA channel\n");
return -EBUSY;
}
if (request_dma(uart->tx_dma_channel, "BFIN_UART_TX") < 0) {
printk(KERN_NOTICE "Unable to attach Blackfin UART TX DMA channel\n");
free_dma(uart->rx_dma_channel);
return -EBUSY;
}
set_dma_callback(uart->rx_dma_channel, bfin_serial_dma_rx_int, uart);
set_dma_callback(uart->tx_dma_channel, bfin_serial_dma_tx_int, uart);
uart->rx_dma_buf.buf = (unsigned char *)dma_alloc_coherent(NULL, PAGE_SIZE, &dma_handle, GFP_DMA);
uart->rx_dma_buf.head = 0;
uart->rx_dma_buf.tail = 0;
uart->rx_dma_nrows = 0;
set_dma_config(uart->rx_dma_channel,
set_bfin_dma_config(DIR_WRITE, DMA_FLOW_AUTO,
INTR_ON_ROW, DIMENSION_2D,
DATA_SIZE_8,
DMA_SYNC_RESTART));
set_dma_x_count(uart->rx_dma_channel, DMA_RX_XCOUNT);
set_dma_x_modify(uart->rx_dma_channel, 1);
set_dma_y_count(uart->rx_dma_channel, DMA_RX_YCOUNT);
set_dma_y_modify(uart->rx_dma_channel, 1);
set_dma_start_addr(uart->rx_dma_channel, (unsigned long)uart->rx_dma_buf.buf);
enable_dma(uart->rx_dma_channel);
uart->rx_dma_timer.data = (unsigned long)(uart);
uart->rx_dma_timer.function = (void *)bfin_serial_rx_dma_timeout;
uart->rx_dma_timer.expires = jiffies + DMA_RX_FLUSH_JIFFIES;
add_timer(&(uart->rx_dma_timer));
#else
# if defined(CONFIG_KGDB_SERIAL_CONSOLE) || \
defined(CONFIG_KGDB_SERIAL_CONSOLE_MODULE)
if (kgdboc_port_line == uart->port.line && kgdboc_break_enabled)
kgdboc_break_enabled = 0;
else {
# endif
if (request_irq(uart->port.irq, bfin_serial_rx_int, IRQF_DISABLED,
"BFIN_UART_RX", uart)) {
printk(KERN_NOTICE "Unable to attach BlackFin UART RX interrupt\n");
return -EBUSY;
}
if (request_irq
(uart->port.irq+1, bfin_serial_tx_int, IRQF_DISABLED,
"BFIN_UART_TX", uart)) {
printk(KERN_NOTICE "Unable to attach BlackFin UART TX interrupt\n");
free_irq(uart->port.irq, uart);
return -EBUSY;
}
# ifdef CONFIG_BF54x
{
unsigned uart_dma_ch_rx, uart_dma_ch_tx;
switch (uart->port.irq) {
case IRQ_UART3_RX:
uart_dma_ch_rx = CH_UART3_RX;
uart_dma_ch_tx = CH_UART3_TX;
break;
case IRQ_UART2_RX:
uart_dma_ch_rx = CH_UART2_RX;
uart_dma_ch_tx = CH_UART2_TX;
break;
default:
uart_dma_ch_rx = uart_dma_ch_tx = 0;
break;
};
if (uart_dma_ch_rx &&
request_dma(uart_dma_ch_rx, "BFIN_UART_RX") < 0) {
printk(KERN_NOTICE"Fail to attach UART interrupt\n");
free_irq(uart->port.irq, uart);
free_irq(uart->port.irq + 1, uart);
return -EBUSY;
}
if (uart_dma_ch_tx &&
request_dma(uart_dma_ch_tx, "BFIN_UART_TX") < 0) {
printk(KERN_NOTICE "Fail to attach UART interrupt\n");
free_dma(uart_dma_ch_rx);
free_irq(uart->port.irq, uart);
free_irq(uart->port.irq + 1, uart);
return -EBUSY;
}
}
# endif
# if defined(CONFIG_KGDB_SERIAL_CONSOLE) || \
defined(CONFIG_KGDB_SERIAL_CONSOLE_MODULE)
}
# endif
#endif
#ifdef CONFIG_SERIAL_BFIN_CTSRTS
if (uart->cts_pin >= 0) {
if (request_irq(gpio_to_irq(uart->cts_pin),
bfin_serial_mctrl_cts_int,
IRQF_TRIGGER_RISING | IRQF_TRIGGER_FALLING |
IRQF_DISABLED, "BFIN_UART_CTS", uart)) {
uart->cts_pin = -1;
pr_info("Unable to attach BlackFin UART CTS interrupt. So, disable it.\n");
}
}
if (uart->rts_pin >= 0) {
gpio_direction_output(uart->rts_pin, 0);
}
#endif
#ifdef CONFIG_SERIAL_BFIN_HARD_CTSRTS
if (uart->cts_pin >= 0 && request_irq(uart->status_irq,
bfin_serial_mctrl_cts_int,
IRQF_DISABLED, "BFIN_UART_MODEM_STATUS", uart)) {
uart->cts_pin = -1;
pr_info("Unable to attach BlackFin UART Modem Status interrupt.\n");
}
UART_PUT_MCR(uart, ACTS);
UART_SET_IER(uart, EDSSI);
#endif
UART_SET_IER(uart, ERBFI);
return 0;
}
static void bfin_serial_shutdown(struct uart_port *port)
{
struct bfin_serial_port *uart = (struct bfin_serial_port *)port;
#ifdef CONFIG_SERIAL_BFIN_DMA
disable_dma(uart->tx_dma_channel);
free_dma(uart->tx_dma_channel);
disable_dma(uart->rx_dma_channel);
free_dma(uart->rx_dma_channel);
del_timer(&(uart->rx_dma_timer));
dma_free_coherent(NULL, PAGE_SIZE, uart->rx_dma_buf.buf, 0);
#else
#ifdef CONFIG_BF54x
switch (uart->port.irq) {
case IRQ_UART3_RX:
free_dma(CH_UART3_RX);
free_dma(CH_UART3_TX);
break;
case IRQ_UART2_RX:
free_dma(CH_UART2_RX);
free_dma(CH_UART2_TX);
break;
default:
break;
};
#endif
free_irq(uart->port.irq, uart);
free_irq(uart->port.irq+1, uart);
#endif
#ifdef CONFIG_SERIAL_BFIN_CTSRTS
if (uart->cts_pin >= 0)
free_irq(gpio_to_irq(uart->cts_pin), uart);
#endif
#ifdef CONFIG_SERIAL_BFIN_HARD_CTSRTS
if (uart->cts_pin >= 0)
free_irq(uart->status_irq, uart);
#endif
}
static void
bfin_serial_set_termios(struct uart_port *port, struct ktermios *termios,
struct ktermios *old)
{
struct bfin_serial_port *uart = (struct bfin_serial_port *)port;
unsigned long flags;
unsigned int baud, quot;
unsigned short val, ier, lcr = 0;
switch (termios->c_cflag & CSIZE) {
case CS8:
lcr = WLS(8);
break;
case CS7:
lcr = WLS(7);
break;
case CS6:
lcr = WLS(6);
break;
case CS5:
lcr = WLS(5);
break;
default:
printk(KERN_ERR "%s: word lengh not supported\n",
__func__);
}
if (termios->c_cflag & CSTOPB) {
if (ANOMALY_05000231)
printk(KERN_WARNING "STOP bits other than 1 is not "
"supported in case of anomaly 05000231.\n");
else
lcr |= STB;
}
if (termios->c_cflag & PARENB)
lcr |= PEN;
if (!(termios->c_cflag & PARODD))
lcr |= EPS;
if (termios->c_cflag & CMSPAR)
lcr |= STP;
spin_lock_irqsave(&uart->port.lock, flags);
port->read_status_mask = OE;
if (termios->c_iflag & INPCK)
port->read_status_mask |= (FE | PE);
if (termios->c_iflag & (BRKINT | PARMRK))
port->read_status_mask |= BI;
port->ignore_status_mask = 0;
if (termios->c_iflag & IGNPAR)
port->ignore_status_mask |= FE | PE;
if (termios->c_iflag & IGNBRK) {
port->ignore_status_mask |= BI;
if (termios->c_iflag & IGNPAR)
port->ignore_status_mask |= OE;
}
baud = uart_get_baud_rate(port, termios, old, 0, port->uartclk/16);
quot = uart_get_divisor(port, baud);
if (termios->c_line != N_IRDA)
quot -= ANOMALY_05000230;
UART_SET_ANOMALY_THRESHOLD(uart, USEC_PER_SEC / baud * 15);
ier = UART_GET_IER(uart);
UART_DISABLE_INTS(uart);
UART_SET_DLAB(uart);
UART_PUT_DLL(uart, quot & 0xFF);
UART_PUT_DLH(uart, (quot >> 8) & 0xFF);
SSYNC();
UART_CLEAR_DLAB(uart);
UART_PUT_LCR(uart, lcr);
UART_ENABLE_INTS(uart, ier);
val = UART_GET_GCTL(uart);
val |= UCEN;
UART_PUT_GCTL(uart, val);
uart_update_timeout(port, termios->c_cflag, baud);
spin_unlock_irqrestore(&uart->port.lock, flags);
}
static const char *bfin_serial_type(struct uart_port *port)
{
struct bfin_serial_port *uart = (struct bfin_serial_port *)port;
return uart->port.type == PORT_BFIN ? "BFIN-UART" : NULL;
}
static void bfin_serial_release_port(struct uart_port *port)
{
}
static int bfin_serial_request_port(struct uart_port *port)
{
return 0;
}
static void bfin_serial_config_port(struct uart_port *port, int flags)
{
struct bfin_serial_port *uart = (struct bfin_serial_port *)port;
if (flags & UART_CONFIG_TYPE &&
bfin_serial_request_port(&uart->port) == 0)
uart->port.type = PORT_BFIN;
}
static int
bfin_serial_verify_port(struct uart_port *port, struct serial_struct *ser)
{
return 0;
}
static void bfin_serial_set_ldisc(struct uart_port *port, int ld)
{
struct bfin_serial_port *uart = (struct bfin_serial_port *)port;
unsigned short val;
switch (ld) {
case N_IRDA:
val = UART_GET_GCTL(uart);
val |= (IREN | RPOLC);
UART_PUT_GCTL(uart, val);
break;
default:
val = UART_GET_GCTL(uart);
val &= ~(IREN | RPOLC);
UART_PUT_GCTL(uart, val);
}
}
static void bfin_serial_reset_irda(struct uart_port *port)
{
struct bfin_serial_port *uart = (struct bfin_serial_port *)port;
unsigned short val;
val = UART_GET_GCTL(uart);
val &= ~(IREN | RPOLC);
UART_PUT_GCTL(uart, val);
SSYNC();
val |= (IREN | RPOLC);
UART_PUT_GCTL(uart, val);
SSYNC();
}
static void bfin_serial_poll_put_char(struct uart_port *port, unsigned char chr)
{
struct bfin_serial_port *uart = (struct bfin_serial_port *)port;
while (!(UART_GET_LSR(uart) & THRE))
cpu_relax();
UART_CLEAR_DLAB(uart);
UART_PUT_CHAR(uart, (unsigned char)chr);
}
static int bfin_serial_poll_get_char(struct uart_port *port)
{
struct bfin_serial_port *uart = (struct bfin_serial_port *)port;
unsigned char chr;
while (!(UART_GET_LSR(uart) & DR))
cpu_relax();
UART_CLEAR_DLAB(uart);
chr = UART_GET_CHAR(uart);
return chr;
}
static void bfin_kgdboc_port_shutdown(struct uart_port *port)
{
if (kgdboc_break_enabled) {
kgdboc_break_enabled = 0;
bfin_serial_shutdown(port);
}
}
static int bfin_kgdboc_port_startup(struct uart_port *port)
{
kgdboc_port_line = port->line;
kgdboc_break_enabled = !bfin_serial_startup(port);
return 0;
}
static void __init
bfin_serial_console_get_options(struct bfin_serial_port *uart, int *baud,
int *parity, int *bits)
{
unsigned short status;
status = UART_GET_IER(uart) & (ERBFI | ETBEI);
if (status == (ERBFI | ETBEI)) {
u16 lcr, dlh, dll;
lcr = UART_GET_LCR(uart);
*parity = 'n';
if (lcr & PEN) {
if (lcr & EPS)
*parity = 'e';
else
*parity = 'o';
}
switch (lcr & 0x03) {
case 0: *bits = 5; break;
case 1: *bits = 6; break;
case 2: *bits = 7; break;
case 3: *bits = 8; break;
}
UART_SET_DLAB(uart);
dll = UART_GET_DLL(uart);
dlh = UART_GET_DLH(uart);
UART_CLEAR_DLAB(uart);
*baud = get_sclk() / (16*(dll | dlh << 8));
}
pr_debug("%s:baud = %d, parity = %c, bits= %d\n", __func__, *baud, *parity, *bits);
}
static void bfin_serial_console_putchar(struct uart_port *port, int ch)
{
struct bfin_serial_port *uart = (struct bfin_serial_port *)port;
while (!(UART_GET_LSR(uart) & THRE))
barrier();
UART_PUT_CHAR(uart, ch);
}
static void
bfin_serial_console_write(struct console *co, const char *s, unsigned int count)
{
struct bfin_serial_port *uart = bfin_serial_ports[co->index];
unsigned long flags;
spin_lock_irqsave(&uart->port.lock, flags);
uart_console_write(&uart->port, s, count, bfin_serial_console_putchar);
spin_unlock_irqrestore(&uart->port.lock, flags);
}
static int __init
bfin_serial_console_setup(struct console *co, char *options)
{
struct bfin_serial_port *uart;
int baud = 57600;
int bits = 8;
int parity = 'n';
# if defined(CONFIG_SERIAL_BFIN_CTSRTS) || \
defined(CONFIG_SERIAL_BFIN_HARD_CTSRTS)
int flow = 'r';
# else
int flow = 'n';
# endif
if (co->index < 0 || co->index >= BFIN_UART_NR_PORTS)
return -ENODEV;
uart = bfin_serial_ports[co->index];
if (!uart)
return -ENODEV;
if (options)
uart_parse_options(options, &baud, &parity, &bits, &flow);
else
bfin_serial_console_get_options(uart, &baud, &parity, &bits);
return uart_set_options(&uart->port, co, baud, parity, bits, flow);
}
static void
bfin_earlyprintk_console_write(struct console *co, const char *s, unsigned int count)
{
unsigned long flags;
if (bfin_earlyprintk_port.port.line != co->index)
return;
spin_lock_irqsave(&bfin_earlyprintk_port.port.lock, flags);
uart_console_write(&bfin_earlyprintk_port.port, s, count,
bfin_serial_console_putchar);
spin_unlock_irqrestore(&bfin_earlyprintk_port.port.lock, flags);
}
static int bfin_serial_suspend(struct platform_device *pdev, pm_message_t state)
{
struct bfin_serial_port *uart = platform_get_drvdata(pdev);
return uart_suspend_port(&bfin_serial_reg, &uart->port);
}
static int bfin_serial_resume(struct platform_device *pdev)
{
struct bfin_serial_port *uart = platform_get_drvdata(pdev);
return uart_resume_port(&bfin_serial_reg, &uart->port);
}
static int bfin_serial_probe(struct platform_device *pdev)
{
struct resource *res;
struct bfin_serial_port *uart = NULL;
int ret = 0;
if (pdev->id < 0 || pdev->id >= BFIN_UART_NR_PORTS) {
dev_err(&pdev->dev, "Wrong bfin uart platform device id.\n");
return -ENOENT;
}
if (bfin_serial_ports[pdev->id] == NULL) {
uart = kzalloc(sizeof(*uart), GFP_KERNEL);
if (!uart) {
dev_err(&pdev->dev,
"fail to malloc bfin_serial_port\n");
return -ENOMEM;
}
bfin_serial_ports[pdev->id] = uart;
#ifdef CONFIG_EARLY_PRINTK
if (!(bfin_earlyprintk_port.port.membase
&& bfin_earlyprintk_port.port.line == pdev->id)) {
#endif
ret = peripheral_request_list(
(unsigned short *)pdev->dev.platform_data, DRIVER_NAME);
if (ret) {
dev_err(&pdev->dev,
"fail to request bfin serial peripherals\n");
goto out_error_free_mem;
}
#ifdef CONFIG_EARLY_PRINTK
}
#endif
spin_lock_init(&uart->port.lock);
uart->port.uartclk = get_sclk();
uart->port.fifosize = BFIN_UART_TX_FIFO_SIZE;
uart->port.ops = &bfin_serial_pops;
uart->port.line = pdev->id;
uart->port.iotype = UPIO_MEM;
uart->port.flags = UPF_BOOT_AUTOCONF;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (res == NULL) {
dev_err(&pdev->dev, "Cannot get IORESOURCE_MEM\n");
ret = -ENOENT;
goto out_error_free_peripherals;
}
uart->port.membase = ioremap(res->start,
res->end - res->start);
if (!uart->port.membase) {
dev_err(&pdev->dev, "Cannot map uart IO\n");
ret = -ENXIO;
goto out_error_free_peripherals;
}
uart->port.mapbase = res->start;
uart->port.irq = platform_get_irq(pdev, 0);
if (uart->port.irq < 0) {
dev_err(&pdev->dev, "No uart RX/TX IRQ specified\n");
ret = -ENOENT;
goto out_error_unmap;
}
uart->status_irq = platform_get_irq(pdev, 1);
if (uart->status_irq < 0) {
dev_err(&pdev->dev, "No uart status IRQ specified\n");
ret = -ENOENT;
goto out_error_unmap;
}
#ifdef CONFIG_SERIAL_BFIN_DMA
spin_lock_init(&uart->rx_lock);
uart->tx_done = 1;
uart->tx_count = 0;
res = platform_get_resource(pdev, IORESOURCE_DMA, 0);
if (res == NULL) {
dev_err(&pdev->dev, "No uart TX DMA channel specified\n");
ret = -ENOENT;
goto out_error_unmap;
}
uart->tx_dma_channel = res->start;
res = platform_get_resource(pdev, IORESOURCE_DMA, 1);
if (res == NULL) {
dev_err(&pdev->dev, "No uart RX DMA channel specified\n");
ret = -ENOENT;
goto out_error_unmap;
}
uart->rx_dma_channel = res->start;
init_timer(&(uart->rx_dma_timer));
#endif
#if defined(CONFIG_SERIAL_BFIN_CTSRTS) || \
defined(CONFIG_SERIAL_BFIN_HARD_CTSRTS)
res = platform_get_resource(pdev, IORESOURCE_IO, 0);
if (res == NULL)
uart->cts_pin = -1;
else
uart->cts_pin = res->start;
res = platform_get_resource(pdev, IORESOURCE_IO, 1);
if (res == NULL)
uart->rts_pin = -1;
else
uart->rts_pin = res->start;
# if defined(CONFIG_SERIAL_BFIN_CTSRTS)
if (uart->rts_pin >= 0)
gpio_request(uart->rts_pin, DRIVER_NAME);
# endif
#endif
}
#ifdef CONFIG_SERIAL_BFIN_CONSOLE
if (!is_early_platform_device(pdev)) {
#endif
uart = bfin_serial_ports[pdev->id];
uart->port.dev = &pdev->dev;
dev_set_drvdata(&pdev->dev, uart);
ret = uart_add_one_port(&bfin_serial_reg, &uart->port);
#ifdef CONFIG_SERIAL_BFIN_CONSOLE
}
#endif
if (!ret)
return 0;
if (uart) {
out_error_unmap:
iounmap(uart->port.membase);
out_error_free_peripherals:
peripheral_free_list(
(unsigned short *)pdev->dev.platform_data);
out_error_free_mem:
kfree(uart);
bfin_serial_ports[pdev->id] = NULL;
}
return ret;
}
static int __devexit bfin_serial_remove(struct platform_device *pdev)
{
struct bfin_serial_port *uart = platform_get_drvdata(pdev);
dev_set_drvdata(&pdev->dev, NULL);
if (uart) {
uart_remove_one_port(&bfin_serial_reg, &uart->port);
#ifdef CONFIG_SERIAL_BFIN_CTSRTS
if (uart->rts_pin >= 0)
gpio_free(uart->rts_pin);
#endif
iounmap(uart->port.membase);
peripheral_free_list(
(unsigned short *)pdev->dev.platform_data);
kfree(uart);
bfin_serial_ports[pdev->id] = NULL;
}
return 0;
}
static int __init bfin_serial_rs_console_init(void)
{
early_platform_driver_register(&early_bfin_serial_driver, DRIVER_NAME);
early_platform_driver_probe(CLASS_BFIN_CONSOLE, BFIN_UART_NR_PORTS, 0);
register_console(&bfin_serial_console);
return 0;
}
static int bfin_earlyprintk_probe(struct platform_device *pdev)
{
struct resource *res;
int ret;
if (pdev->id < 0 || pdev->id >= BFIN_UART_NR_PORTS) {
dev_err(&pdev->dev, "Wrong earlyprintk platform device id.\n");
return -ENOENT;
}
ret = peripheral_request_list(
(unsigned short *)pdev->dev.platform_data, DRIVER_NAME);
if (ret) {
dev_err(&pdev->dev,
"fail to request bfin serial peripherals\n");
return ret;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (res == NULL) {
dev_err(&pdev->dev, "Cannot get IORESOURCE_MEM\n");
ret = -ENOENT;
goto out_error_free_peripherals;
}
bfin_earlyprintk_port.port.membase = ioremap(res->start,
res->end - res->start);
if (!bfin_earlyprintk_port.port.membase) {
dev_err(&pdev->dev, "Cannot map uart IO\n");
ret = -ENXIO;
goto out_error_free_peripherals;
}
bfin_earlyprintk_port.port.mapbase = res->start;
bfin_earlyprintk_port.port.line = pdev->id;
bfin_earlyprintk_port.port.uartclk = get_sclk();
bfin_earlyprintk_port.port.fifosize = BFIN_UART_TX_FIFO_SIZE;
spin_lock_init(&bfin_earlyprintk_port.port.lock);
return 0;
out_error_free_peripherals:
peripheral_free_list(
(unsigned short *)pdev->dev.platform_data);
return ret;
}
struct console __init *bfin_earlyserial_init(unsigned int port,
unsigned int cflag)
{
struct ktermios t;
char port_name[20];
if (port < 0 || port >= BFIN_UART_NR_PORTS)
return NULL;
snprintf(port_name, 20, DRIVER_NAME ".%d", port);
early_platform_driver_register(&early_bfin_earlyprintk_driver,
port_name);
early_platform_driver_probe(CLASS_BFIN_EARLYPRINTK, 1, 0);
if (!bfin_earlyprintk_port.port.membase)
return NULL;
#ifdef CONFIG_SERIAL_BFIN_CONSOLE
bfin_serial_console.flags &= ~CON_PRINTBUFFER;
#endif
bfin_early_serial_console.index = port;
t.c_cflag = cflag;
t.c_iflag = 0;
t.c_oflag = 0;
t.c_lflag = ICANON;
t.c_line = port;
bfin_serial_set_termios(&bfin_earlyprintk_port.port, &t, &t);
return &bfin_early_serial_console;
}
static int __init bfin_serial_init(void)
{
int ret;
pr_info("Blackfin serial driver\n");
ret = uart_register_driver(&bfin_serial_reg);
if (ret) {
pr_err("failed to register %s:%d\n",
bfin_serial_reg.driver_name, ret);
}
ret = platform_driver_register(&bfin_serial_driver);
if (ret) {
pr_err("fail to register bfin uart\n");
uart_unregister_driver(&bfin_serial_reg);
}
return ret;
}
static void __exit bfin_serial_exit(void)
{
platform_driver_unregister(&bfin_serial_driver);
uart_unregister_driver(&bfin_serial_reg);
}
