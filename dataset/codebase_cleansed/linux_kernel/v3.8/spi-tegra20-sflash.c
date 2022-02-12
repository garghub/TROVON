static inline unsigned long tegra_sflash_readl(struct tegra_sflash_data *tsd,
unsigned long reg)
{
return readl(tsd->base + reg);
}
static inline void tegra_sflash_writel(struct tegra_sflash_data *tsd,
unsigned long val, unsigned long reg)
{
writel(val, tsd->base + reg);
}
static void tegra_sflash_clear_status(struct tegra_sflash_data *tsd)
{
tegra_sflash_writel(tsd, SPI_RDY | SPI_FIFO_ERROR, SPI_STATUS);
}
static unsigned tegra_sflash_calculate_curr_xfer_param(
struct spi_device *spi, struct tegra_sflash_data *tsd,
struct spi_transfer *t)
{
unsigned remain_len = t->len - tsd->cur_pos;
unsigned max_word;
tsd->bytes_per_word = (t->bits_per_word - 1) / 8 + 1;
max_word = remain_len / tsd->bytes_per_word;
if (max_word > SPI_FIFO_DEPTH)
max_word = SPI_FIFO_DEPTH;
tsd->curr_xfer_words = max_word;
return max_word;
}
static unsigned tegra_sflash_fill_tx_fifo_from_client_txbuf(
struct tegra_sflash_data *tsd, struct spi_transfer *t)
{
unsigned nbytes;
unsigned long status;
unsigned max_n_32bit = tsd->curr_xfer_words;
u8 *tx_buf = (u8 *)t->tx_buf + tsd->cur_tx_pos;
if (max_n_32bit > SPI_FIFO_DEPTH)
max_n_32bit = SPI_FIFO_DEPTH;
nbytes = max_n_32bit * tsd->bytes_per_word;
status = tegra_sflash_readl(tsd, SPI_STATUS);
while (!(status & SPI_TXF_FULL)) {
int i;
unsigned int x = 0;
for (i = 0; nbytes && (i < tsd->bytes_per_word);
i++, nbytes--)
x |= ((*tx_buf++) << i*8);
tegra_sflash_writel(tsd, x, SPI_TX_FIFO);
if (!nbytes)
break;
status = tegra_sflash_readl(tsd, SPI_STATUS);
}
tsd->cur_tx_pos += max_n_32bit * tsd->bytes_per_word;
return max_n_32bit;
}
static int tegra_sflash_read_rx_fifo_to_client_rxbuf(
struct tegra_sflash_data *tsd, struct spi_transfer *t)
{
unsigned long status;
unsigned int read_words = 0;
u8 *rx_buf = (u8 *)t->rx_buf + tsd->cur_rx_pos;
status = tegra_sflash_readl(tsd, SPI_STATUS);
while (!(status & SPI_RXF_EMPTY)) {
int i;
unsigned long x;
x = tegra_sflash_readl(tsd, SPI_RX_FIFO);
for (i = 0; (i < tsd->bytes_per_word); i++)
*rx_buf++ = (x >> (i*8)) & 0xFF;
read_words++;
status = tegra_sflash_readl(tsd, SPI_STATUS);
}
tsd->cur_rx_pos += read_words * tsd->bytes_per_word;
return 0;
}
static int tegra_sflash_start_cpu_based_transfer(
struct tegra_sflash_data *tsd, struct spi_transfer *t)
{
unsigned long val = 0;
unsigned cur_words;
if (tsd->cur_direction & DATA_DIR_TX)
val |= SPI_IE_TXC;
if (tsd->cur_direction & DATA_DIR_RX)
val |= SPI_IE_RXC;
tegra_sflash_writel(tsd, val, SPI_DMA_CTL);
tsd->dma_control_reg = val;
if (tsd->cur_direction & DATA_DIR_TX)
cur_words = tegra_sflash_fill_tx_fifo_from_client_txbuf(tsd, t);
else
cur_words = tsd->curr_xfer_words;
val |= SPI_DMA_BLK_COUNT(cur_words);
tegra_sflash_writel(tsd, val, SPI_DMA_CTL);
tsd->dma_control_reg = val;
val |= SPI_DMA_EN;
tegra_sflash_writel(tsd, val, SPI_DMA_CTL);
return 0;
}
static int tegra_sflash_start_transfer_one(struct spi_device *spi,
struct spi_transfer *t, bool is_first_of_msg,
bool is_single_xfer)
{
struct tegra_sflash_data *tsd = spi_master_get_devdata(spi->master);
u32 speed;
unsigned long command;
speed = t->speed_hz ? t->speed_hz : spi->max_speed_hz;
if (!speed)
speed = tsd->spi_max_frequency;
if (speed != tsd->cur_speed) {
clk_set_rate(tsd->clk, speed);
tsd->cur_speed = speed;
}
tsd->cur_spi = spi;
tsd->cur_pos = 0;
tsd->cur_rx_pos = 0;
tsd->cur_tx_pos = 0;
tsd->curr_xfer = t;
tegra_sflash_calculate_curr_xfer_param(spi, tsd, t);
if (is_first_of_msg) {
command = tsd->def_command_reg;
command |= SPI_BIT_LENGTH(t->bits_per_word - 1);
command |= SPI_CS_VAL_HIGH;
command &= ~SPI_MODES;
if (spi->mode & SPI_CPHA)
command |= SPI_CK_SDA_FALLING;
if (spi->mode & SPI_CPOL)
command |= SPI_ACTIVE_SCLK_DRIVE_HIGH;
else
command |= SPI_ACTIVE_SCLK_DRIVE_LOW;
command |= SPI_CS0_EN << spi->chip_select;
} else {
command = tsd->command_reg;
command &= ~SPI_BIT_LENGTH(~0);
command |= SPI_BIT_LENGTH(t->bits_per_word - 1);
command &= ~(SPI_RX_EN | SPI_TX_EN);
}
tsd->cur_direction = 0;
if (t->rx_buf) {
command |= SPI_RX_EN;
tsd->cur_direction |= DATA_DIR_RX;
}
if (t->tx_buf) {
command |= SPI_TX_EN;
tsd->cur_direction |= DATA_DIR_TX;
}
tegra_sflash_writel(tsd, command, SPI_COMMAND);
tsd->command_reg = command;
return tegra_sflash_start_cpu_based_transfer(tsd, t);
}
static int tegra_sflash_transfer_one_message(struct spi_master *master,
struct spi_message *msg)
{
bool is_first_msg = true;
int single_xfer;
struct tegra_sflash_data *tsd = spi_master_get_devdata(master);
struct spi_transfer *xfer;
struct spi_device *spi = msg->spi;
int ret;
ret = pm_runtime_get_sync(tsd->dev);
if (ret < 0) {
dev_err(tsd->dev, "pm_runtime_get() failed, err = %d\n", ret);
return ret;
}
msg->status = 0;
msg->actual_length = 0;
single_xfer = list_is_singular(&msg->transfers);
list_for_each_entry(xfer, &msg->transfers, transfer_list) {
INIT_COMPLETION(tsd->xfer_completion);
ret = tegra_sflash_start_transfer_one(spi, xfer,
is_first_msg, single_xfer);
if (ret < 0) {
dev_err(tsd->dev,
"spi can not start transfer, err %d\n", ret);
goto exit;
}
is_first_msg = false;
ret = wait_for_completion_timeout(&tsd->xfer_completion,
SPI_DMA_TIMEOUT);
if (WARN_ON(ret == 0)) {
dev_err(tsd->dev,
"spi trasfer timeout, err %d\n", ret);
ret = -EIO;
goto exit;
}
if (tsd->tx_status || tsd->rx_status) {
dev_err(tsd->dev, "Error in Transfer\n");
ret = -EIO;
goto exit;
}
msg->actual_length += xfer->len;
if (xfer->cs_change && xfer->delay_usecs) {
tegra_sflash_writel(tsd, tsd->def_command_reg,
SPI_COMMAND);
udelay(xfer->delay_usecs);
}
}
ret = 0;
exit:
tegra_sflash_writel(tsd, tsd->def_command_reg, SPI_COMMAND);
msg->status = ret;
spi_finalize_current_message(master);
pm_runtime_put(tsd->dev);
return ret;
}
static irqreturn_t handle_cpu_based_xfer(struct tegra_sflash_data *tsd)
{
struct spi_transfer *t = tsd->curr_xfer;
unsigned long flags;
spin_lock_irqsave(&tsd->lock, flags);
if (tsd->tx_status || tsd->rx_status || (tsd->status_reg & SPI_BSY)) {
dev_err(tsd->dev,
"CpuXfer ERROR bit set 0x%x\n", tsd->status_reg);
dev_err(tsd->dev,
"CpuXfer 0x%08x:0x%08x\n", tsd->command_reg,
tsd->dma_control_reg);
tegra_periph_reset_assert(tsd->clk);
udelay(2);
tegra_periph_reset_deassert(tsd->clk);
complete(&tsd->xfer_completion);
goto exit;
}
if (tsd->cur_direction & DATA_DIR_RX)
tegra_sflash_read_rx_fifo_to_client_rxbuf(tsd, t);
if (tsd->cur_direction & DATA_DIR_TX)
tsd->cur_pos = tsd->cur_tx_pos;
else
tsd->cur_pos = tsd->cur_rx_pos;
if (tsd->cur_pos == t->len) {
complete(&tsd->xfer_completion);
goto exit;
}
tegra_sflash_calculate_curr_xfer_param(tsd->cur_spi, tsd, t);
tegra_sflash_start_cpu_based_transfer(tsd, t);
exit:
spin_unlock_irqrestore(&tsd->lock, flags);
return IRQ_HANDLED;
}
static irqreturn_t tegra_sflash_isr(int irq, void *context_data)
{
struct tegra_sflash_data *tsd = context_data;
tsd->status_reg = tegra_sflash_readl(tsd, SPI_STATUS);
if (tsd->cur_direction & DATA_DIR_TX)
tsd->tx_status = tsd->status_reg & SPI_TX_OVF;
if (tsd->cur_direction & DATA_DIR_RX)
tsd->rx_status = tsd->status_reg & SPI_RX_UNF;
tegra_sflash_clear_status(tsd);
return handle_cpu_based_xfer(tsd);
}
static struct tegra_spi_platform_data *tegra_sflash_parse_dt(
struct platform_device *pdev)
{
struct tegra_spi_platform_data *pdata;
struct device_node *np = pdev->dev.of_node;
u32 max_freq;
pdata = devm_kzalloc(&pdev->dev, sizeof(*pdata), GFP_KERNEL);
if (!pdata) {
dev_err(&pdev->dev, "Memory alloc for pdata failed\n");
return NULL;
}
if (!of_property_read_u32(np, "spi-max-frequency", &max_freq))
pdata->spi_max_frequency = max_freq;
return pdata;
}
static int tegra_sflash_probe(struct platform_device *pdev)
{
struct spi_master *master;
struct tegra_sflash_data *tsd;
struct resource *r;
struct tegra_spi_platform_data *pdata = pdev->dev.platform_data;
int ret;
const struct of_device_id *match;
match = of_match_device(of_match_ptr(tegra_sflash_of_match),
&pdev->dev);
if (!match) {
dev_err(&pdev->dev, "Error: No device match found\n");
return -ENODEV;
}
if (!pdata && pdev->dev.of_node)
pdata = tegra_sflash_parse_dt(pdev);
if (!pdata) {
dev_err(&pdev->dev, "No platform data, exiting\n");
return -ENODEV;
}
if (!pdata->spi_max_frequency)
pdata->spi_max_frequency = 25000000;
master = spi_alloc_master(&pdev->dev, sizeof(*tsd));
if (!master) {
dev_err(&pdev->dev, "master allocation failed\n");
return -ENOMEM;
}
master->mode_bits = SPI_CPOL | SPI_CPHA;
master->transfer_one_message = tegra_sflash_transfer_one_message;
master->num_chipselect = MAX_CHIP_SELECT;
master->bus_num = -1;
dev_set_drvdata(&pdev->dev, master);
tsd = spi_master_get_devdata(master);
tsd->master = master;
tsd->dev = &pdev->dev;
spin_lock_init(&tsd->lock);
r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!r) {
dev_err(&pdev->dev, "No IO memory resource\n");
ret = -ENODEV;
goto exit_free_master;
}
tsd->base = devm_request_and_ioremap(&pdev->dev, r);
if (!tsd->base) {
dev_err(&pdev->dev,
"Cannot request memregion/iomap dma address\n");
ret = -EADDRNOTAVAIL;
goto exit_free_master;
}
tsd->irq = platform_get_irq(pdev, 0);
ret = request_irq(tsd->irq, tegra_sflash_isr, 0,
dev_name(&pdev->dev), tsd);
if (ret < 0) {
dev_err(&pdev->dev, "Failed to register ISR for IRQ %d\n",
tsd->irq);
goto exit_free_master;
}
tsd->clk = devm_clk_get(&pdev->dev, "spi");
if (IS_ERR(tsd->clk)) {
dev_err(&pdev->dev, "can not get clock\n");
ret = PTR_ERR(tsd->clk);
goto exit_free_irq;
}
tsd->spi_max_frequency = pdata->spi_max_frequency;
init_completion(&tsd->xfer_completion);
pm_runtime_enable(&pdev->dev);
if (!pm_runtime_enabled(&pdev->dev)) {
ret = tegra_sflash_runtime_resume(&pdev->dev);
if (ret)
goto exit_pm_disable;
}
ret = pm_runtime_get_sync(&pdev->dev);
if (ret < 0) {
dev_err(&pdev->dev, "pm runtime get failed, e = %d\n", ret);
goto exit_pm_disable;
}
tegra_periph_reset_assert(tsd->clk);
udelay(2);
tegra_periph_reset_deassert(tsd->clk);
tsd->def_command_reg = SPI_M_S | SPI_CS_SW;
tegra_sflash_writel(tsd, tsd->def_command_reg, SPI_COMMAND);
pm_runtime_put(&pdev->dev);
master->dev.of_node = pdev->dev.of_node;
ret = spi_register_master(master);
if (ret < 0) {
dev_err(&pdev->dev, "can not register to master err %d\n", ret);
goto exit_pm_disable;
}
return ret;
exit_pm_disable:
pm_runtime_disable(&pdev->dev);
if (!pm_runtime_status_suspended(&pdev->dev))
tegra_sflash_runtime_suspend(&pdev->dev);
exit_free_irq:
free_irq(tsd->irq, tsd);
exit_free_master:
spi_master_put(master);
return ret;
}
static int tegra_sflash_remove(struct platform_device *pdev)
{
struct spi_master *master = dev_get_drvdata(&pdev->dev);
struct tegra_sflash_data *tsd = spi_master_get_devdata(master);
free_irq(tsd->irq, tsd);
spi_unregister_master(master);
pm_runtime_disable(&pdev->dev);
if (!pm_runtime_status_suspended(&pdev->dev))
tegra_sflash_runtime_suspend(&pdev->dev);
return 0;
}
static int tegra_sflash_suspend(struct device *dev)
{
struct spi_master *master = dev_get_drvdata(dev);
return spi_master_suspend(master);
}
static int tegra_sflash_resume(struct device *dev)
{
struct spi_master *master = dev_get_drvdata(dev);
struct tegra_sflash_data *tsd = spi_master_get_devdata(master);
int ret;
ret = pm_runtime_get_sync(dev);
if (ret < 0) {
dev_err(dev, "pm runtime failed, e = %d\n", ret);
return ret;
}
tegra_sflash_writel(tsd, tsd->command_reg, SPI_COMMAND);
pm_runtime_put(dev);
return spi_master_resume(master);
}
static int tegra_sflash_runtime_suspend(struct device *dev)
{
struct spi_master *master = dev_get_drvdata(dev);
struct tegra_sflash_data *tsd = spi_master_get_devdata(master);
tegra_sflash_readl(tsd, SPI_COMMAND);
clk_disable_unprepare(tsd->clk);
return 0;
}
static int tegra_sflash_runtime_resume(struct device *dev)
{
struct spi_master *master = dev_get_drvdata(dev);
struct tegra_sflash_data *tsd = spi_master_get_devdata(master);
int ret;
ret = clk_prepare_enable(tsd->clk);
if (ret < 0) {
dev_err(tsd->dev, "clk_prepare failed: %d\n", ret);
return ret;
}
return 0;
}
