static u32 zynqmp_gqspi_read(struct zynqmp_qspi *xqspi, u32 offset)
{
return readl_relaxed(xqspi->regs + offset);
}
static inline void zynqmp_gqspi_write(struct zynqmp_qspi *xqspi, u32 offset,
u32 val)
{
writel_relaxed(val, (xqspi->regs + offset));
}
static void zynqmp_gqspi_selectslave(struct zynqmp_qspi *instanceptr,
u8 slavecs, u8 slavebus)
{
switch (slavecs) {
case GQSPI_SELECT_FLASH_CS_BOTH:
instanceptr->genfifocs = GQSPI_GENFIFO_CS_LOWER |
GQSPI_GENFIFO_CS_UPPER;
break;
case GQSPI_SELECT_FLASH_CS_UPPER:
instanceptr->genfifocs = GQSPI_GENFIFO_CS_UPPER;
break;
case GQSPI_SELECT_FLASH_CS_LOWER:
instanceptr->genfifocs = GQSPI_GENFIFO_CS_LOWER;
break;
default:
dev_warn(instanceptr->dev, "Invalid slave select\n");
}
switch (slavebus) {
case GQSPI_SELECT_FLASH_BUS_BOTH:
instanceptr->genfifobus = GQSPI_GENFIFO_BUS_LOWER |
GQSPI_GENFIFO_BUS_UPPER;
break;
case GQSPI_SELECT_FLASH_BUS_UPPER:
instanceptr->genfifobus = GQSPI_GENFIFO_BUS_UPPER;
break;
case GQSPI_SELECT_FLASH_BUS_LOWER:
instanceptr->genfifobus = GQSPI_GENFIFO_BUS_LOWER;
break;
default:
dev_warn(instanceptr->dev, "Invalid slave bus\n");
}
}
static void zynqmp_qspi_init_hw(struct zynqmp_qspi *xqspi)
{
u32 config_reg;
zynqmp_gqspi_write(xqspi, GQSPI_SEL_OFST, GQSPI_SEL_MASK);
zynqmp_gqspi_write(xqspi, GQSPI_ISR_OFST,
zynqmp_gqspi_read(xqspi, GQSPI_ISR_OFST) |
GQSPI_ISR_WR_TO_CLR_MASK);
zynqmp_gqspi_write(xqspi, GQSPI_QSPIDMA_DST_I_STS_OFST,
zynqmp_gqspi_read(xqspi,
GQSPI_QSPIDMA_DST_I_STS_OFST));
zynqmp_gqspi_write(xqspi, GQSPI_QSPIDMA_DST_STS_OFST,
zynqmp_gqspi_read(xqspi,
GQSPI_QSPIDMA_DST_STS_OFST) |
GQSPI_QSPIDMA_DST_STS_WTC);
zynqmp_gqspi_write(xqspi, GQSPI_IDR_OFST, GQSPI_IDR_ALL_MASK);
zynqmp_gqspi_write(xqspi,
GQSPI_QSPIDMA_DST_I_DIS_OFST,
GQSPI_QSPIDMA_DST_INTR_ALL_MASK);
zynqmp_gqspi_write(xqspi, GQSPI_EN_OFST, 0x0);
config_reg = zynqmp_gqspi_read(xqspi, GQSPI_CONFIG_OFST);
config_reg &= ~GQSPI_CFG_MODE_EN_MASK;
config_reg |= GQSPI_CFG_GEN_FIFO_START_MODE_MASK;
config_reg &= ~GQSPI_CFG_ENDIAN_MASK;
config_reg &= ~GQSPI_CFG_EN_POLL_TO_MASK;
config_reg |= GQSPI_CFG_WP_HOLD_MASK;
config_reg &= ~GQSPI_CFG_BAUD_RATE_DIV_MASK;
config_reg &= ~GQSPI_CFG_CLK_PHA_MASK;
config_reg &= ~GQSPI_CFG_CLK_POL_MASK;
zynqmp_gqspi_write(xqspi, GQSPI_CONFIG_OFST, config_reg);
zynqmp_gqspi_write(xqspi, GQSPI_FIFO_CTRL_OFST,
GQSPI_FIFO_CTRL_RST_RX_FIFO_MASK |
GQSPI_FIFO_CTRL_RST_TX_FIFO_MASK |
GQSPI_FIFO_CTRL_RST_GEN_FIFO_MASK);
zynqmp_gqspi_write(xqspi, GQSPI_LPBK_DLY_ADJ_OFST,
zynqmp_gqspi_read(xqspi, GQSPI_LPBK_DLY_ADJ_OFST) |
GQSPI_LPBK_DLY_ADJ_USE_LPBK_MASK);
zynqmp_gqspi_write(xqspi, GQSPI_TX_THRESHOLD_OFST,
GQSPI_TX_FIFO_THRESHOLD_RESET_VAL);
zynqmp_gqspi_write(xqspi, GQSPI_RX_THRESHOLD_OFST,
GQSPI_RX_FIFO_THRESHOLD);
zynqmp_gqspi_write(xqspi, GQSPI_GF_THRESHOLD_OFST,
GQSPI_GEN_FIFO_THRESHOLD_RESET_VAL);
zynqmp_gqspi_selectslave(xqspi,
GQSPI_SELECT_FLASH_CS_LOWER,
GQSPI_SELECT_FLASH_BUS_LOWER);
zynqmp_gqspi_write(xqspi,
GQSPI_QSPIDMA_DST_CTRL_OFST,
GQSPI_QSPIDMA_DST_CTRL_RESET_VAL);
zynqmp_gqspi_write(xqspi, GQSPI_EN_OFST, GQSPI_EN_MASK);
}
static void zynqmp_qspi_copy_read_data(struct zynqmp_qspi *xqspi,
ulong data, u8 size)
{
memcpy(xqspi->rxbuf, &data, size);
xqspi->rxbuf += size;
xqspi->bytes_to_receive -= size;
}
static int zynqmp_prepare_transfer_hardware(struct spi_master *master)
{
struct zynqmp_qspi *xqspi = spi_master_get_devdata(master);
int ret;
ret = clk_enable(xqspi->refclk);
if (ret)
goto clk_err;
ret = clk_enable(xqspi->pclk);
if (ret)
goto clk_err;
zynqmp_gqspi_write(xqspi, GQSPI_EN_OFST, GQSPI_EN_MASK);
return 0;
clk_err:
return ret;
}
static int zynqmp_unprepare_transfer_hardware(struct spi_master *master)
{
struct zynqmp_qspi *xqspi = spi_master_get_devdata(master);
zynqmp_gqspi_write(xqspi, GQSPI_EN_OFST, 0x0);
clk_disable(xqspi->refclk);
clk_disable(xqspi->pclk);
return 0;
}
static void zynqmp_qspi_chipselect(struct spi_device *qspi, bool is_high)
{
struct zynqmp_qspi *xqspi = spi_master_get_devdata(qspi->master);
ulong timeout;
u32 genfifoentry = 0x0, statusreg;
genfifoentry |= GQSPI_GENFIFO_MODE_SPI;
genfifoentry |= xqspi->genfifobus;
if (!is_high) {
genfifoentry |= xqspi->genfifocs;
genfifoentry |= GQSPI_GENFIFO_CS_SETUP;
} else {
genfifoentry |= GQSPI_GENFIFO_CS_HOLD;
}
zynqmp_gqspi_write(xqspi, GQSPI_GEN_FIFO_OFST, genfifoentry);
zynqmp_gqspi_write(xqspi, GQSPI_GEN_FIFO_OFST, 0x0);
zynqmp_gqspi_write(xqspi, GQSPI_CONFIG_OFST,
zynqmp_gqspi_read(xqspi, GQSPI_CONFIG_OFST) |
GQSPI_CFG_START_GEN_FIFO_MASK);
timeout = jiffies + msecs_to_jiffies(1000);
do {
statusreg = zynqmp_gqspi_read(xqspi, GQSPI_ISR_OFST);
if ((statusreg & GQSPI_ISR_GENFIFOEMPTY_MASK) &&
(statusreg & GQSPI_ISR_TXEMPTY_MASK))
break;
else
cpu_relax();
} while (!time_after_eq(jiffies, timeout));
if (time_after_eq(jiffies, timeout))
dev_err(xqspi->dev, "Chip select timed out\n");
}
static int zynqmp_qspi_setup_transfer(struct spi_device *qspi,
struct spi_transfer *transfer)
{
struct zynqmp_qspi *xqspi = spi_master_get_devdata(qspi->master);
ulong clk_rate;
u32 config_reg, req_hz, baud_rate_val = 0;
if (transfer)
req_hz = transfer->speed_hz;
else
req_hz = qspi->max_speed_hz;
clk_rate = clk_get_rate(xqspi->refclk);
while ((baud_rate_val < GQSPI_BAUD_DIV_MAX) &&
(clk_rate /
(GQSPI_BAUD_DIV_SHIFT << baud_rate_val)) > req_hz)
baud_rate_val++;
config_reg = zynqmp_gqspi_read(xqspi, GQSPI_CONFIG_OFST);
config_reg &= (~GQSPI_CFG_CLK_PHA_MASK) & (~GQSPI_CFG_CLK_POL_MASK);
if (qspi->mode & SPI_CPHA)
config_reg |= GQSPI_CFG_CLK_PHA_MASK;
if (qspi->mode & SPI_CPOL)
config_reg |= GQSPI_CFG_CLK_POL_MASK;
config_reg &= ~GQSPI_CFG_BAUD_RATE_DIV_MASK;
config_reg |= (baud_rate_val << GQSPI_CFG_BAUD_RATE_DIV_SHIFT);
zynqmp_gqspi_write(xqspi, GQSPI_CONFIG_OFST, config_reg);
return 0;
}
static int zynqmp_qspi_setup(struct spi_device *qspi)
{
if (qspi->master->busy)
return -EBUSY;
return 0;
}
static void zynqmp_qspi_filltxfifo(struct zynqmp_qspi *xqspi, int size)
{
u32 count = 0, intermediate;
while ((xqspi->bytes_to_transfer > 0) && (count < size)) {
memcpy(&intermediate, xqspi->txbuf, 4);
zynqmp_gqspi_write(xqspi, GQSPI_TXD_OFST, intermediate);
if (xqspi->bytes_to_transfer >= 4) {
xqspi->txbuf += 4;
xqspi->bytes_to_transfer -= 4;
} else {
xqspi->txbuf += xqspi->bytes_to_transfer;
xqspi->bytes_to_transfer = 0;
}
count++;
}
}
static void zynqmp_qspi_readrxfifo(struct zynqmp_qspi *xqspi, u32 size)
{
ulong data;
int count = 0;
while ((count < size) && (xqspi->bytes_to_receive > 0)) {
if (xqspi->bytes_to_receive >= 4) {
(*(u32 *) xqspi->rxbuf) =
zynqmp_gqspi_read(xqspi, GQSPI_RXD_OFST);
xqspi->rxbuf += 4;
xqspi->bytes_to_receive -= 4;
count += 4;
} else {
data = zynqmp_gqspi_read(xqspi, GQSPI_RXD_OFST);
count += xqspi->bytes_to_receive;
zynqmp_qspi_copy_read_data(xqspi, data,
xqspi->bytes_to_receive);
xqspi->bytes_to_receive = 0;
}
}
}
static void zynqmp_process_dma_irq(struct zynqmp_qspi *xqspi)
{
u32 config_reg, genfifoentry;
dma_unmap_single(xqspi->dev, xqspi->dma_addr,
xqspi->dma_rx_bytes, DMA_FROM_DEVICE);
xqspi->rxbuf += xqspi->dma_rx_bytes;
xqspi->bytes_to_receive -= xqspi->dma_rx_bytes;
xqspi->dma_rx_bytes = 0;
zynqmp_gqspi_write(xqspi, GQSPI_QSPIDMA_DST_I_DIS_OFST,
GQSPI_QSPIDMA_DST_I_EN_DONE_MASK);
if (xqspi->bytes_to_receive > 0) {
config_reg = zynqmp_gqspi_read(xqspi, GQSPI_CONFIG_OFST);
config_reg &= ~GQSPI_CFG_MODE_EN_MASK;
zynqmp_gqspi_write(xqspi, GQSPI_CONFIG_OFST, config_reg);
genfifoentry = xqspi->genfifoentry;
genfifoentry |= xqspi->bytes_to_receive;
zynqmp_gqspi_write(xqspi, GQSPI_GEN_FIFO_OFST, genfifoentry);
zynqmp_gqspi_write(xqspi, GQSPI_GEN_FIFO_OFST, 0x0);
zynqmp_gqspi_write(xqspi, GQSPI_CONFIG_OFST,
(zynqmp_gqspi_read(xqspi, GQSPI_CONFIG_OFST) |
GQSPI_CFG_START_GEN_FIFO_MASK));
zynqmp_gqspi_write(xqspi, GQSPI_IER_OFST,
GQSPI_IER_GENFIFOEMPTY_MASK |
GQSPI_IER_RXNEMPTY_MASK |
GQSPI_IER_RXEMPTY_MASK);
}
}
static irqreturn_t zynqmp_qspi_irq(int irq, void *dev_id)
{
struct spi_master *master = dev_id;
struct zynqmp_qspi *xqspi = spi_master_get_devdata(master);
int ret = IRQ_NONE;
u32 status, mask, dma_status = 0;
status = zynqmp_gqspi_read(xqspi, GQSPI_ISR_OFST);
zynqmp_gqspi_write(xqspi, GQSPI_ISR_OFST, status);
mask = (status & ~(zynqmp_gqspi_read(xqspi, GQSPI_IMASK_OFST)));
if (xqspi->mode == GQSPI_MODE_DMA) {
dma_status =
zynqmp_gqspi_read(xqspi, GQSPI_QSPIDMA_DST_I_STS_OFST);
zynqmp_gqspi_write(xqspi, GQSPI_QSPIDMA_DST_I_STS_OFST,
dma_status);
}
if (mask & GQSPI_ISR_TXNOT_FULL_MASK) {
zynqmp_qspi_filltxfifo(xqspi, GQSPI_TX_FIFO_FILL);
ret = IRQ_HANDLED;
}
if (dma_status & GQSPI_QSPIDMA_DST_I_STS_DONE_MASK) {
zynqmp_process_dma_irq(xqspi);
ret = IRQ_HANDLED;
} else if (!(mask & GQSPI_IER_RXEMPTY_MASK) &&
(mask & GQSPI_IER_GENFIFOEMPTY_MASK)) {
zynqmp_qspi_readrxfifo(xqspi, GQSPI_RX_FIFO_FILL);
ret = IRQ_HANDLED;
}
if ((xqspi->bytes_to_receive == 0) && (xqspi->bytes_to_transfer == 0)
&& ((status & GQSPI_IRQ_MASK) == GQSPI_IRQ_MASK)) {
zynqmp_gqspi_write(xqspi, GQSPI_IDR_OFST, GQSPI_ISR_IDR_MASK);
spi_finalize_current_transfer(master);
ret = IRQ_HANDLED;
}
return ret;
}
static inline u32 zynqmp_qspi_selectspimode(struct zynqmp_qspi *xqspi,
u8 spimode)
{
u32 mask = 0;
switch (spimode) {
case GQSPI_SELECT_MODE_DUALSPI:
mask = GQSPI_GENFIFO_MODE_DUALSPI;
break;
case GQSPI_SELECT_MODE_QUADSPI:
mask = GQSPI_GENFIFO_MODE_QUADSPI;
break;
case GQSPI_SELECT_MODE_SPI:
mask = GQSPI_GENFIFO_MODE_SPI;
break;
default:
dev_warn(xqspi->dev, "Invalid SPI mode\n");
}
return mask;
}
static void zynq_qspi_setuprxdma(struct zynqmp_qspi *xqspi)
{
u32 rx_bytes, rx_rem, config_reg;
dma_addr_t addr;
u64 dma_align = (u64)(uintptr_t)xqspi->rxbuf;
if ((xqspi->bytes_to_receive < 8) ||
((dma_align & GQSPI_DMA_UNALIGN) != 0x0)) {
config_reg = zynqmp_gqspi_read(xqspi, GQSPI_CONFIG_OFST);
config_reg &= ~GQSPI_CFG_MODE_EN_MASK;
zynqmp_gqspi_write(xqspi, GQSPI_CONFIG_OFST, config_reg);
xqspi->mode = GQSPI_MODE_IO;
xqspi->dma_rx_bytes = 0;
return;
}
rx_rem = xqspi->bytes_to_receive % 4;
rx_bytes = (xqspi->bytes_to_receive - rx_rem);
addr = dma_map_single(xqspi->dev, (void *)xqspi->rxbuf,
rx_bytes, DMA_FROM_DEVICE);
if (dma_mapping_error(xqspi->dev, addr))
dev_err(xqspi->dev, "ERR:rxdma:memory not mapped\n");
xqspi->dma_rx_bytes = rx_bytes;
xqspi->dma_addr = addr;
zynqmp_gqspi_write(xqspi, GQSPI_QSPIDMA_DST_ADDR_OFST,
(u32)(addr & 0xffffffff));
addr = ((addr >> 16) >> 16);
zynqmp_gqspi_write(xqspi, GQSPI_QSPIDMA_DST_ADDR_MSB_OFST,
((u32)addr) & 0xfff);
config_reg = zynqmp_gqspi_read(xqspi, GQSPI_CONFIG_OFST);
config_reg &= ~GQSPI_CFG_MODE_EN_MASK;
config_reg |= GQSPI_CFG_MODE_EN_DMA_MASK;
zynqmp_gqspi_write(xqspi, GQSPI_CONFIG_OFST, config_reg);
xqspi->mode = GQSPI_MODE_DMA;
zynqmp_gqspi_write(xqspi, GQSPI_QSPIDMA_DST_SIZE_OFST, rx_bytes);
}
static void zynqmp_qspi_txrxsetup(struct zynqmp_qspi *xqspi,
struct spi_transfer *transfer,
u32 *genfifoentry)
{
u32 config_reg;
if ((xqspi->txbuf != NULL) && (xqspi->rxbuf == NULL)) {
*genfifoentry &= ~GQSPI_GENFIFO_RX;
*genfifoentry |= GQSPI_GENFIFO_DATA_XFER;
*genfifoentry |= GQSPI_GENFIFO_TX;
*genfifoentry |=
zynqmp_qspi_selectspimode(xqspi, transfer->tx_nbits);
xqspi->bytes_to_transfer = transfer->len;
if (xqspi->mode == GQSPI_MODE_DMA) {
config_reg = zynqmp_gqspi_read(xqspi,
GQSPI_CONFIG_OFST);
config_reg &= ~GQSPI_CFG_MODE_EN_MASK;
zynqmp_gqspi_write(xqspi, GQSPI_CONFIG_OFST,
config_reg);
xqspi->mode = GQSPI_MODE_IO;
}
zynqmp_qspi_filltxfifo(xqspi, GQSPI_TXD_DEPTH);
xqspi->bytes_to_receive = 0;
} else if ((xqspi->txbuf == NULL) && (xqspi->rxbuf != NULL)) {
*genfifoentry &= ~GQSPI_GENFIFO_TX;
*genfifoentry |= GQSPI_GENFIFO_DATA_XFER;
*genfifoentry |= GQSPI_GENFIFO_RX;
*genfifoentry |=
zynqmp_qspi_selectspimode(xqspi, transfer->rx_nbits);
xqspi->bytes_to_transfer = 0;
xqspi->bytes_to_receive = transfer->len;
zynq_qspi_setuprxdma(xqspi);
}
}
static int zynqmp_qspi_start_transfer(struct spi_master *master,
struct spi_device *qspi,
struct spi_transfer *transfer)
{
struct zynqmp_qspi *xqspi = spi_master_get_devdata(master);
u32 genfifoentry = 0x0, transfer_len;
xqspi->txbuf = transfer->tx_buf;
xqspi->rxbuf = transfer->rx_buf;
zynqmp_qspi_setup_transfer(qspi, transfer);
genfifoentry |= xqspi->genfifocs;
genfifoentry |= xqspi->genfifobus;
zynqmp_qspi_txrxsetup(xqspi, transfer, &genfifoentry);
if (xqspi->mode == GQSPI_MODE_DMA)
transfer_len = xqspi->dma_rx_bytes;
else
transfer_len = transfer->len;
xqspi->genfifoentry = genfifoentry;
if ((transfer_len) < GQSPI_GENFIFO_IMM_DATA_MASK) {
genfifoentry &= ~GQSPI_GENFIFO_IMM_DATA_MASK;
genfifoentry |= transfer_len;
zynqmp_gqspi_write(xqspi, GQSPI_GEN_FIFO_OFST, genfifoentry);
} else {
int tempcount = transfer_len;
u32 exponent = 8;
u8 imm_data = tempcount & 0xFF;
tempcount &= ~(tempcount & 0xFF);
if (tempcount != 0) {
genfifoentry |= GQSPI_GENFIFO_EXP;
while (tempcount != 0) {
if (tempcount & GQSPI_GENFIFO_EXP_START) {
genfifoentry &=
~GQSPI_GENFIFO_IMM_DATA_MASK;
genfifoentry |= exponent;
zynqmp_gqspi_write(xqspi,
GQSPI_GEN_FIFO_OFST,
genfifoentry);
}
tempcount = tempcount >> 1;
exponent++;
}
}
if (imm_data != 0) {
genfifoentry &= ~GQSPI_GENFIFO_EXP;
genfifoentry &= ~GQSPI_GENFIFO_IMM_DATA_MASK;
genfifoentry |= (u8) (imm_data & 0xFF);
zynqmp_gqspi_write(xqspi,
GQSPI_GEN_FIFO_OFST, genfifoentry);
}
}
if ((xqspi->mode == GQSPI_MODE_IO) &&
(xqspi->rxbuf != NULL)) {
zynqmp_gqspi_write(xqspi, GQSPI_GEN_FIFO_OFST, 0x0);
}
zynqmp_gqspi_write(xqspi, GQSPI_CONFIG_OFST,
zynqmp_gqspi_read(xqspi, GQSPI_CONFIG_OFST) |
GQSPI_CFG_START_GEN_FIFO_MASK);
if (xqspi->txbuf != NULL)
zynqmp_gqspi_write(xqspi, GQSPI_IER_OFST,
GQSPI_IER_TXEMPTY_MASK |
GQSPI_IER_GENFIFOEMPTY_MASK |
GQSPI_IER_TXNOT_FULL_MASK);
if (xqspi->rxbuf != NULL) {
if (xqspi->mode == GQSPI_MODE_DMA) {
zynqmp_gqspi_write(xqspi,
GQSPI_QSPIDMA_DST_I_EN_OFST,
GQSPI_QSPIDMA_DST_I_EN_DONE_MASK);
} else {
zynqmp_gqspi_write(xqspi, GQSPI_IER_OFST,
GQSPI_IER_GENFIFOEMPTY_MASK |
GQSPI_IER_RXNEMPTY_MASK |
GQSPI_IER_RXEMPTY_MASK);
}
}
return transfer->len;
}
static int __maybe_unused zynqmp_qspi_suspend(struct device *dev)
{
struct platform_device *pdev = container_of(dev,
struct platform_device,
dev);
struct spi_master *master = platform_get_drvdata(pdev);
spi_master_suspend(master);
zynqmp_unprepare_transfer_hardware(master);
return 0;
}
static int __maybe_unused zynqmp_qspi_resume(struct device *dev)
{
struct platform_device *pdev = container_of(dev,
struct platform_device,
dev);
struct spi_master *master = platform_get_drvdata(pdev);
struct zynqmp_qspi *xqspi = spi_master_get_devdata(master);
int ret = 0;
ret = clk_enable(xqspi->pclk);
if (ret) {
dev_err(dev, "Cannot enable APB clock.\n");
return ret;
}
ret = clk_enable(xqspi->refclk);
if (ret) {
dev_err(dev, "Cannot enable device clock.\n");
clk_disable(xqspi->pclk);
return ret;
}
spi_master_resume(master);
return 0;
}
static int zynqmp_qspi_probe(struct platform_device *pdev)
{
int ret = 0;
struct spi_master *master;
struct zynqmp_qspi *xqspi;
struct resource *res;
struct device *dev = &pdev->dev;
master = spi_alloc_master(&pdev->dev, sizeof(*xqspi));
if (!master)
return -ENOMEM;
xqspi = spi_master_get_devdata(master);
master->dev.of_node = pdev->dev.of_node;
platform_set_drvdata(pdev, master);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
xqspi->regs = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(xqspi->regs)) {
ret = PTR_ERR(xqspi->regs);
goto remove_master;
}
xqspi->dev = dev;
xqspi->pclk = devm_clk_get(&pdev->dev, "pclk");
if (IS_ERR(xqspi->pclk)) {
dev_err(dev, "pclk clock not found.\n");
ret = PTR_ERR(xqspi->pclk);
goto remove_master;
}
ret = clk_prepare_enable(xqspi->pclk);
if (ret) {
dev_err(dev, "Unable to enable APB clock.\n");
goto remove_master;
}
xqspi->refclk = devm_clk_get(&pdev->dev, "ref_clk");
if (IS_ERR(xqspi->refclk)) {
dev_err(dev, "ref_clk clock not found.\n");
ret = PTR_ERR(xqspi->refclk);
goto clk_dis_pclk;
}
ret = clk_prepare_enable(xqspi->refclk);
if (ret) {
dev_err(dev, "Unable to enable device clock.\n");
goto clk_dis_pclk;
}
zynqmp_qspi_init_hw(xqspi);
xqspi->irq = platform_get_irq(pdev, 0);
if (xqspi->irq <= 0) {
ret = -ENXIO;
dev_err(dev, "irq resource not found\n");
goto clk_dis_all;
}
ret = devm_request_irq(&pdev->dev, xqspi->irq, zynqmp_qspi_irq,
0, pdev->name, master);
if (ret != 0) {
ret = -ENXIO;
dev_err(dev, "request_irq failed\n");
goto clk_dis_all;
}
master->num_chipselect = GQSPI_DEFAULT_NUM_CS;
master->setup = zynqmp_qspi_setup;
master->set_cs = zynqmp_qspi_chipselect;
master->transfer_one = zynqmp_qspi_start_transfer;
master->prepare_transfer_hardware = zynqmp_prepare_transfer_hardware;
master->unprepare_transfer_hardware =
zynqmp_unprepare_transfer_hardware;
master->max_speed_hz = clk_get_rate(xqspi->refclk) / 2;
master->bits_per_word_mask = SPI_BPW_MASK(8);
master->mode_bits = SPI_CPOL | SPI_CPHA | SPI_RX_DUAL | SPI_RX_QUAD |
SPI_TX_DUAL | SPI_TX_QUAD;
if (master->dev.parent == NULL)
master->dev.parent = &master->dev;
ret = spi_register_master(master);
if (ret)
goto clk_dis_all;
return 0;
clk_dis_all:
clk_disable_unprepare(xqspi->refclk);
clk_dis_pclk:
clk_disable_unprepare(xqspi->pclk);
remove_master:
spi_master_put(master);
return ret;
}
static int zynqmp_qspi_remove(struct platform_device *pdev)
{
struct spi_master *master = platform_get_drvdata(pdev);
struct zynqmp_qspi *xqspi = spi_master_get_devdata(master);
zynqmp_gqspi_write(xqspi, GQSPI_EN_OFST, 0x0);
clk_disable_unprepare(xqspi->refclk);
clk_disable_unprepare(xqspi->pclk);
spi_unregister_master(master);
return 0;
}
