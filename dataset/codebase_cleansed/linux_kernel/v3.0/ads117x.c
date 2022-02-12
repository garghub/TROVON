static __devinit int ads117x_probe(struct platform_device *pdev)
{
return snd_soc_register_codec(&pdev->dev,
&soc_codec_dev_ads117x, &ads117x_dai, 1);
}
static int __devexit ads117x_remove(struct platform_device *pdev)
{
snd_soc_unregister_codec(&pdev->dev);
return 0;
}
static int __init ads117x_init(void)
{
return platform_driver_register(&ads117x_codec_driver);
}
static void __exit ads117x_exit(void)
{
platform_driver_unregister(&ads117x_codec_driver);
}
