static int alc262_hippo_master_sw_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct alc_spec *spec = codec->spec;
*ucontrol->value.integer.value = !spec->master_mute;
return 0;
}
static int alc262_hippo_master_sw_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct alc_spec *spec = codec->spec;
int val = !*ucontrol->value.integer.value;
if (val == spec->master_mute)
return 0;
spec->master_mute = val;
update_outputs(codec);
return 1;
}
static void alc262_hippo_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x15;
spec->autocfg.speaker_pins[0] = 0x14;
alc_simple_setup_automute(spec, ALC_AUTOMUTE_AMP);
}
static void alc262_hippo1_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x1b;
spec->autocfg.speaker_pins[0] = 0x14;
alc_simple_setup_automute(spec, ALC_AUTOMUTE_AMP);
}
static void alc262_tyan_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x1b;
spec->autocfg.speaker_pins[0] = 0x15;
alc_simple_setup_automute(spec, ALC_AUTOMUTE_AMP);
}
static void alc262_toshiba_s06_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x15;
spec->autocfg.speaker_pins[0] = 0x14;
spec->ext_mic_pin = 0x18;
spec->int_mic_pin = 0x12;
spec->auto_mic = 1;
alc_simple_setup_automute(spec, ALC_AUTOMUTE_PIN);
}
static void alc262_fujitsu_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x14;
spec->autocfg.hp_pins[1] = 0x1b;
spec->autocfg.speaker_pins[0] = 0x15;
alc_simple_setup_automute(spec, ALC_AUTOMUTE_AMP);
}
static void alc262_lenovo_3000_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x1b;
spec->autocfg.speaker_pins[0] = 0x14;
spec->autocfg.speaker_pins[1] = 0x16;
alc_simple_setup_automute(spec, ALC_AUTOMUTE_AMP);
}
static void alc262_ultra_automute(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
unsigned int mute;
mute = 0;
if (!spec->cur_mux[0]) {
spec->hp_jack_present = snd_hda_jack_detect(codec, 0x15);
if (spec->hp_jack_present)
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
if ((res >> 26) != ALC_HP_EVENT)
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
