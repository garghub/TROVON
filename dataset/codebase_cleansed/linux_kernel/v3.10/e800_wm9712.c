static int e800_spk_amp_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
if (event & SND_SOC_DAPM_PRE_PMU)
gpio_set_value(GPIO_E800_SPK_AMP_ON, 1);
else if (event & SND_SOC_DAPM_POST_PMD)
gpio_set_value(GPIO_E800_SPK_AMP_ON, 0);
return 0;
}
static int e800_hp_amp_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
if (event & SND_SOC_DAPM_PRE_PMU)
gpio_set_value(GPIO_E800_HP_AMP_OFF, 0);
else if (event & SND_SOC_DAPM_POST_PMD)
gpio_set_value(GPIO_E800_HP_AMP_OFF, 1);
return 0;
}
static int e800_ac97_init(struct snd_soc_pcm_runtime *rtd)
{
struct snd_soc_codec *codec = rtd->codec;
struct snd_soc_dapm_context *dapm = &codec->dapm;
snd_soc_dapm_new_controls(dapm, e800_dapm_widgets,
ARRAY_SIZE(e800_dapm_widgets));
snd_soc_dapm_add_routes(dapm, audio_map, ARRAY_SIZE(audio_map));
return 0;
}
static int e800_probe(struct platform_device *pdev)
{
struct snd_soc_card *card = &e800;
int ret;
ret = gpio_request_array(e800_audio_gpios,
ARRAY_SIZE(e800_audio_gpios));
if (ret)
return ret;
card->dev = &pdev->dev;
ret = snd_soc_register_card(card);
if (ret) {
dev_err(&pdev->dev, "snd_soc_register_card() failed: %d\n",
ret);
gpio_free_array(e800_audio_gpios, ARRAY_SIZE(e800_audio_gpios));
}
return ret;
}
static int e800_remove(struct platform_device *pdev)
{
struct snd_soc_card *card = platform_get_drvdata(pdev);
gpio_free_array(e800_audio_gpios, ARRAY_SIZE(e800_audio_gpios));
snd_soc_unregister_card(card);
return 0;
}
