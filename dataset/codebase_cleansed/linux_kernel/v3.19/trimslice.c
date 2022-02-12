static int trimslice_asoc_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
struct snd_soc_card *card = rtd->card;
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
err = snd_soc_dai_set_sysclk(codec_dai, 0, mclk,
SND_SOC_CLOCK_IN);
if (err < 0) {
dev_err(card->dev, "codec_dai clock not set\n");
return err;
}
return 0;
}
static int tegra_snd_trimslice_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct snd_soc_card *card = &snd_soc_trimslice;
struct tegra_trimslice *trimslice;
int ret;
trimslice = devm_kzalloc(&pdev->dev, sizeof(struct tegra_trimslice),
GFP_KERNEL);
if (!trimslice) {
dev_err(&pdev->dev, "Can't allocate tegra_trimslice\n");
return -ENOMEM;
}
card->dev = &pdev->dev;
platform_set_drvdata(pdev, card);
snd_soc_card_set_drvdata(card, trimslice);
trimslice_tlv320aic23_dai.codec_of_node = of_parse_phandle(np,
"nvidia,audio-codec", 0);
if (!trimslice_tlv320aic23_dai.codec_of_node) {
dev_err(&pdev->dev,
"Property 'nvidia,audio-codec' missing or invalid\n");
ret = -EINVAL;
goto err;
}
trimslice_tlv320aic23_dai.cpu_of_node = of_parse_phandle(np,
"nvidia,i2s-controller", 0);
if (!trimslice_tlv320aic23_dai.cpu_of_node) {
dev_err(&pdev->dev,
"Property 'nvidia,i2s-controller' missing or invalid\n");
ret = -EINVAL;
goto err;
}
trimslice_tlv320aic23_dai.platform_of_node =
trimslice_tlv320aic23_dai.cpu_of_node;
ret = tegra_asoc_utils_init(&trimslice->util_data, &pdev->dev);
if (ret)
goto err;
ret = snd_soc_register_card(card);
if (ret) {
dev_err(&pdev->dev, "snd_soc_register_card failed (%d)\n",
ret);
goto err_fini_utils;
}
return 0;
err_fini_utils:
tegra_asoc_utils_fini(&trimslice->util_data);
err:
return ret;
}
static int tegra_snd_trimslice_remove(struct platform_device *pdev)
{
struct snd_soc_card *card = platform_get_drvdata(pdev);
struct tegra_trimslice *trimslice = snd_soc_card_get_drvdata(card);
snd_soc_unregister_card(card);
tegra_asoc_utils_fini(&trimslice->util_data);
return 0;
}
