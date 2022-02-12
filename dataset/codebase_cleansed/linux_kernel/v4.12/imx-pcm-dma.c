static bool filter(struct dma_chan *chan, void *param)
{
if (!imx_dma_is_general_purpose(chan))
return false;
chan->private = param;
return true;
}
int imx_pcm_dma_init(struct platform_device *pdev, size_t size)
{
struct snd_dmaengine_pcm_config *config;
config = devm_kzalloc(&pdev->dev,
sizeof(struct snd_dmaengine_pcm_config), GFP_KERNEL);
if (!config)
return -ENOMEM;
*config = imx_dmaengine_pcm_config;
return devm_snd_dmaengine_pcm_register(&pdev->dev,
config,
SND_DMAENGINE_PCM_FLAG_COMPAT);
}
