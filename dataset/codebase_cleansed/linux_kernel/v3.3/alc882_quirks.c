static void alc885_imac24_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x14;
spec->autocfg.speaker_pins[0] = 0x18;
spec->autocfg.speaker_pins[1] = 0x1a;
alc_simple_setup_automute(spec, ALC_AUTOMUTE_AMP);
}
static void alc885_mba21_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x14;
spec->autocfg.speaker_pins[0] = 0x18;
alc_simple_setup_automute(spec, ALC_AUTOMUTE_AMP);
}
static void alc885_mbp3_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x15;
spec->autocfg.speaker_pins[0] = 0x14;
alc_simple_setup_automute(spec, ALC_AUTOMUTE_AMP);
}
static void alc885_imac91_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x14;
spec->autocfg.speaker_pins[0] = 0x18;
spec->autocfg.speaker_pins[1] = 0x1a;
alc_simple_setup_automute(spec, ALC_AUTOMUTE_AMP);
}
static void alc889A_mb31_automute(struct hda_codec *codec)
{
unsigned int present;
if (snd_hda_codec_read(codec, 0x15, 0, AC_VERB_GET_CONNECT_SEL, 0)
== 0x00) {
present = snd_hda_jack_detect(codec, 0x15);
snd_hda_codec_amp_stereo(codec, 0x14, HDA_OUTPUT, 0,
HDA_AMP_MUTE, present ? HDA_AMP_MUTE : 0);
snd_hda_codec_amp_stereo(codec, 0x16, HDA_OUTPUT, 0,
HDA_AMP_MUTE, present ? HDA_AMP_MUTE : 0);
}
}
static void alc889A_mb31_unsol_event(struct hda_codec *codec, unsigned int res)
{
if ((res >> 26) == ALC_HP_EVENT)
alc889A_mb31_automute(codec);
}
static void alc882_unsol_event(struct hda_codec *codec, unsigned int res)
{
alc_exec_unsol_event(codec, res >> 26);
}
