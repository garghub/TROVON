static inline struct sci_port *
to_sci_port(struct uart_port *uart)
{
return container_of(uart, struct sci_port, port);
}
static unsigned int sci_serial_in(struct uart_port *p, int offset)
{
const struct plat_sci_reg *reg = sci_getreg(p, offset);
if (reg->size == 8)
return ioread8(p->membase + (reg->offset << p->regshift));
else if (reg->size == 16)
return ioread16(p->membase + (reg->offset << p->regshift));
else
WARN(1, "Invalid register access\n");
return 0;
}
static void sci_serial_out(struct uart_port *p, int offset, int value)
{
const struct plat_sci_reg *reg = sci_getreg(p, offset);
if (reg->size == 8)
iowrite8(value, p->membase + (reg->offset << p->regshift));
else if (reg->size == 16)
iowrite16(value, p->membase + (reg->offset << p->regshift));
else
WARN(1, "Invalid register access\n");
}
static void sci_port_enable(struct sci_port *sci_port)
{
unsigned int i;
if (!sci_port->port.dev)
return;
pm_runtime_get_sync(sci_port->port.dev);
for (i = 0; i < SCI_NUM_CLKS; i++) {
clk_prepare_enable(sci_port->clks[i]);
sci_port->clk_rates[i] = clk_get_rate(sci_port->clks[i]);
}
sci_port->port.uartclk = sci_port->clk_rates[SCI_FCK];
}
static void sci_port_disable(struct sci_port *sci_port)
{
unsigned int i;
if (!sci_port->port.dev)
return;
for (i = SCI_NUM_CLKS; i-- > 0; )
clk_disable_unprepare(sci_port->clks[i]);
pm_runtime_put_sync(sci_port->port.dev);
}
static inline unsigned long port_rx_irq_mask(struct uart_port *port)
{
return SCSCR_RIE | (to_sci_port(port)->cfg->scscr & SCSCR_REIE);
}
static void sci_start_tx(struct uart_port *port)
{
struct sci_port *s = to_sci_port(port);
unsigned short ctrl;
#ifdef CONFIG_SERIAL_SH_SCI_DMA
if (port->type == PORT_SCIFA || port->type == PORT_SCIFB) {
u16 new, scr = serial_port_in(port, SCSCR);
if (s->chan_tx)
new = scr | SCSCR_TDRQE;
else
new = scr & ~SCSCR_TDRQE;
if (new != scr)
serial_port_out(port, SCSCR, new);
}
if (s->chan_tx && !uart_circ_empty(&s->port.state->xmit) &&
dma_submit_error(s->cookie_tx)) {
s->cookie_tx = 0;
schedule_work(&s->work_tx);
}
#endif
if (!s->chan_tx || port->type == PORT_SCIFA || port->type == PORT_SCIFB) {
ctrl = serial_port_in(port, SCSCR);
serial_port_out(port, SCSCR, ctrl | SCSCR_TIE);
}
}
static void sci_stop_tx(struct uart_port *port)
{
unsigned short ctrl;
ctrl = serial_port_in(port, SCSCR);
if (port->type == PORT_SCIFA || port->type == PORT_SCIFB)
ctrl &= ~SCSCR_TDRQE;
ctrl &= ~SCSCR_TIE;
serial_port_out(port, SCSCR, ctrl);
}
static void sci_start_rx(struct uart_port *port)
{
unsigned short ctrl;
ctrl = serial_port_in(port, SCSCR) | port_rx_irq_mask(port);
if (port->type == PORT_SCIFA || port->type == PORT_SCIFB)
ctrl &= ~SCSCR_RDRQE;
serial_port_out(port, SCSCR, ctrl);
}
static void sci_stop_rx(struct uart_port *port)
{
unsigned short ctrl;
ctrl = serial_port_in(port, SCSCR);
if (port->type == PORT_SCIFA || port->type == PORT_SCIFB)
ctrl &= ~SCSCR_RDRQE;
ctrl &= ~port_rx_irq_mask(port);
serial_port_out(port, SCSCR, ctrl);
}
static void sci_clear_SCxSR(struct uart_port *port, unsigned int mask)
{
if (port->type == PORT_SCI) {
serial_port_out(port, SCxSR, mask);
} else if (to_sci_port(port)->params->overrun_mask == SCIFA_ORER) {
serial_port_out(port, SCxSR,
serial_port_in(port, SCxSR) & mask);
} else {
serial_port_out(port, SCxSR, mask & ~(SCIF_FERC | SCIF_PERC));
}
}
static int sci_poll_get_char(struct uart_port *port)
{
unsigned short status;
int c;
do {
status = serial_port_in(port, SCxSR);
if (status & SCxSR_ERRORS(port)) {
sci_clear_SCxSR(port, SCxSR_ERROR_CLEAR(port));
continue;
}
break;
} while (1);
if (!(status & SCxSR_RDxF(port)))
return NO_POLL_CHAR;
c = serial_port_in(port, SCxRDR);
serial_port_in(port, SCxSR);
sci_clear_SCxSR(port, SCxSR_RDxF_CLEAR(port));
return c;
}
static void sci_poll_put_char(struct uart_port *port, unsigned char c)
{
unsigned short status;
do {
status = serial_port_in(port, SCxSR);
} while (!(status & SCxSR_TDxE(port)));
serial_port_out(port, SCxTDR, c);
sci_clear_SCxSR(port, SCxSR_TDxE_CLEAR(port) & ~SCxSR_TEND(port));
}
static void sci_init_pins(struct uart_port *port, unsigned int cflag)
{
struct sci_port *s = to_sci_port(port);
if (s->cfg->ops && s->cfg->ops->init_pins) {
s->cfg->ops->init_pins(port, cflag);
return;
}
if (port->type == PORT_SCIFA || port->type == PORT_SCIFB) {
u16 ctrl = serial_port_in(port, SCPCR);
ctrl &= ~(SCPCR_RXDC | SCPCR_TXDC);
if (to_sci_port(port)->has_rtscts) {
ctrl |= SCPCR_RTSC;
serial_port_out(port, SCPDR,
serial_port_in(port, SCPDR) | SCPDR_RTSD);
ctrl &= ~SCPCR_CTSC;
}
serial_port_out(port, SCPCR, ctrl);
} else if (sci_getreg(port, SCSPTR)->size) {
u16 status = serial_port_in(port, SCSPTR);
status |= SCSPTR_RTSIO | SCSPTR_RTSDT;
status &= ~(SCSPTR_CTSIO | SCSPTR_SCKIO);
serial_port_out(port, SCSPTR, status);
}
}
static int sci_txfill(struct uart_port *port)
{
struct sci_port *s = to_sci_port(port);
unsigned int fifo_mask = (s->params->fifosize << 1) - 1;
const struct plat_sci_reg *reg;
reg = sci_getreg(port, SCTFDR);
if (reg->size)
return serial_port_in(port, SCTFDR) & fifo_mask;
reg = sci_getreg(port, SCFDR);
if (reg->size)
return serial_port_in(port, SCFDR) >> 8;
return !(serial_port_in(port, SCxSR) & SCI_TDRE);
}
static int sci_txroom(struct uart_port *port)
{
return port->fifosize - sci_txfill(port);
}
static int sci_rxfill(struct uart_port *port)
{
struct sci_port *s = to_sci_port(port);
unsigned int fifo_mask = (s->params->fifosize << 1) - 1;
const struct plat_sci_reg *reg;
reg = sci_getreg(port, SCRFDR);
if (reg->size)
return serial_port_in(port, SCRFDR) & fifo_mask;
reg = sci_getreg(port, SCFDR);
if (reg->size)
return serial_port_in(port, SCFDR) & fifo_mask;
return (serial_port_in(port, SCxSR) & SCxSR_RDxF(port)) != 0;
}
static void sci_transmit_chars(struct uart_port *port)
{
struct circ_buf *xmit = &port->state->xmit;
unsigned int stopped = uart_tx_stopped(port);
unsigned short status;
unsigned short ctrl;
int count;
status = serial_port_in(port, SCxSR);
if (!(status & SCxSR_TDxE(port))) {
ctrl = serial_port_in(port, SCSCR);
if (uart_circ_empty(xmit))
ctrl &= ~SCSCR_TIE;
else
ctrl |= SCSCR_TIE;
serial_port_out(port, SCSCR, ctrl);
return;
}
count = sci_txroom(port);
do {
unsigned char c;
if (port->x_char) {
c = port->x_char;
port->x_char = 0;
} else if (!uart_circ_empty(xmit) && !stopped) {
c = xmit->buf[xmit->tail];
xmit->tail = (xmit->tail + 1) & (UART_XMIT_SIZE - 1);
} else {
break;
}
serial_port_out(port, SCxTDR, c);
port->icount.tx++;
} while (--count > 0);
sci_clear_SCxSR(port, SCxSR_TDxE_CLEAR(port));
if (uart_circ_chars_pending(xmit) < WAKEUP_CHARS)
uart_write_wakeup(port);
if (uart_circ_empty(xmit)) {
sci_stop_tx(port);
} else {
ctrl = serial_port_in(port, SCSCR);
if (port->type != PORT_SCI) {
serial_port_in(port, SCxSR);
sci_clear_SCxSR(port, SCxSR_TDxE_CLEAR(port));
}
ctrl |= SCSCR_TIE;
serial_port_out(port, SCSCR, ctrl);
}
}
static void sci_receive_chars(struct uart_port *port)
{
struct tty_port *tport = &port->state->port;
int i, count, copied = 0;
unsigned short status;
unsigned char flag;
status = serial_port_in(port, SCxSR);
if (!(status & SCxSR_RDxF(port)))
return;
while (1) {
count = tty_buffer_request_room(tport, sci_rxfill(port));
if (count == 0)
break;
if (port->type == PORT_SCI) {
char c = serial_port_in(port, SCxRDR);
if (uart_handle_sysrq_char(port, c))
count = 0;
else
tty_insert_flip_char(tport, c, TTY_NORMAL);
} else {
for (i = 0; i < count; i++) {
char c = serial_port_in(port, SCxRDR);
status = serial_port_in(port, SCxSR);
if (uart_handle_sysrq_char(port, c)) {
count--; i--;
continue;
}
if (status & SCxSR_FER(port)) {
flag = TTY_FRAME;
port->icount.frame++;
dev_notice(port->dev, "frame error\n");
} else if (status & SCxSR_PER(port)) {
flag = TTY_PARITY;
port->icount.parity++;
dev_notice(port->dev, "parity error\n");
} else
flag = TTY_NORMAL;
tty_insert_flip_char(tport, c, flag);
}
}
serial_port_in(port, SCxSR);
sci_clear_SCxSR(port, SCxSR_RDxF_CLEAR(port));
copied += count;
port->icount.rx += count;
}
if (copied) {
tty_flip_buffer_push(tport);
} else {
serial_port_in(port, SCxSR);
sci_clear_SCxSR(port, SCxSR_RDxF_CLEAR(port));
}
}
static int sci_handle_errors(struct uart_port *port)
{
int copied = 0;
unsigned short status = serial_port_in(port, SCxSR);
struct tty_port *tport = &port->state->port;
struct sci_port *s = to_sci_port(port);
if (status & s->params->overrun_mask) {
port->icount.overrun++;
if (tty_insert_flip_char(tport, 0, TTY_OVERRUN))
copied++;
dev_notice(port->dev, "overrun error\n");
}
if (status & SCxSR_FER(port)) {
port->icount.frame++;
if (tty_insert_flip_char(tport, 0, TTY_FRAME))
copied++;
dev_notice(port->dev, "frame error\n");
}
if (status & SCxSR_PER(port)) {
port->icount.parity++;
if (tty_insert_flip_char(tport, 0, TTY_PARITY))
copied++;
dev_notice(port->dev, "parity error\n");
}
if (copied)
tty_flip_buffer_push(tport);
return copied;
}
static int sci_handle_fifo_overrun(struct uart_port *port)
{
struct tty_port *tport = &port->state->port;
struct sci_port *s = to_sci_port(port);
const struct plat_sci_reg *reg;
int copied = 0;
u16 status;
reg = sci_getreg(port, s->params->overrun_reg);
if (!reg->size)
return 0;
status = serial_port_in(port, s->params->overrun_reg);
if (status & s->params->overrun_mask) {
status &= ~s->params->overrun_mask;
serial_port_out(port, s->params->overrun_reg, status);
port->icount.overrun++;
tty_insert_flip_char(tport, 0, TTY_OVERRUN);
tty_flip_buffer_push(tport);
dev_dbg(port->dev, "overrun error\n");
copied++;
}
return copied;
}
static int sci_handle_breaks(struct uart_port *port)
{
int copied = 0;
unsigned short status = serial_port_in(port, SCxSR);
struct tty_port *tport = &port->state->port;
if (uart_handle_break(port))
return 0;
if (status & SCxSR_BRK(port)) {
port->icount.brk++;
if (tty_insert_flip_char(tport, 0, TTY_BREAK))
copied++;
dev_dbg(port->dev, "BREAK detected\n");
}
if (copied)
tty_flip_buffer_push(tport);
copied += sci_handle_fifo_overrun(port);
return copied;
}
static int scif_set_rtrg(struct uart_port *port, int rx_trig)
{
unsigned int bits;
if (rx_trig < 1)
rx_trig = 1;
if (rx_trig >= port->fifosize)
rx_trig = port->fifosize;
if (sci_getreg(port, HSRTRGR)->size) {
serial_port_out(port, HSRTRGR, rx_trig);
return rx_trig;
}
switch (port->type) {
case PORT_SCIF:
if (rx_trig < 4) {
bits = 0;
rx_trig = 1;
} else if (rx_trig < 8) {
bits = SCFCR_RTRG0;
rx_trig = 4;
} else if (rx_trig < 14) {
bits = SCFCR_RTRG1;
rx_trig = 8;
} else {
bits = SCFCR_RTRG0 | SCFCR_RTRG1;
rx_trig = 14;
}
break;
case PORT_SCIFA:
case PORT_SCIFB:
if (rx_trig < 16) {
bits = 0;
rx_trig = 1;
} else if (rx_trig < 32) {
bits = SCFCR_RTRG0;
rx_trig = 16;
} else if (rx_trig < 48) {
bits = SCFCR_RTRG1;
rx_trig = 32;
} else {
bits = SCFCR_RTRG0 | SCFCR_RTRG1;
rx_trig = 48;
}
break;
default:
WARN(1, "unknown FIFO configuration");
return 1;
}
serial_port_out(port, SCFCR,
(serial_port_in(port, SCFCR) &
~(SCFCR_RTRG1 | SCFCR_RTRG0)) | bits);
return rx_trig;
}
static int scif_rtrg_enabled(struct uart_port *port)
{
if (sci_getreg(port, HSRTRGR)->size)
return serial_port_in(port, HSRTRGR) != 0;
else
return (serial_port_in(port, SCFCR) &
(SCFCR_RTRG0 | SCFCR_RTRG1)) != 0;
}
static void rx_fifo_timer_fn(unsigned long arg)
{
struct sci_port *s = (struct sci_port *)arg;
struct uart_port *port = &s->port;
dev_dbg(port->dev, "Rx timed out\n");
scif_set_rtrg(port, 1);
}
static ssize_t rx_trigger_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct uart_port *port = dev_get_drvdata(dev);
struct sci_port *sci = to_sci_port(port);
return sprintf(buf, "%d\n", sci->rx_trigger);
}
static ssize_t rx_trigger_store(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t count)
{
struct uart_port *port = dev_get_drvdata(dev);
struct sci_port *sci = to_sci_port(port);
long r;
if (kstrtol(buf, 0, &r) == -EINVAL)
return -EINVAL;
sci->rx_trigger = scif_set_rtrg(port, r);
if (port->type == PORT_SCIFA || port->type == PORT_SCIFB)
scif_set_rtrg(port, 1);
return count;
}
static ssize_t rx_fifo_timeout_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct uart_port *port = dev_get_drvdata(dev);
struct sci_port *sci = to_sci_port(port);
return sprintf(buf, "%d\n", sci->rx_fifo_timeout);
}
static ssize_t rx_fifo_timeout_store(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t count)
{
struct uart_port *port = dev_get_drvdata(dev);
struct sci_port *sci = to_sci_port(port);
long r;
if (kstrtol(buf, 0, &r) == -EINVAL)
return -EINVAL;
sci->rx_fifo_timeout = r;
scif_set_rtrg(port, 1);
if (r > 0)
setup_timer(&sci->rx_fifo_timer, rx_fifo_timer_fn,
(unsigned long)sci);
return count;
}
static void sci_dma_tx_complete(void *arg)
{
struct sci_port *s = arg;
struct uart_port *port = &s->port;
struct circ_buf *xmit = &port->state->xmit;
unsigned long flags;
dev_dbg(port->dev, "%s(%d)\n", __func__, port->line);
spin_lock_irqsave(&port->lock, flags);
xmit->tail += s->tx_dma_len;
xmit->tail &= UART_XMIT_SIZE - 1;
port->icount.tx += s->tx_dma_len;
if (uart_circ_chars_pending(xmit) < WAKEUP_CHARS)
uart_write_wakeup(port);
if (!uart_circ_empty(xmit)) {
s->cookie_tx = 0;
schedule_work(&s->work_tx);
} else {
s->cookie_tx = -EINVAL;
if (port->type == PORT_SCIFA || port->type == PORT_SCIFB) {
u16 ctrl = serial_port_in(port, SCSCR);
serial_port_out(port, SCSCR, ctrl & ~SCSCR_TIE);
}
}
spin_unlock_irqrestore(&port->lock, flags);
}
static int sci_dma_rx_push(struct sci_port *s, void *buf, size_t count)
{
struct uart_port *port = &s->port;
struct tty_port *tport = &port->state->port;
int copied;
copied = tty_insert_flip_string(tport, buf, count);
if (copied < count)
port->icount.buf_overrun++;
port->icount.rx += copied;
return copied;
}
static int sci_dma_rx_find_active(struct sci_port *s)
{
unsigned int i;
for (i = 0; i < ARRAY_SIZE(s->cookie_rx); i++)
if (s->active_rx == s->cookie_rx[i])
return i;
return -1;
}
static void sci_rx_dma_release(struct sci_port *s, bool enable_pio)
{
struct dma_chan *chan = s->chan_rx;
struct uart_port *port = &s->port;
unsigned long flags;
spin_lock_irqsave(&port->lock, flags);
s->chan_rx = NULL;
s->cookie_rx[0] = s->cookie_rx[1] = -EINVAL;
spin_unlock_irqrestore(&port->lock, flags);
dmaengine_terminate_all(chan);
dma_free_coherent(chan->device->dev, s->buf_len_rx * 2, s->rx_buf[0],
sg_dma_address(&s->sg_rx[0]));
dma_release_channel(chan);
if (enable_pio)
sci_start_rx(port);
}
static void sci_dma_rx_complete(void *arg)
{
struct sci_port *s = arg;
struct dma_chan *chan = s->chan_rx;
struct uart_port *port = &s->port;
struct dma_async_tx_descriptor *desc;
unsigned long flags;
int active, count = 0;
dev_dbg(port->dev, "%s(%d) active cookie %d\n", __func__, port->line,
s->active_rx);
spin_lock_irqsave(&port->lock, flags);
active = sci_dma_rx_find_active(s);
if (active >= 0)
count = sci_dma_rx_push(s, s->rx_buf[active], s->buf_len_rx);
mod_timer(&s->rx_timer, jiffies + s->rx_timeout);
if (count)
tty_flip_buffer_push(&port->state->port);
desc = dmaengine_prep_slave_sg(s->chan_rx, &s->sg_rx[active], 1,
DMA_DEV_TO_MEM,
DMA_PREP_INTERRUPT | DMA_CTRL_ACK);
if (!desc)
goto fail;
desc->callback = sci_dma_rx_complete;
desc->callback_param = s;
s->cookie_rx[active] = dmaengine_submit(desc);
if (dma_submit_error(s->cookie_rx[active]))
goto fail;
s->active_rx = s->cookie_rx[!active];
dma_async_issue_pending(chan);
spin_unlock_irqrestore(&port->lock, flags);
dev_dbg(port->dev, "%s: cookie %d #%d, new active cookie %d\n",
__func__, s->cookie_rx[active], active, s->active_rx);
return;
fail:
spin_unlock_irqrestore(&port->lock, flags);
dev_warn(port->dev, "Failed submitting Rx DMA descriptor\n");
sci_rx_dma_release(s, true);
}
static void sci_tx_dma_release(struct sci_port *s, bool enable_pio)
{
struct dma_chan *chan = s->chan_tx;
struct uart_port *port = &s->port;
unsigned long flags;
spin_lock_irqsave(&port->lock, flags);
s->chan_tx = NULL;
s->cookie_tx = -EINVAL;
spin_unlock_irqrestore(&port->lock, flags);
dmaengine_terminate_all(chan);
dma_unmap_single(chan->device->dev, s->tx_dma_addr, UART_XMIT_SIZE,
DMA_TO_DEVICE);
dma_release_channel(chan);
if (enable_pio)
sci_start_tx(port);
}
static void sci_submit_rx(struct sci_port *s)
{
struct dma_chan *chan = s->chan_rx;
int i;
for (i = 0; i < 2; i++) {
struct scatterlist *sg = &s->sg_rx[i];
struct dma_async_tx_descriptor *desc;
desc = dmaengine_prep_slave_sg(chan,
sg, 1, DMA_DEV_TO_MEM,
DMA_PREP_INTERRUPT | DMA_CTRL_ACK);
if (!desc)
goto fail;
desc->callback = sci_dma_rx_complete;
desc->callback_param = s;
s->cookie_rx[i] = dmaengine_submit(desc);
if (dma_submit_error(s->cookie_rx[i]))
goto fail;
}
s->active_rx = s->cookie_rx[0];
dma_async_issue_pending(chan);
return;
fail:
if (i)
dmaengine_terminate_all(chan);
for (i = 0; i < 2; i++)
s->cookie_rx[i] = -EINVAL;
s->active_rx = -EINVAL;
sci_rx_dma_release(s, true);
}
static void work_fn_tx(struct work_struct *work)
{
struct sci_port *s = container_of(work, struct sci_port, work_tx);
struct dma_async_tx_descriptor *desc;
struct dma_chan *chan = s->chan_tx;
struct uart_port *port = &s->port;
struct circ_buf *xmit = &port->state->xmit;
dma_addr_t buf;
spin_lock_irq(&port->lock);
buf = s->tx_dma_addr + (xmit->tail & (UART_XMIT_SIZE - 1));
s->tx_dma_len = min_t(unsigned int,
CIRC_CNT(xmit->head, xmit->tail, UART_XMIT_SIZE),
CIRC_CNT_TO_END(xmit->head, xmit->tail, UART_XMIT_SIZE));
spin_unlock_irq(&port->lock);
desc = dmaengine_prep_slave_single(chan, buf, s->tx_dma_len,
DMA_MEM_TO_DEV,
DMA_PREP_INTERRUPT | DMA_CTRL_ACK);
if (!desc) {
dev_warn(port->dev, "Failed preparing Tx DMA descriptor\n");
sci_tx_dma_release(s, true);
return;
}
dma_sync_single_for_device(chan->device->dev, buf, s->tx_dma_len,
DMA_TO_DEVICE);
spin_lock_irq(&port->lock);
desc->callback = sci_dma_tx_complete;
desc->callback_param = s;
spin_unlock_irq(&port->lock);
s->cookie_tx = dmaengine_submit(desc);
if (dma_submit_error(s->cookie_tx)) {
dev_warn(port->dev, "Failed submitting Tx DMA descriptor\n");
sci_tx_dma_release(s, true);
return;
}
dev_dbg(port->dev, "%s: %p: %d...%d, cookie %d\n",
__func__, xmit->buf, xmit->tail, xmit->head, s->cookie_tx);
dma_async_issue_pending(chan);
}
static void rx_timer_fn(unsigned long arg)
{
struct sci_port *s = (struct sci_port *)arg;
struct dma_chan *chan = s->chan_rx;
struct uart_port *port = &s->port;
struct dma_tx_state state;
enum dma_status status;
unsigned long flags;
unsigned int read;
int active, count;
u16 scr;
dev_dbg(port->dev, "DMA Rx timed out\n");
spin_lock_irqsave(&port->lock, flags);
active = sci_dma_rx_find_active(s);
if (active < 0) {
spin_unlock_irqrestore(&port->lock, flags);
return;
}
status = dmaengine_tx_status(s->chan_rx, s->active_rx, &state);
if (status == DMA_COMPLETE) {
spin_unlock_irqrestore(&port->lock, flags);
dev_dbg(port->dev, "Cookie %d #%d has already completed\n",
s->active_rx, active);
return;
}
dmaengine_pause(chan);
status = dmaengine_tx_status(s->chan_rx, s->active_rx, &state);
if (status == DMA_COMPLETE) {
spin_unlock_irqrestore(&port->lock, flags);
dev_dbg(port->dev, "Transaction complete after DMA engine was stopped");
return;
}
dmaengine_terminate_all(s->chan_rx);
read = sg_dma_len(&s->sg_rx[active]) - state.residue;
if (read) {
count = sci_dma_rx_push(s, s->rx_buf[active], read);
if (count)
tty_flip_buffer_push(&port->state->port);
}
if (port->type == PORT_SCIFA || port->type == PORT_SCIFB)
sci_submit_rx(s);
scr = serial_port_in(port, SCSCR);
if (port->type == PORT_SCIFA || port->type == PORT_SCIFB) {
scr &= ~SCSCR_RDRQE;
enable_irq(s->irqs[SCIx_RXI_IRQ]);
}
serial_port_out(port, SCSCR, scr | SCSCR_RIE);
spin_unlock_irqrestore(&port->lock, flags);
}
static struct dma_chan *sci_request_dma_chan(struct uart_port *port,
enum dma_transfer_direction dir)
{
struct dma_chan *chan;
struct dma_slave_config cfg;
int ret;
chan = dma_request_slave_channel(port->dev,
dir == DMA_MEM_TO_DEV ? "tx" : "rx");
if (!chan) {
dev_warn(port->dev,
"dma_request_slave_channel_compat failed\n");
return NULL;
}
memset(&cfg, 0, sizeof(cfg));
cfg.direction = dir;
if (dir == DMA_MEM_TO_DEV) {
cfg.dst_addr = port->mapbase +
(sci_getreg(port, SCxTDR)->offset << port->regshift);
cfg.dst_addr_width = DMA_SLAVE_BUSWIDTH_1_BYTE;
} else {
cfg.src_addr = port->mapbase +
(sci_getreg(port, SCxRDR)->offset << port->regshift);
cfg.src_addr_width = DMA_SLAVE_BUSWIDTH_1_BYTE;
}
ret = dmaengine_slave_config(chan, &cfg);
if (ret) {
dev_warn(port->dev, "dmaengine_slave_config failed %d\n", ret);
dma_release_channel(chan);
return NULL;
}
return chan;
}
static void sci_request_dma(struct uart_port *port)
{
struct sci_port *s = to_sci_port(port);
struct dma_chan *chan;
dev_dbg(port->dev, "%s: port %d\n", __func__, port->line);
if (!port->dev->of_node)
return;
s->cookie_tx = -EINVAL;
chan = sci_request_dma_chan(port, DMA_MEM_TO_DEV);
dev_dbg(port->dev, "%s: TX: got channel %p\n", __func__, chan);
if (chan) {
s->chan_tx = chan;
s->tx_dma_addr = dma_map_single(chan->device->dev,
port->state->xmit.buf,
UART_XMIT_SIZE,
DMA_TO_DEVICE);
if (dma_mapping_error(chan->device->dev, s->tx_dma_addr)) {
dev_warn(port->dev, "Failed mapping Tx DMA descriptor\n");
dma_release_channel(chan);
s->chan_tx = NULL;
} else {
dev_dbg(port->dev, "%s: mapped %lu@%p to %pad\n",
__func__, UART_XMIT_SIZE,
port->state->xmit.buf, &s->tx_dma_addr);
}
INIT_WORK(&s->work_tx, work_fn_tx);
}
chan = sci_request_dma_chan(port, DMA_DEV_TO_MEM);
dev_dbg(port->dev, "%s: RX: got channel %p\n", __func__, chan);
if (chan) {
unsigned int i;
dma_addr_t dma;
void *buf;
s->chan_rx = chan;
s->buf_len_rx = 2 * max_t(size_t, 16, port->fifosize);
buf = dma_alloc_coherent(chan->device->dev, s->buf_len_rx * 2,
&dma, GFP_KERNEL);
if (!buf) {
dev_warn(port->dev,
"Failed to allocate Rx dma buffer, using PIO\n");
dma_release_channel(chan);
s->chan_rx = NULL;
return;
}
for (i = 0; i < 2; i++) {
struct scatterlist *sg = &s->sg_rx[i];
sg_init_table(sg, 1);
s->rx_buf[i] = buf;
sg_dma_address(sg) = dma;
sg_dma_len(sg) = s->buf_len_rx;
buf += s->buf_len_rx;
dma += s->buf_len_rx;
}
setup_timer(&s->rx_timer, rx_timer_fn, (unsigned long)s);
if (port->type == PORT_SCIFA || port->type == PORT_SCIFB)
sci_submit_rx(s);
}
}
static void sci_free_dma(struct uart_port *port)
{
struct sci_port *s = to_sci_port(port);
if (s->chan_tx)
sci_tx_dma_release(s, false);
if (s->chan_rx)
sci_rx_dma_release(s, false);
}
static inline void sci_request_dma(struct uart_port *port)
{
}
static inline void sci_free_dma(struct uart_port *port)
{
}
static irqreturn_t sci_rx_interrupt(int irq, void *ptr)
{
struct uart_port *port = ptr;
struct sci_port *s = to_sci_port(port);
#ifdef CONFIG_SERIAL_SH_SCI_DMA
if (s->chan_rx) {
u16 scr = serial_port_in(port, SCSCR);
u16 ssr = serial_port_in(port, SCxSR);
if (port->type == PORT_SCIFA || port->type == PORT_SCIFB) {
disable_irq_nosync(irq);
scr |= SCSCR_RDRQE;
} else {
scr &= ~SCSCR_RIE;
sci_submit_rx(s);
}
serial_port_out(port, SCSCR, scr);
serial_port_out(port, SCxSR,
ssr & ~(SCIF_DR | SCxSR_RDxF(port)));
dev_dbg(port->dev, "Rx IRQ %lu: setup t-out in %u jiffies\n",
jiffies, s->rx_timeout);
mod_timer(&s->rx_timer, jiffies + s->rx_timeout);
return IRQ_HANDLED;
}
#endif
if (s->rx_trigger > 1 && s->rx_fifo_timeout > 0) {
if (!scif_rtrg_enabled(port))
scif_set_rtrg(port, s->rx_trigger);
mod_timer(&s->rx_fifo_timer, jiffies + DIV_ROUND_UP(
s->rx_frame * s->rx_fifo_timeout, 1000));
}
sci_receive_chars(ptr);
return IRQ_HANDLED;
}
static irqreturn_t sci_tx_interrupt(int irq, void *ptr)
{
struct uart_port *port = ptr;
unsigned long flags;
spin_lock_irqsave(&port->lock, flags);
sci_transmit_chars(port);
spin_unlock_irqrestore(&port->lock, flags);
return IRQ_HANDLED;
}
static irqreturn_t sci_er_interrupt(int irq, void *ptr)
{
struct uart_port *port = ptr;
struct sci_port *s = to_sci_port(port);
if (port->type == PORT_SCI) {
if (sci_handle_errors(port)) {
serial_port_in(port, SCxSR);
sci_clear_SCxSR(port, SCxSR_RDxF_CLEAR(port));
}
} else {
sci_handle_fifo_overrun(port);
if (!s->chan_rx)
sci_receive_chars(ptr);
}
sci_clear_SCxSR(port, SCxSR_ERROR_CLEAR(port));
if (!s->chan_tx)
sci_tx_interrupt(irq, ptr);
return IRQ_HANDLED;
}
static irqreturn_t sci_br_interrupt(int irq, void *ptr)
{
struct uart_port *port = ptr;
sci_handle_breaks(port);
sci_clear_SCxSR(port, SCxSR_BREAK_CLEAR(port));
return IRQ_HANDLED;
}
static irqreturn_t sci_mpxed_interrupt(int irq, void *ptr)
{
unsigned short ssr_status, scr_status, err_enabled, orer_status = 0;
struct uart_port *port = ptr;
struct sci_port *s = to_sci_port(port);
irqreturn_t ret = IRQ_NONE;
ssr_status = serial_port_in(port, SCxSR);
scr_status = serial_port_in(port, SCSCR);
if (s->params->overrun_reg == SCxSR)
orer_status = ssr_status;
else if (sci_getreg(port, s->params->overrun_reg)->size)
orer_status = serial_port_in(port, s->params->overrun_reg);
err_enabled = scr_status & port_rx_irq_mask(port);
if ((ssr_status & SCxSR_TDxE(port)) && (scr_status & SCSCR_TIE) &&
!s->chan_tx)
ret = sci_tx_interrupt(irq, ptr);
if (((ssr_status & SCxSR_RDxF(port)) || s->chan_rx) &&
(scr_status & SCSCR_RIE))
ret = sci_rx_interrupt(irq, ptr);
if ((ssr_status & SCxSR_ERRORS(port)) && err_enabled)
ret = sci_er_interrupt(irq, ptr);
if ((ssr_status & SCxSR_BRK(port)) && err_enabled)
ret = sci_br_interrupt(irq, ptr);
if (orer_status & s->params->overrun_mask) {
sci_handle_fifo_overrun(port);
ret = IRQ_HANDLED;
}
return ret;
}
static int sci_request_irq(struct sci_port *port)
{
struct uart_port *up = &port->port;
int i, j, ret = 0;
for (i = j = 0; i < SCIx_NR_IRQS; i++, j++) {
const struct sci_irq_desc *desc;
int irq;
if (SCIx_IRQ_IS_MUXED(port)) {
i = SCIx_MUX_IRQ;
irq = up->irq;
} else {
irq = port->irqs[i];
if (unlikely(irq < 0))
continue;
}
desc = sci_irq_desc + i;
port->irqstr[j] = kasprintf(GFP_KERNEL, "%s:%s",
dev_name(up->dev), desc->desc);
if (!port->irqstr[j]) {
ret = -ENOMEM;
goto out_nomem;
}
ret = request_irq(irq, desc->handler, up->irqflags,
port->irqstr[j], port);
if (unlikely(ret)) {
dev_err(up->dev, "Can't allocate %s IRQ\n", desc->desc);
goto out_noirq;
}
}
return 0;
out_noirq:
while (--i >= 0)
free_irq(port->irqs[i], port);
out_nomem:
while (--j >= 0)
kfree(port->irqstr[j]);
return ret;
}
static void sci_free_irq(struct sci_port *port)
{
int i;
for (i = 0; i < SCIx_NR_IRQS; i++) {
int irq = port->irqs[i];
if (unlikely(irq < 0))
continue;
free_irq(port->irqs[i], port);
kfree(port->irqstr[i]);
if (SCIx_IRQ_IS_MUXED(port)) {
return;
}
}
}
static unsigned int sci_tx_empty(struct uart_port *port)
{
unsigned short status = serial_port_in(port, SCxSR);
unsigned short in_tx_fifo = sci_txfill(port);
return (status & SCxSR_TEND(port)) && !in_tx_fifo ? TIOCSER_TEMT : 0;
}
static void sci_set_rts(struct uart_port *port, bool state)
{
if (port->type == PORT_SCIFA || port->type == PORT_SCIFB) {
u16 data = serial_port_in(port, SCPDR);
if (state)
data &= ~SCPDR_RTSD;
else
data |= SCPDR_RTSD;
serial_port_out(port, SCPDR, data);
serial_port_out(port, SCPCR,
serial_port_in(port, SCPCR) | SCPCR_RTSC);
} else if (sci_getreg(port, SCSPTR)->size) {
u16 ctrl = serial_port_in(port, SCSPTR);
if (state)
ctrl &= ~SCSPTR_RTSDT;
else
ctrl |= SCSPTR_RTSDT;
serial_port_out(port, SCSPTR, ctrl);
}
}
static bool sci_get_cts(struct uart_port *port)
{
if (port->type == PORT_SCIFA || port->type == PORT_SCIFB) {
return !(serial_port_in(port, SCPDR) & SCPDR_CTSD);
} else if (sci_getreg(port, SCSPTR)->size) {
return !(serial_port_in(port, SCSPTR) & SCSPTR_CTSDT);
}
return true;
}
static void sci_set_mctrl(struct uart_port *port, unsigned int mctrl)
{
struct sci_port *s = to_sci_port(port);
if (mctrl & TIOCM_LOOP) {
const struct plat_sci_reg *reg;
reg = sci_getreg(port, SCFCR);
if (reg->size)
serial_port_out(port, SCFCR,
serial_port_in(port, SCFCR) |
SCFCR_LOOP);
}
mctrl_gpio_set(s->gpios, mctrl);
if (!s->has_rtscts)
return;
if (!(mctrl & TIOCM_RTS)) {
serial_port_out(port, SCFCR,
serial_port_in(port, SCFCR) & ~SCFCR_MCE);
sci_set_rts(port, 0);
} else if (s->autorts) {
if (port->type == PORT_SCIFA || port->type == PORT_SCIFB) {
serial_port_out(port, SCPCR,
serial_port_in(port, SCPCR) & ~SCPCR_RTSC);
}
serial_port_out(port, SCFCR,
serial_port_in(port, SCFCR) | SCFCR_MCE);
} else {
sci_set_rts(port, 1);
}
}
static unsigned int sci_get_mctrl(struct uart_port *port)
{
struct sci_port *s = to_sci_port(port);
struct mctrl_gpios *gpios = s->gpios;
unsigned int mctrl = 0;
mctrl_gpio_get(gpios, &mctrl);
if (s->autorts) {
if (sci_get_cts(port))
mctrl |= TIOCM_CTS;
} else if (IS_ERR_OR_NULL(mctrl_gpio_to_gpiod(gpios, UART_GPIO_CTS))) {
mctrl |= TIOCM_CTS;
}
if (IS_ERR_OR_NULL(mctrl_gpio_to_gpiod(gpios, UART_GPIO_DSR)))
mctrl |= TIOCM_DSR;
if (IS_ERR_OR_NULL(mctrl_gpio_to_gpiod(gpios, UART_GPIO_DCD)))
mctrl |= TIOCM_CAR;
return mctrl;
}
static void sci_enable_ms(struct uart_port *port)
{
mctrl_gpio_enable_ms(to_sci_port(port)->gpios);
}
static void sci_break_ctl(struct uart_port *port, int break_state)
{
unsigned short scscr, scsptr;
if (!sci_getreg(port, SCSPTR)->size) {
return;
}
scsptr = serial_port_in(port, SCSPTR);
scscr = serial_port_in(port, SCSCR);
if (break_state == -1) {
scsptr = (scsptr | SCSPTR_SPB2IO) & ~SCSPTR_SPB2DT;
scscr &= ~SCSCR_TE;
} else {
scsptr = (scsptr | SCSPTR_SPB2DT) & ~SCSPTR_SPB2IO;
scscr |= SCSCR_TE;
}
serial_port_out(port, SCSPTR, scsptr);
serial_port_out(port, SCSCR, scscr);
}
static int sci_startup(struct uart_port *port)
{
struct sci_port *s = to_sci_port(port);
int ret;
dev_dbg(port->dev, "%s(%d)\n", __func__, port->line);
ret = sci_request_irq(s);
if (unlikely(ret < 0))
return ret;
sci_request_dma(port);
return 0;
}
static void sci_shutdown(struct uart_port *port)
{
struct sci_port *s = to_sci_port(port);
unsigned long flags;
u16 scr;
dev_dbg(port->dev, "%s(%d)\n", __func__, port->line);
s->autorts = false;
mctrl_gpio_disable_ms(to_sci_port(port)->gpios);
spin_lock_irqsave(&port->lock, flags);
sci_stop_rx(port);
sci_stop_tx(port);
scr = serial_port_in(port, SCSCR);
serial_port_out(port, SCSCR, scr & (SCSCR_CKE1 | SCSCR_CKE0));
spin_unlock_irqrestore(&port->lock, flags);
#ifdef CONFIG_SERIAL_SH_SCI_DMA
if (s->chan_rx) {
dev_dbg(port->dev, "%s(%d) deleting rx_timer\n", __func__,
port->line);
del_timer_sync(&s->rx_timer);
}
#endif
sci_free_dma(port);
sci_free_irq(s);
}
static int sci_sck_calc(struct sci_port *s, unsigned int bps,
unsigned int *srr)
{
unsigned long freq = s->clk_rates[SCI_SCK];
int err, min_err = INT_MAX;
unsigned int sr;
if (s->port.type != PORT_HSCIF)
freq *= 2;
for_each_sr(sr, s) {
err = DIV_ROUND_CLOSEST(freq, sr) - bps;
if (abs(err) >= abs(min_err))
continue;
min_err = err;
*srr = sr - 1;
if (!err)
break;
}
dev_dbg(s->port.dev, "SCK: %u%+d bps using SR %u\n", bps, min_err,
*srr + 1);
return min_err;
}
static int sci_brg_calc(struct sci_port *s, unsigned int bps,
unsigned long freq, unsigned int *dlr,
unsigned int *srr)
{
int err, min_err = INT_MAX;
unsigned int sr, dl;
if (s->port.type != PORT_HSCIF)
freq *= 2;
for_each_sr(sr, s) {
dl = DIV_ROUND_CLOSEST(freq, sr * bps);
dl = clamp(dl, 1U, 65535U);
err = DIV_ROUND_CLOSEST(freq, sr * dl) - bps;
if (abs(err) >= abs(min_err))
continue;
min_err = err;
*dlr = dl;
*srr = sr - 1;
if (!err)
break;
}
dev_dbg(s->port.dev, "BRG: %u%+d bps using DL %u SR %u\n", bps,
min_err, *dlr, *srr + 1);
return min_err;
}
static int sci_scbrr_calc(struct sci_port *s, unsigned int bps,
unsigned int *brr, unsigned int *srr,
unsigned int *cks)
{
unsigned long freq = s->clk_rates[SCI_FCK];
unsigned int sr, br, prediv, scrate, c;
int err, min_err = INT_MAX;
if (s->port.type != PORT_HSCIF)
freq *= 2;
for_each_sr(sr, s) {
for (c = 0; c <= 3; c++) {
prediv = sr * (1 << (2 * c + 1));
if (bps > UINT_MAX / prediv)
break;
scrate = prediv * bps;
br = DIV_ROUND_CLOSEST(freq, scrate);
br = clamp(br, 1U, 256U);
err = DIV_ROUND_CLOSEST(freq, br * prediv) - bps;
if (abs(err) >= abs(min_err))
continue;
min_err = err;
*brr = br - 1;
*srr = sr - 1;
*cks = c;
if (!err)
goto found;
}
}
found:
dev_dbg(s->port.dev, "BRR: %u%+d bps using N %u SR %u cks %u\n", bps,
min_err, *brr, *srr + 1, *cks);
return min_err;
}
static void sci_reset(struct uart_port *port)
{
const struct plat_sci_reg *reg;
unsigned int status;
struct sci_port *s = to_sci_port(port);
do {
status = serial_port_in(port, SCxSR);
} while (!(status & SCxSR_TEND(port)));
serial_port_out(port, SCSCR, 0x00);
reg = sci_getreg(port, SCFCR);
if (reg->size)
serial_port_out(port, SCFCR, SCFCR_RFRST | SCFCR_TFRST);
sci_clear_SCxSR(port,
SCxSR_RDxF_CLEAR(port) & SCxSR_ERROR_CLEAR(port) &
SCxSR_BREAK_CLEAR(port));
if (sci_getreg(port, SCLSR)->size) {
status = serial_port_in(port, SCLSR);
status &= ~(SCLSR_TO | SCLSR_ORER);
serial_port_out(port, SCLSR, status);
}
if (s->rx_trigger > 1) {
if (s->rx_fifo_timeout) {
scif_set_rtrg(port, 1);
setup_timer(&s->rx_fifo_timer, rx_fifo_timer_fn,
(unsigned long)s);
} else {
if (port->type == PORT_SCIFA ||
port->type == PORT_SCIFB)
scif_set_rtrg(port, 1);
else
scif_set_rtrg(port, s->rx_trigger);
}
}
}
static void sci_set_termios(struct uart_port *port, struct ktermios *termios,
struct ktermios *old)
{
unsigned int baud, smr_val = SCSMR_ASYNC, scr_val = 0, i, bits;
unsigned int brr = 255, cks = 0, srr = 15, dl = 0, sccks = 0;
unsigned int brr1 = 255, cks1 = 0, srr1 = 15, dl1 = 0;
struct sci_port *s = to_sci_port(port);
const struct plat_sci_reg *reg;
int min_err = INT_MAX, err;
unsigned long max_freq = 0;
int best_clk = -1;
if ((termios->c_cflag & CSIZE) == CS7)
smr_val |= SCSMR_CHR;
if (termios->c_cflag & PARENB)
smr_val |= SCSMR_PE;
if (termios->c_cflag & PARODD)
smr_val |= SCSMR_PE | SCSMR_ODD;
if (termios->c_cflag & CSTOPB)
smr_val |= SCSMR_STOP;
if (!port->uartclk) {
baud = uart_get_baud_rate(port, termios, old, 0, 115200);
goto done;
}
for (i = 0; i < SCI_NUM_CLKS; i++)
max_freq = max(max_freq, s->clk_rates[i]);
baud = uart_get_baud_rate(port, termios, old, 0, max_freq / min_sr(s));
if (!baud)
goto done;
if (s->clk_rates[SCI_SCK] && port->type != PORT_SCIFA &&
port->type != PORT_SCIFB) {
err = sci_sck_calc(s, baud, &srr1);
if (abs(err) < abs(min_err)) {
best_clk = SCI_SCK;
scr_val = SCSCR_CKE1;
sccks = SCCKS_CKS;
min_err = err;
srr = srr1;
if (!err)
goto done;
}
}
if (s->clk_rates[SCI_SCIF_CLK] && sci_getreg(port, SCDL)->size) {
err = sci_brg_calc(s, baud, s->clk_rates[SCI_SCIF_CLK], &dl1,
&srr1);
if (abs(err) < abs(min_err)) {
best_clk = SCI_SCIF_CLK;
scr_val = SCSCR_CKE1;
sccks = 0;
min_err = err;
dl = dl1;
srr = srr1;
if (!err)
goto done;
}
}
if (s->clk_rates[SCI_BRG_INT] && sci_getreg(port, SCDL)->size) {
err = sci_brg_calc(s, baud, s->clk_rates[SCI_BRG_INT], &dl1,
&srr1);
if (abs(err) < abs(min_err)) {
best_clk = SCI_BRG_INT;
scr_val = SCSCR_CKE1;
sccks = SCCKS_XIN;
min_err = err;
dl = dl1;
srr = srr1;
if (!min_err)
goto done;
}
}
err = sci_scbrr_calc(s, baud, &brr1, &srr1, &cks1);
if (abs(err) < abs(min_err)) {
best_clk = SCI_FCK;
scr_val = 0;
min_err = err;
brr = brr1;
srr = srr1;
cks = cks1;
}
done:
if (best_clk >= 0)
dev_dbg(port->dev, "Using clk %pC for %u%+d bps\n",
s->clks[best_clk], baud, min_err);
sci_port_enable(s);
if (best_clk >= 0 && sci_getreg(port, SCCKS)->size) {
serial_port_out(port, SCDL, dl);
serial_port_out(port, SCCKS, sccks);
}
sci_reset(port);
uart_update_timeout(port, termios->c_cflag, baud);
if (best_clk >= 0) {
if (port->type == PORT_SCIFA || port->type == PORT_SCIFB)
switch (srr + 1) {
case 5: smr_val |= SCSMR_SRC_5; break;
case 7: smr_val |= SCSMR_SRC_7; break;
case 11: smr_val |= SCSMR_SRC_11; break;
case 13: smr_val |= SCSMR_SRC_13; break;
case 16: smr_val |= SCSMR_SRC_16; break;
case 17: smr_val |= SCSMR_SRC_17; break;
case 19: smr_val |= SCSMR_SRC_19; break;
case 27: smr_val |= SCSMR_SRC_27; break;
}
smr_val |= cks;
dev_dbg(port->dev,
"SCR 0x%x SMR 0x%x BRR %u CKS 0x%x DL %u SRR %u\n",
scr_val, smr_val, brr, sccks, dl, srr);
serial_port_out(port, SCSCR, scr_val);
serial_port_out(port, SCSMR, smr_val);
serial_port_out(port, SCBRR, brr);
if (sci_getreg(port, HSSRR)->size)
serial_port_out(port, HSSRR, srr | HSCIF_SRE);
udelay((1000000 + (baud - 1)) / baud);
} else {
scr_val = s->cfg->scscr & (SCSCR_CKE1 | SCSCR_CKE0);
smr_val |= serial_port_in(port, SCSMR) &
(SCSMR_CKEDG | SCSMR_SRC_MASK | SCSMR_CKS);
dev_dbg(port->dev, "SCR 0x%x SMR 0x%x\n", scr_val, smr_val);
serial_port_out(port, SCSCR, scr_val);
serial_port_out(port, SCSMR, smr_val);
}
sci_init_pins(port, termios->c_cflag);
port->status &= ~UPSTAT_AUTOCTS;
s->autorts = false;
reg = sci_getreg(port, SCFCR);
if (reg->size) {
unsigned short ctrl = serial_port_in(port, SCFCR);
if ((port->flags & UPF_HARD_FLOW) &&
(termios->c_cflag & CRTSCTS)) {
port->status |= UPSTAT_AUTOCTS;
s->autorts = true;
}
ctrl &= ~(SCFCR_RFRST | SCFCR_TFRST);
serial_port_out(port, SCFCR, ctrl);
}
scr_val |= SCSCR_RE | SCSCR_TE |
(s->cfg->scscr & ~(SCSCR_CKE1 | SCSCR_CKE0));
dev_dbg(port->dev, "SCSCR 0x%x\n", scr_val);
serial_port_out(port, SCSCR, scr_val);
if ((srr + 1 == 5) &&
(port->type == PORT_SCIFA || port->type == PORT_SCIFB)) {
udelay(DIV_ROUND_UP(10 * 1000000, baud));
}
switch (termios->c_cflag & CSIZE) {
case CS5:
bits = 7;
break;
case CS6:
bits = 8;
break;
case CS7:
bits = 9;
break;
default:
bits = 10;
break;
}
if (termios->c_cflag & CSTOPB)
bits++;
if (termios->c_cflag & PARENB)
bits++;
s->rx_frame = (100 * bits * HZ) / (baud / 10);
#ifdef CONFIG_SERIAL_SH_SCI_DMA
s->rx_timeout = DIV_ROUND_UP(s->buf_len_rx * 2 * s->rx_frame, 1000);
dev_dbg(port->dev, "DMA Rx t-out %ums, tty t-out %u jiffies\n",
s->rx_timeout * 1000 / HZ, port->timeout);
if (s->rx_timeout < msecs_to_jiffies(20))
s->rx_timeout = msecs_to_jiffies(20);
#endif
if ((termios->c_cflag & CREAD) != 0)
sci_start_rx(port);
sci_port_disable(s);
if (UART_ENABLE_MS(port, termios->c_cflag))
sci_enable_ms(port);
}
static void sci_pm(struct uart_port *port, unsigned int state,
unsigned int oldstate)
{
struct sci_port *sci_port = to_sci_port(port);
switch (state) {
case UART_PM_STATE_OFF:
sci_port_disable(sci_port);
break;
default:
sci_port_enable(sci_port);
break;
}
}
static const char *sci_type(struct uart_port *port)
{
switch (port->type) {
case PORT_IRDA:
return "irda";
case PORT_SCI:
return "sci";
case PORT_SCIF:
return "scif";
case PORT_SCIFA:
return "scifa";
case PORT_SCIFB:
return "scifb";
case PORT_HSCIF:
return "hscif";
}
return NULL;
}
static int sci_remap_port(struct uart_port *port)
{
struct sci_port *sport = to_sci_port(port);
if (port->membase)
return 0;
if (port->dev->of_node || (port->flags & UPF_IOREMAP)) {
port->membase = ioremap_nocache(port->mapbase, sport->reg_size);
if (unlikely(!port->membase)) {
dev_err(port->dev, "can't remap port#%d\n", port->line);
return -ENXIO;
}
} else {
port->membase = (void __iomem *)(uintptr_t)port->mapbase;
}
return 0;
}
static void sci_release_port(struct uart_port *port)
{
struct sci_port *sport = to_sci_port(port);
if (port->dev->of_node || (port->flags & UPF_IOREMAP)) {
iounmap(port->membase);
port->membase = NULL;
}
release_mem_region(port->mapbase, sport->reg_size);
}
static int sci_request_port(struct uart_port *port)
{
struct resource *res;
struct sci_port *sport = to_sci_port(port);
int ret;
res = request_mem_region(port->mapbase, sport->reg_size,
dev_name(port->dev));
if (unlikely(res == NULL)) {
dev_err(port->dev, "request_mem_region failed.");
return -EBUSY;
}
ret = sci_remap_port(port);
if (unlikely(ret != 0)) {
release_resource(res);
return ret;
}
return 0;
}
static void sci_config_port(struct uart_port *port, int flags)
{
if (flags & UART_CONFIG_TYPE) {
struct sci_port *sport = to_sci_port(port);
port->type = sport->cfg->type;
sci_request_port(port);
}
}
static int sci_verify_port(struct uart_port *port, struct serial_struct *ser)
{
if (ser->baud_base < 2400)
return -EINVAL;
return 0;
}
static int sci_init_clocks(struct sci_port *sci_port, struct device *dev)
{
const char *clk_names[] = {
[SCI_FCK] = "fck",
[SCI_SCK] = "sck",
[SCI_BRG_INT] = "brg_int",
[SCI_SCIF_CLK] = "scif_clk",
};
struct clk *clk;
unsigned int i;
if (sci_port->cfg->type == PORT_HSCIF)
clk_names[SCI_SCK] = "hsck";
for (i = 0; i < SCI_NUM_CLKS; i++) {
clk = devm_clk_get(dev, clk_names[i]);
if (PTR_ERR(clk) == -EPROBE_DEFER)
return -EPROBE_DEFER;
if (IS_ERR(clk) && i == SCI_FCK) {
clk = devm_clk_get(dev, "sci_ick");
if (PTR_ERR(clk) == -EPROBE_DEFER)
return -EPROBE_DEFER;
if (!IS_ERR(clk))
goto found;
clk = devm_clk_get(dev, "peripheral_clk");
if (!IS_ERR(clk))
goto found;
dev_err(dev, "failed to get %s (%ld)\n", clk_names[i],
PTR_ERR(clk));
return PTR_ERR(clk);
}
found:
if (IS_ERR(clk))
dev_dbg(dev, "failed to get %s (%ld)\n", clk_names[i],
PTR_ERR(clk));
else
dev_dbg(dev, "clk %s is %pC rate %pCr\n", clk_names[i],
clk, clk);
sci_port->clks[i] = IS_ERR(clk) ? NULL : clk;
}
return 0;
}
static const struct sci_port_params *
sci_probe_regmap(const struct plat_sci_port *cfg)
{
unsigned int regtype;
if (cfg->regtype != SCIx_PROBE_REGTYPE)
return &sci_port_params[cfg->regtype];
switch (cfg->type) {
case PORT_SCI:
regtype = SCIx_SCI_REGTYPE;
break;
case PORT_IRDA:
regtype = SCIx_IRDA_REGTYPE;
break;
case PORT_SCIFA:
regtype = SCIx_SCIFA_REGTYPE;
break;
case PORT_SCIFB:
regtype = SCIx_SCIFB_REGTYPE;
break;
case PORT_SCIF:
regtype = SCIx_SH4_SCIF_REGTYPE;
break;
case PORT_HSCIF:
regtype = SCIx_HSCIF_REGTYPE;
break;
default:
pr_err("Can't probe register map for given port\n");
return NULL;
}
return &sci_port_params[regtype];
}
static int sci_init_single(struct platform_device *dev,
struct sci_port *sci_port, unsigned int index,
const struct plat_sci_port *p, bool early)
{
struct uart_port *port = &sci_port->port;
const struct resource *res;
unsigned int i;
int ret;
sci_port->cfg = p;
port->ops = &sci_uart_ops;
port->iotype = UPIO_MEM;
port->line = index;
res = platform_get_resource(dev, IORESOURCE_MEM, 0);
if (res == NULL)
return -ENOMEM;
port->mapbase = res->start;
sci_port->reg_size = resource_size(res);
for (i = 0; i < ARRAY_SIZE(sci_port->irqs); ++i)
sci_port->irqs[i] = platform_get_irq(dev, i);
if (sci_port->irqs[0] < 0)
return -ENXIO;
if (sci_port->irqs[1] < 0) {
sci_port->irqs[1] = sci_port->irqs[0];
sci_port->irqs[2] = sci_port->irqs[0];
sci_port->irqs[3] = sci_port->irqs[0];
}
sci_port->params = sci_probe_regmap(p);
if (unlikely(sci_port->params == NULL))
return -EINVAL;
switch (p->type) {
case PORT_SCIFB:
sci_port->rx_trigger = 48;
break;
case PORT_HSCIF:
sci_port->rx_trigger = 64;
break;
case PORT_SCIFA:
sci_port->rx_trigger = 32;
break;
case PORT_SCIF:
if (p->regtype == SCIx_SH7705_SCIF_REGTYPE)
sci_port->rx_trigger = 1;
else
sci_port->rx_trigger = 8;
break;
default:
sci_port->rx_trigger = 1;
break;
}
sci_port->rx_fifo_timeout = 0;
sci_port->sampling_rate_mask = p->sampling_rate
? SCI_SR(p->sampling_rate)
: sci_port->params->sampling_rate_mask;
if (!early) {
ret = sci_init_clocks(sci_port, &dev->dev);
if (ret < 0)
return ret;
port->dev = &dev->dev;
pm_runtime_enable(&dev->dev);
}
port->type = p->type;
port->flags = UPF_FIXED_PORT | UPF_BOOT_AUTOCONF | p->flags;
port->fifosize = sci_port->params->fifosize;
if (port->type == PORT_SCI) {
if (sci_port->reg_size >= 0x20)
port->regshift = 2;
else
port->regshift = 1;
}
port->irq = sci_port->irqs[SCIx_RXI_IRQ];
port->irqflags = 0;
port->serial_in = sci_serial_in;
port->serial_out = sci_serial_out;
return 0;
}
static void sci_cleanup_single(struct sci_port *port)
{
pm_runtime_disable(port->port.dev);
}
static void serial_console_putchar(struct uart_port *port, int ch)
{
sci_poll_put_char(port, ch);
}
static void serial_console_write(struct console *co, const char *s,
unsigned count)
{
struct sci_port *sci_port = &sci_ports[co->index];
struct uart_port *port = &sci_port->port;
unsigned short bits, ctrl, ctrl_temp;
unsigned long flags;
int locked = 1;
local_irq_save(flags);
#if defined(SUPPORT_SYSRQ)
if (port->sysrq)
locked = 0;
else
#endif
if (oops_in_progress)
locked = spin_trylock(&port->lock);
else
spin_lock(&port->lock);
ctrl = serial_port_in(port, SCSCR);
ctrl_temp = SCSCR_RE | SCSCR_TE |
(sci_port->cfg->scscr & ~(SCSCR_CKE1 | SCSCR_CKE0)) |
(ctrl & (SCSCR_CKE1 | SCSCR_CKE0));
serial_port_out(port, SCSCR, ctrl_temp);
uart_console_write(port, s, count, serial_console_putchar);
bits = SCxSR_TDxE(port) | SCxSR_TEND(port);
while ((serial_port_in(port, SCxSR) & bits) != bits)
cpu_relax();
serial_port_out(port, SCSCR, ctrl);
if (locked)
spin_unlock(&port->lock);
local_irq_restore(flags);
}
static int serial_console_setup(struct console *co, char *options)
{
struct sci_port *sci_port;
struct uart_port *port;
int baud = 115200;
int bits = 8;
int parity = 'n';
int flow = 'n';
int ret;
if (co->index < 0 || co->index >= SCI_NPORTS)
return -ENODEV;
sci_port = &sci_ports[co->index];
port = &sci_port->port;
if (!port->ops)
return -ENODEV;
ret = sci_remap_port(port);
if (unlikely(ret != 0))
return ret;
if (options)
uart_parse_options(options, &baud, &parity, &bits, &flow);
return uart_set_options(port, co, baud, parity, bits, flow);
}
static int sci_probe_earlyprintk(struct platform_device *pdev)
{
const struct plat_sci_port *cfg = dev_get_platdata(&pdev->dev);
if (early_serial_console.data)
return -EEXIST;
early_serial_console.index = pdev->id;
sci_init_single(pdev, &sci_ports[pdev->id], pdev->id, cfg, true);
serial_console_setup(&early_serial_console, early_serial_buf);
if (!strstr(early_serial_buf, "keep"))
early_serial_console.flags |= CON_BOOT;
register_console(&early_serial_console);
return 0;
}
static inline int sci_probe_earlyprintk(struct platform_device *pdev)
{
return -EINVAL;
}
static int sci_remove(struct platform_device *dev)
{
struct sci_port *port = platform_get_drvdata(dev);
uart_remove_one_port(&sci_uart_driver, &port->port);
sci_cleanup_single(port);
if (port->port.fifosize > 1) {
sysfs_remove_file(&dev->dev.kobj,
&dev_attr_rx_fifo_trigger.attr);
}
if (port->port.type == PORT_SCIFA || port->port.type == PORT_SCIFB) {
sysfs_remove_file(&dev->dev.kobj,
&dev_attr_rx_fifo_timeout.attr);
}
return 0;
}
static struct plat_sci_port *sci_parse_dt(struct platform_device *pdev,
unsigned int *dev_id)
{
struct device_node *np = pdev->dev.of_node;
const struct of_device_id *match;
struct plat_sci_port *p;
struct sci_port *sp;
int id;
if (!IS_ENABLED(CONFIG_OF) || !np)
return NULL;
match = of_match_node(of_sci_match, np);
if (!match)
return NULL;
p = devm_kzalloc(&pdev->dev, sizeof(struct plat_sci_port), GFP_KERNEL);
if (!p)
return NULL;
id = of_alias_get_id(np, "serial");
if (id < 0) {
dev_err(&pdev->dev, "failed to get alias id (%d)\n", id);
return NULL;
}
sp = &sci_ports[id];
*dev_id = id;
p->type = SCI_OF_TYPE(match->data);
p->regtype = SCI_OF_REGTYPE(match->data);
if (of_find_property(np, "uart-has-rtscts", NULL))
sp->has_rtscts = true;
return p;
}
static int sci_probe_single(struct platform_device *dev,
unsigned int index,
struct plat_sci_port *p,
struct sci_port *sciport)
{
int ret;
if (unlikely(index >= SCI_NPORTS)) {
dev_notice(&dev->dev, "Attempting to register port %d when only %d are available\n",
index+1, SCI_NPORTS);
dev_notice(&dev->dev, "Consider bumping CONFIG_SERIAL_SH_SCI_NR_UARTS!\n");
return -EINVAL;
}
ret = sci_init_single(dev, sciport, index, p, false);
if (ret)
return ret;
sciport->gpios = mctrl_gpio_init(&sciport->port, 0);
if (IS_ERR(sciport->gpios) && PTR_ERR(sciport->gpios) != -ENOSYS)
return PTR_ERR(sciport->gpios);
if (sciport->has_rtscts) {
if (!IS_ERR_OR_NULL(mctrl_gpio_to_gpiod(sciport->gpios,
UART_GPIO_CTS)) ||
!IS_ERR_OR_NULL(mctrl_gpio_to_gpiod(sciport->gpios,
UART_GPIO_RTS))) {
dev_err(&dev->dev, "Conflicting RTS/CTS config\n");
return -EINVAL;
}
sciport->port.flags |= UPF_HARD_FLOW;
}
ret = uart_add_one_port(&sci_uart_driver, &sciport->port);
if (ret) {
sci_cleanup_single(sciport);
return ret;
}
return 0;
}
static int sci_probe(struct platform_device *dev)
{
struct plat_sci_port *p;
struct sci_port *sp;
unsigned int dev_id;
int ret;
if (is_early_platform_device(dev))
return sci_probe_earlyprintk(dev);
if (dev->dev.of_node) {
p = sci_parse_dt(dev, &dev_id);
if (p == NULL)
return -EINVAL;
} else {
p = dev->dev.platform_data;
if (p == NULL) {
dev_err(&dev->dev, "no platform data supplied\n");
return -EINVAL;
}
dev_id = dev->id;
}
sp = &sci_ports[dev_id];
platform_set_drvdata(dev, sp);
ret = sci_probe_single(dev, dev_id, p, sp);
if (ret)
return ret;
if (sp->port.fifosize > 1) {
ret = sysfs_create_file(&dev->dev.kobj,
&dev_attr_rx_fifo_trigger.attr);
if (ret)
return ret;
}
if (sp->port.type == PORT_SCIFA || sp->port.type == PORT_SCIFB) {
ret = sysfs_create_file(&dev->dev.kobj,
&dev_attr_rx_fifo_timeout.attr);
if (ret) {
if (sp->port.fifosize > 1) {
sysfs_remove_file(&dev->dev.kobj,
&dev_attr_rx_fifo_trigger.attr);
}
return ret;
}
}
#ifdef CONFIG_SH_STANDARD_BIOS
sh_bios_gdb_detach();
#endif
return 0;
}
static __maybe_unused int sci_suspend(struct device *dev)
{
struct sci_port *sport = dev_get_drvdata(dev);
if (sport)
uart_suspend_port(&sci_uart_driver, &sport->port);
return 0;
}
static __maybe_unused int sci_resume(struct device *dev)
{
struct sci_port *sport = dev_get_drvdata(dev);
if (sport)
uart_resume_port(&sci_uart_driver, &sport->port);
return 0;
}
static int __init sci_init(void)
{
int ret;
pr_info("%s\n", banner);
ret = uart_register_driver(&sci_uart_driver);
if (likely(ret == 0)) {
ret = platform_driver_register(&sci_driver);
if (unlikely(ret))
uart_unregister_driver(&sci_uart_driver);
}
return ret;
}
static void __exit sci_exit(void)
{
platform_driver_unregister(&sci_driver);
uart_unregister_driver(&sci_uart_driver);
}
static int __init early_console_setup(struct earlycon_device *device,
int type)
{
if (!device->port.membase)
return -ENODEV;
device->port.serial_in = sci_serial_in;
device->port.serial_out = sci_serial_out;
device->port.type = type;
memcpy(&sci_ports[0].port, &device->port, sizeof(struct uart_port));
port_cfg.type = type;
sci_ports[0].cfg = &port_cfg;
sci_ports[0].params = sci_probe_regmap(&port_cfg);
port_cfg.scscr = sci_serial_in(&sci_ports[0].port, SCSCR);
sci_serial_out(&sci_ports[0].port, SCSCR,
SCSCR_RE | SCSCR_TE | port_cfg.scscr);
device->con->write = serial_console_write;
return 0;
}
static int __init sci_early_console_setup(struct earlycon_device *device,
const char *opt)
{
return early_console_setup(device, PORT_SCI);
}
static int __init scif_early_console_setup(struct earlycon_device *device,
const char *opt)
{
return early_console_setup(device, PORT_SCIF);
}
static int __init scifa_early_console_setup(struct earlycon_device *device,
const char *opt)
{
return early_console_setup(device, PORT_SCIFA);
}
static int __init scifb_early_console_setup(struct earlycon_device *device,
const char *opt)
{
return early_console_setup(device, PORT_SCIFB);
}
static int __init hscif_early_console_setup(struct earlycon_device *device,
const char *opt)
{
return early_console_setup(device, PORT_HSCIF);
}
