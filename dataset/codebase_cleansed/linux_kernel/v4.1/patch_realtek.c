static int alc_read_coefex_idx(struct hda_codec *codec, hda_nid_t nid,
unsigned int coef_idx)
{
unsigned int val;
snd_hda_codec_write(codec, nid, 0, AC_VERB_SET_COEF_INDEX, coef_idx);
val = snd_hda_codec_read(codec, nid, 0, AC_VERB_GET_PROC_COEF, 0);
return val;
}
static void alc_write_coefex_idx(struct hda_codec *codec, hda_nid_t nid,
unsigned int coef_idx, unsigned int coef_val)
{
snd_hda_codec_write(codec, nid, 0, AC_VERB_SET_COEF_INDEX, coef_idx);
snd_hda_codec_write(codec, nid, 0, AC_VERB_SET_PROC_COEF, coef_val);
}
static void alc_update_coefex_idx(struct hda_codec *codec, hda_nid_t nid,
unsigned int coef_idx, unsigned int mask,
unsigned int bits_set)
{
unsigned int val = alc_read_coefex_idx(codec, nid, coef_idx);
if (val != -1)
alc_write_coefex_idx(codec, nid, coef_idx,
(val & ~mask) | bits_set);
}
static unsigned int alc_get_coef0(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
if (!spec->coef0)
spec->coef0 = alc_read_coef_idx(codec, 0);
return spec->coef0;
}
static void alc_process_coef_fw(struct hda_codec *codec,
const struct coef_fw *fw)
{
for (; fw->nid; fw++) {
if (fw->mask == (unsigned short)-1)
alc_write_coefex_idx(codec, fw->nid, fw->idx, fw->val);
else
alc_update_coefex_idx(codec, fw->nid, fw->idx,
fw->mask, fw->val);
}
}
static void add_mixer(struct alc_spec *spec, const struct snd_kcontrol_new *mix)
{
if (snd_BUG_ON(spec->num_mixers >= ARRAY_SIZE(spec->mixers)))
return;
spec->mixers[spec->num_mixers++] = mix;
}
static void alc_fix_pll(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
if (spec->pll_nid)
alc_update_coefex_idx(codec, spec->pll_nid, spec->pll_coef_idx,
1 << spec->pll_coef_bit, 0);
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
static void alc_update_knob_master(struct hda_codec *codec,
struct hda_jack_callback *jack)
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
val = snd_hda_codec_read(codec, jack->tbl->nid, 0,
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
static void alc_fill_eapd_coef(struct hda_codec *codec)
{
int coef;
coef = alc_get_coef0(codec);
switch (codec->core.vendor_id) {
case 0x10ec0262:
alc_update_coef_idx(codec, 0x7, 0, 1<<5);
break;
case 0x10ec0267:
case 0x10ec0268:
alc_update_coef_idx(codec, 0x7, 0, 1<<13);
break;
case 0x10ec0269:
if ((coef & 0x00f0) == 0x0010)
alc_update_coef_idx(codec, 0xd, 0, 1<<14);
if ((coef & 0x00f0) == 0x0020)
alc_update_coef_idx(codec, 0x4, 1<<15, 0);
if ((coef & 0x00f0) == 0x0030)
alc_update_coef_idx(codec, 0x10, 1<<9, 0);
break;
case 0x10ec0280:
case 0x10ec0284:
case 0x10ec0290:
case 0x10ec0292:
alc_update_coef_idx(codec, 0x4, 1<<15, 0);
break;
case 0x10ec0233:
case 0x10ec0255:
case 0x10ec0256:
case 0x10ec0282:
case 0x10ec0283:
case 0x10ec0286:
case 0x10ec0288:
case 0x10ec0298:
alc_update_coef_idx(codec, 0x10, 1<<9, 0);
break;
case 0x10ec0285:
case 0x10ec0293:
alc_update_coef_idx(codec, 0xa, 1<<13, 0);
break;
case 0x10ec0662:
if ((coef & 0x00f0) == 0x0030)
alc_update_coef_idx(codec, 0x4, 1<<10, 0);
break;
case 0x10ec0272:
case 0x10ec0273:
case 0x10ec0663:
case 0x10ec0665:
case 0x10ec0670:
case 0x10ec0671:
case 0x10ec0672:
alc_update_coef_idx(codec, 0xd, 0, 1<<14);
break;
case 0x10ec0668:
alc_update_coef_idx(codec, 0x7, 3<<13, 0);
break;
case 0x10ec0867:
alc_update_coef_idx(codec, 0x4, 1<<10, 0);
break;
case 0x10ec0888:
if ((coef & 0x00f0) == 0x0020 || (coef & 0x00f0) == 0x0030)
alc_update_coef_idx(codec, 0x7, 1<<5, 0);
break;
case 0x10ec0892:
alc_update_coef_idx(codec, 0x7, 1<<5, 0);
break;
case 0x10ec0899:
case 0x10ec0900:
alc_update_coef_idx(codec, 0x7, 1<<1, 0);
break;
}
}
static void alc888_coef_init(struct hda_codec *codec)
{
switch (alc_get_coef0(codec) & 0x00f0) {
case 0x00:
case 0x10:
alc_update_coef_idx(codec, 7, 0, 0x2030);
break;
}
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
0x0f, 0x10, 0x14, 0x15, 0x17, 0
};
hda_nid_t *p;
for (p = pins; *p; p++)
set_eapd(codec, *p, on);
}
static void alc_eapd_shutup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
alc_auto_setup_eapd(codec, false);
if (!spec->no_depop_delay)
msleep(200);
snd_hda_shutup_pins(codec);
}
static void alc_auto_init_amp(struct hda_codec *codec, int type)
{
alc_fill_eapd_coef(codec);
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
switch (codec->core.vendor_id) {
case 0x10ec0260:
alc_update_coefex_idx(codec, 0x1a, 7, 0, 0x2010);
break;
case 0x10ec0880:
case 0x10ec0882:
case 0x10ec0883:
case 0x10ec0885:
alc_update_coef_idx(codec, 7, 0, 0x2030);
break;
case 0x10ec0888:
alc888_coef_init(codec);
break;
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
static void alc_fixup_no_depop_delay(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
struct alc_spec *spec = codec->spec;
if (action == HDA_FIXUP_ACT_PROBE) {
spec->no_depop_delay = 1;
codec->depop_delay = 0;
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
if (!codec->bus->pci)
return -1;
ass = codec->core.subsystem_id & 0xffff;
if (ass != codec->bus->pci->subsystem_device && (ass & 1))
goto do_sku;
nid = 0x1d;
if (codec->core.vendor_id == 0x10ec0260)
nid = 0x17;
ass = snd_hda_codec_get_pincfg(codec, nid);
if (!(ass & 1)) {
codec_info(codec, "%s: SKU not ready 0x%08x\n",
codec->core.chip_name, ass);
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
codec_dbg(codec, "SKU: Nid=0x%x sku_cfg=0x%08x\n",
nid, spec->cdefine.sku_cfg);
codec_dbg(codec, "SKU: port_connectivity=0x%x\n",
spec->cdefine.port_connectivity);
codec_dbg(codec, "SKU: enable_pcbeep=0x%x\n", spec->cdefine.enable_pcbeep);
codec_dbg(codec, "SKU: check_sum=0x%08x\n", spec->cdefine.check_sum);
codec_dbg(codec, "SKU: customization=0x%08x\n", spec->cdefine.customization);
codec_dbg(codec, "SKU: external_amp=0x%x\n", spec->cdefine.external_amp);
codec_dbg(codec, "SKU: platform_type=0x%x\n", spec->cdefine.platform_type);
codec_dbg(codec, "SKU: swap=0x%x\n", spec->cdefine.swap);
codec_dbg(codec, "SKU: override=0x%x\n", spec->cdefine.override);
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
static int alc_subsystem_id(struct hda_codec *codec, const hda_nid_t *ports)
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
ass = codec->core.subsystem_id & 0xffff;
if (codec->bus->pci &&
ass != codec->bus->pci->subsystem_device && (ass & 1))
goto do_sku;
nid = 0x1d;
if (codec->core.vendor_id == 0x10ec0260)
nid = 0x17;
ass = snd_hda_codec_get_pincfg(codec, nid);
codec_dbg(codec,
"realtek: No valid SSID, checking pincfg 0x%08x for NID 0x%x\n",
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
codec_dbg(codec, "realtek: Enabling init ASM_ID=0x%04x CODEC_ID=%08x\n",
ass & 0xffff, codec->core.vendor_id);
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
nid = ports[tmp];
if (found_in_nid_list(nid, spec->gen.autocfg.line_out_pins,
spec->gen.autocfg.line_outs))
return 1;
spec->gen.autocfg.hp_pins[0] = nid;
}
return 1;
}
static void alc_ssid_check(struct hda_codec *codec, const hda_nid_t *ports)
{
if (!alc_subsystem_id(codec, ports)) {
struct alc_spec *spec = codec->spec;
codec_dbg(codec,
"realtek: Enable default setup for auto mode as fallback\n");
spec->init_amp = ALC_INIT_DEFAULT;
}
}
static void alc_fixup_inv_dmic(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
struct alc_spec *spec = codec->spec;
spec->gen.inv_dmic_split = 1;
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
else
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
struct alc_spec *spec = codec->spec;
if (!spec->no_depop_delay)
msleep(150);
codec->patch_ops.init(codec);
regcache_sync(codec->core.regmap);
hda_call_check_power_status(codec, 0x01);
return 0;
}
static int alc_codec_rename(struct hda_codec *codec, const char *name)
{
kfree(codec->core.chip_name);
codec->core.chip_name = kstrdup(name, GFP_KERNEL);
if (!codec->core.chip_name) {
alc_free(codec);
return -ENOMEM;
}
return 0;
}
static int alc_codec_rename_from_preset(struct hda_codec *codec)
{
const struct alc_codec_rename_table *p;
const struct alc_codec_rename_pci_table *q;
for (p = rename_tbl; p->vendor_id; p++) {
if (p->vendor_id != codec->core.vendor_id)
continue;
if ((alc_get_coef0(codec) & p->coef_mask) == p->coef_bits)
return alc_codec_rename(codec, p->name);
}
if (!codec->bus->pci)
return 0;
for (q = rename_pci_tbl; q->codec_vendor_id; q++) {
if (q->codec_vendor_id != codec->core.vendor_id)
continue;
if (q->pci_subvendor != codec->bus->pci->subsystem_vendor)
continue;
if (!q->pci_subdevice ||
q->pci_subdevice == codec->bus->pci->subsystem_device)
return alc_codec_rename(codec, q->name);
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
snd_hda_jack_detect_enable_callback(codec, 0x21,
alc_update_knob_master);
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
snd_hda_jack_detect_enable_callback(codec, 0x0f,
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
alc_update_coef_idx(codec, 7, 0, 0x2030);
}
static void alc882_gpio_mute(struct hda_codec *codec, int pin, int muted)
{
unsigned int gpiostate, gpiomask, gpiodir;
gpiostate = snd_hda_codec_read(codec, codec->core.afg, 0,
AC_VERB_GET_GPIO_DATA, 0);
if (!muted)
gpiostate |= (1 << pin);
else
gpiostate &= ~(1 << pin);
gpiomask = snd_hda_codec_read(codec, codec->core.afg, 0,
AC_VERB_GET_GPIO_MASK, 0);
gpiomask |= (1 << pin);
gpiodir = snd_hda_codec_read(codec, codec->core.afg, 0,
AC_VERB_GET_GPIO_DIRECTION, 0);
gpiodir |= (1 << pin);
snd_hda_codec_write(codec, codec->core.afg, 0,
AC_VERB_SET_GPIO_MASK, gpiomask);
snd_hda_codec_write(codec, codec->core.afg, 0,
AC_VERB_SET_GPIO_DIRECTION, gpiodir);
msleep(1);
snd_hda_codec_write(codec, codec->core.afg, 0,
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
static void alc889_fixup_mac_pins(struct hda_codec *codec,
const hda_nid_t *nids, int num_nids)
{
struct alc_spec *spec = codec->spec;
int i;
for (i = 0; i < num_nids; i++) {
unsigned int val;
val = snd_hda_codec_get_pin_target(codec, nids[i]);
val |= AC_PINCTL_VREF_50;
snd_hda_set_pin_ctl(codec, nids[i], val);
}
spec->gen.keep_vref_in_automute = 1;
}
static void alc889_fixup_imac91_vref(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
static hda_nid_t nids[2] = { 0x18, 0x1a };
if (action == HDA_FIXUP_ACT_INIT)
alc889_fixup_mac_pins(codec, nids, ARRAY_SIZE(nids));
}
static void alc889_fixup_mba11_vref(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
static hda_nid_t nids[1] = { 0x18 };
if (action == HDA_FIXUP_ACT_INIT)
alc889_fixup_mac_pins(codec, nids, ARRAY_SIZE(nids));
}
static void alc889_fixup_mba21_vref(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
static hda_nid_t nids[2] = { 0x18, 0x19 };
if (action == HDA_FIXUP_ACT_INIT)
alc889_fixup_mac_pins(codec, nids, ARRAY_SIZE(nids));
}
static void alc882_fixup_no_primary_hp(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
struct alc_spec *spec = codec->spec;
if (action == HDA_FIXUP_ACT_PRE_PROBE) {
spec->gen.no_primary_hp = 1;
spec->gen.no_multi_io = 1;
}
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
switch (codec->core.vendor_id) {
case 0x10ec0882:
case 0x10ec0885:
case 0x10ec0900:
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
alc_update_coefex_idx(codec, 0x1a, 7, 0, 0x80);
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
case ALC269_TYPE_ALC285:
ssids = alc269va_ssids;
break;
case ALC269_TYPE_ALC269VB:
case ALC269_TYPE_ALC269VD:
case ALC269_TYPE_ALC282:
case ALC269_TYPE_ALC283:
case ALC269_TYPE_ALC286:
case ALC269_TYPE_ALC298:
case ALC269_TYPE_ALC255:
case ALC269_TYPE_ALC256:
ssids = alc269_ssids;
break;
default:
ssids = alc269_ssids;
break;
}
return alc_parse_auto_config(codec, alc269_ignore, ssids);
}
static void alc286_shutup(struct hda_codec *codec)
{
int i;
int mic_pin = find_ext_mic_pin(codec);
if (codec->bus->shutdown)
return;
for (i = 0; i < codec->init_pins.used; i++) {
struct hda_pincfg *pin = snd_array_elem(&codec->init_pins, i);
if (pin->nid != mic_pin)
snd_hda_codec_read(codec, pin->nid, 0,
AC_VERB_SET_PIN_WIDGET_CONTROL, 0);
}
codec->pins_shutup = 1;
}
static void alc269vb_toggle_power_output(struct hda_codec *codec, int power_up)
{
alc_update_coef_idx(codec, 0x04, 1 << 11, power_up ? (1 << 11) : 0);
}
static void alc269_shutup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
if (spec->codec_variant == ALC269_TYPE_ALC269VB)
alc269vb_toggle_power_output(codec, 0);
if (spec->codec_variant == ALC269_TYPE_ALC269VB &&
(alc_get_coef0(codec) & 0x00ff) == 0x018) {
msleep(150);
}
snd_hda_shutup_pins(codec);
}
static void alc282_restore_default_value(struct hda_codec *codec)
{
alc_process_coef_fw(codec, alc282_coefs);
}
static void alc282_init(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
hda_nid_t hp_pin = spec->gen.autocfg.hp_pins[0];
bool hp_pin_sense;
int coef78;
alc282_restore_default_value(codec);
if (!hp_pin)
return;
hp_pin_sense = snd_hda_jack_detect(codec, hp_pin);
coef78 = alc_read_coef_idx(codec, 0x78);
alc_write_coef_idx(codec, 0x78, 0x9004);
if (hp_pin_sense)
msleep(2);
snd_hda_codec_write(codec, hp_pin, 0,
AC_VERB_SET_AMP_GAIN_MUTE, AMP_OUT_MUTE);
if (hp_pin_sense)
msleep(85);
snd_hda_codec_write(codec, hp_pin, 0,
AC_VERB_SET_PIN_WIDGET_CONTROL, PIN_OUT);
if (hp_pin_sense)
msleep(100);
alc_write_coef_idx(codec, 0x78, coef78);
}
static void alc282_shutup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
hda_nid_t hp_pin = spec->gen.autocfg.hp_pins[0];
bool hp_pin_sense;
int coef78;
if (!hp_pin) {
alc269_shutup(codec);
return;
}
hp_pin_sense = snd_hda_jack_detect(codec, hp_pin);
coef78 = alc_read_coef_idx(codec, 0x78);
alc_write_coef_idx(codec, 0x78, 0x9004);
if (hp_pin_sense)
msleep(2);
snd_hda_codec_write(codec, hp_pin, 0,
AC_VERB_SET_AMP_GAIN_MUTE, AMP_OUT_MUTE);
if (hp_pin_sense)
msleep(85);
snd_hda_codec_write(codec, hp_pin, 0,
AC_VERB_SET_PIN_WIDGET_CONTROL, 0x0);
if (hp_pin_sense)
msleep(100);
alc_auto_setup_eapd(codec, false);
snd_hda_shutup_pins(codec);
alc_write_coef_idx(codec, 0x78, coef78);
}
static void alc283_restore_default_value(struct hda_codec *codec)
{
alc_process_coef_fw(codec, alc283_coefs);
}
static void alc283_init(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
hda_nid_t hp_pin = spec->gen.autocfg.hp_pins[0];
bool hp_pin_sense;
if (!spec->gen.autocfg.hp_outs) {
if (spec->gen.autocfg.line_out_type == AC_JACK_HP_OUT)
hp_pin = spec->gen.autocfg.line_out_pins[0];
}
alc283_restore_default_value(codec);
if (!hp_pin)
return;
msleep(30);
hp_pin_sense = snd_hda_jack_detect(codec, hp_pin);
alc_write_coef_idx(codec, 0x43, 0x9004);
snd_hda_codec_write(codec, hp_pin, 0,
AC_VERB_SET_AMP_GAIN_MUTE, AMP_OUT_MUTE);
if (hp_pin_sense)
msleep(85);
snd_hda_codec_write(codec, hp_pin, 0,
AC_VERB_SET_PIN_WIDGET_CONTROL, PIN_OUT);
if (hp_pin_sense)
msleep(85);
alc_update_coef_idx(codec, 0x46, 3 << 12, 0);
alc_write_coef_idx(codec, 0x43, 0x9614);
}
static void alc283_shutup(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
hda_nid_t hp_pin = spec->gen.autocfg.hp_pins[0];
bool hp_pin_sense;
if (!spec->gen.autocfg.hp_outs) {
if (spec->gen.autocfg.line_out_type == AC_JACK_HP_OUT)
hp_pin = spec->gen.autocfg.line_out_pins[0];
}
if (!hp_pin) {
alc269_shutup(codec);
return;
}
hp_pin_sense = snd_hda_jack_detect(codec, hp_pin);
alc_write_coef_idx(codec, 0x43, 0x9004);
alc_write_coef_idx(codec, 0x06, 0x2100);
snd_hda_codec_write(codec, hp_pin, 0,
AC_VERB_SET_AMP_GAIN_MUTE, AMP_OUT_MUTE);
if (hp_pin_sense)
msleep(100);
snd_hda_codec_write(codec, hp_pin, 0,
AC_VERB_SET_PIN_WIDGET_CONTROL, 0x0);
alc_update_coef_idx(codec, 0x46, 0, 3 << 12);
if (hp_pin_sense)
msleep(100);
alc_auto_setup_eapd(codec, false);
snd_hda_shutup_pins(codec);
alc_write_coef_idx(codec, 0x43, 0x9614);
}
static void alc5505_coef_set(struct hda_codec *codec, unsigned int index_reg,
unsigned int val)
{
snd_hda_codec_write(codec, 0x51, 0, AC_VERB_SET_COEF_INDEX, index_reg >> 1);
snd_hda_codec_write(codec, 0x51, 0, AC_VERB_SET_PROC_COEF, val & 0xffff);
snd_hda_codec_write(codec, 0x51, 0, AC_VERB_SET_PROC_COEF, val >> 16);
}
static int alc5505_coef_get(struct hda_codec *codec, unsigned int index_reg)
{
unsigned int val;
snd_hda_codec_write(codec, 0x51, 0, AC_VERB_SET_COEF_INDEX, index_reg >> 1);
val = snd_hda_codec_read(codec, 0x51, 0, AC_VERB_GET_PROC_COEF, 0)
& 0xffff;
val |= snd_hda_codec_read(codec, 0x51, 0, AC_VERB_GET_PROC_COEF, 0)
<< 16;
return val;
}
static void alc5505_dsp_halt(struct hda_codec *codec)
{
unsigned int val;
alc5505_coef_set(codec, 0x3000, 0x000c);
alc5505_coef_set(codec, 0x880c, 0x0008);
alc5505_coef_set(codec, 0x61c0, 0x11110080);
alc5505_coef_set(codec, 0x6230, 0xfc0d4011);
alc5505_coef_set(codec, 0x61b4, 0x040a2b03);
alc5505_coef_set(codec, 0x61b0, 0x00005b17);
alc5505_coef_set(codec, 0x61b8, 0x04133303);
val = alc5505_coef_get(codec, 0x6220);
alc5505_coef_set(codec, 0x6220, (val | 0x3000));
}
static void alc5505_dsp_back_from_halt(struct hda_codec *codec)
{
alc5505_coef_set(codec, 0x61b8, 0x04133302);
alc5505_coef_set(codec, 0x61b0, 0x00005b16);
alc5505_coef_set(codec, 0x61b4, 0x040a2b02);
alc5505_coef_set(codec, 0x6230, 0xf80d4011);
alc5505_coef_set(codec, 0x6220, 0x2002010f);
alc5505_coef_set(codec, 0x880c, 0x00000004);
}
static void alc5505_dsp_init(struct hda_codec *codec)
{
unsigned int val;
alc5505_dsp_halt(codec);
alc5505_dsp_back_from_halt(codec);
alc5505_coef_set(codec, 0x61b0, 0x5b14);
alc5505_coef_set(codec, 0x61b0, 0x5b16);
alc5505_coef_set(codec, 0x61b4, 0x04132b00);
alc5505_coef_set(codec, 0x61b4, 0x04132b02);
alc5505_coef_set(codec, 0x61b8, 0x041f3300);
alc5505_coef_set(codec, 0x61b8, 0x041f3302);
snd_hda_codec_write(codec, 0x51, 0, AC_VERB_SET_CODEC_RESET, 0);
alc5505_coef_set(codec, 0x61b8, 0x041b3302);
alc5505_coef_set(codec, 0x61b8, 0x04173302);
alc5505_coef_set(codec, 0x61b8, 0x04163302);
alc5505_coef_set(codec, 0x8800, 0x348b328b);
alc5505_coef_set(codec, 0x8808, 0x00020022);
alc5505_coef_set(codec, 0x8818, 0x00000400);
val = alc5505_coef_get(codec, 0x6200) >> 16;
if (val <= 3)
alc5505_coef_set(codec, 0x6220, 0x2002010f);
else
alc5505_coef_set(codec, 0x6220, 0x6002018f);
alc5505_coef_set(codec, 0x61ac, 0x055525f0);
alc5505_coef_set(codec, 0x61c0, 0x12230080);
alc5505_coef_set(codec, 0x61b4, 0x040e2b02);
alc5505_coef_set(codec, 0x61bc, 0x010234f8);
alc5505_coef_set(codec, 0x880c, 0x00000004);
alc5505_coef_set(codec, 0x880c, 0x00000003);
alc5505_coef_set(codec, 0x880c, 0x00000010);
#ifdef HALT_REALTEK_ALC5505
alc5505_dsp_halt(codec);
#endif
}
static int alc269_suspend(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
if (spec->has_alc5505_dsp)
alc5505_dsp_suspend(codec);
return alc_suspend(codec);
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
regcache_sync(codec->core.regmap);
hda_call_check_power_status(codec, 0x01);
if (spec->gpio_led)
snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_GPIO_DATA,
spec->gpio_led);
if (spec->has_alc5505_dsp)
alc5505_dsp_resume(codec);
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
if (action == HDA_FIXUP_ACT_INIT)
alc_update_coef_idx(codec, 0x1e, 0, 0x80);
}
static void alc269_fixup_headset_mic(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
struct alc_spec *spec = codec->spec;
if (action == HDA_FIXUP_ACT_PRE_PROBE)
spec->parse_flags |= HDA_PINCFG_HEADSET_MIC;
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
if (strcmp(codec->core.chip_name, "ALC271X") &&
strcmp(codec->core.chip_name, "ALC269VB"))
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
if (action == HDA_FIXUP_ACT_INIT)
alc_update_coef_idx(codec, 0x07, 0, 0x80);
}
static void alc269_quanta_automute(struct hda_codec *codec)
{
snd_hda_gen_update_outputs(codec);
alc_write_coef_idx(codec, 0x0c, 0x680);
alc_write_coef_idx(codec, 0x0c, 0x480);
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
struct hda_jack_callback *jack)
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
pinval = snd_hda_codec_get_pin_target(codec, spec->mute_led_nid);
pinval &= ~AC_PINCTL_VREFEN;
pinval |= enabled ? AC_PINCTL_VREF_HIZ : AC_PINCTL_VREF_80;
if (spec->mute_led_nid)
snd_hda_set_pin_ctl_cache(codec, spec->mute_led_nid, pinval);
}
static unsigned int led_power_filter(struct hda_codec *codec,
hda_nid_t nid,
unsigned int power_state)
{
struct alc_spec *spec = codec->spec;
if (power_state != AC_PWRST_D3 || nid == 0 ||
(nid != spec->mute_led_nid && nid != spec->cap_mute_led_nid))
return power_state;
snd_hda_set_pin_ctl(codec, nid,
snd_hda_codec_get_pin_target(codec, nid));
return snd_hda_gen_path_power_filter(codec, nid, power_state);
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
codec->power_filter = led_power_filter;
codec_dbg(codec,
"Detected mute LED for %x:%d\n", spec->mute_led_nid,
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
codec->power_filter = led_power_filter;
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
codec->power_filter = led_power_filter;
}
}
static void alc_update_gpio_led(struct hda_codec *codec, unsigned int mask,
bool enabled)
{
struct alc_spec *spec = codec->spec;
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
static void alc_fixup_gpio_mute_hook(void *private_data, int enabled)
{
struct hda_codec *codec = private_data;
struct alc_spec *spec = codec->spec;
alc_update_gpio_led(codec, spec->gpio_mute_led_mask, enabled);
}
static void alc_fixup_gpio_mic_mute_hook(struct hda_codec *codec,
struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct alc_spec *spec = codec->spec;
if (ucontrol)
alc_update_gpio_led(codec, spec->gpio_mic_led_mask,
ucontrol->value.integer.value[0] ||
ucontrol->value.integer.value[1]);
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
spec->gen.vmaster_mute.hook = alc_fixup_gpio_mute_hook;
spec->gen.cap_sync_hook = alc_fixup_gpio_mic_mute_hook;
spec->gpio_led = 0;
spec->mute_led_polarity = 0;
spec->gpio_mute_led_mask = 0x08;
spec->gpio_mic_led_mask = 0x10;
snd_hda_add_verbs(codec, gpio_init);
}
}
static void alc286_fixup_hp_gpio_led(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
struct alc_spec *spec = codec->spec;
static const struct hda_verb gpio_init[] = {
{ 0x01, AC_VERB_SET_GPIO_MASK, 0x22 },
{ 0x01, AC_VERB_SET_GPIO_DIRECTION, 0x22 },
{}
};
if (action == HDA_FIXUP_ACT_PRE_PROBE) {
spec->gen.vmaster_mute.hook = alc_fixup_gpio_mute_hook;
spec->gen.cap_sync_hook = alc_fixup_gpio_mic_mute_hook;
spec->gpio_led = 0;
spec->mute_led_polarity = 0;
spec->gpio_mute_led_mask = 0x02;
spec->gpio_mic_led_mask = 0x20;
snd_hda_add_verbs(codec, gpio_init);
}
}
static void alc269_fixup_hp_cap_mic_mute_hook(struct hda_codec *codec,
struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct alc_spec *spec = codec->spec;
unsigned int pinval, enable, disable;
pinval = snd_hda_codec_get_pin_target(codec, spec->cap_mute_led_nid);
pinval &= ~AC_PINCTL_VREFEN;
enable = pinval | AC_PINCTL_VREF_80;
disable = pinval | AC_PINCTL_VREF_HIZ;
if (!ucontrol)
return;
if (ucontrol->value.integer.value[0] ||
ucontrol->value.integer.value[1])
pinval = disable;
else
pinval = enable;
if (spec->cap_mute_led_nid)
snd_hda_set_pin_ctl_cache(codec, spec->cap_mute_led_nid, pinval);
}
static void alc269_fixup_hp_gpio_mic1_led(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
struct alc_spec *spec = codec->spec;
static const struct hda_verb gpio_init[] = {
{ 0x01, AC_VERB_SET_GPIO_MASK, 0x08 },
{ 0x01, AC_VERB_SET_GPIO_DIRECTION, 0x08 },
{}
};
if (action == HDA_FIXUP_ACT_PRE_PROBE) {
spec->gen.vmaster_mute.hook = alc_fixup_gpio_mute_hook;
spec->gen.cap_sync_hook = alc269_fixup_hp_cap_mic_mute_hook;
spec->gpio_led = 0;
spec->mute_led_polarity = 0;
spec->gpio_mute_led_mask = 0x08;
spec->cap_mute_led_nid = 0x18;
snd_hda_add_verbs(codec, gpio_init);
codec->power_filter = led_power_filter;
}
}
static void alc280_fixup_hp_gpio4(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
struct alc_spec *spec = codec->spec;
static const struct hda_verb gpio_init[] = {
{ 0x01, AC_VERB_SET_GPIO_MASK, 0x18 },
{ 0x01, AC_VERB_SET_GPIO_DIRECTION, 0x18 },
{}
};
if (action == HDA_FIXUP_ACT_PRE_PROBE) {
spec->gen.vmaster_mute.hook = alc_fixup_gpio_mute_hook;
spec->gen.cap_sync_hook = alc269_fixup_hp_cap_mic_mute_hook;
spec->gpio_led = 0;
spec->mute_led_polarity = 0;
spec->gpio_mute_led_mask = 0x08;
spec->cap_mute_led_nid = 0x18;
snd_hda_add_verbs(codec, gpio_init);
codec->power_filter = led_power_filter;
}
}
static void gpio2_mic_hotkey_event(struct hda_codec *codec,
struct hda_jack_callback *event)
{
struct alc_spec *spec = codec->spec;
input_report_key(spec->kb_dev, KEY_MICMUTE, 1);
input_sync(spec->kb_dev);
input_report_key(spec->kb_dev, KEY_MICMUTE, 0);
input_sync(spec->kb_dev);
}
static void alc280_fixup_hp_gpio2_mic_hotkey(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
static const struct hda_verb gpio_init[] = {
{ 0x01, AC_VERB_SET_GPIO_MASK, 0x1e },
{ 0x01, AC_VERB_SET_GPIO_DIRECTION, 0x1a },
{ 0x01, AC_VERB_SET_GPIO_DATA, 0x02 },
{}
};
struct alc_spec *spec = codec->spec;
if (action == HDA_FIXUP_ACT_PRE_PROBE) {
spec->kb_dev = input_allocate_device();
if (!spec->kb_dev) {
codec_err(codec, "Out of memory (input_allocate_device)\n");
return;
}
spec->kb_dev->name = "Microphone Mute Button";
spec->kb_dev->evbit[0] = BIT_MASK(EV_KEY);
spec->kb_dev->keybit[BIT_WORD(KEY_MICMUTE)] = BIT_MASK(KEY_MICMUTE);
if (input_register_device(spec->kb_dev)) {
codec_err(codec, "input_register_device failed\n");
input_free_device(spec->kb_dev);
spec->kb_dev = NULL;
return;
}
snd_hda_add_verbs(codec, gpio_init);
snd_hda_codec_write_cache(codec, codec->core.afg, 0,
AC_VERB_SET_GPIO_UNSOLICITED_RSP_MASK, 0x04);
snd_hda_jack_detect_enable_callback(codec, codec->core.afg,
gpio2_mic_hotkey_event);
spec->gen.vmaster_mute.hook = alc_fixup_gpio_mute_hook;
spec->gen.cap_sync_hook = alc_fixup_gpio_mic_mute_hook;
spec->gpio_led = 0;
spec->mute_led_polarity = 0;
spec->gpio_mute_led_mask = 0x08;
spec->gpio_mic_led_mask = 0x10;
return;
}
if (!spec->kb_dev)
return;
switch (action) {
case HDA_FIXUP_ACT_PROBE:
spec->init_amp = ALC_INIT_DEFAULT;
break;
case HDA_FIXUP_ACT_FREE:
input_unregister_device(spec->kb_dev);
spec->kb_dev = NULL;
}
}
static void alc269_fixup_hp_line1_mic1_led(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
struct alc_spec *spec = codec->spec;
if (action == HDA_FIXUP_ACT_PRE_PROBE) {
spec->gen.vmaster_mute.hook = alc269_fixup_mic_mute_hook;
spec->gen.cap_sync_hook = alc269_fixup_hp_cap_mic_mute_hook;
spec->mute_led_polarity = 0;
spec->mute_led_nid = 0x1a;
spec->cap_mute_led_nid = 0x18;
spec->gen.vmaster_mute_enum = 1;
codec->power_filter = led_power_filter;
}
}
static void alc_headset_mode_unplugged(struct hda_codec *codec)
{
static struct coef_fw coef0255[] = {
WRITE_COEF(0x1b, 0x0c0b),
WRITE_COEF(0x45, 0xd089),
UPDATE_COEFEX(0x57, 0x05, 1<<14, 0),
WRITE_COEF(0x06, 0x6104),
WRITE_COEFEX(0x57, 0x03, 0x8aa6),
{}
};
static struct coef_fw coef0233[] = {
WRITE_COEF(0x1b, 0x0c0b),
WRITE_COEF(0x45, 0xc429),
UPDATE_COEF(0x35, 0x4000, 0),
WRITE_COEF(0x06, 0x2104),
WRITE_COEF(0x1a, 0x0001),
WRITE_COEF(0x26, 0x0004),
WRITE_COEF(0x32, 0x42a3),
{}
};
static struct coef_fw coef0288[] = {
UPDATE_COEF(0x4f, 0xfcc0, 0xc400),
UPDATE_COEF(0x50, 0x2000, 0x2000),
UPDATE_COEF(0x56, 0x0006, 0x0006),
UPDATE_COEF(0x66, 0x0008, 0),
UPDATE_COEF(0x67, 0x2000, 0),
{}
};
static struct coef_fw coef0292[] = {
WRITE_COEF(0x76, 0x000e),
WRITE_COEF(0x6c, 0x2400),
WRITE_COEF(0x18, 0x7308),
WRITE_COEF(0x6b, 0xc429),
{}
};
static struct coef_fw coef0293[] = {
UPDATE_COEF(0x10, 7<<8, 6<<8),
UPDATE_COEFEX(0x57, 0x05, 1<<15|1<<13, 0x0),
UPDATE_COEFEX(0x57, 0x03, 1<<10, 1<<10),
UPDATE_COEF(0x1a, 1<<3, 1<<3),
WRITE_COEF(0x45, 0xc429),
UPDATE_COEF(0x4a, 0x000f, 0x000e),
{}
};
static struct coef_fw coef0668[] = {
WRITE_COEF(0x15, 0x0d40),
WRITE_COEF(0xb7, 0x802b),
{}
};
switch (codec->core.vendor_id) {
case 0x10ec0255:
case 0x10ec0256:
alc_process_coef_fw(codec, coef0255);
break;
case 0x10ec0233:
case 0x10ec0283:
alc_process_coef_fw(codec, coef0233);
break;
case 0x10ec0286:
case 0x10ec0288:
alc_process_coef_fw(codec, coef0288);
break;
case 0x10ec0292:
alc_process_coef_fw(codec, coef0292);
break;
case 0x10ec0293:
alc_process_coef_fw(codec, coef0293);
break;
case 0x10ec0668:
alc_process_coef_fw(codec, coef0668);
break;
}
codec_dbg(codec, "Headset jack set to unplugged mode.\n");
}
static void alc_headset_mode_mic_in(struct hda_codec *codec, hda_nid_t hp_pin,
hda_nid_t mic_pin)
{
static struct coef_fw coef0255[] = {
WRITE_COEFEX(0x57, 0x03, 0x8aa6),
WRITE_COEF(0x06, 0x6100),
{}
};
static struct coef_fw coef0233[] = {
UPDATE_COEF(0x35, 0, 1<<14),
WRITE_COEF(0x06, 0x2100),
WRITE_COEF(0x1a, 0x0021),
WRITE_COEF(0x26, 0x008c),
{}
};
static struct coef_fw coef0288[] = {
UPDATE_COEF(0x50, 0x2000, 0),
UPDATE_COEF(0x56, 0x0006, 0),
UPDATE_COEF(0x4f, 0xfcc0, 0xc400),
UPDATE_COEF(0x66, 0x0008, 0x0008),
UPDATE_COEF(0x67, 0x2000, 0x2000),
{}
};
static struct coef_fw coef0292[] = {
WRITE_COEF(0x19, 0xa208),
WRITE_COEF(0x2e, 0xacf0),
{}
};
static struct coef_fw coef0293[] = {
UPDATE_COEFEX(0x57, 0x05, 0, 1<<15|1<<13),
UPDATE_COEFEX(0x57, 0x03, 1<<10, 0),
UPDATE_COEF(0x1a, 1<<3, 0),
{}
};
static struct coef_fw coef0688[] = {
WRITE_COEF(0xb7, 0x802b),
WRITE_COEF(0xb5, 0x1040),
UPDATE_COEF(0xc3, 0, 1<<12),
{}
};
switch (codec->core.vendor_id) {
case 0x10ec0255:
case 0x10ec0256:
alc_write_coef_idx(codec, 0x45, 0xc489);
snd_hda_set_pin_ctl_cache(codec, hp_pin, 0);
alc_process_coef_fw(codec, coef0255);
snd_hda_set_pin_ctl_cache(codec, mic_pin, PIN_VREF50);
break;
case 0x10ec0233:
case 0x10ec0283:
alc_write_coef_idx(codec, 0x45, 0xc429);
snd_hda_set_pin_ctl_cache(codec, hp_pin, 0);
alc_process_coef_fw(codec, coef0233);
snd_hda_set_pin_ctl_cache(codec, mic_pin, PIN_VREF50);
break;
case 0x10ec0286:
case 0x10ec0288:
alc_update_coef_idx(codec, 0x4f, 0x000c, 0);
snd_hda_set_pin_ctl_cache(codec, hp_pin, 0);
alc_process_coef_fw(codec, coef0288);
snd_hda_set_pin_ctl_cache(codec, mic_pin, PIN_VREF50);
break;
case 0x10ec0292:
snd_hda_set_pin_ctl_cache(codec, hp_pin, 0);
alc_process_coef_fw(codec, coef0292);
break;
case 0x10ec0293:
alc_write_coef_idx(codec, 0x45, 0xc429);
snd_hda_set_pin_ctl_cache(codec, hp_pin, 0);
alc_process_coef_fw(codec, coef0293);
snd_hda_set_pin_ctl_cache(codec, mic_pin, PIN_VREF50);
break;
case 0x10ec0662:
snd_hda_set_pin_ctl_cache(codec, hp_pin, 0);
snd_hda_set_pin_ctl_cache(codec, mic_pin, PIN_VREF50);
break;
case 0x10ec0668:
alc_write_coef_idx(codec, 0x11, 0x0001);
snd_hda_set_pin_ctl_cache(codec, hp_pin, 0);
alc_process_coef_fw(codec, coef0688);
snd_hda_set_pin_ctl_cache(codec, mic_pin, PIN_VREF50);
break;
}
codec_dbg(codec, "Headset jack set to mic-in mode.\n");
}
static void alc_headset_mode_default(struct hda_codec *codec)
{
static struct coef_fw coef0255[] = {
WRITE_COEF(0x45, 0xc089),
WRITE_COEF(0x45, 0xc489),
WRITE_COEFEX(0x57, 0x03, 0x8ea6),
WRITE_COEF(0x49, 0x0049),
{}
};
static struct coef_fw coef0233[] = {
WRITE_COEF(0x06, 0x2100),
WRITE_COEF(0x32, 0x4ea3),
{}
};
static struct coef_fw coef0288[] = {
UPDATE_COEF(0x4f, 0xfcc0, 0xc400),
UPDATE_COEF(0x50, 0x2000, 0x2000),
UPDATE_COEF(0x56, 0x0006, 0x0006),
UPDATE_COEF(0x66, 0x0008, 0),
UPDATE_COEF(0x67, 0x2000, 0),
{}
};
static struct coef_fw coef0292[] = {
WRITE_COEF(0x76, 0x000e),
WRITE_COEF(0x6c, 0x2400),
WRITE_COEF(0x6b, 0xc429),
WRITE_COEF(0x18, 0x7308),
{}
};
static struct coef_fw coef0293[] = {
UPDATE_COEF(0x4a, 0x000f, 0x000e),
WRITE_COEF(0x45, 0xC429),
UPDATE_COEF(0x1a, 1<<3, 0),
{}
};
static struct coef_fw coef0688[] = {
WRITE_COEF(0x11, 0x0041),
WRITE_COEF(0x15, 0x0d40),
WRITE_COEF(0xb7, 0x802b),
{}
};
switch (codec->core.vendor_id) {
case 0x10ec0255:
case 0x10ec0256:
alc_process_coef_fw(codec, coef0255);
break;
case 0x10ec0233:
case 0x10ec0283:
alc_process_coef_fw(codec, coef0233);
break;
case 0x10ec0286:
case 0x10ec0288:
alc_process_coef_fw(codec, coef0288);
break;
case 0x10ec0292:
alc_process_coef_fw(codec, coef0292);
break;
case 0x10ec0293:
alc_process_coef_fw(codec, coef0293);
break;
case 0x10ec0668:
alc_process_coef_fw(codec, coef0688);
break;
}
codec_dbg(codec, "Headset jack set to headphone (default) mode.\n");
}
static void alc_headset_mode_ctia(struct hda_codec *codec)
{
static struct coef_fw coef0255[] = {
WRITE_COEF(0x45, 0xd489),
WRITE_COEF(0x1b, 0x0c2b),
WRITE_COEFEX(0x57, 0x03, 0x8ea6),
{}
};
static struct coef_fw coef0233[] = {
WRITE_COEF(0x45, 0xd429),
WRITE_COEF(0x1b, 0x0c2b),
WRITE_COEF(0x32, 0x4ea3),
{}
};
static struct coef_fw coef0288[] = {
UPDATE_COEF(0x50, 0x2000, 0x2000),
UPDATE_COEF(0x56, 0x0006, 0x0006),
UPDATE_COEF(0x66, 0x0008, 0),
UPDATE_COEF(0x67, 0x2000, 0),
{}
};
static struct coef_fw coef0292[] = {
WRITE_COEF(0x6b, 0xd429),
WRITE_COEF(0x76, 0x0008),
WRITE_COEF(0x18, 0x7388),
{}
};
static struct coef_fw coef0293[] = {
WRITE_COEF(0x45, 0xd429),
UPDATE_COEF(0x10, 7<<8, 7<<8),
{}
};
static struct coef_fw coef0688[] = {
WRITE_COEF(0x11, 0x0001),
WRITE_COEF(0x15, 0x0d60),
WRITE_COEF(0xc3, 0x0000),
{}
};
switch (codec->core.vendor_id) {
case 0x10ec0255:
case 0x10ec0256:
alc_process_coef_fw(codec, coef0255);
break;
case 0x10ec0233:
case 0x10ec0283:
alc_process_coef_fw(codec, coef0233);
break;
case 0x10ec0286:
case 0x10ec0288:
alc_update_coef_idx(codec, 0x4f, 0xfcc0, 0xd400);
msleep(300);
alc_process_coef_fw(codec, coef0288);
break;
case 0x10ec0292:
alc_process_coef_fw(codec, coef0292);
break;
case 0x10ec0293:
alc_process_coef_fw(codec, coef0293);
break;
case 0x10ec0668:
alc_process_coef_fw(codec, coef0688);
break;
}
codec_dbg(codec, "Headset jack set to iPhone-style headset mode.\n");
}
static void alc_headset_mode_omtp(struct hda_codec *codec)
{
static struct coef_fw coef0255[] = {
WRITE_COEF(0x45, 0xe489),
WRITE_COEF(0x1b, 0x0c2b),
WRITE_COEFEX(0x57, 0x03, 0x8ea6),
{}
};
static struct coef_fw coef0233[] = {
WRITE_COEF(0x45, 0xe429),
WRITE_COEF(0x1b, 0x0c2b),
WRITE_COEF(0x32, 0x4ea3),
{}
};
static struct coef_fw coef0288[] = {
UPDATE_COEF(0x50, 0x2000, 0x2000),
UPDATE_COEF(0x56, 0x0006, 0x0006),
UPDATE_COEF(0x66, 0x0008, 0),
UPDATE_COEF(0x67, 0x2000, 0),
{}
};
static struct coef_fw coef0292[] = {
WRITE_COEF(0x6b, 0xe429),
WRITE_COEF(0x76, 0x0008),
WRITE_COEF(0x18, 0x7388),
{}
};
static struct coef_fw coef0293[] = {
WRITE_COEF(0x45, 0xe429),
UPDATE_COEF(0x10, 7<<8, 7<<8),
{}
};
static struct coef_fw coef0688[] = {
WRITE_COEF(0x11, 0x0001),
WRITE_COEF(0x15, 0x0d50),
WRITE_COEF(0xc3, 0x0000),
{}
};
switch (codec->core.vendor_id) {
case 0x10ec0255:
case 0x10ec0256:
alc_process_coef_fw(codec, coef0255);
break;
case 0x10ec0233:
case 0x10ec0283:
alc_process_coef_fw(codec, coef0233);
break;
case 0x10ec0286:
case 0x10ec0288:
alc_update_coef_idx(codec, 0x4f, 0xfcc0, 0xe400);
msleep(300);
alc_process_coef_fw(codec, coef0288);
break;
case 0x10ec0292:
alc_process_coef_fw(codec, coef0292);
break;
case 0x10ec0293:
alc_process_coef_fw(codec, coef0293);
break;
case 0x10ec0668:
alc_process_coef_fw(codec, coef0688);
break;
}
codec_dbg(codec, "Headset jack set to Nokia-style headset mode.\n");
}
static void alc_determine_headset_type(struct hda_codec *codec)
{
int val;
bool is_ctia = false;
struct alc_spec *spec = codec->spec;
static struct coef_fw coef0255[] = {
WRITE_COEF(0x45, 0xd089),
WRITE_COEF(0x49, 0x0149),
{}
};
static struct coef_fw coef0288[] = {
UPDATE_COEF(0x4f, 0xfcc0, 0xd400),
{}
};
static struct coef_fw coef0293[] = {
UPDATE_COEF(0x4a, 0x000f, 0x0008),
WRITE_COEF(0x45, 0xD429),
{}
};
static struct coef_fw coef0688[] = {
WRITE_COEF(0x11, 0x0001),
WRITE_COEF(0xb7, 0x802b),
WRITE_COEF(0x15, 0x0d60),
WRITE_COEF(0xc3, 0x0c00),
{}
};
switch (codec->core.vendor_id) {
case 0x10ec0255:
case 0x10ec0256:
alc_process_coef_fw(codec, coef0255);
msleep(300);
val = alc_read_coef_idx(codec, 0x46);
is_ctia = (val & 0x0070) == 0x0070;
break;
case 0x10ec0233:
case 0x10ec0283:
alc_write_coef_idx(codec, 0x45, 0xd029);
msleep(300);
val = alc_read_coef_idx(codec, 0x46);
is_ctia = (val & 0x0070) == 0x0070;
break;
case 0x10ec0286:
case 0x10ec0288:
alc_process_coef_fw(codec, coef0288);
msleep(350);
val = alc_read_coef_idx(codec, 0x50);
is_ctia = (val & 0x0070) == 0x0070;
break;
case 0x10ec0292:
alc_write_coef_idx(codec, 0x6b, 0xd429);
msleep(300);
val = alc_read_coef_idx(codec, 0x6c);
is_ctia = (val & 0x001c) == 0x001c;
break;
case 0x10ec0293:
alc_process_coef_fw(codec, coef0293);
msleep(300);
val = alc_read_coef_idx(codec, 0x46);
is_ctia = (val & 0x0070) == 0x0070;
break;
case 0x10ec0668:
alc_process_coef_fw(codec, coef0688);
msleep(300);
val = alc_read_coef_idx(codec, 0xbe);
is_ctia = (val & 0x1c02) == 0x1c02;
break;
}
codec_dbg(codec, "Headset jack detected iPhone-style headset: %s\n",
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
if (new_headset_mode == spec->current_headset_mode) {
snd_hda_gen_update_outputs(codec);
return;
}
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
if (spec->headphone_mic_pin && spec->headphone_mic_pin != hp_pin)
snd_hda_set_pin_ctl_cache(codec, spec->headphone_mic_pin,
PIN_VREFHIZ);
}
spec->current_headset_mode = new_headset_mode;
snd_hda_gen_update_outputs(codec);
}
static void alc_update_headset_mode_hook(struct hda_codec *codec,
struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
alc_update_headset_mode(codec);
}
static void alc_update_headset_jack_cb(struct hda_codec *codec,
struct hda_jack_callback *jack)
{
struct alc_spec *spec = codec->spec;
spec->current_headset_type = ALC_HEADSET_TYPE_UNKNOWN;
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
static void alc255_set_default_jack_type(struct hda_codec *codec)
{
static struct coef_fw fw[] = {
WRITE_COEF(0x1b, 0x880b),
WRITE_COEF(0x45, 0xd089),
WRITE_COEF(0x1b, 0x080b),
WRITE_COEF(0x46, 0x0004),
WRITE_COEF(0x1b, 0x0c0b),
{}
};
alc_process_coef_fw(codec, fw);
msleep(30);
}
static void alc_fixup_headset_mode_alc255(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
if (action == HDA_FIXUP_ACT_PRE_PROBE) {
alc255_set_default_jack_type(codec);
}
alc_fixup_headset_mode(codec, fix, action);
}
static void alc_fixup_headset_mode_alc255_no_hp_mic(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
if (action == HDA_FIXUP_ACT_PRE_PROBE) {
struct alc_spec *spec = codec->spec;
spec->parse_flags |= HDA_PINCFG_HEADSET_MIC;
alc255_set_default_jack_type(codec);
}
else
alc_fixup_headset_mode(codec, fix, action);
}
static void alc288_update_headset_jack_cb(struct hda_codec *codec,
struct hda_jack_callback *jack)
{
struct alc_spec *spec = codec->spec;
int present;
alc_update_headset_jack_cb(codec, jack);
present = spec->gen.hp_jack_present ? 0x40 : 0;
snd_hda_codec_write(codec, 0x01, 0, AC_VERB_SET_GPIO_DATA,
present);
}
static void alc_fixup_headset_mode_dell_alc288(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
alc_fixup_headset_mode(codec, fix, action);
if (action == HDA_FIXUP_ACT_PROBE) {
struct alc_spec *spec = codec->spec;
spec->gen.hp_automute_hook = alc288_update_headset_jack_cb;
}
}
static void alc_fixup_auto_mute_via_amp(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
if (action == HDA_FIXUP_ACT_PRE_PROBE) {
struct alc_spec *spec = codec->spec;
spec->gen.auto_mute_via_amp = 1;
}
}
static void alc_no_shutup(struct hda_codec *codec)
{
}
static void alc_fixup_no_shutup(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
if (action == HDA_FIXUP_ACT_PRE_PROBE) {
struct alc_spec *spec = codec->spec;
spec->shutup = alc_no_shutup;
}
}
static void alc_fixup_disable_aamix(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
if (action == HDA_FIXUP_ACT_PRE_PROBE) {
struct alc_spec *spec = codec->spec;
spec->gen.mixer_nid = 0;
}
}
static void alc_shutup_dell_xps13(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
int hp_pin = spec->gen.autocfg.hp_pins[0];
snd_hda_codec_write(codec, hp_pin, 0,
AC_VERB_SET_AMP_GAIN_MUTE, AMP_OUT_MUTE);
msleep(20);
}
static void alc_fixup_dell_xps13(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
struct alc_spec *spec = codec->spec;
struct hda_input_mux *imux = &spec->gen.input_mux;
int i;
switch (action) {
case HDA_FIXUP_ACT_PRE_PROBE:
snd_hda_codec_set_pin_target(codec, 0x19, PIN_VREFHIZ);
break;
case HDA_FIXUP_ACT_PROBE:
spec->shutup = alc_shutup_dell_xps13;
for (i = 0; i < imux->num_items; i++) {
if (spec->gen.imux_pins[i] == 0x12) {
spec->gen.cur_mux[0] = i;
break;
}
}
break;
}
}
static void alc_fixup_headset_mode_alc662(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
struct alc_spec *spec = codec->spec;
if (action == HDA_FIXUP_ACT_PRE_PROBE) {
spec->parse_flags |= HDA_PINCFG_HEADSET_MIC;
spec->gen.hp_mic = 1;
snd_hda_codec_write(codec, 0x1b, 0, AC_VERB_SET_AMP_GAIN_MUTE, 0x7000);
snd_hda_override_wcaps(codec, 0x1b, get_wcaps(codec, 0x1b) & ~AC_WCAP_IN_AMP);
} else
alc_fixup_headset_mode(codec, fix, action);
}
static void alc_fixup_headset_mode_alc668(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
if (action == HDA_FIXUP_ACT_PRE_PROBE) {
alc_write_coef_idx(codec, 0xc4, 0x8000);
alc_update_coef_idx(codec, 0xc2, ~0xfe, 0);
snd_hda_set_pin_ctl_cache(codec, 0x18, 0);
}
alc_fixup_headset_mode(codec, fix, action);
}
static int find_ext_mic_pin(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
struct auto_pin_cfg *cfg = &spec->gen.autocfg;
hda_nid_t nid;
unsigned int defcfg;
int i;
for (i = 0; i < cfg->num_inputs; i++) {
if (cfg->inputs[i].type != AUTO_PIN_MIC)
continue;
nid = cfg->inputs[i].pin;
defcfg = snd_hda_codec_get_pincfg(codec, nid);
if (snd_hda_get_input_pin_attr(defcfg) == INPUT_PIN_ATTR_INT)
continue;
return nid;
}
return 0;
}
static void alc271_hp_gate_mic_jack(struct hda_codec *codec,
const struct hda_fixup *fix,
int action)
{
struct alc_spec *spec = codec->spec;
if (action == HDA_FIXUP_ACT_PROBE) {
int mic_pin = find_ext_mic_pin(codec);
int hp_pin = spec->gen.autocfg.hp_pins[0];
if (snd_BUG_ON(!mic_pin || !hp_pin))
return;
snd_hda_jack_set_gating_jack(codec, mic_pin, hp_pin);
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
static void alc283_hp_automute_hook(struct hda_codec *codec,
struct hda_jack_callback *jack)
{
struct alc_spec *spec = codec->spec;
int vref;
msleep(200);
snd_hda_gen_hp_automute(codec, jack);
vref = spec->gen.hp_jack_present ? PIN_VREF80 : 0;
msleep(600);
snd_hda_codec_write(codec, 0x19, 0, AC_VERB_SET_PIN_WIDGET_CONTROL,
vref);
}
static void alc283_fixup_chromebook(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
struct alc_spec *spec = codec->spec;
switch (action) {
case HDA_FIXUP_ACT_PRE_PROBE:
snd_hda_override_wcaps(codec, 0x03, 0);
spec->gen.mixer_nid = 0;
break;
case HDA_FIXUP_ACT_INIT:
alc_update_coef_idx(codec, 0x06, 0x000c, 0);
alc_update_coef_idx(codec, 0x1a, 0, 1 << 4);
break;
}
}
static void alc283_fixup_sense_combo_jack(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
struct alc_spec *spec = codec->spec;
switch (action) {
case HDA_FIXUP_ACT_PRE_PROBE:
spec->gen.hp_automute_hook = alc283_hp_automute_hook;
break;
case HDA_FIXUP_ACT_INIT:
alc_update_coef_idx(codec, 0x06, 0x000c, 0);
break;
}
}
static void asus_tx300_automute(struct hda_codec *codec)
{
struct alc_spec *spec = codec->spec;
snd_hda_gen_update_outputs(codec);
if (snd_hda_jack_detect(codec, 0x1b))
spec->gen.mute_bits |= (1ULL << 0x14);
}
static void alc282_fixup_asus_tx300(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
struct alc_spec *spec = codec->spec;
static const struct hda_verb gpio2_verbs[] = {
{ 0x01, AC_VERB_SET_GPIO_MASK, 0x04 },
{ 0x01, AC_VERB_SET_GPIO_DIRECTION, 0x04 },
{ 0x01, AC_VERB_SET_GPIO_DATA, 0x04 },
{}
};
static const struct hda_pintbl dock_pins[] = {
{ 0x1b, 0x21114000 },
{}
};
struct snd_kcontrol *kctl;
switch (action) {
case HDA_FIXUP_ACT_PRE_PROBE:
snd_hda_add_verbs(codec, gpio2_verbs);
snd_hda_apply_pincfgs(codec, dock_pins);
spec->gen.auto_mute_via_amp = 1;
spec->gen.automute_hook = asus_tx300_automute;
snd_hda_jack_detect_enable_callback(codec, 0x1b,
snd_hda_gen_hp_automute);
break;
case HDA_FIXUP_ACT_BUILD:
kctl = snd_hda_find_mixer_ctl(codec, "Speaker Playback Switch");
if (kctl)
strcpy(kctl->id.name, "Dock Speaker Playback Switch");
kctl = snd_hda_find_mixer_ctl(codec, "Bass Speaker Playback Switch");
if (kctl)
strcpy(kctl->id.name, "Speaker Playback Switch");
break;
}
}
static void alc290_fixup_mono_speakers(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
if (action == HDA_FIXUP_ACT_PRE_PROBE) {
hda_nid_t conn1[2] = { 0x0c };
snd_hda_override_conn_list(codec, 0x14, 1, conn1);
snd_hda_override_conn_list(codec, 0x15, 1, conn1);
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
alc_update_coef_idx(codec, 0x04, 0, 1<<11);
}
if ((alc_get_coef0(codec) & 0x00ff) == 0x018) {
val = alc_read_coef_idx(codec, 0xd);
if (val != -1 && (val & 0x0c00) >> 10 != 0x1) {
alc_write_coef_idx(codec, 0xd, val | (1<<10));
}
val = alc_read_coef_idx(codec, 0x17);
if (val != -1 && (val & 0x01c0) >> 6 != 0x4) {
alc_write_coef_idx(codec, 0x17, val | (1<<7));
}
}
alc_update_coef_idx(codec, 0x4, 0, 1<<11);
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
codec->power_save_node = 1;
snd_hda_pick_fixup(codec, alc269_fixup_models,
alc269_fixup_tbl, alc269_fixups);
snd_hda_pick_pin_fixup(codec, alc269_pin_fixup_tbl, alc269_fixups);
snd_hda_pick_fixup(codec, NULL, alc269_fixup_vendor_tbl,
alc269_fixups);
snd_hda_apply_fixup(codec, HDA_FIXUP_ACT_PRE_PROBE);
alc_auto_parse_customize_define(codec);
if (has_cdefine_beep(codec))
spec->gen.beep_nid = 0x01;
switch (codec->core.vendor_id) {
case 0x10ec0269:
spec->codec_variant = ALC269_TYPE_ALC269VA;
switch (alc_get_coef0(codec) & 0x00f0) {
case 0x0010:
if (codec->bus->pci &&
codec->bus->pci->subsystem_vendor == 0x1025 &&
spec->cdefine.platform_type == 1)
err = alc_codec_rename(codec, "ALC271X");
spec->codec_variant = ALC269_TYPE_ALC269VB;
break;
case 0x0020:
if (codec->bus->pci &&
codec->bus->pci->subsystem_vendor == 0x17aa &&
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
case 0x10ec0282:
spec->codec_variant = ALC269_TYPE_ALC282;
spec->shutup = alc282_shutup;
spec->init_hook = alc282_init;
break;
case 0x10ec0233:
case 0x10ec0283:
spec->codec_variant = ALC269_TYPE_ALC283;
spec->shutup = alc283_shutup;
spec->init_hook = alc283_init;
break;
case 0x10ec0284:
case 0x10ec0292:
spec->codec_variant = ALC269_TYPE_ALC284;
break;
case 0x10ec0285:
case 0x10ec0293:
spec->codec_variant = ALC269_TYPE_ALC285;
break;
case 0x10ec0286:
case 0x10ec0288:
spec->codec_variant = ALC269_TYPE_ALC286;
spec->shutup = alc286_shutup;
break;
case 0x10ec0298:
spec->codec_variant = ALC269_TYPE_ALC298;
break;
case 0x10ec0255:
spec->codec_variant = ALC269_TYPE_ALC255;
break;
case 0x10ec0256:
spec->codec_variant = ALC269_TYPE_ALC256;
spec->gen.mixer_nid = 0;
alc_update_coef_idx(codec, 0x36, 1 << 13, 1 << 5);
break;
}
if (snd_hda_codec_read(codec, 0x51, 0, AC_VERB_PARAMETERS, 0) == 0x10ec5505) {
spec->has_alc5505_dsp = 1;
spec->init_hook = alc5505_dsp_init;
}
err = alc269_parse_auto_config(codec);
if (err < 0)
goto error;
if (!spec->gen.no_analog && spec->gen.beep_nid && spec->gen.mixer_nid)
set_beep_amp(spec, spec->gen.mixer_nid, 0x04, HDA_INPUT);
codec->patch_ops = alc_patch_ops;
codec->patch_ops.stream_pm = snd_hda_gen_stream_pm;
#ifdef CONFIG_PM
codec->patch_ops.suspend = alc269_suspend;
codec->patch_ops.resume = alc269_resume;
#endif
if (!spec->shutup)
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
if (codec->core.vendor_id == 0x10ec0272 || codec->core.vendor_id == 0x10ec0663 ||
codec->core.vendor_id == 0x10ec0665 || codec->core.vendor_id == 0x10ec0670 ||
codec->core.vendor_id == 0x10ec0671)
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
codec_warn(codec, "failed to override amp caps for NID 0x2\n");
}
static void alc_fixup_bass_chmap(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
if (action == HDA_FIXUP_ACT_BUILD) {
struct alc_spec *spec = codec->spec;
spec->gen.pcm_rec[0]->stream[0].chmap = asus_pcm_2_1_chmaps;
}
}
static unsigned int gpio_led_power_filter(struct hda_codec *codec,
hda_nid_t nid,
unsigned int power_state)
{
struct alc_spec *spec = codec->spec;
if (nid == codec->core.afg && power_state == AC_PWRST_D3 && spec->gpio_led)
return AC_PWRST_D0;
return power_state;
}
static void alc662_fixup_led_gpio1(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
struct alc_spec *spec = codec->spec;
static const struct hda_verb gpio_init[] = {
{ 0x01, AC_VERB_SET_GPIO_MASK, 0x01 },
{ 0x01, AC_VERB_SET_GPIO_DIRECTION, 0x01 },
{}
};
if (action == HDA_FIXUP_ACT_PRE_PROBE) {
spec->gen.vmaster_mute.hook = alc_fixup_gpio_mute_hook;
spec->gpio_led = 0;
spec->mute_led_polarity = 1;
spec->gpio_mute_led_mask = 0x01;
snd_hda_add_verbs(codec, gpio_init);
codec->power_filter = gpio_led_power_filter;
}
}
static void alc668_restore_default_value(struct hda_codec *codec)
{
alc_process_coef_fw(codec, alc668_coefs);
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
switch (codec->core.vendor_id) {
case 0x10ec0668:
spec->init_hook = alc668_restore_default_value;
break;
}
snd_hda_pick_fixup(codec, alc662_fixup_models,
alc662_fixup_tbl, alc662_fixups);
snd_hda_pick_pin_fixup(codec, alc662_pin_fixup_tbl, alc662_fixups);
snd_hda_apply_fixup(codec, HDA_FIXUP_ACT_PRE_PROBE);
alc_auto_parse_customize_define(codec);
if (has_cdefine_beep(codec))
spec->gen.beep_nid = 0x01;
if ((alc_get_coef0(codec) & (1 << 14)) &&
codec->bus->pci && codec->bus->pci->subsystem_vendor == 0x1025 &&
spec->cdefine.platform_type == 1) {
err = alc_codec_rename(codec, "ALC272X");
if (err < 0)
goto error;
}
err = alc662_parse_auto_config(codec);
if (err < 0)
goto error;
if (!spec->gen.no_analog && spec->gen.beep_nid) {
switch (codec->core.vendor_id) {
case 0x10ec0662:
set_beep_amp(spec, 0x0b, 0x05, HDA_INPUT);
break;
case 0x10ec0272:
case 0x10ec0663:
case 0x10ec0665:
case 0x10ec0668:
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
