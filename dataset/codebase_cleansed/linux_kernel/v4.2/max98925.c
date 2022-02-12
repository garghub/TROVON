static int max98925_dac_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_kcontrol_codec(kcontrol);
struct max98925_priv *max98925 = snd_soc_codec_get_drvdata(codec);
switch (event) {
case SND_SOC_DAPM_PRE_PMU:
regmap_update_bits(max98925->regmap,
MAX98925_BLOCK_ENABLE,
M98925_BST_EN_MASK |
M98925_ADC_IMON_EN_MASK | M98925_ADC_VMON_EN_MASK,
M98925_BST_EN_MASK |
M98925_ADC_IMON_EN_MASK | M98925_ADC_VMON_EN_MASK);
break;
case SND_SOC_DAPM_POST_PMD:
regmap_update_bits(max98925->regmap,
MAX98925_BLOCK_ENABLE, M98925_BST_EN_MASK |
M98925_ADC_IMON_EN_MASK | M98925_ADC_VMON_EN_MASK, 0);
break;
default:
return 0;
}
return 0;
}
static bool max98925_volatile_register(struct device *dev, unsigned int reg)
{
switch (reg) {
case MAX98925_VBAT_DATA:
case MAX98925_VBST_DATA:
case MAX98925_LIVE_STATUS0:
case MAX98925_LIVE_STATUS1:
case MAX98925_LIVE_STATUS2:
case MAX98925_STATE0:
case MAX98925_STATE1:
case MAX98925_STATE2:
case MAX98925_FLAG0:
case MAX98925_FLAG1:
case MAX98925_FLAG2:
case MAX98925_REV_VERSION:
return true;
default:
return false;
}
}
static bool max98925_readable_register(struct device *dev, unsigned int reg)
{
switch (reg) {
case MAX98925_IRQ_CLEAR0:
case MAX98925_IRQ_CLEAR1:
case MAX98925_IRQ_CLEAR2:
case MAX98925_ALC_HOLD_RLS:
return false;
default:
return true;
}
}
static inline int max98925_rate_value(struct snd_soc_codec *codec,
int rate, int clock, int *value, int *n, int *m)
{
int ret = -EINVAL;
int i;
for (i = 0; i < ARRAY_SIZE(rate_table); i++) {
if (rate_table[i].rate >= rate) {
*value = rate_table[i].sr;
*n = rate_table[i].divisors[clock][0];
*m = rate_table[i].divisors[clock][1];
ret = 0;
break;
}
}
dev_dbg(codec->dev, "%s: sample rate is %d, returning %d\n",
__func__, rate_table[i].rate, *value);
return ret;
}
static void max98925_set_sense_data(struct max98925_priv *max98925)
{
regmap_update_bits(max98925->regmap,
MAX98925_DOUT_CFG_VMON,
M98925_DAI_VMON_EN_MASK, M98925_DAI_VMON_EN_MASK);
regmap_update_bits(max98925->regmap,
MAX98925_DOUT_CFG_VMON,
M98925_DAI_VMON_SLOT_MASK,
max98925->v_slot << M98925_DAI_VMON_SLOT_SHIFT);
regmap_update_bits(max98925->regmap,
MAX98925_DOUT_CFG_IMON,
M98925_DAI_IMON_EN_MASK, M98925_DAI_IMON_EN_MASK);
regmap_update_bits(max98925->regmap,
MAX98925_DOUT_CFG_IMON,
M98925_DAI_IMON_SLOT_MASK,
max98925->i_slot << M98925_DAI_IMON_SLOT_SHIFT);
}
static int max98925_dai_set_fmt(struct snd_soc_dai *codec_dai,
unsigned int fmt)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct max98925_priv *max98925 = snd_soc_codec_get_drvdata(codec);
unsigned int invert = 0;
dev_dbg(codec->dev, "%s: fmt 0x%08X\n", __func__, fmt);
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBS_CFS:
regmap_update_bits(max98925->regmap,
MAX98925_DAI_CLK_MODE2,
M98925_DAI_MAS_MASK, 0);
max98925_set_sense_data(max98925);
break;
case SND_SOC_DAIFMT_CBM_CFM:
regmap_update_bits(max98925->regmap,
MAX98925_DAI_CLK_MODE2,
M98925_DAI_MAS_MASK, M98925_DAI_MAS_MASK);
break;
case SND_SOC_DAIFMT_CBS_CFM:
case SND_SOC_DAIFMT_CBM_CFS:
default:
dev_err(codec->dev, "DAI clock mode unsupported");
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
break;
case SND_SOC_DAIFMT_NB_IF:
invert = M98925_DAI_WCI_MASK;
break;
case SND_SOC_DAIFMT_IB_NF:
invert = M98925_DAI_BCI_MASK;
break;
case SND_SOC_DAIFMT_IB_IF:
invert = M98925_DAI_BCI_MASK | M98925_DAI_WCI_MASK;
break;
default:
dev_err(codec->dev, "DAI invert mode unsupported");
return -EINVAL;
}
regmap_update_bits(max98925->regmap, MAX98925_FORMAT,
M98925_DAI_BCI_MASK | M98925_DAI_WCI_MASK, invert);
return 0;
}
static int max98925_set_clock(struct max98925_priv *max98925,
struct snd_pcm_hw_params *params)
{
unsigned int dai_sr = 0, clock, mdll, n, m;
struct snd_soc_codec *codec = max98925->codec;
int rate = params_rate(params);
int blr_clk_ratio = params_channels(params) * max98925->ch_size;
switch (blr_clk_ratio) {
case 32:
regmap_update_bits(max98925->regmap,
MAX98925_DAI_CLK_MODE2,
M98925_DAI_BSEL_MASK, M98925_DAI_BSEL_32);
break;
case 48:
regmap_update_bits(max98925->regmap,
MAX98925_DAI_CLK_MODE2,
M98925_DAI_BSEL_MASK, M98925_DAI_BSEL_48);
break;
case 64:
regmap_update_bits(max98925->regmap,
MAX98925_DAI_CLK_MODE2,
M98925_DAI_BSEL_MASK, M98925_DAI_BSEL_64);
break;
default:
return -EINVAL;
}
switch (max98925->sysclk) {
case 6000000:
clock = 0;
mdll = M98925_MDLL_MULT_MCLKx16;
break;
case 11289600:
clock = 1;
mdll = M98925_MDLL_MULT_MCLKx8;
break;
case 12000000:
clock = 0;
mdll = M98925_MDLL_MULT_MCLKx8;
break;
case 12288000:
clock = 2;
mdll = M98925_MDLL_MULT_MCLKx8;
break;
default:
dev_info(max98925->codec->dev, "unsupported sysclk %d\n",
max98925->sysclk);
return -EINVAL;
}
if (max98925_rate_value(codec, rate, clock, &dai_sr, &n, &m))
return -EINVAL;
regmap_update_bits(max98925->regmap,
MAX98925_DAI_CLK_MODE2,
M98925_DAI_SR_MASK, dai_sr << M98925_DAI_SR_SHIFT);
regmap_write(max98925->regmap,
MAX98925_DAI_CLK_DIV_M_MSBS, m >> 8);
regmap_write(max98925->regmap,
MAX98925_DAI_CLK_DIV_M_LSBS, m & 0xFF);
regmap_write(max98925->regmap,
MAX98925_DAI_CLK_DIV_N_MSBS, n >> 8);
regmap_write(max98925->regmap,
MAX98925_DAI_CLK_DIV_N_LSBS, n & 0xFF);
regmap_update_bits(max98925->regmap, MAX98925_DAI_CLK_MODE1,
M98925_MDLL_MULT_MASK, mdll << M98925_MDLL_MULT_SHIFT);
return 0;
}
static int max98925_dai_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct max98925_priv *max98925 = snd_soc_codec_get_drvdata(codec);
switch (snd_pcm_format_width(params_format(params))) {
case 16:
regmap_update_bits(max98925->regmap,
MAX98925_FORMAT,
M98925_DAI_CHANSZ_MASK, M98925_DAI_CHANSZ_16);
max98925->ch_size = 16;
break;
case 24:
regmap_update_bits(max98925->regmap,
MAX98925_FORMAT,
M98925_DAI_CHANSZ_MASK, M98925_DAI_CHANSZ_24);
max98925->ch_size = 24;
break;
case 32:
regmap_update_bits(max98925->regmap,
MAX98925_FORMAT,
M98925_DAI_CHANSZ_MASK, M98925_DAI_CHANSZ_32);
max98925->ch_size = 32;
break;
default:
pr_err("%s: format unsupported %d",
__func__, params_format(params));
return -EINVAL;
}
dev_dbg(codec->dev, "%s: format supported %d",
__func__, params_format(params));
return max98925_set_clock(max98925, params);
}
static int max98925_dai_set_sysclk(struct snd_soc_dai *dai,
int clk_id, unsigned int freq, int dir)
{
struct snd_soc_codec *codec = dai->codec;
struct max98925_priv *max98925 = snd_soc_codec_get_drvdata(codec);
switch (clk_id) {
case 0:
regmap_update_bits(max98925->regmap,
MAX98925_DAI_CLK_MODE1,
M98925_DAI_CLK_SOURCE_MASK, 0);
break;
case 1:
regmap_update_bits(max98925->regmap,
MAX98925_DAI_CLK_MODE1,
M98925_DAI_CLK_SOURCE_MASK,
M98925_DAI_CLK_SOURCE_MASK);
break;
default:
return -EINVAL;
}
max98925->sysclk = freq;
return 0;
}
static int max98925_probe(struct snd_soc_codec *codec)
{
struct max98925_priv *max98925 = snd_soc_codec_get_drvdata(codec);
max98925->codec = codec;
codec->control_data = max98925->regmap;
regmap_write(max98925->regmap, MAX98925_GLOBAL_ENABLE, 0x00);
regmap_write(max98925->regmap,
MAX98925_FORMAT, M98925_DAI_DLY_MASK);
regmap_write(max98925->regmap, MAX98925_TDM_SLOT_SELECT, 0xC8);
regmap_write(max98925->regmap, MAX98925_DOUT_HIZ_CFG1, 0xFF);
regmap_write(max98925->regmap, MAX98925_DOUT_HIZ_CFG2, 0xFF);
regmap_write(max98925->regmap, MAX98925_DOUT_HIZ_CFG3, 0xFF);
regmap_write(max98925->regmap, MAX98925_DOUT_HIZ_CFG4, 0xF0);
regmap_write(max98925->regmap, MAX98925_FILTERS, 0xD8);
regmap_write(max98925->regmap, MAX98925_ALC_CONFIGURATION, 0xF8);
regmap_write(max98925->regmap, MAX98925_CONFIGURATION, 0xF0);
regmap_write(max98925->regmap, MAX98925_BOOST_LIMITER, 0xF8);
return 0;
}
static int max98925_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
int ret, reg;
u32 value;
struct max98925_priv *max98925;
max98925 = devm_kzalloc(&i2c->dev,
sizeof(*max98925), GFP_KERNEL);
if (!max98925)
return -ENOMEM;
i2c_set_clientdata(i2c, max98925);
max98925->regmap = devm_regmap_init_i2c(i2c, &max98925_regmap);
if (IS_ERR(max98925->regmap)) {
ret = PTR_ERR(max98925->regmap);
dev_err(&i2c->dev,
"Failed to allocate regmap: %d\n", ret);
goto err_out;
}
if (!of_property_read_u32(i2c->dev.of_node, "vmon-slot-no", &value)) {
if (value > M98925_DAI_VMON_SLOT_1E_1F) {
dev_err(&i2c->dev, "vmon slot number is wrong:\n");
return -EINVAL;
}
max98925->v_slot = value;
}
if (!of_property_read_u32(i2c->dev.of_node, "imon-slot-no", &value)) {
if (value > M98925_DAI_IMON_SLOT_1E_1F) {
dev_err(&i2c->dev, "imon slot number is wrong:\n");
return -EINVAL;
}
max98925->i_slot = value;
}
ret = regmap_read(max98925->regmap,
MAX98925_REV_VERSION, &reg);
if ((ret < 0) ||
((reg != MAX98925_VERSION) &&
(reg != MAX98925_VERSION1))) {
dev_err(&i2c->dev,
"device initialization error (%d 0x%02X)\n",
ret, reg);
goto err_out;
}
dev_info(&i2c->dev, "device version 0x%02X\n", reg);
ret = snd_soc_register_codec(&i2c->dev, &soc_codec_dev_max98925,
max98925_dai, ARRAY_SIZE(max98925_dai));
if (ret < 0)
dev_err(&i2c->dev,
"Failed to register codec: %d\n", ret);
err_out:
return ret;
}
static int max98925_i2c_remove(struct i2c_client *client)
{
snd_soc_unregister_codec(&client->dev);
return 0;
}
