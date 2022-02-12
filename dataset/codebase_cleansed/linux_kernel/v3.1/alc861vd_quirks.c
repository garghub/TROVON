static void alc861vd_lenovo_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x1b;
spec->autocfg.speaker_pins[0] = 0x14;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_AMP;
}
static void alc861vd_lenovo_init_hook(struct hda_codec *codec)
{
alc_hp_automute(codec);
alc88x_simple_mic_automute(codec);
}
static void alc861vd_lenovo_unsol_event(struct hda_codec *codec,
unsigned int res)
{
switch (res >> 26) {
case ALC_MIC_EVENT:
alc88x_simple_mic_automute(codec);
break;
default:
alc_sku_unsol_event(codec, res);
break;
}
}
static void alc861vd_dallas_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x15;
spec->autocfg.speaker_pins[0] = 0x14;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_AMP;
}
