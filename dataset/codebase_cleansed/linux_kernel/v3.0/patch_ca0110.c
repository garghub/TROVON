static int ca0110_playback_pcm_open(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
struct snd_pcm_substream *substream)
{
struct ca0110_spec *spec = codec->spec;
return snd_hda_multi_out_analog_open(codec, &spec->multiout, substream,
hinfo);
}
static int ca0110_playback_pcm_prepare(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
unsigned int stream_tag,
unsigned int format,
struct snd_pcm_substream *substream)
{
struct ca0110_spec *spec = codec->spec;
return snd_hda_multi_out_analog_prepare(codec, &spec->multiout,
stream_tag, format, substream);
}
static int ca0110_playback_pcm_cleanup(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
struct snd_pcm_substream *substream)
{
struct ca0110_spec *spec = codec->spec;
return snd_hda_multi_out_analog_cleanup(codec, &spec->multiout);
}
static int ca0110_dig_playback_pcm_open(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
struct snd_pcm_substream *substream)
{
struct ca0110_spec *spec = codec->spec;
return snd_hda_multi_out_dig_open(codec, &spec->multiout);
}
static int ca0110_dig_playback_pcm_close(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
struct snd_pcm_substream *substream)
{
struct ca0110_spec *spec = codec->spec;
return snd_hda_multi_out_dig_close(codec, &spec->multiout);
}
static int ca0110_dig_playback_pcm_prepare(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
unsigned int stream_tag,
unsigned int format,
struct snd_pcm_substream *substream)
{
struct ca0110_spec *spec = codec->spec;
return snd_hda_multi_out_dig_prepare(codec, &spec->multiout, stream_tag,
format, substream);
}
static int ca0110_capture_pcm_prepare(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
unsigned int stream_tag,
unsigned int format,
struct snd_pcm_substream *substream)
{
struct ca0110_spec *spec = codec->spec;
snd_hda_codec_setup_stream(codec, spec->adcs[substream->number],
stream_tag, 0, format);
return 0;
}
static int ca0110_capture_pcm_cleanup(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
struct snd_pcm_substream *substream)
{
struct ca0110_spec *spec = codec->spec;
snd_hda_codec_cleanup_stream(codec, spec->adcs[substream->number]);
return 0;
}
static int _add_switch(struct hda_codec *codec, hda_nid_t nid, const char *pfx,
int chan, int dir)
{
char namestr[44];
int type = dir ? HDA_INPUT : HDA_OUTPUT;
struct snd_kcontrol_new knew =
HDA_CODEC_MUTE_MONO(namestr, nid, chan, 0, type);
sprintf(namestr, "%s %s Switch", pfx, dirstr[dir]);
return snd_hda_ctl_add(codec, nid, snd_ctl_new1(&knew, codec));
}
static int _add_volume(struct hda_codec *codec, hda_nid_t nid, const char *pfx,
int chan, int dir)
{
char namestr[44];
int type = dir ? HDA_INPUT : HDA_OUTPUT;
struct snd_kcontrol_new knew =
HDA_CODEC_VOLUME_MONO(namestr, nid, chan, 0, type);
sprintf(namestr, "%s %s Volume", pfx, dirstr[dir]);
return snd_hda_ctl_add(codec, nid, snd_ctl_new1(&knew, codec));
}
static int ca0110_build_controls(struct hda_codec *codec)
{
struct ca0110_spec *spec = codec->spec;
struct auto_pin_cfg *cfg = &spec->autocfg;
static const char * const prefix[AUTO_CFG_MAX_OUTS] = {
"Front", "Surround", NULL, "Side", "Multi"
};
hda_nid_t mutenid;
int i, err;
for (i = 0; i < spec->multiout.num_dacs; i++) {
if (get_wcaps(codec, spec->out_pins[i]) & AC_WCAP_OUT_AMP)
mutenid = spec->out_pins[i];
else
mutenid = spec->multiout.dac_nids[i];
if (!prefix[i]) {
err = add_mono_switch(codec, mutenid,
"Center", 1);
if (err < 0)
return err;
err = add_mono_switch(codec, mutenid,
"LFE", 1);
if (err < 0)
return err;
err = add_mono_volume(codec, spec->multiout.dac_nids[i],
"Center", 1);
if (err < 0)
return err;
err = add_mono_volume(codec, spec->multiout.dac_nids[i],
"LFE", 1);
if (err < 0)
return err;
} else {
err = add_out_switch(codec, mutenid,
prefix[i]);
if (err < 0)
return err;
err = add_out_volume(codec, spec->multiout.dac_nids[i],
prefix[i]);
if (err < 0)
return err;
}
}
if (cfg->hp_outs) {
if (get_wcaps(codec, cfg->hp_pins[0]) & AC_WCAP_OUT_AMP)
mutenid = cfg->hp_pins[0];
else
mutenid = spec->multiout.dac_nids[i];
err = add_out_switch(codec, mutenid, "Headphone");
if (err < 0)
return err;
if (spec->hp_dac) {
err = add_out_volume(codec, spec->hp_dac, "Headphone");
if (err < 0)
return err;
}
}
for (i = 0; i < spec->num_inputs; i++) {
const char *label = spec->input_labels[i];
if (get_wcaps(codec, spec->input_pins[i]) & AC_WCAP_IN_AMP)
mutenid = spec->input_pins[i];
else
mutenid = spec->adcs[i];
err = add_in_switch(codec, mutenid, label);
if (err < 0)
return err;
err = add_in_volume(codec, spec->adcs[i], label);
if (err < 0)
return err;
}
if (spec->dig_out) {
err = snd_hda_create_spdif_out_ctls(codec, spec->dig_out);
if (err < 0)
return err;
err = snd_hda_create_spdif_share_sw(codec, &spec->multiout);
if (err < 0)
return err;
spec->multiout.share_spdif = 1;
}
if (spec->dig_in) {
err = snd_hda_create_spdif_in_ctls(codec, spec->dig_in);
if (err < 0)
return err;
err = add_in_volume(codec, spec->dig_in, "IEC958");
}
return 0;
}
static int ca0110_build_pcms(struct hda_codec *codec)
{
struct ca0110_spec *spec = codec->spec;
struct hda_pcm *info = spec->pcm_rec;
codec->pcm_info = info;
codec->num_pcms = 0;
info->name = "CA0110 Analog";
info->stream[SNDRV_PCM_STREAM_PLAYBACK] = ca0110_pcm_analog_playback;
info->stream[SNDRV_PCM_STREAM_PLAYBACK].nid = spec->dacs[0];
info->stream[SNDRV_PCM_STREAM_PLAYBACK].channels_max =
spec->multiout.max_channels;
info->stream[SNDRV_PCM_STREAM_CAPTURE] = ca0110_pcm_analog_capture;
info->stream[SNDRV_PCM_STREAM_CAPTURE].substreams = spec->num_inputs;
info->stream[SNDRV_PCM_STREAM_CAPTURE].nid = spec->adcs[0];
codec->num_pcms++;
if (!spec->dig_out && !spec->dig_in)
return 0;
info++;
info->name = "CA0110 Digital";
info->pcm_type = HDA_PCM_TYPE_SPDIF;
if (spec->dig_out) {
info->stream[SNDRV_PCM_STREAM_PLAYBACK] =
ca0110_pcm_digital_playback;
info->stream[SNDRV_PCM_STREAM_PLAYBACK].nid = spec->dig_out;
}
if (spec->dig_in) {
info->stream[SNDRV_PCM_STREAM_CAPTURE] =
ca0110_pcm_digital_capture;
info->stream[SNDRV_PCM_STREAM_CAPTURE].nid = spec->dig_in;
}
codec->num_pcms++;
return 0;
}
static void init_output(struct hda_codec *codec, hda_nid_t pin, hda_nid_t dac)
{
if (pin) {
snd_hda_codec_write(codec, pin, 0,
AC_VERB_SET_PIN_WIDGET_CONTROL, PIN_HP);
if (get_wcaps(codec, pin) & AC_WCAP_OUT_AMP)
snd_hda_codec_write(codec, pin, 0,
AC_VERB_SET_AMP_GAIN_MUTE,
AMP_OUT_UNMUTE);
}
if (dac)
snd_hda_codec_write(codec, dac, 0,
AC_VERB_SET_AMP_GAIN_MUTE, AMP_OUT_ZERO);
}
static void init_input(struct hda_codec *codec, hda_nid_t pin, hda_nid_t adc)
{
if (pin) {
snd_hda_codec_write(codec, pin, 0,
AC_VERB_SET_PIN_WIDGET_CONTROL, PIN_VREF80);
if (get_wcaps(codec, pin) & AC_WCAP_IN_AMP)
snd_hda_codec_write(codec, pin, 0,
AC_VERB_SET_AMP_GAIN_MUTE,
AMP_IN_UNMUTE(0));
}
if (adc)
snd_hda_codec_write(codec, adc, 0, AC_VERB_SET_AMP_GAIN_MUTE,
AMP_IN_UNMUTE(0));
}
static int ca0110_init(struct hda_codec *codec)
{
struct ca0110_spec *spec = codec->spec;
struct auto_pin_cfg *cfg = &spec->autocfg;
int i;
for (i = 0; i < spec->multiout.num_dacs; i++)
init_output(codec, spec->out_pins[i],
spec->multiout.dac_nids[i]);
init_output(codec, cfg->hp_pins[0], spec->hp_dac);
init_output(codec, cfg->dig_out_pins[0], spec->dig_out);
for (i = 0; i < spec->num_inputs; i++)
init_input(codec, spec->input_pins[i], spec->adcs[i]);
init_input(codec, cfg->dig_in_pin, spec->dig_in);
return 0;
}
static void ca0110_free(struct hda_codec *codec)
{
kfree(codec->spec);
}
static void parse_line_outs(struct hda_codec *codec)
{
struct ca0110_spec *spec = codec->spec;
struct auto_pin_cfg *cfg = &spec->autocfg;
int i, n;
unsigned int def_conf;
hda_nid_t nid;
n = 0;
for (i = 0; i < cfg->line_outs; i++) {
nid = cfg->line_out_pins[i];
def_conf = snd_hda_codec_get_pincfg(codec, nid);
if (!def_conf)
continue;
if (snd_hda_get_connections(codec, nid, &spec->dacs[i], 1) != 1)
continue;
spec->out_pins[n++] = nid;
}
spec->multiout.dac_nids = spec->dacs;
spec->multiout.num_dacs = n;
spec->multiout.max_channels = n * 2;
}
static void parse_hp_out(struct hda_codec *codec)
{
struct ca0110_spec *spec = codec->spec;
struct auto_pin_cfg *cfg = &spec->autocfg;
int i;
unsigned int def_conf;
hda_nid_t nid, dac;
if (!cfg->hp_outs)
return;
nid = cfg->hp_pins[0];
def_conf = snd_hda_codec_get_pincfg(codec, nid);
if (!def_conf) {
cfg->hp_outs = 0;
return;
}
if (snd_hda_get_connections(codec, nid, &dac, 1) != 1)
return;
for (i = 0; i < cfg->line_outs; i++)
if (dac == spec->dacs[i])
break;
if (i >= cfg->line_outs) {
spec->hp_dac = dac;
spec->multiout.hp_nid = dac;
}
}
static void parse_input(struct hda_codec *codec)
{
struct ca0110_spec *spec = codec->spec;
struct auto_pin_cfg *cfg = &spec->autocfg;
hda_nid_t nid, pin;
int n, i, j;
n = 0;
nid = codec->start_nid;
for (i = 0; i < codec->num_nodes; i++, nid++) {
unsigned int wcaps = get_wcaps(codec, nid);
unsigned int type = get_wcaps_type(wcaps);
if (type != AC_WID_AUD_IN)
continue;
if (snd_hda_get_connections(codec, nid, &pin, 1) != 1)
continue;
if (pin == cfg->dig_in_pin) {
spec->dig_in = nid;
continue;
}
for (j = 0; j < cfg->num_inputs; j++)
if (cfg->inputs[j].pin == pin)
break;
if (j >= cfg->num_inputs)
continue;
spec->input_pins[n] = pin;
spec->input_labels[n] = hda_get_input_pin_label(codec, pin, 1);
spec->adcs[n] = nid;
n++;
}
spec->num_inputs = n;
}
static void parse_digital(struct hda_codec *codec)
{
struct ca0110_spec *spec = codec->spec;
struct auto_pin_cfg *cfg = &spec->autocfg;
if (cfg->dig_outs &&
snd_hda_get_connections(codec, cfg->dig_out_pins[0],
&spec->dig_out, 1) == 1)
spec->multiout.dig_out_nid = spec->dig_out;
}
static int ca0110_parse_auto_config(struct hda_codec *codec)
{
struct ca0110_spec *spec = codec->spec;
int err;
err = snd_hda_parse_pin_def_config(codec, &spec->autocfg, NULL);
if (err < 0)
return err;
parse_line_outs(codec);
parse_hp_out(codec);
parse_digital(codec);
parse_input(codec);
return 0;
}
static int patch_ca0110(struct hda_codec *codec)
{
struct ca0110_spec *spec;
int err;
spec = kzalloc(sizeof(*spec), GFP_KERNEL);
if (!spec)
return -ENOMEM;
codec->spec = spec;
codec->bus->needs_damn_long_delay = 1;
err = ca0110_parse_auto_config(codec);
if (err < 0)
goto error;
codec->patch_ops = ca0110_patch_ops;
return 0;
error:
kfree(codec->spec);
codec->spec = NULL;
return err;
}
static int __init patch_ca0110_init(void)
{
return snd_hda_add_codec_preset(&ca0110_list);
}
static void __exit patch_ca0110_exit(void)
{
snd_hda_delete_codec_preset(&ca0110_list);
}
