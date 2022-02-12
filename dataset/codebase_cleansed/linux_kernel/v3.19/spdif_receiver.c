static int spdif_dir_probe(struct platform_device *pdev)
{
return snd_soc_register_codec(&pdev->dev, &soc_codec_spdif_dir,
&dir_stub_dai, 1);
}
static int spdif_dir_remove(struct platform_device *pdev)
{
snd_soc_unregister_codec(&pdev->dev);
return 0;
}
