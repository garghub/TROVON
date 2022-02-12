static void mmc_davinci_sg_to_buf(struct mmc_davinci_host *host)
{
host->buffer_bytes_left = sg_dma_len(host->sg);
host->buffer = sg_virt(host->sg);
if (host->buffer_bytes_left > host->bytes_left)
host->buffer_bytes_left = host->bytes_left;
}
static void davinci_fifo_data_trans(struct mmc_davinci_host *host,
unsigned int n)
{
u8 *p;
unsigned int i;
if (host->buffer_bytes_left == 0) {
host->sg = sg_next(host->data->sg);
mmc_davinci_sg_to_buf(host);
}
p = host->buffer;
if (n > host->buffer_bytes_left)
n = host->buffer_bytes_left;
host->buffer_bytes_left -= n;
host->bytes_left -= n;
if (host->data_dir == DAVINCI_MMC_DATADIR_WRITE) {
for (i = 0; i < (n >> 2); i++) {
writel(*((u32 *)p), host->base + DAVINCI_MMCDXR);
p = p + 4;
}
if (n & 3) {
iowrite8_rep(host->base + DAVINCI_MMCDXR, p, (n & 3));
p = p + (n & 3);
}
} else {
for (i = 0; i < (n >> 2); i++) {
*((u32 *)p) = readl(host->base + DAVINCI_MMCDRR);
p = p + 4;
}
if (n & 3) {
ioread8_rep(host->base + DAVINCI_MMCDRR, p, (n & 3));
p = p + (n & 3);
}
}
host->buffer = p;
}
static void mmc_davinci_start_command(struct mmc_davinci_host *host,
struct mmc_command *cmd)
{
u32 cmd_reg = 0;
u32 im_val;
dev_dbg(mmc_dev(host->mmc), "CMD%d, arg 0x%08x%s\n",
cmd->opcode, cmd->arg,
({ char *s;
switch (mmc_resp_type(cmd)) {
case MMC_RSP_R1:
s = ", R1/R5/R6/R7 response";
break;
case MMC_RSP_R1B:
s = ", R1b response";
break;
case MMC_RSP_R2:
s = ", R2 response";
break;
case MMC_RSP_R3:
s = ", R3/R4 response";
break;
default:
s = ", (R? response)";
break;
}; s; }));
host->cmd = cmd;
switch (mmc_resp_type(cmd)) {
case MMC_RSP_R1B:
cmd_reg |= MMCCMD_BSYEXP;
case MMC_RSP_R1:
cmd_reg |= MMCCMD_RSPFMT_R1456;
break;
case MMC_RSP_R2:
cmd_reg |= MMCCMD_RSPFMT_R2;
break;
case MMC_RSP_R3:
cmd_reg |= MMCCMD_RSPFMT_R3;
break;
default:
cmd_reg |= MMCCMD_RSPFMT_NONE;
dev_dbg(mmc_dev(host->mmc), "unknown resp_type %04x\n",
mmc_resp_type(cmd));
break;
}
cmd_reg |= cmd->opcode;
if (host->do_dma)
cmd_reg |= MMCCMD_DMATRIG;
if (host->version == MMC_CTLR_VERSION_2 && host->data != NULL &&
host->data_dir == DAVINCI_MMC_DATADIR_READ)
cmd_reg |= MMCCMD_DMATRIG;
if (cmd->data)
cmd_reg |= MMCCMD_WDATX;
if (host->data_dir == DAVINCI_MMC_DATADIR_WRITE)
cmd_reg |= MMCCMD_DTRW;
if (host->bus_mode == MMC_BUSMODE_PUSHPULL)
cmd_reg |= MMCCMD_PPLEN;
writel(0x1FFF, host->base + DAVINCI_MMCTOR);
im_val = MMCST0_RSPDNE | MMCST0_CRCRS | MMCST0_TOUTRS;
if (host->data_dir == DAVINCI_MMC_DATADIR_WRITE) {
im_val |= MMCST0_DATDNE | MMCST0_CRCWR;
if (!host->do_dma)
im_val |= MMCST0_DXRDY;
} else if (host->data_dir == DAVINCI_MMC_DATADIR_READ) {
im_val |= MMCST0_DATDNE | MMCST0_CRCRD | MMCST0_TOUTRD;
if (!host->do_dma)
im_val |= MMCST0_DRRDY;
}
if (!host->do_dma && (host->data_dir == DAVINCI_MMC_DATADIR_WRITE))
davinci_fifo_data_trans(host, rw_threshold);
writel(cmd->arg, host->base + DAVINCI_MMCARGHL);
writel(cmd_reg, host->base + DAVINCI_MMCCMD);
host->active_request = true;
if (!host->do_dma && host->bytes_left <= poll_threshold) {
u32 count = poll_loopcount;
while (host->active_request && count--) {
mmc_davinci_irq(0, host);
cpu_relax();
}
}
if (host->active_request)
writel(im_val, host->base + DAVINCI_MMCIM);
}
static void davinci_abort_dma(struct mmc_davinci_host *host)
{
struct dma_chan *sync_dev;
if (host->data_dir == DAVINCI_MMC_DATADIR_READ)
sync_dev = host->dma_rx;
else
sync_dev = host->dma_tx;
dmaengine_terminate_all(sync_dev);
}
static int mmc_davinci_send_dma_request(struct mmc_davinci_host *host,
struct mmc_data *data)
{
struct dma_chan *chan;
struct dma_async_tx_descriptor *desc;
int ret = 0;
if (host->data_dir == DAVINCI_MMC_DATADIR_WRITE) {
struct dma_slave_config dma_tx_conf = {
.direction = DMA_MEM_TO_DEV,
.dst_addr = host->mem_res->start + DAVINCI_MMCDXR,
.dst_addr_width = DMA_SLAVE_BUSWIDTH_4_BYTES,
.dst_maxburst =
rw_threshold / DMA_SLAVE_BUSWIDTH_4_BYTES,
};
chan = host->dma_tx;
dmaengine_slave_config(host->dma_tx, &dma_tx_conf);
desc = dmaengine_prep_slave_sg(host->dma_tx,
data->sg,
host->sg_len,
DMA_MEM_TO_DEV,
DMA_PREP_INTERRUPT | DMA_CTRL_ACK);
if (!desc) {
dev_dbg(mmc_dev(host->mmc),
"failed to allocate DMA TX descriptor");
ret = -1;
goto out;
}
} else {
struct dma_slave_config dma_rx_conf = {
.direction = DMA_DEV_TO_MEM,
.src_addr = host->mem_res->start + DAVINCI_MMCDRR,
.src_addr_width = DMA_SLAVE_BUSWIDTH_4_BYTES,
.src_maxburst =
rw_threshold / DMA_SLAVE_BUSWIDTH_4_BYTES,
};
chan = host->dma_rx;
dmaengine_slave_config(host->dma_rx, &dma_rx_conf);
desc = dmaengine_prep_slave_sg(host->dma_rx,
data->sg,
host->sg_len,
DMA_DEV_TO_MEM,
DMA_PREP_INTERRUPT | DMA_CTRL_ACK);
if (!desc) {
dev_dbg(mmc_dev(host->mmc),
"failed to allocate DMA RX descriptor");
ret = -1;
goto out;
}
}
dmaengine_submit(desc);
dma_async_issue_pending(chan);
out:
return ret;
}
static int mmc_davinci_start_dma_transfer(struct mmc_davinci_host *host,
struct mmc_data *data)
{
int i;
int mask = rw_threshold - 1;
int ret = 0;
host->sg_len = dma_map_sg(mmc_dev(host->mmc), data->sg, data->sg_len,
((data->flags & MMC_DATA_WRITE)
? DMA_TO_DEVICE
: DMA_FROM_DEVICE));
for (i = 0; i < host->sg_len; i++) {
if (sg_dma_len(data->sg + i) & mask) {
dma_unmap_sg(mmc_dev(host->mmc),
data->sg, data->sg_len,
(data->flags & MMC_DATA_WRITE)
? DMA_TO_DEVICE
: DMA_FROM_DEVICE);
return -1;
}
}
host->do_dma = 1;
ret = mmc_davinci_send_dma_request(host, data);
return ret;
}
static void __init_or_module
davinci_release_dma_channels(struct mmc_davinci_host *host)
{
if (!host->use_dma)
return;
dma_release_channel(host->dma_tx);
dma_release_channel(host->dma_rx);
}
static int __init davinci_acquire_dma_channels(struct mmc_davinci_host *host)
{
host->dma_tx = dma_request_chan(mmc_dev(host->mmc), "tx");
if (IS_ERR(host->dma_tx)) {
dev_err(mmc_dev(host->mmc), "Can't get dma_tx channel\n");
return PTR_ERR(host->dma_tx);
}
host->dma_rx = dma_request_chan(mmc_dev(host->mmc), "rx");
if (IS_ERR(host->dma_rx)) {
dev_err(mmc_dev(host->mmc), "Can't get dma_rx channel\n");
dma_release_channel(host->dma_tx);
return PTR_ERR(host->dma_rx);
}
return 0;
}
static void
mmc_davinci_prepare_data(struct mmc_davinci_host *host, struct mmc_request *req)
{
int fifo_lev = (rw_threshold == 32) ? MMCFIFOCTL_FIFOLEV : 0;
int timeout;
struct mmc_data *data = req->data;
if (host->version == MMC_CTLR_VERSION_2)
fifo_lev = (rw_threshold == 64) ? MMCFIFOCTL_FIFOLEV : 0;
host->data = data;
if (data == NULL) {
host->data_dir = DAVINCI_MMC_DATADIR_NONE;
writel(0, host->base + DAVINCI_MMCBLEN);
writel(0, host->base + DAVINCI_MMCNBLK);
return;
}
dev_dbg(mmc_dev(host->mmc), "%s, %d blocks of %d bytes\n",
(data->flags & MMC_DATA_WRITE) ? "write" : "read",
data->blocks, data->blksz);
dev_dbg(mmc_dev(host->mmc), " DTO %d cycles + %d ns\n",
data->timeout_clks, data->timeout_ns);
timeout = data->timeout_clks +
(data->timeout_ns / host->ns_in_one_cycle);
if (timeout > 0xffff)
timeout = 0xffff;
writel(timeout, host->base + DAVINCI_MMCTOD);
writel(data->blocks, host->base + DAVINCI_MMCNBLK);
writel(data->blksz, host->base + DAVINCI_MMCBLEN);
if (data->flags & MMC_DATA_WRITE) {
host->data_dir = DAVINCI_MMC_DATADIR_WRITE;
writel(fifo_lev | MMCFIFOCTL_FIFODIR_WR | MMCFIFOCTL_FIFORST,
host->base + DAVINCI_MMCFIFOCTL);
writel(fifo_lev | MMCFIFOCTL_FIFODIR_WR,
host->base + DAVINCI_MMCFIFOCTL);
} else {
host->data_dir = DAVINCI_MMC_DATADIR_READ;
writel(fifo_lev | MMCFIFOCTL_FIFODIR_RD | MMCFIFOCTL_FIFORST,
host->base + DAVINCI_MMCFIFOCTL);
writel(fifo_lev | MMCFIFOCTL_FIFODIR_RD,
host->base + DAVINCI_MMCFIFOCTL);
}
host->buffer = NULL;
host->bytes_left = data->blocks * data->blksz;
if (host->use_dma && (host->bytes_left & (rw_threshold - 1)) == 0
&& mmc_davinci_start_dma_transfer(host, data) == 0) {
host->bytes_left = 0;
} else {
host->sg_len = data->sg_len;
host->sg = host->data->sg;
mmc_davinci_sg_to_buf(host);
}
}
static void mmc_davinci_request(struct mmc_host *mmc, struct mmc_request *req)
{
struct mmc_davinci_host *host = mmc_priv(mmc);
unsigned long timeout = jiffies + msecs_to_jiffies(900);
u32 mmcst1 = 0;
while (time_before(jiffies, timeout)) {
mmcst1 = readl(host->base + DAVINCI_MMCST1);
if (!(mmcst1 & MMCST1_BUSY))
break;
cpu_relax();
}
if (mmcst1 & MMCST1_BUSY) {
dev_err(mmc_dev(host->mmc), "still BUSY? bad ... \n");
req->cmd->error = -ETIMEDOUT;
mmc_request_done(mmc, req);
return;
}
host->do_dma = 0;
mmc_davinci_prepare_data(host, req);
mmc_davinci_start_command(host, req->cmd);
}
static unsigned int calculate_freq_for_card(struct mmc_davinci_host *host,
unsigned int mmc_req_freq)
{
unsigned int mmc_freq = 0, mmc_pclk = 0, mmc_push_pull_divisor = 0;
mmc_pclk = host->mmc_input_clk;
if (mmc_req_freq && mmc_pclk > (2 * mmc_req_freq))
mmc_push_pull_divisor = ((unsigned int)mmc_pclk
/ (2 * mmc_req_freq)) - 1;
else
mmc_push_pull_divisor = 0;
mmc_freq = (unsigned int)mmc_pclk
/ (2 * (mmc_push_pull_divisor + 1));
if (mmc_freq > mmc_req_freq)
mmc_push_pull_divisor = mmc_push_pull_divisor + 1;
if (mmc_req_freq <= 400000)
host->ns_in_one_cycle = (1000000) / (((mmc_pclk
/ (2 * (mmc_push_pull_divisor + 1)))/1000));
else
host->ns_in_one_cycle = (1000000) / (((mmc_pclk
/ (2 * (mmc_push_pull_divisor + 1)))/1000000));
return mmc_push_pull_divisor;
}
static void calculate_clk_divider(struct mmc_host *mmc, struct mmc_ios *ios)
{
unsigned int open_drain_freq = 0, mmc_pclk = 0;
unsigned int mmc_push_pull_freq = 0;
struct mmc_davinci_host *host = mmc_priv(mmc);
if (ios->bus_mode == MMC_BUSMODE_OPENDRAIN) {
u32 temp;
open_drain_freq = ((unsigned int)mmc_pclk
/ (2 * MMCSD_INIT_CLOCK)) - 1;
if (open_drain_freq > 0xFF)
open_drain_freq = 0xFF;
temp = readl(host->base + DAVINCI_MMCCLK) & ~MMCCLK_CLKRT_MASK;
temp |= open_drain_freq;
writel(temp, host->base + DAVINCI_MMCCLK);
host->ns_in_one_cycle = (1000000) / (MMCSD_INIT_CLOCK/1000);
} else {
u32 temp;
mmc_push_pull_freq = calculate_freq_for_card(host, ios->clock);
if (mmc_push_pull_freq > 0xFF)
mmc_push_pull_freq = 0xFF;
temp = readl(host->base + DAVINCI_MMCCLK) & ~MMCCLK_CLKEN;
writel(temp, host->base + DAVINCI_MMCCLK);
udelay(10);
temp = readl(host->base + DAVINCI_MMCCLK) & ~MMCCLK_CLKRT_MASK;
temp |= mmc_push_pull_freq;
writel(temp, host->base + DAVINCI_MMCCLK);
writel(temp | MMCCLK_CLKEN, host->base + DAVINCI_MMCCLK);
udelay(10);
}
}
static void mmc_davinci_set_ios(struct mmc_host *mmc, struct mmc_ios *ios)
{
struct mmc_davinci_host *host = mmc_priv(mmc);
struct platform_device *pdev = to_platform_device(mmc->parent);
struct davinci_mmc_config *config = pdev->dev.platform_data;
dev_dbg(mmc_dev(host->mmc),
"clock %dHz busmode %d powermode %d Vdd %04x\n",
ios->clock, ios->bus_mode, ios->power_mode,
ios->vdd);
switch (ios->power_mode) {
case MMC_POWER_OFF:
if (config && config->set_power)
config->set_power(pdev->id, false);
break;
case MMC_POWER_UP:
if (config && config->set_power)
config->set_power(pdev->id, true);
break;
}
switch (ios->bus_width) {
case MMC_BUS_WIDTH_8:
dev_dbg(mmc_dev(host->mmc), "Enabling 8 bit mode\n");
writel((readl(host->base + DAVINCI_MMCCTL) &
~MMCCTL_WIDTH_4_BIT) | MMCCTL_WIDTH_8_BIT,
host->base + DAVINCI_MMCCTL);
break;
case MMC_BUS_WIDTH_4:
dev_dbg(mmc_dev(host->mmc), "Enabling 4 bit mode\n");
if (host->version == MMC_CTLR_VERSION_2)
writel((readl(host->base + DAVINCI_MMCCTL) &
~MMCCTL_WIDTH_8_BIT) | MMCCTL_WIDTH_4_BIT,
host->base + DAVINCI_MMCCTL);
else
writel(readl(host->base + DAVINCI_MMCCTL) |
MMCCTL_WIDTH_4_BIT,
host->base + DAVINCI_MMCCTL);
break;
case MMC_BUS_WIDTH_1:
dev_dbg(mmc_dev(host->mmc), "Enabling 1 bit mode\n");
if (host->version == MMC_CTLR_VERSION_2)
writel(readl(host->base + DAVINCI_MMCCTL) &
~(MMCCTL_WIDTH_8_BIT | MMCCTL_WIDTH_4_BIT),
host->base + DAVINCI_MMCCTL);
else
writel(readl(host->base + DAVINCI_MMCCTL) &
~MMCCTL_WIDTH_4_BIT,
host->base + DAVINCI_MMCCTL);
break;
}
calculate_clk_divider(mmc, ios);
host->bus_mode = ios->bus_mode;
if (ios->power_mode == MMC_POWER_UP) {
unsigned long timeout = jiffies + msecs_to_jiffies(50);
bool lose = true;
writel(0, host->base + DAVINCI_MMCARGHL);
writel(MMCCMD_INITCK, host->base + DAVINCI_MMCCMD);
while (time_before(jiffies, timeout)) {
u32 tmp = readl(host->base + DAVINCI_MMCST0);
if (tmp & MMCST0_RSPDNE) {
lose = false;
break;
}
cpu_relax();
}
if (lose)
dev_warn(mmc_dev(host->mmc), "powerup timeout\n");
}
}
static void
mmc_davinci_xfer_done(struct mmc_davinci_host *host, struct mmc_data *data)
{
host->data = NULL;
if (host->mmc->caps & MMC_CAP_SDIO_IRQ) {
if (host->sdio_int && !(readl(host->base + DAVINCI_SDIOST0) &
SDIOST0_DAT1_HI)) {
writel(SDIOIST_IOINT, host->base + DAVINCI_SDIOIST);
mmc_signal_sdio_irq(host->mmc);
}
}
if (host->do_dma) {
davinci_abort_dma(host);
dma_unmap_sg(mmc_dev(host->mmc), data->sg, data->sg_len,
(data->flags & MMC_DATA_WRITE)
? DMA_TO_DEVICE
: DMA_FROM_DEVICE);
host->do_dma = false;
}
host->data_dir = DAVINCI_MMC_DATADIR_NONE;
if (!data->stop || (host->cmd && host->cmd->error)) {
mmc_request_done(host->mmc, data->mrq);
writel(0, host->base + DAVINCI_MMCIM);
host->active_request = false;
} else
mmc_davinci_start_command(host, data->stop);
}
static void mmc_davinci_cmd_done(struct mmc_davinci_host *host,
struct mmc_command *cmd)
{
host->cmd = NULL;
if (cmd->flags & MMC_RSP_PRESENT) {
if (cmd->flags & MMC_RSP_136) {
cmd->resp[3] = readl(host->base + DAVINCI_MMCRSP01);
cmd->resp[2] = readl(host->base + DAVINCI_MMCRSP23);
cmd->resp[1] = readl(host->base + DAVINCI_MMCRSP45);
cmd->resp[0] = readl(host->base + DAVINCI_MMCRSP67);
} else {
cmd->resp[0] = readl(host->base + DAVINCI_MMCRSP67);
}
}
if (host->data == NULL || cmd->error) {
if (cmd->error == -ETIMEDOUT)
cmd->mrq->cmd->retries = 0;
mmc_request_done(host->mmc, cmd->mrq);
writel(0, host->base + DAVINCI_MMCIM);
host->active_request = false;
}
}
static inline void mmc_davinci_reset_ctrl(struct mmc_davinci_host *host,
int val)
{
u32 temp;
temp = readl(host->base + DAVINCI_MMCCTL);
if (val)
temp |= MMCCTL_CMDRST | MMCCTL_DATRST;
else
temp &= ~(MMCCTL_CMDRST | MMCCTL_DATRST);
writel(temp, host->base + DAVINCI_MMCCTL);
udelay(10);
}
static void
davinci_abort_data(struct mmc_davinci_host *host, struct mmc_data *data)
{
mmc_davinci_reset_ctrl(host, 1);
mmc_davinci_reset_ctrl(host, 0);
}
static irqreturn_t mmc_davinci_sdio_irq(int irq, void *dev_id)
{
struct mmc_davinci_host *host = dev_id;
unsigned int status;
status = readl(host->base + DAVINCI_SDIOIST);
if (status & SDIOIST_IOINT) {
dev_dbg(mmc_dev(host->mmc),
"SDIO interrupt status %x\n", status);
writel(status | SDIOIST_IOINT, host->base + DAVINCI_SDIOIST);
mmc_signal_sdio_irq(host->mmc);
}
return IRQ_HANDLED;
}
static irqreturn_t mmc_davinci_irq(int irq, void *dev_id)
{
struct mmc_davinci_host *host = (struct mmc_davinci_host *)dev_id;
unsigned int status, qstatus;
int end_command = 0;
int end_transfer = 0;
struct mmc_data *data = host->data;
if (host->cmd == NULL && host->data == NULL) {
status = readl(host->base + DAVINCI_MMCST0);
dev_dbg(mmc_dev(host->mmc),
"Spurious interrupt 0x%04x\n", status);
writel(0, host->base + DAVINCI_MMCIM);
return IRQ_NONE;
}
status = readl(host->base + DAVINCI_MMCST0);
qstatus = status;
if (host->bytes_left && (status & (MMCST0_DXRDY | MMCST0_DRRDY))) {
unsigned long im_val;
im_val = readl(host->base + DAVINCI_MMCIM);
writel(0, host->base + DAVINCI_MMCIM);
do {
davinci_fifo_data_trans(host, rw_threshold);
status = readl(host->base + DAVINCI_MMCST0);
qstatus |= status;
} while (host->bytes_left &&
(status & (MMCST0_DXRDY | MMCST0_DRRDY)));
writel(im_val, host->base + DAVINCI_MMCIM);
}
if (qstatus & MMCST0_DATDNE) {
if (data != NULL) {
if ((host->do_dma == 0) && (host->bytes_left > 0)) {
davinci_fifo_data_trans(host, host->bytes_left);
}
end_transfer = 1;
data->bytes_xfered = data->blocks * data->blksz;
} else {
dev_err(mmc_dev(host->mmc),
"DATDNE with no host->data\n");
}
}
if (qstatus & MMCST0_TOUTRD) {
data->error = -ETIMEDOUT;
end_transfer = 1;
dev_dbg(mmc_dev(host->mmc),
"read data timeout, status %x\n",
qstatus);
davinci_abort_data(host, data);
}
if (qstatus & (MMCST0_CRCWR | MMCST0_CRCRD)) {
data->error = -EILSEQ;
end_transfer = 1;
if (qstatus & MMCST0_CRCWR) {
u32 temp = readb(host->base + DAVINCI_MMCDRSP);
if (temp == 0x9f)
data->error = -ETIMEDOUT;
}
dev_dbg(mmc_dev(host->mmc), "data %s %s error\n",
(qstatus & MMCST0_CRCWR) ? "write" : "read",
(data->error == -ETIMEDOUT) ? "timeout" : "CRC");
davinci_abort_data(host, data);
}
if (qstatus & MMCST0_TOUTRS) {
if (host->cmd) {
dev_dbg(mmc_dev(host->mmc),
"CMD%d timeout, status %x\n",
host->cmd->opcode, qstatus);
host->cmd->error = -ETIMEDOUT;
if (data) {
end_transfer = 1;
davinci_abort_data(host, data);
} else
end_command = 1;
}
}
if (qstatus & MMCST0_CRCRS) {
dev_dbg(mmc_dev(host->mmc), "Command CRC error\n");
if (host->cmd) {
host->cmd->error = -EILSEQ;
end_command = 1;
}
}
if (qstatus & MMCST0_RSPDNE) {
end_command = (int) host->cmd;
}
if (end_command)
mmc_davinci_cmd_done(host, host->cmd);
if (end_transfer)
mmc_davinci_xfer_done(host, data);
return IRQ_HANDLED;
}
static int mmc_davinci_get_cd(struct mmc_host *mmc)
{
struct platform_device *pdev = to_platform_device(mmc->parent);
struct davinci_mmc_config *config = pdev->dev.platform_data;
if (config && config->get_cd)
return config->get_cd(pdev->id);
return mmc_gpio_get_cd(mmc);
}
static int mmc_davinci_get_ro(struct mmc_host *mmc)
{
struct platform_device *pdev = to_platform_device(mmc->parent);
struct davinci_mmc_config *config = pdev->dev.platform_data;
if (config && config->get_ro)
return config->get_ro(pdev->id);
return mmc_gpio_get_ro(mmc);
}
static void mmc_davinci_enable_sdio_irq(struct mmc_host *mmc, int enable)
{
struct mmc_davinci_host *host = mmc_priv(mmc);
if (enable) {
if (!(readl(host->base + DAVINCI_SDIOST0) & SDIOST0_DAT1_HI)) {
writel(SDIOIST_IOINT, host->base + DAVINCI_SDIOIST);
mmc_signal_sdio_irq(host->mmc);
} else {
host->sdio_int = true;
writel(readl(host->base + DAVINCI_SDIOIEN) |
SDIOIEN_IOINTEN, host->base + DAVINCI_SDIOIEN);
}
} else {
host->sdio_int = false;
writel(readl(host->base + DAVINCI_SDIOIEN) & ~SDIOIEN_IOINTEN,
host->base + DAVINCI_SDIOIEN);
}
}
static int mmc_davinci_cpufreq_transition(struct notifier_block *nb,
unsigned long val, void *data)
{
struct mmc_davinci_host *host;
unsigned int mmc_pclk;
struct mmc_host *mmc;
unsigned long flags;
host = container_of(nb, struct mmc_davinci_host, freq_transition);
mmc = host->mmc;
mmc_pclk = clk_get_rate(host->clk);
if (val == CPUFREQ_POSTCHANGE) {
spin_lock_irqsave(&mmc->lock, flags);
host->mmc_input_clk = mmc_pclk;
calculate_clk_divider(mmc, &mmc->ios);
spin_unlock_irqrestore(&mmc->lock, flags);
}
return 0;
}
static inline int mmc_davinci_cpufreq_register(struct mmc_davinci_host *host)
{
host->freq_transition.notifier_call = mmc_davinci_cpufreq_transition;
return cpufreq_register_notifier(&host->freq_transition,
CPUFREQ_TRANSITION_NOTIFIER);
}
static inline void mmc_davinci_cpufreq_deregister(struct mmc_davinci_host *host)
{
cpufreq_unregister_notifier(&host->freq_transition,
CPUFREQ_TRANSITION_NOTIFIER);
}
static inline int mmc_davinci_cpufreq_register(struct mmc_davinci_host *host)
{
return 0;
}
static inline void mmc_davinci_cpufreq_deregister(struct mmc_davinci_host *host)
{
}
static void __init init_mmcsd_host(struct mmc_davinci_host *host)
{
mmc_davinci_reset_ctrl(host, 1);
writel(0, host->base + DAVINCI_MMCCLK);
writel(MMCCLK_CLKEN, host->base + DAVINCI_MMCCLK);
writel(0x1FFF, host->base + DAVINCI_MMCTOR);
writel(0xFFFF, host->base + DAVINCI_MMCTOD);
mmc_davinci_reset_ctrl(host, 0);
}
static int mmc_davinci_parse_pdata(struct mmc_host *mmc)
{
struct platform_device *pdev = to_platform_device(mmc->parent);
struct davinci_mmc_config *pdata = pdev->dev.platform_data;
struct mmc_davinci_host *host;
int ret;
if (!pdata)
return -EINVAL;
host = mmc_priv(mmc);
if (!host)
return -EINVAL;
if (pdata && pdata->nr_sg)
host->nr_sg = pdata->nr_sg - 1;
if (pdata && (pdata->wires == 4 || pdata->wires == 0))
mmc->caps |= MMC_CAP_4_BIT_DATA;
if (pdata && (pdata->wires == 8))
mmc->caps |= (MMC_CAP_4_BIT_DATA | MMC_CAP_8_BIT_DATA);
mmc->f_min = 312500;
mmc->f_max = 25000000;
if (pdata && pdata->max_freq)
mmc->f_max = pdata->max_freq;
if (pdata && pdata->caps)
mmc->caps |= pdata->caps;
ret = mmc_gpiod_request_cd(mmc, "cd", 0, false, 0, NULL);
if (ret == -EPROBE_DEFER)
return ret;
else if (ret)
mmc->caps |= MMC_CAP_NEEDS_POLL;
ret = mmc_gpiod_request_ro(mmc, "wp", 0, false, 0, NULL);
if (ret == -EPROBE_DEFER)
return ret;
return 0;
}
static int __init davinci_mmcsd_probe(struct platform_device *pdev)
{
const struct of_device_id *match;
struct mmc_davinci_host *host = NULL;
struct mmc_host *mmc = NULL;
struct resource *r, *mem = NULL;
int ret, irq;
size_t mem_size;
const struct platform_device_id *id_entry;
r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!r)
return -ENODEV;
irq = platform_get_irq(pdev, 0);
if (irq < 0)
return irq;
mem_size = resource_size(r);
mem = devm_request_mem_region(&pdev->dev, r->start, mem_size,
pdev->name);
if (!mem)
return -EBUSY;
mmc = mmc_alloc_host(sizeof(struct mmc_davinci_host), &pdev->dev);
if (!mmc)
return -ENOMEM;
host = mmc_priv(mmc);
host->mmc = mmc;
host->mem_res = mem;
host->base = devm_ioremap(&pdev->dev, mem->start, mem_size);
if (!host->base) {
ret = -ENOMEM;
goto ioremap_fail;
}
host->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(host->clk)) {
ret = PTR_ERR(host->clk);
goto clk_get_fail;
}
ret = clk_prepare_enable(host->clk);
if (ret)
goto clk_prepare_enable_fail;
host->mmc_input_clk = clk_get_rate(host->clk);
match = of_match_device(davinci_mmc_dt_ids, &pdev->dev);
if (match) {
pdev->id_entry = match->data;
ret = mmc_of_parse(mmc);
if (ret) {
dev_err(&pdev->dev,
"could not parse of data: %d\n", ret);
goto parse_fail;
}
} else {
ret = mmc_davinci_parse_pdata(mmc);
if (ret) {
dev_err(&pdev->dev,
"could not parse platform data: %d\n", ret);
goto parse_fail;
} }
if (host->nr_sg > MAX_NR_SG || !host->nr_sg)
host->nr_sg = MAX_NR_SG;
init_mmcsd_host(host);
host->use_dma = use_dma;
host->mmc_irq = irq;
host->sdio_irq = platform_get_irq(pdev, 1);
if (host->use_dma) {
ret = davinci_acquire_dma_channels(host);
if (ret == -EPROBE_DEFER)
goto dma_probe_defer;
else if (ret)
host->use_dma = 0;
}
mmc->caps |= MMC_CAP_WAIT_WHILE_BUSY;
id_entry = platform_get_device_id(pdev);
if (id_entry)
host->version = id_entry->driver_data;
mmc->ops = &mmc_davinci_ops;
mmc->ocr_avail = MMC_VDD_32_33 | MMC_VDD_33_34;
mmc->max_segs = MAX_NR_SG;
mmc->max_seg_size = MAX_CCNT * rw_threshold;
mmc->max_blk_size = 4095;
mmc->max_blk_count = 65535;
mmc->max_req_size = mmc->max_blk_size * mmc->max_blk_count;
dev_dbg(mmc_dev(host->mmc), "max_segs=%d\n", mmc->max_segs);
dev_dbg(mmc_dev(host->mmc), "max_blk_size=%d\n", mmc->max_blk_size);
dev_dbg(mmc_dev(host->mmc), "max_req_size=%d\n", mmc->max_req_size);
dev_dbg(mmc_dev(host->mmc), "max_seg_size=%d\n", mmc->max_seg_size);
platform_set_drvdata(pdev, host);
ret = mmc_davinci_cpufreq_register(host);
if (ret) {
dev_err(&pdev->dev, "failed to register cpufreq\n");
goto cpu_freq_fail;
}
ret = mmc_add_host(mmc);
if (ret < 0)
goto mmc_add_host_fail;
ret = devm_request_irq(&pdev->dev, irq, mmc_davinci_irq, 0,
mmc_hostname(mmc), host);
if (ret)
goto request_irq_fail;
if (host->sdio_irq >= 0) {
ret = devm_request_irq(&pdev->dev, host->sdio_irq,
mmc_davinci_sdio_irq, 0,
mmc_hostname(mmc), host);
if (!ret)
mmc->caps |= MMC_CAP_SDIO_IRQ;
}
rename_region(mem, mmc_hostname(mmc));
dev_info(mmc_dev(host->mmc), "Using %s, %d-bit mode\n",
host->use_dma ? "DMA" : "PIO",
(mmc->caps & MMC_CAP_4_BIT_DATA) ? 4 : 1);
return 0;
request_irq_fail:
mmc_remove_host(mmc);
mmc_add_host_fail:
mmc_davinci_cpufreq_deregister(host);
cpu_freq_fail:
davinci_release_dma_channels(host);
parse_fail:
dma_probe_defer:
clk_disable_unprepare(host->clk);
clk_prepare_enable_fail:
clk_get_fail:
ioremap_fail:
mmc_free_host(mmc);
return ret;
}
static int __exit davinci_mmcsd_remove(struct platform_device *pdev)
{
struct mmc_davinci_host *host = platform_get_drvdata(pdev);
mmc_remove_host(host->mmc);
mmc_davinci_cpufreq_deregister(host);
davinci_release_dma_channels(host);
clk_disable_unprepare(host->clk);
mmc_free_host(host->mmc);
return 0;
}
static int davinci_mmcsd_suspend(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct mmc_davinci_host *host = platform_get_drvdata(pdev);
writel(0, host->base + DAVINCI_MMCIM);
mmc_davinci_reset_ctrl(host, 1);
clk_disable(host->clk);
return 0;
}
static int davinci_mmcsd_resume(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct mmc_davinci_host *host = platform_get_drvdata(pdev);
clk_enable(host->clk);
mmc_davinci_reset_ctrl(host, 0);
return 0;
}
