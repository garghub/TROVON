static int evm_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
struct snd_soc_dai *cpu_dai = rtd->cpu_dai;
int ret = 0;
unsigned sysclk;
if (machine_is_davinci_dm355_evm() || machine_is_davinci_dm6467_evm() ||
machine_is_davinci_dm365_evm())
sysclk = 27000000;
else if (machine_is_davinci_evm())
sysclk = 12288000;
else if (machine_is_davinci_da830_evm() ||
machine_is_davinci_da850_evm())
sysclk = 24576000;
else
return -EINVAL;
ret = snd_soc_dai_set_fmt(codec_dai, AUDIO_FORMAT);
if (ret < 0)
return ret;
ret = snd_soc_dai_set_fmt(cpu_dai, AUDIO_FORMAT);
if (ret < 0)
return ret;
ret = snd_soc_dai_set_sysclk(codec_dai, 0, sysclk, SND_SOC_CLOCK_OUT);
if (ret < 0)
return ret;
ret = snd_soc_dai_set_sysclk(cpu_dai, 0, sysclk, SND_SOC_CLOCK_OUT);
if (ret < 0)
return ret;
return 0;
}
static int evm_spdif_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *cpu_dai = rtd->cpu_dai;
return snd_soc_dai_set_fmt(cpu_dai, AUDIO_FORMAT);
}
static int evm_aic3x_init(struct snd_soc_pcm_runtime *rtd)
{
struct snd_soc_codec *codec = rtd->codec;
struct snd_soc_dapm_context *dapm = &codec->dapm;
snd_soc_dapm_new_controls(dapm, aic3x_dapm_widgets,
ARRAY_SIZE(aic3x_dapm_widgets));
snd_soc_dapm_add_routes(dapm, audio_map, ARRAY_SIZE(audio_map));
snd_soc_dapm_disable_pin(dapm, "MONO_LOUT");
snd_soc_dapm_disable_pin(dapm, "HPLCOM");
snd_soc_dapm_disable_pin(dapm, "HPRCOM");
snd_soc_dapm_enable_pin(dapm, "Headphone Jack");
snd_soc_dapm_enable_pin(dapm, "Line Out");
snd_soc_dapm_enable_pin(dapm, "Mic Jack");
snd_soc_dapm_enable_pin(dapm, "Line In");
return 0;
}
static int __init evm_init(void)
{
struct snd_soc_card *evm_snd_dev_data;
int index;
int ret;
if (machine_is_davinci_evm()) {
evm_snd_dev_data = &dm6446_snd_soc_card_evm;
index = 0;
} else if (machine_is_davinci_dm355_evm()) {
evm_snd_dev_data = &dm355_snd_soc_card_evm;
index = 1;
} else if (machine_is_davinci_dm365_evm()) {
evm_snd_dev_data = &dm365_snd_soc_card_evm;
index = 0;
} else if (machine_is_davinci_dm6467_evm()) {
evm_snd_dev_data = &dm6467_snd_soc_card_evm;
index = 0;
} else if (machine_is_davinci_da830_evm()) {
evm_snd_dev_data = &da830_snd_soc_card;
index = 1;
} else if (machine_is_davinci_da850_evm()) {
evm_snd_dev_data = &da850_snd_soc_card;
index = 0;
} else
return -EINVAL;
evm_snd_device = platform_device_alloc("soc-audio", index);
if (!evm_snd_device)
return -ENOMEM;
platform_set_drvdata(evm_snd_device, evm_snd_dev_data);
ret = platform_device_add(evm_snd_device);
if (ret)
platform_device_put(evm_snd_device);
return ret;
}
static void __exit evm_exit(void)
{
platform_device_unregister(evm_snd_device);
}
