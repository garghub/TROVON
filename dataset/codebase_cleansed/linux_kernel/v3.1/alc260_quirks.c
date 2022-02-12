static void alc260_hp_master_update(struct hda_codec *codec)
{
update_speakers(codec);
}
static int alc260_hp_master_sw_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct alc_spec *spec = codec->spec;
*ucontrol->value.integer.value = !spec->master_mute;
return 0;
}
static int alc260_hp_master_sw_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct alc_spec *spec = codec->spec;
int val = !*ucontrol->value.integer.value;
if (val == spec->master_mute)
return 0;
spec->master_mute = val;
alc260_hp_master_update(codec);
return 1;
}
static void alc260_hp_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x0f;
spec->autocfg.speaker_pins[0] = 0x10;
spec->autocfg.speaker_pins[1] = 0x11;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_PIN;
}
static void alc260_hp_3013_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x15;
spec->autocfg.speaker_pins[0] = 0x10;
spec->autocfg.speaker_pins[1] = 0x11;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_PIN;
}
static void alc260_hp_3012_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x10;
spec->autocfg.speaker_pins[0] = 0x0f;
spec->autocfg.speaker_pins[1] = 0x11;
spec->autocfg.speaker_pins[2] = 0x15;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_PIN;
}
static void alc260_replacer_672v_automute(struct hda_codec *codec)
{
unsigned int present;
present = snd_hda_jack_detect(codec, 0x0f);
if (present) {
snd_hda_codec_write_cache(codec, 0x01, 0,
AC_VERB_SET_GPIO_DATA, 1);
snd_hda_codec_write_cache(codec, 0x0f, 0,
AC_VERB_SET_PIN_WIDGET_CONTROL,
PIN_HP);
} else {
snd_hda_codec_write_cache(codec, 0x01, 0,
AC_VERB_SET_GPIO_DATA, 0);
snd_hda_codec_write_cache(codec, 0x0f, 0,
AC_VERB_SET_PIN_WIDGET_CONTROL,
PIN_OUT);
}
}
static void alc260_replacer_672v_unsol_event(struct hda_codec *codec,
unsigned int res)
{
if ((res >> 26) == ALC_HP_EVENT)
alc260_replacer_672v_automute(codec);
}
