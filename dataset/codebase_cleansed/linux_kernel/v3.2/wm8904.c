static int wm8904_volatile_register(struct snd_soc_codec *codec, unsigned int reg)
{
return wm8904_access[reg].vol;
}
static int wm8904_reset(struct snd_soc_codec *codec)
{
return snd_soc_write(codec, WM8904_SW_RESET_AND_ID, 0);
}
static int wm8904_configure_clocking(struct snd_soc_codec *codec)
{
struct wm8904_priv *wm8904 = snd_soc_codec_get_drvdata(codec);
unsigned int clock0, clock2, rate;
clock2 = snd_soc_read(codec, WM8904_CLOCK_RATES_2);
snd_soc_update_bits(codec, WM8904_CLOCK_RATES_2,
WM8904_SYSCLK_SRC, 0);
switch (wm8904->sysclk_src) {
case WM8904_CLK_MCLK:
dev_dbg(codec->dev, "Using %dHz MCLK\n", wm8904->mclk_rate);
clock2 &= ~WM8904_SYSCLK_SRC;
rate = wm8904->mclk_rate;
snd_soc_update_bits(codec, WM8904_FLL_CONTROL_1,
WM8904_FLL_OSC_ENA | WM8904_FLL_ENA, 0);
break;
case WM8904_CLK_FLL:
dev_dbg(codec->dev, "Using %dHz FLL clock\n",
wm8904->fll_fout);
clock2 |= WM8904_SYSCLK_SRC;
rate = wm8904->fll_fout;
break;
default:
dev_err(codec->dev, "System clock not configured\n");
return -EINVAL;
}
if (rate > 13500000) {
clock0 = WM8904_MCLK_DIV;
wm8904->sysclk_rate = rate / 2;
} else {
clock0 = 0;
wm8904->sysclk_rate = rate;
}
snd_soc_update_bits(codec, WM8904_CLOCK_RATES_0, WM8904_MCLK_DIV,
clock0);
snd_soc_update_bits(codec, WM8904_CLOCK_RATES_2,
WM8904_CLK_SYS_ENA | WM8904_SYSCLK_SRC, clock2);
dev_dbg(codec->dev, "CLK_SYS is %dHz\n", wm8904->sysclk_rate);
return 0;
}
static void wm8904_set_drc(struct snd_soc_codec *codec)
{
struct wm8904_priv *wm8904 = snd_soc_codec_get_drvdata(codec);
struct wm8904_pdata *pdata = wm8904->pdata;
int save, i;
save = snd_soc_read(codec, WM8904_DRC_0);
for (i = 0; i < WM8904_DRC_REGS; i++)
snd_soc_update_bits(codec, WM8904_DRC_0 + i, 0xffff,
pdata->drc_cfgs[wm8904->drc_cfg].regs[i]);
snd_soc_update_bits(codec, WM8904_DRC_0,
WM8904_DRC_ENA | WM8904_DRC_DAC_PATH, save);
}
static int wm8904_put_drc_enum(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_kcontrol_chip(kcontrol);
struct wm8904_priv *wm8904 = snd_soc_codec_get_drvdata(codec);
struct wm8904_pdata *pdata = wm8904->pdata;
int value = ucontrol->value.integer.value[0];
if (value >= pdata->num_drc_cfgs)
return -EINVAL;
wm8904->drc_cfg = value;
wm8904_set_drc(codec);
return 0;
}
static int wm8904_get_drc_enum(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_kcontrol_chip(kcontrol);
struct wm8904_priv *wm8904 = snd_soc_codec_get_drvdata(codec);
ucontrol->value.enumerated.item[0] = wm8904->drc_cfg;
return 0;
}
static void wm8904_set_retune_mobile(struct snd_soc_codec *codec)
{
struct wm8904_priv *wm8904 = snd_soc_codec_get_drvdata(codec);
struct wm8904_pdata *pdata = wm8904->pdata;
int best, best_val, save, i, cfg;
if (!pdata || !wm8904->num_retune_mobile_texts)
return;
cfg = wm8904->retune_mobile_cfg;
best = 0;
best_val = INT_MAX;
for (i = 0; i < pdata->num_retune_mobile_cfgs; i++) {
if (strcmp(pdata->retune_mobile_cfgs[i].name,
wm8904->retune_mobile_texts[cfg]) == 0 &&
abs(pdata->retune_mobile_cfgs[i].rate
- wm8904->fs) < best_val) {
best = i;
best_val = abs(pdata->retune_mobile_cfgs[i].rate
- wm8904->fs);
}
}
dev_dbg(codec->dev, "ReTune Mobile %s/%dHz for %dHz sample rate\n",
pdata->retune_mobile_cfgs[best].name,
pdata->retune_mobile_cfgs[best].rate,
wm8904->fs);
save = snd_soc_read(codec, WM8904_EQ1);
for (i = 0; i < WM8904_EQ_REGS; i++)
snd_soc_update_bits(codec, WM8904_EQ1 + i, 0xffff,
pdata->retune_mobile_cfgs[best].regs[i]);
snd_soc_update_bits(codec, WM8904_EQ1, WM8904_EQ_ENA, save);
}
static int wm8904_put_retune_mobile_enum(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_kcontrol_chip(kcontrol);
struct wm8904_priv *wm8904 = snd_soc_codec_get_drvdata(codec);
struct wm8904_pdata *pdata = wm8904->pdata;
int value = ucontrol->value.integer.value[0];
if (value >= pdata->num_retune_mobile_cfgs)
return -EINVAL;
wm8904->retune_mobile_cfg = value;
wm8904_set_retune_mobile(codec);
return 0;
}
static int wm8904_get_retune_mobile_enum(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_kcontrol_chip(kcontrol);
struct wm8904_priv *wm8904 = snd_soc_codec_get_drvdata(codec);
ucontrol->value.enumerated.item[0] = wm8904->retune_mobile_cfg;
return 0;
}
static int wm8904_set_deemph(struct snd_soc_codec *codec)
{
struct wm8904_priv *wm8904 = snd_soc_codec_get_drvdata(codec);
int val, i, best;
if (wm8904->deemph) {
best = 1;
for (i = 2; i < ARRAY_SIZE(deemph_settings); i++) {
if (abs(deemph_settings[i] - wm8904->fs) <
abs(deemph_settings[best] - wm8904->fs))
best = i;
}
val = best << WM8904_DEEMPH_SHIFT;
} else {
val = 0;
}
dev_dbg(codec->dev, "Set deemphasis %d\n", val);
return snd_soc_update_bits(codec, WM8904_DAC_DIGITAL_1,
WM8904_DEEMPH_MASK, val);
}
static int wm8904_get_deemph(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_kcontrol_chip(kcontrol);
struct wm8904_priv *wm8904 = snd_soc_codec_get_drvdata(codec);
ucontrol->value.enumerated.item[0] = wm8904->deemph;
return 0;
}
static int wm8904_put_deemph(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_kcontrol_chip(kcontrol);
struct wm8904_priv *wm8904 = snd_soc_codec_get_drvdata(codec);
int deemph = ucontrol->value.enumerated.item[0];
if (deemph > 1)
return -EINVAL;
wm8904->deemph = deemph;
return wm8904_set_deemph(codec);
}
static int cp_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
BUG_ON(event != SND_SOC_DAPM_POST_PMU);
udelay(500);
return 0;
}
static int sysclk_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = w->codec;
struct wm8904_priv *wm8904 = snd_soc_codec_get_drvdata(codec);
switch (event) {
case SND_SOC_DAPM_PRE_PMU:
switch (wm8904->sysclk_src) {
case WM8904_CLK_FLL:
snd_soc_update_bits(codec, WM8904_FLL_CONTROL_1,
WM8904_FLL_OSC_ENA,
WM8904_FLL_OSC_ENA);
snd_soc_update_bits(codec, WM8904_FLL_CONTROL_1,
WM8904_FLL_ENA,
WM8904_FLL_ENA);
break;
default:
break;
}
break;
case SND_SOC_DAPM_POST_PMD:
snd_soc_update_bits(codec, WM8904_FLL_CONTROL_1,
WM8904_FLL_OSC_ENA | WM8904_FLL_ENA, 0);
break;
}
return 0;
}
static int out_pga_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = w->codec;
struct wm8904_priv *wm8904 = snd_soc_codec_get_drvdata(codec);
int reg, val;
int dcs_mask;
int dcs_l, dcs_r;
int dcs_l_reg, dcs_r_reg;
int timeout;
int pwr_reg;
reg = w->shift;
switch (reg) {
case WM8904_ANALOGUE_HP_0:
pwr_reg = WM8904_POWER_MANAGEMENT_2;
dcs_mask = WM8904_DCS_ENA_CHAN_0 | WM8904_DCS_ENA_CHAN_1;
dcs_r_reg = WM8904_DC_SERVO_8;
dcs_l_reg = WM8904_DC_SERVO_9;
dcs_l = 0;
dcs_r = 1;
break;
case WM8904_ANALOGUE_LINEOUT_0:
pwr_reg = WM8904_POWER_MANAGEMENT_3;
dcs_mask = WM8904_DCS_ENA_CHAN_2 | WM8904_DCS_ENA_CHAN_3;
dcs_r_reg = WM8904_DC_SERVO_6;
dcs_l_reg = WM8904_DC_SERVO_7;
dcs_l = 2;
dcs_r = 3;
break;
default:
BUG();
return -EINVAL;
}
switch (event) {
case SND_SOC_DAPM_PRE_PMU:
snd_soc_update_bits(codec, pwr_reg,
WM8904_HPL_PGA_ENA | WM8904_HPR_PGA_ENA,
WM8904_HPL_PGA_ENA | WM8904_HPR_PGA_ENA);
snd_soc_update_bits(codec, reg,
WM8904_HPL_ENA | WM8904_HPR_ENA,
WM8904_HPL_ENA | WM8904_HPR_ENA);
snd_soc_update_bits(codec, reg,
WM8904_HPL_ENA_DLY | WM8904_HPR_ENA_DLY,
WM8904_HPL_ENA_DLY | WM8904_HPR_ENA_DLY);
snd_soc_update_bits(codec, WM8904_DC_SERVO_0,
dcs_mask, dcs_mask);
if (wm8904->dcs_state[dcs_l] || wm8904->dcs_state[dcs_r]) {
dev_dbg(codec->dev, "Restoring DC servo state\n");
snd_soc_write(codec, dcs_l_reg,
wm8904->dcs_state[dcs_l]);
snd_soc_write(codec, dcs_r_reg,
wm8904->dcs_state[dcs_r]);
snd_soc_write(codec, WM8904_DC_SERVO_1, dcs_mask);
timeout = 20;
} else {
dev_dbg(codec->dev, "Calibrating DC servo\n");
snd_soc_write(codec, WM8904_DC_SERVO_1,
dcs_mask << WM8904_DCS_TRIG_STARTUP_0_SHIFT);
timeout = 500;
}
dcs_mask <<= WM8904_DCS_CAL_COMPLETE_SHIFT;
do {
val = snd_soc_read(codec, WM8904_DC_SERVO_READBACK_0);
if ((val & dcs_mask) == dcs_mask)
break;
msleep(1);
} while (--timeout);
if ((val & dcs_mask) != dcs_mask)
dev_warn(codec->dev, "DC servo timed out\n");
else
dev_dbg(codec->dev, "DC servo ready\n");
snd_soc_update_bits(codec, reg,
WM8904_HPL_ENA_OUTP | WM8904_HPR_ENA_OUTP,
WM8904_HPL_ENA_OUTP | WM8904_HPR_ENA_OUTP);
break;
case SND_SOC_DAPM_POST_PMU:
snd_soc_update_bits(codec, reg,
WM8904_HPL_RMV_SHORT |
WM8904_HPR_RMV_SHORT,
WM8904_HPL_RMV_SHORT |
WM8904_HPR_RMV_SHORT);
break;
case SND_SOC_DAPM_PRE_PMD:
snd_soc_update_bits(codec, reg,
WM8904_HPL_RMV_SHORT |
WM8904_HPR_RMV_SHORT, 0);
break;
case SND_SOC_DAPM_POST_PMD:
wm8904->dcs_state[dcs_l] = snd_soc_read(codec, dcs_l_reg);
wm8904->dcs_state[dcs_r] = snd_soc_read(codec, dcs_r_reg);
snd_soc_update_bits(codec, WM8904_DC_SERVO_0,
dcs_mask, 0);
snd_soc_update_bits(codec, reg,
WM8904_HPL_ENA | WM8904_HPR_ENA |
WM8904_HPL_ENA_DLY | WM8904_HPR_ENA_DLY |
WM8904_HPL_ENA_OUTP | WM8904_HPR_ENA_OUTP,
0);
snd_soc_update_bits(codec, pwr_reg,
WM8904_HPL_PGA_ENA | WM8904_HPR_PGA_ENA,
0);
break;
}
return 0;
}
static int wm8904_add_widgets(struct snd_soc_codec *codec)
{
struct wm8904_priv *wm8904 = snd_soc_codec_get_drvdata(codec);
struct snd_soc_dapm_context *dapm = &codec->dapm;
snd_soc_dapm_new_controls(dapm, wm8904_core_dapm_widgets,
ARRAY_SIZE(wm8904_core_dapm_widgets));
snd_soc_dapm_add_routes(dapm, core_intercon,
ARRAY_SIZE(core_intercon));
switch (wm8904->devtype) {
case WM8904:
snd_soc_add_controls(codec, wm8904_adc_snd_controls,
ARRAY_SIZE(wm8904_adc_snd_controls));
snd_soc_add_controls(codec, wm8904_dac_snd_controls,
ARRAY_SIZE(wm8904_dac_snd_controls));
snd_soc_add_controls(codec, wm8904_snd_controls,
ARRAY_SIZE(wm8904_snd_controls));
snd_soc_dapm_new_controls(dapm, wm8904_adc_dapm_widgets,
ARRAY_SIZE(wm8904_adc_dapm_widgets));
snd_soc_dapm_new_controls(dapm, wm8904_dac_dapm_widgets,
ARRAY_SIZE(wm8904_dac_dapm_widgets));
snd_soc_dapm_new_controls(dapm, wm8904_dapm_widgets,
ARRAY_SIZE(wm8904_dapm_widgets));
snd_soc_dapm_add_routes(dapm, core_intercon,
ARRAY_SIZE(core_intercon));
snd_soc_dapm_add_routes(dapm, adc_intercon,
ARRAY_SIZE(adc_intercon));
snd_soc_dapm_add_routes(dapm, dac_intercon,
ARRAY_SIZE(dac_intercon));
snd_soc_dapm_add_routes(dapm, wm8904_intercon,
ARRAY_SIZE(wm8904_intercon));
break;
case WM8912:
snd_soc_add_controls(codec, wm8904_dac_snd_controls,
ARRAY_SIZE(wm8904_dac_snd_controls));
snd_soc_dapm_new_controls(dapm, wm8904_dac_dapm_widgets,
ARRAY_SIZE(wm8904_dac_dapm_widgets));
snd_soc_dapm_add_routes(dapm, dac_intercon,
ARRAY_SIZE(dac_intercon));
snd_soc_dapm_add_routes(dapm, wm8912_intercon,
ARRAY_SIZE(wm8912_intercon));
break;
}
snd_soc_dapm_new_widgets(dapm);
return 0;
}
static int wm8904_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct wm8904_priv *wm8904 = snd_soc_codec_get_drvdata(codec);
int ret, i, best, best_val, cur_val;
unsigned int aif1 = 0;
unsigned int aif2 = 0;
unsigned int aif3 = 0;
unsigned int clock1 = 0;
unsigned int dac_digital1 = 0;
wm8904->fs = params_rate(params);
if (wm8904->tdm_slots) {
dev_dbg(codec->dev, "Configuring for %d %d bit TDM slots\n",
wm8904->tdm_slots, wm8904->tdm_width);
wm8904->bclk = snd_soc_calc_bclk(wm8904->fs,
wm8904->tdm_width, 2,
wm8904->tdm_slots);
} else {
wm8904->bclk = snd_soc_params_to_bclk(params);
}
switch (params_format(params)) {
case SNDRV_PCM_FORMAT_S16_LE:
break;
case SNDRV_PCM_FORMAT_S20_3LE:
aif1 |= 0x40;
break;
case SNDRV_PCM_FORMAT_S24_LE:
aif1 |= 0x80;
break;
case SNDRV_PCM_FORMAT_S32_LE:
aif1 |= 0xc0;
break;
default:
return -EINVAL;
}
dev_dbg(codec->dev, "Target BCLK is %dHz\n", wm8904->bclk);
ret = wm8904_configure_clocking(codec);
if (ret != 0)
return ret;
best = 0;
best_val = abs((wm8904->sysclk_rate / clk_sys_rates[0].ratio)
- wm8904->fs);
for (i = 1; i < ARRAY_SIZE(clk_sys_rates); i++) {
cur_val = abs((wm8904->sysclk_rate /
clk_sys_rates[i].ratio) - wm8904->fs);
if (cur_val < best_val) {
best = i;
best_val = cur_val;
}
}
dev_dbg(codec->dev, "Selected CLK_SYS_RATIO of %d\n",
clk_sys_rates[best].ratio);
clock1 |= (clk_sys_rates[best].clk_sys_rate
<< WM8904_CLK_SYS_RATE_SHIFT);
best = 0;
best_val = abs(wm8904->fs - sample_rates[0].rate);
for (i = 1; i < ARRAY_SIZE(sample_rates); i++) {
cur_val = abs(wm8904->fs - sample_rates[i].rate);
if (cur_val < best_val) {
best = i;
best_val = cur_val;
}
}
dev_dbg(codec->dev, "Selected SAMPLE_RATE of %dHz\n",
sample_rates[best].rate);
clock1 |= (sample_rates[best].sample_rate
<< WM8904_SAMPLE_RATE_SHIFT);
if (wm8904->fs <= 24000)
dac_digital1 |= WM8904_DAC_SB_FILT;
best = 0;
best_val = INT_MAX;
for (i = 0; i < ARRAY_SIZE(bclk_divs); i++) {
cur_val = ((wm8904->sysclk_rate * 10) / bclk_divs[i].div)
- wm8904->bclk;
if (cur_val < 0)
break;
if (cur_val < best_val) {
best = i;
best_val = cur_val;
}
}
wm8904->bclk = (wm8904->sysclk_rate * 10) / bclk_divs[best].div;
dev_dbg(codec->dev, "Selected BCLK_DIV of %d for %dHz BCLK\n",
bclk_divs[best].div, wm8904->bclk);
aif2 |= bclk_divs[best].bclk_div;
dev_dbg(codec->dev, "LRCLK_RATE is %d\n", wm8904->bclk / wm8904->fs);
aif3 |= wm8904->bclk / wm8904->fs;
snd_soc_update_bits(codec, WM8904_DAC_DIGITAL_1,
WM8904_DAC_SB_FILT, dac_digital1);
snd_soc_update_bits(codec, WM8904_AUDIO_INTERFACE_1,
WM8904_AIF_WL_MASK, aif1);
snd_soc_update_bits(codec, WM8904_AUDIO_INTERFACE_2,
WM8904_BCLK_DIV_MASK, aif2);
snd_soc_update_bits(codec, WM8904_AUDIO_INTERFACE_3,
WM8904_LRCLK_RATE_MASK, aif3);
snd_soc_update_bits(codec, WM8904_CLOCK_RATES_1,
WM8904_SAMPLE_RATE_MASK |
WM8904_CLK_SYS_RATE_MASK, clock1);
wm8904_set_retune_mobile(codec);
wm8904_set_deemph(codec);
return 0;
}
static int wm8904_set_sysclk(struct snd_soc_dai *dai, int clk_id,
unsigned int freq, int dir)
{
struct snd_soc_codec *codec = dai->codec;
struct wm8904_priv *priv = snd_soc_codec_get_drvdata(codec);
switch (clk_id) {
case WM8904_CLK_MCLK:
priv->sysclk_src = clk_id;
priv->mclk_rate = freq;
break;
case WM8904_CLK_FLL:
priv->sysclk_src = clk_id;
break;
default:
return -EINVAL;
}
dev_dbg(dai->dev, "Clock source is %d at %uHz\n", clk_id, freq);
wm8904_configure_clocking(codec);
return 0;
}
static int wm8904_set_fmt(struct snd_soc_dai *dai, unsigned int fmt)
{
struct snd_soc_codec *codec = dai->codec;
unsigned int aif1 = 0;
unsigned int aif3 = 0;
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBS_CFS:
break;
case SND_SOC_DAIFMT_CBS_CFM:
aif3 |= WM8904_LRCLK_DIR;
break;
case SND_SOC_DAIFMT_CBM_CFS:
aif1 |= WM8904_BCLK_DIR;
break;
case SND_SOC_DAIFMT_CBM_CFM:
aif1 |= WM8904_BCLK_DIR;
aif3 |= WM8904_LRCLK_DIR;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_DSP_B:
aif1 |= WM8904_AIF_LRCLK_INV;
case SND_SOC_DAIFMT_DSP_A:
aif1 |= 0x3;
break;
case SND_SOC_DAIFMT_I2S:
aif1 |= 0x2;
break;
case SND_SOC_DAIFMT_RIGHT_J:
break;
case SND_SOC_DAIFMT_LEFT_J:
aif1 |= 0x1;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_DSP_A:
case SND_SOC_DAIFMT_DSP_B:
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
break;
case SND_SOC_DAIFMT_IB_NF:
aif1 |= WM8904_AIF_BCLK_INV;
break;
default:
return -EINVAL;
}
break;
case SND_SOC_DAIFMT_I2S:
case SND_SOC_DAIFMT_RIGHT_J:
case SND_SOC_DAIFMT_LEFT_J:
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
break;
case SND_SOC_DAIFMT_IB_IF:
aif1 |= WM8904_AIF_BCLK_INV | WM8904_AIF_LRCLK_INV;
break;
case SND_SOC_DAIFMT_IB_NF:
aif1 |= WM8904_AIF_BCLK_INV;
break;
case SND_SOC_DAIFMT_NB_IF:
aif1 |= WM8904_AIF_LRCLK_INV;
break;
default:
return -EINVAL;
}
break;
default:
return -EINVAL;
}
snd_soc_update_bits(codec, WM8904_AUDIO_INTERFACE_1,
WM8904_AIF_BCLK_INV | WM8904_AIF_LRCLK_INV |
WM8904_AIF_FMT_MASK | WM8904_BCLK_DIR, aif1);
snd_soc_update_bits(codec, WM8904_AUDIO_INTERFACE_3,
WM8904_LRCLK_DIR, aif3);
return 0;
}
static int wm8904_set_tdm_slot(struct snd_soc_dai *dai, unsigned int tx_mask,
unsigned int rx_mask, int slots, int slot_width)
{
struct snd_soc_codec *codec = dai->codec;
struct wm8904_priv *wm8904 = snd_soc_codec_get_drvdata(codec);
int aif1 = 0;
if (slots == 0)
goto out;
aif1 |= WM8904_AIFADC_TDM | WM8904_AIFDAC_TDM;
switch (rx_mask) {
case 3:
break;
case 0xc:
aif1 |= WM8904_AIFADC_TDM_CHAN;
break;
default:
return -EINVAL;
}
switch (tx_mask) {
case 3:
break;
case 0xc:
aif1 |= WM8904_AIFDAC_TDM_CHAN;
break;
default:
return -EINVAL;
}
out:
wm8904->tdm_width = slot_width;
wm8904->tdm_slots = slots / 2;
snd_soc_update_bits(codec, WM8904_AUDIO_INTERFACE_1,
WM8904_AIFADC_TDM | WM8904_AIFADC_TDM_CHAN |
WM8904_AIFDAC_TDM | WM8904_AIFDAC_TDM_CHAN, aif1);
return 0;
}
static int fll_factors(struct _fll_div *fll_div, unsigned int Fref,
unsigned int Fout)
{
u64 Kpart;
unsigned int K, Ndiv, Nmod, target;
unsigned int div;
int i;
div = 1;
fll_div->fll_clk_ref_div = 0;
while ((Fref / div) > 13500000) {
div *= 2;
fll_div->fll_clk_ref_div++;
if (div > 8) {
pr_err("Can't scale %dMHz input down to <=13.5MHz\n",
Fref);
return -EINVAL;
}
}
pr_debug("Fref=%u Fout=%u\n", Fref, Fout);
Fref /= div;
div = 4;
while (Fout * div < 90000000) {
div++;
if (div > 64) {
pr_err("Unable to find FLL_OUTDIV for Fout=%uHz\n",
Fout);
return -EINVAL;
}
}
target = Fout * div;
fll_div->fll_outdiv = div - 1;
pr_debug("Fvco=%dHz\n", target);
for (i = 0; i < ARRAY_SIZE(fll_fratios); i++) {
if (fll_fratios[i].min <= Fref && Fref <= fll_fratios[i].max) {
fll_div->fll_fratio = fll_fratios[i].fll_fratio;
target /= fll_fratios[i].ratio;
break;
}
}
if (i == ARRAY_SIZE(fll_fratios)) {
pr_err("Unable to find FLL_FRATIO for Fref=%uHz\n", Fref);
return -EINVAL;
}
Ndiv = target / Fref;
fll_div->n = Ndiv;
Nmod = target % Fref;
pr_debug("Nmod=%d\n", Nmod);
Kpart = FIXED_FLL_SIZE * (long long)Nmod;
do_div(Kpart, Fref);
K = Kpart & 0xFFFFFFFF;
if ((K % 10) >= 5)
K += 5;
fll_div->k = K / 10;
pr_debug("N=%x K=%x FLL_FRATIO=%x FLL_OUTDIV=%x FLL_CLK_REF_DIV=%x\n",
fll_div->n, fll_div->k,
fll_div->fll_fratio, fll_div->fll_outdiv,
fll_div->fll_clk_ref_div);
return 0;
}
static int wm8904_set_fll(struct snd_soc_dai *dai, int fll_id, int source,
unsigned int Fref, unsigned int Fout)
{
struct snd_soc_codec *codec = dai->codec;
struct wm8904_priv *wm8904 = snd_soc_codec_get_drvdata(codec);
struct _fll_div fll_div;
int ret, val;
int clock2, fll1;
if (source == wm8904->fll_src && Fref == wm8904->fll_fref &&
Fout == wm8904->fll_fout)
return 0;
clock2 = snd_soc_read(codec, WM8904_CLOCK_RATES_2);
if (Fout == 0) {
dev_dbg(codec->dev, "FLL disabled\n");
wm8904->fll_fref = 0;
wm8904->fll_fout = 0;
snd_soc_update_bits(codec, WM8904_CLOCK_RATES_2,
WM8904_CLK_SYS_ENA, 0);
snd_soc_update_bits(codec, WM8904_FLL_CONTROL_1,
WM8904_FLL_OSC_ENA | WM8904_FLL_ENA, 0);
goto out;
}
switch (source) {
case WM8904_FLL_MCLK:
case WM8904_FLL_LRCLK:
case WM8904_FLL_BCLK:
ret = fll_factors(&fll_div, Fref, Fout);
if (ret != 0)
return ret;
break;
case WM8904_FLL_FREE_RUNNING:
dev_dbg(codec->dev, "Using free running FLL\n");
Fout = 12000000;
Fref = 12000000;
memset(&fll_div, 0, sizeof(fll_div));
fll_div.fll_outdiv = 3;
break;
default:
dev_err(codec->dev, "Unknown FLL ID %d\n", fll_id);
return -EINVAL;
}
fll1 = snd_soc_read(codec, WM8904_FLL_CONTROL_1);
snd_soc_update_bits(codec, WM8904_CLOCK_RATES_2,
WM8904_CLK_SYS_ENA, 0);
snd_soc_update_bits(codec, WM8904_FLL_CONTROL_1,
WM8904_FLL_OSC_ENA | WM8904_FLL_ENA, 0);
snd_soc_update_bits(codec, WM8904_CONTROL_INTERFACE_TEST_1,
WM8904_USER_KEY, WM8904_USER_KEY);
if (fll_id == WM8904_FLL_FREE_RUNNING) {
val = WM8904_FLL_FRC_NCO;
} else {
val = 0;
}
snd_soc_update_bits(codec, WM8904_FLL_NCO_TEST_1, WM8904_FLL_FRC_NCO,
val);
snd_soc_update_bits(codec, WM8904_CONTROL_INTERFACE_TEST_1,
WM8904_USER_KEY, 0);
switch (fll_id) {
case WM8904_FLL_MCLK:
snd_soc_update_bits(codec, WM8904_FLL_CONTROL_5,
WM8904_FLL_CLK_REF_SRC_MASK, 0);
break;
case WM8904_FLL_LRCLK:
snd_soc_update_bits(codec, WM8904_FLL_CONTROL_5,
WM8904_FLL_CLK_REF_SRC_MASK, 1);
break;
case WM8904_FLL_BCLK:
snd_soc_update_bits(codec, WM8904_FLL_CONTROL_5,
WM8904_FLL_CLK_REF_SRC_MASK, 2);
break;
}
if (fll_div.k)
val = WM8904_FLL_FRACN_ENA;
else
val = 0;
snd_soc_update_bits(codec, WM8904_FLL_CONTROL_1,
WM8904_FLL_FRACN_ENA, val);
snd_soc_update_bits(codec, WM8904_FLL_CONTROL_2,
WM8904_FLL_OUTDIV_MASK | WM8904_FLL_FRATIO_MASK,
(fll_div.fll_outdiv << WM8904_FLL_OUTDIV_SHIFT) |
(fll_div.fll_fratio << WM8904_FLL_FRATIO_SHIFT));
snd_soc_write(codec, WM8904_FLL_CONTROL_3, fll_div.k);
snd_soc_update_bits(codec, WM8904_FLL_CONTROL_4, WM8904_FLL_N_MASK,
fll_div.n << WM8904_FLL_N_SHIFT);
snd_soc_update_bits(codec, WM8904_FLL_CONTROL_5,
WM8904_FLL_CLK_REF_DIV_MASK,
fll_div.fll_clk_ref_div
<< WM8904_FLL_CLK_REF_DIV_SHIFT);
dev_dbg(codec->dev, "FLL configured for %dHz->%dHz\n", Fref, Fout);
wm8904->fll_fref = Fref;
wm8904->fll_fout = Fout;
wm8904->fll_src = source;
snd_soc_update_bits(codec, WM8904_FLL_CONTROL_1,
WM8904_FLL_OSC_ENA, fll1);
snd_soc_update_bits(codec, WM8904_FLL_CONTROL_1,
WM8904_FLL_ENA, fll1);
out:
snd_soc_update_bits(codec, WM8904_CLOCK_RATES_2,
WM8904_CLK_SYS_ENA, clock2);
return 0;
}
static int wm8904_digital_mute(struct snd_soc_dai *codec_dai, int mute)
{
struct snd_soc_codec *codec = codec_dai->codec;
int val;
if (mute)
val = WM8904_DAC_MUTE;
else
val = 0;
snd_soc_update_bits(codec, WM8904_DAC_DIGITAL_1, WM8904_DAC_MUTE, val);
return 0;
}
static void wm8904_sync_cache(struct snd_soc_codec *codec)
{
u16 *reg_cache = codec->reg_cache;
int i;
if (!codec->cache_sync)
return;
codec->cache_only = 0;
for (i = 1; i < codec->driver->reg_cache_size; i++) {
if (!wm8904_access[i].writable)
continue;
if (reg_cache[i] == wm8904_reg[i])
continue;
snd_soc_write(codec, i, reg_cache[i]);
}
codec->cache_sync = 0;
}
static int wm8904_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
struct wm8904_priv *wm8904 = snd_soc_codec_get_drvdata(codec);
int ret;
switch (level) {
case SND_SOC_BIAS_ON:
break;
case SND_SOC_BIAS_PREPARE:
snd_soc_update_bits(codec, WM8904_VMID_CONTROL_0,
WM8904_VMID_RES_MASK,
0x1 << WM8904_VMID_RES_SHIFT);
snd_soc_update_bits(codec, WM8904_BIAS_CONTROL_0,
WM8904_ISEL_MASK, 2 << WM8904_ISEL_SHIFT);
break;
case SND_SOC_BIAS_STANDBY:
if (codec->dapm.bias_level == SND_SOC_BIAS_OFF) {
ret = regulator_bulk_enable(ARRAY_SIZE(wm8904->supplies),
wm8904->supplies);
if (ret != 0) {
dev_err(codec->dev,
"Failed to enable supplies: %d\n",
ret);
return ret;
}
wm8904_sync_cache(codec);
snd_soc_update_bits(codec, WM8904_BIAS_CONTROL_0,
WM8904_BIAS_ENA, WM8904_BIAS_ENA);
snd_soc_update_bits(codec, WM8904_VMID_CONTROL_0,
WM8904_VMID_ENA |
WM8904_VMID_RES_MASK,
WM8904_VMID_ENA |
0x3 << WM8904_VMID_RES_SHIFT);
msleep(1);
}
snd_soc_update_bits(codec, WM8904_VMID_CONTROL_0,
WM8904_VMID_RES_MASK,
0x2 << WM8904_VMID_RES_SHIFT);
snd_soc_update_bits(codec, WM8904_BIAS_CONTROL_0,
WM8904_ISEL_MASK, 0);
break;
case SND_SOC_BIAS_OFF:
snd_soc_update_bits(codec, WM8904_VMID_CONTROL_0,
WM8904_VMID_RES_MASK | WM8904_VMID_ENA, 0);
snd_soc_update_bits(codec, WM8904_BIAS_CONTROL_0,
WM8904_BIAS_ENA, 0);
#ifdef CONFIG_REGULATOR
codec->cache_sync = 1;
#endif
regulator_bulk_disable(ARRAY_SIZE(wm8904->supplies),
wm8904->supplies);
break;
}
codec->dapm.bias_level = level;
return 0;
}
static int wm8904_suspend(struct snd_soc_codec *codec, pm_message_t state)
{
wm8904_set_bias_level(codec, SND_SOC_BIAS_OFF);
return 0;
}
static int wm8904_resume(struct snd_soc_codec *codec)
{
wm8904_set_bias_level(codec, SND_SOC_BIAS_STANDBY);
return 0;
}
static void wm8904_handle_retune_mobile_pdata(struct snd_soc_codec *codec)
{
struct wm8904_priv *wm8904 = snd_soc_codec_get_drvdata(codec);
struct wm8904_pdata *pdata = wm8904->pdata;
struct snd_kcontrol_new control =
SOC_ENUM_EXT("EQ Mode",
wm8904->retune_mobile_enum,
wm8904_get_retune_mobile_enum,
wm8904_put_retune_mobile_enum);
int ret, i, j;
const char **t;
wm8904->num_retune_mobile_texts = 0;
wm8904->retune_mobile_texts = NULL;
for (i = 0; i < pdata->num_retune_mobile_cfgs; i++) {
for (j = 0; j < wm8904->num_retune_mobile_texts; j++) {
if (strcmp(pdata->retune_mobile_cfgs[i].name,
wm8904->retune_mobile_texts[j]) == 0)
break;
}
if (j != wm8904->num_retune_mobile_texts)
continue;
t = krealloc(wm8904->retune_mobile_texts,
sizeof(char *) *
(wm8904->num_retune_mobile_texts + 1),
GFP_KERNEL);
if (t == NULL)
continue;
t[wm8904->num_retune_mobile_texts] =
pdata->retune_mobile_cfgs[i].name;
wm8904->num_retune_mobile_texts++;
wm8904->retune_mobile_texts = t;
}
dev_dbg(codec->dev, "Allocated %d unique ReTune Mobile names\n",
wm8904->num_retune_mobile_texts);
wm8904->retune_mobile_enum.max = wm8904->num_retune_mobile_texts;
wm8904->retune_mobile_enum.texts = wm8904->retune_mobile_texts;
ret = snd_soc_add_controls(codec, &control, 1);
if (ret != 0)
dev_err(codec->dev,
"Failed to add ReTune Mobile control: %d\n", ret);
}
static void wm8904_handle_pdata(struct snd_soc_codec *codec)
{
struct wm8904_priv *wm8904 = snd_soc_codec_get_drvdata(codec);
struct wm8904_pdata *pdata = wm8904->pdata;
int ret, i;
if (!pdata) {
snd_soc_add_controls(codec, wm8904_eq_controls,
ARRAY_SIZE(wm8904_eq_controls));
return;
}
dev_dbg(codec->dev, "%d DRC configurations\n", pdata->num_drc_cfgs);
if (pdata->num_drc_cfgs) {
struct snd_kcontrol_new control =
SOC_ENUM_EXT("DRC Mode", wm8904->drc_enum,
wm8904_get_drc_enum, wm8904_put_drc_enum);
wm8904->drc_texts = kmalloc(sizeof(char *)
* pdata->num_drc_cfgs, GFP_KERNEL);
if (!wm8904->drc_texts) {
dev_err(codec->dev,
"Failed to allocate %d DRC config texts\n",
pdata->num_drc_cfgs);
return;
}
for (i = 0; i < pdata->num_drc_cfgs; i++)
wm8904->drc_texts[i] = pdata->drc_cfgs[i].name;
wm8904->drc_enum.max = pdata->num_drc_cfgs;
wm8904->drc_enum.texts = wm8904->drc_texts;
ret = snd_soc_add_controls(codec, &control, 1);
if (ret != 0)
dev_err(codec->dev,
"Failed to add DRC mode control: %d\n", ret);
wm8904_set_drc(codec);
}
dev_dbg(codec->dev, "%d ReTune Mobile configurations\n",
pdata->num_retune_mobile_cfgs);
if (pdata->num_retune_mobile_cfgs)
wm8904_handle_retune_mobile_pdata(codec);
else
snd_soc_add_controls(codec, wm8904_eq_controls,
ARRAY_SIZE(wm8904_eq_controls));
}
static int wm8904_probe(struct snd_soc_codec *codec)
{
struct wm8904_priv *wm8904 = snd_soc_codec_get_drvdata(codec);
struct wm8904_pdata *pdata = wm8904->pdata;
u16 *reg_cache = codec->reg_cache;
int ret, i;
codec->cache_sync = 1;
codec->dapm.idle_bias_off = 1;
switch (wm8904->devtype) {
case WM8904:
break;
case WM8912:
memset(&wm8904_dai.capture, 0, sizeof(wm8904_dai.capture));
break;
default:
dev_err(codec->dev, "Unknown device type %d\n",
wm8904->devtype);
return -EINVAL;
}
ret = snd_soc_codec_set_cache_io(codec, 8, 16, SND_SOC_I2C);
if (ret != 0) {
dev_err(codec->dev, "Failed to set cache I/O: %d\n", ret);
return ret;
}
for (i = 0; i < ARRAY_SIZE(wm8904->supplies); i++)
wm8904->supplies[i].supply = wm8904_supply_names[i];
ret = regulator_bulk_get(codec->dev, ARRAY_SIZE(wm8904->supplies),
wm8904->supplies);
if (ret != 0) {
dev_err(codec->dev, "Failed to request supplies: %d\n", ret);
return ret;
}
ret = regulator_bulk_enable(ARRAY_SIZE(wm8904->supplies),
wm8904->supplies);
if (ret != 0) {
dev_err(codec->dev, "Failed to enable supplies: %d\n", ret);
goto err_get;
}
ret = snd_soc_read(codec, WM8904_SW_RESET_AND_ID);
if (ret < 0) {
dev_err(codec->dev, "Failed to read ID register\n");
goto err_enable;
}
if (ret != wm8904_reg[WM8904_SW_RESET_AND_ID]) {
dev_err(codec->dev, "Device is not a WM8904, ID is %x\n", ret);
ret = -EINVAL;
goto err_enable;
}
ret = snd_soc_read(codec, WM8904_REVISION);
if (ret < 0) {
dev_err(codec->dev, "Failed to read device revision: %d\n",
ret);
goto err_enable;
}
dev_info(codec->dev, "revision %c\n", ret + 'A');
ret = wm8904_reset(codec);
if (ret < 0) {
dev_err(codec->dev, "Failed to issue reset\n");
goto err_enable;
}
snd_soc_update_bits(codec, WM8904_ADC_DIGITAL_VOLUME_LEFT,
WM8904_ADC_VU, WM8904_ADC_VU);
snd_soc_update_bits(codec, WM8904_ADC_DIGITAL_VOLUME_RIGHT,
WM8904_ADC_VU, WM8904_ADC_VU);
snd_soc_update_bits(codec, WM8904_DAC_DIGITAL_VOLUME_LEFT,
WM8904_DAC_VU, WM8904_DAC_VU);
snd_soc_update_bits(codec, WM8904_DAC_DIGITAL_VOLUME_RIGHT,
WM8904_DAC_VU, WM8904_DAC_VU);
snd_soc_update_bits(codec, WM8904_ANALOGUE_OUT1_LEFT,
WM8904_HPOUT_VU | WM8904_HPOUTLZC,
WM8904_HPOUT_VU | WM8904_HPOUTLZC);
snd_soc_update_bits(codec, WM8904_ANALOGUE_OUT1_RIGHT,
WM8904_HPOUT_VU | WM8904_HPOUTRZC,
WM8904_HPOUT_VU | WM8904_HPOUTRZC);
snd_soc_update_bits(codec, WM8904_ANALOGUE_OUT2_LEFT,
WM8904_LINEOUT_VU | WM8904_LINEOUTLZC,
WM8904_LINEOUT_VU | WM8904_LINEOUTLZC);
snd_soc_update_bits(codec, WM8904_ANALOGUE_OUT2_RIGHT,
WM8904_LINEOUT_VU | WM8904_LINEOUTRZC,
WM8904_LINEOUT_VU | WM8904_LINEOUTRZC);
snd_soc_update_bits(codec, WM8904_CLOCK_RATES_0,
WM8904_SR_MODE, 0);
if (wm8904->pdata) {
for (i = 0; i < WM8904_GPIO_REGS; i++) {
if (!pdata->gpio_cfg[i])
continue;
reg_cache[WM8904_GPIO_CONTROL_1 + i]
= pdata->gpio_cfg[i] & 0xffff;
}
for (i = 0; i < WM8904_MIC_REGS; i++)
reg_cache[WM8904_MIC_BIAS_CONTROL_0 + i]
= pdata->mic_cfg[i];
}
snd_soc_update_bits(codec, WM8904_CLASS_W_0,
WM8904_CP_DYN_PWR, WM8904_CP_DYN_PWR);
snd_soc_update_bits(codec, WM8904_BIAS_CONTROL_0,
WM8904_POBCTRL, 0);
wm8904_set_bias_level(codec, SND_SOC_BIAS_STANDBY);
regulator_bulk_disable(ARRAY_SIZE(wm8904->supplies), wm8904->supplies);
wm8904_handle_pdata(codec);
wm8904_add_widgets(codec);
return 0;
err_enable:
regulator_bulk_disable(ARRAY_SIZE(wm8904->supplies), wm8904->supplies);
err_get:
regulator_bulk_free(ARRAY_SIZE(wm8904->supplies), wm8904->supplies);
return ret;
}
static int wm8904_remove(struct snd_soc_codec *codec)
{
struct wm8904_priv *wm8904 = snd_soc_codec_get_drvdata(codec);
wm8904_set_bias_level(codec, SND_SOC_BIAS_OFF);
regulator_bulk_free(ARRAY_SIZE(wm8904->supplies), wm8904->supplies);
kfree(wm8904->retune_mobile_texts);
kfree(wm8904->drc_texts);
return 0;
}
static __devinit int wm8904_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct wm8904_priv *wm8904;
int ret;
wm8904 = kzalloc(sizeof(struct wm8904_priv), GFP_KERNEL);
if (wm8904 == NULL)
return -ENOMEM;
wm8904->devtype = id->driver_data;
i2c_set_clientdata(i2c, wm8904);
wm8904->pdata = i2c->dev.platform_data;
ret = snd_soc_register_codec(&i2c->dev,
&soc_codec_dev_wm8904, &wm8904_dai, 1);
if (ret < 0)
kfree(wm8904);
return ret;
}
static __devexit int wm8904_i2c_remove(struct i2c_client *client)
{
snd_soc_unregister_codec(&client->dev);
kfree(i2c_get_clientdata(client));
return 0;
}
static int __init wm8904_modinit(void)
{
int ret = 0;
#if defined(CONFIG_I2C) || defined(CONFIG_I2C_MODULE)
ret = i2c_add_driver(&wm8904_i2c_driver);
if (ret != 0) {
printk(KERN_ERR "Failed to register wm8904 I2C driver: %d\n",
ret);
}
#endif
return ret;
}
static void __exit wm8904_exit(void)
{
#if defined(CONFIG_I2C) || defined(CONFIG_I2C_MODULE)
i2c_del_driver(&wm8904_i2c_driver);
#endif
}
