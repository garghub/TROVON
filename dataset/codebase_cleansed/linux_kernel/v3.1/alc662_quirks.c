static void alc662_lenovo_101e_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x1b;
spec->autocfg.line_out_pins[0] = 0x14;
spec->autocfg.speaker_pins[0] = 0x15;
spec->automute = 1;
spec->detect_line = 1;
spec->automute_lines = 1;
spec->automute_mode = ALC_AUTOMUTE_AMP;
}
static void alc662_eeepc_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
alc262_hippo1_setup(codec);
spec->ext_mic_pin = 0x18;
spec->int_mic_pin = 0x19;
spec->auto_mic = 1;
}
static void alc662_eeepc_ep20_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x14;
spec->autocfg.speaker_pins[0] = 0x1b;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_AMP;
}
static void alc663_m51va_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x21;
spec->autocfg.speaker_pins[0] = 0x14;
spec->automute_mixer_nid[0] = 0x0c;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_MIXER;
spec->ext_mic_pin = 0x18;
spec->int_mic_pin = 0x12;
spec->auto_mic = 1;
}
static void alc663_mode1_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x21;
spec->autocfg.speaker_pins[0] = 0x14;
spec->automute_mixer_nid[0] = 0x0c;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_MIXER;
spec->ext_mic_pin = 0x18;
spec->int_mic_pin = 0x19;
spec->auto_mic = 1;
}
static void alc662_mode2_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x1b;
spec->autocfg.speaker_pins[0] = 0x14;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_PIN;
spec->ext_mic_pin = 0x18;
spec->int_mic_pin = 0x19;
spec->auto_mic = 1;
}
static void alc663_mode3_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x21;
spec->autocfg.hp_pins[0] = 0x15;
spec->autocfg.speaker_pins[0] = 0x14;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_PIN;
spec->ext_mic_pin = 0x18;
spec->int_mic_pin = 0x19;
spec->auto_mic = 1;
}
static void alc663_mode4_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x21;
spec->autocfg.speaker_pins[0] = 0x14;
spec->autocfg.speaker_pins[1] = 0x16;
spec->automute_mixer_nid[0] = 0x0c;
spec->automute_mixer_nid[1] = 0x0e;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_MIXER;
spec->ext_mic_pin = 0x18;
spec->int_mic_pin = 0x19;
spec->auto_mic = 1;
}
static void alc663_mode5_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x15;
spec->autocfg.speaker_pins[0] = 0x14;
spec->autocfg.speaker_pins[1] = 0x16;
spec->automute_mixer_nid[0] = 0x0c;
spec->automute_mixer_nid[1] = 0x0e;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_MIXER;
spec->ext_mic_pin = 0x18;
spec->int_mic_pin = 0x19;
spec->auto_mic = 1;
}
static void alc663_mode6_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x1b;
spec->autocfg.hp_pins[0] = 0x15;
spec->autocfg.speaker_pins[0] = 0x14;
spec->automute_mixer_nid[0] = 0x0c;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_MIXER;
spec->ext_mic_pin = 0x18;
spec->int_mic_pin = 0x19;
spec->auto_mic = 1;
}
static void alc663_mode7_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x1b;
spec->autocfg.hp_pins[0] = 0x21;
spec->autocfg.speaker_pins[0] = 0x14;
spec->autocfg.speaker_pins[0] = 0x17;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_PIN;
spec->ext_mic_pin = 0x18;
spec->int_mic_pin = 0x19;
spec->auto_mic = 1;
}
static void alc663_mode8_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x21;
spec->autocfg.hp_pins[1] = 0x15;
spec->autocfg.speaker_pins[0] = 0x14;
spec->autocfg.speaker_pins[0] = 0x17;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_PIN;
spec->ext_mic_pin = 0x18;
spec->int_mic_pin = 0x12;
spec->auto_mic = 1;
}
static void alc663_g71v_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x21;
spec->autocfg.line_out_pins[0] = 0x15;
spec->autocfg.speaker_pins[0] = 0x14;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_AMP;
spec->detect_line = 1;
spec->automute_lines = 1;
spec->ext_mic_pin = 0x18;
spec->int_mic_pin = 0x12;
spec->auto_mic = 1;
}
