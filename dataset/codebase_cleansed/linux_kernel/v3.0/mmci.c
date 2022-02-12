static void mmci_set_clkreg(struct mmci_host *host, unsigned int desired)
{
struct variant_data *variant = host->variant;
u32 clk = variant->clkreg;
if (desired) {
if (desired >= host->mclk) {
clk = MCI_CLK_BYPASS;
if (variant->st_clkdiv)
clk |= MCI_ST_UX500_NEG_EDGE;
host->cclk = host->mclk;
} else if (variant->st_clkdiv) {
clk = DIV_ROUND_UP(host->mclk, desired) - 2;
if (clk >= 256)
clk = 255;
host->cclk = host->mclk / (clk + 2);
} else {
clk = host->mclk / (2 * desired) - 1;
if (clk >= 256)
clk = 255;
host->cclk = host->mclk / (2 * (clk + 1));
}
clk |= variant->clkreg_enable;
clk |= MCI_CLK_ENABLE;
}
if (host->mmc->ios.bus_width == MMC_BUS_WIDTH_4)
clk |= MCI_4BIT_BUS;
if (host->mmc->ios.bus_width == MMC_BUS_WIDTH_8)
clk |= MCI_ST_8BIT_BUS;
writel(clk, host->base + MMCICLOCK);
}
static void
mmci_request_end(struct mmci_host *host, struct mmc_request *mrq)
{
writel(0, host->base + MMCICOMMAND);
BUG_ON(host->data);
host->mrq = NULL;
host->cmd = NULL;
spin_unlock(&host->lock);
mmc_request_done(host->mmc, mrq);
spin_lock(&host->lock);
}
static void mmci_set_mask1(struct mmci_host *host, unsigned int mask)
{
void __iomem *base = host->base;
if (host->singleirq) {
unsigned int mask0 = readl(base + MMCIMASK0);
mask0 &= ~MCI_IRQ1MASK;
mask0 |= mask;
writel(mask0, base + MMCIMASK0);
}
writel(mask, base + MMCIMASK1);
}
static void mmci_stop_data(struct mmci_host *host)
{
writel(0, host->base + MMCIDATACTRL);
mmci_set_mask1(host, 0);
host->data = NULL;
}
static void mmci_init_sg(struct mmci_host *host, struct mmc_data *data)
{
unsigned int flags = SG_MITER_ATOMIC;
if (data->flags & MMC_DATA_READ)
flags |= SG_MITER_TO_SG;
else
flags |= SG_MITER_FROM_SG;
sg_miter_start(&host->sg_miter, data->sg, data->sg_len, flags);
}
static void __devinit mmci_dma_setup(struct mmci_host *host)
{
struct mmci_platform_data *plat = host->plat;
const char *rxname, *txname;
dma_cap_mask_t mask;
if (!plat || !plat->dma_filter) {
dev_info(mmc_dev(host->mmc), "no DMA platform data\n");
return;
}
dma_cap_zero(mask);
dma_cap_set(DMA_SLAVE, mask);
if (plat->dma_rx_param) {
host->dma_rx_channel = dma_request_channel(mask,
plat->dma_filter,
plat->dma_rx_param);
if (!host->dma_rx_channel)
dev_err(mmc_dev(host->mmc), "no RX DMA channel\n");
}
if (plat->dma_tx_param) {
host->dma_tx_channel = dma_request_channel(mask,
plat->dma_filter,
plat->dma_tx_param);
if (!host->dma_tx_channel)
dev_warn(mmc_dev(host->mmc), "no TX DMA channel\n");
} else {
host->dma_tx_channel = host->dma_rx_channel;
}
if (host->dma_rx_channel)
rxname = dma_chan_name(host->dma_rx_channel);
else
rxname = "none";
if (host->dma_tx_channel)
txname = dma_chan_name(host->dma_tx_channel);
else
txname = "none";
dev_info(mmc_dev(host->mmc), "DMA channels RX %s, TX %s\n",
rxname, txname);
if (host->dma_tx_channel) {
struct device *dev = host->dma_tx_channel->device->dev;
unsigned int max_seg_size = dma_get_max_seg_size(dev);
if (max_seg_size < host->mmc->max_seg_size)
host->mmc->max_seg_size = max_seg_size;
}
if (host->dma_rx_channel) {
struct device *dev = host->dma_rx_channel->device->dev;
unsigned int max_seg_size = dma_get_max_seg_size(dev);
if (max_seg_size < host->mmc->max_seg_size)
host->mmc->max_seg_size = max_seg_size;
}
}
static inline void mmci_dma_release(struct mmci_host *host)
{
struct mmci_platform_data *plat = host->plat;
if (host->dma_rx_channel)
dma_release_channel(host->dma_rx_channel);
if (host->dma_tx_channel && plat->dma_tx_param)
dma_release_channel(host->dma_tx_channel);
host->dma_rx_channel = host->dma_tx_channel = NULL;
}
static void mmci_dma_unmap(struct mmci_host *host, struct mmc_data *data)
{
struct dma_chan *chan = host->dma_current;
enum dma_data_direction dir;
u32 status;
int i;
for (i = 0; ; i++) {
status = readl(host->base + MMCISTATUS);
if (!(status & MCI_RXDATAAVLBLMASK) || i >= 100)
break;
udelay(10);
}
if (status & MCI_RXDATAAVLBLMASK) {
dmaengine_terminate_all(chan);
if (!data->error)
data->error = -EIO;
}
if (data->flags & MMC_DATA_WRITE) {
dir = DMA_TO_DEVICE;
} else {
dir = DMA_FROM_DEVICE;
}
dma_unmap_sg(chan->device->dev, data->sg, data->sg_len, dir);
if (status & MCI_RXDATAAVLBLMASK) {
dev_err(mmc_dev(host->mmc), "buggy DMA detected. Taking evasive action.\n");
mmci_dma_release(host);
}
}
static void mmci_dma_data_error(struct mmci_host *host)
{
dev_err(mmc_dev(host->mmc), "error during DMA transfer!\n");
dmaengine_terminate_all(host->dma_current);
}
static int mmci_dma_start_data(struct mmci_host *host, unsigned int datactrl)
{
struct variant_data *variant = host->variant;
struct dma_slave_config conf = {
.src_addr = host->phybase + MMCIFIFO,
.dst_addr = host->phybase + MMCIFIFO,
.src_addr_width = DMA_SLAVE_BUSWIDTH_4_BYTES,
.dst_addr_width = DMA_SLAVE_BUSWIDTH_4_BYTES,
.src_maxburst = variant->fifohalfsize >> 2,
.dst_maxburst = variant->fifohalfsize >> 2,
};
struct mmc_data *data = host->data;
struct dma_chan *chan;
struct dma_device *device;
struct dma_async_tx_descriptor *desc;
int nr_sg;
host->dma_current = NULL;
if (data->flags & MMC_DATA_READ) {
conf.direction = DMA_FROM_DEVICE;
chan = host->dma_rx_channel;
} else {
conf.direction = DMA_TO_DEVICE;
chan = host->dma_tx_channel;
}
if (!chan)
return -EINVAL;
if (host->size <= variant->fifosize)
return -EINVAL;
device = chan->device;
nr_sg = dma_map_sg(device->dev, data->sg, data->sg_len, conf.direction);
if (nr_sg == 0)
return -EINVAL;
dmaengine_slave_config(chan, &conf);
desc = device->device_prep_slave_sg(chan, data->sg, nr_sg,
conf.direction, DMA_CTRL_ACK);
if (!desc)
goto unmap_exit;
host->dma_current = chan;
dev_vdbg(mmc_dev(host->mmc),
"Submit MMCI DMA job, sglen %d blksz %04x blks %04x flags %08x\n",
data->sg_len, data->blksz, data->blocks, data->flags);
dmaengine_submit(desc);
dma_async_issue_pending(chan);
datactrl |= MCI_DPSM_DMAENABLE;
writel(datactrl, host->base + MMCIDATACTRL);
writel(readl(host->base + MMCIMASK0) | MCI_DATAENDMASK,
host->base + MMCIMASK0);
return 0;
unmap_exit:
dmaengine_terminate_all(chan);
dma_unmap_sg(device->dev, data->sg, data->sg_len, conf.direction);
return -ENOMEM;
}
static inline void mmci_dma_setup(struct mmci_host *host)
{
}
static inline void mmci_dma_release(struct mmci_host *host)
{
}
static inline void mmci_dma_unmap(struct mmci_host *host, struct mmc_data *data)
{
}
static inline void mmci_dma_data_error(struct mmci_host *host)
{
}
static inline int mmci_dma_start_data(struct mmci_host *host, unsigned int datactrl)
{
return -ENOSYS;
}
static void mmci_start_data(struct mmci_host *host, struct mmc_data *data)
{
struct variant_data *variant = host->variant;
unsigned int datactrl, timeout, irqmask;
unsigned long long clks;
void __iomem *base;
int blksz_bits;
dev_dbg(mmc_dev(host->mmc), "blksz %04x blks %04x flags %08x\n",
data->blksz, data->blocks, data->flags);
host->data = data;
host->size = data->blksz * data->blocks;
data->bytes_xfered = 0;
clks = (unsigned long long)data->timeout_ns * host->cclk;
do_div(clks, 1000000000UL);
timeout = data->timeout_clks + (unsigned int)clks;
base = host->base;
writel(timeout, base + MMCIDATATIMER);
writel(host->size, base + MMCIDATALENGTH);
blksz_bits = ffs(data->blksz) - 1;
BUG_ON(1 << blksz_bits != data->blksz);
if (variant->blksz_datactrl16)
datactrl = MCI_DPSM_ENABLE | (data->blksz << 16);
else
datactrl = MCI_DPSM_ENABLE | blksz_bits << 4;
if (data->flags & MMC_DATA_READ)
datactrl |= MCI_DPSM_DIRECTION;
if (!mmci_dma_start_data(host, datactrl))
return;
mmci_init_sg(host, data);
if (data->flags & MMC_DATA_READ) {
irqmask = MCI_RXFIFOHALFFULLMASK;
if (host->size < variant->fifohalfsize)
irqmask |= MCI_RXDATAAVLBLMASK;
} else {
irqmask = MCI_TXFIFOHALFEMPTYMASK;
}
if (variant->sdio && host->mmc->card)
if (mmc_card_sdio(host->mmc->card))
datactrl |= MCI_ST_DPSM_SDIOEN;
writel(datactrl, base + MMCIDATACTRL);
writel(readl(base + MMCIMASK0) & ~MCI_DATAENDMASK, base + MMCIMASK0);
mmci_set_mask1(host, irqmask);
}
static void
mmci_start_command(struct mmci_host *host, struct mmc_command *cmd, u32 c)
{
void __iomem *base = host->base;
dev_dbg(mmc_dev(host->mmc), "op %02x arg %08x flags %08x\n",
cmd->opcode, cmd->arg, cmd->flags);
if (readl(base + MMCICOMMAND) & MCI_CPSM_ENABLE) {
writel(0, base + MMCICOMMAND);
udelay(1);
}
c |= cmd->opcode | MCI_CPSM_ENABLE;
if (cmd->flags & MMC_RSP_PRESENT) {
if (cmd->flags & MMC_RSP_136)
c |= MCI_CPSM_LONGRSP;
c |= MCI_CPSM_RESPONSE;
}
if (0)
c |= MCI_CPSM_INTERRUPT;
host->cmd = cmd;
writel(cmd->arg, base + MMCIARGUMENT);
writel(c, base + MMCICOMMAND);
}
static void
mmci_data_irq(struct mmci_host *host, struct mmc_data *data,
unsigned int status)
{
if (status & (MCI_DATACRCFAIL|MCI_DATATIMEOUT|MCI_TXUNDERRUN|MCI_RXOVERRUN)) {
u32 remain, success;
if (dma_inprogress(host))
mmci_dma_data_error(host);
remain = readl(host->base + MMCIDATACNT);
success = data->blksz * data->blocks - remain;
dev_dbg(mmc_dev(host->mmc), "MCI ERROR IRQ, status 0x%08x at 0x%08x\n",
status, success);
if (status & MCI_DATACRCFAIL) {
success -= 1;
data->error = -EILSEQ;
} else if (status & MCI_DATATIMEOUT) {
data->error = -ETIMEDOUT;
} else if (status & MCI_STARTBITERR) {
data->error = -ECOMM;
} else if (status & MCI_TXUNDERRUN) {
data->error = -EIO;
} else if (status & MCI_RXOVERRUN) {
if (success > host->variant->fifosize)
success -= host->variant->fifosize;
else
success = 0;
data->error = -EIO;
}
data->bytes_xfered = round_down(success, data->blksz);
}
if (status & MCI_DATABLOCKEND)
dev_err(mmc_dev(host->mmc), "stray MCI_DATABLOCKEND interrupt\n");
if (status & MCI_DATAEND || data->error) {
if (dma_inprogress(host))
mmci_dma_unmap(host, data);
mmci_stop_data(host);
if (!data->error)
data->bytes_xfered = data->blksz * data->blocks;
if (!data->stop) {
mmci_request_end(host, data->mrq);
} else {
mmci_start_command(host, data->stop, 0);
}
}
}
static void
mmci_cmd_irq(struct mmci_host *host, struct mmc_command *cmd,
unsigned int status)
{
void __iomem *base = host->base;
host->cmd = NULL;
if (status & MCI_CMDTIMEOUT) {
cmd->error = -ETIMEDOUT;
} else if (status & MCI_CMDCRCFAIL && cmd->flags & MMC_RSP_CRC) {
cmd->error = -EILSEQ;
} else {
cmd->resp[0] = readl(base + MMCIRESPONSE0);
cmd->resp[1] = readl(base + MMCIRESPONSE1);
cmd->resp[2] = readl(base + MMCIRESPONSE2);
cmd->resp[3] = readl(base + MMCIRESPONSE3);
}
if (!cmd->data || cmd->error) {
if (host->data)
mmci_stop_data(host);
mmci_request_end(host, cmd->mrq);
} else if (!(cmd->data->flags & MMC_DATA_READ)) {
mmci_start_data(host, cmd->data);
}
}
static int mmci_pio_read(struct mmci_host *host, char *buffer, unsigned int remain)
{
void __iomem *base = host->base;
char *ptr = buffer;
u32 status;
int host_remain = host->size;
do {
int count = host_remain - (readl(base + MMCIFIFOCNT) << 2);
if (count > remain)
count = remain;
if (count <= 0)
break;
readsl(base + MMCIFIFO, ptr, count >> 2);
ptr += count;
remain -= count;
host_remain -= count;
if (remain == 0)
break;
status = readl(base + MMCISTATUS);
} while (status & MCI_RXDATAAVLBL);
return ptr - buffer;
}
static int mmci_pio_write(struct mmci_host *host, char *buffer, unsigned int remain, u32 status)
{
struct variant_data *variant = host->variant;
void __iomem *base = host->base;
char *ptr = buffer;
do {
unsigned int count, maxcnt;
maxcnt = status & MCI_TXFIFOEMPTY ?
variant->fifosize : variant->fifohalfsize;
count = min(remain, maxcnt);
if (variant->sdio &&
mmc_card_sdio(host->mmc->card)) {
if (count < 8)
writel(readl(host->base + MMCICLOCK) &
~variant->clkreg_enable,
host->base + MMCICLOCK);
else
writel(readl(host->base + MMCICLOCK) |
variant->clkreg_enable,
host->base + MMCICLOCK);
}
writesl(base + MMCIFIFO, ptr, (count + 3) >> 2);
ptr += count;
remain -= count;
if (remain == 0)
break;
status = readl(base + MMCISTATUS);
} while (status & MCI_TXFIFOHALFEMPTY);
return ptr - buffer;
}
static irqreturn_t mmci_pio_irq(int irq, void *dev_id)
{
struct mmci_host *host = dev_id;
struct sg_mapping_iter *sg_miter = &host->sg_miter;
struct variant_data *variant = host->variant;
void __iomem *base = host->base;
unsigned long flags;
u32 status;
status = readl(base + MMCISTATUS);
dev_dbg(mmc_dev(host->mmc), "irq1 (pio) %08x\n", status);
local_irq_save(flags);
do {
unsigned int remain, len;
char *buffer;
if (!(status & (MCI_TXFIFOHALFEMPTY|MCI_RXDATAAVLBL)))
break;
if (!sg_miter_next(sg_miter))
break;
buffer = sg_miter->addr;
remain = sg_miter->length;
len = 0;
if (status & MCI_RXACTIVE)
len = mmci_pio_read(host, buffer, remain);
if (status & MCI_TXACTIVE)
len = mmci_pio_write(host, buffer, remain, status);
sg_miter->consumed = len;
host->size -= len;
remain -= len;
if (remain)
break;
status = readl(base + MMCISTATUS);
} while (1);
sg_miter_stop(sg_miter);
local_irq_restore(flags);
if (status & MCI_RXACTIVE && host->size < variant->fifohalfsize)
mmci_set_mask1(host, MCI_RXDATAAVLBLMASK);
if (host->size == 0) {
mmci_set_mask1(host, 0);
writel(readl(base + MMCIMASK0) | MCI_DATAENDMASK, base + MMCIMASK0);
}
return IRQ_HANDLED;
}
static irqreturn_t mmci_irq(int irq, void *dev_id)
{
struct mmci_host *host = dev_id;
u32 status;
int ret = 0;
spin_lock(&host->lock);
do {
struct mmc_command *cmd;
struct mmc_data *data;
status = readl(host->base + MMCISTATUS);
if (host->singleirq) {
if (status & readl(host->base + MMCIMASK1))
mmci_pio_irq(irq, dev_id);
status &= ~MCI_IRQ1MASK;
}
status &= readl(host->base + MMCIMASK0);
writel(status, host->base + MMCICLEAR);
dev_dbg(mmc_dev(host->mmc), "irq0 (data+cmd) %08x\n", status);
data = host->data;
if (status & (MCI_DATACRCFAIL|MCI_DATATIMEOUT|MCI_TXUNDERRUN|
MCI_RXOVERRUN|MCI_DATAEND|MCI_DATABLOCKEND) && data)
mmci_data_irq(host, data, status);
cmd = host->cmd;
if (status & (MCI_CMDCRCFAIL|MCI_CMDTIMEOUT|MCI_CMDSENT|MCI_CMDRESPEND) && cmd)
mmci_cmd_irq(host, cmd, status);
ret = 1;
} while (status);
spin_unlock(&host->lock);
return IRQ_RETVAL(ret);
}
static void mmci_request(struct mmc_host *mmc, struct mmc_request *mrq)
{
struct mmci_host *host = mmc_priv(mmc);
unsigned long flags;
WARN_ON(host->mrq != NULL);
if (mrq->data && !is_power_of_2(mrq->data->blksz)) {
dev_err(mmc_dev(mmc), "unsupported block size (%d bytes)\n",
mrq->data->blksz);
mrq->cmd->error = -EINVAL;
mmc_request_done(mmc, mrq);
return;
}
spin_lock_irqsave(&host->lock, flags);
host->mrq = mrq;
if (mrq->data && mrq->data->flags & MMC_DATA_READ)
mmci_start_data(host, mrq->data);
mmci_start_command(host, mrq->cmd, 0);
spin_unlock_irqrestore(&host->lock, flags);
}
static void mmci_set_ios(struct mmc_host *mmc, struct mmc_ios *ios)
{
struct mmci_host *host = mmc_priv(mmc);
u32 pwr = 0;
unsigned long flags;
int ret;
switch (ios->power_mode) {
case MMC_POWER_OFF:
if (host->vcc)
ret = mmc_regulator_set_ocr(mmc, host->vcc, 0);
break;
case MMC_POWER_UP:
if (host->vcc) {
ret = mmc_regulator_set_ocr(mmc, host->vcc, ios->vdd);
if (ret) {
dev_err(mmc_dev(mmc), "unable to set OCR\n");
return;
}
}
if (host->plat->vdd_handler)
pwr |= host->plat->vdd_handler(mmc_dev(mmc), ios->vdd,
ios->power_mode);
if (host->hw_designer != AMBA_VENDOR_ST) {
pwr |= MCI_PWR_UP;
break;
}
case MMC_POWER_ON:
pwr |= MCI_PWR_ON;
break;
}
if (ios->bus_mode == MMC_BUSMODE_OPENDRAIN) {
if (host->hw_designer != AMBA_VENDOR_ST)
pwr |= MCI_ROD;
else {
pwr |= MCI_OD;
}
}
spin_lock_irqsave(&host->lock, flags);
mmci_set_clkreg(host, ios->clock);
if (host->pwr != pwr) {
host->pwr = pwr;
writel(pwr, host->base + MMCIPOWER);
}
spin_unlock_irqrestore(&host->lock, flags);
}
static int mmci_get_ro(struct mmc_host *mmc)
{
struct mmci_host *host = mmc_priv(mmc);
if (host->gpio_wp == -ENOSYS)
return -ENOSYS;
return gpio_get_value_cansleep(host->gpio_wp);
}
static int mmci_get_cd(struct mmc_host *mmc)
{
struct mmci_host *host = mmc_priv(mmc);
struct mmci_platform_data *plat = host->plat;
unsigned int status;
if (host->gpio_cd == -ENOSYS) {
if (!plat->status)
return 1;
status = plat->status(mmc_dev(host->mmc));
} else
status = !!gpio_get_value_cansleep(host->gpio_cd)
^ plat->cd_invert;
return status;
}
static irqreturn_t mmci_cd_irq(int irq, void *dev_id)
{
struct mmci_host *host = dev_id;
mmc_detect_change(host->mmc, msecs_to_jiffies(500));
return IRQ_HANDLED;
}
static int __devinit mmci_probe(struct amba_device *dev,
const struct amba_id *id)
{
struct mmci_platform_data *plat = dev->dev.platform_data;
struct variant_data *variant = id->data;
struct mmci_host *host;
struct mmc_host *mmc;
int ret;
if (!plat) {
ret = -EINVAL;
goto out;
}
ret = amba_request_regions(dev, DRIVER_NAME);
if (ret)
goto out;
mmc = mmc_alloc_host(sizeof(struct mmci_host), &dev->dev);
if (!mmc) {
ret = -ENOMEM;
goto rel_regions;
}
host = mmc_priv(mmc);
host->mmc = mmc;
host->gpio_wp = -ENOSYS;
host->gpio_cd = -ENOSYS;
host->gpio_cd_irq = -1;
host->hw_designer = amba_manf(dev);
host->hw_revision = amba_rev(dev);
dev_dbg(mmc_dev(mmc), "designer ID = 0x%02x\n", host->hw_designer);
dev_dbg(mmc_dev(mmc), "revision = 0x%01x\n", host->hw_revision);
host->clk = clk_get(&dev->dev, NULL);
if (IS_ERR(host->clk)) {
ret = PTR_ERR(host->clk);
host->clk = NULL;
goto host_free;
}
ret = clk_enable(host->clk);
if (ret)
goto clk_free;
host->plat = plat;
host->variant = variant;
host->mclk = clk_get_rate(host->clk);
if (host->mclk > 100000000) {
ret = clk_set_rate(host->clk, 100000000);
if (ret < 0)
goto clk_disable;
host->mclk = clk_get_rate(host->clk);
dev_dbg(mmc_dev(mmc), "eventual mclk rate: %u Hz\n",
host->mclk);
}
host->phybase = dev->res.start;
host->base = ioremap(dev->res.start, resource_size(&dev->res));
if (!host->base) {
ret = -ENOMEM;
goto clk_disable;
}
mmc->ops = &mmci_ops;
mmc->f_min = (host->mclk + 511) / 512;
if (plat->f_max)
mmc->f_max = min(host->mclk, plat->f_max);
else
mmc->f_max = min(host->mclk, fmax);
dev_dbg(mmc_dev(mmc), "clocking block at %u Hz\n", mmc->f_max);
#ifdef CONFIG_REGULATOR
host->vcc = regulator_get(&dev->dev, "vmmc");
if (IS_ERR(host->vcc))
host->vcc = NULL;
else {
int mask = mmc_regulator_get_ocrmask(host->vcc);
if (mask < 0)
dev_err(&dev->dev, "error getting OCR mask (%d)\n",
mask);
else {
host->mmc->ocr_avail = (u32) mask;
if (plat->ocr_mask)
dev_warn(&dev->dev,
"Provided ocr_mask/setpower will not be used "
"(using regulator instead)\n");
}
}
#endif
if (host->vcc == NULL)
mmc->ocr_avail = plat->ocr_mask;
mmc->caps = plat->capabilities;
mmc->max_segs = NR_SG;
mmc->max_req_size = (1 << variant->datalength_bits) - 1;
mmc->max_seg_size = mmc->max_req_size;
mmc->max_blk_size = 2048;
mmc->max_blk_count = mmc->max_req_size;
spin_lock_init(&host->lock);
writel(0, host->base + MMCIMASK0);
writel(0, host->base + MMCIMASK1);
writel(0xfff, host->base + MMCICLEAR);
if (gpio_is_valid(plat->gpio_cd)) {
ret = gpio_request(plat->gpio_cd, DRIVER_NAME " (cd)");
if (ret == 0)
ret = gpio_direction_input(plat->gpio_cd);
if (ret == 0)
host->gpio_cd = plat->gpio_cd;
else if (ret != -ENOSYS)
goto err_gpio_cd;
ret = request_any_context_irq(gpio_to_irq(plat->gpio_cd),
mmci_cd_irq,
IRQF_TRIGGER_RISING | IRQF_TRIGGER_FALLING,
DRIVER_NAME " (cd)", host);
if (ret >= 0)
host->gpio_cd_irq = gpio_to_irq(plat->gpio_cd);
}
if (gpio_is_valid(plat->gpio_wp)) {
ret = gpio_request(plat->gpio_wp, DRIVER_NAME " (wp)");
if (ret == 0)
ret = gpio_direction_input(plat->gpio_wp);
if (ret == 0)
host->gpio_wp = plat->gpio_wp;
else if (ret != -ENOSYS)
goto err_gpio_wp;
}
if ((host->plat->status || host->gpio_cd != -ENOSYS)
&& host->gpio_cd_irq < 0)
mmc->caps |= MMC_CAP_NEEDS_POLL;
ret = request_irq(dev->irq[0], mmci_irq, IRQF_SHARED, DRIVER_NAME " (cmd)", host);
if (ret)
goto unmap;
if (dev->irq[1] == NO_IRQ)
host->singleirq = true;
else {
ret = request_irq(dev->irq[1], mmci_pio_irq, IRQF_SHARED,
DRIVER_NAME " (pio)", host);
if (ret)
goto irq0_free;
}
writel(MCI_IRQENABLE, host->base + MMCIMASK0);
amba_set_drvdata(dev, mmc);
dev_info(&dev->dev, "%s: PL%03x manf %x rev%u at 0x%08llx irq %d,%d (pio)\n",
mmc_hostname(mmc), amba_part(dev), amba_manf(dev),
amba_rev(dev), (unsigned long long)dev->res.start,
dev->irq[0], dev->irq[1]);
mmci_dma_setup(host);
mmc_add_host(mmc);
return 0;
irq0_free:
free_irq(dev->irq[0], host);
unmap:
if (host->gpio_wp != -ENOSYS)
gpio_free(host->gpio_wp);
err_gpio_wp:
if (host->gpio_cd_irq >= 0)
free_irq(host->gpio_cd_irq, host);
if (host->gpio_cd != -ENOSYS)
gpio_free(host->gpio_cd);
err_gpio_cd:
iounmap(host->base);
clk_disable:
clk_disable(host->clk);
clk_free:
clk_put(host->clk);
host_free:
mmc_free_host(mmc);
rel_regions:
amba_release_regions(dev);
out:
return ret;
}
static int __devexit mmci_remove(struct amba_device *dev)
{
struct mmc_host *mmc = amba_get_drvdata(dev);
amba_set_drvdata(dev, NULL);
if (mmc) {
struct mmci_host *host = mmc_priv(mmc);
mmc_remove_host(mmc);
writel(0, host->base + MMCIMASK0);
writel(0, host->base + MMCIMASK1);
writel(0, host->base + MMCICOMMAND);
writel(0, host->base + MMCIDATACTRL);
mmci_dma_release(host);
free_irq(dev->irq[0], host);
if (!host->singleirq)
free_irq(dev->irq[1], host);
if (host->gpio_wp != -ENOSYS)
gpio_free(host->gpio_wp);
if (host->gpio_cd_irq >= 0)
free_irq(host->gpio_cd_irq, host);
if (host->gpio_cd != -ENOSYS)
gpio_free(host->gpio_cd);
iounmap(host->base);
clk_disable(host->clk);
clk_put(host->clk);
if (host->vcc)
mmc_regulator_set_ocr(mmc, host->vcc, 0);
regulator_put(host->vcc);
mmc_free_host(mmc);
amba_release_regions(dev);
}
return 0;
}
static int mmci_suspend(struct amba_device *dev, pm_message_t state)
{
struct mmc_host *mmc = amba_get_drvdata(dev);
int ret = 0;
if (mmc) {
struct mmci_host *host = mmc_priv(mmc);
ret = mmc_suspend_host(mmc);
if (ret == 0)
writel(0, host->base + MMCIMASK0);
}
return ret;
}
static int mmci_resume(struct amba_device *dev)
{
struct mmc_host *mmc = amba_get_drvdata(dev);
int ret = 0;
if (mmc) {
struct mmci_host *host = mmc_priv(mmc);
writel(MCI_IRQENABLE, host->base + MMCIMASK0);
ret = mmc_resume_host(mmc);
}
return ret;
}
static int __init mmci_init(void)
{
return amba_driver_register(&mmci_driver);
}
static void __exit mmci_exit(void)
{
amba_driver_unregister(&mmci_driver);
}
