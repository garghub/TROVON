static bool max98090_volatile_register(struct device *dev, unsigned int reg)
{
switch (reg) {
case M98090_REG_SOFTWARE_RESET:
case M98090_REG_DEVICE_STATUS:
case M98090_REG_JACK_STATUS:
case M98090_REG_REVISION_ID:
return true;
default:
return false;
}
}
static bool max98090_readable_register(struct device *dev, unsigned int reg)
{
switch (reg) {
case M98090_REG_DEVICE_STATUS:
case M98090_REG_JACK_STATUS:
case M98090_REG_INTERRUPT_S:
case M98090_REG_RESERVED:
case M98090_REG_LINE_INPUT_CONFIG:
case M98090_REG_LINE_INPUT_LEVEL:
case M98090_REG_INPUT_MODE:
case M98090_REG_MIC1_INPUT_LEVEL:
case M98090_REG_MIC2_INPUT_LEVEL:
case M98090_REG_MIC_BIAS_VOLTAGE:
case M98090_REG_DIGITAL_MIC_ENABLE:
case M98090_REG_DIGITAL_MIC_CONFIG:
case M98090_REG_LEFT_ADC_MIXER:
case M98090_REG_RIGHT_ADC_MIXER:
case M98090_REG_LEFT_ADC_LEVEL:
case M98090_REG_RIGHT_ADC_LEVEL:
case M98090_REG_ADC_BIQUAD_LEVEL:
case M98090_REG_ADC_SIDETONE:
case M98090_REG_SYSTEM_CLOCK:
case M98090_REG_CLOCK_MODE:
case M98090_REG_CLOCK_RATIO_NI_MSB:
case M98090_REG_CLOCK_RATIO_NI_LSB:
case M98090_REG_CLOCK_RATIO_MI_MSB:
case M98090_REG_CLOCK_RATIO_MI_LSB:
case M98090_REG_MASTER_MODE:
case M98090_REG_INTERFACE_FORMAT:
case M98090_REG_TDM_CONTROL:
case M98090_REG_TDM_FORMAT:
case M98090_REG_IO_CONFIGURATION:
case M98090_REG_FILTER_CONFIG:
case M98090_REG_DAI_PLAYBACK_LEVEL:
case M98090_REG_DAI_PLAYBACK_LEVEL_EQ:
case M98090_REG_LEFT_HP_MIXER:
case M98090_REG_RIGHT_HP_MIXER:
case M98090_REG_HP_CONTROL:
case M98090_REG_LEFT_HP_VOLUME:
case M98090_REG_RIGHT_HP_VOLUME:
case M98090_REG_LEFT_SPK_MIXER:
case M98090_REG_RIGHT_SPK_MIXER:
case M98090_REG_SPK_CONTROL:
case M98090_REG_LEFT_SPK_VOLUME:
case M98090_REG_RIGHT_SPK_VOLUME:
case M98090_REG_DRC_TIMING:
case M98090_REG_DRC_COMPRESSOR:
case M98090_REG_DRC_EXPANDER:
case M98090_REG_DRC_GAIN:
case M98090_REG_RCV_LOUTL_MIXER:
case M98090_REG_RCV_LOUTL_CONTROL:
case M98090_REG_RCV_LOUTL_VOLUME:
case M98090_REG_LOUTR_MIXER:
case M98090_REG_LOUTR_CONTROL:
case M98090_REG_LOUTR_VOLUME:
case M98090_REG_JACK_DETECT:
case M98090_REG_INPUT_ENABLE:
case M98090_REG_OUTPUT_ENABLE:
case M98090_REG_LEVEL_CONTROL:
case M98090_REG_DSP_FILTER_ENABLE:
case M98090_REG_BIAS_CONTROL:
case M98090_REG_DAC_CONTROL:
case M98090_REG_ADC_CONTROL:
case M98090_REG_DEVICE_SHUTDOWN:
case M98090_REG_EQUALIZER_BASE ... M98090_REG_EQUALIZER_BASE + 0x68:
case M98090_REG_RECORD_BIQUAD_BASE ... M98090_REG_RECORD_BIQUAD_BASE + 0x0E:
case M98090_REG_DMIC3_VOLUME:
case M98090_REG_DMIC4_VOLUME:
case M98090_REG_DMIC34_BQ_PREATTEN:
case M98090_REG_RECORD_TDM_SLOT:
case M98090_REG_SAMPLE_RATE:
case M98090_REG_DMIC34_BIQUAD_BASE ... M98090_REG_DMIC34_BIQUAD_BASE + 0x0E:
case M98090_REG_REVISION_ID:
return true;
default:
return false;
}
}
static int max98090_reset(struct max98090_priv *max98090)
{
int ret;
ret = regmap_write(max98090->regmap, M98090_REG_SOFTWARE_RESET,
M98090_SWRESET_MASK);
if (ret < 0) {
dev_err(max98090->codec->dev,
"Failed to reset codec: %d\n", ret);
return ret;
}
msleep(20);
return ret;
}
static int max98090_get_enab_tlv(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_soc_kcontrol_codec(kcontrol);
struct max98090_priv *max98090 = snd_soc_codec_get_drvdata(codec);
struct soc_mixer_control *mc =
(struct soc_mixer_control *)kcontrol->private_value;
unsigned int mask = (1 << fls(mc->max)) - 1;
unsigned int val = snd_soc_read(codec, mc->reg);
unsigned int *select;
switch (mc->reg) {
case M98090_REG_MIC1_INPUT_LEVEL:
select = &(max98090->pa1en);
break;
case M98090_REG_MIC2_INPUT_LEVEL:
select = &(max98090->pa2en);
break;
case M98090_REG_ADC_SIDETONE:
select = &(max98090->sidetone);
break;
default:
return -EINVAL;
}
val = (val >> mc->shift) & mask;
if (val >= 1) {
val = val - 1;
*select = val;
} else {
val = *select;
}
ucontrol->value.integer.value[0] = val;
return 0;
}
static int max98090_put_enab_tlv(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_soc_kcontrol_codec(kcontrol);
struct max98090_priv *max98090 = snd_soc_codec_get_drvdata(codec);
struct soc_mixer_control *mc =
(struct soc_mixer_control *)kcontrol->private_value;
unsigned int mask = (1 << fls(mc->max)) - 1;
unsigned int sel = ucontrol->value.integer.value[0];
unsigned int val = snd_soc_read(codec, mc->reg);
unsigned int *select;
switch (mc->reg) {
case M98090_REG_MIC1_INPUT_LEVEL:
select = &(max98090->pa1en);
break;
case M98090_REG_MIC2_INPUT_LEVEL:
select = &(max98090->pa2en);
break;
case M98090_REG_ADC_SIDETONE:
select = &(max98090->sidetone);
break;
default:
return -EINVAL;
}
val = (val >> mc->shift) & mask;
*select = sel;
if (val >= 1) {
sel = sel + 1;
} else {
sel = val;
}
snd_soc_update_bits(codec, mc->reg,
mask << mc->shift,
sel << mc->shift);
return 0;
}
static int max98090_micinput_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = w->codec;
struct max98090_priv *max98090 = snd_soc_codec_get_drvdata(codec);
unsigned int val = snd_soc_read(codec, w->reg);
if (w->reg == M98090_REG_MIC1_INPUT_LEVEL)
val = (val & M98090_MIC_PA1EN_MASK) >> M98090_MIC_PA1EN_SHIFT;
else
val = (val & M98090_MIC_PA2EN_MASK) >> M98090_MIC_PA2EN_SHIFT;
if (val >= 1) {
if (w->reg == M98090_REG_MIC1_INPUT_LEVEL) {
max98090->pa1en = val - 1;
} else {
max98090->pa2en = val - 1;
}
}
switch (event) {
case SND_SOC_DAPM_POST_PMU:
if (w->reg == M98090_REG_MIC1_INPUT_LEVEL)
val = max98090->pa1en + 1;
else
val = max98090->pa2en + 1;
break;
case SND_SOC_DAPM_POST_PMD:
val = 0;
break;
default:
return -EINVAL;
}
if (w->reg == M98090_REG_MIC1_INPUT_LEVEL)
snd_soc_update_bits(codec, w->reg, M98090_MIC_PA1EN_MASK,
val << M98090_MIC_PA1EN_SHIFT);
else
snd_soc_update_bits(codec, w->reg, M98090_MIC_PA2EN_MASK,
val << M98090_MIC_PA2EN_SHIFT);
return 0;
}
static int max98090_add_widgets(struct snd_soc_codec *codec)
{
struct max98090_priv *max98090 = snd_soc_codec_get_drvdata(codec);
struct snd_soc_dapm_context *dapm = &codec->dapm;
snd_soc_add_codec_controls(codec, max98090_snd_controls,
ARRAY_SIZE(max98090_snd_controls));
if (max98090->devtype == MAX98091) {
snd_soc_add_codec_controls(codec, max98091_snd_controls,
ARRAY_SIZE(max98091_snd_controls));
}
snd_soc_dapm_new_controls(dapm, max98090_dapm_widgets,
ARRAY_SIZE(max98090_dapm_widgets));
snd_soc_dapm_add_routes(dapm, max98090_dapm_routes,
ARRAY_SIZE(max98090_dapm_routes));
if (max98090->devtype == MAX98091) {
snd_soc_dapm_new_controls(dapm, max98091_dapm_widgets,
ARRAY_SIZE(max98091_dapm_widgets));
snd_soc_dapm_add_routes(dapm, max98091_dapm_routes,
ARRAY_SIZE(max98091_dapm_routes));
}
return 0;
}
static void max98090_configure_bclk(struct snd_soc_codec *codec)
{
struct max98090_priv *max98090 = snd_soc_codec_get_drvdata(codec);
unsigned long long ni;
int i;
if (!max98090->sysclk) {
dev_err(codec->dev, "No SYSCLK configured\n");
return;
}
if (!max98090->bclk || !max98090->lrclk) {
dev_err(codec->dev, "No audio clocks configured\n");
return;
}
if (!(snd_soc_read(codec, M98090_REG_MASTER_MODE) &
M98090_MAS_MASK)) {
return;
}
for (i = 0; i < ARRAY_SIZE(pclk_rates); i++) {
if ((pclk_rates[i] == max98090->sysclk) &&
(lrclk_rates[i] == max98090->lrclk)) {
dev_dbg(codec->dev,
"Found supported PCLK to LRCLK rates 0x%x\n",
i + 0x8);
snd_soc_update_bits(codec, M98090_REG_CLOCK_MODE,
M98090_FREQ_MASK,
(i + 0x8) << M98090_FREQ_SHIFT);
snd_soc_update_bits(codec, M98090_REG_CLOCK_MODE,
M98090_USE_M1_MASK, 0);
return;
}
}
for (i = 0; i < ARRAY_SIZE(user_pclk_rates); i++) {
if ((user_pclk_rates[i] == max98090->sysclk) &&
(user_lrclk_rates[i] == max98090->lrclk)) {
dev_dbg(codec->dev,
"Found user supported PCLK to LRCLK rates\n");
dev_dbg(codec->dev, "i %d ni %lld mi %lld\n",
i, ni_value[i], mi_value[i]);
snd_soc_update_bits(codec, M98090_REG_CLOCK_MODE,
M98090_FREQ_MASK, 0);
snd_soc_update_bits(codec, M98090_REG_CLOCK_MODE,
M98090_USE_M1_MASK,
1 << M98090_USE_M1_SHIFT);
snd_soc_write(codec, M98090_REG_CLOCK_RATIO_NI_MSB,
(ni_value[i] >> 8) & 0x7F);
snd_soc_write(codec, M98090_REG_CLOCK_RATIO_NI_LSB,
ni_value[i] & 0xFF);
snd_soc_write(codec, M98090_REG_CLOCK_RATIO_MI_MSB,
(mi_value[i] >> 8) & 0x7F);
snd_soc_write(codec, M98090_REG_CLOCK_RATIO_MI_LSB,
mi_value[i] & 0xFF);
return;
}
}
snd_soc_update_bits(codec, M98090_REG_CLOCK_MODE,
M98090_FREQ_MASK, 0);
snd_soc_update_bits(codec, M98090_REG_CLOCK_MODE,
M98090_USE_M1_MASK, 0);
ni = 65536ULL * (max98090->lrclk < 50000 ? 96ULL : 48ULL)
* (unsigned long long int)max98090->lrclk;
do_div(ni, (unsigned long long int)max98090->sysclk);
dev_info(codec->dev, "No better method found\n");
dev_info(codec->dev, "Calculating ni %lld with mi 65536\n", ni);
snd_soc_write(codec, M98090_REG_CLOCK_RATIO_NI_MSB,
(ni >> 8) & 0x7F);
snd_soc_write(codec, M98090_REG_CLOCK_RATIO_NI_LSB, ni & 0xFF);
}
static int max98090_dai_set_fmt(struct snd_soc_dai *codec_dai,
unsigned int fmt)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct max98090_priv *max98090 = snd_soc_codec_get_drvdata(codec);
struct max98090_cdata *cdata;
u8 regval;
max98090->dai_fmt = fmt;
cdata = &max98090->dai[0];
if (fmt != cdata->fmt) {
cdata->fmt = fmt;
regval = 0;
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBS_CFS:
snd_soc_write(codec,
M98090_REG_CLOCK_RATIO_NI_MSB, 0x00);
snd_soc_write(codec,
M98090_REG_CLOCK_RATIO_NI_LSB, 0x00);
snd_soc_update_bits(codec, M98090_REG_CLOCK_MODE,
M98090_USE_M1_MASK, 0);
max98090->master = false;
break;
case SND_SOC_DAIFMT_CBM_CFM:
if (max98090->tdm_slots == 4) {
regval |= M98090_MAS_MASK |
M98090_BSEL_64;
} else if (max98090->tdm_slots == 3) {
regval |= M98090_MAS_MASK |
M98090_BSEL_48;
} else {
regval |= M98090_MAS_MASK |
M98090_BSEL_32;
}
max98090->master = true;
break;
case SND_SOC_DAIFMT_CBS_CFM:
case SND_SOC_DAIFMT_CBM_CFS:
default:
dev_err(codec->dev, "DAI clock mode unsupported");
return -EINVAL;
}
snd_soc_write(codec, M98090_REG_MASTER_MODE, regval);
regval = 0;
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
regval |= M98090_DLY_MASK;
break;
case SND_SOC_DAIFMT_LEFT_J:
break;
case SND_SOC_DAIFMT_RIGHT_J:
regval |= M98090_RJ_MASK;
break;
case SND_SOC_DAIFMT_DSP_A:
default:
dev_err(codec->dev, "DAI format unsupported");
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
break;
case SND_SOC_DAIFMT_NB_IF:
regval |= M98090_WCI_MASK;
break;
case SND_SOC_DAIFMT_IB_NF:
regval |= M98090_BCI_MASK;
break;
case SND_SOC_DAIFMT_IB_IF:
regval |= M98090_BCI_MASK|M98090_WCI_MASK;
break;
default:
dev_err(codec->dev, "DAI invert mode unsupported");
return -EINVAL;
}
if (max98090->tdm_slots > 1)
regval ^= M98090_BCI_MASK;
snd_soc_write(codec,
M98090_REG_INTERFACE_FORMAT, regval);
}
return 0;
}
static int max98090_set_tdm_slot(struct snd_soc_dai *codec_dai,
unsigned int tx_mask, unsigned int rx_mask, int slots, int slot_width)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct max98090_priv *max98090 = snd_soc_codec_get_drvdata(codec);
struct max98090_cdata *cdata;
cdata = &max98090->dai[0];
if (slots < 0 || slots > 4)
return -EINVAL;
max98090->tdm_slots = slots;
max98090->tdm_width = slot_width;
if (max98090->tdm_slots > 1) {
snd_soc_write(codec, M98090_REG_TDM_FORMAT,
0 << M98090_TDM_SLOTL_SHIFT |
1 << M98090_TDM_SLOTR_SHIFT |
0 << M98090_TDM_SLOTDLY_SHIFT);
snd_soc_update_bits(codec, M98090_REG_TDM_CONTROL,
M98090_TDM_MASK,
M98090_TDM_MASK);
}
cdata->fmt = 0;
max98090_dai_set_fmt(codec_dai, max98090->dai_fmt);
return 0;
}
static int max98090_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
struct max98090_priv *max98090 = snd_soc_codec_get_drvdata(codec);
int ret;
switch (level) {
case SND_SOC_BIAS_ON:
break;
case SND_SOC_BIAS_PREPARE:
if (!IS_ERR(max98090->mclk)) {
if (codec->dapm.bias_level == SND_SOC_BIAS_ON)
clk_disable_unprepare(max98090->mclk);
else
clk_prepare_enable(max98090->mclk);
}
break;
case SND_SOC_BIAS_STANDBY:
if (codec->dapm.bias_level == SND_SOC_BIAS_OFF) {
ret = regcache_sync(max98090->regmap);
if (ret != 0) {
dev_err(codec->dev,
"Failed to sync cache: %d\n", ret);
return ret;
}
}
break;
case SND_SOC_BIAS_OFF:
snd_soc_update_bits(codec, M98090_REG_JACK_DETECT,
M98090_JDWK_MASK, M98090_JDWK_MASK);
regcache_mark_dirty(max98090->regmap);
break;
}
codec->dapm.bias_level = level;
return 0;
}
static int max98090_dai_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct max98090_priv *max98090 = snd_soc_codec_get_drvdata(codec);
struct max98090_cdata *cdata;
int i, j;
cdata = &max98090->dai[0];
max98090->bclk = snd_soc_params_to_bclk(params);
if (params_channels(params) == 1)
max98090->bclk *= 2;
max98090->lrclk = params_rate(params);
switch (params_width(params)) {
case 16:
snd_soc_update_bits(codec, M98090_REG_INTERFACE_FORMAT,
M98090_WS_MASK, 0);
break;
default:
return -EINVAL;
}
if (max98090->master)
max98090_configure_bclk(codec);
cdata->rate = max98090->lrclk;
if (max98090->lrclk < 24000)
snd_soc_update_bits(codec, M98090_REG_FILTER_CONFIG,
M98090_MODE_MASK, 0);
else
snd_soc_update_bits(codec, M98090_REG_FILTER_CONFIG,
M98090_MODE_MASK, M98090_MODE_MASK);
if (max98090->lrclk < 50000)
snd_soc_update_bits(codec, M98090_REG_FILTER_CONFIG,
M98090_DHF_MASK, 0);
else
snd_soc_update_bits(codec, M98090_REG_FILTER_CONFIG,
M98090_DHF_MASK, M98090_DHF_MASK);
for (j = 0; j < ARRAY_SIZE(comp_pclk_rates); j++) {
if (comp_pclk_rates[j] == max98090->sysclk) {
break;
}
}
for (i = 0; i < ARRAY_SIZE(comp_lrclk_rates) - 1; i++) {
if (max98090->lrclk <= (comp_lrclk_rates[i] +
comp_lrclk_rates[i + 1]) / 2) {
break;
}
}
snd_soc_update_bits(codec, M98090_REG_DIGITAL_MIC_ENABLE,
M98090_MICCLK_MASK,
dmic_micclk[j] << M98090_MICCLK_SHIFT);
snd_soc_update_bits(codec, M98090_REG_DIGITAL_MIC_CONFIG,
M98090_DMIC_COMP_MASK,
dmic_comp[j][i] << M98090_DMIC_COMP_SHIFT);
return 0;
}
static int max98090_dai_set_sysclk(struct snd_soc_dai *dai,
int clk_id, unsigned int freq, int dir)
{
struct snd_soc_codec *codec = dai->codec;
struct max98090_priv *max98090 = snd_soc_codec_get_drvdata(codec);
if (freq == max98090->sysclk)
return 0;
if (!IS_ERR(max98090->mclk)) {
freq = clk_round_rate(max98090->mclk, freq);
clk_set_rate(max98090->mclk, freq);
}
if ((freq >= 10000000) && (freq < 20000000)) {
snd_soc_write(codec, M98090_REG_SYSTEM_CLOCK,
M98090_PSCLK_DIV1);
} else if ((freq >= 20000000) && (freq < 40000000)) {
snd_soc_write(codec, M98090_REG_SYSTEM_CLOCK,
M98090_PSCLK_DIV2);
} else if ((freq >= 40000000) && (freq < 60000000)) {
snd_soc_write(codec, M98090_REG_SYSTEM_CLOCK,
M98090_PSCLK_DIV4);
} else {
dev_err(codec->dev, "Invalid master clock frequency\n");
return -EINVAL;
}
max98090->sysclk = freq;
return 0;
}
static int max98090_dai_digital_mute(struct snd_soc_dai *codec_dai, int mute)
{
struct snd_soc_codec *codec = codec_dai->codec;
int regval;
regval = mute ? M98090_DVM_MASK : 0;
snd_soc_update_bits(codec, M98090_REG_DAI_PLAYBACK_LEVEL,
M98090_DVM_MASK, regval);
return 0;
}
static void max98090_jack_work(struct work_struct *work)
{
struct max98090_priv *max98090 = container_of(work,
struct max98090_priv,
jack_work.work);
struct snd_soc_codec *codec = max98090->codec;
struct snd_soc_dapm_context *dapm = &codec->dapm;
int status = 0;
int reg;
if (max98090->jack_state == M98090_JACK_STATE_NO_HEADSET) {
snd_soc_update_bits(codec, M98090_REG_JACK_DETECT,
M98090_JDWK_MASK, 0);
msleep(50);
reg = snd_soc_read(codec, M98090_REG_JACK_STATUS);
snd_soc_update_bits(codec, M98090_REG_JACK_DETECT,
M98090_JDWK_MASK, M98090_JDWK_MASK);
} else {
reg = snd_soc_read(codec, M98090_REG_JACK_STATUS);
}
reg = snd_soc_read(codec, M98090_REG_JACK_STATUS);
switch (reg & (M98090_LSNS_MASK | M98090_JKSNS_MASK)) {
case M98090_LSNS_MASK | M98090_JKSNS_MASK:
dev_dbg(codec->dev, "No Headset Detected\n");
max98090->jack_state = M98090_JACK_STATE_NO_HEADSET;
status |= 0;
break;
case 0:
if (max98090->jack_state ==
M98090_JACK_STATE_HEADSET) {
dev_dbg(codec->dev,
"Headset Button Down Detected\n");
status |= SND_JACK_HEADSET;
status |= SND_JACK_BTN_0;
break;
}
dev_dbg(codec->dev, "Headphone Detected\n");
max98090->jack_state = M98090_JACK_STATE_HEADPHONE;
status |= SND_JACK_HEADPHONE;
break;
case M98090_JKSNS_MASK:
dev_dbg(codec->dev, "Headset Detected\n");
max98090->jack_state = M98090_JACK_STATE_HEADSET;
status |= SND_JACK_HEADSET;
break;
default:
dev_dbg(codec->dev, "Unrecognized Jack Status\n");
break;
}
snd_soc_jack_report(max98090->jack, status,
SND_JACK_HEADSET | SND_JACK_BTN_0);
snd_soc_dapm_sync(dapm);
}
static irqreturn_t max98090_interrupt(int irq, void *data)
{
struct snd_soc_codec *codec = data;
struct max98090_priv *max98090 = snd_soc_codec_get_drvdata(codec);
int ret;
unsigned int mask;
unsigned int active;
dev_dbg(codec->dev, "***** max98090_interrupt *****\n");
ret = regmap_read(max98090->regmap, M98090_REG_INTERRUPT_S, &mask);
if (ret != 0) {
dev_err(codec->dev,
"failed to read M98090_REG_INTERRUPT_S: %d\n",
ret);
return IRQ_NONE;
}
ret = regmap_read(max98090->regmap, M98090_REG_DEVICE_STATUS, &active);
if (ret != 0) {
dev_err(codec->dev,
"failed to read M98090_REG_DEVICE_STATUS: %d\n",
ret);
return IRQ_NONE;
}
dev_dbg(codec->dev, "active=0x%02x mask=0x%02x -> active=0x%02x\n",
active, mask, active & mask);
active &= mask;
if (!active)
return IRQ_NONE;
if (active & M98090_CLD_MASK)
dev_err(codec->dev, "M98090_CLD_MASK\n");
if (active & M98090_SLD_MASK)
dev_dbg(codec->dev, "M98090_SLD_MASK\n");
if (active & M98090_ULK_MASK)
dev_err(codec->dev, "M98090_ULK_MASK\n");
if (active & M98090_JDET_MASK) {
dev_dbg(codec->dev, "M98090_JDET_MASK\n");
pm_wakeup_event(codec->dev, 100);
queue_delayed_work(system_power_efficient_wq,
&max98090->jack_work,
msecs_to_jiffies(100));
}
if (active & M98090_DRCACT_MASK)
dev_dbg(codec->dev, "M98090_DRCACT_MASK\n");
if (active & M98090_DRCCLP_MASK)
dev_err(codec->dev, "M98090_DRCCLP_MASK\n");
return IRQ_HANDLED;
}
int max98090_mic_detect(struct snd_soc_codec *codec,
struct snd_soc_jack *jack)
{
struct max98090_priv *max98090 = snd_soc_codec_get_drvdata(codec);
dev_dbg(codec->dev, "max98090_mic_detect\n");
max98090->jack = jack;
if (jack) {
snd_soc_update_bits(codec, M98090_REG_INTERRUPT_S,
M98090_IJDET_MASK,
1 << M98090_IJDET_SHIFT);
} else {
snd_soc_update_bits(codec, M98090_REG_INTERRUPT_S,
M98090_IJDET_MASK,
0);
}
snd_soc_jack_report(max98090->jack, 0,
SND_JACK_HEADSET | SND_JACK_BTN_0);
queue_delayed_work(system_power_efficient_wq,
&max98090->jack_work,
msecs_to_jiffies(100));
return 0;
}
static int max98090_probe(struct snd_soc_codec *codec)
{
struct max98090_priv *max98090 = snd_soc_codec_get_drvdata(codec);
struct max98090_cdata *cdata;
enum max98090_type devtype;
int ret = 0;
dev_dbg(codec->dev, "max98090_probe\n");
max98090->mclk = devm_clk_get(codec->dev, "mclk");
if (PTR_ERR(max98090->mclk) == -EPROBE_DEFER)
return -EPROBE_DEFER;
max98090->codec = codec;
max98090_reset(max98090);
max98090->sysclk = (unsigned)-1;
max98090->master = false;
cdata = &max98090->dai[0];
cdata->rate = (unsigned)-1;
cdata->fmt = (unsigned)-1;
max98090->lin_state = 0;
max98090->pa1en = 0;
max98090->pa2en = 0;
max98090->extmic_mux = 0;
ret = snd_soc_read(codec, M98090_REG_REVISION_ID);
if (ret < 0) {
dev_err(codec->dev, "Failed to read device revision: %d\n",
ret);
goto err_access;
}
if ((ret >= M98090_REVA) && (ret <= M98090_REVA + 0x0f)) {
devtype = MAX98090;
dev_info(codec->dev, "MAX98090 REVID=0x%02x\n", ret);
} else if ((ret >= M98091_REVA) && (ret <= M98091_REVA + 0x0f)) {
devtype = MAX98091;
dev_info(codec->dev, "MAX98091 REVID=0x%02x\n", ret);
} else {
devtype = MAX98090;
dev_err(codec->dev, "Unrecognized revision 0x%02x\n", ret);
}
if (max98090->devtype != devtype) {
dev_warn(codec->dev, "Mismatch in DT specified CODEC type.\n");
max98090->devtype = devtype;
}
max98090->jack_state = M98090_JACK_STATE_NO_HEADSET;
INIT_DELAYED_WORK(&max98090->jack_work, max98090_jack_work);
snd_soc_write(codec, M98090_REG_JACK_DETECT,
M98090_JDETEN_MASK | M98090_JDEB_25MS);
dev_dbg(codec->dev, "irq = %d\n", max98090->irq);
ret = devm_request_threaded_irq(codec->dev, max98090->irq, NULL,
max98090_interrupt, IRQF_TRIGGER_FALLING | IRQF_ONESHOT,
"max98090_interrupt", codec);
if (ret < 0) {
dev_err(codec->dev, "request_irq failed: %d\n",
ret);
}
snd_soc_read(codec, M98090_REG_DEVICE_STATUS);
snd_soc_update_bits(codec, M98090_REG_DAC_CONTROL,
M98090_DACHP_MASK,
1 << M98090_DACHP_SHIFT);
snd_soc_update_bits(codec, M98090_REG_DAC_CONTROL,
M98090_PERFMODE_MASK,
0 << M98090_PERFMODE_SHIFT);
snd_soc_update_bits(codec, M98090_REG_ADC_CONTROL,
M98090_ADCHP_MASK,
1 << M98090_ADCHP_SHIFT);
snd_soc_write(codec, M98090_REG_BIAS_CONTROL,
M98090_VCM_MODE_MASK);
snd_soc_update_bits(codec, M98090_REG_MIC_BIAS_VOLTAGE,
M98090_MBVSEL_MASK, M98090_MBVSEL_2V8);
max98090_add_widgets(codec);
err_access:
return ret;
}
static int max98090_remove(struct snd_soc_codec *codec)
{
struct max98090_priv *max98090 = snd_soc_codec_get_drvdata(codec);
cancel_delayed_work_sync(&max98090->jack_work);
return 0;
}
static int max98090_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *i2c_id)
{
struct max98090_priv *max98090;
const struct acpi_device_id *acpi_id;
kernel_ulong_t driver_data = 0;
int ret;
pr_debug("max98090_i2c_probe\n");
max98090 = devm_kzalloc(&i2c->dev, sizeof(struct max98090_priv),
GFP_KERNEL);
if (max98090 == NULL)
return -ENOMEM;
if (ACPI_HANDLE(&i2c->dev)) {
acpi_id = acpi_match_device(i2c->dev.driver->acpi_match_table,
&i2c->dev);
if (!acpi_id) {
dev_err(&i2c->dev, "No driver data\n");
return -EINVAL;
}
driver_data = acpi_id->driver_data;
} else if (i2c_id) {
driver_data = i2c_id->driver_data;
}
max98090->devtype = driver_data;
i2c_set_clientdata(i2c, max98090);
max98090->pdata = i2c->dev.platform_data;
max98090->irq = i2c->irq;
max98090->regmap = devm_regmap_init_i2c(i2c, &max98090_regmap);
if (IS_ERR(max98090->regmap)) {
ret = PTR_ERR(max98090->regmap);
dev_err(&i2c->dev, "Failed to allocate regmap: %d\n", ret);
goto err_enable;
}
ret = snd_soc_register_codec(&i2c->dev,
&soc_codec_dev_max98090, max98090_dai,
ARRAY_SIZE(max98090_dai));
err_enable:
return ret;
}
static int max98090_i2c_remove(struct i2c_client *client)
{
snd_soc_unregister_codec(&client->dev);
return 0;
}
static int max98090_runtime_resume(struct device *dev)
{
struct max98090_priv *max98090 = dev_get_drvdata(dev);
regcache_cache_only(max98090->regmap, false);
max98090_reset(max98090);
regcache_sync(max98090->regmap);
return 0;
}
static int max98090_runtime_suspend(struct device *dev)
{
struct max98090_priv *max98090 = dev_get_drvdata(dev);
regcache_cache_only(max98090->regmap, true);
return 0;
}
static int max98090_resume(struct device *dev)
{
struct max98090_priv *max98090 = dev_get_drvdata(dev);
unsigned int status;
regcache_mark_dirty(max98090->regmap);
max98090_reset(max98090);
regmap_read(max98090->regmap, M98090_REG_DEVICE_STATUS, &status);
regcache_sync(max98090->regmap);
return 0;
}
static int max98090_suspend(struct device *dev)
{
return 0;
}
