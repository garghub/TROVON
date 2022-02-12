static int lowland_hw_params(struct snd_pcm_substream *substream,
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
static int lowland_wm5100_init(struct snd_soc_pcm_runtime *rtd)
{
struct snd_soc_codec *codec = rtd->codec;
int ret;
ret = snd_soc_codec_set_sysclk(codec, WM5100_CLK_SYSCLK,
WM5100_CLKSRC_MCLK1, MCLK1_RATE,
SND_SOC_CLOCK_IN);
if (ret < 0) {
pr_err("Failed to set SYSCLK clock source: %d\n", ret);
return ret;
}
ret = snd_soc_codec_set_sysclk(codec, WM5100_CLK_OPCLK, 0,
CLKOUT_RATE, 0);
if (ret < 0) {
pr_err("Failed to set OPCLK rate: %d\n", ret);
return ret;
}
ret = snd_soc_jack_new(codec, "Headset",
SND_JACK_LINEOUT | SND_JACK_HEADSET |
SND_JACK_BTN_0,
&lowland_headset);
if (ret)
return ret;
ret = snd_soc_jack_add_pins(&lowland_headset,
ARRAY_SIZE(lowland_headset_pins),
lowland_headset_pins);
if (ret)
return ret;
wm5100_detect(codec, &lowland_headset);
return 0;
}
static int lowland_wm9081_init(struct snd_soc_dapm_context *dapm)
{
snd_soc_dapm_nc_pin(dapm, "LINEOUT");
return snd_soc_codec_set_sysclk(dapm->codec, WM9081_SYSCLK_MCLK, 0,
CLKOUT_RATE, 0);
}
static __devinit int lowland_probe(struct platform_device *pdev)
{
struct snd_soc_card *card = &lowland;
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
static int __devexit lowland_remove(struct platform_device *pdev)
{
struct snd_soc_card *card = platform_get_drvdata(pdev);
snd_soc_unregister_card(card);
return 0;
}
