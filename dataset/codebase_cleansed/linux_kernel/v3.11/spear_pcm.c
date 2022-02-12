static struct dma_chan *spear_pcm_request_chan(struct snd_soc_pcm_runtime *rtd,
struct snd_pcm_substream *substream)
{
struct spear_dma_data *dma_data;
dma_data = snd_soc_dai_get_dma_data(rtd->cpu_dai, substream);
return snd_dmaengine_pcm_request_channel(dma_data->filter, dma_data);
}
static int spear_soc_platform_probe(struct platform_device *pdev)
{
return snd_dmaengine_pcm_register(&pdev->dev,
&spear_dmaengine_pcm_config,
SND_DMAENGINE_PCM_FLAG_NO_DT |
SND_DMAENGINE_PCM_FLAG_COMPAT);
}
static int spear_soc_platform_remove(struct platform_device *pdev)
{
snd_dmaengine_pcm_unregister(&pdev->dev);
return 0;
}
