static inline void sh_mmcif_bitset(struct sh_mmcif_host *host,
unsigned int reg, u32 val)
{
writel(val | readl(host->addr + reg), host->addr + reg);
}
static inline void sh_mmcif_bitclr(struct sh_mmcif_host *host,
unsigned int reg, u32 val)
{
writel(~val & readl(host->addr + reg), host->addr + reg);
}
static void sh_mmcif_dma_complete(void *arg)
{
struct sh_mmcif_host *host = arg;
struct mmc_request *mrq = host->mrq;
struct device *dev = sh_mmcif_host_to_dev(host);
dev_dbg(dev, "Command completed\n");
if (WARN(!mrq || !mrq->data, "%s: NULL data in DMA completion!\n",
dev_name(dev)))
return;
complete(&host->dma_complete);
}
static void sh_mmcif_start_dma_rx(struct sh_mmcif_host *host)
{
struct mmc_data *data = host->mrq->data;
struct scatterlist *sg = data->sg;
struct dma_async_tx_descriptor *desc = NULL;
struct dma_chan *chan = host->chan_rx;
struct device *dev = sh_mmcif_host_to_dev(host);
dma_cookie_t cookie = -EINVAL;
int ret;
ret = dma_map_sg(chan->device->dev, sg, data->sg_len,
DMA_FROM_DEVICE);
if (ret > 0) {
host->dma_active = true;
desc = dmaengine_prep_slave_sg(chan, sg, ret,
DMA_DEV_TO_MEM, DMA_PREP_INTERRUPT | DMA_CTRL_ACK);
}
if (desc) {
desc->callback = sh_mmcif_dma_complete;
desc->callback_param = host;
cookie = dmaengine_submit(desc);
sh_mmcif_bitset(host, MMCIF_CE_BUF_ACC, BUF_ACC_DMAREN);
dma_async_issue_pending(chan);
}
dev_dbg(dev, "%s(): mapped %d -> %d, cookie %d\n",
__func__, data->sg_len, ret, cookie);
if (!desc) {
if (ret >= 0)
ret = -EIO;
host->chan_rx = NULL;
host->dma_active = false;
dma_release_channel(chan);
chan = host->chan_tx;
if (chan) {
host->chan_tx = NULL;
dma_release_channel(chan);
}
dev_warn(dev,
"DMA failed: %d, falling back to PIO\n", ret);
sh_mmcif_bitclr(host, MMCIF_CE_BUF_ACC, BUF_ACC_DMAREN | BUF_ACC_DMAWEN);
}
dev_dbg(dev, "%s(): desc %p, cookie %d, sg[%d]\n", __func__,
desc, cookie, data->sg_len);
}
static void sh_mmcif_start_dma_tx(struct sh_mmcif_host *host)
{
struct mmc_data *data = host->mrq->data;
struct scatterlist *sg = data->sg;
struct dma_async_tx_descriptor *desc = NULL;
struct dma_chan *chan = host->chan_tx;
struct device *dev = sh_mmcif_host_to_dev(host);
dma_cookie_t cookie = -EINVAL;
int ret;
ret = dma_map_sg(chan->device->dev, sg, data->sg_len,
DMA_TO_DEVICE);
if (ret > 0) {
host->dma_active = true;
desc = dmaengine_prep_slave_sg(chan, sg, ret,
DMA_MEM_TO_DEV, DMA_PREP_INTERRUPT | DMA_CTRL_ACK);
}
if (desc) {
desc->callback = sh_mmcif_dma_complete;
desc->callback_param = host;
cookie = dmaengine_submit(desc);
sh_mmcif_bitset(host, MMCIF_CE_BUF_ACC, BUF_ACC_DMAWEN);
dma_async_issue_pending(chan);
}
dev_dbg(dev, "%s(): mapped %d -> %d, cookie %d\n",
__func__, data->sg_len, ret, cookie);
if (!desc) {
if (ret >= 0)
ret = -EIO;
host->chan_tx = NULL;
host->dma_active = false;
dma_release_channel(chan);
chan = host->chan_rx;
if (chan) {
host->chan_rx = NULL;
dma_release_channel(chan);
}
dev_warn(dev,
"DMA failed: %d, falling back to PIO\n", ret);
sh_mmcif_bitclr(host, MMCIF_CE_BUF_ACC, BUF_ACC_DMAREN | BUF_ACC_DMAWEN);
}
dev_dbg(dev, "%s(): desc %p, cookie %d\n", __func__,
desc, cookie);
}
static struct dma_chan *
sh_mmcif_request_dma_pdata(struct sh_mmcif_host *host, uintptr_t slave_id)
{
dma_cap_mask_t mask;
dma_cap_zero(mask);
dma_cap_set(DMA_SLAVE, mask);
if (slave_id <= 0)
return NULL;
return dma_request_channel(mask, shdma_chan_filter, (void *)slave_id);
}
static int sh_mmcif_dma_slave_config(struct sh_mmcif_host *host,
struct dma_chan *chan,
enum dma_transfer_direction direction)
{
struct resource *res;
struct dma_slave_config cfg = { 0, };
res = platform_get_resource(host->pd, IORESOURCE_MEM, 0);
cfg.direction = direction;
if (direction == DMA_DEV_TO_MEM) {
cfg.src_addr = res->start + MMCIF_CE_DATA;
cfg.src_addr_width = DMA_SLAVE_BUSWIDTH_4_BYTES;
} else {
cfg.dst_addr = res->start + MMCIF_CE_DATA;
cfg.dst_addr_width = DMA_SLAVE_BUSWIDTH_4_BYTES;
}
return dmaengine_slave_config(chan, &cfg);
}
static void sh_mmcif_request_dma(struct sh_mmcif_host *host)
{
struct device *dev = sh_mmcif_host_to_dev(host);
host->dma_active = false;
if (IS_ENABLED(CONFIG_SUPERH) && dev->platform_data) {
struct sh_mmcif_plat_data *pdata = dev->platform_data;
host->chan_tx = sh_mmcif_request_dma_pdata(host,
pdata->slave_id_tx);
host->chan_rx = sh_mmcif_request_dma_pdata(host,
pdata->slave_id_rx);
} else {
host->chan_tx = dma_request_slave_channel(dev, "tx");
host->chan_rx = dma_request_slave_channel(dev, "rx");
}
dev_dbg(dev, "%s: got channel TX %p RX %p\n", __func__, host->chan_tx,
host->chan_rx);
if (!host->chan_tx || !host->chan_rx ||
sh_mmcif_dma_slave_config(host, host->chan_tx, DMA_MEM_TO_DEV) ||
sh_mmcif_dma_slave_config(host, host->chan_rx, DMA_DEV_TO_MEM))
goto error;
return;
error:
if (host->chan_tx)
dma_release_channel(host->chan_tx);
if (host->chan_rx)
dma_release_channel(host->chan_rx);
host->chan_tx = host->chan_rx = NULL;
}
static void sh_mmcif_release_dma(struct sh_mmcif_host *host)
{
sh_mmcif_bitclr(host, MMCIF_CE_BUF_ACC, BUF_ACC_DMAREN | BUF_ACC_DMAWEN);
if (host->chan_tx) {
struct dma_chan *chan = host->chan_tx;
host->chan_tx = NULL;
dma_release_channel(chan);
}
if (host->chan_rx) {
struct dma_chan *chan = host->chan_rx;
host->chan_rx = NULL;
dma_release_channel(chan);
}
host->dma_active = false;
}
static void sh_mmcif_clock_control(struct sh_mmcif_host *host, unsigned int clk)
{
struct device *dev = sh_mmcif_host_to_dev(host);
struct sh_mmcif_plat_data *p = dev->platform_data;
bool sup_pclk = p ? p->sup_pclk : false;
unsigned int current_clk = clk_get_rate(host->clk);
unsigned int clkdiv;
sh_mmcif_bitclr(host, MMCIF_CE_CLK_CTRL, CLK_ENABLE);
sh_mmcif_bitclr(host, MMCIF_CE_CLK_CTRL, CLK_CLEAR);
if (!clk)
return;
if (host->clkdiv_map) {
unsigned int freq, best_freq, myclk, div, diff_min, diff;
int i;
clkdiv = 0;
diff_min = ~0;
best_freq = 0;
for (i = 31; i >= 0; i--) {
if (!((1 << i) & host->clkdiv_map))
continue;
div = 1 << (i + 1);
freq = clk_round_rate(host->clk, clk * div);
myclk = freq / div;
diff = (myclk > clk) ? myclk - clk : clk - myclk;
if (diff <= diff_min) {
best_freq = freq;
clkdiv = i;
diff_min = diff;
}
}
dev_dbg(dev, "clk %u/%u (%u, 0x%x)\n",
(best_freq / (1 << (clkdiv + 1))), clk,
best_freq, clkdiv);
clk_set_rate(host->clk, best_freq);
clkdiv = clkdiv << 16;
} else if (sup_pclk && clk == current_clk) {
clkdiv = CLK_SUP_PCLK;
} else {
clkdiv = (fls(DIV_ROUND_UP(current_clk, clk) - 1) - 1) << 16;
}
sh_mmcif_bitset(host, MMCIF_CE_CLK_CTRL, CLK_CLEAR & clkdiv);
sh_mmcif_bitset(host, MMCIF_CE_CLK_CTRL, CLK_ENABLE);
}
static void sh_mmcif_sync_reset(struct sh_mmcif_host *host)
{
u32 tmp;
tmp = 0x010f0000 & sh_mmcif_readl(host->addr, MMCIF_CE_CLK_CTRL);
sh_mmcif_writel(host->addr, MMCIF_CE_VERSION, SOFT_RST_ON);
sh_mmcif_writel(host->addr, MMCIF_CE_VERSION, SOFT_RST_OFF);
if (host->ccs_enable)
tmp |= SCCSTO_29;
if (host->clk_ctrl2_enable)
sh_mmcif_writel(host->addr, MMCIF_CE_CLK_CTRL2, 0x0F0F0000);
sh_mmcif_bitset(host, MMCIF_CE_CLK_CTRL, tmp |
SRSPTO_256 | SRBSYTO_29 | SRWDTO_29);
sh_mmcif_bitset(host, MMCIF_CE_BUF_ACC, BUF_ACC_ATYP);
}
static int sh_mmcif_error_manage(struct sh_mmcif_host *host)
{
struct device *dev = sh_mmcif_host_to_dev(host);
u32 state1, state2;
int ret, timeout;
host->sd_error = false;
state1 = sh_mmcif_readl(host->addr, MMCIF_CE_HOST_STS1);
state2 = sh_mmcif_readl(host->addr, MMCIF_CE_HOST_STS2);
dev_dbg(dev, "ERR HOST_STS1 = %08x\n", state1);
dev_dbg(dev, "ERR HOST_STS2 = %08x\n", state2);
if (state1 & STS1_CMDSEQ) {
sh_mmcif_bitset(host, MMCIF_CE_CMD_CTRL, CMD_CTRL_BREAK);
sh_mmcif_bitset(host, MMCIF_CE_CMD_CTRL, ~CMD_CTRL_BREAK);
for (timeout = 10000000; timeout; timeout--) {
if (!(sh_mmcif_readl(host->addr, MMCIF_CE_HOST_STS1)
& STS1_CMDSEQ))
break;
mdelay(1);
}
if (!timeout) {
dev_err(dev,
"Forced end of command sequence timeout err\n");
return -EIO;
}
sh_mmcif_sync_reset(host);
dev_dbg(dev, "Forced end of command sequence\n");
return -EIO;
}
if (state2 & STS2_CRC_ERR) {
dev_err(dev, " CRC error: state %u, wait %u\n",
host->state, host->wait_for);
ret = -EIO;
} else if (state2 & STS2_TIMEOUT_ERR) {
dev_err(dev, " Timeout: state %u, wait %u\n",
host->state, host->wait_for);
ret = -ETIMEDOUT;
} else {
dev_dbg(dev, " End/Index error: state %u, wait %u\n",
host->state, host->wait_for);
ret = -EIO;
}
return ret;
}
static bool sh_mmcif_next_block(struct sh_mmcif_host *host, u32 *p)
{
struct mmc_data *data = host->mrq->data;
host->sg_blkidx += host->blocksize;
BUG_ON(host->sg_blkidx > data->sg->length);
if (host->sg_blkidx == data->sg->length) {
host->sg_blkidx = 0;
if (++host->sg_idx < data->sg_len)
host->pio_ptr = sg_virt(++data->sg);
} else {
host->pio_ptr = p;
}
return host->sg_idx != data->sg_len;
}
static void sh_mmcif_single_read(struct sh_mmcif_host *host,
struct mmc_request *mrq)
{
host->blocksize = (sh_mmcif_readl(host->addr, MMCIF_CE_BLOCK_SET) &
BLOCK_SIZE_MASK) + 3;
host->wait_for = MMCIF_WAIT_FOR_READ;
sh_mmcif_bitset(host, MMCIF_CE_INT_MASK, MASK_MBUFREN);
}
static bool sh_mmcif_read_block(struct sh_mmcif_host *host)
{
struct device *dev = sh_mmcif_host_to_dev(host);
struct mmc_data *data = host->mrq->data;
u32 *p = sg_virt(data->sg);
int i;
if (host->sd_error) {
data->error = sh_mmcif_error_manage(host);
dev_dbg(dev, "%s(): %d\n", __func__, data->error);
return false;
}
for (i = 0; i < host->blocksize / 4; i++)
*p++ = sh_mmcif_readl(host->addr, MMCIF_CE_DATA);
sh_mmcif_bitset(host, MMCIF_CE_INT_MASK, MASK_MBUFRE);
host->wait_for = MMCIF_WAIT_FOR_READ_END;
return true;
}
static void sh_mmcif_multi_read(struct sh_mmcif_host *host,
struct mmc_request *mrq)
{
struct mmc_data *data = mrq->data;
if (!data->sg_len || !data->sg->length)
return;
host->blocksize = sh_mmcif_readl(host->addr, MMCIF_CE_BLOCK_SET) &
BLOCK_SIZE_MASK;
host->wait_for = MMCIF_WAIT_FOR_MREAD;
host->sg_idx = 0;
host->sg_blkidx = 0;
host->pio_ptr = sg_virt(data->sg);
sh_mmcif_bitset(host, MMCIF_CE_INT_MASK, MASK_MBUFREN);
}
static bool sh_mmcif_mread_block(struct sh_mmcif_host *host)
{
struct device *dev = sh_mmcif_host_to_dev(host);
struct mmc_data *data = host->mrq->data;
u32 *p = host->pio_ptr;
int i;
if (host->sd_error) {
data->error = sh_mmcif_error_manage(host);
dev_dbg(dev, "%s(): %d\n", __func__, data->error);
return false;
}
BUG_ON(!data->sg->length);
for (i = 0; i < host->blocksize / 4; i++)
*p++ = sh_mmcif_readl(host->addr, MMCIF_CE_DATA);
if (!sh_mmcif_next_block(host, p))
return false;
sh_mmcif_bitset(host, MMCIF_CE_INT_MASK, MASK_MBUFREN);
return true;
}
static void sh_mmcif_single_write(struct sh_mmcif_host *host,
struct mmc_request *mrq)
{
host->blocksize = (sh_mmcif_readl(host->addr, MMCIF_CE_BLOCK_SET) &
BLOCK_SIZE_MASK) + 3;
host->wait_for = MMCIF_WAIT_FOR_WRITE;
sh_mmcif_bitset(host, MMCIF_CE_INT_MASK, MASK_MBUFWEN);
}
static bool sh_mmcif_write_block(struct sh_mmcif_host *host)
{
struct device *dev = sh_mmcif_host_to_dev(host);
struct mmc_data *data = host->mrq->data;
u32 *p = sg_virt(data->sg);
int i;
if (host->sd_error) {
data->error = sh_mmcif_error_manage(host);
dev_dbg(dev, "%s(): %d\n", __func__, data->error);
return false;
}
for (i = 0; i < host->blocksize / 4; i++)
sh_mmcif_writel(host->addr, MMCIF_CE_DATA, *p++);
sh_mmcif_bitset(host, MMCIF_CE_INT_MASK, MASK_MDTRANE);
host->wait_for = MMCIF_WAIT_FOR_WRITE_END;
return true;
}
static void sh_mmcif_multi_write(struct sh_mmcif_host *host,
struct mmc_request *mrq)
{
struct mmc_data *data = mrq->data;
if (!data->sg_len || !data->sg->length)
return;
host->blocksize = sh_mmcif_readl(host->addr, MMCIF_CE_BLOCK_SET) &
BLOCK_SIZE_MASK;
host->wait_for = MMCIF_WAIT_FOR_MWRITE;
host->sg_idx = 0;
host->sg_blkidx = 0;
host->pio_ptr = sg_virt(data->sg);
sh_mmcif_bitset(host, MMCIF_CE_INT_MASK, MASK_MBUFWEN);
}
static bool sh_mmcif_mwrite_block(struct sh_mmcif_host *host)
{
struct device *dev = sh_mmcif_host_to_dev(host);
struct mmc_data *data = host->mrq->data;
u32 *p = host->pio_ptr;
int i;
if (host->sd_error) {
data->error = sh_mmcif_error_manage(host);
dev_dbg(dev, "%s(): %d\n", __func__, data->error);
return false;
}
BUG_ON(!data->sg->length);
for (i = 0; i < host->blocksize / 4; i++)
sh_mmcif_writel(host->addr, MMCIF_CE_DATA, *p++);
if (!sh_mmcif_next_block(host, p))
return false;
sh_mmcif_bitset(host, MMCIF_CE_INT_MASK, MASK_MBUFWEN);
return true;
}
static void sh_mmcif_get_response(struct sh_mmcif_host *host,
struct mmc_command *cmd)
{
if (cmd->flags & MMC_RSP_136) {
cmd->resp[0] = sh_mmcif_readl(host->addr, MMCIF_CE_RESP3);
cmd->resp[1] = sh_mmcif_readl(host->addr, MMCIF_CE_RESP2);
cmd->resp[2] = sh_mmcif_readl(host->addr, MMCIF_CE_RESP1);
cmd->resp[3] = sh_mmcif_readl(host->addr, MMCIF_CE_RESP0);
} else
cmd->resp[0] = sh_mmcif_readl(host->addr, MMCIF_CE_RESP0);
}
static void sh_mmcif_get_cmd12response(struct sh_mmcif_host *host,
struct mmc_command *cmd)
{
cmd->resp[0] = sh_mmcif_readl(host->addr, MMCIF_CE_RESP_CMD12);
}
static u32 sh_mmcif_set_cmd(struct sh_mmcif_host *host,
struct mmc_request *mrq)
{
struct device *dev = sh_mmcif_host_to_dev(host);
struct mmc_data *data = mrq->data;
struct mmc_command *cmd = mrq->cmd;
u32 opc = cmd->opcode;
u32 tmp = 0;
switch (mmc_resp_type(cmd)) {
case MMC_RSP_NONE:
tmp |= CMD_SET_RTYP_NO;
break;
case MMC_RSP_R1:
case MMC_RSP_R1B:
case MMC_RSP_R3:
tmp |= CMD_SET_RTYP_6B;
break;
case MMC_RSP_R2:
tmp |= CMD_SET_RTYP_17B;
break;
default:
dev_err(dev, "Unsupported response type.\n");
break;
}
switch (opc) {
case MMC_SLEEP_AWAKE:
case MMC_SWITCH:
case MMC_STOP_TRANSMISSION:
case MMC_SET_WRITE_PROT:
case MMC_CLR_WRITE_PROT:
case MMC_ERASE:
tmp |= CMD_SET_RBSY;
break;
}
if (data) {
tmp |= CMD_SET_WDAT;
switch (host->bus_width) {
case MMC_BUS_WIDTH_1:
tmp |= CMD_SET_DATW_1;
break;
case MMC_BUS_WIDTH_4:
tmp |= CMD_SET_DATW_4;
break;
case MMC_BUS_WIDTH_8:
tmp |= CMD_SET_DATW_8;
break;
default:
dev_err(dev, "Unsupported bus width.\n");
break;
}
switch (host->timing) {
case MMC_TIMING_MMC_DDR52:
tmp |= CMD_SET_DARS;
break;
}
}
if (opc == MMC_WRITE_BLOCK || opc == MMC_WRITE_MULTIPLE_BLOCK)
tmp |= CMD_SET_DWEN;
if (opc == MMC_READ_MULTIPLE_BLOCK || opc == MMC_WRITE_MULTIPLE_BLOCK) {
tmp |= CMD_SET_CMLTE | CMD_SET_CMD12EN;
sh_mmcif_bitset(host, MMCIF_CE_BLOCK_SET,
data->blocks << 16);
}
if (opc == MMC_SEND_OP_COND || opc == MMC_ALL_SEND_CID ||
opc == MMC_SEND_CSD || opc == MMC_SEND_CID)
tmp |= CMD_SET_RIDXC_BITS;
if (opc == MMC_SEND_OP_COND)
tmp |= CMD_SET_CRC7C_BITS;
if (opc == MMC_ALL_SEND_CID ||
opc == MMC_SEND_CSD || opc == MMC_SEND_CID)
tmp |= CMD_SET_CRC7C_INTERNAL;
return (opc << 24) | tmp;
}
static int sh_mmcif_data_trans(struct sh_mmcif_host *host,
struct mmc_request *mrq, u32 opc)
{
struct device *dev = sh_mmcif_host_to_dev(host);
switch (opc) {
case MMC_READ_MULTIPLE_BLOCK:
sh_mmcif_multi_read(host, mrq);
return 0;
case MMC_WRITE_MULTIPLE_BLOCK:
sh_mmcif_multi_write(host, mrq);
return 0;
case MMC_WRITE_BLOCK:
sh_mmcif_single_write(host, mrq);
return 0;
case MMC_READ_SINGLE_BLOCK:
case MMC_SEND_EXT_CSD:
sh_mmcif_single_read(host, mrq);
return 0;
default:
dev_err(dev, "Unsupported CMD%d\n", opc);
return -EINVAL;
}
}
static void sh_mmcif_start_cmd(struct sh_mmcif_host *host,
struct mmc_request *mrq)
{
struct mmc_command *cmd = mrq->cmd;
u32 opc = cmd->opcode;
u32 mask;
unsigned long flags;
switch (opc) {
case MMC_SLEEP_AWAKE:
case MMC_SWITCH:
case MMC_STOP_TRANSMISSION:
case MMC_SET_WRITE_PROT:
case MMC_CLR_WRITE_PROT:
case MMC_ERASE:
mask = MASK_START_CMD | MASK_MRBSYE;
break;
default:
mask = MASK_START_CMD | MASK_MCRSPE;
break;
}
if (host->ccs_enable)
mask |= MASK_MCCSTO;
if (mrq->data) {
sh_mmcif_writel(host->addr, MMCIF_CE_BLOCK_SET, 0);
sh_mmcif_writel(host->addr, MMCIF_CE_BLOCK_SET,
mrq->data->blksz);
}
opc = sh_mmcif_set_cmd(host, mrq);
if (host->ccs_enable)
sh_mmcif_writel(host->addr, MMCIF_CE_INT, 0xD80430C0);
else
sh_mmcif_writel(host->addr, MMCIF_CE_INT, 0xD80430C0 | INT_CCS);
sh_mmcif_writel(host->addr, MMCIF_CE_INT_MASK, mask);
sh_mmcif_writel(host->addr, MMCIF_CE_ARG, cmd->arg);
spin_lock_irqsave(&host->lock, flags);
sh_mmcif_writel(host->addr, MMCIF_CE_CMD_SET, opc);
host->wait_for = MMCIF_WAIT_FOR_CMD;
schedule_delayed_work(&host->timeout_work, host->timeout);
spin_unlock_irqrestore(&host->lock, flags);
}
static void sh_mmcif_stop_cmd(struct sh_mmcif_host *host,
struct mmc_request *mrq)
{
struct device *dev = sh_mmcif_host_to_dev(host);
switch (mrq->cmd->opcode) {
case MMC_READ_MULTIPLE_BLOCK:
sh_mmcif_bitset(host, MMCIF_CE_INT_MASK, MASK_MCMD12DRE);
break;
case MMC_WRITE_MULTIPLE_BLOCK:
sh_mmcif_bitset(host, MMCIF_CE_INT_MASK, MASK_MCMD12RBE);
break;
default:
dev_err(dev, "unsupported stop cmd\n");
mrq->stop->error = sh_mmcif_error_manage(host);
return;
}
host->wait_for = MMCIF_WAIT_FOR_STOP;
}
static void sh_mmcif_request(struct mmc_host *mmc, struct mmc_request *mrq)
{
struct sh_mmcif_host *host = mmc_priv(mmc);
struct device *dev = sh_mmcif_host_to_dev(host);
unsigned long flags;
spin_lock_irqsave(&host->lock, flags);
if (host->state != STATE_IDLE) {
dev_dbg(dev, "%s() rejected, state %u\n",
__func__, host->state);
spin_unlock_irqrestore(&host->lock, flags);
mrq->cmd->error = -EAGAIN;
mmc_request_done(mmc, mrq);
return;
}
host->state = STATE_REQUEST;
spin_unlock_irqrestore(&host->lock, flags);
switch (mrq->cmd->opcode) {
case MMC_SLEEP_AWAKE:
case MMC_SEND_EXT_CSD:
if ((mrq->cmd->flags & MMC_CMD_MASK) != MMC_CMD_BCR)
break;
case MMC_APP_CMD:
case SD_IO_RW_DIRECT:
host->state = STATE_IDLE;
mrq->cmd->error = -ETIMEDOUT;
mmc_request_done(mmc, mrq);
return;
default:
break;
}
host->mrq = mrq;
sh_mmcif_start_cmd(host, mrq);
}
static void sh_mmcif_clk_setup(struct sh_mmcif_host *host)
{
struct device *dev = sh_mmcif_host_to_dev(host);
if (host->mmc->f_max) {
unsigned int f_max, f_min = 0, f_min_old;
f_max = host->mmc->f_max;
for (f_min_old = f_max; f_min_old > 2;) {
f_min = clk_round_rate(host->clk, f_min_old / 2);
if (f_min == f_min_old)
break;
f_min_old = f_min;
}
host->clkdiv_map = 0x3ff;
host->mmc->f_max = f_max / (1 << ffs(host->clkdiv_map));
host->mmc->f_min = f_min / (1 << fls(host->clkdiv_map));
} else {
unsigned int clk = clk_get_rate(host->clk);
host->mmc->f_max = clk / 2;
host->mmc->f_min = clk / 512;
}
dev_dbg(dev, "clk max/min = %d/%d\n",
host->mmc->f_max, host->mmc->f_min);
}
static void sh_mmcif_set_ios(struct mmc_host *mmc, struct mmc_ios *ios)
{
struct sh_mmcif_host *host = mmc_priv(mmc);
struct device *dev = sh_mmcif_host_to_dev(host);
unsigned long flags;
spin_lock_irqsave(&host->lock, flags);
if (host->state != STATE_IDLE) {
dev_dbg(dev, "%s() rejected, state %u\n",
__func__, host->state);
spin_unlock_irqrestore(&host->lock, flags);
return;
}
host->state = STATE_IOS;
spin_unlock_irqrestore(&host->lock, flags);
switch (ios->power_mode) {
case MMC_POWER_UP:
if (!IS_ERR(mmc->supply.vmmc))
mmc_regulator_set_ocr(mmc, mmc->supply.vmmc, ios->vdd);
if (!host->power) {
clk_prepare_enable(host->clk);
pm_runtime_get_sync(dev);
sh_mmcif_sync_reset(host);
sh_mmcif_request_dma(host);
host->power = true;
}
break;
case MMC_POWER_OFF:
if (!IS_ERR(mmc->supply.vmmc))
mmc_regulator_set_ocr(mmc, mmc->supply.vmmc, 0);
if (host->power) {
sh_mmcif_clock_control(host, 0);
sh_mmcif_release_dma(host);
pm_runtime_put(dev);
clk_disable_unprepare(host->clk);
host->power = false;
}
break;
case MMC_POWER_ON:
sh_mmcif_clock_control(host, ios->clock);
break;
}
host->timing = ios->timing;
host->bus_width = ios->bus_width;
host->state = STATE_IDLE;
}
static int sh_mmcif_get_cd(struct mmc_host *mmc)
{
struct sh_mmcif_host *host = mmc_priv(mmc);
struct device *dev = sh_mmcif_host_to_dev(host);
struct sh_mmcif_plat_data *p = dev->platform_data;
int ret = mmc_gpio_get_cd(mmc);
if (ret >= 0)
return ret;
if (!p || !p->get_cd)
return -ENOSYS;
else
return p->get_cd(host->pd);
}
static bool sh_mmcif_end_cmd(struct sh_mmcif_host *host)
{
struct mmc_command *cmd = host->mrq->cmd;
struct mmc_data *data = host->mrq->data;
struct device *dev = sh_mmcif_host_to_dev(host);
long time;
if (host->sd_error) {
switch (cmd->opcode) {
case MMC_ALL_SEND_CID:
case MMC_SELECT_CARD:
case MMC_APP_CMD:
cmd->error = -ETIMEDOUT;
break;
default:
cmd->error = sh_mmcif_error_manage(host);
break;
}
dev_dbg(dev, "CMD%d error %d\n",
cmd->opcode, cmd->error);
host->sd_error = false;
return false;
}
if (!(cmd->flags & MMC_RSP_PRESENT)) {
cmd->error = 0;
return false;
}
sh_mmcif_get_response(host, cmd);
if (!data)
return false;
init_completion(&host->dma_complete);
if (data->flags & MMC_DATA_READ) {
if (host->chan_rx)
sh_mmcif_start_dma_rx(host);
} else {
if (host->chan_tx)
sh_mmcif_start_dma_tx(host);
}
if (!host->dma_active) {
data->error = sh_mmcif_data_trans(host, host->mrq, cmd->opcode);
return !data->error;
}
time = wait_for_completion_interruptible_timeout(&host->dma_complete,
host->timeout);
if (data->flags & MMC_DATA_READ)
dma_unmap_sg(host->chan_rx->device->dev,
data->sg, data->sg_len,
DMA_FROM_DEVICE);
else
dma_unmap_sg(host->chan_tx->device->dev,
data->sg, data->sg_len,
DMA_TO_DEVICE);
if (host->sd_error) {
dev_err(host->mmc->parent,
"Error IRQ while waiting for DMA completion!\n");
data->error = sh_mmcif_error_manage(host);
} else if (!time) {
dev_err(host->mmc->parent, "DMA timeout!\n");
data->error = -ETIMEDOUT;
} else if (time < 0) {
dev_err(host->mmc->parent,
"wait_for_completion_...() error %ld!\n", time);
data->error = time;
}
sh_mmcif_bitclr(host, MMCIF_CE_BUF_ACC,
BUF_ACC_DMAREN | BUF_ACC_DMAWEN);
host->dma_active = false;
if (data->error) {
data->bytes_xfered = 0;
if (data->flags & MMC_DATA_READ)
dmaengine_terminate_all(host->chan_rx);
else
dmaengine_terminate_all(host->chan_tx);
}
return false;
}
static irqreturn_t sh_mmcif_irqt(int irq, void *dev_id)
{
struct sh_mmcif_host *host = dev_id;
struct mmc_request *mrq;
struct device *dev = sh_mmcif_host_to_dev(host);
bool wait = false;
unsigned long flags;
int wait_work;
spin_lock_irqsave(&host->lock, flags);
wait_work = host->wait_for;
spin_unlock_irqrestore(&host->lock, flags);
cancel_delayed_work_sync(&host->timeout_work);
mutex_lock(&host->thread_lock);
mrq = host->mrq;
if (!mrq) {
dev_dbg(dev, "IRQ thread state %u, wait %u: NULL mrq!\n",
host->state, host->wait_for);
mutex_unlock(&host->thread_lock);
return IRQ_HANDLED;
}
switch (wait_work) {
case MMCIF_WAIT_FOR_REQUEST:
mutex_unlock(&host->thread_lock);
return IRQ_HANDLED;
case MMCIF_WAIT_FOR_CMD:
wait = sh_mmcif_end_cmd(host);
break;
case MMCIF_WAIT_FOR_MREAD:
wait = sh_mmcif_mread_block(host);
break;
case MMCIF_WAIT_FOR_READ:
wait = sh_mmcif_read_block(host);
break;
case MMCIF_WAIT_FOR_MWRITE:
wait = sh_mmcif_mwrite_block(host);
break;
case MMCIF_WAIT_FOR_WRITE:
wait = sh_mmcif_write_block(host);
break;
case MMCIF_WAIT_FOR_STOP:
if (host->sd_error) {
mrq->stop->error = sh_mmcif_error_manage(host);
dev_dbg(dev, "%s(): %d\n", __func__, mrq->stop->error);
break;
}
sh_mmcif_get_cmd12response(host, mrq->stop);
mrq->stop->error = 0;
break;
case MMCIF_WAIT_FOR_READ_END:
case MMCIF_WAIT_FOR_WRITE_END:
if (host->sd_error) {
mrq->data->error = sh_mmcif_error_manage(host);
dev_dbg(dev, "%s(): %d\n", __func__, mrq->data->error);
}
break;
default:
BUG();
}
if (wait) {
schedule_delayed_work(&host->timeout_work, host->timeout);
mutex_unlock(&host->thread_lock);
return IRQ_HANDLED;
}
if (host->wait_for != MMCIF_WAIT_FOR_STOP) {
struct mmc_data *data = mrq->data;
if (!mrq->cmd->error && data && !data->error)
data->bytes_xfered =
data->blocks * data->blksz;
if (mrq->stop && !mrq->cmd->error && (!data || !data->error)) {
sh_mmcif_stop_cmd(host, mrq);
if (!mrq->stop->error) {
schedule_delayed_work(&host->timeout_work, host->timeout);
mutex_unlock(&host->thread_lock);
return IRQ_HANDLED;
}
}
}
host->wait_for = MMCIF_WAIT_FOR_REQUEST;
host->state = STATE_IDLE;
host->mrq = NULL;
mmc_request_done(host->mmc, mrq);
mutex_unlock(&host->thread_lock);
return IRQ_HANDLED;
}
static irqreturn_t sh_mmcif_intr(int irq, void *dev_id)
{
struct sh_mmcif_host *host = dev_id;
struct device *dev = sh_mmcif_host_to_dev(host);
u32 state, mask;
state = sh_mmcif_readl(host->addr, MMCIF_CE_INT);
mask = sh_mmcif_readl(host->addr, MMCIF_CE_INT_MASK);
if (host->ccs_enable)
sh_mmcif_writel(host->addr, MMCIF_CE_INT, ~(state & mask));
else
sh_mmcif_writel(host->addr, MMCIF_CE_INT, INT_CCS | ~(state & mask));
sh_mmcif_bitclr(host, MMCIF_CE_INT_MASK, state & MASK_CLEAN);
if (state & ~MASK_CLEAN)
dev_dbg(dev, "IRQ state = 0x%08x incompletely cleared\n",
state);
if (state & INT_ERR_STS || state & ~INT_ALL) {
host->sd_error = true;
dev_dbg(dev, "int err state = 0x%08x\n", state);
}
if (state & ~(INT_CMD12RBE | INT_CMD12CRE)) {
if (!host->mrq)
dev_dbg(dev, "NULL IRQ state = 0x%08x\n", state);
if (!host->dma_active)
return IRQ_WAKE_THREAD;
else if (host->sd_error)
sh_mmcif_dma_complete(host);
} else {
dev_dbg(dev, "Unexpected IRQ 0x%x\n", state);
}
return IRQ_HANDLED;
}
static void sh_mmcif_timeout_work(struct work_struct *work)
{
struct delayed_work *d = to_delayed_work(work);
struct sh_mmcif_host *host = container_of(d, struct sh_mmcif_host, timeout_work);
struct mmc_request *mrq = host->mrq;
struct device *dev = sh_mmcif_host_to_dev(host);
unsigned long flags;
if (host->dying)
return;
spin_lock_irqsave(&host->lock, flags);
if (host->state == STATE_IDLE) {
spin_unlock_irqrestore(&host->lock, flags);
return;
}
dev_err(dev, "Timeout waiting for %u on CMD%u\n",
host->wait_for, mrq->cmd->opcode);
host->state = STATE_TIMEOUT;
spin_unlock_irqrestore(&host->lock, flags);
switch (host->wait_for) {
case MMCIF_WAIT_FOR_CMD:
mrq->cmd->error = sh_mmcif_error_manage(host);
break;
case MMCIF_WAIT_FOR_STOP:
mrq->stop->error = sh_mmcif_error_manage(host);
break;
case MMCIF_WAIT_FOR_MREAD:
case MMCIF_WAIT_FOR_MWRITE:
case MMCIF_WAIT_FOR_READ:
case MMCIF_WAIT_FOR_WRITE:
case MMCIF_WAIT_FOR_READ_END:
case MMCIF_WAIT_FOR_WRITE_END:
mrq->data->error = sh_mmcif_error_manage(host);
break;
default:
BUG();
}
host->state = STATE_IDLE;
host->wait_for = MMCIF_WAIT_FOR_REQUEST;
host->mrq = NULL;
mmc_request_done(host->mmc, mrq);
}
static void sh_mmcif_init_ocr(struct sh_mmcif_host *host)
{
struct device *dev = sh_mmcif_host_to_dev(host);
struct sh_mmcif_plat_data *pd = dev->platform_data;
struct mmc_host *mmc = host->mmc;
mmc_regulator_get_supply(mmc);
if (!pd)
return;
if (!mmc->ocr_avail)
mmc->ocr_avail = pd->ocr;
else if (pd->ocr)
dev_warn(mmc_dev(mmc), "Platform OCR mask is ignored\n");
}
static int sh_mmcif_probe(struct platform_device *pdev)
{
int ret = 0, irq[2];
struct mmc_host *mmc;
struct sh_mmcif_host *host;
struct device *dev = &pdev->dev;
struct sh_mmcif_plat_data *pd = dev->platform_data;
struct resource *res;
void __iomem *reg;
const char *name;
irq[0] = platform_get_irq(pdev, 0);
irq[1] = platform_get_irq(pdev, 1);
if (irq[0] < 0) {
dev_err(dev, "Get irq error\n");
return -ENXIO;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
reg = devm_ioremap_resource(dev, res);
if (IS_ERR(reg))
return PTR_ERR(reg);
mmc = mmc_alloc_host(sizeof(struct sh_mmcif_host), dev);
if (!mmc)
return -ENOMEM;
ret = mmc_of_parse(mmc);
if (ret < 0)
goto err_host;
host = mmc_priv(mmc);
host->mmc = mmc;
host->addr = reg;
host->timeout = msecs_to_jiffies(10000);
host->ccs_enable = !pd || !pd->ccs_unsupported;
host->clk_ctrl2_enable = pd && pd->clk_ctrl2_present;
host->pd = pdev;
spin_lock_init(&host->lock);
mmc->ops = &sh_mmcif_ops;
sh_mmcif_init_ocr(host);
mmc->caps |= MMC_CAP_MMC_HIGHSPEED | MMC_CAP_WAIT_WHILE_BUSY;
if (pd && pd->caps)
mmc->caps |= pd->caps;
mmc->max_segs = 32;
mmc->max_blk_size = 512;
mmc->max_req_size = PAGE_SIZE * mmc->max_segs;
mmc->max_blk_count = mmc->max_req_size / mmc->max_blk_size;
mmc->max_seg_size = mmc->max_req_size;
platform_set_drvdata(pdev, host);
host->clk = devm_clk_get(dev, NULL);
if (IS_ERR(host->clk)) {
ret = PTR_ERR(host->clk);
dev_err(dev, "cannot get clock: %d\n", ret);
goto err_host;
}
ret = clk_prepare_enable(host->clk);
if (ret < 0)
goto err_host;
sh_mmcif_clk_setup(host);
pm_runtime_enable(dev);
host->power = false;
ret = pm_runtime_get_sync(dev);
if (ret < 0)
goto err_clk;
INIT_DELAYED_WORK(&host->timeout_work, sh_mmcif_timeout_work);
sh_mmcif_sync_reset(host);
sh_mmcif_writel(host->addr, MMCIF_CE_INT_MASK, MASK_ALL);
name = irq[1] < 0 ? dev_name(dev) : "sh_mmc:error";
ret = devm_request_threaded_irq(dev, irq[0], sh_mmcif_intr,
sh_mmcif_irqt, 0, name, host);
if (ret) {
dev_err(dev, "request_irq error (%s)\n", name);
goto err_clk;
}
if (irq[1] >= 0) {
ret = devm_request_threaded_irq(dev, irq[1],
sh_mmcif_intr, sh_mmcif_irqt,
0, "sh_mmc:int", host);
if (ret) {
dev_err(dev, "request_irq error (sh_mmc:int)\n");
goto err_clk;
}
}
if (pd && pd->use_cd_gpio) {
ret = mmc_gpio_request_cd(mmc, pd->cd_gpio, 0);
if (ret < 0)
goto err_clk;
}
mutex_init(&host->thread_lock);
ret = mmc_add_host(mmc);
if (ret < 0)
goto err_clk;
dev_pm_qos_expose_latency_limit(dev, 100);
dev_info(dev, "Chip version 0x%04x, clock rate %luMHz\n",
sh_mmcif_readl(host->addr, MMCIF_CE_VERSION) & 0xffff,
clk_get_rate(host->clk) / 1000000UL);
pm_runtime_put(dev);
clk_disable_unprepare(host->clk);
return ret;
err_clk:
clk_disable_unprepare(host->clk);
pm_runtime_put_sync(dev);
pm_runtime_disable(dev);
err_host:
mmc_free_host(mmc);
return ret;
}
static int sh_mmcif_remove(struct platform_device *pdev)
{
struct sh_mmcif_host *host = platform_get_drvdata(pdev);
host->dying = true;
clk_prepare_enable(host->clk);
pm_runtime_get_sync(&pdev->dev);
dev_pm_qos_hide_latency_limit(&pdev->dev);
mmc_remove_host(host->mmc);
sh_mmcif_writel(host->addr, MMCIF_CE_INT_MASK, MASK_ALL);
cancel_delayed_work_sync(&host->timeout_work);
clk_disable_unprepare(host->clk);
mmc_free_host(host->mmc);
pm_runtime_put_sync(&pdev->dev);
pm_runtime_disable(&pdev->dev);
return 0;
}
static int sh_mmcif_suspend(struct device *dev)
{
struct sh_mmcif_host *host = dev_get_drvdata(dev);
pm_runtime_get_sync(dev);
sh_mmcif_writel(host->addr, MMCIF_CE_INT_MASK, MASK_ALL);
pm_runtime_put(dev);
return 0;
}
static int sh_mmcif_resume(struct device *dev)
{
return 0;
}
