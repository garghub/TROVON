static inline struct atmel_uart_port *
to_atmel_uart_port(struct uart_port *uart)
{
return container_of(uart, struct atmel_uart_port, uart);
}
static inline u32 atmel_uart_readl(struct uart_port *port, u32 reg)
{
return __raw_readl(port->membase + reg);
}
static inline void atmel_uart_writel(struct uart_port *port, u32 reg, u32 value)
{
__raw_writel(value, port->membase + reg);
}
static inline u8 atmel_uart_read_char(struct uart_port *port)
{
return __raw_readl(port->membase + ATMEL_US_RHR);
}
static inline void atmel_uart_write_char(struct uart_port *port, u8 value)
{
__raw_writel(value, port->membase + ATMEL_US_THR);
}
static inline u8 atmel_uart_read_char(struct uart_port *port)
{
return __raw_readb(port->membase + ATMEL_US_RHR);
}
static inline void atmel_uart_write_char(struct uart_port *port, u8 value)
{
__raw_writeb(value, port->membase + ATMEL_US_THR);
}
static bool atmel_use_pdc_rx(struct uart_port *port)
{
struct atmel_uart_port *atmel_port = to_atmel_uart_port(port);
return atmel_port->use_pdc_rx;
}
static bool atmel_use_pdc_tx(struct uart_port *port)
{
struct atmel_uart_port *atmel_port = to_atmel_uart_port(port);
return atmel_port->use_pdc_tx;
}
static bool atmel_use_pdc_rx(struct uart_port *port)
{
return false;
}
static bool atmel_use_pdc_tx(struct uart_port *port)
{
return false;
}
static bool atmel_use_dma_tx(struct uart_port *port)
{
struct atmel_uart_port *atmel_port = to_atmel_uart_port(port);
return atmel_port->use_dma_tx;
}
static bool atmel_use_dma_rx(struct uart_port *port)
{
struct atmel_uart_port *atmel_port = to_atmel_uart_port(port);
return atmel_port->use_dma_rx;
}
static unsigned int atmel_get_lines_status(struct uart_port *port)
{
struct atmel_uart_port *atmel_port = to_atmel_uart_port(port);
unsigned int status, ret = 0;
status = atmel_uart_readl(port, ATMEL_US_CSR);
mctrl_gpio_get(atmel_port->gpios, &ret);
if (!IS_ERR_OR_NULL(mctrl_gpio_to_gpiod(atmel_port->gpios,
UART_GPIO_CTS))) {
if (ret & TIOCM_CTS)
status &= ~ATMEL_US_CTS;
else
status |= ATMEL_US_CTS;
}
if (!IS_ERR_OR_NULL(mctrl_gpio_to_gpiod(atmel_port->gpios,
UART_GPIO_DSR))) {
if (ret & TIOCM_DSR)
status &= ~ATMEL_US_DSR;
else
status |= ATMEL_US_DSR;
}
if (!IS_ERR_OR_NULL(mctrl_gpio_to_gpiod(atmel_port->gpios,
UART_GPIO_RI))) {
if (ret & TIOCM_RI)
status &= ~ATMEL_US_RI;
else
status |= ATMEL_US_RI;
}
if (!IS_ERR_OR_NULL(mctrl_gpio_to_gpiod(atmel_port->gpios,
UART_GPIO_DCD))) {
if (ret & TIOCM_CD)
status &= ~ATMEL_US_DCD;
else
status |= ATMEL_US_DCD;
}
return status;
}
static int atmel_config_rs485(struct uart_port *port,
struct serial_rs485 *rs485conf)
{
struct atmel_uart_port *atmel_port = to_atmel_uart_port(port);
unsigned int mode;
atmel_uart_writel(port, ATMEL_US_IDR, atmel_port->tx_done_mask);
mode = atmel_uart_readl(port, ATMEL_US_MR);
mode &= ~ATMEL_US_USMODE;
port->rs485 = *rs485conf;
if (rs485conf->flags & SER_RS485_ENABLED) {
dev_dbg(port->dev, "Setting UART to RS485\n");
atmel_port->tx_done_mask = ATMEL_US_TXEMPTY;
atmel_uart_writel(port, ATMEL_US_TTGR,
rs485conf->delay_rts_after_send);
mode |= ATMEL_US_USMODE_RS485;
} else {
dev_dbg(port->dev, "Setting UART to RS232\n");
if (atmel_use_pdc_tx(port))
atmel_port->tx_done_mask = ATMEL_US_ENDTX |
ATMEL_US_TXBUFE;
else
atmel_port->tx_done_mask = ATMEL_US_TXRDY;
}
atmel_uart_writel(port, ATMEL_US_MR, mode);
atmel_uart_writel(port, ATMEL_US_IER, atmel_port->tx_done_mask);
return 0;
}
static u_int atmel_tx_empty(struct uart_port *port)
{
return (atmel_uart_readl(port, ATMEL_US_CSR) & ATMEL_US_TXEMPTY) ?
TIOCSER_TEMT :
0;
}
static void atmel_set_mctrl(struct uart_port *port, u_int mctrl)
{
unsigned int control = 0;
unsigned int mode = atmel_uart_readl(port, ATMEL_US_MR);
unsigned int rts_paused, rts_ready;
struct atmel_uart_port *atmel_port = to_atmel_uart_port(port);
if (port->rs485.flags & SER_RS485_ENABLED) {
atmel_uart_writel(port, ATMEL_US_TTGR,
port->rs485.delay_rts_after_send);
mode &= ~ATMEL_US_USMODE;
mode |= ATMEL_US_USMODE_RS485;
}
if ((mode & ATMEL_US_USMODE) == ATMEL_US_USMODE_HWHS) {
rts_paused = ATMEL_US_RTSEN;
rts_ready = ATMEL_US_RTSDIS;
} else {
rts_paused = ATMEL_US_RTSDIS;
rts_ready = ATMEL_US_RTSEN;
}
if (mctrl & TIOCM_RTS)
control |= rts_ready;
else
control |= rts_paused;
if (mctrl & TIOCM_DTR)
control |= ATMEL_US_DTREN;
else
control |= ATMEL_US_DTRDIS;
atmel_uart_writel(port, ATMEL_US_CR, control);
mctrl_gpio_set(atmel_port->gpios, mctrl);
mode &= ~ATMEL_US_CHMODE;
if (mctrl & TIOCM_LOOP)
mode |= ATMEL_US_CHMODE_LOC_LOOP;
else
mode |= ATMEL_US_CHMODE_NORMAL;
atmel_uart_writel(port, ATMEL_US_MR, mode);
}
static u_int atmel_get_mctrl(struct uart_port *port)
{
struct atmel_uart_port *atmel_port = to_atmel_uart_port(port);
unsigned int ret = 0, status;
status = atmel_uart_readl(port, ATMEL_US_CSR);
if (!(status & ATMEL_US_DCD))
ret |= TIOCM_CD;
if (!(status & ATMEL_US_CTS))
ret |= TIOCM_CTS;
if (!(status & ATMEL_US_DSR))
ret |= TIOCM_DSR;
if (!(status & ATMEL_US_RI))
ret |= TIOCM_RI;
return mctrl_gpio_get(atmel_port->gpios, &ret);
}
static void atmel_stop_tx(struct uart_port *port)
{
struct atmel_uart_port *atmel_port = to_atmel_uart_port(port);
if (atmel_use_pdc_tx(port)) {
atmel_uart_writel(port, ATMEL_PDC_PTCR, ATMEL_PDC_TXTDIS);
}
atmel_uart_writel(port, ATMEL_US_IDR, atmel_port->tx_done_mask);
if ((port->rs485.flags & SER_RS485_ENABLED) &&
!(port->rs485.flags & SER_RS485_RX_DURING_TX))
atmel_start_rx(port);
}
static void atmel_start_tx(struct uart_port *port)
{
struct atmel_uart_port *atmel_port = to_atmel_uart_port(port);
if (atmel_use_pdc_tx(port)) {
if (atmel_uart_readl(port, ATMEL_PDC_PTSR) & ATMEL_PDC_TXTEN)
return;
if ((port->rs485.flags & SER_RS485_ENABLED) &&
!(port->rs485.flags & SER_RS485_RX_DURING_TX))
atmel_stop_rx(port);
atmel_uart_writel(port, ATMEL_PDC_PTCR, ATMEL_PDC_TXTEN);
}
atmel_uart_writel(port, ATMEL_US_IER, atmel_port->tx_done_mask);
}
static void atmel_start_rx(struct uart_port *port)
{
atmel_uart_writel(port, ATMEL_US_CR, ATMEL_US_RSTSTA);
atmel_uart_writel(port, ATMEL_US_CR, ATMEL_US_RXEN);
if (atmel_use_pdc_rx(port)) {
atmel_uart_writel(port, ATMEL_US_IER,
ATMEL_US_ENDRX | ATMEL_US_TIMEOUT |
port->read_status_mask);
atmel_uart_writel(port, ATMEL_PDC_PTCR, ATMEL_PDC_RXTEN);
} else {
atmel_uart_writel(port, ATMEL_US_IER, ATMEL_US_RXRDY);
}
}
static void atmel_stop_rx(struct uart_port *port)
{
atmel_uart_writel(port, ATMEL_US_CR, ATMEL_US_RXDIS);
if (atmel_use_pdc_rx(port)) {
atmel_uart_writel(port, ATMEL_PDC_PTCR, ATMEL_PDC_RXTDIS);
atmel_uart_writel(port, ATMEL_US_IDR,
ATMEL_US_ENDRX | ATMEL_US_TIMEOUT |
port->read_status_mask);
} else {
atmel_uart_writel(port, ATMEL_US_IDR, ATMEL_US_RXRDY);
}
}
static void atmel_enable_ms(struct uart_port *port)
{
struct atmel_uart_port *atmel_port = to_atmel_uart_port(port);
uint32_t ier = 0;
if (atmel_port->ms_irq_enabled)
return;
atmel_port->ms_irq_enabled = true;
if (!mctrl_gpio_to_gpiod(atmel_port->gpios, UART_GPIO_CTS))
ier |= ATMEL_US_CTSIC;
if (!mctrl_gpio_to_gpiod(atmel_port->gpios, UART_GPIO_DSR))
ier |= ATMEL_US_DSRIC;
if (!mctrl_gpio_to_gpiod(atmel_port->gpios, UART_GPIO_RI))
ier |= ATMEL_US_RIIC;
if (!mctrl_gpio_to_gpiod(atmel_port->gpios, UART_GPIO_DCD))
ier |= ATMEL_US_DCDIC;
atmel_uart_writel(port, ATMEL_US_IER, ier);
mctrl_gpio_enable_ms(atmel_port->gpios);
}
static void atmel_disable_ms(struct uart_port *port)
{
struct atmel_uart_port *atmel_port = to_atmel_uart_port(port);
uint32_t idr = 0;
if (!atmel_port->ms_irq_enabled)
return;
atmel_port->ms_irq_enabled = false;
mctrl_gpio_disable_ms(atmel_port->gpios);
if (!mctrl_gpio_to_gpiod(atmel_port->gpios, UART_GPIO_CTS))
idr |= ATMEL_US_CTSIC;
if (!mctrl_gpio_to_gpiod(atmel_port->gpios, UART_GPIO_DSR))
idr |= ATMEL_US_DSRIC;
if (!mctrl_gpio_to_gpiod(atmel_port->gpios, UART_GPIO_RI))
idr |= ATMEL_US_RIIC;
if (!mctrl_gpio_to_gpiod(atmel_port->gpios, UART_GPIO_DCD))
idr |= ATMEL_US_DCDIC;
atmel_uart_writel(port, ATMEL_US_IDR, idr);
}
static void atmel_break_ctl(struct uart_port *port, int break_state)
{
if (break_state != 0)
atmel_uart_writel(port, ATMEL_US_CR, ATMEL_US_STTBRK);
else
atmel_uart_writel(port, ATMEL_US_CR, ATMEL_US_STPBRK);
}
static void
atmel_buffer_rx_char(struct uart_port *port, unsigned int status,
unsigned int ch)
{
struct atmel_uart_port *atmel_port = to_atmel_uart_port(port);
struct circ_buf *ring = &atmel_port->rx_ring;
struct atmel_uart_char *c;
if (!CIRC_SPACE(ring->head, ring->tail, ATMEL_SERIAL_RINGSIZE))
return;
c = &((struct atmel_uart_char *)ring->buf)[ring->head];
c->status = status;
c->ch = ch;
smp_wmb();
ring->head = (ring->head + 1) & (ATMEL_SERIAL_RINGSIZE - 1);
}
static void atmel_pdc_rxerr(struct uart_port *port, unsigned int status)
{
atmel_uart_writel(port, ATMEL_US_CR, ATMEL_US_RSTSTA);
if (status & ATMEL_US_RXBRK) {
status &= ~(ATMEL_US_PARE | ATMEL_US_FRAME);
port->icount.brk++;
}
if (status & ATMEL_US_PARE)
port->icount.parity++;
if (status & ATMEL_US_FRAME)
port->icount.frame++;
if (status & ATMEL_US_OVRE)
port->icount.overrun++;
}
static void atmel_rx_chars(struct uart_port *port)
{
struct atmel_uart_port *atmel_port = to_atmel_uart_port(port);
unsigned int status, ch;
status = atmel_uart_readl(port, ATMEL_US_CSR);
while (status & ATMEL_US_RXRDY) {
ch = atmel_uart_read_char(port);
if (unlikely(status & (ATMEL_US_PARE | ATMEL_US_FRAME
| ATMEL_US_OVRE | ATMEL_US_RXBRK)
|| atmel_port->break_active)) {
atmel_uart_writel(port, ATMEL_US_CR, ATMEL_US_RSTSTA);
if (status & ATMEL_US_RXBRK
&& !atmel_port->break_active) {
atmel_port->break_active = 1;
atmel_uart_writel(port, ATMEL_US_IER,
ATMEL_US_RXBRK);
} else {
atmel_uart_writel(port, ATMEL_US_IDR,
ATMEL_US_RXBRK);
status &= ~ATMEL_US_RXBRK;
atmel_port->break_active = 0;
}
}
atmel_buffer_rx_char(port, status, ch);
status = atmel_uart_readl(port, ATMEL_US_CSR);
}
tasklet_schedule(&atmel_port->tasklet);
}
static void atmel_tx_chars(struct uart_port *port)
{
struct circ_buf *xmit = &port->state->xmit;
struct atmel_uart_port *atmel_port = to_atmel_uart_port(port);
if (port->x_char &&
(atmel_uart_readl(port, ATMEL_US_CSR) & atmel_port->tx_done_mask)) {
atmel_uart_write_char(port, port->x_char);
port->icount.tx++;
port->x_char = 0;
}
if (uart_circ_empty(xmit) || uart_tx_stopped(port))
return;
while (atmel_uart_readl(port, ATMEL_US_CSR) &
atmel_port->tx_done_mask) {
atmel_uart_write_char(port, xmit->buf[xmit->tail]);
xmit->tail = (xmit->tail + 1) & (UART_XMIT_SIZE - 1);
port->icount.tx++;
if (uart_circ_empty(xmit))
break;
}
if (uart_circ_chars_pending(xmit) < WAKEUP_CHARS)
uart_write_wakeup(port);
if (!uart_circ_empty(xmit))
atmel_uart_writel(port, ATMEL_US_IER,
atmel_port->tx_done_mask);
}
static void atmel_complete_tx_dma(void *arg)
{
struct atmel_uart_port *atmel_port = arg;
struct uart_port *port = &atmel_port->uart;
struct circ_buf *xmit = &port->state->xmit;
struct dma_chan *chan = atmel_port->chan_tx;
unsigned long flags;
spin_lock_irqsave(&port->lock, flags);
if (chan)
dmaengine_terminate_all(chan);
xmit->tail += atmel_port->tx_len;
xmit->tail &= UART_XMIT_SIZE - 1;
port->icount.tx += atmel_port->tx_len;
spin_lock_irq(&atmel_port->lock_tx);
async_tx_ack(atmel_port->desc_tx);
atmel_port->cookie_tx = -EINVAL;
atmel_port->desc_tx = NULL;
spin_unlock_irq(&atmel_port->lock_tx);
if (uart_circ_chars_pending(xmit) < WAKEUP_CHARS)
uart_write_wakeup(port);
if (!uart_circ_empty(xmit))
tasklet_schedule(&atmel_port->tasklet);
spin_unlock_irqrestore(&port->lock, flags);
}
static void atmel_release_tx_dma(struct uart_port *port)
{
struct atmel_uart_port *atmel_port = to_atmel_uart_port(port);
struct dma_chan *chan = atmel_port->chan_tx;
if (chan) {
dmaengine_terminate_all(chan);
dma_release_channel(chan);
dma_unmap_sg(port->dev, &atmel_port->sg_tx, 1,
DMA_TO_DEVICE);
}
atmel_port->desc_tx = NULL;
atmel_port->chan_tx = NULL;
atmel_port->cookie_tx = -EINVAL;
}
static void atmel_tx_dma(struct uart_port *port)
{
struct atmel_uart_port *atmel_port = to_atmel_uart_port(port);
struct circ_buf *xmit = &port->state->xmit;
struct dma_chan *chan = atmel_port->chan_tx;
struct dma_async_tx_descriptor *desc;
struct scatterlist sgl[2], *sg, *sg_tx = &atmel_port->sg_tx;
unsigned int tx_len, part1_len, part2_len, sg_len;
dma_addr_t phys_addr;
if (atmel_port->desc_tx != NULL)
return;
if (!uart_circ_empty(xmit) && !uart_tx_stopped(port)) {
tx_len = CIRC_CNT_TO_END(xmit->head,
xmit->tail,
UART_XMIT_SIZE);
if (atmel_port->fifo_size) {
part1_len = (tx_len & ~0x3);
part2_len = (tx_len & 0x3);
} else {
part1_len = 0;
part2_len = tx_len;
}
sg_init_table(sgl, 2);
sg_len = 0;
phys_addr = sg_dma_address(sg_tx) + xmit->tail;
if (part1_len) {
sg = &sgl[sg_len++];
sg_dma_address(sg) = phys_addr;
sg_dma_len(sg) = part1_len;
phys_addr += part1_len;
}
if (part2_len) {
sg = &sgl[sg_len++];
sg_dma_address(sg) = phys_addr;
sg_dma_len(sg) = part2_len;
}
atmel_port->tx_len = tx_len;
desc = dmaengine_prep_slave_sg(chan,
sgl,
sg_len,
DMA_MEM_TO_DEV,
DMA_PREP_INTERRUPT |
DMA_CTRL_ACK);
if (!desc) {
dev_err(port->dev, "Failed to send via dma!\n");
return;
}
dma_sync_sg_for_device(port->dev, sg_tx, 1, DMA_TO_DEVICE);
atmel_port->desc_tx = desc;
desc->callback = atmel_complete_tx_dma;
desc->callback_param = atmel_port;
atmel_port->cookie_tx = dmaengine_submit(desc);
} else {
if (port->rs485.flags & SER_RS485_ENABLED) {
atmel_start_rx(port);
}
}
if (uart_circ_chars_pending(xmit) < WAKEUP_CHARS)
uart_write_wakeup(port);
}
static int atmel_prepare_tx_dma(struct uart_port *port)
{
struct atmel_uart_port *atmel_port = to_atmel_uart_port(port);
dma_cap_mask_t mask;
struct dma_slave_config config;
int ret, nent;
dma_cap_zero(mask);
dma_cap_set(DMA_SLAVE, mask);
atmel_port->chan_tx = dma_request_slave_channel(port->dev, "tx");
if (atmel_port->chan_tx == NULL)
goto chan_err;
dev_info(port->dev, "using %s for tx DMA transfers\n",
dma_chan_name(atmel_port->chan_tx));
spin_lock_init(&atmel_port->lock_tx);
sg_init_table(&atmel_port->sg_tx, 1);
BUG_ON(!PAGE_ALIGNED(port->state->xmit.buf));
sg_set_page(&atmel_port->sg_tx,
virt_to_page(port->state->xmit.buf),
UART_XMIT_SIZE,
(unsigned long)port->state->xmit.buf & ~PAGE_MASK);
nent = dma_map_sg(port->dev,
&atmel_port->sg_tx,
1,
DMA_TO_DEVICE);
if (!nent) {
dev_dbg(port->dev, "need to release resource of dma\n");
goto chan_err;
} else {
dev_dbg(port->dev, "%s: mapped %d@%p to %pad\n", __func__,
sg_dma_len(&atmel_port->sg_tx),
port->state->xmit.buf,
&sg_dma_address(&atmel_port->sg_tx));
}
memset(&config, 0, sizeof(config));
config.direction = DMA_MEM_TO_DEV;
config.dst_addr_width = (atmel_port->fifo_size) ?
DMA_SLAVE_BUSWIDTH_4_BYTES :
DMA_SLAVE_BUSWIDTH_1_BYTE;
config.dst_addr = port->mapbase + ATMEL_US_THR;
config.dst_maxburst = 1;
ret = dmaengine_slave_config(atmel_port->chan_tx,
&config);
if (ret) {
dev_err(port->dev, "DMA tx slave configuration failed\n");
goto chan_err;
}
return 0;
chan_err:
dev_err(port->dev, "TX channel not available, switch to pio\n");
atmel_port->use_dma_tx = 0;
if (atmel_port->chan_tx)
atmel_release_tx_dma(port);
return -EINVAL;
}
static void atmel_complete_rx_dma(void *arg)
{
struct uart_port *port = arg;
struct atmel_uart_port *atmel_port = to_atmel_uart_port(port);
tasklet_schedule(&atmel_port->tasklet);
}
static void atmel_release_rx_dma(struct uart_port *port)
{
struct atmel_uart_port *atmel_port = to_atmel_uart_port(port);
struct dma_chan *chan = atmel_port->chan_rx;
if (chan) {
dmaengine_terminate_all(chan);
dma_release_channel(chan);
dma_unmap_sg(port->dev, &atmel_port->sg_rx, 1,
DMA_FROM_DEVICE);
}
atmel_port->desc_rx = NULL;
atmel_port->chan_rx = NULL;
atmel_port->cookie_rx = -EINVAL;
}
static void atmel_rx_from_dma(struct uart_port *port)
{
struct atmel_uart_port *atmel_port = to_atmel_uart_port(port);
struct tty_port *tport = &port->state->port;
struct circ_buf *ring = &atmel_port->rx_ring;
struct dma_chan *chan = atmel_port->chan_rx;
struct dma_tx_state state;
enum dma_status dmastat;
size_t count;
atmel_uart_writel(port, ATMEL_US_CR, ATMEL_US_STTTO);
dmastat = dmaengine_tx_status(chan,
atmel_port->cookie_rx,
&state);
if (dmastat == DMA_ERROR) {
dev_dbg(port->dev, "Get residue error, restart tasklet\n");
atmel_uart_writel(port, ATMEL_US_IER, ATMEL_US_TIMEOUT);
tasklet_schedule(&atmel_port->tasklet);
return;
}
dma_sync_sg_for_cpu(port->dev,
&atmel_port->sg_rx,
1,
DMA_FROM_DEVICE);
ring->head = sg_dma_len(&atmel_port->sg_rx) - state.residue;
BUG_ON(ring->head > sg_dma_len(&atmel_port->sg_rx));
if (ring->head < ring->tail) {
count = sg_dma_len(&atmel_port->sg_rx) - ring->tail;
tty_insert_flip_string(tport, ring->buf + ring->tail, count);
ring->tail = 0;
port->icount.rx += count;
}
if (ring->tail < ring->head) {
count = ring->head - ring->tail;
tty_insert_flip_string(tport, ring->buf + ring->tail, count);
if (ring->head >= sg_dma_len(&atmel_port->sg_rx))
ring->head = 0;
ring->tail = ring->head;
port->icount.rx += count;
}
dma_sync_sg_for_device(port->dev,
&atmel_port->sg_rx,
1,
DMA_FROM_DEVICE);
spin_unlock(&port->lock);
tty_flip_buffer_push(tport);
spin_lock(&port->lock);
atmel_uart_writel(port, ATMEL_US_IER, ATMEL_US_TIMEOUT);
}
static int atmel_prepare_rx_dma(struct uart_port *port)
{
struct atmel_uart_port *atmel_port = to_atmel_uart_port(port);
struct dma_async_tx_descriptor *desc;
dma_cap_mask_t mask;
struct dma_slave_config config;
struct circ_buf *ring;
int ret, nent;
ring = &atmel_port->rx_ring;
dma_cap_zero(mask);
dma_cap_set(DMA_CYCLIC, mask);
atmel_port->chan_rx = dma_request_slave_channel(port->dev, "rx");
if (atmel_port->chan_rx == NULL)
goto chan_err;
dev_info(port->dev, "using %s for rx DMA transfers\n",
dma_chan_name(atmel_port->chan_rx));
spin_lock_init(&atmel_port->lock_rx);
sg_init_table(&atmel_port->sg_rx, 1);
BUG_ON(!PAGE_ALIGNED(ring->buf));
sg_set_page(&atmel_port->sg_rx,
virt_to_page(ring->buf),
sizeof(struct atmel_uart_char) * ATMEL_SERIAL_RINGSIZE,
(unsigned long)ring->buf & ~PAGE_MASK);
nent = dma_map_sg(port->dev,
&atmel_port->sg_rx,
1,
DMA_FROM_DEVICE);
if (!nent) {
dev_dbg(port->dev, "need to release resource of dma\n");
goto chan_err;
} else {
dev_dbg(port->dev, "%s: mapped %d@%p to %pad\n", __func__,
sg_dma_len(&atmel_port->sg_rx),
ring->buf,
&sg_dma_address(&atmel_port->sg_rx));
}
memset(&config, 0, sizeof(config));
config.direction = DMA_DEV_TO_MEM;
config.src_addr_width = DMA_SLAVE_BUSWIDTH_1_BYTE;
config.src_addr = port->mapbase + ATMEL_US_RHR;
config.src_maxburst = 1;
ret = dmaengine_slave_config(atmel_port->chan_rx,
&config);
if (ret) {
dev_err(port->dev, "DMA rx slave configuration failed\n");
goto chan_err;
}
desc = dmaengine_prep_dma_cyclic(atmel_port->chan_rx,
sg_dma_address(&atmel_port->sg_rx),
sg_dma_len(&atmel_port->sg_rx),
sg_dma_len(&atmel_port->sg_rx)/2,
DMA_DEV_TO_MEM,
DMA_PREP_INTERRUPT);
desc->callback = atmel_complete_rx_dma;
desc->callback_param = port;
atmel_port->desc_rx = desc;
atmel_port->cookie_rx = dmaengine_submit(desc);
return 0;
chan_err:
dev_err(port->dev, "RX channel not available, switch to pio\n");
atmel_port->use_dma_rx = 0;
if (atmel_port->chan_rx)
atmel_release_rx_dma(port);
return -EINVAL;
}
static void atmel_uart_timer_callback(unsigned long data)
{
struct uart_port *port = (void *)data;
struct atmel_uart_port *atmel_port = to_atmel_uart_port(port);
tasklet_schedule(&atmel_port->tasklet);
mod_timer(&atmel_port->uart_timer, jiffies + uart_poll_timeout(port));
}
static void
atmel_handle_receive(struct uart_port *port, unsigned int pending)
{
struct atmel_uart_port *atmel_port = to_atmel_uart_port(port);
if (atmel_use_pdc_rx(port)) {
if (pending & (ATMEL_US_ENDRX | ATMEL_US_TIMEOUT)) {
atmel_uart_writel(port, ATMEL_US_IDR,
(ATMEL_US_ENDRX | ATMEL_US_TIMEOUT));
tasklet_schedule(&atmel_port->tasklet);
}
if (pending & (ATMEL_US_RXBRK | ATMEL_US_OVRE |
ATMEL_US_FRAME | ATMEL_US_PARE))
atmel_pdc_rxerr(port, pending);
}
if (atmel_use_dma_rx(port)) {
if (pending & ATMEL_US_TIMEOUT) {
atmel_uart_writel(port, ATMEL_US_IDR,
ATMEL_US_TIMEOUT);
tasklet_schedule(&atmel_port->tasklet);
}
}
if (pending & ATMEL_US_RXRDY)
atmel_rx_chars(port);
else if (pending & ATMEL_US_RXBRK) {
atmel_uart_writel(port, ATMEL_US_CR, ATMEL_US_RSTSTA);
atmel_uart_writel(port, ATMEL_US_IDR, ATMEL_US_RXBRK);
atmel_port->break_active = 0;
}
}
static void
atmel_handle_transmit(struct uart_port *port, unsigned int pending)
{
struct atmel_uart_port *atmel_port = to_atmel_uart_port(port);
if (pending & atmel_port->tx_done_mask) {
atmel_uart_writel(port, ATMEL_US_IDR,
atmel_port->tx_done_mask);
tasklet_schedule(&atmel_port->tasklet);
}
}
static void
atmel_handle_status(struct uart_port *port, unsigned int pending,
unsigned int status)
{
struct atmel_uart_port *atmel_port = to_atmel_uart_port(port);
if (pending & (ATMEL_US_RIIC | ATMEL_US_DSRIC | ATMEL_US_DCDIC
| ATMEL_US_CTSIC)) {
atmel_port->irq_status = status;
atmel_port->status_change = atmel_port->irq_status ^
atmel_port->irq_status_prev;
atmel_port->irq_status_prev = status;
tasklet_schedule(&atmel_port->tasklet);
}
}
static irqreturn_t atmel_interrupt(int irq, void *dev_id)
{
struct uart_port *port = dev_id;
struct atmel_uart_port *atmel_port = to_atmel_uart_port(port);
unsigned int status, pending, mask, pass_counter = 0;
spin_lock(&atmel_port->lock_suspended);
do {
status = atmel_get_lines_status(port);
mask = atmel_uart_readl(port, ATMEL_US_IMR);
pending = status & mask;
if (!pending)
break;
if (atmel_port->suspended) {
atmel_port->pending |= pending;
atmel_port->pending_status = status;
atmel_uart_writel(port, ATMEL_US_IDR, mask);
pm_system_wakeup();
break;
}
atmel_handle_receive(port, pending);
atmel_handle_status(port, pending, status);
atmel_handle_transmit(port, pending);
} while (pass_counter++ < ATMEL_ISR_PASS_LIMIT);
spin_unlock(&atmel_port->lock_suspended);
return pass_counter ? IRQ_HANDLED : IRQ_NONE;
}
static void atmel_release_tx_pdc(struct uart_port *port)
{
struct atmel_uart_port *atmel_port = to_atmel_uart_port(port);
struct atmel_dma_buffer *pdc = &atmel_port->pdc_tx;
dma_unmap_single(port->dev,
pdc->dma_addr,
pdc->dma_size,
DMA_TO_DEVICE);
}
static void atmel_tx_pdc(struct uart_port *port)
{
struct atmel_uart_port *atmel_port = to_atmel_uart_port(port);
struct circ_buf *xmit = &port->state->xmit;
struct atmel_dma_buffer *pdc = &atmel_port->pdc_tx;
int count;
if (atmel_uart_readl(port, ATMEL_PDC_TCR))
return;
xmit->tail += pdc->ofs;
xmit->tail &= UART_XMIT_SIZE - 1;
port->icount.tx += pdc->ofs;
pdc->ofs = 0;
atmel_uart_writel(port, ATMEL_PDC_PTCR, ATMEL_PDC_TXTDIS);
if (!uart_circ_empty(xmit) && !uart_tx_stopped(port)) {
dma_sync_single_for_device(port->dev,
pdc->dma_addr,
pdc->dma_size,
DMA_TO_DEVICE);
count = CIRC_CNT_TO_END(xmit->head, xmit->tail, UART_XMIT_SIZE);
pdc->ofs = count;
atmel_uart_writel(port, ATMEL_PDC_TPR,
pdc->dma_addr + xmit->tail);
atmel_uart_writel(port, ATMEL_PDC_TCR, count);
atmel_uart_writel(port, ATMEL_PDC_PTCR, ATMEL_PDC_TXTEN);
atmel_uart_writel(port, ATMEL_US_IER,
atmel_port->tx_done_mask);
} else {
if ((port->rs485.flags & SER_RS485_ENABLED) &&
!(port->rs485.flags & SER_RS485_RX_DURING_TX)) {
atmel_start_rx(port);
}
}
if (uart_circ_chars_pending(xmit) < WAKEUP_CHARS)
uart_write_wakeup(port);
}
static int atmel_prepare_tx_pdc(struct uart_port *port)
{
struct atmel_uart_port *atmel_port = to_atmel_uart_port(port);
struct atmel_dma_buffer *pdc = &atmel_port->pdc_tx;
struct circ_buf *xmit = &port->state->xmit;
pdc->buf = xmit->buf;
pdc->dma_addr = dma_map_single(port->dev,
pdc->buf,
UART_XMIT_SIZE,
DMA_TO_DEVICE);
pdc->dma_size = UART_XMIT_SIZE;
pdc->ofs = 0;
return 0;
}
static void atmel_rx_from_ring(struct uart_port *port)
{
struct atmel_uart_port *atmel_port = to_atmel_uart_port(port);
struct circ_buf *ring = &atmel_port->rx_ring;
unsigned int flg;
unsigned int status;
while (ring->head != ring->tail) {
struct atmel_uart_char c;
smp_rmb();
c = ((struct atmel_uart_char *)ring->buf)[ring->tail];
ring->tail = (ring->tail + 1) & (ATMEL_SERIAL_RINGSIZE - 1);
port->icount.rx++;
status = c.status;
flg = TTY_NORMAL;
if (unlikely(status & (ATMEL_US_PARE | ATMEL_US_FRAME
| ATMEL_US_OVRE | ATMEL_US_RXBRK))) {
if (status & ATMEL_US_RXBRK) {
status &= ~(ATMEL_US_PARE | ATMEL_US_FRAME);
port->icount.brk++;
if (uart_handle_break(port))
continue;
}
if (status & ATMEL_US_PARE)
port->icount.parity++;
if (status & ATMEL_US_FRAME)
port->icount.frame++;
if (status & ATMEL_US_OVRE)
port->icount.overrun++;
status &= port->read_status_mask;
if (status & ATMEL_US_RXBRK)
flg = TTY_BREAK;
else if (status & ATMEL_US_PARE)
flg = TTY_PARITY;
else if (status & ATMEL_US_FRAME)
flg = TTY_FRAME;
}
if (uart_handle_sysrq_char(port, c.ch))
continue;
uart_insert_char(port, status, ATMEL_US_OVRE, c.ch, flg);
}
spin_unlock(&port->lock);
tty_flip_buffer_push(&port->state->port);
spin_lock(&port->lock);
}
static void atmel_release_rx_pdc(struct uart_port *port)
{
struct atmel_uart_port *atmel_port = to_atmel_uart_port(port);
int i;
for (i = 0; i < 2; i++) {
struct atmel_dma_buffer *pdc = &atmel_port->pdc_rx[i];
dma_unmap_single(port->dev,
pdc->dma_addr,
pdc->dma_size,
DMA_FROM_DEVICE);
kfree(pdc->buf);
}
}
static void atmel_rx_from_pdc(struct uart_port *port)
{
struct atmel_uart_port *atmel_port = to_atmel_uart_port(port);
struct tty_port *tport = &port->state->port;
struct atmel_dma_buffer *pdc;
int rx_idx = atmel_port->pdc_rx_idx;
unsigned int head;
unsigned int tail;
unsigned int count;
do {
atmel_uart_writel(port, ATMEL_US_CR, ATMEL_US_STTTO);
pdc = &atmel_port->pdc_rx[rx_idx];
head = atmel_uart_readl(port, ATMEL_PDC_RPR) - pdc->dma_addr;
tail = pdc->ofs;
head = min(head, pdc->dma_size);
if (likely(head != tail)) {
dma_sync_single_for_cpu(port->dev, pdc->dma_addr,
pdc->dma_size, DMA_FROM_DEVICE);
count = head - tail;
tty_insert_flip_string(tport, pdc->buf + pdc->ofs,
count);
dma_sync_single_for_device(port->dev, pdc->dma_addr,
pdc->dma_size, DMA_FROM_DEVICE);
port->icount.rx += count;
pdc->ofs = head;
}
if (head >= pdc->dma_size) {
pdc->ofs = 0;
atmel_uart_writel(port, ATMEL_PDC_RNPR, pdc->dma_addr);
atmel_uart_writel(port, ATMEL_PDC_RNCR, pdc->dma_size);
rx_idx = !rx_idx;
atmel_port->pdc_rx_idx = rx_idx;
}
} while (head >= pdc->dma_size);
spin_unlock(&port->lock);
tty_flip_buffer_push(tport);
spin_lock(&port->lock);
atmel_uart_writel(port, ATMEL_US_IER,
ATMEL_US_ENDRX | ATMEL_US_TIMEOUT);
}
static int atmel_prepare_rx_pdc(struct uart_port *port)
{
struct atmel_uart_port *atmel_port = to_atmel_uart_port(port);
int i;
for (i = 0; i < 2; i++) {
struct atmel_dma_buffer *pdc = &atmel_port->pdc_rx[i];
pdc->buf = kmalloc(PDC_BUFFER_SIZE, GFP_KERNEL);
if (pdc->buf == NULL) {
if (i != 0) {
dma_unmap_single(port->dev,
atmel_port->pdc_rx[0].dma_addr,
PDC_BUFFER_SIZE,
DMA_FROM_DEVICE);
kfree(atmel_port->pdc_rx[0].buf);
}
atmel_port->use_pdc_rx = 0;
return -ENOMEM;
}
pdc->dma_addr = dma_map_single(port->dev,
pdc->buf,
PDC_BUFFER_SIZE,
DMA_FROM_DEVICE);
pdc->dma_size = PDC_BUFFER_SIZE;
pdc->ofs = 0;
}
atmel_port->pdc_rx_idx = 0;
atmel_uart_writel(port, ATMEL_PDC_RPR, atmel_port->pdc_rx[0].dma_addr);
atmel_uart_writel(port, ATMEL_PDC_RCR, PDC_BUFFER_SIZE);
atmel_uart_writel(port, ATMEL_PDC_RNPR,
atmel_port->pdc_rx[1].dma_addr);
atmel_uart_writel(port, ATMEL_PDC_RNCR, PDC_BUFFER_SIZE);
return 0;
}
static void atmel_tasklet_func(unsigned long data)
{
struct uart_port *port = (struct uart_port *)data;
struct atmel_uart_port *atmel_port = to_atmel_uart_port(port);
unsigned int status = atmel_port->irq_status;
unsigned int status_change = atmel_port->status_change;
spin_lock(&port->lock);
atmel_port->schedule_tx(port);
if (status_change & (ATMEL_US_RI | ATMEL_US_DSR
| ATMEL_US_DCD | ATMEL_US_CTS)) {
if (status_change & ATMEL_US_RI)
port->icount.rng++;
if (status_change & ATMEL_US_DSR)
port->icount.dsr++;
if (status_change & ATMEL_US_DCD)
uart_handle_dcd_change(port, !(status & ATMEL_US_DCD));
if (status_change & ATMEL_US_CTS)
uart_handle_cts_change(port, !(status & ATMEL_US_CTS));
wake_up_interruptible(&port->state->port.delta_msr_wait);
atmel_port->status_change = 0;
}
atmel_port->schedule_rx(port);
spin_unlock(&port->lock);
}
static void atmel_init_property(struct atmel_uart_port *atmel_port,
struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct atmel_uart_data *pdata = dev_get_platdata(&pdev->dev);
if (np) {
if (of_get_property(np, "atmel,use-dma-rx", NULL)) {
if (of_get_property(np, "dmas", NULL)) {
atmel_port->use_dma_rx = true;
atmel_port->use_pdc_rx = false;
} else {
atmel_port->use_dma_rx = false;
atmel_port->use_pdc_rx = true;
}
} else {
atmel_port->use_dma_rx = false;
atmel_port->use_pdc_rx = false;
}
if (of_get_property(np, "atmel,use-dma-tx", NULL)) {
if (of_get_property(np, "dmas", NULL)) {
atmel_port->use_dma_tx = true;
atmel_port->use_pdc_tx = false;
} else {
atmel_port->use_dma_tx = false;
atmel_port->use_pdc_tx = true;
}
} else {
atmel_port->use_dma_tx = false;
atmel_port->use_pdc_tx = false;
}
} else {
atmel_port->use_pdc_rx = pdata->use_dma_rx;
atmel_port->use_pdc_tx = pdata->use_dma_tx;
atmel_port->use_dma_rx = false;
atmel_port->use_dma_tx = false;
}
}
static void atmel_init_rs485(struct uart_port *port,
struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct atmel_uart_data *pdata = dev_get_platdata(&pdev->dev);
if (np) {
struct serial_rs485 *rs485conf = &port->rs485;
u32 rs485_delay[2];
if (of_property_read_u32_array(np, "rs485-rts-delay",
rs485_delay, 2) == 0) {
rs485conf->delay_rts_before_send = rs485_delay[0];
rs485conf->delay_rts_after_send = rs485_delay[1];
rs485conf->flags = 0;
}
if (of_get_property(np, "rs485-rx-during-tx", NULL))
rs485conf->flags |= SER_RS485_RX_DURING_TX;
if (of_get_property(np, "linux,rs485-enabled-at-boot-time",
NULL))
rs485conf->flags |= SER_RS485_ENABLED;
} else {
port->rs485 = pdata->rs485;
}
}
static void atmel_set_ops(struct uart_port *port)
{
struct atmel_uart_port *atmel_port = to_atmel_uart_port(port);
if (atmel_use_dma_rx(port)) {
atmel_port->prepare_rx = &atmel_prepare_rx_dma;
atmel_port->schedule_rx = &atmel_rx_from_dma;
atmel_port->release_rx = &atmel_release_rx_dma;
} else if (atmel_use_pdc_rx(port)) {
atmel_port->prepare_rx = &atmel_prepare_rx_pdc;
atmel_port->schedule_rx = &atmel_rx_from_pdc;
atmel_port->release_rx = &atmel_release_rx_pdc;
} else {
atmel_port->prepare_rx = NULL;
atmel_port->schedule_rx = &atmel_rx_from_ring;
atmel_port->release_rx = NULL;
}
if (atmel_use_dma_tx(port)) {
atmel_port->prepare_tx = &atmel_prepare_tx_dma;
atmel_port->schedule_tx = &atmel_tx_dma;
atmel_port->release_tx = &atmel_release_tx_dma;
} else if (atmel_use_pdc_tx(port)) {
atmel_port->prepare_tx = &atmel_prepare_tx_pdc;
atmel_port->schedule_tx = &atmel_tx_pdc;
atmel_port->release_tx = &atmel_release_tx_pdc;
} else {
atmel_port->prepare_tx = NULL;
atmel_port->schedule_tx = &atmel_tx_chars;
atmel_port->release_tx = NULL;
}
}
static void atmel_get_ip_name(struct uart_port *port)
{
struct atmel_uart_port *atmel_port = to_atmel_uart_port(port);
int name = atmel_uart_readl(port, ATMEL_US_NAME);
u32 version;
u32 usart, dbgu_uart, new_uart;
usart = 0x55534152;
dbgu_uart = 0x44424755;
new_uart = 0x55415254;
atmel_port->has_hw_timer = false;
if (name == new_uart) {
dev_dbg(port->dev, "Uart with hw timer");
atmel_port->has_hw_timer = true;
atmel_port->rtor = ATMEL_UA_RTOR;
} else if (name == usart) {
dev_dbg(port->dev, "Usart\n");
atmel_port->has_hw_timer = true;
atmel_port->rtor = ATMEL_US_RTOR;
} else if (name == dbgu_uart) {
dev_dbg(port->dev, "Dbgu or uart without hw timer\n");
} else {
version = atmel_uart_readl(port, ATMEL_US_VERSION);
switch (version) {
case 0x302:
case 0x10213:
dev_dbg(port->dev, "This version is usart\n");
atmel_port->has_hw_timer = true;
atmel_port->rtor = ATMEL_US_RTOR;
break;
case 0x203:
case 0x10202:
dev_dbg(port->dev, "This version is uart\n");
break;
default:
dev_err(port->dev, "Not supported ip name nor version, set to uart\n");
}
}
}
static int atmel_startup(struct uart_port *port)
{
struct platform_device *pdev = to_platform_device(port->dev);
struct atmel_uart_port *atmel_port = to_atmel_uart_port(port);
struct tty_struct *tty = port->state->port.tty;
int retval;
atmel_uart_writel(port, ATMEL_US_IDR, -1);
atmel_port->ms_irq_enabled = false;
retval = request_irq(port->irq, atmel_interrupt,
IRQF_SHARED | IRQF_COND_SUSPEND,
tty ? tty->name : "atmel_serial", port);
if (retval) {
dev_err(port->dev, "atmel_startup - Can't get irq\n");
return retval;
}
tasklet_enable(&atmel_port->tasklet);
atmel_init_property(atmel_port, pdev);
atmel_set_ops(port);
if (atmel_port->prepare_rx) {
retval = atmel_port->prepare_rx(port);
if (retval < 0)
atmel_set_ops(port);
}
if (atmel_port->prepare_tx) {
retval = atmel_port->prepare_tx(port);
if (retval < 0)
atmel_set_ops(port);
}
if (atmel_port->fifo_size) {
unsigned int txrdym = ATMEL_US_ONE_DATA;
unsigned int rxrdym = ATMEL_US_ONE_DATA;
unsigned int fmr;
atmel_uart_writel(port, ATMEL_US_CR,
ATMEL_US_FIFOEN |
ATMEL_US_RXFCLR |
ATMEL_US_TXFLCLR);
if (atmel_use_dma_tx(port))
txrdym = ATMEL_US_FOUR_DATA;
fmr = ATMEL_US_TXRDYM(txrdym) | ATMEL_US_RXRDYM(rxrdym);
if (atmel_port->rts_high &&
atmel_port->rts_low)
fmr |= ATMEL_US_FRTSC |
ATMEL_US_RXFTHRES(atmel_port->rts_high) |
ATMEL_US_RXFTHRES2(atmel_port->rts_low);
atmel_uart_writel(port, ATMEL_US_FMR, fmr);
}
atmel_port->irq_status_prev = atmel_get_lines_status(port);
atmel_port->irq_status = atmel_port->irq_status_prev;
atmel_uart_writel(port, ATMEL_US_CR, ATMEL_US_RSTSTA | ATMEL_US_RSTRX);
atmel_uart_writel(port, ATMEL_US_CR, ATMEL_US_TXEN | ATMEL_US_RXEN);
setup_timer(&atmel_port->uart_timer,
atmel_uart_timer_callback,
(unsigned long)port);
if (atmel_use_pdc_rx(port)) {
if (!atmel_port->has_hw_timer) {
mod_timer(&atmel_port->uart_timer,
jiffies + uart_poll_timeout(port));
} else {
atmel_uart_writel(port, atmel_port->rtor,
PDC_RX_TIMEOUT);
atmel_uart_writel(port, ATMEL_US_CR, ATMEL_US_STTTO);
atmel_uart_writel(port, ATMEL_US_IER,
ATMEL_US_ENDRX | ATMEL_US_TIMEOUT);
}
atmel_uart_writel(port, ATMEL_PDC_PTCR, ATMEL_PDC_RXTEN);
} else if (atmel_use_dma_rx(port)) {
if (!atmel_port->has_hw_timer) {
mod_timer(&atmel_port->uart_timer,
jiffies + uart_poll_timeout(port));
} else {
atmel_uart_writel(port, atmel_port->rtor,
PDC_RX_TIMEOUT);
atmel_uart_writel(port, ATMEL_US_CR, ATMEL_US_STTTO);
atmel_uart_writel(port, ATMEL_US_IER,
ATMEL_US_TIMEOUT);
}
} else {
atmel_uart_writel(port, ATMEL_US_IER, ATMEL_US_RXRDY);
}
return 0;
}
static void atmel_flush_buffer(struct uart_port *port)
{
struct atmel_uart_port *atmel_port = to_atmel_uart_port(port);
if (atmel_use_pdc_tx(port)) {
atmel_uart_writel(port, ATMEL_PDC_TCR, 0);
atmel_port->pdc_tx.ofs = 0;
}
}
static void atmel_shutdown(struct uart_port *port)
{
struct atmel_uart_port *atmel_port = to_atmel_uart_port(port);
del_timer_sync(&atmel_port->uart_timer);
tasklet_disable(&atmel_port->tasklet);
tasklet_kill(&atmel_port->tasklet);
atmel_stop_rx(port);
atmel_stop_tx(port);
atmel_uart_writel(port, ATMEL_US_CR, ATMEL_US_RSTSTA);
atmel_uart_writel(port, ATMEL_US_IDR, -1);
if (atmel_port->release_rx)
atmel_port->release_rx(port);
if (atmel_port->release_tx)
atmel_port->release_tx(port);
atmel_port->rx_ring.head = 0;
atmel_port->rx_ring.tail = 0;
free_irq(port->irq, port);
atmel_port->ms_irq_enabled = false;
atmel_flush_buffer(port);
}
static void atmel_serial_pm(struct uart_port *port, unsigned int state,
unsigned int oldstate)
{
struct atmel_uart_port *atmel_port = to_atmel_uart_port(port);
switch (state) {
case 0:
clk_prepare_enable(atmel_port->clk);
atmel_uart_writel(port, ATMEL_US_IER, atmel_port->backup_imr);
break;
case 3:
atmel_port->backup_imr = atmel_uart_readl(port, ATMEL_US_IMR);
atmel_uart_writel(port, ATMEL_US_IDR, -1);
clk_disable_unprepare(atmel_port->clk);
break;
default:
dev_err(port->dev, "atmel_serial: unknown pm %d\n", state);
}
}
static void atmel_set_termios(struct uart_port *port, struct ktermios *termios,
struct ktermios *old)
{
unsigned long flags;
unsigned int old_mode, mode, imr, quot, baud;
mode = old_mode = atmel_uart_readl(port, ATMEL_US_MR);
mode &= ~(ATMEL_US_USCLKS | ATMEL_US_CHRL | ATMEL_US_NBSTOP |
ATMEL_US_PAR | ATMEL_US_USMODE);
baud = uart_get_baud_rate(port, termios, old, 0, port->uartclk / 16);
quot = uart_get_divisor(port, baud);
if (quot > 65535) {
quot /= 8;
mode |= ATMEL_US_USCLKS_MCK_DIV8;
}
switch (termios->c_cflag & CSIZE) {
case CS5:
mode |= ATMEL_US_CHRL_5;
break;
case CS6:
mode |= ATMEL_US_CHRL_6;
break;
case CS7:
mode |= ATMEL_US_CHRL_7;
break;
default:
mode |= ATMEL_US_CHRL_8;
break;
}
if (termios->c_cflag & CSTOPB)
mode |= ATMEL_US_NBSTOP_2;
if (termios->c_cflag & PARENB) {
if (termios->c_cflag & CMSPAR) {
if (termios->c_cflag & PARODD)
mode |= ATMEL_US_PAR_MARK;
else
mode |= ATMEL_US_PAR_SPACE;
} else if (termios->c_cflag & PARODD)
mode |= ATMEL_US_PAR_ODD;
else
mode |= ATMEL_US_PAR_EVEN;
} else
mode |= ATMEL_US_PAR_NONE;
spin_lock_irqsave(&port->lock, flags);
port->read_status_mask = ATMEL_US_OVRE;
if (termios->c_iflag & INPCK)
port->read_status_mask |= (ATMEL_US_FRAME | ATMEL_US_PARE);
if (termios->c_iflag & (IGNBRK | BRKINT | PARMRK))
port->read_status_mask |= ATMEL_US_RXBRK;
if (atmel_use_pdc_rx(port))
atmel_uart_writel(port, ATMEL_US_IER, port->read_status_mask);
port->ignore_status_mask = 0;
if (termios->c_iflag & IGNPAR)
port->ignore_status_mask |= (ATMEL_US_FRAME | ATMEL_US_PARE);
if (termios->c_iflag & IGNBRK) {
port->ignore_status_mask |= ATMEL_US_RXBRK;
if (termios->c_iflag & IGNPAR)
port->ignore_status_mask |= ATMEL_US_OVRE;
}
uart_update_timeout(port, termios->c_cflag, baud);
imr = atmel_uart_readl(port, ATMEL_US_IMR);
atmel_uart_writel(port, ATMEL_US_IDR, -1);
atmel_uart_writel(port, ATMEL_US_CR, ATMEL_US_TXDIS | ATMEL_US_RXDIS);
if (port->rs485.flags & SER_RS485_ENABLED) {
atmel_uart_writel(port, ATMEL_US_TTGR,
port->rs485.delay_rts_after_send);
mode |= ATMEL_US_USMODE_RS485;
} else if (termios->c_cflag & CRTSCTS) {
mode |= ATMEL_US_USMODE_HWHS;
} else {
mode |= ATMEL_US_USMODE_NORMAL;
}
atmel_uart_writel(port, ATMEL_US_MR, mode);
if ((old_mode & ATMEL_US_USMODE) != (mode & ATMEL_US_USMODE)) {
unsigned int rts_state;
if ((mode & ATMEL_US_USMODE) == ATMEL_US_USMODE_HWHS) {
rts_state = ATMEL_US_RTSDIS;
} else {
rts_state = ATMEL_US_RTSEN;
}
atmel_uart_writel(port, ATMEL_US_CR, rts_state);
}
atmel_uart_writel(port, ATMEL_US_BRGR, quot);
atmel_uart_writel(port, ATMEL_US_CR, ATMEL_US_RSTSTA | ATMEL_US_RSTRX);
atmel_uart_writel(port, ATMEL_US_CR, ATMEL_US_TXEN | ATMEL_US_RXEN);
atmel_uart_writel(port, ATMEL_US_IER, imr);
if (UART_ENABLE_MS(port, termios->c_cflag))
atmel_enable_ms(port);
else
atmel_disable_ms(port);
spin_unlock_irqrestore(&port->lock, flags);
}
static void atmel_set_ldisc(struct uart_port *port, struct ktermios *termios)
{
if (termios->c_line == N_PPS) {
port->flags |= UPF_HARDPPS_CD;
spin_lock_irq(&port->lock);
atmel_enable_ms(port);
spin_unlock_irq(&port->lock);
} else {
port->flags &= ~UPF_HARDPPS_CD;
if (!UART_ENABLE_MS(port, termios->c_cflag)) {
spin_lock_irq(&port->lock);
atmel_disable_ms(port);
spin_unlock_irq(&port->lock);
}
}
}
static const char *atmel_type(struct uart_port *port)
{
return (port->type == PORT_ATMEL) ? "ATMEL_SERIAL" : NULL;
}
static void atmel_release_port(struct uart_port *port)
{
struct platform_device *pdev = to_platform_device(port->dev);
int size = pdev->resource[0].end - pdev->resource[0].start + 1;
release_mem_region(port->mapbase, size);
if (port->flags & UPF_IOREMAP) {
iounmap(port->membase);
port->membase = NULL;
}
}
static int atmel_request_port(struct uart_port *port)
{
struct platform_device *pdev = to_platform_device(port->dev);
int size = pdev->resource[0].end - pdev->resource[0].start + 1;
if (!request_mem_region(port->mapbase, size, "atmel_serial"))
return -EBUSY;
if (port->flags & UPF_IOREMAP) {
port->membase = ioremap(port->mapbase, size);
if (port->membase == NULL) {
release_mem_region(port->mapbase, size);
return -ENOMEM;
}
}
return 0;
}
static void atmel_config_port(struct uart_port *port, int flags)
{
if (flags & UART_CONFIG_TYPE) {
port->type = PORT_ATMEL;
atmel_request_port(port);
}
}
static int atmel_verify_port(struct uart_port *port, struct serial_struct *ser)
{
int ret = 0;
if (ser->type != PORT_UNKNOWN && ser->type != PORT_ATMEL)
ret = -EINVAL;
if (port->irq != ser->irq)
ret = -EINVAL;
if (ser->io_type != SERIAL_IO_MEM)
ret = -EINVAL;
if (port->uartclk / 16 != ser->baud_base)
ret = -EINVAL;
if (port->mapbase != (unsigned long)ser->iomem_base)
ret = -EINVAL;
if (port->iobase != ser->port)
ret = -EINVAL;
if (ser->hub6 != 0)
ret = -EINVAL;
return ret;
}
static int atmel_poll_get_char(struct uart_port *port)
{
while (!(atmel_uart_readl(port, ATMEL_US_CSR) & ATMEL_US_RXRDY))
cpu_relax();
return atmel_uart_read_char(port);
}
static void atmel_poll_put_char(struct uart_port *port, unsigned char ch)
{
while (!(atmel_uart_readl(port, ATMEL_US_CSR) & ATMEL_US_TXRDY))
cpu_relax();
atmel_uart_write_char(port, ch);
}
static int atmel_init_port(struct atmel_uart_port *atmel_port,
struct platform_device *pdev)
{
int ret;
struct uart_port *port = &atmel_port->uart;
struct atmel_uart_data *pdata = dev_get_platdata(&pdev->dev);
atmel_init_property(atmel_port, pdev);
atmel_set_ops(port);
atmel_init_rs485(port, pdev);
port->iotype = UPIO_MEM;
port->flags = UPF_BOOT_AUTOCONF;
port->ops = &atmel_pops;
port->fifosize = 1;
port->dev = &pdev->dev;
port->mapbase = pdev->resource[0].start;
port->irq = pdev->resource[1].start;
port->rs485_config = atmel_config_rs485;
tasklet_init(&atmel_port->tasklet, atmel_tasklet_func,
(unsigned long)port);
tasklet_disable(&atmel_port->tasklet);
memset(&atmel_port->rx_ring, 0, sizeof(atmel_port->rx_ring));
if (pdata && pdata->regs) {
port->membase = pdata->regs;
} else {
port->flags |= UPF_IOREMAP;
port->membase = NULL;
}
if (!atmel_port->clk) {
atmel_port->clk = clk_get(&pdev->dev, "usart");
if (IS_ERR(atmel_port->clk)) {
ret = PTR_ERR(atmel_port->clk);
atmel_port->clk = NULL;
return ret;
}
ret = clk_prepare_enable(atmel_port->clk);
if (ret) {
clk_put(atmel_port->clk);
atmel_port->clk = NULL;
return ret;
}
port->uartclk = clk_get_rate(atmel_port->clk);
clk_disable_unprepare(atmel_port->clk);
}
if (port->rs485.flags & SER_RS485_ENABLED)
atmel_port->tx_done_mask = ATMEL_US_TXEMPTY;
else if (atmel_use_pdc_tx(port)) {
port->fifosize = PDC_BUFFER_SIZE;
atmel_port->tx_done_mask = ATMEL_US_ENDTX | ATMEL_US_TXBUFE;
} else {
atmel_port->tx_done_mask = ATMEL_US_TXRDY;
}
return 0;
}
static void atmel_console_putchar(struct uart_port *port, int ch)
{
while (!(atmel_uart_readl(port, ATMEL_US_CSR) & ATMEL_US_TXRDY))
cpu_relax();
atmel_uart_write_char(port, ch);
}
static void atmel_console_write(struct console *co, const char *s, u_int count)
{
struct uart_port *port = &atmel_ports[co->index].uart;
struct atmel_uart_port *atmel_port = to_atmel_uart_port(port);
unsigned int status, imr;
unsigned int pdc_tx;
imr = atmel_uart_readl(port, ATMEL_US_IMR);
atmel_uart_writel(port, ATMEL_US_IDR,
ATMEL_US_RXRDY | atmel_port->tx_done_mask);
pdc_tx = atmel_uart_readl(port, ATMEL_PDC_PTSR) & ATMEL_PDC_TXTEN;
atmel_uart_writel(port, ATMEL_PDC_PTCR, ATMEL_PDC_TXTDIS);
uart_console_write(port, s, count, atmel_console_putchar);
do {
status = atmel_uart_readl(port, ATMEL_US_CSR);
} while (!(status & ATMEL_US_TXRDY));
if (pdc_tx)
atmel_uart_writel(port, ATMEL_PDC_PTCR, ATMEL_PDC_TXTEN);
atmel_uart_writel(port, ATMEL_US_IER, imr);
}
static void __init atmel_console_get_options(struct uart_port *port, int *baud,
int *parity, int *bits)
{
unsigned int mr, quot;
quot = atmel_uart_readl(port, ATMEL_US_BRGR) & ATMEL_US_CD;
if (!quot)
return;
mr = atmel_uart_readl(port, ATMEL_US_MR) & ATMEL_US_CHRL;
if (mr == ATMEL_US_CHRL_8)
*bits = 8;
else
*bits = 7;
mr = atmel_uart_readl(port, ATMEL_US_MR) & ATMEL_US_PAR;
if (mr == ATMEL_US_PAR_EVEN)
*parity = 'e';
else if (mr == ATMEL_US_PAR_ODD)
*parity = 'o';
*baud = port->uartclk / (16 * (quot - 1));
}
static int __init atmel_console_setup(struct console *co, char *options)
{
int ret;
struct uart_port *port = &atmel_ports[co->index].uart;
int baud = 115200;
int bits = 8;
int parity = 'n';
int flow = 'n';
if (port->membase == NULL) {
return -ENODEV;
}
ret = clk_prepare_enable(atmel_ports[co->index].clk);
if (ret)
return ret;
atmel_uart_writel(port, ATMEL_US_IDR, -1);
atmel_uart_writel(port, ATMEL_US_CR, ATMEL_US_RSTSTA | ATMEL_US_RSTRX);
atmel_uart_writel(port, ATMEL_US_CR, ATMEL_US_TXEN | ATMEL_US_RXEN);
if (options)
uart_parse_options(options, &baud, &parity, &bits, &flow);
else
atmel_console_get_options(port, &baud, &parity, &bits);
return uart_set_options(port, co, baud, parity, bits, flow);
}
static int __init atmel_console_init(void)
{
int ret;
if (atmel_default_console_device) {
struct atmel_uart_data *pdata =
dev_get_platdata(&atmel_default_console_device->dev);
int id = pdata->num;
struct atmel_uart_port *atmel_port = &atmel_ports[id];
atmel_port->backup_imr = 0;
atmel_port->uart.line = id;
add_preferred_console(ATMEL_DEVICENAME, id, NULL);
ret = atmel_init_port(atmel_port, atmel_default_console_device);
if (ret)
return ret;
register_console(&atmel_console);
}
return 0;
}
static int __init atmel_late_console_init(void)
{
if (atmel_default_console_device
&& !(atmel_console.flags & CON_ENABLED))
register_console(&atmel_console);
return 0;
}
static inline bool atmel_is_console_port(struct uart_port *port)
{
return port->cons && port->cons->index == port->line;
}
static inline bool atmel_is_console_port(struct uart_port *port)
{
return false;
}
static bool atmel_serial_clk_will_stop(void)
{
#ifdef CONFIG_ARCH_AT91
return at91_suspend_entering_slow_clock();
#else
return false;
#endif
}
static int atmel_serial_suspend(struct platform_device *pdev,
pm_message_t state)
{
struct uart_port *port = platform_get_drvdata(pdev);
struct atmel_uart_port *atmel_port = to_atmel_uart_port(port);
if (atmel_is_console_port(port) && console_suspend_enabled) {
while (!(atmel_uart_readl(port, ATMEL_US_CSR) &
ATMEL_US_TXEMPTY))
cpu_relax();
}
atmel_port->may_wakeup = device_may_wakeup(&pdev->dev);
if (atmel_serial_clk_will_stop()) {
unsigned long flags;
spin_lock_irqsave(&atmel_port->lock_suspended, flags);
atmel_port->suspended = true;
spin_unlock_irqrestore(&atmel_port->lock_suspended, flags);
device_set_wakeup_enable(&pdev->dev, 0);
}
uart_suspend_port(&atmel_uart, port);
return 0;
}
static int atmel_serial_resume(struct platform_device *pdev)
{
struct uart_port *port = platform_get_drvdata(pdev);
struct atmel_uart_port *atmel_port = to_atmel_uart_port(port);
unsigned long flags;
spin_lock_irqsave(&atmel_port->lock_suspended, flags);
if (atmel_port->pending) {
atmel_handle_receive(port, atmel_port->pending);
atmel_handle_status(port, atmel_port->pending,
atmel_port->pending_status);
atmel_handle_transmit(port, atmel_port->pending);
atmel_port->pending = 0;
}
atmel_port->suspended = false;
spin_unlock_irqrestore(&atmel_port->lock_suspended, flags);
uart_resume_port(&atmel_uart, port);
device_set_wakeup_enable(&pdev->dev, atmel_port->may_wakeup);
return 0;
}
static void atmel_serial_probe_fifos(struct atmel_uart_port *atmel_port,
struct platform_device *pdev)
{
atmel_port->fifo_size = 0;
atmel_port->rts_low = 0;
atmel_port->rts_high = 0;
if (of_property_read_u32(pdev->dev.of_node,
"atmel,fifo-size",
&atmel_port->fifo_size))
return;
if (!atmel_port->fifo_size)
return;
if (atmel_port->fifo_size < ATMEL_MIN_FIFO_SIZE) {
atmel_port->fifo_size = 0;
dev_err(&pdev->dev, "Invalid FIFO size\n");
return;
}
atmel_port->rts_high = max_t(int, atmel_port->fifo_size >> 1,
atmel_port->fifo_size - ATMEL_RTS_HIGH_OFFSET);
atmel_port->rts_low = max_t(int, atmel_port->fifo_size >> 2,
atmel_port->fifo_size - ATMEL_RTS_LOW_OFFSET);
dev_info(&pdev->dev, "Using FIFO (%u data)\n",
atmel_port->fifo_size);
dev_dbg(&pdev->dev, "RTS High Threshold : %2u data\n",
atmel_port->rts_high);
dev_dbg(&pdev->dev, "RTS Low Threshold : %2u data\n",
atmel_port->rts_low);
}
static int atmel_serial_probe(struct platform_device *pdev)
{
struct atmel_uart_port *atmel_port;
struct device_node *np = pdev->dev.of_node;
struct atmel_uart_data *pdata = dev_get_platdata(&pdev->dev);
void *data;
int ret = -ENODEV;
bool rs485_enabled;
BUILD_BUG_ON(ATMEL_SERIAL_RINGSIZE & (ATMEL_SERIAL_RINGSIZE - 1));
if (np)
ret = of_alias_get_id(np, "serial");
else
if (pdata)
ret = pdata->num;
if (ret < 0)
ret = find_first_zero_bit(atmel_ports_in_use, ATMEL_MAX_UART);
if (ret >= ATMEL_MAX_UART) {
ret = -ENODEV;
goto err;
}
if (test_and_set_bit(ret, atmel_ports_in_use)) {
ret = -EBUSY;
goto err;
}
atmel_port = &atmel_ports[ret];
atmel_port->backup_imr = 0;
atmel_port->uart.line = ret;
atmel_serial_probe_fifos(atmel_port, pdev);
spin_lock_init(&atmel_port->lock_suspended);
ret = atmel_init_port(atmel_port, pdev);
if (ret)
goto err_clear_bit;
atmel_port->gpios = mctrl_gpio_init(&atmel_port->uart, 0);
if (IS_ERR(atmel_port->gpios)) {
ret = PTR_ERR(atmel_port->gpios);
goto err_clear_bit;
}
if (!atmel_use_pdc_rx(&atmel_port->uart)) {
ret = -ENOMEM;
data = kmalloc(sizeof(struct atmel_uart_char)
* ATMEL_SERIAL_RINGSIZE, GFP_KERNEL);
if (!data)
goto err_alloc_ring;
atmel_port->rx_ring.buf = data;
}
rs485_enabled = atmel_port->uart.rs485.flags & SER_RS485_ENABLED;
ret = uart_add_one_port(&atmel_uart, &atmel_port->uart);
if (ret)
goto err_add_port;
#ifdef CONFIG_SERIAL_ATMEL_CONSOLE
if (atmel_is_console_port(&atmel_port->uart)
&& ATMEL_CONSOLE_DEVICE->flags & CON_ENABLED) {
clk_disable_unprepare(atmel_port->clk);
}
#endif
device_init_wakeup(&pdev->dev, 1);
platform_set_drvdata(pdev, atmel_port);
clk_prepare_enable(atmel_port->clk);
if (rs485_enabled) {
atmel_uart_writel(&atmel_port->uart, ATMEL_US_MR,
ATMEL_US_USMODE_NORMAL);
atmel_uart_writel(&atmel_port->uart, ATMEL_US_CR,
ATMEL_US_RTSEN);
}
atmel_get_ip_name(&atmel_port->uart);
clk_disable_unprepare(atmel_port->clk);
return 0;
err_add_port:
kfree(atmel_port->rx_ring.buf);
atmel_port->rx_ring.buf = NULL;
err_alloc_ring:
if (!atmel_is_console_port(&atmel_port->uart)) {
clk_put(atmel_port->clk);
atmel_port->clk = NULL;
}
err_clear_bit:
clear_bit(atmel_port->uart.line, atmel_ports_in_use);
err:
return ret;
}
static int atmel_serial_remove(struct platform_device *pdev)
{
struct uart_port *port = platform_get_drvdata(pdev);
struct atmel_uart_port *atmel_port = to_atmel_uart_port(port);
int ret = 0;
tasklet_kill(&atmel_port->tasklet);
device_init_wakeup(&pdev->dev, 0);
ret = uart_remove_one_port(&atmel_uart, port);
kfree(atmel_port->rx_ring.buf);
clear_bit(port->line, atmel_ports_in_use);
clk_put(atmel_port->clk);
atmel_port->clk = NULL;
return ret;
}
static int __init atmel_serial_init(void)
{
int ret;
ret = uart_register_driver(&atmel_uart);
if (ret)
return ret;
ret = platform_driver_register(&atmel_serial_driver);
if (ret)
uart_unregister_driver(&atmel_uart);
return ret;
}
