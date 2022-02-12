static int goni_wm8994_init(struct snd_soc_pcm_runtime *rtd)
{
struct snd_soc_codec *codec = rtd->codec;
struct snd_soc_dapm_context *dapm = &codec->dapm;
int ret;
snd_soc_dapm_nc_pin(dapm, "IN2LP:VXRN");
snd_soc_dapm_nc_pin(dapm, "IN2RP:VXRP");
snd_soc_dapm_nc_pin(dapm, "LINEOUT1N");
snd_soc_dapm_nc_pin(dapm, "LINEOUT1P");
snd_soc_dapm_nc_pin(dapm, "LINEOUT2N");
snd_soc_dapm_nc_pin(dapm, "LINEOUT2P");
if (machine_is_aquila()) {
snd_soc_dapm_nc_pin(dapm, "SPKOUTRN");
snd_soc_dapm_nc_pin(dapm, "SPKOUTRP");
}
ret = snd_soc_jack_new(codec, "Headset Jack",
SND_JACK_HEADSET | SND_JACK_MECHANICAL | SND_JACK_AVOUT,
&jack);
if (ret)
return ret;
ret = snd_soc_jack_add_pins(&jack, ARRAY_SIZE(jack_pins), jack_pins);
if (ret)
return ret;
ret = snd_soc_jack_add_gpios(&jack, ARRAY_SIZE(jack_gpios), jack_gpios);
if (ret)
return ret;
return 0;
}
static int goni_hifi_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
struct snd_soc_dai *cpu_dai = rtd->cpu_dai;
unsigned int pll_out = 24000000;
int ret = 0;
ret = snd_soc_dai_set_fmt(cpu_dai, SND_SOC_DAIFMT_I2S |
SND_SOC_DAIFMT_NB_NF | SND_SOC_DAIFMT_CBM_CFM);
if (ret < 0)
return ret;
ret = snd_soc_dai_set_fmt(codec_dai, SND_SOC_DAIFMT_I2S |
SND_SOC_DAIFMT_NB_NF | SND_SOC_DAIFMT_CBM_CFM);
if (ret < 0)
return ret;
ret = snd_soc_dai_set_pll(codec_dai, WM8994_FLL1, 0, pll_out,
params_rate(params) * 256);
if (ret < 0)
return ret;
ret = snd_soc_dai_set_sysclk(codec_dai, WM8994_SYSCLK_FLL1,
params_rate(params) * 256, SND_SOC_CLOCK_IN);
if (ret < 0)
return ret;
return 0;
}
static int goni_voice_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
unsigned int pll_out = 24000000;
int ret = 0;
if (params_rate(params) != 8000)
return -EINVAL;
ret = snd_soc_dai_set_fmt(codec_dai, SND_SOC_DAIFMT_LEFT_J |
SND_SOC_DAIFMT_IB_IF | SND_SOC_DAIFMT_CBM_CFM);
if (ret < 0)
return ret;
ret = snd_soc_dai_set_pll(codec_dai, WM8994_FLL2, 0, pll_out,
params_rate(params) * 256);
if (ret < 0)
return ret;
ret = snd_soc_dai_set_sysclk(codec_dai, WM8994_SYSCLK_FLL2,
params_rate(params) * 256, SND_SOC_CLOCK_IN);
if (ret < 0)
return ret;
return 0;
}
static int __init goni_init(void)
{
int ret;
if (machine_is_aquila()) {
voice_dai.name = aquila_str[CPU_VOICE_DAI];
goni_dai[1].cpu_dai_name = aquila_str[CPU_VOICE_DAI];
goni.name = aquila_str[MACHINE_NAME];
} else if (!machine_is_goni())
return -ENODEV;
goni_snd_device = platform_device_alloc("soc-audio", -1);
if (!goni_snd_device)
return -ENOMEM;
ret = snd_soc_register_component(&goni_snd_device->dev, &voice_component,
&voice_dai, 1);
if (ret) {
platform_device_put(goni_snd_device);
return ret;
}
platform_set_drvdata(goni_snd_device, &goni);
ret = platform_device_add(goni_snd_device);
if (ret) {
snd_soc_unregister_component(&goni_snd_device->dev);
platform_device_put(goni_snd_device);
}
return ret;
}
static void __exit goni_exit(void)
{
snd_soc_unregister_component(&goni_snd_device->dev);
platform_device_unregister(goni_snd_device);
}
