static hda_nid_t alc680_get_cur_adc(struct hda_codec *codec)
{
static hda_nid_t pins[] = {0x18, 0x19};
static hda_nid_t adcs[] = {0x08, 0x09};
int i;
for (i = 0; i < ARRAY_SIZE(pins); i++) {
if (!is_jack_detectable(codec, pins[i]))
continue;
if (snd_hda_jack_detect(codec, pins[i]))
return adcs[i];
}
return 0x07;
}
static void alc680_rec_autoswitch(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
hda_nid_t nid = alc680_get_cur_adc(codec);
if (spec->cur_adc && nid != spec->cur_adc) {
__snd_hda_codec_cleanup_stream(codec, spec->cur_adc, 1);
spec->cur_adc = nid;
snd_hda_codec_setup_stream(codec, nid,
spec->cur_adc_stream_tag, 0,
spec->cur_adc_format);
}
}
static int alc680_capture_pcm_prepare(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
unsigned int stream_tag,
unsigned int format,
struct snd_pcm_substream *substream)
{
struct alc_spec *spec = codec->spec;
hda_nid_t nid = alc680_get_cur_adc(codec);
spec->cur_adc = nid;
spec->cur_adc_stream_tag = stream_tag;
spec->cur_adc_format = format;
snd_hda_codec_setup_stream(codec, nid, stream_tag, 0, format);
return 0;
}
static int alc680_capture_pcm_cleanup(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
struct snd_pcm_substream *substream)
{
struct alc_spec *spec = codec->spec;
snd_hda_codec_cleanup_stream(codec, spec->cur_adc);
spec->cur_adc = 0;
return 0;
}
static void alc680_base_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x16;
spec->autocfg.speaker_pins[0] = 0x14;
spec->autocfg.speaker_pins[1] = 0x15;
spec->autocfg.num_inputs = 2;
spec->autocfg.inputs[0].pin = 0x18;
spec->autocfg.inputs[0].type = AUTO_PIN_MIC;
spec->autocfg.inputs[1].pin = 0x19;
spec->autocfg.inputs[1].type = AUTO_PIN_LINE_IN;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_AMP;
}
static void alc680_unsol_event(struct hda_codec *codec,
unsigned int res)
{
if ((res >> 26) == ALC_HP_EVENT)
alc_hp_automute(codec);
if ((res >> 26) == ALC_MIC_EVENT)
alc680_rec_autoswitch(codec);
}
static void alc680_inithook(struct hda_codec *codec)
{
alc_hp_automute(codec);
alc680_rec_autoswitch(codec);
}
