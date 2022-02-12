static int ad73311_probe(struct platform_device *pdev)
{
return snd_soc_register_codec(&pdev->dev,
&soc_codec_dev_ad73311, &ad73311_dai, 1);
}
static int __devexit ad73311_remove(struct platform_device *pdev)
{
snd_soc_unregister_codec(&pdev->dev);
return 0;
}
static int __init ad73311_init(void)
{
return platform_driver_register(&ad73311_codec_driver);
}
static void __exit ad73311_exit(void)
{
platform_driver_unregister(&ad73311_codec_driver);
}
