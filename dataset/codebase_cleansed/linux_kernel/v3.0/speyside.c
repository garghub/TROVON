static int speyside_set_bias_level(struct snd_soc_card *card,
enum snd_soc_bias_level level)
{
struct snd_soc_dai *codec_dai = card->rtd[0].codec_dai;
int ret;
switch (level) {
case SND_SOC_BIAS_STANDBY:
ret = snd_soc_dai_set_sysclk(codec_dai, WM8915_SYSCLK_MCLK1,
32768, SND_SOC_CLOCK_IN);
if (ret < 0)
return ret;
ret = snd_soc_dai_set_pll(codec_dai, WM8915_FLL_MCLK1,
0, 0, 0);
if (ret < 0) {
pr_err("Failed to stop FLL\n");
return ret;
}
default:
break;
}
return 0;
}
static int speyside_hw_params(struct snd_pcm_substream *substream,
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
ret = snd_soc_dai_set_pll(codec_dai, 0, WM8915_FLL_MCLK1,
32768, 256 * 48000);
if (ret < 0)
return ret;
ret = snd_soc_dai_set_sysclk(codec_dai, WM8915_SYSCLK_FLL,
256 * 48000, SND_SOC_CLOCK_IN);
if (ret < 0)
return ret;
return 0;
}
static int speyside_get_micbias(struct snd_soc_dapm_widget *source,
struct snd_soc_dapm_widget *sink)
{
if (speyside_jack_polarity && (strcmp(source->name, "MICB1") == 0))
return 1;
if (!speyside_jack_polarity && (strcmp(source->name, "MICB2") == 0))
return 1;
return 0;
}
static void speyside_set_polarity(struct snd_soc_codec *codec,
int polarity)
{
speyside_jack_polarity = !polarity;
gpio_direction_output(WM8915_HPSEL_GPIO, speyside_jack_polarity);
snd_soc_dapm_sync(&codec->dapm);
}
static int speyside_wm8915_init(struct snd_soc_pcm_runtime *rtd)
{
struct snd_soc_dai *dai = rtd->codec_dai;
struct snd_soc_codec *codec = rtd->codec;
int ret;
ret = snd_soc_dai_set_sysclk(dai, WM8915_SYSCLK_MCLK1, 32768, 0);
if (ret < 0)
return ret;
ret = gpio_request(WM8915_HPSEL_GPIO, "HP_SEL");
if (ret != 0)
pr_err("Failed to request HP_SEL GPIO: %d\n", ret);
gpio_direction_output(WM8915_HPSEL_GPIO, speyside_jack_polarity);
ret = snd_soc_jack_new(codec, "Headset",
SND_JACK_HEADSET | SND_JACK_BTN_0,
&speyside_headset);
if (ret)
return ret;
ret = snd_soc_jack_add_pins(&speyside_headset,
ARRAY_SIZE(speyside_headset_pins),
speyside_headset_pins);
if (ret)
return ret;
wm8915_detect(codec, &speyside_headset, speyside_set_polarity);
return 0;
}
static int speyside_late_probe(struct snd_soc_card *card)
{
snd_soc_dapm_ignore_suspend(&card->dapm, "Headphone");
snd_soc_dapm_ignore_suspend(&card->dapm, "Headset Mic");
snd_soc_dapm_ignore_suspend(&card->dapm, "Main AMIC");
snd_soc_dapm_ignore_suspend(&card->dapm, "Main DMIC");
snd_soc_dapm_ignore_suspend(&card->dapm, "Speaker");
snd_soc_dapm_ignore_suspend(&card->dapm, "WM1250 Output");
snd_soc_dapm_ignore_suspend(&card->dapm, "WM1250 Input");
return 0;
}
static int speyside_wm9081_init(struct snd_soc_dapm_context *dapm)
{
snd_soc_dapm_nc_pin(dapm, "LINEOUT");
return snd_soc_codec_set_sysclk(dapm->codec, WM9081_SYSCLK_MCLK,
48000 * 256, 0);
}
static __devinit int speyside_probe(struct platform_device *pdev)
{
struct snd_soc_card *card = &speyside;
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
static int __devexit speyside_remove(struct platform_device *pdev)
{
struct snd_soc_card *card = platform_get_drvdata(pdev);
snd_soc_unregister_card(card);
return 0;
}
static int __init speyside_audio_init(void)
{
return platform_driver_register(&speyside_driver);
}
static void __exit speyside_audio_exit(void)
{
platform_driver_unregister(&speyside_driver);
}
