static void atmel_pcm_dma_irq(u32 ssc_sr,
struct snd_pcm_substream *substream)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct atmel_pcm_dma_params *prtd;
prtd = snd_soc_dai_get_dma_data(rtd->cpu_dai, substream);
if (ssc_sr & prtd->mask->ssc_error) {
if (snd_pcm_running(substream))
pr_warn("atmel-pcm: buffer %s on %s (SSC_SR=%#x)\n",
substream->stream == SNDRV_PCM_STREAM_PLAYBACK
? "underrun" : "overrun", prtd->name,
ssc_sr);
ssc_writex(prtd->ssc->regs, SSC_CR, prtd->mask->ssc_disable);
snd_pcm_stop_xrun(substream);
ssc_readx(prtd->ssc->regs, SSC_RHR);
ssc_readx(prtd->ssc->regs, SSC_SR);
}
}
static int atmel_pcm_configure_dma(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params, struct dma_slave_config *slave_config)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct atmel_pcm_dma_params *prtd;
struct ssc_device *ssc;
int ret;
prtd = snd_soc_dai_get_dma_data(rtd->cpu_dai, substream);
ssc = prtd->ssc;
ret = snd_hwparams_to_dma_slave_config(substream, params, slave_config);
if (ret) {
pr_err("atmel-pcm: hwparams to dma slave configure failed\n");
return ret;
}
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK) {
slave_config->dst_addr = ssc->phybase + SSC_THR;
slave_config->dst_maxburst = 1;
} else {
slave_config->src_addr = ssc->phybase + SSC_RHR;
slave_config->src_maxburst = 1;
}
prtd->dma_intr_handler = atmel_pcm_dma_irq;
return 0;
}
int atmel_pcm_dma_platform_register(struct device *dev)
{
return snd_dmaengine_pcm_register(dev, &atmel_dmaengine_pcm_config,
SND_DMAENGINE_PCM_FLAG_NO_RESIDUE);
}
void atmel_pcm_dma_platform_unregister(struct device *dev)
{
snd_dmaengine_pcm_unregister(dev);
}
