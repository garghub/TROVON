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
AC_VERB_SET_PIN_WIDGET_CONTROL,
PIN_VREF80);
if (get_wcaps(codec, pin) & AC_WCAP_IN_AMP)
snd_hda_codec_write(codec, pin, 0,
AC_VERB_SET_AMP_GAIN_MUTE,
AMP_IN_UNMUTE(0));
}
if (adc)
snd_hda_codec_write(codec, adc, 0, AC_VERB_SET_AMP_GAIN_MUTE,
AMP_IN_UNMUTE(0));
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
static int chipio_send(struct hda_codec *codec,
unsigned int reg,
unsigned int data)
{
unsigned int res;
int retry = 50;
do {
res = snd_hda_codec_read(codec, WIDGET_CHIP_CTRL, 0,
reg, data);
if (res == VENDOR_STATUS_CHIPIO_OK)
return 0;
} while (--retry);
return -EIO;
}
static int chipio_write_address(struct hda_codec *codec,
unsigned int chip_addx)
{
int res;
res = chipio_send(codec, VENDOR_CHIPIO_ADDRESS_LOW,
chip_addx & 0xffff);
if (res != -EIO) {
res = chipio_send(codec, VENDOR_CHIPIO_ADDRESS_HIGH,
chip_addx >> 16);
}
return res;
}
static int chipio_write_data(struct hda_codec *codec, unsigned int data)
{
int res;
res = chipio_send(codec, VENDOR_CHIPIO_DATA_LOW, data & 0xffff);
if (res != -EIO) {
res = chipio_send(codec, VENDOR_CHIPIO_DATA_HIGH,
data >> 16);
}
return res;
}
static int chipio_read_data(struct hda_codec *codec, unsigned int *data)
{
int res;
res = chipio_send(codec, VENDOR_CHIPIO_HIC_POST_READ, 0);
if (res != -EIO) {
res = chipio_send(codec, VENDOR_CHIPIO_STATUS, 0);
}
if (res != -EIO) {
*data = snd_hda_codec_read(codec, WIDGET_CHIP_CTRL, 0,
VENDOR_CHIPIO_HIC_READ_DATA,
0);
}
return res;
}
static int chipio_write(struct hda_codec *codec,
unsigned int chip_addx, const unsigned int data)
{
struct ca0132_spec *spec = codec->spec;
int err;
mutex_lock(&spec->chipio_mutex);
err = chipio_write_address(codec, chip_addx);
if (err < 0)
goto exit;
err = chipio_write_data(codec, data);
if (err < 0)
goto exit;
exit:
mutex_unlock(&spec->chipio_mutex);
return err;
}
static int chipio_read(struct hda_codec *codec,
unsigned int chip_addx, unsigned int *data)
{
struct ca0132_spec *spec = codec->spec;
int err;
mutex_lock(&spec->chipio_mutex);
err = chipio_write_address(codec, chip_addx);
if (err < 0)
goto exit;
err = chipio_read_data(codec, data);
if (err < 0)
goto exit;
exit:
mutex_unlock(&spec->chipio_mutex);
return err;
}
static void ca0132_setup_stream(struct hda_codec *codec, hda_nid_t nid,
u32 stream_tag,
int channel_id, int format)
{
unsigned int oldval, newval;
if (!nid)
return;
snd_printdd("ca0132_setup_stream: "
"NID=0x%x, stream=0x%x, channel=%d, format=0x%x\n",
nid, stream_tag, channel_id, format);
oldval = snd_hda_codec_read(codec, nid, 0,
AC_VERB_GET_STREAM_FORMAT,
0);
if (oldval != format) {
msleep(20);
snd_hda_codec_write(codec, nid, 0,
AC_VERB_SET_STREAM_FORMAT,
format);
}
oldval = snd_hda_codec_read(codec, nid, 0, AC_VERB_GET_CONV, 0);
newval = (stream_tag << 4) | channel_id;
if (oldval != newval) {
snd_hda_codec_write(codec, nid, 0,
AC_VERB_SET_CHANNEL_STREAMID,
newval);
}
}
static void ca0132_cleanup_stream(struct hda_codec *codec, hda_nid_t nid)
{
snd_hda_codec_write(codec, nid, 0, AC_VERB_SET_STREAM_FORMAT, 0);
snd_hda_codec_write(codec, nid, 0, AC_VERB_SET_CHANNEL_STREAMID, 0);
}
static int ca0132_playback_pcm_prepare(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
unsigned int stream_tag,
unsigned int format,
struct snd_pcm_substream *substream)
{
struct ca0132_spec *spec = codec->spec;
ca0132_setup_stream(codec, spec->dacs[0], stream_tag, 0, format);
return 0;
}
static int ca0132_playback_pcm_cleanup(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
struct snd_pcm_substream *substream)
{
struct ca0132_spec *spec = codec->spec;
ca0132_cleanup_stream(codec, spec->dacs[0]);
return 0;
}
static int ca0132_dig_playback_pcm_prepare(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
unsigned int stream_tag,
unsigned int format,
struct snd_pcm_substream *substream)
{
struct ca0132_spec *spec = codec->spec;
ca0132_setup_stream(codec, spec->dig_out, stream_tag, 0, format);
return 0;
}
static int ca0132_dig_playback_pcm_cleanup(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
struct snd_pcm_substream *substream)
{
struct ca0132_spec *spec = codec->spec;
ca0132_cleanup_stream(codec, spec->dig_out);
return 0;
}
static int ca0132_capture_pcm_prepare(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
unsigned int stream_tag,
unsigned int format,
struct snd_pcm_substream *substream)
{
struct ca0132_spec *spec = codec->spec;
ca0132_setup_stream(codec, spec->adcs[substream->number],
stream_tag, 0, format);
return 0;
}
static int ca0132_capture_pcm_cleanup(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
struct snd_pcm_substream *substream)
{
struct ca0132_spec *spec = codec->spec;
ca0132_cleanup_stream(codec, spec->adcs[substream->number]);
return 0;
}
static int ca0132_dig_capture_pcm_prepare(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
unsigned int stream_tag,
unsigned int format,
struct snd_pcm_substream *substream)
{
struct ca0132_spec *spec = codec->spec;
ca0132_setup_stream(codec, spec->dig_in, stream_tag, 0, format);
return 0;
}
static int ca0132_dig_capture_pcm_cleanup(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
struct snd_pcm_substream *substream)
{
struct ca0132_spec *spec = codec->spec;
ca0132_cleanup_stream(codec, spec->dig_in);
return 0;
}
static int ca0132_build_pcms(struct hda_codec *codec)
{
struct ca0132_spec *spec = codec->spec;
struct hda_pcm *info = spec->pcm_rec;
codec->pcm_info = info;
codec->num_pcms = 0;
info->name = "CA0132 Analog";
info->stream[SNDRV_PCM_STREAM_PLAYBACK] = ca0132_pcm_analog_playback;
info->stream[SNDRV_PCM_STREAM_PLAYBACK].nid = spec->dacs[0];
info->stream[SNDRV_PCM_STREAM_PLAYBACK].channels_max =
spec->multiout.max_channels;
info->stream[SNDRV_PCM_STREAM_CAPTURE] = ca0132_pcm_analog_capture;
info->stream[SNDRV_PCM_STREAM_CAPTURE].substreams = spec->num_inputs;
info->stream[SNDRV_PCM_STREAM_CAPTURE].nid = spec->adcs[0];
codec->num_pcms++;
if (!spec->dig_out && !spec->dig_in)
return 0;
info++;
info->name = "CA0132 Digital";
info->pcm_type = HDA_PCM_TYPE_SPDIF;
if (spec->dig_out) {
info->stream[SNDRV_PCM_STREAM_PLAYBACK] =
ca0132_pcm_digital_playback;
info->stream[SNDRV_PCM_STREAM_PLAYBACK].nid = spec->dig_out;
}
if (spec->dig_in) {
info->stream[SNDRV_PCM_STREAM_CAPTURE] =
ca0132_pcm_digital_capture;
info->stream[SNDRV_PCM_STREAM_CAPTURE].nid = spec->dig_in;
}
codec->num_pcms++;
return 0;
}
static int ca0132_hp_switch_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct ca0132_spec *spec = codec->spec;
long *valp = ucontrol->value.integer.value;
*valp = spec->curr_hp_switch;
return 0;
}
static int ca0132_hp_switch_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct ca0132_spec *spec = codec->spec;
long *valp = ucontrol->value.integer.value;
unsigned int data;
int err;
if (spec->curr_hp_switch == *valp)
return 0;
snd_hda_power_up(codec);
err = chipio_read(codec, REG_CODEC_MUTE, &data);
if (err < 0)
goto exit;
data = (data & 0x7f) | (*valp ? 0 : 0x80);
err = chipio_write(codec, REG_CODEC_MUTE, data);
if (err < 0)
goto exit;
spec->curr_hp_switch = *valp;
exit:
snd_hda_power_down(codec);
return err < 0 ? err : 1;
}
static int ca0132_speaker_switch_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct ca0132_spec *spec = codec->spec;
long *valp = ucontrol->value.integer.value;
*valp = spec->curr_speaker_switch;
return 0;
}
static int ca0132_speaker_switch_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct ca0132_spec *spec = codec->spec;
long *valp = ucontrol->value.integer.value;
unsigned int data;
int err;
if (spec->curr_speaker_switch == *valp)
return 0;
snd_hda_power_up(codec);
err = chipio_read(codec, REG_CODEC_MUTE, &data);
if (err < 0)
goto exit;
data = (data & 0xef) | (*valp ? 0 : 0x10);
err = chipio_write(codec, REG_CODEC_MUTE, data);
if (err < 0)
goto exit;
spec->curr_speaker_switch = *valp;
exit:
snd_hda_power_down(codec);
return err < 0 ? err : 1;
}
static int ca0132_hp_volume_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct ca0132_spec *spec = codec->spec;
long *valp = ucontrol->value.integer.value;
*valp++ = spec->curr_hp_volume[0];
*valp = spec->curr_hp_volume[1];
return 0;
}
static int ca0132_hp_volume_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct ca0132_spec *spec = codec->spec;
long *valp = ucontrol->value.integer.value;
long left_vol, right_vol;
unsigned int data;
int val;
int err;
left_vol = *valp++;
right_vol = *valp;
if ((spec->curr_hp_volume[0] == left_vol) &&
(spec->curr_hp_volume[1] == right_vol))
return 0;
snd_hda_power_up(codec);
err = chipio_read(codec, REG_CODEC_HP_VOL_L, &data);
if (err < 0)
goto exit;
val = 31 - left_vol;
data = (data & 0xe0) | val;
err = chipio_write(codec, REG_CODEC_HP_VOL_L, data);
if (err < 0)
goto exit;
val = 31 - right_vol;
data = (data & 0xe0) | val;
err = chipio_write(codec, REG_CODEC_HP_VOL_R, data);
if (err < 0)
goto exit;
spec->curr_hp_volume[0] = left_vol;
spec->curr_hp_volume[1] = right_vol;
exit:
snd_hda_power_down(codec);
return err < 0 ? err : 1;
}
static int add_hp_switch(struct hda_codec *codec, hda_nid_t nid)
{
struct snd_kcontrol_new knew =
HDA_CODEC_MUTE_MONO("Headphone Playback Switch",
nid, 1, 0, HDA_OUTPUT);
knew.get = ca0132_hp_switch_get;
knew.put = ca0132_hp_switch_put;
return snd_hda_ctl_add(codec, nid, snd_ctl_new1(&knew, codec));
}
static int add_hp_volume(struct hda_codec *codec, hda_nid_t nid)
{
struct snd_kcontrol_new knew =
HDA_CODEC_VOLUME_MONO("Headphone Playback Volume",
nid, 3, 0, HDA_OUTPUT);
knew.get = ca0132_hp_volume_get;
knew.put = ca0132_hp_volume_put;
return snd_hda_ctl_add(codec, nid, snd_ctl_new1(&knew, codec));
}
static int add_speaker_switch(struct hda_codec *codec, hda_nid_t nid)
{
struct snd_kcontrol_new knew =
HDA_CODEC_MUTE_MONO("Speaker Playback Switch",
nid, 1, 0, HDA_OUTPUT);
knew.get = ca0132_speaker_switch_get;
knew.put = ca0132_speaker_switch_put;
return snd_hda_ctl_add(codec, nid, snd_ctl_new1(&knew, codec));
}
static void ca0132_fix_hp_caps(struct hda_codec *codec)
{
struct ca0132_spec *spec = codec->spec;
struct auto_pin_cfg *cfg = &spec->autocfg;
unsigned int caps;
caps = 0x80031f06;
snd_hda_override_amp_caps(codec, cfg->hp_pins[0], HDA_OUTPUT, caps);
}
static int ca0132_build_controls(struct hda_codec *codec)
{
struct ca0132_spec *spec = codec->spec;
struct auto_pin_cfg *cfg = &spec->autocfg;
int i, err;
if (spec->multiout.num_dacs) {
err = add_speaker_switch(codec, spec->out_pins[0]);
if (err < 0)
return err;
}
if (cfg->hp_outs) {
ca0132_fix_hp_caps(codec);
err = add_hp_switch(codec, cfg->hp_pins[0]);
if (err < 0)
return err;
err = add_hp_volume(codec, cfg->hp_pins[0]);
if (err < 0)
return err;
}
for (i = 0; i < spec->num_inputs; i++) {
const char *label = spec->input_labels[i];
err = add_in_switch(codec, spec->adcs[i], label);
if (err < 0)
return err;
err = add_in_volume(codec, spec->adcs[i], label);
if (err < 0)
return err;
if (cfg->inputs[i].type == AUTO_PIN_MIC) {
err = add_in_mono_volume(codec, spec->input_pins[i],
"Mic Boost", 1);
if (err < 0)
return err;
}
}
if (spec->dig_out) {
err = snd_hda_create_spdif_out_ctls(codec, spec->dig_out,
spec->dig_out);
if (err < 0)
return err;
err = add_out_volume(codec, spec->dig_out, "IEC958");
if (err < 0)
return err;
}
if (spec->dig_in) {
err = snd_hda_create_spdif_in_ctls(codec, spec->dig_in);
if (err < 0)
return err;
err = add_in_volume(codec, spec->dig_in, "IEC958");
if (err < 0)
return err;
}
return 0;
}
static void ca0132_set_ct_ext(struct hda_codec *codec, int enable)
{
snd_printdd("SET CREATIVE EXTENSION\n");
snd_hda_codec_write(codec, WIDGET_CHIP_CTRL, 0,
VENDOR_CHIPIO_CT_EXTENSIONS_ENABLE,
enable);
msleep(20);
}
static void ca0132_config(struct hda_codec *codec)
{
struct ca0132_spec *spec = codec->spec;
struct auto_pin_cfg *cfg = &spec->autocfg;
cfg->line_outs = 1;
cfg->line_out_pins[0] = 0x0b;
cfg->line_out_type = AUTO_PIN_LINE_OUT;
spec->dacs[0] = 0x02;
spec->out_pins[0] = 0x0b;
spec->multiout.dac_nids = spec->dacs;
spec->multiout.num_dacs = 1;
spec->multiout.max_channels = 2;
cfg->hp_outs = 1;
cfg->hp_pins[0] = 0x0f;
spec->hp_dac = 0;
spec->multiout.hp_nid = 0;
cfg->num_inputs = 2;
cfg->inputs[0].pin = 0x12;
cfg->inputs[0].type = AUTO_PIN_MIC;
cfg->inputs[1].pin = 0x11;
cfg->inputs[1].type = AUTO_PIN_LINE_IN;
spec->input_pins[0] = 0x12;
spec->input_labels[0] = "Mic-In";
spec->adcs[0] = 0x07;
spec->input_pins[1] = 0x11;
spec->input_labels[1] = "Line-In";
spec->adcs[1] = 0x08;
spec->num_inputs = 2;
}
static void ca0132_init_chip(struct hda_codec *codec)
{
struct ca0132_spec *spec = codec->spec;
mutex_init(&spec->chipio_mutex);
}
static void ca0132_exit_chip(struct hda_codec *codec)
{
}
static int ca0132_init(struct hda_codec *codec)
{
struct ca0132_spec *spec = codec->spec;
struct auto_pin_cfg *cfg = &spec->autocfg;
int i;
for (i = 0; i < spec->multiout.num_dacs; i++) {
init_output(codec, spec->out_pins[i],
spec->multiout.dac_nids[i]);
}
init_output(codec, cfg->hp_pins[0], spec->hp_dac);
init_output(codec, cfg->dig_out_pins[0], spec->dig_out);
for (i = 0; i < spec->num_inputs; i++)
init_input(codec, spec->input_pins[i], spec->adcs[i]);
init_input(codec, cfg->dig_in_pin, spec->dig_in);
ca0132_set_ct_ext(codec, 1);
return 0;
}
static void ca0132_free(struct hda_codec *codec)
{
ca0132_set_ct_ext(codec, 0);
ca0132_exit_chip(codec);
kfree(codec->spec);
}
static int patch_ca0132(struct hda_codec *codec)
{
struct ca0132_spec *spec;
snd_printdd("patch_ca0132\n");
spec = kzalloc(sizeof(*spec), GFP_KERNEL);
if (!spec)
return -ENOMEM;
codec->spec = spec;
ca0132_init_chip(codec);
ca0132_config(codec);
codec->patch_ops = ca0132_patch_ops;
return 0;
}
static int __init patch_ca0132_init(void)
{
return snd_hda_add_codec_preset(&ca0132_list);
}
static void __exit patch_ca0132_exit(void)
{
snd_hda_delete_codec_preset(&ca0132_list);
}
