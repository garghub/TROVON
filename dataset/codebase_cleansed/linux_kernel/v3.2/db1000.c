static int __devinit db1000_audio_probe(struct platform_device *pdev)
{
struct snd_soc_card *card = &db1000_ac97;
card->dev = &pdev->dev;
return snd_soc_register_card(card);
}
static int __devexit db1000_audio_remove(struct platform_device *pdev)
{
struct snd_soc_card *card = platform_get_drvdata(pdev);
snd_soc_unregister_card(card);
return 0;
}
static int __init db1000_audio_load(void)
{
return platform_driver_register(&db1000_audio_driver);
}
static void __exit db1000_audio_unload(void)
{
platform_driver_unregister(&db1000_audio_driver);
}
