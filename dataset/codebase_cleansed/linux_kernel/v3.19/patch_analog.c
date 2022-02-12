static int create_beep_ctls(struct hda_codec *codec)
{
struct ad198x_spec *spec = codec->spec;
const struct snd_kcontrol_new *knew;
if (!spec->beep_amp)
return 0;
for (knew = ad_beep_mixer ; knew->name; knew++) {
int err;
struct snd_kcontrol *kctl;
kctl = snd_ctl_new1(knew, codec);
if (!kctl)
return -ENOMEM;
kctl->private_value = spec->beep_amp;
err = snd_hda_ctl_add(codec, 0, kctl);
if (err < 0)
return err;
}
return 0;
}
static void ad198x_power_eapd_write(struct hda_codec *codec, hda_nid_t front,
hda_nid_t hp)
{
if (snd_hda_query_pin_caps(codec, front) & AC_PINCAP_EAPD)
snd_hda_codec_write(codec, front, 0, AC_VERB_SET_EAPD_BTLENABLE,
!codec->inv_eapd ? 0x00 : 0x02);
if (snd_hda_query_pin_caps(codec, hp) & AC_PINCAP_EAPD)
snd_hda_codec_write(codec, hp, 0, AC_VERB_SET_EAPD_BTLENABLE,
!codec->inv_eapd ? 0x00 : 0x02);
}
static void ad198x_power_eapd(struct hda_codec *codec)
{
switch (codec->vendor_id) {
case 0x11d41882:
case 0x11d4882a:
case 0x11d41884:
case 0x11d41984:
case 0x11d41883:
case 0x11d4184a:
case 0x11d4194a:
case 0x11d4194b:
case 0x11d41988:
case 0x11d4198b:
case 0x11d4989a:
case 0x11d4989b:
ad198x_power_eapd_write(codec, 0x12, 0x11);
break;
case 0x11d41981:
case 0x11d41983:
ad198x_power_eapd_write(codec, 0x05, 0x06);
break;
case 0x11d41986:
ad198x_power_eapd_write(codec, 0x1b, 0x1a);
break;
}
}
static void ad198x_shutup(struct hda_codec *codec)
{
snd_hda_shutup_pins(codec);
ad198x_power_eapd(codec);
}
static int ad198x_suspend(struct hda_codec *codec)
{
ad198x_shutup(codec);
return 0;
}
static void ad_vmaster_eapd_hook(void *private_data, int enabled)
{
struct hda_codec *codec = private_data;
struct ad198x_spec *spec = codec->spec;
if (!spec->eapd_nid)
return;
if (codec->inv_eapd)
enabled = !enabled;
snd_hda_codec_update_cache(codec, spec->eapd_nid, 0,
AC_VERB_SET_EAPD_BTLENABLE,
enabled ? 0x02 : 0x00);
}
static int ad198x_auto_build_controls(struct hda_codec *codec)
{
int err;
err = snd_hda_gen_build_controls(codec);
if (err < 0)
return err;
err = create_beep_ctls(codec);
if (err < 0)
return err;
return 0;
}
static int ad198x_parse_auto_config(struct hda_codec *codec, bool indep_hp)
{
struct ad198x_spec *spec = codec->spec;
struct auto_pin_cfg *cfg = &spec->gen.autocfg;
int err;
codec->spdif_status_reset = 1;
codec->no_trigger_sense = 1;
codec->no_sticky_stream = 1;
spec->gen.indep_hp = indep_hp;
if (!spec->gen.add_stereo_mix_input)
spec->gen.add_stereo_mix_input = HDA_HINT_STEREO_MIX_AUTO;
err = snd_hda_parse_pin_defcfg(codec, cfg, NULL, 0);
if (err < 0)
return err;
err = snd_hda_gen_parse_auto_config(codec, cfg);
if (err < 0)
return err;
codec->patch_ops = ad198x_auto_patch_ops;
return 0;
}
static int alloc_ad_spec(struct hda_codec *codec)
{
struct ad198x_spec *spec;
spec = kzalloc(sizeof(*spec), GFP_KERNEL);
if (!spec)
return -ENOMEM;
codec->spec = spec;
snd_hda_gen_spec_init(&spec->gen);
return 0;
}
static void ad_fixup_inv_jack_detect(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
struct ad198x_spec *spec = codec->spec;
if (action == HDA_FIXUP_ACT_PRE_PROBE) {
codec->inv_jack_detect = 1;
spec->gen.keep_eapd_on = 1;
spec->gen.vmaster_mute.hook = ad_vmaster_eapd_hook;
spec->eapd_nid = 0x1b;
}
}
static void ad1986a_fixup_eapd(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
struct ad198x_spec *spec = codec->spec;
if (action == HDA_FIXUP_ACT_PRE_PROBE) {
codec->inv_eapd = 0;
spec->gen.keep_eapd_on = 1;
spec->eapd_nid = 0x1b;
}
}
static void ad1986a_fixup_eapd_mix_in(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
struct ad198x_spec *spec = codec->spec;
if (action == HDA_FIXUP_ACT_PRE_PROBE) {
ad1986a_fixup_eapd(codec, fix, action);
spec->gen.add_stereo_mix_input = HDA_HINT_STEREO_MIX_ENABLE;
}
}
static int patch_ad1986a(struct hda_codec *codec)
{
int err;
struct ad198x_spec *spec;
static hda_nid_t preferred_pairs[] = {
0x1a, 0x03,
0x1b, 0x03,
0x1c, 0x04,
0x1d, 0x05,
0x1e, 0x03,
0
};
err = alloc_ad_spec(codec);
if (err < 0)
return err;
spec = codec->spec;
codec->inv_eapd = 1;
spec->gen.mixer_nid = 0x07;
spec->gen.beep_nid = 0x19;
set_beep_amp(spec, 0x18, 0, HDA_OUTPUT);
spec->gen.multiout.no_share_stream = 1;
spec->gen.preferred_dacs = preferred_pairs;
spec->gen.auto_mute_via_amp = 1;
snd_hda_pick_fixup(codec, ad1986a_fixup_models, ad1986a_fixup_tbl,
ad1986a_fixups);
snd_hda_apply_fixup(codec, HDA_FIXUP_ACT_PRE_PROBE);
err = ad198x_parse_auto_config(codec, false);
if (err < 0) {
snd_hda_gen_free(codec);
return err;
}
snd_hda_apply_fixup(codec, HDA_FIXUP_ACT_PROBE);
return 0;
}
static int ad1983_auto_smux_enum_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct ad198x_spec *spec = codec->spec;
static const char * const texts2[] = { "PCM", "ADC" };
static const char * const texts3[] = { "PCM", "ADC1", "ADC2" };
hda_nid_t dig_out = spec->gen.multiout.dig_out_nid;
int num_conns = snd_hda_get_num_conns(codec, dig_out);
if (num_conns == 2)
return snd_hda_enum_helper_info(kcontrol, uinfo, 2, texts2);
else if (num_conns == 3)
return snd_hda_enum_helper_info(kcontrol, uinfo, 3, texts3);
else
return -EINVAL;
}
static int ad1983_auto_smux_enum_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct ad198x_spec *spec = codec->spec;
ucontrol->value.enumerated.item[0] = spec->cur_smux;
return 0;
}
static int ad1983_auto_smux_enum_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct ad198x_spec *spec = codec->spec;
unsigned int val = ucontrol->value.enumerated.item[0];
hda_nid_t dig_out = spec->gen.multiout.dig_out_nid;
int num_conns = snd_hda_get_num_conns(codec, dig_out);
if (val >= num_conns)
return -EINVAL;
if (spec->cur_smux == val)
return 0;
spec->cur_smux = val;
snd_hda_codec_write_cache(codec, dig_out, 0,
AC_VERB_SET_CONNECT_SEL, val);
return 1;
}
static int ad1983_add_spdif_mux_ctl(struct hda_codec *codec)
{
struct ad198x_spec *spec = codec->spec;
hda_nid_t dig_out = spec->gen.multiout.dig_out_nid;
int num_conns;
if (!dig_out)
return 0;
num_conns = snd_hda_get_num_conns(codec, dig_out);
if (num_conns != 2 && num_conns != 3)
return 0;
if (!snd_hda_gen_add_kctl(&spec->gen, NULL, &ad1983_auto_smux_mixer))
return -ENOMEM;
return 0;
}
static int patch_ad1983(struct hda_codec *codec)
{
struct ad198x_spec *spec;
static hda_nid_t conn_0c[] = { 0x08 };
static hda_nid_t conn_0d[] = { 0x09 };
int err;
err = alloc_ad_spec(codec);
if (err < 0)
return err;
spec = codec->spec;
spec->gen.mixer_nid = 0x0e;
spec->gen.beep_nid = 0x10;
set_beep_amp(spec, 0x10, 0, HDA_OUTPUT);
snd_hda_override_conn_list(codec, 0x0c, ARRAY_SIZE(conn_0c), conn_0c);
snd_hda_override_conn_list(codec, 0x0d, ARRAY_SIZE(conn_0d), conn_0d);
err = ad198x_parse_auto_config(codec, false);
if (err < 0)
goto error;
err = ad1983_add_spdif_mux_ctl(codec);
if (err < 0)
goto error;
return 0;
error:
snd_hda_gen_free(codec);
return err;
}
static void ad1981_fixup_hp_eapd(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
struct ad198x_spec *spec = codec->spec;
if (action == HDA_FIXUP_ACT_PRE_PROBE) {
spec->gen.vmaster_mute.hook = ad_vmaster_eapd_hook;
spec->eapd_nid = 0x05;
}
}
static void ad1981_fixup_amp_override(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
if (action == HDA_FIXUP_ACT_PRE_PROBE)
snd_hda_override_amp_caps(codec, 0x11, HDA_INPUT,
(0x17 << AC_AMPCAP_OFFSET_SHIFT) |
(0x17 << AC_AMPCAP_NUM_STEPS_SHIFT) |
(0x05 << AC_AMPCAP_STEP_SIZE_SHIFT) |
(1 << AC_AMPCAP_MUTE_SHIFT));
}
static int patch_ad1981(struct hda_codec *codec)
{
struct ad198x_spec *spec;
int err;
err = alloc_ad_spec(codec);
if (err < 0)
return -ENOMEM;
spec = codec->spec;
spec->gen.mixer_nid = 0x0e;
spec->gen.beep_nid = 0x10;
set_beep_amp(spec, 0x0d, 0, HDA_OUTPUT);
snd_hda_pick_fixup(codec, NULL, ad1981_fixup_tbl, ad1981_fixups);
snd_hda_apply_fixup(codec, HDA_FIXUP_ACT_PRE_PROBE);
err = ad198x_parse_auto_config(codec, false);
if (err < 0)
goto error;
err = ad1983_add_spdif_mux_ctl(codec);
if (err < 0)
goto error;
snd_hda_apply_fixup(codec, HDA_FIXUP_ACT_PROBE);
return 0;
error:
snd_hda_gen_free(codec);
return err;
}
static int ad198x_ch_mode_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct ad198x_spec *spec = codec->spec;
return snd_hda_ch_mode_info(codec, uinfo, spec->channel_mode,
spec->num_channel_mode);
}
static int ad198x_ch_mode_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct ad198x_spec *spec = codec->spec;
return snd_hda_ch_mode_get(codec, ucontrol, spec->channel_mode,
spec->num_channel_mode, spec->multiout.max_channels);
}
static int ad198x_ch_mode_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct ad198x_spec *spec = codec->spec;
int err = snd_hda_ch_mode_put(codec, ucontrol, spec->channel_mode,
spec->num_channel_mode,
&spec->multiout.max_channels);
if (err >= 0 && spec->need_dac_fix)
spec->multiout.num_dacs = spec->multiout.max_channels / 2;
return err;
}
static int ad1988_auto_smux_enum_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
static const char * const texts[] = {
"PCM", "ADC1", "ADC2", "ADC3",
};
int num_conns = snd_hda_get_num_conns(codec, 0x0b) + 1;
if (num_conns > 4)
num_conns = 4;
return snd_hda_enum_helper_info(kcontrol, uinfo, num_conns, texts);
}
static int ad1988_auto_smux_enum_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct ad198x_spec *spec = codec->spec;
ucontrol->value.enumerated.item[0] = spec->cur_smux;
return 0;
}
static int ad1988_auto_smux_enum_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct ad198x_spec *spec = codec->spec;
unsigned int val = ucontrol->value.enumerated.item[0];
struct nid_path *path;
int num_conns = snd_hda_get_num_conns(codec, 0x0b) + 1;
if (val >= num_conns)
return -EINVAL;
if (spec->cur_smux == val)
return 0;
mutex_lock(&codec->control_mutex);
codec->cached_write = 1;
path = snd_hda_get_path_from_idx(codec,
spec->smux_paths[spec->cur_smux]);
if (path)
snd_hda_activate_path(codec, path, false, true);
path = snd_hda_get_path_from_idx(codec, spec->smux_paths[val]);
if (path)
snd_hda_activate_path(codec, path, true, true);
spec->cur_smux = val;
codec->cached_write = 0;
mutex_unlock(&codec->control_mutex);
snd_hda_codec_flush_cache(codec);
return 1;
}
static int ad1988_auto_init(struct hda_codec *codec)
{
struct ad198x_spec *spec = codec->spec;
int i, err;
err = snd_hda_gen_init(codec);
if (err < 0)
return err;
if (!spec->gen.autocfg.dig_outs)
return 0;
for (i = 0; i < 4; i++) {
struct nid_path *path;
path = snd_hda_get_path_from_idx(codec, spec->smux_paths[i]);
if (path)
snd_hda_activate_path(codec, path, path->active, false);
}
return 0;
}
static int ad1988_add_spdif_mux_ctl(struct hda_codec *codec)
{
struct ad198x_spec *spec = codec->spec;
int i, num_conns;
static struct nid_path fake_paths[4] = {
{
.depth = 3,
.path = { 0x02, 0x1d, 0x1b },
.idx = { 0, 0, 0 },
.multi = { 0, 0, 0 },
},
{
.depth = 4,
.path = { 0x08, 0x0b, 0x1d, 0x1b },
.idx = { 0, 0, 1, 0 },
.multi = { 0, 1, 0, 0 },
},
{
.depth = 4,
.path = { 0x09, 0x0b, 0x1d, 0x1b },
.idx = { 0, 1, 1, 0 },
.multi = { 0, 1, 0, 0 },
},
{
.depth = 4,
.path = { 0x0f, 0x0b, 0x1d, 0x1b },
.idx = { 0, 2, 1, 0 },
.multi = { 0, 1, 0, 0 },
},
};
if (!spec->gen.autocfg.dig_outs ||
get_wcaps_type(get_wcaps(codec, 0x1d)) != AC_WID_AUD_MIX)
return 0;
num_conns = snd_hda_get_num_conns(codec, 0x0b) + 1;
if (num_conns != 3 && num_conns != 4)
return 0;
for (i = 0; i < num_conns; i++) {
struct nid_path *path = snd_array_new(&spec->gen.paths);
if (!path)
return -ENOMEM;
*path = fake_paths[i];
if (!i)
path->active = 1;
spec->smux_paths[i] = snd_hda_get_path_idx(codec, path);
}
if (!snd_hda_gen_add_kctl(&spec->gen, NULL, &ad1988_auto_smux_mixer))
return -ENOMEM;
codec->patch_ops.init = ad1988_auto_init;
return 0;
}
static int patch_ad1988(struct hda_codec *codec)
{
struct ad198x_spec *spec;
int err;
err = alloc_ad_spec(codec);
if (err < 0)
return err;
spec = codec->spec;
spec->gen.mixer_nid = 0x20;
spec->gen.mixer_merge_nid = 0x21;
spec->gen.beep_nid = 0x10;
set_beep_amp(spec, 0x10, 0, HDA_OUTPUT);
snd_hda_pick_fixup(codec, ad1988_fixup_models, NULL, ad1988_fixups);
snd_hda_apply_fixup(codec, HDA_FIXUP_ACT_PRE_PROBE);
err = ad198x_parse_auto_config(codec, true);
if (err < 0)
goto error;
err = ad1988_add_spdif_mux_ctl(codec);
if (err < 0)
goto error;
snd_hda_apply_fixup(codec, HDA_FIXUP_ACT_PROBE);
return 0;
error:
snd_hda_gen_free(codec);
return err;
}
static void ad1884_fixup_amp_override(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
if (action == HDA_FIXUP_ACT_PRE_PROBE)
snd_hda_override_amp_caps(codec, 0x20, HDA_INPUT,
(0x17 << AC_AMPCAP_OFFSET_SHIFT) |
(0x17 << AC_AMPCAP_NUM_STEPS_SHIFT) |
(0x05 << AC_AMPCAP_STEP_SIZE_SHIFT) |
(1 << AC_AMPCAP_MUTE_SHIFT));
}
static void ad1884_vmaster_hp_gpio_hook(void *private_data, int enabled)
{
struct hda_codec *codec = private_data;
struct ad198x_spec *spec = codec->spec;
if (spec->eapd_nid)
ad_vmaster_eapd_hook(private_data, enabled);
snd_hda_codec_update_cache(codec, 0x01, 0,
AC_VERB_SET_GPIO_DATA,
enabled ? 0x00 : 0x02);
}
static void ad1884_fixup_hp_eapd(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
struct ad198x_spec *spec = codec->spec;
static const struct hda_verb gpio_init_verbs[] = {
{0x01, AC_VERB_SET_GPIO_MASK, 0x02},
{0x01, AC_VERB_SET_GPIO_DIRECTION, 0x02},
{0x01, AC_VERB_SET_GPIO_DATA, 0x02},
{},
};
switch (action) {
case HDA_FIXUP_ACT_PRE_PROBE:
spec->gen.vmaster_mute.hook = ad1884_vmaster_hp_gpio_hook;
spec->gen.own_eapd_ctl = 1;
snd_hda_sequence_write_cache(codec, gpio_init_verbs);
break;
case HDA_FIXUP_ACT_PROBE:
if (spec->gen.autocfg.line_out_type == AUTO_PIN_SPEAKER_OUT)
spec->eapd_nid = spec->gen.autocfg.line_out_pins[0];
else
spec->eapd_nid = spec->gen.autocfg.speaker_pins[0];
break;
}
}
static void ad1884_fixup_thinkpad(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
struct ad198x_spec *spec = codec->spec;
if (action == HDA_FIXUP_ACT_PRE_PROBE) {
spec->gen.keep_eapd_on = 1;
spec->gen.vmaster_mute.hook = ad_vmaster_eapd_hook;
spec->eapd_nid = 0x12;
spec->beep_amp = HDA_COMPOSE_AMP_VAL(0x20, 3, 3, HDA_INPUT);
spec->gen.beep_nid = 0;
}
}
static int patch_ad1884(struct hda_codec *codec)
{
struct ad198x_spec *spec;
int err;
err = alloc_ad_spec(codec);
if (err < 0)
return err;
spec = codec->spec;
spec->gen.mixer_nid = 0x20;
spec->gen.mixer_merge_nid = 0x21;
spec->gen.beep_nid = 0x10;
set_beep_amp(spec, 0x10, 0, HDA_OUTPUT);
snd_hda_pick_fixup(codec, NULL, ad1884_fixup_tbl, ad1884_fixups);
snd_hda_apply_fixup(codec, HDA_FIXUP_ACT_PRE_PROBE);
err = ad198x_parse_auto_config(codec, true);
if (err < 0)
goto error;
err = ad1983_add_spdif_mux_ctl(codec);
if (err < 0)
goto error;
snd_hda_apply_fixup(codec, HDA_FIXUP_ACT_PROBE);
return 0;
error:
snd_hda_gen_free(codec);
return err;
}
static int patch_ad1882(struct hda_codec *codec)
{
struct ad198x_spec *spec;
int err;
err = alloc_ad_spec(codec);
if (err < 0)
return err;
spec = codec->spec;
spec->gen.mixer_nid = 0x20;
spec->gen.mixer_merge_nid = 0x21;
spec->gen.beep_nid = 0x10;
set_beep_amp(spec, 0x10, 0, HDA_OUTPUT);
err = ad198x_parse_auto_config(codec, true);
if (err < 0)
goto error;
err = ad1988_add_spdif_mux_ctl(codec);
if (err < 0)
goto error;
return 0;
error:
snd_hda_gen_free(codec);
return err;
}
static int __init patch_analog_init(void)
{
return snd_hda_add_codec_preset(&analog_list);
}
static void __exit patch_analog_exit(void)
{
snd_hda_delete_codec_preset(&analog_list);
}
