static bool cs35l33_volatile_register(struct device *dev, unsigned int reg)
{
switch (reg) {
case CS35L33_DEVID_AB:
case CS35L33_DEVID_CD:
case CS35L33_DEVID_E:
case CS35L33_REV_ID:
case CS35L33_INT_STATUS_1:
case CS35L33_INT_STATUS_2:
case CS35L33_HG_STATUS:
return true;
default:
return false;
}
}
static bool cs35l33_writeable_register(struct device *dev, unsigned int reg)
{
switch (reg) {
case CS35L33_DEVID_AB:
case CS35L33_DEVID_CD:
case CS35L33_DEVID_E:
case CS35L33_REV_ID:
case CS35L33_INT_STATUS_1:
case CS35L33_INT_STATUS_2:
case CS35L33_HG_STATUS:
return false;
default:
return true;
}
}
static bool cs35l33_readable_register(struct device *dev, unsigned int reg)
{
switch (reg) {
case CS35L33_DEVID_AB:
case CS35L33_DEVID_CD:
case CS35L33_DEVID_E:
case CS35L33_REV_ID:
case CS35L33_PWRCTL1:
case CS35L33_PWRCTL2:
case CS35L33_CLK_CTL:
case CS35L33_BST_PEAK_CTL:
case CS35L33_PROTECT_CTL:
case CS35L33_BST_CTL1:
case CS35L33_BST_CTL2:
case CS35L33_ADSP_CTL:
case CS35L33_ADC_CTL:
case CS35L33_DAC_CTL:
case CS35L33_DIG_VOL_CTL:
case CS35L33_CLASSD_CTL:
case CS35L33_AMP_CTL:
case CS35L33_INT_MASK_1:
case CS35L33_INT_MASK_2:
case CS35L33_INT_STATUS_1:
case CS35L33_INT_STATUS_2:
case CS35L33_DIAG_LOCK:
case CS35L33_DIAG_CTRL_1:
case CS35L33_DIAG_CTRL_2:
case CS35L33_HG_MEMLDO_CTL:
case CS35L33_HG_REL_RATE:
case CS35L33_LDO_DEL:
case CS35L33_HG_HEAD:
case CS35L33_HG_EN:
case CS35L33_TX_VMON:
case CS35L33_TX_IMON:
case CS35L33_TX_VPMON:
case CS35L33_TX_VBSTMON:
case CS35L33_TX_FLAG:
case CS35L33_TX_EN1:
case CS35L33_TX_EN2:
case CS35L33_TX_EN3:
case CS35L33_TX_EN4:
case CS35L33_RX_AUD:
case CS35L33_RX_SPLY:
case CS35L33_RX_ALIVE:
case CS35L33_BST_CTL4:
return true;
default:
return false;
}
}
static int cs35l33_spkrdrv_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
struct cs35l33_private *priv = snd_soc_codec_get_drvdata(codec);
switch (event) {
case SND_SOC_DAPM_POST_PMU:
if (!priv->amp_cal) {
usleep_range(8000, 9000);
priv->amp_cal = true;
regmap_update_bits(priv->regmap, CS35L33_CLASSD_CTL,
CS35L33_AMP_CAL, 0);
dev_dbg(codec->dev, "Amp calibration done\n");
}
dev_dbg(codec->dev, "Amp turned on\n");
break;
case SND_SOC_DAPM_POST_PMD:
dev_dbg(codec->dev, "Amp turned off\n");
break;
default:
dev_err(codec->dev, "Invalid event = 0x%x\n", event);
break;
}
return 0;
}
static int cs35l33_sdin_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
struct cs35l33_private *priv = snd_soc_codec_get_drvdata(codec);
unsigned int val;
switch (event) {
case SND_SOC_DAPM_PRE_PMU:
regmap_update_bits(priv->regmap, CS35L33_PWRCTL1,
CS35L33_PDN_BST, 0);
val = priv->is_tdm_mode ? 0 : CS35L33_PDN_TDM;
regmap_update_bits(priv->regmap, CS35L33_PWRCTL2,
CS35L33_PDN_TDM, val);
dev_dbg(codec->dev, "BST turned on\n");
break;
case SND_SOC_DAPM_POST_PMU:
dev_dbg(codec->dev, "SDIN turned on\n");
if (!priv->amp_cal) {
regmap_update_bits(priv->regmap, CS35L33_CLASSD_CTL,
CS35L33_AMP_CAL, CS35L33_AMP_CAL);
dev_dbg(codec->dev, "Amp calibration started\n");
usleep_range(10000, 11000);
}
break;
case SND_SOC_DAPM_POST_PMD:
regmap_update_bits(priv->regmap, CS35L33_PWRCTL2,
CS35L33_PDN_TDM, CS35L33_PDN_TDM);
usleep_range(4000, 4100);
regmap_update_bits(priv->regmap, CS35L33_PWRCTL1,
CS35L33_PDN_BST, CS35L33_PDN_BST);
dev_dbg(codec->dev, "BST and SDIN turned off\n");
break;
default:
dev_err(codec->dev, "Invalid event = 0x%x\n", event);
}
return 0;
}
static int cs35l33_sdout_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
struct cs35l33_private *priv = snd_soc_codec_get_drvdata(codec);
unsigned int mask = CS35L33_SDOUT_3ST_I2S | CS35L33_PDN_TDM;
unsigned int mask2 = CS35L33_SDOUT_3ST_TDM;
unsigned int val, val2;
switch (event) {
case SND_SOC_DAPM_PRE_PMU:
if (priv->is_tdm_mode) {
val = CS35L33_SDOUT_3ST_I2S;
val2 = 0;
} else {
val = CS35L33_PDN_TDM;
val2 = CS35L33_SDOUT_3ST_TDM;
}
dev_dbg(codec->dev, "SDOUT turned on\n");
break;
case SND_SOC_DAPM_PRE_PMD:
val = CS35L33_SDOUT_3ST_I2S | CS35L33_PDN_TDM;
val2 = CS35L33_SDOUT_3ST_TDM;
dev_dbg(codec->dev, "SDOUT turned off\n");
break;
default:
dev_err(codec->dev, "Invalid event = 0x%x\n", event);
return 0;
}
regmap_update_bits(priv->regmap, CS35L33_PWRCTL2,
mask, val);
regmap_update_bits(priv->regmap, CS35L33_CLK_CTL,
mask2, val2);
return 0;
}
static int cs35l33_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
unsigned int val;
struct cs35l33_private *priv = snd_soc_codec_get_drvdata(codec);
switch (level) {
case SND_SOC_BIAS_ON:
break;
case SND_SOC_BIAS_PREPARE:
regmap_update_bits(priv->regmap, CS35L33_PWRCTL1,
CS35L33_PDN_ALL, 0);
regmap_update_bits(priv->regmap, CS35L33_CLK_CTL,
CS35L33_MCLKDIS, 0);
break;
case SND_SOC_BIAS_STANDBY:
regmap_update_bits(priv->regmap, CS35L33_PWRCTL1,
CS35L33_PDN_ALL, CS35L33_PDN_ALL);
regmap_read(priv->regmap, CS35L33_INT_STATUS_2, &val);
usleep_range(1000, 1100);
if (val & CS35L33_PDN_DONE)
regmap_update_bits(priv->regmap, CS35L33_CLK_CTL,
CS35L33_MCLKDIS, CS35L33_MCLKDIS);
break;
case SND_SOC_BIAS_OFF:
break;
default:
return -EINVAL;
}
return 0;
}
static int cs35l33_get_mclk_coeff(int mclk, int srate)
{
int i;
for (i = 0; i < ARRAY_SIZE(cs35l33_mclk_coeffs); i++) {
if (cs35l33_mclk_coeffs[i].mclk == mclk &&
cs35l33_mclk_coeffs[i].srate == srate)
return i;
}
return -EINVAL;
}
static int cs35l33_set_dai_fmt(struct snd_soc_dai *codec_dai, unsigned int fmt)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct cs35l33_private *priv = snd_soc_codec_get_drvdata(codec);
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBM_CFM:
regmap_update_bits(priv->regmap, CS35L33_ADSP_CTL,
CS35L33_MS_MASK, CS35L33_MS_MASK);
dev_dbg(codec->dev, "Audio port in master mode\n");
break;
case SND_SOC_DAIFMT_CBS_CFS:
regmap_update_bits(priv->regmap, CS35L33_ADSP_CTL,
CS35L33_MS_MASK, 0);
dev_dbg(codec->dev, "Audio port in slave mode\n");
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_DSP_A:
priv->is_tdm_mode = true;
dev_dbg(codec->dev, "Audio port in TDM mode\n");
break;
case SND_SOC_DAIFMT_I2S:
priv->is_tdm_mode = false;
dev_dbg(codec->dev, "Audio port in I2S mode\n");
break;
default:
return -EINVAL;
}
return 0;
}
static int cs35l33_pcm_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct cs35l33_private *priv = snd_soc_codec_get_drvdata(codec);
int sample_size = params_width(params);
int coeff = cs35l33_get_mclk_coeff(priv->mclk_int, params_rate(params));
if (coeff < 0)
return coeff;
regmap_update_bits(priv->regmap, CS35L33_CLK_CTL,
CS35L33_ADSP_FS | CS35L33_INT_FS_RATE,
cs35l33_mclk_coeffs[coeff].int_fs_ratio
| cs35l33_mclk_coeffs[coeff].adsp_rate);
if (priv->is_tdm_mode) {
sample_size = (sample_size / 8) - 1;
if (sample_size > 2)
sample_size = 2;
regmap_update_bits(priv->regmap, CS35L33_RX_AUD,
CS35L33_AUDIN_RX_DEPTH,
sample_size << CS35L33_AUDIN_RX_DEPTH_SHIFT);
}
dev_dbg(codec->dev, "sample rate=%d, bits per sample=%d\n",
params_rate(params), params_width(params));
return 0;
}
static int cs35l33_pcm_startup(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
snd_pcm_hw_constraint_list(substream->runtime, 0,
SNDRV_PCM_HW_PARAM_RATE,
&cs35l33_constraints);
return 0;
}
static int cs35l33_set_tristate(struct snd_soc_dai *dai, int tristate)
{
struct snd_soc_codec *codec = dai->codec;
struct cs35l33_private *priv = snd_soc_codec_get_drvdata(codec);
if (tristate) {
regmap_update_bits(priv->regmap, CS35L33_PWRCTL2,
CS35L33_SDOUT_3ST_I2S, CS35L33_SDOUT_3ST_I2S);
regmap_update_bits(priv->regmap, CS35L33_CLK_CTL,
CS35L33_SDOUT_3ST_TDM, CS35L33_SDOUT_3ST_TDM);
} else {
regmap_update_bits(priv->regmap, CS35L33_PWRCTL2,
CS35L33_SDOUT_3ST_I2S, 0);
regmap_update_bits(priv->regmap, CS35L33_CLK_CTL,
CS35L33_SDOUT_3ST_TDM, 0);
}
return 0;
}
static int cs35l33_set_tdm_slot(struct snd_soc_dai *dai, unsigned int tx_mask,
unsigned int rx_mask, int slots, int slot_width)
{
struct snd_soc_codec *codec = dai->codec;
struct snd_soc_dapm_context *dapm = snd_soc_codec_get_dapm(codec);
struct cs35l33_private *priv = snd_soc_codec_get_drvdata(codec);
unsigned int reg, bit_pos, i;
int slot, slot_num;
if (slot_width != 8)
return -EINVAL;
slot = ffs(rx_mask) - 1;
if (slot >= 0) {
regmap_update_bits(priv->regmap, CS35L33_RX_AUD,
CS35L33_X_LOC, slot);
dev_dbg(codec->dev, "Audio starts from slots %d", slot);
}
slot = ffs(tx_mask) - 1;
slot_num = 0;
for (i = 0; i < 2 ; i++) {
regmap_update_bits(priv->regmap, CS35L33_TX_VPMON + i,
CS35L33_X_STATE | CS35L33_X_LOC, CS35L33_X_STATE
| CS35L33_X_LOC);
}
snd_soc_dapm_del_routes(dapm, cs35l33_vp_vbst_mon_route,
ARRAY_SIZE(cs35l33_vp_vbst_mon_route));
while (slot >= 0) {
if (slot_num == 0) {
regmap_update_bits(priv->regmap, CS35L33_TX_VMON,
CS35L33_X_STATE | CS35L33_X_LOC, slot);
dev_dbg(codec->dev, "VMON enabled in slots %d-%d",
slot, slot + 1);
}
if (slot_num == 3) {
regmap_update_bits(priv->regmap, CS35L33_TX_IMON,
CS35L33_X_STATE | CS35L33_X_LOC, slot);
dev_dbg(codec->dev, "IMON enabled in slots %d-%d",
slot, slot + 1);
}
if (slot_num == 4) {
regmap_update_bits(priv->regmap, CS35L33_TX_VPMON,
CS35L33_X_STATE | CS35L33_X_LOC, slot);
snd_soc_dapm_add_routes(dapm,
&cs35l33_vp_vbst_mon_route[0], 2);
dev_dbg(codec->dev, "VPMON enabled in slots %d", slot);
}
if (slot_num == 5) {
regmap_update_bits(priv->regmap, CS35L33_TX_VBSTMON,
CS35L33_X_STATE | CS35L33_X_LOC, slot);
snd_soc_dapm_add_routes(dapm,
&cs35l33_vp_vbst_mon_route[2], 2);
dev_dbg(codec->dev,
"VBSTMON enabled in slots %d", slot);
}
reg = CS35L33_TX_EN4 - (slot/8);
bit_pos = slot - ((slot / 8) * (8));
regmap_update_bits(priv->regmap, reg,
1 << bit_pos, 1 << bit_pos);
tx_mask &= ~(1 << slot);
slot = ffs(tx_mask) - 1;
slot_num++;
}
return 0;
}
static int cs35l33_codec_set_sysclk(struct snd_soc_codec *codec,
int clk_id, int source, unsigned int freq, int dir)
{
struct cs35l33_private *cs35l33 = snd_soc_codec_get_drvdata(codec);
switch (freq) {
case CS35L33_MCLK_5644:
case CS35L33_MCLK_6:
case CS35L33_MCLK_6144:
regmap_update_bits(cs35l33->regmap, CS35L33_CLK_CTL,
CS35L33_MCLKDIV2, 0);
cs35l33->mclk_int = freq;
break;
case CS35L33_MCLK_11289:
case CS35L33_MCLK_12:
case CS35L33_MCLK_12288:
regmap_update_bits(cs35l33->regmap, CS35L33_CLK_CTL,
CS35L33_MCLKDIV2, CS35L33_MCLKDIV2);
cs35l33->mclk_int = freq/2;
break;
default:
cs35l33->mclk_int = 0;
return -EINVAL;
}
dev_dbg(codec->dev, "external mclk freq=%d, internal mclk freq=%d\n",
freq, cs35l33->mclk_int);
return 0;
}
static int cs35l33_set_hg_data(struct snd_soc_codec *codec,
struct cs35l33_pdata *pdata)
{
struct cs35l33_hg *hg_config = &pdata->hg_config;
struct snd_soc_dapm_context *dapm = snd_soc_codec_get_dapm(codec);
struct cs35l33_private *priv = snd_soc_codec_get_drvdata(codec);
if (hg_config->enable_hg_algo) {
regmap_update_bits(priv->regmap, CS35L33_HG_MEMLDO_CTL,
CS35L33_MEM_DEPTH_MASK,
hg_config->mem_depth << CS35L33_MEM_DEPTH_SHIFT);
regmap_write(priv->regmap, CS35L33_HG_REL_RATE,
hg_config->release_rate);
regmap_update_bits(priv->regmap, CS35L33_HG_HEAD,
CS35L33_HD_RM_MASK,
hg_config->hd_rm << CS35L33_HD_RM_SHIFT);
regmap_update_bits(priv->regmap, CS35L33_HG_MEMLDO_CTL,
CS35L33_LDO_THLD_MASK,
hg_config->ldo_thld << CS35L33_LDO_THLD_SHIFT);
regmap_update_bits(priv->regmap, CS35L33_HG_MEMLDO_CTL,
CS35L33_LDO_DISABLE_MASK,
hg_config->ldo_path_disable <<
CS35L33_LDO_DISABLE_SHIFT);
regmap_update_bits(priv->regmap, CS35L33_LDO_DEL,
CS35L33_LDO_ENTRY_DELAY_MASK,
hg_config->ldo_entry_delay <<
CS35L33_LDO_ENTRY_DELAY_SHIFT);
if (hg_config->vp_hg_auto) {
regmap_update_bits(priv->regmap, CS35L33_HG_EN,
CS35L33_VP_HG_AUTO_MASK,
CS35L33_VP_HG_AUTO_MASK);
snd_soc_dapm_add_routes(dapm, cs35l33_vphg_auto_route,
ARRAY_SIZE(cs35l33_vphg_auto_route));
}
regmap_update_bits(priv->regmap, CS35L33_HG_EN,
CS35L33_VP_HG_MASK,
hg_config->vp_hg << CS35L33_VP_HG_SHIFT);
regmap_update_bits(priv->regmap, CS35L33_LDO_DEL,
CS35L33_VP_HG_RATE_MASK,
hg_config->vp_hg_rate << CS35L33_VP_HG_RATE_SHIFT);
regmap_update_bits(priv->regmap, CS35L33_LDO_DEL,
CS35L33_VP_HG_VA_MASK,
hg_config->vp_hg_va << CS35L33_VP_HG_VA_SHIFT);
regmap_update_bits(priv->regmap, CS35L33_HG_EN,
CS35L33_CLASS_HG_EN_MASK, CS35L33_CLASS_HG_EN_MASK);
}
return 0;
}
static int cs35l33_set_bst_ipk(struct snd_soc_codec *codec, unsigned int bst)
{
struct cs35l33_private *cs35l33 = snd_soc_codec_get_drvdata(codec);
int ret = 0, steps = 0;
if (bst > 3600000 || bst < 1850000) {
dev_err(codec->dev, "Invalid boost current %d\n", bst);
ret = -EINVAL;
goto err;
}
if (bst % 15625) {
dev_err(codec->dev, "Current not a multiple of 15625uA (%d)\n",
bst);
ret = -EINVAL;
goto err;
}
while (bst > 1850000) {
bst -= 15625;
steps++;
}
regmap_write(cs35l33->regmap, CS35L33_BST_PEAK_CTL,
steps+0x70);
err:
return ret;
}
static int cs35l33_probe(struct snd_soc_codec *codec)
{
struct cs35l33_private *cs35l33 = snd_soc_codec_get_drvdata(codec);
cs35l33->codec = codec;
pm_runtime_get_sync(codec->dev);
regmap_update_bits(cs35l33->regmap, CS35L33_PROTECT_CTL,
CS35L33_ALIVE_WD_DIS, 0x8);
regmap_update_bits(cs35l33->regmap, CS35L33_BST_CTL2,
CS35L33_ALIVE_WD_DIS2,
CS35L33_ALIVE_WD_DIS2);
regmap_update_bits(cs35l33->regmap, CS35L33_BST_CTL1,
CS35L33_BST_CTL_MASK, cs35l33->pdata.boost_ctl);
regmap_update_bits(cs35l33->regmap, CS35L33_CLASSD_CTL,
CS35L33_AMP_DRV_SEL_MASK,
cs35l33->pdata.amp_drv_sel << CS35L33_AMP_DRV_SEL_SHIFT);
if (cs35l33->pdata.boost_ipk)
cs35l33_set_bst_ipk(codec, cs35l33->pdata.boost_ipk);
if (cs35l33->enable_soft_ramp) {
snd_soc_update_bits(codec, CS35L33_DAC_CTL,
CS35L33_DIGSFT, CS35L33_DIGSFT);
snd_soc_update_bits(codec, CS35L33_DAC_CTL,
CS35L33_DSR_RATE, cs35l33->pdata.ramp_rate);
} else {
snd_soc_update_bits(codec, CS35L33_DAC_CTL,
CS35L33_DIGSFT, 0);
}
if (cs35l33->pdata.imon_adc_scale != 0x8)
snd_soc_update_bits(codec, CS35L33_ADC_CTL,
CS35L33_IMON_SCALE, cs35l33->pdata.imon_adc_scale);
cs35l33_set_hg_data(codec, &(cs35l33->pdata));
regmap_update_bits(cs35l33->regmap, CS35L33_INT_MASK_1,
CS35L33_M_OTE | CS35L33_M_OTW | CS35L33_M_AMP_SHORT |
CS35L33_M_CAL_ERR, 0);
pm_runtime_put_sync(codec->dev);
return 0;
}
static int __maybe_unused cs35l33_runtime_resume(struct device *dev)
{
struct cs35l33_private *cs35l33 = dev_get_drvdata(dev);
int ret;
dev_dbg(dev, "%s\n", __func__);
if (cs35l33->reset_gpio)
gpiod_set_value_cansleep(cs35l33->reset_gpio, 0);
ret = regulator_bulk_enable(cs35l33->num_core_supplies,
cs35l33->core_supplies);
if (ret != 0) {
dev_err(dev, "Failed to enable core supplies: %d\n", ret);
return ret;
}
regcache_cache_only(cs35l33->regmap, false);
if (cs35l33->reset_gpio)
gpiod_set_value_cansleep(cs35l33->reset_gpio, 1);
msleep(CS35L33_BOOT_DELAY);
ret = regcache_sync(cs35l33->regmap);
if (ret != 0) {
dev_err(dev, "Failed to restore register cache\n");
goto err;
}
return 0;
err:
regcache_cache_only(cs35l33->regmap, true);
regulator_bulk_disable(cs35l33->num_core_supplies,
cs35l33->core_supplies);
return ret;
}
static int __maybe_unused cs35l33_runtime_suspend(struct device *dev)
{
struct cs35l33_private *cs35l33 = dev_get_drvdata(dev);
dev_dbg(dev, "%s\n", __func__);
cs35l33->amp_cal = false;
regcache_cache_only(cs35l33->regmap, true);
regcache_mark_dirty(cs35l33->regmap);
regulator_bulk_disable(cs35l33->num_core_supplies,
cs35l33->core_supplies);
return 0;
}
static int cs35l33_get_hg_data(const struct device_node *np,
struct cs35l33_pdata *pdata)
{
struct device_node *hg;
struct cs35l33_hg *hg_config = &pdata->hg_config;
u32 val32;
hg = of_get_child_by_name(np, "cirrus,hg-algo");
hg_config->enable_hg_algo = hg ? true : false;
if (hg_config->enable_hg_algo) {
if (of_property_read_u32(hg, "cirrus,mem-depth", &val32) >= 0)
hg_config->mem_depth = val32;
if (of_property_read_u32(hg, "cirrus,release-rate",
&val32) >= 0)
hg_config->release_rate = val32;
if (of_property_read_u32(hg, "cirrus,ldo-thld", &val32) >= 0)
hg_config->ldo_thld = val32;
if (of_property_read_u32(hg, "cirrus,ldo-path-disable",
&val32) >= 0)
hg_config->ldo_path_disable = val32;
if (of_property_read_u32(hg, "cirrus,ldo-entry-delay",
&val32) >= 0)
hg_config->ldo_entry_delay = val32;
hg_config->vp_hg_auto = of_property_read_bool(hg,
"cirrus,vp-hg-auto");
if (of_property_read_u32(hg, "cirrus,vp-hg", &val32) >= 0)
hg_config->vp_hg = val32;
if (of_property_read_u32(hg, "cirrus,vp-hg-rate", &val32) >= 0)
hg_config->vp_hg_rate = val32;
if (of_property_read_u32(hg, "cirrus,vp-hg-va", &val32) >= 0)
hg_config->vp_hg_va = val32;
}
of_node_put(hg);
return 0;
}
static irqreturn_t cs35l33_irq_thread(int irq, void *data)
{
struct cs35l33_private *cs35l33 = data;
struct snd_soc_codec *codec = cs35l33->codec;
unsigned int sticky_val1, sticky_val2, current_val, mask1, mask2;
regmap_read(cs35l33->regmap, CS35L33_INT_STATUS_2,
&sticky_val2);
regmap_read(cs35l33->regmap, CS35L33_INT_STATUS_1,
&sticky_val1);
regmap_read(cs35l33->regmap, CS35L33_INT_MASK_2, &mask2);
regmap_read(cs35l33->regmap, CS35L33_INT_MASK_1, &mask1);
if (!(sticky_val1 & ~mask1) && !(sticky_val2 & ~mask2))
return IRQ_NONE;
regmap_read(cs35l33->regmap, CS35L33_INT_STATUS_1,
&current_val);
if (sticky_val1 & CS35L33_AMP_SHORT) {
dev_crit(codec->dev, "Amp short error\n");
if (!(current_val & CS35L33_AMP_SHORT)) {
dev_dbg(codec->dev,
"Amp short error release\n");
regmap_update_bits(cs35l33->regmap,
CS35L33_AMP_CTL,
CS35L33_AMP_SHORT_RLS, 0);
regmap_update_bits(cs35l33->regmap,
CS35L33_AMP_CTL,
CS35L33_AMP_SHORT_RLS,
CS35L33_AMP_SHORT_RLS);
regmap_update_bits(cs35l33->regmap,
CS35L33_AMP_CTL, CS35L33_AMP_SHORT_RLS,
0);
}
}
if (sticky_val1 & CS35L33_CAL_ERR) {
dev_err(codec->dev, "Cal error\n");
cs35l33->amp_cal = false;
if (!(current_val & CS35L33_CAL_ERR)) {
dev_dbg(codec->dev, "Cal error release\n");
regmap_update_bits(cs35l33->regmap,
CS35L33_AMP_CTL, CS35L33_CAL_ERR_RLS,
0);
regmap_update_bits(cs35l33->regmap,
CS35L33_AMP_CTL, CS35L33_CAL_ERR_RLS,
CS35L33_CAL_ERR_RLS);
regmap_update_bits(cs35l33->regmap,
CS35L33_AMP_CTL, CS35L33_CAL_ERR_RLS,
0);
}
}
if (sticky_val1 & CS35L33_OTE) {
dev_crit(codec->dev, "Over temperature error\n");
if (!(current_val & CS35L33_OTE)) {
dev_dbg(codec->dev,
"Over temperature error release\n");
regmap_update_bits(cs35l33->regmap,
CS35L33_AMP_CTL, CS35L33_OTE_RLS, 0);
regmap_update_bits(cs35l33->regmap,
CS35L33_AMP_CTL, CS35L33_OTE_RLS,
CS35L33_OTE_RLS);
regmap_update_bits(cs35l33->regmap,
CS35L33_AMP_CTL, CS35L33_OTE_RLS, 0);
}
}
if (sticky_val1 & CS35L33_OTW) {
dev_err(codec->dev, "Over temperature warning\n");
if (!(current_val & CS35L33_OTW)) {
dev_dbg(codec->dev,
"Over temperature warning release\n");
regmap_update_bits(cs35l33->regmap,
CS35L33_AMP_CTL, CS35L33_OTW_RLS, 0);
regmap_update_bits(cs35l33->regmap,
CS35L33_AMP_CTL, CS35L33_OTW_RLS,
CS35L33_OTW_RLS);
regmap_update_bits(cs35l33->regmap,
CS35L33_AMP_CTL, CS35L33_OTW_RLS, 0);
}
}
if (CS35L33_ALIVE_ERR & sticky_val1)
dev_err(codec->dev, "ERROR: ADSPCLK Interrupt\n");
if (CS35L33_MCLK_ERR & sticky_val1)
dev_err(codec->dev, "ERROR: MCLK Interrupt\n");
if (CS35L33_VMON_OVFL & sticky_val2)
dev_err(codec->dev,
"ERROR: VMON Overflow Interrupt\n");
if (CS35L33_IMON_OVFL & sticky_val2)
dev_err(codec->dev,
"ERROR: IMON Overflow Interrupt\n");
if (CS35L33_VPMON_OVFL & sticky_val2)
dev_err(codec->dev,
"ERROR: VPMON Overflow Interrupt\n");
return IRQ_HANDLED;
}
static int cs35l33_of_get_pdata(struct device *dev,
struct cs35l33_private *cs35l33)
{
struct device_node *np = dev->of_node;
struct cs35l33_pdata *pdata = &cs35l33->pdata;
u32 val32;
if (!np)
return 0;
if (of_property_read_u32(np, "cirrus,boost-ctl", &val32) >= 0) {
pdata->boost_ctl = val32;
pdata->amp_drv_sel = 1;
}
if (of_property_read_u32(np, "cirrus,ramp-rate", &val32) >= 0) {
pdata->ramp_rate = val32;
cs35l33->enable_soft_ramp = true;
}
if (of_property_read_u32(np, "cirrus,boost-ipk", &val32) >= 0)
pdata->boost_ipk = val32;
if (of_property_read_u32(np, "cirrus,imon-adc-scale", &val32) >= 0) {
if ((val32 == 0x0) || (val32 == 0x7) || (val32 == 0x6))
pdata->imon_adc_scale = val32;
else
pdata->imon_adc_scale = 0x8;
} else {
pdata->imon_adc_scale = 0x8;
}
cs35l33_get_hg_data(np, pdata);
return 0;
}
static int cs35l33_i2c_probe(struct i2c_client *i2c_client,
const struct i2c_device_id *id)
{
struct cs35l33_private *cs35l33;
struct cs35l33_pdata *pdata = dev_get_platdata(&i2c_client->dev);
int ret, devid, i;
unsigned int reg;
cs35l33 = devm_kzalloc(&i2c_client->dev, sizeof(struct cs35l33_private),
GFP_KERNEL);
if (!cs35l33)
return -ENOMEM;
i2c_set_clientdata(i2c_client, cs35l33);
cs35l33->regmap = devm_regmap_init_i2c(i2c_client, &cs35l33_regmap);
if (IS_ERR(cs35l33->regmap)) {
ret = PTR_ERR(cs35l33->regmap);
dev_err(&i2c_client->dev, "regmap_init() failed: %d\n", ret);
return ret;
}
regcache_cache_only(cs35l33->regmap, true);
for (i = 0; i < ARRAY_SIZE(cs35l33_core_supplies); i++)
cs35l33->core_supplies[i].supply
= cs35l33_core_supplies[i];
cs35l33->num_core_supplies = ARRAY_SIZE(cs35l33_core_supplies);
ret = devm_regulator_bulk_get(&i2c_client->dev,
cs35l33->num_core_supplies,
cs35l33->core_supplies);
if (ret != 0) {
dev_err(&i2c_client->dev,
"Failed to request core supplies: %d\n",
ret);
return ret;
}
if (pdata) {
cs35l33->pdata = *pdata;
} else {
cs35l33_of_get_pdata(&i2c_client->dev, cs35l33);
pdata = &cs35l33->pdata;
}
ret = devm_request_threaded_irq(&i2c_client->dev, i2c_client->irq, NULL,
cs35l33_irq_thread, IRQF_ONESHOT | IRQF_TRIGGER_LOW,
"cs35l33", cs35l33);
if (ret != 0)
dev_warn(&i2c_client->dev, "Failed to request IRQ: %d\n", ret);
cs35l33->reset_gpio = devm_gpiod_get_optional(&i2c_client->dev,
"reset-gpios", GPIOD_OUT_HIGH);
if (IS_ERR(cs35l33->reset_gpio)) {
dev_err(&i2c_client->dev, "%s ERROR: Can't get reset GPIO\n",
__func__);
return PTR_ERR(cs35l33->reset_gpio);
}
ret = regulator_bulk_enable(cs35l33->num_core_supplies,
cs35l33->core_supplies);
if (ret != 0) {
dev_err(&i2c_client->dev,
"Failed to enable core supplies: %d\n",
ret);
return ret;
}
if (cs35l33->reset_gpio)
gpiod_set_value_cansleep(cs35l33->reset_gpio, 1);
msleep(CS35L33_BOOT_DELAY);
regcache_cache_only(cs35l33->regmap, false);
ret = regmap_read(cs35l33->regmap, CS35L33_DEVID_AB, &reg);
devid = (reg & 0xFF) << 12;
ret = regmap_read(cs35l33->regmap, CS35L33_DEVID_CD, &reg);
devid |= (reg & 0xFF) << 4;
ret = regmap_read(cs35l33->regmap, CS35L33_DEVID_E, &reg);
devid |= (reg & 0xF0) >> 4;
if (devid != CS35L33_CHIP_ID) {
dev_err(&i2c_client->dev,
"CS35L33 Device ID (%X). Expected ID %X\n",
devid, CS35L33_CHIP_ID);
goto err_enable;
}
ret = regmap_read(cs35l33->regmap, CS35L33_REV_ID, &reg);
if (ret < 0) {
dev_err(&i2c_client->dev, "Get Revision ID failed\n");
goto err_enable;
}
dev_info(&i2c_client->dev,
"Cirrus Logic CS35L33, Revision: %02X\n", reg & 0xFF);
ret = regmap_register_patch(cs35l33->regmap,
cs35l33_patch, ARRAY_SIZE(cs35l33_patch));
if (ret < 0) {
dev_err(&i2c_client->dev,
"Error in applying regmap patch: %d\n", ret);
goto err_enable;
}
regmap_update_bits(cs35l33->regmap, CS35L33_CLK_CTL,
CS35L33_MCLKDIS | CS35L33_SDOUT_3ST_TDM,
CS35L33_MCLKDIS | CS35L33_SDOUT_3ST_TDM);
pm_runtime_set_autosuspend_delay(&i2c_client->dev, 100);
pm_runtime_use_autosuspend(&i2c_client->dev);
pm_runtime_set_active(&i2c_client->dev);
pm_runtime_enable(&i2c_client->dev);
ret = snd_soc_register_codec(&i2c_client->dev,
&soc_codec_dev_cs35l33, &cs35l33_dai, 1);
if (ret < 0) {
dev_err(&i2c_client->dev, "%s: Register codec failed\n",
__func__);
goto err_enable;
}
return 0;
err_enable:
regulator_bulk_disable(cs35l33->num_core_supplies,
cs35l33->core_supplies);
return ret;
}
static int cs35l33_i2c_remove(struct i2c_client *client)
{
struct cs35l33_private *cs35l33 = i2c_get_clientdata(client);
snd_soc_unregister_codec(&client->dev);
if (cs35l33->reset_gpio)
gpiod_set_value_cansleep(cs35l33->reset_gpio, 0);
pm_runtime_disable(&client->dev);
regulator_bulk_disable(cs35l33->num_core_supplies,
cs35l33->core_supplies);
return 0;
}
