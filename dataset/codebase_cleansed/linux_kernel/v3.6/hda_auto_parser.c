static int is_in_nid_list(hda_nid_t nid, const hda_nid_t *list)
{
for (; *list; list++)
if (*list == nid)
return 1;
return 0;
}
static void sort_pins_by_sequence(hda_nid_t *pins, short *sequences,
int num_pins)
{
int i, j;
short seq;
hda_nid_t nid;
for (i = 0; i < num_pins; i++) {
for (j = i + 1; j < num_pins; j++) {
if (sequences[i] > sequences[j]) {
seq = sequences[i];
sequences[i] = sequences[j];
sequences[j] = seq;
nid = pins[i];
pins[i] = pins[j];
pins[j] = nid;
}
}
}
}
static void add_auto_cfg_input_pin(struct auto_pin_cfg *cfg, hda_nid_t nid,
int type)
{
if (cfg->num_inputs < AUTO_CFG_MAX_INS) {
cfg->inputs[cfg->num_inputs].pin = nid;
cfg->inputs[cfg->num_inputs].type = type;
cfg->num_inputs++;
}
}
static void sort_autocfg_input_pins(struct auto_pin_cfg *cfg)
{
int i, j;
for (i = 0; i < cfg->num_inputs; i++) {
for (j = i + 1; j < cfg->num_inputs; j++) {
if (cfg->inputs[i].type > cfg->inputs[j].type) {
struct auto_pin_cfg_item tmp;
tmp = cfg->inputs[i];
cfg->inputs[i] = cfg->inputs[j];
cfg->inputs[j] = tmp;
}
}
}
}
static void reorder_outputs(unsigned int nums, hda_nid_t *pins)
{
hda_nid_t nid;
switch (nums) {
case 3:
case 4:
nid = pins[1];
pins[1] = pins[2];
pins[2] = nid;
break;
}
}
int snd_hda_parse_pin_defcfg(struct hda_codec *codec,
struct auto_pin_cfg *cfg,
const hda_nid_t *ignore_nids,
unsigned int cond_flags)
{
hda_nid_t nid, end_nid;
short seq, assoc_line_out;
short sequences_line_out[ARRAY_SIZE(cfg->line_out_pins)];
short sequences_speaker[ARRAY_SIZE(cfg->speaker_pins)];
short sequences_hp[ARRAY_SIZE(cfg->hp_pins)];
int i;
memset(cfg, 0, sizeof(*cfg));
memset(sequences_line_out, 0, sizeof(sequences_line_out));
memset(sequences_speaker, 0, sizeof(sequences_speaker));
memset(sequences_hp, 0, sizeof(sequences_hp));
assoc_line_out = 0;
codec->ignore_misc_bit = true;
end_nid = codec->start_nid + codec->num_nodes;
for (nid = codec->start_nid; nid < end_nid; nid++) {
unsigned int wid_caps = get_wcaps(codec, nid);
unsigned int wid_type = get_wcaps_type(wid_caps);
unsigned int def_conf;
short assoc, loc, conn, dev;
if (wid_type != AC_WID_PIN)
continue;
if (ignore_nids && is_in_nid_list(nid, ignore_nids))
continue;
def_conf = snd_hda_codec_get_pincfg(codec, nid);
if (!(get_defcfg_misc(snd_hda_codec_get_pincfg(codec, nid)) &
AC_DEFCFG_MISC_NO_PRESENCE))
codec->ignore_misc_bit = false;
conn = get_defcfg_connect(def_conf);
if (conn == AC_JACK_PORT_NONE)
continue;
loc = get_defcfg_location(def_conf);
dev = get_defcfg_device(def_conf);
if (dev == AC_JACK_LINE_OUT) {
if (conn == AC_JACK_PORT_FIXED)
dev = AC_JACK_SPEAKER;
}
switch (dev) {
case AC_JACK_LINE_OUT:
seq = get_defcfg_sequence(def_conf);
assoc = get_defcfg_association(def_conf);
if (!(wid_caps & AC_WCAP_STEREO))
if (!cfg->mono_out_pin)
cfg->mono_out_pin = nid;
if (!assoc)
continue;
if (!assoc_line_out)
assoc_line_out = assoc;
else if (assoc_line_out != assoc)
continue;
if (cfg->line_outs >= ARRAY_SIZE(cfg->line_out_pins))
continue;
cfg->line_out_pins[cfg->line_outs] = nid;
sequences_line_out[cfg->line_outs] = seq;
cfg->line_outs++;
break;
case AC_JACK_SPEAKER:
seq = get_defcfg_sequence(def_conf);
assoc = get_defcfg_association(def_conf);
if (cfg->speaker_outs >= ARRAY_SIZE(cfg->speaker_pins))
continue;
cfg->speaker_pins[cfg->speaker_outs] = nid;
sequences_speaker[cfg->speaker_outs] = (assoc << 4) | seq;
cfg->speaker_outs++;
break;
case AC_JACK_HP_OUT:
seq = get_defcfg_sequence(def_conf);
assoc = get_defcfg_association(def_conf);
if (cfg->hp_outs >= ARRAY_SIZE(cfg->hp_pins))
continue;
cfg->hp_pins[cfg->hp_outs] = nid;
sequences_hp[cfg->hp_outs] = (assoc << 4) | seq;
cfg->hp_outs++;
break;
case AC_JACK_MIC_IN:
add_auto_cfg_input_pin(cfg, nid, AUTO_PIN_MIC);
break;
case AC_JACK_LINE_IN:
add_auto_cfg_input_pin(cfg, nid, AUTO_PIN_LINE_IN);
break;
case AC_JACK_CD:
add_auto_cfg_input_pin(cfg, nid, AUTO_PIN_CD);
break;
case AC_JACK_AUX:
add_auto_cfg_input_pin(cfg, nid, AUTO_PIN_AUX);
break;
case AC_JACK_SPDIF_OUT:
case AC_JACK_DIG_OTHER_OUT:
if (cfg->dig_outs >= ARRAY_SIZE(cfg->dig_out_pins))
continue;
cfg->dig_out_pins[cfg->dig_outs] = nid;
cfg->dig_out_type[cfg->dig_outs] =
(loc == AC_JACK_LOC_HDMI) ?
HDA_PCM_TYPE_HDMI : HDA_PCM_TYPE_SPDIF;
cfg->dig_outs++;
break;
case AC_JACK_SPDIF_IN:
case AC_JACK_DIG_OTHER_IN:
cfg->dig_in_pin = nid;
if (loc == AC_JACK_LOC_HDMI)
cfg->dig_in_type = HDA_PCM_TYPE_HDMI;
else
cfg->dig_in_type = HDA_PCM_TYPE_SPDIF;
break;
}
}
if (!cfg->line_outs && cfg->hp_outs > 1 &&
!(cond_flags & HDA_PINCFG_NO_HP_FIXUP)) {
int i = 0;
while (i < cfg->hp_outs) {
if ((sequences_hp[i] & 0x0f) == 0x0f) {
i++;
continue;
}
cfg->line_out_pins[cfg->line_outs] = cfg->hp_pins[i];
sequences_line_out[cfg->line_outs] = sequences_hp[i];
cfg->line_outs++;
cfg->hp_outs--;
memmove(cfg->hp_pins + i, cfg->hp_pins + i + 1,
sizeof(cfg->hp_pins[0]) * (cfg->hp_outs - i));
memmove(sequences_hp + i, sequences_hp + i + 1,
sizeof(sequences_hp[0]) * (cfg->hp_outs - i));
}
memset(cfg->hp_pins + cfg->hp_outs, 0,
sizeof(hda_nid_t) * (AUTO_CFG_MAX_OUTS - cfg->hp_outs));
if (!cfg->hp_outs)
cfg->line_out_type = AUTO_PIN_HP_OUT;
}
sort_pins_by_sequence(cfg->line_out_pins, sequences_line_out,
cfg->line_outs);
sort_pins_by_sequence(cfg->speaker_pins, sequences_speaker,
cfg->speaker_outs);
sort_pins_by_sequence(cfg->hp_pins, sequences_hp,
cfg->hp_outs);
if (!cfg->line_outs &&
!(cond_flags & HDA_PINCFG_NO_LO_FIXUP)) {
if (cfg->speaker_outs) {
cfg->line_outs = cfg->speaker_outs;
memcpy(cfg->line_out_pins, cfg->speaker_pins,
sizeof(cfg->speaker_pins));
cfg->speaker_outs = 0;
memset(cfg->speaker_pins, 0, sizeof(cfg->speaker_pins));
cfg->line_out_type = AUTO_PIN_SPEAKER_OUT;
} else if (cfg->hp_outs) {
cfg->line_outs = cfg->hp_outs;
memcpy(cfg->line_out_pins, cfg->hp_pins,
sizeof(cfg->hp_pins));
cfg->hp_outs = 0;
memset(cfg->hp_pins, 0, sizeof(cfg->hp_pins));
cfg->line_out_type = AUTO_PIN_HP_OUT;
}
}
reorder_outputs(cfg->line_outs, cfg->line_out_pins);
reorder_outputs(cfg->hp_outs, cfg->hp_pins);
reorder_outputs(cfg->speaker_outs, cfg->speaker_pins);
sort_autocfg_input_pins(cfg);
snd_printd("autoconfig: line_outs=%d (0x%x/0x%x/0x%x/0x%x/0x%x) type:%s\n",
cfg->line_outs, cfg->line_out_pins[0], cfg->line_out_pins[1],
cfg->line_out_pins[2], cfg->line_out_pins[3],
cfg->line_out_pins[4],
cfg->line_out_type == AUTO_PIN_HP_OUT ? "hp" :
(cfg->line_out_type == AUTO_PIN_SPEAKER_OUT ?
"speaker" : "line"));
snd_printd(" speaker_outs=%d (0x%x/0x%x/0x%x/0x%x/0x%x)\n",
cfg->speaker_outs, cfg->speaker_pins[0],
cfg->speaker_pins[1], cfg->speaker_pins[2],
cfg->speaker_pins[3], cfg->speaker_pins[4]);
snd_printd(" hp_outs=%d (0x%x/0x%x/0x%x/0x%x/0x%x)\n",
cfg->hp_outs, cfg->hp_pins[0],
cfg->hp_pins[1], cfg->hp_pins[2],
cfg->hp_pins[3], cfg->hp_pins[4]);
snd_printd(" mono: mono_out=0x%x\n", cfg->mono_out_pin);
if (cfg->dig_outs)
snd_printd(" dig-out=0x%x/0x%x\n",
cfg->dig_out_pins[0], cfg->dig_out_pins[1]);
snd_printd(" inputs:\n");
for (i = 0; i < cfg->num_inputs; i++) {
snd_printd(" %s=0x%x\n",
hda_get_autocfg_input_label(codec, cfg, i),
cfg->inputs[i].pin);
}
if (cfg->dig_in_pin)
snd_printd(" dig-in=0x%x\n", cfg->dig_in_pin);
return 0;
}
int snd_hda_get_input_pin_attr(unsigned int def_conf)
{
unsigned int loc = get_defcfg_location(def_conf);
unsigned int conn = get_defcfg_connect(def_conf);
if (conn == AC_JACK_PORT_NONE)
return INPUT_PIN_ATTR_UNUSED;
if (conn == AC_JACK_PORT_FIXED || conn == AC_JACK_PORT_BOTH)
return INPUT_PIN_ATTR_INT;
if ((loc & 0x30) == AC_JACK_LOC_INTERNAL)
return INPUT_PIN_ATTR_INT;
if ((loc & 0x30) == AC_JACK_LOC_SEPARATE)
return INPUT_PIN_ATTR_DOCK;
if (loc == AC_JACK_LOC_REAR)
return INPUT_PIN_ATTR_REAR;
if (loc == AC_JACK_LOC_FRONT)
return INPUT_PIN_ATTR_FRONT;
return INPUT_PIN_ATTR_NORMAL;
}
static const char *hda_get_input_pin_label(struct hda_codec *codec,
hda_nid_t pin, bool check_location)
{
unsigned int def_conf;
static const char * const mic_names[] = {
"Internal Mic", "Dock Mic", "Mic", "Front Mic", "Rear Mic",
};
int attr;
def_conf = snd_hda_codec_get_pincfg(codec, pin);
switch (get_defcfg_device(def_conf)) {
case AC_JACK_MIC_IN:
if (!check_location)
return "Mic";
attr = snd_hda_get_input_pin_attr(def_conf);
if (!attr)
return "None";
return mic_names[attr - 1];
case AC_JACK_LINE_IN:
if (!check_location)
return "Line";
attr = snd_hda_get_input_pin_attr(def_conf);
if (!attr)
return "None";
if (attr == INPUT_PIN_ATTR_DOCK)
return "Dock Line";
return "Line";
case AC_JACK_AUX:
return "Aux";
case AC_JACK_CD:
return "CD";
case AC_JACK_SPDIF_IN:
return "SPDIF In";
case AC_JACK_DIG_OTHER_IN:
return "Digital In";
default:
return "Misc";
}
}
static int check_mic_location_need(struct hda_codec *codec,
const struct auto_pin_cfg *cfg,
int input)
{
unsigned int defc;
int i, attr, attr2;
defc = snd_hda_codec_get_pincfg(codec, cfg->inputs[input].pin);
attr = snd_hda_get_input_pin_attr(defc);
if (attr <= INPUT_PIN_ATTR_NORMAL)
return 1;
attr = 0;
for (i = 0; i < cfg->num_inputs; i++) {
defc = snd_hda_codec_get_pincfg(codec, cfg->inputs[i].pin);
attr2 = snd_hda_get_input_pin_attr(defc);
if (attr2 >= INPUT_PIN_ATTR_NORMAL) {
if (attr && attr != attr2)
return 1;
attr = attr2;
}
}
return 0;
}
const char *hda_get_autocfg_input_label(struct hda_codec *codec,
const struct auto_pin_cfg *cfg,
int input)
{
int type = cfg->inputs[input].type;
int has_multiple_pins = 0;
if ((input > 0 && cfg->inputs[input - 1].type == type) ||
(input < cfg->num_inputs - 1 && cfg->inputs[input + 1].type == type))
has_multiple_pins = 1;
if (has_multiple_pins && type == AUTO_PIN_MIC)
has_multiple_pins &= check_mic_location_need(codec, cfg, input);
return hda_get_input_pin_label(codec, cfg->inputs[input].pin,
has_multiple_pins);
}
static int find_idx_in_nid_list(hda_nid_t nid, const hda_nid_t *list, int nums)
{
int i;
for (i = 0; i < nums; i++)
if (list[i] == nid)
return i;
return -1;
}
static const char *check_output_sfx(hda_nid_t nid, const hda_nid_t *pins,
int num_pins, int *indexp)
{
static const char * const channel_sfx[] = {
" Front", " Surround", " CLFE", " Side"
};
int i;
i = find_idx_in_nid_list(nid, pins, num_pins);
if (i < 0)
return NULL;
if (num_pins == 1)
return "";
if (num_pins > ARRAY_SIZE(channel_sfx)) {
if (indexp)
*indexp = i;
return "";
}
return channel_sfx[i];
}
static int fill_audio_out_name(struct hda_codec *codec, hda_nid_t nid,
const struct auto_pin_cfg *cfg,
const char *name, char *label, int maxlen,
int *indexp)
{
unsigned int def_conf = snd_hda_codec_get_pincfg(codec, nid);
int attr = snd_hda_get_input_pin_attr(def_conf);
const char *pfx = "", *sfx = "";
if (!strcmp(name, "Line Out") && attr == INPUT_PIN_ATTR_INT)
name = "Speaker";
switch (attr) {
case INPUT_PIN_ATTR_DOCK:
pfx = "Dock ";
break;
case INPUT_PIN_ATTR_FRONT:
pfx = "Front ";
break;
}
if (cfg) {
sfx = check_output_sfx(nid, cfg->line_out_pins, cfg->line_outs,
indexp);
if (!sfx)
sfx = check_output_sfx(nid, cfg->speaker_pins, cfg->speaker_outs,
indexp);
if (!sfx) {
int idx = find_idx_in_nid_list(nid, cfg->hp_pins,
cfg->hp_outs);
if (idx >= 0)
*indexp = idx;
sfx = "";
}
}
snprintf(label, maxlen, "%s%s%s", pfx, name, sfx);
return 1;
}
int snd_hda_get_pin_label(struct hda_codec *codec, hda_nid_t nid,
const struct auto_pin_cfg *cfg,
char *label, int maxlen, int *indexp)
{
unsigned int def_conf = snd_hda_codec_get_pincfg(codec, nid);
const char *name = NULL;
int i;
if (indexp)
*indexp = 0;
if (get_defcfg_connect(def_conf) == AC_JACK_PORT_NONE)
return 0;
switch (get_defcfg_device(def_conf)) {
case AC_JACK_LINE_OUT:
return fill_audio_out_name(codec, nid, cfg, "Line Out",
label, maxlen, indexp);
case AC_JACK_SPEAKER:
return fill_audio_out_name(codec, nid, cfg, "Speaker",
label, maxlen, indexp);
case AC_JACK_HP_OUT:
return fill_audio_out_name(codec, nid, cfg, "Headphone",
label, maxlen, indexp);
case AC_JACK_SPDIF_OUT:
case AC_JACK_DIG_OTHER_OUT:
if (get_defcfg_location(def_conf) == AC_JACK_LOC_HDMI)
name = "HDMI";
else
name = "SPDIF";
if (cfg && indexp) {
i = find_idx_in_nid_list(nid, cfg->dig_out_pins,
cfg->dig_outs);
if (i >= 0)
*indexp = i;
}
break;
default:
if (cfg) {
for (i = 0; i < cfg->num_inputs; i++) {
if (cfg->inputs[i].pin != nid)
continue;
name = hda_get_autocfg_input_label(codec, cfg, i);
if (name)
break;
}
}
if (!name)
name = hda_get_input_pin_label(codec, nid, true);
break;
}
if (!name)
return 0;
strlcpy(label, name, maxlen);
return 1;
}
int snd_hda_gen_add_verbs(struct hda_gen_spec *spec,
const struct hda_verb *list)
{
const struct hda_verb **v;
v = snd_array_new(&spec->verbs);
if (!v)
return -ENOMEM;
*v = list;
return 0;
}
void snd_hda_gen_apply_verbs(struct hda_codec *codec)
{
struct hda_gen_spec *spec = codec->spec;
int i;
for (i = 0; i < spec->verbs.used; i++) {
struct hda_verb **v = snd_array_elem(&spec->verbs, i);
snd_hda_sequence_write(codec, *v);
}
}
void snd_hda_apply_pincfgs(struct hda_codec *codec,
const struct hda_pintbl *cfg)
{
for (; cfg->nid; cfg++)
snd_hda_codec_set_pincfg(codec, cfg->nid, cfg->val);
}
void snd_hda_apply_fixup(struct hda_codec *codec, int action)
{
struct hda_gen_spec *spec = codec->spec;
int id = spec->fixup_id;
#ifdef CONFIG_SND_DEBUG_VERBOSE
const char *modelname = spec->fixup_name;
#endif
int depth = 0;
if (!spec->fixup_list)
return;
while (id >= 0) {
const struct hda_fixup *fix = spec->fixup_list + id;
switch (fix->type) {
case HDA_FIXUP_PINS:
if (action != HDA_FIXUP_ACT_PRE_PROBE || !fix->v.pins)
break;
snd_printdd(KERN_INFO SFX
"%s: Apply pincfg for %s\n",
codec->chip_name, modelname);
snd_hda_apply_pincfgs(codec, fix->v.pins);
break;
case HDA_FIXUP_VERBS:
if (action != HDA_FIXUP_ACT_PROBE || !fix->v.verbs)
break;
snd_printdd(KERN_INFO SFX
"%s: Apply fix-verbs for %s\n",
codec->chip_name, modelname);
snd_hda_gen_add_verbs(codec->spec, fix->v.verbs);
break;
case HDA_FIXUP_FUNC:
if (!fix->v.func)
break;
snd_printdd(KERN_INFO SFX
"%s: Apply fix-func for %s\n",
codec->chip_name, modelname);
fix->v.func(codec, fix, action);
break;
default:
snd_printk(KERN_ERR SFX
"%s: Invalid fixup type %d\n",
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
void snd_hda_pick_fixup(struct hda_codec *codec,
const struct hda_model_fixup *models,
const struct snd_pci_quirk *quirk,
const struct hda_fixup *fixlist)
{
struct hda_gen_spec *spec = codec->spec;
const struct snd_pci_quirk *q;
int id = -1;
const char *name = NULL;
if (codec->modelname && !strcmp(codec->modelname, "nofixup")) {
spec->fixup_list = NULL;
spec->fixup_id = -1;
return;
}
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
if (id < 0 && quirk) {
q = snd_pci_quirk_lookup(codec->bus->pci, quirk);
if (q) {
id = q->value;
#ifdef CONFIG_SND_DEBUG_VERBOSE
name = q->name;
#endif
}
}
if (id < 0 && quirk) {
for (q = quirk; q->subvendor; q++) {
unsigned int vendorid =
q->subdevice | (q->subvendor << 16);
if (vendorid == codec->subsystem_id) {
id = q->value;
#ifdef CONFIG_SND_DEBUG_VERBOSE
name = q->name;
#endif
break;
}
}
}
spec->fixup_id = id;
if (id >= 0) {
spec->fixup_list = fixlist;
spec->fixup_name = name;
}
}
