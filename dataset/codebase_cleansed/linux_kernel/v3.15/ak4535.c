static bool ak4535_volatile(struct device *dev, unsigned int reg)
{
switch (reg) {
case AK4535_STATUS:
return true;
default:
return false;
}
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
struct snd_soc_codec *codec = dai->codec;
struct ak4535_priv *ak4535 = snd_soc_codec_get_drvdata(codec);
u8 mode2 = snd_soc_read(codec, AK4535_MODE2) & ~(0x3 << 5);
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
snd_soc_write(codec, AK4535_MODE2, mode2);
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
snd_soc_write(codec, AK4535_MODE1, mode1);
return 0;
}
static int ak4535_mute(struct snd_soc_dai *dai, int mute)
{
struct snd_soc_codec *codec = dai->codec;
u16 mute_reg = snd_soc_read(codec, AK4535_DAC);
if (!mute)
snd_soc_write(codec, AK4535_DAC, mute_reg & ~0x20);
else
snd_soc_write(codec, AK4535_DAC, mute_reg | 0x20);
return 0;
}
static int ak4535_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
switch (level) {
case SND_SOC_BIAS_ON:
snd_soc_update_bits(codec, AK4535_DAC, 0x20, 0);
break;
case SND_SOC_BIAS_PREPARE:
snd_soc_update_bits(codec, AK4535_DAC, 0x20, 0x20);
break;
case SND_SOC_BIAS_STANDBY:
snd_soc_update_bits(codec, AK4535_PM1, 0x80, 0x80);
snd_soc_update_bits(codec, AK4535_PM2, 0x80, 0);
break;
case SND_SOC_BIAS_OFF:
snd_soc_update_bits(codec, AK4535_PM1, 0x80, 0);
break;
}
codec->dapm.bias_level = level;
return 0;
}
static int ak4535_suspend(struct snd_soc_codec *codec)
{
ak4535_set_bias_level(codec, SND_SOC_BIAS_OFF);
return 0;
}
static int ak4535_resume(struct snd_soc_codec *codec)
{
snd_soc_cache_sync(codec);
ak4535_set_bias_level(codec, SND_SOC_BIAS_STANDBY);
return 0;
}
static int ak4535_probe(struct snd_soc_codec *codec)
{
ak4535_set_bias_level(codec, SND_SOC_BIAS_STANDBY);
snd_soc_add_codec_controls(codec, ak4535_snd_controls,
ARRAY_SIZE(ak4535_snd_controls));
return 0;
}
static int ak4535_remove(struct snd_soc_codec *codec)
{
ak4535_set_bias_level(codec, SND_SOC_BIAS_OFF);
return 0;
}
static int ak4535_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct ak4535_priv *ak4535;
int ret;
ak4535 = devm_kzalloc(&i2c->dev, sizeof(struct ak4535_priv),
GFP_KERNEL);
if (ak4535 == NULL)
return -ENOMEM;
ak4535->regmap = devm_regmap_init_i2c(i2c, &ak4535_regmap);
if (IS_ERR(ak4535->regmap)) {
ret = PTR_ERR(ak4535->regmap);
dev_err(&i2c->dev, "Failed to init regmap: %d\n", ret);
return ret;
}
i2c_set_clientdata(i2c, ak4535);
ret = snd_soc_register_codec(&i2c->dev,
&soc_codec_dev_ak4535, &ak4535_dai, 1);
return ret;
}
static int ak4535_i2c_remove(struct i2c_client *client)
{
snd_soc_unregister_codec(&client->dev);
return 0;
}
