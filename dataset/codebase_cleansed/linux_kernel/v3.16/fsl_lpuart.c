static void lpuart_stop_tx(struct uart_port *port)
{
unsigned char temp;
temp = readb(port->membase + UARTCR2);
temp &= ~(UARTCR2_TIE | UARTCR2_TCIE);
writeb(temp, port->membase + UARTCR2);
}
static void lpuart_stop_rx(struct uart_port *port)
{
unsigned char temp;
temp = readb(port->membase + UARTCR2);
writeb(temp & ~UARTCR2_RE, port->membase + UARTCR2);
}
static void lpuart_enable_ms(struct uart_port *port)
{
}
static void lpuart_copy_rx_to_tty(struct lpuart_port *sport,
struct tty_port *tty, int count)
{
int copied;
sport->port.icount.rx += count;
if (!tty) {
dev_err(sport->port.dev, "No tty port\n");
return;
}
dma_sync_single_for_cpu(sport->port.dev, sport->dma_rx_buf_bus,
FSL_UART_RX_DMA_BUFFER_SIZE, DMA_FROM_DEVICE);
copied = tty_insert_flip_string(tty,
((unsigned char *)(sport->dma_rx_buf_virt)), count);
if (copied != count) {
WARN_ON(1);
dev_err(sport->port.dev, "RxData copy to tty layer failed\n");
}
dma_sync_single_for_device(sport->port.dev, sport->dma_rx_buf_bus,
FSL_UART_RX_DMA_BUFFER_SIZE, DMA_TO_DEVICE);
}
static void lpuart_pio_tx(struct lpuart_port *sport)
{
struct circ_buf *xmit = &sport->port.state->xmit;
unsigned long flags;
spin_lock_irqsave(&sport->port.lock, flags);
while (!uart_circ_empty(xmit) &&
readb(sport->port.membase + UARTTCFIFO) < sport->txfifo_size) {
writeb(xmit->buf[xmit->tail], sport->port.membase + UARTDR);
xmit->tail = (xmit->tail + 1) & (UART_XMIT_SIZE - 1);
sport->port.icount.tx++;
}
if (uart_circ_chars_pending(xmit) < WAKEUP_CHARS)
uart_write_wakeup(&sport->port);
if (uart_circ_empty(xmit))
writeb(readb(sport->port.membase + UARTCR5) | UARTCR5_TDMAS,
sport->port.membase + UARTCR5);
spin_unlock_irqrestore(&sport->port.lock, flags);
}
static int lpuart_dma_tx(struct lpuart_port *sport, unsigned long count)
{
struct circ_buf *xmit = &sport->port.state->xmit;
dma_addr_t tx_bus_addr;
dma_sync_single_for_device(sport->port.dev, sport->dma_tx_buf_bus,
UART_XMIT_SIZE, DMA_TO_DEVICE);
sport->dma_tx_bytes = count & ~(DMA_MAXBURST_MASK);
tx_bus_addr = sport->dma_tx_buf_bus + xmit->tail;
sport->dma_tx_desc = dmaengine_prep_slave_single(sport->dma_tx_chan,
tx_bus_addr, sport->dma_tx_bytes,
DMA_MEM_TO_DEV, DMA_PREP_INTERRUPT);
if (!sport->dma_tx_desc) {
dev_err(sport->port.dev, "Not able to get desc for tx\n");
return -EIO;
}
sport->dma_tx_desc->callback = lpuart_dma_tx_complete;
sport->dma_tx_desc->callback_param = sport;
sport->dma_tx_in_progress = 1;
sport->dma_tx_cookie = dmaengine_submit(sport->dma_tx_desc);
dma_async_issue_pending(sport->dma_tx_chan);
return 0;
}
static void lpuart_prepare_tx(struct lpuart_port *sport)
{
struct circ_buf *xmit = &sport->port.state->xmit;
unsigned long count = CIRC_CNT_TO_END(xmit->head,
xmit->tail, UART_XMIT_SIZE);
if (!count)
return;
if (count < DMA_MAXBURST)
writeb(readb(sport->port.membase + UARTCR5) & ~UARTCR5_TDMAS,
sport->port.membase + UARTCR5);
else {
writeb(readb(sport->port.membase + UARTCR5) | UARTCR5_TDMAS,
sport->port.membase + UARTCR5);
lpuart_dma_tx(sport, count);
}
}
static void lpuart_dma_tx_complete(void *arg)
{
struct lpuart_port *sport = arg;
struct circ_buf *xmit = &sport->port.state->xmit;
unsigned long flags;
async_tx_ack(sport->dma_tx_desc);
spin_lock_irqsave(&sport->port.lock, flags);
xmit->tail = (xmit->tail + sport->dma_tx_bytes) & (UART_XMIT_SIZE - 1);
sport->dma_tx_in_progress = 0;
if (uart_circ_chars_pending(xmit) < WAKEUP_CHARS)
uart_write_wakeup(&sport->port);
lpuart_prepare_tx(sport);
spin_unlock_irqrestore(&sport->port.lock, flags);
}
static int lpuart_dma_rx(struct lpuart_port *sport)
{
dma_sync_single_for_device(sport->port.dev, sport->dma_rx_buf_bus,
FSL_UART_RX_DMA_BUFFER_SIZE, DMA_TO_DEVICE);
sport->dma_rx_desc = dmaengine_prep_slave_single(sport->dma_rx_chan,
sport->dma_rx_buf_bus, FSL_UART_RX_DMA_BUFFER_SIZE,
DMA_DEV_TO_MEM, DMA_PREP_INTERRUPT);
if (!sport->dma_rx_desc) {
dev_err(sport->port.dev, "Not able to get desc for rx\n");
return -EIO;
}
sport->dma_rx_desc->callback = lpuart_dma_rx_complete;
sport->dma_rx_desc->callback_param = sport;
sport->dma_rx_in_progress = 1;
sport->dma_rx_cookie = dmaengine_submit(sport->dma_rx_desc);
dma_async_issue_pending(sport->dma_rx_chan);
return 0;
}
static void lpuart_dma_rx_complete(void *arg)
{
struct lpuart_port *sport = arg;
struct tty_port *port = &sport->port.state->port;
unsigned long flags;
async_tx_ack(sport->dma_rx_desc);
spin_lock_irqsave(&sport->port.lock, flags);
sport->dma_rx_in_progress = 0;
lpuart_copy_rx_to_tty(sport, port, FSL_UART_RX_DMA_BUFFER_SIZE);
tty_flip_buffer_push(port);
lpuart_dma_rx(sport);
spin_unlock_irqrestore(&sport->port.lock, flags);
}
static void lpuart_timer_func(unsigned long data)
{
struct lpuart_port *sport = (struct lpuart_port *)data;
struct tty_port *port = &sport->port.state->port;
struct dma_tx_state state;
unsigned long flags;
unsigned char temp;
int count;
del_timer(&sport->lpuart_timer);
dmaengine_pause(sport->dma_rx_chan);
dmaengine_tx_status(sport->dma_rx_chan, sport->dma_rx_cookie, &state);
dmaengine_terminate_all(sport->dma_rx_chan);
count = FSL_UART_RX_DMA_BUFFER_SIZE - state.residue;
async_tx_ack(sport->dma_rx_desc);
spin_lock_irqsave(&sport->port.lock, flags);
sport->dma_rx_in_progress = 0;
lpuart_copy_rx_to_tty(sport, port, count);
tty_flip_buffer_push(port);
temp = readb(sport->port.membase + UARTCR5);
writeb(temp & ~UARTCR5_RDMAS, sport->port.membase + UARTCR5);
spin_unlock_irqrestore(&sport->port.lock, flags);
}
static inline void lpuart_prepare_rx(struct lpuart_port *sport)
{
unsigned long flags;
unsigned char temp;
spin_lock_irqsave(&sport->port.lock, flags);
init_timer(&sport->lpuart_timer);
sport->lpuart_timer.function = lpuart_timer_func;
sport->lpuart_timer.data = (unsigned long)sport;
sport->lpuart_timer.expires = jiffies + sport->dma_rx_timeout;
add_timer(&sport->lpuart_timer);
lpuart_dma_rx(sport);
temp = readb(sport->port.membase + UARTCR5);
writeb(temp | UARTCR5_RDMAS, sport->port.membase + UARTCR5);
spin_unlock_irqrestore(&sport->port.lock, flags);
}
static inline void lpuart_transmit_buffer(struct lpuart_port *sport)
{
struct circ_buf *xmit = &sport->port.state->xmit;
while (!uart_circ_empty(xmit) &&
(readb(sport->port.membase + UARTTCFIFO) < sport->txfifo_size)) {
writeb(xmit->buf[xmit->tail], sport->port.membase + UARTDR);
xmit->tail = (xmit->tail + 1) & (UART_XMIT_SIZE - 1);
sport->port.icount.tx++;
}
if (uart_circ_chars_pending(xmit) < WAKEUP_CHARS)
uart_write_wakeup(&sport->port);
if (uart_circ_empty(xmit))
lpuart_stop_tx(&sport->port);
}
static void lpuart_start_tx(struct uart_port *port)
{
struct lpuart_port *sport = container_of(port,
struct lpuart_port, port);
struct circ_buf *xmit = &sport->port.state->xmit;
unsigned char temp;
temp = readb(port->membase + UARTCR2);
writeb(temp | UARTCR2_TIE, port->membase + UARTCR2);
if (sport->lpuart_dma_use) {
if (!uart_circ_empty(xmit) && !sport->dma_tx_in_progress)
lpuart_prepare_tx(sport);
} else {
if (readb(port->membase + UARTSR1) & UARTSR1_TDRE)
lpuart_transmit_buffer(sport);
}
}
static irqreturn_t lpuart_txint(int irq, void *dev_id)
{
struct lpuart_port *sport = dev_id;
struct circ_buf *xmit = &sport->port.state->xmit;
unsigned long flags;
spin_lock_irqsave(&sport->port.lock, flags);
if (sport->port.x_char) {
writeb(sport->port.x_char, sport->port.membase + UARTDR);
goto out;
}
if (uart_circ_empty(xmit) || uart_tx_stopped(&sport->port)) {
lpuart_stop_tx(&sport->port);
goto out;
}
lpuart_transmit_buffer(sport);
if (uart_circ_chars_pending(xmit) < WAKEUP_CHARS)
uart_write_wakeup(&sport->port);
out:
spin_unlock_irqrestore(&sport->port.lock, flags);
return IRQ_HANDLED;
}
static irqreturn_t lpuart_rxint(int irq, void *dev_id)
{
struct lpuart_port *sport = dev_id;
unsigned int flg, ignored = 0;
struct tty_port *port = &sport->port.state->port;
unsigned long flags;
unsigned char rx, sr;
spin_lock_irqsave(&sport->port.lock, flags);
while (!(readb(sport->port.membase + UARTSFIFO) & UARTSFIFO_RXEMPT)) {
flg = TTY_NORMAL;
sport->port.icount.rx++;
sr = readb(sport->port.membase + UARTSR1);
rx = readb(sport->port.membase + UARTDR);
if (uart_handle_sysrq_char(&sport->port, (unsigned char)rx))
continue;
if (sr & (UARTSR1_PE | UARTSR1_OR | UARTSR1_FE)) {
if (sr & UARTSR1_PE)
sport->port.icount.parity++;
else if (sr & UARTSR1_FE)
sport->port.icount.frame++;
if (sr & UARTSR1_OR)
sport->port.icount.overrun++;
if (sr & sport->port.ignore_status_mask) {
if (++ignored > 100)
goto out;
continue;
}
sr &= sport->port.read_status_mask;
if (sr & UARTSR1_PE)
flg = TTY_PARITY;
else if (sr & UARTSR1_FE)
flg = TTY_FRAME;
if (sr & UARTSR1_OR)
flg = TTY_OVERRUN;
#ifdef SUPPORT_SYSRQ
sport->port.sysrq = 0;
#endif
}
tty_insert_flip_char(port, rx, flg);
}
out:
spin_unlock_irqrestore(&sport->port.lock, flags);
tty_flip_buffer_push(port);
return IRQ_HANDLED;
}
static irqreturn_t lpuart_int(int irq, void *dev_id)
{
struct lpuart_port *sport = dev_id;
unsigned char sts;
sts = readb(sport->port.membase + UARTSR1);
if (sts & UARTSR1_RDRF) {
if (sport->lpuart_dma_use)
lpuart_prepare_rx(sport);
else
lpuart_rxint(irq, dev_id);
}
if (sts & UARTSR1_TDRE &&
!(readb(sport->port.membase + UARTCR5) & UARTCR5_TDMAS)) {
if (sport->lpuart_dma_use)
lpuart_pio_tx(sport);
else
lpuart_txint(irq, dev_id);
}
return IRQ_HANDLED;
}
static unsigned int lpuart_tx_empty(struct uart_port *port)
{
return (readb(port->membase + UARTSR1) & UARTSR1_TC) ?
TIOCSER_TEMT : 0;
}
static unsigned int lpuart_get_mctrl(struct uart_port *port)
{
unsigned int temp = 0;
unsigned char reg;
reg = readb(port->membase + UARTMODEM);
if (reg & UARTMODEM_TXCTSE)
temp |= TIOCM_CTS;
if (reg & UARTMODEM_RXRTSE)
temp |= TIOCM_RTS;
return temp;
}
static void lpuart_set_mctrl(struct uart_port *port, unsigned int mctrl)
{
unsigned char temp;
temp = readb(port->membase + UARTMODEM) &
~(UARTMODEM_RXRTSE | UARTMODEM_TXCTSE);
if (mctrl & TIOCM_RTS)
temp |= UARTMODEM_RXRTSE;
if (mctrl & TIOCM_CTS)
temp |= UARTMODEM_TXCTSE;
writeb(temp, port->membase + UARTMODEM);
}
static void lpuart_break_ctl(struct uart_port *port, int break_state)
{
unsigned char temp;
temp = readb(port->membase + UARTCR2) & ~UARTCR2_SBK;
if (break_state != 0)
temp |= UARTCR2_SBK;
writeb(temp, port->membase + UARTCR2);
}
static void lpuart_setup_watermark(struct lpuart_port *sport)
{
unsigned char val, cr2;
unsigned char cr2_saved;
cr2 = readb(sport->port.membase + UARTCR2);
cr2_saved = cr2;
cr2 &= ~(UARTCR2_TIE | UARTCR2_TCIE | UARTCR2_TE |
UARTCR2_RIE | UARTCR2_RE);
writeb(cr2, sport->port.membase + UARTCR2);
val = readb(sport->port.membase + UARTPFIFO);
sport->txfifo_size = 0x1 << (((val >> UARTPFIFO_TXSIZE_OFF) &
UARTPFIFO_FIFOSIZE_MASK) + 1);
sport->rxfifo_size = 0x1 << (((val >> UARTPFIFO_RXSIZE_OFF) &
UARTPFIFO_FIFOSIZE_MASK) + 1);
writeb(val | UARTPFIFO_TXFE | UARTPFIFO_RXFE,
sport->port.membase + UARTPFIFO);
writeb(UARTCFIFO_TXFLUSH | UARTCFIFO_RXFLUSH,
sport->port.membase + UARTCFIFO);
writeb(0, sport->port.membase + UARTTWFIFO);
writeb(1, sport->port.membase + UARTRWFIFO);
writeb(cr2_saved, sport->port.membase + UARTCR2);
}
static int lpuart_dma_tx_request(struct uart_port *port)
{
struct lpuart_port *sport = container_of(port,
struct lpuart_port, port);
struct dma_chan *tx_chan;
struct dma_slave_config dma_tx_sconfig;
dma_addr_t dma_bus;
unsigned char *dma_buf;
int ret;
tx_chan = dma_request_slave_channel(sport->port.dev, "tx");
if (!tx_chan) {
dev_err(sport->port.dev, "Dma tx channel request failed!\n");
return -ENODEV;
}
dma_bus = dma_map_single(tx_chan->device->dev,
sport->port.state->xmit.buf,
UART_XMIT_SIZE, DMA_TO_DEVICE);
if (dma_mapping_error(tx_chan->device->dev, dma_bus)) {
dev_err(sport->port.dev, "dma_map_single tx failed\n");
dma_release_channel(tx_chan);
return -ENOMEM;
}
dma_buf = sport->port.state->xmit.buf;
dma_tx_sconfig.dst_addr = sport->port.mapbase + UARTDR;
dma_tx_sconfig.dst_addr_width = DMA_SLAVE_BUSWIDTH_1_BYTE;
dma_tx_sconfig.dst_maxburst = DMA_MAXBURST;
dma_tx_sconfig.direction = DMA_MEM_TO_DEV;
ret = dmaengine_slave_config(tx_chan, &dma_tx_sconfig);
if (ret < 0) {
dev_err(sport->port.dev,
"Dma slave config failed, err = %d\n", ret);
dma_release_channel(tx_chan);
return ret;
}
sport->dma_tx_chan = tx_chan;
sport->dma_tx_buf_virt = dma_buf;
sport->dma_tx_buf_bus = dma_bus;
sport->dma_tx_in_progress = 0;
return 0;
}
static int lpuart_dma_rx_request(struct uart_port *port)
{
struct lpuart_port *sport = container_of(port,
struct lpuart_port, port);
struct dma_chan *rx_chan;
struct dma_slave_config dma_rx_sconfig;
dma_addr_t dma_bus;
unsigned char *dma_buf;
int ret;
rx_chan = dma_request_slave_channel(sport->port.dev, "rx");
if (!rx_chan) {
dev_err(sport->port.dev, "Dma rx channel request failed!\n");
return -ENODEV;
}
dma_buf = devm_kzalloc(sport->port.dev,
FSL_UART_RX_DMA_BUFFER_SIZE, GFP_KERNEL);
if (!dma_buf) {
dev_err(sport->port.dev, "Dma rx alloc failed\n");
dma_release_channel(rx_chan);
return -ENOMEM;
}
dma_bus = dma_map_single(rx_chan->device->dev, dma_buf,
FSL_UART_RX_DMA_BUFFER_SIZE, DMA_FROM_DEVICE);
if (dma_mapping_error(rx_chan->device->dev, dma_bus)) {
dev_err(sport->port.dev, "dma_map_single rx failed\n");
dma_release_channel(rx_chan);
return -ENOMEM;
}
dma_rx_sconfig.src_addr = sport->port.mapbase + UARTDR;
dma_rx_sconfig.src_addr_width = DMA_SLAVE_BUSWIDTH_1_BYTE;
dma_rx_sconfig.src_maxburst = 1;
dma_rx_sconfig.direction = DMA_DEV_TO_MEM;
ret = dmaengine_slave_config(rx_chan, &dma_rx_sconfig);
if (ret < 0) {
dev_err(sport->port.dev,
"Dma slave config failed, err = %d\n", ret);
dma_release_channel(rx_chan);
return ret;
}
sport->dma_rx_chan = rx_chan;
sport->dma_rx_buf_virt = dma_buf;
sport->dma_rx_buf_bus = dma_bus;
sport->dma_rx_in_progress = 0;
sport->dma_rx_timeout = (sport->port.timeout - HZ / 50) *
FSL_UART_RX_DMA_BUFFER_SIZE * 3 /
sport->rxfifo_size / 2;
if (sport->dma_rx_timeout < msecs_to_jiffies(20))
sport->dma_rx_timeout = msecs_to_jiffies(20);
return 0;
}
static void lpuart_dma_tx_free(struct uart_port *port)
{
struct lpuart_port *sport = container_of(port,
struct lpuart_port, port);
struct dma_chan *dma_chan;
dma_unmap_single(sport->port.dev, sport->dma_tx_buf_bus,
UART_XMIT_SIZE, DMA_TO_DEVICE);
dma_chan = sport->dma_tx_chan;
sport->dma_tx_chan = NULL;
sport->dma_tx_buf_bus = 0;
sport->dma_tx_buf_virt = NULL;
dma_release_channel(dma_chan);
}
static void lpuart_dma_rx_free(struct uart_port *port)
{
struct lpuart_port *sport = container_of(port,
struct lpuart_port, port);
struct dma_chan *dma_chan;
dma_unmap_single(sport->port.dev, sport->dma_rx_buf_bus,
FSL_UART_RX_DMA_BUFFER_SIZE, DMA_FROM_DEVICE);
dma_chan = sport->dma_rx_chan;
sport->dma_rx_chan = NULL;
sport->dma_rx_buf_bus = 0;
sport->dma_rx_buf_virt = NULL;
dma_release_channel(dma_chan);
}
static int lpuart_startup(struct uart_port *port)
{
struct lpuart_port *sport = container_of(port, struct lpuart_port, port);
int ret;
unsigned long flags;
unsigned char temp;
if (lpuart_dma_tx_request(port) || lpuart_dma_rx_request(port)) {
sport->lpuart_dma_use = false;
} else {
sport->lpuart_dma_use = true;
temp = readb(port->membase + UARTCR5);
writeb(temp | UARTCR5_TDMAS, port->membase + UARTCR5);
}
ret = devm_request_irq(port->dev, port->irq, lpuart_int, 0,
DRIVER_NAME, sport);
if (ret)
return ret;
spin_lock_irqsave(&sport->port.lock, flags);
lpuart_setup_watermark(sport);
temp = readb(sport->port.membase + UARTCR2);
temp |= (UARTCR2_RIE | UARTCR2_TIE | UARTCR2_RE | UARTCR2_TE);
writeb(temp, sport->port.membase + UARTCR2);
spin_unlock_irqrestore(&sport->port.lock, flags);
return 0;
}
static void lpuart_shutdown(struct uart_port *port)
{
struct lpuart_port *sport = container_of(port, struct lpuart_port, port);
unsigned char temp;
unsigned long flags;
spin_lock_irqsave(&port->lock, flags);
temp = readb(port->membase + UARTCR2);
temp &= ~(UARTCR2_TE | UARTCR2_RE |
UARTCR2_TIE | UARTCR2_TCIE | UARTCR2_RIE);
writeb(temp, port->membase + UARTCR2);
spin_unlock_irqrestore(&port->lock, flags);
devm_free_irq(port->dev, port->irq, sport);
if (sport->lpuart_dma_use) {
lpuart_dma_tx_free(port);
lpuart_dma_rx_free(port);
}
}
static void
lpuart_set_termios(struct uart_port *port, struct ktermios *termios,
struct ktermios *old)
{
struct lpuart_port *sport = container_of(port, struct lpuart_port, port);
unsigned long flags;
unsigned char cr1, old_cr1, old_cr2, cr4, bdh, modem;
unsigned int baud;
unsigned int old_csize = old ? old->c_cflag & CSIZE : CS8;
unsigned int sbr, brfa;
cr1 = old_cr1 = readb(sport->port.membase + UARTCR1);
old_cr2 = readb(sport->port.membase + UARTCR2);
cr4 = readb(sport->port.membase + UARTCR4);
bdh = readb(sport->port.membase + UARTBDH);
modem = readb(sport->port.membase + UARTMODEM);
while ((termios->c_cflag & CSIZE) != CS8 &&
(termios->c_cflag & CSIZE) != CS7) {
termios->c_cflag &= ~CSIZE;
termios->c_cflag |= old_csize;
old_csize = CS8;
}
if ((termios->c_cflag & CSIZE) == CS8 ||
(termios->c_cflag & CSIZE) == CS7)
cr1 = old_cr1 & ~UARTCR1_M;
if (termios->c_cflag & CMSPAR) {
if ((termios->c_cflag & CSIZE) != CS8) {
termios->c_cflag &= ~CSIZE;
termios->c_cflag |= CS8;
}
cr1 |= UARTCR1_M;
}
if (termios->c_cflag & CRTSCTS) {
modem |= (UARTMODEM_RXRTSE | UARTMODEM_TXCTSE);
} else {
termios->c_cflag &= ~CRTSCTS;
modem &= ~(UARTMODEM_RXRTSE | UARTMODEM_TXCTSE);
}
if (termios->c_cflag & CSTOPB)
termios->c_cflag &= ~CSTOPB;
if ((termios->c_cflag & CSIZE) == CS7)
termios->c_cflag |= PARENB;
if ((termios->c_cflag & PARENB)) {
if (termios->c_cflag & CMSPAR) {
cr1 &= ~UARTCR1_PE;
cr1 |= UARTCR1_M;
} else {
cr1 |= UARTCR1_PE;
if ((termios->c_cflag & CSIZE) == CS8)
cr1 |= UARTCR1_M;
if (termios->c_cflag & PARODD)
cr1 |= UARTCR1_PT;
else
cr1 &= ~UARTCR1_PT;
}
}
baud = uart_get_baud_rate(port, termios, old, 50, port->uartclk / 16);
spin_lock_irqsave(&sport->port.lock, flags);
sport->port.read_status_mask = 0;
if (termios->c_iflag & INPCK)
sport->port.read_status_mask |= (UARTSR1_FE | UARTSR1_PE);
if (termios->c_iflag & (IGNBRK | BRKINT | PARMRK))
sport->port.read_status_mask |= UARTSR1_FE;
sport->port.ignore_status_mask = 0;
if (termios->c_iflag & IGNPAR)
sport->port.ignore_status_mask |= UARTSR1_PE;
if (termios->c_iflag & IGNBRK) {
sport->port.ignore_status_mask |= UARTSR1_FE;
if (termios->c_iflag & IGNPAR)
sport->port.ignore_status_mask |= UARTSR1_OR;
}
uart_update_timeout(port, termios->c_cflag, baud);
while (!(readb(sport->port.membase + UARTSR1) & UARTSR1_TC))
barrier();
writeb(old_cr2 & ~(UARTCR2_TE | UARTCR2_RE),
sport->port.membase + UARTCR2);
sbr = sport->port.uartclk / (16 * baud);
brfa = ((sport->port.uartclk - (16 * sbr * baud)) * 2) / baud;
bdh &= ~UARTBDH_SBR_MASK;
bdh |= (sbr >> 8) & 0x1F;
cr4 &= ~UARTCR4_BRFA_MASK;
brfa &= UARTCR4_BRFA_MASK;
writeb(cr4 | brfa, sport->port.membase + UARTCR4);
writeb(bdh, sport->port.membase + UARTBDH);
writeb(sbr & 0xFF, sport->port.membase + UARTBDL);
writeb(cr1, sport->port.membase + UARTCR1);
writeb(modem, sport->port.membase + UARTMODEM);
writeb(old_cr2, sport->port.membase + UARTCR2);
spin_unlock_irqrestore(&sport->port.lock, flags);
}
static const char *lpuart_type(struct uart_port *port)
{
return "FSL_LPUART";
}
static void lpuart_release_port(struct uart_port *port)
{
}
static int lpuart_request_port(struct uart_port *port)
{
return 0;
}
static void lpuart_config_port(struct uart_port *port, int flags)
{
if (flags & UART_CONFIG_TYPE)
port->type = PORT_LPUART;
}
static int lpuart_verify_port(struct uart_port *port, struct serial_struct *ser)
{
int ret = 0;
if (ser->type != PORT_UNKNOWN && ser->type != PORT_LPUART)
ret = -EINVAL;
if (port->irq != ser->irq)
ret = -EINVAL;
if (ser->io_type != UPIO_MEM)
ret = -EINVAL;
if (port->uartclk / 16 != ser->baud_base)
ret = -EINVAL;
if (port->iobase != ser->port)
ret = -EINVAL;
if (ser->hub6 != 0)
ret = -EINVAL;
return ret;
}
static void lpuart_console_putchar(struct uart_port *port, int ch)
{
while (!(readb(port->membase + UARTSR1) & UARTSR1_TDRE))
barrier();
writeb(ch, port->membase + UARTDR);
}
static void
lpuart_console_write(struct console *co, const char *s, unsigned int count)
{
struct lpuart_port *sport = lpuart_ports[co->index];
unsigned char old_cr2, cr2;
cr2 = old_cr2 = readb(sport->port.membase + UARTCR2);
cr2 |= (UARTCR2_TE | UARTCR2_RE);
cr2 &= ~(UARTCR2_TIE | UARTCR2_TCIE | UARTCR2_RIE);
writeb(cr2, sport->port.membase + UARTCR2);
uart_console_write(&sport->port, s, count, lpuart_console_putchar);
while (!(readb(sport->port.membase + UARTSR1) & UARTSR1_TC))
barrier();
writeb(old_cr2, sport->port.membase + UARTCR2);
}
static void __init
lpuart_console_get_options(struct lpuart_port *sport, int *baud,
int *parity, int *bits)
{
unsigned char cr, bdh, bdl, brfa;
unsigned int sbr, uartclk, baud_raw;
cr = readb(sport->port.membase + UARTCR2);
cr &= UARTCR2_TE | UARTCR2_RE;
if (!cr)
return;
cr = readb(sport->port.membase + UARTCR1);
*parity = 'n';
if (cr & UARTCR1_PE) {
if (cr & UARTCR1_PT)
*parity = 'o';
else
*parity = 'e';
}
if (cr & UARTCR1_M)
*bits = 9;
else
*bits = 8;
bdh = readb(sport->port.membase + UARTBDH);
bdh &= UARTBDH_SBR_MASK;
bdl = readb(sport->port.membase + UARTBDL);
sbr = bdh;
sbr <<= 8;
sbr |= bdl;
brfa = readb(sport->port.membase + UARTCR4);
brfa &= UARTCR4_BRFA_MASK;
uartclk = clk_get_rate(sport->clk);
baud_raw = uartclk / (16 * (sbr + brfa / 32));
if (*baud != baud_raw)
printk(KERN_INFO "Serial: Console lpuart rounded baud rate"
"from %d to %d\n", baud_raw, *baud);
}
static int __init lpuart_console_setup(struct console *co, char *options)
{
struct lpuart_port *sport;
int baud = 115200;
int bits = 8;
int parity = 'n';
int flow = 'n';
if (co->index == -1 || co->index >= ARRAY_SIZE(lpuart_ports))
co->index = 0;
sport = lpuart_ports[co->index];
if (sport == NULL)
return -ENODEV;
if (options)
uart_parse_options(options, &baud, &parity, &bits, &flow);
else
lpuart_console_get_options(sport, &baud, &parity, &bits);
lpuart_setup_watermark(sport);
return uart_set_options(&sport->port, co, baud, parity, bits, flow);
}
static int lpuart_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct lpuart_port *sport;
struct resource *res;
int ret;
sport = devm_kzalloc(&pdev->dev, sizeof(*sport), GFP_KERNEL);
if (!sport)
return -ENOMEM;
pdev->dev.coherent_dma_mask = 0;
ret = of_alias_get_id(np, "serial");
if (ret < 0) {
dev_err(&pdev->dev, "failed to get alias id, errno %d\n", ret);
return ret;
}
sport->port.line = ret;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res)
return -ENODEV;
sport->port.mapbase = res->start;
sport->port.membase = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(sport->port.membase))
return PTR_ERR(sport->port.membase);
sport->port.dev = &pdev->dev;
sport->port.type = PORT_LPUART;
sport->port.iotype = UPIO_MEM;
sport->port.irq = platform_get_irq(pdev, 0);
sport->port.ops = &lpuart_pops;
sport->port.flags = UPF_BOOT_AUTOCONF;
sport->clk = devm_clk_get(&pdev->dev, "ipg");
if (IS_ERR(sport->clk)) {
ret = PTR_ERR(sport->clk);
dev_err(&pdev->dev, "failed to get uart clk: %d\n", ret);
return ret;
}
ret = clk_prepare_enable(sport->clk);
if (ret) {
dev_err(&pdev->dev, "failed to enable uart clk: %d\n", ret);
return ret;
}
sport->port.uartclk = clk_get_rate(sport->clk);
lpuart_ports[sport->port.line] = sport;
platform_set_drvdata(pdev, &sport->port);
ret = uart_add_one_port(&lpuart_reg, &sport->port);
if (ret) {
clk_disable_unprepare(sport->clk);
return ret;
}
return 0;
}
static int lpuart_remove(struct platform_device *pdev)
{
struct lpuart_port *sport = platform_get_drvdata(pdev);
uart_remove_one_port(&lpuart_reg, &sport->port);
clk_disable_unprepare(sport->clk);
return 0;
}
static int lpuart_suspend(struct device *dev)
{
struct lpuart_port *sport = dev_get_drvdata(dev);
uart_suspend_port(&lpuart_reg, &sport->port);
return 0;
}
static int lpuart_resume(struct device *dev)
{
struct lpuart_port *sport = dev_get_drvdata(dev);
uart_resume_port(&lpuart_reg, &sport->port);
return 0;
}
static int __init lpuart_serial_init(void)
{
int ret;
pr_info("serial: Freescale lpuart driver\n");
ret = uart_register_driver(&lpuart_reg);
if (ret)
return ret;
ret = platform_driver_register(&lpuart_driver);
if (ret)
uart_unregister_driver(&lpuart_reg);
return ret;
}
static void __exit lpuart_serial_exit(void)
{
platform_driver_unregister(&lpuart_driver);
uart_unregister_driver(&lpuart_reg);
}
