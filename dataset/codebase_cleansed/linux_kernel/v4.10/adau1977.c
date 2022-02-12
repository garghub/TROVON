static int adau1977_reset(struct adau1977 *adau1977)
{
int ret;
regcache_cache_bypass(adau1977->regmap, true);
ret = regmap_write(adau1977->regmap, ADAU1977_REG_POWER,
ADAU1977_POWER_RESET);
regcache_cache_bypass(adau1977->regmap, false);
if (ret)
return ret;
return ret;
}
static int adau1977_lookup_fs(unsigned int rate)
{
if (rate >= 8000 && rate <= 12000)
return ADAU1977_SAI_CTRL0_FS_8000_12000;
else if (rate >= 16000 && rate <= 24000)
return ADAU1977_SAI_CTRL0_FS_16000_24000;
else if (rate >= 32000 && rate <= 48000)
return ADAU1977_SAI_CTRL0_FS_32000_48000;
else if (rate >= 64000 && rate <= 96000)
return ADAU1977_SAI_CTRL0_FS_64000_96000;
else if (rate >= 128000 && rate <= 192000)
return ADAU1977_SAI_CTRL0_FS_128000_192000;
else
return -EINVAL;
}
static int adau1977_lookup_mcs(struct adau1977 *adau1977, unsigned int rate,
unsigned int fs)
{
unsigned int mcs;
rate *= 512 >> fs;
if (adau1977->sysclk % rate != 0)
return -EINVAL;
mcs = adau1977->sysclk / rate;
if (mcs < 1 || mcs > 6 || mcs == 5)
return -EINVAL;
mcs = mcs - 1;
if (mcs == 5)
mcs = 4;
return mcs;
}
static int adau1977_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params, struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct adau1977 *adau1977 = snd_soc_codec_get_drvdata(codec);
unsigned int rate = params_rate(params);
unsigned int slot_width;
unsigned int ctrl0, ctrl0_mask;
unsigned int ctrl1;
int mcs, fs;
int ret;
fs = adau1977_lookup_fs(rate);
if (fs < 0)
return fs;
if (adau1977->sysclk_src == ADAU1977_SYSCLK_SRC_MCLK) {
mcs = adau1977_lookup_mcs(adau1977, rate, fs);
if (mcs < 0)
return mcs;
} else {
mcs = 0;
}
ctrl0_mask = ADAU1977_SAI_CTRL0_FS_MASK;
ctrl0 = fs;
if (adau1977->right_j) {
switch (params_width(params)) {
case 16:
ctrl0 |= ADAU1977_SAI_CTRL0_FMT_RJ_16BIT;
break;
case 24:
ctrl0 |= ADAU1977_SAI_CTRL0_FMT_RJ_24BIT;
break;
default:
return -EINVAL;
}
ctrl0_mask |= ADAU1977_SAI_CTRL0_FMT_MASK;
}
if (adau1977->master) {
switch (params_width(params)) {
case 16:
ctrl1 = ADAU1977_SAI_CTRL1_DATA_WIDTH_16BIT;
slot_width = 16;
break;
case 24:
case 32:
ctrl1 = ADAU1977_SAI_CTRL1_DATA_WIDTH_24BIT;
slot_width = 32;
break;
default:
return -EINVAL;
}
if (adau1977->slot_width)
slot_width = adau1977->slot_width;
if (slot_width == 16)
ctrl1 |= ADAU1977_SAI_CTRL1_BCLKRATE_16;
else
ctrl1 |= ADAU1977_SAI_CTRL1_BCLKRATE_32;
ret = regmap_update_bits(adau1977->regmap,
ADAU1977_REG_SAI_CTRL1,
ADAU1977_SAI_CTRL1_DATA_WIDTH_MASK |
ADAU1977_SAI_CTRL1_BCLKRATE_MASK,
ctrl1);
if (ret < 0)
return ret;
}
ret = regmap_update_bits(adau1977->regmap, ADAU1977_REG_SAI_CTRL0,
ctrl0_mask, ctrl0);
if (ret < 0)
return ret;
return regmap_update_bits(adau1977->regmap, ADAU1977_REG_PLL,
ADAU1977_PLL_MCS_MASK, mcs);
}
static int adau1977_power_disable(struct adau1977 *adau1977)
{
int ret = 0;
if (!adau1977->enabled)
return 0;
ret = regmap_update_bits(adau1977->regmap, ADAU1977_REG_POWER,
ADAU1977_POWER_PWUP, 0);
if (ret)
return ret;
regcache_mark_dirty(adau1977->regmap);
if (adau1977->reset_gpio)
gpiod_set_value_cansleep(adau1977->reset_gpio, 0);
regcache_cache_only(adau1977->regmap, true);
regulator_disable(adau1977->avdd_reg);
if (adau1977->dvdd_reg)
regulator_disable(adau1977->dvdd_reg);
adau1977->enabled = false;
return 0;
}
static int adau1977_power_enable(struct adau1977 *adau1977)
{
unsigned int val;
int ret = 0;
if (adau1977->enabled)
return 0;
ret = regulator_enable(adau1977->avdd_reg);
if (ret)
return ret;
if (adau1977->dvdd_reg) {
ret = regulator_enable(adau1977->dvdd_reg);
if (ret)
goto err_disable_avdd;
}
if (adau1977->reset_gpio)
gpiod_set_value_cansleep(adau1977->reset_gpio, 1);
regcache_cache_only(adau1977->regmap, false);
if (adau1977->switch_mode)
adau1977->switch_mode(adau1977->dev);
ret = adau1977_reset(adau1977);
if (ret)
goto err_disable_dvdd;
ret = regmap_update_bits(adau1977->regmap, ADAU1977_REG_POWER,
ADAU1977_POWER_PWUP, ADAU1977_POWER_PWUP);
if (ret)
goto err_disable_dvdd;
ret = regcache_sync(adau1977->regmap);
if (ret)
goto err_disable_dvdd;
ret = regmap_read(adau1977->regmap, ADAU1977_REG_PLL, &val);
if (ret)
goto err_disable_dvdd;
if (val == 0x41) {
regcache_cache_bypass(adau1977->regmap, true);
ret = regmap_write(adau1977->regmap, ADAU1977_REG_PLL,
0x41);
if (ret)
goto err_disable_dvdd;
regcache_cache_bypass(adau1977->regmap, false);
}
adau1977->enabled = true;
return ret;
err_disable_dvdd:
if (adau1977->dvdd_reg)
regulator_disable(adau1977->dvdd_reg);
err_disable_avdd:
regulator_disable(adau1977->avdd_reg);
return ret;
}
static int adau1977_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
struct adau1977 *adau1977 = snd_soc_codec_get_drvdata(codec);
int ret = 0;
switch (level) {
case SND_SOC_BIAS_ON:
break;
case SND_SOC_BIAS_PREPARE:
break;
case SND_SOC_BIAS_STANDBY:
if (snd_soc_codec_get_bias_level(codec) == SND_SOC_BIAS_OFF)
ret = adau1977_power_enable(adau1977);
break;
case SND_SOC_BIAS_OFF:
ret = adau1977_power_disable(adau1977);
break;
}
return ret;
}
static int adau1977_set_tdm_slot(struct snd_soc_dai *dai, unsigned int tx_mask,
unsigned int rx_mask, int slots, int width)
{
struct adau1977 *adau1977 = snd_soc_codec_get_drvdata(dai->codec);
unsigned int ctrl0, ctrl1, drv;
unsigned int slot[4];
unsigned int i;
int ret;
if (slots == 0) {
adau1977->slot_width = 0;
adau1977->max_master_fs = 192000;
return regmap_update_bits(adau1977->regmap,
ADAU1977_REG_SAI_CTRL0, ADAU1977_SAI_CTRL0_SAI_MASK,
ADAU1977_SAI_CTRL0_SAI_I2S);
}
if (rx_mask == 0 || tx_mask != 0)
return -EINVAL;
drv = 0;
for (i = 0; i < 4; i++) {
slot[i] = __ffs(rx_mask);
drv |= ADAU1977_SAI_OVERTEMP_DRV_C(i);
rx_mask &= ~(1 << slot[i]);
if (slot[i] >= slots)
return -EINVAL;
if (rx_mask == 0)
break;
}
if (rx_mask != 0)
return -EINVAL;
switch (width) {
case 16:
ctrl1 = ADAU1977_SAI_CTRL1_SLOT_WIDTH_16;
break;
case 24:
if (adau1977->master)
return -EINVAL;
ctrl1 = ADAU1977_SAI_CTRL1_SLOT_WIDTH_24;
break;
case 32:
ctrl1 = ADAU1977_SAI_CTRL1_SLOT_WIDTH_32;
break;
default:
return -EINVAL;
}
switch (slots) {
case 2:
ctrl0 = ADAU1977_SAI_CTRL0_SAI_TDM_2;
break;
case 4:
ctrl0 = ADAU1977_SAI_CTRL0_SAI_TDM_4;
break;
case 8:
ctrl0 = ADAU1977_SAI_CTRL0_SAI_TDM_8;
break;
case 16:
ctrl0 = ADAU1977_SAI_CTRL0_SAI_TDM_16;
break;
default:
return -EINVAL;
}
ret = regmap_update_bits(adau1977->regmap, ADAU1977_REG_SAI_OVERTEMP,
ADAU1977_SAI_OVERTEMP_DRV_C(0) |
ADAU1977_SAI_OVERTEMP_DRV_C(1) |
ADAU1977_SAI_OVERTEMP_DRV_C(2) |
ADAU1977_SAI_OVERTEMP_DRV_C(3), drv);
if (ret)
return ret;
ret = regmap_write(adau1977->regmap, ADAU1977_REG_CMAP12,
(slot[1] << ADAU1977_CHAN_MAP_SECOND_SLOT_OFFSET) |
(slot[0] << ADAU1977_CHAN_MAP_FIRST_SLOT_OFFSET));
if (ret)
return ret;
ret = regmap_write(adau1977->regmap, ADAU1977_REG_CMAP34,
(slot[3] << ADAU1977_CHAN_MAP_SECOND_SLOT_OFFSET) |
(slot[2] << ADAU1977_CHAN_MAP_FIRST_SLOT_OFFSET));
if (ret)
return ret;
ret = regmap_update_bits(adau1977->regmap, ADAU1977_REG_SAI_CTRL0,
ADAU1977_SAI_CTRL0_SAI_MASK, ctrl0);
if (ret)
return ret;
ret = regmap_update_bits(adau1977->regmap, ADAU1977_REG_SAI_CTRL1,
ADAU1977_SAI_CTRL1_SLOT_WIDTH_MASK, ctrl1);
if (ret)
return ret;
adau1977->slot_width = width;
adau1977->max_master_fs = min(192000, 24576000 / width / slots);
return 0;
}
static int adau1977_mute(struct snd_soc_dai *dai, int mute, int stream)
{
struct adau1977 *adau1977 = snd_soc_codec_get_drvdata(dai->codec);
unsigned int val;
if (mute)
val = ADAU1977_MISC_CONTROL_MMUTE;
else
val = 0;
return regmap_update_bits(adau1977->regmap, ADAU1977_REG_MISC_CONTROL,
ADAU1977_MISC_CONTROL_MMUTE, val);
}
static int adau1977_set_dai_fmt(struct snd_soc_dai *dai, unsigned int fmt)
{
struct adau1977 *adau1977 = snd_soc_codec_get_drvdata(dai->codec);
unsigned int ctrl0 = 0, ctrl1 = 0, block_power = 0;
bool invert_lrclk;
int ret;
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBS_CFS:
adau1977->master = false;
break;
case SND_SOC_DAIFMT_CBM_CFM:
ctrl1 |= ADAU1977_SAI_CTRL1_MASTER;
adau1977->master = true;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
invert_lrclk = false;
break;
case SND_SOC_DAIFMT_IB_NF:
block_power |= ADAU1977_BLOCK_POWER_SAI_BCLK_EDGE;
invert_lrclk = false;
break;
case SND_SOC_DAIFMT_NB_IF:
invert_lrclk = true;
break;
case SND_SOC_DAIFMT_IB_IF:
block_power |= ADAU1977_BLOCK_POWER_SAI_BCLK_EDGE;
invert_lrclk = true;
break;
default:
return -EINVAL;
}
adau1977->right_j = false;
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
ctrl0 |= ADAU1977_SAI_CTRL0_FMT_I2S;
break;
case SND_SOC_DAIFMT_LEFT_J:
ctrl0 |= ADAU1977_SAI_CTRL0_FMT_LJ;
invert_lrclk = !invert_lrclk;
break;
case SND_SOC_DAIFMT_RIGHT_J:
ctrl0 |= ADAU1977_SAI_CTRL0_FMT_RJ_24BIT;
adau1977->right_j = true;
invert_lrclk = !invert_lrclk;
break;
case SND_SOC_DAIFMT_DSP_A:
ctrl1 |= ADAU1977_SAI_CTRL1_LRCLK_PULSE;
ctrl0 |= ADAU1977_SAI_CTRL0_FMT_I2S;
invert_lrclk = false;
break;
case SND_SOC_DAIFMT_DSP_B:
ctrl1 |= ADAU1977_SAI_CTRL1_LRCLK_PULSE;
ctrl0 |= ADAU1977_SAI_CTRL0_FMT_LJ;
invert_lrclk = false;
break;
default:
return -EINVAL;
}
if (invert_lrclk)
block_power |= ADAU1977_BLOCK_POWER_SAI_LR_POL;
ret = regmap_update_bits(adau1977->regmap, ADAU1977_REG_BLOCK_POWER_SAI,
ADAU1977_BLOCK_POWER_SAI_LR_POL |
ADAU1977_BLOCK_POWER_SAI_BCLK_EDGE, block_power);
if (ret)
return ret;
ret = regmap_update_bits(adau1977->regmap, ADAU1977_REG_SAI_CTRL0,
ADAU1977_SAI_CTRL0_FMT_MASK,
ctrl0);
if (ret)
return ret;
return regmap_update_bits(adau1977->regmap, ADAU1977_REG_SAI_CTRL1,
ADAU1977_SAI_CTRL1_MASTER | ADAU1977_SAI_CTRL1_LRCLK_PULSE,
ctrl1);
}
static int adau1977_startup(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct adau1977 *adau1977 = snd_soc_codec_get_drvdata(dai->codec);
u64 formats = 0;
if (adau1977->slot_width == 16)
formats = SNDRV_PCM_FMTBIT_S16_LE | SNDRV_PCM_FMTBIT_S16_BE;
else if (adau1977->right_j || adau1977->slot_width == 24)
formats = SNDRV_PCM_FMTBIT_S16_LE | SNDRV_PCM_FMTBIT_S16_BE |
SNDRV_PCM_FMTBIT_S24_LE | SNDRV_PCM_FMTBIT_S24_BE;
snd_pcm_hw_constraint_list(substream->runtime, 0,
SNDRV_PCM_HW_PARAM_RATE, &adau1977->constraints);
if (adau1977->master)
snd_pcm_hw_constraint_minmax(substream->runtime,
SNDRV_PCM_HW_PARAM_RATE, 8000, adau1977->max_master_fs);
if (formats != 0)
snd_pcm_hw_constraint_mask64(substream->runtime,
SNDRV_PCM_HW_PARAM_FORMAT, formats);
return 0;
}
static int adau1977_set_tristate(struct snd_soc_dai *dai, int tristate)
{
struct adau1977 *adau1977 = snd_soc_codec_get_drvdata(dai->codec);
unsigned int val;
if (tristate)
val = ADAU1977_SAI_OVERTEMP_DRV_HIZ;
else
val = 0;
return regmap_update_bits(adau1977->regmap, ADAU1977_REG_SAI_OVERTEMP,
ADAU1977_SAI_OVERTEMP_DRV_HIZ, val);
}
static bool adau1977_check_sysclk(unsigned int mclk, unsigned int base_freq)
{
unsigned int mcs;
if (mclk % (base_freq * 128) != 0)
return false;
mcs = mclk / (128 * base_freq);
if (mcs < 1 || mcs > 6 || mcs == 5)
return false;
return true;
}
static int adau1977_set_sysclk(struct snd_soc_codec *codec,
int clk_id, int source, unsigned int freq, int dir)
{
struct adau1977 *adau1977 = snd_soc_codec_get_drvdata(codec);
unsigned int mask = 0;
unsigned int clk_src;
unsigned int ret;
if (dir != SND_SOC_CLOCK_IN)
return -EINVAL;
if (clk_id != ADAU1977_SYSCLK)
return -EINVAL;
switch (source) {
case ADAU1977_SYSCLK_SRC_MCLK:
clk_src = 0;
break;
case ADAU1977_SYSCLK_SRC_LRCLK:
clk_src = ADAU1977_PLL_CLK_S;
break;
default:
return -EINVAL;
}
if (freq != 0 && source == ADAU1977_SYSCLK_SRC_MCLK) {
if (freq < 4000000 || freq > 36864000)
return -EINVAL;
if (adau1977_check_sysclk(freq, 32000))
mask |= ADAU1977_RATE_CONSTRAINT_MASK_32000;
if (adau1977_check_sysclk(freq, 44100))
mask |= ADAU1977_RATE_CONSTRAINT_MASK_44100;
if (adau1977_check_sysclk(freq, 48000))
mask |= ADAU1977_RATE_CONSTRAINT_MASK_48000;
if (mask == 0)
return -EINVAL;
} else if (source == ADAU1977_SYSCLK_SRC_LRCLK) {
mask = ADAU1977_RATE_CONSTRAINT_MASK_LRCLK;
}
ret = regmap_update_bits(adau1977->regmap, ADAU1977_REG_PLL,
ADAU1977_PLL_CLK_S, clk_src);
if (ret)
return ret;
adau1977->constraints.mask = mask;
adau1977->sysclk_src = source;
adau1977->sysclk = freq;
return 0;
}
static int adau1977_codec_probe(struct snd_soc_codec *codec)
{
struct snd_soc_dapm_context *dapm = snd_soc_codec_get_dapm(codec);
struct adau1977 *adau1977 = snd_soc_codec_get_drvdata(codec);
int ret;
switch (adau1977->type) {
case ADAU1977:
ret = snd_soc_dapm_new_controls(dapm,
adau1977_micbias_dapm_widgets,
ARRAY_SIZE(adau1977_micbias_dapm_widgets));
if (ret < 0)
return ret;
break;
default:
break;
}
return 0;
}
static int adau1977_setup_micbias(struct adau1977 *adau1977)
{
struct adau1977_platform_data *pdata = adau1977->dev->platform_data;
unsigned int micbias;
if (pdata) {
micbias = pdata->micbias;
if (micbias > ADAU1977_MICBIAS_9V0)
return -EINVAL;
} else {
micbias = ADAU1977_MICBIAS_8V5;
}
return regmap_update_bits(adau1977->regmap, ADAU1977_REG_MICBIAS,
ADAU1977_MICBIAS_MB_VOLTS_MASK,
micbias << ADAU1977_MICBIAS_MB_VOLTS_OFFSET);
}
int adau1977_probe(struct device *dev, struct regmap *regmap,
enum adau1977_type type, void (*switch_mode)(struct device *dev))
{
unsigned int power_off_mask;
struct adau1977 *adau1977;
int ret;
if (IS_ERR(regmap))
return PTR_ERR(regmap);
adau1977 = devm_kzalloc(dev, sizeof(*adau1977), GFP_KERNEL);
if (adau1977 == NULL)
return -ENOMEM;
adau1977->dev = dev;
adau1977->type = type;
adau1977->regmap = regmap;
adau1977->switch_mode = switch_mode;
adau1977->max_master_fs = 192000;
adau1977->constraints.list = adau1977_rates;
adau1977->constraints.count = ARRAY_SIZE(adau1977_rates);
adau1977->avdd_reg = devm_regulator_get(dev, "AVDD");
if (IS_ERR(adau1977->avdd_reg))
return PTR_ERR(adau1977->avdd_reg);
adau1977->dvdd_reg = devm_regulator_get_optional(dev, "DVDD");
if (IS_ERR(adau1977->dvdd_reg)) {
if (PTR_ERR(adau1977->dvdd_reg) != -ENODEV)
return PTR_ERR(adau1977->dvdd_reg);
adau1977->dvdd_reg = NULL;
}
adau1977->reset_gpio = devm_gpiod_get_optional(dev, "reset",
GPIOD_OUT_LOW);
if (IS_ERR(adau1977->reset_gpio))
return PTR_ERR(adau1977->reset_gpio);
dev_set_drvdata(dev, adau1977);
if (adau1977->reset_gpio)
ndelay(100);
ret = adau1977_power_enable(adau1977);
if (ret)
return ret;
if (type == ADAU1977) {
ret = adau1977_setup_micbias(adau1977);
if (ret)
goto err_poweroff;
}
if (adau1977->dvdd_reg)
power_off_mask = ~0;
else
power_off_mask = (unsigned int)~ADAU1977_BLOCK_POWER_SAI_LDO_EN;
ret = regmap_update_bits(adau1977->regmap, ADAU1977_REG_BLOCK_POWER_SAI,
power_off_mask, 0x00);
if (ret)
goto err_poweroff;
ret = adau1977_power_disable(adau1977);
if (ret)
return ret;
return snd_soc_register_codec(dev, &adau1977_codec_driver,
&adau1977_dai, 1);
err_poweroff:
adau1977_power_disable(adau1977);
return ret;
}
static bool adau1977_register_volatile(struct device *dev, unsigned int reg)
{
switch (reg) {
case ADAU1977_REG_STATUS(0):
case ADAU1977_REG_STATUS(1):
case ADAU1977_REG_STATUS(2):
case ADAU1977_REG_STATUS(3):
case ADAU1977_REG_ADC_CLIP:
return true;
}
return false;
}
