static int max98088_volatile_register(struct snd_soc_codec *codec, unsigned int reg)
{
return max98088_access[reg].vol;
}
static void m98088_eq_band(struct snd_soc_codec *codec, unsigned int dai,
unsigned int band, u16 *coefs)
{
unsigned int eq_reg;
unsigned int i;
BUG_ON(band > 4);
BUG_ON(dai > 1);
eq_reg = dai ? M98088_REG_84_DAI2_EQ_BASE : M98088_REG_52_DAI1_EQ_BASE;
eq_reg += band * (M98088_COEFS_PER_BAND << 1);
for (i = 0; i < M98088_COEFS_PER_BAND; i++) {
snd_soc_write(codec, eq_reg++, M98088_BYTE1(coefs[i]));
snd_soc_write(codec, eq_reg++, M98088_BYTE0(coefs[i]));
}
}
static int max98088_mic1pre_set(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_kcontrol_chip(kcontrol);
struct max98088_priv *max98088 = snd_soc_codec_get_drvdata(codec);
unsigned int sel = ucontrol->value.integer.value[0];
max98088->mic1pre = sel;
snd_soc_update_bits(codec, M98088_REG_35_LVL_MIC1, M98088_MICPRE_MASK,
(1+sel)<<M98088_MICPRE_SHIFT);
return 0;
}
static int max98088_mic1pre_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_kcontrol_chip(kcontrol);
struct max98088_priv *max98088 = snd_soc_codec_get_drvdata(codec);
ucontrol->value.integer.value[0] = max98088->mic1pre;
return 0;
}
static int max98088_mic2pre_set(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_kcontrol_chip(kcontrol);
struct max98088_priv *max98088 = snd_soc_codec_get_drvdata(codec);
unsigned int sel = ucontrol->value.integer.value[0];
max98088->mic2pre = sel;
snd_soc_update_bits(codec, M98088_REG_36_LVL_MIC2, M98088_MICPRE_MASK,
(1+sel)<<M98088_MICPRE_SHIFT);
return 0;
}
static int max98088_mic2pre_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_kcontrol_chip(kcontrol);
struct max98088_priv *max98088 = snd_soc_codec_get_drvdata(codec);
ucontrol->value.integer.value[0] = max98088->mic2pre;
return 0;
}
static int max98088_mic_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = w->codec;
struct max98088_priv *max98088 = snd_soc_codec_get_drvdata(codec);
switch (event) {
case SND_SOC_DAPM_POST_PMU:
if (w->reg == M98088_REG_35_LVL_MIC1) {
snd_soc_update_bits(codec, w->reg, M98088_MICPRE_MASK,
(1+max98088->mic1pre)<<M98088_MICPRE_SHIFT);
} else {
snd_soc_update_bits(codec, w->reg, M98088_MICPRE_MASK,
(1+max98088->mic2pre)<<M98088_MICPRE_SHIFT);
}
break;
case SND_SOC_DAPM_POST_PMD:
snd_soc_update_bits(codec, w->reg, M98088_MICPRE_MASK, 0);
break;
default:
return -EINVAL;
}
return 0;
}
static int max98088_line_pga(struct snd_soc_dapm_widget *w,
int event, int line, u8 channel)
{
struct snd_soc_codec *codec = w->codec;
struct max98088_priv *max98088 = snd_soc_codec_get_drvdata(codec);
u8 *state;
BUG_ON(!((channel == 1) || (channel == 2)));
switch (line) {
case LINE_INA:
state = &max98088->ina_state;
break;
case LINE_INB:
state = &max98088->inb_state;
break;
default:
return -EINVAL;
}
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
static int max98088_pga_ina1_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *k, int event)
{
return max98088_line_pga(w, event, LINE_INA, 1);
}
static int max98088_pga_ina2_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *k, int event)
{
return max98088_line_pga(w, event, LINE_INA, 2);
}
static int max98088_pga_inb1_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *k, int event)
{
return max98088_line_pga(w, event, LINE_INB, 1);
}
static int max98088_pga_inb2_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *k, int event)
{
return max98088_line_pga(w, event, LINE_INB, 2);
}
static inline int rate_value(int rate, u8 *value)
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
static int max98088_dai1_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct max98088_priv *max98088 = snd_soc_codec_get_drvdata(codec);
struct max98088_cdata *cdata;
unsigned long long ni;
unsigned int rate;
u8 regval;
cdata = &max98088->dai[0];
rate = params_rate(params);
switch (params_format(params)) {
case SNDRV_PCM_FORMAT_S16_LE:
snd_soc_update_bits(codec, M98088_REG_14_DAI1_FORMAT,
M98088_DAI_WS, 0);
break;
case SNDRV_PCM_FORMAT_S24_LE:
snd_soc_update_bits(codec, M98088_REG_14_DAI1_FORMAT,
M98088_DAI_WS, M98088_DAI_WS);
break;
default:
return -EINVAL;
}
snd_soc_update_bits(codec, M98088_REG_51_PWR_SYS, M98088_SHDNRUN, 0);
if (rate_value(rate, &regval))
return -EINVAL;
snd_soc_update_bits(codec, M98088_REG_11_DAI1_CLKMODE,
M98088_CLKMODE_MASK, regval);
cdata->rate = rate;
if (snd_soc_read(codec, M98088_REG_14_DAI1_FORMAT)
& M98088_DAI_MAS) {
if (max98088->sysclk == 0) {
dev_err(codec->dev, "Invalid system clock frequency\n");
return -EINVAL;
}
ni = 65536ULL * (rate < 50000 ? 96ULL : 48ULL)
* (unsigned long long int)rate;
do_div(ni, (unsigned long long int)max98088->sysclk);
snd_soc_write(codec, M98088_REG_12_DAI1_CLKCFG_HI,
(ni >> 8) & 0x7F);
snd_soc_write(codec, M98088_REG_13_DAI1_CLKCFG_LO,
ni & 0xFF);
}
if (rate < 50000)
snd_soc_update_bits(codec, M98088_REG_18_DAI1_FILTERS,
M98088_DAI_DHF, 0);
else
snd_soc_update_bits(codec, M98088_REG_18_DAI1_FILTERS,
M98088_DAI_DHF, M98088_DAI_DHF);
snd_soc_update_bits(codec, M98088_REG_51_PWR_SYS, M98088_SHDNRUN,
M98088_SHDNRUN);
return 0;
}
static int max98088_dai2_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct max98088_priv *max98088 = snd_soc_codec_get_drvdata(codec);
struct max98088_cdata *cdata;
unsigned long long ni;
unsigned int rate;
u8 regval;
cdata = &max98088->dai[1];
rate = params_rate(params);
switch (params_format(params)) {
case SNDRV_PCM_FORMAT_S16_LE:
snd_soc_update_bits(codec, M98088_REG_1C_DAI2_FORMAT,
M98088_DAI_WS, 0);
break;
case SNDRV_PCM_FORMAT_S24_LE:
snd_soc_update_bits(codec, M98088_REG_1C_DAI2_FORMAT,
M98088_DAI_WS, M98088_DAI_WS);
break;
default:
return -EINVAL;
}
snd_soc_update_bits(codec, M98088_REG_51_PWR_SYS, M98088_SHDNRUN, 0);
if (rate_value(rate, &regval))
return -EINVAL;
snd_soc_update_bits(codec, M98088_REG_19_DAI2_CLKMODE,
M98088_CLKMODE_MASK, regval);
cdata->rate = rate;
if (snd_soc_read(codec, M98088_REG_1C_DAI2_FORMAT)
& M98088_DAI_MAS) {
if (max98088->sysclk == 0) {
dev_err(codec->dev, "Invalid system clock frequency\n");
return -EINVAL;
}
ni = 65536ULL * (rate < 50000 ? 96ULL : 48ULL)
* (unsigned long long int)rate;
do_div(ni, (unsigned long long int)max98088->sysclk);
snd_soc_write(codec, M98088_REG_1A_DAI2_CLKCFG_HI,
(ni >> 8) & 0x7F);
snd_soc_write(codec, M98088_REG_1B_DAI2_CLKCFG_LO,
ni & 0xFF);
}
if (rate < 50000)
snd_soc_update_bits(codec, M98088_REG_20_DAI2_FILTERS,
M98088_DAI_DHF, 0);
else
snd_soc_update_bits(codec, M98088_REG_20_DAI2_FILTERS,
M98088_DAI_DHF, M98088_DAI_DHF);
snd_soc_update_bits(codec, M98088_REG_51_PWR_SYS, M98088_SHDNRUN,
M98088_SHDNRUN);
return 0;
}
static int max98088_dai_set_sysclk(struct snd_soc_dai *dai,
int clk_id, unsigned int freq, int dir)
{
struct snd_soc_codec *codec = dai->codec;
struct max98088_priv *max98088 = snd_soc_codec_get_drvdata(codec);
if (freq == max98088->sysclk)
return 0;
if ((freq >= 10000000) && (freq < 20000000)) {
snd_soc_write(codec, M98088_REG_10_SYS_CLK, 0x10);
} else if ((freq >= 20000000) && (freq < 30000000)) {
snd_soc_write(codec, M98088_REG_10_SYS_CLK, 0x20);
} else {
dev_err(codec->dev, "Invalid master clock frequency\n");
return -EINVAL;
}
if (snd_soc_read(codec, M98088_REG_51_PWR_SYS) & M98088_SHDNRUN) {
snd_soc_update_bits(codec, M98088_REG_51_PWR_SYS,
M98088_SHDNRUN, 0);
snd_soc_update_bits(codec, M98088_REG_51_PWR_SYS,
M98088_SHDNRUN, M98088_SHDNRUN);
}
dev_dbg(dai->dev, "Clock source is %d at %uHz\n", clk_id, freq);
max98088->sysclk = freq;
return 0;
}
static int max98088_dai1_set_fmt(struct snd_soc_dai *codec_dai,
unsigned int fmt)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct max98088_priv *max98088 = snd_soc_codec_get_drvdata(codec);
struct max98088_cdata *cdata;
u8 reg15val;
u8 reg14val = 0;
cdata = &max98088->dai[0];
if (fmt != cdata->fmt) {
cdata->fmt = fmt;
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBS_CFS:
snd_soc_write(codec, M98088_REG_12_DAI1_CLKCFG_HI,
0x80);
snd_soc_write(codec, M98088_REG_13_DAI1_CLKCFG_LO,
0x00);
break;
case SND_SOC_DAIFMT_CBM_CFM:
reg14val |= M98088_DAI_MAS;
break;
case SND_SOC_DAIFMT_CBS_CFM:
case SND_SOC_DAIFMT_CBM_CFS:
default:
dev_err(codec->dev, "Clock mode unsupported");
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
reg14val |= M98088_DAI_DLY;
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
reg14val |= M98088_DAI_WCI;
break;
case SND_SOC_DAIFMT_IB_NF:
reg14val |= M98088_DAI_BCI;
break;
case SND_SOC_DAIFMT_IB_IF:
reg14val |= M98088_DAI_BCI|M98088_DAI_WCI;
break;
default:
return -EINVAL;
}
snd_soc_update_bits(codec, M98088_REG_14_DAI1_FORMAT,
M98088_DAI_MAS | M98088_DAI_DLY | M98088_DAI_BCI |
M98088_DAI_WCI, reg14val);
reg15val = M98088_DAI_BSEL64;
if (max98088->digmic)
reg15val |= M98088_DAI_OSR64;
snd_soc_write(codec, M98088_REG_15_DAI1_CLOCK, reg15val);
}
return 0;
}
static int max98088_dai2_set_fmt(struct snd_soc_dai *codec_dai,
unsigned int fmt)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct max98088_priv *max98088 = snd_soc_codec_get_drvdata(codec);
struct max98088_cdata *cdata;
u8 reg1Cval = 0;
cdata = &max98088->dai[1];
if (fmt != cdata->fmt) {
cdata->fmt = fmt;
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBS_CFS:
snd_soc_write(codec, M98088_REG_1A_DAI2_CLKCFG_HI,
0x80);
snd_soc_write(codec, M98088_REG_1B_DAI2_CLKCFG_LO,
0x00);
break;
case SND_SOC_DAIFMT_CBM_CFM:
reg1Cval |= M98088_DAI_MAS;
break;
case SND_SOC_DAIFMT_CBS_CFM:
case SND_SOC_DAIFMT_CBM_CFS:
default:
dev_err(codec->dev, "Clock mode unsupported");
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
reg1Cval |= M98088_DAI_DLY;
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
reg1Cval |= M98088_DAI_WCI;
break;
case SND_SOC_DAIFMT_IB_NF:
reg1Cval |= M98088_DAI_BCI;
break;
case SND_SOC_DAIFMT_IB_IF:
reg1Cval |= M98088_DAI_BCI|M98088_DAI_WCI;
break;
default:
return -EINVAL;
}
snd_soc_update_bits(codec, M98088_REG_1C_DAI2_FORMAT,
M98088_DAI_MAS | M98088_DAI_DLY | M98088_DAI_BCI |
M98088_DAI_WCI, reg1Cval);
snd_soc_write(codec, M98088_REG_1D_DAI2_CLOCK,
M98088_DAI_BSEL64);
}
return 0;
}
static int max98088_dai1_digital_mute(struct snd_soc_dai *codec_dai, int mute)
{
struct snd_soc_codec *codec = codec_dai->codec;
int reg;
if (mute)
reg = M98088_DAI_MUTE;
else
reg = 0;
snd_soc_update_bits(codec, M98088_REG_2F_LVL_DAI1_PLAY,
M98088_DAI_MUTE_MASK, reg);
return 0;
}
static int max98088_dai2_digital_mute(struct snd_soc_dai *codec_dai, int mute)
{
struct snd_soc_codec *codec = codec_dai->codec;
int reg;
if (mute)
reg = M98088_DAI_MUTE;
else
reg = 0;
snd_soc_update_bits(codec, M98088_REG_31_LVL_DAI2_PLAY,
M98088_DAI_MUTE_MASK, reg);
return 0;
}
static void max98088_sync_cache(struct snd_soc_codec *codec)
{
u16 *reg_cache = codec->reg_cache;
int i;
if (!codec->cache_sync)
return;
codec->cache_only = 0;
for (i = 1; i < codec->driver->reg_cache_size; i++) {
if (!max98088_access[i].writable)
continue;
if (reg_cache[i] == max98088_reg[i])
continue;
snd_soc_write(codec, i, reg_cache[i]);
}
codec->cache_sync = 0;
}
static int max98088_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
switch (level) {
case SND_SOC_BIAS_ON:
break;
case SND_SOC_BIAS_PREPARE:
break;
case SND_SOC_BIAS_STANDBY:
if (codec->dapm.bias_level == SND_SOC_BIAS_OFF)
max98088_sync_cache(codec);
snd_soc_update_bits(codec, M98088_REG_4C_PWR_EN_IN,
M98088_MBEN, M98088_MBEN);
break;
case SND_SOC_BIAS_OFF:
snd_soc_update_bits(codec, M98088_REG_4C_PWR_EN_IN,
M98088_MBEN, 0);
codec->cache_sync = 1;
break;
}
codec->dapm.bias_level = level;
return 0;
}
static int max98088_get_channel(struct snd_soc_codec *codec, const char *name)
{
int i;
for (i = 0; i < ARRAY_SIZE(eq_mode_name); i++)
if (strcmp(name, eq_mode_name[i]) == 0)
return i;
dev_err(codec->dev, "Bad EQ channel name '%s'\n", name);
return -EINVAL;
}
static void max98088_setup_eq1(struct snd_soc_codec *codec)
{
struct max98088_priv *max98088 = snd_soc_codec_get_drvdata(codec);
struct max98088_pdata *pdata = max98088->pdata;
struct max98088_eq_cfg *coef_set;
int best, best_val, save, i, sel, fs;
struct max98088_cdata *cdata;
cdata = &max98088->dai[0];
if (!pdata || !max98088->eq_textcnt)
return;
fs = cdata->rate;
sel = cdata->eq_sel;
best = 0;
best_val = INT_MAX;
for (i = 0; i < pdata->eq_cfgcnt; i++) {
if (strcmp(pdata->eq_cfg[i].name, max98088->eq_texts[sel]) == 0 &&
abs(pdata->eq_cfg[i].rate - fs) < best_val) {
best = i;
best_val = abs(pdata->eq_cfg[i].rate - fs);
}
}
dev_dbg(codec->dev, "Selected %s/%dHz for %dHz sample rate\n",
pdata->eq_cfg[best].name,
pdata->eq_cfg[best].rate, fs);
save = snd_soc_read(codec, M98088_REG_49_CFG_LEVEL);
snd_soc_update_bits(codec, M98088_REG_49_CFG_LEVEL, M98088_EQ1EN, 0);
coef_set = &pdata->eq_cfg[sel];
m98088_eq_band(codec, 0, 0, coef_set->band1);
m98088_eq_band(codec, 0, 1, coef_set->band2);
m98088_eq_band(codec, 0, 2, coef_set->band3);
m98088_eq_band(codec, 0, 3, coef_set->band4);
m98088_eq_band(codec, 0, 4, coef_set->band5);
snd_soc_update_bits(codec, M98088_REG_49_CFG_LEVEL, M98088_EQ1EN, save);
}
static void max98088_setup_eq2(struct snd_soc_codec *codec)
{
struct max98088_priv *max98088 = snd_soc_codec_get_drvdata(codec);
struct max98088_pdata *pdata = max98088->pdata;
struct max98088_eq_cfg *coef_set;
int best, best_val, save, i, sel, fs;
struct max98088_cdata *cdata;
cdata = &max98088->dai[1];
if (!pdata || !max98088->eq_textcnt)
return;
fs = cdata->rate;
sel = cdata->eq_sel;
best = 0;
best_val = INT_MAX;
for (i = 0; i < pdata->eq_cfgcnt; i++) {
if (strcmp(pdata->eq_cfg[i].name, max98088->eq_texts[sel]) == 0 &&
abs(pdata->eq_cfg[i].rate - fs) < best_val) {
best = i;
best_val = abs(pdata->eq_cfg[i].rate - fs);
}
}
dev_dbg(codec->dev, "Selected %s/%dHz for %dHz sample rate\n",
pdata->eq_cfg[best].name,
pdata->eq_cfg[best].rate, fs);
save = snd_soc_read(codec, M98088_REG_49_CFG_LEVEL);
snd_soc_update_bits(codec, M98088_REG_49_CFG_LEVEL, M98088_EQ2EN, 0);
coef_set = &pdata->eq_cfg[sel];
m98088_eq_band(codec, 1, 0, coef_set->band1);
m98088_eq_band(codec, 1, 1, coef_set->band2);
m98088_eq_band(codec, 1, 2, coef_set->band3);
m98088_eq_band(codec, 1, 3, coef_set->band4);
m98088_eq_band(codec, 1, 4, coef_set->band5);
snd_soc_update_bits(codec, M98088_REG_49_CFG_LEVEL, M98088_EQ2EN,
save);
}
static int max98088_put_eq_enum(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_kcontrol_chip(kcontrol);
struct max98088_priv *max98088 = snd_soc_codec_get_drvdata(codec);
struct max98088_pdata *pdata = max98088->pdata;
int channel = max98088_get_channel(codec, kcontrol->id.name);
struct max98088_cdata *cdata;
int sel = ucontrol->value.integer.value[0];
if (channel < 0)
return channel;
cdata = &max98088->dai[channel];
if (sel >= pdata->eq_cfgcnt)
return -EINVAL;
cdata->eq_sel = sel;
switch (channel) {
case 0:
max98088_setup_eq1(codec);
break;
case 1:
max98088_setup_eq2(codec);
break;
}
return 0;
}
static int max98088_get_eq_enum(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_kcontrol_chip(kcontrol);
struct max98088_priv *max98088 = snd_soc_codec_get_drvdata(codec);
int channel = max98088_get_channel(codec, kcontrol->id.name);
struct max98088_cdata *cdata;
if (channel < 0)
return channel;
cdata = &max98088->dai[channel];
ucontrol->value.enumerated.item[0] = cdata->eq_sel;
return 0;
}
static void max98088_handle_eq_pdata(struct snd_soc_codec *codec)
{
struct max98088_priv *max98088 = snd_soc_codec_get_drvdata(codec);
struct max98088_pdata *pdata = max98088->pdata;
struct max98088_eq_cfg *cfg;
unsigned int cfgcnt;
int i, j;
const char **t;
int ret;
struct snd_kcontrol_new controls[] = {
SOC_ENUM_EXT((char *)eq_mode_name[0],
max98088->eq_enum,
max98088_get_eq_enum,
max98088_put_eq_enum),
SOC_ENUM_EXT((char *)eq_mode_name[1],
max98088->eq_enum,
max98088_get_eq_enum,
max98088_put_eq_enum),
};
BUILD_BUG_ON(ARRAY_SIZE(controls) != ARRAY_SIZE(eq_mode_name));
cfg = pdata->eq_cfg;
cfgcnt = pdata->eq_cfgcnt;
max98088->eq_textcnt = 0;
max98088->eq_texts = NULL;
for (i = 0; i < cfgcnt; i++) {
for (j = 0; j < max98088->eq_textcnt; j++) {
if (strcmp(cfg[i].name, max98088->eq_texts[j]) == 0)
break;
}
if (j != max98088->eq_textcnt)
continue;
t = krealloc(max98088->eq_texts,
sizeof(char *) * (max98088->eq_textcnt + 1),
GFP_KERNEL);
if (t == NULL)
continue;
t[max98088->eq_textcnt] = cfg[i].name;
max98088->eq_textcnt++;
max98088->eq_texts = t;
}
max98088->eq_enum.texts = max98088->eq_texts;
max98088->eq_enum.max = max98088->eq_textcnt;
ret = snd_soc_add_codec_controls(codec, controls, ARRAY_SIZE(controls));
if (ret != 0)
dev_err(codec->dev, "Failed to add EQ control: %d\n", ret);
}
static void max98088_handle_pdata(struct snd_soc_codec *codec)
{
struct max98088_priv *max98088 = snd_soc_codec_get_drvdata(codec);
struct max98088_pdata *pdata = max98088->pdata;
u8 regval = 0;
if (!pdata) {
dev_dbg(codec->dev, "No platform data\n");
return;
}
if (pdata->digmic_left_mode)
regval |= M98088_DIGMIC_L;
if (pdata->digmic_right_mode)
regval |= M98088_DIGMIC_R;
max98088->digmic = (regval ? 1 : 0);
snd_soc_write(codec, M98088_REG_48_CFG_MIC, regval);
regval = ((pdata->receiver_mode) ? M98088_REC_LINEMODE : 0);
snd_soc_update_bits(codec, M98088_REG_2A_MIC_REC_CNTL,
M98088_REC_LINEMODE_MASK, regval);
if (pdata->eq_cfgcnt)
max98088_handle_eq_pdata(codec);
}
static int max98088_suspend(struct snd_soc_codec *codec)
{
max98088_set_bias_level(codec, SND_SOC_BIAS_OFF);
return 0;
}
static int max98088_resume(struct snd_soc_codec *codec)
{
max98088_set_bias_level(codec, SND_SOC_BIAS_STANDBY);
return 0;
}
static int max98088_probe(struct snd_soc_codec *codec)
{
struct max98088_priv *max98088 = snd_soc_codec_get_drvdata(codec);
struct max98088_cdata *cdata;
int ret = 0;
codec->cache_sync = 1;
ret = snd_soc_codec_set_cache_io(codec, 8, 8, SND_SOC_I2C);
if (ret != 0) {
dev_err(codec->dev, "Failed to set cache I/O: %d\n", ret);
return ret;
}
max98088->sysclk = (unsigned)-1;
max98088->eq_textcnt = 0;
cdata = &max98088->dai[0];
cdata->rate = (unsigned)-1;
cdata->fmt = (unsigned)-1;
cdata->eq_sel = 0;
cdata = &max98088->dai[1];
cdata->rate = (unsigned)-1;
cdata->fmt = (unsigned)-1;
cdata->eq_sel = 0;
max98088->ina_state = 0;
max98088->inb_state = 0;
max98088->ex_mode = 0;
max98088->digmic = 0;
max98088->mic1pre = 0;
max98088->mic2pre = 0;
ret = snd_soc_read(codec, M98088_REG_FF_REV_ID);
if (ret < 0) {
dev_err(codec->dev, "Failed to read device revision: %d\n",
ret);
goto err_access;
}
dev_info(codec->dev, "revision %c\n", ret + 'A');
snd_soc_write(codec, M98088_REG_51_PWR_SYS, M98088_PWRSV);
max98088_set_bias_level(codec, SND_SOC_BIAS_STANDBY);
snd_soc_write(codec, M98088_REG_0F_IRQ_ENABLE, 0x00);
snd_soc_write(codec, M98088_REG_22_MIX_DAC,
M98088_DAI1L_TO_DACL|M98088_DAI2L_TO_DACL|
M98088_DAI1R_TO_DACR|M98088_DAI2R_TO_DACR);
snd_soc_write(codec, M98088_REG_4E_BIAS_CNTL, 0xF0);
snd_soc_write(codec, M98088_REG_50_DAC_BIAS2, 0x0F);
snd_soc_write(codec, M98088_REG_16_DAI1_IOCFG,
M98088_S1NORMAL|M98088_SDATA);
snd_soc_write(codec, M98088_REG_1E_DAI2_IOCFG,
M98088_S2NORMAL|M98088_SDATA);
max98088_handle_pdata(codec);
snd_soc_add_codec_controls(codec, max98088_snd_controls,
ARRAY_SIZE(max98088_snd_controls));
err_access:
return ret;
}
static int max98088_remove(struct snd_soc_codec *codec)
{
struct max98088_priv *max98088 = snd_soc_codec_get_drvdata(codec);
max98088_set_bias_level(codec, SND_SOC_BIAS_OFF);
kfree(max98088->eq_texts);
return 0;
}
static int max98088_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct max98088_priv *max98088;
int ret;
max98088 = devm_kzalloc(&i2c->dev, sizeof(struct max98088_priv),
GFP_KERNEL);
if (max98088 == NULL)
return -ENOMEM;
max98088->devtype = id->driver_data;
i2c_set_clientdata(i2c, max98088);
max98088->pdata = i2c->dev.platform_data;
ret = snd_soc_register_codec(&i2c->dev,
&soc_codec_dev_max98088, &max98088_dai[0], 2);
return ret;
}
static int __devexit max98088_i2c_remove(struct i2c_client *client)
{
snd_soc_unregister_codec(&client->dev);
return 0;
}
