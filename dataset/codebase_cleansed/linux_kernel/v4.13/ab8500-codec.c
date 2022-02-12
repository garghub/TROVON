static inline const char *amic_micbias_str(enum amic_micbias micbias)
{
switch (micbias) {
case AMIC_MICBIAS_VAMIC1:
return "VAMIC1";
case AMIC_MICBIAS_VAMIC2:
return "VAMIC2";
default:
return "Unknown";
}
}
static inline const char *amic_type_str(enum amic_type type)
{
switch (type) {
case AMIC_TYPE_DIFFERENTIAL:
return "DIFFERENTIAL";
case AMIC_TYPE_SINGLE_ENDED:
return "SINGLE ENDED";
default:
return "Unknown";
}
}
static int ab8500_codec_read_reg(void *context, unsigned int reg,
unsigned int *value)
{
struct device *dev = context;
int status;
u8 value8;
status = abx500_get_register_interruptible(dev, AB8500_AUDIO,
reg, &value8);
*value = (unsigned int)value8;
return status;
}
static int ab8500_codec_write_reg(void *context, unsigned int reg,
unsigned int value)
{
struct device *dev = context;
return abx500_set_register_interruptible(dev, AB8500_AUDIO,
reg, value);
}
static void anc_fir(struct snd_soc_codec *codec,
unsigned int bnk, unsigned int par, unsigned int val)
{
if (par == 0 && bnk == 0)
snd_soc_update_bits(codec, AB8500_ANCCONF1,
BIT(AB8500_ANCCONF1_ANCFIRUPDATE),
BIT(AB8500_ANCCONF1_ANCFIRUPDATE));
snd_soc_write(codec, AB8500_ANCCONF5, val >> 8 & 0xff);
snd_soc_write(codec, AB8500_ANCCONF6, val & 0xff);
if (par == AB8500_ANC_FIR_COEFFS - 1 && bnk == 1)
snd_soc_update_bits(codec, AB8500_ANCCONF1,
BIT(AB8500_ANCCONF1_ANCFIRUPDATE), 0);
}
static void anc_iir(struct snd_soc_codec *codec, unsigned int bnk,
unsigned int par, unsigned int val)
{
if (par == 0) {
if (bnk == 0) {
snd_soc_update_bits(codec, AB8500_ANCCONF1,
BIT(AB8500_ANCCONF1_ANCIIRINIT),
BIT(AB8500_ANCCONF1_ANCIIRINIT));
usleep_range(AB8500_ANC_SM_DELAY, AB8500_ANC_SM_DELAY);
snd_soc_update_bits(codec, AB8500_ANCCONF1,
BIT(AB8500_ANCCONF1_ANCIIRINIT), 0);
usleep_range(AB8500_ANC_SM_DELAY, AB8500_ANC_SM_DELAY);
} else {
snd_soc_update_bits(codec, AB8500_ANCCONF1,
BIT(AB8500_ANCCONF1_ANCIIRUPDATE),
BIT(AB8500_ANCCONF1_ANCIIRUPDATE));
}
} else if (par > 3) {
snd_soc_write(codec, AB8500_ANCCONF7, 0);
snd_soc_write(codec, AB8500_ANCCONF8, val >> 16 & 0xff);
}
snd_soc_write(codec, AB8500_ANCCONF7, val >> 8 & 0xff);
snd_soc_write(codec, AB8500_ANCCONF8, val & 0xff);
if (par == AB8500_ANC_IIR_COEFFS - 1 && bnk == 1)
snd_soc_update_bits(codec, AB8500_ANCCONF1,
BIT(AB8500_ANCCONF1_ANCIIRUPDATE), 0);
}
static void anc_configure(struct snd_soc_codec *codec,
bool apply_fir, bool apply_iir)
{
struct ab8500_codec_drvdata *drvdata = dev_get_drvdata(codec->dev);
unsigned int bnk, par, val;
dev_dbg(codec->dev, "%s: Enter.\n", __func__);
if (apply_fir)
snd_soc_update_bits(codec, AB8500_ANCCONF1,
BIT(AB8500_ANCCONF1_ENANC), 0);
snd_soc_update_bits(codec, AB8500_ANCCONF1,
BIT(AB8500_ANCCONF1_ENANC), BIT(AB8500_ANCCONF1_ENANC));
if (apply_fir)
for (bnk = 0; bnk < AB8500_NR_OF_ANC_COEFF_BANKS; bnk++)
for (par = 0; par < AB8500_ANC_FIR_COEFFS; par++) {
val = snd_soc_read(codec,
drvdata->anc_fir_values[par]);
anc_fir(codec, bnk, par, val);
}
if (apply_iir)
for (bnk = 0; bnk < AB8500_NR_OF_ANC_COEFF_BANKS; bnk++)
for (par = 0; par < AB8500_ANC_IIR_COEFFS; par++) {
val = snd_soc_read(codec,
drvdata->anc_iir_values[par]);
anc_iir(codec, bnk, par, val);
}
dev_dbg(codec->dev, "%s: Exit.\n", __func__);
}
static int sid_status_control_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_soc_kcontrol_codec(kcontrol);
struct ab8500_codec_drvdata *drvdata = dev_get_drvdata(codec->dev);
mutex_lock(&drvdata->ctrl_lock);
ucontrol->value.enumerated.item[0] = drvdata->sid_status;
mutex_unlock(&drvdata->ctrl_lock);
return 0;
}
static int sid_status_control_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_soc_kcontrol_codec(kcontrol);
struct ab8500_codec_drvdata *drvdata = dev_get_drvdata(codec->dev);
unsigned int param, sidconf, val;
int status = 1;
dev_dbg(codec->dev, "%s: Enter\n", __func__);
if (ucontrol->value.enumerated.item[0] != SID_APPLY_FIR) {
dev_err(codec->dev,
"%s: ERROR: This control supports '%s' only!\n",
__func__, enum_sid_state[SID_APPLY_FIR]);
return -EIO;
}
mutex_lock(&drvdata->ctrl_lock);
sidconf = snd_soc_read(codec, AB8500_SIDFIRCONF);
if (((sidconf & BIT(AB8500_SIDFIRCONF_FIRSIDBUSY)) != 0)) {
if ((sidconf & BIT(AB8500_SIDFIRCONF_ENFIRSIDS)) == 0) {
dev_err(codec->dev, "%s: Sidetone busy while off!\n",
__func__);
status = -EPERM;
} else {
status = -EBUSY;
}
goto out;
}
snd_soc_write(codec, AB8500_SIDFIRADR, 0);
for (param = 0; param < AB8500_SID_FIR_COEFFS; param++) {
val = snd_soc_read(codec, drvdata->sid_fir_values[param]);
snd_soc_write(codec, AB8500_SIDFIRCOEF1, val >> 8 & 0xff);
snd_soc_write(codec, AB8500_SIDFIRCOEF2, val & 0xff);
}
snd_soc_update_bits(codec, AB8500_SIDFIRADR,
BIT(AB8500_SIDFIRADR_FIRSIDSET),
BIT(AB8500_SIDFIRADR_FIRSIDSET));
snd_soc_update_bits(codec, AB8500_SIDFIRADR,
BIT(AB8500_SIDFIRADR_FIRSIDSET), 0);
drvdata->sid_status = SID_FIR_CONFIGURED;
out:
mutex_unlock(&drvdata->ctrl_lock);
dev_dbg(codec->dev, "%s: Exit\n", __func__);
return status;
}
static int anc_status_control_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_soc_kcontrol_codec(kcontrol);
struct ab8500_codec_drvdata *drvdata = dev_get_drvdata(codec->dev);
mutex_lock(&drvdata->ctrl_lock);
ucontrol->value.enumerated.item[0] = drvdata->anc_status;
mutex_unlock(&drvdata->ctrl_lock);
return 0;
}
static int anc_status_control_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_soc_kcontrol_codec(kcontrol);
struct snd_soc_dapm_context *dapm = snd_soc_codec_get_dapm(codec);
struct ab8500_codec_drvdata *drvdata = dev_get_drvdata(codec->dev);
struct device *dev = codec->dev;
bool apply_fir, apply_iir;
unsigned int req;
int status;
dev_dbg(dev, "%s: Enter.\n", __func__);
mutex_lock(&drvdata->ctrl_lock);
req = ucontrol->value.enumerated.item[0];
if (req >= ARRAY_SIZE(enum_anc_state)) {
status = -EINVAL;
goto cleanup;
}
if (req != ANC_APPLY_FIR_IIR && req != ANC_APPLY_FIR &&
req != ANC_APPLY_IIR) {
dev_err(dev, "%s: ERROR: Unsupported status to set '%s'!\n",
__func__, enum_anc_state[req]);
status = -EINVAL;
goto cleanup;
}
apply_fir = req == ANC_APPLY_FIR || req == ANC_APPLY_FIR_IIR;
apply_iir = req == ANC_APPLY_IIR || req == ANC_APPLY_FIR_IIR;
status = snd_soc_dapm_force_enable_pin(dapm, "ANC Configure Input");
if (status < 0) {
dev_err(dev,
"%s: ERROR: Failed to enable power (status = %d)!\n",
__func__, status);
goto cleanup;
}
snd_soc_dapm_sync(dapm);
anc_configure(codec, apply_fir, apply_iir);
if (apply_fir) {
if (drvdata->anc_status == ANC_IIR_CONFIGURED)
drvdata->anc_status = ANC_FIR_IIR_CONFIGURED;
else if (drvdata->anc_status != ANC_FIR_IIR_CONFIGURED)
drvdata->anc_status = ANC_FIR_CONFIGURED;
}
if (apply_iir) {
if (drvdata->anc_status == ANC_FIR_CONFIGURED)
drvdata->anc_status = ANC_FIR_IIR_CONFIGURED;
else if (drvdata->anc_status != ANC_FIR_IIR_CONFIGURED)
drvdata->anc_status = ANC_IIR_CONFIGURED;
}
status = snd_soc_dapm_disable_pin(dapm, "ANC Configure Input");
snd_soc_dapm_sync(dapm);
cleanup:
mutex_unlock(&drvdata->ctrl_lock);
if (status < 0)
dev_err(dev, "%s: Unable to configure ANC! (status = %d)\n",
__func__, status);
dev_dbg(dev, "%s: Exit.\n", __func__);
return (status < 0) ? status : 1;
}
static int filter_control_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
struct filter_control *fc =
(struct filter_control *)kcontrol->private_value;
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = fc->count;
uinfo->value.integer.min = fc->min;
uinfo->value.integer.max = fc->max;
return 0;
}
static int filter_control_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_soc_kcontrol_codec(kcontrol);
struct ab8500_codec_drvdata *drvdata = snd_soc_codec_get_drvdata(codec);
struct filter_control *fc =
(struct filter_control *)kcontrol->private_value;
unsigned int i;
mutex_lock(&drvdata->ctrl_lock);
for (i = 0; i < fc->count; i++)
ucontrol->value.integer.value[i] = fc->value[i];
mutex_unlock(&drvdata->ctrl_lock);
return 0;
}
static int filter_control_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_soc_kcontrol_codec(kcontrol);
struct ab8500_codec_drvdata *drvdata = snd_soc_codec_get_drvdata(codec);
struct filter_control *fc =
(struct filter_control *)kcontrol->private_value;
unsigned int i;
mutex_lock(&drvdata->ctrl_lock);
for (i = 0; i < fc->count; i++)
fc->value[i] = ucontrol->value.integer.value[i];
mutex_unlock(&drvdata->ctrl_lock);
return 0;
}
static int ab8500_audio_init_audioblock(struct snd_soc_codec *codec)
{
int status;
dev_dbg(codec->dev, "%s: Enter.\n", __func__);
status = ab8500_sysctrl_write(AB8500_STW4500CTRL3,
AB8500_STW4500CTRL3_CLK32KOUT2DIS |
AB8500_STW4500CTRL3_RESETAUDN,
AB8500_STW4500CTRL3_RESETAUDN);
if (status < 0)
return status;
return 0;
}
static int ab8500_audio_setup_mics(struct snd_soc_codec *codec,
struct amic_settings *amics)
{
struct snd_soc_dapm_context *dapm = snd_soc_codec_get_dapm(codec);
u8 value8;
unsigned int value;
int status;
const struct snd_soc_dapm_route *route;
dev_dbg(codec->dev, "%s: Enter.\n", __func__);
status = abx500_get_register_interruptible(codec->dev, AB8500_MISC,
AB8500_GPIO_DIR4_REG,
&value8);
if (status < 0)
return status;
value = value8 | GPIO27_DIR_OUTPUT | GPIO29_DIR_OUTPUT |
GPIO31_DIR_OUTPUT;
status = abx500_set_register_interruptible(codec->dev,
AB8500_MISC,
AB8500_GPIO_DIR4_REG,
value);
if (status < 0)
return status;
dev_dbg(codec->dev, "%s: Mic 1a regulator: %s\n", __func__,
amic_micbias_str(amics->mic1a_micbias));
route = &ab8500_dapm_routes_mic1a_vamicx[amics->mic1a_micbias];
status = snd_soc_dapm_add_routes(dapm, route, 1);
dev_dbg(codec->dev, "%s: Mic 1b regulator: %s\n", __func__,
amic_micbias_str(amics->mic1b_micbias));
route = &ab8500_dapm_routes_mic1b_vamicx[amics->mic1b_micbias];
status |= snd_soc_dapm_add_routes(dapm, route, 1);
dev_dbg(codec->dev, "%s: Mic 2 regulator: %s\n", __func__,
amic_micbias_str(amics->mic2_micbias));
route = &ab8500_dapm_routes_mic2_vamicx[amics->mic2_micbias];
status |= snd_soc_dapm_add_routes(dapm, route, 1);
if (status < 0) {
dev_err(codec->dev,
"%s: Failed to add AMic-regulator DAPM-routes (%d).\n",
__func__, status);
return status;
}
dev_dbg(codec->dev, "%s: Mic 1 mic-type: %s\n", __func__,
amic_type_str(amics->mic1_type));
snd_soc_update_bits(codec, AB8500_ANAGAIN1, AB8500_ANAGAINX_ENSEMICX,
amics->mic1_type == AMIC_TYPE_DIFFERENTIAL ?
0 : AB8500_ANAGAINX_ENSEMICX);
dev_dbg(codec->dev, "%s: Mic 2 mic-type: %s\n", __func__,
amic_type_str(amics->mic2_type));
snd_soc_update_bits(codec, AB8500_ANAGAIN2, AB8500_ANAGAINX_ENSEMICX,
amics->mic2_type == AMIC_TYPE_DIFFERENTIAL ?
0 : AB8500_ANAGAINX_ENSEMICX);
return 0;
}
static int ab8500_audio_set_ear_cmv(struct snd_soc_codec *codec,
enum ear_cm_voltage ear_cmv)
{
char *cmv_str;
switch (ear_cmv) {
case EAR_CMV_0_95V:
cmv_str = "0.95V";
break;
case EAR_CMV_1_10V:
cmv_str = "1.10V";
break;
case EAR_CMV_1_27V:
cmv_str = "1.27V";
break;
case EAR_CMV_1_58V:
cmv_str = "1.58V";
break;
default:
dev_err(codec->dev,
"%s: Unknown earpiece CM-voltage (%d)!\n",
__func__, (int)ear_cmv);
return -EINVAL;
}
dev_dbg(codec->dev, "%s: Earpiece CM-voltage: %s\n", __func__,
cmv_str);
snd_soc_update_bits(codec, AB8500_ANACONF1, AB8500_ANACONF1_EARSELCM,
ear_cmv);
return 0;
}
static int ab8500_audio_set_bit_delay(struct snd_soc_dai *dai,
unsigned int delay)
{
unsigned int mask, val;
struct snd_soc_codec *codec = dai->codec;
mask = BIT(AB8500_DIGIFCONF2_IF0DEL);
val = 0;
switch (delay) {
case 0:
break;
case 1:
val |= BIT(AB8500_DIGIFCONF2_IF0DEL);
break;
default:
dev_err(dai->codec->dev,
"%s: ERROR: Unsupported bit-delay (0x%x)!\n",
__func__, delay);
return -EINVAL;
}
dev_dbg(dai->codec->dev, "%s: IF0 Bit-delay: %d bits.\n",
__func__, delay);
snd_soc_update_bits(codec, AB8500_DIGIFCONF2, mask, val);
return 0;
}
static int ab8500_codec_set_dai_clock_gate(struct snd_soc_codec *codec,
unsigned int fmt)
{
unsigned int mask;
unsigned int val;
mask = BIT(AB8500_DIGIFCONF1_ENMASTGEN) |
BIT(AB8500_DIGIFCONF1_ENFSBITCLK0);
val = BIT(AB8500_DIGIFCONF1_ENMASTGEN);
switch (fmt & SND_SOC_DAIFMT_CLOCK_MASK) {
case SND_SOC_DAIFMT_CONT:
dev_dbg(codec->dev, "%s: IF0 Clock is continuous.\n",
__func__);
val |= BIT(AB8500_DIGIFCONF1_ENFSBITCLK0);
break;
case SND_SOC_DAIFMT_GATED:
dev_dbg(codec->dev, "%s: IF0 Clock is gated.\n",
__func__);
break;
default:
dev_err(codec->dev,
"%s: ERROR: Unsupported clock mask (0x%x)!\n",
__func__, fmt & SND_SOC_DAIFMT_CLOCK_MASK);
return -EINVAL;
}
snd_soc_update_bits(codec, AB8500_DIGIFCONF1, mask, val);
return 0;
}
static int ab8500_codec_set_dai_fmt(struct snd_soc_dai *dai, unsigned int fmt)
{
unsigned int mask;
unsigned int val;
struct snd_soc_codec *codec = dai->codec;
int status;
dev_dbg(codec->dev, "%s: Enter (fmt = 0x%x)\n", __func__, fmt);
mask = BIT(AB8500_DIGIFCONF3_IF1DATOIF0AD) |
BIT(AB8500_DIGIFCONF3_IF1CLKTOIF0CLK) |
BIT(AB8500_DIGIFCONF3_IF0BFIFOEN) |
BIT(AB8500_DIGIFCONF3_IF0MASTER);
val = 0;
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBM_CFM:
dev_dbg(dai->codec->dev,
"%s: IF0 Master-mode: AB8500 master.\n", __func__);
val |= BIT(AB8500_DIGIFCONF3_IF0MASTER);
break;
case SND_SOC_DAIFMT_CBS_CFS:
dev_dbg(dai->codec->dev,
"%s: IF0 Master-mode: AB8500 slave.\n", __func__);
break;
case SND_SOC_DAIFMT_CBS_CFM:
case SND_SOC_DAIFMT_CBM_CFS:
dev_err(dai->codec->dev,
"%s: ERROR: The device is either a master or a slave.\n",
__func__);
default:
dev_err(dai->codec->dev,
"%s: ERROR: Unsupporter master mask 0x%x\n",
__func__, fmt & SND_SOC_DAIFMT_MASTER_MASK);
return -EINVAL;
}
snd_soc_update_bits(codec, AB8500_DIGIFCONF3, mask, val);
status = ab8500_codec_set_dai_clock_gate(codec, fmt);
if (status) {
dev_err(dai->codec->dev,
"%s: ERROR: Failed to set clock gate (%d).\n",
__func__, status);
return status;
}
mask = BIT(AB8500_DIGIFCONF2_IF0FORMAT0) |
BIT(AB8500_DIGIFCONF2_IF0FORMAT1) |
BIT(AB8500_DIGIFCONF2_FSYNC0P) |
BIT(AB8500_DIGIFCONF2_BITCLK0P);
val = 0;
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
dev_dbg(dai->codec->dev, "%s: IF0 Protocol: I2S\n", __func__);
val |= BIT(AB8500_DIGIFCONF2_IF0FORMAT1);
ab8500_audio_set_bit_delay(dai, 0);
break;
case SND_SOC_DAIFMT_DSP_A:
dev_dbg(dai->codec->dev,
"%s: IF0 Protocol: DSP A (TDM)\n", __func__);
val |= BIT(AB8500_DIGIFCONF2_IF0FORMAT0);
ab8500_audio_set_bit_delay(dai, 1);
break;
case SND_SOC_DAIFMT_DSP_B:
dev_dbg(dai->codec->dev,
"%s: IF0 Protocol: DSP B (TDM)\n", __func__);
val |= BIT(AB8500_DIGIFCONF2_IF0FORMAT0);
ab8500_audio_set_bit_delay(dai, 0);
break;
default:
dev_err(dai->codec->dev,
"%s: ERROR: Unsupported format (0x%x)!\n",
__func__, fmt & SND_SOC_DAIFMT_FORMAT_MASK);
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
dev_dbg(dai->codec->dev,
"%s: IF0: Normal bit clock, normal frame\n",
__func__);
break;
case SND_SOC_DAIFMT_NB_IF:
dev_dbg(dai->codec->dev,
"%s: IF0: Normal bit clock, inverted frame\n",
__func__);
val |= BIT(AB8500_DIGIFCONF2_FSYNC0P);
break;
case SND_SOC_DAIFMT_IB_NF:
dev_dbg(dai->codec->dev,
"%s: IF0: Inverted bit clock, normal frame\n",
__func__);
val |= BIT(AB8500_DIGIFCONF2_BITCLK0P);
break;
case SND_SOC_DAIFMT_IB_IF:
dev_dbg(dai->codec->dev,
"%s: IF0: Inverted bit clock, inverted frame\n",
__func__);
val |= BIT(AB8500_DIGIFCONF2_FSYNC0P);
val |= BIT(AB8500_DIGIFCONF2_BITCLK0P);
break;
default:
dev_err(dai->codec->dev,
"%s: ERROR: Unsupported INV mask 0x%x\n",
__func__, fmt & SND_SOC_DAIFMT_INV_MASK);
return -EINVAL;
}
snd_soc_update_bits(codec, AB8500_DIGIFCONF2, mask, val);
return 0;
}
static int ab8500_codec_set_dai_tdm_slot(struct snd_soc_dai *dai,
unsigned int tx_mask, unsigned int rx_mask,
int slots, int slot_width)
{
struct snd_soc_codec *codec = dai->codec;
unsigned int val, mask, slot, slots_active;
mask = BIT(AB8500_DIGIFCONF2_IF0WL0) |
BIT(AB8500_DIGIFCONF2_IF0WL1);
val = 0;
switch (slot_width) {
case 16:
break;
case 20:
val |= BIT(AB8500_DIGIFCONF2_IF0WL0);
break;
case 24:
val |= BIT(AB8500_DIGIFCONF2_IF0WL1);
break;
case 32:
val |= BIT(AB8500_DIGIFCONF2_IF0WL1) |
BIT(AB8500_DIGIFCONF2_IF0WL0);
break;
default:
dev_err(dai->codec->dev, "%s: Unsupported slot-width 0x%x\n",
__func__, slot_width);
return -EINVAL;
}
dev_dbg(dai->codec->dev, "%s: IF0 slot-width: %d bits.\n",
__func__, slot_width);
snd_soc_update_bits(codec, AB8500_DIGIFCONF2, mask, val);
dev_dbg(dai->codec->dev, "%s: Slots, total: %d\n", __func__, slots);
mask = BIT(AB8500_DIGIFCONF1_IF0BITCLKOS0) |
BIT(AB8500_DIGIFCONF1_IF0BITCLKOS1);
switch (slots) {
case 2:
val = AB8500_MASK_NONE;
break;
case 4:
val = BIT(AB8500_DIGIFCONF1_IF0BITCLKOS0);
break;
case 8:
val = BIT(AB8500_DIGIFCONF1_IF0BITCLKOS1);
break;
case 16:
val = BIT(AB8500_DIGIFCONF1_IF0BITCLKOS0) |
BIT(AB8500_DIGIFCONF1_IF0BITCLKOS1);
break;
default:
dev_err(dai->codec->dev,
"%s: ERROR: Unsupported number of slots (%d)!\n",
__func__, slots);
return -EINVAL;
}
snd_soc_update_bits(codec, AB8500_DIGIFCONF1, mask, val);
if (tx_mask & ~0xff)
return -EINVAL;
mask = AB8500_DASLOTCONFX_SLTODAX_MASK;
tx_mask = tx_mask << AB8500_DA_DATA0_OFFSET;
slots_active = hweight32(tx_mask);
dev_dbg(dai->codec->dev, "%s: Slots, active, TX: %d\n", __func__,
slots_active);
switch (slots_active) {
case 0:
break;
case 1:
slot = ffs(tx_mask);
snd_soc_update_bits(codec, AB8500_DASLOTCONF1, mask, slot);
snd_soc_update_bits(codec, AB8500_DASLOTCONF3, mask, slot);
snd_soc_update_bits(codec, AB8500_DASLOTCONF2, mask, slot);
snd_soc_update_bits(codec, AB8500_DASLOTCONF4, mask, slot);
break;
case 2:
slot = ffs(tx_mask);
snd_soc_update_bits(codec, AB8500_DASLOTCONF1, mask, slot);
snd_soc_update_bits(codec, AB8500_DASLOTCONF3, mask, slot);
slot = fls(tx_mask);
snd_soc_update_bits(codec, AB8500_DASLOTCONF2, mask, slot);
snd_soc_update_bits(codec, AB8500_DASLOTCONF4, mask, slot);
break;
case 8:
dev_dbg(dai->codec->dev,
"%s: In 8-channel mode DA-from-slot mapping is set manually.",
__func__);
break;
default:
dev_err(dai->codec->dev,
"%s: Unsupported number of active TX-slots (%d)!\n",
__func__, slots_active);
return -EINVAL;
}
if (rx_mask & ~0xff)
return -EINVAL;
rx_mask = rx_mask << AB8500_AD_DATA0_OFFSET;
slots_active = hweight32(rx_mask);
dev_dbg(dai->codec->dev, "%s: Slots, active, RX: %d\n", __func__,
slots_active);
switch (slots_active) {
case 0:
break;
case 1:
slot = ffs(rx_mask);
snd_soc_update_bits(codec, AB8500_ADSLOTSEL(slot),
AB8500_MASK_SLOT(slot),
AB8500_ADSLOTSELX_AD_OUT_TO_SLOT(AB8500_AD_OUT3, slot));
break;
case 2:
slot = ffs(rx_mask);
snd_soc_update_bits(codec,
AB8500_ADSLOTSEL(slot),
AB8500_MASK_SLOT(slot),
AB8500_ADSLOTSELX_AD_OUT_TO_SLOT(AB8500_AD_OUT3, slot));
slot = fls(rx_mask);
snd_soc_update_bits(codec,
AB8500_ADSLOTSEL(slot),
AB8500_MASK_SLOT(slot),
AB8500_ADSLOTSELX_AD_OUT_TO_SLOT(AB8500_AD_OUT2, slot));
break;
case 8:
dev_dbg(dai->codec->dev,
"%s: In 8-channel mode AD-to-slot mapping is set manually.",
__func__);
break;
default:
dev_err(dai->codec->dev,
"%s: Unsupported number of active RX-slots (%d)!\n",
__func__, slots_active);
return -EINVAL;
}
return 0;
}
static void ab8500_codec_of_probe(struct device *dev, struct device_node *np,
struct ab8500_codec_platform_data *codec)
{
u32 value;
if (of_property_read_bool(np, "stericsson,amic1-type-single-ended"))
codec->amics.mic1_type = AMIC_TYPE_SINGLE_ENDED;
else
codec->amics.mic1_type = AMIC_TYPE_DIFFERENTIAL;
if (of_property_read_bool(np, "stericsson,amic2-type-single-ended"))
codec->amics.mic2_type = AMIC_TYPE_SINGLE_ENDED;
else
codec->amics.mic2_type = AMIC_TYPE_DIFFERENTIAL;
if (of_property_read_bool(np, "stericsson,amic1a-bias-vamic2"))
codec->amics.mic1a_micbias = AMIC_MICBIAS_VAMIC2;
else
codec->amics.mic1a_micbias = AMIC_MICBIAS_VAMIC1;
if (of_property_read_bool(np, "stericsson,amic1b-bias-vamic2"))
codec->amics.mic1b_micbias = AMIC_MICBIAS_VAMIC2;
else
codec->amics.mic1b_micbias = AMIC_MICBIAS_VAMIC1;
if (of_property_read_bool(np, "stericsson,amic2-bias-vamic1"))
codec->amics.mic2_micbias = AMIC_MICBIAS_VAMIC1;
else
codec->amics.mic2_micbias = AMIC_MICBIAS_VAMIC2;
if (!of_property_read_u32(np, "stericsson,earpeice-cmv", &value)) {
switch (value) {
case 950 :
codec->ear_cmv = EAR_CMV_0_95V;
break;
case 1100 :
codec->ear_cmv = EAR_CMV_1_10V;
break;
case 1270 :
codec->ear_cmv = EAR_CMV_1_27V;
break;
case 1580 :
codec->ear_cmv = EAR_CMV_1_58V;
break;
default :
codec->ear_cmv = EAR_CMV_UNKNOWN;
dev_err(dev, "Unsuitable earpiece voltage found in DT\n");
}
} else {
dev_warn(dev, "No earpiece voltage found in DT - using default\n");
codec->ear_cmv = EAR_CMV_0_95V;
}
}
static int ab8500_codec_probe(struct snd_soc_codec *codec)
{
struct snd_soc_dapm_context *dapm = snd_soc_codec_get_dapm(codec);
struct device *dev = codec->dev;
struct device_node *np = dev->of_node;
struct ab8500_codec_drvdata *drvdata = dev_get_drvdata(dev);
struct ab8500_codec_platform_data codec_pdata;
struct filter_control *fc;
int status;
dev_dbg(dev, "%s: Enter.\n", __func__);
ab8500_codec_of_probe(dev, np, &codec_pdata);
status = ab8500_audio_setup_mics(codec, &codec_pdata.amics);
if (status < 0) {
pr_err("%s: Failed to setup mics (%d)!\n", __func__, status);
return status;
}
status = ab8500_audio_set_ear_cmv(codec, codec_pdata.ear_cmv);
if (status < 0) {
pr_err("%s: Failed to set earpiece CM-voltage (%d)!\n",
__func__, status);
return status;
}
status = ab8500_audio_init_audioblock(codec);
if (status < 0) {
dev_err(dev, "%s: failed to init audio-block (%d)!\n",
__func__, status);
return status;
}
snd_soc_write(codec, AB8500_ANACONF5,
BIT(AB8500_ANACONF5_HSAUTOEN));
snd_soc_write(codec, AB8500_SHORTCIRCONF,
BIT(AB8500_SHORTCIRCONF_HSZCDDIS));
status = snd_soc_add_codec_controls(codec, ab8500_filter_controls,
ARRAY_SIZE(ab8500_filter_controls));
if (status < 0) {
dev_err(dev,
"%s: failed to add ab8500 filter controls (%d).\n",
__func__, status);
return status;
}
fc = (struct filter_control *)
&ab8500_filter_controls[AB8500_FILTER_ANC_FIR].private_value;
drvdata->anc_fir_values = (long *)fc->value;
fc = (struct filter_control *)
&ab8500_filter_controls[AB8500_FILTER_ANC_IIR].private_value;
drvdata->anc_iir_values = (long *)fc->value;
fc = (struct filter_control *)
&ab8500_filter_controls[AB8500_FILTER_SID_FIR].private_value;
drvdata->sid_fir_values = (long *)fc->value;
snd_soc_dapm_disable_pin(dapm, "ANC Configure Input");
mutex_init(&drvdata->ctrl_lock);
return status;
}
static int ab8500_codec_driver_probe(struct platform_device *pdev)
{
int status;
struct ab8500_codec_drvdata *drvdata;
dev_dbg(&pdev->dev, "%s: Enter.\n", __func__);
drvdata = devm_kzalloc(&pdev->dev, sizeof(struct ab8500_codec_drvdata),
GFP_KERNEL);
if (!drvdata)
return -ENOMEM;
drvdata->sid_status = SID_UNCONFIGURED;
drvdata->anc_status = ANC_UNCONFIGURED;
dev_set_drvdata(&pdev->dev, drvdata);
drvdata->regmap = devm_regmap_init(&pdev->dev, NULL, &pdev->dev,
&ab8500_codec_regmap);
if (IS_ERR(drvdata->regmap)) {
status = PTR_ERR(drvdata->regmap);
dev_err(&pdev->dev, "%s: Failed to allocate regmap: %d\n",
__func__, status);
return status;
}
dev_dbg(&pdev->dev, "%s: Register codec.\n", __func__);
status = snd_soc_register_codec(&pdev->dev, &ab8500_codec_driver,
ab8500_codec_dai,
ARRAY_SIZE(ab8500_codec_dai));
if (status < 0)
dev_err(&pdev->dev,
"%s: Error: Failed to register codec (%d).\n",
__func__, status);
return status;
}
static int ab8500_codec_driver_remove(struct platform_device *pdev)
{
dev_dbg(&pdev->dev, "%s Enter.\n", __func__);
snd_soc_unregister_codec(&pdev->dev);
return 0;
}
