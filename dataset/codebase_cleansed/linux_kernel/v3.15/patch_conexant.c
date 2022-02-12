static inline void set_beep_amp(struct conexant_spec *spec, hda_nid_t nid,
int idx, int dir)
{
spec->gen.beep_nid = nid;
spec->beep_amp = HDA_COMPOSE_AMP_VAL(nid, 1, idx, dir);
}
static int add_beep_ctls(struct hda_codec *codec)
{
struct conexant_spec *spec = codec->spec;
int err;
if (spec->beep_amp) {
const struct snd_kcontrol_new *knew;
for (knew = cxt_beep_mixer; knew->name; knew++) {
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
return 0;
}
static int conexant_playback_pcm_open(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
struct snd_pcm_substream *substream)
{
struct conexant_spec *spec = codec->spec;
return snd_hda_multi_out_analog_open(codec, &spec->multiout, substream,
hinfo);
}
static int conexant_playback_pcm_prepare(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
unsigned int stream_tag,
unsigned int format,
struct snd_pcm_substream *substream)
{
struct conexant_spec *spec = codec->spec;
return snd_hda_multi_out_analog_prepare(codec, &spec->multiout,
stream_tag,
format, substream);
}
static int conexant_playback_pcm_cleanup(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
struct snd_pcm_substream *substream)
{
struct conexant_spec *spec = codec->spec;
return snd_hda_multi_out_analog_cleanup(codec, &spec->multiout);
}
static int conexant_dig_playback_pcm_open(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
struct snd_pcm_substream *substream)
{
struct conexant_spec *spec = codec->spec;
return snd_hda_multi_out_dig_open(codec, &spec->multiout);
}
static int conexant_dig_playback_pcm_close(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
struct snd_pcm_substream *substream)
{
struct conexant_spec *spec = codec->spec;
return snd_hda_multi_out_dig_close(codec, &spec->multiout);
}
static int conexant_dig_playback_pcm_prepare(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
unsigned int stream_tag,
unsigned int format,
struct snd_pcm_substream *substream)
{
struct conexant_spec *spec = codec->spec;
return snd_hda_multi_out_dig_prepare(codec, &spec->multiout,
stream_tag,
format, substream);
}
static int conexant_capture_pcm_prepare(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
unsigned int stream_tag,
unsigned int format,
struct snd_pcm_substream *substream)
{
struct conexant_spec *spec = codec->spec;
snd_hda_codec_setup_stream(codec, spec->adc_nids[substream->number],
stream_tag, 0, format);
return 0;
}
static int conexant_capture_pcm_cleanup(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
struct snd_pcm_substream *substream)
{
struct conexant_spec *spec = codec->spec;
snd_hda_codec_cleanup_stream(codec, spec->adc_nids[substream->number]);
return 0;
}
static int cx5051_capture_pcm_prepare(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
unsigned int stream_tag,
unsigned int format,
struct snd_pcm_substream *substream)
{
struct conexant_spec *spec = codec->spec;
spec->cur_adc = spec->adc_nids[spec->cur_adc_idx];
spec->cur_adc_stream_tag = stream_tag;
spec->cur_adc_format = format;
snd_hda_codec_setup_stream(codec, spec->cur_adc, stream_tag, 0, format);
return 0;
}
static int cx5051_capture_pcm_cleanup(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
struct snd_pcm_substream *substream)
{
struct conexant_spec *spec = codec->spec;
snd_hda_codec_cleanup_stream(codec, spec->cur_adc);
spec->cur_adc = 0;
return 0;
}
static int conexant_build_pcms(struct hda_codec *codec)
{
struct conexant_spec *spec = codec->spec;
struct hda_pcm *info = spec->pcm_rec;
codec->num_pcms = 1;
codec->pcm_info = info;
info->name = "CONEXANT Analog";
info->stream[SNDRV_PCM_STREAM_PLAYBACK] = conexant_pcm_analog_playback;
info->stream[SNDRV_PCM_STREAM_PLAYBACK].channels_max =
spec->multiout.max_channels;
info->stream[SNDRV_PCM_STREAM_PLAYBACK].nid =
spec->multiout.dac_nids[0];
if (spec->capture_stream)
info->stream[SNDRV_PCM_STREAM_CAPTURE] = *spec->capture_stream;
else {
if (codec->vendor_id == 0x14f15051)
info->stream[SNDRV_PCM_STREAM_CAPTURE] =
cx5051_pcm_analog_capture;
else {
info->stream[SNDRV_PCM_STREAM_CAPTURE] =
conexant_pcm_analog_capture;
info->stream[SNDRV_PCM_STREAM_CAPTURE].substreams =
spec->num_adc_nids;
}
}
info->stream[SNDRV_PCM_STREAM_CAPTURE].nid = spec->adc_nids[0];
if (spec->multiout.dig_out_nid) {
info++;
codec->num_pcms++;
info->name = "Conexant Digital";
info->pcm_type = HDA_PCM_TYPE_SPDIF;
info->stream[SNDRV_PCM_STREAM_PLAYBACK] =
conexant_pcm_digital_playback;
info->stream[SNDRV_PCM_STREAM_PLAYBACK].nid =
spec->multiout.dig_out_nid;
if (spec->dig_in_nid) {
info->stream[SNDRV_PCM_STREAM_CAPTURE] =
conexant_pcm_digital_capture;
info->stream[SNDRV_PCM_STREAM_CAPTURE].nid =
spec->dig_in_nid;
}
}
return 0;
}
static int conexant_mux_enum_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct conexant_spec *spec = codec->spec;
return snd_hda_input_mux_info(spec->input_mux, uinfo);
}
static int conexant_mux_enum_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct conexant_spec *spec = codec->spec;
unsigned int adc_idx = snd_ctl_get_ioffidx(kcontrol, &ucontrol->id);
ucontrol->value.enumerated.item[0] = spec->cur_mux[adc_idx];
return 0;
}
static int conexant_mux_enum_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct conexant_spec *spec = codec->spec;
unsigned int adc_idx = snd_ctl_get_ioffidx(kcontrol, &ucontrol->id);
return snd_hda_input_mux_put(codec, spec->input_mux, ucontrol,
spec->capsrc_nids[adc_idx],
&spec->cur_mux[adc_idx]);
}
static void conexant_set_power(struct hda_codec *codec, hda_nid_t fg,
unsigned int power_state)
{
if (power_state == AC_PWRST_D3)
msleep(100);
snd_hda_codec_read(codec, fg, 0, AC_VERB_SET_POWER_STATE,
power_state);
if (power_state == AC_PWRST_D0)
msleep(10);
snd_hda_codec_set_power_to_all(codec, fg, power_state);
}
static int conexant_init(struct hda_codec *codec)
{
struct conexant_spec *spec = codec->spec;
int i;
for (i = 0; i < spec->num_init_verbs; i++)
snd_hda_sequence_write(codec, spec->init_verbs[i]);
return 0;
}
static void conexant_free(struct hda_codec *codec)
{
kfree(codec->spec);
}
static int conexant_build_controls(struct hda_codec *codec)
{
struct conexant_spec *spec = codec->spec;
unsigned int i;
int err;
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
err = snd_hda_create_spdif_in_ctls(codec,spec->dig_in_nid);
if (err < 0)
return err;
}
if (spec->vmaster_nid &&
!snd_hda_find_mixer_ctl(codec, "Master Playback Volume")) {
unsigned int vmaster_tlv[4];
snd_hda_set_vmaster_tlv(codec, spec->vmaster_nid,
HDA_OUTPUT, vmaster_tlv);
err = snd_hda_add_vmaster(codec, "Master Playback Volume",
vmaster_tlv, slave_pfxs,
"Playback Volume");
if (err < 0)
return err;
}
if (spec->vmaster_nid &&
!snd_hda_find_mixer_ctl(codec, "Master Playback Switch")) {
err = snd_hda_add_vmaster(codec, "Master Playback Switch",
NULL, slave_pfxs,
"Playback Switch");
if (err < 0)
return err;
}
if (spec->input_mux) {
err = snd_hda_add_new_ctls(codec, cxt_capture_mixers);
if (err < 0)
return err;
}
err = add_beep_ctls(codec);
if (err < 0)
return err;
return 0;
}
static int cxt_eapd_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct conexant_spec *spec = codec->spec;
int invert = (kcontrol->private_value >> 8) & 1;
if (invert)
ucontrol->value.integer.value[0] = !spec->cur_eapd;
else
ucontrol->value.integer.value[0] = spec->cur_eapd;
return 0;
}
static int cxt_eapd_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct conexant_spec *spec = codec->spec;
int invert = (kcontrol->private_value >> 8) & 1;
hda_nid_t nid = kcontrol->private_value & 0xff;
unsigned int eapd;
eapd = !!ucontrol->value.integer.value[0];
if (invert)
eapd = !eapd;
if (eapd == spec->cur_eapd)
return 0;
spec->cur_eapd = eapd;
snd_hda_codec_write_cache(codec, nid,
0, AC_VERB_SET_EAPD_BTLENABLE,
eapd ? 0x02 : 0x00);
return 1;
}
static int conexant_ch_mode_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct conexant_spec *spec = codec->spec;
return snd_hda_ch_mode_info(codec, uinfo, spec->channel_mode,
spec->num_channel_mode);
}
static int conexant_ch_mode_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct conexant_spec *spec = codec->spec;
return snd_hda_ch_mode_get(codec, ucontrol, spec->channel_mode,
spec->num_channel_mode,
spec->multiout.max_channels);
}
static int conexant_ch_mode_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct conexant_spec *spec = codec->spec;
int err = snd_hda_ch_mode_put(codec, ucontrol, spec->channel_mode,
spec->num_channel_mode,
&spec->multiout.max_channels);
return err;
}
static int cxt5045_hp_master_sw_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct conexant_spec *spec = codec->spec;
unsigned int bits;
if (!cxt_eapd_put(kcontrol, ucontrol))
return 0;
bits = (!spec->hp_present && spec->cur_eapd) ? 0 : HDA_AMP_MUTE;
snd_hda_codec_amp_stereo(codec, 0x10, HDA_OUTPUT, 0,
HDA_AMP_MUTE, bits);
bits = spec->cur_eapd ? 0 : HDA_AMP_MUTE;
snd_hda_codec_amp_stereo(codec, 0x11, HDA_OUTPUT, 0,
HDA_AMP_MUTE, bits);
return 1;
}
static void cxt5045_hp_automic(struct hda_codec *codec)
{
static const struct hda_verb mic_jack_on[] = {
{0x14, AC_VERB_SET_AMP_GAIN_MUTE, 0xb080},
{0x12, AC_VERB_SET_AMP_GAIN_MUTE, 0xb000},
{}
};
static const struct hda_verb mic_jack_off[] = {
{0x12, AC_VERB_SET_AMP_GAIN_MUTE, 0xb080},
{0x14, AC_VERB_SET_AMP_GAIN_MUTE, 0xb000},
{}
};
unsigned int present;
present = snd_hda_jack_detect(codec, 0x12);
if (present)
snd_hda_sequence_write(codec, mic_jack_on);
else
snd_hda_sequence_write(codec, mic_jack_off);
}
static void cxt5045_hp_automute(struct hda_codec *codec)
{
struct conexant_spec *spec = codec->spec;
unsigned int bits;
spec->hp_present = snd_hda_jack_detect(codec, 0x11);
bits = (spec->hp_present || !spec->cur_eapd) ? HDA_AMP_MUTE : 0;
snd_hda_codec_amp_stereo(codec, 0x10, HDA_OUTPUT, 0,
HDA_AMP_MUTE, bits);
}
static void cxt5045_hp_unsol_event(struct hda_codec *codec,
unsigned int res)
{
res >>= 26;
switch (res) {
case CONEXANT_HP_EVENT:
cxt5045_hp_automute(codec);
break;
case CONEXANT_MIC_EVENT:
cxt5045_hp_automic(codec);
break;
}
}
static int cxt5045_init(struct hda_codec *codec)
{
conexant_init(codec);
cxt5045_hp_automute(codec);
return 0;
}
static int patch_cxt5045(struct hda_codec *codec)
{
struct conexant_spec *spec;
int board_config;
board_config = snd_hda_check_board_config(codec, CXT5045_MODELS,
cxt5045_models,
cxt5045_cfg_tbl);
if (board_config < 0)
board_config = CXT5045_AUTO;
if (board_config == CXT5045_AUTO)
return patch_conexant_auto(codec);
spec = kzalloc(sizeof(*spec), GFP_KERNEL);
if (!spec)
return -ENOMEM;
codec->spec = spec;
codec->single_adc_amp = 1;
spec->multiout.max_channels = 2;
spec->multiout.num_dacs = ARRAY_SIZE(cxt5045_dac_nids);
spec->multiout.dac_nids = cxt5045_dac_nids;
spec->multiout.dig_out_nid = CXT5045_SPDIF_OUT;
spec->num_adc_nids = 1;
spec->adc_nids = cxt5045_adc_nids;
spec->capsrc_nids = cxt5045_capsrc_nids;
spec->input_mux = &cxt5045_capture_source;
spec->num_mixers = 1;
spec->mixers[0] = cxt5045_mixers;
spec->num_init_verbs = 1;
spec->init_verbs[0] = cxt5045_init_verbs;
spec->spdif_route = 0;
spec->num_channel_mode = ARRAY_SIZE(cxt5045_modes);
spec->channel_mode = cxt5045_modes;
set_beep_amp(spec, 0x16, 0, 1);
codec->patch_ops = conexant_patch_ops;
switch (board_config) {
case CXT5045_LAPTOP_HPSENSE:
codec->patch_ops.unsol_event = cxt5045_hp_unsol_event;
spec->input_mux = &cxt5045_capture_source;
spec->num_init_verbs = 2;
spec->init_verbs[1] = cxt5045_hp_sense_init_verbs;
spec->mixers[0] = cxt5045_mixers;
codec->patch_ops.init = cxt5045_init;
break;
case CXT5045_LAPTOP_MICSENSE:
codec->patch_ops.unsol_event = cxt5045_hp_unsol_event;
spec->input_mux = &cxt5045_capture_source;
spec->num_init_verbs = 2;
spec->init_verbs[1] = cxt5045_mic_sense_init_verbs;
spec->mixers[0] = cxt5045_mixers;
codec->patch_ops.init = cxt5045_init;
break;
default:
case CXT5045_LAPTOP_HPMICSENSE:
codec->patch_ops.unsol_event = cxt5045_hp_unsol_event;
spec->input_mux = &cxt5045_capture_source;
spec->num_init_verbs = 3;
spec->init_verbs[1] = cxt5045_hp_sense_init_verbs;
spec->init_verbs[2] = cxt5045_mic_sense_init_verbs;
spec->mixers[0] = cxt5045_mixers;
codec->patch_ops.init = cxt5045_init;
break;
case CXT5045_BENQ:
codec->patch_ops.unsol_event = cxt5045_hp_unsol_event;
spec->input_mux = &cxt5045_capture_source_benq;
spec->num_init_verbs = 1;
spec->init_verbs[0] = cxt5045_benq_init_verbs;
spec->mixers[0] = cxt5045_mixers;
spec->mixers[1] = cxt5045_benq_mixers;
spec->num_mixers = 2;
codec->patch_ops.init = cxt5045_init;
break;
#ifdef CONFIG_SND_DEBUG
case CXT5045_TEST:
spec->input_mux = &cxt5045_test_capture_source;
spec->mixers[0] = cxt5045_test_mixer;
spec->init_verbs[0] = cxt5045_test_init_verbs;
break;
#endif
}
switch (codec->subsystem_id >> 16) {
case 0x103c:
case 0x1631:
case 0x1734:
case 0x17aa:
snd_hda_override_amp_caps(codec, 0x17, HDA_INPUT,
(0x14 << AC_AMPCAP_OFFSET_SHIFT) |
(0x14 << AC_AMPCAP_NUM_STEPS_SHIFT) |
(0x05 << AC_AMPCAP_STEP_SIZE_SHIFT) |
(1 << AC_AMPCAP_MUTE_SHIFT));
break;
}
if (spec->beep_amp)
snd_hda_attach_beep_device(codec, get_amp_nid_(spec->beep_amp));
return 0;
}
static int cxt5047_hp_master_sw_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct conexant_spec *spec = codec->spec;
unsigned int bits;
if (!cxt_eapd_put(kcontrol, ucontrol))
return 0;
bits = (!spec->hp_present && spec->cur_eapd) ? 0 : HDA_AMP_MUTE;
snd_hda_codec_amp_stereo(codec, 0x1d, HDA_OUTPUT, 0x01,
HDA_AMP_MUTE, bits);
bits = spec->cur_eapd ? 0 : HDA_AMP_MUTE;
snd_hda_codec_amp_stereo(codec, 0x13, HDA_OUTPUT, 0,
HDA_AMP_MUTE, bits);
return 1;
}
static void cxt5047_hp_automute(struct hda_codec *codec)
{
struct conexant_spec *spec = codec->spec;
unsigned int bits;
spec->hp_present = snd_hda_jack_detect(codec, 0x13);
bits = (spec->hp_present || !spec->cur_eapd) ? HDA_AMP_MUTE : 0;
snd_hda_codec_amp_stereo(codec, 0x1d, HDA_OUTPUT, 0x01,
HDA_AMP_MUTE, bits);
}
static void cxt5047_hp_automic(struct hda_codec *codec)
{
static const struct hda_verb mic_jack_on[] = {
{0x15, AC_VERB_SET_AMP_GAIN_MUTE, AMP_OUT_MUTE},
{0x17, AC_VERB_SET_AMP_GAIN_MUTE, AMP_OUT_UNMUTE},
{}
};
static const struct hda_verb mic_jack_off[] = {
{0x17, AC_VERB_SET_AMP_GAIN_MUTE, AMP_OUT_MUTE},
{0x15, AC_VERB_SET_AMP_GAIN_MUTE, AMP_OUT_UNMUTE},
{}
};
unsigned int present;
present = snd_hda_jack_detect(codec, 0x15);
if (present)
snd_hda_sequence_write(codec, mic_jack_on);
else
snd_hda_sequence_write(codec, mic_jack_off);
}
static void cxt5047_hp_unsol_event(struct hda_codec *codec,
unsigned int res)
{
switch (res >> 26) {
case CONEXANT_HP_EVENT:
cxt5047_hp_automute(codec);
break;
case CONEXANT_MIC_EVENT:
cxt5047_hp_automic(codec);
break;
}
}
static int cxt5047_hp_init(struct hda_codec *codec)
{
conexant_init(codec);
cxt5047_hp_automute(codec);
return 0;
}
static int patch_cxt5047(struct hda_codec *codec)
{
struct conexant_spec *spec;
int board_config;
board_config = snd_hda_check_board_config(codec, CXT5047_MODELS,
cxt5047_models,
cxt5047_cfg_tbl);
if (board_config < 0)
board_config = CXT5047_AUTO;
if (board_config == CXT5047_AUTO)
return patch_conexant_auto(codec);
spec = kzalloc(sizeof(*spec), GFP_KERNEL);
if (!spec)
return -ENOMEM;
codec->spec = spec;
codec->pin_amp_workaround = 1;
spec->multiout.max_channels = 2;
spec->multiout.num_dacs = ARRAY_SIZE(cxt5047_dac_nids);
spec->multiout.dac_nids = cxt5047_dac_nids;
spec->multiout.dig_out_nid = CXT5047_SPDIF_OUT;
spec->num_adc_nids = 1;
spec->adc_nids = cxt5047_adc_nids;
spec->capsrc_nids = cxt5047_capsrc_nids;
spec->num_mixers = 1;
spec->mixers[0] = cxt5047_base_mixers;
spec->num_init_verbs = 1;
spec->init_verbs[0] = cxt5047_init_verbs;
spec->spdif_route = 0;
spec->num_channel_mode = ARRAY_SIZE(cxt5047_modes),
spec->channel_mode = cxt5047_modes,
codec->patch_ops = conexant_patch_ops;
switch (board_config) {
case CXT5047_LAPTOP:
spec->num_mixers = 2;
spec->mixers[1] = cxt5047_hp_spk_mixers;
codec->patch_ops.unsol_event = cxt5047_hp_unsol_event;
break;
case CXT5047_LAPTOP_HP:
spec->num_mixers = 2;
spec->mixers[1] = cxt5047_hp_only_mixers;
codec->patch_ops.unsol_event = cxt5047_hp_unsol_event;
codec->patch_ops.init = cxt5047_hp_init;
break;
case CXT5047_LAPTOP_EAPD:
spec->input_mux = &cxt5047_toshiba_capture_source;
spec->num_mixers = 2;
spec->mixers[1] = cxt5047_hp_spk_mixers;
spec->num_init_verbs = 2;
spec->init_verbs[1] = cxt5047_toshiba_init_verbs;
codec->patch_ops.unsol_event = cxt5047_hp_unsol_event;
break;
#ifdef CONFIG_SND_DEBUG
case CXT5047_TEST:
spec->input_mux = &cxt5047_test_capture_source;
spec->mixers[0] = cxt5047_test_mixer;
spec->init_verbs[0] = cxt5047_test_init_verbs;
codec->patch_ops.unsol_event = cxt5047_hp_unsol_event;
#endif
}
spec->vmaster_nid = 0x13;
switch (codec->subsystem_id >> 16) {
case 0x103c:
snd_hda_override_amp_caps(codec, 0x10, HDA_INPUT,
(0x17 << AC_AMPCAP_OFFSET_SHIFT) |
(0x17 << AC_AMPCAP_NUM_STEPS_SHIFT) |
(0x05 << AC_AMPCAP_STEP_SIZE_SHIFT) |
(1 << AC_AMPCAP_MUTE_SHIFT));
break;
}
return 0;
}
static void cxt5051_update_speaker(struct hda_codec *codec)
{
struct conexant_spec *spec = codec->spec;
unsigned int pinctl;
pinctl = (spec->hp_present && spec->cur_eapd) ? PIN_HP : 0;
snd_hda_set_pin_ctl(codec, 0x16, pinctl);
pinctl = (!spec->hp_present && spec->cur_eapd) ? PIN_OUT : 0;
snd_hda_set_pin_ctl(codec, 0x1a, pinctl);
if (spec->ideapad)
snd_hda_set_pin_ctl(codec, 0x1b, pinctl);
}
static int cxt5051_hp_master_sw_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
if (!cxt_eapd_put(kcontrol, ucontrol))
return 0;
cxt5051_update_speaker(codec);
return 1;
}
static void cxt5051_portb_automic(struct hda_codec *codec)
{
struct conexant_spec *spec = codec->spec;
unsigned int present;
if (!(spec->auto_mic & AUTO_MIC_PORTB))
return;
present = snd_hda_jack_detect(codec, 0x17);
snd_hda_codec_write(codec, 0x14, 0,
AC_VERB_SET_CONNECT_SEL,
present ? 0x01 : 0x00);
}
static void cxt5051_portc_automic(struct hda_codec *codec)
{
struct conexant_spec *spec = codec->spec;
unsigned int present;
hda_nid_t new_adc;
if (!(spec->auto_mic & AUTO_MIC_PORTC))
return;
present = snd_hda_jack_detect(codec, 0x18);
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
static void cxt5051_hp_automute(struct hda_codec *codec)
{
struct conexant_spec *spec = codec->spec;
spec->hp_present = snd_hda_jack_detect(codec, 0x16);
cxt5051_update_speaker(codec);
}
static void cxt5051_hp_unsol_event(struct hda_codec *codec,
unsigned int res)
{
switch (res >> 26) {
case CONEXANT_HP_EVENT:
cxt5051_hp_automute(codec);
break;
case CXT5051_PORTB_EVENT:
cxt5051_portb_automic(codec);
break;
case CXT5051_PORTC_EVENT:
cxt5051_portc_automic(codec);
break;
}
}
static void cxt5051_init_mic_port(struct hda_codec *codec, hda_nid_t nid,
unsigned int event)
{
snd_hda_codec_write(codec, nid, 0,
AC_VERB_SET_UNSOLICITED_ENABLE,
AC_USRSP_EN | event);
}
static int cxt5051_init(struct hda_codec *codec)
{
struct conexant_spec *spec = codec->spec;
conexant_init(codec);
if (spec->auto_mic & AUTO_MIC_PORTB)
cxt5051_init_mic_port(codec, 0x17, CXT5051_PORTB_EVENT);
if (spec->auto_mic & AUTO_MIC_PORTC)
cxt5051_init_mic_port(codec, 0x18, CXT5051_PORTC_EVENT);
if (codec->patch_ops.unsol_event) {
cxt5051_hp_automute(codec);
cxt5051_portb_automic(codec);
cxt5051_portc_automic(codec);
}
return 0;
}
static int patch_cxt5051(struct hda_codec *codec)
{
struct conexant_spec *spec;
int board_config;
board_config = snd_hda_check_board_config(codec, CXT5051_MODELS,
cxt5051_models,
cxt5051_cfg_tbl);
if (board_config < 0)
board_config = CXT5051_AUTO;
if (board_config == CXT5051_AUTO)
return patch_conexant_auto(codec);
spec = kzalloc(sizeof(*spec), GFP_KERNEL);
if (!spec)
return -ENOMEM;
codec->spec = spec;
codec->pin_amp_workaround = 1;
codec->patch_ops = conexant_patch_ops;
codec->patch_ops.init = cxt5051_init;
spec->multiout.max_channels = 2;
spec->multiout.num_dacs = ARRAY_SIZE(cxt5051_dac_nids);
spec->multiout.dac_nids = cxt5051_dac_nids;
spec->multiout.dig_out_nid = CXT5051_SPDIF_OUT;
spec->num_adc_nids = 1;
spec->adc_nids = cxt5051_adc_nids;
spec->num_mixers = 2;
spec->mixers[0] = cxt5051_capture_mixers;
spec->mixers[1] = cxt5051_playback_mixers;
spec->num_init_verbs = 1;
spec->init_verbs[0] = cxt5051_init_verbs;
spec->spdif_route = 0;
spec->num_channel_mode = ARRAY_SIZE(cxt5051_modes);
spec->channel_mode = cxt5051_modes;
spec->cur_adc = 0;
spec->cur_adc_idx = 0;
set_beep_amp(spec, 0x13, 0, HDA_OUTPUT);
codec->patch_ops.unsol_event = cxt5051_hp_unsol_event;
spec->auto_mic = AUTO_MIC_PORTB | AUTO_MIC_PORTC;
switch (board_config) {
case CXT5051_HP:
spec->mixers[0] = cxt5051_hp_mixers;
break;
case CXT5051_HP_DV6736:
spec->init_verbs[0] = cxt5051_hp_dv6736_init_verbs;
spec->mixers[0] = cxt5051_hp_dv6736_mixers;
spec->auto_mic = 0;
break;
case CXT5051_F700:
spec->init_verbs[0] = cxt5051_f700_init_verbs;
spec->mixers[0] = cxt5051_f700_mixers;
spec->auto_mic = 0;
break;
case CXT5051_TOSHIBA:
spec->mixers[0] = cxt5051_toshiba_mixers;
spec->auto_mic = AUTO_MIC_PORTB;
break;
case CXT5051_IDEAPAD:
spec->init_verbs[spec->num_init_verbs++] =
cxt5051_ideapad_init_verbs;
spec->ideapad = 1;
break;
}
if (spec->beep_amp)
snd_hda_attach_beep_device(codec, get_amp_nid_(spec->beep_amp));
return 0;
}
static void cxt5066_update_speaker(struct hda_codec *codec)
{
struct conexant_spec *spec = codec->spec;
unsigned int pinctl;
codec_dbg(codec,
"CXT5066: update speaker, hp_present=%d, cur_eapd=%d\n",
spec->hp_present, spec->cur_eapd);
pinctl = (hp_port_a_present(spec) && spec->cur_eapd) ? PIN_HP : 0;
snd_hda_set_pin_ctl(codec, 0x19, pinctl);
pinctl = spec->cur_eapd ? spec->port_d_mode : 0;
if (spec->dell_automute || spec->thinkpad) {
if (hp_port_a_present(spec))
pinctl = 0;
} else {
if (!hp_port_d_present(spec))
pinctl = 0;
}
snd_hda_set_pin_ctl(codec, 0x1c, pinctl);
pinctl = (!spec->hp_present && spec->cur_eapd) ? PIN_OUT : 0;
snd_hda_set_pin_ctl(codec, 0x1f, pinctl);
}
static int cxt5066_hp_master_sw_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
if (!cxt_eapd_put(kcontrol, ucontrol))
return 0;
cxt5066_update_speaker(codec);
return 1;
}
static void cxt5066_vostro_automic(struct hda_codec *codec)
{
unsigned int present;
struct hda_verb ext_mic_present[] = {
{0x1a, AC_VERB_SET_PIN_WIDGET_CONTROL, PIN_VREF80},
{0x17, AC_VERB_SET_CONNECT_SEL, 0},
{0x14, AC_VERB_SET_CONNECT_SEL, 0},
{0x23, AC_VERB_SET_PIN_WIDGET_CONTROL, 0},
{}
};
static const struct hda_verb ext_mic_absent[] = {
{0x23, AC_VERB_SET_PIN_WIDGET_CONTROL, PIN_IN},
{0x14, AC_VERB_SET_CONNECT_SEL, 2},
{0x1a, AC_VERB_SET_PIN_WIDGET_CONTROL, 0},
{}
};
present = snd_hda_jack_detect(codec, 0x1a);
if (present) {
codec_dbg(codec, "CXT5066: external microphone detected\n");
snd_hda_sequence_write(codec, ext_mic_present);
} else {
codec_dbg(codec, "CXT5066: external microphone absent\n");
snd_hda_sequence_write(codec, ext_mic_absent);
}
}
static void cxt5066_ideapad_automic(struct hda_codec *codec)
{
unsigned int present;
struct hda_verb ext_mic_present[] = {
{0x14, AC_VERB_SET_CONNECT_SEL, 0},
{0x1b, AC_VERB_SET_PIN_WIDGET_CONTROL, PIN_VREF80},
{0x23, AC_VERB_SET_PIN_WIDGET_CONTROL, 0},
{}
};
static const struct hda_verb ext_mic_absent[] = {
{0x14, AC_VERB_SET_CONNECT_SEL, 2},
{0x23, AC_VERB_SET_PIN_WIDGET_CONTROL, PIN_IN},
{0x1b, AC_VERB_SET_PIN_WIDGET_CONTROL, 0},
{}
};
present = snd_hda_jack_detect(codec, 0x1b);
if (present) {
codec_dbg(codec, "CXT5066: external microphone detected\n");
snd_hda_sequence_write(codec, ext_mic_present);
} else {
codec_dbg(codec, "CXT5066: external microphone absent\n");
snd_hda_sequence_write(codec, ext_mic_absent);
}
}
static void cxt5066_asus_automic(struct hda_codec *codec)
{
unsigned int present;
present = snd_hda_jack_detect(codec, 0x1b);
codec_dbg(codec, "CXT5066: external microphone present=%d\n", present);
snd_hda_codec_write(codec, 0x17, 0, AC_VERB_SET_CONNECT_SEL,
present ? 1 : 0);
}
static void cxt5066_hp_laptop_automic(struct hda_codec *codec)
{
unsigned int present;
present = snd_hda_jack_detect(codec, 0x1b);
codec_dbg(codec, "CXT5066: external microphone present=%d\n", present);
snd_hda_codec_write(codec, 0x17, 0, AC_VERB_SET_CONNECT_SEL,
present ? 1 : 3);
}
static void cxt5066_thinkpad_automic(struct hda_codec *codec)
{
unsigned int ext_present, dock_present;
static const struct hda_verb ext_mic_present[] = {
{0x14, AC_VERB_SET_CONNECT_SEL, 0},
{0x17, AC_VERB_SET_CONNECT_SEL, 1},
{0x1b, AC_VERB_SET_PIN_WIDGET_CONTROL, PIN_VREF80},
{0x23, AC_VERB_SET_PIN_WIDGET_CONTROL, 0},
{0x1a, AC_VERB_SET_PIN_WIDGET_CONTROL, 0},
{}
};
static const struct hda_verb dock_mic_present[] = {
{0x14, AC_VERB_SET_CONNECT_SEL, 0},
{0x17, AC_VERB_SET_CONNECT_SEL, 0},
{0x1a, AC_VERB_SET_PIN_WIDGET_CONTROL, PIN_VREF80},
{0x23, AC_VERB_SET_PIN_WIDGET_CONTROL, 0},
{0x1b, AC_VERB_SET_PIN_WIDGET_CONTROL, 0},
{}
};
static const struct hda_verb ext_mic_absent[] = {
{0x14, AC_VERB_SET_CONNECT_SEL, 2},
{0x23, AC_VERB_SET_PIN_WIDGET_CONTROL, PIN_IN},
{0x1b, AC_VERB_SET_PIN_WIDGET_CONTROL, 0},
{0x1a, AC_VERB_SET_PIN_WIDGET_CONTROL, 0},
{}
};
ext_present = snd_hda_jack_detect(codec, 0x1b);
dock_present = snd_hda_jack_detect(codec, 0x1a);
if (ext_present) {
codec_dbg(codec, "CXT5066: external microphone detected\n");
snd_hda_sequence_write(codec, ext_mic_present);
} else if (dock_present) {
codec_dbg(codec, "CXT5066: dock microphone detected\n");
snd_hda_sequence_write(codec, dock_mic_present);
} else {
codec_dbg(codec, "CXT5066: external microphone absent\n");
snd_hda_sequence_write(codec, ext_mic_absent);
}
}
static void cxt5066_hp_automute(struct hda_codec *codec)
{
struct conexant_spec *spec = codec->spec;
unsigned int portA, portD;
portA = snd_hda_jack_detect(codec, 0x19);
portD = snd_hda_jack_detect(codec, 0x1c);
spec->hp_present = portA ? HP_PRESENT_PORT_A : 0;
spec->hp_present |= portD ? HP_PRESENT_PORT_D : 0;
codec_dbg(codec, "CXT5066: hp automute portA=%x portD=%x present=%d\n",
portA, portD, spec->hp_present);
cxt5066_update_speaker(codec);
}
static void cxt5066_automic(struct hda_codec *codec)
{
struct conexant_spec *spec = codec->spec;
if (spec->dell_vostro)
cxt5066_vostro_automic(codec);
else if (spec->ideapad)
cxt5066_ideapad_automic(codec);
else if (spec->thinkpad)
cxt5066_thinkpad_automic(codec);
else if (spec->hp_laptop)
cxt5066_hp_laptop_automic(codec);
else if (spec->asus)
cxt5066_asus_automic(codec);
}
static void cxt5066_unsol_event(struct hda_codec *codec, unsigned int res)
{
codec_dbg(codec, "CXT5066: unsol event %x (%x)\n", res, res >> 26);
switch (res >> 26) {
case CONEXANT_HP_EVENT:
cxt5066_hp_automute(codec);
break;
case CONEXANT_MIC_EVENT:
cxt5066_automic(codec);
break;
}
}
static void cxt5066_set_mic_boost(struct hda_codec *codec)
{
struct conexant_spec *spec = codec->spec;
snd_hda_codec_write_cache(codec, 0x17, 0,
AC_VERB_SET_AMP_GAIN_MUTE,
AC_AMP_SET_RIGHT | AC_AMP_SET_LEFT | AC_AMP_SET_OUTPUT |
cxt5066_analog_mic_boost.items[spec->mic_boost].index);
if (spec->ideapad || spec->thinkpad) {
snd_hda_codec_write_cache(codec, 0x23, 0,
AC_VERB_SET_AMP_GAIN_MUTE,
AC_AMP_SET_RIGHT | AC_AMP_SET_LEFT | AC_AMP_SET_INPUT |
cxt5066_analog_mic_boost.
items[spec->mic_boost].index);
}
}
static int cxt5066_mic_boost_mux_enum_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
return snd_hda_input_mux_info(&cxt5066_analog_mic_boost, uinfo);
}
static int cxt5066_mic_boost_mux_enum_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct conexant_spec *spec = codec->spec;
ucontrol->value.enumerated.item[0] = spec->mic_boost;
return 0;
}
static int cxt5066_mic_boost_mux_enum_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct conexant_spec *spec = codec->spec;
const struct hda_input_mux *imux = &cxt5066_analog_mic_boost;
unsigned int idx;
idx = ucontrol->value.enumerated.item[0];
if (idx >= imux->num_items)
idx = imux->num_items - 1;
spec->mic_boost = idx;
cxt5066_set_mic_boost(codec);
return 1;
}
static void conexant_check_dig_outs(struct hda_codec *codec,
const hda_nid_t *dig_pins,
int num_pins)
{
struct conexant_spec *spec = codec->spec;
hda_nid_t *nid_loc = &spec->multiout.dig_out_nid;
int i;
for (i = 0; i < num_pins; i++, dig_pins++) {
unsigned int cfg = snd_hda_codec_get_pincfg(codec, *dig_pins);
if (get_defcfg_connect(cfg) == AC_JACK_PORT_NONE)
continue;
if (snd_hda_get_connections(codec, *dig_pins, nid_loc, 1) != 1)
continue;
}
}
static int cxt5066_init(struct hda_codec *codec)
{
codec_dbg(codec, "CXT5066: init\n");
conexant_init(codec);
if (codec->patch_ops.unsol_event) {
cxt5066_hp_automute(codec);
cxt5066_automic(codec);
}
cxt5066_set_mic_boost(codec);
return 0;
}
static int patch_cxt5066(struct hda_codec *codec)
{
struct conexant_spec *spec;
int board_config;
board_config = snd_hda_check_board_config(codec, CXT5066_MODELS,
cxt5066_models, cxt5066_cfg_tbl);
if (board_config < 0)
board_config = CXT5066_AUTO;
if (board_config == CXT5066_AUTO)
return patch_conexant_auto(codec);
spec = kzalloc(sizeof(*spec), GFP_KERNEL);
if (!spec)
return -ENOMEM;
codec->spec = spec;
codec->patch_ops = conexant_patch_ops;
codec->patch_ops.init = conexant_init;
spec->dell_automute = 0;
spec->multiout.max_channels = 2;
spec->multiout.num_dacs = ARRAY_SIZE(cxt5066_dac_nids);
spec->multiout.dac_nids = cxt5066_dac_nids;
conexant_check_dig_outs(codec, cxt5066_digout_pin_nids,
ARRAY_SIZE(cxt5066_digout_pin_nids));
spec->num_adc_nids = 1;
spec->adc_nids = cxt5066_adc_nids;
spec->capsrc_nids = cxt5066_capsrc_nids;
spec->input_mux = &cxt5066_capture_source;
spec->port_d_mode = PIN_HP;
spec->num_init_verbs = 1;
spec->init_verbs[0] = cxt5066_init_verbs;
spec->num_channel_mode = ARRAY_SIZE(cxt5066_modes);
spec->channel_mode = cxt5066_modes;
spec->cur_adc = 0;
spec->cur_adc_idx = 0;
set_beep_amp(spec, 0x13, 0, HDA_OUTPUT);
switch (board_config) {
default:
case CXT5066_LAPTOP:
spec->mixers[spec->num_mixers++] = cxt5066_mixer_master;
spec->mixers[spec->num_mixers++] = cxt5066_mixers;
break;
case CXT5066_DELL_LAPTOP:
spec->mixers[spec->num_mixers++] = cxt5066_mixer_master;
spec->mixers[spec->num_mixers++] = cxt5066_mixers;
spec->port_d_mode = PIN_OUT;
spec->init_verbs[spec->num_init_verbs] = cxt5066_init_verbs_portd_lo;
spec->num_init_verbs++;
spec->dell_automute = 1;
break;
case CXT5066_ASUS:
case CXT5066_HP_LAPTOP:
codec->patch_ops.init = cxt5066_init;
codec->patch_ops.unsol_event = cxt5066_unsol_event;
spec->init_verbs[spec->num_init_verbs] =
cxt5066_init_verbs_hp_laptop;
spec->num_init_verbs++;
spec->hp_laptop = board_config == CXT5066_HP_LAPTOP;
spec->asus = board_config == CXT5066_ASUS;
spec->mixers[spec->num_mixers++] = cxt5066_mixer_master;
spec->mixers[spec->num_mixers++] = cxt5066_mixers;
if (board_config == CXT5066_HP_LAPTOP)
spec->multiout.dig_out_nid = 0;
spec->input_mux = NULL;
spec->port_d_mode = 0;
spec->mic_boost = 3;
break;
case CXT5066_DELL_VOSTRO:
codec->patch_ops.init = cxt5066_init;
codec->patch_ops.unsol_event = cxt5066_unsol_event;
spec->init_verbs[0] = cxt5066_init_verbs_vostro;
spec->mixers[spec->num_mixers++] = cxt5066_mixer_master;
spec->mixers[spec->num_mixers++] = cxt5066_mixers;
spec->mixers[spec->num_mixers++] = cxt5066_vostro_mixers;
spec->port_d_mode = 0;
spec->dell_vostro = 1;
spec->mic_boost = 3;
spec->multiout.dig_out_nid = 0;
spec->input_mux = NULL;
break;
case CXT5066_IDEAPAD:
codec->patch_ops.init = cxt5066_init;
codec->patch_ops.unsol_event = cxt5066_unsol_event;
spec->mixers[spec->num_mixers++] = cxt5066_mixer_master;
spec->mixers[spec->num_mixers++] = cxt5066_mixers;
spec->init_verbs[0] = cxt5066_init_verbs_ideapad;
spec->port_d_mode = 0;
spec->ideapad = 1;
spec->mic_boost = 2;
spec->multiout.dig_out_nid = 0;
spec->input_mux = NULL;
break;
case CXT5066_THINKPAD:
codec->patch_ops.init = cxt5066_init;
codec->patch_ops.unsol_event = cxt5066_unsol_event;
spec->mixers[spec->num_mixers++] = cxt5066_mixer_master;
spec->mixers[spec->num_mixers++] = cxt5066_mixers;
spec->init_verbs[0] = cxt5066_init_verbs_thinkpad;
spec->thinkpad = 1;
spec->port_d_mode = PIN_OUT;
spec->mic_boost = 2;
spec->multiout.dig_out_nid = 0;
spec->input_mux = NULL;
break;
}
if (spec->beep_amp)
snd_hda_attach_beep_device(codec, get_amp_nid_(spec->beep_amp));
return 0;
}
static void cx_auto_parse_beep(struct hda_codec *codec)
{
struct conexant_spec *spec = codec->spec;
hda_nid_t nid, end_nid;
end_nid = codec->start_nid + codec->num_nodes;
for (nid = codec->start_nid; nid < end_nid; nid++)
if (get_wcaps_type(get_wcaps(codec, nid)) == AC_WID_BEEP) {
set_beep_amp(spec, nid, 0, HDA_OUTPUT);
break;
}
}
static void cx_auto_parse_eapd(struct hda_codec *codec)
{
struct conexant_spec *spec = codec->spec;
hda_nid_t nid, end_nid;
end_nid = codec->start_nid + codec->num_nodes;
for (nid = codec->start_nid; nid < end_nid; nid++) {
if (get_wcaps_type(get_wcaps(codec, nid)) != AC_WID_PIN)
continue;
if (!(snd_hda_query_pin_caps(codec, nid) & AC_PINCAP_EAPD))
continue;
spec->eapds[spec->num_eapds++] = nid;
if (spec->num_eapds >= ARRAY_SIZE(spec->eapds))
break;
}
if (spec->num_eapds > 2)
spec->dynamic_eapd = 1;
}
static void cx_auto_turn_eapd(struct hda_codec *codec, int num_pins,
hda_nid_t *pins, bool on)
{
int i;
for (i = 0; i < num_pins; i++) {
if (snd_hda_query_pin_caps(codec, pins[i]) & AC_PINCAP_EAPD)
snd_hda_codec_write(codec, pins[i], 0,
AC_VERB_SET_EAPD_BTLENABLE,
on ? 0x02 : 0);
}
}
static void cx_auto_vmaster_hook(void *private_data, int enabled)
{
struct hda_codec *codec = private_data;
struct conexant_spec *spec = codec->spec;
cx_auto_turn_eapd(codec, spec->num_eapds, spec->eapds, enabled);
}
static int cx_auto_build_controls(struct hda_codec *codec)
{
int err;
err = snd_hda_gen_build_controls(codec);
if (err < 0)
return err;
err = add_beep_ctls(codec);
if (err < 0)
return err;
return 0;
}
static int cx_auto_init(struct hda_codec *codec)
{
struct conexant_spec *spec = codec->spec;
snd_hda_gen_init(codec);
if (!spec->dynamic_eapd)
cx_auto_turn_eapd(codec, spec->num_eapds, spec->eapds, true);
snd_hda_apply_fixup(codec, HDA_FIXUP_ACT_INIT);
return 0;
}
static void cxt_fixup_stereo_dmic(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
struct conexant_spec *spec = codec->spec;
spec->gen.inv_dmic_split = 1;
}
static void cxt5066_increase_mic_boost(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
if (action != HDA_FIXUP_ACT_PRE_PROBE)
return;
snd_hda_override_amp_caps(codec, 0x17, HDA_OUTPUT,
(0x3 << AC_AMPCAP_OFFSET_SHIFT) |
(0x4 << AC_AMPCAP_NUM_STEPS_SHIFT) |
(0x27 << AC_AMPCAP_STEP_SIZE_SHIFT) |
(0 << AC_AMPCAP_MUTE_SHIFT));
}
static void cxt_update_headset_mode(struct hda_codec *codec)
{
int i;
bool mic_mode = false;
struct conexant_spec *spec = codec->spec;
struct auto_pin_cfg *cfg = &spec->gen.autocfg;
hda_nid_t mux_pin = spec->gen.imux_pins[spec->gen.cur_mux[0]];
for (i = 0; i < cfg->num_inputs; i++)
if (cfg->inputs[i].pin == mux_pin) {
mic_mode = !!cfg->inputs[i].is_headphone_mic;
break;
}
if (mic_mode) {
snd_hda_codec_write_cache(codec, 0x1c, 0, 0x410, 0x7c);
spec->gen.hp_jack_present = false;
} else {
snd_hda_codec_write_cache(codec, 0x1c, 0, 0x410, 0x54);
spec->gen.hp_jack_present = snd_hda_jack_detect(codec, spec->gen.autocfg.hp_pins[0]);
}
snd_hda_gen_update_outputs(codec);
}
static void cxt_update_headset_mode_hook(struct hda_codec *codec,
struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
cxt_update_headset_mode(codec);
}
static void cxt_fixup_headphone_mic(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
struct conexant_spec *spec = codec->spec;
switch (action) {
case HDA_FIXUP_ACT_PRE_PROBE:
spec->parse_flags |= HDA_PINCFG_HEADPHONE_MIC;
break;
case HDA_FIXUP_ACT_PROBE:
spec->gen.cap_sync_hook = cxt_update_headset_mode_hook;
spec->gen.automute_hook = cxt_update_headset_mode;
break;
case HDA_FIXUP_ACT_INIT:
cxt_update_headset_mode(codec);
break;
}
}
static void olpc_xo_update_mic_boost(struct hda_codec *codec)
{
struct conexant_spec *spec = codec->spec;
int ch, val;
for (ch = 0; ch < 2; ch++) {
val = AC_AMP_SET_OUTPUT |
(ch ? AC_AMP_SET_RIGHT : AC_AMP_SET_LEFT);
if (!spec->dc_enable)
val |= snd_hda_codec_amp_read(codec, 0x17, ch, HDA_OUTPUT, 0);
snd_hda_codec_write(codec, 0x17, 0,
AC_VERB_SET_AMP_GAIN_MUTE, val);
}
}
static void olpc_xo_update_mic_pins(struct hda_codec *codec)
{
struct conexant_spec *spec = codec->spec;
int cur_input, val;
struct nid_path *path;
cur_input = spec->gen.input_paths[0][spec->gen.cur_mux[0]];
if (!spec->dc_enable) {
update_mic_pin(codec, 0x1e, 0);
snd_hda_activate_path(codec, spec->dc_mode_path, false, false);
update_mic_pin(codec, 0x1a, spec->recording ?
snd_hda_codec_get_pin_target(codec, 0x1a) : 0);
update_mic_pin(codec, 0x1b, spec->recording ?
snd_hda_codec_get_pin_target(codec, 0x1b) : 0);
path = snd_hda_get_path_from_idx(codec, cur_input);
if (path)
snd_hda_activate_path(codec, path, true, false);
} else {
path = snd_hda_get_path_from_idx(codec, cur_input);
if (path)
snd_hda_activate_path(codec, path, false, false);
if (spec->recording)
val = olpc_xo_dc_bias.items[spec->dc_input_bias].index;
else
val = 0;
update_mic_pin(codec, 0x1a, val);
update_mic_pin(codec, 0x1b, 0);
update_mic_pin(codec, 0x1e, spec->recording ? PIN_IN : 0);
snd_hda_activate_path(codec, spec->dc_mode_path, true, false);
}
}
static void olpc_xo_automic(struct hda_codec *codec, struct hda_jack_tbl *jack)
{
struct conexant_spec *spec = codec->spec;
int saved_cached_write = codec->cached_write;
codec->cached_write = 1;
if (!spec->dc_enable)
snd_hda_gen_mic_autoswitch(codec, jack);
olpc_xo_update_mic_pins(codec);
snd_hda_codec_flush_cache(codec);
codec->cached_write = saved_cached_write;
if (spec->dc_enable)
olpc_xo_update_mic_boost(codec);
}
static void olpc_xo_capture_hook(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
struct snd_pcm_substream *substream,
int action)
{
struct conexant_spec *spec = codec->spec;
switch (action) {
case HDA_GEN_PCM_ACT_PREPARE:
spec->recording = 1;
olpc_xo_update_mic_pins(codec);
break;
case HDA_GEN_PCM_ACT_CLEANUP:
spec->recording = 0;
olpc_xo_update_mic_pins(codec);
break;
}
}
static int olpc_xo_dc_mode_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct conexant_spec *spec = codec->spec;
ucontrol->value.integer.value[0] = spec->dc_enable;
return 0;
}
static int olpc_xo_dc_mode_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct conexant_spec *spec = codec->spec;
int dc_enable = !!ucontrol->value.integer.value[0];
if (dc_enable == spec->dc_enable)
return 0;
spec->dc_enable = dc_enable;
olpc_xo_update_mic_pins(codec);
olpc_xo_update_mic_boost(codec);
return 1;
}
static int olpc_xo_dc_bias_enum_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct conexant_spec *spec = codec->spec;
ucontrol->value.enumerated.item[0] = spec->dc_input_bias;
return 0;
}
static int olpc_xo_dc_bias_enum_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
return snd_hda_input_mux_info(&olpc_xo_dc_bias, uinfo);
}
static int olpc_xo_dc_bias_enum_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct conexant_spec *spec = codec->spec;
const struct hda_input_mux *imux = &olpc_xo_dc_bias;
unsigned int idx;
idx = ucontrol->value.enumerated.item[0];
if (idx >= imux->num_items)
idx = imux->num_items - 1;
if (spec->dc_input_bias == idx)
return 0;
spec->dc_input_bias = idx;
if (spec->dc_enable)
olpc_xo_update_mic_pins(codec);
return 1;
}
static int olpc_xo_mic_boost_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct conexant_spec *spec = codec->spec;
int ret = snd_hda_mixer_amp_volume_put(kcontrol, ucontrol);
if (ret > 0 && spec->dc_enable)
olpc_xo_update_mic_boost(codec);
return ret;
}
static void cxt_fixup_olpc_xo(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
struct conexant_spec *spec = codec->spec;
int i;
if (action != HDA_FIXUP_ACT_PROBE)
return;
spec->gen.mic_autoswitch_hook = olpc_xo_automic;
spec->gen.pcm_capture_hook = olpc_xo_capture_hook;
spec->dc_mode_path = snd_hda_add_new_path(codec, 0x1e, 0x14, 0);
snd_hda_add_new_ctls(codec, olpc_xo_mixers);
snd_hda_codec_set_pin_target(codec, 0x1a, PIN_VREF50);
for (i = 0; i < spec->gen.kctls.used; i++) {
struct snd_kcontrol_new *kctl =
snd_array_elem(&spec->gen.kctls, i);
if (!strcmp(kctl->name, "Mic Boost Volume")) {
kctl->put = olpc_xo_mic_boost_put;
break;
}
}
}
static void cxt_fixup_cap_mix_amp(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
snd_hda_override_amp_caps(codec, 0x17, HDA_INPUT,
(0x14 << AC_AMPCAP_OFFSET_SHIFT) |
(0x14 << AC_AMPCAP_NUM_STEPS_SHIFT) |
(0x05 << AC_AMPCAP_STEP_SIZE_SHIFT) |
(1 << AC_AMPCAP_MUTE_SHIFT));
}
static void cxt_fixup_cap_mix_amp_5047(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
snd_hda_override_amp_caps(codec, 0x10, HDA_INPUT,
(0x17 << AC_AMPCAP_OFFSET_SHIFT) |
(0x17 << AC_AMPCAP_NUM_STEPS_SHIFT) |
(0x05 << AC_AMPCAP_STEP_SIZE_SHIFT) |
(1 << AC_AMPCAP_MUTE_SHIFT));
}
static void add_cx5051_fake_mutes(struct hda_codec *codec)
{
static hda_nid_t out_nids[] = {
0x10, 0x11, 0
};
hda_nid_t *p;
for (p = out_nids; *p; p++)
snd_hda_override_amp_caps(codec, *p, HDA_OUTPUT,
AC_AMPCAP_MIN_MUTE |
query_amp_caps(codec, *p, HDA_OUTPUT));
}
static int patch_conexant_auto(struct hda_codec *codec)
{
struct conexant_spec *spec;
int err;
codec_info(codec, "%s: BIOS auto-probing.\n", codec->chip_name);
spec = kzalloc(sizeof(*spec), GFP_KERNEL);
if (!spec)
return -ENOMEM;
snd_hda_gen_spec_init(&spec->gen);
codec->spec = spec;
cx_auto_parse_beep(codec);
cx_auto_parse_eapd(codec);
spec->gen.own_eapd_ctl = 1;
if (spec->dynamic_eapd)
spec->gen.vmaster_mute.hook = cx_auto_vmaster_hook;
switch (codec->vendor_id) {
case 0x14f15045:
codec->single_adc_amp = 1;
spec->gen.mixer_nid = 0x17;
spec->gen.add_stereo_mix_input = 1;
snd_hda_pick_fixup(codec, cxt5045_fixup_models,
cxt5045_fixups, cxt_fixups);
break;
case 0x14f15047:
codec->pin_amp_workaround = 1;
spec->gen.mixer_nid = 0x19;
spec->gen.add_stereo_mix_input = 1;
snd_hda_pick_fixup(codec, cxt5047_fixup_models,
cxt5047_fixups, cxt_fixups);
break;
case 0x14f15051:
add_cx5051_fake_mutes(codec);
codec->pin_amp_workaround = 1;
snd_hda_pick_fixup(codec, cxt5051_fixup_models,
cxt5051_fixups, cxt_fixups);
break;
default:
codec->pin_amp_workaround = 1;
snd_hda_pick_fixup(codec, cxt5066_fixup_models,
cxt5066_fixups, cxt_fixups);
break;
}
switch (codec->subsystem_id >> 16) {
case 0x103c:
spec->gen.vmaster_mute_enum = 1;
break;
}
snd_hda_apply_fixup(codec, HDA_FIXUP_ACT_PRE_PROBE);
err = snd_hda_parse_pin_defcfg(codec, &spec->gen.autocfg, NULL,
spec->parse_flags);
if (err < 0)
goto error;
err = snd_hda_gen_parse_auto_config(codec, &spec->gen.autocfg);
if (err < 0)
goto error;
codec->patch_ops = cx_auto_patch_ops;
if (!codec->bus->sync_write) {
codec_info(codec,
"Enable sync_write for stable communication\n");
codec->bus->sync_write = 1;
codec->bus->allow_bus_reset = 1;
}
snd_hda_apply_fixup(codec, HDA_FIXUP_ACT_PROBE);
return 0;
error:
cx_auto_free(codec);
return err;
}
static int __init patch_conexant_init(void)
{
return snd_hda_add_codec_preset(&conexant_list);
}
static void __exit patch_conexant_exit(void)
{
snd_hda_delete_codec_preset(&conexant_list);
}
