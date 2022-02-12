static int rt5640_reset(struct snd_soc_codec *codec)
{
return snd_soc_write(codec, RT5640_RESET, 0);
}
static bool rt5640_volatile_register(struct device *dev, unsigned int reg)
{
int i;
for (i = 0; i < ARRAY_SIZE(rt5640_ranges); i++)
if ((reg >= rt5640_ranges[i].window_start &&
reg <= rt5640_ranges[i].window_start +
rt5640_ranges[i].window_len) ||
(reg >= rt5640_ranges[i].range_min &&
reg <= rt5640_ranges[i].range_max))
return true;
switch (reg) {
case RT5640_RESET:
case RT5640_ASRC_5:
case RT5640_EQ_CTRL1:
case RT5640_DRC_AGC_1:
case RT5640_ANC_CTRL1:
case RT5640_IRQ_CTRL2:
case RT5640_INT_IRQ_ST:
case RT5640_DSP_CTRL2:
case RT5640_DSP_CTRL3:
case RT5640_PRIV_INDEX:
case RT5640_PRIV_DATA:
case RT5640_PGM_REG_ARR1:
case RT5640_PGM_REG_ARR3:
case RT5640_VENDOR_ID:
case RT5640_VENDOR_ID1:
case RT5640_VENDOR_ID2:
return true;
default:
return false;
}
}
static bool rt5640_readable_register(struct device *dev, unsigned int reg)
{
int i;
for (i = 0; i < ARRAY_SIZE(rt5640_ranges); i++)
if ((reg >= rt5640_ranges[i].window_start &&
reg <= rt5640_ranges[i].window_start +
rt5640_ranges[i].window_len) ||
(reg >= rt5640_ranges[i].range_min &&
reg <= rt5640_ranges[i].range_max))
return true;
switch (reg) {
case RT5640_RESET:
case RT5640_SPK_VOL:
case RT5640_HP_VOL:
case RT5640_OUTPUT:
case RT5640_MONO_OUT:
case RT5640_IN1_IN2:
case RT5640_IN3_IN4:
case RT5640_INL_INR_VOL:
case RT5640_DAC1_DIG_VOL:
case RT5640_DAC2_DIG_VOL:
case RT5640_DAC2_CTRL:
case RT5640_ADC_DIG_VOL:
case RT5640_ADC_DATA:
case RT5640_ADC_BST_VOL:
case RT5640_STO_ADC_MIXER:
case RT5640_MONO_ADC_MIXER:
case RT5640_AD_DA_MIXER:
case RT5640_STO_DAC_MIXER:
case RT5640_MONO_DAC_MIXER:
case RT5640_DIG_MIXER:
case RT5640_DSP_PATH1:
case RT5640_DSP_PATH2:
case RT5640_DIG_INF_DATA:
case RT5640_REC_L1_MIXER:
case RT5640_REC_L2_MIXER:
case RT5640_REC_R1_MIXER:
case RT5640_REC_R2_MIXER:
case RT5640_HPO_MIXER:
case RT5640_SPK_L_MIXER:
case RT5640_SPK_R_MIXER:
case RT5640_SPO_L_MIXER:
case RT5640_SPO_R_MIXER:
case RT5640_SPO_CLSD_RATIO:
case RT5640_MONO_MIXER:
case RT5640_OUT_L1_MIXER:
case RT5640_OUT_L2_MIXER:
case RT5640_OUT_L3_MIXER:
case RT5640_OUT_R1_MIXER:
case RT5640_OUT_R2_MIXER:
case RT5640_OUT_R3_MIXER:
case RT5640_LOUT_MIXER:
case RT5640_PWR_DIG1:
case RT5640_PWR_DIG2:
case RT5640_PWR_ANLG1:
case RT5640_PWR_ANLG2:
case RT5640_PWR_MIXER:
case RT5640_PWR_VOL:
case RT5640_PRIV_INDEX:
case RT5640_PRIV_DATA:
case RT5640_I2S1_SDP:
case RT5640_I2S2_SDP:
case RT5640_ADDA_CLK1:
case RT5640_ADDA_CLK2:
case RT5640_DMIC:
case RT5640_GLB_CLK:
case RT5640_PLL_CTRL1:
case RT5640_PLL_CTRL2:
case RT5640_ASRC_1:
case RT5640_ASRC_2:
case RT5640_ASRC_3:
case RT5640_ASRC_4:
case RT5640_ASRC_5:
case RT5640_HP_OVCD:
case RT5640_CLS_D_OVCD:
case RT5640_CLS_D_OUT:
case RT5640_DEPOP_M1:
case RT5640_DEPOP_M2:
case RT5640_DEPOP_M3:
case RT5640_CHARGE_PUMP:
case RT5640_PV_DET_SPK_G:
case RT5640_MICBIAS:
case RT5640_EQ_CTRL1:
case RT5640_EQ_CTRL2:
case RT5640_WIND_FILTER:
case RT5640_DRC_AGC_1:
case RT5640_DRC_AGC_2:
case RT5640_DRC_AGC_3:
case RT5640_SVOL_ZC:
case RT5640_ANC_CTRL1:
case RT5640_ANC_CTRL2:
case RT5640_ANC_CTRL3:
case RT5640_JD_CTRL:
case RT5640_ANC_JD:
case RT5640_IRQ_CTRL1:
case RT5640_IRQ_CTRL2:
case RT5640_INT_IRQ_ST:
case RT5640_GPIO_CTRL1:
case RT5640_GPIO_CTRL2:
case RT5640_GPIO_CTRL3:
case RT5640_DSP_CTRL1:
case RT5640_DSP_CTRL2:
case RT5640_DSP_CTRL3:
case RT5640_DSP_CTRL4:
case RT5640_PGM_REG_ARR1:
case RT5640_PGM_REG_ARR2:
case RT5640_PGM_REG_ARR3:
case RT5640_PGM_REG_ARR4:
case RT5640_PGM_REG_ARR5:
case RT5640_SCB_FUNC:
case RT5640_SCB_CTRL:
case RT5640_BASE_BACK:
case RT5640_MP3_PLUS1:
case RT5640_MP3_PLUS2:
case RT5640_3D_HP:
case RT5640_ADJ_HPF:
case RT5640_HP_CALIB_AMP_DET:
case RT5640_HP_CALIB2:
case RT5640_SV_ZCD1:
case RT5640_SV_ZCD2:
case RT5640_DUMMY1:
case RT5640_DUMMY2:
case RT5640_DUMMY3:
case RT5640_VENDOR_ID:
case RT5640_VENDOR_ID1:
case RT5640_VENDOR_ID2:
return true;
default:
return false;
}
}
static int set_dmic_clk(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = w->codec;
struct rt5640_priv *rt5640 = snd_soc_codec_get_drvdata(codec);
int div[] = {2, 3, 4, 6, 8, 12};
int idx = -EINVAL, i;
int rate, red, bound, temp;
rate = rt5640->sysclk;
red = 3000000 * 12;
for (i = 0; i < ARRAY_SIZE(div); i++) {
bound = div[i] * 3000000;
if (rate > bound)
continue;
temp = bound - rate;
if (temp < red) {
red = temp;
idx = i;
}
}
if (idx < 0)
dev_err(codec->dev, "Failed to set DMIC clock\n");
else
snd_soc_update_bits(codec, RT5640_DMIC, RT5640_DMIC_CLK_MASK,
idx << RT5640_DMIC_CLK_SFT);
return idx;
}
static int check_sysclk1_source(struct snd_soc_dapm_widget *source,
struct snd_soc_dapm_widget *sink)
{
unsigned int val;
val = snd_soc_read(source->codec, RT5640_GLB_CLK);
val &= RT5640_SCLK_SRC_MASK;
if (val == RT5640_SCLK_SRC_PLL1 || val == RT5640_SCLK_SRC_PLL1T)
return 1;
else
return 0;
}
static int rt5640_set_dmic1_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = w->codec;
switch (event) {
case SND_SOC_DAPM_PRE_PMU:
snd_soc_update_bits(codec, RT5640_GPIO_CTRL1,
RT5640_GP2_PIN_MASK | RT5640_GP3_PIN_MASK,
RT5640_GP2_PIN_DMIC1_SCL | RT5640_GP3_PIN_DMIC1_SDA);
snd_soc_update_bits(codec, RT5640_DMIC,
RT5640_DMIC_1L_LH_MASK | RT5640_DMIC_1R_LH_MASK |
RT5640_DMIC_1_DP_MASK,
RT5640_DMIC_1L_LH_FALLING | RT5640_DMIC_1R_LH_RISING |
RT5640_DMIC_1_DP_IN1P);
break;
default:
return 0;
}
return 0;
}
static int rt5640_set_dmic2_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = w->codec;
switch (event) {
case SND_SOC_DAPM_PRE_PMU:
snd_soc_update_bits(codec, RT5640_GPIO_CTRL1,
RT5640_GP2_PIN_MASK | RT5640_GP4_PIN_MASK,
RT5640_GP2_PIN_DMIC1_SCL | RT5640_GP4_PIN_DMIC2_SDA);
snd_soc_update_bits(codec, RT5640_DMIC,
RT5640_DMIC_2L_LH_MASK | RT5640_DMIC_2R_LH_MASK |
RT5640_DMIC_2_DP_MASK,
RT5640_DMIC_2L_LH_FALLING | RT5640_DMIC_2R_LH_RISING |
RT5640_DMIC_2_DP_IN1N);
break;
default:
return 0;
}
return 0;
}
static void hp_amp_power_on(struct snd_soc_codec *codec)
{
struct rt5640_priv *rt5640 = snd_soc_codec_get_drvdata(codec);
regmap_update_bits(rt5640->regmap, RT5640_PR_BASE +
RT5640_CHPUMP_INT_REG1, 0x0700, 0x0200);
regmap_update_bits(rt5640->regmap, RT5640_DEPOP_M2,
RT5640_DEPOP_MASK, RT5640_DEPOP_MAN);
regmap_update_bits(rt5640->regmap, RT5640_DEPOP_M1,
RT5640_HP_CP_MASK | RT5640_HP_SG_MASK | RT5640_HP_CB_MASK,
RT5640_HP_CP_PU | RT5640_HP_SG_DIS | RT5640_HP_CB_PU);
regmap_write(rt5640->regmap, RT5640_PR_BASE + RT5640_HP_DCC_INT1,
0x9f00);
regmap_update_bits(rt5640->regmap, RT5640_PWR_ANLG1,
RT5640_PWR_FV1 | RT5640_PWR_FV2, 0);
regmap_update_bits(rt5640->regmap, RT5640_PWR_ANLG1,
RT5640_PWR_HA,
RT5640_PWR_HA);
usleep_range(10000, 15000);
regmap_update_bits(rt5640->regmap, RT5640_PWR_ANLG1,
RT5640_PWR_FV1 | RT5640_PWR_FV2 ,
RT5640_PWR_FV1 | RT5640_PWR_FV2);
}
static void rt5640_pmu_depop(struct snd_soc_codec *codec)
{
struct rt5640_priv *rt5640 = snd_soc_codec_get_drvdata(codec);
regmap_update_bits(rt5640->regmap, RT5640_DEPOP_M2,
RT5640_DEPOP_MASK | RT5640_DIG_DP_MASK,
RT5640_DEPOP_AUTO | RT5640_DIG_DP_EN);
regmap_update_bits(rt5640->regmap, RT5640_CHARGE_PUMP,
RT5640_PM_HP_MASK, RT5640_PM_HP_HV);
regmap_update_bits(rt5640->regmap, RT5640_DEPOP_M3,
RT5640_CP_FQ1_MASK | RT5640_CP_FQ2_MASK | RT5640_CP_FQ3_MASK,
(RT5640_CP_FQ_192_KHZ << RT5640_CP_FQ1_SFT) |
(RT5640_CP_FQ_12_KHZ << RT5640_CP_FQ2_SFT) |
(RT5640_CP_FQ_192_KHZ << RT5640_CP_FQ3_SFT));
regmap_write(rt5640->regmap, RT5640_PR_BASE +
RT5640_MAMP_INT_REG2, 0x1c00);
regmap_update_bits(rt5640->regmap, RT5640_DEPOP_M1,
RT5640_HP_CP_MASK | RT5640_HP_SG_MASK,
RT5640_HP_CP_PD | RT5640_HP_SG_EN);
regmap_update_bits(rt5640->regmap, RT5640_PR_BASE +
RT5640_CHPUMP_INT_REG1, 0x0700, 0x0400);
}
static int rt5640_hp_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = w->codec;
struct rt5640_priv *rt5640 = snd_soc_codec_get_drvdata(codec);
switch (event) {
case SND_SOC_DAPM_POST_PMU:
rt5640_pmu_depop(codec);
rt5640->hp_mute = 0;
break;
case SND_SOC_DAPM_PRE_PMD:
rt5640->hp_mute = 1;
usleep_range(70000, 75000);
break;
default:
return 0;
}
return 0;
}
static int rt5640_hp_power_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = w->codec;
switch (event) {
case SND_SOC_DAPM_POST_PMU:
hp_amp_power_on(codec);
break;
default:
return 0;
}
return 0;
}
static int rt5640_hp_post_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = w->codec;
struct rt5640_priv *rt5640 = snd_soc_codec_get_drvdata(codec);
switch (event) {
case SND_SOC_DAPM_POST_PMU:
if (!rt5640->hp_mute)
usleep_range(80000, 85000);
break;
default:
return 0;
}
return 0;
}
static int get_sdp_info(struct snd_soc_codec *codec, int dai_id)
{
int ret = 0, val;
if (codec == NULL)
return -EINVAL;
val = snd_soc_read(codec, RT5640_I2S1_SDP);
val = (val & RT5640_I2S_IF_MASK) >> RT5640_I2S_IF_SFT;
switch (dai_id) {
case RT5640_AIF1:
switch (val) {
case RT5640_IF_123:
case RT5640_IF_132:
ret |= RT5640_U_IF1;
break;
case RT5640_IF_113:
ret |= RT5640_U_IF1;
case RT5640_IF_312:
case RT5640_IF_213:
ret |= RT5640_U_IF2;
break;
}
break;
case RT5640_AIF2:
switch (val) {
case RT5640_IF_231:
case RT5640_IF_213:
ret |= RT5640_U_IF1;
break;
case RT5640_IF_223:
ret |= RT5640_U_IF1;
case RT5640_IF_123:
case RT5640_IF_321:
ret |= RT5640_U_IF2;
break;
}
break;
default:
ret = -EINVAL;
break;
}
return ret;
}
static int get_clk_info(int sclk, int rate)
{
int i, pd[] = {1, 2, 3, 4, 6, 8, 12, 16};
if (sclk <= 0 || rate <= 0)
return -EINVAL;
rate = rate << 8;
for (i = 0; i < ARRAY_SIZE(pd); i++)
if (sclk == rate * pd[i])
return i;
return -EINVAL;
}
static int rt5640_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params, struct snd_soc_dai *dai)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_codec *codec = rtd->codec;
struct rt5640_priv *rt5640 = snd_soc_codec_get_drvdata(codec);
unsigned int val_len = 0, val_clk, mask_clk;
int dai_sel, pre_div, bclk_ms, frame_size;
rt5640->lrck[dai->id] = params_rate(params);
pre_div = get_clk_info(rt5640->sysclk, rt5640->lrck[dai->id]);
if (pre_div < 0) {
dev_err(codec->dev, "Unsupported clock setting %d for DAI %d\n",
rt5640->lrck[dai->id], dai->id);
return -EINVAL;
}
frame_size = snd_soc_params_to_frame_size(params);
if (frame_size < 0) {
dev_err(codec->dev, "Unsupported frame size: %d\n", frame_size);
return frame_size;
}
if (frame_size > 32)
bclk_ms = 1;
else
bclk_ms = 0;
rt5640->bclk[dai->id] = rt5640->lrck[dai->id] * (32 << bclk_ms);
dev_dbg(dai->dev, "bclk is %dHz and lrck is %dHz\n",
rt5640->bclk[dai->id], rt5640->lrck[dai->id]);
dev_dbg(dai->dev, "bclk_ms is %d and pre_div is %d for iis %d\n",
bclk_ms, pre_div, dai->id);
switch (params_format(params)) {
case SNDRV_PCM_FORMAT_S16_LE:
break;
case SNDRV_PCM_FORMAT_S20_3LE:
val_len |= RT5640_I2S_DL_20;
break;
case SNDRV_PCM_FORMAT_S24_LE:
val_len |= RT5640_I2S_DL_24;
break;
case SNDRV_PCM_FORMAT_S8:
val_len |= RT5640_I2S_DL_8;
break;
default:
return -EINVAL;
}
dai_sel = get_sdp_info(codec, dai->id);
if (dai_sel < 0) {
dev_err(codec->dev, "Failed to get sdp info: %d\n", dai_sel);
return -EINVAL;
}
if (dai_sel & RT5640_U_IF1) {
mask_clk = RT5640_I2S_BCLK_MS1_MASK | RT5640_I2S_PD1_MASK;
val_clk = bclk_ms << RT5640_I2S_BCLK_MS1_SFT |
pre_div << RT5640_I2S_PD1_SFT;
snd_soc_update_bits(codec, RT5640_I2S1_SDP,
RT5640_I2S_DL_MASK, val_len);
snd_soc_update_bits(codec, RT5640_ADDA_CLK1, mask_clk, val_clk);
}
if (dai_sel & RT5640_U_IF2) {
mask_clk = RT5640_I2S_BCLK_MS2_MASK | RT5640_I2S_PD2_MASK;
val_clk = bclk_ms << RT5640_I2S_BCLK_MS2_SFT |
pre_div << RT5640_I2S_PD2_SFT;
snd_soc_update_bits(codec, RT5640_I2S2_SDP,
RT5640_I2S_DL_MASK, val_len);
snd_soc_update_bits(codec, RT5640_ADDA_CLK1, mask_clk, val_clk);
}
return 0;
}
static int rt5640_set_dai_fmt(struct snd_soc_dai *dai, unsigned int fmt)
{
struct snd_soc_codec *codec = dai->codec;
struct rt5640_priv *rt5640 = snd_soc_codec_get_drvdata(codec);
unsigned int reg_val = 0;
int dai_sel;
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBM_CFM:
rt5640->master[dai->id] = 1;
break;
case SND_SOC_DAIFMT_CBS_CFS:
reg_val |= RT5640_I2S_MS_S;
rt5640->master[dai->id] = 0;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
break;
case SND_SOC_DAIFMT_IB_NF:
reg_val |= RT5640_I2S_BP_INV;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
break;
case SND_SOC_DAIFMT_LEFT_J:
reg_val |= RT5640_I2S_DF_LEFT;
break;
case SND_SOC_DAIFMT_DSP_A:
reg_val |= RT5640_I2S_DF_PCM_A;
break;
case SND_SOC_DAIFMT_DSP_B:
reg_val |= RT5640_I2S_DF_PCM_B;
break;
default:
return -EINVAL;
}
dai_sel = get_sdp_info(codec, dai->id);
if (dai_sel < 0) {
dev_err(codec->dev, "Failed to get sdp info: %d\n", dai_sel);
return -EINVAL;
}
if (dai_sel & RT5640_U_IF1) {
snd_soc_update_bits(codec, RT5640_I2S1_SDP,
RT5640_I2S_MS_MASK | RT5640_I2S_BP_MASK |
RT5640_I2S_DF_MASK, reg_val);
}
if (dai_sel & RT5640_U_IF2) {
snd_soc_update_bits(codec, RT5640_I2S2_SDP,
RT5640_I2S_MS_MASK | RT5640_I2S_BP_MASK |
RT5640_I2S_DF_MASK, reg_val);
}
return 0;
}
static int rt5640_set_dai_sysclk(struct snd_soc_dai *dai,
int clk_id, unsigned int freq, int dir)
{
struct snd_soc_codec *codec = dai->codec;
struct rt5640_priv *rt5640 = snd_soc_codec_get_drvdata(codec);
unsigned int reg_val = 0;
if (freq == rt5640->sysclk && clk_id == rt5640->sysclk_src)
return 0;
switch (clk_id) {
case RT5640_SCLK_S_MCLK:
reg_val |= RT5640_SCLK_SRC_MCLK;
break;
case RT5640_SCLK_S_PLL1:
reg_val |= RT5640_SCLK_SRC_PLL1;
break;
case RT5640_SCLK_S_PLL1_TK:
reg_val |= RT5640_SCLK_SRC_PLL1T;
break;
case RT5640_SCLK_S_RCCLK:
reg_val |= RT5640_SCLK_SRC_RCCLK;
break;
default:
dev_err(codec->dev, "Invalid clock id (%d)\n", clk_id);
return -EINVAL;
}
snd_soc_update_bits(codec, RT5640_GLB_CLK,
RT5640_SCLK_SRC_MASK, reg_val);
rt5640->sysclk = freq;
rt5640->sysclk_src = clk_id;
dev_dbg(dai->dev, "Sysclk is %dHz and clock id is %d\n", freq, clk_id);
return 0;
}
static int rt5640_pll_calc(const unsigned int freq_in,
const unsigned int freq_out, struct rt5640_pll_code *pll_code)
{
int max_n = RT5640_PLL_N_MAX, max_m = RT5640_PLL_M_MAX;
int n = 0, m = 0, red, n_t, m_t, in_t, out_t;
int red_t = abs(freq_out - freq_in);
bool bypass = false;
if (RT5640_PLL_INP_MAX < freq_in || RT5640_PLL_INP_MIN > freq_in)
return -EINVAL;
for (n_t = 0; n_t <= max_n; n_t++) {
in_t = (freq_in >> 1) + (freq_in >> 2) * n_t;
if (in_t < 0)
continue;
if (in_t == freq_out) {
bypass = true;
n = n_t;
goto code_find;
}
for (m_t = 0; m_t <= max_m; m_t++) {
out_t = in_t / (m_t + 2);
red = abs(out_t - freq_out);
if (red < red_t) {
n = n_t;
m = m_t;
if (red == 0)
goto code_find;
red_t = red;
}
}
}
pr_debug("Only get approximation about PLL\n");
code_find:
pll_code->m_bp = bypass;
pll_code->m_code = m;
pll_code->n_code = n;
pll_code->k_code = 2;
return 0;
}
static int rt5640_set_dai_pll(struct snd_soc_dai *dai, int pll_id, int source,
unsigned int freq_in, unsigned int freq_out)
{
struct snd_soc_codec *codec = dai->codec;
struct rt5640_priv *rt5640 = snd_soc_codec_get_drvdata(codec);
struct rt5640_pll_code *pll_code = &rt5640->pll_code;
int ret, dai_sel;
if (source == rt5640->pll_src && freq_in == rt5640->pll_in &&
freq_out == rt5640->pll_out)
return 0;
if (!freq_in || !freq_out) {
dev_dbg(codec->dev, "PLL disabled\n");
rt5640->pll_in = 0;
rt5640->pll_out = 0;
snd_soc_update_bits(codec, RT5640_GLB_CLK,
RT5640_SCLK_SRC_MASK, RT5640_SCLK_SRC_MCLK);
return 0;
}
switch (source) {
case RT5640_PLL1_S_MCLK:
snd_soc_update_bits(codec, RT5640_GLB_CLK,
RT5640_PLL1_SRC_MASK, RT5640_PLL1_SRC_MCLK);
break;
case RT5640_PLL1_S_BCLK1:
case RT5640_PLL1_S_BCLK2:
dai_sel = get_sdp_info(codec, dai->id);
if (dai_sel < 0) {
dev_err(codec->dev,
"Failed to get sdp info: %d\n", dai_sel);
return -EINVAL;
}
if (dai_sel & RT5640_U_IF1) {
snd_soc_update_bits(codec, RT5640_GLB_CLK,
RT5640_PLL1_SRC_MASK, RT5640_PLL1_SRC_BCLK1);
}
if (dai_sel & RT5640_U_IF2) {
snd_soc_update_bits(codec, RT5640_GLB_CLK,
RT5640_PLL1_SRC_MASK, RT5640_PLL1_SRC_BCLK2);
}
break;
default:
dev_err(codec->dev, "Unknown PLL source %d\n", source);
return -EINVAL;
}
ret = rt5640_pll_calc(freq_in, freq_out, pll_code);
if (ret < 0) {
dev_err(codec->dev, "Unsupport input clock %d\n", freq_in);
return ret;
}
dev_dbg(codec->dev, "bypass=%d m=%d n=%d k=2\n", pll_code->m_bp,
(pll_code->m_bp ? 0 : pll_code->m_code), pll_code->n_code);
snd_soc_write(codec, RT5640_PLL_CTRL1,
pll_code->n_code << RT5640_PLL_N_SFT | pll_code->k_code);
snd_soc_write(codec, RT5640_PLL_CTRL2,
(pll_code->m_bp ? 0 : pll_code->m_code) << RT5640_PLL_M_SFT |
pll_code->m_bp << RT5640_PLL_M_BP_SFT);
rt5640->pll_in = freq_in;
rt5640->pll_out = freq_out;
rt5640->pll_src = source;
return 0;
}
static int rt5640_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
struct rt5640_priv *rt5640 = snd_soc_codec_get_drvdata(codec);
switch (level) {
case SND_SOC_BIAS_STANDBY:
if (SND_SOC_BIAS_OFF == codec->dapm.bias_level) {
regcache_cache_only(rt5640->regmap, false);
snd_soc_update_bits(codec, RT5640_PWR_ANLG1,
RT5640_PWR_VREF1 | RT5640_PWR_MB |
RT5640_PWR_BG | RT5640_PWR_VREF2,
RT5640_PWR_VREF1 | RT5640_PWR_MB |
RT5640_PWR_BG | RT5640_PWR_VREF2);
usleep_range(10000, 15000);
snd_soc_update_bits(codec, RT5640_PWR_ANLG1,
RT5640_PWR_FV1 | RT5640_PWR_FV2,
RT5640_PWR_FV1 | RT5640_PWR_FV2);
regcache_sync(rt5640->regmap);
snd_soc_update_bits(codec, RT5640_DUMMY1,
0x0301, 0x0301);
snd_soc_update_bits(codec, RT5640_MICBIAS,
0x0030, 0x0030);
}
break;
case SND_SOC_BIAS_OFF:
snd_soc_write(codec, RT5640_DEPOP_M1, 0x0004);
snd_soc_write(codec, RT5640_DEPOP_M2, 0x1100);
snd_soc_update_bits(codec, RT5640_DUMMY1, 0x1, 0);
snd_soc_write(codec, RT5640_PWR_DIG1, 0x0000);
snd_soc_write(codec, RT5640_PWR_DIG2, 0x0000);
snd_soc_write(codec, RT5640_PWR_VOL, 0x0000);
snd_soc_write(codec, RT5640_PWR_MIXER, 0x0000);
snd_soc_write(codec, RT5640_PWR_ANLG1, 0x0000);
snd_soc_write(codec, RT5640_PWR_ANLG2, 0x0000);
break;
default:
break;
}
codec->dapm.bias_level = level;
return 0;
}
static int rt5640_probe(struct snd_soc_codec *codec)
{
struct rt5640_priv *rt5640 = snd_soc_codec_get_drvdata(codec);
int ret;
rt5640->codec = codec;
codec->control_data = rt5640->regmap;
ret = snd_soc_codec_set_cache_io(codec, 8, 16, SND_SOC_REGMAP);
if (ret != 0) {
dev_err(codec->dev, "Failed to set cache I/O: %d\n", ret);
return ret;
}
codec->dapm.idle_bias_off = 1;
rt5640_set_bias_level(codec, SND_SOC_BIAS_OFF);
snd_soc_update_bits(codec, RT5640_DUMMY1, 0x0301, 0x0301);
snd_soc_update_bits(codec, RT5640_MICBIAS, 0x0030, 0x0030);
snd_soc_update_bits(codec, RT5640_DSP_PATH2, 0xfc00, 0x0c00);
return 0;
}
static int rt5640_remove(struct snd_soc_codec *codec)
{
rt5640_reset(codec);
return 0;
}
static int rt5640_suspend(struct snd_soc_codec *codec)
{
struct rt5640_priv *rt5640 = snd_soc_codec_get_drvdata(codec);
rt5640_set_bias_level(codec, SND_SOC_BIAS_OFF);
rt5640_reset(codec);
regcache_cache_only(rt5640->regmap, true);
regcache_mark_dirty(rt5640->regmap);
if (gpio_is_valid(rt5640->pdata.ldo1_en))
gpio_set_value_cansleep(rt5640->pdata.ldo1_en, 0);
return 0;
}
static int rt5640_resume(struct snd_soc_codec *codec)
{
struct rt5640_priv *rt5640 = snd_soc_codec_get_drvdata(codec);
if (gpio_is_valid(rt5640->pdata.ldo1_en)) {
gpio_set_value_cansleep(rt5640->pdata.ldo1_en, 1);
msleep(400);
}
return 0;
}
static int rt5640_parse_dt(struct rt5640_priv *rt5640, struct device_node *np)
{
rt5640->pdata.in1_diff = of_property_read_bool(np,
"realtek,in1-differential");
rt5640->pdata.in2_diff = of_property_read_bool(np,
"realtek,in2-differential");
rt5640->pdata.ldo1_en = of_get_named_gpio(np,
"realtek,ldo1-en-gpios", 0);
if (!gpio_is_valid(rt5640->pdata.ldo1_en) &&
(rt5640->pdata.ldo1_en != -ENOENT))
return rt5640->pdata.ldo1_en;
return 0;
}
static int rt5640_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct rt5640_platform_data *pdata = dev_get_platdata(&i2c->dev);
struct rt5640_priv *rt5640;
int ret;
unsigned int val;
rt5640 = devm_kzalloc(&i2c->dev,
sizeof(struct rt5640_priv),
GFP_KERNEL);
if (NULL == rt5640)
return -ENOMEM;
i2c_set_clientdata(i2c, rt5640);
if (pdata) {
rt5640->pdata = *pdata;
if (!rt5640->pdata.ldo1_en)
rt5640->pdata.ldo1_en = -EINVAL;
} else if (i2c->dev.of_node) {
ret = rt5640_parse_dt(rt5640, i2c->dev.of_node);
if (ret)
return ret;
} else
rt5640->pdata.ldo1_en = -EINVAL;
rt5640->regmap = devm_regmap_init_i2c(i2c, &rt5640_regmap);
if (IS_ERR(rt5640->regmap)) {
ret = PTR_ERR(rt5640->regmap);
dev_err(&i2c->dev, "Failed to allocate register map: %d\n",
ret);
return ret;
}
if (gpio_is_valid(rt5640->pdata.ldo1_en)) {
ret = devm_gpio_request_one(&i2c->dev, rt5640->pdata.ldo1_en,
GPIOF_OUT_INIT_HIGH,
"RT5640 LDO1_EN");
if (ret < 0) {
dev_err(&i2c->dev, "Failed to request LDO1_EN %d: %d\n",
rt5640->pdata.ldo1_en, ret);
return ret;
}
msleep(400);
}
regmap_read(rt5640->regmap, RT5640_VENDOR_ID2, &val);
if ((val != RT5640_DEVICE_ID)) {
dev_err(&i2c->dev,
"Device with ID register %x is not rt5640/39\n", val);
return -ENODEV;
}
regmap_write(rt5640->regmap, RT5640_RESET, 0);
ret = regmap_register_patch(rt5640->regmap, init_list,
ARRAY_SIZE(init_list));
if (ret != 0)
dev_warn(&i2c->dev, "Failed to apply regmap patch: %d\n", ret);
if (rt5640->pdata.in1_diff)
regmap_update_bits(rt5640->regmap, RT5640_IN1_IN2,
RT5640_IN_DF1, RT5640_IN_DF1);
if (rt5640->pdata.in2_diff)
regmap_update_bits(rt5640->regmap, RT5640_IN3_IN4,
RT5640_IN_DF2, RT5640_IN_DF2);
rt5640->hp_mute = 1;
ret = snd_soc_register_codec(&i2c->dev, &soc_codec_dev_rt5640,
rt5640_dai, ARRAY_SIZE(rt5640_dai));
if (ret < 0)
goto err;
return 0;
err:
return ret;
}
static int rt5640_i2c_remove(struct i2c_client *i2c)
{
snd_soc_unregister_codec(&i2c->dev);
return 0;
}
