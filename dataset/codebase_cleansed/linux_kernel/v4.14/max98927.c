static int max98927_dai_set_fmt(struct snd_soc_dai *codec_dai, unsigned int fmt)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct max98927_priv *max98927 = snd_soc_codec_get_drvdata(codec);
unsigned int mode = 0;
unsigned int format = 0;
unsigned int invert = 0;
dev_dbg(codec->dev, "%s: fmt 0x%08X\n", __func__, fmt);
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBS_CFS:
mode = MAX98927_PCM_MASTER_MODE_SLAVE;
break;
case SND_SOC_DAIFMT_CBM_CFM:
max98927->master = true;
mode = MAX98927_PCM_MASTER_MODE_MASTER;
break;
default:
dev_err(codec->dev, "DAI clock mode unsupported\n");
return -EINVAL;
}
regmap_update_bits(max98927->regmap,
MAX98927_R0021_PCM_MASTER_MODE,
MAX98927_PCM_MASTER_MODE_MASK,
mode);
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
break;
case SND_SOC_DAIFMT_IB_NF:
invert = MAX98927_PCM_MODE_CFG_PCM_BCLKEDGE;
break;
default:
dev_err(codec->dev, "DAI invert mode unsupported\n");
return -EINVAL;
}
regmap_update_bits(max98927->regmap,
MAX98927_R0020_PCM_MODE_CFG,
MAX98927_PCM_MODE_CFG_PCM_BCLKEDGE,
invert);
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
max98927->iface |= SND_SOC_DAIFMT_I2S;
format = MAX98927_PCM_FORMAT_I2S;
break;
case SND_SOC_DAIFMT_LEFT_J:
max98927->iface |= SND_SOC_DAIFMT_LEFT_J;
format = MAX98927_PCM_FORMAT_LJ;
break;
case SND_SOC_DAIFMT_PDM:
max98927->iface |= SND_SOC_DAIFMT_PDM;
break;
default:
return -EINVAL;
}
if (max98927->iface & (SND_SOC_DAIFMT_I2S | SND_SOC_DAIFMT_LEFT_J)) {
regmap_update_bits(max98927->regmap,
MAX98927_R0018_PCM_RX_EN_A,
MAX98927_PCM_RX_CH0_EN | MAX98927_PCM_RX_CH1_EN,
MAX98927_PCM_RX_CH0_EN | MAX98927_PCM_RX_CH1_EN);
regmap_update_bits(max98927->regmap,
MAX98927_R0020_PCM_MODE_CFG,
MAX98927_PCM_MODE_CFG_FORMAT_MASK,
format << MAX98927_PCM_MODE_CFG_FORMAT_SHIFT);
regmap_update_bits(max98927->regmap,
MAX98927_R003B_SPK_SRC_SEL,
MAX98927_SPK_SRC_MASK, 0);
} else
regmap_update_bits(max98927->regmap,
MAX98927_R0018_PCM_RX_EN_A,
MAX98927_PCM_RX_CH0_EN | MAX98927_PCM_RX_CH1_EN, 0);
if (max98927->iface & SND_SOC_DAIFMT_PDM) {
regmap_update_bits(max98927->regmap,
MAX98927_R0035_PDM_RX_CTRL,
MAX98927_PDM_RX_EN_MASK, 1);
regmap_update_bits(max98927->regmap,
MAX98927_R003B_SPK_SRC_SEL,
MAX98927_SPK_SRC_MASK, 3);
} else
regmap_update_bits(max98927->regmap,
MAX98927_R0035_PDM_RX_CTRL,
MAX98927_PDM_RX_EN_MASK, 0);
return 0;
}
static int max98927_set_clock(struct max98927_priv *max98927,
struct snd_pcm_hw_params *params)
{
struct snd_soc_codec *codec = max98927->codec;
int blr_clk_ratio = params_channels(params) * max98927->ch_size;
int value;
if (max98927->master) {
int i;
for (i = 0; i < ARRAY_SIZE(rate_table); i++) {
if (rate_table[i] >= max98927->sysclk)
break;
}
if (i == ARRAY_SIZE(rate_table)) {
dev_err(codec->dev, "failed to find proper clock rate.\n");
return -EINVAL;
}
regmap_update_bits(max98927->regmap,
MAX98927_R0021_PCM_MASTER_MODE,
MAX98927_PCM_MASTER_MODE_MCLK_MASK,
i << MAX98927_PCM_MASTER_MODE_MCLK_RATE_SHIFT);
}
switch (blr_clk_ratio) {
case 32:
value = 2;
break;
case 48:
value = 3;
break;
case 64:
value = 4;
break;
default:
return -EINVAL;
}
regmap_update_bits(max98927->regmap,
MAX98927_R0022_PCM_CLK_SETUP,
MAX98927_PCM_CLK_SETUP_BSEL_MASK,
value);
return 0;
}
static int max98927_dai_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct max98927_priv *max98927 = snd_soc_codec_get_drvdata(codec);
unsigned int sampling_rate = 0;
unsigned int chan_sz = 0;
switch (snd_pcm_format_width(params_format(params))) {
case 16:
chan_sz = MAX98927_PCM_MODE_CFG_CHANSZ_16;
break;
case 24:
chan_sz = MAX98927_PCM_MODE_CFG_CHANSZ_24;
break;
case 32:
chan_sz = MAX98927_PCM_MODE_CFG_CHANSZ_32;
break;
default:
dev_err(codec->dev, "format unsupported %d\n",
params_format(params));
goto err;
}
max98927->ch_size = snd_pcm_format_width(params_format(params));
regmap_update_bits(max98927->regmap,
MAX98927_R0020_PCM_MODE_CFG,
MAX98927_PCM_MODE_CFG_CHANSZ_MASK, chan_sz);
dev_dbg(codec->dev, "format supported %d",
params_format(params));
switch (params_rate(params)) {
case 8000:
sampling_rate = MAX98927_PCM_SR_SET1_SR_8000;
break;
case 11025:
sampling_rate = MAX98927_PCM_SR_SET1_SR_11025;
break;
case 12000:
sampling_rate = MAX98927_PCM_SR_SET1_SR_12000;
break;
case 16000:
sampling_rate = MAX98927_PCM_SR_SET1_SR_16000;
break;
case 22050:
sampling_rate = MAX98927_PCM_SR_SET1_SR_22050;
break;
case 24000:
sampling_rate = MAX98927_PCM_SR_SET1_SR_24000;
break;
case 32000:
sampling_rate = MAX98927_PCM_SR_SET1_SR_32000;
break;
case 44100:
sampling_rate = MAX98927_PCM_SR_SET1_SR_44100;
break;
case 48000:
sampling_rate = MAX98927_PCM_SR_SET1_SR_48000;
break;
default:
dev_err(codec->dev, "rate %d not supported\n",
params_rate(params));
goto err;
}
regmap_update_bits(max98927->regmap,
MAX98927_R0023_PCM_SR_SETUP1,
MAX98927_PCM_SR_SET1_SR_MASK,
sampling_rate);
regmap_update_bits(max98927->regmap,
MAX98927_R0024_PCM_SR_SETUP2,
MAX98927_PCM_SR_SET2_SR_MASK,
sampling_rate << MAX98927_PCM_SR_SET2_SR_SHIFT);
if (max98927->interleave_mode &&
sampling_rate > MAX98927_PCM_SR_SET1_SR_16000)
regmap_update_bits(max98927->regmap,
MAX98927_R0024_PCM_SR_SETUP2,
MAX98927_PCM_SR_SET2_IVADC_SR_MASK,
sampling_rate - 3);
else
regmap_update_bits(max98927->regmap,
MAX98927_R0024_PCM_SR_SETUP2,
MAX98927_PCM_SR_SET2_IVADC_SR_MASK,
sampling_rate);
return max98927_set_clock(max98927, params);
err:
return -EINVAL;
}
static int max98927_dai_set_sysclk(struct snd_soc_dai *dai,
int clk_id, unsigned int freq, int dir)
{
struct snd_soc_codec *codec = dai->codec;
struct max98927_priv *max98927 = snd_soc_codec_get_drvdata(codec);
max98927->sysclk = freq;
return 0;
}
static int max98927_dac_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
struct max98927_priv *max98927 = snd_soc_codec_get_drvdata(codec);
switch (event) {
case SND_SOC_DAPM_POST_PMU:
regmap_update_bits(max98927->regmap,
MAX98927_R003A_AMP_EN,
MAX98927_AMP_EN_MASK, 1);
regmap_update_bits(max98927->regmap,
MAX98927_R00FF_GLOBAL_SHDN,
MAX98927_GLOBAL_EN_MASK, 1);
break;
case SND_SOC_DAPM_POST_PMD:
regmap_update_bits(max98927->regmap,
MAX98927_R00FF_GLOBAL_SHDN,
MAX98927_GLOBAL_EN_MASK, 0);
regmap_update_bits(max98927->regmap,
MAX98927_R003A_AMP_EN,
MAX98927_AMP_EN_MASK, 0);
break;
default:
return 0;
}
return 0;
}
static bool max98927_readable_register(struct device *dev, unsigned int reg)
{
switch (reg) {
case MAX98927_R0001_INT_RAW1 ... MAX98927_R0028_ICC_RX_EN_B:
case MAX98927_R002B_ICC_TX_EN_A ... MAX98927_R002C_ICC_TX_EN_B:
case MAX98927_R002E_ICC_HIZ_MANUAL_MODE
... MAX98927_R004E_MEAS_ADC_CH2_READ:
case MAX98927_R0051_BROWNOUT_STATUS
... MAX98927_R0055_BROWNOUT_LVL_HOLD:
case MAX98927_R005A_BROWNOUT_LVL1_THRESH
... MAX98927_R0061_BROWNOUT_AMP1_CLIP_MODE:
case MAX98927_R0072_BROWNOUT_LVL1_CUR_LIMIT
... MAX98927_R0087_ENV_TRACK_BOOST_VOUT_READ:
case MAX98927_R00FF_GLOBAL_SHDN:
case MAX98927_R0100_SOFT_RESET:
case MAX98927_R01FF_REV_ID:
return true;
default:
return false;
}
}
static bool max98927_volatile_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case MAX98927_R0001_INT_RAW1 ... MAX98927_R0009_INT_FLAG3:
case MAX98927_R004C_MEAS_ADC_CH0_READ:
case MAX98927_R004D_MEAS_ADC_CH1_READ:
case MAX98927_R004E_MEAS_ADC_CH2_READ:
case MAX98927_R0051_BROWNOUT_STATUS:
case MAX98927_R0087_ENV_TRACK_BOOST_VOUT_READ:
case MAX98927_R01FF_REV_ID:
case MAX98927_R0100_SOFT_RESET:
return true;
default:
return false;
}
}
static int max98927_probe(struct snd_soc_codec *codec)
{
struct max98927_priv *max98927 = snd_soc_codec_get_drvdata(codec);
max98927->codec = codec;
codec->control_data = max98927->regmap;
regmap_write(max98927->regmap,
MAX98927_R0100_SOFT_RESET, MAX98927_SOFT_RESET);
regmap_write(max98927->regmap,
MAX98927_R001C_PCM_TX_HIZ_CTRL_A,
0xFF);
regmap_write(max98927->regmap,
MAX98927_R001D_PCM_TX_HIZ_CTRL_B,
0xFF);
regmap_write(max98927->regmap,
MAX98927_R0025_PCM_TO_SPK_MONOMIX_A,
0x80);
regmap_write(max98927->regmap,
MAX98927_R0026_PCM_TO_SPK_MONOMIX_B,
0x1);
regmap_write(max98927->regmap,
MAX98927_R0036_AMP_VOL_CTRL,
0x38);
regmap_write(max98927->regmap,
MAX98927_R003C_SPK_GAIN,
0x05);
regmap_write(max98927->regmap,
MAX98927_R0037_AMP_DSP_CFG,
0x03);
regmap_write(max98927->regmap,
MAX98927_R003F_MEAS_DSP_CFG,
0xF7);
regmap_write(max98927->regmap,
MAX98927_R0040_BOOST_CTRL0,
0x1C);
regmap_write(max98927->regmap,
MAX98927_R0042_BOOST_CTRL1,
0x3E);
regmap_write(max98927->regmap,
MAX98927_R0043_MEAS_ADC_CFG,
0x04);
regmap_write(max98927->regmap,
MAX98927_R0044_MEAS_ADC_BASE_MSB,
0x00);
regmap_write(max98927->regmap,
MAX98927_R0045_MEAS_ADC_BASE_LSB,
0x24);
regmap_write(max98927->regmap,
MAX98927_R007F_BROWNOUT_LVL4_AMP1_CTRL1,
0x06);
regmap_write(max98927->regmap,
MAX98927_R0082_ENV_TRACK_VOUT_HEADROOM,
0x08);
regmap_write(max98927->regmap,
MAX98927_R0086_ENV_TRACK_CTRL,
0x01);
regmap_write(max98927->regmap,
MAX98927_R0087_ENV_TRACK_BOOST_VOUT_READ,
0x10);
regmap_write(max98927->regmap,
MAX98927_R001E_PCM_TX_CH_SRC_A,
(max98927->i_l_slot<<MAX98927_PCM_TX_CH_SRC_A_I_SHIFT|
max98927->v_l_slot)&0xFF);
if (max98927->v_l_slot < 8) {
regmap_update_bits(max98927->regmap,
MAX98927_R001C_PCM_TX_HIZ_CTRL_A,
1 << max98927->v_l_slot, 0);
regmap_update_bits(max98927->regmap,
MAX98927_R001A_PCM_TX_EN_A,
1 << max98927->v_l_slot,
1 << max98927->v_l_slot);
} else {
regmap_update_bits(max98927->regmap,
MAX98927_R001D_PCM_TX_HIZ_CTRL_B,
1 << (max98927->v_l_slot - 8), 0);
regmap_update_bits(max98927->regmap,
MAX98927_R001B_PCM_TX_EN_B,
1 << (max98927->v_l_slot - 8),
1 << (max98927->v_l_slot - 8));
}
if (max98927->i_l_slot < 8) {
regmap_update_bits(max98927->regmap,
MAX98927_R001C_PCM_TX_HIZ_CTRL_A,
1 << max98927->i_l_slot, 0);
regmap_update_bits(max98927->regmap,
MAX98927_R001A_PCM_TX_EN_A,
1 << max98927->i_l_slot,
1 << max98927->i_l_slot);
} else {
regmap_update_bits(max98927->regmap,
MAX98927_R001D_PCM_TX_HIZ_CTRL_B,
1 << (max98927->i_l_slot - 8), 0);
regmap_update_bits(max98927->regmap,
MAX98927_R001B_PCM_TX_EN_B,
1 << (max98927->i_l_slot - 8),
1 << (max98927->i_l_slot - 8));
}
if (max98927->interleave_mode)
regmap_update_bits(max98927->regmap,
MAX98927_R001F_PCM_TX_CH_SRC_B,
MAX98927_PCM_TX_CH_INTERLEAVE_MASK,
MAX98927_PCM_TX_CH_INTERLEAVE_MASK);
return 0;
}
static int max98927_suspend(struct device *dev)
{
struct max98927_priv *max98927 = dev_get_drvdata(dev);
regcache_cache_only(max98927->regmap, true);
regcache_mark_dirty(max98927->regmap);
return 0;
}
static int max98927_resume(struct device *dev)
{
struct max98927_priv *max98927 = dev_get_drvdata(dev);
regmap_write(max98927->regmap,
MAX98927_R0100_SOFT_RESET, MAX98927_SOFT_RESET);
regcache_cache_only(max98927->regmap, false);
regcache_sync(max98927->regmap);
return 0;
}
static void max98927_slot_config(struct i2c_client *i2c,
struct max98927_priv *max98927)
{
int value;
struct device *dev = &i2c->dev;
if (!device_property_read_u32(dev, "vmon-slot-no", &value))
max98927->v_l_slot = value & 0xF;
else
max98927->v_l_slot = 0;
if (!device_property_read_u32(dev, "imon-slot-no", &value))
max98927->i_l_slot = value & 0xF;
else
max98927->i_l_slot = 1;
}
static int max98927_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
int ret = 0, value;
int reg = 0;
struct max98927_priv *max98927 = NULL;
max98927 = devm_kzalloc(&i2c->dev,
sizeof(*max98927), GFP_KERNEL);
if (!max98927) {
ret = -ENOMEM;
return ret;
}
i2c_set_clientdata(i2c, max98927);
if (!of_property_read_u32(i2c->dev.of_node,
"interleave_mode", &value)) {
if (value > 0)
max98927->interleave_mode = 1;
else
max98927->interleave_mode = 0;
} else
max98927->interleave_mode = 0;
max98927->regmap
= devm_regmap_init_i2c(i2c, &max98927_regmap);
if (IS_ERR(max98927->regmap)) {
ret = PTR_ERR(max98927->regmap);
dev_err(&i2c->dev,
"Failed to allocate regmap: %d\n", ret);
return ret;
}
ret = regmap_read(max98927->regmap,
MAX98927_R01FF_REV_ID, &reg);
if (ret < 0) {
dev_err(&i2c->dev,
"Failed to read: 0x%02X\n", MAX98927_R01FF_REV_ID);
return ret;
}
dev_info(&i2c->dev, "MAX98927 revisionID: 0x%02X\n", reg);
max98927_slot_config(i2c, max98927);
ret = snd_soc_register_codec(&i2c->dev, &soc_codec_dev_max98927,
max98927_dai, ARRAY_SIZE(max98927_dai));
if (ret < 0)
dev_err(&i2c->dev, "Failed to register codec: %d\n", ret);
return ret;
}
static int max98927_i2c_remove(struct i2c_client *client)
{
snd_soc_unregister_codec(&client->dev);
return 0;
}
