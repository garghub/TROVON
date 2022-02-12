static bool cs53l30_volatile_register(struct device *dev, unsigned int reg)
{
if (reg == CS53L30_IS)
return true;
else
return false;
}
static bool cs53l30_writeable_register(struct device *dev, unsigned int reg)
{
switch (reg) {
case CS53L30_DEVID_AB:
case CS53L30_DEVID_CD:
case CS53L30_DEVID_E:
case CS53L30_REVID:
case CS53L30_IS:
return false;
default:
return true;
}
}
static bool cs53l30_readable_register(struct device *dev, unsigned int reg)
{
switch (reg) {
case CS53L30_DEVID_AB:
case CS53L30_DEVID_CD:
case CS53L30_DEVID_E:
case CS53L30_REVID:
case CS53L30_PWRCTL:
case CS53L30_MCLKCTL:
case CS53L30_INT_SR_CTL:
case CS53L30_MICBIAS_CTL:
case CS53L30_ASPCFG_CTL:
case CS53L30_ASP_CTL1:
case CS53L30_ASP_TDMTX_CTL1:
case CS53L30_ASP_TDMTX_CTL2:
case CS53L30_ASP_TDMTX_CTL3:
case CS53L30_ASP_TDMTX_CTL4:
case CS53L30_ASP_TDMTX_EN1:
case CS53L30_ASP_TDMTX_EN2:
case CS53L30_ASP_TDMTX_EN3:
case CS53L30_ASP_TDMTX_EN4:
case CS53L30_ASP_TDMTX_EN5:
case CS53L30_ASP_TDMTX_EN6:
case CS53L30_ASP_CTL2:
case CS53L30_SFT_RAMP:
case CS53L30_LRCK_CTL1:
case CS53L30_LRCK_CTL2:
case CS53L30_MUTEP_CTL1:
case CS53L30_MUTEP_CTL2:
case CS53L30_INBIAS_CTL1:
case CS53L30_INBIAS_CTL2:
case CS53L30_DMIC1_STR_CTL:
case CS53L30_DMIC2_STR_CTL:
case CS53L30_ADCDMIC1_CTL1:
case CS53L30_ADCDMIC1_CTL2:
case CS53L30_ADC1_CTL3:
case CS53L30_ADC1_NG_CTL:
case CS53L30_ADC1A_AFE_CTL:
case CS53L30_ADC1B_AFE_CTL:
case CS53L30_ADC1A_DIG_VOL:
case CS53L30_ADC1B_DIG_VOL:
case CS53L30_ADCDMIC2_CTL1:
case CS53L30_ADCDMIC2_CTL2:
case CS53L30_ADC2_CTL3:
case CS53L30_ADC2_NG_CTL:
case CS53L30_ADC2A_AFE_CTL:
case CS53L30_ADC2B_AFE_CTL:
case CS53L30_ADC2A_DIG_VOL:
case CS53L30_ADC2B_DIG_VOL:
case CS53L30_INT_MASK:
return true;
default:
return false;
}
}
static int cs53l30_get_mclkx_coeff(int mclkx)
{
int i;
for (i = 0; i < ARRAY_SIZE(cs53l30_mclkx_coeffs); i++) {
if (cs53l30_mclkx_coeffs[i].mclkx == mclkx)
return i;
}
return -EINVAL;
}
static int cs53l30_get_mclk_coeff(int mclk_rate, int srate)
{
int i;
for (i = 0; i < ARRAY_SIZE(cs53l30_mclk_coeffs); i++) {
if (cs53l30_mclk_coeffs[i].mclk_rate == mclk_rate &&
cs53l30_mclk_coeffs[i].srate == srate)
return i;
}
return -EINVAL;
}
static int cs53l30_set_sysclk(struct snd_soc_dai *dai,
int clk_id, unsigned int freq, int dir)
{
struct cs53l30_private *priv = snd_soc_codec_get_drvdata(dai->codec);
int mclkx_coeff;
u32 mclk_rate;
mclkx_coeff = cs53l30_get_mclkx_coeff(freq);
if (mclkx_coeff < 0)
return mclkx_coeff;
mclk_rate = cs53l30_mclkx_coeffs[mclkx_coeff].mclkx /
cs53l30_mclkx_coeffs[mclkx_coeff].ratio;
regmap_update_bits(priv->regmap, CS53L30_MCLKCTL,
CS53L30_MCLK_DIV_MASK,
cs53l30_mclkx_coeffs[mclkx_coeff].mclkdiv);
priv->mclk_rate = mclk_rate;
return 0;
}
static int cs53l30_set_dai_fmt(struct snd_soc_dai *dai, unsigned int fmt)
{
struct cs53l30_private *priv = snd_soc_codec_get_drvdata(dai->codec);
u8 aspcfg = 0, aspctl1 = 0;
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBM_CFM:
aspcfg |= CS53L30_ASP_MS;
break;
case SND_SOC_DAIFMT_CBS_CFS:
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
aspctl1 |= CS53L30_ASP_TDM_PDN;
break;
case SND_SOC_DAIFMT_DSP_A:
aspctl1 |= CS53L30_SHIFT_LEFT;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_IB_NF:
case SND_SOC_DAIFMT_IB_IF:
aspcfg ^= CS53L30_ASP_SCLK_INV;
break;
default:
break;
}
regmap_update_bits(priv->regmap, CS53L30_ASPCFG_CTL,
CS53L30_ASP_MS | CS53L30_ASP_SCLK_INV, aspcfg);
regmap_update_bits(priv->regmap, CS53L30_ASP_CTL1,
CS53L30_ASP_TDM_PDN | CS53L30_SHIFT_LEFT, aspctl1);
return 0;
}
static int cs53l30_pcm_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct cs53l30_private *priv = snd_soc_codec_get_drvdata(dai->codec);
int srate = params_rate(params);
int mclk_coeff;
mclk_coeff = cs53l30_get_mclk_coeff(priv->mclk_rate, srate);
if (mclk_coeff < 0)
return -EINVAL;
regmap_update_bits(priv->regmap, CS53L30_INT_SR_CTL,
CS53L30_INTRNL_FS_RATIO_MASK,
cs53l30_mclk_coeffs[mclk_coeff].internal_fs_ratio);
regmap_update_bits(priv->regmap, CS53L30_MCLKCTL,
CS53L30_MCLK_INT_SCALE_MASK,
cs53l30_mclk_coeffs[mclk_coeff].mclk_int_scale);
regmap_update_bits(priv->regmap, CS53L30_ASPCFG_CTL,
CS53L30_ASP_RATE_MASK,
cs53l30_mclk_coeffs[mclk_coeff].asp_rate);
return 0;
}
static int cs53l30_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
struct snd_soc_dapm_context *dapm = snd_soc_codec_get_dapm(codec);
struct cs53l30_private *priv = snd_soc_codec_get_drvdata(codec);
unsigned int reg;
int i, inter_max_check, ret;
switch (level) {
case SND_SOC_BIAS_ON:
break;
case SND_SOC_BIAS_PREPARE:
if (dapm->bias_level == SND_SOC_BIAS_STANDBY)
regmap_update_bits(priv->regmap, CS53L30_PWRCTL,
CS53L30_PDN_LP_MASK, 0);
break;
case SND_SOC_BIAS_STANDBY:
if (dapm->bias_level == SND_SOC_BIAS_OFF) {
ret = clk_prepare_enable(priv->mclk);
if (ret) {
dev_err(codec->dev,
"failed to enable MCLK: %d\n", ret);
return ret;
}
regmap_update_bits(priv->regmap, CS53L30_MCLKCTL,
CS53L30_MCLK_DIS_MASK, 0);
regmap_update_bits(priv->regmap, CS53L30_PWRCTL,
CS53L30_PDN_ULP_MASK, 0);
msleep(50);
} else {
regmap_update_bits(priv->regmap, CS53L30_PWRCTL,
CS53L30_PDN_ULP_MASK,
CS53L30_PDN_ULP);
}
break;
case SND_SOC_BIAS_OFF:
regmap_update_bits(priv->regmap, CS53L30_INT_MASK,
CS53L30_PDN_DONE, 0);
regmap_read(priv->regmap, CS53L30_SFT_RAMP, &reg);
if (reg & CS53L30_DIGSFT_MASK)
inter_max_check = CS53L30_PDN_POLL_MAX;
else
inter_max_check = 10;
regmap_update_bits(priv->regmap, CS53L30_PWRCTL,
CS53L30_PDN_ULP_MASK,
CS53L30_PDN_ULP);
msleep(20);
regmap_read(priv->regmap, CS53L30_IS, &reg);
for (i = 0; i < inter_max_check; i++) {
if (inter_max_check < 10) {
usleep_range(1000, 1100);
regmap_read(priv->regmap, CS53L30_IS, &reg);
if (reg & CS53L30_PDN_DONE)
break;
} else {
usleep_range(10000, 10100);
regmap_read(priv->regmap, CS53L30_IS, &reg);
if (reg & CS53L30_PDN_DONE)
break;
}
}
regmap_update_bits(priv->regmap, CS53L30_INT_MASK,
CS53L30_PDN_DONE, CS53L30_PDN_DONE);
regmap_update_bits(priv->regmap, CS53L30_MCLKCTL,
CS53L30_MCLK_DIS_MASK,
CS53L30_MCLK_DIS);
clk_disable_unprepare(priv->mclk);
break;
}
return 0;
}
static int cs53l30_set_tristate(struct snd_soc_dai *dai, int tristate)
{
struct cs53l30_private *priv = snd_soc_codec_get_drvdata(dai->codec);
u8 val = tristate ? CS53L30_ASP_3ST : 0;
return regmap_update_bits(priv->regmap, CS53L30_ASP_CTL1,
CS53L30_ASP_3ST_MASK, val);
}
static int cs53l30_pcm_startup(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
snd_pcm_hw_constraint_list(substream->runtime, 0,
SNDRV_PCM_HW_PARAM_RATE, &src_constraints);
return 0;
}
static int cs53l30_set_dai_tdm_slot(struct snd_soc_dai *dai,
unsigned int tx_mask, unsigned int rx_mask,
int slots, int slot_width)
{
struct cs53l30_private *priv = snd_soc_codec_get_drvdata(dai->codec);
unsigned int loc[CS53L30_TDM_SLOT_MAX] = {48, 48, 48, 48};
unsigned int slot_next, slot_step;
u64 tx_enable = 0;
int i;
if (!rx_mask) {
dev_err(dai->dev, "rx masks must not be 0\n");
return -EINVAL;
}
if (slots <= 0 || slot_width <= 0 || slot_width > 64) {
dev_err(dai->dev, "invalid slot number or slot width\n");
return -EINVAL;
}
if (slot_width & 0x7) {
dev_err(dai->dev, "slot width must count in byte\n");
return -EINVAL;
}
slot_step = slot_width >> 3;
for (i = 0; rx_mask && i < CS53L30_TDM_SLOT_MAX; i++) {
slot_next = __ffs(rx_mask);
loc[i] = slot_next * slot_step;
tx_enable |= (u64)((u64)(1 << slot_step) - 1) << (u64)loc[i];
rx_mask &= ~(1 << slot_next);
}
if (rx_mask && i == CS53L30_TDM_SLOT_MAX) {
dev_err(dai->dev, "rx_mask exceeds max slot number: %d\n",
CS53L30_TDM_SLOT_MAX);
return -EINVAL;
}
slot_next = loc[i - 1] + slot_step - 1;
if (slot_next > 47) {
dev_err(dai->dev, "slot selection out of bounds: %u\n",
slot_next);
return -EINVAL;
}
for (i = 0; i < CS53L30_TDM_SLOT_MAX && loc[i] != 48; i++) {
regmap_update_bits(priv->regmap, CS53L30_ASP_TDMTX_CTL(i),
CS53L30_ASP_CHx_TX_LOC_MASK, loc[i]);
dev_dbg(dai->dev, "loc[%d]=%x\n", i, loc[i]);
}
for (i = 0; i < CS53L30_ASP_TDMTX_ENx_MAX && tx_enable; i++) {
regmap_write(priv->regmap, CS53L30_ASP_TDMTX_ENx(i),
tx_enable & 0xff);
tx_enable >>= 8;
dev_dbg(dai->dev, "en_reg=%x, tx_enable=%llx\n",
CS53L30_ASP_TDMTX_ENx(i), tx_enable & 0xff);
}
return 0;
}
static int cs53l30_mute_stream(struct snd_soc_dai *dai, int mute, int stream)
{
struct cs53l30_private *priv = snd_soc_codec_get_drvdata(dai->codec);
if (priv->mute_gpio)
gpiod_set_value_cansleep(priv->mute_gpio, mute);
return 0;
}
static int cs53l30_codec_probe(struct snd_soc_codec *codec)
{
struct cs53l30_private *priv = snd_soc_codec_get_drvdata(codec);
struct snd_soc_dapm_context *dapm = snd_soc_codec_get_dapm(codec);
if (priv->use_sdout2)
snd_soc_dapm_add_routes(dapm, cs53l30_dapm_routes_sdout2,
ARRAY_SIZE(cs53l30_dapm_routes_sdout2));
else
snd_soc_dapm_add_routes(dapm, cs53l30_dapm_routes_sdout1,
ARRAY_SIZE(cs53l30_dapm_routes_sdout1));
return 0;
}
static int cs53l30_i2c_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
const struct device_node *np = client->dev.of_node;
struct device *dev = &client->dev;
struct cs53l30_private *cs53l30;
unsigned int devid = 0;
unsigned int reg;
int ret = 0, i;
u8 val;
cs53l30 = devm_kzalloc(dev, sizeof(*cs53l30), GFP_KERNEL);
if (!cs53l30)
return -ENOMEM;
for (i = 0; i < ARRAY_SIZE(cs53l30->supplies); i++)
cs53l30->supplies[i].supply = cs53l30_supply_names[i];
ret = devm_regulator_bulk_get(dev, ARRAY_SIZE(cs53l30->supplies),
cs53l30->supplies);
if (ret) {
dev_err(dev, "failed to get supplies: %d\n", ret);
return ret;
}
ret = regulator_bulk_enable(ARRAY_SIZE(cs53l30->supplies),
cs53l30->supplies);
if (ret) {
dev_err(dev, "failed to enable supplies: %d\n", ret);
return ret;
}
cs53l30->reset_gpio = devm_gpiod_get_optional(dev, "reset",
GPIOD_OUT_LOW);
if (IS_ERR(cs53l30->reset_gpio)) {
ret = PTR_ERR(cs53l30->reset_gpio);
goto error;
}
if (cs53l30->reset_gpio)
gpiod_set_value_cansleep(cs53l30->reset_gpio, 1);
i2c_set_clientdata(client, cs53l30);
cs53l30->mclk_rate = 0;
cs53l30->regmap = devm_regmap_init_i2c(client, &cs53l30_regmap);
if (IS_ERR(cs53l30->regmap)) {
ret = PTR_ERR(cs53l30->regmap);
dev_err(dev, "regmap_init() failed: %d\n", ret);
goto error;
}
ret = regmap_read(cs53l30->regmap, CS53L30_DEVID_AB, &reg);
devid = reg << 12;
ret = regmap_read(cs53l30->regmap, CS53L30_DEVID_CD, &reg);
devid |= reg << 4;
ret = regmap_read(cs53l30->regmap, CS53L30_DEVID_E, &reg);
devid |= (reg & 0xF0) >> 4;
if (devid != CS53L30_DEVID) {
ret = -ENODEV;
dev_err(dev, "Device ID (%X). Expected %X\n",
devid, CS53L30_DEVID);
goto error;
}
ret = regmap_read(cs53l30->regmap, CS53L30_REVID, &reg);
if (ret < 0) {
dev_err(dev, "failed to get Revision ID: %d\n", ret);
goto error;
}
cs53l30->mclk = devm_clk_get(dev, "mclk");
if (IS_ERR(cs53l30->mclk)) {
if (PTR_ERR(cs53l30->mclk) == -EPROBE_DEFER) {
ret = -EPROBE_DEFER;
goto error;
}
cs53l30->mclk = NULL;
}
cs53l30->mute_gpio = devm_gpiod_get_optional(dev, "mute",
GPIOD_OUT_HIGH);
if (IS_ERR(cs53l30->mute_gpio)) {
ret = PTR_ERR(cs53l30->mute_gpio);
goto error;
}
if (cs53l30->mute_gpio) {
regmap_write(cs53l30->regmap, CS53L30_MUTEP_CTL1,
CS53L30_MUTEP_CTL1_MUTEALL);
if (gpiod_is_active_low(cs53l30->mute_gpio))
regmap_update_bits(cs53l30->regmap, CS53L30_MUTEP_CTL2,
CS53L30_MUTE_PIN_POLARITY, 0);
}
if (!of_property_read_u8(np, "cirrus,micbias-lvl", &val))
regmap_update_bits(cs53l30->regmap, CS53L30_MICBIAS_CTL,
CS53L30_MIC_BIAS_CTRL_MASK, val);
if (of_property_read_bool(np, "cirrus,use-sdout2"))
cs53l30->use_sdout2 = true;
dev_info(dev, "Cirrus Logic CS53L30, Revision: %02X\n", reg & 0xFF);
ret = snd_soc_register_codec(dev, &cs53l30_driver, &cs53l30_dai, 1);
if (ret) {
dev_err(dev, "failed to register codec: %d\n", ret);
goto error;
}
return 0;
error:
regulator_bulk_disable(ARRAY_SIZE(cs53l30->supplies),
cs53l30->supplies);
return ret;
}
static int cs53l30_i2c_remove(struct i2c_client *client)
{
struct cs53l30_private *cs53l30 = i2c_get_clientdata(client);
snd_soc_unregister_codec(&client->dev);
if (cs53l30->reset_gpio)
gpiod_set_value_cansleep(cs53l30->reset_gpio, 0);
regulator_bulk_disable(ARRAY_SIZE(cs53l30->supplies),
cs53l30->supplies);
return 0;
}
static int cs53l30_runtime_suspend(struct device *dev)
{
struct cs53l30_private *cs53l30 = dev_get_drvdata(dev);
regcache_cache_only(cs53l30->regmap, true);
if (cs53l30->reset_gpio)
gpiod_set_value_cansleep(cs53l30->reset_gpio, 0);
regulator_bulk_disable(ARRAY_SIZE(cs53l30->supplies),
cs53l30->supplies);
return 0;
}
static int cs53l30_runtime_resume(struct device *dev)
{
struct cs53l30_private *cs53l30 = dev_get_drvdata(dev);
int ret;
ret = regulator_bulk_enable(ARRAY_SIZE(cs53l30->supplies),
cs53l30->supplies);
if (ret) {
dev_err(dev, "failed to enable supplies: %d\n", ret);
return ret;
}
if (cs53l30->reset_gpio)
gpiod_set_value_cansleep(cs53l30->reset_gpio, 1);
regcache_cache_only(cs53l30->regmap, false);
ret = regcache_sync(cs53l30->regmap);
if (ret) {
dev_err(dev, "failed to synchronize regcache: %d\n", ret);
return ret;
}
return 0;
}
