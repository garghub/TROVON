static int dw_mci_req_show(struct seq_file *s, void *v)
{
struct dw_mci_slot *slot = s->private;
struct mmc_request *mrq;
struct mmc_command *cmd;
struct mmc_command *stop;
struct mmc_data *data;
spin_lock_bh(&slot->host->lock);
mrq = slot->mrq;
if (mrq) {
cmd = mrq->cmd;
data = mrq->data;
stop = mrq->stop;
if (cmd)
seq_printf(s,
"CMD%u(0x%x) flg %x rsp %x %x %x %x err %d\n",
cmd->opcode, cmd->arg, cmd->flags,
cmd->resp[0], cmd->resp[1], cmd->resp[2],
cmd->resp[2], cmd->error);
if (data)
seq_printf(s, "DATA %u / %u * %u flg %x err %d\n",
data->bytes_xfered, data->blocks,
data->blksz, data->flags, data->error);
if (stop)
seq_printf(s,
"CMD%u(0x%x) flg %x rsp %x %x %x %x err %d\n",
stop->opcode, stop->arg, stop->flags,
stop->resp[0], stop->resp[1], stop->resp[2],
stop->resp[2], stop->error);
}
spin_unlock_bh(&slot->host->lock);
return 0;
}
static int dw_mci_req_open(struct inode *inode, struct file *file)
{
return single_open(file, dw_mci_req_show, inode->i_private);
}
static int dw_mci_regs_show(struct seq_file *s, void *v)
{
seq_printf(s, "STATUS:\t0x%08x\n", SDMMC_STATUS);
seq_printf(s, "RINTSTS:\t0x%08x\n", SDMMC_RINTSTS);
seq_printf(s, "CMD:\t0x%08x\n", SDMMC_CMD);
seq_printf(s, "CTRL:\t0x%08x\n", SDMMC_CTRL);
seq_printf(s, "INTMASK:\t0x%08x\n", SDMMC_INTMASK);
seq_printf(s, "CLKENA:\t0x%08x\n", SDMMC_CLKENA);
return 0;
}
static int dw_mci_regs_open(struct inode *inode, struct file *file)
{
return single_open(file, dw_mci_regs_show, inode->i_private);
}
static void dw_mci_init_debugfs(struct dw_mci_slot *slot)
{
struct mmc_host *mmc = slot->mmc;
struct dw_mci *host = slot->host;
struct dentry *root;
struct dentry *node;
root = mmc->debugfs_root;
if (!root)
return;
node = debugfs_create_file("regs", S_IRUSR, root, host,
&dw_mci_regs_fops);
if (!node)
goto err;
node = debugfs_create_file("req", S_IRUSR, root, slot,
&dw_mci_req_fops);
if (!node)
goto err;
node = debugfs_create_u32("state", S_IRUSR, root, (u32 *)&host->state);
if (!node)
goto err;
node = debugfs_create_x32("pending_events", S_IRUSR, root,
(u32 *)&host->pending_events);
if (!node)
goto err;
node = debugfs_create_x32("completed_events", S_IRUSR, root,
(u32 *)&host->completed_events);
if (!node)
goto err;
return;
err:
dev_err(&mmc->class_dev, "failed to initialize debugfs for slot\n");
}
static void dw_mci_set_timeout(struct dw_mci *host)
{
mci_writel(host, TMOUT, 0xffffffff);
}
static u32 dw_mci_prepare_command(struct mmc_host *mmc, struct mmc_command *cmd)
{
struct mmc_data *data;
struct dw_mci_slot *slot = mmc_priv(mmc);
const struct dw_mci_drv_data *drv_data = slot->host->drv_data;
u32 cmdr;
cmd->error = -EINPROGRESS;
cmdr = cmd->opcode;
if (cmd->opcode == MMC_STOP_TRANSMISSION ||
cmd->opcode == MMC_GO_IDLE_STATE ||
cmd->opcode == MMC_GO_INACTIVE_STATE ||
(cmd->opcode == SD_IO_RW_DIRECT &&
((cmd->arg >> 9) & 0x1FFFF) == SDIO_CCCR_ABORT))
cmdr |= SDMMC_CMD_STOP;
else
if (cmd->opcode != MMC_SEND_STATUS && cmd->data)
cmdr |= SDMMC_CMD_PRV_DAT_WAIT;
if (cmd->flags & MMC_RSP_PRESENT) {
cmdr |= SDMMC_CMD_RESP_EXP;
if (cmd->flags & MMC_RSP_136)
cmdr |= SDMMC_CMD_RESP_LONG;
}
if (cmd->flags & MMC_RSP_CRC)
cmdr |= SDMMC_CMD_RESP_CRC;
data = cmd->data;
if (data) {
cmdr |= SDMMC_CMD_DAT_EXP;
if (data->flags & MMC_DATA_STREAM)
cmdr |= SDMMC_CMD_STRM_MODE;
if (data->flags & MMC_DATA_WRITE)
cmdr |= SDMMC_CMD_DAT_WR;
}
if (drv_data && drv_data->prepare_command)
drv_data->prepare_command(slot->host, &cmdr);
return cmdr;
}
static u32 dw_mci_prep_stop_abort(struct dw_mci *host, struct mmc_command *cmd)
{
struct mmc_command *stop;
u32 cmdr;
if (!cmd->data)
return 0;
stop = &host->stop_abort;
cmdr = cmd->opcode;
memset(stop, 0, sizeof(struct mmc_command));
if (cmdr == MMC_READ_SINGLE_BLOCK ||
cmdr == MMC_READ_MULTIPLE_BLOCK ||
cmdr == MMC_WRITE_BLOCK ||
cmdr == MMC_WRITE_MULTIPLE_BLOCK) {
stop->opcode = MMC_STOP_TRANSMISSION;
stop->arg = 0;
stop->flags = MMC_RSP_R1B | MMC_CMD_AC;
} else if (cmdr == SD_IO_RW_EXTENDED) {
stop->opcode = SD_IO_RW_DIRECT;
stop->arg |= (1 << 31) | (0 << 28) | (SDIO_CCCR_ABORT << 9) |
((cmd->arg >> 28) & 0x7);
stop->flags = MMC_RSP_SPI_R5 | MMC_RSP_R5 | MMC_CMD_AC;
} else {
return 0;
}
cmdr = stop->opcode | SDMMC_CMD_STOP |
SDMMC_CMD_RESP_CRC | SDMMC_CMD_RESP_EXP;
return cmdr;
}
static void dw_mci_start_command(struct dw_mci *host,
struct mmc_command *cmd, u32 cmd_flags)
{
host->cmd = cmd;
dev_vdbg(host->dev,
"start command: ARGR=0x%08x CMDR=0x%08x\n",
cmd->arg, cmd_flags);
mci_writel(host, CMDARG, cmd->arg);
wmb();
mci_writel(host, CMD, cmd_flags | SDMMC_CMD_START);
}
static inline void send_stop_abort(struct dw_mci *host, struct mmc_data *data)
{
struct mmc_command *stop = data->stop ? data->stop : &host->stop_abort;
dw_mci_start_command(host, stop, host->stop_cmdr);
}
static void dw_mci_stop_dma(struct dw_mci *host)
{
if (host->using_dma) {
host->dma_ops->stop(host);
host->dma_ops->cleanup(host);
}
set_bit(EVENT_XFER_COMPLETE, &host->pending_events);
}
static int dw_mci_get_dma_dir(struct mmc_data *data)
{
if (data->flags & MMC_DATA_WRITE)
return DMA_TO_DEVICE;
else
return DMA_FROM_DEVICE;
}
static void dw_mci_dma_cleanup(struct dw_mci *host)
{
struct mmc_data *data = host->data;
if (data)
if (!data->host_cookie)
dma_unmap_sg(host->dev,
data->sg,
data->sg_len,
dw_mci_get_dma_dir(data));
}
static void dw_mci_idmac_reset(struct dw_mci *host)
{
u32 bmod = mci_readl(host, BMOD);
bmod |= SDMMC_IDMAC_SWRESET;
mci_writel(host, BMOD, bmod);
}
static void dw_mci_idmac_stop_dma(struct dw_mci *host)
{
u32 temp;
temp = mci_readl(host, CTRL);
temp &= ~SDMMC_CTRL_USE_IDMAC;
temp |= SDMMC_CTRL_DMA_RESET;
mci_writel(host, CTRL, temp);
temp = mci_readl(host, BMOD);
temp &= ~(SDMMC_IDMAC_ENABLE | SDMMC_IDMAC_FB);
temp |= SDMMC_IDMAC_SWRESET;
mci_writel(host, BMOD, temp);
}
static void dw_mci_idmac_complete_dma(struct dw_mci *host)
{
struct mmc_data *data = host->data;
dev_vdbg(host->dev, "DMA complete\n");
host->dma_ops->cleanup(host);
if (data) {
set_bit(EVENT_XFER_COMPLETE, &host->pending_events);
tasklet_schedule(&host->tasklet);
}
}
static void dw_mci_translate_sglist(struct dw_mci *host, struct mmc_data *data,
unsigned int sg_len)
{
int i;
struct idmac_desc *desc = host->sg_cpu;
for (i = 0; i < sg_len; i++, desc++) {
unsigned int length = sg_dma_len(&data->sg[i]);
u32 mem_addr = sg_dma_address(&data->sg[i]);
desc->des0 = IDMAC_DES0_OWN | IDMAC_DES0_DIC | IDMAC_DES0_CH;
IDMAC_SET_BUFFER1_SIZE(desc, length);
desc->des2 = mem_addr;
}
desc = host->sg_cpu;
desc->des0 |= IDMAC_DES0_FD;
desc = host->sg_cpu + (i - 1) * sizeof(struct idmac_desc);
desc->des0 &= ~(IDMAC_DES0_CH | IDMAC_DES0_DIC);
desc->des0 |= IDMAC_DES0_LD;
wmb();
}
static void dw_mci_idmac_start_dma(struct dw_mci *host, unsigned int sg_len)
{
u32 temp;
dw_mci_translate_sglist(host, host->data, sg_len);
temp = mci_readl(host, CTRL);
temp |= SDMMC_CTRL_USE_IDMAC;
mci_writel(host, CTRL, temp);
wmb();
temp = mci_readl(host, BMOD);
temp |= SDMMC_IDMAC_ENABLE | SDMMC_IDMAC_FB;
mci_writel(host, BMOD, temp);
mci_writel(host, PLDMND, 1);
}
static int dw_mci_idmac_init(struct dw_mci *host)
{
struct idmac_desc *p;
int i;
host->ring_size = PAGE_SIZE / sizeof(struct idmac_desc);
for (i = 0, p = host->sg_cpu; i < host->ring_size - 1; i++, p++)
p->des3 = host->sg_dma + (sizeof(struct idmac_desc) * (i + 1));
p->des3 = host->sg_dma;
p->des0 = IDMAC_DES0_ER;
dw_mci_idmac_reset(host);
mci_writel(host, IDSTS, IDMAC_INT_CLR);
mci_writel(host, IDINTEN, SDMMC_IDMAC_INT_NI | SDMMC_IDMAC_INT_RI |
SDMMC_IDMAC_INT_TI);
mci_writel(host, DBADDR, host->sg_dma);
return 0;
}
static int dw_mci_pre_dma_transfer(struct dw_mci *host,
struct mmc_data *data,
bool next)
{
struct scatterlist *sg;
unsigned int i, sg_len;
if (!next && data->host_cookie)
return data->host_cookie;
if (data->blocks * data->blksz < DW_MCI_DMA_THRESHOLD)
return -EINVAL;
if (data->blksz & 3)
return -EINVAL;
for_each_sg(data->sg, sg, data->sg_len, i) {
if (sg->offset & 3 || sg->length & 3)
return -EINVAL;
}
sg_len = dma_map_sg(host->dev,
data->sg,
data->sg_len,
dw_mci_get_dma_dir(data));
if (sg_len == 0)
return -EINVAL;
if (next)
data->host_cookie = sg_len;
return sg_len;
}
static void dw_mci_pre_req(struct mmc_host *mmc,
struct mmc_request *mrq,
bool is_first_req)
{
struct dw_mci_slot *slot = mmc_priv(mmc);
struct mmc_data *data = mrq->data;
if (!slot->host->use_dma || !data)
return;
if (data->host_cookie) {
data->host_cookie = 0;
return;
}
if (dw_mci_pre_dma_transfer(slot->host, mrq->data, 1) < 0)
data->host_cookie = 0;
}
static void dw_mci_post_req(struct mmc_host *mmc,
struct mmc_request *mrq,
int err)
{
struct dw_mci_slot *slot = mmc_priv(mmc);
struct mmc_data *data = mrq->data;
if (!slot->host->use_dma || !data)
return;
if (data->host_cookie)
dma_unmap_sg(slot->host->dev,
data->sg,
data->sg_len,
dw_mci_get_dma_dir(data));
data->host_cookie = 0;
}
static void dw_mci_adjust_fifoth(struct dw_mci *host, struct mmc_data *data)
{
#ifdef CONFIG_MMC_DW_IDMAC
unsigned int blksz = data->blksz;
const u32 mszs[] = {1, 4, 8, 16, 32, 64, 128, 256};
u32 fifo_width = 1 << host->data_shift;
u32 blksz_depth = blksz / fifo_width, fifoth_val;
u32 msize = 0, rx_wmark = 1, tx_wmark, tx_wmark_invers;
int idx = (sizeof(mszs) / sizeof(mszs[0])) - 1;
tx_wmark = (host->fifo_depth) / 2;
tx_wmark_invers = host->fifo_depth - tx_wmark;
if (blksz % fifo_width) {
msize = 0;
rx_wmark = 1;
goto done;
}
do {
if (!((blksz_depth % mszs[idx]) ||
(tx_wmark_invers % mszs[idx]))) {
msize = idx;
rx_wmark = mszs[idx] - 1;
break;
}
} while (--idx > 0);
done:
fifoth_val = SDMMC_SET_FIFOTH(msize, rx_wmark, tx_wmark);
mci_writel(host, FIFOTH, fifoth_val);
#endif
}
static void dw_mci_ctrl_rd_thld(struct dw_mci *host, struct mmc_data *data)
{
unsigned int blksz = data->blksz;
u32 blksz_depth, fifo_depth;
u16 thld_size;
WARN_ON(!(data->flags & MMC_DATA_READ));
if (host->timing != MMC_TIMING_MMC_HS200 &&
host->timing != MMC_TIMING_UHS_SDR104)
goto disable;
blksz_depth = blksz / (1 << host->data_shift);
fifo_depth = host->fifo_depth;
if (blksz_depth > fifo_depth)
goto disable;
thld_size = blksz;
mci_writel(host, CDTHRCTL, SDMMC_SET_RD_THLD(thld_size, 1));
return;
disable:
mci_writel(host, CDTHRCTL, SDMMC_SET_RD_THLD(0, 0));
}
static int dw_mci_submit_data_dma(struct dw_mci *host, struct mmc_data *data)
{
int sg_len;
u32 temp;
host->using_dma = 0;
if (!host->use_dma)
return -ENODEV;
sg_len = dw_mci_pre_dma_transfer(host, data, 0);
if (sg_len < 0) {
host->dma_ops->stop(host);
return sg_len;
}
host->using_dma = 1;
dev_vdbg(host->dev,
"sd sg_cpu: %#lx sg_dma: %#lx sg_len: %d\n",
(unsigned long)host->sg_cpu, (unsigned long)host->sg_dma,
sg_len);
if (host->prev_blksz != data->blksz)
dw_mci_adjust_fifoth(host, data);
temp = mci_readl(host, CTRL);
temp |= SDMMC_CTRL_DMA_ENABLE;
mci_writel(host, CTRL, temp);
temp = mci_readl(host, INTMASK);
temp &= ~(SDMMC_INT_RXDR | SDMMC_INT_TXDR);
mci_writel(host, INTMASK, temp);
host->dma_ops->start(host, sg_len);
return 0;
}
static void dw_mci_submit_data(struct dw_mci *host, struct mmc_data *data)
{
u32 temp;
data->error = -EINPROGRESS;
WARN_ON(host->data);
host->sg = NULL;
host->data = data;
if (data->flags & MMC_DATA_READ) {
host->dir_status = DW_MCI_RECV_STATUS;
dw_mci_ctrl_rd_thld(host, data);
} else {
host->dir_status = DW_MCI_SEND_STATUS;
}
if (dw_mci_submit_data_dma(host, data)) {
int flags = SG_MITER_ATOMIC;
if (host->data->flags & MMC_DATA_READ)
flags |= SG_MITER_TO_SG;
else
flags |= SG_MITER_FROM_SG;
sg_miter_start(&host->sg_miter, data->sg, data->sg_len, flags);
host->sg = data->sg;
host->part_buf_start = 0;
host->part_buf_count = 0;
mci_writel(host, RINTSTS, SDMMC_INT_TXDR | SDMMC_INT_RXDR);
temp = mci_readl(host, INTMASK);
temp |= SDMMC_INT_TXDR | SDMMC_INT_RXDR;
mci_writel(host, INTMASK, temp);
temp = mci_readl(host, CTRL);
temp &= ~SDMMC_CTRL_DMA_ENABLE;
mci_writel(host, CTRL, temp);
mci_writel(host, FIFOTH, host->fifoth_val);
host->prev_blksz = 0;
} else {
host->prev_blksz = data->blksz;
}
}
static void mci_send_cmd(struct dw_mci_slot *slot, u32 cmd, u32 arg)
{
struct dw_mci *host = slot->host;
unsigned long timeout = jiffies + msecs_to_jiffies(500);
unsigned int cmd_status = 0;
mci_writel(host, CMDARG, arg);
wmb();
mci_writel(host, CMD, SDMMC_CMD_START | cmd);
while (time_before(jiffies, timeout)) {
cmd_status = mci_readl(host, CMD);
if (!(cmd_status & SDMMC_CMD_START))
return;
}
dev_err(&slot->mmc->class_dev,
"Timeout sending command (cmd %#x arg %#x status %#x)\n",
cmd, arg, cmd_status);
}
static void dw_mci_setup_bus(struct dw_mci_slot *slot, bool force_clkinit)
{
struct dw_mci *host = slot->host;
unsigned int clock = slot->clock;
u32 div;
u32 clk_en_a;
if (!clock) {
mci_writel(host, CLKENA, 0);
mci_send_cmd(slot,
SDMMC_CMD_UPD_CLK | SDMMC_CMD_PRV_DAT_WAIT, 0);
} else if (clock != host->current_speed || force_clkinit) {
div = host->bus_hz / clock;
if (host->bus_hz % clock && host->bus_hz > clock)
div += 1;
div = (host->bus_hz != clock) ? DIV_ROUND_UP(div, 2) : 0;
if ((clock << div) != slot->__clk_old || force_clkinit)
dev_info(&slot->mmc->class_dev,
"Bus speed (slot %d) = %dHz (slot req %dHz, actual %dHZ div = %d)\n",
slot->id, host->bus_hz, clock,
div ? ((host->bus_hz / div) >> 1) :
host->bus_hz, div);
mci_writel(host, CLKENA, 0);
mci_writel(host, CLKSRC, 0);
mci_send_cmd(slot,
SDMMC_CMD_UPD_CLK | SDMMC_CMD_PRV_DAT_WAIT, 0);
mci_writel(host, CLKDIV, div);
mci_send_cmd(slot,
SDMMC_CMD_UPD_CLK | SDMMC_CMD_PRV_DAT_WAIT, 0);
clk_en_a = SDMMC_CLKEN_ENABLE << slot->id;
if (!(mci_readl(host, INTMASK) & SDMMC_INT_SDIO(slot->id)))
clk_en_a |= SDMMC_CLKEN_LOW_PWR << slot->id;
mci_writel(host, CLKENA, clk_en_a);
mci_send_cmd(slot,
SDMMC_CMD_UPD_CLK | SDMMC_CMD_PRV_DAT_WAIT, 0);
slot->__clk_old = clock << div;
}
host->current_speed = clock;
mci_writel(host, CTYPE, (slot->ctype << slot->id));
}
static void __dw_mci_start_request(struct dw_mci *host,
struct dw_mci_slot *slot,
struct mmc_command *cmd)
{
struct mmc_request *mrq;
struct mmc_data *data;
u32 cmdflags;
mrq = slot->mrq;
if (host->pdata->select_slot)
host->pdata->select_slot(slot->id);
host->cur_slot = slot;
host->mrq = mrq;
host->pending_events = 0;
host->completed_events = 0;
host->cmd_status = 0;
host->data_status = 0;
host->dir_status = 0;
data = cmd->data;
if (data) {
dw_mci_set_timeout(host);
mci_writel(host, BYTCNT, data->blksz*data->blocks);
mci_writel(host, BLKSIZ, data->blksz);
}
cmdflags = dw_mci_prepare_command(slot->mmc, cmd);
if (test_and_clear_bit(DW_MMC_CARD_NEED_INIT, &slot->flags))
cmdflags |= SDMMC_CMD_INIT;
if (data) {
dw_mci_submit_data(host, data);
wmb();
}
dw_mci_start_command(host, cmd, cmdflags);
if (mrq->stop)
host->stop_cmdr = dw_mci_prepare_command(slot->mmc, mrq->stop);
else
host->stop_cmdr = dw_mci_prep_stop_abort(host, cmd);
}
static void dw_mci_start_request(struct dw_mci *host,
struct dw_mci_slot *slot)
{
struct mmc_request *mrq = slot->mrq;
struct mmc_command *cmd;
cmd = mrq->sbc ? mrq->sbc : mrq->cmd;
__dw_mci_start_request(host, slot, cmd);
}
static void dw_mci_queue_request(struct dw_mci *host, struct dw_mci_slot *slot,
struct mmc_request *mrq)
{
dev_vdbg(&slot->mmc->class_dev, "queue request: state=%d\n",
host->state);
slot->mrq = mrq;
if (host->state == STATE_IDLE) {
host->state = STATE_SENDING_CMD;
dw_mci_start_request(host, slot);
} else {
list_add_tail(&slot->queue_node, &host->queue);
}
}
static void dw_mci_request(struct mmc_host *mmc, struct mmc_request *mrq)
{
struct dw_mci_slot *slot = mmc_priv(mmc);
struct dw_mci *host = slot->host;
WARN_ON(slot->mrq);
spin_lock_bh(&host->lock);
if (!test_bit(DW_MMC_CARD_PRESENT, &slot->flags)) {
spin_unlock_bh(&host->lock);
mrq->cmd->error = -ENOMEDIUM;
mmc_request_done(mmc, mrq);
return;
}
dw_mci_queue_request(host, slot, mrq);
spin_unlock_bh(&host->lock);
}
static void dw_mci_set_ios(struct mmc_host *mmc, struct mmc_ios *ios)
{
struct dw_mci_slot *slot = mmc_priv(mmc);
const struct dw_mci_drv_data *drv_data = slot->host->drv_data;
u32 regs;
switch (ios->bus_width) {
case MMC_BUS_WIDTH_4:
slot->ctype = SDMMC_CTYPE_4BIT;
break;
case MMC_BUS_WIDTH_8:
slot->ctype = SDMMC_CTYPE_8BIT;
break;
default:
slot->ctype = SDMMC_CTYPE_1BIT;
}
regs = mci_readl(slot->host, UHS_REG);
if (ios->timing == MMC_TIMING_UHS_DDR50)
regs |= ((0x1 << slot->id) << 16);
else
regs &= ~((0x1 << slot->id) << 16);
mci_writel(slot->host, UHS_REG, regs);
slot->host->timing = ios->timing;
slot->clock = ios->clock;
if (drv_data && drv_data->set_ios)
drv_data->set_ios(slot->host, ios);
dw_mci_setup_bus(slot, false);
switch (ios->power_mode) {
case MMC_POWER_UP:
set_bit(DW_MMC_CARD_NEED_INIT, &slot->flags);
if (slot->host->pdata->setpower)
slot->host->pdata->setpower(slot->id, mmc->ocr_avail);
regs = mci_readl(slot->host, PWREN);
regs |= (1 << slot->id);
mci_writel(slot->host, PWREN, regs);
break;
case MMC_POWER_OFF:
if (slot->host->pdata->setpower)
slot->host->pdata->setpower(slot->id, 0);
regs = mci_readl(slot->host, PWREN);
regs &= ~(1 << slot->id);
mci_writel(slot->host, PWREN, regs);
break;
default:
break;
}
}
static int dw_mci_get_ro(struct mmc_host *mmc)
{
int read_only;
struct dw_mci_slot *slot = mmc_priv(mmc);
struct dw_mci_board *brd = slot->host->pdata;
if (slot->quirks & DW_MCI_SLOT_QUIRK_NO_WRITE_PROTECT)
read_only = 0;
else if (brd->get_ro)
read_only = brd->get_ro(slot->id);
else if (gpio_is_valid(slot->wp_gpio))
read_only = gpio_get_value(slot->wp_gpio);
else
read_only =
mci_readl(slot->host, WRTPRT) & (1 << slot->id) ? 1 : 0;
dev_dbg(&mmc->class_dev, "card is %s\n",
read_only ? "read-only" : "read-write");
return read_only;
}
static int dw_mci_get_cd(struct mmc_host *mmc)
{
int present;
struct dw_mci_slot *slot = mmc_priv(mmc);
struct dw_mci_board *brd = slot->host->pdata;
if (brd->quirks & DW_MCI_QUIRK_BROKEN_CARD_DETECTION)
present = 1;
else if (brd->get_cd)
present = !brd->get_cd(slot->id);
else
present = (mci_readl(slot->host, CDETECT) & (1 << slot->id))
== 0 ? 1 : 0;
if (present)
dev_dbg(&mmc->class_dev, "card is present\n");
else
dev_dbg(&mmc->class_dev, "card is not present\n");
return present;
}
static void dw_mci_disable_low_power(struct dw_mci_slot *slot)
{
struct dw_mci *host = slot->host;
u32 clk_en_a;
const u32 clken_low_pwr = SDMMC_CLKEN_LOW_PWR << slot->id;
clk_en_a = mci_readl(host, CLKENA);
if (clk_en_a & clken_low_pwr) {
mci_writel(host, CLKENA, clk_en_a & ~clken_low_pwr);
mci_send_cmd(slot, SDMMC_CMD_UPD_CLK |
SDMMC_CMD_PRV_DAT_WAIT, 0);
}
}
static void dw_mci_enable_sdio_irq(struct mmc_host *mmc, int enb)
{
struct dw_mci_slot *slot = mmc_priv(mmc);
struct dw_mci *host = slot->host;
u32 int_mask;
int_mask = mci_readl(host, INTMASK);
if (enb) {
dw_mci_disable_low_power(slot);
mci_writel(host, INTMASK,
(int_mask | SDMMC_INT_SDIO(slot->id)));
} else {
mci_writel(host, INTMASK,
(int_mask & ~SDMMC_INT_SDIO(slot->id)));
}
}
static int dw_mci_execute_tuning(struct mmc_host *mmc, u32 opcode)
{
struct dw_mci_slot *slot = mmc_priv(mmc);
struct dw_mci *host = slot->host;
const struct dw_mci_drv_data *drv_data = host->drv_data;
struct dw_mci_tuning_data tuning_data;
int err = -ENOSYS;
if (opcode == MMC_SEND_TUNING_BLOCK_HS200) {
if (mmc->ios.bus_width == MMC_BUS_WIDTH_8) {
tuning_data.blk_pattern = tuning_blk_pattern_8bit;
tuning_data.blksz = sizeof(tuning_blk_pattern_8bit);
} else if (mmc->ios.bus_width == MMC_BUS_WIDTH_4) {
tuning_data.blk_pattern = tuning_blk_pattern_4bit;
tuning_data.blksz = sizeof(tuning_blk_pattern_4bit);
} else {
return -EINVAL;
}
} else if (opcode == MMC_SEND_TUNING_BLOCK) {
tuning_data.blk_pattern = tuning_blk_pattern_4bit;
tuning_data.blksz = sizeof(tuning_blk_pattern_4bit);
} else {
dev_err(host->dev,
"Undefined command(%d) for tuning\n", opcode);
return -EINVAL;
}
if (drv_data && drv_data->execute_tuning)
err = drv_data->execute_tuning(slot, opcode, &tuning_data);
return err;
}
static void dw_mci_request_end(struct dw_mci *host, struct mmc_request *mrq)
__releases(&host->lock
static int dw_mci_command_complete(struct dw_mci *host, struct mmc_command *cmd)
{
u32 status = host->cmd_status;
host->cmd_status = 0;
if (cmd->flags & MMC_RSP_PRESENT) {
if (cmd->flags & MMC_RSP_136) {
cmd->resp[3] = mci_readl(host, RESP0);
cmd->resp[2] = mci_readl(host, RESP1);
cmd->resp[1] = mci_readl(host, RESP2);
cmd->resp[0] = mci_readl(host, RESP3);
} else {
cmd->resp[0] = mci_readl(host, RESP0);
cmd->resp[1] = 0;
cmd->resp[2] = 0;
cmd->resp[3] = 0;
}
}
if (status & SDMMC_INT_RTO)
cmd->error = -ETIMEDOUT;
else if ((cmd->flags & MMC_RSP_CRC) && (status & SDMMC_INT_RCRC))
cmd->error = -EILSEQ;
else if (status & SDMMC_INT_RESP_ERR)
cmd->error = -EIO;
else
cmd->error = 0;
if (cmd->error) {
if (host->quirks & DW_MCI_QUIRK_RETRY_DELAY)
mdelay(20);
}
return cmd->error;
}
static int dw_mci_data_complete(struct dw_mci *host, struct mmc_data *data)
{
u32 status = host->data_status;
if (status & DW_MCI_DATA_ERROR_FLAGS) {
if (status & SDMMC_INT_DRTO) {
data->error = -ETIMEDOUT;
} else if (status & SDMMC_INT_DCRC) {
data->error = -EILSEQ;
} else if (status & SDMMC_INT_EBE) {
if (host->dir_status ==
DW_MCI_SEND_STATUS) {
data->bytes_xfered = 0;
data->error = -ETIMEDOUT;
} else if (host->dir_status ==
DW_MCI_RECV_STATUS) {
data->error = -EIO;
}
} else {
data->error = -EIO;
}
dev_err(host->dev, "data error, status 0x%08x\n", status);
dw_mci_fifo_reset(host);
} else {
data->bytes_xfered = data->blocks * data->blksz;
data->error = 0;
}
return data->error;
}
static void dw_mci_tasklet_func(unsigned long priv)
{
struct dw_mci *host = (struct dw_mci *)priv;
struct mmc_data *data;
struct mmc_command *cmd;
struct mmc_request *mrq;
enum dw_mci_state state;
enum dw_mci_state prev_state;
unsigned int err;
spin_lock(&host->lock);
state = host->state;
data = host->data;
mrq = host->mrq;
do {
prev_state = state;
switch (state) {
case STATE_IDLE:
break;
case STATE_SENDING_CMD:
if (!test_and_clear_bit(EVENT_CMD_COMPLETE,
&host->pending_events))
break;
cmd = host->cmd;
host->cmd = NULL;
set_bit(EVENT_CMD_COMPLETE, &host->completed_events);
err = dw_mci_command_complete(host, cmd);
if (cmd == mrq->sbc && !err) {
prev_state = state = STATE_SENDING_CMD;
__dw_mci_start_request(host, host->cur_slot,
mrq->cmd);
goto unlock;
}
if (cmd->data && err) {
dw_mci_stop_dma(host);
send_stop_abort(host, data);
state = STATE_SENDING_STOP;
break;
}
if (!cmd->data || err) {
dw_mci_request_end(host, mrq);
goto unlock;
}
prev_state = state = STATE_SENDING_DATA;
case STATE_SENDING_DATA:
if (test_and_clear_bit(EVENT_DATA_ERROR,
&host->pending_events)) {
dw_mci_stop_dma(host);
send_stop_abort(host, data);
state = STATE_DATA_ERROR;
break;
}
if (!test_and_clear_bit(EVENT_XFER_COMPLETE,
&host->pending_events))
break;
set_bit(EVENT_XFER_COMPLETE, &host->completed_events);
prev_state = state = STATE_DATA_BUSY;
case STATE_DATA_BUSY:
if (!test_and_clear_bit(EVENT_DATA_COMPLETE,
&host->pending_events))
break;
host->data = NULL;
set_bit(EVENT_DATA_COMPLETE, &host->completed_events);
err = dw_mci_data_complete(host, data);
if (!err) {
if (!data->stop || mrq->sbc) {
if (mrq->sbc)
data->stop->error = 0;
dw_mci_request_end(host, mrq);
goto unlock;
}
if (data->stop)
send_stop_abort(host, data);
}
prev_state = state = STATE_SENDING_STOP;
case STATE_SENDING_STOP:
if (!test_and_clear_bit(EVENT_CMD_COMPLETE,
&host->pending_events))
break;
if (mrq->cmd->error && mrq->data)
dw_mci_fifo_reset(host);
host->cmd = NULL;
host->data = NULL;
if (mrq->stop)
dw_mci_command_complete(host, mrq->stop);
else
host->cmd_status = 0;
dw_mci_request_end(host, mrq);
goto unlock;
case STATE_DATA_ERROR:
if (!test_and_clear_bit(EVENT_XFER_COMPLETE,
&host->pending_events))
break;
state = STATE_DATA_BUSY;
break;
}
} while (state != prev_state);
host->state = state;
unlock:
spin_unlock(&host->lock);
}
static void dw_mci_set_part_bytes(struct dw_mci *host, void *buf, int cnt)
{
memcpy((void *)&host->part_buf, buf, cnt);
host->part_buf_count = cnt;
}
static int dw_mci_push_part_bytes(struct dw_mci *host, void *buf, int cnt)
{
cnt = min(cnt, (1 << host->data_shift) - host->part_buf_count);
memcpy((void *)&host->part_buf + host->part_buf_count, buf, cnt);
host->part_buf_count += cnt;
return cnt;
}
static int dw_mci_pull_part_bytes(struct dw_mci *host, void *buf, int cnt)
{
cnt = min(cnt, (int)host->part_buf_count);
if (cnt) {
memcpy(buf, (void *)&host->part_buf + host->part_buf_start,
cnt);
host->part_buf_count -= cnt;
host->part_buf_start += cnt;
}
return cnt;
}
static void dw_mci_pull_final_bytes(struct dw_mci *host, void *buf, int cnt)
{
memcpy(buf, &host->part_buf, cnt);
host->part_buf_start = cnt;
host->part_buf_count = (1 << host->data_shift) - cnt;
}
static void dw_mci_push_data16(struct dw_mci *host, void *buf, int cnt)
{
struct mmc_data *data = host->data;
int init_cnt = cnt;
if (unlikely(host->part_buf_count)) {
int len = dw_mci_push_part_bytes(host, buf, cnt);
buf += len;
cnt -= len;
if (host->part_buf_count == 2) {
mci_writew(host, DATA(host->data_offset),
host->part_buf16);
host->part_buf_count = 0;
}
}
#ifndef CONFIG_HAVE_EFFICIENT_UNALIGNED_ACCESS
if (unlikely((unsigned long)buf & 0x1)) {
while (cnt >= 2) {
u16 aligned_buf[64];
int len = min(cnt & -2, (int)sizeof(aligned_buf));
int items = len >> 1;
int i;
memcpy(aligned_buf, buf, len);
buf += len;
cnt -= len;
for (i = 0; i < items; ++i)
mci_writew(host, DATA(host->data_offset),
aligned_buf[i]);
}
} else
#endif
{
u16 *pdata = buf;
for (; cnt >= 2; cnt -= 2)
mci_writew(host, DATA(host->data_offset), *pdata++);
buf = pdata;
}
if (cnt) {
dw_mci_set_part_bytes(host, buf, cnt);
if ((data->bytes_xfered + init_cnt) ==
(data->blksz * data->blocks))
mci_writew(host, DATA(host->data_offset),
host->part_buf16);
}
}
static void dw_mci_pull_data16(struct dw_mci *host, void *buf, int cnt)
{
#ifndef CONFIG_HAVE_EFFICIENT_UNALIGNED_ACCESS
if (unlikely((unsigned long)buf & 0x1)) {
while (cnt >= 2) {
u16 aligned_buf[64];
int len = min(cnt & -2, (int)sizeof(aligned_buf));
int items = len >> 1;
int i;
for (i = 0; i < items; ++i)
aligned_buf[i] = mci_readw(host,
DATA(host->data_offset));
memcpy(buf, aligned_buf, len);
buf += len;
cnt -= len;
}
} else
#endif
{
u16 *pdata = buf;
for (; cnt >= 2; cnt -= 2)
*pdata++ = mci_readw(host, DATA(host->data_offset));
buf = pdata;
}
if (cnt) {
host->part_buf16 = mci_readw(host, DATA(host->data_offset));
dw_mci_pull_final_bytes(host, buf, cnt);
}
}
static void dw_mci_push_data32(struct dw_mci *host, void *buf, int cnt)
{
struct mmc_data *data = host->data;
int init_cnt = cnt;
if (unlikely(host->part_buf_count)) {
int len = dw_mci_push_part_bytes(host, buf, cnt);
buf += len;
cnt -= len;
if (host->part_buf_count == 4) {
mci_writel(host, DATA(host->data_offset),
host->part_buf32);
host->part_buf_count = 0;
}
}
#ifndef CONFIG_HAVE_EFFICIENT_UNALIGNED_ACCESS
if (unlikely((unsigned long)buf & 0x3)) {
while (cnt >= 4) {
u32 aligned_buf[32];
int len = min(cnt & -4, (int)sizeof(aligned_buf));
int items = len >> 2;
int i;
memcpy(aligned_buf, buf, len);
buf += len;
cnt -= len;
for (i = 0; i < items; ++i)
mci_writel(host, DATA(host->data_offset),
aligned_buf[i]);
}
} else
#endif
{
u32 *pdata = buf;
for (; cnt >= 4; cnt -= 4)
mci_writel(host, DATA(host->data_offset), *pdata++);
buf = pdata;
}
if (cnt) {
dw_mci_set_part_bytes(host, buf, cnt);
if ((data->bytes_xfered + init_cnt) ==
(data->blksz * data->blocks))
mci_writel(host, DATA(host->data_offset),
host->part_buf32);
}
}
static void dw_mci_pull_data32(struct dw_mci *host, void *buf, int cnt)
{
#ifndef CONFIG_HAVE_EFFICIENT_UNALIGNED_ACCESS
if (unlikely((unsigned long)buf & 0x3)) {
while (cnt >= 4) {
u32 aligned_buf[32];
int len = min(cnt & -4, (int)sizeof(aligned_buf));
int items = len >> 2;
int i;
for (i = 0; i < items; ++i)
aligned_buf[i] = mci_readl(host,
DATA(host->data_offset));
memcpy(buf, aligned_buf, len);
buf += len;
cnt -= len;
}
} else
#endif
{
u32 *pdata = buf;
for (; cnt >= 4; cnt -= 4)
*pdata++ = mci_readl(host, DATA(host->data_offset));
buf = pdata;
}
if (cnt) {
host->part_buf32 = mci_readl(host, DATA(host->data_offset));
dw_mci_pull_final_bytes(host, buf, cnt);
}
}
static void dw_mci_push_data64(struct dw_mci *host, void *buf, int cnt)
{
struct mmc_data *data = host->data;
int init_cnt = cnt;
if (unlikely(host->part_buf_count)) {
int len = dw_mci_push_part_bytes(host, buf, cnt);
buf += len;
cnt -= len;
if (host->part_buf_count == 8) {
mci_writeq(host, DATA(host->data_offset),
host->part_buf);
host->part_buf_count = 0;
}
}
#ifndef CONFIG_HAVE_EFFICIENT_UNALIGNED_ACCESS
if (unlikely((unsigned long)buf & 0x7)) {
while (cnt >= 8) {
u64 aligned_buf[16];
int len = min(cnt & -8, (int)sizeof(aligned_buf));
int items = len >> 3;
int i;
memcpy(aligned_buf, buf, len);
buf += len;
cnt -= len;
for (i = 0; i < items; ++i)
mci_writeq(host, DATA(host->data_offset),
aligned_buf[i]);
}
} else
#endif
{
u64 *pdata = buf;
for (; cnt >= 8; cnt -= 8)
mci_writeq(host, DATA(host->data_offset), *pdata++);
buf = pdata;
}
if (cnt) {
dw_mci_set_part_bytes(host, buf, cnt);
if ((data->bytes_xfered + init_cnt) ==
(data->blksz * data->blocks))
mci_writeq(host, DATA(host->data_offset),
host->part_buf);
}
}
static void dw_mci_pull_data64(struct dw_mci *host, void *buf, int cnt)
{
#ifndef CONFIG_HAVE_EFFICIENT_UNALIGNED_ACCESS
if (unlikely((unsigned long)buf & 0x7)) {
while (cnt >= 8) {
u64 aligned_buf[16];
int len = min(cnt & -8, (int)sizeof(aligned_buf));
int items = len >> 3;
int i;
for (i = 0; i < items; ++i)
aligned_buf[i] = mci_readq(host,
DATA(host->data_offset));
memcpy(buf, aligned_buf, len);
buf += len;
cnt -= len;
}
} else
#endif
{
u64 *pdata = buf;
for (; cnt >= 8; cnt -= 8)
*pdata++ = mci_readq(host, DATA(host->data_offset));
buf = pdata;
}
if (cnt) {
host->part_buf = mci_readq(host, DATA(host->data_offset));
dw_mci_pull_final_bytes(host, buf, cnt);
}
}
static void dw_mci_pull_data(struct dw_mci *host, void *buf, int cnt)
{
int len;
len = dw_mci_pull_part_bytes(host, buf, cnt);
if (unlikely(len == cnt))
return;
buf += len;
cnt -= len;
host->pull_data(host, buf, cnt);
}
static void dw_mci_read_data_pio(struct dw_mci *host, bool dto)
{
struct sg_mapping_iter *sg_miter = &host->sg_miter;
void *buf;
unsigned int offset;
struct mmc_data *data = host->data;
int shift = host->data_shift;
u32 status;
unsigned int len;
unsigned int remain, fcnt;
do {
if (!sg_miter_next(sg_miter))
goto done;
host->sg = sg_miter->piter.sg;
buf = sg_miter->addr;
remain = sg_miter->length;
offset = 0;
do {
fcnt = (SDMMC_GET_FCNT(mci_readl(host, STATUS))
<< shift) + host->part_buf_count;
len = min(remain, fcnt);
if (!len)
break;
dw_mci_pull_data(host, (void *)(buf + offset), len);
data->bytes_xfered += len;
offset += len;
remain -= len;
} while (remain);
sg_miter->consumed = offset;
status = mci_readl(host, MINTSTS);
mci_writel(host, RINTSTS, SDMMC_INT_RXDR);
} while ((status & SDMMC_INT_RXDR) ||
(dto && SDMMC_GET_FCNT(mci_readl(host, STATUS))));
if (!remain) {
if (!sg_miter_next(sg_miter))
goto done;
sg_miter->consumed = 0;
}
sg_miter_stop(sg_miter);
return;
done:
sg_miter_stop(sg_miter);
host->sg = NULL;
smp_wmb();
set_bit(EVENT_XFER_COMPLETE, &host->pending_events);
}
static void dw_mci_write_data_pio(struct dw_mci *host)
{
struct sg_mapping_iter *sg_miter = &host->sg_miter;
void *buf;
unsigned int offset;
struct mmc_data *data = host->data;
int shift = host->data_shift;
u32 status;
unsigned int len;
unsigned int fifo_depth = host->fifo_depth;
unsigned int remain, fcnt;
do {
if (!sg_miter_next(sg_miter))
goto done;
host->sg = sg_miter->piter.sg;
buf = sg_miter->addr;
remain = sg_miter->length;
offset = 0;
do {
fcnt = ((fifo_depth -
SDMMC_GET_FCNT(mci_readl(host, STATUS)))
<< shift) - host->part_buf_count;
len = min(remain, fcnt);
if (!len)
break;
host->push_data(host, (void *)(buf + offset), len);
data->bytes_xfered += len;
offset += len;
remain -= len;
} while (remain);
sg_miter->consumed = offset;
status = mci_readl(host, MINTSTS);
mci_writel(host, RINTSTS, SDMMC_INT_TXDR);
} while (status & SDMMC_INT_TXDR);
if (!remain) {
if (!sg_miter_next(sg_miter))
goto done;
sg_miter->consumed = 0;
}
sg_miter_stop(sg_miter);
return;
done:
sg_miter_stop(sg_miter);
host->sg = NULL;
smp_wmb();
set_bit(EVENT_XFER_COMPLETE, &host->pending_events);
}
static void dw_mci_cmd_interrupt(struct dw_mci *host, u32 status)
{
if (!host->cmd_status)
host->cmd_status = status;
smp_wmb();
set_bit(EVENT_CMD_COMPLETE, &host->pending_events);
tasklet_schedule(&host->tasklet);
}
static irqreturn_t dw_mci_interrupt(int irq, void *dev_id)
{
struct dw_mci *host = dev_id;
u32 pending;
int i;
pending = mci_readl(host, MINTSTS);
if (host->quirks & DW_MCI_QUIRK_IDMAC_DTO) {
if (!pending &&
((mci_readl(host, STATUS) >> 17) & 0x1fff))
pending |= SDMMC_INT_DATA_OVER;
}
if (pending) {
if (pending & DW_MCI_CMD_ERROR_FLAGS) {
mci_writel(host, RINTSTS, DW_MCI_CMD_ERROR_FLAGS);
host->cmd_status = pending;
smp_wmb();
set_bit(EVENT_CMD_COMPLETE, &host->pending_events);
}
if (pending & DW_MCI_DATA_ERROR_FLAGS) {
mci_writel(host, RINTSTS, DW_MCI_DATA_ERROR_FLAGS);
host->data_status = pending;
smp_wmb();
set_bit(EVENT_DATA_ERROR, &host->pending_events);
tasklet_schedule(&host->tasklet);
}
if (pending & SDMMC_INT_DATA_OVER) {
mci_writel(host, RINTSTS, SDMMC_INT_DATA_OVER);
if (!host->data_status)
host->data_status = pending;
smp_wmb();
if (host->dir_status == DW_MCI_RECV_STATUS) {
if (host->sg != NULL)
dw_mci_read_data_pio(host, true);
}
set_bit(EVENT_DATA_COMPLETE, &host->pending_events);
tasklet_schedule(&host->tasklet);
}
if (pending & SDMMC_INT_RXDR) {
mci_writel(host, RINTSTS, SDMMC_INT_RXDR);
if (host->dir_status == DW_MCI_RECV_STATUS && host->sg)
dw_mci_read_data_pio(host, false);
}
if (pending & SDMMC_INT_TXDR) {
mci_writel(host, RINTSTS, SDMMC_INT_TXDR);
if (host->dir_status == DW_MCI_SEND_STATUS && host->sg)
dw_mci_write_data_pio(host);
}
if (pending & SDMMC_INT_CMD_DONE) {
mci_writel(host, RINTSTS, SDMMC_INT_CMD_DONE);
dw_mci_cmd_interrupt(host, pending);
}
if (pending & SDMMC_INT_CD) {
mci_writel(host, RINTSTS, SDMMC_INT_CD);
queue_work(host->card_workqueue, &host->card_work);
}
for (i = 0; i < host->num_slots; i++) {
struct dw_mci_slot *slot = host->slot[i];
if (pending & SDMMC_INT_SDIO(i)) {
mci_writel(host, RINTSTS, SDMMC_INT_SDIO(i));
mmc_signal_sdio_irq(slot->mmc);
}
}
}
#ifdef CONFIG_MMC_DW_IDMAC
pending = mci_readl(host, IDSTS);
if (pending & (SDMMC_IDMAC_INT_TI | SDMMC_IDMAC_INT_RI)) {
mci_writel(host, IDSTS, SDMMC_IDMAC_INT_TI | SDMMC_IDMAC_INT_RI);
mci_writel(host, IDSTS, SDMMC_IDMAC_INT_NI);
host->dma_ops->complete(host);
}
#endif
return IRQ_HANDLED;
}
static void dw_mci_work_routine_card(struct work_struct *work)
{
struct dw_mci *host = container_of(work, struct dw_mci, card_work);
int i;
for (i = 0; i < host->num_slots; i++) {
struct dw_mci_slot *slot = host->slot[i];
struct mmc_host *mmc = slot->mmc;
struct mmc_request *mrq;
int present;
present = dw_mci_get_cd(mmc);
while (present != slot->last_detect_state) {
dev_dbg(&slot->mmc->class_dev, "card %s\n",
present ? "inserted" : "removed");
spin_lock_bh(&host->lock);
slot->last_detect_state = present;
if (present != 0)
set_bit(DW_MMC_CARD_PRESENT, &slot->flags);
mrq = slot->mrq;
if (mrq) {
if (mrq == host->mrq) {
host->data = NULL;
host->cmd = NULL;
switch (host->state) {
case STATE_IDLE:
break;
case STATE_SENDING_CMD:
mrq->cmd->error = -ENOMEDIUM;
if (!mrq->data)
break;
case STATE_SENDING_DATA:
mrq->data->error = -ENOMEDIUM;
dw_mci_stop_dma(host);
break;
case STATE_DATA_BUSY:
case STATE_DATA_ERROR:
if (mrq->data->error == -EINPROGRESS)
mrq->data->error = -ENOMEDIUM;
case STATE_SENDING_STOP:
if (mrq->stop)
mrq->stop->error = -ENOMEDIUM;
break;
}
dw_mci_request_end(host, mrq);
} else {
list_del(&slot->queue_node);
mrq->cmd->error = -ENOMEDIUM;
if (mrq->data)
mrq->data->error = -ENOMEDIUM;
if (mrq->stop)
mrq->stop->error = -ENOMEDIUM;
spin_unlock(&host->lock);
mmc_request_done(slot->mmc, mrq);
spin_lock(&host->lock);
}
}
if (present == 0) {
clear_bit(DW_MMC_CARD_PRESENT, &slot->flags);
dw_mci_fifo_reset(host);
#ifdef CONFIG_MMC_DW_IDMAC
dw_mci_idmac_reset(host);
#endif
}
spin_unlock_bh(&host->lock);
present = dw_mci_get_cd(mmc);
}
mmc_detect_change(slot->mmc,
msecs_to_jiffies(host->pdata->detect_delay_ms));
}
}
static struct device_node *dw_mci_of_find_slot_node(struct device *dev, u8 slot)
{
struct device_node *np;
const __be32 *addr;
int len;
if (!dev || !dev->of_node)
return NULL;
for_each_child_of_node(dev->of_node, np) {
addr = of_get_property(np, "reg", &len);
if (!addr || (len < sizeof(int)))
continue;
if (be32_to_cpup(addr) == slot)
return np;
}
return NULL;
}
static int dw_mci_of_get_slot_quirks(struct device *dev, u8 slot)
{
struct device_node *np = dw_mci_of_find_slot_node(dev, slot);
int quirks = 0;
int idx;
for (idx = 0; idx < ARRAY_SIZE(of_slot_quirks); idx++)
if (of_get_property(np, of_slot_quirks[idx].quirk, NULL))
quirks |= of_slot_quirks[idx].id;
return quirks;
}
static u32 dw_mci_of_get_bus_wd(struct device *dev, u8 slot)
{
struct device_node *np = dw_mci_of_find_slot_node(dev, slot);
u32 bus_wd = 1;
if (!np)
return 1;
if (of_property_read_u32(np, "bus-width", &bus_wd))
dev_err(dev, "bus-width property not found, assuming width"
" as 1\n");
return bus_wd;
}
static int dw_mci_of_get_wp_gpio(struct device *dev, u8 slot)
{
struct device_node *np = dw_mci_of_find_slot_node(dev, slot);
int gpio;
if (!np)
return -EINVAL;
gpio = of_get_named_gpio(np, "wp-gpios", 0);
if (!gpio_is_valid(gpio))
return -EINVAL;
if (devm_gpio_request(dev, gpio, "dw-mci-wp")) {
dev_warn(dev, "gpio [%d] request failed\n", gpio);
return -EINVAL;
}
return gpio;
}
static int dw_mci_of_get_slot_quirks(struct device *dev, u8 slot)
{
return 0;
}
static u32 dw_mci_of_get_bus_wd(struct device *dev, u8 slot)
{
return 1;
}
static struct device_node *dw_mci_of_find_slot_node(struct device *dev, u8 slot)
{
return NULL;
}
static int dw_mci_of_get_wp_gpio(struct device *dev, u8 slot)
{
return -EINVAL;
}
static int dw_mci_init_slot(struct dw_mci *host, unsigned int id)
{
struct mmc_host *mmc;
struct dw_mci_slot *slot;
const struct dw_mci_drv_data *drv_data = host->drv_data;
int ctrl_id, ret;
u32 freq[2];
u8 bus_width;
mmc = mmc_alloc_host(sizeof(struct dw_mci_slot), host->dev);
if (!mmc)
return -ENOMEM;
slot = mmc_priv(mmc);
slot->id = id;
slot->mmc = mmc;
slot->host = host;
host->slot[id] = slot;
slot->quirks = dw_mci_of_get_slot_quirks(host->dev, slot->id);
mmc->ops = &dw_mci_ops;
if (of_property_read_u32_array(host->dev->of_node,
"clock-freq-min-max", freq, 2)) {
mmc->f_min = DW_MCI_FREQ_MIN;
mmc->f_max = DW_MCI_FREQ_MAX;
} else {
mmc->f_min = freq[0];
mmc->f_max = freq[1];
}
if (host->pdata->get_ocr)
mmc->ocr_avail = host->pdata->get_ocr(id);
else
mmc->ocr_avail = MMC_VDD_32_33 | MMC_VDD_33_34;
if (host->pdata->setpower)
host->pdata->setpower(id, 0);
if (host->pdata->caps)
mmc->caps = host->pdata->caps;
if (host->pdata->pm_caps)
mmc->pm_caps = host->pdata->pm_caps;
if (host->dev->of_node) {
ctrl_id = of_alias_get_id(host->dev->of_node, "mshc");
if (ctrl_id < 0)
ctrl_id = 0;
} else {
ctrl_id = to_platform_device(host->dev)->id;
}
if (drv_data && drv_data->caps)
mmc->caps |= drv_data->caps[ctrl_id];
if (host->pdata->caps2)
mmc->caps2 = host->pdata->caps2;
if (host->pdata->get_bus_wd)
bus_width = host->pdata->get_bus_wd(slot->id);
else if (host->dev->of_node)
bus_width = dw_mci_of_get_bus_wd(host->dev, slot->id);
else
bus_width = 1;
switch (bus_width) {
case 8:
mmc->caps |= MMC_CAP_8_BIT_DATA;
case 4:
mmc->caps |= MMC_CAP_4_BIT_DATA;
}
if (host->pdata->blk_settings) {
mmc->max_segs = host->pdata->blk_settings->max_segs;
mmc->max_blk_size = host->pdata->blk_settings->max_blk_size;
mmc->max_blk_count = host->pdata->blk_settings->max_blk_count;
mmc->max_req_size = host->pdata->blk_settings->max_req_size;
mmc->max_seg_size = host->pdata->blk_settings->max_seg_size;
} else {
#ifdef CONFIG_MMC_DW_IDMAC
mmc->max_segs = host->ring_size;
mmc->max_blk_size = 65536;
mmc->max_blk_count = host->ring_size;
mmc->max_seg_size = 0x1000;
mmc->max_req_size = mmc->max_seg_size * mmc->max_blk_count;
#else
mmc->max_segs = 64;
mmc->max_blk_size = 65536;
mmc->max_blk_count = 512;
mmc->max_req_size = mmc->max_blk_size * mmc->max_blk_count;
mmc->max_seg_size = mmc->max_req_size;
#endif
}
if (dw_mci_get_cd(mmc))
set_bit(DW_MMC_CARD_PRESENT, &slot->flags);
else
clear_bit(DW_MMC_CARD_PRESENT, &slot->flags);
slot->wp_gpio = dw_mci_of_get_wp_gpio(host->dev, slot->id);
ret = mmc_add_host(mmc);
if (ret)
goto err_setup_bus;
#if defined(CONFIG_DEBUG_FS)
dw_mci_init_debugfs(slot);
#endif
slot->last_detect_state = 0;
return 0;
err_setup_bus:
mmc_free_host(mmc);
return -EINVAL;
}
static void dw_mci_cleanup_slot(struct dw_mci_slot *slot, unsigned int id)
{
if (slot->host->pdata->exit)
slot->host->pdata->exit(id);
mmc_remove_host(slot->mmc);
slot->host->slot[id] = NULL;
mmc_free_host(slot->mmc);
}
static void dw_mci_init_dma(struct dw_mci *host)
{
host->sg_cpu = dmam_alloc_coherent(host->dev, PAGE_SIZE,
&host->sg_dma, GFP_KERNEL);
if (!host->sg_cpu) {
dev_err(host->dev, "%s: could not alloc DMA memory\n",
__func__);
goto no_dma;
}
#ifdef CONFIG_MMC_DW_IDMAC
host->dma_ops = &dw_mci_idmac_ops;
dev_info(host->dev, "Using internal DMA controller.\n");
#endif
if (!host->dma_ops)
goto no_dma;
if (host->dma_ops->init && host->dma_ops->start &&
host->dma_ops->stop && host->dma_ops->cleanup) {
if (host->dma_ops->init(host)) {
dev_err(host->dev, "%s: Unable to initialize "
"DMA Controller.\n", __func__);
goto no_dma;
}
} else {
dev_err(host->dev, "DMA initialization not found.\n");
goto no_dma;
}
host->use_dma = 1;
return;
no_dma:
dev_info(host->dev, "Using PIO mode.\n");
host->use_dma = 0;
return;
}
static bool dw_mci_ctrl_reset(struct dw_mci *host, u32 reset)
{
unsigned long timeout = jiffies + msecs_to_jiffies(500);
u32 ctrl;
ctrl = mci_readl(host, CTRL);
ctrl |= reset;
mci_writel(host, CTRL, ctrl);
do {
ctrl = mci_readl(host, CTRL);
if (!(ctrl & reset))
return true;
} while (time_before(jiffies, timeout));
dev_err(host->dev,
"Timeout resetting block (ctrl reset %#x)\n",
ctrl & reset);
return false;
}
static inline bool dw_mci_fifo_reset(struct dw_mci *host)
{
if (host->sg) {
sg_miter_stop(&host->sg_miter);
host->sg = NULL;
}
return dw_mci_ctrl_reset(host, SDMMC_CTRL_FIFO_RESET);
}
static inline bool dw_mci_ctrl_all_reset(struct dw_mci *host)
{
return dw_mci_ctrl_reset(host,
SDMMC_CTRL_FIFO_RESET |
SDMMC_CTRL_RESET |
SDMMC_CTRL_DMA_RESET);
}
static struct dw_mci_board *dw_mci_parse_dt(struct dw_mci *host)
{
struct dw_mci_board *pdata;
struct device *dev = host->dev;
struct device_node *np = dev->of_node;
const struct dw_mci_drv_data *drv_data = host->drv_data;
int idx, ret;
u32 clock_frequency;
pdata = devm_kzalloc(dev, sizeof(*pdata), GFP_KERNEL);
if (!pdata) {
dev_err(dev, "could not allocate memory for pdata\n");
return ERR_PTR(-ENOMEM);
}
if (of_property_read_u32(dev->of_node, "num-slots",
&pdata->num_slots)) {
dev_info(dev, "num-slots property not found, "
"assuming 1 slot is available\n");
pdata->num_slots = 1;
}
for (idx = 0; idx < ARRAY_SIZE(of_quirks); idx++)
if (of_get_property(np, of_quirks[idx].quirk, NULL))
pdata->quirks |= of_quirks[idx].id;
if (of_property_read_u32(np, "fifo-depth", &pdata->fifo_depth))
dev_info(dev, "fifo-depth property not found, using "
"value of FIFOTH register as default\n");
of_property_read_u32(np, "card-detect-delay", &pdata->detect_delay_ms);
if (!of_property_read_u32(np, "clock-frequency", &clock_frequency))
pdata->bus_hz = clock_frequency;
if (drv_data && drv_data->parse_dt) {
ret = drv_data->parse_dt(host);
if (ret)
return ERR_PTR(ret);
}
if (of_find_property(np, "keep-power-in-suspend", NULL))
pdata->pm_caps |= MMC_PM_KEEP_POWER;
if (of_find_property(np, "enable-sdio-wakeup", NULL))
pdata->pm_caps |= MMC_PM_WAKE_SDIO_IRQ;
if (of_find_property(np, "supports-highspeed", NULL))
pdata->caps |= MMC_CAP_SD_HIGHSPEED | MMC_CAP_MMC_HIGHSPEED;
if (of_find_property(np, "caps2-mmc-hs200-1_8v", NULL))
pdata->caps2 |= MMC_CAP2_HS200_1_8V_SDR;
if (of_find_property(np, "caps2-mmc-hs200-1_2v", NULL))
pdata->caps2 |= MMC_CAP2_HS200_1_2V_SDR;
return pdata;
}
static struct dw_mci_board *dw_mci_parse_dt(struct dw_mci *host)
{
return ERR_PTR(-EINVAL);
}
int dw_mci_probe(struct dw_mci *host)
{
const struct dw_mci_drv_data *drv_data = host->drv_data;
int width, i, ret = 0;
u32 fifo_size;
int init_slots = 0;
if (!host->pdata) {
host->pdata = dw_mci_parse_dt(host);
if (IS_ERR(host->pdata)) {
dev_err(host->dev, "platform data not available\n");
return -EINVAL;
}
}
if (!host->pdata->select_slot && host->pdata->num_slots > 1) {
dev_err(host->dev,
"Platform data must supply select_slot function\n");
return -ENODEV;
}
host->biu_clk = devm_clk_get(host->dev, "biu");
if (IS_ERR(host->biu_clk)) {
dev_dbg(host->dev, "biu clock not available\n");
} else {
ret = clk_prepare_enable(host->biu_clk);
if (ret) {
dev_err(host->dev, "failed to enable biu clock\n");
return ret;
}
}
host->ciu_clk = devm_clk_get(host->dev, "ciu");
if (IS_ERR(host->ciu_clk)) {
dev_dbg(host->dev, "ciu clock not available\n");
host->bus_hz = host->pdata->bus_hz;
} else {
ret = clk_prepare_enable(host->ciu_clk);
if (ret) {
dev_err(host->dev, "failed to enable ciu clock\n");
goto err_clk_biu;
}
if (host->pdata->bus_hz) {
ret = clk_set_rate(host->ciu_clk, host->pdata->bus_hz);
if (ret)
dev_warn(host->dev,
"Unable to set bus rate to %ul\n",
host->pdata->bus_hz);
}
host->bus_hz = clk_get_rate(host->ciu_clk);
}
if (drv_data && drv_data->init) {
ret = drv_data->init(host);
if (ret) {
dev_err(host->dev,
"implementation specific init failed\n");
goto err_clk_ciu;
}
}
if (drv_data && drv_data->setup_clock) {
ret = drv_data->setup_clock(host);
if (ret) {
dev_err(host->dev,
"implementation specific clock setup failed\n");
goto err_clk_ciu;
}
}
host->vmmc = devm_regulator_get_optional(host->dev, "vmmc");
if (IS_ERR(host->vmmc)) {
ret = PTR_ERR(host->vmmc);
if (ret == -EPROBE_DEFER)
goto err_clk_ciu;
dev_info(host->dev, "no vmmc regulator found: %d\n", ret);
host->vmmc = NULL;
} else {
ret = regulator_enable(host->vmmc);
if (ret) {
if (ret != -EPROBE_DEFER)
dev_err(host->dev,
"regulator_enable fail: %d\n", ret);
goto err_clk_ciu;
}
}
if (!host->bus_hz) {
dev_err(host->dev,
"Platform data must supply bus speed\n");
ret = -ENODEV;
goto err_regulator;
}
host->quirks = host->pdata->quirks;
spin_lock_init(&host->lock);
INIT_LIST_HEAD(&host->queue);
i = (mci_readl(host, HCON) >> 7) & 0x7;
if (!i) {
host->push_data = dw_mci_push_data16;
host->pull_data = dw_mci_pull_data16;
width = 16;
host->data_shift = 1;
} else if (i == 2) {
host->push_data = dw_mci_push_data64;
host->pull_data = dw_mci_pull_data64;
width = 64;
host->data_shift = 3;
} else {
WARN((i != 1),
"HCON reports a reserved host data width!\n"
"Defaulting to 32-bit access.\n");
host->push_data = dw_mci_push_data32;
host->pull_data = dw_mci_pull_data32;
width = 32;
host->data_shift = 2;
}
if (!dw_mci_ctrl_all_reset(host))
return -ENODEV;
host->dma_ops = host->pdata->dma_ops;
dw_mci_init_dma(host);
mci_writel(host, RINTSTS, 0xFFFFFFFF);
mci_writel(host, INTMASK, 0);
mci_writel(host, TMOUT, 0xFFFFFFFF);
if (!host->pdata->fifo_depth) {
fifo_size = mci_readl(host, FIFOTH);
fifo_size = 1 + ((fifo_size >> 16) & 0xfff);
} else {
fifo_size = host->pdata->fifo_depth;
}
host->fifo_depth = fifo_size;
host->fifoth_val =
SDMMC_SET_FIFOTH(0x2, fifo_size / 2 - 1, fifo_size / 2);
mci_writel(host, FIFOTH, host->fifoth_val);
mci_writel(host, CLKENA, 0);
mci_writel(host, CLKSRC, 0);
host->verid = SDMMC_GET_VERID(mci_readl(host, VERID));
dev_info(host->dev, "Version ID is %04x\n", host->verid);
if (host->verid < DW_MMC_240A)
host->data_offset = DATA_OFFSET;
else
host->data_offset = DATA_240A_OFFSET;
tasklet_init(&host->tasklet, dw_mci_tasklet_func, (unsigned long)host);
host->card_workqueue = alloc_workqueue("dw-mci-card",
WQ_MEM_RECLAIM | WQ_NON_REENTRANT, 1);
if (!host->card_workqueue) {
ret = -ENOMEM;
goto err_dmaunmap;
}
INIT_WORK(&host->card_work, dw_mci_work_routine_card);
ret = devm_request_irq(host->dev, host->irq, dw_mci_interrupt,
host->irq_flags, "dw-mci", host);
if (ret)
goto err_workqueue;
if (host->pdata->num_slots)
host->num_slots = host->pdata->num_slots;
else
host->num_slots = ((mci_readl(host, HCON) >> 1) & 0x1F) + 1;
mci_writel(host, RINTSTS, 0xFFFFFFFF);
mci_writel(host, INTMASK, SDMMC_INT_CMD_DONE | SDMMC_INT_DATA_OVER |
SDMMC_INT_TXDR | SDMMC_INT_RXDR |
DW_MCI_ERROR_FLAGS | SDMMC_INT_CD);
mci_writel(host, CTRL, SDMMC_CTRL_INT_ENABLE);
dev_info(host->dev, "DW MMC controller at irq %d, "
"%d bit host data width, "
"%u deep fifo\n",
host->irq, width, fifo_size);
for (i = 0; i < host->num_slots; i++) {
ret = dw_mci_init_slot(host, i);
if (ret)
dev_dbg(host->dev, "slot %d init failed\n", i);
else
init_slots++;
}
if (init_slots) {
dev_info(host->dev, "%d slots initialized\n", init_slots);
} else {
dev_dbg(host->dev, "attempted to initialize %d slots, "
"but failed on all\n", host->num_slots);
goto err_workqueue;
}
if (host->quirks & DW_MCI_QUIRK_IDMAC_DTO)
dev_info(host->dev, "Internal DMAC interrupt fix enabled.\n");
return 0;
err_workqueue:
destroy_workqueue(host->card_workqueue);
err_dmaunmap:
if (host->use_dma && host->dma_ops->exit)
host->dma_ops->exit(host);
err_regulator:
if (host->vmmc)
regulator_disable(host->vmmc);
err_clk_ciu:
if (!IS_ERR(host->ciu_clk))
clk_disable_unprepare(host->ciu_clk);
err_clk_biu:
if (!IS_ERR(host->biu_clk))
clk_disable_unprepare(host->biu_clk);
return ret;
}
void dw_mci_remove(struct dw_mci *host)
{
int i;
mci_writel(host, RINTSTS, 0xFFFFFFFF);
mci_writel(host, INTMASK, 0);
for (i = 0; i < host->num_slots; i++) {
dev_dbg(host->dev, "remove slot %d\n", i);
if (host->slot[i])
dw_mci_cleanup_slot(host->slot[i], i);
}
mci_writel(host, CLKENA, 0);
mci_writel(host, CLKSRC, 0);
destroy_workqueue(host->card_workqueue);
if (host->use_dma && host->dma_ops->exit)
host->dma_ops->exit(host);
if (host->vmmc)
regulator_disable(host->vmmc);
if (!IS_ERR(host->ciu_clk))
clk_disable_unprepare(host->ciu_clk);
if (!IS_ERR(host->biu_clk))
clk_disable_unprepare(host->biu_clk);
}
int dw_mci_suspend(struct dw_mci *host)
{
if (host->vmmc)
regulator_disable(host->vmmc);
return 0;
}
int dw_mci_resume(struct dw_mci *host)
{
int i, ret;
if (host->vmmc) {
ret = regulator_enable(host->vmmc);
if (ret) {
dev_err(host->dev,
"failed to enable regulator: %d\n", ret);
return ret;
}
}
if (!dw_mci_ctrl_all_reset(host)) {
ret = -ENODEV;
return ret;
}
if (host->use_dma && host->dma_ops->init)
host->dma_ops->init(host);
mci_writel(host, FIFOTH, host->fifoth_val);
host->prev_blksz = 0;
mci_writel(host, TMOUT, 0xFFFFFFFF);
mci_writel(host, RINTSTS, 0xFFFFFFFF);
mci_writel(host, INTMASK, SDMMC_INT_CMD_DONE | SDMMC_INT_DATA_OVER |
SDMMC_INT_TXDR | SDMMC_INT_RXDR |
DW_MCI_ERROR_FLAGS | SDMMC_INT_CD);
mci_writel(host, CTRL, SDMMC_CTRL_INT_ENABLE);
for (i = 0; i < host->num_slots; i++) {
struct dw_mci_slot *slot = host->slot[i];
if (!slot)
continue;
if (slot->mmc->pm_flags & MMC_PM_KEEP_POWER) {
dw_mci_set_ios(slot->mmc, &slot->mmc->ios);
dw_mci_setup_bus(slot, true);
}
}
return 0;
}
static int __init dw_mci_init(void)
{
pr_info("Synopsys Designware Multimedia Card Interface Driver\n");
return 0;
}
static void __exit dw_mci_exit(void)
{
}
