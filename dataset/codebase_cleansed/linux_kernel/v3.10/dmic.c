static int dmic_probe(struct snd_soc_codec *codec)
{
struct snd_soc_dapm_context *dapm = &codec->dapm;
snd_soc_dapm_new_controls(dapm, dmic_dapm_widgets,
ARRAY_SIZE(dmic_dapm_widgets));
snd_soc_dapm_add_routes(dapm, intercon, ARRAY_SIZE(intercon));
snd_soc_dapm_new_widgets(dapm);
return 0;
}
static int dmic_dev_probe(struct platform_device *pdev)
{
return snd_soc_register_codec(&pdev->dev,
&soc_dmic, &dmic_dai, 1);
}
static int dmic_dev_remove(struct platform_device *pdev)
{
snd_soc_unregister_codec(&pdev->dev);
return 0;
}
