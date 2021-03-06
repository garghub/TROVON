static inline int has_dbdma(void)
{
switch (alchemy_get_cputype()) {
case ALCHEMY_CPU_AU1200:
case ALCHEMY_CPU_AU1300:
return 1;
default:
return 0;
}
}
static inline void IRQ_ON(struct au1xmmc_host *host, u32 mask)
{
u32 val = au_readl(HOST_CONFIG(host));
val |= mask;
au_writel(val, HOST_CONFIG(host));
au_sync();
}
static inline void FLUSH_FIFO(struct au1xmmc_host *host)
{
u32 val = au_readl(HOST_CONFIG2(host));
au_writel(val | SD_CONFIG2_FF, HOST_CONFIG2(host));
au_sync_delay(1);
val &= ~SD_CONFIG2_DF;
au_writel(val, HOST_CONFIG2(host));
au_sync();
}
static inline void IRQ_OFF(struct au1xmmc_host *host, u32 mask)
{
u32 val = au_readl(HOST_CONFIG(host));
val &= ~mask;
au_writel(val, HOST_CONFIG(host));
au_sync();
}
static inline void SEND_STOP(struct au1xmmc_host *host)
{
u32 config2;
WARN_ON(host->status != HOST_S_DATA);
host->status = HOST_S_STOP;
config2 = au_readl(HOST_CONFIG2(host));
au_writel(config2 | SD_CONFIG2_DF, HOST_CONFIG2(host));
au_sync();
au_writel(STOP_CMD, HOST_CMD(host));
}
static void au1xmmc_set_power(struct au1xmmc_host *host, int state)
{
if (host->platdata && host->platdata->set_power)
host->platdata->set_power(host->mmc, state);
}
static int au1xmmc_card_inserted(struct mmc_host *mmc)
{
struct au1xmmc_host *host = mmc_priv(mmc);
if (host->platdata && host->platdata->card_inserted)
return !!host->platdata->card_inserted(host->mmc);
return -ENOSYS;
}
static int au1xmmc_card_readonly(struct mmc_host *mmc)
{
struct au1xmmc_host *host = mmc_priv(mmc);
if (host->platdata && host->platdata->card_readonly)
return !!host->platdata->card_readonly(mmc);
return -ENOSYS;
}
static void au1xmmc_finish_request(struct au1xmmc_host *host)
{
struct mmc_request *mrq = host->mrq;
host->mrq = NULL;
host->flags &= HOST_F_ACTIVE | HOST_F_DMA;
host->dma.len = 0;
host->dma.dir = 0;
host->pio.index = 0;
host->pio.offset = 0;
host->pio.len = 0;
host->status = HOST_S_IDLE;
mmc_request_done(host->mmc, mrq);
}
static void au1xmmc_tasklet_finish(unsigned long param)
{
struct au1xmmc_host *host = (struct au1xmmc_host *) param;
au1xmmc_finish_request(host);
}
static int au1xmmc_send_command(struct au1xmmc_host *host, int wait,
struct mmc_command *cmd, struct mmc_data *data)
{
u32 mmccmd = (cmd->opcode << SD_CMD_CI_SHIFT);
switch (mmc_resp_type(cmd)) {
case MMC_RSP_NONE:
break;
case MMC_RSP_R1:
mmccmd |= SD_CMD_RT_1;
break;
case MMC_RSP_R1B:
mmccmd |= SD_CMD_RT_1B;
break;
case MMC_RSP_R2:
mmccmd |= SD_CMD_RT_2;
break;
case MMC_RSP_R3:
mmccmd |= SD_CMD_RT_3;
break;
default:
pr_info("au1xmmc: unhandled response type %02x\n",
mmc_resp_type(cmd));
return -EINVAL;
}
if (data) {
if (data->flags & MMC_DATA_READ) {
if (data->blocks > 1)
mmccmd |= SD_CMD_CT_4;
else
mmccmd |= SD_CMD_CT_2;
} else if (data->flags & MMC_DATA_WRITE) {
if (data->blocks > 1)
mmccmd |= SD_CMD_CT_3;
else
mmccmd |= SD_CMD_CT_1;
}
}
au_writel(cmd->arg, HOST_CMDARG(host));
au_sync();
if (wait)
IRQ_OFF(host, SD_CONFIG_CR);
au_writel((mmccmd | SD_CMD_GO), HOST_CMD(host));
au_sync();
while (au_readl(HOST_CMD(host)) & SD_CMD_GO)
;
if (wait) {
u32 status = au_readl(HOST_STATUS(host));
while (!(status & SD_STATUS_CR))
status = au_readl(HOST_STATUS(host));
au_writel(SD_STATUS_CR, HOST_STATUS(host));
IRQ_ON(host, SD_CONFIG_CR);
}
return 0;
}
static void au1xmmc_data_complete(struct au1xmmc_host *host, u32 status)
{
struct mmc_request *mrq = host->mrq;
struct mmc_data *data;
u32 crc;
WARN_ON((host->status != HOST_S_DATA) && (host->status != HOST_S_STOP));
if (host->mrq == NULL)
return;
data = mrq->cmd->data;
if (status == 0)
status = au_readl(HOST_STATUS(host));
while ((host->flags & HOST_F_XMIT) && (status & SD_STATUS_DB))
status = au_readl(HOST_STATUS(host));
data->error = 0;
dma_unmap_sg(mmc_dev(host->mmc), data->sg, data->sg_len, host->dma.dir);
crc = (status & (SD_STATUS_WC | SD_STATUS_RC));
if (host->flags & HOST_F_XMIT)
crc |= ((status & 0x07) == 0x02) ? 0 : 1;
if (crc)
data->error = -EILSEQ;
au_writel(SD_STATUS_WC | SD_STATUS_RC, HOST_STATUS(host));
data->bytes_xfered = 0;
if (!data->error) {
if (host->flags & (HOST_F_DMA | HOST_F_DBDMA)) {
u32 chan = DMA_CHANNEL(host);
chan_tab_t *c = *((chan_tab_t **)chan);
au1x_dma_chan_t *cp = c->chan_ptr;
data->bytes_xfered = cp->ddma_bytecnt;
} else
data->bytes_xfered =
(data->blocks * data->blksz) - host->pio.len;
}
au1xmmc_finish_request(host);
}
static void au1xmmc_tasklet_data(unsigned long param)
{
struct au1xmmc_host *host = (struct au1xmmc_host *)param;
u32 status = au_readl(HOST_STATUS(host));
au1xmmc_data_complete(host, status);
}
static void au1xmmc_send_pio(struct au1xmmc_host *host)
{
struct mmc_data *data;
int sg_len, max, count;
unsigned char *sg_ptr, val;
u32 status;
struct scatterlist *sg;
data = host->mrq->data;
if (!(host->flags & HOST_F_XMIT))
return;
sg = &data->sg[host->pio.index];
sg_ptr = sg_virt(sg) + host->pio.offset;
sg_len = data->sg[host->pio.index].length - host->pio.offset;
max = (sg_len > host->pio.len) ? host->pio.len : sg_len;
if (max > AU1XMMC_MAX_TRANSFER)
max = AU1XMMC_MAX_TRANSFER;
for (count = 0; count < max; count++) {
status = au_readl(HOST_STATUS(host));
if (!(status & SD_STATUS_TH))
break;
val = *sg_ptr++;
au_writel((unsigned long)val, HOST_TXPORT(host));
au_sync();
}
host->pio.len -= count;
host->pio.offset += count;
if (count == sg_len) {
host->pio.index++;
host->pio.offset = 0;
}
if (host->pio.len == 0) {
IRQ_OFF(host, SD_CONFIG_TH);
if (host->flags & HOST_F_STOP)
SEND_STOP(host);
tasklet_schedule(&host->data_task);
}
}
static void au1xmmc_receive_pio(struct au1xmmc_host *host)
{
struct mmc_data *data;
int max, count, sg_len = 0;
unsigned char *sg_ptr = NULL;
u32 status, val;
struct scatterlist *sg;
data = host->mrq->data;
if (!(host->flags & HOST_F_RECV))
return;
max = host->pio.len;
if (host->pio.index < host->dma.len) {
sg = &data->sg[host->pio.index];
sg_ptr = sg_virt(sg) + host->pio.offset;
sg_len = sg_dma_len(&data->sg[host->pio.index]) - host->pio.offset;
if (sg_len < max)
max = sg_len;
}
if (max > AU1XMMC_MAX_TRANSFER)
max = AU1XMMC_MAX_TRANSFER;
for (count = 0; count < max; count++) {
status = au_readl(HOST_STATUS(host));
if (!(status & SD_STATUS_NE))
break;
if (status & SD_STATUS_RC) {
DBG("RX CRC Error [%d + %d].\n", host->pdev->id,
host->pio.len, count);
break;
}
if (status & SD_STATUS_RO) {
DBG("RX Overrun [%d + %d]\n", host->pdev->id,
host->pio.len, count);
break;
}
else if (status & SD_STATUS_RU) {
DBG("RX Underrun [%d + %d]\n", host->pdev->id,
host->pio.len, count);
break;
}
val = au_readl(HOST_RXPORT(host));
if (sg_ptr)
*sg_ptr++ = (unsigned char)(val & 0xFF);
}
host->pio.len -= count;
host->pio.offset += count;
if (sg_len && count == sg_len) {
host->pio.index++;
host->pio.offset = 0;
}
if (host->pio.len == 0) {
IRQ_OFF(host, SD_CONFIG_NE);
if (host->flags & HOST_F_STOP)
SEND_STOP(host);
tasklet_schedule(&host->data_task);
}
}
static void au1xmmc_cmd_complete(struct au1xmmc_host *host, u32 status)
{
struct mmc_request *mrq = host->mrq;
struct mmc_command *cmd;
u32 r[4];
int i, trans;
if (!host->mrq)
return;
cmd = mrq->cmd;
cmd->error = 0;
if (cmd->flags & MMC_RSP_PRESENT) {
if (cmd->flags & MMC_RSP_136) {
r[0] = au_readl(host->iobase + SD_RESP3);
r[1] = au_readl(host->iobase + SD_RESP2);
r[2] = au_readl(host->iobase + SD_RESP1);
r[3] = au_readl(host->iobase + SD_RESP0);
for (i = 0; i < 4; i++) {
cmd->resp[i] = (r[i] & 0x00FFFFFF) << 8;
if (i != 3)
cmd->resp[i] |= (r[i + 1] & 0xFF000000) >> 24;
}
} else {
cmd->resp[0] = au_readl(host->iobase + SD_RESP0);
}
}
if (status & (SD_STATUS_SC | SD_STATUS_WC | SD_STATUS_RC))
cmd->error = -EILSEQ;
trans = host->flags & (HOST_F_XMIT | HOST_F_RECV);
if (!trans || cmd->error) {
IRQ_OFF(host, SD_CONFIG_TH | SD_CONFIG_RA | SD_CONFIG_RF);
tasklet_schedule(&host->finish_task);
return;
}
host->status = HOST_S_DATA;
if ((host->flags & (HOST_F_DMA | HOST_F_DBDMA))) {
u32 channel = DMA_CHANNEL(host);
if (host->flags & HOST_F_RECV) {
u32 mask = SD_STATUS_DB | SD_STATUS_NE;
while((status & mask) != mask)
status = au_readl(HOST_STATUS(host));
}
au1xxx_dbdma_start(channel);
}
}
static void au1xmmc_set_clock(struct au1xmmc_host *host, int rate)
{
unsigned int pbus = get_au1x00_speed();
unsigned int divisor;
u32 config;
pbus /= ((au_readl(SYS_POWERCTRL) & 0x3) + 2);
pbus /= 2;
divisor = ((pbus / rate) / 2) - 1;
config = au_readl(HOST_CONFIG(host));
config &= ~(SD_CONFIG_DIV);
config |= (divisor & SD_CONFIG_DIV) | SD_CONFIG_DE;
au_writel(config, HOST_CONFIG(host));
au_sync();
}
static int au1xmmc_prepare_data(struct au1xmmc_host *host,
struct mmc_data *data)
{
int datalen = data->blocks * data->blksz;
if (data->flags & MMC_DATA_READ)
host->flags |= HOST_F_RECV;
else
host->flags |= HOST_F_XMIT;
if (host->mrq->stop)
host->flags |= HOST_F_STOP;
host->dma.dir = DMA_BIDIRECTIONAL;
host->dma.len = dma_map_sg(mmc_dev(host->mmc), data->sg,
data->sg_len, host->dma.dir);
if (host->dma.len == 0)
return -ETIMEDOUT;
au_writel(data->blksz - 1, HOST_BLKSIZE(host));
if (host->flags & (HOST_F_DMA | HOST_F_DBDMA)) {
int i;
u32 channel = DMA_CHANNEL(host);
au1xxx_dbdma_stop(channel);
for (i = 0; i < host->dma.len; i++) {
u32 ret = 0, flags = DDMA_FLAGS_NOIE;
struct scatterlist *sg = &data->sg[i];
int sg_len = sg->length;
int len = (datalen > sg_len) ? sg_len : datalen;
if (i == host->dma.len - 1)
flags = DDMA_FLAGS_IE;
if (host->flags & HOST_F_XMIT) {
ret = au1xxx_dbdma_put_source(channel,
sg_phys(sg), len, flags);
} else {
ret = au1xxx_dbdma_put_dest(channel,
sg_phys(sg), len, flags);
}
if (!ret)
goto dataerr;
datalen -= len;
}
} else {
host->pio.index = 0;
host->pio.offset = 0;
host->pio.len = datalen;
if (host->flags & HOST_F_XMIT)
IRQ_ON(host, SD_CONFIG_TH);
else
IRQ_ON(host, SD_CONFIG_NE);
}
return 0;
dataerr:
dma_unmap_sg(mmc_dev(host->mmc), data->sg, data->sg_len,
host->dma.dir);
return -ETIMEDOUT;
}
static void au1xmmc_request(struct mmc_host* mmc, struct mmc_request* mrq)
{
struct au1xmmc_host *host = mmc_priv(mmc);
int ret = 0;
WARN_ON(irqs_disabled());
WARN_ON(host->status != HOST_S_IDLE);
host->mrq = mrq;
host->status = HOST_S_CMD;
if (0 == au1xmmc_card_inserted(mmc)) {
mrq->cmd->error = -ENOMEDIUM;
au1xmmc_finish_request(host);
return;
}
if (mrq->data) {
FLUSH_FIFO(host);
ret = au1xmmc_prepare_data(host, mrq->data);
}
if (!ret)
ret = au1xmmc_send_command(host, 0, mrq->cmd, mrq->data);
if (ret) {
mrq->cmd->error = ret;
au1xmmc_finish_request(host);
}
}
static void au1xmmc_reset_controller(struct au1xmmc_host *host)
{
au_writel(SD_ENABLE_CE, HOST_ENABLE(host));
au_sync_delay(1);
au_writel(SD_ENABLE_R | SD_ENABLE_CE, HOST_ENABLE(host));
au_sync_delay(5);
au_writel(~0, HOST_STATUS(host));
au_sync();
au_writel(0, HOST_BLKSIZE(host));
au_writel(0x001fffff, HOST_TIMEOUT(host));
au_sync();
au_writel(SD_CONFIG2_EN, HOST_CONFIG2(host));
au_sync();
au_writel(SD_CONFIG2_EN | SD_CONFIG2_FF, HOST_CONFIG2(host));
au_sync_delay(1);
au_writel(SD_CONFIG2_EN, HOST_CONFIG2(host));
au_sync();
au_writel(AU1XMMC_INTERRUPTS, HOST_CONFIG(host));
au_sync();
}
static void au1xmmc_set_ios(struct mmc_host *mmc, struct mmc_ios *ios)
{
struct au1xmmc_host *host = mmc_priv(mmc);
u32 config2;
if (ios->power_mode == MMC_POWER_OFF)
au1xmmc_set_power(host, 0);
else if (ios->power_mode == MMC_POWER_ON) {
au1xmmc_set_power(host, 1);
}
if (ios->clock && ios->clock != host->clock) {
au1xmmc_set_clock(host, ios->clock);
host->clock = ios->clock;
}
config2 = au_readl(HOST_CONFIG2(host));
switch (ios->bus_width) {
case MMC_BUS_WIDTH_8:
config2 |= SD_CONFIG2_BB;
break;
case MMC_BUS_WIDTH_4:
config2 &= ~SD_CONFIG2_BB;
config2 |= SD_CONFIG2_WB;
break;
case MMC_BUS_WIDTH_1:
config2 &= ~(SD_CONFIG2_WB | SD_CONFIG2_BB);
break;
}
au_writel(config2, HOST_CONFIG2(host));
au_sync();
}
static irqreturn_t au1xmmc_irq(int irq, void *dev_id)
{
struct au1xmmc_host *host = dev_id;
u32 status;
status = au_readl(HOST_STATUS(host));
if (!(status & SD_STATUS_I))
return IRQ_NONE;
if (status & SD_STATUS_SI)
mmc_signal_sdio_irq(host->mmc);
if (host->mrq && (status & STATUS_TIMEOUT)) {
if (status & SD_STATUS_RAT)
host->mrq->cmd->error = -ETIMEDOUT;
else if (status & SD_STATUS_DT)
host->mrq->data->error = -ETIMEDOUT;
IRQ_OFF(host, SD_CONFIG_NE | SD_CONFIG_TH);
tasklet_schedule(&host->finish_task);
}
#if 0
else if (status & SD_STATUS_DD) {
if (!(host->flags & HOST_F_DMA) && (status & SD_STATUS_NE))
au1xmmc_receive_pio(host);
else {
au1xmmc_data_complete(host, status);
}
}
#endif
else if (status & SD_STATUS_CR) {
if (host->status == HOST_S_CMD)
au1xmmc_cmd_complete(host, status);
} else if (!(host->flags & HOST_F_DMA)) {
if ((host->flags & HOST_F_XMIT) && (status & STATUS_DATA_OUT))
au1xmmc_send_pio(host);
else if ((host->flags & HOST_F_RECV) && (status & STATUS_DATA_IN))
au1xmmc_receive_pio(host);
} else if (status & 0x203F3C70) {
DBG("Unhandled status %8.8x\n", host->pdev->id,
status);
}
au_writel(status, HOST_STATUS(host));
au_sync();
return IRQ_HANDLED;
}
static void au1xmmc_dbdma_callback(int irq, void *dev_id)
{
struct au1xmmc_host *host = (struct au1xmmc_host *)dev_id;
if (!host->mrq)
return;
if (host->flags & HOST_F_STOP)
SEND_STOP(host);
tasklet_schedule(&host->data_task);
}
static int au1xmmc_dbdma_init(struct au1xmmc_host *host)
{
struct resource *res;
int txid, rxid;
res = platform_get_resource(host->pdev, IORESOURCE_DMA, 0);
if (!res)
return -ENODEV;
txid = res->start;
res = platform_get_resource(host->pdev, IORESOURCE_DMA, 1);
if (!res)
return -ENODEV;
rxid = res->start;
if (!memid)
return -ENODEV;
host->tx_chan = au1xxx_dbdma_chan_alloc(memid, txid,
au1xmmc_dbdma_callback, (void *)host);
if (!host->tx_chan) {
dev_err(&host->pdev->dev, "cannot allocate TX DMA\n");
return -ENODEV;
}
host->rx_chan = au1xxx_dbdma_chan_alloc(rxid, memid,
au1xmmc_dbdma_callback, (void *)host);
if (!host->rx_chan) {
dev_err(&host->pdev->dev, "cannot allocate RX DMA\n");
au1xxx_dbdma_chan_free(host->tx_chan);
return -ENODEV;
}
au1xxx_dbdma_set_devwidth(host->tx_chan, 8);
au1xxx_dbdma_set_devwidth(host->rx_chan, 8);
au1xxx_dbdma_ring_alloc(host->tx_chan, AU1XMMC_DESCRIPTOR_COUNT);
au1xxx_dbdma_ring_alloc(host->rx_chan, AU1XMMC_DESCRIPTOR_COUNT);
host->flags |= HOST_F_DMA | HOST_F_DBDMA;
return 0;
}
static void au1xmmc_dbdma_shutdown(struct au1xmmc_host *host)
{
if (host->flags & HOST_F_DMA) {
host->flags &= ~HOST_F_DMA;
au1xxx_dbdma_chan_free(host->tx_chan);
au1xxx_dbdma_chan_free(host->rx_chan);
}
}
static void au1xmmc_enable_sdio_irq(struct mmc_host *mmc, int en)
{
struct au1xmmc_host *host = mmc_priv(mmc);
if (en)
IRQ_ON(host, SD_CONFIG_SI);
else
IRQ_OFF(host, SD_CONFIG_SI);
}
static int au1xmmc_probe(struct platform_device *pdev)
{
struct mmc_host *mmc;
struct au1xmmc_host *host;
struct resource *r;
int ret, iflag;
mmc = mmc_alloc_host(sizeof(struct au1xmmc_host), &pdev->dev);
if (!mmc) {
dev_err(&pdev->dev, "no memory for mmc_host\n");
ret = -ENOMEM;
goto out0;
}
host = mmc_priv(mmc);
host->mmc = mmc;
host->platdata = pdev->dev.platform_data;
host->pdev = pdev;
ret = -ENODEV;
r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!r) {
dev_err(&pdev->dev, "no mmio defined\n");
goto out1;
}
host->ioarea = request_mem_region(r->start, resource_size(r),
pdev->name);
if (!host->ioarea) {
dev_err(&pdev->dev, "mmio already in use\n");
goto out1;
}
host->iobase = (unsigned long)ioremap(r->start, 0x3c);
if (!host->iobase) {
dev_err(&pdev->dev, "cannot remap mmio\n");
goto out2;
}
r = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
if (!r) {
dev_err(&pdev->dev, "no IRQ defined\n");
goto out3;
}
host->irq = r->start;
mmc->ops = &au1xmmc_ops;
mmc->f_min = 450000;
mmc->f_max = 24000000;
mmc->max_blk_size = 2048;
mmc->max_blk_count = 512;
mmc->ocr_avail = AU1XMMC_OCR;
mmc->caps = MMC_CAP_4_BIT_DATA | MMC_CAP_SDIO_IRQ;
mmc->max_segs = AU1XMMC_DESCRIPTOR_COUNT;
iflag = IRQF_SHARED;
switch (alchemy_get_cputype()) {
case ALCHEMY_CPU_AU1100:
mmc->max_seg_size = AU1100_MMC_DESCRIPTOR_SIZE;
break;
case ALCHEMY_CPU_AU1200:
mmc->max_seg_size = AU1200_MMC_DESCRIPTOR_SIZE;
break;
case ALCHEMY_CPU_AU1300:
iflag = 0;
mmc->max_seg_size = AU1200_MMC_DESCRIPTOR_SIZE;
mmc->f_max = 52000000;
if (host->ioarea->start == AU1100_SD0_PHYS_ADDR)
mmc->caps |= MMC_CAP_8_BIT_DATA;
break;
}
ret = request_irq(host->irq, au1xmmc_irq, iflag, DRIVER_NAME, host);
if (ret) {
dev_err(&pdev->dev, "cannot grab IRQ\n");
goto out3;
}
host->status = HOST_S_IDLE;
if (host->platdata && host->platdata->cd_setup) {
ret = host->platdata->cd_setup(mmc, 1);
if (ret) {
dev_warn(&pdev->dev, "board CD setup failed\n");
mmc->caps |= MMC_CAP_NEEDS_POLL;
}
} else
mmc->caps |= MMC_CAP_NEEDS_POLL;
if (host->platdata)
mmc->caps &= ~(host->platdata->mask_host_caps);
tasklet_init(&host->data_task, au1xmmc_tasklet_data,
(unsigned long)host);
tasklet_init(&host->finish_task, au1xmmc_tasklet_finish,
(unsigned long)host);
if (has_dbdma()) {
ret = au1xmmc_dbdma_init(host);
if (ret)
pr_info(DRIVER_NAME ": DBDMA init failed; using PIO\n");
}
#ifdef CONFIG_LEDS_CLASS
if (host->platdata && host->platdata->led) {
struct led_classdev *led = host->platdata->led;
led->name = mmc_hostname(mmc);
led->brightness = LED_OFF;
led->default_trigger = mmc_hostname(mmc);
ret = led_classdev_register(mmc_dev(mmc), led);
if (ret)
goto out5;
}
#endif
au1xmmc_reset_controller(host);
ret = mmc_add_host(mmc);
if (ret) {
dev_err(&pdev->dev, "cannot add mmc host\n");
goto out6;
}
platform_set_drvdata(pdev, host);
pr_info(DRIVER_NAME ": MMC Controller %d set up at %8.8X"
" (mode=%s)\n", pdev->id, host->iobase,
host->flags & HOST_F_DMA ? "dma" : "pio");
return 0;
out6:
#ifdef CONFIG_LEDS_CLASS
if (host->platdata && host->platdata->led)
led_classdev_unregister(host->platdata->led);
out5:
#endif
au_writel(0, HOST_ENABLE(host));
au_writel(0, HOST_CONFIG(host));
au_writel(0, HOST_CONFIG2(host));
au_sync();
if (host->flags & HOST_F_DBDMA)
au1xmmc_dbdma_shutdown(host);
tasklet_kill(&host->data_task);
tasklet_kill(&host->finish_task);
if (host->platdata && host->platdata->cd_setup &&
!(mmc->caps & MMC_CAP_NEEDS_POLL))
host->platdata->cd_setup(mmc, 0);
free_irq(host->irq, host);
out3:
iounmap((void *)host->iobase);
out2:
release_resource(host->ioarea);
kfree(host->ioarea);
out1:
mmc_free_host(mmc);
out0:
return ret;
}
static int au1xmmc_remove(struct platform_device *pdev)
{
struct au1xmmc_host *host = platform_get_drvdata(pdev);
if (host) {
mmc_remove_host(host->mmc);
#ifdef CONFIG_LEDS_CLASS
if (host->platdata && host->platdata->led)
led_classdev_unregister(host->platdata->led);
#endif
if (host->platdata && host->platdata->cd_setup &&
!(host->mmc->caps & MMC_CAP_NEEDS_POLL))
host->platdata->cd_setup(host->mmc, 0);
au_writel(0, HOST_ENABLE(host));
au_writel(0, HOST_CONFIG(host));
au_writel(0, HOST_CONFIG2(host));
au_sync();
tasklet_kill(&host->data_task);
tasklet_kill(&host->finish_task);
if (host->flags & HOST_F_DBDMA)
au1xmmc_dbdma_shutdown(host);
au1xmmc_set_power(host, 0);
free_irq(host->irq, host);
iounmap((void *)host->iobase);
release_resource(host->ioarea);
kfree(host->ioarea);
mmc_free_host(host->mmc);
}
return 0;
}
static int au1xmmc_suspend(struct platform_device *pdev, pm_message_t state)
{
struct au1xmmc_host *host = platform_get_drvdata(pdev);
int ret;
ret = mmc_suspend_host(host->mmc);
if (ret)
return ret;
au_writel(0, HOST_CONFIG2(host));
au_writel(0, HOST_CONFIG(host));
au_writel(0xffffffff, HOST_STATUS(host));
au_writel(0, HOST_ENABLE(host));
au_sync();
return 0;
}
static int au1xmmc_resume(struct platform_device *pdev)
{
struct au1xmmc_host *host = platform_get_drvdata(pdev);
au1xmmc_reset_controller(host);
return mmc_resume_host(host->mmc);
}
static int __init au1xmmc_init(void)
{
if (has_dbdma()) {
memid = au1xxx_ddma_add_device(&au1xmmc_mem_dbdev);
if (!memid)
pr_err("au1xmmc: cannot add memory dbdma\n");
}
return platform_driver_register(&au1xmmc_driver);
}
static void __exit au1xmmc_exit(void)
{
if (has_dbdma() && memid)
au1xxx_ddma_del_device(memid);
platform_driver_unregister(&au1xmmc_driver);
}
