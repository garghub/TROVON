static int saarb_i2s_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
struct snd_soc_dai *cpu_dai = rtd->cpu_dai;
int width = snd_pcm_format_physical_width(params_format(params));
int ret;
ret = snd_soc_dai_set_sysclk(cpu_dai, PXA_SSP_CLK_NET_PLL, 0,
PM860X_CLK_DIR_OUT);
if (ret < 0)
return ret;
ret = snd_soc_dai_set_sysclk(codec_dai, 0, 0, PM860X_CLK_DIR_OUT);
if (ret < 0)
return ret;
ret = snd_soc_dai_set_tdm_slot(cpu_dai, 3, 3, 2, width);
return ret;
}
static int saarb_pm860x_init(struct snd_soc_pcm_runtime *rtd)
{
struct snd_soc_codec *codec = rtd->codec;
struct snd_soc_dapm_context *dapm = &codec->dapm;
snd_soc_dapm_enable_pin(dapm, "Ext Speaker");
snd_soc_dapm_enable_pin(dapm, "Ext Mic 1");
snd_soc_dapm_enable_pin(dapm, "Ext Mic 3");
snd_soc_dapm_disable_pin(dapm, "Headset Mic 2");
snd_soc_dapm_disable_pin(dapm, "Headset Stereophone");
snd_soc_jack_new(codec, "Headphone Jack", SND_JACK_HEADPHONE
| SND_JACK_BTN_0 | SND_JACK_BTN_1 | SND_JACK_BTN_2,
&hs_jack);
snd_soc_jack_add_pins(&hs_jack, ARRAY_SIZE(hs_jack_pins),
hs_jack_pins);
snd_soc_jack_new(codec, "Microphone Jack", SND_JACK_MICROPHONE,
&mic_jack);
snd_soc_jack_add_pins(&mic_jack, ARRAY_SIZE(mic_jack_pins),
mic_jack_pins);
pm860x_hs_jack_detect(codec, &hs_jack, SND_JACK_HEADPHONE,
SND_JACK_BTN_0, SND_JACK_BTN_1, SND_JACK_BTN_2);
pm860x_mic_jack_detect(codec, &hs_jack, SND_JACK_MICROPHONE);
return 0;
}
static int __init saarb_init(void)
{
int ret;
if (!machine_is_saarb())
return -ENODEV;
saarb_snd_device = platform_device_alloc("soc-audio", -1);
if (!saarb_snd_device)
return -ENOMEM;
platform_set_drvdata(saarb_snd_device, &snd_soc_card_saarb);
ret = platform_device_add(saarb_snd_device);
if (ret)
platform_device_put(saarb_snd_device);
return ret;
}
static void __exit saarb_exit(void)
{
platform_device_unregister(saarb_snd_device);
}
