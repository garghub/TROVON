static bool nau8825_readable_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case NAU8825_REG_ENA_CTRL ... NAU8825_REG_FLL_VCO_RSV:
case NAU8825_REG_HSD_CTRL ... NAU8825_REG_JACK_DET_CTRL:
case NAU8825_REG_INTERRUPT_MASK ... NAU8825_REG_KEYDET_CTRL:
case NAU8825_REG_VDET_THRESHOLD_1 ... NAU8825_REG_DACR_CTRL:
case NAU8825_REG_ADC_DRC_KNEE_IP12 ... NAU8825_REG_ADC_DRC_ATKDCY:
case NAU8825_REG_DAC_DRC_KNEE_IP12 ... NAU8825_REG_DAC_DRC_ATKDCY:
case NAU8825_REG_IMM_MODE_CTRL ... NAU8825_REG_IMM_RMS_R:
case NAU8825_REG_CLASSG_CTRL ... NAU8825_REG_OPT_EFUSE_CTRL:
case NAU8825_REG_MISC_CTRL:
case NAU8825_REG_I2C_DEVICE_ID ... NAU8825_REG_SARDOUT_RAM_STATUS:
case NAU8825_REG_BIAS_ADJ:
case NAU8825_REG_TRIM_SETTINGS ... NAU8825_REG_ANALOG_CONTROL_2:
case NAU8825_REG_ANALOG_ADC_1 ... NAU8825_REG_MIC_BIAS:
case NAU8825_REG_BOOST ... NAU8825_REG_FEPGA:
case NAU8825_REG_POWER_UP_CONTROL ... NAU8825_REG_GENERAL_STATUS:
return true;
default:
return false;
}
}
static bool nau8825_writeable_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case NAU8825_REG_RESET ... NAU8825_REG_FLL_VCO_RSV:
case NAU8825_REG_HSD_CTRL ... NAU8825_REG_JACK_DET_CTRL:
case NAU8825_REG_INTERRUPT_MASK:
case NAU8825_REG_INT_CLR_KEY_STATUS ... NAU8825_REG_KEYDET_CTRL:
case NAU8825_REG_VDET_THRESHOLD_1 ... NAU8825_REG_DACR_CTRL:
case NAU8825_REG_ADC_DRC_KNEE_IP12 ... NAU8825_REG_ADC_DRC_ATKDCY:
case NAU8825_REG_DAC_DRC_KNEE_IP12 ... NAU8825_REG_DAC_DRC_ATKDCY:
case NAU8825_REG_IMM_MODE_CTRL:
case NAU8825_REG_CLASSG_CTRL ... NAU8825_REG_OPT_EFUSE_CTRL:
case NAU8825_REG_MISC_CTRL:
case NAU8825_REG_BIAS_ADJ:
case NAU8825_REG_TRIM_SETTINGS ... NAU8825_REG_ANALOG_CONTROL_2:
case NAU8825_REG_ANALOG_ADC_1 ... NAU8825_REG_MIC_BIAS:
case NAU8825_REG_BOOST ... NAU8825_REG_FEPGA:
case NAU8825_REG_POWER_UP_CONTROL ... NAU8825_REG_CHARGE_PUMP:
return true;
default:
return false;
}
}
static bool nau8825_volatile_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case NAU8825_REG_RESET:
case NAU8825_REG_IRQ_STATUS:
case NAU8825_REG_INT_CLR_KEY_STATUS:
case NAU8825_REG_IMM_RMS_L:
case NAU8825_REG_IMM_RMS_R:
case NAU8825_REG_I2C_DEVICE_ID:
case NAU8825_REG_SARDOUT_RAM_STATUS:
case NAU8825_REG_CHARGE_PUMP_INPUT_READ:
case NAU8825_REG_GENERAL_STATUS:
return true;
default:
return false;
}
}
static int nau8825_pump_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
struct nau8825 *nau8825 = snd_soc_codec_get_drvdata(codec);
switch (event) {
case SND_SOC_DAPM_POST_PMU:
msleep(10);
regmap_update_bits(nau8825->regmap, NAU8825_REG_CHARGE_PUMP,
NAU8825_JAMNODCLOW, NAU8825_JAMNODCLOW);
break;
case SND_SOC_DAPM_PRE_PMD:
regmap_update_bits(nau8825->regmap, NAU8825_REG_CHARGE_PUMP,
NAU8825_JAMNODCLOW, 0);
break;
default:
return -EINVAL;
}
return 0;
}
static int nau8825_output_dac_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
struct nau8825 *nau8825 = snd_soc_codec_get_drvdata(codec);
switch (event) {
case SND_SOC_DAPM_PRE_PMU:
regmap_update_bits(nau8825->regmap, NAU8825_REG_BIAS_ADJ,
NAU8825_BIAS_TESTDAC_EN, 0);
break;
case SND_SOC_DAPM_POST_PMD:
regmap_update_bits(nau8825->regmap, NAU8825_REG_BIAS_ADJ,
NAU8825_BIAS_TESTDAC_EN, NAU8825_BIAS_TESTDAC_EN);
break;
default:
return -EINVAL;
}
return 0;
}
static int nau8825_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct nau8825 *nau8825 = snd_soc_codec_get_drvdata(codec);
unsigned int val_len = 0;
switch (params_width(params)) {
case 16:
val_len |= NAU8825_I2S_DL_16;
break;
case 20:
val_len |= NAU8825_I2S_DL_20;
break;
case 24:
val_len |= NAU8825_I2S_DL_24;
break;
case 32:
val_len |= NAU8825_I2S_DL_32;
break;
default:
return -EINVAL;
}
regmap_update_bits(nau8825->regmap, NAU8825_REG_I2S_PCM_CTRL1,
NAU8825_I2S_DL_MASK, val_len);
return 0;
}
static int nau8825_set_dai_fmt(struct snd_soc_dai *codec_dai, unsigned int fmt)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct nau8825 *nau8825 = snd_soc_codec_get_drvdata(codec);
unsigned int ctrl1_val = 0, ctrl2_val = 0;
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBM_CFM:
ctrl2_val |= NAU8825_I2S_MS_MASTER;
break;
case SND_SOC_DAIFMT_CBS_CFS:
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
break;
case SND_SOC_DAIFMT_IB_NF:
ctrl1_val |= NAU8825_I2S_BP_INV;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
ctrl1_val |= NAU8825_I2S_DF_I2S;
break;
case SND_SOC_DAIFMT_LEFT_J:
ctrl1_val |= NAU8825_I2S_DF_LEFT;
break;
case SND_SOC_DAIFMT_RIGHT_J:
ctrl1_val |= NAU8825_I2S_DF_RIGTH;
break;
case SND_SOC_DAIFMT_DSP_A:
ctrl1_val |= NAU8825_I2S_DF_PCM_AB;
break;
case SND_SOC_DAIFMT_DSP_B:
ctrl1_val |= NAU8825_I2S_DF_PCM_AB;
ctrl1_val |= NAU8825_I2S_PCMB_EN;
break;
default:
return -EINVAL;
}
regmap_update_bits(nau8825->regmap, NAU8825_REG_I2S_PCM_CTRL1,
NAU8825_I2S_DL_MASK | NAU8825_I2S_DF_MASK |
NAU8825_I2S_BP_MASK | NAU8825_I2S_PCMB_MASK,
ctrl1_val);
regmap_update_bits(nau8825->regmap, NAU8825_REG_I2S_PCM_CTRL2,
NAU8825_I2S_MS_MASK, ctrl2_val);
return 0;
}
int nau8825_enable_jack_detect(struct snd_soc_codec *codec,
struct snd_soc_jack *jack)
{
struct nau8825 *nau8825 = snd_soc_codec_get_drvdata(codec);
struct regmap *regmap = nau8825->regmap;
nau8825->jack = jack;
regmap_update_bits(regmap, NAU8825_REG_HSD_CTRL,
NAU8825_HSD_AUTO_MODE | NAU8825_SPKR_DWN1R | NAU8825_SPKR_DWN1L,
NAU8825_HSD_AUTO_MODE | NAU8825_SPKR_DWN1R | NAU8825_SPKR_DWN1L);
regmap_update_bits(regmap, NAU8825_REG_INTERRUPT_MASK,
NAU8825_IRQ_HEADSET_COMPLETE_EN | NAU8825_IRQ_EJECT_EN, 0);
return 0;
}
static bool nau8825_is_jack_inserted(struct regmap *regmap)
{
int status;
regmap_read(regmap, NAU8825_REG_I2C_DEVICE_ID, &status);
return !(status & NAU8825_GPIO2JD1);
}
static void nau8825_restart_jack_detection(struct regmap *regmap)
{
regmap_update_bits(regmap, NAU8825_REG_I2S_PCM_CTRL2,
NAU8825_I2S_MS_MASK, NAU8825_I2S_MS_MASTER);
regmap_update_bits(regmap, NAU8825_REG_I2S_PCM_CTRL2,
NAU8825_I2S_MS_MASK, NAU8825_I2S_MS_SLAVE);
regmap_update_bits(regmap, NAU8825_REG_JACK_DET_CTRL,
NAU8825_JACK_DET_RESTART, NAU8825_JACK_DET_RESTART);
regmap_update_bits(regmap, NAU8825_REG_JACK_DET_CTRL,
NAU8825_JACK_DET_RESTART, 0);
}
static void nau8825_eject_jack(struct nau8825 *nau8825)
{
struct snd_soc_dapm_context *dapm = nau8825->dapm;
struct regmap *regmap = nau8825->regmap;
snd_soc_dapm_disable_pin(dapm, "SAR");
snd_soc_dapm_disable_pin(dapm, "MICBIAS");
regmap_update_bits(regmap, NAU8825_REG_MIC_BIAS,
NAU8825_MICBIAS_JKSLV | NAU8825_MICBIAS_JKR2, 0);
regmap_update_bits(regmap, NAU8825_REG_HSD_CTRL, 0xf, 0xf);
snd_soc_dapm_sync(dapm);
}
static int nau8825_button_decode(int value)
{
int buttons = 0;
if (value & BIT(0))
buttons |= SND_JACK_BTN_0;
if (value & BIT(1))
buttons |= SND_JACK_BTN_1;
if (value & BIT(2))
buttons |= SND_JACK_BTN_2;
if (value & BIT(3))
buttons |= SND_JACK_BTN_3;
if (value & BIT(4))
buttons |= SND_JACK_BTN_4;
if (value & BIT(5))
buttons |= SND_JACK_BTN_5;
return buttons;
}
static int nau8825_jack_insert(struct nau8825 *nau8825)
{
struct regmap *regmap = nau8825->regmap;
struct snd_soc_dapm_context *dapm = nau8825->dapm;
int jack_status_reg, mic_detected;
int type = 0;
regmap_read(regmap, NAU8825_REG_GENERAL_STATUS, &jack_status_reg);
mic_detected = (jack_status_reg >> 10) & 3;
switch (mic_detected) {
case 0:
type = SND_JACK_HEADPHONE;
break;
case 1:
dev_dbg(nau8825->dev, "OMTP (micgnd1) mic connected\n");
type = SND_JACK_HEADSET;
regmap_update_bits(regmap, NAU8825_REG_HSD_CTRL, 3 << 2,
1 << 2);
regmap_update_bits(regmap, NAU8825_REG_MIC_BIAS,
NAU8825_MICBIAS_JKSLV | NAU8825_MICBIAS_JKR2,
NAU8825_MICBIAS_JKR2);
regmap_update_bits(regmap, NAU8825_REG_SAR_CTRL,
NAU8825_SAR_INPUT_MASK,
NAU8825_SAR_INPUT_JKR2);
snd_soc_dapm_force_enable_pin(dapm, "MICBIAS");
snd_soc_dapm_force_enable_pin(dapm, "SAR");
snd_soc_dapm_sync(dapm);
break;
case 2:
case 3:
dev_dbg(nau8825->dev, "CTIA (micgnd2) mic connected\n");
type = SND_JACK_HEADSET;
regmap_update_bits(regmap, NAU8825_REG_HSD_CTRL, 3 << 2,
2 << 2);
regmap_update_bits(regmap, NAU8825_REG_MIC_BIAS,
NAU8825_MICBIAS_JKSLV | NAU8825_MICBIAS_JKR2,
NAU8825_MICBIAS_JKSLV);
regmap_update_bits(regmap, NAU8825_REG_SAR_CTRL,
NAU8825_SAR_INPUT_MASK,
NAU8825_SAR_INPUT_JKSLV);
snd_soc_dapm_force_enable_pin(dapm, "MICBIAS");
snd_soc_dapm_force_enable_pin(dapm, "SAR");
snd_soc_dapm_sync(dapm);
break;
}
return type;
}
static irqreturn_t nau8825_interrupt(int irq, void *data)
{
struct nau8825 *nau8825 = (struct nau8825 *)data;
struct regmap *regmap = nau8825->regmap;
int active_irq, clear_irq = 0, event = 0, event_mask = 0;
if (regmap_read(regmap, NAU8825_REG_IRQ_STATUS, &active_irq)) {
dev_err(nau8825->dev, "failed to read irq status\n");
return IRQ_NONE;
}
if ((active_irq & NAU8825_JACK_EJECTION_IRQ_MASK) ==
NAU8825_JACK_EJECTION_DETECTED) {
nau8825_eject_jack(nau8825);
event_mask |= SND_JACK_HEADSET;
clear_irq = NAU8825_JACK_EJECTION_IRQ_MASK;
} else if (active_irq & NAU8825_KEY_SHORT_PRESS_IRQ) {
int key_status;
regmap_read(regmap, NAU8825_REG_INT_CLR_KEY_STATUS,
&key_status);
nau8825->button_pressed = nau8825_button_decode(
key_status >> 8);
event |= nau8825->button_pressed;
event_mask |= NAU8825_BUTTONS;
clear_irq = NAU8825_KEY_SHORT_PRESS_IRQ;
} else if (active_irq & NAU8825_KEY_RELEASE_IRQ) {
event_mask = NAU8825_BUTTONS;
clear_irq = NAU8825_KEY_RELEASE_IRQ;
} else if (active_irq & NAU8825_HEADSET_COMPLETION_IRQ) {
if (nau8825_is_jack_inserted(regmap)) {
event |= nau8825_jack_insert(nau8825);
} else {
dev_warn(nau8825->dev, "Headset completion IRQ fired but no headset connected\n");
nau8825_eject_jack(nau8825);
}
event_mask |= SND_JACK_HEADSET;
clear_irq = NAU8825_HEADSET_COMPLETION_IRQ;
}
if (!clear_irq)
clear_irq = active_irq;
regmap_write(regmap, NAU8825_REG_INT_CLR_KEY_STATUS, clear_irq);
if (event_mask)
snd_soc_jack_report(nau8825->jack, event, event_mask);
return IRQ_HANDLED;
}
static void nau8825_setup_buttons(struct nau8825 *nau8825)
{
struct regmap *regmap = nau8825->regmap;
regmap_update_bits(regmap, NAU8825_REG_SAR_CTRL,
NAU8825_SAR_TRACKING_GAIN_MASK,
nau8825->sar_voltage << NAU8825_SAR_TRACKING_GAIN_SFT);
regmap_update_bits(regmap, NAU8825_REG_SAR_CTRL,
NAU8825_SAR_COMPARE_TIME_MASK,
nau8825->sar_compare_time << NAU8825_SAR_COMPARE_TIME_SFT);
regmap_update_bits(regmap, NAU8825_REG_SAR_CTRL,
NAU8825_SAR_SAMPLING_TIME_MASK,
nau8825->sar_sampling_time << NAU8825_SAR_SAMPLING_TIME_SFT);
regmap_update_bits(regmap, NAU8825_REG_KEYDET_CTRL,
NAU8825_KEYDET_LEVELS_NR_MASK,
(nau8825->sar_threshold_num - 1) << NAU8825_KEYDET_LEVELS_NR_SFT);
regmap_update_bits(regmap, NAU8825_REG_KEYDET_CTRL,
NAU8825_KEYDET_HYSTERESIS_MASK,
nau8825->sar_hysteresis << NAU8825_KEYDET_HYSTERESIS_SFT);
regmap_update_bits(regmap, NAU8825_REG_KEYDET_CTRL,
NAU8825_KEYDET_SHORTKEY_DEBOUNCE_MASK,
nau8825->key_debounce << NAU8825_KEYDET_SHORTKEY_DEBOUNCE_SFT);
regmap_write(regmap, NAU8825_REG_VDET_THRESHOLD_1,
(nau8825->sar_threshold[0] << 8) | nau8825->sar_threshold[1]);
regmap_write(regmap, NAU8825_REG_VDET_THRESHOLD_2,
(nau8825->sar_threshold[2] << 8) | nau8825->sar_threshold[3]);
regmap_write(regmap, NAU8825_REG_VDET_THRESHOLD_3,
(nau8825->sar_threshold[4] << 8) | nau8825->sar_threshold[5]);
regmap_write(regmap, NAU8825_REG_VDET_THRESHOLD_4,
(nau8825->sar_threshold[6] << 8) | nau8825->sar_threshold[7]);
regmap_update_bits(regmap, NAU8825_REG_INTERRUPT_MASK,
NAU8825_IRQ_KEY_SHORT_PRESS_EN | NAU8825_IRQ_KEY_RELEASE_EN,
0);
}
static void nau8825_init_regs(struct nau8825 *nau8825)
{
struct regmap *regmap = nau8825->regmap;
regmap_write(regmap, NAU8825_REG_IIC_ADDR_SET, 0x0001);
regmap_update_bits(nau8825->regmap, NAU8825_REG_BIAS_ADJ,
NAU8825_BIAS_VMID, NAU8825_BIAS_VMID);
regmap_update_bits(nau8825->regmap, NAU8825_REG_BOOST,
NAU8825_GLOBAL_BIAS_EN, NAU8825_GLOBAL_BIAS_EN);
regmap_update_bits(regmap, NAU8825_REG_BIAS_ADJ,
NAU8825_BIAS_VMID_SEL_MASK,
nau8825->vref_impedance << NAU8825_BIAS_VMID_SEL_SFT);
regmap_update_bits(regmap, NAU8825_REG_BOOST,
NAU8825_PRECHARGE_DIS | NAU8825_HP_BOOST_DIS |
NAU8825_HP_BOOST_G_DIS | NAU8825_SHORT_SHUTDOWN_EN,
NAU8825_PRECHARGE_DIS | NAU8825_HP_BOOST_DIS |
NAU8825_HP_BOOST_G_DIS | NAU8825_SHORT_SHUTDOWN_EN);
regmap_update_bits(regmap, NAU8825_REG_GPIO12_CTRL,
NAU8825_JKDET_OUTPUT_EN,
nau8825->jkdet_enable ? 0 : NAU8825_JKDET_OUTPUT_EN);
regmap_update_bits(regmap, NAU8825_REG_GPIO12_CTRL,
NAU8825_JKDET_PULL_EN,
nau8825->jkdet_pull_enable ? 0 : NAU8825_JKDET_PULL_EN);
regmap_update_bits(regmap, NAU8825_REG_GPIO12_CTRL,
NAU8825_JKDET_PULL_UP,
nau8825->jkdet_pull_up ? NAU8825_JKDET_PULL_UP : 0);
regmap_update_bits(regmap, NAU8825_REG_JACK_DET_CTRL,
NAU8825_JACK_POLARITY,
nau8825->jkdet_polarity ? 0 : NAU8825_JACK_POLARITY);
regmap_update_bits(regmap, NAU8825_REG_JACK_DET_CTRL,
NAU8825_JACK_INSERT_DEBOUNCE_MASK,
nau8825->jack_insert_debounce << NAU8825_JACK_INSERT_DEBOUNCE_SFT);
regmap_update_bits(regmap, NAU8825_REG_JACK_DET_CTRL,
NAU8825_JACK_EJECT_DEBOUNCE_MASK,
nau8825->jack_eject_debounce << NAU8825_JACK_EJECT_DEBOUNCE_SFT);
regmap_update_bits(regmap, NAU8825_REG_INTERRUPT_MASK, 0x7ff, 0x7ff);
regmap_update_bits(regmap, NAU8825_REG_MIC_BIAS,
NAU8825_MICBIAS_VOLTAGE_MASK, nau8825->micbias_voltage);
if (nau8825->sar_threshold_num)
nau8825_setup_buttons(nau8825);
regmap_update_bits(regmap, NAU8825_REG_ADC_RATE,
NAU8825_ADC_SYNC_DOWN_MASK, NAU8825_ADC_SYNC_DOWN_128);
regmap_update_bits(regmap, NAU8825_REG_DAC_CTRL1,
NAU8825_DAC_OVERSAMPLE_MASK, NAU8825_DAC_OVERSAMPLE_128);
regmap_update_bits(regmap, NAU8825_REG_CHARGE_PUMP,
NAU8825_POWER_DOWN_DACR | NAU8825_POWER_DOWN_DACL,
NAU8825_POWER_DOWN_DACR | NAU8825_POWER_DOWN_DACL);
regmap_update_bits(nau8825->regmap, NAU8825_REG_BIAS_ADJ,
NAU8825_BIAS_TESTDAC_EN, NAU8825_BIAS_TESTDAC_EN);
regmap_update_bits(regmap, NAU8825_REG_DAC_CTRL1,
NAU8825_DAC_CLIP_OFF, NAU8825_DAC_CLIP_OFF);
regmap_update_bits(regmap, NAU8825_REG_ANALOG_CONTROL_2,
NAU8825_HP_NON_CLASSG_CURRENT_2xADJ |
NAU8825_DAC_CAPACITOR_MSB | NAU8825_DAC_CAPACITOR_LSB,
NAU8825_HP_NON_CLASSG_CURRENT_2xADJ |
NAU8825_DAC_CAPACITOR_MSB | NAU8825_DAC_CAPACITOR_LSB);
regmap_update_bits(regmap, NAU8825_REG_CLASSG_CTRL,
NAU8825_CLASSG_TIMER_MASK,
0x20 << NAU8825_CLASSG_TIMER_SFT);
regmap_update_bits(regmap, NAU8825_REG_RDAC,
NAU8825_RDAC_CLK_DELAY_MASK | NAU8825_RDAC_VREF_MASK,
(0x2 << NAU8825_RDAC_CLK_DELAY_SFT) |
(0x3 << NAU8825_RDAC_VREF_SFT));
}
static int nau8825_codec_probe(struct snd_soc_codec *codec)
{
struct nau8825 *nau8825 = snd_soc_codec_get_drvdata(codec);
struct snd_soc_dapm_context *dapm = snd_soc_codec_get_dapm(codec);
nau8825->dapm = dapm;
snd_soc_dapm_force_enable_pin(dapm, "DDACR");
snd_soc_dapm_sync(dapm);
regmap_write(nau8825->regmap, NAU8825_REG_INTERRUPT_DIS_CTRL, 0);
nau8825_restart_jack_detection(nau8825->regmap);
return 0;
}
static int nau8825_calc_fll_param(unsigned int fll_in, unsigned int fs,
struct nau8825_fll *fll_param)
{
u64 fvco;
unsigned int fref, i;
for (i = 0; i < ARRAY_SIZE(fll_pre_scalar); i++) {
fref = fll_in / fll_pre_scalar[i].param;
if (fref <= NAU_FREF_MAX)
break;
}
if (i == ARRAY_SIZE(fll_pre_scalar))
return -EINVAL;
fll_param->clk_ref_div = fll_pre_scalar[i].val;
for (i = 0; i < ARRAY_SIZE(fll_ratio); i++) {
if (fref >= fll_ratio[i].param)
break;
}
if (i == ARRAY_SIZE(fll_ratio))
return -EINVAL;
fll_param->ratio = fll_ratio[i].val;
for (i = 0; i < ARRAY_SIZE(mclk_src_scaling); i++) {
fvco = 256 * fs * 2 * mclk_src_scaling[i].param;
if (NAU_FVCO_MIN < fvco && fvco < NAU_FVCO_MAX)
break;
}
if (i == ARRAY_SIZE(mclk_src_scaling))
return -EINVAL;
fll_param->mclk_src = mclk_src_scaling[i].val;
fvco = div_u64(fvco << 16, fref * fll_param->ratio);
fll_param->fll_int = (fvco >> 16) & 0x3FF;
fll_param->fll_frac = fvco & 0xFFFF;
return 0;
}
static void nau8825_fll_apply(struct nau8825 *nau8825,
struct nau8825_fll *fll_param)
{
regmap_update_bits(nau8825->regmap, NAU8825_REG_CLK_DIVIDER,
NAU8825_CLK_MCLK_SRC_MASK, fll_param->mclk_src);
regmap_update_bits(nau8825->regmap, NAU8825_REG_FLL1,
NAU8825_FLL_RATIO_MASK, fll_param->ratio);
regmap_write(nau8825->regmap, NAU8825_REG_FLL2, fll_param->fll_frac);
regmap_update_bits(nau8825->regmap, NAU8825_REG_FLL3,
NAU8825_FLL_INTEGER_MASK, fll_param->fll_int);
regmap_update_bits(nau8825->regmap, NAU8825_REG_FLL4,
NAU8825_FLL_REF_DIV_MASK, fll_param->clk_ref_div);
regmap_update_bits(nau8825->regmap, NAU8825_REG_FLL5,
NAU8825_FLL_FILTER_SW_MASK, 0x0000);
regmap_update_bits(nau8825->regmap, NAU8825_REG_FLL6,
NAU8825_SDM_EN_MASK, NAU8825_SDM_EN);
}
static int nau8825_set_pll(struct snd_soc_codec *codec, int pll_id, int source,
unsigned int freq_in, unsigned int freq_out)
{
struct nau8825 *nau8825 = snd_soc_codec_get_drvdata(codec);
struct nau8825_fll fll_param;
int ret, fs;
fs = freq_out / 256;
ret = nau8825_calc_fll_param(freq_in, fs, &fll_param);
if (ret < 0) {
dev_err(codec->dev, "Unsupported input clock %d\n", freq_in);
return ret;
}
dev_dbg(codec->dev, "mclk_src=%x ratio=%x fll_frac=%x fll_int=%x clk_ref_div=%x\n",
fll_param.mclk_src, fll_param.ratio, fll_param.fll_frac,
fll_param.fll_int, fll_param.clk_ref_div);
nau8825_fll_apply(nau8825, &fll_param);
mdelay(2);
regmap_update_bits(nau8825->regmap, NAU8825_REG_CLK_DIVIDER,
NAU8825_CLK_SRC_MASK, NAU8825_CLK_SRC_VCO);
return 0;
}
static int nau8825_configure_sysclk(struct nau8825 *nau8825, int clk_id,
unsigned int freq)
{
struct regmap *regmap = nau8825->regmap;
int ret;
switch (clk_id) {
case NAU8825_CLK_MCLK:
regmap_update_bits(regmap, NAU8825_REG_CLK_DIVIDER,
NAU8825_CLK_SRC_MASK, NAU8825_CLK_SRC_MCLK);
regmap_update_bits(regmap, NAU8825_REG_FLL6, NAU8825_DCO_EN, 0);
if (!nau8825->mclk)
break;
if (!nau8825->mclk_freq) {
ret = clk_prepare_enable(nau8825->mclk);
if (ret) {
dev_err(nau8825->dev, "Unable to prepare codec mclk\n");
return ret;
}
}
if (nau8825->mclk_freq != freq) {
nau8825->mclk_freq = freq;
freq = clk_round_rate(nau8825->mclk, freq);
ret = clk_set_rate(nau8825->mclk, freq);
if (ret) {
dev_err(nau8825->dev, "Unable to set mclk rate\n");
return ret;
}
}
break;
case NAU8825_CLK_INTERNAL:
regmap_update_bits(regmap, NAU8825_REG_FLL6, NAU8825_DCO_EN,
NAU8825_DCO_EN);
regmap_update_bits(regmap, NAU8825_REG_CLK_DIVIDER,
NAU8825_CLK_SRC_MASK, NAU8825_CLK_SRC_VCO);
if (nau8825->mclk_freq) {
clk_disable_unprepare(nau8825->mclk);
nau8825->mclk_freq = 0;
}
break;
default:
dev_err(nau8825->dev, "Invalid clock id (%d)\n", clk_id);
return -EINVAL;
}
dev_dbg(nau8825->dev, "Sysclk is %dHz and clock id is %d\n", freq,
clk_id);
return 0;
}
static int nau8825_set_sysclk(struct snd_soc_codec *codec, int clk_id,
int source, unsigned int freq, int dir)
{
struct nau8825 *nau8825 = snd_soc_codec_get_drvdata(codec);
return nau8825_configure_sysclk(nau8825, clk_id, freq);
}
static int nau8825_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
struct nau8825 *nau8825 = snd_soc_codec_get_drvdata(codec);
int ret;
switch (level) {
case SND_SOC_BIAS_ON:
break;
case SND_SOC_BIAS_PREPARE:
break;
case SND_SOC_BIAS_STANDBY:
if (snd_soc_codec_get_bias_level(codec) == SND_SOC_BIAS_OFF) {
if (nau8825->mclk_freq) {
ret = clk_prepare_enable(nau8825->mclk);
if (ret) {
dev_err(nau8825->dev, "Unable to prepare codec mclk\n");
return ret;
}
}
}
break;
case SND_SOC_BIAS_OFF:
if (nau8825->mclk_freq)
clk_disable_unprepare(nau8825->mclk);
break;
}
return 0;
}
static int nau8825_suspend(struct snd_soc_codec *codec)
{
struct nau8825 *nau8825 = snd_soc_codec_get_drvdata(codec);
disable_irq(nau8825->irq);
regcache_cache_only(nau8825->regmap, true);
regcache_mark_dirty(nau8825->regmap);
return 0;
}
static int nau8825_resume(struct snd_soc_codec *codec)
{
struct nau8825 *nau8825 = snd_soc_codec_get_drvdata(codec);
regcache_cache_only(nau8825->regmap, false);
regcache_sync(nau8825->regmap);
if (!nau8825_is_jack_inserted(nau8825->regmap)) {
nau8825_eject_jack(nau8825);
snd_soc_jack_report(nau8825->jack, 0, SND_JACK_HEADSET);
}
enable_irq(nau8825->irq);
nau8825_restart_jack_detection(nau8825->regmap);
return 0;
}
static void nau8825_reset_chip(struct regmap *regmap)
{
regmap_write(regmap, NAU8825_REG_RESET, 0x00);
regmap_write(regmap, NAU8825_REG_RESET, 0x00);
}
static void nau8825_print_device_properties(struct nau8825 *nau8825)
{
int i;
struct device *dev = nau8825->dev;
dev_dbg(dev, "jkdet-enable: %d\n", nau8825->jkdet_enable);
dev_dbg(dev, "jkdet-pull-enable: %d\n", nau8825->jkdet_pull_enable);
dev_dbg(dev, "jkdet-pull-up: %d\n", nau8825->jkdet_pull_up);
dev_dbg(dev, "jkdet-polarity: %d\n", nau8825->jkdet_polarity);
dev_dbg(dev, "micbias-voltage: %d\n", nau8825->micbias_voltage);
dev_dbg(dev, "vref-impedance: %d\n", nau8825->vref_impedance);
dev_dbg(dev, "sar-threshold-num: %d\n", nau8825->sar_threshold_num);
for (i = 0; i < nau8825->sar_threshold_num; i++)
dev_dbg(dev, "sar-threshold[%d]=%d\n", i,
nau8825->sar_threshold[i]);
dev_dbg(dev, "sar-hysteresis: %d\n", nau8825->sar_hysteresis);
dev_dbg(dev, "sar-voltage: %d\n", nau8825->sar_voltage);
dev_dbg(dev, "sar-compare-time: %d\n", nau8825->sar_compare_time);
dev_dbg(dev, "sar-sampling-time: %d\n", nau8825->sar_sampling_time);
dev_dbg(dev, "short-key-debounce: %d\n", nau8825->key_debounce);
dev_dbg(dev, "jack-insert-debounce: %d\n",
nau8825->jack_insert_debounce);
dev_dbg(dev, "jack-eject-debounce: %d\n",
nau8825->jack_eject_debounce);
}
static int nau8825_read_device_properties(struct device *dev,
struct nau8825 *nau8825) {
nau8825->jkdet_enable = device_property_read_bool(dev,
"nuvoton,jkdet-enable");
nau8825->jkdet_pull_enable = device_property_read_bool(dev,
"nuvoton,jkdet-pull-enable");
nau8825->jkdet_pull_up = device_property_read_bool(dev,
"nuvoton,jkdet-pull-up");
device_property_read_u32(dev, "nuvoton,jkdet-polarity",
&nau8825->jkdet_polarity);
device_property_read_u32(dev, "nuvoton,micbias-voltage",
&nau8825->micbias_voltage);
device_property_read_u32(dev, "nuvoton,vref-impedance",
&nau8825->vref_impedance);
device_property_read_u32(dev, "nuvoton,sar-threshold-num",
&nau8825->sar_threshold_num);
device_property_read_u32_array(dev, "nuvoton,sar-threshold",
nau8825->sar_threshold, nau8825->sar_threshold_num);
device_property_read_u32(dev, "nuvoton,sar-hysteresis",
&nau8825->sar_hysteresis);
device_property_read_u32(dev, "nuvoton,sar-voltage",
&nau8825->sar_voltage);
device_property_read_u32(dev, "nuvoton,sar-compare-time",
&nau8825->sar_compare_time);
device_property_read_u32(dev, "nuvoton,sar-sampling-time",
&nau8825->sar_sampling_time);
device_property_read_u32(dev, "nuvoton,short-key-debounce",
&nau8825->key_debounce);
device_property_read_u32(dev, "nuvoton,jack-insert-debounce",
&nau8825->jack_insert_debounce);
device_property_read_u32(dev, "nuvoton,jack-eject-debounce",
&nau8825->jack_eject_debounce);
nau8825->mclk = devm_clk_get(dev, "mclk");
if (PTR_ERR(nau8825->mclk) == -EPROBE_DEFER) {
return -EPROBE_DEFER;
} else if (PTR_ERR(nau8825->mclk) == -ENOENT) {
nau8825->mclk = NULL;
dev_info(dev, "No 'mclk' clock found, assume MCLK is managed externally");
} else if (IS_ERR(nau8825->mclk)) {
return -EINVAL;
}
return 0;
}
static int nau8825_setup_irq(struct nau8825 *nau8825)
{
struct regmap *regmap = nau8825->regmap;
int ret;
regmap_update_bits(regmap, NAU8825_REG_INTERRUPT_MASK,
NAU8825_IRQ_OUTPUT_EN, NAU8825_IRQ_OUTPUT_EN);
nau8825_configure_sysclk(nau8825, NAU8825_CLK_INTERNAL, 0);
regmap_update_bits(regmap, NAU8825_REG_ENA_CTRL,
NAU8825_ENABLE_DACR, NAU8825_ENABLE_DACR);
ret = devm_request_threaded_irq(nau8825->dev, nau8825->irq, NULL,
nau8825_interrupt, IRQF_TRIGGER_LOW | IRQF_ONESHOT,
"nau8825", nau8825);
if (ret) {
dev_err(nau8825->dev, "Cannot request irq %d (%d)\n",
nau8825->irq, ret);
return ret;
}
return 0;
}
static int nau8825_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct device *dev = &i2c->dev;
struct nau8825 *nau8825 = dev_get_platdata(&i2c->dev);
int ret, value;
if (!nau8825) {
nau8825 = devm_kzalloc(dev, sizeof(*nau8825), GFP_KERNEL);
if (!nau8825)
return -ENOMEM;
ret = nau8825_read_device_properties(dev, nau8825);
if (ret)
return ret;
}
i2c_set_clientdata(i2c, nau8825);
nau8825->regmap = devm_regmap_init_i2c(i2c, &nau8825_regmap_config);
if (IS_ERR(nau8825->regmap))
return PTR_ERR(nau8825->regmap);
nau8825->dev = dev;
nau8825->irq = i2c->irq;
nau8825_print_device_properties(nau8825);
nau8825_reset_chip(nau8825->regmap);
ret = regmap_read(nau8825->regmap, NAU8825_REG_I2C_DEVICE_ID, &value);
if (ret < 0) {
dev_err(dev, "Failed to read device id from the NAU8825: %d\n",
ret);
return ret;
}
if ((value & NAU8825_SOFTWARE_ID_MASK) !=
NAU8825_SOFTWARE_ID_NAU8825) {
dev_err(dev, "Not a NAU8825 chip\n");
return -ENODEV;
}
nau8825_init_regs(nau8825);
if (i2c->irq)
nau8825_setup_irq(nau8825);
return snd_soc_register_codec(&i2c->dev, &nau8825_codec_driver,
&nau8825_dai, 1);
}
static int nau8825_i2c_remove(struct i2c_client *client)
{
snd_soc_unregister_codec(&client->dev);
return 0;
}
