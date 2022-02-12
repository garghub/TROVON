static int tegra_wm8753_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
struct snd_soc_codec *codec = rtd->codec;
struct snd_soc_card *card = codec->card;
struct tegra_wm8753 *machine = snd_soc_card_get_drvdata(card);
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
err = snd_soc_dai_set_sysclk(codec_dai, WM8753_MCLK, mclk,
SND_SOC_CLOCK_IN);
if (err < 0) {
dev_err(card->dev, "codec_dai clock not set\n");
return err;
}
return 0;
}
static __devinit int tegra_wm8753_driver_probe(struct platform_device *pdev)
{
struct snd_soc_card *card = &snd_soc_tegra_wm8753;
struct tegra_wm8753 *machine;
int ret;
machine = devm_kzalloc(&pdev->dev, sizeof(struct tegra_wm8753),
GFP_KERNEL);
if (!machine) {
dev_err(&pdev->dev, "Can't allocate tegra_wm8753 struct\n");
ret = -ENOMEM;
goto err;
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
tegra_wm8753_dai.codec_of_node = of_parse_phandle(
pdev->dev.of_node, "nvidia,audio-codec", 0);
if (!tegra_wm8753_dai.codec_of_node) {
dev_err(&pdev->dev,
"Property 'nvidia,audio-codec' missing or invalid\n");
ret = -EINVAL;
goto err;
}
tegra_wm8753_dai.cpu_dai_of_node = of_parse_phandle(
pdev->dev.of_node, "nvidia,i2s-controller", 0);
if (!tegra_wm8753_dai.cpu_dai_of_node) {
dev_err(&pdev->dev,
"Property 'nvidia,i2s-controller' missing or invalid\n");
ret = -EINVAL;
goto err;
}
tegra_wm8753_dai.platform_of_node =
tegra_wm8753_dai.cpu_dai_of_node;
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
static int __devexit tegra_wm8753_driver_remove(struct platform_device *pdev)
{
struct snd_soc_card *card = platform_get_drvdata(pdev);
struct tegra_wm8753 *machine = snd_soc_card_get_drvdata(card);
snd_soc_unregister_card(card);
tegra_asoc_utils_fini(&machine->util_data);
return 0;
}
