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
if (mixer->chip->usb_id == USB_ID(0x041e, 0x3042))
err = snd_usb_ctl_msg(mixer->chip->dev,
usb_sndctrlpipe(mixer->chip->dev, 0), 0x24,
USB_DIR_OUT | USB_TYPE_VENDOR | USB_RECIP_OTHER,
!value, 0, NULL, 0, 100);
if (mixer->chip->usb_id == USB_ID(0x041e, 0x30df))
err = snd_usb_ctl_msg(mixer->chip->dev,
usb_sndctrlpipe(mixer->chip->dev, 0), 0x24,
USB_DIR_OUT | USB_TYPE_VENDOR | USB_RECIP_OTHER,
!value, 0, NULL, 0, 100);
else
err = snd_usb_ctl_msg(mixer->chip->dev,
usb_sndctrlpipe(mixer->chip->dev, 0), 0x24,
USB_DIR_OUT | USB_TYPE_VENDOR | USB_RECIP_OTHER,
value, index + 2, NULL, 0, 100);
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
err = snd_usb_ctl_msg(mixer->chip->dev,
usb_rcvctrlpipe(mixer->chip->dev, 0),
UAC_GET_MEM, USB_DIR_IN | USB_TYPE_CLASS |
USB_RECIP_INTERFACE, 0,
jacks[i].unitid << 8, buf, 3, 100);
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
err = snd_usb_ctl_msg(mixer->chip->dev,
usb_sndctrlpipe(mixer->chip->dev, 0), 0x08,
USB_DIR_OUT | USB_TYPE_VENDOR | USB_RECIP_OTHER,
50, 0, &new_status, 1, 100);
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
int ret = usb_control_msg(dev, usb_rcvctrlpipe(dev, 0), bRequest,
USB_TYPE_VENDOR | USB_RECIP_DEVICE | USB_DIR_IN,
0, cpu_to_le16(wIndex),
&tmp, sizeof(tmp), 1000);
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
int ret = usb_control_msg(dev, usb_sndctrlpipe(dev, 0), bRequest,
USB_TYPE_VENDOR | USB_RECIP_DEVICE | USB_DIR_OUT,
cpu_to_le16(wValue), cpu_to_le16(wIndex),
NULL, 0, 1000);
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
static void usb_mixer_elem_free(struct snd_kcontrol *kctl)
{
kfree(kctl->private_data);
kctl->private_data = NULL;
}
static int snd_maudio_ftu_create_ctl(struct usb_mixer_interface *mixer,
int in, int out, const char *name)
{
struct usb_mixer_elem_info *cval;
struct snd_kcontrol *kctl;
cval = kzalloc(sizeof(*cval), GFP_KERNEL);
if (!cval)
return -ENOMEM;
cval->id = 5;
cval->mixer = mixer;
cval->val_type = USB_MIXER_S16;
cval->channels = 1;
cval->control = out + 1;
cval->cmask = 1 << in;
kctl = snd_ctl_new1(snd_usb_feature_unit_ctl, cval);
if (!kctl) {
kfree(cval);
return -ENOMEM;
}
snprintf(kctl->id.name, sizeof(kctl->id.name), name);
kctl->private_free = usb_mixer_elem_free;
return snd_usb_mixer_add_control(mixer, kctl);
}
static int snd_maudio_ftu_create_mixer(struct usb_mixer_interface *mixer)
{
char name[64];
int in, out, err;
for (out = 0; out < 8; out++) {
for (in = 0; in < 8; in++) {
snprintf(name, sizeof(name),
"AIn%d - Out%d Capture Volume", in + 1, out + 1);
err = snd_maudio_ftu_create_ctl(mixer, in, out, name);
if (err < 0)
return err;
}
for (in = 8; in < 16; in++) {
snprintf(name, sizeof(name),
"DIn%d - Out%d Playback Volume", in - 7, out + 1);
err = snd_maudio_ftu_create_ctl(mixer, in, out, name);
if (err < 0)
return err;
}
}
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
case USB_ID(0x0763, 0x2080):
case USB_ID(0x0763, 0x2081):
err = snd_maudio_ftu_create_mixer(mixer);
break;
case USB_ID(0x0b05, 0x1739):
case USB_ID(0x0b05, 0x1743):
err = snd_xonar_u1_controls_create(mixer);
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
