static int rt5645_reset(struct snd_soc_codec *codec)
{
return snd_soc_write(codec, RT5645_RESET, 0);
}
static bool rt5645_volatile_register(struct device *dev, unsigned int reg)
{
int i;
for (i = 0; i < ARRAY_SIZE(rt5645_ranges); i++) {
if (reg >= rt5645_ranges[i].range_min &&
reg <= rt5645_ranges[i].range_max) {
return true;
}
}
switch (reg) {
case RT5645_RESET:
case RT5645_PRIV_DATA:
case RT5645_IN1_CTRL1:
case RT5645_IN1_CTRL2:
case RT5645_IN1_CTRL3:
case RT5645_A_JD_CTRL1:
case RT5645_ADC_EQ_CTRL1:
case RT5645_EQ_CTRL1:
case RT5645_ALC_CTRL_1:
case RT5645_IRQ_CTRL2:
case RT5645_IRQ_CTRL3:
case RT5645_INT_IRQ_ST:
case RT5645_IL_CMD:
case RT5650_4BTN_IL_CMD1:
case RT5645_VENDOR_ID:
case RT5645_VENDOR_ID1:
case RT5645_VENDOR_ID2:
return true;
default:
return false;
}
}
static bool rt5645_readable_register(struct device *dev, unsigned int reg)
{
int i;
for (i = 0; i < ARRAY_SIZE(rt5645_ranges); i++) {
if (reg >= rt5645_ranges[i].range_min &&
reg <= rt5645_ranges[i].range_max) {
return true;
}
}
switch (reg) {
case RT5645_RESET:
case RT5645_SPK_VOL:
case RT5645_HP_VOL:
case RT5645_LOUT1:
case RT5645_IN1_CTRL1:
case RT5645_IN1_CTRL2:
case RT5645_IN1_CTRL3:
case RT5645_IN2_CTRL:
case RT5645_INL1_INR1_VOL:
case RT5645_SPK_FUNC_LIM:
case RT5645_ADJ_HPF_CTRL:
case RT5645_DAC1_DIG_VOL:
case RT5645_DAC2_DIG_VOL:
case RT5645_DAC_CTRL:
case RT5645_STO1_ADC_DIG_VOL:
case RT5645_MONO_ADC_DIG_VOL:
case RT5645_ADC_BST_VOL1:
case RT5645_ADC_BST_VOL2:
case RT5645_STO1_ADC_MIXER:
case RT5645_MONO_ADC_MIXER:
case RT5645_AD_DA_MIXER:
case RT5645_STO_DAC_MIXER:
case RT5645_MONO_DAC_MIXER:
case RT5645_DIG_MIXER:
case RT5650_A_DAC_SOUR:
case RT5645_DIG_INF1_DATA:
case RT5645_PDM_OUT_CTRL:
case RT5645_REC_L1_MIXER:
case RT5645_REC_L2_MIXER:
case RT5645_REC_R1_MIXER:
case RT5645_REC_R2_MIXER:
case RT5645_HPMIXL_CTRL:
case RT5645_HPOMIXL_CTRL:
case RT5645_HPMIXR_CTRL:
case RT5645_HPOMIXR_CTRL:
case RT5645_HPO_MIXER:
case RT5645_SPK_L_MIXER:
case RT5645_SPK_R_MIXER:
case RT5645_SPO_MIXER:
case RT5645_SPO_CLSD_RATIO:
case RT5645_OUT_L1_MIXER:
case RT5645_OUT_R1_MIXER:
case RT5645_OUT_L_GAIN1:
case RT5645_OUT_L_GAIN2:
case RT5645_OUT_R_GAIN1:
case RT5645_OUT_R_GAIN2:
case RT5645_LOUT_MIXER:
case RT5645_HAPTIC_CTRL1:
case RT5645_HAPTIC_CTRL2:
case RT5645_HAPTIC_CTRL3:
case RT5645_HAPTIC_CTRL4:
case RT5645_HAPTIC_CTRL5:
case RT5645_HAPTIC_CTRL6:
case RT5645_HAPTIC_CTRL7:
case RT5645_HAPTIC_CTRL8:
case RT5645_HAPTIC_CTRL9:
case RT5645_HAPTIC_CTRL10:
case RT5645_PWR_DIG1:
case RT5645_PWR_DIG2:
case RT5645_PWR_ANLG1:
case RT5645_PWR_ANLG2:
case RT5645_PWR_MIXER:
case RT5645_PWR_VOL:
case RT5645_PRIV_INDEX:
case RT5645_PRIV_DATA:
case RT5645_I2S1_SDP:
case RT5645_I2S2_SDP:
case RT5645_ADDA_CLK1:
case RT5645_ADDA_CLK2:
case RT5645_DMIC_CTRL1:
case RT5645_DMIC_CTRL2:
case RT5645_TDM_CTRL_1:
case RT5645_TDM_CTRL_2:
case RT5645_TDM_CTRL_3:
case RT5645_GLB_CLK:
case RT5645_PLL_CTRL1:
case RT5645_PLL_CTRL2:
case RT5645_ASRC_1:
case RT5645_ASRC_2:
case RT5645_ASRC_3:
case RT5645_ASRC_4:
case RT5645_DEPOP_M1:
case RT5645_DEPOP_M2:
case RT5645_DEPOP_M3:
case RT5645_MICBIAS:
case RT5645_A_JD_CTRL1:
case RT5645_VAD_CTRL4:
case RT5645_CLSD_OUT_CTRL:
case RT5645_ADC_EQ_CTRL1:
case RT5645_ADC_EQ_CTRL2:
case RT5645_EQ_CTRL1:
case RT5645_EQ_CTRL2:
case RT5645_ALC_CTRL_1:
case RT5645_ALC_CTRL_2:
case RT5645_ALC_CTRL_3:
case RT5645_ALC_CTRL_4:
case RT5645_ALC_CTRL_5:
case RT5645_JD_CTRL:
case RT5645_IRQ_CTRL1:
case RT5645_IRQ_CTRL2:
case RT5645_IRQ_CTRL3:
case RT5645_INT_IRQ_ST:
case RT5645_GPIO_CTRL1:
case RT5645_GPIO_CTRL2:
case RT5645_GPIO_CTRL3:
case RT5645_BASS_BACK:
case RT5645_MP3_PLUS1:
case RT5645_MP3_PLUS2:
case RT5645_ADJ_HPF1:
case RT5645_ADJ_HPF2:
case RT5645_HP_CALIB_AMP_DET:
case RT5645_SV_ZCD1:
case RT5645_SV_ZCD2:
case RT5645_IL_CMD:
case RT5645_IL_CMD2:
case RT5645_IL_CMD3:
case RT5650_4BTN_IL_CMD1:
case RT5650_4BTN_IL_CMD2:
case RT5645_DRC1_HL_CTRL1:
case RT5645_DRC2_HL_CTRL1:
case RT5645_ADC_MONO_HP_CTRL1:
case RT5645_ADC_MONO_HP_CTRL2:
case RT5645_DRC2_CTRL1:
case RT5645_DRC2_CTRL2:
case RT5645_DRC2_CTRL3:
case RT5645_DRC2_CTRL4:
case RT5645_DRC2_CTRL5:
case RT5645_JD_CTRL3:
case RT5645_JD_CTRL4:
case RT5645_GEN_CTRL1:
case RT5645_GEN_CTRL2:
case RT5645_GEN_CTRL3:
case RT5645_VENDOR_ID:
case RT5645_VENDOR_ID1:
case RT5645_VENDOR_ID2:
return true;
default:
return false;
}
}
static int set_dmic_clk(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
struct rt5645_priv *rt5645 = snd_soc_codec_get_drvdata(codec);
int idx = -EINVAL;
idx = rl6231_calc_dmic_clk(rt5645->sysclk);
if (idx < 0)
dev_err(codec->dev, "Failed to set DMIC clock\n");
else
snd_soc_update_bits(codec, RT5645_DMIC_CTRL1,
RT5645_DMIC_CLK_MASK, idx << RT5645_DMIC_CLK_SFT);
return idx;
}
static int is_sys_clk_from_pll(struct snd_soc_dapm_widget *source,
struct snd_soc_dapm_widget *sink)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(source->dapm);
unsigned int val;
val = snd_soc_read(codec, RT5645_GLB_CLK);
val &= RT5645_SCLK_SRC_MASK;
if (val == RT5645_SCLK_SRC_PLL1)
return 1;
else
return 0;
}
static int is_using_asrc(struct snd_soc_dapm_widget *source,
struct snd_soc_dapm_widget *sink)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(source->dapm);
unsigned int reg, shift, val;
switch (source->shift) {
case 0:
reg = RT5645_ASRC_3;
shift = 0;
break;
case 1:
reg = RT5645_ASRC_3;
shift = 4;
break;
case 3:
reg = RT5645_ASRC_2;
shift = 0;
break;
case 8:
reg = RT5645_ASRC_2;
shift = 4;
break;
case 9:
reg = RT5645_ASRC_2;
shift = 8;
break;
case 10:
reg = RT5645_ASRC_2;
shift = 12;
break;
default:
return 0;
}
val = (snd_soc_read(codec, reg) >> shift) & 0xf;
switch (val) {
case 1:
case 2:
case 3:
case 4:
return 1;
default:
return 0;
}
}
int rt5645_sel_asrc_clk_src(struct snd_soc_codec *codec,
unsigned int filter_mask, unsigned int clk_src)
{
unsigned int asrc2_mask = 0;
unsigned int asrc2_value = 0;
unsigned int asrc3_mask = 0;
unsigned int asrc3_value = 0;
switch (clk_src) {
case RT5645_CLK_SEL_SYS:
case RT5645_CLK_SEL_I2S1_ASRC:
case RT5645_CLK_SEL_I2S2_ASRC:
case RT5645_CLK_SEL_SYS2:
break;
default:
return -EINVAL;
}
if (filter_mask & RT5645_DA_STEREO_FILTER) {
asrc2_mask |= RT5645_DA_STO_CLK_SEL_MASK;
asrc2_value = (asrc2_value & ~RT5645_DA_STO_CLK_SEL_MASK)
| (clk_src << RT5645_DA_STO_CLK_SEL_SFT);
}
if (filter_mask & RT5645_DA_MONO_L_FILTER) {
asrc2_mask |= RT5645_DA_MONOL_CLK_SEL_MASK;
asrc2_value = (asrc2_value & ~RT5645_DA_MONOL_CLK_SEL_MASK)
| (clk_src << RT5645_DA_MONOL_CLK_SEL_SFT);
}
if (filter_mask & RT5645_DA_MONO_R_FILTER) {
asrc2_mask |= RT5645_DA_MONOR_CLK_SEL_MASK;
asrc2_value = (asrc2_value & ~RT5645_DA_MONOR_CLK_SEL_MASK)
| (clk_src << RT5645_DA_MONOR_CLK_SEL_SFT);
}
if (filter_mask & RT5645_AD_STEREO_FILTER) {
asrc2_mask |= RT5645_AD_STO1_CLK_SEL_MASK;
asrc2_value = (asrc2_value & ~RT5645_AD_STO1_CLK_SEL_MASK)
| (clk_src << RT5645_AD_STO1_CLK_SEL_SFT);
}
if (filter_mask & RT5645_AD_MONO_L_FILTER) {
asrc3_mask |= RT5645_AD_MONOL_CLK_SEL_MASK;
asrc3_value = (asrc3_value & ~RT5645_AD_MONOL_CLK_SEL_MASK)
| (clk_src << RT5645_AD_MONOL_CLK_SEL_SFT);
}
if (filter_mask & RT5645_AD_MONO_R_FILTER) {
asrc3_mask |= RT5645_AD_MONOR_CLK_SEL_MASK;
asrc3_value = (asrc3_value & ~RT5645_AD_MONOR_CLK_SEL_MASK)
| (clk_src << RT5645_AD_MONOR_CLK_SEL_SFT);
}
if (asrc2_mask)
snd_soc_update_bits(codec, RT5645_ASRC_2,
asrc2_mask, asrc2_value);
if (asrc3_mask)
snd_soc_update_bits(codec, RT5645_ASRC_3,
asrc3_mask, asrc3_value);
return 0;
}
static void hp_amp_power(struct snd_soc_codec *codec, int on)
{
static int hp_amp_power_count;
struct rt5645_priv *rt5645 = snd_soc_codec_get_drvdata(codec);
if (on) {
if (hp_amp_power_count <= 0) {
snd_soc_update_bits(codec, RT5645_DEPOP_M2,
RT5645_DEPOP_MASK, RT5645_DEPOP_MAN);
snd_soc_write(codec, RT5645_DEPOP_M1, 0x000d);
regmap_write(rt5645->regmap, RT5645_PR_BASE +
RT5645_HP_DCC_INT1, 0x9f01);
mdelay(150);
snd_soc_update_bits(codec, RT5645_PWR_ANLG1,
RT5645_PWR_FV1 | RT5645_PWR_FV2 , 0);
snd_soc_update_bits(codec, RT5645_PWR_VOL,
RT5645_PWR_HV_L | RT5645_PWR_HV_R,
RT5645_PWR_HV_L | RT5645_PWR_HV_R);
snd_soc_update_bits(codec, RT5645_PWR_ANLG1,
RT5645_PWR_HP_L | RT5645_PWR_HP_R |
RT5645_PWR_HA,
RT5645_PWR_HP_L | RT5645_PWR_HP_R |
RT5645_PWR_HA);
mdelay(5);
snd_soc_update_bits(codec, RT5645_PWR_ANLG1,
RT5645_PWR_FV1 | RT5645_PWR_FV2,
RT5645_PWR_FV1 | RT5645_PWR_FV2);
snd_soc_update_bits(codec, RT5645_DEPOP_M1,
RT5645_HP_CO_MASK | RT5645_HP_SG_MASK,
RT5645_HP_CO_EN | RT5645_HP_SG_EN);
regmap_write(rt5645->regmap, RT5645_PR_BASE +
0x14, 0x1aaa);
regmap_write(rt5645->regmap, RT5645_PR_BASE +
0x24, 0x0430);
}
hp_amp_power_count++;
} else {
hp_amp_power_count--;
if (hp_amp_power_count <= 0) {
snd_soc_update_bits(codec, RT5645_DEPOP_M1,
RT5645_HP_SG_MASK | RT5645_HP_L_SMT_MASK |
RT5645_HP_R_SMT_MASK, RT5645_HP_SG_DIS |
RT5645_HP_L_SMT_DIS | RT5645_HP_R_SMT_DIS);
snd_soc_write(codec, RT5645_DEPOP_M1, 0x0000);
snd_soc_update_bits(codec, RT5645_PWR_ANLG1,
RT5645_PWR_HP_L | RT5645_PWR_HP_R |
RT5645_PWR_HA, 0);
}
}
}
static int rt5645_hp_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
struct rt5645_priv *rt5645 = snd_soc_codec_get_drvdata(codec);
switch (event) {
case SND_SOC_DAPM_POST_PMU:
hp_amp_power(codec, 1);
if (rt5645->codec_type == CODEC_TYPE_RT5650) {
snd_soc_write(codec, RT5645_DEPOP_M3, 0x0737);
} else {
snd_soc_update_bits(codec, RT5645_DEPOP_M3,
RT5645_CP_FQ1_MASK | RT5645_CP_FQ2_MASK |
RT5645_CP_FQ3_MASK,
(RT5645_CP_FQ_192_KHZ << RT5645_CP_FQ1_SFT) |
(RT5645_CP_FQ_12_KHZ << RT5645_CP_FQ2_SFT) |
(RT5645_CP_FQ_192_KHZ << RT5645_CP_FQ3_SFT));
}
regmap_write(rt5645->regmap,
RT5645_PR_BASE + RT5645_MAMP_INT_REG2, 0xfc00);
snd_soc_update_bits(codec, RT5645_DEPOP_M1,
RT5645_SMT_TRIG_MASK, RT5645_SMT_TRIG_EN);
snd_soc_update_bits(codec, RT5645_DEPOP_M1,
RT5645_RSTN_MASK, RT5645_RSTN_EN);
snd_soc_update_bits(codec, RT5645_DEPOP_M1,
RT5645_RSTN_MASK | RT5645_HP_L_SMT_MASK |
RT5645_HP_R_SMT_MASK, RT5645_RSTN_DIS |
RT5645_HP_L_SMT_EN | RT5645_HP_R_SMT_EN);
msleep(40);
snd_soc_update_bits(codec, RT5645_DEPOP_M1,
RT5645_HP_SG_MASK | RT5645_HP_L_SMT_MASK |
RT5645_HP_R_SMT_MASK, RT5645_HP_SG_DIS |
RT5645_HP_L_SMT_DIS | RT5645_HP_R_SMT_DIS);
break;
case SND_SOC_DAPM_PRE_PMD:
if (rt5645->codec_type == CODEC_TYPE_RT5650) {
snd_soc_write(codec, RT5645_DEPOP_M3, 0x0737);
} else {
snd_soc_update_bits(codec, RT5645_DEPOP_M3,
RT5645_CP_FQ1_MASK | RT5645_CP_FQ2_MASK |
RT5645_CP_FQ3_MASK,
(RT5645_CP_FQ_96_KHZ << RT5645_CP_FQ1_SFT) |
(RT5645_CP_FQ_12_KHZ << RT5645_CP_FQ2_SFT) |
(RT5645_CP_FQ_96_KHZ << RT5645_CP_FQ3_SFT));
}
regmap_write(rt5645->regmap,
RT5645_PR_BASE + RT5645_MAMP_INT_REG2, 0xfc00);
snd_soc_update_bits(codec, RT5645_DEPOP_M1,
RT5645_HP_SG_MASK, RT5645_HP_SG_EN);
snd_soc_update_bits(codec, RT5645_DEPOP_M1,
RT5645_RSTP_MASK, RT5645_RSTP_EN);
snd_soc_update_bits(codec, RT5645_DEPOP_M1,
RT5645_RSTP_MASK | RT5645_HP_L_SMT_MASK |
RT5645_HP_R_SMT_MASK, RT5645_RSTP_DIS |
RT5645_HP_L_SMT_EN | RT5645_HP_R_SMT_EN);
msleep(30);
hp_amp_power(codec, 0);
break;
default:
return 0;
}
return 0;
}
static int rt5645_spk_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
switch (event) {
case SND_SOC_DAPM_POST_PMU:
snd_soc_update_bits(codec, RT5645_PWR_DIG1,
RT5645_PWR_CLS_D | RT5645_PWR_CLS_D_R |
RT5645_PWR_CLS_D_L,
RT5645_PWR_CLS_D | RT5645_PWR_CLS_D_R |
RT5645_PWR_CLS_D_L);
break;
case SND_SOC_DAPM_PRE_PMD:
snd_soc_update_bits(codec, RT5645_PWR_DIG1,
RT5645_PWR_CLS_D | RT5645_PWR_CLS_D_R |
RT5645_PWR_CLS_D_L, 0);
break;
default:
return 0;
}
return 0;
}
static int rt5645_lout_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
switch (event) {
case SND_SOC_DAPM_POST_PMU:
hp_amp_power(codec, 1);
snd_soc_update_bits(codec, RT5645_PWR_ANLG1,
RT5645_PWR_LM, RT5645_PWR_LM);
snd_soc_update_bits(codec, RT5645_LOUT1,
RT5645_L_MUTE | RT5645_R_MUTE, 0);
break;
case SND_SOC_DAPM_PRE_PMD:
snd_soc_update_bits(codec, RT5645_LOUT1,
RT5645_L_MUTE | RT5645_R_MUTE,
RT5645_L_MUTE | RT5645_R_MUTE);
snd_soc_update_bits(codec, RT5645_PWR_ANLG1,
RT5645_PWR_LM, 0);
hp_amp_power(codec, 0);
break;
default:
return 0;
}
return 0;
}
static int rt5645_bst2_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
switch (event) {
case SND_SOC_DAPM_POST_PMU:
snd_soc_update_bits(codec, RT5645_PWR_ANLG2,
RT5645_PWR_BST2_P, RT5645_PWR_BST2_P);
break;
case SND_SOC_DAPM_PRE_PMD:
snd_soc_update_bits(codec, RT5645_PWR_ANLG2,
RT5645_PWR_BST2_P, 0);
break;
default:
return 0;
}
return 0;
}
static int rt5645_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params, struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct rt5645_priv *rt5645 = snd_soc_codec_get_drvdata(codec);
unsigned int val_len = 0, val_clk, mask_clk;
int pre_div, bclk_ms, frame_size;
rt5645->lrck[dai->id] = params_rate(params);
pre_div = rl6231_get_clk_info(rt5645->sysclk, rt5645->lrck[dai->id]);
if (pre_div < 0) {
dev_err(codec->dev, "Unsupported clock setting\n");
return -EINVAL;
}
frame_size = snd_soc_params_to_frame_size(params);
if (frame_size < 0) {
dev_err(codec->dev, "Unsupported frame size: %d\n", frame_size);
return -EINVAL;
}
bclk_ms = frame_size > 32;
rt5645->bclk[dai->id] = rt5645->lrck[dai->id] * (32 << bclk_ms);
dev_dbg(dai->dev, "bclk is %dHz and lrck is %dHz\n",
rt5645->bclk[dai->id], rt5645->lrck[dai->id]);
dev_dbg(dai->dev, "bclk_ms is %d and pre_div is %d for iis %d\n",
bclk_ms, pre_div, dai->id);
switch (params_width(params)) {
case 16:
break;
case 20:
val_len |= RT5645_I2S_DL_20;
break;
case 24:
val_len |= RT5645_I2S_DL_24;
break;
case 8:
val_len |= RT5645_I2S_DL_8;
break;
default:
return -EINVAL;
}
switch (dai->id) {
case RT5645_AIF1:
mask_clk = RT5645_I2S_BCLK_MS1_MASK | RT5645_I2S_PD1_MASK;
val_clk = bclk_ms << RT5645_I2S_BCLK_MS1_SFT |
pre_div << RT5645_I2S_PD1_SFT;
snd_soc_update_bits(codec, RT5645_I2S1_SDP,
RT5645_I2S_DL_MASK, val_len);
snd_soc_update_bits(codec, RT5645_ADDA_CLK1, mask_clk, val_clk);
break;
case RT5645_AIF2:
mask_clk = RT5645_I2S_BCLK_MS2_MASK | RT5645_I2S_PD2_MASK;
val_clk = bclk_ms << RT5645_I2S_BCLK_MS2_SFT |
pre_div << RT5645_I2S_PD2_SFT;
snd_soc_update_bits(codec, RT5645_I2S2_SDP,
RT5645_I2S_DL_MASK, val_len);
snd_soc_update_bits(codec, RT5645_ADDA_CLK1, mask_clk, val_clk);
break;
default:
dev_err(codec->dev, "Invalid dai->id: %d\n", dai->id);
return -EINVAL;
}
return 0;
}
static int rt5645_set_dai_fmt(struct snd_soc_dai *dai, unsigned int fmt)
{
struct snd_soc_codec *codec = dai->codec;
struct rt5645_priv *rt5645 = snd_soc_codec_get_drvdata(codec);
unsigned int reg_val = 0;
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBM_CFM:
rt5645->master[dai->id] = 1;
break;
case SND_SOC_DAIFMT_CBS_CFS:
reg_val |= RT5645_I2S_MS_S;
rt5645->master[dai->id] = 0;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
break;
case SND_SOC_DAIFMT_IB_NF:
reg_val |= RT5645_I2S_BP_INV;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
break;
case SND_SOC_DAIFMT_LEFT_J:
reg_val |= RT5645_I2S_DF_LEFT;
break;
case SND_SOC_DAIFMT_DSP_A:
reg_val |= RT5645_I2S_DF_PCM_A;
break;
case SND_SOC_DAIFMT_DSP_B:
reg_val |= RT5645_I2S_DF_PCM_B;
break;
default:
return -EINVAL;
}
switch (dai->id) {
case RT5645_AIF1:
snd_soc_update_bits(codec, RT5645_I2S1_SDP,
RT5645_I2S_MS_MASK | RT5645_I2S_BP_MASK |
RT5645_I2S_DF_MASK, reg_val);
break;
case RT5645_AIF2:
snd_soc_update_bits(codec, RT5645_I2S2_SDP,
RT5645_I2S_MS_MASK | RT5645_I2S_BP_MASK |
RT5645_I2S_DF_MASK, reg_val);
break;
default:
dev_err(codec->dev, "Invalid dai->id: %d\n", dai->id);
return -EINVAL;
}
return 0;
}
static int rt5645_set_dai_sysclk(struct snd_soc_dai *dai,
int clk_id, unsigned int freq, int dir)
{
struct snd_soc_codec *codec = dai->codec;
struct rt5645_priv *rt5645 = snd_soc_codec_get_drvdata(codec);
unsigned int reg_val = 0;
if (freq == rt5645->sysclk && clk_id == rt5645->sysclk_src)
return 0;
switch (clk_id) {
case RT5645_SCLK_S_MCLK:
reg_val |= RT5645_SCLK_SRC_MCLK;
break;
case RT5645_SCLK_S_PLL1:
reg_val |= RT5645_SCLK_SRC_PLL1;
break;
case RT5645_SCLK_S_RCCLK:
reg_val |= RT5645_SCLK_SRC_RCCLK;
break;
default:
dev_err(codec->dev, "Invalid clock id (%d)\n", clk_id);
return -EINVAL;
}
snd_soc_update_bits(codec, RT5645_GLB_CLK,
RT5645_SCLK_SRC_MASK, reg_val);
rt5645->sysclk = freq;
rt5645->sysclk_src = clk_id;
dev_dbg(dai->dev, "Sysclk is %dHz and clock id is %d\n", freq, clk_id);
return 0;
}
static int rt5645_set_dai_pll(struct snd_soc_dai *dai, int pll_id, int source,
unsigned int freq_in, unsigned int freq_out)
{
struct snd_soc_codec *codec = dai->codec;
struct rt5645_priv *rt5645 = snd_soc_codec_get_drvdata(codec);
struct rl6231_pll_code pll_code;
int ret;
if (source == rt5645->pll_src && freq_in == rt5645->pll_in &&
freq_out == rt5645->pll_out)
return 0;
if (!freq_in || !freq_out) {
dev_dbg(codec->dev, "PLL disabled\n");
rt5645->pll_in = 0;
rt5645->pll_out = 0;
snd_soc_update_bits(codec, RT5645_GLB_CLK,
RT5645_SCLK_SRC_MASK, RT5645_SCLK_SRC_MCLK);
return 0;
}
switch (source) {
case RT5645_PLL1_S_MCLK:
snd_soc_update_bits(codec, RT5645_GLB_CLK,
RT5645_PLL1_SRC_MASK, RT5645_PLL1_SRC_MCLK);
break;
case RT5645_PLL1_S_BCLK1:
case RT5645_PLL1_S_BCLK2:
switch (dai->id) {
case RT5645_AIF1:
snd_soc_update_bits(codec, RT5645_GLB_CLK,
RT5645_PLL1_SRC_MASK, RT5645_PLL1_SRC_BCLK1);
break;
case RT5645_AIF2:
snd_soc_update_bits(codec, RT5645_GLB_CLK,
RT5645_PLL1_SRC_MASK, RT5645_PLL1_SRC_BCLK2);
break;
default:
dev_err(codec->dev, "Invalid dai->id: %d\n", dai->id);
return -EINVAL;
}
break;
default:
dev_err(codec->dev, "Unknown PLL source %d\n", source);
return -EINVAL;
}
ret = rl6231_pll_calc(freq_in, freq_out, &pll_code);
if (ret < 0) {
dev_err(codec->dev, "Unsupport input clock %d\n", freq_in);
return ret;
}
dev_dbg(codec->dev, "bypass=%d m=%d n=%d k=%d\n",
pll_code.m_bp, (pll_code.m_bp ? 0 : pll_code.m_code),
pll_code.n_code, pll_code.k_code);
snd_soc_write(codec, RT5645_PLL_CTRL1,
pll_code.n_code << RT5645_PLL_N_SFT | pll_code.k_code);
snd_soc_write(codec, RT5645_PLL_CTRL2,
(pll_code.m_bp ? 0 : pll_code.m_code) << RT5645_PLL_M_SFT |
pll_code.m_bp << RT5645_PLL_M_BP_SFT);
rt5645->pll_in = freq_in;
rt5645->pll_out = freq_out;
rt5645->pll_src = source;
return 0;
}
static int rt5645_set_tdm_slot(struct snd_soc_dai *dai, unsigned int tx_mask,
unsigned int rx_mask, int slots, int slot_width)
{
struct snd_soc_codec *codec = dai->codec;
unsigned int val = 0;
if (rx_mask || tx_mask) {
val |= (1 << 14);
snd_soc_update_bits(codec, RT5645_BASS_BACK,
RT5645_G_BB_BST_MASK, RT5645_G_BB_BST_25DB);
}
switch (slots) {
case 4:
val |= (1 << 12);
break;
case 6:
val |= (2 << 12);
break;
case 8:
val |= (3 << 12);
break;
case 2:
default:
break;
}
switch (slot_width) {
case 20:
val |= (1 << 10);
break;
case 24:
val |= (2 << 10);
break;
case 32:
val |= (3 << 10);
break;
case 16:
default:
break;
}
snd_soc_update_bits(codec, RT5645_TDM_CTRL_1, 0x7c00, val);
return 0;
}
static int rt5645_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
switch (level) {
case SND_SOC_BIAS_PREPARE:
if (SND_SOC_BIAS_STANDBY == codec->dapm.bias_level) {
snd_soc_update_bits(codec, RT5645_PWR_ANLG1,
RT5645_PWR_VREF1 | RT5645_PWR_MB |
RT5645_PWR_BG | RT5645_PWR_VREF2,
RT5645_PWR_VREF1 | RT5645_PWR_MB |
RT5645_PWR_BG | RT5645_PWR_VREF2);
mdelay(10);
snd_soc_update_bits(codec, RT5645_PWR_ANLG1,
RT5645_PWR_FV1 | RT5645_PWR_FV2,
RT5645_PWR_FV1 | RT5645_PWR_FV2);
snd_soc_update_bits(codec, RT5645_GEN_CTRL1,
RT5645_DIG_GATE_CTRL, RT5645_DIG_GATE_CTRL);
}
break;
case SND_SOC_BIAS_STANDBY:
snd_soc_update_bits(codec, RT5645_PWR_ANLG1,
RT5645_PWR_VREF1 | RT5645_PWR_MB |
RT5645_PWR_BG | RT5645_PWR_VREF2,
RT5645_PWR_VREF1 | RT5645_PWR_MB |
RT5645_PWR_BG | RT5645_PWR_VREF2);
snd_soc_update_bits(codec, RT5645_PWR_ANLG1,
RT5645_PWR_FV1 | RT5645_PWR_FV2,
RT5645_PWR_FV1 | RT5645_PWR_FV2);
break;
case SND_SOC_BIAS_OFF:
snd_soc_write(codec, RT5645_DEPOP_M2, 0x1100);
snd_soc_write(codec, RT5645_GEN_CTRL1, 0x0128);
snd_soc_update_bits(codec, RT5645_PWR_ANLG1,
RT5645_PWR_VREF1 | RT5645_PWR_MB |
RT5645_PWR_BG | RT5645_PWR_VREF2 |
RT5645_PWR_FV1 | RT5645_PWR_FV2, 0x0);
break;
default:
break;
}
codec->dapm.bias_level = level;
return 0;
}
static int rt5645_jack_detect(struct snd_soc_codec *codec)
{
struct rt5645_priv *rt5645 = snd_soc_codec_get_drvdata(codec);
int gpio_state, jack_type = 0;
unsigned int val;
if (!gpio_is_valid(rt5645->pdata.hp_det_gpio)) {
dev_err(codec->dev, "invalid gpio\n");
return -EINVAL;
}
gpio_state = gpio_get_value(rt5645->pdata.hp_det_gpio);
dev_dbg(codec->dev, "gpio = %d(%d)\n", rt5645->pdata.hp_det_gpio,
gpio_state);
if ((rt5645->pdata.gpio_hp_det_active_high && gpio_state) ||
(!rt5645->pdata.gpio_hp_det_active_high && !gpio_state)) {
snd_soc_dapm_force_enable_pin(&codec->dapm, "micbias1");
snd_soc_dapm_force_enable_pin(&codec->dapm, "micbias2");
snd_soc_dapm_force_enable_pin(&codec->dapm, "LDO2");
snd_soc_dapm_force_enable_pin(&codec->dapm, "Mic Det Power");
snd_soc_dapm_sync(&codec->dapm);
snd_soc_write(codec, RT5645_IN1_CTRL1, 0x0006);
snd_soc_write(codec, RT5645_JD_CTRL3, 0x00b0);
snd_soc_update_bits(codec, RT5645_IN1_CTRL2,
RT5645_CBJ_MN_JD, 0);
snd_soc_update_bits(codec, RT5645_IN1_CTRL2,
RT5645_CBJ_MN_JD, RT5645_CBJ_MN_JD);
msleep(400);
val = snd_soc_read(codec, RT5645_IN1_CTRL3) & 0x7;
dev_dbg(codec->dev, "val = %d\n", val);
if (val == 1 || val == 2)
jack_type = SND_JACK_HEADSET;
else
jack_type = SND_JACK_HEADPHONE;
snd_soc_dapm_disable_pin(&codec->dapm, "micbias1");
snd_soc_dapm_disable_pin(&codec->dapm, "micbias2");
if (rt5645->pdata.jd_mode == 0)
snd_soc_dapm_disable_pin(&codec->dapm, "LDO2");
snd_soc_dapm_disable_pin(&codec->dapm, "Mic Det Power");
snd_soc_dapm_sync(&codec->dapm);
}
snd_soc_jack_report(rt5645->hp_jack, jack_type, SND_JACK_HEADPHONE);
snd_soc_jack_report(rt5645->mic_jack, jack_type, SND_JACK_MICROPHONE);
return 0;
}
int rt5645_set_jack_detect(struct snd_soc_codec *codec,
struct snd_soc_jack *hp_jack, struct snd_soc_jack *mic_jack)
{
struct rt5645_priv *rt5645 = snd_soc_codec_get_drvdata(codec);
rt5645->hp_jack = hp_jack;
rt5645->mic_jack = mic_jack;
rt5645_jack_detect(codec);
return 0;
}
static void rt5645_jack_detect_work(struct work_struct *work)
{
struct rt5645_priv *rt5645 =
container_of(work, struct rt5645_priv, jack_detect_work.work);
rt5645_jack_detect(rt5645->codec);
}
static irqreturn_t rt5645_irq(int irq, void *data)
{
struct rt5645_priv *rt5645 = data;
queue_delayed_work(system_power_efficient_wq,
&rt5645->jack_detect_work, msecs_to_jiffies(250));
return IRQ_HANDLED;
}
static int rt5645_probe(struct snd_soc_codec *codec)
{
struct rt5645_priv *rt5645 = snd_soc_codec_get_drvdata(codec);
rt5645->codec = codec;
switch (rt5645->codec_type) {
case CODEC_TYPE_RT5645:
snd_soc_dapm_add_routes(&codec->dapm,
rt5645_specific_dapm_routes,
ARRAY_SIZE(rt5645_specific_dapm_routes));
break;
case CODEC_TYPE_RT5650:
snd_soc_dapm_new_controls(&codec->dapm,
rt5650_specific_dapm_widgets,
ARRAY_SIZE(rt5650_specific_dapm_widgets));
snd_soc_dapm_add_routes(&codec->dapm,
rt5650_specific_dapm_routes,
ARRAY_SIZE(rt5650_specific_dapm_routes));
break;
}
rt5645_set_bias_level(codec, SND_SOC_BIAS_OFF);
snd_soc_update_bits(codec, RT5645_CHARGE_PUMP, 0x0300, 0x0200);
if (rt5645->pdata.en_jd_func) {
snd_soc_dapm_force_enable_pin(&codec->dapm, "JD Power");
snd_soc_dapm_force_enable_pin(&codec->dapm, "LDO2");
snd_soc_dapm_sync(&codec->dapm);
}
return 0;
}
static int rt5645_remove(struct snd_soc_codec *codec)
{
rt5645_reset(codec);
return 0;
}
static int rt5645_suspend(struct snd_soc_codec *codec)
{
struct rt5645_priv *rt5645 = snd_soc_codec_get_drvdata(codec);
regcache_cache_only(rt5645->regmap, true);
regcache_mark_dirty(rt5645->regmap);
return 0;
}
static int rt5645_resume(struct snd_soc_codec *codec)
{
struct rt5645_priv *rt5645 = snd_soc_codec_get_drvdata(codec);
regcache_cache_only(rt5645->regmap, false);
regcache_sync(rt5645->regmap);
return 0;
}
static int rt5645_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct rt5645_platform_data *pdata = dev_get_platdata(&i2c->dev);
struct rt5645_priv *rt5645;
int ret;
unsigned int val;
rt5645 = devm_kzalloc(&i2c->dev, sizeof(struct rt5645_priv),
GFP_KERNEL);
if (rt5645 == NULL)
return -ENOMEM;
rt5645->i2c = i2c;
i2c_set_clientdata(i2c, rt5645);
if (pdata)
rt5645->pdata = *pdata;
rt5645->regmap = devm_regmap_init_i2c(i2c, &rt5645_regmap);
if (IS_ERR(rt5645->regmap)) {
ret = PTR_ERR(rt5645->regmap);
dev_err(&i2c->dev, "Failed to allocate register map: %d\n",
ret);
return ret;
}
regmap_read(rt5645->regmap, RT5645_VENDOR_ID2, &val);
switch (val) {
case RT5645_DEVICE_ID:
rt5645->codec_type = CODEC_TYPE_RT5645;
break;
case RT5650_DEVICE_ID:
rt5645->codec_type = CODEC_TYPE_RT5650;
break;
default:
dev_err(&i2c->dev,
"Device with ID register %x is not rt5645 or rt5650\n",
val);
return -ENODEV;
}
regmap_write(rt5645->regmap, RT5645_RESET, 0);
ret = regmap_register_patch(rt5645->regmap, init_list,
ARRAY_SIZE(init_list));
if (ret != 0)
dev_warn(&i2c->dev, "Failed to apply regmap patch: %d\n", ret);
if (rt5645->codec_type == CODEC_TYPE_RT5650) {
ret = regmap_register_patch(rt5645->regmap, rt5650_init_list,
ARRAY_SIZE(rt5650_init_list));
if (ret != 0)
dev_warn(&i2c->dev, "Apply rt5650 patch failed: %d\n",
ret);
}
if (rt5645->pdata.in2_diff)
regmap_update_bits(rt5645->regmap, RT5645_IN2_CTRL,
RT5645_IN_DF2, RT5645_IN_DF2);
if (rt5645->pdata.dmic_en) {
regmap_update_bits(rt5645->regmap, RT5645_GPIO_CTRL1,
RT5645_GP2_PIN_MASK, RT5645_GP2_PIN_DMIC1_SCL);
switch (rt5645->pdata.dmic1_data_pin) {
case RT5645_DMIC_DATA_IN2N:
regmap_update_bits(rt5645->regmap, RT5645_DMIC_CTRL1,
RT5645_DMIC_1_DP_MASK, RT5645_DMIC_1_DP_IN2N);
break;
case RT5645_DMIC_DATA_GPIO5:
regmap_update_bits(rt5645->regmap, RT5645_DMIC_CTRL1,
RT5645_DMIC_1_DP_MASK, RT5645_DMIC_1_DP_GPIO5);
regmap_update_bits(rt5645->regmap, RT5645_GPIO_CTRL1,
RT5645_GP5_PIN_MASK, RT5645_GP5_PIN_DMIC1_SDA);
break;
case RT5645_DMIC_DATA_GPIO11:
regmap_update_bits(rt5645->regmap, RT5645_DMIC_CTRL1,
RT5645_DMIC_1_DP_MASK, RT5645_DMIC_1_DP_GPIO11);
regmap_update_bits(rt5645->regmap, RT5645_GPIO_CTRL1,
RT5645_GP11_PIN_MASK,
RT5645_GP11_PIN_DMIC1_SDA);
break;
default:
break;
}
switch (rt5645->pdata.dmic2_data_pin) {
case RT5645_DMIC_DATA_IN2P:
regmap_update_bits(rt5645->regmap, RT5645_DMIC_CTRL1,
RT5645_DMIC_2_DP_MASK, RT5645_DMIC_2_DP_IN2P);
break;
case RT5645_DMIC_DATA_GPIO6:
regmap_update_bits(rt5645->regmap, RT5645_DMIC_CTRL1,
RT5645_DMIC_2_DP_MASK, RT5645_DMIC_2_DP_GPIO6);
regmap_update_bits(rt5645->regmap, RT5645_GPIO_CTRL1,
RT5645_GP6_PIN_MASK, RT5645_GP6_PIN_DMIC2_SDA);
break;
case RT5645_DMIC_DATA_GPIO10:
regmap_update_bits(rt5645->regmap, RT5645_DMIC_CTRL1,
RT5645_DMIC_2_DP_MASK, RT5645_DMIC_2_DP_GPIO10);
regmap_update_bits(rt5645->regmap, RT5645_GPIO_CTRL1,
RT5645_GP10_PIN_MASK,
RT5645_GP10_PIN_DMIC2_SDA);
break;
case RT5645_DMIC_DATA_GPIO12:
regmap_update_bits(rt5645->regmap, RT5645_DMIC_CTRL1,
RT5645_DMIC_1_DP_MASK, RT5645_DMIC_2_DP_GPIO12);
regmap_update_bits(rt5645->regmap, RT5645_GPIO_CTRL1,
RT5645_GP12_PIN_MASK,
RT5645_GP12_PIN_DMIC2_SDA);
break;
default:
break;
}
}
if (rt5645->pdata.en_jd_func) {
regmap_update_bits(rt5645->regmap, RT5645_GEN_CTRL3,
RT5645_IRQ_CLK_GATE_CTRL | RT5645_MICINDET_MANU,
RT5645_IRQ_CLK_GATE_CTRL | RT5645_MICINDET_MANU);
regmap_update_bits(rt5645->regmap, RT5645_IN1_CTRL1,
RT5645_CBJ_BST1_EN, RT5645_CBJ_BST1_EN);
regmap_update_bits(rt5645->regmap, RT5645_JD_CTRL3,
RT5645_JD_CBJ_EN | RT5645_JD_CBJ_POL,
RT5645_JD_CBJ_EN | RT5645_JD_CBJ_POL);
regmap_update_bits(rt5645->regmap, RT5645_MICBIAS,
RT5645_IRQ_CLK_INT, RT5645_IRQ_CLK_INT);
}
if (rt5645->pdata.jd_mode) {
regmap_update_bits(rt5645->regmap, RT5645_IRQ_CTRL2,
RT5645_IRQ_JD_1_1_EN, RT5645_IRQ_JD_1_1_EN);
regmap_update_bits(rt5645->regmap, RT5645_GEN_CTRL3,
RT5645_JD_PSV_MODE, RT5645_JD_PSV_MODE);
regmap_update_bits(rt5645->regmap, RT5645_HPO_MIXER,
RT5645_IRQ_PSV_MODE, RT5645_IRQ_PSV_MODE);
regmap_update_bits(rt5645->regmap, RT5645_MICBIAS,
RT5645_MIC2_OVCD_EN, RT5645_MIC2_OVCD_EN);
regmap_update_bits(rt5645->regmap, RT5645_GPIO_CTRL1,
RT5645_GP1_PIN_IRQ, RT5645_GP1_PIN_IRQ);
switch (rt5645->pdata.jd_mode) {
case 1:
regmap_update_bits(rt5645->regmap, RT5645_A_JD_CTRL1,
RT5645_JD1_MODE_MASK,
RT5645_JD1_MODE_0);
break;
case 2:
regmap_update_bits(rt5645->regmap, RT5645_A_JD_CTRL1,
RT5645_JD1_MODE_MASK,
RT5645_JD1_MODE_1);
break;
case 3:
regmap_update_bits(rt5645->regmap, RT5645_A_JD_CTRL1,
RT5645_JD1_MODE_MASK,
RT5645_JD1_MODE_2);
break;
default:
break;
}
}
if (rt5645->i2c->irq) {
ret = request_threaded_irq(rt5645->i2c->irq, NULL, rt5645_irq,
IRQF_TRIGGER_RISING | IRQF_TRIGGER_FALLING
| IRQF_ONESHOT, "rt5645", rt5645);
if (ret)
dev_err(&i2c->dev, "Failed to reguest IRQ: %d\n", ret);
}
if (gpio_is_valid(rt5645->pdata.hp_det_gpio)) {
ret = gpio_request(rt5645->pdata.hp_det_gpio, "rt5645");
if (ret)
dev_err(&i2c->dev, "Fail gpio_request hp_det_gpio\n");
ret = gpio_direction_input(rt5645->pdata.hp_det_gpio);
if (ret)
dev_err(&i2c->dev, "Fail gpio_direction hp_det_gpio\n");
}
INIT_DELAYED_WORK(&rt5645->jack_detect_work, rt5645_jack_detect_work);
return snd_soc_register_codec(&i2c->dev, &soc_codec_dev_rt5645,
rt5645_dai, ARRAY_SIZE(rt5645_dai));
}
static int rt5645_i2c_remove(struct i2c_client *i2c)
{
struct rt5645_priv *rt5645 = i2c_get_clientdata(i2c);
if (i2c->irq)
free_irq(i2c->irq, rt5645);
cancel_delayed_work_sync(&rt5645->jack_detect_work);
if (gpio_is_valid(rt5645->pdata.hp_det_gpio))
gpio_free(rt5645->pdata.hp_det_gpio);
snd_soc_unregister_codec(&i2c->dev);
return 0;
}
