static u32 lpuart32_read(void __iomem *addr)
{
return ioread32be(addr);
}
static void lpuart32_write(u32 val, void __iomem *addr)
{
iowrite32be(val, addr);
}
static void lpuart_stop_tx(struct uart_port *port)
{
unsigned char temp;
temp = readb(port->membase + UARTCR2);
temp &= ~(UARTCR2_TIE | UARTCR2_TCIE);
writeb(temp, port->membase + UARTCR2);
}
static void lpuart32_stop_tx(struct uart_port *port)
{
unsigned long temp;
temp = lpuart32_read(port->membase + UARTCTRL);
temp &= ~(UARTCTRL_TIE | UARTCTRL_TCIE);
lpuart32_write(temp, port->membase + UARTCTRL);
}
static void lpuart_stop_rx(struct uart_port *port)
{
unsigned char temp;
temp = readb(port->membase + UARTCR2);
writeb(temp & ~UARTCR2_RE, port->membase + UARTCR2);
}
static void lpuart32_stop_rx(struct uart_port *port)
{
unsigned long temp;
temp = lpuart32_read(port->membase + UARTCTRL);
lpuart32_write(temp & ~UARTCTRL_RE, port->membase + UARTCTRL);
}
static void lpuart_dma_tx(struct lpuart_port *sport)
{
struct circ_buf *xmit = &sport->port.state->xmit;
struct scatterlist *sgl = sport->tx_sgl;
struct device *dev = sport->port.dev;
int ret;
if (sport->dma_tx_in_progress)
return;
sport->dma_tx_bytes = uart_circ_chars_pending(xmit);
if (xmit->tail < xmit->head || xmit->head == 0) {
sport->dma_tx_nents = 1;
sg_init_one(sgl, xmit->buf + xmit->tail, sport->dma_tx_bytes);
} else {
sport->dma_tx_nents = 2;
sg_init_table(sgl, 2);
sg_set_buf(sgl, xmit->buf + xmit->tail,
UART_XMIT_SIZE - xmit->tail);
sg_set_buf(sgl + 1, xmit->buf, xmit->head);
}
ret = dma_map_sg(dev, sgl, sport->dma_tx_nents, DMA_TO_DEVICE);
if (!ret) {
dev_err(dev, "DMA mapping error for TX.\n");
return;
}
sport->dma_tx_desc = dmaengine_prep_slave_sg(sport->dma_tx_chan, sgl,
sport->dma_tx_nents,
DMA_MEM_TO_DEV, DMA_PREP_INTERRUPT);
if (!sport->dma_tx_desc) {
dma_unmap_sg(dev, sgl, sport->dma_tx_nents, DMA_TO_DEVICE);
dev_err(dev, "Cannot prepare TX slave DMA!\n");
return;
}
sport->dma_tx_desc->callback = lpuart_dma_tx_complete;
sport->dma_tx_desc->callback_param = sport;
sport->dma_tx_in_progress = true;
sport->dma_tx_cookie = dmaengine_submit(sport->dma_tx_desc);
dma_async_issue_pending(sport->dma_tx_chan);
}
static void lpuart_dma_tx_complete(void *arg)
{
struct lpuart_port *sport = arg;
struct scatterlist *sgl = &sport->tx_sgl[0];
struct circ_buf *xmit = &sport->port.state->xmit;
unsigned long flags;
spin_lock_irqsave(&sport->port.lock, flags);
dma_unmap_sg(sport->port.dev, sgl, sport->dma_tx_nents, DMA_TO_DEVICE);
xmit->tail = (xmit->tail + sport->dma_tx_bytes) & (UART_XMIT_SIZE - 1);
sport->port.icount.tx += sport->dma_tx_bytes;
sport->dma_tx_in_progress = false;
spin_unlock_irqrestore(&sport->port.lock, flags);
if (uart_circ_chars_pending(xmit) < WAKEUP_CHARS)
uart_write_wakeup(&sport->port);
if (waitqueue_active(&sport->dma_wait)) {
wake_up(&sport->dma_wait);
return;
}
spin_lock_irqsave(&sport->port.lock, flags);
if (!uart_circ_empty(xmit) && !uart_tx_stopped(&sport->port))
lpuart_dma_tx(sport);
spin_unlock_irqrestore(&sport->port.lock, flags);
}
static int lpuart_dma_tx_request(struct uart_port *port)
{
struct lpuart_port *sport = container_of(port,
struct lpuart_port, port);
struct dma_slave_config dma_tx_sconfig = {};
int ret;
dma_tx_sconfig.dst_addr = sport->port.mapbase + UARTDR;
dma_tx_sconfig.dst_addr_width = DMA_SLAVE_BUSWIDTH_1_BYTE;
dma_tx_sconfig.dst_maxburst = 1;
dma_tx_sconfig.direction = DMA_MEM_TO_DEV;
ret = dmaengine_slave_config(sport->dma_tx_chan, &dma_tx_sconfig);
if (ret) {
dev_err(sport->port.dev,
"DMA slave config failed, err = %d\n", ret);
return ret;
}
return 0;
}
static void lpuart_flush_buffer(struct uart_port *port)
{
struct lpuart_port *sport = container_of(port, struct lpuart_port, port);
if (sport->lpuart_dma_tx_use) {
if (sport->dma_tx_in_progress) {
dma_unmap_sg(sport->port.dev, &sport->tx_sgl[0],
sport->dma_tx_nents, DMA_TO_DEVICE);
sport->dma_tx_in_progress = false;
}
dmaengine_terminate_all(sport->dma_tx_chan);
}
}
static int lpuart_poll_init(struct uart_port *port)
{
struct lpuart_port *sport = container_of(port,
struct lpuart_port, port);
unsigned long flags;
unsigned char temp;
sport->port.fifosize = 0;
spin_lock_irqsave(&sport->port.lock, flags);
writeb(0, sport->port.membase + UARTCR2);
temp = readb(sport->port.membase + UARTPFIFO);
writeb(temp | UARTPFIFO_RXFE | UARTPFIFO_TXFE,
sport->port.membase + UARTPFIFO);
writeb(UARTCFIFO_TXFLUSH | UARTCFIFO_RXFLUSH,
sport->port.membase + UARTCFIFO);
if (readb(sport->port.membase + UARTSR1) & UARTSR1_RDRF) {
readb(sport->port.membase + UARTDR);
writeb(UARTSFIFO_RXUF, sport->port.membase + UARTSFIFO);
}
writeb(0, sport->port.membase + UARTTWFIFO);
writeb(1, sport->port.membase + UARTRWFIFO);
writeb(UARTCR2_RE | UARTCR2_TE, sport->port.membase + UARTCR2);
spin_unlock_irqrestore(&sport->port.lock, flags);
return 0;
}
static void lpuart_poll_put_char(struct uart_port *port, unsigned char c)
{
while (!(readb(port->membase + UARTSR1) & UARTSR1_TDRE))
barrier();
writeb(c, port->membase + UARTDR);
}
static int lpuart_poll_get_char(struct uart_port *port)
{
if (!(readb(port->membase + UARTSR1) & UARTSR1_RDRF))
return NO_POLL_CHAR;
return readb(port->membase + UARTDR);
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
static inline void lpuart32_transmit_buffer(struct lpuart_port *sport)
{
struct circ_buf *xmit = &sport->port.state->xmit;
unsigned long txcnt;
txcnt = lpuart32_read(sport->port.membase + UARTWATER);
txcnt = txcnt >> UARTWATER_TXCNT_OFF;
txcnt &= UARTWATER_COUNT_MASK;
while (!uart_circ_empty(xmit) && (txcnt < sport->txfifo_size)) {
lpuart32_write(xmit->buf[xmit->tail], sport->port.membase + UARTDATA);
xmit->tail = (xmit->tail + 1) & (UART_XMIT_SIZE - 1);
sport->port.icount.tx++;
txcnt = lpuart32_read(sport->port.membase + UARTWATER);
txcnt = txcnt >> UARTWATER_TXCNT_OFF;
txcnt &= UARTWATER_COUNT_MASK;
}
if (uart_circ_chars_pending(xmit) < WAKEUP_CHARS)
uart_write_wakeup(&sport->port);
if (uart_circ_empty(xmit))
lpuart32_stop_tx(&sport->port);
}
static void lpuart_start_tx(struct uart_port *port)
{
struct lpuart_port *sport = container_of(port,
struct lpuart_port, port);
struct circ_buf *xmit = &sport->port.state->xmit;
unsigned char temp;
temp = readb(port->membase + UARTCR2);
writeb(temp | UARTCR2_TIE, port->membase + UARTCR2);
if (sport->lpuart_dma_tx_use) {
if (!uart_circ_empty(xmit) && !uart_tx_stopped(port))
lpuart_dma_tx(sport);
} else {
if (readb(port->membase + UARTSR1) & UARTSR1_TDRE)
lpuart_transmit_buffer(sport);
}
}
static void lpuart32_start_tx(struct uart_port *port)
{
struct lpuart_port *sport = container_of(port, struct lpuart_port, port);
unsigned long temp;
temp = lpuart32_read(port->membase + UARTCTRL);
lpuart32_write(temp | UARTCTRL_TIE, port->membase + UARTCTRL);
if (lpuart32_read(port->membase + UARTSTAT) & UARTSTAT_TDRE)
lpuart32_transmit_buffer(sport);
}
static unsigned int lpuart_tx_empty(struct uart_port *port)
{
struct lpuart_port *sport = container_of(port,
struct lpuart_port, port);
unsigned char sr1 = readb(port->membase + UARTSR1);
unsigned char sfifo = readb(port->membase + UARTSFIFO);
if (sport->dma_tx_in_progress)
return 0;
if (sr1 & UARTSR1_TC && sfifo & UARTSFIFO_TXEMPT)
return TIOCSER_TEMT;
return 0;
}
static unsigned int lpuart32_tx_empty(struct uart_port *port)
{
return (lpuart32_read(port->membase + UARTSTAT) & UARTSTAT_TC) ?
TIOCSER_TEMT : 0;
}
static irqreturn_t lpuart_txint(int irq, void *dev_id)
{
struct lpuart_port *sport = dev_id;
struct circ_buf *xmit = &sport->port.state->xmit;
unsigned long flags;
spin_lock_irqsave(&sport->port.lock, flags);
if (sport->port.x_char) {
if (sport->lpuart32)
lpuart32_write(sport->port.x_char, sport->port.membase + UARTDATA);
else
writeb(sport->port.x_char, sport->port.membase + UARTDR);
goto out;
}
if (uart_circ_empty(xmit) || uart_tx_stopped(&sport->port)) {
if (sport->lpuart32)
lpuart32_stop_tx(&sport->port);
else
lpuart_stop_tx(&sport->port);
goto out;
}
if (sport->lpuart32)
lpuart32_transmit_buffer(sport);
else
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
static irqreturn_t lpuart32_rxint(int irq, void *dev_id)
{
struct lpuart_port *sport = dev_id;
unsigned int flg, ignored = 0;
struct tty_port *port = &sport->port.state->port;
unsigned long flags;
unsigned long rx, sr;
spin_lock_irqsave(&sport->port.lock, flags);
while (!(lpuart32_read(sport->port.membase + UARTFIFO) & UARTFIFO_RXEMPT)) {
flg = TTY_NORMAL;
sport->port.icount.rx++;
sr = lpuart32_read(sport->port.membase + UARTSTAT);
rx = lpuart32_read(sport->port.membase + UARTDATA);
rx &= 0x3ff;
if (uart_handle_sysrq_char(&sport->port, (unsigned char)rx))
continue;
if (sr & (UARTSTAT_PE | UARTSTAT_OR | UARTSTAT_FE)) {
if (sr & UARTSTAT_PE)
sport->port.icount.parity++;
else if (sr & UARTSTAT_FE)
sport->port.icount.frame++;
if (sr & UARTSTAT_OR)
sport->port.icount.overrun++;
if (sr & sport->port.ignore_status_mask) {
if (++ignored > 100)
goto out;
continue;
}
sr &= sport->port.read_status_mask;
if (sr & UARTSTAT_PE)
flg = TTY_PARITY;
else if (sr & UARTSTAT_FE)
flg = TTY_FRAME;
if (sr & UARTSTAT_OR)
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
if (sts & UARTSR1_RDRF)
lpuart_rxint(irq, dev_id);
if (sts & UARTSR1_TDRE)
lpuart_txint(irq, dev_id);
return IRQ_HANDLED;
}
static irqreturn_t lpuart32_int(int irq, void *dev_id)
{
struct lpuart_port *sport = dev_id;
unsigned long sts, rxcount;
sts = lpuart32_read(sport->port.membase + UARTSTAT);
rxcount = lpuart32_read(sport->port.membase + UARTWATER);
rxcount = rxcount >> UARTWATER_RXCNT_OFF;
if (sts & UARTSTAT_RDRF || rxcount > 0)
lpuart32_rxint(irq, dev_id);
if ((sts & UARTSTAT_TDRE) &&
!(lpuart32_read(sport->port.membase + UARTBAUD) & UARTBAUD_TDMAE))
lpuart_txint(irq, dev_id);
lpuart32_write(sts, sport->port.membase + UARTSTAT);
return IRQ_HANDLED;
}
static void lpuart_copy_rx_to_tty(struct lpuart_port *sport)
{
struct tty_port *port = &sport->port.state->port;
struct dma_tx_state state;
enum dma_status dmastat;
struct circ_buf *ring = &sport->rx_ring;
unsigned long flags;
int count = 0;
unsigned char sr;
sr = readb(sport->port.membase + UARTSR1);
if (sr & (UARTSR1_PE | UARTSR1_FE)) {
readb(sport->port.membase + UARTDR);
if (sr & UARTSR1_PE)
sport->port.icount.parity++;
else if (sr & UARTSR1_FE)
sport->port.icount.frame++;
}
async_tx_ack(sport->dma_rx_desc);
spin_lock_irqsave(&sport->port.lock, flags);
dmastat = dmaengine_tx_status(sport->dma_rx_chan,
sport->dma_rx_cookie,
&state);
if (dmastat == DMA_ERROR) {
dev_err(sport->port.dev, "Rx DMA transfer failed!\n");
spin_unlock_irqrestore(&sport->port.lock, flags);
return;
}
dma_sync_sg_for_cpu(sport->port.dev, &sport->rx_sgl, 1, DMA_FROM_DEVICE);
ring->head = sport->rx_sgl.length - state.residue;
BUG_ON(ring->head > sport->rx_sgl.length);
if (ring->head < ring->tail) {
count = sport->rx_sgl.length - ring->tail;
tty_insert_flip_string(port, ring->buf + ring->tail, count);
ring->tail = 0;
sport->port.icount.rx += count;
}
if (ring->tail < ring->head) {
count = ring->head - ring->tail;
tty_insert_flip_string(port, ring->buf + ring->tail, count);
if (ring->head >= sport->rx_sgl.length)
ring->head = 0;
ring->tail = ring->head;
sport->port.icount.rx += count;
}
dma_sync_sg_for_device(sport->port.dev, &sport->rx_sgl, 1,
DMA_FROM_DEVICE);
spin_unlock_irqrestore(&sport->port.lock, flags);
tty_flip_buffer_push(port);
mod_timer(&sport->lpuart_timer, jiffies + sport->dma_rx_timeout);
}
static void lpuart_dma_rx_complete(void *arg)
{
struct lpuart_port *sport = arg;
lpuart_copy_rx_to_tty(sport);
}
static void lpuart_timer_func(unsigned long data)
{
struct lpuart_port *sport = (struct lpuart_port *)data;
lpuart_copy_rx_to_tty(sport);
}
static inline int lpuart_start_rx_dma(struct lpuart_port *sport)
{
struct dma_slave_config dma_rx_sconfig = {};
struct circ_buf *ring = &sport->rx_ring;
int ret, nent;
int bits, baud;
struct tty_struct *tty = tty_port_tty_get(&sport->port.state->port);
struct ktermios *termios = &tty->termios;
baud = tty_get_baud_rate(tty);
bits = (termios->c_cflag & CSIZE) == CS7 ? 9 : 10;
if (termios->c_cflag & PARENB)
bits++;
sport->rx_dma_rng_buf_len = (DMA_RX_TIMEOUT * baud / bits / 1000) * 2;
sport->rx_dma_rng_buf_len = (1 << (fls(sport->rx_dma_rng_buf_len) - 1));
if (sport->rx_dma_rng_buf_len < 16)
sport->rx_dma_rng_buf_len = 16;
ring->buf = kmalloc(sport->rx_dma_rng_buf_len, GFP_ATOMIC);
if (!ring->buf) {
dev_err(sport->port.dev, "Ring buf alloc failed\n");
return -ENOMEM;
}
sg_init_one(&sport->rx_sgl, ring->buf, sport->rx_dma_rng_buf_len);
sg_set_buf(&sport->rx_sgl, ring->buf, sport->rx_dma_rng_buf_len);
nent = dma_map_sg(sport->port.dev, &sport->rx_sgl, 1, DMA_FROM_DEVICE);
if (!nent) {
dev_err(sport->port.dev, "DMA Rx mapping error\n");
return -EINVAL;
}
dma_rx_sconfig.src_addr = sport->port.mapbase + UARTDR;
dma_rx_sconfig.src_addr_width = DMA_SLAVE_BUSWIDTH_1_BYTE;
dma_rx_sconfig.src_maxburst = 1;
dma_rx_sconfig.direction = DMA_DEV_TO_MEM;
ret = dmaengine_slave_config(sport->dma_rx_chan, &dma_rx_sconfig);
if (ret < 0) {
dev_err(sport->port.dev,
"DMA Rx slave config failed, err = %d\n", ret);
return ret;
}
sport->dma_rx_desc = dmaengine_prep_dma_cyclic(sport->dma_rx_chan,
sg_dma_address(&sport->rx_sgl),
sport->rx_sgl.length,
sport->rx_sgl.length / 2,
DMA_DEV_TO_MEM,
DMA_PREP_INTERRUPT);
if (!sport->dma_rx_desc) {
dev_err(sport->port.dev, "Cannot prepare cyclic DMA\n");
return -EFAULT;
}
sport->dma_rx_desc->callback = lpuart_dma_rx_complete;
sport->dma_rx_desc->callback_param = sport;
sport->dma_rx_cookie = dmaengine_submit(sport->dma_rx_desc);
dma_async_issue_pending(sport->dma_rx_chan);
writeb(readb(sport->port.membase + UARTCR5) | UARTCR5_RDMAS,
sport->port.membase + UARTCR5);
return 0;
}
static void lpuart_dma_rx_free(struct uart_port *port)
{
struct lpuart_port *sport = container_of(port,
struct lpuart_port, port);
if (sport->dma_rx_chan)
dmaengine_terminate_all(sport->dma_rx_chan);
dma_unmap_sg(sport->port.dev, &sport->rx_sgl, 1, DMA_FROM_DEVICE);
kfree(sport->rx_ring.buf);
sport->rx_ring.tail = 0;
sport->rx_ring.head = 0;
sport->dma_rx_desc = NULL;
sport->dma_rx_cookie = -EINVAL;
}
static int lpuart_config_rs485(struct uart_port *port,
struct serial_rs485 *rs485)
{
struct lpuart_port *sport = container_of(port,
struct lpuart_port, port);
u8 modem = readb(sport->port.membase + UARTMODEM) &
~(UARTMODEM_TXRTSPOL | UARTMODEM_TXRTSE);
writeb(modem, sport->port.membase + UARTMODEM);
if (rs485->flags & SER_RS485_ENABLED) {
modem |= UARTMODEM_TXRTSE;
if (!(rs485->flags & (SER_RS485_RTS_ON_SEND |
SER_RS485_RTS_AFTER_SEND)))
rs485->flags |= SER_RS485_RTS_ON_SEND;
if (rs485->flags & SER_RS485_RTS_ON_SEND &&
rs485->flags & SER_RS485_RTS_AFTER_SEND)
rs485->flags &= ~SER_RS485_RTS_AFTER_SEND;
if (rs485->flags & SER_RS485_RTS_ON_SEND)
modem &= ~UARTMODEM_TXRTSPOL;
else if (rs485->flags & SER_RS485_RTS_AFTER_SEND)
modem |= UARTMODEM_TXRTSPOL;
}
sport->port.rs485 = *rs485;
writeb(modem, sport->port.membase + UARTMODEM);
return 0;
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
static unsigned int lpuart32_get_mctrl(struct uart_port *port)
{
unsigned int temp = 0;
unsigned long reg;
reg = lpuart32_read(port->membase + UARTMODIR);
if (reg & UARTMODIR_TXCTSE)
temp |= TIOCM_CTS;
if (reg & UARTMODIR_RXRTSE)
temp |= TIOCM_RTS;
return temp;
}
static void lpuart_set_mctrl(struct uart_port *port, unsigned int mctrl)
{
unsigned char temp;
struct lpuart_port *sport = container_of(port,
struct lpuart_port, port);
if (!(sport->port.rs485.flags & SER_RS485_ENABLED)) {
temp = readb(sport->port.membase + UARTMODEM) &
~(UARTMODEM_RXRTSE | UARTMODEM_TXCTSE);
if (mctrl & TIOCM_RTS)
temp |= UARTMODEM_RXRTSE;
if (mctrl & TIOCM_CTS)
temp |= UARTMODEM_TXCTSE;
writeb(temp, port->membase + UARTMODEM);
}
}
static void lpuart32_set_mctrl(struct uart_port *port, unsigned int mctrl)
{
unsigned long temp;
temp = lpuart32_read(port->membase + UARTMODIR) &
~(UARTMODIR_RXRTSE | UARTMODIR_TXCTSE);
if (mctrl & TIOCM_RTS)
temp |= UARTMODIR_RXRTSE;
if (mctrl & TIOCM_CTS)
temp |= UARTMODIR_TXCTSE;
lpuart32_write(temp, port->membase + UARTMODIR);
}
static void lpuart_break_ctl(struct uart_port *port, int break_state)
{
unsigned char temp;
temp = readb(port->membase + UARTCR2) & ~UARTCR2_SBK;
if (break_state != 0)
temp |= UARTCR2_SBK;
writeb(temp, port->membase + UARTCR2);
}
static void lpuart32_break_ctl(struct uart_port *port, int break_state)
{
unsigned long temp;
temp = lpuart32_read(port->membase + UARTCTRL) & ~UARTCTRL_SBK;
if (break_state != 0)
temp |= UARTCTRL_SBK;
lpuart32_write(temp, port->membase + UARTCTRL);
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
writeb(val | UARTPFIFO_TXFE | UARTPFIFO_RXFE,
sport->port.membase + UARTPFIFO);
writeb(UARTCFIFO_TXFLUSH | UARTCFIFO_RXFLUSH,
sport->port.membase + UARTCFIFO);
if (readb(sport->port.membase + UARTSR1) & UARTSR1_RDRF) {
readb(sport->port.membase + UARTDR);
writeb(UARTSFIFO_RXUF, sport->port.membase + UARTSFIFO);
}
writeb(0, sport->port.membase + UARTTWFIFO);
writeb(1, sport->port.membase + UARTRWFIFO);
writeb(cr2_saved, sport->port.membase + UARTCR2);
}
static void lpuart32_setup_watermark(struct lpuart_port *sport)
{
unsigned long val, ctrl;
unsigned long ctrl_saved;
ctrl = lpuart32_read(sport->port.membase + UARTCTRL);
ctrl_saved = ctrl;
ctrl &= ~(UARTCTRL_TIE | UARTCTRL_TCIE | UARTCTRL_TE |
UARTCTRL_RIE | UARTCTRL_RE);
lpuart32_write(ctrl, sport->port.membase + UARTCTRL);
val = lpuart32_read(sport->port.membase + UARTFIFO);
val |= UARTFIFO_TXFE | UARTFIFO_RXFE;
val |= UARTFIFO_TXFLUSH | UARTFIFO_RXFLUSH;
lpuart32_write(val, sport->port.membase + UARTFIFO);
val = (0x1 << UARTWATER_RXWATER_OFF) | (0x0 << UARTWATER_TXWATER_OFF);
lpuart32_write(val, sport->port.membase + UARTWATER);
lpuart32_write(ctrl_saved, sport->port.membase + UARTCTRL);
}
static void rx_dma_timer_init(struct lpuart_port *sport)
{
setup_timer(&sport->lpuart_timer, lpuart_timer_func,
(unsigned long)sport);
sport->lpuart_timer.expires = jiffies + sport->dma_rx_timeout;
add_timer(&sport->lpuart_timer);
}
static int lpuart_startup(struct uart_port *port)
{
struct lpuart_port *sport = container_of(port, struct lpuart_port, port);
int ret;
unsigned long flags;
unsigned char temp;
temp = readb(sport->port.membase + UARTPFIFO);
sport->txfifo_size = 0x1 << (((temp >> UARTPFIFO_TXSIZE_OFF) &
UARTPFIFO_FIFOSIZE_MASK) + 1);
sport->port.fifosize = sport->txfifo_size;
sport->rxfifo_size = 0x1 << (((temp >> UARTPFIFO_RXSIZE_OFF) &
UARTPFIFO_FIFOSIZE_MASK) + 1);
ret = devm_request_irq(port->dev, port->irq, lpuart_int, 0,
DRIVER_NAME, sport);
if (ret)
return ret;
spin_lock_irqsave(&sport->port.lock, flags);
lpuart_setup_watermark(sport);
temp = readb(sport->port.membase + UARTCR2);
temp |= (UARTCR2_RIE | UARTCR2_TIE | UARTCR2_RE | UARTCR2_TE);
writeb(temp, sport->port.membase + UARTCR2);
if (sport->dma_rx_chan && !lpuart_start_rx_dma(sport)) {
sport->dma_rx_timeout = msecs_to_jiffies(DMA_RX_TIMEOUT);
if (!sport->dma_rx_timeout)
sport->dma_rx_timeout = 1;
sport->lpuart_dma_rx_use = true;
rx_dma_timer_init(sport);
} else {
sport->lpuart_dma_rx_use = false;
}
if (sport->dma_tx_chan && !lpuart_dma_tx_request(port)) {
init_waitqueue_head(&sport->dma_wait);
sport->lpuart_dma_tx_use = true;
temp = readb(port->membase + UARTCR5);
writeb(temp | UARTCR5_TDMAS, port->membase + UARTCR5);
} else {
sport->lpuart_dma_tx_use = false;
}
spin_unlock_irqrestore(&sport->port.lock, flags);
return 0;
}
static int lpuart32_startup(struct uart_port *port)
{
struct lpuart_port *sport = container_of(port, struct lpuart_port, port);
int ret;
unsigned long flags;
unsigned long temp;
temp = lpuart32_read(sport->port.membase + UARTFIFO);
sport->txfifo_size = 0x1 << (((temp >> UARTFIFO_TXSIZE_OFF) &
UARTFIFO_FIFOSIZE_MASK) - 1);
sport->rxfifo_size = 0x1 << (((temp >> UARTFIFO_RXSIZE_OFF) &
UARTFIFO_FIFOSIZE_MASK) - 1);
ret = devm_request_irq(port->dev, port->irq, lpuart32_int, 0,
DRIVER_NAME, sport);
if (ret)
return ret;
spin_lock_irqsave(&sport->port.lock, flags);
lpuart32_setup_watermark(sport);
temp = lpuart32_read(sport->port.membase + UARTCTRL);
temp |= (UARTCTRL_RIE | UARTCTRL_TIE | UARTCTRL_RE | UARTCTRL_TE);
temp |= UARTCTRL_ILIE;
lpuart32_write(temp, sport->port.membase + UARTCTRL);
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
if (sport->lpuart_dma_rx_use) {
del_timer_sync(&sport->lpuart_timer);
lpuart_dma_rx_free(&sport->port);
}
if (sport->lpuart_dma_tx_use) {
if (wait_event_interruptible(sport->dma_wait,
!sport->dma_tx_in_progress) != false) {
sport->dma_tx_in_progress = false;
dmaengine_terminate_all(sport->dma_tx_chan);
}
lpuart_stop_tx(port);
}
}
static void lpuart32_shutdown(struct uart_port *port)
{
struct lpuart_port *sport = container_of(port, struct lpuart_port, port);
unsigned long temp;
unsigned long flags;
spin_lock_irqsave(&port->lock, flags);
temp = lpuart32_read(port->membase + UARTCTRL);
temp &= ~(UARTCTRL_TE | UARTCTRL_RE |
UARTCTRL_TIE | UARTCTRL_TCIE | UARTCTRL_RIE);
lpuart32_write(temp, port->membase + UARTCTRL);
spin_unlock_irqrestore(&port->lock, flags);
devm_free_irq(port->dev, port->irq, sport);
}
static void
lpuart_set_termios(struct uart_port *port, struct ktermios *termios,
struct ktermios *old)
{
struct lpuart_port *sport = container_of(port, struct lpuart_port, port);
unsigned long flags;
unsigned char cr1, old_cr1, old_cr2, cr3, cr4, bdh, modem;
unsigned int baud;
unsigned int old_csize = old ? old->c_cflag & CSIZE : CS8;
unsigned int sbr, brfa;
cr1 = old_cr1 = readb(sport->port.membase + UARTCR1);
old_cr2 = readb(sport->port.membase + UARTCR2);
cr3 = readb(sport->port.membase + UARTCR3);
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
if (sport->port.rs485.flags & SER_RS485_ENABLED)
termios->c_cflag &= ~CRTSCTS;
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
if (termios->c_cflag & PARODD)
cr3 |= UARTCR3_T8;
else
cr3 &= ~UARTCR3_T8;
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
if (old && sport->lpuart_dma_rx_use) {
del_timer_sync(&sport->lpuart_timer);
lpuart_dma_rx_free(&sport->port);
}
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
writeb(cr3, sport->port.membase + UARTCR3);
writeb(cr1, sport->port.membase + UARTCR1);
writeb(modem, sport->port.membase + UARTMODEM);
writeb(old_cr2, sport->port.membase + UARTCR2);
if (old && sport->lpuart_dma_rx_use) {
if (!lpuart_start_rx_dma(sport))
rx_dma_timer_init(sport);
else
sport->lpuart_dma_rx_use = false;
}
spin_unlock_irqrestore(&sport->port.lock, flags);
}
static void
lpuart32_set_termios(struct uart_port *port, struct ktermios *termios,
struct ktermios *old)
{
struct lpuart_port *sport = container_of(port, struct lpuart_port, port);
unsigned long flags;
unsigned long ctrl, old_ctrl, bd, modem;
unsigned int baud;
unsigned int old_csize = old ? old->c_cflag & CSIZE : CS8;
unsigned int sbr;
ctrl = old_ctrl = lpuart32_read(sport->port.membase + UARTCTRL);
bd = lpuart32_read(sport->port.membase + UARTBAUD);
modem = lpuart32_read(sport->port.membase + UARTMODIR);
while ((termios->c_cflag & CSIZE) != CS8 &&
(termios->c_cflag & CSIZE) != CS7) {
termios->c_cflag &= ~CSIZE;
termios->c_cflag |= old_csize;
old_csize = CS8;
}
if ((termios->c_cflag & CSIZE) == CS8 ||
(termios->c_cflag & CSIZE) == CS7)
ctrl = old_ctrl & ~UARTCTRL_M;
if (termios->c_cflag & CMSPAR) {
if ((termios->c_cflag & CSIZE) != CS8) {
termios->c_cflag &= ~CSIZE;
termios->c_cflag |= CS8;
}
ctrl |= UARTCTRL_M;
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
ctrl &= ~UARTCTRL_PE;
ctrl |= UARTCTRL_M;
} else {
ctrl |= UARTCR1_PE;
if ((termios->c_cflag & CSIZE) == CS8)
ctrl |= UARTCTRL_M;
if (termios->c_cflag & PARODD)
ctrl |= UARTCTRL_PT;
else
ctrl &= ~UARTCTRL_PT;
}
}
baud = uart_get_baud_rate(port, termios, old, 50, port->uartclk / 16);
spin_lock_irqsave(&sport->port.lock, flags);
sport->port.read_status_mask = 0;
if (termios->c_iflag & INPCK)
sport->port.read_status_mask |= (UARTSTAT_FE | UARTSTAT_PE);
if (termios->c_iflag & (IGNBRK | BRKINT | PARMRK))
sport->port.read_status_mask |= UARTSTAT_FE;
sport->port.ignore_status_mask = 0;
if (termios->c_iflag & IGNPAR)
sport->port.ignore_status_mask |= UARTSTAT_PE;
if (termios->c_iflag & IGNBRK) {
sport->port.ignore_status_mask |= UARTSTAT_FE;
if (termios->c_iflag & IGNPAR)
sport->port.ignore_status_mask |= UARTSTAT_OR;
}
uart_update_timeout(port, termios->c_cflag, baud);
while (!(lpuart32_read(sport->port.membase + UARTSTAT) & UARTSTAT_TC))
barrier();
lpuart32_write(old_ctrl & ~(UARTCTRL_TE | UARTCTRL_RE),
sport->port.membase + UARTCTRL);
sbr = sport->port.uartclk / (16 * baud);
bd &= ~UARTBAUD_SBR_MASK;
bd |= sbr & UARTBAUD_SBR_MASK;
bd |= UARTBAUD_BOTHEDGE;
bd &= ~(UARTBAUD_TDMAE | UARTBAUD_RDMAE);
lpuart32_write(bd, sport->port.membase + UARTBAUD);
lpuart32_write(modem, sport->port.membase + UARTMODIR);
lpuart32_write(ctrl, sport->port.membase + UARTCTRL);
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
static void lpuart32_console_putchar(struct uart_port *port, int ch)
{
while (!(lpuart32_read(port->membase + UARTSTAT) & UARTSTAT_TDRE))
barrier();
lpuart32_write(ch, port->membase + UARTDATA);
}
static void
lpuart_console_write(struct console *co, const char *s, unsigned int count)
{
struct lpuart_port *sport = lpuart_ports[co->index];
unsigned char old_cr2, cr2;
unsigned long flags;
int locked = 1;
if (sport->port.sysrq || oops_in_progress)
locked = spin_trylock_irqsave(&sport->port.lock, flags);
else
spin_lock_irqsave(&sport->port.lock, flags);
cr2 = old_cr2 = readb(sport->port.membase + UARTCR2);
cr2 |= (UARTCR2_TE | UARTCR2_RE);
cr2 &= ~(UARTCR2_TIE | UARTCR2_TCIE | UARTCR2_RIE);
writeb(cr2, sport->port.membase + UARTCR2);
uart_console_write(&sport->port, s, count, lpuart_console_putchar);
while (!(readb(sport->port.membase + UARTSR1) & UARTSR1_TC))
barrier();
writeb(old_cr2, sport->port.membase + UARTCR2);
if (locked)
spin_unlock_irqrestore(&sport->port.lock, flags);
}
static void
lpuart32_console_write(struct console *co, const char *s, unsigned int count)
{
struct lpuart_port *sport = lpuart_ports[co->index];
unsigned long old_cr, cr;
unsigned long flags;
int locked = 1;
if (sport->port.sysrq || oops_in_progress)
locked = spin_trylock_irqsave(&sport->port.lock, flags);
else
spin_lock_irqsave(&sport->port.lock, flags);
cr = old_cr = lpuart32_read(sport->port.membase + UARTCTRL);
cr |= (UARTCTRL_TE | UARTCTRL_RE);
cr &= ~(UARTCTRL_TIE | UARTCTRL_TCIE | UARTCTRL_RIE);
lpuart32_write(cr, sport->port.membase + UARTCTRL);
uart_console_write(&sport->port, s, count, lpuart32_console_putchar);
while (!(lpuart32_read(sport->port.membase + UARTSTAT) & UARTSTAT_TC))
barrier();
lpuart32_write(old_cr, sport->port.membase + UARTCTRL);
if (locked)
spin_unlock_irqrestore(&sport->port.lock, flags);
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
static void __init
lpuart32_console_get_options(struct lpuart_port *sport, int *baud,
int *parity, int *bits)
{
unsigned long cr, bd;
unsigned int sbr, uartclk, baud_raw;
cr = lpuart32_read(sport->port.membase + UARTCTRL);
cr &= UARTCTRL_TE | UARTCTRL_RE;
if (!cr)
return;
cr = lpuart32_read(sport->port.membase + UARTCTRL);
*parity = 'n';
if (cr & UARTCTRL_PE) {
if (cr & UARTCTRL_PT)
*parity = 'o';
else
*parity = 'e';
}
if (cr & UARTCTRL_M)
*bits = 9;
else
*bits = 8;
bd = lpuart32_read(sport->port.membase + UARTBAUD);
bd &= UARTBAUD_SBR_MASK;
sbr = bd;
uartclk = clk_get_rate(sport->clk);
baud_raw = uartclk / (16 * sbr);
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
if (sport->lpuart32)
lpuart32_console_get_options(sport, &baud, &parity, &bits);
else
lpuart_console_get_options(sport, &baud, &parity, &bits);
if (sport->lpuart32)
lpuart32_setup_watermark(sport);
else
lpuart_setup_watermark(sport);
return uart_set_options(&sport->port, co, baud, parity, bits, flow);
}
static void lpuart_early_write(struct console *con, const char *s, unsigned n)
{
struct earlycon_device *dev = con->data;
uart_console_write(&dev->port, s, n, lpuart_console_putchar);
}
static void lpuart32_early_write(struct console *con, const char *s, unsigned n)
{
struct earlycon_device *dev = con->data;
uart_console_write(&dev->port, s, n, lpuart32_console_putchar);
}
static int __init lpuart_early_console_setup(struct earlycon_device *device,
const char *opt)
{
if (!device->port.membase)
return -ENODEV;
device->con->write = lpuart_early_write;
return 0;
}
static int __init lpuart32_early_console_setup(struct earlycon_device *device,
const char *opt)
{
if (!device->port.membase)
return -ENODEV;
device->con->write = lpuart32_early_write;
return 0;
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
sport->lpuart32 = of_device_is_compatible(np, "fsl,ls1021a-lpuart");
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
sport->port.membase = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(sport->port.membase))
return PTR_ERR(sport->port.membase);
sport->port.mapbase = res->start;
sport->port.dev = &pdev->dev;
sport->port.type = PORT_LPUART;
sport->port.iotype = UPIO_MEM;
ret = platform_get_irq(pdev, 0);
if (ret < 0) {
dev_err(&pdev->dev, "cannot obtain irq\n");
return ret;
}
sport->port.irq = ret;
if (sport->lpuart32)
sport->port.ops = &lpuart32_pops;
else
sport->port.ops = &lpuart_pops;
sport->port.flags = UPF_BOOT_AUTOCONF;
sport->port.rs485_config = lpuart_config_rs485;
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
if (sport->lpuart32)
lpuart_reg.cons = LPUART32_CONSOLE;
else
lpuart_reg.cons = LPUART_CONSOLE;
ret = uart_add_one_port(&lpuart_reg, &sport->port);
if (ret) {
clk_disable_unprepare(sport->clk);
return ret;
}
sport->dma_tx_chan = dma_request_slave_channel(sport->port.dev, "tx");
if (!sport->dma_tx_chan)
dev_info(sport->port.dev, "DMA tx channel request failed, "
"operating without tx DMA\n");
sport->dma_rx_chan = dma_request_slave_channel(sport->port.dev, "rx");
if (!sport->dma_rx_chan)
dev_info(sport->port.dev, "DMA rx channel request failed, "
"operating without rx DMA\n");
if (of_property_read_bool(np, "linux,rs485-enabled-at-boot-time")) {
sport->port.rs485.flags |= SER_RS485_ENABLED;
sport->port.rs485.flags |= SER_RS485_RTS_ON_SEND;
writeb(UARTMODEM_TXRTSE, sport->port.membase + UARTMODEM);
}
return 0;
}
static int lpuart_remove(struct platform_device *pdev)
{
struct lpuart_port *sport = platform_get_drvdata(pdev);
uart_remove_one_port(&lpuart_reg, &sport->port);
clk_disable_unprepare(sport->clk);
if (sport->dma_tx_chan)
dma_release_channel(sport->dma_tx_chan);
if (sport->dma_rx_chan)
dma_release_channel(sport->dma_rx_chan);
return 0;
}
static int lpuart_suspend(struct device *dev)
{
struct lpuart_port *sport = dev_get_drvdata(dev);
unsigned long temp;
if (sport->lpuart32) {
temp = lpuart32_read(sport->port.membase + UARTCTRL);
temp &= ~(UARTCTRL_TE | UARTCTRL_TIE | UARTCTRL_TCIE);
lpuart32_write(temp, sport->port.membase + UARTCTRL);
} else {
temp = readb(sport->port.membase + UARTCR2);
temp &= ~(UARTCR2_TE | UARTCR2_TIE | UARTCR2_TCIE);
writeb(temp, sport->port.membase + UARTCR2);
}
uart_suspend_port(&lpuart_reg, &sport->port);
if (sport->lpuart_dma_rx_use) {
if (sport->port.irq_wake) {
del_timer_sync(&sport->lpuart_timer);
lpuart_dma_rx_free(&sport->port);
}
writeb(readb(sport->port.membase + UARTCR5) & ~UARTCR5_RDMAS,
sport->port.membase + UARTCR5);
}
if (sport->lpuart_dma_tx_use) {
sport->dma_tx_in_progress = false;
dmaengine_terminate_all(sport->dma_tx_chan);
}
if (sport->port.suspended && !sport->port.irq_wake)
clk_disable_unprepare(sport->clk);
return 0;
}
static int lpuart_resume(struct device *dev)
{
struct lpuart_port *sport = dev_get_drvdata(dev);
unsigned long temp;
if (sport->port.suspended && !sport->port.irq_wake)
clk_prepare_enable(sport->clk);
if (sport->lpuart32) {
lpuart32_setup_watermark(sport);
temp = lpuart32_read(sport->port.membase + UARTCTRL);
temp |= (UARTCTRL_RIE | UARTCTRL_TIE | UARTCTRL_RE |
UARTCTRL_TE | UARTCTRL_ILIE);
lpuart32_write(temp, sport->port.membase + UARTCTRL);
} else {
lpuart_setup_watermark(sport);
temp = readb(sport->port.membase + UARTCR2);
temp |= (UARTCR2_RIE | UARTCR2_TIE | UARTCR2_RE | UARTCR2_TE);
writeb(temp, sport->port.membase + UARTCR2);
}
if (sport->lpuart_dma_rx_use) {
if (sport->port.irq_wake) {
if (!lpuart_start_rx_dma(sport))
rx_dma_timer_init(sport);
else
sport->lpuart_dma_rx_use = false;
}
}
if (sport->dma_tx_chan && !lpuart_dma_tx_request(&sport->port)) {
init_waitqueue_head(&sport->dma_wait);
sport->lpuart_dma_tx_use = true;
writeb(readb(sport->port.membase + UARTCR5) |
UARTCR5_TDMAS, sport->port.membase + UARTCR5);
} else {
sport->lpuart_dma_tx_use = false;
}
uart_resume_port(&lpuart_reg, &sport->port);
return 0;
}
static int __init lpuart_serial_init(void)
{
int ret = uart_register_driver(&lpuart_reg);
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
