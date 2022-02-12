static int da7210_put_alc_sw(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_kcontrol_chip(kcontrol);
if (ucontrol->value.integer.value[0]) {
if (snd_soc_read(codec, DA7210_CONTROL) & DA7210_NOISE_SUP_EN) {
dev_dbg(codec->dev,
"Disable noise suppression to enable ALC\n");
return -EINVAL;
}
}
return snd_soc_put_volsw(kcontrol, ucontrol);
}
static int da7210_put_noise_sup_sw(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_kcontrol_chip(kcontrol);
u8 val;
if (ucontrol->value.integer.value[0]) {
if (snd_soc_read(codec, DA7210_ADC) & DA7210_ADC_ALC_EN)
goto err;
if ((snd_soc_read(codec, DA7210_ZERO_CROSS) &
(DA7210_AUX1_L_ZC | DA7210_AUX1_R_ZC | DA7210_HP_L_ZC |
DA7210_HP_R_ZC)) != (DA7210_AUX1_L_ZC |
DA7210_AUX1_R_ZC | DA7210_HP_L_ZC | DA7210_HP_R_ZC))
goto err;
val = snd_soc_read(codec, DA7210_IN_GAIN);
if (((val & DA7210_INPGA_L_VOL) < DA7210_INPGA_MIN_VOL_NS) ||
(((val & DA7210_INPGA_R_VOL) >> 4) <
DA7210_INPGA_MIN_VOL_NS))
goto err;
if (((snd_soc_read(codec, DA7210_AUX1_L) & DA7210_AUX1_L_VOL) <
DA7210_AUX1_MIN_VOL_NS) ||
((snd_soc_read(codec, DA7210_AUX1_R) & DA7210_AUX1_R_VOL) <
DA7210_AUX1_MIN_VOL_NS))
goto err;
}
return snd_soc_put_volsw(kcontrol, ucontrol);
err:
return -EINVAL;
}
static bool da7210_readable_register(struct device *dev, unsigned int reg)
{
switch (reg) {
case DA7210_A_HID_UNLOCK:
case DA7210_A_TEST_UNLOCK:
case DA7210_A_PLL1:
case DA7210_A_CP_MODE:
return false;
default:
return true;
}
}
static bool da7210_volatile_register(struct device *dev,
unsigned int reg)
{
switch (reg) {
case DA7210_STATUS:
return true;
default:
return false;
}
}
static int da7210_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_codec *codec = rtd->codec;
u32 dai_cfg1;
u32 fs, bypass;
snd_soc_write(codec, DA7210_DAI_SRC_SEL,
DA7210_DAI_OUT_R_SRC | DA7210_DAI_OUT_L_SRC);
snd_soc_write(codec, DA7210_DAI_CFG3, DA7210_DAI_OE | DA7210_DAI_EN);
dai_cfg1 = 0xFC & snd_soc_read(codec, DA7210_DAI_CFG1);
switch (params_format(params)) {
case SNDRV_PCM_FORMAT_S16_LE:
dai_cfg1 |= DA7210_DAI_WORD_S16_LE;
break;
case SNDRV_PCM_FORMAT_S20_3LE:
dai_cfg1 |= DA7210_DAI_WORD_S20_3LE;
break;
case SNDRV_PCM_FORMAT_S24_LE:
dai_cfg1 |= DA7210_DAI_WORD_S24_LE;
break;
case SNDRV_PCM_FORMAT_S32_LE:
dai_cfg1 |= DA7210_DAI_WORD_S32_LE;
break;
default:
return -EINVAL;
}
snd_soc_write(codec, DA7210_DAI_CFG1, dai_cfg1);
switch (params_rate(params)) {
case 8000:
fs = DA7210_PLL_FS_8000;
bypass = DA7210_PLL_BYP;
break;
case 11025:
fs = DA7210_PLL_FS_11025;
bypass = 0;
break;
case 12000:
fs = DA7210_PLL_FS_12000;
bypass = DA7210_PLL_BYP;
break;
case 16000:
fs = DA7210_PLL_FS_16000;
bypass = DA7210_PLL_BYP;
break;
case 22050:
fs = DA7210_PLL_FS_22050;
bypass = 0;
break;
case 32000:
fs = DA7210_PLL_FS_32000;
bypass = DA7210_PLL_BYP;
break;
case 44100:
fs = DA7210_PLL_FS_44100;
bypass = 0;
break;
case 48000:
fs = DA7210_PLL_FS_48000;
bypass = DA7210_PLL_BYP;
break;
case 88200:
fs = DA7210_PLL_FS_88200;
bypass = 0;
break;
case 96000:
fs = DA7210_PLL_FS_96000;
bypass = DA7210_PLL_BYP;
break;
default:
return -EINVAL;
}
snd_soc_update_bits(codec, DA7210_STARTUP1, DA7210_SC_MST_EN, 0);
snd_soc_update_bits(codec, DA7210_PLL, DA7210_PLL_FS_MASK, fs);
snd_soc_update_bits(codec, DA7210_PLL_DIV3, DA7210_PLL_BYP, bypass);
snd_soc_update_bits(codec, DA7210_STARTUP1,
DA7210_SC_MST_EN, DA7210_SC_MST_EN);
return 0;
}
static int da7210_set_dai_fmt(struct snd_soc_dai *codec_dai, u32 fmt)
{
struct snd_soc_codec *codec = codec_dai->codec;
u32 dai_cfg1;
u32 dai_cfg3;
dai_cfg1 = 0x7f & snd_soc_read(codec, DA7210_DAI_CFG1);
dai_cfg3 = 0xfc & snd_soc_read(codec, DA7210_DAI_CFG3);
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBM_CFM:
dai_cfg1 |= DA7210_DAI_MODE_MASTER;
break;
case SND_SOC_DAIFMT_CBS_CFS:
dai_cfg1 |= DA7210_DAI_MODE_SLAVE;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
dai_cfg3 |= DA7210_DAI_FORMAT_I2SMODE;
break;
case SND_SOC_DAIFMT_LEFT_J:
dai_cfg3 |= DA7210_DAI_FORMAT_LEFT_J;
break;
case SND_SOC_DAIFMT_RIGHT_J:
dai_cfg3 |= DA7210_DAI_FORMAT_RIGHT_J;
break;
default:
return -EINVAL;
}
dai_cfg1 |= DA7210_DAI_FLEN_64BIT;
snd_soc_write(codec, DA7210_DAI_CFG1, dai_cfg1);
snd_soc_write(codec, DA7210_DAI_CFG3, dai_cfg3);
return 0;
}
static int da7210_mute(struct snd_soc_dai *dai, int mute)
{
struct snd_soc_codec *codec = dai->codec;
u8 mute_reg = snd_soc_read(codec, DA7210_DAC_HPF) & 0xFB;
if (mute)
snd_soc_write(codec, DA7210_DAC_HPF, mute_reg | 0x4);
else
snd_soc_write(codec, DA7210_DAC_HPF, mute_reg);
return 0;
}
static int da7210_probe(struct snd_soc_codec *codec)
{
struct da7210_priv *da7210 = snd_soc_codec_get_drvdata(codec);
int ret;
dev_info(codec->dev, "DA7210 Audio Codec %s\n", DA7210_VERSION);
codec->control_data = da7210->regmap;
ret = snd_soc_codec_set_cache_io(codec, 8, 8, SND_SOC_REGMAP);
if (ret < 0) {
dev_err(codec->dev, "Failed to set cache I/O: %d\n", ret);
return ret;
}
snd_soc_write(codec, DA7210_STARTUP1, 0);
snd_soc_write(codec, DA7210_PLL_DIV3,
DA7210_MCLK_RANGE_10_20_MHZ | DA7210_PLL_BYP);
snd_soc_write(codec, DA7210_MIC_L, DA7210_MIC_L_EN | DA7210_MICBIAS_EN);
snd_soc_write(codec, DA7210_MIC_R, DA7210_MIC_R_EN);
snd_soc_write(codec, DA7210_INMIX_L, DA7210_IN_L_EN);
snd_soc_write(codec, DA7210_INMIX_R, DA7210_IN_R_EN);
snd_soc_write(codec, DA7210_ADC, DA7210_ADC_L_EN | DA7210_ADC_R_EN);
snd_soc_write(codec, DA7210_DAC_SEL,
DA7210_DAC_L_SRC_DAI_L | DA7210_DAC_L_EN |
DA7210_DAC_R_SRC_DAI_R | DA7210_DAC_R_EN);
snd_soc_write(codec, DA7210_OUTMIX_L, DA7210_OUT_L_EN);
snd_soc_write(codec, DA7210_OUTMIX_R, DA7210_OUT_R_EN);
snd_soc_write(codec, DA7210_HP_CFG,
DA7210_HP_2CAP_MODE | DA7210_HP_SENSE_EN |
DA7210_HP_L_EN | DA7210_HP_MODE | DA7210_HP_R_EN);
snd_soc_write(codec, DA7210_SOFTMUTE, DA7210_RAMP_EN);
snd_soc_write(codec, DA7210_OUT1_L, DA7210_OUT1_L_EN);
snd_soc_write(codec, DA7210_OUT1_R, DA7210_OUT1_R_EN);
snd_soc_write(codec, DA7210_OUT2, DA7210_OUT2_EN |
DA7210_OUT2_OUTMIX_L | DA7210_OUT2_OUTMIX_R);
snd_soc_write(codec, DA7210_AUX1_L, DA7210_AUX1_L_EN);
snd_soc_write(codec, DA7210_AUX1_R, DA7210_AUX1_R_EN);
snd_soc_write(codec, DA7210_AUX2, DA7210_AUX2_EN);
snd_soc_write(codec, DA7210_PLL, DA7210_PLL_FS_48000);
snd_soc_write(codec, DA7210_PLL_DIV1, 0xE5);
snd_soc_write(codec, DA7210_PLL_DIV2, 0x99);
snd_soc_write(codec, DA7210_PLL_DIV3, 0x0A |
DA7210_MCLK_RANGE_10_20_MHZ | DA7210_PLL_BYP);
snd_soc_update_bits(codec, DA7210_PLL, DA7210_PLL_EN, DA7210_PLL_EN);
regmap_write(da7210->regmap, DA7210_A_HID_UNLOCK, 0x8B);
regmap_write(da7210->regmap, DA7210_A_TEST_UNLOCK, 0xB4);
regmap_write(da7210->regmap, DA7210_A_PLL1, 0x01);
regmap_write(da7210->regmap, DA7210_A_CP_MODE, 0x7C);
regmap_write(da7210->regmap, DA7210_A_HID_UNLOCK, 0x00);
regmap_write(da7210->regmap, DA7210_A_TEST_UNLOCK, 0x00);
snd_soc_write(codec, DA7210_STARTUP1, DA7210_SC_MST_EN);
dev_info(codec->dev, "DA7210 Audio Codec %s\n", DA7210_VERSION);
return 0;
}
static int __devinit da7210_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct da7210_priv *da7210;
int ret;
da7210 = devm_kzalloc(&i2c->dev, sizeof(struct da7210_priv),
GFP_KERNEL);
if (!da7210)
return -ENOMEM;
i2c_set_clientdata(i2c, da7210);
da7210->regmap = regmap_init_i2c(i2c, &da7210_regmap);
if (IS_ERR(da7210->regmap)) {
ret = PTR_ERR(da7210->regmap);
dev_err(&i2c->dev, "regmap_init() failed: %d\n", ret);
return ret;
}
ret = snd_soc_register_codec(&i2c->dev,
&soc_codec_dev_da7210, &da7210_dai, 1);
if (ret < 0) {
dev_err(&i2c->dev, "Failed to register codec: %d\n", ret);
goto err_regmap;
}
return ret;
err_regmap:
regmap_exit(da7210->regmap);
return ret;
}
static int __devexit da7210_i2c_remove(struct i2c_client *client)
{
struct da7210_priv *da7210 = i2c_get_clientdata(client);
snd_soc_unregister_codec(&client->dev);
regmap_exit(da7210->regmap);
return 0;
}
static int __init da7210_modinit(void)
{
int ret = 0;
#if defined(CONFIG_I2C) || defined(CONFIG_I2C_MODULE)
ret = i2c_add_driver(&da7210_i2c_driver);
#endif
return ret;
}
static void __exit da7210_exit(void)
{
#if defined(CONFIG_I2C) || defined(CONFIG_I2C_MODULE)
i2c_del_driver(&da7210_i2c_driver);
#endif
}
