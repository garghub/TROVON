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
static int e740_ac97_init(struct snd_soc_pcm_runtime *rtd)
{
struct snd_soc_codec *codec = rtd->codec;
struct snd_soc_dapm_context *dapm = &codec->dapm;
snd_soc_dapm_nc_pin(dapm, "HPOUTL");
snd_soc_dapm_nc_pin(dapm, "HPOUTR");
snd_soc_dapm_nc_pin(dapm, "PHONE");
snd_soc_dapm_nc_pin(dapm, "LINEINL");
snd_soc_dapm_nc_pin(dapm, "LINEINR");
snd_soc_dapm_nc_pin(dapm, "CDINL");
snd_soc_dapm_nc_pin(dapm, "CDINR");
snd_soc_dapm_nc_pin(dapm, "PCBEEP");
snd_soc_dapm_nc_pin(dapm, "MIC2");
snd_soc_dapm_new_controls(dapm, e740_dapm_widgets,
ARRAY_SIZE(e740_dapm_widgets));
snd_soc_dapm_add_routes(dapm, audio_map, ARRAY_SIZE(audio_map));
snd_soc_dapm_sync(dapm);
return 0;
}
static int __init e740_init(void)
{
int ret;
if (!machine_is_e740())
return -ENODEV;
ret = gpio_request(GPIO_E740_MIC_ON, "Mic amp");
if (ret)
return ret;
ret = gpio_request(GPIO_E740_AMP_ON, "Output amp");
if (ret)
goto free_mic_amp_gpio;
ret = gpio_request(GPIO_E740_WM9705_nAVDD2, "Audio power");
if (ret)
goto free_op_amp_gpio;
ret = gpio_direction_output(GPIO_E740_MIC_ON, 0);
if (ret)
goto free_apwr_gpio;
ret = gpio_direction_output(GPIO_E740_AMP_ON, 0);
if (ret)
goto free_apwr_gpio;
ret = gpio_direction_output(GPIO_E740_WM9705_nAVDD2, 1);
if (ret)
goto free_apwr_gpio;
e740_snd_device = platform_device_alloc("soc-audio", -1);
if (!e740_snd_device) {
ret = -ENOMEM;
goto free_apwr_gpio;
}
platform_set_drvdata(e740_snd_device, &e740);
ret = platform_device_add(e740_snd_device);
if (!ret)
return 0;
platform_device_put(e740_snd_device);
free_apwr_gpio:
gpio_free(GPIO_E740_WM9705_nAVDD2);
free_op_amp_gpio:
gpio_free(GPIO_E740_AMP_ON);
free_mic_amp_gpio:
gpio_free(GPIO_E740_MIC_ON);
return ret;
}
static void __exit e740_exit(void)
{
platform_device_unregister(e740_snd_device);
gpio_free(GPIO_E740_WM9705_nAVDD2);
gpio_free(GPIO_E740_AMP_ON);
gpio_free(GPIO_E740_MIC_ON);
}
