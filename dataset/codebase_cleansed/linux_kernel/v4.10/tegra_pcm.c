int tegra_pcm_platform_register(struct device *dev)
{
return snd_dmaengine_pcm_register(dev, &tegra_dmaengine_pcm_config, 0);
}
int tegra_pcm_platform_register_with_chan_names(struct device *dev,
struct snd_dmaengine_pcm_config *config,
char *txdmachan, char *rxdmachan)
{
*config = tegra_dmaengine_pcm_config;
config->dma_dev = dev->parent;
config->chan_names[0] = txdmachan;
config->chan_names[1] = rxdmachan;
return snd_dmaengine_pcm_register(dev, config, 0);
}
void tegra_pcm_platform_unregister(struct device *dev)
{
return snd_dmaengine_pcm_unregister(dev);
}
