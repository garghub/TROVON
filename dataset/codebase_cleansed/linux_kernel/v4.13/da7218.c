static void da7218_alc_calib(struct snd_soc_codec *codec)
{
u8 mic_1_ctrl, mic_2_ctrl;
u8 mixin_1_ctrl, mixin_2_ctrl;
u8 in_1l_filt_ctrl, in_1r_filt_ctrl, in_2l_filt_ctrl, in_2r_filt_ctrl;
u8 in_1_hpf_ctrl, in_2_hpf_ctrl;
u8 calib_ctrl;
int i = 0;
bool calibrated = false;
mic_1_ctrl = snd_soc_read(codec, DA7218_MIC_1_CTRL);
mic_2_ctrl = snd_soc_read(codec, DA7218_MIC_2_CTRL);
mixin_1_ctrl = snd_soc_read(codec, DA7218_MIXIN_1_CTRL);
mixin_2_ctrl = snd_soc_read(codec, DA7218_MIXIN_2_CTRL);
in_1l_filt_ctrl = snd_soc_read(codec, DA7218_IN_1L_FILTER_CTRL);
in_1r_filt_ctrl = snd_soc_read(codec, DA7218_IN_1R_FILTER_CTRL);
in_2l_filt_ctrl = snd_soc_read(codec, DA7218_IN_2L_FILTER_CTRL);
in_2r_filt_ctrl = snd_soc_read(codec, DA7218_IN_2R_FILTER_CTRL);
in_1_hpf_ctrl = snd_soc_read(codec, DA7218_IN_1_HPF_FILTER_CTRL);
in_2_hpf_ctrl = snd_soc_read(codec, DA7218_IN_2_HPF_FILTER_CTRL);
snd_soc_update_bits(codec, DA7218_MIC_1_CTRL, DA7218_MIC_1_AMP_EN_MASK,
DA7218_MIC_1_AMP_EN_MASK);
snd_soc_update_bits(codec, DA7218_MIC_2_CTRL, DA7218_MIC_2_AMP_EN_MASK,
DA7218_MIC_2_AMP_EN_MASK);
snd_soc_update_bits(codec, DA7218_MIC_1_CTRL,
DA7218_MIC_1_AMP_MUTE_EN_MASK,
DA7218_MIC_1_AMP_MUTE_EN_MASK);
snd_soc_update_bits(codec, DA7218_MIC_2_CTRL,
DA7218_MIC_2_AMP_MUTE_EN_MASK,
DA7218_MIC_2_AMP_MUTE_EN_MASK);
snd_soc_update_bits(codec, DA7218_MIXIN_1_CTRL,
DA7218_MIXIN_1_AMP_EN_MASK |
DA7218_MIXIN_1_AMP_MUTE_EN_MASK,
DA7218_MIXIN_1_AMP_EN_MASK);
snd_soc_update_bits(codec, DA7218_MIXIN_2_CTRL,
DA7218_MIXIN_2_AMP_EN_MASK |
DA7218_MIXIN_2_AMP_MUTE_EN_MASK,
DA7218_MIXIN_2_AMP_EN_MASK);
snd_soc_update_bits(codec, DA7218_IN_1L_FILTER_CTRL,
DA7218_IN_1L_FILTER_EN_MASK |
DA7218_IN_1L_MUTE_EN_MASK,
DA7218_IN_1L_FILTER_EN_MASK);
snd_soc_update_bits(codec, DA7218_IN_1R_FILTER_CTRL,
DA7218_IN_1R_FILTER_EN_MASK |
DA7218_IN_1R_MUTE_EN_MASK,
DA7218_IN_1R_FILTER_EN_MASK);
snd_soc_update_bits(codec, DA7218_IN_2L_FILTER_CTRL,
DA7218_IN_2L_FILTER_EN_MASK |
DA7218_IN_2L_MUTE_EN_MASK,
DA7218_IN_2L_FILTER_EN_MASK);
snd_soc_update_bits(codec, DA7218_IN_2R_FILTER_CTRL,
DA7218_IN_2R_FILTER_EN_MASK |
DA7218_IN_2R_MUTE_EN_MASK,
DA7218_IN_2R_FILTER_EN_MASK);
snd_soc_update_bits(codec, DA7218_IN_1_HPF_FILTER_CTRL,
DA7218_IN_1_VOICE_EN_MASK, 0);
snd_soc_update_bits(codec, DA7218_IN_2_HPF_FILTER_CTRL,
DA7218_IN_2_VOICE_EN_MASK, 0);
snd_soc_update_bits(codec, DA7218_CALIB_CTRL, DA7218_CALIB_AUTO_EN_MASK,
DA7218_CALIB_AUTO_EN_MASK);
do {
calib_ctrl = snd_soc_read(codec, DA7218_CALIB_CTRL);
if (calib_ctrl & DA7218_CALIB_AUTO_EN_MASK) {
++i;
usleep_range(DA7218_ALC_CALIB_DELAY_MIN,
DA7218_ALC_CALIB_DELAY_MAX);
} else {
calibrated = true;
}
} while ((i < DA7218_ALC_CALIB_MAX_TRIES) && (!calibrated));
if ((!calibrated) || (calib_ctrl & DA7218_CALIB_OVERFLOW_MASK)) {
dev_warn(codec->dev,
"ALC auto calibration failed - %s\n",
(calibrated) ? "overflow" : "timeout");
snd_soc_update_bits(codec, DA7218_CALIB_CTRL,
DA7218_CALIB_OFFSET_EN_MASK, 0);
snd_soc_update_bits(codec, DA7218_ALC_CTRL1,
DA7218_ALC_SYNC_MODE_MASK, 0);
} else {
snd_soc_update_bits(codec, DA7218_CALIB_CTRL,
DA7218_CALIB_OFFSET_EN_MASK,
DA7218_CALIB_OFFSET_EN_MASK);
snd_soc_update_bits(codec, DA7218_ALC_CTRL1,
DA7218_ALC_SYNC_MODE_MASK,
DA7218_ALC_SYNC_MODE_CH1 |
DA7218_ALC_SYNC_MODE_CH2);
}
snd_soc_write(codec, DA7218_IN_1_HPF_FILTER_CTRL, in_1_hpf_ctrl);
snd_soc_write(codec, DA7218_IN_2_HPF_FILTER_CTRL, in_2_hpf_ctrl);
snd_soc_write(codec, DA7218_IN_1L_FILTER_CTRL, in_1l_filt_ctrl);
snd_soc_write(codec, DA7218_IN_1R_FILTER_CTRL, in_1r_filt_ctrl);
snd_soc_write(codec, DA7218_IN_2L_FILTER_CTRL, in_2l_filt_ctrl);
snd_soc_write(codec, DA7218_IN_2R_FILTER_CTRL, in_2r_filt_ctrl);
snd_soc_write(codec, DA7218_MIXIN_1_CTRL, mixin_1_ctrl);
snd_soc_write(codec, DA7218_MIXIN_2_CTRL, mixin_2_ctrl);
snd_soc_write(codec, DA7218_MIC_1_CTRL, mic_1_ctrl);
snd_soc_write(codec, DA7218_MIC_2_CTRL, mic_2_ctrl);
}
static int da7218_mixin_gain_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_soc_kcontrol_codec(kcontrol);
struct da7218_priv *da7218 = snd_soc_codec_get_drvdata(codec);
int ret;
ret = snd_soc_put_volsw(kcontrol, ucontrol);
if ((ret == 1) && (da7218->alc_en))
da7218_alc_calib(codec);
return ret;
}
static int da7218_alc_sw_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct soc_mixer_control *mc =
(struct soc_mixer_control *) kcontrol->private_value;
struct snd_soc_codec *codec = snd_soc_kcontrol_codec(kcontrol);
struct da7218_priv *da7218 = snd_soc_codec_get_drvdata(codec);
unsigned int lvalue = ucontrol->value.integer.value[0];
unsigned int rvalue = ucontrol->value.integer.value[1];
unsigned int lshift = mc->shift;
unsigned int rshift = mc->rshift;
unsigned int mask = (mc->max << lshift) | (mc->max << rshift);
if ((lvalue || rvalue) && (!da7218->alc_en))
da7218_alc_calib(codec);
da7218->alc_en &= ~mask;
da7218->alc_en |= (lvalue << lshift) | (rvalue << rshift);
return snd_soc_put_volsw(kcontrol, ucontrol);
}
static int da7218_tonegen_freq_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_soc_kcontrol_codec(kcontrol);
struct da7218_priv *da7218 = snd_soc_codec_get_drvdata(codec);
struct soc_mixer_control *mixer_ctrl =
(struct soc_mixer_control *) kcontrol->private_value;
unsigned int reg = mixer_ctrl->reg;
u16 val;
int ret;
ret = regmap_raw_read(da7218->regmap, reg, &val, 2);
if (ret)
return ret;
ucontrol->value.integer.value[0] = le16_to_cpu(val);
return 0;
}
static int da7218_tonegen_freq_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_soc_kcontrol_codec(kcontrol);
struct da7218_priv *da7218 = snd_soc_codec_get_drvdata(codec);
struct soc_mixer_control *mixer_ctrl =
(struct soc_mixer_control *) kcontrol->private_value;
unsigned int reg = mixer_ctrl->reg;
u16 val;
val = cpu_to_le16(ucontrol->value.integer.value[0]);
return regmap_raw_write(da7218->regmap, reg, &val, 2);
}
static int da7218_mic_lvl_det_sw_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_soc_kcontrol_codec(kcontrol);
struct da7218_priv *da7218 = snd_soc_codec_get_drvdata(codec);
struct soc_mixer_control *mixer_ctrl =
(struct soc_mixer_control *) kcontrol->private_value;
unsigned int lvalue = ucontrol->value.integer.value[0];
unsigned int rvalue = ucontrol->value.integer.value[1];
unsigned int lshift = mixer_ctrl->shift;
unsigned int rshift = mixer_ctrl->rshift;
unsigned int mask = (mixer_ctrl->max << lshift) |
(mixer_ctrl->max << rshift);
da7218->mic_lvl_det_en &= ~mask;
da7218->mic_lvl_det_en |= (lvalue << lshift) | (rvalue << rshift);
return snd_soc_write(codec, mixer_ctrl->reg,
(da7218->in_filt_en & da7218->mic_lvl_det_en));
}
static int da7218_mic_lvl_det_sw_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_soc_kcontrol_codec(kcontrol);
struct da7218_priv *da7218 = snd_soc_codec_get_drvdata(codec);
struct soc_mixer_control *mixer_ctrl =
(struct soc_mixer_control *) kcontrol->private_value;
unsigned int lshift = mixer_ctrl->shift;
unsigned int rshift = mixer_ctrl->rshift;
unsigned int lmask = (mixer_ctrl->max << lshift);
unsigned int rmask = (mixer_ctrl->max << rshift);
ucontrol->value.integer.value[0] =
(da7218->mic_lvl_det_en & lmask) >> lshift;
ucontrol->value.integer.value[1] =
(da7218->mic_lvl_det_en & rmask) >> rshift;
return 0;
}
static int da7218_biquad_coeff_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_soc_kcontrol_codec(kcontrol);
struct da7218_priv *da7218 = snd_soc_codec_get_drvdata(codec);
struct soc_bytes_ext *bytes_ext =
(struct soc_bytes_ext *) kcontrol->private_value;
switch (bytes_ext->max) {
case DA7218_OUT_1_BIQ_5STAGE_CFG_SIZE:
memcpy(ucontrol->value.bytes.data, da7218->biq_5stage_coeff,
bytes_ext->max);
break;
case DA7218_SIDETONE_BIQ_3STAGE_CFG_SIZE:
memcpy(ucontrol->value.bytes.data, da7218->stbiq_3stage_coeff,
bytes_ext->max);
break;
default:
return -EINVAL;
}
return 0;
}
static int da7218_biquad_coeff_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_soc_kcontrol_codec(kcontrol);
struct da7218_priv *da7218 = snd_soc_codec_get_drvdata(codec);
struct soc_bytes_ext *bytes_ext =
(struct soc_bytes_ext *) kcontrol->private_value;
u8 reg, out_filt1l;
u8 cfg[DA7218_BIQ_CFG_SIZE];
int i;
switch (bytes_ext->max) {
case DA7218_OUT_1_BIQ_5STAGE_CFG_SIZE:
reg = DA7218_OUT_1_BIQ_5STAGE_DATA;
memcpy(da7218->biq_5stage_coeff, ucontrol->value.bytes.data,
bytes_ext->max);
break;
case DA7218_SIDETONE_BIQ_3STAGE_CFG_SIZE:
reg = DA7218_SIDETONE_BIQ_3STAGE_DATA;
memcpy(da7218->stbiq_3stage_coeff, ucontrol->value.bytes.data,
bytes_ext->max);
break;
default:
return -EINVAL;
}
out_filt1l = snd_soc_read(codec, DA7218_OUT_1L_FILTER_CTRL);
snd_soc_write(codec, DA7218_OUT_1L_FILTER_CTRL,
out_filt1l | DA7218_OUT_1L_FILTER_EN_MASK);
for (i = 0; i < bytes_ext->max; ++i) {
cfg[DA7218_BIQ_CFG_DATA] = ucontrol->value.bytes.data[i];
cfg[DA7218_BIQ_CFG_ADDR] = i;
regmap_raw_write(da7218->regmap, reg, cfg, DA7218_BIQ_CFG_SIZE);
}
snd_soc_write(codec, DA7218_OUT_1L_FILTER_CTRL, out_filt1l);
return 0;
}
static int da7218_in_filter_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
struct da7218_priv *da7218 = snd_soc_codec_get_drvdata(codec);
u8 mask;
switch (w->reg) {
case DA7218_IN_1L_FILTER_CTRL:
mask = (1 << DA7218_LVL_DET_EN_CHAN1L_SHIFT);
break;
case DA7218_IN_1R_FILTER_CTRL:
mask = (1 << DA7218_LVL_DET_EN_CHAN1R_SHIFT);
break;
case DA7218_IN_2L_FILTER_CTRL:
mask = (1 << DA7218_LVL_DET_EN_CHAN2L_SHIFT);
break;
case DA7218_IN_2R_FILTER_CTRL:
mask = (1 << DA7218_LVL_DET_EN_CHAN2R_SHIFT);
break;
default:
return -EINVAL;
}
switch (event) {
case SND_SOC_DAPM_POST_PMU:
da7218->in_filt_en |= mask;
if (mask & da7218->mic_lvl_det_en)
msleep(DA7218_MIC_LVL_DET_DELAY);
break;
case SND_SOC_DAPM_PRE_PMD:
da7218->in_filt_en &= ~mask;
break;
default:
return -EINVAL;
}
snd_soc_write(codec, DA7218_LVL_DET_CTRL,
(da7218->in_filt_en & da7218->mic_lvl_det_en));
return 0;
}
static int da7218_dai_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
struct da7218_priv *da7218 = snd_soc_codec_get_drvdata(codec);
u8 pll_ctrl, pll_status, refosc_cal;
int i;
bool success;
switch (event) {
case SND_SOC_DAPM_POST_PMU:
if (da7218->master)
snd_soc_update_bits(codec, DA7218_DAI_CLK_MODE,
DA7218_DAI_CLK_EN_MASK,
DA7218_DAI_CLK_EN_MASK);
snd_soc_write(codec, DA7218_PLL_REFOSC_CAL,
DA7218_PLL_REFOSC_CAL_START_MASK);
snd_soc_write(codec, DA7218_PLL_REFOSC_CAL,
DA7218_PLL_REFOSC_CAL_START_MASK |
DA7218_PLL_REFOSC_CAL_EN_MASK);
i = 0;
success = false;
do {
refosc_cal = snd_soc_read(codec, DA7218_PLL_REFOSC_CAL);
if (!(refosc_cal & DA7218_PLL_REFOSC_CAL_START_MASK)) {
success = true;
} else {
++i;
usleep_range(DA7218_REF_OSC_CHECK_DELAY_MIN,
DA7218_REF_OSC_CHECK_DELAY_MAX);
}
} while ((i < DA7218_REF_OSC_CHECK_TRIES) && (!success));
if (!success)
dev_warn(codec->dev,
"Reference oscillator failed calibration\n");
snd_soc_write(codec, DA7218_PC_COUNT,
DA7218_PC_RESYNC_AUTO_MASK);
pll_ctrl = snd_soc_read(codec, DA7218_PLL_CTRL);
if ((pll_ctrl & DA7218_PLL_MODE_MASK) != DA7218_PLL_MODE_SRM)
return 0;
i = 0;
success = false;
do {
pll_status = snd_soc_read(codec, DA7218_PLL_STATUS);
if (pll_status & DA7218_PLL_SRM_STATUS_SRM_LOCK) {
success = true;
} else {
++i;
msleep(DA7218_SRM_CHECK_DELAY);
}
} while ((i < DA7218_SRM_CHECK_TRIES) && (!success));
if (!success)
dev_warn(codec->dev, "SRM failed to lock\n");
return 0;
case SND_SOC_DAPM_POST_PMD:
snd_soc_write(codec, DA7218_PC_COUNT, DA7218_PC_FREERUN_MASK);
if (da7218->master)
snd_soc_update_bits(codec, DA7218_DAI_CLK_MODE,
DA7218_DAI_CLK_EN_MASK, 0);
return 0;
default:
return -EINVAL;
}
}
static int da7218_cp_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
struct da7218_priv *da7218 = snd_soc_codec_get_drvdata(codec);
if (da7218->hp_single_supply)
return 0;
switch (event) {
case SND_SOC_DAPM_PRE_PMU:
snd_soc_update_bits(codec, DA7218_CP_CTRL, DA7218_CP_EN_MASK,
DA7218_CP_EN_MASK);
return 0;
case SND_SOC_DAPM_PRE_PMD:
snd_soc_update_bits(codec, DA7218_CP_CTRL, DA7218_CP_EN_MASK,
0);
return 0;
default:
return -EINVAL;
}
}
static int da7218_hp_pga_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
switch (event) {
case SND_SOC_DAPM_POST_PMU:
snd_soc_update_bits(codec, w->reg, DA7218_HP_AMP_OE_MASK,
DA7218_HP_AMP_OE_MASK);
return 0;
case SND_SOC_DAPM_PRE_PMD:
snd_soc_update_bits(codec, w->reg, DA7218_HP_AMP_OE_MASK, 0);
return 0;
default:
return -EINVAL;
}
}
static int da7218_set_dai_sysclk(struct snd_soc_dai *codec_dai,
int clk_id, unsigned int freq, int dir)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct da7218_priv *da7218 = snd_soc_codec_get_drvdata(codec);
int ret;
if (da7218->mclk_rate == freq)
return 0;
if ((freq < 2000000) || (freq > 54000000)) {
dev_err(codec_dai->dev, "Unsupported MCLK value %d\n",
freq);
return -EINVAL;
}
switch (clk_id) {
case DA7218_CLKSRC_MCLK_SQR:
snd_soc_update_bits(codec, DA7218_PLL_CTRL,
DA7218_PLL_MCLK_SQR_EN_MASK,
DA7218_PLL_MCLK_SQR_EN_MASK);
break;
case DA7218_CLKSRC_MCLK:
snd_soc_update_bits(codec, DA7218_PLL_CTRL,
DA7218_PLL_MCLK_SQR_EN_MASK, 0);
break;
default:
dev_err(codec_dai->dev, "Unknown clock source %d\n", clk_id);
return -EINVAL;
}
if (da7218->mclk) {
freq = clk_round_rate(da7218->mclk, freq);
ret = clk_set_rate(da7218->mclk, freq);
if (ret) {
dev_err(codec_dai->dev, "Failed to set clock rate %d\n",
freq);
return ret;
}
}
da7218->mclk_rate = freq;
return 0;
}
static int da7218_set_dai_pll(struct snd_soc_dai *codec_dai, int pll_id,
int source, unsigned int fref, unsigned int fout)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct da7218_priv *da7218 = snd_soc_codec_get_drvdata(codec);
u8 pll_ctrl, indiv_bits, indiv;
u8 pll_frac_top, pll_frac_bot, pll_integer;
u32 freq_ref;
u64 frac_div;
if (da7218->mclk_rate < 2000000) {
dev_err(codec->dev, "PLL input clock %d below valid range\n",
da7218->mclk_rate);
return -EINVAL;
} else if (da7218->mclk_rate <= 4500000) {
indiv_bits = DA7218_PLL_INDIV_2_TO_4_5_MHZ;
indiv = DA7218_PLL_INDIV_2_TO_4_5_MHZ_VAL;
} else if (da7218->mclk_rate <= 9000000) {
indiv_bits = DA7218_PLL_INDIV_4_5_TO_9_MHZ;
indiv = DA7218_PLL_INDIV_4_5_TO_9_MHZ_VAL;
} else if (da7218->mclk_rate <= 18000000) {
indiv_bits = DA7218_PLL_INDIV_9_TO_18_MHZ;
indiv = DA7218_PLL_INDIV_9_TO_18_MHZ_VAL;
} else if (da7218->mclk_rate <= 36000000) {
indiv_bits = DA7218_PLL_INDIV_18_TO_36_MHZ;
indiv = DA7218_PLL_INDIV_18_TO_36_MHZ_VAL;
} else if (da7218->mclk_rate <= 54000000) {
indiv_bits = DA7218_PLL_INDIV_36_TO_54_MHZ;
indiv = DA7218_PLL_INDIV_36_TO_54_MHZ_VAL;
} else {
dev_err(codec->dev, "PLL input clock %d above valid range\n",
da7218->mclk_rate);
return -EINVAL;
}
freq_ref = (da7218->mclk_rate / indiv);
pll_ctrl = indiv_bits;
switch (source) {
case DA7218_SYSCLK_MCLK:
pll_ctrl |= DA7218_PLL_MODE_BYPASS;
snd_soc_update_bits(codec, DA7218_PLL_CTRL,
DA7218_PLL_INDIV_MASK |
DA7218_PLL_MODE_MASK, pll_ctrl);
return 0;
case DA7218_SYSCLK_PLL:
pll_ctrl |= DA7218_PLL_MODE_NORMAL;
break;
case DA7218_SYSCLK_PLL_SRM:
pll_ctrl |= DA7218_PLL_MODE_SRM;
break;
default:
dev_err(codec->dev, "Invalid PLL config\n");
return -EINVAL;
}
pll_integer = fout / freq_ref;
frac_div = (u64)(fout % freq_ref) * 8192ULL;
do_div(frac_div, freq_ref);
pll_frac_top = (frac_div >> DA7218_BYTE_SHIFT) & DA7218_BYTE_MASK;
pll_frac_bot = (frac_div) & DA7218_BYTE_MASK;
snd_soc_write(codec, DA7218_PLL_FRAC_TOP, pll_frac_top);
snd_soc_write(codec, DA7218_PLL_FRAC_BOT, pll_frac_bot);
snd_soc_write(codec, DA7218_PLL_INTEGER, pll_integer);
snd_soc_update_bits(codec, DA7218_PLL_CTRL,
DA7218_PLL_MODE_MASK | DA7218_PLL_INDIV_MASK,
pll_ctrl);
return 0;
}
static int da7218_set_dai_fmt(struct snd_soc_dai *codec_dai, unsigned int fmt)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct da7218_priv *da7218 = snd_soc_codec_get_drvdata(codec);
u8 dai_clk_mode = 0, dai_ctrl = 0;
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBM_CFM:
da7218->master = true;
break;
case SND_SOC_DAIFMT_CBS_CFS:
da7218->master = false;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
case SND_SOC_DAIFMT_LEFT_J:
case SND_SOC_DAIFMT_RIGHT_J:
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
break;
case SND_SOC_DAIFMT_NB_IF:
dai_clk_mode |= DA7218_DAI_WCLK_POL_INV;
break;
case SND_SOC_DAIFMT_IB_NF:
dai_clk_mode |= DA7218_DAI_CLK_POL_INV;
break;
case SND_SOC_DAIFMT_IB_IF:
dai_clk_mode |= DA7218_DAI_WCLK_POL_INV |
DA7218_DAI_CLK_POL_INV;
break;
default:
return -EINVAL;
}
break;
case SND_SOC_DAIFMT_DSP_B:
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
dai_clk_mode |= DA7218_DAI_CLK_POL_INV;
break;
case SND_SOC_DAIFMT_NB_IF:
dai_clk_mode |= DA7218_DAI_WCLK_POL_INV |
DA7218_DAI_CLK_POL_INV;
break;
case SND_SOC_DAIFMT_IB_NF:
break;
case SND_SOC_DAIFMT_IB_IF:
dai_clk_mode |= DA7218_DAI_WCLK_POL_INV;
break;
default:
return -EINVAL;
}
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
dai_ctrl |= DA7218_DAI_FORMAT_I2S;
break;
case SND_SOC_DAIFMT_LEFT_J:
dai_ctrl |= DA7218_DAI_FORMAT_LEFT_J;
break;
case SND_SOC_DAIFMT_RIGHT_J:
dai_ctrl |= DA7218_DAI_FORMAT_RIGHT_J;
break;
case SND_SOC_DAIFMT_DSP_B:
dai_ctrl |= DA7218_DAI_FORMAT_DSP;
break;
default:
return -EINVAL;
}
dai_clk_mode |= DA7218_DAI_BCLKS_PER_WCLK_64;
snd_soc_write(codec, DA7218_DAI_CLK_MODE, dai_clk_mode);
snd_soc_update_bits(codec, DA7218_DAI_CTRL, DA7218_DAI_FORMAT_MASK,
dai_ctrl);
return 0;
}
static int da7218_set_dai_tdm_slot(struct snd_soc_dai *dai,
unsigned int tx_mask, unsigned int rx_mask,
int slots, int slot_width)
{
struct snd_soc_codec *codec = dai->codec;
u8 dai_bclks_per_wclk;
u32 frame_size;
if (!tx_mask) {
snd_soc_update_bits(codec, DA7218_DAI_TDM_CTRL,
DA7218_DAI_TDM_CH_EN_MASK |
DA7218_DAI_TDM_MODE_EN_MASK, 0);
snd_soc_update_bits(codec, DA7218_DAI_CLK_MODE,
DA7218_DAI_BCLKS_PER_WCLK_MASK,
DA7218_DAI_BCLKS_PER_WCLK_64);
return 0;
}
if (fls(tx_mask) > DA7218_DAI_TDM_MAX_SLOTS) {
dev_err(codec->dev, "Invalid number of slots, max = %d\n",
DA7218_DAI_TDM_MAX_SLOTS);
return -EINVAL;
}
if (rx_mask >> DA7218_2BYTE_SHIFT) {
dev_err(codec->dev, "Invalid slot offset, max = %d\n",
DA7218_2BYTE_MASK);
return -EINVAL;
}
frame_size = slots * slot_width;
switch (frame_size) {
case 32:
dai_bclks_per_wclk = DA7218_DAI_BCLKS_PER_WCLK_32;
break;
case 64:
dai_bclks_per_wclk = DA7218_DAI_BCLKS_PER_WCLK_64;
break;
case 128:
dai_bclks_per_wclk = DA7218_DAI_BCLKS_PER_WCLK_128;
break;
case 256:
dai_bclks_per_wclk = DA7218_DAI_BCLKS_PER_WCLK_256;
break;
default:
dev_err(codec->dev, "Invalid frame size\n");
return -EINVAL;
}
snd_soc_update_bits(codec, DA7218_DAI_CLK_MODE,
DA7218_DAI_BCLKS_PER_WCLK_MASK,
dai_bclks_per_wclk);
snd_soc_write(codec, DA7218_DAI_OFFSET_LOWER,
(rx_mask & DA7218_BYTE_MASK));
snd_soc_write(codec, DA7218_DAI_OFFSET_UPPER,
((rx_mask >> DA7218_BYTE_SHIFT) & DA7218_BYTE_MASK));
snd_soc_update_bits(codec, DA7218_DAI_TDM_CTRL,
DA7218_DAI_TDM_CH_EN_MASK |
DA7218_DAI_TDM_MODE_EN_MASK,
(tx_mask << DA7218_DAI_TDM_CH_EN_SHIFT) |
DA7218_DAI_TDM_MODE_EN_MASK);
return 0;
}
static int da7218_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
u8 dai_ctrl = 0, fs;
unsigned int channels;
switch (params_width(params)) {
case 16:
dai_ctrl |= DA7218_DAI_WORD_LENGTH_S16_LE;
break;
case 20:
dai_ctrl |= DA7218_DAI_WORD_LENGTH_S20_LE;
break;
case 24:
dai_ctrl |= DA7218_DAI_WORD_LENGTH_S24_LE;
break;
case 32:
dai_ctrl |= DA7218_DAI_WORD_LENGTH_S32_LE;
break;
default:
return -EINVAL;
}
channels = params_channels(params);
if ((channels < 1) || (channels > DA7218_DAI_CH_NUM_MAX)) {
dev_err(codec->dev,
"Invalid number of channels, only 1 to %d supported\n",
DA7218_DAI_CH_NUM_MAX);
return -EINVAL;
}
dai_ctrl |= channels << DA7218_DAI_CH_NUM_SHIFT;
switch (params_rate(params)) {
case 8000:
fs = DA7218_SR_8000;
break;
case 11025:
fs = DA7218_SR_11025;
break;
case 12000:
fs = DA7218_SR_12000;
break;
case 16000:
fs = DA7218_SR_16000;
break;
case 22050:
fs = DA7218_SR_22050;
break;
case 24000:
fs = DA7218_SR_24000;
break;
case 32000:
fs = DA7218_SR_32000;
break;
case 44100:
fs = DA7218_SR_44100;
break;
case 48000:
fs = DA7218_SR_48000;
break;
case 88200:
fs = DA7218_SR_88200;
break;
case 96000:
fs = DA7218_SR_96000;
break;
default:
return -EINVAL;
}
snd_soc_update_bits(codec, DA7218_DAI_CTRL,
DA7218_DAI_WORD_LENGTH_MASK | DA7218_DAI_CH_NUM_MASK,
dai_ctrl);
snd_soc_write(codec, DA7218_SR,
(fs << DA7218_SR_DAC_SHIFT) | (fs << DA7218_SR_ADC_SHIFT));
return 0;
}
int da7218_hpldet(struct snd_soc_codec *codec, struct snd_soc_jack *jack)
{
struct da7218_priv *da7218 = snd_soc_codec_get_drvdata(codec);
if (da7218->dev_id == DA7217_DEV_ID)
return -EINVAL;
da7218->jack = jack;
snd_soc_update_bits(codec, DA7218_HPLDET_JACK,
DA7218_HPLDET_JACK_EN_MASK,
jack ? DA7218_HPLDET_JACK_EN_MASK : 0);
return 0;
}
static void da7218_micldet_irq(struct snd_soc_codec *codec)
{
char *envp[] = {
"EVENT=MIC_LEVEL_DETECT",
NULL,
};
kobject_uevent_env(&codec->dev->kobj, KOBJ_CHANGE, envp);
}
static void da7218_hpldet_irq(struct snd_soc_codec *codec)
{
struct da7218_priv *da7218 = snd_soc_codec_get_drvdata(codec);
u8 jack_status;
int report;
jack_status = snd_soc_read(codec, DA7218_EVENT_STATUS);
if (jack_status & DA7218_HPLDET_JACK_STS_MASK)
report = SND_JACK_HEADPHONE;
else
report = 0;
snd_soc_jack_report(da7218->jack, report, SND_JACK_HEADPHONE);
}
static irqreturn_t da7218_irq_thread(int irq, void *data)
{
struct snd_soc_codec *codec = data;
u8 status;
status = snd_soc_read(codec, DA7218_EVENT);
if (!status)
return IRQ_NONE;
if (status & DA7218_LVL_DET_EVENT_MASK)
da7218_micldet_irq(codec);
if (status & DA7218_HPLDET_JACK_EVENT_MASK)
da7218_hpldet_irq(codec);
snd_soc_write(codec, DA7218_EVENT, status);
return IRQ_HANDLED;
}
static inline int da7218_of_get_id(struct device *dev)
{
const struct of_device_id *id = of_match_device(da7218_of_match, dev);
if (id)
return (uintptr_t)id->data;
else
return -EINVAL;
}
static enum da7218_micbias_voltage
da7218_of_micbias_lvl(struct snd_soc_codec *codec, u32 val)
{
switch (val) {
case 1200:
return DA7218_MICBIAS_1_2V;
case 1600:
return DA7218_MICBIAS_1_6V;
case 1800:
return DA7218_MICBIAS_1_8V;
case 2000:
return DA7218_MICBIAS_2_0V;
case 2200:
return DA7218_MICBIAS_2_2V;
case 2400:
return DA7218_MICBIAS_2_4V;
case 2600:
return DA7218_MICBIAS_2_6V;
case 2800:
return DA7218_MICBIAS_2_8V;
case 3000:
return DA7218_MICBIAS_3_0V;
default:
dev_warn(codec->dev, "Invalid micbias level");
return DA7218_MICBIAS_1_6V;
}
}
static enum da7218_mic_amp_in_sel
da7218_of_mic_amp_in_sel(struct snd_soc_codec *codec, const char *str)
{
if (!strcmp(str, "diff")) {
return DA7218_MIC_AMP_IN_SEL_DIFF;
} else if (!strcmp(str, "se_p")) {
return DA7218_MIC_AMP_IN_SEL_SE_P;
} else if (!strcmp(str, "se_n")) {
return DA7218_MIC_AMP_IN_SEL_SE_N;
} else {
dev_warn(codec->dev, "Invalid mic input type selection");
return DA7218_MIC_AMP_IN_SEL_DIFF;
}
}
static enum da7218_dmic_data_sel
da7218_of_dmic_data_sel(struct snd_soc_codec *codec, const char *str)
{
if (!strcmp(str, "lrise_rfall")) {
return DA7218_DMIC_DATA_LRISE_RFALL;
} else if (!strcmp(str, "lfall_rrise")) {
return DA7218_DMIC_DATA_LFALL_RRISE;
} else {
dev_warn(codec->dev, "Invalid DMIC data type selection");
return DA7218_DMIC_DATA_LRISE_RFALL;
}
}
static enum da7218_dmic_samplephase
da7218_of_dmic_samplephase(struct snd_soc_codec *codec, const char *str)
{
if (!strcmp(str, "on_clkedge")) {
return DA7218_DMIC_SAMPLE_ON_CLKEDGE;
} else if (!strcmp(str, "between_clkedge")) {
return DA7218_DMIC_SAMPLE_BETWEEN_CLKEDGE;
} else {
dev_warn(codec->dev, "Invalid DMIC sample phase");
return DA7218_DMIC_SAMPLE_ON_CLKEDGE;
}
}
static enum da7218_dmic_clk_rate
da7218_of_dmic_clkrate(struct snd_soc_codec *codec, u32 val)
{
switch (val) {
case 1500000:
return DA7218_DMIC_CLK_1_5MHZ;
case 3000000:
return DA7218_DMIC_CLK_3_0MHZ;
default:
dev_warn(codec->dev, "Invalid DMIC clock rate");
return DA7218_DMIC_CLK_3_0MHZ;
}
}
static enum da7218_hpldet_jack_rate
da7218_of_jack_rate(struct snd_soc_codec *codec, u32 val)
{
switch (val) {
case 5:
return DA7218_HPLDET_JACK_RATE_5US;
case 10:
return DA7218_HPLDET_JACK_RATE_10US;
case 20:
return DA7218_HPLDET_JACK_RATE_20US;
case 40:
return DA7218_HPLDET_JACK_RATE_40US;
case 80:
return DA7218_HPLDET_JACK_RATE_80US;
case 160:
return DA7218_HPLDET_JACK_RATE_160US;
case 320:
return DA7218_HPLDET_JACK_RATE_320US;
case 640:
return DA7218_HPLDET_JACK_RATE_640US;
default:
dev_warn(codec->dev, "Invalid jack detect rate");
return DA7218_HPLDET_JACK_RATE_40US;
}
}
static enum da7218_hpldet_jack_debounce
da7218_of_jack_debounce(struct snd_soc_codec *codec, u32 val)
{
switch (val) {
case 0:
return DA7218_HPLDET_JACK_DEBOUNCE_OFF;
case 2:
return DA7218_HPLDET_JACK_DEBOUNCE_2;
case 3:
return DA7218_HPLDET_JACK_DEBOUNCE_3;
case 4:
return DA7218_HPLDET_JACK_DEBOUNCE_4;
default:
dev_warn(codec->dev, "Invalid jack debounce");
return DA7218_HPLDET_JACK_DEBOUNCE_2;
}
}
static enum da7218_hpldet_jack_thr
da7218_of_jack_thr(struct snd_soc_codec *codec, u32 val)
{
switch (val) {
case 84:
return DA7218_HPLDET_JACK_THR_84PCT;
case 88:
return DA7218_HPLDET_JACK_THR_88PCT;
case 92:
return DA7218_HPLDET_JACK_THR_92PCT;
case 96:
return DA7218_HPLDET_JACK_THR_96PCT;
default:
dev_warn(codec->dev, "Invalid jack threshold level");
return DA7218_HPLDET_JACK_THR_84PCT;
}
}
static struct da7218_pdata *da7218_of_to_pdata(struct snd_soc_codec *codec)
{
struct da7218_priv *da7218 = snd_soc_codec_get_drvdata(codec);
struct device_node *np = codec->dev->of_node;
struct device_node *hpldet_np;
struct da7218_pdata *pdata;
struct da7218_hpldet_pdata *hpldet_pdata;
const char *of_str;
u32 of_val32;
pdata = devm_kzalloc(codec->dev, sizeof(*pdata), GFP_KERNEL);
if (!pdata) {
dev_warn(codec->dev, "Failed to allocate memory for pdata\n");
return NULL;
}
if (of_property_read_u32(np, "dlg,micbias1-lvl-millivolt", &of_val32) >= 0)
pdata->micbias1_lvl = da7218_of_micbias_lvl(codec, of_val32);
else
pdata->micbias1_lvl = DA7218_MICBIAS_1_6V;
if (of_property_read_u32(np, "dlg,micbias2-lvl-millivolt", &of_val32) >= 0)
pdata->micbias2_lvl = da7218_of_micbias_lvl(codec, of_val32);
else
pdata->micbias2_lvl = DA7218_MICBIAS_1_6V;
if (!of_property_read_string(np, "dlg,mic1-amp-in-sel", &of_str))
pdata->mic1_amp_in_sel =
da7218_of_mic_amp_in_sel(codec, of_str);
else
pdata->mic1_amp_in_sel = DA7218_MIC_AMP_IN_SEL_DIFF;
if (!of_property_read_string(np, "dlg,mic2-amp-in-sel", &of_str))
pdata->mic2_amp_in_sel =
da7218_of_mic_amp_in_sel(codec, of_str);
else
pdata->mic2_amp_in_sel = DA7218_MIC_AMP_IN_SEL_DIFF;
if (!of_property_read_string(np, "dlg,dmic1-data-sel", &of_str))
pdata->dmic1_data_sel = da7218_of_dmic_data_sel(codec, of_str);
else
pdata->dmic1_data_sel = DA7218_DMIC_DATA_LRISE_RFALL;
if (!of_property_read_string(np, "dlg,dmic1-samplephase", &of_str))
pdata->dmic1_samplephase =
da7218_of_dmic_samplephase(codec, of_str);
else
pdata->dmic1_samplephase = DA7218_DMIC_SAMPLE_ON_CLKEDGE;
if (of_property_read_u32(np, "dlg,dmic1-clkrate-hz", &of_val32) >= 0)
pdata->dmic1_clk_rate = da7218_of_dmic_clkrate(codec, of_val32);
else
pdata->dmic1_clk_rate = DA7218_DMIC_CLK_3_0MHZ;
if (!of_property_read_string(np, "dlg,dmic2-data-sel", &of_str))
pdata->dmic2_data_sel = da7218_of_dmic_data_sel(codec, of_str);
else
pdata->dmic2_data_sel = DA7218_DMIC_DATA_LRISE_RFALL;
if (!of_property_read_string(np, "dlg,dmic2-samplephase", &of_str))
pdata->dmic2_samplephase =
da7218_of_dmic_samplephase(codec, of_str);
else
pdata->dmic2_samplephase = DA7218_DMIC_SAMPLE_ON_CLKEDGE;
if (of_property_read_u32(np, "dlg,dmic2-clkrate-hz", &of_val32) >= 0)
pdata->dmic2_clk_rate = da7218_of_dmic_clkrate(codec, of_val32);
else
pdata->dmic2_clk_rate = DA7218_DMIC_CLK_3_0MHZ;
if (da7218->dev_id == DA7217_DEV_ID) {
if (of_property_read_bool(np, "dlg,hp-diff-single-supply"))
pdata->hp_diff_single_supply = true;
}
if (da7218->dev_id == DA7218_DEV_ID) {
hpldet_np = of_find_node_by_name(np, "da7218_hpldet");
if (!hpldet_np)
return pdata;
hpldet_pdata = devm_kzalloc(codec->dev, sizeof(*hpldet_pdata),
GFP_KERNEL);
if (!hpldet_pdata) {
dev_warn(codec->dev,
"Failed to allocate memory for hpldet pdata\n");
of_node_put(hpldet_np);
return pdata;
}
pdata->hpldet_pdata = hpldet_pdata;
if (of_property_read_u32(hpldet_np, "dlg,jack-rate-us",
&of_val32) >= 0)
hpldet_pdata->jack_rate =
da7218_of_jack_rate(codec, of_val32);
else
hpldet_pdata->jack_rate = DA7218_HPLDET_JACK_RATE_40US;
if (of_property_read_u32(hpldet_np, "dlg,jack-debounce",
&of_val32) >= 0)
hpldet_pdata->jack_debounce =
da7218_of_jack_debounce(codec, of_val32);
else
hpldet_pdata->jack_debounce =
DA7218_HPLDET_JACK_DEBOUNCE_2;
if (of_property_read_u32(hpldet_np, "dlg,jack-threshold-pct",
&of_val32) >= 0)
hpldet_pdata->jack_thr =
da7218_of_jack_thr(codec, of_val32);
else
hpldet_pdata->jack_thr = DA7218_HPLDET_JACK_THR_84PCT;
if (of_property_read_bool(hpldet_np, "dlg,comp-inv"))
hpldet_pdata->comp_inv = true;
if (of_property_read_bool(hpldet_np, "dlg,hyst"))
hpldet_pdata->hyst = true;
if (of_property_read_bool(hpldet_np, "dlg,discharge"))
hpldet_pdata->discharge = true;
of_node_put(hpldet_np);
}
return pdata;
}
static int da7218_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
struct da7218_priv *da7218 = snd_soc_codec_get_drvdata(codec);
int ret;
switch (level) {
case SND_SOC_BIAS_ON:
break;
case SND_SOC_BIAS_PREPARE:
if (snd_soc_codec_get_bias_level(codec) == SND_SOC_BIAS_STANDBY) {
if (da7218->mclk) {
ret = clk_prepare_enable(da7218->mclk);
if (ret) {
dev_err(codec->dev, "Failed to enable mclk\n");
return ret;
}
}
}
break;
case SND_SOC_BIAS_STANDBY:
if (snd_soc_codec_get_bias_level(codec) == SND_SOC_BIAS_OFF) {
snd_soc_update_bits(codec, DA7218_REFERENCES,
DA7218_BIAS_EN_MASK,
DA7218_BIAS_EN_MASK);
snd_soc_update_bits(codec, DA7218_LDO_CTRL,
DA7218_LDO_EN_MASK,
DA7218_LDO_EN_MASK);
} else {
if (da7218->mclk)
clk_disable_unprepare(da7218->mclk);
}
break;
case SND_SOC_BIAS_OFF:
if (!da7218->jack) {
snd_soc_update_bits(codec, DA7218_LDO_CTRL,
DA7218_LDO_EN_MASK, 0);
snd_soc_update_bits(codec, DA7218_REFERENCES,
DA7218_BIAS_EN_MASK, 0);
}
break;
}
return 0;
}
static int da7218_handle_supplies(struct snd_soc_codec *codec)
{
struct da7218_priv *da7218 = snd_soc_codec_get_drvdata(codec);
struct regulator *vddio;
u8 io_voltage_lvl = DA7218_IO_VOLTAGE_LEVEL_2_5V_3_6V;
int i, ret;
for (i = 0; i < DA7218_NUM_SUPPLIES; ++i)
da7218->supplies[i].supply = da7218_supply_names[i];
ret = devm_regulator_bulk_get(codec->dev, DA7218_NUM_SUPPLIES,
da7218->supplies);
if (ret) {
dev_err(codec->dev, "Failed to get supplies\n");
return ret;
}
vddio = da7218->supplies[DA7218_SUPPLY_VDDIO].consumer;
ret = regulator_get_voltage(vddio);
if (ret < 1500000)
dev_warn(codec->dev, "Invalid VDDIO voltage\n");
else if (ret < 2500000)
io_voltage_lvl = DA7218_IO_VOLTAGE_LEVEL_1_5V_2_5V;
ret = regulator_bulk_enable(DA7218_NUM_SUPPLIES, da7218->supplies);
if (ret) {
dev_err(codec->dev, "Failed to enable supplies\n");
return ret;
}
snd_soc_write(codec, DA7218_SYSTEM_ACTIVE, DA7218_SYSTEM_ACTIVE_MASK);
snd_soc_write(codec, DA7218_IO_CTRL, io_voltage_lvl);
return 0;
}
static void da7218_handle_pdata(struct snd_soc_codec *codec)
{
struct da7218_priv *da7218 = snd_soc_codec_get_drvdata(codec);
struct da7218_pdata *pdata = da7218->pdata;
if (pdata) {
u8 micbias_lvl = 0, dmic_cfg = 0;
switch (pdata->micbias1_lvl) {
case DA7218_MICBIAS_1_2V:
micbias_lvl |= DA7218_MICBIAS_1_LP_MODE_MASK;
break;
case DA7218_MICBIAS_1_6V:
case DA7218_MICBIAS_1_8V:
case DA7218_MICBIAS_2_0V:
case DA7218_MICBIAS_2_2V:
case DA7218_MICBIAS_2_4V:
case DA7218_MICBIAS_2_6V:
case DA7218_MICBIAS_2_8V:
case DA7218_MICBIAS_3_0V:
micbias_lvl |= (pdata->micbias1_lvl <<
DA7218_MICBIAS_1_LEVEL_SHIFT);
break;
}
switch (pdata->micbias2_lvl) {
case DA7218_MICBIAS_1_2V:
micbias_lvl |= DA7218_MICBIAS_2_LP_MODE_MASK;
break;
case DA7218_MICBIAS_1_6V:
case DA7218_MICBIAS_1_8V:
case DA7218_MICBIAS_2_0V:
case DA7218_MICBIAS_2_2V:
case DA7218_MICBIAS_2_4V:
case DA7218_MICBIAS_2_6V:
case DA7218_MICBIAS_2_8V:
case DA7218_MICBIAS_3_0V:
micbias_lvl |= (pdata->micbias2_lvl <<
DA7218_MICBIAS_2_LEVEL_SHIFT);
break;
}
snd_soc_write(codec, DA7218_MICBIAS_CTRL, micbias_lvl);
switch (pdata->mic1_amp_in_sel) {
case DA7218_MIC_AMP_IN_SEL_DIFF:
case DA7218_MIC_AMP_IN_SEL_SE_P:
case DA7218_MIC_AMP_IN_SEL_SE_N:
snd_soc_write(codec, DA7218_MIC_1_SELECT,
pdata->mic1_amp_in_sel);
break;
}
switch (pdata->mic2_amp_in_sel) {
case DA7218_MIC_AMP_IN_SEL_DIFF:
case DA7218_MIC_AMP_IN_SEL_SE_P:
case DA7218_MIC_AMP_IN_SEL_SE_N:
snd_soc_write(codec, DA7218_MIC_2_SELECT,
pdata->mic2_amp_in_sel);
break;
}
switch (pdata->dmic1_data_sel) {
case DA7218_DMIC_DATA_LFALL_RRISE:
case DA7218_DMIC_DATA_LRISE_RFALL:
dmic_cfg |= (pdata->dmic1_data_sel <<
DA7218_DMIC_1_DATA_SEL_SHIFT);
break;
}
switch (pdata->dmic1_samplephase) {
case DA7218_DMIC_SAMPLE_ON_CLKEDGE:
case DA7218_DMIC_SAMPLE_BETWEEN_CLKEDGE:
dmic_cfg |= (pdata->dmic1_samplephase <<
DA7218_DMIC_1_SAMPLEPHASE_SHIFT);
break;
}
switch (pdata->dmic1_clk_rate) {
case DA7218_DMIC_CLK_3_0MHZ:
case DA7218_DMIC_CLK_1_5MHZ:
dmic_cfg |= (pdata->dmic1_clk_rate <<
DA7218_DMIC_1_CLK_RATE_SHIFT);
break;
}
snd_soc_update_bits(codec, DA7218_DMIC_1_CTRL,
DA7218_DMIC_1_DATA_SEL_MASK |
DA7218_DMIC_1_SAMPLEPHASE_MASK |
DA7218_DMIC_1_CLK_RATE_MASK, dmic_cfg);
dmic_cfg = 0;
switch (pdata->dmic2_data_sel) {
case DA7218_DMIC_DATA_LFALL_RRISE:
case DA7218_DMIC_DATA_LRISE_RFALL:
dmic_cfg |= (pdata->dmic2_data_sel <<
DA7218_DMIC_2_DATA_SEL_SHIFT);
break;
}
switch (pdata->dmic2_samplephase) {
case DA7218_DMIC_SAMPLE_ON_CLKEDGE:
case DA7218_DMIC_SAMPLE_BETWEEN_CLKEDGE:
dmic_cfg |= (pdata->dmic2_samplephase <<
DA7218_DMIC_2_SAMPLEPHASE_SHIFT);
break;
}
switch (pdata->dmic2_clk_rate) {
case DA7218_DMIC_CLK_3_0MHZ:
case DA7218_DMIC_CLK_1_5MHZ:
dmic_cfg |= (pdata->dmic2_clk_rate <<
DA7218_DMIC_2_CLK_RATE_SHIFT);
break;
}
snd_soc_update_bits(codec, DA7218_DMIC_2_CTRL,
DA7218_DMIC_2_DATA_SEL_MASK |
DA7218_DMIC_2_SAMPLEPHASE_MASK |
DA7218_DMIC_2_CLK_RATE_MASK, dmic_cfg);
if (da7218->dev_id == DA7217_DEV_ID) {
da7218->hp_single_supply =
pdata->hp_diff_single_supply;
if (da7218->hp_single_supply) {
snd_soc_write(codec, DA7218_HP_DIFF_UNLOCK,
DA7218_HP_DIFF_UNLOCK_VAL);
snd_soc_update_bits(codec, DA7218_HP_DIFF_CTRL,
DA7218_HP_AMP_SINGLE_SUPPLY_EN_MASK,
DA7218_HP_AMP_SINGLE_SUPPLY_EN_MASK);
}
}
if ((da7218->dev_id == DA7218_DEV_ID) &&
(pdata->hpldet_pdata)) {
struct da7218_hpldet_pdata *hpldet_pdata =
pdata->hpldet_pdata;
u8 hpldet_cfg = 0;
switch (hpldet_pdata->jack_rate) {
case DA7218_HPLDET_JACK_RATE_5US:
case DA7218_HPLDET_JACK_RATE_10US:
case DA7218_HPLDET_JACK_RATE_20US:
case DA7218_HPLDET_JACK_RATE_40US:
case DA7218_HPLDET_JACK_RATE_80US:
case DA7218_HPLDET_JACK_RATE_160US:
case DA7218_HPLDET_JACK_RATE_320US:
case DA7218_HPLDET_JACK_RATE_640US:
hpldet_cfg |=
(hpldet_pdata->jack_rate <<
DA7218_HPLDET_JACK_RATE_SHIFT);
break;
}
switch (hpldet_pdata->jack_debounce) {
case DA7218_HPLDET_JACK_DEBOUNCE_OFF:
case DA7218_HPLDET_JACK_DEBOUNCE_2:
case DA7218_HPLDET_JACK_DEBOUNCE_3:
case DA7218_HPLDET_JACK_DEBOUNCE_4:
hpldet_cfg |=
(hpldet_pdata->jack_debounce <<
DA7218_HPLDET_JACK_DEBOUNCE_SHIFT);
break;
}
switch (hpldet_pdata->jack_thr) {
case DA7218_HPLDET_JACK_THR_84PCT:
case DA7218_HPLDET_JACK_THR_88PCT:
case DA7218_HPLDET_JACK_THR_92PCT:
case DA7218_HPLDET_JACK_THR_96PCT:
hpldet_cfg |=
(hpldet_pdata->jack_thr <<
DA7218_HPLDET_JACK_THR_SHIFT);
break;
}
snd_soc_update_bits(codec, DA7218_HPLDET_JACK,
DA7218_HPLDET_JACK_RATE_MASK |
DA7218_HPLDET_JACK_DEBOUNCE_MASK |
DA7218_HPLDET_JACK_THR_MASK,
hpldet_cfg);
hpldet_cfg = 0;
if (hpldet_pdata->comp_inv)
hpldet_cfg |= DA7218_HPLDET_COMP_INV_MASK;
if (hpldet_pdata->hyst)
hpldet_cfg |= DA7218_HPLDET_HYST_EN_MASK;
if (hpldet_pdata->discharge)
hpldet_cfg |= DA7218_HPLDET_DISCHARGE_EN_MASK;
snd_soc_write(codec, DA7218_HPLDET_CTRL, hpldet_cfg);
}
}
}
static int da7218_probe(struct snd_soc_codec *codec)
{
struct da7218_priv *da7218 = snd_soc_codec_get_drvdata(codec);
int ret;
ret = da7218_handle_supplies(codec);
if (ret)
return ret;
if (codec->dev->of_node)
da7218->pdata = da7218_of_to_pdata(codec);
else
da7218->pdata = dev_get_platdata(codec->dev);
da7218_handle_pdata(codec);
da7218->mclk = devm_clk_get(codec->dev, "mclk");
if (IS_ERR(da7218->mclk)) {
if (PTR_ERR(da7218->mclk) != -ENOENT) {
ret = PTR_ERR(da7218->mclk);
goto err_disable_reg;
} else {
da7218->mclk = NULL;
}
}
snd_soc_write(codec, DA7218_PC_COUNT, DA7218_PC_FREERUN_MASK);
snd_soc_write(codec, DA7218_DROUTING_OUTFILT_1L, 0);
snd_soc_write(codec, DA7218_DROUTING_OUTFILT_1R, 0);
snd_soc_update_bits(codec, DA7218_CP_CTRL,
DA7218_CP_SMALL_SWITCH_FREQ_EN_MASK, 0);
snd_soc_update_bits(codec, DA7218_MIXIN_1_CTRL,
DA7218_MIXIN_1_AMP_RAMP_EN_MASK,
DA7218_MIXIN_1_AMP_RAMP_EN_MASK);
snd_soc_update_bits(codec, DA7218_MIXIN_2_CTRL,
DA7218_MIXIN_2_AMP_RAMP_EN_MASK,
DA7218_MIXIN_2_AMP_RAMP_EN_MASK);
snd_soc_update_bits(codec, DA7218_IN_1L_FILTER_CTRL,
DA7218_IN_1L_RAMP_EN_MASK,
DA7218_IN_1L_RAMP_EN_MASK);
snd_soc_update_bits(codec, DA7218_IN_1R_FILTER_CTRL,
DA7218_IN_1R_RAMP_EN_MASK,
DA7218_IN_1R_RAMP_EN_MASK);
snd_soc_update_bits(codec, DA7218_IN_2L_FILTER_CTRL,
DA7218_IN_2L_RAMP_EN_MASK,
DA7218_IN_2L_RAMP_EN_MASK);
snd_soc_update_bits(codec, DA7218_IN_2R_FILTER_CTRL,
DA7218_IN_2R_RAMP_EN_MASK,
DA7218_IN_2R_RAMP_EN_MASK);
snd_soc_update_bits(codec, DA7218_DGS_GAIN_CTRL,
DA7218_DGS_RAMP_EN_MASK, DA7218_DGS_RAMP_EN_MASK);
snd_soc_update_bits(codec, DA7218_OUT_1L_FILTER_CTRL,
DA7218_OUT_1L_RAMP_EN_MASK,
DA7218_OUT_1L_RAMP_EN_MASK);
snd_soc_update_bits(codec, DA7218_OUT_1R_FILTER_CTRL,
DA7218_OUT_1R_RAMP_EN_MASK,
DA7218_OUT_1R_RAMP_EN_MASK);
snd_soc_update_bits(codec, DA7218_HP_L_CTRL,
DA7218_HP_L_AMP_RAMP_EN_MASK,
DA7218_HP_L_AMP_RAMP_EN_MASK);
snd_soc_update_bits(codec, DA7218_HP_R_CTRL,
DA7218_HP_R_AMP_RAMP_EN_MASK,
DA7218_HP_R_AMP_RAMP_EN_MASK);
snd_soc_write(codec, DA7218_TONE_GEN_CYCLES, DA7218_BEEP_CYCLES_MASK);
if (da7218->dev_id == DA7217_DEV_ID) {
snd_soc_update_bits(codec, DA7218_HP_DIFF_CTRL,
DA7218_HP_AMP_DIFF_MODE_EN_MASK,
DA7218_HP_AMP_DIFF_MODE_EN_MASK);
snd_soc_write(codec, DA7218_EVENT_MASK,
DA7218_HPLDET_JACK_EVENT_IRQ_MSK_MASK);
}
if (da7218->irq) {
ret = devm_request_threaded_irq(codec->dev, da7218->irq, NULL,
da7218_irq_thread,
IRQF_TRIGGER_LOW | IRQF_ONESHOT,
"da7218", codec);
if (ret != 0) {
dev_err(codec->dev, "Failed to request IRQ %d: %d\n",
da7218->irq, ret);
goto err_disable_reg;
}
}
return 0;
err_disable_reg:
regulator_bulk_disable(DA7218_NUM_SUPPLIES, da7218->supplies);
return ret;
}
static int da7218_remove(struct snd_soc_codec *codec)
{
struct da7218_priv *da7218 = snd_soc_codec_get_drvdata(codec);
regulator_bulk_disable(DA7218_NUM_SUPPLIES, da7218->supplies);
return 0;
}
static int da7218_suspend(struct snd_soc_codec *codec)
{
struct da7218_priv *da7218 = snd_soc_codec_get_drvdata(codec);
da7218_set_bias_level(codec, SND_SOC_BIAS_OFF);
if (!da7218->jack)
snd_soc_write(codec, DA7218_SYSTEM_ACTIVE, 0);
return 0;
}
static int da7218_resume(struct snd_soc_codec *codec)
{
struct da7218_priv *da7218 = snd_soc_codec_get_drvdata(codec);
if (!da7218->jack)
snd_soc_write(codec, DA7218_SYSTEM_ACTIVE,
DA7218_SYSTEM_ACTIVE_MASK);
da7218_set_bias_level(codec, SND_SOC_BIAS_STANDBY);
return 0;
}
static bool da7218_volatile_register(struct device *dev, unsigned int reg)
{
switch (reg) {
case DA7218_STATUS1:
case DA7218_SOFT_RESET:
case DA7218_SYSTEM_STATUS:
case DA7218_CALIB_CTRL:
case DA7218_CALIB_OFFSET_AUTO_M_1:
case DA7218_CALIB_OFFSET_AUTO_U_1:
case DA7218_CALIB_OFFSET_AUTO_M_2:
case DA7218_CALIB_OFFSET_AUTO_U_2:
case DA7218_PLL_STATUS:
case DA7218_PLL_REFOSC_CAL:
case DA7218_TONE_GEN_CFG1:
case DA7218_ADC_MODE:
case DA7218_HP_SNGL_CTRL:
case DA7218_HPLDET_TEST:
case DA7218_EVENT_STATUS:
case DA7218_EVENT:
return true;
default:
return false;
}
}
static int da7218_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct da7218_priv *da7218;
int ret;
da7218 = devm_kzalloc(&i2c->dev, sizeof(struct da7218_priv),
GFP_KERNEL);
if (!da7218)
return -ENOMEM;
i2c_set_clientdata(i2c, da7218);
if (i2c->dev.of_node)
da7218->dev_id = da7218_of_get_id(&i2c->dev);
else
da7218->dev_id = id->driver_data;
if ((da7218->dev_id != DA7217_DEV_ID) &&
(da7218->dev_id != DA7218_DEV_ID)) {
dev_err(&i2c->dev, "Invalid device Id\n");
return -EINVAL;
}
da7218->irq = i2c->irq;
da7218->regmap = devm_regmap_init_i2c(i2c, &da7218_regmap_config);
if (IS_ERR(da7218->regmap)) {
ret = PTR_ERR(da7218->regmap);
dev_err(&i2c->dev, "regmap_init() failed: %d\n", ret);
return ret;
}
ret = snd_soc_register_codec(&i2c->dev,
&soc_codec_dev_da7218, &da7218_dai, 1);
if (ret < 0) {
dev_err(&i2c->dev, "Failed to register da7218 codec: %d\n",
ret);
}
return ret;
}
static int da7218_i2c_remove(struct i2c_client *client)
{
snd_soc_unregister_codec(&client->dev);
return 0;
}
