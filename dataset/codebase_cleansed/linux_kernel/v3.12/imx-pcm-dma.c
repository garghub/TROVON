static bool filter(struct dma_chan *chan, void *param)
{
struct snd_dmaengine_dai_dma_data *dma_data = param;
if (!imx_dma_is_general_purpose(chan))
return false;
chan->private = dma_data->filter_data;
return true;
}
int imx_pcm_dma_init(struct platform_device *pdev)
{
return snd_dmaengine_pcm_register(&pdev->dev, &imx_dmaengine_pcm_config,
SND_DMAENGINE_PCM_FLAG_NO_RESIDUE |
SND_DMAENGINE_PCM_FLAG_COMPAT);
}
void imx_pcm_dma_exit(struct platform_device *pdev)
{
snd_dmaengine_pcm_unregister(&pdev->dev);
}
