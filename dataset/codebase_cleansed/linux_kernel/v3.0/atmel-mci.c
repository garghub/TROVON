static bool mci_has_rwproof(void)
{
if (cpu_is_at91sam9261() || cpu_is_at91rm9200())
return false;
else
return true;
}
static inline bool atmci_is_mci2(void)
{
if (cpu_is_at91sam9g45())
return true;
return false;
}
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
buf = kmalloc(MCI_REGS_SIZE, GFP_KERNEL);
if (!buf)
return -ENOMEM;
spin_lock_bh(&host->lock);
clk_enable(host->mck);
memcpy_fromio(buf, host->regs, MCI_REGS_SIZE);
clk_disable(host->mck);
spin_unlock_bh(&host->lock);
seq_printf(s, "MR:\t0x%08x%s%s CLKDIV=%u\n",
buf[MCI_MR / 4],
buf[MCI_MR / 4] & MCI_MR_RDPROOF ? " RDPROOF" : "",
buf[MCI_MR / 4] & MCI_MR_WRPROOF ? " WRPROOF" : "",
buf[MCI_MR / 4] & 0xff);
seq_printf(s, "DTOR:\t0x%08x\n", buf[MCI_DTOR / 4]);
seq_printf(s, "SDCR:\t0x%08x\n", buf[MCI_SDCR / 4]);
seq_printf(s, "ARGR:\t0x%08x\n", buf[MCI_ARGR / 4]);
seq_printf(s, "BLKR:\t0x%08x BCNT=%u BLKLEN=%u\n",
buf[MCI_BLKR / 4],
buf[MCI_BLKR / 4] & 0xffff,
(buf[MCI_BLKR / 4] >> 16) & 0xffff);
if (atmci_is_mci2())
seq_printf(s, "CSTOR:\t0x%08x\n", buf[MCI_CSTOR / 4]);
atmci_show_status_reg(s, "SR", buf[MCI_SR / 4]);
atmci_show_status_reg(s, "IMR", buf[MCI_IMR / 4]);
if (atmci_is_mci2()) {
u32 val;
val = buf[MCI_DMA / 4];
seq_printf(s, "DMA:\t0x%08x OFFSET=%u CHKSIZE=%u%s\n",
val, val & 3,
((val >> 4) & 3) ?
1 << (((val >> 4) & 3) + 1) : 1,
val & MCI_DMAEN ? " DMAEN" : "");
val = buf[MCI_CFG / 4];
seq_printf(s, "CFG:\t0x%08x%s%s%s%s\n",
val,
val & MCI_CFG_FIFOMODE_1DATA ? " FIFOMODE_ONE_DATA" : "",
val & MCI_CFG_FERRCTRL_COR ? " FERRCTRL_CLEAR_ON_READ" : "",
val & MCI_CFG_HSMODE ? " HSMODE" : "",
val & MCI_CFG_LSYNC ? " LSYNC" : "");
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
static inline unsigned int ns_to_clocks(struct atmel_mci *host,
unsigned int ns)
{
return (ns * (host->bus_hz / 1000000) + 999) / 1000;
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
timeout = ns_to_clocks(host, data->timeout_ns) + data->timeout_clks;
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
mci_writel(host, DTOR, (MCI_DTOMUL(dtomul) | MCI_DTOCYC(dtocyc)));
}
static u32 atmci_prepare_command(struct mmc_host *mmc,
struct mmc_command *cmd)
{
struct mmc_data *data;
u32 cmdr;
cmd->error = -EINPROGRESS;
cmdr = MCI_CMDR_CMDNB(cmd->opcode);
if (cmd->flags & MMC_RSP_PRESENT) {
if (cmd->flags & MMC_RSP_136)
cmdr |= MCI_CMDR_RSPTYP_136BIT;
else
cmdr |= MCI_CMDR_RSPTYP_48BIT;
}
cmdr |= MCI_CMDR_MAXLAT_64CYC;
if (mmc->ios.bus_mode == MMC_BUSMODE_OPENDRAIN)
cmdr |= MCI_CMDR_OPDCMD;
data = cmd->data;
if (data) {
cmdr |= MCI_CMDR_START_XFER;
if (cmd->opcode == SD_IO_RW_EXTENDED) {
cmdr |= MCI_CMDR_SDIO_BLOCK;
} else {
if (data->flags & MMC_DATA_STREAM)
cmdr |= MCI_CMDR_STREAM;
else if (data->blocks > 1)
cmdr |= MCI_CMDR_MULTI_BLOCK;
else
cmdr |= MCI_CMDR_BLOCK;
}
if (data->flags & MMC_DATA_READ)
cmdr |= MCI_CMDR_TRDIR_READ;
}
return cmdr;
}
static void atmci_start_command(struct atmel_mci *host,
struct mmc_command *cmd, u32 cmd_flags)
{
WARN_ON(host->cmd);
host->cmd = cmd;
dev_vdbg(&host->pdev->dev,
"start command: ARGR=0x%08x CMDR=0x%08x\n",
cmd->arg, cmd_flags);
mci_writel(host, ARGR, cmd->arg);
mci_writel(host, CMDR, cmd_flags);
}
static void send_stop_cmd(struct atmel_mci *host, struct mmc_data *data)
{
atmci_start_command(host, data->stop, host->stop_cmdr);
mci_writel(host, IER, MCI_CMDRDY);
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
static void atmci_stop_dma(struct atmel_mci *host)
{
struct dma_chan *chan = host->data_chan;
if (chan) {
dmaengine_terminate_all(chan);
atmci_dma_cleanup(host);
} else {
atmci_set_pending(host, EVENT_XFER_COMPLETE);
mci_writel(host, IER, MCI_NOTBUSY);
}
}
static void atmci_dma_complete(void *arg)
{
struct atmel_mci *host = arg;
struct mmc_data *data = host->data;
dev_vdbg(&host->pdev->dev, "DMA complete\n");
if (atmci_is_mci2())
mci_writel(host, DMA, mci_readl(host, DMA) & ~MCI_DMAEN);
atmci_dma_cleanup(host);
if (data) {
atmci_set_pending(host, EVENT_XFER_COMPLETE);
tasklet_schedule(&host->tasklet);
mci_writel(host, IER, MCI_NOTBUSY);
}
}
static int
atmci_prepare_data_dma(struct atmel_mci *host, struct mmc_data *data)
{
struct dma_chan *chan;
struct dma_async_tx_descriptor *desc;
struct scatterlist *sg;
unsigned int i;
enum dma_data_direction direction;
unsigned int sglen;
if (data->blocks * data->blksz < ATMCI_DMA_THRESHOLD)
return -EINVAL;
if (data->blksz & 3)
return -EINVAL;
for_each_sg(data->sg, sg, data->sg_len, i) {
if (sg->offset & 3 || sg->length & 3)
return -EINVAL;
}
chan = host->dma.chan;
if (chan)
host->data_chan = chan;
if (!chan)
return -ENODEV;
if (atmci_is_mci2())
mci_writel(host, DMA, MCI_DMA_CHKSIZE(3) | MCI_DMAEN);
if (data->flags & MMC_DATA_READ)
direction = DMA_FROM_DEVICE;
else
direction = DMA_TO_DEVICE;
sglen = dma_map_sg(chan->device->dev, data->sg,
data->sg_len, direction);
desc = chan->device->device_prep_slave_sg(chan,
data->sg, sglen, direction,
DMA_PREP_INTERRUPT | DMA_CTRL_ACK);
if (!desc)
goto unmap_exit;
host->dma.data_desc = desc;
desc->callback = atmci_dma_complete;
desc->callback_param = host;
return 0;
unmap_exit:
dma_unmap_sg(chan->device->dev, data->sg, data->sg_len, direction);
return -ENOMEM;
}
static void atmci_submit_data(struct atmel_mci *host)
{
struct dma_chan *chan = host->data_chan;
struct dma_async_tx_descriptor *desc = host->dma.data_desc;
if (chan) {
dmaengine_submit(desc);
dma_async_issue_pending(chan);
}
}
static int atmci_prepare_data_dma(struct atmel_mci *host, struct mmc_data *data)
{
return -ENOSYS;
}
static void atmci_submit_data(struct atmel_mci *host) {}
static void atmci_stop_dma(struct atmel_mci *host)
{
atmci_set_pending(host, EVENT_XFER_COMPLETE);
mci_writel(host, IER, MCI_NOTBUSY);
}
static u32 atmci_prepare_data(struct atmel_mci *host, struct mmc_data *data)
{
u32 iflags;
data->error = -EINPROGRESS;
WARN_ON(host->data);
host->sg = NULL;
host->data = data;
iflags = ATMCI_DATA_ERROR_FLAGS;
if (atmci_prepare_data_dma(host, data)) {
host->data_chan = NULL;
if (data->blocks * data->blksz < 12
|| (data->blocks * data->blksz) & 3)
host->need_reset = true;
host->sg = data->sg;
host->pio_offset = 0;
if (data->flags & MMC_DATA_READ)
iflags |= MCI_RXRDY;
else
iflags |= MCI_TXRDY;
}
return iflags;
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
host->data_status = 0;
if (host->need_reset) {
mci_writel(host, CR, MCI_CR_SWRST);
mci_writel(host, CR, MCI_CR_MCIEN);
mci_writel(host, MR, host->mode_reg);
if (atmci_is_mci2())
mci_writel(host, CFG, host->cfg_reg);
host->need_reset = false;
}
mci_writel(host, SDCR, slot->sdc_reg);
iflags = mci_readl(host, IMR);
if (iflags & ~(MCI_SDIOIRQA | MCI_SDIOIRQB))
dev_warn(&slot->mmc->class_dev, "WARNING: IMR=0x%08x\n",
iflags);
if (unlikely(test_and_clear_bit(ATMCI_CARD_NEED_INIT, &slot->flags))) {
mci_writel(host, CMDR, MCI_CMDR_SPCMD_INIT);
while (!(mci_readl(host, SR) & MCI_CMDRDY))
cpu_relax();
}
iflags = 0;
data = mrq->data;
if (data) {
atmci_set_timeout(host, slot, data);
mci_writel(host, BLKR, MCI_BCNT(data->blocks)
| MCI_BLKLEN(data->blksz));
dev_vdbg(&slot->mmc->class_dev, "BLKR=0x%08x\n",
MCI_BCNT(data->blocks) | MCI_BLKLEN(data->blksz));
iflags |= atmci_prepare_data(host, data);
}
iflags |= MCI_CMDRDY;
cmd = mrq->cmd;
cmdflags = atmci_prepare_command(slot->mmc, cmd);
atmci_start_command(host, cmd, cmdflags);
if (data)
atmci_submit_data(host);
if (mrq->stop) {
host->stop_cmdr = atmci_prepare_command(slot->mmc, mrq->stop);
host->stop_cmdr |= MCI_CMDR_STOP_XFER;
if (!(data->flags & MMC_DATA_WRITE))
host->stop_cmdr |= MCI_CMDR_TRDIR_READ;
if (data->flags & MMC_DATA_STREAM)
host->stop_cmdr |= MCI_CMDR_STREAM;
else
host->stop_cmdr |= MCI_CMDR_MULTI_BLOCK;
}
mci_writel(host, IER, iflags);
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
slot->sdc_reg &= ~MCI_SDCBUS_MASK;
switch (ios->bus_width) {
case MMC_BUS_WIDTH_1:
slot->sdc_reg |= MCI_SDCBUS_1BIT;
break;
case MMC_BUS_WIDTH_4:
slot->sdc_reg |= MCI_SDCBUS_4BIT;
break;
}
if (ios->clock) {
unsigned int clock_min = ~0U;
u32 clkdiv;
spin_lock_bh(&host->lock);
if (!host->mode_reg) {
clk_enable(host->mck);
mci_writel(host, CR, MCI_CR_SWRST);
mci_writel(host, CR, MCI_CR_MCIEN);
if (atmci_is_mci2())
mci_writel(host, CFG, host->cfg_reg);
}
slot->clock = ios->clock;
for (i = 0; i < ATMEL_MCI_MAX_NR_SLOTS; i++) {
if (host->slot[i] && host->slot[i]->clock
&& host->slot[i]->clock < clock_min)
clock_min = host->slot[i]->clock;
}
clkdiv = DIV_ROUND_UP(host->bus_hz, 2 * clock_min) - 1;
if (clkdiv > 255) {
dev_warn(&mmc->class_dev,
"clock %u too slow; using %lu\n",
clock_min, host->bus_hz / (2 * 256));
clkdiv = 255;
}
host->mode_reg = MCI_MR_CLKDIV(clkdiv);
if (mci_has_rwproof())
host->mode_reg |= (MCI_MR_WRPROOF | MCI_MR_RDPROOF);
if (atmci_is_mci2()) {
if (ios->timing == MMC_TIMING_SD_HS)
host->cfg_reg |= MCI_CFG_HSMODE;
else
host->cfg_reg &= ~MCI_CFG_HSMODE;
}
if (list_empty(&host->queue)) {
mci_writel(host, MR, host->mode_reg);
if (atmci_is_mci2())
mci_writel(host, CFG, host->cfg_reg);
} else {
host->need_clock_update = true;
}
spin_unlock_bh(&host->lock);
} else {
bool any_slot_active = false;
spin_lock_bh(&host->lock);
slot->clock = 0;
for (i = 0; i < ATMEL_MCI_MAX_NR_SLOTS; i++) {
if (host->slot[i] && host->slot[i]->clock) {
any_slot_active = true;
break;
}
}
if (!any_slot_active) {
mci_writel(host, CR, MCI_CR_MCIDIS);
if (host->mode_reg) {
mci_readl(host, MR);
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
mci_writel(host, IER, slot->sdio_irq);
else
mci_writel(host, IDR, slot->sdio_irq);
}
static void atmci_request_end(struct atmel_mci *host, struct mmc_request *mrq)
__releases(&host->lock
static void atmci_command_complete(struct atmel_mci *host,
struct mmc_command *cmd)
{
u32 status = host->cmd_status;
cmd->resp[0] = mci_readl(host, RSPR);
cmd->resp[1] = mci_readl(host, RSPR);
cmd->resp[2] = mci_readl(host, RSPR);
cmd->resp[3] = mci_readl(host, RSPR);
if (status & MCI_RTOE)
cmd->error = -ETIMEDOUT;
else if ((cmd->flags & MMC_RSP_CRC) && (status & MCI_RCRCE))
cmd->error = -EILSEQ;
else if (status & (MCI_RINDE | MCI_RDIRE | MCI_RENDE))
cmd->error = -EIO;
else
cmd->error = 0;
if (cmd->error) {
dev_dbg(&host->pdev->dev,
"command error: status=0x%08x\n", status);
if (cmd->data) {
atmci_stop_dma(host);
host->data = NULL;
mci_writel(host, IDR, MCI_NOTBUSY
| MCI_TXRDY | MCI_RXRDY
| ATMCI_DATA_ERROR_FLAGS);
}
}
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
mci_writel(host, CR, MCI_CR_SWRST);
mci_writel(host, CR, MCI_CR_MCIEN);
mci_writel(host, MR, host->mode_reg);
if (atmci_is_mci2())
mci_writel(host, CFG, host->cfg_reg);
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
atmci_stop_dma(host);
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
struct mmc_command *cmd = host->cmd;
enum atmel_mci_state state = host->state;
enum atmel_mci_state prev_state;
u32 status;
spin_lock(&host->lock);
state = host->state;
dev_vdbg(&host->pdev->dev,
"tasklet: state %u pending/completed/mask %lx/%lx/%x\n",
state, host->pending_events, host->completed_events,
mci_readl(host, IMR));
do {
prev_state = state;
switch (state) {
case STATE_IDLE:
break;
case STATE_SENDING_CMD:
if (!atmci_test_and_clear_pending(host,
EVENT_CMD_COMPLETE))
break;
host->cmd = NULL;
atmci_set_completed(host, EVENT_CMD_COMPLETE);
atmci_command_complete(host, mrq->cmd);
if (!mrq->data || cmd->error) {
atmci_request_end(host, host->mrq);
goto unlock;
}
prev_state = state = STATE_SENDING_DATA;
case STATE_SENDING_DATA:
if (atmci_test_and_clear_pending(host,
EVENT_DATA_ERROR)) {
atmci_stop_dma(host);
if (data->stop)
send_stop_cmd(host, data);
state = STATE_DATA_ERROR;
break;
}
if (!atmci_test_and_clear_pending(host,
EVENT_XFER_COMPLETE))
break;
atmci_set_completed(host, EVENT_XFER_COMPLETE);
prev_state = state = STATE_DATA_BUSY;
case STATE_DATA_BUSY:
if (!atmci_test_and_clear_pending(host,
EVENT_DATA_COMPLETE))
break;
host->data = NULL;
atmci_set_completed(host, EVENT_DATA_COMPLETE);
status = host->data_status;
if (unlikely(status & ATMCI_DATA_ERROR_FLAGS)) {
if (status & MCI_DTOE) {
dev_dbg(&host->pdev->dev,
"data timeout error\n");
data->error = -ETIMEDOUT;
} else if (status & MCI_DCRCE) {
dev_dbg(&host->pdev->dev,
"data CRC error\n");
data->error = -EILSEQ;
} else {
dev_dbg(&host->pdev->dev,
"data FIFO error (status=%08x)\n",
status);
data->error = -EIO;
}
} else {
data->bytes_xfered = data->blocks * data->blksz;
data->error = 0;
mci_writel(host, IDR, ATMCI_DATA_ERROR_FLAGS);
}
if (!data->stop) {
atmci_request_end(host, host->mrq);
goto unlock;
}
prev_state = state = STATE_SENDING_STOP;
if (!data->error)
send_stop_cmd(host, data);
case STATE_SENDING_STOP:
if (!atmci_test_and_clear_pending(host,
EVENT_CMD_COMPLETE))
break;
host->cmd = NULL;
atmci_command_complete(host, mrq->stop);
atmci_request_end(host, host->mrq);
goto unlock;
case STATE_DATA_ERROR:
if (!atmci_test_and_clear_pending(host,
EVENT_XFER_COMPLETE))
break;
state = STATE_DATA_BUSY;
break;
}
} while (state != prev_state);
host->state = state;
unlock:
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
value = mci_readl(host, RDR);
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
status = mci_readl(host, SR);
if (status & ATMCI_DATA_ERROR_FLAGS) {
mci_writel(host, IDR, (MCI_NOTBUSY | MCI_RXRDY
| ATMCI_DATA_ERROR_FLAGS));
host->data_status = status;
data->bytes_xfered += nbytes;
smp_wmb();
atmci_set_pending(host, EVENT_DATA_ERROR);
tasklet_schedule(&host->tasklet);
return;
}
} while (status & MCI_RXRDY);
host->pio_offset = offset;
data->bytes_xfered += nbytes;
return;
done:
mci_writel(host, IDR, MCI_RXRDY);
mci_writel(host, IER, MCI_NOTBUSY);
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
mci_writel(host, TDR, value);
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
mci_writel(host, TDR, value);
goto done;
}
offset = 4 - remaining;
buf = sg_virt(sg);
memcpy((u8 *)&value + remaining, buf, offset);
mci_writel(host, TDR, value);
nbytes += offset;
}
status = mci_readl(host, SR);
if (status & ATMCI_DATA_ERROR_FLAGS) {
mci_writel(host, IDR, (MCI_NOTBUSY | MCI_TXRDY
| ATMCI_DATA_ERROR_FLAGS));
host->data_status = status;
data->bytes_xfered += nbytes;
smp_wmb();
atmci_set_pending(host, EVENT_DATA_ERROR);
tasklet_schedule(&host->tasklet);
return;
}
} while (status & MCI_TXRDY);
host->pio_offset = offset;
data->bytes_xfered += nbytes;
return;
done:
mci_writel(host, IDR, MCI_TXRDY);
mci_writel(host, IER, MCI_NOTBUSY);
data->bytes_xfered += nbytes;
smp_wmb();
atmci_set_pending(host, EVENT_XFER_COMPLETE);
}
static void atmci_cmd_interrupt(struct atmel_mci *host, u32 status)
{
mci_writel(host, IDR, MCI_CMDRDY);
host->cmd_status = status;
smp_wmb();
atmci_set_pending(host, EVENT_CMD_COMPLETE);
tasklet_schedule(&host->tasklet);
}
static void atmci_sdio_interrupt(struct atmel_mci *host, u32 status)
{
int i;
for (i = 0; i < ATMEL_MCI_MAX_NR_SLOTS; i++) {
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
status = mci_readl(host, SR);
mask = mci_readl(host, IMR);
pending = status & mask;
if (!pending)
break;
if (pending & ATMCI_DATA_ERROR_FLAGS) {
mci_writel(host, IDR, ATMCI_DATA_ERROR_FLAGS
| MCI_RXRDY | MCI_TXRDY);
pending &= mci_readl(host, IMR);
host->data_status = status;
smp_wmb();
atmci_set_pending(host, EVENT_DATA_ERROR);
tasklet_schedule(&host->tasklet);
}
if (pending & MCI_NOTBUSY) {
mci_writel(host, IDR,
ATMCI_DATA_ERROR_FLAGS | MCI_NOTBUSY);
if (!host->data_status)
host->data_status = status;
smp_wmb();
atmci_set_pending(host, EVENT_DATA_COMPLETE);
tasklet_schedule(&host->tasklet);
}
if (pending & MCI_RXRDY)
atmci_read_data_pio(host);
if (pending & MCI_TXRDY)
atmci_write_data_pio(host);
if (pending & MCI_CMDRDY)
atmci_cmd_interrupt(host, status);
if (pending & (MCI_SDIOIRQA | MCI_SDIOIRQB))
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
if (atmci_is_mci2())
mmc->caps |= MMC_CAP_SD_HIGHSPEED;
if (slot_data->bus_width >= 4)
mmc->caps |= MMC_CAP_4_BIT_DATA;
mmc->max_segs = 64;
mmc->max_req_size = 32768 * 512;
mmc->max_blk_size = 32768;
mmc->max_blk_count = 512;
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
static bool filter(struct dma_chan *chan, void *slave)
{
struct mci_dma_data *sl = slave;
if (sl && find_slave_dev(sl) == chan->device->dev) {
chan->private = slave_data_ptr(sl);
return true;
} else {
return false;
}
}
static void atmci_configure_dma(struct atmel_mci *host)
{
struct mci_platform_data *pdata;
if (host == NULL)
return;
pdata = host->pdev->dev.platform_data;
if (pdata && find_slave_dev(pdata->dma_slave)) {
dma_cap_mask_t mask;
setup_dma_addr(pdata->dma_slave,
host->mapbase + MCI_TDR,
host->mapbase + MCI_RDR);
dma_cap_zero(mask);
dma_cap_set(DMA_SLAVE, mask);
host->dma.chan =
dma_request_channel(mask, filter, pdata->dma_slave);
}
if (!host->dma.chan)
dev_notice(&host->pdev->dev, "DMA not available, using PIO\n");
else
dev_info(&host->pdev->dev,
"Using %s for DMA transfers\n",
dma_chan_name(host->dma.chan));
}
static void atmci_configure_dma(struct atmel_mci *host) {}
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
mci_writel(host, CR, MCI_CR_SWRST);
host->bus_hz = clk_get_rate(host->mck);
clk_disable(host->mck);
host->mapbase = regs->start;
tasklet_init(&host->tasklet, atmci_tasklet_func, (unsigned long)host);
ret = request_irq(irq, atmci_interrupt, 0, dev_name(&pdev->dev), host);
if (ret)
goto err_request_irq;
atmci_configure_dma(host);
platform_set_drvdata(pdev, host);
nr_slots = 0;
ret = -ENODEV;
if (pdata->slot[0].bus_width) {
ret = atmci_init_slot(host, &pdata->slot[0],
0, MCI_SDCSEL_SLOT_A, MCI_SDIOIRQA);
if (!ret)
nr_slots++;
}
if (pdata->slot[1].bus_width) {
ret = atmci_init_slot(host, &pdata->slot[1],
1, MCI_SDCSEL_SLOT_B, MCI_SDIOIRQB);
if (!ret)
nr_slots++;
}
if (!nr_slots) {
dev_err(&pdev->dev, "init failed: no slot defined\n");
goto err_init_slot;
}
dev_info(&pdev->dev,
"Atmel MCI controller at 0x%08lx irq %d, %u slots\n",
host->mapbase, irq, nr_slots);
return 0;
err_init_slot:
#ifdef CONFIG_MMC_ATMELMCI_DMA
if (host->dma.chan)
dma_release_channel(host->dma.chan);
#endif
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
for (i = 0; i < ATMEL_MCI_MAX_NR_SLOTS; i++) {
if (host->slot[i])
atmci_cleanup_slot(host->slot[i], i);
}
clk_enable(host->mck);
mci_writel(host, IDR, ~0UL);
mci_writel(host, CR, MCI_CR_MCIDIS);
mci_readl(host, SR);
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
static int __init atmci_init(void)
{
return platform_driver_probe(&atmci_driver, atmci_probe);
}
static void __exit atmci_exit(void)
{
platform_driver_unregister(&atmci_driver);
}
