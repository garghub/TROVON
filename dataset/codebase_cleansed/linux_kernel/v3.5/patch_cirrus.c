static inline int cs_vendor_coef_get(struct hda_codec *codec, unsigned int idx)
{
struct cs_spec *spec = codec->spec;
snd_hda_codec_write(codec, spec->vendor_nid, 0,
AC_VERB_SET_COEF_INDEX, idx);
return snd_hda_codec_read(codec, spec->vendor_nid, 0,
AC_VERB_GET_PROC_COEF, 0);
}
static inline void cs_vendor_coef_set(struct hda_codec *codec, unsigned int idx,
unsigned int coef)
{
struct cs_spec *spec = codec->spec;
snd_hda_codec_write(codec, spec->vendor_nid, 0,
AC_VERB_SET_COEF_INDEX, idx);
snd_hda_codec_write(codec, spec->vendor_nid, 0,
AC_VERB_SET_PROC_COEF, coef);
}
static int cs_playback_pcm_open(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
struct snd_pcm_substream *substream)
{
struct cs_spec *spec = codec->spec;
return snd_hda_multi_out_analog_open(codec, &spec->multiout, substream,
hinfo);
}
static int cs_playback_pcm_prepare(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
unsigned int stream_tag,
unsigned int format,
struct snd_pcm_substream *substream)
{
struct cs_spec *spec = codec->spec;
return snd_hda_multi_out_analog_prepare(codec, &spec->multiout,
stream_tag, format, substream);
}
static int cs_playback_pcm_cleanup(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
struct snd_pcm_substream *substream)
{
struct cs_spec *spec = codec->spec;
return snd_hda_multi_out_analog_cleanup(codec, &spec->multiout);
}
static int cs_dig_playback_pcm_open(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
struct snd_pcm_substream *substream)
{
struct cs_spec *spec = codec->spec;
return snd_hda_multi_out_dig_open(codec, &spec->multiout);
}
static int cs_dig_playback_pcm_close(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
struct snd_pcm_substream *substream)
{
struct cs_spec *spec = codec->spec;
return snd_hda_multi_out_dig_close(codec, &spec->multiout);
}
static int cs_dig_playback_pcm_prepare(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
unsigned int stream_tag,
unsigned int format,
struct snd_pcm_substream *substream)
{
struct cs_spec *spec = codec->spec;
return snd_hda_multi_out_dig_prepare(codec, &spec->multiout, stream_tag,
format, substream);
}
static int cs_dig_playback_pcm_cleanup(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
struct snd_pcm_substream *substream)
{
struct cs_spec *spec = codec->spec;
return snd_hda_multi_out_dig_cleanup(codec, &spec->multiout);
}
static void cs_update_input_select(struct hda_codec *codec)
{
struct cs_spec *spec = codec->spec;
if (spec->cur_adc)
snd_hda_codec_write(codec, spec->cur_adc, 0,
AC_VERB_SET_CONNECT_SEL,
spec->adc_idx[spec->cur_input]);
}
static int cs_capture_pcm_prepare(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
unsigned int stream_tag,
unsigned int format,
struct snd_pcm_substream *substream)
{
struct cs_spec *spec = codec->spec;
spec->cur_adc = spec->adc_nid[spec->cur_input];
spec->cur_adc_stream_tag = stream_tag;
spec->cur_adc_format = format;
cs_update_input_select(codec);
snd_hda_codec_setup_stream(codec, spec->cur_adc, stream_tag, 0, format);
return 0;
}
static int cs_capture_pcm_cleanup(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
struct snd_pcm_substream *substream)
{
struct cs_spec *spec = codec->spec;
snd_hda_codec_cleanup_stream(codec, spec->cur_adc);
spec->cur_adc = 0;
return 0;
}
static int cs_build_pcms(struct hda_codec *codec)
{
struct cs_spec *spec = codec->spec;
struct hda_pcm *info = spec->pcm_rec;
codec->pcm_info = info;
codec->num_pcms = 0;
info->name = "Cirrus Analog";
info->stream[SNDRV_PCM_STREAM_PLAYBACK] = cs_pcm_analog_playback;
info->stream[SNDRV_PCM_STREAM_PLAYBACK].nid = spec->dac_nid[0];
info->stream[SNDRV_PCM_STREAM_PLAYBACK].channels_max =
spec->multiout.max_channels;
info->stream[SNDRV_PCM_STREAM_CAPTURE] = cs_pcm_analog_capture;
info->stream[SNDRV_PCM_STREAM_CAPTURE].nid =
spec->adc_nid[spec->cur_input];
codec->num_pcms++;
if (!spec->multiout.dig_out_nid && !spec->dig_in)
return 0;
info++;
info->name = "Cirrus Digital";
info->pcm_type = spec->autocfg.dig_out_type[0];
if (!info->pcm_type)
info->pcm_type = HDA_PCM_TYPE_SPDIF;
if (spec->multiout.dig_out_nid) {
info->stream[SNDRV_PCM_STREAM_PLAYBACK] =
cs_pcm_digital_playback;
info->stream[SNDRV_PCM_STREAM_PLAYBACK].nid =
spec->multiout.dig_out_nid;
}
if (spec->dig_in) {
info->stream[SNDRV_PCM_STREAM_CAPTURE] =
cs_pcm_digital_capture;
info->stream[SNDRV_PCM_STREAM_CAPTURE].nid = spec->dig_in;
}
codec->num_pcms++;
return 0;
}
static hda_nid_t get_dac(struct hda_codec *codec, hda_nid_t pin)
{
hda_nid_t dac;
if (!pin)
return 0;
if (snd_hda_get_connections(codec, pin, &dac, 1) != 1)
return 0;
return dac;
}
static int is_ext_mic(struct hda_codec *codec, unsigned int idx)
{
struct cs_spec *spec = codec->spec;
struct auto_pin_cfg *cfg = &spec->autocfg;
hda_nid_t pin = cfg->inputs[idx].pin;
unsigned int val;
if (!is_jack_detectable(codec, pin))
return 0;
val = snd_hda_codec_get_pincfg(codec, pin);
return (snd_hda_get_input_pin_attr(val) != INPUT_PIN_ATTR_INT);
}
static hda_nid_t get_adc(struct hda_codec *codec, hda_nid_t pin,
unsigned int *idxp)
{
int i, idx;
hda_nid_t nid;
nid = codec->start_nid;
for (i = 0; i < codec->num_nodes; i++, nid++) {
unsigned int type;
type = get_wcaps_type(get_wcaps(codec, nid));
if (type != AC_WID_AUD_IN)
continue;
idx = snd_hda_get_conn_index(codec, nid, pin, false);
if (idx >= 0) {
*idxp = idx;
return nid;
}
}
return 0;
}
static int is_active_pin(struct hda_codec *codec, hda_nid_t nid)
{
unsigned int val;
val = snd_hda_codec_get_pincfg(codec, nid);
return (get_defcfg_connect(val) != AC_JACK_PORT_NONE);
}
static int parse_output(struct hda_codec *codec)
{
struct cs_spec *spec = codec->spec;
struct auto_pin_cfg *cfg = &spec->autocfg;
int i, extra_nids;
hda_nid_t dac;
for (i = 0; i < cfg->line_outs; i++) {
dac = get_dac(codec, cfg->line_out_pins[i]);
if (!dac)
break;
spec->dac_nid[i] = dac;
}
spec->multiout.num_dacs = i;
spec->multiout.dac_nids = spec->dac_nid;
spec->multiout.max_channels = i * 2;
extra_nids = 0;
for (i = 0; i < cfg->hp_outs; i++) {
dac = get_dac(codec, cfg->hp_pins[i]);
if (!dac)
break;
if (!i)
spec->multiout.hp_nid = dac;
else
spec->multiout.extra_out_nid[extra_nids++] = dac;
}
for (i = 0; i < cfg->speaker_outs; i++) {
dac = get_dac(codec, cfg->speaker_pins[i]);
if (!dac)
break;
spec->multiout.extra_out_nid[extra_nids++] = dac;
}
if (cfg->line_out_type == AUTO_PIN_SPEAKER_OUT) {
cfg->speaker_outs = cfg->line_outs;
memcpy(cfg->speaker_pins, cfg->line_out_pins,
sizeof(cfg->speaker_pins));
cfg->line_outs = 0;
}
return 0;
}
static int parse_input(struct hda_codec *codec)
{
struct cs_spec *spec = codec->spec;
struct auto_pin_cfg *cfg = &spec->autocfg;
int i;
for (i = 0; i < cfg->num_inputs; i++) {
hda_nid_t pin = cfg->inputs[i].pin;
spec->input_idx[spec->num_inputs] = i;
spec->capsrc_idx[i] = spec->num_inputs++;
spec->cur_input = i;
spec->adc_nid[i] = get_adc(codec, pin, &spec->adc_idx[i]);
}
if (!spec->num_inputs)
return 0;
if (spec->num_inputs == 2 &&
cfg->inputs[0].type == AUTO_PIN_MIC &&
cfg->inputs[1].type == AUTO_PIN_MIC) {
if (is_ext_mic(codec, cfg->inputs[0].pin)) {
if (!is_ext_mic(codec, cfg->inputs[1].pin)) {
spec->mic_detect = 1;
spec->automic_idx = 0;
}
} else {
if (is_ext_mic(codec, cfg->inputs[1].pin)) {
spec->mic_detect = 1;
spec->automic_idx = 1;
}
}
}
return 0;
}
static int parse_digital_output(struct hda_codec *codec)
{
struct cs_spec *spec = codec->spec;
struct auto_pin_cfg *cfg = &spec->autocfg;
hda_nid_t nid;
if (!cfg->dig_outs)
return 0;
if (snd_hda_get_connections(codec, cfg->dig_out_pins[0], &nid, 1) < 1)
return 0;
spec->multiout.dig_out_nid = nid;
spec->multiout.share_spdif = 1;
if (cfg->dig_outs > 1 &&
snd_hda_get_connections(codec, cfg->dig_out_pins[1], &nid, 1) > 0) {
spec->slave_dig_outs[0] = nid;
codec->slave_dig_outs = spec->slave_dig_outs;
}
return 0;
}
static int parse_digital_input(struct hda_codec *codec)
{
struct cs_spec *spec = codec->spec;
struct auto_pin_cfg *cfg = &spec->autocfg;
int idx;
if (cfg->dig_in_pin)
spec->dig_in = get_adc(codec, cfg->dig_in_pin, &idx);
return 0;
}
static int add_mute(struct hda_codec *codec, const char *name, int index,
unsigned int pval, int dir, struct snd_kcontrol **kctlp)
{
char tmp[44];
struct snd_kcontrol_new knew =
HDA_CODEC_MUTE_IDX(tmp, index, 0, 0, HDA_OUTPUT);
knew.private_value = pval;
snprintf(tmp, sizeof(tmp), "%s %s Switch", name, dir_sfx[dir]);
*kctlp = snd_ctl_new1(&knew, codec);
(*kctlp)->id.subdevice = HDA_SUBDEV_AMP_FLAG;
return snd_hda_ctl_add(codec, 0, *kctlp);
}
static int add_volume(struct hda_codec *codec, const char *name,
int index, unsigned int pval, int dir,
struct snd_kcontrol **kctlp)
{
char tmp[44];
struct snd_kcontrol_new knew =
HDA_CODEC_VOLUME_IDX(tmp, index, 0, 0, HDA_OUTPUT);
knew.private_value = pval;
snprintf(tmp, sizeof(tmp), "%s %s Volume", name, dir_sfx[dir]);
*kctlp = snd_ctl_new1(&knew, codec);
(*kctlp)->id.subdevice = HDA_SUBDEV_AMP_FLAG;
return snd_hda_ctl_add(codec, 0, *kctlp);
}
static void fix_volume_caps(struct hda_codec *codec, hda_nid_t dac)
{
unsigned int caps;
caps = query_amp_caps(codec, dac, HDA_OUTPUT);
caps &= ~(0x7f << AC_AMPCAP_NUM_STEPS_SHIFT);
caps |= ((caps >> AC_AMPCAP_OFFSET_SHIFT) & 0x7f)
<< AC_AMPCAP_NUM_STEPS_SHIFT;
snd_hda_override_amp_caps(codec, dac, HDA_OUTPUT, caps);
}
static int add_vmaster(struct hda_codec *codec, hda_nid_t dac)
{
struct cs_spec *spec = codec->spec;
unsigned int tlv[4];
int err;
spec->vmaster_sw =
snd_ctl_make_virtual_master("Master Playback Switch", NULL);
err = snd_hda_ctl_add(codec, dac, spec->vmaster_sw);
if (err < 0)
return err;
snd_hda_set_vmaster_tlv(codec, dac, HDA_OUTPUT, tlv);
spec->vmaster_vol =
snd_ctl_make_virtual_master("Master Playback Volume", tlv);
err = snd_hda_ctl_add(codec, dac, spec->vmaster_vol);
if (err < 0)
return err;
return 0;
}
static int add_output(struct hda_codec *codec, hda_nid_t dac, int idx,
int num_ctls, int type)
{
struct cs_spec *spec = codec->spec;
const char *name;
int err, index;
struct snd_kcontrol *kctl;
static const char * const speakers[] = {
"Front Speaker", "Surround Speaker", "Bass Speaker"
};
static const char * const line_outs[] = {
"Front Line Out", "Surround Line Out", "Bass Line Out"
};
fix_volume_caps(codec, dac);
if (!spec->vmaster_sw) {
err = add_vmaster(codec, dac);
if (err < 0)
return err;
}
index = 0;
switch (type) {
case AUTO_PIN_HP_OUT:
name = "Headphone";
index = idx;
break;
case AUTO_PIN_SPEAKER_OUT:
if (num_ctls > 1)
name = speakers[idx];
else
name = "Speaker";
break;
default:
if (num_ctls > 1)
name = line_outs[idx];
else
name = "Line Out";
break;
}
err = add_mute(codec, name, index,
HDA_COMPOSE_AMP_VAL(dac, 3, 0, HDA_OUTPUT), 0, &kctl);
if (err < 0)
return err;
err = snd_ctl_add_slave(spec->vmaster_sw, kctl);
if (err < 0)
return err;
err = add_volume(codec, name, index,
HDA_COMPOSE_AMP_VAL(dac, 3, 0, HDA_OUTPUT), 0, &kctl);
if (err < 0)
return err;
err = snd_ctl_add_slave(spec->vmaster_vol, kctl);
if (err < 0)
return err;
return 0;
}
static int build_output(struct hda_codec *codec)
{
struct cs_spec *spec = codec->spec;
struct auto_pin_cfg *cfg = &spec->autocfg;
int i, err;
for (i = 0; i < cfg->line_outs; i++) {
err = add_output(codec, get_dac(codec, cfg->line_out_pins[i]),
i, cfg->line_outs, cfg->line_out_type);
if (err < 0)
return err;
}
for (i = 0; i < cfg->hp_outs; i++) {
err = add_output(codec, get_dac(codec, cfg->hp_pins[i]),
i, cfg->hp_outs, AUTO_PIN_HP_OUT);
if (err < 0)
return err;
}
for (i = 0; i < cfg->speaker_outs; i++) {
err = add_output(codec, get_dac(codec, cfg->speaker_pins[i]),
i, cfg->speaker_outs, AUTO_PIN_SPEAKER_OUT);
if (err < 0)
return err;
}
return 0;
}
static int change_cur_input(struct hda_codec *codec, unsigned int idx,
int force)
{
struct cs_spec *spec = codec->spec;
if (spec->cur_input == idx && !force)
return 0;
if (spec->cur_adc && spec->cur_adc != spec->adc_nid[idx]) {
__snd_hda_codec_cleanup_stream(codec, spec->cur_adc, 1);
spec->cur_adc = spec->adc_nid[idx];
snd_hda_codec_setup_stream(codec, spec->cur_adc,
spec->cur_adc_stream_tag, 0,
spec->cur_adc_format);
}
spec->cur_input = idx;
cs_update_input_select(codec);
return 1;
}
static int cs_capture_source_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct cs_spec *spec = codec->spec;
struct auto_pin_cfg *cfg = &spec->autocfg;
unsigned int idx;
uinfo->type = SNDRV_CTL_ELEM_TYPE_ENUMERATED;
uinfo->count = 1;
uinfo->value.enumerated.items = spec->num_inputs;
if (uinfo->value.enumerated.item >= spec->num_inputs)
uinfo->value.enumerated.item = spec->num_inputs - 1;
idx = spec->input_idx[uinfo->value.enumerated.item];
snd_hda_get_pin_label(codec, cfg->inputs[idx].pin, cfg,
uinfo->value.enumerated.name,
sizeof(uinfo->value.enumerated.name), NULL);
return 0;
}
static int cs_capture_source_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct cs_spec *spec = codec->spec;
ucontrol->value.enumerated.item[0] = spec->capsrc_idx[spec->cur_input];
return 0;
}
static int cs_capture_source_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct cs_spec *spec = codec->spec;
unsigned int idx = ucontrol->value.enumerated.item[0];
if (idx >= spec->num_inputs)
return -EINVAL;
idx = spec->input_idx[idx];
return change_cur_input(codec, idx, 0);
}
static const struct hda_bind_ctls *make_bind_capture(struct hda_codec *codec,
struct hda_ctl_ops *ops)
{
struct cs_spec *spec = codec->spec;
struct hda_bind_ctls *bind;
int i, n;
bind = kzalloc(sizeof(*bind) + sizeof(long) * (spec->num_inputs + 1),
GFP_KERNEL);
if (!bind)
return NULL;
bind->ops = ops;
n = 0;
for (i = 0; i < AUTO_PIN_LAST; i++) {
if (!spec->adc_nid[i])
continue;
bind->values[n++] =
HDA_COMPOSE_AMP_VAL(spec->adc_nid[i], 3,
spec->adc_idx[i], HDA_INPUT);
}
return bind;
}
static int add_input_volume_control(struct hda_codec *codec,
struct auto_pin_cfg *cfg,
int item)
{
hda_nid_t pin = cfg->inputs[item].pin;
u32 caps;
const char *label;
struct snd_kcontrol *kctl;
if (!(get_wcaps(codec, pin) & AC_WCAP_IN_AMP))
return 0;
caps = query_amp_caps(codec, pin, HDA_INPUT);
caps = (caps & AC_AMPCAP_NUM_STEPS) >> AC_AMPCAP_NUM_STEPS_SHIFT;
if (caps <= 1)
return 0;
label = hda_get_autocfg_input_label(codec, cfg, item);
return add_volume(codec, label, 0,
HDA_COMPOSE_AMP_VAL(pin, 3, 0, HDA_INPUT), 1, &kctl);
}
static int build_input(struct hda_codec *codec)
{
struct cs_spec *spec = codec->spec;
int i, err;
if (!spec->num_inputs)
return 0;
spec->capture_bind[0] = make_bind_capture(codec, &snd_hda_bind_sw);
spec->capture_bind[1] = make_bind_capture(codec, &snd_hda_bind_vol);
for (i = 0; i < 2; i++) {
struct snd_kcontrol *kctl;
int n;
if (!spec->capture_bind[i])
return -ENOMEM;
kctl = snd_ctl_new1(&cs_capture_ctls[i], codec);
if (!kctl)
return -ENOMEM;
kctl->private_value = (long)spec->capture_bind[i];
err = snd_hda_ctl_add(codec, 0, kctl);
if (err < 0)
return err;
for (n = 0; n < AUTO_PIN_LAST; n++) {
if (!spec->adc_nid[n])
continue;
err = snd_hda_add_nid(codec, kctl, 0, spec->adc_nid[n]);
if (err < 0)
return err;
}
}
if (spec->num_inputs > 1 && !spec->mic_detect) {
err = snd_hda_ctl_add(codec, 0,
snd_ctl_new1(&cs_capture_source, codec));
if (err < 0)
return err;
}
for (i = 0; i < spec->num_inputs; i++) {
err = add_input_volume_control(codec, &spec->autocfg, i);
if (err < 0)
return err;
}
return 0;
}
static int build_digital_output(struct hda_codec *codec)
{
struct cs_spec *spec = codec->spec;
int err;
if (!spec->multiout.dig_out_nid)
return 0;
err = snd_hda_create_spdif_out_ctls(codec, spec->multiout.dig_out_nid,
spec->multiout.dig_out_nid);
if (err < 0)
return err;
err = snd_hda_create_spdif_share_sw(codec, &spec->multiout);
if (err < 0)
return err;
return 0;
}
static int build_digital_input(struct hda_codec *codec)
{
struct cs_spec *spec = codec->spec;
if (spec->dig_in)
return snd_hda_create_spdif_in_ctls(codec, spec->dig_in);
return 0;
}
static void cs_automute(struct hda_codec *codec)
{
struct cs_spec *spec = codec->spec;
struct auto_pin_cfg *cfg = &spec->autocfg;
unsigned int hp_present;
unsigned int spdif_present;
hda_nid_t nid;
int i;
spdif_present = 0;
if (cfg->dig_outs) {
nid = cfg->dig_out_pins[0];
if (is_jack_detectable(codec, nid)) {
if (snd_hda_jack_detect(codec, nid)
)
spdif_present = 1;
}
}
hp_present = 0;
for (i = 0; i < cfg->hp_outs; i++) {
nid = cfg->hp_pins[i];
if (!is_jack_detectable(codec, nid))
continue;
hp_present = snd_hda_jack_detect(codec, nid);
if (hp_present)
break;
}
for (i = 0; i < cfg->speaker_outs; i++) {
int pin_ctl = hp_present ? 0 : PIN_OUT;
if (spdif_present && (spec->vendor_nid == CS4210_VENDOR_NID))
pin_ctl = 0;
nid = cfg->speaker_pins[i];
snd_hda_set_pin_ctl(codec, nid, pin_ctl);
}
if (spec->gpio_eapd_hp) {
unsigned int gpio = hp_present ?
spec->gpio_eapd_hp : spec->gpio_eapd_speaker;
snd_hda_codec_write(codec, 0x01, 0,
AC_VERB_SET_GPIO_DATA, gpio);
}
if (spec->vendor_nid == CS4210_VENDOR_NID) {
for (i = 0; i < cfg->hp_outs; i++) {
nid = cfg->hp_pins[i];
snd_hda_set_pin_ctl(codec, nid,
(spdif_present && spec->sense_b) ? 0 : PIN_HP);
}
if (cfg->dig_outs) {
nid = cfg->dig_out_pins[0];
snd_hda_set_pin_ctl(codec, nid,
spdif_present ? PIN_OUT : 0);
}
}
}
static void cs_automic(struct hda_codec *codec)
{
struct cs_spec *spec = codec->spec;
struct auto_pin_cfg *cfg = &spec->autocfg;
hda_nid_t nid;
unsigned int present;
nid = cfg->inputs[spec->automic_idx].pin;
present = snd_hda_jack_detect(codec, nid);
if (spec->vendor_nid == CS420X_VENDOR_NID) {
if (present)
change_cur_input(codec, spec->automic_idx, 0);
else
change_cur_input(codec, !spec->automic_idx, 0);
} else {
if (present) {
if (spec->cur_input != spec->automic_idx) {
spec->last_input = spec->cur_input;
spec->cur_input = spec->automic_idx;
}
} else {
spec->cur_input = spec->last_input;
}
cs_update_input_select(codec);
}
}
static void init_output(struct hda_codec *codec)
{
struct cs_spec *spec = codec->spec;
struct auto_pin_cfg *cfg = &spec->autocfg;
int i;
for (i = 0; i < spec->multiout.num_dacs; i++)
snd_hda_codec_write(codec, spec->multiout.dac_nids[i], 0,
AC_VERB_SET_AMP_GAIN_MUTE, AMP_OUT_MUTE);
if (spec->multiout.hp_nid)
snd_hda_codec_write(codec, spec->multiout.hp_nid, 0,
AC_VERB_SET_AMP_GAIN_MUTE, AMP_OUT_MUTE);
for (i = 0; i < ARRAY_SIZE(spec->multiout.extra_out_nid); i++) {
if (!spec->multiout.extra_out_nid[i])
break;
snd_hda_codec_write(codec, spec->multiout.extra_out_nid[i], 0,
AC_VERB_SET_AMP_GAIN_MUTE, AMP_OUT_MUTE);
}
for (i = 0; i < cfg->line_outs; i++)
snd_hda_set_pin_ctl(codec, cfg->line_out_pins[i], PIN_OUT);
for (i = 0; i < cfg->hp_outs; i++) {
hda_nid_t nid = cfg->hp_pins[i];
snd_hda_set_pin_ctl(codec, nid, PIN_HP);
if (!cfg->speaker_outs)
continue;
if (get_wcaps(codec, nid) & AC_WCAP_UNSOL_CAP) {
snd_hda_jack_detect_enable(codec, nid, HP_EVENT);
spec->hp_detect = 1;
}
}
for (i = 0; i < cfg->speaker_outs; i++)
snd_hda_set_pin_ctl(codec, cfg->speaker_pins[i], PIN_OUT);
if (spec->hp_detect || spec->spdif_detect)
cs_automute(codec);
}
static void init_input(struct hda_codec *codec)
{
struct cs_spec *spec = codec->spec;
struct auto_pin_cfg *cfg = &spec->autocfg;
unsigned int coef;
int i;
for (i = 0; i < cfg->num_inputs; i++) {
unsigned int ctl;
hda_nid_t pin = cfg->inputs[i].pin;
if (!spec->adc_nid[i])
continue;
ctl = PIN_IN;
if (cfg->inputs[i].type == AUTO_PIN_MIC)
ctl |= snd_hda_get_default_vref(codec, pin);
snd_hda_set_pin_ctl(codec, pin, ctl);
snd_hda_codec_write(codec, spec->adc_nid[i], 0,
AC_VERB_SET_AMP_GAIN_MUTE,
AMP_IN_MUTE(spec->adc_idx[i]));
if (spec->mic_detect && spec->automic_idx == i)
snd_hda_jack_detect_enable(codec, pin, MIC_EVENT);
}
if (spec->vendor_nid == CS420X_VENDOR_NID) {
change_cur_input(codec, spec->cur_input, 1);
if (spec->mic_detect)
cs_automic(codec);
coef = 0x000a;
if (is_active_pin(codec, CS_DMIC2_PIN_NID))
coef |= 0x0500;
if (is_active_pin(codec, CS_DMIC1_PIN_NID))
coef |= 0x1800;
cs_vendor_coef_set(codec, IDX_ADC_CFG, coef);
} else {
if (spec->mic_detect)
cs_automic(codec);
else {
spec->cur_adc = spec->adc_nid[spec->cur_input];
cs_update_input_select(codec);
}
}
}
static void init_digital(struct hda_codec *codec)
{
unsigned int coef;
coef = 0x0002;
coef |= 0x0008;
if (is_active_pin(codec, CS_DIG_OUT2_PIN_NID))
coef |= 0x4000;
cs_vendor_coef_set(codec, IDX_SPDIF_CTL, coef);
}
static int cs_init(struct hda_codec *codec)
{
struct cs_spec *spec = codec->spec;
snd_hda_sequence_write(codec, cs_errata_init_verbs);
snd_hda_sequence_write(codec, cs_coef_init_verbs);
if (spec->gpio_mask) {
snd_hda_codec_write(codec, 0x01, 0, AC_VERB_SET_GPIO_MASK,
spec->gpio_mask);
snd_hda_codec_write(codec, 0x01, 0, AC_VERB_SET_GPIO_DIRECTION,
spec->gpio_dir);
snd_hda_codec_write(codec, 0x01, 0, AC_VERB_SET_GPIO_DATA,
spec->gpio_data);
}
init_output(codec);
init_input(codec);
init_digital(codec);
snd_hda_jack_report_sync(codec);
return 0;
}
static int cs_build_controls(struct hda_codec *codec)
{
struct cs_spec *spec = codec->spec;
int err;
err = build_output(codec);
if (err < 0)
return err;
err = build_input(codec);
if (err < 0)
return err;
err = build_digital_output(codec);
if (err < 0)
return err;
err = build_digital_input(codec);
if (err < 0)
return err;
err = cs_init(codec);
if (err < 0)
return err;
err = snd_hda_jack_add_kctls(codec, &spec->autocfg);
if (err < 0)
return err;
return 0;
}
static void cs_free(struct hda_codec *codec)
{
struct cs_spec *spec = codec->spec;
kfree(spec->capture_bind[0]);
kfree(spec->capture_bind[1]);
kfree(codec->spec);
}
static void cs_unsol_event(struct hda_codec *codec, unsigned int res)
{
switch (snd_hda_jack_get_action(codec, res >> 26)) {
case HP_EVENT:
cs_automute(codec);
break;
case MIC_EVENT:
cs_automic(codec);
break;
}
snd_hda_jack_report_sync(codec);
}
static int cs_parse_auto_config(struct hda_codec *codec)
{
struct cs_spec *spec = codec->spec;
int err;
err = snd_hda_parse_pin_def_config(codec, &spec->autocfg, NULL);
if (err < 0)
return err;
err = parse_output(codec);
if (err < 0)
return err;
err = parse_input(codec);
if (err < 0)
return err;
err = parse_digital_output(codec);
if (err < 0)
return err;
err = parse_digital_input(codec);
if (err < 0)
return err;
return 0;
}
static void fix_pincfg(struct hda_codec *codec, int model,
const struct cs_pincfg **pin_configs)
{
const struct cs_pincfg *cfg = pin_configs[model];
if (!cfg)
return;
for (; cfg->nid; cfg++)
snd_hda_codec_set_pincfg(codec, cfg->nid, cfg->val);
}
static int patch_cs420x(struct hda_codec *codec)
{
struct cs_spec *spec;
int err;
spec = kzalloc(sizeof(*spec), GFP_KERNEL);
if (!spec)
return -ENOMEM;
codec->spec = spec;
spec->vendor_nid = CS420X_VENDOR_NID;
spec->board_config =
snd_hda_check_board_config(codec, CS420X_MODELS,
cs420x_models, cs420x_cfg_tbl);
if (spec->board_config < 0)
spec->board_config =
snd_hda_check_board_codec_sid_config(codec,
CS420X_MODELS, NULL, cs420x_codec_cfg_tbl);
if (spec->board_config >= 0)
fix_pincfg(codec, spec->board_config, cs_pincfgs);
switch (spec->board_config) {
case CS420X_IMAC27:
case CS420X_MBP53:
case CS420X_MBP55:
case CS420X_APPLE:
spec->gpio_eapd_hp = 2;
spec->gpio_eapd_speaker = 8;
spec->gpio_mask = spec->gpio_dir =
spec->gpio_eapd_hp | spec->gpio_eapd_speaker;
break;
case CS420X_IMAC27_122:
spec->gpio_eapd_hp = 4;
spec->gpio_eapd_speaker = 8;
spec->gpio_mask = spec->gpio_dir =
spec->gpio_eapd_hp | spec->gpio_eapd_speaker;
break;
}
err = cs_parse_auto_config(codec);
if (err < 0)
goto error;
codec->patch_ops = cs_patch_ops;
return 0;
error:
kfree(codec->spec);
codec->spec = NULL;
return err;
}
static int cs421x_boost_vol_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = 1;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = 3;
return 0;
}
static int cs421x_boost_vol_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
ucontrol->value.integer.value[0] =
cs_vendor_coef_get(codec, CS421X_IDX_SPK_CTL) & 0x0003;
return 0;
}
static int cs421x_boost_vol_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
unsigned int vol = ucontrol->value.integer.value[0];
unsigned int coef =
cs_vendor_coef_get(codec, CS421X_IDX_SPK_CTL);
unsigned int original_coef = coef;
coef &= ~0x0003;
coef |= (vol & 0x0003);
if (original_coef == coef)
return 0;
else {
cs_vendor_coef_set(codec, CS421X_IDX_SPK_CTL, coef);
return 1;
}
}
static void cs4210_pinmux_init(struct hda_codec *codec)
{
struct cs_spec *spec = codec->spec;
unsigned int def_conf, coef;
coef = cs_vendor_coef_get(codec, CS421X_IDX_DEV_CFG);
if (spec->gpio_mask)
coef |= 0x0008;
else
coef &= ~0x0008;
if (spec->sense_b)
coef |= 0x0010;
else
coef &= ~0x0010;
cs_vendor_coef_set(codec, CS421X_IDX_DEV_CFG, coef);
if ((spec->gpio_mask || spec->sense_b) &&
is_active_pin(codec, CS421X_DMIC_PIN_NID)) {
def_conf = snd_hda_codec_get_pincfg(codec, CS421X_DMIC_PIN_NID);
def_conf &= ~AC_DEFCFG_PORT_CONN;
def_conf |= (AC_JACK_PORT_NONE << AC_DEFCFG_PORT_CONN_SHIFT);
snd_hda_codec_set_pincfg(codec, CS421X_DMIC_PIN_NID, def_conf);
}
}
static void init_cs421x_digital(struct hda_codec *codec)
{
struct cs_spec *spec = codec->spec;
struct auto_pin_cfg *cfg = &spec->autocfg;
int i;
for (i = 0; i < cfg->dig_outs; i++) {
hda_nid_t nid = cfg->dig_out_pins[i];
if (!cfg->speaker_outs)
continue;
if (get_wcaps(codec, nid) & AC_WCAP_UNSOL_CAP) {
snd_hda_jack_detect_enable(codec, nid, SPDIF_EVENT);
spec->spdif_detect = 1;
}
}
}
static int cs421x_init(struct hda_codec *codec)
{
struct cs_spec *spec = codec->spec;
if (spec->vendor_nid == CS4210_VENDOR_NID) {
snd_hda_sequence_write(codec, cs421x_coef_init_verbs);
snd_hda_sequence_write(codec, cs421x_coef_init_verbs_A1_silicon_fixes);
cs4210_pinmux_init(codec);
}
if (spec->gpio_mask) {
snd_hda_codec_write(codec, 0x01, 0, AC_VERB_SET_GPIO_MASK,
spec->gpio_mask);
snd_hda_codec_write(codec, 0x01, 0, AC_VERB_SET_GPIO_DIRECTION,
spec->gpio_dir);
snd_hda_codec_write(codec, 0x01, 0, AC_VERB_SET_GPIO_DATA,
spec->gpio_data);
}
init_output(codec);
init_input(codec);
init_cs421x_digital(codec);
snd_hda_jack_report_sync(codec);
return 0;
}
static int cs421x_mux_enum_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct cs_spec *spec = codec->spec;
return snd_hda_input_mux_info(&spec->input_mux, uinfo);
}
static int cs421x_mux_enum_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct cs_spec *spec = codec->spec;
ucontrol->value.enumerated.item[0] = spec->cur_input;
return 0;
}
static int cs421x_mux_enum_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct cs_spec *spec = codec->spec;
return snd_hda_input_mux_put(codec, &spec->input_mux, ucontrol,
spec->adc_nid[0], &spec->cur_input);
}
static int cs421x_add_input_volume_control(struct hda_codec *codec, int item)
{
struct cs_spec *spec = codec->spec;
struct auto_pin_cfg *cfg = &spec->autocfg;
const struct hda_input_mux *imux = &spec->input_mux;
hda_nid_t pin = cfg->inputs[item].pin;
struct snd_kcontrol *kctl;
u32 caps;
if (!(get_wcaps(codec, pin) & AC_WCAP_IN_AMP))
return 0;
caps = query_amp_caps(codec, pin, HDA_INPUT);
caps = (caps & AC_AMPCAP_NUM_STEPS) >> AC_AMPCAP_NUM_STEPS_SHIFT;
if (caps <= 1)
return 0;
return add_volume(codec, imux->items[item].label, 0,
HDA_COMPOSE_AMP_VAL(pin, 3, 0, HDA_INPUT), 1, &kctl);
}
static int build_cs421x_input(struct hda_codec *codec)
{
struct cs_spec *spec = codec->spec;
struct auto_pin_cfg *cfg = &spec->autocfg;
struct hda_input_mux *imux = &spec->input_mux;
int i, err, type_idx;
const char *label;
if (!spec->num_inputs)
return 0;
spec->capture_bind[0] = make_bind_capture(codec, &snd_hda_bind_sw);
spec->capture_bind[1] = make_bind_capture(codec, &snd_hda_bind_vol);
for (i = 0; i < 2; i++) {
struct snd_kcontrol *kctl;
int n;
if (!spec->capture_bind[i])
return -ENOMEM;
kctl = snd_ctl_new1(&cs_capture_ctls[i], codec);
if (!kctl)
return -ENOMEM;
kctl->private_value = (long)spec->capture_bind[i];
err = snd_hda_ctl_add(codec, 0, kctl);
if (err < 0)
return err;
for (n = 0; n < AUTO_PIN_LAST; n++) {
if (!spec->adc_nid[n])
continue;
err = snd_hda_add_nid(codec, kctl, 0, spec->adc_nid[n]);
if (err < 0)
return err;
}
}
for (i = 0; i < spec->num_inputs; i++) {
label = hda_get_autocfg_input_label(codec, cfg, i);
snd_hda_add_imux_item(imux, label, spec->adc_idx[i], &type_idx);
err = cs421x_add_input_volume_control(codec, i);
if (err < 0)
return err;
}
if ((spec->num_inputs == 2 && !spec->mic_detect) ||
(spec->num_inputs == 3)) {
err = snd_hda_ctl_add(codec, spec->adc_nid[0],
snd_ctl_new1(&cs421x_capture_source, codec));
if (err < 0)
return err;
}
return 0;
}
static int build_cs421x_output(struct hda_codec *codec)
{
hda_nid_t dac = CS4210_DAC_NID;
struct cs_spec *spec = codec->spec;
struct auto_pin_cfg *cfg = &spec->autocfg;
struct snd_kcontrol *kctl;
int err;
char *name = "Master";
fix_volume_caps(codec, dac);
err = add_mute(codec, name, 0,
HDA_COMPOSE_AMP_VAL(dac, 3, 0, HDA_OUTPUT), 0, &kctl);
if (err < 0)
return err;
err = add_volume(codec, name, 0,
HDA_COMPOSE_AMP_VAL(dac, 3, 0, HDA_OUTPUT), 0, &kctl);
if (err < 0)
return err;
if (cfg->speaker_outs && (spec->vendor_nid == CS4210_VENDOR_NID)) {
err = snd_hda_ctl_add(codec, 0,
snd_ctl_new1(&cs421x_speaker_bost_ctl, codec));
if (err < 0)
return err;
}
return err;
}
static int cs421x_build_controls(struct hda_codec *codec)
{
struct cs_spec *spec = codec->spec;
int err;
err = build_cs421x_output(codec);
if (err < 0)
return err;
err = build_cs421x_input(codec);
if (err < 0)
return err;
err = build_digital_output(codec);
if (err < 0)
return err;
err = cs421x_init(codec);
if (err < 0)
return err;
err = snd_hda_jack_add_kctls(codec, &spec->autocfg);
if (err < 0)
return err;
return 0;
}
static void cs421x_unsol_event(struct hda_codec *codec, unsigned int res)
{
switch (snd_hda_jack_get_action(codec, res >> 26)) {
case HP_EVENT:
case SPDIF_EVENT:
cs_automute(codec);
break;
case MIC_EVENT:
cs_automic(codec);
break;
}
snd_hda_jack_report_sync(codec);
}
static int parse_cs421x_input(struct hda_codec *codec)
{
struct cs_spec *spec = codec->spec;
struct auto_pin_cfg *cfg = &spec->autocfg;
int i;
for (i = 0; i < cfg->num_inputs; i++) {
hda_nid_t pin = cfg->inputs[i].pin;
spec->adc_nid[i] = get_adc(codec, pin, &spec->adc_idx[i]);
spec->cur_input = spec->last_input = i;
spec->num_inputs++;
if (is_ext_mic(codec, i) && cfg->num_inputs >= 2) {
spec->mic_detect = 1;
spec->automic_idx = i;
}
}
return 0;
}
static int cs421x_parse_auto_config(struct hda_codec *codec)
{
struct cs_spec *spec = codec->spec;
int err;
err = snd_hda_parse_pin_def_config(codec, &spec->autocfg, NULL);
if (err < 0)
return err;
err = parse_output(codec);
if (err < 0)
return err;
err = parse_cs421x_input(codec);
if (err < 0)
return err;
err = parse_digital_output(codec);
if (err < 0)
return err;
return 0;
}
static int cs421x_suspend(struct hda_codec *codec, pm_message_t state)
{
struct cs_spec *spec = codec->spec;
unsigned int coef;
snd_hda_shutup_pins(codec);
snd_hda_codec_write(codec, CS4210_DAC_NID, 0,
AC_VERB_SET_POWER_STATE, AC_PWRST_D3);
snd_hda_codec_write(codec, CS4210_ADC_NID, 0,
AC_VERB_SET_POWER_STATE, AC_PWRST_D3);
if (spec->vendor_nid == CS4210_VENDOR_NID) {
coef = cs_vendor_coef_get(codec, CS421X_IDX_DEV_CFG);
coef |= 0x0004;
cs_vendor_coef_set(codec, CS421X_IDX_DEV_CFG, coef);
}
return 0;
}
static int patch_cs4210(struct hda_codec *codec)
{
struct cs_spec *spec;
int err;
spec = kzalloc(sizeof(*spec), GFP_KERNEL);
if (!spec)
return -ENOMEM;
codec->spec = spec;
spec->vendor_nid = CS4210_VENDOR_NID;
spec->board_config =
snd_hda_check_board_config(codec, CS421X_MODELS,
cs421x_models, cs421x_cfg_tbl);
if (spec->board_config >= 0)
fix_pincfg(codec, spec->board_config, cs421x_pincfgs);
switch (spec->board_config) {
case CS421X_CDB4210:
snd_printd("CS4210 board: %s\n",
cs421x_models[spec->board_config]);
spec->sense_b = 1;
break;
}
cs4210_pinmux_init(codec);
err = cs421x_parse_auto_config(codec);
if (err < 0)
goto error;
codec->patch_ops = cs421x_patch_ops;
return 0;
error:
kfree(codec->spec);
codec->spec = NULL;
return err;
}
static int patch_cs4213(struct hda_codec *codec)
{
struct cs_spec *spec;
int err;
spec = kzalloc(sizeof(*spec), GFP_KERNEL);
if (!spec)
return -ENOMEM;
codec->spec = spec;
spec->vendor_nid = CS4213_VENDOR_NID;
err = cs421x_parse_auto_config(codec);
if (err < 0)
goto error;
codec->patch_ops = cs421x_patch_ops;
return 0;
error:
kfree(codec->spec);
codec->spec = NULL;
return err;
}
static int __init patch_cirrus_init(void)
{
return snd_hda_add_codec_preset(&cirrus_list);
}
static void __exit patch_cirrus_exit(void)
{
snd_hda_delete_codec_preset(&cirrus_list);
}
