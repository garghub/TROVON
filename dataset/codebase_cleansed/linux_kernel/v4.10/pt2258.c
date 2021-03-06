int snd_pt2258_reset(struct snd_pt2258 *pt)
{
unsigned char bytes[2];
int i;
bytes[0] = PT2258_CMD_RESET;
snd_i2c_lock(pt->i2c_bus);
if (snd_i2c_sendbytes(pt->i2c_dev, bytes, 1) != 1)
goto __error;
snd_i2c_unlock(pt->i2c_bus);
pt->mute = 1;
bytes[0] = PT2258_CMD_MUTE;
snd_i2c_lock(pt->i2c_bus);
if (snd_i2c_sendbytes(pt->i2c_dev, bytes, 1) != 1)
goto __error;
snd_i2c_unlock(pt->i2c_bus);
for (i = 0; i < 6; ++i)
pt->volume[i] = 0;
bytes[0] = 0xd0;
bytes[1] = 0xe0;
snd_i2c_lock(pt->i2c_bus);
if (snd_i2c_sendbytes(pt->i2c_dev, bytes, 2) != 2)
goto __error;
snd_i2c_unlock(pt->i2c_bus);
return 0;
__error:
snd_i2c_unlock(pt->i2c_bus);
snd_printk(KERN_ERR "PT2258 reset failed\n");
return -EIO;
}
static int pt2258_stereo_volume_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = 2;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = 79;
return 0;
}
static int pt2258_stereo_volume_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_pt2258 *pt = kcontrol->private_data;
int base = kcontrol->private_value;
ucontrol->value.integer.value[0] = 79 - pt->volume[base];
ucontrol->value.integer.value[1] = 79 - pt->volume[base + 1];
return 0;
}
static int pt2258_stereo_volume_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_pt2258 *pt = kcontrol->private_data;
int base = kcontrol->private_value;
unsigned char bytes[2];
int val0, val1;
val0 = 79 - ucontrol->value.integer.value[0];
val1 = 79 - ucontrol->value.integer.value[1];
if (val0 < 0 || val0 > 79 || val1 < 0 || val1 > 79)
return -EINVAL;
if (val0 == pt->volume[base] && val1 == pt->volume[base + 1])
return 0;
pt->volume[base] = val0;
bytes[0] = pt2258_channel_code[2 * base] | (val0 / 10);
bytes[1] = pt2258_channel_code[2 * base + 1] | (val0 % 10);
snd_i2c_lock(pt->i2c_bus);
if (snd_i2c_sendbytes(pt->i2c_dev, bytes, 2) != 2)
goto __error;
snd_i2c_unlock(pt->i2c_bus);
pt->volume[base + 1] = val1;
bytes[0] = pt2258_channel_code[2 * base + 2] | (val1 / 10);
bytes[1] = pt2258_channel_code[2 * base + 3] | (val1 % 10);
snd_i2c_lock(pt->i2c_bus);
if (snd_i2c_sendbytes(pt->i2c_dev, bytes, 2) != 2)
goto __error;
snd_i2c_unlock(pt->i2c_bus);
return 1;
__error:
snd_i2c_unlock(pt->i2c_bus);
snd_printk(KERN_ERR "PT2258 access failed\n");
return -EIO;
}
static int pt2258_switch_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_pt2258 *pt = kcontrol->private_data;
ucontrol->value.integer.value[0] = !pt->mute;
return 0;
}
static int pt2258_switch_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_pt2258 *pt = kcontrol->private_data;
unsigned char bytes[2];
int val;
val = !ucontrol->value.integer.value[0];
if (pt->mute == val)
return 0;
pt->mute = val;
bytes[0] = val ? PT2258_CMD_MUTE : PT2258_CMD_UNMUTE;
snd_i2c_lock(pt->i2c_bus);
if (snd_i2c_sendbytes(pt->i2c_dev, bytes, 1) != 1)
goto __error;
snd_i2c_unlock(pt->i2c_bus);
return 1;
__error:
snd_i2c_unlock(pt->i2c_bus);
snd_printk(KERN_ERR "PT2258 access failed 2\n");
return -EIO;
}
int snd_pt2258_build_controls(struct snd_pt2258 *pt)
{
struct snd_kcontrol_new knew;
char *names[3] = {
"Mic Loopback Playback Volume",
"Line Loopback Playback Volume",
"CD Loopback Playback Volume"
};
int i, err;
for (i = 0; i < 3; ++i) {
memset(&knew, 0, sizeof(knew));
knew.name = names[i];
knew.iface = SNDRV_CTL_ELEM_IFACE_MIXER;
knew.count = 1;
knew.access = SNDRV_CTL_ELEM_ACCESS_READWRITE |
SNDRV_CTL_ELEM_ACCESS_TLV_READ;
knew.private_value = 2 * i;
knew.info = pt2258_stereo_volume_info;
knew.get = pt2258_stereo_volume_get;
knew.put = pt2258_stereo_volume_put;
knew.tlv.p = pt2258_db_scale;
err = snd_ctl_add(pt->card, snd_ctl_new1(&knew, pt));
if (err < 0)
return err;
}
memset(&knew, 0, sizeof(knew));
knew.name = "Loopback Switch";
knew.iface = SNDRV_CTL_ELEM_IFACE_MIXER;
knew.info = pt2258_switch_info;
knew.get = pt2258_switch_get;
knew.put = pt2258_switch_put;
knew.access = 0;
err = snd_ctl_add(pt->card, snd_ctl_new1(&knew, pt));
if (err < 0)
return err;
return 0;
}
