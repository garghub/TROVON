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
static int cmi9880_fill_multi_dac_nids(struct hda_codec *codec, const struct auto_pin_cfg *cfg)
{
struct cmi_spec *spec = codec->spec;
hda_nid_t nid;
int assigned[4];
int i, j;
memset(spec->dac_nids, 0, sizeof(spec->dac_nids));
memset(assigned, 0, sizeof(assigned));
for (i = 0; i < cfg->line_outs; i++) {
nid = cfg->line_out_pins[i];
if (nid >= 0x0b && nid <= 0x0e) {
spec->dac_nids[i] = (nid - 0x0b) + 0x03;
assigned[nid - 0x0b] = 1;
}
}
for (i = 0; i < cfg->line_outs; i++) {
nid = cfg->line_out_pins[i];
if (nid <= 0x0e)
continue;
for (j = 0; j < cfg->line_outs; j++) {
if (! assigned[j]) {
spec->dac_nids[i] = j + 0x03;
assigned[j] = 1;
break;
}
}
}
spec->num_dacs = cfg->line_outs;
return 0;
}
static int cmi9880_fill_multi_init(struct hda_codec *codec, const struct auto_pin_cfg *cfg)
{
struct cmi_spec *spec = codec->spec;
hda_nid_t nid;
int i, j, k;
memset(spec->multi_init, 0, sizeof(spec->multi_init));
for (j = 0, i = 0; i < cfg->line_outs; i++) {
nid = cfg->line_out_pins[i];
spec->multi_init[j].nid = nid;
spec->multi_init[j].verb = AC_VERB_SET_PIN_WIDGET_CONTROL;
spec->multi_init[j].param = PIN_OUT;
j++;
if (nid > 0x0e) {
spec->multi_init[j].nid = nid;
spec->multi_init[j].verb = AC_VERB_SET_CONNECT_SEL;
spec->multi_init[j].param = 0;
k = snd_hda_get_conn_index(codec, nid,
spec->dac_nids[i], 0);
if (k >= 0)
spec->multi_init[j].param = k;
j++;
}
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
static int patch_cmi9880(struct hda_codec *codec)
{
struct cmi_spec *spec;
spec = kzalloc(sizeof(*spec), GFP_KERNEL);
if (spec == NULL)
return -ENOMEM;
codec->spec = spec;
spec->board_config = snd_hda_check_board_config(codec, CMI_MODELS,
cmi9880_models,
cmi9880_cfg_tbl);
if (spec->board_config < 0) {
snd_printdd(KERN_INFO "hda_codec: %s: BIOS auto-probing.\n",
codec->chip_name);
spec->board_config = CMI_AUTO;
}
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
spec->front_panel = 1;
spec->multiout.max_channels = 8;
spec->no_line_in = 1;
spec->input_mux = &cmi9880_no_line_mux;
spec->multiout.dig_out_nid = CMI_DIG_OUT_NID;
break;
case CMI_AUTO:
{
unsigned int port_e, port_f, port_g, port_h;
unsigned int port_spdifi, port_spdifo;
struct auto_pin_cfg cfg;
port_e = snd_hda_codec_get_pincfg(codec, 0x0f);
port_f = snd_hda_codec_get_pincfg(codec, 0x10);
spec->front_panel = 1;
if (get_defcfg_connect(port_e) == AC_JACK_PORT_NONE ||
get_defcfg_connect(port_f) == AC_JACK_PORT_NONE) {
port_g = snd_hda_codec_get_pincfg(codec, 0x1f);
port_h = snd_hda_codec_get_pincfg(codec, 0x20);
spec->channel_modes = cmi9880_channel_modes;
if (get_defcfg_connect(port_g) == AC_JACK_PORT_NONE ||
get_defcfg_connect(port_h) == AC_JACK_PORT_NONE) {
spec->board_config = CMI_MINIMAL;
spec->front_panel = 0;
spec->num_channel_modes = 2;
} else {
spec->board_config = CMI_MIN_FP;
spec->num_channel_modes = 3;
}
spec->input_mux = &cmi9880_basic_mux;
spec->multiout.max_channels = cmi9880_channel_modes[0].channels;
} else {
spec->input_mux = &cmi9880_basic_mux;
port_spdifi = snd_hda_codec_get_pincfg(codec, 0x13);
port_spdifo = snd_hda_codec_get_pincfg(codec, 0x12);
if (get_defcfg_connect(port_spdifo) != AC_JACK_PORT_NONE)
spec->multiout.dig_out_nid = CMI_DIG_OUT_NID;
if (get_defcfg_connect(port_spdifi) != AC_JACK_PORT_NONE)
spec->dig_in_nid = CMI_DIG_IN_NID;
spec->multiout.max_channels = 8;
}
snd_hda_parse_pin_def_config(codec, &cfg, NULL);
if (cfg.line_outs) {
spec->multiout.max_channels = cfg.line_outs * 2;
cmi9880_fill_multi_dac_nids(codec, &cfg);
cmi9880_fill_multi_init(codec, &cfg);
} else
snd_printd("patch_cmedia: cannot detect association in defcfg\n");
break;
}
}
spec->multiout.num_dacs = spec->num_dacs;
spec->multiout.dac_nids = spec->dac_nids;
spec->adc_nids = cmi9880_adc_nids;
codec->patch_ops = cmi9880_patch_ops;
return 0;
}
static int __init patch_cmedia_init(void)
{
return snd_hda_add_codec_preset(&cmedia_list);
}
static void __exit patch_cmedia_exit(void)
{
snd_hda_delete_codec_preset(&cmedia_list);
}
