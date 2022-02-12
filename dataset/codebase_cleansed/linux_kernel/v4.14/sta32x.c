static int sta32x_coefficient_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
int numcoef = kcontrol->private_value >> 16;
uinfo->type = SNDRV_CTL_ELEM_TYPE_BYTES;
uinfo->count = 3 * numcoef;
return 0;
}
static int sta32x_coefficient_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_soc_kcontrol_codec(kcontrol);
struct sta32x_priv *sta32x = snd_soc_codec_get_drvdata(codec);
int numcoef = kcontrol->private_value >> 16;
int index = kcontrol->private_value & 0xffff;
unsigned int cfud, val;
int i, ret = 0;
mutex_lock(&sta32x->coeff_lock);
regmap_read(sta32x->regmap, STA32X_CFUD, &cfud);
cfud &= 0xf0;
regmap_write(sta32x->regmap, STA32X_CFUD, cfud);
regmap_write(sta32x->regmap, STA32X_CFADDR2, index);
if (numcoef == 1) {
regmap_write(sta32x->regmap, STA32X_CFUD, cfud | 0x04);
} else if (numcoef == 5) {
regmap_write(sta32x->regmap, STA32X_CFUD, cfud | 0x08);
} else {
ret = -EINVAL;
goto exit_unlock;
}
for (i = 0; i < 3 * numcoef; i++) {
regmap_read(sta32x->regmap, STA32X_B1CF1 + i, &val);
ucontrol->value.bytes.data[i] = val;
}
exit_unlock:
mutex_unlock(&sta32x->coeff_lock);
return ret;
}
static int sta32x_coefficient_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_soc_kcontrol_codec(kcontrol);
struct sta32x_priv *sta32x = snd_soc_codec_get_drvdata(codec);
int numcoef = kcontrol->private_value >> 16;
int index = kcontrol->private_value & 0xffff;
unsigned int cfud;
int i;
regmap_read(sta32x->regmap, STA32X_CFUD, &cfud);
cfud &= 0xf0;
regmap_write(sta32x->regmap, STA32X_CFUD, cfud);
regmap_write(sta32x->regmap, STA32X_CFADDR2, index);
for (i = 0; i < numcoef && (index + i < STA32X_COEF_COUNT); i++)
sta32x->coef_shadow[index + i] =
(ucontrol->value.bytes.data[3 * i] << 16)
| (ucontrol->value.bytes.data[3 * i + 1] << 8)
| (ucontrol->value.bytes.data[3 * i + 2]);
for (i = 0; i < 3 * numcoef; i++)
regmap_write(sta32x->regmap, STA32X_B1CF1 + i,
ucontrol->value.bytes.data[i]);
if (numcoef == 1)
regmap_write(sta32x->regmap, STA32X_CFUD, cfud | 0x01);
else if (numcoef == 5)
regmap_write(sta32x->regmap, STA32X_CFUD, cfud | 0x02);
else
return -EINVAL;
return 0;
}
static int sta32x_sync_coef_shadow(struct snd_soc_codec *codec)
{
struct sta32x_priv *sta32x = snd_soc_codec_get_drvdata(codec);
unsigned int cfud;
int i;
regmap_read(sta32x->regmap, STA32X_CFUD, &cfud);
cfud &= 0xf0;
for (i = 0; i < STA32X_COEF_COUNT; i++) {
regmap_write(sta32x->regmap, STA32X_CFADDR2, i);
regmap_write(sta32x->regmap, STA32X_B1CF1,
(sta32x->coef_shadow[i] >> 16) & 0xff);
regmap_write(sta32x->regmap, STA32X_B1CF2,
(sta32x->coef_shadow[i] >> 8) & 0xff);
regmap_write(sta32x->regmap, STA32X_B1CF3,
(sta32x->coef_shadow[i]) & 0xff);
regmap_write(sta32x->regmap, STA32X_CFUD, cfud);
regmap_write(sta32x->regmap, STA32X_CFUD, cfud | 0x01);
}
return 0;
}
static int sta32x_cache_sync(struct snd_soc_codec *codec)
{
struct sta32x_priv *sta32x = snd_soc_codec_get_drvdata(codec);
unsigned int mute;
int rc;
regmap_read(sta32x->regmap, STA32X_MMUTE, &mute);
regmap_write(sta32x->regmap, STA32X_MMUTE, mute | STA32X_MMUTE_MMUTE);
sta32x_sync_coef_shadow(codec);
rc = regcache_sync(sta32x->regmap);
regmap_write(sta32x->regmap, STA32X_MMUTE, mute);
return rc;
}
static void sta32x_watchdog(struct work_struct *work)
{
struct sta32x_priv *sta32x = container_of(work, struct sta32x_priv,
watchdog_work.work);
struct snd_soc_codec *codec = sta32x->codec;
unsigned int confa, confa_cached;
confa_cached = snd_soc_read(codec, STA32X_CONFA);
regcache_cache_bypass(sta32x->regmap, true);
confa = snd_soc_read(codec, STA32X_CONFA);
regcache_cache_bypass(sta32x->regmap, false);
if (confa != confa_cached) {
regcache_mark_dirty(sta32x->regmap);
sta32x_cache_sync(codec);
}
if (!sta32x->shutdown)
queue_delayed_work(system_power_efficient_wq,
&sta32x->watchdog_work,
round_jiffies_relative(HZ));
}
static void sta32x_watchdog_start(struct sta32x_priv *sta32x)
{
if (sta32x->pdata->needs_esd_watchdog) {
sta32x->shutdown = 0;
queue_delayed_work(system_power_efficient_wq,
&sta32x->watchdog_work,
round_jiffies_relative(HZ));
}
}
static void sta32x_watchdog_stop(struct sta32x_priv *sta32x)
{
if (sta32x->pdata->needs_esd_watchdog) {
sta32x->shutdown = 1;
cancel_delayed_work_sync(&sta32x->watchdog_work);
}
}
static int sta32x_set_dai_sysclk(struct snd_soc_dai *codec_dai,
int clk_id, unsigned int freq, int dir)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct sta32x_priv *sta32x = snd_soc_codec_get_drvdata(codec);
dev_dbg(codec->dev, "mclk=%u\n", freq);
sta32x->mclk = freq;
return 0;
}
static int sta32x_set_dai_fmt(struct snd_soc_dai *codec_dai,
unsigned int fmt)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct sta32x_priv *sta32x = snd_soc_codec_get_drvdata(codec);
u8 confb = 0;
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBS_CFS:
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
case SND_SOC_DAIFMT_RIGHT_J:
case SND_SOC_DAIFMT_LEFT_J:
sta32x->format = fmt & SND_SOC_DAIFMT_FORMAT_MASK;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
confb |= STA32X_CONFB_C2IM;
break;
case SND_SOC_DAIFMT_NB_IF:
confb |= STA32X_CONFB_C1IM;
break;
default:
return -EINVAL;
}
return regmap_update_bits(sta32x->regmap, STA32X_CONFB,
STA32X_CONFB_C1IM | STA32X_CONFB_C2IM, confb);
}
static int sta32x_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct sta32x_priv *sta32x = snd_soc_codec_get_drvdata(codec);
int i, mcs = -EINVAL, ir = -EINVAL;
unsigned int confa, confb;
unsigned int rate, ratio;
int ret;
if (!sta32x->mclk) {
dev_err(codec->dev,
"sta32x->mclk is unset. Unable to determine ratio\n");
return -EIO;
}
rate = params_rate(params);
ratio = sta32x->mclk / rate;
dev_dbg(codec->dev, "rate: %u, ratio: %u\n", rate, ratio);
for (i = 0; i < ARRAY_SIZE(interpolation_ratios); i++) {
if (interpolation_ratios[i].fs == rate) {
ir = interpolation_ratios[i].ir;
break;
}
}
if (ir < 0) {
dev_err(codec->dev, "Unsupported samplerate: %u\n", rate);
return -EINVAL;
}
for (i = 0; i < 6; i++) {
if (mcs_ratio_table[ir][i] == ratio) {
mcs = i;
break;
}
}
if (mcs < 0) {
dev_err(codec->dev, "Unresolvable ratio: %u\n", ratio);
return -EINVAL;
}
confa = (ir << STA32X_CONFA_IR_SHIFT) |
(mcs << STA32X_CONFA_MCS_SHIFT);
confb = 0;
switch (params_width(params)) {
case 24:
dev_dbg(codec->dev, "24bit\n");
case 32:
dev_dbg(codec->dev, "24bit or 32bit\n");
switch (sta32x->format) {
case SND_SOC_DAIFMT_I2S:
confb |= 0x0;
break;
case SND_SOC_DAIFMT_LEFT_J:
confb |= 0x1;
break;
case SND_SOC_DAIFMT_RIGHT_J:
confb |= 0x2;
break;
}
break;
case 20:
dev_dbg(codec->dev, "20bit\n");
switch (sta32x->format) {
case SND_SOC_DAIFMT_I2S:
confb |= 0x4;
break;
case SND_SOC_DAIFMT_LEFT_J:
confb |= 0x5;
break;
case SND_SOC_DAIFMT_RIGHT_J:
confb |= 0x6;
break;
}
break;
case 18:
dev_dbg(codec->dev, "18bit\n");
switch (sta32x->format) {
case SND_SOC_DAIFMT_I2S:
confb |= 0x8;
break;
case SND_SOC_DAIFMT_LEFT_J:
confb |= 0x9;
break;
case SND_SOC_DAIFMT_RIGHT_J:
confb |= 0xa;
break;
}
break;
case 16:
dev_dbg(codec->dev, "16bit\n");
switch (sta32x->format) {
case SND_SOC_DAIFMT_I2S:
confb |= 0x0;
break;
case SND_SOC_DAIFMT_LEFT_J:
confb |= 0xd;
break;
case SND_SOC_DAIFMT_RIGHT_J:
confb |= 0xe;
break;
}
break;
default:
return -EINVAL;
}
ret = regmap_update_bits(sta32x->regmap, STA32X_CONFA,
STA32X_CONFA_MCS_MASK | STA32X_CONFA_IR_MASK,
confa);
if (ret < 0)
return ret;
ret = regmap_update_bits(sta32x->regmap, STA32X_CONFB,
STA32X_CONFB_SAI_MASK | STA32X_CONFB_SAIFB,
confb);
if (ret < 0)
return ret;
return 0;
}
static int sta32x_startup_sequence(struct sta32x_priv *sta32x)
{
if (sta32x->gpiod_nreset) {
gpiod_set_value(sta32x->gpiod_nreset, 0);
mdelay(1);
gpiod_set_value(sta32x->gpiod_nreset, 1);
mdelay(1);
}
return 0;
}
static int sta32x_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
int ret;
struct sta32x_priv *sta32x = snd_soc_codec_get_drvdata(codec);
dev_dbg(codec->dev, "level = %d\n", level);
switch (level) {
case SND_SOC_BIAS_ON:
break;
case SND_SOC_BIAS_PREPARE:
regmap_update_bits(sta32x->regmap, STA32X_CONFF,
STA32X_CONFF_PWDN | STA32X_CONFF_EAPD,
STA32X_CONFF_PWDN | STA32X_CONFF_EAPD);
break;
case SND_SOC_BIAS_STANDBY:
if (snd_soc_codec_get_bias_level(codec) == SND_SOC_BIAS_OFF) {
ret = regulator_bulk_enable(ARRAY_SIZE(sta32x->supplies),
sta32x->supplies);
if (ret != 0) {
dev_err(codec->dev,
"Failed to enable supplies: %d\n", ret);
return ret;
}
sta32x_startup_sequence(sta32x);
sta32x_cache_sync(codec);
sta32x_watchdog_start(sta32x);
}
regmap_update_bits(sta32x->regmap, STA32X_CONFF,
STA32X_CONFF_PWDN | STA32X_CONFF_EAPD,
0);
break;
case SND_SOC_BIAS_OFF:
regmap_update_bits(sta32x->regmap, STA32X_CONFF,
STA32X_CONFF_PWDN | STA32X_CONFF_EAPD, 0);
msleep(300);
sta32x_watchdog_stop(sta32x);
gpiod_set_value(sta32x->gpiod_nreset, 0);
regulator_bulk_disable(ARRAY_SIZE(sta32x->supplies),
sta32x->supplies);
break;
}
return 0;
}
static int sta32x_probe(struct snd_soc_codec *codec)
{
struct sta32x_priv *sta32x = snd_soc_codec_get_drvdata(codec);
struct sta32x_platform_data *pdata = sta32x->pdata;
int i, ret = 0, thermal = 0;
ret = regulator_bulk_enable(ARRAY_SIZE(sta32x->supplies),
sta32x->supplies);
if (ret != 0) {
dev_err(codec->dev, "Failed to enable supplies: %d\n", ret);
return ret;
}
ret = sta32x_startup_sequence(sta32x);
if (ret < 0) {
dev_err(codec->dev, "Failed to startup device\n");
return ret;
}
if (!pdata->thermal_warning_recovery)
thermal |= STA32X_CONFA_TWAB;
if (!pdata->thermal_warning_adjustment)
thermal |= STA32X_CONFA_TWRB;
if (!pdata->fault_detect_recovery)
thermal |= STA32X_CONFA_FDRB;
regmap_update_bits(sta32x->regmap, STA32X_CONFA,
STA32X_CONFA_TWAB | STA32X_CONFA_TWRB |
STA32X_CONFA_FDRB,
thermal);
regmap_update_bits(sta32x->regmap, STA32X_CONFC,
STA32X_CONFC_CSZ_MASK,
pdata->drop_compensation_ns
<< STA32X_CONFC_CSZ_SHIFT);
regmap_update_bits(sta32x->regmap, STA32X_CONFE,
STA32X_CONFE_MPCV,
pdata->max_power_use_mpcc ?
STA32X_CONFE_MPCV : 0);
regmap_update_bits(sta32x->regmap, STA32X_CONFE,
STA32X_CONFE_MPC,
pdata->max_power_correction ?
STA32X_CONFE_MPC : 0);
regmap_update_bits(sta32x->regmap, STA32X_CONFE,
STA32X_CONFE_AME,
pdata->am_reduction_mode ?
STA32X_CONFE_AME : 0);
regmap_update_bits(sta32x->regmap, STA32X_CONFE,
STA32X_CONFE_PWMS,
pdata->odd_pwm_speed_mode ?
STA32X_CONFE_PWMS : 0);
regmap_update_bits(sta32x->regmap, STA32X_CONFF,
STA32X_CONFF_IDE,
pdata->invalid_input_detect_mute ?
STA32X_CONFF_IDE : 0);
regmap_update_bits(sta32x->regmap, STA32X_CONFF,
STA32X_CONFF_OCFG_MASK,
pdata->output_conf
<< STA32X_CONFF_OCFG_SHIFT);
regmap_update_bits(sta32x->regmap, STA32X_C1CFG,
STA32X_CxCFG_OM_MASK,
pdata->ch1_output_mapping
<< STA32X_CxCFG_OM_SHIFT);
regmap_update_bits(sta32x->regmap, STA32X_C2CFG,
STA32X_CxCFG_OM_MASK,
pdata->ch2_output_mapping
<< STA32X_CxCFG_OM_SHIFT);
regmap_update_bits(sta32x->regmap, STA32X_C3CFG,
STA32X_CxCFG_OM_MASK,
pdata->ch3_output_mapping
<< STA32X_CxCFG_OM_SHIFT);
for (i = 4; i <= 49; i += 5)
sta32x->coef_shadow[i] = 0x400000;
for (i = 50; i <= 54; i++)
sta32x->coef_shadow[i] = 0x7fffff;
sta32x->coef_shadow[55] = 0x5a9df7;
sta32x->coef_shadow[56] = 0x7fffff;
sta32x->coef_shadow[59] = 0x7fffff;
sta32x->coef_shadow[60] = 0x400000;
sta32x->coef_shadow[61] = 0x400000;
if (sta32x->pdata->needs_esd_watchdog)
INIT_DELAYED_WORK(&sta32x->watchdog_work, sta32x_watchdog);
snd_soc_codec_force_bias_level(codec, SND_SOC_BIAS_STANDBY);
regulator_bulk_disable(ARRAY_SIZE(sta32x->supplies), sta32x->supplies);
return 0;
}
static int sta32x_remove(struct snd_soc_codec *codec)
{
struct sta32x_priv *sta32x = snd_soc_codec_get_drvdata(codec);
sta32x_watchdog_stop(sta32x);
regulator_bulk_disable(ARRAY_SIZE(sta32x->supplies), sta32x->supplies);
return 0;
}
static int sta32x_probe_dt(struct device *dev, struct sta32x_priv *sta32x)
{
struct device_node *np = dev->of_node;
struct sta32x_platform_data *pdata;
u16 tmp;
pdata = devm_kzalloc(dev, sizeof(*pdata), GFP_KERNEL);
if (!pdata)
return -ENOMEM;
of_property_read_u8(np, "st,output-conf",
&pdata->output_conf);
of_property_read_u8(np, "st,ch1-output-mapping",
&pdata->ch1_output_mapping);
of_property_read_u8(np, "st,ch2-output-mapping",
&pdata->ch2_output_mapping);
of_property_read_u8(np, "st,ch3-output-mapping",
&pdata->ch3_output_mapping);
if (of_get_property(np, "st,thermal-warning-recovery", NULL))
pdata->thermal_warning_recovery = 1;
if (of_get_property(np, "st,thermal-warning-adjustment", NULL))
pdata->thermal_warning_adjustment = 1;
if (of_get_property(np, "st,needs_esd_watchdog", NULL))
pdata->needs_esd_watchdog = 1;
tmp = 140;
of_property_read_u16(np, "st,drop-compensation-ns", &tmp);
pdata->drop_compensation_ns = clamp_t(u16, tmp, 0, 300) / 20;
if (of_get_property(np, "st,max-power-use-mpcc", NULL))
pdata->max_power_use_mpcc = 1;
if (of_get_property(np, "st,max-power-correction", NULL))
pdata->max_power_correction = 1;
if (of_get_property(np, "st,am-reduction-mode", NULL))
pdata->am_reduction_mode = 1;
if (of_get_property(np, "st,odd-pwm-speed-mode", NULL))
pdata->odd_pwm_speed_mode = 1;
if (of_get_property(np, "st,invalid-input-detect-mute", NULL))
pdata->invalid_input_detect_mute = 1;
sta32x->pdata = pdata;
return 0;
}
static int sta32x_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct device *dev = &i2c->dev;
struct sta32x_priv *sta32x;
int ret, i;
sta32x = devm_kzalloc(&i2c->dev, sizeof(struct sta32x_priv),
GFP_KERNEL);
if (!sta32x)
return -ENOMEM;
mutex_init(&sta32x->coeff_lock);
sta32x->pdata = dev_get_platdata(dev);
#ifdef CONFIG_OF
if (dev->of_node) {
ret = sta32x_probe_dt(dev, sta32x);
if (ret < 0)
return ret;
}
#endif
sta32x->gpiod_nreset = devm_gpiod_get_optional(dev, "reset",
GPIOD_OUT_LOW);
if (IS_ERR(sta32x->gpiod_nreset))
return PTR_ERR(sta32x->gpiod_nreset);
for (i = 0; i < ARRAY_SIZE(sta32x->supplies); i++)
sta32x->supplies[i].supply = sta32x_supply_names[i];
ret = devm_regulator_bulk_get(&i2c->dev, ARRAY_SIZE(sta32x->supplies),
sta32x->supplies);
if (ret != 0) {
dev_err(&i2c->dev, "Failed to request supplies: %d\n", ret);
return ret;
}
sta32x->regmap = devm_regmap_init_i2c(i2c, &sta32x_regmap);
if (IS_ERR(sta32x->regmap)) {
ret = PTR_ERR(sta32x->regmap);
dev_err(dev, "Failed to init regmap: %d\n", ret);
return ret;
}
i2c_set_clientdata(i2c, sta32x);
ret = snd_soc_register_codec(dev, &sta32x_codec, &sta32x_dai, 1);
if (ret < 0)
dev_err(dev, "Failed to register codec (%d)\n", ret);
return ret;
}
static int sta32x_i2c_remove(struct i2c_client *client)
{
snd_soc_unregister_codec(&client->dev);
return 0;
}
