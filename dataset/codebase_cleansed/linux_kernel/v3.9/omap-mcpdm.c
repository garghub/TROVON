static inline void omap_mcpdm_write(struct omap_mcpdm *mcpdm, u16 reg, u32 val)
{
__raw_writel(val, mcpdm->io_base + reg);
}
static inline int omap_mcpdm_read(struct omap_mcpdm *mcpdm, u16 reg)
{
return __raw_readl(mcpdm->io_base + reg);
}
static void omap_mcpdm_reg_dump(struct omap_mcpdm *mcpdm)
{
dev_dbg(mcpdm->dev, "***********************\n");
dev_dbg(mcpdm->dev, "IRQSTATUS_RAW: 0x%04x\n",
omap_mcpdm_read(mcpdm, MCPDM_REG_IRQSTATUS_RAW));
dev_dbg(mcpdm->dev, "IRQSTATUS: 0x%04x\n",
omap_mcpdm_read(mcpdm, MCPDM_REG_IRQSTATUS));
dev_dbg(mcpdm->dev, "IRQENABLE_SET: 0x%04x\n",
omap_mcpdm_read(mcpdm, MCPDM_REG_IRQENABLE_SET));
dev_dbg(mcpdm->dev, "IRQENABLE_CLR: 0x%04x\n",
omap_mcpdm_read(mcpdm, MCPDM_REG_IRQENABLE_CLR));
dev_dbg(mcpdm->dev, "IRQWAKE_EN: 0x%04x\n",
omap_mcpdm_read(mcpdm, MCPDM_REG_IRQWAKE_EN));
dev_dbg(mcpdm->dev, "DMAENABLE_SET: 0x%04x\n",
omap_mcpdm_read(mcpdm, MCPDM_REG_DMAENABLE_SET));
dev_dbg(mcpdm->dev, "DMAENABLE_CLR: 0x%04x\n",
omap_mcpdm_read(mcpdm, MCPDM_REG_DMAENABLE_CLR));
dev_dbg(mcpdm->dev, "DMAWAKEEN: 0x%04x\n",
omap_mcpdm_read(mcpdm, MCPDM_REG_DMAWAKEEN));
dev_dbg(mcpdm->dev, "CTRL: 0x%04x\n",
omap_mcpdm_read(mcpdm, MCPDM_REG_CTRL));
dev_dbg(mcpdm->dev, "DN_DATA: 0x%04x\n",
omap_mcpdm_read(mcpdm, MCPDM_REG_DN_DATA));
dev_dbg(mcpdm->dev, "UP_DATA: 0x%04x\n",
omap_mcpdm_read(mcpdm, MCPDM_REG_UP_DATA));
dev_dbg(mcpdm->dev, "FIFO_CTRL_DN: 0x%04x\n",
omap_mcpdm_read(mcpdm, MCPDM_REG_FIFO_CTRL_DN));
dev_dbg(mcpdm->dev, "FIFO_CTRL_UP: 0x%04x\n",
omap_mcpdm_read(mcpdm, MCPDM_REG_FIFO_CTRL_UP));
dev_dbg(mcpdm->dev, "***********************\n");
}
static void omap_mcpdm_reg_dump(struct omap_mcpdm *mcpdm) {}
static void omap_mcpdm_start(struct omap_mcpdm *mcpdm)
{
u32 ctrl = omap_mcpdm_read(mcpdm, MCPDM_REG_CTRL);
ctrl |= (MCPDM_SW_DN_RST | MCPDM_SW_UP_RST);
omap_mcpdm_write(mcpdm, MCPDM_REG_CTRL, ctrl);
ctrl |= mcpdm->dn_channels | mcpdm->up_channels;
omap_mcpdm_write(mcpdm, MCPDM_REG_CTRL, ctrl);
ctrl &= ~(MCPDM_SW_DN_RST | MCPDM_SW_UP_RST);
omap_mcpdm_write(mcpdm, MCPDM_REG_CTRL, ctrl);
}
static void omap_mcpdm_stop(struct omap_mcpdm *mcpdm)
{
u32 ctrl = omap_mcpdm_read(mcpdm, MCPDM_REG_CTRL);
ctrl |= (MCPDM_SW_DN_RST | MCPDM_SW_UP_RST);
omap_mcpdm_write(mcpdm, MCPDM_REG_CTRL, ctrl);
ctrl &= ~(mcpdm->dn_channels | mcpdm->up_channels);
omap_mcpdm_write(mcpdm, MCPDM_REG_CTRL, ctrl);
ctrl &= ~(MCPDM_SW_DN_RST | MCPDM_SW_UP_RST);
omap_mcpdm_write(mcpdm, MCPDM_REG_CTRL, ctrl);
}
static inline int omap_mcpdm_active(struct omap_mcpdm *mcpdm)
{
return omap_mcpdm_read(mcpdm, MCPDM_REG_CTRL) &
(MCPDM_PDM_DN_MASK | MCPDM_PDM_UP_MASK);
}
static void omap_mcpdm_open_streams(struct omap_mcpdm *mcpdm)
{
omap_mcpdm_write(mcpdm, MCPDM_REG_IRQENABLE_SET,
MCPDM_DN_IRQ_EMPTY | MCPDM_DN_IRQ_FULL |
MCPDM_UP_IRQ_EMPTY | MCPDM_UP_IRQ_FULL);
if (mcpdm->dn_rx_offset) {
u32 dn_offset = mcpdm->dn_rx_offset;
omap_mcpdm_write(mcpdm, MCPDM_REG_DN_OFFSET, dn_offset);
dn_offset |= (MCPDM_DN_OFST_RX1_EN | MCPDM_DN_OFST_RX2_EN);
omap_mcpdm_write(mcpdm, MCPDM_REG_DN_OFFSET, dn_offset);
}
omap_mcpdm_write(mcpdm, MCPDM_REG_FIFO_CTRL_DN, mcpdm->dn_threshold);
omap_mcpdm_write(mcpdm, MCPDM_REG_FIFO_CTRL_UP, mcpdm->up_threshold);
omap_mcpdm_write(mcpdm, MCPDM_REG_DMAENABLE_SET,
MCPDM_DMA_DN_ENABLE | MCPDM_DMA_UP_ENABLE);
}
static void omap_mcpdm_close_streams(struct omap_mcpdm *mcpdm)
{
omap_mcpdm_write(mcpdm, MCPDM_REG_IRQENABLE_CLR,
MCPDM_DN_IRQ_EMPTY | MCPDM_DN_IRQ_FULL);
omap_mcpdm_write(mcpdm, MCPDM_REG_DMAENABLE_CLR, MCPDM_DMA_DN_ENABLE);
omap_mcpdm_write(mcpdm, MCPDM_REG_IRQENABLE_CLR,
MCPDM_UP_IRQ_EMPTY | MCPDM_UP_IRQ_FULL);
omap_mcpdm_write(mcpdm, MCPDM_REG_DMAENABLE_CLR, MCPDM_DMA_UP_ENABLE);
if (mcpdm->dn_rx_offset)
omap_mcpdm_write(mcpdm, MCPDM_REG_DN_OFFSET, 0);
}
static irqreturn_t omap_mcpdm_irq_handler(int irq, void *dev_id)
{
struct omap_mcpdm *mcpdm = dev_id;
int irq_status;
irq_status = omap_mcpdm_read(mcpdm, MCPDM_REG_IRQSTATUS);
omap_mcpdm_write(mcpdm, MCPDM_REG_IRQSTATUS, irq_status);
if (irq_status & MCPDM_DN_IRQ_FULL)
dev_dbg(mcpdm->dev, "DN (playback) FIFO Full\n");
if (irq_status & MCPDM_DN_IRQ_EMPTY)
dev_dbg(mcpdm->dev, "DN (playback) FIFO Empty\n");
if (irq_status & MCPDM_DN_IRQ)
dev_dbg(mcpdm->dev, "DN (playback) write request\n");
if (irq_status & MCPDM_UP_IRQ_FULL)
dev_dbg(mcpdm->dev, "UP (capture) FIFO Full\n");
if (irq_status & MCPDM_UP_IRQ_EMPTY)
dev_dbg(mcpdm->dev, "UP (capture) FIFO Empty\n");
if (irq_status & MCPDM_UP_IRQ)
dev_dbg(mcpdm->dev, "UP (capture) write request\n");
return IRQ_HANDLED;
}
static int omap_mcpdm_dai_startup(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct omap_mcpdm *mcpdm = snd_soc_dai_get_drvdata(dai);
mutex_lock(&mcpdm->mutex);
if (!dai->active) {
u32 ctrl = omap_mcpdm_read(mcpdm, MCPDM_REG_CTRL);
omap_mcpdm_write(mcpdm, MCPDM_REG_CTRL, ctrl | MCPDM_WD_EN);
omap_mcpdm_open_streams(mcpdm);
}
mutex_unlock(&mcpdm->mutex);
snd_soc_dai_set_dma_data(dai, substream,
&omap_mcpdm_dai_dma_params[substream->stream]);
return 0;
}
static void omap_mcpdm_dai_shutdown(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct omap_mcpdm *mcpdm = snd_soc_dai_get_drvdata(dai);
mutex_lock(&mcpdm->mutex);
if (!dai->active) {
if (omap_mcpdm_active(mcpdm)) {
omap_mcpdm_stop(mcpdm);
omap_mcpdm_close_streams(mcpdm);
}
}
mutex_unlock(&mcpdm->mutex);
}
static int omap_mcpdm_dai_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct omap_mcpdm *mcpdm = snd_soc_dai_get_drvdata(dai);
int stream = substream->stream;
struct omap_pcm_dma_data *dma_data;
int channels;
int link_mask = 0;
channels = params_channels(params);
switch (channels) {
case 5:
if (stream == SNDRV_PCM_STREAM_CAPTURE)
return -EINVAL;
link_mask |= 1 << 4;
case 4:
if (stream == SNDRV_PCM_STREAM_CAPTURE)
return -EINVAL;
link_mask |= 1 << 3;
case 3:
link_mask |= 1 << 2;
case 2:
link_mask |= 1 << 1;
case 1:
link_mask |= 1 << 0;
break;
default:
return -EINVAL;
}
dma_data = snd_soc_dai_get_dma_data(dai, substream);
if (stream == SNDRV_PCM_STREAM_PLAYBACK) {
mcpdm->dn_channels = link_mask << 3;
dma_data->packet_size =
(MCPDM_DN_THRES_MAX - mcpdm->dn_threshold) * channels;
} else {
mcpdm->up_channels = link_mask << 0;
dma_data->packet_size = mcpdm->up_threshold * channels;
}
return 0;
}
static int omap_mcpdm_prepare(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct omap_mcpdm *mcpdm = snd_soc_dai_get_drvdata(dai);
if (!omap_mcpdm_active(mcpdm)) {
omap_mcpdm_start(mcpdm);
omap_mcpdm_reg_dump(mcpdm);
}
return 0;
}
static int omap_mcpdm_probe(struct snd_soc_dai *dai)
{
struct omap_mcpdm *mcpdm = snd_soc_dai_get_drvdata(dai);
int ret;
pm_runtime_enable(mcpdm->dev);
pm_runtime_get_sync(mcpdm->dev);
omap_mcpdm_write(mcpdm, MCPDM_REG_CTRL, 0x00);
ret = request_irq(mcpdm->irq, omap_mcpdm_irq_handler,
0, "McPDM", (void *)mcpdm);
pm_runtime_put_sync(mcpdm->dev);
if (ret) {
dev_err(mcpdm->dev, "Request for IRQ failed\n");
pm_runtime_disable(mcpdm->dev);
}
mcpdm->dn_threshold = 2;
mcpdm->up_threshold = MCPDM_UP_THRES_MAX - 3;
return ret;
}
static int omap_mcpdm_remove(struct snd_soc_dai *dai)
{
struct omap_mcpdm *mcpdm = snd_soc_dai_get_drvdata(dai);
free_irq(mcpdm->irq, (void *)mcpdm);
pm_runtime_disable(mcpdm->dev);
return 0;
}
void omap_mcpdm_configure_dn_offsets(struct snd_soc_pcm_runtime *rtd,
u8 rx1, u8 rx2)
{
struct omap_mcpdm *mcpdm = snd_soc_dai_get_drvdata(rtd->cpu_dai);
mcpdm->dn_rx_offset = MCPDM_DNOFST_RX1(rx1) | MCPDM_DNOFST_RX2(rx2);
}
static int asoc_mcpdm_probe(struct platform_device *pdev)
{
struct omap_mcpdm *mcpdm;
struct resource *res;
mcpdm = devm_kzalloc(&pdev->dev, sizeof(struct omap_mcpdm), GFP_KERNEL);
if (!mcpdm)
return -ENOMEM;
platform_set_drvdata(pdev, mcpdm);
mutex_init(&mcpdm->mutex);
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "dma");
if (res == NULL)
return -ENOMEM;
omap_mcpdm_dai_dma_params[0].port_addr = res->start + MCPDM_REG_DN_DATA;
omap_mcpdm_dai_dma_params[1].port_addr = res->start + MCPDM_REG_UP_DATA;
res = platform_get_resource_byname(pdev, IORESOURCE_DMA, "dn_link");
if (!res)
return -ENODEV;
omap_mcpdm_dai_dma_params[0].dma_req = res->start;
res = platform_get_resource_byname(pdev, IORESOURCE_DMA, "up_link");
if (!res)
return -ENODEV;
omap_mcpdm_dai_dma_params[1].dma_req = res->start;
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "mpu");
if (res == NULL)
return -ENOMEM;
if (!devm_request_mem_region(&pdev->dev, res->start,
resource_size(res), "McPDM"))
return -EBUSY;
mcpdm->io_base = devm_ioremap(&pdev->dev, res->start,
resource_size(res));
if (!mcpdm->io_base)
return -ENOMEM;
mcpdm->irq = platform_get_irq(pdev, 0);
if (mcpdm->irq < 0)
return mcpdm->irq;
mcpdm->dev = &pdev->dev;
return snd_soc_register_dai(&pdev->dev, &omap_mcpdm_dai);
}
static int asoc_mcpdm_remove(struct platform_device *pdev)
{
snd_soc_unregister_dai(&pdev->dev);
return 0;
}
