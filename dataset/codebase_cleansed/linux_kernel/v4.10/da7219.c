static int da7219_volsw_locked_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_soc_kcontrol_codec(kcontrol);
struct da7219_priv *da7219 = snd_soc_codec_get_drvdata(codec);
int ret;
mutex_lock(&da7219->lock);
ret = snd_soc_get_volsw(kcontrol, ucontrol);
mutex_unlock(&da7219->lock);
return ret;
}
static int da7219_volsw_locked_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_soc_kcontrol_codec(kcontrol);
struct da7219_priv *da7219 = snd_soc_codec_get_drvdata(codec);
int ret;
mutex_lock(&da7219->lock);
ret = snd_soc_put_volsw(kcontrol, ucontrol);
mutex_unlock(&da7219->lock);
return ret;
}
static int da7219_enum_locked_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_soc_kcontrol_codec(kcontrol);
struct da7219_priv *da7219 = snd_soc_codec_get_drvdata(codec);
int ret;
mutex_lock(&da7219->lock);
ret = snd_soc_get_enum_double(kcontrol, ucontrol);
mutex_unlock(&da7219->lock);
return ret;
}
static int da7219_enum_locked_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_soc_kcontrol_codec(kcontrol);
struct da7219_priv *da7219 = snd_soc_codec_get_drvdata(codec);
int ret;
mutex_lock(&da7219->lock);
ret = snd_soc_put_enum_double(kcontrol, ucontrol);
mutex_unlock(&da7219->lock);
return ret;
}
static void da7219_alc_calib(struct snd_soc_codec *codec)
{
u8 mic_ctrl, mixin_ctrl, adc_ctrl, calib_ctrl;
mic_ctrl = snd_soc_read(codec, DA7219_MIC_1_CTRL);
mixin_ctrl = snd_soc_read(codec, DA7219_MIXIN_L_CTRL);
adc_ctrl = snd_soc_read(codec, DA7219_ADC_L_CTRL);
snd_soc_update_bits(codec, DA7219_MIC_1_CTRL, DA7219_MIC_1_AMP_EN_MASK,
DA7219_MIC_1_AMP_EN_MASK);
snd_soc_update_bits(codec, DA7219_MIC_1_CTRL,
DA7219_MIC_1_AMP_MUTE_EN_MASK,
DA7219_MIC_1_AMP_MUTE_EN_MASK);
snd_soc_update_bits(codec, DA7219_MIXIN_L_CTRL,
DA7219_MIXIN_L_AMP_EN_MASK |
DA7219_MIXIN_L_AMP_MUTE_EN_MASK,
DA7219_MIXIN_L_AMP_EN_MASK);
snd_soc_update_bits(codec, DA7219_ADC_L_CTRL,
DA7219_ADC_L_MUTE_EN_MASK | DA7219_ADC_L_EN_MASK,
DA7219_ADC_L_EN_MASK);
snd_soc_update_bits(codec, DA7219_ALC_CTRL1,
DA7219_ALC_AUTO_CALIB_EN_MASK,
DA7219_ALC_AUTO_CALIB_EN_MASK);
do {
calib_ctrl = snd_soc_read(codec, DA7219_ALC_CTRL1);
} while (calib_ctrl & DA7219_ALC_AUTO_CALIB_EN_MASK);
if (calib_ctrl & DA7219_ALC_CALIB_OVERFLOW_MASK) {
dev_warn(codec->dev,
"ALC auto calibration failed with overflow\n");
snd_soc_update_bits(codec, DA7219_ALC_CTRL1,
DA7219_ALC_OFFSET_EN_MASK |
DA7219_ALC_SYNC_MODE_MASK, 0);
} else {
snd_soc_update_bits(codec, DA7219_ALC_CTRL1,
DA7219_ALC_OFFSET_EN_MASK |
DA7219_ALC_SYNC_MODE_MASK,
DA7219_ALC_OFFSET_EN_MASK |
DA7219_ALC_SYNC_MODE_MASK);
}
snd_soc_write(codec, DA7219_ADC_L_CTRL, adc_ctrl);
snd_soc_write(codec, DA7219_MIXIN_L_CTRL, mixin_ctrl);
snd_soc_write(codec, DA7219_MIC_1_CTRL, mic_ctrl);
}
static int da7219_mixin_gain_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_soc_kcontrol_codec(kcontrol);
struct da7219_priv *da7219 = snd_soc_codec_get_drvdata(codec);
int ret;
ret = snd_soc_put_volsw(kcontrol, ucontrol);
if ((ret == 1) && (da7219->alc_en))
da7219_alc_calib(codec);
return ret;
}
static int da7219_alc_sw_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_soc_kcontrol_codec(kcontrol);
struct da7219_priv *da7219 = snd_soc_codec_get_drvdata(codec);
if ((ucontrol->value.integer.value[0]) && (!da7219->alc_en)) {
da7219_alc_calib(codec);
da7219->alc_en = true;
} else {
da7219->alc_en = false;
}
return snd_soc_put_volsw(kcontrol, ucontrol);
}
static int da7219_tonegen_freq_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_soc_kcontrol_codec(kcontrol);
struct da7219_priv *da7219 = snd_soc_codec_get_drvdata(codec);
struct soc_mixer_control *mixer_ctrl =
(struct soc_mixer_control *) kcontrol->private_value;
unsigned int reg = mixer_ctrl->reg;
u16 val;
int ret;
mutex_lock(&da7219->lock);
ret = regmap_raw_read(da7219->regmap, reg, &val, sizeof(val));
mutex_unlock(&da7219->lock);
if (ret)
return ret;
ucontrol->value.integer.value[0] = le16_to_cpu(val);
return 0;
}
static int da7219_tonegen_freq_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_soc_kcontrol_codec(kcontrol);
struct da7219_priv *da7219 = snd_soc_codec_get_drvdata(codec);
struct soc_mixer_control *mixer_ctrl =
(struct soc_mixer_control *) kcontrol->private_value;
unsigned int reg = mixer_ctrl->reg;
u16 val;
int ret;
val = cpu_to_le16(ucontrol->value.integer.value[0]);
mutex_lock(&da7219->lock);
ret = regmap_raw_write(da7219->regmap, reg, &val, sizeof(val));
mutex_unlock(&da7219->lock);
return ret;
}
static int da7219_dai_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
struct da7219_priv *da7219 = snd_soc_codec_get_drvdata(codec);
u8 pll_ctrl, pll_status;
int i = 0;
bool srm_lock = false;
switch (event) {
case SND_SOC_DAPM_PRE_PMU:
if (da7219->master)
snd_soc_update_bits(codec, DA7219_DAI_CLK_MODE,
DA7219_DAI_CLK_EN_MASK,
DA7219_DAI_CLK_EN_MASK);
snd_soc_update_bits(codec, DA7219_PC_COUNT,
DA7219_PC_FREERUN_MASK, 0);
pll_ctrl = snd_soc_read(codec, DA7219_PLL_CTRL);
if ((pll_ctrl & DA7219_PLL_MODE_MASK) != DA7219_PLL_MODE_SRM)
return 0;
do {
pll_status = snd_soc_read(codec, DA7219_PLL_SRM_STS);
if (pll_status & DA7219_PLL_SRM_STS_SRM_LOCK) {
srm_lock = true;
} else {
++i;
msleep(50);
}
} while ((i < DA7219_SRM_CHECK_RETRIES) && (!srm_lock));
if (!srm_lock)
dev_warn(codec->dev, "SRM failed to lock\n");
return 0;
case SND_SOC_DAPM_POST_PMD:
snd_soc_update_bits(codec, DA7219_PC_COUNT,
DA7219_PC_FREERUN_MASK,
DA7219_PC_FREERUN_MASK);
if (da7219->master)
snd_soc_update_bits(codec, DA7219_DAI_CLK_MODE,
DA7219_DAI_CLK_EN_MASK, 0);
return 0;
default:
return -EINVAL;
}
}
static int da7219_settling_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
switch (event) {
case SND_SOC_DAPM_POST_PMU:
case SND_SOC_DAPM_POST_PMD:
msleep(DA7219_SETTLING_DELAY);
break;
default:
break;
}
return 0;
}
static int da7219_mixout_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
u8 hp_ctrl, min_gain_mask;
switch (w->reg) {
case DA7219_MIXOUT_L_CTRL:
hp_ctrl = DA7219_HP_L_CTRL;
min_gain_mask = DA7219_HP_L_AMP_MIN_GAIN_EN_MASK;
break;
case DA7219_MIXOUT_R_CTRL:
hp_ctrl = DA7219_HP_R_CTRL;
min_gain_mask = DA7219_HP_R_AMP_MIN_GAIN_EN_MASK;
break;
default:
return -EINVAL;
}
switch (event) {
case SND_SOC_DAPM_PRE_PMD:
snd_soc_update_bits(codec, hp_ctrl, min_gain_mask,
min_gain_mask);
msleep(DA7219_MIN_GAIN_DELAY);
break;
case SND_SOC_DAPM_POST_PMU:
snd_soc_update_bits(codec, hp_ctrl, min_gain_mask, 0);
break;
}
return 0;
}
static int da7219_gain_ramp_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
struct da7219_priv *da7219 = snd_soc_codec_get_drvdata(codec);
switch (event) {
case SND_SOC_DAPM_PRE_PMU:
case SND_SOC_DAPM_PRE_PMD:
da7219->gain_ramp_ctrl =
snd_soc_read(codec, DA7219_GAIN_RAMP_CTRL);
snd_soc_write(codec, DA7219_GAIN_RAMP_CTRL,
DA7219_GAIN_RAMP_RATE_NOMINAL);
break;
case SND_SOC_DAPM_POST_PMU:
case SND_SOC_DAPM_POST_PMD:
snd_soc_write(codec, DA7219_GAIN_RAMP_CTRL,
da7219->gain_ramp_ctrl);
break;
}
return 0;
}
static int da7219_set_dai_sysclk(struct snd_soc_dai *codec_dai,
int clk_id, unsigned int freq, int dir)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct da7219_priv *da7219 = snd_soc_codec_get_drvdata(codec);
int ret = 0;
if ((da7219->clk_src == clk_id) && (da7219->mclk_rate == freq))
return 0;
if ((freq < 2000000) || (freq > 54000000)) {
dev_err(codec_dai->dev, "Unsupported MCLK value %d\n",
freq);
return -EINVAL;
}
switch (clk_id) {
case DA7219_CLKSRC_MCLK_SQR:
snd_soc_update_bits(codec, DA7219_PLL_CTRL,
DA7219_PLL_MCLK_SQR_EN_MASK,
DA7219_PLL_MCLK_SQR_EN_MASK);
break;
case DA7219_CLKSRC_MCLK:
snd_soc_update_bits(codec, DA7219_PLL_CTRL,
DA7219_PLL_MCLK_SQR_EN_MASK, 0);
break;
default:
dev_err(codec_dai->dev, "Unknown clock source %d\n", clk_id);
return -EINVAL;
}
da7219->clk_src = clk_id;
if (da7219->mclk) {
freq = clk_round_rate(da7219->mclk, freq);
ret = clk_set_rate(da7219->mclk, freq);
if (ret) {
dev_err(codec_dai->dev, "Failed to set clock rate %d\n",
freq);
return ret;
}
}
da7219->mclk_rate = freq;
return 0;
}
static int da7219_set_dai_pll(struct snd_soc_dai *codec_dai, int pll_id,
int source, unsigned int fref, unsigned int fout)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct da7219_priv *da7219 = snd_soc_codec_get_drvdata(codec);
u8 pll_ctrl, indiv_bits, indiv;
u8 pll_frac_top, pll_frac_bot, pll_integer;
u32 freq_ref;
u64 frac_div;
if (da7219->mclk_rate < 2000000) {
dev_err(codec->dev, "PLL input clock %d below valid range\n",
da7219->mclk_rate);
return -EINVAL;
} else if (da7219->mclk_rate <= 4500000) {
indiv_bits = DA7219_PLL_INDIV_2_TO_4_5_MHZ;
indiv = DA7219_PLL_INDIV_2_TO_4_5_MHZ_VAL;
} else if (da7219->mclk_rate <= 9000000) {
indiv_bits = DA7219_PLL_INDIV_4_5_TO_9_MHZ;
indiv = DA7219_PLL_INDIV_4_5_TO_9_MHZ_VAL;
} else if (da7219->mclk_rate <= 18000000) {
indiv_bits = DA7219_PLL_INDIV_9_TO_18_MHZ;
indiv = DA7219_PLL_INDIV_9_TO_18_MHZ_VAL;
} else if (da7219->mclk_rate <= 36000000) {
indiv_bits = DA7219_PLL_INDIV_18_TO_36_MHZ;
indiv = DA7219_PLL_INDIV_18_TO_36_MHZ_VAL;
} else if (da7219->mclk_rate <= 54000000) {
indiv_bits = DA7219_PLL_INDIV_36_TO_54_MHZ;
indiv = DA7219_PLL_INDIV_36_TO_54_MHZ_VAL;
} else {
dev_err(codec->dev, "PLL input clock %d above valid range\n",
da7219->mclk_rate);
return -EINVAL;
}
freq_ref = (da7219->mclk_rate / indiv);
pll_ctrl = indiv_bits;
switch (source) {
case DA7219_SYSCLK_MCLK:
pll_ctrl |= DA7219_PLL_MODE_BYPASS;
snd_soc_update_bits(codec, DA7219_PLL_CTRL,
DA7219_PLL_INDIV_MASK |
DA7219_PLL_MODE_MASK, pll_ctrl);
return 0;
case DA7219_SYSCLK_PLL:
pll_ctrl |= DA7219_PLL_MODE_NORMAL;
break;
case DA7219_SYSCLK_PLL_SRM:
pll_ctrl |= DA7219_PLL_MODE_SRM;
break;
default:
dev_err(codec->dev, "Invalid PLL config\n");
return -EINVAL;
}
pll_integer = fout / freq_ref;
frac_div = (u64)(fout % freq_ref) * 8192ULL;
do_div(frac_div, freq_ref);
pll_frac_top = (frac_div >> DA7219_BYTE_SHIFT) & DA7219_BYTE_MASK;
pll_frac_bot = (frac_div) & DA7219_BYTE_MASK;
snd_soc_write(codec, DA7219_PLL_FRAC_TOP, pll_frac_top);
snd_soc_write(codec, DA7219_PLL_FRAC_BOT, pll_frac_bot);
snd_soc_write(codec, DA7219_PLL_INTEGER, pll_integer);
snd_soc_update_bits(codec, DA7219_PLL_CTRL,
DA7219_PLL_INDIV_MASK | DA7219_PLL_MODE_MASK,
pll_ctrl);
return 0;
}
static int da7219_set_dai_fmt(struct snd_soc_dai *codec_dai, unsigned int fmt)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct da7219_priv *da7219 = snd_soc_codec_get_drvdata(codec);
u8 dai_clk_mode = 0, dai_ctrl = 0;
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBM_CFM:
da7219->master = true;
break;
case SND_SOC_DAIFMT_CBS_CFS:
da7219->master = false;
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
dai_clk_mode |= DA7219_DAI_WCLK_POL_INV;
break;
case SND_SOC_DAIFMT_IB_NF:
dai_clk_mode |= DA7219_DAI_CLK_POL_INV;
break;
case SND_SOC_DAIFMT_IB_IF:
dai_clk_mode |= DA7219_DAI_WCLK_POL_INV |
DA7219_DAI_CLK_POL_INV;
break;
default:
return -EINVAL;
}
break;
case SND_SOC_DAIFMT_DSP_B:
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
dai_clk_mode |= DA7219_DAI_CLK_POL_INV;
break;
case SND_SOC_DAIFMT_NB_IF:
dai_clk_mode |= DA7219_DAI_WCLK_POL_INV |
DA7219_DAI_CLK_POL_INV;
break;
case SND_SOC_DAIFMT_IB_NF:
break;
case SND_SOC_DAIFMT_IB_IF:
dai_clk_mode |= DA7219_DAI_WCLK_POL_INV;
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
dai_ctrl |= DA7219_DAI_FORMAT_I2S;
break;
case SND_SOC_DAIFMT_LEFT_J:
dai_ctrl |= DA7219_DAI_FORMAT_LEFT_J;
break;
case SND_SOC_DAIFMT_RIGHT_J:
dai_ctrl |= DA7219_DAI_FORMAT_RIGHT_J;
break;
case SND_SOC_DAIFMT_DSP_B:
dai_ctrl |= DA7219_DAI_FORMAT_DSP;
break;
default:
return -EINVAL;
}
dai_clk_mode |= DA7219_DAI_BCLKS_PER_WCLK_64;
snd_soc_update_bits(codec, DA7219_DAI_CLK_MODE,
DA7219_DAI_BCLKS_PER_WCLK_MASK |
DA7219_DAI_CLK_POL_MASK | DA7219_DAI_WCLK_POL_MASK,
dai_clk_mode);
snd_soc_update_bits(codec, DA7219_DAI_CTRL, DA7219_DAI_FORMAT_MASK,
dai_ctrl);
return 0;
}
static int da7219_set_dai_tdm_slot(struct snd_soc_dai *dai,
unsigned int tx_mask, unsigned int rx_mask,
int slots, int slot_width)
{
struct snd_soc_codec *codec = dai->codec;
struct da7219_priv *da7219 = snd_soc_codec_get_drvdata(codec);
u8 dai_bclks_per_wclk;
u16 offset;
u32 frame_size;
if (!tx_mask) {
snd_soc_update_bits(codec, DA7219_DAI_TDM_CTRL,
DA7219_DAI_TDM_CH_EN_MASK |
DA7219_DAI_TDM_MODE_EN_MASK, 0);
snd_soc_update_bits(codec, DA7219_DAI_CLK_MODE,
DA7219_DAI_BCLKS_PER_WCLK_MASK,
DA7219_DAI_BCLKS_PER_WCLK_64);
return 0;
}
if (fls(tx_mask) > DA7219_DAI_TDM_MAX_SLOTS) {
dev_err(codec->dev, "Invalid number of slots, max = %d\n",
DA7219_DAI_TDM_MAX_SLOTS);
return -EINVAL;
}
if (rx_mask > DA7219_DAI_OFFSET_MAX) {
dev_err(codec->dev, "Invalid slot offset, max = %d\n",
DA7219_DAI_OFFSET_MAX);
return -EINVAL;
}
frame_size = slots * slot_width;
switch (frame_size) {
case 32:
dai_bclks_per_wclk = DA7219_DAI_BCLKS_PER_WCLK_32;
break;
case 64:
dai_bclks_per_wclk = DA7219_DAI_BCLKS_PER_WCLK_64;
break;
case 128:
dai_bclks_per_wclk = DA7219_DAI_BCLKS_PER_WCLK_128;
break;
case 256:
dai_bclks_per_wclk = DA7219_DAI_BCLKS_PER_WCLK_256;
break;
default:
dev_err(codec->dev, "Invalid frame size %d\n", frame_size);
return -EINVAL;
}
snd_soc_update_bits(codec, DA7219_DAI_CLK_MODE,
DA7219_DAI_BCLKS_PER_WCLK_MASK,
dai_bclks_per_wclk);
offset = cpu_to_le16(rx_mask);
regmap_bulk_write(da7219->regmap, DA7219_DAI_OFFSET_LOWER,
&offset, sizeof(offset));
snd_soc_update_bits(codec, DA7219_DAI_TDM_CTRL,
DA7219_DAI_TDM_CH_EN_MASK |
DA7219_DAI_TDM_MODE_EN_MASK,
(tx_mask << DA7219_DAI_TDM_CH_EN_SHIFT) |
DA7219_DAI_TDM_MODE_EN_MASK);
return 0;
}
static int da7219_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
u8 dai_ctrl = 0, fs;
unsigned int channels;
switch (params_width(params)) {
case 16:
dai_ctrl |= DA7219_DAI_WORD_LENGTH_S16_LE;
break;
case 20:
dai_ctrl |= DA7219_DAI_WORD_LENGTH_S20_LE;
break;
case 24:
dai_ctrl |= DA7219_DAI_WORD_LENGTH_S24_LE;
break;
case 32:
dai_ctrl |= DA7219_DAI_WORD_LENGTH_S32_LE;
break;
default:
return -EINVAL;
}
channels = params_channels(params);
if ((channels < 1) || (channels > DA7219_DAI_CH_NUM_MAX)) {
dev_err(codec->dev,
"Invalid number of channels, only 1 to %d supported\n",
DA7219_DAI_CH_NUM_MAX);
return -EINVAL;
}
dai_ctrl |= channels << DA7219_DAI_CH_NUM_SHIFT;
switch (params_rate(params)) {
case 8000:
fs = DA7219_SR_8000;
break;
case 11025:
fs = DA7219_SR_11025;
break;
case 12000:
fs = DA7219_SR_12000;
break;
case 16000:
fs = DA7219_SR_16000;
break;
case 22050:
fs = DA7219_SR_22050;
break;
case 24000:
fs = DA7219_SR_24000;
break;
case 32000:
fs = DA7219_SR_32000;
break;
case 44100:
fs = DA7219_SR_44100;
break;
case 48000:
fs = DA7219_SR_48000;
break;
case 88200:
fs = DA7219_SR_88200;
break;
case 96000:
fs = DA7219_SR_96000;
break;
default:
return -EINVAL;
}
snd_soc_update_bits(codec, DA7219_DAI_CTRL,
DA7219_DAI_WORD_LENGTH_MASK |
DA7219_DAI_CH_NUM_MASK,
dai_ctrl);
snd_soc_write(codec, DA7219_SR, fs);
return 0;
}
static enum da7219_micbias_voltage
da7219_fw_micbias_lvl(struct device *dev, u32 val)
{
switch (val) {
case 1600:
return DA7219_MICBIAS_1_6V;
case 1800:
return DA7219_MICBIAS_1_8V;
case 2000:
return DA7219_MICBIAS_2_0V;
case 2200:
return DA7219_MICBIAS_2_2V;
case 2400:
return DA7219_MICBIAS_2_4V;
case 2600:
return DA7219_MICBIAS_2_6V;
default:
dev_warn(dev, "Invalid micbias level");
return DA7219_MICBIAS_2_2V;
}
}
static enum da7219_mic_amp_in_sel
da7219_fw_mic_amp_in_sel(struct device *dev, const char *str)
{
if (!strcmp(str, "diff")) {
return DA7219_MIC_AMP_IN_SEL_DIFF;
} else if (!strcmp(str, "se_p")) {
return DA7219_MIC_AMP_IN_SEL_SE_P;
} else if (!strcmp(str, "se_n")) {
return DA7219_MIC_AMP_IN_SEL_SE_N;
} else {
dev_warn(dev, "Invalid mic input type selection");
return DA7219_MIC_AMP_IN_SEL_DIFF;
}
}
static struct da7219_pdata *da7219_fw_to_pdata(struct snd_soc_codec *codec)
{
struct device *dev = codec->dev;
struct da7219_pdata *pdata;
const char *of_str;
u32 of_val32;
pdata = devm_kzalloc(dev, sizeof(*pdata), GFP_KERNEL);
if (!pdata)
return NULL;
pdata->wakeup_source = device_property_read_bool(dev, "wakeup-source");
if (device_property_read_u32(dev, "dlg,micbias-lvl", &of_val32) >= 0)
pdata->micbias_lvl = da7219_fw_micbias_lvl(dev, of_val32);
else
pdata->micbias_lvl = DA7219_MICBIAS_2_2V;
if (!device_property_read_string(dev, "dlg,mic-amp-in-sel", &of_str))
pdata->mic_amp_in_sel = da7219_fw_mic_amp_in_sel(dev, of_str);
else
pdata->mic_amp_in_sel = DA7219_MIC_AMP_IN_SEL_DIFF;
return pdata;
}
static int da7219_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
struct da7219_priv *da7219 = snd_soc_codec_get_drvdata(codec);
int ret;
switch (level) {
case SND_SOC_BIAS_ON:
break;
case SND_SOC_BIAS_PREPARE:
if (snd_soc_codec_get_bias_level(codec) == SND_SOC_BIAS_STANDBY) {
if (da7219->mclk) {
ret = clk_prepare_enable(da7219->mclk);
if (ret) {
dev_err(codec->dev,
"Failed to enable mclk\n");
return ret;
}
}
}
break;
case SND_SOC_BIAS_STANDBY:
if (snd_soc_codec_get_bias_level(codec) == SND_SOC_BIAS_OFF)
snd_soc_update_bits(codec, DA7219_REFERENCES,
DA7219_BIAS_EN_MASK,
DA7219_BIAS_EN_MASK);
if (snd_soc_codec_get_bias_level(codec) == SND_SOC_BIAS_PREPARE) {
if (da7219->mclk)
clk_disable_unprepare(da7219->mclk);
}
break;
case SND_SOC_BIAS_OFF:
if (!da7219->wakeup_source)
snd_soc_update_bits(codec, DA7219_REFERENCES,
DA7219_BIAS_EN_MASK, 0);
break;
}
return 0;
}
static int da7219_handle_supplies(struct snd_soc_codec *codec)
{
struct da7219_priv *da7219 = snd_soc_codec_get_drvdata(codec);
struct regulator *vddio;
u8 io_voltage_lvl = DA7219_IO_VOLTAGE_LEVEL_2_5V_3_6V;
int i, ret;
for (i = 0; i < DA7219_NUM_SUPPLIES; ++i)
da7219->supplies[i].supply = da7219_supply_names[i];
ret = devm_regulator_bulk_get(codec->dev, DA7219_NUM_SUPPLIES,
da7219->supplies);
if (ret) {
dev_err(codec->dev, "Failed to get supplies");
return ret;
}
vddio = da7219->supplies[DA7219_SUPPLY_VDDIO].consumer;
ret = regulator_get_voltage(vddio);
if (ret < 1200000)
dev_warn(codec->dev, "Invalid VDDIO voltage\n");
else if (ret < 2800000)
io_voltage_lvl = DA7219_IO_VOLTAGE_LEVEL_1_2V_2_8V;
ret = regulator_bulk_enable(DA7219_NUM_SUPPLIES, da7219->supplies);
if (ret) {
dev_err(codec->dev, "Failed to enable supplies");
return ret;
}
snd_soc_write(codec, DA7219_SYSTEM_ACTIVE, DA7219_SYSTEM_ACTIVE_MASK);
snd_soc_write(codec, DA7219_IO_CTRL, io_voltage_lvl);
return 0;
}
static void da7219_handle_pdata(struct snd_soc_codec *codec)
{
struct da7219_priv *da7219 = snd_soc_codec_get_drvdata(codec);
struct da7219_pdata *pdata = da7219->pdata;
if (pdata) {
u8 micbias_lvl = 0;
da7219->wakeup_source = pdata->wakeup_source;
switch (pdata->micbias_lvl) {
case DA7219_MICBIAS_1_6V:
case DA7219_MICBIAS_1_8V:
case DA7219_MICBIAS_2_0V:
case DA7219_MICBIAS_2_2V:
case DA7219_MICBIAS_2_4V:
case DA7219_MICBIAS_2_6V:
micbias_lvl |= (pdata->micbias_lvl <<
DA7219_MICBIAS1_LEVEL_SHIFT);
break;
}
snd_soc_write(codec, DA7219_MICBIAS_CTRL, micbias_lvl);
switch (pdata->mic_amp_in_sel) {
case DA7219_MIC_AMP_IN_SEL_DIFF:
case DA7219_MIC_AMP_IN_SEL_SE_P:
case DA7219_MIC_AMP_IN_SEL_SE_N:
snd_soc_write(codec, DA7219_MIC_1_SELECT,
pdata->mic_amp_in_sel);
break;
}
}
}
static int da7219_probe(struct snd_soc_codec *codec)
{
struct da7219_priv *da7219 = snd_soc_codec_get_drvdata(codec);
unsigned int rev;
int ret;
mutex_init(&da7219->lock);
ret = da7219_handle_supplies(codec);
if (ret)
return ret;
ret = regmap_read(da7219->regmap, DA7219_CHIP_REVISION, &rev);
if (ret) {
dev_err(codec->dev, "Failed to read chip revision: %d\n", ret);
goto err_disable_reg;
}
switch (rev & DA7219_CHIP_MINOR_MASK) {
case 0:
ret = regmap_register_patch(da7219->regmap, da7219_rev_aa_patch,
ARRAY_SIZE(da7219_rev_aa_patch));
if (ret) {
dev_err(codec->dev, "Failed to register AA patch: %d\n",
ret);
goto err_disable_reg;
}
break;
default:
break;
}
da7219->pdata = dev_get_platdata(codec->dev);
if (!da7219->pdata)
da7219->pdata = da7219_fw_to_pdata(codec);
da7219_handle_pdata(codec);
da7219->mclk = devm_clk_get(codec->dev, "mclk");
if (IS_ERR(da7219->mclk)) {
if (PTR_ERR(da7219->mclk) != -ENOENT) {
ret = PTR_ERR(da7219->mclk);
goto err_disable_reg;
} else {
da7219->mclk = NULL;
}
}
snd_soc_update_bits(codec, DA7219_PC_COUNT, DA7219_PC_FREERUN_MASK,
DA7219_PC_FREERUN_MASK);
snd_soc_update_bits(codec, DA7219_MIXIN_L_CTRL,
DA7219_MIXIN_L_AMP_RAMP_EN_MASK,
DA7219_MIXIN_L_AMP_RAMP_EN_MASK);
snd_soc_update_bits(codec, DA7219_ADC_L_CTRL, DA7219_ADC_L_RAMP_EN_MASK,
DA7219_ADC_L_RAMP_EN_MASK);
snd_soc_update_bits(codec, DA7219_DAC_L_CTRL, DA7219_DAC_L_RAMP_EN_MASK,
DA7219_DAC_L_RAMP_EN_MASK);
snd_soc_update_bits(codec, DA7219_DAC_R_CTRL, DA7219_DAC_R_RAMP_EN_MASK,
DA7219_DAC_R_RAMP_EN_MASK);
snd_soc_update_bits(codec, DA7219_HP_L_CTRL,
DA7219_HP_L_AMP_RAMP_EN_MASK,
DA7219_HP_L_AMP_RAMP_EN_MASK);
snd_soc_update_bits(codec, DA7219_HP_R_CTRL,
DA7219_HP_R_AMP_RAMP_EN_MASK,
DA7219_HP_R_AMP_RAMP_EN_MASK);
snd_soc_update_bits(codec, DA7219_HP_L_CTRL,
DA7219_HP_L_AMP_MIN_GAIN_EN_MASK,
DA7219_HP_L_AMP_MIN_GAIN_EN_MASK);
snd_soc_update_bits(codec, DA7219_HP_R_CTRL,
DA7219_HP_R_AMP_MIN_GAIN_EN_MASK,
DA7219_HP_R_AMP_MIN_GAIN_EN_MASK);
snd_soc_write(codec, DA7219_TONE_GEN_CYCLES, DA7219_BEEP_CYCLES_MASK);
ret = da7219_aad_init(codec);
if (ret)
goto err_disable_reg;
return 0;
err_disable_reg:
regulator_bulk_disable(DA7219_NUM_SUPPLIES, da7219->supplies);
return ret;
}
static int da7219_remove(struct snd_soc_codec *codec)
{
struct da7219_priv *da7219 = snd_soc_codec_get_drvdata(codec);
da7219_aad_exit(codec);
return regulator_bulk_disable(DA7219_NUM_SUPPLIES, da7219->supplies);
}
static int da7219_suspend(struct snd_soc_codec *codec)
{
struct da7219_priv *da7219 = snd_soc_codec_get_drvdata(codec);
if (!da7219->wakeup_source)
da7219_aad_suspend(codec);
snd_soc_codec_force_bias_level(codec, SND_SOC_BIAS_OFF);
return 0;
}
static int da7219_resume(struct snd_soc_codec *codec)
{
struct da7219_priv *da7219 = snd_soc_codec_get_drvdata(codec);
snd_soc_codec_force_bias_level(codec, SND_SOC_BIAS_STANDBY);
if (!da7219->wakeup_source)
da7219_aad_resume(codec);
return 0;
}
static bool da7219_volatile_register(struct device *dev, unsigned int reg)
{
switch (reg) {
case DA7219_MIC_1_GAIN_STATUS:
case DA7219_MIXIN_L_GAIN_STATUS:
case DA7219_ADC_L_GAIN_STATUS:
case DA7219_DAC_L_GAIN_STATUS:
case DA7219_DAC_R_GAIN_STATUS:
case DA7219_HP_L_GAIN_STATUS:
case DA7219_HP_R_GAIN_STATUS:
case DA7219_CIF_CTRL:
case DA7219_PLL_SRM_STS:
case DA7219_ALC_CTRL1:
case DA7219_SYSTEM_MODES_INPUT:
case DA7219_SYSTEM_MODES_OUTPUT:
case DA7219_ALC_OFFSET_AUTO_M_L:
case DA7219_ALC_OFFSET_AUTO_U_L:
case DA7219_TONE_GEN_CFG1:
case DA7219_ACCDET_STATUS_A:
case DA7219_ACCDET_STATUS_B:
case DA7219_ACCDET_IRQ_EVENT_A:
case DA7219_ACCDET_IRQ_EVENT_B:
case DA7219_ACCDET_CONFIG_8:
case DA7219_SYSTEM_STATUS:
return 1;
default:
return 0;
}
}
static int da7219_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct da7219_priv *da7219;
unsigned int system_active, system_status;
int i, ret;
da7219 = devm_kzalloc(&i2c->dev, sizeof(struct da7219_priv),
GFP_KERNEL);
if (!da7219)
return -ENOMEM;
i2c_set_clientdata(i2c, da7219);
da7219->regmap = devm_regmap_init_i2c(i2c, &da7219_regmap_config);
if (IS_ERR(da7219->regmap)) {
ret = PTR_ERR(da7219->regmap);
dev_err(&i2c->dev, "regmap_init() failed: %d\n", ret);
return ret;
}
regcache_cache_bypass(da7219->regmap, true);
regmap_read(da7219->regmap, DA7219_SYSTEM_ACTIVE, &system_active);
if (system_active) {
regmap_write(da7219->regmap, DA7219_GAIN_RAMP_CTRL,
DA7219_GAIN_RAMP_RATE_NOMINAL);
regmap_write(da7219->regmap, DA7219_SYSTEM_MODES_INPUT, 0x00);
regmap_write(da7219->regmap, DA7219_SYSTEM_MODES_OUTPUT, 0x01);
for (i = 0; i < DA7219_SYS_STAT_CHECK_RETRIES; ++i) {
regmap_read(da7219->regmap, DA7219_SYSTEM_STATUS,
&system_status);
if (!system_status)
break;
msleep(DA7219_SYS_STAT_CHECK_DELAY);
}
}
regmap_write_bits(da7219->regmap, DA7219_ACCDET_CONFIG_1,
DA7219_ACCDET_EN_MASK, 0);
regmap_write_bits(da7219->regmap, DA7219_CIF_CTRL,
DA7219_CIF_REG_SOFT_RESET_MASK,
DA7219_CIF_REG_SOFT_RESET_MASK);
regmap_write_bits(da7219->regmap, DA7219_SYSTEM_ACTIVE,
DA7219_SYSTEM_ACTIVE_MASK, 0);
regcache_cache_bypass(da7219->regmap, false);
ret = snd_soc_register_codec(&i2c->dev, &soc_codec_dev_da7219,
&da7219_dai, 1);
if (ret < 0) {
dev_err(&i2c->dev, "Failed to register da7219 codec: %d\n",
ret);
}
return ret;
}
static int da7219_i2c_remove(struct i2c_client *client)
{
snd_soc_unregister_codec(&client->dev);
return 0;
}
