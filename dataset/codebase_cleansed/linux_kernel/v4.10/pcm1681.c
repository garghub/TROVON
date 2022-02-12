static bool pcm1681_accessible_reg(struct device *dev, unsigned int reg)
{
return !((reg == 0x00) || (reg == 0x0f));
}
static bool pcm1681_writeable_reg(struct device *dev, unsigned int reg)
{
return pcm1681_accessible_reg(dev, reg) &&
(reg != PCM1681_ZERO_DETECT_STATUS);
}
static int pcm1681_set_deemph(struct snd_soc_codec *codec)
{
struct pcm1681_private *priv = snd_soc_codec_get_drvdata(codec);
int i = 0, val = -1, enable = 0;
if (priv->deemph) {
for (i = 0; i < ARRAY_SIZE(pcm1681_deemph); i++) {
if (pcm1681_deemph[i] == priv->rate) {
val = i;
break;
}
}
}
if (val != -1) {
regmap_update_bits(priv->regmap, PCM1681_DEEMPH_CONTROL,
PCM1681_DEEMPH_RATE_MASK, val << 3);
enable = 1;
} else {
enable = 0;
}
return regmap_update_bits(priv->regmap, PCM1681_DEEMPH_CONTROL,
PCM1681_DEEMPH_MASK, enable);
}
static int pcm1681_get_deemph(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_soc_kcontrol_codec(kcontrol);
struct pcm1681_private *priv = snd_soc_codec_get_drvdata(codec);
ucontrol->value.integer.value[0] = priv->deemph;
return 0;
}
static int pcm1681_put_deemph(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_soc_kcontrol_codec(kcontrol);
struct pcm1681_private *priv = snd_soc_codec_get_drvdata(codec);
priv->deemph = ucontrol->value.integer.value[0];
return pcm1681_set_deemph(codec);
}
static int pcm1681_set_dai_fmt(struct snd_soc_dai *codec_dai,
unsigned int format)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct pcm1681_private *priv = snd_soc_codec_get_drvdata(codec);
if ((format & SND_SOC_DAIFMT_MASTER_MASK) != SND_SOC_DAIFMT_CBS_CFS) {
dev_err(codec->dev, "Invalid clocking mode\n");
return -EINVAL;
}
priv->format = format;
return 0;
}
static int pcm1681_digital_mute(struct snd_soc_dai *dai, int mute)
{
struct snd_soc_codec *codec = dai->codec;
struct pcm1681_private *priv = snd_soc_codec_get_drvdata(codec);
int val;
if (mute)
val = PCM1681_SOFT_MUTE_ALL;
else
val = 0;
return regmap_write(priv->regmap, PCM1681_SOFT_MUTE, val);
}
static int pcm1681_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct pcm1681_private *priv = snd_soc_codec_get_drvdata(codec);
int val = 0, ret;
priv->rate = params_rate(params);
switch (priv->format & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_RIGHT_J:
switch (params_width(params)) {
case 24:
val = 0;
break;
case 16:
val = 3;
break;
default:
return -EINVAL;
}
break;
case SND_SOC_DAIFMT_I2S:
val = 0x04;
break;
case SND_SOC_DAIFMT_LEFT_J:
val = 0x05;
break;
default:
dev_err(codec->dev, "Invalid DAI format\n");
return -EINVAL;
}
ret = regmap_update_bits(priv->regmap, PCM1681_FMT_CONTROL, 0x0f, val);
if (ret < 0)
return ret;
return pcm1681_set_deemph(codec);
}
static int pcm1681_i2c_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
int ret;
struct pcm1681_private *priv;
priv = devm_kzalloc(&client->dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
priv->regmap = devm_regmap_init_i2c(client, &pcm1681_regmap);
if (IS_ERR(priv->regmap)) {
ret = PTR_ERR(priv->regmap);
dev_err(&client->dev, "Failed to create regmap: %d\n", ret);
return ret;
}
i2c_set_clientdata(client, priv);
return snd_soc_register_codec(&client->dev, &soc_codec_dev_pcm1681,
&pcm1681_dai, 1);
}
static int pcm1681_i2c_remove(struct i2c_client *client)
{
snd_soc_unregister_codec(&client->dev);
return 0;
}
