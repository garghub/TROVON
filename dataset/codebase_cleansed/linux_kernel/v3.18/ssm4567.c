static bool ssm4567_readable_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case SSM4567_REG_POWER_CTRL ... SSM4567_REG_BOOST_CTRL_2:
return true;
default:
return false;
}
}
static bool ssm4567_writeable_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case SSM4567_REG_POWER_CTRL ... SSM4567_REG_SAI_PLACEMENT_6:
case SSM4567_REG_LIMITER_CTRL_1 ... SSM4567_REG_LIMITER_CTRL_3:
case SSM4567_REG_FAULT_CTRL ... SSM4567_REG_BOOST_CTRL_2:
case SSM4567_REG_SOFT_RESET:
return true;
default:
return false;
}
}
static bool ssm4567_volatile_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case SSM4567_REG_BATTERY_V_OUT:
case SSM4567_REG_STATUS_1 ... SSM4567_REG_STATUS_2:
case SSM4567_REG_SOFT_RESET:
return true;
default:
return false;
}
}
static int ssm4567_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params, struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct ssm4567 *ssm4567 = snd_soc_codec_get_drvdata(codec);
unsigned int rate = params_rate(params);
unsigned int dacfs;
if (rate >= 8000 && rate <= 12000)
dacfs = SSM4567_DAC_FS_8000_12000;
else if (rate >= 16000 && rate <= 24000)
dacfs = SSM4567_DAC_FS_16000_24000;
else if (rate >= 32000 && rate <= 48000)
dacfs = SSM4567_DAC_FS_32000_48000;
else if (rate >= 64000 && rate <= 96000)
dacfs = SSM4567_DAC_FS_64000_96000;
else if (rate >= 128000 && rate <= 192000)
dacfs = SSM4567_DAC_FS_128000_192000;
else
return -EINVAL;
return regmap_update_bits(ssm4567->regmap, SSM4567_REG_DAC_CTRL,
SSM4567_DAC_FS_MASK, dacfs);
}
static int ssm4567_mute(struct snd_soc_dai *dai, int mute)
{
struct ssm4567 *ssm4567 = snd_soc_codec_get_drvdata(dai->codec);
unsigned int val;
val = mute ? SSM4567_DAC_MUTE : 0;
return regmap_update_bits(ssm4567->regmap, SSM4567_REG_DAC_CTRL,
SSM4567_DAC_MUTE, val);
}
static int ssm4567_set_power(struct ssm4567 *ssm4567, bool enable)
{
int ret = 0;
if (!enable) {
ret = regmap_update_bits(ssm4567->regmap,
SSM4567_REG_POWER_CTRL,
SSM4567_POWER_SPWDN, SSM4567_POWER_SPWDN);
regcache_mark_dirty(ssm4567->regmap);
}
regcache_cache_only(ssm4567->regmap, !enable);
if (enable) {
ret = regmap_update_bits(ssm4567->regmap,
SSM4567_REG_POWER_CTRL,
SSM4567_POWER_SPWDN, 0x00);
regcache_sync(ssm4567->regmap);
}
return ret;
}
static int ssm4567_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
struct ssm4567 *ssm4567 = snd_soc_codec_get_drvdata(codec);
int ret = 0;
switch (level) {
case SND_SOC_BIAS_ON:
break;
case SND_SOC_BIAS_PREPARE:
break;
case SND_SOC_BIAS_STANDBY:
if (codec->dapm.bias_level == SND_SOC_BIAS_OFF)
ret = ssm4567_set_power(ssm4567, true);
break;
case SND_SOC_BIAS_OFF:
ret = ssm4567_set_power(ssm4567, false);
break;
}
if (ret)
return ret;
codec->dapm.bias_level = level;
return 0;
}
static int ssm4567_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct ssm4567 *ssm4567;
int ret;
ssm4567 = devm_kzalloc(&i2c->dev, sizeof(*ssm4567), GFP_KERNEL);
if (ssm4567 == NULL)
return -ENOMEM;
i2c_set_clientdata(i2c, ssm4567);
ssm4567->regmap = devm_regmap_init_i2c(i2c, &ssm4567_regmap_config);
if (IS_ERR(ssm4567->regmap))
return PTR_ERR(ssm4567->regmap);
ret = regmap_write(ssm4567->regmap, SSM4567_REG_SOFT_RESET, 0x00);
if (ret)
return ret;
ret = ssm4567_set_power(ssm4567, false);
if (ret)
return ret;
return snd_soc_register_codec(&i2c->dev, &ssm4567_codec_driver,
&ssm4567_dai, 1);
}
static int ssm4567_i2c_remove(struct i2c_client *client)
{
snd_soc_unregister_codec(&client->dev);
return 0;
}
