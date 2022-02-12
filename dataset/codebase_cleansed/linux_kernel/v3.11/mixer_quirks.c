static void usb_mixer_elem_free(struct snd_kcontrol *kctl)
{
kfree(kctl->private_data);
kctl->private_data = NULL;
}
static int snd_create_std_mono_ctl_offset(struct usb_mixer_interface *mixer,
unsigned int unitid,
unsigned int control,
unsigned int cmask,
int val_type,
unsigned int idx_off,
const char *name,
snd_kcontrol_tlv_rw_t *tlv_callback)
{
int err;
struct usb_mixer_elem_info *cval;
struct snd_kcontrol *kctl;
cval = kzalloc(sizeof(*cval), GFP_KERNEL);
if (!cval)
return -ENOMEM;
cval->id = unitid;
cval->mixer = mixer;
cval->val_type = val_type;
cval->channels = 1;
cval->control = control;
cval->cmask = cmask;
cval->idx_off = idx_off;
cval->min = 0;
cval->max = 1;
cval->res = 0;
cval->dBmin = 0;
cval->dBmax = 0;
kctl = snd_ctl_new1(snd_usb_feature_unit_ctl, cval);
if (!kctl) {
kfree(cval);
return -ENOMEM;
}
snprintf(kctl->id.name, sizeof(kctl->id.name), name);
kctl->private_free = usb_mixer_elem_free;
if (tlv_callback) {
kctl->tlv.c = tlv_callback;
kctl->vd[0].access |=
SNDRV_CTL_ELEM_ACCESS_TLV_READ |
SNDRV_CTL_ELEM_ACCESS_TLV_CALLBACK;
}
err = snd_usb_mixer_add_control(mixer, kctl);
if (err < 0)
return err;
return 0;
}
static int snd_create_std_mono_ctl(struct usb_mixer_interface *mixer,
unsigned int unitid,
unsigned int control,
unsigned int cmask,
int val_type,
const char *name,
snd_kcontrol_tlv_rw_t *tlv_callback)
{
return snd_create_std_mono_ctl_offset(mixer, unitid, control, cmask,
val_type, 0 , name, tlv_callback);
}
static int snd_create_std_mono_table(struct usb_mixer_interface *mixer,
struct std_mono_table *t)
{
int err;
while (t->name != NULL) {
err = snd_create_std_mono_ctl(mixer, t->unitid, t->control,
t->cmask, t->val_type, t->name, t->tlv_callback);
if (err < 0)
return err;
t++;
}
return 0;
}
static void snd_usb_soundblaster_remote_complete(struct urb *urb)
{
struct usb_mixer_interface *mixer = urb->context;
const struct rc_config *rc = mixer->rc_cfg;
u32 code;
if (urb->status < 0 || urb->actual_length < rc->min_packet_length)
return;
code = mixer->rc_buffer[rc->offset];
if (rc->length == 2)
code |= mixer->rc_buffer[rc->offset + 1] << 8;
if (code == rc->mute_code)
snd_usb_mixer_notify_id(mixer, rc->mute_mixer_id);
mixer->rc_code = code;
wmb();
wake_up(&mixer->rc_waitq);
}
static long snd_usb_sbrc_hwdep_read(struct snd_hwdep *hw, char __user *buf,
long count, loff_t *offset)
{
struct usb_mixer_interface *mixer = hw->private_data;
int err;
u32 rc_code;
if (count != 1 && count != 4)
return -EINVAL;
err = wait_event_interruptible(mixer->rc_waitq,
(rc_code = xchg(&mixer->rc_code, 0)) != 0);
if (err == 0) {
if (count == 1)
err = put_user(rc_code, buf);
else
err = put_user(rc_code, (u32 __user *)buf);
}
return err < 0 ? err : count;
}
static unsigned int snd_usb_sbrc_hwdep_poll(struct snd_hwdep *hw, struct file *file,
poll_table *wait)
{
struct usb_mixer_interface *mixer = hw->private_data;
poll_wait(file, &mixer->rc_waitq, wait);
return mixer->rc_code ? POLLIN | POLLRDNORM : 0;
}
static int snd_usb_soundblaster_remote_init(struct usb_mixer_interface *mixer)
{
struct snd_hwdep *hwdep;
int err, len, i;
for (i = 0; i < ARRAY_SIZE(rc_configs); ++i)
if (rc_configs[i].usb_id == mixer->chip->usb_id)
break;
if (i >= ARRAY_SIZE(rc_configs))
return 0;
mixer->rc_cfg = &rc_configs[i];
len = mixer->rc_cfg->packet_length;
init_waitqueue_head(&mixer->rc_waitq);
err = snd_hwdep_new(mixer->chip->card, "SB remote control", 0, &hwdep);
if (err < 0)
return err;
snprintf(hwdep->name, sizeof(hwdep->name),
"%s remote control", mixer->chip->card->shortname);
hwdep->iface = SNDRV_HWDEP_IFACE_SB_RC;
hwdep->private_data = mixer;
hwdep->ops.read = snd_usb_sbrc_hwdep_read;
hwdep->ops.poll = snd_usb_sbrc_hwdep_poll;
hwdep->exclusive = 1;
mixer->rc_urb = usb_alloc_urb(0, GFP_KERNEL);
if (!mixer->rc_urb)
return -ENOMEM;
mixer->rc_setup_packet = kmalloc(sizeof(*mixer->rc_setup_packet), GFP_KERNEL);
if (!mixer->rc_setup_packet) {
usb_free_urb(mixer->rc_urb);
mixer->rc_urb = NULL;
return -ENOMEM;
}
mixer->rc_setup_packet->bRequestType =
USB_DIR_IN | USB_TYPE_CLASS | USB_RECIP_INTERFACE;
mixer->rc_setup_packet->bRequest = UAC_GET_MEM;
mixer->rc_setup_packet->wValue = cpu_to_le16(0);
mixer->rc_setup_packet->wIndex = cpu_to_le16(0);
mixer->rc_setup_packet->wLength = cpu_to_le16(len);
usb_fill_control_urb(mixer->rc_urb, mixer->chip->dev,
usb_rcvctrlpipe(mixer->chip->dev, 0),
(u8*)mixer->rc_setup_packet, mixer->rc_buffer, len,
snd_usb_soundblaster_remote_complete, mixer);
return 0;
}
static int snd_audigy2nx_led_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct usb_mixer_interface *mixer = snd_kcontrol_chip(kcontrol);
int index = kcontrol->private_value;
ucontrol->value.integer.value[0] = mixer->audigy2nx_leds[index];
return 0;
}
static int snd_audigy2nx_led_put(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct usb_mixer_interface *mixer = snd_kcontrol_chip(kcontrol);
int index = kcontrol->private_value;
int value = ucontrol->value.integer.value[0];
int err, changed;
if (value > 1)
return -EINVAL;
changed = value != mixer->audigy2nx_leds[index];
down_read(&mixer->chip->shutdown_rwsem);
if (mixer->chip->shutdown) {
err = -ENODEV;
goto out;
}
if (mixer->chip->usb_id == USB_ID(0x041e, 0x3042))
err = snd_usb_ctl_msg(mixer->chip->dev,
usb_sndctrlpipe(mixer->chip->dev, 0), 0x24,
USB_DIR_OUT | USB_TYPE_VENDOR | USB_RECIP_OTHER,
!value, 0, NULL, 0);
if (mixer->chip->usb_id == USB_ID(0x041e, 0x30df))
err = snd_usb_ctl_msg(mixer->chip->dev,
usb_sndctrlpipe(mixer->chip->dev, 0), 0x24,
USB_DIR_OUT | USB_TYPE_VENDOR | USB_RECIP_OTHER,
!value, 0, NULL, 0);
else
err = snd_usb_ctl_msg(mixer->chip->dev,
usb_sndctrlpipe(mixer->chip->dev, 0), 0x24,
USB_DIR_OUT | USB_TYPE_VENDOR | USB_RECIP_OTHER,
value, index + 2, NULL, 0);
out:
up_read(&mixer->chip->shutdown_rwsem);
if (err < 0)
return err;
mixer->audigy2nx_leds[index] = value;
return changed;
}
static int snd_audigy2nx_controls_create(struct usb_mixer_interface *mixer)
{
int i, err;
for (i = 0; i < ARRAY_SIZE(snd_audigy2nx_controls); ++i) {
if ((mixer->chip->usb_id == USB_ID(0x041e, 0x3042)) && i == 0)
continue;
if ((mixer->chip->usb_id == USB_ID(0x041e, 0x30df)) && i == 0)
continue;
if (i > 1 &&
(mixer->chip->usb_id == USB_ID(0x041e, 0x3040) ||
mixer->chip->usb_id == USB_ID(0x041e, 0x3042) ||
mixer->chip->usb_id == USB_ID(0x041e, 0x30df) ||
mixer->chip->usb_id == USB_ID(0x041e, 0x3048)))
break;
err = snd_ctl_add(mixer->chip->card,
snd_ctl_new1(&snd_audigy2nx_controls[i], mixer));
if (err < 0)
return err;
}
mixer->audigy2nx_leds[1] = 1;
return 0;
}
static void snd_audigy2nx_proc_read(struct snd_info_entry *entry,
struct snd_info_buffer *buffer)
{
static const struct sb_jack {
int unitid;
const char *name;
} jacks_audigy2nx[] = {
{4, "dig in "},
{7, "line in"},
{19, "spk out"},
{20, "hph out"},
{-1, NULL}
}, jacks_live24ext[] = {
{4, "line in"},
{3, "hph out"},
{0, "RC "},
{-1, NULL}
};
const struct sb_jack *jacks;
struct usb_mixer_interface *mixer = entry->private_data;
int i, err;
u8 buf[3];
snd_iprintf(buffer, "%s jacks\n\n", mixer->chip->card->shortname);
if (mixer->chip->usb_id == USB_ID(0x041e, 0x3020))
jacks = jacks_audigy2nx;
else if (mixer->chip->usb_id == USB_ID(0x041e, 0x3040) ||
mixer->chip->usb_id == USB_ID(0x041e, 0x3048))
jacks = jacks_live24ext;
else
return;
for (i = 0; jacks[i].name; ++i) {
snd_iprintf(buffer, "%s: ", jacks[i].name);
down_read(&mixer->chip->shutdown_rwsem);
if (mixer->chip->shutdown)
err = 0;
else
err = snd_usb_ctl_msg(mixer->chip->dev,
usb_rcvctrlpipe(mixer->chip->dev, 0),
UAC_GET_MEM, USB_DIR_IN | USB_TYPE_CLASS |
USB_RECIP_INTERFACE, 0,
jacks[i].unitid << 8, buf, 3);
up_read(&mixer->chip->shutdown_rwsem);
if (err == 3 && (buf[0] == 3 || buf[0] == 6))
snd_iprintf(buffer, "%02x %02x\n", buf[1], buf[2]);
else
snd_iprintf(buffer, "?\n");
}
}
static int snd_xonar_u1_switch_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct usb_mixer_interface *mixer = snd_kcontrol_chip(kcontrol);
ucontrol->value.integer.value[0] = !!(mixer->xonar_u1_status & 0x02);
return 0;
}
static int snd_xonar_u1_switch_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct usb_mixer_interface *mixer = snd_kcontrol_chip(kcontrol);
u8 old_status, new_status;
int err, changed;
old_status = mixer->xonar_u1_status;
if (ucontrol->value.integer.value[0])
new_status = old_status | 0x02;
else
new_status = old_status & ~0x02;
changed = new_status != old_status;
down_read(&mixer->chip->shutdown_rwsem);
if (mixer->chip->shutdown)
err = -ENODEV;
else
err = snd_usb_ctl_msg(mixer->chip->dev,
usb_sndctrlpipe(mixer->chip->dev, 0), 0x08,
USB_DIR_OUT | USB_TYPE_VENDOR | USB_RECIP_OTHER,
50, 0, &new_status, 1);
up_read(&mixer->chip->shutdown_rwsem);
if (err < 0)
return err;
mixer->xonar_u1_status = new_status;
return changed;
}
static int snd_xonar_u1_controls_create(struct usb_mixer_interface *mixer)
{
int err;
err = snd_ctl_add(mixer->chip->card,
snd_ctl_new1(&snd_xonar_u1_output_switch, mixer));
if (err < 0)
return err;
mixer->xonar_u1_status = 0x05;
return 0;
}
static int snd_nativeinstruments_control_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct usb_mixer_interface *mixer = snd_kcontrol_chip(kcontrol);
struct usb_device *dev = mixer->chip->dev;
u8 bRequest = (kcontrol->private_value >> 16) & 0xff;
u16 wIndex = kcontrol->private_value & 0xffff;
u8 tmp;
int ret;
down_read(&mixer->chip->shutdown_rwsem);
if (mixer->chip->shutdown)
ret = -ENODEV;
else
ret = usb_control_msg(dev, usb_rcvctrlpipe(dev, 0), bRequest,
USB_TYPE_VENDOR | USB_RECIP_DEVICE | USB_DIR_IN,
0, wIndex,
&tmp, sizeof(tmp), 1000);
up_read(&mixer->chip->shutdown_rwsem);
if (ret < 0) {
snd_printk(KERN_ERR
"unable to issue vendor read request (ret = %d)", ret);
return ret;
}
ucontrol->value.integer.value[0] = tmp;
return 0;
}
static int snd_nativeinstruments_control_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct usb_mixer_interface *mixer = snd_kcontrol_chip(kcontrol);
struct usb_device *dev = mixer->chip->dev;
u8 bRequest = (kcontrol->private_value >> 16) & 0xff;
u16 wIndex = kcontrol->private_value & 0xffff;
u16 wValue = ucontrol->value.integer.value[0];
int ret;
down_read(&mixer->chip->shutdown_rwsem);
if (mixer->chip->shutdown)
ret = -ENODEV;
else
ret = usb_control_msg(dev, usb_sndctrlpipe(dev, 0), bRequest,
USB_TYPE_VENDOR | USB_RECIP_DEVICE | USB_DIR_OUT,
wValue, wIndex,
NULL, 0, 1000);
up_read(&mixer->chip->shutdown_rwsem);
if (ret < 0) {
snd_printk(KERN_ERR
"unable to issue vendor write request (ret = %d)", ret);
return ret;
}
return 0;
}
static int snd_nativeinstruments_create_mixer(struct usb_mixer_interface *mixer,
const struct snd_kcontrol_new *kc,
unsigned int count)
{
int i, err = 0;
struct snd_kcontrol_new template = {
.iface = SNDRV_CTL_ELEM_IFACE_MIXER,
.access = SNDRV_CTL_ELEM_ACCESS_READWRITE,
.get = snd_nativeinstruments_control_get,
.put = snd_nativeinstruments_control_put,
.info = snd_ctl_boolean_mono_info,
};
for (i = 0; i < count; i++) {
struct snd_kcontrol *c;
template.name = kc[i].name;
template.private_value = kc[i].private_value;
c = snd_ctl_new1(&template, mixer);
err = snd_ctl_add(mixer->chip->card, c);
if (err < 0)
break;
}
return err;
}
static int snd_ftu_eff_switch_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
static const char *texts[8] = {"Room 1",
"Room 2",
"Room 3",
"Hall 1",
"Hall 2",
"Plate",
"Delay",
"Echo"
};
uinfo->type = SNDRV_CTL_ELEM_TYPE_ENUMERATED;
uinfo->count = 1;
uinfo->value.enumerated.items = 8;
if (uinfo->value.enumerated.item > 7)
uinfo->value.enumerated.item = 7;
strcpy(uinfo->value.enumerated.name,
texts[uinfo->value.enumerated.item]);
return 0;
}
static int snd_ftu_eff_switch_get(struct snd_kcontrol *kctl,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_usb_audio *chip;
struct usb_mixer_interface *mixer;
struct snd_ftu_eff_switch_priv_val *pval;
int err;
unsigned char value[2];
int id, validx;
const int val_len = 2;
value[0] = 0x00;
value[1] = 0x00;
pval = (struct snd_ftu_eff_switch_priv_val *)
kctl->private_value;
if (pval->is_cached) {
ucontrol->value.enumerated.item[0] = pval->cached_value;
return 0;
}
mixer = (struct usb_mixer_interface *) pval->mixer;
if (snd_BUG_ON(!mixer))
return -EINVAL;
chip = (struct snd_usb_audio *) mixer->chip;
if (snd_BUG_ON(!chip))
return -EINVAL;
id = pval->bUnitID;
validx = pval->validx;
down_read(&mixer->chip->shutdown_rwsem);
if (mixer->chip->shutdown)
err = -ENODEV;
else
err = snd_usb_ctl_msg(chip->dev,
usb_rcvctrlpipe(chip->dev, 0), UAC_GET_CUR,
USB_RECIP_INTERFACE | USB_TYPE_CLASS | USB_DIR_IN,
validx << 8, snd_usb_ctrl_intf(chip) | (id << 8),
value, val_len);
up_read(&mixer->chip->shutdown_rwsem);
if (err < 0)
return err;
ucontrol->value.enumerated.item[0] = value[0];
pval->cached_value = value[0];
pval->is_cached = 1;
return 0;
}
static int snd_ftu_eff_switch_put(struct snd_kcontrol *kctl,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_usb_audio *chip;
struct snd_ftu_eff_switch_priv_val *pval;
struct usb_mixer_interface *mixer;
int changed, cur_val, err, new_val;
unsigned char value[2];
int id, validx;
const int val_len = 2;
changed = 0;
pval = (struct snd_ftu_eff_switch_priv_val *)
kctl->private_value;
cur_val = pval->cached_value;
new_val = ucontrol->value.enumerated.item[0];
mixer = (struct usb_mixer_interface *) pval->mixer;
if (snd_BUG_ON(!mixer))
return -EINVAL;
chip = (struct snd_usb_audio *) mixer->chip;
if (snd_BUG_ON(!chip))
return -EINVAL;
id = pval->bUnitID;
validx = pval->validx;
if (!pval->is_cached) {
down_read(&mixer->chip->shutdown_rwsem);
if (mixer->chip->shutdown)
err = -ENODEV;
else
err = snd_usb_ctl_msg(chip->dev,
usb_rcvctrlpipe(chip->dev, 0), UAC_GET_CUR,
USB_RECIP_INTERFACE | USB_TYPE_CLASS | USB_DIR_IN,
validx << 8, snd_usb_ctrl_intf(chip) | (id << 8),
value, val_len);
up_read(&mixer->chip->shutdown_rwsem);
if (err < 0)
return err;
cur_val = value[0];
pval->cached_value = cur_val;
pval->is_cached = 1;
}
if (cur_val != new_val) {
value[0] = new_val;
value[1] = 0;
down_read(&mixer->chip->shutdown_rwsem);
if (mixer->chip->shutdown)
err = -ENODEV;
else
err = snd_usb_ctl_msg(chip->dev,
usb_sndctrlpipe(chip->dev, 0), UAC_SET_CUR,
USB_RECIP_INTERFACE | USB_TYPE_CLASS | USB_DIR_OUT,
validx << 8, snd_usb_ctrl_intf(chip) | (id << 8),
value, val_len);
up_read(&mixer->chip->shutdown_rwsem);
if (err < 0)
return err;
pval->cached_value = new_val;
pval->is_cached = 1;
changed = 1;
}
return changed;
}
static int snd_ftu_create_effect_switch(struct usb_mixer_interface *mixer,
int validx, int bUnitID)
{
static struct snd_kcontrol_new template = {
.iface = SNDRV_CTL_ELEM_IFACE_MIXER,
.name = "Effect Program Switch",
.index = 0,
.access = SNDRV_CTL_ELEM_ACCESS_READWRITE,
.info = snd_ftu_eff_switch_info,
.get = snd_ftu_eff_switch_get,
.put = snd_ftu_eff_switch_put
};
int err;
struct snd_kcontrol *kctl;
struct snd_ftu_eff_switch_priv_val *pval;
pval = kzalloc(sizeof(*pval), GFP_KERNEL);
if (!pval)
return -ENOMEM;
pval->cached_value = 0;
pval->is_cached = 0;
pval->mixer = mixer;
pval->bUnitID = bUnitID;
pval->validx = validx;
template.private_value = (unsigned long) pval;
kctl = snd_ctl_new1(&template, mixer->chip);
if (!kctl) {
kfree(pval);
return -ENOMEM;
}
err = snd_ctl_add(mixer->chip->card, kctl);
if (err < 0)
return err;
return 0;
}
static int snd_ftu_create_volume_ctls(struct usb_mixer_interface *mixer)
{
char name[64];
unsigned int control, cmask;
int in, out, err;
const unsigned int id = 5;
const int val_type = USB_MIXER_S16;
for (out = 0; out < 8; out++) {
control = out + 1;
for (in = 0; in < 8; in++) {
cmask = 1 << in;
snprintf(name, sizeof(name),
"AIn%d - Out%d Capture Volume",
in + 1, out + 1);
err = snd_create_std_mono_ctl(mixer, id, control,
cmask, val_type, name,
&snd_usb_mixer_vol_tlv);
if (err < 0)
return err;
}
for (in = 8; in < 16; in++) {
cmask = 1 << in;
snprintf(name, sizeof(name),
"DIn%d - Out%d Playback Volume",
in - 7, out + 1);
err = snd_create_std_mono_ctl(mixer, id, control,
cmask, val_type, name,
&snd_usb_mixer_vol_tlv);
if (err < 0)
return err;
}
}
return 0;
}
static int snd_ftu_create_effect_volume_ctl(struct usb_mixer_interface *mixer)
{
static const char name[] = "Effect Volume";
const unsigned int id = 6;
const int val_type = USB_MIXER_U8;
const unsigned int control = 2;
const unsigned int cmask = 0;
return snd_create_std_mono_ctl(mixer, id, control, cmask, val_type,
name, snd_usb_mixer_vol_tlv);
}
static int snd_ftu_create_effect_duration_ctl(struct usb_mixer_interface *mixer)
{
static const char name[] = "Effect Duration";
const unsigned int id = 6;
const int val_type = USB_MIXER_S16;
const unsigned int control = 3;
const unsigned int cmask = 0;
return snd_create_std_mono_ctl(mixer, id, control, cmask, val_type,
name, snd_usb_mixer_vol_tlv);
}
static int snd_ftu_create_effect_feedback_ctl(struct usb_mixer_interface *mixer)
{
static const char name[] = "Effect Feedback Volume";
const unsigned int id = 6;
const int val_type = USB_MIXER_U8;
const unsigned int control = 4;
const unsigned int cmask = 0;
return snd_create_std_mono_ctl(mixer, id, control, cmask, val_type,
name, NULL);
}
static int snd_ftu_create_effect_return_ctls(struct usb_mixer_interface *mixer)
{
unsigned int cmask;
int err, ch;
char name[48];
const unsigned int id = 7;
const int val_type = USB_MIXER_S16;
const unsigned int control = 7;
for (ch = 0; ch < 4; ++ch) {
cmask = 1 << ch;
snprintf(name, sizeof(name),
"Effect Return %d Volume", ch + 1);
err = snd_create_std_mono_ctl(mixer, id, control,
cmask, val_type, name,
snd_usb_mixer_vol_tlv);
if (err < 0)
return err;
}
return 0;
}
static int snd_ftu_create_effect_send_ctls(struct usb_mixer_interface *mixer)
{
unsigned int cmask;
int err, ch;
char name[48];
const unsigned int id = 5;
const int val_type = USB_MIXER_S16;
const unsigned int control = 9;
for (ch = 0; ch < 8; ++ch) {
cmask = 1 << ch;
snprintf(name, sizeof(name),
"Effect Send AIn%d Volume", ch + 1);
err = snd_create_std_mono_ctl(mixer, id, control, cmask,
val_type, name,
snd_usb_mixer_vol_tlv);
if (err < 0)
return err;
}
for (ch = 8; ch < 16; ++ch) {
cmask = 1 << ch;
snprintf(name, sizeof(name),
"Effect Send DIn%d Volume", ch - 7);
err = snd_create_std_mono_ctl(mixer, id, control, cmask,
val_type, name,
snd_usb_mixer_vol_tlv);
if (err < 0)
return err;
}
return 0;
}
static int snd_ftu_create_mixer(struct usb_mixer_interface *mixer)
{
int err;
err = snd_ftu_create_volume_ctls(mixer);
if (err < 0)
return err;
err = snd_ftu_create_effect_switch(mixer, 1, 6);
if (err < 0)
return err;
err = snd_ftu_create_effect_volume_ctl(mixer);
if (err < 0)
return err;
err = snd_ftu_create_effect_duration_ctl(mixer);
if (err < 0)
return err;
err = snd_ftu_create_effect_feedback_ctl(mixer);
if (err < 0)
return err;
err = snd_ftu_create_effect_return_ctls(mixer);
if (err < 0)
return err;
err = snd_ftu_create_effect_send_ctls(mixer);
if (err < 0)
return err;
return 0;
}
void snd_emuusb_set_samplerate(struct snd_usb_audio *chip,
unsigned char samplerate_id)
{
struct usb_mixer_interface *mixer;
struct usb_mixer_elem_info *cval;
int unitid = 12;
list_for_each_entry(mixer, &chip->mixer_list, list) {
cval = mixer->id_elems[unitid];
if (cval) {
snd_usb_mixer_set_ctl_value(cval, UAC_SET_CUR,
cval->control << 8,
samplerate_id);
snd_usb_mixer_notify_id(mixer, unitid);
}
break;
}
}
static int snd_c400_create_vol_ctls(struct usb_mixer_interface *mixer)
{
char name[64];
unsigned int cmask, offset;
int out, chan, err;
int num_outs = 0;
int num_ins = 0;
const unsigned int id = 0x40;
const int val_type = USB_MIXER_S16;
const int control = 1;
switch (mixer->chip->usb_id) {
case USB_ID(0x0763, 0x2030):
num_outs = 6;
num_ins = 4;
break;
case USB_ID(0x0763, 0x2031):
num_outs = 8;
num_ins = 6;
break;
}
for (chan = 0; chan < num_outs + num_ins; chan++) {
for (out = 0; out < num_outs; out++) {
if (chan < num_outs) {
snprintf(name, sizeof(name),
"PCM%d-Out%d Playback Volume",
chan + 1, out + 1);
} else {
snprintf(name, sizeof(name),
"In%d-Out%d Playback Volume",
chan - num_outs + 1, out + 1);
}
cmask = (out == 0) ? 0 : 1 << (out - 1);
offset = chan * num_outs;
err = snd_create_std_mono_ctl_offset(mixer, id, control,
cmask, val_type, offset, name,
&snd_usb_mixer_vol_tlv);
if (err < 0)
return err;
}
}
return 0;
}
static int snd_c400_create_effect_volume_ctl(struct usb_mixer_interface *mixer)
{
static const char name[] = "Effect Volume";
const unsigned int id = 0x43;
const int val_type = USB_MIXER_U8;
const unsigned int control = 3;
const unsigned int cmask = 0;
return snd_create_std_mono_ctl(mixer, id, control, cmask, val_type,
name, snd_usb_mixer_vol_tlv);
}
static int snd_c400_create_effect_duration_ctl(struct usb_mixer_interface *mixer)
{
static const char name[] = "Effect Duration";
const unsigned int id = 0x43;
const int val_type = USB_MIXER_S16;
const unsigned int control = 4;
const unsigned int cmask = 0;
return snd_create_std_mono_ctl(mixer, id, control, cmask, val_type,
name, snd_usb_mixer_vol_tlv);
}
static int snd_c400_create_effect_feedback_ctl(struct usb_mixer_interface *mixer)
{
static const char name[] = "Effect Feedback Volume";
const unsigned int id = 0x43;
const int val_type = USB_MIXER_U8;
const unsigned int control = 5;
const unsigned int cmask = 0;
return snd_create_std_mono_ctl(mixer, id, control, cmask, val_type,
name, NULL);
}
static int snd_c400_create_effect_vol_ctls(struct usb_mixer_interface *mixer)
{
char name[64];
unsigned int cmask;
int chan, err;
int num_outs = 0;
int num_ins = 0;
const unsigned int id = 0x42;
const int val_type = USB_MIXER_S16;
const int control = 1;
switch (mixer->chip->usb_id) {
case USB_ID(0x0763, 0x2030):
num_outs = 6;
num_ins = 4;
break;
case USB_ID(0x0763, 0x2031):
num_outs = 8;
num_ins = 6;
break;
}
for (chan = 0; chan < num_outs + num_ins; chan++) {
if (chan < num_outs) {
snprintf(name, sizeof(name),
"Effect Send DOut%d",
chan + 1);
} else {
snprintf(name, sizeof(name),
"Effect Send AIn%d",
chan - num_outs + 1);
}
cmask = (chan == 0) ? 0 : 1 << (chan - 1);
err = snd_create_std_mono_ctl(mixer, id, control,
cmask, val_type, name,
&snd_usb_mixer_vol_tlv);
if (err < 0)
return err;
}
return 0;
}
static int snd_c400_create_effect_ret_vol_ctls(struct usb_mixer_interface *mixer)
{
char name[64];
unsigned int cmask;
int chan, err;
int num_outs = 0;
int offset = 0;
const unsigned int id = 0x40;
const int val_type = USB_MIXER_S16;
const int control = 1;
switch (mixer->chip->usb_id) {
case USB_ID(0x0763, 0x2030):
num_outs = 6;
offset = 0x3c;
break;
case USB_ID(0x0763, 0x2031):
num_outs = 8;
offset = 0x70;
break;
}
for (chan = 0; chan < num_outs; chan++) {
snprintf(name, sizeof(name),
"Effect Return %d",
chan + 1);
cmask = (chan == 0) ? 0 :
1 << (chan + (chan % 2) * num_outs - 1);
err = snd_create_std_mono_ctl_offset(mixer, id, control,
cmask, val_type, offset, name,
&snd_usb_mixer_vol_tlv);
if (err < 0)
return err;
}
return 0;
}
static int snd_c400_create_mixer(struct usb_mixer_interface *mixer)
{
int err;
err = snd_c400_create_vol_ctls(mixer);
if (err < 0)
return err;
err = snd_c400_create_effect_vol_ctls(mixer);
if (err < 0)
return err;
err = snd_c400_create_effect_ret_vol_ctls(mixer);
if (err < 0)
return err;
err = snd_ftu_create_effect_switch(mixer, 2, 0x43);
if (err < 0)
return err;
err = snd_c400_create_effect_volume_ctl(mixer);
if (err < 0)
return err;
err = snd_c400_create_effect_duration_ctl(mixer);
if (err < 0)
return err;
err = snd_c400_create_effect_feedback_ctl(mixer);
if (err < 0)
return err;
return 0;
}
static int snd_microii_spdif_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_IEC958;
uinfo->count = 1;
return 0;
}
static int snd_microii_spdif_default_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct usb_mixer_interface *mixer = snd_kcontrol_chip(kcontrol);
int err;
struct usb_interface *iface;
struct usb_host_interface *alts;
unsigned int ep;
unsigned char data[3];
int rate;
ucontrol->value.iec958.status[0] = kcontrol->private_value & 0xff;
ucontrol->value.iec958.status[1] = (kcontrol->private_value >> 8) & 0xff;
ucontrol->value.iec958.status[2] = 0x00;
iface = usb_ifnum_to_if(mixer->chip->dev, 1);
alts = &iface->altsetting[1];
ep = get_endpoint(alts, 0)->bEndpointAddress;
err = snd_usb_ctl_msg(mixer->chip->dev,
usb_rcvctrlpipe(mixer->chip->dev, 0),
UAC_GET_CUR,
USB_TYPE_CLASS | USB_RECIP_ENDPOINT | USB_DIR_IN,
UAC_EP_CS_ATTR_SAMPLE_RATE << 8,
ep,
data,
sizeof(data));
if (err < 0)
goto end;
rate = data[0] | (data[1] << 8) | (data[2] << 16);
ucontrol->value.iec958.status[3] = (rate == 48000) ?
IEC958_AES3_CON_FS_48000 : IEC958_AES3_CON_FS_44100;
err = 0;
end:
return err;
}
static int snd_microii_spdif_default_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct usb_mixer_interface *mixer = snd_kcontrol_chip(kcontrol);
int err;
u8 reg;
unsigned long priv_backup = kcontrol->private_value;
reg = ((ucontrol->value.iec958.status[1] & 0x0f) << 4) |
(ucontrol->value.iec958.status[0] & 0x0f);
err = snd_usb_ctl_msg(mixer->chip->dev,
usb_sndctrlpipe(mixer->chip->dev, 0),
UAC_SET_CUR,
USB_DIR_OUT | USB_TYPE_VENDOR | USB_RECIP_OTHER,
reg,
2,
NULL,
0);
if (err < 0)
goto end;
kcontrol->private_value &= 0xfffff0f0;
kcontrol->private_value |= (ucontrol->value.iec958.status[1] & 0x0f) << 8;
kcontrol->private_value |= (ucontrol->value.iec958.status[0] & 0x0f);
reg = (ucontrol->value.iec958.status[0] & IEC958_AES0_NONAUDIO) ?
0xa0 : 0x20;
reg |= (ucontrol->value.iec958.status[1] >> 4) & 0x0f;
err = snd_usb_ctl_msg(mixer->chip->dev,
usb_sndctrlpipe(mixer->chip->dev, 0),
UAC_SET_CUR,
USB_DIR_OUT | USB_TYPE_VENDOR | USB_RECIP_OTHER,
reg,
3,
NULL,
0);
if (err < 0)
goto end;
kcontrol->private_value &= 0xffff0fff;
kcontrol->private_value |= (ucontrol->value.iec958.status[1] & 0xf0) << 8;
err = (priv_backup != kcontrol->private_value);
end:
return err;
}
static int snd_microii_spdif_mask_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
ucontrol->value.iec958.status[0] = 0x0f;
ucontrol->value.iec958.status[1] = 0xff;
ucontrol->value.iec958.status[2] = 0x00;
ucontrol->value.iec958.status[3] = 0x00;
return 0;
}
static int snd_microii_spdif_switch_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
ucontrol->value.integer.value[0] = !(kcontrol->private_value & 0x02);
return 0;
}
static int snd_microii_spdif_switch_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct usb_mixer_interface *mixer = snd_kcontrol_chip(kcontrol);
int err;
u8 reg = ucontrol->value.integer.value[0] ? 0x28 : 0x2a;
err = snd_usb_ctl_msg(mixer->chip->dev,
usb_sndctrlpipe(mixer->chip->dev, 0),
UAC_SET_CUR,
USB_DIR_OUT | USB_TYPE_VENDOR | USB_RECIP_OTHER,
reg,
9,
NULL,
0);
if (!err) {
err = (reg != (kcontrol->private_value & 0x0ff));
if (err)
kcontrol->private_value = reg;
}
return err;
}
static int snd_microii_controls_create(struct usb_mixer_interface *mixer)
{
int err, i;
for (i = 0; i < ARRAY_SIZE(snd_microii_mixer_spdif); ++i) {
err = snd_ctl_add(mixer->chip->card,
snd_ctl_new1(&snd_microii_mixer_spdif[i], mixer));
if (err < 0)
return err;
}
return err;
}
int snd_usb_mixer_apply_create_quirk(struct usb_mixer_interface *mixer)
{
int err = 0;
struct snd_info_entry *entry;
if ((err = snd_usb_soundblaster_remote_init(mixer)) < 0)
return err;
switch (mixer->chip->usb_id) {
case USB_ID(0x041e, 0x3020):
case USB_ID(0x041e, 0x3040):
case USB_ID(0x041e, 0x3042):
case USB_ID(0x041e, 0x30df):
case USB_ID(0x041e, 0x3048):
err = snd_audigy2nx_controls_create(mixer);
if (err < 0)
break;
if (!snd_card_proc_new(mixer->chip->card, "audigy2nx", &entry))
snd_info_set_text_ops(entry, mixer,
snd_audigy2nx_proc_read);
break;
case USB_ID(0x0763, 0x2030):
case USB_ID(0x0763, 0x2031):
err = snd_c400_create_mixer(mixer);
break;
case USB_ID(0x0763, 0x2080):
case USB_ID(0x0763, 0x2081):
err = snd_ftu_create_mixer(mixer);
break;
case USB_ID(0x0b05, 0x1739):
case USB_ID(0x0b05, 0x1743):
case USB_ID(0x0b05, 0x17a0):
err = snd_xonar_u1_controls_create(mixer);
break;
case USB_ID(0x0d8c, 0x0103):
err = snd_microii_controls_create(mixer);
break;
case USB_ID(0x17cc, 0x1011):
err = snd_nativeinstruments_create_mixer(mixer,
snd_nativeinstruments_ta6_mixers,
ARRAY_SIZE(snd_nativeinstruments_ta6_mixers));
break;
case USB_ID(0x17cc, 0x1021):
err = snd_nativeinstruments_create_mixer(mixer,
snd_nativeinstruments_ta10_mixers,
ARRAY_SIZE(snd_nativeinstruments_ta10_mixers));
break;
case USB_ID(0x200c, 0x1018):
err = snd_create_std_mono_table(mixer, ebox44_table);
break;
}
return err;
}
void snd_usb_mixer_rc_memory_change(struct usb_mixer_interface *mixer,
int unitid)
{
if (!mixer->rc_cfg)
return;
switch (unitid) {
case 0:
mixer->rc_urb->dev = mixer->chip->dev;
usb_submit_urb(mixer->rc_urb, GFP_ATOMIC);
break;
case 4:
case 7:
case 19:
case 20:
break;
case 3:
if (mixer->chip->usb_id == USB_ID(0x041e, 0x3040) ||
mixer->chip->usb_id == USB_ID(0x041e, 0x3048))
snd_usb_mixer_notify_id(mixer, mixer->rc_cfg->mute_mixer_id);
break;
default:
snd_printd(KERN_DEBUG "memory change in unknown unit %d\n", unitid);
break;
}
}
