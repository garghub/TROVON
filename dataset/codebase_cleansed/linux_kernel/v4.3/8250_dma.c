static void __dma_tx_complete(void *param)
{
struct uart_8250_port *p = param;
struct uart_8250_dma *dma = p->dma;
struct circ_buf *xmit = &p->port.state->xmit;
unsigned long flags;
int ret;
dma_sync_single_for_cpu(dma->txchan->device->dev, dma->tx_addr,
UART_XMIT_SIZE, DMA_TO_DEVICE);
spin_lock_irqsave(&p->port.lock, flags);
dma->tx_running = 0;
xmit->tail += dma->tx_size;
xmit->tail &= UART_XMIT_SIZE - 1;
p->port.icount.tx += dma->tx_size;
if (uart_circ_chars_pending(xmit) < WAKEUP_CHARS)
uart_write_wakeup(&p->port);
ret = serial8250_tx_dma(p);
if (ret) {
p->ier |= UART_IER_THRI;
serial_port_out(&p->port, UART_IER, p->ier);
}
spin_unlock_irqrestore(&p->port.lock, flags);
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
dma->rx_running = 0;
dmaengine_tx_status(dma->rxchan, dma->rx_cookie, &state);
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
int ret;
if (uart_tx_stopped(&p->port) || dma->tx_running ||
uart_circ_empty(xmit))
return 0;
dma->tx_size = CIRC_CNT_TO_END(xmit->head, xmit->tail, UART_XMIT_SIZE);
desc = dmaengine_prep_slave_single(dma->txchan,
dma->tx_addr + xmit->tail,
dma->tx_size, DMA_MEM_TO_DEV,
DMA_PREP_INTERRUPT | DMA_CTRL_ACK);
if (!desc) {
ret = -EBUSY;
goto err;
}
dma->tx_running = 1;
desc->callback = __dma_tx_complete;
desc->callback_param = p;
dma->tx_cookie = dmaengine_submit(desc);
dma_sync_single_for_device(dma->txchan->device->dev, dma->tx_addr,
UART_XMIT_SIZE, DMA_TO_DEVICE);
dma_async_issue_pending(dma->txchan);
if (dma->tx_err) {
dma->tx_err = 0;
if (p->ier & UART_IER_THRI) {
p->ier &= ~UART_IER_THRI;
serial_out(p, UART_IER, p->ier);
}
}
return 0;
err:
dma->tx_err = 1;
return ret;
}
int serial8250_rx_dma(struct uart_8250_port *p, unsigned int iir)
{
struct uart_8250_dma *dma = p->dma;
struct dma_async_tx_descriptor *desc;
switch (iir & 0x3f) {
case UART_IIR_RLSI:
return -EIO;
case UART_IIR_RX_TIMEOUT:
if (dma->rx_running) {
dmaengine_pause(dma->rxchan);
__dma_rx_complete(p);
dmaengine_terminate_all(dma->rxchan);
}
return -ETIMEDOUT;
default:
break;
}
if (dma->rx_running)
return 0;
desc = dmaengine_prep_slave_single(dma->rxchan, dma->rx_addr,
dma->rx_size, DMA_DEV_TO_MEM,
DMA_PREP_INTERRUPT | DMA_CTRL_ACK);
if (!desc)
return -EBUSY;
dma->rx_running = 1;
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
dma->rxconf.direction = DMA_DEV_TO_MEM;
dma->rxconf.src_addr_width = DMA_SLAVE_BUSWIDTH_1_BYTE;
dma->rxconf.src_addr = p->port.mapbase + UART_RX;
dma->txconf.direction = DMA_MEM_TO_DEV;
dma->txconf.dst_addr_width = DMA_SLAVE_BUSWIDTH_1_BYTE;
dma->txconf.dst_addr = p->port.mapbase + UART_TX;
dma_cap_zero(mask);
dma_cap_set(DMA_SLAVE, mask);
dma->rxchan = dma_request_slave_channel_compat(mask,
dma->fn, dma->rx_param,
p->port.dev, "rx");
if (!dma->rxchan)
return -ENODEV;
dmaengine_slave_config(dma->rxchan, &dma->rxconf);
dma->txchan = dma_request_slave_channel_compat(mask,
dma->fn, dma->tx_param,
p->port.dev, "tx");
if (!dma->txchan) {
dma_release_channel(dma->rxchan);
return -ENODEV;
}
dmaengine_slave_config(dma->txchan, &dma->txconf);
if (!dma->rx_size)
dma->rx_size = PAGE_SIZE;
dma->rx_buf = dma_alloc_coherent(dma->rxchan->device->dev, dma->rx_size,
&dma->rx_addr, GFP_KERNEL);
if (!dma->rx_buf)
goto err;
dma->tx_addr = dma_map_single(dma->txchan->device->dev,
p->port.state->xmit.buf,
UART_XMIT_SIZE,
DMA_TO_DEVICE);
if (dma_mapping_error(dma->txchan->device->dev, dma->tx_addr)) {
dma_free_coherent(dma->rxchan->device->dev, dma->rx_size,
dma->rx_buf, dma->rx_addr);
goto err;
}
dev_dbg_ratelimited(p->port.dev, "got both dma channels\n");
return 0;
err:
dma_release_channel(dma->rxchan);
dma_release_channel(dma->txchan);
return -ENOMEM;
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
