static int max98357a_daiops_trigger(struct snd_pcm_substream *substream,
int cmd, struct snd_soc_dai *dai)
{
struct gpio_desc *sdmode = snd_soc_dai_get_drvdata(dai);
if (!sdmode)
return 0;
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
case SNDRV_PCM_TRIGGER_RESUME:
case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
gpiod_set_value(sdmode, 1);
break;
case SNDRV_PCM_TRIGGER_STOP:
case SNDRV_PCM_TRIGGER_SUSPEND:
case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
gpiod_set_value(sdmode, 0);
break;
}
return 0;
}
static int max98357a_codec_probe(struct snd_soc_codec *codec)
{
struct gpio_desc *sdmode;
sdmode = devm_gpiod_get_optional(codec->dev, "sdmode", GPIOD_OUT_LOW);
if (IS_ERR(sdmode))
return PTR_ERR(sdmode);
snd_soc_codec_set_drvdata(codec, sdmode);
return 0;
}
static int max98357a_platform_probe(struct platform_device *pdev)
{
return snd_soc_register_codec(&pdev->dev, &max98357a_codec_driver,
&max98357a_dai_driver, 1);
}
static int max98357a_platform_remove(struct platform_device *pdev)
{
snd_soc_unregister_codec(&pdev->dev);
return 0;
}
