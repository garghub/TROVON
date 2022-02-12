static u16 sd_ctrl_read16(struct tmio_mmc_host *host, int addr)
{
return readw(host->ctl + (addr << host->bus_shift));
}
static void sd_ctrl_read16_rep(struct tmio_mmc_host *host, int addr,
u16 *buf, int count)
{
readsw(host->ctl + (addr << host->bus_shift), buf, count);
}
static u32 sd_ctrl_read32(struct tmio_mmc_host *host, int addr)
{
return readw(host->ctl + (addr << host->bus_shift)) |
readw(host->ctl + ((addr + 2) << host->bus_shift)) << 16;
}
static void sd_ctrl_write16(struct tmio_mmc_host *host, int addr, u16 val)
{
writew(val, host->ctl + (addr << host->bus_shift));
}
static void sd_ctrl_write16_rep(struct tmio_mmc_host *host, int addr,
u16 *buf, int count)
{
writesw(host->ctl + (addr << host->bus_shift), buf, count);
}
static void sd_ctrl_write32(struct tmio_mmc_host *host, int addr, u32 val)
{
writew(val, host->ctl + (addr << host->bus_shift));
writew(val >> 16, host->ctl + ((addr + 2) << host->bus_shift));
}
void tmio_mmc_enable_mmc_irqs(struct tmio_mmc_host *host, u32 i)
{
u32 mask = sd_ctrl_read32(host, CTL_IRQ_MASK) & ~(i & TMIO_MASK_IRQ);
sd_ctrl_write32(host, CTL_IRQ_MASK, mask);
}
void tmio_mmc_disable_mmc_irqs(struct tmio_mmc_host *host, u32 i)
{
u32 mask = sd_ctrl_read32(host, CTL_IRQ_MASK) | (i & TMIO_MASK_IRQ);
sd_ctrl_write32(host, CTL_IRQ_MASK, mask);
}
static void tmio_mmc_ack_mmc_irqs(struct tmio_mmc_host *host, u32 i)
{
sd_ctrl_write32(host, CTL_STATUS, ~i);
}
static void tmio_mmc_init_sg(struct tmio_mmc_host *host, struct mmc_data *data)
{
host->sg_len = data->sg_len;
host->sg_ptr = data->sg;
host->sg_orig = data->sg;
host->sg_off = 0;
}
static int tmio_mmc_next_sg(struct tmio_mmc_host *host)
{
host->sg_ptr = sg_next(host->sg_ptr);
host->sg_off = 0;
return --host->sg_len;
}
static void pr_debug_status(u32 status)
{
int i = 0;
printk(KERN_DEBUG "status: %08x = ", status);
STATUS_TO_TEXT(CARD_REMOVE, status, i);
STATUS_TO_TEXT(CARD_INSERT, status, i);
STATUS_TO_TEXT(SIGSTATE, status, i);
STATUS_TO_TEXT(WRPROTECT, status, i);
STATUS_TO_TEXT(CARD_REMOVE_A, status, i);
STATUS_TO_TEXT(CARD_INSERT_A, status, i);
STATUS_TO_TEXT(SIGSTATE_A, status, i);
STATUS_TO_TEXT(CMD_IDX_ERR, status, i);
STATUS_TO_TEXT(STOPBIT_ERR, status, i);
STATUS_TO_TEXT(ILL_FUNC, status, i);
STATUS_TO_TEXT(CMD_BUSY, status, i);
STATUS_TO_TEXT(CMDRESPEND, status, i);
STATUS_TO_TEXT(DATAEND, status, i);
STATUS_TO_TEXT(CRCFAIL, status, i);
STATUS_TO_TEXT(DATATIMEOUT, status, i);
STATUS_TO_TEXT(CMDTIMEOUT, status, i);
STATUS_TO_TEXT(RXOVERFLOW, status, i);
STATUS_TO_TEXT(TXUNDERRUN, status, i);
STATUS_TO_TEXT(RXRDY, status, i);
STATUS_TO_TEXT(TXRQ, status, i);
STATUS_TO_TEXT(ILL_ACCESS, status, i);
printk("\n");
}
static void tmio_mmc_enable_sdio_irq(struct mmc_host *mmc, int enable)
{
struct tmio_mmc_host *host = mmc_priv(mmc);
if (enable) {
host->sdio_irq_enabled = 1;
sd_ctrl_write16(host, CTL_TRANSACTION_CTL, 0x0001);
sd_ctrl_write16(host, CTL_SDIO_IRQ_MASK,
(TMIO_SDIO_MASK_ALL & ~TMIO_SDIO_STAT_IOIRQ));
} else {
sd_ctrl_write16(host, CTL_SDIO_IRQ_MASK, TMIO_SDIO_MASK_ALL);
sd_ctrl_write16(host, CTL_TRANSACTION_CTL, 0x0000);
host->sdio_irq_enabled = 0;
}
}
static void tmio_mmc_set_clock(struct tmio_mmc_host *host, int new_clock)
{
u32 clk = 0, clock;
if (new_clock) {
for (clock = host->mmc->f_min, clk = 0x80000080;
new_clock >= (clock<<1); clk >>= 1)
clock <<= 1;
clk |= 0x100;
}
if (host->set_clk_div)
host->set_clk_div(host->pdev, (clk>>22) & 1);
sd_ctrl_write16(host, CTL_SD_CARD_CLK_CTL, clk & 0x1ff);
}
static void tmio_mmc_clk_stop(struct tmio_mmc_host *host)
{
struct resource *res = platform_get_resource(host->pdev, IORESOURCE_MEM, 0);
if (resource_size(res) > 0x100) {
sd_ctrl_write16(host, CTL_CLK_AND_WAIT_CTL, 0x0000);
msleep(10);
}
sd_ctrl_write16(host, CTL_SD_CARD_CLK_CTL, ~0x0100 &
sd_ctrl_read16(host, CTL_SD_CARD_CLK_CTL));
msleep(10);
}
static void tmio_mmc_clk_start(struct tmio_mmc_host *host)
{
struct resource *res = platform_get_resource(host->pdev, IORESOURCE_MEM, 0);
sd_ctrl_write16(host, CTL_SD_CARD_CLK_CTL, 0x0100 |
sd_ctrl_read16(host, CTL_SD_CARD_CLK_CTL));
msleep(10);
if (resource_size(res) > 0x100) {
sd_ctrl_write16(host, CTL_CLK_AND_WAIT_CTL, 0x0100);
msleep(10);
}
}
static void tmio_mmc_reset(struct tmio_mmc_host *host)
{
struct resource *res = platform_get_resource(host->pdev, IORESOURCE_MEM, 0);
sd_ctrl_write16(host, CTL_RESET_SD, 0x0000);
if (resource_size(res) > 0x100)
sd_ctrl_write16(host, CTL_RESET_SDIO, 0x0000);
msleep(10);
sd_ctrl_write16(host, CTL_RESET_SD, 0x0001);
if (resource_size(res) > 0x100)
sd_ctrl_write16(host, CTL_RESET_SDIO, 0x0001);
msleep(10);
}
static void tmio_mmc_reset_work(struct work_struct *work)
{
struct tmio_mmc_host *host = container_of(work, struct tmio_mmc_host,
delayed_reset_work.work);
struct mmc_request *mrq;
unsigned long flags;
spin_lock_irqsave(&host->lock, flags);
mrq = host->mrq;
if (IS_ERR_OR_NULL(mrq)
|| time_is_after_jiffies(host->last_req_ts +
msecs_to_jiffies(2000))) {
spin_unlock_irqrestore(&host->lock, flags);
return;
}
dev_warn(&host->pdev->dev,
"timeout waiting for hardware interrupt (CMD%u)\n",
mrq->cmd->opcode);
if (host->data)
host->data->error = -ETIMEDOUT;
else if (host->cmd)
host->cmd->error = -ETIMEDOUT;
else
mrq->cmd->error = -ETIMEDOUT;
host->cmd = NULL;
host->data = NULL;
host->force_pio = false;
spin_unlock_irqrestore(&host->lock, flags);
tmio_mmc_reset(host);
host->mrq = NULL;
mmc_request_done(host->mmc, mrq);
}
static void tmio_mmc_finish_request(struct tmio_mmc_host *host)
{
struct mmc_request *mrq = host->mrq;
if (!mrq)
return;
host->cmd = NULL;
host->data = NULL;
host->force_pio = false;
cancel_delayed_work(&host->delayed_reset_work);
host->mrq = NULL;
mmc_request_done(host->mmc, mrq);
}
static int tmio_mmc_start_command(struct tmio_mmc_host *host, struct mmc_command *cmd)
{
struct mmc_data *data = host->data;
int c = cmd->opcode;
if (cmd->opcode == 12 && !cmd->arg) {
sd_ctrl_write16(host, CTL_STOP_INTERNAL_ACTION, 0x001);
return 0;
}
switch (mmc_resp_type(cmd)) {
case MMC_RSP_NONE: c |= RESP_NONE; break;
case MMC_RSP_R1: c |= RESP_R1; break;
case MMC_RSP_R1B: c |= RESP_R1B; break;
case MMC_RSP_R2: c |= RESP_R2; break;
case MMC_RSP_R3: c |= RESP_R3; break;
default:
pr_debug("Unknown response type %d\n", mmc_resp_type(cmd));
return -EINVAL;
}
host->cmd = cmd;
if (data) {
c |= DATA_PRESENT;
if (data->blocks > 1) {
sd_ctrl_write16(host, CTL_STOP_INTERNAL_ACTION, 0x100);
c |= TRANSFER_MULTI;
}
if (data->flags & MMC_DATA_READ)
c |= TRANSFER_READ;
}
tmio_mmc_enable_mmc_irqs(host, TMIO_MASK_CMD);
sd_ctrl_write32(host, CTL_ARG_REG, cmd->arg);
sd_ctrl_write16(host, CTL_SD_CMD, c);
return 0;
}
static void tmio_mmc_pio_irq(struct tmio_mmc_host *host)
{
struct mmc_data *data = host->data;
void *sg_virt;
unsigned short *buf;
unsigned int count;
unsigned long flags;
if ((host->chan_tx || host->chan_rx) && !host->force_pio) {
pr_err("PIO IRQ in DMA mode!\n");
return;
} else if (!data) {
pr_debug("Spurious PIO IRQ\n");
return;
}
sg_virt = tmio_mmc_kmap_atomic(host->sg_ptr, &flags);
buf = (unsigned short *)(sg_virt + host->sg_off);
count = host->sg_ptr->length - host->sg_off;
if (count > data->blksz)
count = data->blksz;
pr_debug("count: %08x offset: %08x flags %08x\n",
count, host->sg_off, data->flags);
if (data->flags & MMC_DATA_READ)
sd_ctrl_read16_rep(host, CTL_SD_DATA_PORT, buf, count >> 1);
else
sd_ctrl_write16_rep(host, CTL_SD_DATA_PORT, buf, count >> 1);
host->sg_off += count;
tmio_mmc_kunmap_atomic(host->sg_ptr, &flags, sg_virt);
if (host->sg_off == host->sg_ptr->length)
tmio_mmc_next_sg(host);
return;
}
static void tmio_mmc_check_bounce_buffer(struct tmio_mmc_host *host)
{
if (host->sg_ptr == &host->bounce_sg) {
unsigned long flags;
void *sg_vaddr = tmio_mmc_kmap_atomic(host->sg_orig, &flags);
memcpy(sg_vaddr, host->bounce_buf, host->bounce_sg.length);
tmio_mmc_kunmap_atomic(host->sg_orig, &flags, sg_vaddr);
}
}
void tmio_mmc_do_data_irq(struct tmio_mmc_host *host)
{
struct mmc_data *data = host->data;
struct mmc_command *stop;
host->data = NULL;
if (!data) {
dev_warn(&host->pdev->dev, "Spurious data end IRQ\n");
return;
}
stop = data->stop;
if (!data->error)
data->bytes_xfered = data->blocks * data->blksz;
else
data->bytes_xfered = 0;
pr_debug("Completed data request\n");
if (data->flags & MMC_DATA_READ) {
if (host->chan_rx && !host->force_pio)
tmio_mmc_check_bounce_buffer(host);
dev_dbg(&host->pdev->dev, "Complete Rx request %p\n",
host->mrq);
} else {
dev_dbg(&host->pdev->dev, "Complete Tx request %p\n",
host->mrq);
}
if (stop) {
if (stop->opcode == 12 && !stop->arg)
sd_ctrl_write16(host, CTL_STOP_INTERNAL_ACTION, 0x000);
else
BUG();
}
tmio_mmc_finish_request(host);
}
static void tmio_mmc_data_irq(struct tmio_mmc_host *host)
{
struct mmc_data *data;
spin_lock(&host->lock);
data = host->data;
if (!data)
goto out;
if (host->chan_tx && (data->flags & MMC_DATA_WRITE) && !host->force_pio) {
if (!(sd_ctrl_read32(host, CTL_STATUS) & TMIO_STAT_CMD_BUSY)) {
tmio_mmc_disable_mmc_irqs(host, TMIO_STAT_DATAEND);
tasklet_schedule(&host->dma_complete);
}
} else if (host->chan_rx && (data->flags & MMC_DATA_READ) && !host->force_pio) {
tmio_mmc_disable_mmc_irqs(host, TMIO_STAT_DATAEND);
tasklet_schedule(&host->dma_complete);
} else {
tmio_mmc_do_data_irq(host);
tmio_mmc_disable_mmc_irqs(host, TMIO_MASK_READOP | TMIO_MASK_WRITEOP);
}
out:
spin_unlock(&host->lock);
}
static void tmio_mmc_cmd_irq(struct tmio_mmc_host *host,
unsigned int stat)
{
struct mmc_command *cmd = host->cmd;
int i, addr;
spin_lock(&host->lock);
if (!host->cmd) {
pr_debug("Spurious CMD irq\n");
goto out;
}
host->cmd = NULL;
for (i = 3, addr = CTL_RESPONSE ; i >= 0 ; i--, addr += 4)
cmd->resp[i] = sd_ctrl_read32(host, addr);
if (cmd->flags & MMC_RSP_136) {
cmd->resp[0] = (cmd->resp[0] << 8) | (cmd->resp[1] >> 24);
cmd->resp[1] = (cmd->resp[1] << 8) | (cmd->resp[2] >> 24);
cmd->resp[2] = (cmd->resp[2] << 8) | (cmd->resp[3] >> 24);
cmd->resp[3] <<= 8;
} else if (cmd->flags & MMC_RSP_R3) {
cmd->resp[0] = cmd->resp[3];
}
if (stat & TMIO_STAT_CMDTIMEOUT)
cmd->error = -ETIMEDOUT;
else if (stat & TMIO_STAT_CRCFAIL && cmd->flags & MMC_RSP_CRC)
cmd->error = -EILSEQ;
if (host->data && !cmd->error) {
if (host->data->flags & MMC_DATA_READ) {
if (host->force_pio || !host->chan_rx)
tmio_mmc_enable_mmc_irqs(host, TMIO_MASK_READOP);
else
tasklet_schedule(&host->dma_issue);
} else {
if (host->force_pio || !host->chan_tx)
tmio_mmc_enable_mmc_irqs(host, TMIO_MASK_WRITEOP);
else
tasklet_schedule(&host->dma_issue);
}
} else {
tmio_mmc_finish_request(host);
}
out:
spin_unlock(&host->lock);
}
irqreturn_t tmio_mmc_irq(int irq, void *devid)
{
struct tmio_mmc_host *host = devid;
struct tmio_mmc_data *pdata = host->pdata;
unsigned int ireg, irq_mask, status;
unsigned int sdio_ireg, sdio_irq_mask, sdio_status;
pr_debug("MMC IRQ begin\n");
status = sd_ctrl_read32(host, CTL_STATUS);
irq_mask = sd_ctrl_read32(host, CTL_IRQ_MASK);
ireg = status & TMIO_MASK_IRQ & ~irq_mask;
sdio_ireg = 0;
if (!ireg && pdata->flags & TMIO_MMC_SDIO_IRQ) {
sdio_status = sd_ctrl_read16(host, CTL_SDIO_STATUS);
sdio_irq_mask = sd_ctrl_read16(host, CTL_SDIO_IRQ_MASK);
sdio_ireg = sdio_status & TMIO_SDIO_MASK_ALL & ~sdio_irq_mask;
sd_ctrl_write16(host, CTL_SDIO_STATUS, sdio_status & ~TMIO_SDIO_MASK_ALL);
if (sdio_ireg && !host->sdio_irq_enabled) {
pr_warning("tmio_mmc: Spurious SDIO IRQ, disabling! 0x%04x 0x%04x 0x%04x\n",
sdio_status, sdio_irq_mask, sdio_ireg);
tmio_mmc_enable_sdio_irq(host->mmc, 0);
goto out;
}
if (host->mmc->caps & MMC_CAP_SDIO_IRQ &&
sdio_ireg & TMIO_SDIO_STAT_IOIRQ)
mmc_signal_sdio_irq(host->mmc);
if (sdio_ireg)
goto out;
}
pr_debug_status(status);
pr_debug_status(ireg);
if (!ireg) {
tmio_mmc_disable_mmc_irqs(host, status & ~irq_mask);
pr_warning("tmio_mmc: Spurious irq, disabling! "
"0x%08x 0x%08x 0x%08x\n", status, irq_mask, ireg);
pr_debug_status(status);
goto out;
}
while (ireg) {
if (ireg & (TMIO_STAT_CARD_INSERT | TMIO_STAT_CARD_REMOVE)) {
tmio_mmc_ack_mmc_irqs(host, TMIO_STAT_CARD_INSERT |
TMIO_STAT_CARD_REMOVE);
mmc_detect_change(host->mmc, msecs_to_jiffies(100));
}
if (ireg & (TMIO_STAT_CMDRESPEND | TMIO_STAT_CMDTIMEOUT)) {
tmio_mmc_ack_mmc_irqs(host,
TMIO_STAT_CMDRESPEND |
TMIO_STAT_CMDTIMEOUT);
tmio_mmc_cmd_irq(host, status);
}
if (ireg & (TMIO_STAT_RXRDY | TMIO_STAT_TXRQ)) {
tmio_mmc_ack_mmc_irqs(host, TMIO_STAT_RXRDY | TMIO_STAT_TXRQ);
tmio_mmc_pio_irq(host);
}
if (ireg & TMIO_STAT_DATAEND) {
tmio_mmc_ack_mmc_irqs(host, TMIO_STAT_DATAEND);
tmio_mmc_data_irq(host);
}
status = sd_ctrl_read32(host, CTL_STATUS);
irq_mask = sd_ctrl_read32(host, CTL_IRQ_MASK);
ireg = status & TMIO_MASK_IRQ & ~irq_mask;
pr_debug("Status at end of loop: %08x\n", status);
pr_debug_status(status);
}
pr_debug("MMC IRQ end\n");
out:
return IRQ_HANDLED;
}
static int tmio_mmc_start_data(struct tmio_mmc_host *host,
struct mmc_data *data)
{
struct tmio_mmc_data *pdata = host->pdata;
pr_debug("setup data transfer: blocksize %08x nr_blocks %d\n",
data->blksz, data->blocks);
if (host->mmc->ios.bus_width == MMC_BUS_WIDTH_4) {
int blksz_2bytes = pdata->flags & TMIO_MMC_BLKSZ_2BYTES;
if (data->blksz < 2 || (data->blksz < 4 && !blksz_2bytes)) {
pr_err("%s: %d byte block unsupported in 4 bit mode\n",
mmc_hostname(host->mmc), data->blksz);
return -EINVAL;
}
}
tmio_mmc_init_sg(host, data);
host->data = data;
sd_ctrl_write16(host, CTL_SD_XFER_LEN, data->blksz);
sd_ctrl_write16(host, CTL_XFER_BLK_COUNT, data->blocks);
tmio_mmc_start_dma(host, data);
return 0;
}
static void tmio_mmc_request(struct mmc_host *mmc, struct mmc_request *mrq)
{
struct tmio_mmc_host *host = mmc_priv(mmc);
unsigned long flags;
int ret;
spin_lock_irqsave(&host->lock, flags);
if (host->mrq) {
pr_debug("request not null\n");
if (IS_ERR(host->mrq)) {
spin_unlock_irqrestore(&host->lock, flags);
mrq->cmd->error = -EAGAIN;
mmc_request_done(mmc, mrq);
return;
}
}
host->last_req_ts = jiffies;
wmb();
host->mrq = mrq;
spin_unlock_irqrestore(&host->lock, flags);
if (mrq->data) {
ret = tmio_mmc_start_data(host, mrq->data);
if (ret)
goto fail;
}
ret = tmio_mmc_start_command(host, mrq->cmd);
if (!ret) {
schedule_delayed_work(&host->delayed_reset_work,
msecs_to_jiffies(2000));
return;
}
fail:
host->force_pio = false;
host->mrq = NULL;
mrq->cmd->error = ret;
mmc_request_done(mmc, mrq);
}
static void tmio_mmc_set_ios(struct mmc_host *mmc, struct mmc_ios *ios)
{
struct tmio_mmc_host *host = mmc_priv(mmc);
struct tmio_mmc_data *pdata = host->pdata;
unsigned long flags;
spin_lock_irqsave(&host->lock, flags);
if (host->mrq) {
if (IS_ERR(host->mrq)) {
dev_dbg(&host->pdev->dev,
"%s.%d: concurrent .set_ios(), clk %u, mode %u\n",
current->comm, task_pid_nr(current),
ios->clock, ios->power_mode);
host->mrq = ERR_PTR(-EINTR);
} else {
dev_dbg(&host->pdev->dev,
"%s.%d: CMD%u active since %lu, now %lu!\n",
current->comm, task_pid_nr(current),
host->mrq->cmd->opcode, host->last_req_ts, jiffies);
}
spin_unlock_irqrestore(&host->lock, flags);
return;
}
host->mrq = ERR_PTR(-EBUSY);
spin_unlock_irqrestore(&host->lock, flags);
if (ios->clock)
tmio_mmc_set_clock(host, ios->clock);
if (ios->power_mode == MMC_POWER_UP) {
if ((pdata->flags & TMIO_MMC_HAS_COLD_CD) && !pdata->power) {
pm_runtime_get_sync(&host->pdev->dev);
pdata->power = true;
}
if (host->set_pwr)
host->set_pwr(host->pdev, 1);
} else if (ios->power_mode == MMC_POWER_OFF || !ios->clock) {
if (ios->power_mode == MMC_POWER_OFF) {
if (host->set_pwr)
host->set_pwr(host->pdev, 0);
if ((pdata->flags & TMIO_MMC_HAS_COLD_CD) &&
pdata->power) {
pdata->power = false;
pm_runtime_put(&host->pdev->dev);
}
}
tmio_mmc_clk_stop(host);
} else {
tmio_mmc_clk_start(host);
}
switch (ios->bus_width) {
case MMC_BUS_WIDTH_1:
sd_ctrl_write16(host, CTL_SD_MEM_CARD_OPT, 0x80e0);
break;
case MMC_BUS_WIDTH_4:
sd_ctrl_write16(host, CTL_SD_MEM_CARD_OPT, 0x00e0);
break;
}
udelay(140);
if (PTR_ERR(host->mrq) == -EINTR)
dev_dbg(&host->pdev->dev,
"%s.%d: IOS interrupted: clk %u, mode %u",
current->comm, task_pid_nr(current),
ios->clock, ios->power_mode);
host->mrq = NULL;
}
static int tmio_mmc_get_ro(struct mmc_host *mmc)
{
struct tmio_mmc_host *host = mmc_priv(mmc);
struct tmio_mmc_data *pdata = host->pdata;
return !((pdata->flags & TMIO_MMC_WRPROTECT_DISABLE) ||
(sd_ctrl_read32(host, CTL_STATUS) & TMIO_STAT_WRPROTECT));
}
static int tmio_mmc_get_cd(struct mmc_host *mmc)
{
struct tmio_mmc_host *host = mmc_priv(mmc);
struct tmio_mmc_data *pdata = host->pdata;
if (!pdata->get_cd)
return -ENOSYS;
else
return pdata->get_cd(host->pdev);
}
int __devinit tmio_mmc_host_probe(struct tmio_mmc_host **host,
struct platform_device *pdev,
struct tmio_mmc_data *pdata)
{
struct tmio_mmc_host *_host;
struct mmc_host *mmc;
struct resource *res_ctl;
int ret;
u32 irq_mask = TMIO_MASK_CMD;
res_ctl = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res_ctl)
return -EINVAL;
mmc = mmc_alloc_host(sizeof(struct tmio_mmc_host), &pdev->dev);
if (!mmc)
return -ENOMEM;
pdata->dev = &pdev->dev;
_host = mmc_priv(mmc);
_host->pdata = pdata;
_host->mmc = mmc;
_host->pdev = pdev;
platform_set_drvdata(pdev, mmc);
_host->set_pwr = pdata->set_pwr;
_host->set_clk_div = pdata->set_clk_div;
_host->bus_shift = resource_size(res_ctl) >> 10;
_host->ctl = ioremap(res_ctl->start, resource_size(res_ctl));
if (!_host->ctl) {
ret = -ENOMEM;
goto host_free;
}
mmc->ops = &tmio_mmc_ops;
mmc->caps = MMC_CAP_4_BIT_DATA | pdata->capabilities;
mmc->f_max = pdata->hclk;
mmc->f_min = mmc->f_max / 512;
mmc->max_segs = 32;
mmc->max_blk_size = 512;
mmc->max_blk_count = (PAGE_CACHE_SIZE / mmc->max_blk_size) *
mmc->max_segs;
mmc->max_req_size = mmc->max_blk_size * mmc->max_blk_count;
mmc->max_seg_size = mmc->max_req_size;
if (pdata->ocr_mask)
mmc->ocr_avail = pdata->ocr_mask;
else
mmc->ocr_avail = MMC_VDD_32_33 | MMC_VDD_33_34;
pdata->power = false;
pm_runtime_enable(&pdev->dev);
ret = pm_runtime_resume(&pdev->dev);
if (ret < 0)
goto pm_disable;
tmio_mmc_clk_stop(_host);
tmio_mmc_reset(_host);
tmio_mmc_disable_mmc_irqs(_host, TMIO_MASK_ALL);
if (pdata->flags & TMIO_MMC_SDIO_IRQ)
tmio_mmc_enable_sdio_irq(mmc, 0);
spin_lock_init(&_host->lock);
INIT_DELAYED_WORK(&_host->delayed_reset_work, tmio_mmc_reset_work);
tmio_mmc_request_dma(_host, pdata);
if (!(pdata->flags & TMIO_MMC_HAS_COLD_CD))
pm_runtime_get_noresume(&pdev->dev);
mmc_add_host(mmc);
if (!_host->chan_rx)
irq_mask |= TMIO_MASK_READOP;
if (!_host->chan_tx)
irq_mask |= TMIO_MASK_WRITEOP;
tmio_mmc_enable_mmc_irqs(_host, irq_mask);
*host = _host;
return 0;
pm_disable:
pm_runtime_disable(&pdev->dev);
iounmap(_host->ctl);
host_free:
mmc_free_host(mmc);
return ret;
}
void tmio_mmc_host_remove(struct tmio_mmc_host *host)
{
struct platform_device *pdev = host->pdev;
if (host->pdata->flags & TMIO_MMC_HAS_COLD_CD)
pm_runtime_get_sync(&pdev->dev);
mmc_remove_host(host->mmc);
cancel_delayed_work_sync(&host->delayed_reset_work);
tmio_mmc_release_dma(host);
pm_runtime_put_sync(&pdev->dev);
pm_runtime_disable(&pdev->dev);
iounmap(host->ctl);
mmc_free_host(host->mmc);
}
int tmio_mmc_host_suspend(struct device *dev)
{
struct mmc_host *mmc = dev_get_drvdata(dev);
struct tmio_mmc_host *host = mmc_priv(mmc);
int ret = mmc_suspend_host(mmc);
if (!ret)
tmio_mmc_disable_mmc_irqs(host, TMIO_MASK_ALL);
host->pm_error = pm_runtime_put_sync(dev);
return ret;
}
int tmio_mmc_host_resume(struct device *dev)
{
struct mmc_host *mmc = dev_get_drvdata(dev);
struct tmio_mmc_host *host = mmc_priv(mmc);
host->pdata->power = false;
if (!host->pm_error)
pm_runtime_get_sync(dev);
tmio_mmc_reset(mmc_priv(mmc));
tmio_mmc_request_dma(host, host->pdata);
return mmc_resume_host(mmc);
}
int tmio_mmc_host_runtime_suspend(struct device *dev)
{
return 0;
}
int tmio_mmc_host_runtime_resume(struct device *dev)
{
struct mmc_host *mmc = dev_get_drvdata(dev);
struct tmio_mmc_host *host = mmc_priv(mmc);
struct tmio_mmc_data *pdata = host->pdata;
tmio_mmc_reset(host);
if (pdata->power) {
tmio_mmc_set_ios(mmc, &mmc->ios);
mmc_detect_change(mmc, msecs_to_jiffies(100));
}
return 0;
}
