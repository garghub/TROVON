static int bells_set_bias_level(struct snd_soc_card *card,
struct snd_soc_dapm_context *dapm,
enum snd_soc_bias_level level)
{
struct snd_soc_pcm_runtime *rtd;
struct snd_soc_dai *codec_dai;
struct snd_soc_codec *codec;
struct bells_drvdata *bells = card->drvdata;
int ret;
rtd = snd_soc_get_pcm_runtime(card, card->dai_link[DAI_DSP_CODEC].name);
codec_dai = rtd->codec_dai;
codec = codec_dai->codec;
if (dapm->dev != codec_dai->dev)
return 0;
switch (level) {
case SND_SOC_BIAS_PREPARE:
if (dapm->bias_level != SND_SOC_BIAS_STANDBY)
break;
ret = snd_soc_codec_set_pll(codec, WM5102_FLL1,
ARIZONA_FLL_SRC_MCLK1,
MCLK_RATE,
bells->sysclk_rate);
if (ret < 0)
pr_err("Failed to start FLL: %d\n", ret);
if (bells->asyncclk_rate) {
ret = snd_soc_codec_set_pll(codec, WM5102_FLL2,
ARIZONA_FLL_SRC_AIF2BCLK,
BCLK2_RATE,
bells->asyncclk_rate);
if (ret < 0)
pr_err("Failed to start FLL: %d\n", ret);
}
break;
default:
break;
}
return 0;
}
static int bells_set_bias_level_post(struct snd_soc_card *card,
struct snd_soc_dapm_context *dapm,
enum snd_soc_bias_level level)
{
struct snd_soc_pcm_runtime *rtd;
struct snd_soc_dai *codec_dai;
struct snd_soc_codec *codec;
struct bells_drvdata *bells = card->drvdata;
int ret;
rtd = snd_soc_get_pcm_runtime(card, card->dai_link[DAI_DSP_CODEC].name);
codec_dai = rtd->codec_dai;
codec = codec_dai->codec;
if (dapm->dev != codec_dai->dev)
return 0;
switch (level) {
case SND_SOC_BIAS_STANDBY:
ret = snd_soc_codec_set_pll(codec, WM5102_FLL1, 0, 0, 0);
if (ret < 0) {
pr_err("Failed to stop FLL: %d\n", ret);
return ret;
}
if (bells->asyncclk_rate) {
ret = snd_soc_codec_set_pll(codec, WM5102_FLL2,
0, 0, 0);
if (ret < 0) {
pr_err("Failed to stop FLL: %d\n", ret);
return ret;
}
}
break;
default:
break;
}
dapm->bias_level = level;
return 0;
}
static int bells_late_probe(struct snd_soc_card *card)
{
struct bells_drvdata *bells = card->drvdata;
struct snd_soc_pcm_runtime *rtd;
struct snd_soc_codec *wm0010;
struct snd_soc_codec *codec;
struct snd_soc_dai *aif1_dai;
struct snd_soc_dai *aif2_dai;
struct snd_soc_dai *aif3_dai;
struct snd_soc_dai *wm9081_dai;
int ret;
rtd = snd_soc_get_pcm_runtime(card, card->dai_link[DAI_AP_DSP].name);
wm0010 = rtd->codec;
rtd = snd_soc_get_pcm_runtime(card, card->dai_link[DAI_DSP_CODEC].name);
codec = rtd->codec;
aif1_dai = rtd->codec_dai;
ret = snd_soc_codec_set_sysclk(codec, ARIZONA_CLK_SYSCLK,
ARIZONA_CLK_SRC_FLL1,
bells->sysclk_rate,
SND_SOC_CLOCK_IN);
if (ret != 0) {
dev_err(codec->dev, "Failed to set SYSCLK: %d\n", ret);
return ret;
}
ret = snd_soc_codec_set_sysclk(wm0010, 0, 0, SYS_MCLK_RATE, 0);
if (ret != 0) {
dev_err(wm0010->dev, "Failed to set WM0010 clock: %d\n", ret);
return ret;
}
ret = snd_soc_dai_set_sysclk(aif1_dai, ARIZONA_CLK_SYSCLK, 0, 0);
if (ret != 0)
dev_err(aif1_dai->dev, "Failed to set AIF1 clock: %d\n", ret);
ret = snd_soc_codec_set_sysclk(codec, ARIZONA_CLK_OPCLK, 0,
SYS_MCLK_RATE, SND_SOC_CLOCK_OUT);
if (ret != 0)
dev_err(codec->dev, "Failed to set OPCLK: %d\n", ret);
if (card->num_rtd == DAI_CODEC_CP)
return 0;
ret = snd_soc_codec_set_sysclk(codec, ARIZONA_CLK_ASYNCCLK,
ARIZONA_CLK_SRC_FLL2,
bells->asyncclk_rate,
SND_SOC_CLOCK_IN);
if (ret != 0) {
dev_err(codec->dev, "Failed to set ASYNCCLK: %d\n", ret);
return ret;
}
rtd = snd_soc_get_pcm_runtime(card, card->dai_link[DAI_CODEC_CP].name);
aif2_dai = rtd->cpu_dai;
ret = snd_soc_dai_set_sysclk(aif2_dai, ARIZONA_CLK_ASYNCCLK, 0, 0);
if (ret != 0) {
dev_err(aif2_dai->dev, "Failed to set AIF2 clock: %d\n", ret);
return ret;
}
if (card->num_rtd == DAI_CODEC_SUB)
return 0;
rtd = snd_soc_get_pcm_runtime(card, card->dai_link[DAI_CODEC_SUB].name);
aif3_dai = rtd->cpu_dai;
wm9081_dai = rtd->codec_dai;
ret = snd_soc_dai_set_sysclk(aif3_dai, ARIZONA_CLK_SYSCLK, 0, 0);
if (ret != 0) {
dev_err(aif1_dai->dev, "Failed to set AIF1 clock: %d\n", ret);
return ret;
}
ret = snd_soc_codec_set_sysclk(wm9081_dai->codec, WM9081_SYSCLK_MCLK,
0, SYS_MCLK_RATE, 0);
if (ret != 0) {
dev_err(wm9081_dai->dev, "Failed to set MCLK: %d\n", ret);
return ret;
}
return 0;
}
static int bells_probe(struct platform_device *pdev)
{
int ret;
bells_cards[pdev->id].dev = &pdev->dev;
ret = devm_snd_soc_register_card(&pdev->dev, &bells_cards[pdev->id]);
if (ret)
dev_err(&pdev->dev,
"snd_soc_register_card(%s) failed: %d\n",
bells_cards[pdev->id].name, ret);
return ret;
}
