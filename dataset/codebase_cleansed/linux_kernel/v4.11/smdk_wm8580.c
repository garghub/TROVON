static int smdk_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
unsigned int pll_out;
int rfs, ret;
switch (params_width(params)) {
case 8:
case 16:
break;
default:
return -EINVAL;
}
switch (params_rate(params)) {
case 16000:
case 22050:
case 32000:
case 44100:
case 48000:
case 88200:
case 96000:
rfs = 256;
break;
case 64000:
rfs = 384;
break;
case 8000:
case 11025:
rfs = 512;
break;
default:
return -EINVAL;
}
pll_out = params_rate(params) * rfs;
ret = snd_soc_dai_set_clkdiv(codec_dai, WM8580_MCLK,
WM8580_CLKSRC_PLLA);
if (ret < 0)
return ret;
ret = snd_soc_dai_set_pll(codec_dai, WM8580_PLLA, 0,
SMDK_WM8580_FREQ, pll_out);
if (ret < 0)
return ret;
ret = snd_soc_dai_set_sysclk(codec_dai, WM8580_CLKSRC_PLLA,
pll_out, SND_SOC_CLOCK_IN);
if (ret < 0)
return ret;
return 0;
}
static int smdk_wm8580_init_paiftx(struct snd_soc_pcm_runtime *rtd)
{
snd_soc_dapm_disable_pin(&rtd->card->dapm, "MicIn");
return 0;
}
static int __init smdk_audio_init(void)
{
int ret;
smdk_snd_device = platform_device_alloc("soc-audio", -1);
if (!smdk_snd_device)
return -ENOMEM;
platform_set_drvdata(smdk_snd_device, &smdk);
ret = platform_device_add(smdk_snd_device);
if (ret)
platform_device_put(smdk_snd_device);
return ret;
}
static void __exit smdk_audio_exit(void)
{
platform_device_unregister(smdk_snd_device);
}
