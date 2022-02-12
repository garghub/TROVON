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
static int ssm4567_set_tdm_slot(struct snd_soc_dai *dai, unsigned int tx_mask,
unsigned int rx_mask, int slots, int width)
{
struct ssm4567 *ssm4567 = snd_soc_dai_get_drvdata(dai);
unsigned int blcks;
int slot;
int ret;
if (tx_mask == 0)
return -EINVAL;
if (rx_mask && rx_mask != tx_mask)
return -EINVAL;
slot = __ffs(tx_mask);
if (tx_mask != BIT(slot))
return -EINVAL;
switch (width) {
case 32:
blcks = SSM4567_SAI_CTRL_1_TDM_BLCKS_32;
break;
case 48:
blcks = SSM4567_SAI_CTRL_1_TDM_BLCKS_48;
break;
case 64:
blcks = SSM4567_SAI_CTRL_1_TDM_BLCKS_64;
break;
default:
return -EINVAL;
}
ret = regmap_update_bits(ssm4567->regmap, SSM4567_REG_SAI_CTRL_2,
SSM4567_SAI_CTRL_2_AUTO_SLOT | SSM4567_SAI_CTRL_2_TDM_SLOT_MASK,
SSM4567_SAI_CTRL_2_TDM_SLOT(slot));
if (ret)
return ret;
return regmap_update_bits(ssm4567->regmap, SSM4567_REG_SAI_CTRL_1,
SSM4567_SAI_CTRL_1_TDM_BLCKS_MASK, blcks);
}
static int ssm4567_set_dai_fmt(struct snd_soc_dai *dai, unsigned int fmt)
{
struct ssm4567 *ssm4567 = snd_soc_dai_get_drvdata(dai);
unsigned int ctrl1 = 0;
bool invert_fclk;
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBS_CFS:
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
invert_fclk = false;
break;
case SND_SOC_DAIFMT_IB_NF:
ctrl1 |= SSM4567_SAI_CTRL_1_BCLK;
invert_fclk = false;
break;
case SND_SOC_DAIFMT_NB_IF:
ctrl1 |= SSM4567_SAI_CTRL_1_FSYNC;
invert_fclk = true;
break;
case SND_SOC_DAIFMT_IB_IF:
ctrl1 |= SSM4567_SAI_CTRL_1_BCLK;
invert_fclk = true;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
break;
case SND_SOC_DAIFMT_LEFT_J:
ctrl1 |= SSM4567_SAI_CTRL_1_LJ;
invert_fclk = !invert_fclk;
break;
case SND_SOC_DAIFMT_DSP_A:
ctrl1 |= SSM4567_SAI_CTRL_1_TDM;
break;
case SND_SOC_DAIFMT_DSP_B:
ctrl1 |= SSM4567_SAI_CTRL_1_TDM | SSM4567_SAI_CTRL_1_LJ;
break;
case SND_SOC_DAIFMT_PDM:
ctrl1 |= SSM4567_SAI_CTRL_1_PDM;
break;
default:
return -EINVAL;
}
if (invert_fclk)
ctrl1 |= SSM4567_SAI_CTRL_1_FSYNC;
return regmap_update_bits(ssm4567->regmap, SSM4567_REG_SAI_CTRL_1,
SSM4567_SAI_CTRL_1_BCLK |
SSM4567_SAI_CTRL_1_FSYNC |
SSM4567_SAI_CTRL_1_LJ |
SSM4567_SAI_CTRL_1_TDM |
SSM4567_SAI_CTRL_1_PDM,
ctrl1);
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
ret = regmap_write(ssm4567->regmap, SSM4567_REG_SOFT_RESET,
0x00);
if (ret)
return ret;
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
if (snd_soc_codec_get_bias_level(codec) == SND_SOC_BIAS_OFF)
ret = ssm4567_set_power(ssm4567, true);
break;
case SND_SOC_BIAS_OFF:
ret = ssm4567_set_power(ssm4567, false);
break;
}
return ret;
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
