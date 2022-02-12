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
static int alc_mux_select(struct hda_codec *codec, unsigned int adc_idx,
unsigned int idx, bool force)
{
struct alc_spec *spec = codec->spec;
const struct hda_input_mux *imux;
unsigned int mux_idx;
int i, type, num_conns;
hda_nid_t nid;
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
if (spec->dyn_adc_switch) {
alc_dyn_adc_pcm_resetup(codec, idx);
adc_idx = spec->dyn_adc_idx[idx];
}
nid = get_capsrc(spec, adc_idx);
num_conns = snd_hda_get_conn_list(codec, nid, NULL);
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
if (auto_pin_type == AUTO_PIN_MIC) {
unsigned int pincap;
unsigned int oldval;
oldval = snd_hda_codec_read(codec, nid, 0,
AC_VERB_GET_PIN_WIDGET_CONTROL, 0);
pincap = snd_hda_query_pin_caps(codec, nid);
pincap = (pincap & AC_PINCAP_VREF) >> AC_PINCAP_VREF_SHIFT;
if ((pincap & AC_PINCAP_VREF_80) && oldval != PIN_VREF50)
val = PIN_VREF80;
else if (pincap & AC_PINCAP_VREF_50)
val = PIN_VREF50;
else if (pincap & AC_PINCAP_VREF_100)
val = PIN_VREF100;
else if (pincap & AC_PINCAP_VREF_GRD)
val = PIN_VREFGRD;
}
snd_hda_codec_write(codec, nid, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, val);
}
static void add_mixer(struct alc_spec *spec, const struct snd_kcontrol_new *mix)
{
if (snd_BUG_ON(spec->num_mixers >= ARRAY_SIZE(spec->mixers)))
return;
spec->mixers[spec->num_mixers++] = mix;
}
static void add_verb(struct alc_spec *spec, const struct hda_verb *verb)
{
if (snd_BUG_ON(spec->num_init_verbs >= ARRAY_SIZE(spec->init_verbs)))
return;
spec->init_verbs[spec->num_init_verbs++] = verb;
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
static int alc_init_jacks(struct hda_codec *codec)
{
#ifdef CONFIG_SND_HDA_INPUT_JACK
struct alc_spec *spec = codec->spec;
int err;
unsigned int hp_nid = spec->autocfg.hp_pins[0];
unsigned int mic_nid = spec->ext_mic_pin;
unsigned int dock_nid = spec->dock_mic_pin;
if (hp_nid) {
err = snd_hda_input_jack_add(codec, hp_nid,
SND_JACK_HEADPHONE, NULL);
if (err < 0)
return err;
snd_hda_input_jack_report(codec, hp_nid);
}
if (mic_nid) {
err = snd_hda_input_jack_add(codec, mic_nid,
SND_JACK_MICROPHONE, NULL);
if (err < 0)
return err;
snd_hda_input_jack_report(codec, mic_nid);
}
if (dock_nid) {
err = snd_hda_input_jack_add(codec, dock_nid,
SND_JACK_MICROPHONE, NULL);
if (err < 0)
return err;
snd_hda_input_jack_report(codec, dock_nid);
}
#endif
return 0;
}
static bool detect_jacks(struct hda_codec *codec, int num_pins, hda_nid_t *pins)
{
int i, present = 0;
for (i = 0; i < num_pins; i++) {
hda_nid_t nid = pins[i];
if (!nid)
break;
snd_hda_input_jack_report(codec, nid);
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
if (!nid)
break;
switch (spec->automute_mode) {
case ALC_AUTOMUTE_PIN:
snd_hda_codec_write(codec, nid, 0,
AC_VERB_SET_PIN_WIDGET_CONTROL,
pin_bits);
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
static void alc_hp_automute(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->hp_jack_present =
detect_jacks(codec, ARRAY_SIZE(spec->autocfg.hp_pins),
spec->autocfg.hp_pins);
if (!spec->detect_hp || (!spec->automute_speaker && !spec->automute_lo))
return;
call_update_outputs(codec);
}
static void alc_line_automute(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
if (spec->autocfg.line_out_pins[0] == spec->autocfg.hp_pins[0])
return;
spec->line_jack_present =
detect_jacks(codec, ARRAY_SIZE(spec->autocfg.line_out_pins),
spec->autocfg.line_out_pins);
if (!spec->automute_speaker || !spec->detect_lo)
return;
call_update_outputs(codec);
}
static void alc_mic_automute(struct hda_codec *codec)
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
snd_hda_input_jack_report(codec, pins[spec->ext_mic_idx]);
if (spec->dock_mic_idx >= 0)
snd_hda_input_jack_report(codec, pins[spec->dock_mic_idx]);
}
static void alc_sku_unsol_event(struct hda_codec *codec, unsigned int res)
{
if (codec->vendor_id == 0x10ec0880)
res >>= 28;
else
res >>= 26;
switch (res) {
case ALC_HP_EVENT:
alc_hp_automute(codec);
break;
case ALC_FRONT_EVENT:
alc_line_automute(codec);
break;
case ALC_MIC_EVENT:
alc_mic_automute(codec);
break;
}
}
static void alc_inithook(struct hda_codec *codec)
{
alc_hp_automute(codec);
alc_line_automute(codec);
alc_mic_automute(codec);
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
static const char * const texts2[] = {
"Disabled", "Enabled"
};
static const char * const texts3[] = {
"Disabled", "Speaker Only", "Line-Out+Speaker"
};
const char * const *texts;
uinfo->type = SNDRV_CTL_ELEM_TYPE_ENUMERATED;
uinfo->count = 1;
if (spec->automute_speaker_possible && spec->automute_lo_possible) {
uinfo->value.enumerated.items = 3;
texts = texts3;
} else {
uinfo->value.enumerated.items = 2;
texts = texts2;
}
if (uinfo->value.enumerated.item >= uinfo->value.enumerated.items)
uinfo->value.enumerated.item = uinfo->value.enumerated.items - 1;
strcpy(uinfo->value.enumerated.name,
texts[uinfo->value.enumerated.item]);
return 0;
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
static struct snd_kcontrol_new *alc_kcontrol_new(struct alc_spec *spec)
{
snd_array_init(&spec->kctls, sizeof(struct snd_kcontrol_new), 32);
return snd_array_new(&spec->kctls);
}
static int alc_add_automute_mode_enum(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
struct snd_kcontrol_new *knew;
knew = alc_kcontrol_new(spec);
if (!knew)
return -ENOMEM;
*knew = alc_automute_mode_enum;
knew->name = kstrdup("Auto-Mute Mode", GFP_KERNEL);
if (!knew->name)
return -ENOMEM;
return 0;
}
static void alc_init_automute(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
struct auto_pin_cfg *cfg = &spec->autocfg;
int present = 0;
int i;
if (cfg->hp_pins[0])
present++;
if (cfg->line_out_pins[0])
present++;
if (cfg->speaker_pins[0])
present++;
if (present < 2)
return;
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
snd_hda_codec_write_cache(codec, nid, 0,
AC_VERB_SET_UNSOLICITED_ENABLE,
AC_USRSP_EN | ALC_HP_EVENT);
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
snd_hda_codec_write_cache(codec, nid, 0,
AC_VERB_SET_UNSOLICITED_ENABLE,
AC_USRSP_EN | ALC_FRONT_EVENT);
spec->detect_lo = 1;
}
spec->automute_lo_possible = spec->detect_hp;
}
spec->automute_speaker_possible = cfg->speaker_outs &&
(spec->detect_hp || spec->detect_lo);
spec->automute_lo = spec->automute_lo_possible;
spec->automute_speaker = spec->automute_speaker_possible;
if (spec->automute_speaker_possible || spec->automute_lo_possible) {
alc_add_automute_mode_enum(codec);
spec->unsol_event = alc_sku_unsol_event;
}
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
static bool alc_rebuild_imux_for_auto_mic(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
struct hda_input_mux *imux;
static char * const texts[3] = {
"Mic", "Internal Mic", "Dock Mic"
};
int i;
if (!spec->auto_mic)
return false;
imux = &spec->private_imux[0];
if (spec->input_mux == imux)
return true;
spec->imux_pins[0] = spec->ext_mic_pin;
spec->imux_pins[1] = spec->int_mic_pin;
spec->imux_pins[2] = spec->dock_mic_pin;
for (i = 0; i < 3; i++) {
strcpy(imux->items[i].label, texts[i]);
if (spec->imux_pins[i]) {
hda_nid_t pin = spec->imux_pins[i];
int c;
for (c = 0; c < spec->num_adc_nids; c++) {
hda_nid_t cap = get_capsrc(spec, c);
int idx = get_connection_index(codec, cap, pin);
if (idx >= 0) {
imux->items[i].index = idx;
break;
}
}
imux->num_items = i + 1;
}
}
spec->num_mux_defs = 1;
spec->input_mux = imux;
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
snd_hda_codec_write_cache(codec, spec->ext_mic_pin, 0,
AC_VERB_SET_UNSOLICITED_ENABLE,
AC_USRSP_EN | ALC_MIC_EVENT);
if (spec->dock_mic_pin)
snd_hda_codec_write_cache(codec, spec->dock_mic_pin, 0,
AC_VERB_SET_UNSOLICITED_ENABLE,
AC_USRSP_EN | ALC_MIC_EVENT);
spec->auto_mic_valid_imux = 1;
spec->auto_mic = 1;
return true;
}
static void alc_init_auto_mic(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
struct auto_pin_cfg *cfg = &spec->autocfg;
hda_nid_t fixed, ext, dock;
int i;
spec->ext_mic_idx = spec->int_mic_idx = spec->dock_mic_idx = -1;
fixed = ext = dock = 0;
for (i = 0; i < cfg->num_inputs; i++) {
hda_nid_t nid = cfg->inputs[i].pin;
unsigned int defcfg;
defcfg = snd_hda_codec_get_pincfg(codec, nid);
switch (snd_hda_get_input_pin_attr(defcfg)) {
case INPUT_PIN_ATTR_INT:
if (fixed)
return;
if (cfg->inputs[i].type != AUTO_PIN_MIC)
return;
fixed = nid;
break;
case INPUT_PIN_ATTR_UNUSED:
return;
case INPUT_PIN_ATTR_DOCK:
if (dock)
return;
if (cfg->inputs[i].type > AUTO_PIN_LINE_IN)
return;
dock = nid;
break;
default:
if (ext)
return;
if (cfg->inputs[i].type != AUTO_PIN_MIC)
return;
ext = nid;
break;
}
}
if (!ext && dock) {
ext = dock;
dock = 0;
}
if (!ext || !fixed)
return;
if (!is_jack_detectable(codec, ext))
return;
if (dock && !is_jack_detectable(codec, dock))
return;
spec->ext_mic_pin = ext;
spec->int_mic_pin = fixed;
spec->dock_mic_pin = dock;
spec->auto_mic = 1;
if (!alc_auto_mic_check_imux(codec))
return;
snd_printdd("realtek: Enable auto-mic switch on NID 0x%x/0x%x/0x%x\n",
ext, fixed, dock);
spec->unsol_event = alc_sku_unsol_event;
}
static void alc_auto_check_switches(struct hda_codec *codec)
{
alc_init_automute(codec);
alc_init_auto_mic(codec);
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
static void alc_apply_fixup(struct hda_codec *codec, int action)
{
struct alc_spec *spec = codec->spec;
int id = spec->fixup_id;
#ifdef CONFIG_SND_DEBUG_VERBOSE
const char *modelname = spec->fixup_name;
#endif
int depth = 0;
if (!spec->fixup_list)
return;
while (id >= 0) {
const struct alc_fixup *fix = spec->fixup_list + id;
const struct alc_pincfg *cfg;
switch (fix->type) {
case ALC_FIXUP_SKU:
if (action != ALC_FIXUP_ACT_PRE_PROBE || !fix->v.sku)
break;
snd_printdd(KERN_INFO "hda_codec: %s: "
"Apply sku override for %s\n",
codec->chip_name, modelname);
spec->cdefine.sku_cfg = fix->v.sku;
spec->cdefine.fixup = 1;
break;
case ALC_FIXUP_PINS:
cfg = fix->v.pins;
if (action != ALC_FIXUP_ACT_PRE_PROBE || !cfg)
break;
snd_printdd(KERN_INFO "hda_codec: %s: "
"Apply pincfg for %s\n",
codec->chip_name, modelname);
for (; cfg->nid; cfg++)
snd_hda_codec_set_pincfg(codec, cfg->nid,
cfg->val);
break;
case ALC_FIXUP_VERBS:
if (action != ALC_FIXUP_ACT_PROBE || !fix->v.verbs)
break;
snd_printdd(KERN_INFO "hda_codec: %s: "
"Apply fix-verbs for %s\n",
codec->chip_name, modelname);
add_verb(codec->spec, fix->v.verbs);
break;
case ALC_FIXUP_FUNC:
if (!fix->v.func)
break;
snd_printdd(KERN_INFO "hda_codec: %s: "
"Apply fix-func for %s\n",
codec->chip_name, modelname);
fix->v.func(codec, fix, action);
break;
default:
snd_printk(KERN_ERR "hda_codec: %s: "
"Invalid fixup type %d\n",
codec->chip_name, fix->type);
break;
}
if (!fix->chained)
break;
if (++depth > 10)
break;
id = fix->chain_id;
}
}
static void alc_pick_fixup(struct hda_codec *codec,
const struct alc_model_fixup *models,
const struct snd_pci_quirk *quirk,
const struct alc_fixup *fixlist)
{
struct alc_spec *spec = codec->spec;
int id = -1;
const char *name = NULL;
if (codec->modelname && models) {
while (models->name) {
if (!strcmp(codec->modelname, models->name)) {
id = models->id;
name = models->name;
break;
}
models++;
}
}
if (id < 0) {
quirk = snd_pci_quirk_lookup(codec->bus->pci, quirk);
if (quirk) {
id = quirk->value;
#ifdef CONFIG_SND_DEBUG_VERBOSE
name = quirk->name;
#endif
}
}
spec->fixup_id = id;
if (id >= 0) {
spec->fixup_list = fixlist;
spec->fixup_name = name;
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
snd_hda_codec_write(codec, pin, 0,
AC_VERB_SET_PIN_WIDGET_CONTROL, PIN_OUT);
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
snd_hda_codec_write(codec, pin, 0,
AC_VERB_SET_PIN_WIDGET_CONTROL,
PIN_IN);
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
getput_call_t func, bool check_adc_switch)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct alc_spec *spec = codec->spec;
int i, err = 0;
mutex_lock(&codec->control_mutex);
if (check_adc_switch && spec->dyn_adc_switch) {
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
static int alc_build_controls(struct hda_codec *codec)
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
err = snd_hda_create_spdif_out_ctls(codec,
spec->multiout.dig_out_nid,
spec->multiout.dig_out_nid);
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
vmaster_tlv, alc_slave_vols);
if (err < 0)
return err;
}
if (!spec->no_analog &&
!snd_hda_find_mixer_ctl(codec, "Master Playback Switch")) {
err = snd_hda_add_vmaster(codec, "Master Playback Switch",
NULL, alc_slave_sws);
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
static int alc_init(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
unsigned int i;
alc_fix_pll(codec);
alc_auto_init_amp(codec, spec->init_amp);
for (i = 0; i < spec->num_init_verbs; i++)
snd_hda_sequence_write(codec, spec->init_verbs[i]);
alc_init_special_input_src(codec);
if (spec->init_hook)
spec->init_hook(codec);
alc_apply_fixup(codec, ALC_FIXUP_ACT_INIT);
hda_call_check_power_status(codec, 0x01);
return 0;
}
static void alc_unsol_event(struct hda_codec *codec, unsigned int res)
{
struct alc_spec *spec = codec->spec;
if (spec->unsol_event)
spec->unsol_event(codec, res);
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
if (spec->multiout.dac_nids > 0) {
p = spec->stream_analog_playback;
if (!p)
p = &alc_pcm_analog_playback;
info->stream[SNDRV_PCM_STREAM_PLAYBACK] = *p;
info->stream[SNDRV_PCM_STREAM_PLAYBACK].nid = spec->multiout.dac_nids[0];
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
alc_shutup(codec);
snd_hda_input_jack_free(codec);
alc_free_kctls(codec);
alc_free_bind_ctls(codec);
kfree(spec);
snd_hda_detach_beep_device(codec);
}
static void alc_power_eapd(struct hda_codec *codec)
{
alc_auto_setup_eapd(codec, false);
}
static int alc_suspend(struct hda_codec *codec, pm_message_t state)
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
knew = alc_kcontrol_new(spec);
if (!knew)
return -ENOMEM;
*knew = alc_control_templates[type];
knew->name = kstrdup(name, GFP_KERNEL);
if (!knew->name)
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
if (snd_BUG_ON(ch >= ARRAY_SIZE(channel_name)))
return "PCM";
return channel_name[ch];
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
const hda_nid_t *list;
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
n = snd_hda_get_conn_list(codec, src, &list);
if (n > 1) {
cap_nids[nums] = src;
break;
} else if (n != 1)
break;
src = *list;
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
static void alc_set_pin_output(struct hda_codec *codec, hda_nid_t nid,
unsigned int pin_type)
{
snd_hda_codec_write(codec, nid, 0, AC_VERB_SET_PIN_WIDGET_CONTROL,
pin_type);
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
int nums = snd_hda_get_conn_list(codec, spec->mixer_nid, NULL);
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
static hda_nid_t alc_auto_look_for_dac(struct hda_codec *codec, hda_nid_t pin)
{
struct alc_spec *spec = codec->spec;
hda_nid_t srcs[5];
int i, num;
pin = alc_go_down_to_selector(codec, pin);
num = snd_hda_get_connections(codec, pin, srcs, ARRAY_SIZE(srcs));
for (i = 0; i < num; i++) {
hda_nid_t nid = alc_auto_mix_to_dac(codec, srcs[i]);
if (!nid)
continue;
if (found_in_nid_list(nid, spec->multiout.dac_nids,
ARRAY_SIZE(spec->private_dac_nids)))
continue;
if (found_in_nid_list(nid, spec->multiout.hp_out_nid,
ARRAY_SIZE(spec->multiout.hp_out_nid)))
continue;
if (found_in_nid_list(nid, spec->multiout.extra_out_nid,
ARRAY_SIZE(spec->multiout.extra_out_nid)))
continue;
return nid;
}
return 0;
}
static hda_nid_t get_dac_if_single(struct hda_codec *codec, hda_nid_t pin)
{
hda_nid_t sel = alc_go_down_to_selector(codec, pin);
if (snd_hda_get_conn_list(codec, sel, NULL) == 1)
return alc_auto_look_for_dac(codec, pin);
return 0;
}
static int alc_auto_fill_extra_dacs(struct hda_codec *codec, int num_outs,
const hda_nid_t *pins, hda_nid_t *dacs)
{
int i;
if (num_outs && !dacs[0]) {
dacs[0] = alc_auto_look_for_dac(codec, pins[0]);
if (!dacs[0])
return 0;
}
for (i = 1; i < num_outs; i++)
dacs[i] = get_dac_if_single(codec, pins[i]);
for (i = 1; i < num_outs; i++) {
if (!dacs[i])
dacs[i] = alc_auto_look_for_dac(codec, pins[i]);
}
return 1;
}
static int alc_auto_fill_dac_nids(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
struct auto_pin_cfg *cfg = &spec->autocfg;
bool redone = false;
int i;
again:
spec->multiout.num_dacs = cfg->line_outs;
spec->multiout.hp_out_nid[0] = 0;
spec->multiout.extra_out_nid[0] = 0;
memset(spec->private_dac_nids, 0, sizeof(spec->private_dac_nids));
spec->multiout.dac_nids = spec->private_dac_nids;
spec->multi_ios = 0;
if (!redone) {
for (i = 0; i < cfg->line_outs; i++)
spec->private_dac_nids[i] =
get_dac_if_single(codec, cfg->line_out_pins[i]);
if (cfg->hp_outs)
spec->multiout.hp_out_nid[0] =
get_dac_if_single(codec, cfg->hp_pins[0]);
if (cfg->speaker_outs)
spec->multiout.extra_out_nid[0] =
get_dac_if_single(codec, cfg->speaker_pins[0]);
}
for (i = 0; i < cfg->line_outs; i++) {
hda_nid_t pin = cfg->line_out_pins[i];
if (spec->private_dac_nids[i])
continue;
spec->private_dac_nids[i] = alc_auto_look_for_dac(codec, pin);
if (!spec->private_dac_nids[i] && !redone) {
redone = true;
goto again;
}
}
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
if (cfg->line_outs == 1 && cfg->line_out_type != AUTO_PIN_SPEAKER_OUT) {
unsigned int location, defcfg;
int num_pins;
defcfg = snd_hda_codec_get_pincfg(codec, cfg->line_out_pins[0]);
location = get_defcfg_location(defcfg);
num_pins = alc_auto_fill_multi_ios(codec, location);
if (num_pins > 0) {
spec->multi_ios = num_pins;
spec->ext_channel_count = 2;
spec->multiout.num_dacs = num_pins + 1;
}
}
if (cfg->line_out_type != AUTO_PIN_HP_OUT)
alc_auto_fill_extra_dacs(codec, cfg->hp_outs, cfg->hp_pins,
spec->multiout.hp_out_nid);
if (cfg->line_out_type != AUTO_PIN_SPEAKER_OUT) {
int err = alc_auto_fill_extra_dacs(codec, cfg->speaker_outs,
cfg->speaker_pins,
spec->multiout.extra_out_nid);
if (!err && cfg->speaker_outs > 0 &&
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
redone = false;
goto again;
}
}
return 0;
}
static inline unsigned int get_ctl_pos(unsigned int data)
{
hda_nid_t nid = get_amp_nid_(data);
unsigned int dir = get_amp_direction_(data);
return (nid << 1) | dir;
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
} else if (snd_hda_get_conn_list(codec, nid, NULL) == 1) {
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
if (spec->multi_ios > 0)
noutputs += spec->multi_ios;
for (i = 0; i < noutputs; i++) {
const char *name;
int index;
hda_nid_t dac, pin;
hda_nid_t sw, vol;
dac = spec->multiout.dac_nids[i];
if (!dac)
continue;
if (i >= cfg->line_outs)
pin = spec->multi_io[i - 1].pin;
else
pin = cfg->line_out_pins[i];
sw = alc_look_for_out_mute_nid(codec, pin, dac);
vol = alc_look_for_out_vol_nid(codec, pin, dac);
name = alc_get_line_out_pfx(spec, i, true, &index);
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
snd_array_init(&spec->bind_ctls, sizeof(ctl), 8);
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
if (dacs[num_pins - 1]) {
for (i = 0; i < num_pins; i++) {
if (num_pins >= 3) {
snprintf(name, sizeof(name), "%s %s",
pfx, channel_name[i]);
err = alc_auto_create_extra_out(codec, pins[i], dacs[i],
name, 0);
} else {
err = alc_auto_create_extra_out(codec, pins[i], dacs[i],
pfx, i);
}
if (err < 0)
return err;
}
return 0;
}
ctl = new_bind_ctl(codec, num_pins, &snd_hda_bind_sw);
if (!ctl)
return -ENOMEM;
n = 0;
for (i = 0; i < num_pins; i++) {
if (get_wcaps(codec, pins[i]) & AC_WCAP_OUT_AMP)
ctl->values[n++] =
HDA_COMPOSE_AMP_VAL(pins[i], 3, 0, HDA_OUTPUT);
}
if (n) {
snprintf(name, sizeof(name), "%s Playback Switch", pfx);
err = add_control(spec, ALC_CTL_BIND_SW, name, 0, (long)ctl);
if (err < 0)
return err;
}
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
static int alc_auto_fill_multi_ios(struct hda_codec *codec,
unsigned int location)
{
struct alc_spec *spec = codec->spec;
struct auto_pin_cfg *cfg = &spec->autocfg;
hda_nid_t prime_dac = spec->private_dac_nids[0];
int type, i, num_pins = 0;
for (type = AUTO_PIN_LINE_IN; type >= AUTO_PIN_MIC; type--) {
for (i = 0; i < cfg->num_inputs; i++) {
hda_nid_t nid = cfg->inputs[i].pin;
hda_nid_t dac;
unsigned int defcfg, caps;
if (cfg->inputs[i].type != type)
continue;
defcfg = snd_hda_codec_get_pincfg(codec, nid);
if (get_defcfg_connect(defcfg) != AC_JACK_PORT_COMPLEX)
continue;
if (location && get_defcfg_location(defcfg) != location)
continue;
caps = snd_hda_query_pin_caps(codec, nid);
if (!(caps & AC_PINCAP_OUT))
continue;
dac = alc_auto_look_for_dac(codec, nid);
if (!dac)
continue;
spec->multi_io[num_pins].pin = nid;
spec->multi_io[num_pins].dac = dac;
num_pins++;
spec->private_dac_nids[spec->multiout.num_dacs++] = dac;
}
}
spec->multiout.num_dacs = 1;
if (num_pins < 2) {
memset(spec->private_dac_nids, 0,
sizeof(spec->private_dac_nids));
spec->private_dac_nids[0] = prime_dac;
return 0;
}
return num_pins;
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
snd_hda_codec_update_cache(codec, nid, 0,
AC_VERB_SET_PIN_WIDGET_CONTROL,
PIN_OUT);
if (get_wcaps(codec, nid) & AC_WCAP_OUT_AMP)
snd_hda_codec_amp_stereo(codec, nid, HDA_OUTPUT, 0,
HDA_AMP_MUTE, 0);
alc_auto_select_dac(codec, nid, spec->multi_io[idx].dac);
} else {
if (get_wcaps(codec, nid) & AC_WCAP_OUT_AMP)
snd_hda_codec_amp_stereo(codec, nid, HDA_OUTPUT, 0,
HDA_AMP_MUTE, HDA_AMP_MUTE);
snd_hda_codec_update_cache(codec, nid, 0,
AC_VERB_SET_PIN_WIDGET_CONTROL,
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
spec->multiout.max_channels = spec->ext_channel_count;
if (spec->need_dac_fix && !spec->const_channel_count)
spec->multiout.num_dacs = spec->multiout.max_channels / 2;
return 1;
}
static int alc_auto_add_multi_channel_mode(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
if (spec->multi_ios > 0) {
struct snd_kcontrol_new *knew;
knew = alc_kcontrol_new(spec);
if (!knew)
return -ENOMEM;
*knew = alc_auto_channel_mode_enum;
knew->name = kstrdup("Channel Mode", GFP_KERNEL);
if (!knew->name)
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
nums = 0;
for (n = 0; n < spec->num_adc_nids; n++) {
hda_nid_t cap = spec->private_capsrc_nids[n];
int num_conns = snd_hda_get_conn_list(codec, cap, NULL);
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
else if (spec->input_mux->num_items == 1)
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
alc_mux_select(codec, 0, spec->cur_mux[c], true);
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
} else if (snd_hda_get_conn_list(codec, cap, NULL) > 1) {
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
struct alc_spec *spec = codec->spec;
alc_auto_init_multi_out(codec);
alc_auto_init_extra_out(codec);
alc_auto_init_analog_input(codec);
alc_auto_init_input_src(codec);
alc_auto_init_digital(codec);
if (spec->unsol_event)
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
if (cfg->line_out_type == AUTO_PIN_SPEAKER_OUT &&
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
err = alc_auto_create_input_ctls(codec);
if (err < 0)
return err;
spec->multiout.max_channels = spec->multiout.num_dacs * 2;
dig_only:
alc_auto_parse_digital(codec);
if (!spec->no_analog)
alc_remove_invalid_adc_nids(codec);
if (ssid_nids)
alc_ssid_check(codec, ssid_nids);
if (!spec->no_analog) {
alc_auto_check_switches(codec);
err = alc_auto_add_mic_boost(codec);
if (err < 0)
return err;
}
if (spec->kctls.list)
add_mixer(spec, spec->kctls.list);
return 1;
}
static int alc880_parse_auto_config(struct hda_codec *codec)
{
static const hda_nid_t alc880_ignore[] = { 0x1d, 0 };
static const hda_nid_t alc880_ssids[] = { 0x15, 0x1b, 0x14, 0 };
return alc_parse_auto_config(codec, alc880_ignore, alc880_ssids);
}
static int patch_alc880(struct hda_codec *codec)
{
struct alc_spec *spec;
int board_config;
int err;
spec = kzalloc(sizeof(*spec), GFP_KERNEL);
if (spec == NULL)
return -ENOMEM;
codec->spec = spec;
spec->mixer_nid = 0x0b;
spec->need_dac_fix = 1;
board_config = alc_board_config(codec, ALC880_MODEL_LAST,
alc880_models, alc880_cfg_tbl);
if (board_config < 0) {
printk(KERN_INFO "hda_codec: %s: BIOS auto-probing.\n",
codec->chip_name);
board_config = ALC_MODEL_AUTO;
}
if (board_config == ALC_MODEL_AUTO) {
err = alc880_parse_auto_config(codec);
if (err < 0)
goto error;
#ifdef CONFIG_SND_HDA_ENABLE_REALTEK_QUIRKS
else if (!err) {
printk(KERN_INFO
"hda_codec: Cannot set up configuration "
"from BIOS. Using 3-stack mode...\n");
board_config = ALC880_3ST;
}
#endif
}
if (board_config != ALC_MODEL_AUTO)
setup_preset(codec, &alc880_presets[board_config]);
if (!spec->no_analog && !spec->adc_nids) {
alc_auto_fill_adc_caps(codec);
alc_rebuild_imux_for_auto_mic(codec);
alc_remove_invalid_adc_nids(codec);
}
if (!spec->no_analog && !spec->cap_mixer)
set_capture_mixer(codec);
if (!spec->no_analog) {
err = snd_hda_attach_beep_device(codec, 0x1);
if (err < 0)
goto error;
set_beep_amp(spec, 0x0b, 0x05, HDA_INPUT);
}
spec->vmaster_nid = 0x0c;
codec->patch_ops = alc_patch_ops;
if (board_config == ALC_MODEL_AUTO)
spec->init_hook = alc_auto_init_std;
#ifdef CONFIG_SND_HDA_POWER_SAVE
if (!spec->loopback.amplist)
spec->loopback.amplist = alc880_loopbacks;
#endif
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
static int patch_alc260(struct hda_codec *codec)
{
struct alc_spec *spec;
int err, board_config;
spec = kzalloc(sizeof(*spec), GFP_KERNEL);
if (spec == NULL)
return -ENOMEM;
codec->spec = spec;
spec->mixer_nid = 0x07;
board_config = alc_board_config(codec, ALC260_MODEL_LAST,
alc260_models, alc260_cfg_tbl);
if (board_config < 0) {
snd_printd(KERN_INFO "hda_codec: %s: BIOS auto-probing.\n",
codec->chip_name);
board_config = ALC_MODEL_AUTO;
}
if (board_config == ALC_MODEL_AUTO) {
alc_pick_fixup(codec, NULL, alc260_fixup_tbl, alc260_fixups);
alc_apply_fixup(codec, ALC_FIXUP_ACT_PRE_PROBE);
}
if (board_config == ALC_MODEL_AUTO) {
err = alc260_parse_auto_config(codec);
if (err < 0)
goto error;
#ifdef CONFIG_SND_HDA_ENABLE_REALTEK_QUIRKS
else if (!err) {
printk(KERN_INFO
"hda_codec: Cannot set up configuration "
"from BIOS. Using base mode...\n");
board_config = ALC260_BASIC;
}
#endif
}
if (board_config != ALC_MODEL_AUTO)
setup_preset(codec, &alc260_presets[board_config]);
if (!spec->no_analog && !spec->adc_nids) {
alc_auto_fill_adc_caps(codec);
alc_rebuild_imux_for_auto_mic(codec);
alc_remove_invalid_adc_nids(codec);
}
if (!spec->no_analog && !spec->cap_mixer)
set_capture_mixer(codec);
if (!spec->no_analog) {
err = snd_hda_attach_beep_device(codec, 0x1);
if (err < 0)
goto error;
set_beep_amp(spec, 0x07, 0x05, HDA_INPUT);
}
alc_apply_fixup(codec, ALC_FIXUP_ACT_PROBE);
spec->vmaster_nid = 0x08;
codec->patch_ops = alc_patch_ops;
if (board_config == ALC_MODEL_AUTO)
spec->init_hook = alc_auto_init_std;
spec->shutup = alc_eapd_shutup;
#ifdef CONFIG_SND_HDA_POWER_SAVE
if (!spec->loopback.amplist)
spec->loopback.amplist = alc260_loopbacks;
#endif
return 0;
error:
alc_free(codec);
return err;
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
int err, board_config;
spec = kzalloc(sizeof(*spec), GFP_KERNEL);
if (spec == NULL)
return -ENOMEM;
codec->spec = spec;
spec->mixer_nid = 0x0b;
switch (codec->vendor_id) {
case 0x10ec0882:
case 0x10ec0885:
break;
default:
alc_fix_pll_init(codec, 0x20, 0x0a, 10);
break;
}
err = alc_codec_rename_from_preset(codec);
if (err < 0)
goto error;
board_config = alc_board_config(codec, ALC882_MODEL_LAST,
alc882_models, alc882_cfg_tbl);
if (board_config < 0)
board_config = alc_board_codec_sid_config(codec,
ALC882_MODEL_LAST, alc882_models, alc882_ssid_cfg_tbl);
if (board_config < 0) {
printk(KERN_INFO "hda_codec: %s: BIOS auto-probing.\n",
codec->chip_name);
board_config = ALC_MODEL_AUTO;
}
if (board_config == ALC_MODEL_AUTO) {
alc_pick_fixup(codec, NULL, alc882_fixup_tbl, alc882_fixups);
alc_apply_fixup(codec, ALC_FIXUP_ACT_PRE_PROBE);
}
alc_auto_parse_customize_define(codec);
if (board_config == ALC_MODEL_AUTO) {
err = alc882_parse_auto_config(codec);
if (err < 0)
goto error;
#ifdef CONFIG_SND_HDA_ENABLE_REALTEK_QUIRKS
else if (!err) {
printk(KERN_INFO
"hda_codec: Cannot set up configuration "
"from BIOS. Using base mode...\n");
board_config = ALC882_3ST_DIG;
}
#endif
}
if (board_config != ALC_MODEL_AUTO)
setup_preset(codec, &alc882_presets[board_config]);
if (!spec->no_analog && !spec->adc_nids) {
alc_auto_fill_adc_caps(codec);
alc_rebuild_imux_for_auto_mic(codec);
alc_remove_invalid_adc_nids(codec);
}
if (!spec->no_analog && !spec->cap_mixer)
set_capture_mixer(codec);
if (!spec->no_analog && has_cdefine_beep(codec)) {
err = snd_hda_attach_beep_device(codec, 0x1);
if (err < 0)
goto error;
set_beep_amp(spec, 0x0b, 0x05, HDA_INPUT);
}
alc_apply_fixup(codec, ALC_FIXUP_ACT_PROBE);
spec->vmaster_nid = 0x0c;
codec->patch_ops = alc_patch_ops;
if (board_config == ALC_MODEL_AUTO)
spec->init_hook = alc_auto_init_std;
alc_init_jacks(codec);
#ifdef CONFIG_SND_HDA_POWER_SAVE
if (!spec->loopback.amplist)
spec->loopback.amplist = alc882_loopbacks;
#endif
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
int board_config;
int err;
spec = kzalloc(sizeof(*spec), GFP_KERNEL);
if (spec == NULL)
return -ENOMEM;
codec->spec = spec;
spec->mixer_nid = 0x0b;
#if 0
{
int tmp;
snd_hda_codec_write(codec, 0x1a, 0, AC_VERB_SET_COEF_INDEX, 7);
tmp = snd_hda_codec_read(codec, 0x20, 0, AC_VERB_GET_PROC_COEF, 0);
snd_hda_codec_write(codec, 0x1a, 0, AC_VERB_SET_COEF_INDEX, 7);
snd_hda_codec_write(codec, 0x1a, 0, AC_VERB_SET_PROC_COEF, tmp | 0x80);
}
#endif
alc_auto_parse_customize_define(codec);
alc_fix_pll_init(codec, 0x20, 0x0a, 10);
board_config = alc_board_config(codec, ALC262_MODEL_LAST,
alc262_models, alc262_cfg_tbl);
if (board_config < 0) {
printk(KERN_INFO "hda_codec: %s: BIOS auto-probing.\n",
codec->chip_name);
board_config = ALC_MODEL_AUTO;
}
if (board_config == ALC_MODEL_AUTO) {
alc_pick_fixup(codec, NULL, alc262_fixup_tbl, alc262_fixups);
alc_apply_fixup(codec, ALC_FIXUP_ACT_PRE_PROBE);
}
if (board_config == ALC_MODEL_AUTO) {
err = alc262_parse_auto_config(codec);
if (err < 0)
goto error;
#ifdef CONFIG_SND_HDA_ENABLE_REALTEK_QUIRKS
else if (!err) {
printk(KERN_INFO
"hda_codec: Cannot set up configuration "
"from BIOS. Using base mode...\n");
board_config = ALC262_BASIC;
}
#endif
}
if (board_config != ALC_MODEL_AUTO)
setup_preset(codec, &alc262_presets[board_config]);
if (!spec->no_analog && !spec->adc_nids) {
alc_auto_fill_adc_caps(codec);
alc_rebuild_imux_for_auto_mic(codec);
alc_remove_invalid_adc_nids(codec);
}
if (!spec->no_analog && !spec->cap_mixer)
set_capture_mixer(codec);
if (!spec->no_analog && has_cdefine_beep(codec)) {
err = snd_hda_attach_beep_device(codec, 0x1);
if (err < 0)
goto error;
set_beep_amp(spec, 0x0b, 0x05, HDA_INPUT);
}
alc_apply_fixup(codec, ALC_FIXUP_ACT_PROBE);
spec->vmaster_nid = 0x0c;
codec->patch_ops = alc_patch_ops;
if (board_config == ALC_MODEL_AUTO)
spec->init_hook = alc_auto_init_std;
spec->shutup = alc_eapd_shutup;
alc_init_jacks(codec);
#ifdef CONFIG_SND_HDA_POWER_SAVE
if (!spec->loopback.amplist)
spec->loopback.amplist = alc262_loopbacks;
#endif
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
add_verb(spec, alc268_beep_init_verbs);
}
}
return err;
}
static int patch_alc268(struct hda_codec *codec)
{
struct alc_spec *spec;
int i, has_beep, err;
spec = kzalloc(sizeof(*spec), GFP_KERNEL);
if (spec == NULL)
return -ENOMEM;
codec->spec = spec;
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
if (!spec->no_analog && !spec->adc_nids) {
alc_auto_fill_adc_caps(codec);
alc_rebuild_imux_for_auto_mic(codec);
alc_remove_invalid_adc_nids(codec);
}
if (!spec->no_analog && !spec->cap_mixer)
set_capture_mixer(codec);
spec->vmaster_nid = 0x02;
codec->patch_ops = alc_patch_ops;
spec->init_hook = alc_auto_init_std;
spec->shutup = alc_eapd_shutup;
alc_init_jacks(codec);
return 0;
error:
alc_free(codec);
return err;
}
static int alc269_mic2_for_mute_led(struct hda_codec *codec)
{
switch (codec->subsystem_id) {
case 0x103c1586:
return 1;
}
return 0;
}
static int alc269_mic2_mute_check_ps(struct hda_codec *codec, hda_nid_t nid)
{
if (nid == 0x01 || nid == 0x14) {
int pinval;
if (snd_hda_codec_amp_read(codec, 0x14, 0, HDA_OUTPUT, 0) &
HDA_AMP_MUTE)
pinval = 0x24;
else
pinval = 0x20;
snd_hda_codec_update_cache(codec, 0x19, 0,
AC_VERB_SET_PIN_WIDGET_CONTROL,
pinval);
}
return alc_check_power_status(codec, nid);
}
static int alc269_parse_auto_config(struct hda_codec *codec)
{
static const hda_nid_t alc269_ignore[] = { 0x1d, 0 };
static const hda_nid_t alc269_ssids[] = { 0, 0x1b, 0x14, 0x21 };
static const hda_nid_t alc269va_ssids[] = { 0x15, 0x1b, 0x14, 0 };
struct alc_spec *spec = codec->spec;
const hda_nid_t *ssids = spec->codec_variant == ALC269_TYPE_ALC269VA ?
alc269va_ssids : alc269_ssids;
return alc_parse_auto_config(codec, alc269_ignore, ssids);
}
static void alc269_toggle_power_output(struct hda_codec *codec, int power_up)
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
if ((alc_get_coef0(codec) & 0x00ff) == 0x017)
alc269_toggle_power_output(codec, 0);
if ((alc_get_coef0(codec) & 0x00ff) == 0x018) {
alc269_toggle_power_output(codec, 0);
msleep(150);
}
}
static int alc269_resume(struct hda_codec *codec)
{
if ((alc_get_coef0(codec) & 0x00ff) == 0x018) {
alc269_toggle_power_output(codec, 0);
msleep(150);
}
codec->patch_ops.init(codec);
if ((alc_get_coef0(codec) & 0x00ff) == 0x017) {
alc269_toggle_power_output(codec, 1);
msleep(200);
}
if ((alc_get_coef0(codec) & 0x00ff) == 0x018)
alc269_toggle_power_output(codec, 1);
snd_hda_codec_resume_amp(codec);
snd_hda_codec_resume_cache(codec);
hda_call_check_power_status(codec, 0x01);
return 0;
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
static int alc269_fill_coef(struct hda_codec *codec)
{
int val;
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
return 0;
}
static int patch_alc269(struct hda_codec *codec)
{
struct alc_spec *spec;
int err = 0;
spec = kzalloc(sizeof(*spec), GFP_KERNEL);
if (spec == NULL)
return -ENOMEM;
codec->spec = spec;
spec->mixer_nid = 0x0b;
alc_auto_parse_customize_define(codec);
err = alc_codec_rename_from_preset(codec);
if (err < 0)
goto error;
if (codec->vendor_id == 0x10ec0269) {
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
default:
alc_fix_pll_init(codec, 0x20, 0x04, 15);
}
if (err < 0)
goto error;
alc269_fill_coef(codec);
}
alc_pick_fixup(codec, alc269_fixup_models,
alc269_fixup_tbl, alc269_fixups);
alc_apply_fixup(codec, ALC_FIXUP_ACT_PRE_PROBE);
err = alc269_parse_auto_config(codec);
if (err < 0)
goto error;
if (!spec->no_analog && !spec->adc_nids) {
alc_auto_fill_adc_caps(codec);
alc_rebuild_imux_for_auto_mic(codec);
alc_remove_invalid_adc_nids(codec);
}
if (!spec->no_analog && !spec->cap_mixer)
set_capture_mixer(codec);
if (!spec->no_analog && has_cdefine_beep(codec)) {
err = snd_hda_attach_beep_device(codec, 0x1);
if (err < 0)
goto error;
set_beep_amp(spec, 0x0b, 0x04, HDA_INPUT);
}
alc_apply_fixup(codec, ALC_FIXUP_ACT_PROBE);
spec->vmaster_nid = 0x02;
codec->patch_ops = alc_patch_ops;
#ifdef CONFIG_PM
codec->patch_ops.resume = alc269_resume;
#endif
spec->init_hook = alc_auto_init_std;
spec->shutup = alc269_shutup;
alc_init_jacks(codec);
#ifdef CONFIG_SND_HDA_POWER_SAVE
if (!spec->loopback.amplist)
spec->loopback.amplist = alc269_loopbacks;
if (alc269_mic2_for_mute_led(codec))
codec->patch_ops.check_power_status = alc269_mic2_mute_check_ps;
#endif
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
static int patch_alc861(struct hda_codec *codec)
{
struct alc_spec *spec;
int err;
spec = kzalloc(sizeof(*spec), GFP_KERNEL);
if (spec == NULL)
return -ENOMEM;
codec->spec = spec;
spec->mixer_nid = 0x15;
alc_pick_fixup(codec, NULL, alc861_fixup_tbl, alc861_fixups);
alc_apply_fixup(codec, ALC_FIXUP_ACT_PRE_PROBE);
err = alc861_parse_auto_config(codec);
if (err < 0)
goto error;
if (!spec->no_analog && !spec->adc_nids) {
alc_auto_fill_adc_caps(codec);
alc_rebuild_imux_for_auto_mic(codec);
alc_remove_invalid_adc_nids(codec);
}
if (!spec->no_analog && !spec->cap_mixer)
set_capture_mixer(codec);
if (!spec->no_analog) {
err = snd_hda_attach_beep_device(codec, 0x23);
if (err < 0)
goto error;
set_beep_amp(spec, 0x23, 0, HDA_OUTPUT);
}
spec->vmaster_nid = 0x03;
alc_apply_fixup(codec, ALC_FIXUP_ACT_PROBE);
codec->patch_ops = alc_patch_ops;
spec->init_hook = alc_auto_init_std;
#ifdef CONFIG_SND_HDA_POWER_SAVE
spec->power_hook = alc_power_eapd;
if (!spec->loopback.amplist)
spec->loopback.amplist = alc861_loopbacks;
#endif
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
snd_hda_override_pin_caps(codec, 0x18, 0x00001714);
snd_hda_override_pin_caps(codec, 0x19, 0x0000171c);
}
}
static int patch_alc861vd(struct hda_codec *codec)
{
struct alc_spec *spec;
int err;
spec = kzalloc(sizeof(*spec), GFP_KERNEL);
if (spec == NULL)
return -ENOMEM;
codec->spec = spec;
spec->mixer_nid = 0x0b;
alc_pick_fixup(codec, NULL, alc861vd_fixup_tbl, alc861vd_fixups);
alc_apply_fixup(codec, ALC_FIXUP_ACT_PRE_PROBE);
err = alc861vd_parse_auto_config(codec);
if (err < 0)
goto error;
if (codec->vendor_id == 0x10ec0660) {
add_verb(spec, alc660vd_eapd_verbs);
}
if (!spec->no_analog && !spec->adc_nids) {
alc_auto_fill_adc_caps(codec);
alc_rebuild_imux_for_auto_mic(codec);
alc_remove_invalid_adc_nids(codec);
}
if (!spec->no_analog && !spec->cap_mixer)
set_capture_mixer(codec);
if (!spec->no_analog) {
err = snd_hda_attach_beep_device(codec, 0x23);
if (err < 0)
goto error;
set_beep_amp(spec, 0x0b, 0x05, HDA_INPUT);
}
spec->vmaster_nid = 0x02;
alc_apply_fixup(codec, ALC_FIXUP_ACT_PROBE);
codec->patch_ops = alc_patch_ops;
spec->init_hook = alc_auto_init_std;
spec->shutup = alc_eapd_shutup;
#ifdef CONFIG_SND_HDA_POWER_SAVE
if (!spec->loopback.amplist)
spec->loopback.amplist = alc861vd_loopbacks;
#endif
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
static int patch_alc662(struct hda_codec *codec)
{
struct alc_spec *spec;
int err = 0;
spec = kzalloc(sizeof(*spec), GFP_KERNEL);
if (!spec)
return -ENOMEM;
codec->spec = spec;
spec->mixer_nid = 0x0b;
spec->parse_flags = HDA_PINCFG_NO_HP_FIXUP;
alc_auto_parse_customize_define(codec);
alc_fix_pll_init(codec, 0x20, 0x04, 15);
err = alc_codec_rename_from_preset(codec);
if (err < 0)
goto error;
if ((alc_get_coef0(codec) & (1 << 14)) &&
codec->bus->pci->subsystem_vendor == 0x1025 &&
spec->cdefine.platform_type == 1) {
if (alc_codec_rename(codec, "ALC272X") < 0)
goto error;
}
alc_pick_fixup(codec, alc662_fixup_models,
alc662_fixup_tbl, alc662_fixups);
alc_apply_fixup(codec, ALC_FIXUP_ACT_PRE_PROBE);
err = alc662_parse_auto_config(codec);
if (err < 0)
goto error;
if (!spec->no_analog && !spec->adc_nids) {
alc_auto_fill_adc_caps(codec);
alc_rebuild_imux_for_auto_mic(codec);
alc_remove_invalid_adc_nids(codec);
}
if (!spec->no_analog && !spec->cap_mixer)
set_capture_mixer(codec);
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
spec->vmaster_nid = 0x02;
alc_apply_fixup(codec, ALC_FIXUP_ACT_PROBE);
codec->patch_ops = alc_patch_ops;
spec->init_hook = alc_auto_init_std;
spec->shutup = alc_eapd_shutup;
alc_init_jacks(codec);
#ifdef CONFIG_SND_HDA_POWER_SAVE
if (!spec->loopback.amplist)
spec->loopback.amplist = alc662_loopbacks;
#endif
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
struct alc_spec *spec;
int err;
spec = kzalloc(sizeof(*spec), GFP_KERNEL);
if (spec == NULL)
return -ENOMEM;
codec->spec = spec;
err = alc680_parse_auto_config(codec);
if (err < 0) {
alc_free(codec);
return err;
}
if (!spec->no_analog && !spec->cap_mixer)
set_capture_mixer(codec);
spec->vmaster_nid = 0x02;
codec->patch_ops = alc_patch_ops;
spec->init_hook = alc_auto_init_std;
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
