static inline u32 spfi_readl(struct img_spfi *spfi, u32 reg)
{
return readl(spfi->regs + reg);
}
static inline void spfi_writel(struct img_spfi *spfi, u32 val, u32 reg)
{
writel(val, spfi->regs + reg);
}
static inline void spfi_start(struct img_spfi *spfi)
{
u32 val;
val = spfi_readl(spfi, SPFI_CONTROL);
val |= SPFI_CONTROL_SPFI_EN;
spfi_writel(spfi, val, SPFI_CONTROL);
}
static inline void spfi_stop(struct img_spfi *spfi)
{
u32 val;
val = spfi_readl(spfi, SPFI_CONTROL);
val &= ~SPFI_CONTROL_SPFI_EN;
spfi_writel(spfi, val, SPFI_CONTROL);
}
static inline void spfi_reset(struct img_spfi *spfi)
{
spfi_writel(spfi, SPFI_CONTROL_SOFT_RESET, SPFI_CONTROL);
udelay(1);
spfi_writel(spfi, 0, SPFI_CONTROL);
}
static void spfi_flush_tx_fifo(struct img_spfi *spfi)
{
unsigned long timeout = jiffies + msecs_to_jiffies(10);
spfi_writel(spfi, SPFI_INTERRUPT_SDE, SPFI_INTERRUPT_CLEAR);
while (time_before(jiffies, timeout)) {
if (spfi_readl(spfi, SPFI_INTERRUPT_STATUS) &
SPFI_INTERRUPT_SDE)
return;
cpu_relax();
}
dev_err(spfi->dev, "Timed out waiting for FIFO to drain\n");
spfi_reset(spfi);
}
static unsigned int spfi_pio_write32(struct img_spfi *spfi, const u32 *buf,
unsigned int max)
{
unsigned int count = 0;
u32 status;
while (count < max / 4) {
spfi_writel(spfi, SPFI_INTERRUPT_SDFUL, SPFI_INTERRUPT_CLEAR);
status = spfi_readl(spfi, SPFI_INTERRUPT_STATUS);
if (status & SPFI_INTERRUPT_SDFUL)
break;
spfi_writel(spfi, buf[count], SPFI_TX_32BIT_VALID_DATA);
count++;
}
return count * 4;
}
static unsigned int spfi_pio_write8(struct img_spfi *spfi, const u8 *buf,
unsigned int max)
{
unsigned int count = 0;
u32 status;
while (count < max) {
spfi_writel(spfi, SPFI_INTERRUPT_SDFUL, SPFI_INTERRUPT_CLEAR);
status = spfi_readl(spfi, SPFI_INTERRUPT_STATUS);
if (status & SPFI_INTERRUPT_SDFUL)
break;
spfi_writel(spfi, buf[count], SPFI_TX_8BIT_VALID_DATA);
count++;
}
return count;
}
static unsigned int spfi_pio_read32(struct img_spfi *spfi, u32 *buf,
unsigned int max)
{
unsigned int count = 0;
u32 status;
while (count < max / 4) {
spfi_writel(spfi, SPFI_INTERRUPT_GDEX32BIT,
SPFI_INTERRUPT_CLEAR);
status = spfi_readl(spfi, SPFI_INTERRUPT_STATUS);
if (!(status & SPFI_INTERRUPT_GDEX32BIT))
break;
buf[count] = spfi_readl(spfi, SPFI_RX_32BIT_VALID_DATA);
count++;
}
return count * 4;
}
static unsigned int spfi_pio_read8(struct img_spfi *spfi, u8 *buf,
unsigned int max)
{
unsigned int count = 0;
u32 status;
while (count < max) {
spfi_writel(spfi, SPFI_INTERRUPT_GDEX8BIT,
SPFI_INTERRUPT_CLEAR);
status = spfi_readl(spfi, SPFI_INTERRUPT_STATUS);
if (!(status & SPFI_INTERRUPT_GDEX8BIT))
break;
buf[count] = spfi_readl(spfi, SPFI_RX_8BIT_VALID_DATA);
count++;
}
return count;
}
static int img_spfi_start_pio(struct spi_master *master,
struct spi_device *spi,
struct spi_transfer *xfer)
{
struct img_spfi *spfi = spi_master_get_devdata(spi->master);
unsigned int tx_bytes = 0, rx_bytes = 0;
const void *tx_buf = xfer->tx_buf;
void *rx_buf = xfer->rx_buf;
unsigned long timeout;
if (tx_buf)
tx_bytes = xfer->len;
if (rx_buf)
rx_bytes = xfer->len;
spfi_start(spfi);
timeout = jiffies +
msecs_to_jiffies(xfer->len * 8 * 1000 / xfer->speed_hz + 100);
while ((tx_bytes > 0 || rx_bytes > 0) &&
time_before(jiffies, timeout)) {
unsigned int tx_count, rx_count;
if (tx_bytes >= 4)
tx_count = spfi_pio_write32(spfi, tx_buf, tx_bytes);
else
tx_count = spfi_pio_write8(spfi, tx_buf, tx_bytes);
if (rx_bytes >= 4)
rx_count = spfi_pio_read32(spfi, rx_buf, rx_bytes);
else
rx_count = spfi_pio_read8(spfi, rx_buf, rx_bytes);
tx_buf += tx_count;
rx_buf += rx_count;
tx_bytes -= tx_count;
rx_bytes -= rx_count;
cpu_relax();
}
if (rx_bytes > 0 || tx_bytes > 0) {
dev_err(spfi->dev, "PIO transfer timed out\n");
spfi_reset(spfi);
return -ETIMEDOUT;
}
if (tx_buf)
spfi_flush_tx_fifo(spfi);
spfi_stop(spfi);
return 0;
}
static void img_spfi_dma_rx_cb(void *data)
{
struct img_spfi *spfi = data;
unsigned long flags;
spin_lock_irqsave(&spfi->lock, flags);
spfi->rx_dma_busy = false;
if (!spfi->tx_dma_busy) {
spfi_stop(spfi);
spi_finalize_current_transfer(spfi->master);
}
spin_unlock_irqrestore(&spfi->lock, flags);
}
static void img_spfi_dma_tx_cb(void *data)
{
struct img_spfi *spfi = data;
unsigned long flags;
spfi_flush_tx_fifo(spfi);
spin_lock_irqsave(&spfi->lock, flags);
spfi->tx_dma_busy = false;
if (!spfi->rx_dma_busy) {
spfi_stop(spfi);
spi_finalize_current_transfer(spfi->master);
}
spin_unlock_irqrestore(&spfi->lock, flags);
}
static int img_spfi_start_dma(struct spi_master *master,
struct spi_device *spi,
struct spi_transfer *xfer)
{
struct img_spfi *spfi = spi_master_get_devdata(spi->master);
struct dma_async_tx_descriptor *rxdesc = NULL, *txdesc = NULL;
struct dma_slave_config rxconf, txconf;
spfi->rx_dma_busy = false;
spfi->tx_dma_busy = false;
if (xfer->rx_buf) {
rxconf.direction = DMA_DEV_TO_MEM;
if (xfer->len % 4 == 0) {
rxconf.src_addr = spfi->phys + SPFI_RX_32BIT_VALID_DATA;
rxconf.src_addr_width = 4;
rxconf.src_maxburst = 4;
} else {
rxconf.src_addr = spfi->phys + SPFI_RX_8BIT_VALID_DATA;
rxconf.src_addr_width = 1;
rxconf.src_maxburst = 4;
}
dmaengine_slave_config(spfi->rx_ch, &rxconf);
rxdesc = dmaengine_prep_slave_sg(spfi->rx_ch, xfer->rx_sg.sgl,
xfer->rx_sg.nents,
DMA_DEV_TO_MEM,
DMA_PREP_INTERRUPT);
if (!rxdesc)
goto stop_dma;
rxdesc->callback = img_spfi_dma_rx_cb;
rxdesc->callback_param = spfi;
}
if (xfer->tx_buf) {
txconf.direction = DMA_MEM_TO_DEV;
if (xfer->len % 4 == 0) {
txconf.dst_addr = spfi->phys + SPFI_TX_32BIT_VALID_DATA;
txconf.dst_addr_width = 4;
txconf.dst_maxburst = 4;
} else {
txconf.dst_addr = spfi->phys + SPFI_TX_8BIT_VALID_DATA;
txconf.dst_addr_width = 1;
txconf.dst_maxburst = 4;
}
dmaengine_slave_config(spfi->tx_ch, &txconf);
txdesc = dmaengine_prep_slave_sg(spfi->tx_ch, xfer->tx_sg.sgl,
xfer->tx_sg.nents,
DMA_MEM_TO_DEV,
DMA_PREP_INTERRUPT);
if (!txdesc)
goto stop_dma;
txdesc->callback = img_spfi_dma_tx_cb;
txdesc->callback_param = spfi;
}
if (xfer->rx_buf) {
spfi->rx_dma_busy = true;
dmaengine_submit(rxdesc);
dma_async_issue_pending(spfi->rx_ch);
}
spfi_start(spfi);
if (xfer->tx_buf) {
spfi->tx_dma_busy = true;
dmaengine_submit(txdesc);
dma_async_issue_pending(spfi->tx_ch);
}
return 1;
stop_dma:
dmaengine_terminate_all(spfi->rx_ch);
dmaengine_terminate_all(spfi->tx_ch);
return -EIO;
}
static void img_spfi_config(struct spi_master *master, struct spi_device *spi,
struct spi_transfer *xfer)
{
struct img_spfi *spfi = spi_master_get_devdata(spi->master);
u32 val, div;
div = DIV_ROUND_UP(master->max_speed_hz, xfer->speed_hz);
div = clamp(512 / (1 << get_count_order(div)), 1, 255);
val = spfi_readl(spfi, SPFI_DEVICE_PARAMETER(spi->chip_select));
val &= ~(SPFI_DEVICE_PARAMETER_BITCLK_MASK <<
SPFI_DEVICE_PARAMETER_BITCLK_SHIFT);
val |= div << SPFI_DEVICE_PARAMETER_BITCLK_SHIFT;
spfi_writel(spfi, val, SPFI_DEVICE_PARAMETER(spi->chip_select));
val = spfi_readl(spfi, SPFI_CONTROL);
val &= ~(SPFI_CONTROL_SEND_DMA | SPFI_CONTROL_GET_DMA);
if (xfer->tx_buf)
val |= SPFI_CONTROL_SEND_DMA;
if (xfer->rx_buf)
val |= SPFI_CONTROL_GET_DMA;
val &= ~(SPFI_CONTROL_TMODE_MASK << SPFI_CONTROL_TMODE_SHIFT);
if (xfer->tx_nbits == SPI_NBITS_DUAL &&
xfer->rx_nbits == SPI_NBITS_DUAL)
val |= SPFI_CONTROL_TMODE_DUAL << SPFI_CONTROL_TMODE_SHIFT;
else if (xfer->tx_nbits == SPI_NBITS_QUAD &&
xfer->rx_nbits == SPI_NBITS_QUAD)
val |= SPFI_CONTROL_TMODE_QUAD << SPFI_CONTROL_TMODE_SHIFT;
val &= ~SPFI_CONTROL_CONTINUE;
if (!xfer->cs_change && !list_is_last(&xfer->transfer_list,
&master->cur_msg->transfers))
val |= SPFI_CONTROL_CONTINUE;
spfi_writel(spfi, val, SPFI_CONTROL);
val = spfi_readl(spfi, SPFI_PORT_STATE);
if (spi->mode & SPI_CPHA)
val |= SPFI_PORT_STATE_CK_PHASE(spi->chip_select);
else
val &= ~SPFI_PORT_STATE_CK_PHASE(spi->chip_select);
if (spi->mode & SPI_CPOL)
val |= SPFI_PORT_STATE_CK_POL(spi->chip_select);
else
val &= ~SPFI_PORT_STATE_CK_POL(spi->chip_select);
spfi_writel(spfi, val, SPFI_PORT_STATE);
spfi_writel(spfi, xfer->len << SPFI_TRANSACTION_TSIZE_SHIFT,
SPFI_TRANSACTION);
}
static int img_spfi_transfer_one(struct spi_master *master,
struct spi_device *spi,
struct spi_transfer *xfer)
{
struct img_spfi *spfi = spi_master_get_devdata(spi->master);
bool dma_reset = false;
unsigned long flags;
int ret;
if (xfer->len > SPFI_TRANSACTION_TSIZE_MASK) {
dev_err(spfi->dev,
"Transfer length (%d) is greater than the max supported (%d)",
xfer->len, SPFI_TRANSACTION_TSIZE_MASK);
return -EINVAL;
}
spin_lock_irqsave(&spfi->lock, flags);
if (spfi->tx_dma_busy || spfi->rx_dma_busy) {
dev_err(spfi->dev, "SPI DMA still busy\n");
dma_reset = true;
}
spin_unlock_irqrestore(&spfi->lock, flags);
if (dma_reset) {
dmaengine_terminate_all(spfi->tx_ch);
dmaengine_terminate_all(spfi->rx_ch);
spfi_reset(spfi);
}
img_spfi_config(master, spi, xfer);
if (master->can_dma && master->can_dma(master, spi, xfer))
ret = img_spfi_start_dma(master, spi, xfer);
else
ret = img_spfi_start_pio(master, spi, xfer);
return ret;
}
static void img_spfi_set_cs(struct spi_device *spi, bool enable)
{
struct img_spfi *spfi = spi_master_get_devdata(spi->master);
u32 val;
val = spfi_readl(spfi, SPFI_PORT_STATE);
val &= ~(SPFI_PORT_STATE_DEV_SEL_MASK << SPFI_PORT_STATE_DEV_SEL_SHIFT);
val |= spi->chip_select << SPFI_PORT_STATE_DEV_SEL_SHIFT;
spfi_writel(spfi, val, SPFI_PORT_STATE);
}
static bool img_spfi_can_dma(struct spi_master *master, struct spi_device *spi,
struct spi_transfer *xfer)
{
if (xfer->len > SPFI_32BIT_FIFO_SIZE)
return true;
return false;
}
static irqreturn_t img_spfi_irq(int irq, void *dev_id)
{
struct img_spfi *spfi = (struct img_spfi *)dev_id;
u32 status;
status = spfi_readl(spfi, SPFI_INTERRUPT_STATUS);
if (status & SPFI_INTERRUPT_IACCESS) {
spfi_writel(spfi, SPFI_INTERRUPT_IACCESS, SPFI_INTERRUPT_CLEAR);
dev_err(spfi->dev, "Illegal access interrupt");
return IRQ_HANDLED;
}
return IRQ_NONE;
}
static int img_spfi_probe(struct platform_device *pdev)
{
struct spi_master *master;
struct img_spfi *spfi;
struct resource *res;
int ret;
master = spi_alloc_master(&pdev->dev, sizeof(*spfi));
if (!master)
return -ENOMEM;
platform_set_drvdata(pdev, master);
spfi = spi_master_get_devdata(master);
spfi->dev = &pdev->dev;
spfi->master = master;
spin_lock_init(&spfi->lock);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
spfi->regs = devm_ioremap_resource(spfi->dev, res);
if (IS_ERR(spfi->regs)) {
ret = PTR_ERR(spfi->regs);
goto put_spi;
}
spfi->phys = res->start;
spfi->irq = platform_get_irq(pdev, 0);
if (spfi->irq < 0) {
ret = spfi->irq;
goto put_spi;
}
ret = devm_request_irq(spfi->dev, spfi->irq, img_spfi_irq,
IRQ_TYPE_LEVEL_HIGH, dev_name(spfi->dev), spfi);
if (ret)
goto put_spi;
spfi->sys_clk = devm_clk_get(spfi->dev, "sys");
if (IS_ERR(spfi->sys_clk)) {
ret = PTR_ERR(spfi->sys_clk);
goto put_spi;
}
spfi->spfi_clk = devm_clk_get(spfi->dev, "spfi");
if (IS_ERR(spfi->spfi_clk)) {
ret = PTR_ERR(spfi->spfi_clk);
goto put_spi;
}
ret = clk_prepare_enable(spfi->sys_clk);
if (ret)
goto put_spi;
ret = clk_prepare_enable(spfi->spfi_clk);
if (ret)
goto disable_pclk;
spfi_reset(spfi);
spfi_writel(spfi, SPFI_INTERRUPT_IACCESS, SPFI_INTERRUPT_ENABLE);
master->auto_runtime_pm = true;
master->bus_num = pdev->id;
master->mode_bits = SPI_CPOL | SPI_CPHA | SPI_TX_DUAL | SPI_RX_DUAL;
if (of_property_read_bool(spfi->dev->of_node, "img,supports-quad-mode"))
master->mode_bits |= SPI_TX_QUAD | SPI_RX_QUAD;
master->num_chipselect = 5;
master->dev.of_node = pdev->dev.of_node;
master->bits_per_word_mask = SPI_BPW_MASK(32) | SPI_BPW_MASK(8);
master->max_speed_hz = clk_get_rate(spfi->spfi_clk);
master->min_speed_hz = master->max_speed_hz / 512;
master->set_cs = img_spfi_set_cs;
master->transfer_one = img_spfi_transfer_one;
spfi->tx_ch = dma_request_slave_channel(spfi->dev, "tx");
spfi->rx_ch = dma_request_slave_channel(spfi->dev, "rx");
if (!spfi->tx_ch || !spfi->rx_ch) {
if (spfi->tx_ch)
dma_release_channel(spfi->tx_ch);
if (spfi->rx_ch)
dma_release_channel(spfi->rx_ch);
dev_warn(spfi->dev, "Failed to get DMA channels, falling back to PIO mode\n");
} else {
master->dma_tx = spfi->tx_ch;
master->dma_rx = spfi->rx_ch;
master->can_dma = img_spfi_can_dma;
}
pm_runtime_set_active(spfi->dev);
pm_runtime_enable(spfi->dev);
ret = devm_spi_register_master(spfi->dev, master);
if (ret)
goto disable_pm;
return 0;
disable_pm:
pm_runtime_disable(spfi->dev);
if (spfi->rx_ch)
dma_release_channel(spfi->rx_ch);
if (spfi->tx_ch)
dma_release_channel(spfi->tx_ch);
clk_disable_unprepare(spfi->spfi_clk);
disable_pclk:
clk_disable_unprepare(spfi->sys_clk);
put_spi:
spi_master_put(master);
return ret;
}
static int img_spfi_remove(struct platform_device *pdev)
{
struct spi_master *master = platform_get_drvdata(pdev);
struct img_spfi *spfi = spi_master_get_devdata(master);
if (spfi->tx_ch)
dma_release_channel(spfi->tx_ch);
if (spfi->rx_ch)
dma_release_channel(spfi->rx_ch);
pm_runtime_disable(spfi->dev);
if (!pm_runtime_status_suspended(spfi->dev)) {
clk_disable_unprepare(spfi->spfi_clk);
clk_disable_unprepare(spfi->sys_clk);
}
spi_master_put(master);
return 0;
}
static int img_spfi_runtime_suspend(struct device *dev)
{
struct spi_master *master = dev_get_drvdata(dev);
struct img_spfi *spfi = spi_master_get_devdata(master);
clk_disable_unprepare(spfi->spfi_clk);
clk_disable_unprepare(spfi->sys_clk);
return 0;
}
static int img_spfi_runtime_resume(struct device *dev)
{
struct spi_master *master = dev_get_drvdata(dev);
struct img_spfi *spfi = spi_master_get_devdata(master);
int ret;
ret = clk_prepare_enable(spfi->sys_clk);
if (ret)
return ret;
ret = clk_prepare_enable(spfi->spfi_clk);
if (ret) {
clk_disable_unprepare(spfi->sys_clk);
return ret;
}
return 0;
}
static int img_spfi_suspend(struct device *dev)
{
struct spi_master *master = dev_get_drvdata(dev);
return spi_master_suspend(master);
}
static int img_spfi_resume(struct device *dev)
{
struct spi_master *master = dev_get_drvdata(dev);
struct img_spfi *spfi = spi_master_get_devdata(master);
int ret;
ret = pm_runtime_get_sync(dev);
if (ret)
return ret;
spfi_reset(spfi);
pm_runtime_put(dev);
return spi_master_resume(master);
}
