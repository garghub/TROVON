static bool check_amp_caps(struct hda_codec *codec, hda_nid_t nid,
int dir, unsigned int bits)
{
if (!nid)
return false;
if (get_wcaps(codec, nid) & (1 << (dir + 1)))
if (query_amp_caps(codec, nid, dir) & bits)
return true;
return false;
}
static int alc_mux_enum_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct alc_spec *spec = codec->spec;
unsigned int mux_idx = snd_ctl_get_ioffidx(kcontrol, &uinfo->id);
if (mux_idx >= spec->num_mux_defs)
mux_idx = 0;
if (!spec->input_mux[mux_idx].num_items && mux_idx > 0)
mux_idx = 0;
return snd_hda_input_mux_info(&spec->input_mux[mux_idx], uinfo);
}
static int alc_mux_enum_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct alc_spec *spec = codec->spec;
unsigned int adc_idx = snd_ctl_get_ioffidx(kcontrol, &ucontrol->id);
ucontrol->value.enumerated.item[0] = spec->cur_mux[adc_idx];
return 0;
}
static bool alc_dyn_adc_pcm_resetup(struct hda_codec *codec, int cur)
{
struct alc_spec *spec = codec->spec;
hda_nid_t new_adc = spec->adc_nids[spec->dyn_adc_idx[cur]];
if (spec->cur_adc && spec->cur_adc != new_adc) {
__snd_hda_codec_cleanup_stream(codec, spec->cur_adc, 1);
spec->cur_adc = new_adc;
snd_hda_codec_setup_stream(codec, new_adc,
spec->cur_adc_stream_tag, 0,
spec->cur_adc_format);
return true;
}
return false;
}
static inline hda_nid_t get_capsrc(struct alc_spec *spec, int idx)
{
return spec->capsrc_nids ?
spec->capsrc_nids[idx] : spec->adc_nids[idx];
}
static void update_shared_mic_hp(struct hda_codec *codec, bool set_as_mic)
{
struct alc_spec *spec = codec->spec;
unsigned int val;
hda_nid_t pin = spec->autocfg.inputs[1].pin;
val = snd_hda_get_default_vref(codec, pin);
if (val == AC_PINCTL_VREF_HIZ) {
const hda_nid_t vref_pin = 0x18;
if (get_wcaps_type(get_wcaps(codec, vref_pin)) == AC_WID_PIN &&
get_defcfg_connect(snd_hda_codec_get_pincfg(codec, vref_pin)) == AC_JACK_PORT_NONE) {
unsigned int vref_val = snd_hda_get_default_vref(codec, vref_pin);
if (vref_val != AC_PINCTL_VREF_HIZ)
snd_hda_set_pin_ctl(codec, vref_pin, PIN_IN | (set_as_mic ? vref_val : 0));
}
}
val = set_as_mic ? val | PIN_IN : PIN_HP;
snd_hda_set_pin_ctl(codec, pin, val);
spec->automute_speaker = !set_as_mic;
call_update_outputs(codec);
}
static int alc_mux_select(struct hda_codec *codec, unsigned int adc_idx,
unsigned int idx, bool force)
{
struct alc_spec *spec = codec->spec;
const struct hda_input_mux *imux;
unsigned int mux_idx;
int i, type, num_conns;
hda_nid_t nid;
if (!spec->input_mux)
return 0;
mux_idx = adc_idx >= spec->num_mux_defs ? 0 : adc_idx;
imux = &spec->input_mux[mux_idx];
if (!imux->num_items && mux_idx > 0)
imux = &spec->input_mux[0];
if (!imux->num_items)
return 0;
if (idx >= imux->num_items)
idx = imux->num_items - 1;
if (spec->cur_mux[adc_idx] == idx && !force)
return 0;
spec->cur_mux[adc_idx] = idx;
if (spec->shared_mic_hp)
update_shared_mic_hp(codec, spec->cur_mux[adc_idx]);
if (spec->dyn_adc_switch) {
alc_dyn_adc_pcm_resetup(codec, idx);
adc_idx = spec->dyn_adc_idx[idx];
}
nid = get_capsrc(spec, adc_idx);
num_conns = snd_hda_get_num_conns(codec, nid);
if (num_conns <= 1)
return 1;
type = get_wcaps_type(get_wcaps(codec, nid));
if (type == AC_WID_AUD_MIX) {
int active = imux->items[idx].index;
for (i = 0; i < num_conns; i++) {
unsigned int v = (i == active) ? 0 : HDA_AMP_MUTE;
snd_hda_codec_amp_stereo(codec, nid, HDA_INPUT, i,
HDA_AMP_MUTE, v);
}
} else {
snd_hda_codec_write_cache(codec, nid, 0,
AC_VERB_SET_CONNECT_SEL,
imux->items[idx].index);
}
alc_inv_dmic_sync(codec, true);
return 1;
}
static int alc_mux_enum_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
unsigned int adc_idx = snd_ctl_get_ioffidx(kcontrol, &ucontrol->id);
return alc_mux_select(codec, adc_idx,
ucontrol->value.enumerated.item[0], false);
}
static void alc_set_input_pin(struct hda_codec *codec, hda_nid_t nid,
int auto_pin_type)
{
unsigned int val = PIN_IN;
if (auto_pin_type == AUTO_PIN_MIC)
val |= snd_hda_get_default_vref(codec, nid);
snd_hda_set_pin_ctl(codec, nid, val);
}
static void add_mixer(struct alc_spec *spec, const struct snd_kcontrol_new *mix)
{
if (snd_BUG_ON(spec->num_mixers >= ARRAY_SIZE(spec->mixers)))
return;
spec->mixers[spec->num_mixers++] = mix;
}
static void alc_fix_pll(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
unsigned int val;
if (!spec->pll_nid)
return;
snd_hda_codec_write(codec, spec->pll_nid, 0, AC_VERB_SET_COEF_INDEX,
spec->pll_coef_idx);
val = snd_hda_codec_read(codec, spec->pll_nid, 0,
AC_VERB_GET_PROC_COEF, 0);
snd_hda_codec_write(codec, spec->pll_nid, 0, AC_VERB_SET_COEF_INDEX,
spec->pll_coef_idx);
snd_hda_codec_write(codec, spec->pll_nid, 0, AC_VERB_SET_PROC_COEF,
val & ~(1 << spec->pll_coef_bit));
}
static void alc_fix_pll_init(struct hda_codec *codec, hda_nid_t nid,
unsigned int coef_idx, unsigned int coef_bit)
{
struct alc_spec *spec = codec->spec;
spec->pll_nid = nid;
spec->pll_coef_idx = coef_idx;
spec->pll_coef_bit = coef_bit;
alc_fix_pll(codec);
}
static bool detect_jacks(struct hda_codec *codec, int num_pins, hda_nid_t *pins)
{
int i, present = 0;
for (i = 0; i < num_pins; i++) {
hda_nid_t nid = pins[i];
if (!nid)
break;
present |= snd_hda_jack_detect(codec, nid);
}
return present;
}
static void do_automute(struct hda_codec *codec, int num_pins, hda_nid_t *pins,
bool mute, bool hp_out)
{
struct alc_spec *spec = codec->spec;
unsigned int mute_bits = mute ? HDA_AMP_MUTE : 0;
unsigned int pin_bits = mute ? 0 : (hp_out ? PIN_HP : PIN_OUT);
int i;
for (i = 0; i < num_pins; i++) {
hda_nid_t nid = pins[i];
unsigned int val;
if (!nid)
break;
switch (spec->automute_mode) {
case ALC_AUTOMUTE_PIN:
if (spec->keep_vref_in_automute) {
val = snd_hda_codec_read(codec, nid, 0,
AC_VERB_GET_PIN_WIDGET_CONTROL, 0);
val &= ~PIN_HP;
} else
val = 0;
val |= pin_bits;
snd_hda_set_pin_ctl(codec, nid, val);
break;
case ALC_AUTOMUTE_AMP:
snd_hda_codec_amp_stereo(codec, nid, HDA_OUTPUT, 0,
HDA_AMP_MUTE, mute_bits);
break;
case ALC_AUTOMUTE_MIXER:
nid = spec->automute_mixer_nid[i];
if (!nid)
break;
snd_hda_codec_amp_stereo(codec, nid, HDA_INPUT, 0,
HDA_AMP_MUTE, mute_bits);
snd_hda_codec_amp_stereo(codec, nid, HDA_INPUT, 1,
HDA_AMP_MUTE, mute_bits);
break;
}
}
}
static void update_outputs(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
int on;
if (!spec->shared_mic_hp)
do_automute(codec, ARRAY_SIZE(spec->autocfg.hp_pins),
spec->autocfg.hp_pins, spec->master_mute, true);
if (!spec->automute_speaker)
on = 0;
else
on = spec->hp_jack_present | spec->line_jack_present;
on |= spec->master_mute;
do_automute(codec, ARRAY_SIZE(spec->autocfg.speaker_pins),
spec->autocfg.speaker_pins, on, false);
if (spec->autocfg.line_out_pins[0] == spec->autocfg.hp_pins[0] ||
spec->autocfg.line_out_pins[0] == spec->autocfg.speaker_pins[0])
return;
if (!spec->automute_lo)
on = 0;
else
on = spec->hp_jack_present;
on |= spec->master_mute;
do_automute(codec, ARRAY_SIZE(spec->autocfg.line_out_pins),
spec->autocfg.line_out_pins, on, false);
}
static void call_update_outputs(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
if (spec->automute_hook)
spec->automute_hook(codec);
else
update_outputs(codec);
}
static void alc_hp_automute(struct hda_codec *codec, struct hda_jack_tbl *jack)
{
struct alc_spec *spec = codec->spec;
spec->hp_jack_present =
detect_jacks(codec, ARRAY_SIZE(spec->autocfg.hp_pins),
spec->autocfg.hp_pins);
if (!spec->detect_hp || (!spec->automute_speaker && !spec->automute_lo))
return;
call_update_outputs(codec);
}
static void alc_line_automute(struct hda_codec *codec, struct hda_jack_tbl *jack)
{
struct alc_spec *spec = codec->spec;
if (spec->autocfg.line_out_type == AUTO_PIN_SPEAKER_OUT)
return;
if (spec->autocfg.line_out_pins[0] == spec->autocfg.hp_pins[0])
return;
spec->line_jack_present =
detect_jacks(codec, ARRAY_SIZE(spec->autocfg.line_out_pins),
spec->autocfg.line_out_pins);
if (!spec->automute_speaker || !spec->detect_lo)
return;
call_update_outputs(codec);
}
static void alc_mic_automute(struct hda_codec *codec, struct hda_jack_tbl *jack)
{
struct alc_spec *spec = codec->spec;
hda_nid_t *pins = spec->imux_pins;
if (!spec->auto_mic || !spec->auto_mic_valid_imux)
return;
if (snd_BUG_ON(!spec->adc_nids))
return;
if (snd_BUG_ON(spec->int_mic_idx < 0 || spec->ext_mic_idx < 0))
return;
if (snd_hda_jack_detect(codec, pins[spec->ext_mic_idx]))
alc_mux_select(codec, 0, spec->ext_mic_idx, false);
else if (spec->dock_mic_idx >= 0 &&
snd_hda_jack_detect(codec, pins[spec->dock_mic_idx]))
alc_mux_select(codec, 0, spec->dock_mic_idx, false);
else
alc_mux_select(codec, 0, spec->int_mic_idx, false);
}
static void alc_update_knob_master(struct hda_codec *codec, struct hda_jack_tbl *jack)
{
unsigned int val;
struct snd_kcontrol *kctl;
struct snd_ctl_elem_value *uctl;
kctl = snd_hda_find_mixer_ctl(codec, "Master Playback Volume");
if (!kctl)
return;
uctl = kzalloc(sizeof(*uctl), GFP_KERNEL);
if (!uctl)
return;
val = snd_hda_codec_read(codec, jack->nid, 0,
AC_VERB_GET_VOLUME_KNOB_CONTROL, 0);
val &= HDA_AMP_VOLMASK;
uctl->value.integer.value[0] = val;
uctl->value.integer.value[1] = val;
kctl->put(kctl, uctl);
kfree(uctl);
}
static void alc880_unsol_event(struct hda_codec *codec, unsigned int res)
{
snd_hda_jack_unsol_event(codec, res >> 2);
}
static void alc_inithook(struct hda_codec *codec)
{
alc_hp_automute(codec, NULL);
alc_line_automute(codec, NULL);
alc_mic_automute(codec, NULL);
}
static void alc888_coef_init(struct hda_codec *codec)
{
unsigned int tmp;
snd_hda_codec_write(codec, 0x20, 0, AC_VERB_SET_COEF_INDEX, 0);
tmp = snd_hda_codec_read(codec, 0x20, 0, AC_VERB_GET_PROC_COEF, 0);
snd_hda_codec_write(codec, 0x20, 0, AC_VERB_SET_COEF_INDEX, 7);
if ((tmp & 0xf0) == 0x20)
snd_hda_codec_read(codec, 0x20, 0,
AC_VERB_SET_PROC_COEF, 0x830);
else
snd_hda_codec_read(codec, 0x20, 0,
AC_VERB_SET_PROC_COEF, 0x3030);
}
static void alc889_coef_init(struct hda_codec *codec)
{
unsigned int tmp;
snd_hda_codec_write(codec, 0x20, 0, AC_VERB_SET_COEF_INDEX, 7);
tmp = snd_hda_codec_read(codec, 0x20, 0, AC_VERB_GET_PROC_COEF, 0);
snd_hda_codec_write(codec, 0x20, 0, AC_VERB_SET_COEF_INDEX, 7);
snd_hda_codec_write(codec, 0x20, 0, AC_VERB_SET_PROC_COEF, tmp|0x2010);
}
static void set_eapd(struct hda_codec *codec, hda_nid_t nid, int on)
{
if (get_wcaps_type(get_wcaps(codec, nid)) != AC_WID_PIN)
return;
if (snd_hda_query_pin_caps(codec, nid) & AC_PINCAP_EAPD)
snd_hda_codec_write(codec, nid, 0, AC_VERB_SET_EAPD_BTLENABLE,
on ? 2 : 0);
}
static void alc_auto_setup_eapd(struct hda_codec *codec, bool on)
{
static hda_nid_t pins[] = {
0x0f, 0x10, 0x14, 0x15, 0
};
hda_nid_t *p;
for (p = pins; *p; p++)
set_eapd(codec, *p, on);
}
static void alc_eapd_shutup(struct hda_codec *codec)
{
alc_auto_setup_eapd(codec, false);
msleep(200);
}
static void alc_auto_init_amp(struct hda_codec *codec, int type)
{
unsigned int tmp;
alc_auto_setup_eapd(codec, true);
switch (type) {
case ALC_INIT_GPIO1:
snd_hda_sequence_write(codec, alc_gpio1_init_verbs);
break;
case ALC_INIT_GPIO2:
snd_hda_sequence_write(codec, alc_gpio2_init_verbs);
break;
case ALC_INIT_GPIO3:
snd_hda_sequence_write(codec, alc_gpio3_init_verbs);
break;
case ALC_INIT_DEFAULT:
switch (codec->vendor_id) {
case 0x10ec0260:
snd_hda_codec_write(codec, 0x1a, 0,
AC_VERB_SET_COEF_INDEX, 7);
tmp = snd_hda_codec_read(codec, 0x1a, 0,
AC_VERB_GET_PROC_COEF, 0);
snd_hda_codec_write(codec, 0x1a, 0,
AC_VERB_SET_COEF_INDEX, 7);
snd_hda_codec_write(codec, 0x1a, 0,
AC_VERB_SET_PROC_COEF,
tmp | 0x2010);
break;
case 0x10ec0262:
case 0x10ec0880:
case 0x10ec0882:
case 0x10ec0883:
case 0x10ec0885:
case 0x10ec0887:
alc889_coef_init(codec);
break;
case 0x10ec0888:
alc888_coef_init(codec);
break;
#if 0
case 0x10ec0267:
case 0x10ec0268:
snd_hda_codec_write(codec, 0x20, 0,
AC_VERB_SET_COEF_INDEX, 7);
tmp = snd_hda_codec_read(codec, 0x20, 0,
AC_VERB_GET_PROC_COEF, 0);
snd_hda_codec_write(codec, 0x20, 0,
AC_VERB_SET_COEF_INDEX, 7);
snd_hda_codec_write(codec, 0x20, 0,
AC_VERB_SET_PROC_COEF,
tmp | 0x3000);
break;
#endif
}
break;
}
}
static int alc_automute_mode_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct alc_spec *spec = codec->spec;
static const char * const texts3[] = {
"Disabled", "Speaker Only", "Line Out+Speaker"
};
if (spec->automute_speaker_possible && spec->automute_lo_possible)
return snd_hda_enum_helper_info(kcontrol, uinfo, 3, texts3);
return snd_hda_enum_bool_helper_info(kcontrol, uinfo);
}
static int alc_automute_mode_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct alc_spec *spec = codec->spec;
unsigned int val = 0;
if (spec->automute_speaker)
val++;
if (spec->automute_lo)
val++;
ucontrol->value.enumerated.item[0] = val;
return 0;
}
static int alc_automute_mode_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct alc_spec *spec = codec->spec;
switch (ucontrol->value.enumerated.item[0]) {
case 0:
if (!spec->automute_speaker && !spec->automute_lo)
return 0;
spec->automute_speaker = 0;
spec->automute_lo = 0;
break;
case 1:
if (spec->automute_speaker_possible) {
if (!spec->automute_lo && spec->automute_speaker)
return 0;
spec->automute_speaker = 1;
spec->automute_lo = 0;
} else if (spec->automute_lo_possible) {
if (spec->automute_lo)
return 0;
spec->automute_lo = 1;
} else
return -EINVAL;
break;
case 2:
if (!spec->automute_lo_possible || !spec->automute_speaker_possible)
return -EINVAL;
if (spec->automute_speaker && spec->automute_lo)
return 0;
spec->automute_speaker = 1;
spec->automute_lo = 1;
break;
default:
return -EINVAL;
}
call_update_outputs(codec);
return 1;
}
static struct snd_kcontrol_new *
alc_kcontrol_new(struct alc_spec *spec, const char *name,
const struct snd_kcontrol_new *temp)
{
struct snd_kcontrol_new *knew = snd_array_new(&spec->kctls);
if (!knew)
return NULL;
*knew = *temp;
knew->name = kstrdup(name, GFP_KERNEL);
if (!knew->name)
return NULL;
return knew;
}
static int alc_add_automute_mode_enum(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
if (!alc_kcontrol_new(spec, "Auto-Mute Mode", &alc_automute_mode_enum))
return -ENOMEM;
return 0;
}
static int alc_init_automute(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
struct auto_pin_cfg *cfg = &spec->autocfg;
int present = 0;
int i, err;
if (cfg->hp_pins[0])
present++;
if (cfg->line_out_pins[0])
present++;
if (cfg->speaker_pins[0])
present++;
if (present < 2)
return 0;
if (!cfg->speaker_pins[0] &&
cfg->line_out_type == AUTO_PIN_SPEAKER_OUT) {
memcpy(cfg->speaker_pins, cfg->line_out_pins,
sizeof(cfg->speaker_pins));
cfg->speaker_outs = cfg->line_outs;
}
if (!cfg->hp_pins[0] &&
cfg->line_out_type == AUTO_PIN_HP_OUT) {
memcpy(cfg->hp_pins, cfg->line_out_pins,
sizeof(cfg->hp_pins));
cfg->hp_outs = cfg->line_outs;
}
spec->automute_mode = ALC_AUTOMUTE_PIN;
for (i = 0; i < cfg->hp_outs; i++) {
hda_nid_t nid = cfg->hp_pins[i];
if (!is_jack_detectable(codec, nid))
continue;
snd_printdd("realtek: Enable HP auto-muting on NID 0x%x\n",
nid);
snd_hda_jack_detect_enable_callback(codec, nid, ALC_HP_EVENT,
alc_hp_automute);
spec->detect_hp = 1;
}
if (cfg->line_out_type == AUTO_PIN_LINE_OUT && cfg->line_outs) {
if (cfg->speaker_outs)
for (i = 0; i < cfg->line_outs; i++) {
hda_nid_t nid = cfg->line_out_pins[i];
if (!is_jack_detectable(codec, nid))
continue;
snd_printdd("realtek: Enable Line-Out "
"auto-muting on NID 0x%x\n", nid);
snd_hda_jack_detect_enable_callback(codec, nid, ALC_FRONT_EVENT,
alc_line_automute);
spec->detect_lo = 1;
}
spec->automute_lo_possible = spec->detect_hp;
}
spec->automute_speaker_possible = cfg->speaker_outs &&
(spec->detect_hp || spec->detect_lo);
spec->automute_lo = spec->automute_lo_possible;
spec->automute_speaker = spec->automute_speaker_possible;
if (spec->automute_speaker_possible || spec->automute_lo_possible) {
err = alc_add_automute_mode_enum(codec);
if (err < 0)
return err;
}
return 0;
}
static int find_idx_in_nid_list(hda_nid_t nid, const hda_nid_t *list, int nums)
{
int i;
for (i = 0; i < nums; i++)
if (list[i] == nid)
return i;
return -1;
}
static bool alc_check_dyn_adc_switch(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
struct hda_input_mux *imux = &spec->private_imux[0];
int i, n, idx;
hda_nid_t cap, pin;
if (imux != spec->input_mux)
return false;
for (n = 0; n < spec->num_adc_nids; n++) {
cap = spec->private_capsrc_nids[n];
for (i = 0; i < imux->num_items; i++) {
pin = spec->imux_pins[i];
if (!pin)
return false;
if (get_connection_index(codec, cap, pin) < 0)
break;
}
if (i >= imux->num_items)
return true;
}
for (i = 0; i < imux->num_items; i++) {
pin = spec->imux_pins[i];
for (n = 0; n < spec->num_adc_nids; n++) {
cap = spec->private_capsrc_nids[n];
idx = get_connection_index(codec, cap, pin);
if (idx >= 0) {
imux->items[i].index = idx;
spec->dyn_adc_idx[i] = n;
break;
}
}
}
snd_printdd("realtek: enabling ADC switching\n");
spec->dyn_adc_switch = 1;
return true;
}
static bool alc_auto_mic_check_imux(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
const struct hda_input_mux *imux;
if (!spec->auto_mic)
return false;
if (spec->auto_mic_valid_imux)
return true;
if (!alc_check_dyn_adc_switch(codec)) {
spec->auto_mic = 0;
return false;
}
imux = spec->input_mux;
spec->ext_mic_idx = find_idx_in_nid_list(spec->ext_mic_pin,
spec->imux_pins, imux->num_items);
spec->int_mic_idx = find_idx_in_nid_list(spec->int_mic_pin,
spec->imux_pins, imux->num_items);
spec->dock_mic_idx = find_idx_in_nid_list(spec->dock_mic_pin,
spec->imux_pins, imux->num_items);
if (spec->ext_mic_idx < 0 || spec->int_mic_idx < 0) {
spec->auto_mic = 0;
return false;
}
snd_hda_jack_detect_enable_callback(codec, spec->ext_mic_pin,
ALC_MIC_EVENT, alc_mic_automute);
if (spec->dock_mic_pin)
snd_hda_jack_detect_enable_callback(codec, spec->dock_mic_pin,
ALC_MIC_EVENT,
alc_mic_automute);
spec->auto_mic_valid_imux = 1;
spec->auto_mic = 1;
return true;
}
static int alc_init_auto_mic(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
struct auto_pin_cfg *cfg = &spec->autocfg;
hda_nid_t fixed, ext, dock;
int i;
if (spec->shared_mic_hp)
return 0;
spec->ext_mic_idx = spec->int_mic_idx = spec->dock_mic_idx = -1;
fixed = ext = dock = 0;
for (i = 0; i < cfg->num_inputs; i++) {
hda_nid_t nid = cfg->inputs[i].pin;
unsigned int defcfg;
defcfg = snd_hda_codec_get_pincfg(codec, nid);
switch (snd_hda_get_input_pin_attr(defcfg)) {
case INPUT_PIN_ATTR_INT:
if (fixed)
return 0;
if (cfg->inputs[i].type != AUTO_PIN_MIC)
return 0;
fixed = nid;
break;
case INPUT_PIN_ATTR_UNUSED:
return 0;
case INPUT_PIN_ATTR_DOCK:
if (dock)
return 0;
if (cfg->inputs[i].type > AUTO_PIN_LINE_IN)
return 0;
dock = nid;
break;
default:
if (ext)
return 0;
if (cfg->inputs[i].type != AUTO_PIN_MIC)
return 0;
ext = nid;
break;
}
}
if (!ext && dock) {
ext = dock;
dock = 0;
}
if (!ext || !fixed)
return 0;
if (!is_jack_detectable(codec, ext))
return 0;
if (dock && !is_jack_detectable(codec, dock))
return 0;
spec->ext_mic_pin = ext;
spec->int_mic_pin = fixed;
spec->dock_mic_pin = dock;
spec->auto_mic = 1;
if (!alc_auto_mic_check_imux(codec))
return 0;
snd_printdd("realtek: Enable auto-mic switch on NID 0x%x/0x%x/0x%x\n",
ext, fixed, dock);
return 0;
}
static int alc_auto_check_switches(struct hda_codec *codec)
{
int err;
err = alc_init_automute(codec);
if (err < 0)
return err;
err = alc_init_auto_mic(codec);
if (err < 0)
return err;
return 0;
}
static void alc_fixup_sku_ignore(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
struct alc_spec *spec = codec->spec;
if (action == HDA_FIXUP_ACT_PRE_PROBE) {
spec->cdefine.fixup = 1;
spec->cdefine.sku_cfg = ALC_FIXUP_SKU_IGNORE;
}
}
static int alc_auto_parse_customize_define(struct hda_codec *codec)
{
unsigned int ass, tmp, i;
unsigned nid = 0;
struct alc_spec *spec = codec->spec;
spec->cdefine.enable_pcbeep = 1;
if (spec->cdefine.fixup) {
ass = spec->cdefine.sku_cfg;
if (ass == ALC_FIXUP_SKU_IGNORE)
return -1;
goto do_sku;
}
ass = codec->subsystem_id & 0xffff;
if (ass != codec->bus->pci->subsystem_device && (ass & 1))
goto do_sku;
nid = 0x1d;
if (codec->vendor_id == 0x10ec0260)
nid = 0x17;
ass = snd_hda_codec_get_pincfg(codec, nid);
if (!(ass & 1)) {
printk(KERN_INFO "hda_codec: %s: SKU not ready 0x%08x\n",
codec->chip_name, ass);
return -1;
}
tmp = 0;
for (i = 1; i < 16; i++) {
if ((ass >> i) & 1)
tmp++;
}
if (((ass >> 16) & 0xf) != tmp)
return -1;
spec->cdefine.port_connectivity = ass >> 30;
spec->cdefine.enable_pcbeep = (ass & 0x100000) >> 20;
spec->cdefine.check_sum = (ass >> 16) & 0xf;
spec->cdefine.customization = ass >> 8;
do_sku:
spec->cdefine.sku_cfg = ass;
spec->cdefine.external_amp = (ass & 0x38) >> 3;
spec->cdefine.platform_type = (ass & 0x4) >> 2;
spec->cdefine.swap = (ass & 0x2) >> 1;
spec->cdefine.override = ass & 0x1;
snd_printd("SKU: Nid=0x%x sku_cfg=0x%08x\n",
nid, spec->cdefine.sku_cfg);
snd_printd("SKU: port_connectivity=0x%x\n",
spec->cdefine.port_connectivity);
snd_printd("SKU: enable_pcbeep=0x%x\n", spec->cdefine.enable_pcbeep);
snd_printd("SKU: check_sum=0x%08x\n", spec->cdefine.check_sum);
snd_printd("SKU: customization=0x%08x\n", spec->cdefine.customization);
snd_printd("SKU: external_amp=0x%x\n", spec->cdefine.external_amp);
snd_printd("SKU: platform_type=0x%x\n", spec->cdefine.platform_type);
snd_printd("SKU: swap=0x%x\n", spec->cdefine.swap);
snd_printd("SKU: override=0x%x\n", spec->cdefine.override);
return 0;
}
static bool found_in_nid_list(hda_nid_t nid, const hda_nid_t *list, int nums)
{
return find_idx_in_nid_list(nid, list, nums) >= 0;
}
static int alc_subsystem_id(struct hda_codec *codec,
hda_nid_t porta, hda_nid_t porte,
hda_nid_t portd, hda_nid_t porti)
{
unsigned int ass, tmp, i;
unsigned nid;
struct alc_spec *spec = codec->spec;
if (spec->cdefine.fixup) {
ass = spec->cdefine.sku_cfg;
if (ass == ALC_FIXUP_SKU_IGNORE)
return 0;
goto do_sku;
}
ass = codec->subsystem_id & 0xffff;
if ((ass != codec->bus->pci->subsystem_device) && (ass & 1))
goto do_sku;
nid = 0x1d;
if (codec->vendor_id == 0x10ec0260)
nid = 0x17;
ass = snd_hda_codec_get_pincfg(codec, nid);
snd_printd("realtek: No valid SSID, "
"checking pincfg 0x%08x for NID 0x%x\n",
ass, nid);
if (!(ass & 1))
return 0;
if ((ass >> 30) != 1)
return 0;
tmp = 0;
for (i = 1; i < 16; i++) {
if ((ass >> i) & 1)
tmp++;
}
if (((ass >> 16) & 0xf) != tmp)
return 0;
do_sku:
snd_printd("realtek: Enabling init ASM_ID=0x%04x CODEC_ID=%08x\n",
ass & 0xffff, codec->vendor_id);
tmp = (ass & 0x38) >> 3;
switch (tmp) {
case 1:
spec->init_amp = ALC_INIT_GPIO1;
break;
case 3:
spec->init_amp = ALC_INIT_GPIO2;
break;
case 7:
spec->init_amp = ALC_INIT_GPIO3;
break;
case 5:
default:
spec->init_amp = ALC_INIT_DEFAULT;
break;
}
if (!(ass & 0x8000))
return 1;
if (!spec->autocfg.hp_pins[0] &&
!(spec->autocfg.line_out_pins[0] &&
spec->autocfg.line_out_type == AUTO_PIN_HP_OUT)) {
hda_nid_t nid;
tmp = (ass >> 11) & 0x3;
if (tmp == 0)
nid = porta;
else if (tmp == 1)
nid = porte;
else if (tmp == 2)
nid = portd;
else if (tmp == 3)
nid = porti;
else
return 1;
if (found_in_nid_list(nid, spec->autocfg.line_out_pins,
spec->autocfg.line_outs))
return 1;
spec->autocfg.hp_pins[0] = nid;
}
return 1;
}
static void alc_ssid_check(struct hda_codec *codec, const hda_nid_t *ports)
{
if (!alc_subsystem_id(codec, ports[0], ports[1], ports[2], ports[3])) {
struct alc_spec *spec = codec->spec;
snd_printd("realtek: "
"Enable default setup for auto mode as fallback\n");
spec->init_amp = ALC_INIT_DEFAULT;
}
}
static int alc_read_coef_idx(struct hda_codec *codec,
unsigned int coef_idx)
{
unsigned int val;
snd_hda_codec_write(codec, 0x20, 0, AC_VERB_SET_COEF_INDEX,
coef_idx);
val = snd_hda_codec_read(codec, 0x20, 0,
AC_VERB_GET_PROC_COEF, 0);
return val;
}
static void alc_write_coef_idx(struct hda_codec *codec, unsigned int coef_idx,
unsigned int coef_val)
{
snd_hda_codec_write(codec, 0x20, 0, AC_VERB_SET_COEF_INDEX,
coef_idx);
snd_hda_codec_write(codec, 0x20, 0, AC_VERB_SET_PROC_COEF,
coef_val);
}
static unsigned int alc_get_coef0(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
if (!spec->coef0)
spec->coef0 = alc_read_coef_idx(codec, 0);
return spec->coef0;
}
static void alc_auto_init_digital(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
int i;
hda_nid_t pin, dac;
for (i = 0; i < spec->autocfg.dig_outs; i++) {
pin = spec->autocfg.dig_out_pins[i];
if (!pin)
continue;
snd_hda_set_pin_ctl(codec, pin, PIN_OUT);
if (!i)
dac = spec->multiout.dig_out_nid;
else
dac = spec->slave_dig_outs[i - 1];
if (!dac || !(get_wcaps(codec, dac) & AC_WCAP_OUT_AMP))
continue;
snd_hda_codec_write(codec, dac, 0,
AC_VERB_SET_AMP_GAIN_MUTE,
AMP_OUT_UNMUTE);
}
pin = spec->autocfg.dig_in_pin;
if (pin)
snd_hda_set_pin_ctl(codec, pin, PIN_IN);
}
static void alc_auto_parse_digital(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
int i, err, nums;
hda_nid_t dig_nid;
nums = 0;
for (i = 0; i < spec->autocfg.dig_outs; i++) {
hda_nid_t conn[4];
err = snd_hda_get_connections(codec,
spec->autocfg.dig_out_pins[i],
conn, ARRAY_SIZE(conn));
if (err <= 0)
continue;
dig_nid = conn[0];
if (!nums) {
spec->multiout.dig_out_nid = dig_nid;
spec->dig_out_type = spec->autocfg.dig_out_type[0];
} else {
spec->multiout.slave_dig_outs = spec->slave_dig_outs;
if (nums >= ARRAY_SIZE(spec->slave_dig_outs) - 1)
break;
spec->slave_dig_outs[nums - 1] = dig_nid;
}
nums++;
}
if (spec->autocfg.dig_in_pin) {
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
}
static int alc_cap_vol_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct alc_spec *spec = codec->spec;
unsigned long val;
int err;
mutex_lock(&codec->control_mutex);
if (spec->vol_in_capsrc)
val = HDA_COMPOSE_AMP_VAL(spec->capsrc_nids[0], 3, 0, HDA_OUTPUT);
else
val = HDA_COMPOSE_AMP_VAL(spec->adc_nids[0], 3, 0, HDA_INPUT);
kcontrol->private_value = val;
err = snd_hda_mixer_amp_volume_info(kcontrol, uinfo);
mutex_unlock(&codec->control_mutex);
return err;
}
static int alc_cap_vol_tlv(struct snd_kcontrol *kcontrol, int op_flag,
unsigned int size, unsigned int __user *tlv)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct alc_spec *spec = codec->spec;
unsigned long val;
int err;
mutex_lock(&codec->control_mutex);
if (spec->vol_in_capsrc)
val = HDA_COMPOSE_AMP_VAL(spec->capsrc_nids[0], 3, 0, HDA_OUTPUT);
else
val = HDA_COMPOSE_AMP_VAL(spec->adc_nids[0], 3, 0, HDA_INPUT);
kcontrol->private_value = val;
err = snd_hda_mixer_amp_tlv(kcontrol, op_flag, size, tlv);
mutex_unlock(&codec->control_mutex);
return err;
}
static int alc_cap_getput_caller(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol,
getput_call_t func, bool is_put)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct alc_spec *spec = codec->spec;
int i, err = 0;
mutex_lock(&codec->control_mutex);
if (is_put && spec->dyn_adc_switch) {
for (i = 0; i < spec->num_adc_nids; i++) {
kcontrol->private_value =
HDA_COMPOSE_AMP_VAL(spec->adc_nids[i],
3, 0, HDA_INPUT);
err = func(kcontrol, ucontrol);
if (err < 0)
goto error;
}
} else {
i = snd_ctl_get_ioffidx(kcontrol, &ucontrol->id);
if (spec->vol_in_capsrc)
kcontrol->private_value =
HDA_COMPOSE_AMP_VAL(spec->capsrc_nids[i],
3, 0, HDA_OUTPUT);
else
kcontrol->private_value =
HDA_COMPOSE_AMP_VAL(spec->adc_nids[i],
3, 0, HDA_INPUT);
err = func(kcontrol, ucontrol);
}
if (err >= 0 && is_put)
alc_inv_dmic_sync(codec, false);
error:
mutex_unlock(&codec->control_mutex);
return err;
}
static int alc_cap_vol_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
return alc_cap_getput_caller(kcontrol, ucontrol,
snd_hda_mixer_amp_volume_get, false);
}
static int alc_cap_vol_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
return alc_cap_getput_caller(kcontrol, ucontrol,
snd_hda_mixer_amp_volume_put, true);
}
static int alc_cap_sw_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
return alc_cap_getput_caller(kcontrol, ucontrol,
snd_hda_mixer_amp_switch_get, false);
}
static int alc_cap_sw_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
return alc_cap_getput_caller(kcontrol, ucontrol,
snd_hda_mixer_amp_switch_put, true);
}
static void alc_inv_dmic_sync(struct hda_codec *codec, bool force)
{
struct alc_spec *spec = codec->spec;
int i;
if (!spec->inv_dmic_fixup)
return;
if (!spec->inv_dmic_muted && !force)
return;
for (i = 0; i < spec->num_adc_nids; i++) {
int src = spec->dyn_adc_switch ? 0 : i;
bool dmic_fixup = false;
hda_nid_t nid;
int parm, dir, v;
if (spec->inv_dmic_muted &&
spec->imux_pins[spec->cur_mux[src]] == spec->inv_dmic_pin)
dmic_fixup = true;
if (!dmic_fixup && !force)
continue;
if (spec->vol_in_capsrc) {
nid = spec->capsrc_nids[i];
parm = AC_AMP_SET_RIGHT | AC_AMP_SET_OUTPUT;
dir = HDA_OUTPUT;
} else {
nid = spec->adc_nids[i];
parm = AC_AMP_SET_RIGHT | AC_AMP_SET_INPUT;
dir = HDA_INPUT;
}
v = snd_hda_codec_amp_read(codec, nid, 1, dir, 0);
if (v & 0x80)
continue;
if (dmic_fixup)
v |= 0x80;
snd_hda_codec_write(codec, nid, 0, AC_VERB_SET_AMP_GAIN_MUTE,
parm | v);
}
}
static int alc_inv_dmic_sw_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct alc_spec *spec = codec->spec;
ucontrol->value.integer.value[0] = !spec->inv_dmic_muted;
return 0;
}
static int alc_inv_dmic_sw_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct alc_spec *spec = codec->spec;
unsigned int val = !ucontrol->value.integer.value[0];
if (val == spec->inv_dmic_muted)
return 0;
spec->inv_dmic_muted = val;
alc_inv_dmic_sync(codec, true);
return 0;
}
static int alc_add_inv_dmic_mixer(struct hda_codec *codec, hda_nid_t nid)
{
struct alc_spec *spec = codec->spec;
if (!alc_kcontrol_new(spec, "Inverted Internal Mic Capture Switch",
&alc_inv_dmic_sw))
return -ENOMEM;
spec->inv_dmic_fixup = 1;
spec->inv_dmic_muted = 0;
spec->inv_dmic_pin = nid;
return 0;
}
static void alc_fixup_inv_dmic_0x12(struct hda_codec *codec,
const struct alc_fixup *fix, int action)
{
if (action == ALC_FIXUP_ACT_PROBE)
alc_add_inv_dmic_mixer(codec, 0x12);
}
static int __alc_build_controls(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
struct snd_kcontrol *kctl = NULL;
const struct snd_kcontrol_new *knew;
int i, j, err;
unsigned int u;
hda_nid_t nid;
for (i = 0; i < spec->num_mixers; i++) {
err = snd_hda_add_new_ctls(codec, spec->mixers[i]);
if (err < 0)
return err;
}
if (spec->cap_mixer) {
err = snd_hda_add_new_ctls(codec, spec->cap_mixer);
if (err < 0)
return err;
}
if (spec->multiout.dig_out_nid) {
err = snd_hda_create_dig_out_ctls(codec,
spec->multiout.dig_out_nid,
spec->multiout.dig_out_nid,
spec->pcm_rec[1].pcm_type);
if (err < 0)
return err;
if (!spec->no_analog) {
err = snd_hda_create_spdif_share_sw(codec,
&spec->multiout);
if (err < 0)
return err;
spec->multiout.share_spdif = 1;
}
}
if (spec->dig_in_nid) {
err = snd_hda_create_spdif_in_ctls(codec, spec->dig_in_nid);
if (err < 0)
return err;
}
#ifdef CONFIG_SND_HDA_INPUT_BEEP
if (spec->beep_amp) {
const struct snd_kcontrol_new *knew;
for (knew = alc_beep_mixer; knew->name; knew++) {
struct snd_kcontrol *kctl;
kctl = snd_ctl_new1(knew, codec);
if (!kctl)
return -ENOMEM;
kctl->private_value = spec->beep_amp;
err = snd_hda_ctl_add(codec, 0, kctl);
if (err < 0)
return err;
}
}
#endif
if (!spec->no_analog &&
!snd_hda_find_mixer_ctl(codec, "Master Playback Volume")) {
unsigned int vmaster_tlv[4];
snd_hda_set_vmaster_tlv(codec, spec->vmaster_nid,
HDA_OUTPUT, vmaster_tlv);
err = snd_hda_add_vmaster(codec, "Master Playback Volume",
vmaster_tlv, alc_slave_pfxs,
"Playback Volume");
if (err < 0)
return err;
}
if (!spec->no_analog &&
!snd_hda_find_mixer_ctl(codec, "Master Playback Switch")) {
err = __snd_hda_add_vmaster(codec, "Master Playback Switch",
NULL, alc_slave_pfxs,
"Playback Switch",
true, &spec->vmaster_mute.sw_kctl);
if (err < 0)
return err;
}
if (spec->capsrc_nids || spec->adc_nids) {
kctl = snd_hda_find_mixer_ctl(codec, "Capture Source");
if (!kctl)
kctl = snd_hda_find_mixer_ctl(codec, "Input Source");
for (i = 0; kctl && i < kctl->count; i++) {
err = snd_hda_add_nid(codec, kctl, i,
get_capsrc(spec, i));
if (err < 0)
return err;
}
}
if (spec->cap_mixer && spec->adc_nids) {
const char *kname = kctl ? kctl->id.name : NULL;
for (knew = spec->cap_mixer; knew->name; knew++) {
if (kname && strcmp(knew->name, kname) == 0)
continue;
kctl = snd_hda_find_mixer_ctl(codec, knew->name);
for (i = 0; kctl && i < kctl->count; i++) {
err = snd_hda_add_nid(codec, kctl, i,
spec->adc_nids[i]);
if (err < 0)
return err;
}
}
}
for (i = 0; i < spec->num_mixers; i++) {
for (knew = spec->mixers[i]; knew->name; knew++) {
if (knew->iface != NID_MAPPING)
continue;
kctl = snd_hda_find_mixer_ctl(codec, knew->name);
if (kctl == NULL)
continue;
u = knew->subdevice;
for (j = 0; j < 4; j++, u >>= 8) {
nid = u & 0x3f;
if (nid == 0)
continue;
switch (u & 0xc0) {
case SUBDEV_SPEAKER_:
nid = spec->autocfg.speaker_pins[nid];
break;
case SUBDEV_LINE_:
nid = spec->autocfg.line_out_pins[nid];
break;
case SUBDEV_HP_:
nid = spec->autocfg.hp_pins[nid];
break;
default:
continue;
}
err = snd_hda_add_nid(codec, kctl, 0, nid);
if (err < 0)
return err;
}
u = knew->private_value;
for (j = 0; j < 4; j++, u >>= 8) {
nid = u & 0xff;
if (nid == 0)
continue;
err = snd_hda_add_nid(codec, kctl, 0, nid);
if (err < 0)
return err;
}
}
}
alc_free_kctls(codec);
return 0;
}
static int alc_build_jacks(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
if (spec->shared_mic_hp) {
int err;
int nid = spec->autocfg.inputs[1].pin;
err = snd_hda_jack_add_kctl(codec, nid, "Headphone Mic", 0);
if (err < 0)
return err;
err = snd_hda_jack_detect_enable(codec, nid, 0);
if (err < 0)
return err;
}
return snd_hda_jack_add_kctls(codec, &spec->autocfg);
}
static int alc_build_controls(struct hda_codec *codec)
{
int err = __alc_build_controls(codec);
if (err < 0)
return err;
err = alc_build_jacks(codec);
if (err < 0)
return err;
alc_apply_fixup(codec, ALC_FIXUP_ACT_BUILD);
return 0;
}
static int alc_init(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
if (spec->init_hook)
spec->init_hook(codec);
alc_fix_pll(codec);
alc_auto_init_amp(codec, spec->init_amp);
snd_hda_gen_apply_verbs(codec);
alc_init_special_input_src(codec);
alc_auto_init_std(codec);
alc_apply_fixup(codec, ALC_FIXUP_ACT_INIT);
hda_call_check_power_status(codec, 0x01);
return 0;
}
static int alc_check_power_status(struct hda_codec *codec, hda_nid_t nid)
{
struct alc_spec *spec = codec->spec;
return snd_hda_check_amp_list_power(codec, &spec->loopback, nid);
}
static int alc_playback_pcm_open(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
struct snd_pcm_substream *substream)
{
struct alc_spec *spec = codec->spec;
return snd_hda_multi_out_analog_open(codec, &spec->multiout, substream,
hinfo);
}
static int alc_playback_pcm_prepare(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
unsigned int stream_tag,
unsigned int format,
struct snd_pcm_substream *substream)
{
struct alc_spec *spec = codec->spec;
return snd_hda_multi_out_analog_prepare(codec, &spec->multiout,
stream_tag, format, substream);
}
static int alc_playback_pcm_cleanup(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
struct snd_pcm_substream *substream)
{
struct alc_spec *spec = codec->spec;
return snd_hda_multi_out_analog_cleanup(codec, &spec->multiout);
}
static int alc_dig_playback_pcm_open(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
struct snd_pcm_substream *substream)
{
struct alc_spec *spec = codec->spec;
return snd_hda_multi_out_dig_open(codec, &spec->multiout);
}
static int alc_dig_playback_pcm_prepare(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
unsigned int stream_tag,
unsigned int format,
struct snd_pcm_substream *substream)
{
struct alc_spec *spec = codec->spec;
return snd_hda_multi_out_dig_prepare(codec, &spec->multiout,
stream_tag, format, substream);
}
static int alc_dig_playback_pcm_cleanup(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
struct snd_pcm_substream *substream)
{
struct alc_spec *spec = codec->spec;
return snd_hda_multi_out_dig_cleanup(codec, &spec->multiout);
}
static int alc_dig_playback_pcm_close(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
struct snd_pcm_substream *substream)
{
struct alc_spec *spec = codec->spec;
return snd_hda_multi_out_dig_close(codec, &spec->multiout);
}
static int alc_alt_capture_pcm_prepare(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
unsigned int stream_tag,
unsigned int format,
struct snd_pcm_substream *substream)
{
struct alc_spec *spec = codec->spec;
snd_hda_codec_setup_stream(codec, spec->adc_nids[substream->number + 1],
stream_tag, 0, format);
return 0;
}
static int alc_alt_capture_pcm_cleanup(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
struct snd_pcm_substream *substream)
{
struct alc_spec *spec = codec->spec;
snd_hda_codec_cleanup_stream(codec,
spec->adc_nids[substream->number + 1]);
return 0;
}
static int dyn_adc_capture_pcm_prepare(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
unsigned int stream_tag,
unsigned int format,
struct snd_pcm_substream *substream)
{
struct alc_spec *spec = codec->spec;
spec->cur_adc = spec->adc_nids[spec->dyn_adc_idx[spec->cur_mux[0]]];
spec->cur_adc_stream_tag = stream_tag;
spec->cur_adc_format = format;
snd_hda_codec_setup_stream(codec, spec->cur_adc, stream_tag, 0, format);
return 0;
}
static int dyn_adc_capture_pcm_cleanup(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
struct snd_pcm_substream *substream)
{
struct alc_spec *spec = codec->spec;
snd_hda_codec_cleanup_stream(codec, spec->cur_adc);
spec->cur_adc = 0;
return 0;
}
static int alc_build_pcms(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
struct hda_pcm *info = spec->pcm_rec;
const struct hda_pcm_stream *p;
bool have_multi_adcs;
int i;
codec->num_pcms = 1;
codec->pcm_info = info;
if (spec->no_analog)
goto skip_analog;
snprintf(spec->stream_name_analog, sizeof(spec->stream_name_analog),
"%s Analog", codec->chip_name);
info->name = spec->stream_name_analog;
if (spec->multiout.num_dacs > 0) {
p = spec->stream_analog_playback;
if (!p)
p = &alc_pcm_analog_playback;
info->stream[SNDRV_PCM_STREAM_PLAYBACK] = *p;
info->stream[SNDRV_PCM_STREAM_PLAYBACK].nid = spec->multiout.dac_nids[0];
info->stream[SNDRV_PCM_STREAM_PLAYBACK].channels_max =
spec->multiout.max_channels;
if (spec->autocfg.line_out_type == AUTO_PIN_SPEAKER_OUT &&
spec->autocfg.line_outs == 2)
info->stream[SNDRV_PCM_STREAM_PLAYBACK].chmap =
snd_pcm_2_1_chmaps;
}
if (spec->adc_nids) {
p = spec->stream_analog_capture;
if (!p) {
if (spec->dyn_adc_switch)
p = &dyn_adc_pcm_analog_capture;
else
p = &alc_pcm_analog_capture;
}
info->stream[SNDRV_PCM_STREAM_CAPTURE] = *p;
info->stream[SNDRV_PCM_STREAM_CAPTURE].nid = spec->adc_nids[0];
}
if (spec->channel_mode) {
info->stream[SNDRV_PCM_STREAM_PLAYBACK].channels_max = 0;
for (i = 0; i < spec->num_channel_mode; i++) {
if (spec->channel_mode[i].channels > info->stream[SNDRV_PCM_STREAM_PLAYBACK].channels_max) {
info->stream[SNDRV_PCM_STREAM_PLAYBACK].channels_max = spec->channel_mode[i].channels;
}
}
}
skip_analog:
if (spec->multiout.dig_out_nid || spec->dig_in_nid) {
snprintf(spec->stream_name_digital,
sizeof(spec->stream_name_digital),
"%s Digital", codec->chip_name);
codec->num_pcms = 2;
codec->slave_dig_outs = spec->multiout.slave_dig_outs;
info = spec->pcm_rec + 1;
info->name = spec->stream_name_digital;
if (spec->dig_out_type)
info->pcm_type = spec->dig_out_type;
else
info->pcm_type = HDA_PCM_TYPE_SPDIF;
if (spec->multiout.dig_out_nid) {
p = spec->stream_digital_playback;
if (!p)
p = &alc_pcm_digital_playback;
info->stream[SNDRV_PCM_STREAM_PLAYBACK] = *p;
info->stream[SNDRV_PCM_STREAM_PLAYBACK].nid = spec->multiout.dig_out_nid;
}
if (spec->dig_in_nid) {
p = spec->stream_digital_capture;
if (!p)
p = &alc_pcm_digital_capture;
info->stream[SNDRV_PCM_STREAM_CAPTURE] = *p;
info->stream[SNDRV_PCM_STREAM_CAPTURE].nid = spec->dig_in_nid;
}
codec->spdif_status_reset = 1;
}
if (spec->no_analog)
return 0;
have_multi_adcs = (spec->num_adc_nids > 1) &&
!spec->dyn_adc_switch && !spec->auto_mic &&
(!spec->input_mux || spec->input_mux->num_items > 1);
if (spec->alt_dac_nid || have_multi_adcs) {
codec->num_pcms = 3;
info = spec->pcm_rec + 2;
info->name = spec->stream_name_analog;
if (spec->alt_dac_nid) {
p = spec->stream_analog_alt_playback;
if (!p)
p = &alc_pcm_analog_alt_playback;
info->stream[SNDRV_PCM_STREAM_PLAYBACK] = *p;
info->stream[SNDRV_PCM_STREAM_PLAYBACK].nid =
spec->alt_dac_nid;
} else {
info->stream[SNDRV_PCM_STREAM_PLAYBACK] =
alc_pcm_null_stream;
info->stream[SNDRV_PCM_STREAM_PLAYBACK].nid = 0;
}
if (have_multi_adcs) {
p = spec->stream_analog_alt_capture;
if (!p)
p = &alc_pcm_analog_alt_capture;
info->stream[SNDRV_PCM_STREAM_CAPTURE] = *p;
info->stream[SNDRV_PCM_STREAM_CAPTURE].nid =
spec->adc_nids[1];
info->stream[SNDRV_PCM_STREAM_CAPTURE].substreams =
spec->num_adc_nids - 1;
} else {
info->stream[SNDRV_PCM_STREAM_CAPTURE] =
alc_pcm_null_stream;
info->stream[SNDRV_PCM_STREAM_CAPTURE].nid = 0;
}
}
return 0;
}
static inline void alc_shutup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
if (spec && spec->shutup)
spec->shutup(codec);
snd_hda_shutup_pins(codec);
}
static void alc_free_kctls(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
if (spec->kctls.list) {
struct snd_kcontrol_new *kctl = spec->kctls.list;
int i;
for (i = 0; i < spec->kctls.used; i++)
kfree(kctl[i].name);
}
snd_array_free(&spec->kctls);
}
static void alc_free_bind_ctls(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
if (spec->bind_ctls.list) {
struct hda_bind_ctls **ctl = spec->bind_ctls.list;
int i;
for (i = 0; i < spec->bind_ctls.used; i++)
kfree(ctl[i]);
}
snd_array_free(&spec->bind_ctls);
}
static void alc_free(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
if (!spec)
return;
alc_free_kctls(codec);
alc_free_bind_ctls(codec);
snd_hda_gen_free(&spec->gen);
kfree(spec);
snd_hda_detach_beep_device(codec);
}
static void alc_power_eapd(struct hda_codec *codec)
{
alc_auto_setup_eapd(codec, false);
}
static int alc_suspend(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
alc_shutup(codec);
if (spec && spec->power_hook)
spec->power_hook(codec);
return 0;
}
static int alc_resume(struct hda_codec *codec)
{
msleep(150);
codec->patch_ops.init(codec);
snd_hda_codec_resume_amp(codec);
snd_hda_codec_resume_cache(codec);
alc_inv_dmic_sync(codec, true);
hda_call_check_power_status(codec, 0x01);
return 0;
}
static int alc_codec_rename(struct hda_codec *codec, const char *name)
{
kfree(codec->chip_name);
codec->chip_name = kstrdup(name, GFP_KERNEL);
if (!codec->chip_name) {
alc_free(codec);
return -ENOMEM;
}
return 0;
}
static int alc_codec_rename_from_preset(struct hda_codec *codec)
{
const struct alc_codec_rename_table *p;
for (p = rename_tbl; p->vendor_id; p++) {
if (p->vendor_id != codec->vendor_id)
continue;
if ((alc_get_coef0(codec) & p->coef_mask) == p->coef_bits)
return alc_codec_rename(codec, p->name);
}
return 0;
}
static int add_control(struct alc_spec *spec, int type, const char *name,
int cidx, unsigned long val)
{
struct snd_kcontrol_new *knew;
knew = alc_kcontrol_new(spec, name, &alc_control_templates[type]);
if (!knew)
return -ENOMEM;
knew->index = cidx;
if (get_amp_nid_(val))
knew->subdevice = HDA_SUBDEV_AMP_FLAG;
knew->private_value = val;
return 0;
}
static int add_control_with_pfx(struct alc_spec *spec, int type,
const char *pfx, const char *dir,
const char *sfx, int cidx, unsigned long val)
{
char name[32];
snprintf(name, sizeof(name), "%s %s %s", pfx, dir, sfx);
return add_control(spec, type, name, cidx, val);
}
static const char *alc_get_line_out_pfx(struct alc_spec *spec, int ch,
bool can_be_master, int *index)
{
struct auto_pin_cfg *cfg = &spec->autocfg;
*index = 0;
if (cfg->line_outs == 1 && !spec->multi_ios &&
!cfg->hp_outs && !cfg->speaker_outs && can_be_master)
return "Master";
switch (cfg->line_out_type) {
case AUTO_PIN_SPEAKER_OUT:
if (cfg->line_outs == 1)
return "Speaker";
if (cfg->line_outs == 2)
return ch ? "Bass Speaker" : "Speaker";
break;
case AUTO_PIN_HP_OUT:
if (ch && spec->multi_ios)
break;
*index = ch;
return "Headphone";
default:
if (cfg->line_outs == 1 && !spec->multi_ios)
return "PCM";
break;
}
if (ch >= ARRAY_SIZE(channel_name)) {
snd_BUG();
return "PCM";
}
return channel_name[ch];
}
static void add_loopback_list(struct alc_spec *spec, hda_nid_t mix, int idx)
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
static int new_analog_input(struct alc_spec *spec, hda_nid_t pin,
const char *ctlname, int ctlidx,
int idx, hda_nid_t mix_nid)
{
int err;
err = __add_pb_vol_ctrl(spec, ALC_CTL_WIDGET_VOL, ctlname, ctlidx,
HDA_COMPOSE_AMP_VAL(mix_nid, 3, idx, HDA_INPUT));
if (err < 0)
return err;
err = __add_pb_sw_ctrl(spec, ALC_CTL_WIDGET_MUTE, ctlname, ctlidx,
HDA_COMPOSE_AMP_VAL(mix_nid, 3, idx, HDA_INPUT));
if (err < 0)
return err;
add_loopback_list(spec, mix_nid, idx);
return 0;
}
static int alc_is_input_pin(struct hda_codec *codec, hda_nid_t nid)
{
unsigned int pincap = snd_hda_query_pin_caps(codec, nid);
return (pincap & AC_PINCAP_IN) != 0;
}
static int alc_auto_fill_adc_caps(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
hda_nid_t nid;
hda_nid_t *adc_nids = spec->private_adc_nids;
hda_nid_t *cap_nids = spec->private_capsrc_nids;
int max_nums = ARRAY_SIZE(spec->private_adc_nids);
int i, nums = 0;
nid = codec->start_nid;
for (i = 0; i < codec->num_nodes; i++, nid++) {
hda_nid_t src;
unsigned int caps = get_wcaps(codec, nid);
int type = get_wcaps_type(caps);
if (type != AC_WID_AUD_IN || (caps & AC_WCAP_DIGITAL))
continue;
adc_nids[nums] = nid;
cap_nids[nums] = nid;
src = nid;
for (;;) {
int n;
type = get_wcaps_type(get_wcaps(codec, src));
if (type == AC_WID_PIN)
break;
if (type == AC_WID_AUD_SEL) {
cap_nids[nums] = src;
break;
}
n = snd_hda_get_num_conns(codec, src);
if (n > 1) {
cap_nids[nums] = src;
break;
} else if (n != 1)
break;
if (snd_hda_get_connections(codec, src, &src, 1) != 1)
break;
}
if (++nums >= max_nums)
break;
}
spec->adc_nids = spec->private_adc_nids;
spec->capsrc_nids = spec->private_capsrc_nids;
spec->num_adc_nids = nums;
return nums;
}
static int alc_auto_create_input_ctls(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
const struct auto_pin_cfg *cfg = &spec->autocfg;
hda_nid_t mixer = spec->mixer_nid;
struct hda_input_mux *imux = &spec->private_imux[0];
int num_adcs;
int i, c, err, idx, type_idx = 0;
const char *prev_label = NULL;
num_adcs = alc_auto_fill_adc_caps(codec);
if (num_adcs < 0)
return 0;
for (i = 0; i < cfg->num_inputs; i++) {
hda_nid_t pin;
const char *label;
pin = cfg->inputs[i].pin;
if (!alc_is_input_pin(codec, pin))
continue;
label = hda_get_autocfg_input_label(codec, cfg, i);
if (spec->shared_mic_hp && !strcmp(label, "Misc"))
label = "Headphone Mic";
if (prev_label && !strcmp(label, prev_label))
type_idx++;
else
type_idx = 0;
prev_label = label;
if (mixer) {
idx = get_connection_index(codec, mixer, pin);
if (idx >= 0) {
err = new_analog_input(spec, pin,
label, type_idx,
idx, mixer);
if (err < 0)
return err;
}
}
for (c = 0; c < num_adcs; c++) {
hda_nid_t cap = get_capsrc(spec, c);
idx = get_connection_index(codec, cap, pin);
if (idx >= 0) {
spec->imux_pins[imux->num_items] = pin;
snd_hda_add_imux_item(imux, label, idx, NULL);
break;
}
}
}
spec->num_mux_defs = 1;
spec->input_mux = imux;
return 0;
}
static int alc_auto_create_shared_input(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
struct auto_pin_cfg *cfg = &spec->autocfg;
unsigned int defcfg;
hda_nid_t nid;
if (cfg->num_inputs != 1)
return 0;
defcfg = snd_hda_codec_get_pincfg(codec, cfg->inputs[0].pin);
if (snd_hda_get_input_pin_attr(defcfg) != INPUT_PIN_ATTR_INT)
return 0;
if (cfg->hp_outs == 1 && cfg->line_out_type == AUTO_PIN_SPEAKER_OUT)
nid = cfg->hp_pins[0];
else if (cfg->line_outs == 1 && cfg->line_out_type == AUTO_PIN_HP_OUT)
nid = cfg->line_out_pins[0];
else
return 0;
if (!(snd_hda_query_pin_caps(codec, nid) & AC_PINCAP_IN))
return 0;
cfg->inputs[1].pin = nid;
cfg->inputs[1].type = AUTO_PIN_MIC;
cfg->num_inputs = 2;
spec->shared_mic_hp = 1;
snd_printdd("realtek: Enable shared I/O jack on NID 0x%x\n", nid);
return 0;
}
static void alc_set_pin_output(struct hda_codec *codec, hda_nid_t nid,
unsigned int pin_type)
{
snd_hda_set_pin_ctl(codec, nid, pin_type);
if (nid_has_mute(codec, nid, HDA_OUTPUT))
snd_hda_codec_write(codec, nid, 0, AC_VERB_SET_AMP_GAIN_MUTE,
AMP_OUT_UNMUTE);
}
static int get_pin_type(int line_out_type)
{
if (line_out_type == AUTO_PIN_HP_OUT)
return PIN_HP;
else
return PIN_OUT;
}
static void alc_auto_init_analog_input(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
struct auto_pin_cfg *cfg = &spec->autocfg;
int i;
for (i = 0; i < cfg->num_inputs; i++) {
hda_nid_t nid = cfg->inputs[i].pin;
if (alc_is_input_pin(codec, nid)) {
alc_set_input_pin(codec, nid, cfg->inputs[i].type);
if (get_wcaps(codec, nid) & AC_WCAP_OUT_AMP)
snd_hda_codec_write(codec, nid, 0,
AC_VERB_SET_AMP_GAIN_MUTE,
AMP_OUT_MUTE);
}
}
if (spec->mixer_nid) {
int nums = snd_hda_get_num_conns(codec, spec->mixer_nid);
for (i = 0; i < nums; i++)
snd_hda_codec_write(codec, spec->mixer_nid, 0,
AC_VERB_SET_AMP_GAIN_MUTE,
AMP_IN_MUTE(i));
}
}
static hda_nid_t alc_auto_mix_to_dac(struct hda_codec *codec, hda_nid_t nid)
{
hda_nid_t list[5];
int i, num;
if (get_wcaps_type(get_wcaps(codec, nid)) == AC_WID_AUD_OUT)
return nid;
num = snd_hda_get_connections(codec, nid, list, ARRAY_SIZE(list));
for (i = 0; i < num; i++) {
if (get_wcaps_type(get_wcaps(codec, list[i])) == AC_WID_AUD_OUT)
return list[i];
}
return 0;
}
static hda_nid_t alc_go_down_to_selector(struct hda_codec *codec, hda_nid_t pin)
{
hda_nid_t srcs[5];
int num = snd_hda_get_connections(codec, pin, srcs,
ARRAY_SIZE(srcs));
if (num != 1 ||
get_wcaps_type(get_wcaps(codec, srcs[0])) != AC_WID_AUD_SEL)
return pin;
return srcs[0];
}
static hda_nid_t alc_auto_dac_to_mix(struct hda_codec *codec, hda_nid_t pin,
hda_nid_t dac)
{
hda_nid_t mix[5];
int i, num;
pin = alc_go_down_to_selector(codec, pin);
num = snd_hda_get_connections(codec, pin, mix, ARRAY_SIZE(mix));
for (i = 0; i < num; i++) {
if (alc_auto_mix_to_dac(codec, mix[i]) == dac)
return mix[i];
}
return 0;
}
static int alc_auto_select_dac(struct hda_codec *codec, hda_nid_t pin,
hda_nid_t dac)
{
hda_nid_t mix[5];
int i, num;
pin = alc_go_down_to_selector(codec, pin);
num = snd_hda_get_connections(codec, pin, mix, ARRAY_SIZE(mix));
if (num < 2)
return 0;
for (i = 0; i < num; i++) {
if (alc_auto_mix_to_dac(codec, mix[i]) == dac) {
snd_hda_codec_update_cache(codec, pin, 0,
AC_VERB_SET_CONNECT_SEL, i);
return 0;
}
}
return 0;
}
static bool alc_is_dac_already_used(struct hda_codec *codec, hda_nid_t nid)
{
struct alc_spec *spec = codec->spec;
int i;
if (found_in_nid_list(nid, spec->multiout.dac_nids,
ARRAY_SIZE(spec->private_dac_nids)) ||
found_in_nid_list(nid, spec->multiout.hp_out_nid,
ARRAY_SIZE(spec->multiout.hp_out_nid)) ||
found_in_nid_list(nid, spec->multiout.extra_out_nid,
ARRAY_SIZE(spec->multiout.extra_out_nid)))
return true;
for (i = 0; i < spec->multi_ios; i++) {
if (spec->multi_io[i].dac == nid)
return true;
}
return false;
}
static hda_nid_t alc_auto_look_for_dac(struct hda_codec *codec, hda_nid_t pin)
{
hda_nid_t srcs[5];
int i, num;
pin = alc_go_down_to_selector(codec, pin);
num = snd_hda_get_connections(codec, pin, srcs, ARRAY_SIZE(srcs));
for (i = 0; i < num; i++) {
hda_nid_t nid = alc_auto_mix_to_dac(codec, srcs[i]);
if (!nid)
continue;
if (!alc_is_dac_already_used(codec, nid))
return nid;
}
return 0;
}
static bool alc_auto_is_dac_reachable(struct hda_codec *codec,
hda_nid_t pin, hda_nid_t dac)
{
hda_nid_t srcs[5];
int i, num;
if (!pin || !dac)
return false;
pin = alc_go_down_to_selector(codec, pin);
num = snd_hda_get_connections(codec, pin, srcs, ARRAY_SIZE(srcs));
for (i = 0; i < num; i++) {
hda_nid_t nid = alc_auto_mix_to_dac(codec, srcs[i]);
if (nid == dac)
return true;
}
return false;
}
static hda_nid_t get_dac_if_single(struct hda_codec *codec, hda_nid_t pin)
{
struct alc_spec *spec = codec->spec;
hda_nid_t sel = alc_go_down_to_selector(codec, pin);
hda_nid_t nid, nid_found, srcs[5];
int i, num = snd_hda_get_connections(codec, sel, srcs,
ARRAY_SIZE(srcs));
if (num == 1)
return alc_auto_look_for_dac(codec, pin);
nid_found = 0;
for (i = 0; i < num; i++) {
if (srcs[i] == spec->mixer_nid)
continue;
nid = alc_auto_mix_to_dac(codec, srcs[i]);
if (nid && !alc_is_dac_already_used(codec, nid)) {
if (nid_found)
return 0;
nid_found = nid;
}
}
return nid_found;
}
static inline unsigned int get_ctl_pos(unsigned int data)
{
hda_nid_t nid = get_amp_nid_(data);
unsigned int dir;
if (snd_BUG_ON(nid >= MAX_VOL_NIDS))
return 0;
dir = get_amp_direction_(data);
return (nid << 1) | dir;
}
static void clear_vol_marks(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
memset(spec->vol_ctls, 0, sizeof(spec->vol_ctls));
memset(spec->sw_ctls, 0, sizeof(spec->sw_ctls));
}
static int eval_shared_vol_badness(struct hda_codec *codec, hda_nid_t pin,
hda_nid_t dac)
{
struct alc_spec *spec = codec->spec;
hda_nid_t nid;
unsigned int val;
int badness = 0;
nid = alc_look_for_out_vol_nid(codec, pin, dac);
if (nid) {
val = HDA_COMPOSE_AMP_VAL(nid, 3, 0, HDA_OUTPUT);
if (is_ctl_used(spec->vol_ctls, nid))
badness += BAD_SHARED_VOL;
else
mark_ctl_usage(spec->vol_ctls, val);
} else
badness += BAD_SHARED_VOL;
nid = alc_look_for_out_mute_nid(codec, pin, dac);
if (nid) {
unsigned int wid_type = get_wcaps_type(get_wcaps(codec, nid));
if (wid_type == AC_WID_PIN || wid_type == AC_WID_AUD_OUT)
val = HDA_COMPOSE_AMP_VAL(nid, 3, 0, HDA_OUTPUT);
else
val = HDA_COMPOSE_AMP_VAL(nid, 3, 0, HDA_INPUT);
if (is_ctl_used(spec->sw_ctls, val))
badness += BAD_SHARED_VOL;
else
mark_ctl_usage(spec->sw_ctls, val);
} else
badness += BAD_SHARED_VOL;
return badness;
}
static int alc_auto_fill_dacs(struct hda_codec *codec, int num_outs,
const hda_nid_t *pins, hda_nid_t *dacs,
const struct badness_table *bad)
{
struct alc_spec *spec = codec->spec;
struct auto_pin_cfg *cfg = &spec->autocfg;
int i, j;
int badness = 0;
hda_nid_t dac;
if (!num_outs)
return 0;
for (i = 0; i < num_outs; i++) {
hda_nid_t pin = pins[i];
if (!dacs[i])
dacs[i] = alc_auto_look_for_dac(codec, pin);
if (!dacs[i] && !i) {
for (j = 1; j < num_outs; j++) {
if (alc_auto_is_dac_reachable(codec, pin, dacs[j])) {
dacs[0] = dacs[j];
dacs[j] = 0;
break;
}
}
}
dac = dacs[i];
if (!dac) {
if (alc_auto_is_dac_reachable(codec, pin, dacs[0]))
dac = dacs[0];
else if (cfg->line_outs > i &&
alc_auto_is_dac_reachable(codec, pin,
spec->private_dac_nids[i]))
dac = spec->private_dac_nids[i];
if (dac) {
if (!i)
badness += bad->shared_primary;
else if (i == 1)
badness += bad->shared_surr;
else
badness += bad->shared_clfe;
} else if (alc_auto_is_dac_reachable(codec, pin,
spec->private_dac_nids[0])) {
dac = spec->private_dac_nids[0];
badness += bad->shared_surr_main;
} else if (!i)
badness += bad->no_primary_dac;
else
badness += bad->no_dac;
}
if (dac)
badness += eval_shared_vol_badness(codec, pin, dac);
}
return badness;
}
static bool alc_map_singles(struct hda_codec *codec, int outs,
const hda_nid_t *pins, hda_nid_t *dacs)
{
int i;
bool found = false;
for (i = 0; i < outs; i++) {
if (dacs[i])
continue;
dacs[i] = get_dac_if_single(codec, pins[i]);
if (dacs[i])
found = true;
}
return found;
}
static int fill_and_eval_dacs(struct hda_codec *codec,
bool fill_hardwired,
bool fill_mio_first)
{
struct alc_spec *spec = codec->spec;
struct auto_pin_cfg *cfg = &spec->autocfg;
int i, err, badness;
spec->multiout.num_dacs = cfg->line_outs;
spec->multiout.dac_nids = spec->private_dac_nids;
memset(spec->private_dac_nids, 0, sizeof(spec->private_dac_nids));
memset(spec->multiout.hp_out_nid, 0, sizeof(spec->multiout.hp_out_nid));
memset(spec->multiout.extra_out_nid, 0, sizeof(spec->multiout.extra_out_nid));
spec->multi_ios = 0;
clear_vol_marks(codec);
badness = 0;
if (fill_hardwired) {
bool mapped;
do {
mapped = alc_map_singles(codec, cfg->line_outs,
cfg->line_out_pins,
spec->private_dac_nids);
mapped |= alc_map_singles(codec, cfg->hp_outs,
cfg->hp_pins,
spec->multiout.hp_out_nid);
mapped |= alc_map_singles(codec, cfg->speaker_outs,
cfg->speaker_pins,
spec->multiout.extra_out_nid);
if (fill_mio_first && cfg->line_outs == 1 &&
cfg->line_out_type != AUTO_PIN_SPEAKER_OUT) {
err = alc_auto_fill_multi_ios(codec, cfg->line_out_pins[0], true, 0);
if (!err)
mapped = true;
}
} while (mapped);
}
badness += alc_auto_fill_dacs(codec, cfg->line_outs, cfg->line_out_pins,
spec->private_dac_nids,
&main_out_badness);
spec->multiout.num_dacs = 0;
for (i = 0; i < cfg->line_outs; i++) {
if (spec->private_dac_nids[i])
spec->multiout.num_dacs++;
else {
memmove(spec->private_dac_nids + i,
spec->private_dac_nids + i + 1,
sizeof(hda_nid_t) * (cfg->line_outs - i - 1));
spec->private_dac_nids[cfg->line_outs - 1] = 0;
}
}
if (fill_mio_first &&
cfg->line_outs == 1 && cfg->line_out_type != AUTO_PIN_SPEAKER_OUT) {
err = alc_auto_fill_multi_ios(codec, cfg->line_out_pins[0], false, 0);
if (err < 0)
return err;
}
if (cfg->line_out_type != AUTO_PIN_HP_OUT) {
err = alc_auto_fill_dacs(codec, cfg->hp_outs, cfg->hp_pins,
spec->multiout.hp_out_nid,
&extra_out_badness);
if (err < 0)
return err;
badness += err;
}
if (cfg->line_out_type != AUTO_PIN_SPEAKER_OUT) {
err = alc_auto_fill_dacs(codec, cfg->speaker_outs,
cfg->speaker_pins,
spec->multiout.extra_out_nid,
&extra_out_badness);
if (err < 0)
return err;
badness += err;
}
if (cfg->line_outs == 1 && cfg->line_out_type != AUTO_PIN_SPEAKER_OUT) {
err = alc_auto_fill_multi_ios(codec, cfg->line_out_pins[0], false, 0);
if (err < 0)
return err;
badness += err;
}
if (cfg->hp_outs && cfg->line_out_type == AUTO_PIN_SPEAKER_OUT) {
int offset = 0;
if (cfg->line_outs >= 3)
offset = 1;
err = alc_auto_fill_multi_ios(codec, cfg->hp_pins[0], false,
offset);
if (err < 0)
return err;
badness += err;
}
if (spec->multi_ios == 2) {
for (i = 0; i < 2; i++)
spec->private_dac_nids[spec->multiout.num_dacs++] =
spec->multi_io[i].dac;
spec->ext_channel_count = 2;
} else if (spec->multi_ios) {
spec->multi_ios = 0;
badness += BAD_MULTI_IO;
}
return badness;
}
static void debug_show_configs(struct alc_spec *spec, struct auto_pin_cfg *cfg)
{
debug_badness("multi_outs = %x/%x/%x/%x : %x/%x/%x/%x\n",
cfg->line_out_pins[0], cfg->line_out_pins[1],
cfg->line_out_pins[2], cfg->line_out_pins[2],
spec->multiout.dac_nids[0],
spec->multiout.dac_nids[1],
spec->multiout.dac_nids[2],
spec->multiout.dac_nids[3]);
if (spec->multi_ios > 0)
debug_badness("multi_ios(%d) = %x/%x : %x/%x\n",
spec->multi_ios,
spec->multi_io[0].pin, spec->multi_io[1].pin,
spec->multi_io[0].dac, spec->multi_io[1].dac);
debug_badness("hp_outs = %x/%x/%x/%x : %x/%x/%x/%x\n",
cfg->hp_pins[0], cfg->hp_pins[1],
cfg->hp_pins[2], cfg->hp_pins[2],
spec->multiout.hp_out_nid[0],
spec->multiout.hp_out_nid[1],
spec->multiout.hp_out_nid[2],
spec->multiout.hp_out_nid[3]);
debug_badness("spk_outs = %x/%x/%x/%x : %x/%x/%x/%x\n",
cfg->speaker_pins[0], cfg->speaker_pins[1],
cfg->speaker_pins[2], cfg->speaker_pins[3],
spec->multiout.extra_out_nid[0],
spec->multiout.extra_out_nid[1],
spec->multiout.extra_out_nid[2],
spec->multiout.extra_out_nid[3]);
}
static int alc_auto_fill_dac_nids(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
struct auto_pin_cfg *cfg = &spec->autocfg;
struct auto_pin_cfg *best_cfg;
int best_badness = INT_MAX;
int badness;
bool fill_hardwired = true, fill_mio_first = true;
bool best_wired = true, best_mio = true;
bool hp_spk_swapped = false;
best_cfg = kmalloc(sizeof(*best_cfg), GFP_KERNEL);
if (!best_cfg)
return -ENOMEM;
*best_cfg = *cfg;
for (;;) {
badness = fill_and_eval_dacs(codec, fill_hardwired,
fill_mio_first);
if (badness < 0) {
kfree(best_cfg);
return badness;
}
debug_badness("==> lo_type=%d, wired=%d, mio=%d, badness=0x%x\n",
cfg->line_out_type, fill_hardwired, fill_mio_first,
badness);
debug_show_configs(spec, cfg);
if (badness < best_badness) {
best_badness = badness;
*best_cfg = *cfg;
best_wired = fill_hardwired;
best_mio = fill_mio_first;
}
if (!badness)
break;
fill_mio_first = !fill_mio_first;
if (!fill_mio_first)
continue;
fill_hardwired = !fill_hardwired;
if (!fill_hardwired)
continue;
if (hp_spk_swapped)
break;
hp_spk_swapped = true;
if (cfg->speaker_outs > 0 &&
cfg->line_out_type == AUTO_PIN_HP_OUT) {
cfg->hp_outs = cfg->line_outs;
memcpy(cfg->hp_pins, cfg->line_out_pins,
sizeof(cfg->hp_pins));
cfg->line_outs = cfg->speaker_outs;
memcpy(cfg->line_out_pins, cfg->speaker_pins,
sizeof(cfg->speaker_pins));
cfg->speaker_outs = 0;
memset(cfg->speaker_pins, 0, sizeof(cfg->speaker_pins));
cfg->line_out_type = AUTO_PIN_SPEAKER_OUT;
fill_hardwired = true;
continue;
}
if (cfg->hp_outs > 0 &&
cfg->line_out_type == AUTO_PIN_SPEAKER_OUT) {
cfg->speaker_outs = cfg->line_outs;
memcpy(cfg->speaker_pins, cfg->line_out_pins,
sizeof(cfg->speaker_pins));
cfg->line_outs = cfg->hp_outs;
memcpy(cfg->line_out_pins, cfg->hp_pins,
sizeof(cfg->hp_pins));
cfg->hp_outs = 0;
memset(cfg->hp_pins, 0, sizeof(cfg->hp_pins));
cfg->line_out_type = AUTO_PIN_HP_OUT;
fill_hardwired = true;
continue;
}
break;
}
if (badness) {
*cfg = *best_cfg;
fill_and_eval_dacs(codec, best_wired, best_mio);
}
debug_badness("==> Best config: lo_type=%d, wired=%d, mio=%d\n",
cfg->line_out_type, best_wired, best_mio);
debug_show_configs(spec, cfg);
if (cfg->line_out_pins[0])
spec->vmaster_nid =
alc_look_for_out_vol_nid(codec, cfg->line_out_pins[0],
spec->multiout.dac_nids[0]);
clear_vol_marks(codec);
kfree(best_cfg);
return 0;
}
static int alc_auto_add_vol_ctl(struct hda_codec *codec,
const char *pfx, int cidx,
hda_nid_t nid, unsigned int chs)
{
struct alc_spec *spec = codec->spec;
unsigned int val;
if (!nid)
return 0;
val = HDA_COMPOSE_AMP_VAL(nid, chs, 0, HDA_OUTPUT);
if (is_ctl_used(spec->vol_ctls, val) && chs != 2)
return 0;
mark_ctl_usage(spec->vol_ctls, val);
return __add_pb_vol_ctrl(codec->spec, ALC_CTL_WIDGET_VOL, pfx, cidx,
val);
}
static int alc_auto_add_stereo_vol(struct hda_codec *codec,
const char *pfx, int cidx,
hda_nid_t nid)
{
int chs = 1;
if (get_wcaps(codec, nid) & AC_WCAP_STEREO)
chs = 3;
return alc_auto_add_vol_ctl(codec, pfx, cidx, nid, chs);
}
static int alc_auto_add_sw_ctl(struct hda_codec *codec,
const char *pfx, int cidx,
hda_nid_t nid, unsigned int chs)
{
struct alc_spec *spec = codec->spec;
int wid_type;
int type;
unsigned long val;
if (!nid)
return 0;
wid_type = get_wcaps_type(get_wcaps(codec, nid));
if (wid_type == AC_WID_PIN || wid_type == AC_WID_AUD_OUT) {
type = ALC_CTL_WIDGET_MUTE;
val = HDA_COMPOSE_AMP_VAL(nid, chs, 0, HDA_OUTPUT);
} else if (snd_hda_get_num_conns(codec, nid) == 1) {
type = ALC_CTL_WIDGET_MUTE;
val = HDA_COMPOSE_AMP_VAL(nid, chs, 0, HDA_INPUT);
} else {
type = ALC_CTL_BIND_MUTE;
val = HDA_COMPOSE_AMP_VAL(nid, chs, 2, HDA_INPUT);
}
if (is_ctl_used(spec->sw_ctls, val) && chs != 2)
return 0;
mark_ctl_usage(spec->sw_ctls, val);
return __add_pb_sw_ctrl(codec->spec, type, pfx, cidx, val);
}
static int alc_auto_add_stereo_sw(struct hda_codec *codec, const char *pfx,
int cidx, hda_nid_t nid)
{
int chs = 1;
if (get_wcaps(codec, nid) & AC_WCAP_STEREO)
chs = 3;
return alc_auto_add_sw_ctl(codec, pfx, cidx, nid, chs);
}
static hda_nid_t alc_look_for_out_mute_nid(struct hda_codec *codec,
hda_nid_t pin, hda_nid_t dac)
{
hda_nid_t mix = alc_auto_dac_to_mix(codec, pin, dac);
if (nid_has_mute(codec, pin, HDA_OUTPUT))
return pin;
else if (mix && nid_has_mute(codec, mix, HDA_INPUT))
return mix;
else if (nid_has_mute(codec, dac, HDA_OUTPUT))
return dac;
return 0;
}
static hda_nid_t alc_look_for_out_vol_nid(struct hda_codec *codec,
hda_nid_t pin, hda_nid_t dac)
{
hda_nid_t mix = alc_auto_dac_to_mix(codec, pin, dac);
if (nid_has_volume(codec, dac, HDA_OUTPUT))
return dac;
else if (nid_has_volume(codec, mix, HDA_OUTPUT))
return mix;
else if (nid_has_volume(codec, pin, HDA_OUTPUT))
return pin;
return 0;
}
static int alc_auto_create_multi_out_ctls(struct hda_codec *codec,
const struct auto_pin_cfg *cfg)
{
struct alc_spec *spec = codec->spec;
int i, err, noutputs;
noutputs = cfg->line_outs;
if (spec->multi_ios > 0 && cfg->line_outs < 3)
noutputs += spec->multi_ios;
for (i = 0; i < noutputs; i++) {
const char *name;
int index;
hda_nid_t dac, pin;
hda_nid_t sw, vol;
dac = spec->multiout.dac_nids[i];
if (!dac)
continue;
if (i >= cfg->line_outs) {
pin = spec->multi_io[i - 1].pin;
index = 0;
name = channel_name[i];
} else {
pin = cfg->line_out_pins[i];
name = alc_get_line_out_pfx(spec, i, true, &index);
}
sw = alc_look_for_out_mute_nid(codec, pin, dac);
vol = alc_look_for_out_vol_nid(codec, pin, dac);
if (!name || !strcmp(name, "CLFE")) {
err = alc_auto_add_vol_ctl(codec, "Center", 0, vol, 1);
if (err < 0)
return err;
err = alc_auto_add_vol_ctl(codec, "LFE", 0, vol, 2);
if (err < 0)
return err;
err = alc_auto_add_sw_ctl(codec, "Center", 0, sw, 1);
if (err < 0)
return err;
err = alc_auto_add_sw_ctl(codec, "LFE", 0, sw, 2);
if (err < 0)
return err;
} else {
err = alc_auto_add_stereo_vol(codec, name, index, vol);
if (err < 0)
return err;
err = alc_auto_add_stereo_sw(codec, name, index, sw);
if (err < 0)
return err;
}
}
return 0;
}
static int alc_auto_create_extra_out(struct hda_codec *codec, hda_nid_t pin,
hda_nid_t dac, const char *pfx,
int cidx)
{
struct alc_spec *spec = codec->spec;
hda_nid_t sw, vol;
int err;
if (!dac) {
unsigned int val;
if (!(get_wcaps(codec, pin) & AC_WCAP_OUT_AMP))
return 0;
val = HDA_COMPOSE_AMP_VAL(pin, 3, 0, HDA_OUTPUT);
if (is_ctl_used(spec->sw_ctls, val))
return 0;
mark_ctl_usage(spec->sw_ctls, val);
return __add_pb_sw_ctrl(spec, ALC_CTL_WIDGET_MUTE, pfx, cidx, val);
}
sw = alc_look_for_out_mute_nid(codec, pin, dac);
vol = alc_look_for_out_vol_nid(codec, pin, dac);
err = alc_auto_add_stereo_vol(codec, pfx, cidx, vol);
if (err < 0)
return err;
err = alc_auto_add_stereo_sw(codec, pfx, cidx, sw);
if (err < 0)
return err;
return 0;
}
static struct hda_bind_ctls *new_bind_ctl(struct hda_codec *codec,
unsigned int nums,
struct hda_ctl_ops *ops)
{
struct alc_spec *spec = codec->spec;
struct hda_bind_ctls **ctlp, *ctl;
ctlp = snd_array_new(&spec->bind_ctls);
if (!ctlp)
return NULL;
ctl = kzalloc(sizeof(*ctl) + sizeof(long) * (nums + 1), GFP_KERNEL);
*ctlp = ctl;
if (ctl)
ctl->ops = ops;
return ctl;
}
static int alc_auto_create_extra_outs(struct hda_codec *codec, int num_pins,
const hda_nid_t *pins,
const hda_nid_t *dacs,
const char *pfx)
{
struct alc_spec *spec = codec->spec;
struct hda_bind_ctls *ctl;
char name[32];
int i, n, err;
if (!num_pins || !pins[0])
return 0;
if (num_pins == 1) {
hda_nid_t dac = *dacs;
if (!dac)
dac = spec->multiout.dac_nids[0];
return alc_auto_create_extra_out(codec, *pins, dac, pfx, 0);
}
for (i = 0; i < num_pins; i++) {
hda_nid_t dac;
if (dacs[num_pins - 1])
dac = dacs[i];
else
dac = 0;
if (num_pins == 2 && i == 1 && !strcmp(pfx, "Speaker")) {
err = alc_auto_create_extra_out(codec, pins[i], dac,
"Bass Speaker", 0);
} else if (num_pins >= 3) {
snprintf(name, sizeof(name), "%s %s",
pfx, channel_name[i]);
err = alc_auto_create_extra_out(codec, pins[i], dac,
name, 0);
} else {
err = alc_auto_create_extra_out(codec, pins[i], dac,
pfx, i);
}
if (err < 0)
return err;
}
if (dacs[num_pins - 1])
return 0;
ctl = new_bind_ctl(codec, num_pins, &snd_hda_bind_vol);
if (!ctl)
return -ENOMEM;
n = 0;
for (i = 0; i < num_pins; i++) {
hda_nid_t vol;
if (!pins[i] || !dacs[i])
continue;
vol = alc_look_for_out_vol_nid(codec, pins[i], dacs[i]);
if (vol)
ctl->values[n++] =
HDA_COMPOSE_AMP_VAL(vol, 3, 0, HDA_OUTPUT);
}
if (n) {
snprintf(name, sizeof(name), "%s Playback Volume", pfx);
err = add_control(spec, ALC_CTL_BIND_VOL, name, 0, (long)ctl);
if (err < 0)
return err;
}
return 0;
}
static int alc_auto_create_hp_out(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
return alc_auto_create_extra_outs(codec, spec->autocfg.hp_outs,
spec->autocfg.hp_pins,
spec->multiout.hp_out_nid,
"Headphone");
}
static int alc_auto_create_speaker_out(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
return alc_auto_create_extra_outs(codec, spec->autocfg.speaker_outs,
spec->autocfg.speaker_pins,
spec->multiout.extra_out_nid,
"Speaker");
}
static void alc_auto_set_output_and_unmute(struct hda_codec *codec,
hda_nid_t pin, int pin_type,
hda_nid_t dac)
{
int i, num;
hda_nid_t nid, mix = 0;
hda_nid_t srcs[HDA_MAX_CONNECTIONS];
alc_set_pin_output(codec, pin, pin_type);
nid = alc_go_down_to_selector(codec, pin);
num = snd_hda_get_connections(codec, nid, srcs, ARRAY_SIZE(srcs));
for (i = 0; i < num; i++) {
if (alc_auto_mix_to_dac(codec, srcs[i]) != dac)
continue;
mix = srcs[i];
break;
}
if (!mix)
return;
if (num > 1)
snd_hda_codec_write(codec, nid, 0, AC_VERB_SET_CONNECT_SEL, i);
if (nid_has_mute(codec, mix, HDA_INPUT)) {
snd_hda_codec_write(codec, mix, 0, AC_VERB_SET_AMP_GAIN_MUTE,
AMP_IN_UNMUTE(0));
snd_hda_codec_write(codec, mix, 0, AC_VERB_SET_AMP_GAIN_MUTE,
AMP_IN_UNMUTE(1));
}
nid = alc_look_for_out_vol_nid(codec, pin, dac);
if (nid)
snd_hda_codec_write(codec, nid, 0, AC_VERB_SET_AMP_GAIN_MUTE,
AMP_OUT_ZERO);
nid = alc_look_for_out_mute_nid(codec, pin, dac);
if (nid == mix && nid_has_mute(codec, dac, HDA_OUTPUT))
snd_hda_codec_write(codec, dac, 0, AC_VERB_SET_AMP_GAIN_MUTE,
AMP_OUT_ZERO);
}
static void alc_auto_init_multi_out(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
int pin_type = get_pin_type(spec->autocfg.line_out_type);
int i;
for (i = 0; i <= HDA_SIDE; i++) {
hda_nid_t nid = spec->autocfg.line_out_pins[i];
if (nid)
alc_auto_set_output_and_unmute(codec, nid, pin_type,
spec->multiout.dac_nids[i]);
}
}
static void alc_auto_init_extra_out(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
int i;
hda_nid_t pin, dac;
for (i = 0; i < spec->autocfg.hp_outs; i++) {
if (spec->autocfg.line_out_type == AUTO_PIN_HP_OUT)
break;
pin = spec->autocfg.hp_pins[i];
if (!pin)
break;
dac = spec->multiout.hp_out_nid[i];
if (!dac) {
if (i > 0 && spec->multiout.hp_out_nid[0])
dac = spec->multiout.hp_out_nid[0];
else
dac = spec->multiout.dac_nids[0];
}
alc_auto_set_output_and_unmute(codec, pin, PIN_HP, dac);
}
for (i = 0; i < spec->autocfg.speaker_outs; i++) {
if (spec->autocfg.line_out_type == AUTO_PIN_SPEAKER_OUT)
break;
pin = spec->autocfg.speaker_pins[i];
if (!pin)
break;
dac = spec->multiout.extra_out_nid[i];
if (!dac) {
if (i > 0 && spec->multiout.extra_out_nid[0])
dac = spec->multiout.extra_out_nid[0];
else
dac = spec->multiout.dac_nids[0];
}
alc_auto_set_output_and_unmute(codec, pin, PIN_OUT, dac);
}
}
static bool can_be_multiio_pin(struct hda_codec *codec,
unsigned int location, hda_nid_t nid)
{
unsigned int defcfg, caps;
defcfg = snd_hda_codec_get_pincfg(codec, nid);
if (get_defcfg_connect(defcfg) != AC_JACK_PORT_COMPLEX)
return false;
if (location && get_defcfg_location(defcfg) != location)
return false;
caps = snd_hda_query_pin_caps(codec, nid);
if (!(caps & AC_PINCAP_OUT))
return false;
return true;
}
static int alc_auto_fill_multi_ios(struct hda_codec *codec,
hda_nid_t reference_pin,
bool hardwired, int offset)
{
struct alc_spec *spec = codec->spec;
struct auto_pin_cfg *cfg = &spec->autocfg;
int type, i, j, dacs, num_pins, old_pins;
unsigned int defcfg = snd_hda_codec_get_pincfg(codec, reference_pin);
unsigned int location = get_defcfg_location(defcfg);
int badness = 0;
old_pins = spec->multi_ios;
if (old_pins >= 2)
goto end_fill;
num_pins = 0;
for (type = AUTO_PIN_LINE_IN; type >= AUTO_PIN_MIC; type--) {
for (i = 0; i < cfg->num_inputs; i++) {
if (cfg->inputs[i].type != type)
continue;
if (can_be_multiio_pin(codec, location,
cfg->inputs[i].pin))
num_pins++;
}
}
if (num_pins < 2)
goto end_fill;
dacs = spec->multiout.num_dacs;
for (type = AUTO_PIN_LINE_IN; type >= AUTO_PIN_MIC; type--) {
for (i = 0; i < cfg->num_inputs; i++) {
hda_nid_t nid = cfg->inputs[i].pin;
hda_nid_t dac = 0;
if (cfg->inputs[i].type != type)
continue;
if (!can_be_multiio_pin(codec, location, nid))
continue;
for (j = 0; j < spec->multi_ios; j++) {
if (nid == spec->multi_io[j].pin)
break;
}
if (j < spec->multi_ios)
continue;
if (offset && offset + spec->multi_ios < dacs) {
dac = spec->private_dac_nids[offset + spec->multi_ios];
if (!alc_auto_is_dac_reachable(codec, nid, dac))
dac = 0;
}
if (hardwired)
dac = get_dac_if_single(codec, nid);
else if (!dac)
dac = alc_auto_look_for_dac(codec, nid);
if (!dac) {
badness++;
continue;
}
spec->multi_io[spec->multi_ios].pin = nid;
spec->multi_io[spec->multi_ios].dac = dac;
spec->multi_ios++;
if (spec->multi_ios >= 2)
break;
}
}
end_fill:
if (badness)
badness = BAD_MULTI_IO;
if (old_pins == spec->multi_ios) {
if (hardwired)
return 1;
else
return badness;
}
if (!hardwired && spec->multi_ios < 2) {
spec->multi_ios = old_pins;
return badness;
}
return 0;
}
static int alc_auto_ch_mode_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct alc_spec *spec = codec->spec;
uinfo->type = SNDRV_CTL_ELEM_TYPE_ENUMERATED;
uinfo->count = 1;
uinfo->value.enumerated.items = spec->multi_ios + 1;
if (uinfo->value.enumerated.item > spec->multi_ios)
uinfo->value.enumerated.item = spec->multi_ios;
sprintf(uinfo->value.enumerated.name, "%dch",
(uinfo->value.enumerated.item + 1) * 2);
return 0;
}
static int alc_auto_ch_mode_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct alc_spec *spec = codec->spec;
ucontrol->value.enumerated.item[0] = (spec->ext_channel_count - 1) / 2;
return 0;
}
static int alc_set_multi_io(struct hda_codec *codec, int idx, bool output)
{
struct alc_spec *spec = codec->spec;
hda_nid_t nid = spec->multi_io[idx].pin;
if (!spec->multi_io[idx].ctl_in)
spec->multi_io[idx].ctl_in =
snd_hda_codec_read(codec, nid, 0,
AC_VERB_GET_PIN_WIDGET_CONTROL, 0);
if (output) {
snd_hda_set_pin_ctl_cache(codec, nid, PIN_OUT);
if (get_wcaps(codec, nid) & AC_WCAP_OUT_AMP)
snd_hda_codec_amp_stereo(codec, nid, HDA_OUTPUT, 0,
HDA_AMP_MUTE, 0);
alc_auto_select_dac(codec, nid, spec->multi_io[idx].dac);
} else {
if (get_wcaps(codec, nid) & AC_WCAP_OUT_AMP)
snd_hda_codec_amp_stereo(codec, nid, HDA_OUTPUT, 0,
HDA_AMP_MUTE, HDA_AMP_MUTE);
snd_hda_set_pin_ctl_cache(codec, nid,
spec->multi_io[idx].ctl_in);
}
return 0;
}
static int alc_auto_ch_mode_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct alc_spec *spec = codec->spec;
int i, ch;
ch = ucontrol->value.enumerated.item[0];
if (ch < 0 || ch > spec->multi_ios)
return -EINVAL;
if (ch == (spec->ext_channel_count - 1) / 2)
return 0;
spec->ext_channel_count = (ch + 1) * 2;
for (i = 0; i < spec->multi_ios; i++)
alc_set_multi_io(codec, i, i < ch);
spec->multiout.max_channels = max(spec->ext_channel_count,
spec->const_channel_count);
if (spec->need_dac_fix)
spec->multiout.num_dacs = spec->multiout.max_channels / 2;
return 1;
}
static int alc_auto_add_multi_channel_mode(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
if (spec->multi_ios > 0) {
if (!alc_kcontrol_new(spec, "Channel Mode",
&alc_auto_channel_mode_enum))
return -ENOMEM;
}
return 0;
}
static void alc_remove_invalid_adc_nids(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
const struct hda_input_mux *imux;
hda_nid_t adc_nids[ARRAY_SIZE(spec->private_adc_nids)];
hda_nid_t capsrc_nids[ARRAY_SIZE(spec->private_adc_nids)];
int i, n, nums;
imux = spec->input_mux;
if (!imux)
return;
if (spec->dyn_adc_switch)
return;
again:
nums = 0;
for (n = 0; n < spec->num_adc_nids; n++) {
hda_nid_t cap = spec->private_capsrc_nids[n];
int num_conns = snd_hda_get_num_conns(codec, cap);
for (i = 0; i < imux->num_items; i++) {
hda_nid_t pin = spec->imux_pins[i];
if (pin) {
if (get_connection_index(codec, cap, pin) < 0)
break;
} else if (num_conns <= imux->items[i].index)
break;
}
if (i >= imux->num_items) {
adc_nids[nums] = spec->private_adc_nids[n];
capsrc_nids[nums++] = cap;
}
}
if (!nums) {
if (!alc_check_dyn_adc_switch(codec)) {
if (spec->shared_mic_hp) {
spec->shared_mic_hp = 0;
spec->private_imux[0].num_items = 1;
goto again;
}
printk(KERN_WARNING "hda_codec: %s: no valid ADC found;"
" using fallback 0x%x\n",
codec->chip_name, spec->private_adc_nids[0]);
spec->num_adc_nids = 1;
spec->auto_mic = 0;
return;
}
} else if (nums != spec->num_adc_nids) {
memcpy(spec->private_adc_nids, adc_nids,
nums * sizeof(hda_nid_t));
memcpy(spec->private_capsrc_nids, capsrc_nids,
nums * sizeof(hda_nid_t));
spec->num_adc_nids = nums;
}
if (spec->auto_mic)
alc_auto_mic_check_imux(codec);
else if (spec->input_mux->num_items == 1 || spec->shared_mic_hp)
spec->num_adc_nids = 1;
}
static void alc_auto_init_adc(struct hda_codec *codec, int adc_idx)
{
struct alc_spec *spec = codec->spec;
hda_nid_t nid;
nid = spec->adc_nids[adc_idx];
if (nid_has_mute(codec, nid, HDA_INPUT)) {
snd_hda_codec_write(codec, nid, 0,
AC_VERB_SET_AMP_GAIN_MUTE,
AMP_IN_MUTE(0));
return;
}
if (!spec->capsrc_nids)
return;
nid = spec->capsrc_nids[adc_idx];
if (nid_has_mute(codec, nid, HDA_OUTPUT))
snd_hda_codec_write(codec, nid, 0,
AC_VERB_SET_AMP_GAIN_MUTE,
AMP_OUT_MUTE);
}
static void alc_auto_init_input_src(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
int c, nums;
for (c = 0; c < spec->num_adc_nids; c++)
alc_auto_init_adc(codec, c);
if (spec->dyn_adc_switch)
nums = 1;
else
nums = spec->num_adc_nids;
for (c = 0; c < nums; c++)
alc_mux_select(codec, c, spec->cur_mux[c], true);
}
static int alc_auto_add_mic_boost(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
struct auto_pin_cfg *cfg = &spec->autocfg;
int i, err;
int type_idx = 0;
hda_nid_t nid;
const char *prev_label = NULL;
for (i = 0; i < cfg->num_inputs; i++) {
if (cfg->inputs[i].type > AUTO_PIN_MIC)
break;
nid = cfg->inputs[i].pin;
if (get_wcaps(codec, nid) & AC_WCAP_IN_AMP) {
const char *label;
char boost_label[32];
label = hda_get_autocfg_input_label(codec, cfg, i);
if (spec->shared_mic_hp && !strcmp(label, "Misc"))
label = "Headphone Mic";
if (prev_label && !strcmp(label, prev_label))
type_idx++;
else
type_idx = 0;
prev_label = label;
snprintf(boost_label, sizeof(boost_label),
"%s Boost Volume", label);
err = add_control(spec, ALC_CTL_WIDGET_VOL,
boost_label, type_idx,
HDA_COMPOSE_AMP_VAL(nid, 3, 0, HDA_INPUT));
if (err < 0)
return err;
}
}
return 0;
}
static void select_or_unmute_capsrc(struct hda_codec *codec, hda_nid_t cap,
int idx)
{
if (get_wcaps_type(get_wcaps(codec, cap)) == AC_WID_AUD_MIX) {
snd_hda_codec_amp_stereo(codec, cap, HDA_INPUT, idx,
HDA_AMP_MUTE, 0);
} else if (snd_hda_get_num_conns(codec, cap) > 1) {
snd_hda_codec_write_cache(codec, cap, 0,
AC_VERB_SET_CONNECT_SEL, idx);
}
}
static int init_capsrc_for_pin(struct hda_codec *codec, hda_nid_t pin)
{
struct alc_spec *spec = codec->spec;
int i;
if (!pin)
return 0;
for (i = 0; i < spec->num_adc_nids; i++) {
hda_nid_t cap = get_capsrc(spec, i);
int idx;
idx = get_connection_index(codec, cap, pin);
if (idx < 0)
continue;
select_or_unmute_capsrc(codec, cap, idx);
return i;
}
return -1;
}
static void alc_init_special_input_src(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
int i;
for (i = 0; i < spec->autocfg.num_inputs; i++)
init_capsrc_for_pin(codec, spec->autocfg.inputs[i].pin);
}
static void set_capture_mixer(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
static const struct snd_kcontrol_new *caps[2][3] = {
{ alc_capture_mixer_nosrc1,
alc_capture_mixer_nosrc2,
alc_capture_mixer_nosrc3 },
{ alc_capture_mixer1,
alc_capture_mixer2,
alc_capture_mixer3 },
};
if (!nid_has_volume(codec, spec->adc_nids[0], HDA_INPUT)) {
if (!spec->capsrc_nids)
return;
if (!nid_has_volume(codec, spec->capsrc_nids[0], HDA_OUTPUT))
return;
spec->vol_in_capsrc = 1;
}
if (spec->num_adc_nids > 0) {
int mux = 0;
int num_adcs = 0;
if (spec->input_mux && spec->input_mux->num_items > 1)
mux = 1;
if (spec->auto_mic) {
num_adcs = 1;
mux = 0;
} else if (spec->dyn_adc_switch)
num_adcs = 1;
if (!num_adcs) {
if (spec->num_adc_nids > 3)
spec->num_adc_nids = 3;
else if (!spec->num_adc_nids)
return;
num_adcs = spec->num_adc_nids;
}
spec->cap_mixer = caps[mux][num_adcs - 1];
}
}
static void alc_auto_init_std(struct hda_codec *codec)
{
alc_auto_init_multi_out(codec);
alc_auto_init_extra_out(codec);
alc_auto_init_analog_input(codec);
alc_auto_init_input_src(codec);
alc_auto_init_digital(codec);
alc_inithook(codec);
}
static inline int has_cdefine_beep(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
const struct snd_pci_quirk *q;
q = snd_pci_quirk_lookup(codec->bus->pci, beep_white_list);
if (q)
return q->value;
return spec->cdefine.enable_pcbeep;
}
static int alc_parse_auto_config(struct hda_codec *codec,
const hda_nid_t *ignore_nids,
const hda_nid_t *ssid_nids)
{
struct alc_spec *spec = codec->spec;
struct auto_pin_cfg *cfg = &spec->autocfg;
int err;
err = snd_hda_parse_pin_defcfg(codec, cfg, ignore_nids,
spec->parse_flags);
if (err < 0)
return err;
if (!cfg->line_outs) {
if (cfg->dig_outs || cfg->dig_in_pin) {
spec->multiout.max_channels = 2;
spec->no_analog = 1;
goto dig_only;
}
return 0;
}
if (!spec->no_primary_hp &&
cfg->line_out_type == AUTO_PIN_SPEAKER_OUT &&
cfg->line_outs <= cfg->hp_outs) {
cfg->speaker_outs = cfg->line_outs;
memcpy(cfg->speaker_pins, cfg->line_out_pins,
sizeof(cfg->speaker_pins));
cfg->line_outs = cfg->hp_outs;
memcpy(cfg->line_out_pins, cfg->hp_pins, sizeof(cfg->hp_pins));
cfg->hp_outs = 0;
memset(cfg->hp_pins, 0, sizeof(cfg->hp_pins));
cfg->line_out_type = AUTO_PIN_HP_OUT;
}
err = alc_auto_fill_dac_nids(codec);
if (err < 0)
return err;
err = alc_auto_add_multi_channel_mode(codec);
if (err < 0)
return err;
err = alc_auto_create_multi_out_ctls(codec, cfg);
if (err < 0)
return err;
err = alc_auto_create_hp_out(codec);
if (err < 0)
return err;
err = alc_auto_create_speaker_out(codec);
if (err < 0)
return err;
err = alc_auto_create_shared_input(codec);
if (err < 0)
return err;
err = alc_auto_create_input_ctls(codec);
if (err < 0)
return err;
if (cfg->line_out_type == AUTO_PIN_SPEAKER_OUT)
spec->const_channel_count = cfg->line_outs * 2;
else
spec->const_channel_count = cfg->speaker_outs * 2;
if (spec->multi_ios > 0)
spec->multiout.max_channels = max(spec->ext_channel_count,
spec->const_channel_count);
else
spec->multiout.max_channels = spec->multiout.num_dacs * 2;
dig_only:
alc_auto_parse_digital(codec);
if (!spec->no_analog)
alc_remove_invalid_adc_nids(codec);
if (ssid_nids)
alc_ssid_check(codec, ssid_nids);
if (!spec->no_analog) {
err = alc_auto_check_switches(codec);
if (err < 0)
return err;
err = alc_auto_add_mic_boost(codec);
if (err < 0)
return err;
}
if (spec->kctls.list)
add_mixer(spec, spec->kctls.list);
if (!spec->no_analog && !spec->cap_mixer)
set_capture_mixer(codec);
return 1;
}
static int alc_alloc_spec(struct hda_codec *codec, hda_nid_t mixer_nid)
{
struct alc_spec *spec = kzalloc(sizeof(*spec), GFP_KERNEL);
int err;
if (!spec)
return -ENOMEM;
codec->spec = spec;
codec->single_adc_amp = 1;
spec->mixer_nid = mixer_nid;
snd_hda_gen_init(&spec->gen);
snd_array_init(&spec->kctls, sizeof(struct snd_kcontrol_new), 32);
snd_array_init(&spec->bind_ctls, sizeof(struct hda_bind_ctls *), 8);
err = alc_codec_rename_from_preset(codec);
if (err < 0) {
kfree(spec);
return err;
}
return 0;
}
static int alc880_parse_auto_config(struct hda_codec *codec)
{
static const hda_nid_t alc880_ignore[] = { 0x1d, 0 };
static const hda_nid_t alc880_ssids[] = { 0x15, 0x1b, 0x14, 0 };
return alc_parse_auto_config(codec, alc880_ignore, alc880_ssids);
}
static void alc880_fixup_vol_knob(struct hda_codec *codec,
const struct alc_fixup *fix, int action)
{
if (action == ALC_FIXUP_ACT_PROBE)
snd_hda_jack_detect_enable_callback(codec, 0x21, ALC_DCVOL_EVENT, alc_update_knob_master);
}
static int patch_alc880(struct hda_codec *codec)
{
struct alc_spec *spec;
int err;
err = alc_alloc_spec(codec, 0x0b);
if (err < 0)
return err;
spec = codec->spec;
spec->need_dac_fix = 1;
alc_pick_fixup(codec, alc880_fixup_models, alc880_fixup_tbl,
alc880_fixups);
alc_apply_fixup(codec, ALC_FIXUP_ACT_PRE_PROBE);
err = alc880_parse_auto_config(codec);
if (err < 0)
goto error;
if (!spec->no_analog) {
err = snd_hda_attach_beep_device(codec, 0x1);
if (err < 0)
goto error;
set_beep_amp(spec, 0x0b, 0x05, HDA_INPUT);
}
codec->patch_ops = alc_patch_ops;
codec->patch_ops.unsol_event = alc880_unsol_event;
alc_apply_fixup(codec, ALC_FIXUP_ACT_PROBE);
return 0;
error:
alc_free(codec);
return err;
}
static int alc260_parse_auto_config(struct hda_codec *codec)
{
static const hda_nid_t alc260_ignore[] = { 0x17, 0 };
static const hda_nid_t alc260_ssids[] = { 0x10, 0x15, 0x0f, 0 };
return alc_parse_auto_config(codec, alc260_ignore, alc260_ssids);
}
static void alc260_gpio1_automute(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
snd_hda_codec_write(codec, 0x01, 0, AC_VERB_SET_GPIO_DATA,
spec->hp_jack_present);
}
static void alc260_fixup_gpio1_toggle(struct hda_codec *codec,
const struct alc_fixup *fix, int action)
{
struct alc_spec *spec = codec->spec;
if (action == ALC_FIXUP_ACT_PROBE) {
spec->automute_hook = alc260_gpio1_automute;
spec->detect_hp = 1;
spec->automute_speaker = 1;
spec->autocfg.hp_pins[0] = 0x0f;
snd_hda_jack_detect_enable_callback(codec, 0x0f, ALC_HP_EVENT,
alc_hp_automute);
snd_hda_gen_add_verbs(&spec->gen, alc_gpio1_init_verbs);
}
}
static void alc260_fixup_kn1(struct hda_codec *codec,
const struct alc_fixup *fix, int action)
{
struct alc_spec *spec = codec->spec;
static const struct alc_pincfg pincfgs[] = {
{ 0x0f, 0x02214000 },
{ 0x12, 0x90a60160 },
{ 0x13, 0x02a19000 },
{ 0x18, 0x01446000 },
{ 0x10, 0x411111f0 },
{ 0x11, 0x411111f0 },
{ 0x14, 0x411111f0 },
{ 0x15, 0x411111f0 },
{ 0x16, 0x411111f0 },
{ 0x17, 0x411111f0 },
{ 0x19, 0x411111f0 },
{ }
};
switch (action) {
case ALC_FIXUP_ACT_PRE_PROBE:
alc_apply_pincfgs(codec, pincfgs);
break;
case ALC_FIXUP_ACT_PROBE:
spec->init_amp = ALC_INIT_NONE;
break;
}
}
static int patch_alc260(struct hda_codec *codec)
{
struct alc_spec *spec;
int err;
err = alc_alloc_spec(codec, 0x07);
if (err < 0)
return err;
spec = codec->spec;
alc_pick_fixup(codec, NULL, alc260_fixup_tbl, alc260_fixups);
alc_apply_fixup(codec, ALC_FIXUP_ACT_PRE_PROBE);
err = alc260_parse_auto_config(codec);
if (err < 0)
goto error;
if (!spec->no_analog) {
err = snd_hda_attach_beep_device(codec, 0x1);
if (err < 0)
goto error;
set_beep_amp(spec, 0x07, 0x05, HDA_INPUT);
}
codec->patch_ops = alc_patch_ops;
spec->shutup = alc_eapd_shutup;
alc_apply_fixup(codec, ALC_FIXUP_ACT_PROBE);
return 0;
error:
alc_free(codec);
return err;
}
static void alc889_fixup_coef(struct hda_codec *codec,
const struct alc_fixup *fix, int action)
{
if (action != ALC_FIXUP_ACT_INIT)
return;
alc889_coef_init(codec);
}
static void alc882_gpio_mute(struct hda_codec *codec, int pin, int muted)
{
unsigned int gpiostate, gpiomask, gpiodir;
gpiostate = snd_hda_codec_read(codec, codec->afg, 0,
AC_VERB_GET_GPIO_DATA, 0);
if (!muted)
gpiostate |= (1 << pin);
else
gpiostate &= ~(1 << pin);
gpiomask = snd_hda_codec_read(codec, codec->afg, 0,
AC_VERB_GET_GPIO_MASK, 0);
gpiomask |= (1 << pin);
gpiodir = snd_hda_codec_read(codec, codec->afg, 0,
AC_VERB_GET_GPIO_DIRECTION, 0);
gpiodir |= (1 << pin);
snd_hda_codec_write(codec, codec->afg, 0,
AC_VERB_SET_GPIO_MASK, gpiomask);
snd_hda_codec_write(codec, codec->afg, 0,
AC_VERB_SET_GPIO_DIRECTION, gpiodir);
msleep(1);
snd_hda_codec_write(codec, codec->afg, 0,
AC_VERB_SET_GPIO_DATA, gpiostate);
}
static void alc885_fixup_macpro_gpio(struct hda_codec *codec,
const struct alc_fixup *fix, int action)
{
if (action != ALC_FIXUP_ACT_INIT)
return;
alc882_gpio_mute(codec, 0, 0);
alc882_gpio_mute(codec, 1, 0);
}
static void alc889_fixup_dac_route(struct hda_codec *codec,
const struct alc_fixup *fix, int action)
{
if (action == ALC_FIXUP_ACT_PRE_PROBE) {
hda_nid_t conn1[2] = { 0x0c, 0x0d };
hda_nid_t conn2[2] = { 0x0e, 0x0f };
snd_hda_override_conn_list(codec, 0x14, 2, conn1);
snd_hda_override_conn_list(codec, 0x15, 2, conn1);
snd_hda_override_conn_list(codec, 0x18, 2, conn2);
snd_hda_override_conn_list(codec, 0x1a, 2, conn2);
} else if (action == ALC_FIXUP_ACT_PROBE) {
hda_nid_t conn[5] = { 0x0c, 0x0d, 0x0e, 0x0f, 0x26 };
snd_hda_override_conn_list(codec, 0x14, 5, conn);
snd_hda_override_conn_list(codec, 0x15, 5, conn);
snd_hda_override_conn_list(codec, 0x18, 5, conn);
snd_hda_override_conn_list(codec, 0x1a, 5, conn);
}
}
static void alc889_fixup_mbp_vref(struct hda_codec *codec,
const struct alc_fixup *fix, int action)
{
struct alc_spec *spec = codec->spec;
static hda_nid_t nids[2] = { 0x14, 0x15 };
int i;
if (action != ALC_FIXUP_ACT_INIT)
return;
for (i = 0; i < ARRAY_SIZE(nids); i++) {
unsigned int val = snd_hda_codec_get_pincfg(codec, nids[i]);
if (get_defcfg_device(val) != AC_JACK_HP_OUT)
continue;
val = snd_hda_codec_read(codec, nids[i], 0,
AC_VERB_GET_PIN_WIDGET_CONTROL, 0);
val |= AC_PINCTL_VREF_80;
snd_hda_set_pin_ctl(codec, nids[i], val);
spec->keep_vref_in_automute = 1;
break;
}
}
static void alc889_fixup_imac91_vref(struct hda_codec *codec,
const struct alc_fixup *fix, int action)
{
struct alc_spec *spec = codec->spec;
static hda_nid_t nids[2] = { 0x18, 0x1a };
int i;
if (action != ALC_FIXUP_ACT_INIT)
return;
for (i = 0; i < ARRAY_SIZE(nids); i++) {
unsigned int val;
val = snd_hda_codec_read(codec, nids[i], 0,
AC_VERB_GET_PIN_WIDGET_CONTROL, 0);
val |= AC_PINCTL_VREF_50;
snd_hda_set_pin_ctl(codec, nids[i], val);
}
spec->keep_vref_in_automute = 1;
}
static void alc882_fixup_no_primary_hp(struct hda_codec *codec,
const struct alc_fixup *fix, int action)
{
struct alc_spec *spec = codec->spec;
if (action == ALC_FIXUP_ACT_PRE_PROBE)
spec->no_primary_hp = 1;
}
static int alc882_parse_auto_config(struct hda_codec *codec)
{
static const hda_nid_t alc882_ignore[] = { 0x1d, 0 };
static const hda_nid_t alc882_ssids[] = { 0x15, 0x1b, 0x14, 0 };
return alc_parse_auto_config(codec, alc882_ignore, alc882_ssids);
}
static int patch_alc882(struct hda_codec *codec)
{
struct alc_spec *spec;
int err;
err = alc_alloc_spec(codec, 0x0b);
if (err < 0)
return err;
spec = codec->spec;
switch (codec->vendor_id) {
case 0x10ec0882:
case 0x10ec0885:
break;
default:
alc_fix_pll_init(codec, 0x20, 0x0a, 10);
break;
}
alc_pick_fixup(codec, alc882_fixup_models, alc882_fixup_tbl,
alc882_fixups);
alc_apply_fixup(codec, ALC_FIXUP_ACT_PRE_PROBE);
alc_auto_parse_customize_define(codec);
err = alc882_parse_auto_config(codec);
if (err < 0)
goto error;
if (!spec->no_analog && has_cdefine_beep(codec)) {
err = snd_hda_attach_beep_device(codec, 0x1);
if (err < 0)
goto error;
set_beep_amp(spec, 0x0b, 0x05, HDA_INPUT);
}
codec->patch_ops = alc_patch_ops;
alc_apply_fixup(codec, ALC_FIXUP_ACT_PROBE);
return 0;
error:
alc_free(codec);
return err;
}
static int alc262_parse_auto_config(struct hda_codec *codec)
{
static const hda_nid_t alc262_ignore[] = { 0x1d, 0 };
static const hda_nid_t alc262_ssids[] = { 0x15, 0x1b, 0x14, 0 };
return alc_parse_auto_config(codec, alc262_ignore, alc262_ssids);
}
static int patch_alc262(struct hda_codec *codec)
{
struct alc_spec *spec;
int err;
err = alc_alloc_spec(codec, 0x0b);
if (err < 0)
return err;
spec = codec->spec;
#if 0
{
int tmp;
snd_hda_codec_write(codec, 0x1a, 0, AC_VERB_SET_COEF_INDEX, 7);
tmp = snd_hda_codec_read(codec, 0x20, 0, AC_VERB_GET_PROC_COEF, 0);
snd_hda_codec_write(codec, 0x1a, 0, AC_VERB_SET_COEF_INDEX, 7);
snd_hda_codec_write(codec, 0x1a, 0, AC_VERB_SET_PROC_COEF, tmp | 0x80);
}
#endif
alc_fix_pll_init(codec, 0x20, 0x0a, 10);
alc_pick_fixup(codec, alc262_fixup_models, alc262_fixup_tbl,
alc262_fixups);
alc_apply_fixup(codec, ALC_FIXUP_ACT_PRE_PROBE);
alc_auto_parse_customize_define(codec);
err = alc262_parse_auto_config(codec);
if (err < 0)
goto error;
if (!spec->no_analog && has_cdefine_beep(codec)) {
err = snd_hda_attach_beep_device(codec, 0x1);
if (err < 0)
goto error;
set_beep_amp(spec, 0x0b, 0x05, HDA_INPUT);
}
codec->patch_ops = alc_patch_ops;
spec->shutup = alc_eapd_shutup;
alc_apply_fixup(codec, ALC_FIXUP_ACT_PROBE);
return 0;
error:
alc_free(codec);
return err;
}
static int alc268_parse_auto_config(struct hda_codec *codec)
{
static const hda_nid_t alc268_ssids[] = { 0x15, 0x1b, 0x14, 0 };
struct alc_spec *spec = codec->spec;
int err = alc_parse_auto_config(codec, NULL, alc268_ssids);
if (err > 0) {
if (!spec->no_analog && spec->autocfg.speaker_pins[0] != 0x1d) {
add_mixer(spec, alc268_beep_mixer);
snd_hda_gen_add_verbs(&spec->gen, alc268_beep_init_verbs);
}
}
return err;
}
static int patch_alc268(struct hda_codec *codec)
{
struct alc_spec *spec;
int i, has_beep, err;
err = alc_alloc_spec(codec, 0);
if (err < 0)
return err;
spec = codec->spec;
alc_pick_fixup(codec, alc268_fixup_models, alc268_fixup_tbl, alc268_fixups);
alc_apply_fixup(codec, ALC_FIXUP_ACT_PRE_PROBE);
err = alc268_parse_auto_config(codec);
if (err < 0)
goto error;
has_beep = 0;
for (i = 0; i < spec->num_mixers; i++) {
if (spec->mixers[i] == alc268_beep_mixer) {
has_beep = 1;
break;
}
}
if (has_beep) {
err = snd_hda_attach_beep_device(codec, 0x1);
if (err < 0)
goto error;
if (!query_amp_caps(codec, 0x1d, HDA_INPUT))
snd_hda_override_amp_caps(codec, 0x1d, HDA_INPUT,
(0x0c << AC_AMPCAP_OFFSET_SHIFT) |
(0x0c << AC_AMPCAP_NUM_STEPS_SHIFT) |
(0x07 << AC_AMPCAP_STEP_SIZE_SHIFT) |
(0 << AC_AMPCAP_MUTE_SHIFT));
}
codec->patch_ops = alc_patch_ops;
spec->shutup = alc_eapd_shutup;
alc_apply_fixup(codec, ALC_FIXUP_ACT_PROBE);
return 0;
error:
alc_free(codec);
return err;
}
static int alc269_parse_auto_config(struct hda_codec *codec)
{
static const hda_nid_t alc269_ignore[] = { 0x1d, 0 };
static const hda_nid_t alc269_ssids[] = { 0, 0x1b, 0x14, 0x21 };
static const hda_nid_t alc269va_ssids[] = { 0x15, 0x1b, 0x14, 0 };
struct alc_spec *spec = codec->spec;
const hda_nid_t *ssids;
switch (spec->codec_variant) {
case ALC269_TYPE_ALC269VA:
case ALC269_TYPE_ALC269VC:
case ALC269_TYPE_ALC280:
case ALC269_TYPE_ALC284:
ssids = alc269va_ssids;
break;
case ALC269_TYPE_ALC269VB:
case ALC269_TYPE_ALC269VD:
case ALC269_TYPE_ALC282:
ssids = alc269_ssids;
break;
default:
ssids = alc269_ssids;
break;
}
return alc_parse_auto_config(codec, alc269_ignore, ssids);
}
static void alc269vb_toggle_power_output(struct hda_codec *codec, int power_up)
{
int val = alc_read_coef_idx(codec, 0x04);
if (power_up)
val |= 1 << 11;
else
val &= ~(1 << 11);
alc_write_coef_idx(codec, 0x04, val);
}
static void alc269_shutup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
if (spec->codec_variant != ALC269_TYPE_ALC269VB)
return;
if (spec->codec_variant == ALC269_TYPE_ALC269VB)
alc269vb_toggle_power_output(codec, 0);
if (spec->codec_variant == ALC269_TYPE_ALC269VB &&
(alc_get_coef0(codec) & 0x00ff) == 0x018) {
msleep(150);
}
}
static int alc269_resume(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
if (spec->codec_variant == ALC269_TYPE_ALC269VB)
alc269vb_toggle_power_output(codec, 0);
if (spec->codec_variant == ALC269_TYPE_ALC269VB &&
(alc_get_coef0(codec) & 0x00ff) == 0x018) {
msleep(150);
}
codec->patch_ops.init(codec);
if (spec->codec_variant == ALC269_TYPE_ALC269VB)
alc269vb_toggle_power_output(codec, 1);
if (spec->codec_variant == ALC269_TYPE_ALC269VB &&
(alc_get_coef0(codec) & 0x00ff) == 0x017) {
msleep(200);
}
snd_hda_codec_resume_amp(codec);
snd_hda_codec_resume_cache(codec);
hda_call_check_power_status(codec, 0x01);
return 0;
}
static void alc269_fixup_pincfg_no_hp_to_lineout(struct hda_codec *codec,
const struct alc_fixup *fix, int action)
{
struct alc_spec *spec = codec->spec;
if (action == ALC_FIXUP_ACT_PRE_PROBE)
spec->parse_flags = HDA_PINCFG_NO_HP_FIXUP;
}
static void alc269_fixup_hweq(struct hda_codec *codec,
const struct alc_fixup *fix, int action)
{
int coef;
if (action != ALC_FIXUP_ACT_INIT)
return;
coef = alc_read_coef_idx(codec, 0x1e);
alc_write_coef_idx(codec, 0x1e, coef | 0x80);
}
static void alc271_fixup_dmic(struct hda_codec *codec,
const struct alc_fixup *fix, int action)
{
static const struct hda_verb verbs[] = {
{0x20, AC_VERB_SET_COEF_INDEX, 0x0d},
{0x20, AC_VERB_SET_PROC_COEF, 0x4000},
{}
};
unsigned int cfg;
if (strcmp(codec->chip_name, "ALC271X"))
return;
cfg = snd_hda_codec_get_pincfg(codec, 0x12);
if (get_defcfg_connect(cfg) == AC_JACK_PORT_FIXED)
snd_hda_sequence_write(codec, verbs);
}
static void alc269_fixup_pcm_44k(struct hda_codec *codec,
const struct alc_fixup *fix, int action)
{
struct alc_spec *spec = codec->spec;
if (action != ALC_FIXUP_ACT_PROBE)
return;
spec->stream_analog_playback = &alc269_44k_pcm_analog_playback;
spec->stream_analog_capture = &alc269_44k_pcm_analog_capture;
}
static void alc269_fixup_stereo_dmic(struct hda_codec *codec,
const struct alc_fixup *fix, int action)
{
int coef;
if (action != ALC_FIXUP_ACT_INIT)
return;
coef = alc_read_coef_idx(codec, 0x07);
alc_write_coef_idx(codec, 0x07, coef | 0x80);
}
static void alc269_quanta_automute(struct hda_codec *codec)
{
update_outputs(codec);
snd_hda_codec_write(codec, 0x20, 0,
AC_VERB_SET_COEF_INDEX, 0x0c);
snd_hda_codec_write(codec, 0x20, 0,
AC_VERB_SET_PROC_COEF, 0x680);
snd_hda_codec_write(codec, 0x20, 0,
AC_VERB_SET_COEF_INDEX, 0x0c);
snd_hda_codec_write(codec, 0x20, 0,
AC_VERB_SET_PROC_COEF, 0x480);
}
static void alc269_fixup_quanta_mute(struct hda_codec *codec,
const struct alc_fixup *fix, int action)
{
struct alc_spec *spec = codec->spec;
if (action != ALC_FIXUP_ACT_PROBE)
return;
spec->automute_hook = alc269_quanta_automute;
}
static void alc269_fixup_mic1_mute_hook(void *private_data, int enabled)
{
struct hda_codec *codec = private_data;
unsigned int pinval = AC_PINCTL_IN_EN + (enabled ?
AC_PINCTL_VREF_HIZ : AC_PINCTL_VREF_80);
snd_hda_set_pin_ctl_cache(codec, 0x18, pinval);
}
static void alc269_fixup_mic1_mute(struct hda_codec *codec,
const struct alc_fixup *fix, int action)
{
struct alc_spec *spec = codec->spec;
switch (action) {
case ALC_FIXUP_ACT_BUILD:
spec->vmaster_mute.hook = alc269_fixup_mic1_mute_hook;
snd_hda_add_vmaster_hook(codec, &spec->vmaster_mute, true);
case ALC_FIXUP_ACT_INIT:
snd_hda_sync_vmaster_hook(&spec->vmaster_mute);
break;
}
}
static void alc269_fixup_mic2_mute_hook(void *private_data, int enabled)
{
struct hda_codec *codec = private_data;
unsigned int pinval = enabled ? 0x20 : 0x24;
snd_hda_set_pin_ctl_cache(codec, 0x19, pinval);
}
static void alc269_fixup_mic2_mute(struct hda_codec *codec,
const struct alc_fixup *fix, int action)
{
struct alc_spec *spec = codec->spec;
switch (action) {
case ALC_FIXUP_ACT_BUILD:
spec->vmaster_mute.hook = alc269_fixup_mic2_mute_hook;
snd_hda_add_vmaster_hook(codec, &spec->vmaster_mute, true);
case ALC_FIXUP_ACT_INIT:
snd_hda_sync_vmaster_hook(&spec->vmaster_mute);
break;
}
}
static void alc271_hp_gate_mic_jack(struct hda_codec *codec,
const struct alc_fixup *fix,
int action)
{
struct alc_spec *spec = codec->spec;
if (action == ALC_FIXUP_ACT_PROBE)
snd_hda_jack_set_gating_jack(codec, spec->ext_mic_pin,
spec->autocfg.hp_pins[0]);
}
static void alc269_fill_coef(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
int val;
if (spec->codec_variant != ALC269_TYPE_ALC269VB)
return;
if ((alc_get_coef0(codec) & 0x00ff) < 0x015) {
alc_write_coef_idx(codec, 0xf, 0x960b);
alc_write_coef_idx(codec, 0xe, 0x8817);
}
if ((alc_get_coef0(codec) & 0x00ff) == 0x016) {
alc_write_coef_idx(codec, 0xf, 0x960b);
alc_write_coef_idx(codec, 0xe, 0x8814);
}
if ((alc_get_coef0(codec) & 0x00ff) == 0x017) {
val = alc_read_coef_idx(codec, 0x04);
alc_write_coef_idx(codec, 0x04, val | (1<<11));
}
if ((alc_get_coef0(codec) & 0x00ff) == 0x018) {
val = alc_read_coef_idx(codec, 0xd);
if ((val & 0x0c00) >> 10 != 0x1) {
alc_write_coef_idx(codec, 0xd, val | (1<<10));
}
val = alc_read_coef_idx(codec, 0x17);
if ((val & 0x01c0) >> 6 != 0x4) {
alc_write_coef_idx(codec, 0x17, val | (1<<7));
}
}
val = alc_read_coef_idx(codec, 0xd);
alc_write_coef_idx(codec, 0xd, val | (1<<14));
val = alc_read_coef_idx(codec, 0x4);
alc_write_coef_idx(codec, 0x4, val | (1<<11));
}
static int patch_alc269(struct hda_codec *codec)
{
struct alc_spec *spec;
int err;
err = alc_alloc_spec(codec, 0x0b);
if (err < 0)
return err;
spec = codec->spec;
alc_pick_fixup(codec, alc269_fixup_models,
alc269_fixup_tbl, alc269_fixups);
alc_apply_fixup(codec, ALC_FIXUP_ACT_PRE_PROBE);
alc_auto_parse_customize_define(codec);
switch (codec->vendor_id) {
case 0x10ec0269:
spec->codec_variant = ALC269_TYPE_ALC269VA;
switch (alc_get_coef0(codec) & 0x00f0) {
case 0x0010:
if (codec->bus->pci->subsystem_vendor == 0x1025 &&
spec->cdefine.platform_type == 1)
err = alc_codec_rename(codec, "ALC271X");
spec->codec_variant = ALC269_TYPE_ALC269VB;
break;
case 0x0020:
if (codec->bus->pci->subsystem_vendor == 0x17aa &&
codec->bus->pci->subsystem_device == 0x21f3)
err = alc_codec_rename(codec, "ALC3202");
spec->codec_variant = ALC269_TYPE_ALC269VC;
break;
case 0x0030:
spec->codec_variant = ALC269_TYPE_ALC269VD;
break;
default:
alc_fix_pll_init(codec, 0x20, 0x04, 15);
}
if (err < 0)
goto error;
spec->init_hook = alc269_fill_coef;
alc269_fill_coef(codec);
break;
case 0x10ec0280:
case 0x10ec0290:
spec->codec_variant = ALC269_TYPE_ALC280;
break;
case 0x10ec0282:
case 0x10ec0283:
spec->codec_variant = ALC269_TYPE_ALC282;
break;
case 0x10ec0284:
case 0x10ec0292:
spec->codec_variant = ALC269_TYPE_ALC284;
break;
}
err = alc269_parse_auto_config(codec);
if (err < 0)
goto error;
if (!spec->no_analog && has_cdefine_beep(codec)) {
err = snd_hda_attach_beep_device(codec, 0x1);
if (err < 0)
goto error;
set_beep_amp(spec, 0x0b, 0x04, HDA_INPUT);
}
codec->patch_ops = alc_patch_ops;
#ifdef CONFIG_PM
codec->patch_ops.resume = alc269_resume;
#endif
spec->shutup = alc269_shutup;
alc_apply_fixup(codec, ALC_FIXUP_ACT_PROBE);
return 0;
error:
alc_free(codec);
return err;
}
static int alc861_parse_auto_config(struct hda_codec *codec)
{
static const hda_nid_t alc861_ignore[] = { 0x1d, 0 };
static const hda_nid_t alc861_ssids[] = { 0x0e, 0x0f, 0x0b, 0 };
return alc_parse_auto_config(codec, alc861_ignore, alc861_ssids);
}
static void alc861_fixup_asus_amp_vref_0f(struct hda_codec *codec,
const struct alc_fixup *fix, int action)
{
struct alc_spec *spec = codec->spec;
unsigned int val;
if (action != ALC_FIXUP_ACT_INIT)
return;
val = snd_hda_codec_read(codec, 0x0f, 0,
AC_VERB_GET_PIN_WIDGET_CONTROL, 0);
if (!(val & (AC_PINCTL_IN_EN | AC_PINCTL_OUT_EN)))
val |= AC_PINCTL_IN_EN;
val |= AC_PINCTL_VREF_50;
snd_hda_set_pin_ctl(codec, 0x0f, val);
spec->keep_vref_in_automute = 1;
}
static void alc_fixup_no_jack_detect(struct hda_codec *codec,
const struct alc_fixup *fix, int action)
{
if (action == ALC_FIXUP_ACT_PRE_PROBE)
codec->no_jack_detect = 1;
}
static int patch_alc861(struct hda_codec *codec)
{
struct alc_spec *spec;
int err;
err = alc_alloc_spec(codec, 0x15);
if (err < 0)
return err;
spec = codec->spec;
alc_pick_fixup(codec, NULL, alc861_fixup_tbl, alc861_fixups);
alc_apply_fixup(codec, ALC_FIXUP_ACT_PRE_PROBE);
err = alc861_parse_auto_config(codec);
if (err < 0)
goto error;
if (!spec->no_analog) {
err = snd_hda_attach_beep_device(codec, 0x23);
if (err < 0)
goto error;
set_beep_amp(spec, 0x23, 0, HDA_OUTPUT);
}
codec->patch_ops = alc_patch_ops;
#ifdef CONFIG_PM
spec->power_hook = alc_power_eapd;
#endif
alc_apply_fixup(codec, ALC_FIXUP_ACT_PROBE);
return 0;
error:
alc_free(codec);
return err;
}
static int alc861vd_parse_auto_config(struct hda_codec *codec)
{
static const hda_nid_t alc861vd_ignore[] = { 0x1d, 0 };
static const hda_nid_t alc861vd_ssids[] = { 0x15, 0x1b, 0x14, 0 };
return alc_parse_auto_config(codec, alc861vd_ignore, alc861vd_ssids);
}
static void alc861vd_fixup_dallas(struct hda_codec *codec,
const struct alc_fixup *fix, int action)
{
if (action == ALC_FIXUP_ACT_PRE_PROBE) {
snd_hda_override_pin_caps(codec, 0x18, 0x00000734);
snd_hda_override_pin_caps(codec, 0x19, 0x0000073c);
}
}
static int patch_alc861vd(struct hda_codec *codec)
{
struct alc_spec *spec;
int err;
err = alc_alloc_spec(codec, 0x0b);
if (err < 0)
return err;
spec = codec->spec;
alc_pick_fixup(codec, NULL, alc861vd_fixup_tbl, alc861vd_fixups);
alc_apply_fixup(codec, ALC_FIXUP_ACT_PRE_PROBE);
err = alc861vd_parse_auto_config(codec);
if (err < 0)
goto error;
if (!spec->no_analog) {
err = snd_hda_attach_beep_device(codec, 0x23);
if (err < 0)
goto error;
set_beep_amp(spec, 0x0b, 0x05, HDA_INPUT);
}
codec->patch_ops = alc_patch_ops;
spec->shutup = alc_eapd_shutup;
alc_apply_fixup(codec, ALC_FIXUP_ACT_PROBE);
return 0;
error:
alc_free(codec);
return err;
}
static int alc662_parse_auto_config(struct hda_codec *codec)
{
static const hda_nid_t alc662_ignore[] = { 0x1d, 0 };
static const hda_nid_t alc663_ssids[] = { 0x15, 0x1b, 0x14, 0x21 };
static const hda_nid_t alc662_ssids[] = { 0x15, 0x1b, 0x14, 0 };
const hda_nid_t *ssids;
if (codec->vendor_id == 0x10ec0272 || codec->vendor_id == 0x10ec0663 ||
codec->vendor_id == 0x10ec0665 || codec->vendor_id == 0x10ec0670)
ssids = alc663_ssids;
else
ssids = alc662_ssids;
return alc_parse_auto_config(codec, alc662_ignore, ssids);
}
static void alc272_fixup_mario(struct hda_codec *codec,
const struct alc_fixup *fix, int action)
{
if (action != ALC_FIXUP_ACT_PROBE)
return;
if (snd_hda_override_amp_caps(codec, 0x2, HDA_OUTPUT,
(0x3b << AC_AMPCAP_OFFSET_SHIFT) |
(0x3b << AC_AMPCAP_NUM_STEPS_SHIFT) |
(0x03 << AC_AMPCAP_STEP_SIZE_SHIFT) |
(0 << AC_AMPCAP_MUTE_SHIFT)))
printk(KERN_WARNING
"hda_codec: failed to override amp caps for NID 0x2\n");
}
static void alc662_fill_coef(struct hda_codec *codec)
{
int val, coef;
coef = alc_get_coef0(codec);
switch (codec->vendor_id) {
case 0x10ec0662:
if ((coef & 0x00f0) == 0x0030) {
val = alc_read_coef_idx(codec, 0x4);
alc_write_coef_idx(codec, 0x4, val & ~(1<<10));
}
break;
case 0x10ec0272:
case 0x10ec0273:
case 0x10ec0663:
case 0x10ec0665:
case 0x10ec0670:
case 0x10ec0671:
case 0x10ec0672:
val = alc_read_coef_idx(codec, 0xd);
alc_write_coef_idx(codec, 0xd, val | (1<<14));
break;
}
}
static int patch_alc662(struct hda_codec *codec)
{
struct alc_spec *spec;
int err;
err = alc_alloc_spec(codec, 0x0b);
if (err < 0)
return err;
spec = codec->spec;
spec->parse_flags = HDA_PINCFG_NO_HP_FIXUP;
alc_fix_pll_init(codec, 0x20, 0x04, 15);
spec->init_hook = alc662_fill_coef;
alc662_fill_coef(codec);
alc_pick_fixup(codec, alc662_fixup_models,
alc662_fixup_tbl, alc662_fixups);
alc_apply_fixup(codec, ALC_FIXUP_ACT_PRE_PROBE);
alc_auto_parse_customize_define(codec);
if ((alc_get_coef0(codec) & (1 << 14)) &&
codec->bus->pci->subsystem_vendor == 0x1025 &&
spec->cdefine.platform_type == 1) {
if (alc_codec_rename(codec, "ALC272X") < 0)
goto error;
}
err = alc662_parse_auto_config(codec);
if (err < 0)
goto error;
if (!spec->no_analog && has_cdefine_beep(codec)) {
err = snd_hda_attach_beep_device(codec, 0x1);
if (err < 0)
goto error;
switch (codec->vendor_id) {
case 0x10ec0662:
set_beep_amp(spec, 0x0b, 0x05, HDA_INPUT);
break;
case 0x10ec0272:
case 0x10ec0663:
case 0x10ec0665:
set_beep_amp(spec, 0x0b, 0x04, HDA_INPUT);
break;
case 0x10ec0273:
set_beep_amp(spec, 0x0b, 0x03, HDA_INPUT);
break;
}
}
codec->patch_ops = alc_patch_ops;
spec->shutup = alc_eapd_shutup;
alc_apply_fixup(codec, ALC_FIXUP_ACT_PROBE);
return 0;
error:
alc_free(codec);
return err;
}
static int alc680_parse_auto_config(struct hda_codec *codec)
{
return alc_parse_auto_config(codec, NULL, NULL);
}
static int patch_alc680(struct hda_codec *codec)
{
int err;
err = alc_alloc_spec(codec, 0);
if (err < 0)
return err;
err = alc680_parse_auto_config(codec);
if (err < 0) {
alc_free(codec);
return err;
}
codec->patch_ops = alc_patch_ops;
return 0;
}
static int __init patch_realtek_init(void)
{
return snd_hda_add_codec_preset(&realtek_list);
}
static void __exit patch_realtek_exit(void)
{
snd_hda_delete_codec_preset(&realtek_list);
}
