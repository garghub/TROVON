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
struct davinci_pcm_dma_params *dma_params =
&davinci_vcif_dev->dma_params[substream->stream];
u32 w;
davinci_vcif_stop(substream);
davinci_vcif_start(substream);
writel(DAVINCI_VC_CTRL_MASK, davinci_vc->base + DAVINCI_VC_CTRL);
writel(DAVINCI_VC_INT_MASK, davinci_vc->base + DAVINCI_VC_INTCLR);
writel(DAVINCI_VC_INT_MASK, davinci_vc->base + DAVINCI_VC_INTEN);
w = readl(davinci_vc->base + DAVINCI_VC_CTRL);
switch (params_format(params)) {
case SNDRV_PCM_FORMAT_U8:
dma_params->data_type = 0;
MOD_REG_BIT(w, DAVINCI_VC_CTRL_RD_BITS_8 |
DAVINCI_VC_CTRL_RD_UNSIGNED |
DAVINCI_VC_CTRL_WD_BITS_8 |
DAVINCI_VC_CTRL_WD_UNSIGNED, 1);
break;
case SNDRV_PCM_FORMAT_S8:
dma_params->data_type = 1;
MOD_REG_BIT(w, DAVINCI_VC_CTRL_RD_BITS_8 |
DAVINCI_VC_CTRL_WD_BITS_8, 1);
MOD_REG_BIT(w, DAVINCI_VC_CTRL_RD_UNSIGNED |
DAVINCI_VC_CTRL_WD_UNSIGNED, 0);
break;
case SNDRV_PCM_FORMAT_S16_LE:
dma_params->data_type = 2;
MOD_REG_BIT(w, DAVINCI_VC_CTRL_RD_BITS_8 |
DAVINCI_VC_CTRL_RD_UNSIGNED |
DAVINCI_VC_CTRL_WD_BITS_8 |
DAVINCI_VC_CTRL_WD_UNSIGNED, 0);
break;
default:
printk(KERN_WARNING "davinci-vcif: unsupported PCM format");
return -EINVAL;
}
dma_params->acnt = dma_params->data_type;
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
static int davinci_vcif_startup(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct davinci_vcif_dev *dev = snd_soc_dai_get_drvdata(dai);
snd_soc_dai_set_dma_data(dai, substream, dev->dma_params);
return 0;
}
static int davinci_vcif_probe(struct platform_device *pdev)
{
struct davinci_vc *davinci_vc = pdev->dev.platform_data;
struct davinci_vcif_dev *davinci_vcif_dev;
int ret;
davinci_vcif_dev = kzalloc(sizeof(struct davinci_vcif_dev), GFP_KERNEL);
if (!davinci_vcif_dev) {
dev_dbg(&pdev->dev,
"could not allocate memory for private data\n");
return -ENOMEM;
}
davinci_vcif_dev->davinci_vc = davinci_vc;
davinci_vcif_dev->dma_params[SNDRV_PCM_STREAM_PLAYBACK].channel =
davinci_vc->davinci_vcif.dma_tx_channel;
davinci_vcif_dev->dma_params[SNDRV_PCM_STREAM_PLAYBACK].dma_addr =
davinci_vc->davinci_vcif.dma_tx_addr;
davinci_vcif_dev->dma_params[SNDRV_PCM_STREAM_CAPTURE].channel =
davinci_vc->davinci_vcif.dma_rx_channel;
davinci_vcif_dev->dma_params[SNDRV_PCM_STREAM_CAPTURE].dma_addr =
davinci_vc->davinci_vcif.dma_rx_addr;
dev_set_drvdata(&pdev->dev, davinci_vcif_dev);
ret = snd_soc_register_dai(&pdev->dev, &davinci_vcif_dai);
if (ret != 0) {
dev_err(&pdev->dev, "could not register dai\n");
goto fail;
}
return 0;
fail:
kfree(davinci_vcif_dev);
return ret;
}
static int davinci_vcif_remove(struct platform_device *pdev)
{
struct davinci_vcif_dev *davinci_vcif_dev = dev_get_drvdata(&pdev->dev);
snd_soc_unregister_dai(&pdev->dev);
kfree(davinci_vcif_dev);
return 0;
}
static int __init davinci_vcif_init(void)
{
return platform_driver_probe(&davinci_vcif_driver, davinci_vcif_probe);
}
static void __exit davinci_vcif_exit(void)
{
platform_driver_unregister(&davinci_vcif_driver);
}
