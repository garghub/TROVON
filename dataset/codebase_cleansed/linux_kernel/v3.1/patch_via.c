static struct via_spec * via_new_spec(struct hda_codec *codec)
{
struct via_spec *spec;
spec = kzalloc(sizeof(*spec), GFP_KERNEL);
if (spec == NULL)
return NULL;
mutex_init(&spec->config_mutex);
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
!spec->vt1708_jack_detect);
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
!spec->vt1708_jack_detect);
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
analog_low_current_mode(snd_kcontrol_chip(kcontrol));
if (snd_hda_get_bool_hint(codec, "analog_loopback_hp_detect") == 1) {
if (is_aa_path_mute(codec))
vt1708_start_hp_work(codec->spec);
else
vt1708_stop_hp_work(codec->spec);
}
return change;
}
static struct snd_kcontrol_new *__via_clone_ctl(struct via_spec *spec,
const struct snd_kcontrol_new *tmpl,
const char *name)
{
struct snd_kcontrol_new *knew;
snd_array_init(&spec->kctls, sizeof(*knew), 32);
knew = snd_array_new(&spec->kctls);
if (!knew)
return NULL;
*knew = *tmpl;
if (!name)
name = tmpl->name;
if (name) {
knew->name = kstrdup(name, GFP_KERNEL);
if (!knew->name)
return NULL;
}
return knew;
}
static int __via_add_control(struct via_spec *spec, int type, const char *name,
int idx, unsigned long val)
{
struct snd_kcontrol_new *knew;
knew = __via_clone_ctl(spec, &via_control_templates[type], name);
if (!knew)
return -ENOMEM;
knew->index = idx;
if (get_amp_nid_(val))
knew->subdevice = HDA_SUBDEV_AMP_FLAG;
knew->private_value = val;
return 0;
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
static bool check_amp_caps(struct hda_codec *codec, hda_nid_t nid, int dir,
unsigned int mask)
{
unsigned int caps;
if (!nid)
return false;
caps = get_wcaps(codec, nid);
if (dir == HDA_INPUT)
caps &= AC_WCAP_IN_AMP;
else
caps &= AC_WCAP_OUT_AMP;
if (!caps)
return false;
if (query_amp_caps(codec, nid, dir) & mask)
return true;
return false;
}
static void activate_output_mix(struct hda_codec *codec, struct nid_path *path,
hda_nid_t mix_nid, int idx, bool enable)
{
int i, num, val;
if (!path)
return;
num = snd_hda_get_conn_list(codec, mix_nid, NULL);
for (i = 0; i < num; i++) {
if (i == idx)
val = AMP_IN_UNMUTE(i);
else
val = AMP_IN_MUTE(i);
snd_hda_codec_write(codec, mix_nid, 0,
AC_VERB_SET_AMP_GAIN_MUTE, val);
}
}
static void activate_output_path(struct hda_codec *codec, struct nid_path *path,
bool enable, bool force)
{
struct via_spec *spec = codec->spec;
int i;
for (i = 0; i < path->depth; i++) {
hda_nid_t src, dst;
int idx = path->idx[i];
src = path->path[i];
if (i < path->depth - 1)
dst = path->path[i + 1];
else
dst = 0;
if (enable && path->multi[i])
snd_hda_codec_write(codec, dst, 0,
AC_VERB_SET_CONNECT_SEL, idx);
if (!force && (dst == spec->aa_mix_nid))
continue;
if (have_mute(codec, dst, HDA_INPUT))
activate_output_mix(codec, path, dst, idx, enable);
if (!force && (src == path->vol_ctl || src == path->mute_ctl))
continue;
if (have_mute(codec, src, HDA_OUTPUT)) {
int val = enable ? AMP_OUT_UNMUTE : AMP_OUT_MUTE;
snd_hda_codec_write(codec, src, 0,
AC_VERB_SET_AMP_GAIN_MUTE, val);
}
}
}
static void init_output_pin(struct hda_codec *codec, hda_nid_t pin,
int pin_type)
{
if (!pin)
return;
snd_hda_codec_write(codec, pin, 0, AC_VERB_SET_PIN_WIDGET_CONTROL,
pin_type);
if (snd_hda_query_pin_caps(codec, pin) & AC_PINCAP_EAPD)
snd_hda_codec_write(codec, pin, 0,
AC_VERB_SET_EAPD_BTLENABLE, 0x02);
}
static void via_auto_init_output(struct hda_codec *codec,
struct nid_path *path, int pin_type)
{
unsigned int caps;
hda_nid_t pin;
if (!path->depth)
return;
pin = path->path[path->depth - 1];
init_output_pin(codec, pin, pin_type);
caps = query_amp_caps(codec, pin, HDA_OUTPUT);
if (caps & AC_AMPCAP_MUTE) {
unsigned int val;
val = (caps & AC_AMPCAP_OFFSET) >> AC_AMPCAP_OFFSET_SHIFT;
snd_hda_codec_write(codec, pin, 0, AC_VERB_SET_AMP_GAIN_MUTE,
AMP_OUT_MUTE | val);
}
activate_output_path(codec, path, true, true);
}
static void via_auto_init_multi_out(struct hda_codec *codec)
{
struct via_spec *spec = codec->spec;
struct nid_path *path;
int i;
for (i = 0; i < spec->autocfg.line_outs + spec->smart51_nums; i++) {
path = &spec->out_path[i];
if (!i && spec->aamix_mode && spec->out_mix_path.depth)
path = &spec->out_mix_path;
via_auto_init_output(codec, path, PIN_OUT);
}
}
static void deactivate_hp_paths(struct hda_codec *codec)
{
struct via_spec *spec = codec->spec;
int shared = spec->hp_indep_shared;
if (spec->hp_independent_mode) {
activate_output_path(codec, &spec->hp_path, false, false);
activate_output_path(codec, &spec->hp_mix_path, false, false);
if (shared)
activate_output_path(codec, &spec->out_path[shared],
false, false);
} else if (spec->aamix_mode || !spec->hp_path.depth) {
activate_output_path(codec, &spec->hp_indep_path, false, false);
activate_output_path(codec, &spec->hp_path, false, false);
} else {
activate_output_path(codec, &spec->hp_indep_path, false, false);
activate_output_path(codec, &spec->hp_mix_path, false, false);
}
}
static void via_auto_init_hp_out(struct hda_codec *codec)
{
struct via_spec *spec = codec->spec;
if (!spec->hp_path.depth) {
via_auto_init_output(codec, &spec->hp_mix_path, PIN_HP);
return;
}
deactivate_hp_paths(codec);
if (spec->hp_independent_mode)
via_auto_init_output(codec, &spec->hp_indep_path, PIN_HP);
else if (spec->aamix_mode)
via_auto_init_output(codec, &spec->hp_mix_path, PIN_HP);
else
via_auto_init_output(codec, &spec->hp_path, PIN_HP);
}
static void via_auto_init_speaker_out(struct hda_codec *codec)
{
struct via_spec *spec = codec->spec;
if (!spec->autocfg.speaker_outs)
return;
if (!spec->speaker_path.depth) {
via_auto_init_output(codec, &spec->speaker_mix_path, PIN_OUT);
return;
}
if (!spec->aamix_mode) {
activate_output_path(codec, &spec->speaker_mix_path,
false, false);
via_auto_init_output(codec, &spec->speaker_path, PIN_OUT);
} else {
activate_output_path(codec, &spec->speaker_path, false, false);
via_auto_init_output(codec, &spec->speaker_mix_path, PIN_OUT);
}
}
static void via_auto_init_analog_input(struct hda_codec *codec)
{
struct via_spec *spec = codec->spec;
const struct auto_pin_cfg *cfg = &spec->autocfg;
hda_nid_t conn[HDA_MAX_CONNECTIONS];
unsigned int ctl;
int i, num_conns;
for (i = 0; i < spec->num_adc_nids; i++) {
snd_hda_codec_write(codec, spec->adc_nids[i], 0,
AC_VERB_SET_AMP_GAIN_MUTE,
AMP_IN_UNMUTE(0));
}
for (i = 0; i < cfg->num_inputs; i++) {
hda_nid_t nid = cfg->inputs[i].pin;
if (spec->smart51_enabled && is_smart51_pins(codec, nid))
ctl = PIN_OUT;
else if (cfg->inputs[i].type == AUTO_PIN_MIC)
ctl = PIN_VREF50;
else
ctl = PIN_IN;
snd_hda_codec_write(codec, nid, 0,
AC_VERB_SET_PIN_WIDGET_CONTROL, ctl);
}
for (i = 0; i < spec->num_adc_nids; i++) {
int adc_idx = spec->inputs[spec->cur_mux[i]].adc_idx;
if (spec->mux_nids[adc_idx]) {
int mux_idx = spec->inputs[spec->cur_mux[i]].mux_idx;
snd_hda_codec_write(codec, spec->mux_nids[adc_idx], 0,
AC_VERB_SET_CONNECT_SEL,
mux_idx);
}
if (spec->dyn_adc_switch)
break;
}
if (!spec->aa_mix_nid)
return;
num_conns = snd_hda_get_connections(codec, spec->aa_mix_nid, conn,
ARRAY_SIZE(conn));
for (i = 0; i < num_conns; i++) {
unsigned int caps = get_wcaps(codec, conn[i]);
if (get_wcaps_type(caps) == AC_WID_PIN)
snd_hda_codec_write(codec, spec->aa_mix_nid, 0,
AC_VERB_SET_AMP_GAIN_MUTE,
AMP_IN_MUTE(i));
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
struct via_spec *spec = codec->spec;
unsigned present = 0;
no_presence |= spec->no_pin_power_ctl;
if (!no_presence)
present = snd_hda_jack_detect(codec, nid);
if ((spec->smart51_enabled && is_smart51_pins(codec, nid))
|| ((no_presence || present)
&& get_defcfg_connect(def_conf) != AC_JACK_PORT_NONE)) {
*affected_parm = AC_PWRST_D0;
parm = AC_PWRST_D0;
} else
parm = AC_PWRST_D3;
snd_hda_codec_write(codec, nid, 0, AC_VERB_SET_POWER_STATE, parm);
}
static int via_pin_power_ctl_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
static const char * const texts[] = {
"Disabled", "Enabled"
};
uinfo->type = SNDRV_CTL_ELEM_TYPE_ENUMERATED;
uinfo->count = 1;
uinfo->value.enumerated.items = 2;
if (uinfo->value.enumerated.item >= uinfo->value.enumerated.items)
uinfo->value.enumerated.item = uinfo->value.enumerated.items - 1;
strcpy(uinfo->value.enumerated.name,
texts[uinfo->value.enumerated.item]);
return 0;
}
static int via_pin_power_ctl_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct via_spec *spec = codec->spec;
ucontrol->value.enumerated.item[0] = !spec->no_pin_power_ctl;
return 0;
}
static int via_pin_power_ctl_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct via_spec *spec = codec->spec;
unsigned int val = !ucontrol->value.enumerated.item[0];
if (val == spec->no_pin_power_ctl)
return 0;
spec->no_pin_power_ctl = val;
set_widgets_power_state(codec);
return 1;
}
static int via_independent_hp_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
static const char * const texts[] = { "OFF", "ON" };
uinfo->type = SNDRV_CTL_ELEM_TYPE_ENUMERATED;
uinfo->count = 1;
uinfo->value.enumerated.items = 2;
if (uinfo->value.enumerated.item >= 2)
uinfo->value.enumerated.item = 1;
strcpy(uinfo->value.enumerated.name,
texts[uinfo->value.enumerated.item]);
return 0;
}
static int via_independent_hp_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct via_spec *spec = codec->spec;
ucontrol->value.enumerated.item[0] = spec->hp_independent_mode;
return 0;
}
static void setup_playback_multi_pcm(struct via_spec *spec)
{
const struct auto_pin_cfg *cfg = &spec->autocfg;
spec->multiout.num_dacs = cfg->line_outs + spec->smart51_nums;
spec->multiout.hp_nid = 0;
if (!spec->hp_independent_mode) {
if (!spec->hp_indep_shared)
spec->multiout.hp_nid = spec->hp_dac_nid;
} else {
if (spec->hp_indep_shared)
spec->multiout.num_dacs = cfg->line_outs - 1;
}
}
static void switch_indep_hp_dacs(struct hda_codec *codec)
{
struct via_spec *spec = codec->spec;
int shared = spec->hp_indep_shared;
hda_nid_t shared_dac, hp_dac;
if (!spec->opened_streams)
return;
shared_dac = shared ? spec->multiout.dac_nids[shared] : 0;
hp_dac = spec->hp_dac_nid;
if (spec->hp_independent_mode) {
if (spec->active_streams & STREAM_MULTI_OUT) {
__snd_hda_codec_cleanup_stream(codec, hp_dac, 1);
__snd_hda_codec_cleanup_stream(codec, shared_dac, 1);
}
if (spec->active_streams & STREAM_INDEP_HP)
snd_hda_codec_setup_stream(codec, hp_dac,
spec->cur_hp_stream_tag, 0,
spec->cur_hp_format);
} else {
if (spec->active_streams & STREAM_INDEP_HP)
__snd_hda_codec_cleanup_stream(codec, hp_dac, 1);
if (spec->active_streams & STREAM_MULTI_OUT) {
hda_nid_t dac;
int ch;
if (shared_dac) {
dac = shared_dac;
ch = shared * 2;
} else {
dac = hp_dac;
ch = 0;
}
snd_hda_codec_setup_stream(codec, dac,
spec->cur_dac_stream_tag, ch,
spec->cur_dac_format);
}
}
setup_playback_multi_pcm(spec);
}
static int via_independent_hp_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct via_spec *spec = codec->spec;
int cur, shared;
mutex_lock(&spec->config_mutex);
cur = !!ucontrol->value.enumerated.item[0];
if (spec->hp_independent_mode == cur) {
mutex_unlock(&spec->config_mutex);
return 0;
}
spec->hp_independent_mode = cur;
shared = spec->hp_indep_shared;
deactivate_hp_paths(codec);
if (cur)
activate_output_path(codec, &spec->hp_indep_path, true, false);
else {
if (shared)
activate_output_path(codec, &spec->out_path[shared],
true, false);
if (spec->aamix_mode || !spec->hp_path.depth)
activate_output_path(codec, &spec->hp_mix_path,
true, false);
else
activate_output_path(codec, &spec->hp_path,
true, false);
}
switch_indep_hp_dacs(codec);
mutex_unlock(&spec->config_mutex);
set_widgets_power_state(codec);
via_hp_automute(codec);
return 1;
}
static int via_hp_build(struct hda_codec *codec)
{
struct via_spec *spec = codec->spec;
struct snd_kcontrol_new *knew;
hda_nid_t nid;
nid = spec->autocfg.hp_pins[0];
knew = via_clone_control(spec, &via_hp_mixer);
if (knew == NULL)
return -ENOMEM;
knew->subdevice = HDA_SUBDEV_NID_FLAG | nid;
return 0;
}
static void notify_aa_path_ctls(struct hda_codec *codec)
{
struct via_spec *spec = codec->spec;
int i;
for (i = 0; i < spec->smart51_nums; i++) {
struct snd_kcontrol *ctl;
struct snd_ctl_elem_id id;
memset(&id, 0, sizeof(id));
id.iface = SNDRV_CTL_ELEM_IFACE_MIXER;
sprintf(id.name, "%s Playback Volume", spec->smart51_labels[i]);
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
int val = mute ? HDA_AMP_MUTE : HDA_AMP_UNMUTE;
int i;
for (i = 0; i < spec->smart51_nums; i++) {
if (spec->smart51_idxs[i] < 0)
continue;
snd_hda_codec_amp_stereo(codec, spec->aa_mix_nid,
HDA_INPUT, spec->smart51_idxs[i],
HDA_AMP_MUTE, val);
}
}
static bool is_smart51_pins(struct hda_codec *codec, hda_nid_t pin)
{
struct via_spec *spec = codec->spec;
int i;
for (i = 0; i < spec->smart51_nums; i++)
if (spec->smart51_pins[i] == pin)
return true;
return false;
}
static int via_smart51_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct via_spec *spec = codec->spec;
*ucontrol->value.integer.value = spec->smart51_enabled;
return 0;
}
static int via_smart51_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct via_spec *spec = codec->spec;
int out_in = *ucontrol->value.integer.value
? AC_PINCTL_OUT_EN : AC_PINCTL_IN_EN;
int i;
for (i = 0; i < spec->smart51_nums; i++) {
hda_nid_t nid = spec->smart51_pins[i];
unsigned int parm;
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
}
spec->smart51_enabled = *ucontrol->value.integer.value;
set_widgets_power_state(codec);
return 1;
}
static int via_smart51_build(struct hda_codec *codec)
{
struct via_spec *spec = codec->spec;
if (!spec->smart51_nums)
return 0;
if (!via_clone_control(spec, &via_smart51_mixer))
return -ENOMEM;
return 0;
}
static bool is_aa_path_mute(struct hda_codec *codec)
{
struct via_spec *spec = codec->spec;
const struct hda_amp_list *p;
int i, ch, v;
for (i = 0; i < spec->num_loopbacks; i++) {
p = &spec->loopback_list[i];
for (ch = 0; ch < 2; ch++) {
v = snd_hda_codec_amp_read(codec, p->nid, ch, p->dir,
p->idx);
if (!(v & HDA_AMP_MUTE) && v > 0)
return false;
}
}
return true;
}
static void analog_low_current_mode(struct hda_codec *codec)
{
struct via_spec *spec = codec->spec;
bool enable;
unsigned int verb, parm;
enable = is_aa_path_mute(codec) && (spec->opened_streams != 0);
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
static void set_stream_open(struct hda_codec *codec, int bit, bool active)
{
struct via_spec *spec = codec->spec;
if (active)
spec->opened_streams |= bit;
else
spec->opened_streams &= ~bit;
analog_low_current_mode(codec);
}
static int via_playback_multi_pcm_open(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
struct snd_pcm_substream *substream)
{
struct via_spec *spec = codec->spec;
const struct auto_pin_cfg *cfg = &spec->autocfg;
int err;
spec->multiout.num_dacs = cfg->line_outs + spec->smart51_nums;
spec->multiout.max_channels = spec->multiout.num_dacs * 2;
set_stream_open(codec, STREAM_MULTI_OUT, true);
err = snd_hda_multi_out_analog_open(codec, &spec->multiout, substream,
hinfo);
if (err < 0) {
set_stream_open(codec, STREAM_MULTI_OUT, false);
return err;
}
return 0;
}
static int via_playback_multi_pcm_close(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
struct snd_pcm_substream *substream)
{
set_stream_open(codec, STREAM_MULTI_OUT, false);
return 0;
}
static int via_playback_hp_pcm_open(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
struct snd_pcm_substream *substream)
{
struct via_spec *spec = codec->spec;
if (snd_BUG_ON(!spec->hp_dac_nid))
return -EINVAL;
set_stream_open(codec, STREAM_INDEP_HP, true);
return 0;
}
static int via_playback_hp_pcm_close(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
struct snd_pcm_substream *substream)
{
set_stream_open(codec, STREAM_INDEP_HP, false);
return 0;
}
static int via_playback_multi_pcm_prepare(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
unsigned int stream_tag,
unsigned int format,
struct snd_pcm_substream *substream)
{
struct via_spec *spec = codec->spec;
mutex_lock(&spec->config_mutex);
setup_playback_multi_pcm(spec);
snd_hda_multi_out_analog_prepare(codec, &spec->multiout, stream_tag,
format, substream);
spec->active_streams |= STREAM_MULTI_OUT;
spec->cur_dac_stream_tag = stream_tag;
spec->cur_dac_format = format;
mutex_unlock(&spec->config_mutex);
vt1708_start_hp_work(spec);
return 0;
}
static int via_playback_hp_pcm_prepare(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
unsigned int stream_tag,
unsigned int format,
struct snd_pcm_substream *substream)
{
struct via_spec *spec = codec->spec;
mutex_lock(&spec->config_mutex);
if (spec->hp_independent_mode)
snd_hda_codec_setup_stream(codec, spec->hp_dac_nid,
stream_tag, 0, format);
spec->active_streams |= STREAM_INDEP_HP;
spec->cur_hp_stream_tag = stream_tag;
spec->cur_hp_format = format;
mutex_unlock(&spec->config_mutex);
vt1708_start_hp_work(spec);
return 0;
}
static int via_playback_multi_pcm_cleanup(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
struct snd_pcm_substream *substream)
{
struct via_spec *spec = codec->spec;
mutex_lock(&spec->config_mutex);
snd_hda_multi_out_analog_cleanup(codec, &spec->multiout);
spec->active_streams &= ~STREAM_MULTI_OUT;
mutex_unlock(&spec->config_mutex);
vt1708_stop_hp_work(spec);
return 0;
}
static int via_playback_hp_pcm_cleanup(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
struct snd_pcm_substream *substream)
{
struct via_spec *spec = codec->spec;
mutex_lock(&spec->config_mutex);
if (spec->hp_independent_mode)
snd_hda_codec_setup_stream(codec, spec->hp_dac_nid, 0, 0, 0);
spec->active_streams &= ~STREAM_INDEP_HP;
mutex_unlock(&spec->config_mutex);
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
static int via_dyn_adc_capture_pcm_prepare(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
unsigned int stream_tag,
unsigned int format,
struct snd_pcm_substream *substream)
{
struct via_spec *spec = codec->spec;
int adc_idx = spec->inputs[spec->cur_mux[0]].adc_idx;
mutex_lock(&spec->config_mutex);
spec->cur_adc = spec->adc_nids[adc_idx];
spec->cur_adc_stream_tag = stream_tag;
spec->cur_adc_format = format;
snd_hda_codec_setup_stream(codec, spec->cur_adc, stream_tag, 0, format);
mutex_unlock(&spec->config_mutex);
return 0;
}
static int via_dyn_adc_capture_pcm_cleanup(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
struct snd_pcm_substream *substream)
{
struct via_spec *spec = codec->spec;
mutex_lock(&spec->config_mutex);
snd_hda_codec_cleanup_stream(codec, spec->cur_adc);
spec->cur_adc = 0;
mutex_unlock(&spec->config_mutex);
return 0;
}
static bool via_dyn_adc_pcm_resetup(struct hda_codec *codec, int cur)
{
struct via_spec *spec = codec->spec;
int adc_idx = spec->inputs[cur].adc_idx;
hda_nid_t adc = spec->adc_nids[adc_idx];
bool ret = false;
mutex_lock(&spec->config_mutex);
if (spec->cur_adc && spec->cur_adc != adc) {
__snd_hda_codec_cleanup_stream(codec, spec->cur_adc, 1);
spec->cur_adc = adc;
snd_hda_codec_setup_stream(codec, adc,
spec->cur_adc_stream_tag, 0,
spec->cur_adc_format);
ret = true;
}
mutex_unlock(&spec->config_mutex);
return ret;
}
static int via_build_controls(struct hda_codec *codec)
{
struct via_spec *spec = codec->spec;
struct snd_kcontrol *kctl;
int err, i;
if (spec->set_widgets_power_state)
if (!via_clone_control(spec, &via_pin_power_ctl_enum))
return -ENOMEM;
for (i = 0; i < spec->num_mixers; i++) {
err = snd_hda_add_new_ctls(codec, spec->mixers[i]);
if (err < 0)
return err;
}
if (spec->multiout.dig_out_nid) {
err = snd_hda_create_spdif_out_ctls(codec,
spec->multiout.dig_out_nid,
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
if (!snd_hda_find_mixer_ctl(codec, "Master Playback Volume")) {
unsigned int vmaster_tlv[4];
snd_hda_set_vmaster_tlv(codec, spec->multiout.dac_nids[0],
HDA_OUTPUT, vmaster_tlv);
err = snd_hda_add_vmaster(codec, "Master Playback Volume",
vmaster_tlv, via_slave_vols);
if (err < 0)
return err;
}
if (!snd_hda_find_mixer_ctl(codec, "Master Playback Switch")) {
err = snd_hda_add_vmaster(codec, "Master Playback Switch",
NULL, via_slave_sws);
if (err < 0)
return err;
}
kctl = snd_hda_find_mixer_ctl(codec, "Input Source");
for (i = 0; kctl && i < kctl->count; i++) {
err = snd_hda_add_nid(codec, kctl, i, spec->mux_nids[i]);
if (err < 0)
return err;
}
set_widgets_power_state(codec);
analog_low_current_mode(codec);
via_free_kctls(codec);
return 0;
}
static int via_build_pcms(struct hda_codec *codec)
{
struct via_spec *spec = codec->spec;
struct hda_pcm *info = spec->pcm_rec;
codec->num_pcms = 1;
codec->pcm_info = info;
snprintf(spec->stream_name_analog, sizeof(spec->stream_name_analog),
"%s Analog", codec->chip_name);
info->name = spec->stream_name_analog;
if (!spec->stream_analog_playback)
spec->stream_analog_playback = &via_pcm_analog_playback;
info->stream[SNDRV_PCM_STREAM_PLAYBACK] =
*spec->stream_analog_playback;
info->stream[SNDRV_PCM_STREAM_PLAYBACK].nid =
spec->multiout.dac_nids[0];
info->stream[SNDRV_PCM_STREAM_PLAYBACK].channels_max =
spec->multiout.max_channels;
if (!spec->stream_analog_capture) {
if (spec->dyn_adc_switch)
spec->stream_analog_capture =
&via_pcm_dyn_adc_analog_capture;
else
spec->stream_analog_capture = &via_pcm_analog_capture;
}
info->stream[SNDRV_PCM_STREAM_CAPTURE] =
*spec->stream_analog_capture;
info->stream[SNDRV_PCM_STREAM_CAPTURE].nid = spec->adc_nids[0];
if (!spec->dyn_adc_switch)
info->stream[SNDRV_PCM_STREAM_CAPTURE].substreams =
spec->num_adc_nids;
if (spec->multiout.dig_out_nid || spec->dig_in_nid) {
codec->num_pcms++;
info++;
snprintf(spec->stream_name_digital,
sizeof(spec->stream_name_digital),
"%s Digital", codec->chip_name);
info->name = spec->stream_name_digital;
info->pcm_type = HDA_PCM_TYPE_SPDIF;
if (spec->multiout.dig_out_nid) {
if (!spec->stream_digital_playback)
spec->stream_digital_playback =
&via_pcm_digital_playback;
info->stream[SNDRV_PCM_STREAM_PLAYBACK] =
*spec->stream_digital_playback;
info->stream[SNDRV_PCM_STREAM_PLAYBACK].nid =
spec->multiout.dig_out_nid;
}
if (spec->dig_in_nid) {
if (!spec->stream_digital_capture)
spec->stream_digital_capture =
&via_pcm_digital_capture;
info->stream[SNDRV_PCM_STREAM_CAPTURE] =
*spec->stream_digital_capture;
info->stream[SNDRV_PCM_STREAM_CAPTURE].nid =
spec->dig_in_nid;
}
}
if (spec->hp_dac_nid) {
codec->num_pcms++;
info++;
snprintf(spec->stream_name_hp, sizeof(spec->stream_name_hp),
"%s HP", codec->chip_name);
info->name = spec->stream_name_hp;
info->stream[SNDRV_PCM_STREAM_PLAYBACK] = via_pcm_hp_playback;
info->stream[SNDRV_PCM_STREAM_PLAYBACK].nid =
spec->hp_dac_nid;
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
kfree(spec->bind_cap_vol);
kfree(spec->bind_cap_sw);
kfree(spec);
}
static void toggle_output_mutes(struct hda_codec *codec, int num_pins,
hda_nid_t *pins, bool mute)
{
int i;
for (i = 0; i < num_pins; i++) {
unsigned int parm = snd_hda_codec_read(codec, pins[i], 0,
AC_VERB_GET_PIN_WIDGET_CONTROL, 0);
if (parm & AC_PINCTL_IN_EN)
continue;
if (mute)
parm &= ~AC_PINCTL_OUT_EN;
else
parm |= AC_PINCTL_OUT_EN;
snd_hda_codec_write(codec, pins[i], 0,
AC_VERB_SET_PIN_WIDGET_CONTROL, parm);
}
}
static void via_line_automute(struct hda_codec *codec, int present)
{
struct via_spec *spec = codec->spec;
if (!spec->autocfg.speaker_outs)
return;
if (!present)
present = snd_hda_jack_detect(codec,
spec->autocfg.line_out_pins[0]);
toggle_output_mutes(codec, spec->autocfg.speaker_outs,
spec->autocfg.speaker_pins,
present);
}
static void via_hp_automute(struct hda_codec *codec)
{
int present = 0;
int nums;
struct via_spec *spec = codec->spec;
if (!spec->hp_independent_mode && spec->autocfg.hp_pins[0])
present = snd_hda_jack_detect(codec, spec->autocfg.hp_pins[0]);
if (spec->smart51_enabled)
nums = spec->autocfg.line_outs + spec->smart51_nums;
else
nums = spec->autocfg.line_outs;
toggle_output_mutes(codec, nums, spec->autocfg.line_out_pins, present);
via_line_automute(codec, present);
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
snd_hda_codec_write(codec, spec->autocfg.line_out_pins[0], 0,
AC_VERB_SET_PIN_WIDGET_CONTROL,
PIN_OUT);
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
snd_hda_codec_write(codec, spec->autocfg.line_out_pins[0], 0,
AC_VERB_SET_PIN_WIDGET_CONTROL,
0);
}
}
static void via_unsol_event(struct hda_codec *codec,
unsigned int res)
{
res >>= 26;
if (res & VIA_JACK_EVENT)
set_widgets_power_state(codec);
res &= ~VIA_JACK_EVENT;
if (res == VIA_HP_EVENT || res == VIA_LINE_EVENT)
via_hp_automute(codec);
else if (res == VIA_GPIO_EVENT)
via_gpio_control(codec);
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
static bool is_empty_dac(struct hda_codec *codec, hda_nid_t dac)
{
struct via_spec *spec = codec->spec;
int i;
for (i = 0; i < spec->multiout.num_dacs; i++) {
if (spec->multiout.dac_nids[i] == dac)
return false;
}
if (spec->hp_dac_nid == dac)
return false;
return true;
}
static bool __parse_output_path(struct hda_codec *codec, hda_nid_t nid,
hda_nid_t target_dac, int with_aa_mix,
struct nid_path *path, int depth)
{
struct via_spec *spec = codec->spec;
hda_nid_t conn[8];
int i, nums;
if (nid == spec->aa_mix_nid) {
if (!with_aa_mix)
return false;
with_aa_mix = 2;
}
nums = snd_hda_get_connections(codec, nid, conn, ARRAY_SIZE(conn));
for (i = 0; i < nums; i++) {
if (get_wcaps_type(get_wcaps(codec, conn[i])) != AC_WID_AUD_OUT)
continue;
if (conn[i] == target_dac || is_empty_dac(codec, conn[i])) {
if (!(spec->aa_mix_nid && with_aa_mix == 1))
goto found;
}
}
if (depth >= MAX_NID_PATH_DEPTH)
return false;
for (i = 0; i < nums; i++) {
unsigned int type;
type = get_wcaps_type(get_wcaps(codec, conn[i]));
if (type == AC_WID_AUD_OUT)
continue;
if (__parse_output_path(codec, conn[i], target_dac,
with_aa_mix, path, depth + 1))
goto found;
}
return false;
found:
path->path[path->depth] = conn[i];
path->idx[path->depth] = i;
if (nums > 1 && get_wcaps_type(get_wcaps(codec, nid)) != AC_WID_AUD_MIX)
path->multi[path->depth] = 1;
path->depth++;
return true;
}
static bool parse_output_path(struct hda_codec *codec, hda_nid_t nid,
hda_nid_t target_dac, int with_aa_mix,
struct nid_path *path)
{
if (__parse_output_path(codec, nid, target_dac, with_aa_mix, path, 1)) {
path->path[path->depth] = nid;
path->depth++;
snd_printdd("output-path: depth=%d, %02x/%02x/%02x/%02x/%02x\n",
path->depth, path->path[0], path->path[1],
path->path[2], path->path[3], path->path[4]);
return true;
}
return false;
}
static int via_auto_fill_dac_nids(struct hda_codec *codec)
{
struct via_spec *spec = codec->spec;
const struct auto_pin_cfg *cfg = &spec->autocfg;
int i, dac_num;
hda_nid_t nid;
spec->multiout.dac_nids = spec->private_dac_nids;
dac_num = 0;
for (i = 0; i < cfg->line_outs; i++) {
hda_nid_t dac = 0;
nid = cfg->line_out_pins[i];
if (!nid)
continue;
if (parse_output_path(codec, nid, 0, 0, &spec->out_path[i]))
dac = spec->out_path[i].path[0];
if (!i && parse_output_path(codec, nid, dac, 1,
&spec->out_mix_path))
dac = spec->out_mix_path.path[0];
if (dac) {
spec->private_dac_nids[i] = dac;
dac_num++;
}
}
if (!spec->out_path[0].depth && spec->out_mix_path.depth) {
spec->out_path[0] = spec->out_mix_path;
spec->out_mix_path.depth = 0;
}
spec->multiout.num_dacs = dac_num;
return 0;
}
static int create_ch_ctls(struct hda_codec *codec, const char *pfx,
int chs, bool check_dac, struct nid_path *path)
{
struct via_spec *spec = codec->spec;
char name[32];
hda_nid_t dac, pin, sel, nid;
int err;
dac = check_dac ? path->path[0] : 0;
pin = path->path[path->depth - 1];
sel = path->depth > 1 ? path->path[1] : 0;
if (dac && check_amp_caps(codec, dac, HDA_OUTPUT, AC_AMPCAP_NUM_STEPS))
nid = dac;
else if (check_amp_caps(codec, pin, HDA_OUTPUT, AC_AMPCAP_NUM_STEPS))
nid = pin;
else if (check_amp_caps(codec, sel, HDA_OUTPUT, AC_AMPCAP_NUM_STEPS))
nid = sel;
else
nid = 0;
if (nid) {
sprintf(name, "%s Playback Volume", pfx);
err = via_add_control(spec, VIA_CTL_WIDGET_VOL, name,
HDA_COMPOSE_AMP_VAL(nid, chs, 0, HDA_OUTPUT));
if (err < 0)
return err;
path->vol_ctl = nid;
}
if (dac && check_amp_caps(codec, dac, HDA_OUTPUT, AC_AMPCAP_MUTE))
nid = dac;
else if (check_amp_caps(codec, pin, HDA_OUTPUT, AC_AMPCAP_MUTE))
nid = pin;
else if (check_amp_caps(codec, sel, HDA_OUTPUT, AC_AMPCAP_MUTE))
nid = sel;
else
nid = 0;
if (nid) {
sprintf(name, "%s Playback Switch", pfx);
err = via_add_control(spec, VIA_CTL_WIDGET_MUTE, name,
HDA_COMPOSE_AMP_VAL(nid, chs, 0, HDA_OUTPUT));
if (err < 0)
return err;
path->mute_ctl = nid;
}
return 0;
}
static void mangle_smart51(struct hda_codec *codec)
{
struct via_spec *spec = codec->spec;
struct auto_pin_cfg *cfg = &spec->autocfg;
struct auto_pin_cfg_item *ins = cfg->inputs;
int i, j, nums, attr;
int pins[AUTO_CFG_MAX_INS];
for (attr = INPUT_PIN_ATTR_REAR; attr >= INPUT_PIN_ATTR_NORMAL; attr--) {
nums = 0;
for (i = 0; i < cfg->num_inputs; i++) {
unsigned int def;
if (ins[i].type > AUTO_PIN_LINE_IN)
continue;
def = snd_hda_codec_get_pincfg(codec, ins[i].pin);
if (snd_hda_get_input_pin_attr(def) != attr)
continue;
for (j = 0; j < nums; j++)
if (ins[pins[j]].type < ins[i].type) {
memmove(pins + j + 1, pins + j,
(nums - j) * sizeof(int));
break;
}
pins[j] = i;
nums++;
}
if (cfg->line_outs + nums < 3)
continue;
for (i = 0; i < nums; i++) {
hda_nid_t pin = ins[pins[i]].pin;
spec->smart51_pins[spec->smart51_nums++] = pin;
cfg->line_out_pins[cfg->line_outs++] = pin;
if (cfg->line_outs == 3)
break;
}
return;
}
}
static void copy_path_mixer_ctls(struct nid_path *dst, struct nid_path *src)
{
dst->vol_ctl = src->vol_ctl;
dst->mute_ctl = src->mute_ctl;
}
static int via_auto_create_multi_out_ctls(struct hda_codec *codec)
{
struct via_spec *spec = codec->spec;
struct auto_pin_cfg *cfg = &spec->autocfg;
struct nid_path *path;
static const char * const chname[4] = {
"Front", "Surround", "C/LFE", "Side"
};
int i, idx, err;
int old_line_outs;
old_line_outs = cfg->line_outs;
if (cfg->line_outs == 1)
mangle_smart51(codec);
err = via_auto_fill_dac_nids(codec);
if (err < 0)
return err;
if (spec->multiout.num_dacs < 3) {
spec->smart51_nums = 0;
cfg->line_outs = old_line_outs;
}
for (i = 0; i < cfg->line_outs; i++) {
hda_nid_t pin, dac;
pin = cfg->line_out_pins[i];
dac = spec->multiout.dac_nids[i];
if (!pin || !dac)
continue;
path = spec->out_path + i;
if (i == HDA_CLFE) {
err = create_ch_ctls(codec, "Center", 1, true, path);
if (err < 0)
return err;
err = create_ch_ctls(codec, "LFE", 2, true, path);
if (err < 0)
return err;
} else {
const char *pfx = chname[i];
if (cfg->line_out_type == AUTO_PIN_SPEAKER_OUT &&
cfg->line_outs == 1)
pfx = "Speaker";
err = create_ch_ctls(codec, pfx, 3, true, path);
if (err < 0)
return err;
}
if (path != spec->out_path + i)
copy_path_mixer_ctls(&spec->out_path[i], path);
if (path == spec->out_path && spec->out_mix_path.depth)
copy_path_mixer_ctls(&spec->out_mix_path, path);
}
idx = get_connection_index(codec, spec->aa_mix_nid,
spec->multiout.dac_nids[0]);
if (idx >= 0) {
const char *name;
name = spec->out_mix_path.depth ?
"PCM Loopback Playback Volume" : "PCM Playback Volume";
err = via_add_control(spec, VIA_CTL_WIDGET_VOL, name,
HDA_COMPOSE_AMP_VAL(spec->aa_mix_nid, 3,
idx, HDA_INPUT));
if (err < 0)
return err;
name = spec->out_mix_path.depth ?
"PCM Loopback Playback Switch" : "PCM Playback Switch";
err = via_add_control(spec, VIA_CTL_WIDGET_MUTE, name,
HDA_COMPOSE_AMP_VAL(spec->aa_mix_nid, 3,
idx, HDA_INPUT));
if (err < 0)
return err;
}
cfg->line_outs = old_line_outs;
return 0;
}
static int via_auto_create_hp_ctls(struct hda_codec *codec, hda_nid_t pin)
{
struct via_spec *spec = codec->spec;
struct nid_path *path;
bool check_dac;
int i, err;
if (!pin)
return 0;
if (!parse_output_path(codec, pin, 0, 0, &spec->hp_indep_path)) {
for (i = HDA_SIDE; i >= HDA_CLFE; i--) {
if (i < spec->multiout.num_dacs &&
parse_output_path(codec, pin,
spec->multiout.dac_nids[i], 0,
&spec->hp_indep_path)) {
spec->hp_indep_shared = i;
break;
}
}
}
if (spec->hp_indep_path.depth) {
spec->hp_dac_nid = spec->hp_indep_path.path[0];
if (!spec->hp_indep_shared)
spec->hp_path = spec->hp_indep_path;
}
if (!spec->hp_path.depth)
parse_output_path(codec, pin,
spec->multiout.dac_nids[HDA_FRONT], 0,
&spec->hp_path);
if (!parse_output_path(codec, pin, spec->multiout.dac_nids[HDA_FRONT],
1, &spec->hp_mix_path) && !spec->hp_path.depth)
return 0;
if (spec->hp_path.depth) {
path = &spec->hp_path;
check_dac = true;
} else {
path = &spec->hp_mix_path;
check_dac = false;
}
err = create_ch_ctls(codec, "Headphone", 3, check_dac, path);
if (err < 0)
return err;
if (check_dac)
copy_path_mixer_ctls(&spec->hp_mix_path, path);
else
copy_path_mixer_ctls(&spec->hp_path, path);
if (spec->hp_indep_path.depth)
copy_path_mixer_ctls(&spec->hp_indep_path, path);
return 0;
}
static int via_auto_create_speaker_ctls(struct hda_codec *codec)
{
struct via_spec *spec = codec->spec;
struct nid_path *path;
bool check_dac;
hda_nid_t pin, dac = 0;
int err;
pin = spec->autocfg.speaker_pins[0];
if (!spec->autocfg.speaker_outs || !pin)
return 0;
if (parse_output_path(codec, pin, 0, 0, &spec->speaker_path))
dac = spec->speaker_path.path[0];
if (!dac)
parse_output_path(codec, pin,
spec->multiout.dac_nids[HDA_FRONT], 0,
&spec->speaker_path);
if (!parse_output_path(codec, pin, spec->multiout.dac_nids[HDA_FRONT],
1, &spec->speaker_mix_path) && !dac)
return 0;
if (!spec->out_mix_path.depth && spec->speaker_mix_path.depth)
dac = 0;
spec->speaker_dac_nid = dac;
spec->multiout.extra_out_nid[0] = dac;
if (dac) {
path = &spec->speaker_path;
check_dac = true;
} else {
path = &spec->speaker_mix_path;
check_dac = false;
}
err = create_ch_ctls(codec, "Speaker", 3, check_dac, path);
if (err < 0)
return err;
if (check_dac)
copy_path_mixer_ctls(&spec->speaker_mix_path, path);
else
copy_path_mixer_ctls(&spec->speaker_path, path);
return 0;
}
static int via_aamix_ctl_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct via_spec *spec = codec->spec;
ucontrol->value.enumerated.item[0] = spec->aamix_mode;
return 0;
}
static void update_aamix_paths(struct hda_codec *codec, int do_mix,
struct nid_path *nomix, struct nid_path *mix)
{
if (do_mix) {
activate_output_path(codec, nomix, false, false);
activate_output_path(codec, mix, true, false);
} else {
activate_output_path(codec, mix, false, false);
activate_output_path(codec, nomix, true, false);
}
}
static int via_aamix_ctl_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct via_spec *spec = codec->spec;
unsigned int val = ucontrol->value.enumerated.item[0];
if (val == spec->aamix_mode)
return 0;
spec->aamix_mode = val;
update_aamix_paths(codec, val, &spec->out_path[0], &spec->out_mix_path);
if (!spec->hp_independent_mode) {
update_aamix_paths(codec, val, &spec->hp_path,
&spec->hp_mix_path);
}
update_aamix_paths(codec, val, &spec->speaker_path,
&spec->speaker_mix_path);
return 1;
}
static int via_auto_create_loopback_switch(struct hda_codec *codec)
{
struct via_spec *spec = codec->spec;
if (!spec->aa_mix_nid || !spec->out_mix_path.depth)
return 0;
if (!via_clone_control(spec, &via_aamix_ctl_enum))
return -ENOMEM;
return 0;
}
static int via_fill_adcs(struct hda_codec *codec)
{
struct via_spec *spec = codec->spec;
hda_nid_t nid = codec->start_nid;
int i;
for (i = 0; i < codec->num_nodes; i++, nid++) {
unsigned int wcaps = get_wcaps(codec, nid);
if (get_wcaps_type(wcaps) != AC_WID_AUD_IN)
continue;
if (wcaps & AC_WCAP_DIGITAL)
continue;
if (!(wcaps & AC_WCAP_CONN_LIST))
continue;
if (spec->num_adc_nids >= ARRAY_SIZE(spec->adc_nids))
return -ENOMEM;
spec->adc_nids[spec->num_adc_nids++] = nid;
}
return 0;
}
static int via_mux_enum_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct via_spec *spec = codec->spec;
uinfo->type = SNDRV_CTL_ELEM_TYPE_ENUMERATED;
uinfo->count = 1;
uinfo->value.enumerated.items = spec->num_inputs;
if (uinfo->value.enumerated.item >= spec->num_inputs)
uinfo->value.enumerated.item = spec->num_inputs - 1;
strcpy(uinfo->value.enumerated.name,
spec->inputs[uinfo->value.enumerated.item].label);
return 0;
}
static int via_mux_enum_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct via_spec *spec = codec->spec;
unsigned int idx = snd_ctl_get_ioffidx(kcontrol, &ucontrol->id);
ucontrol->value.enumerated.item[0] = spec->cur_mux[idx];
return 0;
}
static int via_mux_enum_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct via_spec *spec = codec->spec;
unsigned int idx = snd_ctl_get_ioffidx(kcontrol, &ucontrol->id);
hda_nid_t mux;
int cur;
cur = ucontrol->value.enumerated.item[0];
if (cur < 0 || cur >= spec->num_inputs)
return -EINVAL;
if (spec->cur_mux[idx] == cur)
return 0;
spec->cur_mux[idx] = cur;
if (spec->dyn_adc_switch) {
int adc_idx = spec->inputs[cur].adc_idx;
mux = spec->mux_nids[adc_idx];
via_dyn_adc_pcm_resetup(codec, cur);
} else {
mux = spec->mux_nids[idx];
if (snd_BUG_ON(!mux))
return -EINVAL;
}
if (mux) {
if (snd_hda_codec_read(codec, mux, 0,
AC_VERB_GET_POWER_STATE, 0x00) != AC_PWRST_D0)
snd_hda_codec_write(codec, mux, 0,
AC_VERB_SET_POWER_STATE, AC_PWRST_D0);
snd_hda_codec_write(codec, mux, 0,
AC_VERB_SET_CONNECT_SEL,
spec->inputs[cur].mux_idx);
}
set_widgets_power_state(codec);
return 0;
}
static int create_input_src_ctls(struct hda_codec *codec, int count)
{
struct via_spec *spec = codec->spec;
struct snd_kcontrol_new *knew;
if (spec->num_inputs <= 1 || !count)
return 0;
knew = via_clone_control(spec, &via_input_src_ctl);
if (!knew)
return -ENOMEM;
knew->count = count;
return 0;
}
static void add_loopback_list(struct via_spec *spec, hda_nid_t mix, int idx)
{
struct hda_amp_list *list;
if (spec->num_loopbacks >= ARRAY_SIZE(spec->loopback_list) - 1)
return;
list = spec->loopback_list + spec->num_loopbacks;
list->nid = mix;
list->dir = HDA_INPUT;
list->idx = idx;
spec->num_loopbacks++;
spec->loopback.amplist = spec->loopback_list;
}
static bool is_reachable_nid(struct hda_codec *codec, hda_nid_t src,
hda_nid_t dst)
{
return snd_hda_get_conn_index(codec, src, dst, 1) >= 0;
}
static bool add_input_route(struct hda_codec *codec, hda_nid_t pin)
{
struct via_spec *spec = codec->spec;
int c, idx;
spec->inputs[spec->num_inputs].adc_idx = -1;
spec->inputs[spec->num_inputs].pin = pin;
for (c = 0; c < spec->num_adc_nids; c++) {
if (spec->mux_nids[c]) {
idx = get_connection_index(codec, spec->mux_nids[c],
pin);
if (idx < 0)
continue;
spec->inputs[spec->num_inputs].mux_idx = idx;
} else {
if (!is_reachable_nid(codec, spec->adc_nids[c], pin))
continue;
}
spec->inputs[spec->num_inputs].adc_idx = c;
if (!spec->dyn_adc_switch &&
spec->num_inputs > 0 && spec->inputs[0].adc_idx != c) {
snd_printd(KERN_INFO
"via: dynamic ADC switching enabled\n");
spec->dyn_adc_switch = 1;
}
return true;
}
return false;
}
static int parse_analog_inputs(struct hda_codec *codec)
{
struct via_spec *spec = codec->spec;
const struct auto_pin_cfg *cfg = &spec->autocfg;
int i, err;
err = via_fill_adcs(codec);
if (err < 0)
return err;
err = get_mux_nids(codec);
if (err < 0)
return err;
for (i = 0; i < cfg->num_inputs; i++) {
if (add_input_route(codec, cfg->inputs[i].pin))
spec->inputs[spec->num_inputs++].label =
hda_get_autocfg_input_label(codec, cfg, i);
}
if (spec->aa_mix_nid &&
add_input_route(codec, spec->aa_mix_nid))
spec->inputs[spec->num_inputs++].label = "Stereo Mixer";
return 0;
}
static int create_loopback_ctls(struct hda_codec *codec)
{
struct via_spec *spec = codec->spec;
const struct auto_pin_cfg *cfg = &spec->autocfg;
const char *prev_label = NULL;
int type_idx = 0;
int i, j, err, idx;
if (!spec->aa_mix_nid)
return 0;
for (i = 0; i < cfg->num_inputs; i++) {
hda_nid_t pin = cfg->inputs[i].pin;
const char *label = hda_get_autocfg_input_label(codec, cfg, i);
if (prev_label && !strcmp(label, prev_label))
type_idx++;
else
type_idx = 0;
prev_label = label;
idx = get_connection_index(codec, spec->aa_mix_nid, pin);
if (idx >= 0) {
err = via_new_analog_input(spec, label, type_idx,
idx, spec->aa_mix_nid);
if (err < 0)
return err;
add_loopback_list(spec, spec->aa_mix_nid, idx);
}
for (j = 0; j < spec->smart51_nums; j++) {
if (spec->smart51_pins[j] == pin) {
spec->smart51_idxs[j] = idx;
spec->smart51_labels[j] = label;
break;
}
}
}
return 0;
}
static int create_mic_boost_ctls(struct hda_codec *codec)
{
struct via_spec *spec = codec->spec;
const struct auto_pin_cfg *cfg = &spec->autocfg;
int i, err;
for (i = 0; i < cfg->num_inputs; i++) {
hda_nid_t pin = cfg->inputs[i].pin;
unsigned int caps;
const char *label;
char name[32];
if (cfg->inputs[i].type != AUTO_PIN_MIC)
continue;
caps = query_amp_caps(codec, pin, HDA_INPUT);
if (caps == -1 || !(caps & AC_AMPCAP_NUM_STEPS))
continue;
label = hda_get_autocfg_input_label(codec, cfg, i);
snprintf(name, sizeof(name), "%s Boost Volume", label);
err = via_add_control(spec, VIA_CTL_WIDGET_VOL, name,
HDA_COMPOSE_AMP_VAL(pin, 3, 0, HDA_INPUT));
if (err < 0)
return err;
}
return 0;
}
static int create_multi_adc_ctls(struct hda_codec *codec)
{
struct via_spec *spec = codec->spec;
int i, err;
for (i = 0; i < spec->num_adc_nids; i++) {
hda_nid_t adc = spec->adc_nids[i];
err = __via_add_control(spec, VIA_CTL_WIDGET_VOL,
"Capture Volume", i,
HDA_COMPOSE_AMP_VAL(adc, 3, 0,
HDA_INPUT));
if (err < 0)
return err;
err = __via_add_control(spec, VIA_CTL_WIDGET_MUTE,
"Capture Switch", i,
HDA_COMPOSE_AMP_VAL(adc, 3, 0,
HDA_INPUT));
if (err < 0)
return err;
}
for (i = 0; i < spec->num_adc_nids; i++)
if (!spec->mux_nids[i])
break;
err = create_input_src_ctls(codec, i);
if (err < 0)
return err;
return 0;
}
static int init_bind_ctl(struct via_spec *spec, struct hda_bind_ctls **ctl_ret,
struct hda_ctl_ops *ops)
{
struct hda_bind_ctls *ctl;
int i;
ctl = kzalloc(sizeof(*ctl) + sizeof(long) * 4, GFP_KERNEL);
if (!ctl)
return -ENOMEM;
ctl->ops = ops;
for (i = 0; i < spec->num_adc_nids; i++)
ctl->values[i] =
HDA_COMPOSE_AMP_VAL(spec->adc_nids[i], 3, 0, HDA_INPUT);
*ctl_ret = ctl;
return 0;
}
static int create_dyn_adc_ctls(struct hda_codec *codec)
{
struct via_spec *spec = codec->spec;
struct snd_kcontrol_new *knew;
int err;
err = init_bind_ctl(spec, &spec->bind_cap_vol, &snd_hda_bind_vol);
if (err < 0)
return err;
err = init_bind_ctl(spec, &spec->bind_cap_sw, &snd_hda_bind_sw);
if (err < 0)
return err;
knew = via_clone_control(spec, &via_bind_cap_vol_ctl);
if (!knew)
return -ENOMEM;
knew->private_value = (long)spec->bind_cap_vol;
knew = via_clone_control(spec, &via_bind_cap_sw_ctl);
if (!knew)
return -ENOMEM;
knew->private_value = (long)spec->bind_cap_sw;
err = create_input_src_ctls(codec, 1);
if (err < 0)
return err;
return 0;
}
static int via_auto_create_analog_input_ctls(struct hda_codec *codec)
{
struct via_spec *spec = codec->spec;
int err;
err = parse_analog_inputs(codec);
if (err < 0)
return err;
if (spec->dyn_adc_switch)
err = create_dyn_adc_ctls(codec);
else
err = create_multi_adc_ctls(codec);
if (err < 0)
return err;
err = create_loopback_ctls(codec);
if (err < 0)
return err;
err = create_mic_boost_ctls(codec);
if (err < 0)
return err;
return 0;
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
static int vt1708_jack_detect_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct via_spec *spec = codec->spec;
if (spec->codec_type != VT1708)
return 0;
spec->vt1708_jack_detect =
!((snd_hda_codec_read(codec, 0x1, 0, 0xf84, 0) >> 8) & 0x1);
ucontrol->value.integer.value[0] = spec->vt1708_jack_detect;
return 0;
}
static int vt1708_jack_detect_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct via_spec *spec = codec->spec;
int change;
if (spec->codec_type != VT1708)
return 0;
spec->vt1708_jack_detect = ucontrol->value.integer.value[0];
change = (0x1 & (snd_hda_codec_read(codec, 0x1, 0, 0xf84, 0) >> 8))
== !spec->vt1708_jack_detect;
if (spec->vt1708_jack_detect) {
mute_aa_path(codec, 1);
notify_aa_path_ctls(codec);
}
return change;
}
static int via_parse_auto_config(struct hda_codec *codec)
{
struct via_spec *spec = codec->spec;
int err;
err = snd_hda_parse_pin_def_config(codec, &spec->autocfg, NULL);
if (err < 0)
return err;
if (!spec->autocfg.line_outs && !spec->autocfg.hp_pins[0])
return -EINVAL;
err = via_auto_create_multi_out_ctls(codec);
if (err < 0)
return err;
err = via_auto_create_hp_ctls(codec, spec->autocfg.hp_pins[0]);
if (err < 0)
return err;
err = via_auto_create_speaker_ctls(codec);
if (err < 0)
return err;
err = via_auto_create_loopback_switch(codec);
if (err < 0)
return err;
err = via_auto_create_analog_input_ctls(codec);
if (err < 0)
return err;
spec->multiout.max_channels = spec->multiout.num_dacs * 2;
fill_dig_outs(codec);
fill_dig_in(codec);
if (spec->kctls.list)
spec->mixers[spec->num_mixers++] = spec->kctls.list;
if (spec->hp_dac_nid && spec->hp_mix_path.depth) {
err = via_hp_build(codec);
if (err < 0)
return err;
}
err = via_smart51_build(codec);
if (err < 0)
return err;
if (spec->slave_dig_outs[0])
codec->slave_dig_outs = spec->slave_dig_outs;
return 1;
}
static void via_auto_init_dig_outs(struct hda_codec *codec)
{
struct via_spec *spec = codec->spec;
if (spec->multiout.dig_out_nid)
init_output_pin(codec, spec->autocfg.dig_out_pins[0], PIN_OUT);
if (spec->slave_dig_outs[0])
init_output_pin(codec, spec->autocfg.dig_out_pins[1], PIN_OUT);
}
static void via_auto_init_dig_in(struct hda_codec *codec)
{
struct via_spec *spec = codec->spec;
if (!spec->dig_in_nid)
return;
snd_hda_codec_write(codec, spec->autocfg.dig_in_pin, 0,
AC_VERB_SET_PIN_WIDGET_CONTROL, PIN_IN);
}
static void via_auto_init_unsol_event(struct hda_codec *codec)
{
struct via_spec *spec = codec->spec;
struct auto_pin_cfg *cfg = &spec->autocfg;
unsigned int ev;
int i;
if (cfg->hp_pins[0] && is_jack_detectable(codec, cfg->hp_pins[0]))
snd_hda_codec_write(codec, cfg->hp_pins[0], 0,
AC_VERB_SET_UNSOLICITED_ENABLE,
AC_USRSP_EN | VIA_HP_EVENT | VIA_JACK_EVENT);
if (cfg->speaker_pins[0])
ev = VIA_LINE_EVENT;
else
ev = 0;
for (i = 0; i < cfg->line_outs; i++) {
if (cfg->line_out_pins[i] &&
is_jack_detectable(codec, cfg->line_out_pins[i]))
snd_hda_codec_write(codec, cfg->line_out_pins[i], 0,
AC_VERB_SET_UNSOLICITED_ENABLE,
AC_USRSP_EN | ev | VIA_JACK_EVENT);
}
for (i = 0; i < cfg->num_inputs; i++) {
if (is_jack_detectable(codec, cfg->inputs[i].pin))
snd_hda_codec_write(codec, cfg->inputs[i].pin, 0,
AC_VERB_SET_UNSOLICITED_ENABLE,
AC_USRSP_EN | VIA_JACK_EVENT);
}
}
static int via_init(struct hda_codec *codec)
{
struct via_spec *spec = codec->spec;
int i;
for (i = 0; i < spec->num_iverbs; i++)
snd_hda_sequence_write(codec, spec->init_verbs[i]);
via_auto_init_multi_out(codec);
via_auto_init_hp_out(codec);
via_auto_init_speaker_out(codec);
via_auto_init_analog_input(codec);
via_auto_init_dig_outs(codec);
via_auto_init_dig_in(codec);
via_auto_init_unsol_event(codec);
via_hp_automute(codec);
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
spec->aa_mix_nid = 0x17;
vt1708_set_pinconfig_connect(codec, VT1708_HP_PIN_NID);
vt1708_set_pinconfig_connect(codec, VT1708_CD_PIN_NID);
err = via_parse_auto_config(codec);
if (err < 0) {
via_free(codec);
return err;
}
if (!via_clone_control(spec, &vt1708_jack_detect_ctl))
return -ENOMEM;
if (codec->vendor_id == 0x11061708)
spec->stream_analog_playback = &vt1708_pcm_analog_s16_playback;
spec->init_verbs[spec->num_iverbs++] = vt1708_init_verbs;
codec->patch_ops = via_patch_ops;
INIT_DELAYED_WORK(&spec->vt1708_hp_work, vt1708_update_hp_jack_state);
return 0;
}
static int patch_vt1709(struct hda_codec *codec)
{
struct via_spec *spec;
int err;
spec = via_new_spec(codec);
if (spec == NULL)
return -ENOMEM;
spec->aa_mix_nid = 0x18;
err = via_parse_auto_config(codec);
if (err < 0) {
via_free(codec);
return err;
}
codec->patch_ops = via_patch_ops;
return 0;
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
static int patch_vt1708B(struct hda_codec *codec)
{
struct via_spec *spec;
int err;
if (get_codec_type(codec) == VT1708BCE)
return patch_vt1708S(codec);
spec = via_new_spec(codec);
if (spec == NULL)
return -ENOMEM;
spec->aa_mix_nid = 0x16;
err = via_parse_auto_config(codec);
if (err < 0) {
via_free(codec);
return err;
}
codec->patch_ops = via_patch_ops;
spec->set_widgets_power_state = set_widgets_power_state_vt1708B;
return 0;
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
static void fill_dig_in(struct hda_codec *codec)
{
struct via_spec *spec = codec->spec;
hda_nid_t dig_nid;
int i, err;
if (!spec->autocfg.dig_in_pin)
return;
dig_nid = codec->start_nid;
for (i = 0; i < codec->num_nodes; i++, dig_nid++) {
unsigned int wcaps = get_wcaps(codec, dig_nid);
if (get_wcaps_type(wcaps) != AC_WID_AUD_IN)
continue;
if (!(wcaps & AC_WCAP_DIGITAL))
continue;
if (!(wcaps & AC_WCAP_CONN_LIST))
continue;
err = get_connection_index(codec, dig_nid,
spec->autocfg.dig_in_pin);
if (err >= 0) {
spec->dig_in_nid = dig_nid;
break;
}
}
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
spec->aa_mix_nid = 0x16;
override_mic_boost(codec, 0x1a, 0, 3, 40);
override_mic_boost(codec, 0x1e, 0, 3, 40);
err = via_parse_auto_config(codec);
if (err < 0) {
via_free(codec);
return err;
}
spec->init_verbs[spec->num_iverbs++] = vt1708S_init_verbs;
codec->patch_ops = via_patch_ops;
if (get_codec_type(codec) == VT1708BCE) {
kfree(codec->chip_name);
codec->chip_name = kstrdup("VT1708BCE", GFP_KERNEL);
snprintf(codec->bus->card->mixername,
sizeof(codec->bus->card->mixername),
"%s %s", codec->vendor_name, codec->chip_name);
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
spec->aa_mix_nid = 0x1a;
snd_hda_override_amp_caps(codec, 0x1A, HDA_INPUT,
(0x17 << AC_AMPCAP_OFFSET_SHIFT) |
(0x17 << AC_AMPCAP_NUM_STEPS_SHIFT) |
(0x5 << AC_AMPCAP_STEP_SIZE_SHIFT) |
(1 << AC_AMPCAP_MUTE_SHIFT));
err = via_parse_auto_config(codec);
if (err < 0) {
via_free(codec);
return err;
}
spec->init_verbs[spec->num_iverbs++] = vt1702_init_verbs;
codec->patch_ops = via_patch_ops;
spec->set_widgets_power_state = set_widgets_power_state_vt1702;
return 0;
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
static int add_secret_dac_path(struct hda_codec *codec)
{
struct via_spec *spec = codec->spec;
int i, nums;
hda_nid_t conn[8];
hda_nid_t nid;
if (!spec->aa_mix_nid)
return 0;
nums = snd_hda_get_connections(codec, spec->aa_mix_nid, conn,
ARRAY_SIZE(conn) - 1);
for (i = 0; i < nums; i++) {
if (get_wcaps_type(get_wcaps(codec, conn[i])) == AC_WID_AUD_OUT)
return 0;
}
nid = codec->start_nid;
for (i = 0; i < codec->num_nodes; i++, nid++) {
unsigned int caps = get_wcaps(codec, nid);
if (get_wcaps_type(caps) == AC_WID_AUD_OUT &&
!(caps & AC_WCAP_DIGITAL)) {
conn[nums++] = nid;
return snd_hda_override_conn_list(codec,
spec->aa_mix_nid,
nums, conn);
}
}
return 0;
}
static int patch_vt1718S(struct hda_codec *codec)
{
struct via_spec *spec;
int err;
spec = via_new_spec(codec);
if (spec == NULL)
return -ENOMEM;
spec->aa_mix_nid = 0x21;
override_mic_boost(codec, 0x2b, 0, 3, 40);
override_mic_boost(codec, 0x29, 0, 3, 40);
add_secret_dac_path(codec);
err = via_parse_auto_config(codec);
if (err < 0) {
via_free(codec);
return err;
}
spec->init_verbs[spec->num_iverbs++] = vt1718S_init_verbs;
codec->patch_ops = via_patch_ops;
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
spec->aa_mix_nid = 0x16;
override_mic_boost(codec, 0x1a, 0, 3, 40);
override_mic_boost(codec, 0x1e, 0, 3, 40);
err = via_parse_auto_config(codec);
if (err < 0) {
via_free(codec);
return err;
}
spec->init_verbs[spec->num_iverbs++] = vt1716S_init_verbs;
spec->mixers[spec->num_mixers] = vt1716s_dmic_mixer;
spec->num_mixers++;
spec->mixers[spec->num_mixers++] = vt1716S_mono_out_mixer;
codec->patch_ops = via_patch_ops;
spec->set_widgets_power_state = set_widgets_power_state_vt1716S;
return 0;
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
spec->aa_mix_nid = 0x21;
override_mic_boost(codec, 0x2b, 0, 3, 40);
override_mic_boost(codec, 0x29, 0, 3, 40);
add_secret_dac_path(codec);
err = via_parse_auto_config(codec);
if (err < 0) {
via_free(codec);
return err;
}
if (spec->codec_type == VT1802)
spec->init_verbs[spec->num_iverbs++] = vt1802_init_verbs;
else
spec->init_verbs[spec->num_iverbs++] = vt2002P_init_verbs;
codec->patch_ops = via_patch_ops;
spec->set_widgets_power_state = set_widgets_power_state_vt2002P;
return 0;
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
spec->aa_mix_nid = 0x21;
override_mic_boost(codec, 0x2b, 0, 3, 40);
override_mic_boost(codec, 0x29, 0, 3, 40);
add_secret_dac_path(codec);
err = via_parse_auto_config(codec);
if (err < 0) {
via_free(codec);
return err;
}
spec->init_verbs[spec->num_iverbs++] = vt1812_init_verbs;
codec->patch_ops = via_patch_ops;
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
