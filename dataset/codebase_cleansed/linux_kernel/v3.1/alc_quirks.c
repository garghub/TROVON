static int alc_ch_mode_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct alc_spec *spec = codec->spec;
return snd_hda_ch_mode_info(codec, uinfo, spec->channel_mode,
spec->num_channel_mode);
}
static int alc_ch_mode_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct alc_spec *spec = codec->spec;
return snd_hda_ch_mode_get(codec, ucontrol, spec->channel_mode,
spec->num_channel_mode,
spec->ext_channel_count);
}
static int alc_ch_mode_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct alc_spec *spec = codec->spec;
int err = snd_hda_ch_mode_put(codec, ucontrol, spec->channel_mode,
spec->num_channel_mode,
&spec->ext_channel_count);
if (err >= 0 && !spec->const_channel_count) {
spec->multiout.max_channels = spec->ext_channel_count;
if (spec->need_dac_fix)
spec->multiout.num_dacs = spec->multiout.max_channels / 2;
}
return err;
}
static int alc_pin_mode_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
unsigned int item_num = uinfo->value.enumerated.item;
unsigned char dir = (kcontrol->private_value >> 16) & 0xff;
uinfo->type = SNDRV_CTL_ELEM_TYPE_ENUMERATED;
uinfo->count = 1;
uinfo->value.enumerated.items = alc_pin_mode_n_items(dir);
if (item_num<alc_pin_mode_min(dir) || item_num>alc_pin_mode_max(dir))
item_num = alc_pin_mode_min(dir);
strcpy(uinfo->value.enumerated.name, alc_pin_mode_names[item_num]);
return 0;
}
static int alc_pin_mode_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
unsigned int i;
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
hda_nid_t nid = kcontrol->private_value & 0xffff;
unsigned char dir = (kcontrol->private_value >> 16) & 0xff;
long *valp = ucontrol->value.integer.value;
unsigned int pinctl = snd_hda_codec_read(codec, nid, 0,
AC_VERB_GET_PIN_WIDGET_CONTROL,
0x00);
i = alc_pin_mode_min(dir);
while (i <= alc_pin_mode_max(dir) && alc_pin_mode_values[i] != pinctl)
i++;
*valp = i <= alc_pin_mode_max(dir) ? i: alc_pin_mode_min(dir);
return 0;
}
static int alc_pin_mode_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
signed int change;
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
hda_nid_t nid = kcontrol->private_value & 0xffff;
unsigned char dir = (kcontrol->private_value >> 16) & 0xff;
long val = *ucontrol->value.integer.value;
unsigned int pinctl = snd_hda_codec_read(codec, nid, 0,
AC_VERB_GET_PIN_WIDGET_CONTROL,
0x00);
if (val < alc_pin_mode_min(dir) || val > alc_pin_mode_max(dir))
val = alc_pin_mode_min(dir);
change = pinctl != alc_pin_mode_values[val];
if (change) {
snd_hda_codec_write_cache(codec, nid, 0,
AC_VERB_SET_PIN_WIDGET_CONTROL,
alc_pin_mode_values[val]);
if (val <= 2) {
snd_hda_codec_amp_stereo(codec, nid, HDA_OUTPUT, 0,
HDA_AMP_MUTE, HDA_AMP_MUTE);
snd_hda_codec_amp_stereo(codec, nid, HDA_INPUT, 0,
HDA_AMP_MUTE, 0);
} else {
snd_hda_codec_amp_stereo(codec, nid, HDA_INPUT, 0,
HDA_AMP_MUTE, HDA_AMP_MUTE);
snd_hda_codec_amp_stereo(codec, nid, HDA_OUTPUT, 0,
HDA_AMP_MUTE, 0);
}
}
return change;
}
static int alc_gpio_data_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
hda_nid_t nid = kcontrol->private_value & 0xffff;
unsigned char mask = (kcontrol->private_value >> 16) & 0xff;
long *valp = ucontrol->value.integer.value;
unsigned int val = snd_hda_codec_read(codec, nid, 0,
AC_VERB_GET_GPIO_DATA, 0x00);
*valp = (val & mask) != 0;
return 0;
}
static int alc_gpio_data_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
signed int change;
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
hda_nid_t nid = kcontrol->private_value & 0xffff;
unsigned char mask = (kcontrol->private_value >> 16) & 0xff;
long val = *ucontrol->value.integer.value;
unsigned int gpio_data = snd_hda_codec_read(codec, nid, 0,
AC_VERB_GET_GPIO_DATA,
0x00);
change = (val == 0 ? 0 : mask) != (gpio_data & mask);
if (val == 0)
gpio_data &= ~mask;
else
gpio_data |= mask;
snd_hda_codec_write_cache(codec, nid, 0,
AC_VERB_SET_GPIO_DATA, gpio_data);
return change;
}
static int alc_spdif_ctrl_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
hda_nid_t nid = kcontrol->private_value & 0xffff;
unsigned char mask = (kcontrol->private_value >> 16) & 0xff;
long *valp = ucontrol->value.integer.value;
unsigned int val = snd_hda_codec_read(codec, nid, 0,
AC_VERB_GET_DIGI_CONVERT_1, 0x00);
*valp = (val & mask) != 0;
return 0;
}
static int alc_spdif_ctrl_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
signed int change;
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
hda_nid_t nid = kcontrol->private_value & 0xffff;
unsigned char mask = (kcontrol->private_value >> 16) & 0xff;
long val = *ucontrol->value.integer.value;
unsigned int ctrl_data = snd_hda_codec_read(codec, nid, 0,
AC_VERB_GET_DIGI_CONVERT_1,
0x00);
change = (val == 0 ? 0 : mask) != (ctrl_data & mask);
if (val==0)
ctrl_data &= ~mask;
else
ctrl_data |= mask;
snd_hda_codec_write_cache(codec, nid, 0, AC_VERB_SET_DIGI_CONVERT_1,
ctrl_data);
return change;
}
static int alc_eapd_ctrl_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
hda_nid_t nid = kcontrol->private_value & 0xffff;
unsigned char mask = (kcontrol->private_value >> 16) & 0xff;
long *valp = ucontrol->value.integer.value;
unsigned int val = snd_hda_codec_read(codec, nid, 0,
AC_VERB_GET_EAPD_BTLENABLE, 0x00);
*valp = (val & mask) != 0;
return 0;
}
static int alc_eapd_ctrl_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
int change;
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
hda_nid_t nid = kcontrol->private_value & 0xffff;
unsigned char mask = (kcontrol->private_value >> 16) & 0xff;
long val = *ucontrol->value.integer.value;
unsigned int ctrl_data = snd_hda_codec_read(codec, nid, 0,
AC_VERB_GET_EAPD_BTLENABLE,
0x00);
change = (!val ? 0 : mask) != (ctrl_data & mask);
if (!val)
ctrl_data &= ~mask;
else
ctrl_data |= mask;
snd_hda_codec_write_cache(codec, nid, 0, AC_VERB_SET_EAPD_BTLENABLE,
ctrl_data);
return change;
}
static void alc_fixup_autocfg_pin_nums(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
struct auto_pin_cfg *cfg = &spec->autocfg;
if (!cfg->line_outs) {
while (cfg->line_outs < AUTO_CFG_MAX_OUTS &&
cfg->line_out_pins[cfg->line_outs])
cfg->line_outs++;
}
if (!cfg->speaker_outs) {
while (cfg->speaker_outs < AUTO_CFG_MAX_OUTS &&
cfg->speaker_pins[cfg->speaker_outs])
cfg->speaker_outs++;
}
if (!cfg->hp_outs) {
while (cfg->hp_outs < AUTO_CFG_MAX_OUTS &&
cfg->hp_pins[cfg->hp_outs])
cfg->hp_outs++;
}
}
static void setup_preset(struct hda_codec *codec,
const struct alc_config_preset *preset)
{
struct alc_spec *spec = codec->spec;
int i;
for (i = 0; i < ARRAY_SIZE(preset->mixers) && preset->mixers[i]; i++)
add_mixer(spec, preset->mixers[i]);
spec->cap_mixer = preset->cap_mixer;
for (i = 0; i < ARRAY_SIZE(preset->init_verbs) && preset->init_verbs[i];
i++)
add_verb(spec, preset->init_verbs[i]);
spec->channel_mode = preset->channel_mode;
spec->num_channel_mode = preset->num_channel_mode;
spec->need_dac_fix = preset->need_dac_fix;
spec->const_channel_count = preset->const_channel_count;
if (preset->const_channel_count)
spec->multiout.max_channels = preset->const_channel_count;
else
spec->multiout.max_channels = spec->channel_mode[0].channels;
spec->ext_channel_count = spec->channel_mode[0].channels;
spec->multiout.num_dacs = preset->num_dacs;
spec->multiout.dac_nids = preset->dac_nids;
spec->multiout.dig_out_nid = preset->dig_out_nid;
spec->multiout.slave_dig_outs = preset->slave_dig_outs;
spec->multiout.hp_nid = preset->hp_nid;
spec->num_mux_defs = preset->num_mux_defs;
if (!spec->num_mux_defs)
spec->num_mux_defs = 1;
spec->input_mux = preset->input_mux;
spec->num_adc_nids = preset->num_adc_nids;
spec->adc_nids = preset->adc_nids;
spec->capsrc_nids = preset->capsrc_nids;
spec->dig_in_nid = preset->dig_in_nid;
spec->unsol_event = preset->unsol_event;
spec->init_hook = preset->init_hook;
#ifdef CONFIG_SND_HDA_POWER_SAVE
spec->power_hook = preset->power_hook;
spec->loopback.amplist = preset->loopbacks;
#endif
if (preset->setup)
preset->setup(codec);
alc_fixup_autocfg_pin_nums(codec);
}
static void alc88x_simple_mic_automute(struct hda_codec *codec)
{
unsigned int present;
unsigned char bits;
present = snd_hda_jack_detect(codec, 0x18);
bits = present ? HDA_AMP_MUTE : 0;
snd_hda_codec_amp_stereo(codec, 0x0b, HDA_INPUT, 1, HDA_AMP_MUTE, bits);
}
