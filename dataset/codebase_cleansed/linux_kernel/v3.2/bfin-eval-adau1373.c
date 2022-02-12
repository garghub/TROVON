static int bfin_eval_adau1373_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *cpu_dai = rtd->cpu_dai;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
int ret;
int pll_rate;
ret = snd_soc_dai_set_fmt(cpu_dai, SND_SOC_DAIFMT_I2S |
SND_SOC_DAIFMT_NB_NF | SND_SOC_DAIFMT_CBM_CFM);
if (ret)
return ret;
ret = snd_soc_dai_set_fmt(codec_dai, SND_SOC_DAIFMT_I2S |
SND_SOC_DAIFMT_NB_NF | SND_SOC_DAIFMT_CBM_CFM);
if (ret)
return ret;
switch (params_rate(params)) {
case 48000:
case 8000:
case 12000:
case 16000:
case 24000:
case 32000:
pll_rate = 48000 * 1024;
break;
case 44100:
case 7350:
case 11025:
case 14700:
case 22050:
case 29400:
pll_rate = 44100 * 1024;
break;
default:
return -EINVAL;
}
ret = snd_soc_dai_set_pll(codec_dai, ADAU1373_PLL1,
ADAU1373_PLL_SRC_MCLK1, 12288000, pll_rate);
if (ret)
return ret;
ret = snd_soc_dai_set_sysclk(codec_dai, ADAU1373_CLK_SRC_PLL1, pll_rate,
SND_SOC_CLOCK_IN);
return ret;
}
static int bfin_eval_adau1373_codec_init(struct snd_soc_pcm_runtime *rtd)
{
struct snd_soc_dai *codec_dai = rtd->codec_dai;
unsigned int pll_rate = 48000 * 1024;
int ret;
ret = snd_soc_dai_set_pll(codec_dai, ADAU1373_PLL1,
ADAU1373_PLL_SRC_MCLK1, 12288000, pll_rate);
if (ret)
return ret;
ret = snd_soc_dai_set_sysclk(codec_dai, ADAU1373_CLK_SRC_PLL1, pll_rate,
SND_SOC_CLOCK_IN);
return ret;
}
static int bfin_eval_adau1373_probe(struct platform_device *pdev)
{
struct snd_soc_card *card = &bfin_eval_adau1373;
card->dev = &pdev->dev;
return snd_soc_register_card(&bfin_eval_adau1373);
}
static int __devexit bfin_eval_adau1373_remove(struct platform_device *pdev)
{
struct snd_soc_card *card = platform_get_drvdata(pdev);
snd_soc_unregister_card(card);
return 0;
}
static int __init bfin_eval_adau1373_init(void)
{
return platform_driver_register(&bfin_eval_adau1373_driver);
}
static void __exit bfin_eval_adau1373_exit(void)
{
platform_driver_unregister(&bfin_eval_adau1373_driver);
}
