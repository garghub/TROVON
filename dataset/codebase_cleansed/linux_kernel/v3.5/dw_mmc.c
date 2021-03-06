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
u32 cmdr;
cmd->error = -EINPROGRESS;
cmdr = cmd->opcode;
if (cmdr == MMC_STOP_TRANSMISSION)
cmdr |= SDMMC_CMD_STOP;
else
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
return cmdr;
}
static void dw_mci_start_command(struct dw_mci *host,
struct mmc_command *cmd, u32 cmd_flags)
{
host->cmd = cmd;
dev_vdbg(&host->dev,
"start command: ARGR=0x%08x CMDR=0x%08x\n",
cmd->arg, cmd_flags);
mci_writel(host, CMDARG, cmd->arg);
wmb();
mci_writel(host, CMD, cmd_flags | SDMMC_CMD_START);
}
static void send_stop_cmd(struct dw_mci *host, struct mmc_data *data)
{
dw_mci_start_command(host, data->stop, host->stop_cmdr);
}
static void dw_mci_stop_dma(struct dw_mci *host)
{
if (host->using_dma) {
host->dma_ops->stop(host);
host->dma_ops->cleanup(host);
} else {
set_bit(EVENT_XFER_COMPLETE, &host->pending_events);
}
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
dma_unmap_sg(&host->dev,
data->sg,
data->sg_len,
dw_mci_get_dma_dir(data));
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
mci_writel(host, BMOD, temp);
}
static void dw_mci_idmac_complete_dma(struct dw_mci *host)
{
struct mmc_data *data = host->data;
dev_vdbg(&host->dev, "DMA complete\n");
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
mci_writel(host, BMOD, SDMMC_IDMAC_SWRESET);
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
sg_len = dma_map_sg(&host->dev,
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
dma_unmap_sg(&slot->host->dev,
data->sg,
data->sg_len,
dw_mci_get_dma_dir(data));
data->host_cookie = 0;
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
dev_vdbg(&host->dev,
"sd sg_cpu: %#lx sg_dma: %#lx sg_len: %d\n",
(unsigned long)host->sg_cpu, (unsigned long)host->sg_dma,
sg_len);
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
if (data->flags & MMC_DATA_READ)
host->dir_status = DW_MCI_RECV_STATUS;
else
host->dir_status = DW_MCI_SEND_STATUS;
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
static void dw_mci_setup_bus(struct dw_mci_slot *slot)
{
struct dw_mci *host = slot->host;
u32 div;
if (slot->clock != host->current_speed) {
div = host->bus_hz / slot->clock;
if (host->bus_hz % slot->clock && host->bus_hz > slot->clock)
div += 1;
div = (host->bus_hz != slot->clock) ? DIV_ROUND_UP(div, 2) : 0;
dev_info(&slot->mmc->class_dev,
"Bus speed (slot %d) = %dHz (slot req %dHz, actual %dHZ"
" div = %d)\n", slot->id, host->bus_hz, slot->clock,
div ? ((host->bus_hz / div) >> 1) : host->bus_hz, div);
mci_writel(host, CLKENA, 0);
mci_writel(host, CLKSRC, 0);
mci_send_cmd(slot,
SDMMC_CMD_UPD_CLK | SDMMC_CMD_PRV_DAT_WAIT, 0);
mci_writel(host, CLKDIV, div);
mci_send_cmd(slot,
SDMMC_CMD_UPD_CLK | SDMMC_CMD_PRV_DAT_WAIT, 0);
mci_writel(host, CLKENA, ((SDMMC_CLKEN_ENABLE |
SDMMC_CLKEN_LOW_PWR) << slot->id));
mci_send_cmd(slot,
SDMMC_CMD_UPD_CLK | SDMMC_CMD_PRV_DAT_WAIT, 0);
host->current_speed = slot->clock;
}
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
dw_mci_setup_bus(slot);
host->cur_slot = slot;
host->mrq = mrq;
host->pending_events = 0;
host->completed_events = 0;
host->data_status = 0;
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
u32 regs;
slot->ctype = SDMMC_CTYPE_1BIT;
switch (ios->bus_width) {
case MMC_BUS_WIDTH_1:
slot->ctype = SDMMC_CTYPE_1BIT;
break;
case MMC_BUS_WIDTH_4:
slot->ctype = SDMMC_CTYPE_4BIT;
break;
case MMC_BUS_WIDTH_8:
slot->ctype = SDMMC_CTYPE_8BIT;
break;
}
regs = mci_readl(slot->host, UHS_REG);
if (ios->timing == MMC_TIMING_UHS_DDR50)
regs |= (0x1 << slot->id) << 16;
else
regs &= ~(0x1 << slot->id) << 16;
mci_writel(slot->host, UHS_REG, regs);
if (ios->clock) {
slot->clock = ios->clock;
}
switch (ios->power_mode) {
case MMC_POWER_UP:
set_bit(DW_MMC_CARD_NEED_INIT, &slot->flags);
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
if (brd->get_ro)
read_only = brd->get_ro(slot->id);
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
static void dw_mci_enable_sdio_irq(struct mmc_host *mmc, int enb)
{
struct dw_mci_slot *slot = mmc_priv(mmc);
struct dw_mci *host = slot->host;
u32 int_mask;
int_mask = mci_readl(host, INTMASK);
if (enb) {
mci_writel(host, INTMASK,
(int_mask | SDMMC_INT_SDIO(slot->id)));
} else {
mci_writel(host, INTMASK,
(int_mask & ~SDMMC_INT_SDIO(slot->id)));
}
}
static void dw_mci_request_end(struct dw_mci *host, struct mmc_request *mrq)
__releases(&host->lock
static void dw_mci_command_complete(struct dw_mci *host, struct mmc_command *cmd)
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
if (cmd->data) {
dw_mci_stop_dma(host);
host->data = NULL;
}
}
}
static void dw_mci_tasklet_func(unsigned long priv)
{
struct dw_mci *host = (struct dw_mci *)priv;
struct mmc_data *data;
struct mmc_command *cmd;
enum dw_mci_state state;
enum dw_mci_state prev_state;
u32 status, ctrl;
spin_lock(&host->lock);
state = host->state;
data = host->data;
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
dw_mci_command_complete(host, cmd);
if (cmd == host->mrq->sbc && !cmd->error) {
prev_state = state = STATE_SENDING_CMD;
__dw_mci_start_request(host, host->cur_slot,
host->mrq->cmd);
goto unlock;
}
if (!host->mrq->data || cmd->error) {
dw_mci_request_end(host, host->mrq);
goto unlock;
}
prev_state = state = STATE_SENDING_DATA;
case STATE_SENDING_DATA:
if (test_and_clear_bit(EVENT_DATA_ERROR,
&host->pending_events)) {
dw_mci_stop_dma(host);
if (data->stop)
send_stop_cmd(host, data);
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
status = host->data_status;
if (status & DW_MCI_DATA_ERROR_FLAGS) {
if (status & SDMMC_INT_DTO) {
data->error = -ETIMEDOUT;
} else if (status & SDMMC_INT_DCRC) {
data->error = -EILSEQ;
} else if (status & SDMMC_INT_EBE &&
host->dir_status ==
DW_MCI_SEND_STATUS) {
data->bytes_xfered = 0;
data->error = -ETIMEDOUT;
} else {
dev_err(&host->dev,
"data FIFO error "
"(status=%08x)\n",
status);
data->error = -EIO;
}
sg_miter_stop(&host->sg_miter);
host->sg = NULL;
ctrl = mci_readl(host, CTRL);
ctrl |= SDMMC_CTRL_FIFO_RESET;
mci_writel(host, CTRL, ctrl);
} else {
data->bytes_xfered = data->blocks * data->blksz;
data->error = 0;
}
if (!data->stop) {
dw_mci_request_end(host, host->mrq);
goto unlock;
}
if (host->mrq->sbc && !data->error) {
data->stop->error = 0;
dw_mci_request_end(host, host->mrq);
goto unlock;
}
prev_state = state = STATE_SENDING_STOP;
if (!data->error)
send_stop_cmd(host, data);
case STATE_SENDING_STOP:
if (!test_and_clear_bit(EVENT_CMD_COMPLETE,
&host->pending_events))
break;
host->cmd = NULL;
dw_mci_command_complete(host, host->mrq->stop);
dw_mci_request_end(host, host->mrq);
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
if (unlikely(host->part_buf_count)) {
int len = dw_mci_push_part_bytes(host, buf, cnt);
buf += len;
cnt -= len;
if (!sg_next(host->sg) || host->part_buf_count == 2) {
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
if (!sg_next(host->sg))
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
if (unlikely(host->part_buf_count)) {
int len = dw_mci_push_part_bytes(host, buf, cnt);
buf += len;
cnt -= len;
if (!sg_next(host->sg) || host->part_buf_count == 4) {
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
if (!sg_next(host->sg))
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
if (unlikely(host->part_buf_count)) {
int len = dw_mci_push_part_bytes(host, buf, cnt);
buf += len;
cnt -= len;
if (!sg_next(host->sg) || host->part_buf_count == 8) {
mci_writew(host, DATA(host->data_offset),
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
if (!sg_next(host->sg))
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
static void dw_mci_read_data_pio(struct dw_mci *host)
{
struct sg_mapping_iter *sg_miter = &host->sg_miter;
void *buf;
unsigned int offset;
struct mmc_data *data = host->data;
int shift = host->data_shift;
u32 status;
unsigned int nbytes = 0, len;
unsigned int remain, fcnt;
do {
if (!sg_miter_next(sg_miter))
goto done;
host->sg = sg_miter->__sg;
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
offset += len;
nbytes += len;
remain -= len;
} while (remain);
sg_miter->consumed = offset;
status = mci_readl(host, MINTSTS);
mci_writel(host, RINTSTS, SDMMC_INT_RXDR);
if (status & DW_MCI_DATA_ERROR_FLAGS) {
host->data_status = status;
data->bytes_xfered += nbytes;
sg_miter_stop(sg_miter);
host->sg = NULL;
smp_wmb();
set_bit(EVENT_DATA_ERROR, &host->pending_events);
tasklet_schedule(&host->tasklet);
return;
}
} while (status & SDMMC_INT_RXDR);
data->bytes_xfered += nbytes;
if (!remain) {
if (!sg_miter_next(sg_miter))
goto done;
sg_miter->consumed = 0;
}
sg_miter_stop(sg_miter);
return;
done:
data->bytes_xfered += nbytes;
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
unsigned int nbytes = 0, len;
unsigned int fifo_depth = host->fifo_depth;
unsigned int remain, fcnt;
do {
if (!sg_miter_next(sg_miter))
goto done;
host->sg = sg_miter->__sg;
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
offset += len;
nbytes += len;
remain -= len;
} while (remain);
sg_miter->consumed = offset;
status = mci_readl(host, MINTSTS);
mci_writel(host, RINTSTS, SDMMC_INT_TXDR);
if (status & DW_MCI_DATA_ERROR_FLAGS) {
host->data_status = status;
data->bytes_xfered += nbytes;
sg_miter_stop(sg_miter);
host->sg = NULL;
smp_wmb();
set_bit(EVENT_DATA_ERROR, &host->pending_events);
tasklet_schedule(&host->tasklet);
return;
}
} while (status & SDMMC_INT_TXDR);
data->bytes_xfered += nbytes;
if (!remain) {
if (!sg_miter_next(sg_miter))
goto done;
sg_miter->consumed = 0;
}
sg_miter_stop(sg_miter);
return;
done:
data->bytes_xfered += nbytes;
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
u32 status, pending;
unsigned int pass_count = 0;
int i;
do {
status = mci_readl(host, RINTSTS);
pending = mci_readl(host, MINTSTS);
if (host->quirks & DW_MCI_QUIRK_IDMAC_DTO) {
if (!pending &&
((mci_readl(host, STATUS) >> 17) & 0x1fff))
pending |= SDMMC_INT_DATA_OVER;
}
if (!pending)
break;
if (pending & DW_MCI_CMD_ERROR_FLAGS) {
mci_writel(host, RINTSTS, DW_MCI_CMD_ERROR_FLAGS);
host->cmd_status = status;
smp_wmb();
set_bit(EVENT_CMD_COMPLETE, &host->pending_events);
}
if (pending & DW_MCI_DATA_ERROR_FLAGS) {
mci_writel(host, RINTSTS, DW_MCI_DATA_ERROR_FLAGS);
host->data_status = status;
smp_wmb();
set_bit(EVENT_DATA_ERROR, &host->pending_events);
if (!(pending & (SDMMC_INT_DTO | SDMMC_INT_DCRC |
SDMMC_INT_SBE | SDMMC_INT_EBE)))
tasklet_schedule(&host->tasklet);
}
if (pending & SDMMC_INT_DATA_OVER) {
mci_writel(host, RINTSTS, SDMMC_INT_DATA_OVER);
if (!host->data_status)
host->data_status = status;
smp_wmb();
if (host->dir_status == DW_MCI_RECV_STATUS) {
if (host->sg != NULL)
dw_mci_read_data_pio(host);
}
set_bit(EVENT_DATA_COMPLETE, &host->pending_events);
tasklet_schedule(&host->tasklet);
}
if (pending & SDMMC_INT_RXDR) {
mci_writel(host, RINTSTS, SDMMC_INT_RXDR);
if (host->dir_status == DW_MCI_RECV_STATUS && host->sg)
dw_mci_read_data_pio(host);
}
if (pending & SDMMC_INT_TXDR) {
mci_writel(host, RINTSTS, SDMMC_INT_TXDR);
if (host->dir_status == DW_MCI_SEND_STATUS && host->sg)
dw_mci_write_data_pio(host);
}
if (pending & SDMMC_INT_CMD_DONE) {
mci_writel(host, RINTSTS, SDMMC_INT_CMD_DONE);
dw_mci_cmd_interrupt(host, status);
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
} while (pass_count++ < 5);
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
u32 ctrl;
present = dw_mci_get_cd(mmc);
while (present != slot->last_detect_state) {
dev_dbg(&slot->mmc->class_dev, "card %s\n",
present ? "inserted" : "removed");
if (present != 0 && host->pdata->setpower)
host->pdata->setpower(slot->id, mmc->ocr_avail);
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
if (!mrq->stop)
break;
case STATE_SENDING_STOP:
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
sg_miter_stop(&host->sg_miter);
host->sg = NULL;
ctrl = mci_readl(host, CTRL);
ctrl |= SDMMC_CTRL_FIFO_RESET;
mci_writel(host, CTRL, ctrl);
#ifdef CONFIG_MMC_DW_IDMAC
ctrl = mci_readl(host, BMOD);
ctrl |= SDMMC_IDMAC_SWRESET;
mci_writel(host, BMOD, ctrl);
#endif
}
spin_unlock_bh(&host->lock);
if (present == 0 && host->pdata->setpower)
host->pdata->setpower(slot->id, 0);
present = dw_mci_get_cd(mmc);
}
mmc_detect_change(slot->mmc,
msecs_to_jiffies(host->pdata->detect_delay_ms));
}
}
static int __init dw_mci_init_slot(struct dw_mci *host, unsigned int id)
{
struct mmc_host *mmc;
struct dw_mci_slot *slot;
mmc = mmc_alloc_host(sizeof(struct dw_mci_slot), &host->dev);
if (!mmc)
return -ENOMEM;
slot = mmc_priv(mmc);
slot->id = id;
slot->mmc = mmc;
slot->host = host;
mmc->ops = &dw_mci_ops;
mmc->f_min = DIV_ROUND_UP(host->bus_hz, 510);
mmc->f_max = host->bus_hz;
if (host->pdata->get_ocr)
mmc->ocr_avail = host->pdata->get_ocr(id);
else
mmc->ocr_avail = MMC_VDD_32_33 | MMC_VDD_33_34;
if (host->pdata->setpower)
host->pdata->setpower(id, 0);
if (host->pdata->caps)
mmc->caps = host->pdata->caps;
if (host->pdata->caps2)
mmc->caps2 = host->pdata->caps2;
if (host->pdata->get_bus_wd)
if (host->pdata->get_bus_wd(slot->id) >= 4)
mmc->caps |= MMC_CAP_4_BIT_DATA;
if (host->pdata->quirks & DW_MCI_QUIRK_HIGHSPEED)
mmc->caps |= MMC_CAP_SD_HIGHSPEED | MMC_CAP_MMC_HIGHSPEED;
if (mmc->caps2 & MMC_CAP2_POWEROFF_NOTIFY)
mmc->power_notify_type = MMC_HOST_PW_NOTIFY_SHORT;
else
mmc->power_notify_type = MMC_HOST_PW_NOTIFY_NONE;
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
host->vmmc = regulator_get(mmc_dev(mmc), "vmmc");
if (IS_ERR(host->vmmc)) {
pr_info("%s: no vmmc regulator found\n", mmc_hostname(mmc));
host->vmmc = NULL;
} else
regulator_enable(host->vmmc);
if (dw_mci_get_cd(mmc))
set_bit(DW_MMC_CARD_PRESENT, &slot->flags);
else
clear_bit(DW_MMC_CARD_PRESENT, &slot->flags);
host->slot[id] = slot;
mmc_add_host(mmc);
#if defined(CONFIG_DEBUG_FS)
dw_mci_init_debugfs(slot);
#endif
slot->last_detect_state = 0;
queue_work(host->card_workqueue, &host->card_work);
return 0;
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
host->sg_cpu = dma_alloc_coherent(&host->dev, PAGE_SIZE,
&host->sg_dma, GFP_KERNEL);
if (!host->sg_cpu) {
dev_err(&host->dev, "%s: could not alloc DMA memory\n",
__func__);
goto no_dma;
}
#ifdef CONFIG_MMC_DW_IDMAC
host->dma_ops = &dw_mci_idmac_ops;
dev_info(&host->dev, "Using internal DMA controller.\n");
#endif
if (!host->dma_ops)
goto no_dma;
if (host->dma_ops->init && host->dma_ops->start &&
host->dma_ops->stop && host->dma_ops->cleanup) {
if (host->dma_ops->init(host)) {
dev_err(&host->dev, "%s: Unable to initialize "
"DMA Controller.\n", __func__);
goto no_dma;
}
} else {
dev_err(&host->dev, "DMA initialization not found.\n");
goto no_dma;
}
host->use_dma = 1;
return;
no_dma:
dev_info(&host->dev, "Using PIO mode.\n");
host->use_dma = 0;
return;
}
static bool mci_wait_reset(struct device *dev, struct dw_mci *host)
{
unsigned long timeout = jiffies + msecs_to_jiffies(500);
unsigned int ctrl;
mci_writel(host, CTRL, (SDMMC_CTRL_RESET | SDMMC_CTRL_FIFO_RESET |
SDMMC_CTRL_DMA_RESET));
do {
ctrl = mci_readl(host, CTRL);
if (!(ctrl & (SDMMC_CTRL_RESET | SDMMC_CTRL_FIFO_RESET |
SDMMC_CTRL_DMA_RESET)))
return true;
} while (time_before(jiffies, timeout));
dev_err(dev, "Timeout resetting block (ctrl %#x)\n", ctrl);
return false;
}
int dw_mci_probe(struct dw_mci *host)
{
int width, i, ret = 0;
u32 fifo_size;
if (!host->pdata || !host->pdata->init) {
dev_err(&host->dev,
"Platform data must supply init function\n");
return -ENODEV;
}
if (!host->pdata->select_slot && host->pdata->num_slots > 1) {
dev_err(&host->dev,
"Platform data must supply select_slot function\n");
return -ENODEV;
}
if (!host->pdata->bus_hz) {
dev_err(&host->dev,
"Platform data must supply bus speed\n");
return -ENODEV;
}
host->bus_hz = host->pdata->bus_hz;
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
if (!mci_wait_reset(&host->dev, host))
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
host->fifoth_val = ((0x2 << 28) | ((fifo_size/2 - 1) << 16) |
((fifo_size/2) << 0));
mci_writel(host, FIFOTH, host->fifoth_val);
mci_writel(host, CLKENA, 0);
mci_writel(host, CLKSRC, 0);
tasklet_init(&host->tasklet, dw_mci_tasklet_func, (unsigned long)host);
host->card_workqueue = alloc_workqueue("dw-mci-card",
WQ_MEM_RECLAIM | WQ_NON_REENTRANT, 1);
if (!host->card_workqueue)
goto err_dmaunmap;
INIT_WORK(&host->card_work, dw_mci_work_routine_card);
ret = request_irq(host->irq, dw_mci_interrupt, host->irq_flags, "dw-mci", host);
if (ret)
goto err_workqueue;
if (host->pdata->num_slots)
host->num_slots = host->pdata->num_slots;
else
host->num_slots = ((mci_readl(host, HCON) >> 1) & 0x1F) + 1;
for (i = 0; i < host->num_slots; i++) {
ret = dw_mci_init_slot(host, i);
if (ret) {
ret = -ENODEV;
goto err_init_slot;
}
}
host->verid = SDMMC_GET_VERID(mci_readl(host, VERID));
dev_info(&host->dev, "Version ID is %04x\n", host->verid);
if (host->verid < DW_MMC_240A)
host->data_offset = DATA_OFFSET;
else
host->data_offset = DATA_240A_OFFSET;
mci_writel(host, RINTSTS, 0xFFFFFFFF);
mci_writel(host, INTMASK, SDMMC_INT_CMD_DONE | SDMMC_INT_DATA_OVER |
SDMMC_INT_TXDR | SDMMC_INT_RXDR |
DW_MCI_ERROR_FLAGS | SDMMC_INT_CD);
mci_writel(host, CTRL, SDMMC_CTRL_INT_ENABLE);
dev_info(&host->dev, "DW MMC controller at irq %d, "
"%d bit host data width, "
"%u deep fifo\n",
host->irq, width, fifo_size);
if (host->quirks & DW_MCI_QUIRK_IDMAC_DTO)
dev_info(&host->dev, "Internal DMAC interrupt fix enabled.\n");
return 0;
err_init_slot:
while (i > 0) {
if (host->slot[i])
dw_mci_cleanup_slot(host->slot[i], i);
i--;
}
free_irq(host->irq, host);
err_workqueue:
destroy_workqueue(host->card_workqueue);
err_dmaunmap:
if (host->use_dma && host->dma_ops->exit)
host->dma_ops->exit(host);
dma_free_coherent(&host->dev, PAGE_SIZE,
host->sg_cpu, host->sg_dma);
if (host->vmmc) {
regulator_disable(host->vmmc);
regulator_put(host->vmmc);
}
return ret;
}
void dw_mci_remove(struct dw_mci *host)
{
int i;
mci_writel(host, RINTSTS, 0xFFFFFFFF);
mci_writel(host, INTMASK, 0);
for (i = 0; i < host->num_slots; i++) {
dev_dbg(&host->dev, "remove slot %d\n", i);
if (host->slot[i])
dw_mci_cleanup_slot(host->slot[i], i);
}
mci_writel(host, CLKENA, 0);
mci_writel(host, CLKSRC, 0);
free_irq(host->irq, host);
destroy_workqueue(host->card_workqueue);
dma_free_coherent(&host->dev, PAGE_SIZE, host->sg_cpu, host->sg_dma);
if (host->use_dma && host->dma_ops->exit)
host->dma_ops->exit(host);
if (host->vmmc) {
regulator_disable(host->vmmc);
regulator_put(host->vmmc);
}
}
int dw_mci_suspend(struct dw_mci *host)
{
int i, ret = 0;
for (i = 0; i < host->num_slots; i++) {
struct dw_mci_slot *slot = host->slot[i];
if (!slot)
continue;
ret = mmc_suspend_host(slot->mmc);
if (ret < 0) {
while (--i >= 0) {
slot = host->slot[i];
if (slot)
mmc_resume_host(host->slot[i]->mmc);
}
return ret;
}
}
if (host->vmmc)
regulator_disable(host->vmmc);
return 0;
}
int dw_mci_resume(struct dw_mci *host)
{
int i, ret;
if (host->vmmc)
regulator_enable(host->vmmc);
if (!mci_wait_reset(&host->dev, host)) {
ret = -ENODEV;
return ret;
}
if (host->dma_ops->init)
host->dma_ops->init(host);
mci_writel(host, FIFOTH, host->fifoth_val);
mci_writel(host, RINTSTS, 0xFFFFFFFF);
mci_writel(host, INTMASK, SDMMC_INT_CMD_DONE | SDMMC_INT_DATA_OVER |
SDMMC_INT_TXDR | SDMMC_INT_RXDR |
DW_MCI_ERROR_FLAGS | SDMMC_INT_CD);
mci_writel(host, CTRL, SDMMC_CTRL_INT_ENABLE);
for (i = 0; i < host->num_slots; i++) {
struct dw_mci_slot *slot = host->slot[i];
if (!slot)
continue;
ret = mmc_resume_host(host->slot[i]->mmc);
if (ret < 0)
return ret;
}
return 0;
}
static int __init dw_mci_init(void)
{
printk(KERN_INFO "Synopsys Designware Multimedia Card Interface Driver");
return 0;
}
static void __exit dw_mci_exit(void)
{
}
