static void imxmci_stop_clock(struct imxmci_host *host)
{
int i = 0;
u16 reg;
reg = readw(host->base + MMC_REG_STR_STP_CLK);
writew(reg & ~STR_STP_CLK_START_CLK, host->base + MMC_REG_STR_STP_CLK);
while (i < 0x1000) {
if (!(i & 0x7f)) {
reg = readw(host->base + MMC_REG_STR_STP_CLK);
writew(reg | STR_STP_CLK_STOP_CLK,
host->base + MMC_REG_STR_STP_CLK);
}
reg = readw(host->base + MMC_REG_STATUS);
if (!(reg & STATUS_CARD_BUS_CLK_RUN)) {
reg = readw(host->base + MMC_REG_STATUS);
if (!(reg & STATUS_CARD_BUS_CLK_RUN))
return;
}
i++;
}
dev_dbg(mmc_dev(host->mmc), "imxmci_stop_clock blocked, no luck\n");
}
static int imxmci_start_clock(struct imxmci_host *host)
{
unsigned int trials = 0;
unsigned int delay_limit = 128;
unsigned long flags;
u16 reg;
reg = readw(host->base + MMC_REG_STR_STP_CLK);
writew(reg & ~STR_STP_CLK_STOP_CLK, host->base + MMC_REG_STR_STP_CLK);
clear_bit(IMXMCI_PEND_STARTED_b, &host->pending_events);
reg = readw(host->base + MMC_REG_STR_STP_CLK);
writew(reg | STR_STP_CLK_START_CLK, host->base + MMC_REG_STR_STP_CLK);
do {
unsigned int delay = delay_limit;
while (delay--) {
reg = readw(host->base + MMC_REG_STATUS);
if (reg & STATUS_CARD_BUS_CLK_RUN) {
reg = readw(host->base + MMC_REG_STATUS);
if (reg & STATUS_CARD_BUS_CLK_RUN)
return 0;
}
if (test_bit(IMXMCI_PEND_STARTED_b, &host->pending_events))
return 0;
}
local_irq_save(flags);
if (!test_bit(IMXMCI_PEND_STARTED_b, &host->pending_events)) {
reg = readw(host->base + MMC_REG_STR_STP_CLK);
writew(reg | STR_STP_CLK_START_CLK,
host->base + MMC_REG_STR_STP_CLK);
}
local_irq_restore(flags);
} while (++trials < 256);
dev_err(mmc_dev(host->mmc), "imxmci_start_clock blocked, no luck\n");
return -1;
}
static void imxmci_softreset(struct imxmci_host *host)
{
int i;
writew(0x08, host->base + MMC_REG_STR_STP_CLK);
writew(0x0D, host->base + MMC_REG_STR_STP_CLK);
for (i = 0; i < 8; i++)
writew(0x05, host->base + MMC_REG_STR_STP_CLK);
writew(0xff, host->base + MMC_REG_RES_TO);
writew(512, host->base + MMC_REG_BLK_LEN);
writew(1, host->base + MMC_REG_NOB);
}
static int imxmci_busy_wait_for_status(struct imxmci_host *host,
unsigned int *pstat, unsigned int stat_mask,
int timeout, const char *where)
{
int loops = 0;
while (!(*pstat & stat_mask)) {
loops += 2;
if (loops >= timeout) {
dev_dbg(mmc_dev(host->mmc), "busy wait timeout in %s, STATUS = 0x%x (0x%x)\n",
where, *pstat, stat_mask);
return -1;
}
udelay(2);
*pstat |= readw(host->base + MMC_REG_STATUS);
}
if (!loops)
return 0;
if (!(stat_mask & STATUS_END_CMD_RESP) || (host->mmc->ios.clock >= 8000000))
dev_info(mmc_dev(host->mmc), "busy wait for %d usec in %s, STATUS = 0x%x (0x%x)\n",
loops, where, *pstat, stat_mask);
return loops;
}
static void imxmci_setup_data(struct imxmci_host *host, struct mmc_data *data)
{
unsigned int nob = data->blocks;
unsigned int blksz = data->blksz;
unsigned int datasz = nob * blksz;
int i;
if (data->flags & MMC_DATA_STREAM)
nob = 0xffff;
host->data = data;
data->bytes_xfered = 0;
writew(nob, host->base + MMC_REG_NOB);
writew(blksz, host->base + MMC_REG_BLK_LEN);
if (datasz < 512) {
host->dma_size = datasz;
if (data->flags & MMC_DATA_READ) {
host->dma_dir = DMA_FROM_DEVICE;
writew(1, host->base + MMC_REG_NOB);
writew(512, host->base + MMC_REG_BLK_LEN);
} else {
host->dma_dir = DMA_TO_DEVICE;
}
host->data_ptr = (u16 *)sg_virt(data->sg);
host->data_cnt = 0;
clear_bit(IMXMCI_PEND_DMA_DATA_b, &host->pending_events);
set_bit(IMXMCI_PEND_CPU_DATA_b, &host->pending_events);
return;
}
if (data->flags & MMC_DATA_READ) {
host->dma_dir = DMA_FROM_DEVICE;
host->dma_nents = dma_map_sg(mmc_dev(host->mmc), data->sg,
data->sg_len, host->dma_dir);
imx_dma_setup_sg(host->dma, data->sg, data->sg_len, datasz,
host->res->start + MMC_REG_BUFFER_ACCESS,
DMA_MODE_READ);
CCR(host->dma) = CCR_DMOD_LINEAR | CCR_DSIZ_32 | CCR_SMOD_FIFO | CCR_SSIZ_16 | CCR_REN;
} else {
host->dma_dir = DMA_TO_DEVICE;
host->dma_nents = dma_map_sg(mmc_dev(host->mmc), data->sg,
data->sg_len, host->dma_dir);
imx_dma_setup_sg(host->dma, data->sg, data->sg_len, datasz,
host->res->start + MMC_REG_BUFFER_ACCESS,
DMA_MODE_WRITE);
CCR(host->dma) = CCR_SMOD_LINEAR | CCR_SSIZ_32 | CCR_DMOD_FIFO | CCR_DSIZ_16 | CCR_REN;
}
#if 1
host->dma_size = 0;
for (i = 0; i < host->dma_nents; i++)
host->dma_size += data->sg[i].length;
if (datasz > host->dma_size) {
dev_err(mmc_dev(host->mmc), "imxmci_setup_data datasz 0x%x > 0x%x dm_size\n",
datasz, host->dma_size);
}
#endif
host->dma_size = datasz;
wmb();
set_bit(IMXMCI_PEND_DMA_DATA_b, &host->pending_events);
clear_bit(IMXMCI_PEND_CPU_DATA_b, &host->pending_events);
if (host->dma_dir == DMA_FROM_DEVICE)
imx_dma_enable(host->dma);
}
static void imxmci_start_cmd(struct imxmci_host *host, struct mmc_command *cmd, unsigned int cmdat)
{
unsigned long flags;
u32 imask;
WARN_ON(host->cmd != NULL);
host->cmd = cmd;
imxmci_stop_clock(host);
if (cmd->flags & MMC_RSP_BUSY)
cmdat |= CMD_DAT_CONT_BUSY;
switch (mmc_resp_type(cmd)) {
case MMC_RSP_R1:
case MMC_RSP_R1B:
cmdat |= CMD_DAT_CONT_RESPONSE_FORMAT_R1;
break;
case MMC_RSP_R2:
cmdat |= CMD_DAT_CONT_RESPONSE_FORMAT_R2;
break;
case MMC_RSP_R3:
cmdat |= CMD_DAT_CONT_RESPONSE_FORMAT_R3;
break;
default:
break;
}
if (test_and_clear_bit(IMXMCI_PEND_SET_INIT_b, &host->pending_events))
cmdat |= CMD_DAT_CONT_INIT;
if (host->actual_bus_width == MMC_BUS_WIDTH_4)
cmdat |= CMD_DAT_CONT_BUS_WIDTH_4;
writew(cmd->opcode, host->base + MMC_REG_CMD);
writew(cmd->arg >> 16, host->base + MMC_REG_ARGH);
writew(cmd->arg & 0xffff, host->base + MMC_REG_ARGL);
writew(cmdat, host->base + MMC_REG_CMD_DAT_CONT);
atomic_set(&host->stuck_timeout, 0);
set_bit(IMXMCI_PEND_WAIT_RESP_b, &host->pending_events);
imask = IMXMCI_INT_MASK_DEFAULT;
imask &= ~INT_MASK_END_CMD_RES;
if (cmdat & CMD_DAT_CONT_DATA_ENABLE) {
imask &= ~INT_MASK_DATA_TRAN;
if (cmdat & CMD_DAT_CONT_WRITE)
imask &= ~INT_MASK_WRITE_OP_DONE;
if (test_bit(IMXMCI_PEND_CPU_DATA_b, &host->pending_events))
imask &= ~INT_MASK_BUF_READY;
}
spin_lock_irqsave(&host->lock, flags);
host->imask = imask;
writew(host->imask, host->base + MMC_REG_INT_MASK);
spin_unlock_irqrestore(&host->lock, flags);
dev_dbg(mmc_dev(host->mmc), "CMD%02d (0x%02x) mask set to 0x%04x\n",
cmd->opcode, cmd->opcode, imask);
imxmci_start_clock(host);
}
static void imxmci_finish_request(struct imxmci_host *host, struct mmc_request *req)
{
unsigned long flags;
spin_lock_irqsave(&host->lock, flags);
host->pending_events &= ~(IMXMCI_PEND_WAIT_RESP_m | IMXMCI_PEND_DMA_END_m |
IMXMCI_PEND_DMA_DATA_m | IMXMCI_PEND_CPU_DATA_m);
host->imask = IMXMCI_INT_MASK_DEFAULT;
writew(host->imask, host->base + MMC_REG_INT_MASK);
spin_unlock_irqrestore(&host->lock, flags);
if (req && req->cmd)
host->prev_cmd_code = req->cmd->opcode;
host->req = NULL;
host->cmd = NULL;
host->data = NULL;
mmc_request_done(host->mmc, req);
}
static int imxmci_finish_data(struct imxmci_host *host, unsigned int stat)
{
struct mmc_data *data = host->data;
int data_error;
if (test_and_clear_bit(IMXMCI_PEND_DMA_DATA_b, &host->pending_events)) {
imx_dma_disable(host->dma);
dma_unmap_sg(mmc_dev(host->mmc), data->sg, host->dma_nents,
host->dma_dir);
}
if (stat & STATUS_ERR_MASK) {
dev_dbg(mmc_dev(host->mmc), "request failed. status: 0x%08x\n", stat);
if (stat & (STATUS_CRC_READ_ERR | STATUS_CRC_WRITE_ERR))
data->error = -EILSEQ;
else if (stat & STATUS_TIME_OUT_READ)
data->error = -ETIMEDOUT;
else
data->error = -EIO;
} else {
data->bytes_xfered = host->dma_size;
}
data_error = data->error;
host->data = NULL;
return data_error;
}
static int imxmci_cmd_done(struct imxmci_host *host, unsigned int stat)
{
struct mmc_command *cmd = host->cmd;
int i;
u32 a, b, c;
struct mmc_data *data = host->data;
if (!cmd)
return 0;
host->cmd = NULL;
if (stat & STATUS_TIME_OUT_RESP) {
dev_dbg(mmc_dev(host->mmc), "CMD TIMEOUT\n");
cmd->error = -ETIMEDOUT;
} else if (stat & STATUS_RESP_CRC_ERR && cmd->flags & MMC_RSP_CRC) {
dev_dbg(mmc_dev(host->mmc), "cmd crc error\n");
cmd->error = -EILSEQ;
}
if (cmd->flags & MMC_RSP_PRESENT) {
if (cmd->flags & MMC_RSP_136) {
for (i = 0; i < 4; i++) {
a = readw(host->base + MMC_REG_RES_FIFO);
b = readw(host->base + MMC_REG_RES_FIFO);
cmd->resp[i] = a << 16 | b;
}
} else {
a = readw(host->base + MMC_REG_RES_FIFO);
b = readw(host->base + MMC_REG_RES_FIFO);
c = readw(host->base + MMC_REG_RES_FIFO);
cmd->resp[0] = a << 24 | b << 8 | c >> 8;
}
}
dev_dbg(mmc_dev(host->mmc), "RESP 0x%08x, 0x%08x, 0x%08x, 0x%08x, error %d\n",
cmd->resp[0], cmd->resp[1], cmd->resp[2], cmd->resp[3], cmd->error);
if (data && !cmd->error && !(stat & STATUS_ERR_MASK)) {
if (host->req->data->flags & MMC_DATA_WRITE) {
stat = readw(host->base + MMC_REG_STATUS);
if (imxmci_busy_wait_for_status(host, &stat,
STATUS_APPL_BUFF_FE,
40, "imxmci_cmd_done DMA WR") < 0) {
cmd->error = -EIO;
imxmci_finish_data(host, stat);
if (host->req)
imxmci_finish_request(host, host->req);
dev_warn(mmc_dev(host->mmc), "STATUS = 0x%04x\n",
stat);
return 0;
}
if (test_bit(IMXMCI_PEND_DMA_DATA_b, &host->pending_events))
imx_dma_enable(host->dma);
}
} else {
struct mmc_request *req;
imxmci_stop_clock(host);
req = host->req;
if (data)
imxmci_finish_data(host, stat);
if (req)
imxmci_finish_request(host, req);
else
dev_warn(mmc_dev(host->mmc), "imxmci_cmd_done: no request to finish\n");
}
return 1;
}
static int imxmci_data_done(struct imxmci_host *host, unsigned int stat)
{
struct mmc_data *data = host->data;
int data_error;
if (!data)
return 0;
data_error = imxmci_finish_data(host, stat);
if (host->req->stop) {
imxmci_stop_clock(host);
imxmci_start_cmd(host, host->req->stop, 0);
} else {
struct mmc_request *req;
req = host->req;
if (req)
imxmci_finish_request(host, req);
else
dev_warn(mmc_dev(host->mmc), "imxmci_data_done: no request to finish\n");
}
return 1;
}
static int imxmci_cpu_driven_data(struct imxmci_host *host, unsigned int *pstat)
{
int i;
int burst_len;
int trans_done = 0;
unsigned int stat = *pstat;
if (host->actual_bus_width != MMC_BUS_WIDTH_4)
burst_len = 16;
else
burst_len = 64;
dev_dbg(mmc_dev(host->mmc), "imxmci_cpu_driven_data running STATUS = 0x%x\n",
stat);
udelay(20);
if (host->dma_dir == DMA_FROM_DEVICE) {
imxmci_busy_wait_for_status(host, &stat,
STATUS_APPL_BUFF_FF | STATUS_DATA_TRANS_DONE |
STATUS_TIME_OUT_READ,
50, "imxmci_cpu_driven_data read");
while ((stat & (STATUS_APPL_BUFF_FF | STATUS_DATA_TRANS_DONE)) &&
!(stat & STATUS_TIME_OUT_READ) &&
(host->data_cnt < 512)) {
udelay(20);
for (i = burst_len; i >= 2 ; i -= 2) {
u16 data;
data = readw(host->base + MMC_REG_BUFFER_ACCESS);
udelay(10);
if (host->data_cnt+2 <= host->dma_size) {
*(host->data_ptr++) = data;
} else {
if (host->data_cnt < host->dma_size)
*(u8 *)(host->data_ptr) = data;
}
host->data_cnt += 2;
}
stat = readw(host->base + MMC_REG_STATUS);
dev_dbg(mmc_dev(host->mmc), "imxmci_cpu_driven_data read %d burst %d STATUS = 0x%x\n",
host->data_cnt, burst_len, stat);
}
if ((stat & STATUS_DATA_TRANS_DONE) && (host->data_cnt >= 512))
trans_done = 1;
if (host->dma_size & 0x1ff)
stat &= ~STATUS_CRC_READ_ERR;
if (stat & STATUS_TIME_OUT_READ) {
dev_dbg(mmc_dev(host->mmc), "imxmci_cpu_driven_data read timeout STATUS = 0x%x\n",
stat);
trans_done = -1;
}
} else {
imxmci_busy_wait_for_status(host, &stat,
STATUS_APPL_BUFF_FE,
20, "imxmci_cpu_driven_data write");
while ((stat & STATUS_APPL_BUFF_FE) &&
(host->data_cnt < host->dma_size)) {
if (burst_len >= host->dma_size - host->data_cnt) {
burst_len = host->dma_size - host->data_cnt;
host->data_cnt = host->dma_size;
trans_done = 1;
} else {
host->data_cnt += burst_len;
}
for (i = burst_len; i > 0 ; i -= 2)
writew(*(host->data_ptr++), host->base + MMC_REG_BUFFER_ACCESS);
stat = readw(host->base + MMC_REG_STATUS);
dev_dbg(mmc_dev(host->mmc), "imxmci_cpu_driven_data write burst %d STATUS = 0x%x\n",
burst_len, stat);
}
}
*pstat = stat;
return trans_done;
}
static void imxmci_dma_irq(int dma, void *devid)
{
struct imxmci_host *host = devid;
u32 stat = readw(host->base + MMC_REG_STATUS);
atomic_set(&host->stuck_timeout, 0);
host->status_reg = stat;
set_bit(IMXMCI_PEND_DMA_END_b, &host->pending_events);
tasklet_schedule(&host->tasklet);
}
static irqreturn_t imxmci_irq(int irq, void *devid)
{
struct imxmci_host *host = devid;
u32 stat = readw(host->base + MMC_REG_STATUS);
int handled = 1;
writew(host->imask | INT_MASK_SDIO | INT_MASK_AUTO_CARD_DETECT,
host->base + MMC_REG_INT_MASK);
atomic_set(&host->stuck_timeout, 0);
host->status_reg = stat;
set_bit(IMXMCI_PEND_IRQ_b, &host->pending_events);
set_bit(IMXMCI_PEND_STARTED_b, &host->pending_events);
tasklet_schedule(&host->tasklet);
return IRQ_RETVAL(handled);
}
static void imxmci_tasklet_fnc(unsigned long data)
{
struct imxmci_host *host = (struct imxmci_host *)data;
u32 stat;
unsigned int data_dir_mask = 0;
int timeout = 0;
if (atomic_read(&host->stuck_timeout) > 4) {
char *what;
timeout = 1;
stat = readw(host->base + MMC_REG_STATUS);
host->status_reg = stat;
if (test_bit(IMXMCI_PEND_WAIT_RESP_b, &host->pending_events))
if (test_bit(IMXMCI_PEND_DMA_DATA_b, &host->pending_events))
what = "RESP+DMA";
else
what = "RESP";
else
if (test_bit(IMXMCI_PEND_DMA_DATA_b, &host->pending_events))
if (test_bit(IMXMCI_PEND_DMA_END_b, &host->pending_events))
what = "DATA";
else
what = "DMA";
else
what = "???";
dev_err(mmc_dev(host->mmc),
"%s TIMEOUT, hardware stucked STATUS = 0x%04x IMASK = 0x%04x\n",
what, stat,
readw(host->base + MMC_REG_INT_MASK));
dev_err(mmc_dev(host->mmc),
"CMD_DAT_CONT = 0x%04x, MMC_BLK_LEN = 0x%04x, MMC_NOB = 0x%04x, DMA_CCR = 0x%08x\n",
readw(host->base + MMC_REG_CMD_DAT_CONT),
readw(host->base + MMC_REG_BLK_LEN),
readw(host->base + MMC_REG_NOB),
CCR(host->dma));
dev_err(mmc_dev(host->mmc), "CMD%d, prevCMD%d, bus %d-bit, dma_size = 0x%x\n",
host->cmd ? host->cmd->opcode : 0,
host->prev_cmd_code,
1 << host->actual_bus_width, host->dma_size);
}
if (!host->present || timeout)
host->status_reg = STATUS_TIME_OUT_RESP | STATUS_TIME_OUT_READ |
STATUS_CRC_READ_ERR | STATUS_CRC_WRITE_ERR;
if (test_bit(IMXMCI_PEND_IRQ_b, &host->pending_events) || timeout) {
clear_bit(IMXMCI_PEND_IRQ_b, &host->pending_events);
stat = readw(host->base + MMC_REG_STATUS);
stat |= host->status_reg;
if (test_bit(IMXMCI_PEND_CPU_DATA_b, &host->pending_events))
stat &= ~STATUS_CRC_READ_ERR;
if (test_bit(IMXMCI_PEND_WAIT_RESP_b, &host->pending_events)) {
imxmci_busy_wait_for_status(host, &stat,
STATUS_END_CMD_RESP | STATUS_ERR_MASK,
20, "imxmci_tasklet_fnc resp (ERRATUM #4)");
}
if (stat & (STATUS_END_CMD_RESP | STATUS_ERR_MASK)) {
if (test_and_clear_bit(IMXMCI_PEND_WAIT_RESP_b, &host->pending_events))
imxmci_cmd_done(host, stat);
if (host->data && (stat & STATUS_ERR_MASK))
imxmci_data_done(host, stat);
}
if (test_bit(IMXMCI_PEND_CPU_DATA_b, &host->pending_events)) {
stat |= readw(host->base + MMC_REG_STATUS);
if (imxmci_cpu_driven_data(host, &stat)) {
if (test_and_clear_bit(IMXMCI_PEND_WAIT_RESP_b, &host->pending_events))
imxmci_cmd_done(host, stat);
atomic_clear_mask(IMXMCI_PEND_IRQ_m|IMXMCI_PEND_CPU_DATA_m,
&host->pending_events);
imxmci_data_done(host, stat);
}
}
}
if (test_bit(IMXMCI_PEND_DMA_END_b, &host->pending_events) &&
!test_bit(IMXMCI_PEND_WAIT_RESP_b, &host->pending_events)) {
stat = readw(host->base + MMC_REG_STATUS);
stat |= host->status_reg;
if (host->dma_dir == DMA_TO_DEVICE)
data_dir_mask = STATUS_WRITE_OP_DONE;
else
data_dir_mask = STATUS_DATA_TRANS_DONE;
if (stat & data_dir_mask) {
clear_bit(IMXMCI_PEND_DMA_END_b, &host->pending_events);
imxmci_data_done(host, stat);
}
}
if (test_and_clear_bit(IMXMCI_PEND_CARD_XCHG_b, &host->pending_events)) {
if (host->cmd)
imxmci_cmd_done(host, STATUS_TIME_OUT_RESP);
if (host->data)
imxmci_data_done(host, STATUS_TIME_OUT_READ |
STATUS_CRC_READ_ERR | STATUS_CRC_WRITE_ERR);
if (host->req)
imxmci_finish_request(host, host->req);
mmc_detect_change(host->mmc, msecs_to_jiffies(100));
}
}
static void imxmci_request(struct mmc_host *mmc, struct mmc_request *req)
{
struct imxmci_host *host = mmc_priv(mmc);
unsigned int cmdat;
WARN_ON(host->req != NULL);
host->req = req;
cmdat = 0;
if (req->data) {
imxmci_setup_data(host, req->data);
cmdat |= CMD_DAT_CONT_DATA_ENABLE;
if (req->data->flags & MMC_DATA_WRITE)
cmdat |= CMD_DAT_CONT_WRITE;
if (req->data->flags & MMC_DATA_STREAM)
cmdat |= CMD_DAT_CONT_STREAM_BLOCK;
}
imxmci_start_cmd(host, req->cmd, cmdat);
}
static void imxmci_set_ios(struct mmc_host *mmc, struct mmc_ios *ios)
{
struct imxmci_host *host = mmc_priv(mmc);
int prescaler;
if (ios->bus_width == MMC_BUS_WIDTH_4) {
host->actual_bus_width = MMC_BUS_WIDTH_4;
imx_gpio_mode(PB11_PF_SD_DAT3);
BLR(host->dma) = 0;
} else {
host->actual_bus_width = MMC_BUS_WIDTH_1;
imx_gpio_mode(GPIO_PORTB | GPIO_IN | GPIO_PUEN | 11);
BLR(host->dma) = 16;
}
if (host->power_mode != ios->power_mode) {
switch (ios->power_mode) {
case MMC_POWER_OFF:
break;
case MMC_POWER_UP:
set_bit(IMXMCI_PEND_SET_INIT_b, &host->pending_events);
break;
case MMC_POWER_ON:
break;
}
host->power_mode = ios->power_mode;
}
if (ios->clock) {
unsigned int clk;
u16 reg;
clk = clk_get_rate(host->clk);
prescaler = (clk + (CLK_RATE * 7) / 8) / CLK_RATE;
switch (prescaler) {
case 0:
case 1: prescaler = 0;
break;
case 2: prescaler = 1;
break;
case 3: prescaler = 2;
break;
case 4: prescaler = 4;
break;
default:
case 5: prescaler = 5;
break;
}
dev_dbg(mmc_dev(host->mmc), "PERCLK2 %d MHz -> prescaler %d\n",
clk, prescaler);
for (clk = 0; clk < 8; clk++) {
int x;
x = CLK_RATE / (1 << clk);
if (x <= ios->clock)
break;
}
reg = readw(host->base + MMC_REG_STR_STP_CLK);
writew(reg | STR_STP_CLK_ENABLE,
host->base + MMC_REG_STR_STP_CLK);
imxmci_stop_clock(host);
writew((prescaler << 3) | clk, host->base + MMC_REG_CLK_RATE);
dev_dbg(mmc_dev(host->mmc),
"MMC_CLK_RATE: 0x%08x\n",
readw(host->base + MMC_REG_CLK_RATE));
} else {
imxmci_stop_clock(host);
}
}
static int imxmci_get_ro(struct mmc_host *mmc)
{
struct imxmci_host *host = mmc_priv(mmc);
if (host->pdata && host->pdata->get_ro)
return !!host->pdata->get_ro(mmc_dev(mmc));
return -ENOSYS;
}
static void imxmci_check_status(unsigned long data)
{
struct imxmci_host *host = (struct imxmci_host *)data;
if (host->pdata && host->pdata->card_present &&
host->pdata->card_present(mmc_dev(host->mmc)) != host->present) {
host->present ^= 1;
dev_info(mmc_dev(host->mmc), "card %s\n",
host->present ? "inserted" : "removed");
set_bit(IMXMCI_PEND_CARD_XCHG_b, &host->pending_events);
tasklet_schedule(&host->tasklet);
}
if (test_bit(IMXMCI_PEND_WAIT_RESP_b, &host->pending_events) ||
test_bit(IMXMCI_PEND_DMA_DATA_b, &host->pending_events)) {
atomic_inc(&host->stuck_timeout);
if (atomic_read(&host->stuck_timeout) > 4)
tasklet_schedule(&host->tasklet);
} else {
atomic_set(&host->stuck_timeout, 0);
}
mod_timer(&host->timer, jiffies + (HZ>>1));
}
static int __init imxmci_probe(struct platform_device *pdev)
{
struct mmc_host *mmc;
struct imxmci_host *host = NULL;
struct resource *r;
int ret = 0, irq;
u16 rev_no;
pr_info("i.MX mmc driver\n");
r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
irq = platform_get_irq(pdev, 0);
if (!r || irq < 0)
return -ENXIO;
r = request_mem_region(r->start, resource_size(r), pdev->name);
if (!r)
return -EBUSY;
mmc = mmc_alloc_host(sizeof(struct imxmci_host), &pdev->dev);
if (!mmc) {
ret = -ENOMEM;
goto out;
}
mmc->ops = &imxmci_ops;
mmc->f_min = 150000;
mmc->f_max = CLK_RATE/2;
mmc->ocr_avail = MMC_VDD_32_33;
mmc->caps = MMC_CAP_4_BIT_DATA;
mmc->max_segs = 64;
mmc->max_seg_size = 64*512;
mmc->max_req_size = 64*512;
mmc->max_blk_size = 2048;
mmc->max_blk_count = 65535;
host = mmc_priv(mmc);
host->base = ioremap(r->start, resource_size(r));
if (!host->base) {
ret = -ENOMEM;
goto out;
}
host->mmc = mmc;
host->dma_allocated = 0;
host->pdata = pdev->dev.platform_data;
if (!host->pdata)
dev_warn(&pdev->dev, "No platform data provided!\n");
spin_lock_init(&host->lock);
host->res = r;
host->irq = irq;
host->clk = clk_get(&pdev->dev, "perclk2");
if (IS_ERR(host->clk)) {
ret = PTR_ERR(host->clk);
goto out;
}
clk_enable(host->clk);
imx_gpio_mode(PB8_PF_SD_DAT0);
imx_gpio_mode(PB9_PF_SD_DAT1);
imx_gpio_mode(PB10_PF_SD_DAT2);
imx_gpio_mode(GPIO_PORTB | GPIO_IN | GPIO_PUEN | 11);
imx_gpio_mode(PB12_PF_SD_CLK);
imx_gpio_mode(PB13_PF_SD_CMD);
imxmci_softreset(host);
rev_no = readw(host->base + MMC_REG_REV_NO);
if (rev_no != 0x390) {
dev_err(mmc_dev(host->mmc), "wrong rev.no. 0x%08x. aborting.\n",
readw(host->base + MMC_REG_REV_NO));
goto out;
}
writew(0x2db4, host->base + MMC_REG_READ_TO);
host->imask = IMXMCI_INT_MASK_DEFAULT;
writew(host->imask, host->base + MMC_REG_INT_MASK);
host->dma = imx_dma_request_by_prio(DRIVER_NAME, DMA_PRIO_LOW);
if(host->dma < 0) {
dev_err(mmc_dev(host->mmc), "imx_dma_request_by_prio failed\n");
ret = -EBUSY;
goto out;
}
host->dma_allocated = 1;
imx_dma_setup_handlers(host->dma, imxmci_dma_irq, NULL, host);
RSSR(host->dma) = DMA_REQ_SDHC;
tasklet_init(&host->tasklet, imxmci_tasklet_fnc, (unsigned long)host);
host->status_reg=0;
host->pending_events=0;
ret = request_irq(host->irq, imxmci_irq, 0, DRIVER_NAME, host);
if (ret)
goto out;
if (host->pdata && host->pdata->card_present)
host->present = host->pdata->card_present(mmc_dev(mmc));
else
host->present = 1;
init_timer(&host->timer);
host->timer.data = (unsigned long)host;
host->timer.function = imxmci_check_status;
add_timer(&host->timer);
mod_timer(&host->timer, jiffies + (HZ >> 1));
platform_set_drvdata(pdev, mmc);
mmc_add_host(mmc);
return 0;
out:
if (host) {
if (host->dma_allocated) {
imx_dma_free(host->dma);
host->dma_allocated = 0;
}
if (host->clk) {
clk_disable(host->clk);
clk_put(host->clk);
}
if (host->base)
iounmap(host->base);
}
if (mmc)
mmc_free_host(mmc);
release_mem_region(r->start, resource_size(r));
return ret;
}
static int __exit imxmci_remove(struct platform_device *pdev)
{
struct mmc_host *mmc = platform_get_drvdata(pdev);
platform_set_drvdata(pdev, NULL);
if (mmc) {
struct imxmci_host *host = mmc_priv(mmc);
tasklet_disable(&host->tasklet);
del_timer_sync(&host->timer);
mmc_remove_host(mmc);
free_irq(host->irq, host);
iounmap(host->base);
if (host->dma_allocated) {
imx_dma_free(host->dma);
host->dma_allocated = 0;
}
tasklet_kill(&host->tasklet);
clk_disable(host->clk);
clk_put(host->clk);
release_mem_region(host->res->start, resource_size(host->res));
mmc_free_host(mmc);
}
return 0;
}
static int imxmci_suspend(struct platform_device *dev, pm_message_t state)
{
struct mmc_host *mmc = platform_get_drvdata(dev);
int ret = 0;
if (mmc)
ret = mmc_suspend_host(mmc);
return ret;
}
static int imxmci_resume(struct platform_device *dev)
{
struct mmc_host *mmc = platform_get_drvdata(dev);
struct imxmci_host *host;
int ret = 0;
if (mmc) {
host = mmc_priv(mmc);
if (host)
set_bit(IMXMCI_PEND_SET_INIT_b, &host->pending_events);
ret = mmc_resume_host(mmc);
}
return ret;
}
static int __init imxmci_init(void)
{
return platform_driver_probe(&imxmci_driver, imxmci_probe);
}
static void __exit imxmci_exit(void)
{
platform_driver_unregister(&imxmci_driver);
}
