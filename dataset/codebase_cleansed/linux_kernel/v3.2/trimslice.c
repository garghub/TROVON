static int trimslice_asoc_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
struct snd_soc_dai *cpu_dai = rtd->cpu_dai;
struct snd_soc_codec *codec = rtd->codec;
struct snd_soc_card *card = codec->card;
struct tegra_trimslice *trimslice = snd_soc_card_get_drvdata(card);
int srate, mclk;
int err;
srate = params_rate(params);
mclk = 128 * srate;
err = tegra_asoc_utils_set_rate(&trimslice->util_data, srate, mclk);
if (err < 0) {
dev_err(card->dev, "Can't configure clocks\n");
return err;
}
err = snd_soc_dai_set_fmt(codec_dai,
SND_SOC_DAIFMT_I2S |
SND_SOC_DAIFMT_NB_NF |
SND_SOC_DAIFMT_CBS_CFS);
if (err < 0) {
dev_err(card->dev, "codec_dai fmt not set\n");
return err;
}
err = snd_soc_dai_set_fmt(cpu_dai,
SND_SOC_DAIFMT_I2S |
SND_SOC_DAIFMT_NB_NF |
SND_SOC_DAIFMT_CBS_CFS);
if (err < 0) {
dev_err(card->dev, "cpu_dai fmt not set\n");
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
static int trimslice_asoc_init(struct snd_soc_pcm_runtime *rtd)
{
struct snd_soc_codec *codec = rtd->codec;
struct snd_soc_dapm_context *dapm = &codec->dapm;
snd_soc_dapm_nc_pin(dapm, "LHPOUT");
snd_soc_dapm_nc_pin(dapm, "RHPOUT");
snd_soc_dapm_nc_pin(dapm, "MICIN");
return 0;
}
static __devinit int tegra_snd_trimslice_probe(struct platform_device *pdev)
{
struct snd_soc_card *card = &snd_soc_trimslice;
struct tegra_trimslice *trimslice;
int ret;
trimslice = kzalloc(sizeof(struct tegra_trimslice), GFP_KERNEL);
if (!trimslice) {
dev_err(&pdev->dev, "Can't allocate tegra_trimslice\n");
return -ENOMEM;
}
ret = tegra_asoc_utils_init(&trimslice->util_data, &pdev->dev);
if (ret)
goto err_free_trimslice;
card->dev = &pdev->dev;
platform_set_drvdata(pdev, card);
snd_soc_card_set_drvdata(card, trimslice);
ret = snd_soc_register_card(card);
if (ret) {
dev_err(&pdev->dev, "snd_soc_register_card failed (%d)\n",
ret);
goto err_fini_utils;
}
return 0;
err_fini_utils:
tegra_asoc_utils_fini(&trimslice->util_data);
err_free_trimslice:
kfree(trimslice);
return ret;
}
static int __devexit tegra_snd_trimslice_remove(struct platform_device *pdev)
{
struct snd_soc_card *card = platform_get_drvdata(pdev);
struct tegra_trimslice *trimslice = snd_soc_card_get_drvdata(card);
snd_soc_unregister_card(card);
tegra_asoc_utils_fini(&trimslice->util_data);
kfree(trimslice);
return 0;
}
static int __init snd_tegra_trimslice_init(void)
{
return platform_driver_register(&tegra_snd_trimslice_driver);
}
static void __exit snd_tegra_trimslice_exit(void)
{
platform_driver_unregister(&tegra_snd_trimslice_driver);
}
