static int simone_probe(struct platform_device *pdev)
{
struct snd_soc_card *card = &snd_soc_simone;
int ret;
simone_snd_ac97_device = platform_device_register_simple("ac97-codec",
-1, NULL, 0);
if (IS_ERR(simone_snd_ac97_device))
return PTR_ERR(simone_snd_ac97_device);
card->dev = &pdev->dev;
ret = snd_soc_register_card(card);
if (ret) {
dev_err(&pdev->dev, "snd_soc_register_card() failed: %d\n",
ret);
platform_device_unregister(simone_snd_ac97_device);
}
return ret;
}
static int simone_remove(struct platform_device *pdev)
{
struct snd_soc_card *card = platform_get_drvdata(pdev);
snd_soc_unregister_card(card);
platform_device_unregister(simone_snd_ac97_device);
return 0;
}
