static void alc268_acer_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x14;
spec->autocfg.speaker_pins[0] = 0x15;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_AMP;
}
static void alc268_acer_lc_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x15;
spec->autocfg.speaker_pins[0] = 0x14;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_AMP;
spec->ext_mic_pin = 0x18;
spec->int_mic_pin = 0x12;
spec->auto_mic = 1;
}
static void alc268_dell_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x15;
spec->autocfg.speaker_pins[0] = 0x14;
spec->ext_mic_pin = 0x18;
spec->int_mic_pin = 0x19;
spec->auto_mic = 1;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_PIN;
}
static void alc267_quanta_il1_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x15;
spec->autocfg.speaker_pins[0] = 0x14;
spec->ext_mic_pin = 0x18;
spec->int_mic_pin = 0x19;
spec->auto_mic = 1;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_PIN;
}
