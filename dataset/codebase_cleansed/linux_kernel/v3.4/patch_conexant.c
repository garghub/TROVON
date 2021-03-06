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
if (spec->capture_prepare)
spec->capture_prepare(codec);
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
if (spec->capture_cleanup)
spec->capture_cleanup(codec);
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
if (spec->slave_dig_outs[0])
codec->slave_dig_outs = spec->slave_dig_outs;
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
snd_hda_codec_set_power_to_all(codec, fg, power_state, true);
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
snd_hda_detach_beep_device(codec);
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
err = __snd_hda_add_vmaster(codec, "Master Playback Switch",
NULL, slave_pfxs,
"Playback Switch", true,
&spec->vmaster_mute.sw_kctl);
if (err < 0)
return err;
}
if (spec->input_mux) {
err = snd_hda_add_new_ctls(codec, cxt_capture_mixers);
if (err < 0)
return err;
}
#ifdef CONFIG_SND_HDA_INPUT_BEEP
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
#endif
return 0;
}
static int conexant_suspend(struct hda_codec *codec, pm_message_t state)
{
snd_hda_shutup_pins(codec);
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
if (err >= 0 && spec->need_dac_fix)
spec->multiout.num_dacs = spec->multiout.max_channels / 2;
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
case CXT5045_LAPTOP_HP530:
codec->patch_ops.unsol_event = cxt5045_hp_unsol_event;
spec->input_mux = &cxt5045_capture_source_hp530;
spec->num_init_verbs = 2;
spec->init_verbs[1] = cxt5045_hp_sense_init_verbs;
spec->mixers[0] = cxt5045_mixers_hp530;
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
snd_hda_attach_beep_device(codec, spec->beep_amp);
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
snd_hda_codec_write(codec, 0x16, 0, AC_VERB_SET_PIN_WIDGET_CONTROL,
pinctl);
pinctl = (!spec->hp_present && spec->cur_eapd) ? PIN_OUT : 0;
snd_hda_codec_write(codec, 0x1a, 0, AC_VERB_SET_PIN_WIDGET_CONTROL,
pinctl);
if (spec->ideapad)
snd_hda_codec_write(codec, 0x1b, 0,
AC_VERB_SET_PIN_WIDGET_CONTROL,
pinctl);
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
snd_hda_attach_beep_device(codec, spec->beep_amp);
return 0;
}
static void cxt5066_update_speaker(struct hda_codec *codec)
{
struct conexant_spec *spec = codec->spec;
unsigned int pinctl;
snd_printdd("CXT5066: update speaker, hp_present=%d, cur_eapd=%d\n",
spec->hp_present, spec->cur_eapd);
pinctl = (hp_port_a_present(spec) && spec->cur_eapd) ? PIN_HP : 0;
snd_hda_codec_write(codec, 0x19, 0, AC_VERB_SET_PIN_WIDGET_CONTROL,
pinctl);
pinctl = spec->cur_eapd ? spec->port_d_mode : 0;
if (spec->dell_automute || spec->thinkpad) {
if (hp_port_a_present(spec))
pinctl = 0;
} else {
if (!hp_port_d_present(spec))
pinctl = 0;
}
snd_hda_codec_write(codec, 0x1c, 0, AC_VERB_SET_PIN_WIDGET_CONTROL,
pinctl);
pinctl = (!spec->hp_present && spec->cur_eapd) ? PIN_OUT : 0;
snd_hda_codec_write(codec, 0x1f, 0, AC_VERB_SET_PIN_WIDGET_CONTROL,
pinctl);
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
static int cxt5066_set_olpc_dc_bias(struct hda_codec *codec)
{
struct conexant_spec *spec = codec->spec;
return snd_hda_codec_write_cache(codec, 0x1a, 0,
AC_VERB_SET_PIN_WIDGET_CONTROL,
cxt5066_olpc_dc_bias.items[spec->dc_input_bias].index);
}
static void cxt5066_olpc_select_mic(struct hda_codec *codec)
{
struct conexant_spec *spec = codec->spec;
if (!spec->recording)
return;
if (spec->dc_enable) {
const struct hda_verb enable_dc_mode[] = {
{0x1b, AC_VERB_SET_PIN_WIDGET_CONTROL, 0},
{0x1e, AC_VERB_SET_PIN_WIDGET_CONTROL, PIN_IN},
{},
};
snd_hda_sequence_write(codec, enable_dc_mode);
cxt5066_set_olpc_dc_bias(codec);
return;
}
snd_hda_codec_write(codec, 0x1e, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0);
snd_hda_codec_write(codec, 0x1a, 0, AC_VERB_SET_PIN_WIDGET_CONTROL,
spec->ext_mic_present ? CXT5066_OLPC_EXT_MIC_BIAS : 0);
snd_hda_codec_write(codec, 0x1b, 0, AC_VERB_SET_PIN_WIDGET_CONTROL,
spec->ext_mic_present ? 0 : PIN_VREF80);
}
static void cxt5066_olpc_automic(struct hda_codec *codec)
{
struct conexant_spec *spec = codec->spec;
unsigned int present;
if (spec->dc_enable)
return;
present = snd_hda_codec_read(codec, 0x1a, 0,
AC_VERB_GET_PIN_SENSE, 0) & 0x80000000;
if (present)
snd_printdd("CXT5066: external microphone detected\n");
else
snd_printdd("CXT5066: external microphone absent\n");
snd_hda_codec_write(codec, 0x17, 0, AC_VERB_SET_CONNECT_SEL,
present ? 0 : 1);
spec->ext_mic_present = !!present;
cxt5066_olpc_select_mic(codec);
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
snd_printdd("CXT5066: external microphone detected\n");
snd_hda_sequence_write(codec, ext_mic_present);
} else {
snd_printdd("CXT5066: external microphone absent\n");
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
snd_printdd("CXT5066: external microphone detected\n");
snd_hda_sequence_write(codec, ext_mic_present);
} else {
snd_printdd("CXT5066: external microphone absent\n");
snd_hda_sequence_write(codec, ext_mic_absent);
}
}
static void cxt5066_asus_automic(struct hda_codec *codec)
{
unsigned int present;
present = snd_hda_jack_detect(codec, 0x1b);
snd_printdd("CXT5066: external microphone present=%d\n", present);
snd_hda_codec_write(codec, 0x17, 0, AC_VERB_SET_CONNECT_SEL,
present ? 1 : 0);
}
static void cxt5066_hp_laptop_automic(struct hda_codec *codec)
{
unsigned int present;
present = snd_hda_jack_detect(codec, 0x1b);
snd_printdd("CXT5066: external microphone present=%d\n", present);
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
snd_printdd("CXT5066: external microphone detected\n");
snd_hda_sequence_write(codec, ext_mic_present);
} else if (dock_present) {
snd_printdd("CXT5066: dock microphone detected\n");
snd_hda_sequence_write(codec, dock_mic_present);
} else {
snd_printdd("CXT5066: external microphone absent\n");
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
snd_printdd("CXT5066: hp automute portA=%x portD=%x present=%d\n",
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
static void cxt5066_olpc_unsol_event(struct hda_codec *codec, unsigned int res)
{
struct conexant_spec *spec = codec->spec;
snd_printdd("CXT5066: unsol event %x (%x)\n", res, res >> 26);
switch (res >> 26) {
case CONEXANT_HP_EVENT:
cxt5066_hp_automute(codec);
break;
case CONEXANT_MIC_EVENT:
if (!spec->dc_enable)
cxt5066_olpc_automic(codec);
break;
}
}
static void cxt5066_unsol_event(struct hda_codec *codec, unsigned int res)
{
snd_printdd("CXT5066: unsol event %x (%x)\n", res, res >> 26);
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
if (!spec->dc_enable)
cxt5066_set_mic_boost(codec);
return 1;
}
static void cxt5066_enable_dc(struct hda_codec *codec)
{
const struct hda_verb enable_dc_mode[] = {
{0x17, AC_VERB_SET_AMP_GAIN_MUTE, AMP_OUT_UNMUTE},
{0x17, AC_VERB_SET_CONNECT_SEL, 3},
{}
};
snd_hda_sequence_write(codec, enable_dc_mode);
cxt5066_olpc_select_mic(codec);
}
static void cxt5066_disable_dc(struct hda_codec *codec)
{
cxt5066_set_mic_boost(codec);
cxt5066_olpc_automic(codec);
}
static int cxt5066_olpc_dc_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct conexant_spec *spec = codec->spec;
ucontrol->value.integer.value[0] = spec->dc_enable;
return 0;
}
static int cxt5066_olpc_dc_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct conexant_spec *spec = codec->spec;
int dc_enable = !!ucontrol->value.integer.value[0];
if (dc_enable == spec->dc_enable)
return 0;
spec->dc_enable = dc_enable;
if (dc_enable)
cxt5066_enable_dc(codec);
else
cxt5066_disable_dc(codec);
return 1;
}
static int cxt5066_olpc_dc_bias_enum_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
return snd_hda_input_mux_info(&cxt5066_olpc_dc_bias, uinfo);
}
static int cxt5066_olpc_dc_bias_enum_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct conexant_spec *spec = codec->spec;
ucontrol->value.enumerated.item[0] = spec->dc_input_bias;
return 0;
}
static int cxt5066_olpc_dc_bias_enum_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct conexant_spec *spec = codec->spec;
const struct hda_input_mux *imux = &cxt5066_analog_mic_boost;
unsigned int idx;
idx = ucontrol->value.enumerated.item[0];
if (idx >= imux->num_items)
idx = imux->num_items - 1;
spec->dc_input_bias = idx;
if (spec->dc_enable)
cxt5066_set_olpc_dc_bias(codec);
return 1;
}
static void cxt5066_olpc_capture_prepare(struct hda_codec *codec)
{
struct conexant_spec *spec = codec->spec;
spec->recording = 1;
cxt5066_olpc_select_mic(codec);
}
static void cxt5066_olpc_capture_cleanup(struct hda_codec *codec)
{
struct conexant_spec *spec = codec->spec;
const struct hda_verb disable_mics[] = {
{0x1a, AC_VERB_SET_PIN_WIDGET_CONTROL, 0},
{0x1b, AC_VERB_SET_PIN_WIDGET_CONTROL, 0},
{0x1e, AC_VERB_SET_PIN_WIDGET_CONTROL, 0},
{},
};
snd_hda_sequence_write(codec, disable_mics);
spec->recording = 0;
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
if (spec->slave_dig_outs[0])
nid_loc++;
else
nid_loc = spec->slave_dig_outs;
}
}
static int cxt5066_init(struct hda_codec *codec)
{
snd_printdd("CXT5066: init\n");
conexant_init(codec);
if (codec->patch_ops.unsol_event) {
cxt5066_hp_automute(codec);
cxt5066_automic(codec);
}
cxt5066_set_mic_boost(codec);
return 0;
}
static int cxt5066_olpc_init(struct hda_codec *codec)
{
struct conexant_spec *spec = codec->spec;
snd_printdd("CXT5066: init\n");
conexant_init(codec);
cxt5066_hp_automute(codec);
if (!spec->dc_enable) {
cxt5066_set_mic_boost(codec);
cxt5066_olpc_automic(codec);
} else {
cxt5066_enable_dc(codec);
}
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
case CXT5066_OLPC_XO_1_5:
codec->patch_ops.init = cxt5066_olpc_init;
codec->patch_ops.unsol_event = cxt5066_olpc_unsol_event;
spec->init_verbs[0] = cxt5066_init_verbs_olpc;
spec->mixers[spec->num_mixers++] = cxt5066_mixer_master_olpc;
spec->mixers[spec->num_mixers++] = cxt5066_mixer_olpc_dc;
spec->mixers[spec->num_mixers++] = cxt5066_mixers;
spec->port_d_mode = 0;
spec->mic_boost = 3;
spec->multiout.dig_out_nid = 0;
spec->input_mux = NULL;
spec->capture_prepare = cxt5066_olpc_capture_prepare;
spec->capture_cleanup = cxt5066_olpc_capture_cleanup;
break;
case CXT5066_DELL_VOSTRO:
codec->patch_ops.init = cxt5066_init;
codec->patch_ops.unsol_event = cxt5066_unsol_event;
spec->init_verbs[0] = cxt5066_init_verbs_vostro;
spec->mixers[spec->num_mixers++] = cxt5066_mixer_master_olpc;
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
snd_hda_attach_beep_device(codec, spec->beep_amp);
return 0;
}
static int cx_auto_capture_pcm_prepare(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
unsigned int stream_tag,
unsigned int format,
struct snd_pcm_substream *substream)
{
struct conexant_spec *spec = codec->spec;
hda_nid_t adc = spec->imux_info[spec->cur_mux[0]].adc;
if (spec->adc_switching) {
spec->cur_adc = adc;
spec->cur_adc_stream_tag = stream_tag;
spec->cur_adc_format = format;
}
snd_hda_codec_setup_stream(codec, adc, stream_tag, 0, format);
return 0;
}
static int cx_auto_capture_pcm_cleanup(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
struct snd_pcm_substream *substream)
{
struct conexant_spec *spec = codec->spec;
snd_hda_codec_cleanup_stream(codec, spec->cur_adc);
spec->cur_adc = 0;
return 0;
}
static hda_nid_t get_unassigned_dac(struct hda_codec *codec, hda_nid_t pin,
hda_nid_t *dacs, int *num_dacs)
{
int i, nums = *num_dacs;
hda_nid_t ret = 0;
for (i = 0; i < nums; i++) {
if (get_connection_index(codec, pin, dacs[i]) >= 0) {
ret = dacs[i];
break;
}
}
if (!ret)
return 0;
if (--nums > 0)
memmove(dacs, dacs + 1, nums * sizeof(hda_nid_t));
*num_dacs = nums;
return ret;
}
static int fill_cx_auto_dacs(struct hda_codec *codec, hda_nid_t *dacs)
{
hda_nid_t nid, end_nid;
int nums = 0;
end_nid = codec->start_nid + codec->num_nodes;
for (nid = codec->start_nid; nid < end_nid; nid++) {
unsigned int wcaps = get_wcaps(codec, nid);
unsigned int type = get_wcaps_type(wcaps);
if (type == AC_WID_AUD_OUT && !(wcaps & AC_WCAP_DIGITAL)) {
dacs[nums++] = nid;
if (nums >= MAX_AUTO_DACS)
break;
}
}
return nums;
}
static int fill_dacs_for_pins(struct hda_codec *codec, hda_nid_t *pins,
int num_pins, hda_nid_t *dacs, int *rest,
struct pin_dac_pair *filled, int nums,
int type)
{
int i, start = nums;
for (i = 0; i < num_pins; i++, nums++) {
filled[nums].pin = pins[i];
filled[nums].type = type;
filled[nums].dac = get_unassigned_dac(codec, pins[i], dacs, rest);
if (filled[nums].dac)
continue;
if (filled[start].dac && get_connection_index(codec, pins[i], filled[start].dac) >= 0) {
filled[nums].dac = filled[start].dac | DAC_SLAVE_FLAG;
continue;
}
if (filled[0].dac && get_connection_index(codec, pins[i], filled[0].dac) >= 0) {
filled[nums].dac = filled[0].dac | DAC_SLAVE_FLAG;
continue;
}
snd_printdd("Failed to find a DAC for pin 0x%x", pins[i]);
}
return nums;
}
static void cx_auto_parse_output(struct hda_codec *codec)
{
struct conexant_spec *spec = codec->spec;
struct auto_pin_cfg *cfg = &spec->autocfg;
hda_nid_t dacs[MAX_AUTO_DACS];
int i, j, nums, rest;
rest = fill_cx_auto_dacs(codec, dacs);
nums = fill_dacs_for_pins(codec, cfg->line_out_pins, cfg->line_outs,
dacs, &rest, spec->dac_info, 0,
AUTO_PIN_LINE_OUT);
nums = fill_dacs_for_pins(codec, cfg->hp_pins, cfg->hp_outs,
dacs, &rest, spec->dac_info, nums,
AUTO_PIN_HP_OUT);
nums = fill_dacs_for_pins(codec, cfg->speaker_pins, cfg->speaker_outs,
dacs, &rest, spec->dac_info, nums,
AUTO_PIN_SPEAKER_OUT);
spec->dac_info_filled = nums;
for (i = 0; i < nums; i++) {
hda_nid_t dac = spec->dac_info[i].dac;
if (!dac || (dac & DAC_SLAVE_FLAG))
continue;
switch (spec->dac_info[i].type) {
case AUTO_PIN_LINE_OUT:
spec->private_dac_nids[spec->multiout.num_dacs] = dac;
spec->multiout.num_dacs++;
break;
case AUTO_PIN_HP_OUT:
case AUTO_PIN_SPEAKER_OUT:
if (!spec->multiout.hp_nid) {
spec->multiout.hp_nid = dac;
break;
}
for (j = 0; j < ARRAY_SIZE(spec->multiout.extra_out_nid); j++)
if (!spec->multiout.extra_out_nid[j]) {
spec->multiout.extra_out_nid[j] = dac;
break;
}
break;
}
}
spec->multiout.dac_nids = spec->private_dac_nids;
spec->multiout.max_channels = spec->multiout.num_dacs * 2;
for (i = 0; i < cfg->hp_outs; i++) {
if (is_jack_detectable(codec, cfg->hp_pins[i])) {
spec->auto_mute = 1;
break;
}
}
if (spec->auto_mute &&
cfg->line_out_pins[0] &&
cfg->line_out_type != AUTO_PIN_SPEAKER_OUT &&
cfg->line_out_pins[0] != cfg->hp_pins[0] &&
cfg->line_out_pins[0] != cfg->speaker_pins[0]) {
for (i = 0; i < cfg->line_outs; i++) {
if (is_jack_detectable(codec, cfg->line_out_pins[i])) {
spec->detect_line = 1;
break;
}
}
spec->automute_lines = spec->detect_line;
}
spec->vmaster_nid = spec->private_dac_nids[0];
}
static void do_automute(struct hda_codec *codec, int num_pins,
hda_nid_t *pins, bool on)
{
struct conexant_spec *spec = codec->spec;
int i;
for (i = 0; i < num_pins; i++)
snd_hda_codec_write(codec, pins[i], 0,
AC_VERB_SET_PIN_WIDGET_CONTROL,
on ? PIN_OUT : 0);
if (spec->pin_eapd_ctrls)
cx_auto_turn_eapd(codec, num_pins, pins, on);
}
static int detect_jacks(struct hda_codec *codec, int num_pins, hda_nid_t *pins)
{
int i, present = 0;
for (i = 0; i < num_pins; i++) {
hda_nid_t nid = pins[i];
if (!nid || !is_jack_detectable(codec, nid))
break;
present |= snd_hda_jack_detect(codec, nid);
}
return present;
}
static void cx_auto_update_speakers(struct hda_codec *codec)
{
struct conexant_spec *spec = codec->spec;
struct auto_pin_cfg *cfg = &spec->autocfg;
int on = 1;
if (spec->pin_eapd_ctrls) {
if (spec->auto_mute)
on = spec->hp_present;
cx_auto_turn_eapd(codec, cfg->hp_outs, cfg->hp_pins, on);
}
if (spec->auto_mute)
on = !(spec->hp_present ||
(spec->detect_line && spec->line_present));
do_automute(codec, cfg->speaker_outs, cfg->speaker_pins, on);
if (cfg->line_out_pins[0] == cfg->hp_pins[0] ||
cfg->line_out_pins[0] == cfg->speaker_pins[0])
return;
if (spec->auto_mute) {
if (cfg->line_out_type == AUTO_PIN_SPEAKER_OUT ||
spec->automute_lines)
on = !spec->hp_present;
else
on = 1;
}
do_automute(codec, cfg->line_outs, cfg->line_out_pins, on);
}
static void cx_auto_hp_automute(struct hda_codec *codec)
{
struct conexant_spec *spec = codec->spec;
struct auto_pin_cfg *cfg = &spec->autocfg;
if (!spec->auto_mute)
return;
spec->hp_present = detect_jacks(codec, cfg->hp_outs, cfg->hp_pins);
cx_auto_update_speakers(codec);
}
static void cx_auto_line_automute(struct hda_codec *codec)
{
struct conexant_spec *spec = codec->spec;
struct auto_pin_cfg *cfg = &spec->autocfg;
if (!spec->auto_mute || !spec->detect_line)
return;
spec->line_present = detect_jacks(codec, cfg->line_outs,
cfg->line_out_pins);
cx_auto_update_speakers(codec);
}
static int cx_automute_mode_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct conexant_spec *spec = codec->spec;
static const char * const texts2[] = {
"Disabled", "Enabled"
};
static const char * const texts3[] = {
"Disabled", "Speaker Only", "Line Out+Speaker"
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
static int cx_automute_mode_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct conexant_spec *spec = codec->spec;
unsigned int val;
if (!spec->auto_mute)
val = 0;
else if (!spec->automute_lines)
val = 1;
else
val = 2;
ucontrol->value.enumerated.item[0] = val;
return 0;
}
static int cx_automute_mode_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct conexant_spec *spec = codec->spec;
switch (ucontrol->value.enumerated.item[0]) {
case 0:
if (!spec->auto_mute)
return 0;
spec->auto_mute = 0;
break;
case 1:
if (spec->auto_mute && !spec->automute_lines)
return 0;
spec->auto_mute = 1;
spec->automute_lines = 0;
break;
case 2:
if (!spec->automute_hp_lo)
return -EINVAL;
if (spec->auto_mute && spec->automute_lines)
return 0;
spec->auto_mute = 1;
spec->automute_lines = 1;
break;
default:
return -EINVAL;
}
cx_auto_update_speakers(codec);
return 1;
}
static int cx_auto_mux_enum_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct conexant_spec *spec = codec->spec;
return snd_hda_input_mux_info(&spec->private_imux, uinfo);
}
static int cx_auto_mux_enum_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct conexant_spec *spec = codec->spec;
ucontrol->value.enumerated.item[0] = spec->cur_mux[0];
return 0;
}
static int __select_input_connection(struct hda_codec *codec, hda_nid_t mux,
hda_nid_t pin, hda_nid_t *srcp,
bool do_select, int depth)
{
hda_nid_t conn[HDA_MAX_NUM_INPUTS];
int i, nums;
switch (get_wcaps_type(get_wcaps(codec, mux))) {
case AC_WID_AUD_IN:
case AC_WID_AUD_SEL:
case AC_WID_AUD_MIX:
break;
default:
return -1;
}
nums = snd_hda_get_connections(codec, mux, conn, ARRAY_SIZE(conn));
for (i = 0; i < nums; i++)
if (conn[i] == pin) {
if (do_select)
snd_hda_codec_write(codec, mux, 0,
AC_VERB_SET_CONNECT_SEL, i);
if (srcp)
*srcp = mux;
return i;
}
depth++;
if (depth == 2)
return -1;
for (i = 0; i < nums; i++) {
int ret = __select_input_connection(codec, conn[i], pin, srcp,
do_select, depth);
if (ret >= 0) {
if (do_select)
snd_hda_codec_write(codec, mux, 0,
AC_VERB_SET_CONNECT_SEL, i);
return i;
}
}
return -1;
}
static void select_input_connection(struct hda_codec *codec, hda_nid_t mux,
hda_nid_t pin)
{
__select_input_connection(codec, mux, pin, NULL, true, 0);
}
static int get_input_connection(struct hda_codec *codec, hda_nid_t mux,
hda_nid_t pin)
{
return __select_input_connection(codec, mux, pin, NULL, false, 0);
}
static int cx_auto_mux_enum_update(struct hda_codec *codec,
const struct hda_input_mux *imux,
unsigned int idx)
{
struct conexant_spec *spec = codec->spec;
hda_nid_t adc;
int changed = 1;
if (!imux->num_items)
return 0;
if (idx >= imux->num_items)
idx = imux->num_items - 1;
if (spec->cur_mux[0] == idx)
changed = 0;
adc = spec->imux_info[idx].adc;
select_input_connection(codec, spec->imux_info[idx].adc,
spec->imux_info[idx].pin);
if (spec->cur_adc && spec->cur_adc != adc) {
__snd_hda_codec_cleanup_stream(codec, spec->cur_adc, 1);
spec->cur_adc = adc;
snd_hda_codec_setup_stream(codec, adc,
spec->cur_adc_stream_tag, 0,
spec->cur_adc_format);
}
spec->cur_mux[0] = idx;
return changed;
}
static int cx_auto_mux_enum_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct conexant_spec *spec = codec->spec;
return cx_auto_mux_enum_update(codec, &spec->private_imux,
ucontrol->value.enumerated.item[0]);
}
static bool select_automic(struct hda_codec *codec, int idx, bool detect)
{
struct conexant_spec *spec = codec->spec;
if (idx < 0)
return false;
if (detect && !snd_hda_jack_detect(codec, spec->imux_info[idx].pin))
return false;
cx_auto_mux_enum_update(codec, &spec->private_imux, idx);
return true;
}
static void cx_auto_automic(struct hda_codec *codec)
{
struct conexant_spec *spec = codec->spec;
if (!spec->auto_mic)
return;
if (!select_automic(codec, spec->auto_mic_ext, true))
if (!select_automic(codec, spec->auto_mic_dock, true))
select_automic(codec, spec->auto_mic_int, false);
}
static void cx_auto_unsol_event(struct hda_codec *codec, unsigned int res)
{
switch (snd_hda_jack_get_action(codec, res >> 26)) {
case CONEXANT_HP_EVENT:
cx_auto_hp_automute(codec);
break;
case CONEXANT_LINE_EVENT:
cx_auto_line_automute(codec);
break;
case CONEXANT_MIC_EVENT:
cx_auto_automic(codec);
break;
}
snd_hda_jack_report_sync(codec);
}
static void cx_auto_check_auto_mic(struct hda_codec *codec)
{
struct conexant_spec *spec = codec->spec;
int pset[INPUT_PIN_ATTR_NORMAL + 1];
int i;
for (i = 0; i < ARRAY_SIZE(pset); i++)
pset[i] = -1;
for (i = 0; i < spec->private_imux.num_items; i++) {
hda_nid_t pin = spec->imux_info[i].pin;
unsigned int def_conf = snd_hda_codec_get_pincfg(codec, pin);
int type, attr;
attr = snd_hda_get_input_pin_attr(def_conf);
if (attr == INPUT_PIN_ATTR_UNUSED)
return;
if (attr > INPUT_PIN_ATTR_NORMAL)
attr = INPUT_PIN_ATTR_NORMAL;
if (attr != INPUT_PIN_ATTR_INT &&
!is_jack_detectable(codec, pin))
return;
type = get_defcfg_device(def_conf);
if (type != AC_JACK_MIC_IN &&
(attr != INPUT_PIN_ATTR_DOCK || type != AC_JACK_LINE_IN))
return;
if (pset[attr] >= 0)
return;
pset[attr] = i;
}
if (pset[INPUT_PIN_ATTR_INT] < 0 ||
(pset[INPUT_PIN_ATTR_NORMAL] < 0 && pset[INPUT_PIN_ATTR_DOCK]))
return;
spec->auto_mic = 1;
spec->auto_mic_ext = pset[INPUT_PIN_ATTR_NORMAL];
spec->auto_mic_dock = pset[INPUT_PIN_ATTR_DOCK];
spec->auto_mic_int = pset[INPUT_PIN_ATTR_INT];
}
static void cx_auto_parse_input(struct hda_codec *codec)
{
struct conexant_spec *spec = codec->spec;
struct auto_pin_cfg *cfg = &spec->autocfg;
struct hda_input_mux *imux;
int i, j;
imux = &spec->private_imux;
for (i = 0; i < cfg->num_inputs; i++) {
for (j = 0; j < spec->num_adc_nids; j++) {
hda_nid_t adc = spec->adc_nids[j];
int idx = get_input_connection(codec, adc,
cfg->inputs[i].pin);
if (idx >= 0) {
const char *label;
label = hda_get_autocfg_input_label(codec, cfg, i);
spec->imux_info[imux->num_items].index = i;
spec->imux_info[imux->num_items].boost = 0;
spec->imux_info[imux->num_items].adc = adc;
spec->imux_info[imux->num_items].pin =
cfg->inputs[i].pin;
snd_hda_add_imux_item(imux, label, idx, NULL);
break;
}
}
}
if (imux->num_items >= 2 && cfg->num_inputs == imux->num_items)
cx_auto_check_auto_mic(codec);
if (imux->num_items > 1) {
for (i = 1; i < imux->num_items; i++) {
if (spec->imux_info[i].adc != spec->imux_info[0].adc) {
spec->adc_switching = 1;
break;
}
}
}
}
static hda_nid_t cx_auto_get_dig_in(struct hda_codec *codec, hda_nid_t pin)
{
hda_nid_t nid, end_nid;
end_nid = codec->start_nid + codec->num_nodes;
for (nid = codec->start_nid; nid < end_nid; nid++) {
unsigned int wcaps = get_wcaps(codec, nid);
unsigned int type = get_wcaps_type(wcaps);
if (type == AC_WID_AUD_IN && (wcaps & AC_WCAP_DIGITAL)) {
if (get_connection_index(codec, nid, pin) >= 0)
return nid;
}
}
return 0;
}
static void cx_auto_parse_digital(struct hda_codec *codec)
{
struct conexant_spec *spec = codec->spec;
struct auto_pin_cfg *cfg = &spec->autocfg;
hda_nid_t nid;
if (cfg->dig_outs &&
snd_hda_get_connections(codec, cfg->dig_out_pins[0], &nid, 1) == 1)
spec->multiout.dig_out_nid = nid;
if (cfg->dig_in_pin)
spec->dig_in_nid = cx_auto_get_dig_in(codec, cfg->dig_in_pin);
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
spec->pin_eapd_ctrls = spec->num_eapds > 2;
}
static int cx_auto_parse_auto_config(struct hda_codec *codec)
{
struct conexant_spec *spec = codec->spec;
int err;
err = snd_hda_parse_pin_def_config(codec, &spec->autocfg, NULL);
if (err < 0)
return err;
cx_auto_parse_output(codec);
cx_auto_parse_input(codec);
cx_auto_parse_digital(codec);
cx_auto_parse_beep(codec);
cx_auto_parse_eapd(codec);
return 0;
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
static void select_connection(struct hda_codec *codec, hda_nid_t pin,
hda_nid_t src)
{
int idx = get_connection_index(codec, pin, src);
if (idx >= 0)
snd_hda_codec_write(codec, pin, 0,
AC_VERB_SET_CONNECT_SEL, idx);
}
static void mute_outputs(struct hda_codec *codec, int num_nids,
const hda_nid_t *nids)
{
int i, val;
for (i = 0; i < num_nids; i++) {
hda_nid_t nid = nids[i];
if (!(get_wcaps(codec, nid) & AC_WCAP_OUT_AMP))
continue;
if (query_amp_caps(codec, nid, HDA_OUTPUT) & AC_AMPCAP_MUTE)
val = AMP_OUT_MUTE;
else
val = AMP_OUT_ZERO;
snd_hda_codec_write(codec, nid, 0,
AC_VERB_SET_AMP_GAIN_MUTE, val);
}
}
static void enable_unsol_pins(struct hda_codec *codec, int num_pins,
hda_nid_t *pins, unsigned int action)
{
int i;
for (i = 0; i < num_pins; i++)
snd_hda_jack_detect_enable(codec, pins[i], action);
}
static bool found_in_nid_list(hda_nid_t nid, const hda_nid_t *list, int nums)
{
int i;
for (i = 0; i < nums; i++)
if (list[i] == nid)
return true;
return false;
}
static bool found_in_autocfg(struct auto_pin_cfg *cfg, hda_nid_t nid)
{
int i;
if (found_in_nid_list(nid, cfg->line_out_pins, cfg->line_outs) ||
found_in_nid_list(nid, cfg->hp_pins, cfg->hp_outs) ||
found_in_nid_list(nid, cfg->speaker_pins, cfg->speaker_outs) ||
found_in_nid_list(nid, cfg->dig_out_pins, cfg->dig_outs))
return true;
for (i = 0; i < cfg->num_inputs; i++)
if (cfg->inputs[i].pin == nid)
return true;
if (cfg->dig_in_pin == nid)
return true;
return false;
}
static void clear_unsol_on_unused_pins(struct hda_codec *codec)
{
struct conexant_spec *spec = codec->spec;
struct auto_pin_cfg *cfg = &spec->autocfg;
int i;
for (i = 0; i < codec->init_pins.used; i++) {
struct hda_pincfg *pin = snd_array_elem(&codec->init_pins, i);
if (!found_in_autocfg(cfg, pin->nid))
snd_hda_codec_write(codec, pin->nid, 0,
AC_VERB_SET_UNSOLICITED_ENABLE, 0);
}
}
static void cx_auto_vmaster_hook(void *private_data, int enabled)
{
struct hda_codec *codec = private_data;
struct conexant_spec *spec = codec->spec;
if (enabled && spec->pin_eapd_ctrls) {
cx_auto_update_speakers(codec);
return;
}
cx_auto_turn_eapd(codec, spec->num_eapds, spec->eapds, enabled);
}
static void cx_auto_init_output(struct hda_codec *codec)
{
struct conexant_spec *spec = codec->spec;
struct auto_pin_cfg *cfg = &spec->autocfg;
hda_nid_t nid;
int i;
mute_outputs(codec, spec->multiout.num_dacs, spec->multiout.dac_nids);
for (i = 0; i < cfg->hp_outs; i++) {
unsigned int val = PIN_OUT;
if (snd_hda_query_pin_caps(codec, cfg->hp_pins[i]) &
AC_PINCAP_HP_DRV)
val |= AC_PINCTL_HP_EN;
snd_hda_codec_write(codec, cfg->hp_pins[i], 0,
AC_VERB_SET_PIN_WIDGET_CONTROL, val);
}
mute_outputs(codec, cfg->hp_outs, cfg->hp_pins);
mute_outputs(codec, cfg->line_outs, cfg->line_out_pins);
mute_outputs(codec, cfg->speaker_outs, cfg->speaker_pins);
for (i = 0; i < spec->dac_info_filled; i++) {
nid = spec->dac_info[i].dac;
if (!nid)
nid = spec->multiout.dac_nids[0];
else if (nid & DAC_SLAVE_FLAG)
nid &= ~DAC_SLAVE_FLAG;
select_connection(codec, spec->dac_info[i].pin, nid);
}
if (spec->auto_mute) {
enable_unsol_pins(codec, cfg->hp_outs, cfg->hp_pins,
CONEXANT_HP_EVENT);
spec->hp_present = detect_jacks(codec, cfg->hp_outs,
cfg->hp_pins);
if (spec->detect_line) {
enable_unsol_pins(codec, cfg->line_outs,
cfg->line_out_pins,
CONEXANT_LINE_EVENT);
spec->line_present =
detect_jacks(codec, cfg->line_outs,
cfg->line_out_pins);
}
}
cx_auto_update_speakers(codec);
if (!spec->pin_eapd_ctrls)
cx_auto_turn_eapd(codec, spec->num_eapds, spec->eapds, true);
clear_unsol_on_unused_pins(codec);
}
static void cx_auto_init_input(struct hda_codec *codec)
{
struct conexant_spec *spec = codec->spec;
struct auto_pin_cfg *cfg = &spec->autocfg;
int i, val;
for (i = 0; i < spec->num_adc_nids; i++) {
hda_nid_t nid = spec->adc_nids[i];
if (!(get_wcaps(codec, nid) & AC_WCAP_IN_AMP))
continue;
if (query_amp_caps(codec, nid, HDA_INPUT) & AC_AMPCAP_MUTE)
val = AMP_IN_MUTE(0);
else
val = AMP_IN_UNMUTE(0);
snd_hda_codec_write(codec, nid, 0, AC_VERB_SET_AMP_GAIN_MUTE,
val);
}
for (i = 0; i < cfg->num_inputs; i++) {
unsigned int type;
if (cfg->inputs[i].type == AUTO_PIN_MIC)
type = PIN_VREF80;
else
type = PIN_IN;
snd_hda_codec_write(codec, cfg->inputs[i].pin, 0,
AC_VERB_SET_PIN_WIDGET_CONTROL, type);
}
if (spec->auto_mic) {
if (spec->auto_mic_ext >= 0) {
snd_hda_jack_detect_enable(codec,
cfg->inputs[spec->auto_mic_ext].pin,
CONEXANT_MIC_EVENT);
}
if (spec->auto_mic_dock >= 0) {
snd_hda_jack_detect_enable(codec,
cfg->inputs[spec->auto_mic_dock].pin,
CONEXANT_MIC_EVENT);
}
cx_auto_automic(codec);
} else {
select_input_connection(codec, spec->imux_info[0].adc,
spec->imux_info[0].pin);
}
}
static void cx_auto_init_digital(struct hda_codec *codec)
{
struct conexant_spec *spec = codec->spec;
struct auto_pin_cfg *cfg = &spec->autocfg;
if (spec->multiout.dig_out_nid)
snd_hda_codec_write(codec, cfg->dig_out_pins[0], 0,
AC_VERB_SET_PIN_WIDGET_CONTROL, PIN_OUT);
if (spec->dig_in_nid)
snd_hda_codec_write(codec, cfg->dig_in_pin, 0,
AC_VERB_SET_PIN_WIDGET_CONTROL, PIN_IN);
}
static int cx_auto_init(struct hda_codec *codec)
{
struct conexant_spec *spec = codec->spec;
cx_auto_init_output(codec);
cx_auto_init_input(codec);
cx_auto_init_digital(codec);
snd_hda_jack_report_sync(codec);
snd_hda_sync_vmaster_hook(&spec->vmaster_mute);
return 0;
}
static int cx_auto_add_volume_idx(struct hda_codec *codec, const char *basename,
const char *dir, int cidx,
hda_nid_t nid, int hda_dir, int amp_idx)
{
static char name[32];
static struct snd_kcontrol_new knew[] = {
HDA_CODEC_VOLUME(name, 0, 0, 0),
HDA_CODEC_MUTE(name, 0, 0, 0),
};
static const char * const sfx[2] = { "Volume", "Switch" };
int i, err;
for (i = 0; i < 2; i++) {
struct snd_kcontrol *kctl;
knew[i].private_value = HDA_COMPOSE_AMP_VAL(nid, 3, amp_idx,
hda_dir);
knew[i].subdevice = HDA_SUBDEV_AMP_FLAG;
knew[i].index = cidx;
snprintf(name, sizeof(name), "%s%s %s", basename, dir, sfx[i]);
kctl = snd_ctl_new1(&knew[i], codec);
if (!kctl)
return -ENOMEM;
err = snd_hda_ctl_add(codec, nid, kctl);
if (err < 0)
return err;
if (!(query_amp_caps(codec, nid, hda_dir) &
(AC_AMPCAP_MUTE | AC_AMPCAP_MIN_MUTE)))
break;
}
return 0;
}
static int try_add_pb_volume(struct hda_codec *codec, hda_nid_t dac,
hda_nid_t pin, const char *name, int idx)
{
unsigned int caps;
if (dac && !(dac & DAC_SLAVE_FLAG)) {
caps = query_amp_caps(codec, dac, HDA_OUTPUT);
if (caps & AC_AMPCAP_NUM_STEPS)
return cx_auto_add_pb_volume(codec, dac, name, idx);
}
caps = query_amp_caps(codec, pin, HDA_OUTPUT);
if (caps & AC_AMPCAP_NUM_STEPS)
return cx_auto_add_pb_volume(codec, pin, name, idx);
return 0;
}
static int cx_auto_build_output_controls(struct hda_codec *codec)
{
struct conexant_spec *spec = codec->spec;
int i, err;
int num_line = 0, num_hp = 0, num_spk = 0;
static const char * const texts[3] = { "Front", "Surround", "CLFE" };
if (spec->dac_info_filled == 1)
return try_add_pb_volume(codec, spec->dac_info[0].dac,
spec->dac_info[0].pin,
"Master", 0);
for (i = 0; i < spec->dac_info_filled; i++) {
const char *label;
int idx, type;
hda_nid_t dac = spec->dac_info[i].dac;
type = spec->dac_info[i].type;
if (type == AUTO_PIN_LINE_OUT)
type = spec->autocfg.line_out_type;
switch (type) {
case AUTO_PIN_LINE_OUT:
default:
label = texts[num_line++];
idx = 0;
break;
case AUTO_PIN_HP_OUT:
label = "Headphone";
idx = num_hp++;
break;
case AUTO_PIN_SPEAKER_OUT:
label = "Speaker";
idx = num_spk++;
break;
}
err = try_add_pb_volume(codec, dac,
spec->dac_info[i].pin,
label, idx);
if (err < 0)
return err;
}
if (spec->auto_mute) {
err = snd_hda_add_new_ctls(codec, cx_automute_mode_enum);
if (err < 0)
return err;
}
return 0;
}
static int cx_auto_add_capture_volume(struct hda_codec *codec, hda_nid_t nid,
const char *label, const char *pfx,
int cidx)
{
struct conexant_spec *spec = codec->spec;
int i;
for (i = 0; i < spec->num_adc_nids; i++) {
hda_nid_t adc_nid = spec->adc_nids[i];
int idx = get_input_connection(codec, adc_nid, nid);
if (idx < 0)
continue;
if (codec->single_adc_amp)
idx = 0;
return cx_auto_add_volume_idx(codec, label, pfx,
cidx, adc_nid, HDA_INPUT, idx);
}
return 0;
}
static int cx_auto_add_boost_volume(struct hda_codec *codec, int idx,
const char *label, int cidx)
{
struct conexant_spec *spec = codec->spec;
hda_nid_t mux, nid;
int i, con;
nid = spec->imux_info[idx].pin;
if (get_wcaps(codec, nid) & AC_WCAP_IN_AMP)
return cx_auto_add_volume(codec, label, " Boost", cidx,
nid, HDA_INPUT);
con = __select_input_connection(codec, spec->imux_info[idx].adc, nid,
&mux, false, 0);
if (con < 0)
return 0;
for (i = 0; i < idx; i++) {
if (spec->imux_info[i].boost == mux)
return 0;
}
if (get_wcaps(codec, mux) & AC_WCAP_OUT_AMP) {
spec->imux_info[idx].boost = mux;
return cx_auto_add_volume(codec, label, " Boost", 0,
mux, HDA_OUTPUT);
}
return 0;
}
static int cx_auto_build_input_controls(struct hda_codec *codec)
{
struct conexant_spec *spec = codec->spec;
struct hda_input_mux *imux = &spec->private_imux;
const char *prev_label;
int input_conn[HDA_MAX_NUM_INPUTS];
int i, j, err, cidx;
int multi_connection;
if (!imux->num_items)
return 0;
multi_connection = 0;
for (i = 0; i < imux->num_items; i++) {
cidx = get_input_connection(codec, spec->imux_info[i].adc,
spec->imux_info[i].pin);
if (cidx < 0)
continue;
input_conn[i] = spec->imux_info[i].adc;
if (!codec->single_adc_amp)
input_conn[i] |= cidx << 8;
if (i > 0 && input_conn[i] != input_conn[0])
multi_connection = 1;
}
prev_label = NULL;
cidx = 0;
for (i = 0; i < imux->num_items; i++) {
hda_nid_t nid = spec->imux_info[i].pin;
const char *label;
label = hda_get_autocfg_input_label(codec, &spec->autocfg,
spec->imux_info[i].index);
if (label == prev_label)
cidx++;
else
cidx = 0;
prev_label = label;
err = cx_auto_add_boost_volume(codec, i, label, cidx);
if (err < 0)
return err;
if (!multi_connection) {
if (i > 0)
continue;
err = cx_auto_add_capture_volume(codec, nid,
"Capture", "", cidx);
} else {
bool dup_found = false;
for (j = 0; j < i; j++) {
if (input_conn[j] == input_conn[i]) {
dup_found = true;
break;
}
}
if (dup_found)
continue;
err = cx_auto_add_capture_volume(codec, nid,
label, " Capture", cidx);
}
if (err < 0)
return err;
}
if (spec->private_imux.num_items > 1 && !spec->auto_mic) {
err = snd_hda_add_new_ctls(codec, cx_auto_capture_mixers);
if (err < 0)
return err;
}
return 0;
}
static int cx_auto_build_controls(struct hda_codec *codec)
{
struct conexant_spec *spec = codec->spec;
int err;
err = cx_auto_build_output_controls(codec);
if (err < 0)
return err;
err = cx_auto_build_input_controls(codec);
if (err < 0)
return err;
err = conexant_build_controls(codec);
if (err < 0)
return err;
err = snd_hda_jack_add_kctls(codec, &spec->autocfg);
if (err < 0)
return err;
if (spec->vmaster_mute.sw_kctl) {
spec->vmaster_mute.hook = cx_auto_vmaster_hook;
err = snd_hda_add_vmaster_hook(codec, &spec->vmaster_mute,
spec->vmaster_mute_led);
if (err < 0)
return err;
}
return 0;
}
static int cx_auto_search_adcs(struct hda_codec *codec)
{
struct conexant_spec *spec = codec->spec;
hda_nid_t nid, end_nid;
end_nid = codec->start_nid + codec->num_nodes;
for (nid = codec->start_nid; nid < end_nid; nid++) {
unsigned int caps = get_wcaps(codec, nid);
if (get_wcaps_type(caps) != AC_WID_AUD_IN)
continue;
if (caps & AC_WCAP_DIGITAL)
continue;
if (snd_BUG_ON(spec->num_adc_nids >=
ARRAY_SIZE(spec->private_adc_nids)))
break;
spec->private_adc_nids[spec->num_adc_nids++] = nid;
}
spec->adc_nids = spec->private_adc_nids;
return 0;
}
static void apply_pincfg(struct hda_codec *codec, const struct cxt_pincfg *cfg)
{
for (; cfg->nid; cfg++)
snd_hda_codec_set_pincfg(codec, cfg->nid, cfg->val);
}
static void apply_pin_fixup(struct hda_codec *codec,
const struct snd_pci_quirk *quirk,
const struct cxt_pincfg **table)
{
quirk = snd_pci_quirk_lookup(codec->bus->pci, quirk);
if (quirk) {
snd_printdd(KERN_INFO "hda_codec: applying pincfg for %s\n",
quirk->name);
apply_pincfg(codec, table[quirk->value]);
}
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
printk(KERN_INFO "hda_codec: %s: BIOS auto-probing.\n",
codec->chip_name);
spec = kzalloc(sizeof(*spec), GFP_KERNEL);
if (!spec)
return -ENOMEM;
codec->spec = spec;
switch (codec->vendor_id) {
case 0x14f15045:
codec->single_adc_amp = 1;
break;
case 0x14f15051:
add_cx5051_fake_mutes(codec);
codec->pin_amp_workaround = 1;
apply_pin_fixup(codec, cxt5051_fixups, cxt_pincfg_tbl);
break;
default:
codec->pin_amp_workaround = 1;
apply_pin_fixup(codec, cxt5066_fixups, cxt_pincfg_tbl);
}
switch (codec->subsystem_id >> 16) {
case 0x103c:
spec->vmaster_mute_led = 1;
break;
}
err = cx_auto_search_adcs(codec);
if (err < 0)
return err;
err = cx_auto_parse_auto_config(codec);
if (err < 0) {
kfree(codec->spec);
codec->spec = NULL;
return err;
}
spec->capture_stream = &cx_auto_pcm_analog_capture;
codec->patch_ops = cx_auto_patch_ops;
if (spec->beep_amp)
snd_hda_attach_beep_device(codec, spec->beep_amp);
if (!codec->bus->sync_write) {
snd_printd("hda_codec: "
"Enable sync_write for stable communication\n");
codec->bus->sync_write = 1;
codec->bus->allow_bus_reset = 1;
}
return 0;
}
static int __init patch_conexant_init(void)
{
return snd_hda_add_codec_preset(&conexant_list);
}
static void __exit patch_conexant_exit(void)
{
snd_hda_delete_codec_preset(&conexant_list);
}
