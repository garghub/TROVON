static struct via_spec *via_new_spec(struct hda_codec *codec)
{
struct via_spec *spec;
spec = kzalloc(sizeof(*spec), GFP_KERNEL);
if (spec == NULL)
return NULL;
codec->spec = spec;
snd_hda_gen_spec_init(&spec->gen);
spec->codec_type = get_codec_type(codec);
if (spec->codec_type == VT1708BCE)
spec->codec_type = VT1708S;
spec->gen.indep_hp = 1;
spec->gen.keep_eapd_on = 1;
spec->gen.pcm_playback_hook = via_playback_pcm_hook;
spec->gen.add_stereo_mix_input = HDA_HINT_STEREO_MIX_AUTO;
codec->power_save_node = 1;
spec->gen.power_down_unused = 1;
return spec;
}
static enum VIA_HDA_CODEC get_codec_type(struct hda_codec *codec)
{
u32 vendor_id = codec->core.vendor_id;
u16 ven_id = vendor_id >> 16;
u16 dev_id = vendor_id & 0xffff;
enum VIA_HDA_CODEC codec_type;
if (ven_id != 0x1106)
codec_type = UNKNOWN;
else if (dev_id >= 0x1708 && dev_id <= 0x170b)
codec_type = VT1708;
else if (dev_id >= 0xe710 && dev_id <= 0xe713)
codec_type = VT1709_10CH;
else if (dev_id >= 0xe714 && dev_id <= 0xe717)
codec_type = VT1709_6CH;
else if (dev_id >= 0xe720 && dev_id <= 0xe723) {
codec_type = VT1708B_8CH;
if (snd_hda_param_read(codec, 0x16, AC_PAR_CONNLIST_LEN) == 0x7)
codec_type = VT1708BCE;
} else if (dev_id >= 0xe724 && dev_id <= 0xe727)
codec_type = VT1708B_4CH;
else if ((dev_id & 0xfff) == 0x397
&& (dev_id >> 12) < 8)
codec_type = VT1708S;
else if ((dev_id & 0xfff) == 0x398
&& (dev_id >> 12) < 8)
codec_type = VT1702;
else if ((dev_id & 0xfff) == 0x428
&& (dev_id >> 12) < 8)
codec_type = VT1718S;
else if (dev_id == 0x0433 || dev_id == 0xa721)
codec_type = VT1716S;
else if (dev_id == 0x0441 || dev_id == 0x4441)
codec_type = VT1718S;
else if (dev_id == 0x0438 || dev_id == 0x4438)
codec_type = VT2002P;
else if (dev_id == 0x0448)
codec_type = VT1812;
else if (dev_id == 0x0440)
codec_type = VT1708S;
else if ((dev_id & 0xfff) == 0x446)
codec_type = VT1802;
else if (dev_id == 0x4760)
codec_type = VT1705CF;
else if (dev_id == 0x4761 || dev_id == 0x4762)
codec_type = VT1808;
else
codec_type = UNKNOWN;
return codec_type;
}
static void vt1708_stop_hp_work(struct hda_codec *codec)
{
struct via_spec *spec = codec->spec;
if (spec->codec_type != VT1708 || !spec->gen.autocfg.hp_outs)
return;
if (spec->hp_work_active) {
snd_hda_codec_write(codec, 0x1, 0, 0xf81, 1);
codec->jackpoll_interval = 0;
cancel_delayed_work_sync(&codec->jackpoll_work);
spec->hp_work_active = false;
}
}
static void vt1708_update_hp_work(struct hda_codec *codec)
{
struct via_spec *spec = codec->spec;
if (spec->codec_type != VT1708 || !spec->gen.autocfg.hp_outs)
return;
if (spec->vt1708_jack_detect) {
if (!spec->hp_work_active) {
codec->jackpoll_interval = msecs_to_jiffies(100);
snd_hda_codec_write(codec, 0x1, 0, 0xf81, 0);
schedule_delayed_work(&codec->jackpoll_work, 0);
spec->hp_work_active = true;
}
} else if (!hp_detect_with_aa(codec))
vt1708_stop_hp_work(codec);
}
static int via_pin_power_ctl_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
return snd_hda_enum_bool_helper_info(kcontrol, uinfo);
}
static int via_pin_power_ctl_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
ucontrol->value.enumerated.item[0] = codec->power_save_node;
return 0;
}
static int via_pin_power_ctl_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct via_spec *spec = codec->spec;
bool val = !!ucontrol->value.enumerated.item[0];
if (val == codec->power_save_node)
return 0;
codec->power_save_node = val;
spec->gen.power_down_unused = val;
analog_low_current_mode(codec);
return 1;
}
static inline void set_beep_amp(struct via_spec *spec, hda_nid_t nid,
int idx, int dir)
{
spec->gen.beep_nid = nid;
spec->beep_amp = HDA_COMPOSE_AMP_VAL(nid, 1, idx, dir);
}
static int add_beep_ctls(struct hda_codec *codec)
{
struct via_spec *spec = codec->spec;
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
static void auto_parse_beep(struct hda_codec *codec)
{
struct via_spec *spec = codec->spec;
hda_nid_t nid;
for_each_hda_codec_node(nid, codec)
if (get_wcaps_type(get_wcaps(codec, nid)) == AC_WID_BEEP) {
set_beep_amp(spec, nid, 0, HDA_OUTPUT);
break;
}
}
static bool is_aa_path_mute(struct hda_codec *codec)
{
struct via_spec *spec = codec->spec;
const struct hda_amp_list *p;
int ch, v;
p = spec->gen.loopback.amplist;
if (!p)
return true;
for (; p->nid; p++) {
for (ch = 0; ch < 2; ch++) {
v = snd_hda_codec_amp_read(codec, p->nid, ch, p->dir,
p->idx);
if (!(v & HDA_AMP_MUTE) && v > 0)
return false;
}
}
return true;
}
static void __analog_low_current_mode(struct hda_codec *codec, bool force)
{
struct via_spec *spec = codec->spec;
bool enable;
unsigned int verb, parm;
if (!codec->power_save_node)
enable = false;
else
enable = is_aa_path_mute(codec) && !spec->gen.active_streams;
if (enable == spec->alc_mode && !force)
return;
spec->alc_mode = enable;
switch (spec->codec_type) {
case VT1708B_8CH:
case VT1708B_4CH:
verb = 0xf70;
parm = enable ? 0x02 : 0x00;
break;
case VT1708S:
case VT1718S:
case VT1716S:
verb = 0xf73;
parm = enable ? 0x51 : 0xe1;
break;
case VT1702:
verb = 0xf73;
parm = enable ? 0x01 : 0x1d;
break;
case VT2002P:
case VT1812:
case VT1802:
verb = 0xf93;
parm = enable ? 0x00 : 0xe0;
break;
case VT1705CF:
case VT1808:
verb = 0xf82;
parm = enable ? 0x00 : 0xe0;
break;
default:
return;
}
snd_hda_codec_write(codec, codec->core.afg, 0, verb, parm);
}
static void analog_low_current_mode(struct hda_codec *codec)
{
return __analog_low_current_mode(codec, false);
}
static int via_build_controls(struct hda_codec *codec)
{
struct via_spec *spec = codec->spec;
int err, i;
err = snd_hda_gen_build_controls(codec);
if (err < 0)
return err;
err = add_beep_ctls(codec);
if (err < 0)
return err;
spec->mixers[spec->num_mixers++] = via_pin_power_ctl_enum;
for (i = 0; i < spec->num_mixers; i++) {
err = snd_hda_add_new_ctls(codec, spec->mixers[i]);
if (err < 0)
return err;
}
return 0;
}
static void via_playback_pcm_hook(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
struct snd_pcm_substream *substream,
int action)
{
analog_low_current_mode(codec);
vt1708_update_hp_work(codec);
}
static void via_free(struct hda_codec *codec)
{
vt1708_stop_hp_work(codec);
snd_hda_gen_free(codec);
}
static int via_suspend(struct hda_codec *codec)
{
struct via_spec *spec = codec->spec;
vt1708_stop_hp_work(codec);
if (spec->codec_type == VT1802)
snd_hda_shutup_pins(codec);
return 0;
}
static int via_resume(struct hda_codec *codec)
{
msleep(10);
codec->patch_ops.init(codec);
regcache_sync(codec->core.regmap);
return 0;
}
static int via_check_power_status(struct hda_codec *codec, hda_nid_t nid)
{
struct via_spec *spec = codec->spec;
analog_low_current_mode(codec);
vt1708_update_hp_work(codec);
return snd_hda_check_amp_list_power(codec, &spec->gen.loopback, nid);
}
static void vt1708_set_pinconfig_connect(struct hda_codec *codec, hda_nid_t nid)
{
unsigned int def_conf;
unsigned char seqassoc;
def_conf = snd_hda_codec_get_pincfg(codec, nid);
seqassoc = (unsigned char) get_defcfg_association(def_conf);
seqassoc = (seqassoc << 4) | get_defcfg_sequence(def_conf);
if (get_defcfg_connect(def_conf) == AC_JACK_PORT_NONE
&& (seqassoc == 0xf0 || seqassoc == 0xff)) {
def_conf = def_conf & (~(AC_JACK_PORT_BOTH << 30));
snd_hda_codec_set_pincfg(codec, nid, def_conf);
}
return;
}
static int vt1708_jack_detect_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct via_spec *spec = codec->spec;
if (spec->codec_type != VT1708)
return 0;
ucontrol->value.integer.value[0] = spec->vt1708_jack_detect;
return 0;
}
static int vt1708_jack_detect_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct via_spec *spec = codec->spec;
int val;
if (spec->codec_type != VT1708)
return 0;
val = !!ucontrol->value.integer.value[0];
if (spec->vt1708_jack_detect == val)
return 0;
spec->vt1708_jack_detect = val;
vt1708_update_hp_work(codec);
return 1;
}
static int via_parse_auto_config(struct hda_codec *codec)
{
struct via_spec *spec = codec->spec;
int err;
spec->gen.main_out_badness = &via_main_out_badness;
spec->gen.extra_out_badness = &via_extra_out_badness;
err = snd_hda_parse_pin_defcfg(codec, &spec->gen.autocfg, NULL, 0);
if (err < 0)
return err;
auto_parse_beep(codec);
err = snd_hda_gen_parse_auto_config(codec, &spec->gen.autocfg);
if (err < 0)
return err;
codec->power_save_node = 0;
spec->gen.power_down_unused = 0;
return 0;
}
static int via_init(struct hda_codec *codec)
{
struct via_spec *spec = codec->spec;
int i;
for (i = 0; i < spec->num_iverbs; i++)
snd_hda_sequence_write(codec, spec->init_verbs[i]);
__analog_low_current_mode(codec, true);
snd_hda_gen_init(codec);
vt1708_update_hp_work(codec);
return 0;
}
static int vt1708_build_controls(struct hda_codec *codec)
{
int err;
int old_interval = codec->jackpoll_interval;
codec->jackpoll_interval = msecs_to_jiffies(100);
err = via_build_controls(codec);
codec->jackpoll_interval = old_interval;
return err;
}
static int vt1708_build_pcms(struct hda_codec *codec)
{
struct via_spec *spec = codec->spec;
int i, err;
err = snd_hda_gen_build_pcms(codec);
if (err < 0 || codec->core.vendor_id != 0x11061708)
return err;
for (i = 0; i < ARRAY_SIZE(spec->gen.pcm_rec); i++) {
struct hda_pcm *info = spec->gen.pcm_rec[i];
if (!info)
continue;
if (!info->stream[SNDRV_PCM_STREAM_PLAYBACK].substreams ||
info->pcm_type != HDA_PCM_TYPE_AUDIO)
continue;
info->stream[SNDRV_PCM_STREAM_PLAYBACK].formats =
SNDRV_PCM_FMTBIT_S16_LE;
}
return 0;
}
static int patch_vt1708(struct hda_codec *codec)
{
struct via_spec *spec;
int err;
spec = via_new_spec(codec);
if (spec == NULL)
return -ENOMEM;
spec->gen.mixer_nid = 0x17;
codec->jackpoll_interval = msecs_to_jiffies(100);
spec->vt1708_jack_detect = 1;
spec->gen.suppress_auto_mic = 1;
spec->gen.auto_mute_via_amp = 1;
vt1708_set_pinconfig_connect(codec, VT1708_HP_PIN_NID);
vt1708_set_pinconfig_connect(codec, VT1708_CD_PIN_NID);
err = via_parse_auto_config(codec);
if (err < 0) {
via_free(codec);
return err;
}
spec->mixers[spec->num_mixers++] = vt1708_jack_detect_ctl;
spec->init_verbs[spec->num_iverbs++] = vt1708_init_verbs;
codec->patch_ops = via_patch_ops;
codec->patch_ops.build_controls = vt1708_build_controls;
codec->patch_ops.build_pcms = vt1708_build_pcms;
codec->jackpoll_interval = 0;
return 0;
}
static int patch_vt1709(struct hda_codec *codec)
{
struct via_spec *spec;
int err;
spec = via_new_spec(codec);
if (spec == NULL)
return -ENOMEM;
spec->gen.mixer_nid = 0x18;
err = via_parse_auto_config(codec);
if (err < 0) {
via_free(codec);
return err;
}
codec->patch_ops = via_patch_ops;
return 0;
}
static int patch_vt1708B(struct hda_codec *codec)
{
struct via_spec *spec;
int err;
if (get_codec_type(codec) == VT1708BCE)
return patch_vt1708S(codec);
spec = via_new_spec(codec);
if (spec == NULL)
return -ENOMEM;
spec->gen.mixer_nid = 0x16;
err = via_parse_auto_config(codec);
if (err < 0) {
via_free(codec);
return err;
}
codec->patch_ops = via_patch_ops;
return 0;
}
static void override_mic_boost(struct hda_codec *codec, hda_nid_t pin,
int offset, int num_steps, int step_size)
{
snd_hda_override_wcaps(codec, pin,
get_wcaps(codec, pin) | AC_WCAP_IN_AMP);
snd_hda_override_amp_caps(codec, pin, HDA_INPUT,
(offset << AC_AMPCAP_OFFSET_SHIFT) |
(num_steps << AC_AMPCAP_NUM_STEPS_SHIFT) |
(step_size << AC_AMPCAP_STEP_SIZE_SHIFT) |
(0 << AC_AMPCAP_MUTE_SHIFT));
}
static int patch_vt1708S(struct hda_codec *codec)
{
struct via_spec *spec;
int err;
spec = via_new_spec(codec);
if (spec == NULL)
return -ENOMEM;
spec->gen.mixer_nid = 0x16;
override_mic_boost(codec, 0x1a, 0, 3, 40);
override_mic_boost(codec, 0x1e, 0, 3, 40);
if (get_codec_type(codec) == VT1708BCE) {
kfree(codec->core.chip_name);
codec->core.chip_name = kstrdup("VT1708BCE", GFP_KERNEL);
snprintf(codec->card->mixername,
sizeof(codec->card->mixername),
"%s %s", codec->core.vendor_name, codec->core.chip_name);
}
if (codec->core.vendor_id == 0x11064397) {
kfree(codec->core.chip_name);
codec->core.chip_name = kstrdup("VT1705", GFP_KERNEL);
snprintf(codec->card->mixername,
sizeof(codec->card->mixername),
"%s %s", codec->core.vendor_name, codec->core.chip_name);
}
err = via_parse_auto_config(codec);
if (err < 0) {
via_free(codec);
return err;
}
spec->init_verbs[spec->num_iverbs++] = vt1708S_init_verbs;
codec->patch_ops = via_patch_ops;
return 0;
}
static int patch_vt1702(struct hda_codec *codec)
{
struct via_spec *spec;
int err;
spec = via_new_spec(codec);
if (spec == NULL)
return -ENOMEM;
spec->gen.mixer_nid = 0x1a;
snd_hda_override_amp_caps(codec, 0x1A, HDA_INPUT,
(0x17 << AC_AMPCAP_OFFSET_SHIFT) |
(0x17 << AC_AMPCAP_NUM_STEPS_SHIFT) |
(0x5 << AC_AMPCAP_STEP_SIZE_SHIFT) |
(1 << AC_AMPCAP_MUTE_SHIFT));
err = via_parse_auto_config(codec);
if (err < 0) {
via_free(codec);
return err;
}
spec->init_verbs[spec->num_iverbs++] = vt1702_init_verbs;
codec->patch_ops = via_patch_ops;
return 0;
}
static int add_secret_dac_path(struct hda_codec *codec)
{
struct via_spec *spec = codec->spec;
int i, nums;
hda_nid_t conn[8];
hda_nid_t nid;
if (!spec->gen.mixer_nid)
return 0;
nums = snd_hda_get_connections(codec, spec->gen.mixer_nid, conn,
ARRAY_SIZE(conn) - 1);
for (i = 0; i < nums; i++) {
if (get_wcaps_type(get_wcaps(codec, conn[i])) == AC_WID_AUD_OUT)
return 0;
}
for_each_hda_codec_node(nid, codec) {
unsigned int caps = get_wcaps(codec, nid);
if (get_wcaps_type(caps) == AC_WID_AUD_OUT &&
!(caps & AC_WCAP_DIGITAL)) {
conn[nums++] = nid;
return snd_hda_override_conn_list(codec,
spec->gen.mixer_nid,
nums, conn);
}
}
return 0;
}
static int patch_vt1718S(struct hda_codec *codec)
{
struct via_spec *spec;
int err;
spec = via_new_spec(codec);
if (spec == NULL)
return -ENOMEM;
spec->gen.mixer_nid = 0x21;
override_mic_boost(codec, 0x2b, 0, 3, 40);
override_mic_boost(codec, 0x29, 0, 3, 40);
add_secret_dac_path(codec);
err = via_parse_auto_config(codec);
if (err < 0) {
via_free(codec);
return err;
}
spec->init_verbs[spec->num_iverbs++] = vt1718S_init_verbs;
codec->patch_ops = via_patch_ops;
return 0;
}
static int vt1716s_dmic_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_BOOLEAN;
uinfo->count = 1;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = 1;
return 0;
}
static int vt1716s_dmic_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
int index = 0;
index = snd_hda_codec_read(codec, 0x26, 0,
AC_VERB_GET_CONNECT_SEL, 0);
if (index != -1)
*ucontrol->value.integer.value = index;
return 0;
}
static int vt1716s_dmic_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct via_spec *spec = codec->spec;
int index = *ucontrol->value.integer.value;
snd_hda_codec_write(codec, 0x26, 0,
AC_VERB_SET_CONNECT_SEL, index);
spec->dmic_enabled = index;
return 1;
}
static int patch_vt1716S(struct hda_codec *codec)
{
struct via_spec *spec;
int err;
spec = via_new_spec(codec);
if (spec == NULL)
return -ENOMEM;
spec->gen.mixer_nid = 0x16;
override_mic_boost(codec, 0x1a, 0, 3, 40);
override_mic_boost(codec, 0x1e, 0, 3, 40);
err = via_parse_auto_config(codec);
if (err < 0) {
via_free(codec);
return err;
}
spec->init_verbs[spec->num_iverbs++] = vt1716S_init_verbs;
spec->mixers[spec->num_mixers++] = vt1716s_dmic_mixer;
spec->mixers[spec->num_mixers++] = vt1716S_mono_out_mixer;
codec->patch_ops = via_patch_ops;
return 0;
}
static void via_fixup_intmic_boost(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
if (action == HDA_FIXUP_ACT_PRE_PROBE)
override_mic_boost(codec, 0x30, 0, 2, 40);
}
static void fix_vt1802_connections(struct hda_codec *codec)
{
static hda_nid_t conn_24[] = { 0x14, 0x1c };
static hda_nid_t conn_33[] = { 0x1c };
snd_hda_override_conn_list(codec, 0x24, ARRAY_SIZE(conn_24), conn_24);
snd_hda_override_conn_list(codec, 0x33, ARRAY_SIZE(conn_33), conn_33);
}
static int patch_vt2002P(struct hda_codec *codec)
{
struct via_spec *spec;
int err;
spec = via_new_spec(codec);
if (spec == NULL)
return -ENOMEM;
spec->gen.mixer_nid = 0x21;
override_mic_boost(codec, 0x2b, 0, 3, 40);
override_mic_boost(codec, 0x29, 0, 3, 40);
if (spec->codec_type == VT1802)
fix_vt1802_connections(codec);
add_secret_dac_path(codec);
snd_hda_pick_fixup(codec, NULL, vt2002p_fixups, via_fixups);
snd_hda_apply_fixup(codec, HDA_FIXUP_ACT_PRE_PROBE);
err = via_parse_auto_config(codec);
if (err < 0) {
via_free(codec);
return err;
}
if (spec->codec_type == VT1802)
spec->init_verbs[spec->num_iverbs++] = vt1802_init_verbs;
else
spec->init_verbs[spec->num_iverbs++] = vt2002P_init_verbs;
codec->patch_ops = via_patch_ops;
return 0;
}
static int patch_vt1812(struct hda_codec *codec)
{
struct via_spec *spec;
int err;
spec = via_new_spec(codec);
if (spec == NULL)
return -ENOMEM;
spec->gen.mixer_nid = 0x21;
override_mic_boost(codec, 0x2b, 0, 3, 40);
override_mic_boost(codec, 0x29, 0, 3, 40);
add_secret_dac_path(codec);
err = via_parse_auto_config(codec);
if (err < 0) {
via_free(codec);
return err;
}
spec->init_verbs[spec->num_iverbs++] = vt1812_init_verbs;
codec->patch_ops = via_patch_ops;
return 0;
}
static int patch_vt3476(struct hda_codec *codec)
{
struct via_spec *spec;
int err;
spec = via_new_spec(codec);
if (spec == NULL)
return -ENOMEM;
spec->gen.mixer_nid = 0x3f;
add_secret_dac_path(codec);
err = via_parse_auto_config(codec);
if (err < 0) {
via_free(codec);
return err;
}
spec->init_verbs[spec->num_iverbs++] = vt3476_init_verbs;
codec->patch_ops = via_patch_ops;
return 0;
}
