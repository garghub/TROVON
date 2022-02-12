static int mixart_update_analog_audio_level(struct snd_mixart* chip, int is_capture)
{
int i, err;
struct mixart_msg request;
struct mixart_io_level io_level;
struct mixart_return_uid resp;
memset(&io_level, 0, sizeof(io_level));
io_level.channel = -1;
for(i=0; i<2; i++) {
if(is_capture) {
io_level.level[i].analog_level = mixart_analog_level[chip->analog_capture_volume[i]];
} else {
if(chip->analog_playback_active[i])
io_level.level[i].analog_level = mixart_analog_level[chip->analog_playback_volume[i]];
else
io_level.level[i].analog_level = mixart_analog_level[MIXART_ANALOG_PLAYBACK_LEVEL_MIN];
}
}
if(is_capture) request.uid = chip->uid_in_analog_physio;
else request.uid = chip->uid_out_analog_physio;
request.message_id = MSG_PHYSICALIO_SET_LEVEL;
request.data = &io_level;
request.size = sizeof(io_level);
err = snd_mixart_send_msg(chip->mgr, &request, sizeof(resp), &resp);
if((err<0) || (resp.error_code)) {
dev_dbg(chip->card->dev,
"error MSG_PHYSICALIO_SET_LEVEL card(%d) is_capture(%d) error_code(%x)\n",
chip->chip_idx, is_capture, resp.error_code);
return -EINVAL;
}
return 0;
}
static int mixart_analog_vol_info(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = 2;
if(kcontrol->private_value == 0) {
uinfo->value.integer.min = MIXART_ANALOG_PLAYBACK_LEVEL_MIN;
uinfo->value.integer.max = MIXART_ANALOG_PLAYBACK_LEVEL_MAX;
} else {
uinfo->value.integer.min = MIXART_ANALOG_CAPTURE_LEVEL_MIN;
uinfo->value.integer.max = MIXART_ANALOG_CAPTURE_LEVEL_MAX;
}
return 0;
}
static int mixart_analog_vol_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_mixart *chip = snd_kcontrol_chip(kcontrol);
mutex_lock(&chip->mgr->mixer_mutex);
if(kcontrol->private_value == 0) {
ucontrol->value.integer.value[0] = chip->analog_playback_volume[0];
ucontrol->value.integer.value[1] = chip->analog_playback_volume[1];
} else {
ucontrol->value.integer.value[0] = chip->analog_capture_volume[0];
ucontrol->value.integer.value[1] = chip->analog_capture_volume[1];
}
mutex_unlock(&chip->mgr->mixer_mutex);
return 0;
}
static int mixart_analog_vol_put(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_mixart *chip = snd_kcontrol_chip(kcontrol);
int changed = 0;
int is_capture, i;
mutex_lock(&chip->mgr->mixer_mutex);
is_capture = (kcontrol->private_value != 0);
for (i = 0; i < 2; i++) {
int new_volume = ucontrol->value.integer.value[i];
int *stored_volume = is_capture ?
&chip->analog_capture_volume[i] :
&chip->analog_playback_volume[i];
if (is_capture) {
if (new_volume < MIXART_ANALOG_CAPTURE_LEVEL_MIN ||
new_volume > MIXART_ANALOG_CAPTURE_LEVEL_MAX)
continue;
} else {
if (new_volume < MIXART_ANALOG_PLAYBACK_LEVEL_MIN ||
new_volume > MIXART_ANALOG_PLAYBACK_LEVEL_MAX)
continue;
}
if (*stored_volume != new_volume) {
*stored_volume = new_volume;
changed = 1;
}
}
if (changed)
mixart_update_analog_audio_level(chip, is_capture);
mutex_unlock(&chip->mgr->mixer_mutex);
return changed;
}
static int mixart_audio_sw_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_mixart *chip = snd_kcontrol_chip(kcontrol);
mutex_lock(&chip->mgr->mixer_mutex);
ucontrol->value.integer.value[0] = chip->analog_playback_active[0];
ucontrol->value.integer.value[1] = chip->analog_playback_active[1];
mutex_unlock(&chip->mgr->mixer_mutex);
return 0;
}
static int mixart_audio_sw_put(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_mixart *chip = snd_kcontrol_chip(kcontrol);
int i, changed = 0;
mutex_lock(&chip->mgr->mixer_mutex);
for (i = 0; i < 2; i++) {
if (chip->analog_playback_active[i] !=
ucontrol->value.integer.value[i]) {
chip->analog_playback_active[i] =
!!ucontrol->value.integer.value[i];
changed = 1;
}
}
if (changed)
mixart_update_analog_audio_level(chip, 0);
mutex_unlock(&chip->mgr->mixer_mutex);
return changed;
}
int mixart_update_playback_stream_level(struct snd_mixart* chip, int is_aes, int idx)
{
int err, i;
int volume[2];
struct mixart_msg request;
struct mixart_set_out_stream_level_req set_level;
u32 status = 0;
struct mixart_pipe *pipe;
memset(&set_level, 0, sizeof(set_level));
set_level.nb_of_stream = 1;
set_level.stream_level.desc.stream_idx = idx;
if(is_aes) {
pipe = &chip->pipe_out_dig;
idx += MIXART_PLAYBACK_STREAMS;
} else {
pipe = &chip->pipe_out_ana;
}
if(pipe->status == PIPE_UNDEFINED)
return 0;
set_level.stream_level.desc.uid_pipe = pipe->group_uid;
for(i=0; i<2; i++) {
if(chip->digital_playback_active[idx][i])
volume[i] = chip->digital_playback_volume[idx][i];
else
volume[i] = MIXART_DIGITAL_LEVEL_MIN;
}
set_level.stream_level.out_level.valid_mask1 = MIXART_OUT_STREAM_SET_LEVEL_LEFT_AUDIO1 | MIXART_OUT_STREAM_SET_LEVEL_RIGHT_AUDIO2;
set_level.stream_level.out_level.left_to_out1_level = mixart_digital_level[volume[0]];
set_level.stream_level.out_level.right_to_out2_level = mixart_digital_level[volume[1]];
request.message_id = MSG_STREAM_SET_OUT_STREAM_LEVEL;
request.uid = (struct mixart_uid){0,0};
request.data = &set_level;
request.size = sizeof(set_level);
err = snd_mixart_send_msg(chip->mgr, &request, sizeof(status), &status);
if((err<0) || status) {
dev_dbg(chip->card->dev,
"error MSG_STREAM_SET_OUT_STREAM_LEVEL card(%d) status(%x)\n",
chip->chip_idx, status);
return -EINVAL;
}
return 0;
}
int mixart_update_capture_stream_level(struct snd_mixart* chip, int is_aes)
{
int err, i, idx;
struct mixart_pipe *pipe;
struct mixart_msg request;
struct mixart_set_in_audio_level_req set_level;
u32 status = 0;
if(is_aes) {
idx = 1;
pipe = &chip->pipe_in_dig;
} else {
idx = 0;
pipe = &chip->pipe_in_ana;
}
if(pipe->status == PIPE_UNDEFINED)
return 0;
memset(&set_level, 0, sizeof(set_level));
set_level.audio_count = 2;
set_level.level[0].connector = pipe->uid_left_connector;
set_level.level[1].connector = pipe->uid_right_connector;
for(i=0; i<2; i++) {
set_level.level[i].valid_mask1 = MIXART_AUDIO_LEVEL_DIGITAL_MASK;
set_level.level[i].digital_level = mixart_digital_level[chip->digital_capture_volume[idx][i]];
}
request.message_id = MSG_STREAM_SET_IN_AUDIO_LEVEL;
request.uid = (struct mixart_uid){0,0};
request.data = &set_level;
request.size = sizeof(set_level);
err = snd_mixart_send_msg(chip->mgr, &request, sizeof(status), &status);
if((err<0) || status) {
dev_dbg(chip->card->dev,
"error MSG_STREAM_SET_IN_AUDIO_LEVEL card(%d) status(%x)\n",
chip->chip_idx, status);
return -EINVAL;
}
return 0;
}
static int mixart_digital_vol_info(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = 2;
uinfo->value.integer.min = MIXART_DIGITAL_LEVEL_MIN;
uinfo->value.integer.max = MIXART_DIGITAL_LEVEL_MAX;
return 0;
}
static int mixart_pcm_vol_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_mixart *chip = snd_kcontrol_chip(kcontrol);
int idx = snd_ctl_get_ioffidx(kcontrol, &ucontrol->id);
int *stored_volume;
int is_capture = kcontrol->private_value & MIXART_VOL_REC_MASK;
int is_aes = kcontrol->private_value & MIXART_VOL_AES_MASK;
mutex_lock(&chip->mgr->mixer_mutex);
if(is_capture) {
if(is_aes) stored_volume = chip->digital_capture_volume[1];
else stored_volume = chip->digital_capture_volume[0];
} else {
snd_BUG_ON(idx >= MIXART_PLAYBACK_STREAMS);
if(is_aes) stored_volume = chip->digital_playback_volume[MIXART_PLAYBACK_STREAMS + idx];
else stored_volume = chip->digital_playback_volume[idx];
}
ucontrol->value.integer.value[0] = stored_volume[0];
ucontrol->value.integer.value[1] = stored_volume[1];
mutex_unlock(&chip->mgr->mixer_mutex);
return 0;
}
static int mixart_pcm_vol_put(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_mixart *chip = snd_kcontrol_chip(kcontrol);
int idx = snd_ctl_get_ioffidx(kcontrol, &ucontrol->id);
int changed = 0;
int is_capture = kcontrol->private_value & MIXART_VOL_REC_MASK;
int is_aes = kcontrol->private_value & MIXART_VOL_AES_MASK;
int* stored_volume;
int i;
mutex_lock(&chip->mgr->mixer_mutex);
if (is_capture) {
if (is_aes)
stored_volume = chip->digital_capture_volume[1];
else
stored_volume = chip->digital_capture_volume[0];
} else {
snd_BUG_ON(idx >= MIXART_PLAYBACK_STREAMS);
if (is_aes)
stored_volume = chip->digital_playback_volume[MIXART_PLAYBACK_STREAMS + idx];
else
stored_volume = chip->digital_playback_volume[idx];
}
for (i = 0; i < 2; i++) {
int vol = ucontrol->value.integer.value[i];
if (vol < MIXART_DIGITAL_LEVEL_MIN ||
vol > MIXART_DIGITAL_LEVEL_MAX)
continue;
if (stored_volume[i] != vol) {
stored_volume[i] = vol;
changed = 1;
}
}
if (changed) {
if (is_capture)
mixart_update_capture_stream_level(chip, is_aes);
else
mixart_update_playback_stream_level(chip, is_aes, idx);
}
mutex_unlock(&chip->mgr->mixer_mutex);
return changed;
}
static int mixart_pcm_sw_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_mixart *chip = snd_kcontrol_chip(kcontrol);
int idx = snd_ctl_get_ioffidx(kcontrol, &ucontrol->id);
snd_BUG_ON(idx >= MIXART_PLAYBACK_STREAMS);
mutex_lock(&chip->mgr->mixer_mutex);
if(kcontrol->private_value & MIXART_VOL_AES_MASK)
idx += MIXART_PLAYBACK_STREAMS;
ucontrol->value.integer.value[0] = chip->digital_playback_active[idx][0];
ucontrol->value.integer.value[1] = chip->digital_playback_active[idx][1];
mutex_unlock(&chip->mgr->mixer_mutex);
return 0;
}
static int mixart_pcm_sw_put(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_mixart *chip = snd_kcontrol_chip(kcontrol);
int changed = 0;
int is_aes = kcontrol->private_value & MIXART_VOL_AES_MASK;
int idx = snd_ctl_get_ioffidx(kcontrol, &ucontrol->id);
int i, j;
snd_BUG_ON(idx >= MIXART_PLAYBACK_STREAMS);
mutex_lock(&chip->mgr->mixer_mutex);
j = idx;
if (is_aes)
j += MIXART_PLAYBACK_STREAMS;
for (i = 0; i < 2; i++) {
if (chip->digital_playback_active[j][i] !=
ucontrol->value.integer.value[i]) {
chip->digital_playback_active[j][i] =
!!ucontrol->value.integer.value[i];
changed = 1;
}
}
if (changed)
mixart_update_playback_stream_level(chip, is_aes, idx);
mutex_unlock(&chip->mgr->mixer_mutex);
return changed;
}
static int mixart_update_monitoring(struct snd_mixart* chip, int channel)
{
int err;
struct mixart_msg request;
struct mixart_set_out_audio_level audio_level;
u32 resp;
if(chip->pipe_out_ana.status == PIPE_UNDEFINED)
return -EINVAL;
if(!channel) request.uid = chip->pipe_out_ana.uid_left_connector;
else request.uid = chip->pipe_out_ana.uid_right_connector;
request.message_id = MSG_CONNECTOR_SET_OUT_AUDIO_LEVEL;
request.data = &audio_level;
request.size = sizeof(audio_level);
memset(&audio_level, 0, sizeof(audio_level));
audio_level.valid_mask1 = MIXART_AUDIO_LEVEL_MONITOR_MASK | MIXART_AUDIO_LEVEL_MUTE_M1_MASK;
audio_level.monitor_level = mixart_digital_level[chip->monitoring_volume[channel!=0]];
audio_level.monitor_mute1 = !chip->monitoring_active[channel!=0];
err = snd_mixart_send_msg(chip->mgr, &request, sizeof(resp), &resp);
if((err<0) || resp) {
dev_dbg(chip->card->dev,
"error MSG_CONNECTOR_SET_OUT_AUDIO_LEVEL card(%d) resp(%x)\n",
chip->chip_idx, resp);
return -EINVAL;
}
return 0;
}
static int mixart_monitor_vol_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_mixart *chip = snd_kcontrol_chip(kcontrol);
mutex_lock(&chip->mgr->mixer_mutex);
ucontrol->value.integer.value[0] = chip->monitoring_volume[0];
ucontrol->value.integer.value[1] = chip->monitoring_volume[1];
mutex_unlock(&chip->mgr->mixer_mutex);
return 0;
}
static int mixart_monitor_vol_put(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_mixart *chip = snd_kcontrol_chip(kcontrol);
int changed = 0;
int i;
mutex_lock(&chip->mgr->mixer_mutex);
for (i = 0; i < 2; i++) {
if (chip->monitoring_volume[i] !=
ucontrol->value.integer.value[i]) {
chip->monitoring_volume[i] =
!!ucontrol->value.integer.value[i];
mixart_update_monitoring(chip, i);
changed = 1;
}
}
mutex_unlock(&chip->mgr->mixer_mutex);
return changed;
}
static int mixart_monitor_sw_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_mixart *chip = snd_kcontrol_chip(kcontrol);
mutex_lock(&chip->mgr->mixer_mutex);
ucontrol->value.integer.value[0] = chip->monitoring_active[0];
ucontrol->value.integer.value[1] = chip->monitoring_active[1];
mutex_unlock(&chip->mgr->mixer_mutex);
return 0;
}
static int mixart_monitor_sw_put(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_mixart *chip = snd_kcontrol_chip(kcontrol);
int changed = 0;
int i;
mutex_lock(&chip->mgr->mixer_mutex);
for (i = 0; i < 2; i++) {
if (chip->monitoring_active[i] !=
ucontrol->value.integer.value[i]) {
chip->monitoring_active[i] =
!!ucontrol->value.integer.value[i];
changed |= (1<<i);
}
}
if (changed) {
int allocate = chip->monitoring_active[0] ||
chip->monitoring_active[1];
if (allocate) {
snd_mixart_add_ref_pipe(chip, MIXART_PCM_ANALOG, 0, 1);
snd_mixart_add_ref_pipe(chip, MIXART_PCM_ANALOG, 1, 1);
}
if (changed & 0x01)
mixart_update_monitoring(chip, 0);
if (changed & 0x02)
mixart_update_monitoring(chip, 1);
if (!allocate) {
snd_mixart_kill_ref_pipe(chip->mgr,
&chip->pipe_in_ana, 1);
snd_mixart_kill_ref_pipe(chip->mgr,
&chip->pipe_out_ana, 1);
}
}
mutex_unlock(&chip->mgr->mixer_mutex);
return (changed != 0);
}
static void mixart_reset_audio_levels(struct snd_mixart *chip)
{
mixart_update_analog_audio_level(chip, 0);
if(chip->chip_idx < 2) {
mixart_update_analog_audio_level(chip, 1);
}
return;
}
int snd_mixart_create_mixer(struct mixart_mgr *mgr)
{
struct snd_mixart *chip;
int err, i;
mutex_init(&mgr->mixer_mutex);
for(i=0; i<mgr->num_cards; i++) {
struct snd_kcontrol_new temp;
chip = mgr->chip[i];
temp = mixart_control_analog_level;
temp.name = "Master Playback Volume";
temp.private_value = 0;
if ((err = snd_ctl_add(chip->card, snd_ctl_new1(&temp, chip))) < 0)
return err;
if ((err = snd_ctl_add(chip->card, snd_ctl_new1(&mixart_control_output_switch, chip))) < 0)
return err;
if(i<2) {
temp = mixart_control_analog_level;
temp.name = "Master Capture Volume";
temp.private_value = 1;
if ((err = snd_ctl_add(chip->card, snd_ctl_new1(&temp, chip))) < 0)
return err;
}
temp = snd_mixart_pcm_vol;
temp.name = "PCM Playback Volume";
temp.count = MIXART_PLAYBACK_STREAMS;
temp.private_value = 0;
if ((err = snd_ctl_add(chip->card, snd_ctl_new1(&temp, chip))) < 0)
return err;
temp.name = "PCM Capture Volume";
temp.count = 1;
temp.private_value = MIXART_VOL_REC_MASK;
if ((err = snd_ctl_add(chip->card, snd_ctl_new1(&temp, chip))) < 0)
return err;
if(mgr->board_type == MIXART_DAUGHTER_TYPE_AES) {
temp.name = "AES Playback Volume";
temp.count = MIXART_PLAYBACK_STREAMS;
temp.private_value = MIXART_VOL_AES_MASK;
if ((err = snd_ctl_add(chip->card, snd_ctl_new1(&temp, chip))) < 0)
return err;
temp.name = "AES Capture Volume";
temp.count = 0;
temp.private_value = MIXART_VOL_REC_MASK | MIXART_VOL_AES_MASK;
if ((err = snd_ctl_add(chip->card, snd_ctl_new1(&temp, chip))) < 0)
return err;
}
temp = mixart_control_pcm_switch;
temp.name = "PCM Playback Switch";
temp.private_value = 0;
if ((err = snd_ctl_add(chip->card, snd_ctl_new1(&temp, chip))) < 0)
return err;
if(mgr->board_type == MIXART_DAUGHTER_TYPE_AES) {
temp.name = "AES Playback Switch";
temp.private_value = MIXART_VOL_AES_MASK;
if ((err = snd_ctl_add(chip->card, snd_ctl_new1(&temp, chip))) < 0)
return err;
}
if ((err = snd_ctl_add(chip->card, snd_ctl_new1(&mixart_control_monitor_vol, chip))) < 0)
return err;
if ((err = snd_ctl_add(chip->card, snd_ctl_new1(&mixart_control_monitor_sw, chip))) < 0)
return err;
mixart_reset_audio_levels(chip);
}
return 0;
}
