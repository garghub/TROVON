static int pxa2xx_pcm_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_dmaengine_dai_dma_data *dma;
dma = snd_soc_dai_get_dma_data(rtd->cpu_dai, substream);
if (!dma)
return 0;
return __pxa2xx_pcm_hw_params(substream, params);
}
static int pxa2xx_pcm_hw_free(struct snd_pcm_substream *substream)
{
__pxa2xx_pcm_hw_free(substream);
return 0;
}
static int pxa2xx_soc_pcm_new(struct snd_soc_pcm_runtime *rtd)
{
struct snd_card *card = rtd->card->snd_card;
struct snd_pcm *pcm = rtd->pcm;
int ret;
ret = dma_coerce_mask_and_coherent(card->dev, DMA_BIT_MASK(32));
if (ret)
return ret;
if (pcm->streams[SNDRV_PCM_STREAM_PLAYBACK].substream) {
ret = pxa2xx_pcm_preallocate_dma_buffer(pcm,
SNDRV_PCM_STREAM_PLAYBACK);
if (ret)
goto out;
}
if (pcm->streams[SNDRV_PCM_STREAM_CAPTURE].substream) {
ret = pxa2xx_pcm_preallocate_dma_buffer(pcm,
SNDRV_PCM_STREAM_CAPTURE);
if (ret)
goto out;
}
out:
return ret;
}
static int pxa2xx_soc_platform_probe(struct platform_device *pdev)
{
return devm_snd_soc_register_platform(&pdev->dev, &pxa2xx_soc_platform);
}
