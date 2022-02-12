static void flush_fifo(struct s3c64xx_spi_driver_data *sdd)
{
struct s3c64xx_spi_info *sci = sdd->cntrlr_info;
void __iomem *regs = sdd->regs;
unsigned long loops;
u32 val;
writel(0, regs + S3C64XX_SPI_PACKET_CNT);
val = readl(regs + S3C64XX_SPI_CH_CFG);
val |= S3C64XX_SPI_CH_SW_RST;
val &= ~S3C64XX_SPI_CH_HS_EN;
writel(val, regs + S3C64XX_SPI_CH_CFG);
loops = msecs_to_loops(1);
do {
val = readl(regs + S3C64XX_SPI_STATUS);
} while (TX_FIFO_LVL(val, sci) && loops--);
if (loops == 0)
dev_warn(&sdd->pdev->dev, "Timed out flushing TX FIFO\n");
loops = msecs_to_loops(1);
do {
val = readl(regs + S3C64XX_SPI_STATUS);
if (RX_FIFO_LVL(val, sci))
readl(regs + S3C64XX_SPI_RX_DATA);
else
break;
} while (loops--);
if (loops == 0)
dev_warn(&sdd->pdev->dev, "Timed out flushing RX FIFO\n");
val = readl(regs + S3C64XX_SPI_CH_CFG);
val &= ~S3C64XX_SPI_CH_SW_RST;
writel(val, regs + S3C64XX_SPI_CH_CFG);
val = readl(regs + S3C64XX_SPI_MODE_CFG);
val &= ~(S3C64XX_SPI_MODE_TXDMA_ON | S3C64XX_SPI_MODE_RXDMA_ON);
writel(val, regs + S3C64XX_SPI_MODE_CFG);
val = readl(regs + S3C64XX_SPI_CH_CFG);
val &= ~(S3C64XX_SPI_CH_RXCH_ON | S3C64XX_SPI_CH_TXCH_ON);
writel(val, regs + S3C64XX_SPI_CH_CFG);
}
static void s3c64xx_spi_dmacb(void *data)
{
struct s3c64xx_spi_driver_data *sdd;
struct s3c64xx_spi_dma_data *dma = data;
unsigned long flags;
if (dma->direction == DMA_FROM_DEVICE)
sdd = container_of(data,
struct s3c64xx_spi_driver_data, rx_dma);
else
sdd = container_of(data,
struct s3c64xx_spi_driver_data, tx_dma);
spin_lock_irqsave(&sdd->lock, flags);
if (dma->direction == DMA_FROM_DEVICE) {
sdd->state &= ~RXBUSY;
if (!(sdd->state & TXBUSY))
complete(&sdd->xfer_completion);
} else {
sdd->state &= ~TXBUSY;
if (!(sdd->state & RXBUSY))
complete(&sdd->xfer_completion);
}
spin_unlock_irqrestore(&sdd->lock, flags);
}
static void prepare_dma(struct s3c64xx_spi_dma_data *dma,
unsigned len, dma_addr_t buf)
{
struct s3c64xx_spi_driver_data *sdd;
struct samsung_dma_prep_info info;
if (dma->direction == DMA_FROM_DEVICE)
sdd = container_of((void *)dma,
struct s3c64xx_spi_driver_data, rx_dma);
else
sdd = container_of((void *)dma,
struct s3c64xx_spi_driver_data, tx_dma);
info.cap = DMA_SLAVE;
info.len = len;
info.fp = s3c64xx_spi_dmacb;
info.fp_param = dma;
info.direction = dma->direction;
info.buf = buf;
sdd->ops->prepare(dma->ch, &info);
sdd->ops->trigger(dma->ch);
}
static int acquire_dma(struct s3c64xx_spi_driver_data *sdd)
{
struct samsung_dma_info info;
sdd->ops = samsung_dma_get_ops();
info.cap = DMA_SLAVE;
info.client = &s3c64xx_spi_dma_client;
info.width = sdd->cur_bpw / 8;
info.direction = sdd->rx_dma.direction;
info.fifo = sdd->sfr_start + S3C64XX_SPI_RX_DATA;
sdd->rx_dma.ch = sdd->ops->request(sdd->rx_dma.dmach, &info);
info.direction = sdd->tx_dma.direction;
info.fifo = sdd->sfr_start + S3C64XX_SPI_TX_DATA;
sdd->tx_dma.ch = sdd->ops->request(sdd->tx_dma.dmach, &info);
return 1;
}
static void enable_datapath(struct s3c64xx_spi_driver_data *sdd,
struct spi_device *spi,
struct spi_transfer *xfer, int dma_mode)
{
struct s3c64xx_spi_info *sci = sdd->cntrlr_info;
void __iomem *regs = sdd->regs;
u32 modecfg, chcfg;
modecfg = readl(regs + S3C64XX_SPI_MODE_CFG);
modecfg &= ~(S3C64XX_SPI_MODE_TXDMA_ON | S3C64XX_SPI_MODE_RXDMA_ON);
chcfg = readl(regs + S3C64XX_SPI_CH_CFG);
chcfg &= ~S3C64XX_SPI_CH_TXCH_ON;
if (dma_mode) {
chcfg &= ~S3C64XX_SPI_CH_RXCH_ON;
} else {
chcfg |= S3C64XX_SPI_CH_RXCH_ON;
writel(((xfer->len * 8 / sdd->cur_bpw) & 0xffff)
| S3C64XX_SPI_PACKET_CNT_EN,
regs + S3C64XX_SPI_PACKET_CNT);
}
if (xfer->tx_buf != NULL) {
sdd->state |= TXBUSY;
chcfg |= S3C64XX_SPI_CH_TXCH_ON;
if (dma_mode) {
modecfg |= S3C64XX_SPI_MODE_TXDMA_ON;
prepare_dma(&sdd->tx_dma, xfer->len, xfer->tx_dma);
} else {
switch (sdd->cur_bpw) {
case 32:
iowrite32_rep(regs + S3C64XX_SPI_TX_DATA,
xfer->tx_buf, xfer->len / 4);
break;
case 16:
iowrite16_rep(regs + S3C64XX_SPI_TX_DATA,
xfer->tx_buf, xfer->len / 2);
break;
default:
iowrite8_rep(regs + S3C64XX_SPI_TX_DATA,
xfer->tx_buf, xfer->len);
break;
}
}
}
if (xfer->rx_buf != NULL) {
sdd->state |= RXBUSY;
if (sci->high_speed && sdd->cur_speed >= 30000000UL
&& !(sdd->cur_mode & SPI_CPHA))
chcfg |= S3C64XX_SPI_CH_HS_EN;
if (dma_mode) {
modecfg |= S3C64XX_SPI_MODE_RXDMA_ON;
chcfg |= S3C64XX_SPI_CH_RXCH_ON;
writel(((xfer->len * 8 / sdd->cur_bpw) & 0xffff)
| S3C64XX_SPI_PACKET_CNT_EN,
regs + S3C64XX_SPI_PACKET_CNT);
prepare_dma(&sdd->rx_dma, xfer->len, xfer->rx_dma);
}
}
writel(modecfg, regs + S3C64XX_SPI_MODE_CFG);
writel(chcfg, regs + S3C64XX_SPI_CH_CFG);
}
static inline void enable_cs(struct s3c64xx_spi_driver_data *sdd,
struct spi_device *spi)
{
struct s3c64xx_spi_csinfo *cs;
if (sdd->tgl_spi != NULL) {
if (sdd->tgl_spi != spi) {
cs = sdd->tgl_spi->controller_data;
cs->set_level(cs->line,
spi->mode & SPI_CS_HIGH ? 0 : 1);
}
sdd->tgl_spi = NULL;
}
cs = spi->controller_data;
cs->set_level(cs->line, spi->mode & SPI_CS_HIGH ? 1 : 0);
}
static int wait_for_xfer(struct s3c64xx_spi_driver_data *sdd,
struct spi_transfer *xfer, int dma_mode)
{
struct s3c64xx_spi_info *sci = sdd->cntrlr_info;
void __iomem *regs = sdd->regs;
unsigned long val;
int ms;
ms = xfer->len * 8 * 1000 / sdd->cur_speed;
ms += 10;
if (dma_mode) {
val = msecs_to_jiffies(ms) + 10;
val = wait_for_completion_timeout(&sdd->xfer_completion, val);
} else {
u32 status;
val = msecs_to_loops(ms);
do {
status = readl(regs + S3C64XX_SPI_STATUS);
} while (RX_FIFO_LVL(status, sci) < xfer->len && --val);
}
if (!val)
return -EIO;
if (dma_mode) {
u32 status;
if (xfer->rx_buf == NULL) {
val = msecs_to_loops(10);
status = readl(regs + S3C64XX_SPI_STATUS);
while ((TX_FIFO_LVL(status, sci)
|| !S3C64XX_SPI_ST_TX_DONE(status, sci))
&& --val) {
cpu_relax();
status = readl(regs + S3C64XX_SPI_STATUS);
}
if (!val)
return -EIO;
}
} else {
if (xfer->rx_buf == NULL) {
sdd->state &= ~TXBUSY;
return 0;
}
switch (sdd->cur_bpw) {
case 32:
ioread32_rep(regs + S3C64XX_SPI_RX_DATA,
xfer->rx_buf, xfer->len / 4);
break;
case 16:
ioread16_rep(regs + S3C64XX_SPI_RX_DATA,
xfer->rx_buf, xfer->len / 2);
break;
default:
ioread8_rep(regs + S3C64XX_SPI_RX_DATA,
xfer->rx_buf, xfer->len);
break;
}
sdd->state &= ~RXBUSY;
}
return 0;
}
static inline void disable_cs(struct s3c64xx_spi_driver_data *sdd,
struct spi_device *spi)
{
struct s3c64xx_spi_csinfo *cs = spi->controller_data;
if (sdd->tgl_spi == spi)
sdd->tgl_spi = NULL;
cs->set_level(cs->line, spi->mode & SPI_CS_HIGH ? 0 : 1);
}
static void s3c64xx_spi_config(struct s3c64xx_spi_driver_data *sdd)
{
struct s3c64xx_spi_info *sci = sdd->cntrlr_info;
void __iomem *regs = sdd->regs;
u32 val;
if (sci->clk_from_cmu) {
clk_disable(sdd->src_clk);
} else {
val = readl(regs + S3C64XX_SPI_CLK_CFG);
val &= ~S3C64XX_SPI_ENCLK_ENABLE;
writel(val, regs + S3C64XX_SPI_CLK_CFG);
}
val = readl(regs + S3C64XX_SPI_CH_CFG);
val &= ~(S3C64XX_SPI_CH_SLAVE |
S3C64XX_SPI_CPOL_L |
S3C64XX_SPI_CPHA_B);
if (sdd->cur_mode & SPI_CPOL)
val |= S3C64XX_SPI_CPOL_L;
if (sdd->cur_mode & SPI_CPHA)
val |= S3C64XX_SPI_CPHA_B;
writel(val, regs + S3C64XX_SPI_CH_CFG);
val = readl(regs + S3C64XX_SPI_MODE_CFG);
val &= ~(S3C64XX_SPI_MODE_BUS_TSZ_MASK
| S3C64XX_SPI_MODE_CH_TSZ_MASK);
switch (sdd->cur_bpw) {
case 32:
val |= S3C64XX_SPI_MODE_BUS_TSZ_WORD;
val |= S3C64XX_SPI_MODE_CH_TSZ_WORD;
break;
case 16:
val |= S3C64XX_SPI_MODE_BUS_TSZ_HALFWORD;
val |= S3C64XX_SPI_MODE_CH_TSZ_HALFWORD;
break;
default:
val |= S3C64XX_SPI_MODE_BUS_TSZ_BYTE;
val |= S3C64XX_SPI_MODE_CH_TSZ_BYTE;
break;
}
writel(val, regs + S3C64XX_SPI_MODE_CFG);
if (sci->clk_from_cmu) {
clk_set_rate(sdd->src_clk, sdd->cur_speed * 2);
clk_enable(sdd->src_clk);
} else {
val = readl(regs + S3C64XX_SPI_CLK_CFG);
val &= ~S3C64XX_SPI_PSR_MASK;
val |= ((clk_get_rate(sdd->src_clk) / sdd->cur_speed / 2 - 1)
& S3C64XX_SPI_PSR_MASK);
writel(val, regs + S3C64XX_SPI_CLK_CFG);
val = readl(regs + S3C64XX_SPI_CLK_CFG);
val |= S3C64XX_SPI_ENCLK_ENABLE;
writel(val, regs + S3C64XX_SPI_CLK_CFG);
}
}
static int s3c64xx_spi_map_mssg(struct s3c64xx_spi_driver_data *sdd,
struct spi_message *msg)
{
struct s3c64xx_spi_info *sci = sdd->cntrlr_info;
struct device *dev = &sdd->pdev->dev;
struct spi_transfer *xfer;
if (msg->is_dma_mapped)
return 0;
list_for_each_entry(xfer, &msg->transfers, transfer_list) {
xfer->rx_dma = XFER_DMAADDR_INVALID;
xfer->tx_dma = XFER_DMAADDR_INVALID;
}
list_for_each_entry(xfer, &msg->transfers, transfer_list) {
if (xfer->len <= ((sci->fifo_lvl_mask >> 1) + 1))
continue;
if (xfer->tx_buf != NULL) {
xfer->tx_dma = dma_map_single(dev,
(void *)xfer->tx_buf, xfer->len,
DMA_TO_DEVICE);
if (dma_mapping_error(dev, xfer->tx_dma)) {
dev_err(dev, "dma_map_single Tx failed\n");
xfer->tx_dma = XFER_DMAADDR_INVALID;
return -ENOMEM;
}
}
if (xfer->rx_buf != NULL) {
xfer->rx_dma = dma_map_single(dev, xfer->rx_buf,
xfer->len, DMA_FROM_DEVICE);
if (dma_mapping_error(dev, xfer->rx_dma)) {
dev_err(dev, "dma_map_single Rx failed\n");
dma_unmap_single(dev, xfer->tx_dma,
xfer->len, DMA_TO_DEVICE);
xfer->tx_dma = XFER_DMAADDR_INVALID;
xfer->rx_dma = XFER_DMAADDR_INVALID;
return -ENOMEM;
}
}
}
return 0;
}
static void s3c64xx_spi_unmap_mssg(struct s3c64xx_spi_driver_data *sdd,
struct spi_message *msg)
{
struct s3c64xx_spi_info *sci = sdd->cntrlr_info;
struct device *dev = &sdd->pdev->dev;
struct spi_transfer *xfer;
if (msg->is_dma_mapped)
return;
list_for_each_entry(xfer, &msg->transfers, transfer_list) {
if (xfer->len <= ((sci->fifo_lvl_mask >> 1) + 1))
continue;
if (xfer->rx_buf != NULL
&& xfer->rx_dma != XFER_DMAADDR_INVALID)
dma_unmap_single(dev, xfer->rx_dma,
xfer->len, DMA_FROM_DEVICE);
if (xfer->tx_buf != NULL
&& xfer->tx_dma != XFER_DMAADDR_INVALID)
dma_unmap_single(dev, xfer->tx_dma,
xfer->len, DMA_TO_DEVICE);
}
}
static void handle_msg(struct s3c64xx_spi_driver_data *sdd,
struct spi_message *msg)
{
struct s3c64xx_spi_info *sci = sdd->cntrlr_info;
struct spi_device *spi = msg->spi;
struct s3c64xx_spi_csinfo *cs = spi->controller_data;
struct spi_transfer *xfer;
int status = 0, cs_toggle = 0;
u32 speed;
u8 bpw;
if (sdd->cur_speed != spi->max_speed_hz
|| sdd->cur_mode != spi->mode
|| sdd->cur_bpw != spi->bits_per_word) {
sdd->cur_bpw = spi->bits_per_word;
sdd->cur_speed = spi->max_speed_hz;
sdd->cur_mode = spi->mode;
s3c64xx_spi_config(sdd);
}
if (s3c64xx_spi_map_mssg(sdd, msg)) {
dev_err(&spi->dev,
"Xfer: Unable to map message buffers!\n");
status = -ENOMEM;
goto out;
}
writel(cs->fb_delay & 0x3, sdd->regs + S3C64XX_SPI_FB_CLK);
list_for_each_entry(xfer, &msg->transfers, transfer_list) {
unsigned long flags;
int use_dma;
INIT_COMPLETION(sdd->xfer_completion);
bpw = xfer->bits_per_word ? : spi->bits_per_word;
speed = xfer->speed_hz ? : spi->max_speed_hz;
if (xfer->len % (bpw / 8)) {
dev_err(&spi->dev,
"Xfer length(%u) not a multiple of word size(%u)\n",
xfer->len, bpw / 8);
status = -EIO;
goto out;
}
if (bpw != sdd->cur_bpw || speed != sdd->cur_speed) {
sdd->cur_bpw = bpw;
sdd->cur_speed = speed;
s3c64xx_spi_config(sdd);
}
if (xfer->len <= ((sci->fifo_lvl_mask >> 1) + 1))
use_dma = 0;
else
use_dma = 1;
spin_lock_irqsave(&sdd->lock, flags);
sdd->state &= ~RXBUSY;
sdd->state &= ~TXBUSY;
enable_datapath(sdd, spi, xfer, use_dma);
enable_cs(sdd, spi);
S3C64XX_SPI_ACT(sdd);
spin_unlock_irqrestore(&sdd->lock, flags);
status = wait_for_xfer(sdd, xfer, use_dma);
S3C64XX_SPI_DEACT(sdd);
if (status) {
dev_err(&spi->dev, "I/O Error: "
"rx-%d tx-%d res:rx-%c tx-%c len-%d\n",
xfer->rx_buf ? 1 : 0, xfer->tx_buf ? 1 : 0,
(sdd->state & RXBUSY) ? 'f' : 'p',
(sdd->state & TXBUSY) ? 'f' : 'p',
xfer->len);
if (use_dma) {
if (xfer->tx_buf != NULL
&& (sdd->state & TXBUSY))
sdd->ops->stop(sdd->tx_dma.ch);
if (xfer->rx_buf != NULL
&& (sdd->state & RXBUSY))
sdd->ops->stop(sdd->rx_dma.ch);
}
goto out;
}
if (xfer->delay_usecs)
udelay(xfer->delay_usecs);
if (xfer->cs_change) {
if (list_is_last(&xfer->transfer_list,
&msg->transfers))
cs_toggle = 1;
else
disable_cs(sdd, spi);
}
msg->actual_length += xfer->len;
flush_fifo(sdd);
}
out:
if (!cs_toggle || status)
disable_cs(sdd, spi);
else
sdd->tgl_spi = spi;
s3c64xx_spi_unmap_mssg(sdd, msg);
msg->status = status;
if (msg->complete)
msg->complete(msg->context);
}
static void s3c64xx_spi_work(struct work_struct *work)
{
struct s3c64xx_spi_driver_data *sdd = container_of(work,
struct s3c64xx_spi_driver_data, work);
unsigned long flags;
while (!acquire_dma(sdd))
msleep(10);
spin_lock_irqsave(&sdd->lock, flags);
while (!list_empty(&sdd->queue)
&& !(sdd->state & SUSPND)) {
struct spi_message *msg;
msg = container_of(sdd->queue.next, struct spi_message, queue);
list_del_init(&msg->queue);
sdd->state |= SPIBUSY;
spin_unlock_irqrestore(&sdd->lock, flags);
handle_msg(sdd, msg);
spin_lock_irqsave(&sdd->lock, flags);
sdd->state &= ~SPIBUSY;
}
spin_unlock_irqrestore(&sdd->lock, flags);
sdd->ops->release(sdd->rx_dma.ch, &s3c64xx_spi_dma_client);
sdd->ops->release(sdd->tx_dma.ch, &s3c64xx_spi_dma_client);
}
static int s3c64xx_spi_transfer(struct spi_device *spi,
struct spi_message *msg)
{
struct s3c64xx_spi_driver_data *sdd;
unsigned long flags;
sdd = spi_master_get_devdata(spi->master);
spin_lock_irqsave(&sdd->lock, flags);
if (sdd->state & SUSPND) {
spin_unlock_irqrestore(&sdd->lock, flags);
return -ESHUTDOWN;
}
msg->status = -EINPROGRESS;
msg->actual_length = 0;
list_add_tail(&msg->queue, &sdd->queue);
queue_work(sdd->workqueue, &sdd->work);
spin_unlock_irqrestore(&sdd->lock, flags);
return 0;
}
static int s3c64xx_spi_setup(struct spi_device *spi)
{
struct s3c64xx_spi_csinfo *cs = spi->controller_data;
struct s3c64xx_spi_driver_data *sdd;
struct s3c64xx_spi_info *sci;
struct spi_message *msg;
unsigned long flags;
int err = 0;
if (cs == NULL || cs->set_level == NULL) {
dev_err(&spi->dev, "No CS for SPI(%d)\n", spi->chip_select);
return -ENODEV;
}
sdd = spi_master_get_devdata(spi->master);
sci = sdd->cntrlr_info;
spin_lock_irqsave(&sdd->lock, flags);
list_for_each_entry(msg, &sdd->queue, queue) {
if (msg->spi == spi) {
dev_err(&spi->dev,
"setup: attempt while mssg in queue!\n");
spin_unlock_irqrestore(&sdd->lock, flags);
return -EBUSY;
}
}
if (sdd->state & SUSPND) {
spin_unlock_irqrestore(&sdd->lock, flags);
dev_err(&spi->dev,
"setup: SPI-%d not active!\n", spi->master->bus_num);
return -ESHUTDOWN;
}
spin_unlock_irqrestore(&sdd->lock, flags);
if (spi->bits_per_word != 8
&& spi->bits_per_word != 16
&& spi->bits_per_word != 32) {
dev_err(&spi->dev, "setup: %dbits/wrd not supported!\n",
spi->bits_per_word);
err = -EINVAL;
goto setup_exit;
}
if (!sci->clk_from_cmu) {
u32 psr, speed;
speed = clk_get_rate(sdd->src_clk) / 2 / (0 + 1);
if (spi->max_speed_hz > speed)
spi->max_speed_hz = speed;
psr = clk_get_rate(sdd->src_clk) / 2 / spi->max_speed_hz - 1;
psr &= S3C64XX_SPI_PSR_MASK;
if (psr == S3C64XX_SPI_PSR_MASK)
psr--;
speed = clk_get_rate(sdd->src_clk) / 2 / (psr + 1);
if (spi->max_speed_hz < speed) {
if (psr+1 < S3C64XX_SPI_PSR_MASK) {
psr++;
} else {
err = -EINVAL;
goto setup_exit;
}
}
speed = clk_get_rate(sdd->src_clk) / 2 / (psr + 1);
if (spi->max_speed_hz >= speed)
spi->max_speed_hz = speed;
else
err = -EINVAL;
}
setup_exit:
disable_cs(sdd, spi);
return err;
}
static void s3c64xx_spi_hwinit(struct s3c64xx_spi_driver_data *sdd, int channel)
{
struct s3c64xx_spi_info *sci = sdd->cntrlr_info;
void __iomem *regs = sdd->regs;
unsigned int val;
sdd->cur_speed = 0;
S3C64XX_SPI_DEACT(sdd);
writel(0, regs + S3C64XX_SPI_INT_EN);
if (!sci->clk_from_cmu)
writel(sci->src_clk_nr << S3C64XX_SPI_CLKSEL_SRCSHFT,
regs + S3C64XX_SPI_CLK_CFG);
writel(0, regs + S3C64XX_SPI_MODE_CFG);
writel(0, regs + S3C64XX_SPI_PACKET_CNT);
writel(readl(regs + S3C64XX_SPI_PENDING_CLR),
regs + S3C64XX_SPI_PENDING_CLR);
writel(0, regs + S3C64XX_SPI_SWAP_CFG);
val = readl(regs + S3C64XX_SPI_MODE_CFG);
val &= ~S3C64XX_SPI_MODE_4BURST;
val &= ~(S3C64XX_SPI_MAX_TRAILCNT << S3C64XX_SPI_TRAILCNT_OFF);
val |= (S3C64XX_SPI_TRAILCNT << S3C64XX_SPI_TRAILCNT_OFF);
writel(val, regs + S3C64XX_SPI_MODE_CFG);
flush_fifo(sdd);
}
static int __init s3c64xx_spi_probe(struct platform_device *pdev)
{
struct resource *mem_res, *dmatx_res, *dmarx_res;
struct s3c64xx_spi_driver_data *sdd;
struct s3c64xx_spi_info *sci;
struct spi_master *master;
int ret;
if (pdev->id < 0) {
dev_err(&pdev->dev,
"Invalid platform device id-%d\n", pdev->id);
return -ENODEV;
}
if (pdev->dev.platform_data == NULL) {
dev_err(&pdev->dev, "platform_data missing!\n");
return -ENODEV;
}
sci = pdev->dev.platform_data;
if (!sci->src_clk_name) {
dev_err(&pdev->dev,
"Board init must call s3c64xx_spi_set_info()\n");
return -EINVAL;
}
dmatx_res = platform_get_resource(pdev, IORESOURCE_DMA, 0);
if (dmatx_res == NULL) {
dev_err(&pdev->dev, "Unable to get SPI-Tx dma resource\n");
return -ENXIO;
}
dmarx_res = platform_get_resource(pdev, IORESOURCE_DMA, 1);
if (dmarx_res == NULL) {
dev_err(&pdev->dev, "Unable to get SPI-Rx dma resource\n");
return -ENXIO;
}
mem_res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (mem_res == NULL) {
dev_err(&pdev->dev, "Unable to get SPI MEM resource\n");
return -ENXIO;
}
master = spi_alloc_master(&pdev->dev,
sizeof(struct s3c64xx_spi_driver_data));
if (master == NULL) {
dev_err(&pdev->dev, "Unable to allocate SPI Master\n");
return -ENOMEM;
}
platform_set_drvdata(pdev, master);
sdd = spi_master_get_devdata(master);
sdd->master = master;
sdd->cntrlr_info = sci;
sdd->pdev = pdev;
sdd->sfr_start = mem_res->start;
sdd->tx_dma.dmach = dmatx_res->start;
sdd->tx_dma.direction = DMA_TO_DEVICE;
sdd->rx_dma.dmach = dmarx_res->start;
sdd->rx_dma.direction = DMA_FROM_DEVICE;
sdd->cur_bpw = 8;
master->bus_num = pdev->id;
master->setup = s3c64xx_spi_setup;
master->transfer = s3c64xx_spi_transfer;
master->num_chipselect = sci->num_cs;
master->dma_alignment = 8;
master->mode_bits = SPI_CPOL | SPI_CPHA | SPI_CS_HIGH;
if (request_mem_region(mem_res->start,
resource_size(mem_res), pdev->name) == NULL) {
dev_err(&pdev->dev, "Req mem region failed\n");
ret = -ENXIO;
goto err0;
}
sdd->regs = ioremap(mem_res->start, resource_size(mem_res));
if (sdd->regs == NULL) {
dev_err(&pdev->dev, "Unable to remap IO\n");
ret = -ENXIO;
goto err1;
}
if (sci->cfg_gpio == NULL || sci->cfg_gpio(pdev)) {
dev_err(&pdev->dev, "Unable to config gpio\n");
ret = -EBUSY;
goto err2;
}
sdd->clk = clk_get(&pdev->dev, "spi");
if (IS_ERR(sdd->clk)) {
dev_err(&pdev->dev, "Unable to acquire clock 'spi'\n");
ret = PTR_ERR(sdd->clk);
goto err3;
}
if (clk_enable(sdd->clk)) {
dev_err(&pdev->dev, "Couldn't enable clock 'spi'\n");
ret = -EBUSY;
goto err4;
}
sdd->src_clk = clk_get(&pdev->dev, sci->src_clk_name);
if (IS_ERR(sdd->src_clk)) {
dev_err(&pdev->dev,
"Unable to acquire clock '%s'\n", sci->src_clk_name);
ret = PTR_ERR(sdd->src_clk);
goto err5;
}
if (clk_enable(sdd->src_clk)) {
dev_err(&pdev->dev, "Couldn't enable clock '%s'\n",
sci->src_clk_name);
ret = -EBUSY;
goto err6;
}
sdd->workqueue = create_singlethread_workqueue(
dev_name(master->dev.parent));
if (sdd->workqueue == NULL) {
dev_err(&pdev->dev, "Unable to create workqueue\n");
ret = -ENOMEM;
goto err7;
}
s3c64xx_spi_hwinit(sdd, pdev->id);
spin_lock_init(&sdd->lock);
init_completion(&sdd->xfer_completion);
INIT_WORK(&sdd->work, s3c64xx_spi_work);
INIT_LIST_HEAD(&sdd->queue);
if (spi_register_master(master)) {
dev_err(&pdev->dev, "cannot register SPI master\n");
ret = -EBUSY;
goto err8;
}
dev_dbg(&pdev->dev, "Samsung SoC SPI Driver loaded for Bus SPI-%d "
"with %d Slaves attached\n",
pdev->id, master->num_chipselect);
dev_dbg(&pdev->dev, "\tIOmem=[0x%x-0x%x]\tDMA=[Rx-%d, Tx-%d]\n",
mem_res->end, mem_res->start,
sdd->rx_dma.dmach, sdd->tx_dma.dmach);
return 0;
err8:
destroy_workqueue(sdd->workqueue);
err7:
clk_disable(sdd->src_clk);
err6:
clk_put(sdd->src_clk);
err5:
clk_disable(sdd->clk);
err4:
clk_put(sdd->clk);
err3:
err2:
iounmap((void *) sdd->regs);
err1:
release_mem_region(mem_res->start, resource_size(mem_res));
err0:
platform_set_drvdata(pdev, NULL);
spi_master_put(master);
return ret;
}
static int s3c64xx_spi_remove(struct platform_device *pdev)
{
struct spi_master *master = spi_master_get(platform_get_drvdata(pdev));
struct s3c64xx_spi_driver_data *sdd = spi_master_get_devdata(master);
struct resource *mem_res;
unsigned long flags;
spin_lock_irqsave(&sdd->lock, flags);
sdd->state |= SUSPND;
spin_unlock_irqrestore(&sdd->lock, flags);
while (sdd->state & SPIBUSY)
msleep(10);
spi_unregister_master(master);
destroy_workqueue(sdd->workqueue);
clk_disable(sdd->src_clk);
clk_put(sdd->src_clk);
clk_disable(sdd->clk);
clk_put(sdd->clk);
iounmap((void *) sdd->regs);
mem_res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (mem_res != NULL)
release_mem_region(mem_res->start, resource_size(mem_res));
platform_set_drvdata(pdev, NULL);
spi_master_put(master);
return 0;
}
static int s3c64xx_spi_suspend(struct platform_device *pdev, pm_message_t state)
{
struct spi_master *master = spi_master_get(platform_get_drvdata(pdev));
struct s3c64xx_spi_driver_data *sdd = spi_master_get_devdata(master);
unsigned long flags;
spin_lock_irqsave(&sdd->lock, flags);
sdd->state |= SUSPND;
spin_unlock_irqrestore(&sdd->lock, flags);
while (sdd->state & SPIBUSY)
msleep(10);
clk_disable(sdd->src_clk);
clk_disable(sdd->clk);
sdd->cur_speed = 0;
return 0;
}
static int s3c64xx_spi_resume(struct platform_device *pdev)
{
struct spi_master *master = spi_master_get(platform_get_drvdata(pdev));
struct s3c64xx_spi_driver_data *sdd = spi_master_get_devdata(master);
struct s3c64xx_spi_info *sci = sdd->cntrlr_info;
unsigned long flags;
sci->cfg_gpio(pdev);
clk_enable(sdd->src_clk);
clk_enable(sdd->clk);
s3c64xx_spi_hwinit(sdd, pdev->id);
spin_lock_irqsave(&sdd->lock, flags);
sdd->state &= ~SUSPND;
spin_unlock_irqrestore(&sdd->lock, flags);
return 0;
}
static int __init s3c64xx_spi_init(void)
{
return platform_driver_probe(&s3c64xx_spi_driver, s3c64xx_spi_probe);
}
static void __exit s3c64xx_spi_exit(void)
{
platform_driver_unregister(&s3c64xx_spi_driver);
}
