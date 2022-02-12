static int lm4857_get_mode(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_kcontrol_chip(kcontrol);
struct lm4857 *lm4857 = snd_soc_codec_get_drvdata(codec);
ucontrol->value.integer.value[0] = lm4857->mode;
return 0;
}
static int lm4857_set_mode(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_kcontrol_chip(kcontrol);
struct lm4857 *lm4857 = snd_soc_codec_get_drvdata(codec);
uint8_t value = ucontrol->value.integer.value[0];
lm4857->mode = value;
if (codec->dapm.bias_level == SND_SOC_BIAS_ON)
regmap_update_bits(lm4857->regmap, LM4857_CTRL, 0x0F, value + 6);
return 1;
}
static int lm4857_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
struct lm4857 *lm4857 = snd_soc_codec_get_drvdata(codec);
switch (level) {
case SND_SOC_BIAS_ON:
regmap_update_bits(lm4857->regmap, LM4857_CTRL, 0x0F,
lm4857->mode + 6);
break;
case SND_SOC_BIAS_STANDBY:
regmap_update_bits(lm4857->regmap, LM4857_CTRL, 0x0F, 0);
break;
default:
break;
}
codec->dapm.bias_level = level;
return 0;
}
static int lm4857_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct lm4857 *lm4857;
lm4857 = devm_kzalloc(&i2c->dev, sizeof(*lm4857), GFP_KERNEL);
if (!lm4857)
return -ENOMEM;
i2c_set_clientdata(i2c, lm4857);
lm4857->regmap = devm_regmap_init_i2c(i2c, &lm4857_regmap_config);
if (IS_ERR(lm4857->regmap))
return PTR_ERR(lm4857->regmap);
return snd_soc_register_codec(&i2c->dev, &soc_codec_dev_lm4857, NULL, 0);
}
static int lm4857_i2c_remove(struct i2c_client *i2c)
{
snd_soc_unregister_codec(&i2c->dev);
return 0;
}
