static bool wm8903_readable_register(struct device *dev, unsigned int reg)
{
switch (reg) {
case WM8903_SW_RESET_AND_ID:
case WM8903_REVISION_NUMBER:
case WM8903_BIAS_CONTROL_0:
case WM8903_VMID_CONTROL_0:
case WM8903_MIC_BIAS_CONTROL_0:
case WM8903_ANALOGUE_DAC_0:
case WM8903_ANALOGUE_ADC_0:
case WM8903_POWER_MANAGEMENT_0:
case WM8903_POWER_MANAGEMENT_1:
case WM8903_POWER_MANAGEMENT_2:
case WM8903_POWER_MANAGEMENT_3:
case WM8903_POWER_MANAGEMENT_4:
case WM8903_POWER_MANAGEMENT_5:
case WM8903_POWER_MANAGEMENT_6:
case WM8903_CLOCK_RATES_0:
case WM8903_CLOCK_RATES_1:
case WM8903_CLOCK_RATES_2:
case WM8903_AUDIO_INTERFACE_0:
case WM8903_AUDIO_INTERFACE_1:
case WM8903_AUDIO_INTERFACE_2:
case WM8903_AUDIO_INTERFACE_3:
case WM8903_DAC_DIGITAL_VOLUME_LEFT:
case WM8903_DAC_DIGITAL_VOLUME_RIGHT:
case WM8903_DAC_DIGITAL_0:
case WM8903_DAC_DIGITAL_1:
case WM8903_ADC_DIGITAL_VOLUME_LEFT:
case WM8903_ADC_DIGITAL_VOLUME_RIGHT:
case WM8903_ADC_DIGITAL_0:
case WM8903_DIGITAL_MICROPHONE_0:
case WM8903_DRC_0:
case WM8903_DRC_1:
case WM8903_DRC_2:
case WM8903_DRC_3:
case WM8903_ANALOGUE_LEFT_INPUT_0:
case WM8903_ANALOGUE_RIGHT_INPUT_0:
case WM8903_ANALOGUE_LEFT_INPUT_1:
case WM8903_ANALOGUE_RIGHT_INPUT_1:
case WM8903_ANALOGUE_LEFT_MIX_0:
case WM8903_ANALOGUE_RIGHT_MIX_0:
case WM8903_ANALOGUE_SPK_MIX_LEFT_0:
case WM8903_ANALOGUE_SPK_MIX_LEFT_1:
case WM8903_ANALOGUE_SPK_MIX_RIGHT_0:
case WM8903_ANALOGUE_SPK_MIX_RIGHT_1:
case WM8903_ANALOGUE_OUT1_LEFT:
case WM8903_ANALOGUE_OUT1_RIGHT:
case WM8903_ANALOGUE_OUT2_LEFT:
case WM8903_ANALOGUE_OUT2_RIGHT:
case WM8903_ANALOGUE_OUT3_LEFT:
case WM8903_ANALOGUE_OUT3_RIGHT:
case WM8903_ANALOGUE_SPK_OUTPUT_CONTROL_0:
case WM8903_DC_SERVO_0:
case WM8903_DC_SERVO_2:
case WM8903_DC_SERVO_READBACK_1:
case WM8903_DC_SERVO_READBACK_2:
case WM8903_DC_SERVO_READBACK_3:
case WM8903_DC_SERVO_READBACK_4:
case WM8903_ANALOGUE_HP_0:
case WM8903_ANALOGUE_LINEOUT_0:
case WM8903_CHARGE_PUMP_0:
case WM8903_CLASS_W_0:
case WM8903_WRITE_SEQUENCER_0:
case WM8903_WRITE_SEQUENCER_1:
case WM8903_WRITE_SEQUENCER_2:
case WM8903_WRITE_SEQUENCER_3:
case WM8903_WRITE_SEQUENCER_4:
case WM8903_CONTROL_INTERFACE:
case WM8903_GPIO_CONTROL_1:
case WM8903_GPIO_CONTROL_2:
case WM8903_GPIO_CONTROL_3:
case WM8903_GPIO_CONTROL_4:
case WM8903_GPIO_CONTROL_5:
case WM8903_INTERRUPT_STATUS_1:
case WM8903_INTERRUPT_STATUS_1_MASK:
case WM8903_INTERRUPT_POLARITY_1:
case WM8903_INTERRUPT_CONTROL:
case WM8903_CLOCK_RATE_TEST_4:
case WM8903_ANALOGUE_OUTPUT_BIAS_0:
return true;
default:
return false;
}
}
static bool wm8903_volatile_register(struct device *dev, unsigned int reg)
{
switch (reg) {
case WM8903_SW_RESET_AND_ID:
case WM8903_REVISION_NUMBER:
case WM8903_INTERRUPT_STATUS_1:
case WM8903_WRITE_SEQUENCER_4:
case WM8903_DC_SERVO_READBACK_1:
case WM8903_DC_SERVO_READBACK_2:
case WM8903_DC_SERVO_READBACK_3:
case WM8903_DC_SERVO_READBACK_4:
return 1;
default:
return 0;
}
}
static int wm8903_cp_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
WARN_ON(event != SND_SOC_DAPM_POST_PMU);
mdelay(4);
return 0;
}
static int wm8903_dcs_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
struct wm8903_priv *wm8903 = snd_soc_codec_get_drvdata(codec);
switch (event) {
case SND_SOC_DAPM_POST_PMU:
wm8903->dcs_pending |= 1 << w->shift;
break;
case SND_SOC_DAPM_PRE_PMD:
snd_soc_update_bits(codec, WM8903_DC_SERVO_0,
1 << w->shift, 0);
break;
}
return 0;
}
static void wm8903_seq_notifier(struct snd_soc_dapm_context *dapm,
enum snd_soc_dapm_type event, int subseq)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(dapm);
struct wm8903_priv *wm8903 = snd_soc_codec_get_drvdata(codec);
int dcs_mode = WM8903_DCS_MODE_WRITE_STOP;
int i, val;
if (wm8903->dcs_pending) {
dev_dbg(codec->dev, "Starting DC servo for %x\n",
wm8903->dcs_pending);
for (i = 0; i < ARRAY_SIZE(wm8903->dcs_cache); i++) {
if (!(wm8903->dcs_pending & (1 << i)))
continue;
if (wm8903->dcs_cache[i]) {
dev_dbg(codec->dev,
"Restore DC servo %d value %x\n",
3 - i, wm8903->dcs_cache[i]);
snd_soc_write(codec, WM8903_DC_SERVO_4 + i,
wm8903->dcs_cache[i] & 0xff);
} else {
dev_dbg(codec->dev,
"Calibrate DC servo %d\n", 3 - i);
dcs_mode = WM8903_DCS_MODE_START_STOP;
}
}
if (wm8903->class_w_users)
dcs_mode = WM8903_DCS_MODE_START_STOP;
snd_soc_update_bits(codec, WM8903_DC_SERVO_2,
WM8903_DCS_MODE_MASK, dcs_mode);
snd_soc_update_bits(codec, WM8903_DC_SERVO_0,
WM8903_DCS_ENA_MASK, wm8903->dcs_pending);
switch (dcs_mode) {
case WM8903_DCS_MODE_WRITE_STOP:
break;
case WM8903_DCS_MODE_START_STOP:
msleep(270);
if (wm8903->class_w_users)
break;
for (i = 0; i < ARRAY_SIZE(wm8903->dcs_cache); i++) {
if (!(wm8903->dcs_pending & (1 << i)))
continue;
val = snd_soc_read(codec,
WM8903_DC_SERVO_READBACK_1 + i);
dev_dbg(codec->dev, "DC servo %d: %x\n",
3 - i, val);
wm8903->dcs_cache[i] = val;
}
break;
default:
pr_warn("DCS mode %d delay not set\n", dcs_mode);
break;
}
wm8903->dcs_pending = 0;
}
}
static int wm8903_class_w_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_soc_dapm_kcontrol_codec(kcontrol);
struct wm8903_priv *wm8903 = snd_soc_codec_get_drvdata(codec);
u16 reg;
int ret;
reg = snd_soc_read(codec, WM8903_CLASS_W_0);
if (ucontrol->value.integer.value[0]) {
if (wm8903->class_w_users == 0) {
dev_dbg(codec->dev, "Disabling Class W\n");
snd_soc_write(codec, WM8903_CLASS_W_0, reg &
~(WM8903_CP_DYN_FREQ | WM8903_CP_DYN_V));
}
wm8903->class_w_users++;
}
ret = snd_soc_dapm_put_volsw(kcontrol, ucontrol);
if (!ucontrol->value.integer.value[0]) {
if (wm8903->class_w_users == 1) {
dev_dbg(codec->dev, "Enabling Class W\n");
snd_soc_write(codec, WM8903_CLASS_W_0, reg |
WM8903_CP_DYN_FREQ | WM8903_CP_DYN_V);
}
wm8903->class_w_users--;
}
dev_dbg(codec->dev, "Bypass use count now %d\n",
wm8903->class_w_users);
return ret;
}
static int wm8903_set_deemph(struct snd_soc_codec *codec)
{
struct wm8903_priv *wm8903 = snd_soc_codec_get_drvdata(codec);
int val, i, best;
if (wm8903->deemph) {
best = 1;
for (i = 2; i < ARRAY_SIZE(wm8903_deemph); i++) {
if (abs(wm8903_deemph[i] - wm8903->fs) <
abs(wm8903_deemph[best] - wm8903->fs))
best = i;
}
val = best << WM8903_DEEMPH_SHIFT;
} else {
best = 0;
val = 0;
}
dev_dbg(codec->dev, "Set deemphasis %d (%dHz)\n",
best, wm8903_deemph[best]);
return snd_soc_update_bits(codec, WM8903_DAC_DIGITAL_1,
WM8903_DEEMPH_MASK, val);
}
static int wm8903_get_deemph(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_soc_kcontrol_codec(kcontrol);
struct wm8903_priv *wm8903 = snd_soc_codec_get_drvdata(codec);
ucontrol->value.integer.value[0] = wm8903->deemph;
return 0;
}
static int wm8903_put_deemph(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_soc_kcontrol_codec(kcontrol);
struct wm8903_priv *wm8903 = snd_soc_codec_get_drvdata(codec);
unsigned int deemph = ucontrol->value.integer.value[0];
int ret = 0;
if (deemph > 1)
return -EINVAL;
mutex_lock(&wm8903->lock);
if (wm8903->deemph != deemph) {
wm8903->deemph = deemph;
wm8903_set_deemph(codec);
ret = 1;
}
mutex_unlock(&wm8903->lock);
return ret;
}
static int wm8903_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
switch (level) {
case SND_SOC_BIAS_ON:
break;
case SND_SOC_BIAS_PREPARE:
snd_soc_update_bits(codec, WM8903_VMID_CONTROL_0,
WM8903_VMID_RES_MASK,
WM8903_VMID_RES_50K);
break;
case SND_SOC_BIAS_STANDBY:
if (snd_soc_codec_get_bias_level(codec) == SND_SOC_BIAS_OFF) {
snd_soc_update_bits(codec, WM8903_BIAS_CONTROL_0,
WM8903_POBCTRL | WM8903_ISEL_MASK |
WM8903_STARTUP_BIAS_ENA |
WM8903_BIAS_ENA,
WM8903_POBCTRL |
(2 << WM8903_ISEL_SHIFT) |
WM8903_STARTUP_BIAS_ENA);
snd_soc_update_bits(codec,
WM8903_ANALOGUE_SPK_OUTPUT_CONTROL_0,
WM8903_SPK_DISCHARGE,
WM8903_SPK_DISCHARGE);
msleep(33);
snd_soc_update_bits(codec, WM8903_POWER_MANAGEMENT_5,
WM8903_SPKL_ENA | WM8903_SPKR_ENA,
WM8903_SPKL_ENA | WM8903_SPKR_ENA);
snd_soc_update_bits(codec,
WM8903_ANALOGUE_SPK_OUTPUT_CONTROL_0,
WM8903_SPK_DISCHARGE, 0);
snd_soc_update_bits(codec, WM8903_VMID_CONTROL_0,
WM8903_VMID_TIE_ENA |
WM8903_BUFIO_ENA |
WM8903_VMID_IO_ENA |
WM8903_VMID_SOFT_MASK |
WM8903_VMID_RES_MASK |
WM8903_VMID_BUF_ENA,
WM8903_VMID_TIE_ENA |
WM8903_BUFIO_ENA |
WM8903_VMID_IO_ENA |
(2 << WM8903_VMID_SOFT_SHIFT) |
WM8903_VMID_RES_250K |
WM8903_VMID_BUF_ENA);
msleep(129);
snd_soc_update_bits(codec, WM8903_POWER_MANAGEMENT_5,
WM8903_SPKL_ENA | WM8903_SPKR_ENA,
0);
snd_soc_update_bits(codec, WM8903_VMID_CONTROL_0,
WM8903_VMID_SOFT_MASK, 0);
snd_soc_update_bits(codec, WM8903_VMID_CONTROL_0,
WM8903_VMID_RES_MASK,
WM8903_VMID_RES_50K);
snd_soc_update_bits(codec, WM8903_BIAS_CONTROL_0,
WM8903_BIAS_ENA | WM8903_POBCTRL,
WM8903_BIAS_ENA);
dev_dbg(codec->dev, "Enabling Class W\n");
snd_soc_update_bits(codec, WM8903_CLASS_W_0,
WM8903_CP_DYN_FREQ |
WM8903_CP_DYN_V,
WM8903_CP_DYN_FREQ |
WM8903_CP_DYN_V);
}
snd_soc_update_bits(codec, WM8903_VMID_CONTROL_0,
WM8903_VMID_RES_MASK,
WM8903_VMID_RES_250K);
break;
case SND_SOC_BIAS_OFF:
snd_soc_update_bits(codec, WM8903_BIAS_CONTROL_0,
WM8903_BIAS_ENA, 0);
snd_soc_update_bits(codec, WM8903_VMID_CONTROL_0,
WM8903_VMID_SOFT_MASK,
2 << WM8903_VMID_SOFT_SHIFT);
snd_soc_update_bits(codec, WM8903_VMID_CONTROL_0,
WM8903_VMID_BUF_ENA, 0);
msleep(290);
snd_soc_update_bits(codec, WM8903_VMID_CONTROL_0,
WM8903_VMID_TIE_ENA | WM8903_BUFIO_ENA |
WM8903_VMID_IO_ENA | WM8903_VMID_RES_MASK |
WM8903_VMID_SOFT_MASK |
WM8903_VMID_BUF_ENA, 0);
snd_soc_update_bits(codec, WM8903_BIAS_CONTROL_0,
WM8903_STARTUP_BIAS_ENA, 0);
break;
}
return 0;
}
static int wm8903_set_dai_sysclk(struct snd_soc_dai *codec_dai,
int clk_id, unsigned int freq, int dir)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct wm8903_priv *wm8903 = snd_soc_codec_get_drvdata(codec);
wm8903->sysclk = freq;
return 0;
}
static int wm8903_set_dai_fmt(struct snd_soc_dai *codec_dai,
unsigned int fmt)
{
struct snd_soc_codec *codec = codec_dai->codec;
u16 aif1 = snd_soc_read(codec, WM8903_AUDIO_INTERFACE_1);
aif1 &= ~(WM8903_LRCLK_DIR | WM8903_BCLK_DIR | WM8903_AIF_FMT_MASK |
WM8903_AIF_LRCLK_INV | WM8903_AIF_BCLK_INV);
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBS_CFS:
break;
case SND_SOC_DAIFMT_CBS_CFM:
aif1 |= WM8903_LRCLK_DIR;
break;
case SND_SOC_DAIFMT_CBM_CFM:
aif1 |= WM8903_LRCLK_DIR | WM8903_BCLK_DIR;
break;
case SND_SOC_DAIFMT_CBM_CFS:
aif1 |= WM8903_BCLK_DIR;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_DSP_A:
aif1 |= 0x3;
break;
case SND_SOC_DAIFMT_DSP_B:
aif1 |= 0x3 | WM8903_AIF_LRCLK_INV;
break;
case SND_SOC_DAIFMT_I2S:
aif1 |= 0x2;
break;
case SND_SOC_DAIFMT_RIGHT_J:
aif1 |= 0x1;
break;
case SND_SOC_DAIFMT_LEFT_J:
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
aif1 |= WM8903_AIF_BCLK_INV;
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
aif1 |= WM8903_AIF_BCLK_INV | WM8903_AIF_LRCLK_INV;
break;
case SND_SOC_DAIFMT_IB_NF:
aif1 |= WM8903_AIF_BCLK_INV;
break;
case SND_SOC_DAIFMT_NB_IF:
aif1 |= WM8903_AIF_LRCLK_INV;
break;
default:
return -EINVAL;
}
break;
default:
return -EINVAL;
}
snd_soc_write(codec, WM8903_AUDIO_INTERFACE_1, aif1);
return 0;
}
static int wm8903_digital_mute(struct snd_soc_dai *codec_dai, int mute)
{
struct snd_soc_codec *codec = codec_dai->codec;
u16 reg;
reg = snd_soc_read(codec, WM8903_DAC_DIGITAL_1);
if (mute)
reg |= WM8903_DAC_MUTE;
else
reg &= ~WM8903_DAC_MUTE;
snd_soc_write(codec, WM8903_DAC_DIGITAL_1, reg);
return 0;
}
static int wm8903_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct wm8903_priv *wm8903 = snd_soc_codec_get_drvdata(codec);
int fs = params_rate(params);
int bclk;
int bclk_div;
int i;
int dsp_config;
int clk_config;
int best_val;
int cur_val;
int clk_sys;
u16 aif1 = snd_soc_read(codec, WM8903_AUDIO_INTERFACE_1);
u16 aif2 = snd_soc_read(codec, WM8903_AUDIO_INTERFACE_2);
u16 aif3 = snd_soc_read(codec, WM8903_AUDIO_INTERFACE_3);
u16 clock0 = snd_soc_read(codec, WM8903_CLOCK_RATES_0);
u16 clock1 = snd_soc_read(codec, WM8903_CLOCK_RATES_1);
u16 dac_digital1 = snd_soc_read(codec, WM8903_DAC_DIGITAL_1);
if (fs <= 24000)
dac_digital1 |= WM8903_DAC_SB_FILT;
else
dac_digital1 &= ~WM8903_DAC_SB_FILT;
dsp_config = 0;
best_val = abs(sample_rates[dsp_config].rate - fs);
for (i = 1; i < ARRAY_SIZE(sample_rates); i++) {
cur_val = abs(sample_rates[i].rate - fs);
if (cur_val <= best_val) {
dsp_config = i;
best_val = cur_val;
}
}
dev_dbg(codec->dev, "DSP fs = %dHz\n", sample_rates[dsp_config].rate);
clock1 &= ~WM8903_SAMPLE_RATE_MASK;
clock1 |= sample_rates[dsp_config].value;
aif1 &= ~WM8903_AIF_WL_MASK;
bclk = 2 * fs;
switch (params_width(params)) {
case 16:
bclk *= 16;
break;
case 20:
bclk *= 20;
aif1 |= 0x4;
break;
case 24:
bclk *= 24;
aif1 |= 0x8;
break;
case 32:
bclk *= 32;
aif1 |= 0xc;
break;
default:
return -EINVAL;
}
dev_dbg(codec->dev, "MCLK = %dHz, target sample rate = %dHz\n",
wm8903->sysclk, fs);
clk_config = 0;
best_val = abs((wm8903->sysclk /
(clk_sys_ratios[0].mclk_div *
clk_sys_ratios[0].div)) - fs);
for (i = 1; i < ARRAY_SIZE(clk_sys_ratios); i++) {
cur_val = abs((wm8903->sysclk /
(clk_sys_ratios[i].mclk_div *
clk_sys_ratios[i].div)) - fs);
if (cur_val <= best_val) {
clk_config = i;
best_val = cur_val;
}
}
if (clk_sys_ratios[clk_config].mclk_div == 2) {
clock0 |= WM8903_MCLKDIV2;
clk_sys = wm8903->sysclk / 2;
} else {
clock0 &= ~WM8903_MCLKDIV2;
clk_sys = wm8903->sysclk;
}
clock1 &= ~(WM8903_CLK_SYS_RATE_MASK |
WM8903_CLK_SYS_MODE_MASK);
clock1 |= clk_sys_ratios[clk_config].rate << WM8903_CLK_SYS_RATE_SHIFT;
clock1 |= clk_sys_ratios[clk_config].mode << WM8903_CLK_SYS_MODE_SHIFT;
dev_dbg(codec->dev, "CLK_SYS_RATE=%x, CLK_SYS_MODE=%x div=%d\n",
clk_sys_ratios[clk_config].rate,
clk_sys_ratios[clk_config].mode,
clk_sys_ratios[clk_config].div);
dev_dbg(codec->dev, "Actual CLK_SYS = %dHz\n", clk_sys);
bclk_div = 0;
best_val = ((clk_sys * 10) / bclk_divs[0].ratio) - bclk;
i = 1;
while (i < ARRAY_SIZE(bclk_divs)) {
cur_val = ((clk_sys * 10) / bclk_divs[i].ratio) - bclk;
if (cur_val < 0)
break;
bclk_div = i;
best_val = cur_val;
i++;
}
aif2 &= ~WM8903_BCLK_DIV_MASK;
aif3 &= ~WM8903_LRCLK_RATE_MASK;
dev_dbg(codec->dev, "BCLK ratio %d for %dHz - actual BCLK = %dHz\n",
bclk_divs[bclk_div].ratio / 10, bclk,
(clk_sys * 10) / bclk_divs[bclk_div].ratio);
aif2 |= bclk_divs[bclk_div].div;
aif3 |= bclk / fs;
wm8903->fs = params_rate(params);
wm8903_set_deemph(codec);
snd_soc_write(codec, WM8903_CLOCK_RATES_0, clock0);
snd_soc_write(codec, WM8903_CLOCK_RATES_1, clock1);
snd_soc_write(codec, WM8903_AUDIO_INTERFACE_1, aif1);
snd_soc_write(codec, WM8903_AUDIO_INTERFACE_2, aif2);
snd_soc_write(codec, WM8903_AUDIO_INTERFACE_3, aif3);
snd_soc_write(codec, WM8903_DAC_DIGITAL_1, dac_digital1);
return 0;
}
int wm8903_mic_detect(struct snd_soc_codec *codec, struct snd_soc_jack *jack,
int det, int shrt)
{
struct wm8903_priv *wm8903 = snd_soc_codec_get_drvdata(codec);
int irq_mask = WM8903_MICDET_EINT | WM8903_MICSHRT_EINT;
dev_dbg(codec->dev, "Enabling microphone detection: %x %x\n",
det, shrt);
wm8903->mic_jack = jack;
wm8903->mic_det = det;
wm8903->mic_short = shrt;
if (det)
irq_mask &= ~WM8903_MICDET_EINT;
if (shrt)
irq_mask &= ~WM8903_MICSHRT_EINT;
snd_soc_update_bits(codec, WM8903_INTERRUPT_STATUS_1_MASK,
WM8903_MICDET_EINT | WM8903_MICSHRT_EINT,
irq_mask);
if (det || shrt) {
snd_soc_update_bits(codec, WM8903_WRITE_SEQUENCER_0,
WM8903_WSEQ_ENA, WM8903_WSEQ_ENA);
snd_soc_update_bits(codec, WM8903_MIC_BIAS_CONTROL_0,
WM8903_MICDET_ENA, WM8903_MICDET_ENA);
} else {
snd_soc_update_bits(codec, WM8903_MIC_BIAS_CONTROL_0,
WM8903_MICDET_ENA, 0);
}
return 0;
}
static irqreturn_t wm8903_irq(int irq, void *data)
{
struct wm8903_priv *wm8903 = data;
int mic_report, ret;
unsigned int int_val, mask, int_pol;
ret = regmap_read(wm8903->regmap, WM8903_INTERRUPT_STATUS_1_MASK,
&mask);
if (ret != 0) {
dev_err(wm8903->dev, "Failed to read IRQ mask: %d\n", ret);
return IRQ_NONE;
}
ret = regmap_read(wm8903->regmap, WM8903_INTERRUPT_STATUS_1, &int_val);
if (ret != 0) {
dev_err(wm8903->dev, "Failed to read IRQ status: %d\n", ret);
return IRQ_NONE;
}
int_val &= ~mask;
if (int_val & WM8903_WSEQ_BUSY_EINT) {
dev_warn(wm8903->dev, "Write sequencer done\n");
}
mic_report = wm8903->mic_last_report;
ret = regmap_read(wm8903->regmap, WM8903_INTERRUPT_POLARITY_1,
&int_pol);
if (ret != 0) {
dev_err(wm8903->dev, "Failed to read interrupt polarity: %d\n",
ret);
return IRQ_HANDLED;
}
#ifndef CONFIG_SND_SOC_WM8903_MODULE
if (int_val & (WM8903_MICSHRT_EINT | WM8903_MICDET_EINT))
trace_snd_soc_jack_irq(dev_name(wm8903->dev));
#endif
if (int_val & WM8903_MICSHRT_EINT) {
dev_dbg(wm8903->dev, "Microphone short (pol=%x)\n", int_pol);
mic_report ^= wm8903->mic_short;
int_pol ^= WM8903_MICSHRT_INV;
}
if (int_val & WM8903_MICDET_EINT) {
dev_dbg(wm8903->dev, "Microphone detect (pol=%x)\n", int_pol);
mic_report ^= wm8903->mic_det;
int_pol ^= WM8903_MICDET_INV;
msleep(wm8903->mic_delay);
}
regmap_update_bits(wm8903->regmap, WM8903_INTERRUPT_POLARITY_1,
WM8903_MICSHRT_INV | WM8903_MICDET_INV, int_pol);
snd_soc_jack_report(wm8903->mic_jack, mic_report,
wm8903->mic_short | wm8903->mic_det);
wm8903->mic_last_report = mic_report;
return IRQ_HANDLED;
}
static int wm8903_resume(struct snd_soc_codec *codec)
{
struct wm8903_priv *wm8903 = snd_soc_codec_get_drvdata(codec);
regcache_sync(wm8903->regmap);
return 0;
}
static int wm8903_gpio_request(struct gpio_chip *chip, unsigned offset)
{
if (offset >= WM8903_NUM_GPIO)
return -EINVAL;
return 0;
}
static int wm8903_gpio_direction_in(struct gpio_chip *chip, unsigned offset)
{
struct wm8903_priv *wm8903 = gpiochip_get_data(chip);
unsigned int mask, val;
int ret;
mask = WM8903_GP1_FN_MASK | WM8903_GP1_DIR_MASK;
val = (WM8903_GPn_FN_GPIO_INPUT << WM8903_GP1_FN_SHIFT) |
WM8903_GP1_DIR;
ret = regmap_update_bits(wm8903->regmap,
WM8903_GPIO_CONTROL_1 + offset, mask, val);
if (ret < 0)
return ret;
return 0;
}
static int wm8903_gpio_get(struct gpio_chip *chip, unsigned offset)
{
struct wm8903_priv *wm8903 = gpiochip_get_data(chip);
unsigned int reg;
regmap_read(wm8903->regmap, WM8903_GPIO_CONTROL_1 + offset, &reg);
return !!((reg & WM8903_GP1_LVL_MASK) >> WM8903_GP1_LVL_SHIFT);
}
static int wm8903_gpio_direction_out(struct gpio_chip *chip,
unsigned offset, int value)
{
struct wm8903_priv *wm8903 = gpiochip_get_data(chip);
unsigned int mask, val;
int ret;
mask = WM8903_GP1_FN_MASK | WM8903_GP1_DIR_MASK | WM8903_GP1_LVL_MASK;
val = (WM8903_GPn_FN_GPIO_OUTPUT << WM8903_GP1_FN_SHIFT) |
(value << WM8903_GP2_LVL_SHIFT);
ret = regmap_update_bits(wm8903->regmap,
WM8903_GPIO_CONTROL_1 + offset, mask, val);
if (ret < 0)
return ret;
return 0;
}
static void wm8903_gpio_set(struct gpio_chip *chip, unsigned offset, int value)
{
struct wm8903_priv *wm8903 = gpiochip_get_data(chip);
regmap_update_bits(wm8903->regmap, WM8903_GPIO_CONTROL_1 + offset,
WM8903_GP1_LVL_MASK,
!!value << WM8903_GP1_LVL_SHIFT);
}
static void wm8903_init_gpio(struct wm8903_priv *wm8903)
{
struct wm8903_platform_data *pdata = wm8903->pdata;
int ret;
wm8903->gpio_chip = wm8903_template_chip;
wm8903->gpio_chip.ngpio = WM8903_NUM_GPIO;
wm8903->gpio_chip.parent = wm8903->dev;
if (pdata->gpio_base)
wm8903->gpio_chip.base = pdata->gpio_base;
else
wm8903->gpio_chip.base = -1;
ret = gpiochip_add_data(&wm8903->gpio_chip, wm8903);
if (ret != 0)
dev_err(wm8903->dev, "Failed to add GPIOs: %d\n", ret);
}
static void wm8903_free_gpio(struct wm8903_priv *wm8903)
{
gpiochip_remove(&wm8903->gpio_chip);
}
static void wm8903_init_gpio(struct wm8903_priv *wm8903)
{
}
static void wm8903_free_gpio(struct wm8903_priv *wm8903)
{
}
static int wm8903_set_pdata_irq_trigger(struct i2c_client *i2c,
struct wm8903_platform_data *pdata)
{
struct irq_data *irq_data = irq_get_irq_data(i2c->irq);
if (!irq_data) {
dev_err(&i2c->dev, "Invalid IRQ: %d\n",
i2c->irq);
return -EINVAL;
}
switch (irqd_get_trigger_type(irq_data)) {
case IRQ_TYPE_NONE:
default:
case IRQ_TYPE_LEVEL_HIGH:
pdata->irq_active_low = false;
break;
case IRQ_TYPE_LEVEL_LOW:
pdata->irq_active_low = true;
break;
}
return 0;
}
static int wm8903_set_pdata_from_of(struct i2c_client *i2c,
struct wm8903_platform_data *pdata)
{
const struct device_node *np = i2c->dev.of_node;
u32 val32;
int i;
if (of_property_read_u32(np, "micdet-cfg", &val32) >= 0)
pdata->micdet_cfg = val32;
if (of_property_read_u32(np, "micdet-delay", &val32) >= 0)
pdata->micdet_delay = val32;
if (of_property_read_u32_array(np, "gpio-cfg", pdata->gpio_cfg,
ARRAY_SIZE(pdata->gpio_cfg)) >= 0) {
for (i = 0; i < ARRAY_SIZE(pdata->gpio_cfg); i++) {
if (pdata->gpio_cfg[i] == 0) {
pdata->gpio_cfg[i] = WM8903_GPIO_CONFIG_ZERO;
} else if (pdata->gpio_cfg[i] == 0xffffffff) {
pdata->gpio_cfg[i] = 0;
} else if (pdata->gpio_cfg[i] > 0x7fff) {
dev_err(&i2c->dev, "Invalid gpio-cfg[%d] %x\n",
i, pdata->gpio_cfg[i]);
return -EINVAL;
}
}
}
return 0;
}
static int wm8903_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct wm8903_platform_data *pdata = dev_get_platdata(&i2c->dev);
struct wm8903_priv *wm8903;
int trigger;
bool mic_gpio = false;
unsigned int val, irq_pol;
int ret, i;
wm8903 = devm_kzalloc(&i2c->dev, sizeof(struct wm8903_priv),
GFP_KERNEL);
if (wm8903 == NULL)
return -ENOMEM;
mutex_init(&wm8903->lock);
wm8903->dev = &i2c->dev;
wm8903->regmap = devm_regmap_init_i2c(i2c, &wm8903_regmap);
if (IS_ERR(wm8903->regmap)) {
ret = PTR_ERR(wm8903->regmap);
dev_err(&i2c->dev, "Failed to allocate register map: %d\n",
ret);
return ret;
}
i2c_set_clientdata(i2c, wm8903);
if (pdata) {
wm8903->pdata = pdata;
} else {
wm8903->pdata = devm_kzalloc(&i2c->dev,
sizeof(struct wm8903_platform_data),
GFP_KERNEL);
if (wm8903->pdata == NULL) {
dev_err(&i2c->dev, "Failed to allocate pdata\n");
return -ENOMEM;
}
if (i2c->irq) {
ret = wm8903_set_pdata_irq_trigger(i2c, wm8903->pdata);
if (ret != 0)
return ret;
}
if (i2c->dev.of_node) {
ret = wm8903_set_pdata_from_of(i2c, wm8903->pdata);
if (ret != 0)
return ret;
}
}
pdata = wm8903->pdata;
ret = regmap_read(wm8903->regmap, WM8903_SW_RESET_AND_ID, &val);
if (ret != 0) {
dev_err(&i2c->dev, "Failed to read chip ID: %d\n", ret);
goto err;
}
if (val != 0x8903) {
dev_err(&i2c->dev, "Device with ID %x is not a WM8903\n", val);
ret = -ENODEV;
goto err;
}
ret = regmap_read(wm8903->regmap, WM8903_REVISION_NUMBER, &val);
if (ret != 0) {
dev_err(&i2c->dev, "Failed to read chip revision: %d\n", ret);
goto err;
}
dev_info(&i2c->dev, "WM8903 revision %c\n",
(val & WM8903_CHIP_REV_MASK) + 'A');
regmap_write(wm8903->regmap, WM8903_SW_RESET_AND_ID, 0x8903);
wm8903_init_gpio(wm8903);
for (i = 0; i < ARRAY_SIZE(pdata->gpio_cfg); i++) {
if ((!pdata->gpio_cfg[i]) ||
(pdata->gpio_cfg[i] > WM8903_GPIO_CONFIG_ZERO))
continue;
regmap_write(wm8903->regmap, WM8903_GPIO_CONTROL_1 + i,
pdata->gpio_cfg[i] & 0x7fff);
val = (pdata->gpio_cfg[i] & WM8903_GP1_FN_MASK)
>> WM8903_GP1_FN_SHIFT;
switch (val) {
case WM8903_GPn_FN_MICBIAS_CURRENT_DETECT:
case WM8903_GPn_FN_MICBIAS_SHORT_DETECT:
mic_gpio = true;
break;
default:
break;
}
}
regmap_write(wm8903->regmap, WM8903_MIC_BIAS_CONTROL_0,
pdata->micdet_cfg);
if (pdata->micdet_cfg)
regmap_update_bits(wm8903->regmap, WM8903_WRITE_SEQUENCER_0,
WM8903_WSEQ_ENA, WM8903_WSEQ_ENA);
WARN_ON(!mic_gpio && (pdata->micdet_cfg & WM8903_MICDET_ENA));
wm8903->mic_delay = pdata->micdet_delay;
if (i2c->irq) {
if (pdata->irq_active_low) {
trigger = IRQF_TRIGGER_LOW;
irq_pol = WM8903_IRQ_POL;
} else {
trigger = IRQF_TRIGGER_HIGH;
irq_pol = 0;
}
regmap_update_bits(wm8903->regmap, WM8903_INTERRUPT_CONTROL,
WM8903_IRQ_POL, irq_pol);
ret = request_threaded_irq(i2c->irq, NULL, wm8903_irq,
trigger | IRQF_ONESHOT,
"wm8903", wm8903);
if (ret != 0) {
dev_err(wm8903->dev, "Failed to request IRQ: %d\n",
ret);
return ret;
}
regmap_update_bits(wm8903->regmap,
WM8903_INTERRUPT_STATUS_1_MASK,
WM8903_IM_WSEQ_BUSY_EINT, 0);
}
regmap_update_bits(wm8903->regmap, WM8903_ADC_DIGITAL_VOLUME_LEFT,
WM8903_ADCVU, WM8903_ADCVU);
regmap_update_bits(wm8903->regmap, WM8903_ADC_DIGITAL_VOLUME_RIGHT,
WM8903_ADCVU, WM8903_ADCVU);
regmap_update_bits(wm8903->regmap, WM8903_DAC_DIGITAL_VOLUME_LEFT,
WM8903_DACVU, WM8903_DACVU);
regmap_update_bits(wm8903->regmap, WM8903_DAC_DIGITAL_VOLUME_RIGHT,
WM8903_DACVU, WM8903_DACVU);
regmap_update_bits(wm8903->regmap, WM8903_ANALOGUE_OUT1_LEFT,
WM8903_HPOUTVU, WM8903_HPOUTVU);
regmap_update_bits(wm8903->regmap, WM8903_ANALOGUE_OUT1_RIGHT,
WM8903_HPOUTVU, WM8903_HPOUTVU);
regmap_update_bits(wm8903->regmap, WM8903_ANALOGUE_OUT2_LEFT,
WM8903_LINEOUTVU, WM8903_LINEOUTVU);
regmap_update_bits(wm8903->regmap, WM8903_ANALOGUE_OUT2_RIGHT,
WM8903_LINEOUTVU, WM8903_LINEOUTVU);
regmap_update_bits(wm8903->regmap, WM8903_ANALOGUE_OUT3_LEFT,
WM8903_SPKVU, WM8903_SPKVU);
regmap_update_bits(wm8903->regmap, WM8903_ANALOGUE_OUT3_RIGHT,
WM8903_SPKVU, WM8903_SPKVU);
regmap_update_bits(wm8903->regmap, WM8903_DAC_DIGITAL_1,
WM8903_DAC_MUTEMODE | WM8903_DAC_MUTE,
WM8903_DAC_MUTEMODE | WM8903_DAC_MUTE);
ret = snd_soc_register_codec(&i2c->dev,
&soc_codec_dev_wm8903, &wm8903_dai, 1);
if (ret != 0)
goto err;
return 0;
err:
return ret;
}
static int wm8903_i2c_remove(struct i2c_client *client)
{
struct wm8903_priv *wm8903 = i2c_get_clientdata(client);
if (client->irq)
free_irq(client->irq, wm8903);
wm8903_free_gpio(wm8903);
snd_soc_unregister_codec(&client->dev);
return 0;
}
