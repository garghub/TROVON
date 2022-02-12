static bool sta529_readable(struct device *dev, unsigned int reg)
{
switch (reg) {
case STA529_FFXCFG0:
case STA529_FFXCFG1:
case STA529_MVOL:
case STA529_LVOL:
case STA529_RVOL:
case STA529_S2PCFG0:
case STA529_S2PCFG1:
case STA529_P2SCFG0:
case STA529_P2SCFG1:
case STA529_ADCCFG:
case STA529_CKOCFG:
case STA529_MISC:
return true;
default:
return false;
}
}
static int sta529_set_bias_level(struct snd_soc_codec *codec, enum
snd_soc_bias_level level)
{
struct sta529 *sta529 = snd_soc_codec_get_drvdata(codec);
switch (level) {
case SND_SOC_BIAS_ON:
case SND_SOC_BIAS_PREPARE:
snd_soc_update_bits(codec, STA529_FFXCFG0, POWER_CNTLMSAK,
POWER_UP);
snd_soc_update_bits(codec, STA529_MISC, FFX_CLK_MSK,
FFX_CLK_ENB);
break;
case SND_SOC_BIAS_STANDBY:
if (snd_soc_codec_get_bias_level(codec) == SND_SOC_BIAS_OFF)
regcache_sync(sta529->regmap);
snd_soc_update_bits(codec, STA529_FFXCFG0,
POWER_CNTLMSAK, POWER_STDBY);
snd_soc_update_bits(codec, STA529_FFXCFG0, FFX_MASK,
FFX_OFF);
snd_soc_update_bits(codec, STA529_MISC, FFX_CLK_MSK,
FFX_CLK_DIS);
break;
case SND_SOC_BIAS_OFF:
break;
}
return 0;
}
static int sta529_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
int pdata, play_freq_val, record_freq_val;
int bclk_to_fs_ratio;
switch (params_width(params)) {
case 16:
pdata = 1;
bclk_to_fs_ratio = 0;
break;
case 24:
pdata = 2;
bclk_to_fs_ratio = 1;
break;
case 32:
pdata = 3;
bclk_to_fs_ratio = 2;
break;
default:
dev_err(codec->dev, "Unsupported format\n");
return -EINVAL;
}
switch (params_rate(params)) {
case 8000:
case 11025:
play_freq_val = 0;
record_freq_val = 2;
break;
case 16000:
case 22050:
play_freq_val = 1;
record_freq_val = 0;
break;
case 32000:
case 44100:
case 48000:
play_freq_val = 2;
record_freq_val = 0;
break;
default:
dev_err(codec->dev, "Unsupported rate\n");
return -EINVAL;
}
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK) {
snd_soc_update_bits(codec, STA529_S2PCFG1, PDATA_LEN_MSK,
pdata << 6);
snd_soc_update_bits(codec, STA529_S2PCFG1, BCLK_TO_FS_MSK,
bclk_to_fs_ratio << 4);
snd_soc_update_bits(codec, STA529_MISC, PLAY_FREQ_RANGE_MSK,
play_freq_val << 4);
} else {
snd_soc_update_bits(codec, STA529_P2SCFG1, PDATA_LEN_MSK,
pdata << 6);
snd_soc_update_bits(codec, STA529_P2SCFG1, BCLK_TO_FS_MSK,
bclk_to_fs_ratio << 4);
snd_soc_update_bits(codec, STA529_MISC, CAP_FREQ_RANGE_MSK,
record_freq_val << 2);
}
return 0;
}
static int sta529_mute(struct snd_soc_dai *dai, int mute)
{
u8 val = 0;
if (mute)
val |= CODEC_MUTE_VAL;
snd_soc_update_bits(dai->codec, STA529_FFXCFG0, AUDIO_MUTE_MSK, val);
return 0;
}
static int sta529_set_dai_fmt(struct snd_soc_dai *codec_dai, u32 fmt)
{
struct snd_soc_codec *codec = codec_dai->codec;
u8 mode = 0;
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_LEFT_J:
mode = LEFT_J_DATA_FORMAT;
break;
case SND_SOC_DAIFMT_I2S:
mode = I2S_DATA_FORMAT;
break;
case SND_SOC_DAIFMT_RIGHT_J:
mode = RIGHT_J_DATA_FORMAT;
break;
default:
return -EINVAL;
}
snd_soc_update_bits(codec, STA529_S2PCFG0, DATA_FORMAT_MSK, mode);
return 0;
}
static int sta529_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct sta529 *sta529;
int ret;
sta529 = devm_kzalloc(&i2c->dev, sizeof(struct sta529), GFP_KERNEL);
if (!sta529)
return -ENOMEM;
sta529->regmap = devm_regmap_init_i2c(i2c, &sta529_regmap);
if (IS_ERR(sta529->regmap)) {
ret = PTR_ERR(sta529->regmap);
dev_err(&i2c->dev, "Failed to allocate regmap: %d\n", ret);
return ret;
}
i2c_set_clientdata(i2c, sta529);
ret = snd_soc_register_codec(&i2c->dev,
&sta529_codec_driver, &sta529_dai, 1);
if (ret != 0)
dev_err(&i2c->dev, "Failed to register CODEC: %d\n", ret);
return ret;
}
static int sta529_i2c_remove(struct i2c_client *client)
{
snd_soc_unregister_codec(&client->dev);
return 0;
}
