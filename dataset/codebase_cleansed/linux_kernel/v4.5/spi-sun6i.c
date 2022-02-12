static inline u32 sun6i_spi_read(struct sun6i_spi *sspi, u32 reg)
{
return readl(sspi->base_addr + reg);
}
static inline void sun6i_spi_write(struct sun6i_spi *sspi, u32 reg, u32 value)
{
writel(value, sspi->base_addr + reg);
}
static inline void sun6i_spi_drain_fifo(struct sun6i_spi *sspi, int len)
{
u32 reg, cnt;
u8 byte;
reg = sun6i_spi_read(sspi, SUN6I_FIFO_STA_REG);
reg &= SUN6I_FIFO_STA_RF_CNT_MASK;
cnt = reg >> SUN6I_FIFO_STA_RF_CNT_BITS;
if (len > cnt)
len = cnt;
while (len--) {
byte = readb(sspi->base_addr + SUN6I_RXDATA_REG);
if (sspi->rx_buf)
*sspi->rx_buf++ = byte;
}
}
static inline void sun6i_spi_fill_fifo(struct sun6i_spi *sspi, int len)
{
u8 byte;
if (len > sspi->len)
len = sspi->len;
while (len--) {
byte = sspi->tx_buf ? *sspi->tx_buf++ : 0;
writeb(byte, sspi->base_addr + SUN6I_TXDATA_REG);
sspi->len--;
}
}
static void sun6i_spi_set_cs(struct spi_device *spi, bool enable)
{
struct sun6i_spi *sspi = spi_master_get_devdata(spi->master);
u32 reg;
reg = sun6i_spi_read(sspi, SUN6I_TFR_CTL_REG);
reg &= ~SUN6I_TFR_CTL_CS_MASK;
reg |= SUN6I_TFR_CTL_CS(spi->chip_select);
if (enable)
reg |= SUN6I_TFR_CTL_CS_LEVEL;
else
reg &= ~SUN6I_TFR_CTL_CS_LEVEL;
sun6i_spi_write(sspi, SUN6I_TFR_CTL_REG, reg);
}
static int sun6i_spi_transfer_one(struct spi_master *master,
struct spi_device *spi,
struct spi_transfer *tfr)
{
struct sun6i_spi *sspi = spi_master_get_devdata(master);
unsigned int mclk_rate, div, timeout;
unsigned int tx_len = 0;
int ret = 0;
u32 reg;
if (tfr->len > SUN6I_FIFO_DEPTH)
return -EINVAL;
reinit_completion(&sspi->done);
sspi->tx_buf = tfr->tx_buf;
sspi->rx_buf = tfr->rx_buf;
sspi->len = tfr->len;
sun6i_spi_write(sspi, SUN6I_INT_STA_REG, ~0);
sun6i_spi_write(sspi, SUN6I_FIFO_CTL_REG,
SUN6I_FIFO_CTL_RF_RST | SUN6I_FIFO_CTL_TF_RST);
reg = sun6i_spi_read(sspi, SUN6I_TFR_CTL_REG);
if (spi->mode & SPI_CPOL)
reg |= SUN6I_TFR_CTL_CPOL;
else
reg &= ~SUN6I_TFR_CTL_CPOL;
if (spi->mode & SPI_CPHA)
reg |= SUN6I_TFR_CTL_CPHA;
else
reg &= ~SUN6I_TFR_CTL_CPHA;
if (spi->mode & SPI_LSB_FIRST)
reg |= SUN6I_TFR_CTL_FBS;
else
reg &= ~SUN6I_TFR_CTL_FBS;
if (sspi->rx_buf)
reg &= ~SUN6I_TFR_CTL_DHB;
else
reg |= SUN6I_TFR_CTL_DHB;
reg |= SUN6I_TFR_CTL_CS_MANUAL;
sun6i_spi_write(sspi, SUN6I_TFR_CTL_REG, reg);
mclk_rate = clk_get_rate(sspi->mclk);
if (mclk_rate < (2 * tfr->speed_hz)) {
clk_set_rate(sspi->mclk, 2 * tfr->speed_hz);
mclk_rate = clk_get_rate(sspi->mclk);
}
div = mclk_rate / (2 * tfr->speed_hz);
if (div <= (SUN6I_CLK_CTL_CDR2_MASK + 1)) {
if (div > 0)
div--;
reg = SUN6I_CLK_CTL_CDR2(div) | SUN6I_CLK_CTL_DRS;
} else {
div = ilog2(mclk_rate) - ilog2(tfr->speed_hz);
reg = SUN6I_CLK_CTL_CDR1(div);
}
sun6i_spi_write(sspi, SUN6I_CLK_CTL_REG, reg);
if (sspi->tx_buf)
tx_len = tfr->len;
sun6i_spi_write(sspi, SUN6I_BURST_CNT_REG, SUN6I_BURST_CNT(tfr->len));
sun6i_spi_write(sspi, SUN6I_XMIT_CNT_REG, SUN6I_XMIT_CNT(tx_len));
sun6i_spi_write(sspi, SUN6I_BURST_CTL_CNT_REG,
SUN6I_BURST_CTL_CNT_STC(tx_len));
sun6i_spi_fill_fifo(sspi, SUN6I_FIFO_DEPTH);
sun6i_spi_write(sspi, SUN6I_INT_CTL_REG, SUN6I_INT_CTL_TC);
reg = sun6i_spi_read(sspi, SUN6I_TFR_CTL_REG);
sun6i_spi_write(sspi, SUN6I_TFR_CTL_REG, reg | SUN6I_TFR_CTL_XCH);
timeout = wait_for_completion_timeout(&sspi->done,
msecs_to_jiffies(1000));
if (!timeout) {
ret = -ETIMEDOUT;
goto out;
}
sun6i_spi_drain_fifo(sspi, SUN6I_FIFO_DEPTH);
out:
sun6i_spi_write(sspi, SUN6I_INT_CTL_REG, 0);
return ret;
}
static irqreturn_t sun6i_spi_handler(int irq, void *dev_id)
{
struct sun6i_spi *sspi = dev_id;
u32 status = sun6i_spi_read(sspi, SUN6I_INT_STA_REG);
if (status & SUN6I_INT_CTL_TC) {
sun6i_spi_write(sspi, SUN6I_INT_STA_REG, SUN6I_INT_CTL_TC);
complete(&sspi->done);
return IRQ_HANDLED;
}
return IRQ_NONE;
}
static int sun6i_spi_runtime_resume(struct device *dev)
{
struct spi_master *master = dev_get_drvdata(dev);
struct sun6i_spi *sspi = spi_master_get_devdata(master);
int ret;
ret = clk_prepare_enable(sspi->hclk);
if (ret) {
dev_err(dev, "Couldn't enable AHB clock\n");
goto out;
}
ret = clk_prepare_enable(sspi->mclk);
if (ret) {
dev_err(dev, "Couldn't enable module clock\n");
goto err;
}
ret = reset_control_deassert(sspi->rstc);
if (ret) {
dev_err(dev, "Couldn't deassert the device from reset\n");
goto err2;
}
sun6i_spi_write(sspi, SUN6I_GBL_CTL_REG,
SUN6I_GBL_CTL_BUS_ENABLE | SUN6I_GBL_CTL_MASTER | SUN6I_GBL_CTL_TP);
return 0;
err2:
clk_disable_unprepare(sspi->mclk);
err:
clk_disable_unprepare(sspi->hclk);
out:
return ret;
}
static int sun6i_spi_runtime_suspend(struct device *dev)
{
struct spi_master *master = dev_get_drvdata(dev);
struct sun6i_spi *sspi = spi_master_get_devdata(master);
reset_control_assert(sspi->rstc);
clk_disable_unprepare(sspi->mclk);
clk_disable_unprepare(sspi->hclk);
return 0;
}
static int sun6i_spi_probe(struct platform_device *pdev)
{
struct spi_master *master;
struct sun6i_spi *sspi;
struct resource *res;
int ret = 0, irq;
master = spi_alloc_master(&pdev->dev, sizeof(struct sun6i_spi));
if (!master) {
dev_err(&pdev->dev, "Unable to allocate SPI Master\n");
return -ENOMEM;
}
platform_set_drvdata(pdev, master);
sspi = spi_master_get_devdata(master);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
sspi->base_addr = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(sspi->base_addr)) {
ret = PTR_ERR(sspi->base_addr);
goto err_free_master;
}
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_err(&pdev->dev, "No spi IRQ specified\n");
ret = -ENXIO;
goto err_free_master;
}
ret = devm_request_irq(&pdev->dev, irq, sun6i_spi_handler,
0, "sun6i-spi", sspi);
if (ret) {
dev_err(&pdev->dev, "Cannot request IRQ\n");
goto err_free_master;
}
sspi->master = master;
master->set_cs = sun6i_spi_set_cs;
master->transfer_one = sun6i_spi_transfer_one;
master->num_chipselect = 4;
master->mode_bits = SPI_CPOL | SPI_CPHA | SPI_CS_HIGH | SPI_LSB_FIRST;
master->bits_per_word_mask = SPI_BPW_MASK(8);
master->dev.of_node = pdev->dev.of_node;
master->auto_runtime_pm = true;
sspi->hclk = devm_clk_get(&pdev->dev, "ahb");
if (IS_ERR(sspi->hclk)) {
dev_err(&pdev->dev, "Unable to acquire AHB clock\n");
ret = PTR_ERR(sspi->hclk);
goto err_free_master;
}
sspi->mclk = devm_clk_get(&pdev->dev, "mod");
if (IS_ERR(sspi->mclk)) {
dev_err(&pdev->dev, "Unable to acquire module clock\n");
ret = PTR_ERR(sspi->mclk);
goto err_free_master;
}
init_completion(&sspi->done);
sspi->rstc = devm_reset_control_get(&pdev->dev, NULL);
if (IS_ERR(sspi->rstc)) {
dev_err(&pdev->dev, "Couldn't get reset controller\n");
ret = PTR_ERR(sspi->rstc);
goto err_free_master;
}
ret = sun6i_spi_runtime_resume(&pdev->dev);
if (ret) {
dev_err(&pdev->dev, "Couldn't resume the device\n");
goto err_free_master;
}
pm_runtime_set_active(&pdev->dev);
pm_runtime_enable(&pdev->dev);
pm_runtime_idle(&pdev->dev);
ret = devm_spi_register_master(&pdev->dev, master);
if (ret) {
dev_err(&pdev->dev, "cannot register SPI master\n");
goto err_pm_disable;
}
return 0;
err_pm_disable:
pm_runtime_disable(&pdev->dev);
sun6i_spi_runtime_suspend(&pdev->dev);
err_free_master:
spi_master_put(master);
return ret;
}
static int sun6i_spi_remove(struct platform_device *pdev)
{
pm_runtime_disable(&pdev->dev);
return 0;
}
