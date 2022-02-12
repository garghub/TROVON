static void e740_sync_audio_power(int status)
{
gpio_set_value(GPIO_E740_WM9705_nAVDD2, !status);
gpio_set_value(GPIO_E740_AMP_ON, (status & E740_AUDIO_OUT) ? 1 : 0);
gpio_set_value(GPIO_E740_MIC_ON, (status & E740_AUDIO_IN) ? 1 : 0);
}
static int e740_mic_amp_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
if (event & SND_SOC_DAPM_PRE_PMU)
e740_audio_power |= E740_AUDIO_IN;
else if (event & SND_SOC_DAPM_POST_PMD)
e740_audio_power &= ~E740_AUDIO_IN;
e740_sync_audio_power(e740_audio_power);
return 0;
}
static int e740_output_amp_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
if (event & SND_SOC_DAPM_PRE_PMU)
e740_audio_power |= E740_AUDIO_OUT;
else if (event & SND_SOC_DAPM_POST_PMD)
e740_audio_power &= ~E740_AUDIO_OUT;
e740_sync_audio_power(e740_audio_power);
return 0;
}
static int e740_probe(struct platform_device *pdev)
{
struct snd_soc_card *card = &e740;
int ret;
ret = gpio_request_array(e740_audio_gpios,
ARRAY_SIZE(e740_audio_gpios));
if (ret)
return ret;
card->dev = &pdev->dev;
ret = snd_soc_register_card(card);
if (ret) {
dev_err(&pdev->dev, "snd_soc_register_card() failed: %d\n",
ret);
gpio_free_array(e740_audio_gpios, ARRAY_SIZE(e740_audio_gpios));
}
return ret;
}
static int e740_remove(struct platform_device *pdev)
{
struct snd_soc_card *card = platform_get_drvdata(pdev);
gpio_free_array(e740_audio_gpios, ARRAY_SIZE(e740_audio_gpios));
snd_soc_unregister_card(card);
return 0;
}
