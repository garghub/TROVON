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
