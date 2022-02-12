static int bt_sco_probe(struct platform_device *pdev)
{
return snd_soc_register_codec(&pdev->dev, &soc_codec_dev_bt_sco,
&bt_sco_dai, 1);
}
static int bt_sco_remove(struct platform_device *pdev)
{
snd_soc_unregister_codec(&pdev->dev);
return 0;
}
