static bool mid_spi_dma_chan_filter(struct dma_chan *chan, void *param)
{
struct dw_dma_slave *s = param;
if (s->dma_dev != chan->device->dev)
return false;
chan->private = s;
return true;
}
static int mid_spi_dma_init(struct dw_spi *dws)
{
struct pci_dev *dma_dev;
struct dw_dma_slave *tx = dws->dma_tx;
struct dw_dma_slave *rx = dws->dma_rx;
dma_cap_mask_t mask;
dma_dev = pci_get_device(PCI_VENDOR_ID_INTEL, 0x0827, NULL);
if (!dma_dev)
return -ENODEV;
dma_cap_zero(mask);
dma_cap_set(DMA_SLAVE, mask);
rx->dma_dev = &dma_dev->dev;
dws->rxchan = dma_request_channel(mask, mid_spi_dma_chan_filter, rx);
if (!dws->rxchan)
goto err_exit;
dws->master->dma_rx = dws->rxchan;
tx->dma_dev = &dma_dev->dev;
dws->txchan = dma_request_channel(mask, mid_spi_dma_chan_filter, tx);
if (!dws->txchan)
goto free_rxchan;
dws->master->dma_tx = dws->txchan;
dws->dma_inited = 1;
return 0;
free_rxchan:
dma_release_channel(dws->rxchan);
err_exit:
return -EBUSY;
}
static void mid_spi_dma_exit(struct dw_spi *dws)
{
if (!dws->dma_inited)
return;
dmaengine_terminate_sync(dws->txchan);
dma_release_channel(dws->txchan);
dmaengine_terminate_sync(dws->rxchan);
dma_release_channel(dws->rxchan);
}
static irqreturn_t dma_transfer(struct dw_spi *dws)
{
u16 irq_status = dw_readl(dws, DW_SPI_ISR);
if (!irq_status)
return IRQ_NONE;
dw_readl(dws, DW_SPI_ICR);
spi_reset_chip(dws);
dev_err(&dws->master->dev, "%s: FIFO overrun/underrun\n", __func__);
dws->master->cur_msg->status = -EIO;
spi_finalize_current_transfer(dws->master);
return IRQ_HANDLED;
}
static bool mid_spi_can_dma(struct spi_master *master, struct spi_device *spi,
struct spi_transfer *xfer)
{
struct dw_spi *dws = spi_master_get_devdata(master);
if (!dws->dma_inited)
return false;
return xfer->len > dws->fifo_len;
}
static enum dma_slave_buswidth convert_dma_width(u32 dma_width) {
if (dma_width == 1)
return DMA_SLAVE_BUSWIDTH_1_BYTE;
else if (dma_width == 2)
return DMA_SLAVE_BUSWIDTH_2_BYTES;
return DMA_SLAVE_BUSWIDTH_UNDEFINED;
}
static void dw_spi_dma_tx_done(void *arg)
{
struct dw_spi *dws = arg;
clear_bit(TX_BUSY, &dws->dma_chan_busy);
if (test_bit(RX_BUSY, &dws->dma_chan_busy))
return;
spi_finalize_current_transfer(dws->master);
}
static struct dma_async_tx_descriptor *dw_spi_dma_prepare_tx(struct dw_spi *dws,
struct spi_transfer *xfer)
{
struct dma_slave_config txconf;
struct dma_async_tx_descriptor *txdesc;
if (!xfer->tx_buf)
return NULL;
txconf.direction = DMA_MEM_TO_DEV;
txconf.dst_addr = dws->dma_addr;
txconf.dst_maxburst = 16;
txconf.src_addr_width = DMA_SLAVE_BUSWIDTH_4_BYTES;
txconf.dst_addr_width = convert_dma_width(dws->dma_width);
txconf.device_fc = false;
dmaengine_slave_config(dws->txchan, &txconf);
txdesc = dmaengine_prep_slave_sg(dws->txchan,
xfer->tx_sg.sgl,
xfer->tx_sg.nents,
DMA_MEM_TO_DEV,
DMA_PREP_INTERRUPT | DMA_CTRL_ACK);
if (!txdesc)
return NULL;
txdesc->callback = dw_spi_dma_tx_done;
txdesc->callback_param = dws;
return txdesc;
}
static void dw_spi_dma_rx_done(void *arg)
{
struct dw_spi *dws = arg;
clear_bit(RX_BUSY, &dws->dma_chan_busy);
if (test_bit(TX_BUSY, &dws->dma_chan_busy))
return;
spi_finalize_current_transfer(dws->master);
}
static struct dma_async_tx_descriptor *dw_spi_dma_prepare_rx(struct dw_spi *dws,
struct spi_transfer *xfer)
{
struct dma_slave_config rxconf;
struct dma_async_tx_descriptor *rxdesc;
if (!xfer->rx_buf)
return NULL;
rxconf.direction = DMA_DEV_TO_MEM;
rxconf.src_addr = dws->dma_addr;
rxconf.src_maxburst = 16;
rxconf.dst_addr_width = DMA_SLAVE_BUSWIDTH_4_BYTES;
rxconf.src_addr_width = convert_dma_width(dws->dma_width);
rxconf.device_fc = false;
dmaengine_slave_config(dws->rxchan, &rxconf);
rxdesc = dmaengine_prep_slave_sg(dws->rxchan,
xfer->rx_sg.sgl,
xfer->rx_sg.nents,
DMA_DEV_TO_MEM,
DMA_PREP_INTERRUPT | DMA_CTRL_ACK);
if (!rxdesc)
return NULL;
rxdesc->callback = dw_spi_dma_rx_done;
rxdesc->callback_param = dws;
return rxdesc;
}
static int mid_spi_dma_setup(struct dw_spi *dws, struct spi_transfer *xfer)
{
u16 dma_ctrl = 0;
dw_writel(dws, DW_SPI_DMARDLR, 0xf);
dw_writel(dws, DW_SPI_DMATDLR, 0x10);
if (xfer->tx_buf)
dma_ctrl |= SPI_DMA_TDMAE;
if (xfer->rx_buf)
dma_ctrl |= SPI_DMA_RDMAE;
dw_writel(dws, DW_SPI_DMACR, dma_ctrl);
spi_umask_intr(dws, SPI_INT_TXOI | SPI_INT_RXUI | SPI_INT_RXOI);
dws->transfer_handler = dma_transfer;
return 0;
}
static int mid_spi_dma_transfer(struct dw_spi *dws, struct spi_transfer *xfer)
{
struct dma_async_tx_descriptor *txdesc, *rxdesc;
txdesc = dw_spi_dma_prepare_tx(dws, xfer);
rxdesc = dw_spi_dma_prepare_rx(dws, xfer);
if (rxdesc) {
set_bit(RX_BUSY, &dws->dma_chan_busy);
dmaengine_submit(rxdesc);
dma_async_issue_pending(dws->rxchan);
}
if (txdesc) {
set_bit(TX_BUSY, &dws->dma_chan_busy);
dmaengine_submit(txdesc);
dma_async_issue_pending(dws->txchan);
}
return 0;
}
static void mid_spi_dma_stop(struct dw_spi *dws)
{
if (test_bit(TX_BUSY, &dws->dma_chan_busy)) {
dmaengine_terminate_all(dws->txchan);
clear_bit(TX_BUSY, &dws->dma_chan_busy);
}
if (test_bit(RX_BUSY, &dws->dma_chan_busy)) {
dmaengine_terminate_all(dws->rxchan);
clear_bit(RX_BUSY, &dws->dma_chan_busy);
}
}
int dw_spi_mid_init(struct dw_spi *dws)
{
void __iomem *clk_reg;
u32 clk_cdiv;
clk_reg = ioremap_nocache(MRST_CLK_SPI_REG, 16);
if (!clk_reg)
return -ENOMEM;
clk_cdiv = readl(clk_reg + dws->bus_num * sizeof(u32));
clk_cdiv &= CLK_SPI_CDIV_MASK;
clk_cdiv >>= CLK_SPI_CDIV_OFFSET;
dws->max_freq = MRST_SPI_CLK_BASE / (clk_cdiv + 1);
iounmap(clk_reg);
#ifdef CONFIG_SPI_DW_MID_DMA
dws->dma_tx = &mid_dma_tx;
dws->dma_rx = &mid_dma_rx;
dws->dma_ops = &mid_dma_ops;
#endif
return 0;
}
