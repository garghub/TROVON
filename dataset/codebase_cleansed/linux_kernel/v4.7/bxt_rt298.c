static int broxton_rt298_codec_init(struct snd_soc_pcm_runtime *rtd)
{
struct snd_soc_codec *codec = rtd->codec;
int ret = 0;
ret = snd_soc_card_jack_new(rtd->card, "Headset",
SND_JACK_HEADSET | SND_JACK_BTN_0,
&broxton_headset,
broxton_headset_pins, ARRAY_SIZE(broxton_headset_pins));
if (ret)
return ret;
rt298_mic_detect(codec, &broxton_headset);
return 0;
}
static int broxton_hdmi_init(struct snd_soc_pcm_runtime *rtd)
{
struct snd_soc_dai *dai = rtd->codec_dai;
return hdac_hdmi_jack_init(dai, BXT_DPCM_AUDIO_HDMI1_PB + dai->id);
}
static int broxton_ssp5_fixup(struct snd_soc_pcm_runtime *rtd,
struct snd_pcm_hw_params *params)
{
struct snd_interval *rate = hw_param_interval(params,
SNDRV_PCM_HW_PARAM_RATE);
struct snd_interval *channels = hw_param_interval(params,
SNDRV_PCM_HW_PARAM_CHANNELS);
struct snd_mask *fmt = hw_param_mask(params, SNDRV_PCM_HW_PARAM_FORMAT);
rate->min = rate->max = 48000;
channels->min = channels->max = 2;
snd_mask_none(fmt);
snd_mask_set(fmt, SNDRV_PCM_FORMAT_S24_LE);
return 0;
}
static int broxton_rt298_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
int ret;
ret = snd_soc_dai_set_sysclk(codec_dai, RT298_SCLK_S_PLL,
19200000, SND_SOC_CLOCK_IN);
if (ret < 0) {
dev_err(rtd->dev, "can't set codec sysclk configuration\n");
return ret;
}
return ret;
}
static int broxton_audio_probe(struct platform_device *pdev)
{
broxton_rt298.dev = &pdev->dev;
return devm_snd_soc_register_card(&pdev->dev, &broxton_rt298);
}
