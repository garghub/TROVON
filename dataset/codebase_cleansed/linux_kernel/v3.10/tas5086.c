static bool tas5086_accessible_reg(struct device *dev, unsigned int reg)
{
return !((reg == 0x0f) || (reg >= 0x11 && reg <= 0x17));
}
static bool tas5086_volatile_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case TAS5086_DEV_ID:
case TAS5086_ERROR_STATUS:
return true;
}
return false;
}
static bool tas5086_writeable_reg(struct device *dev, unsigned int reg)
{
return tas5086_accessible_reg(dev, reg) && (reg != TAS5086_DEV_ID);
}
static int tas5086_set_deemph(struct snd_soc_codec *codec)
{
struct tas5086_private *priv = snd_soc_codec_get_drvdata(codec);
int i, val = 0;
if (priv->deemph)
for (i = 0; i < ARRAY_SIZE(tas5086_deemph); i++)
if (tas5086_deemph[i] == priv->rate)
val = i;
return regmap_update_bits(priv->regmap, TAS5086_SYS_CONTROL_1,
TAS5086_DEEMPH_MASK, val);
}
static int tas5086_get_deemph(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_kcontrol_chip(kcontrol);
struct tas5086_private *priv = snd_soc_codec_get_drvdata(codec);
ucontrol->value.enumerated.item[0] = priv->deemph;
return 0;
}
static int tas5086_put_deemph(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_kcontrol_chip(kcontrol);
struct tas5086_private *priv = snd_soc_codec_get_drvdata(codec);
priv->deemph = ucontrol->value.enumerated.item[0];
return tas5086_set_deemph(codec);
}
static int tas5086_set_dai_sysclk(struct snd_soc_dai *codec_dai,
int clk_id, unsigned int freq, int dir)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct tas5086_private *priv = snd_soc_codec_get_drvdata(codec);
switch (clk_id) {
case TAS5086_CLK_IDX_MCLK:
priv->mclk = freq;
break;
case TAS5086_CLK_IDX_SCLK:
priv->sclk = freq;
break;
}
return 0;
}
static int tas5086_set_dai_fmt(struct snd_soc_dai *codec_dai,
unsigned int format)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct tas5086_private *priv = snd_soc_codec_get_drvdata(codec);
if ((format & SND_SOC_DAIFMT_MASTER_MASK) != SND_SOC_DAIFMT_CBS_CFS) {
dev_err(codec->dev, "Invalid clocking mode\n");
return -EINVAL;
}
priv->format = format;
return 0;
}
static int index_in_array(const int *array, int len, int needle)
{
int i;
for (i = 0; i < len; i++)
if (array[i] == needle)
return i;
return -ENOENT;
}
static int tas5086_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct tas5086_private *priv = snd_soc_codec_get_drvdata(codec);
int val;
int ret;
priv->rate = params_rate(params);
val = index_in_array(tas5086_sample_rates,
ARRAY_SIZE(tas5086_sample_rates), priv->rate);
if (val < 0) {
dev_err(codec->dev, "Invalid sample rate\n");
return -EINVAL;
}
ret = regmap_update_bits(priv->regmap, TAS5086_CLOCK_CONTROL,
TAS5086_CLOCK_RATE_MASK,
TAS5086_CLOCK_RATE(val));
if (ret < 0)
return ret;
val = index_in_array(tas5086_ratios, ARRAY_SIZE(tas5086_ratios),
priv->mclk / priv->rate);
if (val < 0) {
dev_err(codec->dev, "Inavlid MCLK / Fs ratio\n");
return -EINVAL;
}
ret = regmap_update_bits(priv->regmap, TAS5086_CLOCK_CONTROL,
TAS5086_CLOCK_RATIO_MASK,
TAS5086_CLOCK_RATIO(val));
if (ret < 0)
return ret;
ret = regmap_update_bits(priv->regmap, TAS5086_CLOCK_CONTROL,
TAS5086_CLOCK_SCLK_RATIO_48,
(priv->sclk == 48 * priv->rate) ?
TAS5086_CLOCK_SCLK_RATIO_48 : 0);
if (ret < 0)
return ret;
switch (priv->format & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_RIGHT_J:
val = 0x00;
break;
case SND_SOC_DAIFMT_I2S:
val = 0x03;
break;
case SND_SOC_DAIFMT_LEFT_J:
val = 0x06;
break;
default:
dev_err(codec->dev, "Invalid DAI format\n");
return -EINVAL;
}
switch (params_format(params)) {
case SNDRV_PCM_FORMAT_S16_LE:
val += 0;
break;
case SNDRV_PCM_FORMAT_S20_3LE:
val += 1;
break;
case SNDRV_PCM_FORMAT_S24_3LE:
val += 2;
break;
default:
dev_err(codec->dev, "Invalid bit width\n");
return -EINVAL;
};
ret = regmap_write(priv->regmap, TAS5086_SERIAL_DATA_IF, val);
if (ret < 0)
return ret;
ret = regmap_update_bits(priv->regmap, TAS5086_CLOCK_CONTROL,
TAS5086_CLOCK_VALID, TAS5086_CLOCK_VALID);
if (ret < 0)
return ret;
return tas5086_set_deemph(codec);
}
static int tas5086_mute_stream(struct snd_soc_dai *dai, int mute, int stream)
{
struct snd_soc_codec *codec = dai->codec;
struct tas5086_private *priv = snd_soc_codec_get_drvdata(codec);
unsigned int val = 0;
if (mute)
val = TAS5086_SOFT_MUTE_ALL;
return regmap_write(priv->regmap, TAS5086_SOFT_MUTE, val);
}
static int tas5086_soc_resume(struct snd_soc_codec *codec)
{
struct tas5086_private *priv = snd_soc_codec_get_drvdata(codec);
return regcache_sync(priv->regmap);
}
static int tas5086_probe(struct snd_soc_codec *codec)
{
struct tas5086_private *priv = snd_soc_codec_get_drvdata(codec);
int charge_period = 1300000;
int i, ret;
if (of_match_device(of_match_ptr(tas5086_dt_ids), codec->dev)) {
struct device_node *of_node = codec->dev->of_node;
of_property_read_u32(of_node, "ti,charge-period", &charge_period);
}
if (charge_period == 0) {
regmap_write(priv->regmap, TAS5086_SPLIT_CAP_CHARGE, 0);
} else {
i = index_in_array(tas5086_charge_period,
ARRAY_SIZE(tas5086_charge_period),
charge_period);
if (i >= 0)
regmap_write(priv->regmap, TAS5086_SPLIT_CAP_CHARGE,
i + 0x08);
else
dev_warn(codec->dev,
"Invalid split-cap charge period of %d ns.\n",
charge_period);
}
ret = regmap_write(priv->regmap, TAS5086_OSC_TRIM, 0x00);
if (ret < 0)
return ret;
ret = regmap_write(priv->regmap, TAS5086_SYS_CONTROL_2, 0x20);
if (ret < 0)
return ret;
ret = regmap_write(priv->regmap, TAS5086_MASTER_VOL, 0x30);
if (ret < 0)
return ret;
ret = regmap_write(priv->regmap, TAS5086_SOFT_MUTE,
TAS5086_SOFT_MUTE_ALL);
if (ret < 0)
return ret;
return 0;
}
static int tas5086_remove(struct snd_soc_codec *codec)
{
struct tas5086_private *priv = snd_soc_codec_get_drvdata(codec);
if (gpio_is_valid(priv->gpio_nreset))
gpio_set_value(priv->gpio_nreset, 0);
return 0;
}
static int tas5086_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct tas5086_private *priv;
struct device *dev = &i2c->dev;
int gpio_nreset = -EINVAL;
int i, ret;
priv = devm_kzalloc(dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
priv->regmap = devm_regmap_init_i2c(i2c, &tas5086_regmap);
if (IS_ERR(priv->regmap)) {
ret = PTR_ERR(priv->regmap);
dev_err(&i2c->dev, "Failed to create regmap: %d\n", ret);
return ret;
}
i2c_set_clientdata(i2c, priv);
if (of_match_device(of_match_ptr(tas5086_dt_ids), dev)) {
struct device_node *of_node = dev->of_node;
gpio_nreset = of_get_named_gpio(of_node, "reset-gpio", 0);
}
if (gpio_is_valid(gpio_nreset))
if (devm_gpio_request(dev, gpio_nreset, "TAS5086 Reset"))
gpio_nreset = -EINVAL;
if (gpio_is_valid(gpio_nreset)) {
gpio_direction_output(gpio_nreset, 0);
udelay(1);
gpio_set_value(gpio_nreset, 1);
msleep(15);
}
priv->gpio_nreset = gpio_nreset;
ret = regmap_read(priv->regmap, TAS5086_DEV_ID, &i);
if (ret < 0)
return ret;
if (i != 0x3) {
dev_err(dev,
"Failed to identify TAS5086 codec (got %02x)\n", i);
return -ENODEV;
}
return snd_soc_register_codec(&i2c->dev, &soc_codec_dev_tas5086,
&tas5086_dai, 1);
}
static int tas5086_i2c_remove(struct i2c_client *i2c)
{
snd_soc_unregister_codec(&i2c->dev);
return 0;
}
