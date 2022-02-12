static int tfa9879_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct tfa9879_priv *tfa9879 = snd_soc_codec_get_drvdata(codec);
int fs;
int i2s_set = 0;
switch (params_rate(params)) {
case 8000:
fs = TFA9879_I2S_FS_8000;
break;
case 11025:
fs = TFA9879_I2S_FS_11025;
break;
case 12000:
fs = TFA9879_I2S_FS_12000;
break;
case 16000:
fs = TFA9879_I2S_FS_16000;
break;
case 22050:
fs = TFA9879_I2S_FS_22050;
break;
case 24000:
fs = TFA9879_I2S_FS_24000;
break;
case 32000:
fs = TFA9879_I2S_FS_32000;
break;
case 44100:
fs = TFA9879_I2S_FS_44100;
break;
case 48000:
fs = TFA9879_I2S_FS_48000;
break;
case 64000:
fs = TFA9879_I2S_FS_64000;
break;
case 88200:
fs = TFA9879_I2S_FS_88200;
break;
case 96000:
fs = TFA9879_I2S_FS_96000;
break;
default:
return -EINVAL;
}
switch (params_width(params)) {
case 16:
i2s_set = TFA9879_I2S_SET_LSB_J_16;
break;
case 24:
i2s_set = TFA9879_I2S_SET_LSB_J_24;
break;
default:
return -EINVAL;
}
if (tfa9879->lsb_justified)
snd_soc_update_bits(codec, TFA9879_SERIAL_INTERFACE_1,
TFA9879_I2S_SET_MASK,
i2s_set << TFA9879_I2S_SET_SHIFT);
snd_soc_update_bits(codec, TFA9879_SERIAL_INTERFACE_1,
TFA9879_I2S_FS_MASK,
fs << TFA9879_I2S_FS_SHIFT);
return 0;
}
static int tfa9879_digital_mute(struct snd_soc_dai *dai, int mute)
{
struct snd_soc_codec *codec = dai->codec;
snd_soc_update_bits(codec, TFA9879_MISC_CONTROL,
TFA9879_S_MUTE_MASK,
!!mute << TFA9879_S_MUTE_SHIFT);
return 0;
}
static int tfa9879_set_fmt(struct snd_soc_dai *dai, unsigned int fmt)
{
struct snd_soc_codec *codec = dai->codec;
struct tfa9879_priv *tfa9879 = snd_soc_codec_get_drvdata(codec);
int i2s_set;
int sck_pol;
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBS_CFS:
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
sck_pol = TFA9879_SCK_POL_NORMAL;
break;
case SND_SOC_DAIFMT_IB_NF:
sck_pol = TFA9879_SCK_POL_INVERSE;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
tfa9879->lsb_justified = 0;
i2s_set = TFA9879_I2S_SET_I2S_24;
break;
case SND_SOC_DAIFMT_LEFT_J:
tfa9879->lsb_justified = 0;
i2s_set = TFA9879_I2S_SET_MSB_J_24;
break;
case SND_SOC_DAIFMT_RIGHT_J:
tfa9879->lsb_justified = 1;
i2s_set = TFA9879_I2S_SET_LSB_J_24;
break;
default:
return -EINVAL;
}
snd_soc_update_bits(codec, TFA9879_SERIAL_INTERFACE_1,
TFA9879_SCK_POL_MASK,
sck_pol << TFA9879_SCK_POL_SHIFT);
snd_soc_update_bits(codec, TFA9879_SERIAL_INTERFACE_1,
TFA9879_I2S_SET_MASK,
i2s_set << TFA9879_I2S_SET_SHIFT);
return 0;
}
static bool tfa9879_volatile_reg(struct device *dev, unsigned int reg)
{
return reg == TFA9879_MISC_STATUS;
}
static int tfa9879_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct tfa9879_priv *tfa9879;
int i;
tfa9879 = devm_kzalloc(&i2c->dev, sizeof(*tfa9879), GFP_KERNEL);
if (!tfa9879)
return -ENOMEM;
i2c_set_clientdata(i2c, tfa9879);
tfa9879->regmap = devm_regmap_init_i2c(i2c, &tfa9879_regmap);
if (IS_ERR(tfa9879->regmap))
return PTR_ERR(tfa9879->regmap);
for (i = 0; i < ARRAY_SIZE(tfa9879_regs); i++)
regmap_write(tfa9879->regmap,
tfa9879_regs[i].reg, tfa9879_regs[i].def);
return snd_soc_register_codec(&i2c->dev, &tfa9879_codec,
&tfa9879_dai, 1);
}
static int tfa9879_i2c_remove(struct i2c_client *client)
{
snd_soc_unregister_codec(&client->dev);
return 0;
}
