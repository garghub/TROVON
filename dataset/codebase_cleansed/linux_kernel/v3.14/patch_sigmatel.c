static void stac_playback_pcm_hook(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
struct snd_pcm_substream *substream,
int action)
{
struct sigmatel_spec *spec = codec->spec;
if (action == HDA_GEN_PCM_ACT_OPEN && spec->stream_delay)
msleep(spec->stream_delay);
}
static void stac_capture_pcm_hook(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
struct snd_pcm_substream *substream,
int action)
{
struct sigmatel_spec *spec = codec->spec;
int i, idx = 0;
if (!spec->powerdown_adcs)
return;
for (i = 0; i < spec->gen.num_all_adcs; i++) {
if (spec->gen.all_adcs[i] == hinfo->nid) {
idx = i;
break;
}
}
switch (action) {
case HDA_GEN_PCM_ACT_OPEN:
msleep(40);
snd_hda_codec_write(codec, hinfo->nid, 0,
AC_VERB_SET_POWER_STATE, AC_PWRST_D0);
spec->active_adcs |= (1 << idx);
break;
case HDA_GEN_PCM_ACT_CLOSE:
snd_hda_codec_write(codec, hinfo->nid, 0,
AC_VERB_SET_POWER_STATE, AC_PWRST_D3);
spec->active_adcs &= ~(1 << idx);
break;
}
}
static void stac_gpio_set(struct hda_codec *codec, unsigned int mask,
unsigned int dir_mask, unsigned int data)
{
unsigned int gpiostate, gpiomask, gpiodir;
snd_printdd("%s msk %x dir %x gpio %x\n", __func__, mask, dir_mask, data);
gpiostate = snd_hda_codec_read(codec, codec->afg, 0,
AC_VERB_GET_GPIO_DATA, 0);
gpiostate = (gpiostate & ~dir_mask) | (data & dir_mask);
gpiomask = snd_hda_codec_read(codec, codec->afg, 0,
AC_VERB_GET_GPIO_MASK, 0);
gpiomask |= mask;
gpiodir = snd_hda_codec_read(codec, codec->afg, 0,
AC_VERB_GET_GPIO_DIRECTION, 0);
gpiodir |= dir_mask;
snd_hda_codec_write(codec, codec->afg, 0, 0x7e7, 0);
snd_hda_codec_write(codec, codec->afg, 0,
AC_VERB_SET_GPIO_MASK, gpiomask);
snd_hda_codec_read(codec, codec->afg, 0,
AC_VERB_SET_GPIO_DIRECTION, gpiodir);
msleep(1);
snd_hda_codec_read(codec, codec->afg, 0,
AC_VERB_SET_GPIO_DATA, gpiostate);
}
static void stac_capture_led_hook(struct hda_codec *codec,
struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct sigmatel_spec *spec = codec->spec;
unsigned int mask;
bool cur_mute, prev_mute;
if (!kcontrol || !ucontrol)
return;
mask = 1U << snd_ctl_get_ioffidx(kcontrol, &ucontrol->id);
prev_mute = !spec->mic_enabled;
if (ucontrol->value.integer.value[0] ||
ucontrol->value.integer.value[1])
spec->mic_enabled |= mask;
else
spec->mic_enabled &= ~mask;
cur_mute = !spec->mic_enabled;
if (cur_mute != prev_mute) {
if (cur_mute)
spec->gpio_data |= spec->mic_mute_led_gpio;
else
spec->gpio_data &= ~spec->mic_mute_led_gpio;
stac_gpio_set(codec, spec->gpio_mask,
spec->gpio_dir, spec->gpio_data);
}
}
static int stac_vrefout_set(struct hda_codec *codec,
hda_nid_t nid, unsigned int new_vref)
{
int error, pinctl;
snd_printdd("%s, nid %x ctl %x\n", __func__, nid, new_vref);
pinctl = snd_hda_codec_read(codec, nid, 0,
AC_VERB_GET_PIN_WIDGET_CONTROL, 0);
if (pinctl < 0)
return pinctl;
pinctl &= 0xff;
pinctl &= ~AC_PINCTL_VREFEN;
pinctl |= (new_vref & AC_PINCTL_VREFEN);
error = snd_hda_set_pin_ctl_cache(codec, nid, pinctl);
if (error < 0)
return error;
return 1;
}
static unsigned int stac_vref_led_power_filter(struct hda_codec *codec,
hda_nid_t nid,
unsigned int power_state)
{
if (nid == codec->afg && power_state == AC_PWRST_D3)
return AC_PWRST_D1;
return snd_hda_gen_path_power_filter(codec, nid, power_state);
}
static void stac_update_led_status(struct hda_codec *codec, int enabled)
{
struct sigmatel_spec *spec = codec->spec;
int muted = !enabled;
if (!spec->gpio_led)
return;
if (spec->gpio_led_polarity)
muted = !muted;
if (!spec->vref_mute_led_nid) {
if (muted)
spec->gpio_data |= spec->gpio_led;
else
spec->gpio_data &= ~spec->gpio_led;
stac_gpio_set(codec, spec->gpio_mask,
spec->gpio_dir, spec->gpio_data);
} else {
spec->vref_led = muted ? AC_PINCTL_VREF_50 : AC_PINCTL_VREF_GRD;
stac_vrefout_set(codec, spec->vref_mute_led_nid,
spec->vref_led);
}
}
static void stac_vmaster_hook(void *private_data, int val)
{
stac_update_led_status(private_data, val);
}
static void stac_update_outputs(struct hda_codec *codec)
{
struct sigmatel_spec *spec = codec->spec;
if (spec->gpio_mute)
spec->gen.master_mute =
!(snd_hda_codec_read(codec, codec->afg, 0,
AC_VERB_GET_GPIO_DATA, 0) & spec->gpio_mute);
snd_hda_gen_update_outputs(codec);
if (spec->eapd_mask && spec->eapd_switch) {
unsigned int val = spec->gpio_data;
if (spec->gen.speaker_muted)
val &= ~spec->eapd_mask;
else
val |= spec->eapd_mask;
if (spec->gpio_data != val) {
spec->gpio_data = val;
stac_gpio_set(codec, spec->gpio_mask, spec->gpio_dir,
val);
}
}
}
static void stac_toggle_power_map(struct hda_codec *codec, hda_nid_t nid,
bool enable, bool do_write)
{
struct sigmatel_spec *spec = codec->spec;
unsigned int idx, val;
for (idx = 0; idx < spec->num_pwrs; idx++) {
if (spec->pwr_nids[idx] == nid)
break;
}
if (idx >= spec->num_pwrs)
return;
idx = 1 << idx;
val = spec->power_map_bits;
if (enable)
val &= ~idx;
else
val |= idx;
if (val != spec->power_map_bits) {
spec->power_map_bits = val;
if (do_write)
snd_hda_codec_write(codec, codec->afg, 0,
AC_VERB_IDT_SET_POWER_MAP, val);
}
}
static void jack_update_power(struct hda_codec *codec,
struct hda_jack_tbl *jack)
{
struct sigmatel_spec *spec = codec->spec;
int i;
if (!spec->num_pwrs)
return;
if (jack && jack->nid) {
stac_toggle_power_map(codec, jack->nid,
snd_hda_jack_detect(codec, jack->nid),
true);
return;
}
for (i = 0; i < spec->num_pwrs; i++) {
hda_nid_t nid = spec->pwr_nids[i];
jack = snd_hda_jack_tbl_get(codec, nid);
if (!jack || !jack->action)
continue;
if (jack->action == STAC_PWR_EVENT ||
jack->action <= HDA_GEN_LAST_EVENT)
stac_toggle_power_map(codec, nid,
snd_hda_jack_detect(codec, nid),
false);
}
snd_hda_codec_write(codec, codec->afg, 0, AC_VERB_IDT_SET_POWER_MAP,
spec->power_map_bits);
}
static void stac_hp_automute(struct hda_codec *codec,
struct hda_jack_tbl *jack)
{
snd_hda_gen_hp_automute(codec, jack);
jack_update_power(codec, jack);
}
static void stac_line_automute(struct hda_codec *codec,
struct hda_jack_tbl *jack)
{
snd_hda_gen_line_automute(codec, jack);
jack_update_power(codec, jack);
}
static void stac_mic_autoswitch(struct hda_codec *codec,
struct hda_jack_tbl *jack)
{
snd_hda_gen_mic_autoswitch(codec, jack);
jack_update_power(codec, jack);
}
static void stac_vref_event(struct hda_codec *codec, struct hda_jack_tbl *event)
{
unsigned int data;
data = snd_hda_codec_read(codec, codec->afg, 0,
AC_VERB_GET_GPIO_DATA, 0);
snd_hda_codec_write(codec, codec->afg, 0, 0x7e0,
!!(data & (1 << event->private_data)));
}
static void stac_init_power_map(struct hda_codec *codec)
{
struct sigmatel_spec *spec = codec->spec;
int i;
for (i = 0; i < spec->num_pwrs; i++) {
hda_nid_t nid = spec->pwr_nids[i];
unsigned int def_conf = snd_hda_codec_get_pincfg(codec, nid);
def_conf = get_defcfg_connect(def_conf);
if (snd_hda_jack_tbl_get(codec, nid))
continue;
if (def_conf == AC_JACK_PORT_COMPLEX &&
!(spec->vref_mute_led_nid == nid ||
is_jack_detectable(codec, nid))) {
snd_hda_jack_detect_enable_callback(codec, nid,
STAC_PWR_EVENT,
jack_update_power);
} else {
if (def_conf == AC_JACK_PORT_NONE)
stac_toggle_power_map(codec, nid, false, false);
else
stac_toggle_power_map(codec, nid, true, false);
}
}
}
static inline bool get_int_hint(struct hda_codec *codec, const char *key,
int *valp)
{
return !snd_hda_get_int_hint(codec, key, valp);
}
static void stac_store_hints(struct hda_codec *codec)
{
struct sigmatel_spec *spec = codec->spec;
int val;
if (get_int_hint(codec, "gpio_mask", &spec->gpio_mask)) {
spec->eapd_mask = spec->gpio_dir = spec->gpio_data =
spec->gpio_mask;
}
if (get_int_hint(codec, "gpio_dir", &spec->gpio_dir))
spec->gpio_mask &= spec->gpio_mask;
if (get_int_hint(codec, "gpio_data", &spec->gpio_data))
spec->gpio_dir &= spec->gpio_mask;
if (get_int_hint(codec, "eapd_mask", &spec->eapd_mask))
spec->eapd_mask &= spec->gpio_mask;
if (get_int_hint(codec, "gpio_mute", &spec->gpio_mute))
spec->gpio_mute &= spec->gpio_mask;
val = snd_hda_get_bool_hint(codec, "eapd_switch");
if (val >= 0)
spec->eapd_switch = val;
}
static int stac_aloopback_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
unsigned int idx = snd_ctl_get_ioffidx(kcontrol, &ucontrol->id);
struct sigmatel_spec *spec = codec->spec;
ucontrol->value.integer.value[0] = !!(spec->aloopback &
(spec->aloopback_mask << idx));
return 0;
}
static int stac_aloopback_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct sigmatel_spec *spec = codec->spec;
unsigned int idx = snd_ctl_get_ioffidx(kcontrol, &ucontrol->id);
unsigned int dac_mode;
unsigned int val, idx_val;
idx_val = spec->aloopback_mask << idx;
if (ucontrol->value.integer.value[0])
val = spec->aloopback | idx_val;
else
val = spec->aloopback & ~idx_val;
if (spec->aloopback == val)
return 0;
spec->aloopback = val;
dac_mode = snd_hda_codec_read(codec, codec->afg, 0,
kcontrol->private_value & 0xFFFF, 0x0);
dac_mode >>= spec->aloopback_shift;
if (spec->aloopback & idx_val) {
snd_hda_power_up(codec);
dac_mode |= idx_val;
} else {
snd_hda_power_down(codec);
dac_mode &= ~idx_val;
}
snd_hda_codec_write_cache(codec, codec->afg, 0,
kcontrol->private_value >> 16, dac_mode);
return 1;
}
static bool hp_bnb2011_with_dock(struct hda_codec *codec)
{
if (codec->vendor_id != 0x111d7605 &&
codec->vendor_id != 0x111d76d1)
return false;
switch (codec->subsystem_id) {
case 0x103c1618:
case 0x103c1619:
case 0x103c161a:
case 0x103c161b:
case 0x103c161c:
case 0x103c161d:
case 0x103c161e:
case 0x103c161f:
case 0x103c162a:
case 0x103c162b:
case 0x103c1630:
case 0x103c1631:
case 0x103c1633:
case 0x103c1634:
case 0x103c1635:
case 0x103c3587:
case 0x103c3588:
case 0x103c3589:
case 0x103c358a:
case 0x103c3667:
case 0x103c3668:
case 0x103c3669:
return true;
}
return false;
}
static bool hp_blike_system(u32 subsystem_id)
{
switch (subsystem_id) {
case 0x103c1520:
case 0x103c1521:
case 0x103c1523:
case 0x103c1524:
case 0x103c1525:
case 0x103c1722:
case 0x103c1723:
case 0x103c1724:
case 0x103c1725:
case 0x103c1726:
case 0x103c1727:
case 0x103c1728:
case 0x103c1729:
case 0x103c172a:
case 0x103c172b:
case 0x103c307e:
case 0x103c307f:
case 0x103c3080:
case 0x103c3081:
case 0x103c7007:
case 0x103c7008:
return true;
}
return false;
}
static void set_hp_led_gpio(struct hda_codec *codec)
{
struct sigmatel_spec *spec = codec->spec;
unsigned int gpio;
if (spec->gpio_led)
return;
gpio = snd_hda_param_read(codec, codec->afg, AC_PAR_GPIO_CAP);
gpio &= AC_GPIO_IO_COUNT;
if (gpio > 3)
spec->gpio_led = 0x08;
else
spec->gpio_led = 0x01;
}
static int find_mute_led_cfg(struct hda_codec *codec, int default_polarity)
{
struct sigmatel_spec *spec = codec->spec;
const struct dmi_device *dev = NULL;
if (get_int_hint(codec, "gpio_led", &spec->gpio_led)) {
get_int_hint(codec, "gpio_led_polarity",
&spec->gpio_led_polarity);
return 1;
}
while ((dev = dmi_find_device(DMI_DEV_TYPE_OEM_STRING, NULL, dev))) {
if (sscanf(dev->name, "HP_Mute_LED_%d_%x",
&spec->gpio_led_polarity,
&spec->gpio_led) == 2) {
unsigned int max_gpio;
max_gpio = snd_hda_param_read(codec, codec->afg,
AC_PAR_GPIO_CAP);
max_gpio &= AC_GPIO_IO_COUNT;
if (spec->gpio_led < max_gpio)
spec->gpio_led = 1 << spec->gpio_led;
else
spec->vref_mute_led_nid = spec->gpio_led;
return 1;
}
if (sscanf(dev->name, "HP_Mute_LED_%d",
&spec->gpio_led_polarity) == 1) {
set_hp_led_gpio(codec);
return 1;
}
if (strstr(dev->name, "HP_Mute_LED_P_G")) {
set_hp_led_gpio(codec);
if (default_polarity >= 0)
spec->gpio_led_polarity = default_polarity;
else
spec->gpio_led_polarity = 1;
return 1;
}
}
if (!hp_blike_system(codec->subsystem_id) &&
(default_polarity == 0 || default_polarity == 1)) {
set_hp_led_gpio(codec);
spec->gpio_led_polarity = default_polarity;
return 1;
}
return 0;
}
static bool has_builtin_speaker(struct hda_codec *codec)
{
struct sigmatel_spec *spec = codec->spec;
hda_nid_t *nid_pin;
int nids, i;
if (spec->gen.autocfg.line_out_type == AUTO_PIN_SPEAKER_OUT) {
nid_pin = spec->gen.autocfg.line_out_pins;
nids = spec->gen.autocfg.line_outs;
} else {
nid_pin = spec->gen.autocfg.speaker_pins;
nids = spec->gen.autocfg.speaker_outs;
}
for (i = 0; i < nids; i++) {
unsigned int def_conf = snd_hda_codec_get_pincfg(codec, nid_pin[i]);
if (snd_hda_get_input_pin_attr(def_conf) == INPUT_PIN_ATTR_INT)
return true;
}
return false;
}
static int stac_auto_create_beep_ctls(struct hda_codec *codec,
hda_nid_t nid)
{
struct sigmatel_spec *spec = codec->spec;
u32 caps = query_amp_caps(codec, nid, HDA_OUTPUT);
struct snd_kcontrol_new *knew;
static struct snd_kcontrol_new abeep_mute_ctl =
HDA_CODEC_MUTE(NULL, 0, 0, 0);
static struct snd_kcontrol_new dbeep_mute_ctl =
HDA_CODEC_MUTE_BEEP(NULL, 0, 0, 0);
static struct snd_kcontrol_new beep_vol_ctl =
HDA_CODEC_VOLUME(NULL, 0, 0, 0);
if ((caps & AC_AMPCAP_MUTE) >> AC_AMPCAP_MUTE_SHIFT) {
const struct snd_kcontrol_new *temp;
if (spec->anabeep_nid == nid)
temp = &abeep_mute_ctl;
else
temp = &dbeep_mute_ctl;
knew = snd_hda_gen_add_kctl(&spec->gen,
"Beep Playback Switch", temp);
if (!knew)
return -ENOMEM;
knew->private_value =
HDA_COMPOSE_AMP_VAL(nid, 1, 0, HDA_OUTPUT);
}
if ((caps & AC_AMPCAP_NUM_STEPS) >> AC_AMPCAP_NUM_STEPS_SHIFT) {
knew = snd_hda_gen_add_kctl(&spec->gen,
"Beep Playback Volume",
&beep_vol_ctl);
if (!knew)
return -ENOMEM;
knew->private_value =
HDA_COMPOSE_AMP_VAL(nid, 1, 0, HDA_OUTPUT);
}
return 0;
}
static int stac_dig_beep_switch_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
ucontrol->value.integer.value[0] = codec->beep->enabled;
return 0;
}
static int stac_dig_beep_switch_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
return snd_hda_enable_beep_device(codec, ucontrol->value.integer.value[0]);
}
static int stac_beep_switch_ctl(struct hda_codec *codec)
{
struct sigmatel_spec *spec = codec->spec;
if (!snd_hda_gen_add_kctl(&spec->gen, NULL, &stac_dig_beep_ctrl))
return -ENOMEM;
return 0;
}
static int stac_smux_enum_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct sigmatel_spec *spec = codec->spec;
return snd_hda_input_mux_info(&spec->spdif_mux, uinfo);
}
static int stac_smux_enum_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct sigmatel_spec *spec = codec->spec;
unsigned int smux_idx = snd_ctl_get_ioffidx(kcontrol, &ucontrol->id);
ucontrol->value.enumerated.item[0] = spec->cur_smux[smux_idx];
return 0;
}
static int stac_smux_enum_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct sigmatel_spec *spec = codec->spec;
unsigned int smux_idx = snd_ctl_get_ioffidx(kcontrol, &ucontrol->id);
return snd_hda_input_mux_put(codec, &spec->spdif_mux, ucontrol,
spec->gen.autocfg.dig_out_pins[smux_idx],
&spec->cur_smux[smux_idx]);
}
static int stac_create_spdif_mux_ctls(struct hda_codec *codec)
{
struct sigmatel_spec *spec = codec->spec;
struct auto_pin_cfg *cfg = &spec->gen.autocfg;
const char * const *labels = spec->spdif_labels;
struct snd_kcontrol_new *kctl;
int i, num_cons;
if (cfg->dig_outs < 1)
return 0;
num_cons = snd_hda_get_num_conns(codec, cfg->dig_out_pins[0]);
if (num_cons <= 1)
return 0;
if (!labels)
labels = stac_spdif_labels;
for (i = 0; i < num_cons; i++) {
if (snd_BUG_ON(!labels[i]))
return -EINVAL;
snd_hda_add_imux_item(&spec->spdif_mux, labels[i], i, NULL);
}
kctl = snd_hda_gen_add_kctl(&spec->gen, NULL, &stac_smux_mixer);
if (!kctl)
return -ENOMEM;
kctl->count = cfg->dig_outs;
return 0;
}
static void stac9200_fixup_panasonic(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
struct sigmatel_spec *spec = codec->spec;
if (action == HDA_FIXUP_ACT_PRE_PROBE) {
spec->gpio_mask = spec->gpio_dir = 0x09;
spec->gpio_data = 0x00;
spec->gen.suppress_auto_mute = 1;
}
}
static void stac92hd73xx_fixup_ref(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
struct sigmatel_spec *spec = codec->spec;
if (action != HDA_FIXUP_ACT_PRE_PROBE)
return;
snd_hda_apply_pincfgs(codec, ref92hd73xx_pin_configs);
spec->gpio_mask = spec->gpio_dir = spec->gpio_data = 0;
}
static void stac92hd73xx_fixup_dell(struct hda_codec *codec)
{
struct sigmatel_spec *spec = codec->spec;
snd_hda_apply_pincfgs(codec, dell_m6_pin_configs);
spec->eapd_switch = 0;
}
static void stac92hd73xx_fixup_dell_eq(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
struct sigmatel_spec *spec = codec->spec;
if (action != HDA_FIXUP_ACT_PRE_PROBE)
return;
stac92hd73xx_fixup_dell(codec);
snd_hda_add_verbs(codec, dell_eq_core_init);
spec->volknob_init = 1;
}
static void stac92hd73xx_fixup_dell_m6_amic(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
if (action != HDA_FIXUP_ACT_PRE_PROBE)
return;
stac92hd73xx_fixup_dell(codec);
snd_hda_codec_set_pincfg(codec, 0x0b, 0x90A70170);
}
static void stac92hd73xx_fixup_dell_m6_dmic(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
if (action != HDA_FIXUP_ACT_PRE_PROBE)
return;
stac92hd73xx_fixup_dell(codec);
snd_hda_codec_set_pincfg(codec, 0x13, 0x90A60160);
}
static void stac92hd73xx_fixup_dell_m6_both(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
if (action != HDA_FIXUP_ACT_PRE_PROBE)
return;
stac92hd73xx_fixup_dell(codec);
snd_hda_codec_set_pincfg(codec, 0x0b, 0x90A70170);
snd_hda_codec_set_pincfg(codec, 0x13, 0x90A60160);
}
static void stac92hd73xx_fixup_alienware_m17x(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
struct sigmatel_spec *spec = codec->spec;
if (action != HDA_FIXUP_ACT_PRE_PROBE)
return;
snd_hda_apply_pincfgs(codec, alienware_m17x_pin_configs);
spec->eapd_switch = 0;
}
static void stac92hd73xx_fixup_no_jd(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
if (action == HDA_FIXUP_ACT_PRE_PROBE)
codec->no_jack_detect = 1;
}
static void stac92hd83xxx_fixup_hp(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
struct sigmatel_spec *spec = codec->spec;
if (action != HDA_FIXUP_ACT_PRE_PROBE)
return;
if (hp_bnb2011_with_dock(codec)) {
snd_hda_codec_set_pincfg(codec, 0xa, 0x2101201f);
snd_hda_codec_set_pincfg(codec, 0xf, 0x2181205e);
}
if (find_mute_led_cfg(codec, spec->default_polarity))
snd_printd("mute LED gpio %d polarity %d\n",
spec->gpio_led,
spec->gpio_led_polarity);
}
static void stac92hd83xxx_fixup_hp_zephyr(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
if (action != HDA_FIXUP_ACT_PRE_PROBE)
return;
snd_hda_apply_pincfgs(codec, hp_zephyr_pin_configs);
snd_hda_add_verbs(codec, stac92hd83xxx_hp_zephyr_init);
}
static void stac92hd83xxx_fixup_hp_led(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
struct sigmatel_spec *spec = codec->spec;
if (action == HDA_FIXUP_ACT_PRE_PROBE)
spec->default_polarity = 0;
}
static void stac92hd83xxx_fixup_hp_inv_led(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
struct sigmatel_spec *spec = codec->spec;
if (action == HDA_FIXUP_ACT_PRE_PROBE)
spec->default_polarity = 1;
}
static void stac92hd83xxx_fixup_hp_mic_led(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
struct sigmatel_spec *spec = codec->spec;
if (action == HDA_FIXUP_ACT_PRE_PROBE) {
spec->mic_mute_led_gpio = 0x08;
codec->bus->power_keep_link_on = 1;
}
}
static void stac92hd83xxx_fixup_hp_led_gpio10(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
struct sigmatel_spec *spec = codec->spec;
if (action == HDA_FIXUP_ACT_PRE_PROBE) {
spec->gpio_led = 0x10;
spec->default_polarity = 0;
}
}
static void stac92hd83xxx_fixup_headset_jack(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
struct sigmatel_spec *spec = codec->spec;
if (action == HDA_FIXUP_ACT_PRE_PROBE)
spec->headset_jack = 1;
}
static int stac_hp_bass_gpio_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct sigmatel_spec *spec = codec->spec;
ucontrol->value.integer.value[0] = !!(spec->gpio_data & 0x20);
return 0;
}
static int stac_hp_bass_gpio_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct sigmatel_spec *spec = codec->spec;
unsigned int gpio_data;
gpio_data = (spec->gpio_data & ~0x20) |
(ucontrol->value.integer.value[0] ? 0x20 : 0);
if (gpio_data == spec->gpio_data)
return 0;
spec->gpio_data = gpio_data;
stac_gpio_set(codec, spec->gpio_mask, spec->gpio_dir, spec->gpio_data);
return 1;
}
static int stac_add_hp_bass_switch(struct hda_codec *codec)
{
struct sigmatel_spec *spec = codec->spec;
if (!snd_hda_gen_add_kctl(&spec->gen, "Bass Speaker Playback Switch",
&stac_hp_bass_sw_ctrl))
return -ENOMEM;
spec->gpio_mask |= 0x20;
spec->gpio_dir |= 0x20;
spec->gpio_data |= 0x20;
return 0;
}
static void stac92hd71bxx_fixup_ref(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
struct sigmatel_spec *spec = codec->spec;
if (action != HDA_FIXUP_ACT_PRE_PROBE)
return;
snd_hda_apply_pincfgs(codec, ref92hd71bxx_pin_configs);
spec->gpio_mask = spec->gpio_dir = spec->gpio_data = 0;
}
static void stac92hd71bxx_fixup_hp_m4(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
struct sigmatel_spec *spec = codec->spec;
struct hda_jack_tbl *jack;
if (action != HDA_FIXUP_ACT_PRE_PROBE)
return;
snd_hda_codec_write_cache(codec, codec->afg, 0,
AC_VERB_SET_GPIO_UNSOLICITED_RSP_MASK, 0x02);
snd_hda_jack_detect_enable_callback(codec, codec->afg,
STAC_VREF_EVENT,
stac_vref_event);
jack = snd_hda_jack_tbl_get(codec, codec->afg);
if (jack)
jack->private_data = 0x02;
spec->gpio_mask |= 0x02;
snd_hda_codec_set_pincfg(codec, 0x0e, 0x01813040);
}
static void stac92hd71bxx_fixup_hp_dv4(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
struct sigmatel_spec *spec = codec->spec;
if (action != HDA_FIXUP_ACT_PRE_PROBE)
return;
spec->gpio_led = 0x01;
}
static void stac92hd71bxx_fixup_hp_dv5(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
unsigned int cap;
switch (action) {
case HDA_FIXUP_ACT_PRE_PROBE:
snd_hda_codec_set_pincfg(codec, 0x0d, 0x90170010);
break;
case HDA_FIXUP_ACT_PROBE:
cap = snd_hda_param_read(codec, 0x1, AC_PAR_GPIO_CAP);
cap &= AC_GPIO_IO_COUNT;
if (cap >= 6)
stac_add_hp_bass_switch(codec);
break;
}
}
static void stac92hd71bxx_fixup_hp_hdx(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
struct sigmatel_spec *spec = codec->spec;
if (action != HDA_FIXUP_ACT_PRE_PROBE)
return;
spec->gpio_led = 0x08;
}
static void stac92hd71bxx_fixup_hp(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
struct sigmatel_spec *spec = codec->spec;
if (action != HDA_FIXUP_ACT_PRE_PROBE)
return;
if (hp_blike_system(codec->subsystem_id)) {
unsigned int pin_cfg = snd_hda_codec_get_pincfg(codec, 0x0f);
if (get_defcfg_device(pin_cfg) == AC_JACK_LINE_OUT ||
get_defcfg_device(pin_cfg) == AC_JACK_SPEAKER ||
get_defcfg_device(pin_cfg) == AC_JACK_HP_OUT) {
pin_cfg = (pin_cfg & (~AC_DEFCFG_DEVICE))
| (AC_JACK_HP_OUT <<
AC_DEFCFG_DEVICE_SHIFT);
pin_cfg = (pin_cfg & (~(AC_DEFCFG_DEF_ASSOC
| AC_DEFCFG_SEQUENCE)))
| 0x1f;
snd_hda_codec_set_pincfg(codec, 0x0f, pin_cfg);
}
}
if (find_mute_led_cfg(codec, 1))
snd_printd("mute LED gpio %d polarity %d\n",
spec->gpio_led,
spec->gpio_led_polarity);
}
static void stac922x_fixup_intel_mac_auto(struct hda_codec *codec,
const struct hda_fixup *fix,
int action)
{
if (action != HDA_FIXUP_ACT_PRE_PROBE)
return;
snd_hda_pick_fixup(codec, NULL, stac922x_intel_mac_fixup_tbl,
stac922x_fixups);
if (codec->fixup_id != STAC_INTEL_MAC_AUTO)
snd_hda_apply_fixup(codec, action);
}
static void stac922x_fixup_intel_mac_gpio(struct hda_codec *codec,
const struct hda_fixup *fix,
int action)
{
struct sigmatel_spec *spec = codec->spec;
if (action == HDA_FIXUP_ACT_PRE_PROBE) {
spec->gpio_mask = spec->gpio_dir = 0x03;
spec->gpio_data = 0x03;
}
}
static void stac927x_fixup_ref_no_jd(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
if (action == HDA_FIXUP_ACT_PRE_PROBE)
codec->no_jack_detect = 1;
}
static void stac927x_fixup_ref(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
struct sigmatel_spec *spec = codec->spec;
if (action == HDA_FIXUP_ACT_PRE_PROBE) {
snd_hda_apply_pincfgs(codec, ref927x_pin_configs);
spec->eapd_mask = spec->gpio_mask = 0;
spec->gpio_dir = spec->gpio_data = 0;
}
}
static void stac927x_fixup_dell_dmic(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
struct sigmatel_spec *spec = codec->spec;
if (action != HDA_FIXUP_ACT_PRE_PROBE)
return;
if (codec->subsystem_id != 0x1028022f) {
spec->eapd_mask = spec->gpio_mask = 0x04;
spec->gpio_dir = spec->gpio_data = 0x04;
}
snd_hda_add_verbs(codec, dell_3st_core_init);
spec->volknob_init = 1;
}
static void stac927x_fixup_volknob(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
struct sigmatel_spec *spec = codec->spec;
if (action == HDA_FIXUP_ACT_PRE_PROBE) {
snd_hda_add_verbs(codec, stac927x_volknob_core_init);
spec->volknob_init = 1;
}
}
static void stac9205_fixup_ref(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
struct sigmatel_spec *spec = codec->spec;
if (action == HDA_FIXUP_ACT_PRE_PROBE) {
snd_hda_apply_pincfgs(codec, ref9205_pin_configs);
spec->eapd_mask = spec->gpio_mask = spec->gpio_dir = 0;
}
}
static void stac9205_fixup_dell_m43(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
struct sigmatel_spec *spec = codec->spec;
struct hda_jack_tbl *jack;
if (action == HDA_FIXUP_ACT_PRE_PROBE) {
snd_hda_apply_pincfgs(codec, dell_9205_m43_pin_configs);
snd_hda_codec_write_cache(codec, codec->afg, 0,
AC_VERB_SET_GPIO_UNSOLICITED_RSP_MASK, 0x10);
snd_hda_jack_detect_enable_callback(codec, codec->afg,
STAC_VREF_EVENT,
stac_vref_event);
jack = snd_hda_jack_tbl_get(codec, codec->afg);
if (jack)
jack->private_data = 0x01;
spec->gpio_dir = 0x0b;
spec->eapd_mask = 0x01;
spec->gpio_mask = 0x1b;
spec->gpio_mute = 0x10;
spec->gpio_data = 0x01;
}
}
static void stac9205_fixup_eapd(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
struct sigmatel_spec *spec = codec->spec;
if (action == HDA_FIXUP_ACT_PRE_PROBE)
spec->eapd_switch = 0;
}
static int stac_parse_auto_config(struct hda_codec *codec)
{
struct sigmatel_spec *spec = codec->spec;
int err;
int flags = 0;
if (spec->headset_jack)
flags |= HDA_PINCFG_HEADSET_MIC;
err = snd_hda_parse_pin_defcfg(codec, &spec->gen.autocfg, NULL, flags);
if (err < 0)
return err;
spec->gen.pcm_playback_hook = stac_playback_pcm_hook;
spec->gen.pcm_capture_hook = stac_capture_pcm_hook;
spec->gen.automute_hook = stac_update_outputs;
spec->gen.hp_automute_hook = stac_hp_automute;
spec->gen.line_automute_hook = stac_line_automute;
spec->gen.mic_autoswitch_hook = stac_mic_autoswitch;
err = snd_hda_gen_parse_auto_config(codec, &spec->gen.autocfg);
if (err < 0)
return err;
spec->gen.vmaster_tlv[3] |= TLV_DB_SCALE_MUTE;
if (spec->anabeep_nid > 0) {
err = stac_auto_create_beep_ctls(codec,
spec->anabeep_nid);
if (err < 0)
return err;
}
#ifdef CONFIG_SND_HDA_INPUT_BEEP
if (spec->gen.beep_nid) {
hda_nid_t nid = spec->gen.beep_nid;
unsigned int caps;
err = stac_auto_create_beep_ctls(codec, nid);
if (err < 0)
return err;
if (codec->beep) {
codec->beep->linear_tone = spec->linear_tone_beep;
caps = query_amp_caps(codec, nid, HDA_OUTPUT);
if (!(caps & AC_AMPCAP_MUTE)) {
err = stac_beep_switch_ctl(codec);
if (err < 0)
return err;
}
}
}
#endif
if (spec->gpio_led)
spec->gen.vmaster_mute.hook = stac_vmaster_hook;
if (spec->aloopback_ctl &&
snd_hda_get_bool_hint(codec, "loopback") == 1) {
if (!snd_hda_gen_add_kctl(&spec->gen, NULL, spec->aloopback_ctl))
return -ENOMEM;
}
if (spec->have_spdif_mux) {
err = stac_create_spdif_mux_ctls(codec);
if (err < 0)
return err;
}
stac_init_power_map(codec);
return 0;
}
static int stac_init(struct hda_codec *codec)
{
struct sigmatel_spec *spec = codec->spec;
int i;
stac_store_hints(codec);
if (!spec->eapd_switch)
spec->gpio_data |= spec->eapd_mask;
stac_gpio_set(codec, spec->gpio_mask, spec->gpio_dir, spec->gpio_data);
snd_hda_gen_init(codec);
if (spec->num_pwrs)
snd_hda_codec_write(codec, codec->afg, 0,
AC_VERB_IDT_SET_POWER_MAP,
spec->power_map_bits);
if (spec->powerdown_adcs) {
for (i = 0; i < spec->gen.num_all_adcs; i++) {
if (spec->active_adcs & (1 << i))
continue;
snd_hda_codec_write(codec, spec->gen.all_adcs[i], 0,
AC_VERB_SET_POWER_STATE,
AC_PWRST_D3);
}
}
return 0;
}
static void stac_shutup(struct hda_codec *codec)
{
struct sigmatel_spec *spec = codec->spec;
snd_hda_shutup_pins(codec);
if (spec->eapd_mask)
stac_gpio_set(codec, spec->gpio_mask,
spec->gpio_dir, spec->gpio_data &
~spec->eapd_mask);
}
static void stac92hd_proc_hook(struct snd_info_buffer *buffer,
struct hda_codec *codec, hda_nid_t nid)
{
if (nid == codec->afg)
snd_iprintf(buffer, "Power-Map: 0x%02x\n",
snd_hda_codec_read(codec, nid, 0,
AC_VERB_IDT_GET_POWER_MAP, 0));
}
static void analog_loop_proc_hook(struct snd_info_buffer *buffer,
struct hda_codec *codec,
unsigned int verb)
{
snd_iprintf(buffer, "Analog Loopback: 0x%02x\n",
snd_hda_codec_read(codec, codec->afg, 0, verb, 0));
}
static void stac92hd7x_proc_hook(struct snd_info_buffer *buffer,
struct hda_codec *codec, hda_nid_t nid)
{
stac92hd_proc_hook(buffer, codec, nid);
if (nid == codec->afg)
analog_loop_proc_hook(buffer, codec, 0xfa0);
}
static void stac9205_proc_hook(struct snd_info_buffer *buffer,
struct hda_codec *codec, hda_nid_t nid)
{
if (nid == codec->afg)
analog_loop_proc_hook(buffer, codec, 0xfe0);
}
static void stac927x_proc_hook(struct snd_info_buffer *buffer,
struct hda_codec *codec, hda_nid_t nid)
{
if (nid == codec->afg)
analog_loop_proc_hook(buffer, codec, 0xfeb);
}
static int stac_suspend(struct hda_codec *codec)
{
stac_shutup(codec);
return 0;
}
static int alloc_stac_spec(struct hda_codec *codec)
{
struct sigmatel_spec *spec;
spec = kzalloc(sizeof(*spec), GFP_KERNEL);
if (!spec)
return -ENOMEM;
snd_hda_gen_spec_init(&spec->gen);
codec->spec = spec;
codec->no_trigger_sense = 1;
return 0;
}
static int patch_stac9200(struct hda_codec *codec)
{
struct sigmatel_spec *spec;
int err;
err = alloc_stac_spec(codec);
if (err < 0)
return err;
spec = codec->spec;
spec->linear_tone_beep = 1;
spec->gen.own_eapd_ctl = 1;
codec->patch_ops = stac_patch_ops;
codec->power_filter = snd_hda_codec_eapd_power_filter;
snd_hda_add_verbs(codec, stac9200_eapd_init);
snd_hda_pick_fixup(codec, stac9200_models, stac9200_fixup_tbl,
stac9200_fixups);
snd_hda_apply_fixup(codec, HDA_FIXUP_ACT_PRE_PROBE);
err = stac_parse_auto_config(codec);
if (err < 0) {
stac_free(codec);
return err;
}
snd_hda_apply_fixup(codec, HDA_FIXUP_ACT_PROBE);
return 0;
}
static int patch_stac925x(struct hda_codec *codec)
{
struct sigmatel_spec *spec;
int err;
err = alloc_stac_spec(codec);
if (err < 0)
return err;
spec = codec->spec;
spec->linear_tone_beep = 1;
spec->gen.own_eapd_ctl = 1;
codec->patch_ops = stac_patch_ops;
snd_hda_add_verbs(codec, stac925x_core_init);
snd_hda_pick_fixup(codec, stac925x_models, stac925x_fixup_tbl,
stac925x_fixups);
snd_hda_apply_fixup(codec, HDA_FIXUP_ACT_PRE_PROBE);
err = stac_parse_auto_config(codec);
if (err < 0) {
stac_free(codec);
return err;
}
snd_hda_apply_fixup(codec, HDA_FIXUP_ACT_PROBE);
return 0;
}
static int patch_stac92hd73xx(struct hda_codec *codec)
{
struct sigmatel_spec *spec;
int err;
int num_dacs;
err = alloc_stac_spec(codec);
if (err < 0)
return err;
spec = codec->spec;
spec->linear_tone_beep = 0;
spec->gen.mixer_nid = 0x1d;
spec->have_spdif_mux = 1;
num_dacs = snd_hda_get_num_conns(codec, 0x0a) - 1;
if (num_dacs < 3 || num_dacs > 5) {
printk(KERN_WARNING "hda_codec: Could not determine "
"number of channels defaulting to DAC count\n");
num_dacs = 5;
}
switch (num_dacs) {
case 0x3:
spec->aloopback_ctl = &stac92hd73xx_6ch_loopback;
break;
case 0x4:
spec->aloopback_ctl = &stac92hd73xx_8ch_loopback;
break;
case 0x5:
spec->aloopback_ctl = &stac92hd73xx_10ch_loopback;
break;
}
spec->aloopback_mask = 0x01;
spec->aloopback_shift = 8;
spec->gen.beep_nid = 0x1c;
spec->eapd_mask = spec->gpio_mask = spec->gpio_dir = 0x1;
spec->gpio_data = 0x01;
spec->eapd_switch = 1;
spec->num_pwrs = ARRAY_SIZE(stac92hd73xx_pwr_nids);
spec->pwr_nids = stac92hd73xx_pwr_nids;
spec->gen.own_eapd_ctl = 1;
spec->gen.power_down_unused = 1;
codec->patch_ops = stac_patch_ops;
snd_hda_pick_fixup(codec, stac92hd73xx_models, stac92hd73xx_fixup_tbl,
stac92hd73xx_fixups);
snd_hda_apply_fixup(codec, HDA_FIXUP_ACT_PRE_PROBE);
if (!spec->volknob_init)
snd_hda_add_verbs(codec, stac92hd73xx_core_init);
err = stac_parse_auto_config(codec);
if (err < 0) {
stac_free(codec);
return err;
}
if (spec->eapd_switch && !has_builtin_speaker(codec))
spec->eapd_switch = 0;
codec->proc_widget_hook = stac92hd7x_proc_hook;
snd_hda_apply_fixup(codec, HDA_FIXUP_ACT_PROBE);
return 0;
}
static void stac_setup_gpio(struct hda_codec *codec)
{
struct sigmatel_spec *spec = codec->spec;
spec->gpio_mask |= spec->eapd_mask;
if (spec->gpio_led) {
if (!spec->vref_mute_led_nid) {
spec->gpio_mask |= spec->gpio_led;
spec->gpio_dir |= spec->gpio_led;
spec->gpio_data |= spec->gpio_led;
} else {
codec->power_filter = stac_vref_led_power_filter;
}
}
if (spec->mic_mute_led_gpio) {
spec->gpio_mask |= spec->mic_mute_led_gpio;
spec->gpio_dir |= spec->mic_mute_led_gpio;
spec->mic_enabled = 0;
spec->gpio_data |= spec->mic_mute_led_gpio;
spec->gen.cap_sync_hook = stac_capture_led_hook;
}
}
static int patch_stac92hd83xxx(struct hda_codec *codec)
{
struct sigmatel_spec *spec;
int err;
err = alloc_stac_spec(codec);
if (err < 0)
return err;
codec->epss = 0;
spec = codec->spec;
spec->linear_tone_beep = 0;
spec->gen.own_eapd_ctl = 1;
spec->gen.power_down_unused = 1;
spec->gen.mixer_nid = 0x1b;
spec->gen.beep_nid = 0x21;
spec->pwr_nids = stac92hd83xxx_pwr_nids;
spec->num_pwrs = ARRAY_SIZE(stac92hd83xxx_pwr_nids);
spec->default_polarity = -1;
codec->patch_ops = stac_patch_ops;
snd_hda_add_verbs(codec, stac92hd83xxx_core_init);
snd_hda_pick_fixup(codec, stac92hd83xxx_models, stac92hd83xxx_fixup_tbl,
stac92hd83xxx_fixups);
snd_hda_apply_fixup(codec, HDA_FIXUP_ACT_PRE_PROBE);
stac_setup_gpio(codec);
err = stac_parse_auto_config(codec);
if (err < 0) {
stac_free(codec);
return err;
}
codec->proc_widget_hook = stac92hd_proc_hook;
snd_hda_apply_fixup(codec, HDA_FIXUP_ACT_PROBE);
return 0;
}
static int patch_stac92hd95(struct hda_codec *codec)
{
struct sigmatel_spec *spec;
int err;
err = alloc_stac_spec(codec);
if (err < 0)
return err;
codec->epss = 0;
spec = codec->spec;
spec->linear_tone_beep = 0;
spec->gen.own_eapd_ctl = 1;
spec->gen.power_down_unused = 1;
spec->gen.beep_nid = 0x19;
spec->pwr_nids = stac92hd95_pwr_nids;
spec->num_pwrs = ARRAY_SIZE(stac92hd95_pwr_nids);
spec->default_polarity = -1;
codec->patch_ops = stac_patch_ops;
err = stac_parse_auto_config(codec);
if (err < 0) {
stac_free(codec);
return err;
}
codec->proc_widget_hook = stac92hd_proc_hook;
return 0;
}
static int patch_stac92hd71bxx(struct hda_codec *codec)
{
struct sigmatel_spec *spec;
const struct hda_verb *unmute_init = stac92hd71bxx_unmute_core_init;
int err;
err = alloc_stac_spec(codec);
if (err < 0)
return err;
spec = codec->spec;
spec->linear_tone_beep = 0;
spec->gen.own_eapd_ctl = 1;
spec->gen.power_down_unused = 1;
spec->gen.mixer_nid = 0x17;
spec->have_spdif_mux = 1;
codec->patch_ops = stac_patch_ops;
spec->gpio_mask = 0x01;
spec->gpio_dir = 0x01;
spec->gpio_data = 0x01;
switch (codec->vendor_id) {
case 0x111d76b6:
case 0x111d76b7:
unmute_init++;
break;
case 0x111d7608:
if ((codec->revision_id & 0xf) == 0 ||
(codec->revision_id & 0xf) == 1)
spec->stream_delay = 40;
unmute_init++;
snd_hda_codec_set_pincfg(codec, 0x0f, 0x40f000f0);
snd_hda_codec_set_pincfg(codec, 0x19, 0x40f000f3);
break;
case 0x111d7603:
if ((codec->revision_id & 0xf) == 1)
spec->stream_delay = 40;
break;
}
if (get_wcaps_type(get_wcaps(codec, 0x28)) == AC_WID_VOL_KNB)
snd_hda_add_verbs(codec, stac92hd71bxx_core_init);
if (get_wcaps(codec, 0xa) & AC_WCAP_IN_AMP)
snd_hda_sequence_write_cache(codec, unmute_init);
spec->aloopback_ctl = &stac92hd71bxx_loopback;
spec->aloopback_mask = 0x50;
spec->aloopback_shift = 0;
spec->powerdown_adcs = 1;
spec->gen.beep_nid = 0x26;
spec->num_pwrs = ARRAY_SIZE(stac92hd71bxx_pwr_nids);
spec->pwr_nids = stac92hd71bxx_pwr_nids;
snd_hda_pick_fixup(codec, stac92hd71bxx_models, stac92hd71bxx_fixup_tbl,
stac92hd71bxx_fixups);
snd_hda_apply_fixup(codec, HDA_FIXUP_ACT_PRE_PROBE);
stac_setup_gpio(codec);
err = stac_parse_auto_config(codec);
if (err < 0) {
stac_free(codec);
return err;
}
codec->proc_widget_hook = stac92hd7x_proc_hook;
snd_hda_apply_fixup(codec, HDA_FIXUP_ACT_PROBE);
return 0;
}
static int patch_stac922x(struct hda_codec *codec)
{
struct sigmatel_spec *spec;
int err;
err = alloc_stac_spec(codec);
if (err < 0)
return err;
spec = codec->spec;
spec->linear_tone_beep = 1;
spec->gen.own_eapd_ctl = 1;
codec->patch_ops = stac_patch_ops;
snd_hda_add_verbs(codec, stac922x_core_init);
snd_hda_override_amp_caps(codec, 0x12, HDA_OUTPUT,
(0 << AC_AMPCAP_OFFSET_SHIFT) |
(2 << AC_AMPCAP_NUM_STEPS_SHIFT) |
(0x27 << AC_AMPCAP_STEP_SIZE_SHIFT) |
(0 << AC_AMPCAP_MUTE_SHIFT));
snd_hda_pick_fixup(codec, stac922x_models, stac922x_fixup_tbl,
stac922x_fixups);
snd_hda_apply_fixup(codec, HDA_FIXUP_ACT_PRE_PROBE);
err = stac_parse_auto_config(codec);
if (err < 0) {
stac_free(codec);
return err;
}
snd_hda_apply_fixup(codec, HDA_FIXUP_ACT_PROBE);
return 0;
}
static int patch_stac927x(struct hda_codec *codec)
{
struct sigmatel_spec *spec;
int err;
err = alloc_stac_spec(codec);
if (err < 0)
return err;
spec = codec->spec;
spec->linear_tone_beep = 1;
spec->gen.own_eapd_ctl = 1;
spec->have_spdif_mux = 1;
spec->spdif_labels = stac927x_spdif_labels;
spec->gen.beep_nid = 0x23;
spec->eapd_mask = spec->gpio_mask = 0x01;
spec->gpio_dir = spec->gpio_data = 0x01;
spec->aloopback_ctl = &stac927x_loopback;
spec->aloopback_mask = 0x40;
spec->aloopback_shift = 0;
spec->eapd_switch = 1;
codec->patch_ops = stac_patch_ops;
snd_hda_pick_fixup(codec, stac927x_models, stac927x_fixup_tbl,
stac927x_fixups);
snd_hda_apply_fixup(codec, HDA_FIXUP_ACT_PRE_PROBE);
if (!spec->volknob_init)
snd_hda_add_verbs(codec, stac927x_core_init);
err = stac_parse_auto_config(codec);
if (err < 0) {
stac_free(codec);
return err;
}
codec->proc_widget_hook = stac927x_proc_hook;
codec->bus->needs_damn_long_delay = 1;
snd_hda_apply_fixup(codec, HDA_FIXUP_ACT_PROBE);
return 0;
}
static int patch_stac9205(struct hda_codec *codec)
{
struct sigmatel_spec *spec;
int err;
err = alloc_stac_spec(codec);
if (err < 0)
return err;
spec = codec->spec;
spec->linear_tone_beep = 1;
spec->gen.own_eapd_ctl = 1;
spec->have_spdif_mux = 1;
spec->gen.beep_nid = 0x23;
snd_hda_add_verbs(codec, stac9205_core_init);
spec->aloopback_ctl = &stac9205_loopback;
spec->aloopback_mask = 0x40;
spec->aloopback_shift = 0;
spec->eapd_mask = spec->gpio_mask = spec->gpio_dir = 0x1;
spec->gpio_data = 0x01;
spec->eapd_switch = 1;
codec->patch_ops = stac_patch_ops;
snd_hda_pick_fixup(codec, stac9205_models, stac9205_fixup_tbl,
stac9205_fixups);
snd_hda_apply_fixup(codec, HDA_FIXUP_ACT_PRE_PROBE);
err = stac_parse_auto_config(codec);
if (err < 0) {
stac_free(codec);
return err;
}
codec->proc_widget_hook = stac9205_proc_hook;
snd_hda_apply_fixup(codec, HDA_FIXUP_ACT_PROBE);
return 0;
}
static int patch_stac9872(struct hda_codec *codec)
{
struct sigmatel_spec *spec;
int err;
err = alloc_stac_spec(codec);
if (err < 0)
return err;
spec = codec->spec;
spec->linear_tone_beep = 1;
spec->gen.own_eapd_ctl = 1;
codec->patch_ops = stac_patch_ops;
snd_hda_add_verbs(codec, stac9872_core_init);
snd_hda_pick_fixup(codec, stac9872_models, stac9872_fixup_tbl,
stac9872_fixups);
snd_hda_apply_fixup(codec, HDA_FIXUP_ACT_PRE_PROBE);
err = stac_parse_auto_config(codec);
if (err < 0) {
stac_free(codec);
return -EINVAL;
}
snd_hda_apply_fixup(codec, HDA_FIXUP_ACT_PROBE);
return 0;
}
static int __init patch_sigmatel_init(void)
{
return snd_hda_add_codec_preset(&sigmatel_list);
}
static void __exit patch_sigmatel_exit(void)
{
snd_hda_delete_codec_preset(&sigmatel_list);
}
