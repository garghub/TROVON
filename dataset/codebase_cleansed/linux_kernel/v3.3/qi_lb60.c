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
static int __init qi_lb60_init(void)
{
int ret;
qi_lb60_snd_device = platform_device_alloc("soc-audio", -1);
if (!qi_lb60_snd_device)
return -ENOMEM;
ret = gpio_request_array(qi_lb60_gpios, ARRAY_SIZE(qi_lb60_gpios));
if (ret) {
pr_err("qi_lb60 snd: Failed to request gpios: %d\n", ret);
goto err_device_put;
}
platform_set_drvdata(qi_lb60_snd_device, &qi_lb60);
ret = platform_device_add(qi_lb60_snd_device);
if (ret) {
pr_err("qi_lb60 snd: Failed to add snd soc device: %d\n", ret);
goto err_unset_pdata;
}
return 0;
err_unset_pdata:
platform_set_drvdata(qi_lb60_snd_device, NULL);
gpio_free_array(qi_lb60_gpios, ARRAY_SIZE(qi_lb60_gpios));
err_device_put:
platform_device_put(qi_lb60_snd_device);
return ret;
}
static void __exit qi_lb60_exit(void)
{
platform_device_unregister(qi_lb60_snd_device);
gpio_free_array(qi_lb60_gpios, ARRAY_SIZE(qi_lb60_gpios));
}
