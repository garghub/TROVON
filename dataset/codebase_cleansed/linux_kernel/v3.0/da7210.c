static inline u32 da7210_read_reg_cache(struct snd_soc_codec *codec, u32 reg)
{
u8 *cache = codec->reg_cache;
BUG_ON(reg >= ARRAY_SIZE(da7210_reg));
return cache[reg];
}
static int da7210_write(struct snd_soc_codec *codec, u32 reg, u32 value)
{
u8 *cache = codec->reg_cache;
u8 data[2];
BUG_ON(codec->driver->volatile_register);
data[0] = reg & 0xff;
data[1] = value & 0xff;
if (reg >= codec->driver->reg_cache_size)
return -EIO;
if (2 != codec->hw_write(codec->control_data, data, 2))
return -EIO;
cache[reg] = value;
return 0;
}
static inline u32 da7210_read(struct snd_soc_codec *codec, u32 reg)
{
if (DA7210_STATUS == reg)
return i2c_smbus_read_byte_data(codec->control_data, reg);
return da7210_read_reg_cache(codec, reg);
}
static int da7210_startup(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
int is_play = substream->stream == SNDRV_PCM_STREAM_PLAYBACK;
struct snd_soc_codec *codec = dai->codec;
if (is_play) {
snd_soc_update_bits(codec, DA7210_OUTMIX_L, 0x1F, 0x10);
snd_soc_update_bits(codec, DA7210_OUTMIX_R, 0x1F, 0x10);
} else {
snd_soc_update_bits(codec, DA7210_MIC_L, 0x7, 0x7);
snd_soc_update_bits(codec, DA7210_MIC_R, 0x7, 0x7);
snd_soc_update_bits(codec, DA7210_INMIX_L, 0x1F, 0x1);
snd_soc_update_bits(codec, DA7210_INMIX_R, 0x1F, 0x1);
}
return 0;
}
static int da7210_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_codec *codec = rtd->codec;
u32 dai_cfg1;
u32 hpf_reg, hpf_mask, hpf_value;
u32 fs, bypass;
da7210_write(codec, DA7210_DAI_SRC_SEL,
DA7210_DAI_OUT_R_SRC | DA7210_DAI_OUT_L_SRC);
da7210_write(codec, DA7210_DAI_CFG3, DA7210_DAI_OE | DA7210_DAI_EN);
dai_cfg1 = 0xFC & da7210_read(codec, DA7210_DAI_CFG1);
switch (params_format(params)) {
case SNDRV_PCM_FORMAT_S16_LE:
dai_cfg1 |= DA7210_DAI_WORD_S16_LE;
break;
case SNDRV_PCM_FORMAT_S24_LE:
dai_cfg1 |= DA7210_DAI_WORD_S24_LE;
break;
default:
return -EINVAL;
}
da7210_write(codec, DA7210_DAI_CFG1, dai_cfg1);
hpf_reg = (SNDRV_PCM_STREAM_PLAYBACK == substream->stream) ?
DA7210_DAC_HPF : DA7210_ADC_HPF;
switch (params_rate(params)) {
case 8000:
fs = DA7210_PLL_FS_8000;
hpf_mask = DA7210_VOICE_F0_MASK | DA7210_VOICE_EN;
hpf_value = DA7210_VOICE_F0_25 | DA7210_VOICE_EN;
bypass = DA7210_PLL_BYP;
break;
case 11025:
fs = DA7210_PLL_FS_11025;
hpf_mask = DA7210_VOICE_F0_MASK | DA7210_VOICE_EN;
hpf_value = DA7210_VOICE_F0_25 | DA7210_VOICE_EN;
bypass = 0;
break;
case 12000:
fs = DA7210_PLL_FS_12000;
hpf_mask = DA7210_VOICE_F0_MASK | DA7210_VOICE_EN;
hpf_value = DA7210_VOICE_F0_25 | DA7210_VOICE_EN;
bypass = DA7210_PLL_BYP;
break;
case 16000:
fs = DA7210_PLL_FS_16000;
hpf_mask = DA7210_VOICE_F0_MASK | DA7210_VOICE_EN;
hpf_value = DA7210_VOICE_F0_25 | DA7210_VOICE_EN;
bypass = DA7210_PLL_BYP;
break;
case 22050:
fs = DA7210_PLL_FS_22050;
hpf_mask = DA7210_VOICE_EN;
hpf_value = 0;
bypass = 0;
break;
case 32000:
fs = DA7210_PLL_FS_32000;
hpf_mask = DA7210_VOICE_EN;
hpf_value = 0;
bypass = DA7210_PLL_BYP;
break;
case 44100:
fs = DA7210_PLL_FS_44100;
hpf_mask = DA7210_VOICE_EN;
hpf_value = 0;
bypass = 0;
break;
case 48000:
fs = DA7210_PLL_FS_48000;
hpf_mask = DA7210_VOICE_EN;
hpf_value = 0;
bypass = DA7210_PLL_BYP;
break;
case 88200:
fs = DA7210_PLL_FS_88200;
hpf_mask = DA7210_VOICE_EN;
hpf_value = 0;
bypass = 0;
break;
case 96000:
fs = DA7210_PLL_FS_96000;
hpf_mask = DA7210_VOICE_EN;
hpf_value = 0;
bypass = DA7210_PLL_BYP;
break;
default:
return -EINVAL;
}
snd_soc_update_bits(codec, DA7210_STARTUP1, DA7210_SC_MST_EN, 0);
snd_soc_update_bits(codec, hpf_reg, hpf_mask, hpf_value);
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
dai_cfg1 = 0x7f & da7210_read(codec, DA7210_DAI_CFG1);
dai_cfg3 = 0xfc & da7210_read(codec, DA7210_DAI_CFG3);
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBM_CFM:
dai_cfg1 |= DA7210_DAI_MODE_MASTER;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
dai_cfg3 |= DA7210_DAI_FORMAT_I2SMODE;
break;
default:
return -EINVAL;
}
dai_cfg1 |= DA7210_DAI_FLEN_64BIT;
da7210_write(codec, DA7210_DAI_CFG1, dai_cfg1);
da7210_write(codec, DA7210_DAI_CFG3, dai_cfg3);
return 0;
}
static int da7210_probe(struct snd_soc_codec *codec)
{
struct da7210_priv *da7210 = snd_soc_codec_get_drvdata(codec);
dev_info(codec->dev, "DA7210 Audio Codec %s\n", DA7210_VERSION);
codec->control_data = da7210->control_data;
codec->hw_write = (hw_write_t)i2c_master_send;
da7210_write(codec, DA7210_STARTUP1, 0);
da7210_write(codec, DA7210_PLL_DIV3,
DA7210_MCLK_RANGE_10_20_MHZ | DA7210_PLL_BYP);
da7210_write(codec, DA7210_MIC_L, DA7210_MIC_L_EN | DA7210_MICBIAS_EN);
da7210_write(codec, DA7210_MIC_R, DA7210_MIC_R_EN);
da7210_write(codec, DA7210_INMIX_L, DA7210_IN_L_EN);
da7210_write(codec, DA7210_INMIX_R, DA7210_IN_R_EN);
da7210_write(codec, DA7210_ADC, DA7210_ADC_L_EN | DA7210_ADC_R_EN);
da7210_write(codec, DA7210_DAC_SEL,
DA7210_DAC_L_SRC_DAI_L | DA7210_DAC_L_EN |
DA7210_DAC_R_SRC_DAI_R | DA7210_DAC_R_EN);
da7210_write(codec, DA7210_OUTMIX_L, DA7210_OUT_L_EN);
da7210_write(codec, DA7210_OUTMIX_R, DA7210_OUT_R_EN);
da7210_write(codec, DA7210_HP_CFG,
DA7210_HP_2CAP_MODE | DA7210_HP_SENSE_EN |
DA7210_HP_L_EN | DA7210_HP_MODE | DA7210_HP_R_EN);
da7210_write(codec, DA7210_PLL, DA7210_PLL_FS_48000);
da7210_write(codec, DA7210_PLL_DIV1, 0xE5);
da7210_write(codec, DA7210_PLL_DIV2, 0x99);
da7210_write(codec, DA7210_PLL_DIV3, 0x0A |
DA7210_MCLK_RANGE_10_20_MHZ | DA7210_PLL_BYP);
snd_soc_update_bits(codec, DA7210_PLL, DA7210_PLL_EN, DA7210_PLL_EN);
da7210_write(codec, DA7210_A_HID_UNLOCK, 0x8B);
da7210_write(codec, DA7210_A_TEST_UNLOCK, 0xB4);
da7210_write(codec, DA7210_A_PLL1, 0x01);
da7210_write(codec, DA7210_A_CP_MODE, 0x7C);
da7210_write(codec, DA7210_A_HID_UNLOCK, 0x00);
da7210_write(codec, DA7210_A_TEST_UNLOCK, 0x00);
da7210_write(codec, DA7210_STARTUP1, DA7210_SC_MST_EN);
snd_soc_add_controls(codec, da7210_snd_controls,
ARRAY_SIZE(da7210_snd_controls));
dev_info(codec->dev, "DA7210 Audio Codec %s\n", DA7210_VERSION);
return 0;
}
static int __devinit da7210_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct da7210_priv *da7210;
int ret;
da7210 = kzalloc(sizeof(struct da7210_priv), GFP_KERNEL);
if (!da7210)
return -ENOMEM;
i2c_set_clientdata(i2c, da7210);
da7210->control_data = i2c;
da7210->control_type = SND_SOC_I2C;
ret = snd_soc_register_codec(&i2c->dev,
&soc_codec_dev_da7210, &da7210_dai, 1);
if (ret < 0)
kfree(da7210);
return ret;
}
static int __devexit da7210_i2c_remove(struct i2c_client *client)
{
snd_soc_unregister_codec(&client->dev);
kfree(i2c_get_clientdata(client));
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
