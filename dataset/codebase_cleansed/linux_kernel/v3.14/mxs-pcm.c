int mxs_pcm_platform_register(struct device *dev)
{
return devm_snd_dmaengine_pcm_register(dev, &mxs_dmaengine_pcm_config,
SND_DMAENGINE_PCM_FLAG_HALF_DUPLEX);
}
