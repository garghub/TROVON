static int qi_lb60_spk_event(struct snd_soc_dapm_widget *widget,
struct snd_kcontrol *ctrl, int event)
{
int on = !SND_SOC_DAPM_EVENT_OFF(event);
gpio_set_value(QI_LB60_SND_GPIO, on);
gpio_set_value(QI_LB60_AMP_GPIO, on);
return 0;
}
static int qi_lb60_codec_init(struct snd_soc_pcm_runtime *rtd)
{
struct snd_soc_codec *codec = rtd->codec;
struct snd_soc_dai *cpu_dai = rtd->cpu_dai;
struct snd_soc_dapm_context *dapm = &codec->dapm;
int ret;
snd_soc_dapm_nc_pin(dapm, "LIN");
snd_soc_dapm_nc_pin(dapm, "RIN");
ret = snd_soc_dai_set_fmt(cpu_dai, QI_LB60_DAIFMT);
if (ret < 0) {
dev_err(codec->dev, "Failed to set cpu dai format: %d\n", ret);
return ret;
}
return 0;
}
static int __devinit qi_lb60_probe(struct platform_device *pdev)
{
struct snd_soc_card *card = &qi_lb60;
int ret;
ret = gpio_request_array(qi_lb60_gpios, ARRAY_SIZE(qi_lb60_gpios));
if (ret)
return ret;
card->dev = &pdev->dev;
ret = snd_soc_register_card(card);
if (ret) {
dev_err(&pdev->dev, "snd_soc_register_card() failed: %d\n",
ret);
gpio_free_array(qi_lb60_gpios, ARRAY_SIZE(qi_lb60_gpios));
}
return ret;
}
static int __devexit qi_lb60_remove(struct platform_device *pdev)
{
struct snd_soc_card *card = platform_get_drvdata(pdev);
snd_soc_unregister_card(card);
gpio_free_array(qi_lb60_gpios, ARRAY_SIZE(qi_lb60_gpios));
return 0;
}
