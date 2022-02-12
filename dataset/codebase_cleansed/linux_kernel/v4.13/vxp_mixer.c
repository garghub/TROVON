static int vx_mic_level_info(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = 1;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = MIC_LEVEL_MAX;
return 0;
}
static int vx_mic_level_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct vx_core *_chip = snd_kcontrol_chip(kcontrol);
struct snd_vxpocket *chip = to_vxpocket(_chip);
ucontrol->value.integer.value[0] = chip->mic_level;
return 0;
}
static int vx_mic_level_put(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct vx_core *_chip = snd_kcontrol_chip(kcontrol);
struct snd_vxpocket *chip = to_vxpocket(_chip);
unsigned int val = ucontrol->value.integer.value[0];
if (val > MIC_LEVEL_MAX)
return -EINVAL;
mutex_lock(&_chip->mixer_mutex);
if (chip->mic_level != ucontrol->value.integer.value[0]) {
vx_set_mic_level(_chip, ucontrol->value.integer.value[0]);
chip->mic_level = ucontrol->value.integer.value[0];
mutex_unlock(&_chip->mixer_mutex);
return 1;
}
mutex_unlock(&_chip->mixer_mutex);
return 0;
}
static int vx_mic_boost_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct vx_core *_chip = snd_kcontrol_chip(kcontrol);
struct snd_vxpocket *chip = to_vxpocket(_chip);
ucontrol->value.integer.value[0] = chip->mic_level;
return 0;
}
static int vx_mic_boost_put(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct vx_core *_chip = snd_kcontrol_chip(kcontrol);
struct snd_vxpocket *chip = to_vxpocket(_chip);
int val = !!ucontrol->value.integer.value[0];
mutex_lock(&_chip->mixer_mutex);
if (chip->mic_level != val) {
vx_set_mic_boost(_chip, val);
chip->mic_level = val;
mutex_unlock(&_chip->mixer_mutex);
return 1;
}
mutex_unlock(&_chip->mixer_mutex);
return 0;
}
int vxp_add_mic_controls(struct vx_core *_chip)
{
struct snd_vxpocket *chip = to_vxpocket(_chip);
int err;
chip->mic_level = 0;
switch (_chip->type) {
case VX_TYPE_VXPOCKET:
vx_set_mic_level(_chip, 0);
break;
case VX_TYPE_VXP440:
vx_set_mic_boost(_chip, 0);
break;
}
switch (_chip->type) {
case VX_TYPE_VXPOCKET:
if ((err = snd_ctl_add(_chip->card, snd_ctl_new1(&vx_control_mic_level, chip))) < 0)
return err;
break;
case VX_TYPE_VXP440:
if ((err = snd_ctl_add(_chip->card, snd_ctl_new1(&vx_control_mic_boost, chip))) < 0)
return err;
break;
}
return 0;
}
