static int __devinit dfbmcs320_probe(struct platform_device *pdev)
{
return snd_soc_register_codec(&pdev->dev, &soc_codec_dev_dfbmcs320,
&dfbmcs320_dai, 1);
}
static int __devexit dfbmcs320_remove(struct platform_device *pdev)
{
snd_soc_unregister_codec(&pdev->dev);
return 0;
}
