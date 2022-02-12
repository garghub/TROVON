static int isabelle_hs_mute(struct snd_soc_dai *dai, int mute)
{
snd_soc_update_bits(dai->codec, ISABELLE_DAC1_SOFTRAMP_REG,
BIT(4), (mute ? BIT(4) : 0));
return 0;
}
static int isabelle_hf_mute(struct snd_soc_dai *dai, int mute)
{
snd_soc_update_bits(dai->codec, ISABELLE_DAC2_SOFTRAMP_REG,
BIT(4), (mute ? BIT(4) : 0));
return 0;
}
static int isabelle_line_mute(struct snd_soc_dai *dai, int mute)
{
snd_soc_update_bits(dai->codec, ISABELLE_DAC3_SOFTRAMP_REG,
BIT(4), (mute ? BIT(4) : 0));
return 0;
}
static int isabelle_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
switch (level) {
case SND_SOC_BIAS_ON:
break;
case SND_SOC_BIAS_PREPARE:
break;
case SND_SOC_BIAS_STANDBY:
snd_soc_update_bits(codec, ISABELLE_PWR_EN_REG,
ISABELLE_CHIP_EN, BIT(0));
break;
case SND_SOC_BIAS_OFF:
snd_soc_update_bits(codec, ISABELLE_PWR_EN_REG,
ISABELLE_CHIP_EN, 0);
break;
}
codec->dapm.bias_level = level;
return 0;
}
static int isabelle_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
u16 aif = 0;
unsigned int fs_val = 0;
switch (params_rate(params)) {
case 8000:
fs_val = ISABELLE_FS_RATE_8;
break;
case 11025:
fs_val = ISABELLE_FS_RATE_11;
break;
case 12000:
fs_val = ISABELLE_FS_RATE_12;
break;
case 16000:
fs_val = ISABELLE_FS_RATE_16;
break;
case 22050:
fs_val = ISABELLE_FS_RATE_22;
break;
case 24000:
fs_val = ISABELLE_FS_RATE_24;
break;
case 32000:
fs_val = ISABELLE_FS_RATE_32;
break;
case 44100:
fs_val = ISABELLE_FS_RATE_44;
break;
case 48000:
fs_val = ISABELLE_FS_RATE_48;
break;
default:
return -EINVAL;
}
snd_soc_update_bits(codec, ISABELLE_FS_RATE_CFG_REG,
ISABELLE_FS_RATE_MASK, fs_val);
switch (params_width(params)) {
case 20:
aif |= ISABELLE_AIF_LENGTH_20;
break;
case 32:
aif |= ISABELLE_AIF_LENGTH_32;
break;
default:
return -EINVAL;
}
snd_soc_update_bits(codec, ISABELLE_INTF_CFG_REG,
ISABELLE_AIF_LENGTH_MASK, aif);
return 0;
}
static int isabelle_set_dai_fmt(struct snd_soc_dai *codec_dai, unsigned int fmt)
{
struct snd_soc_codec *codec = codec_dai->codec;
unsigned int aif_val = 0;
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBS_CFS:
aif_val &= ~ISABELLE_AIF_MS;
break;
case SND_SOC_DAIFMT_CBM_CFM:
aif_val |= ISABELLE_AIF_MS;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
aif_val |= ISABELLE_I2S_MODE;
break;
case SND_SOC_DAIFMT_LEFT_J:
aif_val |= ISABELLE_LEFT_J_MODE;
break;
case SND_SOC_DAIFMT_PDM:
aif_val |= ISABELLE_PDM_MODE;
break;
default:
return -EINVAL;
}
snd_soc_update_bits(codec, ISABELLE_INTF_CFG_REG,
(ISABELLE_AIF_MS | ISABELLE_AIF_FMT_MASK), aif_val);
return 0;
}
static int isabelle_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct regmap *isabelle_regmap;
int ret = 0;
isabelle_regmap = devm_regmap_init_i2c(i2c, &isabelle_regmap_config);
if (IS_ERR(isabelle_regmap)) {
ret = PTR_ERR(isabelle_regmap);
dev_err(&i2c->dev, "Failed to allocate register map: %d\n",
ret);
return ret;
}
i2c_set_clientdata(i2c, isabelle_regmap);
ret = snd_soc_register_codec(&i2c->dev,
&soc_codec_dev_isabelle, isabelle_dai,
ARRAY_SIZE(isabelle_dai));
if (ret < 0) {
dev_err(&i2c->dev, "Failed to register codec: %d\n", ret);
return ret;
}
return ret;
}
static int isabelle_i2c_remove(struct i2c_client *client)
{
snd_soc_unregister_codec(&client->dev);
return 0;
}
