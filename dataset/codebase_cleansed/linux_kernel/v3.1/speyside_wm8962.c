static int speyside_wm8962_set_bias_level(struct snd_soc_card *card,
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
ret = snd_soc_dai_set_pll(codec_dai, WM8962_FLL,
WM8962_FLL_MCLK, 32768,
44100 * 256);
if (ret < 0)
pr_err("Failed to start FLL: %d\n", ret);
ret = snd_soc_dai_set_sysclk(codec_dai,
WM8962_SYSCLK_FLL,
44100 * 256,
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
static int speyside_wm8962_set_bias_level_post(struct snd_soc_card *card,
struct snd_soc_dapm_context *dapm,
enum snd_soc_bias_level level)
{
struct snd_soc_dai *codec_dai = card->rtd[0].codec_dai;
int ret;
if (dapm->dev != codec_dai->dev)
return 0;
switch (level) {
case SND_SOC_BIAS_STANDBY:
ret = snd_soc_dai_set_sysclk(codec_dai, WM8962_SYSCLK_MCLK,
32768, SND_SOC_CLOCK_IN);
if (ret < 0) {
pr_err("Failed to switch away from FLL: %d\n", ret);
return ret;
}
ret = snd_soc_dai_set_pll(codec_dai, WM8962_FLL,
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
static int speyside_wm8962_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *cpu_dai = rtd->cpu_dai;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
int ret;
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
return 0;
}
static int speyside_wm8962_late_probe(struct snd_soc_card *card)
{
struct snd_soc_codec *codec = card->rtd[0].codec;
struct snd_soc_dai *codec_dai = card->rtd[0].codec_dai;
int ret;
ret = snd_soc_dai_set_sysclk(codec_dai, WM8962_SYSCLK_MCLK,
32768, SND_SOC_CLOCK_IN);
if (ret < 0)
return ret;
ret = snd_soc_jack_new(codec, "Headset",
SND_JACK_HEADSET | SND_JACK_BTN_0,
&speyside_wm8962_headset);
if (ret)
return ret;
ret = snd_soc_jack_add_pins(&speyside_wm8962_headset,
ARRAY_SIZE(speyside_wm8962_headset_pins),
speyside_wm8962_headset_pins);
if (ret)
return ret;
wm8962_mic_detect(codec, &speyside_wm8962_headset);
return 0;
}
static __devinit int speyside_wm8962_probe(struct platform_device *pdev)
{
struct snd_soc_card *card = &speyside_wm8962;
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
static int __devexit speyside_wm8962_remove(struct platform_device *pdev)
{
struct snd_soc_card *card = platform_get_drvdata(pdev);
snd_soc_unregister_card(card);
return 0;
}
static int __init speyside_wm8962_audio_init(void)
{
return platform_driver_register(&speyside_wm8962_driver);
}
static void __exit speyside_wm8962_audio_exit(void)
{
platform_driver_unregister(&speyside_wm8962_driver);
}
