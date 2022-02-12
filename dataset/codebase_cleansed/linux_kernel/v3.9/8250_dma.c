static void __dma_tx_complete(void *param)
{
struct uart_8250_port *p = param;
struct uart_8250_dma *dma = p->dma;
struct circ_buf *xmit = &p->port.state->xmit;
dma->tx_running = 0;
dma_sync_single_for_cpu(dma->txchan->device->dev, dma->tx_addr,
UART_XMIT_SIZE, DMA_TO_DEVICE);
xmit->tail += dma->tx_size;
xmit->tail &= UART_XMIT_SIZE - 1;
p->port.icount.tx += dma->tx_size;
if (uart_circ_chars_pending(xmit) < WAKEUP_CHARS)
uart_write_wakeup(&p->port);
if (!uart_circ_empty(xmit) && !uart_tx_stopped(&p->port)) {
serial8250_tx_dma(p);
uart_write_wakeup(&p->port);
}
}
static void __dma_rx_complete(void *param)
{
struct uart_8250_port *p = param;
struct uart_8250_dma *dma = p->dma;
struct tty_port *tty_port = &p->port.state->port;
struct dma_tx_state state;
int count;
dma_sync_single_for_cpu(dma->rxchan->device->dev, dma->rx_addr,
dma->rx_size, DMA_FROM_DEVICE);
dmaengine_tx_status(dma->rxchan, dma->rx_cookie, &state);
dmaengine_terminate_all(dma->rxchan);
count = dma->rx_size - state.residue;
tty_insert_flip_string(tty_port, dma->rx_buf, count);
p->port.icount.rx += count;
tty_flip_buffer_push(tty_port);
}
int serial8250_tx_dma(struct uart_8250_port *p)
{
struct uart_8250_dma *dma = p->dma;
struct circ_buf *xmit = &p->port.state->xmit;
struct dma_async_tx_descriptor *desc;
if (dma->tx_running)
return -EBUSY;
dma->tx_size = CIRC_CNT_TO_END(xmit->head, xmit->tail, UART_XMIT_SIZE);
if (!dma->tx_size)
return -EINVAL;
desc = dmaengine_prep_slave_single(dma->txchan,
dma->tx_addr + xmit->tail,
dma->tx_size, DMA_MEM_TO_DEV,
DMA_PREP_INTERRUPT | DMA_CTRL_ACK);
if (!desc)
return -EBUSY;
dma->tx_running = 1;
desc->callback = __dma_tx_complete;
desc->callback_param = p;
dma->tx_cookie = dmaengine_submit(desc);
dma_sync_single_for_device(dma->txchan->device->dev, dma->tx_addr,
UART_XMIT_SIZE, DMA_TO_DEVICE);
dma_async_issue_pending(dma->txchan);
return 0;
}
int serial8250_rx_dma(struct uart_8250_port *p, unsigned int iir)
{
struct uart_8250_dma *dma = p->dma;
struct dma_async_tx_descriptor *desc;
struct dma_tx_state state;
int dma_status;
if ((iir & 0x3f) == UART_IIR_RX_TIMEOUT) {
dma_status = dmaengine_tx_status(dma->rxchan, dma->rx_cookie,
&state);
if (dma_status == DMA_IN_PROGRESS) {
dmaengine_pause(dma->rxchan);
__dma_rx_complete(p);
}
return -ETIMEDOUT;
}
desc = dmaengine_prep_slave_single(dma->rxchan, dma->rx_addr,
dma->rx_size, DMA_DEV_TO_MEM,
DMA_PREP_INTERRUPT | DMA_CTRL_ACK);
if (!desc)
return -EBUSY;
desc->callback = __dma_rx_complete;
desc->callback_param = p;
dma->rx_cookie = dmaengine_submit(desc);
dma_sync_single_for_device(dma->rxchan->device->dev, dma->rx_addr,
dma->rx_size, DMA_FROM_DEVICE);
dma_async_issue_pending(dma->rxchan);
return 0;
}
int serial8250_request_dma(struct uart_8250_port *p)
{
struct uart_8250_dma *dma = p->dma;
dma_cap_mask_t mask;
dma->rxconf.src_addr = p->port.mapbase + UART_RX;
dma->txconf.dst_addr = p->port.mapbase + UART_TX;
dma_cap_zero(mask);
dma_cap_set(DMA_SLAVE, mask);
dma->rxchan = dma_request_channel(mask, dma->fn, dma->rx_param);
if (!dma->rxchan)
return -ENODEV;
dmaengine_slave_config(dma->rxchan, &dma->rxconf);
dma->txchan = dma_request_channel(mask, dma->fn, dma->tx_param);
if (!dma->txchan) {
dma_release_channel(dma->rxchan);
return -ENODEV;
}
dmaengine_slave_config(dma->txchan, &dma->txconf);
if (!dma->rx_size)
dma->rx_size = PAGE_SIZE;
dma->rx_buf = dma_alloc_coherent(dma->rxchan->device->dev, dma->rx_size,
&dma->rx_addr, GFP_KERNEL);
if (!dma->rx_buf) {
dma_release_channel(dma->rxchan);
dma_release_channel(dma->txchan);
return -ENOMEM;
}
dma->tx_addr = dma_map_single(dma->txchan->device->dev,
p->port.state->xmit.buf,
UART_XMIT_SIZE,
DMA_TO_DEVICE);
dev_dbg_ratelimited(p->port.dev, "got both dma channels\n");
return 0;
}
void serial8250_release_dma(struct uart_8250_port *p)
{
struct uart_8250_dma *dma = p->dma;
if (!dma)
return;
dmaengine_terminate_all(dma->rxchan);
dma_free_coherent(dma->rxchan->device->dev, dma->rx_size, dma->rx_buf,
dma->rx_addr);
dma_release_channel(dma->rxchan);
dma->rxchan = NULL;
dmaengine_terminate_all(dma->txchan);
dma_unmap_single(dma->txchan->device->dev, dma->tx_addr,
UART_XMIT_SIZE, DMA_TO_DEVICE);
dma_release_channel(dma->txchan);
dma->txchan = NULL;
dma->tx_running = 0;
dev_dbg_ratelimited(p->port.dev, "dma channels released\n");
}
