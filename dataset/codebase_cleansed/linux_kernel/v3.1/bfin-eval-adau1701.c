static int bfin_eval_adau1701_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *cpu_dai = rtd->cpu_dai;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
int ret;
ret = snd_soc_dai_set_fmt(cpu_dai, SND_SOC_DAIFMT_I2S |
SND_SOC_DAIFMT_NB_NF | SND_SOC_DAIFMT_CBM_CFM);
if (ret)
return ret;
ret = snd_soc_dai_set_fmt(codec_dai, SND_SOC_DAIFMT_I2S |
SND_SOC_DAIFMT_NB_NF | SND_SOC_DAIFMT_CBM_CFM);
if (ret)
return ret;
ret = snd_soc_dai_set_sysclk(codec_dai, ADAU1701_CLK_SRC_OSC, 12288000,
SND_SOC_CLOCK_IN);
return ret;
}
static int bfin_eval_adau1701_probe(struct platform_device *pdev)
{
struct snd_soc_card *card = &bfin_eval_adau1701;
card->dev = &pdev->dev;
return snd_soc_register_card(&bfin_eval_adau1701);
}
static int __devexit bfin_eval_adau1701_remove(struct platform_device *pdev)
{
struct snd_soc_card *card = platform_get_drvdata(pdev);
snd_soc_unregister_card(card);
return 0;
}
static int __init bfin_eval_adau1701_init(void)
{
return platform_driver_register(&bfin_eval_adau1701_driver);
}
static void __exit bfin_eval_adau1701_exit(void)
{
platform_driver_unregister(&bfin_eval_adau1701_driver);
}
