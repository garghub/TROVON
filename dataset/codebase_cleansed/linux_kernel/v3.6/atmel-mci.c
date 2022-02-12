static int atmci_req_show(struct seq_file *s, void *v)
{
struct atmel_mci_slot *slot = s->private;
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
cmd->resp[3], cmd->error);
if (data)
seq_printf(s, "DATA %u / %u * %u flg %x err %d\n",
data->bytes_xfered, data->blocks,
data->blksz, data->flags, data->error);
if (stop)
seq_printf(s,
"CMD%u(0x%x) flg %x rsp %x %x %x %x err %d\n",
stop->opcode, stop->arg, stop->flags,
stop->resp[0], stop->resp[1], stop->resp[2],
stop->resp[3], stop->error);
}
spin_unlock_bh(&slot->host->lock);
return 0;
}
static int atmci_req_open(struct inode *inode, struct file *file)
{
return single_open(file, atmci_req_show, inode->i_private);
}
static void atmci_show_status_reg(struct seq_file *s,
const char *regname, u32 value)
{
static const char *sr_bit[] = {
[0] = "CMDRDY",
[1] = "RXRDY",
[2] = "TXRDY",
[3] = "BLKE",
[4] = "DTIP",
[5] = "NOTBUSY",
[6] = "ENDRX",
[7] = "ENDTX",
[8] = "SDIOIRQA",
[9] = "SDIOIRQB",
[12] = "SDIOWAIT",
[14] = "RXBUFF",
[15] = "TXBUFE",
[16] = "RINDE",
[17] = "RDIRE",
[18] = "RCRCE",
[19] = "RENDE",
[20] = "RTOE",
[21] = "DCRCE",
[22] = "DTOE",
[23] = "CSTOE",
[24] = "BLKOVRE",
[25] = "DMADONE",
[26] = "FIFOEMPTY",
[27] = "XFRDONE",
[30] = "OVRE",
[31] = "UNRE",
};
unsigned int i;
seq_printf(s, "%s:\t0x%08x", regname, value);
for (i = 0; i < ARRAY_SIZE(sr_bit); i++) {
if (value & (1 << i)) {
if (sr_bit[i])
seq_printf(s, " %s", sr_bit[i]);
else
seq_puts(s, " UNKNOWN");
}
}
seq_putc(s, '\n');
}
static int atmci_regs_show(struct seq_file *s, void *v)
{
struct atmel_mci *host = s->private;
u32 *buf;
buf = kmalloc(ATMCI_REGS_SIZE, GFP_KERNEL);
if (!buf)
return -ENOMEM;
spin_lock_bh(&host->lock);
clk_enable(host->mck);
memcpy_fromio(buf, host->regs, ATMCI_REGS_SIZE);
clk_disable(host->mck);
spin_unlock_bh(&host->lock);
seq_printf(s, "MR:\t0x%08x%s%s ",
buf[ATMCI_MR / 4],
buf[ATMCI_MR / 4] & ATMCI_MR_RDPROOF ? " RDPROOF" : "",
buf[ATMCI_MR / 4] & ATMCI_MR_WRPROOF ? " WRPROOF" : "");
if (host->caps.has_odd_clk_div)
seq_printf(s, "{CLKDIV,CLKODD}=%u\n",
((buf[ATMCI_MR / 4] & 0xff) << 1)
| ((buf[ATMCI_MR / 4] >> 16) & 1));
else
seq_printf(s, "CLKDIV=%u\n",
(buf[ATMCI_MR / 4] & 0xff));
seq_printf(s, "DTOR:\t0x%08x\n", buf[ATMCI_DTOR / 4]);
seq_printf(s, "SDCR:\t0x%08x\n", buf[ATMCI_SDCR / 4]);
seq_printf(s, "ARGR:\t0x%08x\n", buf[ATMCI_ARGR / 4]);
seq_printf(s, "BLKR:\t0x%08x BCNT=%u BLKLEN=%u\n",
buf[ATMCI_BLKR / 4],
buf[ATMCI_BLKR / 4] & 0xffff,
(buf[ATMCI_BLKR / 4] >> 16) & 0xffff);
if (host->caps.has_cstor_reg)
seq_printf(s, "CSTOR:\t0x%08x\n", buf[ATMCI_CSTOR / 4]);
atmci_show_status_reg(s, "SR", buf[ATMCI_SR / 4]);
atmci_show_status_reg(s, "IMR", buf[ATMCI_IMR / 4]);
if (host->caps.has_dma) {
u32 val;
val = buf[ATMCI_DMA / 4];
seq_printf(s, "DMA:\t0x%08x OFFSET=%u CHKSIZE=%u%s\n",
val, val & 3,
((val >> 4) & 3) ?
1 << (((val >> 4) & 3) + 1) : 1,
val & ATMCI_DMAEN ? " DMAEN" : "");
}
if (host->caps.has_cfg_reg) {
u32 val;
val = buf[ATMCI_CFG / 4];
seq_printf(s, "CFG:\t0x%08x%s%s%s%s\n",
val,
val & ATMCI_CFG_FIFOMODE_1DATA ? " FIFOMODE_ONE_DATA" : "",
val & ATMCI_CFG_FERRCTRL_COR ? " FERRCTRL_CLEAR_ON_READ" : "",
val & ATMCI_CFG_HSMODE ? " HSMODE" : "",
val & ATMCI_CFG_LSYNC ? " LSYNC" : "");
}
kfree(buf);
return 0;
}
static int atmci_regs_open(struct inode *inode, struct file *file)
{
return single_open(file, atmci_regs_show, inode->i_private);
}
static void atmci_init_debugfs(struct atmel_mci_slot *slot)
{
struct mmc_host *mmc = slot->mmc;
struct atmel_mci *host = slot->host;
struct dentry *root;
struct dentry *node;
root = mmc->debugfs_root;
if (!root)
return;
node = debugfs_create_file("regs", S_IRUSR, root, host,
&atmci_regs_fops);
if (IS_ERR(node))
return;
if (!node)
goto err;
node = debugfs_create_file("req", S_IRUSR, root, slot, &atmci_req_fops);
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
static inline unsigned int atmci_get_version(struct atmel_mci *host)
{
return atmci_readl(host, ATMCI_VERSION) & 0x00000fff;
}
static void atmci_timeout_timer(unsigned long data)
{
struct atmel_mci *host;
host = (struct atmel_mci *)data;
dev_dbg(&host->pdev->dev, "software timeout\n");
if (host->mrq->cmd->data) {
host->mrq->cmd->data->error = -ETIMEDOUT;
host->data = NULL;
} else {
host->mrq->cmd->error = -ETIMEDOUT;
host->cmd = NULL;
}
host->need_reset = 1;
host->state = STATE_END_REQUEST;
smp_wmb();
tasklet_schedule(&host->tasklet);
}
static inline unsigned int atmci_ns_to_clocks(struct atmel_mci *host,
unsigned int ns)
{
unsigned int us = DIV_ROUND_UP(ns, 1000);
return us * (DIV_ROUND_UP(host->bus_hz, 2000000));
}
static void atmci_set_timeout(struct atmel_mci *host,
struct atmel_mci_slot *slot, struct mmc_data *data)
{
static unsigned dtomul_to_shift[] = {
0, 4, 7, 8, 10, 12, 16, 20
};
unsigned timeout;
unsigned dtocyc;
unsigned dtomul;
timeout = atmci_ns_to_clocks(host, data->timeout_ns)
+ data->timeout_clks;
for (dtomul = 0; dtomul < 8; dtomul++) {
unsigned shift = dtomul_to_shift[dtomul];
dtocyc = (timeout + (1 << shift) - 1) >> shift;
if (dtocyc < 15)
break;
}
if (dtomul >= 8) {
dtomul = 7;
dtocyc = 15;
}
dev_vdbg(&slot->mmc->class_dev, "setting timeout to %u cycles\n",
dtocyc << dtomul_to_shift[dtomul]);
atmci_writel(host, ATMCI_DTOR, (ATMCI_DTOMUL(dtomul) | ATMCI_DTOCYC(dtocyc)));
}
static u32 atmci_prepare_command(struct mmc_host *mmc,
struct mmc_command *cmd)
{
struct mmc_data *data;
u32 cmdr;
cmd->error = -EINPROGRESS;
cmdr = ATMCI_CMDR_CMDNB(cmd->opcode);
if (cmd->flags & MMC_RSP_PRESENT) {
if (cmd->flags & MMC_RSP_136)
cmdr |= ATMCI_CMDR_RSPTYP_136BIT;
else
cmdr |= ATMCI_CMDR_RSPTYP_48BIT;
}
cmdr |= ATMCI_CMDR_MAXLAT_64CYC;
if (mmc->ios.bus_mode == MMC_BUSMODE_OPENDRAIN)
cmdr |= ATMCI_CMDR_OPDCMD;
data = cmd->data;
if (data) {
cmdr |= ATMCI_CMDR_START_XFER;
if (cmd->opcode == SD_IO_RW_EXTENDED) {
cmdr |= ATMCI_CMDR_SDIO_BLOCK;
} else {
if (data->flags & MMC_DATA_STREAM)
cmdr |= ATMCI_CMDR_STREAM;
else if (data->blocks > 1)
cmdr |= ATMCI_CMDR_MULTI_BLOCK;
else
cmdr |= ATMCI_CMDR_BLOCK;
}
if (data->flags & MMC_DATA_READ)
cmdr |= ATMCI_CMDR_TRDIR_READ;
}
return cmdr;
}
static void atmci_send_command(struct atmel_mci *host,
struct mmc_command *cmd, u32 cmd_flags)
{
WARN_ON(host->cmd);
host->cmd = cmd;
dev_vdbg(&host->pdev->dev,
"start command: ARGR=0x%08x CMDR=0x%08x\n",
cmd->arg, cmd_flags);
atmci_writel(host, ATMCI_ARGR, cmd->arg);
atmci_writel(host, ATMCI_CMDR, cmd_flags);
}
static void atmci_send_stop_cmd(struct atmel_mci *host, struct mmc_data *data)
{
dev_dbg(&host->pdev->dev, "send stop command\n");
atmci_send_command(host, data->stop, host->stop_cmdr);
atmci_writel(host, ATMCI_IER, ATMCI_CMDRDY);
}
static void atmci_pdc_set_single_buf(struct atmel_mci *host,
enum atmci_xfer_dir dir, enum atmci_pdc_buf buf_nb)
{
u32 pointer_reg, counter_reg;
unsigned int buf_size;
if (dir == XFER_RECEIVE) {
pointer_reg = ATMEL_PDC_RPR;
counter_reg = ATMEL_PDC_RCR;
} else {
pointer_reg = ATMEL_PDC_TPR;
counter_reg = ATMEL_PDC_TCR;
}
if (buf_nb == PDC_SECOND_BUF) {
pointer_reg += ATMEL_PDC_SCND_BUF_OFF;
counter_reg += ATMEL_PDC_SCND_BUF_OFF;
}
if (!host->caps.has_rwproof) {
buf_size = host->buf_size;
atmci_writel(host, pointer_reg, host->buf_phys_addr);
} else {
buf_size = sg_dma_len(host->sg);
atmci_writel(host, pointer_reg, sg_dma_address(host->sg));
}
if (host->data_size <= buf_size) {
if (host->data_size & 0x3) {
atmci_writel(host, counter_reg, host->data_size);
atmci_writel(host, ATMCI_MR, host->mode_reg | ATMCI_MR_PDCFBYTE);
} else {
atmci_writel(host, counter_reg, host->data_size / 4);
}
host->data_size = 0;
} else {
atmci_writel(host, counter_reg, sg_dma_len(host->sg) / 4);
host->data_size -= sg_dma_len(host->sg);
if (host->data_size)
host->sg = sg_next(host->sg);
}
}
static void atmci_pdc_set_both_buf(struct atmel_mci *host, int dir)
{
atmci_pdc_set_single_buf(host, dir, PDC_FIRST_BUF);
if (host->data_size)
atmci_pdc_set_single_buf(host, dir, PDC_SECOND_BUF);
}
static void atmci_pdc_cleanup(struct atmel_mci *host)
{
struct mmc_data *data = host->data;
if (data)
dma_unmap_sg(&host->pdev->dev,
data->sg, data->sg_len,
((data->flags & MMC_DATA_WRITE)
? DMA_TO_DEVICE : DMA_FROM_DEVICE));
}
static void atmci_pdc_complete(struct atmel_mci *host)
{
int transfer_size = host->data->blocks * host->data->blksz;
int i;
atmci_writel(host, ATMEL_PDC_PTCR, ATMEL_PDC_RXTDIS | ATMEL_PDC_TXTDIS);
if ((!host->caps.has_rwproof)
&& (host->data->flags & MMC_DATA_READ)) {
if (host->caps.has_bad_data_ordering)
for (i = 0; i < transfer_size; i++)
host->buffer[i] = swab32(host->buffer[i]);
sg_copy_from_buffer(host->data->sg, host->data->sg_len,
host->buffer, transfer_size);
}
atmci_pdc_cleanup(host);
if (host->data) {
dev_dbg(&host->pdev->dev,
"(%s) set pending xfer complete\n", __func__);
atmci_set_pending(host, EVENT_XFER_COMPLETE);
tasklet_schedule(&host->tasklet);
}
}
static void atmci_dma_cleanup(struct atmel_mci *host)
{
struct mmc_data *data = host->data;
if (data)
dma_unmap_sg(host->dma.chan->device->dev,
data->sg, data->sg_len,
((data->flags & MMC_DATA_WRITE)
? DMA_TO_DEVICE : DMA_FROM_DEVICE));
}
static void atmci_dma_complete(void *arg)
{
struct atmel_mci *host = arg;
struct mmc_data *data = host->data;
dev_vdbg(&host->pdev->dev, "DMA complete\n");
if (host->caps.has_dma)
atmci_writel(host, ATMCI_DMA, atmci_readl(host, ATMCI_DMA) & ~ATMCI_DMAEN);
atmci_dma_cleanup(host);
if (data) {
dev_dbg(&host->pdev->dev,
"(%s) set pending xfer complete\n", __func__);
atmci_set_pending(host, EVENT_XFER_COMPLETE);
tasklet_schedule(&host->tasklet);
atmci_writel(host, ATMCI_IER, ATMCI_NOTBUSY);
}
}
static u32 atmci_prepare_data(struct atmel_mci *host, struct mmc_data *data)
{
u32 iflags;
data->error = -EINPROGRESS;
host->sg = data->sg;
host->data = data;
host->data_chan = NULL;
iflags = ATMCI_DATA_ERROR_FLAGS;
if (data->blocks * data->blksz < 12
|| (data->blocks * data->blksz) & 3)
host->need_reset = true;
host->pio_offset = 0;
if (data->flags & MMC_DATA_READ)
iflags |= ATMCI_RXRDY;
else
iflags |= ATMCI_TXRDY;
return iflags;
}
static u32
atmci_prepare_data_pdc(struct atmel_mci *host, struct mmc_data *data)
{
u32 iflags, tmp;
unsigned int sg_len;
enum dma_data_direction dir;
int i;
data->error = -EINPROGRESS;
host->data = data;
host->sg = data->sg;
iflags = ATMCI_DATA_ERROR_FLAGS;
atmci_writel(host, ATMCI_MR, host->mode_reg | ATMCI_MR_PDCMODE);
if (data->flags & MMC_DATA_READ) {
dir = DMA_FROM_DEVICE;
iflags |= ATMCI_ENDRX | ATMCI_RXBUFF;
} else {
dir = DMA_TO_DEVICE;
iflags |= ATMCI_ENDTX | ATMCI_TXBUFE | ATMCI_BLKE;
}
tmp = atmci_readl(host, ATMCI_MR);
tmp &= 0x0000ffff;
tmp |= ATMCI_BLKLEN(data->blksz);
atmci_writel(host, ATMCI_MR, tmp);
host->data_size = data->blocks * data->blksz;
sg_len = dma_map_sg(&host->pdev->dev, data->sg, data->sg_len, dir);
if ((!host->caps.has_rwproof)
&& (host->data->flags & MMC_DATA_WRITE)) {
sg_copy_to_buffer(host->data->sg, host->data->sg_len,
host->buffer, host->data_size);
if (host->caps.has_bad_data_ordering)
for (i = 0; i < host->data_size; i++)
host->buffer[i] = swab32(host->buffer[i]);
}
if (host->data_size)
atmci_pdc_set_both_buf(host,
((dir == DMA_FROM_DEVICE) ? XFER_RECEIVE : XFER_TRANSMIT));
return iflags;
}
static u32
atmci_prepare_data_dma(struct atmel_mci *host, struct mmc_data *data)
{
struct dma_chan *chan;
struct dma_async_tx_descriptor *desc;
struct scatterlist *sg;
unsigned int i;
enum dma_data_direction direction;
enum dma_transfer_direction slave_dirn;
unsigned int sglen;
u32 maxburst;
u32 iflags;
data->error = -EINPROGRESS;
WARN_ON(host->data);
host->sg = NULL;
host->data = data;
iflags = ATMCI_DATA_ERROR_FLAGS;
if (data->blocks * data->blksz < ATMCI_DMA_THRESHOLD)
return atmci_prepare_data(host, data);
if (data->blksz & 3)
return atmci_prepare_data(host, data);
for_each_sg(data->sg, sg, data->sg_len, i) {
if (sg->offset & 3 || sg->length & 3)
return atmci_prepare_data(host, data);
}
chan = host->dma.chan;
if (chan)
host->data_chan = chan;
if (!chan)
return -ENODEV;
if (data->flags & MMC_DATA_READ) {
direction = DMA_FROM_DEVICE;
host->dma_conf.direction = slave_dirn = DMA_DEV_TO_MEM;
maxburst = atmci_convert_chksize(host->dma_conf.src_maxburst);
} else {
direction = DMA_TO_DEVICE;
host->dma_conf.direction = slave_dirn = DMA_MEM_TO_DEV;
maxburst = atmci_convert_chksize(host->dma_conf.dst_maxburst);
}
atmci_writel(host, ATMCI_DMA, ATMCI_DMA_CHKSIZE(maxburst) | ATMCI_DMAEN);
sglen = dma_map_sg(chan->device->dev, data->sg,
data->sg_len, direction);
dmaengine_slave_config(chan, &host->dma_conf);
desc = dmaengine_prep_slave_sg(chan,
data->sg, sglen, slave_dirn,
DMA_PREP_INTERRUPT | DMA_CTRL_ACK);
if (!desc)
goto unmap_exit;
host->dma.data_desc = desc;
desc->callback = atmci_dma_complete;
desc->callback_param = host;
return iflags;
unmap_exit:
dma_unmap_sg(chan->device->dev, data->sg, data->sg_len, direction);
return -ENOMEM;
}
static void
atmci_submit_data(struct atmel_mci *host, struct mmc_data *data)
{
return;
}
static void
atmci_submit_data_pdc(struct atmel_mci *host, struct mmc_data *data)
{
if (data->flags & MMC_DATA_READ)
atmci_writel(host, ATMEL_PDC_PTCR, ATMEL_PDC_RXTEN);
else
atmci_writel(host, ATMEL_PDC_PTCR, ATMEL_PDC_TXTEN);
}
static void
atmci_submit_data_dma(struct atmel_mci *host, struct mmc_data *data)
{
struct dma_chan *chan = host->data_chan;
struct dma_async_tx_descriptor *desc = host->dma.data_desc;
if (chan) {
dmaengine_submit(desc);
dma_async_issue_pending(chan);
}
}
static void atmci_stop_transfer(struct atmel_mci *host)
{
dev_dbg(&host->pdev->dev,
"(%s) set pending xfer complete\n", __func__);
atmci_set_pending(host, EVENT_XFER_COMPLETE);
atmci_writel(host, ATMCI_IER, ATMCI_NOTBUSY);
}
static void atmci_stop_transfer_pdc(struct atmel_mci *host)
{
atmci_writel(host, ATMEL_PDC_PTCR, ATMEL_PDC_RXTDIS | ATMEL_PDC_TXTDIS);
}
static void atmci_stop_transfer_dma(struct atmel_mci *host)
{
struct dma_chan *chan = host->data_chan;
if (chan) {
dmaengine_terminate_all(chan);
atmci_dma_cleanup(host);
} else {
dev_dbg(&host->pdev->dev,
"(%s) set pending xfer complete\n", __func__);
atmci_set_pending(host, EVENT_XFER_COMPLETE);
atmci_writel(host, ATMCI_IER, ATMCI_NOTBUSY);
}
}
static void atmci_start_request(struct atmel_mci *host,
struct atmel_mci_slot *slot)
{
struct mmc_request *mrq;
struct mmc_command *cmd;
struct mmc_data *data;
u32 iflags;
u32 cmdflags;
mrq = slot->mrq;
host->cur_slot = slot;
host->mrq = mrq;
host->pending_events = 0;
host->completed_events = 0;
host->cmd_status = 0;
host->data_status = 0;
dev_dbg(&host->pdev->dev, "start request: cmd %u\n", mrq->cmd->opcode);
if (host->need_reset || host->caps.need_reset_after_xfer) {
iflags = atmci_readl(host, ATMCI_IMR);
iflags &= (ATMCI_SDIOIRQA | ATMCI_SDIOIRQB);
atmci_writel(host, ATMCI_CR, ATMCI_CR_SWRST);
atmci_writel(host, ATMCI_CR, ATMCI_CR_MCIEN);
atmci_writel(host, ATMCI_MR, host->mode_reg);
if (host->caps.has_cfg_reg)
atmci_writel(host, ATMCI_CFG, host->cfg_reg);
atmci_writel(host, ATMCI_IER, iflags);
host->need_reset = false;
}
atmci_writel(host, ATMCI_SDCR, slot->sdc_reg);
iflags = atmci_readl(host, ATMCI_IMR);
if (iflags & ~(ATMCI_SDIOIRQA | ATMCI_SDIOIRQB))
dev_dbg(&slot->mmc->class_dev, "WARNING: IMR=0x%08x\n",
iflags);
if (unlikely(test_and_clear_bit(ATMCI_CARD_NEED_INIT, &slot->flags))) {
atmci_writel(host, ATMCI_CMDR, ATMCI_CMDR_SPCMD_INIT);
while (!(atmci_readl(host, ATMCI_SR) & ATMCI_CMDRDY))
cpu_relax();
}
iflags = 0;
data = mrq->data;
if (data) {
atmci_set_timeout(host, slot, data);
atmci_writel(host, ATMCI_BLKR, ATMCI_BCNT(data->blocks)
| ATMCI_BLKLEN(data->blksz));
dev_vdbg(&slot->mmc->class_dev, "BLKR=0x%08x\n",
ATMCI_BCNT(data->blocks) | ATMCI_BLKLEN(data->blksz));
iflags |= host->prepare_data(host, data);
}
iflags |= ATMCI_CMDRDY;
cmd = mrq->cmd;
cmdflags = atmci_prepare_command(slot->mmc, cmd);
atmci_send_command(host, cmd, cmdflags);
if (data)
host->submit_data(host, data);
if (mrq->stop) {
host->stop_cmdr = atmci_prepare_command(slot->mmc, mrq->stop);
host->stop_cmdr |= ATMCI_CMDR_STOP_XFER;
if (!(data->flags & MMC_DATA_WRITE))
host->stop_cmdr |= ATMCI_CMDR_TRDIR_READ;
if (data->flags & MMC_DATA_STREAM)
host->stop_cmdr |= ATMCI_CMDR_STREAM;
else
host->stop_cmdr |= ATMCI_CMDR_MULTI_BLOCK;
}
atmci_writel(host, ATMCI_IER, iflags);
mod_timer(&host->timer, jiffies + msecs_to_jiffies(2000));
}
static void atmci_queue_request(struct atmel_mci *host,
struct atmel_mci_slot *slot, struct mmc_request *mrq)
{
dev_vdbg(&slot->mmc->class_dev, "queue request: state=%d\n",
host->state);
spin_lock_bh(&host->lock);
slot->mrq = mrq;
if (host->state == STATE_IDLE) {
host->state = STATE_SENDING_CMD;
atmci_start_request(host, slot);
} else {
dev_dbg(&host->pdev->dev, "queue request\n");
list_add_tail(&slot->queue_node, &host->queue);
}
spin_unlock_bh(&host->lock);
}
static void atmci_request(struct mmc_host *mmc, struct mmc_request *mrq)
{
struct atmel_mci_slot *slot = mmc_priv(mmc);
struct atmel_mci *host = slot->host;
struct mmc_data *data;
WARN_ON(slot->mrq);
dev_dbg(&host->pdev->dev, "MRQ: cmd %u\n", mrq->cmd->opcode);
if (!test_bit(ATMCI_CARD_PRESENT, &slot->flags)) {
mrq->cmd->error = -ENOMEDIUM;
mmc_request_done(mmc, mrq);
return;
}
data = mrq->data;
if (data && data->blocks > 1 && data->blksz & 3) {
mrq->cmd->error = -EINVAL;
mmc_request_done(mmc, mrq);
}
atmci_queue_request(host, slot, mrq);
}
static void atmci_set_ios(struct mmc_host *mmc, struct mmc_ios *ios)
{
struct atmel_mci_slot *slot = mmc_priv(mmc);
struct atmel_mci *host = slot->host;
unsigned int i;
slot->sdc_reg &= ~ATMCI_SDCBUS_MASK;
switch (ios->bus_width) {
case MMC_BUS_WIDTH_1:
slot->sdc_reg |= ATMCI_SDCBUS_1BIT;
break;
case MMC_BUS_WIDTH_4:
slot->sdc_reg |= ATMCI_SDCBUS_4BIT;
break;
}
if (ios->clock) {
unsigned int clock_min = ~0U;
u32 clkdiv;
spin_lock_bh(&host->lock);
if (!host->mode_reg) {
clk_enable(host->mck);
atmci_writel(host, ATMCI_CR, ATMCI_CR_SWRST);
atmci_writel(host, ATMCI_CR, ATMCI_CR_MCIEN);
if (host->caps.has_cfg_reg)
atmci_writel(host, ATMCI_CFG, host->cfg_reg);
}
slot->clock = ios->clock;
for (i = 0; i < ATMCI_MAX_NR_SLOTS; i++) {
if (host->slot[i] && host->slot[i]->clock
&& host->slot[i]->clock < clock_min)
clock_min = host->slot[i]->clock;
}
if (host->caps.has_odd_clk_div) {
clkdiv = DIV_ROUND_UP(host->bus_hz, clock_min) - 2;
if (clkdiv > 511) {
dev_warn(&mmc->class_dev,
"clock %u too slow; using %lu\n",
clock_min, host->bus_hz / (511 + 2));
clkdiv = 511;
}
host->mode_reg = ATMCI_MR_CLKDIV(clkdiv >> 1)
| ATMCI_MR_CLKODD(clkdiv & 1);
} else {
clkdiv = DIV_ROUND_UP(host->bus_hz, 2 * clock_min) - 1;
if (clkdiv > 255) {
dev_warn(&mmc->class_dev,
"clock %u too slow; using %lu\n",
clock_min, host->bus_hz / (2 * 256));
clkdiv = 255;
}
host->mode_reg = ATMCI_MR_CLKDIV(clkdiv);
}
if (host->caps.has_rwproof)
host->mode_reg |= (ATMCI_MR_WRPROOF | ATMCI_MR_RDPROOF);
if (host->caps.has_cfg_reg) {
if (ios->timing == MMC_TIMING_SD_HS)
host->cfg_reg |= ATMCI_CFG_HSMODE;
else
host->cfg_reg &= ~ATMCI_CFG_HSMODE;
}
if (list_empty(&host->queue)) {
atmci_writel(host, ATMCI_MR, host->mode_reg);
if (host->caps.has_cfg_reg)
atmci_writel(host, ATMCI_CFG, host->cfg_reg);
} else {
host->need_clock_update = true;
}
spin_unlock_bh(&host->lock);
} else {
bool any_slot_active = false;
spin_lock_bh(&host->lock);
slot->clock = 0;
for (i = 0; i < ATMCI_MAX_NR_SLOTS; i++) {
if (host->slot[i] && host->slot[i]->clock) {
any_slot_active = true;
break;
}
}
if (!any_slot_active) {
atmci_writel(host, ATMCI_CR, ATMCI_CR_MCIDIS);
if (host->mode_reg) {
atmci_readl(host, ATMCI_MR);
clk_disable(host->mck);
}
host->mode_reg = 0;
}
spin_unlock_bh(&host->lock);
}
switch (ios->power_mode) {
case MMC_POWER_UP:
set_bit(ATMCI_CARD_NEED_INIT, &slot->flags);
break;
default:
break;
}
}
static int atmci_get_ro(struct mmc_host *mmc)
{
int read_only = -ENOSYS;
struct atmel_mci_slot *slot = mmc_priv(mmc);
if (gpio_is_valid(slot->wp_pin)) {
read_only = gpio_get_value(slot->wp_pin);
dev_dbg(&mmc->class_dev, "card is %s\n",
read_only ? "read-only" : "read-write");
}
return read_only;
}
static int atmci_get_cd(struct mmc_host *mmc)
{
int present = -ENOSYS;
struct atmel_mci_slot *slot = mmc_priv(mmc);
if (gpio_is_valid(slot->detect_pin)) {
present = !(gpio_get_value(slot->detect_pin) ^
slot->detect_is_active_high);
dev_dbg(&mmc->class_dev, "card is %spresent\n",
present ? "" : "not ");
}
return present;
}
static void atmci_enable_sdio_irq(struct mmc_host *mmc, int enable)
{
struct atmel_mci_slot *slot = mmc_priv(mmc);
struct atmel_mci *host = slot->host;
if (enable)
atmci_writel(host, ATMCI_IER, slot->sdio_irq);
else
atmci_writel(host, ATMCI_IDR, slot->sdio_irq);
}
static void atmci_request_end(struct atmel_mci *host, struct mmc_request *mrq)
__releases(&host->lock
static void atmci_command_complete(struct atmel_mci *host,
struct mmc_command *cmd)
{
u32 status = host->cmd_status;
cmd->resp[0] = atmci_readl(host, ATMCI_RSPR);
cmd->resp[1] = atmci_readl(host, ATMCI_RSPR);
cmd->resp[2] = atmci_readl(host, ATMCI_RSPR);
cmd->resp[3] = atmci_readl(host, ATMCI_RSPR);
if (status & ATMCI_RTOE)
cmd->error = -ETIMEDOUT;
else if ((cmd->flags & MMC_RSP_CRC) && (status & ATMCI_RCRCE))
cmd->error = -EILSEQ;
else if (status & (ATMCI_RINDE | ATMCI_RDIRE | ATMCI_RENDE))
cmd->error = -EIO;
else if (host->mrq->data && (host->mrq->data->blksz & 3)) {
if (host->caps.need_blksz_mul_4) {
cmd->error = -EINVAL;
host->need_reset = 1;
}
} else
cmd->error = 0;
}
static void atmci_detect_change(unsigned long data)
{
struct atmel_mci_slot *slot = (struct atmel_mci_slot *)data;
bool present;
bool present_old;
smp_rmb();
if (test_bit(ATMCI_SHUTDOWN, &slot->flags))
return;
enable_irq(gpio_to_irq(slot->detect_pin));
present = !(gpio_get_value(slot->detect_pin) ^
slot->detect_is_active_high);
present_old = test_bit(ATMCI_CARD_PRESENT, &slot->flags);
dev_vdbg(&slot->mmc->class_dev, "detect change: %d (was %d)\n",
present, present_old);
if (present != present_old) {
struct atmel_mci *host = slot->host;
struct mmc_request *mrq;
dev_dbg(&slot->mmc->class_dev, "card %s\n",
present ? "inserted" : "removed");
spin_lock(&host->lock);
if (!present)
clear_bit(ATMCI_CARD_PRESENT, &slot->flags);
else
set_bit(ATMCI_CARD_PRESENT, &slot->flags);
mrq = slot->mrq;
if (mrq) {
if (mrq == host->mrq) {
atmci_writel(host, ATMCI_CR, ATMCI_CR_SWRST);
atmci_writel(host, ATMCI_CR, ATMCI_CR_MCIEN);
atmci_writel(host, ATMCI_MR, host->mode_reg);
if (host->caps.has_cfg_reg)
atmci_writel(host, ATMCI_CFG, host->cfg_reg);
host->data = NULL;
host->cmd = NULL;
switch (host->state) {
case STATE_IDLE:
break;
case STATE_SENDING_CMD:
mrq->cmd->error = -ENOMEDIUM;
if (mrq->data)
host->stop_transfer(host);
break;
case STATE_DATA_XFER:
mrq->data->error = -ENOMEDIUM;
host->stop_transfer(host);
break;
case STATE_WAITING_NOTBUSY:
mrq->data->error = -ENOMEDIUM;
break;
case STATE_SENDING_STOP:
mrq->stop->error = -ENOMEDIUM;
break;
case STATE_END_REQUEST:
break;
}
atmci_request_end(host, mrq);
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
spin_unlock(&host->lock);
mmc_detect_change(slot->mmc, 0);
}
}
static void atmci_tasklet_func(unsigned long priv)
{
struct atmel_mci *host = (struct atmel_mci *)priv;
struct mmc_request *mrq = host->mrq;
struct mmc_data *data = host->data;
enum atmel_mci_state state = host->state;
enum atmel_mci_state prev_state;
u32 status;
spin_lock(&host->lock);
state = host->state;
dev_vdbg(&host->pdev->dev,
"tasklet: state %u pending/completed/mask %lx/%lx/%x\n",
state, host->pending_events, host->completed_events,
atmci_readl(host, ATMCI_IMR));
do {
prev_state = state;
dev_dbg(&host->pdev->dev, "FSM: state=%d\n", state);
switch (state) {
case STATE_IDLE:
break;
case STATE_SENDING_CMD:
dev_dbg(&host->pdev->dev, "FSM: cmd ready?\n");
if (!atmci_test_and_clear_pending(host,
EVENT_CMD_RDY))
break;
dev_dbg(&host->pdev->dev, "set completed cmd ready\n");
host->cmd = NULL;
atmci_set_completed(host, EVENT_CMD_RDY);
atmci_command_complete(host, mrq->cmd);
if (mrq->data) {
dev_dbg(&host->pdev->dev,
"command with data transfer");
if (mrq->cmd->error) {
host->stop_transfer(host);
host->data = NULL;
atmci_writel(host, ATMCI_IDR,
ATMCI_TXRDY | ATMCI_RXRDY
| ATMCI_DATA_ERROR_FLAGS);
state = STATE_END_REQUEST;
} else
state = STATE_DATA_XFER;
} else if ((!mrq->data) && (mrq->cmd->flags & MMC_RSP_BUSY)) {
dev_dbg(&host->pdev->dev,
"command response need waiting notbusy");
atmci_writel(host, ATMCI_IER, ATMCI_NOTBUSY);
state = STATE_WAITING_NOTBUSY;
} else
state = STATE_END_REQUEST;
break;
case STATE_DATA_XFER:
if (atmci_test_and_clear_pending(host,
EVENT_DATA_ERROR)) {
dev_dbg(&host->pdev->dev, "set completed data error\n");
atmci_set_completed(host, EVENT_DATA_ERROR);
state = STATE_END_REQUEST;
break;
}
dev_dbg(&host->pdev->dev, "FSM: xfer complete?\n");
if (!atmci_test_and_clear_pending(host,
EVENT_XFER_COMPLETE))
break;
dev_dbg(&host->pdev->dev,
"(%s) set completed xfer complete\n",
__func__);
atmci_set_completed(host, EVENT_XFER_COMPLETE);
if (host->caps.need_notbusy_for_read_ops ||
(host->data->flags & MMC_DATA_WRITE)) {
atmci_writel(host, ATMCI_IER, ATMCI_NOTBUSY);
state = STATE_WAITING_NOTBUSY;
} else if (host->mrq->stop) {
atmci_writel(host, ATMCI_IER, ATMCI_CMDRDY);
atmci_send_stop_cmd(host, data);
state = STATE_SENDING_STOP;
} else {
host->data = NULL;
data->bytes_xfered = data->blocks * data->blksz;
data->error = 0;
state = STATE_END_REQUEST;
}
break;
case STATE_WAITING_NOTBUSY:
dev_dbg(&host->pdev->dev, "FSM: not busy?\n");
if (!atmci_test_and_clear_pending(host,
EVENT_NOTBUSY))
break;
dev_dbg(&host->pdev->dev, "set completed not busy\n");
atmci_set_completed(host, EVENT_NOTBUSY);
if (host->data) {
if (host->mrq->stop) {
atmci_writel(host, ATMCI_IER,
ATMCI_CMDRDY);
atmci_send_stop_cmd(host, data);
state = STATE_SENDING_STOP;
} else {
host->data = NULL;
data->bytes_xfered = data->blocks
* data->blksz;
data->error = 0;
state = STATE_END_REQUEST;
}
} else
state = STATE_END_REQUEST;
break;
case STATE_SENDING_STOP:
dev_dbg(&host->pdev->dev, "FSM: cmd ready?\n");
if (!atmci_test_and_clear_pending(host,
EVENT_CMD_RDY))
break;
dev_dbg(&host->pdev->dev, "FSM: cmd ready\n");
host->cmd = NULL;
data->bytes_xfered = data->blocks * data->blksz;
data->error = 0;
atmci_command_complete(host, mrq->stop);
if (mrq->stop->error) {
host->stop_transfer(host);
atmci_writel(host, ATMCI_IDR,
ATMCI_TXRDY | ATMCI_RXRDY
| ATMCI_DATA_ERROR_FLAGS);
state = STATE_END_REQUEST;
} else {
atmci_writel(host, ATMCI_IER, ATMCI_NOTBUSY);
state = STATE_WAITING_NOTBUSY;
}
host->data = NULL;
break;
case STATE_END_REQUEST:
atmci_writel(host, ATMCI_IDR, ATMCI_TXRDY | ATMCI_RXRDY
| ATMCI_DATA_ERROR_FLAGS);
status = host->data_status;
if (unlikely(status)) {
host->stop_transfer(host);
host->data = NULL;
if (status & ATMCI_DTOE) {
data->error = -ETIMEDOUT;
} else if (status & ATMCI_DCRCE) {
data->error = -EILSEQ;
} else {
data->error = -EIO;
}
}
atmci_request_end(host, host->mrq);
state = STATE_IDLE;
break;
}
} while (state != prev_state);
host->state = state;
spin_unlock(&host->lock);
}
static void atmci_read_data_pio(struct atmel_mci *host)
{
struct scatterlist *sg = host->sg;
void *buf = sg_virt(sg);
unsigned int offset = host->pio_offset;
struct mmc_data *data = host->data;
u32 value;
u32 status;
unsigned int nbytes = 0;
do {
value = atmci_readl(host, ATMCI_RDR);
if (likely(offset + 4 <= sg->length)) {
put_unaligned(value, (u32 *)(buf + offset));
offset += 4;
nbytes += 4;
if (offset == sg->length) {
flush_dcache_page(sg_page(sg));
host->sg = sg = sg_next(sg);
if (!sg)
goto done;
offset = 0;
buf = sg_virt(sg);
}
} else {
unsigned int remaining = sg->length - offset;
memcpy(buf + offset, &value, remaining);
nbytes += remaining;
flush_dcache_page(sg_page(sg));
host->sg = sg = sg_next(sg);
if (!sg)
goto done;
offset = 4 - remaining;
buf = sg_virt(sg);
memcpy(buf, (u8 *)&value + remaining, offset);
nbytes += offset;
}
status = atmci_readl(host, ATMCI_SR);
if (status & ATMCI_DATA_ERROR_FLAGS) {
atmci_writel(host, ATMCI_IDR, (ATMCI_NOTBUSY | ATMCI_RXRDY
| ATMCI_DATA_ERROR_FLAGS));
host->data_status = status;
data->bytes_xfered += nbytes;
return;
}
} while (status & ATMCI_RXRDY);
host->pio_offset = offset;
data->bytes_xfered += nbytes;
return;
done:
atmci_writel(host, ATMCI_IDR, ATMCI_RXRDY);
atmci_writel(host, ATMCI_IER, ATMCI_NOTBUSY);
data->bytes_xfered += nbytes;
smp_wmb();
atmci_set_pending(host, EVENT_XFER_COMPLETE);
}
static void atmci_write_data_pio(struct atmel_mci *host)
{
struct scatterlist *sg = host->sg;
void *buf = sg_virt(sg);
unsigned int offset = host->pio_offset;
struct mmc_data *data = host->data;
u32 value;
u32 status;
unsigned int nbytes = 0;
do {
if (likely(offset + 4 <= sg->length)) {
value = get_unaligned((u32 *)(buf + offset));
atmci_writel(host, ATMCI_TDR, value);
offset += 4;
nbytes += 4;
if (offset == sg->length) {
host->sg = sg = sg_next(sg);
if (!sg)
goto done;
offset = 0;
buf = sg_virt(sg);
}
} else {
unsigned int remaining = sg->length - offset;
value = 0;
memcpy(&value, buf + offset, remaining);
nbytes += remaining;
host->sg = sg = sg_next(sg);
if (!sg) {
atmci_writel(host, ATMCI_TDR, value);
goto done;
}
offset = 4 - remaining;
buf = sg_virt(sg);
memcpy((u8 *)&value + remaining, buf, offset);
atmci_writel(host, ATMCI_TDR, value);
nbytes += offset;
}
status = atmci_readl(host, ATMCI_SR);
if (status & ATMCI_DATA_ERROR_FLAGS) {
atmci_writel(host, ATMCI_IDR, (ATMCI_NOTBUSY | ATMCI_TXRDY
| ATMCI_DATA_ERROR_FLAGS));
host->data_status = status;
data->bytes_xfered += nbytes;
return;
}
} while (status & ATMCI_TXRDY);
host->pio_offset = offset;
data->bytes_xfered += nbytes;
return;
done:
atmci_writel(host, ATMCI_IDR, ATMCI_TXRDY);
atmci_writel(host, ATMCI_IER, ATMCI_NOTBUSY);
data->bytes_xfered += nbytes;
smp_wmb();
atmci_set_pending(host, EVENT_XFER_COMPLETE);
}
static void atmci_sdio_interrupt(struct atmel_mci *host, u32 status)
{
int i;
for (i = 0; i < ATMCI_MAX_NR_SLOTS; i++) {
struct atmel_mci_slot *slot = host->slot[i];
if (slot && (status & slot->sdio_irq)) {
mmc_signal_sdio_irq(slot->mmc);
}
}
}
static irqreturn_t atmci_interrupt(int irq, void *dev_id)
{
struct atmel_mci *host = dev_id;
u32 status, mask, pending;
unsigned int pass_count = 0;
do {
status = atmci_readl(host, ATMCI_SR);
mask = atmci_readl(host, ATMCI_IMR);
pending = status & mask;
if (!pending)
break;
if (pending & ATMCI_DATA_ERROR_FLAGS) {
dev_dbg(&host->pdev->dev, "IRQ: data error\n");
atmci_writel(host, ATMCI_IDR, ATMCI_DATA_ERROR_FLAGS
| ATMCI_RXRDY | ATMCI_TXRDY
| ATMCI_ENDRX | ATMCI_ENDTX
| ATMCI_RXBUFF | ATMCI_TXBUFE);
host->data_status = status;
dev_dbg(&host->pdev->dev, "set pending data error\n");
smp_wmb();
atmci_set_pending(host, EVENT_DATA_ERROR);
tasklet_schedule(&host->tasklet);
}
if (pending & ATMCI_TXBUFE) {
dev_dbg(&host->pdev->dev, "IRQ: tx buffer empty\n");
atmci_writel(host, ATMCI_IDR, ATMCI_TXBUFE);
atmci_writel(host, ATMCI_IDR, ATMCI_ENDTX);
if (host->data_size) {
atmci_pdc_set_both_buf(host, XFER_TRANSMIT);
atmci_writel(host, ATMCI_IER, ATMCI_ENDTX);
atmci_writel(host, ATMCI_IER, ATMCI_TXBUFE);
} else {
atmci_pdc_complete(host);
}
} else if (pending & ATMCI_ENDTX) {
dev_dbg(&host->pdev->dev, "IRQ: end of tx buffer\n");
atmci_writel(host, ATMCI_IDR, ATMCI_ENDTX);
if (host->data_size) {
atmci_pdc_set_single_buf(host,
XFER_TRANSMIT, PDC_SECOND_BUF);
atmci_writel(host, ATMCI_IER, ATMCI_ENDTX);
}
}
if (pending & ATMCI_RXBUFF) {
dev_dbg(&host->pdev->dev, "IRQ: rx buffer full\n");
atmci_writel(host, ATMCI_IDR, ATMCI_RXBUFF);
atmci_writel(host, ATMCI_IDR, ATMCI_ENDRX);
if (host->data_size) {
atmci_pdc_set_both_buf(host, XFER_RECEIVE);
atmci_writel(host, ATMCI_IER, ATMCI_ENDRX);
atmci_writel(host, ATMCI_IER, ATMCI_RXBUFF);
} else {
atmci_pdc_complete(host);
}
} else if (pending & ATMCI_ENDRX) {
dev_dbg(&host->pdev->dev, "IRQ: end of rx buffer\n");
atmci_writel(host, ATMCI_IDR, ATMCI_ENDRX);
if (host->data_size) {
atmci_pdc_set_single_buf(host,
XFER_RECEIVE, PDC_SECOND_BUF);
atmci_writel(host, ATMCI_IER, ATMCI_ENDRX);
}
}
if (pending & ATMCI_BLKE) {
dev_dbg(&host->pdev->dev, "IRQ: blke\n");
atmci_writel(host, ATMCI_IDR, ATMCI_BLKE);
smp_wmb();
dev_dbg(&host->pdev->dev, "set pending notbusy\n");
atmci_set_pending(host, EVENT_NOTBUSY);
tasklet_schedule(&host->tasklet);
}
if (pending & ATMCI_NOTBUSY) {
dev_dbg(&host->pdev->dev, "IRQ: not_busy\n");
atmci_writel(host, ATMCI_IDR, ATMCI_NOTBUSY);
smp_wmb();
dev_dbg(&host->pdev->dev, "set pending notbusy\n");
atmci_set_pending(host, EVENT_NOTBUSY);
tasklet_schedule(&host->tasklet);
}
if (pending & ATMCI_RXRDY)
atmci_read_data_pio(host);
if (pending & ATMCI_TXRDY)
atmci_write_data_pio(host);
if (pending & ATMCI_CMDRDY) {
dev_dbg(&host->pdev->dev, "IRQ: cmd ready\n");
atmci_writel(host, ATMCI_IDR, ATMCI_CMDRDY);
host->cmd_status = status;
smp_wmb();
dev_dbg(&host->pdev->dev, "set pending cmd rdy\n");
atmci_set_pending(host, EVENT_CMD_RDY);
tasklet_schedule(&host->tasklet);
}
if (pending & (ATMCI_SDIOIRQA | ATMCI_SDIOIRQB))
atmci_sdio_interrupt(host, status);
} while (pass_count++ < 5);
return pass_count ? IRQ_HANDLED : IRQ_NONE;
}
static irqreturn_t atmci_detect_interrupt(int irq, void *dev_id)
{
struct atmel_mci_slot *slot = dev_id;
disable_irq_nosync(irq);
mod_timer(&slot->detect_timer, jiffies + msecs_to_jiffies(20));
return IRQ_HANDLED;
}
static int __init atmci_init_slot(struct atmel_mci *host,
struct mci_slot_pdata *slot_data, unsigned int id,
u32 sdc_reg, u32 sdio_irq)
{
struct mmc_host *mmc;
struct atmel_mci_slot *slot;
mmc = mmc_alloc_host(sizeof(struct atmel_mci_slot), &host->pdev->dev);
if (!mmc)
return -ENOMEM;
slot = mmc_priv(mmc);
slot->mmc = mmc;
slot->host = host;
slot->detect_pin = slot_data->detect_pin;
slot->wp_pin = slot_data->wp_pin;
slot->detect_is_active_high = slot_data->detect_is_active_high;
slot->sdc_reg = sdc_reg;
slot->sdio_irq = sdio_irq;
mmc->ops = &atmci_ops;
mmc->f_min = DIV_ROUND_UP(host->bus_hz, 512);
mmc->f_max = host->bus_hz / 2;
mmc->ocr_avail = MMC_VDD_32_33 | MMC_VDD_33_34;
if (sdio_irq)
mmc->caps |= MMC_CAP_SDIO_IRQ;
if (host->caps.has_highspeed)
mmc->caps |= MMC_CAP_SD_HIGHSPEED;
if ((slot_data->bus_width >= 4) && host->caps.has_rwproof)
mmc->caps |= MMC_CAP_4_BIT_DATA;
if (atmci_get_version(host) < 0x200) {
mmc->max_segs = 256;
mmc->max_blk_size = 4095;
mmc->max_blk_count = 256;
mmc->max_req_size = mmc->max_blk_size * mmc->max_blk_count;
mmc->max_seg_size = mmc->max_blk_size * mmc->max_segs;
} else {
mmc->max_segs = 64;
mmc->max_req_size = 32768 * 512;
mmc->max_blk_size = 32768;
mmc->max_blk_count = 512;
}
set_bit(ATMCI_CARD_PRESENT, &slot->flags);
if (gpio_is_valid(slot->detect_pin)) {
if (gpio_request(slot->detect_pin, "mmc_detect")) {
dev_dbg(&mmc->class_dev, "no detect pin available\n");
slot->detect_pin = -EBUSY;
} else if (gpio_get_value(slot->detect_pin) ^
slot->detect_is_active_high) {
clear_bit(ATMCI_CARD_PRESENT, &slot->flags);
}
}
if (!gpio_is_valid(slot->detect_pin))
mmc->caps |= MMC_CAP_NEEDS_POLL;
if (gpio_is_valid(slot->wp_pin)) {
if (gpio_request(slot->wp_pin, "mmc_wp")) {
dev_dbg(&mmc->class_dev, "no WP pin available\n");
slot->wp_pin = -EBUSY;
}
}
host->slot[id] = slot;
mmc_add_host(mmc);
if (gpio_is_valid(slot->detect_pin)) {
int ret;
setup_timer(&slot->detect_timer, atmci_detect_change,
(unsigned long)slot);
ret = request_irq(gpio_to_irq(slot->detect_pin),
atmci_detect_interrupt,
IRQF_TRIGGER_FALLING | IRQF_TRIGGER_RISING,
"mmc-detect", slot);
if (ret) {
dev_dbg(&mmc->class_dev,
"could not request IRQ %d for detect pin\n",
gpio_to_irq(slot->detect_pin));
gpio_free(slot->detect_pin);
slot->detect_pin = -EBUSY;
}
}
atmci_init_debugfs(slot);
return 0;
}
static void __exit atmci_cleanup_slot(struct atmel_mci_slot *slot,
unsigned int id)
{
set_bit(ATMCI_SHUTDOWN, &slot->flags);
smp_wmb();
mmc_remove_host(slot->mmc);
if (gpio_is_valid(slot->detect_pin)) {
int pin = slot->detect_pin;
free_irq(gpio_to_irq(pin), slot);
del_timer_sync(&slot->detect_timer);
gpio_free(pin);
}
if (gpio_is_valid(slot->wp_pin))
gpio_free(slot->wp_pin);
slot->host->slot[id] = NULL;
mmc_free_host(slot->mmc);
}
static bool atmci_filter(struct dma_chan *chan, void *slave)
{
struct mci_dma_data *sl = slave;
if (sl && find_slave_dev(sl) == chan->device->dev) {
chan->private = slave_data_ptr(sl);
return true;
} else {
return false;
}
}
static bool atmci_configure_dma(struct atmel_mci *host)
{
struct mci_platform_data *pdata;
if (host == NULL)
return false;
pdata = host->pdev->dev.platform_data;
if (pdata && find_slave_dev(pdata->dma_slave)) {
dma_cap_mask_t mask;
dma_cap_zero(mask);
dma_cap_set(DMA_SLAVE, mask);
host->dma.chan =
dma_request_channel(mask, atmci_filter, pdata->dma_slave);
}
if (!host->dma.chan) {
dev_warn(&host->pdev->dev, "no DMA channel available\n");
return false;
} else {
dev_info(&host->pdev->dev,
"using %s for DMA transfers\n",
dma_chan_name(host->dma.chan));
host->dma_conf.src_addr = host->mapbase + ATMCI_RDR;
host->dma_conf.src_addr_width = DMA_SLAVE_BUSWIDTH_4_BYTES;
host->dma_conf.src_maxburst = 1;
host->dma_conf.dst_addr = host->mapbase + ATMCI_TDR;
host->dma_conf.dst_addr_width = DMA_SLAVE_BUSWIDTH_4_BYTES;
host->dma_conf.dst_maxburst = 1;
host->dma_conf.device_fc = false;
return true;
}
}
static void __init atmci_get_cap(struct atmel_mci *host)
{
unsigned int version;
version = atmci_get_version(host);
dev_info(&host->pdev->dev,
"version: 0x%x\n", version);
host->caps.has_dma = 0;
host->caps.has_pdc = 1;
host->caps.has_cfg_reg = 0;
host->caps.has_cstor_reg = 0;
host->caps.has_highspeed = 0;
host->caps.has_rwproof = 0;
host->caps.has_odd_clk_div = 0;
host->caps.has_bad_data_ordering = 1;
host->caps.need_reset_after_xfer = 1;
host->caps.need_blksz_mul_4 = 1;
host->caps.need_notbusy_for_read_ops = 0;
switch (version & 0xf00) {
case 0x500:
host->caps.has_odd_clk_div = 1;
case 0x400:
case 0x300:
#ifdef CONFIG_AT_HDMAC
host->caps.has_dma = 1;
#else
dev_info(&host->pdev->dev,
"has dma capability but dma engine is not selected, then use pio\n");
#endif
host->caps.has_pdc = 0;
host->caps.has_cfg_reg = 1;
host->caps.has_cstor_reg = 1;
host->caps.has_highspeed = 1;
case 0x200:
host->caps.has_rwproof = 1;
host->caps.need_blksz_mul_4 = 0;
host->caps.need_notbusy_for_read_ops = 1;
case 0x100:
host->caps.has_bad_data_ordering = 0;
host->caps.need_reset_after_xfer = 0;
case 0x0:
break;
default:
host->caps.has_pdc = 0;
dev_warn(&host->pdev->dev,
"Unmanaged mci version, set minimum capabilities\n");
break;
}
}
static int __init atmci_probe(struct platform_device *pdev)
{
struct mci_platform_data *pdata;
struct atmel_mci *host;
struct resource *regs;
unsigned int nr_slots;
int irq;
int ret;
regs = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!regs)
return -ENXIO;
pdata = pdev->dev.platform_data;
if (!pdata)
return -ENXIO;
irq = platform_get_irq(pdev, 0);
if (irq < 0)
return irq;
host = kzalloc(sizeof(struct atmel_mci), GFP_KERNEL);
if (!host)
return -ENOMEM;
host->pdev = pdev;
spin_lock_init(&host->lock);
INIT_LIST_HEAD(&host->queue);
host->mck = clk_get(&pdev->dev, "mci_clk");
if (IS_ERR(host->mck)) {
ret = PTR_ERR(host->mck);
goto err_clk_get;
}
ret = -ENOMEM;
host->regs = ioremap(regs->start, resource_size(regs));
if (!host->regs)
goto err_ioremap;
clk_enable(host->mck);
atmci_writel(host, ATMCI_CR, ATMCI_CR_SWRST);
host->bus_hz = clk_get_rate(host->mck);
clk_disable(host->mck);
host->mapbase = regs->start;
tasklet_init(&host->tasklet, atmci_tasklet_func, (unsigned long)host);
ret = request_irq(irq, atmci_interrupt, 0, dev_name(&pdev->dev), host);
if (ret)
goto err_request_irq;
atmci_get_cap(host);
if (host->caps.has_dma && atmci_configure_dma(host)) {
host->prepare_data = &atmci_prepare_data_dma;
host->submit_data = &atmci_submit_data_dma;
host->stop_transfer = &atmci_stop_transfer_dma;
} else if (host->caps.has_pdc) {
dev_info(&pdev->dev, "using PDC\n");
host->prepare_data = &atmci_prepare_data_pdc;
host->submit_data = &atmci_submit_data_pdc;
host->stop_transfer = &atmci_stop_transfer_pdc;
} else {
dev_info(&pdev->dev, "using PIO\n");
host->prepare_data = &atmci_prepare_data;
host->submit_data = &atmci_submit_data;
host->stop_transfer = &atmci_stop_transfer;
}
platform_set_drvdata(pdev, host);
setup_timer(&host->timer, atmci_timeout_timer, (unsigned long)host);
nr_slots = 0;
ret = -ENODEV;
if (pdata->slot[0].bus_width) {
ret = atmci_init_slot(host, &pdata->slot[0],
0, ATMCI_SDCSEL_SLOT_A, ATMCI_SDIOIRQA);
if (!ret) {
nr_slots++;
host->buf_size = host->slot[0]->mmc->max_req_size;
}
}
if (pdata->slot[1].bus_width) {
ret = atmci_init_slot(host, &pdata->slot[1],
1, ATMCI_SDCSEL_SLOT_B, ATMCI_SDIOIRQB);
if (!ret) {
nr_slots++;
if (host->slot[1]->mmc->max_req_size > host->buf_size)
host->buf_size =
host->slot[1]->mmc->max_req_size;
}
}
if (!nr_slots) {
dev_err(&pdev->dev, "init failed: no slot defined\n");
goto err_init_slot;
}
if (!host->caps.has_rwproof) {
host->buffer = dma_alloc_coherent(&pdev->dev, host->buf_size,
&host->buf_phys_addr,
GFP_KERNEL);
if (!host->buffer) {
ret = -ENOMEM;
dev_err(&pdev->dev, "buffer allocation failed\n");
goto err_init_slot;
}
}
dev_info(&pdev->dev,
"Atmel MCI controller at 0x%08lx irq %d, %u slots\n",
host->mapbase, irq, nr_slots);
return 0;
err_init_slot:
if (host->dma.chan)
dma_release_channel(host->dma.chan);
free_irq(irq, host);
err_request_irq:
iounmap(host->regs);
err_ioremap:
clk_put(host->mck);
err_clk_get:
kfree(host);
return ret;
}
static int __exit atmci_remove(struct platform_device *pdev)
{
struct atmel_mci *host = platform_get_drvdata(pdev);
unsigned int i;
platform_set_drvdata(pdev, NULL);
if (host->buffer)
dma_free_coherent(&pdev->dev, host->buf_size,
host->buffer, host->buf_phys_addr);
for (i = 0; i < ATMCI_MAX_NR_SLOTS; i++) {
if (host->slot[i])
atmci_cleanup_slot(host->slot[i], i);
}
clk_enable(host->mck);
atmci_writel(host, ATMCI_IDR, ~0UL);
atmci_writel(host, ATMCI_CR, ATMCI_CR_MCIDIS);
atmci_readl(host, ATMCI_SR);
clk_disable(host->mck);
#ifdef CONFIG_MMC_ATMELMCI_DMA
if (host->dma.chan)
dma_release_channel(host->dma.chan);
#endif
free_irq(platform_get_irq(pdev, 0), host);
iounmap(host->regs);
clk_put(host->mck);
kfree(host);
return 0;
}
static int atmci_suspend(struct device *dev)
{
struct atmel_mci *host = dev_get_drvdata(dev);
int i;
for (i = 0; i < ATMCI_MAX_NR_SLOTS; i++) {
struct atmel_mci_slot *slot = host->slot[i];
int ret;
if (!slot)
continue;
ret = mmc_suspend_host(slot->mmc);
if (ret < 0) {
while (--i >= 0) {
slot = host->slot[i];
if (slot
&& test_bit(ATMCI_SUSPENDED, &slot->flags)) {
mmc_resume_host(host->slot[i]->mmc);
clear_bit(ATMCI_SUSPENDED, &slot->flags);
}
}
return ret;
} else {
set_bit(ATMCI_SUSPENDED, &slot->flags);
}
}
return 0;
}
static int atmci_resume(struct device *dev)
{
struct atmel_mci *host = dev_get_drvdata(dev);
int i;
int ret = 0;
for (i = 0; i < ATMCI_MAX_NR_SLOTS; i++) {
struct atmel_mci_slot *slot = host->slot[i];
int err;
slot = host->slot[i];
if (!slot)
continue;
if (!test_bit(ATMCI_SUSPENDED, &slot->flags))
continue;
err = mmc_resume_host(slot->mmc);
if (err < 0)
ret = err;
else
clear_bit(ATMCI_SUSPENDED, &slot->flags);
}
return ret;
}
static int __init atmci_init(void)
{
return platform_driver_probe(&atmci_driver, atmci_probe);
}
static void __exit atmci_exit(void)
{
platform_driver_unregister(&atmci_driver);
}
