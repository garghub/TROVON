static unsigned int ssm2518_lookup_mcs(struct ssm2518 *ssm2518,
unsigned int rate)
{
const unsigned int *sysclks = NULL;
int i;
for (i = 0; i < ARRAY_SIZE(ssm2518_mcs_lut); i++) {
if (ssm2518_mcs_lut[i].rate == rate) {
sysclks = ssm2518_mcs_lut[i].sysclks;
break;
}
}
if (!sysclks)
return -EINVAL;
for (i = 0; sysclks[i]; i++) {
if (sysclks[i] == ssm2518->sysclk)
return i;
}
return -EINVAL;
}
static int ssm2518_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params, struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct ssm2518 *ssm2518 = snd_soc_codec_get_drvdata(codec);
unsigned int rate = params_rate(params);
unsigned int ctrl1, ctrl1_mask;
int mcs;
int ret;
mcs = ssm2518_lookup_mcs(ssm2518, rate);
if (mcs < 0)
return mcs;
ctrl1_mask = SSM2518_SAI_CTRL1_FS_MASK;
if (rate >= 8000 && rate <= 12000)
ctrl1 = SSM2518_SAI_CTRL1_FS_8000_12000;
else if (rate >= 16000 && rate <= 24000)
ctrl1 = SSM2518_SAI_CTRL1_FS_16000_24000;
else if (rate >= 32000 && rate <= 48000)
ctrl1 = SSM2518_SAI_CTRL1_FS_32000_48000;
else if (rate >= 64000 && rate <= 96000)
ctrl1 = SSM2518_SAI_CTRL1_FS_64000_96000;
else
return -EINVAL;
if (ssm2518->right_j) {
switch (params_width(params)) {
case 16:
ctrl1 |= SSM2518_SAI_CTRL1_FMT_RJ_16BIT;
break;
case 24:
ctrl1 |= SSM2518_SAI_CTRL1_FMT_RJ_24BIT;
break;
default:
return -EINVAL;
}
ctrl1_mask |= SSM2518_SAI_CTRL1_FMT_MASK;
}
ret = regmap_update_bits(ssm2518->regmap, SSM2518_REG_CLOCK,
SSM2518_CLOCK_ASR, SSM2518_CLOCK_ASR);
if (ret < 0)
return ret;
ret = regmap_update_bits(ssm2518->regmap, SSM2518_REG_SAI_CTRL1,
ctrl1_mask, ctrl1);
if (ret < 0)
return ret;
return regmap_update_bits(ssm2518->regmap, SSM2518_REG_POWER1,
SSM2518_POWER1_MCS_MASK, mcs << 1);
}
static int ssm2518_mute(struct snd_soc_dai *dai, int mute)
{
struct ssm2518 *ssm2518 = snd_soc_codec_get_drvdata(dai->codec);
unsigned int val;
if (mute)
val = SSM2518_MUTE_CTRL_MUTE_MASTER;
else
val = 0;
return regmap_update_bits(ssm2518->regmap, SSM2518_REG_MUTE_CTRL,
SSM2518_MUTE_CTRL_MUTE_MASTER, val);
}
static int ssm2518_set_dai_fmt(struct snd_soc_dai *dai, unsigned int fmt)
{
struct ssm2518 *ssm2518 = snd_soc_codec_get_drvdata(dai->codec);
unsigned int ctrl1 = 0, ctrl2 = 0;
bool invert_fclk;
int ret;
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
ctrl2 |= SSM2518_SAI_CTRL2_BCLK_INVERT;
invert_fclk = false;
break;
case SND_SOC_DAIFMT_NB_IF:
invert_fclk = true;
break;
case SND_SOC_DAIFMT_IB_IF:
ctrl2 |= SSM2518_SAI_CTRL2_BCLK_INVERT;
invert_fclk = true;
break;
default:
return -EINVAL;
}
ssm2518->right_j = false;
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
ctrl1 |= SSM2518_SAI_CTRL1_FMT_I2S;
break;
case SND_SOC_DAIFMT_LEFT_J:
ctrl1 |= SSM2518_SAI_CTRL1_FMT_LJ;
invert_fclk = !invert_fclk;
break;
case SND_SOC_DAIFMT_RIGHT_J:
ctrl1 |= SSM2518_SAI_CTRL1_FMT_RJ_24BIT;
ssm2518->right_j = true;
invert_fclk = !invert_fclk;
break;
case SND_SOC_DAIFMT_DSP_A:
ctrl2 |= SSM2518_SAI_CTRL2_LRCLK_PULSE;
ctrl1 |= SSM2518_SAI_CTRL1_FMT_I2S;
invert_fclk = false;
break;
case SND_SOC_DAIFMT_DSP_B:
ctrl2 |= SSM2518_SAI_CTRL2_LRCLK_PULSE;
ctrl1 |= SSM2518_SAI_CTRL1_FMT_LJ;
invert_fclk = false;
break;
default:
return -EINVAL;
}
if (invert_fclk)
ctrl2 |= SSM2518_SAI_CTRL2_LRCLK_INVERT;
ret = regmap_write(ssm2518->regmap, SSM2518_REG_SAI_CTRL1, ctrl1);
if (ret)
return ret;
return regmap_write(ssm2518->regmap, SSM2518_REG_SAI_CTRL2, ctrl2);
}
static int ssm2518_set_power(struct ssm2518 *ssm2518, bool enable)
{
int ret = 0;
if (!enable) {
ret = regmap_update_bits(ssm2518->regmap, SSM2518_REG_POWER1,
SSM2518_POWER1_SPWDN, SSM2518_POWER1_SPWDN);
regcache_mark_dirty(ssm2518->regmap);
}
if (gpio_is_valid(ssm2518->enable_gpio))
gpio_set_value(ssm2518->enable_gpio, enable);
regcache_cache_only(ssm2518->regmap, !enable);
if (enable) {
ret = regmap_update_bits(ssm2518->regmap, SSM2518_REG_POWER1,
SSM2518_POWER1_SPWDN | SSM2518_POWER1_RESET, 0x00);
regcache_sync(ssm2518->regmap);
}
return ret;
}
static int ssm2518_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
struct ssm2518 *ssm2518 = snd_soc_codec_get_drvdata(codec);
int ret = 0;
switch (level) {
case SND_SOC_BIAS_ON:
break;
case SND_SOC_BIAS_PREPARE:
break;
case SND_SOC_BIAS_STANDBY:
if (snd_soc_codec_get_bias_level(codec) == SND_SOC_BIAS_OFF)
ret = ssm2518_set_power(ssm2518, true);
break;
case SND_SOC_BIAS_OFF:
ret = ssm2518_set_power(ssm2518, false);
break;
}
return ret;
}
static int ssm2518_set_tdm_slot(struct snd_soc_dai *dai, unsigned int tx_mask,
unsigned int rx_mask, int slots, int width)
{
struct ssm2518 *ssm2518 = snd_soc_codec_get_drvdata(dai->codec);
unsigned int ctrl1, ctrl2;
int left_slot, right_slot;
int ret;
if (slots == 0)
return regmap_update_bits(ssm2518->regmap,
SSM2518_REG_SAI_CTRL1, SSM2518_SAI_CTRL1_SAI_MASK,
SSM2518_SAI_CTRL1_SAI_I2S);
if (tx_mask == 0 || rx_mask != 0)
return -EINVAL;
if (slots == 1) {
if (tx_mask != 1)
return -EINVAL;
left_slot = 0;
right_slot = 0;
} else {
left_slot = __ffs(tx_mask);
tx_mask &= ~(1 << left_slot);
if (tx_mask == 0) {
right_slot = left_slot;
} else {
right_slot = __ffs(tx_mask);
tx_mask &= ~(1 << right_slot);
}
}
if (tx_mask != 0 || left_slot >= slots || right_slot >= slots)
return -EINVAL;
switch (width) {
case 16:
ctrl2 = SSM2518_SAI_CTRL2_SLOT_WIDTH_16;
break;
case 24:
ctrl2 = SSM2518_SAI_CTRL2_SLOT_WIDTH_24;
break;
case 32:
ctrl2 = SSM2518_SAI_CTRL2_SLOT_WIDTH_32;
break;
default:
return -EINVAL;
}
switch (slots) {
case 1:
ctrl1 = SSM2518_SAI_CTRL1_SAI_MONO;
break;
case 2:
ctrl1 = SSM2518_SAI_CTRL1_SAI_TDM_2;
break;
case 4:
ctrl1 = SSM2518_SAI_CTRL1_SAI_TDM_4;
break;
case 8:
ctrl1 = SSM2518_SAI_CTRL1_SAI_TDM_8;
break;
case 16:
ctrl1 = SSM2518_SAI_CTRL1_SAI_TDM_16;
break;
default:
return -EINVAL;
}
ret = regmap_write(ssm2518->regmap, SSM2518_REG_CHAN_MAP,
(left_slot << SSM2518_CHAN_MAP_LEFT_SLOT_OFFSET) |
(right_slot << SSM2518_CHAN_MAP_RIGHT_SLOT_OFFSET));
if (ret)
return ret;
ret = regmap_update_bits(ssm2518->regmap, SSM2518_REG_SAI_CTRL1,
SSM2518_SAI_CTRL1_SAI_MASK, ctrl1);
if (ret)
return ret;
return regmap_update_bits(ssm2518->regmap, SSM2518_REG_SAI_CTRL2,
SSM2518_SAI_CTRL2_SLOT_WIDTH_MASK, ctrl2);
}
static int ssm2518_startup(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct ssm2518 *ssm2518 = snd_soc_codec_get_drvdata(dai->codec);
if (ssm2518->constraints)
snd_pcm_hw_constraint_list(substream->runtime, 0,
SNDRV_PCM_HW_PARAM_RATE, ssm2518->constraints);
return 0;
}
static int ssm2518_set_sysclk(struct snd_soc_codec *codec, int clk_id,
int source, unsigned int freq, int dir)
{
struct ssm2518 *ssm2518 = snd_soc_codec_get_drvdata(codec);
unsigned int val;
if (clk_id != SSM2518_SYSCLK)
return -EINVAL;
switch (source) {
case SSM2518_SYSCLK_SRC_MCLK:
val = 0;
break;
case SSM2518_SYSCLK_SRC_BCLK:
val = SSM2518_POWER1_NO_BCLK;
break;
default:
return -EINVAL;
}
switch (freq) {
case 0:
ssm2518->constraints = NULL;
break;
case 2048000:
case 4096000:
case 8192000:
case 3200000:
case 6400000:
case 12800000:
ssm2518->constraints = &ssm2518_constraints_2048000;
break;
case 2822000:
case 5644800:
case 11289600:
case 16934400:
case 22579200:
case 33868800:
case 4410000:
case 8820000:
case 17640000:
ssm2518->constraints = &ssm2518_constraints_2822000;
break;
case 3072000:
case 6144000:
case 38864000:
case 4800000:
case 9600000:
case 19200000:
ssm2518->constraints = &ssm2518_constraints_3072000;
break;
case 12288000:
case 16384000:
case 24576000:
ssm2518->constraints = &ssm2518_constraints_12288000;
break;
default:
return -EINVAL;
}
ssm2518->sysclk = freq;
return regmap_update_bits(ssm2518->regmap, SSM2518_REG_POWER1,
SSM2518_POWER1_NO_BCLK, val);
}
static bool ssm2518_register_volatile(struct device *dev, unsigned int reg)
{
return false;
}
static int ssm2518_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct ssm2518_platform_data *pdata = i2c->dev.platform_data;
struct ssm2518 *ssm2518;
int ret;
ssm2518 = devm_kzalloc(&i2c->dev, sizeof(*ssm2518), GFP_KERNEL);
if (ssm2518 == NULL)
return -ENOMEM;
if (pdata) {
ssm2518->enable_gpio = pdata->enable_gpio;
} else if (i2c->dev.of_node) {
ssm2518->enable_gpio = of_get_gpio(i2c->dev.of_node, 0);
if (ssm2518->enable_gpio < 0 && ssm2518->enable_gpio != -ENOENT)
return ssm2518->enable_gpio;
} else {
ssm2518->enable_gpio = -1;
}
if (gpio_is_valid(ssm2518->enable_gpio)) {
ret = devm_gpio_request_one(&i2c->dev, ssm2518->enable_gpio,
GPIOF_OUT_INIT_HIGH, "SSM2518 nSD");
if (ret)
return ret;
}
i2c_set_clientdata(i2c, ssm2518);
ssm2518->regmap = devm_regmap_init_i2c(i2c, &ssm2518_regmap_config);
if (IS_ERR(ssm2518->regmap))
return PTR_ERR(ssm2518->regmap);
regcache_cache_bypass(ssm2518->regmap, true);
ret = regmap_write(ssm2518->regmap, SSM2518_REG_POWER1,
SSM2518_POWER1_RESET);
regcache_cache_bypass(ssm2518->regmap, false);
if (ret)
return ret;
ret = regmap_update_bits(ssm2518->regmap, SSM2518_REG_POWER2,
SSM2518_POWER2_APWDN, 0x00);
if (ret)
return ret;
ret = ssm2518_set_power(ssm2518, false);
if (ret)
return ret;
return snd_soc_register_codec(&i2c->dev, &ssm2518_codec_driver,
&ssm2518_dai, 1);
}
static int ssm2518_i2c_remove(struct i2c_client *client)
{
snd_soc_unregister_codec(&client->dev);
return 0;
}
