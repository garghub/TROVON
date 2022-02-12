bool is_jack_detectable(struct hda_codec *codec, hda_nid_t nid)
{
if (codec->no_jack_detect)
return false;
if (!(snd_hda_query_pin_caps(codec, nid) & AC_PINCAP_PRES_DETECT))
return false;
if (get_defcfg_misc(snd_hda_codec_get_pincfg(codec, nid)) &
AC_DEFCFG_MISC_NO_PRESENCE)
return false;
if (!(get_wcaps(codec, nid) & AC_WCAP_UNSOL_CAP) &&
!codec->jackpoll_interval)
return false;
return true;
}
static u32 read_pin_sense(struct hda_codec *codec, hda_nid_t nid)
{
u32 pincap;
u32 val;
if (!codec->no_trigger_sense) {
pincap = snd_hda_query_pin_caps(codec, nid);
if (pincap & AC_PINCAP_TRIG_REQ)
snd_hda_codec_read(codec, nid, 0,
AC_VERB_SET_PIN_SENSE, 0);
}
val = snd_hda_codec_read(codec, nid, 0,
AC_VERB_GET_PIN_SENSE, 0);
if (codec->inv_jack_detect)
val ^= AC_PINSENSE_PRESENCE;
return val;
}
struct hda_jack_tbl *
snd_hda_jack_tbl_get(struct hda_codec *codec, hda_nid_t nid)
{
struct hda_jack_tbl *jack = codec->jacktbl.list;
int i;
if (!nid || !jack)
return NULL;
for (i = 0; i < codec->jacktbl.used; i++, jack++)
if (jack->nid == nid)
return jack;
return NULL;
}
struct hda_jack_tbl *
snd_hda_jack_tbl_get_from_tag(struct hda_codec *codec, unsigned char tag)
{
struct hda_jack_tbl *jack = codec->jacktbl.list;
int i;
if (!tag || !jack)
return NULL;
for (i = 0; i < codec->jacktbl.used; i++, jack++)
if (jack->tag == tag)
return jack;
return NULL;
}
struct hda_jack_tbl *
snd_hda_jack_tbl_new(struct hda_codec *codec, hda_nid_t nid)
{
struct hda_jack_tbl *jack = snd_hda_jack_tbl_get(codec, nid);
if (jack)
return jack;
jack = snd_array_new(&codec->jacktbl);
if (!jack)
return NULL;
jack->nid = nid;
jack->jack_dirty = 1;
jack->tag = codec->jacktbl.used;
return jack;
}
void snd_hda_jack_tbl_clear(struct hda_codec *codec)
{
#ifdef CONFIG_SND_HDA_INPUT_JACK
if (!codec->bus->shutdown && codec->jacktbl.list) {
struct hda_jack_tbl *jack = codec->jacktbl.list;
int i;
for (i = 0; i < codec->jacktbl.used; i++, jack++) {
if (jack->jack)
snd_device_free(codec->bus->card, jack->jack);
}
}
#endif
snd_array_free(&codec->jacktbl);
}
static void jack_detect_update(struct hda_codec *codec,
struct hda_jack_tbl *jack)
{
if (!jack->jack_dirty)
return;
if (jack->phantom_jack)
jack->pin_sense = AC_PINSENSE_PRESENCE;
else
jack->pin_sense = read_pin_sense(codec, jack->nid);
if (jack->gating_jack && !snd_hda_jack_detect(codec, jack->gating_jack))
jack->pin_sense &= ~AC_PINSENSE_PRESENCE;
jack->jack_dirty = 0;
if (jack->gated_jack) {
struct hda_jack_tbl *gated =
snd_hda_jack_tbl_get(codec, jack->gated_jack);
if (gated) {
gated->jack_dirty = 1;
jack_detect_update(codec, gated);
}
}
}
void snd_hda_jack_set_dirty_all(struct hda_codec *codec)
{
struct hda_jack_tbl *jack = codec->jacktbl.list;
int i;
for (i = 0; i < codec->jacktbl.used; i++, jack++)
if (jack->nid)
jack->jack_dirty = 1;
}
u32 snd_hda_pin_sense(struct hda_codec *codec, hda_nid_t nid)
{
struct hda_jack_tbl *jack = snd_hda_jack_tbl_get(codec, nid);
if (jack) {
jack_detect_update(codec, jack);
return jack->pin_sense;
}
return read_pin_sense(codec, nid);
}
int snd_hda_jack_detect(struct hda_codec *codec, hda_nid_t nid)
{
u32 sense = snd_hda_pin_sense(codec, nid);
return get_jack_plug_state(sense);
}
int snd_hda_jack_detect_enable_callback(struct hda_codec *codec, hda_nid_t nid,
unsigned char action,
hda_jack_callback cb)
{
struct hda_jack_tbl *jack = snd_hda_jack_tbl_new(codec, nid);
if (!jack)
return -ENOMEM;
if (jack->jack_detect)
return 0;
jack->jack_detect = 1;
if (action)
jack->action = action;
if (cb)
jack->callback = cb;
if (codec->jackpoll_interval > 0)
return 0;
return snd_hda_codec_write_cache(codec, nid, 0,
AC_VERB_SET_UNSOLICITED_ENABLE,
AC_USRSP_EN | jack->tag);
}
int snd_hda_jack_detect_enable(struct hda_codec *codec, hda_nid_t nid,
unsigned char action)
{
return snd_hda_jack_detect_enable_callback(codec, nid, action, NULL);
}
int snd_hda_jack_set_gating_jack(struct hda_codec *codec, hda_nid_t gated_nid,
hda_nid_t gating_nid)
{
struct hda_jack_tbl *gated = snd_hda_jack_tbl_get(codec, gated_nid);
struct hda_jack_tbl *gating = snd_hda_jack_tbl_get(codec, gating_nid);
if (!gated || !gating)
return -EINVAL;
gated->gating_jack = gating_nid;
gating->gated_jack = gated_nid;
return 0;
}
void snd_hda_jack_report_sync(struct hda_codec *codec)
{
struct hda_jack_tbl *jack;
int i, state;
jack = codec->jacktbl.list;
for (i = 0; i < codec->jacktbl.used; i++, jack++)
if (jack->nid)
jack_detect_update(codec, jack);
jack = codec->jacktbl.list;
for (i = 0; i < codec->jacktbl.used; i++, jack++)
if (jack->nid) {
if (!jack->kctl)
continue;
state = get_jack_plug_state(jack->pin_sense);
snd_kctl_jack_report(codec->bus->card, jack->kctl, state);
#ifdef CONFIG_SND_HDA_INPUT_JACK
if (jack->jack)
snd_jack_report(jack->jack,
state ? jack->type : 0);
#endif
}
}
static int get_input_jack_type(struct hda_codec *codec, hda_nid_t nid)
{
unsigned int def_conf = snd_hda_codec_get_pincfg(codec, nid);
switch (get_defcfg_device(def_conf)) {
case AC_JACK_LINE_OUT:
case AC_JACK_SPEAKER:
return SND_JACK_LINEOUT;
case AC_JACK_HP_OUT:
return SND_JACK_HEADPHONE;
case AC_JACK_SPDIF_OUT:
case AC_JACK_DIG_OTHER_OUT:
return SND_JACK_AVOUT;
case AC_JACK_MIC_IN:
return SND_JACK_MICROPHONE;
default:
return SND_JACK_LINEIN;
}
}
static void hda_free_jack_priv(struct snd_jack *jack)
{
struct hda_jack_tbl *jacks = jack->private_data;
jacks->nid = 0;
jacks->jack = NULL;
}
static int __snd_hda_jack_add_kctl(struct hda_codec *codec, hda_nid_t nid,
const char *name, int idx, bool phantom_jack)
{
struct hda_jack_tbl *jack;
struct snd_kcontrol *kctl;
int err, state;
jack = snd_hda_jack_tbl_new(codec, nid);
if (!jack)
return 0;
if (jack->kctl)
return 0;
kctl = snd_kctl_jack_new(name, idx, codec);
if (!kctl)
return -ENOMEM;
err = snd_hda_ctl_add(codec, nid, kctl);
if (err < 0)
return err;
jack->kctl = kctl;
jack->phantom_jack = !!phantom_jack;
state = snd_hda_jack_detect(codec, nid);
snd_kctl_jack_report(codec->bus->card, kctl, state);
#ifdef CONFIG_SND_HDA_INPUT_JACK
if (!phantom_jack) {
jack->type = get_input_jack_type(codec, nid);
err = snd_jack_new(codec->bus->card, name, jack->type,
&jack->jack);
if (err < 0)
return err;
jack->jack->private_data = jack;
jack->jack->private_free = hda_free_jack_priv;
snd_jack_report(jack->jack, state ? jack->type : 0);
}
#endif
return 0;
}
int snd_hda_jack_add_kctl(struct hda_codec *codec, hda_nid_t nid,
const char *name, int idx)
{
return __snd_hda_jack_add_kctl(codec, nid, name, idx, false);
}
static int get_unique_index(struct hda_codec *codec, const char *name, int idx)
{
struct hda_jack_tbl *jack;
int i, len = strlen(name);
again:
jack = codec->jacktbl.list;
for (i = 0; i < codec->jacktbl.used; i++, jack++) {
if (jack->kctl &&
!strncmp(name, jack->kctl->id.name, len) &&
!strcmp(" Jack", jack->kctl->id.name + len) &&
jack->kctl->id.index == idx) {
idx++;
goto again;
}
}
return idx;
}
static int add_jack_kctl(struct hda_codec *codec, hda_nid_t nid,
const struct auto_pin_cfg *cfg)
{
unsigned int def_conf, conn;
char name[44];
int idx, err;
bool phantom_jack;
if (!nid)
return 0;
def_conf = snd_hda_codec_get_pincfg(codec, nid);
conn = get_defcfg_connect(def_conf);
if (conn == AC_JACK_PORT_NONE)
return 0;
phantom_jack = (conn != AC_JACK_PORT_COMPLEX) ||
!is_jack_detectable(codec, nid);
snd_hda_get_pin_label(codec, nid, cfg, name, sizeof(name), &idx);
if (phantom_jack)
strncat(name, " Phantom", sizeof(name) - strlen(name) - 1);
idx = get_unique_index(codec, name, idx);
err = __snd_hda_jack_add_kctl(codec, nid, name, idx, phantom_jack);
if (err < 0)
return err;
if (!phantom_jack)
return snd_hda_jack_detect_enable(codec, nid, 0);
return 0;
}
int snd_hda_jack_add_kctls(struct hda_codec *codec,
const struct auto_pin_cfg *cfg)
{
const hda_nid_t *p;
int i, err;
for (i = 0, p = cfg->line_out_pins; i < cfg->line_outs; i++, p++) {
err = add_jack_kctl(codec, *p, cfg);
if (err < 0)
return err;
}
for (i = 0, p = cfg->hp_pins; i < cfg->hp_outs; i++, p++) {
if (*p == *cfg->line_out_pins)
break;
err = add_jack_kctl(codec, *p, cfg);
if (err < 0)
return err;
}
for (i = 0, p = cfg->speaker_pins; i < cfg->speaker_outs; i++, p++) {
if (*p == *cfg->line_out_pins)
break;
err = add_jack_kctl(codec, *p, cfg);
if (err < 0)
return err;
}
for (i = 0; i < cfg->num_inputs; i++) {
err = add_jack_kctl(codec, cfg->inputs[i].pin, cfg);
if (err < 0)
return err;
}
for (i = 0, p = cfg->dig_out_pins; i < cfg->dig_outs; i++, p++) {
err = add_jack_kctl(codec, *p, cfg);
if (err < 0)
return err;
}
err = add_jack_kctl(codec, cfg->dig_in_pin, cfg);
if (err < 0)
return err;
err = add_jack_kctl(codec, cfg->mono_out_pin, cfg);
if (err < 0)
return err;
return 0;
}
static void call_jack_callback(struct hda_codec *codec,
struct hda_jack_tbl *jack)
{
if (jack->callback)
jack->callback(codec, jack);
if (jack->gated_jack) {
struct hda_jack_tbl *gated =
snd_hda_jack_tbl_get(codec, jack->gated_jack);
if (gated && gated->callback)
gated->callback(codec, gated);
}
}
void snd_hda_jack_unsol_event(struct hda_codec *codec, unsigned int res)
{
struct hda_jack_tbl *event;
int tag = (res >> AC_UNSOL_RES_TAG_SHIFT) & 0x7f;
event = snd_hda_jack_tbl_get_from_tag(codec, tag);
if (!event)
return;
event->jack_dirty = 1;
call_jack_callback(codec, event);
snd_hda_jack_report_sync(codec);
}
void snd_hda_jack_poll_all(struct hda_codec *codec)
{
struct hda_jack_tbl *jack = codec->jacktbl.list;
int i, changes = 0;
for (i = 0; i < codec->jacktbl.used; i++, jack++) {
unsigned int old_sense;
if (!jack->nid || !jack->jack_dirty || jack->phantom_jack)
continue;
old_sense = get_jack_plug_state(jack->pin_sense);
jack_detect_update(codec, jack);
if (old_sense == get_jack_plug_state(jack->pin_sense))
continue;
changes = 1;
call_jack_callback(codec, jack);
}
if (changes)
snd_hda_jack_report_sync(codec);
}
