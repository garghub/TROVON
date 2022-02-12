static void davinci_vcif_start(struct snd_pcm_substream *substream)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct davinci_vcif_dev *davinci_vcif_dev =
snd_soc_dai_get_drvdata(rtd->cpu_dai);
struct davinci_vc *davinci_vc = davinci_vcif_dev->davinci_vc;
u32 w;
w = readl(davinci_vc->base + DAVINCI_VC_CTRL);
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
MOD_REG_BIT(w, DAVINCI_VC_CTRL_RSTDAC, 0);
else
MOD_REG_BIT(w, DAVINCI_VC_CTRL_RSTADC, 0);
writel(w, davinci_vc->base + DAVINCI_VC_CTRL);
}
static void davinci_vcif_stop(struct snd_pcm_substream *substream)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct davinci_vcif_dev *davinci_vcif_dev =
snd_soc_dai_get_drvdata(rtd->cpu_dai);
struct davinci_vc *davinci_vc = davinci_vcif_dev->davinci_vc;
u32 w;
w = readl(davinci_vc->base + DAVINCI_VC_CTRL);
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
MOD_REG_BIT(w, DAVINCI_VC_CTRL_RSTDAC, 1);
else
MOD_REG_BIT(w, DAVINCI_VC_CTRL_RSTADC, 1);
writel(w, davinci_vc->base + DAVINCI_VC_CTRL);
}
static int davinci_vcif_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct davinci_vcif_dev *davinci_vcif_dev = snd_soc_dai_get_drvdata(dai);
struct davinci_vc *davinci_vc = davinci_vcif_dev->davinci_vc;
u32 w;
davinci_vcif_stop(substream);
davinci_vcif_start(substream);
writel(DAVINCI_VC_CTRL_MASK, davinci_vc->base + DAVINCI_VC_CTRL);
writel(DAVINCI_VC_INT_MASK, davinci_vc->base + DAVINCI_VC_INTCLR);
writel(DAVINCI_VC_INT_MASK, davinci_vc->base + DAVINCI_VC_INTEN);
w = readl(davinci_vc->base + DAVINCI_VC_CTRL);
switch (params_format(params)) {
case SNDRV_PCM_FORMAT_U8:
MOD_REG_BIT(w, DAVINCI_VC_CTRL_RD_BITS_8 |
DAVINCI_VC_CTRL_RD_UNSIGNED |
DAVINCI_VC_CTRL_WD_BITS_8 |
DAVINCI_VC_CTRL_WD_UNSIGNED, 1);
break;
case SNDRV_PCM_FORMAT_S8:
MOD_REG_BIT(w, DAVINCI_VC_CTRL_RD_BITS_8 |
DAVINCI_VC_CTRL_WD_BITS_8, 1);
MOD_REG_BIT(w, DAVINCI_VC_CTRL_RD_UNSIGNED |
DAVINCI_VC_CTRL_WD_UNSIGNED, 0);
break;
case SNDRV_PCM_FORMAT_S16_LE:
MOD_REG_BIT(w, DAVINCI_VC_CTRL_RD_BITS_8 |
DAVINCI_VC_CTRL_RD_UNSIGNED |
DAVINCI_VC_CTRL_WD_BITS_8 |
DAVINCI_VC_CTRL_WD_UNSIGNED, 0);
break;
default:
printk(KERN_WARNING "davinci-vcif: unsupported PCM format");
return -EINVAL;
}
writel(w, davinci_vc->base + DAVINCI_VC_CTRL);
return 0;
}
static int davinci_vcif_trigger(struct snd_pcm_substream *substream, int cmd,
struct snd_soc_dai *dai)
{
int ret = 0;
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
case SNDRV_PCM_TRIGGER_RESUME:
case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
davinci_vcif_start(substream);
break;
case SNDRV_PCM_TRIGGER_STOP:
case SNDRV_PCM_TRIGGER_SUSPEND:
case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
davinci_vcif_stop(substream);
break;
default:
ret = -EINVAL;
}
return ret;
}
static int davinci_vcif_dai_probe(struct snd_soc_dai *dai)
{
struct davinci_vcif_dev *dev = snd_soc_dai_get_drvdata(dai);
dai->playback_dma_data = &dev->dma_data[SNDRV_PCM_STREAM_PLAYBACK];
dai->capture_dma_data = &dev->dma_data[SNDRV_PCM_STREAM_CAPTURE];
return 0;
}
static int davinci_vcif_probe(struct platform_device *pdev)
{
struct davinci_vc *davinci_vc = pdev->dev.platform_data;
struct davinci_vcif_dev *davinci_vcif_dev;
int ret;
davinci_vcif_dev = devm_kzalloc(&pdev->dev,
sizeof(struct davinci_vcif_dev),
GFP_KERNEL);
if (!davinci_vcif_dev) {
dev_dbg(&pdev->dev,
"could not allocate memory for private data\n");
return -ENOMEM;
}
davinci_vcif_dev->davinci_vc = davinci_vc;
davinci_vcif_dev->dma_data[SNDRV_PCM_STREAM_PLAYBACK].filter_data =
&davinci_vc->davinci_vcif.dma_tx_channel;
davinci_vcif_dev->dma_data[SNDRV_PCM_STREAM_PLAYBACK].addr =
davinci_vc->davinci_vcif.dma_tx_addr;
davinci_vcif_dev->dma_data[SNDRV_PCM_STREAM_CAPTURE].filter_data =
&davinci_vc->davinci_vcif.dma_rx_channel;
davinci_vcif_dev->dma_data[SNDRV_PCM_STREAM_CAPTURE].addr =
davinci_vc->davinci_vcif.dma_rx_addr;
dev_set_drvdata(&pdev->dev, davinci_vcif_dev);
ret = devm_snd_soc_register_component(&pdev->dev,
&davinci_vcif_component,
&davinci_vcif_dai, 1);
if (ret != 0) {
dev_err(&pdev->dev, "could not register dai\n");
return ret;
}
ret = edma_pcm_platform_register(&pdev->dev);
if (ret) {
dev_err(&pdev->dev, "register PCM failed: %d\n", ret);
return ret;
}
return 0;
}
