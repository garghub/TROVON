static inline unsigned int ak4535_read_reg_cache(struct snd_soc_codec *codec,
unsigned int reg)
{
u16 *cache = codec->reg_cache;
if (reg >= AK4535_CACHEREGNUM)
return -1;
return cache[reg];
}
static inline void ak4535_write_reg_cache(struct snd_soc_codec *codec,
u16 reg, unsigned int value)
{
u16 *cache = codec->reg_cache;
if (reg >= AK4535_CACHEREGNUM)
return;
cache[reg] = value;
}
static int ak4535_write(struct snd_soc_codec *codec, unsigned int reg,
unsigned int value)
{
u8 data[2];
data[0] = reg & 0xff;
data[1] = value & 0xff;
ak4535_write_reg_cache(codec, reg, value);
if (codec->hw_write(codec->control_data, data, 2) == 2)
return 0;
else
return -EIO;
}
static int ak4535_sync(struct snd_soc_codec *codec)
{
u16 *cache = codec->reg_cache;
int i, r = 0;
for (i = 0; i < AK4535_CACHEREGNUM; i++)
r |= ak4535_write(codec, i, cache[i]);
return r;
}
static int ak4535_set_dai_sysclk(struct snd_soc_dai *codec_dai,
int clk_id, unsigned int freq, int dir)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct ak4535_priv *ak4535 = snd_soc_codec_get_drvdata(codec);
ak4535->sysclk = freq;
return 0;
}
static int ak4535_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_codec *codec = rtd->codec;
struct ak4535_priv *ak4535 = snd_soc_codec_get_drvdata(codec);
u8 mode2 = ak4535_read_reg_cache(codec, AK4535_MODE2) & ~(0x3 << 5);
int rate = params_rate(params), fs = 256;
if (rate)
fs = ak4535->sysclk / rate;
switch (fs) {
case 1024:
mode2 |= (0x2 << 5);
break;
case 512:
mode2 |= (0x1 << 5);
break;
case 256:
break;
}
ak4535_write(codec, AK4535_MODE2, mode2);
return 0;
}
static int ak4535_set_dai_fmt(struct snd_soc_dai *codec_dai,
unsigned int fmt)
{
struct snd_soc_codec *codec = codec_dai->codec;
u8 mode1 = 0;
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
mode1 = 0x0002;
break;
case SND_SOC_DAIFMT_LEFT_J:
mode1 = 0x0001;
break;
default:
return -EINVAL;
}
mode1 |= 0x4;
ak4535_write(codec, AK4535_MODE1, mode1);
return 0;
}
static int ak4535_mute(struct snd_soc_dai *dai, int mute)
{
struct snd_soc_codec *codec = dai->codec;
u16 mute_reg = ak4535_read_reg_cache(codec, AK4535_DAC);
if (!mute)
ak4535_write(codec, AK4535_DAC, mute_reg & ~0x20);
else
ak4535_write(codec, AK4535_DAC, mute_reg | 0x20);
return 0;
}
static int ak4535_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
u16 i, mute_reg;
switch (level) {
case SND_SOC_BIAS_ON:
mute_reg = ak4535_read_reg_cache(codec, AK4535_DAC);
ak4535_write(codec, AK4535_DAC, mute_reg & ~0x20);
break;
case SND_SOC_BIAS_PREPARE:
mute_reg = ak4535_read_reg_cache(codec, AK4535_DAC);
ak4535_write(codec, AK4535_DAC, mute_reg | 0x20);
break;
case SND_SOC_BIAS_STANDBY:
i = ak4535_read_reg_cache(codec, AK4535_PM1);
ak4535_write(codec, AK4535_PM1, i | 0x80);
i = ak4535_read_reg_cache(codec, AK4535_PM2);
ak4535_write(codec, AK4535_PM2, i & (~0x80));
break;
case SND_SOC_BIAS_OFF:
i = ak4535_read_reg_cache(codec, AK4535_PM1);
ak4535_write(codec, AK4535_PM1, i & (~0x80));
break;
}
codec->dapm.bias_level = level;
return 0;
}
static int ak4535_suspend(struct snd_soc_codec *codec, pm_message_t state)
{
ak4535_set_bias_level(codec, SND_SOC_BIAS_OFF);
return 0;
}
static int ak4535_resume(struct snd_soc_codec *codec)
{
ak4535_sync(codec);
ak4535_set_bias_level(codec, SND_SOC_BIAS_STANDBY);
return 0;
}
static int ak4535_probe(struct snd_soc_codec *codec)
{
struct ak4535_priv *ak4535 = snd_soc_codec_get_drvdata(codec);
printk(KERN_INFO "AK4535 Audio Codec %s", AK4535_VERSION);
codec->control_data = ak4535->control_data;
ak4535_set_bias_level(codec, SND_SOC_BIAS_STANDBY);
snd_soc_add_controls(codec, ak4535_snd_controls,
ARRAY_SIZE(ak4535_snd_controls));
return 0;
}
static int ak4535_remove(struct snd_soc_codec *codec)
{
ak4535_set_bias_level(codec, SND_SOC_BIAS_OFF);
return 0;
}
static __devinit int ak4535_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct ak4535_priv *ak4535;
int ret;
ak4535 = kzalloc(sizeof(struct ak4535_priv), GFP_KERNEL);
if (ak4535 == NULL)
return -ENOMEM;
i2c_set_clientdata(i2c, ak4535);
ak4535->control_data = i2c;
ak4535->control_type = SND_SOC_I2C;
ret = snd_soc_register_codec(&i2c->dev,
&soc_codec_dev_ak4535, &ak4535_dai, 1);
if (ret < 0)
kfree(ak4535);
return ret;
}
static __devexit int ak4535_i2c_remove(struct i2c_client *client)
{
snd_soc_unregister_codec(&client->dev);
kfree(i2c_get_clientdata(client));
return 0;
}
static int __init ak4535_modinit(void)
{
int ret = 0;
#if defined(CONFIG_I2C) || defined(CONFIG_I2C_MODULE)
ret = i2c_add_driver(&ak4535_i2c_driver);
if (ret != 0) {
printk(KERN_ERR "Failed to register AK4535 I2C driver: %d\n",
ret);
}
#endif
return ret;
}
static void __exit ak4535_exit(void)
{
#if defined(CONFIG_I2C) || defined(CONFIG_I2C_MODULE)
i2c_del_driver(&ak4535_i2c_driver);
#endif
}
