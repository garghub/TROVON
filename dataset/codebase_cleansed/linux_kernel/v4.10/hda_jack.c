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
static struct hda_jack_tbl *
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
struct hda_jack_tbl *jack = codec->jacktbl.list;
int i;
for (i = 0; i < codec->jacktbl.used; i++, jack++) {
struct hda_jack_callback *cb, *next;
if (!codec->bus->shutdown && jack->jack)
snd_device_free(codec->card, jack->jack);
for (cb = jack->callback; cb; cb = next) {
next = cb->next;
kfree(cb);
}
}
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
int snd_hda_jack_detect_state(struct hda_codec *codec, hda_nid_t nid)
{
struct hda_jack_tbl *jack = snd_hda_jack_tbl_get(codec, nid);
if (jack && jack->phantom_jack)
return HDA_JACK_PHANTOM;
else if (snd_hda_pin_sense(codec, nid) & AC_PINSENSE_PRESENCE)
return HDA_JACK_PRESENT;
else
return HDA_JACK_NOT_PRESENT;
}
struct hda_jack_callback *
snd_hda_jack_detect_enable_callback(struct hda_codec *codec, hda_nid_t nid,
hda_jack_callback_fn func)
{
struct hda_jack_tbl *jack;
struct hda_jack_callback *callback = NULL;
int err;
jack = snd_hda_jack_tbl_new(codec, nid);
if (!jack)
return ERR_PTR(-ENOMEM);
if (func) {
callback = kzalloc(sizeof(*callback), GFP_KERNEL);
if (!callback)
return ERR_PTR(-ENOMEM);
callback->func = func;
callback->nid = jack->nid;
callback->next = jack->callback;
jack->callback = callback;
}
if (jack->jack_detect)
return callback;
jack->jack_detect = 1;
if (codec->jackpoll_interval > 0)
return callback;
err = snd_hda_codec_write_cache(codec, nid, 0,
AC_VERB_SET_UNSOLICITED_ENABLE,
AC_USRSP_EN | jack->tag);
if (err < 0)
return ERR_PTR(err);
return callback;
}
int snd_hda_jack_detect_enable(struct hda_codec *codec, hda_nid_t nid)
{
return PTR_ERR_OR_ZERO(snd_hda_jack_detect_enable_callback(codec, nid, NULL));
}
int snd_hda_jack_set_gating_jack(struct hda_codec *codec, hda_nid_t gated_nid,
hda_nid_t gating_nid)
{
struct hda_jack_tbl *gated = snd_hda_jack_tbl_new(codec, gated_nid);
struct hda_jack_tbl *gating = snd_hda_jack_tbl_new(codec, gating_nid);
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
if (!jack->jack || jack->block_report)
continue;
state = get_jack_plug_state(jack->pin_sense);
snd_jack_report(jack->jack,
state ? jack->type : 0);
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
int snd_hda_jack_add_kctl(struct hda_codec *codec, hda_nid_t nid,
const char *name, bool phantom_jack)
{
struct hda_jack_tbl *jack;
int err, state, type;
jack = snd_hda_jack_tbl_new(codec, nid);
if (!jack)
return 0;
if (jack->jack)
return 0;
type = get_input_jack_type(codec, nid);
err = snd_jack_new(codec->card, name, type,
&jack->jack, true, phantom_jack);
if (err < 0)
return err;
jack->phantom_jack = !!phantom_jack;
jack->type = type;
jack->jack->private_data = jack;
jack->jack->private_free = hda_free_jack_priv;
state = snd_hda_jack_detect(codec, nid);
snd_jack_report(jack->jack, state ? jack->type : 0);
return 0;
}
static int add_jack_kctl(struct hda_codec *codec, hda_nid_t nid,
const struct auto_pin_cfg *cfg,
const char *base_name)
{
unsigned int def_conf, conn;
char name[SNDRV_CTL_ELEM_ID_NAME_MAXLEN];
int err;
bool phantom_jack;
if (!nid)
return 0;
def_conf = snd_hda_codec_get_pincfg(codec, nid);
conn = get_defcfg_connect(def_conf);
if (conn == AC_JACK_PORT_NONE)
return 0;
phantom_jack = (conn != AC_JACK_PORT_COMPLEX) ||
!is_jack_detectable(codec, nid);
if (base_name)
strlcpy(name, base_name, sizeof(name));
else
snd_hda_get_pin_label(codec, nid, cfg, name, sizeof(name), NULL);
if (phantom_jack)
strncat(name, " Phantom", sizeof(name) - strlen(name) - 1);
err = snd_hda_jack_add_kctl(codec, nid, name, phantom_jack);
if (err < 0)
return err;
if (!phantom_jack)
return snd_hda_jack_detect_enable(codec, nid);
return 0;
}
int snd_hda_jack_add_kctls(struct hda_codec *codec,
const struct auto_pin_cfg *cfg)
{
const hda_nid_t *p;
int i, err;
for (i = 0; i < cfg->num_inputs; i++) {
if (cfg->inputs[i].is_headphone_mic) {
if (auto_cfg_hp_outs(cfg) == 1)
err = add_jack_kctl(codec, auto_cfg_hp_pins(cfg)[0],
cfg, "Headphone Mic");
else
err = add_jack_kctl(codec, cfg->inputs[i].pin,
cfg, "Headphone Mic");
} else
err = add_jack_kctl(codec, cfg->inputs[i].pin, cfg,
NULL);
if (err < 0)
return err;
}
for (i = 0, p = cfg->line_out_pins; i < cfg->line_outs; i++, p++) {
err = add_jack_kctl(codec, *p, cfg, NULL);
if (err < 0)
return err;
}
for (i = 0, p = cfg->hp_pins; i < cfg->hp_outs; i++, p++) {
if (*p == *cfg->line_out_pins)
break;
err = add_jack_kctl(codec, *p, cfg, NULL);
if (err < 0)
return err;
}
for (i = 0, p = cfg->speaker_pins; i < cfg->speaker_outs; i++, p++) {
if (*p == *cfg->line_out_pins)
break;
err = add_jack_kctl(codec, *p, cfg, NULL);
if (err < 0)
return err;
}
for (i = 0, p = cfg->dig_out_pins; i < cfg->dig_outs; i++, p++) {
err = add_jack_kctl(codec, *p, cfg, NULL);
if (err < 0)
return err;
}
err = add_jack_kctl(codec, cfg->dig_in_pin, cfg, NULL);
if (err < 0)
return err;
err = add_jack_kctl(codec, cfg->mono_out_pin, cfg, NULL);
if (err < 0)
return err;
return 0;
}
static void call_jack_callback(struct hda_codec *codec,
struct hda_jack_tbl *jack)
{
struct hda_jack_callback *cb;
for (cb = jack->callback; cb; cb = cb->next)
cb->func(codec, cb);
if (jack->gated_jack) {
struct hda_jack_tbl *gated =
snd_hda_jack_tbl_get(codec, jack->gated_jack);
if (gated) {
for (cb = gated->callback; cb; cb = cb->next)
cb->func(codec, cb);
}
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
