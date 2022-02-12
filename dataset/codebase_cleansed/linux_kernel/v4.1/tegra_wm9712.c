static int tegra_wm9712_init(struct snd_soc_pcm_runtime *rtd)
{
return snd_soc_dapm_force_enable_pin(&rtd->card->dapm, "Mic Bias");
}
static int tegra_wm9712_driver_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct snd_soc_card *card = &snd_soc_tegra_wm9712;
struct tegra_wm9712 *machine;
int ret;
machine = devm_kzalloc(&pdev->dev, sizeof(struct tegra_wm9712),
GFP_KERNEL);
if (!machine) {
dev_err(&pdev->dev, "Can't allocate tegra_wm9712 struct\n");
return -ENOMEM;
}
card->dev = &pdev->dev;
platform_set_drvdata(pdev, card);
snd_soc_card_set_drvdata(card, machine);
machine->codec = platform_device_alloc("wm9712-codec", -1);
if (!machine->codec) {
dev_err(&pdev->dev, "Can't allocate wm9712 platform device\n");
return -ENOMEM;
}
ret = platform_device_add(machine->codec);
if (ret)
goto codec_put;
ret = snd_soc_of_parse_card_name(card, "nvidia,model");
if (ret)
goto codec_unregister;
ret = snd_soc_of_parse_audio_routing(card, "nvidia,audio-routing");
if (ret)
goto codec_unregister;
tegra_wm9712_dai.cpu_of_node = of_parse_phandle(np,
"nvidia,ac97-controller", 0);
if (!tegra_wm9712_dai.cpu_of_node) {
dev_err(&pdev->dev,
"Property 'nvidia,ac97-controller' missing or invalid\n");
ret = -EINVAL;
goto codec_unregister;
}
tegra_wm9712_dai.platform_of_node = tegra_wm9712_dai.cpu_of_node;
ret = tegra_asoc_utils_init(&machine->util_data, &pdev->dev);
if (ret)
goto codec_unregister;
ret = tegra_asoc_utils_set_ac97_rate(&machine->util_data);
if (ret)
goto asoc_utils_fini;
ret = snd_soc_register_card(card);
if (ret) {
dev_err(&pdev->dev, "snd_soc_register_card failed (%d)\n",
ret);
goto asoc_utils_fini;
}
return 0;
asoc_utils_fini:
tegra_asoc_utils_fini(&machine->util_data);
codec_unregister:
platform_device_del(machine->codec);
codec_put:
platform_device_put(machine->codec);
return ret;
}
static int tegra_wm9712_driver_remove(struct platform_device *pdev)
{
struct snd_soc_card *card = platform_get_drvdata(pdev);
struct tegra_wm9712 *machine = snd_soc_card_get_drvdata(card);
snd_soc_unregister_card(card);
tegra_asoc_utils_fini(&machine->util_data);
platform_device_unregister(machine->codec);
return 0;
}
