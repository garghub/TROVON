static int scarlett_ctl_switch_info(struct snd_kcontrol *kctl,
struct snd_ctl_elem_info *uinfo)
{
struct usb_mixer_elem_info *elem = kctl->private_data;
uinfo->type = SNDRV_CTL_ELEM_TYPE_BOOLEAN;
uinfo->count = elem->channels;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = 1;
return 0;
}
static int scarlett_ctl_switch_get(struct snd_kcontrol *kctl,
struct snd_ctl_elem_value *ucontrol)
{
struct usb_mixer_elem_info *elem = kctl->private_data;
int i, err, val;
for (i = 0; i < elem->channels; i++) {
err = snd_usb_get_cur_mix_value(elem, i, i, &val);
if (err < 0)
return err;
val = !val;
ucontrol->value.integer.value[i] = val;
}
return 0;
}
static int scarlett_ctl_switch_put(struct snd_kcontrol *kctl,
struct snd_ctl_elem_value *ucontrol)
{
struct usb_mixer_elem_info *elem = kctl->private_data;
int i, changed = 0;
int err, oval, val;
for (i = 0; i < elem->channels; i++) {
err = snd_usb_get_cur_mix_value(elem, i, i, &oval);
if (err < 0)
return err;
val = ucontrol->value.integer.value[i];
val = !val;
if (oval != val) {
err = snd_usb_set_cur_mix_value(elem, i, i, val);
if (err < 0)
return err;
changed = 1;
}
}
return changed;
}
static int scarlett_ctl_resume(struct usb_mixer_elem_list *list)
{
struct usb_mixer_elem_info *elem =
container_of(list, struct usb_mixer_elem_info, head);
int i;
for (i = 0; i < elem->channels; i++)
if (elem->cached & (1 << i))
snd_usb_set_cur_mix_value(elem, i, i,
elem->cache_val[i]);
return 0;
}
static int scarlett_ctl_info(struct snd_kcontrol *kctl,
struct snd_ctl_elem_info *uinfo)
{
struct usb_mixer_elem_info *elem = kctl->private_data;
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = elem->channels;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = (int)kctl->private_value +
SND_SCARLETT_LEVEL_BIAS;
uinfo->value.integer.step = 1;
return 0;
}
static int scarlett_ctl_get(struct snd_kcontrol *kctl,
struct snd_ctl_elem_value *ucontrol)
{
struct usb_mixer_elem_info *elem = kctl->private_data;
int i, err, val;
for (i = 0; i < elem->channels; i++) {
err = snd_usb_get_cur_mix_value(elem, i, i, &val);
if (err < 0)
return err;
val = clamp(val / 256, -128, (int)kctl->private_value) +
SND_SCARLETT_LEVEL_BIAS;
ucontrol->value.integer.value[i] = val;
}
return 0;
}
static int scarlett_ctl_put(struct snd_kcontrol *kctl,
struct snd_ctl_elem_value *ucontrol)
{
struct usb_mixer_elem_info *elem = kctl->private_data;
int i, changed = 0;
int err, oval, val;
for (i = 0; i < elem->channels; i++) {
err = snd_usb_get_cur_mix_value(elem, i, i, &oval);
if (err < 0)
return err;
val = ucontrol->value.integer.value[i] -
SND_SCARLETT_LEVEL_BIAS;
val = val * 256;
if (oval != val) {
err = snd_usb_set_cur_mix_value(elem, i, i, val);
if (err < 0)
return err;
changed = 1;
}
}
return changed;
}
static void scarlett_generate_name(int i, char *dst, int offsets[])
{
if (i > offsets[SCARLETT_OFFSET_MIX])
sprintf(dst, "Mix %c",
'A'+(i - offsets[SCARLETT_OFFSET_MIX] - 1));
else if (i > offsets[SCARLETT_OFFSET_ADAT])
sprintf(dst, "ADAT %d", i - offsets[SCARLETT_OFFSET_ADAT]);
else if (i > offsets[SCARLETT_OFFSET_SPDIF])
sprintf(dst, "SPDIF %d", i - offsets[SCARLETT_OFFSET_SPDIF]);
else if (i > offsets[SCARLETT_OFFSET_ANALOG])
sprintf(dst, "Analog %d", i - offsets[SCARLETT_OFFSET_ANALOG]);
else if (i > offsets[SCARLETT_OFFSET_PCM])
sprintf(dst, "PCM %d", i - offsets[SCARLETT_OFFSET_PCM]);
else
sprintf(dst, "Off");
}
static int scarlett_ctl_enum_dynamic_info(struct snd_kcontrol *kctl,
struct snd_ctl_elem_info *uinfo)
{
struct usb_mixer_elem_info *elem = kctl->private_data;
struct scarlett_mixer_elem_enum_info *opt = elem->private_data;
unsigned int items = opt->len;
uinfo->type = SNDRV_CTL_ELEM_TYPE_ENUMERATED;
uinfo->count = elem->channels;
uinfo->value.enumerated.items = items;
if (uinfo->value.enumerated.item >= items)
uinfo->value.enumerated.item = items - 1;
scarlett_generate_name(uinfo->value.enumerated.item,
uinfo->value.enumerated.name,
opt->offsets);
return 0;
}
static int scarlett_ctl_enum_info(struct snd_kcontrol *kctl,
struct snd_ctl_elem_info *uinfo)
{
struct usb_mixer_elem_info *elem = kctl->private_data;
struct scarlett_mixer_elem_enum_info *opt = elem->private_data;
return snd_ctl_enum_info(uinfo, elem->channels, opt->len,
(const char * const *)opt->names);
}
static int scarlett_ctl_enum_get(struct snd_kcontrol *kctl,
struct snd_ctl_elem_value *ucontrol)
{
struct usb_mixer_elem_info *elem = kctl->private_data;
struct scarlett_mixer_elem_enum_info *opt = elem->private_data;
int err, val;
err = snd_usb_get_cur_mix_value(elem, 0, 0, &val);
if (err < 0)
return err;
val = clamp(val - opt->start, 0, opt->len-1);
ucontrol->value.enumerated.item[0] = val;
return 0;
}
static int scarlett_ctl_enum_put(struct snd_kcontrol *kctl,
struct snd_ctl_elem_value *ucontrol)
{
struct usb_mixer_elem_info *elem = kctl->private_data;
struct scarlett_mixer_elem_enum_info *opt = elem->private_data;
int err, oval, val;
err = snd_usb_get_cur_mix_value(elem, 0, 0, &oval);
if (err < 0)
return err;
val = ucontrol->value.integer.value[0];
val = val + opt->start;
if (val != oval) {
snd_usb_set_cur_mix_value(elem, 0, 0, val);
return 1;
}
return 0;
}
static int scarlett_ctl_enum_resume(struct usb_mixer_elem_list *list)
{
struct usb_mixer_elem_info *elem =
container_of(list, struct usb_mixer_elem_info, head);
if (elem->cached)
snd_usb_set_cur_mix_value(elem, 0, 0, *elem->cache_val);
return 0;
}
static int scarlett_ctl_meter_get(struct snd_kcontrol *kctl,
struct snd_ctl_elem_value *ucontrol)
{
struct usb_mixer_elem_info *elem = kctl->private_data;
struct snd_usb_audio *chip = elem->head.mixer->chip;
unsigned char buf[2 * MAX_CHANNELS] = {0, };
int wValue = (elem->control << 8) | elem->idx_off;
int idx = snd_usb_ctrl_intf(chip) | (elem->head.id << 8);
int err;
err = snd_usb_ctl_msg(chip->dev,
usb_rcvctrlpipe(chip->dev, 0),
UAC2_CS_MEM,
USB_RECIP_INTERFACE | USB_TYPE_CLASS |
USB_DIR_IN, wValue, idx, buf, elem->channels);
if (err < 0)
return err;
ucontrol->value.enumerated.item[0] = clamp((int)buf[0], 0, 1);
return 0;
}
static int add_new_ctl(struct usb_mixer_interface *mixer,
const struct snd_kcontrol_new *ncontrol,
usb_mixer_elem_resume_func_t resume,
int index, int offset, int num,
int val_type, int channels, const char *name,
const struct scarlett_mixer_elem_enum_info *opt,
struct usb_mixer_elem_info **elem_ret
)
{
struct snd_kcontrol *kctl;
struct usb_mixer_elem_info *elem;
int err;
elem = kzalloc(sizeof(*elem), GFP_KERNEL);
if (!elem)
return -ENOMEM;
elem->head.mixer = mixer;
elem->head.resume = resume;
elem->control = offset;
elem->idx_off = num;
elem->head.id = index;
elem->val_type = val_type;
elem->channels = channels;
elem->private_data = (void *)opt;
kctl = snd_ctl_new1(ncontrol, elem);
if (!kctl) {
kfree(elem);
return -ENOMEM;
}
kctl->private_free = snd_usb_mixer_elem_free;
strlcpy(kctl->id.name, name, sizeof(kctl->id.name));
err = snd_usb_mixer_add_control(&elem->head, kctl);
if (err < 0)
return err;
if (elem_ret)
*elem_ret = elem;
return 0;
}
static int add_output_ctls(struct usb_mixer_interface *mixer,
int index, const char *name,
const struct scarlett_device_info *info)
{
int err;
char mx[SNDRV_CTL_ELEM_ID_NAME_MAXLEN];
struct usb_mixer_elem_info *elem;
snprintf(mx, sizeof(mx), "Master %d (%s) Playback Switch",
index + 1, name);
err = add_new_ctl(mixer, &usb_scarlett_ctl_switch,
scarlett_ctl_resume, 0x0a, 0x01,
2*index+1, USB_MIXER_S16, 2, mx, NULL, &elem);
if (err < 0)
return err;
snprintf(mx, sizeof(mx), "Master %d (%s) Playback Volume",
index + 1, name);
err = add_new_ctl(mixer, &usb_scarlett_ctl_master,
scarlett_ctl_resume, 0x0a, 0x02,
2*index+1, USB_MIXER_S16, 2, mx, NULL, &elem);
if (err < 0)
return err;
snprintf(mx, sizeof(mx), "Master %dL (%s) Source Playback Enum",
index + 1, name);
err = add_new_ctl(mixer, &usb_scarlett_ctl_dynamic_enum,
scarlett_ctl_enum_resume, 0x33, 0x00,
2*index, USB_MIXER_S16, 1, mx, &info->opt_master,
&elem);
if (err < 0)
return err;
snprintf(mx, sizeof(mx), "Master %dR (%s) Source Playback Enum",
index + 1, name);
err = add_new_ctl(mixer, &usb_scarlett_ctl_dynamic_enum,
scarlett_ctl_enum_resume, 0x33, 0x00,
2*index+1, USB_MIXER_S16, 1, mx, &info->opt_master,
&elem);
if (err < 0)
return err;
return 0;
}
static int scarlett_controls_create_generic(struct usb_mixer_interface *mixer,
struct scarlett_device_info *info)
{
int i, err;
char mx[SNDRV_CTL_ELEM_ID_NAME_MAXLEN];
const struct scarlett_mixer_control *ctl;
struct usb_mixer_elem_info *elem;
err = add_new_ctl(mixer, &usb_scarlett_ctl_switch,
scarlett_ctl_resume, 0x0a, 0x01, 0,
USB_MIXER_S16, 1, "Master Playback Switch", NULL,
&elem);
if (err < 0)
return err;
err = add_new_ctl(mixer, &usb_scarlett_ctl_master,
scarlett_ctl_resume, 0x0a, 0x02, 0,
USB_MIXER_S16, 1, "Master Playback Volume", NULL,
&elem);
if (err < 0)
return err;
for (i = 0; i < info->num_controls; i++) {
ctl = &info->controls[i];
switch (ctl->type) {
case SCARLETT_OUTPUTS:
err = add_output_ctls(mixer, ctl->num, ctl->name, info);
if (err < 0)
return err;
break;
case SCARLETT_SWITCH_IMPEDANCE:
sprintf(mx, "Input %d Impedance Switch", ctl->num);
err = add_new_ctl(mixer, &usb_scarlett_ctl_enum,
scarlett_ctl_enum_resume, 0x01,
0x09, ctl->num, USB_MIXER_S16, 1, mx,
&opt_impedance, &elem);
if (err < 0)
return err;
break;
case SCARLETT_SWITCH_PAD:
sprintf(mx, "Input %d Pad Switch", ctl->num);
err = add_new_ctl(mixer, &usb_scarlett_ctl_enum,
scarlett_ctl_enum_resume, 0x01,
0x0b, ctl->num, USB_MIXER_S16, 1, mx,
&opt_pad, &elem);
if (err < 0)
return err;
break;
}
}
return 0;
}
int snd_scarlett_controls_create(struct usb_mixer_interface *mixer)
{
int err, i, o;
char mx[SNDRV_CTL_ELEM_ID_NAME_MAXLEN];
struct scarlett_device_info *info;
struct usb_mixer_elem_info *elem;
static char sample_rate_buffer[4] = { '\x80', '\xbb', '\x00', '\x00' };
if (!mixer->protocol)
return 0;
switch (mixer->chip->usb_id) {
case USB_ID(0x1235, 0x8012):
info = &s6i6_info;
break;
case USB_ID(0x1235, 0x8002):
info = &s8i6_info;
break;
case USB_ID(0x1235, 0x8004):
info = &s18i6_info;
break;
case USB_ID(0x1235, 0x8014):
info = &s18i8_info;
break;
case USB_ID(0x1235, 0x800c):
info = &s18i20_info;
break;
default:
return -EINVAL;
}
err = scarlett_controls_create_generic(mixer, info);
if (err < 0)
return err;
for (i = 0; i < info->matrix_in; i++) {
snprintf(mx, sizeof(mx), "Matrix %02d Input Playback Route",
i+1);
err = add_new_ctl(mixer, &usb_scarlett_ctl_dynamic_enum,
scarlett_ctl_enum_resume, 0x32,
0x06, i, USB_MIXER_S16, 1, mx,
&info->opt_matrix, &elem);
if (err < 0)
return err;
for (o = 0; o < info->matrix_out; o++) {
sprintf(mx, "Matrix %02d Mix %c Playback Volume", i+1,
o+'A');
err = add_new_ctl(mixer, &usb_scarlett_ctl,
scarlett_ctl_resume, 0x3c, 0x00,
(i << 3) + (o & 0x07), USB_MIXER_S16,
1, mx, NULL, &elem);
if (err < 0)
return err;
}
}
for (i = 0; i < info->input_len; i++) {
snprintf(mx, sizeof(mx), "Input Source %02d Capture Route",
i+1);
err = add_new_ctl(mixer, &usb_scarlett_ctl_dynamic_enum,
scarlett_ctl_enum_resume, 0x34,
0x00, i, USB_MIXER_S16, 1, mx,
&info->opt_master, &elem);
if (err < 0)
return err;
}
err = add_new_ctl(mixer, &usb_scarlett_ctl_enum,
scarlett_ctl_enum_resume, 0x28, 0x01, 0,
USB_MIXER_U8, 1, "Sample Clock Source",
&opt_clock, &elem);
if (err < 0)
return err;
err = add_new_ctl(mixer, &usb_scarlett_ctl_sync, NULL, 0x3c, 0x00, 2,
USB_MIXER_U8, 1, "Sample Clock Sync Status",
&opt_sync, &elem);
if (err < 0)
return err;
err = snd_usb_ctl_msg(mixer->chip->dev,
usb_sndctrlpipe(mixer->chip->dev, 0), UAC2_CS_CUR,
USB_RECIP_INTERFACE | USB_TYPE_CLASS |
USB_DIR_OUT, 0x0100, snd_usb_ctrl_intf(mixer->chip) |
(0x29 << 8), sample_rate_buffer, 4);
if (err < 0)
return err;
return err;
}
