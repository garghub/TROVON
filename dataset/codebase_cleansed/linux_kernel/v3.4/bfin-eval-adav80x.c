static int bfin_eval_adav80x_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
int ret;
ret = snd_soc_dai_set_pll(codec_dai, ADAV80X_PLL1, ADAV80X_PLL_SRC_XTAL,
27000000, params_rate(params) * 256);
if (ret)
return ret;
ret = snd_soc_dai_set_sysclk(codec_dai, ADAV80X_CLK_PLL1,
params_rate(params) * 256, SND_SOC_CLOCK_IN);
return ret;
}
static int bfin_eval_adav80x_codec_init(struct snd_soc_pcm_runtime *rtd)
{
struct snd_soc_dai *codec_dai = rtd->codec_dai;
snd_soc_dai_set_sysclk(codec_dai, ADAV80X_CLK_SYSCLK1, 0,
SND_SOC_CLOCK_OUT);
snd_soc_dai_set_sysclk(codec_dai, ADAV80X_CLK_SYSCLK2, 0,
SND_SOC_CLOCK_OUT);
snd_soc_dai_set_sysclk(codec_dai, ADAV80X_CLK_SYSCLK3, 0,
SND_SOC_CLOCK_OUT);
snd_soc_dai_set_sysclk(codec_dai, ADAV80X_CLK_XTAL, 2700000, 0);
return 0;
}
static int bfin_eval_adav80x_probe(struct platform_device *pdev)
{
struct snd_soc_card *card = &bfin_eval_adav80x;
const char *codec_name;
switch (platform_get_device_id(pdev)->driver_data) {
case BFIN_EVAL_ADAV801:
codec_name = "spi0.1";
break;
case BFIN_EVAL_ADAV803:
codec_name = "adav803.0-0034";
break;
default:
return -EINVAL;
}
bfin_eval_adav80x_dais[0].codec_name = codec_name;
card->dev = &pdev->dev;
return snd_soc_register_card(&bfin_eval_adav80x);
}
static int __devexit bfin_eval_adav80x_remove(struct platform_device *pdev)
{
struct snd_soc_card *card = platform_get_drvdata(pdev);
snd_soc_unregister_card(card);
return 0;
}
