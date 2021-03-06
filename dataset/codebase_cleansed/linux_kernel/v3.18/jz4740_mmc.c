static void jz4740_mmc_release_dma_channels(struct jz4740_mmc_host *host)
{
if (!host->use_dma)
return;
dma_release_channel(host->dma_tx);
dma_release_channel(host->dma_rx);
}
static int jz4740_mmc_acquire_dma_channels(struct jz4740_mmc_host *host)
{
dma_cap_mask_t mask;
dma_cap_zero(mask);
dma_cap_set(DMA_SLAVE, mask);
host->dma_tx = dma_request_channel(mask, NULL, host);
if (!host->dma_tx) {
dev_err(mmc_dev(host->mmc), "Failed to get dma_tx channel\n");
return -ENODEV;
}
host->dma_rx = dma_request_channel(mask, NULL, host);
if (!host->dma_rx) {
dev_err(mmc_dev(host->mmc), "Failed to get dma_rx channel\n");
goto free_master_write;
}
host->next_data.cookie = 1;
return 0;
free_master_write:
dma_release_channel(host->dma_tx);
return -ENODEV;
}
static inline int jz4740_mmc_get_dma_dir(struct mmc_data *data)
{
return (data->flags & MMC_DATA_READ) ? DMA_FROM_DEVICE : DMA_TO_DEVICE;
}
static inline struct dma_chan *jz4740_mmc_get_dma_chan(struct jz4740_mmc_host *host,
struct mmc_data *data)
{
return (data->flags & MMC_DATA_READ) ? host->dma_rx : host->dma_tx;
}
static void jz4740_mmc_dma_unmap(struct jz4740_mmc_host *host,
struct mmc_data *data)
{
struct dma_chan *chan = jz4740_mmc_get_dma_chan(host, data);
enum dma_data_direction dir = jz4740_mmc_get_dma_dir(data);
dma_unmap_sg(chan->device->dev, data->sg, data->sg_len, dir);
}
static int jz4740_mmc_prepare_dma_data(struct jz4740_mmc_host *host,
struct mmc_data *data,
struct jz4740_mmc_host_next *next,
struct dma_chan *chan)
{
struct jz4740_mmc_host_next *next_data = &host->next_data;
enum dma_data_direction dir = jz4740_mmc_get_dma_dir(data);
int sg_len;
if (!next && data->host_cookie &&
data->host_cookie != host->next_data.cookie) {
dev_warn(mmc_dev(host->mmc),
"[%s] invalid cookie: data->host_cookie %d host->next_data.cookie %d\n",
__func__,
data->host_cookie,
host->next_data.cookie);
data->host_cookie = 0;
}
if (next || data->host_cookie != host->next_data.cookie) {
sg_len = dma_map_sg(chan->device->dev,
data->sg,
data->sg_len,
dir);
} else {
sg_len = next_data->sg_len;
next_data->sg_len = 0;
}
if (sg_len <= 0) {
dev_err(mmc_dev(host->mmc),
"Failed to map scatterlist for DMA operation\n");
return -EINVAL;
}
if (next) {
next->sg_len = sg_len;
data->host_cookie = ++next->cookie < 0 ? 1 : next->cookie;
} else
host->sg_len = sg_len;
return 0;
}
static int jz4740_mmc_start_dma_transfer(struct jz4740_mmc_host *host,
struct mmc_data *data)
{
int ret;
struct dma_chan *chan;
struct dma_async_tx_descriptor *desc;
struct dma_slave_config conf = {
.src_addr_width = DMA_SLAVE_BUSWIDTH_4_BYTES,
.dst_addr_width = DMA_SLAVE_BUSWIDTH_4_BYTES,
.src_maxburst = JZ4740_MMC_FIFO_HALF_SIZE,
.dst_maxburst = JZ4740_MMC_FIFO_HALF_SIZE,
};
if (data->flags & MMC_DATA_WRITE) {
conf.direction = DMA_MEM_TO_DEV;
conf.dst_addr = host->mem_res->start + JZ_REG_MMC_TXFIFO;
conf.slave_id = JZ4740_DMA_TYPE_MMC_TRANSMIT;
chan = host->dma_tx;
} else {
conf.direction = DMA_DEV_TO_MEM;
conf.src_addr = host->mem_res->start + JZ_REG_MMC_RXFIFO;
conf.slave_id = JZ4740_DMA_TYPE_MMC_RECEIVE;
chan = host->dma_rx;
}
ret = jz4740_mmc_prepare_dma_data(host, data, NULL, chan);
if (ret)
return ret;
dmaengine_slave_config(chan, &conf);
desc = dmaengine_prep_slave_sg(chan,
data->sg,
host->sg_len,
conf.direction,
DMA_PREP_INTERRUPT | DMA_CTRL_ACK);
if (!desc) {
dev_err(mmc_dev(host->mmc),
"Failed to allocate DMA %s descriptor",
conf.direction == DMA_MEM_TO_DEV ? "TX" : "RX");
goto dma_unmap;
}
dmaengine_submit(desc);
dma_async_issue_pending(chan);
return 0;
dma_unmap:
jz4740_mmc_dma_unmap(host, data);
return -ENOMEM;
}
static void jz4740_mmc_pre_request(struct mmc_host *mmc,
struct mmc_request *mrq,
bool is_first_req)
{
struct jz4740_mmc_host *host = mmc_priv(mmc);
struct mmc_data *data = mrq->data;
struct jz4740_mmc_host_next *next_data = &host->next_data;
BUG_ON(data->host_cookie);
if (host->use_dma) {
struct dma_chan *chan = jz4740_mmc_get_dma_chan(host, data);
if (jz4740_mmc_prepare_dma_data(host, data, next_data, chan))
data->host_cookie = 0;
}
}
static void jz4740_mmc_post_request(struct mmc_host *mmc,
struct mmc_request *mrq,
int err)
{
struct jz4740_mmc_host *host = mmc_priv(mmc);
struct mmc_data *data = mrq->data;
if (host->use_dma && data->host_cookie) {
jz4740_mmc_dma_unmap(host, data);
data->host_cookie = 0;
}
if (err) {
struct dma_chan *chan = jz4740_mmc_get_dma_chan(host, data);
dmaengine_terminate_all(chan);
}
}
static void jz4740_mmc_set_irq_enabled(struct jz4740_mmc_host *host,
unsigned int irq, bool enabled)
{
unsigned long flags;
spin_lock_irqsave(&host->lock, flags);
if (enabled)
host->irq_mask &= ~irq;
else
host->irq_mask |= irq;
spin_unlock_irqrestore(&host->lock, flags);
writew(host->irq_mask, host->base + JZ_REG_MMC_IMASK);
}
static void jz4740_mmc_clock_enable(struct jz4740_mmc_host *host,
bool start_transfer)
{
uint16_t val = JZ_MMC_STRPCL_CLOCK_START;
if (start_transfer)
val |= JZ_MMC_STRPCL_START_OP;
writew(val, host->base + JZ_REG_MMC_STRPCL);
}
static void jz4740_mmc_clock_disable(struct jz4740_mmc_host *host)
{
uint32_t status;
unsigned int timeout = 1000;
writew(JZ_MMC_STRPCL_CLOCK_STOP, host->base + JZ_REG_MMC_STRPCL);
do {
status = readl(host->base + JZ_REG_MMC_STATUS);
} while (status & JZ_MMC_STATUS_CLK_EN && --timeout);
}
static void jz4740_mmc_reset(struct jz4740_mmc_host *host)
{
uint32_t status;
unsigned int timeout = 1000;
writew(JZ_MMC_STRPCL_RESET, host->base + JZ_REG_MMC_STRPCL);
udelay(10);
do {
status = readl(host->base + JZ_REG_MMC_STATUS);
} while (status & JZ_MMC_STATUS_IS_RESETTING && --timeout);
}
static void jz4740_mmc_request_done(struct jz4740_mmc_host *host)
{
struct mmc_request *req;
req = host->req;
host->req = NULL;
mmc_request_done(host->mmc, req);
}
static unsigned int jz4740_mmc_poll_irq(struct jz4740_mmc_host *host,
unsigned int irq)
{
unsigned int timeout = 0x800;
uint16_t status;
do {
status = readw(host->base + JZ_REG_MMC_IREG);
} while (!(status & irq) && --timeout);
if (timeout == 0) {
set_bit(0, &host->waiting);
mod_timer(&host->timeout_timer, jiffies + 5*HZ);
jz4740_mmc_set_irq_enabled(host, irq, true);
return true;
}
return false;
}
static void jz4740_mmc_transfer_check_state(struct jz4740_mmc_host *host,
struct mmc_data *data)
{
int status;
status = readl(host->base + JZ_REG_MMC_STATUS);
if (status & JZ_MMC_STATUS_WRITE_ERROR_MASK) {
if (status & (JZ_MMC_STATUS_TIMEOUT_WRITE)) {
host->req->cmd->error = -ETIMEDOUT;
data->error = -ETIMEDOUT;
} else {
host->req->cmd->error = -EIO;
data->error = -EIO;
}
} else if (status & JZ_MMC_STATUS_READ_ERROR_MASK) {
if (status & (JZ_MMC_STATUS_TIMEOUT_READ)) {
host->req->cmd->error = -ETIMEDOUT;
data->error = -ETIMEDOUT;
} else {
host->req->cmd->error = -EIO;
data->error = -EIO;
}
}
}
static bool jz4740_mmc_write_data(struct jz4740_mmc_host *host,
struct mmc_data *data)
{
struct sg_mapping_iter *miter = &host->miter;
void __iomem *fifo_addr = host->base + JZ_REG_MMC_TXFIFO;
uint32_t *buf;
bool timeout;
size_t i, j;
while (sg_miter_next(miter)) {
buf = miter->addr;
i = miter->length / 4;
j = i / 8;
i = i & 0x7;
while (j) {
timeout = jz4740_mmc_poll_irq(host, JZ_MMC_IRQ_TXFIFO_WR_REQ);
if (unlikely(timeout))
goto poll_timeout;
writel(buf[0], fifo_addr);
writel(buf[1], fifo_addr);
writel(buf[2], fifo_addr);
writel(buf[3], fifo_addr);
writel(buf[4], fifo_addr);
writel(buf[5], fifo_addr);
writel(buf[6], fifo_addr);
writel(buf[7], fifo_addr);
buf += 8;
--j;
}
if (unlikely(i)) {
timeout = jz4740_mmc_poll_irq(host, JZ_MMC_IRQ_TXFIFO_WR_REQ);
if (unlikely(timeout))
goto poll_timeout;
while (i) {
writel(*buf, fifo_addr);
++buf;
--i;
}
}
data->bytes_xfered += miter->length;
}
sg_miter_stop(miter);
return false;
poll_timeout:
miter->consumed = (void *)buf - miter->addr;
data->bytes_xfered += miter->consumed;
sg_miter_stop(miter);
return true;
}
static bool jz4740_mmc_read_data(struct jz4740_mmc_host *host,
struct mmc_data *data)
{
struct sg_mapping_iter *miter = &host->miter;
void __iomem *fifo_addr = host->base + JZ_REG_MMC_RXFIFO;
uint32_t *buf;
uint32_t d;
uint16_t status;
size_t i, j;
unsigned int timeout;
while (sg_miter_next(miter)) {
buf = miter->addr;
i = miter->length;
j = i / 32;
i = i & 0x1f;
while (j) {
timeout = jz4740_mmc_poll_irq(host, JZ_MMC_IRQ_RXFIFO_RD_REQ);
if (unlikely(timeout))
goto poll_timeout;
buf[0] = readl(fifo_addr);
buf[1] = readl(fifo_addr);
buf[2] = readl(fifo_addr);
buf[3] = readl(fifo_addr);
buf[4] = readl(fifo_addr);
buf[5] = readl(fifo_addr);
buf[6] = readl(fifo_addr);
buf[7] = readl(fifo_addr);
buf += 8;
--j;
}
if (unlikely(i)) {
timeout = jz4740_mmc_poll_irq(host, JZ_MMC_IRQ_RXFIFO_RD_REQ);
if (unlikely(timeout))
goto poll_timeout;
while (i >= 4) {
*buf++ = readl(fifo_addr);
i -= 4;
}
if (unlikely(i > 0)) {
d = readl(fifo_addr);
memcpy(buf, &d, i);
}
}
data->bytes_xfered += miter->length;
flush_dcache_page(miter->page);
}
sg_miter_stop(miter);
timeout = 1000;
status = readl(host->base + JZ_REG_MMC_STATUS);
while (!(status & JZ_MMC_STATUS_DATA_FIFO_EMPTY) && --timeout) {
d = readl(fifo_addr);
status = readl(host->base + JZ_REG_MMC_STATUS);
}
return false;
poll_timeout:
miter->consumed = (void *)buf - miter->addr;
data->bytes_xfered += miter->consumed;
sg_miter_stop(miter);
return true;
}
static void jz4740_mmc_timeout(unsigned long data)
{
struct jz4740_mmc_host *host = (struct jz4740_mmc_host *)data;
if (!test_and_clear_bit(0, &host->waiting))
return;
jz4740_mmc_set_irq_enabled(host, JZ_MMC_IRQ_END_CMD_RES, false);
host->req->cmd->error = -ETIMEDOUT;
jz4740_mmc_request_done(host);
}
static void jz4740_mmc_read_response(struct jz4740_mmc_host *host,
struct mmc_command *cmd)
{
int i;
uint16_t tmp;
void __iomem *fifo_addr = host->base + JZ_REG_MMC_RESP_FIFO;
if (cmd->flags & MMC_RSP_136) {
tmp = readw(fifo_addr);
for (i = 0; i < 4; ++i) {
cmd->resp[i] = tmp << 24;
tmp = readw(fifo_addr);
cmd->resp[i] |= tmp << 8;
tmp = readw(fifo_addr);
cmd->resp[i] |= tmp >> 8;
}
} else {
cmd->resp[0] = readw(fifo_addr) << 24;
cmd->resp[0] |= readw(fifo_addr) << 8;
cmd->resp[0] |= readw(fifo_addr) & 0xff;
}
}
static void jz4740_mmc_send_command(struct jz4740_mmc_host *host,
struct mmc_command *cmd)
{
uint32_t cmdat = host->cmdat;
host->cmdat &= ~JZ_MMC_CMDAT_INIT;
jz4740_mmc_clock_disable(host);
host->cmd = cmd;
if (cmd->flags & MMC_RSP_BUSY)
cmdat |= JZ_MMC_CMDAT_BUSY;
switch (mmc_resp_type(cmd)) {
case MMC_RSP_R1B:
case MMC_RSP_R1:
cmdat |= JZ_MMC_CMDAT_RSP_R1;
break;
case MMC_RSP_R2:
cmdat |= JZ_MMC_CMDAT_RSP_R2;
break;
case MMC_RSP_R3:
cmdat |= JZ_MMC_CMDAT_RSP_R3;
break;
default:
break;
}
if (cmd->data) {
cmdat |= JZ_MMC_CMDAT_DATA_EN;
if (cmd->data->flags & MMC_DATA_WRITE)
cmdat |= JZ_MMC_CMDAT_WRITE;
if (cmd->data->flags & MMC_DATA_STREAM)
cmdat |= JZ_MMC_CMDAT_STREAM;
if (host->use_dma)
cmdat |= JZ_MMC_CMDAT_DMA_EN;
writew(cmd->data->blksz, host->base + JZ_REG_MMC_BLKLEN);
writew(cmd->data->blocks, host->base + JZ_REG_MMC_NOB);
}
writeb(cmd->opcode, host->base + JZ_REG_MMC_CMD);
writel(cmd->arg, host->base + JZ_REG_MMC_ARG);
writel(cmdat, host->base + JZ_REG_MMC_CMDAT);
jz4740_mmc_clock_enable(host, 1);
}
static void jz_mmc_prepare_data_transfer(struct jz4740_mmc_host *host)
{
struct mmc_command *cmd = host->req->cmd;
struct mmc_data *data = cmd->data;
int direction;
if (data->flags & MMC_DATA_READ)
direction = SG_MITER_TO_SG;
else
direction = SG_MITER_FROM_SG;
sg_miter_start(&host->miter, data->sg, data->sg_len, direction);
}
static irqreturn_t jz_mmc_irq_worker(int irq, void *devid)
{
struct jz4740_mmc_host *host = (struct jz4740_mmc_host *)devid;
struct mmc_command *cmd = host->req->cmd;
struct mmc_request *req = host->req;
struct mmc_data *data = cmd->data;
bool timeout = false;
if (cmd->error)
host->state = JZ4740_MMC_STATE_DONE;
switch (host->state) {
case JZ4740_MMC_STATE_READ_RESPONSE:
if (cmd->flags & MMC_RSP_PRESENT)
jz4740_mmc_read_response(host, cmd);
if (!data)
break;
jz_mmc_prepare_data_transfer(host);
case JZ4740_MMC_STATE_TRANSFER_DATA:
if (host->use_dma) {
timeout = jz4740_mmc_start_dma_transfer(host, data);
data->bytes_xfered = data->blocks * data->blksz;
} else if (data->flags & MMC_DATA_READ)
timeout = jz4740_mmc_read_data(host, data);
else
timeout = jz4740_mmc_write_data(host, data);
if (unlikely(timeout)) {
host->state = JZ4740_MMC_STATE_TRANSFER_DATA;
break;
}
jz4740_mmc_transfer_check_state(host, data);
timeout = jz4740_mmc_poll_irq(host, JZ_MMC_IRQ_DATA_TRAN_DONE);
if (unlikely(timeout)) {
host->state = JZ4740_MMC_STATE_SEND_STOP;
break;
}
writew(JZ_MMC_IRQ_DATA_TRAN_DONE, host->base + JZ_REG_MMC_IREG);
case JZ4740_MMC_STATE_SEND_STOP:
if (!req->stop)
break;
jz4740_mmc_send_command(host, req->stop);
if (mmc_resp_type(req->stop) & MMC_RSP_BUSY) {
timeout = jz4740_mmc_poll_irq(host,
JZ_MMC_IRQ_PRG_DONE);
if (timeout) {
host->state = JZ4740_MMC_STATE_DONE;
break;
}
}
case JZ4740_MMC_STATE_DONE:
break;
}
if (!timeout)
jz4740_mmc_request_done(host);
return IRQ_HANDLED;
}
static irqreturn_t jz_mmc_irq(int irq, void *devid)
{
struct jz4740_mmc_host *host = devid;
struct mmc_command *cmd = host->cmd;
uint16_t irq_reg, status, tmp;
irq_reg = readw(host->base + JZ_REG_MMC_IREG);
tmp = irq_reg;
irq_reg &= ~host->irq_mask;
tmp &= ~(JZ_MMC_IRQ_TXFIFO_WR_REQ | JZ_MMC_IRQ_RXFIFO_RD_REQ |
JZ_MMC_IRQ_PRG_DONE | JZ_MMC_IRQ_DATA_TRAN_DONE);
if (tmp != irq_reg)
writew(tmp & ~irq_reg, host->base + JZ_REG_MMC_IREG);
if (irq_reg & JZ_MMC_IRQ_SDIO) {
writew(JZ_MMC_IRQ_SDIO, host->base + JZ_REG_MMC_IREG);
mmc_signal_sdio_irq(host->mmc);
irq_reg &= ~JZ_MMC_IRQ_SDIO;
}
if (host->req && cmd && irq_reg) {
if (test_and_clear_bit(0, &host->waiting)) {
del_timer(&host->timeout_timer);
status = readl(host->base + JZ_REG_MMC_STATUS);
if (status & JZ_MMC_STATUS_TIMEOUT_RES) {
cmd->error = -ETIMEDOUT;
} else if (status & JZ_MMC_STATUS_CRC_RES_ERR) {
cmd->error = -EIO;
} else if (status & (JZ_MMC_STATUS_CRC_READ_ERROR |
JZ_MMC_STATUS_CRC_WRITE_ERROR)) {
if (cmd->data)
cmd->data->error = -EIO;
cmd->error = -EIO;
}
jz4740_mmc_set_irq_enabled(host, irq_reg, false);
writew(irq_reg, host->base + JZ_REG_MMC_IREG);
return IRQ_WAKE_THREAD;
}
}
return IRQ_HANDLED;
}
static int jz4740_mmc_set_clock_rate(struct jz4740_mmc_host *host, int rate)
{
int div = 0;
int real_rate;
jz4740_mmc_clock_disable(host);
clk_set_rate(host->clk, JZ_MMC_CLK_RATE);
real_rate = clk_get_rate(host->clk);
while (real_rate > rate && div < 7) {
++div;
real_rate >>= 1;
}
writew(div, host->base + JZ_REG_MMC_CLKRT);
return real_rate;
}
static void jz4740_mmc_request(struct mmc_host *mmc, struct mmc_request *req)
{
struct jz4740_mmc_host *host = mmc_priv(mmc);
host->req = req;
writew(0xffff, host->base + JZ_REG_MMC_IREG);
writew(JZ_MMC_IRQ_END_CMD_RES, host->base + JZ_REG_MMC_IREG);
jz4740_mmc_set_irq_enabled(host, JZ_MMC_IRQ_END_CMD_RES, true);
host->state = JZ4740_MMC_STATE_READ_RESPONSE;
set_bit(0, &host->waiting);
mod_timer(&host->timeout_timer, jiffies + 5*HZ);
jz4740_mmc_send_command(host, req->cmd);
}
static void jz4740_mmc_set_ios(struct mmc_host *mmc, struct mmc_ios *ios)
{
struct jz4740_mmc_host *host = mmc_priv(mmc);
if (ios->clock)
jz4740_mmc_set_clock_rate(host, ios->clock);
switch (ios->power_mode) {
case MMC_POWER_UP:
jz4740_mmc_reset(host);
if (gpio_is_valid(host->pdata->gpio_power))
gpio_set_value(host->pdata->gpio_power,
!host->pdata->power_active_low);
host->cmdat |= JZ_MMC_CMDAT_INIT;
clk_prepare_enable(host->clk);
break;
case MMC_POWER_ON:
break;
default:
if (gpio_is_valid(host->pdata->gpio_power))
gpio_set_value(host->pdata->gpio_power,
host->pdata->power_active_low);
clk_disable_unprepare(host->clk);
break;
}
switch (ios->bus_width) {
case MMC_BUS_WIDTH_1:
host->cmdat &= ~JZ_MMC_CMDAT_BUS_WIDTH_4BIT;
break;
case MMC_BUS_WIDTH_4:
host->cmdat |= JZ_MMC_CMDAT_BUS_WIDTH_4BIT;
break;
default:
break;
}
}
static void jz4740_mmc_enable_sdio_irq(struct mmc_host *mmc, int enable)
{
struct jz4740_mmc_host *host = mmc_priv(mmc);
jz4740_mmc_set_irq_enabled(host, JZ_MMC_IRQ_SDIO, enable);
}
static int jz4740_mmc_request_gpio(struct device *dev, int gpio,
const char *name, bool output, int value)
{
int ret;
if (!gpio_is_valid(gpio))
return 0;
ret = gpio_request(gpio, name);
if (ret) {
dev_err(dev, "Failed to request %s gpio: %d\n", name, ret);
return ret;
}
if (output)
gpio_direction_output(gpio, value);
else
gpio_direction_input(gpio);
return 0;
}
static int jz4740_mmc_request_gpios(struct mmc_host *mmc,
struct platform_device *pdev)
{
struct jz4740_mmc_platform_data *pdata = pdev->dev.platform_data;
int ret = 0;
if (!pdata)
return 0;
if (!pdata->card_detect_active_low)
mmc->caps2 |= MMC_CAP2_CD_ACTIVE_HIGH;
if (!pdata->read_only_active_low)
mmc->caps2 |= MMC_CAP2_RO_ACTIVE_HIGH;
if (gpio_is_valid(pdata->gpio_card_detect)) {
ret = mmc_gpio_request_cd(mmc, pdata->gpio_card_detect, 0);
if (ret)
return ret;
}
if (gpio_is_valid(pdata->gpio_read_only)) {
ret = mmc_gpio_request_ro(mmc, pdata->gpio_read_only);
if (ret)
return ret;
}
return jz4740_mmc_request_gpio(&pdev->dev, pdata->gpio_power,
"MMC read only", true, pdata->power_active_low);
}
static void jz4740_mmc_free_gpios(struct platform_device *pdev)
{
struct jz4740_mmc_platform_data *pdata = pdev->dev.platform_data;
if (!pdata)
return;
if (gpio_is_valid(pdata->gpio_power))
gpio_free(pdata->gpio_power);
}
static inline size_t jz4740_mmc_num_pins(struct jz4740_mmc_host *host)
{
size_t num_pins = ARRAY_SIZE(jz4740_mmc_pins);
if (host->pdata && host->pdata->data_1bit)
num_pins -= 3;
return num_pins;
}
static int jz4740_mmc_probe(struct platform_device* pdev)
{
int ret;
struct mmc_host *mmc;
struct jz4740_mmc_host *host;
struct jz4740_mmc_platform_data *pdata;
pdata = pdev->dev.platform_data;
mmc = mmc_alloc_host(sizeof(struct jz4740_mmc_host), &pdev->dev);
if (!mmc) {
dev_err(&pdev->dev, "Failed to alloc mmc host structure\n");
return -ENOMEM;
}
host = mmc_priv(mmc);
host->pdata = pdata;
host->irq = platform_get_irq(pdev, 0);
if (host->irq < 0) {
ret = host->irq;
dev_err(&pdev->dev, "Failed to get platform irq: %d\n", ret);
goto err_free_host;
}
host->clk = devm_clk_get(&pdev->dev, "mmc");
if (IS_ERR(host->clk)) {
ret = PTR_ERR(host->clk);
dev_err(&pdev->dev, "Failed to get mmc clock\n");
goto err_free_host;
}
host->mem_res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
host->base = devm_ioremap_resource(&pdev->dev, host->mem_res);
if (IS_ERR(host->base)) {
ret = PTR_ERR(host->base);
dev_err(&pdev->dev, "Failed to ioremap base memory\n");
goto err_free_host;
}
ret = jz_gpio_bulk_request(jz4740_mmc_pins, jz4740_mmc_num_pins(host));
if (ret) {
dev_err(&pdev->dev, "Failed to request mmc pins: %d\n", ret);
goto err_free_host;
}
ret = jz4740_mmc_request_gpios(mmc, pdev);
if (ret)
goto err_gpio_bulk_free;
mmc->ops = &jz4740_mmc_ops;
mmc->f_min = JZ_MMC_CLK_RATE / 128;
mmc->f_max = JZ_MMC_CLK_RATE;
mmc->ocr_avail = MMC_VDD_32_33 | MMC_VDD_33_34;
mmc->caps = (pdata && pdata->data_1bit) ? 0 : MMC_CAP_4_BIT_DATA;
mmc->caps |= MMC_CAP_SDIO_IRQ;
mmc->max_blk_size = (1 << 10) - 1;
mmc->max_blk_count = (1 << 15) - 1;
mmc->max_req_size = mmc->max_blk_size * mmc->max_blk_count;
mmc->max_segs = 128;
mmc->max_seg_size = mmc->max_req_size;
host->mmc = mmc;
host->pdev = pdev;
spin_lock_init(&host->lock);
host->irq_mask = 0xffff;
ret = request_threaded_irq(host->irq, jz_mmc_irq, jz_mmc_irq_worker, 0,
dev_name(&pdev->dev), host);
if (ret) {
dev_err(&pdev->dev, "Failed to request irq: %d\n", ret);
goto err_free_gpios;
}
jz4740_mmc_reset(host);
jz4740_mmc_clock_disable(host);
setup_timer(&host->timeout_timer, jz4740_mmc_timeout,
(unsigned long)host);
set_timer_slack(&host->timeout_timer, HZ);
host->use_dma = true;
if (host->use_dma && jz4740_mmc_acquire_dma_channels(host) != 0)
host->use_dma = false;
platform_set_drvdata(pdev, host);
ret = mmc_add_host(mmc);
if (ret) {
dev_err(&pdev->dev, "Failed to add mmc host: %d\n", ret);
goto err_free_irq;
}
dev_info(&pdev->dev, "JZ SD/MMC card driver registered\n");
dev_info(&pdev->dev, "Using %s, %d-bit mode\n",
host->use_dma ? "DMA" : "PIO",
(mmc->caps & MMC_CAP_4_BIT_DATA) ? 4 : 1);
return 0;
err_free_irq:
free_irq(host->irq, host);
err_free_gpios:
jz4740_mmc_free_gpios(pdev);
err_gpio_bulk_free:
if (host->use_dma)
jz4740_mmc_release_dma_channels(host);
jz_gpio_bulk_free(jz4740_mmc_pins, jz4740_mmc_num_pins(host));
err_free_host:
mmc_free_host(mmc);
return ret;
}
static int jz4740_mmc_remove(struct platform_device *pdev)
{
struct jz4740_mmc_host *host = platform_get_drvdata(pdev);
del_timer_sync(&host->timeout_timer);
jz4740_mmc_set_irq_enabled(host, 0xff, false);
jz4740_mmc_reset(host);
mmc_remove_host(host->mmc);
free_irq(host->irq, host);
jz4740_mmc_free_gpios(pdev);
jz_gpio_bulk_free(jz4740_mmc_pins, jz4740_mmc_num_pins(host));
if (host->use_dma)
jz4740_mmc_release_dma_channels(host);
mmc_free_host(host->mmc);
return 0;
}
static int jz4740_mmc_suspend(struct device *dev)
{
struct jz4740_mmc_host *host = dev_get_drvdata(dev);
jz_gpio_bulk_suspend(jz4740_mmc_pins, jz4740_mmc_num_pins(host));
return 0;
}
static int jz4740_mmc_resume(struct device *dev)
{
struct jz4740_mmc_host *host = dev_get_drvdata(dev);
jz_gpio_bulk_resume(jz4740_mmc_pins, jz4740_mmc_num_pins(host));
return 0;
}
