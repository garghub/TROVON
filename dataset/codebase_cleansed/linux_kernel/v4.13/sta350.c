static int sta350_coefficient_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
int numcoef = kcontrol->private_value >> 16;
uinfo->type = SNDRV_CTL_ELEM_TYPE_BYTES;
uinfo->count = 3 * numcoef;
return 0;
}
static int sta350_coefficient_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_soc_kcontrol_codec(kcontrol);
struct sta350_priv *sta350 = snd_soc_codec_get_drvdata(codec);
int numcoef = kcontrol->private_value >> 16;
int index = kcontrol->private_value & 0xffff;
unsigned int cfud, val;
int i, ret = 0;
mutex_lock(&sta350->coeff_lock);
regmap_read(sta350->regmap, STA350_CFUD, &cfud);
cfud &= 0xf0;
regmap_write(sta350->regmap, STA350_CFUD, cfud);
regmap_write(sta350->regmap, STA350_CFADDR2, index);
if (numcoef == 1) {
regmap_write(sta350->regmap, STA350_CFUD, cfud | 0x04);
} else if (numcoef == 5) {
regmap_write(sta350->regmap, STA350_CFUD, cfud | 0x08);
} else {
ret = -EINVAL;
goto exit_unlock;
}
for (i = 0; i < 3 * numcoef; i++) {
regmap_read(sta350->regmap, STA350_B1CF1 + i, &val);
ucontrol->value.bytes.data[i] = val;
}
exit_unlock:
mutex_unlock(&sta350->coeff_lock);
return ret;
}
static int sta350_coefficient_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_soc_kcontrol_codec(kcontrol);
struct sta350_priv *sta350 = snd_soc_codec_get_drvdata(codec);
int numcoef = kcontrol->private_value >> 16;
int index = kcontrol->private_value & 0xffff;
unsigned int cfud;
int i;
regmap_read(sta350->regmap, STA350_CFUD, &cfud);
cfud &= 0xf0;
regmap_write(sta350->regmap, STA350_CFUD, cfud);
regmap_write(sta350->regmap, STA350_CFADDR2, index);
for (i = 0; i < numcoef && (index + i < STA350_COEF_COUNT); i++)
sta350->coef_shadow[index + i] =
(ucontrol->value.bytes.data[3 * i] << 16)
| (ucontrol->value.bytes.data[3 * i + 1] << 8)
| (ucontrol->value.bytes.data[3 * i + 2]);
for (i = 0; i < 3 * numcoef; i++)
regmap_write(sta350->regmap, STA350_B1CF1 + i,
ucontrol->value.bytes.data[i]);
if (numcoef == 1)
regmap_write(sta350->regmap, STA350_CFUD, cfud | 0x01);
else if (numcoef == 5)
regmap_write(sta350->regmap, STA350_CFUD, cfud | 0x02);
else
return -EINVAL;
return 0;
}
static int sta350_sync_coef_shadow(struct snd_soc_codec *codec)
{
struct sta350_priv *sta350 = snd_soc_codec_get_drvdata(codec);
unsigned int cfud;
int i;
regmap_read(sta350->regmap, STA350_CFUD, &cfud);
cfud &= 0xf0;
for (i = 0; i < STA350_COEF_COUNT; i++) {
regmap_write(sta350->regmap, STA350_CFADDR2, i);
regmap_write(sta350->regmap, STA350_B1CF1,
(sta350->coef_shadow[i] >> 16) & 0xff);
regmap_write(sta350->regmap, STA350_B1CF2,
(sta350->coef_shadow[i] >> 8) & 0xff);
regmap_write(sta350->regmap, STA350_B1CF3,
(sta350->coef_shadow[i]) & 0xff);
regmap_write(sta350->regmap, STA350_CFUD, cfud);
regmap_write(sta350->regmap, STA350_CFUD, cfud | 0x01);
}
return 0;
}
static int sta350_cache_sync(struct snd_soc_codec *codec)
{
struct sta350_priv *sta350 = snd_soc_codec_get_drvdata(codec);
unsigned int mute;
int rc;
regmap_read(sta350->regmap, STA350_CFUD, &mute);
regmap_write(sta350->regmap, STA350_MMUTE, mute | STA350_MMUTE_MMUTE);
sta350_sync_coef_shadow(codec);
rc = regcache_sync(sta350->regmap);
regmap_write(sta350->regmap, STA350_MMUTE, mute);
return rc;
}
static int sta350_set_dai_sysclk(struct snd_soc_dai *codec_dai,
int clk_id, unsigned int freq, int dir)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct sta350_priv *sta350 = snd_soc_codec_get_drvdata(codec);
dev_dbg(codec->dev, "mclk=%u\n", freq);
sta350->mclk = freq;
return 0;
}
static int sta350_set_dai_fmt(struct snd_soc_dai *codec_dai,
unsigned int fmt)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct sta350_priv *sta350 = snd_soc_codec_get_drvdata(codec);
unsigned int confb = 0;
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
sta350->format = fmt & SND_SOC_DAIFMT_FORMAT_MASK;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
confb |= STA350_CONFB_C2IM;
break;
case SND_SOC_DAIFMT_NB_IF:
confb |= STA350_CONFB_C1IM;
break;
default:
return -EINVAL;
}
return regmap_update_bits(sta350->regmap, STA350_CONFB,
STA350_CONFB_C1IM | STA350_CONFB_C2IM, confb);
}
static int sta350_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct sta350_priv *sta350 = snd_soc_codec_get_drvdata(codec);
int i, mcs = -EINVAL, ir = -EINVAL;
unsigned int confa, confb;
unsigned int rate, ratio;
int ret;
if (!sta350->mclk) {
dev_err(codec->dev,
"sta350->mclk is unset. Unable to determine ratio\n");
return -EIO;
}
rate = params_rate(params);
ratio = sta350->mclk / rate;
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
confa = (ir << STA350_CONFA_IR_SHIFT) |
(mcs << STA350_CONFA_MCS_SHIFT);
confb = 0;
switch (params_width(params)) {
case 24:
dev_dbg(codec->dev, "24bit\n");
case 32:
dev_dbg(codec->dev, "24bit or 32bit\n");
switch (sta350->format) {
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
switch (sta350->format) {
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
switch (sta350->format) {
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
switch (sta350->format) {
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
ret = regmap_update_bits(sta350->regmap, STA350_CONFA,
STA350_CONFA_MCS_MASK | STA350_CONFA_IR_MASK,
confa);
if (ret < 0)
return ret;
ret = regmap_update_bits(sta350->regmap, STA350_CONFB,
STA350_CONFB_SAI_MASK | STA350_CONFB_SAIFB,
confb);
if (ret < 0)
return ret;
return 0;
}
static int sta350_startup_sequence(struct sta350_priv *sta350)
{
if (sta350->gpiod_power_down)
gpiod_set_value(sta350->gpiod_power_down, 1);
if (sta350->gpiod_nreset) {
gpiod_set_value(sta350->gpiod_nreset, 0);
mdelay(1);
gpiod_set_value(sta350->gpiod_nreset, 1);
mdelay(1);
}
return 0;
}
static int sta350_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
struct sta350_priv *sta350 = snd_soc_codec_get_drvdata(codec);
int ret;
dev_dbg(codec->dev, "level = %d\n", level);
switch (level) {
case SND_SOC_BIAS_ON:
break;
case SND_SOC_BIAS_PREPARE:
regmap_update_bits(sta350->regmap, STA350_CONFF,
STA350_CONFF_PWDN | STA350_CONFF_EAPD,
STA350_CONFF_PWDN | STA350_CONFF_EAPD);
break;
case SND_SOC_BIAS_STANDBY:
if (snd_soc_codec_get_bias_level(codec) == SND_SOC_BIAS_OFF) {
ret = regulator_bulk_enable(
ARRAY_SIZE(sta350->supplies),
sta350->supplies);
if (ret < 0) {
dev_err(codec->dev,
"Failed to enable supplies: %d\n",
ret);
return ret;
}
sta350_startup_sequence(sta350);
sta350_cache_sync(codec);
}
regmap_update_bits(sta350->regmap, STA350_CONFF,
STA350_CONFF_PWDN | STA350_CONFF_EAPD,
0);
break;
case SND_SOC_BIAS_OFF:
regmap_update_bits(sta350->regmap, STA350_CONFF,
STA350_CONFF_PWDN | STA350_CONFF_EAPD, 0);
if (sta350->gpiod_power_down)
gpiod_set_value(sta350->gpiod_power_down, 0);
if (sta350->gpiod_nreset)
gpiod_set_value(sta350->gpiod_nreset, 0);
regulator_bulk_disable(ARRAY_SIZE(sta350->supplies),
sta350->supplies);
break;
}
return 0;
}
static int sta350_probe(struct snd_soc_codec *codec)
{
struct sta350_priv *sta350 = snd_soc_codec_get_drvdata(codec);
struct sta350_platform_data *pdata = sta350->pdata;
int i, ret = 0, thermal = 0;
ret = regulator_bulk_enable(ARRAY_SIZE(sta350->supplies),
sta350->supplies);
if (ret < 0) {
dev_err(codec->dev, "Failed to enable supplies: %d\n", ret);
return ret;
}
ret = sta350_startup_sequence(sta350);
if (ret < 0) {
dev_err(codec->dev, "Failed to startup device\n");
return ret;
}
if (!pdata->thermal_warning_recovery)
thermal |= STA350_CONFA_TWAB;
if (!pdata->thermal_warning_adjustment)
thermal |= STA350_CONFA_TWRB;
if (!pdata->fault_detect_recovery)
thermal |= STA350_CONFA_FDRB;
regmap_update_bits(sta350->regmap, STA350_CONFA,
STA350_CONFA_TWAB | STA350_CONFA_TWRB |
STA350_CONFA_FDRB,
thermal);
regmap_update_bits(sta350->regmap, STA350_CONFC,
STA350_CONFC_OM_MASK,
pdata->ffx_power_output_mode
<< STA350_CONFC_OM_SHIFT);
regmap_update_bits(sta350->regmap, STA350_CONFC,
STA350_CONFC_CSZ_MASK,
pdata->drop_compensation_ns
<< STA350_CONFC_CSZ_SHIFT);
regmap_update_bits(sta350->regmap,
STA350_CONFC,
STA350_CONFC_OCRB,
pdata->oc_warning_adjustment ?
STA350_CONFC_OCRB : 0);
regmap_update_bits(sta350->regmap, STA350_CONFE,
STA350_CONFE_MPCV,
pdata->max_power_use_mpcc ?
STA350_CONFE_MPCV : 0);
regmap_update_bits(sta350->regmap, STA350_CONFE,
STA350_CONFE_MPC,
pdata->max_power_correction ?
STA350_CONFE_MPC : 0);
regmap_update_bits(sta350->regmap, STA350_CONFE,
STA350_CONFE_AME,
pdata->am_reduction_mode ?
STA350_CONFE_AME : 0);
regmap_update_bits(sta350->regmap, STA350_CONFE,
STA350_CONFE_PWMS,
pdata->odd_pwm_speed_mode ?
STA350_CONFE_PWMS : 0);
regmap_update_bits(sta350->regmap, STA350_CONFE,
STA350_CONFE_DCCV,
pdata->distortion_compensation ?
STA350_CONFE_DCCV : 0);
regmap_update_bits(sta350->regmap, STA350_CONFF,
STA350_CONFF_IDE,
pdata->invalid_input_detect_mute ?
STA350_CONFF_IDE : 0);
regmap_update_bits(sta350->regmap, STA350_CONFF,
STA350_CONFF_OCFG_MASK,
pdata->output_conf
<< STA350_CONFF_OCFG_SHIFT);
regmap_update_bits(sta350->regmap, STA350_C1CFG,
STA350_CxCFG_OM_MASK,
pdata->ch1_output_mapping
<< STA350_CxCFG_OM_SHIFT);
regmap_update_bits(sta350->regmap, STA350_C2CFG,
STA350_CxCFG_OM_MASK,
pdata->ch2_output_mapping
<< STA350_CxCFG_OM_SHIFT);
regmap_update_bits(sta350->regmap, STA350_C3CFG,
STA350_CxCFG_OM_MASK,
pdata->ch3_output_mapping
<< STA350_CxCFG_OM_SHIFT);
regmap_update_bits(sta350->regmap, STA350_MISC1,
STA350_MISC1_CPWMEN,
pdata->activate_mute_output ?
STA350_MISC1_CPWMEN : 0);
regmap_update_bits(sta350->regmap, STA350_MISC1,
STA350_MISC1_BRIDGOFF,
pdata->bridge_immediate_off ?
STA350_MISC1_BRIDGOFF : 0);
regmap_update_bits(sta350->regmap, STA350_MISC1,
STA350_MISC1_NSHHPEN,
pdata->noise_shape_dc_cut ?
STA350_MISC1_NSHHPEN : 0);
regmap_update_bits(sta350->regmap, STA350_MISC1,
STA350_MISC1_RPDNEN,
pdata->powerdown_master_vol ?
STA350_MISC1_RPDNEN: 0);
regmap_update_bits(sta350->regmap, STA350_MISC2,
STA350_MISC2_PNDLSL_MASK,
pdata->powerdown_delay_divider
<< STA350_MISC2_PNDLSL_SHIFT);
for (i = 4; i <= 49; i += 5)
sta350->coef_shadow[i] = 0x400000;
for (i = 50; i <= 54; i++)
sta350->coef_shadow[i] = 0x7fffff;
sta350->coef_shadow[55] = 0x5a9df7;
sta350->coef_shadow[56] = 0x7fffff;
sta350->coef_shadow[59] = 0x7fffff;
sta350->coef_shadow[60] = 0x400000;
sta350->coef_shadow[61] = 0x400000;
snd_soc_codec_force_bias_level(codec, SND_SOC_BIAS_STANDBY);
regulator_bulk_disable(ARRAY_SIZE(sta350->supplies), sta350->supplies);
return 0;
}
static int sta350_remove(struct snd_soc_codec *codec)
{
struct sta350_priv *sta350 = snd_soc_codec_get_drvdata(codec);
regulator_bulk_disable(ARRAY_SIZE(sta350->supplies), sta350->supplies);
return 0;
}
static int sta350_probe_dt(struct device *dev, struct sta350_priv *sta350)
{
struct device_node *np = dev->of_node;
struct sta350_platform_data *pdata;
const char *ffx_power_mode;
u16 tmp;
u8 tmp8;
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
if (of_get_property(np, "st,fault-detect-recovery", NULL))
pdata->fault_detect_recovery = 1;
pdata->ffx_power_output_mode = STA350_FFX_PM_VARIABLE_DROP_COMP;
if (!of_property_read_string(np, "st,ffx-power-output-mode",
&ffx_power_mode)) {
int i, mode = -EINVAL;
for (i = 0; i < ARRAY_SIZE(sta350_ffx_modes); i++)
if (!strcasecmp(ffx_power_mode, sta350_ffx_modes[i]))
mode = i;
if (mode < 0)
dev_warn(dev, "Unsupported ffx output mode: %s\n",
ffx_power_mode);
else
pdata->ffx_power_output_mode = mode;
}
tmp = 140;
of_property_read_u16(np, "st,drop-compensation-ns", &tmp);
pdata->drop_compensation_ns = clamp_t(u16, tmp, 0, 300) / 20;
if (of_get_property(np, "st,overcurrent-warning-adjustment", NULL))
pdata->oc_warning_adjustment = 1;
if (of_get_property(np, "st,max-power-use-mpcc", NULL))
pdata->max_power_use_mpcc = 1;
if (of_get_property(np, "st,max-power-correction", NULL))
pdata->max_power_correction = 1;
if (of_get_property(np, "st,am-reduction-mode", NULL))
pdata->am_reduction_mode = 1;
if (of_get_property(np, "st,odd-pwm-speed-mode", NULL))
pdata->odd_pwm_speed_mode = 1;
if (of_get_property(np, "st,distortion-compensation", NULL))
pdata->distortion_compensation = 1;
if (of_get_property(np, "st,invalid-input-detect-mute", NULL))
pdata->invalid_input_detect_mute = 1;
if (of_get_property(np, "st,activate-mute-output", NULL))
pdata->activate_mute_output = 1;
if (of_get_property(np, "st,bridge-immediate-off", NULL))
pdata->bridge_immediate_off = 1;
if (of_get_property(np, "st,noise-shape-dc-cut", NULL))
pdata->noise_shape_dc_cut = 1;
if (of_get_property(np, "st,powerdown-master-volume", NULL))
pdata->powerdown_master_vol = 1;
if (!of_property_read_u8(np, "st,powerdown-delay-divider", &tmp8)) {
if (is_power_of_2(tmp8) && tmp8 >= 1 && tmp8 <= 128)
pdata->powerdown_delay_divider = ilog2(tmp8);
else
dev_warn(dev, "Unsupported powerdown delay divider %d\n",
tmp8);
}
sta350->pdata = pdata;
return 0;
}
static int sta350_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct device *dev = &i2c->dev;
struct sta350_priv *sta350;
int ret, i;
sta350 = devm_kzalloc(dev, sizeof(struct sta350_priv), GFP_KERNEL);
if (!sta350)
return -ENOMEM;
mutex_init(&sta350->coeff_lock);
sta350->pdata = dev_get_platdata(dev);
#ifdef CONFIG_OF
if (dev->of_node) {
ret = sta350_probe_dt(dev, sta350);
if (ret < 0)
return ret;
}
#endif
sta350->gpiod_nreset = devm_gpiod_get_optional(dev, "reset",
GPIOD_OUT_LOW);
if (IS_ERR(sta350->gpiod_nreset))
return PTR_ERR(sta350->gpiod_nreset);
sta350->gpiod_power_down = devm_gpiod_get_optional(dev, "power-down",
GPIOD_OUT_LOW);
if (IS_ERR(sta350->gpiod_power_down))
return PTR_ERR(sta350->gpiod_power_down);
for (i = 0; i < ARRAY_SIZE(sta350->supplies); i++)
sta350->supplies[i].supply = sta350_supply_names[i];
ret = devm_regulator_bulk_get(dev, ARRAY_SIZE(sta350->supplies),
sta350->supplies);
if (ret < 0) {
dev_err(dev, "Failed to request supplies: %d\n", ret);
return ret;
}
sta350->regmap = devm_regmap_init_i2c(i2c, &sta350_regmap);
if (IS_ERR(sta350->regmap)) {
ret = PTR_ERR(sta350->regmap);
dev_err(dev, "Failed to init regmap: %d\n", ret);
return ret;
}
i2c_set_clientdata(i2c, sta350);
ret = snd_soc_register_codec(dev, &sta350_codec, &sta350_dai, 1);
if (ret < 0)
dev_err(dev, "Failed to register codec (%d)\n", ret);
return ret;
}
static int sta350_i2c_remove(struct i2c_client *client)
{
snd_soc_unregister_codec(&client->dev);
return 0;
}
