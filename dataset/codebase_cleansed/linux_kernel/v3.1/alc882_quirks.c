static void alc889_automute_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x15;
spec->autocfg.speaker_pins[0] = 0x14;
spec->autocfg.speaker_pins[1] = 0x16;
spec->autocfg.speaker_pins[2] = 0x17;
spec->autocfg.speaker_pins[3] = 0x19;
spec->autocfg.speaker_pins[4] = 0x1a;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_AMP;
}
static void alc889_intel_init_hook(struct hda_codec *codec)
{
alc889_coef_init(codec);
alc_hp_automute(codec);
}
static void alc888_fujitsu_xa3530_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x17;
spec->autocfg.hp_pins[1] = 0x1b;
spec->autocfg.speaker_pins[0] = 0x14;
spec->autocfg.speaker_pins[1] = 0x15;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_AMP;
}
static void alc888_acer_aspire_4930g_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x15;
spec->autocfg.speaker_pins[0] = 0x14;
spec->autocfg.speaker_pins[1] = 0x16;
spec->autocfg.speaker_pins[2] = 0x17;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_AMP;
}
static void alc888_acer_aspire_6530g_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x15;
spec->autocfg.speaker_pins[0] = 0x14;
spec->autocfg.speaker_pins[1] = 0x16;
spec->autocfg.speaker_pins[2] = 0x17;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_AMP;
}
static void alc888_acer_aspire_7730g_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x15;
spec->autocfg.speaker_pins[0] = 0x14;
spec->autocfg.speaker_pins[1] = 0x16;
spec->autocfg.speaker_pins[2] = 0x17;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_AMP;
}
static void alc889_acer_aspire_8930g_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x15;
spec->autocfg.speaker_pins[0] = 0x14;
spec->autocfg.speaker_pins[1] = 0x16;
spec->autocfg.speaker_pins[2] = 0x1b;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_AMP;
}
static void alc885_imac24_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x14;
spec->autocfg.speaker_pins[0] = 0x18;
spec->autocfg.speaker_pins[1] = 0x1a;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_AMP;
}
static void alc885_mba21_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x14;
spec->autocfg.speaker_pins[0] = 0x18;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_AMP;
}
static void alc885_mbp3_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x15;
spec->autocfg.speaker_pins[0] = 0x14;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_AMP;
}
static void alc885_imac91_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x14;
spec->autocfg.speaker_pins[0] = 0x18;
spec->autocfg.speaker_pins[1] = 0x1a;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_AMP;
}
static void alc882_targa_automute(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
alc_hp_automute(codec);
snd_hda_codec_write_cache(codec, 1, 0, AC_VERB_SET_GPIO_DATA,
spec->jack_present ? 1 : 3);
}
static void alc882_targa_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x14;
spec->autocfg.speaker_pins[0] = 0x1b;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_AMP;
}
static void alc882_targa_unsol_event(struct hda_codec *codec, unsigned int res)
{
if ((res >> 26) == ALC_HP_EVENT)
alc882_targa_automute(codec);
}
static void alc882_gpio_mute(struct hda_codec *codec, int pin, int muted)
{
unsigned int gpiostate, gpiomask, gpiodir;
gpiostate = snd_hda_codec_read(codec, codec->afg, 0,
AC_VERB_GET_GPIO_DATA, 0);
if (!muted)
gpiostate |= (1 << pin);
else
gpiostate &= ~(1 << pin);
gpiomask = snd_hda_codec_read(codec, codec->afg, 0,
AC_VERB_GET_GPIO_MASK, 0);
gpiomask |= (1 << pin);
gpiodir = snd_hda_codec_read(codec, codec->afg, 0,
AC_VERB_GET_GPIO_DIRECTION, 0);
gpiodir |= (1 << pin);
snd_hda_codec_write(codec, codec->afg, 0,
AC_VERB_SET_GPIO_MASK, gpiomask);
snd_hda_codec_write(codec, codec->afg, 0,
AC_VERB_SET_GPIO_DIRECTION, gpiodir);
msleep(1);
snd_hda_codec_write(codec, codec->afg, 0,
AC_VERB_SET_GPIO_DATA, gpiostate);
}
static void alc885_macpro_init_hook(struct hda_codec *codec)
{
alc882_gpio_mute(codec, 0, 0);
alc882_gpio_mute(codec, 1, 0);
}
static void alc885_imac24_init_hook(struct hda_codec *codec)
{
alc885_macpro_init_hook(codec);
alc_hp_automute(codec);
}
static void alc883_medion_wim2160_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x1a;
spec->autocfg.speaker_pins[0] = 0x15;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_AMP;
}
static void alc883_mitac_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x15;
spec->autocfg.speaker_pins[0] = 0x14;
spec->autocfg.speaker_pins[1] = 0x17;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_AMP;
}
static void alc888_3st_hp_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x1b;
spec->autocfg.speaker_pins[0] = 0x14;
spec->autocfg.speaker_pins[1] = 0x16;
spec->autocfg.speaker_pins[2] = 0x18;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_AMP;
}
static void alc888_lenovo_ms7195_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x1b;
spec->autocfg.line_out_pins[0] = 0x14;
spec->autocfg.speaker_pins[0] = 0x15;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_AMP;
}
static void alc883_lenovo_nb0763_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x14;
spec->autocfg.speaker_pins[0] = 0x15;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_AMP;
}
static void alc883_clevo_m720_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x15;
spec->autocfg.speaker_pins[0] = 0x14;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_AMP;
}
static void alc883_clevo_m720_init_hook(struct hda_codec *codec)
{
alc_hp_automute(codec);
alc88x_simple_mic_automute(codec);
}
static void alc883_clevo_m720_unsol_event(struct hda_codec *codec,
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
static void alc883_2ch_fujitsu_pi2515_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x14;
spec->autocfg.speaker_pins[0] = 0x15;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_AMP;
}
static void alc883_haier_w66_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x1b;
spec->autocfg.speaker_pins[0] = 0x14;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_AMP;
}
static void alc883_lenovo_101e_setup(struct hda_codec *codec)
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
static void alc883_acer_aspire_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x14;
spec->autocfg.speaker_pins[0] = 0x15;
spec->autocfg.speaker_pins[1] = 0x16;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_AMP;
}
static void alc888_6st_dell_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x1b;
spec->autocfg.speaker_pins[0] = 0x14;
spec->autocfg.speaker_pins[1] = 0x15;
spec->autocfg.speaker_pins[2] = 0x16;
spec->autocfg.speaker_pins[3] = 0x17;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_AMP;
}
static void alc888_lenovo_sky_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x1b;
spec->autocfg.speaker_pins[0] = 0x14;
spec->autocfg.speaker_pins[1] = 0x15;
spec->autocfg.speaker_pins[2] = 0x16;
spec->autocfg.speaker_pins[3] = 0x17;
spec->autocfg.speaker_pins[4] = 0x1a;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_AMP;
}
static void alc883_vaiott_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x15;
spec->autocfg.speaker_pins[0] = 0x14;
spec->autocfg.speaker_pins[1] = 0x17;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_AMP;
}
static void alc883_mode2_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x1b;
spec->autocfg.speaker_pins[0] = 0x14;
spec->autocfg.speaker_pins[1] = 0x15;
spec->autocfg.speaker_pins[2] = 0x16;
spec->ext_mic_pin = 0x18;
spec->int_mic_pin = 0x19;
spec->auto_mic = 1;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_AMP;
}
static void alc883_eee1601_inithook(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x14;
spec->autocfg.speaker_pins[0] = 0x1b;
alc_hp_automute(codec);
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
