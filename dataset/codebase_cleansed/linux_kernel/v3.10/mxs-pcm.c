static bool filter(struct dma_chan *chan, void *param)
{
struct mxs_pcm_dma_params *dma_params = param;
if (!mxs_dma_is_apbx(chan))
return false;
if (chan->chan_id != dma_params->chan_num)
return false;
chan->private = &dma_params->dma_data;
return true;
}
int mxs_pcm_platform_register(struct device *dev)
{
return snd_dmaengine_pcm_register(dev, &mxs_dmaengine_pcm_config,
SND_DMAENGINE_PCM_FLAG_NO_RESIDUE |
SND_DMAENGINE_PCM_FLAG_NO_DT |
SND_DMAENGINE_PCM_FLAG_COMPAT |
SND_DMAENGINE_PCM_FLAG_HALF_DUPLEX);
}
void mxs_pcm_platform_unregister(struct device *dev)
{
snd_dmaengine_pcm_unregister(dev);
}
