static inline int is_imx27_cspi(struct spi_imx_data *d)
{
return d->devtype_data->devtype == IMX27_CSPI;
}
static inline int is_imx35_cspi(struct spi_imx_data *d)
{
return d->devtype_data->devtype == IMX35_CSPI;
}
static inline int is_imx51_ecspi(struct spi_imx_data *d)
{
return d->devtype_data->devtype == IMX51_ECSPI;
}
static inline unsigned spi_imx_get_fifosize(struct spi_imx_data *d)
{
return is_imx51_ecspi(d) ? 64 : 8;
}
static unsigned int spi_imx_clkdiv_1(unsigned int fin,
unsigned int fspi, unsigned int max)
{
int i;
for (i = 2; i < max; i++)
if (fspi * mxc_clkdivs[i] >= fin)
return i;
return max;
}
static unsigned int spi_imx_clkdiv_2(unsigned int fin,
unsigned int fspi, unsigned int *fres)
{
int i, div = 4;
for (i = 0; i < 7; i++) {
if (fspi * div >= fin)
goto out;
div <<= 1;
}
out:
*fres = fin / div;
return i;
}
static int spi_imx_bytes_per_word(const int bpw)
{
return DIV_ROUND_UP(bpw, BITS_PER_BYTE);
}
static bool spi_imx_can_dma(struct spi_master *master, struct spi_device *spi,
struct spi_transfer *transfer)
{
struct spi_imx_data *spi_imx = spi_master_get_devdata(master);
unsigned int bpw;
if (!master->dma_rx)
return false;
if (!transfer)
return false;
bpw = transfer->bits_per_word;
if (!bpw)
bpw = spi->bits_per_word;
bpw = spi_imx_bytes_per_word(bpw);
if (bpw != 1 && bpw != 2 && bpw != 4)
return false;
if (transfer->len < spi_imx->wml * bpw)
return false;
if (transfer->len % (spi_imx->wml * bpw))
return false;
return true;
}
static unsigned int mx51_ecspi_clkdiv(struct spi_imx_data *spi_imx,
unsigned int fspi, unsigned int *fres)
{
unsigned int pre, post;
unsigned int fin = spi_imx->spi_clk;
if (unlikely(fspi > fin))
return 0;
post = fls(fin) - fls(fspi);
if (fin > fspi << post)
post++;
post = max(4U, post) - 4;
if (unlikely(post > 0xf)) {
dev_err(spi_imx->dev, "cannot set clock freq: %u (base freq: %u)\n",
fspi, fin);
return 0xff;
}
pre = DIV_ROUND_UP(fin, fspi << post) - 1;
dev_dbg(spi_imx->dev, "%s: fin: %u, fspi: %u, post: %u, pre: %u\n",
__func__, fin, fspi, post, pre);
*fres = (fin / (pre + 1)) >> post;
return (pre << MX51_ECSPI_CTRL_PREDIV_OFFSET) |
(post << MX51_ECSPI_CTRL_POSTDIV_OFFSET);
}
static void mx51_ecspi_intctrl(struct spi_imx_data *spi_imx, int enable)
{
unsigned val = 0;
if (enable & MXC_INT_TE)
val |= MX51_ECSPI_INT_TEEN;
if (enable & MXC_INT_RR)
val |= MX51_ECSPI_INT_RREN;
writel(val, spi_imx->base + MX51_ECSPI_INT);
}
static void mx51_ecspi_trigger(struct spi_imx_data *spi_imx)
{
u32 reg;
reg = readl(spi_imx->base + MX51_ECSPI_CTRL);
reg |= MX51_ECSPI_CTRL_XCH;
writel(reg, spi_imx->base + MX51_ECSPI_CTRL);
}
static int mx51_ecspi_config(struct spi_device *spi,
struct spi_imx_config *config)
{
struct spi_imx_data *spi_imx = spi_master_get_devdata(spi->master);
u32 ctrl = MX51_ECSPI_CTRL_ENABLE;
u32 clk = config->speed_hz, delay, reg;
u32 cfg = readl(spi_imx->base + MX51_ECSPI_CONFIG);
ctrl |= MX51_ECSPI_CTRL_MODE_MASK;
ctrl |= mx51_ecspi_clkdiv(spi_imx, config->speed_hz, &clk);
spi_imx->spi_bus_clk = clk;
ctrl |= MX51_ECSPI_CTRL_CS(spi->chip_select);
ctrl |= (config->bpw - 1) << MX51_ECSPI_CTRL_BL_OFFSET;
cfg |= MX51_ECSPI_CONFIG_SBBCTRL(spi->chip_select);
if (spi->mode & SPI_CPHA)
cfg |= MX51_ECSPI_CONFIG_SCLKPHA(spi->chip_select);
else
cfg &= ~MX51_ECSPI_CONFIG_SCLKPHA(spi->chip_select);
if (spi->mode & SPI_CPOL) {
cfg |= MX51_ECSPI_CONFIG_SCLKPOL(spi->chip_select);
cfg |= MX51_ECSPI_CONFIG_SCLKCTL(spi->chip_select);
} else {
cfg &= ~MX51_ECSPI_CONFIG_SCLKPOL(spi->chip_select);
cfg &= ~MX51_ECSPI_CONFIG_SCLKCTL(spi->chip_select);
}
if (spi->mode & SPI_CS_HIGH)
cfg |= MX51_ECSPI_CONFIG_SSBPOL(spi->chip_select);
else
cfg &= ~MX51_ECSPI_CONFIG_SSBPOL(spi->chip_select);
if (spi_imx->usedma)
ctrl |= MX51_ECSPI_CTRL_SMC;
writel(ctrl, spi_imx->base + MX51_ECSPI_CTRL);
reg = readl(spi_imx->base + MX51_ECSPI_TESTREG);
if (spi->mode & SPI_LOOP)
reg |= MX51_ECSPI_TESTREG_LBC;
else
reg &= ~MX51_ECSPI_TESTREG_LBC;
writel(reg, spi_imx->base + MX51_ECSPI_TESTREG);
writel(cfg, spi_imx->base + MX51_ECSPI_CONFIG);
delay = (2 * 1000000) / clk;
if (likely(delay < 10))
udelay(delay);
else
usleep_range(delay, delay + 10);
writel(MX51_ECSPI_DMA_RX_WML(spi_imx->wml) |
MX51_ECSPI_DMA_TX_WML(spi_imx->wml) |
MX51_ECSPI_DMA_RXT_WML(spi_imx->wml) |
MX51_ECSPI_DMA_TEDEN | MX51_ECSPI_DMA_RXDEN |
MX51_ECSPI_DMA_RXTDEN, spi_imx->base + MX51_ECSPI_DMA);
return 0;
}
static int mx51_ecspi_rx_available(struct spi_imx_data *spi_imx)
{
return readl(spi_imx->base + MX51_ECSPI_STAT) & MX51_ECSPI_STAT_RR;
}
static void mx51_ecspi_reset(struct spi_imx_data *spi_imx)
{
while (mx51_ecspi_rx_available(spi_imx))
readl(spi_imx->base + MXC_CSPIRXDATA);
}
static void mx31_intctrl(struct spi_imx_data *spi_imx, int enable)
{
unsigned int val = 0;
if (enable & MXC_INT_TE)
val |= MX31_INTREG_TEEN;
if (enable & MXC_INT_RR)
val |= MX31_INTREG_RREN;
writel(val, spi_imx->base + MXC_CSPIINT);
}
static void mx31_trigger(struct spi_imx_data *spi_imx)
{
unsigned int reg;
reg = readl(spi_imx->base + MXC_CSPICTRL);
reg |= MX31_CSPICTRL_XCH;
writel(reg, spi_imx->base + MXC_CSPICTRL);
}
static int mx31_config(struct spi_device *spi, struct spi_imx_config *config)
{
struct spi_imx_data *spi_imx = spi_master_get_devdata(spi->master);
unsigned int reg = MX31_CSPICTRL_ENABLE | MX31_CSPICTRL_MASTER;
unsigned int clk;
reg |= spi_imx_clkdiv_2(spi_imx->spi_clk, config->speed_hz, &clk) <<
MX31_CSPICTRL_DR_SHIFT;
spi_imx->spi_bus_clk = clk;
if (is_imx35_cspi(spi_imx)) {
reg |= (config->bpw - 1) << MX35_CSPICTRL_BL_SHIFT;
reg |= MX31_CSPICTRL_SSCTL;
} else {
reg |= (config->bpw - 1) << MX31_CSPICTRL_BC_SHIFT;
}
if (spi->mode & SPI_CPHA)
reg |= MX31_CSPICTRL_PHA;
if (spi->mode & SPI_CPOL)
reg |= MX31_CSPICTRL_POL;
if (spi->mode & SPI_CS_HIGH)
reg |= MX31_CSPICTRL_SSPOL;
if (spi->cs_gpio < 0)
reg |= (spi->cs_gpio + 32) <<
(is_imx35_cspi(spi_imx) ? MX35_CSPICTRL_CS_SHIFT :
MX31_CSPICTRL_CS_SHIFT);
writel(reg, spi_imx->base + MXC_CSPICTRL);
reg = readl(spi_imx->base + MX31_CSPI_TESTREG);
if (spi->mode & SPI_LOOP)
reg |= MX31_TEST_LBC;
else
reg &= ~MX31_TEST_LBC;
writel(reg, spi_imx->base + MX31_CSPI_TESTREG);
return 0;
}
static int mx31_rx_available(struct spi_imx_data *spi_imx)
{
return readl(spi_imx->base + MX31_CSPISTATUS) & MX31_STATUS_RR;
}
static void mx31_reset(struct spi_imx_data *spi_imx)
{
while (readl(spi_imx->base + MX31_CSPISTATUS) & MX31_STATUS_RR)
readl(spi_imx->base + MXC_CSPIRXDATA);
}
static void mx21_intctrl(struct spi_imx_data *spi_imx, int enable)
{
unsigned int val = 0;
if (enable & MXC_INT_TE)
val |= MX21_INTREG_TEEN;
if (enable & MXC_INT_RR)
val |= MX21_INTREG_RREN;
writel(val, spi_imx->base + MXC_CSPIINT);
}
static void mx21_trigger(struct spi_imx_data *spi_imx)
{
unsigned int reg;
reg = readl(spi_imx->base + MXC_CSPICTRL);
reg |= MX21_CSPICTRL_XCH;
writel(reg, spi_imx->base + MXC_CSPICTRL);
}
static int mx21_config(struct spi_device *spi, struct spi_imx_config *config)
{
struct spi_imx_data *spi_imx = spi_master_get_devdata(spi->master);
unsigned int reg = MX21_CSPICTRL_ENABLE | MX21_CSPICTRL_MASTER;
unsigned int max = is_imx27_cspi(spi_imx) ? 16 : 18;
reg |= spi_imx_clkdiv_1(spi_imx->spi_clk, config->speed_hz, max) <<
MX21_CSPICTRL_DR_SHIFT;
reg |= config->bpw - 1;
if (spi->mode & SPI_CPHA)
reg |= MX21_CSPICTRL_PHA;
if (spi->mode & SPI_CPOL)
reg |= MX21_CSPICTRL_POL;
if (spi->mode & SPI_CS_HIGH)
reg |= MX21_CSPICTRL_SSPOL;
if (spi->cs_gpio < 0)
reg |= (spi->cs_gpio + 32) << MX21_CSPICTRL_CS_SHIFT;
writel(reg, spi_imx->base + MXC_CSPICTRL);
return 0;
}
static int mx21_rx_available(struct spi_imx_data *spi_imx)
{
return readl(spi_imx->base + MXC_CSPIINT) & MX21_INTREG_RR;
}
static void mx21_reset(struct spi_imx_data *spi_imx)
{
writel(1, spi_imx->base + MXC_RESET);
}
static void mx1_intctrl(struct spi_imx_data *spi_imx, int enable)
{
unsigned int val = 0;
if (enable & MXC_INT_TE)
val |= MX1_INTREG_TEEN;
if (enable & MXC_INT_RR)
val |= MX1_INTREG_RREN;
writel(val, spi_imx->base + MXC_CSPIINT);
}
static void mx1_trigger(struct spi_imx_data *spi_imx)
{
unsigned int reg;
reg = readl(spi_imx->base + MXC_CSPICTRL);
reg |= MX1_CSPICTRL_XCH;
writel(reg, spi_imx->base + MXC_CSPICTRL);
}
static int mx1_config(struct spi_device *spi, struct spi_imx_config *config)
{
struct spi_imx_data *spi_imx = spi_master_get_devdata(spi->master);
unsigned int reg = MX1_CSPICTRL_ENABLE | MX1_CSPICTRL_MASTER;
unsigned int clk;
reg |= spi_imx_clkdiv_2(spi_imx->spi_clk, config->speed_hz, &clk) <<
MX1_CSPICTRL_DR_SHIFT;
spi_imx->spi_bus_clk = clk;
reg |= config->bpw - 1;
if (spi->mode & SPI_CPHA)
reg |= MX1_CSPICTRL_PHA;
if (spi->mode & SPI_CPOL)
reg |= MX1_CSPICTRL_POL;
writel(reg, spi_imx->base + MXC_CSPICTRL);
return 0;
}
static int mx1_rx_available(struct spi_imx_data *spi_imx)
{
return readl(spi_imx->base + MXC_CSPIINT) & MX1_INTREG_RR;
}
static void mx1_reset(struct spi_imx_data *spi_imx)
{
writel(1, spi_imx->base + MXC_RESET);
}
static void spi_imx_chipselect(struct spi_device *spi, int is_active)
{
int active = is_active != BITBANG_CS_INACTIVE;
int dev_is_lowactive = !(spi->mode & SPI_CS_HIGH);
if (!gpio_is_valid(spi->cs_gpio))
return;
gpio_set_value(spi->cs_gpio, dev_is_lowactive ^ active);
}
static void spi_imx_push(struct spi_imx_data *spi_imx)
{
while (spi_imx->txfifo < spi_imx_get_fifosize(spi_imx)) {
if (!spi_imx->count)
break;
spi_imx->tx(spi_imx);
spi_imx->txfifo++;
}
spi_imx->devtype_data->trigger(spi_imx);
}
static irqreturn_t spi_imx_isr(int irq, void *dev_id)
{
struct spi_imx_data *spi_imx = dev_id;
while (spi_imx->devtype_data->rx_available(spi_imx)) {
spi_imx->rx(spi_imx);
spi_imx->txfifo--;
}
if (spi_imx->count) {
spi_imx_push(spi_imx);
return IRQ_HANDLED;
}
if (spi_imx->txfifo) {
spi_imx->devtype_data->intctrl(
spi_imx, MXC_INT_RR);
return IRQ_HANDLED;
}
spi_imx->devtype_data->intctrl(spi_imx, 0);
complete(&spi_imx->xfer_done);
return IRQ_HANDLED;
}
static int spi_imx_dma_configure(struct spi_master *master,
int bytes_per_word)
{
int ret;
enum dma_slave_buswidth buswidth;
struct dma_slave_config rx = {}, tx = {};
struct spi_imx_data *spi_imx = spi_master_get_devdata(master);
if (bytes_per_word == spi_imx->bytes_per_word)
return 0;
switch (bytes_per_word) {
case 4:
buswidth = DMA_SLAVE_BUSWIDTH_4_BYTES;
break;
case 2:
buswidth = DMA_SLAVE_BUSWIDTH_2_BYTES;
break;
case 1:
buswidth = DMA_SLAVE_BUSWIDTH_1_BYTE;
break;
default:
return -EINVAL;
}
tx.direction = DMA_MEM_TO_DEV;
tx.dst_addr = spi_imx->base_phys + MXC_CSPITXDATA;
tx.dst_addr_width = buswidth;
tx.dst_maxburst = spi_imx->wml;
ret = dmaengine_slave_config(master->dma_tx, &tx);
if (ret) {
dev_err(spi_imx->dev, "TX dma configuration failed with %d\n", ret);
return ret;
}
rx.direction = DMA_DEV_TO_MEM;
rx.src_addr = spi_imx->base_phys + MXC_CSPIRXDATA;
rx.src_addr_width = buswidth;
rx.src_maxburst = spi_imx->wml;
ret = dmaengine_slave_config(master->dma_rx, &rx);
if (ret) {
dev_err(spi_imx->dev, "RX dma configuration failed with %d\n", ret);
return ret;
}
spi_imx->bytes_per_word = bytes_per_word;
return 0;
}
static int spi_imx_setupxfer(struct spi_device *spi,
struct spi_transfer *t)
{
struct spi_imx_data *spi_imx = spi_master_get_devdata(spi->master);
struct spi_imx_config config;
int ret;
config.bpw = t ? t->bits_per_word : spi->bits_per_word;
config.speed_hz = t ? t->speed_hz : spi->max_speed_hz;
if (!config.speed_hz)
config.speed_hz = spi->max_speed_hz;
if (!config.bpw)
config.bpw = spi->bits_per_word;
if (config.bpw <= 8) {
spi_imx->rx = spi_imx_buf_rx_u8;
spi_imx->tx = spi_imx_buf_tx_u8;
} else if (config.bpw <= 16) {
spi_imx->rx = spi_imx_buf_rx_u16;
spi_imx->tx = spi_imx_buf_tx_u16;
} else {
spi_imx->rx = spi_imx_buf_rx_u32;
spi_imx->tx = spi_imx_buf_tx_u32;
}
if (spi_imx_can_dma(spi_imx->bitbang.master, spi, t))
spi_imx->usedma = 1;
else
spi_imx->usedma = 0;
if (spi_imx->usedma) {
ret = spi_imx_dma_configure(spi->master,
spi_imx_bytes_per_word(config.bpw));
if (ret)
return ret;
}
spi_imx->devtype_data->config(spi, &config);
return 0;
}
static void spi_imx_sdma_exit(struct spi_imx_data *spi_imx)
{
struct spi_master *master = spi_imx->bitbang.master;
if (master->dma_rx) {
dma_release_channel(master->dma_rx);
master->dma_rx = NULL;
}
if (master->dma_tx) {
dma_release_channel(master->dma_tx);
master->dma_tx = NULL;
}
}
static int spi_imx_sdma_init(struct device *dev, struct spi_imx_data *spi_imx,
struct spi_master *master)
{
int ret;
if (of_machine_is_compatible("fsl,imx6dl"))
return 0;
spi_imx->wml = spi_imx_get_fifosize(spi_imx) / 2;
master->dma_tx = dma_request_slave_channel_reason(dev, "tx");
if (IS_ERR(master->dma_tx)) {
ret = PTR_ERR(master->dma_tx);
dev_dbg(dev, "can't get the TX DMA channel, error %d!\n", ret);
master->dma_tx = NULL;
goto err;
}
master->dma_rx = dma_request_slave_channel_reason(dev, "rx");
if (IS_ERR(master->dma_rx)) {
ret = PTR_ERR(master->dma_rx);
dev_dbg(dev, "can't get the RX DMA channel, error %d\n", ret);
master->dma_rx = NULL;
goto err;
}
spi_imx_dma_configure(master, 1);
init_completion(&spi_imx->dma_rx_completion);
init_completion(&spi_imx->dma_tx_completion);
master->can_dma = spi_imx_can_dma;
master->max_dma_len = MAX_SDMA_BD_BYTES;
spi_imx->bitbang.master->flags = SPI_MASTER_MUST_RX |
SPI_MASTER_MUST_TX;
return 0;
err:
spi_imx_sdma_exit(spi_imx);
return ret;
}
static void spi_imx_dma_rx_callback(void *cookie)
{
struct spi_imx_data *spi_imx = (struct spi_imx_data *)cookie;
complete(&spi_imx->dma_rx_completion);
}
static void spi_imx_dma_tx_callback(void *cookie)
{
struct spi_imx_data *spi_imx = (struct spi_imx_data *)cookie;
complete(&spi_imx->dma_tx_completion);
}
static int spi_imx_calculate_timeout(struct spi_imx_data *spi_imx, int size)
{
unsigned long timeout = 0;
timeout = (8 + 4) * size / spi_imx->spi_bus_clk;
timeout += 1;
return msecs_to_jiffies(2 * timeout * MSEC_PER_SEC);
}
static int spi_imx_dma_transfer(struct spi_imx_data *spi_imx,
struct spi_transfer *transfer)
{
struct dma_async_tx_descriptor *desc_tx, *desc_rx;
unsigned long transfer_timeout;
unsigned long timeout;
struct spi_master *master = spi_imx->bitbang.master;
struct sg_table *tx = &transfer->tx_sg, *rx = &transfer->rx_sg;
desc_rx = dmaengine_prep_slave_sg(master->dma_rx,
rx->sgl, rx->nents, DMA_DEV_TO_MEM,
DMA_PREP_INTERRUPT | DMA_CTRL_ACK);
if (!desc_rx)
return -EINVAL;
desc_rx->callback = spi_imx_dma_rx_callback;
desc_rx->callback_param = (void *)spi_imx;
dmaengine_submit(desc_rx);
reinit_completion(&spi_imx->dma_rx_completion);
dma_async_issue_pending(master->dma_rx);
desc_tx = dmaengine_prep_slave_sg(master->dma_tx,
tx->sgl, tx->nents, DMA_MEM_TO_DEV,
DMA_PREP_INTERRUPT | DMA_CTRL_ACK);
if (!desc_tx) {
dmaengine_terminate_all(master->dma_tx);
return -EINVAL;
}
desc_tx->callback = spi_imx_dma_tx_callback;
desc_tx->callback_param = (void *)spi_imx;
dmaengine_submit(desc_tx);
reinit_completion(&spi_imx->dma_tx_completion);
dma_async_issue_pending(master->dma_tx);
transfer_timeout = spi_imx_calculate_timeout(spi_imx, transfer->len);
timeout = wait_for_completion_timeout(&spi_imx->dma_tx_completion,
transfer_timeout);
if (!timeout) {
dev_err(spi_imx->dev, "I/O Error in DMA TX\n");
dmaengine_terminate_all(master->dma_tx);
dmaengine_terminate_all(master->dma_rx);
return -ETIMEDOUT;
}
timeout = wait_for_completion_timeout(&spi_imx->dma_rx_completion,
transfer_timeout);
if (!timeout) {
dev_err(&master->dev, "I/O Error in DMA RX\n");
spi_imx->devtype_data->reset(spi_imx);
dmaengine_terminate_all(master->dma_rx);
return -ETIMEDOUT;
}
return transfer->len;
}
static int spi_imx_pio_transfer(struct spi_device *spi,
struct spi_transfer *transfer)
{
struct spi_imx_data *spi_imx = spi_master_get_devdata(spi->master);
unsigned long transfer_timeout;
unsigned long timeout;
spi_imx->tx_buf = transfer->tx_buf;
spi_imx->rx_buf = transfer->rx_buf;
spi_imx->count = transfer->len;
spi_imx->txfifo = 0;
reinit_completion(&spi_imx->xfer_done);
spi_imx_push(spi_imx);
spi_imx->devtype_data->intctrl(spi_imx, MXC_INT_TE);
transfer_timeout = spi_imx_calculate_timeout(spi_imx, transfer->len);
timeout = wait_for_completion_timeout(&spi_imx->xfer_done,
transfer_timeout);
if (!timeout) {
dev_err(&spi->dev, "I/O Error in PIO\n");
spi_imx->devtype_data->reset(spi_imx);
return -ETIMEDOUT;
}
return transfer->len;
}
static int spi_imx_transfer(struct spi_device *spi,
struct spi_transfer *transfer)
{
struct spi_imx_data *spi_imx = spi_master_get_devdata(spi->master);
if (spi_imx->usedma)
return spi_imx_dma_transfer(spi_imx, transfer);
else
return spi_imx_pio_transfer(spi, transfer);
}
static int spi_imx_setup(struct spi_device *spi)
{
dev_dbg(&spi->dev, "%s: mode %d, %u bpw, %d hz\n", __func__,
spi->mode, spi->bits_per_word, spi->max_speed_hz);
if (gpio_is_valid(spi->cs_gpio))
gpio_direction_output(spi->cs_gpio,
spi->mode & SPI_CS_HIGH ? 0 : 1);
spi_imx_chipselect(spi, BITBANG_CS_INACTIVE);
return 0;
}
static void spi_imx_cleanup(struct spi_device *spi)
{
}
static int
spi_imx_prepare_message(struct spi_master *master, struct spi_message *msg)
{
struct spi_imx_data *spi_imx = spi_master_get_devdata(master);
int ret;
ret = clk_enable(spi_imx->clk_per);
if (ret)
return ret;
ret = clk_enable(spi_imx->clk_ipg);
if (ret) {
clk_disable(spi_imx->clk_per);
return ret;
}
return 0;
}
static int
spi_imx_unprepare_message(struct spi_master *master, struct spi_message *msg)
{
struct spi_imx_data *spi_imx = spi_master_get_devdata(master);
clk_disable(spi_imx->clk_ipg);
clk_disable(spi_imx->clk_per);
return 0;
}
static int spi_imx_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
const struct of_device_id *of_id =
of_match_device(spi_imx_dt_ids, &pdev->dev);
struct spi_imx_master *mxc_platform_info =
dev_get_platdata(&pdev->dev);
struct spi_master *master;
struct spi_imx_data *spi_imx;
struct resource *res;
int i, ret, irq;
if (!np && !mxc_platform_info) {
dev_err(&pdev->dev, "can't get the platform data\n");
return -EINVAL;
}
master = spi_alloc_master(&pdev->dev, sizeof(struct spi_imx_data));
if (!master)
return -ENOMEM;
platform_set_drvdata(pdev, master);
master->bits_per_word_mask = SPI_BPW_RANGE_MASK(1, 32);
master->bus_num = np ? -1 : pdev->id;
spi_imx = spi_master_get_devdata(master);
spi_imx->bitbang.master = master;
spi_imx->dev = &pdev->dev;
spi_imx->devtype_data = of_id ? of_id->data :
(struct spi_imx_devtype_data *)pdev->id_entry->driver_data;
if (mxc_platform_info) {
master->num_chipselect = mxc_platform_info->num_chipselect;
master->cs_gpios = devm_kzalloc(&master->dev,
sizeof(int) * master->num_chipselect, GFP_KERNEL);
if (!master->cs_gpios)
return -ENOMEM;
for (i = 0; i < master->num_chipselect; i++)
master->cs_gpios[i] = mxc_platform_info->chipselect[i];
}
spi_imx->bitbang.chipselect = spi_imx_chipselect;
spi_imx->bitbang.setup_transfer = spi_imx_setupxfer;
spi_imx->bitbang.txrx_bufs = spi_imx_transfer;
spi_imx->bitbang.master->setup = spi_imx_setup;
spi_imx->bitbang.master->cleanup = spi_imx_cleanup;
spi_imx->bitbang.master->prepare_message = spi_imx_prepare_message;
spi_imx->bitbang.master->unprepare_message = spi_imx_unprepare_message;
spi_imx->bitbang.master->mode_bits = SPI_CPOL | SPI_CPHA | SPI_CS_HIGH;
if (is_imx35_cspi(spi_imx) || is_imx51_ecspi(spi_imx))
spi_imx->bitbang.master->mode_bits |= SPI_LOOP;
init_completion(&spi_imx->xfer_done);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
spi_imx->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(spi_imx->base)) {
ret = PTR_ERR(spi_imx->base);
goto out_master_put;
}
spi_imx->base_phys = res->start;
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
ret = irq;
goto out_master_put;
}
ret = devm_request_irq(&pdev->dev, irq, spi_imx_isr, 0,
dev_name(&pdev->dev), spi_imx);
if (ret) {
dev_err(&pdev->dev, "can't get irq%d: %d\n", irq, ret);
goto out_master_put;
}
spi_imx->clk_ipg = devm_clk_get(&pdev->dev, "ipg");
if (IS_ERR(spi_imx->clk_ipg)) {
ret = PTR_ERR(spi_imx->clk_ipg);
goto out_master_put;
}
spi_imx->clk_per = devm_clk_get(&pdev->dev, "per");
if (IS_ERR(spi_imx->clk_per)) {
ret = PTR_ERR(spi_imx->clk_per);
goto out_master_put;
}
ret = clk_prepare_enable(spi_imx->clk_per);
if (ret)
goto out_master_put;
ret = clk_prepare_enable(spi_imx->clk_ipg);
if (ret)
goto out_put_per;
spi_imx->spi_clk = clk_get_rate(spi_imx->clk_per);
if (is_imx51_ecspi(spi_imx)) {
ret = spi_imx_sdma_init(&pdev->dev, spi_imx, master);
if (ret == -EPROBE_DEFER)
goto out_clk_put;
if (ret < 0)
dev_err(&pdev->dev, "dma setup error %d, use pio\n",
ret);
}
spi_imx->devtype_data->reset(spi_imx);
spi_imx->devtype_data->intctrl(spi_imx, 0);
master->dev.of_node = pdev->dev.of_node;
ret = spi_bitbang_start(&spi_imx->bitbang);
if (ret) {
dev_err(&pdev->dev, "bitbang start failed with %d\n", ret);
goto out_clk_put;
}
if (!master->cs_gpios) {
dev_err(&pdev->dev, "No CS GPIOs available\n");
ret = -EINVAL;
goto out_clk_put;
}
for (i = 0; i < master->num_chipselect; i++) {
if (!gpio_is_valid(master->cs_gpios[i]))
continue;
ret = devm_gpio_request(&pdev->dev, master->cs_gpios[i],
DRIVER_NAME);
if (ret) {
dev_err(&pdev->dev, "Can't get CS GPIO %i\n",
master->cs_gpios[i]);
goto out_clk_put;
}
}
dev_info(&pdev->dev, "probed\n");
clk_disable(spi_imx->clk_ipg);
clk_disable(spi_imx->clk_per);
return ret;
out_clk_put:
clk_disable_unprepare(spi_imx->clk_ipg);
out_put_per:
clk_disable_unprepare(spi_imx->clk_per);
out_master_put:
spi_master_put(master);
return ret;
}
static int spi_imx_remove(struct platform_device *pdev)
{
struct spi_master *master = platform_get_drvdata(pdev);
struct spi_imx_data *spi_imx = spi_master_get_devdata(master);
spi_bitbang_stop(&spi_imx->bitbang);
writel(0, spi_imx->base + MXC_CSPICTRL);
clk_unprepare(spi_imx->clk_ipg);
clk_unprepare(spi_imx->clk_per);
spi_imx_sdma_exit(spi_imx);
spi_master_put(master);
return 0;
}
