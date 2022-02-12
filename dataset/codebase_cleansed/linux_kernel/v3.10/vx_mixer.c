static void vx_write_codec_reg(struct vx_core *chip, int codec, unsigned int data)
{
unsigned long flags;
if (snd_BUG_ON(!chip->ops->write_codec))
return;
if (chip->chip_status & VX_STAT_IS_STALE)
return;
spin_lock_irqsave(&chip->lock, flags);
chip->ops->write_codec(chip, codec, data);
spin_unlock_irqrestore(&chip->lock, flags);
}
static void vx_set_codec_reg(struct vx_core *chip, int codec, int reg, int val)
{
union vx_codec_data data;
SET_CDC_DATA_INIT(data);
SET_CDC_DATA_REG(data, reg);
SET_CDC_DATA_VAL(data, val);
vx_write_codec_reg(chip, codec, data.l);
}
static void vx_set_analog_output_level(struct vx_core *chip, int codec, int left, int right)
{
left = chip->hw->output_level_max - left;
right = chip->hw->output_level_max - right;
if (chip->ops->akm_write) {
chip->ops->akm_write(chip, XX_CODEC_LEVEL_LEFT_REGISTER, left);
chip->ops->akm_write(chip, XX_CODEC_LEVEL_RIGHT_REGISTER, right);
} else {
vx_set_codec_reg(chip, codec, XX_CODEC_LEVEL_LEFT_REGISTER, left);
vx_set_codec_reg(chip, codec, XX_CODEC_LEVEL_RIGHT_REGISTER, right);
}
}
void vx_toggle_dac_mute(struct vx_core *chip, int mute)
{
unsigned int i;
for (i = 0; i < chip->hw->num_codecs; i++) {
if (chip->ops->akm_write)
chip->ops->akm_write(chip, XX_CODEC_DAC_CONTROL_REGISTER, mute);
else
vx_set_codec_reg(chip, i, XX_CODEC_DAC_CONTROL_REGISTER,
mute ? DAC_ATTEN_MAX : DAC_ATTEN_MIN);
}
}
void vx_reset_codec(struct vx_core *chip, int cold_reset)
{
unsigned int i;
int port = chip->type >= VX_TYPE_VXPOCKET ? 0x75 : 0x65;
chip->ops->reset_codec(chip);
if (! chip->ops->akm_write) {
for (i = 0; i < chip->hw->num_codecs; i++) {
vx_set_codec_reg(chip, i, XX_CODEC_DAC_CONTROL_REGISTER, DAC_ATTEN_MAX);
vx_set_codec_reg(chip, i, XX_CODEC_ADC_CONTROL_REGISTER, 0x00);
vx_set_codec_reg(chip, i, XX_CODEC_PORT_MODE_REGISTER, port);
vx_set_codec_reg(chip, i, XX_CODEC_CLOCK_CONTROL_REGISTER, 0x00);
}
}
for (i = 0; i < chip->hw->num_codecs; i++) {
chip->output_level[i][0] = 0;
chip->output_level[i][1] = 0;
vx_set_analog_output_level(chip, i, 0, 0);
}
}
static void vx_change_audio_source(struct vx_core *chip, int src)
{
unsigned long flags;
if (chip->chip_status & VX_STAT_IS_STALE)
return;
spin_lock_irqsave(&chip->lock, flags);
chip->ops->change_audio_source(chip, src);
spin_unlock_irqrestore(&chip->lock, flags);
}
int vx_sync_audio_source(struct vx_core *chip)
{
if (chip->audio_source_target == chip->audio_source ||
chip->pcm_running)
return 0;
vx_change_audio_source(chip, chip->audio_source_target);
chip->audio_source = chip->audio_source_target;
return 1;
}
static int vx_adjust_audio_level(struct vx_core *chip, int audio, int capture,
struct vx_audio_level *info)
{
struct vx_rmh rmh;
if (chip->chip_status & VX_STAT_IS_STALE)
return -EBUSY;
vx_init_rmh(&rmh, CMD_AUDIO_LEVEL_ADJUST);
if (capture)
rmh.Cmd[0] |= COMMAND_RECORD_MASK;
rmh.Cmd[1] = 1 << audio;
rmh.Cmd[2] = 0;
if (info->has_level) {
rmh.Cmd[0] |= VALID_AUDIO_IO_DIGITAL_LEVEL;
rmh.Cmd[2] |= info->level;
}
if (info->has_monitor_level) {
rmh.Cmd[0] |= VALID_AUDIO_IO_MONITORING_LEVEL;
rmh.Cmd[2] |= ((unsigned int)info->monitor_level << 10);
}
if (info->has_mute) {
rmh.Cmd[0] |= VALID_AUDIO_IO_MUTE_LEVEL;
if (info->mute)
rmh.Cmd[2] |= AUDIO_IO_HAS_MUTE_LEVEL;
}
if (info->has_monitor_mute) {
rmh.Cmd[0] |= VALID_AUDIO_IO_MUTE_MONITORING_1 | VALID_AUDIO_IO_MUTE_MONITORING_2;
if (info->monitor_mute)
rmh.Cmd[2] |= AUDIO_IO_HAS_MUTE_MONITORING_1;
}
return vx_send_msg(chip, &rmh);
}
int vx_set_monitor_level(struct vx_core *chip, int audio, int level, int active)
{
struct vx_audio_level info;
memset(&info, 0, sizeof(info));
info.has_monitor_level = 1;
info.monitor_level = level;
info.has_monitor_mute = 1;
info.monitor_mute = !active;
chip->audio_monitor[audio] = level;
chip->audio_monitor_active[audio] = active;
return vx_adjust_audio_level(chip, audio, 0, &info);
}
static int vx_set_audio_switch(struct vx_core *chip, int audio, int active)
{
struct vx_audio_level info;
memset(&info, 0, sizeof(info));
info.has_mute = 1;
info.mute = !active;
chip->audio_active[audio] = active;
return vx_adjust_audio_level(chip, audio, 0, &info);
}
static int vx_set_audio_gain(struct vx_core *chip, int audio, int capture, int level)
{
struct vx_audio_level info;
memset(&info, 0, sizeof(info));
info.has_level = 1;
info.level = level;
chip->audio_gain[capture][audio] = level;
return vx_adjust_audio_level(chip, audio, capture, &info);
}
static void vx_reset_audio_levels(struct vx_core *chip)
{
unsigned int i, c;
struct vx_audio_level info;
memset(chip->audio_gain, 0, sizeof(chip->audio_gain));
memset(chip->audio_active, 0, sizeof(chip->audio_active));
memset(chip->audio_monitor, 0, sizeof(chip->audio_monitor));
memset(chip->audio_monitor_active, 0, sizeof(chip->audio_monitor_active));
for (c = 0; c < 2; c++) {
for (i = 0; i < chip->hw->num_ins * 2; i++) {
memset(&info, 0, sizeof(info));
if (c == 0) {
info.has_monitor_level = 1;
info.has_mute = 1;
info.has_monitor_mute = 1;
}
info.has_level = 1;
info.level = CVAL_0DB;
vx_adjust_audio_level(chip, i, c, &info);
chip->audio_gain[c][i] = CVAL_0DB;
chip->audio_monitor[i] = CVAL_0DB;
}
}
}
static int vx_get_audio_vu_meter(struct vx_core *chip, int audio, int capture, struct vx_vu_meter *info)
{
struct vx_rmh rmh;
int i, err;
if (chip->chip_status & VX_STAT_IS_STALE)
return -EBUSY;
vx_init_rmh(&rmh, CMD_AUDIO_VU_PIC_METER);
rmh.LgStat += 2 * VU_METER_CHANNELS;
if (capture)
rmh.Cmd[0] |= COMMAND_RECORD_MASK;
rmh.Cmd[1] = 0;
for (i = 0; i < VU_METER_CHANNELS; i++)
rmh.Cmd[1] |= 1 << (audio + i);
err = vx_send_msg(chip, &rmh);
if (err < 0)
return err;
for (i = 0; i < 2 * VU_METER_CHANNELS; i +=2) {
info->saturated = (rmh.Stat[0] & (1 << (audio + i))) ? 1 : 0;
info->vu_level = rmh.Stat[i + 1];
info->peak_level = rmh.Stat[i + 2];
info++;
}
return 0;
}
static int vx_output_level_info(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_info *uinfo)
{
struct vx_core *chip = snd_kcontrol_chip(kcontrol);
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = 2;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = chip->hw->output_level_max;
return 0;
}
static int vx_output_level_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct vx_core *chip = snd_kcontrol_chip(kcontrol);
int codec = kcontrol->id.index;
mutex_lock(&chip->mixer_mutex);
ucontrol->value.integer.value[0] = chip->output_level[codec][0];
ucontrol->value.integer.value[1] = chip->output_level[codec][1];
mutex_unlock(&chip->mixer_mutex);
return 0;
}
static int vx_output_level_put(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct vx_core *chip = snd_kcontrol_chip(kcontrol);
int codec = kcontrol->id.index;
unsigned int val[2], vmax;
vmax = chip->hw->output_level_max;
val[0] = ucontrol->value.integer.value[0];
val[1] = ucontrol->value.integer.value[1];
if (val[0] > vmax || val[1] > vmax)
return -EINVAL;
mutex_lock(&chip->mixer_mutex);
if (val[0] != chip->output_level[codec][0] ||
val[1] != chip->output_level[codec][1]) {
vx_set_analog_output_level(chip, codec, val[0], val[1]);
chip->output_level[codec][0] = val[0];
chip->output_level[codec][1] = val[1];
mutex_unlock(&chip->mixer_mutex);
return 1;
}
mutex_unlock(&chip->mixer_mutex);
return 0;
}
static int vx_audio_src_info(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_info *uinfo)
{
static char *texts_mic[3] = {
"Digital", "Line", "Mic"
};
static char *texts_vx2[2] = {
"Digital", "Analog"
};
struct vx_core *chip = snd_kcontrol_chip(kcontrol);
uinfo->type = SNDRV_CTL_ELEM_TYPE_ENUMERATED;
uinfo->count = 1;
if (chip->type >= VX_TYPE_VXPOCKET) {
uinfo->value.enumerated.items = 3;
if (uinfo->value.enumerated.item > 2)
uinfo->value.enumerated.item = 2;
strcpy(uinfo->value.enumerated.name,
texts_mic[uinfo->value.enumerated.item]);
} else {
uinfo->value.enumerated.items = 2;
if (uinfo->value.enumerated.item > 1)
uinfo->value.enumerated.item = 1;
strcpy(uinfo->value.enumerated.name,
texts_vx2[uinfo->value.enumerated.item]);
}
return 0;
}
static int vx_audio_src_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct vx_core *chip = snd_kcontrol_chip(kcontrol);
ucontrol->value.enumerated.item[0] = chip->audio_source_target;
return 0;
}
static int vx_audio_src_put(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct vx_core *chip = snd_kcontrol_chip(kcontrol);
if (chip->type >= VX_TYPE_VXPOCKET) {
if (ucontrol->value.enumerated.item[0] > 2)
return -EINVAL;
} else {
if (ucontrol->value.enumerated.item[0] > 1)
return -EINVAL;
}
mutex_lock(&chip->mixer_mutex);
if (chip->audio_source_target != ucontrol->value.enumerated.item[0]) {
chip->audio_source_target = ucontrol->value.enumerated.item[0];
vx_sync_audio_source(chip);
mutex_unlock(&chip->mixer_mutex);
return 1;
}
mutex_unlock(&chip->mixer_mutex);
return 0;
}
static int vx_clock_mode_info(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_info *uinfo)
{
static char *texts[3] = {
"Auto", "Internal", "External"
};
uinfo->type = SNDRV_CTL_ELEM_TYPE_ENUMERATED;
uinfo->count = 1;
uinfo->value.enumerated.items = 3;
if (uinfo->value.enumerated.item > 2)
uinfo->value.enumerated.item = 2;
strcpy(uinfo->value.enumerated.name,
texts[uinfo->value.enumerated.item]);
return 0;
}
static int vx_clock_mode_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct vx_core *chip = snd_kcontrol_chip(kcontrol);
ucontrol->value.enumerated.item[0] = chip->clock_mode;
return 0;
}
static int vx_clock_mode_put(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct vx_core *chip = snd_kcontrol_chip(kcontrol);
if (ucontrol->value.enumerated.item[0] > 2)
return -EINVAL;
mutex_lock(&chip->mixer_mutex);
if (chip->clock_mode != ucontrol->value.enumerated.item[0]) {
chip->clock_mode = ucontrol->value.enumerated.item[0];
vx_set_clock(chip, chip->freq);
mutex_unlock(&chip->mixer_mutex);
return 1;
}
mutex_unlock(&chip->mixer_mutex);
return 0;
}
static int vx_audio_gain_info(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = 2;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = CVAL_MAX;
return 0;
}
static int vx_audio_gain_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct vx_core *chip = snd_kcontrol_chip(kcontrol);
int audio = kcontrol->private_value & 0xff;
int capture = (kcontrol->private_value >> 8) & 1;
mutex_lock(&chip->mixer_mutex);
ucontrol->value.integer.value[0] = chip->audio_gain[capture][audio];
ucontrol->value.integer.value[1] = chip->audio_gain[capture][audio+1];
mutex_unlock(&chip->mixer_mutex);
return 0;
}
static int vx_audio_gain_put(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct vx_core *chip = snd_kcontrol_chip(kcontrol);
int audio = kcontrol->private_value & 0xff;
int capture = (kcontrol->private_value >> 8) & 1;
unsigned int val[2];
val[0] = ucontrol->value.integer.value[0];
val[1] = ucontrol->value.integer.value[1];
if (val[0] > CVAL_MAX || val[1] > CVAL_MAX)
return -EINVAL;
mutex_lock(&chip->mixer_mutex);
if (val[0] != chip->audio_gain[capture][audio] ||
val[1] != chip->audio_gain[capture][audio+1]) {
vx_set_audio_gain(chip, audio, capture, val[0]);
vx_set_audio_gain(chip, audio+1, capture, val[1]);
mutex_unlock(&chip->mixer_mutex);
return 1;
}
mutex_unlock(&chip->mixer_mutex);
return 0;
}
static int vx_audio_monitor_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct vx_core *chip = snd_kcontrol_chip(kcontrol);
int audio = kcontrol->private_value & 0xff;
mutex_lock(&chip->mixer_mutex);
ucontrol->value.integer.value[0] = chip->audio_monitor[audio];
ucontrol->value.integer.value[1] = chip->audio_monitor[audio+1];
mutex_unlock(&chip->mixer_mutex);
return 0;
}
static int vx_audio_monitor_put(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct vx_core *chip = snd_kcontrol_chip(kcontrol);
int audio = kcontrol->private_value & 0xff;
unsigned int val[2];
val[0] = ucontrol->value.integer.value[0];
val[1] = ucontrol->value.integer.value[1];
if (val[0] > CVAL_MAX || val[1] > CVAL_MAX)
return -EINVAL;
mutex_lock(&chip->mixer_mutex);
if (val[0] != chip->audio_monitor[audio] ||
val[1] != chip->audio_monitor[audio+1]) {
vx_set_monitor_level(chip, audio, val[0],
chip->audio_monitor_active[audio]);
vx_set_monitor_level(chip, audio+1, val[1],
chip->audio_monitor_active[audio+1]);
mutex_unlock(&chip->mixer_mutex);
return 1;
}
mutex_unlock(&chip->mixer_mutex);
return 0;
}
static int vx_audio_sw_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct vx_core *chip = snd_kcontrol_chip(kcontrol);
int audio = kcontrol->private_value & 0xff;
mutex_lock(&chip->mixer_mutex);
ucontrol->value.integer.value[0] = chip->audio_active[audio];
ucontrol->value.integer.value[1] = chip->audio_active[audio+1];
mutex_unlock(&chip->mixer_mutex);
return 0;
}
static int vx_audio_sw_put(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct vx_core *chip = snd_kcontrol_chip(kcontrol);
int audio = kcontrol->private_value & 0xff;
mutex_lock(&chip->mixer_mutex);
if (ucontrol->value.integer.value[0] != chip->audio_active[audio] ||
ucontrol->value.integer.value[1] != chip->audio_active[audio+1]) {
vx_set_audio_switch(chip, audio,
!!ucontrol->value.integer.value[0]);
vx_set_audio_switch(chip, audio+1,
!!ucontrol->value.integer.value[1]);
mutex_unlock(&chip->mixer_mutex);
return 1;
}
mutex_unlock(&chip->mixer_mutex);
return 0;
}
static int vx_monitor_sw_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct vx_core *chip = snd_kcontrol_chip(kcontrol);
int audio = kcontrol->private_value & 0xff;
mutex_lock(&chip->mixer_mutex);
ucontrol->value.integer.value[0] = chip->audio_monitor_active[audio];
ucontrol->value.integer.value[1] = chip->audio_monitor_active[audio+1];
mutex_unlock(&chip->mixer_mutex);
return 0;
}
static int vx_monitor_sw_put(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct vx_core *chip = snd_kcontrol_chip(kcontrol);
int audio = kcontrol->private_value & 0xff;
mutex_lock(&chip->mixer_mutex);
if (ucontrol->value.integer.value[0] != chip->audio_monitor_active[audio] ||
ucontrol->value.integer.value[1] != chip->audio_monitor_active[audio+1]) {
vx_set_monitor_level(chip, audio, chip->audio_monitor[audio],
!!ucontrol->value.integer.value[0]);
vx_set_monitor_level(chip, audio+1, chip->audio_monitor[audio+1],
!!ucontrol->value.integer.value[1]);
mutex_unlock(&chip->mixer_mutex);
return 1;
}
mutex_unlock(&chip->mixer_mutex);
return 0;
}
static int vx_iec958_info(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_IEC958;
uinfo->count = 1;
return 0;
}
static int vx_iec958_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct vx_core *chip = snd_kcontrol_chip(kcontrol);
mutex_lock(&chip->mixer_mutex);
ucontrol->value.iec958.status[0] = (chip->uer_bits >> 0) & 0xff;
ucontrol->value.iec958.status[1] = (chip->uer_bits >> 8) & 0xff;
ucontrol->value.iec958.status[2] = (chip->uer_bits >> 16) & 0xff;
ucontrol->value.iec958.status[3] = (chip->uer_bits >> 24) & 0xff;
mutex_unlock(&chip->mixer_mutex);
return 0;
}
static int vx_iec958_mask_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
ucontrol->value.iec958.status[0] = 0xff;
ucontrol->value.iec958.status[1] = 0xff;
ucontrol->value.iec958.status[2] = 0xff;
ucontrol->value.iec958.status[3] = 0xff;
return 0;
}
static int vx_iec958_put(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct vx_core *chip = snd_kcontrol_chip(kcontrol);
unsigned int val;
val = (ucontrol->value.iec958.status[0] << 0) |
(ucontrol->value.iec958.status[1] << 8) |
(ucontrol->value.iec958.status[2] << 16) |
(ucontrol->value.iec958.status[3] << 24);
mutex_lock(&chip->mixer_mutex);
if (chip->uer_bits != val) {
chip->uer_bits = val;
vx_set_iec958_status(chip, val);
mutex_unlock(&chip->mixer_mutex);
return 1;
}
mutex_unlock(&chip->mixer_mutex);
return 0;
}
static int vx_vu_meter_info(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = 2;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = METER_MAX;
return 0;
}
static int vx_vu_meter_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct vx_core *chip = snd_kcontrol_chip(kcontrol);
struct vx_vu_meter meter[2];
int audio = kcontrol->private_value & 0xff;
int capture = (kcontrol->private_value >> 8) & 1;
vx_get_audio_vu_meter(chip, audio, capture, meter);
ucontrol->value.integer.value[0] = meter[0].vu_level >> METER_SHIFT;
ucontrol->value.integer.value[1] = meter[1].vu_level >> METER_SHIFT;
return 0;
}
static int vx_peak_meter_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct vx_core *chip = snd_kcontrol_chip(kcontrol);
struct vx_vu_meter meter[2];
int audio = kcontrol->private_value & 0xff;
int capture = (kcontrol->private_value >> 8) & 1;
vx_get_audio_vu_meter(chip, audio, capture, meter);
ucontrol->value.integer.value[0] = meter[0].peak_level >> METER_SHIFT;
ucontrol->value.integer.value[1] = meter[1].peak_level >> METER_SHIFT;
return 0;
}
static int vx_saturation_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct vx_core *chip = snd_kcontrol_chip(kcontrol);
struct vx_vu_meter meter[2];
int audio = kcontrol->private_value & 0xff;
vx_get_audio_vu_meter(chip, audio, 1, meter);
ucontrol->value.integer.value[0] = meter[0].saturated;
ucontrol->value.integer.value[1] = meter[1].saturated;
return 0;
}
int snd_vx_mixer_new(struct vx_core *chip)
{
unsigned int i, c;
int err;
struct snd_kcontrol_new temp;
struct snd_card *card = chip->card;
char name[32];
strcpy(card->mixername, card->driver);
for (i = 0; i < chip->hw->num_outs; i++) {
temp = vx_control_output_level;
temp.index = i;
temp.tlv.p = chip->hw->output_level_db_scale;
if ((err = snd_ctl_add(card, snd_ctl_new1(&temp, chip))) < 0)
return err;
}
for (i = 0; i < chip->hw->num_outs; i++) {
int val = i * 2;
temp = vx_control_audio_gain;
temp.index = i;
temp.name = "PCM Playback Volume";
temp.private_value = val;
if ((err = snd_ctl_add(card, snd_ctl_new1(&temp, chip))) < 0)
return err;
temp = vx_control_output_switch;
temp.index = i;
temp.private_value = val;
if ((err = snd_ctl_add(card, snd_ctl_new1(&temp, chip))) < 0)
return err;
temp = vx_control_monitor_gain;
temp.index = i;
temp.private_value = val;
if ((err = snd_ctl_add(card, snd_ctl_new1(&temp, chip))) < 0)
return err;
temp = vx_control_monitor_switch;
temp.index = i;
temp.private_value = val;
if ((err = snd_ctl_add(card, snd_ctl_new1(&temp, chip))) < 0)
return err;
}
for (i = 0; i < chip->hw->num_outs; i++) {
temp = vx_control_audio_gain;
temp.index = i;
temp.name = "PCM Capture Volume";
temp.private_value = (i * 2) | (1 << 8);
if ((err = snd_ctl_add(card, snd_ctl_new1(&temp, chip))) < 0)
return err;
}
if ((err = snd_ctl_add(card, snd_ctl_new1(&vx_control_audio_src, chip))) < 0)
return err;
if ((err = snd_ctl_add(card, snd_ctl_new1(&vx_control_clock_mode, chip))) < 0)
return err;
if ((err = snd_ctl_add(card, snd_ctl_new1(&vx_control_iec958_mask, chip))) < 0)
return err;
if ((err = snd_ctl_add(card, snd_ctl_new1(&vx_control_iec958, chip))) < 0)
return err;
for (c = 0; c < 2; c++) {
static char *dir[2] = { "Output", "Input" };
for (i = 0; i < chip->hw->num_ins; i++) {
int val = (i * 2) | (c << 8);
if (c == 1) {
temp = vx_control_saturation;
temp.index = i;
temp.private_value = val;
if ((err = snd_ctl_add(card, snd_ctl_new1(&temp, chip))) < 0)
return err;
}
sprintf(name, "%s VU Meter", dir[c]);
temp = vx_control_vu_meter;
temp.index = i;
temp.name = name;
temp.private_value = val;
if ((err = snd_ctl_add(card, snd_ctl_new1(&temp, chip))) < 0)
return err;
sprintf(name, "%s Peak Meter", dir[c]);
temp = vx_control_peak_meter;
temp.index = i;
temp.name = name;
temp.private_value = val;
if ((err = snd_ctl_add(card, snd_ctl_new1(&temp, chip))) < 0)
return err;
}
}
vx_reset_audio_levels(chip);
return 0;
}
