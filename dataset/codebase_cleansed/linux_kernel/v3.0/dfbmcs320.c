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
static int __init dfbmcs320_init(void)
{
return platform_driver_register(&dfmcs320_driver);
}
static void __exit dfbmcs320_exit(void)
{
platform_driver_unregister(&dfmcs320_driver);
}
