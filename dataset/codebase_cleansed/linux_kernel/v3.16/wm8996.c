static void wm8996_set_retune_mobile(struct snd_soc_codec *codec, int block)
{
struct wm8996_priv *wm8996 = snd_soc_codec_get_drvdata(codec);
struct wm8996_pdata *pdata = &wm8996->pdata;
int base, best, best_val, save, i, cfg, iface;
if (!wm8996->num_retune_mobile_texts)
return;
switch (block) {
case 0:
base = WM8996_DSP1_RX_EQ_GAINS_1;
if (snd_soc_read(codec, WM8996_POWER_MANAGEMENT_8) &
WM8996_DSP1RX_SRC)
iface = 1;
else
iface = 0;
break;
case 1:
base = WM8996_DSP1_RX_EQ_GAINS_2;
if (snd_soc_read(codec, WM8996_POWER_MANAGEMENT_8) &
WM8996_DSP2RX_SRC)
iface = 1;
else
iface = 0;
break;
default:
return;
}
cfg = wm8996->retune_mobile_cfg[block];
best = 0;
best_val = INT_MAX;
for (i = 0; i < pdata->num_retune_mobile_cfgs; i++) {
if (strcmp(pdata->retune_mobile_cfgs[i].name,
wm8996->retune_mobile_texts[cfg]) == 0 &&
abs(pdata->retune_mobile_cfgs[i].rate
- wm8996->rx_rate[iface]) < best_val) {
best = i;
best_val = abs(pdata->retune_mobile_cfgs[i].rate
- wm8996->rx_rate[iface]);
}
}
dev_dbg(codec->dev, "ReTune Mobile %d %s/%dHz for %dHz sample rate\n",
block,
pdata->retune_mobile_cfgs[best].name,
pdata->retune_mobile_cfgs[best].rate,
wm8996->rx_rate[iface]);
save = snd_soc_read(codec, base);
save &= WM8996_DSP1RX_EQ_ENA;
for (i = 0; i < ARRAY_SIZE(pdata->retune_mobile_cfgs[best].regs); i++)
snd_soc_update_bits(codec, base + i, 0xffff,
pdata->retune_mobile_cfgs[best].regs[i]);
snd_soc_update_bits(codec, base, WM8996_DSP1RX_EQ_ENA, save);
}
static int wm8996_get_retune_mobile_block(const char *name)
{
if (strcmp(name, "DSP1 EQ Mode") == 0)
return 0;
if (strcmp(name, "DSP2 EQ Mode") == 0)
return 1;
return -EINVAL;
}
static int wm8996_put_retune_mobile_enum(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_soc_kcontrol_codec(kcontrol);
struct wm8996_priv *wm8996 = snd_soc_codec_get_drvdata(codec);
struct wm8996_pdata *pdata = &wm8996->pdata;
int block = wm8996_get_retune_mobile_block(kcontrol->id.name);
int value = ucontrol->value.integer.value[0];
if (block < 0)
return block;
if (value >= pdata->num_retune_mobile_cfgs)
return -EINVAL;
wm8996->retune_mobile_cfg[block] = value;
wm8996_set_retune_mobile(codec, block);
return 0;
}
static int wm8996_get_retune_mobile_enum(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_soc_kcontrol_codec(kcontrol);
struct wm8996_priv *wm8996 = snd_soc_codec_get_drvdata(codec);
int block = wm8996_get_retune_mobile_block(kcontrol->id.name);
if (block < 0)
return block;
ucontrol->value.enumerated.item[0] = wm8996->retune_mobile_cfg[block];
return 0;
}
static void wm8996_bg_enable(struct snd_soc_codec *codec)
{
struct wm8996_priv *wm8996 = snd_soc_codec_get_drvdata(codec);
wm8996->bg_ena++;
if (wm8996->bg_ena == 1) {
snd_soc_update_bits(codec, WM8996_POWER_MANAGEMENT_1,
WM8996_BG_ENA, WM8996_BG_ENA);
msleep(2);
}
}
static void wm8996_bg_disable(struct snd_soc_codec *codec)
{
struct wm8996_priv *wm8996 = snd_soc_codec_get_drvdata(codec);
wm8996->bg_ena--;
if (!wm8996->bg_ena)
snd_soc_update_bits(codec, WM8996_POWER_MANAGEMENT_1,
WM8996_BG_ENA, 0);
}
static int bg_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = w->codec;
int ret = 0;
switch (event) {
case SND_SOC_DAPM_PRE_PMU:
wm8996_bg_enable(codec);
break;
case SND_SOC_DAPM_POST_PMD:
wm8996_bg_disable(codec);
break;
default:
WARN(1, "Invalid event %d\n", event);
ret = -EINVAL;
}
return ret;
}
static int cp_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
int ret = 0;
switch (event) {
case SND_SOC_DAPM_POST_PMU:
msleep(5);
break;
default:
WARN(1, "Invalid event %d\n", event);
ret = -EINVAL;
}
return 0;
}
static int rmv_short_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct wm8996_priv *wm8996 = snd_soc_codec_get_drvdata(w->codec);
switch (event) {
case SND_SOC_DAPM_PRE_PMD:
wm8996->hpout_pending &= ~w->shift;
break;
case SND_SOC_DAPM_PRE_PMU:
wm8996->hpout_pending |= w->shift;
break;
default:
WARN(1, "Invalid event %d\n", event);
return -EINVAL;
}
return 0;
}
static void wait_for_dc_servo(struct snd_soc_codec *codec, u16 mask)
{
struct i2c_client *i2c = to_i2c_client(codec->dev);
struct wm8996_priv *wm8996 = snd_soc_codec_get_drvdata(codec);
int ret;
unsigned long timeout = 200;
snd_soc_write(codec, WM8996_DC_SERVO_2, mask);
do {
if (i2c->irq) {
timeout = wait_for_completion_timeout(&wm8996->dcs_done,
msecs_to_jiffies(200));
if (timeout == 0)
dev_err(codec->dev, "DC servo timed out\n");
} else {
msleep(1);
timeout--;
}
ret = snd_soc_read(codec, WM8996_DC_SERVO_2);
dev_dbg(codec->dev, "DC servo state: %x\n", ret);
} while (timeout && ret & mask);
if (timeout == 0)
dev_err(codec->dev, "DC servo timed out for %x\n", mask);
else
dev_dbg(codec->dev, "DC servo complete for %x\n", mask);
}
static void wm8996_seq_notifier(struct snd_soc_dapm_context *dapm,
enum snd_soc_dapm_type event, int subseq)
{
struct snd_soc_codec *codec = container_of(dapm,
struct snd_soc_codec, dapm);
struct wm8996_priv *wm8996 = snd_soc_codec_get_drvdata(codec);
u16 val, mask;
if (wm8996->dcs_pending) {
dev_dbg(codec->dev, "Starting DC servo for %x\n",
wm8996->dcs_pending);
wait_for_dc_servo(codec, wm8996->dcs_pending
<< WM8996_DCS_TRIG_STARTUP_0_SHIFT);
wm8996->dcs_pending = 0;
}
if (wm8996->hpout_pending != wm8996->hpout_ena) {
dev_dbg(codec->dev, "Applying RMV_SHORTs %x->%x\n",
wm8996->hpout_ena, wm8996->hpout_pending);
val = 0;
mask = 0;
if (wm8996->hpout_pending & HPOUT1L) {
val |= WM8996_HPOUT1L_RMV_SHORT | WM8996_HPOUT1L_OUTP;
mask |= WM8996_HPOUT1L_RMV_SHORT | WM8996_HPOUT1L_OUTP;
} else {
mask |= WM8996_HPOUT1L_RMV_SHORT |
WM8996_HPOUT1L_OUTP |
WM8996_HPOUT1L_DLY;
}
if (wm8996->hpout_pending & HPOUT1R) {
val |= WM8996_HPOUT1R_RMV_SHORT | WM8996_HPOUT1R_OUTP;
mask |= WM8996_HPOUT1R_RMV_SHORT | WM8996_HPOUT1R_OUTP;
} else {
mask |= WM8996_HPOUT1R_RMV_SHORT |
WM8996_HPOUT1R_OUTP |
WM8996_HPOUT1R_DLY;
}
snd_soc_update_bits(codec, WM8996_ANALOGUE_HP_1, mask, val);
val = 0;
mask = 0;
if (wm8996->hpout_pending & HPOUT2L) {
val |= WM8996_HPOUT2L_RMV_SHORT | WM8996_HPOUT2L_OUTP;
mask |= WM8996_HPOUT2L_RMV_SHORT | WM8996_HPOUT2L_OUTP;
} else {
mask |= WM8996_HPOUT2L_RMV_SHORT |
WM8996_HPOUT2L_OUTP |
WM8996_HPOUT2L_DLY;
}
if (wm8996->hpout_pending & HPOUT2R) {
val |= WM8996_HPOUT2R_RMV_SHORT | WM8996_HPOUT2R_OUTP;
mask |= WM8996_HPOUT2R_RMV_SHORT | WM8996_HPOUT2R_OUTP;
} else {
mask |= WM8996_HPOUT2R_RMV_SHORT |
WM8996_HPOUT2R_OUTP |
WM8996_HPOUT2R_DLY;
}
snd_soc_update_bits(codec, WM8996_ANALOGUE_HP_2, mask, val);
wm8996->hpout_ena = wm8996->hpout_pending;
}
}
static int dcs_start(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct wm8996_priv *wm8996 = snd_soc_codec_get_drvdata(w->codec);
switch (event) {
case SND_SOC_DAPM_POST_PMU:
wm8996->dcs_pending |= 1 << w->shift;
break;
default:
WARN(1, "Invalid event %d\n", event);
return -EINVAL;
}
return 0;
}
static bool wm8996_readable_register(struct device *dev, unsigned int reg)
{
switch (reg) {
case WM8996_SOFTWARE_RESET:
case WM8996_POWER_MANAGEMENT_1:
case WM8996_POWER_MANAGEMENT_2:
case WM8996_POWER_MANAGEMENT_3:
case WM8996_POWER_MANAGEMENT_4:
case WM8996_POWER_MANAGEMENT_5:
case WM8996_POWER_MANAGEMENT_6:
case WM8996_POWER_MANAGEMENT_7:
case WM8996_POWER_MANAGEMENT_8:
case WM8996_LEFT_LINE_INPUT_VOLUME:
case WM8996_RIGHT_LINE_INPUT_VOLUME:
case WM8996_LINE_INPUT_CONTROL:
case WM8996_DAC1_HPOUT1_VOLUME:
case WM8996_DAC2_HPOUT2_VOLUME:
case WM8996_DAC1_LEFT_VOLUME:
case WM8996_DAC1_RIGHT_VOLUME:
case WM8996_DAC2_LEFT_VOLUME:
case WM8996_DAC2_RIGHT_VOLUME:
case WM8996_OUTPUT1_LEFT_VOLUME:
case WM8996_OUTPUT1_RIGHT_VOLUME:
case WM8996_OUTPUT2_LEFT_VOLUME:
case WM8996_OUTPUT2_RIGHT_VOLUME:
case WM8996_MICBIAS_1:
case WM8996_MICBIAS_2:
case WM8996_LDO_1:
case WM8996_LDO_2:
case WM8996_ACCESSORY_DETECT_MODE_1:
case WM8996_ACCESSORY_DETECT_MODE_2:
case WM8996_HEADPHONE_DETECT_1:
case WM8996_HEADPHONE_DETECT_2:
case WM8996_MIC_DETECT_1:
case WM8996_MIC_DETECT_2:
case WM8996_MIC_DETECT_3:
case WM8996_CHARGE_PUMP_1:
case WM8996_CHARGE_PUMP_2:
case WM8996_DC_SERVO_1:
case WM8996_DC_SERVO_2:
case WM8996_DC_SERVO_3:
case WM8996_DC_SERVO_5:
case WM8996_DC_SERVO_6:
case WM8996_DC_SERVO_7:
case WM8996_DC_SERVO_READBACK_0:
case WM8996_ANALOGUE_HP_1:
case WM8996_ANALOGUE_HP_2:
case WM8996_CHIP_REVISION:
case WM8996_CONTROL_INTERFACE_1:
case WM8996_WRITE_SEQUENCER_CTRL_1:
case WM8996_WRITE_SEQUENCER_CTRL_2:
case WM8996_AIF_CLOCKING_1:
case WM8996_AIF_CLOCKING_2:
case WM8996_CLOCKING_1:
case WM8996_CLOCKING_2:
case WM8996_AIF_RATE:
case WM8996_FLL_CONTROL_1:
case WM8996_FLL_CONTROL_2:
case WM8996_FLL_CONTROL_3:
case WM8996_FLL_CONTROL_4:
case WM8996_FLL_CONTROL_5:
case WM8996_FLL_CONTROL_6:
case WM8996_FLL_EFS_1:
case WM8996_FLL_EFS_2:
case WM8996_AIF1_CONTROL:
case WM8996_AIF1_BCLK:
case WM8996_AIF1_TX_LRCLK_1:
case WM8996_AIF1_TX_LRCLK_2:
case WM8996_AIF1_RX_LRCLK_1:
case WM8996_AIF1_RX_LRCLK_2:
case WM8996_AIF1TX_DATA_CONFIGURATION_1:
case WM8996_AIF1TX_DATA_CONFIGURATION_2:
case WM8996_AIF1RX_DATA_CONFIGURATION:
case WM8996_AIF1TX_CHANNEL_0_CONFIGURATION:
case WM8996_AIF1TX_CHANNEL_1_CONFIGURATION:
case WM8996_AIF1TX_CHANNEL_2_CONFIGURATION:
case WM8996_AIF1TX_CHANNEL_3_CONFIGURATION:
case WM8996_AIF1TX_CHANNEL_4_CONFIGURATION:
case WM8996_AIF1TX_CHANNEL_5_CONFIGURATION:
case WM8996_AIF1RX_CHANNEL_0_CONFIGURATION:
case WM8996_AIF1RX_CHANNEL_1_CONFIGURATION:
case WM8996_AIF1RX_CHANNEL_2_CONFIGURATION:
case WM8996_AIF1RX_CHANNEL_3_CONFIGURATION:
case WM8996_AIF1RX_CHANNEL_4_CONFIGURATION:
case WM8996_AIF1RX_CHANNEL_5_CONFIGURATION:
case WM8996_AIF1RX_MONO_CONFIGURATION:
case WM8996_AIF1TX_TEST:
case WM8996_AIF2_CONTROL:
case WM8996_AIF2_BCLK:
case WM8996_AIF2_TX_LRCLK_1:
case WM8996_AIF2_TX_LRCLK_2:
case WM8996_AIF2_RX_LRCLK_1:
case WM8996_AIF2_RX_LRCLK_2:
case WM8996_AIF2TX_DATA_CONFIGURATION_1:
case WM8996_AIF2TX_DATA_CONFIGURATION_2:
case WM8996_AIF2RX_DATA_CONFIGURATION:
case WM8996_AIF2TX_CHANNEL_0_CONFIGURATION:
case WM8996_AIF2TX_CHANNEL_1_CONFIGURATION:
case WM8996_AIF2RX_CHANNEL_0_CONFIGURATION:
case WM8996_AIF2RX_CHANNEL_1_CONFIGURATION:
case WM8996_AIF2RX_MONO_CONFIGURATION:
case WM8996_AIF2TX_TEST:
case WM8996_DSP1_TX_LEFT_VOLUME:
case WM8996_DSP1_TX_RIGHT_VOLUME:
case WM8996_DSP1_RX_LEFT_VOLUME:
case WM8996_DSP1_RX_RIGHT_VOLUME:
case WM8996_DSP1_TX_FILTERS:
case WM8996_DSP1_RX_FILTERS_1:
case WM8996_DSP1_RX_FILTERS_2:
case WM8996_DSP1_DRC_1:
case WM8996_DSP1_DRC_2:
case WM8996_DSP1_DRC_3:
case WM8996_DSP1_DRC_4:
case WM8996_DSP1_DRC_5:
case WM8996_DSP1_RX_EQ_GAINS_1:
case WM8996_DSP1_RX_EQ_GAINS_2:
case WM8996_DSP1_RX_EQ_BAND_1_A:
case WM8996_DSP1_RX_EQ_BAND_1_B:
case WM8996_DSP1_RX_EQ_BAND_1_PG:
case WM8996_DSP1_RX_EQ_BAND_2_A:
case WM8996_DSP1_RX_EQ_BAND_2_B:
case WM8996_DSP1_RX_EQ_BAND_2_C:
case WM8996_DSP1_RX_EQ_BAND_2_PG:
case WM8996_DSP1_RX_EQ_BAND_3_A:
case WM8996_DSP1_RX_EQ_BAND_3_B:
case WM8996_DSP1_RX_EQ_BAND_3_C:
case WM8996_DSP1_RX_EQ_BAND_3_PG:
case WM8996_DSP1_RX_EQ_BAND_4_A:
case WM8996_DSP1_RX_EQ_BAND_4_B:
case WM8996_DSP1_RX_EQ_BAND_4_C:
case WM8996_DSP1_RX_EQ_BAND_4_PG:
case WM8996_DSP1_RX_EQ_BAND_5_A:
case WM8996_DSP1_RX_EQ_BAND_5_B:
case WM8996_DSP1_RX_EQ_BAND_5_PG:
case WM8996_DSP2_TX_LEFT_VOLUME:
case WM8996_DSP2_TX_RIGHT_VOLUME:
case WM8996_DSP2_RX_LEFT_VOLUME:
case WM8996_DSP2_RX_RIGHT_VOLUME:
case WM8996_DSP2_TX_FILTERS:
case WM8996_DSP2_RX_FILTERS_1:
case WM8996_DSP2_RX_FILTERS_2:
case WM8996_DSP2_DRC_1:
case WM8996_DSP2_DRC_2:
case WM8996_DSP2_DRC_3:
case WM8996_DSP2_DRC_4:
case WM8996_DSP2_DRC_5:
case WM8996_DSP2_RX_EQ_GAINS_1:
case WM8996_DSP2_RX_EQ_GAINS_2:
case WM8996_DSP2_RX_EQ_BAND_1_A:
case WM8996_DSP2_RX_EQ_BAND_1_B:
case WM8996_DSP2_RX_EQ_BAND_1_PG:
case WM8996_DSP2_RX_EQ_BAND_2_A:
case WM8996_DSP2_RX_EQ_BAND_2_B:
case WM8996_DSP2_RX_EQ_BAND_2_C:
case WM8996_DSP2_RX_EQ_BAND_2_PG:
case WM8996_DSP2_RX_EQ_BAND_3_A:
case WM8996_DSP2_RX_EQ_BAND_3_B:
case WM8996_DSP2_RX_EQ_BAND_3_C:
case WM8996_DSP2_RX_EQ_BAND_3_PG:
case WM8996_DSP2_RX_EQ_BAND_4_A:
case WM8996_DSP2_RX_EQ_BAND_4_B:
case WM8996_DSP2_RX_EQ_BAND_4_C:
case WM8996_DSP2_RX_EQ_BAND_4_PG:
case WM8996_DSP2_RX_EQ_BAND_5_A:
case WM8996_DSP2_RX_EQ_BAND_5_B:
case WM8996_DSP2_RX_EQ_BAND_5_PG:
case WM8996_DAC1_MIXER_VOLUMES:
case WM8996_DAC1_LEFT_MIXER_ROUTING:
case WM8996_DAC1_RIGHT_MIXER_ROUTING:
case WM8996_DAC2_MIXER_VOLUMES:
case WM8996_DAC2_LEFT_MIXER_ROUTING:
case WM8996_DAC2_RIGHT_MIXER_ROUTING:
case WM8996_DSP1_TX_LEFT_MIXER_ROUTING:
case WM8996_DSP1_TX_RIGHT_MIXER_ROUTING:
case WM8996_DSP2_TX_LEFT_MIXER_ROUTING:
case WM8996_DSP2_TX_RIGHT_MIXER_ROUTING:
case WM8996_DSP_TX_MIXER_SELECT:
case WM8996_DAC_SOFTMUTE:
case WM8996_OVERSAMPLING:
case WM8996_SIDETONE:
case WM8996_GPIO_1:
case WM8996_GPIO_2:
case WM8996_GPIO_3:
case WM8996_GPIO_4:
case WM8996_GPIO_5:
case WM8996_PULL_CONTROL_1:
case WM8996_PULL_CONTROL_2:
case WM8996_INTERRUPT_STATUS_1:
case WM8996_INTERRUPT_STATUS_2:
case WM8996_INTERRUPT_RAW_STATUS_2:
case WM8996_INTERRUPT_STATUS_1_MASK:
case WM8996_INTERRUPT_STATUS_2_MASK:
case WM8996_INTERRUPT_CONTROL:
case WM8996_LEFT_PDM_SPEAKER:
case WM8996_RIGHT_PDM_SPEAKER:
case WM8996_PDM_SPEAKER_MUTE_SEQUENCE:
case WM8996_PDM_SPEAKER_VOLUME:
return 1;
default:
return 0;
}
}
static bool wm8996_volatile_register(struct device *dev, unsigned int reg)
{
switch (reg) {
case WM8996_SOFTWARE_RESET:
case WM8996_CHIP_REVISION:
case WM8996_LDO_1:
case WM8996_LDO_2:
case WM8996_INTERRUPT_STATUS_1:
case WM8996_INTERRUPT_STATUS_2:
case WM8996_INTERRUPT_RAW_STATUS_2:
case WM8996_DC_SERVO_READBACK_0:
case WM8996_DC_SERVO_2:
case WM8996_DC_SERVO_6:
case WM8996_DC_SERVO_7:
case WM8996_FLL_CONTROL_6:
case WM8996_MIC_DETECT_3:
case WM8996_HEADPHONE_DETECT_1:
case WM8996_HEADPHONE_DETECT_2:
return 1;
default:
return 0;
}
}
static void wm8996_update_bclk(struct snd_soc_codec *codec)
{
struct wm8996_priv *wm8996 = snd_soc_codec_get_drvdata(codec);
int aif, best, cur_val, bclk_rate, bclk_reg, i;
if (wm8996->sysclk < 64000)
return;
for (aif = 0; aif < WM8996_AIFS; aif++) {
switch (aif) {
case 0:
bclk_reg = WM8996_AIF1_BCLK;
break;
case 1:
bclk_reg = WM8996_AIF2_BCLK;
break;
}
bclk_rate = wm8996->bclk_rate[aif];
best = 0;
for (i = 0; i < ARRAY_SIZE(bclk_divs); i++) {
cur_val = (wm8996->sysclk / bclk_divs[i]) - bclk_rate;
if (cur_val < 0)
break;
best = i;
}
bclk_rate = wm8996->sysclk / bclk_divs[best];
dev_dbg(codec->dev, "Using BCLK_DIV %d for actual BCLK %dHz\n",
bclk_divs[best], bclk_rate);
snd_soc_update_bits(codec, bclk_reg,
WM8996_AIF1_BCLK_DIV_MASK, best);
}
}
static int wm8996_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
struct wm8996_priv *wm8996 = snd_soc_codec_get_drvdata(codec);
int ret;
switch (level) {
case SND_SOC_BIAS_ON:
break;
case SND_SOC_BIAS_PREPARE:
snd_soc_update_bits(codec, WM8996_MICBIAS_1,
WM8996_MICB1_MODE, 0);
snd_soc_update_bits(codec, WM8996_MICBIAS_2,
WM8996_MICB2_MODE, 0);
break;
case SND_SOC_BIAS_STANDBY:
if (codec->dapm.bias_level == SND_SOC_BIAS_OFF) {
ret = regulator_bulk_enable(ARRAY_SIZE(wm8996->supplies),
wm8996->supplies);
if (ret != 0) {
dev_err(codec->dev,
"Failed to enable supplies: %d\n",
ret);
return ret;
}
if (wm8996->pdata.ldo_ena >= 0) {
gpio_set_value_cansleep(wm8996->pdata.ldo_ena,
1);
msleep(5);
}
regcache_cache_only(wm8996->regmap, false);
regcache_sync(wm8996->regmap);
}
snd_soc_update_bits(codec, WM8996_MICBIAS_1,
WM8996_MICB1_MODE, WM8996_MICB1_MODE);
snd_soc_update_bits(codec, WM8996_MICBIAS_2,
WM8996_MICB2_MODE, WM8996_MICB2_MODE);
break;
case SND_SOC_BIAS_OFF:
regcache_cache_only(wm8996->regmap, true);
if (wm8996->pdata.ldo_ena >= 0) {
gpio_set_value_cansleep(wm8996->pdata.ldo_ena, 0);
regcache_cache_only(wm8996->regmap, true);
}
regulator_bulk_disable(ARRAY_SIZE(wm8996->supplies),
wm8996->supplies);
break;
}
codec->dapm.bias_level = level;
return 0;
}
static int wm8996_set_fmt(struct snd_soc_dai *dai, unsigned int fmt)
{
struct snd_soc_codec *codec = dai->codec;
int aifctrl = 0;
int bclk = 0;
int lrclk_tx = 0;
int lrclk_rx = 0;
int aifctrl_reg, bclk_reg, lrclk_tx_reg, lrclk_rx_reg;
switch (dai->id) {
case 0:
aifctrl_reg = WM8996_AIF1_CONTROL;
bclk_reg = WM8996_AIF1_BCLK;
lrclk_tx_reg = WM8996_AIF1_TX_LRCLK_2;
lrclk_rx_reg = WM8996_AIF1_RX_LRCLK_2;
break;
case 1:
aifctrl_reg = WM8996_AIF2_CONTROL;
bclk_reg = WM8996_AIF2_BCLK;
lrclk_tx_reg = WM8996_AIF2_TX_LRCLK_2;
lrclk_rx_reg = WM8996_AIF2_RX_LRCLK_2;
break;
default:
WARN(1, "Invalid dai id %d\n", dai->id);
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
break;
case SND_SOC_DAIFMT_IB_NF:
bclk |= WM8996_AIF1_BCLK_INV;
break;
case SND_SOC_DAIFMT_NB_IF:
lrclk_tx |= WM8996_AIF1TX_LRCLK_INV;
lrclk_rx |= WM8996_AIF1RX_LRCLK_INV;
break;
case SND_SOC_DAIFMT_IB_IF:
bclk |= WM8996_AIF1_BCLK_INV;
lrclk_tx |= WM8996_AIF1TX_LRCLK_INV;
lrclk_rx |= WM8996_AIF1RX_LRCLK_INV;
break;
}
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBS_CFS:
break;
case SND_SOC_DAIFMT_CBS_CFM:
lrclk_tx |= WM8996_AIF1TX_LRCLK_MSTR;
lrclk_rx |= WM8996_AIF1RX_LRCLK_MSTR;
break;
case SND_SOC_DAIFMT_CBM_CFS:
bclk |= WM8996_AIF1_BCLK_MSTR;
break;
case SND_SOC_DAIFMT_CBM_CFM:
bclk |= WM8996_AIF1_BCLK_MSTR;
lrclk_tx |= WM8996_AIF1TX_LRCLK_MSTR;
lrclk_rx |= WM8996_AIF1RX_LRCLK_MSTR;
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
snd_soc_update_bits(codec, aifctrl_reg, WM8996_AIF1_FMT_MASK, aifctrl);
snd_soc_update_bits(codec, bclk_reg,
WM8996_AIF1_BCLK_INV | WM8996_AIF1_BCLK_MSTR,
bclk);
snd_soc_update_bits(codec, lrclk_tx_reg,
WM8996_AIF1TX_LRCLK_INV |
WM8996_AIF1TX_LRCLK_MSTR,
lrclk_tx);
snd_soc_update_bits(codec, lrclk_rx_reg,
WM8996_AIF1RX_LRCLK_INV |
WM8996_AIF1RX_LRCLK_MSTR,
lrclk_rx);
return 0;
}
static int wm8996_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct wm8996_priv *wm8996 = snd_soc_codec_get_drvdata(codec);
int bits, i, bclk_rate, best;
int aifdata = 0;
int lrclk = 0;
int dsp = 0;
int aifdata_reg, lrclk_reg, dsp_shift;
switch (dai->id) {
case 0:
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK ||
(snd_soc_read(codec, WM8996_GPIO_1)) & WM8996_GP1_FN_MASK) {
aifdata_reg = WM8996_AIF1RX_DATA_CONFIGURATION;
lrclk_reg = WM8996_AIF1_RX_LRCLK_1;
} else {
aifdata_reg = WM8996_AIF1TX_DATA_CONFIGURATION_1;
lrclk_reg = WM8996_AIF1_TX_LRCLK_1;
}
dsp_shift = 0;
break;
case 1:
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK ||
(snd_soc_read(codec, WM8996_GPIO_2)) & WM8996_GP2_FN_MASK) {
aifdata_reg = WM8996_AIF2RX_DATA_CONFIGURATION;
lrclk_reg = WM8996_AIF2_RX_LRCLK_1;
} else {
aifdata_reg = WM8996_AIF2TX_DATA_CONFIGURATION_1;
lrclk_reg = WM8996_AIF2_TX_LRCLK_1;
}
dsp_shift = WM8996_DSP2_DIV_SHIFT;
break;
default:
WARN(1, "Invalid dai id %d\n", dai->id);
return -EINVAL;
}
bclk_rate = snd_soc_params_to_bclk(params);
if (bclk_rate < 0) {
dev_err(codec->dev, "Unsupported BCLK rate: %d\n", bclk_rate);
return bclk_rate;
}
wm8996->bclk_rate[dai->id] = bclk_rate;
wm8996->rx_rate[dai->id] = params_rate(params);
bits = snd_pcm_format_width(params_format(params));
if (bits < 0)
return bits;
aifdata |= (bits << WM8996_AIF1TX_WL_SHIFT) | bits;
best = 0;
for (i = 0; i < ARRAY_SIZE(dsp_divs); i++) {
if (abs(dsp_divs[i] - params_rate(params)) <
abs(dsp_divs[best] - params_rate(params)))
best = i;
}
dsp |= i << dsp_shift;
wm8996_update_bclk(codec);
lrclk = bclk_rate / params_rate(params);
dev_dbg(dai->dev, "Using LRCLK rate %d for actual LRCLK %dHz\n",
lrclk, bclk_rate / lrclk);
snd_soc_update_bits(codec, aifdata_reg,
WM8996_AIF1TX_WL_MASK |
WM8996_AIF1TX_SLOT_LEN_MASK,
aifdata);
snd_soc_update_bits(codec, lrclk_reg, WM8996_AIF1RX_RATE_MASK,
lrclk);
snd_soc_update_bits(codec, WM8996_AIF_CLOCKING_2,
WM8996_DSP1_DIV_MASK << dsp_shift, dsp);
return 0;
}
static int wm8996_set_sysclk(struct snd_soc_dai *dai,
int clk_id, unsigned int freq, int dir)
{
struct snd_soc_codec *codec = dai->codec;
struct wm8996_priv *wm8996 = snd_soc_codec_get_drvdata(codec);
int lfclk = 0;
int ratediv = 0;
int sync = WM8996_REG_SYNC;
int src;
int old;
if (freq == wm8996->sysclk && clk_id == wm8996->sysclk_src)
return 0;
old = snd_soc_read(codec, WM8996_AIF_CLOCKING_1) & WM8996_SYSCLK_ENA;
snd_soc_update_bits(codec, WM8996_AIF_CLOCKING_1,
WM8996_SYSCLK_ENA, 0);
switch (clk_id) {
case WM8996_SYSCLK_MCLK1:
wm8996->sysclk = freq;
src = 0;
break;
case WM8996_SYSCLK_MCLK2:
wm8996->sysclk = freq;
src = 1;
break;
case WM8996_SYSCLK_FLL:
wm8996->sysclk = freq;
src = 2;
break;
default:
dev_err(codec->dev, "Unsupported clock source %d\n", clk_id);
return -EINVAL;
}
switch (wm8996->sysclk) {
case 5644800:
case 6144000:
snd_soc_update_bits(codec, WM8996_AIF_RATE,
WM8996_SYSCLK_RATE, 0);
break;
case 22579200:
case 24576000:
ratediv = WM8996_SYSCLK_DIV;
wm8996->sysclk /= 2;
case 11289600:
case 12288000:
snd_soc_update_bits(codec, WM8996_AIF_RATE,
WM8996_SYSCLK_RATE, WM8996_SYSCLK_RATE);
break;
case 32000:
case 32768:
lfclk = WM8996_LFCLK_ENA;
sync = 0;
break;
default:
dev_warn(codec->dev, "Unsupported clock rate %dHz\n",
wm8996->sysclk);
return -EINVAL;
}
wm8996_update_bclk(codec);
snd_soc_update_bits(codec, WM8996_AIF_CLOCKING_1,
WM8996_SYSCLK_SRC_MASK | WM8996_SYSCLK_DIV_MASK,
src << WM8996_SYSCLK_SRC_SHIFT | ratediv);
snd_soc_update_bits(codec, WM8996_CLOCKING_1, WM8996_LFCLK_ENA, lfclk);
snd_soc_update_bits(codec, WM8996_CONTROL_INTERFACE_1,
WM8996_REG_SYNC, sync);
snd_soc_update_bits(codec, WM8996_AIF_CLOCKING_1,
WM8996_SYSCLK_ENA, old);
wm8996->sysclk_src = clk_id;
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
static int wm8996_set_fll(struct snd_soc_codec *codec, int fll_id, int source,
unsigned int Fref, unsigned int Fout)
{
struct wm8996_priv *wm8996 = snd_soc_codec_get_drvdata(codec);
struct i2c_client *i2c = to_i2c_client(codec->dev);
struct _fll_div fll_div;
unsigned long timeout;
int ret, reg, retry;
if (source == wm8996->fll_src && Fref == wm8996->fll_fref &&
Fout == wm8996->fll_fout)
return 0;
if (Fout == 0) {
dev_dbg(codec->dev, "FLL disabled\n");
wm8996->fll_fref = 0;
wm8996->fll_fout = 0;
snd_soc_update_bits(codec, WM8996_FLL_CONTROL_1,
WM8996_FLL_ENA, 0);
wm8996_bg_disable(codec);
return 0;
}
ret = fll_factors(&fll_div, Fref, Fout);
if (ret != 0)
return ret;
switch (source) {
case WM8996_FLL_MCLK1:
reg = 0;
break;
case WM8996_FLL_MCLK2:
reg = 1;
break;
case WM8996_FLL_DACLRCLK1:
reg = 2;
break;
case WM8996_FLL_BCLK1:
reg = 3;
break;
default:
dev_err(codec->dev, "Unknown FLL source %d\n", ret);
return -EINVAL;
}
reg |= fll_div.fll_refclk_div << WM8996_FLL_REFCLK_DIV_SHIFT;
reg |= fll_div.fll_ref_freq << WM8996_FLL_REF_FREQ_SHIFT;
snd_soc_update_bits(codec, WM8996_FLL_CONTROL_5,
WM8996_FLL_REFCLK_DIV_MASK | WM8996_FLL_REF_FREQ |
WM8996_FLL_REFCLK_SRC_MASK, reg);
reg = 0;
if (fll_div.theta || fll_div.lambda)
reg |= WM8996_FLL_EFS_ENA | (3 << WM8996_FLL_LFSR_SEL_SHIFT);
else
reg |= 1 << WM8996_FLL_LFSR_SEL_SHIFT;
snd_soc_write(codec, WM8996_FLL_EFS_2, reg);
snd_soc_update_bits(codec, WM8996_FLL_CONTROL_2,
WM8996_FLL_OUTDIV_MASK |
WM8996_FLL_FRATIO_MASK,
(fll_div.fll_outdiv << WM8996_FLL_OUTDIV_SHIFT) |
(fll_div.fll_fratio));
snd_soc_write(codec, WM8996_FLL_CONTROL_3, fll_div.theta);
snd_soc_update_bits(codec, WM8996_FLL_CONTROL_4,
WM8996_FLL_N_MASK | WM8996_FLL_LOOP_GAIN_MASK,
(fll_div.n << WM8996_FLL_N_SHIFT) |
fll_div.fll_loop_gain);
snd_soc_write(codec, WM8996_FLL_EFS_1, fll_div.lambda);
ret = snd_soc_read(codec, WM8996_FLL_CONTROL_1);
if (!(ret & WM8996_FLL_ENA))
wm8996_bg_enable(codec);
try_wait_for_completion(&wm8996->fll_lock);
snd_soc_update_bits(codec, WM8996_FLL_CONTROL_1,
WM8996_FLL_ENA, WM8996_FLL_ENA);
snd_soc_write(codec, WM8996_FLL_CONTROL_6, WM8996_FLL_SWITCH_CLK);
if (Fref > 1000000)
timeout = usecs_to_jiffies(300);
else
timeout = msecs_to_jiffies(2);
if (i2c->irq)
timeout *= 10;
else
timeout /= 2;
for (retry = 0; retry < 10; retry++) {
ret = wait_for_completion_timeout(&wm8996->fll_lock,
timeout);
if (ret != 0) {
WARN_ON(!i2c->irq);
break;
}
ret = snd_soc_read(codec, WM8996_INTERRUPT_RAW_STATUS_2);
if (ret & WM8996_FLL_LOCK_STS)
break;
}
if (retry == 10) {
dev_err(codec->dev, "Timed out waiting for FLL\n");
ret = -ETIMEDOUT;
}
dev_dbg(codec->dev, "FLL configured for %dHz->%dHz\n", Fref, Fout);
wm8996->fll_fref = Fref;
wm8996->fll_fout = Fout;
wm8996->fll_src = source;
return ret;
}
static inline struct wm8996_priv *gpio_to_wm8996(struct gpio_chip *chip)
{
return container_of(chip, struct wm8996_priv, gpio_chip);
}
static void wm8996_gpio_set(struct gpio_chip *chip, unsigned offset, int value)
{
struct wm8996_priv *wm8996 = gpio_to_wm8996(chip);
regmap_update_bits(wm8996->regmap, WM8996_GPIO_1 + offset,
WM8996_GP1_LVL, !!value << WM8996_GP1_LVL_SHIFT);
}
static int wm8996_gpio_direction_out(struct gpio_chip *chip,
unsigned offset, int value)
{
struct wm8996_priv *wm8996 = gpio_to_wm8996(chip);
int val;
val = (1 << WM8996_GP1_FN_SHIFT) | (!!value << WM8996_GP1_LVL_SHIFT);
return regmap_update_bits(wm8996->regmap, WM8996_GPIO_1 + offset,
WM8996_GP1_FN_MASK | WM8996_GP1_DIR |
WM8996_GP1_LVL, val);
}
static int wm8996_gpio_get(struct gpio_chip *chip, unsigned offset)
{
struct wm8996_priv *wm8996 = gpio_to_wm8996(chip);
unsigned int reg;
int ret;
ret = regmap_read(wm8996->regmap, WM8996_GPIO_1 + offset, &reg);
if (ret < 0)
return ret;
return (reg & WM8996_GP1_LVL) != 0;
}
static int wm8996_gpio_direction_in(struct gpio_chip *chip, unsigned offset)
{
struct wm8996_priv *wm8996 = gpio_to_wm8996(chip);
return regmap_update_bits(wm8996->regmap, WM8996_GPIO_1 + offset,
WM8996_GP1_FN_MASK | WM8996_GP1_DIR,
(1 << WM8996_GP1_FN_SHIFT) |
(1 << WM8996_GP1_DIR_SHIFT));
}
static void wm8996_init_gpio(struct wm8996_priv *wm8996)
{
int ret;
wm8996->gpio_chip = wm8996_template_chip;
wm8996->gpio_chip.ngpio = 5;
wm8996->gpio_chip.dev = wm8996->dev;
if (wm8996->pdata.gpio_base)
wm8996->gpio_chip.base = wm8996->pdata.gpio_base;
else
wm8996->gpio_chip.base = -1;
ret = gpiochip_add(&wm8996->gpio_chip);
if (ret != 0)
dev_err(wm8996->dev, "Failed to add GPIOs: %d\n", ret);
}
static void wm8996_free_gpio(struct wm8996_priv *wm8996)
{
int ret;
ret = gpiochip_remove(&wm8996->gpio_chip);
if (ret != 0)
dev_err(wm8996->dev, "Failed to remove GPIOs: %d\n", ret);
}
static void wm8996_init_gpio(struct wm8996_priv *wm8996)
{
}
static void wm8996_free_gpio(struct wm8996_priv *wm8996)
{
}
int wm8996_detect(struct snd_soc_codec *codec, struct snd_soc_jack *jack,
wm8996_polarity_fn polarity_cb)
{
struct wm8996_priv *wm8996 = snd_soc_codec_get_drvdata(codec);
struct snd_soc_dapm_context *dapm = &codec->dapm;
wm8996->jack = jack;
wm8996->detecting = true;
wm8996->polarity_cb = polarity_cb;
wm8996->jack_flips = 0;
if (wm8996->polarity_cb)
wm8996->polarity_cb(codec, 0);
snd_soc_update_bits(codec, WM8996_MICBIAS_1,
WM8996_MICB1_DISCH, 0);
snd_soc_update_bits(codec, WM8996_MICBIAS_2,
WM8996_MICB2_DISCH, 0);
snd_soc_dapm_mutex_lock(dapm);
snd_soc_dapm_force_enable_pin_unlocked(dapm, "LDO2");
snd_soc_dapm_force_enable_pin_unlocked(dapm, "SYSCLK");
snd_soc_dapm_mutex_unlock(dapm);
snd_soc_update_bits(codec, WM8996_MIC_DETECT_1,
WM8996_MICD_ENA, WM8996_MICD_ENA);
snd_soc_update_bits(codec, WM8996_MIC_DETECT_1,
WM8996_MICD_RATE_MASK,
WM8996_MICD_RATE_MASK);
snd_soc_update_bits(codec, WM8996_INTERRUPT_STATUS_2_MASK,
WM8996_IM_MICD_EINT | WM8996_HP_DONE_EINT, 0);
return 0;
}
static void wm8996_hpdet_irq(struct snd_soc_codec *codec)
{
struct wm8996_priv *wm8996 = snd_soc_codec_get_drvdata(codec);
int val, reg, report;
report = SND_JACK_HEADPHONE;
reg = snd_soc_read(codec, WM8996_HEADPHONE_DETECT_2);
if (reg < 0) {
dev_err(codec->dev, "Failed to read HPDET status\n");
goto out;
}
if (!(reg & WM8996_HP_DONE)) {
dev_err(codec->dev, "Got HPDET IRQ but HPDET is busy\n");
goto out;
}
val = reg & WM8996_HP_LVL_MASK;
dev_dbg(codec->dev, "HPDET measured %d ohms\n", val);
if (val >= 126)
report = SND_JACK_LINEOUT;
else
report = SND_JACK_HEADPHONE;
out:
if (wm8996->jack_mic)
report |= SND_JACK_MICROPHONE;
snd_soc_jack_report(wm8996->jack, report,
SND_JACK_LINEOUT | SND_JACK_HEADSET);
wm8996->detecting = false;
if (!(snd_soc_read(codec, WM8996_POWER_MANAGEMENT_1) &
(WM8996_HPOUT1L_ENA | WM8996_HPOUT1R_RMV_SHORT)))
snd_soc_update_bits(codec, WM8996_ANALOGUE_HP_1,
WM8996_HPOUT1L_RMV_SHORT |
WM8996_HPOUT1R_RMV_SHORT, 0);
snd_soc_update_bits(codec, WM8996_ACCESSORY_DETECT_MODE_1,
WM8996_JD_MODE_MASK, 0);
snd_soc_update_bits(codec, WM8996_MIC_DETECT_1, WM8996_MICD_ENA,
WM8996_MICD_ENA);
snd_soc_dapm_disable_pin(&codec->dapm, "Bandgap");
snd_soc_dapm_sync(&codec->dapm);
}
static void wm8996_hpdet_start(struct snd_soc_codec *codec)
{
snd_soc_update_bits(codec, WM8996_ANALOGUE_HP_1,
WM8996_HPOUT1L_RMV_SHORT |
WM8996_HPOUT1R_RMV_SHORT,
WM8996_HPOUT1L_RMV_SHORT |
WM8996_HPOUT1R_RMV_SHORT);
snd_soc_dapm_force_enable_pin(&codec->dapm, "Bandgap");
snd_soc_dapm_sync(&codec->dapm);
snd_soc_update_bits(codec, WM8996_MIC_DETECT_1, WM8996_MICD_ENA, 0);
snd_soc_update_bits(codec, WM8996_ACCESSORY_DETECT_MODE_1,
WM8996_JD_MODE_MASK, 1);
snd_soc_update_bits(codec, WM8996_HEADPHONE_DETECT_1,
WM8996_HP_POLL, WM8996_HP_POLL);
}
static void wm8996_report_headphone(struct snd_soc_codec *codec)
{
dev_dbg(codec->dev, "Headphone detected\n");
wm8996_hpdet_start(codec);
snd_soc_update_bits(codec, WM8996_MIC_DETECT_1,
WM8996_MICD_RATE_MASK |
WM8996_MICD_BIAS_STARTTIME_MASK,
7 << WM8996_MICD_RATE_SHIFT |
7 << WM8996_MICD_BIAS_STARTTIME_SHIFT);
}
static void wm8996_micd(struct snd_soc_codec *codec)
{
struct wm8996_priv *wm8996 = snd_soc_codec_get_drvdata(codec);
int val, reg;
val = snd_soc_read(codec, WM8996_MIC_DETECT_3);
dev_dbg(codec->dev, "Microphone event: %x\n", val);
if (!(val & WM8996_MICD_VALID)) {
dev_warn(codec->dev, "Microphone detection state invalid\n");
return;
}
if (!(val & WM8996_MICD_STS)) {
dev_dbg(codec->dev, "Jack removal detected\n");
wm8996->jack_mic = false;
wm8996->detecting = true;
wm8996->jack_flips = 0;
snd_soc_jack_report(wm8996->jack, 0,
SND_JACK_LINEOUT | SND_JACK_HEADSET |
SND_JACK_BTN_0);
snd_soc_update_bits(codec, WM8996_MIC_DETECT_1,
WM8996_MICD_RATE_MASK |
WM8996_MICD_BIAS_STARTTIME_MASK,
WM8996_MICD_RATE_MASK |
9 << WM8996_MICD_BIAS_STARTTIME_SHIFT);
return;
}
if (val & 0x400) {
if (wm8996->detecting) {
dev_dbg(codec->dev, "Microphone detected\n");
wm8996->jack_mic = true;
wm8996_hpdet_start(codec);
snd_soc_update_bits(codec, WM8996_MIC_DETECT_1,
WM8996_MICD_RATE_MASK |
WM8996_MICD_BIAS_STARTTIME_MASK,
5 << WM8996_MICD_RATE_SHIFT |
7 << WM8996_MICD_BIAS_STARTTIME_SHIFT);
} else {
dev_dbg(codec->dev, "Mic button up\n");
snd_soc_jack_report(wm8996->jack, 0, SND_JACK_BTN_0);
}
return;
}
if (wm8996->detecting && (val & 0x3f0)) {
wm8996->jack_flips++;
if (wm8996->jack_flips > 1) {
wm8996_report_headphone(codec);
return;
}
reg = snd_soc_read(codec, WM8996_ACCESSORY_DETECT_MODE_2);
reg ^= WM8996_HPOUT1FB_SRC | WM8996_MICD_SRC |
WM8996_MICD_BIAS_SRC;
snd_soc_update_bits(codec, WM8996_ACCESSORY_DETECT_MODE_2,
WM8996_HPOUT1FB_SRC | WM8996_MICD_SRC |
WM8996_MICD_BIAS_SRC, reg);
if (wm8996->polarity_cb)
wm8996->polarity_cb(codec,
(reg & WM8996_MICD_SRC) != 0);
dev_dbg(codec->dev, "Set microphone polarity to %d\n",
(reg & WM8996_MICD_SRC) != 0);
return;
}
if (val & 0x3fc) {
if (wm8996->jack_mic) {
dev_dbg(codec->dev, "Mic button detected\n");
snd_soc_jack_report(wm8996->jack, SND_JACK_BTN_0,
SND_JACK_BTN_0);
} else if (wm8996->detecting) {
wm8996_report_headphone(codec);
}
}
}
static irqreturn_t wm8996_irq(int irq, void *data)
{
struct snd_soc_codec *codec = data;
struct wm8996_priv *wm8996 = snd_soc_codec_get_drvdata(codec);
int irq_val;
irq_val = snd_soc_read(codec, WM8996_INTERRUPT_STATUS_2);
if (irq_val < 0) {
dev_err(codec->dev, "Failed to read IRQ status: %d\n",
irq_val);
return IRQ_NONE;
}
irq_val &= ~snd_soc_read(codec, WM8996_INTERRUPT_STATUS_2_MASK);
if (!irq_val)
return IRQ_NONE;
snd_soc_write(codec, WM8996_INTERRUPT_STATUS_2, irq_val);
if (irq_val & (WM8996_DCS_DONE_01_EINT | WM8996_DCS_DONE_23_EINT)) {
dev_dbg(codec->dev, "DC servo IRQ\n");
complete(&wm8996->dcs_done);
}
if (irq_val & WM8996_FIFOS_ERR_EINT)
dev_err(codec->dev, "Digital core FIFO error\n");
if (irq_val & WM8996_FLL_LOCK_EINT) {
dev_dbg(codec->dev, "FLL locked\n");
complete(&wm8996->fll_lock);
}
if (irq_val & WM8996_MICD_EINT)
wm8996_micd(codec);
if (irq_val & WM8996_HP_DONE_EINT)
wm8996_hpdet_irq(codec);
return IRQ_HANDLED;
}
static irqreturn_t wm8996_edge_irq(int irq, void *data)
{
irqreturn_t ret = IRQ_NONE;
irqreturn_t val;
do {
val = wm8996_irq(irq, data);
if (val != IRQ_NONE)
ret = val;
} while (val != IRQ_NONE);
return ret;
}
static void wm8996_retune_mobile_pdata(struct snd_soc_codec *codec)
{
struct wm8996_priv *wm8996 = snd_soc_codec_get_drvdata(codec);
struct wm8996_pdata *pdata = &wm8996->pdata;
struct snd_kcontrol_new controls[] = {
SOC_ENUM_EXT("DSP1 EQ Mode",
wm8996->retune_mobile_enum,
wm8996_get_retune_mobile_enum,
wm8996_put_retune_mobile_enum),
SOC_ENUM_EXT("DSP2 EQ Mode",
wm8996->retune_mobile_enum,
wm8996_get_retune_mobile_enum,
wm8996_put_retune_mobile_enum),
};
int ret, i, j;
const char **t;
wm8996->num_retune_mobile_texts = 0;
wm8996->retune_mobile_texts = NULL;
for (i = 0; i < pdata->num_retune_mobile_cfgs; i++) {
for (j = 0; j < wm8996->num_retune_mobile_texts; j++) {
if (strcmp(pdata->retune_mobile_cfgs[i].name,
wm8996->retune_mobile_texts[j]) == 0)
break;
}
if (j != wm8996->num_retune_mobile_texts)
continue;
t = krealloc(wm8996->retune_mobile_texts,
sizeof(char *) *
(wm8996->num_retune_mobile_texts + 1),
GFP_KERNEL);
if (t == NULL)
continue;
t[wm8996->num_retune_mobile_texts] =
pdata->retune_mobile_cfgs[i].name;
wm8996->num_retune_mobile_texts++;
wm8996->retune_mobile_texts = t;
}
dev_dbg(codec->dev, "Allocated %d unique ReTune Mobile names\n",
wm8996->num_retune_mobile_texts);
wm8996->retune_mobile_enum.items = wm8996->num_retune_mobile_texts;
wm8996->retune_mobile_enum.texts = wm8996->retune_mobile_texts;
ret = snd_soc_add_codec_controls(codec, controls, ARRAY_SIZE(controls));
if (ret != 0)
dev_err(codec->dev,
"Failed to add ReTune Mobile controls: %d\n", ret);
}
static int wm8996_probe(struct snd_soc_codec *codec)
{
int ret;
struct wm8996_priv *wm8996 = snd_soc_codec_get_drvdata(codec);
struct i2c_client *i2c = to_i2c_client(codec->dev);
int irq_flags;
wm8996->codec = codec;
init_completion(&wm8996->dcs_done);
init_completion(&wm8996->fll_lock);
if (wm8996->pdata.num_retune_mobile_cfgs)
wm8996_retune_mobile_pdata(codec);
else
snd_soc_add_codec_controls(codec, wm8996_eq_controls,
ARRAY_SIZE(wm8996_eq_controls));
if (i2c->irq) {
if (wm8996->pdata.irq_flags)
irq_flags = wm8996->pdata.irq_flags;
else
irq_flags = IRQF_TRIGGER_LOW;
irq_flags |= IRQF_ONESHOT;
if (irq_flags & (IRQF_TRIGGER_RISING | IRQF_TRIGGER_FALLING))
ret = request_threaded_irq(i2c->irq, NULL,
wm8996_edge_irq,
irq_flags, "wm8996", codec);
else
ret = request_threaded_irq(i2c->irq, NULL, wm8996_irq,
irq_flags, "wm8996", codec);
if (ret == 0) {
snd_soc_update_bits(codec, WM8996_INTERRUPT_CONTROL,
WM8996_IM_IRQ, 0);
snd_soc_update_bits(codec,
WM8996_INTERRUPT_STATUS_2_MASK,
WM8996_IM_DCS_DONE_23_EINT |
WM8996_IM_DCS_DONE_01_EINT |
WM8996_IM_FLL_LOCK_EINT |
WM8996_IM_FIFOS_ERR_EINT,
0);
} else {
dev_err(codec->dev, "Failed to request IRQ: %d\n",
ret);
return ret;
}
}
return 0;
}
static int wm8996_remove(struct snd_soc_codec *codec)
{
struct i2c_client *i2c = to_i2c_client(codec->dev);
snd_soc_update_bits(codec, WM8996_INTERRUPT_CONTROL,
WM8996_IM_IRQ, WM8996_IM_IRQ);
if (i2c->irq)
free_irq(i2c->irq, codec);
return 0;
}
static int wm8996_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct wm8996_priv *wm8996;
int ret, i;
unsigned int reg;
wm8996 = devm_kzalloc(&i2c->dev, sizeof(struct wm8996_priv),
GFP_KERNEL);
if (wm8996 == NULL)
return -ENOMEM;
i2c_set_clientdata(i2c, wm8996);
wm8996->dev = &i2c->dev;
if (dev_get_platdata(&i2c->dev))
memcpy(&wm8996->pdata, dev_get_platdata(&i2c->dev),
sizeof(wm8996->pdata));
if (wm8996->pdata.ldo_ena > 0) {
ret = gpio_request_one(wm8996->pdata.ldo_ena,
GPIOF_OUT_INIT_LOW, "WM8996 ENA");
if (ret < 0) {
dev_err(&i2c->dev, "Failed to request GPIO %d: %d\n",
wm8996->pdata.ldo_ena, ret);
goto err;
}
}
for (i = 0; i < ARRAY_SIZE(wm8996->supplies); i++)
wm8996->supplies[i].supply = wm8996_supply_names[i];
ret = devm_regulator_bulk_get(&i2c->dev, ARRAY_SIZE(wm8996->supplies),
wm8996->supplies);
if (ret != 0) {
dev_err(&i2c->dev, "Failed to request supplies: %d\n", ret);
goto err_gpio;
}
wm8996->disable_nb[0].notifier_call = wm8996_regulator_event_0;
wm8996->disable_nb[1].notifier_call = wm8996_regulator_event_1;
wm8996->disable_nb[2].notifier_call = wm8996_regulator_event_2;
for (i = 0; i < ARRAY_SIZE(wm8996->supplies); i++) {
ret = regulator_register_notifier(wm8996->supplies[i].consumer,
&wm8996->disable_nb[i]);
if (ret != 0) {
dev_err(&i2c->dev,
"Failed to register regulator notifier: %d\n",
ret);
}
}
ret = regulator_bulk_enable(ARRAY_SIZE(wm8996->supplies),
wm8996->supplies);
if (ret != 0) {
dev_err(&i2c->dev, "Failed to enable supplies: %d\n", ret);
goto err_gpio;
}
if (wm8996->pdata.ldo_ena > 0) {
gpio_set_value_cansleep(wm8996->pdata.ldo_ena, 1);
msleep(5);
}
wm8996->regmap = devm_regmap_init_i2c(i2c, &wm8996_regmap);
if (IS_ERR(wm8996->regmap)) {
ret = PTR_ERR(wm8996->regmap);
dev_err(&i2c->dev, "regmap_init() failed: %d\n", ret);
goto err_enable;
}
ret = regmap_read(wm8996->regmap, WM8996_SOFTWARE_RESET, &reg);
if (ret < 0) {
dev_err(&i2c->dev, "Failed to read ID register: %d\n", ret);
goto err_regmap;
}
if (reg != 0x8915) {
dev_err(&i2c->dev, "Device is not a WM8996, ID %x\n", reg);
ret = -EINVAL;
goto err_regmap;
}
ret = regmap_read(wm8996->regmap, WM8996_CHIP_REVISION, &reg);
if (ret < 0) {
dev_err(&i2c->dev, "Failed to read device revision: %d\n",
ret);
goto err_regmap;
}
dev_info(&i2c->dev, "revision %c\n",
(reg & WM8996_CHIP_REV_MASK) + 'A');
if (wm8996->pdata.ldo_ena > 0) {
gpio_set_value_cansleep(wm8996->pdata.ldo_ena, 0);
regcache_cache_only(wm8996->regmap, true);
} else {
ret = regmap_write(wm8996->regmap, WM8996_SOFTWARE_RESET,
0x8915);
if (ret != 0) {
dev_err(&i2c->dev, "Failed to issue reset: %d\n", ret);
goto err_regmap;
}
}
regulator_bulk_disable(ARRAY_SIZE(wm8996->supplies), wm8996->supplies);
regmap_update_bits(wm8996->regmap, WM8996_LINE_INPUT_CONTROL,
WM8996_INL_MODE_MASK | WM8996_INR_MODE_MASK,
wm8996->pdata.inl_mode << WM8996_INL_MODE_SHIFT |
wm8996->pdata.inr_mode);
for (i = 0; i < ARRAY_SIZE(wm8996->pdata.gpio_default); i++) {
if (!wm8996->pdata.gpio_default[i])
continue;
regmap_write(wm8996->regmap, WM8996_GPIO_1 + i,
wm8996->pdata.gpio_default[i] & 0xffff);
}
if (wm8996->pdata.spkmute_seq)
regmap_update_bits(wm8996->regmap,
WM8996_PDM_SPEAKER_MUTE_SEQUENCE,
WM8996_SPK_MUTE_ENDIAN |
WM8996_SPK_MUTE_SEQ1_MASK,
wm8996->pdata.spkmute_seq);
regmap_update_bits(wm8996->regmap, WM8996_ACCESSORY_DETECT_MODE_2,
WM8996_MICD_BIAS_SRC | WM8996_HPOUT1FB_SRC |
WM8996_MICD_SRC, wm8996->pdata.micdet_def);
regmap_update_bits(wm8996->regmap, WM8996_LEFT_LINE_INPUT_VOLUME,
WM8996_IN1_VU, WM8996_IN1_VU);
regmap_update_bits(wm8996->regmap, WM8996_RIGHT_LINE_INPUT_VOLUME,
WM8996_IN1_VU, WM8996_IN1_VU);
regmap_update_bits(wm8996->regmap, WM8996_DAC1_LEFT_VOLUME,
WM8996_DAC1_VU, WM8996_DAC1_VU);
regmap_update_bits(wm8996->regmap, WM8996_DAC1_RIGHT_VOLUME,
WM8996_DAC1_VU, WM8996_DAC1_VU);
regmap_update_bits(wm8996->regmap, WM8996_DAC2_LEFT_VOLUME,
WM8996_DAC2_VU, WM8996_DAC2_VU);
regmap_update_bits(wm8996->regmap, WM8996_DAC2_RIGHT_VOLUME,
WM8996_DAC2_VU, WM8996_DAC2_VU);
regmap_update_bits(wm8996->regmap, WM8996_OUTPUT1_LEFT_VOLUME,
WM8996_DAC1_VU, WM8996_DAC1_VU);
regmap_update_bits(wm8996->regmap, WM8996_OUTPUT1_RIGHT_VOLUME,
WM8996_DAC1_VU, WM8996_DAC1_VU);
regmap_update_bits(wm8996->regmap, WM8996_OUTPUT2_LEFT_VOLUME,
WM8996_DAC2_VU, WM8996_DAC2_VU);
regmap_update_bits(wm8996->regmap, WM8996_OUTPUT2_RIGHT_VOLUME,
WM8996_DAC2_VU, WM8996_DAC2_VU);
regmap_update_bits(wm8996->regmap, WM8996_DSP1_TX_LEFT_VOLUME,
WM8996_DSP1TX_VU, WM8996_DSP1TX_VU);
regmap_update_bits(wm8996->regmap, WM8996_DSP1_TX_RIGHT_VOLUME,
WM8996_DSP1TX_VU, WM8996_DSP1TX_VU);
regmap_update_bits(wm8996->regmap, WM8996_DSP2_TX_LEFT_VOLUME,
WM8996_DSP2TX_VU, WM8996_DSP2TX_VU);
regmap_update_bits(wm8996->regmap, WM8996_DSP2_TX_RIGHT_VOLUME,
WM8996_DSP2TX_VU, WM8996_DSP2TX_VU);
regmap_update_bits(wm8996->regmap, WM8996_DSP1_RX_LEFT_VOLUME,
WM8996_DSP1RX_VU, WM8996_DSP1RX_VU);
regmap_update_bits(wm8996->regmap, WM8996_DSP1_RX_RIGHT_VOLUME,
WM8996_DSP1RX_VU, WM8996_DSP1RX_VU);
regmap_update_bits(wm8996->regmap, WM8996_DSP2_RX_LEFT_VOLUME,
WM8996_DSP2RX_VU, WM8996_DSP2RX_VU);
regmap_update_bits(wm8996->regmap, WM8996_DSP2_RX_RIGHT_VOLUME,
WM8996_DSP2RX_VU, WM8996_DSP2RX_VU);
regmap_update_bits(wm8996->regmap,
WM8996_AIF1RX_CHANNEL_0_CONFIGURATION,
WM8996_AIF1RX_CHAN0_SLOTS_MASK |
WM8996_AIF1RX_CHAN0_START_SLOT_MASK,
1 << WM8996_AIF1RX_CHAN0_SLOTS_SHIFT | 0);
regmap_update_bits(wm8996->regmap,
WM8996_AIF1RX_CHANNEL_1_CONFIGURATION,
WM8996_AIF1RX_CHAN1_SLOTS_MASK |
WM8996_AIF1RX_CHAN1_START_SLOT_MASK,
1 << WM8996_AIF1RX_CHAN1_SLOTS_SHIFT | 1);
regmap_update_bits(wm8996->regmap,
WM8996_AIF1RX_CHANNEL_2_CONFIGURATION,
WM8996_AIF1RX_CHAN2_SLOTS_MASK |
WM8996_AIF1RX_CHAN2_START_SLOT_MASK,
1 << WM8996_AIF1RX_CHAN2_SLOTS_SHIFT | 0);
regmap_update_bits(wm8996->regmap,
WM8996_AIF1RX_CHANNEL_3_CONFIGURATION,
WM8996_AIF1RX_CHAN3_SLOTS_MASK |
WM8996_AIF1RX_CHAN0_START_SLOT_MASK,
1 << WM8996_AIF1RX_CHAN3_SLOTS_SHIFT | 1);
regmap_update_bits(wm8996->regmap,
WM8996_AIF1RX_CHANNEL_4_CONFIGURATION,
WM8996_AIF1RX_CHAN4_SLOTS_MASK |
WM8996_AIF1RX_CHAN0_START_SLOT_MASK,
1 << WM8996_AIF1RX_CHAN4_SLOTS_SHIFT | 0);
regmap_update_bits(wm8996->regmap,
WM8996_AIF1RX_CHANNEL_5_CONFIGURATION,
WM8996_AIF1RX_CHAN5_SLOTS_MASK |
WM8996_AIF1RX_CHAN0_START_SLOT_MASK,
1 << WM8996_AIF1RX_CHAN5_SLOTS_SHIFT | 1);
regmap_update_bits(wm8996->regmap,
WM8996_AIF2RX_CHANNEL_0_CONFIGURATION,
WM8996_AIF2RX_CHAN0_SLOTS_MASK |
WM8996_AIF2RX_CHAN0_START_SLOT_MASK,
1 << WM8996_AIF2RX_CHAN0_SLOTS_SHIFT | 0);
regmap_update_bits(wm8996->regmap,
WM8996_AIF2RX_CHANNEL_1_CONFIGURATION,
WM8996_AIF2RX_CHAN1_SLOTS_MASK |
WM8996_AIF2RX_CHAN1_START_SLOT_MASK,
1 << WM8996_AIF2RX_CHAN1_SLOTS_SHIFT | 1);
regmap_update_bits(wm8996->regmap,
WM8996_AIF1TX_CHANNEL_0_CONFIGURATION,
WM8996_AIF1TX_CHAN0_SLOTS_MASK |
WM8996_AIF1TX_CHAN0_START_SLOT_MASK,
1 << WM8996_AIF1TX_CHAN0_SLOTS_SHIFT | 0);
regmap_update_bits(wm8996->regmap,
WM8996_AIF1TX_CHANNEL_1_CONFIGURATION,
WM8996_AIF1TX_CHAN1_SLOTS_MASK |
WM8996_AIF1TX_CHAN0_START_SLOT_MASK,
1 << WM8996_AIF1TX_CHAN1_SLOTS_SHIFT | 1);
regmap_update_bits(wm8996->regmap,
WM8996_AIF1TX_CHANNEL_2_CONFIGURATION,
WM8996_AIF1TX_CHAN2_SLOTS_MASK |
WM8996_AIF1TX_CHAN0_START_SLOT_MASK,
1 << WM8996_AIF1TX_CHAN2_SLOTS_SHIFT | 0);
regmap_update_bits(wm8996->regmap,
WM8996_AIF1TX_CHANNEL_3_CONFIGURATION,
WM8996_AIF1TX_CHAN3_SLOTS_MASK |
WM8996_AIF1TX_CHAN0_START_SLOT_MASK,
1 << WM8996_AIF1TX_CHAN3_SLOTS_SHIFT | 1);
regmap_update_bits(wm8996->regmap,
WM8996_AIF1TX_CHANNEL_4_CONFIGURATION,
WM8996_AIF1TX_CHAN4_SLOTS_MASK |
WM8996_AIF1TX_CHAN0_START_SLOT_MASK,
1 << WM8996_AIF1TX_CHAN4_SLOTS_SHIFT | 0);
regmap_update_bits(wm8996->regmap,
WM8996_AIF1TX_CHANNEL_5_CONFIGURATION,
WM8996_AIF1TX_CHAN5_SLOTS_MASK |
WM8996_AIF1TX_CHAN0_START_SLOT_MASK,
1 << WM8996_AIF1TX_CHAN5_SLOTS_SHIFT | 1);
regmap_update_bits(wm8996->regmap,
WM8996_AIF2TX_CHANNEL_0_CONFIGURATION,
WM8996_AIF2TX_CHAN0_SLOTS_MASK |
WM8996_AIF2TX_CHAN0_START_SLOT_MASK,
1 << WM8996_AIF2TX_CHAN0_SLOTS_SHIFT | 0);
regmap_update_bits(wm8996->regmap,
WM8996_AIF1TX_CHANNEL_1_CONFIGURATION,
WM8996_AIF2TX_CHAN1_SLOTS_MASK |
WM8996_AIF2TX_CHAN1_START_SLOT_MASK,
1 << WM8996_AIF1TX_CHAN1_SLOTS_SHIFT | 1);
ret = regmap_read(wm8996->regmap, WM8996_GPIO_1, &reg);
if (ret != 0) {
dev_err(&i2c->dev, "Failed to read GPIO1: %d\n", ret);
goto err_regmap;
}
if (reg & WM8996_GP1_FN_MASK)
regmap_update_bits(wm8996->regmap, WM8996_AIF1_TX_LRCLK_2,
WM8996_AIF1TX_LRCLK_MODE,
WM8996_AIF1TX_LRCLK_MODE);
ret = regmap_read(wm8996->regmap, WM8996_GPIO_2, &reg);
if (ret != 0) {
dev_err(&i2c->dev, "Failed to read GPIO2: %d\n", ret);
goto err_regmap;
}
if (reg & WM8996_GP2_FN_MASK)
regmap_update_bits(wm8996->regmap, WM8996_AIF2_TX_LRCLK_2,
WM8996_AIF2TX_LRCLK_MODE,
WM8996_AIF2TX_LRCLK_MODE);
wm8996_init_gpio(wm8996);
ret = snd_soc_register_codec(&i2c->dev,
&soc_codec_dev_wm8996, wm8996_dai,
ARRAY_SIZE(wm8996_dai));
if (ret < 0)
goto err_gpiolib;
return ret;
err_gpiolib:
wm8996_free_gpio(wm8996);
err_regmap:
err_enable:
if (wm8996->pdata.ldo_ena > 0)
gpio_set_value_cansleep(wm8996->pdata.ldo_ena, 0);
regulator_bulk_disable(ARRAY_SIZE(wm8996->supplies), wm8996->supplies);
err_gpio:
if (wm8996->pdata.ldo_ena > 0)
gpio_free(wm8996->pdata.ldo_ena);
err:
return ret;
}
static int wm8996_i2c_remove(struct i2c_client *client)
{
struct wm8996_priv *wm8996 = i2c_get_clientdata(client);
int i;
snd_soc_unregister_codec(&client->dev);
wm8996_free_gpio(wm8996);
if (wm8996->pdata.ldo_ena > 0) {
gpio_set_value_cansleep(wm8996->pdata.ldo_ena, 0);
gpio_free(wm8996->pdata.ldo_ena);
}
for (i = 0; i < ARRAY_SIZE(wm8996->supplies); i++)
regulator_unregister_notifier(wm8996->supplies[i].consumer,
&wm8996->disable_nb[i]);
return 0;
}
