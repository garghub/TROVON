static int cmi_mux_enum_info(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_info *uinfo)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct cmi_spec *spec = codec->spec;
return snd_hda_input_mux_info(spec->input_mux, uinfo);
}
static int cmi_mux_enum_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct cmi_spec *spec = codec->spec;
unsigned int adc_idx = snd_ctl_get_ioffidx(kcontrol, &ucontrol->id);
ucontrol->value.enumerated.item[0] = spec->cur_mux[adc_idx];
return 0;
}
static int cmi_mux_enum_put(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct cmi_spec *spec = codec->spec;
unsigned int adc_idx = snd_ctl_get_ioffidx(kcontrol, &ucontrol->id);
return snd_hda_input_mux_put(codec, spec->input_mux, ucontrol,
spec->adc_nids[adc_idx], &spec->cur_mux[adc_idx]);
}
static int cmi_ch_mode_info(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_info *uinfo)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct cmi_spec *spec = codec->spec;
return snd_hda_ch_mode_info(codec, uinfo, spec->channel_modes,
spec->num_channel_modes);
}
static int cmi_ch_mode_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct cmi_spec *spec = codec->spec;
return snd_hda_ch_mode_get(codec, ucontrol, spec->channel_modes,
spec->num_channel_modes, spec->multiout.max_channels);
}
static int cmi_ch_mode_put(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct cmi_spec *spec = codec->spec;
return snd_hda_ch_mode_put(codec, ucontrol, spec->channel_modes,
spec->num_channel_modes, &spec->multiout.max_channels);
}
static int cmi9880_build_controls(struct hda_codec *codec)
{
struct cmi_spec *spec = codec->spec;
struct snd_kcontrol *kctl;
int i, err;
err = snd_hda_add_new_ctls(codec, cmi9880_basic_mixer);
if (err < 0)
return err;
if (spec->channel_modes) {
err = snd_hda_add_new_ctls(codec, cmi9880_ch_mode_mixer);
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
err = snd_hda_create_spdif_in_ctls(codec, spec->dig_in_nid);
if (err < 0)
return err;
}
kctl = snd_hda_find_mixer_ctl(codec, "Capture Source");
for (i = 0; kctl && i < kctl->count; i++) {
err = snd_hda_add_nid(codec, kctl, i, spec->adc_nids[i]);
if (err < 0)
return err;
}
return 0;
}
static int cmi9880_init(struct hda_codec *codec)
{
struct cmi_spec *spec = codec->spec;
if (spec->board_config == CMI_ALLOUT)
snd_hda_sequence_write(codec, cmi9880_allout_init);
else
snd_hda_sequence_write(codec, cmi9880_basic_init);
if (spec->board_config == CMI_AUTO)
snd_hda_sequence_write(codec, spec->multi_init);
return 0;
}
static int cmi9880_playback_pcm_open(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
struct snd_pcm_substream *substream)
{
struct cmi_spec *spec = codec->spec;
return snd_hda_multi_out_analog_open(codec, &spec->multiout, substream,
hinfo);
}
static int cmi9880_playback_pcm_prepare(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
unsigned int stream_tag,
unsigned int format,
struct snd_pcm_substream *substream)
{
struct cmi_spec *spec = codec->spec;
return snd_hda_multi_out_analog_prepare(codec, &spec->multiout, stream_tag,
format, substream);
}
static int cmi9880_playback_pcm_cleanup(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
struct snd_pcm_substream *substream)
{
struct cmi_spec *spec = codec->spec;
return snd_hda_multi_out_analog_cleanup(codec, &spec->multiout);
}
static int cmi9880_dig_playback_pcm_open(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
struct snd_pcm_substream *substream)
{
struct cmi_spec *spec = codec->spec;
return snd_hda_multi_out_dig_open(codec, &spec->multiout);
}
static int cmi9880_dig_playback_pcm_close(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
struct snd_pcm_substream *substream)
{
struct cmi_spec *spec = codec->spec;
return snd_hda_multi_out_dig_close(codec, &spec->multiout);
}
static int cmi9880_dig_playback_pcm_prepare(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
unsigned int stream_tag,
unsigned int format,
struct snd_pcm_substream *substream)
{
struct cmi_spec *spec = codec->spec;
return snd_hda_multi_out_dig_prepare(codec, &spec->multiout, stream_tag,
format, substream);
}
static int cmi9880_capture_pcm_prepare(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
unsigned int stream_tag,
unsigned int format,
struct snd_pcm_substream *substream)
{
struct cmi_spec *spec = codec->spec;
snd_hda_codec_setup_stream(codec, spec->adc_nids[substream->number],
stream_tag, 0, format);
return 0;
}
static int cmi9880_capture_pcm_cleanup(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
struct snd_pcm_substream *substream)
{
struct cmi_spec *spec = codec->spec;
snd_hda_codec_cleanup_stream(codec, spec->adc_nids[substream->number]);
return 0;
}
static int cmi9880_build_pcms(struct hda_codec *codec)
{
struct cmi_spec *spec = codec->spec;
struct hda_pcm *info = spec->pcm_rec;
codec->num_pcms = 1;
codec->pcm_info = info;
info->name = "CMI9880";
info->stream[SNDRV_PCM_STREAM_PLAYBACK] = cmi9880_pcm_analog_playback;
info->stream[SNDRV_PCM_STREAM_CAPTURE] = cmi9880_pcm_analog_capture;
if (spec->multiout.dig_out_nid || spec->dig_in_nid) {
codec->num_pcms++;
info++;
info->name = "CMI9880 Digital";
info->pcm_type = HDA_PCM_TYPE_SPDIF;
if (spec->multiout.dig_out_nid) {
info->stream[SNDRV_PCM_STREAM_PLAYBACK] = cmi9880_pcm_digital_playback;
info->stream[SNDRV_PCM_STREAM_PLAYBACK].nid = spec->multiout.dig_out_nid;
}
if (spec->dig_in_nid) {
info->stream[SNDRV_PCM_STREAM_CAPTURE] = cmi9880_pcm_digital_capture;
info->stream[SNDRV_PCM_STREAM_CAPTURE].nid = spec->dig_in_nid;
}
}
return 0;
}
static void cmi9880_free(struct hda_codec *codec)
{
kfree(codec->spec);
}
static int cmi_parse_auto_config(struct hda_codec *codec)
{
struct cmi_spec *spec = codec->spec;
struct auto_pin_cfg *cfg = &spec->gen.autocfg;
int err;
snd_hda_gen_spec_init(&spec->gen);
err = snd_hda_parse_pin_defcfg(codec, cfg, NULL, 0);
if (err < 0)
goto error;
err = snd_hda_gen_parse_auto_config(codec, cfg);
if (err < 0)
goto error;
codec->patch_ops = cmi_auto_patch_ops;
return 0;
error:
snd_hda_gen_free(codec);
return err;
}
static int patch_cmi9880(struct hda_codec *codec)
{
struct cmi_spec *spec;
spec = kzalloc(sizeof(*spec), GFP_KERNEL);
if (spec == NULL)
return -ENOMEM;
codec->spec = spec;
#ifdef ENABLE_CMI_STATIC_QUIRKS
spec->board_config = snd_hda_check_board_config(codec, CMI_MODELS,
cmi9880_models,
cmi9880_cfg_tbl);
if (spec->board_config < 0) {
codec_dbg(codec, "%s: BIOS auto-probing.\n",
codec->chip_name);
spec->board_config = CMI_AUTO;
}
if (spec->board_config == CMI_AUTO)
return cmi_parse_auto_config(codec);
memcpy(spec->dac_nids, cmi9880_dac_nids, sizeof(spec->dac_nids));
spec->num_dacs = 4;
switch (spec->board_config) {
case CMI_MINIMAL:
case CMI_MIN_FP:
spec->channel_modes = cmi9880_channel_modes;
if (spec->board_config == CMI_MINIMAL)
spec->num_channel_modes = 2;
else {
spec->front_panel = 1;
spec->num_channel_modes = 3;
}
spec->multiout.max_channels = cmi9880_channel_modes[0].channels;
spec->input_mux = &cmi9880_basic_mux;
break;
case CMI_FULL:
case CMI_FULL_DIG:
spec->front_panel = 1;
spec->multiout.max_channels = 8;
spec->input_mux = &cmi9880_basic_mux;
if (spec->board_config == CMI_FULL_DIG) {
spec->multiout.dig_out_nid = CMI_DIG_OUT_NID;
spec->dig_in_nid = CMI_DIG_IN_NID;
}
break;
case CMI_ALLOUT:
default:
spec->front_panel = 1;
spec->multiout.max_channels = 8;
spec->no_line_in = 1;
spec->input_mux = &cmi9880_no_line_mux;
spec->multiout.dig_out_nid = CMI_DIG_OUT_NID;
break;
}
spec->multiout.num_dacs = spec->num_dacs;
spec->multiout.dac_nids = spec->dac_nids;
spec->adc_nids = cmi9880_adc_nids;
codec->patch_ops = cmi9880_patch_ops;
return 0;
#else
return cmi_parse_auto_config(codec);
#endif
}
static int __init patch_cmedia_init(void)
{
return snd_hda_add_codec_preset(&cmedia_list);
}
static void __exit patch_cmedia_exit(void)
{
snd_hda_delete_codec_preset(&cmedia_list);
}
