static bool rt5651_volatile_register(struct device *dev, unsigned int reg)
{
int i;
for (i = 0; i < ARRAY_SIZE(rt5651_ranges); i++) {
if ((reg >= rt5651_ranges[i].window_start &&
reg <= rt5651_ranges[i].window_start +
rt5651_ranges[i].window_len) ||
(reg >= rt5651_ranges[i].range_min &&
reg <= rt5651_ranges[i].range_max)) {
return true;
}
}
switch (reg) {
case RT5651_RESET:
case RT5651_PRIV_DATA:
case RT5651_EQ_CTRL1:
case RT5651_ALC_1:
case RT5651_IRQ_CTRL2:
case RT5651_INT_IRQ_ST:
case RT5651_PGM_REG_ARR1:
case RT5651_PGM_REG_ARR3:
case RT5651_VENDOR_ID:
case RT5651_DEVICE_ID:
return true;
default:
return false;
}
}
static bool rt5651_readable_register(struct device *dev, unsigned int reg)
{
int i;
for (i = 0; i < ARRAY_SIZE(rt5651_ranges); i++) {
if ((reg >= rt5651_ranges[i].window_start &&
reg <= rt5651_ranges[i].window_start +
rt5651_ranges[i].window_len) ||
(reg >= rt5651_ranges[i].range_min &&
reg <= rt5651_ranges[i].range_max)) {
return true;
}
}
switch (reg) {
case RT5651_RESET:
case RT5651_VERSION_ID:
case RT5651_VENDOR_ID:
case RT5651_DEVICE_ID:
case RT5651_HP_VOL:
case RT5651_LOUT_CTRL1:
case RT5651_LOUT_CTRL2:
case RT5651_IN1_IN2:
case RT5651_IN3:
case RT5651_INL1_INR1_VOL:
case RT5651_INL2_INR2_VOL:
case RT5651_DAC1_DIG_VOL:
case RT5651_DAC2_DIG_VOL:
case RT5651_DAC2_CTRL:
case RT5651_ADC_DIG_VOL:
case RT5651_ADC_DATA:
case RT5651_ADC_BST_VOL:
case RT5651_STO1_ADC_MIXER:
case RT5651_STO2_ADC_MIXER:
case RT5651_AD_DA_MIXER:
case RT5651_STO_DAC_MIXER:
case RT5651_DD_MIXER:
case RT5651_DIG_INF_DATA:
case RT5651_PDM_CTL:
case RT5651_REC_L1_MIXER:
case RT5651_REC_L2_MIXER:
case RT5651_REC_R1_MIXER:
case RT5651_REC_R2_MIXER:
case RT5651_HPO_MIXER:
case RT5651_OUT_L1_MIXER:
case RT5651_OUT_L2_MIXER:
case RT5651_OUT_L3_MIXER:
case RT5651_OUT_R1_MIXER:
case RT5651_OUT_R2_MIXER:
case RT5651_OUT_R3_MIXER:
case RT5651_LOUT_MIXER:
case RT5651_PWR_DIG1:
case RT5651_PWR_DIG2:
case RT5651_PWR_ANLG1:
case RT5651_PWR_ANLG2:
case RT5651_PWR_MIXER:
case RT5651_PWR_VOL:
case RT5651_PRIV_INDEX:
case RT5651_PRIV_DATA:
case RT5651_I2S1_SDP:
case RT5651_I2S2_SDP:
case RT5651_ADDA_CLK1:
case RT5651_ADDA_CLK2:
case RT5651_DMIC:
case RT5651_TDM_CTL_1:
case RT5651_TDM_CTL_2:
case RT5651_TDM_CTL_3:
case RT5651_GLB_CLK:
case RT5651_PLL_CTRL1:
case RT5651_PLL_CTRL2:
case RT5651_PLL_MODE_1:
case RT5651_PLL_MODE_2:
case RT5651_PLL_MODE_3:
case RT5651_PLL_MODE_4:
case RT5651_PLL_MODE_5:
case RT5651_PLL_MODE_6:
case RT5651_PLL_MODE_7:
case RT5651_DEPOP_M1:
case RT5651_DEPOP_M2:
case RT5651_DEPOP_M3:
case RT5651_CHARGE_PUMP:
case RT5651_MICBIAS:
case RT5651_A_JD_CTL1:
case RT5651_EQ_CTRL1:
case RT5651_EQ_CTRL2:
case RT5651_ALC_1:
case RT5651_ALC_2:
case RT5651_ALC_3:
case RT5651_JD_CTRL1:
case RT5651_JD_CTRL2:
case RT5651_IRQ_CTRL1:
case RT5651_IRQ_CTRL2:
case RT5651_INT_IRQ_ST:
case RT5651_GPIO_CTRL1:
case RT5651_GPIO_CTRL2:
case RT5651_GPIO_CTRL3:
case RT5651_PGM_REG_ARR1:
case RT5651_PGM_REG_ARR2:
case RT5651_PGM_REG_ARR3:
case RT5651_PGM_REG_ARR4:
case RT5651_PGM_REG_ARR5:
case RT5651_SCB_FUNC:
case RT5651_SCB_CTRL:
case RT5651_BASE_BACK:
case RT5651_MP3_PLUS1:
case RT5651_MP3_PLUS2:
case RT5651_ADJ_HPF_CTRL1:
case RT5651_ADJ_HPF_CTRL2:
case RT5651_HP_CALIB_AMP_DET:
case RT5651_HP_CALIB2:
case RT5651_SV_ZCD1:
case RT5651_SV_ZCD2:
case RT5651_D_MISC:
case RT5651_DUMMY2:
case RT5651_DUMMY3:
return true;
default:
return false;
}
}
static int set_dmic_clk(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
struct rt5651_priv *rt5651 = snd_soc_codec_get_drvdata(codec);
int idx, rate;
rate = rt5651->sysclk / rl6231_get_pre_div(rt5651->regmap,
RT5651_ADDA_CLK1, RT5651_I2S_PD1_SFT);
idx = rl6231_calc_dmic_clk(rate);
if (idx < 0)
dev_err(codec->dev, "Failed to set DMIC clock\n");
else
snd_soc_update_bits(codec, RT5651_DMIC, RT5651_DMIC_CLK_MASK,
idx << RT5651_DMIC_CLK_SFT);
return idx;
}
static int is_sysclk_from_pll(struct snd_soc_dapm_widget *source,
struct snd_soc_dapm_widget *sink)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(source->dapm);
unsigned int val;
val = snd_soc_read(codec, RT5651_GLB_CLK);
val &= RT5651_SCLK_SRC_MASK;
if (val == RT5651_SCLK_SRC_PLL1)
return 1;
else
return 0;
}
static int rt5651_amp_power_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
struct rt5651_priv *rt5651 = snd_soc_codec_get_drvdata(codec);
switch (event) {
case SND_SOC_DAPM_POST_PMU:
regmap_update_bits(rt5651->regmap, RT5651_PR_BASE +
RT5651_CHPUMP_INT_REG1, 0x0700, 0x0200);
regmap_update_bits(rt5651->regmap, RT5651_DEPOP_M2,
RT5651_DEPOP_MASK, RT5651_DEPOP_MAN);
regmap_update_bits(rt5651->regmap, RT5651_DEPOP_M1,
RT5651_HP_CP_MASK | RT5651_HP_SG_MASK |
RT5651_HP_CB_MASK, RT5651_HP_CP_PU |
RT5651_HP_SG_DIS | RT5651_HP_CB_PU);
regmap_write(rt5651->regmap, RT5651_PR_BASE +
RT5651_HP_DCC_INT1, 0x9f00);
regmap_update_bits(rt5651->regmap, RT5651_PWR_ANLG1,
RT5651_PWR_FV1 | RT5651_PWR_FV2, 0);
regmap_update_bits(rt5651->regmap, RT5651_PWR_ANLG1,
RT5651_PWR_HA,
RT5651_PWR_HA);
usleep_range(10000, 15000);
regmap_update_bits(rt5651->regmap, RT5651_PWR_ANLG1,
RT5651_PWR_FV1 | RT5651_PWR_FV2 ,
RT5651_PWR_FV1 | RT5651_PWR_FV2);
break;
default:
return 0;
}
return 0;
}
static int rt5651_hp_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
struct rt5651_priv *rt5651 = snd_soc_codec_get_drvdata(codec);
switch (event) {
case SND_SOC_DAPM_POST_PMU:
regmap_update_bits(rt5651->regmap, RT5651_DEPOP_M2,
RT5651_DEPOP_MASK | RT5651_DIG_DP_MASK,
RT5651_DEPOP_AUTO | RT5651_DIG_DP_EN);
regmap_update_bits(rt5651->regmap, RT5651_CHARGE_PUMP,
RT5651_PM_HP_MASK, RT5651_PM_HP_HV);
regmap_update_bits(rt5651->regmap, RT5651_DEPOP_M3,
RT5651_CP_FQ1_MASK | RT5651_CP_FQ2_MASK |
RT5651_CP_FQ3_MASK,
(RT5651_CP_FQ_192_KHZ << RT5651_CP_FQ1_SFT) |
(RT5651_CP_FQ_12_KHZ << RT5651_CP_FQ2_SFT) |
(RT5651_CP_FQ_192_KHZ << RT5651_CP_FQ3_SFT));
regmap_write(rt5651->regmap, RT5651_PR_BASE +
RT5651_MAMP_INT_REG2, 0x1c00);
regmap_update_bits(rt5651->regmap, RT5651_DEPOP_M1,
RT5651_HP_CP_MASK | RT5651_HP_SG_MASK,
RT5651_HP_CP_PD | RT5651_HP_SG_EN);
regmap_update_bits(rt5651->regmap, RT5651_PR_BASE +
RT5651_CHPUMP_INT_REG1, 0x0700, 0x0400);
rt5651->hp_mute = 0;
break;
case SND_SOC_DAPM_PRE_PMD:
rt5651->hp_mute = 1;
usleep_range(70000, 75000);
break;
default:
return 0;
}
return 0;
}
static int rt5651_hp_post_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
struct rt5651_priv *rt5651 = snd_soc_codec_get_drvdata(codec);
switch (event) {
case SND_SOC_DAPM_POST_PMU:
if (!rt5651->hp_mute)
usleep_range(80000, 85000);
break;
default:
return 0;
}
return 0;
}
static int rt5651_bst1_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
switch (event) {
case SND_SOC_DAPM_POST_PMU:
snd_soc_update_bits(codec, RT5651_PWR_ANLG2,
RT5651_PWR_BST1_OP2, RT5651_PWR_BST1_OP2);
break;
case SND_SOC_DAPM_PRE_PMD:
snd_soc_update_bits(codec, RT5651_PWR_ANLG2,
RT5651_PWR_BST1_OP2, 0);
break;
default:
return 0;
}
return 0;
}
static int rt5651_bst2_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
switch (event) {
case SND_SOC_DAPM_POST_PMU:
snd_soc_update_bits(codec, RT5651_PWR_ANLG2,
RT5651_PWR_BST2_OP2, RT5651_PWR_BST2_OP2);
break;
case SND_SOC_DAPM_PRE_PMD:
snd_soc_update_bits(codec, RT5651_PWR_ANLG2,
RT5651_PWR_BST2_OP2, 0);
break;
default:
return 0;
}
return 0;
}
static int rt5651_bst3_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
switch (event) {
case SND_SOC_DAPM_POST_PMU:
snd_soc_update_bits(codec, RT5651_PWR_ANLG2,
RT5651_PWR_BST3_OP2, RT5651_PWR_BST3_OP2);
break;
case SND_SOC_DAPM_PRE_PMD:
snd_soc_update_bits(codec, RT5651_PWR_ANLG2,
RT5651_PWR_BST3_OP2, 0);
break;
default:
return 0;
}
return 0;
}
static int rt5651_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params, struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct rt5651_priv *rt5651 = snd_soc_codec_get_drvdata(codec);
unsigned int val_len = 0, val_clk, mask_clk;
int pre_div, bclk_ms, frame_size;
rt5651->lrck[dai->id] = params_rate(params);
pre_div = rl6231_get_clk_info(rt5651->sysclk, rt5651->lrck[dai->id]);
if (pre_div < 0) {
dev_err(codec->dev, "Unsupported clock setting\n");
return -EINVAL;
}
frame_size = snd_soc_params_to_frame_size(params);
if (frame_size < 0) {
dev_err(codec->dev, "Unsupported frame size: %d\n", frame_size);
return -EINVAL;
}
bclk_ms = frame_size > 32 ? 1 : 0;
rt5651->bclk[dai->id] = rt5651->lrck[dai->id] * (32 << bclk_ms);
dev_dbg(dai->dev, "bclk is %dHz and lrck is %dHz\n",
rt5651->bclk[dai->id], rt5651->lrck[dai->id]);
dev_dbg(dai->dev, "bclk_ms is %d and pre_div is %d for iis %d\n",
bclk_ms, pre_div, dai->id);
switch (params_width(params)) {
case 16:
break;
case 20:
val_len |= RT5651_I2S_DL_20;
break;
case 24:
val_len |= RT5651_I2S_DL_24;
break;
case 8:
val_len |= RT5651_I2S_DL_8;
break;
default:
return -EINVAL;
}
switch (dai->id) {
case RT5651_AIF1:
mask_clk = RT5651_I2S_PD1_MASK;
val_clk = pre_div << RT5651_I2S_PD1_SFT;
snd_soc_update_bits(codec, RT5651_I2S1_SDP,
RT5651_I2S_DL_MASK, val_len);
snd_soc_update_bits(codec, RT5651_ADDA_CLK1, mask_clk, val_clk);
break;
case RT5651_AIF2:
mask_clk = RT5651_I2S_BCLK_MS2_MASK | RT5651_I2S_PD2_MASK;
val_clk = pre_div << RT5651_I2S_PD2_SFT;
snd_soc_update_bits(codec, RT5651_I2S2_SDP,
RT5651_I2S_DL_MASK, val_len);
snd_soc_update_bits(codec, RT5651_ADDA_CLK1, mask_clk, val_clk);
break;
default:
dev_err(codec->dev, "Wrong dai->id: %d\n", dai->id);
return -EINVAL;
}
return 0;
}
static int rt5651_set_dai_fmt(struct snd_soc_dai *dai, unsigned int fmt)
{
struct snd_soc_codec *codec = dai->codec;
struct rt5651_priv *rt5651 = snd_soc_codec_get_drvdata(codec);
unsigned int reg_val = 0;
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBM_CFM:
rt5651->master[dai->id] = 1;
break;
case SND_SOC_DAIFMT_CBS_CFS:
reg_val |= RT5651_I2S_MS_S;
rt5651->master[dai->id] = 0;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
break;
case SND_SOC_DAIFMT_IB_NF:
reg_val |= RT5651_I2S_BP_INV;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
break;
case SND_SOC_DAIFMT_LEFT_J:
reg_val |= RT5651_I2S_DF_LEFT;
break;
case SND_SOC_DAIFMT_DSP_A:
reg_val |= RT5651_I2S_DF_PCM_A;
break;
case SND_SOC_DAIFMT_DSP_B:
reg_val |= RT5651_I2S_DF_PCM_B;
break;
default:
return -EINVAL;
}
switch (dai->id) {
case RT5651_AIF1:
snd_soc_update_bits(codec, RT5651_I2S1_SDP,
RT5651_I2S_MS_MASK | RT5651_I2S_BP_MASK |
RT5651_I2S_DF_MASK, reg_val);
break;
case RT5651_AIF2:
snd_soc_update_bits(codec, RT5651_I2S2_SDP,
RT5651_I2S_MS_MASK | RT5651_I2S_BP_MASK |
RT5651_I2S_DF_MASK, reg_val);
break;
default:
dev_err(codec->dev, "Wrong dai->id: %d\n", dai->id);
return -EINVAL;
}
return 0;
}
static int rt5651_set_dai_sysclk(struct snd_soc_dai *dai,
int clk_id, unsigned int freq, int dir)
{
struct snd_soc_codec *codec = dai->codec;
struct rt5651_priv *rt5651 = snd_soc_codec_get_drvdata(codec);
unsigned int reg_val = 0;
if (freq == rt5651->sysclk && clk_id == rt5651->sysclk_src)
return 0;
switch (clk_id) {
case RT5651_SCLK_S_MCLK:
reg_val |= RT5651_SCLK_SRC_MCLK;
break;
case RT5651_SCLK_S_PLL1:
reg_val |= RT5651_SCLK_SRC_PLL1;
break;
case RT5651_SCLK_S_RCCLK:
reg_val |= RT5651_SCLK_SRC_RCCLK;
break;
default:
dev_err(codec->dev, "Invalid clock id (%d)\n", clk_id);
return -EINVAL;
}
snd_soc_update_bits(codec, RT5651_GLB_CLK,
RT5651_SCLK_SRC_MASK, reg_val);
rt5651->sysclk = freq;
rt5651->sysclk_src = clk_id;
dev_dbg(dai->dev, "Sysclk is %dHz and clock id is %d\n", freq, clk_id);
return 0;
}
static int rt5651_set_dai_pll(struct snd_soc_dai *dai, int pll_id, int source,
unsigned int freq_in, unsigned int freq_out)
{
struct snd_soc_codec *codec = dai->codec;
struct rt5651_priv *rt5651 = snd_soc_codec_get_drvdata(codec);
struct rl6231_pll_code pll_code;
int ret;
if (source == rt5651->pll_src && freq_in == rt5651->pll_in &&
freq_out == rt5651->pll_out)
return 0;
if (!freq_in || !freq_out) {
dev_dbg(codec->dev, "PLL disabled\n");
rt5651->pll_in = 0;
rt5651->pll_out = 0;
snd_soc_update_bits(codec, RT5651_GLB_CLK,
RT5651_SCLK_SRC_MASK, RT5651_SCLK_SRC_MCLK);
return 0;
}
switch (source) {
case RT5651_PLL1_S_MCLK:
snd_soc_update_bits(codec, RT5651_GLB_CLK,
RT5651_PLL1_SRC_MASK, RT5651_PLL1_SRC_MCLK);
break;
case RT5651_PLL1_S_BCLK1:
snd_soc_update_bits(codec, RT5651_GLB_CLK,
RT5651_PLL1_SRC_MASK, RT5651_PLL1_SRC_BCLK1);
break;
case RT5651_PLL1_S_BCLK2:
snd_soc_update_bits(codec, RT5651_GLB_CLK,
RT5651_PLL1_SRC_MASK, RT5651_PLL1_SRC_BCLK2);
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
snd_soc_write(codec, RT5651_PLL_CTRL1,
pll_code.n_code << RT5651_PLL_N_SFT | pll_code.k_code);
snd_soc_write(codec, RT5651_PLL_CTRL2,
(pll_code.m_bp ? 0 : pll_code.m_code) << RT5651_PLL_M_SFT |
pll_code.m_bp << RT5651_PLL_M_BP_SFT);
rt5651->pll_in = freq_in;
rt5651->pll_out = freq_out;
rt5651->pll_src = source;
return 0;
}
static int rt5651_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
switch (level) {
case SND_SOC_BIAS_PREPARE:
if (SND_SOC_BIAS_STANDBY == snd_soc_codec_get_bias_level(codec)) {
snd_soc_update_bits(codec, RT5651_PWR_ANLG1,
RT5651_PWR_VREF1 | RT5651_PWR_MB |
RT5651_PWR_BG | RT5651_PWR_VREF2,
RT5651_PWR_VREF1 | RT5651_PWR_MB |
RT5651_PWR_BG | RT5651_PWR_VREF2);
usleep_range(10000, 15000);
snd_soc_update_bits(codec, RT5651_PWR_ANLG1,
RT5651_PWR_FV1 | RT5651_PWR_FV2,
RT5651_PWR_FV1 | RT5651_PWR_FV2);
snd_soc_update_bits(codec, RT5651_PWR_ANLG1,
RT5651_PWR_LDO_DVO_MASK,
RT5651_PWR_LDO_DVO_1_2V);
snd_soc_update_bits(codec, RT5651_D_MISC, 0x1, 0x1);
if (snd_soc_read(codec, RT5651_PLL_MODE_1) & 0x9200)
snd_soc_update_bits(codec, RT5651_D_MISC,
0xc00, 0xc00);
}
break;
case SND_SOC_BIAS_STANDBY:
snd_soc_write(codec, RT5651_D_MISC, 0x0010);
snd_soc_write(codec, RT5651_PWR_DIG1, 0x0000);
snd_soc_write(codec, RT5651_PWR_DIG2, 0x0000);
snd_soc_write(codec, RT5651_PWR_VOL, 0x0000);
snd_soc_write(codec, RT5651_PWR_MIXER, 0x0000);
snd_soc_write(codec, RT5651_PWR_ANLG1, 0x0000);
snd_soc_write(codec, RT5651_PWR_ANLG2, 0x0000);
break;
default:
break;
}
return 0;
}
static int rt5651_probe(struct snd_soc_codec *codec)
{
struct rt5651_priv *rt5651 = snd_soc_codec_get_drvdata(codec);
rt5651->codec = codec;
snd_soc_update_bits(codec, RT5651_PWR_ANLG1,
RT5651_PWR_VREF1 | RT5651_PWR_MB |
RT5651_PWR_BG | RT5651_PWR_VREF2,
RT5651_PWR_VREF1 | RT5651_PWR_MB |
RT5651_PWR_BG | RT5651_PWR_VREF2);
usleep_range(10000, 15000);
snd_soc_update_bits(codec, RT5651_PWR_ANLG1,
RT5651_PWR_FV1 | RT5651_PWR_FV2,
RT5651_PWR_FV1 | RT5651_PWR_FV2);
snd_soc_codec_force_bias_level(codec, SND_SOC_BIAS_OFF);
return 0;
}
static int rt5651_suspend(struct snd_soc_codec *codec)
{
struct rt5651_priv *rt5651 = snd_soc_codec_get_drvdata(codec);
regcache_cache_only(rt5651->regmap, true);
regcache_mark_dirty(rt5651->regmap);
return 0;
}
static int rt5651_resume(struct snd_soc_codec *codec)
{
struct rt5651_priv *rt5651 = snd_soc_codec_get_drvdata(codec);
regcache_cache_only(rt5651->regmap, false);
snd_soc_cache_sync(codec);
return 0;
}
static int rt5651_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct rt5651_platform_data *pdata = dev_get_platdata(&i2c->dev);
struct rt5651_priv *rt5651;
int ret;
rt5651 = devm_kzalloc(&i2c->dev, sizeof(*rt5651),
GFP_KERNEL);
if (NULL == rt5651)
return -ENOMEM;
i2c_set_clientdata(i2c, rt5651);
if (pdata)
rt5651->pdata = *pdata;
rt5651->regmap = devm_regmap_init_i2c(i2c, &rt5651_regmap);
if (IS_ERR(rt5651->regmap)) {
ret = PTR_ERR(rt5651->regmap);
dev_err(&i2c->dev, "Failed to allocate register map: %d\n",
ret);
return ret;
}
regmap_read(rt5651->regmap, RT5651_DEVICE_ID, &ret);
if (ret != RT5651_DEVICE_ID_VALUE) {
dev_err(&i2c->dev,
"Device with ID register %#x is not rt5651\n", ret);
return -ENODEV;
}
regmap_write(rt5651->regmap, RT5651_RESET, 0);
ret = regmap_register_patch(rt5651->regmap, init_list,
ARRAY_SIZE(init_list));
if (ret != 0)
dev_warn(&i2c->dev, "Failed to apply regmap patch: %d\n", ret);
if (rt5651->pdata.in2_diff)
regmap_update_bits(rt5651->regmap, RT5651_IN1_IN2,
RT5651_IN_DF2, RT5651_IN_DF2);
if (rt5651->pdata.dmic_en)
regmap_update_bits(rt5651->regmap, RT5651_GPIO_CTRL1,
RT5651_GP2_PIN_MASK, RT5651_GP2_PIN_DMIC1_SCL);
rt5651->hp_mute = 1;
ret = snd_soc_register_codec(&i2c->dev, &soc_codec_dev_rt5651,
rt5651_dai, ARRAY_SIZE(rt5651_dai));
return ret;
}
static int rt5651_i2c_remove(struct i2c_client *i2c)
{
snd_soc_unregister_codec(&i2c->dev);
return 0;
}
