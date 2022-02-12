static int skylake_rt286_codec_init(struct snd_soc_pcm_runtime *rtd)
{
struct snd_soc_codec *codec = rtd->codec;
int ret;
ret = snd_soc_card_jack_new(rtd->card, "Headset",
SND_JACK_HEADSET | SND_JACK_BTN_0,
&skylake_headset,
skylake_headset_pins, ARRAY_SIZE(skylake_headset_pins));
if (ret)
return ret;
rt286_mic_detect(codec, &skylake_headset);
return 0;
}
static int skylake_ssp0_fixup(struct snd_soc_pcm_runtime *rtd,
struct snd_pcm_hw_params *params)
{
struct snd_interval *rate = hw_param_interval(params,
SNDRV_PCM_HW_PARAM_RATE);
struct snd_interval *channels = hw_param_interval(params,
SNDRV_PCM_HW_PARAM_CHANNELS);
rate->min = rate->max = 48000;
channels->min = channels->max = 2;
params_set_format(params, SNDRV_PCM_FORMAT_S16_LE);
return 0;
}
static int skylake_rt286_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
int ret;
ret = snd_soc_dai_set_sysclk(codec_dai, RT286_SCLK_S_PLL, 24000000,
SND_SOC_CLOCK_IN);
if (ret < 0)
dev_err(rtd->dev, "set codec sysclk failed: %d\n", ret);
return ret;
}
static int skylake_audio_probe(struct platform_device *pdev)
{
skylake_rt286.dev = &pdev->dev;
return devm_snd_soc_register_card(&pdev->dev, &skylake_rt286);
}
