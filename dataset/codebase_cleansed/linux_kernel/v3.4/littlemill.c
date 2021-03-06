static int littlemill_set_bias_level(struct snd_soc_card *card,
struct snd_soc_dapm_context *dapm,
enum snd_soc_bias_level level)
{
struct snd_soc_dai *codec_dai = card->rtd[0].codec_dai;
int ret;
if (dapm->dev != codec_dai->dev)
return 0;
switch (level) {
case SND_SOC_BIAS_PREPARE:
if (dapm->bias_level == SND_SOC_BIAS_STANDBY) {
ret = snd_soc_dai_set_pll(codec_dai, WM8994_FLL1,
WM8994_FLL_SRC_MCLK2, 32768,
sample_rate * 512);
if (ret < 0) {
pr_err("Failed to start FLL: %d\n", ret);
return ret;
}
ret = snd_soc_dai_set_sysclk(codec_dai,
WM8994_SYSCLK_FLL1,
sample_rate * 512,
SND_SOC_CLOCK_IN);
if (ret < 0) {
pr_err("Failed to set SYSCLK: %d\n", ret);
return ret;
}
}
break;
default:
break;
}
return 0;
}
static int littlemill_set_bias_level_post(struct snd_soc_card *card,
struct snd_soc_dapm_context *dapm,
enum snd_soc_bias_level level)
{
struct snd_soc_dai *codec_dai = card->rtd[0].codec_dai;
int ret;
if (dapm->dev != codec_dai->dev)
return 0;
switch (level) {
case SND_SOC_BIAS_STANDBY:
ret = snd_soc_dai_set_sysclk(codec_dai, WM8994_SYSCLK_MCLK2,
32768, SND_SOC_CLOCK_IN);
if (ret < 0) {
pr_err("Failed to switch away from FLL: %d\n", ret);
return ret;
}
ret = snd_soc_dai_set_pll(codec_dai, WM8994_FLL1,
0, 0, 0);
if (ret < 0) {
pr_err("Failed to stop FLL: %d\n", ret);
return ret;
}
break;
default:
break;
}
dapm->bias_level = level;
return 0;
}
static int littlemill_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
int ret;
sample_rate = params_rate(params);
ret = snd_soc_dai_set_pll(codec_dai, WM8994_FLL1,
WM8994_FLL_SRC_MCLK2, 32768,
sample_rate * 512);
if (ret < 0) {
pr_err("Failed to start FLL: %d\n", ret);
return ret;
}
ret = snd_soc_dai_set_sysclk(codec_dai,
WM8994_SYSCLK_FLL1,
sample_rate * 512,
SND_SOC_CLOCK_IN);
if (ret < 0) {
pr_err("Failed to set SYSCLK: %d\n", ret);
return ret;
}
return 0;
}
static int littlemill_late_probe(struct snd_soc_card *card)
{
struct snd_soc_codec *codec = card->rtd[0].codec;
struct snd_soc_dai *codec_dai = card->rtd[0].codec_dai;
int ret;
ret = snd_soc_dai_set_sysclk(codec_dai, WM8994_SYSCLK_MCLK2,
32768, SND_SOC_CLOCK_IN);
if (ret < 0)
return ret;
ret = snd_soc_jack_new(codec, "Headset",
SND_JACK_HEADSET | SND_JACK_MECHANICAL |
SND_JACK_BTN_0 | SND_JACK_BTN_1 |
SND_JACK_BTN_2 | SND_JACK_BTN_3 |
SND_JACK_BTN_4 | SND_JACK_BTN_5,
&littlemill_headset);
if (ret)
return ret;
wm8958_mic_detect(codec, &littlemill_headset, NULL, NULL);
wm8994_mic_detect(codec, &littlemill_headset, 1);
return 0;
}
static __devinit int littlemill_probe(struct platform_device *pdev)
{
struct snd_soc_card *card = &littlemill;
int ret;
card->dev = &pdev->dev;
ret = snd_soc_register_card(card);
if (ret) {
dev_err(&pdev->dev, "snd_soc_register_card() failed: %d\n",
ret);
return ret;
}
return 0;
}
static int __devexit littlemill_remove(struct platform_device *pdev)
{
struct snd_soc_card *card = platform_get_drvdata(pdev);
snd_soc_unregister_card(card);
return 0;
}
