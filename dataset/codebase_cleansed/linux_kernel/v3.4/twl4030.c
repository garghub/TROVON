static inline unsigned int twl4030_read_reg_cache(struct snd_soc_codec *codec,
unsigned int reg)
{
u8 *cache = codec->reg_cache;
if (reg >= TWL4030_CACHEREGNUM)
return -EIO;
return cache[reg];
}
static inline void twl4030_write_reg_cache(struct snd_soc_codec *codec,
u8 reg, u8 value)
{
u8 *cache = codec->reg_cache;
if (reg >= TWL4030_CACHEREGNUM)
return;
cache[reg] = value;
}
static int twl4030_write(struct snd_soc_codec *codec,
unsigned int reg, unsigned int value)
{
struct twl4030_priv *twl4030 = snd_soc_codec_get_drvdata(codec);
int write_to_reg = 0;
twl4030_write_reg_cache(codec, reg, value);
if (likely(reg < TWL4030_REG_SW_SHADOW)) {
switch (reg) {
case TWL4030_REG_EAR_CTL:
if (twl4030->earpiece_enabled)
write_to_reg = 1;
break;
case TWL4030_REG_PREDL_CTL:
if (twl4030->predrivel_enabled)
write_to_reg = 1;
break;
case TWL4030_REG_PREDR_CTL:
if (twl4030->predriver_enabled)
write_to_reg = 1;
break;
case TWL4030_REG_PRECKL_CTL:
if (twl4030->carkitl_enabled)
write_to_reg = 1;
break;
case TWL4030_REG_PRECKR_CTL:
if (twl4030->carkitr_enabled)
write_to_reg = 1;
break;
case TWL4030_REG_HS_GAIN_SET:
if (twl4030->hsl_enabled || twl4030->hsr_enabled)
write_to_reg = 1;
break;
default:
write_to_reg = 1;
break;
}
if (write_to_reg)
return twl_i2c_write_u8(TWL4030_MODULE_AUDIO_VOICE,
value, reg);
}
return 0;
}
static inline void twl4030_wait_ms(int time)
{
if (time < 60) {
time *= 1000;
usleep_range(time, time + 500);
} else {
msleep(time);
}
}
static void twl4030_codec_enable(struct snd_soc_codec *codec, int enable)
{
struct twl4030_priv *twl4030 = snd_soc_codec_get_drvdata(codec);
int mode;
if (enable == twl4030->codec_powered)
return;
if (enable)
mode = twl4030_audio_enable_resource(TWL4030_AUDIO_RES_POWER);
else
mode = twl4030_audio_disable_resource(TWL4030_AUDIO_RES_POWER);
if (mode >= 0) {
twl4030_write_reg_cache(codec, TWL4030_REG_CODEC_MODE, mode);
twl4030->codec_powered = enable;
}
udelay(10);
}
static inline void twl4030_check_defaults(struct snd_soc_codec *codec)
{
int i, difference = 0;
u8 val;
dev_dbg(codec->dev, "Checking TWL audio default configuration\n");
for (i = 1; i <= TWL4030_REG_MISC_SET_2; i++) {
twl_i2c_read_u8(TWL4030_MODULE_AUDIO_VOICE, &val, i);
if (val != twl4030_reg[i]) {
difference++;
dev_dbg(codec->dev,
"Reg 0x%02x: chip: 0x%02x driver: 0x%02x\n",
i, val, twl4030_reg[i]);
}
}
dev_dbg(codec->dev, "Found %d non-matching registers. %s\n",
difference, difference ? "Not OK" : "OK");
}
static inline void twl4030_reset_registers(struct snd_soc_codec *codec)
{
int i;
for (i = TWL4030_REG_OPTION; i <= TWL4030_REG_MISC_SET_2; i++)
if (i != TWL4030_REG_APLL_CTL)
twl4030_write(codec, i, twl4030_reg[i]);
}
static void twl4030_init_chip(struct snd_soc_codec *codec)
{
struct twl4030_codec_data *pdata = dev_get_platdata(codec->dev);
struct twl4030_priv *twl4030 = snd_soc_codec_get_drvdata(codec);
u8 reg, byte;
int i = 0;
if (pdata && pdata->check_defaults)
twl4030_check_defaults(codec);
if (!pdata || (pdata && pdata->reset_registers))
twl4030_reset_registers(codec);
twl_i2c_read_u8(TWL4030_MODULE_AUDIO_VOICE, &byte,
TWL4030_REG_APLL_CTL);
twl4030_write_reg_cache(codec, TWL4030_REG_APLL_CTL, byte);
reg = twl4030_read_reg_cache(codec, TWL4030_REG_MISC_SET_1);
twl4030_write(codec, TWL4030_REG_MISC_SET_1,
reg | TWL4030_SMOOTH_ANAVOL_EN);
twl4030_write(codec, TWL4030_REG_OPTION,
TWL4030_ATXL1_EN | TWL4030_ATXR1_EN |
TWL4030_ARXL2_EN | TWL4030_ARXR2_EN);
twl4030_write(codec, TWL4030_REG_ARXR2_APGA_CTL, 0x32);
if (!pdata)
return;
twl4030->digimic_delay = pdata->digimic_delay;
reg = twl4030_read_reg_cache(codec, TWL4030_REG_HS_POPN_SET);
reg &= ~TWL4030_RAMP_DELAY;
reg |= (pdata->ramp_delay_value << 2);
twl4030_write_reg_cache(codec, TWL4030_REG_HS_POPN_SET, reg);
twl4030_codec_enable(codec, 1);
reg = twl4030_read_reg_cache(codec, TWL4030_REG_ANAMICL);
reg &= ~TWL4030_OFFSET_CNCL_SEL;
reg |= pdata->offset_cncl_path;
twl4030_write(codec, TWL4030_REG_ANAMICL,
reg | TWL4030_CNCL_OFFSET_START);
msleep(20);
do {
usleep_range(1000, 2000);
twl_i2c_read_u8(TWL4030_MODULE_AUDIO_VOICE, &byte,
TWL4030_REG_ANAMICL);
} while ((i++ < 100) &&
((byte & TWL4030_CNCL_OFFSET_START) ==
TWL4030_CNCL_OFFSET_START));
twl4030_write_reg_cache(codec, TWL4030_REG_ANAMICL, byte);
twl4030_codec_enable(codec, 0);
}
static void twl4030_apll_enable(struct snd_soc_codec *codec, int enable)
{
struct twl4030_priv *twl4030 = snd_soc_codec_get_drvdata(codec);
int status = -1;
if (enable) {
twl4030->apll_enabled++;
if (twl4030->apll_enabled == 1)
status = twl4030_audio_enable_resource(
TWL4030_AUDIO_RES_APLL);
} else {
twl4030->apll_enabled--;
if (!twl4030->apll_enabled)
status = twl4030_audio_disable_resource(
TWL4030_AUDIO_RES_APLL);
}
if (status >= 0)
twl4030_write_reg_cache(codec, TWL4030_REG_APLL_CTL, status);
}
static void handsfree_ramp(struct snd_soc_codec *codec, int reg, int ramp)
{
unsigned char hs_ctl;
hs_ctl = twl4030_read_reg_cache(codec, reg);
if (ramp) {
hs_ctl |= TWL4030_HF_CTL_REF_EN;
twl4030_write(codec, reg, hs_ctl);
udelay(10);
hs_ctl |= TWL4030_HF_CTL_RAMP_EN;
twl4030_write(codec, reg, hs_ctl);
udelay(40);
hs_ctl |= TWL4030_HF_CTL_LOOP_EN;
hs_ctl |= TWL4030_HF_CTL_HB_EN;
twl4030_write(codec, reg, hs_ctl);
} else {
hs_ctl &= ~TWL4030_HF_CTL_LOOP_EN;
hs_ctl &= ~TWL4030_HF_CTL_HB_EN;
twl4030_write(codec, reg, hs_ctl);
hs_ctl &= ~TWL4030_HF_CTL_RAMP_EN;
twl4030_write(codec, reg, hs_ctl);
udelay(40);
hs_ctl &= ~TWL4030_HF_CTL_REF_EN;
twl4030_write(codec, reg, hs_ctl);
}
}
static int handsfreelpga_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
switch (event) {
case SND_SOC_DAPM_POST_PMU:
handsfree_ramp(w->codec, TWL4030_REG_HFL_CTL, 1);
break;
case SND_SOC_DAPM_POST_PMD:
handsfree_ramp(w->codec, TWL4030_REG_HFL_CTL, 0);
break;
}
return 0;
}
static int handsfreerpga_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
switch (event) {
case SND_SOC_DAPM_POST_PMU:
handsfree_ramp(w->codec, TWL4030_REG_HFR_CTL, 1);
break;
case SND_SOC_DAPM_POST_PMD:
handsfree_ramp(w->codec, TWL4030_REG_HFR_CTL, 0);
break;
}
return 0;
}
static int vibramux_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
twl4030_write(w->codec, TWL4030_REG_VIBRA_SET, 0xff);
return 0;
}
static int apll_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
switch (event) {
case SND_SOC_DAPM_PRE_PMU:
twl4030_apll_enable(w->codec, 1);
break;
case SND_SOC_DAPM_POST_PMD:
twl4030_apll_enable(w->codec, 0);
break;
}
return 0;
}
static int aif_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
u8 audio_if;
audio_if = twl4030_read_reg_cache(w->codec, TWL4030_REG_AUDIO_IF);
switch (event) {
case SND_SOC_DAPM_PRE_PMU:
twl4030_apll_enable(w->codec, 1);
twl4030_write(w->codec, TWL4030_REG_AUDIO_IF,
audio_if | TWL4030_AIF_EN);
break;
case SND_SOC_DAPM_POST_PMD:
twl4030_write(w->codec, TWL4030_REG_AUDIO_IF,
audio_if & ~TWL4030_AIF_EN);
twl4030_apll_enable(w->codec, 0);
break;
}
return 0;
}
static void headset_ramp(struct snd_soc_codec *codec, int ramp)
{
struct twl4030_codec_data *pdata = codec->dev->platform_data;
unsigned char hs_gain, hs_pop;
struct twl4030_priv *twl4030 = snd_soc_codec_get_drvdata(codec);
unsigned int ramp_base[] = {524288, 1048576, 2097152, 4194304,
8388608, 16777216, 33554432, 67108864};
unsigned int delay;
hs_gain = twl4030_read_reg_cache(codec, TWL4030_REG_HS_GAIN_SET);
hs_pop = twl4030_read_reg_cache(codec, TWL4030_REG_HS_POPN_SET);
delay = (ramp_base[(hs_pop & TWL4030_RAMP_DELAY) >> 2] /
twl4030->sysclk) + 1;
if (pdata && pdata->hs_extmute) {
if (pdata->set_hs_extmute) {
pdata->set_hs_extmute(1);
} else {
hs_pop |= TWL4030_EXTMUTE;
twl4030_write(codec, TWL4030_REG_HS_POPN_SET, hs_pop);
}
}
if (ramp) {
hs_pop |= TWL4030_VMID_EN;
twl4030_write(codec, TWL4030_REG_HS_POPN_SET, hs_pop);
twl_i2c_write_u8(TWL4030_MODULE_AUDIO_VOICE,
hs_gain,
TWL4030_REG_HS_GAIN_SET);
hs_pop |= TWL4030_RAMP_EN;
twl4030_write(codec, TWL4030_REG_HS_POPN_SET, hs_pop);
twl4030_wait_ms(delay);
} else {
hs_pop &= ~TWL4030_RAMP_EN;
twl4030_write(codec, TWL4030_REG_HS_POPN_SET, hs_pop);
twl4030_wait_ms(delay);
twl_i2c_write_u8(TWL4030_MODULE_AUDIO_VOICE,
hs_gain & (~0x0f),
TWL4030_REG_HS_GAIN_SET);
hs_pop &= ~TWL4030_VMID_EN;
twl4030_write(codec, TWL4030_REG_HS_POPN_SET, hs_pop);
}
if (pdata && pdata->hs_extmute) {
if (pdata->set_hs_extmute) {
pdata->set_hs_extmute(0);
} else {
hs_pop &= ~TWL4030_EXTMUTE;
twl4030_write(codec, TWL4030_REG_HS_POPN_SET, hs_pop);
}
}
}
static int headsetlpga_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct twl4030_priv *twl4030 = snd_soc_codec_get_drvdata(w->codec);
switch (event) {
case SND_SOC_DAPM_POST_PMU:
if (!twl4030->hsr_enabled)
headset_ramp(w->codec, 1);
twl4030->hsl_enabled = 1;
break;
case SND_SOC_DAPM_POST_PMD:
if (!twl4030->hsr_enabled)
headset_ramp(w->codec, 0);
twl4030->hsl_enabled = 0;
break;
}
return 0;
}
static int headsetrpga_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct twl4030_priv *twl4030 = snd_soc_codec_get_drvdata(w->codec);
switch (event) {
case SND_SOC_DAPM_POST_PMU:
if (!twl4030->hsl_enabled)
headset_ramp(w->codec, 1);
twl4030->hsr_enabled = 1;
break;
case SND_SOC_DAPM_POST_PMD:
if (!twl4030->hsl_enabled)
headset_ramp(w->codec, 0);
twl4030->hsr_enabled = 0;
break;
}
return 0;
}
static int digimic_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct twl4030_priv *twl4030 = snd_soc_codec_get_drvdata(w->codec);
if (twl4030->digimic_delay)
twl4030_wait_ms(twl4030->digimic_delay);
return 0;
}
static int snd_soc_get_volsw_twl4030(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct soc_mixer_control *mc =
(struct soc_mixer_control *)kcontrol->private_value;
struct snd_soc_codec *codec = snd_kcontrol_chip(kcontrol);
unsigned int reg = mc->reg;
unsigned int shift = mc->shift;
unsigned int rshift = mc->rshift;
int max = mc->max;
int mask = (1 << fls(max)) - 1;
ucontrol->value.integer.value[0] =
(snd_soc_read(codec, reg) >> shift) & mask;
if (ucontrol->value.integer.value[0])
ucontrol->value.integer.value[0] =
max + 1 - ucontrol->value.integer.value[0];
if (shift != rshift) {
ucontrol->value.integer.value[1] =
(snd_soc_read(codec, reg) >> rshift) & mask;
if (ucontrol->value.integer.value[1])
ucontrol->value.integer.value[1] =
max + 1 - ucontrol->value.integer.value[1];
}
return 0;
}
static int snd_soc_put_volsw_twl4030(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct soc_mixer_control *mc =
(struct soc_mixer_control *)kcontrol->private_value;
struct snd_soc_codec *codec = snd_kcontrol_chip(kcontrol);
unsigned int reg = mc->reg;
unsigned int shift = mc->shift;
unsigned int rshift = mc->rshift;
int max = mc->max;
int mask = (1 << fls(max)) - 1;
unsigned short val, val2, val_mask;
val = (ucontrol->value.integer.value[0] & mask);
val_mask = mask << shift;
if (val)
val = max + 1 - val;
val = val << shift;
if (shift != rshift) {
val2 = (ucontrol->value.integer.value[1] & mask);
val_mask |= mask << rshift;
if (val2)
val2 = max + 1 - val2;
val |= val2 << rshift;
}
return snd_soc_update_bits(codec, reg, val_mask, val);
}
static int snd_soc_get_volsw_r2_twl4030(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct soc_mixer_control *mc =
(struct soc_mixer_control *)kcontrol->private_value;
struct snd_soc_codec *codec = snd_kcontrol_chip(kcontrol);
unsigned int reg = mc->reg;
unsigned int reg2 = mc->rreg;
unsigned int shift = mc->shift;
int max = mc->max;
int mask = (1<<fls(max))-1;
ucontrol->value.integer.value[0] =
(snd_soc_read(codec, reg) >> shift) & mask;
ucontrol->value.integer.value[1] =
(snd_soc_read(codec, reg2) >> shift) & mask;
if (ucontrol->value.integer.value[0])
ucontrol->value.integer.value[0] =
max + 1 - ucontrol->value.integer.value[0];
if (ucontrol->value.integer.value[1])
ucontrol->value.integer.value[1] =
max + 1 - ucontrol->value.integer.value[1];
return 0;
}
static int snd_soc_put_volsw_r2_twl4030(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct soc_mixer_control *mc =
(struct soc_mixer_control *)kcontrol->private_value;
struct snd_soc_codec *codec = snd_kcontrol_chip(kcontrol);
unsigned int reg = mc->reg;
unsigned int reg2 = mc->rreg;
unsigned int shift = mc->shift;
int max = mc->max;
int mask = (1 << fls(max)) - 1;
int err;
unsigned short val, val2, val_mask;
val_mask = mask << shift;
val = (ucontrol->value.integer.value[0] & mask);
val2 = (ucontrol->value.integer.value[1] & mask);
if (val)
val = max + 1 - val;
if (val2)
val2 = max + 1 - val2;
val = val << shift;
val2 = val2 << shift;
err = snd_soc_update_bits(codec, reg, val_mask, val);
if (err < 0)
return err;
err = snd_soc_update_bits(codec, reg2, val_mask, val2);
return err;
}
static int snd_soc_put_twl4030_opmode_enum_double(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_kcontrol_chip(kcontrol);
struct twl4030_priv *twl4030 = snd_soc_codec_get_drvdata(codec);
struct soc_enum *e = (struct soc_enum *)kcontrol->private_value;
unsigned short val;
unsigned short mask, bitmask;
if (twl4030->configured) {
dev_err(codec->dev,
"operation mode cannot be changed on-the-fly\n");
return -EBUSY;
}
for (bitmask = 1; bitmask < e->max; bitmask <<= 1)
;
if (ucontrol->value.enumerated.item[0] > e->max - 1)
return -EINVAL;
val = ucontrol->value.enumerated.item[0] << e->shift_l;
mask = (bitmask - 1) << e->shift_l;
if (e->shift_l != e->shift_r) {
if (ucontrol->value.enumerated.item[1] > e->max - 1)
return -EINVAL;
val |= ucontrol->value.enumerated.item[1] << e->shift_r;
mask |= (bitmask - 1) << e->shift_r;
}
return snd_soc_update_bits(codec, e->reg, mask, val);
}
static int twl4030_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
switch (level) {
case SND_SOC_BIAS_ON:
break;
case SND_SOC_BIAS_PREPARE:
break;
case SND_SOC_BIAS_STANDBY:
if (codec->dapm.bias_level == SND_SOC_BIAS_OFF)
twl4030_codec_enable(codec, 1);
break;
case SND_SOC_BIAS_OFF:
twl4030_codec_enable(codec, 0);
break;
}
codec->dapm.bias_level = level;
return 0;
}
static void twl4030_constraints(struct twl4030_priv *twl4030,
struct snd_pcm_substream *mst_substream)
{
struct snd_pcm_substream *slv_substream;
if (mst_substream == twl4030->master_substream)
slv_substream = twl4030->slave_substream;
else if (mst_substream == twl4030->slave_substream)
slv_substream = twl4030->master_substream;
else
return;
snd_pcm_hw_constraint_minmax(slv_substream->runtime,
SNDRV_PCM_HW_PARAM_RATE,
twl4030->rate,
twl4030->rate);
snd_pcm_hw_constraint_minmax(slv_substream->runtime,
SNDRV_PCM_HW_PARAM_SAMPLE_BITS,
twl4030->sample_bits,
twl4030->sample_bits);
snd_pcm_hw_constraint_minmax(slv_substream->runtime,
SNDRV_PCM_HW_PARAM_CHANNELS,
twl4030->channels,
twl4030->channels);
}
static void twl4030_tdm_enable(struct snd_soc_codec *codec, int direction,
int enable)
{
u8 reg, mask;
reg = twl4030_read_reg_cache(codec, TWL4030_REG_OPTION);
if (direction == SNDRV_PCM_STREAM_PLAYBACK)
mask = TWL4030_ARXL1_VRX_EN | TWL4030_ARXR1_EN;
else
mask = TWL4030_ATXL2_VTXL_EN | TWL4030_ATXR2_VTXR_EN;
if (enable)
reg |= mask;
else
reg &= ~mask;
twl4030_write(codec, TWL4030_REG_OPTION, reg);
}
static int twl4030_startup(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_codec *codec = rtd->codec;
struct twl4030_priv *twl4030 = snd_soc_codec_get_drvdata(codec);
if (twl4030->master_substream) {
twl4030->slave_substream = substream;
if (twl4030->configured)
twl4030_constraints(twl4030, twl4030->master_substream);
} else {
if (!(twl4030_read_reg_cache(codec, TWL4030_REG_CODEC_MODE) &
TWL4030_OPTION_1)) {
snd_pcm_hw_constraint_minmax(substream->runtime,
SNDRV_PCM_HW_PARAM_CHANNELS,
2, 2);
}
twl4030->master_substream = substream;
}
return 0;
}
static void twl4030_shutdown(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_codec *codec = rtd->codec;
struct twl4030_priv *twl4030 = snd_soc_codec_get_drvdata(codec);
if (twl4030->master_substream == substream)
twl4030->master_substream = twl4030->slave_substream;
twl4030->slave_substream = NULL;
if (!twl4030->master_substream)
twl4030->configured = 0;
else if (!twl4030->master_substream->runtime->channels)
twl4030->configured = 0;
if (substream->runtime->channels == 4)
twl4030_tdm_enable(codec, substream->stream, 0);
}
static int twl4030_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_codec *codec = rtd->codec;
struct twl4030_priv *twl4030 = snd_soc_codec_get_drvdata(codec);
u8 mode, old_mode, format, old_format;
if (params_channels(params) == 4) {
format = twl4030_read_reg_cache(codec, TWL4030_REG_AUDIO_IF);
mode = twl4030_read_reg_cache(codec, TWL4030_REG_CODEC_MODE);
if ((mode & TWL4030_OPTION_1) &&
((format & TWL4030_AIF_FORMAT) == TWL4030_AIF_FORMAT_TDM))
twl4030_tdm_enable(codec, substream->stream, 1);
else
return -EINVAL;
}
if (twl4030->configured)
return 0;
old_mode = twl4030_read_reg_cache(codec,
TWL4030_REG_CODEC_MODE) & ~TWL4030_CODECPDZ;
mode = old_mode & ~TWL4030_APLL_RATE;
switch (params_rate(params)) {
case 8000:
mode |= TWL4030_APLL_RATE_8000;
break;
case 11025:
mode |= TWL4030_APLL_RATE_11025;
break;
case 12000:
mode |= TWL4030_APLL_RATE_12000;
break;
case 16000:
mode |= TWL4030_APLL_RATE_16000;
break;
case 22050:
mode |= TWL4030_APLL_RATE_22050;
break;
case 24000:
mode |= TWL4030_APLL_RATE_24000;
break;
case 32000:
mode |= TWL4030_APLL_RATE_32000;
break;
case 44100:
mode |= TWL4030_APLL_RATE_44100;
break;
case 48000:
mode |= TWL4030_APLL_RATE_48000;
break;
case 96000:
mode |= TWL4030_APLL_RATE_96000;
break;
default:
dev_err(codec->dev, "%s: unknown rate %d\n", __func__,
params_rate(params));
return -EINVAL;
}
old_format = twl4030_read_reg_cache(codec, TWL4030_REG_AUDIO_IF);
format = old_format;
format &= ~TWL4030_DATA_WIDTH;
switch (params_format(params)) {
case SNDRV_PCM_FORMAT_S16_LE:
format |= TWL4030_DATA_WIDTH_16S_16W;
break;
case SNDRV_PCM_FORMAT_S32_LE:
format |= TWL4030_DATA_WIDTH_32S_24W;
break;
default:
dev_err(codec->dev, "%s: unknown format %d\n", __func__,
params_format(params));
return -EINVAL;
}
if (format != old_format || mode != old_mode) {
if (twl4030->codec_powered) {
twl4030_codec_enable(codec, 0);
twl4030_write(codec, TWL4030_REG_CODEC_MODE, mode);
twl4030_write(codec, TWL4030_REG_AUDIO_IF, format);
twl4030_codec_enable(codec, 1);
} else {
twl4030_write(codec, TWL4030_REG_CODEC_MODE, mode);
twl4030_write(codec, TWL4030_REG_AUDIO_IF, format);
}
}
twl4030->configured = 1;
twl4030->rate = params_rate(params);
twl4030->sample_bits = hw_param_interval(params,
SNDRV_PCM_HW_PARAM_SAMPLE_BITS)->min;
twl4030->channels = params_channels(params);
if (twl4030->slave_substream)
twl4030_constraints(twl4030, substream);
return 0;
}
static int twl4030_set_dai_sysclk(struct snd_soc_dai *codec_dai,
int clk_id, unsigned int freq, int dir)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct twl4030_priv *twl4030 = snd_soc_codec_get_drvdata(codec);
switch (freq) {
case 19200000:
case 26000000:
case 38400000:
break;
default:
dev_err(codec->dev, "Unsupported HFCLKIN: %u\n", freq);
return -EINVAL;
}
if ((freq / 1000) != twl4030->sysclk) {
dev_err(codec->dev,
"Mismatch in HFCLKIN: %u (configured: %u)\n",
freq, twl4030->sysclk * 1000);
return -EINVAL;
}
return 0;
}
static int twl4030_set_dai_fmt(struct snd_soc_dai *codec_dai,
unsigned int fmt)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct twl4030_priv *twl4030 = snd_soc_codec_get_drvdata(codec);
u8 old_format, format;
old_format = twl4030_read_reg_cache(codec, TWL4030_REG_AUDIO_IF);
format = old_format;
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBM_CFM:
format &= ~(TWL4030_AIF_SLAVE_EN);
format &= ~(TWL4030_CLK256FS_EN);
break;
case SND_SOC_DAIFMT_CBS_CFS:
format |= TWL4030_AIF_SLAVE_EN;
format |= TWL4030_CLK256FS_EN;
break;
default:
return -EINVAL;
}
format &= ~TWL4030_AIF_FORMAT;
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
format |= TWL4030_AIF_FORMAT_CODEC;
break;
case SND_SOC_DAIFMT_DSP_A:
format |= TWL4030_AIF_FORMAT_TDM;
break;
default:
return -EINVAL;
}
if (format != old_format) {
if (twl4030->codec_powered) {
twl4030_codec_enable(codec, 0);
twl4030_write(codec, TWL4030_REG_AUDIO_IF, format);
twl4030_codec_enable(codec, 1);
} else {
twl4030_write(codec, TWL4030_REG_AUDIO_IF, format);
}
}
return 0;
}
static int twl4030_set_tristate(struct snd_soc_dai *dai, int tristate)
{
struct snd_soc_codec *codec = dai->codec;
u8 reg = twl4030_read_reg_cache(codec, TWL4030_REG_AUDIO_IF);
if (tristate)
reg |= TWL4030_AIF_TRI_EN;
else
reg &= ~TWL4030_AIF_TRI_EN;
return twl4030_write(codec, TWL4030_REG_AUDIO_IF, reg);
}
static void twl4030_voice_enable(struct snd_soc_codec *codec, int direction,
int enable)
{
u8 reg, mask;
reg = twl4030_read_reg_cache(codec, TWL4030_REG_OPTION);
if (direction == SNDRV_PCM_STREAM_PLAYBACK)
mask = TWL4030_ARXL1_VRX_EN;
else
mask = TWL4030_ATXL2_VTXL_EN | TWL4030_ATXR2_VTXR_EN;
if (enable)
reg |= mask;
else
reg &= ~mask;
twl4030_write(codec, TWL4030_REG_OPTION, reg);
}
static int twl4030_voice_startup(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_codec *codec = rtd->codec;
struct twl4030_priv *twl4030 = snd_soc_codec_get_drvdata(codec);
u8 mode;
if (twl4030->sysclk != 26000) {
dev_err(codec->dev,
"%s: HFCLKIN is %u KHz, voice interface needs 26MHz\n",
__func__, twl4030->sysclk);
return -EINVAL;
}
mode = twl4030_read_reg_cache(codec, TWL4030_REG_CODEC_MODE)
& TWL4030_OPT_MODE;
if (mode != TWL4030_OPTION_2) {
dev_err(codec->dev, "%s: the codec mode is not option2\n",
__func__);
return -EINVAL;
}
return 0;
}
static void twl4030_voice_shutdown(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_codec *codec = rtd->codec;
twl4030_voice_enable(codec, substream->stream, 0);
}
static int twl4030_voice_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params, struct snd_soc_dai *dai)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_codec *codec = rtd->codec;
struct twl4030_priv *twl4030 = snd_soc_codec_get_drvdata(codec);
u8 old_mode, mode;
twl4030_voice_enable(codec, substream->stream, 1);
old_mode = twl4030_read_reg_cache(codec, TWL4030_REG_CODEC_MODE)
& ~(TWL4030_CODECPDZ);
mode = old_mode;
switch (params_rate(params)) {
case 8000:
mode &= ~(TWL4030_SEL_16K);
break;
case 16000:
mode |= TWL4030_SEL_16K;
break;
default:
dev_err(codec->dev, "%s: unknown rate %d\n", __func__,
params_rate(params));
return -EINVAL;
}
if (mode != old_mode) {
if (twl4030->codec_powered) {
twl4030_codec_enable(codec, 0);
twl4030_write(codec, TWL4030_REG_CODEC_MODE, mode);
twl4030_codec_enable(codec, 1);
} else {
twl4030_write(codec, TWL4030_REG_CODEC_MODE, mode);
}
}
return 0;
}
static int twl4030_voice_set_dai_sysclk(struct snd_soc_dai *codec_dai,
int clk_id, unsigned int freq, int dir)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct twl4030_priv *twl4030 = snd_soc_codec_get_drvdata(codec);
if (freq != 26000000) {
dev_err(codec->dev,
"%s: HFCLKIN is %u KHz, voice interface needs 26MHz\n",
__func__, freq / 1000);
return -EINVAL;
}
if ((freq / 1000) != twl4030->sysclk) {
dev_err(codec->dev,
"Mismatch in HFCLKIN: %u (configured: %u)\n",
freq, twl4030->sysclk * 1000);
return -EINVAL;
}
return 0;
}
static int twl4030_voice_set_dai_fmt(struct snd_soc_dai *codec_dai,
unsigned int fmt)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct twl4030_priv *twl4030 = snd_soc_codec_get_drvdata(codec);
u8 old_format, format;
old_format = twl4030_read_reg_cache(codec, TWL4030_REG_VOICE_IF);
format = old_format;
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBM_CFM:
format &= ~(TWL4030_VIF_SLAVE_EN);
break;
case SND_SOC_DAIFMT_CBS_CFS:
format |= TWL4030_VIF_SLAVE_EN;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_IB_NF:
format &= ~(TWL4030_VIF_FORMAT);
break;
case SND_SOC_DAIFMT_NB_IF:
format |= TWL4030_VIF_FORMAT;
break;
default:
return -EINVAL;
}
if (format != old_format) {
if (twl4030->codec_powered) {
twl4030_codec_enable(codec, 0);
twl4030_write(codec, TWL4030_REG_VOICE_IF, format);
twl4030_codec_enable(codec, 1);
} else {
twl4030_write(codec, TWL4030_REG_VOICE_IF, format);
}
}
return 0;
}
static int twl4030_voice_set_tristate(struct snd_soc_dai *dai, int tristate)
{
struct snd_soc_codec *codec = dai->codec;
u8 reg = twl4030_read_reg_cache(codec, TWL4030_REG_VOICE_IF);
if (tristate)
reg |= TWL4030_VIF_TRI_EN;
else
reg &= ~TWL4030_VIF_TRI_EN;
return twl4030_write(codec, TWL4030_REG_VOICE_IF, reg);
}
static int twl4030_soc_suspend(struct snd_soc_codec *codec)
{
twl4030_set_bias_level(codec, SND_SOC_BIAS_OFF);
return 0;
}
static int twl4030_soc_resume(struct snd_soc_codec *codec)
{
twl4030_set_bias_level(codec, SND_SOC_BIAS_STANDBY);
return 0;
}
static int twl4030_soc_probe(struct snd_soc_codec *codec)
{
struct twl4030_priv *twl4030;
twl4030 = kzalloc(sizeof(struct twl4030_priv), GFP_KERNEL);
if (twl4030 == NULL) {
dev_err(codec->dev, "Can not allocate memory\n");
return -ENOMEM;
}
snd_soc_codec_set_drvdata(codec, twl4030);
twl4030->sysclk = twl4030_audio_get_mclk() / 1000;
twl4030_init_chip(codec);
return 0;
}
static int twl4030_soc_remove(struct snd_soc_codec *codec)
{
struct twl4030_priv *twl4030 = snd_soc_codec_get_drvdata(codec);
twl4030_reset_registers(codec);
twl4030_set_bias_level(codec, SND_SOC_BIAS_OFF);
kfree(twl4030);
return 0;
}
static int __devinit twl4030_codec_probe(struct platform_device *pdev)
{
struct twl4030_codec_data *pdata = pdev->dev.platform_data;
if (!pdata) {
dev_err(&pdev->dev, "platform_data is missing\n");
return -EINVAL;
}
return snd_soc_register_codec(&pdev->dev, &soc_codec_dev_twl4030,
twl4030_dai, ARRAY_SIZE(twl4030_dai));
}
static int __devexit twl4030_codec_remove(struct platform_device *pdev)
{
snd_soc_unregister_codec(&pdev->dev);
return 0;
}
