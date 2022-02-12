static int haswell_ssp0_fixup(struct snd_soc_pcm_runtime *rtd,
struct snd_pcm_hw_params *params)
{
struct snd_interval *rate = hw_param_interval(params,
SNDRV_PCM_HW_PARAM_RATE);
struct snd_interval *channels = hw_param_interval(params,
SNDRV_PCM_HW_PARAM_CHANNELS);
rate->min = rate->max = 48000;
channels->min = channels->max = 2;
snd_mask_set(&params->masks[SNDRV_PCM_HW_PARAM_FORMAT -
SNDRV_PCM_HW_PARAM_FIRST_MASK],
SNDRV_PCM_FORMAT_S16_LE);
return 0;
}
static int haswell_rt5640_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
int ret;
ret = snd_soc_dai_set_sysclk(codec_dai, RT5640_SCLK_S_MCLK, 12288000,
SND_SOC_CLOCK_IN);
if (ret < 0) {
dev_err(rtd->dev, "can't set codec sysclk configuration\n");
return ret;
}
snd_soc_update_bits(rtd->codec, 0x83, 0xffff, 0x8000);
return ret;
}
static int haswell_rtd_init(struct snd_soc_pcm_runtime *rtd)
{
struct sst_pdata *pdata = dev_get_platdata(rtd->platform->dev);
struct sst_hsw *haswell = pdata->dsp;
int ret;
ret = sst_hsw_device_set_config(haswell, SST_HSW_DEVICE_SSP_0,
SST_HSW_DEVICE_MCLK_FREQ_24_MHZ,
SST_HSW_DEVICE_CLOCK_MASTER, 9);
if (ret < 0) {
dev_err(rtd->dev, "failed to set device config\n");
return ret;
}
return 0;
}
static int haswell_audio_probe(struct platform_device *pdev)
{
haswell_rt5640.dev = &pdev->dev;
return devm_snd_soc_register_card(&pdev->dev, &haswell_rt5640);
}
