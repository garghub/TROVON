static int tegra_sgtl5000_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
struct snd_soc_card *card = rtd->card;
struct tegra_sgtl5000 *machine = snd_soc_card_get_drvdata(card);
int srate, mclk;
int err;
srate = params_rate(params);
switch (srate) {
case 11025:
case 22050:
case 44100:
case 88200:
mclk = 11289600;
break;
default:
mclk = 12288000;
break;
}
err = tegra_asoc_utils_set_rate(&machine->util_data, srate, mclk);
if (err < 0) {
dev_err(card->dev, "Can't configure clocks\n");
return err;
}
err = snd_soc_dai_set_sysclk(codec_dai, SGTL5000_SYSCLK, mclk,
SND_SOC_CLOCK_IN);
if (err < 0) {
dev_err(card->dev, "codec_dai clock not set\n");
return err;
}
return 0;
}
static int tegra_sgtl5000_driver_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct snd_soc_card *card = &snd_soc_tegra_sgtl5000;
struct tegra_sgtl5000 *machine;
int ret;
machine = devm_kzalloc(&pdev->dev, sizeof(struct tegra_sgtl5000),
GFP_KERNEL);
if (!machine) {
dev_err(&pdev->dev, "Can't allocate tegra_sgtl5000 struct\n");
return -ENOMEM;
}
card->dev = &pdev->dev;
platform_set_drvdata(pdev, card);
snd_soc_card_set_drvdata(card, machine);
ret = snd_soc_of_parse_card_name(card, "nvidia,model");
if (ret)
goto err;
ret = snd_soc_of_parse_audio_routing(card, "nvidia,audio-routing");
if (ret)
goto err;
tegra_sgtl5000_dai.codec_of_node = of_parse_phandle(np,
"nvidia,audio-codec", 0);
if (!tegra_sgtl5000_dai.codec_of_node) {
dev_err(&pdev->dev,
"Property 'nvidia,audio-codec' missing or invalid\n");
ret = -EINVAL;
goto err;
}
tegra_sgtl5000_dai.cpu_of_node = of_parse_phandle(np,
"nvidia,i2s-controller", 0);
if (!tegra_sgtl5000_dai.cpu_of_node) {
dev_err(&pdev->dev,
"Property 'nvidia,i2s-controller' missing/invalid\n");
ret = -EINVAL;
goto err;
}
tegra_sgtl5000_dai.platform_of_node = tegra_sgtl5000_dai.cpu_of_node;
ret = tegra_asoc_utils_init(&machine->util_data, &pdev->dev);
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
tegra_asoc_utils_fini(&machine->util_data);
err:
return ret;
}
static int tegra_sgtl5000_driver_remove(struct platform_device *pdev)
{
struct snd_soc_card *card = platform_get_drvdata(pdev);
struct tegra_sgtl5000 *machine = snd_soc_card_get_drvdata(card);
int ret;
ret = snd_soc_unregister_card(card);
tegra_asoc_utils_fini(&machine->util_data);
return ret;
}
