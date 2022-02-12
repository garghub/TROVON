static int ak5386_soc_probe(struct snd_soc_codec *codec)
{
struct ak5386_priv *priv = snd_soc_codec_get_drvdata(codec);
return regulator_bulk_enable(ARRAY_SIZE(priv->supplies), priv->supplies);
}
static int ak5386_soc_remove(struct snd_soc_codec *codec)
{
struct ak5386_priv *priv = snd_soc_codec_get_drvdata(codec);
regulator_bulk_disable(ARRAY_SIZE(priv->supplies), priv->supplies);
return 0;
}
static int ak5386_soc_suspend(struct snd_soc_codec *codec)
{
struct ak5386_priv *priv = snd_soc_codec_get_drvdata(codec);
regulator_bulk_disable(ARRAY_SIZE(priv->supplies), priv->supplies);
return 0;
}
static int ak5386_soc_resume(struct snd_soc_codec *codec)
{
struct ak5386_priv *priv = snd_soc_codec_get_drvdata(codec);
return regulator_bulk_enable(ARRAY_SIZE(priv->supplies), priv->supplies);
}
static int ak5386_set_dai_fmt(struct snd_soc_dai *codec_dai,
unsigned int format)
{
struct snd_soc_codec *codec = codec_dai->codec;
format &= SND_SOC_DAIFMT_FORMAT_MASK;
if (format != SND_SOC_DAIFMT_LEFT_J &&
format != SND_SOC_DAIFMT_I2S) {
dev_err(codec->dev, "Invalid DAI format\n");
return -EINVAL;
}
return 0;
}
static int ak5386_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct ak5386_priv *priv = snd_soc_codec_get_drvdata(codec);
if (gpio_is_valid(priv->reset_gpio))
gpio_set_value(priv->reset_gpio, 1);
return 0;
}
static int ak5386_hw_free(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct ak5386_priv *priv = snd_soc_codec_get_drvdata(codec);
if (gpio_is_valid(priv->reset_gpio))
gpio_set_value(priv->reset_gpio, 0);
return 0;
}
static int ak5386_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct ak5386_priv *priv;
int ret, i;
priv = devm_kzalloc(dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
priv->reset_gpio = -EINVAL;
dev_set_drvdata(dev, priv);
for (i = 0; i < ARRAY_SIZE(supply_names); i++)
priv->supplies[i].supply = supply_names[i];
ret = devm_regulator_bulk_get(dev, ARRAY_SIZE(priv->supplies),
priv->supplies);
if (ret < 0)
return ret;
if (of_match_device(of_match_ptr(ak5386_dt_ids), dev))
priv->reset_gpio = of_get_named_gpio(dev->of_node,
"reset-gpio", 0);
if (gpio_is_valid(priv->reset_gpio))
if (devm_gpio_request_one(dev, priv->reset_gpio,
GPIOF_OUT_INIT_LOW,
"AK5386 Reset"))
priv->reset_gpio = -EINVAL;
return snd_soc_register_codec(dev, &soc_codec_ak5386,
&ak5386_dai, 1);
}
static int ak5386_remove(struct platform_device *pdev)
{
snd_soc_unregister_codec(&pdev->dev);
return 0;
}
