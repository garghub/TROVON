static int nau8824_sema_acquire(struct nau8824 *nau8824, long timeout)
{
int ret;
if (timeout) {
ret = down_timeout(&nau8824->jd_sem, timeout);
if (ret < 0)
dev_warn(nau8824->dev, "Acquire semaphone timeout\n");
} else {
ret = down_interruptible(&nau8824->jd_sem);
if (ret < 0)
dev_warn(nau8824->dev, "Acquire semaphone fail\n");
}
return ret;
}
static inline void nau8824_sema_release(struct nau8824 *nau8824)
{
up(&nau8824->jd_sem);
}
static bool nau8824_readable_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case NAU8824_REG_ENA_CTRL ... NAU8824_REG_FLL_VCO_RSV:
case NAU8824_REG_JACK_DET_CTRL:
case NAU8824_REG_INTERRUPT_SETTING_1:
case NAU8824_REG_IRQ:
case NAU8824_REG_CLEAR_INT_REG ... NAU8824_REG_VDET_THRESHOLD_4:
case NAU8824_REG_GPIO_SEL:
case NAU8824_REG_PORT0_I2S_PCM_CTRL_1 ... NAU8824_REG_TDM_CTRL:
case NAU8824_REG_ADC_HPF_FILTER ... NAU8824_REG_EQ4_EQ5:
case NAU8824_REG_ADC_CH0_DGAIN_CTRL ... NAU8824_REG_ADC_TO_DAC_ST:
case NAU8824_REG_DRC_KNEE_IP12_ADC_CH01 ... NAU8824_REG_DRC_GAINL_ADC3:
case NAU8824_REG_DRC_KNEE_IP12_DAC ... NAU8824_REG_DRC_GAIN_DAC_CH1:
case NAU8824_REG_CLASSG ... NAU8824_REG_OTP_EFUSE:
case NAU8824_REG_OTPDOUT_1 ... NAU8824_REG_OTPDOUT_2:
case NAU8824_REG_I2C_TIMEOUT:
case NAU8824_REG_I2C_DEVICE_ID ... NAU8824_REG_SAR_ADC_DATA_OUT:
case NAU8824_REG_BIAS_ADJ ... NAU8824_REG_CLASSD_GAIN_2:
case NAU8824_REG_ANALOG_ADC_1 ... NAU8824_REG_ATT_PORT1:
case NAU8824_REG_POWER_UP_CONTROL ... NAU8824_REG_CHARGE_PUMP_INPUT:
return true;
default:
return false;
}
}
static bool nau8824_writeable_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case NAU8824_REG_RESET ... NAU8824_REG_FLL_VCO_RSV:
case NAU8824_REG_JACK_DET_CTRL:
case NAU8824_REG_INTERRUPT_SETTING_1:
case NAU8824_REG_CLEAR_INT_REG ... NAU8824_REG_VDET_THRESHOLD_4:
case NAU8824_REG_GPIO_SEL:
case NAU8824_REG_PORT0_I2S_PCM_CTRL_1 ... NAU8824_REG_TDM_CTRL:
case NAU8824_REG_ADC_HPF_FILTER ... NAU8824_REG_EQ4_EQ5:
case NAU8824_REG_ADC_CH0_DGAIN_CTRL ... NAU8824_REG_ADC_TO_DAC_ST:
case NAU8824_REG_DRC_KNEE_IP12_ADC_CH01:
case NAU8824_REG_DRC_KNEE_IP34_ADC_CH01:
case NAU8824_REG_DRC_SLOPE_ADC_CH01:
case NAU8824_REG_DRC_ATKDCY_ADC_CH01:
case NAU8824_REG_DRC_KNEE_IP12_ADC_CH23:
case NAU8824_REG_DRC_KNEE_IP34_ADC_CH23:
case NAU8824_REG_DRC_SLOPE_ADC_CH23:
case NAU8824_REG_DRC_ATKDCY_ADC_CH23:
case NAU8824_REG_DRC_KNEE_IP12_DAC ... NAU8824_REG_DRC_ATKDCY_DAC:
case NAU8824_REG_CLASSG ... NAU8824_REG_OTP_EFUSE:
case NAU8824_REG_I2C_TIMEOUT:
case NAU8824_REG_BIAS_ADJ ... NAU8824_REG_CLASSD_GAIN_2:
case NAU8824_REG_ANALOG_ADC_1 ... NAU8824_REG_ATT_PORT1:
case NAU8824_REG_POWER_UP_CONTROL ... NAU8824_REG_CHARGE_PUMP_CONTROL:
return true;
default:
return false;
}
}
static bool nau8824_volatile_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case NAU8824_REG_RESET:
case NAU8824_REG_IRQ ... NAU8824_REG_CLEAR_INT_REG:
case NAU8824_REG_DRC_GAINL_ADC0 ... NAU8824_REG_DRC_GAINL_ADC3:
case NAU8824_REG_DRC_GAIN_DAC_CH0 ... NAU8824_REG_DRC_GAIN_DAC_CH1:
case NAU8824_REG_OTPDOUT_1 ... NAU8824_REG_OTPDOUT_2:
case NAU8824_REG_I2C_DEVICE_ID ... NAU8824_REG_SAR_ADC_DATA_OUT:
case NAU8824_REG_CHARGE_PUMP_INPUT:
return true;
default:
return false;
}
}
static int nau8824_output_dac_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
struct nau8824 *nau8824 = snd_soc_codec_get_drvdata(codec);
switch (event) {
case SND_SOC_DAPM_PRE_PMU:
regmap_update_bits(nau8824->regmap, NAU8824_REG_ENABLE_LO,
NAU8824_TEST_DAC_EN, 0);
break;
case SND_SOC_DAPM_POST_PMD:
regmap_update_bits(nau8824->regmap, NAU8824_REG_ENABLE_LO,
NAU8824_TEST_DAC_EN, NAU8824_TEST_DAC_EN);
break;
default:
return -EINVAL;
}
return 0;
}
static int nau8824_spk_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
struct nau8824 *nau8824 = snd_soc_codec_get_drvdata(codec);
switch (event) {
case SND_SOC_DAPM_PRE_PMU:
regmap_update_bits(nau8824->regmap,
NAU8824_REG_ANALOG_CONTROL_2,
NAU8824_CLASSD_CLAMP_DIS, NAU8824_CLASSD_CLAMP_DIS);
break;
case SND_SOC_DAPM_POST_PMD:
regmap_update_bits(nau8824->regmap,
NAU8824_REG_ANALOG_CONTROL_2,
NAU8824_CLASSD_CLAMP_DIS, 0);
break;
default:
return -EINVAL;
}
return 0;
}
static int nau8824_pump_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
struct nau8824 *nau8824 = snd_soc_codec_get_drvdata(codec);
switch (event) {
case SND_SOC_DAPM_POST_PMU:
msleep(10);
regmap_update_bits(nau8824->regmap,
NAU8824_REG_CHARGE_PUMP_CONTROL,
NAU8824_JAMNODCLOW, NAU8824_JAMNODCLOW);
break;
case SND_SOC_DAPM_PRE_PMD:
regmap_update_bits(nau8824->regmap,
NAU8824_REG_CHARGE_PUMP_CONTROL,
NAU8824_JAMNODCLOW, 0);
break;
default:
return -EINVAL;
}
return 0;
}
static int system_clock_control(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *k, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
struct nau8824 *nau8824 = snd_soc_codec_get_drvdata(codec);
if (SND_SOC_DAPM_EVENT_OFF(event)) {
if (nau8824_is_jack_inserted(nau8824)) {
nau8824_config_sysclk(nau8824,
NAU8824_CLK_INTERNAL, 0);
} else {
nau8824_config_sysclk(nau8824, NAU8824_CLK_DIS, 0);
}
}
return 0;
}
static int dmic_clock_control(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *k, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
struct nau8824 *nau8824 = snd_soc_codec_get_drvdata(codec);
int src;
for (src = 0; src < 5; src++) {
if ((0x1 << (8 - src)) * nau8824->fs <= DMIC_CLK)
break;
}
dev_dbg(nau8824->dev, "dmic src %d for mclk %d\n", src, nau8824->fs * 256);
regmap_update_bits(nau8824->regmap, NAU8824_REG_CLK_DIVIDER,
NAU8824_CLK_DMIC_SRC_MASK, (src << NAU8824_CLK_DMIC_SRC_SFT));
return 0;
}
static bool nau8824_is_jack_inserted(struct nau8824 *nau8824)
{
struct snd_soc_jack *jack = nau8824->jack;
bool insert = FALSE;
if (nau8824->irq && jack)
insert = jack->status & SND_JACK_HEADPHONE;
return insert;
}
static void nau8824_int_status_clear_all(struct regmap *regmap)
{
int active_irq, clear_irq, i;
regmap_read(regmap, NAU8824_REG_IRQ, &active_irq);
for (i = 0; i < NAU8824_REG_DATA_LEN; i++) {
clear_irq = (0x1 << i);
if (active_irq & clear_irq)
regmap_write(regmap,
NAU8824_REG_CLEAR_INT_REG, clear_irq);
}
}
static void nau8824_eject_jack(struct nau8824 *nau8824)
{
struct snd_soc_dapm_context *dapm = nau8824->dapm;
struct regmap *regmap = nau8824->regmap;
nau8824_int_status_clear_all(regmap);
snd_soc_dapm_disable_pin(dapm, "SAR");
snd_soc_dapm_disable_pin(dapm, "MICBIAS");
snd_soc_dapm_sync(dapm);
regmap_update_bits(regmap, NAU8824_REG_INTERRUPT_SETTING,
NAU8824_IRQ_KEY_RELEASE_DIS | NAU8824_IRQ_KEY_SHORT_PRESS_DIS |
NAU8824_IRQ_EJECT_DIS | NAU8824_IRQ_INSERT_DIS,
NAU8824_IRQ_KEY_RELEASE_DIS | NAU8824_IRQ_KEY_SHORT_PRESS_DIS |
NAU8824_IRQ_EJECT_DIS);
regmap_update_bits(regmap, NAU8824_REG_INTERRUPT_SETTING_1,
NAU8824_IRQ_INSERT_EN | NAU8824_IRQ_EJECT_EN,
NAU8824_IRQ_INSERT_EN);
regmap_update_bits(regmap, NAU8824_REG_ENA_CTRL,
NAU8824_JD_SLEEP_MODE, NAU8824_JD_SLEEP_MODE);
nau8824_config_sysclk(nau8824, NAU8824_CLK_DIS, 0);
}
static void nau8824_jdet_work(struct work_struct *work)
{
struct nau8824 *nau8824 = container_of(
work, struct nau8824, jdet_work);
struct snd_soc_dapm_context *dapm = nau8824->dapm;
struct regmap *regmap = nau8824->regmap;
int adc_value, event = 0, event_mask = 0;
snd_soc_dapm_force_enable_pin(dapm, "MICBIAS");
snd_soc_dapm_force_enable_pin(dapm, "SAR");
snd_soc_dapm_sync(dapm);
msleep(100);
regmap_read(regmap, NAU8824_REG_SAR_ADC_DATA_OUT, &adc_value);
adc_value = adc_value & NAU8824_SAR_ADC_DATA_MASK;
dev_dbg(nau8824->dev, "SAR ADC data 0x%02x\n", adc_value);
if (adc_value < HEADSET_SARADC_THD) {
event |= SND_JACK_HEADPHONE;
snd_soc_dapm_disable_pin(dapm, "SAR");
snd_soc_dapm_disable_pin(dapm, "MICBIAS");
snd_soc_dapm_sync(dapm);
} else {
event |= SND_JACK_HEADSET;
}
event_mask |= SND_JACK_HEADSET;
snd_soc_jack_report(nau8824->jack, event, event_mask);
nau8824_sema_release(nau8824);
}
static void nau8824_setup_auto_irq(struct nau8824 *nau8824)
{
struct regmap *regmap = nau8824->regmap;
regmap_update_bits(regmap, NAU8824_REG_INTERRUPT_SETTING_1,
NAU8824_IRQ_INSERT_EN | NAU8824_IRQ_EJECT_EN,
NAU8824_IRQ_EJECT_EN);
regmap_update_bits(regmap, NAU8824_REG_INTERRUPT_SETTING,
NAU8824_IRQ_EJECT_DIS | NAU8824_IRQ_KEY_RELEASE_DIS |
NAU8824_IRQ_KEY_SHORT_PRESS_DIS, 0);
nau8824_config_sysclk(nau8824, NAU8824_CLK_INTERNAL, 0);
regmap_update_bits(regmap, NAU8824_REG_ENA_CTRL,
NAU8824_JD_SLEEP_MODE, 0);
}
static int nau8824_button_decode(int value)
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
static irqreturn_t nau8824_interrupt(int irq, void *data)
{
struct nau8824 *nau8824 = (struct nau8824 *)data;
struct regmap *regmap = nau8824->regmap;
int active_irq, clear_irq = 0, event = 0, event_mask = 0;
if (regmap_read(regmap, NAU8824_REG_IRQ, &active_irq)) {
dev_err(nau8824->dev, "failed to read irq status\n");
return IRQ_NONE;
}
dev_dbg(nau8824->dev, "IRQ %x\n", active_irq);
if (active_irq & NAU8824_JACK_EJECTION_DETECTED) {
nau8824_eject_jack(nau8824);
event_mask |= SND_JACK_HEADSET;
clear_irq = NAU8824_JACK_EJECTION_DETECTED;
nau8824_sema_release(nau8824);
cancel_work_sync(&nau8824->jdet_work);
} else if (active_irq & NAU8824_KEY_SHORT_PRESS_IRQ) {
int key_status, button_pressed;
regmap_read(regmap, NAU8824_REG_CLEAR_INT_REG,
&key_status);
button_pressed = nau8824_button_decode(key_status);
event |= button_pressed;
dev_dbg(nau8824->dev, "button %x pressed\n", event);
event_mask |= NAU8824_BUTTONS;
clear_irq = NAU8824_KEY_SHORT_PRESS_IRQ;
} else if (active_irq & NAU8824_KEY_RELEASE_IRQ) {
event_mask = NAU8824_BUTTONS;
clear_irq = NAU8824_KEY_RELEASE_IRQ;
} else if (active_irq & NAU8824_JACK_INSERTION_DETECTED) {
regmap_update_bits(regmap,
NAU8824_REG_INTERRUPT_SETTING,
NAU8824_IRQ_INSERT_DIS,
NAU8824_IRQ_INSERT_DIS);
regmap_update_bits(regmap,
NAU8824_REG_INTERRUPT_SETTING_1,
NAU8824_IRQ_INSERT_EN, 0);
cancel_work_sync(&nau8824->jdet_work);
schedule_work(&nau8824->jdet_work);
nau8824_setup_auto_irq(nau8824);
}
if (!clear_irq)
clear_irq = active_irq;
regmap_write(regmap, NAU8824_REG_CLEAR_INT_REG, clear_irq);
if (event_mask)
snd_soc_jack_report(nau8824->jack, event, event_mask);
return IRQ_HANDLED;
}
static int nau8824_clock_check(struct nau8824 *nau8824,
int stream, int rate, int osr)
{
int osrate;
if (stream == SNDRV_PCM_STREAM_PLAYBACK) {
if (osr >= ARRAY_SIZE(osr_dac_sel))
return -EINVAL;
osrate = osr_dac_sel[osr].osr;
} else {
if (osr >= ARRAY_SIZE(osr_adc_sel))
return -EINVAL;
osrate = osr_adc_sel[osr].osr;
}
if (!osrate || rate * osr > CLK_DA_AD_MAX) {
dev_err(nau8824->dev, "exceed the maximum frequency of CLK_ADC or CLK_DAC\n");
return -EINVAL;
}
return 0;
}
static int nau8824_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params, struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct nau8824 *nau8824 = snd_soc_codec_get_drvdata(codec);
unsigned int val_len = 0, osr, ctrl_val, bclk_fs, bclk_div;
nau8824_sema_acquire(nau8824, HZ);
nau8824->fs = params_rate(params);
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK) {
regmap_read(nau8824->regmap,
NAU8824_REG_DAC_FILTER_CTRL_1, &osr);
osr &= NAU8824_DAC_OVERSAMPLE_MASK;
if (nau8824_clock_check(nau8824, substream->stream,
nau8824->fs, osr))
return -EINVAL;
regmap_update_bits(nau8824->regmap, NAU8824_REG_CLK_DIVIDER,
NAU8824_CLK_DAC_SRC_MASK,
osr_dac_sel[osr].clk_src << NAU8824_CLK_DAC_SRC_SFT);
} else {
regmap_read(nau8824->regmap,
NAU8824_REG_ADC_FILTER_CTRL, &osr);
osr &= NAU8824_ADC_SYNC_DOWN_MASK;
if (nau8824_clock_check(nau8824, substream->stream,
nau8824->fs, osr))
return -EINVAL;
regmap_update_bits(nau8824->regmap, NAU8824_REG_CLK_DIVIDER,
NAU8824_CLK_ADC_SRC_MASK,
osr_adc_sel[osr].clk_src << NAU8824_CLK_ADC_SRC_SFT);
}
regmap_read(nau8824->regmap,
NAU8824_REG_PORT0_I2S_PCM_CTRL_2, &ctrl_val);
if (ctrl_val & NAU8824_I2S_MS_MASTER) {
bclk_fs = snd_soc_params_to_bclk(params) / nau8824->fs;
if (bclk_fs <= 32)
bclk_div = 0x3;
else if (bclk_fs <= 64)
bclk_div = 0x2;
else if (bclk_fs <= 128)
bclk_div = 0x1;
else if (bclk_fs <= 256)
bclk_div = 0;
else
return -EINVAL;
regmap_update_bits(nau8824->regmap,
NAU8824_REG_PORT0_I2S_PCM_CTRL_2,
NAU8824_I2S_LRC_DIV_MASK | NAU8824_I2S_BLK_DIV_MASK,
(bclk_div << NAU8824_I2S_LRC_DIV_SFT) | bclk_div);
}
switch (params_width(params)) {
case 16:
val_len |= NAU8824_I2S_DL_16;
break;
case 20:
val_len |= NAU8824_I2S_DL_20;
break;
case 24:
val_len |= NAU8824_I2S_DL_24;
break;
case 32:
val_len |= NAU8824_I2S_DL_32;
break;
default:
return -EINVAL;
}
regmap_update_bits(nau8824->regmap, NAU8824_REG_PORT0_I2S_PCM_CTRL_1,
NAU8824_I2S_DL_MASK, val_len);
nau8824_sema_release(nau8824);
return 0;
}
static int nau8824_set_fmt(struct snd_soc_dai *dai, unsigned int fmt)
{
struct snd_soc_codec *codec = dai->codec;
struct nau8824 *nau8824 = snd_soc_codec_get_drvdata(codec);
unsigned int ctrl1_val = 0, ctrl2_val = 0;
nau8824_sema_acquire(nau8824, HZ);
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBM_CFM:
ctrl2_val |= NAU8824_I2S_MS_MASTER;
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
ctrl1_val |= NAU8824_I2S_BP_INV;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
ctrl1_val |= NAU8824_I2S_DF_I2S;
break;
case SND_SOC_DAIFMT_LEFT_J:
ctrl1_val |= NAU8824_I2S_DF_LEFT;
break;
case SND_SOC_DAIFMT_RIGHT_J:
ctrl1_val |= NAU8824_I2S_DF_RIGTH;
break;
case SND_SOC_DAIFMT_DSP_A:
ctrl1_val |= NAU8824_I2S_DF_PCM_AB;
break;
case SND_SOC_DAIFMT_DSP_B:
ctrl1_val |= NAU8824_I2S_DF_PCM_AB;
ctrl1_val |= NAU8824_I2S_PCMB_EN;
break;
default:
return -EINVAL;
}
regmap_update_bits(nau8824->regmap, NAU8824_REG_PORT0_I2S_PCM_CTRL_1,
NAU8824_I2S_DF_MASK | NAU8824_I2S_BP_MASK |
NAU8824_I2S_PCMB_EN, ctrl1_val);
regmap_update_bits(nau8824->regmap, NAU8824_REG_PORT0_I2S_PCM_CTRL_2,
NAU8824_I2S_MS_MASK, ctrl2_val);
nau8824_sema_release(nau8824);
return 0;
}
static int nau8824_calc_fll_param(unsigned int fll_in,
unsigned int fs, struct nau8824_fll *fll_param)
{
u64 fvco, fvco_max;
unsigned int fref, i, fvco_sel;
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
fvco_max = 0;
fvco_sel = ARRAY_SIZE(mclk_src_scaling);
for (i = 0; i < ARRAY_SIZE(mclk_src_scaling); i++) {
fvco = 256 * fs * 2 * mclk_src_scaling[i].param;
if (fvco > NAU_FVCO_MIN && fvco < NAU_FVCO_MAX &&
fvco_max < fvco) {
fvco_max = fvco;
fvco_sel = i;
}
}
if (ARRAY_SIZE(mclk_src_scaling) == fvco_sel)
return -EINVAL;
fll_param->mclk_src = mclk_src_scaling[fvco_sel].val;
fvco = div_u64(fvco_max << 16, fref * fll_param->ratio);
fll_param->fll_int = (fvco >> 16) & 0x3FF;
fll_param->fll_frac = fvco & 0xFFFF;
return 0;
}
static void nau8824_fll_apply(struct regmap *regmap,
struct nau8824_fll *fll_param)
{
regmap_update_bits(regmap, NAU8824_REG_CLK_DIVIDER,
NAU8824_CLK_SRC_MASK | NAU8824_CLK_MCLK_SRC_MASK,
NAU8824_CLK_SRC_MCLK | fll_param->mclk_src);
regmap_update_bits(regmap, NAU8824_REG_FLL1,
NAU8824_FLL_RATIO_MASK, fll_param->ratio);
regmap_write(regmap, NAU8824_REG_FLL2, fll_param->fll_frac);
regmap_update_bits(regmap, NAU8824_REG_FLL3,
NAU8824_FLL_INTEGER_MASK, fll_param->fll_int);
regmap_update_bits(regmap, NAU8824_REG_FLL4,
NAU8824_FLL_REF_DIV_MASK,
fll_param->clk_ref_div << NAU8824_FLL_REF_DIV_SFT);
regmap_update_bits(regmap, NAU8824_REG_FLL5,
NAU8824_FLL_CLK_SW_MASK, NAU8824_FLL_CLK_SW_REF);
regmap_update_bits(regmap,
NAU8824_REG_FLL6, NAU8824_DCO_EN, 0);
if (fll_param->fll_frac) {
regmap_update_bits(regmap, NAU8824_REG_FLL5,
NAU8824_FLL_PDB_DAC_EN | NAU8824_FLL_LOOP_FTR_EN |
NAU8824_FLL_FTR_SW_MASK,
NAU8824_FLL_PDB_DAC_EN | NAU8824_FLL_LOOP_FTR_EN |
NAU8824_FLL_FTR_SW_FILTER);
regmap_update_bits(regmap, NAU8824_REG_FLL6,
NAU8824_SDM_EN, NAU8824_SDM_EN);
} else {
regmap_update_bits(regmap, NAU8824_REG_FLL5,
NAU8824_FLL_PDB_DAC_EN | NAU8824_FLL_LOOP_FTR_EN |
NAU8824_FLL_FTR_SW_MASK, NAU8824_FLL_FTR_SW_ACCU);
regmap_update_bits(regmap,
NAU8824_REG_FLL6, NAU8824_SDM_EN, 0);
}
}
static int nau8824_set_pll(struct snd_soc_codec *codec, int pll_id, int source,
unsigned int freq_in, unsigned int freq_out)
{
struct nau8824 *nau8824 = snd_soc_codec_get_drvdata(codec);
struct nau8824_fll fll_param;
int ret, fs;
fs = freq_out / 256;
ret = nau8824_calc_fll_param(freq_in, fs, &fll_param);
if (ret < 0) {
dev_err(nau8824->dev, "Unsupported input clock %d\n", freq_in);
return ret;
}
dev_dbg(nau8824->dev, "mclk_src=%x ratio=%x fll_frac=%x fll_int=%x clk_ref_div=%x\n",
fll_param.mclk_src, fll_param.ratio, fll_param.fll_frac,
fll_param.fll_int, fll_param.clk_ref_div);
nau8824_fll_apply(nau8824->regmap, &fll_param);
mdelay(2);
regmap_update_bits(nau8824->regmap, NAU8824_REG_CLK_DIVIDER,
NAU8824_CLK_SRC_MASK, NAU8824_CLK_SRC_VCO);
return 0;
}
static int nau8824_config_sysclk(struct nau8824 *nau8824,
int clk_id, unsigned int freq)
{
struct regmap *regmap = nau8824->regmap;
switch (clk_id) {
case NAU8824_CLK_DIS:
regmap_update_bits(regmap, NAU8824_REG_CLK_DIVIDER,
NAU8824_CLK_SRC_MASK, NAU8824_CLK_SRC_MCLK);
regmap_update_bits(regmap, NAU8824_REG_FLL6,
NAU8824_DCO_EN, 0);
break;
case NAU8824_CLK_MCLK:
nau8824_sema_acquire(nau8824, HZ);
regmap_update_bits(regmap, NAU8824_REG_CLK_DIVIDER,
NAU8824_CLK_SRC_MASK, NAU8824_CLK_SRC_MCLK);
regmap_update_bits(regmap, NAU8824_REG_FLL6,
NAU8824_DCO_EN, 0);
nau8824_sema_release(nau8824);
break;
case NAU8824_CLK_INTERNAL:
regmap_update_bits(regmap, NAU8824_REG_FLL6,
NAU8824_DCO_EN, NAU8824_DCO_EN);
regmap_update_bits(regmap, NAU8824_REG_CLK_DIVIDER,
NAU8824_CLK_SRC_MASK, NAU8824_CLK_SRC_VCO);
break;
case NAU8824_CLK_FLL_MCLK:
nau8824_sema_acquire(nau8824, HZ);
regmap_update_bits(regmap, NAU8824_REG_FLL3,
NAU8824_FLL_CLK_SRC_MASK, NAU8824_FLL_CLK_SRC_MCLK);
nau8824_sema_release(nau8824);
break;
case NAU8824_CLK_FLL_BLK:
nau8824_sema_acquire(nau8824, HZ);
regmap_update_bits(regmap, NAU8824_REG_FLL3,
NAU8824_FLL_CLK_SRC_MASK, NAU8824_FLL_CLK_SRC_BLK);
nau8824_sema_release(nau8824);
break;
case NAU8824_CLK_FLL_FS:
nau8824_sema_acquire(nau8824, HZ);
regmap_update_bits(regmap, NAU8824_REG_FLL3,
NAU8824_FLL_CLK_SRC_MASK, NAU8824_FLL_CLK_SRC_FS);
nau8824_sema_release(nau8824);
break;
default:
dev_err(nau8824->dev, "Invalid clock id (%d)\n", clk_id);
return -EINVAL;
}
dev_dbg(nau8824->dev, "Sysclk is %dHz and clock id is %d\n", freq,
clk_id);
return 0;
}
static int nau8824_set_sysclk(struct snd_soc_codec *codec,
int clk_id, int source, unsigned int freq, int dir)
{
struct nau8824 *nau8824 = snd_soc_codec_get_drvdata(codec);
return nau8824_config_sysclk(nau8824, clk_id, freq);
}
static void nau8824_resume_setup(struct nau8824 *nau8824)
{
nau8824_config_sysclk(nau8824, NAU8824_CLK_DIS, 0);
if (nau8824->irq) {
nau8824_int_status_clear_all(nau8824->regmap);
regmap_update_bits(nau8824->regmap, NAU8824_REG_ENA_CTRL,
NAU8824_JD_SLEEP_MODE, NAU8824_JD_SLEEP_MODE);
regmap_update_bits(nau8824->regmap,
NAU8824_REG_INTERRUPT_SETTING_1,
NAU8824_IRQ_EJECT_EN | NAU8824_IRQ_INSERT_EN,
NAU8824_IRQ_EJECT_EN | NAU8824_IRQ_INSERT_EN);
regmap_update_bits(nau8824->regmap,
NAU8824_REG_INTERRUPT_SETTING,
NAU8824_IRQ_EJECT_DIS | NAU8824_IRQ_INSERT_DIS, 0);
}
}
static int nau8824_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
struct nau8824 *nau8824 = snd_soc_codec_get_drvdata(codec);
switch (level) {
case SND_SOC_BIAS_ON:
break;
case SND_SOC_BIAS_PREPARE:
break;
case SND_SOC_BIAS_STANDBY:
if (snd_soc_codec_get_bias_level(codec) == SND_SOC_BIAS_OFF) {
nau8824_resume_setup(nau8824);
}
break;
case SND_SOC_BIAS_OFF:
regmap_update_bits(nau8824->regmap,
NAU8824_REG_INTERRUPT_SETTING, 0x3ff, 0x3ff);
regmap_update_bits(nau8824->regmap,
NAU8824_REG_INTERRUPT_SETTING_1,
NAU8824_IRQ_EJECT_EN | NAU8824_IRQ_INSERT_EN, 0);
break;
}
return 0;
}
static int nau8824_codec_probe(struct snd_soc_codec *codec)
{
struct nau8824 *nau8824 = snd_soc_codec_get_drvdata(codec);
struct snd_soc_dapm_context *dapm = snd_soc_codec_get_dapm(codec);
nau8824->dapm = dapm;
return 0;
}
static int __maybe_unused nau8824_suspend(struct snd_soc_codec *codec)
{
struct nau8824 *nau8824 = snd_soc_codec_get_drvdata(codec);
if (nau8824->irq) {
disable_irq(nau8824->irq);
snd_soc_codec_force_bias_level(codec, SND_SOC_BIAS_OFF);
}
regcache_cache_only(nau8824->regmap, true);
regcache_mark_dirty(nau8824->regmap);
return 0;
}
static int __maybe_unused nau8824_resume(struct snd_soc_codec *codec)
{
struct nau8824 *nau8824 = snd_soc_codec_get_drvdata(codec);
regcache_cache_only(nau8824->regmap, false);
regcache_sync(nau8824->regmap);
if (nau8824->irq) {
nau8824_sema_acquire(nau8824, 0);
enable_irq(nau8824->irq);
}
return 0;
}
int nau8824_enable_jack_detect(struct snd_soc_codec *codec,
struct snd_soc_jack *jack)
{
struct nau8824 *nau8824 = snd_soc_codec_get_drvdata(codec);
int ret;
nau8824->jack = jack;
INIT_WORK(&nau8824->jdet_work, nau8824_jdet_work);
ret = devm_request_threaded_irq(nau8824->dev, nau8824->irq, NULL,
nau8824_interrupt, IRQF_TRIGGER_LOW | IRQF_ONESHOT,
"nau8824", nau8824);
if (ret) {
dev_err(nau8824->dev, "Cannot request irq %d (%d)\n",
nau8824->irq, ret);
}
return ret;
}
static void nau8824_reset_chip(struct regmap *regmap)
{
regmap_write(regmap, NAU8824_REG_RESET, 0x00);
regmap_write(regmap, NAU8824_REG_RESET, 0x00);
}
static void nau8824_setup_buttons(struct nau8824 *nau8824)
{
struct regmap *regmap = nau8824->regmap;
regmap_update_bits(regmap, NAU8824_REG_SAR_ADC,
NAU8824_SAR_TRACKING_GAIN_MASK,
nau8824->sar_voltage << NAU8824_SAR_TRACKING_GAIN_SFT);
regmap_update_bits(regmap, NAU8824_REG_SAR_ADC,
NAU8824_SAR_COMPARE_TIME_MASK,
nau8824->sar_compare_time << NAU8824_SAR_COMPARE_TIME_SFT);
regmap_update_bits(regmap, NAU8824_REG_SAR_ADC,
NAU8824_SAR_SAMPLING_TIME_MASK,
nau8824->sar_sampling_time << NAU8824_SAR_SAMPLING_TIME_SFT);
regmap_update_bits(regmap, NAU8824_REG_VDET_COEFFICIENT,
NAU8824_LEVELS_NR_MASK,
(nau8824->sar_threshold_num - 1) << NAU8824_LEVELS_NR_SFT);
regmap_update_bits(regmap, NAU8824_REG_VDET_COEFFICIENT,
NAU8824_HYSTERESIS_MASK,
nau8824->sar_hysteresis << NAU8824_HYSTERESIS_SFT);
regmap_update_bits(regmap, NAU8824_REG_VDET_COEFFICIENT,
NAU8824_SHORTKEY_DEBOUNCE_MASK,
nau8824->key_debounce << NAU8824_SHORTKEY_DEBOUNCE_SFT);
regmap_write(regmap, NAU8824_REG_VDET_THRESHOLD_1,
(nau8824->sar_threshold[0] << 8) | nau8824->sar_threshold[1]);
regmap_write(regmap, NAU8824_REG_VDET_THRESHOLD_2,
(nau8824->sar_threshold[2] << 8) | nau8824->sar_threshold[3]);
regmap_write(regmap, NAU8824_REG_VDET_THRESHOLD_3,
(nau8824->sar_threshold[4] << 8) | nau8824->sar_threshold[5]);
regmap_write(regmap, NAU8824_REG_VDET_THRESHOLD_4,
(nau8824->sar_threshold[6] << 8) | nau8824->sar_threshold[7]);
}
static void nau8824_init_regs(struct nau8824 *nau8824)
{
struct regmap *regmap = nau8824->regmap;
regmap_update_bits(regmap, NAU8824_REG_BIAS_ADJ,
NAU8824_VMID | NAU8824_VMID_SEL_MASK, NAU8824_VMID |
(nau8824->vref_impedance << NAU8824_VMID_SEL_SFT));
regmap_update_bits(regmap, NAU8824_REG_BOOST,
NAU8824_GLOBAL_BIAS_EN, NAU8824_GLOBAL_BIAS_EN);
mdelay(2);
regmap_update_bits(regmap, NAU8824_REG_MIC_BIAS,
NAU8824_MICBIAS_VOLTAGE_MASK, nau8824->micbias_voltage);
regmap_update_bits(regmap, NAU8824_REG_BOOST,
NAU8824_PRECHARGE_DIS | NAU8824_HP_BOOST_DIS |
NAU8824_HP_BOOST_G_DIS | NAU8824_SHORT_SHUTDOWN_EN,
NAU8824_PRECHARGE_DIS | NAU8824_HP_BOOST_DIS |
NAU8824_HP_BOOST_G_DIS | NAU8824_SHORT_SHUTDOWN_EN);
regmap_update_bits(regmap, NAU8824_REG_CLK_DIVIDER,
NAU8824_CLK_ADC_SRC_MASK | NAU8824_CLK_DAC_SRC_MASK,
(0x1 << NAU8824_CLK_ADC_SRC_SFT) |
(0x1 << NAU8824_CLK_DAC_SRC_SFT));
regmap_update_bits(regmap, NAU8824_REG_DAC_MUTE_CTRL,
NAU8824_DAC_ZC_EN, NAU8824_DAC_ZC_EN);
regmap_update_bits(regmap, NAU8824_REG_ENA_CTRL,
NAU8824_DAC_CH1_EN | NAU8824_DAC_CH0_EN |
NAU8824_ADC_CH0_EN | NAU8824_ADC_CH1_EN |
NAU8824_ADC_CH2_EN | NAU8824_ADC_CH3_EN,
NAU8824_DAC_CH1_EN | NAU8824_DAC_CH0_EN |
NAU8824_ADC_CH0_EN | NAU8824_ADC_CH1_EN |
NAU8824_ADC_CH2_EN | NAU8824_ADC_CH3_EN);
regmap_update_bits(regmap, NAU8824_REG_CLK_GATING_ENA,
NAU8824_CLK_ADC_CH23_EN | NAU8824_CLK_ADC_CH01_EN |
NAU8824_CLK_DAC_CH1_EN | NAU8824_CLK_DAC_CH0_EN |
NAU8824_CLK_I2S_EN | NAU8824_CLK_GAIN_EN |
NAU8824_CLK_SAR_EN | NAU8824_CLK_DMIC_CH23_EN,
NAU8824_CLK_ADC_CH23_EN | NAU8824_CLK_ADC_CH01_EN |
NAU8824_CLK_DAC_CH1_EN | NAU8824_CLK_DAC_CH0_EN |
NAU8824_CLK_I2S_EN | NAU8824_CLK_GAIN_EN |
NAU8824_CLK_SAR_EN | NAU8824_CLK_DMIC_CH23_EN);
regmap_update_bits(regmap, NAU8824_REG_CLASSG,
NAU8824_CLASSG_TIMER_MASK,
0x20 << NAU8824_CLASSG_TIMER_SFT);
regmap_update_bits(regmap, NAU8824_REG_TRIM_SETTINGS,
NAU8824_DRV_CURR_INC, NAU8824_DRV_CURR_INC);
regmap_update_bits(regmap, NAU8824_REG_CHARGE_PUMP_CONTROL,
NAU8824_SPKR_PULL_DOWN | NAU8824_SPKL_PULL_DOWN |
NAU8824_POWER_DOWN_DACR | NAU8824_POWER_DOWN_DACL,
NAU8824_SPKR_PULL_DOWN | NAU8824_SPKL_PULL_DOWN |
NAU8824_POWER_DOWN_DACR | NAU8824_POWER_DOWN_DACL);
regmap_update_bits(regmap, NAU8824_REG_ENABLE_LO,
NAU8824_TEST_DAC_EN, NAU8824_TEST_DAC_EN);
regmap_update_bits(regmap, NAU8824_REG_DAC_CH0_DGAIN_CTRL,
NAU8824_DAC_CH0_SEL_MASK, NAU8824_DAC_CH0_SEL_I2S0);
regmap_update_bits(regmap, NAU8824_REG_DAC_CH1_DGAIN_CTRL,
NAU8824_DAC_CH1_SEL_MASK, NAU8824_DAC_CH1_SEL_I2S1);
regmap_update_bits(regmap, NAU8824_REG_ENABLE_LO,
NAU8824_DACR_HPR_EN | NAU8824_DACL_HPL_EN,
NAU8824_DACR_HPR_EN | NAU8824_DACL_HPL_EN);
regmap_update_bits(regmap, NAU8824_REG_ADC_FILTER_CTRL,
NAU8824_ADC_SYNC_DOWN_MASK, NAU8824_ADC_SYNC_DOWN_64);
regmap_update_bits(regmap, NAU8824_REG_DAC_FILTER_CTRL_1,
NAU8824_DAC_CICCLP_OFF | NAU8824_DAC_OVERSAMPLE_MASK,
NAU8824_DAC_CICCLP_OFF | NAU8824_DAC_OVERSAMPLE_64);
regmap_update_bits(regmap, NAU8824_REG_RDAC,
NAU8824_RDAC_CLK_DELAY_MASK | NAU8824_RDAC_VREF_MASK,
(0x2 << NAU8824_RDAC_CLK_DELAY_SFT) |
(0x3 << NAU8824_RDAC_VREF_SFT));
regmap_update_bits(regmap, NAU8824_REG_FEPGA,
NAU8824_FEPGA_MODEL_SHORT_EN | NAU8824_FEPGA_MODER_SHORT_EN,
NAU8824_FEPGA_MODEL_SHORT_EN | NAU8824_FEPGA_MODER_SHORT_EN);
regmap_update_bits(regmap, NAU8824_REG_ANALOG_CONTROL_1,
NAU8824_DMIC_CLK_DRV_STRG | NAU8824_DMIC_CLK_SLEW_FAST,
NAU8824_DMIC_CLK_DRV_STRG | NAU8824_DMIC_CLK_SLEW_FAST);
regmap_update_bits(regmap, NAU8824_REG_JACK_DET_CTRL,
NAU8824_JACK_LOGIC,
nau8824->jkdet_polarity ? 0 : NAU8824_JACK_LOGIC);
regmap_update_bits(regmap,
NAU8824_REG_JACK_DET_CTRL, NAU8824_JACK_EJECT_DT_MASK,
(nau8824->jack_eject_debounce << NAU8824_JACK_EJECT_DT_SFT));
if (nau8824->sar_threshold_num)
nau8824_setup_buttons(nau8824);
}
static int nau8824_setup_irq(struct nau8824 *nau8824)
{
regmap_update_bits(nau8824->regmap, NAU8824_REG_ENA_CTRL,
NAU8824_JD_SLEEP_MODE, NAU8824_JD_SLEEP_MODE);
regmap_update_bits(nau8824->regmap,
NAU8824_REG_INTERRUPT_SETTING, 0x3ff, 0x3ff);
regmap_update_bits(nau8824->regmap, NAU8824_REG_INTERRUPT_SETTING_1,
NAU8824_IRQ_EJECT_EN | NAU8824_IRQ_INSERT_EN, 0);
return 0;
}
static void nau8824_print_device_properties(struct nau8824 *nau8824)
{
struct device *dev = nau8824->dev;
int i;
dev_dbg(dev, "jkdet-polarity: %d\n", nau8824->jkdet_polarity);
dev_dbg(dev, "micbias-voltage: %d\n", nau8824->micbias_voltage);
dev_dbg(dev, "vref-impedance: %d\n", nau8824->vref_impedance);
dev_dbg(dev, "sar-threshold-num: %d\n", nau8824->sar_threshold_num);
for (i = 0; i < nau8824->sar_threshold_num; i++)
dev_dbg(dev, "sar-threshold[%d]=%x\n", i,
nau8824->sar_threshold[i]);
dev_dbg(dev, "sar-hysteresis: %d\n", nau8824->sar_hysteresis);
dev_dbg(dev, "sar-voltage: %d\n", nau8824->sar_voltage);
dev_dbg(dev, "sar-compare-time: %d\n", nau8824->sar_compare_time);
dev_dbg(dev, "sar-sampling-time: %d\n", nau8824->sar_sampling_time);
dev_dbg(dev, "short-key-debounce: %d\n", nau8824->key_debounce);
dev_dbg(dev, "jack-eject-debounce: %d\n",
nau8824->jack_eject_debounce);
}
static int nau8824_read_device_properties(struct device *dev,
struct nau8824 *nau8824) {
int ret;
ret = device_property_read_u32(dev, "nuvoton,jkdet-polarity",
&nau8824->jkdet_polarity);
if (ret)
nau8824->jkdet_polarity = 1;
ret = device_property_read_u32(dev, "nuvoton,micbias-voltage",
&nau8824->micbias_voltage);
if (ret)
nau8824->micbias_voltage = 6;
ret = device_property_read_u32(dev, "nuvoton,vref-impedance",
&nau8824->vref_impedance);
if (ret)
nau8824->vref_impedance = 2;
ret = device_property_read_u32(dev, "nuvoton,sar-threshold-num",
&nau8824->sar_threshold_num);
if (ret)
nau8824->sar_threshold_num = 4;
ret = device_property_read_u32_array(dev, "nuvoton,sar-threshold",
nau8824->sar_threshold, nau8824->sar_threshold_num);
if (ret) {
nau8824->sar_threshold[0] = 0x0a;
nau8824->sar_threshold[1] = 0x14;
nau8824->sar_threshold[2] = 0x26;
nau8824->sar_threshold[3] = 0x73;
}
ret = device_property_read_u32(dev, "nuvoton,sar-hysteresis",
&nau8824->sar_hysteresis);
if (ret)
nau8824->sar_hysteresis = 0;
ret = device_property_read_u32(dev, "nuvoton,sar-voltage",
&nau8824->sar_voltage);
if (ret)
nau8824->sar_voltage = 6;
ret = device_property_read_u32(dev, "nuvoton,sar-compare-time",
&nau8824->sar_compare_time);
if (ret)
nau8824->sar_compare_time = 1;
ret = device_property_read_u32(dev, "nuvoton,sar-sampling-time",
&nau8824->sar_sampling_time);
if (ret)
nau8824->sar_sampling_time = 1;
ret = device_property_read_u32(dev, "nuvoton,short-key-debounce",
&nau8824->key_debounce);
if (ret)
nau8824->key_debounce = 0;
ret = device_property_read_u32(dev, "nuvoton,jack-eject-debounce",
&nau8824->jack_eject_debounce);
if (ret)
nau8824->jack_eject_debounce = 1;
return 0;
}
static int nau8824_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct device *dev = &i2c->dev;
struct nau8824 *nau8824 = dev_get_platdata(dev);
int ret, value;
if (!nau8824) {
nau8824 = devm_kzalloc(dev, sizeof(*nau8824), GFP_KERNEL);
if (!nau8824)
return -ENOMEM;
ret = nau8824_read_device_properties(dev, nau8824);
if (ret)
return ret;
}
i2c_set_clientdata(i2c, nau8824);
nau8824->regmap = devm_regmap_init_i2c(i2c, &nau8824_regmap_config);
if (IS_ERR(nau8824->regmap))
return PTR_ERR(nau8824->regmap);
nau8824->dev = dev;
nau8824->irq = i2c->irq;
sema_init(&nau8824->jd_sem, 1);
nau8824_print_device_properties(nau8824);
ret = regmap_read(nau8824->regmap, NAU8824_REG_I2C_DEVICE_ID, &value);
if (ret < 0) {
dev_err(dev, "Failed to read device id from the NAU8824: %d\n",
ret);
return ret;
}
nau8824_reset_chip(nau8824->regmap);
nau8824_init_regs(nau8824);
if (i2c->irq)
nau8824_setup_irq(nau8824);
return snd_soc_register_codec(dev,
&nau8824_codec_driver, &nau8824_dai, 1);
}
static int nau8824_i2c_remove(struct i2c_client *client)
{
snd_soc_unregister_codec(&client->dev);
return 0;
}
