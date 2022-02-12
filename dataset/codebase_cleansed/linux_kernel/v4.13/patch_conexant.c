static inline void set_beep_amp(struct conexant_spec *spec, hda_nid_t nid,
int idx, int dir)
{
spec->gen.beep_nid = nid;
spec->beep_amp = HDA_COMPOSE_AMP_VAL(nid, 1, idx, dir);
}
static int add_beep_ctls(struct hda_codec *codec)
{
struct conexant_spec *spec = codec->spec;
int err;
if (spec->beep_amp) {
const struct snd_kcontrol_new *knew;
for (knew = cxt_beep_mixer; knew->name; knew++) {
struct snd_kcontrol *kctl;
kctl = snd_ctl_new1(knew, codec);
if (!kctl)
return -ENOMEM;
kctl->private_value = spec->beep_amp;
err = snd_hda_ctl_add(codec, 0, kctl);
if (err < 0)
return err;
}
}
return 0;
}
static void cx_auto_parse_beep(struct hda_codec *codec)
{
struct conexant_spec *spec = codec->spec;
hda_nid_t nid;
for_each_hda_codec_node(nid, codec)
if (get_wcaps_type(get_wcaps(codec, nid)) == AC_WID_BEEP) {
set_beep_amp(spec, nid, 0, HDA_OUTPUT);
break;
}
}
static void cx_auto_parse_eapd(struct hda_codec *codec)
{
struct conexant_spec *spec = codec->spec;
hda_nid_t nid;
for_each_hda_codec_node(nid, codec) {
if (get_wcaps_type(get_wcaps(codec, nid)) != AC_WID_PIN)
continue;
if (!(snd_hda_query_pin_caps(codec, nid) & AC_PINCAP_EAPD))
continue;
spec->eapds[spec->num_eapds++] = nid;
if (spec->num_eapds >= ARRAY_SIZE(spec->eapds))
break;
}
if (spec->num_eapds > 2)
spec->dynamic_eapd = 1;
}
static void cx_auto_turn_eapd(struct hda_codec *codec, int num_pins,
hda_nid_t *pins, bool on)
{
int i;
for (i = 0; i < num_pins; i++) {
if (snd_hda_query_pin_caps(codec, pins[i]) & AC_PINCAP_EAPD)
snd_hda_codec_write(codec, pins[i], 0,
AC_VERB_SET_EAPD_BTLENABLE,
on ? 0x02 : 0);
}
}
static void cx_auto_vmaster_hook(void *private_data, int enabled)
{
struct hda_codec *codec = private_data;
struct conexant_spec *spec = codec->spec;
cx_auto_turn_eapd(codec, spec->num_eapds, spec->eapds, enabled);
}
static void cx_auto_vmaster_hook_mute_led(void *private_data, int enabled)
{
struct hda_codec *codec = private_data;
struct conexant_spec *spec = codec->spec;
snd_hda_codec_write(codec, spec->mute_led_eapd, 0,
AC_VERB_SET_EAPD_BTLENABLE,
enabled ? 0x00 : 0x02);
}
static int cx_auto_build_controls(struct hda_codec *codec)
{
int err;
err = snd_hda_gen_build_controls(codec);
if (err < 0)
return err;
err = add_beep_ctls(codec);
if (err < 0)
return err;
return 0;
}
static int cx_auto_init(struct hda_codec *codec)
{
struct conexant_spec *spec = codec->spec;
snd_hda_gen_init(codec);
if (!spec->dynamic_eapd)
cx_auto_turn_eapd(codec, spec->num_eapds, spec->eapds, true);
snd_hda_apply_fixup(codec, HDA_FIXUP_ACT_INIT);
return 0;
}
static void cx_auto_reboot_notify(struct hda_codec *codec)
{
struct conexant_spec *spec = codec->spec;
switch (codec->core.vendor_id) {
case 0x14f150f2:
case 0x14f150f4:
break;
default:
return;
}
cx_auto_turn_eapd(codec, spec->num_eapds, spec->eapds, false);
snd_hda_codec_set_power_to_all(codec, codec->core.afg, AC_PWRST_D3);
snd_hda_codec_write(codec, codec->core.afg, 0,
AC_VERB_SET_POWER_STATE, AC_PWRST_D3);
}
static void cx_auto_free(struct hda_codec *codec)
{
cx_auto_reboot_notify(codec);
snd_hda_gen_free(codec);
}
static void cxt_fixup_stereo_dmic(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
struct conexant_spec *spec = codec->spec;
spec->gen.inv_dmic_split = 1;
}
static void cxt5066_increase_mic_boost(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
if (action != HDA_FIXUP_ACT_PRE_PROBE)
return;
snd_hda_override_amp_caps(codec, 0x17, HDA_OUTPUT,
(0x3 << AC_AMPCAP_OFFSET_SHIFT) |
(0x4 << AC_AMPCAP_NUM_STEPS_SHIFT) |
(0x27 << AC_AMPCAP_STEP_SIZE_SHIFT) |
(0 << AC_AMPCAP_MUTE_SHIFT));
}
static void cxt_update_headset_mode(struct hda_codec *codec)
{
int i;
bool mic_mode = false;
struct conexant_spec *spec = codec->spec;
struct auto_pin_cfg *cfg = &spec->gen.autocfg;
hda_nid_t mux_pin = spec->gen.imux_pins[spec->gen.cur_mux[0]];
for (i = 0; i < cfg->num_inputs; i++)
if (cfg->inputs[i].pin == mux_pin) {
mic_mode = !!cfg->inputs[i].is_headphone_mic;
break;
}
if (mic_mode) {
snd_hda_codec_write_cache(codec, 0x1c, 0, 0x410, 0x7c);
spec->gen.hp_jack_present = false;
} else {
snd_hda_codec_write_cache(codec, 0x1c, 0, 0x410, 0x54);
spec->gen.hp_jack_present = snd_hda_jack_detect(codec, spec->gen.autocfg.hp_pins[0]);
}
snd_hda_gen_update_outputs(codec);
}
static void cxt_update_headset_mode_hook(struct hda_codec *codec,
struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
cxt_update_headset_mode(codec);
}
static void cxt_fixup_headphone_mic(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
struct conexant_spec *spec = codec->spec;
switch (action) {
case HDA_FIXUP_ACT_PRE_PROBE:
spec->parse_flags |= HDA_PINCFG_HEADPHONE_MIC;
snd_hdac_regmap_add_vendor_verb(&codec->core, 0x410);
break;
case HDA_FIXUP_ACT_PROBE:
spec->gen.cap_sync_hook = cxt_update_headset_mode_hook;
spec->gen.automute_hook = cxt_update_headset_mode;
break;
case HDA_FIXUP_ACT_INIT:
cxt_update_headset_mode(codec);
break;
}
}
static void olpc_xo_update_mic_boost(struct hda_codec *codec)
{
struct conexant_spec *spec = codec->spec;
int ch, val;
for (ch = 0; ch < 2; ch++) {
val = AC_AMP_SET_OUTPUT |
(ch ? AC_AMP_SET_RIGHT : AC_AMP_SET_LEFT);
if (!spec->dc_enable)
val |= snd_hda_codec_amp_read(codec, 0x17, ch, HDA_OUTPUT, 0);
snd_hda_codec_write(codec, 0x17, 0,
AC_VERB_SET_AMP_GAIN_MUTE, val);
}
}
static void olpc_xo_update_mic_pins(struct hda_codec *codec)
{
struct conexant_spec *spec = codec->spec;
int cur_input, val;
struct nid_path *path;
cur_input = spec->gen.input_paths[0][spec->gen.cur_mux[0]];
if (!spec->dc_enable) {
update_mic_pin(codec, 0x1e, 0);
snd_hda_activate_path(codec, spec->dc_mode_path, false, false);
update_mic_pin(codec, 0x1a, spec->recording ?
snd_hda_codec_get_pin_target(codec, 0x1a) : 0);
update_mic_pin(codec, 0x1b, spec->recording ?
snd_hda_codec_get_pin_target(codec, 0x1b) : 0);
path = snd_hda_get_path_from_idx(codec, cur_input);
if (path)
snd_hda_activate_path(codec, path, true, false);
} else {
path = snd_hda_get_path_from_idx(codec, cur_input);
if (path)
snd_hda_activate_path(codec, path, false, false);
if (spec->recording)
val = olpc_xo_dc_bias.items[spec->dc_input_bias].index;
else
val = 0;
update_mic_pin(codec, 0x1a, val);
update_mic_pin(codec, 0x1b, 0);
update_mic_pin(codec, 0x1e, spec->recording ? PIN_IN : 0);
snd_hda_activate_path(codec, spec->dc_mode_path, true, false);
}
}
static void olpc_xo_automic(struct hda_codec *codec,
struct hda_jack_callback *jack)
{
struct conexant_spec *spec = codec->spec;
if (!spec->dc_enable)
snd_hda_gen_mic_autoswitch(codec, jack);
olpc_xo_update_mic_pins(codec);
if (spec->dc_enable)
olpc_xo_update_mic_boost(codec);
}
static void olpc_xo_capture_hook(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
struct snd_pcm_substream *substream,
int action)
{
struct conexant_spec *spec = codec->spec;
switch (action) {
case HDA_GEN_PCM_ACT_PREPARE:
spec->recording = 1;
olpc_xo_update_mic_pins(codec);
break;
case HDA_GEN_PCM_ACT_CLEANUP:
spec->recording = 0;
olpc_xo_update_mic_pins(codec);
break;
}
}
static int olpc_xo_dc_mode_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct conexant_spec *spec = codec->spec;
ucontrol->value.integer.value[0] = spec->dc_enable;
return 0;
}
static int olpc_xo_dc_mode_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct conexant_spec *spec = codec->spec;
int dc_enable = !!ucontrol->value.integer.value[0];
if (dc_enable == spec->dc_enable)
return 0;
spec->dc_enable = dc_enable;
olpc_xo_update_mic_pins(codec);
olpc_xo_update_mic_boost(codec);
return 1;
}
static int olpc_xo_dc_bias_enum_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct conexant_spec *spec = codec->spec;
ucontrol->value.enumerated.item[0] = spec->dc_input_bias;
return 0;
}
static int olpc_xo_dc_bias_enum_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
return snd_hda_input_mux_info(&olpc_xo_dc_bias, uinfo);
}
static int olpc_xo_dc_bias_enum_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct conexant_spec *spec = codec->spec;
const struct hda_input_mux *imux = &olpc_xo_dc_bias;
unsigned int idx;
idx = ucontrol->value.enumerated.item[0];
if (idx >= imux->num_items)
idx = imux->num_items - 1;
if (spec->dc_input_bias == idx)
return 0;
spec->dc_input_bias = idx;
if (spec->dc_enable)
olpc_xo_update_mic_pins(codec);
return 1;
}
static int olpc_xo_mic_boost_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct conexant_spec *spec = codec->spec;
int ret = snd_hda_mixer_amp_volume_put(kcontrol, ucontrol);
if (ret > 0 && spec->dc_enable)
olpc_xo_update_mic_boost(codec);
return ret;
}
static void cxt_fixup_olpc_xo(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
struct conexant_spec *spec = codec->spec;
int i;
if (action != HDA_FIXUP_ACT_PROBE)
return;
spec->gen.mic_autoswitch_hook = olpc_xo_automic;
spec->gen.pcm_capture_hook = olpc_xo_capture_hook;
spec->dc_mode_path = snd_hda_add_new_path(codec, 0x1e, 0x14, 0);
snd_hda_add_new_ctls(codec, olpc_xo_mixers);
snd_hda_codec_set_pin_target(codec, 0x1a, PIN_VREF50);
for (i = 0; i < spec->gen.kctls.used; i++) {
struct snd_kcontrol_new *kctl =
snd_array_elem(&spec->gen.kctls, i);
if (!strcmp(kctl->name, "Mic Boost Volume")) {
kctl->put = olpc_xo_mic_boost_put;
break;
}
}
}
static void cxt_fixup_mute_led_eapd(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
struct conexant_spec *spec = codec->spec;
if (action == HDA_FIXUP_ACT_PRE_PROBE) {
spec->mute_led_eapd = 0x1b;
spec->dynamic_eapd = 1;
spec->gen.vmaster_mute.hook = cx_auto_vmaster_hook_mute_led;
}
}
static void cxt_fixup_cap_mix_amp(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
snd_hda_override_amp_caps(codec, 0x17, HDA_INPUT,
(0x14 << AC_AMPCAP_OFFSET_SHIFT) |
(0x14 << AC_AMPCAP_NUM_STEPS_SHIFT) |
(0x05 << AC_AMPCAP_STEP_SIZE_SHIFT) |
(1 << AC_AMPCAP_MUTE_SHIFT));
}
static void cxt_fixup_cap_mix_amp_5047(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
snd_hda_override_amp_caps(codec, 0x10, HDA_INPUT,
(0x17 << AC_AMPCAP_OFFSET_SHIFT) |
(0x17 << AC_AMPCAP_NUM_STEPS_SHIFT) |
(0x05 << AC_AMPCAP_STEP_SIZE_SHIFT) |
(1 << AC_AMPCAP_MUTE_SHIFT));
}
static void cxt_fixup_hp_gate_mic_jack(struct hda_codec *codec,
const struct hda_fixup *fix,
int action)
{
if (action == HDA_FIXUP_ACT_PROBE)
snd_hda_jack_set_gating_jack(codec, 0x19, 0x16);
}
static void cxt_update_gpio_led(struct hda_codec *codec, unsigned int mask,
bool enabled)
{
struct conexant_spec *spec = codec->spec;
unsigned int oldval = spec->gpio_led;
if (spec->mute_led_polarity)
enabled = !enabled;
if (enabled)
spec->gpio_led &= ~mask;
else
spec->gpio_led |= mask;
if (spec->gpio_led != oldval)
snd_hda_codec_write(codec, 0x01, 0, AC_VERB_SET_GPIO_DATA,
spec->gpio_led);
}
static void cxt_fixup_gpio_mute_hook(void *private_data, int enabled)
{
struct hda_codec *codec = private_data;
struct conexant_spec *spec = codec->spec;
cxt_update_gpio_led(codec, spec->gpio_mute_led_mask, enabled);
}
static void cxt_fixup_gpio_mic_mute_hook(struct hda_codec *codec,
struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct conexant_spec *spec = codec->spec;
if (ucontrol)
cxt_update_gpio_led(codec, spec->gpio_mic_led_mask,
ucontrol->value.integer.value[0] ||
ucontrol->value.integer.value[1]);
}
static void cxt_fixup_mute_led_gpio(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
struct conexant_spec *spec = codec->spec;
static const struct hda_verb gpio_init[] = {
{ 0x01, AC_VERB_SET_GPIO_MASK, 0x03 },
{ 0x01, AC_VERB_SET_GPIO_DIRECTION, 0x03 },
{}
};
codec_info(codec, "action: %d gpio_led: %d\n", action, spec->gpio_led);
if (action == HDA_FIXUP_ACT_PRE_PROBE) {
spec->gen.vmaster_mute.hook = cxt_fixup_gpio_mute_hook;
spec->gen.cap_sync_hook = cxt_fixup_gpio_mic_mute_hook;
spec->gpio_led = 0;
spec->mute_led_polarity = 0;
spec->gpio_mute_led_mask = 0x01;
spec->gpio_mic_led_mask = 0x02;
}
snd_hda_add_verbs(codec, gpio_init);
if (spec->gpio_led)
snd_hda_codec_write(codec, 0x01, 0, AC_VERB_SET_GPIO_DATA,
spec->gpio_led);
}
static void add_cx5051_fake_mutes(struct hda_codec *codec)
{
struct conexant_spec *spec = codec->spec;
static hda_nid_t out_nids[] = {
0x10, 0x11, 0
};
hda_nid_t *p;
for (p = out_nids; *p; p++)
snd_hda_override_amp_caps(codec, *p, HDA_OUTPUT,
AC_AMPCAP_MIN_MUTE |
query_amp_caps(codec, *p, HDA_OUTPUT));
spec->gen.dac_min_mute = true;
}
static int patch_conexant_auto(struct hda_codec *codec)
{
struct conexant_spec *spec;
int err;
codec_info(codec, "%s: BIOS auto-probing.\n", codec->core.chip_name);
spec = kzalloc(sizeof(*spec), GFP_KERNEL);
if (!spec)
return -ENOMEM;
snd_hda_gen_spec_init(&spec->gen);
codec->spec = spec;
codec->patch_ops = cx_auto_patch_ops;
cx_auto_parse_beep(codec);
cx_auto_parse_eapd(codec);
spec->gen.own_eapd_ctl = 1;
if (spec->dynamic_eapd)
spec->gen.vmaster_mute.hook = cx_auto_vmaster_hook;
switch (codec->core.vendor_id) {
case 0x14f15045:
codec->single_adc_amp = 1;
spec->gen.mixer_nid = 0x17;
spec->gen.add_stereo_mix_input = HDA_HINT_STEREO_MIX_AUTO;
snd_hda_pick_fixup(codec, cxt5045_fixup_models,
cxt5045_fixups, cxt_fixups);
break;
case 0x14f15047:
codec->pin_amp_workaround = 1;
spec->gen.mixer_nid = 0x19;
spec->gen.add_stereo_mix_input = HDA_HINT_STEREO_MIX_AUTO;
snd_hda_pick_fixup(codec, cxt5047_fixup_models,
cxt5047_fixups, cxt_fixups);
break;
case 0x14f15051:
add_cx5051_fake_mutes(codec);
codec->pin_amp_workaround = 1;
snd_hda_pick_fixup(codec, cxt5051_fixup_models,
cxt5051_fixups, cxt_fixups);
break;
case 0x14f150f2:
codec->power_save_node = 1;
default:
codec->pin_amp_workaround = 1;
snd_hda_pick_fixup(codec, cxt5066_fixup_models,
cxt5066_fixups, cxt_fixups);
break;
}
switch (codec->core.subsystem_id >> 16) {
case 0x103c:
spec->gen.vmaster_mute_enum = 1;
break;
}
snd_hda_apply_fixup(codec, HDA_FIXUP_ACT_PRE_PROBE);
err = snd_hda_parse_pin_defcfg(codec, &spec->gen.autocfg, NULL,
spec->parse_flags);
if (err < 0)
goto error;
err = snd_hda_gen_parse_auto_config(codec, &spec->gen.autocfg);
if (err < 0)
goto error;
if (!codec->bus->core.sync_write) {
codec_info(codec,
"Enable sync_write for stable communication\n");
codec->bus->core.sync_write = 1;
codec->bus->allow_bus_reset = 1;
}
snd_hda_apply_fixup(codec, HDA_FIXUP_ACT_PROBE);
return 0;
error:
cx_auto_free(codec);
return err;
}
