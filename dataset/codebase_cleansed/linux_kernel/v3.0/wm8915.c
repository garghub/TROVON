static void wm8915_set_retune_mobile(struct snd_soc_codec *codec, int block)
{
struct wm8915_priv *wm8915 = snd_soc_codec_get_drvdata(codec);
struct wm8915_pdata *pdata = &wm8915->pdata;
int base, best, best_val, save, i, cfg, iface;
if (!wm8915->num_retune_mobile_texts)
return;
switch (block) {
case 0:
base = WM8915_DSP1_RX_EQ_GAINS_1;
if (snd_soc_read(codec, WM8915_POWER_MANAGEMENT_8) &
WM8915_DSP1RX_SRC)
iface = 1;
else
iface = 0;
break;
case 1:
base = WM8915_DSP1_RX_EQ_GAINS_2;
if (snd_soc_read(codec, WM8915_POWER_MANAGEMENT_8) &
WM8915_DSP2RX_SRC)
iface = 1;
else
iface = 0;
break;
default:
return;
}
cfg = wm8915->retune_mobile_cfg[block];
best = 0;
best_val = INT_MAX;
for (i = 0; i < pdata->num_retune_mobile_cfgs; i++) {
if (strcmp(pdata->retune_mobile_cfgs[i].name,
wm8915->retune_mobile_texts[cfg]) == 0 &&
abs(pdata->retune_mobile_cfgs[i].rate
- wm8915->rx_rate[iface]) < best_val) {
best = i;
best_val = abs(pdata->retune_mobile_cfgs[i].rate
- wm8915->rx_rate[iface]);
}
}
dev_dbg(codec->dev, "ReTune Mobile %d %s/%dHz for %dHz sample rate\n",
block,
pdata->retune_mobile_cfgs[best].name,
pdata->retune_mobile_cfgs[best].rate,
wm8915->rx_rate[iface]);
save = snd_soc_read(codec, base);
save &= WM8915_DSP1RX_EQ_ENA;
for (i = 0; i < ARRAY_SIZE(pdata->retune_mobile_cfgs[best].regs); i++)
snd_soc_update_bits(codec, base + i, 0xffff,
pdata->retune_mobile_cfgs[best].regs[i]);
snd_soc_update_bits(codec, base, WM8915_DSP1RX_EQ_ENA, save);
}
static int wm8915_get_retune_mobile_block(const char *name)
{
if (strcmp(name, "DSP1 EQ Mode") == 0)
return 0;
if (strcmp(name, "DSP2 EQ Mode") == 0)
return 1;
return -EINVAL;
}
static int wm8915_put_retune_mobile_enum(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_kcontrol_chip(kcontrol);
struct wm8915_priv *wm8915 = snd_soc_codec_get_drvdata(codec);
struct wm8915_pdata *pdata = &wm8915->pdata;
int block = wm8915_get_retune_mobile_block(kcontrol->id.name);
int value = ucontrol->value.integer.value[0];
if (block < 0)
return block;
if (value >= pdata->num_retune_mobile_cfgs)
return -EINVAL;
wm8915->retune_mobile_cfg[block] = value;
wm8915_set_retune_mobile(codec, block);
return 0;
}
static int wm8915_get_retune_mobile_enum(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_kcontrol_chip(kcontrol);
struct wm8915_priv *wm8915 = snd_soc_codec_get_drvdata(codec);
int block = wm8915_get_retune_mobile_block(kcontrol->id.name);
ucontrol->value.enumerated.item[0] = wm8915->retune_mobile_cfg[block];
return 0;
}
static int cp_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
switch (event) {
case SND_SOC_DAPM_POST_PMU:
msleep(5);
break;
default:
BUG();
return -EINVAL;
}
return 0;
}
static int rmv_short_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct wm8915_priv *wm8915 = snd_soc_codec_get_drvdata(w->codec);
switch (event) {
case SND_SOC_DAPM_PRE_PMD:
wm8915->hpout_pending &= ~w->shift;
break;
case SND_SOC_DAPM_PRE_PMU:
wm8915->hpout_pending |= w->shift;
break;
default:
BUG();
return -EINVAL;
}
return 0;
}
static void wait_for_dc_servo(struct snd_soc_codec *codec, u16 mask)
{
struct i2c_client *i2c = to_i2c_client(codec->dev);
struct wm8915_priv *wm8915 = snd_soc_codec_get_drvdata(codec);
int i, ret;
unsigned long timeout = 200;
snd_soc_write(codec, WM8915_DC_SERVO_2, mask);
do {
if (i2c->irq) {
timeout = wait_for_completion_timeout(&wm8915->dcs_done,
msecs_to_jiffies(200));
if (timeout == 0)
dev_err(codec->dev, "DC servo timed out\n");
} else {
msleep(1);
if (--i) {
timeout = 0;
break;
}
}
ret = snd_soc_read(codec, WM8915_DC_SERVO_2);
dev_dbg(codec->dev, "DC servo state: %x\n", ret);
} while (ret & mask);
if (timeout == 0)
dev_err(codec->dev, "DC servo timed out for %x\n", mask);
else
dev_dbg(codec->dev, "DC servo complete for %x\n", mask);
}
static void wm8915_seq_notifier(struct snd_soc_dapm_context *dapm,
enum snd_soc_dapm_type event, int subseq)
{
struct snd_soc_codec *codec = container_of(dapm,
struct snd_soc_codec, dapm);
struct wm8915_priv *wm8915 = snd_soc_codec_get_drvdata(codec);
u16 val, mask;
if (wm8915->dcs_pending) {
dev_dbg(codec->dev, "Starting DC servo for %x\n",
wm8915->dcs_pending);
wait_for_dc_servo(codec, wm8915->dcs_pending
<< WM8915_DCS_TRIG_STARTUP_0_SHIFT);
wm8915->dcs_pending = 0;
}
if (wm8915->hpout_pending != wm8915->hpout_ena) {
dev_dbg(codec->dev, "Applying RMV_SHORTs %x->%x\n",
wm8915->hpout_ena, wm8915->hpout_pending);
val = 0;
mask = 0;
if (wm8915->hpout_pending & HPOUT1L) {
val |= WM8915_HPOUT1L_RMV_SHORT;
mask |= WM8915_HPOUT1L_RMV_SHORT;
} else {
mask |= WM8915_HPOUT1L_RMV_SHORT |
WM8915_HPOUT1L_OUTP |
WM8915_HPOUT1L_DLY;
}
if (wm8915->hpout_pending & HPOUT1R) {
val |= WM8915_HPOUT1R_RMV_SHORT;
mask |= WM8915_HPOUT1R_RMV_SHORT;
} else {
mask |= WM8915_HPOUT1R_RMV_SHORT |
WM8915_HPOUT1R_OUTP |
WM8915_HPOUT1R_DLY;
}
snd_soc_update_bits(codec, WM8915_ANALOGUE_HP_1, mask, val);
val = 0;
mask = 0;
if (wm8915->hpout_pending & HPOUT2L) {
val |= WM8915_HPOUT2L_RMV_SHORT;
mask |= WM8915_HPOUT2L_RMV_SHORT;
} else {
mask |= WM8915_HPOUT2L_RMV_SHORT |
WM8915_HPOUT2L_OUTP |
WM8915_HPOUT2L_DLY;
}
if (wm8915->hpout_pending & HPOUT2R) {
val |= WM8915_HPOUT2R_RMV_SHORT;
mask |= WM8915_HPOUT2R_RMV_SHORT;
} else {
mask |= WM8915_HPOUT2R_RMV_SHORT |
WM8915_HPOUT2R_OUTP |
WM8915_HPOUT2R_DLY;
}
snd_soc_update_bits(codec, WM8915_ANALOGUE_HP_2, mask, val);
wm8915->hpout_ena = wm8915->hpout_pending;
}
}
static int dcs_start(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct wm8915_priv *wm8915 = snd_soc_codec_get_drvdata(w->codec);
switch (event) {
case SND_SOC_DAPM_POST_PMU:
wm8915->dcs_pending |= 1 << w->shift;
break;
default:
BUG();
return -EINVAL;
}
return 0;
}
static int wm8915_readable_register(struct snd_soc_codec *codec,
unsigned int reg)
{
switch (reg) {
case WM8915_SOFTWARE_RESET:
case WM8915_POWER_MANAGEMENT_1:
case WM8915_POWER_MANAGEMENT_2:
case WM8915_POWER_MANAGEMENT_3:
case WM8915_POWER_MANAGEMENT_4:
case WM8915_POWER_MANAGEMENT_5:
case WM8915_POWER_MANAGEMENT_6:
case WM8915_POWER_MANAGEMENT_7:
case WM8915_POWER_MANAGEMENT_8:
case WM8915_LEFT_LINE_INPUT_VOLUME:
case WM8915_RIGHT_LINE_INPUT_VOLUME:
case WM8915_LINE_INPUT_CONTROL:
case WM8915_DAC1_HPOUT1_VOLUME:
case WM8915_DAC2_HPOUT2_VOLUME:
case WM8915_DAC1_LEFT_VOLUME:
case WM8915_DAC1_RIGHT_VOLUME:
case WM8915_DAC2_LEFT_VOLUME:
case WM8915_DAC2_RIGHT_VOLUME:
case WM8915_OUTPUT1_LEFT_VOLUME:
case WM8915_OUTPUT1_RIGHT_VOLUME:
case WM8915_OUTPUT2_LEFT_VOLUME:
case WM8915_OUTPUT2_RIGHT_VOLUME:
case WM8915_MICBIAS_1:
case WM8915_MICBIAS_2:
case WM8915_LDO_1:
case WM8915_LDO_2:
case WM8915_ACCESSORY_DETECT_MODE_1:
case WM8915_ACCESSORY_DETECT_MODE_2:
case WM8915_HEADPHONE_DETECT_1:
case WM8915_HEADPHONE_DETECT_2:
case WM8915_MIC_DETECT_1:
case WM8915_MIC_DETECT_2:
case WM8915_MIC_DETECT_3:
case WM8915_CHARGE_PUMP_1:
case WM8915_CHARGE_PUMP_2:
case WM8915_DC_SERVO_1:
case WM8915_DC_SERVO_2:
case WM8915_DC_SERVO_3:
case WM8915_DC_SERVO_5:
case WM8915_DC_SERVO_6:
case WM8915_DC_SERVO_7:
case WM8915_DC_SERVO_READBACK_0:
case WM8915_ANALOGUE_HP_1:
case WM8915_ANALOGUE_HP_2:
case WM8915_CHIP_REVISION:
case WM8915_CONTROL_INTERFACE_1:
case WM8915_WRITE_SEQUENCER_CTRL_1:
case WM8915_WRITE_SEQUENCER_CTRL_2:
case WM8915_AIF_CLOCKING_1:
case WM8915_AIF_CLOCKING_2:
case WM8915_CLOCKING_1:
case WM8915_CLOCKING_2:
case WM8915_AIF_RATE:
case WM8915_FLL_CONTROL_1:
case WM8915_FLL_CONTROL_2:
case WM8915_FLL_CONTROL_3:
case WM8915_FLL_CONTROL_4:
case WM8915_FLL_CONTROL_5:
case WM8915_FLL_CONTROL_6:
case WM8915_FLL_EFS_1:
case WM8915_FLL_EFS_2:
case WM8915_AIF1_CONTROL:
case WM8915_AIF1_BCLK:
case WM8915_AIF1_TX_LRCLK_1:
case WM8915_AIF1_TX_LRCLK_2:
case WM8915_AIF1_RX_LRCLK_1:
case WM8915_AIF1_RX_LRCLK_2:
case WM8915_AIF1TX_DATA_CONFIGURATION_1:
case WM8915_AIF1TX_DATA_CONFIGURATION_2:
case WM8915_AIF1RX_DATA_CONFIGURATION:
case WM8915_AIF1TX_CHANNEL_0_CONFIGURATION:
case WM8915_AIF1TX_CHANNEL_1_CONFIGURATION:
case WM8915_AIF1TX_CHANNEL_2_CONFIGURATION:
case WM8915_AIF1TX_CHANNEL_3_CONFIGURATION:
case WM8915_AIF1TX_CHANNEL_4_CONFIGURATION:
case WM8915_AIF1TX_CHANNEL_5_CONFIGURATION:
case WM8915_AIF1RX_CHANNEL_0_CONFIGURATION:
case WM8915_AIF1RX_CHANNEL_1_CONFIGURATION:
case WM8915_AIF1RX_CHANNEL_2_CONFIGURATION:
case WM8915_AIF1RX_CHANNEL_3_CONFIGURATION:
case WM8915_AIF1RX_CHANNEL_4_CONFIGURATION:
case WM8915_AIF1RX_CHANNEL_5_CONFIGURATION:
case WM8915_AIF1RX_MONO_CONFIGURATION:
case WM8915_AIF1TX_TEST:
case WM8915_AIF2_CONTROL:
case WM8915_AIF2_BCLK:
case WM8915_AIF2_TX_LRCLK_1:
case WM8915_AIF2_TX_LRCLK_2:
case WM8915_AIF2_RX_LRCLK_1:
case WM8915_AIF2_RX_LRCLK_2:
case WM8915_AIF2TX_DATA_CONFIGURATION_1:
case WM8915_AIF2TX_DATA_CONFIGURATION_2:
case WM8915_AIF2RX_DATA_CONFIGURATION:
case WM8915_AIF2TX_CHANNEL_0_CONFIGURATION:
case WM8915_AIF2TX_CHANNEL_1_CONFIGURATION:
case WM8915_AIF2RX_CHANNEL_0_CONFIGURATION:
case WM8915_AIF2RX_CHANNEL_1_CONFIGURATION:
case WM8915_AIF2RX_MONO_CONFIGURATION:
case WM8915_AIF2TX_TEST:
case WM8915_DSP1_TX_LEFT_VOLUME:
case WM8915_DSP1_TX_RIGHT_VOLUME:
case WM8915_DSP1_RX_LEFT_VOLUME:
case WM8915_DSP1_RX_RIGHT_VOLUME:
case WM8915_DSP1_TX_FILTERS:
case WM8915_DSP1_RX_FILTERS_1:
case WM8915_DSP1_RX_FILTERS_2:
case WM8915_DSP1_DRC_1:
case WM8915_DSP1_DRC_2:
case WM8915_DSP1_DRC_3:
case WM8915_DSP1_DRC_4:
case WM8915_DSP1_DRC_5:
case WM8915_DSP1_RX_EQ_GAINS_1:
case WM8915_DSP1_RX_EQ_GAINS_2:
case WM8915_DSP1_RX_EQ_BAND_1_A:
case WM8915_DSP1_RX_EQ_BAND_1_B:
case WM8915_DSP1_RX_EQ_BAND_1_PG:
case WM8915_DSP1_RX_EQ_BAND_2_A:
case WM8915_DSP1_RX_EQ_BAND_2_B:
case WM8915_DSP1_RX_EQ_BAND_2_C:
case WM8915_DSP1_RX_EQ_BAND_2_PG:
case WM8915_DSP1_RX_EQ_BAND_3_A:
case WM8915_DSP1_RX_EQ_BAND_3_B:
case WM8915_DSP1_RX_EQ_BAND_3_C:
case WM8915_DSP1_RX_EQ_BAND_3_PG:
case WM8915_DSP1_RX_EQ_BAND_4_A:
case WM8915_DSP1_RX_EQ_BAND_4_B:
case WM8915_DSP1_RX_EQ_BAND_4_C:
case WM8915_DSP1_RX_EQ_BAND_4_PG:
case WM8915_DSP1_RX_EQ_BAND_5_A:
case WM8915_DSP1_RX_EQ_BAND_5_B:
case WM8915_DSP1_RX_EQ_BAND_5_PG:
case WM8915_DSP2_TX_LEFT_VOLUME:
case WM8915_DSP2_TX_RIGHT_VOLUME:
case WM8915_DSP2_RX_LEFT_VOLUME:
case WM8915_DSP2_RX_RIGHT_VOLUME:
case WM8915_DSP2_TX_FILTERS:
case WM8915_DSP2_RX_FILTERS_1:
case WM8915_DSP2_RX_FILTERS_2:
case WM8915_DSP2_DRC_1:
case WM8915_DSP2_DRC_2:
case WM8915_DSP2_DRC_3:
case WM8915_DSP2_DRC_4:
case WM8915_DSP2_DRC_5:
case WM8915_DSP2_RX_EQ_GAINS_1:
case WM8915_DSP2_RX_EQ_GAINS_2:
case WM8915_DSP2_RX_EQ_BAND_1_A:
case WM8915_DSP2_RX_EQ_BAND_1_B:
case WM8915_DSP2_RX_EQ_BAND_1_PG:
case WM8915_DSP2_RX_EQ_BAND_2_A:
case WM8915_DSP2_RX_EQ_BAND_2_B:
case WM8915_DSP2_RX_EQ_BAND_2_C:
case WM8915_DSP2_RX_EQ_BAND_2_PG:
case WM8915_DSP2_RX_EQ_BAND_3_A:
case WM8915_DSP2_RX_EQ_BAND_3_B:
case WM8915_DSP2_RX_EQ_BAND_3_C:
case WM8915_DSP2_RX_EQ_BAND_3_PG:
case WM8915_DSP2_RX_EQ_BAND_4_A:
case WM8915_DSP2_RX_EQ_BAND_4_B:
case WM8915_DSP2_RX_EQ_BAND_4_C:
case WM8915_DSP2_RX_EQ_BAND_4_PG:
case WM8915_DSP2_RX_EQ_BAND_5_A:
case WM8915_DSP2_RX_EQ_BAND_5_B:
case WM8915_DSP2_RX_EQ_BAND_5_PG:
case WM8915_DAC1_MIXER_VOLUMES:
case WM8915_DAC1_LEFT_MIXER_ROUTING:
case WM8915_DAC1_RIGHT_MIXER_ROUTING:
case WM8915_DAC2_MIXER_VOLUMES:
case WM8915_DAC2_LEFT_MIXER_ROUTING:
case WM8915_DAC2_RIGHT_MIXER_ROUTING:
case WM8915_DSP1_TX_LEFT_MIXER_ROUTING:
case WM8915_DSP1_TX_RIGHT_MIXER_ROUTING:
case WM8915_DSP2_TX_LEFT_MIXER_ROUTING:
case WM8915_DSP2_TX_RIGHT_MIXER_ROUTING:
case WM8915_DSP_TX_MIXER_SELECT:
case WM8915_DAC_SOFTMUTE:
case WM8915_OVERSAMPLING:
case WM8915_SIDETONE:
case WM8915_GPIO_1:
case WM8915_GPIO_2:
case WM8915_GPIO_3:
case WM8915_GPIO_4:
case WM8915_GPIO_5:
case WM8915_PULL_CONTROL_1:
case WM8915_PULL_CONTROL_2:
case WM8915_INTERRUPT_STATUS_1:
case WM8915_INTERRUPT_STATUS_2:
case WM8915_INTERRUPT_RAW_STATUS_2:
case WM8915_INTERRUPT_STATUS_1_MASK:
case WM8915_INTERRUPT_STATUS_2_MASK:
case WM8915_INTERRUPT_CONTROL:
case WM8915_LEFT_PDM_SPEAKER:
case WM8915_RIGHT_PDM_SPEAKER:
case WM8915_PDM_SPEAKER_MUTE_SEQUENCE:
case WM8915_PDM_SPEAKER_VOLUME:
return 1;
default:
return 0;
}
}
static int wm8915_volatile_register(struct snd_soc_codec *codec,
unsigned int reg)
{
switch (reg) {
case WM8915_SOFTWARE_RESET:
case WM8915_CHIP_REVISION:
case WM8915_LDO_1:
case WM8915_LDO_2:
case WM8915_INTERRUPT_STATUS_1:
case WM8915_INTERRUPT_STATUS_2:
case WM8915_INTERRUPT_RAW_STATUS_2:
case WM8915_DC_SERVO_READBACK_0:
case WM8915_DC_SERVO_2:
case WM8915_DC_SERVO_6:
case WM8915_DC_SERVO_7:
case WM8915_FLL_CONTROL_6:
case WM8915_MIC_DETECT_3:
case WM8915_HEADPHONE_DETECT_1:
case WM8915_HEADPHONE_DETECT_2:
return 1;
default:
return 0;
}
}
static int wm8915_reset(struct snd_soc_codec *codec)
{
return snd_soc_write(codec, WM8915_SOFTWARE_RESET, 0x8915);
}
static int wm8915_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
struct wm8915_priv *wm8915 = snd_soc_codec_get_drvdata(codec);
int ret;
switch (level) {
case SND_SOC_BIAS_ON:
break;
case SND_SOC_BIAS_PREPARE:
if (codec->dapm.bias_level == SND_SOC_BIAS_STANDBY) {
snd_soc_update_bits(codec, WM8915_POWER_MANAGEMENT_1,
WM8915_BG_ENA, WM8915_BG_ENA);
msleep(2);
}
break;
case SND_SOC_BIAS_STANDBY:
if (codec->dapm.bias_level == SND_SOC_BIAS_OFF) {
ret = regulator_bulk_enable(ARRAY_SIZE(wm8915->supplies),
wm8915->supplies);
if (ret != 0) {
dev_err(codec->dev,
"Failed to enable supplies: %d\n",
ret);
return ret;
}
if (wm8915->pdata.ldo_ena >= 0) {
gpio_set_value_cansleep(wm8915->pdata.ldo_ena,
1);
msleep(5);
}
codec->cache_only = false;
snd_soc_cache_sync(codec);
}
snd_soc_update_bits(codec, WM8915_POWER_MANAGEMENT_1,
WM8915_BG_ENA, 0);
break;
case SND_SOC_BIAS_OFF:
codec->cache_only = true;
if (wm8915->pdata.ldo_ena >= 0)
gpio_set_value_cansleep(wm8915->pdata.ldo_ena, 0);
regulator_bulk_disable(ARRAY_SIZE(wm8915->supplies),
wm8915->supplies);
break;
}
codec->dapm.bias_level = level;
return 0;
}
static int wm8915_set_fmt(struct snd_soc_dai *dai, unsigned int fmt)
{
struct snd_soc_codec *codec = dai->codec;
int aifctrl = 0;
int bclk = 0;
int lrclk_tx = 0;
int lrclk_rx = 0;
int aifctrl_reg, bclk_reg, lrclk_tx_reg, lrclk_rx_reg;
switch (dai->id) {
case 0:
aifctrl_reg = WM8915_AIF1_CONTROL;
bclk_reg = WM8915_AIF1_BCLK;
lrclk_tx_reg = WM8915_AIF1_TX_LRCLK_2;
lrclk_rx_reg = WM8915_AIF1_RX_LRCLK_2;
break;
case 1:
aifctrl_reg = WM8915_AIF2_CONTROL;
bclk_reg = WM8915_AIF2_BCLK;
lrclk_tx_reg = WM8915_AIF2_TX_LRCLK_2;
lrclk_rx_reg = WM8915_AIF2_RX_LRCLK_2;
break;
default:
BUG();
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
break;
case SND_SOC_DAIFMT_IB_NF:
bclk |= WM8915_AIF1_BCLK_INV;
break;
case SND_SOC_DAIFMT_NB_IF:
lrclk_tx |= WM8915_AIF1TX_LRCLK_INV;
lrclk_rx |= WM8915_AIF1RX_LRCLK_INV;
break;
case SND_SOC_DAIFMT_IB_IF:
bclk |= WM8915_AIF1_BCLK_INV;
lrclk_tx |= WM8915_AIF1TX_LRCLK_INV;
lrclk_rx |= WM8915_AIF1RX_LRCLK_INV;
break;
}
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBS_CFS:
break;
case SND_SOC_DAIFMT_CBS_CFM:
lrclk_tx |= WM8915_AIF1TX_LRCLK_MSTR;
lrclk_rx |= WM8915_AIF1RX_LRCLK_MSTR;
break;
case SND_SOC_DAIFMT_CBM_CFS:
bclk |= WM8915_AIF1_BCLK_MSTR;
break;
case SND_SOC_DAIFMT_CBM_CFM:
bclk |= WM8915_AIF1_BCLK_MSTR;
lrclk_tx |= WM8915_AIF1TX_LRCLK_MSTR;
lrclk_rx |= WM8915_AIF1RX_LRCLK_MSTR;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_DSP_A:
break;
case SND_SOC_DAIFMT_DSP_B:
aifctrl |= 1;
break;
case SND_SOC_DAIFMT_I2S:
aifctrl |= 2;
break;
case SND_SOC_DAIFMT_LEFT_J:
aifctrl |= 3;
break;
default:
return -EINVAL;
}
snd_soc_update_bits(codec, aifctrl_reg, WM8915_AIF1_FMT_MASK, aifctrl);
snd_soc_update_bits(codec, bclk_reg,
WM8915_AIF1_BCLK_INV | WM8915_AIF1_BCLK_MSTR,
bclk);
snd_soc_update_bits(codec, lrclk_tx_reg,
WM8915_AIF1TX_LRCLK_INV |
WM8915_AIF1TX_LRCLK_MSTR,
lrclk_tx);
snd_soc_update_bits(codec, lrclk_rx_reg,
WM8915_AIF1RX_LRCLK_INV |
WM8915_AIF1RX_LRCLK_MSTR,
lrclk_rx);
return 0;
}
static int wm8915_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct wm8915_priv *wm8915 = snd_soc_codec_get_drvdata(codec);
int bits, i, bclk_rate, best, cur_val;
int aifdata = 0;
int bclk = 0;
int lrclk = 0;
int dsp = 0;
int aifdata_reg, bclk_reg, lrclk_reg, dsp_shift;
if (!wm8915->sysclk) {
dev_err(codec->dev, "SYSCLK not configured\n");
return -EINVAL;
}
switch (dai->id) {
case 0:
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK ||
(snd_soc_read(codec, WM8915_GPIO_1)) & WM8915_GP1_FN_MASK) {
aifdata_reg = WM8915_AIF1RX_DATA_CONFIGURATION;
lrclk_reg = WM8915_AIF1_RX_LRCLK_1;
} else {
aifdata_reg = WM8915_AIF1TX_DATA_CONFIGURATION_1;
lrclk_reg = WM8915_AIF1_TX_LRCLK_1;
}
bclk_reg = WM8915_AIF1_BCLK;
dsp_shift = 0;
break;
case 1:
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK ||
(snd_soc_read(codec, WM8915_GPIO_2)) & WM8915_GP2_FN_MASK) {
aifdata_reg = WM8915_AIF2RX_DATA_CONFIGURATION;
lrclk_reg = WM8915_AIF2_RX_LRCLK_1;
} else {
aifdata_reg = WM8915_AIF2TX_DATA_CONFIGURATION_1;
lrclk_reg = WM8915_AIF2_TX_LRCLK_1;
}
bclk_reg = WM8915_AIF2_BCLK;
dsp_shift = WM8915_DSP2_DIV_SHIFT;
break;
default:
BUG();
return -EINVAL;
}
bclk_rate = snd_soc_params_to_bclk(params);
if (bclk_rate < 0) {
dev_err(codec->dev, "Unsupported BCLK rate: %d\n", bclk_rate);
return bclk_rate;
}
bits = snd_pcm_format_width(params_format(params));
if (bits < 0)
return bits;
aifdata |= (bits << WM8915_AIF1TX_WL_SHIFT) | bits;
for (i = 0; i < ARRAY_SIZE(dsp_divs); i++) {
if (dsp_divs[i] == params_rate(params))
break;
}
if (i == ARRAY_SIZE(dsp_divs)) {
dev_err(codec->dev, "Unsupported sample rate %dHz\n",
params_rate(params));
return -EINVAL;
}
dsp |= i << dsp_shift;
best = 0;
for (i = 0; i < ARRAY_SIZE(bclk_divs); i++) {
cur_val = (wm8915->sysclk / bclk_divs[i]) - bclk_rate;
if (cur_val < 0)
break;
best = i;
}
bclk_rate = wm8915->sysclk / bclk_divs[best];
dev_dbg(dai->dev, "Using BCLK_DIV %d for actual BCLK %dHz\n",
bclk_divs[best], bclk_rate);
bclk |= best;
lrclk = bclk_rate / params_rate(params);
dev_dbg(dai->dev, "Using LRCLK rate %d for actual LRCLK %dHz\n",
lrclk, bclk_rate / lrclk);
snd_soc_update_bits(codec, aifdata_reg,
WM8915_AIF1TX_WL_MASK |
WM8915_AIF1TX_SLOT_LEN_MASK,
aifdata);
snd_soc_update_bits(codec, bclk_reg, WM8915_AIF1_BCLK_DIV_MASK, bclk);
snd_soc_update_bits(codec, lrclk_reg, WM8915_AIF1RX_RATE_MASK,
lrclk);
snd_soc_update_bits(codec, WM8915_AIF_CLOCKING_2,
WM8915_DSP1_DIV_SHIFT << dsp_shift, dsp);
wm8915->rx_rate[dai->id] = params_rate(params);
return 0;
}
static int wm8915_set_sysclk(struct snd_soc_dai *dai,
int clk_id, unsigned int freq, int dir)
{
struct snd_soc_codec *codec = dai->codec;
struct wm8915_priv *wm8915 = snd_soc_codec_get_drvdata(codec);
int lfclk = 0;
int ratediv = 0;
int src;
int old;
old = snd_soc_read(codec, WM8915_AIF_CLOCKING_1) & WM8915_SYSCLK_ENA;
snd_soc_update_bits(codec, WM8915_AIF_CLOCKING_1,
WM8915_SYSCLK_ENA, 0);
switch (clk_id) {
case WM8915_SYSCLK_MCLK1:
wm8915->sysclk = freq;
src = 0;
break;
case WM8915_SYSCLK_MCLK2:
wm8915->sysclk = freq;
src = 1;
break;
case WM8915_SYSCLK_FLL:
wm8915->sysclk = freq;
src = 2;
break;
default:
dev_err(codec->dev, "Unsupported clock source %d\n", clk_id);
return -EINVAL;
}
switch (wm8915->sysclk) {
case 6144000:
snd_soc_update_bits(codec, WM8915_AIF_RATE,
WM8915_SYSCLK_RATE, 0);
break;
case 24576000:
ratediv = WM8915_SYSCLK_DIV;
case 12288000:
snd_soc_update_bits(codec, WM8915_AIF_RATE,
WM8915_SYSCLK_RATE, WM8915_SYSCLK_RATE);
break;
case 32000:
case 32768:
lfclk = WM8915_LFCLK_ENA;
break;
default:
dev_warn(codec->dev, "Unsupported clock rate %dHz\n",
wm8915->sysclk);
return -EINVAL;
}
snd_soc_update_bits(codec, WM8915_AIF_CLOCKING_1,
WM8915_SYSCLK_SRC_MASK | WM8915_SYSCLK_DIV_MASK,
src << WM8915_SYSCLK_SRC_SHIFT | ratediv);
snd_soc_update_bits(codec, WM8915_CLOCKING_1, WM8915_LFCLK_ENA, lfclk);
snd_soc_update_bits(codec, WM8915_AIF_CLOCKING_1,
WM8915_SYSCLK_ENA, old);
return 0;
}
static int fll_factors(struct _fll_div *fll_div, unsigned int Fref,
unsigned int Fout)
{
unsigned int target;
unsigned int div;
unsigned int fratio, gcd_fll;
int i;
div = 1;
fll_div->fll_refclk_div = 0;
while ((Fref / div) > 13500000) {
div *= 2;
fll_div->fll_refclk_div++;
if (div > 8) {
pr_err("Can't scale %dMHz input down to <=13.5MHz\n",
Fref);
return -EINVAL;
}
}
pr_debug("FLL Fref=%u Fout=%u\n", Fref, Fout);
Fref /= div;
if (Fref >= 3000000)
fll_div->fll_loop_gain = 5;
else
fll_div->fll_loop_gain = 0;
if (Fref >= 48000)
fll_div->fll_ref_freq = 0;
else
fll_div->fll_ref_freq = 1;
div = 2;
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
pr_debug("FLL Fvco=%dHz\n", target);
for (i = 0; i < ARRAY_SIZE(fll_fratios); i++) {
if (fll_fratios[i].min <= Fref && Fref <= fll_fratios[i].max) {
fll_div->fll_fratio = fll_fratios[i].fll_fratio;
fratio = fll_fratios[i].ratio;
break;
}
}
if (i == ARRAY_SIZE(fll_fratios)) {
pr_err("Unable to find FLL_FRATIO for Fref=%uHz\n", Fref);
return -EINVAL;
}
fll_div->n = target / (fratio * Fref);
if (target % Fref == 0) {
fll_div->theta = 0;
fll_div->lambda = 0;
} else {
gcd_fll = gcd(target, fratio * Fref);
fll_div->theta = (target - (fll_div->n * fratio * Fref))
/ gcd_fll;
fll_div->lambda = (fratio * Fref) / gcd_fll;
}
pr_debug("FLL N=%x THETA=%x LAMBDA=%x\n",
fll_div->n, fll_div->theta, fll_div->lambda);
pr_debug("FLL_FRATIO=%x FLL_OUTDIV=%x FLL_REFCLK_DIV=%x\n",
fll_div->fll_fratio, fll_div->fll_outdiv,
fll_div->fll_refclk_div);
return 0;
}
static int wm8915_set_fll(struct snd_soc_codec *codec, int fll_id, int source,
unsigned int Fref, unsigned int Fout)
{
struct wm8915_priv *wm8915 = snd_soc_codec_get_drvdata(codec);
struct _fll_div fll_div;
unsigned long timeout;
int ret, reg;
if (source == wm8915->fll_src && Fref == wm8915->fll_fref &&
Fout == wm8915->fll_fout)
return 0;
if (Fout == 0) {
dev_dbg(codec->dev, "FLL disabled\n");
wm8915->fll_fref = 0;
wm8915->fll_fout = 0;
snd_soc_update_bits(codec, WM8915_FLL_CONTROL_1,
WM8915_FLL_ENA, 0);
return 0;
}
ret = fll_factors(&fll_div, Fref, Fout);
if (ret != 0)
return ret;
switch (source) {
case WM8915_FLL_MCLK1:
reg = 0;
break;
case WM8915_FLL_MCLK2:
reg = 1;
break;
case WM8915_FLL_DACLRCLK1:
reg = 2;
break;
case WM8915_FLL_BCLK1:
reg = 3;
break;
default:
dev_err(codec->dev, "Unknown FLL source %d\n", ret);
return -EINVAL;
}
reg |= fll_div.fll_refclk_div << WM8915_FLL_REFCLK_DIV_SHIFT;
reg |= fll_div.fll_ref_freq << WM8915_FLL_REF_FREQ_SHIFT;
snd_soc_update_bits(codec, WM8915_FLL_CONTROL_5,
WM8915_FLL_REFCLK_DIV_MASK | WM8915_FLL_REF_FREQ |
WM8915_FLL_REFCLK_SRC_MASK, reg);
reg = 0;
if (fll_div.theta || fll_div.lambda)
reg |= WM8915_FLL_EFS_ENA | (3 << WM8915_FLL_LFSR_SEL_SHIFT);
else
reg |= 1 << WM8915_FLL_LFSR_SEL_SHIFT;
snd_soc_write(codec, WM8915_FLL_EFS_2, reg);
snd_soc_update_bits(codec, WM8915_FLL_CONTROL_2,
WM8915_FLL_OUTDIV_MASK |
WM8915_FLL_FRATIO_MASK,
(fll_div.fll_outdiv << WM8915_FLL_OUTDIV_SHIFT) |
(fll_div.fll_fratio));
snd_soc_write(codec, WM8915_FLL_CONTROL_3, fll_div.theta);
snd_soc_update_bits(codec, WM8915_FLL_CONTROL_4,
WM8915_FLL_N_MASK | WM8915_FLL_LOOP_GAIN_MASK,
(fll_div.n << WM8915_FLL_N_SHIFT) |
fll_div.fll_loop_gain);
snd_soc_write(codec, WM8915_FLL_EFS_1, fll_div.lambda);
snd_soc_update_bits(codec, WM8915_FLL_CONTROL_1,
WM8915_FLL_ENA, WM8915_FLL_ENA);
snd_soc_write(codec, WM8915_FLL_CONTROL_6, WM8915_FLL_SWITCH_CLK);
if (Fref > 1000000)
timeout = usecs_to_jiffies(300);
else
timeout = msecs_to_jiffies(2);
wait_for_completion_timeout(&wm8915->fll_lock, timeout);
dev_dbg(codec->dev, "FLL configured for %dHz->%dHz\n", Fref, Fout);
wm8915->fll_fref = Fref;
wm8915->fll_fout = Fout;
wm8915->fll_src = source;
return 0;
}
static inline struct wm8915_priv *gpio_to_wm8915(struct gpio_chip *chip)
{
return container_of(chip, struct wm8915_priv, gpio_chip);
}
static void wm8915_gpio_set(struct gpio_chip *chip, unsigned offset, int value)
{
struct wm8915_priv *wm8915 = gpio_to_wm8915(chip);
struct snd_soc_codec *codec = wm8915->codec;
snd_soc_update_bits(codec, WM8915_GPIO_1 + offset,
WM8915_GP1_LVL, !!value << WM8915_GP1_LVL_SHIFT);
}
static int wm8915_gpio_direction_out(struct gpio_chip *chip,
unsigned offset, int value)
{
struct wm8915_priv *wm8915 = gpio_to_wm8915(chip);
struct snd_soc_codec *codec = wm8915->codec;
int val;
val = (1 << WM8915_GP1_FN_SHIFT) | (!!value << WM8915_GP1_LVL_SHIFT);
return snd_soc_update_bits(codec, WM8915_GPIO_1 + offset,
WM8915_GP1_FN_MASK | WM8915_GP1_DIR |
WM8915_GP1_LVL, val);
}
static int wm8915_gpio_get(struct gpio_chip *chip, unsigned offset)
{
struct wm8915_priv *wm8915 = gpio_to_wm8915(chip);
struct snd_soc_codec *codec = wm8915->codec;
int ret;
ret = snd_soc_read(codec, WM8915_GPIO_1 + offset);
if (ret < 0)
return ret;
return (ret & WM8915_GP1_LVL) != 0;
}
static int wm8915_gpio_direction_in(struct gpio_chip *chip, unsigned offset)
{
struct wm8915_priv *wm8915 = gpio_to_wm8915(chip);
struct snd_soc_codec *codec = wm8915->codec;
return snd_soc_update_bits(codec, WM8915_GPIO_1 + offset,
WM8915_GP1_FN_MASK | WM8915_GP1_DIR,
(1 << WM8915_GP1_FN_SHIFT) |
(1 << WM8915_GP1_DIR_SHIFT));
}
static void wm8915_init_gpio(struct snd_soc_codec *codec)
{
struct wm8915_priv *wm8915 = snd_soc_codec_get_drvdata(codec);
int ret;
wm8915->gpio_chip = wm8915_template_chip;
wm8915->gpio_chip.ngpio = 5;
wm8915->gpio_chip.dev = codec->dev;
if (wm8915->pdata.gpio_base)
wm8915->gpio_chip.base = wm8915->pdata.gpio_base;
else
wm8915->gpio_chip.base = -1;
ret = gpiochip_add(&wm8915->gpio_chip);
if (ret != 0)
dev_err(codec->dev, "Failed to add GPIOs: %d\n", ret);
}
static void wm8915_free_gpio(struct snd_soc_codec *codec)
{
struct wm8915_priv *wm8915 = snd_soc_codec_get_drvdata(codec);
int ret;
ret = gpiochip_remove(&wm8915->gpio_chip);
if (ret != 0)
dev_err(codec->dev, "Failed to remove GPIOs: %d\n", ret);
}
static void wm8915_init_gpio(struct snd_soc_codec *codec)
{
}
static void wm8915_free_gpio(struct snd_soc_codec *codec)
{
}
int wm8915_detect(struct snd_soc_codec *codec, struct snd_soc_jack *jack,
wm8915_polarity_fn polarity_cb)
{
struct wm8915_priv *wm8915 = snd_soc_codec_get_drvdata(codec);
wm8915->jack = jack;
wm8915->detecting = true;
wm8915->polarity_cb = polarity_cb;
if (wm8915->polarity_cb)
wm8915->polarity_cb(codec, 0);
snd_soc_update_bits(codec, WM8915_MICBIAS_1,
WM8915_MICB1_DISCH, 0);
snd_soc_update_bits(codec, WM8915_MICBIAS_2,
WM8915_MICB2_DISCH, 0);
snd_soc_dapm_force_enable_pin(&codec->dapm, "LDO2");
snd_soc_dapm_force_enable_pin(&codec->dapm, "SYSCLK");
snd_soc_update_bits(codec, WM8915_MIC_DETECT_1,
WM8915_MICD_ENA, WM8915_MICD_ENA);
snd_soc_update_bits(codec, WM8915_MIC_DETECT_1,
WM8915_MICD_RATE_MASK,
WM8915_MICD_RATE_MASK);
snd_soc_update_bits(codec, WM8915_INTERRUPT_STATUS_2_MASK,
WM8915_IM_MICD_EINT, 0);
return 0;
}
static void wm8915_micd(struct snd_soc_codec *codec)
{
struct wm8915_priv *wm8915 = snd_soc_codec_get_drvdata(codec);
int val, reg;
val = snd_soc_read(codec, WM8915_MIC_DETECT_3);
dev_dbg(codec->dev, "Microphone event: %x\n", val);
if (!(val & WM8915_MICD_VALID)) {
dev_warn(codec->dev, "Microphone detection state invalid\n");
return;
}
if (!(val & WM8915_MICD_STS)) {
dev_dbg(codec->dev, "Jack removal detected\n");
wm8915->jack_mic = false;
wm8915->detecting = true;
snd_soc_jack_report(wm8915->jack, 0,
SND_JACK_HEADSET | SND_JACK_BTN_0);
snd_soc_update_bits(codec, WM8915_MIC_DETECT_1,
WM8915_MICD_RATE_MASK,
WM8915_MICD_RATE_MASK);
return;
}
if (val & 0x400) {
dev_dbg(codec->dev, "Microphone detected\n");
snd_soc_jack_report(wm8915->jack, SND_JACK_HEADSET,
SND_JACK_HEADSET | SND_JACK_BTN_0);
wm8915->jack_mic = true;
wm8915->detecting = false;
}
if (wm8915->detecting && (val & 0x3f0)) {
reg = snd_soc_read(codec, WM8915_ACCESSORY_DETECT_MODE_2);
reg ^= WM8915_HPOUT1FB_SRC | WM8915_MICD_SRC |
WM8915_MICD_BIAS_SRC;
snd_soc_update_bits(codec, WM8915_ACCESSORY_DETECT_MODE_2,
WM8915_HPOUT1FB_SRC | WM8915_MICD_SRC |
WM8915_MICD_BIAS_SRC, reg);
if (wm8915->polarity_cb)
wm8915->polarity_cb(codec,
(reg & WM8915_MICD_SRC) != 0);
dev_dbg(codec->dev, "Set microphone polarity to %d\n",
(reg & WM8915_MICD_SRC) != 0);
return;
}
if (val & 0x3fc) {
if (wm8915->jack_mic) {
dev_dbg(codec->dev, "Mic button detected\n");
snd_soc_jack_report(wm8915->jack,
SND_JACK_HEADSET | SND_JACK_BTN_0,
SND_JACK_HEADSET | SND_JACK_BTN_0);
} else {
dev_dbg(codec->dev, "Headphone detected\n");
snd_soc_jack_report(wm8915->jack,
SND_JACK_HEADPHONE,
SND_JACK_HEADSET |
SND_JACK_BTN_0);
wm8915->detecting = false;
}
}
if (!wm8915->detecting)
snd_soc_update_bits(codec, WM8915_MIC_DETECT_1,
WM8915_MICD_RATE_MASK,
5 << WM8915_MICD_RATE_SHIFT);
}
static irqreturn_t wm8915_irq(int irq, void *data)
{
struct snd_soc_codec *codec = data;
struct wm8915_priv *wm8915 = snd_soc_codec_get_drvdata(codec);
int irq_val;
irq_val = snd_soc_read(codec, WM8915_INTERRUPT_STATUS_2);
if (irq_val < 0) {
dev_err(codec->dev, "Failed to read IRQ status: %d\n",
irq_val);
return IRQ_NONE;
}
irq_val &= ~snd_soc_read(codec, WM8915_INTERRUPT_STATUS_2_MASK);
if (irq_val & (WM8915_DCS_DONE_01_EINT | WM8915_DCS_DONE_23_EINT)) {
dev_dbg(codec->dev, "DC servo IRQ\n");
complete(&wm8915->dcs_done);
}
if (irq_val & WM8915_FIFOS_ERR_EINT)
dev_err(codec->dev, "Digital core FIFO error\n");
if (irq_val & WM8915_FLL_LOCK_EINT) {
dev_dbg(codec->dev, "FLL locked\n");
complete(&wm8915->fll_lock);
}
if (irq_val & WM8915_MICD_EINT)
wm8915_micd(codec);
if (irq_val) {
snd_soc_write(codec, WM8915_INTERRUPT_STATUS_2, irq_val);
return IRQ_HANDLED;
} else {
return IRQ_NONE;
}
}
static void wm8915_retune_mobile_pdata(struct snd_soc_codec *codec)
{
struct wm8915_priv *wm8915 = snd_soc_codec_get_drvdata(codec);
struct wm8915_pdata *pdata = &wm8915->pdata;
struct snd_kcontrol_new controls[] = {
SOC_ENUM_EXT("DSP1 EQ Mode",
wm8915->retune_mobile_enum,
wm8915_get_retune_mobile_enum,
wm8915_put_retune_mobile_enum),
SOC_ENUM_EXT("DSP2 EQ Mode",
wm8915->retune_mobile_enum,
wm8915_get_retune_mobile_enum,
wm8915_put_retune_mobile_enum),
};
int ret, i, j;
const char **t;
wm8915->num_retune_mobile_texts = 0;
wm8915->retune_mobile_texts = NULL;
for (i = 0; i < pdata->num_retune_mobile_cfgs; i++) {
for (j = 0; j < wm8915->num_retune_mobile_texts; j++) {
if (strcmp(pdata->retune_mobile_cfgs[i].name,
wm8915->retune_mobile_texts[j]) == 0)
break;
}
if (j != wm8915->num_retune_mobile_texts)
continue;
t = krealloc(wm8915->retune_mobile_texts,
sizeof(char *) *
(wm8915->num_retune_mobile_texts + 1),
GFP_KERNEL);
if (t == NULL)
continue;
t[wm8915->num_retune_mobile_texts] =
pdata->retune_mobile_cfgs[i].name;
wm8915->num_retune_mobile_texts++;
wm8915->retune_mobile_texts = t;
}
dev_dbg(codec->dev, "Allocated %d unique ReTune Mobile names\n",
wm8915->num_retune_mobile_texts);
wm8915->retune_mobile_enum.max = wm8915->num_retune_mobile_texts;
wm8915->retune_mobile_enum.texts = wm8915->retune_mobile_texts;
ret = snd_soc_add_controls(codec, controls, ARRAY_SIZE(controls));
if (ret != 0)
dev_err(codec->dev,
"Failed to add ReTune Mobile controls: %d\n", ret);
}
static int wm8915_probe(struct snd_soc_codec *codec)
{
int ret;
struct wm8915_priv *wm8915 = snd_soc_codec_get_drvdata(codec);
struct i2c_client *i2c = to_i2c_client(codec->dev);
struct snd_soc_dapm_context *dapm = &codec->dapm;
int i, irq_flags;
wm8915->codec = codec;
init_completion(&wm8915->dcs_done);
init_completion(&wm8915->fll_lock);
dapm->idle_bias_off = true;
dapm->bias_level = SND_SOC_BIAS_OFF;
ret = snd_soc_codec_set_cache_io(codec, 16, 16, SND_SOC_I2C);
if (ret != 0) {
dev_err(codec->dev, "Failed to set cache I/O: %d\n", ret);
goto err;
}
for (i = 0; i < ARRAY_SIZE(wm8915->supplies); i++)
wm8915->supplies[i].supply = wm8915_supply_names[i];
ret = regulator_bulk_get(codec->dev, ARRAY_SIZE(wm8915->supplies),
wm8915->supplies);
if (ret != 0) {
dev_err(codec->dev, "Failed to request supplies: %d\n", ret);
goto err;
}
wm8915->disable_nb[0].notifier_call = wm8915_regulator_event_0;
wm8915->disable_nb[1].notifier_call = wm8915_regulator_event_1;
wm8915->disable_nb[2].notifier_call = wm8915_regulator_event_2;
wm8915->disable_nb[3].notifier_call = wm8915_regulator_event_3;
wm8915->disable_nb[4].notifier_call = wm8915_regulator_event_4;
wm8915->disable_nb[5].notifier_call = wm8915_regulator_event_5;
for (i = 0; i < ARRAY_SIZE(wm8915->supplies); i++) {
ret = regulator_register_notifier(wm8915->supplies[i].consumer,
&wm8915->disable_nb[i]);
if (ret != 0) {
dev_err(codec->dev,
"Failed to register regulator notifier: %d\n",
ret);
}
}
ret = regulator_bulk_enable(ARRAY_SIZE(wm8915->supplies),
wm8915->supplies);
if (ret != 0) {
dev_err(codec->dev, "Failed to enable supplies: %d\n", ret);
goto err_get;
}
if (wm8915->pdata.ldo_ena >= 0) {
gpio_set_value_cansleep(wm8915->pdata.ldo_ena, 1);
msleep(5);
}
ret = snd_soc_read(codec, WM8915_SOFTWARE_RESET);
if (ret < 0) {
dev_err(codec->dev, "Failed to read ID register: %d\n", ret);
goto err_enable;
}
if (ret != 0x8915) {
dev_err(codec->dev, "Device is not a WM8915, ID %x\n", ret);
ret = -EINVAL;
goto err_enable;
}
ret = snd_soc_read(codec, WM8915_CHIP_REVISION);
if (ret < 0) {
dev_err(codec->dev, "Failed to read device revision: %d\n",
ret);
goto err_enable;
}
dev_info(codec->dev, "revision %c\n",
(ret & WM8915_CHIP_REV_MASK) + 'A');
if (wm8915->pdata.ldo_ena >= 0) {
gpio_set_value_cansleep(wm8915->pdata.ldo_ena, 0);
} else {
ret = wm8915_reset(codec);
if (ret < 0) {
dev_err(codec->dev, "Failed to issue reset\n");
goto err_enable;
}
}
codec->cache_only = true;
snd_soc_update_bits(codec, WM8915_LINE_INPUT_CONTROL,
WM8915_INL_MODE_MASK | WM8915_INR_MODE_MASK,
wm8915->pdata.inl_mode << WM8915_INL_MODE_SHIFT |
wm8915->pdata.inr_mode);
for (i = 0; i < ARRAY_SIZE(wm8915->pdata.gpio_default); i++) {
if (!wm8915->pdata.gpio_default[i])
continue;
snd_soc_write(codec, WM8915_GPIO_1 + i,
wm8915->pdata.gpio_default[i] & 0xffff);
}
if (wm8915->pdata.spkmute_seq)
snd_soc_update_bits(codec, WM8915_PDM_SPEAKER_MUTE_SEQUENCE,
WM8915_SPK_MUTE_ENDIAN |
WM8915_SPK_MUTE_SEQ1_MASK,
wm8915->pdata.spkmute_seq);
snd_soc_update_bits(codec, WM8915_ACCESSORY_DETECT_MODE_2,
WM8915_MICD_BIAS_SRC | WM8915_HPOUT1FB_SRC |
WM8915_MICD_SRC, wm8915->pdata.micdet_def);
snd_soc_update_bits(codec, WM8915_LEFT_LINE_INPUT_VOLUME,
WM8915_IN1_VU, WM8915_IN1_VU);
snd_soc_update_bits(codec, WM8915_RIGHT_LINE_INPUT_VOLUME,
WM8915_IN1_VU, WM8915_IN1_VU);
snd_soc_update_bits(codec, WM8915_DAC1_LEFT_VOLUME,
WM8915_DAC1_VU, WM8915_DAC1_VU);
snd_soc_update_bits(codec, WM8915_DAC1_RIGHT_VOLUME,
WM8915_DAC1_VU, WM8915_DAC1_VU);
snd_soc_update_bits(codec, WM8915_DAC2_LEFT_VOLUME,
WM8915_DAC2_VU, WM8915_DAC2_VU);
snd_soc_update_bits(codec, WM8915_DAC2_RIGHT_VOLUME,
WM8915_DAC2_VU, WM8915_DAC2_VU);
snd_soc_update_bits(codec, WM8915_OUTPUT1_LEFT_VOLUME,
WM8915_DAC1_VU, WM8915_DAC1_VU);
snd_soc_update_bits(codec, WM8915_OUTPUT1_RIGHT_VOLUME,
WM8915_DAC1_VU, WM8915_DAC1_VU);
snd_soc_update_bits(codec, WM8915_OUTPUT2_LEFT_VOLUME,
WM8915_DAC2_VU, WM8915_DAC2_VU);
snd_soc_update_bits(codec, WM8915_OUTPUT2_RIGHT_VOLUME,
WM8915_DAC2_VU, WM8915_DAC2_VU);
snd_soc_update_bits(codec, WM8915_DSP1_TX_LEFT_VOLUME,
WM8915_DSP1TX_VU, WM8915_DSP1TX_VU);
snd_soc_update_bits(codec, WM8915_DSP1_TX_RIGHT_VOLUME,
WM8915_DSP1TX_VU, WM8915_DSP1TX_VU);
snd_soc_update_bits(codec, WM8915_DSP2_TX_LEFT_VOLUME,
WM8915_DSP2TX_VU, WM8915_DSP2TX_VU);
snd_soc_update_bits(codec, WM8915_DSP2_TX_RIGHT_VOLUME,
WM8915_DSP2TX_VU, WM8915_DSP2TX_VU);
snd_soc_update_bits(codec, WM8915_DSP1_RX_LEFT_VOLUME,
WM8915_DSP1RX_VU, WM8915_DSP1RX_VU);
snd_soc_update_bits(codec, WM8915_DSP1_RX_RIGHT_VOLUME,
WM8915_DSP1RX_VU, WM8915_DSP1RX_VU);
snd_soc_update_bits(codec, WM8915_DSP2_RX_LEFT_VOLUME,
WM8915_DSP2RX_VU, WM8915_DSP2RX_VU);
snd_soc_update_bits(codec, WM8915_DSP2_RX_RIGHT_VOLUME,
WM8915_DSP2RX_VU, WM8915_DSP2RX_VU);
snd_soc_update_bits(codec, WM8915_AIF1RX_CHANNEL_0_CONFIGURATION,
WM8915_AIF1RX_CHAN0_SLOTS_MASK |
WM8915_AIF1RX_CHAN0_START_SLOT_MASK,
1 << WM8915_AIF1RX_CHAN0_SLOTS_SHIFT | 0);
snd_soc_update_bits(codec, WM8915_AIF1RX_CHANNEL_1_CONFIGURATION,
WM8915_AIF1RX_CHAN1_SLOTS_MASK |
WM8915_AIF1RX_CHAN1_START_SLOT_MASK,
1 << WM8915_AIF1RX_CHAN1_SLOTS_SHIFT | 1);
snd_soc_update_bits(codec, WM8915_AIF1RX_CHANNEL_2_CONFIGURATION,
WM8915_AIF1RX_CHAN2_SLOTS_MASK |
WM8915_AIF1RX_CHAN2_START_SLOT_MASK,
1 << WM8915_AIF1RX_CHAN2_SLOTS_SHIFT | 0);
snd_soc_update_bits(codec, WM8915_AIF1RX_CHANNEL_3_CONFIGURATION,
WM8915_AIF1RX_CHAN3_SLOTS_MASK |
WM8915_AIF1RX_CHAN0_START_SLOT_MASK,
1 << WM8915_AIF1RX_CHAN3_SLOTS_SHIFT | 1);
snd_soc_update_bits(codec, WM8915_AIF1RX_CHANNEL_4_CONFIGURATION,
WM8915_AIF1RX_CHAN4_SLOTS_MASK |
WM8915_AIF1RX_CHAN0_START_SLOT_MASK,
1 << WM8915_AIF1RX_CHAN4_SLOTS_SHIFT | 0);
snd_soc_update_bits(codec, WM8915_AIF1RX_CHANNEL_5_CONFIGURATION,
WM8915_AIF1RX_CHAN5_SLOTS_MASK |
WM8915_AIF1RX_CHAN0_START_SLOT_MASK,
1 << WM8915_AIF1RX_CHAN5_SLOTS_SHIFT | 1);
snd_soc_update_bits(codec, WM8915_AIF2RX_CHANNEL_0_CONFIGURATION,
WM8915_AIF2RX_CHAN0_SLOTS_MASK |
WM8915_AIF2RX_CHAN0_START_SLOT_MASK,
1 << WM8915_AIF2RX_CHAN0_SLOTS_SHIFT | 0);
snd_soc_update_bits(codec, WM8915_AIF2RX_CHANNEL_1_CONFIGURATION,
WM8915_AIF2RX_CHAN1_SLOTS_MASK |
WM8915_AIF2RX_CHAN1_START_SLOT_MASK,
1 << WM8915_AIF2RX_CHAN1_SLOTS_SHIFT | 1);
snd_soc_update_bits(codec, WM8915_AIF1TX_CHANNEL_0_CONFIGURATION,
WM8915_AIF1TX_CHAN0_SLOTS_MASK |
WM8915_AIF1TX_CHAN0_START_SLOT_MASK,
1 << WM8915_AIF1TX_CHAN0_SLOTS_SHIFT | 0);
snd_soc_update_bits(codec, WM8915_AIF1TX_CHANNEL_1_CONFIGURATION,
WM8915_AIF1TX_CHAN1_SLOTS_MASK |
WM8915_AIF1TX_CHAN0_START_SLOT_MASK,
1 << WM8915_AIF1TX_CHAN1_SLOTS_SHIFT | 1);
snd_soc_update_bits(codec, WM8915_AIF1TX_CHANNEL_2_CONFIGURATION,
WM8915_AIF1TX_CHAN2_SLOTS_MASK |
WM8915_AIF1TX_CHAN0_START_SLOT_MASK,
1 << WM8915_AIF1TX_CHAN2_SLOTS_SHIFT | 0);
snd_soc_update_bits(codec, WM8915_AIF1TX_CHANNEL_3_CONFIGURATION,
WM8915_AIF1TX_CHAN3_SLOTS_MASK |
WM8915_AIF1TX_CHAN0_START_SLOT_MASK,
1 << WM8915_AIF1TX_CHAN3_SLOTS_SHIFT | 1);
snd_soc_update_bits(codec, WM8915_AIF1TX_CHANNEL_4_CONFIGURATION,
WM8915_AIF1TX_CHAN4_SLOTS_MASK |
WM8915_AIF1TX_CHAN0_START_SLOT_MASK,
1 << WM8915_AIF1TX_CHAN4_SLOTS_SHIFT | 0);
snd_soc_update_bits(codec, WM8915_AIF1TX_CHANNEL_5_CONFIGURATION,
WM8915_AIF1TX_CHAN5_SLOTS_MASK |
WM8915_AIF1TX_CHAN0_START_SLOT_MASK,
1 << WM8915_AIF1TX_CHAN5_SLOTS_SHIFT | 1);
snd_soc_update_bits(codec, WM8915_AIF2TX_CHANNEL_0_CONFIGURATION,
WM8915_AIF2TX_CHAN0_SLOTS_MASK |
WM8915_AIF2TX_CHAN0_START_SLOT_MASK,
1 << WM8915_AIF2TX_CHAN0_SLOTS_SHIFT | 0);
snd_soc_update_bits(codec, WM8915_AIF1TX_CHANNEL_1_CONFIGURATION,
WM8915_AIF2TX_CHAN1_SLOTS_MASK |
WM8915_AIF2TX_CHAN1_START_SLOT_MASK,
1 << WM8915_AIF1TX_CHAN1_SLOTS_SHIFT | 1);
if (wm8915->pdata.num_retune_mobile_cfgs)
wm8915_retune_mobile_pdata(codec);
else
snd_soc_add_controls(codec, wm8915_eq_controls,
ARRAY_SIZE(wm8915_eq_controls));
if ((snd_soc_read(codec, WM8915_GPIO_1)))
snd_soc_update_bits(codec, WM8915_AIF1_TX_LRCLK_2,
WM8915_AIF1TX_LRCLK_MODE,
WM8915_AIF1TX_LRCLK_MODE);
if ((snd_soc_read(codec, WM8915_GPIO_2)))
snd_soc_update_bits(codec, WM8915_AIF2_TX_LRCLK_2,
WM8915_AIF2TX_LRCLK_MODE,
WM8915_AIF2TX_LRCLK_MODE);
regulator_bulk_disable(ARRAY_SIZE(wm8915->supplies), wm8915->supplies);
wm8915_init_gpio(codec);
if (i2c->irq) {
if (wm8915->pdata.irq_flags)
irq_flags = wm8915->pdata.irq_flags;
else
irq_flags = IRQF_TRIGGER_LOW;
irq_flags |= IRQF_ONESHOT;
ret = request_threaded_irq(i2c->irq, NULL, wm8915_irq,
irq_flags, "wm8915", codec);
if (ret == 0) {
snd_soc_update_bits(codec, WM8915_INTERRUPT_CONTROL,
WM8915_IM_IRQ, 0);
snd_soc_update_bits(codec,
WM8915_INTERRUPT_STATUS_2_MASK,
WM8915_IM_DCS_DONE_23_EINT |
WM8915_IM_DCS_DONE_01_EINT |
WM8915_IM_FLL_LOCK_EINT |
WM8915_IM_FIFOS_ERR_EINT,
0);
} else {
dev_err(codec->dev, "Failed to request IRQ: %d\n",
ret);
}
}
return 0;
err_enable:
if (wm8915->pdata.ldo_ena >= 0)
gpio_set_value_cansleep(wm8915->pdata.ldo_ena, 0);
regulator_bulk_disable(ARRAY_SIZE(wm8915->supplies), wm8915->supplies);
err_get:
regulator_bulk_free(ARRAY_SIZE(wm8915->supplies), wm8915->supplies);
err:
return ret;
}
static int wm8915_remove(struct snd_soc_codec *codec)
{
struct wm8915_priv *wm8915 = snd_soc_codec_get_drvdata(codec);
struct i2c_client *i2c = to_i2c_client(codec->dev);
int i;
snd_soc_update_bits(codec, WM8915_INTERRUPT_CONTROL,
WM8915_IM_IRQ, WM8915_IM_IRQ);
if (i2c->irq)
free_irq(i2c->irq, codec);
wm8915_free_gpio(codec);
for (i = 0; i < ARRAY_SIZE(wm8915->supplies); i++)
regulator_unregister_notifier(wm8915->supplies[i].consumer,
&wm8915->disable_nb[i]);
regulator_bulk_free(ARRAY_SIZE(wm8915->supplies), wm8915->supplies);
return 0;
}
static __devinit int wm8915_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct wm8915_priv *wm8915;
int ret;
wm8915 = kzalloc(sizeof(struct wm8915_priv), GFP_KERNEL);
if (wm8915 == NULL)
return -ENOMEM;
i2c_set_clientdata(i2c, wm8915);
if (dev_get_platdata(&i2c->dev))
memcpy(&wm8915->pdata, dev_get_platdata(&i2c->dev),
sizeof(wm8915->pdata));
if (wm8915->pdata.ldo_ena > 0) {
ret = gpio_request_one(wm8915->pdata.ldo_ena,
GPIOF_OUT_INIT_LOW, "WM8915 ENA");
if (ret < 0) {
dev_err(&i2c->dev, "Failed to request GPIO %d: %d\n",
wm8915->pdata.ldo_ena, ret);
goto err;
}
}
ret = snd_soc_register_codec(&i2c->dev,
&soc_codec_dev_wm8915, wm8915_dai,
ARRAY_SIZE(wm8915_dai));
if (ret < 0)
goto err_gpio;
return ret;
err_gpio:
if (wm8915->pdata.ldo_ena > 0)
gpio_free(wm8915->pdata.ldo_ena);
err:
kfree(wm8915);
return ret;
}
static __devexit int wm8915_i2c_remove(struct i2c_client *client)
{
struct wm8915_priv *wm8915 = i2c_get_clientdata(client);
snd_soc_unregister_codec(&client->dev);
if (wm8915->pdata.ldo_ena > 0)
gpio_free(wm8915->pdata.ldo_ena);
kfree(i2c_get_clientdata(client));
return 0;
}
static int __init wm8915_modinit(void)
{
int ret;
ret = i2c_add_driver(&wm8915_i2c_driver);
if (ret != 0) {
printk(KERN_ERR "Failed to register WM8915 I2C driver: %d\n",
ret);
}
return ret;
}
static void __exit wm8915_exit(void)
{
i2c_del_driver(&wm8915_i2c_driver);
}
