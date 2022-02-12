static int byt_max98090_init(struct snd_soc_pcm_runtime *runtime)
{
int ret;
struct snd_soc_card *card = runtime->card;
struct byt_max98090_private *drv = snd_soc_card_get_drvdata(card);
struct snd_soc_jack *jack = &drv->jack;
card->dapm.idle_bias_off = true;
ret = snd_soc_dai_set_sysclk(runtime->codec_dai,
M98090_REG_SYSTEM_CLOCK,
25000000, SND_SOC_CLOCK_IN);
if (ret < 0) {
dev_err(card->dev, "Can't set codec clock %d\n", ret);
return ret;
}
ret = snd_soc_card_jack_new(runtime->card, "Headset",
SND_JACK_LINEOUT | SND_JACK_HEADSET, jack,
hs_jack_pins, ARRAY_SIZE(hs_jack_pins));
if (ret)
return ret;
return snd_soc_jack_add_gpiods(card->dev->parent, jack,
ARRAY_SIZE(hs_jack_gpios),
hs_jack_gpios);
}
static int byt_max98090_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct byt_max98090_private *priv;
int ret_val;
priv = devm_kzalloc(&pdev->dev, sizeof(*priv), GFP_ATOMIC);
if (!priv) {
dev_err(&pdev->dev, "allocation failed\n");
return -ENOMEM;
}
ret_val = devm_acpi_dev_add_driver_gpios(dev->parent, acpi_byt_max98090_gpios);
if (ret_val)
dev_dbg(dev, "Unable to add GPIO mapping table\n");
byt_max98090_card.dev = &pdev->dev;
snd_soc_card_set_drvdata(&byt_max98090_card, priv);
ret_val = devm_snd_soc_register_card(&pdev->dev, &byt_max98090_card);
if (ret_val) {
dev_err(&pdev->dev,
"snd_soc_register_card failed %d\n", ret_val);
return ret_val;
}
return 0;
}
