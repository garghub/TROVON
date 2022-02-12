static int adau7002_probe(struct platform_device *pdev)
{
return snd_soc_register_codec(&pdev->dev, &adau7002_codec_driver,
&adau7002_dai, 1);
}
static int adau7002_remove(struct platform_device *pdev)
{
snd_soc_unregister_codec(&pdev->dev);
return 0;
}
