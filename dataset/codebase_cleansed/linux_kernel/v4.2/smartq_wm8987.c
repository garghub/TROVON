static int smartq_hifi_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
struct snd_soc_dai *cpu_dai = rtd->cpu_dai;
unsigned int clk = 0;
int ret;
switch (params_rate(params)) {
case 8000:
case 16000:
case 32000:
case 48000:
case 96000:
clk = 12288000;
break;
case 11025:
case 22050:
case 44100:
case 88200:
clk = 11289600;
break;
}
ret = snd_soc_dai_set_sysclk(cpu_dai, SAMSUNG_I2S_RCLKSRC_0,
0, SND_SOC_CLOCK_IN);
if (ret < 0)
return ret;
ret = snd_soc_dai_set_sysclk(cpu_dai, SAMSUNG_I2S_CDCLK,
0, SND_SOC_CLOCK_IN);
if (ret < 0)
return ret;
ret = snd_soc_dai_set_sysclk(codec_dai, WM8750_SYSCLK, clk,
SND_SOC_CLOCK_IN);
if (ret < 0)
return ret;
return 0;
}
static int smartq_speaker_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *k,
int event)
{
gpio_set_value(S3C64XX_GPK(12), SND_SOC_DAPM_EVENT_OFF(event));
return 0;
}
static int smartq_wm8987_init(struct snd_soc_pcm_runtime *rtd)
{
struct snd_soc_dapm_context *dapm = &rtd->card->dapm;
int err = 0;
snd_soc_dapm_nc_pin(dapm, "LINPUT1");
snd_soc_dapm_nc_pin(dapm, "RINPUT1");
snd_soc_dapm_nc_pin(dapm, "OUT3");
snd_soc_dapm_nc_pin(dapm, "ROUT1");
err = snd_soc_card_jack_new(rtd->card, "Headphone Jack",
SND_JACK_HEADPHONE, &smartq_jack,
smartq_jack_pins,
ARRAY_SIZE(smartq_jack_pins));
if (err)
return err;
err = snd_soc_jack_add_gpios(&smartq_jack,
ARRAY_SIZE(smartq_jack_gpios),
smartq_jack_gpios);
return err;
}
static int smartq_wm8987_card_remove(struct snd_soc_card *card)
{
snd_soc_jack_free_gpios(&smartq_jack, ARRAY_SIZE(smartq_jack_gpios),
smartq_jack_gpios);
return 0;
}
static int __init smartq_init(void)
{
int ret;
if (!machine_is_smartq7() && !machine_is_smartq5()) {
pr_info("Only SmartQ is supported by this ASoC driver\n");
return -ENODEV;
}
smartq_snd_device = platform_device_alloc("soc-audio", -1);
if (!smartq_snd_device)
return -ENOMEM;
platform_set_drvdata(smartq_snd_device, &snd_soc_smartq);
ret = platform_device_add(smartq_snd_device);
if (ret) {
platform_device_put(smartq_snd_device);
return ret;
}
ret = gpio_request(S3C64XX_GPK(12), "amplifiers shutdown");
if (ret) {
dev_err(&smartq_snd_device->dev, "Failed to register GPK12\n");
goto err_unregister_device;
}
ret = gpio_direction_output(S3C64XX_GPK(12), 1);
if (ret) {
dev_err(&smartq_snd_device->dev, "Failed to configure GPK12\n");
goto err_free_gpio_amp_shut;
}
return 0;
err_free_gpio_amp_shut:
gpio_free(S3C64XX_GPK(12));
err_unregister_device:
platform_device_unregister(smartq_snd_device);
return ret;
}
static void __exit smartq_exit(void)
{
gpio_free(S3C64XX_GPK(12));
platform_device_unregister(smartq_snd_device);
}
