static bool mid_spi_dma_chan_filter(struct dma_chan *chan, void *param)
{
struct dw_spi *dws = param;
return dws->dma_dev == chan->device->dev;
}
static int mid_spi_dma_init(struct dw_spi *dws)
{
struct mid_dma *dw_dma = dws->dma_priv;
struct pci_dev *dma_dev;
struct intel_mid_dma_slave *rxs, *txs;
dma_cap_mask_t mask;
dma_dev = pci_get_device(PCI_VENDOR_ID_INTEL, 0x0827, NULL);
if (!dma_dev)
return -ENODEV;
dws->dma_dev = &dma_dev->dev;
dma_cap_zero(mask);
dma_cap_set(DMA_SLAVE, mask);
dws->rxchan = dma_request_channel(mask, mid_spi_dma_chan_filter, dws);
if (!dws->rxchan)
goto err_exit;
rxs = &dw_dma->dmas_rx;
rxs->hs_mode = LNW_DMA_HW_HS;
rxs->cfg_mode = LNW_DMA_PER_TO_MEM;
dws->rxchan->private = rxs;
dws->txchan = dma_request_channel(mask, mid_spi_dma_chan_filter, dws);
if (!dws->txchan)
goto free_rxchan;
txs = &dw_dma->dmas_tx;
txs->hs_mode = LNW_DMA_HW_HS;
txs->cfg_mode = LNW_DMA_MEM_TO_PER;
dws->txchan->private = txs;
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
dmaengine_terminate_all(dws->txchan);
dma_release_channel(dws->txchan);
dmaengine_terminate_all(dws->rxchan);
dma_release_channel(dws->rxchan);
}
static void dw_spi_dma_tx_done(void *arg)
{
struct dw_spi *dws = arg;
if (test_and_clear_bit(TX_BUSY, &dws->dma_chan_busy) & BIT(RX_BUSY))
return;
dw_spi_xfer_done(dws);
}
static struct dma_async_tx_descriptor *dw_spi_dma_prepare_tx(struct dw_spi *dws)
{
struct dma_slave_config txconf;
struct dma_async_tx_descriptor *txdesc;
if (!dws->tx_dma)
return NULL;
txconf.direction = DMA_MEM_TO_DEV;
txconf.dst_addr = dws->dma_addr;
txconf.dst_maxburst = LNW_DMA_MSIZE_16;
txconf.src_addr_width = DMA_SLAVE_BUSWIDTH_4_BYTES;
txconf.dst_addr_width = dws->dma_width;
txconf.device_fc = false;
dmaengine_slave_config(dws->txchan, &txconf);
memset(&dws->tx_sgl, 0, sizeof(dws->tx_sgl));
dws->tx_sgl.dma_address = dws->tx_dma;
dws->tx_sgl.length = dws->len;
txdesc = dmaengine_prep_slave_sg(dws->txchan,
&dws->tx_sgl,
1,
DMA_MEM_TO_DEV,
DMA_PREP_INTERRUPT | DMA_CTRL_ACK);
txdesc->callback = dw_spi_dma_tx_done;
txdesc->callback_param = dws;
return txdesc;
}
static void dw_spi_dma_rx_done(void *arg)
{
struct dw_spi *dws = arg;
if (test_and_clear_bit(RX_BUSY, &dws->dma_chan_busy) & BIT(TX_BUSY))
return;
dw_spi_xfer_done(dws);
}
static struct dma_async_tx_descriptor *dw_spi_dma_prepare_rx(struct dw_spi *dws)
{
struct dma_slave_config rxconf;
struct dma_async_tx_descriptor *rxdesc;
if (!dws->rx_dma)
return NULL;
rxconf.direction = DMA_DEV_TO_MEM;
rxconf.src_addr = dws->dma_addr;
rxconf.src_maxburst = LNW_DMA_MSIZE_16;
rxconf.dst_addr_width = DMA_SLAVE_BUSWIDTH_4_BYTES;
rxconf.src_addr_width = dws->dma_width;
rxconf.device_fc = false;
dmaengine_slave_config(dws->rxchan, &rxconf);
memset(&dws->rx_sgl, 0, sizeof(dws->rx_sgl));
dws->rx_sgl.dma_address = dws->rx_dma;
dws->rx_sgl.length = dws->len;
rxdesc = dmaengine_prep_slave_sg(dws->rxchan,
&dws->rx_sgl,
1,
DMA_DEV_TO_MEM,
DMA_PREP_INTERRUPT | DMA_CTRL_ACK);
rxdesc->callback = dw_spi_dma_rx_done;
rxdesc->callback_param = dws;
return rxdesc;
}
static void dw_spi_dma_setup(struct dw_spi *dws)
{
u16 dma_ctrl = 0;
spi_enable_chip(dws, 0);
dw_writew(dws, DW_SPI_DMARDLR, 0xf);
dw_writew(dws, DW_SPI_DMATDLR, 0x10);
if (dws->tx_dma)
dma_ctrl |= SPI_DMA_TDMAE;
if (dws->rx_dma)
dma_ctrl |= SPI_DMA_RDMAE;
dw_writew(dws, DW_SPI_DMACR, dma_ctrl);
spi_enable_chip(dws, 1);
}
static int mid_spi_dma_transfer(struct dw_spi *dws, int cs_change)
{
struct dma_async_tx_descriptor *txdesc, *rxdesc;
if (cs_change)
dw_spi_dma_setup(dws);
txdesc = dw_spi_dma_prepare_tx(dws);
rxdesc = dw_spi_dma_prepare_rx(dws);
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
int dw_spi_mid_init(struct dw_spi *dws)
{
void __iomem *clk_reg;
u32 clk_cdiv;
clk_reg = ioremap_nocache(MRST_CLK_SPI0_REG, 16);
if (!clk_reg)
return -ENOMEM;
clk_cdiv = (readl(clk_reg) & CLK_SPI_CDIV_MASK) >> CLK_SPI_CDIV_OFFSET;
dws->max_freq = MRST_SPI_CLK_BASE / (clk_cdiv + 1);
iounmap(clk_reg);
dws->num_cs = 16;
#ifdef CONFIG_SPI_DW_MID_DMA
dws->dma_priv = kzalloc(sizeof(struct mid_dma), GFP_KERNEL);
if (!dws->dma_priv)
return -ENOMEM;
dws->dma_ops = &mid_dma_ops;
#endif
return 0;
}
