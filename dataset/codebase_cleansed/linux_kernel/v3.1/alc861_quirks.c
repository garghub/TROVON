static void alc861_toshiba_automute(struct hda_codec *codec)
{
unsigned int present = snd_hda_jack_detect(codec, 0x0f);
snd_hda_codec_amp_stereo(codec, 0x16, HDA_INPUT, 0,
HDA_AMP_MUTE, present ? HDA_AMP_MUTE : 0);
snd_hda_codec_amp_stereo(codec, 0x1a, HDA_INPUT, 3,
HDA_AMP_MUTE, present ? 0 : HDA_AMP_MUTE);
}
static void alc861_toshiba_unsol_event(struct hda_codec *codec,
unsigned int res)
{
if ((res >> 26) == ALC_HP_EVENT)
alc861_toshiba_automute(codec);
}
