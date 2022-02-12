static int sirf_audio_hp_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *ctrl, int event)
{
struct snd_soc_dapm_context *dapm = w->dapm;
struct snd_soc_card *card = dapm->card;
struct sirf_audio_card *sirf_audio_card = snd_soc_card_get_drvdata(card);
int on = !SND_SOC_DAPM_EVENT_OFF(event);
if (gpio_is_valid(sirf_audio_card->gpio_hp_pa))
gpio_set_value(sirf_audio_card->gpio_hp_pa, on);
return 0;
}
static int sirf_audio_spk_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *ctrl, int event)
{
struct snd_soc_dapm_context *dapm = w->dapm;
struct snd_soc_card *card = dapm->card;
struct sirf_audio_card *sirf_audio_card = snd_soc_card_get_drvdata(card);
int on = !SND_SOC_DAPM_EVENT_OFF(event);
if (gpio_is_valid(sirf_audio_card->gpio_spk_pa))
gpio_set_value(sirf_audio_card->gpio_spk_pa, on);
return 0;
}
static int sirf_audio_probe(struct platform_device *pdev)
{
struct snd_soc_card *card = &snd_soc_sirf_audio_card;
struct sirf_audio_card *sirf_audio_card;
int ret;
sirf_audio_card = devm_kzalloc(&pdev->dev, sizeof(struct sirf_audio_card),
GFP_KERNEL);
if (sirf_audio_card == NULL)
return -ENOMEM;
sirf_audio_dai_link[0].cpu_of_node =
of_parse_phandle(pdev->dev.of_node, "sirf,audio-platform", 0);
sirf_audio_dai_link[0].platform_of_node =
of_parse_phandle(pdev->dev.of_node, "sirf,audio-platform", 0);
sirf_audio_dai_link[0].codec_of_node =
of_parse_phandle(pdev->dev.of_node, "sirf,audio-codec", 0);
sirf_audio_card->gpio_spk_pa = of_get_named_gpio(pdev->dev.of_node,
"spk-pa-gpios", 0);
sirf_audio_card->gpio_hp_pa = of_get_named_gpio(pdev->dev.of_node,
"hp-pa-gpios", 0);
if (gpio_is_valid(sirf_audio_card->gpio_spk_pa)) {
ret = devm_gpio_request_one(&pdev->dev,
sirf_audio_card->gpio_spk_pa,
GPIOF_OUT_INIT_LOW, "SPA_PA_SD");
if (ret) {
dev_err(&pdev->dev,
"Failed to request GPIO_%d for reset: %d\n",
sirf_audio_card->gpio_spk_pa, ret);
return ret;
}
}
if (gpio_is_valid(sirf_audio_card->gpio_hp_pa)) {
ret = devm_gpio_request_one(&pdev->dev,
sirf_audio_card->gpio_hp_pa,
GPIOF_OUT_INIT_LOW, "HP_PA_SD");
if (ret) {
dev_err(&pdev->dev,
"Failed to request GPIO_%d for reset: %d\n",
sirf_audio_card->gpio_hp_pa, ret);
return ret;
}
}
card->dev = &pdev->dev;
snd_soc_card_set_drvdata(card, sirf_audio_card);
ret = devm_snd_soc_register_card(&pdev->dev, card);
if (ret)
dev_err(&pdev->dev, "snd_soc_register_card() failed:%d\n", ret);
return ret;
}
