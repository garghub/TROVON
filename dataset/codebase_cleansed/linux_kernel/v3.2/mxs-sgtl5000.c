static int mxs_sgtl5000_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
struct snd_soc_dai *cpu_dai = rtd->cpu_dai;
unsigned int rate = params_rate(params);
u32 dai_format, mclk;
int ret;
switch (rate) {
case 96000:
mclk = 256 * rate;
break;
default:
mclk = 512 * rate;
break;
}
if (mclk < 8000000 || mclk > 27000000)
return -EINVAL;
ret = snd_soc_dai_set_sysclk(codec_dai, SGTL5000_SYSCLK, mclk, 0);
if (ret)
return ret;
ret = snd_soc_dai_set_sysclk(cpu_dai, MXS_SAIF_MCLK, mclk, 0);
if (ret)
return ret;
dai_format = SND_SOC_DAIFMT_I2S | SND_SOC_DAIFMT_NB_NF |
SND_SOC_DAIFMT_CBS_CFS;
ret = snd_soc_dai_set_fmt(codec_dai, dai_format);
if (ret)
return ret;
ret = snd_soc_dai_set_fmt(cpu_dai, dai_format);
if (ret)
return ret;
return 0;
}
static int __devinit mxs_sgtl5000_probe(struct platform_device *pdev)
{
struct snd_soc_card *card = &mxs_sgtl5000;
int ret;
ret = mxs_saif_get_mclk(0, 44100 * 256, 44100);
if (ret)
return ret;
card->dev = &pdev->dev;
platform_set_drvdata(pdev, card);
ret = snd_soc_register_card(card);
if (ret) {
dev_err(&pdev->dev, "snd_soc_register_card failed (%d)\n",
ret);
return ret;
}
return 0;
}
static int __devexit mxs_sgtl5000_remove(struct platform_device *pdev)
{
struct snd_soc_card *card = platform_get_drvdata(pdev);
mxs_saif_put_mclk(0);
snd_soc_unregister_card(card);
return 0;
}
static int __init mxs_sgtl5000_init(void)
{
return platform_driver_register(&mxs_sgtl5000_audio_driver);
}
static void __exit mxs_sgtl5000_exit(void)
{
platform_driver_unregister(&mxs_sgtl5000_audio_driver);
}
