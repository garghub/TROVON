static __devinit int omap_hdmi_probe(struct platform_device *pdev)
{
struct snd_soc_card *card = &snd_soc_omap_hdmi;
int ret;
card->dev = &pdev->dev;
ret = snd_soc_register_card(card);
if (ret) {
dev_err(&pdev->dev, "snd_soc_register_card failed (%d)\n", ret);
card->dev = NULL;
return ret;
}
return 0;
}
static int __devexit omap_hdmi_remove(struct platform_device *pdev)
{
struct snd_soc_card *card = platform_get_drvdata(pdev);
snd_soc_unregister_card(card);
card->dev = NULL;
return 0;
}
