static int ics43432_probe(struct platform_device *pdev)
{
return snd_soc_register_codec(&pdev->dev, &ics43432_codec_driver,
&ics43432_dai, 1);
}
static int ics43432_remove(struct platform_device *pdev)
{
snd_soc_unregister_codec(&pdev->dev);
return 0;
}
