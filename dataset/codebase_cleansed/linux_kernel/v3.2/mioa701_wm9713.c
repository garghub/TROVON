static int rear_amp_power(struct snd_soc_codec *codec, int power)
{
unsigned short reg;
if (power) {
reg = snd_soc_read(codec, AC97_GPIO_CFG);
snd_soc_write(codec, AC97_GPIO_CFG, reg | 0x0100);
reg = snd_soc_read(codec, AC97_GPIO_PULL);
snd_soc_write(codec, AC97_GPIO_PULL, reg | (1<<15));
} else {
reg = snd_soc_read(codec, AC97_GPIO_CFG);
snd_soc_write(codec, AC97_GPIO_CFG, reg & ~0x0100);
reg = snd_soc_read(codec, AC97_GPIO_PULL);
snd_soc_write(codec, AC97_GPIO_PULL, reg & ~(1<<15));
}
return 0;
}
static int rear_amp_event(struct snd_soc_dapm_widget *widget,
struct snd_kcontrol *kctl, int event)
{
struct snd_soc_codec *codec = widget->codec;
return rear_amp_power(codec, SND_SOC_DAPM_EVENT_ON(event));
}
static int mioa701_wm9713_init(struct snd_soc_pcm_runtime *rtd)
{
struct snd_soc_codec *codec = rtd->codec;
struct snd_soc_dapm_context *dapm = &codec->dapm;
unsigned short reg;
snd_soc_dapm_new_controls(dapm, ARRAY_AND_SIZE(mioa701_dapm_widgets));
snd_soc_dapm_add_routes(dapm, ARRAY_AND_SIZE(audio_map));
reg = codec->driver->read(codec, AC97_GPIO_CFG);
codec->driver->write(codec, AC97_GPIO_CFG, reg | 0x0100);
reg = codec->driver->read(codec, AC97_3D_CONTROL);
codec->driver->write(codec, AC97_3D_CONTROL, reg | 0xc000);
snd_soc_dapm_enable_pin(dapm, "Front Speaker");
snd_soc_dapm_enable_pin(dapm, "Rear Speaker");
snd_soc_dapm_enable_pin(dapm, "Front Mic");
snd_soc_dapm_enable_pin(dapm, "GSM Line In");
snd_soc_dapm_enable_pin(dapm, "GSM Line Out");
return 0;
}
static int mioa701_wm9713_probe(struct platform_device *pdev)
{
int ret;
if (!machine_is_mioa701())
return -ENODEV;
dev_warn(&pdev->dev, "Be warned that incorrect mixers/muxes setup will"
"lead to overheating and possible destruction of your device."
"Do not use without a good knowledge of mio's board design!\n");
mioa701_snd_device = platform_device_alloc("soc-audio", -1);
if (!mioa701_snd_device)
return -ENOMEM;
platform_set_drvdata(mioa701_snd_device, &mioa701);
ret = platform_device_add(mioa701_snd_device);
if (!ret)
return 0;
platform_device_put(mioa701_snd_device);
return ret;
}
static int __devexit mioa701_wm9713_remove(struct platform_device *pdev)
{
platform_device_unregister(mioa701_snd_device);
return 0;
}
static int __init mioa701_asoc_init(void)
{
return platform_driver_register(&mioa701_wm9713_driver);
}
static void __exit mioa701_asoc_exit(void)
{
platform_driver_unregister(&mioa701_wm9713_driver);
}
