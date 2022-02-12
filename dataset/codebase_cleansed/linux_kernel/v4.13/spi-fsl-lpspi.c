static void fsl_lpspi_intctrl(struct fsl_lpspi_data *fsl_lpspi,
unsigned int enable)
{
writel(enable, fsl_lpspi->base + IMX7ULP_IER);
}
static int lpspi_prepare_xfer_hardware(struct spi_master *master)
{
struct fsl_lpspi_data *fsl_lpspi = spi_master_get_devdata(master);
return clk_prepare_enable(fsl_lpspi->clk);
}
static int lpspi_unprepare_xfer_hardware(struct spi_master *master)
{
struct fsl_lpspi_data *fsl_lpspi = spi_master_get_devdata(master);
clk_disable_unprepare(fsl_lpspi->clk);
return 0;
}
static int fsl_lpspi_txfifo_empty(struct fsl_lpspi_data *fsl_lpspi)
{
u32 txcnt;
unsigned long orig_jiffies = jiffies;
do {
txcnt = readl(fsl_lpspi->base + IMX7ULP_FSR) & 0xff;
if (time_after(jiffies, orig_jiffies + msecs_to_jiffies(500))) {
dev_dbg(fsl_lpspi->dev, "txfifo empty timeout\n");
return -ETIMEDOUT;
}
cond_resched();
} while (txcnt);
return 0;
}
static void fsl_lpspi_write_tx_fifo(struct fsl_lpspi_data *fsl_lpspi)
{
u8 txfifo_cnt;
txfifo_cnt = readl(fsl_lpspi->base + IMX7ULP_FSR) & 0xff;
while (txfifo_cnt < fsl_lpspi->txfifosize) {
if (!fsl_lpspi->remain)
break;
fsl_lpspi->tx(fsl_lpspi);
txfifo_cnt++;
}
if (!fsl_lpspi->remain && (txfifo_cnt < fsl_lpspi->txfifosize))
writel(0, fsl_lpspi->base + IMX7ULP_TDR);
else
fsl_lpspi_intctrl(fsl_lpspi, IER_TDIE);
}
static void fsl_lpspi_read_rx_fifo(struct fsl_lpspi_data *fsl_lpspi)
{
while (!(readl(fsl_lpspi->base + IMX7ULP_RSR) & RSR_RXEMPTY))
fsl_lpspi->rx(fsl_lpspi);
}
static void fsl_lpspi_set_cmd(struct fsl_lpspi_data *fsl_lpspi,
bool is_first_xfer)
{
u32 temp = 0;
temp |= fsl_lpspi->config.bpw - 1;
temp |= fsl_lpspi->config.prescale << 27;
temp |= (fsl_lpspi->config.mode & 0x3) << 30;
temp |= (fsl_lpspi->config.chip_select & 0x3) << 24;
temp |= TCR_CONT;
if (is_first_xfer)
temp &= ~TCR_CONTC;
else
temp |= TCR_CONTC;
writel(temp, fsl_lpspi->base + IMX7ULP_TCR);
dev_dbg(fsl_lpspi->dev, "TCR=0x%x\n", temp);
}
static void fsl_lpspi_set_watermark(struct fsl_lpspi_data *fsl_lpspi)
{
u32 temp;
temp = fsl_lpspi->txfifosize >> 1 | (fsl_lpspi->rxfifosize >> 1) << 16;
writel(temp, fsl_lpspi->base + IMX7ULP_FCR);
dev_dbg(fsl_lpspi->dev, "FCR=0x%x\n", temp);
}
static int fsl_lpspi_set_bitrate(struct fsl_lpspi_data *fsl_lpspi)
{
struct lpspi_config config = fsl_lpspi->config;
unsigned int perclk_rate, scldiv;
u8 prescale;
perclk_rate = clk_get_rate(fsl_lpspi->clk);
for (prescale = 0; prescale < 8; prescale++) {
scldiv = perclk_rate /
(clkdivs[prescale] * config.speed_hz) - 2;
if (scldiv < 256) {
fsl_lpspi->config.prescale = prescale;
break;
}
}
if (prescale == 8 && scldiv >= 256)
return -EINVAL;
writel(scldiv, fsl_lpspi->base + IMX7ULP_CCR);
dev_dbg(fsl_lpspi->dev, "perclk=%d, speed=%d, prescale =%d, scldiv=%d\n",
perclk_rate, config.speed_hz, prescale, scldiv);
return 0;
}
static int fsl_lpspi_config(struct fsl_lpspi_data *fsl_lpspi)
{
u32 temp;
int ret;
temp = CR_RST;
writel(temp, fsl_lpspi->base + IMX7ULP_CR);
writel(0, fsl_lpspi->base + IMX7ULP_CR);
ret = fsl_lpspi_set_bitrate(fsl_lpspi);
if (ret)
return ret;
fsl_lpspi_set_watermark(fsl_lpspi);
temp = CFGR1_PCSCFG | CFGR1_MASTER | CFGR1_NOSTALL;
if (fsl_lpspi->config.mode & SPI_CS_HIGH)
temp |= CFGR1_PCSPOL;
writel(temp, fsl_lpspi->base + IMX7ULP_CFGR1);
temp = readl(fsl_lpspi->base + IMX7ULP_CR);
temp |= CR_RRF | CR_RTF | CR_MEN;
writel(temp, fsl_lpspi->base + IMX7ULP_CR);
return 0;
}
static void fsl_lpspi_setup_transfer(struct spi_device *spi,
struct spi_transfer *t)
{
struct fsl_lpspi_data *fsl_lpspi = spi_master_get_devdata(spi->master);
fsl_lpspi->config.mode = spi->mode;
fsl_lpspi->config.bpw = t ? t->bits_per_word : spi->bits_per_word;
fsl_lpspi->config.speed_hz = t ? t->speed_hz : spi->max_speed_hz;
fsl_lpspi->config.chip_select = spi->chip_select;
if (!fsl_lpspi->config.speed_hz)
fsl_lpspi->config.speed_hz = spi->max_speed_hz;
if (!fsl_lpspi->config.bpw)
fsl_lpspi->config.bpw = spi->bits_per_word;
if (fsl_lpspi->config.bpw <= 8) {
fsl_lpspi->rx = fsl_lpspi_buf_rx_u8;
fsl_lpspi->tx = fsl_lpspi_buf_tx_u8;
} else if (fsl_lpspi->config.bpw <= 16) {
fsl_lpspi->rx = fsl_lpspi_buf_rx_u16;
fsl_lpspi->tx = fsl_lpspi_buf_tx_u16;
} else {
fsl_lpspi->rx = fsl_lpspi_buf_rx_u32;
fsl_lpspi->tx = fsl_lpspi_buf_tx_u32;
}
fsl_lpspi_config(fsl_lpspi);
}
static int fsl_lpspi_transfer_one(struct spi_master *master,
struct spi_device *spi,
struct spi_transfer *t)
{
struct fsl_lpspi_data *fsl_lpspi = spi_master_get_devdata(master);
int ret;
fsl_lpspi->tx_buf = t->tx_buf;
fsl_lpspi->rx_buf = t->rx_buf;
fsl_lpspi->remain = t->len;
reinit_completion(&fsl_lpspi->xfer_done);
fsl_lpspi_write_tx_fifo(fsl_lpspi);
ret = wait_for_completion_timeout(&fsl_lpspi->xfer_done, HZ);
if (!ret) {
dev_dbg(fsl_lpspi->dev, "wait for completion timeout\n");
return -ETIMEDOUT;
}
ret = fsl_lpspi_txfifo_empty(fsl_lpspi);
if (ret)
return ret;
fsl_lpspi_read_rx_fifo(fsl_lpspi);
return 0;
}
static int fsl_lpspi_transfer_one_msg(struct spi_master *master,
struct spi_message *msg)
{
struct fsl_lpspi_data *fsl_lpspi = spi_master_get_devdata(master);
struct spi_device *spi = msg->spi;
struct spi_transfer *xfer;
bool is_first_xfer = true;
u32 temp;
int ret = 0;
msg->status = 0;
msg->actual_length = 0;
list_for_each_entry(xfer, &msg->transfers, transfer_list) {
fsl_lpspi_setup_transfer(spi, xfer);
fsl_lpspi_set_cmd(fsl_lpspi, is_first_xfer);
is_first_xfer = false;
ret = fsl_lpspi_transfer_one(master, spi, xfer);
if (ret < 0)
goto complete;
msg->actual_length += xfer->len;
}
complete:
temp = readl(fsl_lpspi->base + IMX7ULP_TCR);
temp &= ~TCR_CONTC;
writel(temp, fsl_lpspi->base + IMX7ULP_TCR);
msg->status = ret;
spi_finalize_current_message(master);
return ret;
}
static irqreturn_t fsl_lpspi_isr(int irq, void *dev_id)
{
struct fsl_lpspi_data *fsl_lpspi = dev_id;
u32 temp;
fsl_lpspi_intctrl(fsl_lpspi, 0);
temp = readl(fsl_lpspi->base + IMX7ULP_SR);
fsl_lpspi_read_rx_fifo(fsl_lpspi);
if (temp & SR_TDF) {
fsl_lpspi_write_tx_fifo(fsl_lpspi);
if (!fsl_lpspi->remain)
complete(&fsl_lpspi->xfer_done);
return IRQ_HANDLED;
}
return IRQ_NONE;
}
static int fsl_lpspi_probe(struct platform_device *pdev)
{
struct fsl_lpspi_data *fsl_lpspi;
struct spi_master *master;
struct resource *res;
int ret, irq;
u32 temp;
master = spi_alloc_master(&pdev->dev, sizeof(struct fsl_lpspi_data));
if (!master)
return -ENOMEM;
platform_set_drvdata(pdev, master);
master->bits_per_word_mask = SPI_BPW_RANGE_MASK(8, 32);
master->bus_num = pdev->id;
fsl_lpspi = spi_master_get_devdata(master);
fsl_lpspi->dev = &pdev->dev;
master->transfer_one_message = fsl_lpspi_transfer_one_msg;
master->prepare_transfer_hardware = lpspi_prepare_xfer_hardware;
master->unprepare_transfer_hardware = lpspi_unprepare_xfer_hardware;
master->mode_bits = SPI_CPOL | SPI_CPHA | SPI_CS_HIGH;
master->flags = SPI_MASTER_MUST_RX | SPI_MASTER_MUST_TX;
master->dev.of_node = pdev->dev.of_node;
master->bus_num = pdev->id;
init_completion(&fsl_lpspi->xfer_done);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
fsl_lpspi->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(fsl_lpspi->base)) {
ret = PTR_ERR(fsl_lpspi->base);
goto out_master_put;
}
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
ret = irq;
goto out_master_put;
}
ret = devm_request_irq(&pdev->dev, irq, fsl_lpspi_isr, 0,
dev_name(&pdev->dev), fsl_lpspi);
if (ret) {
dev_err(&pdev->dev, "can't get irq%d: %d\n", irq, ret);
goto out_master_put;
}
fsl_lpspi->clk = devm_clk_get(&pdev->dev, "ipg");
if (IS_ERR(fsl_lpspi->clk)) {
ret = PTR_ERR(fsl_lpspi->clk);
goto out_master_put;
}
ret = clk_prepare_enable(fsl_lpspi->clk);
if (ret) {
dev_err(&pdev->dev, "can't enable lpspi clock, ret=%d\n", ret);
goto out_master_put;
}
temp = readl(fsl_lpspi->base + IMX7ULP_PARAM);
fsl_lpspi->txfifosize = 1 << (temp & 0x0f);
fsl_lpspi->rxfifosize = 1 << ((temp >> 8) & 0x0f);
clk_disable_unprepare(fsl_lpspi->clk);
ret = devm_spi_register_master(&pdev->dev, master);
if (ret < 0) {
dev_err(&pdev->dev, "spi_register_master error.\n");
goto out_master_put;
}
return 0;
out_master_put:
spi_master_put(master);
return ret;
}
static int fsl_lpspi_remove(struct platform_device *pdev)
{
struct spi_master *master = platform_get_drvdata(pdev);
struct fsl_lpspi_data *fsl_lpspi = spi_master_get_devdata(master);
clk_disable_unprepare(fsl_lpspi->clk);
return 0;
}
