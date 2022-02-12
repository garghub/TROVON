static int ak4642_dai_startup(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
int is_play = substream->stream == SNDRV_PCM_STREAM_PLAYBACK;
struct snd_soc_codec *codec = dai->codec;
if (is_play) {
snd_soc_write(codec, L_IVC, 0x91);
snd_soc_write(codec, R_IVC, 0x91);
} else {
snd_soc_write(codec, SG_SL1, PMMP | MGAIN0);
snd_soc_write(codec, TIMER, ZTM(0x3) | WTM(0x3));
snd_soc_write(codec, ALC_CTL1, ALC | LMTH0);
snd_soc_update_bits(codec, PW_MGMT1, PMADL, PMADL);
snd_soc_update_bits(codec, PW_MGMT3, PMADR, PMADR);
}
return 0;
}
static void ak4642_dai_shutdown(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
int is_play = substream->stream == SNDRV_PCM_STREAM_PLAYBACK;
struct snd_soc_codec *codec = dai->codec;
if (is_play) {
} else {
snd_soc_update_bits(codec, PW_MGMT1, PMADL, 0);
snd_soc_update_bits(codec, PW_MGMT3, PMADR, 0);
snd_soc_update_bits(codec, ALC_CTL1, ALC, 0);
}
}
static int ak4642_dai_set_sysclk(struct snd_soc_dai *codec_dai,
int clk_id, unsigned int freq, int dir)
{
struct snd_soc_codec *codec = codec_dai->codec;
u8 pll;
switch (freq) {
case 11289600:
pll = PLL2;
break;
case 12288000:
pll = PLL2 | PLL0;
break;
case 12000000:
pll = PLL2 | PLL1;
break;
case 24000000:
pll = PLL2 | PLL1 | PLL0;
break;
case 13500000:
pll = PLL3 | PLL2;
break;
case 27000000:
pll = PLL3 | PLL2 | PLL0;
break;
default:
return -EINVAL;
}
snd_soc_update_bits(codec, MD_CTL1, PLL_MASK, pll);
return 0;
}
static int ak4642_dai_set_fmt(struct snd_soc_dai *dai, unsigned int fmt)
{
struct snd_soc_codec *codec = dai->codec;
u8 data;
u8 bcko;
data = MCKO | PMPLL;
bcko = 0;
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBM_CFM:
data |= MS;
bcko = BCKO_64;
break;
case SND_SOC_DAIFMT_CBS_CFS:
break;
default:
return -EINVAL;
}
snd_soc_update_bits(codec, PW_MGMT2, MS | MCKO | PMPLL, data);
snd_soc_update_bits(codec, MD_CTL1, BCKO_MASK, bcko);
data = 0;
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_LEFT_J:
data = LEFT_J;
break;
case SND_SOC_DAIFMT_I2S:
data = I2S;
break;
default:
return -EINVAL;
break;
}
snd_soc_update_bits(codec, MD_CTL1, DIF_MASK, data);
return 0;
}
static int ak4642_dai_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
u8 rate;
switch (params_rate(params)) {
case 7350:
rate = FS2;
break;
case 8000:
rate = 0;
break;
case 11025:
rate = FS2 | FS0;
break;
case 12000:
rate = FS0;
break;
case 14700:
rate = FS2 | FS1;
break;
case 16000:
rate = FS1;
break;
case 22050:
rate = FS2 | FS1 | FS0;
break;
case 24000:
rate = FS1 | FS0;
break;
case 29400:
rate = FS3 | FS2 | FS1;
break;
case 32000:
rate = FS3 | FS1;
break;
case 44100:
rate = FS3 | FS2 | FS1 | FS0;
break;
case 48000:
rate = FS3 | FS1 | FS0;
break;
default:
return -EINVAL;
break;
}
snd_soc_update_bits(codec, MD_CTL2, FS_MASK, rate);
return 0;
}
static int ak4642_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
switch (level) {
case SND_SOC_BIAS_OFF:
snd_soc_write(codec, PW_MGMT1, 0x00);
break;
default:
snd_soc_update_bits(codec, PW_MGMT1, PMVCM, PMVCM);
break;
}
codec->dapm.bias_level = level;
return 0;
}
static int ak4642_resume(struct snd_soc_codec *codec)
{
snd_soc_cache_sync(codec);
return 0;
}
static int ak4642_probe(struct snd_soc_codec *codec)
{
struct ak4642_priv *ak4642 = snd_soc_codec_get_drvdata(codec);
int ret;
ret = snd_soc_codec_set_cache_io(codec, 8, 8, ak4642->control_type);
if (ret < 0) {
dev_err(codec->dev, "Failed to set cache I/O: %d\n", ret);
return ret;
}
snd_soc_add_codec_controls(codec, ak4642_snd_controls,
ARRAY_SIZE(ak4642_snd_controls));
ak4642_set_bias_level(codec, SND_SOC_BIAS_STANDBY);
return 0;
}
static int ak4642_remove(struct snd_soc_codec *codec)
{
ak4642_set_bias_level(codec, SND_SOC_BIAS_OFF);
return 0;
}
static __devinit int ak4642_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct ak4642_priv *ak4642;
int ret;
ak4642 = devm_kzalloc(&i2c->dev, sizeof(struct ak4642_priv),
GFP_KERNEL);
if (!ak4642)
return -ENOMEM;
i2c_set_clientdata(i2c, ak4642);
ak4642->control_type = SND_SOC_I2C;
ret = snd_soc_register_codec(&i2c->dev,
(struct snd_soc_codec_driver *)id->driver_data,
&ak4642_dai, 1);
return ret;
}
static __devexit int ak4642_i2c_remove(struct i2c_client *client)
{
snd_soc_unregister_codec(&client->dev);
return 0;
}
static int __init ak4642_modinit(void)
{
int ret = 0;
#if defined(CONFIG_I2C) || defined(CONFIG_I2C_MODULE)
ret = i2c_add_driver(&ak4642_i2c_driver);
#endif
return ret;
}
static void __exit ak4642_exit(void)
{
#if defined(CONFIG_I2C) || defined(CONFIG_I2C_MODULE)
i2c_del_driver(&ak4642_i2c_driver);
#endif
}
