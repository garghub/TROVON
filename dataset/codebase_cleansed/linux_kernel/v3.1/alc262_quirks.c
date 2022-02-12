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
spec->ext_mic_pin = 0x18;
spec->int_mic_pin = 0x12;
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
