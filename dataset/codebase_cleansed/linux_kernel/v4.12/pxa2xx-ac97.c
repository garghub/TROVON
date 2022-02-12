static void pxa2xx_ac97_warm_reset(struct snd_ac97 *ac97)
{
pxa2xx_ac97_try_warm_reset(ac97);
pxa2xx_ac97_finish_reset(ac97);
}
static void pxa2xx_ac97_cold_reset(struct snd_ac97 *ac97)
{
pxa2xx_ac97_try_cold_reset(ac97);
pxa2xx_ac97_finish_reset(ac97);
}
static int pxa2xx_ac97_hifi_startup(struct snd_pcm_substream *substream,
struct snd_soc_dai *cpu_dai)
{
struct snd_dmaengine_dai_dma_data *dma_data;
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
dma_data = &pxa2xx_ac97_pcm_stereo_out;
else
dma_data = &pxa2xx_ac97_pcm_stereo_in;
snd_soc_dai_set_dma_data(cpu_dai, substream, dma_data);
return 0;
}
static int pxa2xx_ac97_aux_startup(struct snd_pcm_substream *substream,
struct snd_soc_dai *cpu_dai)
{
struct snd_dmaengine_dai_dma_data *dma_data;
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
dma_data = &pxa2xx_ac97_pcm_aux_mono_out;
else
dma_data = &pxa2xx_ac97_pcm_aux_mono_in;
snd_soc_dai_set_dma_data(cpu_dai, substream, dma_data);
return 0;
}
static int pxa2xx_ac97_mic_startup(struct snd_pcm_substream *substream,
struct snd_soc_dai *cpu_dai)
{
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
return -ENODEV;
snd_soc_dai_set_dma_data(cpu_dai, substream,
&pxa2xx_ac97_pcm_mic_mono_in);
return 0;
}
static int pxa2xx_ac97_dev_probe(struct platform_device *pdev)
{
int ret;
if (pdev->id != -1) {
dev_err(&pdev->dev, "PXA2xx has only one AC97 port.\n");
return -ENXIO;
}
ret = pxa2xx_ac97_hw_probe(pdev);
if (ret) {
dev_err(&pdev->dev, "PXA2xx AC97 hw probe error (%d)\n", ret);
return ret;
}
ret = snd_soc_set_ac97_ops(&pxa2xx_ac97_ops);
if (ret != 0)
return ret;
return snd_soc_register_component(&pdev->dev, &pxa_ac97_component,
pxa_ac97_dai_driver, ARRAY_SIZE(pxa_ac97_dai_driver));
}
static int pxa2xx_ac97_dev_remove(struct platform_device *pdev)
{
snd_soc_unregister_component(&pdev->dev);
snd_soc_set_ac97_ops(NULL);
pxa2xx_ac97_hw_remove(pdev);
return 0;
}
static int pxa2xx_ac97_dev_suspend(struct device *dev)
{
return pxa2xx_ac97_hw_suspend();
}
static int pxa2xx_ac97_dev_resume(struct device *dev)
{
return pxa2xx_ac97_hw_resume();
}
