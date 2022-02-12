int sgdma_initialize(struct altera_tse_private *priv)
{
priv->txctrlreg = SGDMA_CTRLREG_ILASTD |
SGDMA_CTRLREG_INTEN;
priv->rxctrlreg = SGDMA_CTRLREG_IDESCRIP |
SGDMA_CTRLREG_INTEN |
SGDMA_CTRLREG_ILASTD;
INIT_LIST_HEAD(&priv->txlisthd);
INIT_LIST_HEAD(&priv->rxlisthd);
priv->rxdescphys = (dma_addr_t) 0;
priv->txdescphys = (dma_addr_t) 0;
priv->rxdescphys = dma_map_single(priv->device,
(void __force *)priv->rx_dma_desc,
priv->rxdescmem, DMA_BIDIRECTIONAL);
if (dma_mapping_error(priv->device, priv->rxdescphys)) {
sgdma_uninitialize(priv);
netdev_err(priv->dev, "error mapping rx descriptor memory\n");
return -EINVAL;
}
priv->txdescphys = dma_map_single(priv->device,
(void __force *)priv->tx_dma_desc,
priv->txdescmem, DMA_TO_DEVICE);
if (dma_mapping_error(priv->device, priv->txdescphys)) {
sgdma_uninitialize(priv);
netdev_err(priv->dev, "error mapping tx descriptor memory\n");
return -EINVAL;
}
memset_io(priv->tx_dma_desc, 0, priv->txdescmem);
memset_io(priv->rx_dma_desc, 0, priv->rxdescmem);
dma_sync_single_for_device(priv->device, priv->txdescphys,
priv->txdescmem, DMA_TO_DEVICE);
dma_sync_single_for_device(priv->device, priv->rxdescphys,
priv->rxdescmem, DMA_TO_DEVICE);
return 0;
}
void sgdma_uninitialize(struct altera_tse_private *priv)
{
if (priv->rxdescphys)
dma_unmap_single(priv->device, priv->rxdescphys,
priv->rxdescmem, DMA_BIDIRECTIONAL);
if (priv->txdescphys)
dma_unmap_single(priv->device, priv->txdescphys,
priv->txdescmem, DMA_TO_DEVICE);
}
void sgdma_reset(struct altera_tse_private *priv)
{
memset_io(priv->tx_dma_desc, 0, priv->txdescmem);
memset_io(priv->rx_dma_desc, 0, priv->rxdescmem);
csrwr32(SGDMA_CTRLREG_RESET, priv->tx_dma_csr, sgdma_csroffs(control));
csrwr32(0, priv->tx_dma_csr, sgdma_csroffs(control));
csrwr32(SGDMA_CTRLREG_RESET, priv->rx_dma_csr, sgdma_csroffs(control));
csrwr32(0, priv->rx_dma_csr, sgdma_csroffs(control));
}
void sgdma_enable_rxirq(struct altera_tse_private *priv)
{
}
void sgdma_enable_txirq(struct altera_tse_private *priv)
{
}
void sgdma_disable_rxirq(struct altera_tse_private *priv)
{
}
void sgdma_disable_txirq(struct altera_tse_private *priv)
{
}
void sgdma_clear_rxirq(struct altera_tse_private *priv)
{
tse_set_bit(priv->rx_dma_csr, sgdma_csroffs(control),
SGDMA_CTRLREG_CLRINT);
}
void sgdma_clear_txirq(struct altera_tse_private *priv)
{
tse_set_bit(priv->tx_dma_csr, sgdma_csroffs(control),
SGDMA_CTRLREG_CLRINT);
}
int sgdma_tx_buffer(struct altera_tse_private *priv, struct tse_buffer *buffer)
{
struct sgdma_descrip __iomem *descbase =
(struct sgdma_descrip __iomem *)priv->tx_dma_desc;
struct sgdma_descrip __iomem *cdesc = &descbase[0];
struct sgdma_descrip __iomem *ndesc = &descbase[1];
if (sgdma_txbusy(priv))
return 0;
sgdma_setup_descrip(cdesc,
ndesc,
sgdma_txphysaddr(priv, ndesc),
buffer->dma_addr,
0,
buffer->len,
SGDMA_CONTROL_EOP,
0,
SGDMA_CONTROL_WR_FIXED);
sgdma_async_write(priv, cdesc);
queue_tx(priv, buffer);
return 1;
}
u32 sgdma_tx_completions(struct altera_tse_private *priv)
{
u32 ready = 0;
if (!sgdma_txbusy(priv) &&
((csrrd8(priv->tx_dma_desc, sgdma_descroffs(control))
& SGDMA_CONTROL_HW_OWNED) == 0) &&
(dequeue_tx(priv))) {
ready = 1;
}
return ready;
}
void sgdma_start_rxdma(struct altera_tse_private *priv)
{
sgdma_async_read(priv);
}
void sgdma_add_rx_desc(struct altera_tse_private *priv,
struct tse_buffer *rxbuffer)
{
queue_rx(priv, rxbuffer);
}
u32 sgdma_rx_status(struct altera_tse_private *priv)
{
struct sgdma_descrip __iomem *base =
(struct sgdma_descrip __iomem *)priv->rx_dma_desc;
struct sgdma_descrip __iomem *desc = NULL;
struct tse_buffer *rxbuffer = NULL;
unsigned int rxstatus = 0;
u32 sts = csrrd32(priv->rx_dma_csr, sgdma_csroffs(status));
desc = &base[0];
if (sts & SGDMA_STSREG_EOP) {
unsigned int pktlength = 0;
unsigned int pktstatus = 0;
dma_sync_single_for_cpu(priv->device,
priv->rxdescphys,
SGDMA_DESC_LEN,
DMA_FROM_DEVICE);
pktlength = csrrd16(desc, sgdma_descroffs(bytes_xferred));
pktstatus = csrrd8(desc, sgdma_descroffs(status));
rxstatus = pktstatus & ~SGDMA_STATUS_EOP;
rxstatus = rxstatus << 16;
rxstatus |= (pktlength & 0xffff);
if (rxstatus) {
csrwr8(0, desc, sgdma_descroffs(status));
rxbuffer = dequeue_rx(priv);
if (rxbuffer == NULL)
netdev_info(priv->dev,
"sgdma rx and rx queue empty!\n");
csrwr32(0, priv->rx_dma_csr, sgdma_csroffs(control));
csrwr32(0xf, priv->rx_dma_csr, sgdma_csroffs(status));
sgdma_async_read(priv);
} else {
netdev_err(priv->dev,
"SGDMA RX Error Info: %x, %x, %x\n",
sts, csrrd8(desc, sgdma_descroffs(status)),
rxstatus);
}
} else if (sts == 0) {
sgdma_async_read(priv);
}
return rxstatus;
}
static void sgdma_setup_descrip(struct sgdma_descrip __iomem *desc,
struct sgdma_descrip __iomem *ndesc,
dma_addr_t ndesc_phys,
dma_addr_t raddr,
dma_addr_t waddr,
u16 length,
int generate_eop,
int rfixed,
int wfixed)
{
u32 ctrl = csrrd8(ndesc, sgdma_descroffs(control));
ctrl &= ~SGDMA_CONTROL_HW_OWNED;
csrwr8(ctrl, ndesc, sgdma_descroffs(control));
ctrl = SGDMA_CONTROL_HW_OWNED;
ctrl |= generate_eop;
ctrl |= rfixed;
ctrl |= wfixed;
csrwr32(lower_32_bits(raddr), desc, sgdma_descroffs(raddr));
csrwr32(lower_32_bits(waddr), desc, sgdma_descroffs(waddr));
csrwr32(0, desc, sgdma_descroffs(pad1));
csrwr32(0, desc, sgdma_descroffs(pad2));
csrwr32(lower_32_bits(ndesc_phys), desc, sgdma_descroffs(next));
csrwr8(ctrl, desc, sgdma_descroffs(control));
csrwr8(0, desc, sgdma_descroffs(status));
csrwr8(0, desc, sgdma_descroffs(wburst));
csrwr8(0, desc, sgdma_descroffs(rburst));
csrwr16(length, desc, sgdma_descroffs(bytes));
csrwr16(0, desc, sgdma_descroffs(bytes_xferred));
}
static int sgdma_async_read(struct altera_tse_private *priv)
{
struct sgdma_descrip __iomem *descbase =
(struct sgdma_descrip __iomem *)priv->rx_dma_desc;
struct sgdma_descrip __iomem *cdesc = &descbase[0];
struct sgdma_descrip __iomem *ndesc = &descbase[1];
struct tse_buffer *rxbuffer = NULL;
if (!sgdma_rxbusy(priv)) {
rxbuffer = queue_rx_peekhead(priv);
if (rxbuffer == NULL) {
netdev_err(priv->dev, "no rx buffers available\n");
return 0;
}
sgdma_setup_descrip(cdesc,
ndesc,
sgdma_rxphysaddr(priv, ndesc),
0,
rxbuffer->dma_addr,
0,
0,
0,
0);
dma_sync_single_for_device(priv->device,
priv->rxdescphys,
SGDMA_DESC_LEN,
DMA_TO_DEVICE);
csrwr32(lower_32_bits(sgdma_rxphysaddr(priv, cdesc)),
priv->rx_dma_csr,
sgdma_csroffs(next_descrip));
csrwr32((priv->rxctrlreg | SGDMA_CTRLREG_START),
priv->rx_dma_csr,
sgdma_csroffs(control));
return 1;
}
return 0;
}
static int sgdma_async_write(struct altera_tse_private *priv,
struct sgdma_descrip __iomem *desc)
{
if (sgdma_txbusy(priv))
return 0;
csrwr32(0, priv->tx_dma_csr, sgdma_csroffs(control));
csrwr32(0x1f, priv->tx_dma_csr, sgdma_csroffs(status));
dma_sync_single_for_device(priv->device, priv->txdescphys,
SGDMA_DESC_LEN, DMA_TO_DEVICE);
csrwr32(lower_32_bits(sgdma_txphysaddr(priv, desc)),
priv->tx_dma_csr,
sgdma_csroffs(next_descrip));
csrwr32((priv->txctrlreg | SGDMA_CTRLREG_START),
priv->tx_dma_csr,
sgdma_csroffs(control));
return 1;
}
static dma_addr_t
sgdma_txphysaddr(struct altera_tse_private *priv,
struct sgdma_descrip __iomem *desc)
{
dma_addr_t paddr = priv->txdescmem_busaddr;
uintptr_t offs = (uintptr_t)desc - (uintptr_t)priv->tx_dma_desc;
return (dma_addr_t)((uintptr_t)paddr + offs);
}
static dma_addr_t
sgdma_rxphysaddr(struct altera_tse_private *priv,
struct sgdma_descrip __iomem *desc)
{
dma_addr_t paddr = priv->rxdescmem_busaddr;
uintptr_t offs = (uintptr_t)desc - (uintptr_t)priv->rx_dma_desc;
return (dma_addr_t)((uintptr_t)paddr + offs);
}
static void
queue_tx(struct altera_tse_private *priv, struct tse_buffer *buffer)
{
list_add_tail(&buffer->lh, &priv->txlisthd);
}
static void
queue_rx(struct altera_tse_private *priv, struct tse_buffer *buffer)
{
list_add_tail(&buffer->lh, &priv->rxlisthd);
}
static struct tse_buffer *
dequeue_tx(struct altera_tse_private *priv)
{
struct tse_buffer *buffer = NULL;
list_remove_head(&priv->txlisthd, buffer, struct tse_buffer, lh);
return buffer;
}
static struct tse_buffer *
dequeue_rx(struct altera_tse_private *priv)
{
struct tse_buffer *buffer = NULL;
list_remove_head(&priv->rxlisthd, buffer, struct tse_buffer, lh);
return buffer;
}
static struct tse_buffer *
queue_rx_peekhead(struct altera_tse_private *priv)
{
struct tse_buffer *buffer = NULL;
list_peek_head(&priv->rxlisthd, buffer, struct tse_buffer, lh);
return buffer;
}
static int sgdma_rxbusy(struct altera_tse_private *priv)
{
return csrrd32(priv->rx_dma_csr, sgdma_csroffs(status))
& SGDMA_STSREG_BUSY;
}
static int sgdma_txbusy(struct altera_tse_private *priv)
{
int delay = 0;
while ((csrrd32(priv->tx_dma_csr, sgdma_csroffs(status))
& SGDMA_STSREG_BUSY) && (delay++ < 100))
udelay(1);
if (csrrd32(priv->tx_dma_csr, sgdma_csroffs(status))
& SGDMA_STSREG_BUSY) {
netdev_err(priv->dev, "timeout waiting for tx dma\n");
return 1;
}
return 0;
}
