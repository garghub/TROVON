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
snd_soc_dapm_new_controls(dapm, e750_dapm_widgets,
ARRAY_SIZE(e750_dapm_widgets));
snd_soc_dapm_add_routes(dapm, audio_map, ARRAY_SIZE(audio_map));
snd_soc_dapm_sync(dapm);
return 0;
}
static int __init e750_init(void)
{
int ret;
if (!machine_is_e750())
return -ENODEV;
ret = gpio_request(GPIO_E750_HP_AMP_OFF, "Headphone amp");
if (ret)
return ret;
ret = gpio_request(GPIO_E750_SPK_AMP_OFF, "Speaker amp");
if (ret)
goto free_hp_amp_gpio;
ret = gpio_direction_output(GPIO_E750_HP_AMP_OFF, 1);
if (ret)
goto free_spk_amp_gpio;
ret = gpio_direction_output(GPIO_E750_SPK_AMP_OFF, 1);
if (ret)
goto free_spk_amp_gpio;
e750_snd_device = platform_device_alloc("soc-audio", -1);
if (!e750_snd_device) {
ret = -ENOMEM;
goto free_spk_amp_gpio;
}
platform_set_drvdata(e750_snd_device, &e750);
ret = platform_device_add(e750_snd_device);
if (!ret)
return 0;
platform_device_put(e750_snd_device);
free_spk_amp_gpio:
gpio_free(GPIO_E750_SPK_AMP_OFF);
free_hp_amp_gpio:
gpio_free(GPIO_E750_HP_AMP_OFF);
return ret;
}
static void __exit e750_exit(void)
{
platform_device_unregister(e750_snd_device);
gpio_free(GPIO_E750_SPK_AMP_OFF);
gpio_free(GPIO_E750_HP_AMP_OFF);
}
