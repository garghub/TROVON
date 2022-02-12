static int dmic_daiops_trigger(struct snd_pcm_substream *substream,
int cmd, struct snd_soc_dai *dai)
{
struct gpio_desc *dmic_en = snd_soc_dai_get_drvdata(dai);
if (!dmic_en)
return 0;
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
case SNDRV_PCM_TRIGGER_RESUME:
case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
gpiod_set_value(dmic_en, 1);
break;
case SNDRV_PCM_TRIGGER_STOP:
case SNDRV_PCM_TRIGGER_SUSPEND:
case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
gpiod_set_value(dmic_en, 0);
break;
}
return 0;
}
static int dmic_codec_probe(struct snd_soc_codec *codec)
{
struct gpio_desc *dmic_en;
dmic_en = devm_gpiod_get_optional(codec->dev,
"dmicen", GPIOD_OUT_LOW);
if (IS_ERR(dmic_en))
return PTR_ERR(dmic_en);
snd_soc_codec_set_drvdata(codec, dmic_en);
return 0;
}
static int dmic_dev_probe(struct platform_device *pdev)
{
return snd_soc_register_codec(&pdev->dev,
&soc_dmic, &dmic_dai, 1);
}
static int dmic_dev_remove(struct platform_device *pdev)
{
snd_soc_unregister_codec(&pdev->dev);
return 0;
}
