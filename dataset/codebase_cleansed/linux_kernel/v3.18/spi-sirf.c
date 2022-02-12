static void spi_sirfsoc_rx_word_u8(struct sirfsoc_spi *sspi)
{
u32 data;
u8 *rx = sspi->rx;
data = readl(sspi->base + SIRFSOC_SPI_RXFIFO_DATA);
if (rx) {
*rx++ = (u8) data;
sspi->rx = rx;
}
sspi->left_rx_word--;
}
static void spi_sirfsoc_tx_word_u8(struct sirfsoc_spi *sspi)
{
u32 data = 0;
const u8 *tx = sspi->tx;
if (tx) {
data = *tx++;
sspi->tx = tx;
}
writel(data, sspi->base + SIRFSOC_SPI_TXFIFO_DATA);
sspi->left_tx_word--;
}
static void spi_sirfsoc_rx_word_u16(struct sirfsoc_spi *sspi)
{
u32 data;
u16 *rx = sspi->rx;
data = readl(sspi->base + SIRFSOC_SPI_RXFIFO_DATA);
if (rx) {
*rx++ = (u16) data;
sspi->rx = rx;
}
sspi->left_rx_word--;
}
static void spi_sirfsoc_tx_word_u16(struct sirfsoc_spi *sspi)
{
u32 data = 0;
const u16 *tx = sspi->tx;
if (tx) {
data = *tx++;
sspi->tx = tx;
}
writel(data, sspi->base + SIRFSOC_SPI_TXFIFO_DATA);
sspi->left_tx_word--;
}
static void spi_sirfsoc_rx_word_u32(struct sirfsoc_spi *sspi)
{
u32 data;
u32 *rx = sspi->rx;
data = readl(sspi->base + SIRFSOC_SPI_RXFIFO_DATA);
if (rx) {
*rx++ = (u32) data;
sspi->rx = rx;
}
sspi->left_rx_word--;
}
static void spi_sirfsoc_tx_word_u32(struct sirfsoc_spi *sspi)
{
u32 data = 0;
const u32 *tx = sspi->tx;
if (tx) {
data = *tx++;
sspi->tx = tx;
}
writel(data, sspi->base + SIRFSOC_SPI_TXFIFO_DATA);
sspi->left_tx_word--;
}
static irqreturn_t spi_sirfsoc_irq(int irq, void *dev_id)
{
struct sirfsoc_spi *sspi = dev_id;
u32 spi_stat = readl(sspi->base + SIRFSOC_SPI_INT_STATUS);
if (sspi->tx_by_cmd && (spi_stat & SIRFSOC_SPI_FRM_END)) {
complete(&sspi->tx_done);
writel(0x0, sspi->base + SIRFSOC_SPI_INT_EN);
writel(SIRFSOC_SPI_INT_MASK_ALL,
sspi->base + SIRFSOC_SPI_INT_STATUS);
return IRQ_HANDLED;
}
if (spi_stat & SIRFSOC_SPI_RX_OFLOW ||
spi_stat & SIRFSOC_SPI_TX_UFLOW) {
complete(&sspi->tx_done);
complete(&sspi->rx_done);
writel(0x0, sspi->base + SIRFSOC_SPI_INT_EN);
writel(SIRFSOC_SPI_INT_MASK_ALL,
sspi->base + SIRFSOC_SPI_INT_STATUS);
return IRQ_HANDLED;
}
if (spi_stat & SIRFSOC_SPI_TXFIFO_EMPTY)
complete(&sspi->tx_done);
while (!(readl(sspi->base + SIRFSOC_SPI_INT_STATUS) &
SIRFSOC_SPI_RX_IO_DMA))
cpu_relax();
complete(&sspi->rx_done);
writel(0x0, sspi->base + SIRFSOC_SPI_INT_EN);
writel(SIRFSOC_SPI_INT_MASK_ALL,
sspi->base + SIRFSOC_SPI_INT_STATUS);
return IRQ_HANDLED;
}
static void spi_sirfsoc_dma_fini_callback(void *data)
{
struct completion *dma_complete = data;
complete(dma_complete);
}
static void spi_sirfsoc_cmd_transfer(struct spi_device *spi,
struct spi_transfer *t)
{
struct sirfsoc_spi *sspi;
int timeout = t->len * 10;
u32 cmd;
sspi = spi_master_get_devdata(spi->master);
writel(SIRFSOC_SPI_FIFO_RESET, sspi->base + SIRFSOC_SPI_TXFIFO_OP);
writel(SIRFSOC_SPI_FIFO_START, sspi->base + SIRFSOC_SPI_TXFIFO_OP);
memcpy(&cmd, sspi->tx, t->len);
if (sspi->word_width == 1 && !(spi->mode & SPI_LSB_FIRST))
cmd = cpu_to_be32(cmd) >>
((SIRFSOC_MAX_CMD_BYTES - t->len) * 8);
if (sspi->word_width == 2 && t->len == 4 &&
(!(spi->mode & SPI_LSB_FIRST)))
cmd = ((cmd & 0xffff) << 16) | (cmd >> 16);
writel(cmd, sspi->base + SIRFSOC_SPI_CMD);
writel(SIRFSOC_SPI_FRM_END_INT_EN,
sspi->base + SIRFSOC_SPI_INT_EN);
writel(SIRFSOC_SPI_CMD_TX_EN,
sspi->base + SIRFSOC_SPI_TX_RX_EN);
if (wait_for_completion_timeout(&sspi->tx_done, timeout) == 0) {
dev_err(&spi->dev, "cmd transfer timeout\n");
return;
}
sspi->left_rx_word -= t->len;
}
static void spi_sirfsoc_dma_transfer(struct spi_device *spi,
struct spi_transfer *t)
{
struct sirfsoc_spi *sspi;
struct dma_async_tx_descriptor *rx_desc, *tx_desc;
int timeout = t->len * 10;
sspi = spi_master_get_devdata(spi->master);
writel(SIRFSOC_SPI_FIFO_RESET, sspi->base + SIRFSOC_SPI_RXFIFO_OP);
writel(SIRFSOC_SPI_FIFO_RESET, sspi->base + SIRFSOC_SPI_TXFIFO_OP);
writel(SIRFSOC_SPI_FIFO_START, sspi->base + SIRFSOC_SPI_RXFIFO_OP);
writel(SIRFSOC_SPI_FIFO_START, sspi->base + SIRFSOC_SPI_TXFIFO_OP);
writel(0, sspi->base + SIRFSOC_SPI_INT_EN);
writel(SIRFSOC_SPI_INT_MASK_ALL, sspi->base + SIRFSOC_SPI_INT_STATUS);
if (sspi->left_tx_word < SIRFSOC_SPI_DAT_FRM_LEN_MAX) {
writel(readl(sspi->base + SIRFSOC_SPI_CTRL) |
SIRFSOC_SPI_ENA_AUTO_CLR | SIRFSOC_SPI_MUL_DAT_MODE,
sspi->base + SIRFSOC_SPI_CTRL);
writel(sspi->left_tx_word - 1,
sspi->base + SIRFSOC_SPI_TX_DMA_IO_LEN);
writel(sspi->left_tx_word - 1,
sspi->base + SIRFSOC_SPI_RX_DMA_IO_LEN);
} else {
writel(readl(sspi->base + SIRFSOC_SPI_CTRL),
sspi->base + SIRFSOC_SPI_CTRL);
writel(0, sspi->base + SIRFSOC_SPI_TX_DMA_IO_LEN);
writel(0, sspi->base + SIRFSOC_SPI_RX_DMA_IO_LEN);
}
sspi->dst_start = dma_map_single(&spi->dev, sspi->rx, t->len,
(t->tx_buf != t->rx_buf) ?
DMA_FROM_DEVICE : DMA_BIDIRECTIONAL);
rx_desc = dmaengine_prep_slave_single(sspi->rx_chan,
sspi->dst_start, t->len, DMA_DEV_TO_MEM,
DMA_PREP_INTERRUPT | DMA_CTRL_ACK);
rx_desc->callback = spi_sirfsoc_dma_fini_callback;
rx_desc->callback_param = &sspi->rx_done;
sspi->src_start = dma_map_single(&spi->dev, (void *)sspi->tx, t->len,
(t->tx_buf != t->rx_buf) ?
DMA_TO_DEVICE : DMA_BIDIRECTIONAL);
tx_desc = dmaengine_prep_slave_single(sspi->tx_chan,
sspi->src_start, t->len, DMA_MEM_TO_DEV,
DMA_PREP_INTERRUPT | DMA_CTRL_ACK);
tx_desc->callback = spi_sirfsoc_dma_fini_callback;
tx_desc->callback_param = &sspi->tx_done;
dmaengine_submit(tx_desc);
dmaengine_submit(rx_desc);
dma_async_issue_pending(sspi->tx_chan);
dma_async_issue_pending(sspi->rx_chan);
writel(SIRFSOC_SPI_RX_EN | SIRFSOC_SPI_TX_EN,
sspi->base + SIRFSOC_SPI_TX_RX_EN);
if (wait_for_completion_timeout(&sspi->rx_done, timeout) == 0) {
dev_err(&spi->dev, "transfer timeout\n");
dmaengine_terminate_all(sspi->rx_chan);
} else
sspi->left_rx_word = 0;
if (wait_for_completion_timeout(&sspi->tx_done, timeout) == 0) {
dev_err(&spi->dev, "transfer timeout\n");
dmaengine_terminate_all(sspi->tx_chan);
}
dma_unmap_single(&spi->dev, sspi->src_start, t->len, DMA_TO_DEVICE);
dma_unmap_single(&spi->dev, sspi->dst_start, t->len, DMA_FROM_DEVICE);
writel(0, sspi->base + SIRFSOC_SPI_RXFIFO_OP);
writel(0, sspi->base + SIRFSOC_SPI_TXFIFO_OP);
if (sspi->left_tx_word >= SIRFSOC_SPI_DAT_FRM_LEN_MAX)
writel(0, sspi->base + SIRFSOC_SPI_TX_RX_EN);
}
static void spi_sirfsoc_pio_transfer(struct spi_device *spi,
struct spi_transfer *t)
{
struct sirfsoc_spi *sspi;
int timeout = t->len * 10;
sspi = spi_master_get_devdata(spi->master);
do {
writel(SIRFSOC_SPI_FIFO_RESET,
sspi->base + SIRFSOC_SPI_RXFIFO_OP);
writel(SIRFSOC_SPI_FIFO_RESET,
sspi->base + SIRFSOC_SPI_TXFIFO_OP);
writel(SIRFSOC_SPI_FIFO_START,
sspi->base + SIRFSOC_SPI_RXFIFO_OP);
writel(SIRFSOC_SPI_FIFO_START,
sspi->base + SIRFSOC_SPI_TXFIFO_OP);
writel(0, sspi->base + SIRFSOC_SPI_INT_EN);
writel(SIRFSOC_SPI_INT_MASK_ALL,
sspi->base + SIRFSOC_SPI_INT_STATUS);
writel(readl(sspi->base + SIRFSOC_SPI_CTRL) |
SIRFSOC_SPI_MUL_DAT_MODE | SIRFSOC_SPI_ENA_AUTO_CLR,
sspi->base + SIRFSOC_SPI_CTRL);
writel(min(sspi->left_tx_word, (u32)(256 / sspi->word_width))
- 1, sspi->base + SIRFSOC_SPI_TX_DMA_IO_LEN);
writel(min(sspi->left_rx_word, (u32)(256 / sspi->word_width))
- 1, sspi->base + SIRFSOC_SPI_RX_DMA_IO_LEN);
while (!((readl(sspi->base + SIRFSOC_SPI_TXFIFO_STATUS)
& SIRFSOC_SPI_FIFO_FULL)) && sspi->left_tx_word)
sspi->tx_word(sspi);
writel(SIRFSOC_SPI_TXFIFO_EMPTY_INT_EN |
SIRFSOC_SPI_TX_UFLOW_INT_EN |
SIRFSOC_SPI_RX_OFLOW_INT_EN |
SIRFSOC_SPI_RX_IO_DMA_INT_EN,
sspi->base + SIRFSOC_SPI_INT_EN);
writel(SIRFSOC_SPI_RX_EN | SIRFSOC_SPI_TX_EN,
sspi->base + SIRFSOC_SPI_TX_RX_EN);
if (!wait_for_completion_timeout(&sspi->tx_done, timeout) ||
!wait_for_completion_timeout(&sspi->rx_done, timeout)) {
dev_err(&spi->dev, "transfer timeout\n");
break;
}
while (!((readl(sspi->base + SIRFSOC_SPI_RXFIFO_STATUS)
& SIRFSOC_SPI_FIFO_EMPTY)) && sspi->left_rx_word)
sspi->rx_word(sspi);
writel(0, sspi->base + SIRFSOC_SPI_RXFIFO_OP);
writel(0, sspi->base + SIRFSOC_SPI_TXFIFO_OP);
} while (sspi->left_tx_word != 0 || sspi->left_rx_word != 0);
}
static int spi_sirfsoc_transfer(struct spi_device *spi, struct spi_transfer *t)
{
struct sirfsoc_spi *sspi;
sspi = spi_master_get_devdata(spi->master);
sspi->tx = t->tx_buf ? t->tx_buf : sspi->dummypage;
sspi->rx = t->rx_buf ? t->rx_buf : sspi->dummypage;
sspi->left_tx_word = sspi->left_rx_word = t->len / sspi->word_width;
reinit_completion(&sspi->rx_done);
reinit_completion(&sspi->tx_done);
if (sspi->tx_by_cmd)
spi_sirfsoc_cmd_transfer(spi, t);
else if (IS_DMA_VALID(t))
spi_sirfsoc_dma_transfer(spi, t);
else
spi_sirfsoc_pio_transfer(spi, t);
return t->len - sspi->left_rx_word * sspi->word_width;
}
static void spi_sirfsoc_chipselect(struct spi_device *spi, int value)
{
struct sirfsoc_spi *sspi = spi_master_get_devdata(spi->master);
if (sspi->hw_cs) {
u32 regval = readl(sspi->base + SIRFSOC_SPI_CTRL);
switch (value) {
case BITBANG_CS_ACTIVE:
if (spi->mode & SPI_CS_HIGH)
regval |= SIRFSOC_SPI_CS_IO_OUT;
else
regval &= ~SIRFSOC_SPI_CS_IO_OUT;
break;
case BITBANG_CS_INACTIVE:
if (spi->mode & SPI_CS_HIGH)
regval &= ~SIRFSOC_SPI_CS_IO_OUT;
else
regval |= SIRFSOC_SPI_CS_IO_OUT;
break;
}
writel(regval, sspi->base + SIRFSOC_SPI_CTRL);
} else {
switch (value) {
case BITBANG_CS_ACTIVE:
gpio_direction_output(spi->cs_gpio,
spi->mode & SPI_CS_HIGH ? 1 : 0);
break;
case BITBANG_CS_INACTIVE:
gpio_direction_output(spi->cs_gpio,
spi->mode & SPI_CS_HIGH ? 0 : 1);
break;
}
}
}
static int
spi_sirfsoc_setup_transfer(struct spi_device *spi, struct spi_transfer *t)
{
struct sirfsoc_spi *sspi;
u8 bits_per_word = 0;
int hz = 0;
u32 regval;
u32 txfifo_ctrl, rxfifo_ctrl;
u32 fifo_size = SIRFSOC_SPI_FIFO_SIZE / 4;
sspi = spi_master_get_devdata(spi->master);
bits_per_word = (t) ? t->bits_per_word : spi->bits_per_word;
hz = t && t->speed_hz ? t->speed_hz : spi->max_speed_hz;
regval = (sspi->ctrl_freq / (2 * hz)) - 1;
if (regval > 0xFFFF || regval < 0) {
dev_err(&spi->dev, "Speed %d not supported\n", hz);
return -EINVAL;
}
switch (bits_per_word) {
case 8:
regval |= SIRFSOC_SPI_TRAN_DAT_FORMAT_8;
sspi->rx_word = spi_sirfsoc_rx_word_u8;
sspi->tx_word = spi_sirfsoc_tx_word_u8;
break;
case 12:
case 16:
regval |= (bits_per_word == 12) ?
SIRFSOC_SPI_TRAN_DAT_FORMAT_12 :
SIRFSOC_SPI_TRAN_DAT_FORMAT_16;
sspi->rx_word = spi_sirfsoc_rx_word_u16;
sspi->tx_word = spi_sirfsoc_tx_word_u16;
break;
case 32:
regval |= SIRFSOC_SPI_TRAN_DAT_FORMAT_32;
sspi->rx_word = spi_sirfsoc_rx_word_u32;
sspi->tx_word = spi_sirfsoc_tx_word_u32;
break;
default:
BUG();
}
sspi->word_width = DIV_ROUND_UP(bits_per_word, 8);
txfifo_ctrl = SIRFSOC_SPI_FIFO_THD(SIRFSOC_SPI_FIFO_SIZE / 2) |
(sspi->word_width >> 1);
rxfifo_ctrl = SIRFSOC_SPI_FIFO_THD(SIRFSOC_SPI_FIFO_SIZE / 2) |
(sspi->word_width >> 1);
if (!(spi->mode & SPI_CS_HIGH))
regval |= SIRFSOC_SPI_CS_IDLE_STAT;
if (!(spi->mode & SPI_LSB_FIRST))
regval |= SIRFSOC_SPI_TRAN_MSB;
if (spi->mode & SPI_CPOL)
regval |= SIRFSOC_SPI_CLK_IDLE_STAT;
if (((spi->mode & SPI_CPOL) && (spi->mode & SPI_CPHA)) ||
(!(spi->mode & SPI_CPOL) && !(spi->mode & SPI_CPHA)))
regval &= ~SIRFSOC_SPI_DRV_POS_EDGE;
else
regval |= SIRFSOC_SPI_DRV_POS_EDGE;
writel(SIRFSOC_SPI_FIFO_SC(fifo_size - 2) |
SIRFSOC_SPI_FIFO_LC(fifo_size / 2) |
SIRFSOC_SPI_FIFO_HC(2),
sspi->base + SIRFSOC_SPI_TXFIFO_LEVEL_CHK);
writel(SIRFSOC_SPI_FIFO_SC(2) |
SIRFSOC_SPI_FIFO_LC(fifo_size / 2) |
SIRFSOC_SPI_FIFO_HC(fifo_size - 2),
sspi->base + SIRFSOC_SPI_RXFIFO_LEVEL_CHK);
writel(txfifo_ctrl, sspi->base + SIRFSOC_SPI_TXFIFO_CTRL);
writel(rxfifo_ctrl, sspi->base + SIRFSOC_SPI_RXFIFO_CTRL);
if (t && t->tx_buf && !t->rx_buf && (t->len <= SIRFSOC_MAX_CMD_BYTES)) {
regval |= (SIRFSOC_SPI_CMD_BYTE_NUM((t->len - 1)) |
SIRFSOC_SPI_CMD_MODE);
sspi->tx_by_cmd = true;
} else {
regval &= ~SIRFSOC_SPI_CMD_MODE;
sspi->tx_by_cmd = false;
}
regval |= SIRFSOC_SPI_CS_IO_MODE;
writel(regval, sspi->base + SIRFSOC_SPI_CTRL);
if (IS_DMA_VALID(t)) {
writel(0, sspi->base + SIRFSOC_SPI_TX_DMA_IO_CTRL);
writel(SIRFSOC_SPI_RX_DMA_FLUSH,
sspi->base + SIRFSOC_SPI_RX_DMA_IO_CTRL);
} else {
writel(SIRFSOC_SPI_IO_MODE_SEL,
sspi->base + SIRFSOC_SPI_TX_DMA_IO_CTRL);
writel(SIRFSOC_SPI_IO_MODE_SEL,
sspi->base + SIRFSOC_SPI_RX_DMA_IO_CTRL);
}
return 0;
}
static int spi_sirfsoc_setup(struct spi_device *spi)
{
struct sirfsoc_spi *sspi;
if (!spi->max_speed_hz)
return -EINVAL;
sspi = spi_master_get_devdata(spi->master);
if (spi->cs_gpio == -ENOENT)
sspi->hw_cs = true;
else
sspi->hw_cs = false;
return spi_sirfsoc_setup_transfer(spi, NULL);
}
static int spi_sirfsoc_probe(struct platform_device *pdev)
{
struct sirfsoc_spi *sspi;
struct spi_master *master;
struct resource *mem_res;
int irq;
int i, ret;
master = spi_alloc_master(&pdev->dev, sizeof(*sspi));
if (!master) {
dev_err(&pdev->dev, "Unable to allocate SPI master\n");
return -ENOMEM;
}
platform_set_drvdata(pdev, master);
sspi = spi_master_get_devdata(master);
mem_res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
sspi->base = devm_ioremap_resource(&pdev->dev, mem_res);
if (IS_ERR(sspi->base)) {
ret = PTR_ERR(sspi->base);
goto free_master;
}
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
ret = -ENXIO;
goto free_master;
}
ret = devm_request_irq(&pdev->dev, irq, spi_sirfsoc_irq, 0,
DRIVER_NAME, sspi);
if (ret)
goto free_master;
sspi->bitbang.master = master;
sspi->bitbang.chipselect = spi_sirfsoc_chipselect;
sspi->bitbang.setup_transfer = spi_sirfsoc_setup_transfer;
sspi->bitbang.txrx_bufs = spi_sirfsoc_transfer;
sspi->bitbang.master->setup = spi_sirfsoc_setup;
master->bus_num = pdev->id;
master->mode_bits = SPI_CPOL | SPI_CPHA | SPI_LSB_FIRST | SPI_CS_HIGH;
master->bits_per_word_mask = SPI_BPW_MASK(8) | SPI_BPW_MASK(12) |
SPI_BPW_MASK(16) | SPI_BPW_MASK(32);
sspi->bitbang.master->dev.of_node = pdev->dev.of_node;
sspi->rx_chan = dma_request_slave_channel(&pdev->dev, "rx");
if (!sspi->rx_chan) {
dev_err(&pdev->dev, "can not allocate rx dma channel\n");
ret = -ENODEV;
goto free_master;
}
sspi->tx_chan = dma_request_slave_channel(&pdev->dev, "tx");
if (!sspi->tx_chan) {
dev_err(&pdev->dev, "can not allocate tx dma channel\n");
ret = -ENODEV;
goto free_rx_dma;
}
sspi->clk = clk_get(&pdev->dev, NULL);
if (IS_ERR(sspi->clk)) {
ret = PTR_ERR(sspi->clk);
goto free_tx_dma;
}
clk_prepare_enable(sspi->clk);
sspi->ctrl_freq = clk_get_rate(sspi->clk);
init_completion(&sspi->rx_done);
init_completion(&sspi->tx_done);
writel(SIRFSOC_SPI_FIFO_RESET, sspi->base + SIRFSOC_SPI_RXFIFO_OP);
writel(SIRFSOC_SPI_FIFO_RESET, sspi->base + SIRFSOC_SPI_TXFIFO_OP);
writel(SIRFSOC_SPI_FIFO_START, sspi->base + SIRFSOC_SPI_RXFIFO_OP);
writel(SIRFSOC_SPI_FIFO_START, sspi->base + SIRFSOC_SPI_TXFIFO_OP);
writel(0, sspi->base + SIRFSOC_SPI_DUMMY_DELAY_CTL);
sspi->dummypage = kmalloc(2 * PAGE_SIZE, GFP_KERNEL);
if (!sspi->dummypage) {
ret = -ENOMEM;
goto free_clk;
}
ret = spi_bitbang_start(&sspi->bitbang);
if (ret)
goto free_dummypage;
for (i = 0; master->cs_gpios && i < master->num_chipselect; i++) {
if (master->cs_gpios[i] == -ENOENT)
continue;
if (!gpio_is_valid(master->cs_gpios[i])) {
dev_err(&pdev->dev, "no valid gpio\n");
ret = -EINVAL;
goto free_dummypage;
}
ret = devm_gpio_request(&pdev->dev,
master->cs_gpios[i], DRIVER_NAME);
if (ret) {
dev_err(&pdev->dev, "failed to request gpio\n");
goto free_dummypage;
}
}
dev_info(&pdev->dev, "registerred, bus number = %d\n", master->bus_num);
return 0;
free_dummypage:
kfree(sspi->dummypage);
free_clk:
clk_disable_unprepare(sspi->clk);
clk_put(sspi->clk);
free_tx_dma:
dma_release_channel(sspi->tx_chan);
free_rx_dma:
dma_release_channel(sspi->rx_chan);
free_master:
spi_master_put(master);
return ret;
}
static int spi_sirfsoc_remove(struct platform_device *pdev)
{
struct spi_master *master;
struct sirfsoc_spi *sspi;
master = platform_get_drvdata(pdev);
sspi = spi_master_get_devdata(master);
spi_bitbang_stop(&sspi->bitbang);
kfree(sspi->dummypage);
clk_disable_unprepare(sspi->clk);
clk_put(sspi->clk);
dma_release_channel(sspi->rx_chan);
dma_release_channel(sspi->tx_chan);
spi_master_put(master);
return 0;
}
static int spi_sirfsoc_suspend(struct device *dev)
{
struct spi_master *master = dev_get_drvdata(dev);
struct sirfsoc_spi *sspi = spi_master_get_devdata(master);
int ret;
ret = spi_master_suspend(master);
if (ret)
return ret;
clk_disable(sspi->clk);
return 0;
}
static int spi_sirfsoc_resume(struct device *dev)
{
struct spi_master *master = dev_get_drvdata(dev);
struct sirfsoc_spi *sspi = spi_master_get_devdata(master);
clk_enable(sspi->clk);
writel(SIRFSOC_SPI_FIFO_RESET, sspi->base + SIRFSOC_SPI_RXFIFO_OP);
writel(SIRFSOC_SPI_FIFO_RESET, sspi->base + SIRFSOC_SPI_TXFIFO_OP);
writel(SIRFSOC_SPI_FIFO_START, sspi->base + SIRFSOC_SPI_RXFIFO_OP);
writel(SIRFSOC_SPI_FIFO_START, sspi->base + SIRFSOC_SPI_TXFIFO_OP);
return spi_master_resume(master);
}
