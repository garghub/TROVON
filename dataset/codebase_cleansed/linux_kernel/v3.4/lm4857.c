static int lm4857_write(struct snd_soc_codec *codec, unsigned int reg,
unsigned int value)
{
uint8_t data;
int ret;
ret = snd_soc_cache_write(codec, reg, value);
if (ret < 0)
return ret;
data = (reg << 6) | value;
ret = i2c_master_send(codec->control_data, &data, 1);
if (ret != 1) {
dev_err(codec->dev, "Failed to write register: %d\n", ret);
return ret;
}
return 0;
}
static unsigned int lm4857_read(struct snd_soc_codec *codec,
unsigned int reg)
{
unsigned int val;
int ret;
ret = snd_soc_cache_read(codec, reg, &val);
if (ret)
return -1;
return val;
}
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
snd_soc_update_bits(codec, LM4857_CTRL, 0x0F, value + 6);
return 1;
}
static int lm4857_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
struct lm4857 *lm4857 = snd_soc_codec_get_drvdata(codec);
switch (level) {
case SND_SOC_BIAS_ON:
snd_soc_update_bits(codec, LM4857_CTRL, 0x0F, lm4857->mode + 6);
break;
case SND_SOC_BIAS_STANDBY:
snd_soc_update_bits(codec, LM4857_CTRL, 0x0F, 0);
break;
default:
break;
}
codec->dapm.bias_level = level;
return 0;
}
static int lm4857_probe(struct snd_soc_codec *codec)
{
struct lm4857 *lm4857 = snd_soc_codec_get_drvdata(codec);
struct snd_soc_dapm_context *dapm = &codec->dapm;
int ret;
codec->control_data = lm4857->i2c;
ret = snd_soc_add_codec_controls(codec, lm4857_controls,
ARRAY_SIZE(lm4857_controls));
if (ret)
return ret;
ret = snd_soc_dapm_new_controls(dapm, lm4857_dapm_widgets,
ARRAY_SIZE(lm4857_dapm_widgets));
if (ret)
return ret;
ret = snd_soc_dapm_add_routes(dapm, lm4857_routes,
ARRAY_SIZE(lm4857_routes));
if (ret)
return ret;
snd_soc_dapm_new_widgets(dapm);
return 0;
}
static int __devinit lm4857_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct lm4857 *lm4857;
int ret;
lm4857 = devm_kzalloc(&i2c->dev, sizeof(*lm4857), GFP_KERNEL);
if (!lm4857)
return -ENOMEM;
i2c_set_clientdata(i2c, lm4857);
lm4857->i2c = i2c;
ret = snd_soc_register_codec(&i2c->dev, &soc_codec_dev_lm4857, NULL, 0);
return ret;
}
static int __devexit lm4857_i2c_remove(struct i2c_client *i2c)
{
snd_soc_unregister_codec(&i2c->dev);
return 0;
}
static int __init lm4857_init(void)
{
return i2c_add_driver(&lm4857_i2c_driver);
}
static void __exit lm4857_exit(void)
{
i2c_del_driver(&lm4857_i2c_driver);
}
