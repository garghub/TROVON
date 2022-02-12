static inline struct sci_port *
to_sci_port(struct uart_port *uart)
{
return container_of(uart, struct sci_port, port);
}
static int sci_poll_get_char(struct uart_port *port)
{
unsigned short status;
int c;
do {
status = sci_in(port, SCxSR);
if (status & SCxSR_ERRORS(port)) {
sci_out(port, SCxSR, SCxSR_ERROR_CLEAR(port));
continue;
}
break;
} while (1);
if (!(status & SCxSR_RDxF(port)))
return NO_POLL_CHAR;
c = sci_in(port, SCxRDR);
sci_in(port, SCxSR);
sci_out(port, SCxSR, SCxSR_RDxF_CLEAR(port));
return c;
}
static void sci_poll_put_char(struct uart_port *port, unsigned char c)
{
unsigned short status;
do {
status = sci_in(port, SCxSR);
} while (!(status & SCxSR_TDxE(port)));
sci_out(port, SCxTDR, c);
sci_out(port, SCxSR, SCxSR_TDxE_CLEAR(port) & ~SCxSR_TEND(port));
}
static void sci_init_pins(struct uart_port *port, unsigned int cflag)
{
int ch = (port->mapbase - SMR0) >> 3;
H8300_GPIO_DDR(h8300_sci_pins[ch].port,
h8300_sci_pins[ch].rx,
H8300_GPIO_INPUT);
H8300_GPIO_DDR(h8300_sci_pins[ch].port,
h8300_sci_pins[ch].tx,
H8300_GPIO_OUTPUT);
H8300_SCI_DR(ch) |= h8300_sci_pins[ch].tx;
}
static inline void sci_init_pins(struct uart_port *port, unsigned int cflag)
{
if (port->mapbase == 0xA4400000) {
__raw_writew(__raw_readw(PACR) & 0xffc0, PACR);
__raw_writew(__raw_readw(PBCR) & 0x0fff, PBCR);
} else if (port->mapbase == 0xA4410000)
__raw_writew(__raw_readw(PBCR) & 0xf003, PBCR);
}
static inline void sci_init_pins(struct uart_port *port, unsigned int cflag)
{
unsigned short data;
if (cflag & CRTSCTS) {
if (port->mapbase == 0xa4430000) {
data = __raw_readw(PORT_PTCR);
__raw_writew((data & 0xfc03), PORT_PTCR);
} else if (port->mapbase == 0xa4438000) {
data = __raw_readw(PORT_PVCR);
__raw_writew((data & 0xfc03), PORT_PVCR);
}
} else {
if (port->mapbase == 0xa4430000) {
data = __raw_readw(PORT_PTCR);
__raw_writew((data & 0xffc3), PORT_PTCR);
} else if (port->mapbase == 0xa4438000) {
data = __raw_readw(PORT_PVCR);
__raw_writew((data & 0xffc3), PORT_PVCR);
}
}
}
static inline void sci_init_pins(struct uart_port *port, unsigned int cflag)
{
unsigned short data;
data = __raw_readw(SCPCR);
__raw_writew(data & 0x0fcf, SCPCR);
if (!(cflag & CRTSCTS)) {
data = __raw_readw(SCPCR);
__raw_writew((data & 0x0fcf) | 0x1000, SCPCR);
data = __raw_readb(SCPDR);
__raw_writeb(data & 0xbf, SCPDR);
}
}
static inline void sci_init_pins(struct uart_port *port, unsigned int cflag)
{
unsigned short data;
if (port->mapbase == 0xffe00000) {
data = __raw_readw(PSCR);
data &= ~0x03cf;
if (!(cflag & CRTSCTS))
data |= 0x0340;
__raw_writew(data, PSCR);
}
}
static inline void sci_init_pins(struct uart_port *port, unsigned int cflag)
{
if (!(cflag & CRTSCTS))
__raw_writew(0x0080, SCSPTR0);
}
static inline void sci_init_pins(struct uart_port *port, unsigned int cflag)
{
if (!(cflag & CRTSCTS))
__raw_writew(0x0080, SCSPTR2);
}
static inline void sci_init_pins(struct uart_port *port, unsigned int cflag)
{
}
static int scif_txfill(struct uart_port *port)
{
return sci_in(port, SCTFDR) & 0xff;
}
static int scif_txroom(struct uart_port *port)
{
return SCIF_TXROOM_MAX - scif_txfill(port);
}
static int scif_rxfill(struct uart_port *port)
{
return sci_in(port, SCRFDR) & 0xff;
}
static int scif_txfill(struct uart_port *port)
{
if (port->mapbase == 0xffe00000 ||
port->mapbase == 0xffe08000)
return sci_in(port, SCTFDR) & 0xff;
else
return sci_in(port, SCFDR) >> 8;
}
static int scif_txroom(struct uart_port *port)
{
if (port->mapbase == 0xffe00000 ||
port->mapbase == 0xffe08000)
return SCIF_TXROOM_MAX - scif_txfill(port);
else
return SCIF2_TXROOM_MAX - scif_txfill(port);
}
static int scif_rxfill(struct uart_port *port)
{
if ((port->mapbase == 0xffe00000) ||
(port->mapbase == 0xffe08000)) {
return sci_in(port, SCRFDR) & 0xff;
} else {
return sci_in(port, SCFDR) & SCIF2_RFDC_MASK;
}
}
static int scif_txfill(struct uart_port *port)
{
if (port->type == PORT_SCIFA)
return sci_in(port, SCFDR) >> 8;
else
return sci_in(port, SCTFDR);
}
static int scif_txroom(struct uart_port *port)
{
return port->fifosize - scif_txfill(port);
}
static int scif_rxfill(struct uart_port *port)
{
if (port->type == PORT_SCIFA)
return sci_in(port, SCFDR) & SCIF_RFDC_MASK;
else
return sci_in(port, SCRFDR);
}
static int scif_txfill(struct uart_port *port)
{
return sci_in(port, SCFDR) >> 8;
}
static int scif_txroom(struct uart_port *port)
{
return SCIF_TXROOM_MAX - scif_txfill(port);
}
static int scif_rxfill(struct uart_port *port)
{
return sci_in(port, SCFDR) & SCIF_RFDC_MASK;
}
static int sci_txfill(struct uart_port *port)
{
return !(sci_in(port, SCxSR) & SCI_TDRE);
}
static int sci_txroom(struct uart_port *port)
{
return !sci_txfill(port);
}
static int sci_rxfill(struct uart_port *port)
{
return (sci_in(port, SCxSR) & SCxSR_RDxF(port)) != 0;
}
static void sci_transmit_chars(struct uart_port *port)
{
struct circ_buf *xmit = &port->state->xmit;
unsigned int stopped = uart_tx_stopped(port);
unsigned short status;
unsigned short ctrl;
int count;
status = sci_in(port, SCxSR);
if (!(status & SCxSR_TDxE(port))) {
ctrl = sci_in(port, SCSCR);
if (uart_circ_empty(xmit))
ctrl &= ~SCSCR_TIE;
else
ctrl |= SCSCR_TIE;
sci_out(port, SCSCR, ctrl);
return;
}
if (port->type == PORT_SCI)
count = sci_txroom(port);
else
count = scif_txroom(port);
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
sci_out(port, SCxTDR, c);
port->icount.tx++;
} while (--count > 0);
sci_out(port, SCxSR, SCxSR_TDxE_CLEAR(port));
if (uart_circ_chars_pending(xmit) < WAKEUP_CHARS)
uart_write_wakeup(port);
if (uart_circ_empty(xmit)) {
sci_stop_tx(port);
} else {
ctrl = sci_in(port, SCSCR);
if (port->type != PORT_SCI) {
sci_in(port, SCxSR);
sci_out(port, SCxSR, SCxSR_TDxE_CLEAR(port));
}
ctrl |= SCSCR_TIE;
sci_out(port, SCSCR, ctrl);
}
}
static void sci_receive_chars(struct uart_port *port)
{
struct sci_port *sci_port = to_sci_port(port);
struct tty_struct *tty = port->state->port.tty;
int i, count, copied = 0;
unsigned short status;
unsigned char flag;
status = sci_in(port, SCxSR);
if (!(status & SCxSR_RDxF(port)))
return;
while (1) {
if (port->type == PORT_SCI)
count = sci_rxfill(port);
else
count = scif_rxfill(port);
count = tty_buffer_request_room(tty, count);
if (count == 0)
break;
if (port->type == PORT_SCI) {
char c = sci_in(port, SCxRDR);
if (uart_handle_sysrq_char(port, c) ||
sci_port->break_flag)
count = 0;
else
tty_insert_flip_char(tty, c, TTY_NORMAL);
} else {
for (i = 0; i < count; i++) {
char c = sci_in(port, SCxRDR);
status = sci_in(port, SCxSR);
#if defined(CONFIG_CPU_SH3)
if (sci_port->break_flag) {
if ((c == 0) &&
(status & SCxSR_FER(port))) {
count--; i--;
continue;
}
dev_dbg(port->dev, "debounce<%02x>\n", c);
sci_port->break_flag = 0;
if (STEPFN(c)) {
count--; i--;
continue;
}
}
#endif
if (uart_handle_sysrq_char(port, c)) {
count--; i--;
continue;
}
if (status & SCxSR_FER(port)) {
flag = TTY_FRAME;
dev_notice(port->dev, "frame error\n");
} else if (status & SCxSR_PER(port)) {
flag = TTY_PARITY;
dev_notice(port->dev, "parity error\n");
} else
flag = TTY_NORMAL;
tty_insert_flip_char(tty, c, flag);
}
}
sci_in(port, SCxSR);
sci_out(port, SCxSR, SCxSR_RDxF_CLEAR(port));
copied += count;
port->icount.rx += count;
}
if (copied) {
tty_flip_buffer_push(tty);
} else {
sci_in(port, SCxSR);
sci_out(port, SCxSR, SCxSR_RDxF_CLEAR(port));
}
}
static inline void sci_schedule_break_timer(struct sci_port *port)
{
mod_timer(&port->break_timer, jiffies + SCI_BREAK_JIFFIES);
}
static void sci_break_timer(unsigned long data)
{
struct sci_port *port = (struct sci_port *)data;
if (port->enable)
port->enable(&port->port);
if (sci_rxd_in(&port->port) == 0) {
port->break_flag = 1;
sci_schedule_break_timer(port);
} else if (port->break_flag == 1) {
port->break_flag = 2;
sci_schedule_break_timer(port);
} else
port->break_flag = 0;
if (port->disable)
port->disable(&port->port);
}
static int sci_handle_errors(struct uart_port *port)
{
int copied = 0;
unsigned short status = sci_in(port, SCxSR);
struct tty_struct *tty = port->state->port.tty;
if (status & SCxSR_ORER(port)) {
if (tty_insert_flip_char(tty, 0, TTY_OVERRUN))
copied++;
dev_notice(port->dev, "overrun error");
}
if (status & SCxSR_FER(port)) {
if (sci_rxd_in(port) == 0) {
struct sci_port *sci_port = to_sci_port(port);
if (!sci_port->break_flag) {
sci_port->break_flag = 1;
sci_schedule_break_timer(sci_port);
if (uart_handle_break(port))
return 0;
dev_dbg(port->dev, "BREAK detected\n");
if (tty_insert_flip_char(tty, 0, TTY_BREAK))
copied++;
}
} else {
if (tty_insert_flip_char(tty, 0, TTY_FRAME))
copied++;
dev_notice(port->dev, "frame error\n");
}
}
if (status & SCxSR_PER(port)) {
if (tty_insert_flip_char(tty, 0, TTY_PARITY))
copied++;
dev_notice(port->dev, "parity error");
}
if (copied)
tty_flip_buffer_push(tty);
return copied;
}
static int sci_handle_fifo_overrun(struct uart_port *port)
{
struct tty_struct *tty = port->state->port.tty;
int copied = 0;
if (port->type != PORT_SCIF)
return 0;
if ((sci_in(port, SCLSR) & SCIF_ORER) != 0) {
sci_out(port, SCLSR, 0);
tty_insert_flip_char(tty, 0, TTY_OVERRUN);
tty_flip_buffer_push(tty);
dev_notice(port->dev, "overrun error\n");
copied++;
}
return copied;
}
static int sci_handle_breaks(struct uart_port *port)
{
int copied = 0;
unsigned short status = sci_in(port, SCxSR);
struct tty_struct *tty = port->state->port.tty;
struct sci_port *s = to_sci_port(port);
if (uart_handle_break(port))
return 0;
if (!s->break_flag && status & SCxSR_BRK(port)) {
#if defined(CONFIG_CPU_SH3)
s->break_flag = 1;
#endif
if (tty_insert_flip_char(tty, 0, TTY_BREAK))
copied++;
dev_dbg(port->dev, "BREAK detected\n");
}
if (copied)
tty_flip_buffer_push(tty);
copied += sci_handle_fifo_overrun(port);
return copied;
}
static irqreturn_t sci_rx_interrupt(int irq, void *ptr)
{
#ifdef CONFIG_SERIAL_SH_SCI_DMA
struct uart_port *port = ptr;
struct sci_port *s = to_sci_port(port);
if (s->chan_rx) {
u16 scr = sci_in(port, SCSCR);
u16 ssr = sci_in(port, SCxSR);
if (port->type == PORT_SCIFA || port->type == PORT_SCIFB) {
disable_irq_nosync(irq);
scr |= 0x4000;
} else {
scr &= ~SCSCR_RIE;
}
sci_out(port, SCSCR, scr);
sci_out(port, SCxSR, ssr & ~(1 | SCxSR_RDxF(port)));
dev_dbg(port->dev, "Rx IRQ %lu: setup t-out in %u jiffies\n",
jiffies, s->rx_timeout);
mod_timer(&s->rx_timer, jiffies + s->rx_timeout);
return IRQ_HANDLED;
}
#endif
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
if (port->type == PORT_SCI) {
if (sci_handle_errors(port)) {
sci_in(port, SCxSR);
sci_out(port, SCxSR, SCxSR_RDxF_CLEAR(port));
}
} else {
sci_handle_fifo_overrun(port);
sci_rx_interrupt(irq, ptr);
}
sci_out(port, SCxSR, SCxSR_ERROR_CLEAR(port));
sci_tx_interrupt(irq, ptr);
return IRQ_HANDLED;
}
static irqreturn_t sci_br_interrupt(int irq, void *ptr)
{
struct uart_port *port = ptr;
sci_handle_breaks(port);
sci_out(port, SCxSR, SCxSR_BREAK_CLEAR(port));
return IRQ_HANDLED;
}
static inline unsigned long port_rx_irq_mask(struct uart_port *port)
{
return SCSCR_RIE | (to_sci_port(port)->cfg->scscr & SCSCR_REIE);
}
static irqreturn_t sci_mpxed_interrupt(int irq, void *ptr)
{
unsigned short ssr_status, scr_status, err_enabled;
struct uart_port *port = ptr;
struct sci_port *s = to_sci_port(port);
irqreturn_t ret = IRQ_NONE;
ssr_status = sci_in(port, SCxSR);
scr_status = sci_in(port, SCSCR);
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
return ret;
}
static int sci_notifier(struct notifier_block *self,
unsigned long phase, void *p)
{
struct sci_port *sci_port;
unsigned long flags;
sci_port = container_of(self, struct sci_port, freq_transition);
if ((phase == CPUFREQ_POSTCHANGE) ||
(phase == CPUFREQ_RESUMECHANGE)) {
struct uart_port *port = &sci_port->port;
spin_lock_irqsave(&port->lock, flags);
port->uartclk = clk_get_rate(sci_port->iclk);
spin_unlock_irqrestore(&port->lock, flags);
}
return NOTIFY_OK;
}
static void sci_clk_enable(struct uart_port *port)
{
struct sci_port *sci_port = to_sci_port(port);
pm_runtime_get_sync(port->dev);
clk_enable(sci_port->iclk);
sci_port->port.uartclk = clk_get_rate(sci_port->iclk);
clk_enable(sci_port->fclk);
}
static void sci_clk_disable(struct uart_port *port)
{
struct sci_port *sci_port = to_sci_port(port);
clk_disable(sci_port->fclk);
clk_disable(sci_port->iclk);
pm_runtime_put_sync(port->dev);
}
static int sci_request_irq(struct sci_port *port)
{
int i;
irqreturn_t (*handlers[4])(int irq, void *ptr) = {
sci_er_interrupt, sci_rx_interrupt, sci_tx_interrupt,
sci_br_interrupt,
}
void sci_free_irq(struct sci_port *port)
{
int i;
if (port->cfg->irqs[0] == port->cfg->irqs[1])
free_irq(port->cfg->irqs[0], port);
else {
for (i = 0; i < ARRAY_SIZE(port->cfg->irqs); i++) {
if (!port->cfg->irqs[i])
continue;
free_irq(port->cfg->irqs[i], port);
}
}
}
static unsigned int sci_tx_empty(struct uart_port *port)
{
unsigned short status = sci_in(port, SCxSR);
unsigned short in_tx_fifo = scif_txfill(port);
return (status & SCxSR_TEND(port)) && !in_tx_fifo ? TIOCSER_TEMT : 0;
}
static void sci_set_mctrl(struct uart_port *port, unsigned int mctrl)
{
}
static unsigned int sci_get_mctrl(struct uart_port *port)
{
return TIOCM_DTR | TIOCM_RTS | TIOCM_DSR;
}
static void sci_dma_tx_complete(void *arg)
{
struct sci_port *s = arg;
struct uart_port *port = &s->port;
struct circ_buf *xmit = &port->state->xmit;
unsigned long flags;
dev_dbg(port->dev, "%s(%d)\n", __func__, port->line);
spin_lock_irqsave(&port->lock, flags);
xmit->tail += sg_dma_len(&s->sg_tx);
xmit->tail &= UART_XMIT_SIZE - 1;
port->icount.tx += sg_dma_len(&s->sg_tx);
async_tx_ack(s->desc_tx);
s->cookie_tx = -EINVAL;
s->desc_tx = NULL;
if (uart_circ_chars_pending(xmit) < WAKEUP_CHARS)
uart_write_wakeup(port);
if (!uart_circ_empty(xmit)) {
schedule_work(&s->work_tx);
} else if (port->type == PORT_SCIFA || port->type == PORT_SCIFB) {
u16 ctrl = sci_in(port, SCSCR);
sci_out(port, SCSCR, ctrl & ~SCSCR_TIE);
}
spin_unlock_irqrestore(&port->lock, flags);
}
static int sci_dma_rx_push(struct sci_port *s, struct tty_struct *tty,
size_t count)
{
struct uart_port *port = &s->port;
int i, active, room;
room = tty_buffer_request_room(tty, count);
if (s->active_rx == s->cookie_rx[0]) {
active = 0;
} else if (s->active_rx == s->cookie_rx[1]) {
active = 1;
} else {
dev_err(port->dev, "cookie %d not found!\n", s->active_rx);
return 0;
}
if (room < count)
dev_warn(port->dev, "Rx overrun: dropping %u bytes\n",
count - room);
if (!room)
return room;
for (i = 0; i < room; i++)
tty_insert_flip_char(tty, ((u8 *)sg_virt(&s->sg_rx[active]))[i],
TTY_NORMAL);
port->icount.rx += room;
return room;
}
static void sci_dma_rx_complete(void *arg)
{
struct sci_port *s = arg;
struct uart_port *port = &s->port;
struct tty_struct *tty = port->state->port.tty;
unsigned long flags;
int count;
dev_dbg(port->dev, "%s(%d) active #%d\n", __func__, port->line, s->active_rx);
spin_lock_irqsave(&port->lock, flags);
count = sci_dma_rx_push(s, tty, s->buf_len_rx);
mod_timer(&s->rx_timer, jiffies + s->rx_timeout);
spin_unlock_irqrestore(&port->lock, flags);
if (count)
tty_flip_buffer_push(tty);
schedule_work(&s->work_rx);
}
static void sci_rx_dma_release(struct sci_port *s, bool enable_pio)
{
struct dma_chan *chan = s->chan_rx;
struct uart_port *port = &s->port;
s->chan_rx = NULL;
s->cookie_rx[0] = s->cookie_rx[1] = -EINVAL;
dma_release_channel(chan);
if (sg_dma_address(&s->sg_rx[0]))
dma_free_coherent(port->dev, s->buf_len_rx * 2,
sg_virt(&s->sg_rx[0]), sg_dma_address(&s->sg_rx[0]));
if (enable_pio)
sci_start_rx(port);
}
static void sci_tx_dma_release(struct sci_port *s, bool enable_pio)
{
struct dma_chan *chan = s->chan_tx;
struct uart_port *port = &s->port;
s->chan_tx = NULL;
s->cookie_tx = -EINVAL;
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
desc = chan->device->device_prep_slave_sg(chan,
sg, 1, DMA_FROM_DEVICE, DMA_PREP_INTERRUPT);
if (desc) {
s->desc_rx[i] = desc;
desc->callback = sci_dma_rx_complete;
desc->callback_param = s;
s->cookie_rx[i] = desc->tx_submit(desc);
}
if (!desc || s->cookie_rx[i] < 0) {
if (i) {
async_tx_ack(s->desc_rx[0]);
s->cookie_rx[0] = -EINVAL;
}
if (desc) {
async_tx_ack(desc);
s->cookie_rx[i] = -EINVAL;
}
dev_warn(s->port.dev,
"failed to re-start DMA, using PIO\n");
sci_rx_dma_release(s, true);
return;
}
dev_dbg(s->port.dev, "%s(): cookie %d to #%d\n", __func__,
s->cookie_rx[i], i);
}
s->active_rx = s->cookie_rx[0];
dma_async_issue_pending(chan);
}
static void work_fn_rx(struct work_struct *work)
{
struct sci_port *s = container_of(work, struct sci_port, work_rx);
struct uart_port *port = &s->port;
struct dma_async_tx_descriptor *desc;
int new;
if (s->active_rx == s->cookie_rx[0]) {
new = 0;
} else if (s->active_rx == s->cookie_rx[1]) {
new = 1;
} else {
dev_err(port->dev, "cookie %d not found!\n", s->active_rx);
return;
}
desc = s->desc_rx[new];
if (dma_async_is_tx_complete(s->chan_rx, s->active_rx, NULL, NULL) !=
DMA_SUCCESS) {
struct tty_struct *tty = port->state->port.tty;
struct dma_chan *chan = s->chan_rx;
struct sh_desc *sh_desc = container_of(desc, struct sh_desc,
async_tx);
unsigned long flags;
int count;
chan->device->device_control(chan, DMA_TERMINATE_ALL, 0);
dev_dbg(port->dev, "Read %u bytes with cookie %d\n",
sh_desc->partial, sh_desc->cookie);
spin_lock_irqsave(&port->lock, flags);
count = sci_dma_rx_push(s, tty, sh_desc->partial);
spin_unlock_irqrestore(&port->lock, flags);
if (count)
tty_flip_buffer_push(tty);
sci_submit_rx(s);
return;
}
s->cookie_rx[new] = desc->tx_submit(desc);
if (s->cookie_rx[new] < 0) {
dev_warn(port->dev, "Failed submitting Rx DMA descriptor\n");
sci_rx_dma_release(s, true);
return;
}
s->active_rx = s->cookie_rx[!new];
dev_dbg(port->dev, "%s: cookie %d #%d, new active #%d\n", __func__,
s->cookie_rx[new], new, s->active_rx);
}
static void work_fn_tx(struct work_struct *work)
{
struct sci_port *s = container_of(work, struct sci_port, work_tx);
struct dma_async_tx_descriptor *desc;
struct dma_chan *chan = s->chan_tx;
struct uart_port *port = &s->port;
struct circ_buf *xmit = &port->state->xmit;
struct scatterlist *sg = &s->sg_tx;
spin_lock_irq(&port->lock);
sg->offset = xmit->tail & (UART_XMIT_SIZE - 1);
sg_dma_address(sg) = (sg_dma_address(sg) & ~(UART_XMIT_SIZE - 1)) +
sg->offset;
sg_dma_len(sg) = min((int)CIRC_CNT(xmit->head, xmit->tail, UART_XMIT_SIZE),
CIRC_CNT_TO_END(xmit->head, xmit->tail, UART_XMIT_SIZE));
spin_unlock_irq(&port->lock);
BUG_ON(!sg_dma_len(sg));
desc = chan->device->device_prep_slave_sg(chan,
sg, s->sg_len_tx, DMA_TO_DEVICE,
DMA_PREP_INTERRUPT | DMA_CTRL_ACK);
if (!desc) {
sci_tx_dma_release(s, true);
return;
}
dma_sync_sg_for_device(port->dev, sg, 1, DMA_TO_DEVICE);
spin_lock_irq(&port->lock);
s->desc_tx = desc;
desc->callback = sci_dma_tx_complete;
desc->callback_param = s;
spin_unlock_irq(&port->lock);
s->cookie_tx = desc->tx_submit(desc);
if (s->cookie_tx < 0) {
dev_warn(port->dev, "Failed submitting Tx DMA descriptor\n");
sci_tx_dma_release(s, true);
return;
}
dev_dbg(port->dev, "%s: %p: %d...%d, cookie %d\n", __func__,
xmit->buf, xmit->tail, xmit->head, s->cookie_tx);
dma_async_issue_pending(chan);
}
static void sci_start_tx(struct uart_port *port)
{
struct sci_port *s = to_sci_port(port);
unsigned short ctrl;
#ifdef CONFIG_SERIAL_SH_SCI_DMA
if (port->type == PORT_SCIFA || port->type == PORT_SCIFB) {
u16 new, scr = sci_in(port, SCSCR);
if (s->chan_tx)
new = scr | 0x8000;
else
new = scr & ~0x8000;
if (new != scr)
sci_out(port, SCSCR, new);
}
if (s->chan_tx && !uart_circ_empty(&s->port.state->xmit) &&
s->cookie_tx < 0)
schedule_work(&s->work_tx);
#endif
if (!s->chan_tx || port->type == PORT_SCIFA || port->type == PORT_SCIFB) {
ctrl = sci_in(port, SCSCR);
sci_out(port, SCSCR, ctrl | SCSCR_TIE);
}
}
static void sci_stop_tx(struct uart_port *port)
{
unsigned short ctrl;
ctrl = sci_in(port, SCSCR);
if (port->type == PORT_SCIFA || port->type == PORT_SCIFB)
ctrl &= ~0x8000;
ctrl &= ~SCSCR_TIE;
sci_out(port, SCSCR, ctrl);
}
static void sci_start_rx(struct uart_port *port)
{
unsigned short ctrl;
ctrl = sci_in(port, SCSCR) | port_rx_irq_mask(port);
if (port->type == PORT_SCIFA || port->type == PORT_SCIFB)
ctrl &= ~0x4000;
sci_out(port, SCSCR, ctrl);
}
static void sci_stop_rx(struct uart_port *port)
{
unsigned short ctrl;
ctrl = sci_in(port, SCSCR);
if (port->type == PORT_SCIFA || port->type == PORT_SCIFB)
ctrl &= ~0x4000;
ctrl &= ~port_rx_irq_mask(port);
sci_out(port, SCSCR, ctrl);
}
static void sci_enable_ms(struct uart_port *port)
{
}
static void sci_break_ctl(struct uart_port *port, int break_state)
{
}
static bool filter(struct dma_chan *chan, void *slave)
{
struct sh_dmae_slave *param = slave;
dev_dbg(chan->device->dev, "%s: slave ID %d\n", __func__,
param->slave_id);
if (param->dma_dev == chan->device->dev) {
chan->private = param;
return true;
} else {
return false;
}
}
static void rx_timer_fn(unsigned long arg)
{
struct sci_port *s = (struct sci_port *)arg;
struct uart_port *port = &s->port;
u16 scr = sci_in(port, SCSCR);
if (port->type == PORT_SCIFA || port->type == PORT_SCIFB) {
scr &= ~0x4000;
enable_irq(s->cfg->irqs[1]);
}
sci_out(port, SCSCR, scr | SCSCR_RIE);
dev_dbg(port->dev, "DMA Rx timed out\n");
schedule_work(&s->work_rx);
}
static void sci_request_dma(struct uart_port *port)
{
struct sci_port *s = to_sci_port(port);
struct sh_dmae_slave *param;
struct dma_chan *chan;
dma_cap_mask_t mask;
int nent;
dev_dbg(port->dev, "%s: port %d DMA %p\n", __func__,
port->line, s->cfg->dma_dev);
if (!s->cfg->dma_dev)
return;
dma_cap_zero(mask);
dma_cap_set(DMA_SLAVE, mask);
param = &s->param_tx;
param->slave_id = s->cfg->dma_slave_tx;
param->dma_dev = s->cfg->dma_dev;
s->cookie_tx = -EINVAL;
chan = dma_request_channel(mask, filter, param);
dev_dbg(port->dev, "%s: TX: got channel %p\n", __func__, chan);
if (chan) {
s->chan_tx = chan;
sg_init_table(&s->sg_tx, 1);
BUG_ON((int)port->state->xmit.buf & ~PAGE_MASK);
sg_set_page(&s->sg_tx, virt_to_page(port->state->xmit.buf),
UART_XMIT_SIZE, (int)port->state->xmit.buf & ~PAGE_MASK);
nent = dma_map_sg(port->dev, &s->sg_tx, 1, DMA_TO_DEVICE);
if (!nent)
sci_tx_dma_release(s, false);
else
dev_dbg(port->dev, "%s: mapped %d@%p to %x\n", __func__,
sg_dma_len(&s->sg_tx),
port->state->xmit.buf, sg_dma_address(&s->sg_tx));
s->sg_len_tx = nent;
INIT_WORK(&s->work_tx, work_fn_tx);
}
param = &s->param_rx;
param->slave_id = s->cfg->dma_slave_rx;
param->dma_dev = s->cfg->dma_dev;
chan = dma_request_channel(mask, filter, param);
dev_dbg(port->dev, "%s: RX: got channel %p\n", __func__, chan);
if (chan) {
dma_addr_t dma[2];
void *buf[2];
int i;
s->chan_rx = chan;
s->buf_len_rx = 2 * max(16, (int)port->fifosize);
buf[0] = dma_alloc_coherent(port->dev, s->buf_len_rx * 2,
&dma[0], GFP_KERNEL);
if (!buf[0]) {
dev_warn(port->dev,
"failed to allocate dma buffer, using PIO\n");
sci_rx_dma_release(s, true);
return;
}
buf[1] = buf[0] + s->buf_len_rx;
dma[1] = dma[0] + s->buf_len_rx;
for (i = 0; i < 2; i++) {
struct scatterlist *sg = &s->sg_rx[i];
sg_init_table(sg, 1);
sg_set_page(sg, virt_to_page(buf[i]), s->buf_len_rx,
(int)buf[i] & ~PAGE_MASK);
sg_dma_address(sg) = dma[i];
}
INIT_WORK(&s->work_rx, work_fn_rx);
setup_timer(&s->rx_timer, rx_timer_fn, (unsigned long)s);
sci_submit_rx(s);
}
}
static void sci_free_dma(struct uart_port *port)
{
struct sci_port *s = to_sci_port(port);
if (!s->cfg->dma_dev)
return;
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
static int sci_startup(struct uart_port *port)
{
struct sci_port *s = to_sci_port(port);
int ret;
dev_dbg(port->dev, "%s(%d)\n", __func__, port->line);
if (s->enable)
s->enable(port);
ret = sci_request_irq(s);
if (unlikely(ret < 0))
return ret;
sci_request_dma(port);
sci_start_tx(port);
sci_start_rx(port);
return 0;
}
static void sci_shutdown(struct uart_port *port)
{
struct sci_port *s = to_sci_port(port);
dev_dbg(port->dev, "%s(%d)\n", __func__, port->line);
sci_stop_rx(port);
sci_stop_tx(port);
sci_free_dma(port);
sci_free_irq(s);
if (s->disable)
s->disable(port);
}
static unsigned int sci_scbrr_calc(unsigned int algo_id, unsigned int bps,
unsigned long freq)
{
switch (algo_id) {
case SCBRR_ALGO_1:
return ((freq + 16 * bps) / (16 * bps) - 1);
case SCBRR_ALGO_2:
return ((freq + 16 * bps) / (32 * bps) - 1);
case SCBRR_ALGO_3:
return (((freq * 2) + 16 * bps) / (16 * bps) - 1);
case SCBRR_ALGO_4:
return (((freq * 2) + 16 * bps) / (32 * bps) - 1);
case SCBRR_ALGO_5:
return (((freq * 1000 / 32) / bps) - 1);
}
WARN_ON(1);
return ((freq + 16 * bps) / (32 * bps) - 1);
}
static void sci_set_termios(struct uart_port *port, struct ktermios *termios,
struct ktermios *old)
{
struct sci_port *s = to_sci_port(port);
unsigned int status, baud, smr_val, max_baud;
int t = -1;
u16 scfcr = 0;
max_baud = port->uartclk ? port->uartclk / 16 : 115200;
baud = uart_get_baud_rate(port, termios, old, 0, max_baud);
if (likely(baud && port->uartclk))
t = sci_scbrr_calc(s->cfg->scbrr_algo_id, baud, port->uartclk);
if (s->enable)
s->enable(port);
do {
status = sci_in(port, SCxSR);
} while (!(status & SCxSR_TEND(port)));
sci_out(port, SCSCR, 0x00);
if (port->type != PORT_SCI)
sci_out(port, SCFCR, scfcr | SCFCR_RFRST | SCFCR_TFRST);
smr_val = sci_in(port, SCSMR) & 3;
if ((termios->c_cflag & CSIZE) == CS7)
smr_val |= 0x40;
if (termios->c_cflag & PARENB)
smr_val |= 0x20;
if (termios->c_cflag & PARODD)
smr_val |= 0x30;
if (termios->c_cflag & CSTOPB)
smr_val |= 0x08;
uart_update_timeout(port, termios->c_cflag, baud);
sci_out(port, SCSMR, smr_val);
dev_dbg(port->dev, "%s: SMR %x, t %x, SCSCR %x\n", __func__, smr_val, t,
s->cfg->scscr);
if (t > 0) {
if (t >= 256) {
sci_out(port, SCSMR, (sci_in(port, SCSMR) & ~3) | 1);
t >>= 2;
} else
sci_out(port, SCSMR, sci_in(port, SCSMR) & ~3);
sci_out(port, SCBRR, t);
udelay((1000000+(baud-1)) / baud);
}
sci_init_pins(port, termios->c_cflag);
sci_out(port, SCFCR, scfcr | ((termios->c_cflag & CRTSCTS) ? SCFCR_MCE : 0));
sci_out(port, SCSCR, s->cfg->scscr);
#ifdef CONFIG_SERIAL_SH_SCI_DMA
if (s->chan_rx) {
s->rx_timeout = (port->timeout - HZ / 50) * s->buf_len_rx * 3 /
port->fifosize / 2;
dev_dbg(port->dev,
"DMA Rx t-out %ums, tty t-out %u jiffies\n",
s->rx_timeout * 1000 / HZ, port->timeout);
if (s->rx_timeout < msecs_to_jiffies(20))
s->rx_timeout = msecs_to_jiffies(20);
}
#endif
if ((termios->c_cflag & CREAD) != 0)
sci_start_rx(port);
if (s->disable)
s->disable(port);
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
}
return NULL;
}
static inline unsigned long sci_port_size(struct uart_port *port)
{
return 64;
}
static int sci_remap_port(struct uart_port *port)
{
unsigned long size = sci_port_size(port);
if (port->membase)
return 0;
if (port->flags & UPF_IOREMAP) {
port->membase = ioremap_nocache(port->mapbase, size);
if (unlikely(!port->membase)) {
dev_err(port->dev, "can't remap port#%d\n", port->line);
return -ENXIO;
}
} else {
port->membase = (void __iomem *)port->mapbase;
}
return 0;
}
static void sci_release_port(struct uart_port *port)
{
if (port->flags & UPF_IOREMAP) {
iounmap(port->membase);
port->membase = NULL;
}
release_mem_region(port->mapbase, sci_port_size(port));
}
static int sci_request_port(struct uart_port *port)
{
unsigned long size = sci_port_size(port);
struct resource *res;
int ret;
res = request_mem_region(port->mapbase, size, dev_name(port->dev));
if (unlikely(res == NULL))
return -EBUSY;
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
struct sci_port *s = to_sci_port(port);
if (ser->irq != s->cfg->irqs[SCIx_TXI_IRQ] || ser->irq > nr_irqs)
return -EINVAL;
if (ser->baud_base < 2400)
return -EINVAL;
return 0;
}
static int __devinit sci_init_single(struct platform_device *dev,
struct sci_port *sci_port,
unsigned int index,
struct plat_sci_port *p)
{
struct uart_port *port = &sci_port->port;
port->ops = &sci_uart_ops;
port->iotype = UPIO_MEM;
port->line = index;
switch (p->type) {
case PORT_SCIFB:
port->fifosize = 256;
break;
case PORT_SCIFA:
port->fifosize = 64;
break;
case PORT_SCIF:
port->fifosize = 16;
break;
default:
port->fifosize = 1;
break;
}
if (dev) {
sci_port->iclk = clk_get(&dev->dev, "sci_ick");
if (IS_ERR(sci_port->iclk)) {
sci_port->iclk = clk_get(&dev->dev, "peripheral_clk");
if (IS_ERR(sci_port->iclk)) {
dev_err(&dev->dev, "can't get iclk\n");
return PTR_ERR(sci_port->iclk);
}
}
sci_port->fclk = clk_get(&dev->dev, "sci_fck");
if (IS_ERR(sci_port->fclk))
sci_port->fclk = NULL;
sci_port->enable = sci_clk_enable;
sci_port->disable = sci_clk_disable;
port->dev = &dev->dev;
pm_runtime_enable(&dev->dev);
}
sci_port->break_timer.data = (unsigned long)sci_port;
sci_port->break_timer.function = sci_break_timer;
init_timer(&sci_port->break_timer);
sci_port->cfg = p;
port->mapbase = p->mapbase;
port->type = p->type;
port->flags = p->flags;
port->irq = p->irqs[SCIx_RXI_IRQ];
if (p->dma_dev)
dev_dbg(port->dev, "DMA device %p, tx %d, rx %d\n",
p->dma_dev, p->dma_slave_tx, p->dma_slave_rx);
return 0;
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
unsigned short bits;
if (sci_port->enable)
sci_port->enable(port);
uart_console_write(port, s, count, serial_console_putchar);
bits = SCxSR_TDxE(port) | SCxSR_TEND(port);
while ((sci_in(port, SCxSR) & bits) != bits)
cpu_relax();
if (sci_port->disable)
sci_port->disable(port);
}
static int __devinit serial_console_setup(struct console *co, char *options)
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
if (sci_port->enable)
sci_port->enable(port);
if (options)
uart_parse_options(options, &baud, &parity, &bits, &flow);
ret = uart_set_options(port, co, baud, parity, bits, flow);
#if defined(__H8300H__) || defined(__H8300S__)
if (ret == 0)
sci_stop_rx(port);
#endif
return ret;
}
static int __devinit sci_probe_earlyprintk(struct platform_device *pdev)
{
struct plat_sci_port *cfg = pdev->dev.platform_data;
if (early_serial_console.data)
return -EEXIST;
early_serial_console.index = pdev->id;
sci_init_single(NULL, &sci_ports[pdev->id], pdev->id, cfg);
serial_console_setup(&early_serial_console, early_serial_buf);
if (!strstr(early_serial_buf, "keep"))
early_serial_console.flags |= CON_BOOT;
register_console(&early_serial_console);
return 0;
}
static inline int __devinit sci_probe_earlyprintk(struct platform_device *pdev)
{
return -EINVAL;
}
static int sci_remove(struct platform_device *dev)
{
struct sci_port *port = platform_get_drvdata(dev);
cpufreq_unregister_notifier(&port->freq_transition,
CPUFREQ_TRANSITION_NOTIFIER);
uart_remove_one_port(&sci_uart_driver, &port->port);
clk_put(port->iclk);
clk_put(port->fclk);
pm_runtime_disable(&dev->dev);
return 0;
}
static int __devinit sci_probe_single(struct platform_device *dev,
unsigned int index,
struct plat_sci_port *p,
struct sci_port *sciport)
{
int ret;
if (unlikely(index >= SCI_NPORTS)) {
dev_notice(&dev->dev, "Attempting to register port "
"%d when only %d are available.\n",
index+1, SCI_NPORTS);
dev_notice(&dev->dev, "Consider bumping "
"CONFIG_SERIAL_SH_SCI_NR_UARTS!\n");
return 0;
}
ret = sci_init_single(dev, sciport, index, p);
if (ret)
return ret;
return uart_add_one_port(&sci_uart_driver, &sciport->port);
}
static int __devinit sci_probe(struct platform_device *dev)
{
struct plat_sci_port *p = dev->dev.platform_data;
struct sci_port *sp = &sci_ports[dev->id];
int ret;
if (is_early_platform_device(dev))
return sci_probe_earlyprintk(dev);
platform_set_drvdata(dev, sp);
ret = sci_probe_single(dev, dev->id, p, sp);
if (ret)
goto err_unreg;
sp->freq_transition.notifier_call = sci_notifier;
ret = cpufreq_register_notifier(&sp->freq_transition,
CPUFREQ_TRANSITION_NOTIFIER);
if (unlikely(ret < 0))
goto err_unreg;
#ifdef CONFIG_SH_STANDARD_BIOS
sh_bios_gdb_detach();
#endif
return 0;
err_unreg:
sci_remove(dev);
return ret;
}
static int sci_suspend(struct device *dev)
{
struct sci_port *sport = dev_get_drvdata(dev);
if (sport)
uart_suspend_port(&sci_uart_driver, &sport->port);
return 0;
}
static int sci_resume(struct device *dev)
{
struct sci_port *sport = dev_get_drvdata(dev);
if (sport)
uart_resume_port(&sci_uart_driver, &sport->port);
return 0;
}
static int __init sci_init(void)
{
int ret;
printk(banner);
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
