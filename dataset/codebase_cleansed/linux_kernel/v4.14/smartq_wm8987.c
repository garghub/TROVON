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
struct gpio_desc *gpio = snd_soc_card_get_drvdata(&snd_soc_smartq);
gpiod_set_value(gpio, SND_SOC_DAPM_EVENT_OFF(event));
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
static int smartq_probe(struct platform_device *pdev)
{
struct gpio_desc *gpio;
int ret;
platform_set_drvdata(pdev, &snd_soc_smartq);
gpio = devm_gpiod_get(&pdev->dev, "amplifiers shutdown",
GPIOD_OUT_HIGH);
if (IS_ERR(gpio)) {
dev_err(&pdev->dev, "Failed to register GPK12\n");
ret = PTR_ERR(gpio);
goto out;
}
snd_soc_card_set_drvdata(&snd_soc_smartq, gpio);
ret = devm_snd_soc_register_card(&pdev->dev, &snd_soc_smartq);
if (ret)
dev_err(&pdev->dev, "Failed to register card\n");
out:
return ret;
}
