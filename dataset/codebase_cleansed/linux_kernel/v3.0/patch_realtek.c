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
static int alc_mux_enum_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct alc_spec *spec = codec->spec;
const struct hda_input_mux *imux;
unsigned int adc_idx = snd_ctl_get_ioffidx(kcontrol, &ucontrol->id);
unsigned int mux_idx;
hda_nid_t nid = spec->capsrc_nids ?
spec->capsrc_nids[adc_idx] : spec->adc_nids[adc_idx];
unsigned int type;
mux_idx = adc_idx >= spec->num_mux_defs ? 0 : adc_idx;
imux = &spec->input_mux[mux_idx];
if (!imux->num_items && mux_idx > 0)
imux = &spec->input_mux[0];
type = get_wcaps_type(get_wcaps(codec, nid));
if (type == AC_WID_AUD_MIX) {
unsigned int *cur_val = &spec->cur_mux[adc_idx];
unsigned int i, idx;
idx = ucontrol->value.enumerated.item[0];
if (idx >= imux->num_items)
idx = imux->num_items - 1;
if (*cur_val == idx)
return 0;
for (i = 0; i < imux->num_items; i++) {
unsigned int v = (i == idx) ? 0 : HDA_AMP_MUTE;
snd_hda_codec_amp_stereo(codec, nid, HDA_INPUT,
imux->items[i].index,
HDA_AMP_MUTE, v);
}
*cur_val = idx;
return 1;
} else {
return snd_hda_input_mux_put(codec, imux, ucontrol, nid,
&spec->cur_mux[adc_idx]);
}
}
static int alc_ch_mode_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct alc_spec *spec = codec->spec;
return snd_hda_ch_mode_info(codec, uinfo, spec->channel_mode,
spec->num_channel_mode);
}
static int alc_ch_mode_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct alc_spec *spec = codec->spec;
return snd_hda_ch_mode_get(codec, ucontrol, spec->channel_mode,
spec->num_channel_mode,
spec->ext_channel_count);
}
static int alc_ch_mode_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct alc_spec *spec = codec->spec;
int err = snd_hda_ch_mode_put(codec, ucontrol, spec->channel_mode,
spec->num_channel_mode,
&spec->ext_channel_count);
if (err >= 0 && !spec->const_channel_count) {
spec->multiout.max_channels = spec->ext_channel_count;
if (spec->need_dac_fix)
spec->multiout.num_dacs = spec->multiout.max_channels / 2;
}
return err;
}
static int alc_pin_mode_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
unsigned int item_num = uinfo->value.enumerated.item;
unsigned char dir = (kcontrol->private_value >> 16) & 0xff;
uinfo->type = SNDRV_CTL_ELEM_TYPE_ENUMERATED;
uinfo->count = 1;
uinfo->value.enumerated.items = alc_pin_mode_n_items(dir);
if (item_num<alc_pin_mode_min(dir) || item_num>alc_pin_mode_max(dir))
item_num = alc_pin_mode_min(dir);
strcpy(uinfo->value.enumerated.name, alc_pin_mode_names[item_num]);
return 0;
}
static int alc_pin_mode_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
unsigned int i;
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
hda_nid_t nid = kcontrol->private_value & 0xffff;
unsigned char dir = (kcontrol->private_value >> 16) & 0xff;
long *valp = ucontrol->value.integer.value;
unsigned int pinctl = snd_hda_codec_read(codec, nid, 0,
AC_VERB_GET_PIN_WIDGET_CONTROL,
0x00);
i = alc_pin_mode_min(dir);
while (i <= alc_pin_mode_max(dir) && alc_pin_mode_values[i] != pinctl)
i++;
*valp = i <= alc_pin_mode_max(dir) ? i: alc_pin_mode_min(dir);
return 0;
}
static int alc_pin_mode_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
signed int change;
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
hda_nid_t nid = kcontrol->private_value & 0xffff;
unsigned char dir = (kcontrol->private_value >> 16) & 0xff;
long val = *ucontrol->value.integer.value;
unsigned int pinctl = snd_hda_codec_read(codec, nid, 0,
AC_VERB_GET_PIN_WIDGET_CONTROL,
0x00);
if (val < alc_pin_mode_min(dir) || val > alc_pin_mode_max(dir))
val = alc_pin_mode_min(dir);
change = pinctl != alc_pin_mode_values[val];
if (change) {
snd_hda_codec_write_cache(codec, nid, 0,
AC_VERB_SET_PIN_WIDGET_CONTROL,
alc_pin_mode_values[val]);
if (val <= 2) {
snd_hda_codec_amp_stereo(codec, nid, HDA_OUTPUT, 0,
HDA_AMP_MUTE, HDA_AMP_MUTE);
snd_hda_codec_amp_stereo(codec, nid, HDA_INPUT, 0,
HDA_AMP_MUTE, 0);
} else {
snd_hda_codec_amp_stereo(codec, nid, HDA_INPUT, 0,
HDA_AMP_MUTE, HDA_AMP_MUTE);
snd_hda_codec_amp_stereo(codec, nid, HDA_OUTPUT, 0,
HDA_AMP_MUTE, 0);
}
}
return change;
}
static int alc_gpio_data_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
hda_nid_t nid = kcontrol->private_value & 0xffff;
unsigned char mask = (kcontrol->private_value >> 16) & 0xff;
long *valp = ucontrol->value.integer.value;
unsigned int val = snd_hda_codec_read(codec, nid, 0,
AC_VERB_GET_GPIO_DATA, 0x00);
*valp = (val & mask) != 0;
return 0;
}
static int alc_gpio_data_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
signed int change;
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
hda_nid_t nid = kcontrol->private_value & 0xffff;
unsigned char mask = (kcontrol->private_value >> 16) & 0xff;
long val = *ucontrol->value.integer.value;
unsigned int gpio_data = snd_hda_codec_read(codec, nid, 0,
AC_VERB_GET_GPIO_DATA,
0x00);
change = (val == 0 ? 0 : mask) != (gpio_data & mask);
if (val == 0)
gpio_data &= ~mask;
else
gpio_data |= mask;
snd_hda_codec_write_cache(codec, nid, 0,
AC_VERB_SET_GPIO_DATA, gpio_data);
return change;
}
static int alc_spdif_ctrl_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
hda_nid_t nid = kcontrol->private_value & 0xffff;
unsigned char mask = (kcontrol->private_value >> 16) & 0xff;
long *valp = ucontrol->value.integer.value;
unsigned int val = snd_hda_codec_read(codec, nid, 0,
AC_VERB_GET_DIGI_CONVERT_1, 0x00);
*valp = (val & mask) != 0;
return 0;
}
static int alc_spdif_ctrl_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
signed int change;
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
hda_nid_t nid = kcontrol->private_value & 0xffff;
unsigned char mask = (kcontrol->private_value >> 16) & 0xff;
long val = *ucontrol->value.integer.value;
unsigned int ctrl_data = snd_hda_codec_read(codec, nid, 0,
AC_VERB_GET_DIGI_CONVERT_1,
0x00);
change = (val == 0 ? 0 : mask) != (ctrl_data & mask);
if (val==0)
ctrl_data &= ~mask;
else
ctrl_data |= mask;
snd_hda_codec_write_cache(codec, nid, 0, AC_VERB_SET_DIGI_CONVERT_1,
ctrl_data);
return change;
}
static int alc_eapd_ctrl_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
hda_nid_t nid = kcontrol->private_value & 0xffff;
unsigned char mask = (kcontrol->private_value >> 16) & 0xff;
long *valp = ucontrol->value.integer.value;
unsigned int val = snd_hda_codec_read(codec, nid, 0,
AC_VERB_GET_EAPD_BTLENABLE, 0x00);
*valp = (val & mask) != 0;
return 0;
}
static int alc_eapd_ctrl_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
int change;
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
hda_nid_t nid = kcontrol->private_value & 0xffff;
unsigned char mask = (kcontrol->private_value >> 16) & 0xff;
long val = *ucontrol->value.integer.value;
unsigned int ctrl_data = snd_hda_codec_read(codec, nid, 0,
AC_VERB_GET_EAPD_BTLENABLE,
0x00);
change = (!val ? 0 : mask) != (ctrl_data & mask);
if (!val)
ctrl_data &= ~mask;
else
ctrl_data |= mask;
snd_hda_codec_write_cache(codec, nid, 0, AC_VERB_SET_EAPD_BTLENABLE,
ctrl_data);
return change;
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
static void alc_fixup_autocfg_pin_nums(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
struct auto_pin_cfg *cfg = &spec->autocfg;
if (!cfg->line_outs) {
while (cfg->line_outs < AUTO_CFG_MAX_OUTS &&
cfg->line_out_pins[cfg->line_outs])
cfg->line_outs++;
}
if (!cfg->speaker_outs) {
while (cfg->speaker_outs < AUTO_CFG_MAX_OUTS &&
cfg->speaker_pins[cfg->speaker_outs])
cfg->speaker_outs++;
}
if (!cfg->hp_outs) {
while (cfg->hp_outs < AUTO_CFG_MAX_OUTS &&
cfg->hp_pins[cfg->hp_outs])
cfg->hp_outs++;
}
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
static void setup_preset(struct hda_codec *codec,
const struct alc_config_preset *preset)
{
struct alc_spec *spec = codec->spec;
int i;
for (i = 0; i < ARRAY_SIZE(preset->mixers) && preset->mixers[i]; i++)
add_mixer(spec, preset->mixers[i]);
spec->cap_mixer = preset->cap_mixer;
for (i = 0; i < ARRAY_SIZE(preset->init_verbs) && preset->init_verbs[i];
i++)
add_verb(spec, preset->init_verbs[i]);
spec->channel_mode = preset->channel_mode;
spec->num_channel_mode = preset->num_channel_mode;
spec->need_dac_fix = preset->need_dac_fix;
spec->const_channel_count = preset->const_channel_count;
if (preset->const_channel_count)
spec->multiout.max_channels = preset->const_channel_count;
else
spec->multiout.max_channels = spec->channel_mode[0].channels;
spec->ext_channel_count = spec->channel_mode[0].channels;
spec->multiout.num_dacs = preset->num_dacs;
spec->multiout.dac_nids = preset->dac_nids;
spec->multiout.dig_out_nid = preset->dig_out_nid;
spec->multiout.slave_dig_outs = preset->slave_dig_outs;
spec->multiout.hp_nid = preset->hp_nid;
spec->num_mux_defs = preset->num_mux_defs;
if (!spec->num_mux_defs)
spec->num_mux_defs = 1;
spec->input_mux = preset->input_mux;
spec->num_adc_nids = preset->num_adc_nids;
spec->adc_nids = preset->adc_nids;
spec->capsrc_nids = preset->capsrc_nids;
spec->dig_in_nid = preset->dig_in_nid;
spec->unsol_event = preset->unsol_event;
spec->init_hook = preset->init_hook;
#ifdef CONFIG_SND_HDA_POWER_SAVE
spec->power_hook = preset->power_hook;
spec->loopback.amplist = preset->loopbacks;
#endif
if (preset->setup)
preset->setup(codec);
alc_fixup_autocfg_pin_nums(codec);
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
unsigned int mic_nid = spec->ext_mic.pin;
unsigned int dock_nid = spec->dock_mic.pin;
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
static int detect_jacks(struct hda_codec *codec, int num_pins, hda_nid_t *pins)
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
static void update_speakers(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
int on;
do_automute(codec, ARRAY_SIZE(spec->autocfg.hp_pins),
spec->autocfg.hp_pins, spec->master_mute, true);
if (!spec->automute)
on = 0;
else
on = spec->jack_present | spec->line_jack_present;
on |= spec->master_mute;
do_automute(codec, ARRAY_SIZE(spec->autocfg.speaker_pins),
spec->autocfg.speaker_pins, on, false);
if (spec->autocfg.line_out_pins[0] == spec->autocfg.hp_pins[0] ||
spec->autocfg.line_out_pins[0] == spec->autocfg.speaker_pins[0])
return;
if (!spec->automute_lines || !spec->automute)
on = 0;
else
on = spec->jack_present;
on |= spec->master_mute;
do_automute(codec, ARRAY_SIZE(spec->autocfg.line_out_pins),
spec->autocfg.line_out_pins, on, false);
}
static void alc_hp_automute(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
if (!spec->automute)
return;
spec->jack_present =
detect_jacks(codec, ARRAY_SIZE(spec->autocfg.hp_pins),
spec->autocfg.hp_pins);
update_speakers(codec);
}
static void alc_line_automute(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
if (!spec->automute || !spec->detect_line)
return;
spec->line_jack_present =
detect_jacks(codec, ARRAY_SIZE(spec->autocfg.line_out_pins),
spec->autocfg.line_out_pins);
update_speakers(codec);
}
static int get_connection_index(struct hda_codec *codec, hda_nid_t mux,
hda_nid_t nid)
{
hda_nid_t conn[HDA_MAX_NUM_INPUTS];
int i, nums;
nums = snd_hda_get_connections(codec, mux, conn, ARRAY_SIZE(conn));
for (i = 0; i < nums; i++)
if (conn[i] == nid)
return i;
return -1;
}
static void alc_dual_mic_adc_auto_switch(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
unsigned int present;
hda_nid_t new_adc;
present = snd_hda_jack_detect(codec, spec->ext_mic.pin);
if (present)
spec->cur_adc_idx = 1;
else
spec->cur_adc_idx = 0;
new_adc = spec->adc_nids[spec->cur_adc_idx];
if (spec->cur_adc && spec->cur_adc != new_adc) {
__snd_hda_codec_cleanup_stream(codec, spec->cur_adc, 1);
spec->cur_adc = new_adc;
snd_hda_codec_setup_stream(codec, new_adc,
spec->cur_adc_stream_tag, 0,
spec->cur_adc_format);
}
}
static void alc_mic_automute(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
struct alc_mic_route *dead1, *dead2, *alive;
unsigned int present, type;
hda_nid_t cap_nid;
if (!spec->auto_mic)
return;
if (!spec->int_mic.pin || !spec->ext_mic.pin)
return;
if (snd_BUG_ON(!spec->adc_nids))
return;
if (spec->dual_adc_switch) {
alc_dual_mic_adc_auto_switch(codec);
return;
}
cap_nid = spec->capsrc_nids ? spec->capsrc_nids[0] : spec->adc_nids[0];
alive = &spec->int_mic;
dead1 = &spec->ext_mic;
dead2 = &spec->dock_mic;
present = snd_hda_jack_detect(codec, spec->ext_mic.pin);
if (present) {
alive = &spec->ext_mic;
dead1 = &spec->int_mic;
dead2 = &spec->dock_mic;
}
if (!present && spec->dock_mic.pin > 0) {
present = snd_hda_jack_detect(codec, spec->dock_mic.pin);
if (present) {
alive = &spec->dock_mic;
dead1 = &spec->int_mic;
dead2 = &spec->ext_mic;
}
snd_hda_input_jack_report(codec, spec->dock_mic.pin);
}
type = get_wcaps_type(get_wcaps(codec, cap_nid));
if (type == AC_WID_AUD_MIX) {
snd_hda_codec_amp_stereo(codec, cap_nid, HDA_INPUT,
alive->mux_idx,
HDA_AMP_MUTE, 0);
if (dead1->pin > 0)
snd_hda_codec_amp_stereo(codec, cap_nid, HDA_INPUT,
dead1->mux_idx,
HDA_AMP_MUTE, HDA_AMP_MUTE);
if (dead2->pin > 0)
snd_hda_codec_amp_stereo(codec, cap_nid, HDA_INPUT,
dead2->mux_idx,
HDA_AMP_MUTE, HDA_AMP_MUTE);
} else {
snd_hda_codec_write_cache(codec, cap_nid, 0,
AC_VERB_SET_CONNECT_SEL,
alive->mux_idx);
}
snd_hda_input_jack_report(codec, spec->ext_mic.pin);
}
static void alc_sku_unsol_event(struct hda_codec *codec, unsigned int res)
{
if (codec->vendor_id == 0x10ec0880)
res >>= 28;
else
res >>= 26;
switch (res) {
case ALC880_HP_EVENT:
alc_hp_automute(codec);
break;
case ALC880_FRONT_EVENT:
alc_line_automute(codec);
break;
case ALC880_MIC_EVENT:
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
switch (codec->vendor_id) {
case 0x10ec0260:
set_eapd(codec, 0x0f, on);
set_eapd(codec, 0x10, on);
break;
case 0x10ec0262:
case 0x10ec0267:
case 0x10ec0268:
case 0x10ec0269:
case 0x10ec0270:
case 0x10ec0272:
case 0x10ec0660:
case 0x10ec0662:
case 0x10ec0663:
case 0x10ec0665:
case 0x10ec0862:
case 0x10ec0889:
case 0x10ec0892:
set_eapd(codec, 0x14, on);
set_eapd(codec, 0x15, on);
break;
}
}
static void alc_eapd_shutup(struct hda_codec *codec)
{
alc_auto_setup_eapd(codec, false);
msleep(200);
}
static void alc_auto_init_amp(struct hda_codec *codec, int type)
{
unsigned int tmp;
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
alc_auto_setup_eapd(codec, true);
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
if (spec->automute_hp_lo) {
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
unsigned int val;
if (!spec->automute)
val = 0;
else if (!spec->automute_lines)
val = 1;
else
val = 2;
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
if (!spec->automute)
return 0;
spec->automute = 0;
break;
case 1:
if (spec->automute && !spec->automute_lines)
return 0;
spec->automute = 1;
spec->automute_lines = 0;
break;
case 2:
if (!spec->automute_hp_lo)
return -EINVAL;
if (spec->automute && spec->automute_lines)
return 0;
spec->automute = 1;
spec->automute_lines = 1;
break;
default:
return -EINVAL;
}
update_speakers(codec);
return 1;
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
static void alc_init_auto_hp(struct hda_codec *codec)
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
if (present == 3)
spec->automute_hp_lo = 1;
if (!cfg->speaker_pins[0]) {
memcpy(cfg->speaker_pins, cfg->line_out_pins,
sizeof(cfg->speaker_pins));
cfg->speaker_outs = cfg->line_outs;
}
if (!cfg->hp_pins[0]) {
memcpy(cfg->hp_pins, cfg->line_out_pins,
sizeof(cfg->hp_pins));
cfg->hp_outs = cfg->line_outs;
}
for (i = 0; i < cfg->hp_outs; i++) {
hda_nid_t nid = cfg->hp_pins[i];
if (!is_jack_detectable(codec, nid))
continue;
snd_printdd("realtek: Enable HP auto-muting on NID 0x%x\n",
nid);
snd_hda_codec_write_cache(codec, nid, 0,
AC_VERB_SET_UNSOLICITED_ENABLE,
AC_USRSP_EN | ALC880_HP_EVENT);
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_PIN;
}
if (spec->automute && cfg->line_out_pins[0] &&
cfg->line_out_pins[0] != cfg->hp_pins[0] &&
cfg->line_out_pins[0] != cfg->speaker_pins[0]) {
for (i = 0; i < cfg->line_outs; i++) {
hda_nid_t nid = cfg->line_out_pins[i];
if (!is_jack_detectable(codec, nid))
continue;
snd_printdd("realtek: Enable Line-Out auto-muting "
"on NID 0x%x\n", nid);
snd_hda_codec_write_cache(codec, nid, 0,
AC_VERB_SET_UNSOLICITED_ENABLE,
AC_USRSP_EN | ALC880_FRONT_EVENT);
spec->detect_line = 1;
}
spec->automute_lines = spec->detect_line;
}
if (spec->automute) {
alc_add_automute_mode_enum(codec);
spec->unsol_event = alc_sku_unsol_event;
}
}
static void alc_init_auto_mic(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
struct auto_pin_cfg *cfg = &spec->autocfg;
hda_nid_t fixed, ext, dock;
int i;
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
snd_printdd("realtek: Enable auto-mic switch on NID 0x%x/0x%x/0x%x\n",
ext, fixed, dock);
spec->ext_mic.pin = ext;
spec->dock_mic.pin = dock;
spec->int_mic.pin = fixed;
spec->ext_mic.mux_idx = MUX_IDX_UNDEF;
spec->dock_mic.mux_idx = MUX_IDX_UNDEF;
spec->int_mic.mux_idx = MUX_IDX_UNDEF;
spec->auto_mic = 1;
snd_hda_codec_write_cache(codec, spec->ext_mic.pin, 0,
AC_VERB_SET_UNSOLICITED_ENABLE,
AC_USRSP_EN | ALC880_MIC_EVENT);
spec->unsol_event = alc_sku_unsol_event;
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
if (!spec->autocfg.hp_pins[0]) {
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
for (i = 0; i < spec->autocfg.line_outs; i++)
if (spec->autocfg.line_out_pins[i] == nid)
return 1;
spec->autocfg.hp_pins[0] = nid;
}
return 1;
}
static void alc_ssid_check(struct hda_codec *codec,
hda_nid_t porta, hda_nid_t porte,
hda_nid_t portd, hda_nid_t porti)
{
if (!alc_subsystem_id(codec, porta, porte, portd, porti)) {
struct alc_spec *spec = codec->spec;
snd_printd("realtek: "
"Enable default setup for auto mode as fallback\n");
spec->init_amp = ALC_INIT_DEFAULT;
}
alc_init_auto_hp(codec);
alc_init_auto_mic(codec);
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
break;;
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
static void alc_auto_init_digital(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
int i;
hda_nid_t pin;
for (i = 0; i < spec->autocfg.dig_outs; i++) {
pin = spec->autocfg.dig_out_pins[i];
if (pin) {
snd_hda_codec_write(codec, pin, 0,
AC_VERB_SET_PIN_WIDGET_CONTROL,
PIN_OUT);
}
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
int i, err;
hda_nid_t dig_nid;
for (i = 0; i < spec->autocfg.dig_outs; i++) {
err = snd_hda_get_connections(codec,
spec->autocfg.dig_out_pins[i],
&dig_nid, 1);
if (err < 0)
continue;
if (!i) {
spec->multiout.dig_out_nid = dig_nid;
spec->dig_out_type = spec->autocfg.dig_out_type[0];
} else {
spec->multiout.slave_dig_outs = spec->slave_dig_outs;
if (i >= ARRAY_SIZE(spec->slave_dig_outs) - 1)
break;
spec->slave_dig_outs[i - 1] = dig_nid;
}
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
static void alc889_automute_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x15;
spec->autocfg.speaker_pins[0] = 0x14;
spec->autocfg.speaker_pins[1] = 0x16;
spec->autocfg.speaker_pins[2] = 0x17;
spec->autocfg.speaker_pins[3] = 0x19;
spec->autocfg.speaker_pins[4] = 0x1a;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_AMP;
}
static void alc889_intel_init_hook(struct hda_codec *codec)
{
alc889_coef_init(codec);
alc_hp_automute(codec);
}
static void alc888_fujitsu_xa3530_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x17;
spec->autocfg.hp_pins[1] = 0x1b;
spec->autocfg.speaker_pins[0] = 0x14;
spec->autocfg.speaker_pins[1] = 0x15;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_AMP;
}
static void alc888_acer_aspire_4930g_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x15;
spec->autocfg.speaker_pins[0] = 0x14;
spec->autocfg.speaker_pins[1] = 0x16;
spec->autocfg.speaker_pins[2] = 0x17;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_AMP;
}
static void alc888_acer_aspire_6530g_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x15;
spec->autocfg.speaker_pins[0] = 0x14;
spec->autocfg.speaker_pins[1] = 0x16;
spec->autocfg.speaker_pins[2] = 0x17;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_AMP;
}
static void alc888_acer_aspire_7730g_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x15;
spec->autocfg.speaker_pins[0] = 0x14;
spec->autocfg.speaker_pins[1] = 0x16;
spec->autocfg.speaker_pins[2] = 0x17;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_AMP;
}
static void alc889_acer_aspire_8930g_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x15;
spec->autocfg.speaker_pins[0] = 0x14;
spec->autocfg.speaker_pins[1] = 0x16;
spec->autocfg.speaker_pins[2] = 0x1b;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_AMP;
}
static int alc_cap_vol_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct alc_spec *spec = codec->spec;
int err;
mutex_lock(&codec->control_mutex);
kcontrol->private_value = HDA_COMPOSE_AMP_VAL(spec->adc_nids[0], 3, 0,
HDA_INPUT);
err = snd_hda_mixer_amp_volume_info(kcontrol, uinfo);
mutex_unlock(&codec->control_mutex);
return err;
}
static int alc_cap_vol_tlv(struct snd_kcontrol *kcontrol, int op_flag,
unsigned int size, unsigned int __user *tlv)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct alc_spec *spec = codec->spec;
int err;
mutex_lock(&codec->control_mutex);
kcontrol->private_value = HDA_COMPOSE_AMP_VAL(spec->adc_nids[0], 3, 0,
HDA_INPUT);
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
if (check_adc_switch && spec->dual_adc_switch) {
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
const hda_nid_t *nids = spec->capsrc_nids;
if (!nids)
nids = spec->adc_nids;
err = snd_hda_add_nid(codec, kctl, i, nids[i]);
if (err < 0)
return err;
}
}
if (spec->cap_mixer) {
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
static void alc88x_simple_mic_automute(struct hda_codec *codec)
{
unsigned int present;
unsigned char bits;
present = snd_hda_jack_detect(codec, 0x18);
bits = present ? HDA_AMP_MUTE : 0;
snd_hda_codec_amp_stereo(codec, 0x0b, HDA_INPUT, 1, HDA_AMP_MUTE, bits);
}
static void alc880_uniwill_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x14;
spec->autocfg.speaker_pins[0] = 0x15;
spec->autocfg.speaker_pins[0] = 0x16;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_AMP;
}
static void alc880_uniwill_init_hook(struct hda_codec *codec)
{
alc_hp_automute(codec);
alc88x_simple_mic_automute(codec);
}
static void alc880_uniwill_unsol_event(struct hda_codec *codec,
unsigned int res)
{
switch (res >> 28) {
case ALC880_MIC_EVENT:
alc88x_simple_mic_automute(codec);
break;
default:
alc_sku_unsol_event(codec, res);
break;
}
}
static void alc880_uniwill_p53_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x14;
spec->autocfg.speaker_pins[0] = 0x15;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_AMP;
}
static void alc880_uniwill_p53_dcvol_automute(struct hda_codec *codec)
{
unsigned int present;
present = snd_hda_codec_read(codec, 0x21, 0,
AC_VERB_GET_VOLUME_KNOB_CONTROL, 0);
present &= HDA_AMP_VOLMASK;
snd_hda_codec_amp_stereo(codec, 0x0c, HDA_OUTPUT, 0,
HDA_AMP_VOLMASK, present);
snd_hda_codec_amp_stereo(codec, 0x0d, HDA_OUTPUT, 0,
HDA_AMP_VOLMASK, present);
}
static void alc880_uniwill_p53_unsol_event(struct hda_codec *codec,
unsigned int res)
{
if ((res >> 28) == ALC880_DCVOL_EVENT)
alc880_uniwill_p53_dcvol_automute(codec);
else
alc_sku_unsol_event(codec, res);
}
static void alc880_lg_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x1b;
spec->autocfg.speaker_pins[0] = 0x17;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_AMP;
}
static void alc880_lg_lw_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x1b;
spec->autocfg.speaker_pins[0] = 0x14;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_AMP;
}
static void alc880_medion_rim_automute(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
alc_hp_automute(codec);
if (spec->jack_present)
snd_hda_codec_write(codec, 0x01, 0, AC_VERB_SET_GPIO_DATA, 0);
else
snd_hda_codec_write(codec, 0x01, 0, AC_VERB_SET_GPIO_DATA, 2);
}
static void alc880_medion_rim_unsol_event(struct hda_codec *codec,
unsigned int res)
{
if ((res >> 28) == ALC880_HP_EVENT)
alc880_medion_rim_automute(codec);
}
static void alc880_medion_rim_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x14;
spec->autocfg.speaker_pins[0] = 0x1b;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_AMP;
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
static int alc880_playback_pcm_open(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
struct snd_pcm_substream *substream)
{
struct alc_spec *spec = codec->spec;
return snd_hda_multi_out_analog_open(codec, &spec->multiout, substream,
hinfo);
}
static int alc880_playback_pcm_prepare(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
unsigned int stream_tag,
unsigned int format,
struct snd_pcm_substream *substream)
{
struct alc_spec *spec = codec->spec;
return snd_hda_multi_out_analog_prepare(codec, &spec->multiout,
stream_tag, format, substream);
}
static int alc880_playback_pcm_cleanup(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
struct snd_pcm_substream *substream)
{
struct alc_spec *spec = codec->spec;
return snd_hda_multi_out_analog_cleanup(codec, &spec->multiout);
}
static int alc880_dig_playback_pcm_open(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
struct snd_pcm_substream *substream)
{
struct alc_spec *spec = codec->spec;
return snd_hda_multi_out_dig_open(codec, &spec->multiout);
}
static int alc880_dig_playback_pcm_prepare(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
unsigned int stream_tag,
unsigned int format,
struct snd_pcm_substream *substream)
{
struct alc_spec *spec = codec->spec;
return snd_hda_multi_out_dig_prepare(codec, &spec->multiout,
stream_tag, format, substream);
}
static int alc880_dig_playback_pcm_cleanup(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
struct snd_pcm_substream *substream)
{
struct alc_spec *spec = codec->spec;
return snd_hda_multi_out_dig_cleanup(codec, &spec->multiout);
}
static int alc880_dig_playback_pcm_close(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
struct snd_pcm_substream *substream)
{
struct alc_spec *spec = codec->spec;
return snd_hda_multi_out_dig_close(codec, &spec->multiout);
}
static int alc880_alt_capture_pcm_prepare(struct hda_pcm_stream *hinfo,
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
static int alc880_alt_capture_pcm_cleanup(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
struct snd_pcm_substream *substream)
{
struct alc_spec *spec = codec->spec;
snd_hda_codec_cleanup_stream(codec,
spec->adc_nids[substream->number + 1]);
return 0;
}
static int dualmic_capture_pcm_prepare(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
unsigned int stream_tag,
unsigned int format,
struct snd_pcm_substream *substream)
{
struct alc_spec *spec = codec->spec;
spec->cur_adc = spec->adc_nids[spec->cur_adc_idx];
spec->cur_adc_stream_tag = stream_tag;
spec->cur_adc_format = format;
snd_hda_codec_setup_stream(codec, spec->cur_adc, stream_tag, 0, format);
return 0;
}
static int dualmic_capture_pcm_cleanup(struct hda_pcm_stream *hinfo,
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
int i;
codec->num_pcms = 1;
codec->pcm_info = info;
if (spec->no_analog)
goto skip_analog;
snprintf(spec->stream_name_analog, sizeof(spec->stream_name_analog),
"%s Analog", codec->chip_name);
info->name = spec->stream_name_analog;
if (spec->stream_analog_playback) {
if (snd_BUG_ON(!spec->multiout.dac_nids))
return -EINVAL;
info->stream[SNDRV_PCM_STREAM_PLAYBACK] = *(spec->stream_analog_playback);
info->stream[SNDRV_PCM_STREAM_PLAYBACK].nid = spec->multiout.dac_nids[0];
}
if (spec->stream_analog_capture) {
if (snd_BUG_ON(!spec->adc_nids))
return -EINVAL;
info->stream[SNDRV_PCM_STREAM_CAPTURE] = *(spec->stream_analog_capture);
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
if (spec->multiout.dig_out_nid &&
spec->stream_digital_playback) {
info->stream[SNDRV_PCM_STREAM_PLAYBACK] = *(spec->stream_digital_playback);
info->stream[SNDRV_PCM_STREAM_PLAYBACK].nid = spec->multiout.dig_out_nid;
}
if (spec->dig_in_nid &&
spec->stream_digital_capture) {
info->stream[SNDRV_PCM_STREAM_CAPTURE] = *(spec->stream_digital_capture);
info->stream[SNDRV_PCM_STREAM_CAPTURE].nid = spec->dig_in_nid;
}
codec->spdif_status_reset = 1;
}
if (spec->no_analog)
return 0;
if ((spec->alt_dac_nid && spec->stream_analog_alt_playback) ||
(spec->num_adc_nids > 1 && spec->stream_analog_alt_capture)) {
codec->num_pcms = 3;
info = spec->pcm_rec + 2;
info->name = spec->stream_name_analog;
if (spec->alt_dac_nid) {
info->stream[SNDRV_PCM_STREAM_PLAYBACK] =
*spec->stream_analog_alt_playback;
info->stream[SNDRV_PCM_STREAM_PLAYBACK].nid =
spec->alt_dac_nid;
} else {
info->stream[SNDRV_PCM_STREAM_PLAYBACK] =
alc_pcm_null_stream;
info->stream[SNDRV_PCM_STREAM_PLAYBACK].nid = 0;
}
if (spec->num_adc_nids > 1 && spec->stream_analog_alt_capture) {
info->stream[SNDRV_PCM_STREAM_CAPTURE] =
*spec->stream_analog_alt_capture;
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
static void alc_free(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
if (!spec)
return;
alc_shutup(codec);
snd_hda_input_jack_free(codec);
alc_free_kctls(codec);
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
static int alc_test_pin_ctl_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
static const char * const texts[] = {
"N/A", "Line Out", "HP Out",
"In Hi-Z", "In 50%", "In Grd", "In 80%", "In 100%"
};
uinfo->type = SNDRV_CTL_ELEM_TYPE_ENUMERATED;
uinfo->count = 1;
uinfo->value.enumerated.items = 8;
if (uinfo->value.enumerated.item >= 8)
uinfo->value.enumerated.item = 7;
strcpy(uinfo->value.enumerated.name, texts[uinfo->value.enumerated.item]);
return 0;
}
static int alc_test_pin_ctl_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
hda_nid_t nid = (hda_nid_t)kcontrol->private_value;
unsigned int pin_ctl, item = 0;
pin_ctl = snd_hda_codec_read(codec, nid, 0,
AC_VERB_GET_PIN_WIDGET_CONTROL, 0);
if (pin_ctl & AC_PINCTL_OUT_EN) {
if (pin_ctl & AC_PINCTL_HP_EN)
item = 2;
else
item = 1;
} else if (pin_ctl & AC_PINCTL_IN_EN) {
switch (pin_ctl & AC_PINCTL_VREFEN) {
case AC_PINCTL_VREF_HIZ: item = 3; break;
case AC_PINCTL_VREF_50: item = 4; break;
case AC_PINCTL_VREF_GRD: item = 5; break;
case AC_PINCTL_VREF_80: item = 6; break;
case AC_PINCTL_VREF_100: item = 7; break;
}
}
ucontrol->value.enumerated.item[0] = item;
return 0;
}
static int alc_test_pin_ctl_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
hda_nid_t nid = (hda_nid_t)kcontrol->private_value;
static const unsigned int ctls[] = {
0, AC_PINCTL_OUT_EN, AC_PINCTL_OUT_EN | AC_PINCTL_HP_EN,
AC_PINCTL_IN_EN | AC_PINCTL_VREF_HIZ,
AC_PINCTL_IN_EN | AC_PINCTL_VREF_50,
AC_PINCTL_IN_EN | AC_PINCTL_VREF_GRD,
AC_PINCTL_IN_EN | AC_PINCTL_VREF_80,
AC_PINCTL_IN_EN | AC_PINCTL_VREF_100,
};
unsigned int old_ctl, new_ctl;
old_ctl = snd_hda_codec_read(codec, nid, 0,
AC_VERB_GET_PIN_WIDGET_CONTROL, 0);
new_ctl = ctls[ucontrol->value.enumerated.item[0]];
if (old_ctl != new_ctl) {
int val;
snd_hda_codec_write_cache(codec, nid, 0,
AC_VERB_SET_PIN_WIDGET_CONTROL,
new_ctl);
val = ucontrol->value.enumerated.item[0] >= 3 ?
HDA_AMP_MUTE : 0;
snd_hda_codec_amp_stereo(codec, nid, HDA_OUTPUT, 0,
HDA_AMP_MUTE, val);
return 1;
}
return 0;
}
static int alc_test_pin_src_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
static const char * const texts[] = {
"Front", "Surround", "CLFE", "Side"
};
uinfo->type = SNDRV_CTL_ELEM_TYPE_ENUMERATED;
uinfo->count = 1;
uinfo->value.enumerated.items = 4;
if (uinfo->value.enumerated.item >= 4)
uinfo->value.enumerated.item = 3;
strcpy(uinfo->value.enumerated.name, texts[uinfo->value.enumerated.item]);
return 0;
}
static int alc_test_pin_src_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
hda_nid_t nid = (hda_nid_t)kcontrol->private_value;
unsigned int sel;
sel = snd_hda_codec_read(codec, nid, 0, AC_VERB_GET_CONNECT_SEL, 0);
ucontrol->value.enumerated.item[0] = sel & 3;
return 0;
}
static int alc_test_pin_src_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
hda_nid_t nid = (hda_nid_t)kcontrol->private_value;
unsigned int sel;
sel = snd_hda_codec_read(codec, nid, 0, AC_VERB_GET_CONNECT_SEL, 0) & 3;
if (ucontrol->value.enumerated.item[0] != sel) {
sel = ucontrol->value.enumerated.item[0] & 3;
snd_hda_codec_write_cache(codec, nid, 0,
AC_VERB_SET_CONNECT_SEL, sel);
return 1;
}
return 0;
}
static struct snd_kcontrol_new *alc_kcontrol_new(struct alc_spec *spec)
{
snd_array_init(&spec->kctls, sizeof(struct snd_kcontrol_new), 32);
return snd_array_new(&spec->kctls);
}
static int add_control(struct alc_spec *spec, int type, const char *name,
int cidx, unsigned long val)
{
struct snd_kcontrol_new *knew;
knew = alc_kcontrol_new(spec);
if (!knew)
return -ENOMEM;
*knew = alc880_control_templates[type];
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
static int alc880_auto_fill_dac_nids(struct alc_spec *spec,
const struct auto_pin_cfg *cfg)
{
hda_nid_t nid;
int assigned[4];
int i, j;
memset(assigned, 0, sizeof(assigned));
spec->multiout.dac_nids = spec->private_dac_nids;
for (i = 0; i < cfg->line_outs; i++) {
nid = cfg->line_out_pins[i];
if (alc880_is_fixed_pin(nid)) {
int idx = alc880_fixed_pin_idx(nid);
spec->private_dac_nids[i] = alc880_idx_to_dac(idx);
assigned[idx] = 1;
}
}
for (i = 0; i < cfg->line_outs; i++) {
nid = cfg->line_out_pins[i];
if (alc880_is_fixed_pin(nid))
continue;
for (j = 0; j < cfg->line_outs; j++) {
if (!assigned[j]) {
spec->private_dac_nids[i] =
alc880_idx_to_dac(j);
assigned[j] = 1;
break;
}
}
}
spec->multiout.num_dacs = cfg->line_outs;
return 0;
}
static const char *alc_get_line_out_pfx(struct alc_spec *spec,
bool can_be_master)
{
struct auto_pin_cfg *cfg = &spec->autocfg;
if (cfg->line_outs == 1 && !spec->multi_ios &&
!cfg->hp_outs && !cfg->speaker_outs && can_be_master)
return "Master";
switch (cfg->line_out_type) {
case AUTO_PIN_SPEAKER_OUT:
if (cfg->line_outs == 1)
return "Speaker";
break;
case AUTO_PIN_HP_OUT:
return "Headphone";
default:
if (cfg->line_outs == 1 && !spec->multi_ios)
return "PCM";
break;
}
return NULL;
}
static int alc880_auto_create_multi_out_ctls(struct alc_spec *spec,
const struct auto_pin_cfg *cfg)
{
static const char * const chname[4] = {
"Front", "Surround", NULL , "Side"
};
const char *pfx = alc_get_line_out_pfx(spec, false);
hda_nid_t nid;
int i, err, noutputs;
noutputs = cfg->line_outs;
if (spec->multi_ios > 0)
noutputs += spec->multi_ios;
for (i = 0; i < noutputs; i++) {
if (!spec->multiout.dac_nids[i])
continue;
nid = alc880_idx_to_mixer(alc880_dac_to_idx(spec->multiout.dac_nids[i]));
if (!pfx && i == 2) {
err = add_pb_vol_ctrl(spec, ALC_CTL_WIDGET_VOL,
"Center",
HDA_COMPOSE_AMP_VAL(nid, 1, 0,
HDA_OUTPUT));
if (err < 0)
return err;
err = add_pb_vol_ctrl(spec, ALC_CTL_WIDGET_VOL,
"LFE",
HDA_COMPOSE_AMP_VAL(nid, 2, 0,
HDA_OUTPUT));
if (err < 0)
return err;
err = add_pb_sw_ctrl(spec, ALC_CTL_BIND_MUTE,
"Center",
HDA_COMPOSE_AMP_VAL(nid, 1, 2,
HDA_INPUT));
if (err < 0)
return err;
err = add_pb_sw_ctrl(spec, ALC_CTL_BIND_MUTE,
"LFE",
HDA_COMPOSE_AMP_VAL(nid, 2, 2,
HDA_INPUT));
if (err < 0)
return err;
} else {
const char *name = pfx;
int index = i;
if (!name) {
name = chname[i];
index = 0;
}
err = __add_pb_vol_ctrl(spec, ALC_CTL_WIDGET_VOL,
name, index,
HDA_COMPOSE_AMP_VAL(nid, 3, 0,
HDA_OUTPUT));
if (err < 0)
return err;
err = __add_pb_sw_ctrl(spec, ALC_CTL_BIND_MUTE,
name, index,
HDA_COMPOSE_AMP_VAL(nid, 3, 2,
HDA_INPUT));
if (err < 0)
return err;
}
}
return 0;
}
static int alc880_auto_create_extra_out(struct alc_spec *spec, hda_nid_t pin,
const char *pfx)
{
hda_nid_t nid;
int err;
if (!pin)
return 0;
if (alc880_is_fixed_pin(pin)) {
nid = alc880_idx_to_dac(alc880_fixed_pin_idx(pin));
if (!spec->multiout.hp_nid)
spec->multiout.hp_nid = nid;
else
spec->multiout.extra_out_nid[0] = nid;
nid = alc880_idx_to_mixer(alc880_fixed_pin_idx(pin));
err = add_pb_vol_ctrl(spec, ALC_CTL_WIDGET_VOL, pfx,
HDA_COMPOSE_AMP_VAL(nid, 3, 0, HDA_OUTPUT));
if (err < 0)
return err;
err = add_pb_sw_ctrl(spec, ALC_CTL_BIND_MUTE, pfx,
HDA_COMPOSE_AMP_VAL(nid, 3, 2, HDA_INPUT));
if (err < 0)
return err;
} else if (alc880_is_multi_pin(pin)) {
err = add_pb_sw_ctrl(spec, ALC_CTL_WIDGET_MUTE, pfx,
HDA_COMPOSE_AMP_VAL(pin, 3, 0, HDA_OUTPUT));
if (err < 0)
return err;
}
return 0;
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
static int alc_auto_create_input_ctls(struct hda_codec *codec,
const struct auto_pin_cfg *cfg,
hda_nid_t mixer,
hda_nid_t cap1, hda_nid_t cap2)
{
struct alc_spec *spec = codec->spec;
struct hda_input_mux *imux = &spec->private_imux[0];
int i, err, idx, type_idx = 0;
const char *prev_label = NULL;
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
if (!cap1)
continue;
idx = get_connection_index(codec, cap1, pin);
if (idx < 0 && cap2)
idx = get_connection_index(codec, cap2, pin);
if (idx >= 0)
snd_hda_add_imux_item(imux, label, idx, NULL);
}
return 0;
}
static int alc880_auto_create_input_ctls(struct hda_codec *codec,
const struct auto_pin_cfg *cfg)
{
return alc_auto_create_input_ctls(codec, cfg, 0x0b, 0x08, 0x09);
}
static void alc_set_pin_output(struct hda_codec *codec, hda_nid_t nid,
unsigned int pin_type)
{
snd_hda_codec_write(codec, nid, 0, AC_VERB_SET_PIN_WIDGET_CONTROL,
pin_type);
snd_hda_codec_write(codec, nid, 0, AC_VERB_SET_AMP_GAIN_MUTE,
AMP_OUT_UNMUTE);
}
static void alc880_auto_set_output_and_unmute(struct hda_codec *codec,
hda_nid_t nid, int pin_type,
int dac_idx)
{
alc_set_pin_output(codec, nid, pin_type);
if (alc880_is_multi_pin(nid)) {
struct alc_spec *spec = codec->spec;
int idx = alc880_multi_pin_idx(nid);
snd_hda_codec_write(codec, alc880_idx_to_selector(idx), 0,
AC_VERB_SET_CONNECT_SEL,
alc880_dac_to_idx(spec->multiout.dac_nids[dac_idx]));
}
}
static int get_pin_type(int line_out_type)
{
if (line_out_type == AUTO_PIN_HP_OUT)
return PIN_HP;
else
return PIN_OUT;
}
static void alc880_auto_init_multi_out(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
int i;
for (i = 0; i < spec->autocfg.line_outs; i++) {
hda_nid_t nid = spec->autocfg.line_out_pins[i];
int pin_type = get_pin_type(spec->autocfg.line_out_type);
alc880_auto_set_output_and_unmute(codec, nid, pin_type, i);
}
}
static void alc880_auto_init_extra_out(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
hda_nid_t pin;
pin = spec->autocfg.speaker_pins[0];
if (pin)
alc880_auto_set_output_and_unmute(codec, pin, PIN_OUT, 0);
pin = spec->autocfg.hp_pins[0];
if (pin)
alc880_auto_set_output_and_unmute(codec, pin, PIN_HP, 0);
}
static void alc880_auto_init_analog_input(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
struct auto_pin_cfg *cfg = &spec->autocfg;
int i;
for (i = 0; i < cfg->num_inputs; i++) {
hda_nid_t nid = cfg->inputs[i].pin;
if (alc_is_input_pin(codec, nid)) {
alc_set_input_pin(codec, nid, cfg->inputs[i].type);
if (nid != ALC880_PIN_CD_NID &&
(get_wcaps(codec, nid) & AC_WCAP_OUT_AMP))
snd_hda_codec_write(codec, nid, 0,
AC_VERB_SET_AMP_GAIN_MUTE,
AMP_OUT_MUTE);
}
}
}
static void alc880_auto_init_input_src(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
int c;
for (c = 0; c < spec->num_adc_nids; c++) {
unsigned int mux_idx;
const struct hda_input_mux *imux;
mux_idx = c >= spec->num_mux_defs ? 0 : c;
imux = &spec->input_mux[mux_idx];
if (!imux->num_items && mux_idx > 0)
imux = &spec->input_mux[0];
if (imux)
snd_hda_codec_write(codec, spec->adc_nids[c], 0,
AC_VERB_SET_CONNECT_SEL,
imux->items[0].index);
}
}
static int alc880_parse_auto_config(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
int err;
static const hda_nid_t alc880_ignore[] = { 0x1d, 0 };
err = snd_hda_parse_pin_def_config(codec, &spec->autocfg,
alc880_ignore);
if (err < 0)
return err;
if (!spec->autocfg.line_outs)
return 0;
err = alc880_auto_fill_dac_nids(spec, &spec->autocfg);
if (err < 0)
return err;
err = alc_auto_add_multi_channel_mode(codec);
if (err < 0)
return err;
err = alc880_auto_create_multi_out_ctls(spec, &spec->autocfg);
if (err < 0)
return err;
err = alc880_auto_create_extra_out(spec,
spec->autocfg.speaker_pins[0],
"Speaker");
if (err < 0)
return err;
err = alc880_auto_create_extra_out(spec, spec->autocfg.hp_pins[0],
"Headphone");
if (err < 0)
return err;
err = alc880_auto_create_input_ctls(codec, &spec->autocfg);
if (err < 0)
return err;
spec->multiout.max_channels = spec->multiout.num_dacs * 2;
alc_auto_parse_digital(codec);
if (spec->kctls.list)
add_mixer(spec, spec->kctls.list);
add_verb(spec, alc880_volume_init_verbs);
spec->num_mux_defs = 1;
spec->input_mux = &spec->private_imux[0];
alc_ssid_check(codec, 0x15, 0x1b, 0x14, 0);
return 1;
}
static void alc880_auto_init(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
alc880_auto_init_multi_out(codec);
alc880_auto_init_extra_out(codec);
alc880_auto_init_analog_input(codec);
alc880_auto_init_input_src(codec);
alc_auto_init_digital(codec);
if (spec->unsol_event)
alc_inithook(codec);
}
static void fixup_automic_adc(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
int i;
for (i = 0; i < spec->num_adc_nids; i++) {
hda_nid_t cap = spec->capsrc_nids ?
spec->capsrc_nids[i] : spec->adc_nids[i];
int iidx, eidx;
iidx = get_connection_index(codec, cap, spec->int_mic.pin);
if (iidx < 0)
continue;
eidx = get_connection_index(codec, cap, spec->ext_mic.pin);
if (eidx < 0)
continue;
spec->int_mic.mux_idx = iidx;
spec->ext_mic.mux_idx = eidx;
if (spec->capsrc_nids)
spec->capsrc_nids += i;
spec->adc_nids += i;
spec->num_adc_nids = 1;
eidx = get_connection_index(codec, cap, spec->dock_mic.pin);
if (eidx < 0)
spec->dock_mic.pin = 0;
else
spec->dock_mic.mux_idx = eidx;
return;
}
snd_printd(KERN_INFO "hda_codec: %s: "
"No ADC/MUX containing both 0x%x and 0x%x pins\n",
codec->chip_name, spec->int_mic.pin, spec->ext_mic.pin);
spec->auto_mic = 0;
}
static void select_or_unmute_capsrc(struct hda_codec *codec, hda_nid_t cap,
int idx)
{
if (get_wcaps_type(get_wcaps(codec, cap)) == AC_WID_AUD_MIX) {
snd_hda_codec_amp_stereo(codec, cap, HDA_INPUT, idx,
HDA_AMP_MUTE, 0);
} else {
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
hda_nid_t cap = spec->capsrc_nids ?
spec->capsrc_nids[i] : spec->adc_nids[i];
int idx;
idx = get_connection_index(codec, cap, pin);
if (idx < 0)
continue;
select_or_unmute_capsrc(codec, cap, idx);
return i;
}
return -1;
}
static void fixup_single_adc(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
struct auto_pin_cfg *cfg = &spec->autocfg;
int i;
if (cfg->num_inputs != 1)
return;
i = init_capsrc_for_pin(codec, cfg->inputs[0].pin);
if (i >= 0) {
if (spec->capsrc_nids)
spec->capsrc_nids += i;
spec->adc_nids += i;
spec->num_adc_nids = 1;
spec->single_input_src = 1;
}
}
static void fixup_dual_adc_switch(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
init_capsrc_for_pin(codec, spec->ext_mic.pin);
init_capsrc_for_pin(codec, spec->dock_mic.pin);
init_capsrc_for_pin(codec, spec->int_mic.pin);
}
static void alc_init_special_input_src(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
if (spec->dual_adc_switch)
fixup_dual_adc_switch(codec);
else if (spec->single_input_src)
init_capsrc_for_pin(codec, spec->autocfg.inputs[0].pin);
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
if (spec->num_adc_nids > 0 && spec->num_adc_nids <= 3) {
int mux = 0;
int num_adcs = spec->num_adc_nids;
if (spec->dual_adc_switch)
num_adcs = 1;
else if (spec->auto_mic)
fixup_automic_adc(codec);
else if (spec->input_mux) {
if (spec->input_mux->num_items > 1)
mux = 1;
else if (spec->input_mux->num_items == 1)
fixup_single_adc(codec);
}
spec->cap_mixer = caps[mux][num_adcs - 1];
}
}
static void fillup_priv_adc_nids(struct hda_codec *codec, const hda_nid_t *nids,
int num_nids)
{
struct alc_spec *spec = codec->spec;
struct auto_pin_cfg *cfg = &spec->autocfg;
int n;
hda_nid_t fallback_adc = 0, fallback_cap = 0;
for (n = 0; n < num_nids; n++) {
hda_nid_t adc, cap;
hda_nid_t conn[HDA_MAX_NUM_INPUTS];
int nconns, i, j;
adc = nids[n];
if (get_wcaps_type(get_wcaps(codec, adc)) != AC_WID_AUD_IN)
continue;
cap = adc;
nconns = snd_hda_get_connections(codec, cap, conn,
ARRAY_SIZE(conn));
if (nconns == 1) {
cap = conn[0];
nconns = snd_hda_get_connections(codec, cap, conn,
ARRAY_SIZE(conn));
}
if (nconns <= 0)
continue;
if (!fallback_adc) {
fallback_adc = adc;
fallback_cap = cap;
}
for (i = 0; i < cfg->num_inputs; i++) {
hda_nid_t nid = cfg->inputs[i].pin;
for (j = 0; j < nconns; j++) {
if (conn[j] == nid)
break;
}
if (j >= nconns)
break;
}
if (i >= cfg->num_inputs) {
int num_adcs = spec->num_adc_nids;
spec->private_adc_nids[num_adcs] = adc;
spec->private_capsrc_nids[num_adcs] = cap;
spec->num_adc_nids++;
spec->adc_nids = spec->private_adc_nids;
if (adc != cap)
spec->capsrc_nids = spec->private_capsrc_nids;
}
}
if (!spec->num_adc_nids) {
printk(KERN_WARNING "hda_codec: %s: no valid ADC found;"
" using fallback 0x%x\n",
codec->chip_name, fallback_adc);
spec->private_adc_nids[0] = fallback_adc;
spec->adc_nids = spec->private_adc_nids;
if (fallback_adc != fallback_cap) {
spec->private_capsrc_nids[0] = fallback_cap;
spec->capsrc_nids = spec->private_adc_nids;
}
}
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
static int patch_alc880(struct hda_codec *codec)
{
struct alc_spec *spec;
int board_config;
int err;
spec = kzalloc(sizeof(*spec), GFP_KERNEL);
if (spec == NULL)
return -ENOMEM;
codec->spec = spec;
board_config = snd_hda_check_board_config(codec, ALC880_MODEL_LAST,
alc880_models,
alc880_cfg_tbl);
if (board_config < 0) {
printk(KERN_INFO "hda_codec: %s: BIOS auto-probing.\n",
codec->chip_name);
board_config = ALC880_AUTO;
}
if (board_config == ALC880_AUTO) {
err = alc880_parse_auto_config(codec);
if (err < 0) {
alc_free(codec);
return err;
} else if (!err) {
printk(KERN_INFO
"hda_codec: Cannot set up configuration "
"from BIOS. Using 3-stack mode...\n");
board_config = ALC880_3ST;
}
}
err = snd_hda_attach_beep_device(codec, 0x1);
if (err < 0) {
alc_free(codec);
return err;
}
if (board_config != ALC880_AUTO)
setup_preset(codec, &alc880_presets[board_config]);
spec->stream_analog_playback = &alc880_pcm_analog_playback;
spec->stream_analog_capture = &alc880_pcm_analog_capture;
spec->stream_analog_alt_capture = &alc880_pcm_analog_alt_capture;
spec->stream_digital_playback = &alc880_pcm_digital_playback;
spec->stream_digital_capture = &alc880_pcm_digital_capture;
if (!spec->adc_nids && spec->input_mux) {
unsigned int wcap = get_wcaps(codec, alc880_adc_nids[0]);
wcap = get_wcaps_type(wcap);
if (wcap != AC_WID_AUD_IN) {
spec->adc_nids = alc880_adc_nids_alt;
spec->num_adc_nids = ARRAY_SIZE(alc880_adc_nids_alt);
} else {
spec->adc_nids = alc880_adc_nids;
spec->num_adc_nids = ARRAY_SIZE(alc880_adc_nids);
}
}
set_capture_mixer(codec);
set_beep_amp(spec, 0x0b, 0x05, HDA_INPUT);
spec->vmaster_nid = 0x0c;
codec->patch_ops = alc_patch_ops;
if (board_config == ALC880_AUTO)
spec->init_hook = alc880_auto_init;
#ifdef CONFIG_SND_HDA_POWER_SAVE
if (!spec->loopback.amplist)
spec->loopback.amplist = alc880_loopbacks;
#endif
return 0;
}
static void alc260_hp_master_update(struct hda_codec *codec)
{
update_speakers(codec);
}
static int alc260_hp_master_sw_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct alc_spec *spec = codec->spec;
*ucontrol->value.integer.value = !spec->master_mute;
return 0;
}
static int alc260_hp_master_sw_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct alc_spec *spec = codec->spec;
int val = !*ucontrol->value.integer.value;
if (val == spec->master_mute)
return 0;
spec->master_mute = val;
alc260_hp_master_update(codec);
return 1;
}
static void alc260_hp_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x0f;
spec->autocfg.speaker_pins[0] = 0x10;
spec->autocfg.speaker_pins[1] = 0x11;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_PIN;
}
static void alc260_hp_3013_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x15;
spec->autocfg.speaker_pins[0] = 0x10;
spec->autocfg.speaker_pins[1] = 0x11;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_PIN;
}
static void alc260_hp_3012_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x10;
spec->autocfg.speaker_pins[0] = 0x0f;
spec->autocfg.speaker_pins[1] = 0x11;
spec->autocfg.speaker_pins[2] = 0x15;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_PIN;
}
static void alc260_replacer_672v_automute(struct hda_codec *codec)
{
unsigned int present;
present = snd_hda_jack_detect(codec, 0x0f);
if (present) {
snd_hda_codec_write_cache(codec, 0x01, 0,
AC_VERB_SET_GPIO_DATA, 1);
snd_hda_codec_write_cache(codec, 0x0f, 0,
AC_VERB_SET_PIN_WIDGET_CONTROL,
PIN_HP);
} else {
snd_hda_codec_write_cache(codec, 0x01, 0,
AC_VERB_SET_GPIO_DATA, 0);
snd_hda_codec_write_cache(codec, 0x0f, 0,
AC_VERB_SET_PIN_WIDGET_CONTROL,
PIN_OUT);
}
}
static void alc260_replacer_672v_unsol_event(struct hda_codec *codec,
unsigned int res)
{
if ((res >> 26) == ALC880_HP_EVENT)
alc260_replacer_672v_automute(codec);
}
static int alc260_add_playback_controls(struct alc_spec *spec, hda_nid_t nid,
const char *pfx, int *vol_bits)
{
hda_nid_t nid_vol;
unsigned long vol_val, sw_val;
int err;
if (nid >= 0x0f && nid < 0x11) {
nid_vol = nid - 0x7;
vol_val = HDA_COMPOSE_AMP_VAL(nid_vol, 3, 0, HDA_OUTPUT);
sw_val = HDA_COMPOSE_AMP_VAL(nid, 3, 0, HDA_OUTPUT);
} else if (nid == 0x11) {
nid_vol = nid - 0x7;
vol_val = HDA_COMPOSE_AMP_VAL(nid_vol, 2, 0, HDA_OUTPUT);
sw_val = HDA_COMPOSE_AMP_VAL(nid, 2, 0, HDA_OUTPUT);
} else if (nid >= 0x12 && nid <= 0x15) {
nid_vol = 0x08;
vol_val = HDA_COMPOSE_AMP_VAL(nid_vol, 3, 0, HDA_OUTPUT);
sw_val = HDA_COMPOSE_AMP_VAL(nid, 3, 0, HDA_OUTPUT);
} else
return 0;
if (!(*vol_bits & (1 << nid_vol))) {
err = add_pb_vol_ctrl(spec, ALC_CTL_WIDGET_VOL, pfx, vol_val);
if (err < 0)
return err;
*vol_bits |= (1 << nid_vol);
}
err = add_pb_sw_ctrl(spec, ALC_CTL_WIDGET_MUTE, pfx, sw_val);
if (err < 0)
return err;
return 1;
}
static int alc260_auto_create_multi_out_ctls(struct alc_spec *spec,
const struct auto_pin_cfg *cfg)
{
hda_nid_t nid;
int err;
int vols = 0;
spec->multiout.num_dacs = 1;
spec->multiout.dac_nids = spec->private_dac_nids;
spec->private_dac_nids[0] = 0x02;
nid = cfg->line_out_pins[0];
if (nid) {
const char *pfx;
if (!cfg->speaker_pins[0] && !cfg->hp_pins[0])
pfx = "Master";
else if (cfg->line_out_type == AUTO_PIN_SPEAKER_OUT)
pfx = "Speaker";
else
pfx = "Front";
err = alc260_add_playback_controls(spec, nid, pfx, &vols);
if (err < 0)
return err;
}
nid = cfg->speaker_pins[0];
if (nid) {
err = alc260_add_playback_controls(spec, nid, "Speaker", &vols);
if (err < 0)
return err;
}
nid = cfg->hp_pins[0];
if (nid) {
err = alc260_add_playback_controls(spec, nid, "Headphone",
&vols);
if (err < 0)
return err;
}
return 0;
}
static int alc260_auto_create_input_ctls(struct hda_codec *codec,
const struct auto_pin_cfg *cfg)
{
return alc_auto_create_input_ctls(codec, cfg, 0x07, 0x04, 0x05);
}
static void alc260_auto_set_output_and_unmute(struct hda_codec *codec,
hda_nid_t nid, int pin_type,
int sel_idx)
{
alc_set_pin_output(codec, nid, pin_type);
if (nid >= 0x12) {
int idx = nid - 0x12;
snd_hda_codec_write(codec, idx + 0x0b, 0,
AC_VERB_SET_CONNECT_SEL, sel_idx);
}
}
static void alc260_auto_init_multi_out(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
hda_nid_t nid;
nid = spec->autocfg.line_out_pins[0];
if (nid) {
int pin_type = get_pin_type(spec->autocfg.line_out_type);
alc260_auto_set_output_and_unmute(codec, nid, pin_type, 0);
}
nid = spec->autocfg.speaker_pins[0];
if (nid)
alc260_auto_set_output_and_unmute(codec, nid, PIN_OUT, 0);
nid = spec->autocfg.hp_pins[0];
if (nid)
alc260_auto_set_output_and_unmute(codec, nid, PIN_HP, 0);
}
static void alc260_auto_init_analog_input(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
struct auto_pin_cfg *cfg = &spec->autocfg;
int i;
for (i = 0; i < cfg->num_inputs; i++) {
hda_nid_t nid = cfg->inputs[i].pin;
if (nid >= 0x12) {
alc_set_input_pin(codec, nid, cfg->inputs[i].type);
if (nid != ALC260_PIN_CD_NID &&
(get_wcaps(codec, nid) & AC_WCAP_OUT_AMP))
snd_hda_codec_write(codec, nid, 0,
AC_VERB_SET_AMP_GAIN_MUTE,
AMP_OUT_MUTE);
}
}
}
static int alc260_parse_auto_config(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
int err;
static const hda_nid_t alc260_ignore[] = { 0x17, 0 };
err = snd_hda_parse_pin_def_config(codec, &spec->autocfg,
alc260_ignore);
if (err < 0)
return err;
err = alc260_auto_create_multi_out_ctls(spec, &spec->autocfg);
if (err < 0)
return err;
if (!spec->kctls.list)
return 0;
err = alc260_auto_create_input_ctls(codec, &spec->autocfg);
if (err < 0)
return err;
spec->multiout.max_channels = 2;
if (spec->autocfg.dig_outs)
spec->multiout.dig_out_nid = ALC260_DIGOUT_NID;
if (spec->kctls.list)
add_mixer(spec, spec->kctls.list);
add_verb(spec, alc260_volume_init_verbs);
spec->num_mux_defs = 1;
spec->input_mux = &spec->private_imux[0];
alc_ssid_check(codec, 0x10, 0x15, 0x0f, 0);
return 1;
}
static void alc260_auto_init(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
alc260_auto_init_multi_out(codec);
alc260_auto_init_analog_input(codec);
alc260_auto_init_input_src(codec);
alc_auto_init_digital(codec);
if (spec->unsol_event)
alc_inithook(codec);
}
static int patch_alc260(struct hda_codec *codec)
{
struct alc_spec *spec;
int err, board_config;
spec = kzalloc(sizeof(*spec), GFP_KERNEL);
if (spec == NULL)
return -ENOMEM;
codec->spec = spec;
board_config = snd_hda_check_board_config(codec, ALC260_MODEL_LAST,
alc260_models,
alc260_cfg_tbl);
if (board_config < 0) {
snd_printd(KERN_INFO "hda_codec: %s: BIOS auto-probing.\n",
codec->chip_name);
board_config = ALC260_AUTO;
}
if (board_config == ALC260_AUTO) {
alc_pick_fixup(codec, NULL, alc260_fixup_tbl, alc260_fixups);
alc_apply_fixup(codec, ALC_FIXUP_ACT_PRE_PROBE);
}
if (board_config == ALC260_AUTO) {
err = alc260_parse_auto_config(codec);
if (err < 0) {
alc_free(codec);
return err;
} else if (!err) {
printk(KERN_INFO
"hda_codec: Cannot set up configuration "
"from BIOS. Using base mode...\n");
board_config = ALC260_BASIC;
}
}
err = snd_hda_attach_beep_device(codec, 0x1);
if (err < 0) {
alc_free(codec);
return err;
}
if (board_config != ALC260_AUTO)
setup_preset(codec, &alc260_presets[board_config]);
spec->stream_analog_playback = &alc260_pcm_analog_playback;
spec->stream_analog_capture = &alc260_pcm_analog_capture;
spec->stream_analog_alt_capture = &alc260_pcm_analog_capture;
spec->stream_digital_playback = &alc260_pcm_digital_playback;
spec->stream_digital_capture = &alc260_pcm_digital_capture;
if (!spec->adc_nids && spec->input_mux) {
unsigned int wcap = get_wcaps(codec, 0x04);
wcap = get_wcaps_type(wcap);
if (wcap != AC_WID_AUD_IN || spec->input_mux->num_items == 1) {
spec->adc_nids = alc260_adc_nids_alt;
spec->num_adc_nids = ARRAY_SIZE(alc260_adc_nids_alt);
} else {
spec->adc_nids = alc260_adc_nids;
spec->num_adc_nids = ARRAY_SIZE(alc260_adc_nids);
}
}
set_capture_mixer(codec);
set_beep_amp(spec, 0x07, 0x05, HDA_INPUT);
alc_apply_fixup(codec, ALC_FIXUP_ACT_PROBE);
spec->vmaster_nid = 0x08;
codec->patch_ops = alc_patch_ops;
if (board_config == ALC260_AUTO)
spec->init_hook = alc260_auto_init;
spec->shutup = alc_eapd_shutup;
#ifdef CONFIG_SND_HDA_POWER_SAVE
if (!spec->loopback.amplist)
spec->loopback.amplist = alc260_loopbacks;
#endif
return 0;
}
static void alc885_imac24_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x14;
spec->autocfg.speaker_pins[0] = 0x18;
spec->autocfg.speaker_pins[1] = 0x1a;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_AMP;
}
static void alc885_mba21_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x14;
spec->autocfg.speaker_pins[0] = 0x18;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_AMP;
}
static void alc885_mbp3_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x15;
spec->autocfg.speaker_pins[0] = 0x14;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_AMP;
}
static void alc885_imac91_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x14;
spec->autocfg.speaker_pins[0] = 0x18;
spec->autocfg.speaker_pins[1] = 0x1a;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_AMP;
}
static void alc882_targa_automute(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
alc_hp_automute(codec);
snd_hda_codec_write_cache(codec, 1, 0, AC_VERB_SET_GPIO_DATA,
spec->jack_present ? 1 : 3);
}
static void alc882_targa_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x14;
spec->autocfg.speaker_pins[0] = 0x1b;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_AMP;
}
static void alc882_targa_unsol_event(struct hda_codec *codec, unsigned int res)
{
if ((res >> 26) == ALC880_HP_EVENT)
alc882_targa_automute(codec);
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
static void alc885_macpro_init_hook(struct hda_codec *codec)
{
alc882_gpio_mute(codec, 0, 0);
alc882_gpio_mute(codec, 1, 0);
}
static void alc885_imac24_init_hook(struct hda_codec *codec)
{
alc885_macpro_init_hook(codec);
alc_hp_automute(codec);
}
static void alc883_medion_wim2160_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x1a;
spec->autocfg.speaker_pins[0] = 0x15;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_AMP;
}
static void alc883_mitac_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x15;
spec->autocfg.speaker_pins[0] = 0x14;
spec->autocfg.speaker_pins[1] = 0x17;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_AMP;
}
static void alc888_3st_hp_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x1b;
spec->autocfg.speaker_pins[0] = 0x14;
spec->autocfg.speaker_pins[1] = 0x16;
spec->autocfg.speaker_pins[2] = 0x18;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_AMP;
}
static void alc888_lenovo_ms7195_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x1b;
spec->autocfg.line_out_pins[0] = 0x14;
spec->autocfg.speaker_pins[0] = 0x15;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_AMP;
}
static void alc883_lenovo_nb0763_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x14;
spec->autocfg.speaker_pins[0] = 0x15;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_AMP;
}
static void alc883_clevo_m720_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x15;
spec->autocfg.speaker_pins[0] = 0x14;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_AMP;
}
static void alc883_clevo_m720_init_hook(struct hda_codec *codec)
{
alc_hp_automute(codec);
alc88x_simple_mic_automute(codec);
}
static void alc883_clevo_m720_unsol_event(struct hda_codec *codec,
unsigned int res)
{
switch (res >> 26) {
case ALC880_MIC_EVENT:
alc88x_simple_mic_automute(codec);
break;
default:
alc_sku_unsol_event(codec, res);
break;
}
}
static void alc883_2ch_fujitsu_pi2515_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x14;
spec->autocfg.speaker_pins[0] = 0x15;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_AMP;
}
static void alc883_haier_w66_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x1b;
spec->autocfg.speaker_pins[0] = 0x14;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_AMP;
}
static void alc883_lenovo_101e_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x1b;
spec->autocfg.line_out_pins[0] = 0x14;
spec->autocfg.speaker_pins[0] = 0x15;
spec->automute = 1;
spec->detect_line = 1;
spec->automute_lines = 1;
spec->automute_mode = ALC_AUTOMUTE_AMP;
}
static void alc883_acer_aspire_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x14;
spec->autocfg.speaker_pins[0] = 0x15;
spec->autocfg.speaker_pins[1] = 0x16;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_AMP;
}
static void alc888_6st_dell_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x1b;
spec->autocfg.speaker_pins[0] = 0x14;
spec->autocfg.speaker_pins[1] = 0x15;
spec->autocfg.speaker_pins[2] = 0x16;
spec->autocfg.speaker_pins[3] = 0x17;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_AMP;
}
static void alc888_lenovo_sky_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x1b;
spec->autocfg.speaker_pins[0] = 0x14;
spec->autocfg.speaker_pins[1] = 0x15;
spec->autocfg.speaker_pins[2] = 0x16;
spec->autocfg.speaker_pins[3] = 0x17;
spec->autocfg.speaker_pins[4] = 0x1a;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_AMP;
}
static void alc883_vaiott_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x15;
spec->autocfg.speaker_pins[0] = 0x14;
spec->autocfg.speaker_pins[1] = 0x17;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_AMP;
}
static void alc883_mode2_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x1b;
spec->autocfg.speaker_pins[0] = 0x14;
spec->autocfg.speaker_pins[1] = 0x15;
spec->autocfg.speaker_pins[2] = 0x16;
spec->ext_mic.pin = 0x18;
spec->int_mic.pin = 0x19;
spec->ext_mic.mux_idx = 0;
spec->int_mic.mux_idx = 1;
spec->auto_mic = 1;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_AMP;
}
static void alc883_eee1601_inithook(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x14;
spec->autocfg.speaker_pins[0] = 0x1b;
alc_hp_automute(codec);
}
static void alc889A_mb31_automute(struct hda_codec *codec)
{
unsigned int present;
if (snd_hda_codec_read(codec, 0x15, 0, AC_VERB_GET_CONNECT_SEL, 0)
== 0x00) {
present = snd_hda_jack_detect(codec, 0x15);
snd_hda_codec_amp_stereo(codec, 0x14, HDA_OUTPUT, 0,
HDA_AMP_MUTE, present ? HDA_AMP_MUTE : 0);
snd_hda_codec_amp_stereo(codec, 0x16, HDA_OUTPUT, 0,
HDA_AMP_MUTE, present ? HDA_AMP_MUTE : 0);
}
}
static void alc889A_mb31_unsol_event(struct hda_codec *codec, unsigned int res)
{
if ((res >> 26) == ALC880_HP_EVENT)
alc889A_mb31_automute(codec);
}
static int alc882_auto_create_input_ctls(struct hda_codec *codec,
const struct auto_pin_cfg *cfg)
{
return alc_auto_create_input_ctls(codec, cfg, 0x0b, 0x23, 0x22);
}
static void alc882_auto_set_output_and_unmute(struct hda_codec *codec,
hda_nid_t nid, int pin_type,
hda_nid_t dac)
{
int idx;
alc_set_pin_output(codec, nid, pin_type);
if (dac == 0x25)
idx = 4;
else if (dac >= 0x02 && dac <= 0x05)
idx = dac - 2;
else
return;
snd_hda_codec_write(codec, nid, 0, AC_VERB_SET_CONNECT_SEL, idx);
}
static void alc882_auto_init_multi_out(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
int i;
for (i = 0; i <= HDA_SIDE; i++) {
hda_nid_t nid = spec->autocfg.line_out_pins[i];
int pin_type = get_pin_type(spec->autocfg.line_out_type);
if (nid)
alc882_auto_set_output_and_unmute(codec, nid, pin_type,
spec->multiout.dac_nids[i]);
}
}
static void alc882_auto_init_hp_out(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
hda_nid_t pin, dac;
int i;
if (spec->autocfg.line_out_type != AUTO_PIN_HP_OUT) {
for (i = 0; i < ARRAY_SIZE(spec->autocfg.hp_pins); i++) {
pin = spec->autocfg.hp_pins[i];
if (!pin)
break;
dac = spec->multiout.hp_nid;
if (!dac)
dac = spec->multiout.dac_nids[0];
alc882_auto_set_output_and_unmute(codec, pin, PIN_HP, dac);
}
}
if (spec->autocfg.line_out_type != AUTO_PIN_SPEAKER_OUT) {
for (i = 0; i < ARRAY_SIZE(spec->autocfg.speaker_pins); i++) {
pin = spec->autocfg.speaker_pins[i];
if (!pin)
break;
dac = spec->multiout.extra_out_nid[0];
if (!dac)
dac = spec->multiout.dac_nids[0];
alc882_auto_set_output_and_unmute(codec, pin, PIN_OUT, dac);
}
}
}
static void alc882_auto_init_analog_input(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
struct auto_pin_cfg *cfg = &spec->autocfg;
int i;
for (i = 0; i < cfg->num_inputs; i++) {
hda_nid_t nid = cfg->inputs[i].pin;
alc_set_input_pin(codec, nid, cfg->inputs[i].type);
if (get_wcaps(codec, nid) & AC_WCAP_OUT_AMP)
snd_hda_codec_write(codec, nid, 0,
AC_VERB_SET_AMP_GAIN_MUTE,
AMP_OUT_MUTE);
}
}
static void alc882_auto_init_input_src(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
int c;
for (c = 0; c < spec->num_adc_nids; c++) {
hda_nid_t conn_list[HDA_MAX_NUM_INPUTS];
hda_nid_t nid = spec->capsrc_nids[c];
unsigned int mux_idx;
const struct hda_input_mux *imux;
int conns, mute, idx, item;
snd_hda_codec_write(codec, spec->adc_nids[c], 0,
AC_VERB_SET_AMP_GAIN_MUTE,
AMP_IN_MUTE(0));
conns = snd_hda_get_connections(codec, nid, conn_list,
ARRAY_SIZE(conn_list));
if (conns < 0)
continue;
mux_idx = c >= spec->num_mux_defs ? 0 : c;
imux = &spec->input_mux[mux_idx];
if (!imux->num_items && mux_idx > 0)
imux = &spec->input_mux[0];
for (idx = 0; idx < conns; idx++) {
mute = AMP_IN_MUTE(idx);
for (item = 0; item < imux->num_items; item++) {
if (imux->items[item].index == idx) {
if (spec->cur_mux[c] == item)
mute = AMP_IN_UNMUTE(idx);
break;
}
}
if (get_wcaps(codec, nid) & AC_WCAP_IN_AMP)
snd_hda_codec_write(codec, nid, 0,
AC_VERB_SET_AMP_GAIN_MUTE,
mute);
else if (mute != AMP_IN_MUTE(idx))
snd_hda_codec_write(codec, nid, 0,
AC_VERB_SET_CONNECT_SEL,
idx);
}
}
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
static int alc882_parse_auto_config(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
static const hda_nid_t alc882_ignore[] = { 0x1d, 0 };
int err;
err = snd_hda_parse_pin_def_config(codec, &spec->autocfg,
alc882_ignore);
if (err < 0)
return err;
if (!spec->autocfg.line_outs)
return 0;
err = alc880_auto_fill_dac_nids(spec, &spec->autocfg);
if (err < 0)
return err;
err = alc_auto_add_multi_channel_mode(codec);
if (err < 0)
return err;
err = alc880_auto_create_multi_out_ctls(spec, &spec->autocfg);
if (err < 0)
return err;
err = alc880_auto_create_extra_out(spec, spec->autocfg.hp_pins[0],
"Headphone");
if (err < 0)
return err;
err = alc880_auto_create_extra_out(spec,
spec->autocfg.speaker_pins[0],
"Speaker");
if (err < 0)
return err;
err = alc882_auto_create_input_ctls(codec, &spec->autocfg);
if (err < 0)
return err;
spec->multiout.max_channels = spec->multiout.num_dacs * 2;
alc_auto_parse_digital(codec);
if (spec->kctls.list)
add_mixer(spec, spec->kctls.list);
add_verb(spec, alc883_auto_init_verbs);
if (get_wcaps_type(get_wcaps(codec, 0x07)) == AC_WID_AUD_IN)
add_verb(spec, alc882_adc1_init_verbs);
spec->num_mux_defs = 1;
spec->input_mux = &spec->private_imux[0];
alc_ssid_check(codec, 0x15, 0x1b, 0x14, 0);
err = alc_auto_add_mic_boost(codec);
if (err < 0)
return err;
return 1;
}
static void alc882_auto_init(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
alc882_auto_init_multi_out(codec);
alc882_auto_init_hp_out(codec);
alc882_auto_init_analog_input(codec);
alc882_auto_init_input_src(codec);
alc_auto_init_digital(codec);
if (spec->unsol_event)
alc_inithook(codec);
}
static int patch_alc882(struct hda_codec *codec)
{
struct alc_spec *spec;
int err, board_config;
spec = kzalloc(sizeof(*spec), GFP_KERNEL);
if (spec == NULL)
return -ENOMEM;
codec->spec = spec;
switch (codec->vendor_id) {
case 0x10ec0882:
case 0x10ec0885:
break;
default:
alc_fix_pll_init(codec, 0x20, 0x0a, 10);
break;
}
board_config = snd_hda_check_board_config(codec, ALC882_MODEL_LAST,
alc882_models,
alc882_cfg_tbl);
if (board_config < 0 || board_config >= ALC882_MODEL_LAST)
board_config = snd_hda_check_board_codec_sid_config(codec,
ALC882_MODEL_LAST, alc882_models, alc882_ssid_cfg_tbl);
if (board_config < 0 || board_config >= ALC882_MODEL_LAST) {
printk(KERN_INFO "hda_codec: %s: BIOS auto-probing.\n",
codec->chip_name);
board_config = ALC882_AUTO;
}
if (board_config == ALC882_AUTO) {
alc_pick_fixup(codec, NULL, alc882_fixup_tbl, alc882_fixups);
alc_apply_fixup(codec, ALC_FIXUP_ACT_PRE_PROBE);
}
alc_auto_parse_customize_define(codec);
if (board_config == ALC882_AUTO) {
err = alc882_parse_auto_config(codec);
if (err < 0) {
alc_free(codec);
return err;
} else if (!err) {
printk(KERN_INFO
"hda_codec: Cannot set up configuration "
"from BIOS. Using base mode...\n");
board_config = ALC882_3ST_DIG;
}
}
if (has_cdefine_beep(codec)) {
err = snd_hda_attach_beep_device(codec, 0x1);
if (err < 0) {
alc_free(codec);
return err;
}
}
if (board_config != ALC882_AUTO)
setup_preset(codec, &alc882_presets[board_config]);
spec->stream_analog_playback = &alc882_pcm_analog_playback;
spec->stream_analog_capture = &alc882_pcm_analog_capture;
spec->stream_analog_alt_capture = &alc880_pcm_analog_alt_capture;
spec->stream_digital_playback = &alc882_pcm_digital_playback;
spec->stream_digital_capture = &alc882_pcm_digital_capture;
if (!spec->adc_nids && spec->input_mux) {
int i, j;
spec->num_adc_nids = 0;
for (i = 0; i < ARRAY_SIZE(alc882_adc_nids); i++) {
const struct hda_input_mux *imux = spec->input_mux;
hda_nid_t cap;
hda_nid_t items[16];
hda_nid_t nid = alc882_adc_nids[i];
unsigned int wcap = get_wcaps(codec, nid);
wcap = get_wcaps_type(wcap);
if (wcap != AC_WID_AUD_IN)
continue;
spec->private_adc_nids[spec->num_adc_nids] = nid;
err = snd_hda_get_connections(codec, nid, &cap, 1);
if (err < 0)
continue;
err = snd_hda_get_connections(codec, cap, items,
ARRAY_SIZE(items));
if (err < 0)
continue;
for (j = 0; j < imux->num_items; j++)
if (imux->items[j].index >= err)
break;
if (j < imux->num_items)
continue;
spec->private_capsrc_nids[spec->num_adc_nids] = cap;
spec->num_adc_nids++;
}
spec->adc_nids = spec->private_adc_nids;
spec->capsrc_nids = spec->private_capsrc_nids;
}
set_capture_mixer(codec);
if (has_cdefine_beep(codec))
set_beep_amp(spec, 0x0b, 0x05, HDA_INPUT);
alc_apply_fixup(codec, ALC_FIXUP_ACT_PROBE);
spec->vmaster_nid = 0x0c;
codec->patch_ops = alc_patch_ops;
if (board_config == ALC882_AUTO)
spec->init_hook = alc882_auto_init;
alc_init_jacks(codec);
#ifdef CONFIG_SND_HDA_POWER_SAVE
if (!spec->loopback.amplist)
spec->loopback.amplist = alc882_loopbacks;
#endif
return 0;
}
static void alc262_hp_bpc_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x1b;
spec->autocfg.speaker_pins[0] = 0x16;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_PIN;
}
static void alc262_hp_wildwest_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x15;
spec->autocfg.speaker_pins[0] = 0x16;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_PIN;
}
static void alc262_hp_t5735_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x15;
spec->autocfg.speaker_pins[0] = 0x14;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_PIN;
}
static void alc262_hippo_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x15;
spec->autocfg.speaker_pins[0] = 0x14;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_AMP;
}
static void alc262_hippo1_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x1b;
spec->autocfg.speaker_pins[0] = 0x14;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_AMP;
}
static void alc262_tyan_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x1b;
spec->autocfg.speaker_pins[0] = 0x15;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_AMP;
}
static void alc262_toshiba_s06_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x15;
spec->autocfg.speaker_pins[0] = 0x14;
spec->ext_mic.pin = 0x18;
spec->ext_mic.mux_idx = 0;
spec->int_mic.pin = 0x12;
spec->int_mic.mux_idx = 9;
spec->auto_mic = 1;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_PIN;
}
static void alc262_fujitsu_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x14;
spec->autocfg.hp_pins[1] = 0x1b;
spec->autocfg.speaker_pins[0] = 0x15;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_AMP;
}
static void alc262_lenovo_3000_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x1b;
spec->autocfg.speaker_pins[0] = 0x14;
spec->autocfg.speaker_pins[1] = 0x16;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_AMP;
}
static void alc262_ultra_automute(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
unsigned int mute;
mute = 0;
if (!spec->cur_mux[0]) {
spec->jack_present = snd_hda_jack_detect(codec, 0x15);
if (spec->jack_present)
mute = HDA_AMP_MUTE;
}
snd_hda_codec_amp_stereo(codec, 0x14, HDA_OUTPUT, 0,
HDA_AMP_MUTE, mute);
snd_hda_codec_amp_stereo(codec, 0x15, HDA_OUTPUT, 0,
HDA_AMP_MUTE, mute ? 0 : HDA_AMP_MUTE);
}
static void alc262_ultra_unsol_event(struct hda_codec *codec,
unsigned int res)
{
if ((res >> 26) != ALC880_HP_EVENT)
return;
alc262_ultra_automute(codec);
}
static int alc262_ultra_mux_enum_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct alc_spec *spec = codec->spec;
int ret;
ret = alc_mux_enum_put(kcontrol, ucontrol);
if (!ret)
return 0;
snd_hda_codec_write_cache(codec, 0x15, 0,
AC_VERB_SET_PIN_WIDGET_CONTROL,
spec->cur_mux[0] ? PIN_VREF80 : PIN_HP);
alc262_ultra_automute(codec);
return ret;
}
static int alc262_check_volbit(hda_nid_t nid)
{
if (!nid)
return 0;
else if (nid == 0x16)
return 2;
else
return 1;
}
static int alc262_add_out_vol_ctl(struct alc_spec *spec, hda_nid_t nid,
const char *pfx, int *vbits, int idx)
{
unsigned long val;
int vbit;
vbit = alc262_check_volbit(nid);
if (!vbit)
return 0;
if (*vbits & vbit)
return 0;
*vbits |= vbit;
if (vbit == 2)
val = HDA_COMPOSE_AMP_VAL(0x0e, 2, 0, HDA_OUTPUT);
else
val = HDA_COMPOSE_AMP_VAL(0x0c, 3, 0, HDA_OUTPUT);
return __add_pb_vol_ctrl(spec, ALC_CTL_WIDGET_VOL, pfx, idx, val);
}
static int alc262_add_out_sw_ctl(struct alc_spec *spec, hda_nid_t nid,
const char *pfx, int idx)
{
unsigned long val;
if (!nid)
return 0;
if (nid == 0x16)
val = HDA_COMPOSE_AMP_VAL(nid, 2, 0, HDA_OUTPUT);
else
val = HDA_COMPOSE_AMP_VAL(nid, 3, 0, HDA_OUTPUT);
return __add_pb_sw_ctrl(spec, ALC_CTL_WIDGET_MUTE, pfx, idx, val);
}
static int alc262_auto_create_multi_out_ctls(struct alc_spec *spec,
const struct auto_pin_cfg *cfg)
{
const char *pfx;
int vbits;
int i, err;
spec->multiout.num_dacs = 1;
spec->multiout.dac_nids = spec->private_dac_nids;
spec->private_dac_nids[0] = 2;
pfx = alc_get_line_out_pfx(spec, true);
if (!pfx)
pfx = "Front";
for (i = 0; i < 2; i++) {
err = alc262_add_out_sw_ctl(spec, cfg->line_out_pins[i], pfx, i);
if (err < 0)
return err;
if (cfg->line_out_type != AUTO_PIN_SPEAKER_OUT) {
err = alc262_add_out_sw_ctl(spec, cfg->speaker_pins[i],
"Speaker", i);
if (err < 0)
return err;
}
if (cfg->line_out_type != AUTO_PIN_HP_OUT) {
err = alc262_add_out_sw_ctl(spec, cfg->hp_pins[i],
"Headphone", i);
if (err < 0)
return err;
}
}
vbits = alc262_check_volbit(cfg->line_out_pins[0]) |
alc262_check_volbit(cfg->speaker_pins[0]) |
alc262_check_volbit(cfg->hp_pins[0]);
if (vbits == 1 || vbits == 2)
pfx = "Master";
vbits = 0;
for (i = 0; i < 2; i++) {
err = alc262_add_out_vol_ctl(spec, cfg->line_out_pins[i], pfx,
&vbits, i);
if (err < 0)
return err;
if (cfg->line_out_type != AUTO_PIN_SPEAKER_OUT) {
err = alc262_add_out_vol_ctl(spec, cfg->speaker_pins[i],
"Speaker", &vbits, i);
if (err < 0)
return err;
}
if (cfg->line_out_type != AUTO_PIN_HP_OUT) {
err = alc262_add_out_vol_ctl(spec, cfg->hp_pins[i],
"Headphone", &vbits, i);
if (err < 0)
return err;
}
}
return 0;
}
static int alc262_parse_auto_config(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
int err;
static const hda_nid_t alc262_ignore[] = { 0x1d, 0 };
err = snd_hda_parse_pin_def_config(codec, &spec->autocfg,
alc262_ignore);
if (err < 0)
return err;
if (!spec->autocfg.line_outs) {
if (spec->autocfg.dig_outs || spec->autocfg.dig_in_pin) {
spec->multiout.max_channels = 2;
spec->no_analog = 1;
goto dig_only;
}
return 0;
}
err = alc262_auto_create_multi_out_ctls(spec, &spec->autocfg);
if (err < 0)
return err;
err = alc262_auto_create_input_ctls(codec, &spec->autocfg);
if (err < 0)
return err;
spec->multiout.max_channels = spec->multiout.num_dacs * 2;
dig_only:
alc_auto_parse_digital(codec);
if (spec->kctls.list)
add_mixer(spec, spec->kctls.list);
add_verb(spec, alc262_volume_init_verbs);
spec->num_mux_defs = 1;
spec->input_mux = &spec->private_imux[0];
err = alc_auto_add_mic_boost(codec);
if (err < 0)
return err;
alc_ssid_check(codec, 0x15, 0x1b, 0x14, 0);
return 1;
}
static void alc262_auto_init(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
alc262_auto_init_multi_out(codec);
alc262_auto_init_hp_out(codec);
alc262_auto_init_analog_input(codec);
alc262_auto_init_input_src(codec);
alc_auto_init_digital(codec);
if (spec->unsol_event)
alc_inithook(codec);
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
board_config = snd_hda_check_board_config(codec, ALC262_MODEL_LAST,
alc262_models,
alc262_cfg_tbl);
if (board_config < 0) {
printk(KERN_INFO "hda_codec: %s: BIOS auto-probing.\n",
codec->chip_name);
board_config = ALC262_AUTO;
}
if (board_config == ALC262_AUTO) {
alc_pick_fixup(codec, NULL, alc262_fixup_tbl, alc262_fixups);
alc_apply_fixup(codec, ALC_FIXUP_ACT_PRE_PROBE);
}
if (board_config == ALC262_AUTO) {
err = alc262_parse_auto_config(codec);
if (err < 0) {
alc_free(codec);
return err;
} else if (!err) {
printk(KERN_INFO
"hda_codec: Cannot set up configuration "
"from BIOS. Using base mode...\n");
board_config = ALC262_BASIC;
}
}
if (!spec->no_analog && has_cdefine_beep(codec)) {
err = snd_hda_attach_beep_device(codec, 0x1);
if (err < 0) {
alc_free(codec);
return err;
}
}
if (board_config != ALC262_AUTO)
setup_preset(codec, &alc262_presets[board_config]);
spec->stream_analog_playback = &alc262_pcm_analog_playback;
spec->stream_analog_capture = &alc262_pcm_analog_capture;
spec->stream_digital_playback = &alc262_pcm_digital_playback;
spec->stream_digital_capture = &alc262_pcm_digital_capture;
if (!spec->adc_nids && spec->input_mux) {
int i;
for (i = 0; i < spec->input_mux->num_items; i++) {
if (spec->input_mux->items[i].index >= 9)
break;
}
if (i < spec->input_mux->num_items) {
spec->adc_nids = alc262_dmic_adc_nids;
spec->num_adc_nids = 1;
spec->capsrc_nids = alc262_dmic_capsrc_nids;
} else {
unsigned int wcap = get_wcaps(codec, 0x07);
wcap = get_wcaps_type(wcap);
if (wcap != AC_WID_AUD_IN) {
spec->adc_nids = alc262_adc_nids_alt;
spec->num_adc_nids =
ARRAY_SIZE(alc262_adc_nids_alt);
spec->capsrc_nids = alc262_capsrc_nids_alt;
} else {
spec->adc_nids = alc262_adc_nids;
spec->num_adc_nids =
ARRAY_SIZE(alc262_adc_nids);
spec->capsrc_nids = alc262_capsrc_nids;
}
}
}
if (!spec->cap_mixer && !spec->no_analog)
set_capture_mixer(codec);
if (!spec->no_analog && has_cdefine_beep(codec))
set_beep_amp(spec, 0x0b, 0x05, HDA_INPUT);
alc_apply_fixup(codec, ALC_FIXUP_ACT_PROBE);
spec->vmaster_nid = 0x0c;
codec->patch_ops = alc_patch_ops;
if (board_config == ALC262_AUTO)
spec->init_hook = alc262_auto_init;
spec->shutup = alc_eapd_shutup;
alc_init_jacks(codec);
#ifdef CONFIG_SND_HDA_POWER_SAVE
if (!spec->loopback.amplist)
spec->loopback.amplist = alc262_loopbacks;
#endif
return 0;
}
static void alc268_acer_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x14;
spec->autocfg.speaker_pins[0] = 0x15;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_AMP;
}
static void alc268_acer_lc_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x15;
spec->autocfg.speaker_pins[0] = 0x14;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_AMP;
spec->ext_mic.pin = 0x18;
spec->ext_mic.mux_idx = 0;
spec->int_mic.pin = 0x12;
spec->int_mic.mux_idx = 6;
spec->auto_mic = 1;
}
static void alc268_dell_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x15;
spec->autocfg.speaker_pins[0] = 0x14;
spec->ext_mic.pin = 0x18;
spec->ext_mic.mux_idx = 0;
spec->int_mic.pin = 0x19;
spec->int_mic.mux_idx = 1;
spec->auto_mic = 1;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_PIN;
}
static void alc267_quanta_il1_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x15;
spec->autocfg.speaker_pins[0] = 0x14;
spec->ext_mic.pin = 0x18;
spec->ext_mic.mux_idx = 0;
spec->int_mic.pin = 0x19;
spec->int_mic.mux_idx = 1;
spec->auto_mic = 1;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_PIN;
}
static int alc268_new_analog_output(struct alc_spec *spec, hda_nid_t nid,
const char *ctlname, int idx)
{
hda_nid_t dac;
int err;
switch (nid) {
case 0x14:
case 0x16:
dac = 0x02;
break;
case 0x15:
case 0x1a:
case 0x1b:
case 0x21:
dac = 0x03;
break;
default:
snd_printd(KERN_WARNING "hda_codec: "
"ignoring pin 0x%x as unknown\n", nid);
return 0;
}
if (spec->multiout.dac_nids[0] != dac &&
spec->multiout.dac_nids[1] != dac) {
err = add_pb_vol_ctrl(spec, ALC_CTL_WIDGET_VOL, ctlname,
HDA_COMPOSE_AMP_VAL(dac, 3, idx,
HDA_OUTPUT));
if (err < 0)
return err;
spec->private_dac_nids[spec->multiout.num_dacs++] = dac;
}
if (nid != 0x16)
err = add_pb_sw_ctrl(spec, ALC_CTL_WIDGET_MUTE, ctlname,
HDA_COMPOSE_AMP_VAL(nid, 3, idx, HDA_OUTPUT));
else
err = add_pb_sw_ctrl(spec, ALC_CTL_WIDGET_MUTE, ctlname,
HDA_COMPOSE_AMP_VAL(nid, 2, idx, HDA_OUTPUT));
if (err < 0)
return err;
return 0;
}
static int alc268_auto_create_multi_out_ctls(struct alc_spec *spec,
const struct auto_pin_cfg *cfg)
{
hda_nid_t nid;
int err;
spec->multiout.dac_nids = spec->private_dac_nids;
nid = cfg->line_out_pins[0];
if (nid) {
const char *name;
if (cfg->line_out_type == AUTO_PIN_SPEAKER_OUT)
name = "Speaker";
else
name = "Front";
err = alc268_new_analog_output(spec, nid, name, 0);
if (err < 0)
return err;
}
nid = cfg->speaker_pins[0];
if (nid == 0x1d) {
err = add_pb_vol_ctrl(spec, ALC_CTL_WIDGET_VOL, "Speaker",
HDA_COMPOSE_AMP_VAL(nid, 3, 0, HDA_INPUT));
if (err < 0)
return err;
} else if (nid) {
err = alc268_new_analog_output(spec, nid, "Speaker", 0);
if (err < 0)
return err;
}
nid = cfg->hp_pins[0];
if (nid) {
err = alc268_new_analog_output(spec, nid, "Headphone", 0);
if (err < 0)
return err;
}
nid = cfg->line_out_pins[1] | cfg->line_out_pins[2];
if (nid == 0x16) {
err = add_pb_sw_ctrl(spec, ALC_CTL_WIDGET_MUTE, "Mono",
HDA_COMPOSE_AMP_VAL(nid, 2, 0, HDA_OUTPUT));
if (err < 0)
return err;
}
return 0;
}
static int alc268_auto_create_input_ctls(struct hda_codec *codec,
const struct auto_pin_cfg *cfg)
{
return alc_auto_create_input_ctls(codec, cfg, 0, 0x23, 0x24);
}
static void alc268_auto_set_output_and_unmute(struct hda_codec *codec,
hda_nid_t nid, int pin_type)
{
int idx;
alc_set_pin_output(codec, nid, pin_type);
if (nid == 0x14 || nid == 0x16)
idx = 0;
else
idx = 1;
snd_hda_codec_write(codec, nid, 0, AC_VERB_SET_CONNECT_SEL, idx);
}
static void alc268_auto_init_multi_out(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
int i;
for (i = 0; i < spec->autocfg.line_outs; i++) {
hda_nid_t nid = spec->autocfg.line_out_pins[i];
int pin_type = get_pin_type(spec->autocfg.line_out_type);
alc268_auto_set_output_and_unmute(codec, nid, pin_type);
}
}
static void alc268_auto_init_hp_out(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
hda_nid_t pin;
int i;
for (i = 0; i < spec->autocfg.hp_outs; i++) {
pin = spec->autocfg.hp_pins[i];
alc268_auto_set_output_and_unmute(codec, pin, PIN_HP);
}
for (i = 0; i < spec->autocfg.speaker_outs; i++) {
pin = spec->autocfg.speaker_pins[i];
alc268_auto_set_output_and_unmute(codec, pin, PIN_OUT);
}
if (spec->autocfg.mono_out_pin)
snd_hda_codec_write(codec, spec->autocfg.mono_out_pin, 0,
AC_VERB_SET_PIN_WIDGET_CONTROL, PIN_OUT);
}
static void alc268_auto_init_mono_speaker_out(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
hda_nid_t speaker_nid = spec->autocfg.speaker_pins[0];
hda_nid_t hp_nid = spec->autocfg.hp_pins[0];
hda_nid_t line_nid = spec->autocfg.line_out_pins[0];
unsigned int dac_vol1, dac_vol2;
if (line_nid == 0x1d || speaker_nid == 0x1d) {
snd_hda_codec_write(codec, speaker_nid, 0,
AC_VERB_SET_PIN_WIDGET_CONTROL, PIN_OUT);
snd_hda_codec_write(codec, 0x0f, 0,
AC_VERB_SET_AMP_GAIN_MUTE,
AMP_IN_UNMUTE(1));
snd_hda_codec_write(codec, 0x10, 0,
AC_VERB_SET_AMP_GAIN_MUTE,
AMP_IN_UNMUTE(1));
} else {
snd_hda_codec_write(codec, 0x0f, 0,
AC_VERB_SET_AMP_GAIN_MUTE, AMP_IN_MUTE(1));
snd_hda_codec_write(codec, 0x10, 0,
AC_VERB_SET_AMP_GAIN_MUTE, AMP_IN_MUTE(1));
}
dac_vol1 = dac_vol2 = 0xb000 | 0x40;
if (line_nid == 0x14)
dac_vol2 = AMP_OUT_ZERO;
else if (line_nid == 0x15)
dac_vol1 = AMP_OUT_ZERO;
if (hp_nid == 0x14)
dac_vol2 = AMP_OUT_ZERO;
else if (hp_nid == 0x15)
dac_vol1 = AMP_OUT_ZERO;
if (line_nid != 0x16 || hp_nid != 0x16 ||
spec->autocfg.line_out_pins[1] != 0x16 ||
spec->autocfg.line_out_pins[2] != 0x16)
dac_vol1 = dac_vol2 = AMP_OUT_ZERO;
snd_hda_codec_write(codec, 0x02, 0,
AC_VERB_SET_AMP_GAIN_MUTE, dac_vol1);
snd_hda_codec_write(codec, 0x03, 0,
AC_VERB_SET_AMP_GAIN_MUTE, dac_vol2);
}
static int alc268_parse_auto_config(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
int err;
static const hda_nid_t alc268_ignore[] = { 0 };
err = snd_hda_parse_pin_def_config(codec, &spec->autocfg,
alc268_ignore);
if (err < 0)
return err;
if (!spec->autocfg.line_outs) {
if (spec->autocfg.dig_outs || spec->autocfg.dig_in_pin) {
spec->multiout.max_channels = 2;
spec->no_analog = 1;
goto dig_only;
}
return 0;
}
err = alc268_auto_create_multi_out_ctls(spec, &spec->autocfg);
if (err < 0)
return err;
err = alc268_auto_create_input_ctls(codec, &spec->autocfg);
if (err < 0)
return err;
spec->multiout.max_channels = 2;
dig_only:
alc_auto_parse_digital(codec);
if (spec->kctls.list)
add_mixer(spec, spec->kctls.list);
if (!spec->no_analog && spec->autocfg.speaker_pins[0] != 0x1d)
add_mixer(spec, alc268_beep_mixer);
add_verb(spec, alc268_volume_init_verbs);
spec->num_mux_defs = 2;
spec->input_mux = &spec->private_imux[0];
err = alc_auto_add_mic_boost(codec);
if (err < 0)
return err;
alc_ssid_check(codec, 0x15, 0x1b, 0x14, 0);
return 1;
}
static void alc268_auto_init(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
alc268_auto_init_multi_out(codec);
alc268_auto_init_hp_out(codec);
alc268_auto_init_mono_speaker_out(codec);
alc268_auto_init_analog_input(codec);
alc268_auto_init_input_src(codec);
alc_auto_init_digital(codec);
if (spec->unsol_event)
alc_inithook(codec);
}
static int patch_alc268(struct hda_codec *codec)
{
struct alc_spec *spec;
int board_config;
int i, has_beep, err;
spec = kzalloc(sizeof(*spec), GFP_KERNEL);
if (spec == NULL)
return -ENOMEM;
codec->spec = spec;
board_config = snd_hda_check_board_config(codec, ALC268_MODEL_LAST,
alc268_models,
alc268_cfg_tbl);
if (board_config < 0 || board_config >= ALC268_MODEL_LAST)
board_config = snd_hda_check_board_codec_sid_config(codec,
ALC268_MODEL_LAST, alc268_models, alc268_ssid_cfg_tbl);
if (board_config < 0 || board_config >= ALC268_MODEL_LAST) {
printk(KERN_INFO "hda_codec: %s: BIOS auto-probing.\n",
codec->chip_name);
board_config = ALC268_AUTO;
}
if (board_config == ALC268_AUTO) {
err = alc268_parse_auto_config(codec);
if (err < 0) {
alc_free(codec);
return err;
} else if (!err) {
printk(KERN_INFO
"hda_codec: Cannot set up configuration "
"from BIOS. Using base mode...\n");
board_config = ALC268_3ST;
}
}
if (board_config != ALC268_AUTO)
setup_preset(codec, &alc268_presets[board_config]);
spec->stream_analog_playback = &alc268_pcm_analog_playback;
spec->stream_analog_capture = &alc268_pcm_analog_capture;
spec->stream_analog_alt_capture = &alc268_pcm_analog_alt_capture;
spec->stream_digital_playback = &alc268_pcm_digital_playback;
has_beep = 0;
for (i = 0; i < spec->num_mixers; i++) {
if (spec->mixers[i] == alc268_beep_mixer) {
has_beep = 1;
break;
}
}
if (has_beep) {
err = snd_hda_attach_beep_device(codec, 0x1);
if (err < 0) {
alc_free(codec);
return err;
}
if (!query_amp_caps(codec, 0x1d, HDA_INPUT))
snd_hda_override_amp_caps(codec, 0x1d, HDA_INPUT,
(0x0c << AC_AMPCAP_OFFSET_SHIFT) |
(0x0c << AC_AMPCAP_NUM_STEPS_SHIFT) |
(0x07 << AC_AMPCAP_STEP_SIZE_SHIFT) |
(0 << AC_AMPCAP_MUTE_SHIFT));
}
if (!spec->no_analog && !spec->adc_nids && spec->input_mux) {
unsigned int wcap = get_wcaps(codec, 0x07);
spec->capsrc_nids = alc268_capsrc_nids;
wcap = get_wcaps_type(wcap);
if (spec->auto_mic ||
wcap != AC_WID_AUD_IN || spec->input_mux->num_items == 1) {
spec->adc_nids = alc268_adc_nids_alt;
spec->num_adc_nids = ARRAY_SIZE(alc268_adc_nids_alt);
if (spec->auto_mic)
fixup_automic_adc(codec);
if (spec->auto_mic || spec->input_mux->num_items == 1)
add_mixer(spec, alc268_capture_nosrc_mixer);
else
add_mixer(spec, alc268_capture_alt_mixer);
} else {
spec->adc_nids = alc268_adc_nids;
spec->num_adc_nids = ARRAY_SIZE(alc268_adc_nids);
add_mixer(spec, alc268_capture_mixer);
}
}
spec->vmaster_nid = 0x02;
codec->patch_ops = alc_patch_ops;
if (board_config == ALC268_AUTO)
spec->init_hook = alc268_auto_init;
spec->shutup = alc_eapd_shutup;
alc_init_jacks(codec);
return 0;
}
static void alc269_quanta_fl1_speaker_automute(struct hda_codec *codec)
{
alc_hp_automute(codec);
snd_hda_codec_write(codec, 0x20, 0,
AC_VERB_SET_COEF_INDEX, 0x0c);
snd_hda_codec_write(codec, 0x20, 0,
AC_VERB_SET_PROC_COEF, 0x680);
snd_hda_codec_write(codec, 0x20, 0,
AC_VERB_SET_COEF_INDEX, 0x0c);
snd_hda_codec_write(codec, 0x20, 0,
AC_VERB_SET_PROC_COEF, 0x480);
}
static void alc269_lifebook_mic_autoswitch(struct hda_codec *codec)
{
unsigned int present_laptop;
unsigned int present_dock;
present_laptop = snd_hda_jack_detect(codec, 0x18);
present_dock = snd_hda_jack_detect(codec, 0x1b);
if (present_dock)
snd_hda_codec_write(codec, 0x23, 0,
AC_VERB_SET_CONNECT_SEL, 0x3);
if (present_laptop)
snd_hda_codec_write(codec, 0x23, 0,
AC_VERB_SET_CONNECT_SEL, 0x0);
if (!present_dock && !present_laptop)
snd_hda_codec_write(codec, 0x23, 0,
AC_VERB_SET_CONNECT_SEL, 0x1);
}
static void alc269_quanta_fl1_unsol_event(struct hda_codec *codec,
unsigned int res)
{
switch (res >> 26) {
case ALC880_HP_EVENT:
alc269_quanta_fl1_speaker_automute(codec);
break;
case ALC880_MIC_EVENT:
alc_mic_automute(codec);
break;
}
}
static void alc269_lifebook_unsol_event(struct hda_codec *codec,
unsigned int res)
{
if ((res >> 26) == ALC880_HP_EVENT)
alc269_lifebook_speaker_automute(codec);
if ((res >> 26) == ALC880_MIC_EVENT)
alc269_lifebook_mic_autoswitch(codec);
}
static void alc269_quanta_fl1_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x15;
spec->autocfg.speaker_pins[0] = 0x14;
spec->automute_mixer_nid[0] = 0x0c;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_MIXER;
spec->ext_mic.pin = 0x18;
spec->ext_mic.mux_idx = 0;
spec->int_mic.pin = 0x19;
spec->int_mic.mux_idx = 1;
spec->auto_mic = 1;
}
static void alc269_quanta_fl1_init_hook(struct hda_codec *codec)
{
alc269_quanta_fl1_speaker_automute(codec);
alc_mic_automute(codec);
}
static void alc269_lifebook_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x15;
spec->autocfg.hp_pins[1] = 0x1a;
spec->autocfg.speaker_pins[0] = 0x14;
spec->automute_mixer_nid[0] = 0x0c;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_MIXER;
}
static void alc269_lifebook_init_hook(struct hda_codec *codec)
{
alc269_lifebook_speaker_automute(codec);
alc269_lifebook_mic_autoswitch(codec);
}
static void alc269_laptop_amic_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x15;
spec->autocfg.speaker_pins[0] = 0x14;
spec->automute_mixer_nid[0] = 0x0c;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_MIXER;
spec->ext_mic.pin = 0x18;
spec->ext_mic.mux_idx = 0;
spec->int_mic.pin = 0x19;
spec->int_mic.mux_idx = 1;
spec->auto_mic = 1;
}
static void alc269_laptop_dmic_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x15;
spec->autocfg.speaker_pins[0] = 0x14;
spec->automute_mixer_nid[0] = 0x0c;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_MIXER;
spec->ext_mic.pin = 0x18;
spec->ext_mic.mux_idx = 0;
spec->int_mic.pin = 0x12;
spec->int_mic.mux_idx = 5;
spec->auto_mic = 1;
}
static void alc269vb_laptop_amic_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x21;
spec->autocfg.speaker_pins[0] = 0x14;
spec->automute_mixer_nid[0] = 0x0c;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_MIXER;
spec->ext_mic.pin = 0x18;
spec->ext_mic.mux_idx = 0;
spec->int_mic.pin = 0x19;
spec->int_mic.mux_idx = 1;
spec->auto_mic = 1;
}
static void alc269vb_laptop_dmic_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x21;
spec->autocfg.speaker_pins[0] = 0x14;
spec->automute_mixer_nid[0] = 0x0c;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_MIXER;
spec->ext_mic.pin = 0x18;
spec->ext_mic.mux_idx = 0;
spec->int_mic.pin = 0x12;
spec->int_mic.mux_idx = 6;
spec->auto_mic = 1;
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
static int alc275_setup_dual_adc(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
if (codec->vendor_id != 0x10ec0275 || !spec->auto_mic)
return 0;
if ((spec->ext_mic.pin >= 0x18 && spec->int_mic.pin <= 0x13) ||
(spec->ext_mic.pin <= 0x12 && spec->int_mic.pin >= 0x18)) {
if (spec->ext_mic.pin <= 0x12) {
spec->private_adc_nids[0] = 0x08;
spec->private_adc_nids[1] = 0x11;
spec->private_capsrc_nids[0] = 0x23;
spec->private_capsrc_nids[1] = 0x22;
} else {
spec->private_adc_nids[0] = 0x11;
spec->private_adc_nids[1] = 0x08;
spec->private_capsrc_nids[0] = 0x22;
spec->private_capsrc_nids[1] = 0x23;
}
spec->adc_nids = spec->private_adc_nids;
spec->capsrc_nids = spec->private_capsrc_nids;
spec->num_adc_nids = 2;
spec->dual_adc_switch = 1;
snd_printdd("realtek: enabling dual ADC switchg (%02x:%02x)\n",
spec->adc_nids[0], spec->adc_nids[1]);
return 1;
}
return 0;
}
static int alc269_parse_auto_config(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
int err;
static const hda_nid_t alc269_ignore[] = { 0x1d, 0 };
err = snd_hda_parse_pin_def_config(codec, &spec->autocfg,
alc269_ignore);
if (err < 0)
return err;
err = alc269_auto_create_multi_out_ctls(spec, &spec->autocfg);
if (err < 0)
return err;
if (spec->codec_variant == ALC269_TYPE_NORMAL)
err = alc269_auto_create_input_ctls(codec, &spec->autocfg);
else
err = alc_auto_create_input_ctls(codec, &spec->autocfg, 0,
0x22, 0);
if (err < 0)
return err;
spec->multiout.max_channels = spec->multiout.num_dacs * 2;
alc_auto_parse_digital(codec);
if (spec->kctls.list)
add_mixer(spec, spec->kctls.list);
if (spec->codec_variant != ALC269_TYPE_NORMAL) {
add_verb(spec, alc269vb_init_verbs);
alc_ssid_check(codec, 0, 0x1b, 0x14, 0x21);
} else {
add_verb(spec, alc269_init_verbs);
alc_ssid_check(codec, 0x15, 0x1b, 0x14, 0);
}
spec->num_mux_defs = 1;
spec->input_mux = &spec->private_imux[0];
if (!alc275_setup_dual_adc(codec))
fillup_priv_adc_nids(codec, alc269_adc_candidates,
sizeof(alc269_adc_candidates));
err = alc_auto_add_mic_boost(codec);
if (err < 0)
return err;
if (!spec->cap_mixer && !spec->no_analog)
set_capture_mixer(codec);
return 1;
}
static void alc269_auto_init(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
alc269_auto_init_multi_out(codec);
alc269_auto_init_hp_out(codec);
alc269_auto_init_analog_input(codec);
if (!spec->dual_adc_switch)
alc269_auto_init_input_src(codec);
alc_auto_init_digital(codec);
if (spec->unsol_event)
alc_inithook(codec);
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
if ((alc_read_coef_idx(codec, 0) & 0x00ff) == 0x017)
alc269_toggle_power_output(codec, 0);
if ((alc_read_coef_idx(codec, 0) & 0x00ff) == 0x018) {
alc269_toggle_power_output(codec, 0);
msleep(150);
}
}
static int alc269_resume(struct hda_codec *codec)
{
if ((alc_read_coef_idx(codec, 0) & 0x00ff) == 0x018) {
alc269_toggle_power_output(codec, 0);
msleep(150);
}
codec->patch_ops.init(codec);
if ((alc_read_coef_idx(codec, 0) & 0x00ff) == 0x017) {
alc269_toggle_power_output(codec, 1);
msleep(200);
}
if ((alc_read_coef_idx(codec, 0) & 0x00ff) == 0x018)
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
static int alc269_fill_coef(struct hda_codec *codec)
{
int val;
if ((alc_read_coef_idx(codec, 0) & 0x00ff) < 0x015) {
alc_write_coef_idx(codec, 0xf, 0x960b);
alc_write_coef_idx(codec, 0xe, 0x8817);
}
if ((alc_read_coef_idx(codec, 0) & 0x00ff) == 0x016) {
alc_write_coef_idx(codec, 0xf, 0x960b);
alc_write_coef_idx(codec, 0xe, 0x8814);
}
if ((alc_read_coef_idx(codec, 0) & 0x00ff) == 0x017) {
val = alc_read_coef_idx(codec, 0x04);
alc_write_coef_idx(codec, 0x04, val | (1<<11));
}
if ((alc_read_coef_idx(codec, 0) & 0x00ff) == 0x018) {
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
int board_config, coef;
int err;
spec = kzalloc(sizeof(*spec), GFP_KERNEL);
if (spec == NULL)
return -ENOMEM;
codec->spec = spec;
alc_auto_parse_customize_define(codec);
if (codec->vendor_id == 0x10ec0269) {
coef = alc_read_coef_idx(codec, 0);
if ((coef & 0x00f0) == 0x0010) {
if (codec->bus->pci->subsystem_vendor == 0x1025 &&
spec->cdefine.platform_type == 1) {
alc_codec_rename(codec, "ALC271X");
spec->codec_variant = ALC269_TYPE_ALC271X;
} else if ((coef & 0xf000) == 0x1000) {
spec->codec_variant = ALC269_TYPE_ALC270;
} else if ((coef & 0xf000) == 0x2000) {
alc_codec_rename(codec, "ALC259");
spec->codec_variant = ALC269_TYPE_ALC259;
} else if ((coef & 0xf000) == 0x3000) {
alc_codec_rename(codec, "ALC258");
spec->codec_variant = ALC269_TYPE_ALC258;
} else {
alc_codec_rename(codec, "ALC269VB");
spec->codec_variant = ALC269_TYPE_ALC269VB;
}
} else
alc_fix_pll_init(codec, 0x20, 0x04, 15);
alc269_fill_coef(codec);
}
board_config = snd_hda_check_board_config(codec, ALC269_MODEL_LAST,
alc269_models,
alc269_cfg_tbl);
if (board_config < 0) {
printk(KERN_INFO "hda_codec: %s: BIOS auto-probing.\n",
codec->chip_name);
board_config = ALC269_AUTO;
}
if (board_config == ALC269_AUTO) {
alc_pick_fixup(codec, NULL, alc269_fixup_tbl, alc269_fixups);
alc_apply_fixup(codec, ALC_FIXUP_ACT_PRE_PROBE);
}
if (board_config == ALC269_AUTO) {
err = alc269_parse_auto_config(codec);
if (err < 0) {
alc_free(codec);
return err;
} else if (!err) {
printk(KERN_INFO
"hda_codec: Cannot set up configuration "
"from BIOS. Using base mode...\n");
board_config = ALC269_BASIC;
}
}
if (has_cdefine_beep(codec)) {
err = snd_hda_attach_beep_device(codec, 0x1);
if (err < 0) {
alc_free(codec);
return err;
}
}
if (board_config != ALC269_AUTO)
setup_preset(codec, &alc269_presets[board_config]);
if (board_config == ALC269_QUANTA_FL1) {
spec->stream_analog_playback = &alc269_44k_pcm_analog_playback;
spec->stream_analog_capture = &alc269_44k_pcm_analog_capture;
} else if (spec->dual_adc_switch) {
spec->stream_analog_playback = &alc269_pcm_analog_playback;
spec->stream_analog_capture = &dualmic_pcm_analog_capture;
} else {
spec->stream_analog_playback = &alc269_pcm_analog_playback;
spec->stream_analog_capture = &alc269_pcm_analog_capture;
}
spec->stream_digital_playback = &alc269_pcm_digital_playback;
spec->stream_digital_capture = &alc269_pcm_digital_capture;
if (!spec->adc_nids) {
if (spec->codec_variant == ALC269_TYPE_NORMAL) {
spec->adc_nids = alc269_adc_nids;
spec->num_adc_nids = ARRAY_SIZE(alc269_adc_nids);
spec->capsrc_nids = alc269_capsrc_nids;
} else {
spec->adc_nids = alc269vb_adc_nids;
spec->num_adc_nids = ARRAY_SIZE(alc269vb_adc_nids);
spec->capsrc_nids = alc269vb_capsrc_nids;
}
}
if (!spec->cap_mixer)
set_capture_mixer(codec);
if (has_cdefine_beep(codec))
set_beep_amp(spec, 0x0b, 0x04, HDA_INPUT);
alc_apply_fixup(codec, ALC_FIXUP_ACT_PROBE);
spec->vmaster_nid = 0x02;
codec->patch_ops = alc_patch_ops;
#ifdef SND_HDA_NEEDS_RESUME
codec->patch_ops.resume = alc269_resume;
#endif
if (board_config == ALC269_AUTO)
spec->init_hook = alc269_auto_init;
spec->shutup = alc269_shutup;
alc_init_jacks(codec);
#ifdef CONFIG_SND_HDA_POWER_SAVE
if (!spec->loopback.amplist)
spec->loopback.amplist = alc269_loopbacks;
if (alc269_mic2_for_mute_led(codec))
codec->patch_ops.check_power_status = alc269_mic2_mute_check_ps;
#endif
return 0;
}
static void alc861_toshiba_automute(struct hda_codec *codec)
{
unsigned int present = snd_hda_jack_detect(codec, 0x0f);
snd_hda_codec_amp_stereo(codec, 0x16, HDA_INPUT, 0,
HDA_AMP_MUTE, present ? HDA_AMP_MUTE : 0);
snd_hda_codec_amp_stereo(codec, 0x1a, HDA_INPUT, 3,
HDA_AMP_MUTE, present ? 0 : HDA_AMP_MUTE);
}
static void alc861_toshiba_unsol_event(struct hda_codec *codec,
unsigned int res)
{
if ((res >> 26) == ALC880_HP_EVENT)
alc861_toshiba_automute(codec);
}
static hda_nid_t alc861_look_for_dac(struct hda_codec *codec, hda_nid_t pin)
{
struct alc_spec *spec = codec->spec;
hda_nid_t mix, srcs[5];
int i, j, num;
if (snd_hda_get_connections(codec, pin, &mix, 1) != 1)
return 0;
num = snd_hda_get_connections(codec, mix, srcs, ARRAY_SIZE(srcs));
if (num < 0)
return 0;
for (i = 0; i < num; i++) {
unsigned int type;
type = get_wcaps_type(get_wcaps(codec, srcs[i]));
if (type != AC_WID_AUD_OUT)
continue;
for (j = 0; j < spec->multiout.num_dacs; j++)
if (spec->multiout.dac_nids[j] == srcs[i])
break;
if (j >= spec->multiout.num_dacs)
return srcs[i];
}
return 0;
}
static int alc861_auto_fill_dac_nids(struct hda_codec *codec,
const struct auto_pin_cfg *cfg)
{
struct alc_spec *spec = codec->spec;
int i;
hda_nid_t nid, dac;
spec->multiout.dac_nids = spec->private_dac_nids;
for (i = 0; i < cfg->line_outs; i++) {
nid = cfg->line_out_pins[i];
dac = alc861_look_for_dac(codec, nid);
if (!dac)
continue;
spec->private_dac_nids[spec->multiout.num_dacs++] = dac;
}
return 0;
}
static int __alc861_create_out_sw(struct hda_codec *codec, const char *pfx,
hda_nid_t nid, int idx, unsigned int chs)
{
return __add_pb_sw_ctrl(codec->spec, ALC_CTL_WIDGET_MUTE, pfx, idx,
HDA_COMPOSE_AMP_VAL(nid, chs, 0, HDA_OUTPUT));
}
static int alc861_auto_create_multi_out_ctls(struct hda_codec *codec,
const struct auto_pin_cfg *cfg)
{
struct alc_spec *spec = codec->spec;
static const char * const chname[4] = {
"Front", "Surround", NULL , "Side"
};
const char *pfx = alc_get_line_out_pfx(spec, true);
hda_nid_t nid;
int i, err, noutputs;
noutputs = cfg->line_outs;
if (spec->multi_ios > 0)
noutputs += spec->multi_ios;
for (i = 0; i < noutputs; i++) {
nid = spec->multiout.dac_nids[i];
if (!nid)
continue;
if (!pfx && i == 2) {
err = alc861_create_out_sw(codec, "Center", nid, 1);
if (err < 0)
return err;
err = alc861_create_out_sw(codec, "LFE", nid, 2);
if (err < 0)
return err;
} else {
const char *name = pfx;
int index = i;
if (!name) {
name = chname[i];
index = 0;
}
err = __alc861_create_out_sw(codec, name, nid, index, 3);
if (err < 0)
return err;
}
}
return 0;
}
static int alc861_auto_create_hp_ctls(struct hda_codec *codec, hda_nid_t pin)
{
struct alc_spec *spec = codec->spec;
int err;
hda_nid_t nid;
if (!pin)
return 0;
if ((pin >= 0x0b && pin <= 0x10) || pin == 0x1f || pin == 0x20) {
nid = alc861_look_for_dac(codec, pin);
if (nid) {
err = alc861_create_out_sw(codec, "Headphone", nid, 3);
if (err < 0)
return err;
spec->multiout.hp_nid = nid;
}
}
return 0;
}
static int alc861_auto_create_input_ctls(struct hda_codec *codec,
const struct auto_pin_cfg *cfg)
{
return alc_auto_create_input_ctls(codec, cfg, 0x15, 0x08, 0);
}
static void alc861_auto_set_output_and_unmute(struct hda_codec *codec,
hda_nid_t nid,
int pin_type, hda_nid_t dac)
{
hda_nid_t mix, srcs[5];
int i, num;
snd_hda_codec_write(codec, nid, 0, AC_VERB_SET_PIN_WIDGET_CONTROL,
pin_type);
snd_hda_codec_write(codec, dac, 0, AC_VERB_SET_AMP_GAIN_MUTE,
AMP_OUT_UNMUTE);
if (snd_hda_get_connections(codec, nid, &mix, 1) != 1)
return;
num = snd_hda_get_connections(codec, mix, srcs, ARRAY_SIZE(srcs));
if (num < 0)
return;
for (i = 0; i < num; i++) {
unsigned int mute;
if (srcs[i] == dac || srcs[i] == 0x15)
mute = AMP_IN_UNMUTE(i);
else
mute = AMP_IN_MUTE(i);
snd_hda_codec_write(codec, mix, 0, AC_VERB_SET_AMP_GAIN_MUTE,
mute);
}
}
static void alc861_auto_init_multi_out(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
int i;
for (i = 0; i < spec->autocfg.line_outs; i++) {
hda_nid_t nid = spec->autocfg.line_out_pins[i];
int pin_type = get_pin_type(spec->autocfg.line_out_type);
if (nid)
alc861_auto_set_output_and_unmute(codec, nid, pin_type,
spec->multiout.dac_nids[i]);
}
}
static void alc861_auto_init_hp_out(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
if (spec->autocfg.hp_outs)
alc861_auto_set_output_and_unmute(codec,
spec->autocfg.hp_pins[0],
PIN_HP,
spec->multiout.hp_nid);
if (spec->autocfg.speaker_outs)
alc861_auto_set_output_and_unmute(codec,
spec->autocfg.speaker_pins[0],
PIN_OUT,
spec->multiout.dac_nids[0]);
}
static void alc861_auto_init_analog_input(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
struct auto_pin_cfg *cfg = &spec->autocfg;
int i;
for (i = 0; i < cfg->num_inputs; i++) {
hda_nid_t nid = cfg->inputs[i].pin;
if (nid >= 0x0c && nid <= 0x11)
alc_set_input_pin(codec, nid, cfg->inputs[i].type);
}
}
static int alc861_parse_auto_config(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
int err;
static const hda_nid_t alc861_ignore[] = { 0x1d, 0 };
err = snd_hda_parse_pin_def_config(codec, &spec->autocfg,
alc861_ignore);
if (err < 0)
return err;
if (!spec->autocfg.line_outs)
return 0;
err = alc861_auto_fill_dac_nids(codec, &spec->autocfg);
if (err < 0)
return err;
err = alc_auto_add_multi_channel_mode(codec);
if (err < 0)
return err;
err = alc861_auto_create_multi_out_ctls(codec, &spec->autocfg);
if (err < 0)
return err;
err = alc861_auto_create_hp_ctls(codec, spec->autocfg.hp_pins[0]);
if (err < 0)
return err;
err = alc861_auto_create_input_ctls(codec, &spec->autocfg);
if (err < 0)
return err;
spec->multiout.max_channels = spec->multiout.num_dacs * 2;
alc_auto_parse_digital(codec);
if (spec->kctls.list)
add_mixer(spec, spec->kctls.list);
add_verb(spec, alc861_auto_init_verbs);
spec->num_mux_defs = 1;
spec->input_mux = &spec->private_imux[0];
spec->adc_nids = alc861_adc_nids;
spec->num_adc_nids = ARRAY_SIZE(alc861_adc_nids);
set_capture_mixer(codec);
alc_ssid_check(codec, 0x0e, 0x0f, 0x0b, 0);
return 1;
}
static void alc861_auto_init(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
alc861_auto_init_multi_out(codec);
alc861_auto_init_hp_out(codec);
alc861_auto_init_analog_input(codec);
alc_auto_init_digital(codec);
if (spec->unsol_event)
alc_inithook(codec);
}
static int patch_alc861(struct hda_codec *codec)
{
struct alc_spec *spec;
int board_config;
int err;
spec = kzalloc(sizeof(*spec), GFP_KERNEL);
if (spec == NULL)
return -ENOMEM;
codec->spec = spec;
board_config = snd_hda_check_board_config(codec, ALC861_MODEL_LAST,
alc861_models,
alc861_cfg_tbl);
if (board_config < 0) {
printk(KERN_INFO "hda_codec: %s: BIOS auto-probing.\n",
codec->chip_name);
board_config = ALC861_AUTO;
}
if (board_config == ALC861_AUTO) {
alc_pick_fixup(codec, NULL, alc861_fixup_tbl, alc861_fixups);
alc_apply_fixup(codec, ALC_FIXUP_ACT_PRE_PROBE);
}
if (board_config == ALC861_AUTO) {
err = alc861_parse_auto_config(codec);
if (err < 0) {
alc_free(codec);
return err;
} else if (!err) {
printk(KERN_INFO
"hda_codec: Cannot set up configuration "
"from BIOS. Using base mode...\n");
board_config = ALC861_3ST_DIG;
}
}
err = snd_hda_attach_beep_device(codec, 0x23);
if (err < 0) {
alc_free(codec);
return err;
}
if (board_config != ALC861_AUTO)
setup_preset(codec, &alc861_presets[board_config]);
spec->stream_analog_playback = &alc861_pcm_analog_playback;
spec->stream_analog_capture = &alc861_pcm_analog_capture;
spec->stream_digital_playback = &alc861_pcm_digital_playback;
spec->stream_digital_capture = &alc861_pcm_digital_capture;
if (!spec->cap_mixer)
set_capture_mixer(codec);
set_beep_amp(spec, 0x23, 0, HDA_OUTPUT);
spec->vmaster_nid = 0x03;
alc_apply_fixup(codec, ALC_FIXUP_ACT_PROBE);
codec->patch_ops = alc_patch_ops;
if (board_config == ALC861_AUTO) {
spec->init_hook = alc861_auto_init;
#ifdef CONFIG_SND_HDA_POWER_SAVE
spec->power_hook = alc_power_eapd;
#endif
}
#ifdef CONFIG_SND_HDA_POWER_SAVE
if (!spec->loopback.amplist)
spec->loopback.amplist = alc861_loopbacks;
#endif
return 0;
}
static void alc861vd_lenovo_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x1b;
spec->autocfg.speaker_pins[0] = 0x14;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_AMP;
}
static void alc861vd_lenovo_init_hook(struct hda_codec *codec)
{
alc_hp_automute(codec);
alc88x_simple_mic_automute(codec);
}
static void alc861vd_lenovo_unsol_event(struct hda_codec *codec,
unsigned int res)
{
switch (res >> 26) {
case ALC880_MIC_EVENT:
alc88x_simple_mic_automute(codec);
break;
default:
alc_sku_unsol_event(codec, res);
break;
}
}
static void alc861vd_dallas_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x15;
spec->autocfg.speaker_pins[0] = 0x14;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_AMP;
}
static int alc861vd_auto_create_input_ctls(struct hda_codec *codec,
const struct auto_pin_cfg *cfg)
{
return alc_auto_create_input_ctls(codec, cfg, 0x0b, 0x22, 0);
}
static void alc861vd_auto_set_output_and_unmute(struct hda_codec *codec,
hda_nid_t nid, int pin_type, int dac_idx)
{
alc_set_pin_output(codec, nid, pin_type);
}
static void alc861vd_auto_init_multi_out(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
int i;
for (i = 0; i <= HDA_SIDE; i++) {
hda_nid_t nid = spec->autocfg.line_out_pins[i];
int pin_type = get_pin_type(spec->autocfg.line_out_type);
if (nid)
alc861vd_auto_set_output_and_unmute(codec, nid,
pin_type, i);
}
}
static void alc861vd_auto_init_hp_out(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
hda_nid_t pin;
pin = spec->autocfg.hp_pins[0];
if (pin)
alc861vd_auto_set_output_and_unmute(codec, pin, PIN_HP, 0);
pin = spec->autocfg.speaker_pins[0];
if (pin)
alc861vd_auto_set_output_and_unmute(codec, pin, PIN_OUT, 0);
}
static void alc861vd_auto_init_analog_input(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
struct auto_pin_cfg *cfg = &spec->autocfg;
int i;
for (i = 0; i < cfg->num_inputs; i++) {
hda_nid_t nid = cfg->inputs[i].pin;
if (alc_is_input_pin(codec, nid)) {
alc_set_input_pin(codec, nid, cfg->inputs[i].type);
if (nid != ALC861VD_PIN_CD_NID &&
(get_wcaps(codec, nid) & AC_WCAP_OUT_AMP))
snd_hda_codec_write(codec, nid, 0,
AC_VERB_SET_AMP_GAIN_MUTE,
AMP_OUT_MUTE);
}
}
}
static int alc861vd_auto_create_multi_out_ctls(struct alc_spec *spec,
const struct auto_pin_cfg *cfg)
{
static const char * const chname[4] = {
"Front", "Surround", "CLFE", "Side"
};
const char *pfx = alc_get_line_out_pfx(spec, true);
hda_nid_t nid_v, nid_s;
int i, err, noutputs;
noutputs = cfg->line_outs;
if (spec->multi_ios > 0)
noutputs += spec->multi_ios;
for (i = 0; i < noutputs; i++) {
if (!spec->multiout.dac_nids[i])
continue;
nid_v = alc861vd_idx_to_mixer_vol(
alc880_dac_to_idx(
spec->multiout.dac_nids[i]));
nid_s = alc861vd_idx_to_mixer_switch(
alc880_dac_to_idx(
spec->multiout.dac_nids[i]));
if (!pfx && i == 2) {
err = add_pb_vol_ctrl(spec, ALC_CTL_WIDGET_VOL,
"Center",
HDA_COMPOSE_AMP_VAL(nid_v, 1, 0,
HDA_OUTPUT));
if (err < 0)
return err;
err = add_pb_vol_ctrl(spec, ALC_CTL_WIDGET_VOL,
"LFE",
HDA_COMPOSE_AMP_VAL(nid_v, 2, 0,
HDA_OUTPUT));
if (err < 0)
return err;
err = add_pb_sw_ctrl(spec, ALC_CTL_BIND_MUTE,
"Center",
HDA_COMPOSE_AMP_VAL(nid_s, 1, 2,
HDA_INPUT));
if (err < 0)
return err;
err = add_pb_sw_ctrl(spec, ALC_CTL_BIND_MUTE,
"LFE",
HDA_COMPOSE_AMP_VAL(nid_s, 2, 2,
HDA_INPUT));
if (err < 0)
return err;
} else {
const char *name = pfx;
int index = i;
if (!name) {
name = chname[i];
index = 0;
}
err = __add_pb_vol_ctrl(spec, ALC_CTL_WIDGET_VOL,
name, index,
HDA_COMPOSE_AMP_VAL(nid_v, 3, 0,
HDA_OUTPUT));
if (err < 0)
return err;
err = __add_pb_sw_ctrl(spec, ALC_CTL_BIND_MUTE,
name, index,
HDA_COMPOSE_AMP_VAL(nid_s, 3, 2,
HDA_INPUT));
if (err < 0)
return err;
}
}
return 0;
}
static int alc861vd_auto_create_extra_out(struct alc_spec *spec,
hda_nid_t pin, const char *pfx)
{
hda_nid_t nid_v, nid_s;
int err;
if (!pin)
return 0;
if (alc880_is_fixed_pin(pin)) {
nid_v = alc880_idx_to_dac(alc880_fixed_pin_idx(pin));
if (!spec->multiout.hp_nid)
spec->multiout.hp_nid = nid_v;
else
spec->multiout.extra_out_nid[0] = nid_v;
nid_v = alc861vd_idx_to_mixer_vol(
alc880_fixed_pin_idx(pin));
nid_s = alc861vd_idx_to_mixer_switch(
alc880_fixed_pin_idx(pin));
err = add_pb_vol_ctrl(spec, ALC_CTL_WIDGET_VOL, pfx,
HDA_COMPOSE_AMP_VAL(nid_v, 3, 0, HDA_OUTPUT));
if (err < 0)
return err;
err = add_pb_sw_ctrl(spec, ALC_CTL_BIND_MUTE, pfx,
HDA_COMPOSE_AMP_VAL(nid_s, 3, 2, HDA_INPUT));
if (err < 0)
return err;
} else if (alc880_is_multi_pin(pin)) {
err = add_pb_sw_ctrl(spec, ALC_CTL_WIDGET_MUTE, pfx,
HDA_COMPOSE_AMP_VAL(pin, 3, 0, HDA_OUTPUT));
if (err < 0)
return err;
}
return 0;
}
static int alc861vd_parse_auto_config(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
int err;
static const hda_nid_t alc861vd_ignore[] = { 0x1d, 0 };
err = snd_hda_parse_pin_def_config(codec, &spec->autocfg,
alc861vd_ignore);
if (err < 0)
return err;
if (!spec->autocfg.line_outs)
return 0;
err = alc880_auto_fill_dac_nids(spec, &spec->autocfg);
if (err < 0)
return err;
err = alc_auto_add_multi_channel_mode(codec);
if (err < 0)
return err;
err = alc861vd_auto_create_multi_out_ctls(spec, &spec->autocfg);
if (err < 0)
return err;
err = alc861vd_auto_create_extra_out(spec,
spec->autocfg.speaker_pins[0],
"Speaker");
if (err < 0)
return err;
err = alc861vd_auto_create_extra_out(spec,
spec->autocfg.hp_pins[0],
"Headphone");
if (err < 0)
return err;
err = alc861vd_auto_create_input_ctls(codec, &spec->autocfg);
if (err < 0)
return err;
spec->multiout.max_channels = spec->multiout.num_dacs * 2;
alc_auto_parse_digital(codec);
if (spec->kctls.list)
add_mixer(spec, spec->kctls.list);
add_verb(spec, alc861vd_volume_init_verbs);
spec->num_mux_defs = 1;
spec->input_mux = &spec->private_imux[0];
err = alc_auto_add_mic_boost(codec);
if (err < 0)
return err;
alc_ssid_check(codec, 0x15, 0x1b, 0x14, 0);
return 1;
}
static void alc861vd_auto_init(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
alc861vd_auto_init_multi_out(codec);
alc861vd_auto_init_hp_out(codec);
alc861vd_auto_init_analog_input(codec);
alc861vd_auto_init_input_src(codec);
alc_auto_init_digital(codec);
if (spec->unsol_event)
alc_inithook(codec);
}
static int patch_alc861vd(struct hda_codec *codec)
{
struct alc_spec *spec;
int err, board_config;
spec = kzalloc(sizeof(*spec), GFP_KERNEL);
if (spec == NULL)
return -ENOMEM;
codec->spec = spec;
board_config = snd_hda_check_board_config(codec, ALC861VD_MODEL_LAST,
alc861vd_models,
alc861vd_cfg_tbl);
if (board_config < 0 || board_config >= ALC861VD_MODEL_LAST) {
printk(KERN_INFO "hda_codec: %s: BIOS auto-probing.\n",
codec->chip_name);
board_config = ALC861VD_AUTO;
}
if (board_config == ALC861VD_AUTO) {
alc_pick_fixup(codec, NULL, alc861vd_fixup_tbl, alc861vd_fixups);
alc_apply_fixup(codec, ALC_FIXUP_ACT_PRE_PROBE);
}
if (board_config == ALC861VD_AUTO) {
err = alc861vd_parse_auto_config(codec);
if (err < 0) {
alc_free(codec);
return err;
} else if (!err) {
printk(KERN_INFO
"hda_codec: Cannot set up configuration "
"from BIOS. Using base mode...\n");
board_config = ALC861VD_3ST;
}
}
err = snd_hda_attach_beep_device(codec, 0x23);
if (err < 0) {
alc_free(codec);
return err;
}
if (board_config != ALC861VD_AUTO)
setup_preset(codec, &alc861vd_presets[board_config]);
if (codec->vendor_id == 0x10ec0660) {
add_verb(spec, alc660vd_eapd_verbs);
}
spec->stream_analog_playback = &alc861vd_pcm_analog_playback;
spec->stream_analog_capture = &alc861vd_pcm_analog_capture;
spec->stream_digital_playback = &alc861vd_pcm_digital_playback;
spec->stream_digital_capture = &alc861vd_pcm_digital_capture;
if (!spec->adc_nids) {
spec->adc_nids = alc861vd_adc_nids;
spec->num_adc_nids = ARRAY_SIZE(alc861vd_adc_nids);
}
if (!spec->capsrc_nids)
spec->capsrc_nids = alc861vd_capsrc_nids;
set_capture_mixer(codec);
set_beep_amp(spec, 0x0b, 0x05, HDA_INPUT);
spec->vmaster_nid = 0x02;
alc_apply_fixup(codec, ALC_FIXUP_ACT_PROBE);
codec->patch_ops = alc_patch_ops;
if (board_config == ALC861VD_AUTO)
spec->init_hook = alc861vd_auto_init;
spec->shutup = alc_eapd_shutup;
#ifdef CONFIG_SND_HDA_POWER_SAVE
if (!spec->loopback.amplist)
spec->loopback.amplist = alc861vd_loopbacks;
#endif
return 0;
}
static void alc662_lenovo_101e_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x1b;
spec->autocfg.line_out_pins[0] = 0x14;
spec->autocfg.speaker_pins[0] = 0x15;
spec->automute = 1;
spec->detect_line = 1;
spec->automute_lines = 1;
spec->automute_mode = ALC_AUTOMUTE_AMP;
}
static void alc662_eeepc_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
alc262_hippo1_setup(codec);
spec->ext_mic.pin = 0x18;
spec->ext_mic.mux_idx = 0;
spec->int_mic.pin = 0x19;
spec->int_mic.mux_idx = 1;
spec->auto_mic = 1;
}
static void alc662_eeepc_ep20_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x14;
spec->autocfg.speaker_pins[0] = 0x1b;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_AMP;
}
static void alc663_m51va_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x21;
spec->autocfg.speaker_pins[0] = 0x14;
spec->automute_mixer_nid[0] = 0x0c;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_MIXER;
spec->ext_mic.pin = 0x18;
spec->ext_mic.mux_idx = 0;
spec->int_mic.pin = 0x12;
spec->int_mic.mux_idx = 9;
spec->auto_mic = 1;
}
static void alc663_mode1_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x21;
spec->autocfg.speaker_pins[0] = 0x14;
spec->automute_mixer_nid[0] = 0x0c;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_MIXER;
spec->ext_mic.pin = 0x18;
spec->ext_mic.mux_idx = 0;
spec->int_mic.pin = 0x19;
spec->int_mic.mux_idx = 1;
spec->auto_mic = 1;
}
static void alc662_mode2_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x1b;
spec->autocfg.speaker_pins[0] = 0x14;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_PIN;
spec->ext_mic.pin = 0x18;
spec->ext_mic.mux_idx = 0;
spec->int_mic.pin = 0x19;
spec->int_mic.mux_idx = 1;
spec->auto_mic = 1;
}
static void alc663_mode3_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x21;
spec->autocfg.hp_pins[0] = 0x15;
spec->autocfg.speaker_pins[0] = 0x14;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_PIN;
spec->ext_mic.pin = 0x18;
spec->ext_mic.mux_idx = 0;
spec->int_mic.pin = 0x19;
spec->int_mic.mux_idx = 1;
spec->auto_mic = 1;
}
static void alc663_mode4_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x21;
spec->autocfg.speaker_pins[0] = 0x14;
spec->autocfg.speaker_pins[1] = 0x16;
spec->automute_mixer_nid[0] = 0x0c;
spec->automute_mixer_nid[1] = 0x0e;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_MIXER;
spec->ext_mic.pin = 0x18;
spec->ext_mic.mux_idx = 0;
spec->int_mic.pin = 0x19;
spec->int_mic.mux_idx = 1;
spec->auto_mic = 1;
}
static void alc663_mode5_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x15;
spec->autocfg.speaker_pins[0] = 0x14;
spec->autocfg.speaker_pins[1] = 0x16;
spec->automute_mixer_nid[0] = 0x0c;
spec->automute_mixer_nid[1] = 0x0e;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_MIXER;
spec->ext_mic.pin = 0x18;
spec->ext_mic.mux_idx = 0;
spec->int_mic.pin = 0x19;
spec->int_mic.mux_idx = 1;
spec->auto_mic = 1;
}
static void alc663_mode6_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x1b;
spec->autocfg.hp_pins[0] = 0x15;
spec->autocfg.speaker_pins[0] = 0x14;
spec->automute_mixer_nid[0] = 0x0c;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_MIXER;
spec->ext_mic.pin = 0x18;
spec->ext_mic.mux_idx = 0;
spec->int_mic.pin = 0x19;
spec->int_mic.mux_idx = 1;
spec->auto_mic = 1;
}
static void alc663_mode7_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x1b;
spec->autocfg.hp_pins[0] = 0x21;
spec->autocfg.speaker_pins[0] = 0x14;
spec->autocfg.speaker_pins[0] = 0x17;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_PIN;
spec->ext_mic.pin = 0x18;
spec->ext_mic.mux_idx = 0;
spec->int_mic.pin = 0x19;
spec->int_mic.mux_idx = 1;
spec->auto_mic = 1;
}
static void alc663_mode8_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x21;
spec->autocfg.hp_pins[1] = 0x15;
spec->autocfg.speaker_pins[0] = 0x14;
spec->autocfg.speaker_pins[0] = 0x17;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_PIN;
spec->ext_mic.pin = 0x18;
spec->ext_mic.mux_idx = 0;
spec->int_mic.pin = 0x12;
spec->int_mic.mux_idx = 9;
spec->auto_mic = 1;
}
static void alc663_g71v_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x21;
spec->autocfg.line_out_pins[0] = 0x15;
spec->autocfg.speaker_pins[0] = 0x14;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_AMP;
spec->detect_line = 1;
spec->automute_lines = 1;
spec->ext_mic.pin = 0x18;
spec->ext_mic.mux_idx = 0;
spec->int_mic.pin = 0x12;
spec->int_mic.mux_idx = 9;
spec->auto_mic = 1;
}
static hda_nid_t alc_auto_mix_to_dac(struct hda_codec *codec, hda_nid_t nid)
{
hda_nid_t list[5];
int i, num;
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
int i, j, num;
pin = alc_go_down_to_selector(codec, pin);
num = snd_hda_get_connections(codec, pin, srcs, ARRAY_SIZE(srcs));
for (i = 0; i < num; i++) {
hda_nid_t nid = alc_auto_mix_to_dac(codec, srcs[i]);
if (!nid)
continue;
for (j = 0; j < spec->multiout.num_dacs; j++)
if (spec->multiout.dac_nids[j] == nid)
break;
if (j >= spec->multiout.num_dacs)
return nid;
}
return 0;
}
static int alc662_auto_fill_dac_nids(struct hda_codec *codec,
const struct auto_pin_cfg *cfg)
{
struct alc_spec *spec = codec->spec;
int i;
hda_nid_t dac;
spec->multiout.dac_nids = spec->private_dac_nids;
for (i = 0; i < cfg->line_outs; i++) {
dac = alc_auto_look_for_dac(codec, cfg->line_out_pins[i]);
if (!dac)
continue;
spec->private_dac_nids[spec->multiout.num_dacs++] = dac;
}
return 0;
}
static inline int __alc662_add_vol_ctl(struct alc_spec *spec, const char *pfx,
hda_nid_t nid, int idx, unsigned int chs)
{
return __add_pb_vol_ctrl(spec, ALC_CTL_WIDGET_VOL, pfx, idx,
HDA_COMPOSE_AMP_VAL(nid, chs, 0, HDA_OUTPUT));
}
static inline int __alc662_add_sw_ctl(struct alc_spec *spec, const char *pfx,
hda_nid_t nid, int idx, unsigned int chs)
{
return __add_pb_sw_ctrl(spec, ALC_CTL_WIDGET_MUTE, pfx, idx,
HDA_COMPOSE_AMP_VAL(nid, chs, 0, HDA_INPUT));
}
static int alc662_auto_create_multi_out_ctls(struct hda_codec *codec,
const struct auto_pin_cfg *cfg)
{
struct alc_spec *spec = codec->spec;
static const char * const chname[4] = {
"Front", "Surround", NULL , "Side"
};
const char *pfx = alc_get_line_out_pfx(spec, true);
hda_nid_t nid, mix, pin;
int i, err, noutputs;
noutputs = cfg->line_outs;
if (spec->multi_ios > 0)
noutputs += spec->multi_ios;
for (i = 0; i < noutputs; i++) {
nid = spec->multiout.dac_nids[i];
if (!nid)
continue;
if (i >= cfg->line_outs)
pin = spec->multi_io[i - 1].pin;
else
pin = cfg->line_out_pins[i];
mix = alc_auto_dac_to_mix(codec, pin, nid);
if (!mix)
continue;
if (!pfx && i == 2) {
err = alc662_add_vol_ctl(spec, "Center", nid, 1);
if (err < 0)
return err;
err = alc662_add_vol_ctl(spec, "LFE", nid, 2);
if (err < 0)
return err;
err = alc662_add_sw_ctl(spec, "Center", mix, 1);
if (err < 0)
return err;
err = alc662_add_sw_ctl(spec, "LFE", mix, 2);
if (err < 0)
return err;
} else {
const char *name = pfx;
int index = i;
if (!name) {
name = chname[i];
index = 0;
}
err = __alc662_add_vol_ctl(spec, name, nid, index, 3);
if (err < 0)
return err;
err = __alc662_add_sw_ctl(spec, name, mix, index, 3);
if (err < 0)
return err;
}
}
return 0;
}
static int alc662_auto_create_extra_out(struct hda_codec *codec, hda_nid_t pin,
const char *pfx)
{
struct alc_spec *spec = codec->spec;
hda_nid_t nid, mix;
int err;
if (!pin)
return 0;
nid = alc_auto_look_for_dac(codec, pin);
if (!nid) {
if (!(get_wcaps(codec, pin) & AC_WCAP_OUT_AMP))
return 0;
return add_pb_sw_ctrl(spec, ALC_CTL_WIDGET_MUTE, pfx,
HDA_COMPOSE_AMP_VAL(pin, 3, 0, HDA_OUTPUT));
}
mix = alc_auto_dac_to_mix(codec, pin, nid);
if (!mix)
return 0;
err = alc662_add_vol_ctl(spec, pfx, nid, 3);
if (err < 0)
return err;
err = alc662_add_sw_ctl(spec, pfx, mix, 3);
if (err < 0)
return err;
return nid;
}
static void alc662_auto_set_output_and_unmute(struct hda_codec *codec,
hda_nid_t nid, int pin_type,
hda_nid_t dac)
{
int i, num;
hda_nid_t srcs[HDA_MAX_CONNECTIONS];
alc_set_pin_output(codec, nid, pin_type);
num = snd_hda_get_connections(codec, nid, srcs, ARRAY_SIZE(srcs));
for (i = 0; i < num; i++) {
if (alc_auto_mix_to_dac(codec, srcs[i]) != dac)
continue;
if (num > 1)
snd_hda_codec_write(codec, nid, 0,
AC_VERB_SET_CONNECT_SEL, i);
snd_hda_codec_write(codec, srcs[i], 0,
AC_VERB_SET_AMP_GAIN_MUTE,
AMP_IN_UNMUTE(0));
snd_hda_codec_write(codec, srcs[i], 0,
AC_VERB_SET_AMP_GAIN_MUTE,
AMP_IN_UNMUTE(1));
return;
}
}
static void alc662_auto_init_multi_out(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
int pin_type = get_pin_type(spec->autocfg.line_out_type);
int i;
for (i = 0; i <= HDA_SIDE; i++) {
hda_nid_t nid = spec->autocfg.line_out_pins[i];
if (nid)
alc662_auto_set_output_and_unmute(codec, nid, pin_type,
spec->multiout.dac_nids[i]);
}
}
static void alc662_auto_init_hp_out(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
hda_nid_t pin;
pin = spec->autocfg.hp_pins[0];
if (pin)
alc662_auto_set_output_and_unmute(codec, pin, PIN_HP,
spec->multiout.hp_nid);
pin = spec->autocfg.speaker_pins[0];
if (pin)
alc662_auto_set_output_and_unmute(codec, pin, PIN_OUT,
spec->multiout.extra_out_nid[0]);
}
static void alc662_auto_init_analog_input(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
struct auto_pin_cfg *cfg = &spec->autocfg;
int i;
for (i = 0; i < cfg->num_inputs; i++) {
hda_nid_t nid = cfg->inputs[i].pin;
if (alc_is_input_pin(codec, nid)) {
alc_set_input_pin(codec, nid, cfg->inputs[i].type);
if (nid != ALC662_PIN_CD_NID &&
(get_wcaps(codec, nid) & AC_WCAP_OUT_AMP))
snd_hda_codec_write(codec, nid, 0,
AC_VERB_SET_AMP_GAIN_MUTE,
AMP_OUT_MUTE);
}
}
}
static int alc_auto_fill_multi_ios(struct hda_codec *codec,
unsigned int location)
{
struct alc_spec *spec = codec->spec;
struct auto_pin_cfg *cfg = &spec->autocfg;
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
if (num_pins < 2)
return 0;
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
return 1;
}
static int alc_auto_add_multi_channel_mode(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
struct auto_pin_cfg *cfg = &spec->autocfg;
unsigned int location, defcfg;
int num_pins;
if (cfg->line_outs != 1 ||
cfg->line_out_type != AUTO_PIN_LINE_OUT)
return 0;
defcfg = snd_hda_codec_get_pincfg(codec, cfg->line_out_pins[0]);
location = get_defcfg_location(defcfg);
num_pins = alc_auto_fill_multi_ios(codec, location);
if (num_pins > 0) {
struct snd_kcontrol_new *knew;
knew = alc_kcontrol_new(spec);
if (!knew)
return -ENOMEM;
*knew = alc_auto_channel_mode_enum;
knew->name = kstrdup("Channel Mode", GFP_KERNEL);
if (!knew->name)
return -ENOMEM;
spec->multi_ios = num_pins;
spec->ext_channel_count = 2;
spec->multiout.num_dacs = num_pins + 1;
}
return 0;
}
static int alc662_parse_auto_config(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
int err;
static const hda_nid_t alc662_ignore[] = { 0x1d, 0 };
err = snd_hda_parse_pin_def_config(codec, &spec->autocfg,
alc662_ignore);
if (err < 0)
return err;
if (!spec->autocfg.line_outs)
return 0;
err = alc662_auto_fill_dac_nids(codec, &spec->autocfg);
if (err < 0)
return err;
err = alc_auto_add_multi_channel_mode(codec);
if (err < 0)
return err;
err = alc662_auto_create_multi_out_ctls(codec, &spec->autocfg);
if (err < 0)
return err;
err = alc662_auto_create_extra_out(codec,
spec->autocfg.speaker_pins[0],
"Speaker");
if (err < 0)
return err;
if (err)
spec->multiout.extra_out_nid[0] = err;
err = alc662_auto_create_extra_out(codec, spec->autocfg.hp_pins[0],
"Headphone");
if (err < 0)
return err;
if (err)
spec->multiout.hp_nid = err;
err = alc662_auto_create_input_ctls(codec, &spec->autocfg);
if (err < 0)
return err;
spec->multiout.max_channels = spec->multiout.num_dacs * 2;
alc_auto_parse_digital(codec);
if (spec->kctls.list)
add_mixer(spec, spec->kctls.list);
spec->num_mux_defs = 1;
spec->input_mux = &spec->private_imux[0];
err = alc_auto_add_mic_boost(codec);
if (err < 0)
return err;
if (codec->vendor_id == 0x10ec0272 || codec->vendor_id == 0x10ec0663 ||
codec->vendor_id == 0x10ec0665 || codec->vendor_id == 0x10ec0670)
alc_ssid_check(codec, 0x15, 0x1b, 0x14, 0x21);
else
alc_ssid_check(codec, 0x15, 0x1b, 0x14, 0);
return 1;
}
static void alc662_auto_init(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
alc662_auto_init_multi_out(codec);
alc662_auto_init_hp_out(codec);
alc662_auto_init_analog_input(codec);
alc662_auto_init_input_src(codec);
alc_auto_init_digital(codec);
if (spec->unsol_event)
alc_inithook(codec);
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
int err, board_config;
int coef;
spec = kzalloc(sizeof(*spec), GFP_KERNEL);
if (!spec)
return -ENOMEM;
codec->spec = spec;
alc_auto_parse_customize_define(codec);
alc_fix_pll_init(codec, 0x20, 0x04, 15);
coef = alc_read_coef_idx(codec, 0);
if (coef == 0x8020 || coef == 0x8011)
alc_codec_rename(codec, "ALC661");
else if (coef & (1 << 14) &&
codec->bus->pci->subsystem_vendor == 0x1025 &&
spec->cdefine.platform_type == 1)
alc_codec_rename(codec, "ALC272X");
else if (coef == 0x4011)
alc_codec_rename(codec, "ALC656");
board_config = snd_hda_check_board_config(codec, ALC662_MODEL_LAST,
alc662_models,
alc662_cfg_tbl);
if (board_config < 0) {
printk(KERN_INFO "hda_codec: %s: BIOS auto-probing.\n",
codec->chip_name);
board_config = ALC662_AUTO;
}
if (board_config == ALC662_AUTO) {
alc_pick_fixup(codec, alc662_fixup_models,
alc662_fixup_tbl, alc662_fixups);
alc_apply_fixup(codec, ALC_FIXUP_ACT_PRE_PROBE);
err = alc662_parse_auto_config(codec);
if (err < 0) {
alc_free(codec);
return err;
} else if (!err) {
printk(KERN_INFO
"hda_codec: Cannot set up configuration "
"from BIOS. Using base mode...\n");
board_config = ALC662_3ST_2ch_DIG;
}
}
if (has_cdefine_beep(codec)) {
err = snd_hda_attach_beep_device(codec, 0x1);
if (err < 0) {
alc_free(codec);
return err;
}
}
if (board_config != ALC662_AUTO)
setup_preset(codec, &alc662_presets[board_config]);
spec->stream_analog_playback = &alc662_pcm_analog_playback;
spec->stream_analog_capture = &alc662_pcm_analog_capture;
spec->stream_digital_playback = &alc662_pcm_digital_playback;
spec->stream_digital_capture = &alc662_pcm_digital_capture;
if (!spec->adc_nids) {
spec->adc_nids = alc662_adc_nids;
spec->num_adc_nids = ARRAY_SIZE(alc662_adc_nids);
}
if (!spec->capsrc_nids)
spec->capsrc_nids = alc662_capsrc_nids;
if (!spec->cap_mixer)
set_capture_mixer(codec);
if (has_cdefine_beep(codec)) {
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
if (board_config == ALC662_AUTO)
spec->init_hook = alc662_auto_init;
spec->shutup = alc_eapd_shutup;
alc_init_jacks(codec);
#ifdef CONFIG_SND_HDA_POWER_SAVE
if (!spec->loopback.amplist)
spec->loopback.amplist = alc662_loopbacks;
#endif
return 0;
}
static int patch_alc888(struct hda_codec *codec)
{
if ((alc_read_coef_idx(codec, 0) & 0x00f0)==0x0030){
kfree(codec->chip_name);
if (codec->vendor_id == 0x10ec0887)
codec->chip_name = kstrdup("ALC887-VD", GFP_KERNEL);
else
codec->chip_name = kstrdup("ALC888-VD", GFP_KERNEL);
if (!codec->chip_name) {
alc_free(codec);
return -ENOMEM;
}
return patch_alc662(codec);
}
return patch_alc882(codec);
}
static int patch_alc899(struct hda_codec *codec)
{
if ((alc_read_coef_idx(codec, 0) & 0x2000) != 0x2000) {
kfree(codec->chip_name);
codec->chip_name = kstrdup("ALC898", GFP_KERNEL);
}
return patch_alc882(codec);
}
static void alc680_rec_autoswitch(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
struct auto_pin_cfg *cfg = &spec->autocfg;
int pin_found = 0;
int type_found = AUTO_PIN_LAST;
hda_nid_t nid;
int i;
for (i = 0; i < cfg->num_inputs; i++) {
nid = cfg->inputs[i].pin;
if (!is_jack_detectable(codec, nid))
continue;
if (snd_hda_jack_detect(codec, nid)) {
if (cfg->inputs[i].type < type_found) {
type_found = cfg->inputs[i].type;
pin_found = nid;
}
}
}
nid = 0x07;
if (pin_found)
snd_hda_get_connections(codec, pin_found, &nid, 1);
if (nid != spec->cur_adc)
__snd_hda_codec_cleanup_stream(codec, spec->cur_adc, 1);
spec->cur_adc = nid;
snd_hda_codec_setup_stream(codec, nid, spec->cur_adc_stream_tag, 0,
spec->cur_adc_format);
}
static int alc680_capture_pcm_prepare(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
unsigned int stream_tag,
unsigned int format,
struct snd_pcm_substream *substream)
{
struct alc_spec *spec = codec->spec;
spec->cur_adc = 0x07;
spec->cur_adc_stream_tag = stream_tag;
spec->cur_adc_format = format;
alc680_rec_autoswitch(codec);
return 0;
}
static int alc680_capture_pcm_cleanup(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
struct snd_pcm_substream *substream)
{
snd_hda_codec_cleanup_stream(codec, 0x07);
snd_hda_codec_cleanup_stream(codec, 0x08);
snd_hda_codec_cleanup_stream(codec, 0x09);
return 0;
}
static void alc680_base_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x16;
spec->autocfg.speaker_pins[0] = 0x14;
spec->autocfg.speaker_pins[1] = 0x15;
spec->autocfg.num_inputs = 2;
spec->autocfg.inputs[0].pin = 0x18;
spec->autocfg.inputs[0].type = AUTO_PIN_MIC;
spec->autocfg.inputs[1].pin = 0x19;
spec->autocfg.inputs[1].type = AUTO_PIN_LINE_IN;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_AMP;
}
static void alc680_unsol_event(struct hda_codec *codec,
unsigned int res)
{
if ((res >> 26) == ALC880_HP_EVENT)
alc_hp_automute(codec);
if ((res >> 26) == ALC880_MIC_EVENT)
alc680_rec_autoswitch(codec);
}
static void alc680_inithook(struct hda_codec *codec)
{
alc_hp_automute(codec);
alc680_rec_autoswitch(codec);
}
static int alc680_new_analog_output(struct alc_spec *spec, hda_nid_t nid,
const char *ctlname, int idx)
{
hda_nid_t dac;
int err;
switch (nid) {
case 0x14:
dac = 0x02;
break;
case 0x15:
dac = 0x03;
break;
case 0x16:
dac = 0x04;
break;
default:
return 0;
}
if (spec->multiout.dac_nids[0] != dac &&
spec->multiout.dac_nids[1] != dac) {
err = add_pb_vol_ctrl(spec, ALC_CTL_WIDGET_VOL, ctlname,
HDA_COMPOSE_AMP_VAL(dac, 3, idx,
HDA_OUTPUT));
if (err < 0)
return err;
err = add_pb_sw_ctrl(spec, ALC_CTL_WIDGET_MUTE, ctlname,
HDA_COMPOSE_AMP_VAL(nid, 3, idx, HDA_OUTPUT));
if (err < 0)
return err;
spec->private_dac_nids[spec->multiout.num_dacs++] = dac;
}
return 0;
}
static int alc680_auto_create_multi_out_ctls(struct alc_spec *spec,
const struct auto_pin_cfg *cfg)
{
hda_nid_t nid;
int err;
spec->multiout.dac_nids = spec->private_dac_nids;
nid = cfg->line_out_pins[0];
if (nid) {
const char *name;
if (cfg->line_out_type == AUTO_PIN_SPEAKER_OUT)
name = "Speaker";
else
name = "Front";
err = alc680_new_analog_output(spec, nid, name, 0);
if (err < 0)
return err;
}
nid = cfg->speaker_pins[0];
if (nid) {
err = alc680_new_analog_output(spec, nid, "Speaker", 0);
if (err < 0)
return err;
}
nid = cfg->hp_pins[0];
if (nid) {
err = alc680_new_analog_output(spec, nid, "Headphone", 0);
if (err < 0)
return err;
}
return 0;
}
static void alc680_auto_set_output_and_unmute(struct hda_codec *codec,
hda_nid_t nid, int pin_type)
{
alc_set_pin_output(codec, nid, pin_type);
}
static void alc680_auto_init_multi_out(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
hda_nid_t nid = spec->autocfg.line_out_pins[0];
if (nid) {
int pin_type = get_pin_type(spec->autocfg.line_out_type);
alc680_auto_set_output_and_unmute(codec, nid, pin_type);
}
}
static void alc680_auto_init_hp_out(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
hda_nid_t pin;
pin = spec->autocfg.hp_pins[0];
if (pin)
alc680_auto_set_output_and_unmute(codec, pin, PIN_HP);
pin = spec->autocfg.speaker_pins[0];
if (pin)
alc680_auto_set_output_and_unmute(codec, pin, PIN_OUT);
}
static int alc680_parse_auto_config(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
int err;
static const hda_nid_t alc680_ignore[] = { 0 };
err = snd_hda_parse_pin_def_config(codec, &spec->autocfg,
alc680_ignore);
if (err < 0)
return err;
if (!spec->autocfg.line_outs) {
if (spec->autocfg.dig_outs || spec->autocfg.dig_in_pin) {
spec->multiout.max_channels = 2;
spec->no_analog = 1;
goto dig_only;
}
return 0;
}
err = alc680_auto_create_multi_out_ctls(spec, &spec->autocfg);
if (err < 0)
return err;
spec->multiout.max_channels = 2;
dig_only:
alc_auto_parse_digital(codec);
if (spec->kctls.list)
add_mixer(spec, spec->kctls.list);
add_verb(spec, alc680_init_verbs);
err = alc_auto_add_mic_boost(codec);
if (err < 0)
return err;
return 1;
}
static void alc680_auto_init(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
alc680_auto_init_multi_out(codec);
alc680_auto_init_hp_out(codec);
alc680_auto_init_analog_input(codec);
alc_auto_init_digital(codec);
if (spec->unsol_event)
alc_inithook(codec);
}
static int patch_alc680(struct hda_codec *codec)
{
struct alc_spec *spec;
int board_config;
int err;
spec = kzalloc(sizeof(*spec), GFP_KERNEL);
if (spec == NULL)
return -ENOMEM;
codec->spec = spec;
board_config = snd_hda_check_board_config(codec, ALC680_MODEL_LAST,
alc680_models,
alc680_cfg_tbl);
if (board_config < 0 || board_config >= ALC680_MODEL_LAST) {
printk(KERN_INFO "hda_codec: %s: BIOS auto-probing.\n",
codec->chip_name);
board_config = ALC680_AUTO;
}
if (board_config == ALC680_AUTO) {
err = alc680_parse_auto_config(codec);
if (err < 0) {
alc_free(codec);
return err;
} else if (!err) {
printk(KERN_INFO
"hda_codec: Cannot set up configuration "
"from BIOS. Using base mode...\n");
board_config = ALC680_BASE;
}
}
if (board_config != ALC680_AUTO)
setup_preset(codec, &alc680_presets[board_config]);
spec->stream_analog_playback = &alc680_pcm_analog_playback;
spec->stream_analog_capture = &alc680_pcm_analog_auto_capture;
spec->stream_digital_playback = &alc680_pcm_digital_playback;
spec->stream_digital_capture = &alc680_pcm_digital_capture;
if (!spec->adc_nids) {
spec->adc_nids = alc680_adc_nids;
spec->num_adc_nids = ARRAY_SIZE(alc680_adc_nids);
}
if (!spec->cap_mixer)
set_capture_mixer(codec);
spec->vmaster_nid = 0x02;
codec->patch_ops = alc_patch_ops;
if (board_config == ALC680_AUTO)
spec->init_hook = alc680_auto_init;
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
