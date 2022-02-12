static int qi_lb60_spk_event(struct snd_soc_dapm_widget *widget,
struct snd_kcontrol *ctrl, int event)
{
struct qi_lb60 *qi_lb60 = snd_soc_card_get_drvdata(widget->dapm->card);
int on = !SND_SOC_DAPM_EVENT_OFF(event);
gpiod_set_value_cansleep(qi_lb60->snd_gpio, on);
gpiod_set_value_cansleep(qi_lb60->amp_gpio, on);
return 0;
}
static int qi_lb60_probe(struct platform_device *pdev)
{
struct qi_lb60 *qi_lb60;
struct snd_soc_card *card = &qi_lb60_card;
qi_lb60 = devm_kzalloc(&pdev->dev, sizeof(*qi_lb60), GFP_KERNEL);
if (!qi_lb60)
return -ENOMEM;
qi_lb60->snd_gpio = devm_gpiod_get(&pdev->dev, "snd", GPIOD_OUT_LOW);
if (IS_ERR(qi_lb60->snd_gpio))
return PTR_ERR(qi_lb60->snd_gpio);
qi_lb60->amp_gpio = devm_gpiod_get(&pdev->dev, "amp", GPIOD_OUT_LOW);
if (IS_ERR(qi_lb60->amp_gpio))
return PTR_ERR(qi_lb60->amp_gpio);
card->dev = &pdev->dev;
snd_soc_card_set_drvdata(card, qi_lb60);
return devm_snd_soc_register_card(&pdev->dev, card);
}
