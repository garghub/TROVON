static int stac92xx_dmux_enum_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct sigmatel_spec *spec = codec->spec;
return snd_hda_input_mux_info(spec->dinput_mux, uinfo);
}
static int stac92xx_dmux_enum_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct sigmatel_spec *spec = codec->spec;
unsigned int dmux_idx = snd_ctl_get_ioffidx(kcontrol, &ucontrol->id);
ucontrol->value.enumerated.item[0] = spec->cur_dmux[dmux_idx];
return 0;
}
static int stac92xx_dmux_enum_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct sigmatel_spec *spec = codec->spec;
unsigned int dmux_idx = snd_ctl_get_ioffidx(kcontrol, &ucontrol->id);
return snd_hda_input_mux_put(codec, spec->dinput_mux, ucontrol,
spec->dmux_nids[dmux_idx], &spec->cur_dmux[dmux_idx]);
}
static int stac92xx_smux_enum_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct sigmatel_spec *spec = codec->spec;
return snd_hda_input_mux_info(spec->sinput_mux, uinfo);
}
static int stac92xx_smux_enum_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct sigmatel_spec *spec = codec->spec;
unsigned int smux_idx = snd_ctl_get_ioffidx(kcontrol, &ucontrol->id);
ucontrol->value.enumerated.item[0] = spec->cur_smux[smux_idx];
return 0;
}
static int stac92xx_smux_enum_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct sigmatel_spec *spec = codec->spec;
struct hda_input_mux *smux = &spec->private_smux;
unsigned int smux_idx = snd_ctl_get_ioffidx(kcontrol, &ucontrol->id);
int err, val;
hda_nid_t nid;
err = snd_hda_input_mux_put(codec, spec->sinput_mux, ucontrol,
spec->smux_nids[smux_idx], &spec->cur_smux[smux_idx]);
if (err < 0)
return err;
if (spec->spdif_mute) {
if (smux_idx == 0)
nid = spec->multiout.dig_out_nid;
else
nid = codec->slave_dig_outs[smux_idx - 1];
if (spec->cur_smux[smux_idx] == smux->num_items - 1)
val = HDA_AMP_MUTE;
else
val = 0;
snd_hda_codec_amp_stereo(codec, nid, HDA_OUTPUT, 0,
HDA_AMP_MUTE, val);
}
return 0;
}
static int stac_vrefout_set(struct hda_codec *codec,
hda_nid_t nid, unsigned int new_vref)
{
int error, pinctl;
snd_printdd("%s, nid %x ctl %x\n", __func__, nid, new_vref);
pinctl = snd_hda_codec_read(codec, nid, 0,
AC_VERB_GET_PIN_WIDGET_CONTROL, 0);
if (pinctl < 0)
return pinctl;
pinctl &= 0xff;
pinctl &= ~AC_PINCTL_VREFEN;
pinctl |= (new_vref & AC_PINCTL_VREFEN);
error = snd_hda_codec_write_cache(codec, nid, 0,
AC_VERB_SET_PIN_WIDGET_CONTROL, pinctl);
if (error < 0)
return error;
return 1;
}
static unsigned int stac92xx_vref_set(struct hda_codec *codec,
hda_nid_t nid, unsigned int new_vref)
{
int error;
unsigned int pincfg;
pincfg = snd_hda_codec_read(codec, nid, 0,
AC_VERB_GET_PIN_WIDGET_CONTROL, 0);
pincfg &= 0xff;
pincfg &= ~(AC_PINCTL_VREFEN | AC_PINCTL_IN_EN | AC_PINCTL_OUT_EN);
pincfg |= new_vref;
if (new_vref == AC_PINCTL_VREF_HIZ)
pincfg |= AC_PINCTL_OUT_EN;
else
pincfg |= AC_PINCTL_IN_EN;
error = snd_hda_codec_write_cache(codec, nid, 0,
AC_VERB_SET_PIN_WIDGET_CONTROL, pincfg);
if (error < 0)
return error;
else
return 1;
}
static unsigned int stac92xx_vref_get(struct hda_codec *codec, hda_nid_t nid)
{
unsigned int vref;
vref = snd_hda_codec_read(codec, nid, 0,
AC_VERB_GET_PIN_WIDGET_CONTROL, 0);
vref &= AC_PINCTL_VREFEN;
return vref;
}
static int stac92xx_mux_enum_info(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_info *uinfo)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct sigmatel_spec *spec = codec->spec;
return snd_hda_input_mux_info(spec->input_mux, uinfo);
}
static int stac92xx_mux_enum_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct sigmatel_spec *spec = codec->spec;
unsigned int adc_idx = snd_ctl_get_ioffidx(kcontrol, &ucontrol->id);
ucontrol->value.enumerated.item[0] = spec->cur_mux[adc_idx];
return 0;
}
static int stac92xx_mux_enum_put(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct sigmatel_spec *spec = codec->spec;
unsigned int adc_idx = snd_ctl_get_ioffidx(kcontrol, &ucontrol->id);
const struct hda_input_mux *imux = spec->input_mux;
unsigned int idx, prev_idx, didx;
idx = ucontrol->value.enumerated.item[0];
if (idx >= imux->num_items)
idx = imux->num_items - 1;
prev_idx = spec->cur_mux[adc_idx];
if (prev_idx == idx)
return 0;
if (idx < spec->num_analog_muxes) {
snd_hda_codec_write_cache(codec, spec->mux_nids[adc_idx], 0,
AC_VERB_SET_CONNECT_SEL,
imux->items[idx].index);
if (prev_idx >= spec->num_analog_muxes &&
spec->mux_nids[adc_idx] != spec->dmux_nids[adc_idx]) {
imux = spec->dinput_mux;
snd_hda_codec_write_cache(codec,
spec->dmux_nids[adc_idx], 0,
AC_VERB_SET_CONNECT_SEL,
imux->items[0].index);
}
} else {
imux = spec->dinput_mux;
didx = idx - spec->num_analog_muxes + 1;
snd_hda_codec_write_cache(codec, spec->dmux_nids[adc_idx], 0,
AC_VERB_SET_CONNECT_SEL,
imux->items[didx].index);
}
spec->cur_mux[adc_idx] = idx;
return 1;
}
static int stac92xx_mono_mux_enum_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct sigmatel_spec *spec = codec->spec;
return snd_hda_input_mux_info(spec->mono_mux, uinfo);
}
static int stac92xx_mono_mux_enum_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct sigmatel_spec *spec = codec->spec;
ucontrol->value.enumerated.item[0] = spec->cur_mmux;
return 0;
}
static int stac92xx_mono_mux_enum_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct sigmatel_spec *spec = codec->spec;
return snd_hda_input_mux_put(codec, spec->mono_mux, ucontrol,
spec->mono_nid, &spec->cur_mmux);
}
static int stac92xx_aloopback_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
unsigned int idx = snd_ctl_get_ioffidx(kcontrol, &ucontrol->id);
struct sigmatel_spec *spec = codec->spec;
ucontrol->value.integer.value[0] = !!(spec->aloopback &
(spec->aloopback_mask << idx));
return 0;
}
static int stac92xx_aloopback_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct sigmatel_spec *spec = codec->spec;
unsigned int idx = snd_ctl_get_ioffidx(kcontrol, &ucontrol->id);
unsigned int dac_mode;
unsigned int val, idx_val;
idx_val = spec->aloopback_mask << idx;
if (ucontrol->value.integer.value[0])
val = spec->aloopback | idx_val;
else
val = spec->aloopback & ~idx_val;
if (spec->aloopback == val)
return 0;
spec->aloopback = val;
dac_mode = snd_hda_codec_read(codec, codec->afg, 0,
kcontrol->private_value & 0xFFFF, 0x0);
dac_mode >>= spec->aloopback_shift;
if (spec->aloopback & idx_val) {
snd_hda_power_up(codec);
dac_mode |= idx_val;
} else {
snd_hda_power_down(codec);
dac_mode &= ~idx_val;
}
snd_hda_codec_write_cache(codec, codec->afg, 0,
kcontrol->private_value >> 16, dac_mode);
return 1;
}
static int stac92xx_build_controls(struct hda_codec *codec)
{
struct sigmatel_spec *spec = codec->spec;
struct auto_pin_cfg *cfg = &spec->autocfg;
hda_nid_t nid;
int err;
int i;
if (spec->mixer) {
err = snd_hda_add_new_ctls(codec, spec->mixer);
if (err < 0)
return err;
}
for (i = 0; i < spec->num_mixers; i++) {
err = snd_hda_add_new_ctls(codec, spec->mixers[i]);
if (err < 0)
return err;
}
if (!spec->auto_mic && spec->num_dmuxes > 0 &&
snd_hda_get_bool_hint(codec, "separate_dmux") == 1) {
stac_dmux_mixer.count = spec->num_dmuxes;
err = snd_hda_ctl_add(codec, 0,
snd_ctl_new1(&stac_dmux_mixer, codec));
if (err < 0)
return err;
}
if (spec->num_smuxes > 0) {
int wcaps = get_wcaps(codec, spec->multiout.dig_out_nid);
struct hda_input_mux *smux = &spec->private_smux;
if (wcaps & AC_WCAP_OUT_AMP) {
snd_hda_add_imux_item(smux, "Off", 0, NULL);
spec->spdif_mute = 1;
}
stac_smux_mixer.count = spec->num_smuxes;
err = snd_hda_ctl_add(codec, 0,
snd_ctl_new1(&stac_smux_mixer, codec));
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
if (spec->dig_in_nid && !(spec->gpio_dir & 0x01)) {
err = snd_hda_create_spdif_in_ctls(codec, spec->dig_in_nid);
if (err < 0)
return err;
}
if (!snd_hda_find_mixer_ctl(codec, "Master Playback Volume")) {
unsigned int vmaster_tlv[4];
snd_hda_set_vmaster_tlv(codec, spec->multiout.dac_nids[0],
HDA_OUTPUT, vmaster_tlv);
vmaster_tlv[2] += vmaster_tlv[3] * spec->volume_offset;
vmaster_tlv[3] |= TLV_DB_SCALE_MUTE;
err = snd_hda_add_vmaster(codec, "Master Playback Volume",
vmaster_tlv, slave_vols);
if (err < 0)
return err;
}
if (!snd_hda_find_mixer_ctl(codec, "Master Playback Switch")) {
err = snd_hda_add_vmaster(codec, "Master Playback Switch",
NULL, slave_sws);
if (err < 0)
return err;
}
if (spec->aloopback_ctl &&
snd_hda_get_bool_hint(codec, "loopback") == 1) {
err = snd_hda_add_new_ctls(codec, spec->aloopback_ctl);
if (err < 0)
return err;
}
stac92xx_free_kctls(codec);
if (spec->hp_detect) {
for (i = 0; i < cfg->hp_outs; i++) {
int type = SND_JACK_HEADPHONE;
nid = cfg->hp_pins[i];
if (cfg->hp_outs == i)
type |= SND_JACK_LINEOUT;
err = stac92xx_add_jack(codec, nid, type);
if (err < 0)
return err;
}
}
for (i = 0; i < cfg->line_outs; i++) {
err = stac92xx_add_jack(codec, cfg->line_out_pins[i],
SND_JACK_LINEOUT);
if (err < 0)
return err;
}
for (i = 0; i < cfg->num_inputs; i++) {
nid = cfg->inputs[i].pin;
err = stac92xx_add_jack(codec, nid, SND_JACK_MICROPHONE);
if (err < 0)
return err;
}
return 0;
}
static void stac92xx_set_config_regs(struct hda_codec *codec,
const unsigned int *pincfgs)
{
int i;
struct sigmatel_spec *spec = codec->spec;
if (!pincfgs)
return;
for (i = 0; i < spec->num_pins; i++)
if (spec->pin_nids[i] && pincfgs[i])
snd_hda_codec_set_pincfg(codec, spec->pin_nids[i],
pincfgs[i]);
}
static int stac92xx_playback_pcm_open(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
struct snd_pcm_substream *substream)
{
struct sigmatel_spec *spec = codec->spec;
if (spec->stream_delay)
msleep(spec->stream_delay);
return snd_hda_multi_out_analog_open(codec, &spec->multiout, substream,
hinfo);
}
static int stac92xx_playback_pcm_prepare(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
unsigned int stream_tag,
unsigned int format,
struct snd_pcm_substream *substream)
{
struct sigmatel_spec *spec = codec->spec;
return snd_hda_multi_out_analog_prepare(codec, &spec->multiout, stream_tag, format, substream);
}
static int stac92xx_playback_pcm_cleanup(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
struct snd_pcm_substream *substream)
{
struct sigmatel_spec *spec = codec->spec;
return snd_hda_multi_out_analog_cleanup(codec, &spec->multiout);
}
static int stac92xx_dig_playback_pcm_open(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
struct snd_pcm_substream *substream)
{
struct sigmatel_spec *spec = codec->spec;
return snd_hda_multi_out_dig_open(codec, &spec->multiout);
}
static int stac92xx_dig_playback_pcm_close(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
struct snd_pcm_substream *substream)
{
struct sigmatel_spec *spec = codec->spec;
return snd_hda_multi_out_dig_close(codec, &spec->multiout);
}
static int stac92xx_dig_playback_pcm_prepare(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
unsigned int stream_tag,
unsigned int format,
struct snd_pcm_substream *substream)
{
struct sigmatel_spec *spec = codec->spec;
return snd_hda_multi_out_dig_prepare(codec, &spec->multiout,
stream_tag, format, substream);
}
static int stac92xx_dig_playback_pcm_cleanup(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
struct snd_pcm_substream *substream)
{
struct sigmatel_spec *spec = codec->spec;
return snd_hda_multi_out_dig_cleanup(codec, &spec->multiout);
}
static int stac92xx_capture_pcm_prepare(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
unsigned int stream_tag,
unsigned int format,
struct snd_pcm_substream *substream)
{
struct sigmatel_spec *spec = codec->spec;
hda_nid_t nid = spec->adc_nids[substream->number];
if (spec->powerdown_adcs) {
msleep(40);
snd_hda_codec_write(codec, nid, 0,
AC_VERB_SET_POWER_STATE, AC_PWRST_D0);
}
snd_hda_codec_setup_stream(codec, nid, stream_tag, 0, format);
return 0;
}
static int stac92xx_capture_pcm_cleanup(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
struct snd_pcm_substream *substream)
{
struct sigmatel_spec *spec = codec->spec;
hda_nid_t nid = spec->adc_nids[substream->number];
snd_hda_codec_cleanup_stream(codec, nid);
if (spec->powerdown_adcs)
snd_hda_codec_write(codec, nid, 0,
AC_VERB_SET_POWER_STATE, AC_PWRST_D3);
return 0;
}
static int stac92xx_build_pcms(struct hda_codec *codec)
{
struct sigmatel_spec *spec = codec->spec;
struct hda_pcm *info = spec->pcm_rec;
codec->num_pcms = 1;
codec->pcm_info = info;
info->name = "STAC92xx Analog";
info->stream[SNDRV_PCM_STREAM_PLAYBACK] = stac92xx_pcm_analog_playback;
info->stream[SNDRV_PCM_STREAM_PLAYBACK].nid =
spec->multiout.dac_nids[0];
info->stream[SNDRV_PCM_STREAM_CAPTURE] = stac92xx_pcm_analog_capture;
info->stream[SNDRV_PCM_STREAM_CAPTURE].nid = spec->adc_nids[0];
info->stream[SNDRV_PCM_STREAM_CAPTURE].substreams = spec->num_adcs;
if (spec->alt_switch) {
codec->num_pcms++;
info++;
info->name = "STAC92xx Analog Alt";
info->stream[SNDRV_PCM_STREAM_PLAYBACK] = stac92xx_pcm_analog_alt_playback;
}
if (spec->multiout.dig_out_nid || spec->dig_in_nid) {
codec->num_pcms++;
info++;
info->name = "STAC92xx Digital";
info->pcm_type = spec->autocfg.dig_out_type[0];
if (spec->multiout.dig_out_nid) {
info->stream[SNDRV_PCM_STREAM_PLAYBACK] = stac92xx_pcm_digital_playback;
info->stream[SNDRV_PCM_STREAM_PLAYBACK].nid = spec->multiout.dig_out_nid;
}
if (spec->dig_in_nid) {
info->stream[SNDRV_PCM_STREAM_CAPTURE] = stac92xx_pcm_digital_capture;
info->stream[SNDRV_PCM_STREAM_CAPTURE].nid = spec->dig_in_nid;
}
}
return 0;
}
static unsigned int stac92xx_get_default_vref(struct hda_codec *codec,
hda_nid_t nid)
{
unsigned int pincap = snd_hda_query_pin_caps(codec, nid);
pincap = (pincap & AC_PINCAP_VREF) >> AC_PINCAP_VREF_SHIFT;
if (pincap & AC_PINCAP_VREF_100)
return AC_PINCTL_VREF_100;
if (pincap & AC_PINCAP_VREF_80)
return AC_PINCTL_VREF_80;
if (pincap & AC_PINCAP_VREF_50)
return AC_PINCTL_VREF_50;
if (pincap & AC_PINCAP_VREF_GRD)
return AC_PINCTL_VREF_GRD;
return 0;
}
static void stac92xx_auto_set_pinctl(struct hda_codec *codec, hda_nid_t nid, int pin_type)
{
snd_hda_codec_write_cache(codec, nid, 0,
AC_VERB_SET_PIN_WIDGET_CONTROL, pin_type);
}
static int stac92xx_hp_switch_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct sigmatel_spec *spec = codec->spec;
ucontrol->value.integer.value[0] = !!spec->hp_switch;
return 0;
}
static int stac92xx_hp_switch_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct sigmatel_spec *spec = codec->spec;
int nid = kcontrol->private_value;
spec->hp_switch = ucontrol->value.integer.value[0] ? nid : 0;
stac_issue_unsol_event(codec, nid);
return 1;
}
static int stac92xx_dc_bias_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
int i;
static const char * const texts[] = {
"Mic In", "Line In", "Line Out"
};
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct sigmatel_spec *spec = codec->spec;
hda_nid_t nid = kcontrol->private_value;
if (nid == spec->mic_switch || nid == spec->line_switch)
i = 3;
else
i = 2;
uinfo->type = SNDRV_CTL_ELEM_TYPE_ENUMERATED;
uinfo->value.enumerated.items = i;
uinfo->count = 1;
if (uinfo->value.enumerated.item >= i)
uinfo->value.enumerated.item = i-1;
strcpy(uinfo->value.enumerated.name,
texts[uinfo->value.enumerated.item]);
return 0;
}
static int stac92xx_dc_bias_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
hda_nid_t nid = kcontrol->private_value;
unsigned int vref = stac92xx_vref_get(codec, nid);
if (vref == stac92xx_get_default_vref(codec, nid))
ucontrol->value.enumerated.item[0] = 0;
else if (vref == AC_PINCTL_VREF_GRD)
ucontrol->value.enumerated.item[0] = 1;
else if (vref == AC_PINCTL_VREF_HIZ)
ucontrol->value.enumerated.item[0] = 2;
return 0;
}
static int stac92xx_dc_bias_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
unsigned int new_vref = 0;
int error;
hda_nid_t nid = kcontrol->private_value;
if (ucontrol->value.enumerated.item[0] == 0)
new_vref = stac92xx_get_default_vref(codec, nid);
else if (ucontrol->value.enumerated.item[0] == 1)
new_vref = AC_PINCTL_VREF_GRD;
else if (ucontrol->value.enumerated.item[0] == 2)
new_vref = AC_PINCTL_VREF_HIZ;
else
return 0;
if (new_vref != stac92xx_vref_get(codec, nid)) {
error = stac92xx_vref_set(codec, nid, new_vref);
return error;
}
return 0;
}
static int stac92xx_io_switch_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
char *texts[2];
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct sigmatel_spec *spec = codec->spec;
if (kcontrol->private_value == spec->line_switch)
texts[0] = "Line In";
else
texts[0] = "Mic In";
texts[1] = "Line Out";
uinfo->type = SNDRV_CTL_ELEM_TYPE_ENUMERATED;
uinfo->value.enumerated.items = 2;
uinfo->count = 1;
if (uinfo->value.enumerated.item >= 2)
uinfo->value.enumerated.item = 1;
strcpy(uinfo->value.enumerated.name,
texts[uinfo->value.enumerated.item]);
return 0;
}
static int stac92xx_io_switch_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct sigmatel_spec *spec = codec->spec;
hda_nid_t nid = kcontrol->private_value;
int io_idx = (nid == spec->mic_switch) ? 1 : 0;
ucontrol->value.enumerated.item[0] = spec->io_switch[io_idx];
return 0;
}
static int stac92xx_io_switch_put(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct sigmatel_spec *spec = codec->spec;
hda_nid_t nid = kcontrol->private_value;
int io_idx = (nid == spec->mic_switch) ? 1 : 0;
unsigned short val = !!ucontrol->value.enumerated.item[0];
spec->io_switch[io_idx] = val;
if (val)
stac92xx_auto_set_pinctl(codec, nid, AC_PINCTL_OUT_EN);
else {
unsigned int pinctl = AC_PINCTL_IN_EN;
if (io_idx)
pinctl |= stac92xx_get_default_vref(codec, nid);
stac92xx_auto_set_pinctl(codec, nid, pinctl);
}
if (spec->hp_detect)
stac_issue_unsol_event(codec, nid);
return 1;
}
static int stac92xx_clfe_switch_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct sigmatel_spec *spec = codec->spec;
ucontrol->value.integer.value[0] = spec->clfe_swap;
return 0;
}
static int stac92xx_clfe_switch_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct sigmatel_spec *spec = codec->spec;
hda_nid_t nid = kcontrol->private_value & 0xff;
unsigned int val = !!ucontrol->value.integer.value[0];
if (spec->clfe_swap == val)
return 0;
spec->clfe_swap = val;
snd_hda_codec_write_cache(codec, nid, 0, AC_VERB_SET_EAPD_BTLENABLE,
spec->clfe_swap ? 0x4 : 0x0);
return 1;
}
static struct snd_kcontrol_new *
stac_control_new(struct sigmatel_spec *spec,
const struct snd_kcontrol_new *ktemp,
const char *name,
unsigned int subdev)
{
struct snd_kcontrol_new *knew;
snd_array_init(&spec->kctls, sizeof(*knew), 32);
knew = snd_array_new(&spec->kctls);
if (!knew)
return NULL;
*knew = *ktemp;
knew->name = kstrdup(name, GFP_KERNEL);
if (!knew->name) {
memset(knew, 0, sizeof(*knew));
spec->kctls.alloced--;
return NULL;
}
knew->subdevice = subdev;
return knew;
}
static int stac92xx_add_control_temp(struct sigmatel_spec *spec,
const struct snd_kcontrol_new *ktemp,
int idx, const char *name,
unsigned long val)
{
struct snd_kcontrol_new *knew = stac_control_new(spec, ktemp, name,
HDA_SUBDEV_AMP_FLAG);
if (!knew)
return -ENOMEM;
knew->index = idx;
knew->private_value = val;
return 0;
}
static inline int stac92xx_add_control_idx(struct sigmatel_spec *spec,
int type, int idx, const char *name,
unsigned long val)
{
return stac92xx_add_control_temp(spec,
&stac92xx_control_templates[type],
idx, name, val);
}
static inline int stac92xx_add_control(struct sigmatel_spec *spec, int type,
const char *name, unsigned long val)
{
return stac92xx_add_control_idx(spec, type, 0, name, val);
}
static inline int stac92xx_add_jack_mode_control(struct hda_codec *codec,
hda_nid_t nid, int idx)
{
int def_conf = snd_hda_codec_get_pincfg(codec, nid);
int control = 0;
struct sigmatel_spec *spec = codec->spec;
char name[22];
if (snd_hda_get_input_pin_attr(def_conf) != INPUT_PIN_ATTR_INT) {
if (stac92xx_get_default_vref(codec, nid) == AC_PINCTL_VREF_GRD
&& nid == spec->line_switch)
control = STAC_CTL_WIDGET_IO_SWITCH;
else if (snd_hda_query_pin_caps(codec, nid)
& (AC_PINCAP_VREF_GRD << AC_PINCAP_VREF_SHIFT))
control = STAC_CTL_WIDGET_DC_BIAS;
else if (nid == spec->mic_switch)
control = STAC_CTL_WIDGET_IO_SWITCH;
}
if (control) {
strcpy(name, hda_get_input_pin_label(codec, nid, 1));
return stac92xx_add_control(codec->spec, control,
strcat(name, " Jack Mode"), nid);
}
return 0;
}
static int stac92xx_add_input_source(struct sigmatel_spec *spec)
{
struct snd_kcontrol_new *knew;
struct hda_input_mux *imux = &spec->private_imux;
if (spec->auto_mic)
return 0;
if (!spec->num_adcs || imux->num_items <= 1)
return 0;
knew = stac_control_new(spec, &stac_input_src_temp,
stac_input_src_temp.name, 0);
if (!knew)
return -ENOMEM;
knew->count = spec->num_adcs;
return 0;
}
static hda_nid_t check_line_out_switch(struct hda_codec *codec)
{
struct sigmatel_spec *spec = codec->spec;
struct auto_pin_cfg *cfg = &spec->autocfg;
hda_nid_t nid;
unsigned int pincap;
int i;
if (cfg->line_out_type != AUTO_PIN_LINE_OUT)
return 0;
for (i = 0; i < cfg->num_inputs; i++) {
if (cfg->inputs[i].type == AUTO_PIN_LINE_IN) {
nid = cfg->inputs[i].pin;
pincap = snd_hda_query_pin_caps(codec, nid);
if (pincap & AC_PINCAP_OUT)
return nid;
}
}
return 0;
}
static hda_nid_t check_mic_out_switch(struct hda_codec *codec, hda_nid_t *dac)
{
struct sigmatel_spec *spec = codec->spec;
struct auto_pin_cfg *cfg = &spec->autocfg;
unsigned int def_conf, pincap;
int i;
*dac = 0;
if (cfg->line_out_type != AUTO_PIN_LINE_OUT)
return 0;
for (i = 0; i < cfg->num_inputs; i++) {
hda_nid_t nid = cfg->inputs[i].pin;
if (cfg->inputs[i].type != AUTO_PIN_MIC)
continue;
def_conf = snd_hda_codec_get_pincfg(codec, nid);
if (snd_hda_get_input_pin_attr(def_conf) != INPUT_PIN_ATTR_INT) {
pincap = snd_hda_query_pin_caps(codec, nid);
if (pincap & AC_PINCAP_OUT) {
*dac = get_unassigned_dac(codec, nid);
if (*dac)
return nid;
}
}
}
return 0;
}
static int is_in_dac_nids(struct sigmatel_spec *spec, hda_nid_t nid)
{
int i;
for (i = 0; i < spec->multiout.num_dacs; i++) {
if (spec->multiout.dac_nids[i] == nid)
return 1;
}
return 0;
}
static int check_all_dac_nids(struct sigmatel_spec *spec, hda_nid_t nid)
{
int i;
if (is_in_dac_nids(spec, nid))
return 1;
for (i = 0; i < spec->autocfg.hp_outs; i++)
if (spec->hp_dacs[i] == nid)
return 1;
for (i = 0; i < spec->autocfg.speaker_outs; i++)
if (spec->speaker_dacs[i] == nid)
return 1;
return 0;
}
static hda_nid_t get_unassigned_dac(struct hda_codec *codec, hda_nid_t nid)
{
struct sigmatel_spec *spec = codec->spec;
struct auto_pin_cfg *cfg = &spec->autocfg;
int j, conn_len;
hda_nid_t conn[HDA_MAX_CONNECTIONS], fallback_dac;
unsigned int wcaps, wtype;
conn_len = snd_hda_get_connections(codec, nid, conn,
HDA_MAX_CONNECTIONS);
while (conn_len == 1 && (get_wcaps_type(get_wcaps(codec, conn[0]))
!= AC_WID_AUD_OUT)) {
nid = conn[0];
conn_len = snd_hda_get_connections(codec, nid, conn,
HDA_MAX_CONNECTIONS);
}
for (j = 0; j < conn_len; j++) {
wcaps = get_wcaps(codec, conn[j]);
wtype = get_wcaps_type(wcaps);
if (wtype != AC_WID_AUD_OUT || (wcaps & AC_WCAP_DIGITAL))
continue;
if (!check_all_dac_nids(spec, conn[j])) {
if (conn_len > 1) {
snd_hda_codec_write_cache(codec, nid, 0,
AC_VERB_SET_CONNECT_SEL, j);
}
return conn[j];
}
}
fallback_dac = spec->multiout.dac_nids[0];
if (spec->multiout.hp_nid) {
for (j = 0; j < cfg->hp_outs; j++)
if (cfg->hp_pins[j] == nid) {
fallback_dac = spec->multiout.hp_nid;
break;
}
}
if (conn_len > 1) {
for (j = 0; j < conn_len; j++) {
if (conn[j] == fallback_dac) {
snd_hda_codec_write_cache(codec, nid, 0,
AC_VERB_SET_CONNECT_SEL, j);
break;
}
}
}
return 0;
}
static int stac92xx_auto_fill_dac_nids(struct hda_codec *codec)
{
struct sigmatel_spec *spec = codec->spec;
struct auto_pin_cfg *cfg = &spec->autocfg;
int i;
hda_nid_t nid, dac;
for (i = 0; i < cfg->line_outs; i++) {
nid = cfg->line_out_pins[i];
dac = get_unassigned_dac(codec, nid);
if (!dac) {
if (spec->multiout.num_dacs > 0) {
cfg->line_outs = spec->multiout.num_dacs;
break;
}
snd_printk(KERN_ERR
"%s: No available DAC for pin 0x%x\n",
__func__, nid);
return -ENODEV;
}
add_spec_dacs(spec, dac);
}
for (i = 0; i < cfg->hp_outs; i++) {
nid = cfg->hp_pins[i];
dac = get_unassigned_dac(codec, nid);
if (dac) {
if (!spec->multiout.hp_nid)
spec->multiout.hp_nid = dac;
else
add_spec_extra_dacs(spec, dac);
}
spec->hp_dacs[i] = dac;
}
for (i = 0; i < cfg->speaker_outs; i++) {
nid = cfg->speaker_pins[i];
dac = get_unassigned_dac(codec, nid);
if (dac)
add_spec_extra_dacs(spec, dac);
spec->speaker_dacs[i] = dac;
}
nid = check_line_out_switch(codec);
if (nid) {
dac = get_unassigned_dac(codec, nid);
if (dac) {
snd_printdd("STAC: Add line-in 0x%x as output %d\n",
nid, cfg->line_outs);
cfg->line_out_pins[cfg->line_outs] = nid;
cfg->line_outs++;
spec->line_switch = nid;
add_spec_dacs(spec, dac);
}
}
nid = check_mic_out_switch(codec, &dac);
if (nid && dac) {
snd_printdd("STAC: Add mic-in 0x%x as output %d\n",
nid, cfg->line_outs);
cfg->line_out_pins[cfg->line_outs] = nid;
cfg->line_outs++;
spec->mic_switch = nid;
add_spec_dacs(spec, dac);
}
snd_printd("stac92xx: dac_nids=%d (0x%x/0x%x/0x%x/0x%x/0x%x)\n",
spec->multiout.num_dacs,
spec->multiout.dac_nids[0],
spec->multiout.dac_nids[1],
spec->multiout.dac_nids[2],
spec->multiout.dac_nids[3],
spec->multiout.dac_nids[4]);
return 0;
}
static int create_controls_idx(struct hda_codec *codec, const char *pfx,
int idx, hda_nid_t nid, int chs)
{
struct sigmatel_spec *spec = codec->spec;
char name[32];
int err;
if (!spec->check_volume_offset) {
unsigned int caps, step, nums, db_scale;
caps = query_amp_caps(codec, nid, HDA_OUTPUT);
step = (caps & AC_AMPCAP_STEP_SIZE) >>
AC_AMPCAP_STEP_SIZE_SHIFT;
step = (step + 1) * 25;
nums = (caps & AC_AMPCAP_NUM_STEPS) >>
AC_AMPCAP_NUM_STEPS_SHIFT;
db_scale = nums * step;
if (db_scale > 6400 && nums >= 0x1f)
spec->volume_offset = nums / 2;
spec->check_volume_offset = 1;
}
sprintf(name, "%s Playback Volume", pfx);
err = stac92xx_add_control_idx(spec, STAC_CTL_WIDGET_VOL, idx, name,
HDA_COMPOSE_AMP_VAL_OFS(nid, chs, 0, HDA_OUTPUT,
spec->volume_offset));
if (err < 0)
return err;
sprintf(name, "%s Playback Switch", pfx);
err = stac92xx_add_control_idx(spec, STAC_CTL_WIDGET_MUTE, idx, name,
HDA_COMPOSE_AMP_VAL(nid, chs, 0, HDA_OUTPUT));
if (err < 0)
return err;
return 0;
}
static int add_spec_dacs(struct sigmatel_spec *spec, hda_nid_t nid)
{
if (spec->multiout.num_dacs > 4) {
printk(KERN_WARNING "stac92xx: No space for DAC 0x%x\n", nid);
return 1;
} else {
snd_BUG_ON(spec->multiout.dac_nids != spec->dac_nids);
spec->dac_nids[spec->multiout.num_dacs] = nid;
spec->multiout.num_dacs++;
}
return 0;
}
static int add_spec_extra_dacs(struct sigmatel_spec *spec, hda_nid_t nid)
{
int i;
for (i = 0; i < ARRAY_SIZE(spec->multiout.extra_out_nid); i++) {
if (!spec->multiout.extra_out_nid[i]) {
spec->multiout.extra_out_nid[i] = nid;
return 0;
}
}
printk(KERN_WARNING "stac92xx: No space for extra DAC 0x%x\n", nid);
return 1;
}
static int create_multi_out_ctls(struct hda_codec *codec, int num_outs,
const hda_nid_t *pins,
const hda_nid_t *dac_nids,
int type)
{
struct sigmatel_spec *spec = codec->spec;
static const char * const chname[4] = {
"Front", "Surround", NULL , "Side"
};
hda_nid_t nid;
int i, err;
unsigned int wid_caps;
for (i = 0; i < num_outs && i < ARRAY_SIZE(chname); i++) {
if (type == AUTO_PIN_HP_OUT && !spec->hp_detect) {
if (is_jack_detectable(codec, pins[i]))
spec->hp_detect = 1;
}
nid = dac_nids[i];
if (!nid)
continue;
if (type != AUTO_PIN_HP_OUT && i == 2) {
err = create_controls(codec, "Center", nid, 1);
if (err < 0)
return err;
err = create_controls(codec, "LFE", nid, 2);
if (err < 0)
return err;
wid_caps = get_wcaps(codec, nid);
if (wid_caps & AC_WCAP_LR_SWAP) {
err = stac92xx_add_control(spec,
STAC_CTL_WIDGET_CLFE_SWITCH,
"Swap Center/LFE Playback Switch", nid);
if (err < 0)
return err;
}
} else {
const char *name;
int idx;
switch (type) {
case AUTO_PIN_HP_OUT:
name = "Headphone";
idx = i;
break;
case AUTO_PIN_SPEAKER_OUT:
name = "Speaker";
idx = i;
break;
default:
name = chname[i];
idx = 0;
break;
}
err = create_controls_idx(codec, name, idx, nid, 3);
if (err < 0)
return err;
}
}
return 0;
}
static int stac92xx_add_capvol_ctls(struct hda_codec *codec, unsigned long vol,
unsigned long sw, int idx)
{
int err;
err = stac92xx_add_control_idx(codec->spec, STAC_CTL_WIDGET_VOL, idx,
"Capture Volume", vol);
if (err < 0)
return err;
err = stac92xx_add_control_idx(codec->spec, STAC_CTL_WIDGET_MUTE, idx,
"Capture Switch", sw);
if (err < 0)
return err;
return 0;
}
static int stac92xx_auto_create_multi_out_ctls(struct hda_codec *codec,
const struct auto_pin_cfg *cfg)
{
struct sigmatel_spec *spec = codec->spec;
hda_nid_t nid;
int err;
int idx;
err = create_multi_out_ctls(codec, cfg->line_outs, cfg->line_out_pins,
spec->multiout.dac_nids,
cfg->line_out_type);
if (err < 0)
return err;
if (cfg->hp_outs > 1 && cfg->line_out_type == AUTO_PIN_LINE_OUT) {
err = stac92xx_add_control(spec,
STAC_CTL_WIDGET_HP_SWITCH,
"Headphone as Line Out Switch",
cfg->hp_pins[cfg->hp_outs - 1]);
if (err < 0)
return err;
}
for (idx = 0; idx < cfg->num_inputs; idx++) {
if (cfg->inputs[idx].type > AUTO_PIN_LINE_IN)
break;
nid = cfg->inputs[idx].pin;
err = stac92xx_add_jack_mode_control(codec, nid, idx);
if (err < 0)
return err;
}
return 0;
}
static int stac92xx_auto_create_hp_ctls(struct hda_codec *codec,
struct auto_pin_cfg *cfg)
{
struct sigmatel_spec *spec = codec->spec;
int err;
err = create_multi_out_ctls(codec, cfg->hp_outs, cfg->hp_pins,
spec->hp_dacs, AUTO_PIN_HP_OUT);
if (err < 0)
return err;
err = create_multi_out_ctls(codec, cfg->speaker_outs, cfg->speaker_pins,
spec->speaker_dacs, AUTO_PIN_SPEAKER_OUT);
if (err < 0)
return err;
return 0;
}
static int stac92xx_auto_create_mono_output_ctls(struct hda_codec *codec)
{
struct sigmatel_spec *spec = codec->spec;
struct hda_input_mux *mono_mux = &spec->private_mono_mux;
int i, num_cons;
hda_nid_t con_lst[ARRAY_SIZE(stac92xx_mono_labels)];
num_cons = snd_hda_get_connections(codec,
spec->mono_nid,
con_lst,
HDA_MAX_NUM_INPUTS);
if (num_cons <= 0 || num_cons > ARRAY_SIZE(stac92xx_mono_labels))
return -EINVAL;
for (i = 0; i < num_cons; i++)
snd_hda_add_imux_item(mono_mux, stac92xx_mono_labels[i], i,
NULL);
return stac92xx_add_control(spec, STAC_CTL_WIDGET_MONO_MUX,
"Mono Mux", spec->mono_nid);
}
static int stac92xx_auto_create_beep_ctls(struct hda_codec *codec,
hda_nid_t nid)
{
struct sigmatel_spec *spec = codec->spec;
u32 caps = query_amp_caps(codec, nid, HDA_OUTPUT);
int err, type = STAC_CTL_WIDGET_MUTE_BEEP;
if (spec->anabeep_nid == nid)
type = STAC_CTL_WIDGET_MUTE;
if ((caps & AC_AMPCAP_MUTE) >> AC_AMPCAP_MUTE_SHIFT) {
err = stac92xx_add_control(spec, type,
"Beep Playback Switch",
HDA_COMPOSE_AMP_VAL(nid, 1, 0, HDA_OUTPUT));
if (err < 0)
return err;
}
if ((caps & AC_AMPCAP_NUM_STEPS) >> AC_AMPCAP_NUM_STEPS_SHIFT) {
err = stac92xx_add_control(spec, STAC_CTL_WIDGET_VOL,
"Beep Playback Volume",
HDA_COMPOSE_AMP_VAL(nid, 1, 0, HDA_OUTPUT));
if (err < 0)
return err;
}
return 0;
}
static int stac92xx_dig_beep_switch_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
ucontrol->value.integer.value[0] = codec->beep->enabled;
return 0;
}
static int stac92xx_dig_beep_switch_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
return snd_hda_enable_beep_device(codec, ucontrol->value.integer.value[0]);
}
static int stac92xx_beep_switch_ctl(struct hda_codec *codec)
{
return stac92xx_add_control_temp(codec->spec, &stac92xx_dig_beep_ctrl,
0, "Beep Playback Switch", 0);
}
static int stac92xx_auto_create_mux_input_ctls(struct hda_codec *codec)
{
struct sigmatel_spec *spec = codec->spec;
int i, j, err = 0;
for (i = 0; i < spec->num_muxes; i++) {
hda_nid_t nid;
unsigned int wcaps;
unsigned long val;
nid = spec->mux_nids[i];
wcaps = get_wcaps(codec, nid);
if (!(wcaps & AC_WCAP_OUT_AMP))
continue;
val = HDA_COMPOSE_AMP_VAL(nid, 3, 0, HDA_OUTPUT);
for (j = 0; j < spec->num_caps; j++) {
if (spec->capvols[j] == val)
break;
}
if (j < spec->num_caps)
continue;
err = stac92xx_add_control_idx(spec, STAC_CTL_WIDGET_VOL, i,
"Mux Capture Volume", val);
if (err < 0)
return err;
}
return 0;
}
static int stac92xx_auto_create_spdif_mux_ctls(struct hda_codec *codec)
{
struct sigmatel_spec *spec = codec->spec;
struct hda_input_mux *spdif_mux = &spec->private_smux;
const char * const *labels = spec->spdif_labels;
int i, num_cons;
hda_nid_t con_lst[HDA_MAX_NUM_INPUTS];
num_cons = snd_hda_get_connections(codec,
spec->smux_nids[0],
con_lst,
HDA_MAX_NUM_INPUTS);
if (num_cons <= 0)
return -EINVAL;
if (!labels)
labels = stac92xx_spdif_labels;
for (i = 0; i < num_cons; i++)
snd_hda_add_imux_item(spdif_mux, labels[i], i, NULL);
return 0;
}
static hda_nid_t get_connected_node(struct hda_codec *codec, hda_nid_t mux,
int idx)
{
hda_nid_t conn[HDA_MAX_NUM_INPUTS];
int nums;
nums = snd_hda_get_connections(codec, mux, conn, ARRAY_SIZE(conn));
if (idx >= 0 && idx < nums)
return conn[idx];
return 0;
}
static int create_elem_capture_vol(struct hda_codec *codec, hda_nid_t nid,
const char *label, int idx, int direction)
{
unsigned int caps, nums;
char name[32];
int err;
if (direction == HDA_OUTPUT)
caps = AC_WCAP_OUT_AMP;
else
caps = AC_WCAP_IN_AMP;
if (!(get_wcaps(codec, nid) & caps))
return 0;
caps = query_amp_caps(codec, nid, direction);
nums = (caps & AC_AMPCAP_NUM_STEPS) >> AC_AMPCAP_NUM_STEPS_SHIFT;
if (!nums)
return 0;
snprintf(name, sizeof(name), "%s Capture Volume", label);
err = stac92xx_add_control_idx(codec->spec, STAC_CTL_WIDGET_VOL, idx, name,
HDA_COMPOSE_AMP_VAL(nid, 3, 0, direction));
if (err < 0)
return err;
return 1;
}
static int stac92xx_auto_create_dmic_input_ctls(struct hda_codec *codec,
const struct auto_pin_cfg *cfg)
{
struct sigmatel_spec *spec = codec->spec;
struct hda_input_mux *imux = &spec->private_imux;
struct hda_input_mux *dimux = &spec->private_dimux;
int err, i;
unsigned int def_conf;
snd_hda_add_imux_item(dimux, stac92xx_dmic_labels[0], 0, NULL);
for (i = 0; i < spec->num_dmics; i++) {
hda_nid_t nid;
int index, type_idx;
const char *label;
nid = spec->dmic_nids[i];
if (get_wcaps_type(get_wcaps(codec, nid)) != AC_WID_PIN)
continue;
def_conf = snd_hda_codec_get_pincfg(codec, nid);
if (get_defcfg_connect(def_conf) == AC_JACK_PORT_NONE)
continue;
index = get_connection_index(codec, spec->dmux_nids[0], nid);
if (index < 0)
continue;
label = hda_get_input_pin_label(codec, nid, 1);
snd_hda_add_imux_item(dimux, label, index, &type_idx);
if (snd_hda_get_bool_hint(codec, "separate_dmux") != 1)
snd_hda_add_imux_item(imux, label, index, &type_idx);
err = create_elem_capture_vol(codec, nid, label, type_idx,
HDA_INPUT);
if (err < 0)
return err;
if (!err) {
err = create_elem_capture_vol(codec, nid, label,
type_idx, HDA_OUTPUT);
if (err < 0)
return err;
if (!err) {
nid = get_connected_node(codec,
spec->dmux_nids[0], index);
if (nid)
err = create_elem_capture_vol(codec,
nid, label,
type_idx, HDA_INPUT);
if (err < 0)
return err;
}
}
}
return 0;
}
static int check_mic_pin(struct hda_codec *codec, hda_nid_t nid,
hda_nid_t *fixed, hda_nid_t *ext, hda_nid_t *dock)
{
unsigned int cfg;
unsigned int type;
if (!nid)
return 0;
cfg = snd_hda_codec_get_pincfg(codec, nid);
type = get_defcfg_device(cfg);
switch (snd_hda_get_input_pin_attr(cfg)) {
case INPUT_PIN_ATTR_INT:
if (*fixed)
return 1;
if (type != AC_JACK_MIC_IN)
return 1;
*fixed = nid;
break;
case INPUT_PIN_ATTR_UNUSED:
break;
case INPUT_PIN_ATTR_DOCK:
if (*dock)
return 1;
if (type != AC_JACK_MIC_IN && type != AC_JACK_LINE_IN)
return 1;
*dock = nid;
break;
default:
if (*ext)
return 1;
if (type != AC_JACK_MIC_IN)
return 1;
*ext = nid;
break;
}
return 0;
}
static int set_mic_route(struct hda_codec *codec,
struct sigmatel_mic_route *mic,
hda_nid_t pin)
{
struct sigmatel_spec *spec = codec->spec;
struct auto_pin_cfg *cfg = &spec->autocfg;
int i;
mic->pin = pin;
if (pin == 0)
return 0;
for (i = 0; i < cfg->num_inputs; i++) {
if (pin == cfg->inputs[i].pin)
break;
}
if (i < cfg->num_inputs && cfg->inputs[i].type == AUTO_PIN_MIC) {
i = get_connection_index(codec, spec->mux_nids[0], pin);
if (i < 0)
return -1;
mic->mux_idx = i;
mic->dmux_idx = -1;
if (spec->dmux_nids)
mic->dmux_idx = get_connection_index(codec,
spec->dmux_nids[0],
spec->mux_nids[0]);
} else if (spec->dmux_nids) {
i = get_connection_index(codec, spec->dmux_nids[0], pin);
if (i < 0)
return -1;
mic->dmux_idx = i;
mic->mux_idx = -1;
if (spec->mux_nids)
mic->mux_idx = get_connection_index(codec,
spec->mux_nids[0],
spec->dmux_nids[0]);
}
return 0;
}
static int stac_check_auto_mic(struct hda_codec *codec)
{
struct sigmatel_spec *spec = codec->spec;
struct auto_pin_cfg *cfg = &spec->autocfg;
hda_nid_t fixed, ext, dock;
int i;
fixed = ext = dock = 0;
for (i = 0; i < cfg->num_inputs; i++)
if (check_mic_pin(codec, cfg->inputs[i].pin,
&fixed, &ext, &dock))
return 0;
for (i = 0; i < spec->num_dmics; i++)
if (check_mic_pin(codec, spec->dmic_nids[i],
&fixed, &ext, &dock))
return 0;
if (!fixed || (!ext && !dock))
return 0;
if (!is_jack_detectable(codec, ext))
return 0;
if (set_mic_route(codec, &spec->ext_mic, ext) ||
set_mic_route(codec, &spec->int_mic, fixed) ||
set_mic_route(codec, &spec->dock_mic, dock))
return 0;
return 1;
}
static int stac92xx_auto_create_analog_input_ctls(struct hda_codec *codec, const struct auto_pin_cfg *cfg)
{
struct sigmatel_spec *spec = codec->spec;
struct hda_input_mux *imux = &spec->private_imux;
int i, j;
const char *label;
for (i = 0; i < cfg->num_inputs; i++) {
hda_nid_t nid = cfg->inputs[i].pin;
int index, err, type_idx;
index = -1;
for (j = 0; j < spec->num_muxes; j++) {
index = get_connection_index(codec, spec->mux_nids[j],
nid);
if (index >= 0)
break;
}
if (index < 0)
continue;
label = hda_get_autocfg_input_label(codec, cfg, i);
snd_hda_add_imux_item(imux, label, index, &type_idx);
err = create_elem_capture_vol(codec, nid,
label, type_idx,
HDA_INPUT);
if (err < 0)
return err;
}
spec->num_analog_muxes = imux->num_items;
if (imux->num_items) {
for (i = 0; i < spec->num_muxes; i++) {
snd_hda_codec_write_cache(codec, spec->mux_nids[i], 0,
AC_VERB_SET_CONNECT_SEL,
imux->items[0].index);
}
}
return 0;
}
static void stac92xx_auto_init_multi_out(struct hda_codec *codec)
{
struct sigmatel_spec *spec = codec->spec;
int i;
for (i = 0; i < spec->autocfg.line_outs; i++) {
hda_nid_t nid = spec->autocfg.line_out_pins[i];
stac92xx_auto_set_pinctl(codec, nid, AC_PINCTL_OUT_EN);
}
}
static void stac92xx_auto_init_hp_out(struct hda_codec *codec)
{
struct sigmatel_spec *spec = codec->spec;
int i;
for (i = 0; i < spec->autocfg.hp_outs; i++) {
hda_nid_t pin;
pin = spec->autocfg.hp_pins[i];
if (pin)
stac92xx_auto_set_pinctl(codec, pin, AC_PINCTL_OUT_EN | AC_PINCTL_HP_EN);
}
for (i = 0; i < spec->autocfg.speaker_outs; i++) {
hda_nid_t pin;
pin = spec->autocfg.speaker_pins[i];
if (pin)
stac92xx_auto_set_pinctl(codec, pin, AC_PINCTL_OUT_EN);
}
}
static int is_dual_headphones(struct hda_codec *codec)
{
struct sigmatel_spec *spec = codec->spec;
int i, valid_hps;
if (spec->autocfg.line_out_type != AUTO_PIN_SPEAKER_OUT ||
spec->autocfg.hp_outs <= 1)
return 0;
valid_hps = 0;
for (i = 0; i < spec->autocfg.hp_outs; i++) {
hda_nid_t nid = spec->autocfg.hp_pins[i];
unsigned int cfg = snd_hda_codec_get_pincfg(codec, nid);
if (get_defcfg_location(cfg) & AC_JACK_LOC_SEPARATE)
continue;
valid_hps++;
}
return (valid_hps > 1);
}
static int stac92xx_parse_auto_config(struct hda_codec *codec)
{
struct sigmatel_spec *spec = codec->spec;
hda_nid_t dig_out = 0, dig_in = 0;
int hp_swap = 0;
int i, err;
if ((err = snd_hda_parse_pin_def_config(codec,
&spec->autocfg,
spec->dmic_nids)) < 0)
return err;
if (! spec->autocfg.line_outs)
return 0;
if (is_dual_headphones(codec)) {
snd_printdd("stac92xx: Enabling multi-HPs workaround\n");
memcpy(spec->autocfg.speaker_pins, spec->autocfg.line_out_pins,
sizeof(spec->autocfg.line_out_pins));
spec->autocfg.speaker_outs = spec->autocfg.line_outs;
memcpy(spec->autocfg.line_out_pins, spec->autocfg.hp_pins,
sizeof(spec->autocfg.hp_pins));
spec->autocfg.line_outs = spec->autocfg.hp_outs;
spec->autocfg.line_out_type = AUTO_PIN_HP_OUT;
spec->autocfg.hp_outs = 0;
hp_swap = 1;
}
if (spec->autocfg.mono_out_pin) {
int dir = get_wcaps(codec, spec->autocfg.mono_out_pin) &
(AC_WCAP_OUT_AMP | AC_WCAP_IN_AMP);
u32 caps = query_amp_caps(codec,
spec->autocfg.mono_out_pin, dir);
hda_nid_t conn_list[1];
if (snd_hda_get_connections(codec,
spec->autocfg.mono_out_pin, conn_list, 1) &&
snd_hda_get_connections(codec, conn_list[0],
conn_list, 1) > 0) {
int wcaps = get_wcaps(codec, conn_list[0]);
int wid_type = get_wcaps_type(wcaps);
if (wid_type == AC_WID_AUD_SEL &&
!(wcaps & AC_WCAP_LR_SWAP))
spec->mono_nid = conn_list[0];
}
if (dir) {
hda_nid_t nid = spec->autocfg.mono_out_pin;
dir = (dir & AC_WCAP_OUT_AMP) ? HDA_OUTPUT : HDA_INPUT;
err = stac92xx_add_control(spec, STAC_CTL_WIDGET_MUTE,
"Mono Playback Switch",
HDA_COMPOSE_AMP_VAL(nid, 1, 0, dir));
if (err < 0)
return err;
if ((caps & AC_AMPCAP_NUM_STEPS)
>> AC_AMPCAP_NUM_STEPS_SHIFT) {
err = stac92xx_add_control(spec,
STAC_CTL_WIDGET_VOL,
"Mono Playback Volume",
HDA_COMPOSE_AMP_VAL(nid, 1, 0, dir));
if (err < 0)
return err;
}
}
stac92xx_auto_set_pinctl(codec, spec->autocfg.mono_out_pin,
AC_PINCTL_OUT_EN);
}
if (!spec->multiout.num_dacs) {
err = stac92xx_auto_fill_dac_nids(codec);
if (err < 0)
return err;
err = stac92xx_auto_create_multi_out_ctls(codec,
&spec->autocfg);
if (err < 0)
return err;
}
if (spec->anabeep_nid > 0) {
err = stac92xx_auto_create_beep_ctls(codec,
spec->anabeep_nid);
if (err < 0)
return err;
}
#ifdef CONFIG_SND_HDA_INPUT_BEEP
if (spec->digbeep_nid > 0) {
hda_nid_t nid = spec->digbeep_nid;
unsigned int caps;
err = stac92xx_auto_create_beep_ctls(codec, nid);
if (err < 0)
return err;
err = snd_hda_attach_beep_device(codec, nid);
if (err < 0)
return err;
if (codec->beep) {
codec->beep->linear_tone = spec->linear_tone_beep;
caps = query_amp_caps(codec, nid, HDA_OUTPUT);
if (!(caps & AC_AMPCAP_MUTE)) {
err = stac92xx_beep_switch_ctl(codec);
if (err < 0)
return err;
}
}
}
#endif
err = stac92xx_auto_create_hp_ctls(codec, &spec->autocfg);
if (err < 0)
return err;
if (hp_swap) {
memcpy(spec->autocfg.hp_pins, spec->autocfg.line_out_pins,
sizeof(spec->autocfg.hp_pins));
spec->autocfg.hp_outs = spec->autocfg.line_outs;
spec->autocfg.line_out_type = AUTO_PIN_HP_OUT;
spec->autocfg.line_outs = 0;
}
if (stac_check_auto_mic(codec)) {
spec->auto_mic = 1;
spec->num_adcs = 1;
spec->num_caps = 1;
spec->num_muxes = 1;
}
for (i = 0; i < spec->num_caps; i++) {
err = stac92xx_add_capvol_ctls(codec, spec->capvols[i],
spec->capsws[i], i);
if (err < 0)
return err;
}
err = stac92xx_auto_create_analog_input_ctls(codec, &spec->autocfg);
if (err < 0)
return err;
if (spec->mono_nid > 0) {
err = stac92xx_auto_create_mono_output_ctls(codec);
if (err < 0)
return err;
}
if (spec->num_dmics > 0 && !spec->dinput_mux)
if ((err = stac92xx_auto_create_dmic_input_ctls(codec,
&spec->autocfg)) < 0)
return err;
if (spec->num_muxes > 0) {
err = stac92xx_auto_create_mux_input_ctls(codec);
if (err < 0)
return err;
}
if (spec->num_smuxes > 0) {
err = stac92xx_auto_create_spdif_mux_ctls(codec);
if (err < 0)
return err;
}
err = stac92xx_add_input_source(spec);
if (err < 0)
return err;
spec->multiout.max_channels = spec->multiout.num_dacs * 2;
if (spec->multiout.max_channels > 2)
spec->surr_switch = 1;
for (i = codec->start_nid; i < codec->start_nid + codec->num_nodes; i++) {
unsigned int wid_caps = get_wcaps(codec, i);
if (wid_caps & AC_WCAP_DIGITAL) {
switch (get_wcaps_type(wid_caps)) {
case AC_WID_AUD_OUT:
if (!dig_out)
dig_out = i;
break;
case AC_WID_AUD_IN:
if (!dig_in)
dig_in = i;
break;
}
}
}
if (spec->autocfg.dig_outs)
spec->multiout.dig_out_nid = dig_out;
if (dig_in && spec->autocfg.dig_in_pin)
spec->dig_in_nid = dig_in;
if (spec->kctls.list)
spec->mixers[spec->num_mixers++] = spec->kctls.list;
spec->input_mux = &spec->private_imux;
if (!spec->dinput_mux)
spec->dinput_mux = &spec->private_dimux;
spec->sinput_mux = &spec->private_smux;
spec->mono_mux = &spec->private_mono_mux;
return 1;
}
static int stac9200_auto_create_hp_ctls(struct hda_codec *codec,
struct auto_pin_cfg *cfg)
{
struct sigmatel_spec *spec = codec->spec;
hda_nid_t pin = cfg->hp_pins[0];
if (! pin)
return 0;
if (is_jack_detectable(codec, pin))
spec->hp_detect = 1;
return 0;
}
static int stac9200_auto_create_lfe_ctls(struct hda_codec *codec,
struct auto_pin_cfg *cfg)
{
struct sigmatel_spec *spec = codec->spec;
int err;
hda_nid_t lfe_pin = 0x0;
int i;
for (i = 0; i < spec->autocfg.speaker_outs && lfe_pin == 0x0; i++) {
hda_nid_t pin = spec->autocfg.speaker_pins[i];
unsigned int wcaps = get_wcaps(codec, pin);
wcaps &= (AC_WCAP_STEREO | AC_WCAP_OUT_AMP);
if (wcaps == AC_WCAP_OUT_AMP)
lfe_pin = pin;
}
if (lfe_pin == 0 && spec->autocfg.speaker_outs == 0) {
for (i = 0; i < spec->autocfg.line_outs && lfe_pin == 0x0; i++) {
hda_nid_t pin = spec->autocfg.line_out_pins[i];
unsigned int defcfg;
defcfg = snd_hda_codec_get_pincfg(codec, pin);
if (get_defcfg_device(defcfg) == AC_JACK_SPEAKER) {
unsigned int wcaps = get_wcaps(codec, pin);
wcaps &= (AC_WCAP_STEREO | AC_WCAP_OUT_AMP);
if (wcaps == AC_WCAP_OUT_AMP)
lfe_pin = pin;
}
}
}
if (lfe_pin) {
err = create_controls(codec, "LFE", lfe_pin, 1);
if (err < 0)
return err;
}
return 0;
}
static int stac9200_parse_auto_config(struct hda_codec *codec)
{
struct sigmatel_spec *spec = codec->spec;
int err;
if ((err = snd_hda_parse_pin_def_config(codec, &spec->autocfg, NULL)) < 0)
return err;
if ((err = stac92xx_auto_create_analog_input_ctls(codec, &spec->autocfg)) < 0)
return err;
if ((err = stac9200_auto_create_hp_ctls(codec, &spec->autocfg)) < 0)
return err;
if ((err = stac9200_auto_create_lfe_ctls(codec, &spec->autocfg)) < 0)
return err;
if (spec->num_muxes > 0) {
err = stac92xx_auto_create_mux_input_ctls(codec);
if (err < 0)
return err;
}
err = stac92xx_add_input_source(spec);
if (err < 0)
return err;
if (spec->autocfg.dig_outs)
spec->multiout.dig_out_nid = 0x05;
if (spec->autocfg.dig_in_pin)
spec->dig_in_nid = 0x04;
if (spec->kctls.list)
spec->mixers[spec->num_mixers++] = spec->kctls.list;
spec->input_mux = &spec->private_imux;
spec->dinput_mux = &spec->private_dimux;
return 1;
}
static void stac_gpio_set(struct hda_codec *codec, unsigned int mask,
unsigned int dir_mask, unsigned int data)
{
unsigned int gpiostate, gpiomask, gpiodir;
snd_printdd("%s msk %x dir %x gpio %x\n", __func__, mask, dir_mask, data);
gpiostate = snd_hda_codec_read(codec, codec->afg, 0,
AC_VERB_GET_GPIO_DATA, 0);
gpiostate = (gpiostate & ~dir_mask) | (data & dir_mask);
gpiomask = snd_hda_codec_read(codec, codec->afg, 0,
AC_VERB_GET_GPIO_MASK, 0);
gpiomask |= mask;
gpiodir = snd_hda_codec_read(codec, codec->afg, 0,
AC_VERB_GET_GPIO_DIRECTION, 0);
gpiodir |= dir_mask;
snd_hda_codec_write(codec, codec->afg, 0, 0x7e7, 0);
snd_hda_codec_write(codec, codec->afg, 0,
AC_VERB_SET_GPIO_MASK, gpiomask);
snd_hda_codec_read(codec, codec->afg, 0,
AC_VERB_SET_GPIO_DIRECTION, gpiodir);
msleep(1);
snd_hda_codec_read(codec, codec->afg, 0,
AC_VERB_SET_GPIO_DATA, gpiostate);
}
static int stac92xx_add_jack(struct hda_codec *codec,
hda_nid_t nid, int type)
{
#ifdef CONFIG_SND_HDA_INPUT_JACK
int def_conf = snd_hda_codec_get_pincfg(codec, nid);
int connectivity = get_defcfg_connect(def_conf);
if (connectivity && connectivity != AC_JACK_PORT_FIXED)
return 0;
return snd_hda_input_jack_add(codec, nid, type, NULL);
#else
return 0;
#endif
}
static int stac_add_event(struct sigmatel_spec *spec, hda_nid_t nid,
unsigned char type, int data)
{
struct sigmatel_event *event;
snd_array_init(&spec->events, sizeof(*event), 32);
event = snd_array_new(&spec->events);
if (!event)
return -ENOMEM;
event->nid = nid;
event->type = type;
event->tag = spec->events.used;
event->data = data;
return event->tag;
}
static struct sigmatel_event *stac_get_event(struct hda_codec *codec,
hda_nid_t nid)
{
struct sigmatel_spec *spec = codec->spec;
struct sigmatel_event *event = spec->events.list;
int i;
for (i = 0; i < spec->events.used; i++, event++) {
if (event->nid == nid)
return event;
}
return NULL;
}
static struct sigmatel_event *stac_get_event_from_tag(struct hda_codec *codec,
unsigned char tag)
{
struct sigmatel_spec *spec = codec->spec;
struct sigmatel_event *event = spec->events.list;
int i;
for (i = 0; i < spec->events.used; i++, event++) {
if (event->tag == tag)
return event;
}
return NULL;
}
static int enable_pin_detect(struct hda_codec *codec, hda_nid_t nid,
unsigned int type)
{
struct sigmatel_event *event;
int tag;
if (!is_jack_detectable(codec, nid))
return 0;
event = stac_get_event(codec, nid);
if (event) {
if (event->type != type)
return 0;
tag = event->tag;
} else {
tag = stac_add_event(codec->spec, nid, type, 0);
if (tag < 0)
return 0;
}
snd_hda_codec_write_cache(codec, nid, 0,
AC_VERB_SET_UNSOLICITED_ENABLE,
AC_USRSP_EN | tag);
return 1;
}
static int is_nid_hp_pin(struct auto_pin_cfg *cfg, hda_nid_t nid)
{
int i;
for (i = 0; i < cfg->hp_outs; i++)
if (cfg->hp_pins[i] == nid)
return 1;
return 0;
}
static void stac92xx_power_down(struct hda_codec *codec)
{
struct sigmatel_spec *spec = codec->spec;
const hda_nid_t *dac;
for (dac = spec->dac_list; *dac; dac++)
if (!check_all_dac_nids(spec, *dac))
snd_hda_codec_write(codec, *dac, 0,
AC_VERB_SET_POWER_STATE, AC_PWRST_D3);
}
static inline int get_int_hint(struct hda_codec *codec, const char *key,
int *valp)
{
const char *p;
p = snd_hda_get_hint(codec, key);
if (p) {
unsigned long val;
if (!strict_strtoul(p, 0, &val)) {
*valp = val;
return 1;
}
}
return 0;
}
static void stac_store_hints(struct hda_codec *codec)
{
struct sigmatel_spec *spec = codec->spec;
int val;
val = snd_hda_get_bool_hint(codec, "hp_detect");
if (val >= 0)
spec->hp_detect = val;
if (get_int_hint(codec, "gpio_mask", &spec->gpio_mask)) {
spec->eapd_mask = spec->gpio_dir = spec->gpio_data =
spec->gpio_mask;
}
if (get_int_hint(codec, "gpio_dir", &spec->gpio_dir))
spec->gpio_mask &= spec->gpio_mask;
if (get_int_hint(codec, "gpio_data", &spec->gpio_data))
spec->gpio_dir &= spec->gpio_mask;
if (get_int_hint(codec, "eapd_mask", &spec->eapd_mask))
spec->eapd_mask &= spec->gpio_mask;
if (get_int_hint(codec, "gpio_mute", &spec->gpio_mute))
spec->gpio_mute &= spec->gpio_mask;
val = snd_hda_get_bool_hint(codec, "eapd_switch");
if (val >= 0)
spec->eapd_switch = val;
get_int_hint(codec, "gpio_led_polarity", &spec->gpio_led_polarity);
if (get_int_hint(codec, "gpio_led", &spec->gpio_led)) {
spec->gpio_mask |= spec->gpio_led;
spec->gpio_dir |= spec->gpio_led;
if (spec->gpio_led_polarity)
spec->gpio_data |= spec->gpio_led;
}
}
static int stac92xx_init(struct hda_codec *codec)
{
struct sigmatel_spec *spec = codec->spec;
struct auto_pin_cfg *cfg = &spec->autocfg;
unsigned int gpio;
int i;
snd_hda_sequence_write(codec, spec->init);
if (spec->powerdown_adcs)
for (i = 0; i < spec->num_adcs; i++)
snd_hda_codec_write(codec,
spec->adc_nids[i], 0,
AC_VERB_SET_POWER_STATE, AC_PWRST_D3);
stac_store_hints(codec);
gpio = spec->gpio_data;
if (!spec->eapd_switch)
gpio |= spec->eapd_mask;
stac_gpio_set(codec, spec->gpio_mask, spec->gpio_dir, gpio);
if (spec->hp_detect) {
for (i = 0; i < cfg->hp_outs; i++) {
hda_nid_t nid = cfg->hp_pins[i];
enable_pin_detect(codec, nid, STAC_HP_EVENT);
}
if (cfg->line_out_type == AUTO_PIN_LINE_OUT &&
cfg->speaker_outs > 0) {
for (i = 0; i < cfg->line_outs; i++) {
hda_nid_t nid = cfg->line_out_pins[i];
enable_pin_detect(codec, nid, STAC_LO_EVENT);
}
}
stac92xx_auto_set_pinctl(codec, spec->autocfg.line_out_pins[0],
AC_PINCTL_OUT_EN);
if (cfg->hp_pins[0])
stac_issue_unsol_event(codec, cfg->hp_pins[0]);
else if (cfg->line_out_pins[0])
stac_issue_unsol_event(codec, cfg->line_out_pins[0]);
} else {
stac92xx_auto_init_multi_out(codec);
stac92xx_auto_init_hp_out(codec);
for (i = 0; i < cfg->hp_outs; i++)
stac_toggle_power_map(codec, cfg->hp_pins[i], 1);
}
if (spec->auto_mic) {
if (spec->dmux_nids)
snd_hda_codec_write_cache(codec, spec->dmux_nids[0], 0,
AC_VERB_SET_CONNECT_SEL, 0);
if (enable_pin_detect(codec, spec->ext_mic.pin, STAC_MIC_EVENT))
stac_issue_unsol_event(codec, spec->ext_mic.pin);
if (enable_pin_detect(codec, spec->dock_mic.pin,
STAC_MIC_EVENT))
stac_issue_unsol_event(codec, spec->dock_mic.pin);
}
for (i = 0; i < cfg->num_inputs; i++) {
hda_nid_t nid = cfg->inputs[i].pin;
int type = cfg->inputs[i].type;
unsigned int pinctl, conf;
if (type == AUTO_PIN_MIC) {
pinctl = stac92xx_get_default_vref(codec, nid);
pinctl |= AC_PINCTL_IN_EN;
stac92xx_auto_set_pinctl(codec, nid, pinctl);
} else {
pinctl = snd_hda_codec_read(codec, nid, 0,
AC_VERB_GET_PIN_WIDGET_CONTROL, 0);
if (!(pinctl & AC_PINCTL_IN_EN) ||
(pinctl & AC_PINCTL_OUT_EN)) {
pinctl &= ~AC_PINCTL_OUT_EN;
pinctl |= AC_PINCTL_IN_EN;
stac92xx_auto_set_pinctl(codec, nid, pinctl);
}
}
conf = snd_hda_codec_get_pincfg(codec, nid);
if (get_defcfg_connect(conf) != AC_JACK_PORT_FIXED) {
if (enable_pin_detect(codec, nid, STAC_INSERT_EVENT))
stac_issue_unsol_event(codec, nid);
}
}
for (i = 0; i < spec->num_dmics; i++)
stac92xx_auto_set_pinctl(codec, spec->dmic_nids[i],
AC_PINCTL_IN_EN);
if (cfg->dig_out_pins[0])
stac92xx_auto_set_pinctl(codec, cfg->dig_out_pins[0],
AC_PINCTL_OUT_EN);
if (cfg->dig_in_pin)
stac92xx_auto_set_pinctl(codec, cfg->dig_in_pin,
AC_PINCTL_IN_EN);
for (i = 0; i < spec->num_pwrs; i++) {
hda_nid_t nid = spec->pwr_nids[i];
int pinctl, def_conf;
if (!spec->hp_detect ||
spec->vref_mute_led_nid == nid) {
stac_toggle_power_map(codec, nid, 1);
continue;
}
if (is_nid_hp_pin(cfg, nid))
continue;
pinctl = snd_hda_codec_read(codec, nid, 0,
AC_VERB_GET_PIN_WIDGET_CONTROL, 0);
if (pinctl & AC_PINCTL_IN_EN) {
stac_toggle_power_map(codec, nid, 1);
continue;
}
def_conf = snd_hda_codec_get_pincfg(codec, nid);
def_conf = get_defcfg_connect(def_conf);
if (def_conf != AC_JACK_PORT_COMPLEX) {
if (def_conf != AC_JACK_PORT_NONE)
stac_toggle_power_map(codec, nid, 1);
continue;
}
if (enable_pin_detect(codec, nid, STAC_PWR_EVENT)) {
stac_issue_unsol_event(codec, nid);
continue;
}
stac_toggle_power_map(codec, nid, 0);
}
if (spec->gpio_led)
hda_call_check_power_status(codec, 0x01);
if (spec->dac_list)
stac92xx_power_down(codec);
return 0;
}
static void stac92xx_free_kctls(struct hda_codec *codec)
{
struct sigmatel_spec *spec = codec->spec;
if (spec->kctls.list) {
struct snd_kcontrol_new *kctl = spec->kctls.list;
int i;
for (i = 0; i < spec->kctls.used; i++)
kfree(kctl[i].name);
}
snd_array_free(&spec->kctls);
}
static void stac92xx_shutup_pins(struct hda_codec *codec)
{
unsigned int i, def_conf;
if (codec->bus->shutdown)
return;
for (i = 0; i < codec->init_pins.used; i++) {
struct hda_pincfg *pin = snd_array_elem(&codec->init_pins, i);
def_conf = snd_hda_codec_get_pincfg(codec, pin->nid);
if (get_defcfg_connect(def_conf) != AC_JACK_PORT_NONE)
snd_hda_codec_write(codec, pin->nid, 0,
AC_VERB_SET_PIN_WIDGET_CONTROL, 0);
}
}
static void stac92xx_shutup(struct hda_codec *codec)
{
struct sigmatel_spec *spec = codec->spec;
stac92xx_shutup_pins(codec);
if (spec->eapd_mask)
stac_gpio_set(codec, spec->gpio_mask,
spec->gpio_dir, spec->gpio_data &
~spec->eapd_mask);
}
static void stac92xx_free(struct hda_codec *codec)
{
struct sigmatel_spec *spec = codec->spec;
if (! spec)
return;
stac92xx_shutup(codec);
snd_hda_input_jack_free(codec);
snd_array_free(&spec->events);
kfree(spec);
snd_hda_detach_beep_device(codec);
}
static void stac92xx_set_pinctl(struct hda_codec *codec, hda_nid_t nid,
unsigned int flag)
{
unsigned int old_ctl, pin_ctl;
pin_ctl = snd_hda_codec_read(codec, nid,
0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00);
if (pin_ctl & AC_PINCTL_IN_EN) {
struct sigmatel_spec *spec = codec->spec;
if (nid == spec->line_switch || nid == spec->mic_switch)
return;
}
old_ctl = pin_ctl;
if (flag & (AC_PINCTL_IN_EN | AC_PINCTL_OUT_EN))
pin_ctl &= ~(AC_PINCTL_IN_EN | AC_PINCTL_OUT_EN);
pin_ctl |= flag;
if (old_ctl != pin_ctl)
snd_hda_codec_write_cache(codec, nid, 0,
AC_VERB_SET_PIN_WIDGET_CONTROL,
pin_ctl);
}
static void stac92xx_reset_pinctl(struct hda_codec *codec, hda_nid_t nid,
unsigned int flag)
{
unsigned int pin_ctl = snd_hda_codec_read(codec, nid,
0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00);
if (pin_ctl & flag)
snd_hda_codec_write_cache(codec, nid, 0,
AC_VERB_SET_PIN_WIDGET_CONTROL,
pin_ctl & ~flag);
}
static inline int get_pin_presence(struct hda_codec *codec, hda_nid_t nid)
{
if (!nid)
return 0;
return snd_hda_jack_detect(codec, nid);
}
static void stac92xx_line_out_detect(struct hda_codec *codec,
int presence)
{
struct sigmatel_spec *spec = codec->spec;
struct auto_pin_cfg *cfg = &spec->autocfg;
int i;
for (i = 0; i < cfg->line_outs; i++) {
if (presence)
break;
presence = get_pin_presence(codec, cfg->line_out_pins[i]);
if (presence) {
unsigned int pinctl;
pinctl = snd_hda_codec_read(codec,
cfg->line_out_pins[i], 0,
AC_VERB_GET_PIN_WIDGET_CONTROL, 0);
if (pinctl & AC_PINCTL_IN_EN)
presence = 0;
}
}
if (presence) {
for (i = 0; i < cfg->speaker_outs; i++)
stac92xx_reset_pinctl(codec, cfg->speaker_pins[i],
AC_PINCTL_OUT_EN);
if (spec->eapd_mask && spec->eapd_switch)
stac_gpio_set(codec, spec->gpio_mask,
spec->gpio_dir, spec->gpio_data &
~spec->eapd_mask);
} else {
for (i = 0; i < cfg->speaker_outs; i++)
stac92xx_set_pinctl(codec, cfg->speaker_pins[i],
AC_PINCTL_OUT_EN);
if (spec->eapd_mask && spec->eapd_switch)
stac_gpio_set(codec, spec->gpio_mask,
spec->gpio_dir, spec->gpio_data |
spec->eapd_mask);
}
}
static int no_hp_sensing(struct sigmatel_spec *spec, int i)
{
struct auto_pin_cfg *cfg = &spec->autocfg;
if (cfg->hp_pins[i] == spec->line_switch)
return 1;
if (cfg->hp_pins[i] == spec->mic_switch)
return 1;
if (cfg->hp_pins[i] == spec->hp_switch)
return 1;
return 0;
}
static void stac92xx_hp_detect(struct hda_codec *codec)
{
struct sigmatel_spec *spec = codec->spec;
struct auto_pin_cfg *cfg = &spec->autocfg;
int i, presence;
presence = 0;
if (spec->gpio_mute)
presence = !(snd_hda_codec_read(codec, codec->afg, 0,
AC_VERB_GET_GPIO_DATA, 0) & spec->gpio_mute);
for (i = 0; i < cfg->hp_outs; i++) {
if (presence)
break;
if (no_hp_sensing(spec, i))
continue;
presence = get_pin_presence(codec, cfg->hp_pins[i]);
if (presence) {
unsigned int pinctl;
pinctl = snd_hda_codec_read(codec, cfg->hp_pins[i], 0,
AC_VERB_GET_PIN_WIDGET_CONTROL, 0);
if (pinctl & AC_PINCTL_IN_EN)
presence = 0;
}
}
if (presence) {
if (spec->hp_switch)
stac92xx_reset_pinctl(codec, spec->hp_switch,
AC_PINCTL_OUT_EN);
for (i = 0; i < cfg->line_outs; i++)
stac92xx_reset_pinctl(codec, cfg->line_out_pins[i],
AC_PINCTL_OUT_EN);
} else {
if (spec->hp_switch)
stac92xx_set_pinctl(codec, spec->hp_switch,
AC_PINCTL_OUT_EN);
for (i = 0; i < cfg->line_outs; i++)
stac92xx_set_pinctl(codec, cfg->line_out_pins[i],
AC_PINCTL_OUT_EN);
}
stac92xx_line_out_detect(codec, presence);
for (i = 0; i < cfg->hp_outs; i++) {
unsigned int val = AC_PINCTL_OUT_EN | AC_PINCTL_HP_EN;
if (no_hp_sensing(spec, i))
continue;
if (presence)
stac92xx_set_pinctl(codec, cfg->hp_pins[i], val);
#if 0
else
stac92xx_reset_pinctl(codec, cfg->hp_pins[i], val);
#endif
}
}
static void stac_toggle_power_map(struct hda_codec *codec, hda_nid_t nid,
int enable)
{
struct sigmatel_spec *spec = codec->spec;
unsigned int idx, val;
for (idx = 0; idx < spec->num_pwrs; idx++) {
if (spec->pwr_nids[idx] == nid)
break;
}
if (idx >= spec->num_pwrs)
return;
idx = 1 << idx;
val = snd_hda_codec_read(codec, codec->afg, 0, 0x0fec, 0x0) & 0xff;
if (enable)
val &= ~idx;
else
val |= idx;
snd_hda_codec_write(codec, codec->afg, 0, 0x7ec, val);
}
static void stac92xx_pin_sense(struct hda_codec *codec, hda_nid_t nid)
{
stac_toggle_power_map(codec, nid, get_pin_presence(codec, nid));
}
static unsigned int stac_get_defcfg_connect(struct hda_codec *codec, int idx)
{
struct sigmatel_spec *spec = codec->spec;
unsigned int cfg;
cfg = snd_hda_codec_get_pincfg(codec, spec->pin_nids[idx]);
return get_defcfg_connect(cfg);
}
static int stac92xx_connected_ports(struct hda_codec *codec,
const hda_nid_t *nids, int num_nids)
{
struct sigmatel_spec *spec = codec->spec;
int idx, num;
unsigned int def_conf;
for (num = 0; num < num_nids; num++) {
for (idx = 0; idx < spec->num_pins; idx++)
if (spec->pin_nids[idx] == nids[num])
break;
if (idx >= spec->num_pins)
break;
def_conf = stac_get_defcfg_connect(codec, idx);
if (def_conf == AC_JACK_PORT_NONE)
break;
}
return num;
}
static void stac92xx_mic_detect(struct hda_codec *codec)
{
struct sigmatel_spec *spec = codec->spec;
struct sigmatel_mic_route *mic;
if (get_pin_presence(codec, spec->ext_mic.pin))
mic = &spec->ext_mic;
else if (get_pin_presence(codec, spec->dock_mic.pin))
mic = &spec->dock_mic;
else
mic = &spec->int_mic;
if (mic->dmux_idx >= 0)
snd_hda_codec_write_cache(codec, spec->dmux_nids[0], 0,
AC_VERB_SET_CONNECT_SEL,
mic->dmux_idx);
if (mic->mux_idx >= 0)
snd_hda_codec_write_cache(codec, spec->mux_nids[0], 0,
AC_VERB_SET_CONNECT_SEL,
mic->mux_idx);
}
static void stac_issue_unsol_event(struct hda_codec *codec, hda_nid_t nid)
{
struct sigmatel_event *event = stac_get_event(codec, nid);
if (!event)
return;
codec->patch_ops.unsol_event(codec, (unsigned)event->tag << 26);
}
static void stac92xx_unsol_event(struct hda_codec *codec, unsigned int res)
{
struct sigmatel_spec *spec = codec->spec;
struct sigmatel_event *event;
int tag, data;
tag = (res >> 26) & 0x7f;
event = stac_get_event_from_tag(codec, tag);
if (!event)
return;
switch (event->type) {
case STAC_HP_EVENT:
case STAC_LO_EVENT:
stac92xx_hp_detect(codec);
break;
case STAC_MIC_EVENT:
stac92xx_mic_detect(codec);
break;
}
switch (event->type) {
case STAC_HP_EVENT:
case STAC_LO_EVENT:
case STAC_MIC_EVENT:
case STAC_INSERT_EVENT:
case STAC_PWR_EVENT:
if (spec->num_pwrs > 0)
stac92xx_pin_sense(codec, event->nid);
snd_hda_input_jack_report(codec, event->nid);
switch (codec->subsystem_id) {
case 0x103c308f:
if (event->nid == 0xb) {
int pin = AC_PINCTL_IN_EN;
if (get_pin_presence(codec, 0xa)
&& get_pin_presence(codec, 0xb))
pin |= AC_PINCTL_VREF_80;
if (!get_pin_presence(codec, 0xb))
pin |= AC_PINCTL_VREF_80;
stac92xx_auto_set_pinctl(codec, 0x0a, pin);
}
}
break;
case STAC_VREF_EVENT:
data = snd_hda_codec_read(codec, codec->afg, 0,
AC_VERB_GET_GPIO_DATA, 0);
snd_hda_codec_write(codec, codec->afg, 0, 0x7e0,
!!(data & (1 << event->data)));
break;
}
}
static void set_hp_led_gpio(struct hda_codec *codec)
{
struct sigmatel_spec *spec = codec->spec;
unsigned int gpio;
if (spec->gpio_led)
return;
gpio = snd_hda_param_read(codec, codec->afg, AC_PAR_GPIO_CAP);
gpio &= AC_GPIO_IO_COUNT;
if (gpio > 3)
spec->gpio_led = 0x08;
else
spec->gpio_led = 0x01;
}
static int find_mute_led_gpio(struct hda_codec *codec, int default_polarity)
{
struct sigmatel_spec *spec = codec->spec;
const struct dmi_device *dev = NULL;
if ((codec->subsystem_id >> 16) == PCI_VENDOR_ID_HP) {
while ((dev = dmi_find_device(DMI_DEV_TYPE_OEM_STRING,
NULL, dev))) {
if (sscanf(dev->name, "HP_Mute_LED_%d_%x",
&spec->gpio_led_polarity,
&spec->gpio_led) == 2) {
unsigned int max_gpio;
max_gpio = snd_hda_param_read(codec, codec->afg,
AC_PAR_GPIO_CAP);
max_gpio &= AC_GPIO_IO_COUNT;
if (spec->gpio_led < max_gpio)
spec->gpio_led = 1 << spec->gpio_led;
else
spec->vref_mute_led_nid = spec->gpio_led;
return 1;
}
if (sscanf(dev->name, "HP_Mute_LED_%d",
&spec->gpio_led_polarity) == 1) {
set_hp_led_gpio(codec);
return 1;
}
if (strstr(dev->name, "HP_Mute_LED_P_G")) {
set_hp_led_gpio(codec);
spec->gpio_led_polarity = 1;
return 1;
}
}
if (!hp_blike_system(codec->subsystem_id)) {
set_hp_led_gpio(codec);
spec->gpio_led_polarity = default_polarity;
return 1;
}
}
return 0;
}
static int hp_blike_system(u32 subsystem_id)
{
switch (subsystem_id) {
case 0x103c1520:
case 0x103c1521:
case 0x103c1523:
case 0x103c1524:
case 0x103c1525:
case 0x103c1722:
case 0x103c1723:
case 0x103c1724:
case 0x103c1725:
case 0x103c1726:
case 0x103c1727:
case 0x103c1728:
case 0x103c1729:
case 0x103c172a:
case 0x103c172b:
case 0x103c307e:
case 0x103c307f:
case 0x103c3080:
case 0x103c3081:
case 0x103c7007:
case 0x103c7008:
return 1;
}
return 0;
}
static void stac92hd_proc_hook(struct snd_info_buffer *buffer,
struct hda_codec *codec, hda_nid_t nid)
{
if (nid == codec->afg)
snd_iprintf(buffer, "Power-Map: 0x%02x\n",
snd_hda_codec_read(codec, nid, 0, 0x0fec, 0x0));
}
static void analog_loop_proc_hook(struct snd_info_buffer *buffer,
struct hda_codec *codec,
unsigned int verb)
{
snd_iprintf(buffer, "Analog Loopback: 0x%02x\n",
snd_hda_codec_read(codec, codec->afg, 0, verb, 0));
}
static void stac92hd7x_proc_hook(struct snd_info_buffer *buffer,
struct hda_codec *codec, hda_nid_t nid)
{
stac92hd_proc_hook(buffer, codec, nid);
if (nid == codec->afg)
analog_loop_proc_hook(buffer, codec, 0xfa0);
}
static void stac9205_proc_hook(struct snd_info_buffer *buffer,
struct hda_codec *codec, hda_nid_t nid)
{
if (nid == codec->afg)
analog_loop_proc_hook(buffer, codec, 0xfe0);
}
static void stac927x_proc_hook(struct snd_info_buffer *buffer,
struct hda_codec *codec, hda_nid_t nid)
{
if (nid == codec->afg)
analog_loop_proc_hook(buffer, codec, 0xfeb);
}
static int stac92xx_resume(struct hda_codec *codec)
{
struct sigmatel_spec *spec = codec->spec;
stac92xx_init(codec);
snd_hda_codec_resume_amp(codec);
snd_hda_codec_resume_cache(codec);
if (spec->hp_detect) {
if (spec->autocfg.hp_pins[0])
stac_issue_unsol_event(codec, spec->autocfg.hp_pins[0]);
else if (spec->autocfg.line_out_pins[0])
stac_issue_unsol_event(codec,
spec->autocfg.line_out_pins[0]);
}
return 0;
}
static int stac92xx_suspend(struct hda_codec *codec, pm_message_t state)
{
stac92xx_shutup(codec);
return 0;
}
static int stac92xx_pre_resume(struct hda_codec *codec)
{
struct sigmatel_spec *spec = codec->spec;
if (spec->vref_mute_led_nid)
stac_vrefout_set(codec, spec->vref_mute_led_nid,
spec->vref_led);
else if (spec->gpio_led)
stac_gpio_set(codec, spec->gpio_mask,
spec->gpio_dir, spec->gpio_data);
return 0;
}
static void stac92xx_set_power_state(struct hda_codec *codec, hda_nid_t fg,
unsigned int power_state)
{
unsigned int afg_power_state = power_state;
struct sigmatel_spec *spec = codec->spec;
if (power_state == AC_PWRST_D3) {
if (spec->vref_mute_led_nid) {
afg_power_state = AC_PWRST_D1;
}
msleep(100);
}
snd_hda_codec_read(codec, fg, 0, AC_VERB_SET_POWER_STATE,
afg_power_state);
snd_hda_codec_set_power_to_all(codec, fg, power_state, true);
}
static int stac92xx_update_led_status(struct hda_codec *codec)
{
struct sigmatel_spec *spec = codec->spec;
int i, num_ext_dacs, muted = 1;
unsigned int muted_lvl, notmtd_lvl;
hda_nid_t nid;
if (!spec->gpio_led)
return 0;
for (i = 0; i < spec->multiout.num_dacs; i++) {
nid = spec->multiout.dac_nids[i];
if (!(snd_hda_codec_amp_read(codec, nid, 0, HDA_OUTPUT, 0) &
HDA_AMP_MUTE)) {
muted = 0;
break;
}
}
if (muted && spec->multiout.hp_nid)
if (!(snd_hda_codec_amp_read(codec,
spec->multiout.hp_nid, 0, HDA_OUTPUT, 0) &
HDA_AMP_MUTE)) {
muted = 0;
}
num_ext_dacs = ARRAY_SIZE(spec->multiout.extra_out_nid);
for (i = 0; muted && i < num_ext_dacs; i++) {
nid = spec->multiout.extra_out_nid[i];
if (nid == 0)
break;
if (!(snd_hda_codec_amp_read(codec, nid, 0, HDA_OUTPUT, 0) &
HDA_AMP_MUTE)) {
muted = 0;
}
}
if (!spec->vref_mute_led_nid) {
if (muted)
spec->gpio_data &= ~spec->gpio_led;
else
spec->gpio_data |= spec->gpio_led;
if (!spec->gpio_led_polarity) {
spec->gpio_data ^= spec->gpio_led;
}
stac_gpio_set(codec, spec->gpio_mask,
spec->gpio_dir, spec->gpio_data);
} else {
notmtd_lvl = spec->gpio_led_polarity ?
AC_PINCTL_VREF_HIZ : AC_PINCTL_VREF_GRD;
muted_lvl = spec->gpio_led_polarity ?
AC_PINCTL_VREF_GRD : AC_PINCTL_VREF_HIZ;
spec->vref_led = muted ? muted_lvl : notmtd_lvl;
stac_vrefout_set(codec, spec->vref_mute_led_nid,
spec->vref_led);
}
return 0;
}
static int stac92xx_check_power_status(struct hda_codec *codec,
hda_nid_t nid)
{
stac92xx_update_led_status(codec);
return 0;
}
static int patch_stac9200(struct hda_codec *codec)
{
struct sigmatel_spec *spec;
int err;
spec = kzalloc(sizeof(*spec), GFP_KERNEL);
if (spec == NULL)
return -ENOMEM;
codec->no_trigger_sense = 1;
codec->spec = spec;
spec->linear_tone_beep = 1;
spec->num_pins = ARRAY_SIZE(stac9200_pin_nids);
spec->pin_nids = stac9200_pin_nids;
spec->board_config = snd_hda_check_board_config(codec, STAC_9200_MODELS,
stac9200_models,
stac9200_cfg_tbl);
if (spec->board_config < 0)
snd_printdd(KERN_INFO "hda_codec: %s: BIOS auto-probing.\n",
codec->chip_name);
else
stac92xx_set_config_regs(codec,
stac9200_brd_tbl[spec->board_config]);
spec->multiout.max_channels = 2;
spec->multiout.num_dacs = 1;
spec->multiout.dac_nids = stac9200_dac_nids;
spec->adc_nids = stac9200_adc_nids;
spec->mux_nids = stac9200_mux_nids;
spec->num_muxes = 1;
spec->num_dmics = 0;
spec->num_adcs = 1;
spec->num_pwrs = 0;
if (spec->board_config == STAC_9200_M4 ||
spec->board_config == STAC_9200_M4_2 ||
spec->board_config == STAC_9200_OQO)
spec->init = stac9200_eapd_init;
else
spec->init = stac9200_core_init;
spec->mixer = stac9200_mixer;
if (spec->board_config == STAC_9200_PANASONIC) {
spec->gpio_mask = spec->gpio_dir = 0x09;
spec->gpio_data = 0x00;
}
err = stac9200_parse_auto_config(codec);
if (err < 0) {
stac92xx_free(codec);
return err;
}
if (spec->board_config == STAC_9200_PANASONIC)
spec->hp_detect = 0;
codec->patch_ops = stac92xx_patch_ops;
return 0;
}
static int patch_stac925x(struct hda_codec *codec)
{
struct sigmatel_spec *spec;
int err;
spec = kzalloc(sizeof(*spec), GFP_KERNEL);
if (spec == NULL)
return -ENOMEM;
codec->no_trigger_sense = 1;
codec->spec = spec;
spec->linear_tone_beep = 1;
spec->num_pins = ARRAY_SIZE(stac925x_pin_nids);
spec->pin_nids = stac925x_pin_nids;
spec->board_config = snd_hda_check_board_codec_sid_config(codec,
STAC_925x_MODELS,
stac925x_models,
stac925x_codec_id_cfg_tbl);
if (spec->board_config < 0)
spec->board_config = snd_hda_check_board_config(codec,
STAC_925x_MODELS,
stac925x_models,
stac925x_cfg_tbl);
again:
if (spec->board_config < 0)
snd_printdd(KERN_INFO "hda_codec: %s: BIOS auto-probing.\n",
codec->chip_name);
else
stac92xx_set_config_regs(codec,
stac925x_brd_tbl[spec->board_config]);
spec->multiout.max_channels = 2;
spec->multiout.num_dacs = 1;
spec->multiout.dac_nids = stac925x_dac_nids;
spec->adc_nids = stac925x_adc_nids;
spec->mux_nids = stac925x_mux_nids;
spec->num_muxes = 1;
spec->num_adcs = 1;
spec->num_pwrs = 0;
switch (codec->vendor_id) {
case 0x83847632:
case 0x83847633:
case 0x83847636:
case 0x83847637:
spec->num_dmics = STAC925X_NUM_DMICS;
spec->dmic_nids = stac925x_dmic_nids;
spec->num_dmuxes = ARRAY_SIZE(stac925x_dmux_nids);
spec->dmux_nids = stac925x_dmux_nids;
break;
default:
spec->num_dmics = 0;
break;
}
spec->init = stac925x_core_init;
spec->mixer = stac925x_mixer;
spec->num_caps = 1;
spec->capvols = stac925x_capvols;
spec->capsws = stac925x_capsws;
err = stac92xx_parse_auto_config(codec);
if (!err) {
if (spec->board_config < 0) {
printk(KERN_WARNING "hda_codec: No auto-config is "
"available, default to model=ref\n");
spec->board_config = STAC_925x_REF;
goto again;
}
err = -EINVAL;
}
if (err < 0) {
stac92xx_free(codec);
return err;
}
codec->patch_ops = stac92xx_patch_ops;
return 0;
}
static int patch_stac92hd73xx(struct hda_codec *codec)
{
struct sigmatel_spec *spec;
hda_nid_t conn[STAC92HD73_DAC_COUNT + 2];
int err = 0;
int num_dacs;
spec = kzalloc(sizeof(*spec), GFP_KERNEL);
if (spec == NULL)
return -ENOMEM;
codec->no_trigger_sense = 1;
codec->spec = spec;
spec->linear_tone_beep = 0;
codec->slave_dig_outs = stac92hd73xx_slave_dig_outs;
spec->num_pins = ARRAY_SIZE(stac92hd73xx_pin_nids);
spec->pin_nids = stac92hd73xx_pin_nids;
spec->board_config = snd_hda_check_board_config(codec,
STAC_92HD73XX_MODELS,
stac92hd73xx_models,
stac92hd73xx_cfg_tbl);
if (spec->board_config < 0)
spec->board_config =
snd_hda_check_board_codec_sid_config(codec,
STAC_92HD73XX_MODELS, stac92hd73xx_models,
stac92hd73xx_codec_id_cfg_tbl);
again:
if (spec->board_config < 0)
snd_printdd(KERN_INFO "hda_codec: %s: BIOS auto-probing.\n",
codec->chip_name);
else
stac92xx_set_config_regs(codec,
stac92hd73xx_brd_tbl[spec->board_config]);
num_dacs = snd_hda_get_connections(codec, 0x0a,
conn, STAC92HD73_DAC_COUNT + 2) - 1;
if (num_dacs < 3 || num_dacs > 5) {
printk(KERN_WARNING "hda_codec: Could not determine "
"number of channels defaulting to DAC count\n");
num_dacs = STAC92HD73_DAC_COUNT;
}
spec->init = stac92hd73xx_core_init;
switch (num_dacs) {
case 0x3:
spec->aloopback_ctl = stac92hd73xx_6ch_loopback;
break;
case 0x4:
spec->aloopback_ctl = stac92hd73xx_8ch_loopback;
break;
case 0x5:
spec->aloopback_ctl = stac92hd73xx_10ch_loopback;
break;
}
spec->multiout.dac_nids = spec->dac_nids;
spec->aloopback_mask = 0x01;
spec->aloopback_shift = 8;
spec->digbeep_nid = 0x1c;
spec->mux_nids = stac92hd73xx_mux_nids;
spec->adc_nids = stac92hd73xx_adc_nids;
spec->dmic_nids = stac92hd73xx_dmic_nids;
spec->dmux_nids = stac92hd73xx_dmux_nids;
spec->smux_nids = stac92hd73xx_smux_nids;
spec->num_muxes = ARRAY_SIZE(stac92hd73xx_mux_nids);
spec->num_adcs = ARRAY_SIZE(stac92hd73xx_adc_nids);
spec->num_dmuxes = ARRAY_SIZE(stac92hd73xx_dmux_nids);
spec->num_caps = STAC92HD73XX_NUM_CAPS;
spec->capvols = stac92hd73xx_capvols;
spec->capsws = stac92hd73xx_capsws;
switch (spec->board_config) {
case STAC_DELL_EQ:
spec->init = dell_eq_core_init;
case STAC_DELL_M6_AMIC:
case STAC_DELL_M6_DMIC:
case STAC_DELL_M6_BOTH:
spec->num_smuxes = 0;
spec->eapd_switch = 0;
switch (spec->board_config) {
case STAC_DELL_M6_AMIC:
snd_hda_codec_set_pincfg(codec, 0x0b, 0x90A70170);
spec->num_dmics = 0;
break;
case STAC_DELL_M6_DMIC:
snd_hda_codec_set_pincfg(codec, 0x13, 0x90A60160);
spec->num_dmics = 1;
break;
case STAC_DELL_M6_BOTH:
snd_hda_codec_set_pincfg(codec, 0x0b, 0x90A70170);
snd_hda_codec_set_pincfg(codec, 0x13, 0x90A60160);
spec->num_dmics = 1;
break;
}
break;
case STAC_ALIENWARE_M17X:
spec->num_dmics = STAC92HD73XX_NUM_DMICS;
spec->num_smuxes = ARRAY_SIZE(stac92hd73xx_smux_nids);
spec->eapd_switch = 0;
break;
default:
spec->num_dmics = STAC92HD73XX_NUM_DMICS;
spec->num_smuxes = ARRAY_SIZE(stac92hd73xx_smux_nids);
spec->eapd_switch = 1;
break;
}
if (spec->board_config != STAC_92HD73XX_REF) {
spec->eapd_mask = spec->gpio_mask = spec->gpio_dir = 0x1;
spec->gpio_data = 0x01;
}
spec->num_pwrs = ARRAY_SIZE(stac92hd73xx_pwr_nids);
spec->pwr_nids = stac92hd73xx_pwr_nids;
err = stac92xx_parse_auto_config(codec);
if (!err) {
if (spec->board_config < 0) {
printk(KERN_WARNING "hda_codec: No auto-config is "
"available, default to model=ref\n");
spec->board_config = STAC_92HD73XX_REF;
goto again;
}
err = -EINVAL;
}
if (err < 0) {
stac92xx_free(codec);
return err;
}
if (spec->board_config == STAC_92HD73XX_NO_JD)
spec->hp_detect = 0;
codec->patch_ops = stac92xx_patch_ops;
codec->proc_widget_hook = stac92hd7x_proc_hook;
return 0;
}
static int hp_bnb2011_with_dock(struct hda_codec *codec)
{
if (codec->vendor_id != 0x111d7605 &&
codec->vendor_id != 0x111d76d1)
return 0;
switch (codec->subsystem_id) {
case 0x103c1618:
case 0x103c1619:
case 0x103c161a:
case 0x103c161b:
case 0x103c161c:
case 0x103c161d:
case 0x103c161e:
case 0x103c161f:
case 0x103c162a:
case 0x103c162b:
case 0x103c1630:
case 0x103c1631:
case 0x103c1633:
case 0x103c1634:
case 0x103c1635:
case 0x103c3587:
case 0x103c3588:
case 0x103c3589:
case 0x103c358a:
case 0x103c3667:
case 0x103c3668:
case 0x103c3669:
return 1;
}
return 0;
}
static void stac92hd8x_add_pin(struct hda_codec *codec, hda_nid_t nid)
{
struct sigmatel_spec *spec = codec->spec;
unsigned int def_conf = snd_hda_codec_get_pincfg(codec, nid);
int i;
spec->auto_pin_nids[spec->auto_pin_cnt] = nid;
spec->auto_pin_cnt++;
if (get_defcfg_device(def_conf) == AC_JACK_MIC_IN &&
get_defcfg_connect(def_conf) != AC_JACK_PORT_NONE) {
for (i = 0; i < ARRAY_SIZE(stac92hd83xxx_dmic_nids); i++) {
if (nid == stac92hd83xxx_dmic_nids[i]) {
spec->auto_dmic_nids[spec->auto_dmic_cnt] = nid;
spec->auto_dmic_cnt++;
}
}
}
}
static void stac92hd8x_add_adc(struct hda_codec *codec, hda_nid_t nid)
{
struct sigmatel_spec *spec = codec->spec;
spec->auto_adc_nids[spec->auto_adc_cnt] = nid;
spec->auto_adc_cnt++;
}
static void stac92hd8x_add_mux(struct hda_codec *codec, hda_nid_t nid)
{
int i, j;
struct sigmatel_spec *spec = codec->spec;
for (i = 0; i < spec->auto_adc_cnt; i++) {
if (get_connection_index(codec,
spec->auto_adc_nids[i], nid) >= 0) {
if (!spec->auto_mux_nids[i]) {
spec->auto_mux_nids[i] = nid;
spec->auto_capvols[i] = HDA_COMPOSE_AMP_VAL(nid,
3, 0, HDA_OUTPUT);
}
for (j = 0; j < spec->auto_dmic_cnt; j++) {
if (get_connection_index(codec, nid,
spec->auto_dmic_nids[j]) >= 0) {
if (!spec->auto_dmux_nids[i])
spec->auto_dmux_nids[i] = nid;
break;
}
}
break;
}
}
}
static void stac92hd8x_fill_auto_spec(struct hda_codec *codec)
{
hda_nid_t nid, end_nid;
unsigned int wid_caps, wid_type;
struct sigmatel_spec *spec = codec->spec;
end_nid = codec->start_nid + codec->num_nodes;
for (nid = codec->start_nid; nid < end_nid; nid++) {
wid_caps = get_wcaps(codec, nid);
wid_type = get_wcaps_type(wid_caps);
if (wid_type == AC_WID_PIN)
stac92hd8x_add_pin(codec, nid);
if (wid_type == AC_WID_AUD_IN && !(wid_caps & AC_WCAP_DIGITAL))
stac92hd8x_add_adc(codec, nid);
}
for (nid = codec->start_nid; nid < end_nid; nid++) {
wid_caps = get_wcaps(codec, nid);
wid_type = get_wcaps_type(wid_caps);
if (wid_type == AC_WID_AUD_SEL)
stac92hd8x_add_mux(codec, nid);
}
spec->pin_nids = spec->auto_pin_nids;
spec->num_pins = spec->auto_pin_cnt;
spec->adc_nids = spec->auto_adc_nids;
spec->num_adcs = spec->auto_adc_cnt;
spec->capvols = spec->auto_capvols;
spec->capsws = spec->auto_capvols;
spec->num_caps = spec->auto_adc_cnt;
spec->mux_nids = spec->auto_mux_nids;
spec->num_muxes = spec->auto_adc_cnt;
spec->dmux_nids = spec->auto_dmux_nids;
spec->num_dmuxes = spec->auto_adc_cnt;
spec->dmic_nids = spec->auto_dmic_nids;
spec->num_dmics = spec->auto_dmic_cnt;
}
static int patch_stac92hd83xxx(struct hda_codec *codec)
{
struct sigmatel_spec *spec;
int err;
spec = kzalloc(sizeof(*spec), GFP_KERNEL);
if (spec == NULL)
return -ENOMEM;
if (hp_bnb2011_with_dock(codec)) {
snd_hda_codec_set_pincfg(codec, 0xa, 0x2101201f);
snd_hda_codec_set_pincfg(codec, 0xf, 0x2181205e);
}
codec->no_trigger_sense = 1;
codec->spec = spec;
stac92hd8x_fill_auto_spec(codec);
spec->linear_tone_beep = 0;
codec->slave_dig_outs = stac92hd83xxx_slave_dig_outs;
spec->digbeep_nid = 0x21;
spec->pwr_nids = stac92hd83xxx_pwr_nids;
spec->num_pwrs = ARRAY_SIZE(stac92hd83xxx_pwr_nids);
spec->multiout.dac_nids = spec->dac_nids;
spec->init = stac92hd83xxx_core_init;
spec->board_config = snd_hda_check_board_config(codec,
STAC_92HD83XXX_MODELS,
stac92hd83xxx_models,
stac92hd83xxx_cfg_tbl);
again:
if (spec->board_config < 0)
snd_printdd(KERN_INFO "hda_codec: %s: BIOS auto-probing.\n",
codec->chip_name);
else
stac92xx_set_config_regs(codec,
stac92hd83xxx_brd_tbl[spec->board_config]);
codec->patch_ops = stac92xx_patch_ops;
if (find_mute_led_gpio(codec, 0))
snd_printd("mute LED gpio %d polarity %d\n",
spec->gpio_led,
spec->gpio_led_polarity);
#ifdef CONFIG_SND_HDA_POWER_SAVE
if (spec->gpio_led) {
if (!spec->vref_mute_led_nid) {
spec->gpio_mask |= spec->gpio_led;
spec->gpio_dir |= spec->gpio_led;
spec->gpio_data |= spec->gpio_led;
} else {
codec->patch_ops.set_power_state =
stac92xx_set_power_state;
}
codec->patch_ops.pre_resume = stac92xx_pre_resume;
codec->patch_ops.check_power_status =
stac92xx_check_power_status;
}
#endif
err = stac92xx_parse_auto_config(codec);
if (!err) {
if (spec->board_config < 0) {
printk(KERN_WARNING "hda_codec: No auto-config is "
"available, default to model=ref\n");
spec->board_config = STAC_92HD83XXX_REF;
goto again;
}
err = -EINVAL;
}
if (err < 0) {
stac92xx_free(codec);
return err;
}
codec->proc_widget_hook = stac92hd_proc_hook;
return 0;
}
static int stac92hd71bxx_connected_smuxes(struct hda_codec *codec,
hda_nid_t dig0pin)
{
struct sigmatel_spec *spec = codec->spec;
int idx;
for (idx = 0; idx < spec->num_pins; idx++)
if (spec->pin_nids[idx] == dig0pin)
break;
if ((idx + 2) >= spec->num_pins)
return 0;
if (stac_get_defcfg_connect(codec, idx + 1) != AC_JACK_PORT_NONE)
return 2;
if (stac_get_defcfg_connect(codec, idx + 2) != AC_JACK_PORT_NONE)
return 2;
if (stac_get_defcfg_connect(codec, idx) != AC_JACK_PORT_NONE)
return 1;
else
return 0;
}
static int stac_hp_bass_gpio_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct sigmatel_spec *spec = codec->spec;
ucontrol->value.integer.value[0] = !!(spec->gpio_data & 0x20);
return 0;
}
static int stac_hp_bass_gpio_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct sigmatel_spec *spec = codec->spec;
unsigned int gpio_data;
gpio_data = (spec->gpio_data & ~0x20) |
(ucontrol->value.integer.value[0] ? 0x20 : 0);
if (gpio_data == spec->gpio_data)
return 0;
spec->gpio_data = gpio_data;
stac_gpio_set(codec, spec->gpio_mask, spec->gpio_dir, spec->gpio_data);
return 1;
}
static int stac_add_hp_bass_switch(struct hda_codec *codec)
{
struct sigmatel_spec *spec = codec->spec;
if (!stac_control_new(spec, &stac_hp_bass_sw_ctrl,
"Bass Speaker Playback Switch", 0))
return -ENOMEM;
spec->gpio_mask |= 0x20;
spec->gpio_dir |= 0x20;
spec->gpio_data |= 0x20;
return 0;
}
static int patch_stac92hd71bxx(struct hda_codec *codec)
{
struct sigmatel_spec *spec;
const struct hda_verb *unmute_init = stac92hd71bxx_unmute_core_init;
unsigned int pin_cfg;
int err = 0;
spec = kzalloc(sizeof(*spec), GFP_KERNEL);
if (spec == NULL)
return -ENOMEM;
codec->no_trigger_sense = 1;
codec->spec = spec;
spec->linear_tone_beep = 0;
codec->patch_ops = stac92xx_patch_ops;
spec->num_pins = STAC92HD71BXX_NUM_PINS;
switch (codec->vendor_id) {
case 0x111d76b6:
case 0x111d76b7:
spec->pin_nids = stac92hd71bxx_pin_nids_4port;
break;
case 0x111d7603:
case 0x111d7608:
spec->num_pins--;
default:
spec->pin_nids = stac92hd71bxx_pin_nids_6port;
}
spec->num_pwrs = ARRAY_SIZE(stac92hd71bxx_pwr_nids);
spec->board_config = snd_hda_check_board_config(codec,
STAC_92HD71BXX_MODELS,
stac92hd71bxx_models,
stac92hd71bxx_cfg_tbl);
again:
if (spec->board_config < 0)
snd_printdd(KERN_INFO "hda_codec: %s: BIOS auto-probing.\n",
codec->chip_name);
else
stac92xx_set_config_regs(codec,
stac92hd71bxx_brd_tbl[spec->board_config]);
if (spec->board_config != STAC_92HD71BXX_REF) {
spec->gpio_mask = 0x01;
spec->gpio_dir = 0x01;
spec->gpio_data = 0x01;
}
spec->dmic_nids = stac92hd71bxx_dmic_nids;
spec->dmux_nids = stac92hd71bxx_dmux_nids;
spec->num_caps = STAC92HD71BXX_NUM_CAPS;
spec->capvols = stac92hd71bxx_capvols;
spec->capsws = stac92hd71bxx_capsws;
switch (codec->vendor_id) {
case 0x111d76b6:
case 0x111d76b7:
unmute_init++;
case 0x111d76b4:
case 0x111d76b5:
spec->init = stac92hd71bxx_core_init;
codec->slave_dig_outs = stac92hd71bxx_slave_dig_outs;
spec->num_dmics = stac92xx_connected_ports(codec,
stac92hd71bxx_dmic_nids,
STAC92HD71BXX_NUM_DMICS);
break;
case 0x111d7608:
switch (spec->board_config) {
case STAC_HP_M4:
err = stac_add_event(spec, codec->afg,
STAC_VREF_EVENT, 0x02);
if (err < 0)
return err;
snd_hda_codec_write_cache(codec, codec->afg, 0,
AC_VERB_SET_GPIO_UNSOLICITED_RSP_MASK, 0x02);
snd_hda_codec_write_cache(codec, codec->afg, 0,
AC_VERB_SET_UNSOLICITED_ENABLE,
AC_USRSP_EN | err);
spec->gpio_mask |= 0x02;
break;
}
if ((codec->revision_id & 0xf) == 0 ||
(codec->revision_id & 0xf) == 1)
spec->stream_delay = 40;
spec->init = stac92hd71bxx_core_init;
unmute_init++;
snd_hda_codec_set_pincfg(codec, 0x0f, 0x40f000f0);
snd_hda_codec_set_pincfg(codec, 0x19, 0x40f000f3);
spec->dmic_nids = stac92hd71bxx_dmic_5port_nids;
spec->num_dmics = stac92xx_connected_ports(codec,
stac92hd71bxx_dmic_5port_nids,
STAC92HD71BXX_NUM_DMICS - 1);
break;
case 0x111d7603:
if ((codec->revision_id & 0xf) == 1)
spec->stream_delay = 40;
default:
spec->init = stac92hd71bxx_core_init;
codec->slave_dig_outs = stac92hd71bxx_slave_dig_outs;
spec->num_dmics = stac92xx_connected_ports(codec,
stac92hd71bxx_dmic_nids,
STAC92HD71BXX_NUM_DMICS);
break;
}
if (get_wcaps(codec, 0xa) & AC_WCAP_IN_AMP)
snd_hda_sequence_write_cache(codec, unmute_init);
spec->aloopback_ctl = stac92hd71bxx_loopback;
spec->aloopback_mask = 0x50;
spec->aloopback_shift = 0;
spec->powerdown_adcs = 1;
spec->digbeep_nid = 0x26;
spec->mux_nids = stac92hd71bxx_mux_nids;
spec->adc_nids = stac92hd71bxx_adc_nids;
spec->smux_nids = stac92hd71bxx_smux_nids;
spec->pwr_nids = stac92hd71bxx_pwr_nids;
spec->num_muxes = ARRAY_SIZE(stac92hd71bxx_mux_nids);
spec->num_adcs = ARRAY_SIZE(stac92hd71bxx_adc_nids);
spec->num_dmuxes = ARRAY_SIZE(stac92hd71bxx_dmux_nids);
spec->num_smuxes = stac92hd71bxx_connected_smuxes(codec, 0x1e);
snd_printdd("Found board config: %d\n", spec->board_config);
switch (spec->board_config) {
case STAC_HP_M4:
snd_hda_codec_set_pincfg(codec, 0x0e, 0x01813040);
stac92xx_auto_set_pinctl(codec, 0x0e,
AC_PINCTL_IN_EN | AC_PINCTL_VREF_80);
case STAC_DELL_M4_2:
spec->num_dmics = 0;
spec->num_smuxes = 0;
spec->num_dmuxes = 0;
break;
case STAC_DELL_M4_1:
case STAC_DELL_M4_3:
spec->num_dmics = 1;
spec->num_smuxes = 0;
spec->num_dmuxes = 1;
break;
case STAC_HP_DV4_1222NR:
spec->num_dmics = 1;
spec->num_smuxes = 1;
spec->num_dmuxes = 1;
case STAC_HP_DV4:
spec->gpio_led = 0x01;
case STAC_HP_DV5:
snd_hda_codec_set_pincfg(codec, 0x0d, 0x90170010);
stac92xx_auto_set_pinctl(codec, 0x0d, AC_PINCTL_OUT_EN);
spec->hp_detect = 1;
break;
case STAC_HP_HDX:
spec->num_dmics = 1;
spec->num_dmuxes = 1;
spec->num_smuxes = 1;
spec->gpio_led = 0x08;
break;
}
if (hp_blike_system(codec->subsystem_id)) {
pin_cfg = snd_hda_codec_get_pincfg(codec, 0x0f);
if (get_defcfg_device(pin_cfg) == AC_JACK_LINE_OUT ||
get_defcfg_device(pin_cfg) == AC_JACK_SPEAKER ||
get_defcfg_device(pin_cfg) == AC_JACK_HP_OUT) {
pin_cfg = (pin_cfg & (~AC_DEFCFG_DEVICE))
| (AC_JACK_HP_OUT <<
AC_DEFCFG_DEVICE_SHIFT);
pin_cfg = (pin_cfg & (~(AC_DEFCFG_DEF_ASSOC
| AC_DEFCFG_SEQUENCE)))
| 0x1f;
snd_hda_codec_set_pincfg(codec, 0x0f, pin_cfg);
}
}
if (find_mute_led_gpio(codec, 1))
snd_printd("mute LED gpio %d polarity %d\n",
spec->gpio_led,
spec->gpio_led_polarity);
#ifdef CONFIG_SND_HDA_POWER_SAVE
if (spec->gpio_led) {
if (!spec->vref_mute_led_nid) {
spec->gpio_mask |= spec->gpio_led;
spec->gpio_dir |= spec->gpio_led;
spec->gpio_data |= spec->gpio_led;
} else {
codec->patch_ops.set_power_state =
stac92xx_set_power_state;
}
codec->patch_ops.pre_resume = stac92xx_pre_resume;
codec->patch_ops.check_power_status =
stac92xx_check_power_status;
}
#endif
spec->multiout.dac_nids = spec->dac_nids;
err = stac92xx_parse_auto_config(codec);
if (!err) {
if (spec->board_config < 0) {
printk(KERN_WARNING "hda_codec: No auto-config is "
"available, default to model=ref\n");
spec->board_config = STAC_92HD71BXX_REF;
goto again;
}
err = -EINVAL;
}
if (err < 0) {
stac92xx_free(codec);
return err;
}
if (spec->board_config == STAC_HP_DV4 ||
spec->board_config == STAC_HP_DV5) {
unsigned int cap;
cap = snd_hda_param_read(codec, 0x1, AC_PAR_GPIO_CAP);
cap &= AC_GPIO_IO_COUNT;
if (cap >= 6)
stac_add_hp_bass_switch(codec);
}
codec->proc_widget_hook = stac92hd7x_proc_hook;
return 0;
}
static int patch_stac922x(struct hda_codec *codec)
{
struct sigmatel_spec *spec;
int err;
spec = kzalloc(sizeof(*spec), GFP_KERNEL);
if (spec == NULL)
return -ENOMEM;
codec->no_trigger_sense = 1;
codec->spec = spec;
spec->linear_tone_beep = 1;
spec->num_pins = ARRAY_SIZE(stac922x_pin_nids);
spec->pin_nids = stac922x_pin_nids;
spec->board_config = snd_hda_check_board_config(codec, STAC_922X_MODELS,
stac922x_models,
stac922x_cfg_tbl);
if (spec->board_config == STAC_INTEL_MAC_AUTO) {
spec->gpio_mask = spec->gpio_dir = 0x03;
spec->gpio_data = 0x03;
printk(KERN_INFO "hda_codec: STAC922x, Apple subsys_id=%x\n", codec->subsystem_id);
switch (codec->subsystem_id) {
case 0x106b0800:
spec->board_config = STAC_INTEL_MAC_V1;
break;
case 0x106b0600:
case 0x106b0700:
spec->board_config = STAC_INTEL_MAC_V2;
break;
case 0x106b0e00:
case 0x106b0f00:
case 0x106b1600:
case 0x106b1700:
case 0x106b0200:
case 0x106b1e00:
spec->board_config = STAC_INTEL_MAC_V3;
break;
case 0x106b1a00:
case 0x00000100:
spec->board_config = STAC_INTEL_MAC_V4;
break;
case 0x106b0a00:
case 0x106b2200:
spec->board_config = STAC_INTEL_MAC_V5;
break;
default:
spec->board_config = STAC_INTEL_MAC_V3;
break;
}
}
again:
if (spec->board_config < 0)
snd_printdd(KERN_INFO "hda_codec: %s: BIOS auto-probing.\n",
codec->chip_name);
else
stac92xx_set_config_regs(codec,
stac922x_brd_tbl[spec->board_config]);
spec->adc_nids = stac922x_adc_nids;
spec->mux_nids = stac922x_mux_nids;
spec->num_muxes = ARRAY_SIZE(stac922x_mux_nids);
spec->num_adcs = ARRAY_SIZE(stac922x_adc_nids);
spec->num_dmics = 0;
spec->num_pwrs = 0;
spec->init = stac922x_core_init;
spec->num_caps = STAC922X_NUM_CAPS;
spec->capvols = stac922x_capvols;
spec->capsws = stac922x_capsws;
spec->multiout.dac_nids = spec->dac_nids;
err = stac92xx_parse_auto_config(codec);
if (!err) {
if (spec->board_config < 0) {
printk(KERN_WARNING "hda_codec: No auto-config is "
"available, default to model=ref\n");
spec->board_config = STAC_D945_REF;
goto again;
}
err = -EINVAL;
}
if (err < 0) {
stac92xx_free(codec);
return err;
}
codec->patch_ops = stac92xx_patch_ops;
snd_hda_override_amp_caps(codec, 0x12, HDA_OUTPUT,
(0 << AC_AMPCAP_OFFSET_SHIFT) |
(2 << AC_AMPCAP_NUM_STEPS_SHIFT) |
(0x27 << AC_AMPCAP_STEP_SIZE_SHIFT) |
(0 << AC_AMPCAP_MUTE_SHIFT));
return 0;
}
static int patch_stac927x(struct hda_codec *codec)
{
struct sigmatel_spec *spec;
int err;
spec = kzalloc(sizeof(*spec), GFP_KERNEL);
if (spec == NULL)
return -ENOMEM;
codec->no_trigger_sense = 1;
codec->spec = spec;
spec->linear_tone_beep = 1;
codec->slave_dig_outs = stac927x_slave_dig_outs;
spec->num_pins = ARRAY_SIZE(stac927x_pin_nids);
spec->pin_nids = stac927x_pin_nids;
spec->board_config = snd_hda_check_board_config(codec, STAC_927X_MODELS,
stac927x_models,
stac927x_cfg_tbl);
again:
if (spec->board_config < 0)
snd_printdd(KERN_INFO "hda_codec: %s: BIOS auto-probing.\n",
codec->chip_name);
else
stac92xx_set_config_regs(codec,
stac927x_brd_tbl[spec->board_config]);
spec->digbeep_nid = 0x23;
spec->adc_nids = stac927x_adc_nids;
spec->num_adcs = ARRAY_SIZE(stac927x_adc_nids);
spec->mux_nids = stac927x_mux_nids;
spec->num_muxes = ARRAY_SIZE(stac927x_mux_nids);
spec->smux_nids = stac927x_smux_nids;
spec->num_smuxes = ARRAY_SIZE(stac927x_smux_nids);
spec->spdif_labels = stac927x_spdif_labels;
spec->dac_list = stac927x_dac_nids;
spec->multiout.dac_nids = spec->dac_nids;
if (spec->board_config != STAC_D965_REF) {
spec->eapd_mask = spec->gpio_mask = 0x01;
spec->gpio_dir = spec->gpio_data = 0x01;
}
switch (spec->board_config) {
case STAC_D965_3ST:
case STAC_D965_5ST:
spec->num_dmics = 0;
spec->init = d965_core_init;
break;
case STAC_DELL_BIOS:
switch (codec->subsystem_id) {
case 0x10280209:
case 0x1028022e:
snd_hda_codec_set_pincfg(codec, 0x21, 0x01442070);
break;
}
snd_hda_codec_set_pincfg(codec, 0x0c, 0x90a79130);
snd_hda_codec_set_pincfg(codec, 0x0f, 0x0227011f);
snd_hda_codec_set_pincfg(codec, 0x0e, 0x02a79130);
case STAC_DELL_3ST:
if (codec->subsystem_id != 0x1028022f) {
spec->eapd_mask = spec->gpio_mask = 0x04;
spec->gpio_dir = spec->gpio_data = 0x04;
}
spec->dmic_nids = stac927x_dmic_nids;
spec->num_dmics = STAC927X_NUM_DMICS;
spec->init = dell_3st_core_init;
spec->dmux_nids = stac927x_dmux_nids;
spec->num_dmuxes = ARRAY_SIZE(stac927x_dmux_nids);
break;
case STAC_927X_VOLKNOB:
spec->num_dmics = 0;
spec->init = stac927x_volknob_core_init;
break;
default:
spec->num_dmics = 0;
spec->init = stac927x_core_init;
break;
}
spec->num_caps = STAC927X_NUM_CAPS;
spec->capvols = stac927x_capvols;
spec->capsws = stac927x_capsws;
spec->num_pwrs = 0;
spec->aloopback_ctl = stac927x_loopback;
spec->aloopback_mask = 0x40;
spec->aloopback_shift = 0;
spec->eapd_switch = 1;
err = stac92xx_parse_auto_config(codec);
if (!err) {
if (spec->board_config < 0) {
printk(KERN_WARNING "hda_codec: No auto-config is "
"available, default to model=ref\n");
spec->board_config = STAC_D965_REF;
goto again;
}
err = -EINVAL;
}
if (err < 0) {
stac92xx_free(codec);
return err;
}
codec->patch_ops = stac92xx_patch_ops;
codec->proc_widget_hook = stac927x_proc_hook;
codec->bus->needs_damn_long_delay = 1;
if (spec->board_config == STAC_D965_REF_NO_JD)
spec->hp_detect = 0;
return 0;
}
static int patch_stac9205(struct hda_codec *codec)
{
struct sigmatel_spec *spec;
int err;
spec = kzalloc(sizeof(*spec), GFP_KERNEL);
if (spec == NULL)
return -ENOMEM;
codec->no_trigger_sense = 1;
codec->spec = spec;
spec->linear_tone_beep = 1;
spec->num_pins = ARRAY_SIZE(stac9205_pin_nids);
spec->pin_nids = stac9205_pin_nids;
spec->board_config = snd_hda_check_board_config(codec, STAC_9205_MODELS,
stac9205_models,
stac9205_cfg_tbl);
again:
if (spec->board_config < 0)
snd_printdd(KERN_INFO "hda_codec: %s: BIOS auto-probing.\n",
codec->chip_name);
else
stac92xx_set_config_regs(codec,
stac9205_brd_tbl[spec->board_config]);
spec->digbeep_nid = 0x23;
spec->adc_nids = stac9205_adc_nids;
spec->num_adcs = ARRAY_SIZE(stac9205_adc_nids);
spec->mux_nids = stac9205_mux_nids;
spec->num_muxes = ARRAY_SIZE(stac9205_mux_nids);
spec->smux_nids = stac9205_smux_nids;
spec->num_smuxes = ARRAY_SIZE(stac9205_smux_nids);
spec->dmic_nids = stac9205_dmic_nids;
spec->num_dmics = STAC9205_NUM_DMICS;
spec->dmux_nids = stac9205_dmux_nids;
spec->num_dmuxes = ARRAY_SIZE(stac9205_dmux_nids);
spec->num_pwrs = 0;
spec->init = stac9205_core_init;
spec->aloopback_ctl = stac9205_loopback;
spec->num_caps = STAC9205_NUM_CAPS;
spec->capvols = stac9205_capvols;
spec->capsws = stac9205_capsws;
spec->aloopback_mask = 0x40;
spec->aloopback_shift = 0;
if (spec->board_config != STAC_9205_EAPD)
spec->eapd_switch = 1;
spec->multiout.dac_nids = spec->dac_nids;
switch (spec->board_config){
case STAC_9205_DELL_M43:
snd_hda_codec_set_pincfg(codec, 0x1f, 0x01441030);
snd_hda_codec_set_pincfg(codec, 0x20, 0x1c410030);
err = stac_add_event(spec, codec->afg, STAC_VREF_EVENT, 0x01);
if (err < 0)
return err;
snd_hda_codec_write_cache(codec, codec->afg, 0,
AC_VERB_SET_GPIO_UNSOLICITED_RSP_MASK, 0x10);
snd_hda_codec_write_cache(codec, codec->afg, 0,
AC_VERB_SET_UNSOLICITED_ENABLE,
AC_USRSP_EN | err);
spec->gpio_dir = 0x0b;
spec->eapd_mask = 0x01;
spec->gpio_mask = 0x1b;
spec->gpio_mute = 0x10;
spec->gpio_data = 0x01;
break;
case STAC_9205_REF:
break;
default:
spec->eapd_mask = spec->gpio_mask = spec->gpio_dir = 0x1;
spec->gpio_data = 0x01;
break;
}
err = stac92xx_parse_auto_config(codec);
if (!err) {
if (spec->board_config < 0) {
printk(KERN_WARNING "hda_codec: No auto-config is "
"available, default to model=ref\n");
spec->board_config = STAC_9205_REF;
goto again;
}
err = -EINVAL;
}
if (err < 0) {
stac92xx_free(codec);
return err;
}
codec->patch_ops = stac92xx_patch_ops;
codec->proc_widget_hook = stac9205_proc_hook;
return 0;
}
static int patch_stac9872(struct hda_codec *codec)
{
struct sigmatel_spec *spec;
int err;
spec = kzalloc(sizeof(*spec), GFP_KERNEL);
if (spec == NULL)
return -ENOMEM;
codec->no_trigger_sense = 1;
codec->spec = spec;
spec->linear_tone_beep = 1;
spec->num_pins = ARRAY_SIZE(stac9872_pin_nids);
spec->pin_nids = stac9872_pin_nids;
spec->board_config = snd_hda_check_board_config(codec, STAC_9872_MODELS,
stac9872_models,
stac9872_cfg_tbl);
if (spec->board_config < 0)
snd_printdd(KERN_INFO "hda_codec: %s: BIOS auto-probing.\n",
codec->chip_name);
else
stac92xx_set_config_regs(codec,
stac9872_brd_tbl[spec->board_config]);
spec->multiout.dac_nids = spec->dac_nids;
spec->num_adcs = ARRAY_SIZE(stac9872_adc_nids);
spec->adc_nids = stac9872_adc_nids;
spec->num_muxes = ARRAY_SIZE(stac9872_mux_nids);
spec->mux_nids = stac9872_mux_nids;
spec->init = stac9872_core_init;
spec->num_caps = 1;
spec->capvols = stac9872_capvols;
spec->capsws = stac9872_capsws;
err = stac92xx_parse_auto_config(codec);
if (err < 0) {
stac92xx_free(codec);
return -EINVAL;
}
spec->input_mux = &spec->private_imux;
codec->patch_ops = stac92xx_patch_ops;
return 0;
}
static int __init patch_sigmatel_init(void)
{
return snd_hda_add_codec_preset(&sigmatel_list);
}
static void __exit patch_sigmatel_exit(void)
{
snd_hda_delete_codec_preset(&sigmatel_list);
}
