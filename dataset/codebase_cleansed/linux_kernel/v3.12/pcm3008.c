static int pcm3008_dac_ev(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol,
int event)
{
struct snd_soc_codec *codec = w->codec;
struct pcm3008_setup_data *setup = codec->dev->platform_data;
gpio_set_value_cansleep(setup->pdda_pin,
SND_SOC_DAPM_EVENT_ON(event));
return 0;
}
static int pcm3008_adc_ev(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol,
int event)
{
struct snd_soc_codec *codec = w->codec;
struct pcm3008_setup_data *setup = codec->dev->platform_data;
gpio_set_value_cansleep(setup->pdad_pin,
SND_SOC_DAPM_EVENT_ON(event));
return 0;
}
static int pcm3008_codec_probe(struct platform_device *pdev)
{
struct pcm3008_setup_data *setup = pdev->dev.platform_data;
int ret;
if (!setup)
return -EINVAL;
ret = devm_gpio_request_one(&pdev->dev, setup->dem0_pin,
GPIOF_OUT_INIT_HIGH, "codec_dem0");
if (ret != 0)
return ret;
ret = devm_gpio_request_one(&pdev->dev, setup->dem1_pin,
GPIOF_OUT_INIT_LOW, "codec_dem1");
if (ret != 0)
return ret;
ret = devm_gpio_request_one(&pdev->dev, setup->pdad_pin,
GPIOF_OUT_INIT_LOW, "codec_pdad");
if (ret != 0)
return ret;
ret = devm_gpio_request_one(&pdev->dev, setup->pdda_pin,
GPIOF_OUT_INIT_LOW, "codec_pdda");
if (ret != 0)
return ret;
return snd_soc_register_codec(&pdev->dev,
&soc_codec_dev_pcm3008, &pcm3008_dai, 1);
}
static int pcm3008_codec_remove(struct platform_device *pdev)
{
snd_soc_unregister_codec(&pdev->dev);
return 0;
}
