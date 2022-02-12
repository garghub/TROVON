static int e750_spk_amp_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
if (event & SND_SOC_DAPM_PRE_PMU)
gpio_set_value(GPIO_E750_SPK_AMP_OFF, 0);
else if (event & SND_SOC_DAPM_POST_PMD)
gpio_set_value(GPIO_E750_SPK_AMP_OFF, 1);
return 0;
}
static int e750_hp_amp_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
if (event & SND_SOC_DAPM_PRE_PMU)
gpio_set_value(GPIO_E750_HP_AMP_OFF, 0);
else if (event & SND_SOC_DAPM_POST_PMD)
gpio_set_value(GPIO_E750_HP_AMP_OFF, 1);
return 0;
}
static int e750_ac97_init(struct snd_soc_pcm_runtime *rtd)
{
struct snd_soc_codec *codec = rtd->codec;
struct snd_soc_dapm_context *dapm = &codec->dapm;
snd_soc_dapm_nc_pin(dapm, "LOUT");
snd_soc_dapm_nc_pin(dapm, "ROUT");
snd_soc_dapm_nc_pin(dapm, "PHONE");
snd_soc_dapm_nc_pin(dapm, "LINEINL");
snd_soc_dapm_nc_pin(dapm, "LINEINR");
snd_soc_dapm_nc_pin(dapm, "CDINL");
snd_soc_dapm_nc_pin(dapm, "CDINR");
snd_soc_dapm_nc_pin(dapm, "PCBEEP");
snd_soc_dapm_nc_pin(dapm, "MIC2");
return 0;
}
static int e750_probe(struct platform_device *pdev)
{
struct snd_soc_card *card = &e750;
int ret;
ret = gpio_request_array(e750_audio_gpios,
ARRAY_SIZE(e750_audio_gpios));
if (ret)
return ret;
card->dev = &pdev->dev;
ret = snd_soc_register_card(card);
if (ret) {
dev_err(&pdev->dev, "snd_soc_register_card() failed: %d\n",
ret);
gpio_free_array(e750_audio_gpios, ARRAY_SIZE(e750_audio_gpios));
}
return ret;
}
static int e750_remove(struct platform_device *pdev)
{
struct snd_soc_card *card = platform_get_drvdata(pdev);
gpio_free_array(e750_audio_gpios, ARRAY_SIZE(e750_audio_gpios));
snd_soc_unregister_card(card);
return 0;
}
