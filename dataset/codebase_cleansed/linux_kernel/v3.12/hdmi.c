static int hdmi_codec_probe(struct platform_device *pdev)
{
return snd_soc_register_codec(&pdev->dev, &hdmi_codec,
&hdmi_codec_dai, 1);
}
static int hdmi_codec_remove(struct platform_device *pdev)
{
snd_soc_unregister_codec(&pdev->dev);
return 0;
}
