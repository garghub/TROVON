static inline void spi_enable_chip(struct rockchip_spi *rs, int enable)
{
writel_relaxed((enable ? 1 : 0), rs->regs + ROCKCHIP_SPI_SSIENR);
}
static inline void spi_set_clk(struct rockchip_spi *rs, u16 div)
{
writel_relaxed(div, rs->regs + ROCKCHIP_SPI_BAUDR);
}
static inline void flush_fifo(struct rockchip_spi *rs)
{
while (readl_relaxed(rs->regs + ROCKCHIP_SPI_RXFLR))
readl_relaxed(rs->regs + ROCKCHIP_SPI_RXDR);
}
static inline void wait_for_idle(struct rockchip_spi *rs)
{
unsigned long timeout = jiffies + msecs_to_jiffies(5);
do {
if (!(readl_relaxed(rs->regs + ROCKCHIP_SPI_SR) & SR_BUSY))
return;
} while (!time_after(jiffies, timeout));
dev_warn(rs->dev, "spi controller is in busy state!\n");
}
static u32 get_fifo_len(struct rockchip_spi *rs)
{
u32 fifo;
for (fifo = 2; fifo < 32; fifo++) {
writel_relaxed(fifo, rs->regs + ROCKCHIP_SPI_TXFTLR);
if (fifo != readl_relaxed(rs->regs + ROCKCHIP_SPI_TXFTLR))
break;
}
writel_relaxed(0, rs->regs + ROCKCHIP_SPI_TXFTLR);
return (fifo == 31) ? 0 : fifo;
}
static inline u32 tx_max(struct rockchip_spi *rs)
{
u32 tx_left, tx_room;
tx_left = (rs->tx_end - rs->tx) / rs->n_bytes;
tx_room = rs->fifo_len - readl_relaxed(rs->regs + ROCKCHIP_SPI_TXFLR);
return min(tx_left, tx_room);
}
static inline u32 rx_max(struct rockchip_spi *rs)
{
u32 rx_left = (rs->rx_end - rs->rx) / rs->n_bytes;
u32 rx_room = (u32)readl_relaxed(rs->regs + ROCKCHIP_SPI_RXFLR);
return min(rx_left, rx_room);
}
static void rockchip_spi_set_cs(struct spi_device *spi, bool enable)
{
u32 ser;
struct rockchip_spi *rs = spi_master_get_devdata(spi->master);
ser = readl_relaxed(rs->regs + ROCKCHIP_SPI_SER) & SER_MASK;
if (!enable)
ser |= 1 << spi->chip_select;
else
ser &= ~(1 << spi->chip_select);
writel_relaxed(ser, rs->regs + ROCKCHIP_SPI_SER);
}
static int rockchip_spi_prepare_message(struct spi_master *master,
struct spi_message *msg)
{
struct rockchip_spi *rs = spi_master_get_devdata(master);
struct spi_device *spi = msg->spi;
rs->mode = spi->mode;
return 0;
}
static void rockchip_spi_handle_err(struct spi_master *master,
struct spi_message *msg)
{
unsigned long flags;
struct rockchip_spi *rs = spi_master_get_devdata(master);
spin_lock_irqsave(&rs->lock, flags);
if (rs->use_dma) {
if (rs->state & RXBUSY) {
dmaengine_terminate_all(rs->dma_rx.ch);
flush_fifo(rs);
}
if (rs->state & TXBUSY)
dmaengine_terminate_all(rs->dma_tx.ch);
}
spin_unlock_irqrestore(&rs->lock, flags);
}
static int rockchip_spi_unprepare_message(struct spi_master *master,
struct spi_message *msg)
{
struct rockchip_spi *rs = spi_master_get_devdata(master);
spi_enable_chip(rs, 0);
return 0;
}
static void rockchip_spi_pio_writer(struct rockchip_spi *rs)
{
u32 max = tx_max(rs);
u32 txw = 0;
while (max--) {
if (rs->n_bytes == 1)
txw = *(u8 *)(rs->tx);
else
txw = *(u16 *)(rs->tx);
writel_relaxed(txw, rs->regs + ROCKCHIP_SPI_TXDR);
rs->tx += rs->n_bytes;
}
}
static void rockchip_spi_pio_reader(struct rockchip_spi *rs)
{
u32 max = rx_max(rs);
u32 rxw;
while (max--) {
rxw = readl_relaxed(rs->regs + ROCKCHIP_SPI_RXDR);
if (rs->n_bytes == 1)
*(u8 *)(rs->rx) = (u8)rxw;
else
*(u16 *)(rs->rx) = (u16)rxw;
rs->rx += rs->n_bytes;
}
}
static int rockchip_spi_pio_transfer(struct rockchip_spi *rs)
{
int remain = 0;
do {
if (rs->tx) {
remain = rs->tx_end - rs->tx;
rockchip_spi_pio_writer(rs);
}
if (rs->rx) {
remain = rs->rx_end - rs->rx;
rockchip_spi_pio_reader(rs);
}
cpu_relax();
} while (remain);
if (rs->tx)
wait_for_idle(rs);
spi_enable_chip(rs, 0);
return 0;
}
static void rockchip_spi_dma_rxcb(void *data)
{
unsigned long flags;
struct rockchip_spi *rs = data;
spin_lock_irqsave(&rs->lock, flags);
rs->state &= ~RXBUSY;
if (!(rs->state & TXBUSY)) {
spi_enable_chip(rs, 0);
spi_finalize_current_transfer(rs->master);
}
spin_unlock_irqrestore(&rs->lock, flags);
}
static void rockchip_spi_dma_txcb(void *data)
{
unsigned long flags;
struct rockchip_spi *rs = data;
wait_for_idle(rs);
spin_lock_irqsave(&rs->lock, flags);
rs->state &= ~TXBUSY;
if (!(rs->state & RXBUSY)) {
spi_enable_chip(rs, 0);
spi_finalize_current_transfer(rs->master);
}
spin_unlock_irqrestore(&rs->lock, flags);
}
static void rockchip_spi_prepare_dma(struct rockchip_spi *rs)
{
unsigned long flags;
struct dma_slave_config rxconf, txconf;
struct dma_async_tx_descriptor *rxdesc, *txdesc;
spin_lock_irqsave(&rs->lock, flags);
rs->state &= ~RXBUSY;
rs->state &= ~TXBUSY;
spin_unlock_irqrestore(&rs->lock, flags);
rxdesc = NULL;
if (rs->rx) {
rxconf.direction = rs->dma_rx.direction;
rxconf.src_addr = rs->dma_rx.addr;
rxconf.src_addr_width = rs->n_bytes;
rxconf.src_maxburst = rs->n_bytes;
dmaengine_slave_config(rs->dma_rx.ch, &rxconf);
rxdesc = dmaengine_prep_slave_sg(
rs->dma_rx.ch,
rs->rx_sg.sgl, rs->rx_sg.nents,
rs->dma_rx.direction, DMA_PREP_INTERRUPT);
rxdesc->callback = rockchip_spi_dma_rxcb;
rxdesc->callback_param = rs;
}
txdesc = NULL;
if (rs->tx) {
txconf.direction = rs->dma_tx.direction;
txconf.dst_addr = rs->dma_tx.addr;
txconf.dst_addr_width = rs->n_bytes;
txconf.dst_maxburst = rs->n_bytes;
dmaengine_slave_config(rs->dma_tx.ch, &txconf);
txdesc = dmaengine_prep_slave_sg(
rs->dma_tx.ch,
rs->tx_sg.sgl, rs->tx_sg.nents,
rs->dma_tx.direction, DMA_PREP_INTERRUPT);
txdesc->callback = rockchip_spi_dma_txcb;
txdesc->callback_param = rs;
}
if (rxdesc) {
spin_lock_irqsave(&rs->lock, flags);
rs->state |= RXBUSY;
spin_unlock_irqrestore(&rs->lock, flags);
dmaengine_submit(rxdesc);
dma_async_issue_pending(rs->dma_rx.ch);
}
if (txdesc) {
spin_lock_irqsave(&rs->lock, flags);
rs->state |= TXBUSY;
spin_unlock_irqrestore(&rs->lock, flags);
dmaengine_submit(txdesc);
dma_async_issue_pending(rs->dma_tx.ch);
}
}
static void rockchip_spi_config(struct rockchip_spi *rs)
{
u32 div = 0;
u32 dmacr = 0;
int rsd = 0;
u32 cr0 = (CR0_BHT_8BIT << CR0_BHT_OFFSET)
| (CR0_SSD_ONE << CR0_SSD_OFFSET);
cr0 |= (rs->n_bytes << CR0_DFS_OFFSET);
cr0 |= ((rs->mode & 0x3) << CR0_SCPH_OFFSET);
cr0 |= (rs->tmode << CR0_XFM_OFFSET);
cr0 |= (rs->type << CR0_FRF_OFFSET);
if (rs->use_dma) {
if (rs->tx)
dmacr |= TF_DMA_EN;
if (rs->rx)
dmacr |= RF_DMA_EN;
}
if (WARN_ON(rs->speed > MAX_SCLK_OUT))
rs->speed = MAX_SCLK_OUT;
if (rs->max_freq < 2 * rs->speed) {
clk_set_rate(rs->spiclk, 2 * rs->speed);
rs->max_freq = clk_get_rate(rs->spiclk);
}
div = DIV_ROUND_UP(rs->max_freq, rs->speed);
div = (div + 1) & 0xfffe;
rsd = DIV_ROUND_CLOSEST(rs->rsd_nsecs * (rs->max_freq >> 8),
1000000000 >> 8);
if (!rsd && rs->rsd_nsecs) {
pr_warn_once("rockchip-spi: %u Hz are too slow to express %u ns delay\n",
rs->max_freq, rs->rsd_nsecs);
} else if (rsd > 3) {
rsd = 3;
pr_warn_once("rockchip-spi: %u Hz are too fast to express %u ns delay, clamping at %u ns\n",
rs->max_freq, rs->rsd_nsecs,
rsd * 1000000000U / rs->max_freq);
}
cr0 |= rsd << CR0_RSD_OFFSET;
writel_relaxed(cr0, rs->regs + ROCKCHIP_SPI_CTRLR0);
writel_relaxed(rs->len - 1, rs->regs + ROCKCHIP_SPI_CTRLR1);
writel_relaxed(rs->fifo_len / 2 - 1, rs->regs + ROCKCHIP_SPI_TXFTLR);
writel_relaxed(rs->fifo_len / 2 - 1, rs->regs + ROCKCHIP_SPI_RXFTLR);
writel_relaxed(0, rs->regs + ROCKCHIP_SPI_DMATDLR);
writel_relaxed(0, rs->regs + ROCKCHIP_SPI_DMARDLR);
writel_relaxed(dmacr, rs->regs + ROCKCHIP_SPI_DMACR);
spi_set_clk(rs, div);
dev_dbg(rs->dev, "cr0 0x%x, div %d\n", cr0, div);
}
static int rockchip_spi_transfer_one(
struct spi_master *master,
struct spi_device *spi,
struct spi_transfer *xfer)
{
int ret = 1;
struct rockchip_spi *rs = spi_master_get_devdata(master);
WARN_ON(readl_relaxed(rs->regs + ROCKCHIP_SPI_SSIENR) &&
(readl_relaxed(rs->regs + ROCKCHIP_SPI_SR) & SR_BUSY));
if (!xfer->tx_buf && !xfer->rx_buf) {
dev_err(rs->dev, "No buffer for transfer\n");
return -EINVAL;
}
rs->speed = xfer->speed_hz;
rs->bpw = xfer->bits_per_word;
rs->n_bytes = rs->bpw >> 3;
rs->tx = xfer->tx_buf;
rs->tx_end = rs->tx + xfer->len;
rs->rx = xfer->rx_buf;
rs->rx_end = rs->rx + xfer->len;
rs->len = xfer->len;
rs->tx_sg = xfer->tx_sg;
rs->rx_sg = xfer->rx_sg;
if (rs->tx && rs->rx)
rs->tmode = CR0_XFM_TR;
else if (rs->tx)
rs->tmode = CR0_XFM_TO;
else if (rs->rx)
rs->tmode = CR0_XFM_RO;
if (master->can_dma && master->can_dma(master, spi, xfer))
rs->use_dma = 1;
else
rs->use_dma = 0;
rockchip_spi_config(rs);
if (rs->use_dma) {
if (rs->tmode == CR0_XFM_RO) {
rockchip_spi_prepare_dma(rs);
spi_enable_chip(rs, 1);
} else {
spi_enable_chip(rs, 1);
rockchip_spi_prepare_dma(rs);
}
} else {
spi_enable_chip(rs, 1);
ret = rockchip_spi_pio_transfer(rs);
}
return ret;
}
static bool rockchip_spi_can_dma(struct spi_master *master,
struct spi_device *spi,
struct spi_transfer *xfer)
{
struct rockchip_spi *rs = spi_master_get_devdata(master);
return (xfer->len > rs->fifo_len);
}
static int rockchip_spi_probe(struct platform_device *pdev)
{
int ret = 0;
struct rockchip_spi *rs;
struct spi_master *master;
struct resource *mem;
u32 rsd_nsecs;
master = spi_alloc_master(&pdev->dev, sizeof(struct rockchip_spi));
if (!master)
return -ENOMEM;
platform_set_drvdata(pdev, master);
rs = spi_master_get_devdata(master);
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
rs->regs = devm_ioremap_resource(&pdev->dev, mem);
if (IS_ERR(rs->regs)) {
ret = PTR_ERR(rs->regs);
goto err_ioremap_resource;
}
rs->apb_pclk = devm_clk_get(&pdev->dev, "apb_pclk");
if (IS_ERR(rs->apb_pclk)) {
dev_err(&pdev->dev, "Failed to get apb_pclk\n");
ret = PTR_ERR(rs->apb_pclk);
goto err_ioremap_resource;
}
rs->spiclk = devm_clk_get(&pdev->dev, "spiclk");
if (IS_ERR(rs->spiclk)) {
dev_err(&pdev->dev, "Failed to get spi_pclk\n");
ret = PTR_ERR(rs->spiclk);
goto err_ioremap_resource;
}
ret = clk_prepare_enable(rs->apb_pclk);
if (ret) {
dev_err(&pdev->dev, "Failed to enable apb_pclk\n");
goto err_ioremap_resource;
}
ret = clk_prepare_enable(rs->spiclk);
if (ret) {
dev_err(&pdev->dev, "Failed to enable spi_clk\n");
goto err_spiclk_enable;
}
spi_enable_chip(rs, 0);
rs->type = SSI_MOTO_SPI;
rs->master = master;
rs->dev = &pdev->dev;
rs->max_freq = clk_get_rate(rs->spiclk);
if (!of_property_read_u32(pdev->dev.of_node, "rx-sample-delay-ns",
&rsd_nsecs))
rs->rsd_nsecs = rsd_nsecs;
rs->fifo_len = get_fifo_len(rs);
if (!rs->fifo_len) {
dev_err(&pdev->dev, "Failed to get fifo length\n");
ret = -EINVAL;
goto err_get_fifo_len;
}
spin_lock_init(&rs->lock);
pm_runtime_set_active(&pdev->dev);
pm_runtime_enable(&pdev->dev);
master->auto_runtime_pm = true;
master->bus_num = pdev->id;
master->mode_bits = SPI_CPOL | SPI_CPHA | SPI_LOOP;
master->num_chipselect = 2;
master->dev.of_node = pdev->dev.of_node;
master->bits_per_word_mask = SPI_BPW_MASK(16) | SPI_BPW_MASK(8);
master->set_cs = rockchip_spi_set_cs;
master->prepare_message = rockchip_spi_prepare_message;
master->unprepare_message = rockchip_spi_unprepare_message;
master->transfer_one = rockchip_spi_transfer_one;
master->handle_err = rockchip_spi_handle_err;
rs->dma_tx.ch = dma_request_slave_channel(rs->dev, "tx");
if (!rs->dma_tx.ch)
dev_warn(rs->dev, "Failed to request TX DMA channel\n");
rs->dma_rx.ch = dma_request_slave_channel(rs->dev, "rx");
if (!rs->dma_rx.ch) {
if (rs->dma_tx.ch) {
dma_release_channel(rs->dma_tx.ch);
rs->dma_tx.ch = NULL;
}
dev_warn(rs->dev, "Failed to request RX DMA channel\n");
}
if (rs->dma_tx.ch && rs->dma_rx.ch) {
rs->dma_tx.addr = (dma_addr_t)(mem->start + ROCKCHIP_SPI_TXDR);
rs->dma_rx.addr = (dma_addr_t)(mem->start + ROCKCHIP_SPI_RXDR);
rs->dma_tx.direction = DMA_MEM_TO_DEV;
rs->dma_rx.direction = DMA_DEV_TO_MEM;
master->can_dma = rockchip_spi_can_dma;
master->dma_tx = rs->dma_tx.ch;
master->dma_rx = rs->dma_rx.ch;
}
ret = devm_spi_register_master(&pdev->dev, master);
if (ret) {
dev_err(&pdev->dev, "Failed to register master\n");
goto err_register_master;
}
return 0;
err_register_master:
if (rs->dma_tx.ch)
dma_release_channel(rs->dma_tx.ch);
if (rs->dma_rx.ch)
dma_release_channel(rs->dma_rx.ch);
err_get_fifo_len:
clk_disable_unprepare(rs->spiclk);
err_spiclk_enable:
clk_disable_unprepare(rs->apb_pclk);
err_ioremap_resource:
spi_master_put(master);
return ret;
}
static int rockchip_spi_remove(struct platform_device *pdev)
{
struct spi_master *master = spi_master_get(platform_get_drvdata(pdev));
struct rockchip_spi *rs = spi_master_get_devdata(master);
pm_runtime_disable(&pdev->dev);
clk_disable_unprepare(rs->spiclk);
clk_disable_unprepare(rs->apb_pclk);
if (rs->dma_tx.ch)
dma_release_channel(rs->dma_tx.ch);
if (rs->dma_rx.ch)
dma_release_channel(rs->dma_rx.ch);
return 0;
}
static int rockchip_spi_suspend(struct device *dev)
{
int ret = 0;
struct spi_master *master = dev_get_drvdata(dev);
struct rockchip_spi *rs = spi_master_get_devdata(master);
ret = spi_master_suspend(rs->master);
if (ret)
return ret;
if (!pm_runtime_suspended(dev)) {
clk_disable_unprepare(rs->spiclk);
clk_disable_unprepare(rs->apb_pclk);
}
return ret;
}
static int rockchip_spi_resume(struct device *dev)
{
int ret = 0;
struct spi_master *master = dev_get_drvdata(dev);
struct rockchip_spi *rs = spi_master_get_devdata(master);
if (!pm_runtime_suspended(dev)) {
ret = clk_prepare_enable(rs->apb_pclk);
if (ret < 0)
return ret;
ret = clk_prepare_enable(rs->spiclk);
if (ret < 0) {
clk_disable_unprepare(rs->apb_pclk);
return ret;
}
}
ret = spi_master_resume(rs->master);
if (ret < 0) {
clk_disable_unprepare(rs->spiclk);
clk_disable_unprepare(rs->apb_pclk);
}
return ret;
}
static int rockchip_spi_runtime_suspend(struct device *dev)
{
struct spi_master *master = dev_get_drvdata(dev);
struct rockchip_spi *rs = spi_master_get_devdata(master);
clk_disable_unprepare(rs->spiclk);
clk_disable_unprepare(rs->apb_pclk);
return 0;
}
static int rockchip_spi_runtime_resume(struct device *dev)
{
int ret;
struct spi_master *master = dev_get_drvdata(dev);
struct rockchip_spi *rs = spi_master_get_devdata(master);
ret = clk_prepare_enable(rs->apb_pclk);
if (ret)
return ret;
ret = clk_prepare_enable(rs->spiclk);
if (ret)
clk_disable_unprepare(rs->apb_pclk);
return ret;
}
