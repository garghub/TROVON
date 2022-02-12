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
dev_dbg(&host->pd->dev, "Command completed\n");
if (WARN(!host->data, "%s: NULL data in DMA completion!\n",
dev_name(&host->pd->dev)))
return;
if (host->data->flags & MMC_DATA_READ)
dma_unmap_sg(host->chan_rx->device->dev,
host->data->sg, host->data->sg_len,
DMA_FROM_DEVICE);
else
dma_unmap_sg(host->chan_tx->device->dev,
host->data->sg, host->data->sg_len,
DMA_TO_DEVICE);
complete(&host->dma_complete);
}
static void sh_mmcif_start_dma_rx(struct sh_mmcif_host *host)
{
struct scatterlist *sg = host->data->sg;
struct dma_async_tx_descriptor *desc = NULL;
struct dma_chan *chan = host->chan_rx;
dma_cookie_t cookie = -EINVAL;
int ret;
ret = dma_map_sg(chan->device->dev, sg, host->data->sg_len,
DMA_FROM_DEVICE);
if (ret > 0) {
host->dma_active = true;
desc = chan->device->device_prep_slave_sg(chan, sg, ret,
DMA_FROM_DEVICE, DMA_PREP_INTERRUPT | DMA_CTRL_ACK);
}
if (desc) {
desc->callback = mmcif_dma_complete;
desc->callback_param = host;
cookie = dmaengine_submit(desc);
sh_mmcif_bitset(host, MMCIF_CE_BUF_ACC, BUF_ACC_DMAREN);
dma_async_issue_pending(chan);
}
dev_dbg(&host->pd->dev, "%s(): mapped %d -> %d, cookie %d\n",
__func__, host->data->sg_len, ret, cookie);
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
desc, cookie, host->data->sg_len);
}
static void sh_mmcif_start_dma_tx(struct sh_mmcif_host *host)
{
struct scatterlist *sg = host->data->sg;
struct dma_async_tx_descriptor *desc = NULL;
struct dma_chan *chan = host->chan_tx;
dma_cookie_t cookie = -EINVAL;
int ret;
ret = dma_map_sg(chan->device->dev, sg, host->data->sg_len,
DMA_TO_DEVICE);
if (ret > 0) {
host->dma_active = true;
desc = chan->device->device_prep_slave_sg(chan, sg, ret,
DMA_TO_DEVICE, DMA_PREP_INTERRUPT | DMA_CTRL_ACK);
}
if (desc) {
desc->callback = mmcif_dma_complete;
desc->callback_param = host;
cookie = dmaengine_submit(desc);
sh_mmcif_bitset(host, MMCIF_CE_BUF_ACC, BUF_ACC_DMAWEN);
dma_async_issue_pending(chan);
}
dev_dbg(&host->pd->dev, "%s(): mapped %d -> %d, cookie %d\n",
__func__, host->data->sg_len, ret, cookie);
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
static bool sh_mmcif_filter(struct dma_chan *chan, void *arg)
{
dev_dbg(chan->device->dev, "%s: slave data %p\n", __func__, arg);
chan->private = arg;
return true;
}
static void sh_mmcif_request_dma(struct sh_mmcif_host *host,
struct sh_mmcif_plat_data *pdata)
{
host->dma_active = false;
if (pdata->dma) {
dma_cap_mask_t mask;
dma_cap_zero(mask);
dma_cap_set(DMA_SLAVE, mask);
host->chan_tx = dma_request_channel(mask, sh_mmcif_filter,
&pdata->dma->chan_priv_tx);
dev_dbg(&host->pd->dev, "%s: TX: got channel %p\n", __func__,
host->chan_tx);
if (!host->chan_tx)
return;
host->chan_rx = dma_request_channel(mask, sh_mmcif_filter,
&pdata->dma->chan_priv_rx);
dev_dbg(&host->pd->dev, "%s: RX: got channel %p\n", __func__,
host->chan_rx);
if (!host->chan_rx) {
dma_release_channel(host->chan_tx);
host->chan_tx = NULL;
return;
}
init_completion(&host->dma_complete);
}
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
sh_mmcif_bitclr(host, MMCIF_CE_CLK_CTRL, CLK_ENABLE);
sh_mmcif_bitclr(host, MMCIF_CE_CLK_CTRL, CLK_CLEAR);
if (!clk)
return;
if (p->sup_pclk && clk == host->clk)
sh_mmcif_bitset(host, MMCIF_CE_CLK_CTRL, CLK_SUP_PCLK);
else
sh_mmcif_bitset(host, MMCIF_CE_CLK_CTRL, CLK_CLEAR &
(ilog2(__rounddown_pow_of_two(host->clk / clk)) << 16));
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
int ret, timeout = 10000000;
host->sd_error = false;
state1 = sh_mmcif_readl(host->addr, MMCIF_CE_HOST_STS1);
state2 = sh_mmcif_readl(host->addr, MMCIF_CE_HOST_STS2);
dev_dbg(&host->pd->dev, "ERR HOST_STS1 = %08x\n", state1);
dev_dbg(&host->pd->dev, "ERR HOST_STS2 = %08x\n", state2);
if (state1 & STS1_CMDSEQ) {
sh_mmcif_bitset(host, MMCIF_CE_CMD_CTRL, CMD_CTRL_BREAK);
sh_mmcif_bitset(host, MMCIF_CE_CMD_CTRL, ~CMD_CTRL_BREAK);
while (1) {
timeout--;
if (timeout < 0) {
dev_err(&host->pd->dev,
"Forceed end of command sequence timeout err\n");
return -EIO;
}
if (!(sh_mmcif_readl(host->addr, MMCIF_CE_HOST_STS1)
& STS1_CMDSEQ))
break;
mdelay(1);
}
sh_mmcif_sync_reset(host);
dev_dbg(&host->pd->dev, "Forced end of command sequence\n");
return -EIO;
}
if (state2 & STS2_CRC_ERR) {
dev_dbg(&host->pd->dev, ": Happened CRC error\n");
ret = -EIO;
} else if (state2 & STS2_TIMEOUT_ERR) {
dev_dbg(&host->pd->dev, ": Happened Timeout error\n");
ret = -ETIMEDOUT;
} else {
dev_dbg(&host->pd->dev, ": Happened End/Index error\n");
ret = -EIO;
}
return ret;
}
static int sh_mmcif_single_read(struct sh_mmcif_host *host,
struct mmc_request *mrq)
{
struct mmc_data *data = mrq->data;
long time;
u32 blocksize, i, *p = sg_virt(data->sg);
sh_mmcif_bitset(host, MMCIF_CE_INT_MASK, MASK_MBUFREN);
time = wait_for_completion_interruptible_timeout(&host->intr_wait,
host->timeout);
if (time <= 0 || host->sd_error)
return sh_mmcif_error_manage(host);
blocksize = (BLOCK_SIZE_MASK &
sh_mmcif_readl(host->addr, MMCIF_CE_BLOCK_SET)) + 3;
for (i = 0; i < blocksize / 4; i++)
*p++ = sh_mmcif_readl(host->addr, MMCIF_CE_DATA);
sh_mmcif_bitset(host, MMCIF_CE_INT_MASK, MASK_MBUFRE);
time = wait_for_completion_interruptible_timeout(&host->intr_wait,
host->timeout);
if (time <= 0 || host->sd_error)
return sh_mmcif_error_manage(host);
return 0;
}
static int sh_mmcif_multi_read(struct sh_mmcif_host *host,
struct mmc_request *mrq)
{
struct mmc_data *data = mrq->data;
long time;
u32 blocksize, i, j, sec, *p;
blocksize = BLOCK_SIZE_MASK & sh_mmcif_readl(host->addr,
MMCIF_CE_BLOCK_SET);
for (j = 0; j < data->sg_len; j++) {
p = sg_virt(data->sg);
for (sec = 0; sec < data->sg->length / blocksize; sec++) {
sh_mmcif_bitset(host, MMCIF_CE_INT_MASK, MASK_MBUFREN);
time = wait_for_completion_interruptible_timeout(&host->intr_wait,
host->timeout);
if (time <= 0 || host->sd_error)
return sh_mmcif_error_manage(host);
for (i = 0; i < blocksize / 4; i++)
*p++ = sh_mmcif_readl(host->addr,
MMCIF_CE_DATA);
}
if (j < data->sg_len - 1)
data->sg++;
}
return 0;
}
static int sh_mmcif_single_write(struct sh_mmcif_host *host,
struct mmc_request *mrq)
{
struct mmc_data *data = mrq->data;
long time;
u32 blocksize, i, *p = sg_virt(data->sg);
sh_mmcif_bitset(host, MMCIF_CE_INT_MASK, MASK_MBUFWEN);
time = wait_for_completion_interruptible_timeout(&host->intr_wait,
host->timeout);
if (time <= 0 || host->sd_error)
return sh_mmcif_error_manage(host);
blocksize = (BLOCK_SIZE_MASK &
sh_mmcif_readl(host->addr, MMCIF_CE_BLOCK_SET)) + 3;
for (i = 0; i < blocksize / 4; i++)
sh_mmcif_writel(host->addr, MMCIF_CE_DATA, *p++);
sh_mmcif_bitset(host, MMCIF_CE_INT_MASK, MASK_MDTRANE);
time = wait_for_completion_interruptible_timeout(&host->intr_wait,
host->timeout);
if (time <= 0 || host->sd_error)
return sh_mmcif_error_manage(host);
return 0;
}
static int sh_mmcif_multi_write(struct sh_mmcif_host *host,
struct mmc_request *mrq)
{
struct mmc_data *data = mrq->data;
long time;
u32 i, sec, j, blocksize, *p;
blocksize = BLOCK_SIZE_MASK & sh_mmcif_readl(host->addr,
MMCIF_CE_BLOCK_SET);
for (j = 0; j < data->sg_len; j++) {
p = sg_virt(data->sg);
for (sec = 0; sec < data->sg->length / blocksize; sec++) {
sh_mmcif_bitset(host, MMCIF_CE_INT_MASK, MASK_MBUFWEN);
time = wait_for_completion_interruptible_timeout(&host->intr_wait,
host->timeout);
if (time <= 0 || host->sd_error)
return sh_mmcif_error_manage(host);
for (i = 0; i < blocksize / 4; i++)
sh_mmcif_writel(host->addr,
MMCIF_CE_DATA, *p++);
}
if (j < data->sg_len - 1)
data->sg++;
}
return 0;
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
struct mmc_request *mrq, struct mmc_command *cmd, u32 opc)
{
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
case MMC_GEN_CMD:
tmp |= CMD_SET_RBSY;
break;
}
if (host->data) {
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
mrq->data->blocks << 16);
}
if (opc == MMC_SEND_OP_COND || opc == MMC_ALL_SEND_CID ||
opc == MMC_SEND_CSD || opc == MMC_SEND_CID)
tmp |= CMD_SET_RIDXC_BITS;
if (opc == MMC_SEND_OP_COND)
tmp |= CMD_SET_CRC7C_BITS;
if (opc == MMC_ALL_SEND_CID ||
opc == MMC_SEND_CSD || opc == MMC_SEND_CID)
tmp |= CMD_SET_CRC7C_INTERNAL;
return opc = ((opc << 24) | tmp);
}
static int sh_mmcif_data_trans(struct sh_mmcif_host *host,
struct mmc_request *mrq, u32 opc)
{
int ret;
switch (opc) {
case MMC_READ_MULTIPLE_BLOCK:
ret = sh_mmcif_multi_read(host, mrq);
break;
case MMC_WRITE_MULTIPLE_BLOCK:
ret = sh_mmcif_multi_write(host, mrq);
break;
case MMC_WRITE_BLOCK:
ret = sh_mmcif_single_write(host, mrq);
break;
case MMC_READ_SINGLE_BLOCK:
case MMC_SEND_EXT_CSD:
ret = sh_mmcif_single_read(host, mrq);
break;
default:
dev_err(&host->pd->dev, "UNSUPPORTED CMD = d'%08d\n", opc);
ret = -EINVAL;
break;
}
return ret;
}
static void sh_mmcif_start_cmd(struct sh_mmcif_host *host,
struct mmc_request *mrq, struct mmc_command *cmd)
{
long time;
int ret = 0, mask = 0;
u32 opc = cmd->opcode;
switch (opc) {
case MMC_SWITCH:
case MMC_STOP_TRANSMISSION:
case MMC_SET_WRITE_PROT:
case MMC_CLR_WRITE_PROT:
case MMC_ERASE:
case MMC_GEN_CMD:
mask = MASK_MRBSYE;
break;
default:
mask = MASK_MCRSPE;
break;
}
mask |= MASK_MCMDVIO | MASK_MBUFVIO | MASK_MWDATERR |
MASK_MRDATERR | MASK_MRIDXERR | MASK_MRSPERR |
MASK_MCCSTO | MASK_MCRCSTO | MASK_MWDATTO |
MASK_MRDATTO | MASK_MRBSYTO | MASK_MRSPTO;
if (host->data) {
sh_mmcif_writel(host->addr, MMCIF_CE_BLOCK_SET, 0);
sh_mmcif_writel(host->addr, MMCIF_CE_BLOCK_SET,
mrq->data->blksz);
}
opc = sh_mmcif_set_cmd(host, mrq, cmd, opc);
sh_mmcif_writel(host->addr, MMCIF_CE_INT, 0xD80430C0);
sh_mmcif_writel(host->addr, MMCIF_CE_INT_MASK, mask);
sh_mmcif_writel(host->addr, MMCIF_CE_ARG, cmd->arg);
sh_mmcif_writel(host->addr, MMCIF_CE_CMD_SET, opc);
time = wait_for_completion_interruptible_timeout(&host->intr_wait,
host->timeout);
if (time <= 0) {
cmd->error = sh_mmcif_error_manage(host);
return;
}
if (host->sd_error) {
switch (cmd->opcode) {
case MMC_ALL_SEND_CID:
case MMC_SELECT_CARD:
case MMC_APP_CMD:
cmd->error = -ETIMEDOUT;
break;
default:
dev_dbg(&host->pd->dev, "Cmd(d'%d) err\n",
cmd->opcode);
cmd->error = sh_mmcif_error_manage(host);
break;
}
host->sd_error = false;
return;
}
if (!(cmd->flags & MMC_RSP_PRESENT)) {
cmd->error = 0;
return;
}
sh_mmcif_get_response(host, cmd);
if (host->data) {
if (!host->dma_active) {
ret = sh_mmcif_data_trans(host, mrq, cmd->opcode);
} else {
long time =
wait_for_completion_interruptible_timeout(&host->dma_complete,
host->timeout);
if (!time)
ret = -ETIMEDOUT;
else if (time < 0)
ret = time;
sh_mmcif_bitclr(host, MMCIF_CE_BUF_ACC,
BUF_ACC_DMAREN | BUF_ACC_DMAWEN);
host->dma_active = false;
}
if (ret < 0)
mrq->data->bytes_xfered = 0;
else
mrq->data->bytes_xfered =
mrq->data->blocks * mrq->data->blksz;
}
cmd->error = ret;
}
static void sh_mmcif_stop_cmd(struct sh_mmcif_host *host,
struct mmc_request *mrq, struct mmc_command *cmd)
{
long time;
if (mrq->cmd->opcode == MMC_READ_MULTIPLE_BLOCK)
sh_mmcif_bitset(host, MMCIF_CE_INT_MASK, MASK_MCMD12DRE);
else if (mrq->cmd->opcode == MMC_WRITE_MULTIPLE_BLOCK)
sh_mmcif_bitset(host, MMCIF_CE_INT_MASK, MASK_MCMD12RBE);
else {
dev_err(&host->pd->dev, "unsupported stop cmd\n");
cmd->error = sh_mmcif_error_manage(host);
return;
}
time = wait_for_completion_interruptible_timeout(&host->intr_wait,
host->timeout);
if (time <= 0 || host->sd_error) {
cmd->error = sh_mmcif_error_manage(host);
return;
}
sh_mmcif_get_cmd12response(host, cmd);
cmd->error = 0;
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
case SD_IO_SEND_OP_COND:
case MMC_APP_CMD:
host->state = STATE_IDLE;
mrq->cmd->error = -ETIMEDOUT;
mmc_request_done(mmc, mrq);
return;
case MMC_SEND_EXT_CSD:
if (!mrq->data) {
host->state = STATE_IDLE;
mrq->cmd->error = -ETIMEDOUT;
mmc_request_done(mmc, mrq);
return;
}
break;
default:
break;
}
host->data = mrq->data;
if (mrq->data) {
if (mrq->data->flags & MMC_DATA_READ) {
if (host->chan_rx)
sh_mmcif_start_dma_rx(host);
} else {
if (host->chan_tx)
sh_mmcif_start_dma_tx(host);
}
}
sh_mmcif_start_cmd(host, mrq, mrq->cmd);
host->data = NULL;
if (!mrq->cmd->error && mrq->stop)
sh_mmcif_stop_cmd(host, mrq, mrq->stop);
host->state = STATE_IDLE;
mmc_request_done(mmc, mrq);
}
static void sh_mmcif_set_ios(struct mmc_host *mmc, struct mmc_ios *ios)
{
struct sh_mmcif_host *host = mmc_priv(mmc);
struct sh_mmcif_plat_data *p = host->pd->dev.platform_data;
unsigned long flags;
spin_lock_irqsave(&host->lock, flags);
if (host->state != STATE_IDLE) {
spin_unlock_irqrestore(&host->lock, flags);
return;
}
host->state = STATE_IOS;
spin_unlock_irqrestore(&host->lock, flags);
if (ios->power_mode == MMC_POWER_UP) {
if (p->set_pwr)
p->set_pwr(host->pd, ios->power_mode);
if (!host->power) {
sh_mmcif_request_dma(host, host->pd->dev.platform_data);
pm_runtime_get_sync(&host->pd->dev);
host->power = true;
}
} else if (ios->power_mode == MMC_POWER_OFF || !ios->clock) {
sh_mmcif_clock_control(host, 0);
if (ios->power_mode == MMC_POWER_OFF) {
if (host->power) {
pm_runtime_put(&host->pd->dev);
sh_mmcif_release_dma(host);
host->power = false;
}
if (p->down_pwr)
p->down_pwr(host->pd);
}
host->state = STATE_IDLE;
return;
}
if (ios->clock)
sh_mmcif_clock_control(host, ios->clock);
host->bus_width = ios->bus_width;
host->state = STATE_IDLE;
}
static int sh_mmcif_get_cd(struct mmc_host *mmc)
{
struct sh_mmcif_host *host = mmc_priv(mmc);
struct sh_mmcif_plat_data *p = host->pd->dev.platform_data;
if (!p->get_cd)
return -ENOSYS;
else
return p->get_cd(host->pd);
}
static void sh_mmcif_detect(struct mmc_host *mmc)
{
mmc_detect_change(mmc, 0);
}
static irqreturn_t sh_mmcif_intr(int irq, void *dev_id)
{
struct sh_mmcif_host *host = dev_id;
u32 state;
int err = 0;
state = sh_mmcif_readl(host->addr, MMCIF_CE_INT);
if (state & INT_RBSYE) {
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
sh_mmcif_writel(host->addr, MMCIF_CE_INT, ~INT_DTRANE);
sh_mmcif_bitclr(host, MMCIF_CE_INT_MASK, MASK_MDTRANE);
} else if (state & INT_CMD12RBE) {
sh_mmcif_writel(host->addr, MMCIF_CE_INT,
~(INT_CMD12RBE | INT_CMD12CRE));
sh_mmcif_bitclr(host, MMCIF_CE_INT_MASK, MASK_MCMD12RBE);
} else if (state & INT_ERR_STS) {
sh_mmcif_writel(host->addr, MMCIF_CE_INT, ~state);
sh_mmcif_bitclr(host, MMCIF_CE_INT_MASK, state);
err = 1;
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
if (state & ~(INT_CMD12RBE | INT_CMD12CRE))
complete(&host->intr_wait);
else
dev_dbg(&host->pd->dev, "Unexpected IRQ 0x%x\n", state);
return IRQ_HANDLED;
}
static int __devinit sh_mmcif_probe(struct platform_device *pdev)
{
int ret = 0, irq[2];
struct mmc_host *mmc;
struct sh_mmcif_host *host;
struct sh_mmcif_plat_data *pd;
struct resource *res;
void __iomem *reg;
char clk_name[8];
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
pd = pdev->dev.platform_data;
if (!pd) {
dev_err(&pdev->dev, "sh_mmcif plat data error.\n");
ret = -ENXIO;
goto clean_up;
}
mmc = mmc_alloc_host(sizeof(struct sh_mmcif_host), &pdev->dev);
if (!mmc) {
ret = -ENOMEM;
goto clean_up;
}
host = mmc_priv(mmc);
host->mmc = mmc;
host->addr = reg;
host->timeout = 1000;
snprintf(clk_name, sizeof(clk_name), "mmc%d", pdev->id);
host->hclk = clk_get(&pdev->dev, clk_name);
if (IS_ERR(host->hclk)) {
dev_err(&pdev->dev, "cannot get clock \"%s\"\n", clk_name);
ret = PTR_ERR(host->hclk);
goto clean_up1;
}
clk_enable(host->hclk);
host->clk = clk_get_rate(host->hclk);
host->pd = pdev;
init_completion(&host->intr_wait);
spin_lock_init(&host->lock);
mmc->ops = &sh_mmcif_ops;
mmc->f_max = host->clk;
if (mmc->f_max < 51200000)
mmc->f_min = mmc->f_max / 128;
else if (mmc->f_max < 102400000)
mmc->f_min = mmc->f_max / 256;
else
mmc->f_min = mmc->f_max / 512;
if (pd->ocr)
mmc->ocr_avail = pd->ocr;
mmc->caps = MMC_CAP_MMC_HIGHSPEED;
if (pd->caps)
mmc->caps |= pd->caps;
mmc->max_segs = 32;
mmc->max_blk_size = 512;
mmc->max_req_size = PAGE_CACHE_SIZE * mmc->max_segs;
mmc->max_blk_count = mmc->max_req_size / mmc->max_blk_size;
mmc->max_seg_size = mmc->max_req_size;
sh_mmcif_sync_reset(host);
platform_set_drvdata(pdev, host);
pm_runtime_enable(&pdev->dev);
host->power = false;
ret = pm_runtime_resume(&pdev->dev);
if (ret < 0)
goto clean_up2;
mmc_add_host(mmc);
sh_mmcif_writel(host->addr, MMCIF_CE_INT_MASK, MASK_ALL);
ret = request_irq(irq[0], sh_mmcif_intr, 0, "sh_mmc:error", host);
if (ret) {
dev_err(&pdev->dev, "request_irq error (sh_mmc:error)\n");
goto clean_up3;
}
ret = request_irq(irq[1], sh_mmcif_intr, 0, "sh_mmc:int", host);
if (ret) {
free_irq(irq[0], host);
dev_err(&pdev->dev, "request_irq error (sh_mmc:int)\n");
goto clean_up3;
}
sh_mmcif_detect(host->mmc);
dev_info(&pdev->dev, "driver version %s\n", DRIVER_VERSION);
dev_dbg(&pdev->dev, "chip ver H'%04x\n",
sh_mmcif_readl(host->addr, MMCIF_CE_VERSION) & 0x0000ffff);
return ret;
clean_up3:
mmc_remove_host(mmc);
pm_runtime_suspend(&pdev->dev);
clean_up2:
pm_runtime_disable(&pdev->dev);
clk_disable(host->hclk);
clean_up1:
mmc_free_host(mmc);
clean_up:
if (reg)
iounmap(reg);
return ret;
}
static int __devexit sh_mmcif_remove(struct platform_device *pdev)
{
struct sh_mmcif_host *host = platform_get_drvdata(pdev);
int irq[2];
pm_runtime_get_sync(&pdev->dev);
mmc_remove_host(host->mmc);
sh_mmcif_writel(host->addr, MMCIF_CE_INT_MASK, MASK_ALL);
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
struct platform_device *pdev = to_platform_device(dev);
struct sh_mmcif_host *host = platform_get_drvdata(pdev);
int ret = mmc_suspend_host(host->mmc);
if (!ret) {
sh_mmcif_writel(host->addr, MMCIF_CE_INT_MASK, MASK_ALL);
clk_disable(host->hclk);
}
return ret;
}
static int sh_mmcif_resume(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct sh_mmcif_host *host = platform_get_drvdata(pdev);
clk_enable(host->hclk);
return mmc_resume_host(host->mmc);
}
static int __init sh_mmcif_init(void)
{
return platform_driver_register(&sh_mmcif_driver);
}
static void __exit sh_mmcif_exit(void)
{
platform_driver_unregister(&sh_mmcif_driver);
}
