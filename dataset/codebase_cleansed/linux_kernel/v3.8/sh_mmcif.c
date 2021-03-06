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
static void mmcif_dma_complete(void *arg)
{
struct sh_mmcif_host *host = arg;
struct mmc_data *data = host->mrq->data;
dev_dbg(&host->pd->dev, "Command completed\n");
if (WARN(!data, "%s: NULL data in DMA completion!\n",
dev_name(&host->pd->dev)))
return;
if (data->flags & MMC_DATA_READ)
dma_unmap_sg(host->chan_rx->device->dev,
data->sg, data->sg_len,
DMA_FROM_DEVICE);
else
dma_unmap_sg(host->chan_tx->device->dev,
data->sg, data->sg_len,
DMA_TO_DEVICE);
complete(&host->dma_complete);
}
static void sh_mmcif_start_dma_rx(struct sh_mmcif_host *host)
{
struct mmc_data *data = host->mrq->data;
struct scatterlist *sg = data->sg;
struct dma_async_tx_descriptor *desc = NULL;
struct dma_chan *chan = host->chan_rx;
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
desc->callback = mmcif_dma_complete;
desc->callback_param = host;
cookie = dmaengine_submit(desc);
sh_mmcif_bitset(host, MMCIF_CE_BUF_ACC, BUF_ACC_DMAREN);
dma_async_issue_pending(chan);
}
dev_dbg(&host->pd->dev, "%s(): mapped %d -> %d, cookie %d\n",
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
dev_warn(&host->pd->dev,
"DMA failed: %d, falling back to PIO\n", ret);
sh_mmcif_bitclr(host, MMCIF_CE_BUF_ACC, BUF_ACC_DMAREN | BUF_ACC_DMAWEN);
}
dev_dbg(&host->pd->dev, "%s(): desc %p, cookie %d, sg[%d]\n", __func__,
desc, cookie, data->sg_len);
}
static void sh_mmcif_start_dma_tx(struct sh_mmcif_host *host)
{
struct mmc_data *data = host->mrq->data;
struct scatterlist *sg = data->sg;
struct dma_async_tx_descriptor *desc = NULL;
struct dma_chan *chan = host->chan_tx;
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
desc->callback = mmcif_dma_complete;
desc->callback_param = host;
cookie = dmaengine_submit(desc);
sh_mmcif_bitset(host, MMCIF_CE_BUF_ACC, BUF_ACC_DMAWEN);
dma_async_issue_pending(chan);
}
dev_dbg(&host->pd->dev, "%s(): mapped %d -> %d, cookie %d\n",
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
dev_warn(&host->pd->dev,
"DMA failed: %d, falling back to PIO\n", ret);
sh_mmcif_bitclr(host, MMCIF_CE_BUF_ACC, BUF_ACC_DMAREN | BUF_ACC_DMAWEN);
}
dev_dbg(&host->pd->dev, "%s(): desc %p, cookie %d\n", __func__,
desc, cookie);
}
static void sh_mmcif_request_dma(struct sh_mmcif_host *host,
struct sh_mmcif_plat_data *pdata)
{
struct resource *res = platform_get_resource(host->pd, IORESOURCE_MEM, 0);
struct dma_slave_config cfg;
dma_cap_mask_t mask;
int ret;
host->dma_active = false;
if (!pdata)
return;
if (pdata->slave_id_tx <= 0 || pdata->slave_id_rx <= 0)
return;
dma_cap_zero(mask);
dma_cap_set(DMA_SLAVE, mask);
host->chan_tx = dma_request_channel(mask, shdma_chan_filter,
(void *)pdata->slave_id_tx);
dev_dbg(&host->pd->dev, "%s: TX: got channel %p\n", __func__,
host->chan_tx);
if (!host->chan_tx)
return;
cfg.slave_id = pdata->slave_id_tx;
cfg.direction = DMA_MEM_TO_DEV;
cfg.dst_addr = res->start + MMCIF_CE_DATA;
cfg.src_addr = 0;
ret = dmaengine_slave_config(host->chan_tx, &cfg);
if (ret < 0)
goto ecfgtx;
host->chan_rx = dma_request_channel(mask, shdma_chan_filter,
(void *)pdata->slave_id_rx);
dev_dbg(&host->pd->dev, "%s: RX: got channel %p\n", __func__,
host->chan_rx);
if (!host->chan_rx)
goto erqrx;
cfg.slave_id = pdata->slave_id_rx;
cfg.direction = DMA_DEV_TO_MEM;
cfg.dst_addr = 0;
cfg.src_addr = res->start + MMCIF_CE_DATA;
ret = dmaengine_slave_config(host->chan_rx, &cfg);
if (ret < 0)
goto ecfgrx;
init_completion(&host->dma_complete);
return;
ecfgrx:
dma_release_channel(host->chan_rx);
host->chan_rx = NULL;
erqrx:
ecfgtx:
dma_release_channel(host->chan_tx);
host->chan_tx = NULL;
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
struct sh_mmcif_plat_data *p = host->pd->dev.platform_data;
bool sup_pclk = p ? p->sup_pclk : false;
sh_mmcif_bitclr(host, MMCIF_CE_CLK_CTRL, CLK_ENABLE);
sh_mmcif_bitclr(host, MMCIF_CE_CLK_CTRL, CLK_CLEAR);
if (!clk)
return;
if (sup_pclk && clk == host->clk)
sh_mmcif_bitset(host, MMCIF_CE_CLK_CTRL, CLK_SUP_PCLK);
else
sh_mmcif_bitset(host, MMCIF_CE_CLK_CTRL, CLK_CLEAR &
((fls(DIV_ROUND_UP(host->clk,
clk) - 1) - 1) << 16));
sh_mmcif_bitset(host, MMCIF_CE_CLK_CTRL, CLK_ENABLE);
}
static void sh_mmcif_sync_reset(struct sh_mmcif_host *host)
{
u32 tmp;
tmp = 0x010f0000 & sh_mmcif_readl(host->addr, MMCIF_CE_CLK_CTRL);
sh_mmcif_writel(host->addr, MMCIF_CE_VERSION, SOFT_RST_ON);
sh_mmcif_writel(host->addr, MMCIF_CE_VERSION, SOFT_RST_OFF);
sh_mmcif_bitset(host, MMCIF_CE_CLK_CTRL, tmp |
SRSPTO_256 | SRBSYTO_29 | SRWDTO_29 | SCCSTO_29);
sh_mmcif_bitset(host, MMCIF_CE_BUF_ACC, BUF_ACC_ATYP);
}
static int sh_mmcif_error_manage(struct sh_mmcif_host *host)
{
u32 state1, state2;
int ret, timeout;
host->sd_error = false;
state1 = sh_mmcif_readl(host->addr, MMCIF_CE_HOST_STS1);
state2 = sh_mmcif_readl(host->addr, MMCIF_CE_HOST_STS2);
dev_dbg(&host->pd->dev, "ERR HOST_STS1 = %08x\n", state1);
dev_dbg(&host->pd->dev, "ERR HOST_STS2 = %08x\n", state2);
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
dev_err(&host->pd->dev,
"Forced end of command sequence timeout err\n");
return -EIO;
}
sh_mmcif_sync_reset(host);
dev_dbg(&host->pd->dev, "Forced end of command sequence\n");
return -EIO;
}
if (state2 & STS2_CRC_ERR) {
dev_dbg(&host->pd->dev, ": CRC error\n");
ret = -EIO;
} else if (state2 & STS2_TIMEOUT_ERR) {
dev_dbg(&host->pd->dev, ": Timeout\n");
ret = -ETIMEDOUT;
} else {
dev_dbg(&host->pd->dev, ": End/Index error\n");
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
if (host->sg_idx == data->sg_len)
return false;
return true;
}
static void sh_mmcif_single_read(struct sh_mmcif_host *host,
struct mmc_request *mrq)
{
host->blocksize = (sh_mmcif_readl(host->addr, MMCIF_CE_BLOCK_SET) &
BLOCK_SIZE_MASK) + 3;
host->wait_for = MMCIF_WAIT_FOR_READ;
schedule_delayed_work(&host->timeout_work, host->timeout);
sh_mmcif_bitset(host, MMCIF_CE_INT_MASK, MASK_MBUFREN);
}
static bool sh_mmcif_read_block(struct sh_mmcif_host *host)
{
struct mmc_data *data = host->mrq->data;
u32 *p = sg_virt(data->sg);
int i;
if (host->sd_error) {
data->error = sh_mmcif_error_manage(host);
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
schedule_delayed_work(&host->timeout_work, host->timeout);
sh_mmcif_bitset(host, MMCIF_CE_INT_MASK, MASK_MBUFREN);
}
static bool sh_mmcif_mread_block(struct sh_mmcif_host *host)
{
struct mmc_data *data = host->mrq->data;
u32 *p = host->pio_ptr;
int i;
if (host->sd_error) {
data->error = sh_mmcif_error_manage(host);
return false;
}
BUG_ON(!data->sg->length);
for (i = 0; i < host->blocksize / 4; i++)
*p++ = sh_mmcif_readl(host->addr, MMCIF_CE_DATA);
if (!sh_mmcif_next_block(host, p))
return false;
schedule_delayed_work(&host->timeout_work, host->timeout);
sh_mmcif_bitset(host, MMCIF_CE_INT_MASK, MASK_MBUFREN);
return true;
}
static void sh_mmcif_single_write(struct sh_mmcif_host *host,
struct mmc_request *mrq)
{
host->blocksize = (sh_mmcif_readl(host->addr, MMCIF_CE_BLOCK_SET) &
BLOCK_SIZE_MASK) + 3;
host->wait_for = MMCIF_WAIT_FOR_WRITE;
schedule_delayed_work(&host->timeout_work, host->timeout);
sh_mmcif_bitset(host, MMCIF_CE_INT_MASK, MASK_MBUFWEN);
}
static bool sh_mmcif_write_block(struct sh_mmcif_host *host)
{
struct mmc_data *data = host->mrq->data;
u32 *p = sg_virt(data->sg);
int i;
if (host->sd_error) {
data->error = sh_mmcif_error_manage(host);
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
schedule_delayed_work(&host->timeout_work, host->timeout);
sh_mmcif_bitset(host, MMCIF_CE_INT_MASK, MASK_MBUFWEN);
}
static bool sh_mmcif_mwrite_block(struct sh_mmcif_host *host)
{
struct mmc_data *data = host->mrq->data;
u32 *p = host->pio_ptr;
int i;
if (host->sd_error) {
data->error = sh_mmcif_error_manage(host);
return false;
}
BUG_ON(!data->sg->length);
for (i = 0; i < host->blocksize / 4; i++)
sh_mmcif_writel(host->addr, MMCIF_CE_DATA, *p++);
if (!sh_mmcif_next_block(host, p))
return false;
schedule_delayed_work(&host->timeout_work, host->timeout);
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
dev_err(&host->pd->dev, "Unsupported response type.\n");
break;
}
switch (opc) {
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
dev_err(&host->pd->dev, "Unsupported bus width.\n");
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
dev_err(&host->pd->dev, "UNSUPPORTED CMD = d'%08d\n", opc);
return -EINVAL;
}
}
static void sh_mmcif_start_cmd(struct sh_mmcif_host *host,
struct mmc_request *mrq)
{
struct mmc_command *cmd = mrq->cmd;
u32 opc = cmd->opcode;
u32 mask;
switch (opc) {
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
if (mrq->data) {
sh_mmcif_writel(host->addr, MMCIF_CE_BLOCK_SET, 0);
sh_mmcif_writel(host->addr, MMCIF_CE_BLOCK_SET,
mrq->data->blksz);
}
opc = sh_mmcif_set_cmd(host, mrq);
sh_mmcif_writel(host->addr, MMCIF_CE_INT, 0xD80430C0);
sh_mmcif_writel(host->addr, MMCIF_CE_INT_MASK, mask);
sh_mmcif_writel(host->addr, MMCIF_CE_ARG, cmd->arg);
sh_mmcif_writel(host->addr, MMCIF_CE_CMD_SET, opc);
host->wait_for = MMCIF_WAIT_FOR_CMD;
schedule_delayed_work(&host->timeout_work, host->timeout);
}
static void sh_mmcif_stop_cmd(struct sh_mmcif_host *host,
struct mmc_request *mrq)
{
switch (mrq->cmd->opcode) {
case MMC_READ_MULTIPLE_BLOCK:
sh_mmcif_bitset(host, MMCIF_CE_INT_MASK, MASK_MCMD12DRE);
break;
case MMC_WRITE_MULTIPLE_BLOCK:
sh_mmcif_bitset(host, MMCIF_CE_INT_MASK, MASK_MCMD12RBE);
break;
default:
dev_err(&host->pd->dev, "unsupported stop cmd\n");
mrq->stop->error = sh_mmcif_error_manage(host);
return;
}
host->wait_for = MMCIF_WAIT_FOR_STOP;
schedule_delayed_work(&host->timeout_work, host->timeout);
}
static void sh_mmcif_request(struct mmc_host *mmc, struct mmc_request *mrq)
{
struct sh_mmcif_host *host = mmc_priv(mmc);
unsigned long flags;
spin_lock_irqsave(&host->lock, flags);
if (host->state != STATE_IDLE) {
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
static int sh_mmcif_clk_update(struct sh_mmcif_host *host)
{
int ret = clk_enable(host->hclk);
if (!ret) {
host->clk = clk_get_rate(host->hclk);
host->mmc->f_max = host->clk / 2;
host->mmc->f_min = host->clk / 512;
}
return ret;
}
static void sh_mmcif_set_power(struct sh_mmcif_host *host, struct mmc_ios *ios)
{
struct sh_mmcif_plat_data *pd = host->pd->dev.platform_data;
struct mmc_host *mmc = host->mmc;
if (pd && pd->set_pwr)
pd->set_pwr(host->pd, ios->power_mode != MMC_POWER_OFF);
if (!IS_ERR(mmc->supply.vmmc))
mmc_regulator_set_ocr(mmc, mmc->supply.vmmc,
ios->power_mode ? ios->vdd : 0);
}
static void sh_mmcif_set_ios(struct mmc_host *mmc, struct mmc_ios *ios)
{
struct sh_mmcif_host *host = mmc_priv(mmc);
unsigned long flags;
spin_lock_irqsave(&host->lock, flags);
if (host->state != STATE_IDLE) {
spin_unlock_irqrestore(&host->lock, flags);
return;
}
host->state = STATE_IOS;
spin_unlock_irqrestore(&host->lock, flags);
if (ios->power_mode == MMC_POWER_UP) {
if (!host->card_present) {
sh_mmcif_request_dma(host, host->pd->dev.platform_data);
host->card_present = true;
}
sh_mmcif_set_power(host, ios);
} else if (ios->power_mode == MMC_POWER_OFF || !ios->clock) {
sh_mmcif_clock_control(host, 0);
if (ios->power_mode == MMC_POWER_OFF) {
if (host->card_present) {
sh_mmcif_release_dma(host);
host->card_present = false;
}
}
if (host->power) {
pm_runtime_put(&host->pd->dev);
clk_disable(host->hclk);
host->power = false;
if (ios->power_mode == MMC_POWER_OFF)
sh_mmcif_set_power(host, ios);
}
host->state = STATE_IDLE;
return;
}
if (ios->clock) {
if (!host->power) {
sh_mmcif_clk_update(host);
pm_runtime_get_sync(&host->pd->dev);
host->power = true;
sh_mmcif_sync_reset(host);
}
sh_mmcif_clock_control(host, ios->clock);
}
host->bus_width = ios->bus_width;
host->state = STATE_IDLE;
}
static int sh_mmcif_get_cd(struct mmc_host *mmc)
{
struct sh_mmcif_host *host = mmc_priv(mmc);
struct sh_mmcif_plat_data *p = host->pd->dev.platform_data;
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
long time;
if (host->sd_error) {
switch (cmd->opcode) {
case MMC_ALL_SEND_CID:
case MMC_SELECT_CARD:
case MMC_APP_CMD:
cmd->error = -ETIMEDOUT;
host->sd_error = false;
break;
default:
cmd->error = sh_mmcif_error_manage(host);
dev_dbg(&host->pd->dev, "Cmd(d'%d) error %d\n",
cmd->opcode, cmd->error);
break;
}
return false;
}
if (!(cmd->flags & MMC_RSP_PRESENT)) {
cmd->error = 0;
return false;
}
sh_mmcif_get_response(host, cmd);
if (!data)
return false;
if (data->flags & MMC_DATA_READ) {
if (host->chan_rx)
sh_mmcif_start_dma_rx(host);
} else {
if (host->chan_tx)
sh_mmcif_start_dma_tx(host);
}
if (!host->dma_active) {
data->error = sh_mmcif_data_trans(host, host->mrq, cmd->opcode);
if (!data->error)
return true;
return false;
}
time = wait_for_completion_interruptible_timeout(&host->dma_complete,
host->timeout);
if (host->sd_error) {
dev_err(host->mmc->parent,
"Error IRQ while waiting for DMA completion!\n");
if (data->flags & MMC_DATA_READ)
dmaengine_terminate_all(host->chan_rx);
else
dmaengine_terminate_all(host->chan_tx);
data->error = sh_mmcif_error_manage(host);
} else if (!time) {
data->error = -ETIMEDOUT;
} else if (time < 0) {
data->error = time;
}
sh_mmcif_bitclr(host, MMCIF_CE_BUF_ACC,
BUF_ACC_DMAREN | BUF_ACC_DMAWEN);
host->dma_active = false;
if (data->error)
data->bytes_xfered = 0;
return false;
}
static irqreturn_t sh_mmcif_irqt(int irq, void *dev_id)
{
struct sh_mmcif_host *host = dev_id;
struct mmc_request *mrq = host->mrq;
cancel_delayed_work_sync(&host->timeout_work);
switch (host->wait_for) {
case MMCIF_WAIT_FOR_REQUEST:
return IRQ_HANDLED;
case MMCIF_WAIT_FOR_CMD:
if (sh_mmcif_end_cmd(host))
return IRQ_HANDLED;
break;
case MMCIF_WAIT_FOR_MREAD:
if (sh_mmcif_mread_block(host))
return IRQ_HANDLED;
break;
case MMCIF_WAIT_FOR_READ:
if (sh_mmcif_read_block(host))
return IRQ_HANDLED;
break;
case MMCIF_WAIT_FOR_MWRITE:
if (sh_mmcif_mwrite_block(host))
return IRQ_HANDLED;
break;
case MMCIF_WAIT_FOR_WRITE:
if (sh_mmcif_write_block(host))
return IRQ_HANDLED;
break;
case MMCIF_WAIT_FOR_STOP:
if (host->sd_error) {
mrq->stop->error = sh_mmcif_error_manage(host);
break;
}
sh_mmcif_get_cmd12response(host, mrq->stop);
mrq->stop->error = 0;
break;
case MMCIF_WAIT_FOR_READ_END:
case MMCIF_WAIT_FOR_WRITE_END:
if (host->sd_error)
mrq->data->error = sh_mmcif_error_manage(host);
break;
default:
BUG();
}
if (host->wait_for != MMCIF_WAIT_FOR_STOP) {
struct mmc_data *data = mrq->data;
if (!mrq->cmd->error && data && !data->error)
data->bytes_xfered =
data->blocks * data->blksz;
if (mrq->stop && !mrq->cmd->error && (!data || !data->error)) {
sh_mmcif_stop_cmd(host, mrq);
if (!mrq->stop->error)
return IRQ_HANDLED;
}
}
host->wait_for = MMCIF_WAIT_FOR_REQUEST;
host->state = STATE_IDLE;
host->mrq = NULL;
mmc_request_done(host->mmc, mrq);
return IRQ_HANDLED;
}
static irqreturn_t sh_mmcif_intr(int irq, void *dev_id)
{
struct sh_mmcif_host *host = dev_id;
u32 state;
int err = 0;
state = sh_mmcif_readl(host->addr, MMCIF_CE_INT);
if (state & INT_ERR_STS) {
sh_mmcif_writel(host->addr, MMCIF_CE_INT, ~state);
sh_mmcif_bitclr(host, MMCIF_CE_INT_MASK, state);
err = 1;
} else if (state & INT_RBSYE) {
sh_mmcif_writel(host->addr, MMCIF_CE_INT,
~(INT_RBSYE | INT_CRSPE));
sh_mmcif_bitclr(host, MMCIF_CE_INT_MASK, MASK_MRBSYE);
} else if (state & INT_CRSPE) {
sh_mmcif_writel(host->addr, MMCIF_CE_INT, ~INT_CRSPE);
sh_mmcif_bitclr(host, MMCIF_CE_INT_MASK, MASK_MCRSPE);
} else if (state & INT_BUFREN) {
sh_mmcif_writel(host->addr, MMCIF_CE_INT, ~INT_BUFREN);
sh_mmcif_bitclr(host, MMCIF_CE_INT_MASK, MASK_MBUFREN);
} else if (state & INT_BUFWEN) {
sh_mmcif_writel(host->addr, MMCIF_CE_INT, ~INT_BUFWEN);
sh_mmcif_bitclr(host, MMCIF_CE_INT_MASK, MASK_MBUFWEN);
} else if (state & INT_CMD12DRE) {
sh_mmcif_writel(host->addr, MMCIF_CE_INT,
~(INT_CMD12DRE | INT_CMD12RBE |
INT_CMD12CRE | INT_BUFRE));
sh_mmcif_bitclr(host, MMCIF_CE_INT_MASK, MASK_MCMD12DRE);
} else if (state & INT_BUFRE) {
sh_mmcif_writel(host->addr, MMCIF_CE_INT, ~INT_BUFRE);
sh_mmcif_bitclr(host, MMCIF_CE_INT_MASK, MASK_MBUFRE);
} else if (state & INT_DTRANE) {
sh_mmcif_writel(host->addr, MMCIF_CE_INT,
~(INT_CMD12DRE | INT_CMD12RBE |
INT_CMD12CRE | INT_DTRANE));
sh_mmcif_bitclr(host, MMCIF_CE_INT_MASK, MASK_MDTRANE);
} else if (state & INT_CMD12RBE) {
sh_mmcif_writel(host->addr, MMCIF_CE_INT,
~(INT_CMD12RBE | INT_CMD12CRE));
sh_mmcif_bitclr(host, MMCIF_CE_INT_MASK, MASK_MCMD12RBE);
} else {
dev_dbg(&host->pd->dev, "Unsupported interrupt: 0x%x\n", state);
sh_mmcif_writel(host->addr, MMCIF_CE_INT, ~state);
sh_mmcif_bitclr(host, MMCIF_CE_INT_MASK, state);
err = 1;
}
if (err) {
host->sd_error = true;
dev_dbg(&host->pd->dev, "int err state = %08x\n", state);
}
if (state & ~(INT_CMD12RBE | INT_CMD12CRE)) {
if (!host->dma_active)
return IRQ_WAKE_THREAD;
else if (host->sd_error)
mmcif_dma_complete(host);
} else {
dev_dbg(&host->pd->dev, "Unexpected IRQ 0x%x\n", state);
}
return IRQ_HANDLED;
}
static void mmcif_timeout_work(struct work_struct *work)
{
struct delayed_work *d = container_of(work, struct delayed_work, work);
struct sh_mmcif_host *host = container_of(d, struct sh_mmcif_host, timeout_work);
struct mmc_request *mrq = host->mrq;
if (host->dying)
return;
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
struct sh_mmcif_plat_data *pd = host->pd->dev.platform_data;
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
struct sh_mmcif_plat_data *pd = pdev->dev.platform_data;
struct resource *res;
void __iomem *reg;
irq[0] = platform_get_irq(pdev, 0);
irq[1] = platform_get_irq(pdev, 1);
if (irq[0] < 0 || irq[1] < 0) {
dev_err(&pdev->dev, "Get irq error\n");
return -ENXIO;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(&pdev->dev, "platform_get_resource error.\n");
return -ENXIO;
}
reg = ioremap(res->start, resource_size(res));
if (!reg) {
dev_err(&pdev->dev, "ioremap error.\n");
return -ENOMEM;
}
mmc = mmc_alloc_host(sizeof(struct sh_mmcif_host), &pdev->dev);
if (!mmc) {
ret = -ENOMEM;
goto ealloch;
}
host = mmc_priv(mmc);
host->mmc = mmc;
host->addr = reg;
host->timeout = 1000;
host->pd = pdev;
spin_lock_init(&host->lock);
mmc->ops = &sh_mmcif_ops;
sh_mmcif_init_ocr(host);
mmc->caps = MMC_CAP_MMC_HIGHSPEED;
if (pd && pd->caps)
mmc->caps |= pd->caps;
mmc->max_segs = 32;
mmc->max_blk_size = 512;
mmc->max_req_size = PAGE_CACHE_SIZE * mmc->max_segs;
mmc->max_blk_count = mmc->max_req_size / mmc->max_blk_size;
mmc->max_seg_size = mmc->max_req_size;
platform_set_drvdata(pdev, host);
pm_runtime_enable(&pdev->dev);
host->power = false;
host->hclk = clk_get(&pdev->dev, NULL);
if (IS_ERR(host->hclk)) {
ret = PTR_ERR(host->hclk);
dev_err(&pdev->dev, "cannot get clock: %d\n", ret);
goto eclkget;
}
ret = sh_mmcif_clk_update(host);
if (ret < 0)
goto eclkupdate;
ret = pm_runtime_resume(&pdev->dev);
if (ret < 0)
goto eresume;
INIT_DELAYED_WORK(&host->timeout_work, mmcif_timeout_work);
sh_mmcif_sync_reset(host);
sh_mmcif_writel(host->addr, MMCIF_CE_INT_MASK, MASK_ALL);
ret = request_threaded_irq(irq[0], sh_mmcif_intr, sh_mmcif_irqt, 0, "sh_mmc:error", host);
if (ret) {
dev_err(&pdev->dev, "request_irq error (sh_mmc:error)\n");
goto ereqirq0;
}
ret = request_threaded_irq(irq[1], sh_mmcif_intr, sh_mmcif_irqt, 0, "sh_mmc:int", host);
if (ret) {
dev_err(&pdev->dev, "request_irq error (sh_mmc:int)\n");
goto ereqirq1;
}
if (pd && pd->use_cd_gpio) {
ret = mmc_gpio_request_cd(mmc, pd->cd_gpio);
if (ret < 0)
goto erqcd;
}
clk_disable(host->hclk);
ret = mmc_add_host(mmc);
if (ret < 0)
goto emmcaddh;
dev_pm_qos_expose_latency_limit(&pdev->dev, 100);
dev_info(&pdev->dev, "driver version %s\n", DRIVER_VERSION);
dev_dbg(&pdev->dev, "chip ver H'%04x\n",
sh_mmcif_readl(host->addr, MMCIF_CE_VERSION) & 0x0000ffff);
return ret;
emmcaddh:
if (pd && pd->use_cd_gpio)
mmc_gpio_free_cd(mmc);
erqcd:
free_irq(irq[1], host);
ereqirq1:
free_irq(irq[0], host);
ereqirq0:
pm_runtime_suspend(&pdev->dev);
eresume:
clk_disable(host->hclk);
eclkupdate:
clk_put(host->hclk);
eclkget:
pm_runtime_disable(&pdev->dev);
mmc_free_host(mmc);
ealloch:
iounmap(reg);
return ret;
}
static int sh_mmcif_remove(struct platform_device *pdev)
{
struct sh_mmcif_host *host = platform_get_drvdata(pdev);
struct sh_mmcif_plat_data *pd = pdev->dev.platform_data;
int irq[2];
host->dying = true;
clk_enable(host->hclk);
pm_runtime_get_sync(&pdev->dev);
dev_pm_qos_hide_latency_limit(&pdev->dev);
if (pd && pd->use_cd_gpio)
mmc_gpio_free_cd(host->mmc);
mmc_remove_host(host->mmc);
sh_mmcif_writel(host->addr, MMCIF_CE_INT_MASK, MASK_ALL);
cancel_delayed_work_sync(&host->timeout_work);
if (host->addr)
iounmap(host->addr);
irq[0] = platform_get_irq(pdev, 0);
irq[1] = platform_get_irq(pdev, 1);
free_irq(irq[0], host);
free_irq(irq[1], host);
platform_set_drvdata(pdev, NULL);
clk_disable(host->hclk);
mmc_free_host(host->mmc);
pm_runtime_put_sync(&pdev->dev);
pm_runtime_disable(&pdev->dev);
return 0;
}
static int sh_mmcif_suspend(struct device *dev)
{
struct sh_mmcif_host *host = dev_get_drvdata(dev);
int ret = mmc_suspend_host(host->mmc);
if (!ret)
sh_mmcif_writel(host->addr, MMCIF_CE_INT_MASK, MASK_ALL);
return ret;
}
static int sh_mmcif_resume(struct device *dev)
{
struct sh_mmcif_host *host = dev_get_drvdata(dev);
return mmc_resume_host(host->mmc);
}
