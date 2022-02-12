static void sdr_set_bits(void __iomem *reg, u32 bs)
{
u32 val = readl(reg);
val |= bs;
writel(val, reg);
}
static void sdr_clr_bits(void __iomem *reg, u32 bs)
{
u32 val = readl(reg);
val &= ~bs;
writel(val, reg);
}
static void sdr_set_field(void __iomem *reg, u32 field, u32 val)
{
unsigned int tv = readl(reg);
tv &= ~field;
tv |= ((val) << (ffs((unsigned int)field) - 1));
writel(tv, reg);
}
static void sdr_get_field(void __iomem *reg, u32 field, u32 *val)
{
unsigned int tv = readl(reg);
*val = ((tv & field) >> (ffs((unsigned int)field) - 1));
}
static void msdc_reset_hw(struct msdc_host *host)
{
u32 val;
sdr_set_bits(host->base + MSDC_CFG, MSDC_CFG_RST);
while (readl(host->base + MSDC_CFG) & MSDC_CFG_RST)
cpu_relax();
sdr_set_bits(host->base + MSDC_FIFOCS, MSDC_FIFOCS_CLR);
while (readl(host->base + MSDC_FIFOCS) & MSDC_FIFOCS_CLR)
cpu_relax();
val = readl(host->base + MSDC_INT);
writel(val, host->base + MSDC_INT);
}
static u8 msdc_dma_calcs(u8 *buf, u32 len)
{
u32 i, sum = 0;
for (i = 0; i < len; i++)
sum += buf[i];
return 0xff - (u8) sum;
}
static inline void msdc_dma_setup(struct msdc_host *host, struct msdc_dma *dma,
struct mmc_data *data)
{
unsigned int j, dma_len;
dma_addr_t dma_address;
u32 dma_ctrl;
struct scatterlist *sg;
struct mt_gpdma_desc *gpd;
struct mt_bdma_desc *bd;
sg = data->sg;
gpd = dma->gpd;
bd = dma->bd;
gpd->gpd_info |= GPDMA_DESC_HWO;
gpd->gpd_info |= GPDMA_DESC_BDP;
gpd->gpd_info &= ~GPDMA_DESC_CHECKSUM;
gpd->gpd_info |= msdc_dma_calcs((u8 *) gpd, 16) << 8;
for_each_sg(data->sg, sg, data->sg_count, j) {
dma_address = sg_dma_address(sg);
dma_len = sg_dma_len(sg);
bd[j].bd_info &= ~BDMA_DESC_BLKPAD;
bd[j].bd_info &= ~BDMA_DESC_DWPAD;
bd[j].ptr = (u32)dma_address;
bd[j].bd_data_len &= ~BDMA_DESC_BUFLEN;
bd[j].bd_data_len |= (dma_len & BDMA_DESC_BUFLEN);
if (j == data->sg_count - 1)
bd[j].bd_info |= BDMA_DESC_EOL;
else
bd[j].bd_info &= ~BDMA_DESC_EOL;
bd[j].bd_info &= ~BDMA_DESC_CHECKSUM;
bd[j].bd_info |= msdc_dma_calcs((u8 *)(&bd[j]), 16) << 8;
}
sdr_set_field(host->base + MSDC_DMA_CFG, MSDC_DMA_CFG_DECSEN, 1);
dma_ctrl = readl_relaxed(host->base + MSDC_DMA_CTRL);
dma_ctrl &= ~(MSDC_DMA_CTRL_BRUSTSZ | MSDC_DMA_CTRL_MODE);
dma_ctrl |= (MSDC_BURST_64B << 12 | 1 << 8);
writel_relaxed(dma_ctrl, host->base + MSDC_DMA_CTRL);
writel((u32)dma->gpd_addr, host->base + MSDC_DMA_SA);
}
static void msdc_prepare_data(struct msdc_host *host, struct mmc_request *mrq)
{
struct mmc_data *data = mrq->data;
if (!(data->host_cookie & MSDC_PREPARE_FLAG)) {
bool read = (data->flags & MMC_DATA_READ) != 0;
data->host_cookie |= MSDC_PREPARE_FLAG;
data->sg_count = dma_map_sg(host->dev, data->sg, data->sg_len,
read ? DMA_FROM_DEVICE : DMA_TO_DEVICE);
}
}
static void msdc_unprepare_data(struct msdc_host *host, struct mmc_request *mrq)
{
struct mmc_data *data = mrq->data;
if (data->host_cookie & MSDC_ASYNC_FLAG)
return;
if (data->host_cookie & MSDC_PREPARE_FLAG) {
bool read = (data->flags & MMC_DATA_READ) != 0;
dma_unmap_sg(host->dev, data->sg, data->sg_len,
read ? DMA_FROM_DEVICE : DMA_TO_DEVICE);
data->host_cookie &= ~MSDC_PREPARE_FLAG;
}
}
static void msdc_set_timeout(struct msdc_host *host, u32 ns, u32 clks)
{
u32 timeout, clk_ns;
u32 mode = 0;
host->timeout_ns = ns;
host->timeout_clks = clks;
if (host->sclk == 0) {
timeout = 0;
} else {
clk_ns = 1000000000UL / host->sclk;
timeout = (ns + clk_ns - 1) / clk_ns + clks;
timeout = (timeout + (0x1 << 20) - 1) >> 20;
sdr_get_field(host->base + MSDC_CFG, MSDC_CFG_CKMOD, &mode);
timeout = mode >= 2 ? timeout * 2 : timeout;
timeout = timeout > 1 ? timeout - 1 : 0;
timeout = timeout > 255 ? 255 : timeout;
}
sdr_set_field(host->base + SDC_CFG, SDC_CFG_DTOC, timeout);
}
static void msdc_gate_clock(struct msdc_host *host)
{
clk_disable_unprepare(host->src_clk);
clk_disable_unprepare(host->h_clk);
}
static void msdc_ungate_clock(struct msdc_host *host)
{
clk_prepare_enable(host->h_clk);
clk_prepare_enable(host->src_clk);
while (!(readl(host->base + MSDC_CFG) & MSDC_CFG_CKSTB))
cpu_relax();
}
static void msdc_set_mclk(struct msdc_host *host, unsigned char timing, u32 hz)
{
u32 mode;
u32 flags;
u32 div;
u32 sclk;
if (!hz) {
dev_dbg(host->dev, "set mclk to 0\n");
host->mclk = 0;
sdr_clr_bits(host->base + MSDC_CFG, MSDC_CFG_CKPDN);
return;
}
flags = readl(host->base + MSDC_INTEN);
sdr_clr_bits(host->base + MSDC_INTEN, flags);
sdr_clr_bits(host->base + MSDC_CFG, MSDC_CFG_HS400_CK_MODE);
if (timing == MMC_TIMING_UHS_DDR50 ||
timing == MMC_TIMING_MMC_DDR52 ||
timing == MMC_TIMING_MMC_HS400) {
if (timing == MMC_TIMING_MMC_HS400)
mode = 0x3;
else
mode = 0x2;
if (hz >= (host->src_clk_freq >> 2)) {
div = 0;
sclk = host->src_clk_freq >> 2;
} else {
div = (host->src_clk_freq + ((hz << 2) - 1)) / (hz << 2);
sclk = (host->src_clk_freq >> 2) / div;
div = (div >> 1);
}
if (timing == MMC_TIMING_MMC_HS400 &&
hz >= (host->src_clk_freq >> 1)) {
sdr_set_bits(host->base + MSDC_CFG,
MSDC_CFG_HS400_CK_MODE);
sclk = host->src_clk_freq >> 1;
div = 0;
}
} else if (hz >= host->src_clk_freq) {
mode = 0x1;
div = 0;
sclk = host->src_clk_freq;
} else {
mode = 0x0;
if (hz >= (host->src_clk_freq >> 1)) {
div = 0;
sclk = host->src_clk_freq >> 1;
} else {
div = (host->src_clk_freq + ((hz << 2) - 1)) / (hz << 2);
sclk = (host->src_clk_freq >> 2) / div;
}
}
sdr_set_field(host->base + MSDC_CFG, MSDC_CFG_CKMOD | MSDC_CFG_CKDIV,
(mode << 8) | (div % 0xff));
sdr_set_bits(host->base + MSDC_CFG, MSDC_CFG_CKPDN);
while (!(readl(host->base + MSDC_CFG) & MSDC_CFG_CKSTB))
cpu_relax();
host->sclk = sclk;
host->mclk = hz;
host->timing = timing;
msdc_set_timeout(host, host->timeout_ns, host->timeout_clks);
sdr_set_bits(host->base + MSDC_INTEN, flags);
if (host->sclk <= 52000000) {
writel(host->def_tune_para.iocon, host->base + MSDC_IOCON);
writel(host->def_tune_para.pad_tune, host->base + MSDC_PAD_TUNE);
} else {
writel(host->saved_tune_para.iocon, host->base + MSDC_IOCON);
writel(host->saved_tune_para.pad_tune, host->base + MSDC_PAD_TUNE);
}
dev_dbg(host->dev, "sclk: %d, timing: %d\n", host->sclk, timing);
}
static inline u32 msdc_cmd_find_resp(struct msdc_host *host,
struct mmc_request *mrq, struct mmc_command *cmd)
{
u32 resp;
switch (mmc_resp_type(cmd)) {
case MMC_RSP_R1:
resp = 0x1;
break;
case MMC_RSP_R1B:
resp = 0x7;
break;
case MMC_RSP_R2:
resp = 0x2;
break;
case MMC_RSP_R3:
resp = 0x3;
break;
case MMC_RSP_NONE:
default:
resp = 0x0;
break;
}
return resp;
}
static inline u32 msdc_cmd_prepare_raw_cmd(struct msdc_host *host,
struct mmc_request *mrq, struct mmc_command *cmd)
{
u32 opcode = cmd->opcode;
u32 resp = msdc_cmd_find_resp(host, mrq, cmd);
u32 rawcmd = (opcode & 0x3f) | ((resp & 0x7) << 7);
host->cmd_rsp = resp;
if ((opcode == SD_IO_RW_DIRECT && cmd->flags == (unsigned int) -1) ||
opcode == MMC_STOP_TRANSMISSION)
rawcmd |= (0x1 << 14);
else if (opcode == SD_SWITCH_VOLTAGE)
rawcmd |= (0x1 << 30);
else if (opcode == SD_APP_SEND_SCR ||
opcode == SD_APP_SEND_NUM_WR_BLKS ||
(opcode == SD_SWITCH && mmc_cmd_type(cmd) == MMC_CMD_ADTC) ||
(opcode == SD_APP_SD_STATUS && mmc_cmd_type(cmd) == MMC_CMD_ADTC) ||
(opcode == MMC_SEND_EXT_CSD && mmc_cmd_type(cmd) == MMC_CMD_ADTC))
rawcmd |= (0x1 << 11);
if (cmd->data) {
struct mmc_data *data = cmd->data;
if (mmc_op_multi(opcode)) {
if (mmc_card_mmc(host->mmc->card) && mrq->sbc &&
!(mrq->sbc->arg & 0xFFFF0000))
rawcmd |= 0x2 << 28;
}
rawcmd |= ((data->blksz & 0xFFF) << 16);
if (data->flags & MMC_DATA_WRITE)
rawcmd |= (0x1 << 13);
if (data->blocks > 1)
rawcmd |= (0x2 << 11);
else
rawcmd |= (0x1 << 11);
sdr_clr_bits(host->base + MSDC_CFG, MSDC_CFG_PIO);
if (host->timeout_ns != data->timeout_ns ||
host->timeout_clks != data->timeout_clks)
msdc_set_timeout(host, data->timeout_ns,
data->timeout_clks);
writel(data->blocks, host->base + SDC_BLK_NUM);
}
return rawcmd;
}
static void msdc_start_data(struct msdc_host *host, struct mmc_request *mrq,
struct mmc_command *cmd, struct mmc_data *data)
{
bool read;
WARN_ON(host->data);
host->data = data;
read = data->flags & MMC_DATA_READ;
mod_delayed_work(system_wq, &host->req_timeout, DAT_TIMEOUT);
msdc_dma_setup(host, &host->dma, data);
sdr_set_bits(host->base + MSDC_INTEN, data_ints_mask);
sdr_set_field(host->base + MSDC_DMA_CTRL, MSDC_DMA_CTRL_START, 1);
dev_dbg(host->dev, "DMA start\n");
dev_dbg(host->dev, "%s: cmd=%d DMA data: %d blocks; read=%d\n",
__func__, cmd->opcode, data->blocks, read);
}
static int msdc_auto_cmd_done(struct msdc_host *host, int events,
struct mmc_command *cmd)
{
u32 *rsp = cmd->resp;
rsp[0] = readl(host->base + SDC_ACMD_RESP);
if (events & MSDC_INT_ACMDRDY) {
cmd->error = 0;
} else {
msdc_reset_hw(host);
if (events & MSDC_INT_ACMDCRCERR) {
cmd->error = -EILSEQ;
host->error |= REQ_STOP_EIO;
} else if (events & MSDC_INT_ACMDTMO) {
cmd->error = -ETIMEDOUT;
host->error |= REQ_STOP_TMO;
}
dev_err(host->dev,
"%s: AUTO_CMD%d arg=%08X; rsp %08X; cmd_error=%d\n",
__func__, cmd->opcode, cmd->arg, rsp[0], cmd->error);
}
return cmd->error;
}
static void msdc_track_cmd_data(struct msdc_host *host,
struct mmc_command *cmd, struct mmc_data *data)
{
if (host->error)
dev_dbg(host->dev, "%s: cmd=%d arg=%08X; host->error=0x%08X\n",
__func__, cmd->opcode, cmd->arg, host->error);
}
static void msdc_request_done(struct msdc_host *host, struct mmc_request *mrq)
{
unsigned long flags;
bool ret;
ret = cancel_delayed_work(&host->req_timeout);
if (!ret) {
return;
}
spin_lock_irqsave(&host->lock, flags);
host->mrq = NULL;
spin_unlock_irqrestore(&host->lock, flags);
msdc_track_cmd_data(host, mrq->cmd, mrq->data);
if (mrq->data)
msdc_unprepare_data(host, mrq);
mmc_request_done(host->mmc, mrq);
}
static bool msdc_cmd_done(struct msdc_host *host, int events,
struct mmc_request *mrq, struct mmc_command *cmd)
{
bool done = false;
bool sbc_error;
unsigned long flags;
u32 *rsp = cmd->resp;
if (mrq->sbc && cmd == mrq->cmd &&
(events & (MSDC_INT_ACMDRDY | MSDC_INT_ACMDCRCERR
| MSDC_INT_ACMDTMO)))
msdc_auto_cmd_done(host, events, mrq->sbc);
sbc_error = mrq->sbc && mrq->sbc->error;
if (!sbc_error && !(events & (MSDC_INT_CMDRDY
| MSDC_INT_RSPCRCERR
| MSDC_INT_CMDTMO)))
return done;
spin_lock_irqsave(&host->lock, flags);
done = !host->cmd;
host->cmd = NULL;
spin_unlock_irqrestore(&host->lock, flags);
if (done)
return true;
sdr_clr_bits(host->base + MSDC_INTEN, cmd_ints_mask);
if (cmd->flags & MMC_RSP_PRESENT) {
if (cmd->flags & MMC_RSP_136) {
rsp[0] = readl(host->base + SDC_RESP3);
rsp[1] = readl(host->base + SDC_RESP2);
rsp[2] = readl(host->base + SDC_RESP1);
rsp[3] = readl(host->base + SDC_RESP0);
} else {
rsp[0] = readl(host->base + SDC_RESP0);
}
}
if (!sbc_error && !(events & MSDC_INT_CMDRDY)) {
if (cmd->opcode != MMC_SEND_TUNING_BLOCK &&
cmd->opcode != MMC_SEND_TUNING_BLOCK_HS200)
msdc_reset_hw(host);
if (events & MSDC_INT_RSPCRCERR) {
cmd->error = -EILSEQ;
host->error |= REQ_CMD_EIO;
} else if (events & MSDC_INT_CMDTMO) {
cmd->error = -ETIMEDOUT;
host->error |= REQ_CMD_TMO;
}
}
if (cmd->error)
dev_dbg(host->dev,
"%s: cmd=%d arg=%08X; rsp %08X; cmd_error=%d\n",
__func__, cmd->opcode, cmd->arg, rsp[0],
cmd->error);
msdc_cmd_next(host, mrq, cmd);
return true;
}
static inline bool msdc_cmd_is_ready(struct msdc_host *host,
struct mmc_request *mrq, struct mmc_command *cmd)
{
unsigned long tmo = jiffies + msecs_to_jiffies(20);
while ((readl(host->base + SDC_STS) & SDC_STS_CMDBUSY) &&
time_before(jiffies, tmo))
cpu_relax();
if (readl(host->base + SDC_STS) & SDC_STS_CMDBUSY) {
dev_err(host->dev, "CMD bus busy detected\n");
host->error |= REQ_CMD_BUSY;
msdc_cmd_done(host, MSDC_INT_CMDTMO, mrq, cmd);
return false;
}
if (mmc_resp_type(cmd) == MMC_RSP_R1B || cmd->data) {
tmo = jiffies + msecs_to_jiffies(20);
while ((readl(host->base + SDC_STS) & SDC_STS_SDCBUSY) &&
time_before(jiffies, tmo))
cpu_relax();
if (readl(host->base + SDC_STS) & SDC_STS_SDCBUSY) {
dev_err(host->dev, "Controller busy detected\n");
host->error |= REQ_CMD_BUSY;
msdc_cmd_done(host, MSDC_INT_CMDTMO, mrq, cmd);
return false;
}
}
return true;
}
static void msdc_start_command(struct msdc_host *host,
struct mmc_request *mrq, struct mmc_command *cmd)
{
u32 rawcmd;
WARN_ON(host->cmd);
host->cmd = cmd;
if (!msdc_cmd_is_ready(host, mrq, cmd))
return;
if ((readl(host->base + MSDC_FIFOCS) & MSDC_FIFOCS_TXCNT) >> 16 ||
readl(host->base + MSDC_FIFOCS) & MSDC_FIFOCS_RXCNT) {
dev_err(host->dev, "TX/RX FIFO non-empty before start of IO. Reset\n");
msdc_reset_hw(host);
}
cmd->error = 0;
rawcmd = msdc_cmd_prepare_raw_cmd(host, mrq, cmd);
mod_delayed_work(system_wq, &host->req_timeout, DAT_TIMEOUT);
sdr_set_bits(host->base + MSDC_INTEN, cmd_ints_mask);
writel(cmd->arg, host->base + SDC_ARG);
writel(rawcmd, host->base + SDC_CMD);
}
static void msdc_cmd_next(struct msdc_host *host,
struct mmc_request *mrq, struct mmc_command *cmd)
{
if ((cmd->error &&
!(cmd->error == -EILSEQ &&
(cmd->opcode == MMC_SEND_TUNING_BLOCK ||
cmd->opcode == MMC_SEND_TUNING_BLOCK_HS200))) ||
(mrq->sbc && mrq->sbc->error))
msdc_request_done(host, mrq);
else if (cmd == mrq->sbc)
msdc_start_command(host, mrq, mrq->cmd);
else if (!cmd->data)
msdc_request_done(host, mrq);
else
msdc_start_data(host, mrq, cmd, cmd->data);
}
static void msdc_ops_request(struct mmc_host *mmc, struct mmc_request *mrq)
{
struct msdc_host *host = mmc_priv(mmc);
host->error = 0;
WARN_ON(host->mrq);
host->mrq = mrq;
if (mrq->data)
msdc_prepare_data(host, mrq);
if (mrq->sbc && (!mmc_card_mmc(mmc->card) ||
(mrq->sbc->arg & 0xFFFF0000)))
msdc_start_command(host, mrq, mrq->sbc);
else
msdc_start_command(host, mrq, mrq->cmd);
}
static void msdc_pre_req(struct mmc_host *mmc, struct mmc_request *mrq,
bool is_first_req)
{
struct msdc_host *host = mmc_priv(mmc);
struct mmc_data *data = mrq->data;
if (!data)
return;
msdc_prepare_data(host, mrq);
data->host_cookie |= MSDC_ASYNC_FLAG;
}
static void msdc_post_req(struct mmc_host *mmc, struct mmc_request *mrq,
int err)
{
struct msdc_host *host = mmc_priv(mmc);
struct mmc_data *data;
data = mrq->data;
if (!data)
return;
if (data->host_cookie) {
data->host_cookie &= ~MSDC_ASYNC_FLAG;
msdc_unprepare_data(host, mrq);
}
}
static void msdc_data_xfer_next(struct msdc_host *host,
struct mmc_request *mrq, struct mmc_data *data)
{
if (mmc_op_multi(mrq->cmd->opcode) && mrq->stop && !mrq->stop->error &&
!mrq->sbc)
msdc_start_command(host, mrq, mrq->stop);
else
msdc_request_done(host, mrq);
}
static bool msdc_data_xfer_done(struct msdc_host *host, u32 events,
struct mmc_request *mrq, struct mmc_data *data)
{
struct mmc_command *stop = data->stop;
unsigned long flags;
bool done;
unsigned int check_data = events &
(MSDC_INT_XFER_COMPL | MSDC_INT_DATCRCERR | MSDC_INT_DATTMO
| MSDC_INT_DMA_BDCSERR | MSDC_INT_DMA_GPDCSERR
| MSDC_INT_DMA_PROTECT);
spin_lock_irqsave(&host->lock, flags);
done = !host->data;
if (check_data)
host->data = NULL;
spin_unlock_irqrestore(&host->lock, flags);
if (done)
return true;
if (check_data || (stop && stop->error)) {
dev_dbg(host->dev, "DMA status: 0x%8X\n",
readl(host->base + MSDC_DMA_CFG));
sdr_set_field(host->base + MSDC_DMA_CTRL, MSDC_DMA_CTRL_STOP,
1);
while (readl(host->base + MSDC_DMA_CFG) & MSDC_DMA_CFG_STS)
cpu_relax();
sdr_clr_bits(host->base + MSDC_INTEN, data_ints_mask);
dev_dbg(host->dev, "DMA stop\n");
if ((events & MSDC_INT_XFER_COMPL) && (!stop || !stop->error)) {
data->bytes_xfered = data->blocks * data->blksz;
} else {
dev_dbg(host->dev, "interrupt events: %x\n", events);
msdc_reset_hw(host);
host->error |= REQ_DAT_ERR;
data->bytes_xfered = 0;
if (events & MSDC_INT_DATTMO)
data->error = -ETIMEDOUT;
else if (events & MSDC_INT_DATCRCERR)
data->error = -EILSEQ;
dev_dbg(host->dev, "%s: cmd=%d; blocks=%d",
__func__, mrq->cmd->opcode, data->blocks);
dev_dbg(host->dev, "data_error=%d xfer_size=%d\n",
(int)data->error, data->bytes_xfered);
}
msdc_data_xfer_next(host, mrq, data);
done = true;
}
return done;
}
static void msdc_set_buswidth(struct msdc_host *host, u32 width)
{
u32 val = readl(host->base + SDC_CFG);
val &= ~SDC_CFG_BUSWIDTH;
switch (width) {
default:
case MMC_BUS_WIDTH_1:
val |= (MSDC_BUS_1BITS << 16);
break;
case MMC_BUS_WIDTH_4:
val |= (MSDC_BUS_4BITS << 16);
break;
case MMC_BUS_WIDTH_8:
val |= (MSDC_BUS_8BITS << 16);
break;
}
writel(val, host->base + SDC_CFG);
dev_dbg(host->dev, "Bus Width = %d", width);
}
static int msdc_ops_switch_volt(struct mmc_host *mmc, struct mmc_ios *ios)
{
struct msdc_host *host = mmc_priv(mmc);
int ret = 0;
if (!IS_ERR(mmc->supply.vqmmc)) {
if (ios->signal_voltage != MMC_SIGNAL_VOLTAGE_330 &&
ios->signal_voltage != MMC_SIGNAL_VOLTAGE_180) {
dev_err(host->dev, "Unsupported signal voltage!\n");
return -EINVAL;
}
ret = mmc_regulator_set_vqmmc(mmc, ios);
if (ret) {
dev_dbg(host->dev, "Regulator set error %d (%d)\n",
ret, ios->signal_voltage);
} else {
if (ios->signal_voltage == MMC_SIGNAL_VOLTAGE_180)
pinctrl_select_state(host->pinctrl, host->pins_uhs);
else
pinctrl_select_state(host->pinctrl, host->pins_default);
}
}
return ret;
}
static int msdc_card_busy(struct mmc_host *mmc)
{
struct msdc_host *host = mmc_priv(mmc);
u32 status = readl(host->base + MSDC_PS);
if (((status >> 16) & 0xf) != 0xf)
return 1;
return 0;
}
static void msdc_request_timeout(struct work_struct *work)
{
struct msdc_host *host = container_of(work, struct msdc_host,
req_timeout.work);
dev_err(host->dev, "%s: aborting cmd/data/mrq\n", __func__);
if (host->mrq) {
dev_err(host->dev, "%s: aborting mrq=%p cmd=%d\n", __func__,
host->mrq, host->mrq->cmd->opcode);
if (host->cmd) {
dev_err(host->dev, "%s: aborting cmd=%d\n",
__func__, host->cmd->opcode);
msdc_cmd_done(host, MSDC_INT_CMDTMO, host->mrq,
host->cmd);
} else if (host->data) {
dev_err(host->dev, "%s: abort data: cmd%d; %d blocks\n",
__func__, host->mrq->cmd->opcode,
host->data->blocks);
msdc_data_xfer_done(host, MSDC_INT_DATTMO, host->mrq,
host->data);
}
}
}
static irqreturn_t msdc_irq(int irq, void *dev_id)
{
struct msdc_host *host = (struct msdc_host *) dev_id;
while (true) {
unsigned long flags;
struct mmc_request *mrq;
struct mmc_command *cmd;
struct mmc_data *data;
u32 events, event_mask;
spin_lock_irqsave(&host->lock, flags);
events = readl(host->base + MSDC_INT);
event_mask = readl(host->base + MSDC_INTEN);
writel(events & event_mask, host->base + MSDC_INT);
mrq = host->mrq;
cmd = host->cmd;
data = host->data;
spin_unlock_irqrestore(&host->lock, flags);
if (!(events & event_mask))
break;
if (!mrq) {
dev_err(host->dev,
"%s: MRQ=NULL; events=%08X; event_mask=%08X\n",
__func__, events, event_mask);
WARN_ON(1);
break;
}
dev_dbg(host->dev, "%s: events=%08X\n", __func__, events);
if (cmd)
msdc_cmd_done(host, events, mrq, cmd);
else if (data)
msdc_data_xfer_done(host, events, mrq, data);
}
return IRQ_HANDLED;
}
static void msdc_init_hw(struct msdc_host *host)
{
u32 val;
sdr_set_bits(host->base + MSDC_CFG, MSDC_CFG_MODE | MSDC_CFG_CKPDN);
msdc_reset_hw(host);
sdr_clr_bits(host->base + MSDC_PS, MSDC_PS_CDEN);
writel(0, host->base + MSDC_INTEN);
val = readl(host->base + MSDC_INT);
writel(val, host->base + MSDC_INT);
writel(0, host->base + MSDC_PAD_TUNE);
writel(0, host->base + MSDC_IOCON);
sdr_set_field(host->base + MSDC_IOCON, MSDC_IOCON_DDLSEL, 0);
writel(0x403c0046, host->base + MSDC_PATCH_BIT);
sdr_set_field(host->base + MSDC_PATCH_BIT, MSDC_CKGEN_MSDC_DLY_SEL, 1);
writel(0xffff0089, host->base + MSDC_PATCH_BIT1);
sdr_set_bits(host->base + EMMC50_CFG0, EMMC50_CFG_CFCSTS_SEL);
sdr_set_bits(host->base + SDC_CFG, SDC_CFG_SDIO);
sdr_clr_bits(host->base + SDC_CFG, SDC_CFG_SDIOIDE);
sdr_set_field(host->base + SDC_CFG, SDC_CFG_DTOC, 3);
host->def_tune_para.iocon = readl(host->base + MSDC_IOCON);
host->def_tune_para.pad_tune = readl(host->base + MSDC_PAD_TUNE);
dev_dbg(host->dev, "init hardware done!");
}
static void msdc_deinit_hw(struct msdc_host *host)
{
u32 val;
writel(0, host->base + MSDC_INTEN);
val = readl(host->base + MSDC_INT);
writel(val, host->base + MSDC_INT);
}
static void msdc_init_gpd_bd(struct msdc_host *host, struct msdc_dma *dma)
{
struct mt_gpdma_desc *gpd = dma->gpd;
struct mt_bdma_desc *bd = dma->bd;
int i;
memset(gpd, 0, sizeof(struct mt_gpdma_desc) * 2);
gpd->gpd_info = GPDMA_DESC_BDP;
gpd->ptr = (u32)dma->bd_addr;
gpd->next = (u32)dma->gpd_addr + sizeof(struct mt_gpdma_desc);
memset(bd, 0, sizeof(struct mt_bdma_desc) * MAX_BD_NUM);
for (i = 0; i < (MAX_BD_NUM - 1); i++)
bd[i].next = (u32)dma->bd_addr + sizeof(*bd) * (i + 1);
}
static void msdc_ops_set_ios(struct mmc_host *mmc, struct mmc_ios *ios)
{
struct msdc_host *host = mmc_priv(mmc);
int ret;
msdc_set_buswidth(host, ios->bus_width);
switch (ios->power_mode) {
case MMC_POWER_UP:
if (!IS_ERR(mmc->supply.vmmc)) {
msdc_init_hw(host);
ret = mmc_regulator_set_ocr(mmc, mmc->supply.vmmc,
ios->vdd);
if (ret) {
dev_err(host->dev, "Failed to set vmmc power!\n");
return;
}
}
break;
case MMC_POWER_ON:
if (!IS_ERR(mmc->supply.vqmmc) && !host->vqmmc_enabled) {
ret = regulator_enable(mmc->supply.vqmmc);
if (ret)
dev_err(host->dev, "Failed to set vqmmc power!\n");
else
host->vqmmc_enabled = true;
}
break;
case MMC_POWER_OFF:
if (!IS_ERR(mmc->supply.vmmc))
mmc_regulator_set_ocr(mmc, mmc->supply.vmmc, 0);
if (!IS_ERR(mmc->supply.vqmmc) && host->vqmmc_enabled) {
regulator_disable(mmc->supply.vqmmc);
host->vqmmc_enabled = false;
}
break;
default:
break;
}
if (host->mclk != ios->clock || host->timing != ios->timing)
msdc_set_mclk(host, ios->timing, ios->clock);
}
static u32 test_delay_bit(u32 delay, u32 bit)
{
bit %= PAD_DELAY_MAX;
return delay & (1 << bit);
}
static int get_delay_len(u32 delay, u32 start_bit)
{
int i;
for (i = 0; i < (PAD_DELAY_MAX - start_bit); i++) {
if (test_delay_bit(delay, start_bit + i) == 0)
return i;
}
return PAD_DELAY_MAX - start_bit;
}
static struct msdc_delay_phase get_best_delay(struct msdc_host *host, u32 delay)
{
int start = 0, len = 0;
int start_final = 0, len_final = 0;
u8 final_phase = 0xff;
struct msdc_delay_phase delay_phase = { 0, };
if (delay == 0) {
dev_err(host->dev, "phase error: [map:%x]\n", delay);
delay_phase.final_phase = final_phase;
return delay_phase;
}
while (start < PAD_DELAY_MAX) {
len = get_delay_len(delay, start);
if (len_final < len) {
start_final = start;
len_final = len;
}
start += len ? len : 1;
if (len >= 8 && start_final < 4)
break;
}
if (start_final == 0)
final_phase = (start_final + len_final / 3) % PAD_DELAY_MAX;
else
final_phase = (start_final + len_final / 2) % PAD_DELAY_MAX;
dev_info(host->dev, "phase: [map:%x] [maxlen:%d] [final:%d]\n",
delay, len_final, final_phase);
delay_phase.maxlen = len_final;
delay_phase.start = start_final;
delay_phase.final_phase = final_phase;
return delay_phase;
}
static int msdc_tune_response(struct mmc_host *mmc, u32 opcode)
{
struct msdc_host *host = mmc_priv(mmc);
u32 rise_delay = 0, fall_delay = 0;
struct msdc_delay_phase final_rise_delay, final_fall_delay = { 0,};
u8 final_delay, final_maxlen;
int cmd_err;
int i;
sdr_clr_bits(host->base + MSDC_IOCON, MSDC_IOCON_RSPL);
for (i = 0 ; i < PAD_DELAY_MAX; i++) {
sdr_set_field(host->base + MSDC_PAD_TUNE,
MSDC_PAD_TUNE_CMDRDLY, i);
mmc_send_tuning(mmc, opcode, &cmd_err);
if (!cmd_err)
rise_delay |= (1 << i);
}
final_rise_delay = get_best_delay(host, rise_delay);
if (final_rise_delay.maxlen >= 10 ||
(final_rise_delay.start == 0 && final_rise_delay.maxlen >= 4))
goto skip_fall;
sdr_set_bits(host->base + MSDC_IOCON, MSDC_IOCON_RSPL);
for (i = 0; i < PAD_DELAY_MAX; i++) {
sdr_set_field(host->base + MSDC_PAD_TUNE,
MSDC_PAD_TUNE_CMDRDLY, i);
mmc_send_tuning(mmc, opcode, &cmd_err);
if (!cmd_err)
fall_delay |= (1 << i);
}
final_fall_delay = get_best_delay(host, fall_delay);
skip_fall:
final_maxlen = max(final_rise_delay.maxlen, final_fall_delay.maxlen);
if (final_maxlen == final_rise_delay.maxlen) {
sdr_clr_bits(host->base + MSDC_IOCON, MSDC_IOCON_RSPL);
sdr_set_field(host->base + MSDC_PAD_TUNE, MSDC_PAD_TUNE_CMDRDLY,
final_rise_delay.final_phase);
final_delay = final_rise_delay.final_phase;
} else {
sdr_set_bits(host->base + MSDC_IOCON, MSDC_IOCON_RSPL);
sdr_set_field(host->base + MSDC_PAD_TUNE, MSDC_PAD_TUNE_CMDRDLY,
final_fall_delay.final_phase);
final_delay = final_fall_delay.final_phase;
}
return final_delay == 0xff ? -EIO : 0;
}
static int msdc_tune_data(struct mmc_host *mmc, u32 opcode)
{
struct msdc_host *host = mmc_priv(mmc);
u32 rise_delay = 0, fall_delay = 0;
struct msdc_delay_phase final_rise_delay, final_fall_delay = { 0,};
u8 final_delay, final_maxlen;
int i, ret;
sdr_clr_bits(host->base + MSDC_IOCON, MSDC_IOCON_DSPL);
sdr_clr_bits(host->base + MSDC_IOCON, MSDC_IOCON_W_DSPL);
for (i = 0 ; i < PAD_DELAY_MAX; i++) {
sdr_set_field(host->base + MSDC_PAD_TUNE,
MSDC_PAD_TUNE_DATRRDLY, i);
ret = mmc_send_tuning(mmc, opcode, NULL);
if (!ret)
rise_delay |= (1 << i);
}
final_rise_delay = get_best_delay(host, rise_delay);
if (final_rise_delay.maxlen >= 10 ||
(final_rise_delay.start == 0 && final_rise_delay.maxlen >= 4))
goto skip_fall;
sdr_set_bits(host->base + MSDC_IOCON, MSDC_IOCON_DSPL);
sdr_set_bits(host->base + MSDC_IOCON, MSDC_IOCON_W_DSPL);
for (i = 0; i < PAD_DELAY_MAX; i++) {
sdr_set_field(host->base + MSDC_PAD_TUNE,
MSDC_PAD_TUNE_DATRRDLY, i);
ret = mmc_send_tuning(mmc, opcode, NULL);
if (!ret)
fall_delay |= (1 << i);
}
final_fall_delay = get_best_delay(host, fall_delay);
skip_fall:
final_maxlen = max(final_rise_delay.maxlen, final_fall_delay.maxlen);
if (final_maxlen == final_rise_delay.maxlen) {
sdr_clr_bits(host->base + MSDC_IOCON, MSDC_IOCON_DSPL);
sdr_clr_bits(host->base + MSDC_IOCON, MSDC_IOCON_W_DSPL);
sdr_set_field(host->base + MSDC_PAD_TUNE,
MSDC_PAD_TUNE_DATRRDLY,
final_rise_delay.final_phase);
final_delay = final_rise_delay.final_phase;
} else {
sdr_set_bits(host->base + MSDC_IOCON, MSDC_IOCON_DSPL);
sdr_set_bits(host->base + MSDC_IOCON, MSDC_IOCON_W_DSPL);
sdr_set_field(host->base + MSDC_PAD_TUNE,
MSDC_PAD_TUNE_DATRRDLY,
final_fall_delay.final_phase);
final_delay = final_fall_delay.final_phase;
}
return final_delay == 0xff ? -EIO : 0;
}
static int msdc_execute_tuning(struct mmc_host *mmc, u32 opcode)
{
struct msdc_host *host = mmc_priv(mmc);
int ret;
ret = msdc_tune_response(mmc, opcode);
if (ret == -EIO) {
dev_err(host->dev, "Tune response fail!\n");
return ret;
}
if (host->hs400_mode == false) {
ret = msdc_tune_data(mmc, opcode);
if (ret == -EIO)
dev_err(host->dev, "Tune data fail!\n");
}
host->saved_tune_para.iocon = readl(host->base + MSDC_IOCON);
host->saved_tune_para.pad_tune = readl(host->base + MSDC_PAD_TUNE);
return ret;
}
static int msdc_prepare_hs400_tuning(struct mmc_host *mmc, struct mmc_ios *ios)
{
struct msdc_host *host = mmc_priv(mmc);
host->hs400_mode = true;
writel(host->hs400_ds_delay, host->base + PAD_DS_TUNE);
return 0;
}
static void msdc_hw_reset(struct mmc_host *mmc)
{
struct msdc_host *host = mmc_priv(mmc);
sdr_set_bits(host->base + EMMC_IOCON, 1);
udelay(10);
sdr_clr_bits(host->base + EMMC_IOCON, 1);
}
static int msdc_drv_probe(struct platform_device *pdev)
{
struct mmc_host *mmc;
struct msdc_host *host;
struct resource *res;
int ret;
if (!pdev->dev.of_node) {
dev_err(&pdev->dev, "No DT found\n");
return -EINVAL;
}
mmc = mmc_alloc_host(sizeof(struct msdc_host), &pdev->dev);
if (!mmc)
return -ENOMEM;
host = mmc_priv(mmc);
ret = mmc_of_parse(mmc);
if (ret)
goto host_free;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
host->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(host->base)) {
ret = PTR_ERR(host->base);
goto host_free;
}
ret = mmc_regulator_get_supply(mmc);
if (ret == -EPROBE_DEFER)
goto host_free;
host->src_clk = devm_clk_get(&pdev->dev, "source");
if (IS_ERR(host->src_clk)) {
ret = PTR_ERR(host->src_clk);
goto host_free;
}
host->h_clk = devm_clk_get(&pdev->dev, "hclk");
if (IS_ERR(host->h_clk)) {
ret = PTR_ERR(host->h_clk);
goto host_free;
}
host->irq = platform_get_irq(pdev, 0);
if (host->irq < 0) {
ret = -EINVAL;
goto host_free;
}
host->pinctrl = devm_pinctrl_get(&pdev->dev);
if (IS_ERR(host->pinctrl)) {
ret = PTR_ERR(host->pinctrl);
dev_err(&pdev->dev, "Cannot find pinctrl!\n");
goto host_free;
}
host->pins_default = pinctrl_lookup_state(host->pinctrl, "default");
if (IS_ERR(host->pins_default)) {
ret = PTR_ERR(host->pins_default);
dev_err(&pdev->dev, "Cannot find pinctrl default!\n");
goto host_free;
}
host->pins_uhs = pinctrl_lookup_state(host->pinctrl, "state_uhs");
if (IS_ERR(host->pins_uhs)) {
ret = PTR_ERR(host->pins_uhs);
dev_err(&pdev->dev, "Cannot find pinctrl uhs!\n");
goto host_free;
}
if (!of_property_read_u32(pdev->dev.of_node, "hs400-ds-delay",
&host->hs400_ds_delay))
dev_dbg(&pdev->dev, "hs400-ds-delay: %x\n",
host->hs400_ds_delay);
host->dev = &pdev->dev;
host->mmc = mmc;
host->src_clk_freq = clk_get_rate(host->src_clk);
mmc->ops = &mt_msdc_ops;
mmc->f_min = host->src_clk_freq / (4 * 255);
mmc->caps |= MMC_CAP_ERASE | MMC_CAP_CMD23;
mmc->max_segs = MAX_BD_NUM;
mmc->max_seg_size = BDMA_DESC_BUFLEN;
mmc->max_blk_size = 2048;
mmc->max_req_size = 512 * 1024;
mmc->max_blk_count = mmc->max_req_size / 512;
host->dma_mask = DMA_BIT_MASK(32);
mmc_dev(mmc)->dma_mask = &host->dma_mask;
host->timeout_clks = 3 * 1048576;
host->dma.gpd = dma_alloc_coherent(&pdev->dev,
2 * sizeof(struct mt_gpdma_desc),
&host->dma.gpd_addr, GFP_KERNEL);
host->dma.bd = dma_alloc_coherent(&pdev->dev,
MAX_BD_NUM * sizeof(struct mt_bdma_desc),
&host->dma.bd_addr, GFP_KERNEL);
if (!host->dma.gpd || !host->dma.bd) {
ret = -ENOMEM;
goto release_mem;
}
msdc_init_gpd_bd(host, &host->dma);
INIT_DELAYED_WORK(&host->req_timeout, msdc_request_timeout);
spin_lock_init(&host->lock);
platform_set_drvdata(pdev, mmc);
msdc_ungate_clock(host);
msdc_init_hw(host);
ret = devm_request_irq(&pdev->dev, host->irq, msdc_irq,
IRQF_TRIGGER_LOW | IRQF_ONESHOT, pdev->name, host);
if (ret)
goto release;
pm_runtime_set_active(host->dev);
pm_runtime_set_autosuspend_delay(host->dev, MTK_MMC_AUTOSUSPEND_DELAY);
pm_runtime_use_autosuspend(host->dev);
pm_runtime_enable(host->dev);
ret = mmc_add_host(mmc);
if (ret)
goto end;
return 0;
end:
pm_runtime_disable(host->dev);
release:
platform_set_drvdata(pdev, NULL);
msdc_deinit_hw(host);
msdc_gate_clock(host);
release_mem:
if (host->dma.gpd)
dma_free_coherent(&pdev->dev,
2 * sizeof(struct mt_gpdma_desc),
host->dma.gpd, host->dma.gpd_addr);
if (host->dma.bd)
dma_free_coherent(&pdev->dev,
MAX_BD_NUM * sizeof(struct mt_bdma_desc),
host->dma.bd, host->dma.bd_addr);
host_free:
mmc_free_host(mmc);
return ret;
}
static int msdc_drv_remove(struct platform_device *pdev)
{
struct mmc_host *mmc;
struct msdc_host *host;
mmc = platform_get_drvdata(pdev);
host = mmc_priv(mmc);
pm_runtime_get_sync(host->dev);
platform_set_drvdata(pdev, NULL);
mmc_remove_host(host->mmc);
msdc_deinit_hw(host);
msdc_gate_clock(host);
pm_runtime_disable(host->dev);
pm_runtime_put_noidle(host->dev);
dma_free_coherent(&pdev->dev,
sizeof(struct mt_gpdma_desc),
host->dma.gpd, host->dma.gpd_addr);
dma_free_coherent(&pdev->dev, MAX_BD_NUM * sizeof(struct mt_bdma_desc),
host->dma.bd, host->dma.bd_addr);
mmc_free_host(host->mmc);
return 0;
}
static void msdc_save_reg(struct msdc_host *host)
{
host->save_para.msdc_cfg = readl(host->base + MSDC_CFG);
host->save_para.iocon = readl(host->base + MSDC_IOCON);
host->save_para.sdc_cfg = readl(host->base + SDC_CFG);
host->save_para.pad_tune = readl(host->base + MSDC_PAD_TUNE);
host->save_para.patch_bit0 = readl(host->base + MSDC_PATCH_BIT);
host->save_para.patch_bit1 = readl(host->base + MSDC_PATCH_BIT1);
host->save_para.pad_ds_tune = readl(host->base + PAD_DS_TUNE);
host->save_para.emmc50_cfg0 = readl(host->base + EMMC50_CFG0);
}
static void msdc_restore_reg(struct msdc_host *host)
{
writel(host->save_para.msdc_cfg, host->base + MSDC_CFG);
writel(host->save_para.iocon, host->base + MSDC_IOCON);
writel(host->save_para.sdc_cfg, host->base + SDC_CFG);
writel(host->save_para.pad_tune, host->base + MSDC_PAD_TUNE);
writel(host->save_para.patch_bit0, host->base + MSDC_PATCH_BIT);
writel(host->save_para.patch_bit1, host->base + MSDC_PATCH_BIT1);
writel(host->save_para.pad_ds_tune, host->base + PAD_DS_TUNE);
writel(host->save_para.emmc50_cfg0, host->base + EMMC50_CFG0);
}
static int msdc_runtime_suspend(struct device *dev)
{
struct mmc_host *mmc = dev_get_drvdata(dev);
struct msdc_host *host = mmc_priv(mmc);
msdc_save_reg(host);
msdc_gate_clock(host);
return 0;
}
static int msdc_runtime_resume(struct device *dev)
{
struct mmc_host *mmc = dev_get_drvdata(dev);
struct msdc_host *host = mmc_priv(mmc);
msdc_ungate_clock(host);
msdc_restore_reg(host);
return 0;
}
