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
snd_soc_dapm_sync(dapm);
return 0;
}
static int __init e800_init(void)
{
int ret;
if (!machine_is_e800())
return -ENODEV;
ret = gpio_request(GPIO_E800_HP_AMP_OFF, "Headphone amp");
if (ret)
return ret;
ret = gpio_request(GPIO_E800_SPK_AMP_ON, "Speaker amp");
if (ret)
goto free_hp_amp_gpio;
ret = gpio_direction_output(GPIO_E800_HP_AMP_OFF, 1);
if (ret)
goto free_spk_amp_gpio;
ret = gpio_direction_output(GPIO_E800_SPK_AMP_ON, 1);
if (ret)
goto free_spk_amp_gpio;
e800_snd_device = platform_device_alloc("soc-audio", -1);
if (!e800_snd_device)
return -ENOMEM;
platform_set_drvdata(e800_snd_device, &e800);
ret = platform_device_add(e800_snd_device);
if (!ret)
return 0;
platform_device_put(e800_snd_device);
free_spk_amp_gpio:
gpio_free(GPIO_E800_SPK_AMP_ON);
free_hp_amp_gpio:
gpio_free(GPIO_E800_HP_AMP_OFF);
return ret;
}
static void __exit e800_exit(void)
{
platform_device_unregister(e800_snd_device);
gpio_free(GPIO_E800_SPK_AMP_ON);
gpio_free(GPIO_E800_HP_AMP_OFF);
}
