static void alc880_uniwill_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x14;
spec->autocfg.speaker_pins[0] = 0x15;
spec->autocfg.speaker_pins[0] = 0x16;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_AMP;
}
static void alc880_uniwill_init_hook(struct hda_codec *codec)
{
alc_hp_automute(codec);
alc88x_simple_mic_automute(codec);
}
static void alc880_uniwill_unsol_event(struct hda_codec *codec,
unsigned int res)
{
switch (res >> 28) {
case ALC_MIC_EVENT:
alc88x_simple_mic_automute(codec);
break;
default:
alc_sku_unsol_event(codec, res);
break;
}
}
static void alc880_uniwill_p53_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x14;
spec->autocfg.speaker_pins[0] = 0x15;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_AMP;
}
static void alc880_uniwill_p53_dcvol_automute(struct hda_codec *codec)
{
unsigned int present;
present = snd_hda_codec_read(codec, 0x21, 0,
AC_VERB_GET_VOLUME_KNOB_CONTROL, 0);
present &= HDA_AMP_VOLMASK;
snd_hda_codec_amp_stereo(codec, 0x0c, HDA_OUTPUT, 0,
HDA_AMP_VOLMASK, present);
snd_hda_codec_amp_stereo(codec, 0x0d, HDA_OUTPUT, 0,
HDA_AMP_VOLMASK, present);
}
static void alc880_uniwill_p53_unsol_event(struct hda_codec *codec,
unsigned int res)
{
if ((res >> 28) == ALC_DCVOL_EVENT)
alc880_uniwill_p53_dcvol_automute(codec);
else
alc_sku_unsol_event(codec, res);
}
static void alc880_lg_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x1b;
spec->autocfg.speaker_pins[0] = 0x17;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_AMP;
}
static void alc880_lg_lw_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x1b;
spec->autocfg.speaker_pins[0] = 0x14;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_AMP;
}
static void alc880_medion_rim_automute(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
alc_hp_automute(codec);
if (spec->jack_present)
snd_hda_codec_write(codec, 0x01, 0, AC_VERB_SET_GPIO_DATA, 0);
else
snd_hda_codec_write(codec, 0x01, 0, AC_VERB_SET_GPIO_DATA, 2);
}
static void alc880_medion_rim_unsol_event(struct hda_codec *codec,
unsigned int res)
{
if ((res >> 28) == ALC_HP_EVENT)
alc880_medion_rim_automute(codec);
}
static void alc880_medion_rim_setup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
spec->autocfg.hp_pins[0] = 0x14;
spec->autocfg.speaker_pins[0] = 0x1b;
spec->automute = 1;
spec->automute_mode = ALC_AUTOMUTE_AMP;
}
static int alc_test_pin_ctl_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
static const char * const texts[] = {
"N/A", "Line Out", "HP Out",
"In Hi-Z", "In 50%", "In Grd", "In 80%", "In 100%"
};
uinfo->type = SNDRV_CTL_ELEM_TYPE_ENUMERATED;
uinfo->count = 1;
uinfo->value.enumerated.items = 8;
if (uinfo->value.enumerated.item >= 8)
uinfo->value.enumerated.item = 7;
strcpy(uinfo->value.enumerated.name, texts[uinfo->value.enumerated.item]);
return 0;
}
static int alc_test_pin_ctl_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
hda_nid_t nid = (hda_nid_t)kcontrol->private_value;
unsigned int pin_ctl, item = 0;
pin_ctl = snd_hda_codec_read(codec, nid, 0,
AC_VERB_GET_PIN_WIDGET_CONTROL, 0);
if (pin_ctl & AC_PINCTL_OUT_EN) {
if (pin_ctl & AC_PINCTL_HP_EN)
item = 2;
else
item = 1;
} else if (pin_ctl & AC_PINCTL_IN_EN) {
switch (pin_ctl & AC_PINCTL_VREFEN) {
case AC_PINCTL_VREF_HIZ: item = 3; break;
case AC_PINCTL_VREF_50: item = 4; break;
case AC_PINCTL_VREF_GRD: item = 5; break;
case AC_PINCTL_VREF_80: item = 6; break;
case AC_PINCTL_VREF_100: item = 7; break;
}
}
ucontrol->value.enumerated.item[0] = item;
return 0;
}
static int alc_test_pin_ctl_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
hda_nid_t nid = (hda_nid_t)kcontrol->private_value;
static const unsigned int ctls[] = {
0, AC_PINCTL_OUT_EN, AC_PINCTL_OUT_EN | AC_PINCTL_HP_EN,
AC_PINCTL_IN_EN | AC_PINCTL_VREF_HIZ,
AC_PINCTL_IN_EN | AC_PINCTL_VREF_50,
AC_PINCTL_IN_EN | AC_PINCTL_VREF_GRD,
AC_PINCTL_IN_EN | AC_PINCTL_VREF_80,
AC_PINCTL_IN_EN | AC_PINCTL_VREF_100,
};
unsigned int old_ctl, new_ctl;
old_ctl = snd_hda_codec_read(codec, nid, 0,
AC_VERB_GET_PIN_WIDGET_CONTROL, 0);
new_ctl = ctls[ucontrol->value.enumerated.item[0]];
if (old_ctl != new_ctl) {
int val;
snd_hda_codec_write_cache(codec, nid, 0,
AC_VERB_SET_PIN_WIDGET_CONTROL,
new_ctl);
val = ucontrol->value.enumerated.item[0] >= 3 ?
HDA_AMP_MUTE : 0;
snd_hda_codec_amp_stereo(codec, nid, HDA_OUTPUT, 0,
HDA_AMP_MUTE, val);
return 1;
}
return 0;
}
static int alc_test_pin_src_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
static const char * const texts[] = {
"Front", "Surround", "CLFE", "Side"
};
uinfo->type = SNDRV_CTL_ELEM_TYPE_ENUMERATED;
uinfo->count = 1;
uinfo->value.enumerated.items = 4;
if (uinfo->value.enumerated.item >= 4)
uinfo->value.enumerated.item = 3;
strcpy(uinfo->value.enumerated.name, texts[uinfo->value.enumerated.item]);
return 0;
}
static int alc_test_pin_src_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
hda_nid_t nid = (hda_nid_t)kcontrol->private_value;
unsigned int sel;
sel = snd_hda_codec_read(codec, nid, 0, AC_VERB_GET_CONNECT_SEL, 0);
ucontrol->value.enumerated.item[0] = sel & 3;
return 0;
}
static int alc_test_pin_src_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
hda_nid_t nid = (hda_nid_t)kcontrol->private_value;
unsigned int sel;
sel = snd_hda_codec_read(codec, nid, 0, AC_VERB_GET_CONNECT_SEL, 0) & 3;
if (ucontrol->value.enumerated.item[0] != sel) {
sel = ucontrol->value.enumerated.item[0] & 3;
snd_hda_codec_write_cache(codec, nid, 0,
AC_VERB_SET_CONNECT_SEL, sel);
return 1;
}
return 0;
}
