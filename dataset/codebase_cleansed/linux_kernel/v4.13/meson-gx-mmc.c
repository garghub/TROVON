static unsigned int meson_mmc_get_timeout_msecs(struct mmc_data *data)
{
unsigned int timeout = data->timeout_ns / NSEC_PER_MSEC;
if (!timeout)
return SD_EMMC_CMD_TIMEOUT_DATA;
timeout = roundup_pow_of_two(timeout);
return min(timeout, 32768U);
}
static struct mmc_command *meson_mmc_get_next_command(struct mmc_command *cmd)
{
if (cmd->opcode == MMC_SET_BLOCK_COUNT && !cmd->error)
return cmd->mrq->cmd;
else if (mmc_op_multi(cmd->opcode) &&
(!cmd->mrq->sbc || cmd->error || cmd->data->error))
return cmd->mrq->stop;
else
return NULL;
}
static void meson_mmc_get_transfer_mode(struct mmc_host *mmc,
struct mmc_request *mrq)
{
struct mmc_data *data = mrq->data;
struct scatterlist *sg;
int i;
bool use_desc_chain_mode = true;
if (mrq->cmd->opcode == SD_IO_RW_EXTENDED)
return;
for_each_sg(data->sg, sg, data->sg_len, i)
if (sg->offset & 7) {
WARN_ONCE(1, "unaligned scatterlist buffer\n");
use_desc_chain_mode = false;
break;
}
if (use_desc_chain_mode)
data->host_cookie |= SD_EMMC_DESC_CHAIN_MODE;
}
static inline bool meson_mmc_desc_chain_mode(const struct mmc_data *data)
{
return data->host_cookie & SD_EMMC_DESC_CHAIN_MODE;
}
static inline bool meson_mmc_bounce_buf_read(const struct mmc_data *data)
{
return data && data->flags & MMC_DATA_READ &&
!meson_mmc_desc_chain_mode(data);
}
static void meson_mmc_pre_req(struct mmc_host *mmc, struct mmc_request *mrq)
{
struct mmc_data *data = mrq->data;
if (!data)
return;
meson_mmc_get_transfer_mode(mmc, mrq);
data->host_cookie |= SD_EMMC_PRE_REQ_DONE;
if (!meson_mmc_desc_chain_mode(data))
return;
data->sg_count = dma_map_sg(mmc_dev(mmc), data->sg, data->sg_len,
mmc_get_dma_dir(data));
if (!data->sg_count)
dev_err(mmc_dev(mmc), "dma_map_sg failed");
}
static void meson_mmc_post_req(struct mmc_host *mmc, struct mmc_request *mrq,
int err)
{
struct mmc_data *data = mrq->data;
if (data && meson_mmc_desc_chain_mode(data) && data->sg_count)
dma_unmap_sg(mmc_dev(mmc), data->sg, data->sg_len,
mmc_get_dma_dir(data));
}
static int meson_mmc_clk_set(struct meson_host *host, unsigned long clk_rate)
{
struct mmc_host *mmc = host->mmc;
int ret;
u32 cfg;
if (clk_rate) {
if (WARN_ON(clk_rate > mmc->f_max))
clk_rate = mmc->f_max;
else if (WARN_ON(clk_rate < mmc->f_min))
clk_rate = mmc->f_min;
}
if (clk_rate == host->current_clock)
return 0;
cfg = readl(host->regs + SD_EMMC_CFG);
if (!(cfg & CFG_STOP_CLOCK)) {
cfg |= CFG_STOP_CLOCK;
writel(cfg, host->regs + SD_EMMC_CFG);
}
dev_dbg(host->dev, "change clock rate %u -> %lu\n",
mmc->actual_clock, clk_rate);
if (!clk_rate) {
mmc->actual_clock = 0;
host->current_clock = 0;
return 0;
}
ret = clk_set_rate(host->cfg_div_clk, clk_rate);
if (ret) {
dev_err(host->dev, "Unable to set cfg_div_clk to %lu. ret=%d\n",
clk_rate, ret);
return ret;
}
mmc->actual_clock = clk_get_rate(host->cfg_div_clk);
host->current_clock = clk_rate;
if (clk_rate != mmc->actual_clock)
dev_dbg(host->dev,
"divider requested rate %lu != actual rate %u\n",
clk_rate, mmc->actual_clock);
cfg = readl(host->regs + SD_EMMC_CFG);
cfg &= ~CFG_STOP_CLOCK;
writel(cfg, host->regs + SD_EMMC_CFG);
return 0;
}
static int meson_mmc_clk_init(struct meson_host *host)
{
struct clk_init_data init;
char clk_name[32];
int i, ret = 0;
const char *mux_parent_names[MUX_CLK_NUM_PARENTS];
const char *clk_div_parents[1];
u32 clk_reg, cfg;
for (i = 0; i < MUX_CLK_NUM_PARENTS; i++) {
struct clk *clk;
char name[16];
snprintf(name, sizeof(name), "clkin%d", i);
clk = devm_clk_get(host->dev, name);
if (IS_ERR(clk)) {
if (clk != ERR_PTR(-EPROBE_DEFER))
dev_err(host->dev, "Missing clock %s\n", name);
return PTR_ERR(clk);
}
mux_parent_names[i] = __clk_get_name(clk);
}
snprintf(clk_name, sizeof(clk_name), "%s#mux", dev_name(host->dev));
init.name = clk_name;
init.ops = &clk_mux_ops;
init.flags = 0;
init.parent_names = mux_parent_names;
init.num_parents = MUX_CLK_NUM_PARENTS;
host->mux.reg = host->regs + SD_EMMC_CLOCK;
host->mux.shift = __bf_shf(CLK_SRC_MASK);
host->mux.mask = CLK_SRC_MASK;
host->mux.flags = 0;
host->mux.table = NULL;
host->mux.hw.init = &init;
host->mux_clk = devm_clk_register(host->dev, &host->mux.hw);
if (WARN_ON(IS_ERR(host->mux_clk)))
return PTR_ERR(host->mux_clk);
snprintf(clk_name, sizeof(clk_name), "%s#div", dev_name(host->dev));
init.name = clk_name;
init.ops = &clk_divider_ops;
init.flags = CLK_SET_RATE_PARENT;
clk_div_parents[0] = __clk_get_name(host->mux_clk);
init.parent_names = clk_div_parents;
init.num_parents = ARRAY_SIZE(clk_div_parents);
host->cfg_div.reg = host->regs + SD_EMMC_CLOCK;
host->cfg_div.shift = __bf_shf(CLK_DIV_MASK);
host->cfg_div.width = __builtin_popcountl(CLK_DIV_MASK);
host->cfg_div.hw.init = &init;
host->cfg_div.flags = CLK_DIVIDER_ONE_BASED |
CLK_DIVIDER_ROUND_CLOSEST | CLK_DIVIDER_ALLOW_ZERO;
host->cfg_div_clk = devm_clk_register(host->dev, &host->cfg_div.hw);
if (WARN_ON(PTR_ERR_OR_ZERO(host->cfg_div_clk)))
return PTR_ERR(host->cfg_div_clk);
clk_reg = 0;
clk_reg |= FIELD_PREP(CLK_CORE_PHASE_MASK, host->tp.core_phase);
clk_reg |= FIELD_PREP(CLK_TX_PHASE_MASK, host->tp.tx_phase);
clk_reg |= FIELD_PREP(CLK_RX_PHASE_MASK, host->tp.rx_phase);
clk_reg |= FIELD_PREP(CLK_SRC_MASK, CLK_SRC_XTAL);
clk_reg |= FIELD_PREP(CLK_DIV_MASK, CLK_DIV_MAX);
clk_reg &= ~CLK_ALWAYS_ON;
writel(clk_reg, host->regs + SD_EMMC_CLOCK);
cfg = readl(host->regs + SD_EMMC_CFG);
cfg &= ~CFG_CLK_ALWAYS_ON;
cfg |= CFG_AUTO_CLK;
writel(cfg, host->regs + SD_EMMC_CFG);
ret = clk_prepare_enable(host->cfg_div_clk);
if (ret)
return ret;
host->mmc->f_min = clk_round_rate(host->cfg_div_clk, 400000);
ret = meson_mmc_clk_set(host, host->mmc->f_min);
if (ret)
clk_disable_unprepare(host->cfg_div_clk);
return ret;
}
static void meson_mmc_set_tuning_params(struct mmc_host *mmc)
{
struct meson_host *host = mmc_priv(mmc);
u32 regval;
regval = readl(host->regs + SD_EMMC_CFG);
regval |= CFG_STOP_CLOCK;
writel(regval, host->regs + SD_EMMC_CFG);
regval = readl(host->regs + SD_EMMC_CLOCK);
regval &= ~CLK_CORE_PHASE_MASK;
regval |= FIELD_PREP(CLK_CORE_PHASE_MASK, host->tp.core_phase);
regval &= ~CLK_TX_PHASE_MASK;
regval |= FIELD_PREP(CLK_TX_PHASE_MASK, host->tp.tx_phase);
regval &= ~CLK_RX_PHASE_MASK;
regval |= FIELD_PREP(CLK_RX_PHASE_MASK, host->tp.rx_phase);
writel(regval, host->regs + SD_EMMC_CLOCK);
regval = readl(host->regs + SD_EMMC_CFG);
regval &= ~CFG_STOP_CLOCK;
writel(regval, host->regs + SD_EMMC_CFG);
}
static void meson_mmc_set_ios(struct mmc_host *mmc, struct mmc_ios *ios)
{
struct meson_host *host = mmc_priv(mmc);
u32 bus_width;
u32 val, orig;
switch (ios->power_mode) {
case MMC_POWER_OFF:
if (!IS_ERR(mmc->supply.vmmc))
mmc_regulator_set_ocr(mmc, mmc->supply.vmmc, 0);
if (!IS_ERR(mmc->supply.vqmmc) && host->vqmmc_enabled) {
regulator_disable(mmc->supply.vqmmc);
host->vqmmc_enabled = false;
}
break;
case MMC_POWER_UP:
if (!IS_ERR(mmc->supply.vmmc))
mmc_regulator_set_ocr(mmc, mmc->supply.vmmc, ios->vdd);
break;
case MMC_POWER_ON:
if (!IS_ERR(mmc->supply.vqmmc) && !host->vqmmc_enabled) {
int ret = regulator_enable(mmc->supply.vqmmc);
if (ret < 0)
dev_err(mmc_dev(mmc),
"failed to enable vqmmc regulator\n");
else
host->vqmmc_enabled = true;
}
break;
}
meson_mmc_clk_set(host, ios->clock);
switch (ios->bus_width) {
case MMC_BUS_WIDTH_1:
bus_width = CFG_BUS_WIDTH_1;
break;
case MMC_BUS_WIDTH_4:
bus_width = CFG_BUS_WIDTH_4;
break;
case MMC_BUS_WIDTH_8:
bus_width = CFG_BUS_WIDTH_8;
break;
default:
dev_err(host->dev, "Invalid ios->bus_width: %u. Setting to 4.\n",
ios->bus_width);
bus_width = CFG_BUS_WIDTH_4;
}
val = readl(host->regs + SD_EMMC_CFG);
orig = val;
val &= ~CFG_BUS_WIDTH_MASK;
val |= FIELD_PREP(CFG_BUS_WIDTH_MASK, bus_width);
val &= ~CFG_DDR;
if (ios->timing == MMC_TIMING_UHS_DDR50 ||
ios->timing == MMC_TIMING_MMC_DDR52 ||
ios->timing == MMC_TIMING_MMC_HS400)
val |= CFG_DDR;
val &= ~CFG_CHK_DS;
if (ios->timing == MMC_TIMING_MMC_HS400)
val |= CFG_CHK_DS;
if (val != orig) {
writel(val, host->regs + SD_EMMC_CFG);
dev_dbg(host->dev, "%s: SD_EMMC_CFG: 0x%08x -> 0x%08x\n",
__func__, orig, val);
}
}
static void meson_mmc_request_done(struct mmc_host *mmc,
struct mmc_request *mrq)
{
struct meson_host *host = mmc_priv(mmc);
host->cmd = NULL;
mmc_request_done(host->mmc, mrq);
}
static void meson_mmc_set_blksz(struct mmc_host *mmc, unsigned int blksz)
{
struct meson_host *host = mmc_priv(mmc);
u32 cfg, blksz_old;
cfg = readl(host->regs + SD_EMMC_CFG);
blksz_old = FIELD_GET(CFG_BLK_LEN_MASK, cfg);
if (!is_power_of_2(blksz))
dev_err(host->dev, "blksz %u is not a power of 2\n", blksz);
blksz = ilog2(blksz);
if (blksz == blksz_old)
return;
dev_dbg(host->dev, "%s: update blk_len %d -> %d\n", __func__,
blksz_old, blksz);
cfg &= ~CFG_BLK_LEN_MASK;
cfg |= FIELD_PREP(CFG_BLK_LEN_MASK, blksz);
writel(cfg, host->regs + SD_EMMC_CFG);
}
static void meson_mmc_set_response_bits(struct mmc_command *cmd, u32 *cmd_cfg)
{
if (cmd->flags & MMC_RSP_PRESENT) {
if (cmd->flags & MMC_RSP_136)
*cmd_cfg |= CMD_CFG_RESP_128;
*cmd_cfg |= CMD_CFG_RESP_NUM;
if (!(cmd->flags & MMC_RSP_CRC))
*cmd_cfg |= CMD_CFG_RESP_NOCRC;
if (cmd->flags & MMC_RSP_BUSY)
*cmd_cfg |= CMD_CFG_R1B;
} else {
*cmd_cfg |= CMD_CFG_NO_RESP;
}
}
static void meson_mmc_desc_chain_transfer(struct mmc_host *mmc, u32 cmd_cfg)
{
struct meson_host *host = mmc_priv(mmc);
struct sd_emmc_desc *desc = host->descs;
struct mmc_data *data = host->cmd->data;
struct scatterlist *sg;
u32 start;
int i;
if (data->flags & MMC_DATA_WRITE)
cmd_cfg |= CMD_CFG_DATA_WR;
if (data->blocks > 1) {
cmd_cfg |= CMD_CFG_BLOCK_MODE;
meson_mmc_set_blksz(mmc, data->blksz);
}
for_each_sg(data->sg, sg, data->sg_count, i) {
unsigned int len = sg_dma_len(sg);
if (data->blocks > 1)
len /= data->blksz;
desc[i].cmd_cfg = cmd_cfg;
desc[i].cmd_cfg |= FIELD_PREP(CMD_CFG_LENGTH_MASK, len);
if (i > 0)
desc[i].cmd_cfg |= CMD_CFG_NO_CMD;
desc[i].cmd_arg = host->cmd->arg;
desc[i].cmd_resp = 0;
desc[i].cmd_data = sg_dma_address(sg);
}
desc[data->sg_count - 1].cmd_cfg |= CMD_CFG_END_OF_CHAIN;
dma_wmb();
start = host->descs_dma_addr | START_DESC_BUSY;
writel(start, host->regs + SD_EMMC_START);
}
static void meson_mmc_start_cmd(struct mmc_host *mmc, struct mmc_command *cmd)
{
struct meson_host *host = mmc_priv(mmc);
struct mmc_data *data = cmd->data;
u32 cmd_cfg = 0, cmd_data = 0;
unsigned int xfer_bytes = 0;
dma_rmb();
host->cmd = cmd;
cmd_cfg |= FIELD_PREP(CMD_CFG_CMD_INDEX_MASK, cmd->opcode);
cmd_cfg |= CMD_CFG_OWNER;
meson_mmc_set_response_bits(cmd, &cmd_cfg);
if (data) {
data->bytes_xfered = 0;
cmd_cfg |= CMD_CFG_DATA_IO;
cmd_cfg |= FIELD_PREP(CMD_CFG_TIMEOUT_MASK,
ilog2(meson_mmc_get_timeout_msecs(data)));
if (meson_mmc_desc_chain_mode(data)) {
meson_mmc_desc_chain_transfer(mmc, cmd_cfg);
return;
}
if (data->blocks > 1) {
cmd_cfg |= CMD_CFG_BLOCK_MODE;
cmd_cfg |= FIELD_PREP(CMD_CFG_LENGTH_MASK,
data->blocks);
meson_mmc_set_blksz(mmc, data->blksz);
} else {
cmd_cfg |= FIELD_PREP(CMD_CFG_LENGTH_MASK, data->blksz);
}
xfer_bytes = data->blksz * data->blocks;
if (data->flags & MMC_DATA_WRITE) {
cmd_cfg |= CMD_CFG_DATA_WR;
WARN_ON(xfer_bytes > host->bounce_buf_size);
sg_copy_to_buffer(data->sg, data->sg_len,
host->bounce_buf, xfer_bytes);
dma_wmb();
}
cmd_data = host->bounce_dma_addr & CMD_DATA_MASK;
} else {
cmd_cfg |= FIELD_PREP(CMD_CFG_TIMEOUT_MASK,
ilog2(SD_EMMC_CMD_TIMEOUT));
}
cmd_cfg |= CMD_CFG_END_OF_CHAIN;
writel(cmd_cfg, host->regs + SD_EMMC_CMD_CFG);
writel(cmd_data, host->regs + SD_EMMC_CMD_DAT);
writel(0, host->regs + SD_EMMC_CMD_RSP);
wmb();
writel(cmd->arg, host->regs + SD_EMMC_CMD_ARG);
}
static void meson_mmc_request(struct mmc_host *mmc, struct mmc_request *mrq)
{
struct meson_host *host = mmc_priv(mmc);
bool needs_pre_post_req = mrq->data &&
!(mrq->data->host_cookie & SD_EMMC_PRE_REQ_DONE);
if (needs_pre_post_req) {
meson_mmc_get_transfer_mode(mmc, mrq);
if (!meson_mmc_desc_chain_mode(mrq->data))
needs_pre_post_req = false;
}
if (needs_pre_post_req)
meson_mmc_pre_req(mmc, mrq);
writel(0, host->regs + SD_EMMC_START);
meson_mmc_start_cmd(mmc, mrq->sbc ?: mrq->cmd);
if (needs_pre_post_req)
meson_mmc_post_req(mmc, mrq, 0);
}
static void meson_mmc_read_resp(struct mmc_host *mmc, struct mmc_command *cmd)
{
struct meson_host *host = mmc_priv(mmc);
if (cmd->flags & MMC_RSP_136) {
cmd->resp[0] = readl(host->regs + SD_EMMC_CMD_RSP3);
cmd->resp[1] = readl(host->regs + SD_EMMC_CMD_RSP2);
cmd->resp[2] = readl(host->regs + SD_EMMC_CMD_RSP1);
cmd->resp[3] = readl(host->regs + SD_EMMC_CMD_RSP);
} else if (cmd->flags & MMC_RSP_PRESENT) {
cmd->resp[0] = readl(host->regs + SD_EMMC_CMD_RSP);
}
}
static irqreturn_t meson_mmc_irq(int irq, void *dev_id)
{
struct meson_host *host = dev_id;
struct mmc_command *cmd;
struct mmc_data *data;
u32 irq_en, status, raw_status;
irqreturn_t ret = IRQ_HANDLED;
if (WARN_ON(!host))
return IRQ_NONE;
cmd = host->cmd;
if (WARN_ON(!cmd))
return IRQ_NONE;
data = cmd->data;
spin_lock(&host->lock);
irq_en = readl(host->regs + SD_EMMC_IRQ_EN);
raw_status = readl(host->regs + SD_EMMC_STATUS);
status = raw_status & irq_en;
if (!status) {
dev_warn(host->dev, "Spurious IRQ! status=0x%08x, irq_en=0x%08x\n",
raw_status, irq_en);
ret = IRQ_NONE;
goto out;
}
meson_mmc_read_resp(host->mmc, cmd);
cmd->error = 0;
if (status & IRQ_RXD_ERR_MASK) {
dev_dbg(host->dev, "Unhandled IRQ: RXD error\n");
cmd->error = -EILSEQ;
}
if (status & IRQ_TXD_ERR) {
dev_dbg(host->dev, "Unhandled IRQ: TXD error\n");
cmd->error = -EILSEQ;
}
if (status & IRQ_DESC_ERR)
dev_dbg(host->dev, "Unhandled IRQ: Descriptor error\n");
if (status & IRQ_RESP_ERR) {
dev_dbg(host->dev, "Unhandled IRQ: Response error\n");
cmd->error = -EILSEQ;
}
if (status & IRQ_RESP_TIMEOUT) {
dev_dbg(host->dev, "Unhandled IRQ: Response timeout\n");
cmd->error = -ETIMEDOUT;
}
if (status & IRQ_DESC_TIMEOUT) {
dev_dbg(host->dev, "Unhandled IRQ: Descriptor timeout\n");
cmd->error = -ETIMEDOUT;
}
if (status & IRQ_SDIO)
dev_dbg(host->dev, "Unhandled IRQ: SDIO.\n");
if (status & (IRQ_END_OF_CHAIN | IRQ_RESP_STATUS)) {
if (data && !cmd->error)
data->bytes_xfered = data->blksz * data->blocks;
if (meson_mmc_bounce_buf_read(data) ||
meson_mmc_get_next_command(cmd))
ret = IRQ_WAKE_THREAD;
} else {
dev_warn(host->dev, "Unknown IRQ! status=0x%04x: MMC CMD%u arg=0x%08x flags=0x%08x stop=%d\n",
status, cmd->opcode, cmd->arg,
cmd->flags, cmd->mrq->stop ? 1 : 0);
if (cmd->data) {
struct mmc_data *data = cmd->data;
dev_warn(host->dev, "\tblksz %u blocks %u flags 0x%08x (%s%s)",
data->blksz, data->blocks, data->flags,
data->flags & MMC_DATA_WRITE ? "write" : "",
data->flags & MMC_DATA_READ ? "read" : "");
}
}
out:
writel(status, host->regs + SD_EMMC_STATUS);
if (ret == IRQ_HANDLED)
meson_mmc_request_done(host->mmc, cmd->mrq);
spin_unlock(&host->lock);
return ret;
}
static irqreturn_t meson_mmc_irq_thread(int irq, void *dev_id)
{
struct meson_host *host = dev_id;
struct mmc_command *next_cmd, *cmd = host->cmd;
struct mmc_data *data;
unsigned int xfer_bytes;
if (WARN_ON(!cmd))
return IRQ_NONE;
data = cmd->data;
if (meson_mmc_bounce_buf_read(data)) {
xfer_bytes = data->blksz * data->blocks;
WARN_ON(xfer_bytes > host->bounce_buf_size);
sg_copy_from_buffer(data->sg, data->sg_len,
host->bounce_buf, xfer_bytes);
}
next_cmd = meson_mmc_get_next_command(cmd);
if (next_cmd)
meson_mmc_start_cmd(host->mmc, next_cmd);
else
meson_mmc_request_done(host->mmc, cmd->mrq);
return IRQ_HANDLED;
}
static int meson_mmc_execute_tuning(struct mmc_host *mmc, u32 opcode)
{
struct meson_host *host = mmc_priv(mmc);
struct meson_tuning_params tp_old = host->tp;
int ret = -EINVAL, i, cmd_error;
dev_info(mmc_dev(mmc), "(re)tuning...\n");
for (i = CLK_PHASE_0; i <= CLK_PHASE_270; i++) {
host->tp.rx_phase = i;
if (!memcmp(&tp_old, &host->tp, sizeof(tp_old)) &&
mmc->doing_retune)
continue;
meson_mmc_set_tuning_params(mmc);
ret = mmc_send_tuning(mmc, opcode, &cmd_error);
if (!ret)
break;
}
return ret;
}
static int meson_mmc_get_cd(struct mmc_host *mmc)
{
int status = mmc_gpio_get_cd(mmc);
if (status == -ENOSYS)
return 1;
return status;
}
static void meson_mmc_cfg_init(struct meson_host *host)
{
u32 cfg = 0;
cfg |= FIELD_PREP(CFG_RESP_TIMEOUT_MASK,
ilog2(SD_EMMC_CFG_RESP_TIMEOUT));
cfg |= FIELD_PREP(CFG_RC_CC_MASK, ilog2(SD_EMMC_CFG_CMD_GAP));
cfg |= FIELD_PREP(CFG_BLK_LEN_MASK, ilog2(SD_EMMC_CFG_BLK_SIZE));
writel(cfg, host->regs + SD_EMMC_CFG);
}
static int meson_mmc_probe(struct platform_device *pdev)
{
struct resource *res;
struct meson_host *host;
struct mmc_host *mmc;
int ret, irq;
mmc = mmc_alloc_host(sizeof(struct meson_host), &pdev->dev);
if (!mmc)
return -ENOMEM;
host = mmc_priv(mmc);
host->mmc = mmc;
host->dev = &pdev->dev;
dev_set_drvdata(&pdev->dev, host);
spin_lock_init(&host->lock);
host->vqmmc_enabled = false;
ret = mmc_regulator_get_supply(mmc);
if (ret == -EPROBE_DEFER)
goto free_host;
ret = mmc_of_parse(mmc);
if (ret) {
if (ret != -EPROBE_DEFER)
dev_warn(&pdev->dev, "error parsing DT: %d\n", ret);
goto free_host;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
host->regs = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(host->regs)) {
ret = PTR_ERR(host->regs);
goto free_host;
}
irq = platform_get_irq(pdev, 0);
if (!irq) {
dev_err(&pdev->dev, "failed to get interrupt resource.\n");
ret = -EINVAL;
goto free_host;
}
host->core_clk = devm_clk_get(&pdev->dev, "core");
if (IS_ERR(host->core_clk)) {
ret = PTR_ERR(host->core_clk);
goto free_host;
}
ret = clk_prepare_enable(host->core_clk);
if (ret)
goto free_host;
host->tp.core_phase = CLK_PHASE_180;
host->tp.tx_phase = CLK_PHASE_0;
host->tp.rx_phase = CLK_PHASE_0;
ret = meson_mmc_clk_init(host);
if (ret)
goto err_core_clk;
writel(0, host->regs + SD_EMMC_START);
writel(0, host->regs + SD_EMMC_IRQ_EN);
writel(IRQ_EN_MASK, host->regs + SD_EMMC_STATUS);
writel(IRQ_EN_MASK, host->regs + SD_EMMC_IRQ_EN);
meson_mmc_cfg_init(host);
ret = devm_request_threaded_irq(&pdev->dev, irq, meson_mmc_irq,
meson_mmc_irq_thread, IRQF_SHARED,
NULL, host);
if (ret)
goto err_div_clk;
mmc->caps |= MMC_CAP_CMD23;
mmc->max_blk_count = CMD_CFG_LENGTH_MASK;
mmc->max_req_size = mmc->max_blk_count * mmc->max_blk_size;
mmc->max_segs = SD_EMMC_DESC_BUF_LEN / sizeof(struct sd_emmc_desc);
mmc->max_seg_size = mmc->max_req_size;
host->bounce_buf_size = mmc->max_req_size;
host->bounce_buf =
dma_alloc_coherent(host->dev, host->bounce_buf_size,
&host->bounce_dma_addr, GFP_KERNEL);
if (host->bounce_buf == NULL) {
dev_err(host->dev, "Unable to map allocate DMA bounce buffer.\n");
ret = -ENOMEM;
goto err_div_clk;
}
host->descs = dma_alloc_coherent(host->dev, SD_EMMC_DESC_BUF_LEN,
&host->descs_dma_addr, GFP_KERNEL);
if (!host->descs) {
dev_err(host->dev, "Allocating descriptor DMA buffer failed\n");
ret = -ENOMEM;
goto err_bounce_buf;
}
mmc->ops = &meson_mmc_ops;
mmc_add_host(mmc);
return 0;
err_bounce_buf:
dma_free_coherent(host->dev, host->bounce_buf_size,
host->bounce_buf, host->bounce_dma_addr);
err_div_clk:
clk_disable_unprepare(host->cfg_div_clk);
err_core_clk:
clk_disable_unprepare(host->core_clk);
free_host:
mmc_free_host(mmc);
return ret;
}
static int meson_mmc_remove(struct platform_device *pdev)
{
struct meson_host *host = dev_get_drvdata(&pdev->dev);
mmc_remove_host(host->mmc);
writel(0, host->regs + SD_EMMC_IRQ_EN);
dma_free_coherent(host->dev, SD_EMMC_DESC_BUF_LEN,
host->descs, host->descs_dma_addr);
dma_free_coherent(host->dev, host->bounce_buf_size,
host->bounce_buf, host->bounce_dma_addr);
clk_disable_unprepare(host->cfg_div_clk);
clk_disable_unprepare(host->core_clk);
mmc_free_host(host->mmc);
return 0;
}
