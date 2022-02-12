static int sunxi_mmc_reset_host(struct sunxi_mmc_host *host)
{
unsigned long expire = jiffies + msecs_to_jiffies(250);
u32 rval;
mmc_writel(host, REG_GCTRL, SDXC_HARDWARE_RESET);
do {
rval = mmc_readl(host, REG_GCTRL);
} while (time_before(jiffies, expire) && (rval & SDXC_HARDWARE_RESET));
if (rval & SDXC_HARDWARE_RESET) {
dev_err(mmc_dev(host->mmc), "fatal err reset timeout\n");
return -EIO;
}
return 0;
}
static int sunxi_mmc_init_host(struct mmc_host *mmc)
{
u32 rval;
struct sunxi_mmc_host *host = mmc_priv(mmc);
if (sunxi_mmc_reset_host(host))
return -EIO;
mmc_writel(host, REG_FTRGL, 0x20070008);
mmc_writel(host, REG_TMOUT, 0xffffffff);
mmc_writel(host, REG_IMASK, host->sdio_imask);
mmc_writel(host, REG_RINTR, 0xffffffff);
mmc_writel(host, REG_DBGC, 0xdeb);
mmc_writel(host, REG_FUNS, SDXC_CEATA_ON);
mmc_writel(host, REG_DLBA, host->sg_dma);
rval = mmc_readl(host, REG_GCTRL);
rval |= SDXC_INTERRUPT_ENABLE_BIT;
rval &= ~SDXC_ACCESS_DONE_DIRECT;
mmc_writel(host, REG_GCTRL, rval);
return 0;
}
static void sunxi_mmc_init_idma_des(struct sunxi_mmc_host *host,
struct mmc_data *data)
{
struct sunxi_idma_des *pdes = (struct sunxi_idma_des *)host->sg_cpu;
dma_addr_t next_desc = host->sg_dma;
int i, max_len = (1 << host->idma_des_size_bits);
for (i = 0; i < data->sg_len; i++) {
pdes[i].config = SDXC_IDMAC_DES0_CH | SDXC_IDMAC_DES0_OWN |
SDXC_IDMAC_DES0_DIC;
if (data->sg[i].length == max_len)
pdes[i].buf_size = 0;
else
pdes[i].buf_size = data->sg[i].length;
next_desc += sizeof(struct sunxi_idma_des);
pdes[i].buf_addr_ptr1 = sg_dma_address(&data->sg[i]);
pdes[i].buf_addr_ptr2 = (u32)next_desc;
}
pdes[0].config |= SDXC_IDMAC_DES0_FD;
pdes[i - 1].config |= SDXC_IDMAC_DES0_LD | SDXC_IDMAC_DES0_ER;
pdes[i - 1].config &= ~SDXC_IDMAC_DES0_DIC;
pdes[i - 1].buf_addr_ptr2 = 0;
wmb();
}
static enum dma_data_direction sunxi_mmc_get_dma_dir(struct mmc_data *data)
{
if (data->flags & MMC_DATA_WRITE)
return DMA_TO_DEVICE;
else
return DMA_FROM_DEVICE;
}
static int sunxi_mmc_map_dma(struct sunxi_mmc_host *host,
struct mmc_data *data)
{
u32 i, dma_len;
struct scatterlist *sg;
dma_len = dma_map_sg(mmc_dev(host->mmc), data->sg, data->sg_len,
sunxi_mmc_get_dma_dir(data));
if (dma_len == 0) {
dev_err(mmc_dev(host->mmc), "dma_map_sg failed\n");
return -ENOMEM;
}
for_each_sg(data->sg, sg, data->sg_len, i) {
if (sg->offset & 3 || sg->length & 3) {
dev_err(mmc_dev(host->mmc),
"unaligned scatterlist: os %x length %d\n",
sg->offset, sg->length);
return -EINVAL;
}
}
return 0;
}
static void sunxi_mmc_start_dma(struct sunxi_mmc_host *host,
struct mmc_data *data)
{
u32 rval;
sunxi_mmc_init_idma_des(host, data);
rval = mmc_readl(host, REG_GCTRL);
rval |= SDXC_DMA_ENABLE_BIT;
mmc_writel(host, REG_GCTRL, rval);
rval |= SDXC_DMA_RESET;
mmc_writel(host, REG_GCTRL, rval);
mmc_writel(host, REG_DMAC, SDXC_IDMAC_SOFT_RESET);
if (!(data->flags & MMC_DATA_WRITE))
mmc_writel(host, REG_IDIE, SDXC_IDMAC_RECEIVE_INTERRUPT);
mmc_writel(host, REG_DMAC,
SDXC_IDMAC_FIX_BURST | SDXC_IDMAC_IDMA_ON);
}
static void sunxi_mmc_send_manual_stop(struct sunxi_mmc_host *host,
struct mmc_request *req)
{
u32 arg, cmd_val, ri;
unsigned long expire = jiffies + msecs_to_jiffies(1000);
cmd_val = SDXC_START | SDXC_RESP_EXPIRE |
SDXC_STOP_ABORT_CMD | SDXC_CHECK_RESPONSE_CRC;
if (req->cmd->opcode == SD_IO_RW_EXTENDED) {
cmd_val |= SD_IO_RW_DIRECT;
arg = (1 << 31) | (0 << 28) | (SDIO_CCCR_ABORT << 9) |
((req->cmd->arg >> 28) & 0x7);
} else {
cmd_val |= MMC_STOP_TRANSMISSION;
arg = 0;
}
mmc_writel(host, REG_CARG, arg);
mmc_writel(host, REG_CMDR, cmd_val);
do {
ri = mmc_readl(host, REG_RINTR);
} while (!(ri & (SDXC_COMMAND_DONE | SDXC_INTERRUPT_ERROR_BIT)) &&
time_before(jiffies, expire));
if (!(ri & SDXC_COMMAND_DONE) || (ri & SDXC_INTERRUPT_ERROR_BIT)) {
dev_err(mmc_dev(host->mmc), "send stop command failed\n");
if (req->stop)
req->stop->resp[0] = -ETIMEDOUT;
} else {
if (req->stop)
req->stop->resp[0] = mmc_readl(host, REG_RESP0);
}
mmc_writel(host, REG_RINTR, 0xffff);
}
static void sunxi_mmc_dump_errinfo(struct sunxi_mmc_host *host)
{
struct mmc_command *cmd = host->mrq->cmd;
struct mmc_data *data = host->mrq->data;
if ((host->int_sum & SDXC_INTERRUPT_ERROR_BIT) ==
SDXC_RESP_TIMEOUT && (cmd->opcode == SD_IO_SEND_OP_COND ||
cmd->opcode == SD_IO_RW_DIRECT))
return;
dev_err(mmc_dev(host->mmc),
"smc %d err, cmd %d,%s%s%s%s%s%s%s%s%s%s !!\n",
host->mmc->index, cmd->opcode,
data ? (data->flags & MMC_DATA_WRITE ? " WR" : " RD") : "",
host->int_sum & SDXC_RESP_ERROR ? " RE" : "",
host->int_sum & SDXC_RESP_CRC_ERROR ? " RCE" : "",
host->int_sum & SDXC_DATA_CRC_ERROR ? " DCE" : "",
host->int_sum & SDXC_RESP_TIMEOUT ? " RTO" : "",
host->int_sum & SDXC_DATA_TIMEOUT ? " DTO" : "",
host->int_sum & SDXC_FIFO_RUN_ERROR ? " FE" : "",
host->int_sum & SDXC_HARD_WARE_LOCKED ? " HL" : "",
host->int_sum & SDXC_START_BIT_ERROR ? " SBE" : "",
host->int_sum & SDXC_END_BIT_ERROR ? " EBE" : ""
);
}
static irqreturn_t sunxi_mmc_finalize_request(struct sunxi_mmc_host *host)
{
struct mmc_request *mrq = host->mrq;
struct mmc_data *data = mrq->data;
u32 rval;
mmc_writel(host, REG_IMASK, host->sdio_imask);
mmc_writel(host, REG_IDIE, 0);
if (host->int_sum & SDXC_INTERRUPT_ERROR_BIT) {
sunxi_mmc_dump_errinfo(host);
mrq->cmd->error = -ETIMEDOUT;
if (data) {
data->error = -ETIMEDOUT;
host->manual_stop_mrq = mrq;
}
if (mrq->stop)
mrq->stop->error = -ETIMEDOUT;
} else {
if (mrq->cmd->flags & MMC_RSP_136) {
mrq->cmd->resp[0] = mmc_readl(host, REG_RESP3);
mrq->cmd->resp[1] = mmc_readl(host, REG_RESP2);
mrq->cmd->resp[2] = mmc_readl(host, REG_RESP1);
mrq->cmd->resp[3] = mmc_readl(host, REG_RESP0);
} else {
mrq->cmd->resp[0] = mmc_readl(host, REG_RESP0);
}
if (data)
data->bytes_xfered = data->blocks * data->blksz;
}
if (data) {
mmc_writel(host, REG_IDST, 0x337);
mmc_writel(host, REG_DMAC, 0);
rval = mmc_readl(host, REG_GCTRL);
rval |= SDXC_DMA_RESET;
mmc_writel(host, REG_GCTRL, rval);
rval &= ~SDXC_DMA_ENABLE_BIT;
mmc_writel(host, REG_GCTRL, rval);
rval |= SDXC_FIFO_RESET;
mmc_writel(host, REG_GCTRL, rval);
dma_unmap_sg(mmc_dev(host->mmc), data->sg, data->sg_len,
sunxi_mmc_get_dma_dir(data));
}
mmc_writel(host, REG_RINTR, 0xffff);
host->mrq = NULL;
host->int_sum = 0;
host->wait_dma = false;
return host->manual_stop_mrq ? IRQ_WAKE_THREAD : IRQ_HANDLED;
}
static irqreturn_t sunxi_mmc_irq(int irq, void *dev_id)
{
struct sunxi_mmc_host *host = dev_id;
struct mmc_request *mrq;
u32 msk_int, idma_int;
bool finalize = false;
bool sdio_int = false;
irqreturn_t ret = IRQ_HANDLED;
spin_lock(&host->lock);
idma_int = mmc_readl(host, REG_IDST);
msk_int = mmc_readl(host, REG_MISTA);
dev_dbg(mmc_dev(host->mmc), "irq: rq %p mi %08x idi %08x\n",
host->mrq, msk_int, idma_int);
mrq = host->mrq;
if (mrq) {
if (idma_int & SDXC_IDMAC_RECEIVE_INTERRUPT)
host->wait_dma = false;
host->int_sum |= msk_int;
if ((host->int_sum & SDXC_RESP_TIMEOUT) &&
!(host->int_sum & SDXC_COMMAND_DONE))
mmc_writel(host, REG_IMASK,
host->sdio_imask | SDXC_COMMAND_DONE);
else if (host->int_sum & SDXC_INTERRUPT_ERROR_BIT)
finalize = true;
else if ((host->int_sum & SDXC_INTERRUPT_DONE_BIT) &&
!host->wait_dma)
finalize = true;
}
if (msk_int & SDXC_SDIO_INTERRUPT)
sdio_int = true;
mmc_writel(host, REG_RINTR, msk_int);
mmc_writel(host, REG_IDST, idma_int);
if (finalize)
ret = sunxi_mmc_finalize_request(host);
spin_unlock(&host->lock);
if (finalize && ret == IRQ_HANDLED)
mmc_request_done(host->mmc, mrq);
if (sdio_int)
mmc_signal_sdio_irq(host->mmc);
return ret;
}
static irqreturn_t sunxi_mmc_handle_manual_stop(int irq, void *dev_id)
{
struct sunxi_mmc_host *host = dev_id;
struct mmc_request *mrq;
unsigned long iflags;
spin_lock_irqsave(&host->lock, iflags);
mrq = host->manual_stop_mrq;
spin_unlock_irqrestore(&host->lock, iflags);
if (!mrq) {
dev_err(mmc_dev(host->mmc), "no request for manual stop\n");
return IRQ_HANDLED;
}
dev_err(mmc_dev(host->mmc), "data error, sending stop command\n");
sunxi_mmc_send_manual_stop(host, mrq);
spin_lock_irqsave(&host->lock, iflags);
host->manual_stop_mrq = NULL;
spin_unlock_irqrestore(&host->lock, iflags);
mmc_request_done(host->mmc, mrq);
return IRQ_HANDLED;
}
static int sunxi_mmc_oclk_onoff(struct sunxi_mmc_host *host, u32 oclk_en)
{
unsigned long expire = jiffies + msecs_to_jiffies(250);
u32 rval;
rval = mmc_readl(host, REG_CLKCR);
rval &= ~(SDXC_CARD_CLOCK_ON | SDXC_LOW_POWER_ON);
if (oclk_en)
rval |= SDXC_CARD_CLOCK_ON;
mmc_writel(host, REG_CLKCR, rval);
rval = SDXC_START | SDXC_UPCLK_ONLY | SDXC_WAIT_PRE_OVER;
mmc_writel(host, REG_CMDR, rval);
do {
rval = mmc_readl(host, REG_CMDR);
} while (time_before(jiffies, expire) && (rval & SDXC_START));
mmc_writel(host, REG_RINTR,
mmc_readl(host, REG_RINTR) & ~SDXC_SDIO_INTERRUPT);
if (rval & SDXC_START) {
dev_err(mmc_dev(host->mmc), "fatal err update clk timeout\n");
return -EIO;
}
return 0;
}
static int sunxi_mmc_clk_set_rate(struct sunxi_mmc_host *host,
struct mmc_ios *ios)
{
u32 rate, oclk_dly, rval, sclk_dly;
int ret;
rate = clk_round_rate(host->clk_mmc, ios->clock);
dev_dbg(mmc_dev(host->mmc), "setting clk to %d, rounded %d\n",
ios->clock, rate);
ret = clk_set_rate(host->clk_mmc, rate);
if (ret) {
dev_err(mmc_dev(host->mmc), "error setting clk to %d: %d\n",
rate, ret);
return ret;
}
ret = sunxi_mmc_oclk_onoff(host, 0);
if (ret)
return ret;
rval = mmc_readl(host, REG_CLKCR);
rval &= ~0xff;
mmc_writel(host, REG_CLKCR, rval);
if (rate <= 400000) {
oclk_dly = 180;
sclk_dly = 42;
} else if (rate <= 25000000) {
oclk_dly = 180;
sclk_dly = 75;
} else if (rate <= 50000000) {
if (ios->timing == MMC_TIMING_UHS_DDR50) {
oclk_dly = 60;
sclk_dly = 120;
} else {
oclk_dly = 90;
sclk_dly = 150;
}
} else if (rate <= 100000000) {
oclk_dly = 6;
sclk_dly = 24;
} else if (rate <= 200000000) {
oclk_dly = 3;
sclk_dly = 12;
} else {
return -EINVAL;
}
clk_set_phase(host->clk_sample, sclk_dly);
clk_set_phase(host->clk_output, oclk_dly);
return sunxi_mmc_oclk_onoff(host, 1);
}
static void sunxi_mmc_set_ios(struct mmc_host *mmc, struct mmc_ios *ios)
{
struct sunxi_mmc_host *host = mmc_priv(mmc);
u32 rval;
switch (ios->power_mode) {
case MMC_POWER_ON:
break;
case MMC_POWER_UP:
mmc_regulator_set_ocr(mmc, mmc->supply.vmmc, ios->vdd);
host->ferror = sunxi_mmc_init_host(mmc);
if (host->ferror)
return;
dev_dbg(mmc_dev(mmc), "power on!\n");
break;
case MMC_POWER_OFF:
dev_dbg(mmc_dev(mmc), "power off!\n");
sunxi_mmc_reset_host(host);
mmc_regulator_set_ocr(mmc, mmc->supply.vmmc, 0);
break;
}
switch (ios->bus_width) {
case MMC_BUS_WIDTH_1:
mmc_writel(host, REG_WIDTH, SDXC_WIDTH1);
break;
case MMC_BUS_WIDTH_4:
mmc_writel(host, REG_WIDTH, SDXC_WIDTH4);
break;
case MMC_BUS_WIDTH_8:
mmc_writel(host, REG_WIDTH, SDXC_WIDTH8);
break;
}
rval = mmc_readl(host, REG_GCTRL);
if (ios->timing == MMC_TIMING_UHS_DDR50)
rval |= SDXC_DDR_MODE;
else
rval &= ~SDXC_DDR_MODE;
mmc_writel(host, REG_GCTRL, rval);
if (ios->clock && ios->power_mode) {
host->ferror = sunxi_mmc_clk_set_rate(host, ios);
}
}
static void sunxi_mmc_enable_sdio_irq(struct mmc_host *mmc, int enable)
{
struct sunxi_mmc_host *host = mmc_priv(mmc);
unsigned long flags;
u32 imask;
spin_lock_irqsave(&host->lock, flags);
imask = mmc_readl(host, REG_IMASK);
if (enable) {
host->sdio_imask = SDXC_SDIO_INTERRUPT;
imask |= SDXC_SDIO_INTERRUPT;
} else {
host->sdio_imask = 0;
imask &= ~SDXC_SDIO_INTERRUPT;
}
mmc_writel(host, REG_IMASK, imask);
spin_unlock_irqrestore(&host->lock, flags);
}
static void sunxi_mmc_hw_reset(struct mmc_host *mmc)
{
struct sunxi_mmc_host *host = mmc_priv(mmc);
mmc_writel(host, REG_HWRST, 0);
udelay(10);
mmc_writel(host, REG_HWRST, 1);
udelay(300);
}
static void sunxi_mmc_request(struct mmc_host *mmc, struct mmc_request *mrq)
{
struct sunxi_mmc_host *host = mmc_priv(mmc);
struct mmc_command *cmd = mrq->cmd;
struct mmc_data *data = mrq->data;
unsigned long iflags;
u32 imask = SDXC_INTERRUPT_ERROR_BIT;
u32 cmd_val = SDXC_START | (cmd->opcode & 0x3f);
bool wait_dma = host->wait_dma;
int ret;
if (host->ferror) {
mrq->cmd->error = host->ferror;
mmc_request_done(mmc, mrq);
return;
}
if (data) {
ret = sunxi_mmc_map_dma(host, data);
if (ret < 0) {
dev_err(mmc_dev(mmc), "map DMA failed\n");
cmd->error = ret;
data->error = ret;
mmc_request_done(mmc, mrq);
return;
}
}
if (cmd->opcode == MMC_GO_IDLE_STATE) {
cmd_val |= SDXC_SEND_INIT_SEQUENCE;
imask |= SDXC_COMMAND_DONE;
}
if (cmd->flags & MMC_RSP_PRESENT) {
cmd_val |= SDXC_RESP_EXPIRE;
if (cmd->flags & MMC_RSP_136)
cmd_val |= SDXC_LONG_RESPONSE;
if (cmd->flags & MMC_RSP_CRC)
cmd_val |= SDXC_CHECK_RESPONSE_CRC;
if ((cmd->flags & MMC_CMD_MASK) == MMC_CMD_ADTC) {
cmd_val |= SDXC_DATA_EXPIRE | SDXC_WAIT_PRE_OVER;
if (cmd->data->flags & MMC_DATA_STREAM) {
imask |= SDXC_AUTO_COMMAND_DONE;
cmd_val |= SDXC_SEQUENCE_MODE |
SDXC_SEND_AUTO_STOP;
}
if (cmd->data->stop) {
imask |= SDXC_AUTO_COMMAND_DONE;
cmd_val |= SDXC_SEND_AUTO_STOP;
} else {
imask |= SDXC_DATA_OVER;
}
if (cmd->data->flags & MMC_DATA_WRITE)
cmd_val |= SDXC_WRITE;
else
wait_dma = true;
} else {
imask |= SDXC_COMMAND_DONE;
}
} else {
imask |= SDXC_COMMAND_DONE;
}
dev_dbg(mmc_dev(mmc), "cmd %d(%08x) arg %x ie 0x%08x len %d\n",
cmd_val & 0x3f, cmd_val, cmd->arg, imask,
mrq->data ? mrq->data->blksz * mrq->data->blocks : 0);
spin_lock_irqsave(&host->lock, iflags);
if (host->mrq || host->manual_stop_mrq) {
spin_unlock_irqrestore(&host->lock, iflags);
if (data)
dma_unmap_sg(mmc_dev(mmc), data->sg, data->sg_len,
sunxi_mmc_get_dma_dir(data));
dev_err(mmc_dev(mmc), "request already pending\n");
mrq->cmd->error = -EBUSY;
mmc_request_done(mmc, mrq);
return;
}
if (data) {
mmc_writel(host, REG_BLKSZ, data->blksz);
mmc_writel(host, REG_BCNTR, data->blksz * data->blocks);
sunxi_mmc_start_dma(host, data);
}
host->mrq = mrq;
host->wait_dma = wait_dma;
mmc_writel(host, REG_IMASK, host->sdio_imask | imask);
mmc_writel(host, REG_CARG, cmd->arg);
mmc_writel(host, REG_CMDR, cmd_val);
spin_unlock_irqrestore(&host->lock, iflags);
}
static int sunxi_mmc_resource_request(struct sunxi_mmc_host *host,
struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
int ret;
if (of_device_is_compatible(np, "allwinner,sun4i-a10-mmc"))
host->idma_des_size_bits = 13;
else
host->idma_des_size_bits = 16;
ret = mmc_regulator_get_supply(host->mmc);
if (ret) {
if (ret != -EPROBE_DEFER)
dev_err(&pdev->dev, "Could not get vmmc supply\n");
return ret;
}
host->reg_base = devm_ioremap_resource(&pdev->dev,
platform_get_resource(pdev, IORESOURCE_MEM, 0));
if (IS_ERR(host->reg_base))
return PTR_ERR(host->reg_base);
host->clk_ahb = devm_clk_get(&pdev->dev, "ahb");
if (IS_ERR(host->clk_ahb)) {
dev_err(&pdev->dev, "Could not get ahb clock\n");
return PTR_ERR(host->clk_ahb);
}
host->clk_mmc = devm_clk_get(&pdev->dev, "mmc");
if (IS_ERR(host->clk_mmc)) {
dev_err(&pdev->dev, "Could not get mmc clock\n");
return PTR_ERR(host->clk_mmc);
}
host->clk_output = devm_clk_get(&pdev->dev, "output");
if (IS_ERR(host->clk_output)) {
dev_err(&pdev->dev, "Could not get output clock\n");
return PTR_ERR(host->clk_output);
}
host->clk_sample = devm_clk_get(&pdev->dev, "sample");
if (IS_ERR(host->clk_sample)) {
dev_err(&pdev->dev, "Could not get sample clock\n");
return PTR_ERR(host->clk_sample);
}
host->reset = devm_reset_control_get_optional(&pdev->dev, "ahb");
if (PTR_ERR(host->reset) == -EPROBE_DEFER)
return PTR_ERR(host->reset);
ret = clk_prepare_enable(host->clk_ahb);
if (ret) {
dev_err(&pdev->dev, "Enable ahb clk err %d\n", ret);
return ret;
}
ret = clk_prepare_enable(host->clk_mmc);
if (ret) {
dev_err(&pdev->dev, "Enable mmc clk err %d\n", ret);
goto error_disable_clk_ahb;
}
ret = clk_prepare_enable(host->clk_output);
if (ret) {
dev_err(&pdev->dev, "Enable output clk err %d\n", ret);
goto error_disable_clk_mmc;
}
ret = clk_prepare_enable(host->clk_sample);
if (ret) {
dev_err(&pdev->dev, "Enable sample clk err %d\n", ret);
goto error_disable_clk_output;
}
if (!IS_ERR(host->reset)) {
ret = reset_control_deassert(host->reset);
if (ret) {
dev_err(&pdev->dev, "reset err %d\n", ret);
goto error_disable_clk_sample;
}
}
ret = sunxi_mmc_reset_host(host);
if (ret)
goto error_assert_reset;
host->irq = platform_get_irq(pdev, 0);
return devm_request_threaded_irq(&pdev->dev, host->irq, sunxi_mmc_irq,
sunxi_mmc_handle_manual_stop, 0, "sunxi-mmc", host);
error_assert_reset:
if (!IS_ERR(host->reset))
reset_control_assert(host->reset);
error_disable_clk_sample:
clk_disable_unprepare(host->clk_sample);
error_disable_clk_output:
clk_disable_unprepare(host->clk_output);
error_disable_clk_mmc:
clk_disable_unprepare(host->clk_mmc);
error_disable_clk_ahb:
clk_disable_unprepare(host->clk_ahb);
return ret;
}
static int sunxi_mmc_probe(struct platform_device *pdev)
{
struct sunxi_mmc_host *host;
struct mmc_host *mmc;
int ret;
mmc = mmc_alloc_host(sizeof(struct sunxi_mmc_host), &pdev->dev);
if (!mmc) {
dev_err(&pdev->dev, "mmc alloc host failed\n");
return -ENOMEM;
}
host = mmc_priv(mmc);
host->mmc = mmc;
spin_lock_init(&host->lock);
ret = sunxi_mmc_resource_request(host, pdev);
if (ret)
goto error_free_host;
host->sg_cpu = dma_alloc_coherent(&pdev->dev, PAGE_SIZE,
&host->sg_dma, GFP_KERNEL);
if (!host->sg_cpu) {
dev_err(&pdev->dev, "Failed to allocate DMA descriptor mem\n");
ret = -ENOMEM;
goto error_free_host;
}
mmc->ops = &sunxi_mmc_ops;
mmc->max_blk_count = 8192;
mmc->max_blk_size = 4096;
mmc->max_segs = PAGE_SIZE / sizeof(struct sunxi_idma_des);
mmc->max_seg_size = (1 << host->idma_des_size_bits);
mmc->max_req_size = mmc->max_seg_size * mmc->max_segs;
mmc->f_min = 400000;
mmc->f_max = 50000000;
mmc->caps |= MMC_CAP_MMC_HIGHSPEED | MMC_CAP_SD_HIGHSPEED |
MMC_CAP_ERASE | MMC_CAP_SDIO_IRQ;
ret = mmc_of_parse(mmc);
if (ret)
goto error_free_dma;
ret = mmc_add_host(mmc);
if (ret)
goto error_free_dma;
dev_info(&pdev->dev, "base:0x%p irq:%u\n", host->reg_base, host->irq);
platform_set_drvdata(pdev, mmc);
return 0;
error_free_dma:
dma_free_coherent(&pdev->dev, PAGE_SIZE, host->sg_cpu, host->sg_dma);
error_free_host:
mmc_free_host(mmc);
return ret;
}
static int sunxi_mmc_remove(struct platform_device *pdev)
{
struct mmc_host *mmc = platform_get_drvdata(pdev);
struct sunxi_mmc_host *host = mmc_priv(mmc);
mmc_remove_host(mmc);
disable_irq(host->irq);
sunxi_mmc_reset_host(host);
if (!IS_ERR(host->reset))
reset_control_assert(host->reset);
clk_disable_unprepare(host->clk_mmc);
clk_disable_unprepare(host->clk_ahb);
dma_free_coherent(&pdev->dev, PAGE_SIZE, host->sg_cpu, host->sg_dma);
mmc_free_host(mmc);
return 0;
}
