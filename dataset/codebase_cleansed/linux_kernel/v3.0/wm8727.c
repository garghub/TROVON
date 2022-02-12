static __devinit int wm8727_probe(struct platform_device *pdev)
{
return snd_soc_register_codec(&pdev->dev,
&soc_codec_dev_wm8727, &wm8727_dai, 1);
}
static int __devexit wm8727_remove(struct platform_device *pdev)
{
snd_soc_unregister_codec(&pdev->dev);
return 0;
}
static int __init wm8727_init(void)
{
return platform_driver_register(&wm8727_codec_driver);
}
static void __exit wm8727_exit(void)
{
platform_driver_unregister(&wm8727_codec_driver);
}
