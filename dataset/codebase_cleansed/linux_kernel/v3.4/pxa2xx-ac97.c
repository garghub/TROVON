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
static int pxa2xx_ac97_suspend(struct snd_soc_dai *dai)
{
return pxa2xx_ac97_hw_suspend();
}
static int pxa2xx_ac97_resume(struct snd_soc_dai *dai)
{
return pxa2xx_ac97_hw_resume();
}
static int __devinit pxa2xx_ac97_probe(struct snd_soc_dai *dai)
{
return pxa2xx_ac97_hw_probe(to_platform_device(dai->dev));
}
static int pxa2xx_ac97_remove(struct snd_soc_dai *dai)
{
pxa2xx_ac97_hw_remove(to_platform_device(dai->dev));
return 0;
}
static int pxa2xx_ac97_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *cpu_dai)
{
struct pxa2xx_pcm_dma_params *dma_data;
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
dma_data = &pxa2xx_ac97_pcm_stereo_out;
else
dma_data = &pxa2xx_ac97_pcm_stereo_in;
snd_soc_dai_set_dma_data(cpu_dai, substream, dma_data);
return 0;
}
static int pxa2xx_ac97_hw_aux_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *cpu_dai)
{
struct pxa2xx_pcm_dma_params *dma_data;
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
dma_data = &pxa2xx_ac97_pcm_aux_mono_out;
else
dma_data = &pxa2xx_ac97_pcm_aux_mono_in;
snd_soc_dai_set_dma_data(cpu_dai, substream, dma_data);
return 0;
}
static int pxa2xx_ac97_hw_mic_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *cpu_dai)
{
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
return -ENODEV;
else
snd_soc_dai_set_dma_data(cpu_dai, substream,
&pxa2xx_ac97_pcm_mic_mono_in);
return 0;
}
static __devinit int pxa2xx_ac97_dev_probe(struct platform_device *pdev)
{
if (pdev->id != -1) {
dev_err(&pdev->dev, "PXA2xx has only one AC97 port.\n");
return -ENXIO;
}
return snd_soc_register_dais(&pdev->dev, pxa_ac97_dai_driver,
ARRAY_SIZE(pxa_ac97_dai_driver));
}
static int __devexit pxa2xx_ac97_dev_remove(struct platform_device *pdev)
{
snd_soc_unregister_dais(&pdev->dev, ARRAY_SIZE(pxa_ac97_dai_driver));
return 0;
}
