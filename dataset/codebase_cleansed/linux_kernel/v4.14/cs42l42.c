static bool cs42l42_readable_register(struct device *dev, unsigned int reg)
{
switch (reg) {
case CS42L42_PAGE_REGISTER:
case CS42L42_DEVID_AB:
case CS42L42_DEVID_CD:
case CS42L42_DEVID_E:
case CS42L42_FABID:
case CS42L42_REVID:
case CS42L42_FRZ_CTL:
case CS42L42_SRC_CTL:
case CS42L42_MCLK_STATUS:
case CS42L42_MCLK_CTL:
case CS42L42_SFTRAMP_RATE:
case CS42L42_I2C_DEBOUNCE:
case CS42L42_I2C_STRETCH:
case CS42L42_I2C_TIMEOUT:
case CS42L42_PWR_CTL1:
case CS42L42_PWR_CTL2:
case CS42L42_PWR_CTL3:
case CS42L42_RSENSE_CTL1:
case CS42L42_RSENSE_CTL2:
case CS42L42_OSC_SWITCH:
case CS42L42_OSC_SWITCH_STATUS:
case CS42L42_RSENSE_CTL3:
case CS42L42_TSENSE_CTL:
case CS42L42_TSRS_INT_DISABLE:
case CS42L42_TRSENSE_STATUS:
case CS42L42_HSDET_CTL1:
case CS42L42_HSDET_CTL2:
case CS42L42_HS_SWITCH_CTL:
case CS42L42_HS_DET_STATUS:
case CS42L42_HS_CLAMP_DISABLE:
case CS42L42_MCLK_SRC_SEL:
case CS42L42_SPDIF_CLK_CFG:
case CS42L42_FSYNC_PW_LOWER:
case CS42L42_FSYNC_PW_UPPER:
case CS42L42_FSYNC_P_LOWER:
case CS42L42_FSYNC_P_UPPER:
case CS42L42_ASP_CLK_CFG:
case CS42L42_ASP_FRM_CFG:
case CS42L42_FS_RATE_EN:
case CS42L42_IN_ASRC_CLK:
case CS42L42_OUT_ASRC_CLK:
case CS42L42_PLL_DIV_CFG1:
case CS42L42_ADC_OVFL_STATUS:
case CS42L42_MIXER_STATUS:
case CS42L42_SRC_STATUS:
case CS42L42_ASP_RX_STATUS:
case CS42L42_ASP_TX_STATUS:
case CS42L42_CODEC_STATUS:
case CS42L42_DET_INT_STATUS1:
case CS42L42_DET_INT_STATUS2:
case CS42L42_SRCPL_INT_STATUS:
case CS42L42_VPMON_STATUS:
case CS42L42_PLL_LOCK_STATUS:
case CS42L42_TSRS_PLUG_STATUS:
case CS42L42_ADC_OVFL_INT_MASK:
case CS42L42_MIXER_INT_MASK:
case CS42L42_SRC_INT_MASK:
case CS42L42_ASP_RX_INT_MASK:
case CS42L42_ASP_TX_INT_MASK:
case CS42L42_CODEC_INT_MASK:
case CS42L42_SRCPL_INT_MASK:
case CS42L42_VPMON_INT_MASK:
case CS42L42_PLL_LOCK_INT_MASK:
case CS42L42_TSRS_PLUG_INT_MASK:
case CS42L42_PLL_CTL1:
case CS42L42_PLL_DIV_FRAC0:
case CS42L42_PLL_DIV_FRAC1:
case CS42L42_PLL_DIV_FRAC2:
case CS42L42_PLL_DIV_INT:
case CS42L42_PLL_CTL3:
case CS42L42_PLL_CAL_RATIO:
case CS42L42_PLL_CTL4:
case CS42L42_LOAD_DET_RCSTAT:
case CS42L42_LOAD_DET_DONE:
case CS42L42_LOAD_DET_EN:
case CS42L42_HSBIAS_SC_AUTOCTL:
case CS42L42_WAKE_CTL:
case CS42L42_ADC_DISABLE_MUTE:
case CS42L42_TIPSENSE_CTL:
case CS42L42_MISC_DET_CTL:
case CS42L42_MIC_DET_CTL1:
case CS42L42_MIC_DET_CTL2:
case CS42L42_DET_STATUS1:
case CS42L42_DET_STATUS2:
case CS42L42_DET_INT1_MASK:
case CS42L42_DET_INT2_MASK:
case CS42L42_HS_BIAS_CTL:
case CS42L42_ADC_CTL:
case CS42L42_ADC_VOLUME:
case CS42L42_ADC_WNF_HPF_CTL:
case CS42L42_DAC_CTL1:
case CS42L42_DAC_CTL2:
case CS42L42_HP_CTL:
case CS42L42_CLASSH_CTL:
case CS42L42_MIXER_CHA_VOL:
case CS42L42_MIXER_ADC_VOL:
case CS42L42_MIXER_CHB_VOL:
case CS42L42_EQ_COEF_IN0:
case CS42L42_EQ_COEF_IN1:
case CS42L42_EQ_COEF_IN2:
case CS42L42_EQ_COEF_IN3:
case CS42L42_EQ_COEF_RW:
case CS42L42_EQ_COEF_OUT0:
case CS42L42_EQ_COEF_OUT1:
case CS42L42_EQ_COEF_OUT2:
case CS42L42_EQ_COEF_OUT3:
case CS42L42_EQ_INIT_STAT:
case CS42L42_EQ_START_FILT:
case CS42L42_EQ_MUTE_CTL:
case CS42L42_SP_RX_CH_SEL:
case CS42L42_SP_RX_ISOC_CTL:
case CS42L42_SP_RX_FS:
case CS42l42_SPDIF_CH_SEL:
case CS42L42_SP_TX_ISOC_CTL:
case CS42L42_SP_TX_FS:
case CS42L42_SPDIF_SW_CTL1:
case CS42L42_SRC_SDIN_FS:
case CS42L42_SRC_SDOUT_FS:
case CS42L42_SPDIF_CTL1:
case CS42L42_SPDIF_CTL2:
case CS42L42_SPDIF_CTL3:
case CS42L42_SPDIF_CTL4:
case CS42L42_ASP_TX_SZ_EN:
case CS42L42_ASP_TX_CH_EN:
case CS42L42_ASP_TX_CH_AP_RES:
case CS42L42_ASP_TX_CH1_BIT_MSB:
case CS42L42_ASP_TX_CH1_BIT_LSB:
case CS42L42_ASP_TX_HIZ_DLY_CFG:
case CS42L42_ASP_TX_CH2_BIT_MSB:
case CS42L42_ASP_TX_CH2_BIT_LSB:
case CS42L42_ASP_RX_DAI0_EN:
case CS42L42_ASP_RX_DAI0_CH1_AP_RES:
case CS42L42_ASP_RX_DAI0_CH1_BIT_MSB:
case CS42L42_ASP_RX_DAI0_CH1_BIT_LSB:
case CS42L42_ASP_RX_DAI0_CH2_AP_RES:
case CS42L42_ASP_RX_DAI0_CH2_BIT_MSB:
case CS42L42_ASP_RX_DAI0_CH2_BIT_LSB:
case CS42L42_ASP_RX_DAI0_CH3_AP_RES:
case CS42L42_ASP_RX_DAI0_CH3_BIT_MSB:
case CS42L42_ASP_RX_DAI0_CH3_BIT_LSB:
case CS42L42_ASP_RX_DAI0_CH4_AP_RES:
case CS42L42_ASP_RX_DAI0_CH4_BIT_MSB:
case CS42L42_ASP_RX_DAI0_CH4_BIT_LSB:
case CS42L42_ASP_RX_DAI1_CH1_AP_RES:
case CS42L42_ASP_RX_DAI1_CH1_BIT_MSB:
case CS42L42_ASP_RX_DAI1_CH1_BIT_LSB:
case CS42L42_ASP_RX_DAI1_CH2_AP_RES:
case CS42L42_ASP_RX_DAI1_CH2_BIT_MSB:
case CS42L42_ASP_RX_DAI1_CH2_BIT_LSB:
case CS42L42_SUB_REVID:
return true;
default:
return false;
}
}
static bool cs42l42_volatile_register(struct device *dev, unsigned int reg)
{
switch (reg) {
case CS42L42_DEVID_AB:
case CS42L42_DEVID_CD:
case CS42L42_DEVID_E:
case CS42L42_MCLK_STATUS:
case CS42L42_TRSENSE_STATUS:
case CS42L42_HS_DET_STATUS:
case CS42L42_ADC_OVFL_STATUS:
case CS42L42_MIXER_STATUS:
case CS42L42_SRC_STATUS:
case CS42L42_ASP_RX_STATUS:
case CS42L42_ASP_TX_STATUS:
case CS42L42_CODEC_STATUS:
case CS42L42_DET_INT_STATUS1:
case CS42L42_DET_INT_STATUS2:
case CS42L42_SRCPL_INT_STATUS:
case CS42L42_VPMON_STATUS:
case CS42L42_PLL_LOCK_STATUS:
case CS42L42_TSRS_PLUG_STATUS:
case CS42L42_LOAD_DET_RCSTAT:
case CS42L42_LOAD_DET_DONE:
case CS42L42_DET_STATUS1:
case CS42L42_DET_STATUS2:
return true;
default:
return false;
}
}
static int cs42l42_hpdrv_evt(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
if (event & SND_SOC_DAPM_POST_PMU) {
snd_soc_update_bits(codec, CS42L42_ASP_RX_DAI0_EN,
CS42L42_ASP_RX0_CH_EN_MASK,
(CS42L42_ASP_RX0_CH1_EN |
CS42L42_ASP_RX0_CH2_EN) <<
CS42L42_ASP_RX0_CH_EN_SHIFT);
snd_soc_update_bits(codec, CS42L42_PWR_CTL1,
CS42L42_ASP_DAI_PDN_MASK | CS42L42_MIXER_PDN_MASK |
CS42L42_HP_PDN_MASK, 0);
} else if (event & SND_SOC_DAPM_PRE_PMD) {
snd_soc_update_bits(codec, CS42L42_ASP_RX_DAI0_EN,
CS42L42_ASP_RX0_CH_EN_MASK, 0);
snd_soc_update_bits(codec, CS42L42_PWR_CTL1,
CS42L42_ASP_DAI_PDN_MASK | CS42L42_MIXER_PDN_MASK |
CS42L42_HP_PDN_MASK,
CS42L42_ASP_DAI_PDN_MASK | CS42L42_MIXER_PDN_MASK |
CS42L42_HP_PDN_MASK);
} else {
dev_err(codec->dev, "Invalid event 0x%x\n", event);
}
return 0;
}
static int cs42l42_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
struct cs42l42_private *cs42l42 = snd_soc_codec_get_drvdata(codec);
int ret;
switch (level) {
case SND_SOC_BIAS_ON:
break;
case SND_SOC_BIAS_PREPARE:
break;
case SND_SOC_BIAS_STANDBY:
if (snd_soc_codec_get_bias_level(codec) == SND_SOC_BIAS_OFF) {
regcache_cache_only(cs42l42->regmap, false);
regcache_sync(cs42l42->regmap);
ret = regulator_bulk_enable(
ARRAY_SIZE(cs42l42->supplies),
cs42l42->supplies);
if (ret != 0) {
dev_err(codec->dev,
"Failed to enable regulators: %d\n",
ret);
return ret;
}
}
break;
case SND_SOC_BIAS_OFF:
regcache_cache_only(cs42l42->regmap, true);
regulator_bulk_disable(ARRAY_SIZE(cs42l42->supplies),
cs42l42->supplies);
break;
}
return 0;
}
static int cs42l42_codec_probe(struct snd_soc_codec *codec)
{
struct cs42l42_private *cs42l42 =
(struct cs42l42_private *)snd_soc_codec_get_drvdata(codec);
cs42l42->codec = codec;
return 0;
}
static int cs42l42_pll_config(struct snd_soc_codec *codec)
{
struct cs42l42_private *cs42l42 = snd_soc_codec_get_drvdata(codec);
int i;
u32 fsync;
for (i = 0; i < ARRAY_SIZE(pll_ratio_table); i++) {
if (pll_ratio_table[i].sclk == cs42l42->sclk) {
snd_soc_update_bits(codec, CS42L42_MCLK_CTL,
CS42L42_INTERNAL_FS_MASK,
((pll_ratio_table[i].mclk_int !=
12000000) &&
(pll_ratio_table[i].mclk_int !=
24000000)) <<
CS42L42_INTERNAL_FS_SHIFT);
snd_soc_update_bits(codec, CS42L42_MCLK_SRC_SEL,
CS42L42_MCLK_SRC_SEL_MASK |
CS42L42_MCLKDIV_MASK,
(pll_ratio_table[i].mclk_src_sel
<< CS42L42_MCLK_SRC_SEL_SHIFT) |
(pll_ratio_table[i].mclk_div <<
CS42L42_MCLKDIV_SHIFT));
fsync = cs42l42->sclk / cs42l42->srate;
if (((fsync * cs42l42->srate) != cs42l42->sclk)
|| ((fsync % 2) != 0)) {
dev_err(codec->dev,
"Unsupported sclk %d/sample rate %d\n",
cs42l42->sclk,
cs42l42->srate);
return -EINVAL;
}
snd_soc_update_bits(codec,
CS42L42_FSYNC_P_LOWER,
CS42L42_FSYNC_PERIOD_MASK,
CS42L42_FRAC0_VAL(fsync - 1) <<
CS42L42_FSYNC_PERIOD_SHIFT);
snd_soc_update_bits(codec,
CS42L42_FSYNC_P_UPPER,
CS42L42_FSYNC_PERIOD_MASK,
CS42L42_FRAC1_VAL(fsync - 1) <<
CS42L42_FSYNC_PERIOD_SHIFT);
fsync = fsync / 2;
snd_soc_update_bits(codec,
CS42L42_FSYNC_PW_LOWER,
CS42L42_FSYNC_PULSE_WIDTH_MASK,
CS42L42_FRAC0_VAL(fsync - 1) <<
CS42L42_FSYNC_PULSE_WIDTH_SHIFT);
snd_soc_update_bits(codec,
CS42L42_FSYNC_PW_UPPER,
CS42L42_FSYNC_PULSE_WIDTH_MASK,
CS42L42_FRAC1_VAL(fsync - 1) <<
CS42L42_FSYNC_PULSE_WIDTH_SHIFT);
snd_soc_update_bits(codec,
CS42L42_ASP_FRM_CFG,
CS42L42_ASP_5050_MASK,
CS42L42_ASP_5050_MASK);
snd_soc_update_bits(codec, CS42L42_ASP_FRM_CFG,
CS42L42_ASP_FSD_MASK,
CS42L42_ASP_FSD_1_0 <<
CS42L42_ASP_FSD_SHIFT);
snd_soc_update_bits(codec, CS42L42_FS_RATE_EN,
CS42L42_FS_EN_MASK,
(CS42L42_FS_EN_IASRC_96K |
CS42L42_FS_EN_OASRC_96K) <<
CS42L42_FS_EN_SHIFT);
snd_soc_update_bits(codec, CS42L42_IN_ASRC_CLK,
CS42L42_CLK_IASRC_SEL_MASK,
CS42L42_CLK_IASRC_SEL_12 <<
CS42L42_CLK_IASRC_SEL_SHIFT);
snd_soc_update_bits(codec,
CS42L42_OUT_ASRC_CLK,
CS42L42_CLK_OASRC_SEL_MASK,
CS42L42_CLK_OASRC_SEL_12 <<
CS42L42_CLK_OASRC_SEL_SHIFT);
snd_soc_update_bits(codec,
CS42L42_ASP_RX_DAI0_CH1_AP_RES,
CS42L42_ASP_RX_CH_AP_MASK |
CS42L42_ASP_RX_CH_RES_MASK,
(CS42L42_ASP_RX_CH_AP_LOW <<
CS42L42_ASP_RX_CH_AP_SHIFT) |
(CS42L42_ASP_RX_CH_RES_32 <<
CS42L42_ASP_RX_CH_RES_SHIFT));
snd_soc_update_bits(codec,
CS42L42_ASP_RX_DAI0_CH2_AP_RES,
CS42L42_ASP_RX_CH_AP_MASK |
CS42L42_ASP_RX_CH_RES_MASK,
(CS42L42_ASP_RX_CH_AP_HI <<
CS42L42_ASP_RX_CH_AP_SHIFT) |
(CS42L42_ASP_RX_CH_RES_32 <<
CS42L42_ASP_RX_CH_RES_SHIFT));
if (pll_ratio_table[i].mclk_src_sel == 0) {
snd_soc_update_bits(codec,
CS42L42_PLL_CTL1,
CS42L42_PLL_START_MASK, 0);
} else {
snd_soc_update_bits(codec,
CS42L42_PLL_DIV_CFG1,
CS42L42_SCLK_PREDIV_MASK,
pll_ratio_table[i].sclk_prediv
<< CS42L42_SCLK_PREDIV_SHIFT);
snd_soc_update_bits(codec,
CS42L42_PLL_DIV_INT,
CS42L42_PLL_DIV_INT_MASK,
pll_ratio_table[i].pll_div_int
<< CS42L42_PLL_DIV_INT_SHIFT);
snd_soc_update_bits(codec,
CS42L42_PLL_DIV_FRAC0,
CS42L42_PLL_DIV_FRAC_MASK,
CS42L42_FRAC0_VAL(
pll_ratio_table[i].pll_div_frac)
<< CS42L42_PLL_DIV_FRAC_SHIFT);
snd_soc_update_bits(codec,
CS42L42_PLL_DIV_FRAC1,
CS42L42_PLL_DIV_FRAC_MASK,
CS42L42_FRAC1_VAL(
pll_ratio_table[i].pll_div_frac)
<< CS42L42_PLL_DIV_FRAC_SHIFT);
snd_soc_update_bits(codec,
CS42L42_PLL_DIV_FRAC2,
CS42L42_PLL_DIV_FRAC_MASK,
CS42L42_FRAC2_VAL(
pll_ratio_table[i].pll_div_frac)
<< CS42L42_PLL_DIV_FRAC_SHIFT);
snd_soc_update_bits(codec,
CS42L42_PLL_CTL4,
CS42L42_PLL_MODE_MASK,
pll_ratio_table[i].pll_mode
<< CS42L42_PLL_MODE_SHIFT);
snd_soc_update_bits(codec,
CS42L42_PLL_CTL3,
CS42L42_PLL_DIVOUT_MASK,
pll_ratio_table[i].pll_divout
<< CS42L42_PLL_DIVOUT_SHIFT);
snd_soc_update_bits(codec,
CS42L42_PLL_CAL_RATIO,
CS42L42_PLL_CAL_RATIO_MASK,
pll_ratio_table[i].pll_cal_ratio
<< CS42L42_PLL_CAL_RATIO_SHIFT);
}
return 0;
}
}
return -EINVAL;
}
static int cs42l42_set_dai_fmt(struct snd_soc_dai *codec_dai, unsigned int fmt)
{
struct snd_soc_codec *codec = codec_dai->codec;
u32 asp_cfg_val = 0;
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBS_CFM:
asp_cfg_val |= CS42L42_ASP_MASTER_MODE <<
CS42L42_ASP_MODE_SHIFT;
break;
case SND_SOC_DAIFMT_CBS_CFS:
asp_cfg_val |= CS42L42_ASP_SLAVE_MODE <<
CS42L42_ASP_MODE_SHIFT;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
case SND_SOC_DAIFMT_LEFT_J:
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
break;
case SND_SOC_DAIFMT_NB_IF:
asp_cfg_val |= CS42L42_ASP_POL_INV <<
CS42L42_ASP_LCPOL_IN_SHIFT;
break;
case SND_SOC_DAIFMT_IB_NF:
asp_cfg_val |= CS42L42_ASP_POL_INV <<
CS42L42_ASP_SCPOL_IN_DAC_SHIFT;
break;
case SND_SOC_DAIFMT_IB_IF:
asp_cfg_val |= CS42L42_ASP_POL_INV <<
CS42L42_ASP_LCPOL_IN_SHIFT;
asp_cfg_val |= CS42L42_ASP_POL_INV <<
CS42L42_ASP_SCPOL_IN_DAC_SHIFT;
break;
}
snd_soc_update_bits(codec, CS42L42_ASP_CLK_CFG,
CS42L42_ASP_MODE_MASK |
CS42L42_ASP_SCPOL_IN_DAC_MASK |
CS42L42_ASP_LCPOL_IN_MASK, asp_cfg_val);
return 0;
}
static int cs42l42_pcm_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct cs42l42_private *cs42l42 = snd_soc_codec_get_drvdata(codec);
int retval;
cs42l42->srate = params_rate(params);
cs42l42->swidth = params_width(params);
retval = cs42l42_pll_config(codec);
return retval;
}
static int cs42l42_set_sysclk(struct snd_soc_dai *dai,
int clk_id, unsigned int freq, int dir)
{
struct snd_soc_codec *codec = dai->codec;
struct cs42l42_private *cs42l42 = snd_soc_codec_get_drvdata(codec);
cs42l42->sclk = freq;
return 0;
}
static int cs42l42_digital_mute(struct snd_soc_dai *dai, int mute)
{
struct snd_soc_codec *codec = dai->codec;
unsigned int regval;
u8 fullScaleVol;
if (mute) {
snd_soc_update_bits(codec, CS42L42_OSC_SWITCH,
CS42L42_SCLK_PRESENT_MASK, 0);
snd_soc_update_bits(codec, CS42L42_PLL_CTL1,
CS42L42_PLL_START_MASK,
0 << CS42L42_PLL_START_SHIFT);
snd_soc_update_bits(codec, CS42L42_HP_CTL,
CS42L42_HP_ANA_AMUTE_MASK |
CS42L42_HP_ANA_BMUTE_MASK,
CS42L42_HP_ANA_AMUTE_MASK |
CS42L42_HP_ANA_BMUTE_MASK);
} else {
snd_soc_update_bits(codec, CS42L42_PLL_CTL1,
CS42L42_PLL_START_MASK,
1 << CS42L42_PLL_START_SHIFT);
regval = snd_soc_read(codec, CS42L42_LOAD_DET_RCSTAT);
if (((regval & CS42L42_RLA_STAT_MASK) >>
CS42L42_RLA_STAT_SHIFT) == CS42L42_RLA_STAT_15_OHM) {
fullScaleVol = CS42L42_HP_FULL_SCALE_VOL_MASK;
} else {
fullScaleVol = 0;
}
snd_soc_update_bits(codec, CS42L42_HP_CTL,
CS42L42_HP_ANA_AMUTE_MASK |
CS42L42_HP_ANA_BMUTE_MASK |
CS42L42_HP_FULL_SCALE_VOL_MASK, fullScaleVol);
snd_soc_update_bits(codec, CS42L42_OSC_SWITCH,
CS42L42_SCLK_PRESENT_MASK,
CS42L42_SCLK_PRESENT_MASK);
}
return 0;
}
static void cs42l42_process_hs_type_detect(struct cs42l42_private *cs42l42)
{
unsigned int hs_det_status;
unsigned int int_status;
regmap_update_bits(cs42l42->regmap,
CS42L42_CODEC_INT_MASK,
CS42L42_PDN_DONE_MASK |
CS42L42_HSDET_AUTO_DONE_MASK,
(1 << CS42L42_PDN_DONE_SHIFT) |
(1 << CS42L42_HSDET_AUTO_DONE_SHIFT));
regmap_update_bits(cs42l42->regmap,
CS42L42_HSDET_CTL2,
CS42L42_HSDET_CTRL_MASK |
CS42L42_HSDET_SET_MASK |
CS42L42_HSBIAS_REF_MASK |
CS42L42_HSDET_AUTO_TIME_MASK,
(2 << CS42L42_HSDET_CTRL_SHIFT) |
(2 << CS42L42_HSDET_SET_SHIFT) |
(0 << CS42L42_HSBIAS_REF_SHIFT) |
(3 << CS42L42_HSDET_AUTO_TIME_SHIFT));
regmap_read(cs42l42->regmap, CS42L42_HS_DET_STATUS, &hs_det_status);
cs42l42->hs_type = (hs_det_status & CS42L42_HSDET_TYPE_MASK) >>
CS42L42_HSDET_TYPE_SHIFT;
if ((cs42l42->hs_type == CS42L42_PLUG_CTIA) ||
(cs42l42->hs_type == CS42L42_PLUG_OMTP)) {
regmap_update_bits(cs42l42->regmap,
CS42L42_HSBIAS_SC_AUTOCTL,
CS42L42_HSBIAS_SENSE_EN_MASK |
CS42L42_AUTO_HSBIAS_HIZ_MASK |
CS42L42_TIP_SENSE_EN_MASK |
CS42L42_HSBIAS_SENSE_TRIP_MASK,
(0 << CS42L42_HSBIAS_SENSE_EN_SHIFT) |
(0 << CS42L42_AUTO_HSBIAS_HIZ_SHIFT) |
(0 << CS42L42_TIP_SENSE_EN_SHIFT) |
(3 << CS42L42_HSBIAS_SENSE_TRIP_SHIFT));
regmap_update_bits(cs42l42->regmap,
CS42L42_MIC_DET_CTL1,
CS42L42_LATCH_TO_VP_MASK |
CS42L42_EVENT_STAT_SEL_MASK |
CS42L42_HS_DET_LEVEL_MASK,
(1 << CS42L42_LATCH_TO_VP_SHIFT) |
(0 << CS42L42_EVENT_STAT_SEL_SHIFT) |
(cs42l42->bias_thresholds[0] <<
CS42L42_HS_DET_LEVEL_SHIFT));
regmap_update_bits(cs42l42->regmap,
CS42L42_HSBIAS_SC_AUTOCTL,
CS42L42_HSBIAS_SENSE_EN_MASK |
CS42L42_AUTO_HSBIAS_HIZ_MASK |
CS42L42_TIP_SENSE_EN_MASK |
CS42L42_HSBIAS_SENSE_TRIP_MASK,
(1 << CS42L42_HSBIAS_SENSE_EN_SHIFT) |
(1 << CS42L42_AUTO_HSBIAS_HIZ_SHIFT) |
(0 << CS42L42_TIP_SENSE_EN_SHIFT) |
(3 << CS42L42_HSBIAS_SENSE_TRIP_SHIFT));
regmap_update_bits(cs42l42->regmap,
CS42L42_MISC_DET_CTL,
CS42L42_DETECT_MODE_MASK |
CS42L42_HSBIAS_CTL_MASK |
CS42L42_PDN_MIC_LVL_DET_MASK,
(0 << CS42L42_DETECT_MODE_SHIFT) |
(3 << CS42L42_HSBIAS_CTL_SHIFT) |
(0 << CS42L42_PDN_MIC_LVL_DET_SHIFT));
msleep(cs42l42->btn_det_init_dbnce);
regmap_read(cs42l42->regmap, CS42L42_DET_INT_STATUS2,
&int_status);
regmap_update_bits(cs42l42->regmap,
CS42L42_DET_INT2_MASK,
CS42L42_M_DETECT_TF_MASK |
CS42L42_M_DETECT_FT_MASK |
CS42L42_M_HSBIAS_HIZ_MASK |
CS42L42_M_SHORT_RLS_MASK |
CS42L42_M_SHORT_DET_MASK,
(0 << CS42L42_M_DETECT_TF_SHIFT) |
(0 << CS42L42_M_DETECT_FT_SHIFT) |
(0 << CS42L42_M_HSBIAS_HIZ_SHIFT) |
(1 << CS42L42_M_SHORT_RLS_SHIFT) |
(1 << CS42L42_M_SHORT_DET_SHIFT));
} else {
regmap_update_bits(cs42l42->regmap,
CS42L42_MISC_DET_CTL,
CS42L42_DETECT_MODE_MASK |
CS42L42_HSBIAS_CTL_MASK |
CS42L42_PDN_MIC_LVL_DET_MASK,
(0 << CS42L42_DETECT_MODE_SHIFT) |
(1 << CS42L42_HSBIAS_CTL_SHIFT) |
(1 << CS42L42_PDN_MIC_LVL_DET_SHIFT));
}
regmap_update_bits(cs42l42->regmap,
CS42L42_DAC_CTL2,
CS42L42_HPOUT_PULLDOWN_MASK |
CS42L42_HPOUT_LOAD_MASK |
CS42L42_HPOUT_CLAMP_MASK |
CS42L42_DAC_HPF_EN_MASK |
CS42L42_DAC_MON_EN_MASK,
(0 << CS42L42_HPOUT_PULLDOWN_SHIFT) |
(0 << CS42L42_HPOUT_LOAD_SHIFT) |
(0 << CS42L42_HPOUT_CLAMP_SHIFT) |
(1 << CS42L42_DAC_HPF_EN_SHIFT) |
(0 << CS42L42_DAC_MON_EN_SHIFT));
regmap_update_bits(cs42l42->regmap,
CS42L42_TSRS_PLUG_INT_MASK,
CS42L42_RS_PLUG_MASK |
CS42L42_RS_UNPLUG_MASK |
CS42L42_TS_PLUG_MASK |
CS42L42_TS_UNPLUG_MASK,
(1 << CS42L42_RS_PLUG_SHIFT) |
(1 << CS42L42_RS_UNPLUG_SHIFT) |
(0 << CS42L42_TS_PLUG_SHIFT) |
(0 << CS42L42_TS_UNPLUG_SHIFT));
}
static void cs42l42_init_hs_type_detect(struct cs42l42_private *cs42l42)
{
regmap_update_bits(cs42l42->regmap,
CS42L42_TSRS_PLUG_INT_MASK,
CS42L42_RS_PLUG_MASK |
CS42L42_RS_UNPLUG_MASK |
CS42L42_TS_PLUG_MASK |
CS42L42_TS_UNPLUG_MASK,
(1 << CS42L42_RS_PLUG_SHIFT) |
(1 << CS42L42_RS_UNPLUG_SHIFT) |
(1 << CS42L42_TS_PLUG_SHIFT) |
(1 << CS42L42_TS_UNPLUG_SHIFT));
regmap_update_bits(cs42l42->regmap,
CS42L42_MISC_DET_CTL,
CS42L42_DETECT_MODE_MASK |
CS42L42_HSBIAS_CTL_MASK |
CS42L42_PDN_MIC_LVL_DET_MASK,
(0 << CS42L42_DETECT_MODE_SHIFT) |
(1 << CS42L42_HSBIAS_CTL_SHIFT) |
(1 << CS42L42_PDN_MIC_LVL_DET_SHIFT));
regmap_update_bits(cs42l42->regmap,
CS42L42_HSBIAS_SC_AUTOCTL,
CS42L42_HSBIAS_SENSE_EN_MASK |
CS42L42_AUTO_HSBIAS_HIZ_MASK |
CS42L42_TIP_SENSE_EN_MASK |
CS42L42_HSBIAS_SENSE_TRIP_MASK,
(0 << CS42L42_HSBIAS_SENSE_EN_SHIFT) |
(0 << CS42L42_AUTO_HSBIAS_HIZ_SHIFT) |
(0 << CS42L42_TIP_SENSE_EN_SHIFT) |
(3 << CS42L42_HSBIAS_SENSE_TRIP_SHIFT));
regmap_update_bits(cs42l42->regmap,
CS42L42_HSDET_CTL2,
CS42L42_HSDET_CTRL_MASK |
CS42L42_HSDET_SET_MASK |
CS42L42_HSBIAS_REF_MASK |
CS42L42_HSDET_AUTO_TIME_MASK,
(0 << CS42L42_HSDET_CTRL_SHIFT) |
(2 << CS42L42_HSDET_SET_SHIFT) |
(0 << CS42L42_HSBIAS_REF_SHIFT) |
(3 << CS42L42_HSDET_AUTO_TIME_SHIFT));
regmap_update_bits(cs42l42->regmap,
CS42L42_DAC_CTL2,
CS42L42_HPOUT_PULLDOWN_MASK |
CS42L42_HPOUT_LOAD_MASK |
CS42L42_HPOUT_CLAMP_MASK |
CS42L42_DAC_HPF_EN_MASK |
CS42L42_DAC_MON_EN_MASK,
(8 << CS42L42_HPOUT_PULLDOWN_SHIFT) |
(0 << CS42L42_HPOUT_LOAD_SHIFT) |
(1 << CS42L42_HPOUT_CLAMP_SHIFT) |
(1 << CS42L42_DAC_HPF_EN_SHIFT) |
(1 << CS42L42_DAC_MON_EN_SHIFT));
regmap_update_bits(cs42l42->regmap,
CS42L42_MISC_DET_CTL,
CS42L42_DETECT_MODE_MASK |
CS42L42_HSBIAS_CTL_MASK |
CS42L42_PDN_MIC_LVL_DET_MASK,
(0 << CS42L42_DETECT_MODE_SHIFT) |
(3 << CS42L42_HSBIAS_CTL_SHIFT) |
(1 << CS42L42_PDN_MIC_LVL_DET_SHIFT));
msleep(cs42l42->hs_bias_ramp_time);
regmap_update_bits(cs42l42->regmap,
CS42L42_CODEC_INT_MASK,
CS42L42_PDN_DONE_MASK |
CS42L42_HSDET_AUTO_DONE_MASK,
(1 << CS42L42_PDN_DONE_SHIFT) |
(0 << CS42L42_HSDET_AUTO_DONE_SHIFT));
regmap_update_bits(cs42l42->regmap,
CS42L42_HSDET_CTL2,
CS42L42_HSDET_CTRL_MASK |
CS42L42_HSDET_SET_MASK |
CS42L42_HSBIAS_REF_MASK |
CS42L42_HSDET_AUTO_TIME_MASK,
(3 << CS42L42_HSDET_CTRL_SHIFT) |
(2 << CS42L42_HSDET_SET_SHIFT) |
(0 << CS42L42_HSBIAS_REF_SHIFT) |
(3 << CS42L42_HSDET_AUTO_TIME_SHIFT));
}
static void cs42l42_cancel_hs_type_detect(struct cs42l42_private *cs42l42)
{
regmap_update_bits(cs42l42->regmap,
CS42L42_DET_INT2_MASK,
CS42L42_M_DETECT_TF_MASK |
CS42L42_M_DETECT_FT_MASK |
CS42L42_M_HSBIAS_HIZ_MASK |
CS42L42_M_SHORT_RLS_MASK |
CS42L42_M_SHORT_DET_MASK,
(1 << CS42L42_M_DETECT_TF_SHIFT) |
(1 << CS42L42_M_DETECT_FT_SHIFT) |
(1 << CS42L42_M_HSBIAS_HIZ_SHIFT) |
(1 << CS42L42_M_SHORT_RLS_SHIFT) |
(1 << CS42L42_M_SHORT_DET_SHIFT));
regmap_update_bits(cs42l42->regmap,
CS42L42_MISC_DET_CTL,
CS42L42_DETECT_MODE_MASK |
CS42L42_HSBIAS_CTL_MASK |
CS42L42_PDN_MIC_LVL_DET_MASK,
(0 << CS42L42_DETECT_MODE_SHIFT) |
(1 << CS42L42_HSBIAS_CTL_SHIFT) |
(1 << CS42L42_PDN_MIC_LVL_DET_SHIFT));
regmap_update_bits(cs42l42->regmap,
CS42L42_HSBIAS_SC_AUTOCTL,
CS42L42_HSBIAS_SENSE_EN_MASK |
CS42L42_AUTO_HSBIAS_HIZ_MASK |
CS42L42_TIP_SENSE_EN_MASK |
CS42L42_HSBIAS_SENSE_TRIP_MASK,
(0 << CS42L42_HSBIAS_SENSE_EN_SHIFT) |
(0 << CS42L42_AUTO_HSBIAS_HIZ_SHIFT) |
(0 << CS42L42_TIP_SENSE_EN_SHIFT) |
(3 << CS42L42_HSBIAS_SENSE_TRIP_SHIFT));
regmap_update_bits(cs42l42->regmap,
CS42L42_HSDET_CTL2,
CS42L42_HSDET_CTRL_MASK |
CS42L42_HSDET_SET_MASK |
CS42L42_HSBIAS_REF_MASK |
CS42L42_HSDET_AUTO_TIME_MASK,
(0 << CS42L42_HSDET_CTRL_SHIFT) |
(2 << CS42L42_HSDET_SET_SHIFT) |
(0 << CS42L42_HSBIAS_REF_SHIFT) |
(3 << CS42L42_HSDET_AUTO_TIME_SHIFT));
}
static void cs42l42_handle_button_press(struct cs42l42_private *cs42l42)
{
int bias_level;
unsigned int detect_status;
regmap_update_bits(cs42l42->regmap,
CS42L42_DET_INT2_MASK,
CS42L42_M_DETECT_TF_MASK |
CS42L42_M_DETECT_FT_MASK |
CS42L42_M_HSBIAS_HIZ_MASK |
CS42L42_M_SHORT_RLS_MASK |
CS42L42_M_SHORT_DET_MASK,
(1 << CS42L42_M_DETECT_TF_SHIFT) |
(1 << CS42L42_M_DETECT_FT_SHIFT) |
(1 << CS42L42_M_HSBIAS_HIZ_SHIFT) |
(1 << CS42L42_M_SHORT_RLS_SHIFT) |
(1 << CS42L42_M_SHORT_DET_SHIFT));
usleep_range(cs42l42->btn_det_event_dbnce * 1000,
cs42l42->btn_det_event_dbnce * 2000);
bias_level = 1;
do {
regmap_update_bits(cs42l42->regmap,
CS42L42_MIC_DET_CTL1,
CS42L42_LATCH_TO_VP_MASK |
CS42L42_EVENT_STAT_SEL_MASK |
CS42L42_HS_DET_LEVEL_MASK,
(1 << CS42L42_LATCH_TO_VP_SHIFT) |
(0 << CS42L42_EVENT_STAT_SEL_SHIFT) |
(cs42l42->bias_thresholds[bias_level] <<
CS42L42_HS_DET_LEVEL_SHIFT));
regmap_read(cs42l42->regmap, CS42L42_DET_STATUS2,
&detect_status);
} while ((detect_status & CS42L42_HS_TRUE_MASK) &&
(++bias_level < CS42L42_NUM_BIASES));
switch (bias_level) {
case 1:
dev_dbg(cs42l42->codec->dev, "Function C button press\n");
break;
case 2:
dev_dbg(cs42l42->codec->dev, "Function B button press\n");
break;
case 3:
dev_dbg(cs42l42->codec->dev, "Function D button press\n");
break;
case 4:
dev_dbg(cs42l42->codec->dev, "Function A button press\n");
break;
}
regmap_update_bits(cs42l42->regmap,
CS42L42_MIC_DET_CTL1,
CS42L42_LATCH_TO_VP_MASK |
CS42L42_EVENT_STAT_SEL_MASK |
CS42L42_HS_DET_LEVEL_MASK,
(1 << CS42L42_LATCH_TO_VP_SHIFT) |
(0 << CS42L42_EVENT_STAT_SEL_SHIFT) |
(cs42l42->bias_thresholds[0] << CS42L42_HS_DET_LEVEL_SHIFT));
regmap_read(cs42l42->regmap, CS42L42_DET_INT_STATUS2,
&detect_status);
regmap_update_bits(cs42l42->regmap,
CS42L42_DET_INT2_MASK,
CS42L42_M_DETECT_TF_MASK |
CS42L42_M_DETECT_FT_MASK |
CS42L42_M_HSBIAS_HIZ_MASK |
CS42L42_M_SHORT_RLS_MASK |
CS42L42_M_SHORT_DET_MASK,
(0 << CS42L42_M_DETECT_TF_SHIFT) |
(0 << CS42L42_M_DETECT_FT_SHIFT) |
(0 << CS42L42_M_HSBIAS_HIZ_SHIFT) |
(1 << CS42L42_M_SHORT_RLS_SHIFT) |
(1 << CS42L42_M_SHORT_DET_SHIFT));
}
static irqreturn_t cs42l42_irq_thread(int irq, void *data)
{
struct cs42l42_private *cs42l42 = (struct cs42l42_private *)data;
struct snd_soc_codec *codec = cs42l42->codec;
unsigned int stickies[12];
unsigned int masks[12];
unsigned int current_plug_status;
unsigned int current_button_status;
unsigned int i;
for (i = 0; i < ARRAY_SIZE(stickies); i++) {
regmap_read(cs42l42->regmap, irq_params_table[i].status_addr,
&(stickies[i]));
regmap_read(cs42l42->regmap, irq_params_table[i].mask_addr,
&(masks[i]));
stickies[i] = stickies[i] & (~masks[i]) &
irq_params_table[i].mask;
}
current_plug_status = (stickies[11] &
(CS42L42_TS_PLUG_MASK | CS42L42_TS_UNPLUG_MASK)) >>
CS42L42_TS_PLUG_SHIFT;
current_button_status = stickies[7] &
(CS42L42_M_DETECT_TF_MASK |
CS42L42_M_DETECT_FT_MASK |
CS42L42_M_HSBIAS_HIZ_MASK);
if ((~masks[5]) & irq_params_table[5].mask) {
if (stickies[5] & CS42L42_HSDET_AUTO_DONE_MASK) {
cs42l42_process_hs_type_detect(cs42l42);
dev_dbg(codec->dev,
"Auto detect done (%d)\n",
cs42l42->hs_type);
}
}
if ((~masks[11]) & irq_params_table[11].mask) {
switch (current_plug_status) {
case CS42L42_TS_PLUG:
if (cs42l42->plug_state != CS42L42_TS_PLUG) {
cs42l42->plug_state = CS42L42_TS_PLUG;
cs42l42_init_hs_type_detect(cs42l42);
}
break;
case CS42L42_TS_UNPLUG:
if (cs42l42->plug_state != CS42L42_TS_UNPLUG) {
cs42l42->plug_state = CS42L42_TS_UNPLUG;
cs42l42_cancel_hs_type_detect(cs42l42);
dev_dbg(codec->dev,
"Unplug event\n");
}
break;
default:
if (cs42l42->plug_state != CS42L42_TS_TRANS)
cs42l42->plug_state = CS42L42_TS_TRANS;
}
}
if ((~masks[7]) & irq_params_table[7].mask) {
if (!(current_button_status &
CS42L42_M_HSBIAS_HIZ_MASK)) {
if (current_button_status &
CS42L42_M_DETECT_TF_MASK) {
dev_dbg(codec->dev,
"Button released\n");
} else if (current_button_status &
CS42L42_M_DETECT_FT_MASK) {
cs42l42_handle_button_press(cs42l42);
}
}
}
return IRQ_HANDLED;
}
static void cs42l42_set_interrupt_masks(struct cs42l42_private *cs42l42)
{
regmap_update_bits(cs42l42->regmap, CS42L42_ADC_OVFL_INT_MASK,
CS42L42_ADC_OVFL_MASK,
(1 << CS42L42_ADC_OVFL_SHIFT));
regmap_update_bits(cs42l42->regmap, CS42L42_MIXER_INT_MASK,
CS42L42_MIX_CHB_OVFL_MASK |
CS42L42_MIX_CHA_OVFL_MASK |
CS42L42_EQ_OVFL_MASK |
CS42L42_EQ_BIQUAD_OVFL_MASK,
(1 << CS42L42_MIX_CHB_OVFL_SHIFT) |
(1 << CS42L42_MIX_CHA_OVFL_SHIFT) |
(1 << CS42L42_EQ_OVFL_SHIFT) |
(1 << CS42L42_EQ_BIQUAD_OVFL_SHIFT));
regmap_update_bits(cs42l42->regmap, CS42L42_SRC_INT_MASK,
CS42L42_SRC_ILK_MASK |
CS42L42_SRC_OLK_MASK |
CS42L42_SRC_IUNLK_MASK |
CS42L42_SRC_OUNLK_MASK,
(1 << CS42L42_SRC_ILK_SHIFT) |
(1 << CS42L42_SRC_OLK_SHIFT) |
(1 << CS42L42_SRC_IUNLK_SHIFT) |
(1 << CS42L42_SRC_OUNLK_SHIFT));
regmap_update_bits(cs42l42->regmap, CS42L42_ASP_RX_INT_MASK,
CS42L42_ASPRX_NOLRCK_MASK |
CS42L42_ASPRX_EARLY_MASK |
CS42L42_ASPRX_LATE_MASK |
CS42L42_ASPRX_ERROR_MASK |
CS42L42_ASPRX_OVLD_MASK,
(1 << CS42L42_ASPRX_NOLRCK_SHIFT) |
(1 << CS42L42_ASPRX_EARLY_SHIFT) |
(1 << CS42L42_ASPRX_LATE_SHIFT) |
(1 << CS42L42_ASPRX_ERROR_SHIFT) |
(1 << CS42L42_ASPRX_OVLD_SHIFT));
regmap_update_bits(cs42l42->regmap, CS42L42_ASP_TX_INT_MASK,
CS42L42_ASPTX_NOLRCK_MASK |
CS42L42_ASPTX_EARLY_MASK |
CS42L42_ASPTX_LATE_MASK |
CS42L42_ASPTX_SMERROR_MASK,
(1 << CS42L42_ASPTX_NOLRCK_SHIFT) |
(1 << CS42L42_ASPTX_EARLY_SHIFT) |
(1 << CS42L42_ASPTX_LATE_SHIFT) |
(1 << CS42L42_ASPTX_SMERROR_SHIFT));
regmap_update_bits(cs42l42->regmap, CS42L42_CODEC_INT_MASK,
CS42L42_PDN_DONE_MASK |
CS42L42_HSDET_AUTO_DONE_MASK,
(1 << CS42L42_PDN_DONE_SHIFT) |
(1 << CS42L42_HSDET_AUTO_DONE_SHIFT));
regmap_update_bits(cs42l42->regmap, CS42L42_SRCPL_INT_MASK,
CS42L42_SRCPL_ADC_LK_MASK |
CS42L42_SRCPL_DAC_LK_MASK |
CS42L42_SRCPL_ADC_UNLK_MASK |
CS42L42_SRCPL_DAC_UNLK_MASK,
(1 << CS42L42_SRCPL_ADC_LK_SHIFT) |
(1 << CS42L42_SRCPL_DAC_LK_SHIFT) |
(1 << CS42L42_SRCPL_ADC_UNLK_SHIFT) |
(1 << CS42L42_SRCPL_DAC_UNLK_SHIFT));
regmap_update_bits(cs42l42->regmap, CS42L42_DET_INT1_MASK,
CS42L42_TIP_SENSE_UNPLUG_MASK |
CS42L42_TIP_SENSE_PLUG_MASK |
CS42L42_HSBIAS_SENSE_MASK,
(1 << CS42L42_TIP_SENSE_UNPLUG_SHIFT) |
(1 << CS42L42_TIP_SENSE_PLUG_SHIFT) |
(1 << CS42L42_HSBIAS_SENSE_SHIFT));
regmap_update_bits(cs42l42->regmap, CS42L42_DET_INT2_MASK,
CS42L42_M_DETECT_TF_MASK |
CS42L42_M_DETECT_FT_MASK |
CS42L42_M_HSBIAS_HIZ_MASK |
CS42L42_M_SHORT_RLS_MASK |
CS42L42_M_SHORT_DET_MASK,
(1 << CS42L42_M_DETECT_TF_SHIFT) |
(1 << CS42L42_M_DETECT_FT_SHIFT) |
(1 << CS42L42_M_HSBIAS_HIZ_SHIFT) |
(1 << CS42L42_M_SHORT_RLS_SHIFT) |
(1 << CS42L42_M_SHORT_DET_SHIFT));
regmap_update_bits(cs42l42->regmap, CS42L42_VPMON_INT_MASK,
CS42L42_VPMON_MASK,
(1 << CS42L42_VPMON_SHIFT));
regmap_update_bits(cs42l42->regmap, CS42L42_PLL_LOCK_INT_MASK,
CS42L42_PLL_LOCK_MASK,
(1 << CS42L42_PLL_LOCK_SHIFT));
regmap_update_bits(cs42l42->regmap, CS42L42_TSRS_PLUG_INT_MASK,
CS42L42_RS_PLUG_MASK |
CS42L42_RS_UNPLUG_MASK |
CS42L42_TS_PLUG_MASK |
CS42L42_TS_UNPLUG_MASK,
(1 << CS42L42_RS_PLUG_SHIFT) |
(1 << CS42L42_RS_UNPLUG_SHIFT) |
(0 << CS42L42_TS_PLUG_SHIFT) |
(0 << CS42L42_TS_UNPLUG_SHIFT));
}
static void cs42l42_setup_hs_type_detect(struct cs42l42_private *cs42l42)
{
unsigned int reg;
cs42l42->hs_type = CS42L42_PLUG_INVALID;
regmap_update_bits(cs42l42->regmap, CS42L42_MIC_DET_CTL1,
CS42L42_LATCH_TO_VP_MASK |
CS42L42_EVENT_STAT_SEL_MASK |
CS42L42_HS_DET_LEVEL_MASK,
(1 << CS42L42_LATCH_TO_VP_SHIFT) |
(0 << CS42L42_EVENT_STAT_SEL_SHIFT) |
(cs42l42->bias_thresholds[0] <<
CS42L42_HS_DET_LEVEL_SHIFT));
regmap_update_bits(cs42l42->regmap,
CS42L42_HS_CLAMP_DISABLE,
CS42L42_HS_CLAMP_DISABLE_MASK,
(1 << CS42L42_HS_CLAMP_DISABLE_SHIFT));
regmap_update_bits(cs42l42->regmap, CS42L42_TIPSENSE_CTL,
CS42L42_TIP_SENSE_CTRL_MASK |
CS42L42_TIP_SENSE_INV_MASK |
CS42L42_TIP_SENSE_DEBOUNCE_MASK,
(3 << CS42L42_TIP_SENSE_CTRL_SHIFT) |
(0 << CS42L42_TIP_SENSE_INV_SHIFT) |
(2 << CS42L42_TIP_SENSE_DEBOUNCE_SHIFT));
regmap_read(cs42l42->regmap,
CS42L42_TSRS_PLUG_STATUS,
&reg);
cs42l42->plug_state = (((char) reg) &
(CS42L42_TS_PLUG_MASK | CS42L42_TS_UNPLUG_MASK)) >>
CS42L42_TS_PLUG_SHIFT;
}
static int cs42l42_handle_device_data(struct i2c_client *i2c_client,
struct cs42l42_private *cs42l42)
{
struct device_node *np = i2c_client->dev.of_node;
unsigned int val;
unsigned int thresholds[CS42L42_NUM_BIASES];
int ret;
int i;
ret = of_property_read_u32(np, "cirrus,ts-inv", &val);
if (!ret) {
switch (val) {
case CS42L42_TS_INV_EN:
case CS42L42_TS_INV_DIS:
cs42l42->ts_inv = val;
break;
default:
dev_err(&i2c_client->dev,
"Wrong cirrus,ts-inv DT value %d\n",
val);
cs42l42->ts_inv = CS42L42_TS_INV_DIS;
}
} else {
cs42l42->ts_inv = CS42L42_TS_INV_DIS;
}
regmap_update_bits(cs42l42->regmap, CS42L42_TSENSE_CTL,
CS42L42_TS_INV_MASK,
(cs42l42->ts_inv << CS42L42_TS_INV_SHIFT));
ret = of_property_read_u32(np, "cirrus,ts-dbnc-rise", &val);
if (!ret) {
switch (val) {
case CS42L42_TS_DBNCE_0:
case CS42L42_TS_DBNCE_125:
case CS42L42_TS_DBNCE_250:
case CS42L42_TS_DBNCE_500:
case CS42L42_TS_DBNCE_750:
case CS42L42_TS_DBNCE_1000:
case CS42L42_TS_DBNCE_1250:
case CS42L42_TS_DBNCE_1500:
cs42l42->ts_dbnc_rise = val;
break;
default:
dev_err(&i2c_client->dev,
"Wrong cirrus,ts-dbnc-rise DT value %d\n",
val);
cs42l42->ts_dbnc_rise = CS42L42_TS_DBNCE_1000;
}
} else {
cs42l42->ts_dbnc_rise = CS42L42_TS_DBNCE_1000;
}
regmap_update_bits(cs42l42->regmap, CS42L42_TSENSE_CTL,
CS42L42_TS_RISE_DBNCE_TIME_MASK,
(cs42l42->ts_dbnc_rise <<
CS42L42_TS_RISE_DBNCE_TIME_SHIFT));
ret = of_property_read_u32(np, "cirrus,ts-dbnc-fall", &val);
if (!ret) {
switch (val) {
case CS42L42_TS_DBNCE_0:
case CS42L42_TS_DBNCE_125:
case CS42L42_TS_DBNCE_250:
case CS42L42_TS_DBNCE_500:
case CS42L42_TS_DBNCE_750:
case CS42L42_TS_DBNCE_1000:
case CS42L42_TS_DBNCE_1250:
case CS42L42_TS_DBNCE_1500:
cs42l42->ts_dbnc_fall = val;
break;
default:
dev_err(&i2c_client->dev,
"Wrong cirrus,ts-dbnc-fall DT value %d\n",
val);
cs42l42->ts_dbnc_fall = CS42L42_TS_DBNCE_0;
}
} else {
cs42l42->ts_dbnc_fall = CS42L42_TS_DBNCE_0;
}
regmap_update_bits(cs42l42->regmap, CS42L42_TSENSE_CTL,
CS42L42_TS_FALL_DBNCE_TIME_MASK,
(cs42l42->ts_dbnc_fall <<
CS42L42_TS_FALL_DBNCE_TIME_SHIFT));
ret = of_property_read_u32(np, "cirrus,btn-det-init-dbnce", &val);
if (!ret) {
if ((val >= CS42L42_BTN_DET_INIT_DBNCE_MIN) &&
(val <= CS42L42_BTN_DET_INIT_DBNCE_MAX))
cs42l42->btn_det_init_dbnce = val;
else {
dev_err(&i2c_client->dev,
"Wrong cirrus,btn-det-init-dbnce DT value %d\n",
val);
cs42l42->btn_det_init_dbnce =
CS42L42_BTN_DET_INIT_DBNCE_DEFAULT;
}
} else {
cs42l42->btn_det_init_dbnce =
CS42L42_BTN_DET_INIT_DBNCE_DEFAULT;
}
ret = of_property_read_u32(np, "cirrus,btn-det-event-dbnce", &val);
if (!ret) {
if ((val >= CS42L42_BTN_DET_EVENT_DBNCE_MIN) &&
(val <= CS42L42_BTN_DET_EVENT_DBNCE_MAX))
cs42l42->btn_det_event_dbnce = val;
else {
dev_err(&i2c_client->dev,
"Wrong cirrus,btn-det-event-dbnce DT value %d\n", val);
cs42l42->btn_det_event_dbnce =
CS42L42_BTN_DET_EVENT_DBNCE_DEFAULT;
}
} else {
cs42l42->btn_det_event_dbnce =
CS42L42_BTN_DET_EVENT_DBNCE_DEFAULT;
}
ret = of_property_read_u32_array(np, "cirrus,bias-lvls",
(u32 *)thresholds, CS42L42_NUM_BIASES);
if (!ret) {
for (i = 0; i < CS42L42_NUM_BIASES; i++) {
if ((thresholds[i] >= CS42L42_HS_DET_LEVEL_MIN) &&
(thresholds[i] <= CS42L42_HS_DET_LEVEL_MAX))
cs42l42->bias_thresholds[i] = thresholds[i];
else {
dev_err(&i2c_client->dev,
"Wrong cirrus,bias-lvls[%d] DT value %d\n", i,
thresholds[i]);
cs42l42->bias_thresholds[i] =
threshold_defaults[i];
}
}
} else {
for (i = 0; i < CS42L42_NUM_BIASES; i++)
cs42l42->bias_thresholds[i] = threshold_defaults[i];
}
ret = of_property_read_u32(np, "cirrus,hs-bias-ramp-rate", &val);
if (!ret) {
switch (val) {
case CS42L42_HSBIAS_RAMP_FAST_RISE_SLOW_FALL:
cs42l42->hs_bias_ramp_rate = val;
cs42l42->hs_bias_ramp_time = CS42L42_HSBIAS_RAMP_TIME0;
break;
case CS42L42_HSBIAS_RAMP_FAST:
cs42l42->hs_bias_ramp_rate = val;
cs42l42->hs_bias_ramp_time = CS42L42_HSBIAS_RAMP_TIME1;
break;
case CS42L42_HSBIAS_RAMP_SLOW:
cs42l42->hs_bias_ramp_rate = val;
cs42l42->hs_bias_ramp_time = CS42L42_HSBIAS_RAMP_TIME2;
break;
case CS42L42_HSBIAS_RAMP_SLOWEST:
cs42l42->hs_bias_ramp_rate = val;
cs42l42->hs_bias_ramp_time = CS42L42_HSBIAS_RAMP_TIME3;
break;
default:
dev_err(&i2c_client->dev,
"Wrong cirrus,hs-bias-ramp-rate DT value %d\n",
val);
cs42l42->hs_bias_ramp_rate = CS42L42_HSBIAS_RAMP_SLOW;
cs42l42->hs_bias_ramp_time = CS42L42_HSBIAS_RAMP_TIME2;
}
} else {
cs42l42->hs_bias_ramp_rate = CS42L42_HSBIAS_RAMP_SLOW;
cs42l42->hs_bias_ramp_time = CS42L42_HSBIAS_RAMP_TIME2;
}
regmap_update_bits(cs42l42->regmap, CS42L42_HS_BIAS_CTL,
CS42L42_HSBIAS_RAMP_MASK,
(cs42l42->hs_bias_ramp_rate <<
CS42L42_HSBIAS_RAMP_SHIFT));
return 0;
}
static int cs42l42_i2c_probe(struct i2c_client *i2c_client,
const struct i2c_device_id *id)
{
struct cs42l42_private *cs42l42;
int ret, i;
unsigned int devid = 0;
unsigned int reg;
cs42l42 = devm_kzalloc(&i2c_client->dev, sizeof(struct cs42l42_private),
GFP_KERNEL);
if (!cs42l42)
return -ENOMEM;
i2c_set_clientdata(i2c_client, cs42l42);
cs42l42->regmap = devm_regmap_init_i2c(i2c_client, &cs42l42_regmap);
if (IS_ERR(cs42l42->regmap)) {
ret = PTR_ERR(cs42l42->regmap);
dev_err(&i2c_client->dev, "regmap_init() failed: %d\n", ret);
return ret;
}
for (i = 0; i < ARRAY_SIZE(cs42l42->supplies); i++)
cs42l42->supplies[i].supply = cs42l42_supply_names[i];
ret = devm_regulator_bulk_get(&i2c_client->dev,
ARRAY_SIZE(cs42l42->supplies),
cs42l42->supplies);
if (ret != 0) {
dev_err(&i2c_client->dev,
"Failed to request supplies: %d\n", ret);
return ret;
}
ret = regulator_bulk_enable(ARRAY_SIZE(cs42l42->supplies),
cs42l42->supplies);
if (ret != 0) {
dev_err(&i2c_client->dev,
"Failed to enable supplies: %d\n", ret);
return ret;
}
cs42l42->reset_gpio = devm_gpiod_get_optional(&i2c_client->dev,
"reset", GPIOD_OUT_LOW);
if (IS_ERR(cs42l42->reset_gpio))
return PTR_ERR(cs42l42->reset_gpio);
if (cs42l42->reset_gpio) {
dev_dbg(&i2c_client->dev, "Found reset GPIO\n");
gpiod_set_value_cansleep(cs42l42->reset_gpio, 1);
}
mdelay(3);
ret = devm_request_threaded_irq(&i2c_client->dev,
i2c_client->irq,
NULL, cs42l42_irq_thread,
IRQF_ONESHOT | IRQF_TRIGGER_LOW,
"cs42l42", cs42l42);
if (ret != 0)
dev_err(&i2c_client->dev,
"Failed to request IRQ: %d\n", ret);
ret = regmap_read(cs42l42->regmap, CS42L42_DEVID_AB, &reg);
devid = (reg & 0xFF) << 12;
ret = regmap_read(cs42l42->regmap, CS42L42_DEVID_CD, &reg);
devid |= (reg & 0xFF) << 4;
ret = regmap_read(cs42l42->regmap, CS42L42_DEVID_E, &reg);
devid |= (reg & 0xF0) >> 4;
if (devid != CS42L42_CHIP_ID) {
ret = -ENODEV;
dev_err(&i2c_client->dev,
"CS42L42 Device ID (%X). Expected %X\n",
devid, CS42L42_CHIP_ID);
return ret;
}
ret = regmap_read(cs42l42->regmap, CS42L42_REVID, &reg);
if (ret < 0) {
dev_err(&i2c_client->dev, "Get Revision ID failed\n");
return ret;
}
dev_info(&i2c_client->dev,
"Cirrus Logic CS42L42, Revision: %02X\n", reg & 0xFF);
regmap_update_bits(cs42l42->regmap, CS42L42_PWR_CTL1,
CS42L42_ASP_DAO_PDN_MASK |
CS42L42_ASP_DAI_PDN_MASK |
CS42L42_MIXER_PDN_MASK |
CS42L42_EQ_PDN_MASK |
CS42L42_HP_PDN_MASK |
CS42L42_ADC_PDN_MASK |
CS42L42_PDN_ALL_MASK,
(1 << CS42L42_ASP_DAO_PDN_SHIFT) |
(1 << CS42L42_ASP_DAI_PDN_SHIFT) |
(1 << CS42L42_MIXER_PDN_SHIFT) |
(1 << CS42L42_EQ_PDN_SHIFT) |
(1 << CS42L42_HP_PDN_SHIFT) |
(1 << CS42L42_ADC_PDN_SHIFT) |
(0 << CS42L42_PDN_ALL_SHIFT));
if (i2c_client->dev.of_node) {
ret = cs42l42_handle_device_data(i2c_client, cs42l42);
if (ret != 0)
return ret;
}
cs42l42_setup_hs_type_detect(cs42l42);
cs42l42_set_interrupt_masks(cs42l42);
ret = snd_soc_register_codec(&i2c_client->dev,
&soc_codec_dev_cs42l42, &cs42l42_dai, 1);
if (ret < 0)
goto err_disable;
return 0;
err_disable:
regulator_bulk_disable(ARRAY_SIZE(cs42l42->supplies),
cs42l42->supplies);
return ret;
}
static int cs42l42_i2c_remove(struct i2c_client *i2c_client)
{
struct cs42l42_private *cs42l42 = i2c_get_clientdata(i2c_client);
snd_soc_unregister_codec(&i2c_client->dev);
gpiod_set_value_cansleep(cs42l42->reset_gpio, 0);
return 0;
}
static int cs42l42_runtime_suspend(struct device *dev)
{
struct cs42l42_private *cs42l42 = dev_get_drvdata(dev);
regcache_cache_only(cs42l42->regmap, true);
regcache_mark_dirty(cs42l42->regmap);
gpiod_set_value_cansleep(cs42l42->reset_gpio, 0);
regulator_bulk_disable(ARRAY_SIZE(cs42l42->supplies),
cs42l42->supplies);
return 0;
}
static int cs42l42_runtime_resume(struct device *dev)
{
struct cs42l42_private *cs42l42 = dev_get_drvdata(dev);
int ret;
ret = regulator_bulk_enable(ARRAY_SIZE(cs42l42->supplies),
cs42l42->supplies);
if (ret != 0) {
dev_err(dev, "Failed to enable supplies: %d\n",
ret);
return ret;
}
gpiod_set_value_cansleep(cs42l42->reset_gpio, 1);
regcache_cache_only(cs42l42->regmap, false);
regcache_sync(cs42l42->regmap);
return 0;
}
