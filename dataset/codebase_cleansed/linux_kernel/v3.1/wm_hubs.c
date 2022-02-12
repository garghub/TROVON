static void wait_for_dc_servo(struct snd_soc_codec *codec, unsigned int op)
{
struct wm_hubs_data *hubs = snd_soc_codec_get_drvdata(codec);
unsigned int reg;
int count = 0;
int timeout;
unsigned int val;
val = op | WM8993_DCS_ENA_CHAN_0 | WM8993_DCS_ENA_CHAN_1;
snd_soc_write(codec, WM8993_DC_SERVO_0, val);
dev_dbg(codec->dev, "Waiting for DC servo...\n");
if (hubs->dcs_done_irq)
timeout = 4;
else
timeout = 400;
do {
count++;
if (hubs->dcs_done_irq)
wait_for_completion_timeout(&hubs->dcs_done,
msecs_to_jiffies(250));
else
msleep(1);
reg = snd_soc_read(codec, WM8993_DC_SERVO_0);
dev_dbg(codec->dev, "DC servo: %x\n", reg);
} while (reg & op && count < timeout);
if (reg & op)
dev_err(codec->dev, "Timed out waiting for DC Servo %x\n",
op);
}
irqreturn_t wm_hubs_dcs_done(int irq, void *data)
{
struct wm_hubs_data *hubs = data;
complete(&hubs->dcs_done);
return IRQ_HANDLED;
}
static void calibrate_dc_servo(struct snd_soc_codec *codec)
{
struct wm_hubs_data *hubs = snd_soc_codec_get_drvdata(codec);
s8 offset;
u16 reg, reg_l, reg_r, dcs_cfg;
if (hubs->class_w && hubs->class_w_dcs) {
dev_dbg(codec->dev, "Using cached DC servo offset %x\n",
hubs->class_w_dcs);
snd_soc_write(codec, WM8993_DC_SERVO_3, hubs->class_w_dcs);
wait_for_dc_servo(codec,
WM8993_DCS_TRIG_DAC_WR_0 |
WM8993_DCS_TRIG_DAC_WR_1);
return;
}
if (hubs->series_startup) {
snd_soc_update_bits(codec, WM8993_DC_SERVO_1,
WM8993_DCS_SERIES_NO_01_MASK,
32 << WM8993_DCS_SERIES_NO_01_SHIFT);
wait_for_dc_servo(codec,
WM8993_DCS_TRIG_SERIES_0 |
WM8993_DCS_TRIG_SERIES_1);
} else {
wait_for_dc_servo(codec,
WM8993_DCS_TRIG_STARTUP_0 |
WM8993_DCS_TRIG_STARTUP_1);
}
switch (hubs->dcs_readback_mode) {
case 0:
reg_l = snd_soc_read(codec, WM8993_DC_SERVO_READBACK_1)
& WM8993_DCS_INTEG_CHAN_0_MASK;
reg_r = snd_soc_read(codec, WM8993_DC_SERVO_READBACK_2)
& WM8993_DCS_INTEG_CHAN_1_MASK;
break;
case 1:
reg = snd_soc_read(codec, WM8993_DC_SERVO_3);
reg_r = (reg & WM8993_DCS_DAC_WR_VAL_1_MASK)
>> WM8993_DCS_DAC_WR_VAL_1_SHIFT;
reg_l = reg & WM8993_DCS_DAC_WR_VAL_0_MASK;
break;
default:
WARN(1, "Unknown DCS readback method\n");
break;
}
dev_dbg(codec->dev, "DCS input: %x %x\n", reg_l, reg_r);
if (hubs->dcs_codes) {
dev_dbg(codec->dev, "Applying %d code DC servo correction\n",
hubs->dcs_codes);
offset = reg_r;
offset += hubs->dcs_codes;
dcs_cfg = (u8)offset << WM8993_DCS_DAC_WR_VAL_1_SHIFT;
offset = reg_l;
offset += hubs->dcs_codes;
dcs_cfg |= (u8)offset;
dev_dbg(codec->dev, "DCS result: %x\n", dcs_cfg);
snd_soc_write(codec, WM8993_DC_SERVO_3, dcs_cfg);
wait_for_dc_servo(codec,
WM8993_DCS_TRIG_DAC_WR_0 |
WM8993_DCS_TRIG_DAC_WR_1);
} else {
dcs_cfg = reg_r << WM8993_DCS_DAC_WR_VAL_1_SHIFT;
dcs_cfg |= reg_l;
}
if (hubs->class_w)
hubs->class_w_dcs = dcs_cfg;
}
static int wm8993_put_dc_servo(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_kcontrol_chip(kcontrol);
struct wm_hubs_data *hubs = snd_soc_codec_get_drvdata(codec);
int ret;
ret = snd_soc_put_volsw_2r(kcontrol, ucontrol);
hubs->class_w_dcs = 0;
if (hubs->dcs_codes || hubs->no_series_update)
return ret;
if (snd_soc_read(codec, WM8993_POWER_MANAGEMENT_1)
& (WM8993_HPOUT1L_ENA | WM8993_HPOUT1R_ENA))
snd_soc_update_bits(codec,
WM8993_DC_SERVO_0,
WM8993_DCS_TRIG_SINGLE_0 |
WM8993_DCS_TRIG_SINGLE_1,
WM8993_DCS_TRIG_SINGLE_0 |
WM8993_DCS_TRIG_SINGLE_1);
return ret;
}
static int hp_supply_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = w->codec;
struct wm_hubs_data *hubs = snd_soc_codec_get_drvdata(codec);
switch (event) {
case SND_SOC_DAPM_PRE_PMU:
switch (hubs->hp_startup_mode) {
case 0:
break;
case 1:
snd_soc_update_bits(codec, WM8993_POWER_MANAGEMENT_1,
WM8993_HPOUT1L_ENA |
WM8993_HPOUT1R_ENA,
WM8993_HPOUT1L_ENA |
WM8993_HPOUT1R_ENA);
snd_soc_update_bits(codec, WM8993_ANALOGUE_HP_0,
WM8993_HPOUT1L_DLY |
WM8993_HPOUT1R_DLY,
WM8993_HPOUT1L_DLY |
WM8993_HPOUT1R_DLY);
break;
default:
dev_err(codec->dev, "Unknown HP startup mode %d\n",
hubs->hp_startup_mode);
break;
}
case SND_SOC_DAPM_PRE_PMD:
snd_soc_update_bits(codec, WM8993_CHARGE_PUMP_1,
WM8993_CP_ENA, 0);
break;
}
return 0;
}
static int hp_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = w->codec;
unsigned int reg = snd_soc_read(codec, WM8993_ANALOGUE_HP_0);
switch (event) {
case SND_SOC_DAPM_POST_PMU:
snd_soc_update_bits(codec, WM8993_CHARGE_PUMP_1,
WM8993_CP_ENA, WM8993_CP_ENA);
msleep(5);
snd_soc_update_bits(codec, WM8993_POWER_MANAGEMENT_1,
WM8993_HPOUT1L_ENA | WM8993_HPOUT1R_ENA,
WM8993_HPOUT1L_ENA | WM8993_HPOUT1R_ENA);
reg |= WM8993_HPOUT1L_DLY | WM8993_HPOUT1R_DLY;
snd_soc_write(codec, WM8993_ANALOGUE_HP_0, reg);
snd_soc_update_bits(codec, WM8993_DC_SERVO_1,
WM8993_DCS_TIMER_PERIOD_01_MASK, 0);
calibrate_dc_servo(codec);
reg |= WM8993_HPOUT1R_OUTP | WM8993_HPOUT1R_RMV_SHORT |
WM8993_HPOUT1L_OUTP | WM8993_HPOUT1L_RMV_SHORT;
snd_soc_write(codec, WM8993_ANALOGUE_HP_0, reg);
break;
case SND_SOC_DAPM_PRE_PMD:
snd_soc_update_bits(codec, WM8993_ANALOGUE_HP_0,
WM8993_HPOUT1L_OUTP |
WM8993_HPOUT1R_OUTP |
WM8993_HPOUT1L_RMV_SHORT |
WM8993_HPOUT1R_RMV_SHORT, 0);
snd_soc_update_bits(codec, WM8993_ANALOGUE_HP_0,
WM8993_HPOUT1L_DLY |
WM8993_HPOUT1R_DLY, 0);
snd_soc_write(codec, WM8993_DC_SERVO_0, 0);
snd_soc_update_bits(codec, WM8993_POWER_MANAGEMENT_1,
WM8993_HPOUT1L_ENA | WM8993_HPOUT1R_ENA,
0);
break;
}
return 0;
}
static int earpiece_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *control, int event)
{
struct snd_soc_codec *codec = w->codec;
u16 reg = snd_soc_read(codec, WM8993_ANTIPOP1) & ~WM8993_HPOUT2_IN_ENA;
switch (event) {
case SND_SOC_DAPM_PRE_PMU:
reg |= WM8993_HPOUT2_IN_ENA;
snd_soc_write(codec, WM8993_ANTIPOP1, reg);
udelay(50);
break;
case SND_SOC_DAPM_POST_PMD:
snd_soc_write(codec, WM8993_ANTIPOP1, reg);
break;
default:
BUG();
break;
}
return 0;
}
int wm_hubs_add_analogue_controls(struct snd_soc_codec *codec)
{
struct snd_soc_dapm_context *dapm = &codec->dapm;
snd_soc_update_bits(codec, WM8993_LEFT_LINE_INPUT_1_2_VOLUME,
WM8993_IN1_VU, WM8993_IN1_VU);
snd_soc_update_bits(codec, WM8993_RIGHT_LINE_INPUT_1_2_VOLUME,
WM8993_IN1_VU, WM8993_IN1_VU);
snd_soc_update_bits(codec, WM8993_LEFT_LINE_INPUT_3_4_VOLUME,
WM8993_IN2_VU, WM8993_IN2_VU);
snd_soc_update_bits(codec, WM8993_RIGHT_LINE_INPUT_3_4_VOLUME,
WM8993_IN2_VU, WM8993_IN2_VU);
snd_soc_update_bits(codec, WM8993_SPEAKER_VOLUME_LEFT,
WM8993_SPKOUT_VU, WM8993_SPKOUT_VU);
snd_soc_update_bits(codec, WM8993_SPEAKER_VOLUME_RIGHT,
WM8993_SPKOUT_VU, WM8993_SPKOUT_VU);
snd_soc_update_bits(codec, WM8993_LEFT_OUTPUT_VOLUME,
WM8993_HPOUT1_VU | WM8993_HPOUT1L_ZC,
WM8993_HPOUT1_VU | WM8993_HPOUT1L_ZC);
snd_soc_update_bits(codec, WM8993_RIGHT_OUTPUT_VOLUME,
WM8993_HPOUT1_VU | WM8993_HPOUT1R_ZC,
WM8993_HPOUT1_VU | WM8993_HPOUT1R_ZC);
snd_soc_update_bits(codec, WM8993_LEFT_OPGA_VOLUME,
WM8993_MIXOUTL_ZC | WM8993_MIXOUT_VU,
WM8993_MIXOUTL_ZC | WM8993_MIXOUT_VU);
snd_soc_update_bits(codec, WM8993_RIGHT_OPGA_VOLUME,
WM8993_MIXOUTR_ZC | WM8993_MIXOUT_VU,
WM8993_MIXOUTR_ZC | WM8993_MIXOUT_VU);
snd_soc_add_controls(codec, analogue_snd_controls,
ARRAY_SIZE(analogue_snd_controls));
snd_soc_dapm_new_controls(dapm, analogue_dapm_widgets,
ARRAY_SIZE(analogue_dapm_widgets));
return 0;
}
int wm_hubs_add_analogue_routes(struct snd_soc_codec *codec,
int lineout1_diff, int lineout2_diff)
{
struct wm_hubs_data *hubs = snd_soc_codec_get_drvdata(codec);
struct snd_soc_dapm_context *dapm = &codec->dapm;
init_completion(&hubs->dcs_done);
snd_soc_dapm_add_routes(dapm, analogue_routes,
ARRAY_SIZE(analogue_routes));
if (lineout1_diff)
snd_soc_dapm_add_routes(dapm,
lineout1_diff_routes,
ARRAY_SIZE(lineout1_diff_routes));
else
snd_soc_dapm_add_routes(dapm,
lineout1_se_routes,
ARRAY_SIZE(lineout1_se_routes));
if (lineout2_diff)
snd_soc_dapm_add_routes(dapm,
lineout2_diff_routes,
ARRAY_SIZE(lineout2_diff_routes));
else
snd_soc_dapm_add_routes(dapm,
lineout2_se_routes,
ARRAY_SIZE(lineout2_se_routes));
return 0;
}
int wm_hubs_handle_analogue_pdata(struct snd_soc_codec *codec,
int lineout1_diff, int lineout2_diff,
int lineout1fb, int lineout2fb,
int jd_scthr, int jd_thr, int micbias1_lvl,
int micbias2_lvl)
{
if (!lineout1_diff)
snd_soc_update_bits(codec, WM8993_LINE_MIXER1,
WM8993_LINEOUT1_MODE,
WM8993_LINEOUT1_MODE);
if (!lineout2_diff)
snd_soc_update_bits(codec, WM8993_LINE_MIXER2,
WM8993_LINEOUT2_MODE,
WM8993_LINEOUT2_MODE);
if (lineout1_diff && lineout2_diff)
codec->dapm.idle_bias_off = 1;
if (lineout1fb)
snd_soc_update_bits(codec, WM8993_ADDITIONAL_CONTROL,
WM8993_LINEOUT1_FB, WM8993_LINEOUT1_FB);
if (lineout2fb)
snd_soc_update_bits(codec, WM8993_ADDITIONAL_CONTROL,
WM8993_LINEOUT2_FB, WM8993_LINEOUT2_FB);
snd_soc_update_bits(codec, WM8993_MICBIAS,
WM8993_JD_SCTHR_MASK | WM8993_JD_THR_MASK |
WM8993_MICB1_LVL | WM8993_MICB2_LVL,
jd_scthr << WM8993_JD_SCTHR_SHIFT |
jd_thr << WM8993_JD_THR_SHIFT |
micbias1_lvl |
micbias2_lvl << WM8993_MICB2_LVL_SHIFT);
return 0;
}
