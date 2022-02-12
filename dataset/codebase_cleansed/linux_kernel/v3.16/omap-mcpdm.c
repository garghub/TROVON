static inline void omap_mcpdm_write(struct omap_mcpdm *mcpdm, u16 reg, u32 val)
{
writel_relaxed(val, mcpdm->io_base + reg);
}
static inline int omap_mcpdm_read(struct omap_mcpdm *mcpdm, u16 reg)
{
return readl_relaxed(mcpdm->io_base + reg);
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
u32 link_mask = mcpdm->config[0].link_mask | mcpdm->config[1].link_mask;
ctrl |= (MCPDM_SW_DN_RST | MCPDM_SW_UP_RST);
omap_mcpdm_write(mcpdm, MCPDM_REG_CTRL, ctrl);
ctrl |= link_mask;
omap_mcpdm_write(mcpdm, MCPDM_REG_CTRL, ctrl);
ctrl &= ~(MCPDM_SW_DN_RST | MCPDM_SW_UP_RST);
omap_mcpdm_write(mcpdm, MCPDM_REG_CTRL, ctrl);
}
static void omap_mcpdm_stop(struct omap_mcpdm *mcpdm)
{
u32 ctrl = omap_mcpdm_read(mcpdm, MCPDM_REG_CTRL);
u32 link_mask = MCPDM_PDM_DN_MASK | MCPDM_PDM_UP_MASK;
ctrl |= (MCPDM_SW_DN_RST | MCPDM_SW_UP_RST);
omap_mcpdm_write(mcpdm, MCPDM_REG_CTRL, ctrl);
ctrl &= ~(link_mask);
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
omap_mcpdm_write(mcpdm, MCPDM_REG_FIFO_CTRL_DN,
mcpdm->config[SNDRV_PCM_STREAM_PLAYBACK].threshold);
omap_mcpdm_write(mcpdm, MCPDM_REG_FIFO_CTRL_UP,
mcpdm->config[SNDRV_PCM_STREAM_CAPTURE].threshold);
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
mcpdm->config[0].link_mask = 0;
mcpdm->config[1].link_mask = 0;
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
struct snd_dmaengine_dai_dma_data *dma_data;
u32 threshold;
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
threshold = mcpdm->config[stream].threshold;
if (stream == SNDRV_PCM_STREAM_PLAYBACK) {
link_mask <<= 3;
if (!mcpdm->config[!stream].link_mask)
mcpdm->config[!stream].link_mask = 0x3;
dma_data->maxburst =
(MCPDM_DN_THRES_MAX - threshold) * channels;
} else {
if (!mcpdm->config[!stream].link_mask)
mcpdm->config[!stream].link_mask = (0x3 << 3);
dma_data->maxburst = threshold * channels;
}
if (mcpdm->config[stream].link_mask &&
mcpdm->config[stream].link_mask != link_mask)
mcpdm->restart = true;
mcpdm->config[stream].link_mask = link_mask;
return 0;
}
static int omap_mcpdm_prepare(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct omap_mcpdm *mcpdm = snd_soc_dai_get_drvdata(dai);
if (!omap_mcpdm_active(mcpdm)) {
omap_mcpdm_start(mcpdm);
omap_mcpdm_reg_dump(mcpdm);
} else if (mcpdm->restart) {
omap_mcpdm_stop(mcpdm);
omap_mcpdm_start(mcpdm);
mcpdm->restart = false;
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
ret = devm_request_irq(mcpdm->dev, mcpdm->irq, omap_mcpdm_irq_handler,
0, "McPDM", (void *)mcpdm);
pm_runtime_put_sync(mcpdm->dev);
if (ret) {
dev_err(mcpdm->dev, "Request for IRQ failed\n");
pm_runtime_disable(mcpdm->dev);
}
mcpdm->config[SNDRV_PCM_STREAM_PLAYBACK].threshold = 2;
mcpdm->config[SNDRV_PCM_STREAM_CAPTURE].threshold =
MCPDM_UP_THRES_MAX - 3;
snd_soc_dai_init_dma_data(dai,
&mcpdm->dma_data[SNDRV_PCM_STREAM_PLAYBACK],
&mcpdm->dma_data[SNDRV_PCM_STREAM_CAPTURE]);
return ret;
}
static int omap_mcpdm_remove(struct snd_soc_dai *dai)
{
struct omap_mcpdm *mcpdm = snd_soc_dai_get_drvdata(dai);
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
int ret;
mcpdm = devm_kzalloc(&pdev->dev, sizeof(struct omap_mcpdm), GFP_KERNEL);
if (!mcpdm)
return -ENOMEM;
platform_set_drvdata(pdev, mcpdm);
mutex_init(&mcpdm->mutex);
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "dma");
if (res == NULL)
return -ENOMEM;
mcpdm->dma_data[0].addr = res->start + MCPDM_REG_DN_DATA;
mcpdm->dma_data[1].addr = res->start + MCPDM_REG_UP_DATA;
mcpdm->dma_data[0].filter_data = "dn_link";
mcpdm->dma_data[1].filter_data = "up_link";
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "mpu");
mcpdm->io_base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(mcpdm->io_base))
return PTR_ERR(mcpdm->io_base);
mcpdm->irq = platform_get_irq(pdev, 0);
if (mcpdm->irq < 0)
return mcpdm->irq;
mcpdm->dev = &pdev->dev;
ret = devm_snd_soc_register_component(&pdev->dev,
&omap_mcpdm_component,
&omap_mcpdm_dai, 1);
if (ret)
return ret;
return omap_pcm_platform_register(&pdev->dev);
}
