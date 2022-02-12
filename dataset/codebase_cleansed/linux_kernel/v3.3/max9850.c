static int max9850_volatile_register(struct snd_soc_codec *codec,
unsigned int reg)
{
switch (reg) {
case MAX9850_STATUSA:
case MAX9850_STATUSB:
return 1;
default:
return 0;
}
}
static int max9850_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct max9850_priv *max9850 = snd_soc_codec_get_drvdata(codec);
u64 lrclk_div;
u8 sf, da;
if (!max9850->sysclk)
return -EINVAL;
sf = (snd_soc_read(codec, MAX9850_CLOCK) >> 2) + 1;
lrclk_div = (1 << 22);
lrclk_div *= params_rate(params);
lrclk_div *= sf;
do_div(lrclk_div, max9850->sysclk);
snd_soc_write(codec, MAX9850_LRCLK_MSB, (lrclk_div >> 8) & 0x7f);
snd_soc_write(codec, MAX9850_LRCLK_LSB, lrclk_div & 0xff);
switch (params_format(params)) {
case SNDRV_PCM_FORMAT_S16_LE:
da = 0;
break;
case SNDRV_PCM_FORMAT_S20_3LE:
da = 0x2;
break;
case SNDRV_PCM_FORMAT_S24_LE:
da = 0x3;
break;
default:
return -EINVAL;
}
snd_soc_update_bits(codec, MAX9850_DIGITAL_AUDIO, 0x3, da);
return 0;
}
static int max9850_set_dai_sysclk(struct snd_soc_dai *codec_dai,
int clk_id, unsigned int freq, int dir)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct max9850_priv *max9850 = snd_soc_codec_get_drvdata(codec);
if (freq <= 13000000)
snd_soc_write(codec, MAX9850_CLOCK, 0x0);
else if (freq <= 26000000)
snd_soc_write(codec, MAX9850_CLOCK, 0x4);
else if (freq <= 40000000)
snd_soc_write(codec, MAX9850_CLOCK, 0x8);
else
return -EINVAL;
max9850->sysclk = freq;
return 0;
}
static int max9850_set_dai_fmt(struct snd_soc_dai *codec_dai, unsigned int fmt)
{
struct snd_soc_codec *codec = codec_dai->codec;
u8 da = 0;
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBM_CFM:
da |= MAX9850_MASTER;
break;
case SND_SOC_DAIFMT_CBS_CFS:
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
da |= MAX9850_DLY;
break;
case SND_SOC_DAIFMT_RIGHT_J:
da |= MAX9850_RTJ;
break;
case SND_SOC_DAIFMT_LEFT_J:
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
break;
case SND_SOC_DAIFMT_IB_IF:
da |= MAX9850_BCINV | MAX9850_INV;
break;
case SND_SOC_DAIFMT_IB_NF:
da |= MAX9850_BCINV;
break;
case SND_SOC_DAIFMT_NB_IF:
da |= MAX9850_INV;
break;
default:
return -EINVAL;
}
snd_soc_write(codec, MAX9850_DIGITAL_AUDIO, da);
return 0;
}
static int max9850_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
int ret;
switch (level) {
case SND_SOC_BIAS_ON:
break;
case SND_SOC_BIAS_PREPARE:
break;
case SND_SOC_BIAS_STANDBY:
if (codec->dapm.bias_level == SND_SOC_BIAS_OFF) {
ret = snd_soc_cache_sync(codec);
if (ret) {
dev_err(codec->dev,
"Failed to sync cache: %d\n", ret);
return ret;
}
}
break;
case SND_SOC_BIAS_OFF:
break;
}
codec->dapm.bias_level = level;
return 0;
}
static int max9850_suspend(struct snd_soc_codec *codec)
{
max9850_set_bias_level(codec, SND_SOC_BIAS_OFF);
return 0;
}
static int max9850_resume(struct snd_soc_codec *codec)
{
max9850_set_bias_level(codec, SND_SOC_BIAS_STANDBY);
return 0;
}
static int max9850_probe(struct snd_soc_codec *codec)
{
int ret;
ret = snd_soc_codec_set_cache_io(codec, 8, 8, SND_SOC_I2C);
if (ret < 0) {
dev_err(codec->dev, "Failed to set cache I/O: %d\n", ret);
return ret;
}
snd_soc_update_bits(codec, MAX9850_GENERAL_PURPOSE, 1, 1);
snd_soc_update_bits(codec, MAX9850_VOLUME, 0x40, 0x40);
snd_soc_update_bits(codec, MAX9850_CHARGE_PUMP, 0xff, 0xc0);
return 0;
}
static int __devinit max9850_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct max9850_priv *max9850;
int ret;
max9850 = devm_kzalloc(&i2c->dev, sizeof(struct max9850_priv),
GFP_KERNEL);
if (max9850 == NULL)
return -ENOMEM;
i2c_set_clientdata(i2c, max9850);
ret = snd_soc_register_codec(&i2c->dev,
&soc_codec_dev_max9850, &max9850_dai, 1);
return ret;
}
static __devexit int max9850_i2c_remove(struct i2c_client *client)
{
snd_soc_unregister_codec(&client->dev);
return 0;
}
static int __init max9850_init(void)
{
return i2c_add_driver(&max9850_i2c_driver);
}
static void __exit max9850_exit(void)
{
i2c_del_driver(&max9850_i2c_driver);
}
