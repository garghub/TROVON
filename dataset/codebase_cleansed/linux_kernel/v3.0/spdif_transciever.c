static int spdif_dit_probe(struct platform_device *pdev)
{
return snd_soc_register_codec(&pdev->dev, &soc_codec_spdif_dit,
&dit_stub_dai, 1);
}
static int spdif_dit_remove(struct platform_device *pdev)
{
snd_soc_unregister_codec(&pdev->dev);
return 0;
}
static int __init dit_modinit(void)
{
return platform_driver_register(&spdif_dit_driver);
}
static void __exit dit_exit(void)
{
platform_driver_unregister(&spdif_dit_driver);
}
