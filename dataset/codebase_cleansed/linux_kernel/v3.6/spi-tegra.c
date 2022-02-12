static inline unsigned long spi_tegra_readl(struct spi_tegra_data *tspi,
unsigned long reg)
{
return readl(tspi->base + reg);
}
static inline void spi_tegra_writel(struct spi_tegra_data *tspi,
unsigned long val,
unsigned long reg)
{
writel(val, tspi->base + reg);
}
static void spi_tegra_go(struct spi_tegra_data *tspi)
{
unsigned long val;
wmb();
val = spi_tegra_readl(tspi, SLINK_DMA_CTL);
val &= ~SLINK_DMA_BLOCK_SIZE(~0) & ~SLINK_DMA_EN;
val |= SLINK_DMA_BLOCK_SIZE(tspi->dma_req_len / 4 - 1);
spi_tegra_writel(tspi, val, SLINK_DMA_CTL);
#if defined(CONFIG_TEGRA_SYSTEM_DMA)
tspi->rx_dma_req.size = tspi->dma_req_len;
tegra_dma_enqueue_req(tspi->rx_dma, &tspi->rx_dma_req);
#else
tspi->rx_dma_desc = dmaengine_prep_slave_single(tspi->rx_dma,
tspi->rx_bb_phys, tspi->dma_req_len,
DMA_DEV_TO_MEM, DMA_PREP_INTERRUPT);
if (!tspi->rx_dma_desc) {
dev_err(&tspi->pdev->dev, "dmaengine slave prep failed\n");
return;
}
tspi->rx_dma_desc->callback = tegra_spi_rx_dma_complete;
tspi->rx_dma_desc->callback_param = tspi;
tspi->rx_cookie = dmaengine_submit(tspi->rx_dma_desc);
dma_async_issue_pending(tspi->rx_dma);
#endif
val |= SLINK_DMA_EN;
spi_tegra_writel(tspi, val, SLINK_DMA_CTL);
}
static unsigned spi_tegra_fill_tx_fifo(struct spi_tegra_data *tspi,
struct spi_transfer *t)
{
unsigned len = min(t->len - tspi->cur_pos, BB_LEN *
tspi->cur_bytes_per_word);
u8 *tx_buf = (u8 *)t->tx_buf + tspi->cur_pos;
int i, j;
unsigned long val;
val = spi_tegra_readl(tspi, SLINK_COMMAND);
val &= ~SLINK_WORD_SIZE(~0);
val |= SLINK_WORD_SIZE(len / tspi->cur_bytes_per_word - 1);
spi_tegra_writel(tspi, val, SLINK_COMMAND);
for (i = 0; i < len; i += tspi->cur_bytes_per_word) {
val = 0;
for (j = 0; j < tspi->cur_bytes_per_word; j++)
val |= tx_buf[i + j] << j * 8;
spi_tegra_writel(tspi, val, SLINK_TX_FIFO);
}
tspi->dma_req_len = len / tspi->cur_bytes_per_word * 4;
return len;
}
static unsigned spi_tegra_drain_rx_fifo(struct spi_tegra_data *tspi,
struct spi_transfer *t)
{
unsigned len = tspi->cur_len;
u8 *rx_buf = (u8 *)t->rx_buf + tspi->cur_pos;
int i, j;
unsigned long val;
for (i = 0; i < len; i += tspi->cur_bytes_per_word) {
val = tspi->rx_bb[i / tspi->cur_bytes_per_word];
for (j = 0; j < tspi->cur_bytes_per_word; j++)
rx_buf[i + j] = (val >> (j * 8)) & 0xff;
}
return len;
}
static void spi_tegra_start_transfer(struct spi_device *spi,
struct spi_transfer *t)
{
struct spi_tegra_data *tspi = spi_master_get_devdata(spi->master);
u32 speed;
u8 bits_per_word;
unsigned long val;
speed = t->speed_hz ? t->speed_hz : spi->max_speed_hz;
bits_per_word = t->bits_per_word ? t->bits_per_word :
spi->bits_per_word;
tspi->cur_bytes_per_word = (bits_per_word - 1) / 8 + 1;
if (speed != tspi->cur_speed)
clk_set_rate(tspi->clk, speed);
if (tspi->cur_speed == 0)
clk_prepare_enable(tspi->clk);
tspi->cur_speed = speed;
val = spi_tegra_readl(tspi, SLINK_COMMAND2);
val &= ~SLINK_SS_EN_CS(~0) | SLINK_RXEN | SLINK_TXEN;
if (t->rx_buf)
val |= SLINK_RXEN;
if (t->tx_buf)
val |= SLINK_TXEN;
val |= SLINK_SS_EN_CS(spi->chip_select);
val |= SLINK_SPIE;
spi_tegra_writel(tspi, val, SLINK_COMMAND2);
val = spi_tegra_readl(tspi, SLINK_COMMAND);
val &= ~SLINK_BIT_LENGTH(~0);
val |= SLINK_BIT_LENGTH(bits_per_word - 1);
val &= ~SLINK_IDLE_SCLK_MASK & ~SLINK_CK_SDA & ~SLINK_CS_SW;
if (spi->mode & SPI_CPHA)
val |= SLINK_CK_SDA;
if (spi->mode & SPI_CPOL)
val |= SLINK_IDLE_SCLK_DRIVE_HIGH;
else
val |= SLINK_IDLE_SCLK_DRIVE_LOW;
val |= SLINK_M_S;
spi_tegra_writel(tspi, val, SLINK_COMMAND);
spi_tegra_writel(tspi, SLINK_RX_FLUSH | SLINK_TX_FLUSH, SLINK_STATUS);
tspi->cur = t;
tspi->cur_pos = 0;
tspi->cur_len = spi_tegra_fill_tx_fifo(tspi, t);
spi_tegra_go(tspi);
}
static void spi_tegra_start_message(struct spi_device *spi,
struct spi_message *m)
{
struct spi_transfer *t;
m->actual_length = 0;
m->status = 0;
t = list_first_entry(&m->transfers, struct spi_transfer, transfer_list);
spi_tegra_start_transfer(spi, t);
}
static void handle_spi_rx_dma_complete(struct spi_tegra_data *tspi)
{
unsigned long flags;
struct spi_message *m;
struct spi_device *spi;
int timeout = 0;
unsigned long val;
while (timeout++ < 1000) {
if (!(spi_tegra_readl(tspi, SLINK_STATUS) & SLINK_BSY))
break;
}
spin_lock_irqsave(&tspi->lock, flags);
val = spi_tegra_readl(tspi, SLINK_STATUS);
val |= SLINK_RDY;
spi_tegra_writel(tspi, val, SLINK_STATUS);
m = list_first_entry(&tspi->queue, struct spi_message, queue);
if (timeout >= 1000)
m->status = -EIO;
spi = m->state;
tspi->cur_pos += spi_tegra_drain_rx_fifo(tspi, tspi->cur);
m->actual_length += tspi->cur_pos;
if (tspi->cur_pos < tspi->cur->len) {
tspi->cur_len = spi_tegra_fill_tx_fifo(tspi, tspi->cur);
spi_tegra_go(tspi);
} else if (!list_is_last(&tspi->cur->transfer_list,
&m->transfers)) {
tspi->cur = list_first_entry(&tspi->cur->transfer_list,
struct spi_transfer,
transfer_list);
spi_tegra_start_transfer(spi, tspi->cur);
} else {
list_del(&m->queue);
m->complete(m->context);
if (!list_empty(&tspi->queue)) {
m = list_first_entry(&tspi->queue, struct spi_message,
queue);
spi = m->state;
spi_tegra_start_message(spi, m);
} else {
clk_disable_unprepare(tspi->clk);
tspi->cur_speed = 0;
}
}
spin_unlock_irqrestore(&tspi->lock, flags);
}
static void tegra_spi_rx_dma_complete(struct tegra_dma_req *req)
{
struct spi_tegra_data *tspi = req->dev;
handle_spi_rx_dma_complete(tspi);
}
static void tegra_spi_rx_dma_complete(void *args)
{
struct spi_tegra_data *tspi = args;
handle_spi_rx_dma_complete(tspi);
}
static int spi_tegra_setup(struct spi_device *spi)
{
struct spi_tegra_data *tspi = spi_master_get_devdata(spi->master);
unsigned long cs_bit;
unsigned long val;
unsigned long flags;
dev_dbg(&spi->dev, "setup %d bpw, %scpol, %scpha, %dHz\n",
spi->bits_per_word,
spi->mode & SPI_CPOL ? "" : "~",
spi->mode & SPI_CPHA ? "" : "~",
spi->max_speed_hz);
switch (spi->chip_select) {
case 0:
cs_bit = SLINK_CS_POLARITY;
break;
case 1:
cs_bit = SLINK_CS_POLARITY1;
break;
case 2:
cs_bit = SLINK_CS_POLARITY2;
break;
case 4:
cs_bit = SLINK_CS_POLARITY3;
break;
default:
return -EINVAL;
}
spin_lock_irqsave(&tspi->lock, flags);
val = spi_tegra_readl(tspi, SLINK_COMMAND);
if (spi->mode & SPI_CS_HIGH)
val |= cs_bit;
else
val &= ~cs_bit;
spi_tegra_writel(tspi, val, SLINK_COMMAND);
spin_unlock_irqrestore(&tspi->lock, flags);
return 0;
}
static int spi_tegra_transfer(struct spi_device *spi, struct spi_message *m)
{
struct spi_tegra_data *tspi = spi_master_get_devdata(spi->master);
struct spi_transfer *t;
unsigned long flags;
int was_empty;
if (list_empty(&m->transfers) || !m->complete)
return -EINVAL;
list_for_each_entry(t, &m->transfers, transfer_list) {
if (t->bits_per_word < 0 || t->bits_per_word > 32)
return -EINVAL;
if (t->len == 0)
return -EINVAL;
if (!t->rx_buf && !t->tx_buf)
return -EINVAL;
}
m->state = spi;
spin_lock_irqsave(&tspi->lock, flags);
was_empty = list_empty(&tspi->queue);
list_add_tail(&m->queue, &tspi->queue);
if (was_empty)
spi_tegra_start_message(spi, m);
spin_unlock_irqrestore(&tspi->lock, flags);
return 0;
}
static int __devinit spi_tegra_probe(struct platform_device *pdev)
{
struct spi_master *master;
struct spi_tegra_data *tspi;
struct resource *r;
int ret;
#if !defined(CONFIG_TEGRA_SYSTEM_DMA)
dma_cap_mask_t mask;
#endif
master = spi_alloc_master(&pdev->dev, sizeof *tspi);
if (master == NULL) {
dev_err(&pdev->dev, "master allocation failed\n");
return -ENOMEM;
}
master->mode_bits = SPI_CPOL | SPI_CPHA | SPI_CS_HIGH;
master->bus_num = pdev->id;
master->setup = spi_tegra_setup;
master->transfer = spi_tegra_transfer;
master->num_chipselect = 4;
dev_set_drvdata(&pdev->dev, master);
tspi = spi_master_get_devdata(master);
tspi->master = master;
tspi->pdev = pdev;
spin_lock_init(&tspi->lock);
r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (r == NULL) {
ret = -ENODEV;
goto err0;
}
if (!request_mem_region(r->start, resource_size(r),
dev_name(&pdev->dev))) {
ret = -EBUSY;
goto err0;
}
tspi->phys = r->start;
tspi->base = ioremap(r->start, resource_size(r));
if (!tspi->base) {
dev_err(&pdev->dev, "can't ioremap iomem\n");
ret = -ENOMEM;
goto err1;
}
tspi->clk = clk_get(&pdev->dev, NULL);
if (IS_ERR(tspi->clk)) {
dev_err(&pdev->dev, "can not get clock\n");
ret = PTR_ERR(tspi->clk);
goto err2;
}
INIT_LIST_HEAD(&tspi->queue);
#if defined(CONFIG_TEGRA_SYSTEM_DMA)
tspi->rx_dma = tegra_dma_allocate_channel(TEGRA_DMA_MODE_ONESHOT);
if (!tspi->rx_dma) {
dev_err(&pdev->dev, "can not allocate rx dma channel\n");
ret = -ENODEV;
goto err3;
}
#else
dma_cap_zero(mask);
dma_cap_set(DMA_SLAVE, mask);
tspi->rx_dma = dma_request_channel(mask, NULL, NULL);
if (!tspi->rx_dma) {
dev_err(&pdev->dev, "can not allocate rx dma channel\n");
ret = -ENODEV;
goto err3;
}
#endif
tspi->rx_bb = dma_alloc_coherent(&pdev->dev, sizeof(u32) * BB_LEN,
&tspi->rx_bb_phys, GFP_KERNEL);
if (!tspi->rx_bb) {
dev_err(&pdev->dev, "can not allocate rx bounce buffer\n");
ret = -ENOMEM;
goto err4;
}
#if defined(CONFIG_TEGRA_SYSTEM_DMA)
tspi->rx_dma_req.complete = tegra_spi_rx_dma_complete;
tspi->rx_dma_req.to_memory = 1;
tspi->rx_dma_req.dest_addr = tspi->rx_bb_phys;
tspi->rx_dma_req.dest_bus_width = 32;
tspi->rx_dma_req.source_addr = tspi->phys + SLINK_RX_FIFO;
tspi->rx_dma_req.source_bus_width = 32;
tspi->rx_dma_req.source_wrap = 4;
tspi->rx_dma_req.req_sel = spi_tegra_req_sels[pdev->id];
tspi->rx_dma_req.dev = tspi;
#else
tspi->sconfig.src_addr = tspi->phys + SLINK_RX_FIFO;
tspi->sconfig.dst_addr = tspi->phys + SLINK_RX_FIFO;
tspi->sconfig.src_addr_width = DMA_SLAVE_BUSWIDTH_4_BYTES;
tspi->sconfig.dst_addr_width = DMA_SLAVE_BUSWIDTH_4_BYTES;
tspi->sconfig.slave_id = spi_tegra_req_sels[pdev->id];
tspi->sconfig.src_maxburst = 1;
tspi->sconfig.dst_maxburst = 1;
ret = dmaengine_device_control(tspi->rx_dma,
DMA_SLAVE_CONFIG, (unsigned long) &tspi->sconfig);
if (ret < 0) {
dev_err(&pdev->dev, "can not do slave configure for dma %d\n",
ret);
goto err4;
}
#endif
master->dev.of_node = pdev->dev.of_node;
ret = spi_register_master(master);
if (ret < 0)
goto err5;
return ret;
err5:
dma_free_coherent(&pdev->dev, sizeof(u32) * BB_LEN,
tspi->rx_bb, tspi->rx_bb_phys);
err4:
#if defined(CONFIG_TEGRA_SYSTEM_DMA)
tegra_dma_free_channel(tspi->rx_dma);
#else
dma_release_channel(tspi->rx_dma);
#endif
err3:
clk_put(tspi->clk);
err2:
iounmap(tspi->base);
err1:
release_mem_region(r->start, resource_size(r));
err0:
spi_master_put(master);
return ret;
}
static int __devexit spi_tegra_remove(struct platform_device *pdev)
{
struct spi_master *master;
struct spi_tegra_data *tspi;
struct resource *r;
master = dev_get_drvdata(&pdev->dev);
tspi = spi_master_get_devdata(master);
spi_unregister_master(master);
#if defined(CONFIG_TEGRA_SYSTEM_DMA)
tegra_dma_free_channel(tspi->rx_dma);
#else
dma_release_channel(tspi->rx_dma);
#endif
dma_free_coherent(&pdev->dev, sizeof(u32) * BB_LEN,
tspi->rx_bb, tspi->rx_bb_phys);
clk_put(tspi->clk);
iounmap(tspi->base);
r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
release_mem_region(r->start, resource_size(r));
return 0;
}
