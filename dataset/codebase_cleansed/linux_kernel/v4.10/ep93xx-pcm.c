static bool ep93xx_pcm_dma_filter(struct dma_chan *chan, void *filter_param)
{
struct ep93xx_dma_data *data = filter_param;
if (data->direction == ep93xx_dma_chan_direction(chan)) {
chan->private = data;
return true;
}
return false;
}
int devm_ep93xx_pcm_platform_register(struct device *dev)
{
return devm_snd_dmaengine_pcm_register(dev,
&ep93xx_dmaengine_pcm_config,
SND_DMAENGINE_PCM_FLAG_NO_DT |
SND_DMAENGINE_PCM_FLAG_COMPAT);
}
