static int tegra_alc5632_asoc_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
struct snd_soc_codec *codec = rtd->codec;
struct snd_soc_card *card = codec->card;
struct tegra_alc5632 *alc5632 = snd_soc_card_get_drvdata(card);
int srate, mclk;
int err;
srate = params_rate(params);
mclk = 512 * srate;
err = tegra_asoc_utils_set_rate(&alc5632->util_data, srate, mclk);
if (err < 0) {
dev_err(card->dev, "Can't configure clocks\n");
return err;
}
err = snd_soc_dai_set_sysclk(codec_dai, 0, mclk,
SND_SOC_CLOCK_IN);
if (err < 0) {
dev_err(card->dev, "codec_dai clock not set\n");
return err;
}
return 0;
}
static int tegra_alc5632_asoc_init(struct snd_soc_pcm_runtime *rtd)
{
struct snd_soc_codec *codec = rtd->codec;
struct snd_soc_dapm_context *dapm = &codec->dapm;
snd_soc_jack_new(codec, "Headset Jack", SND_JACK_HEADSET,
&tegra_alc5632_hs_jack);
snd_soc_jack_add_pins(&tegra_alc5632_hs_jack,
ARRAY_SIZE(tegra_alc5632_hs_jack_pins),
tegra_alc5632_hs_jack_pins);
snd_soc_dapm_force_enable_pin(dapm, "MICBIAS1");
return 0;
}
static __devinit int tegra_alc5632_probe(struct platform_device *pdev)
{
struct snd_soc_card *card = &snd_soc_tegra_alc5632;
struct tegra_alc5632 *alc5632;
int ret;
alc5632 = devm_kzalloc(&pdev->dev,
sizeof(struct tegra_alc5632), GFP_KERNEL);
if (!alc5632) {
dev_err(&pdev->dev, "Can't allocate tegra_alc5632\n");
return -ENOMEM;
}
ret = tegra_asoc_utils_init(&alc5632->util_data, &pdev->dev);
if (ret)
return ret;
card->dev = &pdev->dev;
platform_set_drvdata(pdev, card);
snd_soc_card_set_drvdata(card, alc5632);
ret = snd_soc_register_card(card);
if (ret) {
dev_err(&pdev->dev, "snd_soc_register_card failed (%d)\n",
ret);
tegra_asoc_utils_fini(&alc5632->util_data);
return ret;
}
return 0;
}
static int __devexit tegra_alc5632_remove(struct platform_device *pdev)
{
struct snd_soc_card *card = platform_get_drvdata(pdev);
struct tegra_alc5632 *alc5632 = snd_soc_card_get_drvdata(card);
snd_soc_unregister_card(card);
tegra_asoc_utils_fini(&alc5632->util_data);
return 0;
}
