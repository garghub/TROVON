static inline int cs_vendor_coef_get(struct hda_codec *codec, unsigned int idx)
{
struct cs_spec *spec = codec->spec;
snd_hda_codec_write(codec, spec->vendor_nid, 0,
AC_VERB_SET_COEF_INDEX, idx);
return snd_hda_codec_read(codec, spec->vendor_nid, 0,
AC_VERB_GET_PROC_COEF, 0);
}
static inline void cs_vendor_coef_set(struct hda_codec *codec, unsigned int idx,
unsigned int coef)
{
struct cs_spec *spec = codec->spec;
snd_hda_codec_write(codec, spec->vendor_nid, 0,
AC_VERB_SET_COEF_INDEX, idx);
snd_hda_codec_write(codec, spec->vendor_nid, 0,
AC_VERB_SET_PROC_COEF, coef);
}
static void cs_automute(struct hda_codec *codec)
{
struct cs_spec *spec = codec->spec;
spec->gen.master_mute = !!(spec->spdif_present && spec->sense_b);
snd_hda_gen_update_outputs(codec);
if (spec->gpio_eapd_hp || spec->gpio_eapd_speaker) {
spec->gpio_data = spec->gen.hp_jack_present ?
spec->gpio_eapd_hp : spec->gpio_eapd_speaker;
snd_hda_codec_write(codec, 0x01, 0,
AC_VERB_SET_GPIO_DATA, spec->gpio_data);
}
}
static bool is_active_pin(struct hda_codec *codec, hda_nid_t nid)
{
unsigned int val;
val = snd_hda_codec_get_pincfg(codec, nid);
return (get_defcfg_connect(val) != AC_JACK_PORT_NONE);
}
static void init_input_coef(struct hda_codec *codec)
{
struct cs_spec *spec = codec->spec;
unsigned int coef;
if (spec->vendor_nid == CS420X_VENDOR_NID) {
coef = cs_vendor_coef_get(codec, IDX_BEEP_CFG);
if (is_active_pin(codec, CS_DMIC2_PIN_NID))
coef |= 1 << 4;
if (is_active_pin(codec, CS_DMIC1_PIN_NID))
coef |= 1 << 3;
cs_vendor_coef_set(codec, IDX_BEEP_CFG, coef);
}
}
static void init_digital_coef(struct hda_codec *codec)
{
unsigned int coef;
coef = 0x0002;
coef |= 0x0008;
if (is_active_pin(codec, CS_DIG_OUT2_PIN_NID))
coef |= 0x4000;
cs_vendor_coef_set(codec, IDX_SPDIF_CTL, coef);
}
static int cs_init(struct hda_codec *codec)
{
struct cs_spec *spec = codec->spec;
if (spec->vendor_nid == CS420X_VENDOR_NID) {
snd_hda_sequence_write(codec, cs_errata_init_verbs);
snd_hda_sequence_write(codec, cs_coef_init_verbs);
} else if (spec->vendor_nid == CS4208_VENDOR_NID) {
snd_hda_sequence_write(codec, cs4208_coef_init_verbs);
}
snd_hda_gen_init(codec);
if (spec->gpio_mask) {
snd_hda_codec_write(codec, 0x01, 0, AC_VERB_SET_GPIO_MASK,
spec->gpio_mask);
snd_hda_codec_write(codec, 0x01, 0, AC_VERB_SET_GPIO_DIRECTION,
spec->gpio_dir);
snd_hda_codec_write(codec, 0x01, 0, AC_VERB_SET_GPIO_DATA,
spec->gpio_data);
}
if (spec->vendor_nid == CS420X_VENDOR_NID) {
init_input_coef(codec);
init_digital_coef(codec);
}
return 0;
}
static int cs_build_controls(struct hda_codec *codec)
{
int err;
err = snd_hda_gen_build_controls(codec);
if (err < 0)
return err;
snd_hda_apply_fixup(codec, HDA_FIXUP_ACT_BUILD);
return 0;
}
static int cs_parse_auto_config(struct hda_codec *codec)
{
struct cs_spec *spec = codec->spec;
int err;
err = snd_hda_parse_pin_defcfg(codec, &spec->gen.autocfg, NULL, 0);
if (err < 0)
return err;
err = snd_hda_gen_parse_auto_config(codec, &spec->gen.autocfg);
if (err < 0)
return err;
return 0;
}
static void cs420x_fixup_gpio_13(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
if (action == HDA_FIXUP_ACT_PRE_PROBE) {
struct cs_spec *spec = codec->spec;
spec->gpio_eapd_hp = 2;
spec->gpio_eapd_speaker = 8;
spec->gpio_mask = spec->gpio_dir =
spec->gpio_eapd_hp | spec->gpio_eapd_speaker;
}
}
static void cs420x_fixup_gpio_23(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
if (action == HDA_FIXUP_ACT_PRE_PROBE) {
struct cs_spec *spec = codec->spec;
spec->gpio_eapd_hp = 4;
spec->gpio_eapd_speaker = 8;
spec->gpio_mask = spec->gpio_dir =
spec->gpio_eapd_hp | spec->gpio_eapd_speaker;
}
}
static struct cs_spec *cs_alloc_spec(struct hda_codec *codec, int vendor_nid)
{
struct cs_spec *spec;
spec = kzalloc(sizeof(*spec), GFP_KERNEL);
if (!spec)
return NULL;
codec->spec = spec;
spec->vendor_nid = vendor_nid;
snd_hda_gen_spec_init(&spec->gen);
return spec;
}
static int patch_cs420x(struct hda_codec *codec)
{
struct cs_spec *spec;
int err;
spec = cs_alloc_spec(codec, CS420X_VENDOR_NID);
if (!spec)
return -ENOMEM;
spec->gen.automute_hook = cs_automute;
codec->single_adc_amp = 1;
snd_hda_pick_fixup(codec, cs420x_models, cs420x_fixup_tbl,
cs420x_fixups);
snd_hda_apply_fixup(codec, HDA_FIXUP_ACT_PRE_PROBE);
err = cs_parse_auto_config(codec);
if (err < 0)
goto error;
codec->patch_ops = cs_patch_ops;
snd_hda_apply_fixup(codec, HDA_FIXUP_ACT_PROBE);
return 0;
error:
cs_free(codec);
return err;
}
static void cs4208_fixup_gpio0(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
if (action == HDA_FIXUP_ACT_PRE_PROBE) {
struct cs_spec *spec = codec->spec;
spec->gpio_eapd_hp = 0;
spec->gpio_eapd_speaker = 1;
spec->gpio_mask = spec->gpio_dir =
spec->gpio_eapd_hp | spec->gpio_eapd_speaker;
}
}
static void cs4208_fixup_mac(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
if (action != HDA_FIXUP_ACT_PRE_PROBE)
return;
codec->fixup_id = HDA_FIXUP_ID_NOT_SET;
snd_hda_pick_fixup(codec, NULL, cs4208_mac_fixup_tbl, cs4208_fixups);
if (codec->fixup_id == HDA_FIXUP_ID_NOT_SET)
codec->fixup_id = CS4208_GPIO0;
snd_hda_apply_fixup(codec, action);
}
static int cs4208_spdif_sw_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct cs_spec *spec = codec->spec;
hda_nid_t pin = spec->gen.autocfg.dig_out_pins[0];
int pinctl = ucontrol->value.integer.value[0] ? PIN_OUT : 0;
snd_hda_set_pin_ctl_cache(codec, pin, pinctl);
return spec->spdif_sw_put(kcontrol, ucontrol);
}
static void cs4208_fixup_spdif_switch(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
if (action == HDA_FIXUP_ACT_BUILD) {
struct cs_spec *spec = codec->spec;
struct snd_kcontrol *kctl;
if (!spec->gen.autocfg.dig_out_pins[0])
return;
kctl = snd_hda_find_mixer_ctl(codec, "IEC958 Playback Switch");
if (!kctl)
return;
spec->spdif_sw_put = kctl->put;
kctl->put = cs4208_spdif_sw_put;
}
}
static void cs4208_fix_amp_caps(struct hda_codec *codec, hda_nid_t adc)
{
unsigned int caps;
caps = query_amp_caps(codec, adc, HDA_INPUT);
caps &= ~(AC_AMPCAP_OFFSET);
caps |= 0x02;
snd_hda_override_amp_caps(codec, adc, HDA_INPUT, caps);
}
static int patch_cs4208(struct hda_codec *codec)
{
struct cs_spec *spec;
int err;
spec = cs_alloc_spec(codec, CS4208_VENDOR_NID);
if (!spec)
return -ENOMEM;
spec->gen.automute_hook = cs_automute;
spec->gen.out_vol_mask = 1ULL << 0x10;
snd_hda_pick_fixup(codec, cs4208_models, cs4208_fixup_tbl,
cs4208_fixups);
snd_hda_apply_fixup(codec, HDA_FIXUP_ACT_PRE_PROBE);
snd_hda_override_wcaps(codec, 0x18,
get_wcaps(codec, 0x18) | AC_WCAP_STEREO);
cs4208_fix_amp_caps(codec, 0x18);
cs4208_fix_amp_caps(codec, 0x1b);
cs4208_fix_amp_caps(codec, 0x1c);
err = cs_parse_auto_config(codec);
if (err < 0)
goto error;
codec->patch_ops = cs_patch_ops;
snd_hda_apply_fixup(codec, HDA_FIXUP_ACT_PROBE);
return 0;
error:
cs_free(codec);
return err;
}
static void cs421x_fixup_sense_b(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
struct cs_spec *spec = codec->spec;
if (action == HDA_FIXUP_ACT_PRE_PROBE)
spec->sense_b = 1;
}
static int cs421x_boost_vol_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = 1;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = 3;
return 0;
}
static int cs421x_boost_vol_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
ucontrol->value.integer.value[0] =
cs_vendor_coef_get(codec, CS421X_IDX_SPK_CTL) & 0x0003;
return 0;
}
static int cs421x_boost_vol_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
unsigned int vol = ucontrol->value.integer.value[0];
unsigned int coef =
cs_vendor_coef_get(codec, CS421X_IDX_SPK_CTL);
unsigned int original_coef = coef;
coef &= ~0x0003;
coef |= (vol & 0x0003);
if (original_coef == coef)
return 0;
else {
cs_vendor_coef_set(codec, CS421X_IDX_SPK_CTL, coef);
return 1;
}
}
static void cs4210_pinmux_init(struct hda_codec *codec)
{
struct cs_spec *spec = codec->spec;
unsigned int def_conf, coef;
coef = cs_vendor_coef_get(codec, CS421X_IDX_DEV_CFG);
if (spec->gpio_mask)
coef |= 0x0008;
else
coef &= ~0x0008;
if (spec->sense_b)
coef |= 0x0010;
else
coef &= ~0x0010;
cs_vendor_coef_set(codec, CS421X_IDX_DEV_CFG, coef);
if ((spec->gpio_mask || spec->sense_b) &&
is_active_pin(codec, CS421X_DMIC_PIN_NID)) {
def_conf = snd_hda_codec_get_pincfg(codec, CS421X_DMIC_PIN_NID);
def_conf &= ~AC_DEFCFG_PORT_CONN;
def_conf |= (AC_JACK_PORT_NONE << AC_DEFCFG_PORT_CONN_SHIFT);
snd_hda_codec_set_pincfg(codec, CS421X_DMIC_PIN_NID, def_conf);
}
}
static void cs4210_spdif_automute(struct hda_codec *codec,
struct hda_jack_callback *tbl)
{
struct cs_spec *spec = codec->spec;
bool spdif_present = false;
hda_nid_t spdif_pin = spec->gen.autocfg.dig_out_pins[0];
if (!spec->spdif_detect ||
spec->vendor_nid != CS4210_VENDOR_NID)
return;
spdif_present = snd_hda_jack_detect(codec, spdif_pin);
if (spdif_present == spec->spdif_present)
return;
spec->spdif_present = spdif_present;
if (spdif_present)
snd_hda_set_pin_ctl(codec, spdif_pin,
spdif_present ? PIN_OUT : 0);
cs_automute(codec);
}
static void parse_cs421x_digital(struct hda_codec *codec)
{
struct cs_spec *spec = codec->spec;
struct auto_pin_cfg *cfg = &spec->gen.autocfg;
int i;
for (i = 0; i < cfg->dig_outs; i++) {
hda_nid_t nid = cfg->dig_out_pins[i];
if (get_wcaps(codec, nid) & AC_WCAP_UNSOL_CAP) {
spec->spdif_detect = 1;
snd_hda_jack_detect_enable_callback(codec, nid,
cs4210_spdif_automute);
}
}
}
static int cs421x_init(struct hda_codec *codec)
{
struct cs_spec *spec = codec->spec;
if (spec->vendor_nid == CS4210_VENDOR_NID) {
snd_hda_sequence_write(codec, cs421x_coef_init_verbs);
snd_hda_sequence_write(codec, cs421x_coef_init_verbs_A1_silicon_fixes);
cs4210_pinmux_init(codec);
}
snd_hda_gen_init(codec);
if (spec->gpio_mask) {
snd_hda_codec_write(codec, 0x01, 0, AC_VERB_SET_GPIO_MASK,
spec->gpio_mask);
snd_hda_codec_write(codec, 0x01, 0, AC_VERB_SET_GPIO_DIRECTION,
spec->gpio_dir);
snd_hda_codec_write(codec, 0x01, 0, AC_VERB_SET_GPIO_DATA,
spec->gpio_data);
}
init_input_coef(codec);
cs4210_spdif_automute(codec, NULL);
return 0;
}
static int cs421x_build_controls(struct hda_codec *codec)
{
struct cs_spec *spec = codec->spec;
int err;
err = snd_hda_gen_build_controls(codec);
if (err < 0)
return err;
if (spec->gen.autocfg.speaker_outs &&
spec->vendor_nid == CS4210_VENDOR_NID) {
err = snd_hda_ctl_add(codec, 0,
snd_ctl_new1(&cs421x_speaker_boost_ctl, codec));
if (err < 0)
return err;
}
return 0;
}
static void fix_volume_caps(struct hda_codec *codec, hda_nid_t dac)
{
unsigned int caps;
caps = query_amp_caps(codec, dac, HDA_OUTPUT);
caps &= ~(0x7f << AC_AMPCAP_NUM_STEPS_SHIFT);
caps |= ((caps >> AC_AMPCAP_OFFSET_SHIFT) & 0x7f)
<< AC_AMPCAP_NUM_STEPS_SHIFT;
snd_hda_override_amp_caps(codec, dac, HDA_OUTPUT, caps);
}
static int cs421x_parse_auto_config(struct hda_codec *codec)
{
struct cs_spec *spec = codec->spec;
hda_nid_t dac = CS4210_DAC_NID;
int err;
fix_volume_caps(codec, dac);
err = snd_hda_parse_pin_defcfg(codec, &spec->gen.autocfg, NULL, 0);
if (err < 0)
return err;
err = snd_hda_gen_parse_auto_config(codec, &spec->gen.autocfg);
if (err < 0)
return err;
parse_cs421x_digital(codec);
return 0;
}
static int cs421x_suspend(struct hda_codec *codec)
{
struct cs_spec *spec = codec->spec;
unsigned int coef;
snd_hda_shutup_pins(codec);
snd_hda_codec_write(codec, CS4210_DAC_NID, 0,
AC_VERB_SET_POWER_STATE, AC_PWRST_D3);
snd_hda_codec_write(codec, CS4210_ADC_NID, 0,
AC_VERB_SET_POWER_STATE, AC_PWRST_D3);
if (spec->vendor_nid == CS4210_VENDOR_NID) {
coef = cs_vendor_coef_get(codec, CS421X_IDX_DEV_CFG);
coef |= 0x0004;
cs_vendor_coef_set(codec, CS421X_IDX_DEV_CFG, coef);
}
return 0;
}
static int patch_cs4210(struct hda_codec *codec)
{
struct cs_spec *spec;
int err;
spec = cs_alloc_spec(codec, CS4210_VENDOR_NID);
if (!spec)
return -ENOMEM;
spec->gen.automute_hook = cs_automute;
snd_hda_pick_fixup(codec, cs421x_models, cs421x_fixup_tbl,
cs421x_fixups);
snd_hda_apply_fixup(codec, HDA_FIXUP_ACT_PRE_PROBE);
cs4210_pinmux_init(codec);
err = cs421x_parse_auto_config(codec);
if (err < 0)
goto error;
codec->patch_ops = cs421x_patch_ops;
snd_hda_apply_fixup(codec, HDA_FIXUP_ACT_PROBE);
return 0;
error:
cs_free(codec);
return err;
}
static int patch_cs4213(struct hda_codec *codec)
{
struct cs_spec *spec;
int err;
spec = cs_alloc_spec(codec, CS4213_VENDOR_NID);
if (!spec)
return -ENOMEM;
err = cs421x_parse_auto_config(codec);
if (err < 0)
goto error;
codec->patch_ops = cs421x_patch_ops;
return 0;
error:
cs_free(codec);
return err;
}
