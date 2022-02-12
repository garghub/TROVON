static inline int da732x_get_input_div(struct snd_soc_codec *codec, int sysclk)
{
int val;
int ret;
if (sysclk < DA732X_MCLK_10MHZ) {
val = DA732X_MCLK_RET_0_10MHZ;
ret = DA732X_MCLK_VAL_0_10MHZ;
} else if ((sysclk >= DA732X_MCLK_10MHZ) &&
(sysclk < DA732X_MCLK_20MHZ)) {
val = DA732X_MCLK_RET_10_20MHZ;
ret = DA732X_MCLK_VAL_10_20MHZ;
} else if ((sysclk >= DA732X_MCLK_20MHZ) &&
(sysclk < DA732X_MCLK_40MHZ)) {
val = DA732X_MCLK_RET_20_40MHZ;
ret = DA732X_MCLK_VAL_20_40MHZ;
} else if ((sysclk >= DA732X_MCLK_40MHZ) &&
(sysclk <= DA732X_MCLK_54MHZ)) {
val = DA732X_MCLK_RET_40_54MHZ;
ret = DA732X_MCLK_VAL_40_54MHZ;
} else {
return -EINVAL;
}
snd_soc_write(codec, DA732X_REG_PLL_CTRL, val);
return ret;
}
static void da732x_set_charge_pump(struct snd_soc_codec *codec, int state)
{
switch (state) {
case DA732X_ENABLE_CP:
snd_soc_write(codec, DA732X_REG_CLK_EN2, DA732X_CP_CLK_EN);
snd_soc_write(codec, DA732X_REG_CP_HP2, DA732X_HP_CP_EN |
DA732X_HP_CP_REG | DA732X_HP_CP_PULSESKIP);
snd_soc_write(codec, DA732X_REG_CP_CTRL1, DA732X_CP_EN |
DA732X_CP_CTRL_CPVDD1);
snd_soc_write(codec, DA732X_REG_CP_CTRL2,
DA732X_CP_MANAGE_MAGNITUDE | DA732X_CP_BOOST);
snd_soc_write(codec, DA732X_REG_CP_CTRL3, DA732X_CP_1MHZ);
break;
case DA732X_DISABLE_CP:
snd_soc_write(codec, DA732X_REG_CLK_EN2, DA732X_CP_CLK_DIS);
snd_soc_write(codec, DA732X_REG_CP_HP2, DA732X_HP_CP_DIS);
snd_soc_write(codec, DA732X_REG_CP_CTRL1, DA723X_CP_DIS);
break;
default:
pr_err(KERN_ERR "Wrong charge pump state\n");
break;
}
}
static int da732x_hpf_set(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_kcontrol_chip(kcontrol);
struct soc_enum *enum_ctrl = (struct soc_enum *)kcontrol->private_value;
unsigned int reg = enum_ctrl->reg;
unsigned int sel = ucontrol->value.integer.value[0];
unsigned int bits;
switch (sel) {
case DA732X_HPF_DISABLED:
bits = DA732X_HPF_DIS;
break;
case DA732X_HPF_VOICE:
bits = DA732X_HPF_VOICE_EN;
break;
case DA732X_HPF_MUSIC:
bits = DA732X_HPF_MUSIC_EN;
break;
default:
return -EINVAL;
}
snd_soc_update_bits(codec, reg, DA732X_HPF_MASK, bits);
return 0;
}
static int da732x_hpf_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_kcontrol_chip(kcontrol);
struct soc_enum *enum_ctrl = (struct soc_enum *)kcontrol->private_value;
unsigned int reg = enum_ctrl->reg;
int val;
val = snd_soc_read(codec, reg) & DA732X_HPF_MASK;
switch (val) {
case DA732X_HPF_VOICE_EN:
ucontrol->value.integer.value[0] = DA732X_HPF_VOICE;
break;
case DA732X_HPF_MUSIC_EN:
ucontrol->value.integer.value[0] = DA732X_HPF_MUSIC;
break;
default:
ucontrol->value.integer.value[0] = DA732X_HPF_DISABLED;
break;
}
return 0;
}
static int da732x_adc_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = w->codec;
switch (event) {
case SND_SOC_DAPM_POST_PMU:
switch (w->reg) {
case DA732X_REG_ADC1_PD:
snd_soc_update_bits(codec, DA732X_REG_CLK_EN3,
DA732X_ADCA_BB_CLK_EN,
DA732X_ADCA_BB_CLK_EN);
break;
case DA732X_REG_ADC2_PD:
snd_soc_update_bits(codec, DA732X_REG_CLK_EN3,
DA732X_ADCC_BB_CLK_EN,
DA732X_ADCC_BB_CLK_EN);
break;
default:
return -EINVAL;
}
snd_soc_update_bits(codec, w->reg, DA732X_ADC_RST_MASK,
DA732X_ADC_SET_ACT);
snd_soc_update_bits(codec, w->reg, DA732X_ADC_PD_MASK,
DA732X_ADC_ON);
break;
case SND_SOC_DAPM_POST_PMD:
snd_soc_update_bits(codec, w->reg, DA732X_ADC_PD_MASK,
DA732X_ADC_OFF);
snd_soc_update_bits(codec, w->reg, DA732X_ADC_RST_MASK,
DA732X_ADC_SET_RST);
switch (w->reg) {
case DA732X_REG_ADC1_PD:
snd_soc_update_bits(codec, DA732X_REG_CLK_EN3,
DA732X_ADCA_BB_CLK_EN, 0);
break;
case DA732X_REG_ADC2_PD:
snd_soc_update_bits(codec, DA732X_REG_CLK_EN3,
DA732X_ADCC_BB_CLK_EN, 0);
break;
default:
return -EINVAL;
}
break;
default:
return -EINVAL;
}
return 0;
}
static int da732x_out_pga_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = w->codec;
switch (event) {
case SND_SOC_DAPM_POST_PMU:
snd_soc_update_bits(codec, w->reg,
(1 << w->shift) | DA732X_OUT_HIZ_EN,
(1 << w->shift) | DA732X_OUT_HIZ_EN);
break;
case SND_SOC_DAPM_POST_PMD:
snd_soc_update_bits(codec, w->reg,
(1 << w->shift) | DA732X_OUT_HIZ_EN,
(1 << w->shift) | DA732X_OUT_HIZ_DIS);
break;
default:
return -EINVAL;
}
return 0;
}
static int da732x_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
u32 aif = 0;
u32 reg_aif;
u32 fs;
reg_aif = dai->driver->base;
switch (params_width(params)) {
case 16:
aif |= DA732X_AIF_WORD_16;
break;
case 20:
aif |= DA732X_AIF_WORD_20;
break;
case 24:
aif |= DA732X_AIF_WORD_24;
break;
case 32:
aif |= DA732X_AIF_WORD_32;
break;
default:
return -EINVAL;
}
switch (params_rate(params)) {
case 8000:
fs = DA732X_SR_8KHZ;
break;
case 11025:
fs = DA732X_SR_11_025KHZ;
break;
case 12000:
fs = DA732X_SR_12KHZ;
break;
case 16000:
fs = DA732X_SR_16KHZ;
break;
case 22050:
fs = DA732X_SR_22_05KHZ;
break;
case 24000:
fs = DA732X_SR_24KHZ;
break;
case 32000:
fs = DA732X_SR_32KHZ;
break;
case 44100:
fs = DA732X_SR_44_1KHZ;
break;
case 48000:
fs = DA732X_SR_48KHZ;
break;
case 88100:
fs = DA732X_SR_88_1KHZ;
break;
case 96000:
fs = DA732X_SR_96KHZ;
break;
default:
return -EINVAL;
}
snd_soc_update_bits(codec, reg_aif, DA732X_AIF_WORD_MASK, aif);
snd_soc_update_bits(codec, DA732X_REG_CLK_CTRL, DA732X_SR1_MASK, fs);
return 0;
}
static int da732x_set_dai_fmt(struct snd_soc_dai *dai, u32 fmt)
{
struct snd_soc_codec *codec = dai->codec;
u32 aif_mclk, pc_count;
u32 reg_aif1, aif1;
u32 reg_aif3, aif3;
switch (dai->id) {
case DA732X_DAI_ID1:
reg_aif1 = DA732X_REG_AIFA1;
reg_aif3 = DA732X_REG_AIFA3;
pc_count = DA732X_PC_PULSE_AIFA | DA732X_PC_RESYNC_NOT_AUT |
DA732X_PC_SAME;
break;
case DA732X_DAI_ID2:
reg_aif1 = DA732X_REG_AIFB1;
reg_aif3 = DA732X_REG_AIFB3;
pc_count = DA732X_PC_PULSE_AIFB | DA732X_PC_RESYNC_NOT_AUT |
DA732X_PC_SAME;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBS_CFS:
aif1 = DA732X_AIF_SLAVE;
aif_mclk = DA732X_AIFM_FRAME_64 | DA732X_AIFM_SRC_SEL_AIFA;
break;
case SND_SOC_DAIFMT_CBM_CFM:
aif1 = DA732X_AIF_CLK_FROM_SRC;
aif_mclk = DA732X_CLK_GENERATION_AIF_A;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
aif3 = DA732X_AIF_I2S_MODE;
break;
case SND_SOC_DAIFMT_RIGHT_J:
aif3 = DA732X_AIF_RIGHT_J_MODE;
break;
case SND_SOC_DAIFMT_LEFT_J:
aif3 = DA732X_AIF_LEFT_J_MODE;
break;
case SND_SOC_DAIFMT_DSP_B:
aif3 = DA732X_AIF_DSP_MODE;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_DSP_B:
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
break;
case SND_SOC_DAIFMT_IB_NF:
aif3 |= DA732X_AIF_BCLK_INV;
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
aif3 |= DA732X_AIF_BCLK_INV | DA732X_AIF_WCLK_INV;
break;
case SND_SOC_DAIFMT_IB_NF:
aif3 |= DA732X_AIF_BCLK_INV;
break;
case SND_SOC_DAIFMT_NB_IF:
aif3 |= DA732X_AIF_WCLK_INV;
break;
default:
return -EINVAL;
}
break;
default:
return -EINVAL;
}
snd_soc_write(codec, DA732X_REG_AIF_MCLK, aif_mclk);
snd_soc_update_bits(codec, reg_aif1, DA732X_AIF1_CLK_MASK, aif1);
snd_soc_update_bits(codec, reg_aif3, DA732X_AIF_BCLK_INV |
DA732X_AIF_WCLK_INV | DA732X_AIF_MODE_MASK, aif3);
snd_soc_write(codec, DA732X_REG_PC_CTRL, pc_count);
return 0;
}
static int da732x_set_dai_pll(struct snd_soc_codec *codec, int pll_id,
int source, unsigned int freq_in,
unsigned int freq_out)
{
struct da732x_priv *da732x = snd_soc_codec_get_drvdata(codec);
int fref, indiv;
u8 div_lo, div_mid, div_hi;
u64 frac_div;
if (freq_out == 0) {
snd_soc_update_bits(codec, DA732X_REG_PLL_CTRL,
DA732X_PLL_EN, 0);
da732x->pll_en = false;
return 0;
}
if (da732x->pll_en)
return -EBUSY;
if (source == DA732X_SRCCLK_MCLK) {
switch (da732x->sysclk) {
case 11290000:
case 12288000:
case 22580000:
case 24576000:
case 45160000:
case 49152000:
snd_soc_write(codec, DA732X_REG_PLL_CTRL,
DA732X_PLL_BYPASS);
return 0;
default:
dev_err(codec->dev,
"Cannot use PLL Bypass, invalid SYSCLK rate\n");
return -EINVAL;
}
}
indiv = da732x_get_input_div(codec, da732x->sysclk);
if (indiv < 0)
return indiv;
fref = (da732x->sysclk / indiv);
div_hi = freq_out / fref;
frac_div = (u64)(freq_out % fref) * 8192ULL;
do_div(frac_div, fref);
div_mid = (frac_div >> DA732X_1BYTE_SHIFT) & DA732X_U8_MASK;
div_lo = (frac_div) & DA732X_U8_MASK;
snd_soc_write(codec, DA732X_REG_PLL_DIV_LO, div_lo);
snd_soc_write(codec, DA732X_REG_PLL_DIV_MID, div_mid);
snd_soc_write(codec, DA732X_REG_PLL_DIV_HI, div_hi);
snd_soc_update_bits(codec, DA732X_REG_PLL_CTRL, DA732X_PLL_EN,
DA732X_PLL_EN);
da732x->pll_en = true;
return 0;
}
static int da732x_set_dai_sysclk(struct snd_soc_dai *dai, int clk_id,
unsigned int freq, int dir)
{
struct snd_soc_codec *codec = dai->codec;
struct da732x_priv *da732x = snd_soc_codec_get_drvdata(codec);
da732x->sysclk = freq;
return 0;
}
static bool da732x_volatile(struct device *dev, unsigned int reg)
{
switch (reg) {
case DA732X_REG_HPL_DAC_OFF_CNTL:
case DA732X_REG_HPR_DAC_OFF_CNTL:
return true;
default:
return false;
}
}
static void da732x_dac_offset_adjust(struct snd_soc_codec *codec)
{
u8 offset[DA732X_HP_DACS];
u8 sign[DA732X_HP_DACS];
u8 step = DA732X_DAC_OFFSET_STEP;
snd_soc_write(codec, DA732X_REG_HPL_DAC_OFFSET,
DA732X_HP_DAC_OFFSET_TRIM_VAL);
snd_soc_write(codec, DA732X_REG_HPR_DAC_OFFSET,
DA732X_HP_DAC_OFFSET_TRIM_VAL);
snd_soc_write(codec, DA732X_REG_HPL_DAC_OFF_CNTL,
DA732X_HP_DAC_OFF_CALIBRATION |
DA732X_HP_DAC_OFF_SCALE_STEPS);
snd_soc_write(codec, DA732X_REG_HPR_DAC_OFF_CNTL,
DA732X_HP_DAC_OFF_CALIBRATION |
DA732X_HP_DAC_OFF_SCALE_STEPS);
msleep(DA732X_WAIT_FOR_STABILIZATION);
sign[DA732X_HPL_DAC] = (snd_soc_read(codec, DA732X_REG_HPL_DAC_OFF_CNTL) &
DA732X_HP_DAC_OFF_CNTL_COMPO);
sign[DA732X_HPR_DAC] = (snd_soc_read(codec, DA732X_REG_HPR_DAC_OFF_CNTL) &
DA732X_HP_DAC_OFF_CNTL_COMPO);
offset[DA732X_HPL_DAC] = sign[DA732X_HPL_DAC] << DA732X_HP_DAC_COMPO_SHIFT;
offset[DA732X_HPR_DAC] = sign[DA732X_HPR_DAC] << DA732X_HP_DAC_COMPO_SHIFT;
do {
offset[DA732X_HPL_DAC] |= step;
offset[DA732X_HPR_DAC] |= step;
snd_soc_write(codec, DA732X_REG_HPL_DAC_OFFSET,
~offset[DA732X_HPL_DAC] & DA732X_HP_DAC_OFF_MASK);
snd_soc_write(codec, DA732X_REG_HPR_DAC_OFFSET,
~offset[DA732X_HPR_DAC] & DA732X_HP_DAC_OFF_MASK);
msleep(DA732X_WAIT_FOR_STABILIZATION);
if ((snd_soc_read(codec, DA732X_REG_HPL_DAC_OFF_CNTL) &
DA732X_HP_DAC_OFF_CNTL_COMPO) ^ sign[DA732X_HPL_DAC])
offset[DA732X_HPL_DAC] &= ~step;
if ((snd_soc_read(codec, DA732X_REG_HPR_DAC_OFF_CNTL) &
DA732X_HP_DAC_OFF_CNTL_COMPO) ^ sign[DA732X_HPR_DAC])
offset[DA732X_HPR_DAC] &= ~step;
step >>= 1;
} while (step);
snd_soc_write(codec, DA732X_REG_HPL_DAC_OFFSET,
~offset[DA732X_HPL_DAC] & DA732X_HP_DAC_OFF_MASK);
snd_soc_write(codec, DA732X_REG_HPR_DAC_OFFSET,
~offset[DA732X_HPR_DAC] & DA732X_HP_DAC_OFF_MASK);
snd_soc_write(codec, DA732X_REG_HPL_DAC_OFF_CNTL,
DA732X_HP_DAC_OFF_SCALE_STEPS);
snd_soc_write(codec, DA732X_REG_HPR_DAC_OFF_CNTL,
DA732X_HP_DAC_OFF_SCALE_STEPS);
}
static void da732x_output_offset_adjust(struct snd_soc_codec *codec)
{
u8 offset[DA732X_HP_AMPS];
u8 sign[DA732X_HP_AMPS];
u8 step = DA732X_OUTPUT_OFFSET_STEP;
offset[DA732X_HPL_AMP] = DA732X_HP_OUT_TRIM_VAL;
offset[DA732X_HPR_AMP] = DA732X_HP_OUT_TRIM_VAL;
snd_soc_write(codec, DA732X_REG_HPL_OUT_OFFSET, DA732X_HP_OUT_TRIM_VAL);
snd_soc_write(codec, DA732X_REG_HPR_OUT_OFFSET, DA732X_HP_OUT_TRIM_VAL);
snd_soc_write(codec, DA732X_REG_HPL,
DA732X_HP_OUT_COMP | DA732X_HP_OUT_EN);
snd_soc_write(codec, DA732X_REG_HPR,
DA732X_HP_OUT_COMP | DA732X_HP_OUT_EN);
msleep(DA732X_WAIT_FOR_STABILIZATION);
sign[DA732X_HPL_AMP] = snd_soc_read(codec, DA732X_REG_HPL) &
DA732X_HP_OUT_COMPO;
sign[DA732X_HPR_AMP] = snd_soc_read(codec, DA732X_REG_HPR) &
DA732X_HP_OUT_COMPO;
snd_soc_write(codec, DA732X_REG_HPL, DA732X_HP_OUT_COMP |
(sign[DA732X_HPL_AMP] >> DA732X_HP_OUT_COMPO_SHIFT) |
DA732X_HP_OUT_EN);
snd_soc_write(codec, DA732X_REG_HPR, DA732X_HP_OUT_COMP |
(sign[DA732X_HPR_AMP] >> DA732X_HP_OUT_COMPO_SHIFT) |
DA732X_HP_OUT_EN);
do {
offset[DA732X_HPL_AMP] |= step;
offset[DA732X_HPR_AMP] |= step;
snd_soc_write(codec, DA732X_REG_HPL_OUT_OFFSET,
offset[DA732X_HPL_AMP]);
snd_soc_write(codec, DA732X_REG_HPR_OUT_OFFSET,
offset[DA732X_HPR_AMP]);
msleep(DA732X_WAIT_FOR_STABILIZATION);
if ((snd_soc_read(codec, DA732X_REG_HPL) &
DA732X_HP_OUT_COMPO) ^ sign[DA732X_HPL_AMP])
offset[DA732X_HPL_AMP] &= ~step;
if ((snd_soc_read(codec, DA732X_REG_HPR) &
DA732X_HP_OUT_COMPO) ^ sign[DA732X_HPR_AMP])
offset[DA732X_HPR_AMP] &= ~step;
step >>= 1;
} while (step);
snd_soc_write(codec, DA732X_REG_HPL_OUT_OFFSET, offset[DA732X_HPL_AMP]);
snd_soc_write(codec, DA732X_REG_HPR_OUT_OFFSET, offset[DA732X_HPR_AMP]);
}
static void da732x_hp_dc_offset_cancellation(struct snd_soc_codec *codec)
{
snd_soc_write(codec, DA732X_REG_DAC1_SOFTMUTE, DA732X_SOFTMUTE_EN |
DA732X_GAIN_RAMPED | DA732X_16_SAMPLES);
snd_soc_write(codec, DA732X_REG_DAC1_SEL, DA732X_DACL_EN |
DA732X_DACR_EN | DA732X_DACL_SDM | DA732X_DACR_SDM |
DA732X_DACL_MUTE | DA732X_DACR_MUTE);
snd_soc_write(codec, DA732X_REG_HPL, DA732X_HP_OUT_DAC_EN |
DA732X_HP_OUT_MUTE | DA732X_HP_OUT_EN);
snd_soc_write(codec, DA732X_REG_HPR, DA732X_HP_OUT_EN |
DA732X_HP_OUT_MUTE | DA732X_HP_OUT_DAC_EN);
da732x_dac_offset_adjust(codec);
da732x_output_offset_adjust(codec);
snd_soc_write(codec, DA732X_REG_DAC1_SEL, DA732X_DACS_DIS);
snd_soc_write(codec, DA732X_REG_HPL, DA732X_HP_DIS);
snd_soc_write(codec, DA732X_REG_HPR, DA732X_HP_DIS);
}
static int da732x_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
struct da732x_priv *da732x = snd_soc_codec_get_drvdata(codec);
switch (level) {
case SND_SOC_BIAS_ON:
snd_soc_update_bits(codec, DA732X_REG_BIAS_EN,
DA732X_BIAS_BOOST_MASK,
DA732X_BIAS_BOOST_100PC);
break;
case SND_SOC_BIAS_PREPARE:
break;
case SND_SOC_BIAS_STANDBY:
if (codec->dapm.bias_level == SND_SOC_BIAS_OFF) {
snd_soc_write(codec, DA732X_REG_REF1,
DA732X_VMID_FASTCHG);
snd_soc_write(codec, DA732X_REG_BIAS_EN,
DA732X_BIAS_EN);
mdelay(DA732X_STARTUP_DELAY);
snd_soc_write(codec, DA732X_REG_REF1,
DA732X_REFBUFX2_EN);
snd_soc_write(codec, DA732X_REG_DATA_ROUTE,
DA732X_BYPASS_DSP);
snd_soc_write(codec, DA732X_REG_DSP_CTRL,
DA732X_DIGITAL_EN);
snd_soc_write(codec, DA732X_REG_SPARE1_OUT,
DA732X_HP_DRIVER_EN |
DA732X_HP_GATE_LOW |
DA732X_HP_LOOP_GAIN_CTRL);
snd_soc_write(codec, DA732X_REG_HP_LIN1_GNDSEL,
DA732X_HP_OUT_GNDSEL);
da732x_set_charge_pump(codec, DA732X_ENABLE_CP);
snd_soc_write(codec, DA732X_REG_CLK_EN1,
DA732X_SYS3_CLK_EN | DA732X_PC_CLK_EN);
snd_soc_write(codec, DA732X_REG_INP_ZC_EN,
DA732X_MIC1_PRE_ZC_EN |
DA732X_MIC1_ZC_EN |
DA732X_MIC2_PRE_ZC_EN |
DA732X_MIC2_ZC_EN |
DA732X_AUXL_ZC_EN |
DA732X_AUXR_ZC_EN |
DA732X_MIC3_PRE_ZC_EN |
DA732X_MIC3_ZC_EN);
snd_soc_write(codec, DA732X_REG_OUT_ZC_EN,
DA732X_HPL_ZC_EN | DA732X_HPR_ZC_EN |
DA732X_LIN2_ZC_EN | DA732X_LIN3_ZC_EN |
DA732X_LIN4_ZC_EN);
da732x_hp_dc_offset_cancellation(codec);
regcache_cache_only(da732x->regmap, false);
regcache_sync(da732x->regmap);
} else {
snd_soc_update_bits(codec, DA732X_REG_BIAS_EN,
DA732X_BIAS_BOOST_MASK,
DA732X_BIAS_BOOST_50PC);
snd_soc_update_bits(codec, DA732X_REG_PLL_CTRL,
DA732X_PLL_EN, 0);
da732x->pll_en = false;
}
break;
case SND_SOC_BIAS_OFF:
regcache_cache_only(da732x->regmap, true);
da732x_set_charge_pump(codec, DA732X_DISABLE_CP);
snd_soc_update_bits(codec, DA732X_REG_BIAS_EN, DA732X_BIAS_EN,
DA732X_BIAS_DIS);
da732x->pll_en = false;
break;
}
codec->dapm.bias_level = level;
return 0;
}
static int da732x_probe(struct snd_soc_codec *codec)
{
struct da732x_priv *da732x = snd_soc_codec_get_drvdata(codec);
struct snd_soc_dapm_context *dapm = &codec->dapm;
da732x->codec = codec;
dapm->idle_bias_off = false;
da732x_set_bias_level(codec, SND_SOC_BIAS_STANDBY);
return 0;
}
static int da732x_remove(struct snd_soc_codec *codec)
{
da732x_set_bias_level(codec, SND_SOC_BIAS_OFF);
return 0;
}
static int da732x_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct da732x_priv *da732x;
unsigned int reg;
int ret;
da732x = devm_kzalloc(&i2c->dev, sizeof(struct da732x_priv),
GFP_KERNEL);
if (!da732x)
return -ENOMEM;
i2c_set_clientdata(i2c, da732x);
da732x->regmap = devm_regmap_init_i2c(i2c, &da732x_regmap);
if (IS_ERR(da732x->regmap)) {
ret = PTR_ERR(da732x->regmap);
dev_err(&i2c->dev, "Failed to initialize regmap\n");
goto err;
}
ret = regmap_read(da732x->regmap, DA732X_REG_ID, &reg);
if (ret < 0) {
dev_err(&i2c->dev, "Failed to read ID register: %d\n", ret);
goto err;
}
dev_info(&i2c->dev, "Revision: %d.%d\n",
(reg & DA732X_ID_MAJOR_MASK) >> 4,
(reg & DA732X_ID_MINOR_MASK));
ret = snd_soc_register_codec(&i2c->dev, &soc_codec_dev_da732x,
da732x_dai, ARRAY_SIZE(da732x_dai));
if (ret != 0)
dev_err(&i2c->dev, "Failed to register codec.\n");
err:
return ret;
}
static int da732x_i2c_remove(struct i2c_client *client)
{
snd_soc_unregister_codec(&client->dev);
return 0;
}
