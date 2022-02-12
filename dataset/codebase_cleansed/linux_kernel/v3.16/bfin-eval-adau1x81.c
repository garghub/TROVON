static int bfin_eval_adau1x81_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
int pll_rate;
int ret;
switch (params_rate(params)) {
case 48000:
case 8000:
case 12000:
case 16000:
case 24000:
case 32000:
case 96000:
pll_rate = 48000 * 1024;
break;
case 44100:
case 7350:
case 11025:
case 14700:
case 22050:
case 29400:
case 88200:
pll_rate = 44100 * 1024;
break;
default:
return -EINVAL;
}
ret = snd_soc_dai_set_pll(codec_dai, ADAU17X1_PLL,
ADAU17X1_PLL_SRC_MCLK, 12288000, pll_rate);
if (ret)
return ret;
ret = snd_soc_dai_set_sysclk(codec_dai, ADAU17X1_CLK_SRC_PLL, pll_rate,
SND_SOC_CLOCK_IN);
return ret;
}
static int bfin_eval_adau1x81_probe(struct platform_device *pdev)
{
bfin_eval_adau1x81.dev = &pdev->dev;
return devm_snd_soc_register_card(&pdev->dev, &bfin_eval_adau1x81);
}
