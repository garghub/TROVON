static int aud96p22_adc_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
struct aud96p22_priv *priv = snd_soc_codec_get_drvdata(codec);
struct regmap *regmap = priv->regmap;
if (event != SND_SOC_DAPM_POST_PMU)
return -EINVAL;
regmap_update_bits(regmap, AUD96P22_RESET, RST_ADC_DPZ, 0);
regmap_update_bits(regmap, AUD96P22_RESET, RST_ADC_DPZ, RST_ADC_DPZ);
return 0;
}
static int aud96p22_dac_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
struct aud96p22_priv *priv = snd_soc_codec_get_drvdata(codec);
struct regmap *regmap = priv->regmap;
if (event != SND_SOC_DAPM_POST_PMU)
return -EINVAL;
regmap_update_bits(regmap, AUD96P22_RESET, RST_DAC_DPZ, 0);
regmap_update_bits(regmap, AUD96P22_RESET, RST_DAC_DPZ, RST_DAC_DPZ);
return 0;
}
static int aud96p22_set_fmt(struct snd_soc_dai *dai, unsigned int fmt)
{
struct aud96p22_priv *priv = snd_soc_codec_get_drvdata(dai->codec);
struct regmap *regmap = priv->regmap;
unsigned int val;
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBS_CFS:
val = 0;
break;
case SND_SOC_DAIFMT_CBM_CFM:
val = I2S1_MS_MODE;
break;
default:
return -EINVAL;
}
regmap_update_bits(regmap, AUD96P22_I2S1_CONFIG_0, I2S1_MS_MODE, val);
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_RIGHT_J:
val = I2S1_MODE_RIGHT_J;
break;
case SND_SOC_DAIFMT_I2S:
val = I2S1_MODE_I2S;
break;
case SND_SOC_DAIFMT_LEFT_J:
val = I2S1_MODE_LEFT_J;
break;
default:
return -EINVAL;
}
regmap_update_bits(regmap, AUD96P22_I2S1_CONFIG_0, I2S1_MODE_MASK, val);
return 0;
}
static int aud96p22_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct device *dev = &i2c->dev;
struct aud96p22_priv *priv;
int ret;
priv = devm_kzalloc(dev, sizeof(*priv), GFP_KERNEL);
if (priv == NULL)
return -ENOMEM;
priv->regmap = devm_regmap_init_i2c(i2c, &aud96p22_regmap);
if (IS_ERR(priv->regmap)) {
ret = PTR_ERR(priv->regmap);
dev_err(dev, "failed to init i2c regmap: %d\n", ret);
return ret;
}
i2c_set_clientdata(i2c, priv);
ret = snd_soc_register_codec(dev, &aud96p22_driver, &aud96p22_dai, 1);
if (ret) {
dev_err(dev, "failed to register codec: %d\n", ret);
return ret;
}
return 0;
}
static int aud96p22_i2c_remove(struct i2c_client *i2c)
{
snd_soc_unregister_codec(&i2c->dev);
return 0;
}
