int mxs_pcm_platform_register(struct device *dev)
{
return snd_dmaengine_pcm_register(dev, &mxs_dmaengine_pcm_config,
SND_DMAENGINE_PCM_FLAG_NO_RESIDUE |
SND_DMAENGINE_PCM_FLAG_HALF_DUPLEX);
}
void mxs_pcm_platform_unregister(struct device *dev)
{
snd_dmaengine_pcm_unregister(dev);
}
