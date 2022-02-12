static int smdk_wm8580_pcm_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
struct snd_soc_dai *cpu_dai = rtd->cpu_dai;
int rfs, ret;
switch (params_rate(params)) {
case 8000:
break;
default:
printk(KERN_ERR "%s:%d Sampling Rate %u not supported!\n",
__func__, __LINE__, params_rate(params));
return -EINVAL;
}
rfs = mclk_freq / params_rate(params) / 2;
ret = snd_soc_dai_set_fmt(codec_dai, SND_SOC_DAIFMT_DSP_B
| SND_SOC_DAIFMT_IB_NF
| SND_SOC_DAIFMT_CBS_CFS);
if (ret < 0)
return ret;
ret = snd_soc_dai_set_fmt(cpu_dai, SND_SOC_DAIFMT_DSP_B
| SND_SOC_DAIFMT_IB_NF
| SND_SOC_DAIFMT_CBS_CFS);
if (ret < 0)
return ret;
if (mclk_freq == xtal_freq) {
ret = snd_soc_dai_set_sysclk(codec_dai, WM8580_CLKSRC_MCLK,
mclk_freq, SND_SOC_CLOCK_IN);
if (ret < 0)
return ret;
ret = snd_soc_dai_set_clkdiv(codec_dai, WM8580_MCLK,
WM8580_CLKSRC_MCLK);
if (ret < 0)
return ret;
} else {
ret = snd_soc_dai_set_sysclk(codec_dai, WM8580_CLKSRC_PLLA,
mclk_freq, SND_SOC_CLOCK_IN);
if (ret < 0)
return ret;
ret = snd_soc_dai_set_clkdiv(codec_dai, WM8580_MCLK,
WM8580_CLKSRC_PLLA);
if (ret < 0)
return ret;
ret = snd_soc_dai_set_pll(codec_dai, WM8580_PLLA, 0,
xtal_freq, mclk_freq);
if (ret < 0)
return ret;
}
ret = snd_soc_dai_set_sysclk(cpu_dai, S3C_PCM_CLKSRC_MUX,
mclk_freq, SND_SOC_CLOCK_IN);
if (ret < 0)
return ret;
ret = snd_soc_dai_set_clkdiv(cpu_dai, S3C_PCM_SCLK_PER_FS, rfs);
if (ret < 0)
return ret;
return 0;
}
static int snd_smdk_probe(struct platform_device *pdev)
{
int ret = 0;
xtal_freq = SMDK_WM8580_EXT_OSC;
mclk_freq = SMDK_WM8580_EXT_MCLK;
if (machine_is_smdkc110() || machine_is_smdkv210())
xtal_freq = mclk_freq = SMDK_WM8580_EXT_VOICE;
smdk_pcm.dev = &pdev->dev;
ret = devm_snd_soc_register_card(&pdev->dev, &smdk_pcm);
if (ret)
dev_err(&pdev->dev, "snd_soc_register_card failed %d\n", ret);
return ret;
}
