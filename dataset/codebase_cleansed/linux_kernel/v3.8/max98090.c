static bool max98090_volatile(struct device *dev, unsigned int reg)
{
if ((reg == MAX98090_0x01_INT_STS) ||
(reg == MAX98090_0x02_JACK_STS) ||
(reg > MAX98090_REG_MAX_CACHED))
return true;
return false;
}
static int max98090_dai_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
unsigned int val;
switch (params_rate(params)) {
case 96000:
val = 1 << 5;
break;
case 32000:
val = 1 << 4;
break;
case 48000:
val = 1 << 3;
break;
case 44100:
val = 1 << 2;
break;
case 16000:
val = 1 << 1;
break;
case 8000:
val = 1 << 0;
break;
default:
dev_err(codec->dev, "unsupported rate\n");
return -EINVAL;
}
snd_soc_update_bits(codec, MAX98090_0x05_SAMPLE_RATE, 0x03F, val);
return 0;
}
static int max98090_dai_set_sysclk(struct snd_soc_dai *dai,
int clk_id, unsigned int freq, int dir)
{
struct snd_soc_codec *codec = dai->codec;
unsigned int val;
snd_soc_update_bits(codec, MAX98090_0x45_DEV_SHUTDOWN,
MAX98090_SHDNRUN, 0);
switch (freq) {
case 26000000:
val = 1 << 7;
break;
case 19200000:
val = 1 << 6;
break;
case 13000000:
val = 1 << 5;
break;
case 12288000:
val = 1 << 4;
break;
case 12000000:
val = 1 << 3;
break;
case 11289600:
val = 1 << 2;
break;
default:
dev_err(codec->dev, "Invalid master clock frequency\n");
return -EINVAL;
}
snd_soc_update_bits(codec, MAX98090_0x04_SYS_CLK, 0xFD, val);
snd_soc_update_bits(codec, MAX98090_0x45_DEV_SHUTDOWN,
MAX98090_SHDNRUN, MAX98090_SHDNRUN);
dev_dbg(dai->dev, "sysclk is %uHz\n", freq);
return 0;
}
static int max98090_dai_set_fmt(struct snd_soc_dai *dai,
unsigned int fmt)
{
struct snd_soc_codec *codec = dai->codec;
int is_master;
u8 val;
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBM_CFM:
is_master = 1;
break;
case SND_SOC_DAIFMT_CBS_CFS:
is_master = 0;
break;
default:
dev_err(codec->dev, "unsupported clock\n");
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_I2S:
val = (is_master) ? MAX98090_I2S_M : MAX98090_I2S_S;
break;
case SND_SOC_DAIFMT_RIGHT_J:
val = (is_master) ? MAX98090_RJ_M : MAX98090_RJ_S;
break;
case SND_SOC_DAIFMT_LEFT_J:
val = (is_master) ? MAX98090_LJ_M : MAX98090_LJ_S;
break;
default:
dev_err(codec->dev, "unsupported format\n");
return -EINVAL;
}
snd_soc_update_bits(codec, MAX98090_0x06_DAI_IF,
MAX98090_DAI_IF_MASK, val);
return 0;
}
static int max98090_probe(struct snd_soc_codec *codec)
{
struct max98090_priv *priv = snd_soc_codec_get_drvdata(codec);
struct device *dev = codec->dev;
int ret;
codec->control_data = priv->regmap;
ret = snd_soc_codec_set_cache_io(codec, 8, 8, SND_SOC_REGMAP);
if (ret < 0) {
dev_err(dev, "Failed to set cache I/O: %d\n", ret);
return ret;
}
snd_soc_update_bits(codec, MAX98090_0x45_DEV_SHUTDOWN,
MAX98090_SHDNRUN, MAX98090_SHDNRUN);
return 0;
}
static int max98090_remove(struct snd_soc_codec *codec)
{
return 0;
}
static int max98090_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct max98090_priv *priv;
struct device *dev = &i2c->dev;
unsigned int val;
int ret;
priv = devm_kzalloc(dev, sizeof(struct max98090_priv),
GFP_KERNEL);
if (!priv)
return -ENOMEM;
priv->regmap = devm_regmap_init_i2c(i2c, &max98090_regmap);
if (IS_ERR(priv->regmap)) {
ret = PTR_ERR(priv->regmap);
dev_err(dev, "Failed to init regmap: %d\n", ret);
return ret;
}
i2c_set_clientdata(i2c, priv);
ret = regmap_read(priv->regmap, MAX98090_0xFF_REV_ID, &val);
if (ret < 0) {
dev_err(dev, "Failed to read device revision: %d\n", ret);
return ret;
}
dev_info(dev, "revision 0x%02x\n", val);
ret = snd_soc_register_codec(dev,
&soc_codec_dev_max98090,
&max98090_dai, 1);
return ret;
}
static int max98090_i2c_remove(struct i2c_client *client)
{
snd_soc_unregister_codec(&client->dev);
return 0;
}
