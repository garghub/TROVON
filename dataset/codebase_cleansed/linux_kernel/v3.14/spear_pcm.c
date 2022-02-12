int devm_spear_pcm_platform_register(struct device *dev,
struct snd_dmaengine_pcm_config *config,
bool (*filter)(struct dma_chan *chan, void *slave))
{
*config = spear_dmaengine_pcm_config;
config->compat_filter_fn = filter;
return snd_dmaengine_pcm_register(dev, config,
SND_DMAENGINE_PCM_FLAG_NO_DT |
SND_DMAENGINE_PCM_FLAG_COMPAT);
}
