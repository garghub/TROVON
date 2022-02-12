static bool ep93xx_pcm_dma_filter(struct dma_chan *chan, void *filter_param)
{
struct ep93xx_dma_data *data = filter_param;
if (data->direction == ep93xx_dma_chan_direction(chan)) {
chan->private = data;
return true;
}
return false;
}
static struct dma_chan *ep93xx_compat_request_channel(
struct snd_soc_pcm_runtime *rtd,
struct snd_pcm_substream *substream)
{
struct snd_dmaengine_dai_dma_data *dma_data;
dma_data = snd_soc_dai_get_dma_data(rtd->cpu_dai, substream);
return snd_dmaengine_pcm_request_channel(ep93xx_pcm_dma_filter,
dma_data);
}
static int ep93xx_soc_platform_probe(struct platform_device *pdev)
{
return snd_dmaengine_pcm_register(&pdev->dev,
&ep93xx_dmaengine_pcm_config,
SND_DMAENGINE_PCM_FLAG_NO_RESIDUE |
SND_DMAENGINE_PCM_FLAG_NO_DT |
SND_DMAENGINE_PCM_FLAG_COMPAT);
}
static int ep93xx_soc_platform_remove(struct platform_device *pdev)
{
snd_dmaengine_pcm_unregister(&pdev->dev);
return 0;
}
