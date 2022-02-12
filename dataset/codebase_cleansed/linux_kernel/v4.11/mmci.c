static int mmci_card_busy(struct mmc_host *mmc)
{
struct mmci_host *host = mmc_priv(mmc);
unsigned long flags;
int busy = 0;
spin_lock_irqsave(&host->lock, flags);
if (readl(host->base + MMCISTATUS) & host->variant->busy_detect_flag)
busy = 1;
spin_unlock_irqrestore(&host->lock, flags);
return busy;
}
static int mmci_validate_data(struct mmci_host *host,
struct mmc_data *data)
{
if (!data)
return 0;
if (!is_power_of_2(data->blksz)) {
dev_err(mmc_dev(host->mmc),
"unsupported block size (%d bytes)\n", data->blksz);
return -EINVAL;
}
return 0;
}
static void mmci_reg_delay(struct mmci_host *host)
{
if (host->cclk < 25000000)
udelay(30);
else
ndelay(120);
}
static void mmci_write_clkreg(struct mmci_host *host, u32 clk)
{
if (host->clk_reg != clk) {
host->clk_reg = clk;
writel(clk, host->base + MMCICLOCK);
}
}
static void mmci_write_pwrreg(struct mmci_host *host, u32 pwr)
{
if (host->pwr_reg != pwr) {
host->pwr_reg = pwr;
writel(pwr, host->base + MMCIPOWER);
}
}
static void mmci_write_datactrlreg(struct mmci_host *host, u32 datactrl)
{
datactrl |= host->datactrl_reg & host->variant->busy_dpsm_flag;
if (host->datactrl_reg != datactrl) {
host->datactrl_reg = datactrl;
writel(datactrl, host->base + MMCIDATACTRL);
}
}
static void mmci_set_clkreg(struct mmci_host *host, unsigned int desired)
{
struct variant_data *variant = host->variant;
u32 clk = variant->clkreg;
host->cclk = 0;
if (desired) {
if (variant->explicit_mclk_control) {
host->cclk = host->mclk;
} else if (desired >= host->mclk) {
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
host->mmc->actual_clock = host->cclk;
if (host->mmc->ios.bus_width == MMC_BUS_WIDTH_4)
clk |= MCI_4BIT_BUS;
if (host->mmc->ios.bus_width == MMC_BUS_WIDTH_8)
clk |= variant->clkreg_8bit_bus_enable;
if (host->mmc->ios.timing == MMC_TIMING_UHS_DDR50 ||
host->mmc->ios.timing == MMC_TIMING_MMC_DDR52)
clk |= variant->clkreg_neg_edge_enable;
mmci_write_clkreg(host, clk);
}
static void
mmci_request_end(struct mmci_host *host, struct mmc_request *mrq)
{
writel(0, host->base + MMCICOMMAND);
BUG_ON(host->data);
host->mrq = NULL;
host->cmd = NULL;
mmc_request_done(host->mmc, mrq);
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
mmci_write_datactrlreg(host, 0);
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
static void mmci_dma_setup(struct mmci_host *host)
{
const char *rxname, *txname;
struct variant_data *variant = host->variant;
host->dma_rx_channel = dma_request_slave_channel(mmc_dev(host->mmc), "rx");
host->dma_tx_channel = dma_request_slave_channel(mmc_dev(host->mmc), "tx");
host->next_data.cookie = 1;
if (host->dma_rx_channel && !host->dma_tx_channel)
host->dma_tx_channel = host->dma_rx_channel;
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
if (variant->qcom_dml && host->dma_rx_channel && host->dma_tx_channel)
if (dml_hw_init(host, host->mmc->parent->of_node))
variant->qcom_dml = false;
}
static inline void mmci_dma_release(struct mmci_host *host)
{
if (host->dma_rx_channel)
dma_release_channel(host->dma_rx_channel);
if (host->dma_tx_channel)
dma_release_channel(host->dma_tx_channel);
host->dma_rx_channel = host->dma_tx_channel = NULL;
}
static void mmci_dma_data_error(struct mmci_host *host)
{
dev_err(mmc_dev(host->mmc), "error during DMA transfer!\n");
dmaengine_terminate_all(host->dma_current);
host->dma_in_progress = false;
host->dma_current = NULL;
host->dma_desc_current = NULL;
host->data->host_cookie = 0;
}
static void mmci_dma_unmap(struct mmci_host *host, struct mmc_data *data)
{
struct dma_chan *chan;
enum dma_data_direction dir;
if (data->flags & MMC_DATA_READ) {
dir = DMA_FROM_DEVICE;
chan = host->dma_rx_channel;
} else {
dir = DMA_TO_DEVICE;
chan = host->dma_tx_channel;
}
dma_unmap_sg(chan->device->dev, data->sg, data->sg_len, dir);
}
static void mmci_dma_finalize(struct mmci_host *host, struct mmc_data *data)
{
u32 status;
int i;
for (i = 0; ; i++) {
status = readl(host->base + MMCISTATUS);
if (!(status & MCI_RXDATAAVLBLMASK) || i >= 100)
break;
udelay(10);
}
if (status & MCI_RXDATAAVLBLMASK) {
mmci_dma_data_error(host);
if (!data->error)
data->error = -EIO;
}
if (!data->host_cookie)
mmci_dma_unmap(host, data);
if (status & MCI_RXDATAAVLBLMASK) {
dev_err(mmc_dev(host->mmc), "buggy DMA detected. Taking evasive action.\n");
mmci_dma_release(host);
}
host->dma_in_progress = false;
host->dma_current = NULL;
host->dma_desc_current = NULL;
}
static int __mmci_dma_prep_data(struct mmci_host *host, struct mmc_data *data,
struct dma_chan **dma_chan,
struct dma_async_tx_descriptor **dma_desc)
{
struct variant_data *variant = host->variant;
struct dma_slave_config conf = {
.src_addr = host->phybase + MMCIFIFO,
.dst_addr = host->phybase + MMCIFIFO,
.src_addr_width = DMA_SLAVE_BUSWIDTH_4_BYTES,
.dst_addr_width = DMA_SLAVE_BUSWIDTH_4_BYTES,
.src_maxburst = variant->fifohalfsize >> 2,
.dst_maxburst = variant->fifohalfsize >> 2,
.device_fc = false,
};
struct dma_chan *chan;
struct dma_device *device;
struct dma_async_tx_descriptor *desc;
enum dma_data_direction buffer_dirn;
int nr_sg;
unsigned long flags = DMA_CTRL_ACK;
if (data->flags & MMC_DATA_READ) {
conf.direction = DMA_DEV_TO_MEM;
buffer_dirn = DMA_FROM_DEVICE;
chan = host->dma_rx_channel;
} else {
conf.direction = DMA_MEM_TO_DEV;
buffer_dirn = DMA_TO_DEVICE;
chan = host->dma_tx_channel;
}
if (!chan)
return -EINVAL;
if (data->blksz * data->blocks <= variant->fifosize)
return -EINVAL;
device = chan->device;
nr_sg = dma_map_sg(device->dev, data->sg, data->sg_len, buffer_dirn);
if (nr_sg == 0)
return -EINVAL;
if (host->variant->qcom_dml)
flags |= DMA_PREP_INTERRUPT;
dmaengine_slave_config(chan, &conf);
desc = dmaengine_prep_slave_sg(chan, data->sg, nr_sg,
conf.direction, flags);
if (!desc)
goto unmap_exit;
*dma_chan = chan;
*dma_desc = desc;
return 0;
unmap_exit:
dma_unmap_sg(device->dev, data->sg, data->sg_len, buffer_dirn);
return -ENOMEM;
}
static inline int mmci_dma_prep_data(struct mmci_host *host,
struct mmc_data *data)
{
if (host->dma_current && host->dma_desc_current)
return 0;
return __mmci_dma_prep_data(host, data, &host->dma_current,
&host->dma_desc_current);
}
static inline int mmci_dma_prep_next(struct mmci_host *host,
struct mmc_data *data)
{
struct mmci_host_next *nd = &host->next_data;
return __mmci_dma_prep_data(host, data, &nd->dma_chan, &nd->dma_desc);
}
static int mmci_dma_start_data(struct mmci_host *host, unsigned int datactrl)
{
int ret;
struct mmc_data *data = host->data;
ret = mmci_dma_prep_data(host, host->data);
if (ret)
return ret;
dev_vdbg(mmc_dev(host->mmc),
"Submit MMCI DMA job, sglen %d blksz %04x blks %04x flags %08x\n",
data->sg_len, data->blksz, data->blocks, data->flags);
host->dma_in_progress = true;
dmaengine_submit(host->dma_desc_current);
dma_async_issue_pending(host->dma_current);
if (host->variant->qcom_dml)
dml_start_xfer(host, data);
datactrl |= MCI_DPSM_DMAENABLE;
mmci_write_datactrlreg(host, datactrl);
writel(readl(host->base + MMCIMASK0) | MCI_DATAENDMASK,
host->base + MMCIMASK0);
return 0;
}
static void mmci_get_next_data(struct mmci_host *host, struct mmc_data *data)
{
struct mmci_host_next *next = &host->next_data;
WARN_ON(data->host_cookie && data->host_cookie != next->cookie);
WARN_ON(!data->host_cookie && (next->dma_desc || next->dma_chan));
host->dma_desc_current = next->dma_desc;
host->dma_current = next->dma_chan;
next->dma_desc = NULL;
next->dma_chan = NULL;
}
static void mmci_pre_request(struct mmc_host *mmc, struct mmc_request *mrq)
{
struct mmci_host *host = mmc_priv(mmc);
struct mmc_data *data = mrq->data;
struct mmci_host_next *nd = &host->next_data;
if (!data)
return;
BUG_ON(data->host_cookie);
if (mmci_validate_data(host, data))
return;
if (!mmci_dma_prep_next(host, data))
data->host_cookie = ++nd->cookie < 0 ? 1 : nd->cookie;
}
static void mmci_post_request(struct mmc_host *mmc, struct mmc_request *mrq,
int err)
{
struct mmci_host *host = mmc_priv(mmc);
struct mmc_data *data = mrq->data;
if (!data || !data->host_cookie)
return;
mmci_dma_unmap(host, data);
if (err) {
struct mmci_host_next *next = &host->next_data;
struct dma_chan *chan;
if (data->flags & MMC_DATA_READ)
chan = host->dma_rx_channel;
else
chan = host->dma_tx_channel;
dmaengine_terminate_all(chan);
if (host->dma_desc_current == next->dma_desc)
host->dma_desc_current = NULL;
if (host->dma_current == next->dma_chan) {
host->dma_in_progress = false;
host->dma_current = NULL;
}
next->dma_desc = NULL;
next->dma_chan = NULL;
data->host_cookie = 0;
}
}
static void mmci_get_next_data(struct mmci_host *host, struct mmc_data *data)
{
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
static inline void mmci_dma_finalize(struct mmci_host *host,
struct mmc_data *data)
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
do_div(clks, NSEC_PER_SEC);
timeout = data->timeout_clks + (unsigned int)clks;
base = host->base;
writel(timeout, base + MMCIDATATIMER);
writel(host->size, base + MMCIDATALENGTH);
blksz_bits = ffs(data->blksz) - 1;
BUG_ON(1 << blksz_bits != data->blksz);
if (variant->blksz_datactrl16)
datactrl = MCI_DPSM_ENABLE | (data->blksz << 16);
else if (variant->blksz_datactrl4)
datactrl = MCI_DPSM_ENABLE | (data->blksz << 4);
else
datactrl = MCI_DPSM_ENABLE | blksz_bits << 4;
if (data->flags & MMC_DATA_READ)
datactrl |= MCI_DPSM_DIRECTION;
if (host->mmc->card && mmc_card_sdio(host->mmc->card)) {
u32 clk;
datactrl |= variant->datactrl_mask_sdio;
if (variant->st_sdio && data->flags & MMC_DATA_WRITE &&
(host->size < 8 ||
(host->size <= 8 && host->mclk > 50000000)))
clk = host->clk_reg & ~variant->clkreg_enable;
else
clk = host->clk_reg | variant->clkreg_enable;
mmci_write_clkreg(host, clk);
}
if (host->mmc->ios.timing == MMC_TIMING_UHS_DDR50 ||
host->mmc->ios.timing == MMC_TIMING_MMC_DDR52)
datactrl |= variant->datactrl_mask_ddrmode;
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
mmci_write_datactrlreg(host, datactrl);
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
mmci_reg_delay(host);
}
c |= cmd->opcode | MCI_CPSM_ENABLE;
if (cmd->flags & MMC_RSP_PRESENT) {
if (cmd->flags & MMC_RSP_136)
c |= MCI_CPSM_LONGRSP;
c |= MCI_CPSM_RESPONSE;
}
if (0)
c |= MCI_CPSM_INTERRUPT;
if (mmc_cmd_type(cmd) == MMC_CMD_ADTC)
c |= host->variant->data_cmd_enable;
host->cmd = cmd;
writel(cmd->arg, base + MMCIARGUMENT);
writel(c, base + MMCICOMMAND);
}
static void
mmci_data_irq(struct mmci_host *host, struct mmc_data *data,
unsigned int status)
{
if (!data)
return;
if (status & (MCI_DATACRCFAIL|MCI_DATATIMEOUT|MCI_STARTBITERR|
MCI_TXUNDERRUN|MCI_RXOVERRUN)) {
u32 remain, success;
if (dma_inprogress(host)) {
mmci_dma_data_error(host);
mmci_dma_unmap(host, data);
}
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
mmci_dma_finalize(host, data);
mmci_stop_data(host);
if (!data->error)
data->bytes_xfered = data->blksz * data->blocks;
if (!data->stop || host->mrq->sbc) {
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
bool sbc;
if (!cmd)
return;
sbc = (cmd == host->mrq->sbc);
if (!((status|host->busy_status) &
(MCI_CMDCRCFAIL|MCI_CMDTIMEOUT|MCI_CMDSENT|MCI_CMDRESPEND)))
return;
if (host->variant->busy_detect) {
bool busy_resp = !!(cmd->flags & MMC_RSP_BUSY);
if (host->busy_status &&
(status & host->variant->busy_detect_flag))
return;
if (!host->busy_status && busy_resp &&
!(status & (MCI_CMDCRCFAIL|MCI_CMDTIMEOUT)) &&
(readl(base + MMCISTATUS) & host->variant->busy_detect_flag)) {
writel(host->variant->busy_detect_mask,
host->base + MMCICLEAR);
writel(readl(base + MMCIMASK0) |
host->variant->busy_detect_mask,
base + MMCIMASK0);
host->busy_status =
status & (MCI_CMDSENT|MCI_CMDRESPEND);
return;
}
if (host->busy_status) {
writel(host->variant->busy_detect_mask,
host->base + MMCICLEAR);
writel(readl(base + MMCIMASK0) &
~host->variant->busy_detect_mask,
base + MMCIMASK0);
host->busy_status = 0;
}
}
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
if ((!sbc && !cmd->data) || cmd->error) {
if (host->data) {
if (dma_inprogress(host)) {
mmci_dma_data_error(host);
mmci_dma_unmap(host, host->data);
}
mmci_stop_data(host);
}
mmci_request_end(host, host->mrq);
} else if (sbc) {
mmci_start_command(host, host->mrq->cmd, 0);
} else if (!(cmd->data->flags & MMC_DATA_READ)) {
mmci_start_data(host, cmd->data);
}
}
static int mmci_get_rx_fifocnt(struct mmci_host *host, u32 status, int remain)
{
return remain - (readl(host->base + MMCIFIFOCNT) << 2);
}
static int mmci_qcom_get_rx_fifocnt(struct mmci_host *host, u32 status, int r)
{
if (status & MCI_RXFIFOHALFFULL)
return host->variant->fifohalfsize;
else if (status & MCI_RXDATAAVLBL)
return 4;
return 0;
}
static int mmci_pio_read(struct mmci_host *host, char *buffer, unsigned int remain)
{
void __iomem *base = host->base;
char *ptr = buffer;
u32 status = readl(host->base + MMCISTATUS);
int host_remain = host->size;
do {
int count = host->get_rx_fifocnt(host, status, host_remain);
if (count > remain)
count = remain;
if (count <= 0)
break;
if (unlikely(count & 0x3)) {
if (count < 4) {
unsigned char buf[4];
ioread32_rep(base + MMCIFIFO, buf, 1);
memcpy(ptr, buf, count);
} else {
ioread32_rep(base + MMCIFIFO, ptr, count >> 2);
count &= ~0x3;
}
} else {
ioread32_rep(base + MMCIFIFO, ptr, count >> 2);
}
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
iowrite32_rep(base + MMCIFIFO, ptr, (count + 3) >> 2);
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
status = readl(host->base + MMCISTATUS);
if (host->singleirq) {
if (status & readl(host->base + MMCIMASK1))
mmci_pio_irq(irq, dev_id);
status &= ~MCI_IRQ1MASK;
}
status &= readl(host->base + MMCIMASK0);
if (host->variant->busy_detect)
writel(status & ~host->variant->busy_detect_mask,
host->base + MMCICLEAR);
else
writel(status, host->base + MMCICLEAR);
dev_dbg(mmc_dev(host->mmc), "irq0 (data+cmd) %08x\n", status);
if (host->variant->reversed_irq_handling) {
mmci_data_irq(host, host->data, status);
mmci_cmd_irq(host, host->cmd, status);
} else {
mmci_cmd_irq(host, host->cmd, status);
mmci_data_irq(host, host->data, status);
}
if (host->variant->busy_detect && host->busy_status)
status &= ~host->variant->busy_detect_flag;
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
mrq->cmd->error = mmci_validate_data(host, mrq->data);
if (mrq->cmd->error) {
mmc_request_done(mmc, mrq);
return;
}
spin_lock_irqsave(&host->lock, flags);
host->mrq = mrq;
if (mrq->data)
mmci_get_next_data(host, mrq->data);
if (mrq->data && mrq->data->flags & MMC_DATA_READ)
mmci_start_data(host, mrq->data);
if (mrq->sbc)
mmci_start_command(host, mrq->sbc, 0);
else
mmci_start_command(host, mrq->cmd, 0);
spin_unlock_irqrestore(&host->lock, flags);
}
static void mmci_set_ios(struct mmc_host *mmc, struct mmc_ios *ios)
{
struct mmci_host *host = mmc_priv(mmc);
struct variant_data *variant = host->variant;
u32 pwr = 0;
unsigned long flags;
int ret;
if (host->plat->ios_handler &&
host->plat->ios_handler(mmc_dev(mmc), ios))
dev_err(mmc_dev(mmc), "platform ios_handler failed\n");
switch (ios->power_mode) {
case MMC_POWER_OFF:
if (!IS_ERR(mmc->supply.vmmc))
mmc_regulator_set_ocr(mmc, mmc->supply.vmmc, 0);
if (!IS_ERR(mmc->supply.vqmmc) && host->vqmmc_enabled) {
regulator_disable(mmc->supply.vqmmc);
host->vqmmc_enabled = false;
}
break;
case MMC_POWER_UP:
if (!IS_ERR(mmc->supply.vmmc))
mmc_regulator_set_ocr(mmc, mmc->supply.vmmc, ios->vdd);
pwr |= variant->pwrreg_powerup;
break;
case MMC_POWER_ON:
if (!IS_ERR(mmc->supply.vqmmc) && !host->vqmmc_enabled) {
ret = regulator_enable(mmc->supply.vqmmc);
if (ret < 0)
dev_err(mmc_dev(mmc),
"failed to enable vqmmc regulator\n");
else
host->vqmmc_enabled = true;
}
pwr |= MCI_PWR_ON;
break;
}
if (variant->signal_direction && ios->power_mode != MMC_POWER_OFF) {
pwr |= host->pwr_reg_add;
if (ios->bus_width == MMC_BUS_WIDTH_4)
pwr &= ~MCI_ST_DATA74DIREN;
else if (ios->bus_width == MMC_BUS_WIDTH_1)
pwr &= (~MCI_ST_DATA74DIREN &
~MCI_ST_DATA31DIREN &
~MCI_ST_DATA2DIREN);
}
if (ios->bus_mode == MMC_BUSMODE_OPENDRAIN) {
if (host->hw_designer != AMBA_VENDOR_ST)
pwr |= MCI_ROD;
else {
pwr |= MCI_OD;
}
}
if (!ios->clock && variant->pwrreg_clkgate)
pwr &= ~MCI_PWR_ON;
if (host->variant->explicit_mclk_control &&
ios->clock != host->clock_cache) {
ret = clk_set_rate(host->clk, ios->clock);
if (ret < 0)
dev_err(mmc_dev(host->mmc),
"Error setting clock rate (%d)\n", ret);
else
host->mclk = clk_get_rate(host->clk);
}
host->clock_cache = ios->clock;
spin_lock_irqsave(&host->lock, flags);
mmci_set_clkreg(host, ios->clock);
mmci_write_pwrreg(host, pwr);
mmci_reg_delay(host);
spin_unlock_irqrestore(&host->lock, flags);
}
static int mmci_get_cd(struct mmc_host *mmc)
{
struct mmci_host *host = mmc_priv(mmc);
struct mmci_platform_data *plat = host->plat;
unsigned int status = mmc_gpio_get_cd(mmc);
if (status == -ENOSYS) {
if (!plat->status)
return 1;
status = plat->status(mmc_dev(host->mmc));
}
return status;
}
static int mmci_sig_volt_switch(struct mmc_host *mmc, struct mmc_ios *ios)
{
int ret = 0;
if (!IS_ERR(mmc->supply.vqmmc)) {
switch (ios->signal_voltage) {
case MMC_SIGNAL_VOLTAGE_330:
ret = regulator_set_voltage(mmc->supply.vqmmc,
2700000, 3600000);
break;
case MMC_SIGNAL_VOLTAGE_180:
ret = regulator_set_voltage(mmc->supply.vqmmc,
1700000, 1950000);
break;
case MMC_SIGNAL_VOLTAGE_120:
ret = regulator_set_voltage(mmc->supply.vqmmc,
1100000, 1300000);
break;
}
if (ret)
dev_warn(mmc_dev(mmc), "Voltage switch failed\n");
}
return ret;
}
static int mmci_of_parse(struct device_node *np, struct mmc_host *mmc)
{
struct mmci_host *host = mmc_priv(mmc);
int ret = mmc_of_parse(mmc);
if (ret)
return ret;
if (of_get_property(np, "st,sig-dir-dat0", NULL))
host->pwr_reg_add |= MCI_ST_DATA0DIREN;
if (of_get_property(np, "st,sig-dir-dat2", NULL))
host->pwr_reg_add |= MCI_ST_DATA2DIREN;
if (of_get_property(np, "st,sig-dir-dat31", NULL))
host->pwr_reg_add |= MCI_ST_DATA31DIREN;
if (of_get_property(np, "st,sig-dir-dat74", NULL))
host->pwr_reg_add |= MCI_ST_DATA74DIREN;
if (of_get_property(np, "st,sig-dir-cmd", NULL))
host->pwr_reg_add |= MCI_ST_CMDDIREN;
if (of_get_property(np, "st,sig-pin-fbclk", NULL))
host->pwr_reg_add |= MCI_ST_FBCLKEN;
if (of_get_property(np, "mmc-cap-mmc-highspeed", NULL))
mmc->caps |= MMC_CAP_MMC_HIGHSPEED;
if (of_get_property(np, "mmc-cap-sd-highspeed", NULL))
mmc->caps |= MMC_CAP_SD_HIGHSPEED;
return 0;
}
static int mmci_probe(struct amba_device *dev,
const struct amba_id *id)
{
struct mmci_platform_data *plat = dev->dev.platform_data;
struct device_node *np = dev->dev.of_node;
struct variant_data *variant = id->data;
struct mmci_host *host;
struct mmc_host *mmc;
int ret;
if (!plat && !np) {
dev_err(&dev->dev, "No plat data or DT found\n");
return -EINVAL;
}
if (!plat) {
plat = devm_kzalloc(&dev->dev, sizeof(*plat), GFP_KERNEL);
if (!plat)
return -ENOMEM;
}
mmc = mmc_alloc_host(sizeof(struct mmci_host), &dev->dev);
if (!mmc)
return -ENOMEM;
ret = mmci_of_parse(np, mmc);
if (ret)
goto host_free;
host = mmc_priv(mmc);
host->mmc = mmc;
host->hw_designer = amba_manf(dev);
host->hw_revision = amba_rev(dev);
dev_dbg(mmc_dev(mmc), "designer ID = 0x%02x\n", host->hw_designer);
dev_dbg(mmc_dev(mmc), "revision = 0x%01x\n", host->hw_revision);
host->clk = devm_clk_get(&dev->dev, NULL);
if (IS_ERR(host->clk)) {
ret = PTR_ERR(host->clk);
goto host_free;
}
ret = clk_prepare_enable(host->clk);
if (ret)
goto host_free;
if (variant->qcom_fifo)
host->get_rx_fifocnt = mmci_qcom_get_rx_fifocnt;
else
host->get_rx_fifocnt = mmci_get_rx_fifocnt;
host->plat = plat;
host->variant = variant;
host->mclk = clk_get_rate(host->clk);
if (host->mclk > variant->f_max) {
ret = clk_set_rate(host->clk, variant->f_max);
if (ret < 0)
goto clk_disable;
host->mclk = clk_get_rate(host->clk);
dev_dbg(mmc_dev(mmc), "eventual mclk rate: %u Hz\n",
host->mclk);
}
host->phybase = dev->res.start;
host->base = devm_ioremap_resource(&dev->dev, &dev->res);
if (IS_ERR(host->base)) {
ret = PTR_ERR(host->base);
goto clk_disable;
}
if (variant->st_clkdiv)
mmc->f_min = DIV_ROUND_UP(host->mclk, 257);
else if (variant->explicit_mclk_control)
mmc->f_min = clk_round_rate(host->clk, 100000);
else
mmc->f_min = DIV_ROUND_UP(host->mclk, 512);
if (mmc->f_max)
mmc->f_max = variant->explicit_mclk_control ?
min(variant->f_max, mmc->f_max) :
min(host->mclk, mmc->f_max);
else
mmc->f_max = variant->explicit_mclk_control ?
fmax : min(host->mclk, fmax);
dev_dbg(mmc_dev(mmc), "clocking block at %u Hz\n", mmc->f_max);
ret = mmc_regulator_get_supply(mmc);
if (ret == -EPROBE_DEFER)
goto clk_disable;
if (!mmc->ocr_avail)
mmc->ocr_avail = plat->ocr_mask;
else if (plat->ocr_mask)
dev_warn(mmc_dev(mmc), "Platform OCR mask is ignored\n");
if (!np) {
if (!plat->cd_invert)
mmc->caps2 |= MMC_CAP2_CD_ACTIVE_HIGH;
mmc->caps2 |= MMC_CAP2_RO_ACTIVE_HIGH;
}
mmc->caps |= MMC_CAP_CMD23;
if (variant->busy_detect) {
mmci_ops.card_busy = mmci_card_busy;
if (variant->busy_dpsm_flag)
mmci_write_datactrlreg(host,
host->variant->busy_dpsm_flag);
mmc->caps |= MMC_CAP_WAIT_WHILE_BUSY;
mmc->max_busy_timeout = 0;
}
mmc->ops = &mmci_ops;
mmc->pm_caps |= MMC_PM_KEEP_POWER;
mmc->max_segs = NR_SG;
mmc->max_req_size = (1 << variant->datalength_bits) - 1;
mmc->max_seg_size = mmc->max_req_size;
mmc->max_blk_size = 1 << 11;
mmc->max_blk_count = mmc->max_req_size >> 11;
spin_lock_init(&host->lock);
writel(0, host->base + MMCIMASK0);
writel(0, host->base + MMCIMASK1);
writel(0xfff, host->base + MMCICLEAR);
if (!np) {
ret = mmc_gpiod_request_cd(mmc, "cd", 0, false, 0, NULL);
if (ret < 0) {
if (ret == -EPROBE_DEFER)
goto clk_disable;
else if (gpio_is_valid(plat->gpio_cd)) {
ret = mmc_gpio_request_cd(mmc, plat->gpio_cd, 0);
if (ret)
goto clk_disable;
}
}
ret = mmc_gpiod_request_ro(mmc, "wp", 0, false, 0, NULL);
if (ret < 0) {
if (ret == -EPROBE_DEFER)
goto clk_disable;
else if (gpio_is_valid(plat->gpio_wp)) {
ret = mmc_gpio_request_ro(mmc, plat->gpio_wp);
if (ret)
goto clk_disable;
}
}
}
ret = devm_request_irq(&dev->dev, dev->irq[0], mmci_irq, IRQF_SHARED,
DRIVER_NAME " (cmd)", host);
if (ret)
goto clk_disable;
if (!dev->irq[1])
host->singleirq = true;
else {
ret = devm_request_irq(&dev->dev, dev->irq[1], mmci_pio_irq,
IRQF_SHARED, DRIVER_NAME " (pio)", host);
if (ret)
goto clk_disable;
}
writel(MCI_IRQENABLE, host->base + MMCIMASK0);
amba_set_drvdata(dev, mmc);
dev_info(&dev->dev, "%s: PL%03x manf %x rev%u at 0x%08llx irq %d,%d (pio)\n",
mmc_hostname(mmc), amba_part(dev), amba_manf(dev),
amba_rev(dev), (unsigned long long)dev->res.start,
dev->irq[0], dev->irq[1]);
mmci_dma_setup(host);
pm_runtime_set_autosuspend_delay(&dev->dev, 50);
pm_runtime_use_autosuspend(&dev->dev);
mmc_add_host(mmc);
pm_runtime_put(&dev->dev);
return 0;
clk_disable:
clk_disable_unprepare(host->clk);
host_free:
mmc_free_host(mmc);
return ret;
}
static int mmci_remove(struct amba_device *dev)
{
struct mmc_host *mmc = amba_get_drvdata(dev);
if (mmc) {
struct mmci_host *host = mmc_priv(mmc);
pm_runtime_get_sync(&dev->dev);
mmc_remove_host(mmc);
writel(0, host->base + MMCIMASK0);
writel(0, host->base + MMCIMASK1);
writel(0, host->base + MMCICOMMAND);
writel(0, host->base + MMCIDATACTRL);
mmci_dma_release(host);
clk_disable_unprepare(host->clk);
mmc_free_host(mmc);
}
return 0;
}
static void mmci_save(struct mmci_host *host)
{
unsigned long flags;
spin_lock_irqsave(&host->lock, flags);
writel(0, host->base + MMCIMASK0);
if (host->variant->pwrreg_nopower) {
writel(0, host->base + MMCIDATACTRL);
writel(0, host->base + MMCIPOWER);
writel(0, host->base + MMCICLOCK);
}
mmci_reg_delay(host);
spin_unlock_irqrestore(&host->lock, flags);
}
static void mmci_restore(struct mmci_host *host)
{
unsigned long flags;
spin_lock_irqsave(&host->lock, flags);
if (host->variant->pwrreg_nopower) {
writel(host->clk_reg, host->base + MMCICLOCK);
writel(host->datactrl_reg, host->base + MMCIDATACTRL);
writel(host->pwr_reg, host->base + MMCIPOWER);
}
writel(MCI_IRQENABLE, host->base + MMCIMASK0);
mmci_reg_delay(host);
spin_unlock_irqrestore(&host->lock, flags);
}
static int mmci_runtime_suspend(struct device *dev)
{
struct amba_device *adev = to_amba_device(dev);
struct mmc_host *mmc = amba_get_drvdata(adev);
if (mmc) {
struct mmci_host *host = mmc_priv(mmc);
pinctrl_pm_select_sleep_state(dev);
mmci_save(host);
clk_disable_unprepare(host->clk);
}
return 0;
}
static int mmci_runtime_resume(struct device *dev)
{
struct amba_device *adev = to_amba_device(dev);
struct mmc_host *mmc = amba_get_drvdata(adev);
if (mmc) {
struct mmci_host *host = mmc_priv(mmc);
clk_prepare_enable(host->clk);
mmci_restore(host);
pinctrl_pm_select_default_state(dev);
}
return 0;
}
