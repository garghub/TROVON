static int wm9090_volatile(struct snd_soc_codec *codec, unsigned int reg)
{
switch (reg) {
case WM9090_SOFTWARE_RESET:
case WM9090_DC_SERVO_0:
case WM9090_DC_SERVO_READBACK_0:
case WM9090_DC_SERVO_READBACK_1:
case WM9090_DC_SERVO_READBACK_2:
return 1;
default:
return 0;
}
}
static void wait_for_dc_servo(struct snd_soc_codec *codec)
{
unsigned int reg;
int count = 0;
dev_dbg(codec->dev, "Waiting for DC servo...\n");
do {
count++;
msleep(1);
reg = snd_soc_read(codec, WM9090_DC_SERVO_READBACK_0);
dev_dbg(codec->dev, "DC servo status: %x\n", reg);
} while ((reg & WM9090_DCS_CAL_COMPLETE_MASK)
!= WM9090_DCS_CAL_COMPLETE_MASK && count < 1000);
if ((reg & WM9090_DCS_CAL_COMPLETE_MASK)
!= WM9090_DCS_CAL_COMPLETE_MASK)
dev_err(codec->dev, "Timed out waiting for DC Servo\n");
}
static int hp_ev(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = w->codec;
unsigned int reg = snd_soc_read(codec, WM9090_ANALOGUE_HP_0);
switch (event) {
case SND_SOC_DAPM_POST_PMU:
snd_soc_update_bits(codec, WM9090_CHARGE_PUMP_1,
WM9090_CP_ENA, WM9090_CP_ENA);
msleep(5);
snd_soc_update_bits(codec, WM9090_POWER_MANAGEMENT_1,
WM9090_HPOUT1L_ENA | WM9090_HPOUT1R_ENA,
WM9090_HPOUT1L_ENA | WM9090_HPOUT1R_ENA);
reg |= WM9090_HPOUT1L_DLY | WM9090_HPOUT1R_DLY;
snd_soc_write(codec, WM9090_ANALOGUE_HP_0, reg);
snd_soc_write(codec, WM9090_DC_SERVO_0,
WM9090_DCS_ENA_CHAN_0 |
WM9090_DCS_ENA_CHAN_1 |
WM9090_DCS_TRIG_STARTUP_1 |
WM9090_DCS_TRIG_STARTUP_0);
wait_for_dc_servo(codec);
reg |= WM9090_HPOUT1R_OUTP | WM9090_HPOUT1R_RMV_SHORT |
WM9090_HPOUT1L_OUTP | WM9090_HPOUT1L_RMV_SHORT;
snd_soc_write(codec, WM9090_ANALOGUE_HP_0, reg);
break;
case SND_SOC_DAPM_PRE_PMD:
reg &= ~(WM9090_HPOUT1L_RMV_SHORT |
WM9090_HPOUT1L_DLY |
WM9090_HPOUT1L_OUTP |
WM9090_HPOUT1R_RMV_SHORT |
WM9090_HPOUT1R_DLY |
WM9090_HPOUT1R_OUTP);
snd_soc_write(codec, WM9090_ANALOGUE_HP_0, reg);
snd_soc_write(codec, WM9090_DC_SERVO_0, 0);
snd_soc_update_bits(codec, WM9090_POWER_MANAGEMENT_1,
WM9090_HPOUT1L_ENA | WM9090_HPOUT1R_ENA,
0);
snd_soc_update_bits(codec, WM9090_CHARGE_PUMP_1,
WM9090_CP_ENA, 0);
break;
}
return 0;
}
static int wm9090_add_controls(struct snd_soc_codec *codec)
{
struct wm9090_priv *wm9090 = snd_soc_codec_get_drvdata(codec);
struct snd_soc_dapm_context *dapm = &codec->dapm;
int i;
snd_soc_dapm_new_controls(dapm, wm9090_dapm_widgets,
ARRAY_SIZE(wm9090_dapm_widgets));
snd_soc_dapm_add_routes(dapm, audio_map, ARRAY_SIZE(audio_map));
snd_soc_add_controls(codec, wm9090_controls,
ARRAY_SIZE(wm9090_controls));
if (wm9090->pdata.lin1_diff) {
snd_soc_dapm_add_routes(dapm, audio_map_in1_diff,
ARRAY_SIZE(audio_map_in1_diff));
} else {
snd_soc_dapm_add_routes(dapm, audio_map_in1_se,
ARRAY_SIZE(audio_map_in1_se));
snd_soc_add_controls(codec, wm9090_in1_se_controls,
ARRAY_SIZE(wm9090_in1_se_controls));
}
if (wm9090->pdata.lin2_diff) {
snd_soc_dapm_add_routes(dapm, audio_map_in2_diff,
ARRAY_SIZE(audio_map_in2_diff));
} else {
snd_soc_dapm_add_routes(dapm, audio_map_in2_se,
ARRAY_SIZE(audio_map_in2_se));
snd_soc_add_controls(codec, wm9090_in2_se_controls,
ARRAY_SIZE(wm9090_in2_se_controls));
}
if (wm9090->pdata.agc_ena) {
for (i = 0; i < ARRAY_SIZE(wm9090->pdata.agc); i++)
snd_soc_write(codec, WM9090_AGC_CONTROL_0 + i,
wm9090->pdata.agc[i]);
snd_soc_update_bits(codec, WM9090_POWER_MANAGEMENT_3,
WM9090_AGC_ENA, WM9090_AGC_ENA);
} else {
snd_soc_update_bits(codec, WM9090_POWER_MANAGEMENT_3,
WM9090_AGC_ENA, 0);
}
return 0;
}
static int wm9090_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
u16 *reg_cache = codec->reg_cache;
int i, ret;
switch (level) {
case SND_SOC_BIAS_ON:
break;
case SND_SOC_BIAS_PREPARE:
snd_soc_update_bits(codec, WM9090_ANTIPOP2, WM9090_VMID_ENA,
WM9090_VMID_ENA);
snd_soc_update_bits(codec, WM9090_POWER_MANAGEMENT_1,
WM9090_BIAS_ENA |
WM9090_VMID_RES_MASK,
WM9090_BIAS_ENA |
1 << WM9090_VMID_RES_SHIFT);
msleep(1);
break;
case SND_SOC_BIAS_STANDBY:
if (codec->dapm.bias_level == SND_SOC_BIAS_OFF) {
for (i = 1; i < codec->driver->reg_cache_size; i++) {
if (reg_cache[i] == wm9090_reg_defaults[i])
continue;
if (wm9090_volatile(codec, i))
continue;
ret = snd_soc_write(codec, i, reg_cache[i]);
if (ret != 0)
dev_warn(codec->dev,
"Failed to restore register %d: %d\n",
i, ret);
}
}
snd_soc_update_bits(codec, WM9090_POWER_MANAGEMENT_1,
WM9090_BIAS_ENA | WM9090_VMID_RES_MASK, 0);
snd_soc_update_bits(codec, WM9090_ANTIPOP2,
WM9090_VMID_ENA, 0);
break;
case SND_SOC_BIAS_OFF:
break;
}
codec->dapm.bias_level = level;
return 0;
}
static int wm9090_probe(struct snd_soc_codec *codec)
{
int ret;
ret = snd_soc_codec_set_cache_io(codec, 8, 16, SND_SOC_I2C);
if (ret != 0) {
dev_err(codec->dev, "Failed to set cache I/O: %d\n", ret);
return ret;
}
ret = snd_soc_read(codec, WM9090_SOFTWARE_RESET);
if (ret < 0)
return ret;
if (ret != wm9090_reg_defaults[WM9090_SOFTWARE_RESET]) {
dev_err(codec->dev, "Device is not a WM9090, ID=%x\n", ret);
return -EINVAL;
}
ret = snd_soc_write(codec, WM9090_SOFTWARE_RESET, 0);
if (ret < 0)
return ret;
snd_soc_update_bits(codec, WM9090_IN1_LINE_INPUT_A_VOLUME,
WM9090_IN1_VU | WM9090_IN1A_ZC,
WM9090_IN1_VU | WM9090_IN1A_ZC);
snd_soc_update_bits(codec, WM9090_IN1_LINE_INPUT_B_VOLUME,
WM9090_IN1_VU | WM9090_IN1B_ZC,
WM9090_IN1_VU | WM9090_IN1B_ZC);
snd_soc_update_bits(codec, WM9090_IN2_LINE_INPUT_A_VOLUME,
WM9090_IN2_VU | WM9090_IN2A_ZC,
WM9090_IN2_VU | WM9090_IN2A_ZC);
snd_soc_update_bits(codec, WM9090_IN2_LINE_INPUT_B_VOLUME,
WM9090_IN2_VU | WM9090_IN2B_ZC,
WM9090_IN2_VU | WM9090_IN2B_ZC);
snd_soc_update_bits(codec, WM9090_SPEAKER_VOLUME_LEFT,
WM9090_SPKOUT_VU | WM9090_SPKOUTL_ZC,
WM9090_SPKOUT_VU | WM9090_SPKOUTL_ZC);
snd_soc_update_bits(codec, WM9090_LEFT_OUTPUT_VOLUME,
WM9090_HPOUT1_VU | WM9090_HPOUT1L_ZC,
WM9090_HPOUT1_VU | WM9090_HPOUT1L_ZC);
snd_soc_update_bits(codec, WM9090_RIGHT_OUTPUT_VOLUME,
WM9090_HPOUT1_VU | WM9090_HPOUT1R_ZC,
WM9090_HPOUT1_VU | WM9090_HPOUT1R_ZC);
snd_soc_update_bits(codec, WM9090_CLOCKING_1,
WM9090_TOCLK_ENA, WM9090_TOCLK_ENA);
wm9090_set_bias_level(codec, SND_SOC_BIAS_STANDBY);
wm9090_add_controls(codec);
return 0;
}
static int wm9090_suspend(struct snd_soc_codec *codec, pm_message_t state)
{
wm9090_set_bias_level(codec, SND_SOC_BIAS_OFF);
return 0;
}
static int wm9090_resume(struct snd_soc_codec *codec)
{
wm9090_set_bias_level(codec, SND_SOC_BIAS_STANDBY);
return 0;
}
static int wm9090_remove(struct snd_soc_codec *codec)
{
wm9090_set_bias_level(codec, SND_SOC_BIAS_OFF);
return 0;
}
static int wm9090_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct wm9090_priv *wm9090;
int ret;
wm9090 = kzalloc(sizeof(*wm9090), GFP_KERNEL);
if (wm9090 == NULL) {
dev_err(&i2c->dev, "Can not allocate memory\n");
return -ENOMEM;
}
if (i2c->dev.platform_data)
memcpy(&wm9090->pdata, i2c->dev.platform_data,
sizeof(wm9090->pdata));
i2c_set_clientdata(i2c, wm9090);
ret = snd_soc_register_codec(&i2c->dev,
&soc_codec_dev_wm9090, NULL, 0);
if (ret < 0)
kfree(wm9090);
return ret;
}
static int __devexit wm9090_i2c_remove(struct i2c_client *i2c)
{
struct wm9090_priv *wm9090 = i2c_get_clientdata(i2c);
snd_soc_unregister_codec(&i2c->dev);
kfree(wm9090);
return 0;
}
static int __init wm9090_init(void)
{
return i2c_add_driver(&wm9090_i2c_driver);
}
static void __exit wm9090_exit(void)
{
i2c_del_driver(&wm9090_i2c_driver);
}
