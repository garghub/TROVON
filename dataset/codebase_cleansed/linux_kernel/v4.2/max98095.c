static bool max98095_readable(struct device *dev, unsigned int reg)
{
if (reg >= M98095_REG_CNT)
return 0;
return max98095_access[reg].readable != 0;
}
static bool max98095_volatile(struct device *dev, unsigned int reg)
{
if (reg > M98095_REG_MAX_CACHED)
return 1;
switch (reg) {
case M98095_000_HOST_DATA:
case M98095_001_HOST_INT_STS:
case M98095_002_HOST_RSP_STS:
case M98095_003_HOST_CMD_STS:
case M98095_004_CODEC_STS:
case M98095_005_DAI1_ALC_STS:
case M98095_006_DAI2_ALC_STS:
case M98095_007_JACK_AUTO_STS:
case M98095_008_JACK_MANUAL_STS:
case M98095_009_JACK_VBAT_STS:
case M98095_00A_ACC_ADC_STS:
case M98095_00B_MIC_NG_AGC_STS:
case M98095_00C_SPK_L_VOLT_STS:
case M98095_00D_SPK_R_VOLT_STS:
case M98095_00E_TEMP_SENSOR_STS:
return 1;
}
return 0;
}
static void m98095_eq_band(struct snd_soc_codec *codec, unsigned int dai,
unsigned int band, u16 *coefs)
{
unsigned int eq_reg;
unsigned int i;
if (WARN_ON(band > 4) ||
WARN_ON(dai > 1))
return;
eq_reg = dai ? M98095_142_DAI2_EQ_BASE : M98095_110_DAI1_EQ_BASE;
eq_reg += band * (M98095_COEFS_PER_BAND << 1);
for (i = 0; i < M98095_COEFS_PER_BAND; i++) {
snd_soc_write(codec, eq_reg++, M98095_BYTE1(coefs[i]));
snd_soc_write(codec, eq_reg++, M98095_BYTE0(coefs[i]));
}
}
static void m98095_biquad_band(struct snd_soc_codec *codec, unsigned int dai,
unsigned int band, u16 *coefs)
{
unsigned int bq_reg;
unsigned int i;
if (WARN_ON(band > 1) ||
WARN_ON(dai > 1))
return;
bq_reg = dai ? M98095_17E_DAI2_BQ_BASE : M98095_174_DAI1_BQ_BASE;
bq_reg += band * (M98095_COEFS_PER_BAND << 1);
for (i = 0; i < M98095_COEFS_PER_BAND; i++) {
snd_soc_write(codec, bq_reg++, M98095_BYTE1(coefs[i]));
snd_soc_write(codec, bq_reg++, M98095_BYTE0(coefs[i]));
}
}
static int max98095_mic1pre_set(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_soc_kcontrol_codec(kcontrol);
struct max98095_priv *max98095 = snd_soc_codec_get_drvdata(codec);
unsigned int sel = ucontrol->value.integer.value[0];
max98095->mic1pre = sel;
snd_soc_update_bits(codec, M98095_05F_LVL_MIC1, M98095_MICPRE_MASK,
(1+sel)<<M98095_MICPRE_SHIFT);
return 0;
}
static int max98095_mic1pre_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_soc_kcontrol_codec(kcontrol);
struct max98095_priv *max98095 = snd_soc_codec_get_drvdata(codec);
ucontrol->value.integer.value[0] = max98095->mic1pre;
return 0;
}
static int max98095_mic2pre_set(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_soc_kcontrol_codec(kcontrol);
struct max98095_priv *max98095 = snd_soc_codec_get_drvdata(codec);
unsigned int sel = ucontrol->value.integer.value[0];
max98095->mic2pre = sel;
snd_soc_update_bits(codec, M98095_060_LVL_MIC2, M98095_MICPRE_MASK,
(1+sel)<<M98095_MICPRE_SHIFT);
return 0;
}
static int max98095_mic2pre_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_soc_kcontrol_codec(kcontrol);
struct max98095_priv *max98095 = snd_soc_codec_get_drvdata(codec);
ucontrol->value.integer.value[0] = max98095->mic2pre;
return 0;
}
static int max98095_mic_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
struct max98095_priv *max98095 = snd_soc_codec_get_drvdata(codec);
switch (event) {
case SND_SOC_DAPM_POST_PMU:
if (w->reg == M98095_05F_LVL_MIC1) {
snd_soc_update_bits(codec, w->reg, M98095_MICPRE_MASK,
(1+max98095->mic1pre)<<M98095_MICPRE_SHIFT);
} else {
snd_soc_update_bits(codec, w->reg, M98095_MICPRE_MASK,
(1+max98095->mic2pre)<<M98095_MICPRE_SHIFT);
}
break;
case SND_SOC_DAPM_POST_PMD:
snd_soc_update_bits(codec, w->reg, M98095_MICPRE_MASK, 0);
break;
default:
return -EINVAL;
}
return 0;
}
static int max98095_line_pga(struct snd_soc_dapm_widget *w,
int event, u8 channel)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
struct max98095_priv *max98095 = snd_soc_codec_get_drvdata(codec);
u8 *state;
if (WARN_ON(!(channel == 1 || channel == 2)))
return -EINVAL;
state = &max98095->lin_state;
switch (event) {
case SND_SOC_DAPM_POST_PMU:
*state |= channel;
snd_soc_update_bits(codec, w->reg,
(1 << w->shift), (1 << w->shift));
break;
case SND_SOC_DAPM_POST_PMD:
*state &= ~channel;
if (*state == 0) {
snd_soc_update_bits(codec, w->reg,
(1 << w->shift), 0);
}
break;
default:
return -EINVAL;
}
return 0;
}
static int max98095_pga_in1_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *k, int event)
{
return max98095_line_pga(w, event, 1);
}
static int max98095_pga_in2_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *k, int event)
{
return max98095_line_pga(w, event, 2);
}
static int max98095_lineout_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
switch (event) {
case SND_SOC_DAPM_POST_PMU:
snd_soc_update_bits(codec, w->reg,
(1 << (w->shift+2)), (1 << (w->shift+2)));
break;
case SND_SOC_DAPM_POST_PMD:
snd_soc_update_bits(codec, w->reg,
(1 << (w->shift+2)), 0);
break;
default:
return -EINVAL;
}
return 0;
}
static int rate_value(int rate, u8 *value)
{
int i;
for (i = 0; i < ARRAY_SIZE(rate_table); i++) {
if (rate_table[i].rate >= rate) {
*value = rate_table[i].sr;
return 0;
}
}
*value = rate_table[0].sr;
return -EINVAL;
}
static int max98095_dai1_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct max98095_priv *max98095 = snd_soc_codec_get_drvdata(codec);
struct max98095_cdata *cdata;
unsigned long long ni;
unsigned int rate;
u8 regval;
cdata = &max98095->dai[0];
rate = params_rate(params);
switch (params_width(params)) {
case 16:
snd_soc_update_bits(codec, M98095_02A_DAI1_FORMAT,
M98095_DAI_WS, 0);
break;
case 24:
snd_soc_update_bits(codec, M98095_02A_DAI1_FORMAT,
M98095_DAI_WS, M98095_DAI_WS);
break;
default:
return -EINVAL;
}
if (rate_value(rate, &regval))
return -EINVAL;
snd_soc_update_bits(codec, M98095_027_DAI1_CLKMODE,
M98095_CLKMODE_MASK, regval);
cdata->rate = rate;
if (snd_soc_read(codec, M98095_02A_DAI1_FORMAT) & M98095_DAI_MAS) {
if (max98095->sysclk == 0) {
dev_err(codec->dev, "Invalid system clock frequency\n");
return -EINVAL;
}
ni = 65536ULL * (rate < 50000 ? 96ULL : 48ULL)
* (unsigned long long int)rate;
do_div(ni, (unsigned long long int)max98095->sysclk);
snd_soc_write(codec, M98095_028_DAI1_CLKCFG_HI,
(ni >> 8) & 0x7F);
snd_soc_write(codec, M98095_029_DAI1_CLKCFG_LO,
ni & 0xFF);
}
if (rate < 50000)
snd_soc_update_bits(codec, M98095_02E_DAI1_FILTERS,
M98095_DAI_DHF, 0);
else
snd_soc_update_bits(codec, M98095_02E_DAI1_FILTERS,
M98095_DAI_DHF, M98095_DAI_DHF);
return 0;
}
static int max98095_dai2_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct max98095_priv *max98095 = snd_soc_codec_get_drvdata(codec);
struct max98095_cdata *cdata;
unsigned long long ni;
unsigned int rate;
u8 regval;
cdata = &max98095->dai[1];
rate = params_rate(params);
switch (params_width(params)) {
case 16:
snd_soc_update_bits(codec, M98095_034_DAI2_FORMAT,
M98095_DAI_WS, 0);
break;
case 24:
snd_soc_update_bits(codec, M98095_034_DAI2_FORMAT,
M98095_DAI_WS, M98095_DAI_WS);
break;
default:
return -EINVAL;
}
if (rate_value(rate, &regval))
return -EINVAL;
snd_soc_update_bits(codec, M98095_031_DAI2_CLKMODE,
M98095_CLKMODE_MASK, regval);
cdata->rate = rate;
if (snd_soc_read(codec, M98095_034_DAI2_FORMAT) & M98095_DAI_MAS) {
if (max98095->sysclk == 0) {
dev_err(codec->dev, "Invalid system clock frequency\n");
return -EINVAL;
}
ni = 65536ULL * (rate < 50000 ? 96ULL : 48ULL)
* (unsigned long long int)rate;
do_div(ni, (unsigned long long int)max98095->sysclk);
snd_soc_write(codec, M98095_032_DAI2_CLKCFG_HI,
(ni >> 8) & 0x7F);
snd_soc_write(codec, M98095_033_DAI2_CLKCFG_LO,
ni & 0xFF);
}
if (rate < 50000)
snd_soc_update_bits(codec, M98095_038_DAI2_FILTERS,
M98095_DAI_DHF, 0);
else
snd_soc_update_bits(codec, M98095_038_DAI2_FILTERS,
M98095_DAI_DHF, M98095_DAI_DHF);
return 0;
}
static int max98095_dai3_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct max98095_priv *max98095 = snd_soc_codec_get_drvdata(codec);
struct max98095_cdata *cdata;
unsigned long long ni;
unsigned int rate;
u8 regval;
cdata = &max98095->dai[2];
rate = params_rate(params);
switch (params_width(params)) {
case 16:
snd_soc_update_bits(codec, M98095_03E_DAI3_FORMAT,
M98095_DAI_WS, 0);
break;
case 24:
snd_soc_update_bits(codec, M98095_03E_DAI3_FORMAT,
M98095_DAI_WS, M98095_DAI_WS);
break;
default:
return -EINVAL;
}
if (rate_value(rate, &regval))
return -EINVAL;
snd_soc_update_bits(codec, M98095_03B_DAI3_CLKMODE,
M98095_CLKMODE_MASK, regval);
cdata->rate = rate;
if (snd_soc_read(codec, M98095_03E_DAI3_FORMAT) & M98095_DAI_MAS) {
if (max98095->sysclk == 0) {
dev_err(codec->dev, "Invalid system clock frequency\n");
return -EINVAL;
}
ni = 65536ULL * (rate < 50000 ? 96ULL : 48ULL)
* (unsigned long long int)rate;
do_div(ni, (unsigned long long int)max98095->sysclk);
snd_soc_write(codec, M98095_03C_DAI3_CLKCFG_HI,
(ni >> 8) & 0x7F);
snd_soc_write(codec, M98095_03D_DAI3_CLKCFG_LO,
ni & 0xFF);
}
if (rate < 50000)
snd_soc_update_bits(codec, M98095_042_DAI3_FILTERS,
M98095_DAI_DHF, 0);
else
snd_soc_update_bits(codec, M98095_042_DAI3_FILTERS,
M98095_DAI_DHF, M98095_DAI_DHF);
return 0;
}
static int max98095_dai_set_sysclk(struct snd_soc_dai *dai,
int clk_id, unsigned int freq, int dir)
{
struct snd_soc_codec *codec = dai->codec;
struct max98095_priv *max98095 = snd_soc_codec_get_drvdata(codec);
if (freq == max98095->sysclk)
return 0;
if (!IS_ERR(max98095->mclk)) {
freq = clk_round_rate(max98095->mclk, freq);
clk_set_rate(max98095->mclk, freq);
}
if ((freq >= 10000000) && (freq < 20000000)) {
snd_soc_write(codec, M98095_026_SYS_CLK, 0x10);
} else if ((freq >= 20000000) && (freq < 40000000)) {
snd_soc_write(codec, M98095_026_SYS_CLK, 0x20);
} else if ((freq >= 40000000) && (freq < 60000000)) {
snd_soc_write(codec, M98095_026_SYS_CLK, 0x30);
} else {
dev_err(codec->dev, "Invalid master clock frequency\n");
return -EINVAL;
}
dev_dbg(dai->dev, "Clock source is %d at %uHz\n", clk_id, freq);
max98095->sysclk = freq;
return 0;
}
static int max98095_dai1_set_fmt(struct snd_soc_dai *codec_dai,
unsigned int fmt)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct max98095_priv *max98095 = snd_soc_codec_get_drvdata(codec);
struct max98095_cdata *cdata;
u8 regval = 0;
cdata = &max98095->dai[0];
if (fmt != cdata->fmt) {
cdata->fmt = fmt;
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBS_CFS:
snd_soc_write(codec, M98095_028_DAI1_CLKCFG_HI,
0x80);
snd_soc_write(codec, M98095_029_DAI1_CLKCFG_LO,
0x00);
break;
case SND_SOC_DAIFMT_CBM_CFM:
regval |= M98095_DAI_MAS;
break;
case SND_SOC_DAIFMT_CBS_CFM:
case SND_SOC_DAIFMT_CBM_CFS:
default:
dev_err(codec->dev, "Clock mode unsupported");
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
regval |= M98095_DAI_DLY;
break;
case SND_SOC_DAIFMT_LEFT_J:
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
break;
case SND_SOC_DAIFMT_NB_IF:
regval |= M98095_DAI_WCI;
break;
case SND_SOC_DAIFMT_IB_NF:
regval |= M98095_DAI_BCI;
break;
case SND_SOC_DAIFMT_IB_IF:
regval |= M98095_DAI_BCI|M98095_DAI_WCI;
break;
default:
return -EINVAL;
}
snd_soc_update_bits(codec, M98095_02A_DAI1_FORMAT,
M98095_DAI_MAS | M98095_DAI_DLY | M98095_DAI_BCI |
M98095_DAI_WCI, regval);
snd_soc_write(codec, M98095_02B_DAI1_CLOCK, M98095_DAI_BSEL64);
}
return 0;
}
static int max98095_dai2_set_fmt(struct snd_soc_dai *codec_dai,
unsigned int fmt)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct max98095_priv *max98095 = snd_soc_codec_get_drvdata(codec);
struct max98095_cdata *cdata;
u8 regval = 0;
cdata = &max98095->dai[1];
if (fmt != cdata->fmt) {
cdata->fmt = fmt;
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBS_CFS:
snd_soc_write(codec, M98095_032_DAI2_CLKCFG_HI,
0x80);
snd_soc_write(codec, M98095_033_DAI2_CLKCFG_LO,
0x00);
break;
case SND_SOC_DAIFMT_CBM_CFM:
regval |= M98095_DAI_MAS;
break;
case SND_SOC_DAIFMT_CBS_CFM:
case SND_SOC_DAIFMT_CBM_CFS:
default:
dev_err(codec->dev, "Clock mode unsupported");
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
regval |= M98095_DAI_DLY;
break;
case SND_SOC_DAIFMT_LEFT_J:
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
break;
case SND_SOC_DAIFMT_NB_IF:
regval |= M98095_DAI_WCI;
break;
case SND_SOC_DAIFMT_IB_NF:
regval |= M98095_DAI_BCI;
break;
case SND_SOC_DAIFMT_IB_IF:
regval |= M98095_DAI_BCI|M98095_DAI_WCI;
break;
default:
return -EINVAL;
}
snd_soc_update_bits(codec, M98095_034_DAI2_FORMAT,
M98095_DAI_MAS | M98095_DAI_DLY | M98095_DAI_BCI |
M98095_DAI_WCI, regval);
snd_soc_write(codec, M98095_035_DAI2_CLOCK,
M98095_DAI_BSEL64);
}
return 0;
}
static int max98095_dai3_set_fmt(struct snd_soc_dai *codec_dai,
unsigned int fmt)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct max98095_priv *max98095 = snd_soc_codec_get_drvdata(codec);
struct max98095_cdata *cdata;
u8 regval = 0;
cdata = &max98095->dai[2];
if (fmt != cdata->fmt) {
cdata->fmt = fmt;
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBS_CFS:
snd_soc_write(codec, M98095_03C_DAI3_CLKCFG_HI,
0x80);
snd_soc_write(codec, M98095_03D_DAI3_CLKCFG_LO,
0x00);
break;
case SND_SOC_DAIFMT_CBM_CFM:
regval |= M98095_DAI_MAS;
break;
case SND_SOC_DAIFMT_CBS_CFM:
case SND_SOC_DAIFMT_CBM_CFS:
default:
dev_err(codec->dev, "Clock mode unsupported");
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
regval |= M98095_DAI_DLY;
break;
case SND_SOC_DAIFMT_LEFT_J:
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
break;
case SND_SOC_DAIFMT_NB_IF:
regval |= M98095_DAI_WCI;
break;
case SND_SOC_DAIFMT_IB_NF:
regval |= M98095_DAI_BCI;
break;
case SND_SOC_DAIFMT_IB_IF:
regval |= M98095_DAI_BCI|M98095_DAI_WCI;
break;
default:
return -EINVAL;
}
snd_soc_update_bits(codec, M98095_03E_DAI3_FORMAT,
M98095_DAI_MAS | M98095_DAI_DLY | M98095_DAI_BCI |
M98095_DAI_WCI, regval);
snd_soc_write(codec, M98095_03F_DAI3_CLOCK,
M98095_DAI_BSEL64);
}
return 0;
}
static int max98095_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
struct max98095_priv *max98095 = snd_soc_codec_get_drvdata(codec);
int ret;
switch (level) {
case SND_SOC_BIAS_ON:
break;
case SND_SOC_BIAS_PREPARE:
if (IS_ERR(max98095->mclk))
break;
if (snd_soc_codec_get_bias_level(codec) == SND_SOC_BIAS_ON)
clk_disable_unprepare(max98095->mclk);
else
clk_prepare_enable(max98095->mclk);
break;
case SND_SOC_BIAS_STANDBY:
if (snd_soc_codec_get_bias_level(codec) == SND_SOC_BIAS_OFF) {
ret = regcache_sync(max98095->regmap);
if (ret != 0) {
dev_err(codec->dev, "Failed to sync cache: %d\n", ret);
return ret;
}
}
snd_soc_update_bits(codec, M98095_090_PWR_EN_IN,
M98095_MBEN, M98095_MBEN);
break;
case SND_SOC_BIAS_OFF:
snd_soc_update_bits(codec, M98095_090_PWR_EN_IN,
M98095_MBEN, 0);
regcache_mark_dirty(max98095->regmap);
break;
}
return 0;
}
static int max98095_get_eq_channel(const char *name)
{
if (strcmp(name, "EQ1 Mode") == 0)
return 0;
if (strcmp(name, "EQ2 Mode") == 0)
return 1;
return -EINVAL;
}
static int max98095_put_eq_enum(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_soc_kcontrol_codec(kcontrol);
struct max98095_priv *max98095 = snd_soc_codec_get_drvdata(codec);
struct max98095_pdata *pdata = max98095->pdata;
int channel = max98095_get_eq_channel(kcontrol->id.name);
struct max98095_cdata *cdata;
unsigned int sel = ucontrol->value.integer.value[0];
struct max98095_eq_cfg *coef_set;
int fs, best, best_val, i;
int regmask, regsave;
if (WARN_ON(channel > 1))
return -EINVAL;
if (!pdata || !max98095->eq_textcnt)
return 0;
if (sel >= pdata->eq_cfgcnt)
return -EINVAL;
cdata = &max98095->dai[channel];
cdata->eq_sel = sel;
fs = cdata->rate;
best = 0;
best_val = INT_MAX;
for (i = 0; i < pdata->eq_cfgcnt; i++) {
if (strcmp(pdata->eq_cfg[i].name, max98095->eq_texts[sel]) == 0 &&
abs(pdata->eq_cfg[i].rate - fs) < best_val) {
best = i;
best_val = abs(pdata->eq_cfg[i].rate - fs);
}
}
dev_dbg(codec->dev, "Selected %s/%dHz for %dHz sample rate\n",
pdata->eq_cfg[best].name,
pdata->eq_cfg[best].rate, fs);
coef_set = &pdata->eq_cfg[best];
regmask = (channel == 0) ? M98095_EQ1EN : M98095_EQ2EN;
regsave = snd_soc_read(codec, M98095_088_CFG_LEVEL);
snd_soc_update_bits(codec, M98095_088_CFG_LEVEL, regmask, 0);
mutex_lock(&max98095->lock);
snd_soc_update_bits(codec, M98095_00F_HOST_CFG, M98095_SEG, M98095_SEG);
m98095_eq_band(codec, channel, 0, coef_set->band1);
m98095_eq_band(codec, channel, 1, coef_set->band2);
m98095_eq_band(codec, channel, 2, coef_set->band3);
m98095_eq_band(codec, channel, 3, coef_set->band4);
m98095_eq_band(codec, channel, 4, coef_set->band5);
snd_soc_update_bits(codec, M98095_00F_HOST_CFG, M98095_SEG, 0);
mutex_unlock(&max98095->lock);
snd_soc_update_bits(codec, M98095_088_CFG_LEVEL, regmask, regsave);
return 0;
}
static int max98095_get_eq_enum(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_soc_kcontrol_codec(kcontrol);
struct max98095_priv *max98095 = snd_soc_codec_get_drvdata(codec);
int channel = max98095_get_eq_channel(kcontrol->id.name);
struct max98095_cdata *cdata;
cdata = &max98095->dai[channel];
ucontrol->value.enumerated.item[0] = cdata->eq_sel;
return 0;
}
static void max98095_handle_eq_pdata(struct snd_soc_codec *codec)
{
struct max98095_priv *max98095 = snd_soc_codec_get_drvdata(codec);
struct max98095_pdata *pdata = max98095->pdata;
struct max98095_eq_cfg *cfg;
unsigned int cfgcnt;
int i, j;
const char **t;
int ret;
struct snd_kcontrol_new controls[] = {
SOC_ENUM_EXT("EQ1 Mode",
max98095->eq_enum,
max98095_get_eq_enum,
max98095_put_eq_enum),
SOC_ENUM_EXT("EQ2 Mode",
max98095->eq_enum,
max98095_get_eq_enum,
max98095_put_eq_enum),
};
cfg = pdata->eq_cfg;
cfgcnt = pdata->eq_cfgcnt;
max98095->eq_textcnt = 0;
max98095->eq_texts = NULL;
for (i = 0; i < cfgcnt; i++) {
for (j = 0; j < max98095->eq_textcnt; j++) {
if (strcmp(cfg[i].name, max98095->eq_texts[j]) == 0)
break;
}
if (j != max98095->eq_textcnt)
continue;
t = krealloc(max98095->eq_texts,
sizeof(char *) * (max98095->eq_textcnt + 1),
GFP_KERNEL);
if (t == NULL)
continue;
t[max98095->eq_textcnt] = cfg[i].name;
max98095->eq_textcnt++;
max98095->eq_texts = t;
}
max98095->eq_enum.texts = max98095->eq_texts;
max98095->eq_enum.items = max98095->eq_textcnt;
ret = snd_soc_add_codec_controls(codec, controls, ARRAY_SIZE(controls));
if (ret != 0)
dev_err(codec->dev, "Failed to add EQ control: %d\n", ret);
}
static int max98095_get_bq_channel(struct snd_soc_codec *codec,
const char *name)
{
int i;
for (i = 0; i < ARRAY_SIZE(bq_mode_name); i++)
if (strcmp(name, bq_mode_name[i]) == 0)
return i;
dev_err(codec->dev, "Bad biquad channel name '%s'\n", name);
return -EINVAL;
}
static int max98095_put_bq_enum(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_soc_kcontrol_codec(kcontrol);
struct max98095_priv *max98095 = snd_soc_codec_get_drvdata(codec);
struct max98095_pdata *pdata = max98095->pdata;
int channel = max98095_get_bq_channel(codec, kcontrol->id.name);
struct max98095_cdata *cdata;
unsigned int sel = ucontrol->value.integer.value[0];
struct max98095_biquad_cfg *coef_set;
int fs, best, best_val, i;
int regmask, regsave;
if (channel < 0)
return channel;
if (!pdata || !max98095->bq_textcnt)
return 0;
if (sel >= pdata->bq_cfgcnt)
return -EINVAL;
cdata = &max98095->dai[channel];
cdata->bq_sel = sel;
fs = cdata->rate;
best = 0;
best_val = INT_MAX;
for (i = 0; i < pdata->bq_cfgcnt; i++) {
if (strcmp(pdata->bq_cfg[i].name, max98095->bq_texts[sel]) == 0 &&
abs(pdata->bq_cfg[i].rate - fs) < best_val) {
best = i;
best_val = abs(pdata->bq_cfg[i].rate - fs);
}
}
dev_dbg(codec->dev, "Selected %s/%dHz for %dHz sample rate\n",
pdata->bq_cfg[best].name,
pdata->bq_cfg[best].rate, fs);
coef_set = &pdata->bq_cfg[best];
regmask = (channel == 0) ? M98095_BQ1EN : M98095_BQ2EN;
regsave = snd_soc_read(codec, M98095_088_CFG_LEVEL);
snd_soc_update_bits(codec, M98095_088_CFG_LEVEL, regmask, 0);
mutex_lock(&max98095->lock);
snd_soc_update_bits(codec, M98095_00F_HOST_CFG, M98095_SEG, M98095_SEG);
m98095_biquad_band(codec, channel, 0, coef_set->band1);
m98095_biquad_band(codec, channel, 1, coef_set->band2);
snd_soc_update_bits(codec, M98095_00F_HOST_CFG, M98095_SEG, 0);
mutex_unlock(&max98095->lock);
snd_soc_update_bits(codec, M98095_088_CFG_LEVEL, regmask, regsave);
return 0;
}
static int max98095_get_bq_enum(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_soc_kcontrol_codec(kcontrol);
struct max98095_priv *max98095 = snd_soc_codec_get_drvdata(codec);
int channel = max98095_get_bq_channel(codec, kcontrol->id.name);
struct max98095_cdata *cdata;
if (channel < 0)
return channel;
cdata = &max98095->dai[channel];
ucontrol->value.enumerated.item[0] = cdata->bq_sel;
return 0;
}
static void max98095_handle_bq_pdata(struct snd_soc_codec *codec)
{
struct max98095_priv *max98095 = snd_soc_codec_get_drvdata(codec);
struct max98095_pdata *pdata = max98095->pdata;
struct max98095_biquad_cfg *cfg;
unsigned int cfgcnt;
int i, j;
const char **t;
int ret;
struct snd_kcontrol_new controls[] = {
SOC_ENUM_EXT((char *)bq_mode_name[0],
max98095->bq_enum,
max98095_get_bq_enum,
max98095_put_bq_enum),
SOC_ENUM_EXT((char *)bq_mode_name[1],
max98095->bq_enum,
max98095_get_bq_enum,
max98095_put_bq_enum),
};
BUILD_BUG_ON(ARRAY_SIZE(controls) != ARRAY_SIZE(bq_mode_name));
cfg = pdata->bq_cfg;
cfgcnt = pdata->bq_cfgcnt;
max98095->bq_textcnt = 0;
max98095->bq_texts = NULL;
for (i = 0; i < cfgcnt; i++) {
for (j = 0; j < max98095->bq_textcnt; j++) {
if (strcmp(cfg[i].name, max98095->bq_texts[j]) == 0)
break;
}
if (j != max98095->bq_textcnt)
continue;
t = krealloc(max98095->bq_texts,
sizeof(char *) * (max98095->bq_textcnt + 1),
GFP_KERNEL);
if (t == NULL)
continue;
t[max98095->bq_textcnt] = cfg[i].name;
max98095->bq_textcnt++;
max98095->bq_texts = t;
}
max98095->bq_enum.texts = max98095->bq_texts;
max98095->bq_enum.items = max98095->bq_textcnt;
ret = snd_soc_add_codec_controls(codec, controls, ARRAY_SIZE(controls));
if (ret != 0)
dev_err(codec->dev, "Failed to add Biquad control: %d\n", ret);
}
static void max98095_handle_pdata(struct snd_soc_codec *codec)
{
struct max98095_priv *max98095 = snd_soc_codec_get_drvdata(codec);
struct max98095_pdata *pdata = max98095->pdata;
u8 regval = 0;
if (!pdata) {
dev_dbg(codec->dev, "No platform data\n");
return;
}
if (pdata->digmic_left_mode)
regval |= M98095_DIGMIC_L;
if (pdata->digmic_right_mode)
regval |= M98095_DIGMIC_R;
snd_soc_write(codec, M98095_087_CFG_MIC, regval);
if (pdata->eq_cfgcnt)
max98095_handle_eq_pdata(codec);
if (pdata->bq_cfgcnt)
max98095_handle_bq_pdata(codec);
}
static irqreturn_t max98095_report_jack(int irq, void *data)
{
struct snd_soc_codec *codec = data;
struct max98095_priv *max98095 = snd_soc_codec_get_drvdata(codec);
unsigned int value;
int hp_report = 0;
int mic_report = 0;
value = snd_soc_read(codec, M98095_007_JACK_AUTO_STS);
if ((value & M98095_DDONE) == 0)
return IRQ_NONE;
if ((value & M98095_HP_IN || value & M98095_LO_IN) &&
max98095->headphone_jack)
hp_report |= SND_JACK_HEADPHONE;
if ((value & M98095_MIC_IN) && max98095->mic_jack)
mic_report |= SND_JACK_MICROPHONE;
if (max98095->headphone_jack == max98095->mic_jack) {
snd_soc_jack_report(max98095->headphone_jack,
hp_report | mic_report,
SND_JACK_HEADSET);
} else {
if (max98095->headphone_jack)
snd_soc_jack_report(max98095->headphone_jack,
hp_report, SND_JACK_HEADPHONE);
if (max98095->mic_jack)
snd_soc_jack_report(max98095->mic_jack,
mic_report, SND_JACK_MICROPHONE);
}
return IRQ_HANDLED;
}
static int max98095_jack_detect_enable(struct snd_soc_codec *codec)
{
struct max98095_priv *max98095 = snd_soc_codec_get_drvdata(codec);
int ret = 0;
int detect_enable = M98095_JDEN;
unsigned int slew = M98095_DEFAULT_SLEW_DELAY;
if (max98095->pdata->jack_detect_pin5en)
detect_enable |= M98095_PIN5EN;
if (max98095->pdata->jack_detect_delay)
slew = max98095->pdata->jack_detect_delay;
ret = snd_soc_write(codec, M98095_08E_JACK_DC_SLEW, slew);
if (ret < 0) {
dev_err(codec->dev, "Failed to cfg auto detect %d\n", ret);
return ret;
}
ret = snd_soc_write(codec, M98095_089_JACK_DET_AUTO, detect_enable);
if (ret < 0) {
dev_err(codec->dev, "Failed to cfg auto detect %d\n", ret);
return ret;
}
return ret;
}
static int max98095_jack_detect_disable(struct snd_soc_codec *codec)
{
int ret = 0;
ret = snd_soc_write(codec, M98095_089_JACK_DET_AUTO, 0x0);
if (ret < 0) {
dev_err(codec->dev, "Failed to cfg auto detect %d\n", ret);
return ret;
}
return ret;
}
int max98095_jack_detect(struct snd_soc_codec *codec,
struct snd_soc_jack *hp_jack, struct snd_soc_jack *mic_jack)
{
struct max98095_priv *max98095 = snd_soc_codec_get_drvdata(codec);
struct i2c_client *client = to_i2c_client(codec->dev);
int ret = 0;
max98095->headphone_jack = hp_jack;
max98095->mic_jack = mic_jack;
if (!hp_jack && !mic_jack)
return -EINVAL;
max98095_jack_detect_enable(codec);
ret = snd_soc_update_bits(codec, M98095_013_JACK_INT_EN,
M98095_IDDONE, M98095_IDDONE);
if (ret < 0) {
dev_err(codec->dev, "Failed to cfg jack irqs %d\n", ret);
return ret;
}
max98095_report_jack(client->irq, codec);
return 0;
}
static int max98095_suspend(struct snd_soc_codec *codec)
{
struct max98095_priv *max98095 = snd_soc_codec_get_drvdata(codec);
if (max98095->headphone_jack || max98095->mic_jack)
max98095_jack_detect_disable(codec);
snd_soc_codec_force_bias_level(codec, SND_SOC_BIAS_OFF);
return 0;
}
static int max98095_resume(struct snd_soc_codec *codec)
{
struct max98095_priv *max98095 = snd_soc_codec_get_drvdata(codec);
struct i2c_client *client = to_i2c_client(codec->dev);
snd_soc_codec_force_bias_level(codec, SND_SOC_BIAS_STANDBY);
if (max98095->headphone_jack || max98095->mic_jack) {
max98095_jack_detect_enable(codec);
max98095_report_jack(client->irq, codec);
}
return 0;
}
static int max98095_reset(struct snd_soc_codec *codec)
{
int i, ret;
ret = snd_soc_write(codec, M98095_00F_HOST_CFG, 0);
if (ret < 0) {
dev_err(codec->dev, "Failed to reset DSP: %d\n", ret);
return ret;
}
ret = snd_soc_write(codec, M98095_097_PWR_SYS, 0);
if (ret < 0) {
dev_err(codec->dev, "Failed to reset codec: %d\n", ret);
return ret;
}
for (i = M98095_010_HOST_INT_CFG; i < M98095_REG_MAX_CACHED; i++) {
ret = snd_soc_write(codec, i, snd_soc_read(codec, i));
if (ret < 0) {
dev_err(codec->dev, "Failed to reset: %d\n", ret);
return ret;
}
}
return ret;
}
static int max98095_probe(struct snd_soc_codec *codec)
{
struct max98095_priv *max98095 = snd_soc_codec_get_drvdata(codec);
struct max98095_cdata *cdata;
struct i2c_client *client;
int ret = 0;
max98095->mclk = devm_clk_get(codec->dev, "mclk");
if (PTR_ERR(max98095->mclk) == -EPROBE_DEFER)
return -EPROBE_DEFER;
max98095_reset(codec);
client = to_i2c_client(codec->dev);
max98095->sysclk = (unsigned)-1;
max98095->eq_textcnt = 0;
max98095->bq_textcnt = 0;
cdata = &max98095->dai[0];
cdata->rate = (unsigned)-1;
cdata->fmt = (unsigned)-1;
cdata->eq_sel = 0;
cdata->bq_sel = 0;
cdata = &max98095->dai[1];
cdata->rate = (unsigned)-1;
cdata->fmt = (unsigned)-1;
cdata->eq_sel = 0;
cdata->bq_sel = 0;
cdata = &max98095->dai[2];
cdata->rate = (unsigned)-1;
cdata->fmt = (unsigned)-1;
cdata->eq_sel = 0;
cdata->bq_sel = 0;
max98095->lin_state = 0;
max98095->mic1pre = 0;
max98095->mic2pre = 0;
if (client->irq) {
ret = request_threaded_irq(client->irq, NULL,
max98095_report_jack,
IRQF_TRIGGER_FALLING | IRQF_TRIGGER_RISING |
IRQF_ONESHOT, "max98095", codec);
if (ret) {
dev_err(codec->dev, "Failed to request IRQ: %d\n", ret);
goto err_access;
}
}
ret = snd_soc_read(codec, M98095_0FF_REV_ID);
if (ret < 0) {
dev_err(codec->dev, "Failure reading hardware revision: %d\n",
ret);
goto err_irq;
}
dev_info(codec->dev, "Hardware revision: %c\n", ret - 0x40 + 'A');
snd_soc_write(codec, M98095_097_PWR_SYS, M98095_PWRSV);
snd_soc_write(codec, M98095_048_MIX_DAC_LR,
M98095_DAI1L_TO_DACL|M98095_DAI1R_TO_DACR);
snd_soc_write(codec, M98095_049_MIX_DAC_M,
M98095_DAI2M_TO_DACM|M98095_DAI3M_TO_DACM);
snd_soc_write(codec, M98095_092_PWR_EN_OUT, M98095_SPK_SPREADSPECTRUM);
snd_soc_write(codec, M98095_045_CFG_DSP, M98095_DSPNORMAL);
snd_soc_write(codec, M98095_04E_CFG_HP, M98095_HPNORMAL);
snd_soc_write(codec, M98095_02C_DAI1_IOCFG,
M98095_S1NORMAL|M98095_SDATA);
snd_soc_write(codec, M98095_036_DAI2_IOCFG,
M98095_S2NORMAL|M98095_SDATA);
snd_soc_write(codec, M98095_040_DAI3_IOCFG,
M98095_S3NORMAL|M98095_SDATA);
max98095_handle_pdata(codec);
snd_soc_update_bits(codec, M98095_097_PWR_SYS, M98095_SHDNRUN,
M98095_SHDNRUN);
return 0;
err_irq:
if (client->irq)
free_irq(client->irq, codec);
err_access:
return ret;
}
static int max98095_remove(struct snd_soc_codec *codec)
{
struct max98095_priv *max98095 = snd_soc_codec_get_drvdata(codec);
struct i2c_client *client = to_i2c_client(codec->dev);
if (max98095->headphone_jack || max98095->mic_jack)
max98095_jack_detect_disable(codec);
if (client->irq)
free_irq(client->irq, codec);
return 0;
}
static int max98095_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct max98095_priv *max98095;
int ret;
max98095 = devm_kzalloc(&i2c->dev, sizeof(struct max98095_priv),
GFP_KERNEL);
if (max98095 == NULL)
return -ENOMEM;
mutex_init(&max98095->lock);
max98095->regmap = devm_regmap_init_i2c(i2c, &max98095_regmap);
if (IS_ERR(max98095->regmap)) {
ret = PTR_ERR(max98095->regmap);
dev_err(&i2c->dev, "Failed to allocate regmap: %d\n", ret);
return ret;
}
max98095->devtype = id->driver_data;
i2c_set_clientdata(i2c, max98095);
max98095->pdata = i2c->dev.platform_data;
ret = snd_soc_register_codec(&i2c->dev, &soc_codec_dev_max98095,
max98095_dai, ARRAY_SIZE(max98095_dai));
return ret;
}
static int max98095_i2c_remove(struct i2c_client *client)
{
snd_soc_unregister_codec(&client->dev);
return 0;
}
