static int pcm5102a_probe(struct platform_device *pdev)
{
return snd_soc_register_codec(&pdev->dev, &soc_codec_dev_pcm5102a,
&pcm5102a_dai, 1);
}
static int pcm5102a_remove(struct platform_device *pdev)
{
snd_soc_unregister_codec(&pdev->dev);
return 0;
}
