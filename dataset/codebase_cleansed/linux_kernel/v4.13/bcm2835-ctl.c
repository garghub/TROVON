static int snd_bcm2835_ctl_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
if (kcontrol->private_value == PCM_PLAYBACK_VOLUME) {
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = 1;
uinfo->value.integer.min = CTRL_VOL_MIN;
uinfo->value.integer.max = CTRL_VOL_MAX;
} else if (kcontrol->private_value == PCM_PLAYBACK_MUTE) {
uinfo->type = SNDRV_CTL_ELEM_TYPE_BOOLEAN;
uinfo->count = 1;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = 1;
} else if (kcontrol->private_value == PCM_PLAYBACK_DEVICE) {
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = 1;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = AUDIO_DEST_MAX - 1;
}
return 0;
}
static int toggle_mute(struct bcm2835_chip *chip, int nmute)
{
if (chip->mute == nmute)
return 0;
if (chip->mute == CTRL_VOL_MUTE) {
chip->volume = chip->old_volume;
audio_info("Unmuting, old_volume = %d, volume = %d ...\n", chip->old_volume, chip->volume);
} else {
chip->old_volume = chip->volume;
chip->volume = 26214;
audio_info("Muting, old_volume = %d, volume = %d ...\n", chip->old_volume, chip->volume);
}
chip->mute = nmute;
return 1;
}
static int snd_bcm2835_ctl_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct bcm2835_chip *chip = snd_kcontrol_chip(kcontrol);
if (mutex_lock_interruptible(&chip->audio_mutex))
return -EINTR;
BUG_ON(!chip && !(chip->avail_substreams & AVAIL_SUBSTREAMS_MASK));
if (kcontrol->private_value == PCM_PLAYBACK_VOLUME)
ucontrol->value.integer.value[0] = chip2alsa(chip->volume);
else if (kcontrol->private_value == PCM_PLAYBACK_MUTE)
ucontrol->value.integer.value[0] = chip->mute;
else if (kcontrol->private_value == PCM_PLAYBACK_DEVICE)
ucontrol->value.integer.value[0] = chip->dest;
mutex_unlock(&chip->audio_mutex);
return 0;
}
static int snd_bcm2835_ctl_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct bcm2835_chip *chip = snd_kcontrol_chip(kcontrol);
int changed = 0;
if (mutex_lock_interruptible(&chip->audio_mutex))
return -EINTR;
if (kcontrol->private_value == PCM_PLAYBACK_VOLUME) {
audio_info("Volume change attempted.. volume = %d new_volume = %d\n", chip->volume, (int)ucontrol->value.integer.value[0]);
if (chip->mute == CTRL_VOL_MUTE) {
changed = 1;
goto unlock;
}
if (changed || (ucontrol->value.integer.value[0] != chip2alsa(chip->volume))) {
chip->volume = alsa2chip(ucontrol->value.integer.value[0]);
changed = 1;
}
} else if (kcontrol->private_value == PCM_PLAYBACK_MUTE) {
audio_info(" Mute attempted\n");
changed = toggle_mute(chip, ucontrol->value.integer.value[0]);
} else if (kcontrol->private_value == PCM_PLAYBACK_DEVICE) {
if (ucontrol->value.integer.value[0] != chip->dest) {
chip->dest = ucontrol->value.integer.value[0];
changed = 1;
}
}
if (changed && bcm2835_audio_set_ctls(chip))
dev_err(chip->card->dev, "Failed to set ALSA controls..\n");
unlock:
mutex_unlock(&chip->audio_mutex);
return changed;
}
static int snd_bcm2835_spdif_default_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_IEC958;
uinfo->count = 1;
return 0;
}
static int snd_bcm2835_spdif_default_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct bcm2835_chip *chip = snd_kcontrol_chip(kcontrol);
int i;
if (mutex_lock_interruptible(&chip->audio_mutex))
return -EINTR;
for (i = 0; i < 4; i++)
ucontrol->value.iec958.status[i] =
(chip->spdif_status >> (i * 8)) & 0xff;
mutex_unlock(&chip->audio_mutex);
return 0;
}
static int snd_bcm2835_spdif_default_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct bcm2835_chip *chip = snd_kcontrol_chip(kcontrol);
unsigned int val = 0;
int i, change;
if (mutex_lock_interruptible(&chip->audio_mutex))
return -EINTR;
for (i = 0; i < 4; i++)
val |= (unsigned int)ucontrol->value.iec958.status[i] << (i * 8);
change = val != chip->spdif_status;
chip->spdif_status = val;
mutex_unlock(&chip->audio_mutex);
return change;
}
static int snd_bcm2835_spdif_mask_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_IEC958;
uinfo->count = 1;
return 0;
}
static int snd_bcm2835_spdif_mask_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
ucontrol->value.iec958.status[0] = IEC958_AES0_NONAUDIO;
return 0;
}
static int snd_bcm2835_spdif_stream_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_IEC958;
uinfo->count = 1;
return 0;
}
static int snd_bcm2835_spdif_stream_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct bcm2835_chip *chip = snd_kcontrol_chip(kcontrol);
int i;
if (mutex_lock_interruptible(&chip->audio_mutex))
return -EINTR;
for (i = 0; i < 4; i++)
ucontrol->value.iec958.status[i] =
(chip->spdif_status >> (i * 8)) & 0xff;
mutex_unlock(&chip->audio_mutex);
return 0;
}
static int snd_bcm2835_spdif_stream_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct bcm2835_chip *chip = snd_kcontrol_chip(kcontrol);
unsigned int val = 0;
int i, change;
if (mutex_lock_interruptible(&chip->audio_mutex))
return -EINTR;
for (i = 0; i < 4; i++)
val |= (unsigned int)ucontrol->value.iec958.status[i] << (i * 8);
change = val != chip->spdif_status;
chip->spdif_status = val;
mutex_unlock(&chip->audio_mutex);
return change;
}
int snd_bcm2835_new_ctl(struct bcm2835_chip *chip)
{
int err;
unsigned int idx;
strcpy(chip->card->mixername, "Broadcom Mixer");
for (idx = 0; idx < ARRAY_SIZE(snd_bcm2835_ctl); idx++) {
err = snd_ctl_add(chip->card,
snd_ctl_new1(&snd_bcm2835_ctl[idx], chip));
if (err < 0)
return err;
}
for (idx = 0; idx < ARRAY_SIZE(snd_bcm2835_spdif); idx++) {
err = snd_ctl_add(chip->card,
snd_ctl_new1(&snd_bcm2835_spdif[idx], chip));
if (err < 0)
return err;
}
return 0;
}
int snd_bcm2835_new_headphones_ctl(struct bcm2835_chip *chip)
{
int err;
unsigned int idx;
strcpy(chip->card->mixername, "Broadcom Mixer");
for (idx = 0; idx < ARRAY_SIZE(snd_bcm2835_headphones_ctl); idx++) {
err = snd_ctl_add(chip->card,
snd_ctl_new1(&snd_bcm2835_headphones_ctl[idx],
chip));
if (err)
return err;
}
return 0;
}
int snd_bcm2835_new_hdmi_ctl(struct bcm2835_chip *chip)
{
int err;
unsigned int idx;
strcpy(chip->card->mixername, "Broadcom Mixer");
for (idx = 0; idx < ARRAY_SIZE(snd_bcm2835_hdmi); idx++) {
err = snd_ctl_add(chip->card,
snd_ctl_new1(&snd_bcm2835_hdmi[idx], chip));
if (err)
return err;
}
return 0;
}
