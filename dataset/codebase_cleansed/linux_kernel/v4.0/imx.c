static inline unsigned uts_reg(struct imx_port *sport)
{
return sport->devdata->uts_reg;
}
static inline int is_imx1_uart(struct imx_port *sport)
{
return sport->devdata->devtype == IMX1_UART;
}
static inline int is_imx21_uart(struct imx_port *sport)
{
return sport->devdata->devtype == IMX21_UART;
}
static inline int is_imx6q_uart(struct imx_port *sport)
{
return sport->devdata->devtype == IMX6Q_UART;
}
static void imx_port_ucrs_save(struct uart_port *port,
struct imx_port_ucrs *ucr)
{
ucr->ucr1 = readl(port->membase + UCR1);
ucr->ucr2 = readl(port->membase + UCR2);
ucr->ucr3 = readl(port->membase + UCR3);
}
static void imx_port_ucrs_restore(struct uart_port *port,
struct imx_port_ucrs *ucr)
{
writel(ucr->ucr1, port->membase + UCR1);
writel(ucr->ucr2, port->membase + UCR2);
writel(ucr->ucr3, port->membase + UCR3);
}
static void imx_mctrl_check(struct imx_port *sport)
{
unsigned int status, changed;
status = sport->port.ops->get_mctrl(&sport->port);
changed = status ^ sport->old_status;
if (changed == 0)
return;
sport->old_status = status;
if (changed & TIOCM_RI)
sport->port.icount.rng++;
if (changed & TIOCM_DSR)
sport->port.icount.dsr++;
if (changed & TIOCM_CAR)
uart_handle_dcd_change(&sport->port, status & TIOCM_CAR);
if (changed & TIOCM_CTS)
uart_handle_cts_change(&sport->port, status & TIOCM_CTS);
wake_up_interruptible(&sport->port.state->port.delta_msr_wait);
}
static void imx_timeout(unsigned long data)
{
struct imx_port *sport = (struct imx_port *)data;
unsigned long flags;
if (sport->port.state) {
spin_lock_irqsave(&sport->port.lock, flags);
imx_mctrl_check(sport);
spin_unlock_irqrestore(&sport->port.lock, flags);
mod_timer(&sport->timer, jiffies + MCTRL_TIMEOUT);
}
}
static void imx_stop_tx(struct uart_port *port)
{
struct imx_port *sport = (struct imx_port *)port;
unsigned long temp;
if (USE_IRDA(sport)) {
int n = 256;
while ((--n > 0) &&
!(readl(sport->port.membase + USR2) & USR2_TXDC)) {
udelay(5);
barrier();
}
udelay(sport->trcv_delay);
if (readl(sport->port.membase + USR2) & USR2_TXDC) {
temp = readl(sport->port.membase + UCR1);
temp &= ~(UCR1_TXMPTYEN | UCR1_TRDYEN);
writel(temp, sport->port.membase + UCR1);
temp = readl(sport->port.membase + UCR4);
temp &= ~(UCR4_TCEN);
writel(temp, sport->port.membase + UCR4);
while (readl(sport->port.membase + URXD0) &
URXD_CHARRDY)
barrier();
temp = readl(sport->port.membase + UCR1);
temp |= UCR1_RRDYEN;
writel(temp, sport->port.membase + UCR1);
temp = readl(sport->port.membase + UCR4);
temp |= UCR4_DREN;
writel(temp, sport->port.membase + UCR4);
}
return;
}
if (sport->dma_is_enabled && sport->dma_is_txing)
return;
temp = readl(sport->port.membase + UCR1);
writel(temp & ~UCR1_TXMPTYEN, sport->port.membase + UCR1);
}
static void imx_stop_rx(struct uart_port *port)
{
struct imx_port *sport = (struct imx_port *)port;
unsigned long temp;
if (sport->dma_is_enabled && sport->dma_is_rxing) {
if (sport->port.suspended) {
dmaengine_terminate_all(sport->dma_chan_rx);
sport->dma_is_rxing = 0;
} else {
return;
}
}
temp = readl(sport->port.membase + UCR2);
writel(temp & ~UCR2_RXEN, sport->port.membase + UCR2);
temp = readl(sport->port.membase + UCR1);
writel(temp & ~UCR1_RRDYEN, sport->port.membase + UCR1);
}
static void imx_enable_ms(struct uart_port *port)
{
struct imx_port *sport = (struct imx_port *)port;
mod_timer(&sport->timer, jiffies);
}
static inline void imx_transmit_buffer(struct imx_port *sport)
{
struct circ_buf *xmit = &sport->port.state->xmit;
unsigned long temp;
if (sport->port.x_char) {
writel(sport->port.x_char, sport->port.membase + URTX0);
sport->port.icount.tx++;
sport->port.x_char = 0;
return;
}
if (uart_circ_empty(xmit) || uart_tx_stopped(&sport->port)) {
imx_stop_tx(&sport->port);
return;
}
if (sport->dma_is_enabled) {
temp = readl(sport->port.membase + UCR1);
temp &= ~UCR1_TXMPTYEN;
if (sport->dma_is_txing) {
temp |= UCR1_TDMAEN;
writel(temp, sport->port.membase + UCR1);
} else {
writel(temp, sport->port.membase + UCR1);
imx_dma_tx(sport);
}
}
while (!uart_circ_empty(xmit) &&
!(readl(sport->port.membase + uts_reg(sport)) & UTS_TXFULL)) {
writel(xmit->buf[xmit->tail], sport->port.membase + URTX0);
xmit->tail = (xmit->tail + 1) & (UART_XMIT_SIZE - 1);
sport->port.icount.tx++;
}
if (uart_circ_chars_pending(xmit) < WAKEUP_CHARS)
uart_write_wakeup(&sport->port);
if (uart_circ_empty(xmit))
imx_stop_tx(&sport->port);
}
static void dma_tx_callback(void *data)
{
struct imx_port *sport = data;
struct scatterlist *sgl = &sport->tx_sgl[0];
struct circ_buf *xmit = &sport->port.state->xmit;
unsigned long flags;
unsigned long temp;
spin_lock_irqsave(&sport->port.lock, flags);
dma_unmap_sg(sport->port.dev, sgl, sport->dma_tx_nents, DMA_TO_DEVICE);
temp = readl(sport->port.membase + UCR1);
temp &= ~UCR1_TDMAEN;
writel(temp, sport->port.membase + UCR1);
xmit->tail = (xmit->tail + sport->tx_bytes) & (UART_XMIT_SIZE - 1);
sport->port.icount.tx += sport->tx_bytes;
dev_dbg(sport->port.dev, "we finish the TX DMA.\n");
sport->dma_is_txing = 0;
spin_unlock_irqrestore(&sport->port.lock, flags);
if (uart_circ_chars_pending(xmit) < WAKEUP_CHARS)
uart_write_wakeup(&sport->port);
if (waitqueue_active(&sport->dma_wait)) {
wake_up(&sport->dma_wait);
dev_dbg(sport->port.dev, "exit in %s.\n", __func__);
return;
}
spin_lock_irqsave(&sport->port.lock, flags);
if (!uart_circ_empty(xmit) && !uart_tx_stopped(&sport->port))
imx_dma_tx(sport);
spin_unlock_irqrestore(&sport->port.lock, flags);
}
static void imx_dma_tx(struct imx_port *sport)
{
struct circ_buf *xmit = &sport->port.state->xmit;
struct scatterlist *sgl = sport->tx_sgl;
struct dma_async_tx_descriptor *desc;
struct dma_chan *chan = sport->dma_chan_tx;
struct device *dev = sport->port.dev;
unsigned long temp;
int ret;
if (sport->dma_is_txing)
return;
sport->tx_bytes = uart_circ_chars_pending(xmit);
if (xmit->tail < xmit->head) {
sport->dma_tx_nents = 1;
sg_init_one(sgl, xmit->buf + xmit->tail, sport->tx_bytes);
} else {
sport->dma_tx_nents = 2;
sg_init_table(sgl, 2);
sg_set_buf(sgl, xmit->buf + xmit->tail,
UART_XMIT_SIZE - xmit->tail);
sg_set_buf(sgl + 1, xmit->buf, xmit->head);
}
ret = dma_map_sg(dev, sgl, sport->dma_tx_nents, DMA_TO_DEVICE);
if (ret == 0) {
dev_err(dev, "DMA mapping error for TX.\n");
return;
}
desc = dmaengine_prep_slave_sg(chan, sgl, sport->dma_tx_nents,
DMA_MEM_TO_DEV, DMA_PREP_INTERRUPT);
if (!desc) {
dma_unmap_sg(dev, sgl, sport->dma_tx_nents,
DMA_TO_DEVICE);
dev_err(dev, "We cannot prepare for the TX slave dma!\n");
return;
}
desc->callback = dma_tx_callback;
desc->callback_param = sport;
dev_dbg(dev, "TX: prepare to send %lu bytes by DMA.\n",
uart_circ_chars_pending(xmit));
temp = readl(sport->port.membase + UCR1);
temp |= UCR1_TDMAEN;
writel(temp, sport->port.membase + UCR1);
sport->dma_is_txing = 1;
dmaengine_submit(desc);
dma_async_issue_pending(chan);
return;
}
static void imx_start_tx(struct uart_port *port)
{
struct imx_port *sport = (struct imx_port *)port;
unsigned long temp;
if (USE_IRDA(sport)) {
temp = readl(sport->port.membase + UCR4);
temp &= ~(UCR4_DREN);
writel(temp, sport->port.membase + UCR4);
temp = readl(sport->port.membase + UCR1);
temp &= ~(UCR1_RRDYEN);
writel(temp, sport->port.membase + UCR1);
}
if (!sport->dma_is_enabled) {
temp = readl(sport->port.membase + UCR1);
writel(temp | UCR1_TXMPTYEN, sport->port.membase + UCR1);
}
if (USE_IRDA(sport)) {
temp = readl(sport->port.membase + UCR1);
temp |= UCR1_TRDYEN;
writel(temp, sport->port.membase + UCR1);
temp = readl(sport->port.membase + UCR4);
temp |= UCR4_TCEN;
writel(temp, sport->port.membase + UCR4);
}
if (sport->dma_is_enabled) {
if (sport->port.x_char) {
temp = readl(sport->port.membase + UCR1);
temp &= ~UCR1_TDMAEN;
temp |= UCR1_TXMPTYEN;
writel(temp, sport->port.membase + UCR1);
return;
}
if (!uart_circ_empty(&port->state->xmit) &&
!uart_tx_stopped(port))
imx_dma_tx(sport);
return;
}
}
static irqreturn_t imx_rtsint(int irq, void *dev_id)
{
struct imx_port *sport = dev_id;
unsigned int val;
unsigned long flags;
spin_lock_irqsave(&sport->port.lock, flags);
writel(USR1_RTSD, sport->port.membase + USR1);
val = readl(sport->port.membase + USR1) & USR1_RTSS;
uart_handle_cts_change(&sport->port, !!val);
wake_up_interruptible(&sport->port.state->port.delta_msr_wait);
spin_unlock_irqrestore(&sport->port.lock, flags);
return IRQ_HANDLED;
}
static irqreturn_t imx_txint(int irq, void *dev_id)
{
struct imx_port *sport = dev_id;
unsigned long flags;
spin_lock_irqsave(&sport->port.lock, flags);
imx_transmit_buffer(sport);
spin_unlock_irqrestore(&sport->port.lock, flags);
return IRQ_HANDLED;
}
static irqreturn_t imx_rxint(int irq, void *dev_id)
{
struct imx_port *sport = dev_id;
unsigned int rx, flg, ignored = 0;
struct tty_port *port = &sport->port.state->port;
unsigned long flags, temp;
spin_lock_irqsave(&sport->port.lock, flags);
while (readl(sport->port.membase + USR2) & USR2_RDR) {
flg = TTY_NORMAL;
sport->port.icount.rx++;
rx = readl(sport->port.membase + URXD0);
temp = readl(sport->port.membase + USR2);
if (temp & USR2_BRCD) {
writel(USR2_BRCD, sport->port.membase + USR2);
if (uart_handle_break(&sport->port))
continue;
}
if (uart_handle_sysrq_char(&sport->port, (unsigned char)rx))
continue;
if (unlikely(rx & URXD_ERR)) {
if (rx & URXD_BRK)
sport->port.icount.brk++;
else if (rx & URXD_PRERR)
sport->port.icount.parity++;
else if (rx & URXD_FRMERR)
sport->port.icount.frame++;
if (rx & URXD_OVRRUN)
sport->port.icount.overrun++;
if (rx & sport->port.ignore_status_mask) {
if (++ignored > 100)
goto out;
continue;
}
rx &= (sport->port.read_status_mask | 0xFF);
if (rx & URXD_BRK)
flg = TTY_BREAK;
else if (rx & URXD_PRERR)
flg = TTY_PARITY;
else if (rx & URXD_FRMERR)
flg = TTY_FRAME;
if (rx & URXD_OVRRUN)
flg = TTY_OVERRUN;
#ifdef SUPPORT_SYSRQ
sport->port.sysrq = 0;
#endif
}
if (sport->port.ignore_status_mask & URXD_DUMMY_READ)
goto out;
tty_insert_flip_char(port, rx, flg);
}
out:
spin_unlock_irqrestore(&sport->port.lock, flags);
tty_flip_buffer_push(port);
return IRQ_HANDLED;
}
static void imx_dma_rxint(struct imx_port *sport)
{
unsigned long temp;
unsigned long flags;
spin_lock_irqsave(&sport->port.lock, flags);
temp = readl(sport->port.membase + USR2);
if ((temp & USR2_RDR) && !sport->dma_is_rxing) {
sport->dma_is_rxing = 1;
temp = readl(sport->port.membase + UCR1);
temp &= ~(UCR1_RRDYEN);
writel(temp, sport->port.membase + UCR1);
start_rx_dma(sport);
}
spin_unlock_irqrestore(&sport->port.lock, flags);
}
static irqreturn_t imx_int(int irq, void *dev_id)
{
struct imx_port *sport = dev_id;
unsigned int sts;
unsigned int sts2;
sts = readl(sport->port.membase + USR1);
if (sts & USR1_RRDY) {
if (sport->dma_is_enabled)
imx_dma_rxint(sport);
else
imx_rxint(irq, dev_id);
}
if (sts & USR1_TRDY &&
readl(sport->port.membase + UCR1) & UCR1_TXMPTYEN)
imx_txint(irq, dev_id);
if (sts & USR1_RTSD)
imx_rtsint(irq, dev_id);
if (sts & USR1_AWAKE)
writel(USR1_AWAKE, sport->port.membase + USR1);
sts2 = readl(sport->port.membase + USR2);
if (sts2 & USR2_ORE) {
dev_err(sport->port.dev, "Rx FIFO overrun\n");
sport->port.icount.overrun++;
writel(sts2 | USR2_ORE, sport->port.membase + USR2);
}
return IRQ_HANDLED;
}
static unsigned int imx_tx_empty(struct uart_port *port)
{
struct imx_port *sport = (struct imx_port *)port;
unsigned int ret;
ret = (readl(sport->port.membase + USR2) & USR2_TXDC) ? TIOCSER_TEMT : 0;
if (sport->dma_is_enabled && sport->dma_is_txing)
ret = 0;
return ret;
}
static unsigned int imx_get_mctrl(struct uart_port *port)
{
struct imx_port *sport = (struct imx_port *)port;
unsigned int tmp = TIOCM_DSR | TIOCM_CAR;
if (readl(sport->port.membase + USR1) & USR1_RTSS)
tmp |= TIOCM_CTS;
if (readl(sport->port.membase + UCR2) & UCR2_CTS)
tmp |= TIOCM_RTS;
if (readl(sport->port.membase + uts_reg(sport)) & UTS_LOOP)
tmp |= TIOCM_LOOP;
return tmp;
}
static void imx_set_mctrl(struct uart_port *port, unsigned int mctrl)
{
struct imx_port *sport = (struct imx_port *)port;
unsigned long temp;
temp = readl(sport->port.membase + UCR2) & ~(UCR2_CTS | UCR2_CTSC);
if (mctrl & TIOCM_RTS)
temp |= UCR2_CTS | UCR2_CTSC;
writel(temp, sport->port.membase + UCR2);
temp = readl(sport->port.membase + uts_reg(sport)) & ~UTS_LOOP;
if (mctrl & TIOCM_LOOP)
temp |= UTS_LOOP;
writel(temp, sport->port.membase + uts_reg(sport));
}
static void imx_break_ctl(struct uart_port *port, int break_state)
{
struct imx_port *sport = (struct imx_port *)port;
unsigned long flags, temp;
spin_lock_irqsave(&sport->port.lock, flags);
temp = readl(sport->port.membase + UCR1) & ~UCR1_SNDBRK;
if (break_state != 0)
temp |= UCR1_SNDBRK;
writel(temp, sport->port.membase + UCR1);
spin_unlock_irqrestore(&sport->port.lock, flags);
}
static int imx_setup_ufcr(struct imx_port *sport, unsigned int mode)
{
unsigned int val;
val = readl(sport->port.membase + UFCR) & (UFCR_RFDIV | UFCR_DCEDTE);
val |= TXTL << UFCR_TXTL_SHF | RXTL;
writel(val, sport->port.membase + UFCR);
return 0;
}
static void imx_rx_dma_done(struct imx_port *sport)
{
unsigned long temp;
unsigned long flags;
spin_lock_irqsave(&sport->port.lock, flags);
temp = readl(sport->port.membase + UCR1);
temp |= UCR1_RRDYEN;
writel(temp, sport->port.membase + UCR1);
sport->dma_is_rxing = 0;
if (waitqueue_active(&sport->dma_wait))
wake_up(&sport->dma_wait);
spin_unlock_irqrestore(&sport->port.lock, flags);
}
static void dma_rx_callback(void *data)
{
struct imx_port *sport = data;
struct dma_chan *chan = sport->dma_chan_rx;
struct scatterlist *sgl = &sport->rx_sgl;
struct tty_port *port = &sport->port.state->port;
struct dma_tx_state state;
enum dma_status status;
unsigned int count;
dma_unmap_sg(sport->port.dev, sgl, 1, DMA_FROM_DEVICE);
status = dmaengine_tx_status(chan, (dma_cookie_t)0, &state);
count = RX_BUF_SIZE - state.residue;
dev_dbg(sport->port.dev, "We get %d bytes.\n", count);
if (count) {
if (!(sport->port.ignore_status_mask & URXD_DUMMY_READ))
tty_insert_flip_string(port, sport->rx_buf, count);
tty_flip_buffer_push(port);
start_rx_dma(sport);
} else if (readl(sport->port.membase + USR2) & USR2_RDR) {
start_rx_dma(sport);
} else {
imx_rx_dma_done(sport);
}
}
static int start_rx_dma(struct imx_port *sport)
{
struct scatterlist *sgl = &sport->rx_sgl;
struct dma_chan *chan = sport->dma_chan_rx;
struct device *dev = sport->port.dev;
struct dma_async_tx_descriptor *desc;
int ret;
sg_init_one(sgl, sport->rx_buf, RX_BUF_SIZE);
ret = dma_map_sg(dev, sgl, 1, DMA_FROM_DEVICE);
if (ret == 0) {
dev_err(dev, "DMA mapping error for RX.\n");
return -EINVAL;
}
desc = dmaengine_prep_slave_sg(chan, sgl, 1, DMA_DEV_TO_MEM,
DMA_PREP_INTERRUPT);
if (!desc) {
dma_unmap_sg(dev, sgl, 1, DMA_FROM_DEVICE);
dev_err(dev, "We cannot prepare for the RX slave dma!\n");
return -EINVAL;
}
desc->callback = dma_rx_callback;
desc->callback_param = sport;
dev_dbg(dev, "RX: prepare for the DMA.\n");
dmaengine_submit(desc);
dma_async_issue_pending(chan);
return 0;
}
static void imx_uart_dma_exit(struct imx_port *sport)
{
if (sport->dma_chan_rx) {
dma_release_channel(sport->dma_chan_rx);
sport->dma_chan_rx = NULL;
kfree(sport->rx_buf);
sport->rx_buf = NULL;
}
if (sport->dma_chan_tx) {
dma_release_channel(sport->dma_chan_tx);
sport->dma_chan_tx = NULL;
}
sport->dma_is_inited = 0;
}
static int imx_uart_dma_init(struct imx_port *sport)
{
struct dma_slave_config slave_config = {};
struct device *dev = sport->port.dev;
int ret;
sport->dma_chan_rx = dma_request_slave_channel(dev, "rx");
if (!sport->dma_chan_rx) {
dev_dbg(dev, "cannot get the DMA channel.\n");
ret = -EINVAL;
goto err;
}
slave_config.direction = DMA_DEV_TO_MEM;
slave_config.src_addr = sport->port.mapbase + URXD0;
slave_config.src_addr_width = DMA_SLAVE_BUSWIDTH_1_BYTE;
slave_config.src_maxburst = RXTL;
ret = dmaengine_slave_config(sport->dma_chan_rx, &slave_config);
if (ret) {
dev_err(dev, "error in RX dma configuration.\n");
goto err;
}
sport->rx_buf = kzalloc(PAGE_SIZE, GFP_KERNEL);
if (!sport->rx_buf) {
ret = -ENOMEM;
goto err;
}
sport->dma_chan_tx = dma_request_slave_channel(dev, "tx");
if (!sport->dma_chan_tx) {
dev_err(dev, "cannot get the TX DMA channel!\n");
ret = -EINVAL;
goto err;
}
slave_config.direction = DMA_MEM_TO_DEV;
slave_config.dst_addr = sport->port.mapbase + URTX0;
slave_config.dst_addr_width = DMA_SLAVE_BUSWIDTH_1_BYTE;
slave_config.dst_maxburst = TXTL;
ret = dmaengine_slave_config(sport->dma_chan_tx, &slave_config);
if (ret) {
dev_err(dev, "error in TX dma configuration.");
goto err;
}
sport->dma_is_inited = 1;
return 0;
err:
imx_uart_dma_exit(sport);
return ret;
}
static void imx_enable_dma(struct imx_port *sport)
{
unsigned long temp;
init_waitqueue_head(&sport->dma_wait);
temp = readl(sport->port.membase + UCR1);
temp |= UCR1_RDMAEN | UCR1_TDMAEN | UCR1_ATDMAEN |
UCR1_ICD_REG(3);
writel(temp, sport->port.membase + UCR1);
temp = readl(sport->port.membase + UCR4);
temp |= UCR4_IDDMAEN;
writel(temp, sport->port.membase + UCR4);
sport->dma_is_enabled = 1;
}
static void imx_disable_dma(struct imx_port *sport)
{
unsigned long temp;
temp = readl(sport->port.membase + UCR1);
temp &= ~(UCR1_RDMAEN | UCR1_TDMAEN | UCR1_ATDMAEN);
writel(temp, sport->port.membase + UCR1);
temp = readl(sport->port.membase + UCR2);
temp &= ~(UCR2_CTSC | UCR2_CTS);
writel(temp, sport->port.membase + UCR2);
temp = readl(sport->port.membase + UCR4);
temp &= ~UCR4_IDDMAEN;
writel(temp, sport->port.membase + UCR4);
sport->dma_is_enabled = 0;
}
static int imx_startup(struct uart_port *port)
{
struct imx_port *sport = (struct imx_port *)port;
int retval, i;
unsigned long flags, temp;
retval = clk_prepare_enable(sport->clk_per);
if (retval)
return retval;
retval = clk_prepare_enable(sport->clk_ipg);
if (retval) {
clk_disable_unprepare(sport->clk_per);
return retval;
}
imx_setup_ufcr(sport, 0);
temp = readl(sport->port.membase + UCR4);
if (USE_IRDA(sport))
temp |= UCR4_IRSC;
temp &= ~(UCR4_CTSTL_MASK << UCR4_CTSTL_SHF);
temp |= CTSTL << UCR4_CTSTL_SHF;
writel(temp & ~UCR4_DREN, sport->port.membase + UCR4);
i = 100;
temp = readl(sport->port.membase + UCR2);
temp &= ~UCR2_SRST;
writel(temp, sport->port.membase + UCR2);
while (!(readl(sport->port.membase + UCR2) & UCR2_SRST) && (--i > 0))
udelay(1);
if (is_imx6q_uart(sport) && !uart_console(port) &&
!sport->dma_is_inited)
imx_uart_dma_init(sport);
spin_lock_irqsave(&sport->port.lock, flags);
writel(USR1_RTSD, sport->port.membase + USR1);
if (sport->dma_is_inited && !sport->dma_is_enabled)
imx_enable_dma(sport);
temp = readl(sport->port.membase + UCR1);
temp |= UCR1_RRDYEN | UCR1_RTSDEN | UCR1_UARTEN;
if (USE_IRDA(sport)) {
temp |= UCR1_IREN;
temp &= ~(UCR1_RTSDEN);
}
writel(temp, sport->port.membase + UCR1);
temp = readl(sport->port.membase + USR2);
writel(temp | USR2_ORE, sport->port.membase + USR2);
temp = readl(sport->port.membase + UCR4);
temp |= UCR4_OREN;
writel(temp, sport->port.membase + UCR4);
temp = readl(sport->port.membase + UCR2);
temp |= (UCR2_RXEN | UCR2_TXEN);
if (!sport->have_rtscts)
temp |= UCR2_IRTS;
writel(temp, sport->port.membase + UCR2);
if (!is_imx1_uart(sport)) {
temp = readl(sport->port.membase + UCR3);
temp |= IMX21_UCR3_RXDMUXSEL | UCR3_ADNIMP;
writel(temp, sport->port.membase + UCR3);
}
if (USE_IRDA(sport)) {
temp = readl(sport->port.membase + UCR4);
if (sport->irda_inv_rx)
temp |= UCR4_INVR;
else
temp &= ~(UCR4_INVR);
writel(temp | UCR4_DREN, sport->port.membase + UCR4);
temp = readl(sport->port.membase + UCR3);
if (sport->irda_inv_tx)
temp |= UCR3_INVT;
else
temp &= ~(UCR3_INVT);
writel(temp, sport->port.membase + UCR3);
}
imx_enable_ms(&sport->port);
spin_unlock_irqrestore(&sport->port.lock, flags);
if (USE_IRDA(sport)) {
struct imxuart_platform_data *pdata;
pdata = dev_get_platdata(sport->port.dev);
sport->irda_inv_rx = pdata->irda_inv_rx;
sport->irda_inv_tx = pdata->irda_inv_tx;
sport->trcv_delay = pdata->transceiver_delay;
if (pdata->irda_enable)
pdata->irda_enable(1);
}
return 0;
}
static void imx_shutdown(struct uart_port *port)
{
struct imx_port *sport = (struct imx_port *)port;
unsigned long temp;
unsigned long flags;
if (sport->dma_is_enabled) {
int ret;
ret = wait_event_interruptible(sport->dma_wait,
!sport->dma_is_rxing && !sport->dma_is_txing);
if (ret != 0) {
sport->dma_is_rxing = 0;
sport->dma_is_txing = 0;
dmaengine_terminate_all(sport->dma_chan_tx);
dmaengine_terminate_all(sport->dma_chan_rx);
}
spin_lock_irqsave(&sport->port.lock, flags);
imx_stop_tx(port);
imx_stop_rx(port);
imx_disable_dma(sport);
spin_unlock_irqrestore(&sport->port.lock, flags);
imx_uart_dma_exit(sport);
}
spin_lock_irqsave(&sport->port.lock, flags);
temp = readl(sport->port.membase + UCR2);
temp &= ~(UCR2_TXEN);
writel(temp, sport->port.membase + UCR2);
spin_unlock_irqrestore(&sport->port.lock, flags);
if (USE_IRDA(sport)) {
struct imxuart_platform_data *pdata;
pdata = dev_get_platdata(sport->port.dev);
if (pdata->irda_enable)
pdata->irda_enable(0);
}
del_timer_sync(&sport->timer);
spin_lock_irqsave(&sport->port.lock, flags);
temp = readl(sport->port.membase + UCR1);
temp &= ~(UCR1_TXMPTYEN | UCR1_RRDYEN | UCR1_RTSDEN | UCR1_UARTEN);
if (USE_IRDA(sport))
temp &= ~(UCR1_IREN);
writel(temp, sport->port.membase + UCR1);
spin_unlock_irqrestore(&sport->port.lock, flags);
clk_disable_unprepare(sport->clk_per);
clk_disable_unprepare(sport->clk_ipg);
}
static void imx_flush_buffer(struct uart_port *port)
{
struct imx_port *sport = (struct imx_port *)port;
struct scatterlist *sgl = &sport->tx_sgl[0];
unsigned long temp;
int i = 100, ubir, ubmr, ubrc, uts;
if (!sport->dma_chan_tx)
return;
sport->tx_bytes = 0;
dmaengine_terminate_all(sport->dma_chan_tx);
if (sport->dma_is_txing) {
dma_unmap_sg(sport->port.dev, sgl, sport->dma_tx_nents,
DMA_TO_DEVICE);
temp = readl(sport->port.membase + UCR1);
temp &= ~UCR1_TDMAEN;
writel(temp, sport->port.membase + UCR1);
sport->dma_is_txing = false;
}
ubir = readl(sport->port.membase + UBIR);
ubmr = readl(sport->port.membase + UBMR);
ubrc = readl(sport->port.membase + UBRC);
uts = readl(sport->port.membase + IMX21_UTS);
temp = readl(sport->port.membase + UCR2);
temp &= ~UCR2_SRST;
writel(temp, sport->port.membase + UCR2);
while (!(readl(sport->port.membase + UCR2) & UCR2_SRST) && (--i > 0))
udelay(1);
writel(ubir, sport->port.membase + UBIR);
writel(ubmr, sport->port.membase + UBMR);
writel(ubrc, sport->port.membase + UBRC);
writel(uts, sport->port.membase + IMX21_UTS);
}
static void
imx_set_termios(struct uart_port *port, struct ktermios *termios,
struct ktermios *old)
{
struct imx_port *sport = (struct imx_port *)port;
unsigned long flags;
unsigned int ucr2, old_ucr1, old_txrxen, baud, quot;
unsigned int old_csize = old ? old->c_cflag & CSIZE : CS8;
unsigned int div, ufcr;
unsigned long num, denom;
uint64_t tdiv64;
if (0) {
termios->c_cflag &= ~(HUPCL | CRTSCTS | CMSPAR);
termios->c_cflag |= CLOCAL;
}
while ((termios->c_cflag & CSIZE) != CS7 &&
(termios->c_cflag & CSIZE) != CS8) {
termios->c_cflag &= ~CSIZE;
termios->c_cflag |= old_csize;
old_csize = CS8;
}
if ((termios->c_cflag & CSIZE) == CS8)
ucr2 = UCR2_WS | UCR2_SRST | UCR2_IRTS;
else
ucr2 = UCR2_SRST | UCR2_IRTS;
if (termios->c_cflag & CRTSCTS) {
if (sport->have_rtscts) {
ucr2 &= ~UCR2_IRTS;
ucr2 |= UCR2_CTSC;
} else {
termios->c_cflag &= ~CRTSCTS;
}
}
if (termios->c_cflag & CSTOPB)
ucr2 |= UCR2_STPB;
if (termios->c_cflag & PARENB) {
ucr2 |= UCR2_PREN;
if (termios->c_cflag & PARODD)
ucr2 |= UCR2_PROE;
}
del_timer_sync(&sport->timer);
baud = uart_get_baud_rate(port, termios, old, 50, port->uartclk / 16);
quot = uart_get_divisor(port, baud);
spin_lock_irqsave(&sport->port.lock, flags);
sport->port.read_status_mask = 0;
if (termios->c_iflag & INPCK)
sport->port.read_status_mask |= (URXD_FRMERR | URXD_PRERR);
if (termios->c_iflag & (BRKINT | PARMRK))
sport->port.read_status_mask |= URXD_BRK;
sport->port.ignore_status_mask = 0;
if (termios->c_iflag & IGNPAR)
sport->port.ignore_status_mask |= URXD_PRERR | URXD_FRMERR;
if (termios->c_iflag & IGNBRK) {
sport->port.ignore_status_mask |= URXD_BRK;
if (termios->c_iflag & IGNPAR)
sport->port.ignore_status_mask |= URXD_OVRRUN;
}
if ((termios->c_cflag & CREAD) == 0)
sport->port.ignore_status_mask |= URXD_DUMMY_READ;
uart_update_timeout(port, termios->c_cflag, baud);
old_ucr1 = readl(sport->port.membase + UCR1);
writel(old_ucr1 & ~(UCR1_TXMPTYEN | UCR1_RRDYEN | UCR1_RTSDEN),
sport->port.membase + UCR1);
while (!(readl(sport->port.membase + USR2) & USR2_TXDC))
barrier();
old_txrxen = readl(sport->port.membase + UCR2);
writel(old_txrxen & ~(UCR2_TXEN | UCR2_RXEN),
sport->port.membase + UCR2);
old_txrxen &= (UCR2_TXEN | UCR2_RXEN);
if (USE_IRDA(sport)) {
div = 1;
} else {
div = sport->port.uartclk / (baud * 16);
if (baud == 38400 && quot != div)
baud = sport->port.uartclk / (quot * 16);
div = sport->port.uartclk / (baud * 16);
if (div > 7)
div = 7;
if (!div)
div = 1;
}
rational_best_approximation(16 * div * baud, sport->port.uartclk,
1 << 16, 1 << 16, &num, &denom);
tdiv64 = sport->port.uartclk;
tdiv64 *= num;
do_div(tdiv64, denom * 16 * div);
tty_termios_encode_baud_rate(termios,
(speed_t)tdiv64, (speed_t)tdiv64);
num -= 1;
denom -= 1;
ufcr = readl(sport->port.membase + UFCR);
ufcr = (ufcr & (~UFCR_RFDIV)) | UFCR_RFDIV_REG(div);
if (sport->dte_mode)
ufcr |= UFCR_DCEDTE;
writel(ufcr, sport->port.membase + UFCR);
writel(num, sport->port.membase + UBIR);
writel(denom, sport->port.membase + UBMR);
if (!is_imx1_uart(sport))
writel(sport->port.uartclk / div / 1000,
sport->port.membase + IMX21_ONEMS);
writel(old_ucr1, sport->port.membase + UCR1);
writel(ucr2 | old_txrxen, sport->port.membase + UCR2);
if (UART_ENABLE_MS(&sport->port, termios->c_cflag))
imx_enable_ms(&sport->port);
spin_unlock_irqrestore(&sport->port.lock, flags);
}
static const char *imx_type(struct uart_port *port)
{
struct imx_port *sport = (struct imx_port *)port;
return sport->port.type == PORT_IMX ? "IMX" : NULL;
}
static void imx_config_port(struct uart_port *port, int flags)
{
struct imx_port *sport = (struct imx_port *)port;
if (flags & UART_CONFIG_TYPE)
sport->port.type = PORT_IMX;
}
static int
imx_verify_port(struct uart_port *port, struct serial_struct *ser)
{
struct imx_port *sport = (struct imx_port *)port;
int ret = 0;
if (ser->type != PORT_UNKNOWN && ser->type != PORT_IMX)
ret = -EINVAL;
if (sport->port.irq != ser->irq)
ret = -EINVAL;
if (ser->io_type != UPIO_MEM)
ret = -EINVAL;
if (sport->port.uartclk / 16 != ser->baud_base)
ret = -EINVAL;
if (sport->port.mapbase != (unsigned long)ser->iomem_base)
ret = -EINVAL;
if (sport->port.iobase != ser->port)
ret = -EINVAL;
if (ser->hub6 != 0)
ret = -EINVAL;
return ret;
}
static int imx_poll_init(struct uart_port *port)
{
struct imx_port *sport = (struct imx_port *)port;
unsigned long flags;
unsigned long temp;
int retval;
retval = clk_prepare_enable(sport->clk_ipg);
if (retval)
return retval;
retval = clk_prepare_enable(sport->clk_per);
if (retval)
clk_disable_unprepare(sport->clk_ipg);
imx_setup_ufcr(sport, 0);
spin_lock_irqsave(&sport->port.lock, flags);
temp = readl(sport->port.membase + UCR1);
if (is_imx1_uart(sport))
temp |= IMX1_UCR1_UARTCLKEN;
temp |= UCR1_UARTEN | UCR1_RRDYEN;
temp &= ~(UCR1_TXMPTYEN | UCR1_RTSDEN);
writel(temp, sport->port.membase + UCR1);
temp = readl(sport->port.membase + UCR2);
temp |= UCR2_RXEN;
writel(temp, sport->port.membase + UCR2);
spin_unlock_irqrestore(&sport->port.lock, flags);
return 0;
}
static int imx_poll_get_char(struct uart_port *port)
{
if (!(readl_relaxed(port->membase + USR2) & USR2_RDR))
return NO_POLL_CHAR;
return readl_relaxed(port->membase + URXD0) & URXD_RX_DATA;
}
static void imx_poll_put_char(struct uart_port *port, unsigned char c)
{
unsigned int status;
do {
status = readl_relaxed(port->membase + USR1);
} while (~status & USR1_TRDY);
writel_relaxed(c, port->membase + URTX0);
do {
status = readl_relaxed(port->membase + USR2);
} while (~status & USR2_TXDC);
}
static void imx_console_putchar(struct uart_port *port, int ch)
{
struct imx_port *sport = (struct imx_port *)port;
while (readl(sport->port.membase + uts_reg(sport)) & UTS_TXFULL)
barrier();
writel(ch, sport->port.membase + URTX0);
}
static void
imx_console_write(struct console *co, const char *s, unsigned int count)
{
struct imx_port *sport = imx_ports[co->index];
struct imx_port_ucrs old_ucr;
unsigned int ucr1;
unsigned long flags = 0;
int locked = 1;
int retval;
retval = clk_enable(sport->clk_per);
if (retval)
return;
retval = clk_enable(sport->clk_ipg);
if (retval) {
clk_disable(sport->clk_per);
return;
}
if (sport->port.sysrq)
locked = 0;
else if (oops_in_progress)
locked = spin_trylock_irqsave(&sport->port.lock, flags);
else
spin_lock_irqsave(&sport->port.lock, flags);
imx_port_ucrs_save(&sport->port, &old_ucr);
ucr1 = old_ucr.ucr1;
if (is_imx1_uart(sport))
ucr1 |= IMX1_UCR1_UARTCLKEN;
ucr1 |= UCR1_UARTEN;
ucr1 &= ~(UCR1_TXMPTYEN | UCR1_RRDYEN | UCR1_RTSDEN);
writel(ucr1, sport->port.membase + UCR1);
writel(old_ucr.ucr2 | UCR2_TXEN, sport->port.membase + UCR2);
uart_console_write(&sport->port, s, count, imx_console_putchar);
while (!(readl(sport->port.membase + USR2) & USR2_TXDC));
imx_port_ucrs_restore(&sport->port, &old_ucr);
if (locked)
spin_unlock_irqrestore(&sport->port.lock, flags);
clk_disable(sport->clk_ipg);
clk_disable(sport->clk_per);
}
static void __init
imx_console_get_options(struct imx_port *sport, int *baud,
int *parity, int *bits)
{
if (readl(sport->port.membase + UCR1) & UCR1_UARTEN) {
unsigned int ucr2, ubir, ubmr, uartclk;
unsigned int baud_raw;
unsigned int ucfr_rfdiv;
ucr2 = readl(sport->port.membase + UCR2);
*parity = 'n';
if (ucr2 & UCR2_PREN) {
if (ucr2 & UCR2_PROE)
*parity = 'o';
else
*parity = 'e';
}
if (ucr2 & UCR2_WS)
*bits = 8;
else
*bits = 7;
ubir = readl(sport->port.membase + UBIR) & 0xffff;
ubmr = readl(sport->port.membase + UBMR) & 0xffff;
ucfr_rfdiv = (readl(sport->port.membase + UFCR) & UFCR_RFDIV) >> 7;
if (ucfr_rfdiv == 6)
ucfr_rfdiv = 7;
else
ucfr_rfdiv = 6 - ucfr_rfdiv;
uartclk = clk_get_rate(sport->clk_per);
uartclk /= ucfr_rfdiv;
{
unsigned int mul = ubir + 1;
unsigned int div = 16 * (ubmr + 1);
unsigned int rem = uartclk % div;
baud_raw = (uartclk / div) * mul;
baud_raw += (rem * mul + div / 2) / div;
*baud = (baud_raw + 50) / 100 * 100;
}
if (*baud != baud_raw)
pr_info("Console IMX rounded baud rate from %d to %d\n",
baud_raw, *baud);
}
}
static int __init
imx_console_setup(struct console *co, char *options)
{
struct imx_port *sport;
int baud = 9600;
int bits = 8;
int parity = 'n';
int flow = 'n';
int retval;
if (co->index == -1 || co->index >= ARRAY_SIZE(imx_ports))
co->index = 0;
sport = imx_ports[co->index];
if (sport == NULL)
return -ENODEV;
retval = clk_prepare_enable(sport->clk_ipg);
if (retval)
goto error_console;
if (options)
uart_parse_options(options, &baud, &parity, &bits, &flow);
else
imx_console_get_options(sport, &baud, &parity, &bits);
imx_setup_ufcr(sport, 0);
retval = uart_set_options(&sport->port, co, baud, parity, bits, flow);
clk_disable(sport->clk_ipg);
if (retval) {
clk_unprepare(sport->clk_ipg);
goto error_console;
}
retval = clk_prepare(sport->clk_per);
if (retval)
clk_disable_unprepare(sport->clk_ipg);
error_console:
return retval;
}
static int serial_imx_suspend(struct platform_device *dev, pm_message_t state)
{
struct imx_port *sport = platform_get_drvdata(dev);
unsigned int val;
val = readl(sport->port.membase + UCR3);
val |= UCR3_AWAKEN;
writel(val, sport->port.membase + UCR3);
uart_suspend_port(&imx_reg, &sport->port);
return 0;
}
static int serial_imx_resume(struct platform_device *dev)
{
struct imx_port *sport = platform_get_drvdata(dev);
unsigned int val;
val = readl(sport->port.membase + UCR3);
val &= ~UCR3_AWAKEN;
writel(val, sport->port.membase + UCR3);
uart_resume_port(&imx_reg, &sport->port);
return 0;
}
static int serial_imx_probe_dt(struct imx_port *sport,
struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
const struct of_device_id *of_id =
of_match_device(imx_uart_dt_ids, &pdev->dev);
int ret;
if (!np)
return 1;
ret = of_alias_get_id(np, "serial");
if (ret < 0) {
dev_err(&pdev->dev, "failed to get alias id, errno %d\n", ret);
return ret;
}
sport->port.line = ret;
if (of_get_property(np, "fsl,uart-has-rtscts", NULL))
sport->have_rtscts = 1;
if (of_get_property(np, "fsl,irda-mode", NULL))
sport->use_irda = 1;
if (of_get_property(np, "fsl,dte-mode", NULL))
sport->dte_mode = 1;
sport->devdata = of_id->data;
return 0;
}
static inline int serial_imx_probe_dt(struct imx_port *sport,
struct platform_device *pdev)
{
return 1;
}
static void serial_imx_probe_pdata(struct imx_port *sport,
struct platform_device *pdev)
{
struct imxuart_platform_data *pdata = dev_get_platdata(&pdev->dev);
sport->port.line = pdev->id;
sport->devdata = (struct imx_uart_data *) pdev->id_entry->driver_data;
if (!pdata)
return;
if (pdata->flags & IMXUART_HAVE_RTSCTS)
sport->have_rtscts = 1;
if (pdata->flags & IMXUART_IRDA)
sport->use_irda = 1;
}
static int serial_imx_probe(struct platform_device *pdev)
{
struct imx_port *sport;
void __iomem *base;
int ret = 0;
struct resource *res;
sport = devm_kzalloc(&pdev->dev, sizeof(*sport), GFP_KERNEL);
if (!sport)
return -ENOMEM;
ret = serial_imx_probe_dt(sport, pdev);
if (ret > 0)
serial_imx_probe_pdata(sport, pdev);
else if (ret < 0)
return ret;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(base))
return PTR_ERR(base);
sport->port.dev = &pdev->dev;
sport->port.mapbase = res->start;
sport->port.membase = base;
sport->port.type = PORT_IMX,
sport->port.iotype = UPIO_MEM;
sport->port.irq = platform_get_irq(pdev, 0);
sport->rxirq = platform_get_irq(pdev, 0);
sport->txirq = platform_get_irq(pdev, 1);
sport->rtsirq = platform_get_irq(pdev, 2);
sport->port.fifosize = 32;
sport->port.ops = &imx_pops;
sport->port.flags = UPF_BOOT_AUTOCONF;
init_timer(&sport->timer);
sport->timer.function = imx_timeout;
sport->timer.data = (unsigned long)sport;
sport->clk_ipg = devm_clk_get(&pdev->dev, "ipg");
if (IS_ERR(sport->clk_ipg)) {
ret = PTR_ERR(sport->clk_ipg);
dev_err(&pdev->dev, "failed to get ipg clk: %d\n", ret);
return ret;
}
sport->clk_per = devm_clk_get(&pdev->dev, "per");
if (IS_ERR(sport->clk_per)) {
ret = PTR_ERR(sport->clk_per);
dev_err(&pdev->dev, "failed to get per clk: %d\n", ret);
return ret;
}
sport->port.uartclk = clk_get_rate(sport->clk_per);
if (sport->txirq > 0) {
ret = devm_request_irq(&pdev->dev, sport->rxirq, imx_rxint, 0,
dev_name(&pdev->dev), sport);
if (ret)
return ret;
ret = devm_request_irq(&pdev->dev, sport->txirq, imx_txint, 0,
dev_name(&pdev->dev), sport);
if (ret)
return ret;
if (!USE_IRDA(sport)) {
ret = devm_request_irq(&pdev->dev, sport->rtsirq,
imx_rtsint, 0,
dev_name(&pdev->dev), sport);
if (ret)
return ret;
}
} else {
ret = devm_request_irq(&pdev->dev, sport->port.irq, imx_int, 0,
dev_name(&pdev->dev), sport);
if (ret)
return ret;
}
imx_ports[sport->port.line] = sport;
platform_set_drvdata(pdev, sport);
return uart_add_one_port(&imx_reg, &sport->port);
}
static int serial_imx_remove(struct platform_device *pdev)
{
struct imx_port *sport = platform_get_drvdata(pdev);
return uart_remove_one_port(&imx_reg, &sport->port);
}
static int __init imx_serial_init(void)
{
int ret = uart_register_driver(&imx_reg);
if (ret)
return ret;
ret = platform_driver_register(&serial_imx_driver);
if (ret != 0)
uart_unregister_driver(&imx_reg);
return ret;
}
static void __exit imx_serial_exit(void)
{
platform_driver_unregister(&serial_imx_driver);
uart_unregister_driver(&imx_reg);
}
