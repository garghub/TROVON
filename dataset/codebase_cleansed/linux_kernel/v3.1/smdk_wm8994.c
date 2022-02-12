static int smdk_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *cpu_dai = rtd->cpu_dai;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
unsigned int pll_out;
int ret;
if (params_format(params) == SNDRV_PCM_FORMAT_S24_LE)
pll_out = params_rate(params) * 384;
else if (params_rate(params) == 8000 || params_rate(params) == 11025)
pll_out = params_rate(params) * 512;
else
pll_out = params_rate(params) * 256;
ret = snd_soc_dai_set_fmt(codec_dai, SND_SOC_DAIFMT_I2S
| SND_SOC_DAIFMT_NB_NF
| SND_SOC_DAIFMT_CBM_CFM);
if (ret < 0)
return ret;
ret = snd_soc_dai_set_fmt(cpu_dai, SND_SOC_DAIFMT_I2S
| SND_SOC_DAIFMT_NB_NF
| SND_SOC_DAIFMT_CBM_CFM);
if (ret < 0)
return ret;
ret = snd_soc_dai_set_pll(codec_dai, WM8994_FLL1, WM8994_FLL_SRC_MCLK1,
SMDK_WM8994_FREQ, pll_out);
if (ret < 0)
return ret;
ret = snd_soc_dai_set_sysclk(codec_dai, WM8994_SYSCLK_FLL1,
pll_out, SND_SOC_CLOCK_IN);
if (ret < 0)
return ret;
return 0;
}
static int smdk_wm8994_init_paiftx(struct snd_soc_pcm_runtime *rtd)
{
struct snd_soc_codec *codec = rtd->codec;
struct snd_soc_dapm_context *dapm = &codec->dapm;
snd_soc_dapm_enable_pin(dapm, "HPOUT1R");
snd_soc_dapm_enable_pin(dapm, "HPOUT1L");
snd_soc_dapm_enable_pin(dapm, "IN1LN");
snd_soc_dapm_enable_pin(dapm, "IN1RN");
snd_soc_dapm_enable_pin(dapm, "IN2LN");
snd_soc_dapm_enable_pin(dapm, "IN2RN");
snd_soc_dapm_nc_pin(dapm, "HPOUT2P");
snd_soc_dapm_nc_pin(dapm, "HPOUT2N");
snd_soc_dapm_nc_pin(dapm, "SPKOUTLN");
snd_soc_dapm_nc_pin(dapm, "SPKOUTLP");
snd_soc_dapm_nc_pin(dapm, "SPKOUTRP");
snd_soc_dapm_nc_pin(dapm, "SPKOUTRN");
snd_soc_dapm_nc_pin(dapm, "LINEOUT1N");
snd_soc_dapm_nc_pin(dapm, "LINEOUT1P");
snd_soc_dapm_nc_pin(dapm, "LINEOUT2N");
snd_soc_dapm_nc_pin(dapm, "LINEOUT2P");
snd_soc_dapm_nc_pin(dapm, "IN1LP");
snd_soc_dapm_nc_pin(dapm, "IN2LP:VXRN");
snd_soc_dapm_nc_pin(dapm, "IN1RP");
snd_soc_dapm_nc_pin(dapm, "IN2RP:VXRP");
snd_soc_dapm_sync(dapm);
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
