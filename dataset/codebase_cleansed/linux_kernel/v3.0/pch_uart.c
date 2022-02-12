static void pch_uart_hal_request(struct pci_dev *pdev, int fifosize,
int base_baud)
{
struct eg20t_port *priv = pci_get_drvdata(pdev);
priv->trigger_level = 1;
priv->fcr = 0;
}
static unsigned int get_msr(struct eg20t_port *priv, void __iomem *base)
{
unsigned int msr = ioread8(base + UART_MSR);
priv->dmsr |= msr & PCH_UART_MSR_DELTA;
return msr;
}
static void pch_uart_hal_enable_interrupt(struct eg20t_port *priv,
unsigned int flag)
{
u8 ier = ioread8(priv->membase + UART_IER);
ier |= flag & PCH_UART_IER_MASK;
iowrite8(ier, priv->membase + UART_IER);
}
static void pch_uart_hal_disable_interrupt(struct eg20t_port *priv,
unsigned int flag)
{
u8 ier = ioread8(priv->membase + UART_IER);
ier &= ~(flag & PCH_UART_IER_MASK);
iowrite8(ier, priv->membase + UART_IER);
}
static int pch_uart_hal_set_line(struct eg20t_port *priv, int baud,
unsigned int parity, unsigned int bits,
unsigned int stb)
{
unsigned int dll, dlm, lcr;
int div;
div = DIV_ROUND(priv->base_baud / 16, baud);
if (div < 0 || USHRT_MAX <= div) {
dev_err(priv->port.dev, "Invalid Baud(div=0x%x)\n", div);
return -EINVAL;
}
dll = (unsigned int)div & 0x00FFU;
dlm = ((unsigned int)div >> 8) & 0x00FFU;
if (parity & ~(PCH_UART_LCR_PEN | PCH_UART_LCR_EPS | PCH_UART_LCR_SP)) {
dev_err(priv->port.dev, "Invalid parity(0x%x)\n", parity);
return -EINVAL;
}
if (bits & ~PCH_UART_LCR_WLS) {
dev_err(priv->port.dev, "Invalid bits(0x%x)\n", bits);
return -EINVAL;
}
if (stb & ~PCH_UART_LCR_STB) {
dev_err(priv->port.dev, "Invalid STB(0x%x)\n", stb);
return -EINVAL;
}
lcr = parity;
lcr |= bits;
lcr |= stb;
dev_dbg(priv->port.dev, "%s:baud = %d, div = %04x, lcr = %02x (%lu)\n",
__func__, baud, div, lcr, jiffies);
iowrite8(PCH_UART_LCR_DLAB, priv->membase + UART_LCR);
iowrite8(dll, priv->membase + PCH_UART_DLL);
iowrite8(dlm, priv->membase + PCH_UART_DLM);
iowrite8(lcr, priv->membase + UART_LCR);
return 0;
}
static int pch_uart_hal_fifo_reset(struct eg20t_port *priv,
unsigned int flag)
{
if (flag & ~(PCH_UART_FCR_TFR | PCH_UART_FCR_RFR)) {
dev_err(priv->port.dev, "%s:Invalid flag(0x%x)\n",
__func__, flag);
return -EINVAL;
}
iowrite8(PCH_UART_FCR_FIFOE | priv->fcr, priv->membase + UART_FCR);
iowrite8(PCH_UART_FCR_FIFOE | priv->fcr | flag,
priv->membase + UART_FCR);
iowrite8(priv->fcr, priv->membase + UART_FCR);
return 0;
}
static int pch_uart_hal_set_fifo(struct eg20t_port *priv,
unsigned int dmamode,
unsigned int fifo_size, unsigned int trigger)
{
u8 fcr;
if (dmamode & ~PCH_UART_FCR_DMS) {
dev_err(priv->port.dev, "%s:Invalid DMA Mode(0x%x)\n",
__func__, dmamode);
return -EINVAL;
}
if (fifo_size & ~(PCH_UART_FCR_FIFOE | PCH_UART_FCR_FIFO256)) {
dev_err(priv->port.dev, "%s:Invalid FIFO SIZE(0x%x)\n",
__func__, fifo_size);
return -EINVAL;
}
if (trigger & ~PCH_UART_FCR_RFTL) {
dev_err(priv->port.dev, "%s:Invalid TRIGGER(0x%x)\n",
__func__, trigger);
return -EINVAL;
}
switch (priv->fifo_size) {
case 256:
priv->trigger_level =
trigger_level_256[trigger >> PCH_UART_FCR_RFTL_SHIFT];
break;
case 64:
priv->trigger_level =
trigger_level_64[trigger >> PCH_UART_FCR_RFTL_SHIFT];
break;
case 16:
priv->trigger_level =
trigger_level_16[trigger >> PCH_UART_FCR_RFTL_SHIFT];
break;
default:
priv->trigger_level =
trigger_level_1[trigger >> PCH_UART_FCR_RFTL_SHIFT];
break;
}
fcr =
dmamode | fifo_size | trigger | PCH_UART_FCR_RFR | PCH_UART_FCR_TFR;
iowrite8(PCH_UART_FCR_FIFOE, priv->membase + UART_FCR);
iowrite8(PCH_UART_FCR_FIFOE | PCH_UART_FCR_RFR | PCH_UART_FCR_TFR,
priv->membase + UART_FCR);
iowrite8(fcr, priv->membase + UART_FCR);
priv->fcr = fcr;
return 0;
}
static u8 pch_uart_hal_get_modem(struct eg20t_port *priv)
{
priv->dmsr = 0;
return get_msr(priv, priv->membase);
}
static void pch_uart_hal_write(struct eg20t_port *priv,
const unsigned char *buf, int tx_size)
{
int i;
unsigned int thr;
for (i = 0; i < tx_size;) {
thr = buf[i++];
iowrite8(thr, priv->membase + PCH_UART_THR);
}
}
static int pch_uart_hal_read(struct eg20t_port *priv, unsigned char *buf,
int rx_size)
{
int i;
u8 rbr, lsr;
lsr = ioread8(priv->membase + UART_LSR);
for (i = 0, lsr = ioread8(priv->membase + UART_LSR);
i < rx_size && lsr & UART_LSR_DR;
lsr = ioread8(priv->membase + UART_LSR)) {
rbr = ioread8(priv->membase + PCH_UART_RBR);
buf[i++] = rbr;
}
return i;
}
static unsigned int pch_uart_hal_get_iid(struct eg20t_port *priv)
{
unsigned int iir;
int ret;
iir = ioread8(priv->membase + UART_IIR);
ret = (iir & (PCH_UART_IIR_IID | PCH_UART_IIR_TOI | PCH_UART_IIR_IP));
return ret;
}
static u8 pch_uart_hal_get_line_status(struct eg20t_port *priv)
{
return ioread8(priv->membase + UART_LSR);
}
static void pch_uart_hal_set_break(struct eg20t_port *priv, int on)
{
unsigned int lcr;
lcr = ioread8(priv->membase + UART_LCR);
if (on)
lcr |= PCH_UART_LCR_SB;
else
lcr &= ~PCH_UART_LCR_SB;
iowrite8(lcr, priv->membase + UART_LCR);
}
static int push_rx(struct eg20t_port *priv, const unsigned char *buf,
int size)
{
struct uart_port *port;
struct tty_struct *tty;
port = &priv->port;
tty = tty_port_tty_get(&port->state->port);
if (!tty) {
dev_dbg(priv->port.dev, "%s:tty is busy now", __func__);
return -EBUSY;
}
tty_insert_flip_string(tty, buf, size);
tty_flip_buffer_push(tty);
tty_kref_put(tty);
return 0;
}
static int pop_tx_x(struct eg20t_port *priv, unsigned char *buf)
{
int ret;
struct uart_port *port = &priv->port;
if (port->x_char) {
dev_dbg(priv->port.dev, "%s:X character send %02x (%lu)\n",
__func__, port->x_char, jiffies);
buf[0] = port->x_char;
port->x_char = 0;
ret = 1;
} else {
ret = 0;
}
return ret;
}
static int dma_push_rx(struct eg20t_port *priv, int size)
{
struct tty_struct *tty;
int room;
struct uart_port *port = &priv->port;
port = &priv->port;
tty = tty_port_tty_get(&port->state->port);
if (!tty) {
dev_dbg(priv->port.dev, "%s:tty is busy now", __func__);
return 0;
}
room = tty_buffer_request_room(tty, size);
if (room < size)
dev_warn(port->dev, "Rx overrun: dropping %u bytes\n",
size - room);
if (!room)
return room;
tty_insert_flip_string(tty, sg_virt(&priv->sg_rx), size);
port->icount.rx += room;
tty_kref_put(tty);
return room;
}
static void pch_free_dma(struct uart_port *port)
{
struct eg20t_port *priv;
priv = container_of(port, struct eg20t_port, port);
if (priv->chan_tx) {
dma_release_channel(priv->chan_tx);
priv->chan_tx = NULL;
}
if (priv->chan_rx) {
dma_release_channel(priv->chan_rx);
priv->chan_rx = NULL;
}
if (sg_dma_address(&priv->sg_rx))
dma_free_coherent(port->dev, port->fifosize,
sg_virt(&priv->sg_rx),
sg_dma_address(&priv->sg_rx));
return;
}
static bool filter(struct dma_chan *chan, void *slave)
{
struct pch_dma_slave *param = slave;
if ((chan->chan_id == param->chan_id) && (param->dma_dev ==
chan->device->dev)) {
chan->private = param;
return true;
} else {
return false;
}
}
static void pch_request_dma(struct uart_port *port)
{
dma_cap_mask_t mask;
struct dma_chan *chan;
struct pci_dev *dma_dev;
struct pch_dma_slave *param;
struct eg20t_port *priv =
container_of(port, struct eg20t_port, port);
dma_cap_zero(mask);
dma_cap_set(DMA_SLAVE, mask);
dma_dev = pci_get_bus_and_slot(2, PCI_DEVFN(0xa, 0));
param = &priv->param_tx;
param->dma_dev = &dma_dev->dev;
param->chan_id = priv->port.line * 2;
param->tx_reg = port->mapbase + UART_TX;
chan = dma_request_channel(mask, filter, param);
if (!chan) {
dev_err(priv->port.dev, "%s:dma_request_channel FAILS(Tx)\n",
__func__);
return;
}
priv->chan_tx = chan;
param = &priv->param_rx;
param->dma_dev = &dma_dev->dev;
param->chan_id = priv->port.line * 2 + 1;
param->rx_reg = port->mapbase + UART_RX;
chan = dma_request_channel(mask, filter, param);
if (!chan) {
dev_err(priv->port.dev, "%s:dma_request_channel FAILS(Rx)\n",
__func__);
dma_release_channel(priv->chan_tx);
return;
}
priv->rx_buf_virt = dma_alloc_coherent(port->dev, port->fifosize,
&priv->rx_buf_dma, GFP_KERNEL);
priv->chan_rx = chan;
}
static void pch_dma_rx_complete(void *arg)
{
struct eg20t_port *priv = arg;
struct uart_port *port = &priv->port;
struct tty_struct *tty = tty_port_tty_get(&port->state->port);
int count;
if (!tty) {
dev_dbg(priv->port.dev, "%s:tty is busy now", __func__);
return;
}
dma_sync_sg_for_cpu(port->dev, &priv->sg_rx, 1, DMA_FROM_DEVICE);
count = dma_push_rx(priv, priv->trigger_level);
if (count)
tty_flip_buffer_push(tty);
tty_kref_put(tty);
async_tx_ack(priv->desc_rx);
pch_uart_hal_enable_interrupt(priv, PCH_UART_HAL_RX_INT);
}
static void pch_dma_tx_complete(void *arg)
{
struct eg20t_port *priv = arg;
struct uart_port *port = &priv->port;
struct circ_buf *xmit = &port->state->xmit;
struct scatterlist *sg = priv->sg_tx_p;
int i;
for (i = 0; i < priv->nent; i++, sg++) {
xmit->tail += sg_dma_len(sg);
port->icount.tx += sg_dma_len(sg);
}
xmit->tail &= UART_XMIT_SIZE - 1;
async_tx_ack(priv->desc_tx);
dma_unmap_sg(port->dev, sg, priv->nent, DMA_TO_DEVICE);
priv->tx_dma_use = 0;
priv->nent = 0;
kfree(priv->sg_tx_p);
pch_uart_hal_enable_interrupt(priv, PCH_UART_HAL_TX_INT);
}
static int pop_tx(struct eg20t_port *priv, int size)
{
int count = 0;
struct uart_port *port = &priv->port;
struct circ_buf *xmit = &port->state->xmit;
if (uart_tx_stopped(port) || uart_circ_empty(xmit) || count >= size)
goto pop_tx_end;
do {
int cnt_to_end =
CIRC_CNT_TO_END(xmit->head, xmit->tail, UART_XMIT_SIZE);
int sz = min(size - count, cnt_to_end);
pch_uart_hal_write(priv, &xmit->buf[xmit->tail], sz);
xmit->tail = (xmit->tail + sz) & (UART_XMIT_SIZE - 1);
count += sz;
} while (!uart_circ_empty(xmit) && count < size);
pop_tx_end:
dev_dbg(priv->port.dev, "%d characters. Remained %d characters.(%lu)\n",
count, size - count, jiffies);
return count;
}
static int handle_rx_to(struct eg20t_port *priv)
{
struct pch_uart_buffer *buf;
int rx_size;
int ret;
if (!priv->start_rx) {
pch_uart_hal_disable_interrupt(priv, PCH_UART_HAL_RX_INT);
return 0;
}
buf = &priv->rxbuf;
do {
rx_size = pch_uart_hal_read(priv, buf->buf, buf->size);
ret = push_rx(priv, buf->buf, rx_size);
if (ret)
return 0;
} while (rx_size == buf->size);
return PCH_UART_HANDLED_RX_INT;
}
static int handle_rx(struct eg20t_port *priv)
{
return handle_rx_to(priv);
}
static int dma_handle_rx(struct eg20t_port *priv)
{
struct uart_port *port = &priv->port;
struct dma_async_tx_descriptor *desc;
struct scatterlist *sg;
priv = container_of(port, struct eg20t_port, port);
sg = &priv->sg_rx;
sg_init_table(&priv->sg_rx, 1);
sg_dma_len(sg) = priv->trigger_level;
sg_set_page(&priv->sg_rx, virt_to_page(priv->rx_buf_virt),
sg_dma_len(sg), (unsigned long)priv->rx_buf_virt &
~PAGE_MASK);
sg_dma_address(sg) = priv->rx_buf_dma;
desc = priv->chan_rx->device->device_prep_slave_sg(priv->chan_rx,
sg, 1, DMA_FROM_DEVICE,
DMA_PREP_INTERRUPT | DMA_CTRL_ACK);
if (!desc)
return 0;
priv->desc_rx = desc;
desc->callback = pch_dma_rx_complete;
desc->callback_param = priv;
desc->tx_submit(desc);
dma_async_issue_pending(priv->chan_rx);
return PCH_UART_HANDLED_RX_INT;
}
static unsigned int handle_tx(struct eg20t_port *priv)
{
struct uart_port *port = &priv->port;
struct circ_buf *xmit = &port->state->xmit;
int fifo_size;
int tx_size;
int size;
int tx_empty;
if (!priv->start_tx) {
dev_info(priv->port.dev, "%s:Tx isn't started. (%lu)\n",
__func__, jiffies);
pch_uart_hal_disable_interrupt(priv, PCH_UART_HAL_TX_INT);
priv->tx_empty = 1;
return 0;
}
fifo_size = max(priv->fifo_size, 1);
tx_empty = 1;
if (pop_tx_x(priv, xmit->buf)) {
pch_uart_hal_write(priv, xmit->buf, 1);
port->icount.tx++;
tx_empty = 0;
fifo_size--;
}
size = min(xmit->head - xmit->tail, fifo_size);
if (size < 0)
size = fifo_size;
tx_size = pop_tx(priv, size);
if (tx_size > 0) {
port->icount.tx += tx_size;
tx_empty = 0;
}
priv->tx_empty = tx_empty;
if (tx_empty) {
pch_uart_hal_disable_interrupt(priv, PCH_UART_HAL_TX_INT);
uart_write_wakeup(port);
}
return PCH_UART_HANDLED_TX_INT;
}
static unsigned int dma_handle_tx(struct eg20t_port *priv)
{
struct uart_port *port = &priv->port;
struct circ_buf *xmit = &port->state->xmit;
struct scatterlist *sg;
int nent;
int fifo_size;
int tx_empty;
struct dma_async_tx_descriptor *desc;
int num;
int i;
int bytes;
int size;
int rem;
if (!priv->start_tx) {
dev_info(priv->port.dev, "%s:Tx isn't started. (%lu)\n",
__func__, jiffies);
pch_uart_hal_disable_interrupt(priv, PCH_UART_HAL_TX_INT);
priv->tx_empty = 1;
return 0;
}
if (priv->tx_dma_use) {
dev_dbg(priv->port.dev, "%s:Tx is not completed. (%lu)\n",
__func__, jiffies);
pch_uart_hal_disable_interrupt(priv, PCH_UART_HAL_TX_INT);
priv->tx_empty = 1;
return 0;
}
fifo_size = max(priv->fifo_size, 1);
tx_empty = 1;
if (pop_tx_x(priv, xmit->buf)) {
pch_uart_hal_write(priv, xmit->buf, 1);
port->icount.tx++;
tx_empty = 0;
fifo_size--;
}
bytes = min((int)CIRC_CNT(xmit->head, xmit->tail,
UART_XMIT_SIZE), CIRC_CNT_TO_END(xmit->head,
xmit->tail, UART_XMIT_SIZE));
if (!bytes) {
dev_dbg(priv->port.dev, "%s 0 bytes return\n", __func__);
pch_uart_hal_disable_interrupt(priv, PCH_UART_HAL_TX_INT);
uart_write_wakeup(port);
return 0;
}
if (bytes > fifo_size) {
num = bytes / fifo_size + 1;
size = fifo_size;
rem = bytes % fifo_size;
} else {
num = 1;
size = bytes;
rem = bytes;
}
dev_dbg(priv->port.dev, "%s num=%d size=%d rem=%d\n",
__func__, num, size, rem);
priv->tx_dma_use = 1;
priv->sg_tx_p = kzalloc(sizeof(struct scatterlist)*num, GFP_ATOMIC);
sg_init_table(priv->sg_tx_p, num);
sg = priv->sg_tx_p;
for (i = 0; i < num; i++, sg++) {
if (i == (num - 1))
sg_set_page(sg, virt_to_page(xmit->buf),
rem, fifo_size * i);
else
sg_set_page(sg, virt_to_page(xmit->buf),
size, fifo_size * i);
}
sg = priv->sg_tx_p;
nent = dma_map_sg(port->dev, sg, num, DMA_TO_DEVICE);
if (!nent) {
dev_err(priv->port.dev, "%s:dma_map_sg Failed\n", __func__);
return 0;
}
priv->nent = nent;
for (i = 0; i < nent; i++, sg++) {
sg->offset = (xmit->tail & (UART_XMIT_SIZE - 1)) +
fifo_size * i;
sg_dma_address(sg) = (sg_dma_address(sg) &
~(UART_XMIT_SIZE - 1)) + sg->offset;
if (i == (nent - 1))
sg_dma_len(sg) = rem;
else
sg_dma_len(sg) = size;
}
desc = priv->chan_tx->device->device_prep_slave_sg(priv->chan_tx,
priv->sg_tx_p, nent, DMA_TO_DEVICE,
DMA_PREP_INTERRUPT | DMA_CTRL_ACK);
if (!desc) {
dev_err(priv->port.dev, "%s:device_prep_slave_sg Failed\n",
__func__);
return 0;
}
dma_sync_sg_for_device(port->dev, priv->sg_tx_p, nent, DMA_TO_DEVICE);
priv->desc_tx = desc;
desc->callback = pch_dma_tx_complete;
desc->callback_param = priv;
desc->tx_submit(desc);
dma_async_issue_pending(priv->chan_tx);
return PCH_UART_HANDLED_TX_INT;
}
static void pch_uart_err_ir(struct eg20t_port *priv, unsigned int lsr)
{
u8 fcr = ioread8(priv->membase + UART_FCR);
fcr |= UART_FCR_CLEAR_RCVR;
iowrite8(fcr, priv->membase + UART_FCR);
if (lsr & PCH_UART_LSR_ERR)
dev_err(&priv->pdev->dev, "Error data in FIFO\n");
if (lsr & UART_LSR_FE)
dev_err(&priv->pdev->dev, "Framing Error\n");
if (lsr & UART_LSR_PE)
dev_err(&priv->pdev->dev, "Parity Error\n");
if (lsr & UART_LSR_OE)
dev_err(&priv->pdev->dev, "Overrun Error\n");
}
static irqreturn_t pch_uart_interrupt(int irq, void *dev_id)
{
struct eg20t_port *priv = dev_id;
unsigned int handled;
u8 lsr;
int ret = 0;
unsigned int iid;
unsigned long flags;
spin_lock_irqsave(&priv->port.lock, flags);
handled = 0;
while ((iid = pch_uart_hal_get_iid(priv)) > 1) {
switch (iid) {
case PCH_UART_IID_RLS:
lsr = pch_uart_hal_get_line_status(priv);
if (lsr & (PCH_UART_LSR_ERR | UART_LSR_FE |
UART_LSR_PE | UART_LSR_OE)) {
pch_uart_err_ir(priv, lsr);
ret = PCH_UART_HANDLED_RX_ERR_INT;
}
break;
case PCH_UART_IID_RDR:
if (priv->use_dma) {
pch_uart_hal_disable_interrupt(priv,
PCH_UART_HAL_RX_INT);
ret = dma_handle_rx(priv);
if (!ret)
pch_uart_hal_enable_interrupt(priv,
PCH_UART_HAL_RX_INT);
} else {
ret = handle_rx(priv);
}
break;
case PCH_UART_IID_RDR_TO:
ret = handle_rx_to(priv);
break;
case PCH_UART_IID_THRE:
if (priv->use_dma)
ret = dma_handle_tx(priv);
else
ret = handle_tx(priv);
break;
case PCH_UART_IID_MS:
ret = PCH_UART_HANDLED_MS_INT;
break;
default:
dev_err(priv->port.dev, "%s:iid=%d (%lu)\n", __func__,
iid, jiffies);
ret = -1;
break;
}
handled |= (unsigned int)ret;
}
if (handled == 0 && iid <= 1) {
if (priv->int_dis_flag)
priv->int_dis_flag = 0;
}
spin_unlock_irqrestore(&priv->port.lock, flags);
return IRQ_RETVAL(handled);
}
static unsigned int pch_uart_tx_empty(struct uart_port *port)
{
struct eg20t_port *priv;
int ret;
priv = container_of(port, struct eg20t_port, port);
if (priv->tx_empty)
ret = TIOCSER_TEMT;
else
ret = 0;
return ret;
}
static unsigned int pch_uart_get_mctrl(struct uart_port *port)
{
struct eg20t_port *priv;
u8 modem;
unsigned int ret = 0;
priv = container_of(port, struct eg20t_port, port);
modem = pch_uart_hal_get_modem(priv);
if (modem & UART_MSR_DCD)
ret |= TIOCM_CAR;
if (modem & UART_MSR_RI)
ret |= TIOCM_RNG;
if (modem & UART_MSR_DSR)
ret |= TIOCM_DSR;
if (modem & UART_MSR_CTS)
ret |= TIOCM_CTS;
return ret;
}
static void pch_uart_set_mctrl(struct uart_port *port, unsigned int mctrl)
{
u32 mcr = 0;
struct eg20t_port *priv = container_of(port, struct eg20t_port, port);
if (mctrl & TIOCM_DTR)
mcr |= UART_MCR_DTR;
if (mctrl & TIOCM_RTS)
mcr |= UART_MCR_RTS;
if (mctrl & TIOCM_LOOP)
mcr |= UART_MCR_LOOP;
if (priv->mcr & UART_MCR_AFE)
mcr |= UART_MCR_AFE;
if (mctrl)
iowrite8(mcr, priv->membase + UART_MCR);
}
static void pch_uart_stop_tx(struct uart_port *port)
{
struct eg20t_port *priv;
priv = container_of(port, struct eg20t_port, port);
priv->start_tx = 0;
priv->tx_dma_use = 0;
}
static void pch_uart_start_tx(struct uart_port *port)
{
struct eg20t_port *priv;
priv = container_of(port, struct eg20t_port, port);
if (priv->use_dma) {
if (priv->tx_dma_use) {
dev_dbg(priv->port.dev, "%s : Tx DMA is NOT empty.\n",
__func__);
return;
}
}
priv->start_tx = 1;
pch_uart_hal_enable_interrupt(priv, PCH_UART_HAL_TX_INT);
}
static void pch_uart_stop_rx(struct uart_port *port)
{
struct eg20t_port *priv;
priv = container_of(port, struct eg20t_port, port);
priv->start_rx = 0;
pch_uart_hal_disable_interrupt(priv, PCH_UART_HAL_RX_INT);
priv->int_dis_flag = 1;
}
static void pch_uart_enable_ms(struct uart_port *port)
{
struct eg20t_port *priv;
priv = container_of(port, struct eg20t_port, port);
pch_uart_hal_enable_interrupt(priv, PCH_UART_HAL_MS_INT);
}
static void pch_uart_break_ctl(struct uart_port *port, int ctl)
{
struct eg20t_port *priv;
unsigned long flags;
priv = container_of(port, struct eg20t_port, port);
spin_lock_irqsave(&port->lock, flags);
pch_uart_hal_set_break(priv, ctl);
spin_unlock_irqrestore(&port->lock, flags);
}
static int pch_uart_startup(struct uart_port *port)
{
struct eg20t_port *priv;
int ret;
int fifo_size;
int trigger_level;
priv = container_of(port, struct eg20t_port, port);
priv->tx_empty = 1;
if (port->uartclk)
priv->base_baud = port->uartclk;
else
port->uartclk = priv->base_baud;
pch_uart_hal_disable_interrupt(priv, PCH_UART_HAL_ALL_INT);
ret = pch_uart_hal_set_line(priv, default_baud,
PCH_UART_HAL_PARITY_NONE, PCH_UART_HAL_8BIT,
PCH_UART_HAL_STB1);
if (ret)
return ret;
switch (priv->fifo_size) {
case 256:
fifo_size = PCH_UART_HAL_FIFO256;
break;
case 64:
fifo_size = PCH_UART_HAL_FIFO64;
break;
case 16:
fifo_size = PCH_UART_HAL_FIFO16;
case 1:
default:
fifo_size = PCH_UART_HAL_FIFO_DIS;
break;
}
switch (priv->trigger) {
case PCH_UART_HAL_TRIGGER1:
trigger_level = 1;
break;
case PCH_UART_HAL_TRIGGER_L:
trigger_level = priv->fifo_size / 4;
break;
case PCH_UART_HAL_TRIGGER_M:
trigger_level = priv->fifo_size / 2;
break;
case PCH_UART_HAL_TRIGGER_H:
default:
trigger_level = priv->fifo_size - (priv->fifo_size / 8);
break;
}
priv->trigger_level = trigger_level;
ret = pch_uart_hal_set_fifo(priv, PCH_UART_HAL_DMA_MODE0,
fifo_size, priv->trigger);
if (ret < 0)
return ret;
ret = request_irq(priv->port.irq, pch_uart_interrupt, IRQF_SHARED,
KBUILD_MODNAME, priv);
if (ret < 0)
return ret;
if (priv->use_dma)
pch_request_dma(port);
priv->start_rx = 1;
pch_uart_hal_enable_interrupt(priv, PCH_UART_HAL_RX_INT);
uart_update_timeout(port, CS8, default_baud);
return 0;
}
static void pch_uart_shutdown(struct uart_port *port)
{
struct eg20t_port *priv;
int ret;
priv = container_of(port, struct eg20t_port, port);
pch_uart_hal_disable_interrupt(priv, PCH_UART_HAL_ALL_INT);
pch_uart_hal_fifo_reset(priv, PCH_UART_HAL_CLR_ALL_FIFO);
ret = pch_uart_hal_set_fifo(priv, PCH_UART_HAL_DMA_MODE0,
PCH_UART_HAL_FIFO_DIS, PCH_UART_HAL_TRIGGER1);
if (ret)
dev_err(priv->port.dev,
"pch_uart_hal_set_fifo Failed(ret=%d)\n", ret);
if (priv->use_dma_flag)
pch_free_dma(port);
free_irq(priv->port.irq, priv);
}
static void pch_uart_set_termios(struct uart_port *port,
struct ktermios *termios, struct ktermios *old)
{
int baud;
int rtn;
unsigned int parity, bits, stb;
struct eg20t_port *priv;
unsigned long flags;
priv = container_of(port, struct eg20t_port, port);
switch (termios->c_cflag & CSIZE) {
case CS5:
bits = PCH_UART_HAL_5BIT;
break;
case CS6:
bits = PCH_UART_HAL_6BIT;
break;
case CS7:
bits = PCH_UART_HAL_7BIT;
break;
default:
bits = PCH_UART_HAL_8BIT;
break;
}
if (termios->c_cflag & CSTOPB)
stb = PCH_UART_HAL_STB2;
else
stb = PCH_UART_HAL_STB1;
if (termios->c_cflag & PARENB) {
if (!(termios->c_cflag & PARODD))
parity = PCH_UART_HAL_PARITY_ODD;
else
parity = PCH_UART_HAL_PARITY_EVEN;
} else {
parity = PCH_UART_HAL_PARITY_NONE;
}
if ((termios->c_cflag & CRTSCTS) && (priv->fifo_size == 256))
priv->mcr |= UART_MCR_AFE;
else
priv->mcr &= ~UART_MCR_AFE;
termios->c_cflag &= ~CMSPAR;
baud = uart_get_baud_rate(port, termios, old, 0, port->uartclk / 16);
spin_lock_irqsave(&port->lock, flags);
uart_update_timeout(port, termios->c_cflag, baud);
rtn = pch_uart_hal_set_line(priv, baud, parity, bits, stb);
if (rtn)
goto out;
if (tty_termios_baud_rate(termios))
tty_termios_encode_baud_rate(termios, baud, baud);
out:
spin_unlock_irqrestore(&port->lock, flags);
}
static const char *pch_uart_type(struct uart_port *port)
{
return KBUILD_MODNAME;
}
static void pch_uart_release_port(struct uart_port *port)
{
struct eg20t_port *priv;
priv = container_of(port, struct eg20t_port, port);
pci_iounmap(priv->pdev, priv->membase);
pci_release_regions(priv->pdev);
}
static int pch_uart_request_port(struct uart_port *port)
{
struct eg20t_port *priv;
int ret;
void __iomem *membase;
priv = container_of(port, struct eg20t_port, port);
ret = pci_request_regions(priv->pdev, KBUILD_MODNAME);
if (ret < 0)
return -EBUSY;
membase = pci_iomap(priv->pdev, 1, 0);
if (!membase) {
pci_release_regions(priv->pdev);
return -EBUSY;
}
priv->membase = port->membase = membase;
return 0;
}
static void pch_uart_config_port(struct uart_port *port, int type)
{
struct eg20t_port *priv;
priv = container_of(port, struct eg20t_port, port);
if (type & UART_CONFIG_TYPE) {
port->type = priv->port_type;
pch_uart_request_port(port);
}
}
static int pch_uart_verify_port(struct uart_port *port,
struct serial_struct *serinfo)
{
struct eg20t_port *priv;
priv = container_of(port, struct eg20t_port, port);
if (serinfo->flags & UPF_LOW_LATENCY) {
dev_info(priv->port.dev,
"PCH UART : Use PIO Mode (without DMA)\n");
priv->use_dma = 0;
serinfo->flags &= ~UPF_LOW_LATENCY;
} else {
#ifndef CONFIG_PCH_DMA
dev_err(priv->port.dev, "%s : PCH DMA is not Loaded.\n",
__func__);
return -EOPNOTSUPP;
#endif
priv->use_dma = 1;
priv->use_dma_flag = 1;
dev_info(priv->port.dev, "PCH UART : Use DMA Mode\n");
}
return 0;
}
static struct eg20t_port *pch_uart_init_port(struct pci_dev *pdev,
const struct pci_device_id *id)
{
struct eg20t_port *priv;
int ret;
unsigned int iobase;
unsigned int mapbase;
unsigned char *rxbuf;
int fifosize, base_baud;
int port_type;
struct pch_uart_driver_data *board;
const char *board_name;
board = &drv_dat[id->driver_data];
port_type = board->port_type;
priv = kzalloc(sizeof(struct eg20t_port), GFP_KERNEL);
if (priv == NULL)
goto init_port_alloc_err;
rxbuf = (unsigned char *)__get_free_page(GFP_KERNEL);
if (!rxbuf)
goto init_port_free_txbuf;
base_baud = 1843200;
board_name = dmi_get_system_info(DMI_BOARD_NAME);
if (board_name && strstr(board_name, "CM-iTC"))
base_baud = 192000000;
switch (port_type) {
case PORT_UNKNOWN:
fifosize = 256;
break;
case PORT_8250:
fifosize = 64;
break;
default:
dev_err(&pdev->dev, "Invalid Port Type(=%d)\n", port_type);
goto init_port_hal_free;
}
iobase = pci_resource_start(pdev, 0);
mapbase = pci_resource_start(pdev, 1);
priv->mapbase = mapbase;
priv->iobase = iobase;
priv->pdev = pdev;
priv->tx_empty = 1;
priv->rxbuf.buf = rxbuf;
priv->rxbuf.size = PAGE_SIZE;
priv->fifo_size = fifosize;
priv->base_baud = base_baud;
priv->port_type = PORT_MAX_8250 + port_type + 1;
priv->port.dev = &pdev->dev;
priv->port.iobase = iobase;
priv->port.membase = NULL;
priv->port.mapbase = mapbase;
priv->port.irq = pdev->irq;
priv->port.iotype = UPIO_PORT;
priv->port.ops = &pch_uart_ops;
priv->port.flags = UPF_BOOT_AUTOCONF;
priv->port.fifosize = fifosize;
priv->port.line = board->line_no;
priv->trigger = PCH_UART_HAL_TRIGGER_M;
spin_lock_init(&priv->port.lock);
pci_set_drvdata(pdev, priv);
pch_uart_hal_request(pdev, fifosize, base_baud);
ret = uart_add_one_port(&pch_uart_driver, &priv->port);
if (ret < 0)
goto init_port_hal_free;
return priv;
init_port_hal_free:
free_page((unsigned long)rxbuf);
init_port_free_txbuf:
kfree(priv);
init_port_alloc_err:
return NULL;
}
static void pch_uart_exit_port(struct eg20t_port *priv)
{
uart_remove_one_port(&pch_uart_driver, &priv->port);
pci_set_drvdata(priv->pdev, NULL);
free_page((unsigned long)priv->rxbuf.buf);
}
static void pch_uart_pci_remove(struct pci_dev *pdev)
{
struct eg20t_port *priv;
priv = (struct eg20t_port *)pci_get_drvdata(pdev);
pch_uart_exit_port(priv);
pci_disable_device(pdev);
kfree(priv);
return;
}
static int pch_uart_pci_suspend(struct pci_dev *pdev, pm_message_t state)
{
struct eg20t_port *priv = pci_get_drvdata(pdev);
uart_suspend_port(&pch_uart_driver, &priv->port);
pci_save_state(pdev);
pci_set_power_state(pdev, pci_choose_state(pdev, state));
return 0;
}
static int pch_uart_pci_resume(struct pci_dev *pdev)
{
struct eg20t_port *priv = pci_get_drvdata(pdev);
int ret;
pci_set_power_state(pdev, PCI_D0);
pci_restore_state(pdev);
ret = pci_enable_device(pdev);
if (ret) {
dev_err(&pdev->dev,
"%s-pci_enable_device failed(ret=%d) ", __func__, ret);
return ret;
}
uart_resume_port(&pch_uart_driver, &priv->port);
return 0;
}
static int __devinit pch_uart_pci_probe(struct pci_dev *pdev,
const struct pci_device_id *id)
{
int ret;
struct eg20t_port *priv;
ret = pci_enable_device(pdev);
if (ret < 0)
goto probe_error;
priv = pch_uart_init_port(pdev, id);
if (!priv) {
ret = -EBUSY;
goto probe_disable_device;
}
pci_set_drvdata(pdev, priv);
return ret;
probe_disable_device:
pci_disable_device(pdev);
probe_error:
return ret;
}
static int __init pch_uart_module_init(void)
{
int ret;
ret = uart_register_driver(&pch_uart_driver);
if (ret < 0)
return ret;
ret = pci_register_driver(&pch_uart_pci_driver);
if (ret < 0)
uart_unregister_driver(&pch_uart_driver);
return ret;
}
static void __exit pch_uart_module_exit(void)
{
pci_unregister_driver(&pch_uart_pci_driver);
uart_unregister_driver(&pch_uart_driver);
}
