static void alc269_quanta_fl1_speaker_automute(struct hda_codec *codec)
{
alc_hp_automute(codec);
snd_hda_codec_write(codec, 0x20, 0,
AC_VERB_SET_COEF_INDEX, 0x0c);
snd_hda_codec_write(codec, 0x20, 0,
AC_VERB_SET_PROC_COEF, 0x680);
snd_hda_codec_write(codec, 0x20, 0,
AC_VERB_SET_COEF_INDEX, 0x0c);
snd_hda_codec_write(codec, 0x20, 0,
AC_VERB_SET_PROC_COEF, 0x480);
}
static void alc269_lifebook_mic_autoswitch(struct hda_codec *codec)
{
unsigned int present_laptop;
unsigned int present_dock;
present_laptop = snd_hda_jack_detect(codec, 0x18);
present_dock = snd_hda_jack_detect(codec, 0x1b);
if (present_dock)
snd_hda_codec_write(codec, 0x23, 0,
AC_VERB_SET_CONNECT_SEL, 0x3);
if (present_laptop)
snd_hda_codec_write(codec, 0x23, 0,
AC_VERB_SET_CONNECT_SEL, 0x0);
if (!present_dock && !present_laptop)
snd_hda_codec_write(codec, 0x23, 0,
AC_VERB_SET_CONNECT_SEL, 0x1);
}
static void alc269_quanta_fl1_unsol_event(struct hda_codec *codec,
unsigned int res)
{
switch (res >> 26) {
case ALC_HP_EVENT:
alc269_quanta_fl1_speaker_automute(codec);
break;
case ALC_MIC_EVENT:
alc_mic_automute(codec);
break;
}
}
static void alc269_lifebook_unsol_event(struct hda_codec *codec,
unsigned int res)
{
if ((res >> 26) == ALC_HP_EVENT)
alc269_lifebook_speaker_automute(codec);
if ((res >> 26) == ALC_MIC_EVENT)
alc269_lifebook_mic_autoswitch(codec);
}
static void alc269_quanta_fl1_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x15;
spec->autocfg.speaker_pins[0] = 0x14;
spec->automute_mixer_nid[0] = 0x0c;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_MIXER;
spec->ext_mic_pin = 0x18;
spec->int_mic_pin = 0x19;
spec->auto_mic = 1;
}
static void alc269_quanta_fl1_init_hook(struct hda_codec *codec)
{
alc269_quanta_fl1_speaker_automute(codec);
alc_mic_automute(codec);
}
static void alc269_lifebook_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x15;
spec->autocfg.hp_pins[1] = 0x1a;
spec->autocfg.speaker_pins[0] = 0x14;
spec->automute_mixer_nid[0] = 0x0c;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_MIXER;
}
static void alc269_lifebook_init_hook(struct hda_codec *codec)
{
alc269_lifebook_speaker_automute(codec);
alc269_lifebook_mic_autoswitch(codec);
}
static void alc269_laptop_amic_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x15;
spec->autocfg.speaker_pins[0] = 0x14;
spec->automute_mixer_nid[0] = 0x0c;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_MIXER;
spec->ext_mic_pin = 0x18;
spec->int_mic_pin = 0x19;
spec->auto_mic = 1;
}
static void alc269_laptop_dmic_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x15;
spec->autocfg.speaker_pins[0] = 0x14;
spec->automute_mixer_nid[0] = 0x0c;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_MIXER;
spec->ext_mic_pin = 0x18;
spec->int_mic_pin = 0x12;
spec->auto_mic = 1;
}
static void alc269vb_laptop_amic_setup(struct hda_codec *codec)
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
static void alc269vb_laptop_dmic_setup(struct hda_codec *codec)
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
