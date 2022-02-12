static int gtm601_platform_probe(struct platform_device *pdev)
{
return snd_soc_register_codec(&pdev->dev,
&soc_codec_dev_gtm601, &gtm601_dai, 1);
}
static int gtm601_platform_remove(struct platform_device *pdev)
{
snd_soc_unregister_codec(&pdev->dev);
return 0;
}
