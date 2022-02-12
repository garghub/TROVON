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
