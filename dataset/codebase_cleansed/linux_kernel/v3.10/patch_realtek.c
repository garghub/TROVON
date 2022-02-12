static void add_mixer(struct alc_spec *spec, const struct snd_kcontrol_new *mix)
{
if (snd_BUG_ON(spec->num_mixers >= ARRAY_SIZE(spec->mixers)))
return;
spec->mixers[spec->num_mixers++] = mix;
}
static void alc_fix_pll(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
unsigned int val;
if (!spec->pll_nid)
return;
snd_hda_codec_write(codec, spec->pll_nid, 0, AC_VERB_SET_COEF_INDEX,
spec->pll_coef_idx);
val = snd_hda_codec_read(codec, spec->pll_nid, 0,
AC_VERB_GET_PROC_COEF, 0);
snd_hda_codec_write(codec, spec->pll_nid, 0, AC_VERB_SET_COEF_INDEX,
spec->pll_coef_idx);
snd_hda_codec_write(codec, spec->pll_nid, 0, AC_VERB_SET_PROC_COEF,
val & ~(1 << spec->pll_coef_bit));
}
static void alc_fix_pll_init(struct hda_codec *codec, hda_nid_t nid,
unsigned int coef_idx, unsigned int coef_bit)
{
struct alc_spec *spec = codec->spec;
spec->pll_nid = nid;
spec->pll_coef_idx = coef_idx;
spec->pll_coef_bit = coef_bit;
alc_fix_pll(codec);
}
static void alc_update_knob_master(struct hda_codec *codec, struct hda_jack_tbl *jack)
{
unsigned int val;
struct snd_kcontrol *kctl;
struct snd_ctl_elem_value *uctl;
kctl = snd_hda_find_mixer_ctl(codec, "Master Playback Volume");
if (!kctl)
return;
uctl = kzalloc(sizeof(*uctl), GFP_KERNEL);
if (!uctl)
return;
val = snd_hda_codec_read(codec, jack->nid, 0,
AC_VERB_GET_VOLUME_KNOB_CONTROL, 0);
val &= HDA_AMP_VOLMASK;
uctl->value.integer.value[0] = val;
uctl->value.integer.value[1] = val;
kctl->put(kctl, uctl);
kfree(uctl);
}
static void alc880_unsol_event(struct hda_codec *codec, unsigned int res)
{
snd_hda_jack_unsol_event(codec, res >> 2);
}
static void alc888_coef_init(struct hda_codec *codec)
{
unsigned int tmp;
snd_hda_codec_write(codec, 0x20, 0, AC_VERB_SET_COEF_INDEX, 0);
tmp = snd_hda_codec_read(codec, 0x20, 0, AC_VERB_GET_PROC_COEF, 0);
snd_hda_codec_write(codec, 0x20, 0, AC_VERB_SET_COEF_INDEX, 7);
if ((tmp & 0xf0) == 0x20)
snd_hda_codec_read(codec, 0x20, 0,
AC_VERB_SET_PROC_COEF, 0x830);
else
snd_hda_codec_read(codec, 0x20, 0,
AC_VERB_SET_PROC_COEF, 0x3030);
}
static void alc889_coef_init(struct hda_codec *codec)
{
unsigned int tmp;
snd_hda_codec_write(codec, 0x20, 0, AC_VERB_SET_COEF_INDEX, 7);
tmp = snd_hda_codec_read(codec, 0x20, 0, AC_VERB_GET_PROC_COEF, 0);
snd_hda_codec_write(codec, 0x20, 0, AC_VERB_SET_COEF_INDEX, 7);
snd_hda_codec_write(codec, 0x20, 0, AC_VERB_SET_PROC_COEF, tmp|0x2010);
}
static void set_eapd(struct hda_codec *codec, hda_nid_t nid, int on)
{
if (get_wcaps_type(get_wcaps(codec, nid)) != AC_WID_PIN)
return;
if (snd_hda_query_pin_caps(codec, nid) & AC_PINCAP_EAPD)
snd_hda_codec_write(codec, nid, 0, AC_VERB_SET_EAPD_BTLENABLE,
on ? 2 : 0);
}
static void alc_auto_setup_eapd(struct hda_codec *codec, bool on)
{
static hda_nid_t pins[] = {
0x0f, 0x10, 0x14, 0x15, 0
};
hda_nid_t *p;
for (p = pins; *p; p++)
set_eapd(codec, *p, on);
}
static void alc_eapd_shutup(struct hda_codec *codec)
{
alc_auto_setup_eapd(codec, false);
msleep(200);
}
static void alc_auto_init_amp(struct hda_codec *codec, int type)
{
unsigned int tmp;
alc_auto_setup_eapd(codec, true);
switch (type) {
case ALC_INIT_GPIO1:
snd_hda_sequence_write(codec, alc_gpio1_init_verbs);
break;
case ALC_INIT_GPIO2:
snd_hda_sequence_write(codec, alc_gpio2_init_verbs);
break;
case ALC_INIT_GPIO3:
snd_hda_sequence_write(codec, alc_gpio3_init_verbs);
break;
case ALC_INIT_DEFAULT:
switch (codec->vendor_id) {
case 0x10ec0260:
snd_hda_codec_write(codec, 0x1a, 0,
AC_VERB_SET_COEF_INDEX, 7);
tmp = snd_hda_codec_read(codec, 0x1a, 0,
AC_VERB_GET_PROC_COEF, 0);
snd_hda_codec_write(codec, 0x1a, 0,
AC_VERB_SET_COEF_INDEX, 7);
snd_hda_codec_write(codec, 0x1a, 0,
AC_VERB_SET_PROC_COEF,
tmp | 0x2010);
break;
case 0x10ec0262:
case 0x10ec0880:
case 0x10ec0882:
case 0x10ec0883:
case 0x10ec0885:
case 0x10ec0887:
alc889_coef_init(codec);
break;
case 0x10ec0888:
alc888_coef_init(codec);
break;
#if 0
case 0x10ec0267:
case 0x10ec0268:
snd_hda_codec_write(codec, 0x20, 0,
AC_VERB_SET_COEF_INDEX, 7);
tmp = snd_hda_codec_read(codec, 0x20, 0,
AC_VERB_GET_PROC_COEF, 0);
snd_hda_codec_write(codec, 0x20, 0,
AC_VERB_SET_COEF_INDEX, 7);
snd_hda_codec_write(codec, 0x20, 0,
AC_VERB_SET_PROC_COEF,
tmp | 0x3000);
break;
#endif
}
break;
}
}
static void alc_fixup_sku_ignore(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
struct alc_spec *spec = codec->spec;
if (action == HDA_FIXUP_ACT_PRE_PROBE) {
spec->cdefine.fixup = 1;
spec->cdefine.sku_cfg = ALC_FIXUP_SKU_IGNORE;
}
}
static int alc_auto_parse_customize_define(struct hda_codec *codec)
{
unsigned int ass, tmp, i;
unsigned nid = 0;
struct alc_spec *spec = codec->spec;
spec->cdefine.enable_pcbeep = 1;
if (spec->cdefine.fixup) {
ass = spec->cdefine.sku_cfg;
if (ass == ALC_FIXUP_SKU_IGNORE)
return -1;
goto do_sku;
}
ass = codec->subsystem_id & 0xffff;
if (ass != codec->bus->pci->subsystem_device && (ass & 1))
goto do_sku;
nid = 0x1d;
if (codec->vendor_id == 0x10ec0260)
nid = 0x17;
ass = snd_hda_codec_get_pincfg(codec, nid);
if (!(ass & 1)) {
printk(KERN_INFO "hda_codec: %s: SKU not ready 0x%08x\n",
codec->chip_name, ass);
return -1;
}
tmp = 0;
for (i = 1; i < 16; i++) {
if ((ass >> i) & 1)
tmp++;
}
if (((ass >> 16) & 0xf) != tmp)
return -1;
spec->cdefine.port_connectivity = ass >> 30;
spec->cdefine.enable_pcbeep = (ass & 0x100000) >> 20;
spec->cdefine.check_sum = (ass >> 16) & 0xf;
spec->cdefine.customization = ass >> 8;
do_sku:
spec->cdefine.sku_cfg = ass;
spec->cdefine.external_amp = (ass & 0x38) >> 3;
spec->cdefine.platform_type = (ass & 0x4) >> 2;
spec->cdefine.swap = (ass & 0x2) >> 1;
spec->cdefine.override = ass & 0x1;
snd_printd("SKU: Nid=0x%x sku_cfg=0x%08x\n",
nid, spec->cdefine.sku_cfg);
snd_printd("SKU: port_connectivity=0x%x\n",
spec->cdefine.port_connectivity);
snd_printd("SKU: enable_pcbeep=0x%x\n", spec->cdefine.enable_pcbeep);
snd_printd("SKU: check_sum=0x%08x\n", spec->cdefine.check_sum);
snd_printd("SKU: customization=0x%08x\n", spec->cdefine.customization);
snd_printd("SKU: external_amp=0x%x\n", spec->cdefine.external_amp);
snd_printd("SKU: platform_type=0x%x\n", spec->cdefine.platform_type);
snd_printd("SKU: swap=0x%x\n", spec->cdefine.swap);
snd_printd("SKU: override=0x%x\n", spec->cdefine.override);
return 0;
}
static int find_idx_in_nid_list(hda_nid_t nid, const hda_nid_t *list, int nums)
{
int i;
for (i = 0; i < nums; i++)
if (list[i] == nid)
return i;
return -1;
}
static bool found_in_nid_list(hda_nid_t nid, const hda_nid_t *list, int nums)
{
return find_idx_in_nid_list(nid, list, nums) >= 0;
}
static int alc_subsystem_id(struct hda_codec *codec,
hda_nid_t porta, hda_nid_t porte,
hda_nid_t portd, hda_nid_t porti)
{
unsigned int ass, tmp, i;
unsigned nid;
struct alc_spec *spec = codec->spec;
if (spec->cdefine.fixup) {
ass = spec->cdefine.sku_cfg;
if (ass == ALC_FIXUP_SKU_IGNORE)
return 0;
goto do_sku;
}
ass = codec->subsystem_id & 0xffff;
if ((ass != codec->bus->pci->subsystem_device) && (ass & 1))
goto do_sku;
nid = 0x1d;
if (codec->vendor_id == 0x10ec0260)
nid = 0x17;
ass = snd_hda_codec_get_pincfg(codec, nid);
snd_printd("realtek: No valid SSID, "
"checking pincfg 0x%08x for NID 0x%x\n",
ass, nid);
if (!(ass & 1))
return 0;
if ((ass >> 30) != 1)
return 0;
tmp = 0;
for (i = 1; i < 16; i++) {
if ((ass >> i) & 1)
tmp++;
}
if (((ass >> 16) & 0xf) != tmp)
return 0;
do_sku:
snd_printd("realtek: Enabling init ASM_ID=0x%04x CODEC_ID=%08x\n",
ass & 0xffff, codec->vendor_id);
tmp = (ass & 0x38) >> 3;
switch (tmp) {
case 1:
spec->init_amp = ALC_INIT_GPIO1;
break;
case 3:
spec->init_amp = ALC_INIT_GPIO2;
break;
case 7:
spec->init_amp = ALC_INIT_GPIO3;
break;
case 5:
default:
spec->init_amp = ALC_INIT_DEFAULT;
break;
}
if (!(ass & 0x8000))
return 1;
if (!spec->gen.autocfg.hp_pins[0] &&
!(spec->gen.autocfg.line_out_pins[0] &&
spec->gen.autocfg.line_out_type == AUTO_PIN_HP_OUT)) {
hda_nid_t nid;
tmp = (ass >> 11) & 0x3;
if (tmp == 0)
nid = porta;
else if (tmp == 1)
nid = porte;
else if (tmp == 2)
nid = portd;
else if (tmp == 3)
nid = porti;
else
return 1;
if (found_in_nid_list(nid, spec->gen.autocfg.line_out_pins,
spec->gen.autocfg.line_outs))
return 1;
spec->gen.autocfg.hp_pins[0] = nid;
}
return 1;
}
static void alc_ssid_check(struct hda_codec *codec, const hda_nid_t *ports)
{
if (!alc_subsystem_id(codec, ports[0], ports[1], ports[2], ports[3])) {
struct alc_spec *spec = codec->spec;
snd_printd("realtek: "
"Enable default setup for auto mode as fallback\n");
spec->init_amp = ALC_INIT_DEFAULT;
}
}
static int alc_read_coef_idx(struct hda_codec *codec,
unsigned int coef_idx)
{
unsigned int val;
snd_hda_codec_write(codec, 0x20, 0, AC_VERB_SET_COEF_INDEX,
coef_idx);
val = snd_hda_codec_read(codec, 0x20, 0,
AC_VERB_GET_PROC_COEF, 0);
return val;
}
static void alc_write_coef_idx(struct hda_codec *codec, unsigned int coef_idx,
unsigned int coef_val)
{
snd_hda_codec_write(codec, 0x20, 0, AC_VERB_SET_COEF_INDEX,
coef_idx);
snd_hda_codec_write(codec, 0x20, 0, AC_VERB_SET_PROC_COEF,
coef_val);
}
static unsigned int alc_get_coef0(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
if (!spec->coef0)
spec->coef0 = alc_read_coef_idx(codec, 0);
return spec->coef0;
}
static hda_nid_t get_adc_nid(struct hda_codec *codec, int adc_idx, int imux_idx)
{
struct hda_gen_spec *spec = codec->spec;
if (spec->dyn_adc_switch)
adc_idx = spec->dyn_adc_idx[imux_idx];
return spec->adc_nids[adc_idx];
}
static void alc_inv_dmic_sync_adc(struct hda_codec *codec, int adc_idx)
{
struct alc_spec *spec = codec->spec;
struct hda_input_mux *imux = &spec->gen.input_mux;
struct nid_path *path;
hda_nid_t nid;
int i, dir, parm;
unsigned int val;
for (i = 0; i < imux->num_items; i++) {
if (spec->gen.imux_pins[i] == spec->inv_dmic_pin)
break;
}
if (i >= imux->num_items)
return;
path = snd_hda_get_nid_path(codec, spec->inv_dmic_pin,
get_adc_nid(codec, adc_idx, i));
val = path->ctls[NID_PATH_MUTE_CTL];
if (!val)
return;
nid = get_amp_nid_(val);
dir = get_amp_direction_(val);
parm = AC_AMP_SET_RIGHT |
(dir == HDA_OUTPUT ? AC_AMP_SET_OUTPUT : AC_AMP_SET_INPUT);
snd_hda_codec_flush_cache(codec);
val = snd_hda_codec_amp_read(codec, nid, 1, dir, 0);
if (val & 0x80)
return;
val |= 0x80;
snd_hda_codec_write(codec, nid, 0, AC_VERB_SET_AMP_GAIN_MUTE,
parm | val);
}
static void alc_inv_dmic_sync(struct hda_codec *codec, bool force)
{
struct alc_spec *spec = codec->spec;
int src, nums;
if (!spec->inv_dmic_fixup)
return;
if (!spec->inv_dmic_muted && !force)
return;
nums = spec->gen.dyn_adc_switch ? 1 : spec->gen.num_adc_nids;
for (src = 0; src < nums; src++) {
bool dmic_fixup = false;
if (spec->inv_dmic_muted &&
spec->gen.imux_pins[spec->gen.cur_mux[src]] == spec->inv_dmic_pin)
dmic_fixup = true;
if (!dmic_fixup && !force)
continue;
alc_inv_dmic_sync_adc(codec, src);
}
}
static void alc_inv_dmic_hook(struct hda_codec *codec,
struct snd_ctl_elem_value *ucontrol)
{
alc_inv_dmic_sync(codec, false);
}
static int alc_inv_dmic_sw_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct alc_spec *spec = codec->spec;
ucontrol->value.integer.value[0] = !spec->inv_dmic_muted;
return 0;
}
static int alc_inv_dmic_sw_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct alc_spec *spec = codec->spec;
unsigned int val = !ucontrol->value.integer.value[0];
if (val == spec->inv_dmic_muted)
return 0;
spec->inv_dmic_muted = val;
alc_inv_dmic_sync(codec, true);
return 0;
}
static int alc_add_inv_dmic_mixer(struct hda_codec *codec, hda_nid_t nid)
{
struct alc_spec *spec = codec->spec;
if (!snd_hda_gen_add_kctl(&spec->gen, NULL, &alc_inv_dmic_sw))
return -ENOMEM;
spec->inv_dmic_fixup = 1;
spec->inv_dmic_muted = 0;
spec->inv_dmic_pin = nid;
spec->gen.cap_sync_hook = alc_inv_dmic_hook;
return 0;
}
static void alc_fixup_inv_dmic_0x12(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
if (action == HDA_FIXUP_ACT_PROBE)
alc_add_inv_dmic_mixer(codec, 0x12);
}
static int alc_build_controls(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
int i, err;
err = snd_hda_gen_build_controls(codec);
if (err < 0)
return err;
for (i = 0; i < spec->num_mixers; i++) {
err = snd_hda_add_new_ctls(codec, spec->mixers[i]);
if (err < 0)
return err;
}
#ifdef CONFIG_SND_HDA_INPUT_BEEP
if (spec->beep_amp) {
const struct snd_kcontrol_new *knew;
for (knew = alc_beep_mixer; knew->name; knew++) {
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
#endif
snd_hda_apply_fixup(codec, HDA_FIXUP_ACT_BUILD);
return 0;
}
static int alc_init(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
if (spec->init_hook)
spec->init_hook(codec);
alc_fix_pll(codec);
alc_auto_init_amp(codec, spec->init_amp);
snd_hda_gen_init(codec);
snd_hda_apply_fixup(codec, HDA_FIXUP_ACT_INIT);
return 0;
}
static inline void alc_shutup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
if (spec && spec->shutup)
spec->shutup(codec);
snd_hda_shutup_pins(codec);
}
static void alc_power_eapd(struct hda_codec *codec)
{
alc_auto_setup_eapd(codec, false);
}
static int alc_suspend(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
alc_shutup(codec);
if (spec && spec->power_hook)
spec->power_hook(codec);
return 0;
}
static int alc_resume(struct hda_codec *codec)
{
msleep(150);
codec->patch_ops.init(codec);
snd_hda_codec_resume_amp(codec);
snd_hda_codec_resume_cache(codec);
alc_inv_dmic_sync(codec, true);
hda_call_check_power_status(codec, 0x01);
return 0;
}
static int alc_codec_rename(struct hda_codec *codec, const char *name)
{
kfree(codec->chip_name);
codec->chip_name = kstrdup(name, GFP_KERNEL);
if (!codec->chip_name) {
alc_free(codec);
return -ENOMEM;
}
return 0;
}
static int alc_codec_rename_from_preset(struct hda_codec *codec)
{
const struct alc_codec_rename_table *p;
for (p = rename_tbl; p->vendor_id; p++) {
if (p->vendor_id != codec->vendor_id)
continue;
if ((alc_get_coef0(codec) & p->coef_mask) == p->coef_bits)
return alc_codec_rename(codec, p->name);
}
return 0;
}
static inline int has_cdefine_beep(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
const struct snd_pci_quirk *q;
q = snd_pci_quirk_lookup(codec->bus->pci, beep_white_list);
if (q)
return q->value;
return spec->cdefine.enable_pcbeep;
}
static int alc_parse_auto_config(struct hda_codec *codec,
const hda_nid_t *ignore_nids,
const hda_nid_t *ssid_nids)
{
struct alc_spec *spec = codec->spec;
struct auto_pin_cfg *cfg = &spec->gen.autocfg;
int err;
err = snd_hda_parse_pin_defcfg(codec, cfg, ignore_nids,
spec->parse_flags);
if (err < 0)
return err;
if (ssid_nids)
alc_ssid_check(codec, ssid_nids);
err = snd_hda_gen_parse_auto_config(codec, cfg);
if (err < 0)
return err;
return 1;
}
static int alc_alloc_spec(struct hda_codec *codec, hda_nid_t mixer_nid)
{
struct alc_spec *spec = kzalloc(sizeof(*spec), GFP_KERNEL);
int err;
if (!spec)
return -ENOMEM;
codec->spec = spec;
snd_hda_gen_spec_init(&spec->gen);
spec->gen.mixer_nid = mixer_nid;
spec->gen.own_eapd_ctl = 1;
codec->single_adc_amp = 1;
codec->spdif_status_reset = 1;
err = alc_codec_rename_from_preset(codec);
if (err < 0) {
kfree(spec);
return err;
}
return 0;
}
static int alc880_parse_auto_config(struct hda_codec *codec)
{
static const hda_nid_t alc880_ignore[] = { 0x1d, 0 };
static const hda_nid_t alc880_ssids[] = { 0x15, 0x1b, 0x14, 0 };
return alc_parse_auto_config(codec, alc880_ignore, alc880_ssids);
}
static void alc880_fixup_vol_knob(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
if (action == HDA_FIXUP_ACT_PROBE)
snd_hda_jack_detect_enable_callback(codec, 0x21, ALC_DCVOL_EVENT, alc_update_knob_master);
}
static int patch_alc880(struct hda_codec *codec)
{
struct alc_spec *spec;
int err;
err = alc_alloc_spec(codec, 0x0b);
if (err < 0)
return err;
spec = codec->spec;
spec->gen.need_dac_fix = 1;
spec->gen.beep_nid = 0x01;
snd_hda_pick_fixup(codec, alc880_fixup_models, alc880_fixup_tbl,
alc880_fixups);
snd_hda_apply_fixup(codec, HDA_FIXUP_ACT_PRE_PROBE);
err = alc880_parse_auto_config(codec);
if (err < 0)
goto error;
if (!spec->gen.no_analog)
set_beep_amp(spec, 0x0b, 0x05, HDA_INPUT);
codec->patch_ops = alc_patch_ops;
codec->patch_ops.unsol_event = alc880_unsol_event;
snd_hda_apply_fixup(codec, HDA_FIXUP_ACT_PROBE);
return 0;
error:
alc_free(codec);
return err;
}
static int alc260_parse_auto_config(struct hda_codec *codec)
{
static const hda_nid_t alc260_ignore[] = { 0x17, 0 };
static const hda_nid_t alc260_ssids[] = { 0x10, 0x15, 0x0f, 0 };
return alc_parse_auto_config(codec, alc260_ignore, alc260_ssids);
}
static void alc260_gpio1_automute(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
snd_hda_codec_write(codec, 0x01, 0, AC_VERB_SET_GPIO_DATA,
spec->gen.hp_jack_present);
}
static void alc260_fixup_gpio1_toggle(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
struct alc_spec *spec = codec->spec;
if (action == HDA_FIXUP_ACT_PROBE) {
spec->gen.automute_hook = alc260_gpio1_automute;
spec->gen.detect_hp = 1;
spec->gen.automute_speaker = 1;
spec->gen.autocfg.hp_pins[0] = 0x0f;
snd_hda_jack_detect_enable_callback(codec, 0x0f, HDA_GEN_HP_EVENT,
snd_hda_gen_hp_automute);
snd_hda_add_verbs(codec, alc_gpio1_init_verbs);
}
}
static void alc260_fixup_kn1(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
struct alc_spec *spec = codec->spec;
static const struct hda_pintbl pincfgs[] = {
{ 0x0f, 0x02214000 },
{ 0x12, 0x90a60160 },
{ 0x13, 0x02a19000 },
{ 0x18, 0x01446000 },
{ 0x10, 0x411111f0 },
{ 0x11, 0x411111f0 },
{ 0x14, 0x411111f0 },
{ 0x15, 0x411111f0 },
{ 0x16, 0x411111f0 },
{ 0x17, 0x411111f0 },
{ 0x19, 0x411111f0 },
{ }
};
switch (action) {
case HDA_FIXUP_ACT_PRE_PROBE:
snd_hda_apply_pincfgs(codec, pincfgs);
break;
case HDA_FIXUP_ACT_PROBE:
spec->init_amp = ALC_INIT_NONE;
break;
}
}
static void alc260_fixup_fsc_s7020(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
struct alc_spec *spec = codec->spec;
if (action == HDA_FIXUP_ACT_PROBE)
spec->init_amp = ALC_INIT_NONE;
}
static void alc260_fixup_fsc_s7020_jwse(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
struct alc_spec *spec = codec->spec;
if (action == HDA_FIXUP_ACT_PRE_PROBE) {
spec->gen.add_jack_modes = 1;
spec->gen.hp_mic = 1;
}
}
static int patch_alc260(struct hda_codec *codec)
{
struct alc_spec *spec;
int err;
err = alc_alloc_spec(codec, 0x07);
if (err < 0)
return err;
spec = codec->spec;
spec->gen.prefer_hp_amp = 1;
spec->gen.beep_nid = 0x01;
snd_hda_pick_fixup(codec, alc260_fixup_models, alc260_fixup_tbl,
alc260_fixups);
snd_hda_apply_fixup(codec, HDA_FIXUP_ACT_PRE_PROBE);
err = alc260_parse_auto_config(codec);
if (err < 0)
goto error;
if (!spec->gen.no_analog)
set_beep_amp(spec, 0x07, 0x05, HDA_INPUT);
codec->patch_ops = alc_patch_ops;
spec->shutup = alc_eapd_shutup;
snd_hda_apply_fixup(codec, HDA_FIXUP_ACT_PROBE);
return 0;
error:
alc_free(codec);
return err;
}
static void alc889_fixup_coef(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
if (action != HDA_FIXUP_ACT_INIT)
return;
alc889_coef_init(codec);
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
static void alc885_fixup_macpro_gpio(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
if (action != HDA_FIXUP_ACT_INIT)
return;
alc882_gpio_mute(codec, 0, 0);
alc882_gpio_mute(codec, 1, 0);
}
static void alc889_fixup_dac_route(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
if (action == HDA_FIXUP_ACT_PRE_PROBE) {
hda_nid_t conn1[2] = { 0x0c, 0x0d };
hda_nid_t conn2[2] = { 0x0e, 0x0f };
snd_hda_override_conn_list(codec, 0x14, 2, conn1);
snd_hda_override_conn_list(codec, 0x15, 2, conn1);
snd_hda_override_conn_list(codec, 0x18, 2, conn2);
snd_hda_override_conn_list(codec, 0x1a, 2, conn2);
} else if (action == HDA_FIXUP_ACT_PROBE) {
hda_nid_t conn[5] = { 0x0c, 0x0d, 0x0e, 0x0f, 0x26 };
snd_hda_override_conn_list(codec, 0x14, 5, conn);
snd_hda_override_conn_list(codec, 0x15, 5, conn);
snd_hda_override_conn_list(codec, 0x18, 5, conn);
snd_hda_override_conn_list(codec, 0x1a, 5, conn);
}
}
static void alc889_fixup_mbp_vref(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
struct alc_spec *spec = codec->spec;
static hda_nid_t nids[2] = { 0x14, 0x15 };
int i;
if (action != HDA_FIXUP_ACT_INIT)
return;
for (i = 0; i < ARRAY_SIZE(nids); i++) {
unsigned int val = snd_hda_codec_get_pincfg(codec, nids[i]);
if (get_defcfg_device(val) != AC_JACK_HP_OUT)
continue;
val = snd_hda_codec_get_pin_target(codec, nids[i]);
val |= AC_PINCTL_VREF_80;
snd_hda_set_pin_ctl(codec, nids[i], val);
spec->gen.keep_vref_in_automute = 1;
break;
}
}
static void alc889_fixup_imac91_vref(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
struct alc_spec *spec = codec->spec;
static hda_nid_t nids[2] = { 0x18, 0x1a };
int i;
if (action != HDA_FIXUP_ACT_INIT)
return;
for (i = 0; i < ARRAY_SIZE(nids); i++) {
unsigned int val;
val = snd_hda_codec_get_pin_target(codec, nids[i]);
val |= AC_PINCTL_VREF_50;
snd_hda_set_pin_ctl(codec, nids[i], val);
}
spec->gen.keep_vref_in_automute = 1;
}
static void alc882_fixup_no_primary_hp(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
struct alc_spec *spec = codec->spec;
if (action == HDA_FIXUP_ACT_PRE_PROBE)
spec->gen.no_primary_hp = 1;
}
static int alc882_parse_auto_config(struct hda_codec *codec)
{
static const hda_nid_t alc882_ignore[] = { 0x1d, 0 };
static const hda_nid_t alc882_ssids[] = { 0x15, 0x1b, 0x14, 0 };
return alc_parse_auto_config(codec, alc882_ignore, alc882_ssids);
}
static int patch_alc882(struct hda_codec *codec)
{
struct alc_spec *spec;
int err;
err = alc_alloc_spec(codec, 0x0b);
if (err < 0)
return err;
spec = codec->spec;
switch (codec->vendor_id) {
case 0x10ec0882:
case 0x10ec0885:
break;
default:
alc_fix_pll_init(codec, 0x20, 0x0a, 10);
break;
}
snd_hda_pick_fixup(codec, alc882_fixup_models, alc882_fixup_tbl,
alc882_fixups);
snd_hda_apply_fixup(codec, HDA_FIXUP_ACT_PRE_PROBE);
alc_auto_parse_customize_define(codec);
if (has_cdefine_beep(codec))
spec->gen.beep_nid = 0x01;
err = alc882_parse_auto_config(codec);
if (err < 0)
goto error;
if (!spec->gen.no_analog && spec->gen.beep_nid)
set_beep_amp(spec, 0x0b, 0x05, HDA_INPUT);
codec->patch_ops = alc_patch_ops;
snd_hda_apply_fixup(codec, HDA_FIXUP_ACT_PROBE);
return 0;
error:
alc_free(codec);
return err;
}
static int alc262_parse_auto_config(struct hda_codec *codec)
{
static const hda_nid_t alc262_ignore[] = { 0x1d, 0 };
static const hda_nid_t alc262_ssids[] = { 0x15, 0x1b, 0x14, 0 };
return alc_parse_auto_config(codec, alc262_ignore, alc262_ssids);
}
static int patch_alc262(struct hda_codec *codec)
{
struct alc_spec *spec;
int err;
err = alc_alloc_spec(codec, 0x0b);
if (err < 0)
return err;
spec = codec->spec;
spec->gen.shared_mic_vref_pin = 0x18;
#if 0
{
int tmp;
snd_hda_codec_write(codec, 0x1a, 0, AC_VERB_SET_COEF_INDEX, 7);
tmp = snd_hda_codec_read(codec, 0x20, 0, AC_VERB_GET_PROC_COEF, 0);
snd_hda_codec_write(codec, 0x1a, 0, AC_VERB_SET_COEF_INDEX, 7);
snd_hda_codec_write(codec, 0x1a, 0, AC_VERB_SET_PROC_COEF, tmp | 0x80);
}
#endif
alc_fix_pll_init(codec, 0x20, 0x0a, 10);
snd_hda_pick_fixup(codec, alc262_fixup_models, alc262_fixup_tbl,
alc262_fixups);
snd_hda_apply_fixup(codec, HDA_FIXUP_ACT_PRE_PROBE);
alc_auto_parse_customize_define(codec);
if (has_cdefine_beep(codec))
spec->gen.beep_nid = 0x01;
err = alc262_parse_auto_config(codec);
if (err < 0)
goto error;
if (!spec->gen.no_analog && spec->gen.beep_nid)
set_beep_amp(spec, 0x0b, 0x05, HDA_INPUT);
codec->patch_ops = alc_patch_ops;
spec->shutup = alc_eapd_shutup;
snd_hda_apply_fixup(codec, HDA_FIXUP_ACT_PROBE);
return 0;
error:
alc_free(codec);
return err;
}
static int alc268_parse_auto_config(struct hda_codec *codec)
{
static const hda_nid_t alc268_ssids[] = { 0x15, 0x1b, 0x14, 0 };
return alc_parse_auto_config(codec, NULL, alc268_ssids);
}
static int patch_alc268(struct hda_codec *codec)
{
struct alc_spec *spec;
int err;
err = alc_alloc_spec(codec, 0);
if (err < 0)
return err;
spec = codec->spec;
spec->gen.beep_nid = 0x01;
snd_hda_pick_fixup(codec, alc268_fixup_models, alc268_fixup_tbl, alc268_fixups);
snd_hda_apply_fixup(codec, HDA_FIXUP_ACT_PRE_PROBE);
err = alc268_parse_auto_config(codec);
if (err < 0)
goto error;
if (err > 0 && !spec->gen.no_analog &&
spec->gen.autocfg.speaker_pins[0] != 0x1d) {
add_mixer(spec, alc268_beep_mixer);
snd_hda_add_verbs(codec, alc268_beep_init_verbs);
if (!query_amp_caps(codec, 0x1d, HDA_INPUT))
snd_hda_override_amp_caps(codec, 0x1d, HDA_INPUT,
(0x0c << AC_AMPCAP_OFFSET_SHIFT) |
(0x0c << AC_AMPCAP_NUM_STEPS_SHIFT) |
(0x07 << AC_AMPCAP_STEP_SIZE_SHIFT) |
(0 << AC_AMPCAP_MUTE_SHIFT));
}
codec->patch_ops = alc_patch_ops;
spec->shutup = alc_eapd_shutup;
snd_hda_apply_fixup(codec, HDA_FIXUP_ACT_PROBE);
return 0;
error:
alc_free(codec);
return err;
}
static int playback_pcm_open(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
struct snd_pcm_substream *substream)
{
struct hda_gen_spec *spec = codec->spec;
return snd_hda_multi_out_analog_open(codec, &spec->multiout, substream,
hinfo);
}
static int playback_pcm_prepare(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
unsigned int stream_tag,
unsigned int format,
struct snd_pcm_substream *substream)
{
struct hda_gen_spec *spec = codec->spec;
return snd_hda_multi_out_analog_prepare(codec, &spec->multiout,
stream_tag, format, substream);
}
static int playback_pcm_cleanup(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
struct snd_pcm_substream *substream)
{
struct hda_gen_spec *spec = codec->spec;
return snd_hda_multi_out_analog_cleanup(codec, &spec->multiout);
}
static int alc269_parse_auto_config(struct hda_codec *codec)
{
static const hda_nid_t alc269_ignore[] = { 0x1d, 0 };
static const hda_nid_t alc269_ssids[] = { 0, 0x1b, 0x14, 0x21 };
static const hda_nid_t alc269va_ssids[] = { 0x15, 0x1b, 0x14, 0 };
struct alc_spec *spec = codec->spec;
const hda_nid_t *ssids;
switch (spec->codec_variant) {
case ALC269_TYPE_ALC269VA:
case ALC269_TYPE_ALC269VC:
case ALC269_TYPE_ALC280:
case ALC269_TYPE_ALC284:
ssids = alc269va_ssids;
break;
case ALC269_TYPE_ALC269VB:
case ALC269_TYPE_ALC269VD:
case ALC269_TYPE_ALC282:
case ALC269_TYPE_ALC286:
ssids = alc269_ssids;
break;
default:
ssids = alc269_ssids;
break;
}
return alc_parse_auto_config(codec, alc269_ignore, ssids);
}
static void alc269vb_toggle_power_output(struct hda_codec *codec, int power_up)
{
int val = alc_read_coef_idx(codec, 0x04);
if (power_up)
val |= 1 << 11;
else
val &= ~(1 << 11);
alc_write_coef_idx(codec, 0x04, val);
}
static void alc269_shutup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
if (spec->codec_variant != ALC269_TYPE_ALC269VB)
return;
if (spec->codec_variant == ALC269_TYPE_ALC269VB)
alc269vb_toggle_power_output(codec, 0);
if (spec->codec_variant == ALC269_TYPE_ALC269VB &&
(alc_get_coef0(codec) & 0x00ff) == 0x018) {
msleep(150);
}
}
static int alc269_resume(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
if (spec->codec_variant == ALC269_TYPE_ALC269VB)
alc269vb_toggle_power_output(codec, 0);
if (spec->codec_variant == ALC269_TYPE_ALC269VB &&
(alc_get_coef0(codec) & 0x00ff) == 0x018) {
msleep(150);
}
codec->patch_ops.init(codec);
if (spec->codec_variant == ALC269_TYPE_ALC269VB)
alc269vb_toggle_power_output(codec, 1);
if (spec->codec_variant == ALC269_TYPE_ALC269VB &&
(alc_get_coef0(codec) & 0x00ff) == 0x017) {
msleep(200);
}
snd_hda_codec_resume_amp(codec);
snd_hda_codec_resume_cache(codec);
hda_call_check_power_status(codec, 0x01);
return 0;
}
static void alc269_fixup_pincfg_no_hp_to_lineout(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
struct alc_spec *spec = codec->spec;
if (action == HDA_FIXUP_ACT_PRE_PROBE)
spec->parse_flags = HDA_PINCFG_NO_HP_FIXUP;
}
static void alc269_fixup_hweq(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
int coef;
if (action != HDA_FIXUP_ACT_INIT)
return;
coef = alc_read_coef_idx(codec, 0x1e);
alc_write_coef_idx(codec, 0x1e, coef | 0x80);
}
static void alc271_fixup_dmic(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
static const struct hda_verb verbs[] = {
{0x20, AC_VERB_SET_COEF_INDEX, 0x0d},
{0x20, AC_VERB_SET_PROC_COEF, 0x4000},
{}
};
unsigned int cfg;
if (strcmp(codec->chip_name, "ALC271X") &&
strcmp(codec->chip_name, "ALC269VB"))
return;
cfg = snd_hda_codec_get_pincfg(codec, 0x12);
if (get_defcfg_connect(cfg) == AC_JACK_PORT_FIXED)
snd_hda_sequence_write(codec, verbs);
}
static void alc269_fixup_pcm_44k(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
struct alc_spec *spec = codec->spec;
if (action != HDA_FIXUP_ACT_PROBE)
return;
spec->gen.stream_analog_playback = &alc269_44k_pcm_analog_playback;
spec->gen.stream_analog_capture = &alc269_44k_pcm_analog_capture;
}
static void alc269_fixup_stereo_dmic(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
int coef;
if (action != HDA_FIXUP_ACT_INIT)
return;
coef = alc_read_coef_idx(codec, 0x07);
alc_write_coef_idx(codec, 0x07, coef | 0x80);
}
static void alc269_quanta_automute(struct hda_codec *codec)
{
snd_hda_gen_update_outputs(codec);
snd_hda_codec_write(codec, 0x20, 0,
AC_VERB_SET_COEF_INDEX, 0x0c);
snd_hda_codec_write(codec, 0x20, 0,
AC_VERB_SET_PROC_COEF, 0x680);
snd_hda_codec_write(codec, 0x20, 0,
AC_VERB_SET_COEF_INDEX, 0x0c);
snd_hda_codec_write(codec, 0x20, 0,
AC_VERB_SET_PROC_COEF, 0x480);
}
static void alc269_fixup_quanta_mute(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
struct alc_spec *spec = codec->spec;
if (action != HDA_FIXUP_ACT_PROBE)
return;
spec->gen.automute_hook = alc269_quanta_automute;
}
static void alc269_x101_hp_automute_hook(struct hda_codec *codec,
struct hda_jack_tbl *jack)
{
struct alc_spec *spec = codec->spec;
int vref;
msleep(200);
snd_hda_gen_hp_automute(codec, jack);
vref = spec->gen.hp_jack_present ? PIN_VREF80 : 0;
msleep(100);
snd_hda_codec_write(codec, 0x18, 0, AC_VERB_SET_PIN_WIDGET_CONTROL,
vref);
msleep(500);
snd_hda_codec_write(codec, 0x18, 0, AC_VERB_SET_PIN_WIDGET_CONTROL,
vref);
}
static void alc269_fixup_x101_headset_mic(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
struct alc_spec *spec = codec->spec;
if (action == HDA_FIXUP_ACT_PRE_PROBE) {
spec->parse_flags |= HDA_PINCFG_HEADSET_MIC;
spec->gen.hp_automute_hook = alc269_x101_hp_automute_hook;
}
}
static void alc269_fixup_mic_mute_hook(void *private_data, int enabled)
{
struct hda_codec *codec = private_data;
struct alc_spec *spec = codec->spec;
unsigned int pinval;
if (spec->mute_led_polarity)
enabled = !enabled;
pinval = AC_PINCTL_IN_EN |
(enabled ? AC_PINCTL_VREF_HIZ : AC_PINCTL_VREF_80);
if (spec->mute_led_nid)
snd_hda_set_pin_ctl_cache(codec, spec->mute_led_nid, pinval);
}
static void alc269_fixup_hp_mute_led(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
struct alc_spec *spec = codec->spec;
const struct dmi_device *dev = NULL;
if (action != HDA_FIXUP_ACT_PRE_PROBE)
return;
while ((dev = dmi_find_device(DMI_DEV_TYPE_OEM_STRING, NULL, dev))) {
int pol, pin;
if (sscanf(dev->name, "HP_Mute_LED_%d_%x", &pol, &pin) != 2)
continue;
if (pin < 0x0a || pin >= 0x10)
break;
spec->mute_led_polarity = pol;
spec->mute_led_nid = pin - 0x0a + 0x18;
spec->gen.vmaster_mute.hook = alc269_fixup_mic_mute_hook;
spec->gen.vmaster_mute_enum = 1;
snd_printd("Detected mute LED for %x:%d\n", spec->mute_led_nid,
spec->mute_led_polarity);
break;
}
}
static void alc269_fixup_hp_mute_led_mic1(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
struct alc_spec *spec = codec->spec;
if (action == HDA_FIXUP_ACT_PRE_PROBE) {
spec->mute_led_polarity = 0;
spec->mute_led_nid = 0x18;
spec->gen.vmaster_mute.hook = alc269_fixup_mic_mute_hook;
spec->gen.vmaster_mute_enum = 1;
}
}
static void alc269_fixup_hp_mute_led_mic2(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
struct alc_spec *spec = codec->spec;
if (action == HDA_FIXUP_ACT_PRE_PROBE) {
spec->mute_led_polarity = 0;
spec->mute_led_nid = 0x19;
spec->gen.vmaster_mute.hook = alc269_fixup_mic_mute_hook;
spec->gen.vmaster_mute_enum = 1;
}
}
static void alc269_fixup_hp_gpio_mute_hook(void *private_data, int enabled)
{
struct hda_codec *codec = private_data;
struct alc_spec *spec = codec->spec;
unsigned int oldval = spec->gpio_led;
if (enabled)
spec->gpio_led &= ~0x08;
else
spec->gpio_led |= 0x08;
if (spec->gpio_led != oldval)
snd_hda_codec_write(codec, 0x01, 0, AC_VERB_SET_GPIO_DATA,
spec->gpio_led);
}
static void alc269_fixup_hp_gpio_mic_mute_hook(struct hda_codec *codec,
struct snd_ctl_elem_value *ucontrol)
{
struct alc_spec *spec = codec->spec;
unsigned int oldval = spec->gpio_led;
if (!ucontrol)
return;
if (ucontrol->value.integer.value[0] ||
ucontrol->value.integer.value[1])
spec->gpio_led &= ~0x10;
else
spec->gpio_led |= 0x10;
if (spec->gpio_led != oldval)
snd_hda_codec_write(codec, 0x01, 0, AC_VERB_SET_GPIO_DATA,
spec->gpio_led);
}
static void alc269_fixup_hp_gpio_led(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
struct alc_spec *spec = codec->spec;
static const struct hda_verb gpio_init[] = {
{ 0x01, AC_VERB_SET_GPIO_MASK, 0x18 },
{ 0x01, AC_VERB_SET_GPIO_DIRECTION, 0x18 },
{}
};
if (action == HDA_FIXUP_ACT_PRE_PROBE) {
spec->gen.vmaster_mute.hook = alc269_fixup_hp_gpio_mute_hook;
spec->gen.cap_sync_hook = alc269_fixup_hp_gpio_mic_mute_hook;
spec->gpio_led = 0;
snd_hda_add_verbs(codec, gpio_init);
}
}
static void alc_headset_mode_unplugged(struct hda_codec *codec)
{
int val;
switch (codec->vendor_id) {
case 0x10ec0283:
alc_write_coef_idx(codec, 0x1b, 0x0c0b);
alc_write_coef_idx(codec, 0x45, 0xc429);
val = alc_read_coef_idx(codec, 0x35);
alc_write_coef_idx(codec, 0x35, val & 0xbfff);
alc_write_coef_idx(codec, 0x06, 0x2104);
alc_write_coef_idx(codec, 0x1a, 0x0001);
alc_write_coef_idx(codec, 0x26, 0x0004);
alc_write_coef_idx(codec, 0x32, 0x42a3);
break;
case 0x10ec0292:
alc_write_coef_idx(codec, 0x76, 0x000e);
alc_write_coef_idx(codec, 0x6c, 0x2400);
alc_write_coef_idx(codec, 0x18, 0x7308);
alc_write_coef_idx(codec, 0x6b, 0xc429);
break;
case 0x10ec0668:
alc_write_coef_idx(codec, 0x15, 0x0d40);
alc_write_coef_idx(codec, 0xb7, 0x802b);
break;
}
snd_printdd("Headset jack set to unplugged mode.\n");
}
static void alc_headset_mode_mic_in(struct hda_codec *codec, hda_nid_t hp_pin,
hda_nid_t mic_pin)
{
int val;
switch (codec->vendor_id) {
case 0x10ec0283:
alc_write_coef_idx(codec, 0x45, 0xc429);
snd_hda_set_pin_ctl_cache(codec, hp_pin, 0);
val = alc_read_coef_idx(codec, 0x35);
alc_write_coef_idx(codec, 0x35, val | 1<<14);
alc_write_coef_idx(codec, 0x06, 0x2100);
alc_write_coef_idx(codec, 0x1a, 0x0021);
alc_write_coef_idx(codec, 0x26, 0x008c);
snd_hda_set_pin_ctl_cache(codec, mic_pin, PIN_VREF50);
break;
case 0x10ec0292:
snd_hda_set_pin_ctl_cache(codec, hp_pin, 0);
alc_write_coef_idx(codec, 0x19, 0xa208);
alc_write_coef_idx(codec, 0x2e, 0xacf0);
break;
case 0x10ec0668:
alc_write_coef_idx(codec, 0x11, 0x0001);
snd_hda_set_pin_ctl_cache(codec, hp_pin, 0);
alc_write_coef_idx(codec, 0xb7, 0x802b);
alc_write_coef_idx(codec, 0xb5, 0x1040);
val = alc_read_coef_idx(codec, 0xc3);
alc_write_coef_idx(codec, 0xc3, val | 1<<12);
snd_hda_set_pin_ctl_cache(codec, mic_pin, PIN_VREF50);
break;
}
snd_printdd("Headset jack set to mic-in mode.\n");
}
static void alc_headset_mode_default(struct hda_codec *codec)
{
switch (codec->vendor_id) {
case 0x10ec0283:
alc_write_coef_idx(codec, 0x06, 0x2100);
alc_write_coef_idx(codec, 0x32, 0x4ea3);
break;
case 0x10ec0292:
alc_write_coef_idx(codec, 0x76, 0x000e);
alc_write_coef_idx(codec, 0x6c, 0x2400);
alc_write_coef_idx(codec, 0x6b, 0xc429);
alc_write_coef_idx(codec, 0x18, 0x7308);
break;
case 0x10ec0668:
alc_write_coef_idx(codec, 0x11, 0x0041);
alc_write_coef_idx(codec, 0x15, 0x0d40);
alc_write_coef_idx(codec, 0xb7, 0x802b);
break;
}
snd_printdd("Headset jack set to headphone (default) mode.\n");
}
static void alc_headset_mode_ctia(struct hda_codec *codec)
{
switch (codec->vendor_id) {
case 0x10ec0283:
alc_write_coef_idx(codec, 0x45, 0xd429);
alc_write_coef_idx(codec, 0x1b, 0x0c2b);
alc_write_coef_idx(codec, 0x32, 0x4ea3);
break;
case 0x10ec0292:
alc_write_coef_idx(codec, 0x6b, 0xd429);
alc_write_coef_idx(codec, 0x76, 0x0008);
alc_write_coef_idx(codec, 0x18, 0x7388);
break;
case 0x10ec0668:
alc_write_coef_idx(codec, 0x15, 0x0d60);
alc_write_coef_idx(codec, 0xc3, 0x0000);
break;
}
snd_printdd("Headset jack set to iPhone-style headset mode.\n");
}
static void alc_headset_mode_omtp(struct hda_codec *codec)
{
switch (codec->vendor_id) {
case 0x10ec0283:
alc_write_coef_idx(codec, 0x45, 0xe429);
alc_write_coef_idx(codec, 0x1b, 0x0c2b);
alc_write_coef_idx(codec, 0x32, 0x4ea3);
break;
case 0x10ec0292:
alc_write_coef_idx(codec, 0x6b, 0xe429);
alc_write_coef_idx(codec, 0x76, 0x0008);
alc_write_coef_idx(codec, 0x18, 0x7388);
break;
case 0x10ec0668:
alc_write_coef_idx(codec, 0x15, 0x0d50);
alc_write_coef_idx(codec, 0xc3, 0x0000);
break;
}
snd_printdd("Headset jack set to Nokia-style headset mode.\n");
}
static void alc_determine_headset_type(struct hda_codec *codec)
{
int val;
bool is_ctia = false;
struct alc_spec *spec = codec->spec;
switch (codec->vendor_id) {
case 0x10ec0283:
alc_write_coef_idx(codec, 0x45, 0xd029);
msleep(300);
val = alc_read_coef_idx(codec, 0x46);
is_ctia = (val & 0x0070) == 0x0070;
break;
case 0x10ec0292:
alc_write_coef_idx(codec, 0x6b, 0xd429);
msleep(300);
val = alc_read_coef_idx(codec, 0x6c);
is_ctia = (val & 0x001c) == 0x001c;
break;
case 0x10ec0668:
alc_write_coef_idx(codec, 0x11, 0x0001);
alc_write_coef_idx(codec, 0xb7, 0x802b);
alc_write_coef_idx(codec, 0x15, 0x0d60);
alc_write_coef_idx(codec, 0xc3, 0x0c00);
msleep(300);
val = alc_read_coef_idx(codec, 0xbe);
is_ctia = (val & 0x1c02) == 0x1c02;
break;
}
snd_printdd("Headset jack detected iPhone-style headset: %s\n",
is_ctia ? "yes" : "no");
spec->current_headset_type = is_ctia ? ALC_HEADSET_TYPE_CTIA : ALC_HEADSET_TYPE_OMTP;
}
static void alc_update_headset_mode(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
hda_nid_t mux_pin = spec->gen.imux_pins[spec->gen.cur_mux[0]];
hda_nid_t hp_pin = spec->gen.autocfg.hp_pins[0];
int new_headset_mode;
if (!snd_hda_jack_detect(codec, hp_pin))
new_headset_mode = ALC_HEADSET_MODE_UNPLUGGED;
else if (mux_pin == spec->headset_mic_pin)
new_headset_mode = ALC_HEADSET_MODE_HEADSET;
else if (mux_pin == spec->headphone_mic_pin)
new_headset_mode = ALC_HEADSET_MODE_MIC;
else
new_headset_mode = ALC_HEADSET_MODE_HEADPHONE;
if (new_headset_mode == spec->current_headset_mode)
return;
switch (new_headset_mode) {
case ALC_HEADSET_MODE_UNPLUGGED:
alc_headset_mode_unplugged(codec);
spec->gen.hp_jack_present = false;
break;
case ALC_HEADSET_MODE_HEADSET:
if (spec->current_headset_type == ALC_HEADSET_TYPE_UNKNOWN)
alc_determine_headset_type(codec);
if (spec->current_headset_type == ALC_HEADSET_TYPE_CTIA)
alc_headset_mode_ctia(codec);
else if (spec->current_headset_type == ALC_HEADSET_TYPE_OMTP)
alc_headset_mode_omtp(codec);
spec->gen.hp_jack_present = true;
break;
case ALC_HEADSET_MODE_MIC:
alc_headset_mode_mic_in(codec, hp_pin, spec->headphone_mic_pin);
spec->gen.hp_jack_present = false;
break;
case ALC_HEADSET_MODE_HEADPHONE:
alc_headset_mode_default(codec);
spec->gen.hp_jack_present = true;
break;
}
if (new_headset_mode != ALC_HEADSET_MODE_MIC) {
snd_hda_set_pin_ctl_cache(codec, hp_pin,
AC_PINCTL_OUT_EN | AC_PINCTL_HP_EN);
if (spec->headphone_mic_pin)
snd_hda_set_pin_ctl_cache(codec, spec->headphone_mic_pin,
PIN_VREFHIZ);
}
spec->current_headset_mode = new_headset_mode;
snd_hda_gen_update_outputs(codec);
}
static void alc_update_headset_mode_hook(struct hda_codec *codec,
struct snd_ctl_elem_value *ucontrol)
{
alc_update_headset_mode(codec);
}
static void alc_update_headset_jack_cb(struct hda_codec *codec, struct hda_jack_tbl *jack)
{
struct alc_spec *spec = codec->spec;
spec->current_headset_type = ALC_HEADSET_MODE_UNKNOWN;
snd_hda_gen_hp_automute(codec, jack);
}
static void alc_probe_headset_mode(struct hda_codec *codec)
{
int i;
struct alc_spec *spec = codec->spec;
struct auto_pin_cfg *cfg = &spec->gen.autocfg;
for (i = 0; i < cfg->num_inputs; i++) {
if (cfg->inputs[i].is_headset_mic && !spec->headset_mic_pin)
spec->headset_mic_pin = cfg->inputs[i].pin;
if (cfg->inputs[i].is_headphone_mic && !spec->headphone_mic_pin)
spec->headphone_mic_pin = cfg->inputs[i].pin;
}
spec->gen.cap_sync_hook = alc_update_headset_mode_hook;
spec->gen.automute_hook = alc_update_headset_mode;
spec->gen.hp_automute_hook = alc_update_headset_jack_cb;
}
static void alc_fixup_headset_mode(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
struct alc_spec *spec = codec->spec;
switch (action) {
case HDA_FIXUP_ACT_PRE_PROBE:
spec->parse_flags |= HDA_PINCFG_HEADSET_MIC | HDA_PINCFG_HEADPHONE_MIC;
break;
case HDA_FIXUP_ACT_PROBE:
alc_probe_headset_mode(codec);
break;
case HDA_FIXUP_ACT_INIT:
spec->current_headset_mode = 0;
alc_update_headset_mode(codec);
break;
}
}
static void alc_fixup_headset_mode_no_hp_mic(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
if (action == HDA_FIXUP_ACT_PRE_PROBE) {
struct alc_spec *spec = codec->spec;
spec->parse_flags |= HDA_PINCFG_HEADSET_MIC;
}
else
alc_fixup_headset_mode(codec, fix, action);
}
static void alc_fixup_headset_mode_alc668(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
if (action == HDA_FIXUP_ACT_PRE_PROBE) {
int val;
alc_write_coef_idx(codec, 0xc4, 0x8000);
val = alc_read_coef_idx(codec, 0xc2);
alc_write_coef_idx(codec, 0xc2, val & 0xfe);
snd_hda_set_pin_ctl_cache(codec, 0x18, 0);
}
alc_fixup_headset_mode(codec, fix, action);
}
static void alc271_hp_gate_mic_jack(struct hda_codec *codec,
const struct hda_fixup *fix,
int action)
{
struct alc_spec *spec = codec->spec;
if (action == HDA_FIXUP_ACT_PROBE) {
if (snd_BUG_ON(!spec->gen.am_entry[1].pin ||
!spec->gen.autocfg.hp_pins[0]))
return;
snd_hda_jack_set_gating_jack(codec, spec->gen.am_entry[1].pin,
spec->gen.autocfg.hp_pins[0]);
}
}
static void alc269_fixup_limit_int_mic_boost(struct hda_codec *codec,
const struct hda_fixup *fix,
int action)
{
struct alc_spec *spec = codec->spec;
struct auto_pin_cfg *cfg = &spec->gen.autocfg;
int i;
if (action != HDA_FIXUP_ACT_PROBE)
return;
for (i = 0; i < cfg->num_inputs; i++) {
hda_nid_t nid = cfg->inputs[i].pin;
unsigned int defcfg;
if (cfg->inputs[i].type != AUTO_PIN_MIC)
continue;
defcfg = snd_hda_codec_get_pincfg(codec, nid);
if (snd_hda_get_input_pin_attr(defcfg) != INPUT_PIN_ATTR_INT)
continue;
snd_hda_override_amp_caps(codec, nid, HDA_INPUT,
(0x00 << AC_AMPCAP_OFFSET_SHIFT) |
(0x01 << AC_AMPCAP_NUM_STEPS_SHIFT) |
(0x2f << AC_AMPCAP_STEP_SIZE_SHIFT) |
(0 << AC_AMPCAP_MUTE_SHIFT));
}
}
static void alc269_fill_coef(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
int val;
if (spec->codec_variant != ALC269_TYPE_ALC269VB)
return;
if ((alc_get_coef0(codec) & 0x00ff) < 0x015) {
alc_write_coef_idx(codec, 0xf, 0x960b);
alc_write_coef_idx(codec, 0xe, 0x8817);
}
if ((alc_get_coef0(codec) & 0x00ff) == 0x016) {
alc_write_coef_idx(codec, 0xf, 0x960b);
alc_write_coef_idx(codec, 0xe, 0x8814);
}
if ((alc_get_coef0(codec) & 0x00ff) == 0x017) {
val = alc_read_coef_idx(codec, 0x04);
alc_write_coef_idx(codec, 0x04, val | (1<<11));
}
if ((alc_get_coef0(codec) & 0x00ff) == 0x018) {
val = alc_read_coef_idx(codec, 0xd);
if ((val & 0x0c00) >> 10 != 0x1) {
alc_write_coef_idx(codec, 0xd, val | (1<<10));
}
val = alc_read_coef_idx(codec, 0x17);
if ((val & 0x01c0) >> 6 != 0x4) {
alc_write_coef_idx(codec, 0x17, val | (1<<7));
}
}
val = alc_read_coef_idx(codec, 0xd);
alc_write_coef_idx(codec, 0xd, val | (1<<14));
val = alc_read_coef_idx(codec, 0x4);
alc_write_coef_idx(codec, 0x4, val | (1<<11));
}
static int patch_alc269(struct hda_codec *codec)
{
struct alc_spec *spec;
int err;
err = alc_alloc_spec(codec, 0x0b);
if (err < 0)
return err;
spec = codec->spec;
spec->gen.shared_mic_vref_pin = 0x18;
snd_hda_pick_fixup(codec, alc269_fixup_models,
alc269_fixup_tbl, alc269_fixups);
snd_hda_apply_fixup(codec, HDA_FIXUP_ACT_PRE_PROBE);
alc_auto_parse_customize_define(codec);
if (has_cdefine_beep(codec))
spec->gen.beep_nid = 0x01;
switch (codec->vendor_id) {
case 0x10ec0269:
spec->codec_variant = ALC269_TYPE_ALC269VA;
switch (alc_get_coef0(codec) & 0x00f0) {
case 0x0010:
if (codec->bus->pci->subsystem_vendor == 0x1025 &&
spec->cdefine.platform_type == 1)
err = alc_codec_rename(codec, "ALC271X");
spec->codec_variant = ALC269_TYPE_ALC269VB;
break;
case 0x0020:
if (codec->bus->pci->subsystem_vendor == 0x17aa &&
codec->bus->pci->subsystem_device == 0x21f3)
err = alc_codec_rename(codec, "ALC3202");
spec->codec_variant = ALC269_TYPE_ALC269VC;
break;
case 0x0030:
spec->codec_variant = ALC269_TYPE_ALC269VD;
break;
default:
alc_fix_pll_init(codec, 0x20, 0x04, 15);
}
if (err < 0)
goto error;
spec->init_hook = alc269_fill_coef;
alc269_fill_coef(codec);
break;
case 0x10ec0280:
case 0x10ec0290:
spec->codec_variant = ALC269_TYPE_ALC280;
break;
case 0x10ec0233:
case 0x10ec0282:
case 0x10ec0283:
spec->codec_variant = ALC269_TYPE_ALC282;
break;
case 0x10ec0284:
case 0x10ec0292:
spec->codec_variant = ALC269_TYPE_ALC284;
break;
case 0x10ec0286:
spec->codec_variant = ALC269_TYPE_ALC286;
break;
}
err = alc269_parse_auto_config(codec);
if (err < 0)
goto error;
if (!spec->gen.no_analog && spec->gen.beep_nid)
set_beep_amp(spec, 0x0b, 0x04, HDA_INPUT);
codec->patch_ops = alc_patch_ops;
#ifdef CONFIG_PM
codec->patch_ops.resume = alc269_resume;
#endif
spec->shutup = alc269_shutup;
snd_hda_apply_fixup(codec, HDA_FIXUP_ACT_PROBE);
return 0;
error:
alc_free(codec);
return err;
}
static int alc861_parse_auto_config(struct hda_codec *codec)
{
static const hda_nid_t alc861_ignore[] = { 0x1d, 0 };
static const hda_nid_t alc861_ssids[] = { 0x0e, 0x0f, 0x0b, 0 };
return alc_parse_auto_config(codec, alc861_ignore, alc861_ssids);
}
static void alc861_fixup_asus_amp_vref_0f(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
struct alc_spec *spec = codec->spec;
unsigned int val;
if (action != HDA_FIXUP_ACT_INIT)
return;
val = snd_hda_codec_get_pin_target(codec, 0x0f);
if (!(val & (AC_PINCTL_IN_EN | AC_PINCTL_OUT_EN)))
val |= AC_PINCTL_IN_EN;
val |= AC_PINCTL_VREF_50;
snd_hda_set_pin_ctl(codec, 0x0f, val);
spec->gen.keep_vref_in_automute = 1;
}
static void alc_fixup_no_jack_detect(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
if (action == HDA_FIXUP_ACT_PRE_PROBE)
codec->no_jack_detect = 1;
}
static int patch_alc861(struct hda_codec *codec)
{
struct alc_spec *spec;
int err;
err = alc_alloc_spec(codec, 0x15);
if (err < 0)
return err;
spec = codec->spec;
spec->gen.beep_nid = 0x23;
snd_hda_pick_fixup(codec, NULL, alc861_fixup_tbl, alc861_fixups);
snd_hda_apply_fixup(codec, HDA_FIXUP_ACT_PRE_PROBE);
err = alc861_parse_auto_config(codec);
if (err < 0)
goto error;
if (!spec->gen.no_analog)
set_beep_amp(spec, 0x23, 0, HDA_OUTPUT);
codec->patch_ops = alc_patch_ops;
#ifdef CONFIG_PM
spec->power_hook = alc_power_eapd;
#endif
snd_hda_apply_fixup(codec, HDA_FIXUP_ACT_PROBE);
return 0;
error:
alc_free(codec);
return err;
}
static int alc861vd_parse_auto_config(struct hda_codec *codec)
{
static const hda_nid_t alc861vd_ignore[] = { 0x1d, 0 };
static const hda_nid_t alc861vd_ssids[] = { 0x15, 0x1b, 0x14, 0 };
return alc_parse_auto_config(codec, alc861vd_ignore, alc861vd_ssids);
}
static void alc861vd_fixup_dallas(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
if (action == HDA_FIXUP_ACT_PRE_PROBE) {
snd_hda_override_pin_caps(codec, 0x18, 0x00000734);
snd_hda_override_pin_caps(codec, 0x19, 0x0000073c);
}
}
static int patch_alc861vd(struct hda_codec *codec)
{
struct alc_spec *spec;
int err;
err = alc_alloc_spec(codec, 0x0b);
if (err < 0)
return err;
spec = codec->spec;
spec->gen.beep_nid = 0x23;
snd_hda_pick_fixup(codec, NULL, alc861vd_fixup_tbl, alc861vd_fixups);
snd_hda_apply_fixup(codec, HDA_FIXUP_ACT_PRE_PROBE);
err = alc861vd_parse_auto_config(codec);
if (err < 0)
goto error;
if (!spec->gen.no_analog)
set_beep_amp(spec, 0x0b, 0x05, HDA_INPUT);
codec->patch_ops = alc_patch_ops;
spec->shutup = alc_eapd_shutup;
snd_hda_apply_fixup(codec, HDA_FIXUP_ACT_PROBE);
return 0;
error:
alc_free(codec);
return err;
}
static int alc662_parse_auto_config(struct hda_codec *codec)
{
static const hda_nid_t alc662_ignore[] = { 0x1d, 0 };
static const hda_nid_t alc663_ssids[] = { 0x15, 0x1b, 0x14, 0x21 };
static const hda_nid_t alc662_ssids[] = { 0x15, 0x1b, 0x14, 0 };
const hda_nid_t *ssids;
if (codec->vendor_id == 0x10ec0272 || codec->vendor_id == 0x10ec0663 ||
codec->vendor_id == 0x10ec0665 || codec->vendor_id == 0x10ec0670 ||
codec->vendor_id == 0x10ec0671)
ssids = alc663_ssids;
else
ssids = alc662_ssids;
return alc_parse_auto_config(codec, alc662_ignore, ssids);
}
static void alc272_fixup_mario(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
if (action != HDA_FIXUP_ACT_PRE_PROBE)
return;
if (snd_hda_override_amp_caps(codec, 0x2, HDA_OUTPUT,
(0x3b << AC_AMPCAP_OFFSET_SHIFT) |
(0x3b << AC_AMPCAP_NUM_STEPS_SHIFT) |
(0x03 << AC_AMPCAP_STEP_SIZE_SHIFT) |
(0 << AC_AMPCAP_MUTE_SHIFT)))
printk(KERN_WARNING
"hda_codec: failed to override amp caps for NID 0x2\n");
}
static void alc662_fill_coef(struct hda_codec *codec)
{
int val, coef;
coef = alc_get_coef0(codec);
switch (codec->vendor_id) {
case 0x10ec0662:
if ((coef & 0x00f0) == 0x0030) {
val = alc_read_coef_idx(codec, 0x4);
alc_write_coef_idx(codec, 0x4, val & ~(1<<10));
}
break;
case 0x10ec0272:
case 0x10ec0273:
case 0x10ec0663:
case 0x10ec0665:
case 0x10ec0670:
case 0x10ec0671:
case 0x10ec0672:
val = alc_read_coef_idx(codec, 0xd);
alc_write_coef_idx(codec, 0xd, val | (1<<14));
break;
}
}
static int patch_alc662(struct hda_codec *codec)
{
struct alc_spec *spec;
int err;
err = alc_alloc_spec(codec, 0x0b);
if (err < 0)
return err;
spec = codec->spec;
spec->parse_flags = HDA_PINCFG_NO_HP_FIXUP;
alc_fix_pll_init(codec, 0x20, 0x04, 15);
spec->init_hook = alc662_fill_coef;
alc662_fill_coef(codec);
snd_hda_pick_fixup(codec, alc662_fixup_models,
alc662_fixup_tbl, alc662_fixups);
snd_hda_apply_fixup(codec, HDA_FIXUP_ACT_PRE_PROBE);
alc_auto_parse_customize_define(codec);
if (has_cdefine_beep(codec))
spec->gen.beep_nid = 0x01;
if ((alc_get_coef0(codec) & (1 << 14)) &&
codec->bus->pci->subsystem_vendor == 0x1025 &&
spec->cdefine.platform_type == 1) {
err = alc_codec_rename(codec, "ALC272X");
if (err < 0)
goto error;
}
err = alc662_parse_auto_config(codec);
if (err < 0)
goto error;
if (!spec->gen.no_analog && spec->gen.beep_nid) {
switch (codec->vendor_id) {
case 0x10ec0662:
set_beep_amp(spec, 0x0b, 0x05, HDA_INPUT);
break;
case 0x10ec0272:
case 0x10ec0663:
case 0x10ec0665:
set_beep_amp(spec, 0x0b, 0x04, HDA_INPUT);
break;
case 0x10ec0273:
set_beep_amp(spec, 0x0b, 0x03, HDA_INPUT);
break;
}
}
codec->patch_ops = alc_patch_ops;
spec->shutup = alc_eapd_shutup;
snd_hda_apply_fixup(codec, HDA_FIXUP_ACT_PROBE);
return 0;
error:
alc_free(codec);
return err;
}
static int alc680_parse_auto_config(struct hda_codec *codec)
{
return alc_parse_auto_config(codec, NULL, NULL);
}
static int patch_alc680(struct hda_codec *codec)
{
int err;
err = alc_alloc_spec(codec, 0);
if (err < 0)
return err;
err = alc680_parse_auto_config(codec);
if (err < 0) {
alc_free(codec);
return err;
}
codec->patch_ops = alc_patch_ops;
return 0;
}
static int __init patch_realtek_init(void)
{
return snd_hda_add_codec_preset(&realtek_list);
}
static void __exit patch_realtek_exit(void)
{
snd_hda_delete_codec_preset(&realtek_list);
}
