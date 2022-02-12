static struct via_spec * via_new_spec(struct hda_codec *codec)
{
struct via_spec *spec;
spec = kzalloc(sizeof(*spec), GFP_KERNEL);
if (spec == NULL)
return NULL;
codec->spec = spec;
spec->codec = codec;
spec->codec_type = get_codec_type(codec);
if (spec->codec_type == VT1708BCE)
spec->codec_type = VT1708S;
return spec;
}
static enum VIA_HDA_CODEC get_codec_type(struct hda_codec *codec)
{
u32 vendor_id = codec->vendor_id;
u16 ven_id = vendor_id >> 16;
u16 dev_id = vendor_id & 0xffff;
enum VIA_HDA_CODEC codec_type;
if (ven_id != 0x1106)
codec_type = UNKNOWN;
else if (dev_id >= 0x1708 && dev_id <= 0x170b)
codec_type = VT1708;
else if (dev_id >= 0xe710 && dev_id <= 0xe713)
codec_type = VT1709_10CH;
else if (dev_id >= 0xe714 && dev_id <= 0xe717)
codec_type = VT1709_6CH;
else if (dev_id >= 0xe720 && dev_id <= 0xe723) {
codec_type = VT1708B_8CH;
if (snd_hda_param_read(codec, 0x16, AC_PAR_CONNLIST_LEN) == 0x7)
codec_type = VT1708BCE;
} else if (dev_id >= 0xe724 && dev_id <= 0xe727)
codec_type = VT1708B_4CH;
else if ((dev_id & 0xfff) == 0x397
&& (dev_id >> 12) < 8)
codec_type = VT1708S;
else if ((dev_id & 0xfff) == 0x398
&& (dev_id >> 12) < 8)
codec_type = VT1702;
else if ((dev_id & 0xfff) == 0x428
&& (dev_id >> 12) < 8)
codec_type = VT1718S;
else if (dev_id == 0x0433 || dev_id == 0xa721)
codec_type = VT1716S;
else if (dev_id == 0x0441 || dev_id == 0x4441)
codec_type = VT1718S;
else if (dev_id == 0x0438 || dev_id == 0x4438)
codec_type = VT2002P;
else if (dev_id == 0x0448)
codec_type = VT1812;
else if (dev_id == 0x0440)
codec_type = VT1708S;
else if ((dev_id & 0xfff) == 0x446)
codec_type = VT1802;
else
codec_type = UNKNOWN;
return codec_type;
}
static void vt1708_start_hp_work(struct via_spec *spec)
{
if (spec->codec_type != VT1708 || spec->autocfg.hp_pins[0] == 0)
return;
snd_hda_codec_write(spec->codec, 0x1, 0, 0xf81,
!spec->vt1708_jack_detectect);
if (!delayed_work_pending(&spec->vt1708_hp_work))
schedule_delayed_work(&spec->vt1708_hp_work,
msecs_to_jiffies(100));
}
static void vt1708_stop_hp_work(struct via_spec *spec)
{
if (spec->codec_type != VT1708 || spec->autocfg.hp_pins[0] == 0)
return;
if (snd_hda_get_bool_hint(spec->codec, "analog_loopback_hp_detect") == 1
&& !is_aa_path_mute(spec->codec))
return;
snd_hda_codec_write(spec->codec, 0x1, 0, 0xf81,
!spec->vt1708_jack_detectect);
cancel_delayed_work_sync(&spec->vt1708_hp_work);
}
static void set_widgets_power_state(struct hda_codec *codec)
{
struct via_spec *spec = codec->spec;
if (spec->set_widgets_power_state)
spec->set_widgets_power_state(codec);
}
static int analog_input_switch_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
int change = snd_hda_mixer_amp_switch_put(kcontrol, ucontrol);
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
set_widgets_power_state(codec);
analog_low_current_mode(snd_kcontrol_chip(kcontrol), -1);
if (snd_hda_get_bool_hint(codec, "analog_loopback_hp_detect") == 1) {
if (is_aa_path_mute(codec))
vt1708_start_hp_work(codec->spec);
else
vt1708_stop_hp_work(codec->spec);
}
return change;
}
static int bind_pin_switch_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct via_spec *spec = codec->spec;
int i;
int change = 0;
long *valp = ucontrol->value.integer.value;
int lmute, rmute;
if (strstr(kcontrol->id.name, "Switch") == NULL) {
snd_printd("Invalid control!\n");
return change;
}
change = snd_hda_mixer_amp_switch_put(kcontrol,
ucontrol);
lmute = *valp ? 0 : HDA_AMP_MUTE;
valp++;
rmute = *valp ? 0 : HDA_AMP_MUTE;
if (!spec->hp_independent_mode) {
for (i = 0; i < spec->autocfg.hp_outs; i++) {
snd_hda_codec_amp_update(
codec, spec->autocfg.hp_pins[i],
0, HDA_OUTPUT, 0, HDA_AMP_MUTE,
lmute);
snd_hda_codec_amp_update(
codec, spec->autocfg.hp_pins[i],
1, HDA_OUTPUT, 0, HDA_AMP_MUTE,
rmute);
}
}
if (!lmute && !rmute) {
for (i = 0; i < spec->autocfg.line_outs; i++)
snd_hda_codec_amp_stereo(
codec, spec->autocfg.line_out_pins[i],
HDA_OUTPUT, 0, HDA_AMP_MUTE, 0);
for (i = 0; i < spec->autocfg.speaker_outs; i++)
snd_hda_codec_amp_stereo(
codec, spec->autocfg.speaker_pins[i],
HDA_OUTPUT, 0, HDA_AMP_MUTE, 0);
via_hp_bind_automute(codec);
} else {
if (lmute) {
for (i = 1; i < spec->autocfg.line_outs; i++)
snd_hda_codec_amp_update(
codec,
spec->autocfg.line_out_pins[i],
0, HDA_OUTPUT, 0, HDA_AMP_MUTE,
lmute);
for (i = 0; i < spec->autocfg.speaker_outs; i++)
snd_hda_codec_amp_update(
codec,
spec->autocfg.speaker_pins[i],
0, HDA_OUTPUT, 0, HDA_AMP_MUTE,
lmute);
}
if (rmute) {
for (i = 1; i < spec->autocfg.line_outs; i++)
snd_hda_codec_amp_update(
codec,
spec->autocfg.line_out_pins[i],
1, HDA_OUTPUT, 0, HDA_AMP_MUTE,
rmute);
for (i = 0; i < spec->autocfg.speaker_outs; i++)
snd_hda_codec_amp_update(
codec,
spec->autocfg.speaker_pins[i],
1, HDA_OUTPUT, 0, HDA_AMP_MUTE,
rmute);
}
}
return change;
}
static int __via_add_control(struct via_spec *spec, int type, const char *name,
int idx, unsigned long val)
{
struct snd_kcontrol_new *knew;
snd_array_init(&spec->kctls, sizeof(*knew), 32);
knew = snd_array_new(&spec->kctls);
if (!knew)
return -ENOMEM;
*knew = via_control_templates[type];
knew->name = kstrdup(name, GFP_KERNEL);
if (!knew->name)
return -ENOMEM;
if (get_amp_nid_(val))
knew->subdevice = HDA_SUBDEV_AMP_FLAG;
knew->private_value = val;
return 0;
}
static struct snd_kcontrol_new *via_clone_control(struct via_spec *spec,
const struct snd_kcontrol_new *tmpl)
{
struct snd_kcontrol_new *knew;
snd_array_init(&spec->kctls, sizeof(*knew), 32);
knew = snd_array_new(&spec->kctls);
if (!knew)
return NULL;
*knew = *tmpl;
knew->name = kstrdup(tmpl->name, GFP_KERNEL);
if (!knew->name)
return NULL;
return knew;
}
static void via_free_kctls(struct hda_codec *codec)
{
struct via_spec *spec = codec->spec;
if (spec->kctls.list) {
struct snd_kcontrol_new *kctl = spec->kctls.list;
int i;
for (i = 0; i < spec->kctls.used; i++)
kfree(kctl[i].name);
}
snd_array_free(&spec->kctls);
}
static int via_new_analog_input(struct via_spec *spec, const char *ctlname,
int type_idx, int idx, int mix_nid)
{
char name[32];
int err;
sprintf(name, "%s Playback Volume", ctlname);
err = __via_add_control(spec, VIA_CTL_WIDGET_VOL, name, type_idx,
HDA_COMPOSE_AMP_VAL(mix_nid, 3, idx, HDA_INPUT));
if (err < 0)
return err;
sprintf(name, "%s Playback Switch", ctlname);
err = __via_add_control(spec, VIA_CTL_WIDGET_ANALOG_MUTE, name, type_idx,
HDA_COMPOSE_AMP_VAL(mix_nid, 3, idx, HDA_INPUT));
if (err < 0)
return err;
return 0;
}
static void via_auto_set_output_and_unmute(struct hda_codec *codec,
hda_nid_t nid, int pin_type,
int dac_idx)
{
snd_hda_codec_write(codec, nid, 0, AC_VERB_SET_PIN_WIDGET_CONTROL,
pin_type);
snd_hda_codec_write(codec, nid, 0, AC_VERB_SET_AMP_GAIN_MUTE,
AMP_OUT_UNMUTE);
if (snd_hda_query_pin_caps(codec, nid) & AC_PINCAP_EAPD)
snd_hda_codec_write(codec, nid, 0,
AC_VERB_SET_EAPD_BTLENABLE, 0x02);
}
static void via_auto_init_multi_out(struct hda_codec *codec)
{
struct via_spec *spec = codec->spec;
int i;
for (i = 0; i <= AUTO_SEQ_SIDE; i++) {
hda_nid_t nid = spec->autocfg.line_out_pins[i];
if (nid)
via_auto_set_output_and_unmute(codec, nid, PIN_OUT, i);
}
}
static void via_auto_init_hp_out(struct hda_codec *codec)
{
struct via_spec *spec = codec->spec;
hda_nid_t pin;
int i;
for (i = 0; i < spec->autocfg.hp_outs; i++) {
pin = spec->autocfg.hp_pins[i];
if (pin)
via_auto_set_output_and_unmute(codec, pin, PIN_HP, 0);
}
}
static void via_auto_init_analog_input(struct hda_codec *codec)
{
struct via_spec *spec = codec->spec;
const struct auto_pin_cfg *cfg = &spec->autocfg;
unsigned int ctl;
int i;
for (i = 0; i < cfg->num_inputs; i++) {
hda_nid_t nid = cfg->inputs[i].pin;
if (spec->smart51_enabled && is_smart51_pins(spec, nid))
ctl = PIN_OUT;
else if (cfg->inputs[i].type == AUTO_PIN_MIC)
ctl = PIN_VREF50;
else
ctl = PIN_IN;
snd_hda_codec_write(codec, nid, 0,
AC_VERB_SET_PIN_WIDGET_CONTROL, ctl);
}
}
static void set_pin_power_state(struct hda_codec *codec, hda_nid_t nid,
unsigned int *affected_parm)
{
unsigned parm;
unsigned def_conf = snd_hda_codec_get_pincfg(codec, nid);
unsigned no_presence = (def_conf & AC_DEFCFG_MISC)
>> AC_DEFCFG_MISC_SHIFT
& AC_DEFCFG_MISC_NO_PRESENCE;
unsigned present = snd_hda_jack_detect(codec, nid);
struct via_spec *spec = codec->spec;
if ((spec->smart51_enabled && is_smart51_pins(spec, nid))
|| ((no_presence || present)
&& get_defcfg_connect(def_conf) != AC_JACK_PORT_NONE)) {
*affected_parm = AC_PWRST_D0;
parm = AC_PWRST_D0;
} else
parm = AC_PWRST_D3;
snd_hda_codec_write(codec, nid, 0, AC_VERB_SET_POWER_STATE, parm);
}
static int via_mux_enum_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct via_spec *spec = codec->spec;
return snd_hda_input_mux_info(spec->input_mux, uinfo);
}
static int via_mux_enum_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct via_spec *spec = codec->spec;
unsigned int adc_idx = snd_ctl_get_ioffidx(kcontrol, &ucontrol->id);
ucontrol->value.enumerated.item[0] = spec->cur_mux[adc_idx];
return 0;
}
static int via_mux_enum_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct via_spec *spec = codec->spec;
unsigned int adc_idx = snd_ctl_get_ioffidx(kcontrol, &ucontrol->id);
int ret;
if (!spec->mux_nids[adc_idx])
return -EINVAL;
if (snd_hda_codec_read(codec, spec->mux_nids[adc_idx], 0,
AC_VERB_GET_POWER_STATE, 0x00) != AC_PWRST_D0)
snd_hda_codec_write(codec, spec->mux_nids[adc_idx], 0,
AC_VERB_SET_POWER_STATE, AC_PWRST_D0);
ret = snd_hda_input_mux_put(codec, spec->input_mux, ucontrol,
spec->mux_nids[adc_idx],
&spec->cur_mux[adc_idx]);
set_widgets_power_state(codec);
return ret;
}
static int via_independent_hp_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct via_spec *spec = codec->spec;
return snd_hda_input_mux_info(spec->hp_mux, uinfo);
}
static int via_independent_hp_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
hda_nid_t nid = kcontrol->private_value;
unsigned int pinsel;
pinsel = !!snd_hda_codec_read(codec, nid, 0,
AC_VERB_GET_CONNECT_SEL,
0x00);
ucontrol->value.enumerated.item[0] = pinsel;
return 0;
}
static void activate_ctl(struct hda_codec *codec, const char *name, int active)
{
struct snd_kcontrol *ctl = snd_hda_find_mixer_ctl(codec, name);
if (ctl) {
ctl->vd[0].access &= ~SNDRV_CTL_ELEM_ACCESS_INACTIVE;
ctl->vd[0].access |= active
? 0 : SNDRV_CTL_ELEM_ACCESS_INACTIVE;
snd_ctl_notify(codec->bus->card,
SNDRV_CTL_EVENT_MASK_VALUE, &ctl->id);
}
}
static hda_nid_t side_mute_channel(struct via_spec *spec)
{
switch (spec->codec_type) {
case VT1708: return 0x1b;
case VT1709_10CH: return 0x29;
case VT1708B_8CH:
case VT1708S: return 0x27;
case VT2002P: return 0x19;
case VT1802: return 0x15;
case VT1812: return 0x15;
default: return 0;
}
}
static int update_side_mute_status(struct hda_codec *codec)
{
struct via_spec *spec = codec->spec;
unsigned int parm;
hda_nid_t sw3 = side_mute_channel(spec);
if (sw3) {
if (VT2002P_COMPATIBLE(spec))
parm = spec->hp_independent_mode ?
AMP_IN_MUTE(1) : AMP_IN_UNMUTE(1);
else
parm = spec->hp_independent_mode ?
AMP_OUT_MUTE : AMP_OUT_UNMUTE;
snd_hda_codec_write(codec, sw3, 0,
AC_VERB_SET_AMP_GAIN_MUTE, parm);
if (spec->codec_type == VT1812)
snd_hda_codec_write(codec, 0x1d, 0,
AC_VERB_SET_AMP_GAIN_MUTE, parm);
}
return 0;
}
static int via_independent_hp_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct via_spec *spec = codec->spec;
hda_nid_t nid = kcontrol->private_value;
unsigned int pinsel = ucontrol->value.enumerated.item[0];
unsigned int parm0, parm1;
spec->hp_independent_mode = spec->hp_independent_mode_index == pinsel
? 1 : 0;
if (spec->codec_type == VT1718S) {
snd_hda_codec_write(codec, nid, 0,
AC_VERB_SET_CONNECT_SEL, pinsel ? 2 : 0);
parm0 = spec->hp_independent_mode ?
AMP_IN_UNMUTE(0) : AMP_IN_MUTE(0);
parm1 = spec->hp_independent_mode ?
AMP_IN_MUTE(1) : AMP_IN_UNMUTE(1);
snd_hda_codec_write(codec, 0x1b, 0,
AC_VERB_SET_AMP_GAIN_MUTE, parm0);
snd_hda_codec_write(codec, 0x1b, 0,
AC_VERB_SET_AMP_GAIN_MUTE, parm1);
}
else
snd_hda_codec_write(codec, nid, 0,
AC_VERB_SET_CONNECT_SEL, pinsel);
if (spec->codec_type == VT1812)
snd_hda_codec_write(codec, 0x35, 0,
AC_VERB_SET_CONNECT_SEL, pinsel);
if (spec->multiout.hp_nid && spec->multiout.hp_nid
!= spec->multiout.dac_nids[HDA_FRONT])
snd_hda_codec_setup_stream(codec, spec->multiout.hp_nid,
0, 0, 0);
update_side_mute_status(codec);
if (spec->codec_type == VT1708S
|| spec->codec_type == VT1702
|| spec->codec_type == VT1718S
|| spec->codec_type == VT1716S
|| VT2002P_COMPATIBLE(spec)) {
activate_ctl(codec, "Headphone Playback Volume",
spec->hp_independent_mode);
activate_ctl(codec, "Headphone Playback Switch",
spec->hp_independent_mode);
}
set_widgets_power_state(codec);
return 0;
}
static int via_hp_build(struct hda_codec *codec)
{
struct via_spec *spec = codec->spec;
struct snd_kcontrol_new *knew;
hda_nid_t nid;
int nums;
hda_nid_t conn[HDA_MAX_CONNECTIONS];
switch (spec->codec_type) {
case VT1718S:
nid = 0x34;
break;
case VT2002P:
case VT1802:
nid = 0x35;
break;
case VT1812:
nid = 0x3d;
break;
default:
nid = spec->autocfg.hp_pins[0];
break;
}
if (spec->codec_type != VT1708) {
nums = snd_hda_get_connections(codec, nid,
conn, HDA_MAX_CONNECTIONS);
if (nums <= 1)
return 0;
}
knew = via_clone_control(spec, &via_hp_mixer[0]);
if (knew == NULL)
return -ENOMEM;
knew->subdevice = HDA_SUBDEV_NID_FLAG | nid;
knew->private_value = nid;
nid = side_mute_channel(spec);
if (nid) {
knew = via_clone_control(spec, &via_hp_mixer[1]);
if (knew == NULL)
return -ENOMEM;
knew->subdevice = nid;
}
return 0;
}
static void notify_aa_path_ctls(struct hda_codec *codec)
{
int i;
struct snd_ctl_elem_id id;
const char *labels[] = {"Mic", "Front Mic", "Line", "Rear Mic"};
struct snd_kcontrol *ctl;
memset(&id, 0, sizeof(id));
id.iface = SNDRV_CTL_ELEM_IFACE_MIXER;
for (i = 0; i < ARRAY_SIZE(labels); i++) {
sprintf(id.name, "%s Playback Volume", labels[i]);
ctl = snd_hda_find_mixer_ctl(codec, id.name);
if (ctl)
snd_ctl_notify(codec->bus->card,
SNDRV_CTL_EVENT_MASK_VALUE,
&ctl->id);
}
}
static void mute_aa_path(struct hda_codec *codec, int mute)
{
struct via_spec *spec = codec->spec;
hda_nid_t nid_mixer;
int start_idx;
int end_idx;
int i;
switch (spec->codec_type) {
case VT1708:
nid_mixer = 0x17;
start_idx = 2;
end_idx = 4;
break;
case VT1709_10CH:
case VT1709_6CH:
nid_mixer = 0x18;
start_idx = 2;
end_idx = 4;
break;
case VT1708B_8CH:
case VT1708B_4CH:
case VT1708S:
case VT1716S:
nid_mixer = 0x16;
start_idx = 2;
end_idx = 4;
break;
case VT1718S:
nid_mixer = 0x21;
start_idx = 1;
end_idx = 3;
break;
default:
return;
}
for (i = start_idx; i <= end_idx; i++) {
int val = mute ? HDA_AMP_MUTE : HDA_AMP_UNMUTE;
snd_hda_codec_amp_stereo(codec, nid_mixer, HDA_INPUT, i,
HDA_AMP_MUTE, val);
}
}
static int is_smart51_pins(struct via_spec *spec, hda_nid_t pin)
{
const struct auto_pin_cfg *cfg = &spec->autocfg;
int i;
for (i = 0; i < cfg->num_inputs; i++) {
if (pin == cfg->inputs[i].pin)
return cfg->inputs[i].type <= AUTO_PIN_LINE_IN;
}
return 0;
}
static int via_smart51_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_BOOLEAN;
uinfo->count = 1;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = 1;
return 0;
}
static int via_smart51_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct via_spec *spec = codec->spec;
const struct auto_pin_cfg *cfg = &spec->autocfg;
int on = 1;
int i;
for (i = 0; i < cfg->num_inputs; i++) {
hda_nid_t nid = cfg->inputs[i].pin;
int ctl = snd_hda_codec_read(codec, nid, 0,
AC_VERB_GET_PIN_WIDGET_CONTROL, 0);
if (cfg->inputs[i].type > AUTO_PIN_LINE_IN)
continue;
if (cfg->inputs[i].type == AUTO_PIN_MIC &&
spec->hp_independent_mode && spec->codec_type != VT1718S)
continue;
if ((ctl & AC_PINCTL_IN_EN) && !(ctl & AC_PINCTL_OUT_EN))
on = 0;
}
*ucontrol->value.integer.value = on;
return 0;
}
static int via_smart51_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct via_spec *spec = codec->spec;
const struct auto_pin_cfg *cfg = &spec->autocfg;
int out_in = *ucontrol->value.integer.value
? AC_PINCTL_OUT_EN : AC_PINCTL_IN_EN;
int i;
for (i = 0; i < cfg->num_inputs; i++) {
hda_nid_t nid = cfg->inputs[i].pin;
unsigned int parm;
if (cfg->inputs[i].type > AUTO_PIN_LINE_IN)
continue;
if (cfg->inputs[i].type == AUTO_PIN_MIC &&
spec->hp_independent_mode && spec->codec_type != VT1718S)
continue;
parm = snd_hda_codec_read(codec, nid, 0,
AC_VERB_GET_PIN_WIDGET_CONTROL, 0);
parm &= ~(AC_PINCTL_IN_EN | AC_PINCTL_OUT_EN);
parm |= out_in;
snd_hda_codec_write(codec, nid, 0,
AC_VERB_SET_PIN_WIDGET_CONTROL,
parm);
if (out_in == AC_PINCTL_OUT_EN) {
mute_aa_path(codec, 1);
notify_aa_path_ctls(codec);
}
if (spec->codec_type == VT1718S) {
snd_hda_codec_amp_stereo(
codec, nid, HDA_OUTPUT, 0, HDA_AMP_MUTE,
HDA_AMP_UNMUTE);
}
if (cfg->inputs[i].type == AUTO_PIN_MIC) {
if (spec->codec_type == VT1708S
|| spec->codec_type == VT1716S) {
snd_hda_codec_write(
codec, nid, 0,
AC_VERB_SET_CONNECT_SEL, 1);
snd_hda_codec_amp_stereo(
codec, nid, HDA_OUTPUT,
0, HDA_AMP_MUTE, HDA_AMP_UNMUTE);
}
}
}
spec->smart51_enabled = *ucontrol->value.integer.value;
set_widgets_power_state(codec);
return 1;
}
static int via_smart51_build(struct via_spec *spec)
{
struct snd_kcontrol_new *knew;
const struct auto_pin_cfg *cfg = &spec->autocfg;
hda_nid_t nid;
int i;
if (!cfg)
return 0;
if (cfg->line_outs > 2)
return 0;
knew = via_clone_control(spec, &via_smart51_mixer[0]);
if (knew == NULL)
return -ENOMEM;
for (i = 0; i < cfg->num_inputs; i++) {
nid = cfg->inputs[i].pin;
if (cfg->inputs[i].type <= AUTO_PIN_LINE_IN) {
knew = via_clone_control(spec, &via_smart51_mixer[1]);
if (knew == NULL)
return -ENOMEM;
knew->subdevice = nid;
break;
}
}
return 0;
}
static int is_aa_path_mute(struct hda_codec *codec)
{
int mute = 1;
hda_nid_t nid_mixer;
int start_idx;
int end_idx;
int i;
struct via_spec *spec = codec->spec;
switch (spec->codec_type) {
case VT1708B_8CH:
case VT1708B_4CH:
case VT1708S:
case VT1716S:
nid_mixer = 0x16;
start_idx = 2;
end_idx = 4;
break;
case VT1702:
nid_mixer = 0x1a;
start_idx = 1;
end_idx = 3;
break;
case VT1718S:
nid_mixer = 0x21;
start_idx = 1;
end_idx = 3;
break;
case VT2002P:
case VT1812:
case VT1802:
nid_mixer = 0x21;
start_idx = 0;
end_idx = 2;
break;
default:
return 0;
}
for (i = start_idx; i <= end_idx; i++) {
unsigned int con_list = snd_hda_codec_read(
codec, nid_mixer, 0, AC_VERB_GET_CONNECT_LIST, i/4*4);
int shift = 8 * (i % 4);
hda_nid_t nid_pin = (con_list & (0xff << shift)) >> shift;
unsigned int defconf = snd_hda_codec_get_pincfg(codec, nid_pin);
if (get_defcfg_connect(defconf) == AC_JACK_PORT_COMPLEX) {
int mute_l = snd_hda_codec_amp_read(codec, nid_mixer, 0,
HDA_INPUT, i) >> 7;
int mute_r = snd_hda_codec_amp_read(codec, nid_mixer, 1,
HDA_INPUT, i) >> 7;
if (!mute_l || !mute_r) {
mute = 0;
break;
}
}
}
return mute;
}
static void analog_low_current_mode(struct hda_codec *codec, int stream_idle)
{
struct via_spec *spec = codec->spec;
static int saved_stream_idle = 1;
int enable = is_aa_path_mute(codec);
unsigned int verb = 0;
unsigned int parm = 0;
if (stream_idle == -1)
enable = enable && saved_stream_idle;
else {
enable = enable && stream_idle;
saved_stream_idle = stream_idle;
}
switch (spec->codec_type) {
case VT1708B_8CH:
case VT1708B_4CH:
verb = 0xf70;
parm = enable ? 0x02 : 0x00;
break;
case VT1708S:
case VT1718S:
case VT1716S:
verb = 0xf73;
parm = enable ? 0x51 : 0xe1;
break;
case VT1702:
verb = 0xf73;
parm = enable ? 0x01 : 0x1d;
break;
case VT2002P:
case VT1812:
case VT1802:
verb = 0xf93;
parm = enable ? 0x00 : 0xe0;
break;
default:
return;
}
snd_hda_codec_write(codec, codec->afg, 0, verb, parm);
}
static int via_playback_pcm_open(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
struct snd_pcm_substream *substream)
{
struct via_spec *spec = codec->spec;
int idle = substream->pstr->substream_opened == 1
&& substream->ref_count == 0;
analog_low_current_mode(codec, idle);
return snd_hda_multi_out_analog_open(codec, &spec->multiout, substream,
hinfo);
}
static void playback_multi_pcm_prep_0(struct hda_codec *codec,
unsigned int stream_tag,
unsigned int format,
struct snd_pcm_substream *substream)
{
struct via_spec *spec = codec->spec;
struct hda_multi_out *mout = &spec->multiout;
const hda_nid_t *nids = mout->dac_nids;
int chs = substream->runtime->channels;
int i;
mutex_lock(&codec->spdif_mutex);
if (mout->dig_out_nid && mout->dig_out_used != HDA_DIG_EXCLUSIVE) {
if (chs == 2 &&
snd_hda_is_supported_format(codec, mout->dig_out_nid,
format) &&
!(codec->spdif_status & IEC958_AES0_NONAUDIO)) {
mout->dig_out_used = HDA_DIG_ANALOG_DUP;
if (codec->spdif_ctls & AC_DIG1_ENABLE)
snd_hda_codec_write(codec, mout->dig_out_nid, 0,
AC_VERB_SET_DIGI_CONVERT_1,
codec->spdif_ctls &
~AC_DIG1_ENABLE & 0xff);
snd_hda_codec_setup_stream(codec, mout->dig_out_nid,
stream_tag, 0, format);
if (codec->spdif_ctls & AC_DIG1_ENABLE)
snd_hda_codec_write(codec, mout->dig_out_nid, 0,
AC_VERB_SET_DIGI_CONVERT_1,
codec->spdif_ctls & 0xff);
} else {
mout->dig_out_used = 0;
snd_hda_codec_setup_stream(codec, mout->dig_out_nid,
0, 0, 0);
}
}
mutex_unlock(&codec->spdif_mutex);
snd_hda_codec_setup_stream(codec, nids[HDA_FRONT], stream_tag,
0, format);
if (mout->hp_nid && mout->hp_nid != nids[HDA_FRONT]
&& !spec->hp_independent_mode)
snd_hda_codec_setup_stream(codec, mout->hp_nid, stream_tag,
0, format);
for (i = 0; i < ARRAY_SIZE(mout->extra_out_nid); i++)
if (mout->extra_out_nid[i])
snd_hda_codec_setup_stream(codec,
mout->extra_out_nid[i],
stream_tag, 0, format);
for (i = 1; i < mout->num_dacs; i++) {
if (chs >= (i + 1) * 2)
snd_hda_codec_setup_stream(codec, nids[i], stream_tag,
i * 2, format);
else
snd_hda_codec_setup_stream(codec, nids[i], stream_tag,
0, format);
}
}
static int via_playback_multi_pcm_prepare(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
unsigned int stream_tag,
unsigned int format,
struct snd_pcm_substream *substream)
{
struct via_spec *spec = codec->spec;
struct hda_multi_out *mout = &spec->multiout;
const hda_nid_t *nids = mout->dac_nids;
if (substream->number == 0)
playback_multi_pcm_prep_0(codec, stream_tag, format,
substream);
else {
if (mout->hp_nid && mout->hp_nid != nids[HDA_FRONT] &&
spec->hp_independent_mode)
snd_hda_codec_setup_stream(codec, mout->hp_nid,
stream_tag, 0, format);
}
vt1708_start_hp_work(spec);
return 0;
}
static int via_playback_multi_pcm_cleanup(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
struct snd_pcm_substream *substream)
{
struct via_spec *spec = codec->spec;
struct hda_multi_out *mout = &spec->multiout;
const hda_nid_t *nids = mout->dac_nids;
int i;
if (substream->number == 0) {
for (i = 0; i < mout->num_dacs; i++)
snd_hda_codec_setup_stream(codec, nids[i], 0, 0, 0);
if (mout->hp_nid && !spec->hp_independent_mode)
snd_hda_codec_setup_stream(codec, mout->hp_nid,
0, 0, 0);
for (i = 0; i < ARRAY_SIZE(mout->extra_out_nid); i++)
if (mout->extra_out_nid[i])
snd_hda_codec_setup_stream(codec,
mout->extra_out_nid[i],
0, 0, 0);
mutex_lock(&codec->spdif_mutex);
if (mout->dig_out_nid &&
mout->dig_out_used == HDA_DIG_ANALOG_DUP) {
snd_hda_codec_setup_stream(codec, mout->dig_out_nid,
0, 0, 0);
mout->dig_out_used = 0;
}
mutex_unlock(&codec->spdif_mutex);
} else {
if (mout->hp_nid && mout->hp_nid != nids[HDA_FRONT] &&
spec->hp_independent_mode)
snd_hda_codec_setup_stream(codec, mout->hp_nid,
0, 0, 0);
}
vt1708_stop_hp_work(spec);
return 0;
}
static int via_dig_playback_pcm_open(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
struct snd_pcm_substream *substream)
{
struct via_spec *spec = codec->spec;
return snd_hda_multi_out_dig_open(codec, &spec->multiout);
}
static int via_dig_playback_pcm_close(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
struct snd_pcm_substream *substream)
{
struct via_spec *spec = codec->spec;
return snd_hda_multi_out_dig_close(codec, &spec->multiout);
}
static int via_dig_playback_pcm_prepare(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
unsigned int stream_tag,
unsigned int format,
struct snd_pcm_substream *substream)
{
struct via_spec *spec = codec->spec;
return snd_hda_multi_out_dig_prepare(codec, &spec->multiout,
stream_tag, format, substream);
}
static int via_dig_playback_pcm_cleanup(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
struct snd_pcm_substream *substream)
{
struct via_spec *spec = codec->spec;
snd_hda_multi_out_dig_cleanup(codec, &spec->multiout);
return 0;
}
static int via_capture_pcm_prepare(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
unsigned int stream_tag,
unsigned int format,
struct snd_pcm_substream *substream)
{
struct via_spec *spec = codec->spec;
snd_hda_codec_setup_stream(codec, spec->adc_nids[substream->number],
stream_tag, 0, format);
return 0;
}
static int via_capture_pcm_cleanup(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
struct snd_pcm_substream *substream)
{
struct via_spec *spec = codec->spec;
snd_hda_codec_cleanup_stream(codec, spec->adc_nids[substream->number]);
return 0;
}
static int via_build_controls(struct hda_codec *codec)
{
struct via_spec *spec = codec->spec;
struct snd_kcontrol *kctl;
const struct snd_kcontrol_new *knew;
int err, i;
for (i = 0; i < spec->num_mixers; i++) {
err = snd_hda_add_new_ctls(codec, spec->mixers[i]);
if (err < 0)
return err;
}
if (spec->multiout.dig_out_nid) {
err = snd_hda_create_spdif_out_ctls(codec,
spec->multiout.dig_out_nid);
if (err < 0)
return err;
err = snd_hda_create_spdif_share_sw(codec,
&spec->multiout);
if (err < 0)
return err;
spec->multiout.share_spdif = 1;
}
if (spec->dig_in_nid) {
err = snd_hda_create_spdif_in_ctls(codec, spec->dig_in_nid);
if (err < 0)
return err;
}
kctl = snd_hda_find_mixer_ctl(codec, "Input Source");
for (i = 0; kctl && i < kctl->count; i++) {
err = snd_hda_add_nid(codec, kctl, i, spec->mux_nids[i]);
if (err < 0)
return err;
}
for (i = 0; i < spec->num_mixers; i++) {
for (knew = spec->mixers[i]; knew->name; knew++) {
if (knew->iface != NID_MAPPING)
continue;
kctl = snd_hda_find_mixer_ctl(codec, knew->name);
if (kctl == NULL)
continue;
err = snd_hda_add_nid(codec, kctl, 0,
knew->subdevice);
}
}
set_widgets_power_state(codec);
analog_low_current_mode(codec, 1);
via_free_kctls(codec);
return 0;
}
static int via_build_pcms(struct hda_codec *codec)
{
struct via_spec *spec = codec->spec;
struct hda_pcm *info = spec->pcm_rec;
codec->num_pcms = 1;
codec->pcm_info = info;
info->name = spec->stream_name_analog;
info->stream[SNDRV_PCM_STREAM_PLAYBACK] =
*(spec->stream_analog_playback);
info->stream[SNDRV_PCM_STREAM_PLAYBACK].nid =
spec->multiout.dac_nids[0];
info->stream[SNDRV_PCM_STREAM_CAPTURE] = *(spec->stream_analog_capture);
info->stream[SNDRV_PCM_STREAM_CAPTURE].nid = spec->adc_nids[0];
info->stream[SNDRV_PCM_STREAM_PLAYBACK].channels_max =
spec->multiout.max_channels;
if (spec->multiout.dig_out_nid || spec->dig_in_nid) {
codec->num_pcms++;
info++;
info->name = spec->stream_name_digital;
info->pcm_type = HDA_PCM_TYPE_SPDIF;
if (spec->multiout.dig_out_nid) {
info->stream[SNDRV_PCM_STREAM_PLAYBACK] =
*(spec->stream_digital_playback);
info->stream[SNDRV_PCM_STREAM_PLAYBACK].nid =
spec->multiout.dig_out_nid;
}
if (spec->dig_in_nid) {
info->stream[SNDRV_PCM_STREAM_CAPTURE] =
*(spec->stream_digital_capture);
info->stream[SNDRV_PCM_STREAM_CAPTURE].nid =
spec->dig_in_nid;
}
}
return 0;
}
static void via_free(struct hda_codec *codec)
{
struct via_spec *spec = codec->spec;
if (!spec)
return;
via_free_kctls(codec);
vt1708_stop_hp_work(spec);
kfree(codec->spec);
}
static void via_hp_automute(struct hda_codec *codec)
{
unsigned int present = 0;
struct via_spec *spec = codec->spec;
present = snd_hda_jack_detect(codec, spec->autocfg.hp_pins[0]);
if (!spec->hp_independent_mode) {
struct snd_ctl_elem_id id;
snd_hda_codec_amp_stereo(
codec, spec->autocfg.line_out_pins[0], HDA_OUTPUT, 0,
HDA_AMP_MUTE, present ? HDA_AMP_MUTE : 0);
memset(&id, 0, sizeof(id));
id.iface = SNDRV_CTL_ELEM_IFACE_MIXER;
strcpy(id.name, "Front Playback Switch");
snd_ctl_notify(codec->bus->card, SNDRV_CTL_EVENT_MASK_VALUE,
&id);
}
}
static void via_mono_automute(struct hda_codec *codec)
{
unsigned int hp_present, lineout_present;
struct via_spec *spec = codec->spec;
if (spec->codec_type != VT1716S)
return;
lineout_present = snd_hda_jack_detect(codec,
spec->autocfg.line_out_pins[0]);
if (lineout_present) {
snd_hda_codec_amp_stereo(
codec, 0x2A, HDA_OUTPUT, 0, HDA_AMP_MUTE, HDA_AMP_MUTE);
return;
}
hp_present = snd_hda_jack_detect(codec, spec->autocfg.hp_pins[0]);
if (!spec->hp_independent_mode)
snd_hda_codec_amp_stereo(
codec, 0x2A, HDA_OUTPUT, 0, HDA_AMP_MUTE,
hp_present ? HDA_AMP_MUTE : 0);
}
static void via_gpio_control(struct hda_codec *codec)
{
unsigned int gpio_data;
unsigned int vol_counter;
unsigned int vol;
unsigned int master_vol;
struct via_spec *spec = codec->spec;
gpio_data = snd_hda_codec_read(codec, codec->afg, 0,
AC_VERB_GET_GPIO_DATA, 0) & 0x03;
vol_counter = (snd_hda_codec_read(codec, codec->afg, 0,
0xF84, 0) & 0x3F0000) >> 16;
vol = vol_counter & 0x1F;
master_vol = snd_hda_codec_read(codec, 0x1A, 0,
AC_VERB_GET_AMP_GAIN_MUTE,
AC_AMP_GET_INPUT);
if (gpio_data == 0x02) {
snd_hda_codec_amp_stereo(codec, spec->autocfg.line_out_pins[0],
HDA_OUTPUT, 0, HDA_AMP_MUTE, 0);
if (vol_counter & 0x20) {
if (vol > master_vol)
vol = master_vol;
snd_hda_codec_amp_stereo(codec, 0x1A, HDA_INPUT,
0, HDA_AMP_VOLMASK,
master_vol-vol);
} else {
snd_hda_codec_amp_stereo(codec, 0x1A, HDA_INPUT, 0,
HDA_AMP_VOLMASK,
((master_vol+vol) > 0x2A) ? 0x2A :
(master_vol+vol));
}
} else if (!(gpio_data & 0x02)) {
snd_hda_codec_amp_stereo(codec,
spec->autocfg.line_out_pins[0],
HDA_OUTPUT, 0, HDA_AMP_MUTE,
HDA_AMP_MUTE);
}
}
static void via_speaker_automute(struct hda_codec *codec)
{
unsigned int hp_present;
struct via_spec *spec = codec->spec;
if (!VT2002P_COMPATIBLE(spec))
return;
hp_present = snd_hda_jack_detect(codec, spec->autocfg.hp_pins[0]);
if (!spec->hp_independent_mode) {
struct snd_ctl_elem_id id;
snd_hda_codec_amp_stereo(
codec, spec->autocfg.speaker_pins[0], HDA_OUTPUT, 0,
HDA_AMP_MUTE, hp_present ? HDA_AMP_MUTE : 0);
memset(&id, 0, sizeof(id));
id.iface = SNDRV_CTL_ELEM_IFACE_MIXER;
strcpy(id.name, "Speaker Playback Switch");
snd_ctl_notify(codec->bus->card, SNDRV_CTL_EVENT_MASK_VALUE,
&id);
}
}
static void via_hp_bind_automute(struct hda_codec *codec)
{
unsigned long hp_present, present = 0;
struct via_spec *spec = codec->spec;
int i;
if (!spec->autocfg.hp_pins[0] || !spec->autocfg.line_out_pins[0])
return;
hp_present = snd_hda_jack_detect(codec, spec->autocfg.hp_pins[0]);
present = snd_hda_jack_detect(codec, spec->autocfg.line_out_pins[0]);
if (!spec->hp_independent_mode) {
for (i = 0; i < spec->autocfg.line_outs; i++)
snd_hda_codec_amp_stereo(
codec, spec->autocfg.line_out_pins[i],
HDA_OUTPUT, 0,
HDA_AMP_MUTE, hp_present ? HDA_AMP_MUTE : 0);
if (hp_present)
present = hp_present;
}
for (i = 0; i < spec->autocfg.speaker_outs; i++)
snd_hda_codec_amp_stereo(
codec, spec->autocfg.speaker_pins[i], HDA_OUTPUT, 0,
HDA_AMP_MUTE, present ? HDA_AMP_MUTE : 0);
}
static void via_unsol_event(struct hda_codec *codec,
unsigned int res)
{
res >>= 26;
if (res & VIA_JACK_EVENT)
set_widgets_power_state(codec);
res &= ~VIA_JACK_EVENT;
if (res == VIA_HP_EVENT)
via_hp_automute(codec);
else if (res == VIA_GPIO_EVENT)
via_gpio_control(codec);
else if (res == VIA_MONO_EVENT)
via_mono_automute(codec);
else if (res == VIA_SPEAKER_EVENT)
via_speaker_automute(codec);
else if (res == VIA_BIND_HP_EVENT)
via_hp_bind_automute(codec);
}
static int via_init(struct hda_codec *codec)
{
struct via_spec *spec = codec->spec;
int i;
for (i = 0; i < spec->num_iverbs; i++)
snd_hda_sequence_write(codec, spec->init_verbs[i]);
if (!spec->dig_in_nid) {
if (spec->dig_in_pin) {
snd_hda_codec_write(codec, spec->dig_in_pin, 0,
AC_VERB_SET_PIN_WIDGET_CONTROL,
PIN_OUT);
snd_hda_codec_write(codec, spec->dig_in_pin, 0,
AC_VERB_SET_EAPD_BTLENABLE, 0x02);
}
} else
snd_hda_codec_write(codec, spec->autocfg.dig_in_pin, 0,
AC_VERB_SET_PIN_WIDGET_CONTROL, PIN_IN);
if (spec->slave_dig_outs[0])
codec->slave_dig_outs = spec->slave_dig_outs;
return 0;
}
static int via_suspend(struct hda_codec *codec, pm_message_t state)
{
struct via_spec *spec = codec->spec;
vt1708_stop_hp_work(spec);
return 0;
}
static int via_check_power_status(struct hda_codec *codec, hda_nid_t nid)
{
struct via_spec *spec = codec->spec;
return snd_hda_check_amp_list_power(codec, &spec->loopback, nid);
}
static int vt1708_auto_fill_dac_nids(struct via_spec *spec,
const struct auto_pin_cfg *cfg)
{
int i;
hda_nid_t nid;
spec->multiout.num_dacs = cfg->line_outs;
spec->multiout.dac_nids = spec->private_dac_nids;
for (i = 0; i < 4; i++) {
nid = cfg->line_out_pins[i];
if (nid) {
switch (i) {
case AUTO_SEQ_FRONT:
spec->private_dac_nids[i] = 0x10;
break;
case AUTO_SEQ_CENLFE:
spec->private_dac_nids[i] = 0x12;
break;
case AUTO_SEQ_SURROUND:
spec->private_dac_nids[i] = 0x11;
break;
case AUTO_SEQ_SIDE:
spec->private_dac_nids[i] = 0x13;
break;
}
}
}
return 0;
}
static int vt1708_auto_create_multi_out_ctls(struct via_spec *spec,
const struct auto_pin_cfg *cfg)
{
char name[32];
static const char * const chname[4] = {
"Front", "Surround", "C/LFE", "Side"
};
hda_nid_t nid, nid_vol, nid_vols[] = {0x17, 0x19, 0x1a, 0x1b};
int i, err;
for (i = 0; i <= AUTO_SEQ_SIDE; i++) {
nid = cfg->line_out_pins[i];
if (!nid)
continue;
nid_vol = nid_vols[i];
if (i == AUTO_SEQ_CENLFE) {
err = via_add_control(spec, VIA_CTL_WIDGET_VOL,
"Center Playback Volume",
HDA_COMPOSE_AMP_VAL(nid_vol, 1, 0,
HDA_OUTPUT));
if (err < 0)
return err;
err = via_add_control(spec, VIA_CTL_WIDGET_VOL,
"LFE Playback Volume",
HDA_COMPOSE_AMP_VAL(nid_vol, 2, 0,
HDA_OUTPUT));
if (err < 0)
return err;
err = via_add_control(spec, VIA_CTL_WIDGET_MUTE,
"Center Playback Switch",
HDA_COMPOSE_AMP_VAL(nid_vol, 1, 0,
HDA_OUTPUT));
if (err < 0)
return err;
err = via_add_control(spec, VIA_CTL_WIDGET_MUTE,
"LFE Playback Switch",
HDA_COMPOSE_AMP_VAL(nid_vol, 2, 0,
HDA_OUTPUT));
if (err < 0)
return err;
} else if (i == AUTO_SEQ_FRONT) {
err = via_add_control(spec, VIA_CTL_WIDGET_VOL,
"Master Front Playback Volume",
HDA_COMPOSE_AMP_VAL(nid_vol, 3, 0,
HDA_INPUT));
if (err < 0)
return err;
err = via_add_control(spec, VIA_CTL_WIDGET_MUTE,
"Master Front Playback Switch",
HDA_COMPOSE_AMP_VAL(nid_vol, 3, 0,
HDA_INPUT));
if (err < 0)
return err;
sprintf(name, "%s Playback Volume", chname[i]);
err = via_add_control(spec, VIA_CTL_WIDGET_VOL, name,
HDA_COMPOSE_AMP_VAL(nid, 3, 0,
HDA_OUTPUT));
if (err < 0)
return err;
sprintf(name, "%s Playback Switch", chname[i]);
err = via_add_control(spec, VIA_CTL_WIDGET_MUTE, name,
HDA_COMPOSE_AMP_VAL(nid, 3, 0,
HDA_OUTPUT));
if (err < 0)
return err;
} else {
sprintf(name, "%s Playback Volume", chname[i]);
err = via_add_control(spec, VIA_CTL_WIDGET_VOL, name,
HDA_COMPOSE_AMP_VAL(nid_vol, 3, 0,
HDA_OUTPUT));
if (err < 0)
return err;
sprintf(name, "%s Playback Switch", chname[i]);
err = via_add_control(spec, VIA_CTL_WIDGET_MUTE, name,
HDA_COMPOSE_AMP_VAL(nid_vol, 3, 0,
HDA_OUTPUT));
if (err < 0)
return err;
}
}
return 0;
}
static void create_hp_imux(struct via_spec *spec)
{
int i;
struct hda_input_mux *imux = &spec->private_imux[1];
static const char * const texts[] = { "OFF", "ON", NULL};
for (i = 0; texts[i]; i++)
snd_hda_add_imux_item(imux, texts[i], i, NULL);
spec->hp_mux = &spec->private_imux[1];
}
static int vt1708_auto_create_hp_ctls(struct via_spec *spec, hda_nid_t pin)
{
int err;
if (!pin)
return 0;
spec->multiout.hp_nid = VT1708_HP_NID;
spec->hp_independent_mode_index = 1;
err = via_add_control(spec, VIA_CTL_WIDGET_VOL,
"Headphone Playback Volume",
HDA_COMPOSE_AMP_VAL(pin, 3, 0, HDA_OUTPUT));
if (err < 0)
return err;
err = via_add_control(spec, VIA_CTL_WIDGET_MUTE,
"Headphone Playback Switch",
HDA_COMPOSE_AMP_VAL(pin, 3, 0, HDA_OUTPUT));
if (err < 0)
return err;
create_hp_imux(spec);
return 0;
}
static int vt_auto_create_analog_input_ctls(struct hda_codec *codec,
const struct auto_pin_cfg *cfg,
hda_nid_t cap_nid,
const hda_nid_t pin_idxs[],
int num_idxs)
{
struct via_spec *spec = codec->spec;
struct hda_input_mux *imux = &spec->private_imux[0];
int i, err, idx, type, type_idx = 0;
for (idx = 0; idx < num_idxs; idx++) {
if (pin_idxs[idx] == 0xff) {
snd_hda_add_imux_item(imux, "Stereo Mixer", idx, NULL);
break;
}
}
for (i = 0; i < cfg->num_inputs; i++) {
const char *label;
type = cfg->inputs[i].type;
for (idx = 0; idx < num_idxs; idx++)
if (pin_idxs[idx] == cfg->inputs[i].pin)
break;
if (idx >= num_idxs)
continue;
if (i > 0 && type == cfg->inputs[i - 1].type)
type_idx++;
else
type_idx = 0;
label = hda_get_autocfg_input_label(codec, cfg, i);
if (spec->codec_type == VT1708S ||
spec->codec_type == VT1702 ||
spec->codec_type == VT1716S)
err = via_new_analog_input(spec, label, type_idx,
idx+1, cap_nid);
else
err = via_new_analog_input(spec, label, type_idx,
idx, cap_nid);
if (err < 0)
return err;
snd_hda_add_imux_item(imux, label, idx, NULL);
}
return 0;
}
static int vt1708_auto_create_analog_input_ctls(struct hda_codec *codec,
const struct auto_pin_cfg *cfg)
{
static const hda_nid_t pin_idxs[] = { 0xff, 0x24, 0x1d, 0x1e, 0x21 };
return vt_auto_create_analog_input_ctls(codec, cfg, 0x17, pin_idxs,
ARRAY_SIZE(pin_idxs));
}
static void vt1708_set_pinconfig_connect(struct hda_codec *codec, hda_nid_t nid)
{
unsigned int def_conf;
unsigned char seqassoc;
def_conf = snd_hda_codec_get_pincfg(codec, nid);
seqassoc = (unsigned char) get_defcfg_association(def_conf);
seqassoc = (seqassoc << 4) | get_defcfg_sequence(def_conf);
if (get_defcfg_connect(def_conf) == AC_JACK_PORT_NONE
&& (seqassoc == 0xf0 || seqassoc == 0xff)) {
def_conf = def_conf & (~(AC_JACK_PORT_BOTH << 30));
snd_hda_codec_set_pincfg(codec, nid, def_conf);
}
return;
}
static int vt1708_jack_detectect_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct via_spec *spec = codec->spec;
if (spec->codec_type != VT1708)
return 0;
spec->vt1708_jack_detectect =
!((snd_hda_codec_read(codec, 0x1, 0, 0xf84, 0) >> 8) & 0x1);
ucontrol->value.integer.value[0] = spec->vt1708_jack_detectect;
return 0;
}
static int vt1708_jack_detectect_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct via_spec *spec = codec->spec;
int change;
if (spec->codec_type != VT1708)
return 0;
spec->vt1708_jack_detectect = ucontrol->value.integer.value[0];
change = (0x1 & (snd_hda_codec_read(codec, 0x1, 0, 0xf84, 0) >> 8))
== !spec->vt1708_jack_detectect;
if (spec->vt1708_jack_detectect) {
mute_aa_path(codec, 1);
notify_aa_path_ctls(codec);
}
return change;
}
static int vt1708_parse_auto_config(struct hda_codec *codec)
{
struct via_spec *spec = codec->spec;
int err;
vt1708_set_pinconfig_connect(codec, VT1708_HP_PIN_NID);
vt1708_set_pinconfig_connect(codec, VT1708_CD_PIN_NID);
err = snd_hda_parse_pin_def_config(codec, &spec->autocfg, NULL);
if (err < 0)
return err;
err = vt1708_auto_fill_dac_nids(spec, &spec->autocfg);
if (err < 0)
return err;
if (!spec->autocfg.line_outs && !spec->autocfg.hp_pins[0])
return 0;
err = vt1708_auto_create_multi_out_ctls(spec, &spec->autocfg);
if (err < 0)
return err;
err = vt1708_auto_create_hp_ctls(spec, spec->autocfg.hp_pins[0]);
if (err < 0)
return err;
err = vt1708_auto_create_analog_input_ctls(codec, &spec->autocfg);
if (err < 0)
return err;
err = snd_hda_add_new_ctls(codec, vt1708_jack_detectect);
if (err < 0)
return err;
spec->multiout.max_channels = spec->multiout.num_dacs * 2;
if (spec->autocfg.dig_outs)
spec->multiout.dig_out_nid = VT1708_DIGOUT_NID;
spec->dig_in_pin = VT1708_DIGIN_PIN;
if (spec->autocfg.dig_in_pin)
spec->dig_in_nid = VT1708_DIGIN_NID;
if (spec->kctls.list)
spec->mixers[spec->num_mixers++] = spec->kctls.list;
spec->init_verbs[spec->num_iverbs++] = vt1708_volume_init_verbs;
spec->input_mux = &spec->private_imux[0];
if (spec->hp_mux)
via_hp_build(codec);
via_smart51_build(spec);
return 1;
}
static int via_auto_init(struct hda_codec *codec)
{
struct via_spec *spec = codec->spec;
via_init(codec);
via_auto_init_multi_out(codec);
via_auto_init_hp_out(codec);
via_auto_init_analog_input(codec);
if (VT2002P_COMPATIBLE(spec)) {
via_hp_bind_automute(codec);
} else {
via_hp_automute(codec);
via_speaker_automute(codec);
}
return 0;
}
static void vt1708_update_hp_jack_state(struct work_struct *work)
{
struct via_spec *spec = container_of(work, struct via_spec,
vt1708_hp_work.work);
if (spec->codec_type != VT1708)
return;
if (spec->vt1708_hp_present
!= snd_hda_jack_detect(spec->codec, spec->autocfg.hp_pins[0])) {
spec->vt1708_hp_present ^= 1;
via_hp_automute(spec->codec);
}
vt1708_start_hp_work(spec);
}
static int get_mux_nids(struct hda_codec *codec)
{
struct via_spec *spec = codec->spec;
hda_nid_t nid, conn[8];
unsigned int type;
int i, n;
for (i = 0; i < spec->num_adc_nids; i++) {
nid = spec->adc_nids[i];
while (nid) {
type = get_wcaps_type(get_wcaps(codec, nid));
if (type == AC_WID_PIN)
break;
n = snd_hda_get_connections(codec, nid, conn,
ARRAY_SIZE(conn));
if (n <= 0)
break;
if (n > 1) {
spec->mux_nids[i] = nid;
break;
}
nid = conn[0];
}
}
return 0;
}
static int patch_vt1708(struct hda_codec *codec)
{
struct via_spec *spec;
int err;
spec = via_new_spec(codec);
if (spec == NULL)
return -ENOMEM;
err = vt1708_parse_auto_config(codec);
if (err < 0) {
via_free(codec);
return err;
} else if (!err) {
printk(KERN_INFO "hda_codec: Cannot set up configuration "
"from BIOS. Using genenic mode...\n");
}
spec->stream_name_analog = "VT1708 Analog";
spec->stream_analog_playback = &vt1708_pcm_analog_playback;
if (codec->vendor_id == 0x11061708)
spec->stream_analog_playback = &vt1708_pcm_analog_s16_playback;
spec->stream_analog_capture = &vt1708_pcm_analog_capture;
spec->stream_name_digital = "VT1708 Digital";
spec->stream_digital_playback = &vt1708_pcm_digital_playback;
spec->stream_digital_capture = &vt1708_pcm_digital_capture;
if (!spec->adc_nids && spec->input_mux) {
spec->adc_nids = vt1708_adc_nids;
spec->num_adc_nids = ARRAY_SIZE(vt1708_adc_nids);
get_mux_nids(codec);
spec->mixers[spec->num_mixers] = vt1708_capture_mixer;
spec->num_mixers++;
}
codec->patch_ops = via_patch_ops;
codec->patch_ops.init = via_auto_init;
#ifdef CONFIG_SND_HDA_POWER_SAVE
spec->loopback.amplist = vt1708_loopbacks;
#endif
INIT_DELAYED_WORK(&spec->vt1708_hp_work, vt1708_update_hp_jack_state);
return 0;
}
static int vt1709_auto_fill_dac_nids(struct via_spec *spec,
const struct auto_pin_cfg *cfg)
{
int i;
hda_nid_t nid;
if (cfg->line_outs == 4)
spec->multiout.num_dacs = cfg->line_outs+1;
else if (cfg->line_outs == 3)
spec->multiout.num_dacs = cfg->line_outs;
spec->multiout.dac_nids = spec->private_dac_nids;
if (cfg->line_outs == 4) {
for (i = 0; i < cfg->line_outs; i++) {
nid = cfg->line_out_pins[i];
if (nid) {
switch (i) {
case AUTO_SEQ_FRONT:
spec->private_dac_nids[i] = 0x10;
break;
case AUTO_SEQ_CENLFE:
spec->private_dac_nids[i] = 0x12;
break;
case AUTO_SEQ_SURROUND:
spec->private_dac_nids[i] = 0x11;
break;
case AUTO_SEQ_SIDE:
spec->private_dac_nids[i] = 0x27;
break;
default:
break;
}
}
}
spec->private_dac_nids[cfg->line_outs] = 0x28;
} else if (cfg->line_outs == 3) {
for (i = 0; i < cfg->line_outs; i++) {
nid = cfg->line_out_pins[i];
if (nid) {
switch (i) {
case AUTO_SEQ_FRONT:
spec->private_dac_nids[i] = 0x10;
break;
case AUTO_SEQ_CENLFE:
spec->private_dac_nids[i] = 0x12;
break;
case AUTO_SEQ_SURROUND:
spec->private_dac_nids[i] = 0x11;
break;
default:
break;
}
}
}
}
return 0;
}
static int vt1709_auto_create_multi_out_ctls(struct via_spec *spec,
const struct auto_pin_cfg *cfg)
{
char name[32];
static const char * const chname[4] = {
"Front", "Surround", "C/LFE", "Side"
};
hda_nid_t nid, nid_vol, nid_vols[] = {0x18, 0x1a, 0x1b, 0x29};
int i, err;
for (i = 0; i <= AUTO_SEQ_SIDE; i++) {
nid = cfg->line_out_pins[i];
if (!nid)
continue;
nid_vol = nid_vols[i];
if (i == AUTO_SEQ_CENLFE) {
err = via_add_control(spec, VIA_CTL_WIDGET_VOL,
"Center Playback Volume",
HDA_COMPOSE_AMP_VAL(nid_vol, 1, 0,
HDA_OUTPUT));
if (err < 0)
return err;
err = via_add_control(spec, VIA_CTL_WIDGET_VOL,
"LFE Playback Volume",
HDA_COMPOSE_AMP_VAL(nid_vol, 2, 0,
HDA_OUTPUT));
if (err < 0)
return err;
err = via_add_control(spec, VIA_CTL_WIDGET_MUTE,
"Center Playback Switch",
HDA_COMPOSE_AMP_VAL(nid_vol, 1, 0,
HDA_OUTPUT));
if (err < 0)
return err;
err = via_add_control(spec, VIA_CTL_WIDGET_MUTE,
"LFE Playback Switch",
HDA_COMPOSE_AMP_VAL(nid_vol, 2, 0,
HDA_OUTPUT));
if (err < 0)
return err;
} else if (i == AUTO_SEQ_FRONT) {
err = via_add_control(spec, VIA_CTL_WIDGET_VOL,
"Master Front Playback Volume",
HDA_COMPOSE_AMP_VAL(nid_vol, 3, 0,
HDA_INPUT));
if (err < 0)
return err;
err = via_add_control(spec, VIA_CTL_WIDGET_MUTE,
"Master Front Playback Switch",
HDA_COMPOSE_AMP_VAL(nid_vol, 3, 0,
HDA_INPUT));
if (err < 0)
return err;
sprintf(name, "%s Playback Volume", chname[i]);
err = via_add_control(spec, VIA_CTL_WIDGET_VOL, name,
HDA_COMPOSE_AMP_VAL(nid, 3, 0,
HDA_OUTPUT));
if (err < 0)
return err;
sprintf(name, "%s Playback Switch", chname[i]);
err = via_add_control(spec, VIA_CTL_WIDGET_MUTE, name,
HDA_COMPOSE_AMP_VAL(nid, 3, 0,
HDA_OUTPUT));
if (err < 0)
return err;
} else if (i == AUTO_SEQ_SURROUND) {
sprintf(name, "%s Playback Volume", chname[i]);
err = via_add_control(spec, VIA_CTL_WIDGET_VOL, name,
HDA_COMPOSE_AMP_VAL(nid_vol, 3, 0,
HDA_OUTPUT));
if (err < 0)
return err;
sprintf(name, "%s Playback Switch", chname[i]);
err = via_add_control(spec, VIA_CTL_WIDGET_MUTE, name,
HDA_COMPOSE_AMP_VAL(nid_vol, 3, 0,
HDA_OUTPUT));
if (err < 0)
return err;
} else if (i == AUTO_SEQ_SIDE) {
sprintf(name, "%s Playback Volume", chname[i]);
err = via_add_control(spec, VIA_CTL_WIDGET_VOL, name,
HDA_COMPOSE_AMP_VAL(nid_vol, 3, 0,
HDA_OUTPUT));
if (err < 0)
return err;
sprintf(name, "%s Playback Switch", chname[i]);
err = via_add_control(spec, VIA_CTL_WIDGET_MUTE, name,
HDA_COMPOSE_AMP_VAL(nid_vol, 3, 0,
HDA_OUTPUT));
if (err < 0)
return err;
}
}
return 0;
}
static int vt1709_auto_create_hp_ctls(struct via_spec *spec, hda_nid_t pin)
{
int err;
if (!pin)
return 0;
if (spec->multiout.num_dacs == 5)
spec->multiout.hp_nid = VT1709_HP_DAC_NID;
else if (spec->multiout.num_dacs == 3)
spec->multiout.hp_nid = 0;
spec->hp_independent_mode_index = 1;
err = via_add_control(spec, VIA_CTL_WIDGET_VOL,
"Headphone Playback Volume",
HDA_COMPOSE_AMP_VAL(pin, 3, 0, HDA_OUTPUT));
if (err < 0)
return err;
err = via_add_control(spec, VIA_CTL_WIDGET_MUTE,
"Headphone Playback Switch",
HDA_COMPOSE_AMP_VAL(pin, 3, 0, HDA_OUTPUT));
if (err < 0)
return err;
return 0;
}
static int vt1709_auto_create_analog_input_ctls(struct hda_codec *codec,
const struct auto_pin_cfg *cfg)
{
static const hda_nid_t pin_idxs[] = { 0xff, 0x23, 0x1d, 0x1e, 0x21 };
return vt_auto_create_analog_input_ctls(codec, cfg, 0x18, pin_idxs,
ARRAY_SIZE(pin_idxs));
}
static int vt1709_parse_auto_config(struct hda_codec *codec)
{
struct via_spec *spec = codec->spec;
int err;
err = snd_hda_parse_pin_def_config(codec, &spec->autocfg, NULL);
if (err < 0)
return err;
err = vt1709_auto_fill_dac_nids(spec, &spec->autocfg);
if (err < 0)
return err;
if (!spec->autocfg.line_outs && !spec->autocfg.hp_pins[0])
return 0;
err = vt1709_auto_create_multi_out_ctls(spec, &spec->autocfg);
if (err < 0)
return err;
err = vt1709_auto_create_hp_ctls(spec, spec->autocfg.hp_pins[0]);
if (err < 0)
return err;
err = vt1709_auto_create_analog_input_ctls(codec, &spec->autocfg);
if (err < 0)
return err;
spec->multiout.max_channels = spec->multiout.num_dacs * 2;
if (spec->autocfg.dig_outs)
spec->multiout.dig_out_nid = VT1709_DIGOUT_NID;
spec->dig_in_pin = VT1709_DIGIN_PIN;
if (spec->autocfg.dig_in_pin)
spec->dig_in_nid = VT1709_DIGIN_NID;
if (spec->kctls.list)
spec->mixers[spec->num_mixers++] = spec->kctls.list;
spec->input_mux = &spec->private_imux[0];
if (spec->hp_mux)
via_hp_build(codec);
via_smart51_build(spec);
return 1;
}
static int patch_vt1709_10ch(struct hda_codec *codec)
{
struct via_spec *spec;
int err;
spec = via_new_spec(codec);
if (spec == NULL)
return -ENOMEM;
err = vt1709_parse_auto_config(codec);
if (err < 0) {
via_free(codec);
return err;
} else if (!err) {
printk(KERN_INFO "hda_codec: Cannot set up configuration. "
"Using genenic mode...\n");
}
spec->init_verbs[spec->num_iverbs++] = vt1709_10ch_volume_init_verbs;
spec->init_verbs[spec->num_iverbs++] = vt1709_uniwill_init_verbs;
spec->stream_name_analog = "VT1709 Analog";
spec->stream_analog_playback = &vt1709_10ch_pcm_analog_playback;
spec->stream_analog_capture = &vt1709_pcm_analog_capture;
spec->stream_name_digital = "VT1709 Digital";
spec->stream_digital_playback = &vt1709_pcm_digital_playback;
spec->stream_digital_capture = &vt1709_pcm_digital_capture;
if (!spec->adc_nids && spec->input_mux) {
spec->adc_nids = vt1709_adc_nids;
spec->num_adc_nids = ARRAY_SIZE(vt1709_adc_nids);
get_mux_nids(codec);
spec->mixers[spec->num_mixers] = vt1709_capture_mixer;
spec->num_mixers++;
}
codec->patch_ops = via_patch_ops;
codec->patch_ops.init = via_auto_init;
codec->patch_ops.unsol_event = via_unsol_event;
#ifdef CONFIG_SND_HDA_POWER_SAVE
spec->loopback.amplist = vt1709_loopbacks;
#endif
return 0;
}
static int patch_vt1709_6ch(struct hda_codec *codec)
{
struct via_spec *spec;
int err;
spec = via_new_spec(codec);
if (spec == NULL)
return -ENOMEM;
err = vt1709_parse_auto_config(codec);
if (err < 0) {
via_free(codec);
return err;
} else if (!err) {
printk(KERN_INFO "hda_codec: Cannot set up configuration. "
"Using genenic mode...\n");
}
spec->init_verbs[spec->num_iverbs++] = vt1709_6ch_volume_init_verbs;
spec->init_verbs[spec->num_iverbs++] = vt1709_uniwill_init_verbs;
spec->stream_name_analog = "VT1709 Analog";
spec->stream_analog_playback = &vt1709_6ch_pcm_analog_playback;
spec->stream_analog_capture = &vt1709_pcm_analog_capture;
spec->stream_name_digital = "VT1709 Digital";
spec->stream_digital_playback = &vt1709_pcm_digital_playback;
spec->stream_digital_capture = &vt1709_pcm_digital_capture;
if (!spec->adc_nids && spec->input_mux) {
spec->adc_nids = vt1709_adc_nids;
spec->num_adc_nids = ARRAY_SIZE(vt1709_adc_nids);
get_mux_nids(codec);
spec->mixers[spec->num_mixers] = vt1709_capture_mixer;
spec->num_mixers++;
}
codec->patch_ops = via_patch_ops;
codec->patch_ops.init = via_auto_init;
codec->patch_ops.unsol_event = via_unsol_event;
#ifdef CONFIG_SND_HDA_POWER_SAVE
spec->loopback.amplist = vt1709_loopbacks;
#endif
return 0;
}
static int via_pcm_open_close(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
struct snd_pcm_substream *substream)
{
int idle = substream->pstr->substream_opened == 1
&& substream->ref_count == 0;
analog_low_current_mode(codec, idle);
return 0;
}
static int vt1708B_auto_fill_dac_nids(struct via_spec *spec,
const struct auto_pin_cfg *cfg)
{
int i;
hda_nid_t nid;
spec->multiout.num_dacs = cfg->line_outs;
spec->multiout.dac_nids = spec->private_dac_nids;
for (i = 0; i < 4; i++) {
nid = cfg->line_out_pins[i];
if (nid) {
switch (i) {
case AUTO_SEQ_FRONT:
spec->private_dac_nids[i] = 0x10;
break;
case AUTO_SEQ_CENLFE:
spec->private_dac_nids[i] = 0x24;
break;
case AUTO_SEQ_SURROUND:
spec->private_dac_nids[i] = 0x11;
break;
case AUTO_SEQ_SIDE:
spec->private_dac_nids[i] = 0x25;
break;
}
}
}
return 0;
}
static int vt1708B_auto_create_multi_out_ctls(struct via_spec *spec,
const struct auto_pin_cfg *cfg)
{
char name[32];
static const char * const chname[4] = {
"Front", "Surround", "C/LFE", "Side"
};
hda_nid_t nid_vols[] = {0x16, 0x18, 0x26, 0x27};
hda_nid_t nid, nid_vol = 0;
int i, err;
for (i = 0; i <= AUTO_SEQ_SIDE; i++) {
nid = cfg->line_out_pins[i];
if (!nid)
continue;
nid_vol = nid_vols[i];
if (i == AUTO_SEQ_CENLFE) {
err = via_add_control(spec, VIA_CTL_WIDGET_VOL,
"Center Playback Volume",
HDA_COMPOSE_AMP_VAL(nid_vol, 1, 0,
HDA_OUTPUT));
if (err < 0)
return err;
err = via_add_control(spec, VIA_CTL_WIDGET_VOL,
"LFE Playback Volume",
HDA_COMPOSE_AMP_VAL(nid_vol, 2, 0,
HDA_OUTPUT));
if (err < 0)
return err;
err = via_add_control(spec, VIA_CTL_WIDGET_MUTE,
"Center Playback Switch",
HDA_COMPOSE_AMP_VAL(nid_vol, 1, 0,
HDA_OUTPUT));
if (err < 0)
return err;
err = via_add_control(spec, VIA_CTL_WIDGET_MUTE,
"LFE Playback Switch",
HDA_COMPOSE_AMP_VAL(nid_vol, 2, 0,
HDA_OUTPUT));
if (err < 0)
return err;
} else if (i == AUTO_SEQ_FRONT) {
err = via_add_control(spec, VIA_CTL_WIDGET_VOL,
"Master Front Playback Volume",
HDA_COMPOSE_AMP_VAL(nid_vol, 3, 0,
HDA_INPUT));
if (err < 0)
return err;
err = via_add_control(spec, VIA_CTL_WIDGET_MUTE,
"Master Front Playback Switch",
HDA_COMPOSE_AMP_VAL(nid_vol, 3, 0,
HDA_INPUT));
if (err < 0)
return err;
sprintf(name, "%s Playback Volume", chname[i]);
err = via_add_control(spec, VIA_CTL_WIDGET_VOL, name,
HDA_COMPOSE_AMP_VAL(nid, 3, 0,
HDA_OUTPUT));
if (err < 0)
return err;
sprintf(name, "%s Playback Switch", chname[i]);
err = via_add_control(spec, VIA_CTL_WIDGET_MUTE, name,
HDA_COMPOSE_AMP_VAL(nid, 3, 0,
HDA_OUTPUT));
if (err < 0)
return err;
} else {
sprintf(name, "%s Playback Volume", chname[i]);
err = via_add_control(spec, VIA_CTL_WIDGET_VOL, name,
HDA_COMPOSE_AMP_VAL(nid_vol, 3, 0,
HDA_OUTPUT));
if (err < 0)
return err;
sprintf(name, "%s Playback Switch", chname[i]);
err = via_add_control(spec, VIA_CTL_WIDGET_MUTE, name,
HDA_COMPOSE_AMP_VAL(nid_vol, 3, 0,
HDA_OUTPUT));
if (err < 0)
return err;
}
}
return 0;
}
static int vt1708B_auto_create_hp_ctls(struct via_spec *spec, hda_nid_t pin)
{
int err;
if (!pin)
return 0;
spec->multiout.hp_nid = VT1708B_HP_NID;
spec->hp_independent_mode_index = 1;
err = via_add_control(spec, VIA_CTL_WIDGET_VOL,
"Headphone Playback Volume",
HDA_COMPOSE_AMP_VAL(pin, 3, 0, HDA_OUTPUT));
if (err < 0)
return err;
err = via_add_control(spec, VIA_CTL_WIDGET_MUTE,
"Headphone Playback Switch",
HDA_COMPOSE_AMP_VAL(pin, 3, 0, HDA_OUTPUT));
if (err < 0)
return err;
create_hp_imux(spec);
return 0;
}
static int vt1708B_auto_create_analog_input_ctls(struct hda_codec *codec,
const struct auto_pin_cfg *cfg)
{
static const hda_nid_t pin_idxs[] = { 0xff, 0x1f, 0x1a, 0x1b, 0x1e };
return vt_auto_create_analog_input_ctls(codec, cfg, 0x16, pin_idxs,
ARRAY_SIZE(pin_idxs));
}
static int vt1708B_parse_auto_config(struct hda_codec *codec)
{
struct via_spec *spec = codec->spec;
int err;
err = snd_hda_parse_pin_def_config(codec, &spec->autocfg, NULL);
if (err < 0)
return err;
err = vt1708B_auto_fill_dac_nids(spec, &spec->autocfg);
if (err < 0)
return err;
if (!spec->autocfg.line_outs && !spec->autocfg.hp_pins[0])
return 0;
err = vt1708B_auto_create_multi_out_ctls(spec, &spec->autocfg);
if (err < 0)
return err;
err = vt1708B_auto_create_hp_ctls(spec, spec->autocfg.hp_pins[0]);
if (err < 0)
return err;
err = vt1708B_auto_create_analog_input_ctls(codec, &spec->autocfg);
if (err < 0)
return err;
spec->multiout.max_channels = spec->multiout.num_dacs * 2;
if (spec->autocfg.dig_outs)
spec->multiout.dig_out_nid = VT1708B_DIGOUT_NID;
spec->dig_in_pin = VT1708B_DIGIN_PIN;
if (spec->autocfg.dig_in_pin)
spec->dig_in_nid = VT1708B_DIGIN_NID;
if (spec->kctls.list)
spec->mixers[spec->num_mixers++] = spec->kctls.list;
spec->input_mux = &spec->private_imux[0];
if (spec->hp_mux)
via_hp_build(codec);
via_smart51_build(spec);
return 1;
}
static void set_widgets_power_state_vt1708B(struct hda_codec *codec)
{
struct via_spec *spec = codec->spec;
int imux_is_smixer;
unsigned int parm;
int is_8ch = 0;
if ((spec->codec_type != VT1708B_4CH) &&
(codec->vendor_id != 0x11064397))
is_8ch = 1;
imux_is_smixer =
(snd_hda_codec_read(codec, 0x17, 0, AC_VERB_GET_CONNECT_SEL, 0x00)
== ((spec->codec_type == VT1708S) ? 5 : 0));
parm = AC_PWRST_D3;
set_pin_power_state(codec, 0x1a, &parm);
set_pin_power_state(codec, 0x1b, &parm);
set_pin_power_state(codec, 0x1e, &parm);
if (imux_is_smixer)
parm = AC_PWRST_D0;
snd_hda_codec_write(codec, 0x17, 0, AC_VERB_SET_POWER_STATE, parm);
snd_hda_codec_write(codec, 0x13, 0, AC_VERB_SET_POWER_STATE, parm);
snd_hda_codec_write(codec, 0x14, 0, AC_VERB_SET_POWER_STATE, parm);
parm = AC_PWRST_D3;
set_pin_power_state(codec, 0x19, &parm);
if (spec->smart51_enabled)
set_pin_power_state(codec, 0x1b, &parm);
snd_hda_codec_write(codec, 0x18, 0, AC_VERB_SET_POWER_STATE, parm);
snd_hda_codec_write(codec, 0x11, 0, AC_VERB_SET_POWER_STATE, parm);
if (is_8ch) {
parm = AC_PWRST_D3;
set_pin_power_state(codec, 0x22, &parm);
if (spec->smart51_enabled)
set_pin_power_state(codec, 0x1a, &parm);
snd_hda_codec_write(codec, 0x26, 0,
AC_VERB_SET_POWER_STATE, parm);
snd_hda_codec_write(codec, 0x24, 0,
AC_VERB_SET_POWER_STATE, parm);
} else if (codec->vendor_id == 0x11064397) {
parm = AC_PWRST_D3;
set_pin_power_state(codec, 0x23, &parm);
if (spec->smart51_enabled)
set_pin_power_state(codec, 0x1a, &parm);
snd_hda_codec_write(codec, 0x27, 0,
AC_VERB_SET_POWER_STATE, parm);
snd_hda_codec_write(codec, 0x25, 0,
AC_VERB_SET_POWER_STATE, parm);
}
parm = AC_PWRST_D3;
set_pin_power_state(codec, 0x1c, &parm);
set_pin_power_state(codec, 0x1d, &parm);
if (is_8ch)
set_pin_power_state(codec, 0x23, &parm);
snd_hda_codec_write(codec, 0x16, 0, AC_VERB_SET_POWER_STATE,
imux_is_smixer ? AC_PWRST_D0 : parm);
snd_hda_codec_write(codec, 0x10, 0, AC_VERB_SET_POWER_STATE, parm);
if (is_8ch) {
snd_hda_codec_write(codec, 0x25, 0,
AC_VERB_SET_POWER_STATE, parm);
snd_hda_codec_write(codec, 0x27, 0,
AC_VERB_SET_POWER_STATE, parm);
} else if (codec->vendor_id == 0x11064397 && spec->hp_independent_mode)
snd_hda_codec_write(codec, 0x25, 0,
AC_VERB_SET_POWER_STATE, parm);
}
static int patch_vt1708B_8ch(struct hda_codec *codec)
{
struct via_spec *spec;
int err;
if (get_codec_type(codec) == VT1708BCE)
return patch_vt1708S(codec);
spec = via_new_spec(codec);
if (spec == NULL)
return -ENOMEM;
err = vt1708B_parse_auto_config(codec);
if (err < 0) {
via_free(codec);
return err;
} else if (!err) {
printk(KERN_INFO "hda_codec: Cannot set up configuration "
"from BIOS. Using genenic mode...\n");
}
spec->init_verbs[spec->num_iverbs++] = vt1708B_8ch_volume_init_verbs;
spec->init_verbs[spec->num_iverbs++] = vt1708B_uniwill_init_verbs;
spec->stream_name_analog = "VT1708B Analog";
spec->stream_analog_playback = &vt1708B_8ch_pcm_analog_playback;
spec->stream_analog_capture = &vt1708B_pcm_analog_capture;
spec->stream_name_digital = "VT1708B Digital";
spec->stream_digital_playback = &vt1708B_pcm_digital_playback;
spec->stream_digital_capture = &vt1708B_pcm_digital_capture;
if (!spec->adc_nids && spec->input_mux) {
spec->adc_nids = vt1708B_adc_nids;
spec->num_adc_nids = ARRAY_SIZE(vt1708B_adc_nids);
get_mux_nids(codec);
spec->mixers[spec->num_mixers] = vt1708B_capture_mixer;
spec->num_mixers++;
}
codec->patch_ops = via_patch_ops;
codec->patch_ops.init = via_auto_init;
codec->patch_ops.unsol_event = via_unsol_event;
#ifdef CONFIG_SND_HDA_POWER_SAVE
spec->loopback.amplist = vt1708B_loopbacks;
#endif
spec->set_widgets_power_state = set_widgets_power_state_vt1708B;
return 0;
}
static int patch_vt1708B_4ch(struct hda_codec *codec)
{
struct via_spec *spec;
int err;
spec = via_new_spec(codec);
if (spec == NULL)
return -ENOMEM;
err = vt1708B_parse_auto_config(codec);
if (err < 0) {
via_free(codec);
return err;
} else if (!err) {
printk(KERN_INFO "hda_codec: Cannot set up configuration "
"from BIOS. Using genenic mode...\n");
}
spec->init_verbs[spec->num_iverbs++] = vt1708B_4ch_volume_init_verbs;
spec->init_verbs[spec->num_iverbs++] = vt1708B_uniwill_init_verbs;
spec->stream_name_analog = "VT1708B Analog";
spec->stream_analog_playback = &vt1708B_4ch_pcm_analog_playback;
spec->stream_analog_capture = &vt1708B_pcm_analog_capture;
spec->stream_name_digital = "VT1708B Digital";
spec->stream_digital_playback = &vt1708B_pcm_digital_playback;
spec->stream_digital_capture = &vt1708B_pcm_digital_capture;
if (!spec->adc_nids && spec->input_mux) {
spec->adc_nids = vt1708B_adc_nids;
spec->num_adc_nids = ARRAY_SIZE(vt1708B_adc_nids);
get_mux_nids(codec);
spec->mixers[spec->num_mixers] = vt1708B_capture_mixer;
spec->num_mixers++;
}
codec->patch_ops = via_patch_ops;
codec->patch_ops.init = via_auto_init;
codec->patch_ops.unsol_event = via_unsol_event;
#ifdef CONFIG_SND_HDA_POWER_SAVE
spec->loopback.amplist = vt1708B_loopbacks;
#endif
spec->set_widgets_power_state = set_widgets_power_state_vt1708B;
return 0;
}
static int vt1708S_auto_fill_dac_nids(struct via_spec *spec,
const struct auto_pin_cfg *cfg)
{
int i;
hda_nid_t nid;
spec->multiout.num_dacs = cfg->line_outs;
spec->multiout.dac_nids = spec->private_dac_nids;
for (i = 0; i < 4; i++) {
nid = cfg->line_out_pins[i];
if (nid) {
switch (i) {
case AUTO_SEQ_FRONT:
spec->private_dac_nids[i] = 0x10;
break;
case AUTO_SEQ_CENLFE:
if (spec->codec->vendor_id == 0x11064397)
spec->private_dac_nids[i] = 0x25;
else
spec->private_dac_nids[i] = 0x24;
break;
case AUTO_SEQ_SURROUND:
spec->private_dac_nids[i] = 0x11;
break;
case AUTO_SEQ_SIDE:
spec->private_dac_nids[i] = 0x25;
break;
}
}
}
if (cfg->line_outs == 1) {
spec->multiout.num_dacs = 3;
spec->private_dac_nids[AUTO_SEQ_SURROUND] = 0x11;
if (spec->codec->vendor_id == 0x11064397)
spec->private_dac_nids[AUTO_SEQ_CENLFE] = 0x25;
else
spec->private_dac_nids[AUTO_SEQ_CENLFE] = 0x24;
}
return 0;
}
static int vt1708S_auto_create_multi_out_ctls(struct hda_codec *codec,
const struct auto_pin_cfg *cfg)
{
struct via_spec *spec = codec->spec;
char name[32];
static const char * const chname[4] = {
"Front", "Surround", "C/LFE", "Side"
};
hda_nid_t nid_vols[2][4] = { {0x10, 0x11, 0x24, 0x25},
{0x10, 0x11, 0x25, 0} };
hda_nid_t nid_mutes[2][4] = { {0x1C, 0x18, 0x26, 0x27},
{0x1C, 0x18, 0x27, 0} };
hda_nid_t nid, nid_vol, nid_mute;
int i, err;
for (i = 0; i <= AUTO_SEQ_SIDE; i++) {
nid = cfg->line_out_pins[i];
if (!nid && i > AUTO_SEQ_CENLFE)
continue;
if (codec->vendor_id == 0x11064397) {
nid_vol = nid_vols[1][i];
nid_mute = nid_mutes[1][i];
} else {
nid_vol = nid_vols[0][i];
nid_mute = nid_mutes[0][i];
}
if (!nid_vol && !nid_mute)
continue;
if (i == AUTO_SEQ_CENLFE) {
err = via_add_control(spec, VIA_CTL_WIDGET_VOL,
"Center Playback Volume",
HDA_COMPOSE_AMP_VAL(nid_vol, 1, 0,
HDA_OUTPUT));
if (err < 0)
return err;
err = via_add_control(spec, VIA_CTL_WIDGET_VOL,
"LFE Playback Volume",
HDA_COMPOSE_AMP_VAL(nid_vol, 2, 0,
HDA_OUTPUT));
if (err < 0)
return err;
err = via_add_control(spec, VIA_CTL_WIDGET_MUTE,
"Center Playback Switch",
HDA_COMPOSE_AMP_VAL(nid_mute,
1, 0,
HDA_OUTPUT));
if (err < 0)
return err;
err = via_add_control(spec, VIA_CTL_WIDGET_MUTE,
"LFE Playback Switch",
HDA_COMPOSE_AMP_VAL(nid_mute,
2, 0,
HDA_OUTPUT));
if (err < 0)
return err;
} else if (i == AUTO_SEQ_FRONT) {
err = via_add_control(spec, VIA_CTL_WIDGET_VOL,
"Master Front Playback Volume",
HDA_COMPOSE_AMP_VAL(0x16, 3, 0,
HDA_INPUT));
if (err < 0)
return err;
err = via_add_control(spec, VIA_CTL_WIDGET_MUTE,
"Master Front Playback Switch",
HDA_COMPOSE_AMP_VAL(0x16, 3, 0,
HDA_INPUT));
if (err < 0)
return err;
sprintf(name, "%s Playback Volume", chname[i]);
err = via_add_control(spec, VIA_CTL_WIDGET_VOL, name,
HDA_COMPOSE_AMP_VAL(nid_vol, 3, 0,
HDA_OUTPUT));
if (err < 0)
return err;
sprintf(name, "%s Playback Switch", chname[i]);
err = via_add_control(spec, VIA_CTL_WIDGET_MUTE, name,
HDA_COMPOSE_AMP_VAL(nid_mute,
3, 0,
HDA_OUTPUT));
if (err < 0)
return err;
} else {
sprintf(name, "%s Playback Volume", chname[i]);
err = via_add_control(spec, VIA_CTL_WIDGET_VOL, name,
HDA_COMPOSE_AMP_VAL(nid_vol, 3, 0,
HDA_OUTPUT));
if (err < 0)
return err;
sprintf(name, "%s Playback Switch", chname[i]);
err = via_add_control(spec, VIA_CTL_WIDGET_MUTE, name,
HDA_COMPOSE_AMP_VAL(nid_mute,
3, 0,
HDA_OUTPUT));
if (err < 0)
return err;
}
}
return 0;
}
static int vt1708S_auto_create_hp_ctls(struct via_spec *spec, hda_nid_t pin)
{
int err;
if (!pin)
return 0;
spec->multiout.hp_nid = VT1708S_HP_NID;
spec->hp_independent_mode_index = 1;
err = via_add_control(spec, VIA_CTL_WIDGET_VOL,
"Headphone Playback Volume",
HDA_COMPOSE_AMP_VAL(0x25, 3, 0, HDA_OUTPUT));
if (err < 0)
return err;
err = via_add_control(spec, VIA_CTL_WIDGET_MUTE,
"Headphone Playback Switch",
HDA_COMPOSE_AMP_VAL(pin, 3, 0, HDA_OUTPUT));
if (err < 0)
return err;
create_hp_imux(spec);
return 0;
}
static int vt1708S_auto_create_analog_input_ctls(struct hda_codec *codec,
const struct auto_pin_cfg *cfg)
{
static const hda_nid_t pin_idxs[] = { 0x1f, 0x1a, 0x1b, 0x1e, 0, 0xff };
return vt_auto_create_analog_input_ctls(codec, cfg, 0x16, pin_idxs,
ARRAY_SIZE(pin_idxs));
}
static void fill_dig_outs(struct hda_codec *codec)
{
struct via_spec *spec = codec->spec;
int i;
for (i = 0; i < spec->autocfg.dig_outs; i++) {
hda_nid_t nid;
int conn;
nid = spec->autocfg.dig_out_pins[i];
if (!nid)
continue;
conn = snd_hda_get_connections(codec, nid, &nid, 1);
if (conn < 1)
continue;
if (!spec->multiout.dig_out_nid)
spec->multiout.dig_out_nid = nid;
else {
spec->slave_dig_outs[0] = nid;
break;
}
}
}
static int vt1708S_parse_auto_config(struct hda_codec *codec)
{
struct via_spec *spec = codec->spec;
int err;
err = snd_hda_parse_pin_def_config(codec, &spec->autocfg, NULL);
if (err < 0)
return err;
err = vt1708S_auto_fill_dac_nids(spec, &spec->autocfg);
if (err < 0)
return err;
if (!spec->autocfg.line_outs && !spec->autocfg.hp_pins[0])
return 0;
err = vt1708S_auto_create_multi_out_ctls(codec, &spec->autocfg);
if (err < 0)
return err;
err = vt1708S_auto_create_hp_ctls(spec, spec->autocfg.hp_pins[0]);
if (err < 0)
return err;
err = vt1708S_auto_create_analog_input_ctls(codec, &spec->autocfg);
if (err < 0)
return err;
spec->multiout.max_channels = spec->multiout.num_dacs * 2;
fill_dig_outs(codec);
if (spec->kctls.list)
spec->mixers[spec->num_mixers++] = spec->kctls.list;
spec->input_mux = &spec->private_imux[0];
if (spec->hp_mux)
via_hp_build(codec);
via_smart51_build(spec);
return 1;
}
static void override_mic_boost(struct hda_codec *codec, hda_nid_t pin,
int offset, int num_steps, int step_size)
{
snd_hda_override_amp_caps(codec, pin, HDA_INPUT,
(offset << AC_AMPCAP_OFFSET_SHIFT) |
(num_steps << AC_AMPCAP_NUM_STEPS_SHIFT) |
(step_size << AC_AMPCAP_STEP_SIZE_SHIFT) |
(0 << AC_AMPCAP_MUTE_SHIFT));
}
static int patch_vt1708S(struct hda_codec *codec)
{
struct via_spec *spec;
int err;
spec = via_new_spec(codec);
if (spec == NULL)
return -ENOMEM;
err = vt1708S_parse_auto_config(codec);
if (err < 0) {
via_free(codec);
return err;
} else if (!err) {
printk(KERN_INFO "hda_codec: Cannot set up configuration "
"from BIOS. Using genenic mode...\n");
}
spec->init_verbs[spec->num_iverbs++] = vt1708S_volume_init_verbs;
if (codec->vendor_id == 0x11064397)
spec->init_verbs[spec->num_iverbs++] =
vt1705_uniwill_init_verbs;
else
spec->init_verbs[spec->num_iverbs++] =
vt1708S_uniwill_init_verbs;
if (codec->vendor_id == 0x11060440)
spec->stream_name_analog = "VT1818S Analog";
else if (codec->vendor_id == 0x11064397)
spec->stream_name_analog = "VT1705 Analog";
else
spec->stream_name_analog = "VT1708S Analog";
if (codec->vendor_id == 0x11064397)
spec->stream_analog_playback = &vt1705_pcm_analog_playback;
else
spec->stream_analog_playback = &vt1708S_pcm_analog_playback;
spec->stream_analog_capture = &vt1708S_pcm_analog_capture;
if (codec->vendor_id == 0x11060440)
spec->stream_name_digital = "VT1818S Digital";
else if (codec->vendor_id == 0x11064397)
spec->stream_name_digital = "VT1705 Digital";
else
spec->stream_name_digital = "VT1708S Digital";
spec->stream_digital_playback = &vt1708S_pcm_digital_playback;
if (!spec->adc_nids && spec->input_mux) {
spec->adc_nids = vt1708S_adc_nids;
spec->num_adc_nids = ARRAY_SIZE(vt1708S_adc_nids);
get_mux_nids(codec);
override_mic_boost(codec, 0x1a, 0, 3, 40);
override_mic_boost(codec, 0x1e, 0, 3, 40);
spec->mixers[spec->num_mixers] = vt1708S_capture_mixer;
spec->num_mixers++;
}
codec->patch_ops = via_patch_ops;
codec->patch_ops.init = via_auto_init;
codec->patch_ops.unsol_event = via_unsol_event;
#ifdef CONFIG_SND_HDA_POWER_SAVE
spec->loopback.amplist = vt1708S_loopbacks;
#endif
if (get_codec_type(codec) == VT1708BCE) {
kfree(codec->chip_name);
codec->chip_name = kstrdup("VT1708BCE", GFP_KERNEL);
snprintf(codec->bus->card->mixername,
sizeof(codec->bus->card->mixername),
"%s %s", codec->vendor_name, codec->chip_name);
spec->stream_name_analog = "VT1708BCE Analog";
spec->stream_name_digital = "VT1708BCE Digital";
}
if (codec->vendor_id == 0x11060440) {
spec->stream_name_analog = "VT1818S Analog";
spec->stream_name_digital = "VT1818S Digital";
}
if (codec->vendor_id == 0x11064397) {
kfree(codec->chip_name);
codec->chip_name = kstrdup("VT1705", GFP_KERNEL);
snprintf(codec->bus->card->mixername,
sizeof(codec->bus->card->mixername),
"%s %s", codec->vendor_name, codec->chip_name);
}
spec->set_widgets_power_state = set_widgets_power_state_vt1708B;
return 0;
}
static int vt1702_auto_fill_dac_nids(struct via_spec *spec,
const struct auto_pin_cfg *cfg)
{
spec->multiout.num_dacs = 1;
spec->multiout.dac_nids = spec->private_dac_nids;
if (cfg->line_out_pins[0]) {
spec->private_dac_nids[0] = 0x10;
}
return 0;
}
static int vt1702_auto_create_line_out_ctls(struct via_spec *spec,
const struct auto_pin_cfg *cfg)
{
int err;
if (!cfg->line_out_pins[0])
return -1;
err = via_add_control(spec, VIA_CTL_WIDGET_VOL,
"Master Front Playback Volume",
HDA_COMPOSE_AMP_VAL(0x1A, 3, 0, HDA_INPUT));
if (err < 0)
return err;
err = via_add_control(spec, VIA_CTL_WIDGET_MUTE,
"Master Front Playback Switch",
HDA_COMPOSE_AMP_VAL(0x1A, 3, 0, HDA_INPUT));
if (err < 0)
return err;
err = via_add_control(spec, VIA_CTL_WIDGET_VOL,
"Front Playback Volume",
HDA_COMPOSE_AMP_VAL(0x10, 3, 0, HDA_OUTPUT));
if (err < 0)
return err;
err = via_add_control(spec, VIA_CTL_WIDGET_MUTE,
"Front Playback Switch",
HDA_COMPOSE_AMP_VAL(0x16, 3, 0, HDA_OUTPUT));
if (err < 0)
return err;
return 0;
}
static int vt1702_auto_create_hp_ctls(struct via_spec *spec, hda_nid_t pin)
{
int err, i;
struct hda_input_mux *imux;
static const char * const texts[] = { "ON", "OFF", NULL};
if (!pin)
return 0;
spec->multiout.hp_nid = 0x1D;
spec->hp_independent_mode_index = 0;
err = via_add_control(spec, VIA_CTL_WIDGET_VOL,
"Headphone Playback Volume",
HDA_COMPOSE_AMP_VAL(0x1D, 3, 0, HDA_OUTPUT));
if (err < 0)
return err;
err = via_add_control(spec, VIA_CTL_WIDGET_MUTE,
"Headphone Playback Switch",
HDA_COMPOSE_AMP_VAL(pin, 3, 0, HDA_OUTPUT));
if (err < 0)
return err;
imux = &spec->private_imux[1];
for (i = 0; texts[i]; i++)
snd_hda_add_imux_item(imux, texts[i], i, NULL);
spec->hp_mux = &spec->private_imux[1];
return 0;
}
static int vt1702_auto_create_analog_input_ctls(struct hda_codec *codec,
const struct auto_pin_cfg *cfg)
{
static const hda_nid_t pin_idxs[] = { 0x14, 0x15, 0x18, 0xff };
return vt_auto_create_analog_input_ctls(codec, cfg, 0x1a, pin_idxs,
ARRAY_SIZE(pin_idxs));
}
static int vt1702_parse_auto_config(struct hda_codec *codec)
{
struct via_spec *spec = codec->spec;
int err;
err = snd_hda_parse_pin_def_config(codec, &spec->autocfg, NULL);
if (err < 0)
return err;
err = vt1702_auto_fill_dac_nids(spec, &spec->autocfg);
if (err < 0)
return err;
if (!spec->autocfg.line_outs && !spec->autocfg.hp_pins[0])
return 0;
err = vt1702_auto_create_line_out_ctls(spec, &spec->autocfg);
if (err < 0)
return err;
err = vt1702_auto_create_hp_ctls(spec, spec->autocfg.hp_pins[0]);
if (err < 0)
return err;
snd_hda_override_amp_caps(codec, 0x1A, HDA_INPUT,
(0x17 << AC_AMPCAP_OFFSET_SHIFT) |
(0x17 << AC_AMPCAP_NUM_STEPS_SHIFT) |
(0x5 << AC_AMPCAP_STEP_SIZE_SHIFT) |
(1 << AC_AMPCAP_MUTE_SHIFT));
err = vt1702_auto_create_analog_input_ctls(codec, &spec->autocfg);
if (err < 0)
return err;
spec->multiout.max_channels = spec->multiout.num_dacs * 2;
fill_dig_outs(codec);
if (spec->kctls.list)
spec->mixers[spec->num_mixers++] = spec->kctls.list;
spec->input_mux = &spec->private_imux[0];
if (spec->hp_mux)
via_hp_build(codec);
return 1;
}
static void set_widgets_power_state_vt1702(struct hda_codec *codec)
{
int imux_is_smixer =
snd_hda_codec_read(codec, 0x13, 0, AC_VERB_GET_CONNECT_SEL, 0x00) == 3;
unsigned int parm;
parm = AC_PWRST_D3;
set_pin_power_state(codec, 0x14, &parm);
set_pin_power_state(codec, 0x15, &parm);
set_pin_power_state(codec, 0x18, &parm);
if (imux_is_smixer)
parm = AC_PWRST_D0;
snd_hda_codec_write(codec, 0x13, 0, AC_VERB_SET_POWER_STATE, parm);
snd_hda_codec_write(codec, 0x12, 0, AC_VERB_SET_POWER_STATE, parm);
snd_hda_codec_write(codec, 0x1f, 0, AC_VERB_SET_POWER_STATE, parm);
snd_hda_codec_write(codec, 0x20, 0, AC_VERB_SET_POWER_STATE, parm);
parm = AC_PWRST_D3;
set_pin_power_state(codec, 0x17, &parm);
set_pin_power_state(codec, 0x16, &parm);
snd_hda_codec_write(codec, 0x1a, 0, AC_VERB_SET_POWER_STATE,
imux_is_smixer ? AC_PWRST_D0 : parm);
snd_hda_codec_write(codec, 0x10, 0, AC_VERB_SET_POWER_STATE, parm);
snd_hda_codec_write(codec, 0x1d, 0, AC_VERB_SET_POWER_STATE, parm);
}
static int patch_vt1702(struct hda_codec *codec)
{
struct via_spec *spec;
int err;
spec = via_new_spec(codec);
if (spec == NULL)
return -ENOMEM;
err = vt1702_parse_auto_config(codec);
if (err < 0) {
via_free(codec);
return err;
} else if (!err) {
printk(KERN_INFO "hda_codec: Cannot set up configuration "
"from BIOS. Using genenic mode...\n");
}
spec->init_verbs[spec->num_iverbs++] = vt1702_volume_init_verbs;
spec->init_verbs[spec->num_iverbs++] = vt1702_uniwill_init_verbs;
spec->stream_name_analog = "VT1702 Analog";
spec->stream_analog_playback = &vt1702_pcm_analog_playback;
spec->stream_analog_capture = &vt1702_pcm_analog_capture;
spec->stream_name_digital = "VT1702 Digital";
spec->stream_digital_playback = &vt1702_pcm_digital_playback;
if (!spec->adc_nids && spec->input_mux) {
spec->adc_nids = vt1702_adc_nids;
spec->num_adc_nids = ARRAY_SIZE(vt1702_adc_nids);
get_mux_nids(codec);
spec->mixers[spec->num_mixers] = vt1702_capture_mixer;
spec->num_mixers++;
}
codec->patch_ops = via_patch_ops;
codec->patch_ops.init = via_auto_init;
codec->patch_ops.unsol_event = via_unsol_event;
#ifdef CONFIG_SND_HDA_POWER_SAVE
spec->loopback.amplist = vt1702_loopbacks;
#endif
spec->set_widgets_power_state = set_widgets_power_state_vt1702;
return 0;
}
static int vt1718S_auto_fill_dac_nids(struct via_spec *spec,
const struct auto_pin_cfg *cfg)
{
int i;
hda_nid_t nid;
spec->multiout.num_dacs = cfg->line_outs;
spec->multiout.dac_nids = spec->private_dac_nids;
for (i = 0; i < 4; i++) {
nid = cfg->line_out_pins[i];
if (nid) {
switch (i) {
case AUTO_SEQ_FRONT:
spec->private_dac_nids[i] = 0x8;
break;
case AUTO_SEQ_CENLFE:
spec->private_dac_nids[i] = 0xa;
break;
case AUTO_SEQ_SURROUND:
spec->private_dac_nids[i] = 0x9;
break;
case AUTO_SEQ_SIDE:
spec->private_dac_nids[i] = 0xb;
break;
}
}
}
return 0;
}
static int vt1718S_auto_create_multi_out_ctls(struct via_spec *spec,
const struct auto_pin_cfg *cfg)
{
char name[32];
static const char * const chname[4] = {
"Front", "Surround", "C/LFE", "Side"
};
hda_nid_t nid_vols[] = {0x8, 0x9, 0xa, 0xb};
hda_nid_t nid_mutes[] = {0x24, 0x25, 0x26, 0x27};
hda_nid_t nid, nid_vol, nid_mute = 0;
int i, err;
for (i = 0; i <= AUTO_SEQ_SIDE; i++) {
nid = cfg->line_out_pins[i];
if (!nid)
continue;
nid_vol = nid_vols[i];
nid_mute = nid_mutes[i];
if (i == AUTO_SEQ_CENLFE) {
err = via_add_control(spec, VIA_CTL_WIDGET_VOL,
"Center Playback Volume",
HDA_COMPOSE_AMP_VAL(nid_vol, 1, 0,
HDA_OUTPUT));
if (err < 0)
return err;
err = via_add_control(spec, VIA_CTL_WIDGET_VOL,
"LFE Playback Volume",
HDA_COMPOSE_AMP_VAL(nid_vol, 2, 0,
HDA_OUTPUT));
if (err < 0)
return err;
err = via_add_control(
spec, VIA_CTL_WIDGET_MUTE,
"Center Playback Switch",
HDA_COMPOSE_AMP_VAL(nid_mute, 1, 0,
HDA_OUTPUT));
if (err < 0)
return err;
err = via_add_control(
spec, VIA_CTL_WIDGET_MUTE,
"LFE Playback Switch",
HDA_COMPOSE_AMP_VAL(nid_mute, 2, 0,
HDA_OUTPUT));
if (err < 0)
return err;
} else if (i == AUTO_SEQ_FRONT) {
err = via_add_control(spec, VIA_CTL_WIDGET_VOL,
"Master Front Playback Volume",
HDA_COMPOSE_AMP_VAL(0x21, 3, 5,
HDA_INPUT));
if (err < 0)
return err;
err = via_add_control(spec, VIA_CTL_WIDGET_MUTE,
"Master Front Playback Switch",
HDA_COMPOSE_AMP_VAL(0x21, 3, 5,
HDA_INPUT));
if (err < 0)
return err;
sprintf(name, "%s Playback Volume", chname[i]);
err = via_add_control(
spec, VIA_CTL_WIDGET_VOL, name,
HDA_COMPOSE_AMP_VAL(nid_vol, 3, 0, HDA_OUTPUT));
if (err < 0)
return err;
sprintf(name, "%s Playback Switch", chname[i]);
err = via_add_control(
spec, VIA_CTL_WIDGET_MUTE, name,
HDA_COMPOSE_AMP_VAL(nid_mute, 3, 0,
HDA_OUTPUT));
if (err < 0)
return err;
} else {
sprintf(name, "%s Playback Volume", chname[i]);
err = via_add_control(
spec, VIA_CTL_WIDGET_VOL, name,
HDA_COMPOSE_AMP_VAL(nid_vol, 3, 0, HDA_OUTPUT));
if (err < 0)
return err;
sprintf(name, "%s Playback Switch", chname[i]);
err = via_add_control(
spec, VIA_CTL_WIDGET_MUTE, name,
HDA_COMPOSE_AMP_VAL(nid_mute, 3, 0,
HDA_OUTPUT));
if (err < 0)
return err;
}
}
return 0;
}
static int vt1718S_auto_create_hp_ctls(struct via_spec *spec, hda_nid_t pin)
{
int err;
if (!pin)
return 0;
spec->multiout.hp_nid = 0xc;
spec->hp_independent_mode_index = 1;
err = via_add_control(spec, VIA_CTL_WIDGET_VOL,
"Headphone Playback Volume",
HDA_COMPOSE_AMP_VAL(0xc, 3, 0, HDA_OUTPUT));
if (err < 0)
return err;
err = via_add_control(spec, VIA_CTL_WIDGET_MUTE,
"Headphone Playback Switch",
HDA_COMPOSE_AMP_VAL(pin, 3, 0, HDA_OUTPUT));
if (err < 0)
return err;
create_hp_imux(spec);
return 0;
}
static int vt1718S_auto_create_analog_input_ctls(struct hda_codec *codec,
const struct auto_pin_cfg *cfg)
{
static const hda_nid_t pin_idxs[] = { 0x2c, 0x2b, 0x2a, 0x29, 0, 0xff };
return vt_auto_create_analog_input_ctls(codec, cfg, 0x21, pin_idxs,
ARRAY_SIZE(pin_idxs));
}
static int vt1718S_parse_auto_config(struct hda_codec *codec)
{
struct via_spec *spec = codec->spec;
int err;
err = snd_hda_parse_pin_def_config(codec, &spec->autocfg, NULL);
if (err < 0)
return err;
err = vt1718S_auto_fill_dac_nids(spec, &spec->autocfg);
if (err < 0)
return err;
if (!spec->autocfg.line_outs && !spec->autocfg.hp_pins[0])
return 0;
err = vt1718S_auto_create_multi_out_ctls(spec, &spec->autocfg);
if (err < 0)
return err;
err = vt1718S_auto_create_hp_ctls(spec, spec->autocfg.hp_pins[0]);
if (err < 0)
return err;
err = vt1718S_auto_create_analog_input_ctls(codec, &spec->autocfg);
if (err < 0)
return err;
spec->multiout.max_channels = spec->multiout.num_dacs * 2;
fill_dig_outs(codec);
if (spec->autocfg.dig_in_pin && codec->vendor_id == 0x11060428)
spec->dig_in_nid = 0x13;
if (spec->kctls.list)
spec->mixers[spec->num_mixers++] = spec->kctls.list;
spec->input_mux = &spec->private_imux[0];
if (spec->hp_mux)
via_hp_build(codec);
via_smart51_build(spec);
return 1;
}
static void set_widgets_power_state_vt1718S(struct hda_codec *codec)
{
struct via_spec *spec = codec->spec;
int imux_is_smixer;
unsigned int parm;
imux_is_smixer =
snd_hda_codec_read(codec, 0x1e, 0, AC_VERB_GET_CONNECT_SEL, 0x00) == 5;
parm = AC_PWRST_D3;
set_pin_power_state(codec, 0x29, &parm);
set_pin_power_state(codec, 0x2a, &parm);
set_pin_power_state(codec, 0x2b, &parm);
if (imux_is_smixer)
parm = AC_PWRST_D0;
snd_hda_codec_write(codec, 0x1e, 0, AC_VERB_SET_POWER_STATE, parm);
snd_hda_codec_write(codec, 0x1f, 0, AC_VERB_SET_POWER_STATE, parm);
snd_hda_codec_write(codec, 0x10, 0, AC_VERB_SET_POWER_STATE, parm);
snd_hda_codec_write(codec, 0x11, 0, AC_VERB_SET_POWER_STATE, parm);
parm = AC_PWRST_D3;
set_pin_power_state(codec, 0x27, &parm);
snd_hda_codec_write(codec, 0x1a, 0, AC_VERB_SET_POWER_STATE, parm);
snd_hda_codec_write(codec, 0xb, 0, AC_VERB_SET_POWER_STATE, parm);
parm = AC_PWRST_D3;
set_pin_power_state(codec, 0x26, &parm);
if (spec->smart51_enabled)
set_pin_power_state(codec, 0x2b, &parm);
snd_hda_codec_write(codec, 0xa, 0, AC_VERB_SET_POWER_STATE, parm);
parm = AC_PWRST_D3;
set_pin_power_state(codec, 0x24, &parm);
if (!spec->hp_independent_mode)
set_pin_power_state(codec, 0x28, &parm);
snd_hda_codec_write(codec, 0x8, 0, AC_VERB_SET_POWER_STATE, parm);
snd_hda_codec_write(codec, 0x21, 0, AC_VERB_SET_POWER_STATE,
imux_is_smixer ? AC_PWRST_D0 : parm);
parm = AC_PWRST_D3;
set_pin_power_state(codec, 0x25, &parm);
if (spec->smart51_enabled)
set_pin_power_state(codec, 0x2a, &parm);
snd_hda_codec_write(codec, 0x9, 0, AC_VERB_SET_POWER_STATE, parm);
if (spec->hp_independent_mode) {
parm = AC_PWRST_D3;
set_pin_power_state(codec, 0x28, &parm);
snd_hda_codec_write(codec, 0x1b, 0,
AC_VERB_SET_POWER_STATE, parm);
snd_hda_codec_write(codec, 0x34, 0,
AC_VERB_SET_POWER_STATE, parm);
snd_hda_codec_write(codec, 0xc, 0,
AC_VERB_SET_POWER_STATE, parm);
}
}
static int patch_vt1718S(struct hda_codec *codec)
{
struct via_spec *spec;
int err;
spec = via_new_spec(codec);
if (spec == NULL)
return -ENOMEM;
err = vt1718S_parse_auto_config(codec);
if (err < 0) {
via_free(codec);
return err;
} else if (!err) {
printk(KERN_INFO "hda_codec: Cannot set up configuration "
"from BIOS. Using genenic mode...\n");
}
spec->init_verbs[spec->num_iverbs++] = vt1718S_volume_init_verbs;
spec->init_verbs[spec->num_iverbs++] = vt1718S_uniwill_init_verbs;
if (codec->vendor_id == 0x11060441)
spec->stream_name_analog = "VT2020 Analog";
else if (codec->vendor_id == 0x11064441)
spec->stream_name_analog = "VT1828S Analog";
else
spec->stream_name_analog = "VT1718S Analog";
spec->stream_analog_playback = &vt1718S_pcm_analog_playback;
spec->stream_analog_capture = &vt1718S_pcm_analog_capture;
if (codec->vendor_id == 0x11060441)
spec->stream_name_digital = "VT2020 Digital";
else if (codec->vendor_id == 0x11064441)
spec->stream_name_digital = "VT1828S Digital";
else
spec->stream_name_digital = "VT1718S Digital";
spec->stream_digital_playback = &vt1718S_pcm_digital_playback;
if (codec->vendor_id == 0x11060428 || codec->vendor_id == 0x11060441)
spec->stream_digital_capture = &vt1718S_pcm_digital_capture;
if (!spec->adc_nids && spec->input_mux) {
spec->adc_nids = vt1718S_adc_nids;
spec->num_adc_nids = ARRAY_SIZE(vt1718S_adc_nids);
get_mux_nids(codec);
override_mic_boost(codec, 0x2b, 0, 3, 40);
override_mic_boost(codec, 0x29, 0, 3, 40);
spec->mixers[spec->num_mixers] = vt1718S_capture_mixer;
spec->num_mixers++;
}
codec->patch_ops = via_patch_ops;
codec->patch_ops.init = via_auto_init;
codec->patch_ops.unsol_event = via_unsol_event;
#ifdef CONFIG_SND_HDA_POWER_SAVE
spec->loopback.amplist = vt1718S_loopbacks;
#endif
spec->set_widgets_power_state = set_widgets_power_state_vt1718S;
return 0;
}
static int vt1716s_dmic_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_BOOLEAN;
uinfo->count = 1;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = 1;
return 0;
}
static int vt1716s_dmic_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
int index = 0;
index = snd_hda_codec_read(codec, 0x26, 0,
AC_VERB_GET_CONNECT_SEL, 0);
if (index != -1)
*ucontrol->value.integer.value = index;
return 0;
}
static int vt1716s_dmic_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct via_spec *spec = codec->spec;
int index = *ucontrol->value.integer.value;
snd_hda_codec_write(codec, 0x26, 0,
AC_VERB_SET_CONNECT_SEL, index);
spec->dmic_enabled = index;
set_widgets_power_state(codec);
return 1;
}
static int vt1716S_auto_fill_dac_nids(struct via_spec *spec,
const struct auto_pin_cfg *cfg)
{ int i;
hda_nid_t nid;
spec->multiout.num_dacs = cfg->line_outs;
spec->multiout.dac_nids = spec->private_dac_nids;
for (i = 0; i < 3; i++) {
nid = cfg->line_out_pins[i];
if (nid) {
switch (i) {
case AUTO_SEQ_FRONT:
spec->private_dac_nids[i] = 0x10;
break;
case AUTO_SEQ_CENLFE:
spec->private_dac_nids[i] = 0x25;
break;
case AUTO_SEQ_SURROUND:
spec->private_dac_nids[i] = 0x11;
break;
}
}
}
return 0;
}
static int vt1716S_auto_create_multi_out_ctls(struct via_spec *spec,
const struct auto_pin_cfg *cfg)
{
char name[32];
static const char * const chname[3] = {
"Front", "Surround", "C/LFE"
};
hda_nid_t nid_vols[] = {0x10, 0x11, 0x25};
hda_nid_t nid_mutes[] = {0x1C, 0x18, 0x27};
hda_nid_t nid, nid_vol, nid_mute;
int i, err;
for (i = 0; i <= AUTO_SEQ_CENLFE; i++) {
nid = cfg->line_out_pins[i];
if (!nid)
continue;
nid_vol = nid_vols[i];
nid_mute = nid_mutes[i];
if (i == AUTO_SEQ_CENLFE) {
err = via_add_control(
spec, VIA_CTL_WIDGET_VOL,
"Center Playback Volume",
HDA_COMPOSE_AMP_VAL(nid_vol, 1, 0, HDA_OUTPUT));
if (err < 0)
return err;
err = via_add_control(
spec, VIA_CTL_WIDGET_VOL,
"LFE Playback Volume",
HDA_COMPOSE_AMP_VAL(nid_vol, 2, 0, HDA_OUTPUT));
if (err < 0)
return err;
err = via_add_control(
spec, VIA_CTL_WIDGET_MUTE,
"Center Playback Switch",
HDA_COMPOSE_AMP_VAL(nid_mute, 1, 0,
HDA_OUTPUT));
if (err < 0)
return err;
err = via_add_control(
spec, VIA_CTL_WIDGET_MUTE,
"LFE Playback Switch",
HDA_COMPOSE_AMP_VAL(nid_mute, 2, 0,
HDA_OUTPUT));
if (err < 0)
return err;
} else if (i == AUTO_SEQ_FRONT) {
err = via_add_control(
spec, VIA_CTL_WIDGET_VOL,
"Master Front Playback Volume",
HDA_COMPOSE_AMP_VAL(0x16, 3, 0, HDA_INPUT));
if (err < 0)
return err;
err = via_add_control(
spec, VIA_CTL_WIDGET_MUTE,
"Master Front Playback Switch",
HDA_COMPOSE_AMP_VAL(0x16, 3, 0, HDA_INPUT));
if (err < 0)
return err;
sprintf(name, "%s Playback Volume", chname[i]);
err = via_add_control(
spec, VIA_CTL_WIDGET_VOL, name,
HDA_COMPOSE_AMP_VAL(nid_vol, 3, 0, HDA_OUTPUT));
if (err < 0)
return err;
sprintf(name, "%s Playback Switch", chname[i]);
err = via_add_control(
spec, VIA_CTL_WIDGET_MUTE, name,
HDA_COMPOSE_AMP_VAL(nid_mute, 3, 0,
HDA_OUTPUT));
if (err < 0)
return err;
} else {
sprintf(name, "%s Playback Volume", chname[i]);
err = via_add_control(
spec, VIA_CTL_WIDGET_VOL, name,
HDA_COMPOSE_AMP_VAL(nid_vol, 3, 0, HDA_OUTPUT));
if (err < 0)
return err;
sprintf(name, "%s Playback Switch", chname[i]);
err = via_add_control(
spec, VIA_CTL_WIDGET_MUTE, name,
HDA_COMPOSE_AMP_VAL(nid_mute, 3, 0,
HDA_OUTPUT));
if (err < 0)
return err;
}
}
return 0;
}
static int vt1716S_auto_create_hp_ctls(struct via_spec *spec, hda_nid_t pin)
{
int err;
if (!pin)
return 0;
spec->multiout.hp_nid = 0x25;
spec->hp_independent_mode_index = 1;
err = via_add_control(spec, VIA_CTL_WIDGET_VOL,
"Headphone Playback Volume",
HDA_COMPOSE_AMP_VAL(0x25, 3, 0, HDA_OUTPUT));
if (err < 0)
return err;
err = via_add_control(spec, VIA_CTL_WIDGET_MUTE,
"Headphone Playback Switch",
HDA_COMPOSE_AMP_VAL(pin, 3, 0, HDA_OUTPUT));
if (err < 0)
return err;
create_hp_imux(spec);
return 0;
}
static int vt1716S_auto_create_analog_input_ctls(struct hda_codec *codec,
const struct auto_pin_cfg *cfg)
{
static const hda_nid_t pin_idxs[] = { 0x1f, 0x1a, 0x1b, 0x1e, 0, 0xff };
return vt_auto_create_analog_input_ctls(codec, cfg, 0x16, pin_idxs,
ARRAY_SIZE(pin_idxs));
}
static int vt1716S_parse_auto_config(struct hda_codec *codec)
{
struct via_spec *spec = codec->spec;
int err;
err = snd_hda_parse_pin_def_config(codec, &spec->autocfg, NULL);
if (err < 0)
return err;
err = vt1716S_auto_fill_dac_nids(spec, &spec->autocfg);
if (err < 0)
return err;
if (!spec->autocfg.line_outs && !spec->autocfg.hp_pins[0])
return 0;
err = vt1716S_auto_create_multi_out_ctls(spec, &spec->autocfg);
if (err < 0)
return err;
err = vt1716S_auto_create_hp_ctls(spec, spec->autocfg.hp_pins[0]);
if (err < 0)
return err;
err = vt1716S_auto_create_analog_input_ctls(codec, &spec->autocfg);
if (err < 0)
return err;
spec->multiout.max_channels = spec->multiout.num_dacs * 2;
fill_dig_outs(codec);
if (spec->kctls.list)
spec->mixers[spec->num_mixers++] = spec->kctls.list;
spec->input_mux = &spec->private_imux[0];
if (spec->hp_mux)
via_hp_build(codec);
via_smart51_build(spec);
return 1;
}
static void set_widgets_power_state_vt1716S(struct hda_codec *codec)
{
struct via_spec *spec = codec->spec;
int imux_is_smixer;
unsigned int parm;
unsigned int mono_out, present;
imux_is_smixer =
(snd_hda_codec_read(codec, 0x17, 0,
AC_VERB_GET_CONNECT_SEL, 0x00) == 5);
parm = AC_PWRST_D3;
set_pin_power_state(codec, 0x1a, &parm);
set_pin_power_state(codec, 0x1b, &parm);
set_pin_power_state(codec, 0x1e, &parm);
if (imux_is_smixer)
parm = AC_PWRST_D0;
snd_hda_codec_write(codec, 0x17, 0, AC_VERB_SET_POWER_STATE, parm);
snd_hda_codec_write(codec, 0x13, 0, AC_VERB_SET_POWER_STATE, parm);
parm = AC_PWRST_D3;
set_pin_power_state(codec, 0x1e, &parm);
if (spec->dmic_enabled)
set_pin_power_state(codec, 0x22, &parm);
else
snd_hda_codec_write(codec, 0x22, 0,
AC_VERB_SET_POWER_STATE, AC_PWRST_D3);
snd_hda_codec_write(codec, 0x26, 0, AC_VERB_SET_POWER_STATE, parm);
snd_hda_codec_write(codec, 0x14, 0, AC_VERB_SET_POWER_STATE, parm);
parm = AC_PWRST_D3;
set_pin_power_state(codec, 0x19, &parm);
if (spec->smart51_enabled)
set_pin_power_state(codec, 0x1b, &parm);
snd_hda_codec_write(codec, 0x18, 0, AC_VERB_SET_POWER_STATE, parm);
snd_hda_codec_write(codec, 0x11, 0, AC_VERB_SET_POWER_STATE, parm);
parm = AC_PWRST_D3;
set_pin_power_state(codec, 0x23, &parm);
if (spec->smart51_enabled)
set_pin_power_state(codec, 0x1a, &parm);
snd_hda_codec_write(codec, 0x27, 0, AC_VERB_SET_POWER_STATE, parm);
if (spec->smart51_enabled)
set_pin_power_state(codec, 0x1e, &parm);
snd_hda_codec_write(codec, 0x25, 0, AC_VERB_SET_POWER_STATE, parm);
present = snd_hda_jack_detect(codec, 0x1c);
if (present)
mono_out = 0;
else {
present = snd_hda_jack_detect(codec, 0x1d);
if (!spec->hp_independent_mode && present)
mono_out = 0;
else
mono_out = 1;
}
parm = mono_out ? AC_PWRST_D0 : AC_PWRST_D3;
snd_hda_codec_write(codec, 0x28, 0, AC_VERB_SET_POWER_STATE, parm);
snd_hda_codec_write(codec, 0x29, 0, AC_VERB_SET_POWER_STATE, parm);
snd_hda_codec_write(codec, 0x2a, 0, AC_VERB_SET_POWER_STATE, parm);
parm = AC_PWRST_D3;
set_pin_power_state(codec, 0x1c, &parm);
set_pin_power_state(codec, 0x1d, &parm);
if (spec->hp_independent_mode)
snd_hda_codec_write(codec, 0x25, 0,
AC_VERB_SET_POWER_STATE, parm);
snd_hda_codec_write(codec, 0x16, 0, AC_VERB_SET_POWER_STATE,
imux_is_smixer ? AC_PWRST_D0 : parm);
snd_hda_codec_write(codec, 0x10, 0, AC_VERB_SET_POWER_STATE,
mono_out ? AC_PWRST_D0 : parm);
}
static int patch_vt1716S(struct hda_codec *codec)
{
struct via_spec *spec;
int err;
spec = via_new_spec(codec);
if (spec == NULL)
return -ENOMEM;
err = vt1716S_parse_auto_config(codec);
if (err < 0) {
via_free(codec);
return err;
} else if (!err) {
printk(KERN_INFO "hda_codec: Cannot set up configuration "
"from BIOS. Using genenic mode...\n");
}
spec->init_verbs[spec->num_iverbs++] = vt1716S_volume_init_verbs;
spec->init_verbs[spec->num_iverbs++] = vt1716S_uniwill_init_verbs;
spec->stream_name_analog = "VT1716S Analog";
spec->stream_analog_playback = &vt1716S_pcm_analog_playback;
spec->stream_analog_capture = &vt1716S_pcm_analog_capture;
spec->stream_name_digital = "VT1716S Digital";
spec->stream_digital_playback = &vt1716S_pcm_digital_playback;
if (!spec->adc_nids && spec->input_mux) {
spec->adc_nids = vt1716S_adc_nids;
spec->num_adc_nids = ARRAY_SIZE(vt1716S_adc_nids);
get_mux_nids(codec);
override_mic_boost(codec, 0x1a, 0, 3, 40);
override_mic_boost(codec, 0x1e, 0, 3, 40);
spec->mixers[spec->num_mixers] = vt1716S_capture_mixer;
spec->num_mixers++;
}
spec->mixers[spec->num_mixers] = vt1716s_dmic_mixer;
spec->num_mixers++;
spec->mixers[spec->num_mixers++] = vt1716S_mono_out_mixer;
codec->patch_ops = via_patch_ops;
codec->patch_ops.init = via_auto_init;
codec->patch_ops.unsol_event = via_unsol_event;
#ifdef CONFIG_SND_HDA_POWER_SAVE
spec->loopback.amplist = vt1716S_loopbacks;
#endif
spec->set_widgets_power_state = set_widgets_power_state_vt1716S;
return 0;
}
static int vt2002P_auto_fill_dac_nids(struct via_spec *spec,
const struct auto_pin_cfg *cfg)
{
spec->multiout.num_dacs = 1;
spec->multiout.dac_nids = spec->private_dac_nids;
if (cfg->line_out_pins[0])
spec->private_dac_nids[0] = 0x8;
return 0;
}
static int vt2002P_auto_create_multi_out_ctls(struct via_spec *spec,
const struct auto_pin_cfg *cfg)
{
int err;
hda_nid_t sw_nid;
if (!cfg->line_out_pins[0])
return -1;
if (spec->codec_type == VT1802)
sw_nid = 0x28;
else
sw_nid = 0x26;
err = via_add_control(spec, VIA_CTL_WIDGET_VOL,
"Master Front Playback Volume",
HDA_COMPOSE_AMP_VAL(0x8, 3, 0, HDA_OUTPUT));
if (err < 0)
return err;
err = via_add_control(spec, VIA_CTL_WIDGET_BIND_PIN_MUTE,
"Master Front Playback Switch",
HDA_COMPOSE_AMP_VAL(sw_nid, 3, 0, HDA_OUTPUT));
if (err < 0)
return err;
return 0;
}
static int vt2002P_auto_create_hp_ctls(struct via_spec *spec, hda_nid_t pin)
{
int err;
if (!pin)
return 0;
spec->multiout.hp_nid = 0x9;
spec->hp_independent_mode_index = 1;
err = via_add_control(spec, VIA_CTL_WIDGET_VOL,
"Headphone Playback Volume",
HDA_COMPOSE_AMP_VAL(
spec->multiout.hp_nid, 3, 0, HDA_OUTPUT));
if (err < 0)
return err;
err = via_add_control(spec, VIA_CTL_WIDGET_MUTE,
"Headphone Playback Switch",
HDA_COMPOSE_AMP_VAL(0x25, 3, 0, HDA_OUTPUT));
if (err < 0)
return err;
create_hp_imux(spec);
return 0;
}
static int vt2002P_auto_create_analog_input_ctls(struct hda_codec *codec,
const struct auto_pin_cfg *cfg)
{
struct via_spec *spec = codec->spec;
struct hda_input_mux *imux = &spec->private_imux[0];
static const hda_nid_t pin_idxs[] = { 0x2b, 0x2a, 0x29, 0xff };
int err;
err = vt_auto_create_analog_input_ctls(codec, cfg, 0x21, pin_idxs,
ARRAY_SIZE(pin_idxs));
if (err < 0)
return err;
err = via_new_analog_input(spec, "Stereo Mixer", 0, 3, 0x21);
if (err < 0)
return err;
snd_hda_add_imux_item(imux, "Digital Mic", 4, NULL);
return 0;
}
static int vt2002P_parse_auto_config(struct hda_codec *codec)
{
struct via_spec *spec = codec->spec;
int err;
err = snd_hda_parse_pin_def_config(codec, &spec->autocfg, NULL);
if (err < 0)
return err;
err = vt2002P_auto_fill_dac_nids(spec, &spec->autocfg);
if (err < 0)
return err;
if (!spec->autocfg.line_outs && !spec->autocfg.hp_pins[0])
return 0;
err = vt2002P_auto_create_multi_out_ctls(spec, &spec->autocfg);
if (err < 0)
return err;
err = vt2002P_auto_create_hp_ctls(spec, spec->autocfg.hp_pins[0]);
if (err < 0)
return err;
err = vt2002P_auto_create_analog_input_ctls(codec, &spec->autocfg);
if (err < 0)
return err;
spec->multiout.max_channels = spec->multiout.num_dacs * 2;
fill_dig_outs(codec);
if (spec->kctls.list)
spec->mixers[spec->num_mixers++] = spec->kctls.list;
spec->input_mux = &spec->private_imux[0];
if (spec->hp_mux)
via_hp_build(codec);
return 1;
}
static void set_widgets_power_state_vt2002P(struct hda_codec *codec)
{
struct via_spec *spec = codec->spec;
int imux_is_smixer;
unsigned int parm;
unsigned int present;
imux_is_smixer =
snd_hda_codec_read(codec, 0x1e, 0, AC_VERB_GET_CONNECT_SEL, 0x00) == 3;
parm = AC_PWRST_D3;
set_pin_power_state(codec, 0x29, &parm);
set_pin_power_state(codec, 0x2a, &parm);
set_pin_power_state(codec, 0x2b, &parm);
parm = AC_PWRST_D0;
snd_hda_codec_write(codec, 0x1e, 0, AC_VERB_SET_POWER_STATE, parm);
snd_hda_codec_write(codec, 0x1f, 0, AC_VERB_SET_POWER_STATE, parm);
snd_hda_codec_write(codec, 0x10, 0, AC_VERB_SET_POWER_STATE, parm);
snd_hda_codec_write(codec, 0x11, 0, AC_VERB_SET_POWER_STATE, parm);
snd_hda_codec_write(codec, 0x8, 0, AC_VERB_SET_POWER_STATE, parm);
if (spec->codec_type == VT1802) {
parm = AC_PWRST_D3;
set_pin_power_state(codec, 0x28, &parm);
snd_hda_codec_write(codec, 0x18, 0,
AC_VERB_SET_POWER_STATE, parm);
snd_hda_codec_write(codec, 0x38, 0,
AC_VERB_SET_POWER_STATE, parm);
} else {
parm = AC_PWRST_D3;
set_pin_power_state(codec, 0x26, &parm);
snd_hda_codec_write(codec, 0x1c, 0,
AC_VERB_SET_POWER_STATE, parm);
snd_hda_codec_write(codec, 0x37, 0,
AC_VERB_SET_POWER_STATE, parm);
}
if (spec->codec_type == VT1802) {
parm = AC_PWRST_D3;
set_pin_power_state(codec, 0x25, &parm);
snd_hda_codec_write(codec, 0x15, 0,
AC_VERB_SET_POWER_STATE, parm);
snd_hda_codec_write(codec, 0x35, 0,
AC_VERB_SET_POWER_STATE, parm);
} else {
parm = AC_PWRST_D3;
set_pin_power_state(codec, 0x25, &parm);
snd_hda_codec_write(codec, 0x19, 0,
AC_VERB_SET_POWER_STATE, parm);
snd_hda_codec_write(codec, 0x35, 0,
AC_VERB_SET_POWER_STATE, parm);
}
if (spec->hp_independent_mode)
snd_hda_codec_write(codec, 0x9, 0,
AC_VERB_SET_POWER_STATE, AC_PWRST_D0);
present = snd_hda_jack_detect(codec, 0x25);
parm = AC_PWRST_D3;
set_pin_power_state(codec, 0x24, &parm);
parm = present ? AC_PWRST_D3 : AC_PWRST_D0;
if (spec->codec_type == VT1802)
snd_hda_codec_write(codec, 0x14, 0,
AC_VERB_SET_POWER_STATE, parm);
else
snd_hda_codec_write(codec, 0x18, 0,
AC_VERB_SET_POWER_STATE, parm);
snd_hda_codec_write(codec, 0x34, 0, AC_VERB_SET_POWER_STATE, parm);
present = snd_hda_jack_detect(codec, 0x26);
parm = present ? AC_PWRST_D3 : AC_PWRST_D0;
if (spec->codec_type == VT1802) {
snd_hda_codec_write(codec, 0x33, 0,
AC_VERB_SET_POWER_STATE, parm);
snd_hda_codec_write(codec, 0x1c, 0,
AC_VERB_SET_POWER_STATE, parm);
snd_hda_codec_write(codec, 0x3c, 0,
AC_VERB_SET_POWER_STATE, parm);
} else {
snd_hda_codec_write(codec, 0x31, 0,
AC_VERB_SET_POWER_STATE, parm);
snd_hda_codec_write(codec, 0x17, 0,
AC_VERB_SET_POWER_STATE, parm);
snd_hda_codec_write(codec, 0x3b, 0,
AC_VERB_SET_POWER_STATE, parm);
}
if (imux_is_smixer || !is_aa_path_mute(codec))
snd_hda_codec_write(codec, 0x21, 0,
AC_VERB_SET_POWER_STATE, AC_PWRST_D0);
else
snd_hda_codec_write(codec, 0x21, 0,
AC_VERB_SET_POWER_STATE, AC_PWRST_D3);
}
static int patch_vt2002P(struct hda_codec *codec)
{
struct via_spec *spec;
int err;
spec = via_new_spec(codec);
if (spec == NULL)
return -ENOMEM;
err = vt2002P_parse_auto_config(codec);
if (err < 0) {
via_free(codec);
return err;
} else if (!err) {
printk(KERN_INFO "hda_codec: Cannot set up configuration "
"from BIOS. Using genenic mode...\n");
}
if (spec->codec_type == VT1802)
spec->init_verbs[spec->num_iverbs++] =
vt1802_volume_init_verbs;
else
spec->init_verbs[spec->num_iverbs++] =
vt2002P_volume_init_verbs;
if (spec->codec_type == VT1802)
spec->init_verbs[spec->num_iverbs++] =
vt1802_uniwill_init_verbs;
else
spec->init_verbs[spec->num_iverbs++] =
vt2002P_uniwill_init_verbs;
if (spec->codec_type == VT1802)
spec->stream_name_analog = "VT1802 Analog";
else
spec->stream_name_analog = "VT2002P Analog";
spec->stream_analog_playback = &vt2002P_pcm_analog_playback;
spec->stream_analog_capture = &vt2002P_pcm_analog_capture;
if (spec->codec_type == VT1802)
spec->stream_name_digital = "VT1802 Digital";
else
spec->stream_name_digital = "VT2002P Digital";
spec->stream_digital_playback = &vt2002P_pcm_digital_playback;
if (!spec->adc_nids && spec->input_mux) {
spec->adc_nids = vt2002P_adc_nids;
spec->num_adc_nids = ARRAY_SIZE(vt2002P_adc_nids);
get_mux_nids(codec);
override_mic_boost(codec, 0x2b, 0, 3, 40);
override_mic_boost(codec, 0x29, 0, 3, 40);
spec->mixers[spec->num_mixers] = vt2002P_capture_mixer;
spec->num_mixers++;
}
codec->patch_ops = via_patch_ops;
codec->patch_ops.init = via_auto_init;
codec->patch_ops.unsol_event = via_unsol_event;
#ifdef CONFIG_SND_HDA_POWER_SAVE
spec->loopback.amplist = vt2002P_loopbacks;
#endif
spec->set_widgets_power_state = set_widgets_power_state_vt2002P;
return 0;
}
static int vt1812_auto_fill_dac_nids(struct via_spec *spec,
const struct auto_pin_cfg *cfg)
{
spec->multiout.num_dacs = 1;
spec->multiout.dac_nids = spec->private_dac_nids;
if (cfg->line_out_pins[0])
spec->private_dac_nids[0] = 0x8;
return 0;
}
static int vt1812_auto_create_multi_out_ctls(struct via_spec *spec,
const struct auto_pin_cfg *cfg)
{
int err;
if (!cfg->line_out_pins[0])
return -1;
err = via_add_control(spec, VIA_CTL_WIDGET_VOL,
"Front Playback Volume",
HDA_COMPOSE_AMP_VAL(0x8, 3, 0, HDA_OUTPUT));
if (err < 0)
return err;
err = via_add_control(spec, VIA_CTL_WIDGET_BIND_PIN_MUTE,
"Front Playback Switch",
HDA_COMPOSE_AMP_VAL(0x28, 3, 0, HDA_OUTPUT));
if (err < 0)
return err;
return 0;
}
static int vt1812_auto_create_hp_ctls(struct via_spec *spec, hda_nid_t pin)
{
int err;
if (!pin)
return 0;
spec->multiout.hp_nid = 0x9;
spec->hp_independent_mode_index = 1;
err = via_add_control(spec, VIA_CTL_WIDGET_VOL,
"Headphone Playback Volume",
HDA_COMPOSE_AMP_VAL(
spec->multiout.hp_nid, 3, 0, HDA_OUTPUT));
if (err < 0)
return err;
err = via_add_control(spec, VIA_CTL_WIDGET_MUTE,
"Headphone Playback Switch",
HDA_COMPOSE_AMP_VAL(pin, 3, 0, HDA_OUTPUT));
if (err < 0)
return err;
create_hp_imux(spec);
return 0;
}
static int vt1812_auto_create_analog_input_ctls(struct hda_codec *codec,
const struct auto_pin_cfg *cfg)
{
struct via_spec *spec = codec->spec;
struct hda_input_mux *imux = &spec->private_imux[0];
static const hda_nid_t pin_idxs[] = { 0x2b, 0x2a, 0x29, 0, 0, 0xff };
int err;
err = vt_auto_create_analog_input_ctls(codec, cfg, 0x21, pin_idxs,
ARRAY_SIZE(pin_idxs));
if (err < 0)
return err;
err = via_new_analog_input(spec, "Stereo Mixer", 0, 5, 0x21);
if (err < 0)
return err;
snd_hda_add_imux_item(imux, "Digital Mic", 6, NULL);
return 0;
}
static int vt1812_parse_auto_config(struct hda_codec *codec)
{
struct via_spec *spec = codec->spec;
int err;
err = snd_hda_parse_pin_def_config(codec, &spec->autocfg, NULL);
if (err < 0)
return err;
fill_dig_outs(codec);
err = vt1812_auto_fill_dac_nids(spec, &spec->autocfg);
if (err < 0)
return err;
if (!spec->autocfg.line_outs && !spec->autocfg.hp_outs)
return 0;
err = vt1812_auto_create_multi_out_ctls(spec, &spec->autocfg);
if (err < 0)
return err;
err = vt1812_auto_create_hp_ctls(spec, spec->autocfg.hp_pins[0]);
if (err < 0)
return err;
err = vt1812_auto_create_analog_input_ctls(codec, &spec->autocfg);
if (err < 0)
return err;
spec->multiout.max_channels = spec->multiout.num_dacs * 2;
fill_dig_outs(codec);
if (spec->kctls.list)
spec->mixers[spec->num_mixers++] = spec->kctls.list;
spec->input_mux = &spec->private_imux[0];
if (spec->hp_mux)
via_hp_build(codec);
return 1;
}
static void set_widgets_power_state_vt1812(struct hda_codec *codec)
{
struct via_spec *spec = codec->spec;
int imux_is_smixer =
snd_hda_codec_read(codec, 0x13, 0, AC_VERB_GET_CONNECT_SEL, 0x00) == 3;
unsigned int parm;
unsigned int present;
imux_is_smixer =
snd_hda_codec_read(codec, 0x1e, 0, AC_VERB_GET_CONNECT_SEL, 0x00) == 5;
parm = AC_PWRST_D3;
set_pin_power_state(codec, 0x29, &parm);
set_pin_power_state(codec, 0x2a, &parm);
set_pin_power_state(codec, 0x2b, &parm);
parm = AC_PWRST_D0;
snd_hda_codec_write(codec, 0x1e, 0, AC_VERB_SET_POWER_STATE, parm);
snd_hda_codec_write(codec, 0x1f, 0, AC_VERB_SET_POWER_STATE, parm);
snd_hda_codec_write(codec, 0x10, 0, AC_VERB_SET_POWER_STATE, parm);
snd_hda_codec_write(codec, 0x11, 0, AC_VERB_SET_POWER_STATE, parm);
snd_hda_codec_write(codec, 0x8, 0,
AC_VERB_SET_POWER_STATE, AC_PWRST_D0);
parm = AC_PWRST_D3;
set_pin_power_state(codec, 0x28, &parm);
snd_hda_codec_write(codec, 0x18, 0, AC_VERB_SET_POWER_STATE, parm);
snd_hda_codec_write(codec, 0x38, 0, AC_VERB_SET_POWER_STATE, parm);
parm = AC_PWRST_D3;
set_pin_power_state(codec, 0x25, &parm);
snd_hda_codec_write(codec, 0x15, 0, AC_VERB_SET_POWER_STATE, parm);
snd_hda_codec_write(codec, 0x35, 0, AC_VERB_SET_POWER_STATE, parm);
if (spec->hp_independent_mode)
snd_hda_codec_write(codec, 0x9, 0,
AC_VERB_SET_POWER_STATE, AC_PWRST_D0);
present = snd_hda_jack_detect(codec, 0x25);
parm = AC_PWRST_D3;
set_pin_power_state(codec, 0x24, &parm);
if (present) {
snd_hda_codec_write(codec, 0x14, 0,
AC_VERB_SET_POWER_STATE, AC_PWRST_D3);
snd_hda_codec_write(codec, 0x34, 0,
AC_VERB_SET_POWER_STATE, AC_PWRST_D3);
} else {
snd_hda_codec_write(codec, 0x14, 0,
AC_VERB_SET_POWER_STATE, AC_PWRST_D0);
snd_hda_codec_write(codec, 0x34, 0,
AC_VERB_SET_POWER_STATE, AC_PWRST_D0);
}
present = snd_hda_jack_detect(codec, 0x28);
parm = AC_PWRST_D3;
set_pin_power_state(codec, 0x31, &parm);
if (present) {
snd_hda_codec_write(codec, 0x1c, 0,
AC_VERB_SET_POWER_STATE, AC_PWRST_D3);
snd_hda_codec_write(codec, 0x3c, 0,
AC_VERB_SET_POWER_STATE, AC_PWRST_D3);
snd_hda_codec_write(codec, 0x3e, 0,
AC_VERB_SET_POWER_STATE, AC_PWRST_D3);
} else {
snd_hda_codec_write(codec, 0x1c, 0,
AC_VERB_SET_POWER_STATE, AC_PWRST_D0);
snd_hda_codec_write(codec, 0x3c, 0,
AC_VERB_SET_POWER_STATE, AC_PWRST_D0);
snd_hda_codec_write(codec, 0x3e, 0,
AC_VERB_SET_POWER_STATE, AC_PWRST_D0);
}
parm = AC_PWRST_D3;
set_pin_power_state(codec, 0x33, &parm);
snd_hda_codec_write(codec, 0x1d, 0, AC_VERB_SET_POWER_STATE, parm);
snd_hda_codec_write(codec, 0x3d, 0, AC_VERB_SET_POWER_STATE, parm);
}
static int patch_vt1812(struct hda_codec *codec)
{
struct via_spec *spec;
int err;
spec = via_new_spec(codec);
if (spec == NULL)
return -ENOMEM;
err = vt1812_parse_auto_config(codec);
if (err < 0) {
via_free(codec);
return err;
} else if (!err) {
printk(KERN_INFO "hda_codec: Cannot set up configuration "
"from BIOS. Using genenic mode...\n");
}
spec->init_verbs[spec->num_iverbs++] = vt1812_volume_init_verbs;
spec->init_verbs[spec->num_iverbs++] = vt1812_uniwill_init_verbs;
spec->stream_name_analog = "VT1812 Analog";
spec->stream_analog_playback = &vt1812_pcm_analog_playback;
spec->stream_analog_capture = &vt1812_pcm_analog_capture;
spec->stream_name_digital = "VT1812 Digital";
spec->stream_digital_playback = &vt1812_pcm_digital_playback;
if (!spec->adc_nids && spec->input_mux) {
spec->adc_nids = vt1812_adc_nids;
spec->num_adc_nids = ARRAY_SIZE(vt1812_adc_nids);
get_mux_nids(codec);
override_mic_boost(codec, 0x2b, 0, 3, 40);
override_mic_boost(codec, 0x29, 0, 3, 40);
spec->mixers[spec->num_mixers] = vt1812_capture_mixer;
spec->num_mixers++;
}
codec->patch_ops = via_patch_ops;
codec->patch_ops.init = via_auto_init;
codec->patch_ops.unsol_event = via_unsol_event;
#ifdef CONFIG_SND_HDA_POWER_SAVE
spec->loopback.amplist = vt1812_loopbacks;
#endif
spec->set_widgets_power_state = set_widgets_power_state_vt1812;
return 0;
}
static int __init patch_via_init(void)
{
return snd_hda_add_codec_preset(&via_list);
}
static void __exit patch_via_exit(void)
{
snd_hda_delete_codec_preset(&via_list);
}
