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
