static bool cs4349_readable_register(struct device *dev, unsigned int reg)
{
switch (reg) {
case CS4349_CHIPID ... CS4349_MISC:
return true;
default:
return false;
}
}
static bool cs4349_writeable_register(struct device *dev, unsigned int reg)
{
switch (reg) {
case CS4349_MODE ... CS4349_MISC:
return true;
default:
return false;
}
}
static int cs4349_set_dai_fmt(struct snd_soc_dai *codec_dai,
unsigned int format)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct cs4349_private *cs4349 = snd_soc_codec_get_drvdata(codec);
unsigned int fmt;
fmt = format & SND_SOC_DAIFMT_FORMAT_MASK;
switch (fmt) {
case SND_SOC_DAIFMT_I2S:
case SND_SOC_DAIFMT_LEFT_J:
case SND_SOC_DAIFMT_RIGHT_J:
cs4349->mode = format & SND_SOC_DAIFMT_FORMAT_MASK;
break;
default:
return -EINVAL;
}
return 0;
}
static int cs4349_pcm_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct cs4349_private *cs4349 = snd_soc_codec_get_drvdata(codec);
int fmt, ret;
cs4349->rate = params_rate(params);
switch (cs4349->mode) {
case SND_SOC_DAIFMT_I2S:
fmt = DIF_I2S;
break;
case SND_SOC_DAIFMT_LEFT_J:
fmt = DIF_LEFT_JST;
break;
case SND_SOC_DAIFMT_RIGHT_J:
switch (params_width(params)) {
case 16:
fmt = DIF_RGHT_JST16;
break;
case 24:
fmt = DIF_RGHT_JST24;
break;
default:
return -EINVAL;
}
break;
default:
return -EINVAL;
}
ret = snd_soc_update_bits(codec, CS4349_MODE, DIF_MASK,
MODE_FORMAT(fmt));
if (ret < 0)
return ret;
return 0;
}
static int cs4349_digital_mute(struct snd_soc_dai *dai, int mute)
{
struct snd_soc_codec *codec = dai->codec;
int reg;
reg = 0;
if (mute)
reg = MUTE_AB_MASK;
return snd_soc_update_bits(codec, CS4349_MUTE, MUTE_AB_MASK, reg);
}
static int cs4349_i2c_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct cs4349_private *cs4349;
int ret;
cs4349 = devm_kzalloc(&client->dev, sizeof(*cs4349), GFP_KERNEL);
if (!cs4349)
return -ENOMEM;
cs4349->regmap = devm_regmap_init_i2c(client, &cs4349_regmap);
if (IS_ERR(cs4349->regmap)) {
ret = PTR_ERR(cs4349->regmap);
dev_err(&client->dev, "regmap_init() failed: %d\n", ret);
return ret;
}
cs4349->reset_gpio = devm_gpiod_get_optional(&client->dev,
"reset", GPIOD_OUT_LOW);
if (IS_ERR(cs4349->reset_gpio))
return PTR_ERR(cs4349->reset_gpio);
gpiod_set_value_cansleep(cs4349->reset_gpio, 1);
i2c_set_clientdata(client, cs4349);
return snd_soc_register_codec(&client->dev, &soc_codec_dev_cs4349,
&cs4349_dai, 1);
}
static int cs4349_i2c_remove(struct i2c_client *client)
{
struct cs4349_private *cs4349 = i2c_get_clientdata(client);
snd_soc_unregister_codec(&client->dev);
gpiod_set_value_cansleep(cs4349->reset_gpio, 0);
return 0;
}
static int cs4349_runtime_suspend(struct device *dev)
{
struct cs4349_private *cs4349 = dev_get_drvdata(dev);
int ret;
ret = regmap_update_bits(cs4349->regmap, CS4349_MISC, PWR_DWN, PWR_DWN);
if (ret < 0)
return ret;
regcache_cache_only(cs4349->regmap, true);
gpiod_set_value_cansleep(cs4349->reset_gpio, 0);
return 0;
}
static int cs4349_runtime_resume(struct device *dev)
{
struct cs4349_private *cs4349 = dev_get_drvdata(dev);
int ret;
ret = regmap_update_bits(cs4349->regmap, CS4349_MISC, PWR_DWN, 0);
if (ret < 0)
return ret;
gpiod_set_value_cansleep(cs4349->reset_gpio, 1);
regcache_cache_only(cs4349->regmap, false);
regcache_sync(cs4349->regmap);
return 0;
}
