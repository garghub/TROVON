int tegra_pcm_platform_register(struct device *dev)
{
return snd_dmaengine_pcm_register(dev, &tegra_dmaengine_pcm_config,
SND_DMAENGINE_PCM_FLAG_NO_DT |
SND_DMAENGINE_PCM_FLAG_COMPAT);
}
void tegra_pcm_platform_unregister(struct device *dev)
{
return snd_dmaengine_pcm_unregister(dev);
}
