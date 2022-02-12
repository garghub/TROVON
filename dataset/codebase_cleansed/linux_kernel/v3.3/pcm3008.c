static void pcm3008_gpio_free(struct pcm3008_setup_data *setup)
{
gpio_free(setup->dem0_pin);
gpio_free(setup->dem1_pin);
gpio_free(setup->pdad_pin);
gpio_free(setup->pdda_pin);
}
static int pcm3008_soc_probe(struct snd_soc_codec *codec)
{
struct pcm3008_setup_data *setup = codec->dev->platform_data;
int ret = 0;
printk(KERN_INFO "PCM3008 SoC Audio Codec %s\n", PCM3008_VERSION);
ret = gpio_request(setup->dem0_pin, "codec_dem0");
if (ret == 0)
ret = gpio_direction_output(setup->dem0_pin, 1);
if (ret != 0)
goto gpio_err;
ret = gpio_request(setup->dem1_pin, "codec_dem1");
if (ret == 0)
ret = gpio_direction_output(setup->dem1_pin, 0);
if (ret != 0)
goto gpio_err;
ret = gpio_request(setup->pdad_pin, "codec_pdad");
if (ret == 0)
ret = gpio_direction_output(setup->pdad_pin, 1);
if (ret != 0)
goto gpio_err;
ret = gpio_request(setup->pdda_pin, "codec_pdda");
if (ret == 0)
ret = gpio_direction_output(setup->pdda_pin, 1);
if (ret != 0)
goto gpio_err;
return ret;
gpio_err:
pcm3008_gpio_free(setup);
return ret;
}
static int pcm3008_soc_remove(struct snd_soc_codec *codec)
{
struct pcm3008_setup_data *setup = codec->dev->platform_data;
pcm3008_gpio_free(setup);
return 0;
}
static int pcm3008_soc_suspend(struct snd_soc_codec *codec)
{
struct pcm3008_setup_data *setup = codec->dev->platform_data;
gpio_set_value(setup->pdad_pin, 0);
gpio_set_value(setup->pdda_pin, 0);
return 0;
}
static int pcm3008_soc_resume(struct snd_soc_codec *codec)
{
struct pcm3008_setup_data *setup = codec->dev->platform_data;
gpio_set_value(setup->pdad_pin, 1);
gpio_set_value(setup->pdda_pin, 1);
return 0;
}
static int __devinit pcm3008_codec_probe(struct platform_device *pdev)
{
return snd_soc_register_codec(&pdev->dev,
&soc_codec_dev_pcm3008, &pcm3008_dai, 1);
}
static int __devexit pcm3008_codec_remove(struct platform_device *pdev)
{
snd_soc_unregister_codec(&pdev->dev);
return 0;
}
