static bool mid_spi_dma_chan_filter(struct dma_chan *chan, void *param)
{
struct dw_spi *dws = param;
return dws->dmac && (&dws->dmac->dev == chan->device->dev);
}
static int mid_spi_dma_init(struct dw_spi *dws)
{
struct mid_dma *dw_dma = dws->dma_priv;
struct intel_mid_dma_slave *rxs, *txs;
dma_cap_mask_t mask;
dws->dmac = pci_get_device(PCI_VENDOR_ID_INTEL, 0x0813, NULL);
if (!dws->dmac)
dws->dmac = pci_get_device(PCI_VENDOR_ID_INTEL, 0x0827, NULL);
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
return -1;
}
static void mid_spi_dma_exit(struct dw_spi *dws)
{
dma_release_channel(dws->txchan);
dma_release_channel(dws->rxchan);
}
static void dw_spi_dma_done(void *arg)
{
struct dw_spi *dws = arg;
if (++dws->dma_chan_done != 2)
return;
dw_spi_xfer_done(dws);
}
static int mid_spi_dma_transfer(struct dw_spi *dws, int cs_change)
{
struct dma_async_tx_descriptor *txdesc = NULL, *rxdesc = NULL;
struct dma_chan *txchan, *rxchan;
struct dma_slave_config txconf, rxconf;
u16 dma_ctrl = 0;
if (cs_change) {
spi_enable_chip(dws, 0);
dw_writew(dws, dmardlr, 0xf);
dw_writew(dws, dmatdlr, 0x10);
if (dws->tx_dma)
dma_ctrl |= 0x2;
if (dws->rx_dma)
dma_ctrl |= 0x1;
dw_writew(dws, dmacr, dma_ctrl);
spi_enable_chip(dws, 1);
}
dws->dma_chan_done = 0;
txchan = dws->txchan;
rxchan = dws->rxchan;
txconf.direction = DMA_TO_DEVICE;
txconf.dst_addr = dws->dma_addr;
txconf.dst_maxburst = LNW_DMA_MSIZE_16;
txconf.src_addr_width = DMA_SLAVE_BUSWIDTH_4_BYTES;
txconf.dst_addr_width = DMA_SLAVE_BUSWIDTH_2_BYTES;
txchan->device->device_control(txchan, DMA_SLAVE_CONFIG,
(unsigned long) &txconf);
memset(&dws->tx_sgl, 0, sizeof(dws->tx_sgl));
dws->tx_sgl.dma_address = dws->tx_dma;
dws->tx_sgl.length = dws->len;
txdesc = txchan->device->device_prep_slave_sg(txchan,
&dws->tx_sgl,
1,
DMA_TO_DEVICE,
DMA_PREP_INTERRUPT | DMA_COMPL_SKIP_DEST_UNMAP);
txdesc->callback = dw_spi_dma_done;
txdesc->callback_param = dws;
rxconf.direction = DMA_FROM_DEVICE;
rxconf.src_addr = dws->dma_addr;
rxconf.src_maxburst = LNW_DMA_MSIZE_16;
rxconf.dst_addr_width = DMA_SLAVE_BUSWIDTH_4_BYTES;
rxconf.src_addr_width = DMA_SLAVE_BUSWIDTH_2_BYTES;
rxchan->device->device_control(rxchan, DMA_SLAVE_CONFIG,
(unsigned long) &rxconf);
memset(&dws->rx_sgl, 0, sizeof(dws->rx_sgl));
dws->rx_sgl.dma_address = dws->rx_dma;
dws->rx_sgl.length = dws->len;
rxdesc = rxchan->device->device_prep_slave_sg(rxchan,
&dws->rx_sgl,
1,
DMA_FROM_DEVICE,
DMA_PREP_INTERRUPT | DMA_COMPL_SKIP_DEST_UNMAP);
rxdesc->callback = dw_spi_dma_done;
rxdesc->callback_param = dws;
rxdesc->tx_submit(rxdesc);
txdesc->tx_submit(txdesc);
return 0;
}
int dw_spi_mid_init(struct dw_spi *dws)
{
u32 *clk_reg, clk_cdiv;
clk_reg = ioremap_nocache(MRST_CLK_SPI0_REG, 16);
if (!clk_reg)
return -ENOMEM;
clk_cdiv = (readl(clk_reg) & CLK_SPI_CDIV_MASK) >> CLK_SPI_CDIV_OFFSET;
dws->max_freq = MRST_SPI_CLK_BASE / (clk_cdiv + 1);
iounmap(clk_reg);
dws->num_cs = 16;
dws->fifo_len = 40;
#ifdef CONFIG_SPI_DW_MID_DMA
dws->dma_priv = kzalloc(sizeof(struct mid_dma), GFP_KERNEL);
if (!dws->dma_priv)
return -ENOMEM;
dws->dma_ops = &mid_dma_ops;
#endif
return 0;
}
