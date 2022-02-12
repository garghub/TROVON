static __devinit int wm8782_probe(struct platform_device *pdev)
{
return snd_soc_register_codec(&pdev->dev,
&soc_codec_dev_wm8782, &wm8782_dai, 1);
}
static int __devexit wm8782_remove(struct platform_device *pdev)
{
snd_soc_unregister_codec(&pdev->dev);
return 0;
}
static int __init wm8782_init(void)
{
return platform_driver_register(&wm8782_codec_driver);
}
static void __exit wm8782_exit(void)
{
platform_driver_unregister(&wm8782_codec_driver);
}
