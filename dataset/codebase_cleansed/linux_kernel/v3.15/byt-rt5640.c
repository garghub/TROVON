static int byt_rt5640_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
int ret;
ret = snd_soc_dai_set_sysclk(codec_dai, RT5640_SCLK_S_PLL1,
params_rate(params) * 256,
SND_SOC_CLOCK_IN);
if (ret < 0) {
dev_err(codec_dai->dev, "can't set codec clock %d\n", ret);
return ret;
}
ret = snd_soc_dai_set_pll(codec_dai, 0, RT5640_PLL1_S_BCLK1,
params_rate(params) * 64,
params_rate(params) * 256);
if (ret < 0) {
dev_err(codec_dai->dev, "can't set codec pll: %d\n", ret);
return ret;
}
return 0;
}
static int byt_rt5640_init(struct snd_soc_pcm_runtime *runtime)
{
int ret;
struct snd_soc_codec *codec = runtime->codec;
struct snd_soc_dapm_context *dapm = &codec->dapm;
struct snd_soc_card *card = runtime->card;
card->dapm.idle_bias_off = true;
ret = snd_soc_add_card_controls(card, byt_rt5640_controls,
ARRAY_SIZE(byt_rt5640_controls));
if (ret) {
dev_err(card->dev, "unable to add card controls\n");
return ret;
}
snd_soc_dapm_ignore_suspend(dapm, "HPOL");
snd_soc_dapm_ignore_suspend(dapm, "HPOR");
snd_soc_dapm_ignore_suspend(dapm, "SPOLP");
snd_soc_dapm_ignore_suspend(dapm, "SPOLN");
snd_soc_dapm_ignore_suspend(dapm, "SPORP");
snd_soc_dapm_ignore_suspend(dapm, "SPORN");
snd_soc_dapm_enable_pin(dapm, "Headset Mic");
snd_soc_dapm_enable_pin(dapm, "Headphone");
snd_soc_dapm_enable_pin(dapm, "Speaker");
snd_soc_dapm_enable_pin(dapm, "Internal Mic");
snd_soc_dapm_sync(dapm);
return ret;
}
static int byt_rt5640_probe(struct platform_device *pdev)
{
struct snd_soc_card *card = &byt_rt5640_card;
struct device *dev = &pdev->dev;
card->dev = &pdev->dev;
dev_set_drvdata(dev, card);
return snd_soc_register_card(card);
}
static int byt_rt5640_remove(struct platform_device *pdev)
{
struct snd_soc_card *card = platform_get_drvdata(pdev);
snd_soc_unregister_card(card);
return 0;
}
