static int pin_nid_to_pin_index(struct hda_codec *codec, hda_nid_t pin_nid)
{
struct hdmi_spec *spec = codec->spec;
int pin_idx;
for (pin_idx = 0; pin_idx < spec->num_pins; pin_idx++)
if (get_pin(spec, pin_idx)->pin_nid == pin_nid)
return pin_idx;
codec_warn(codec, "HDMI: pin nid %d not registered\n", pin_nid);
return -EINVAL;
}
static int hinfo_to_pin_index(struct hda_codec *codec,
struct hda_pcm_stream *hinfo)
{
struct hdmi_spec *spec = codec->spec;
int pin_idx;
for (pin_idx = 0; pin_idx < spec->num_pins; pin_idx++)
if (get_pcm_rec(spec, pin_idx)->stream == hinfo)
return pin_idx;
codec_warn(codec, "HDMI: hinfo %p not registered\n", hinfo);
return -EINVAL;
}
static int cvt_nid_to_cvt_index(struct hda_codec *codec, hda_nid_t cvt_nid)
{
struct hdmi_spec *spec = codec->spec;
int cvt_idx;
for (cvt_idx = 0; cvt_idx < spec->num_cvts; cvt_idx++)
if (get_cvt(spec, cvt_idx)->cvt_nid == cvt_nid)
return cvt_idx;
codec_warn(codec, "HDMI: cvt nid %d not registered\n", cvt_nid);
return -EINVAL;
}
static int hdmi_eld_ctl_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct hdmi_spec *spec = codec->spec;
struct hdmi_spec_per_pin *per_pin;
struct hdmi_eld *eld;
int pin_idx;
uinfo->type = SNDRV_CTL_ELEM_TYPE_BYTES;
pin_idx = kcontrol->private_value;
per_pin = get_pin(spec, pin_idx);
eld = &per_pin->sink_eld;
mutex_lock(&per_pin->lock);
uinfo->count = eld->eld_valid ? eld->eld_size : 0;
mutex_unlock(&per_pin->lock);
return 0;
}
static int hdmi_eld_ctl_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct hdmi_spec *spec = codec->spec;
struct hdmi_spec_per_pin *per_pin;
struct hdmi_eld *eld;
int pin_idx;
pin_idx = kcontrol->private_value;
per_pin = get_pin(spec, pin_idx);
eld = &per_pin->sink_eld;
mutex_lock(&per_pin->lock);
if (eld->eld_size > ARRAY_SIZE(ucontrol->value.bytes.data)) {
mutex_unlock(&per_pin->lock);
snd_BUG();
return -EINVAL;
}
memset(ucontrol->value.bytes.data, 0,
ARRAY_SIZE(ucontrol->value.bytes.data));
if (eld->eld_valid)
memcpy(ucontrol->value.bytes.data, eld->eld_buffer,
eld->eld_size);
mutex_unlock(&per_pin->lock);
return 0;
}
static int hdmi_create_eld_ctl(struct hda_codec *codec, int pin_idx,
int device)
{
struct snd_kcontrol *kctl;
struct hdmi_spec *spec = codec->spec;
int err;
kctl = snd_ctl_new1(&eld_bytes_ctl, codec);
if (!kctl)
return -ENOMEM;
kctl->private_value = pin_idx;
kctl->id.device = device;
err = snd_hda_ctl_add(codec, get_pin(spec, pin_idx)->pin_nid, kctl);
if (err < 0)
return err;
get_pin(spec, pin_idx)->eld_ctl = kctl;
return 0;
}
static void hdmi_get_dip_index(struct hda_codec *codec, hda_nid_t pin_nid,
int *packet_index, int *byte_index)
{
int val;
val = snd_hda_codec_read(codec, pin_nid, 0,
AC_VERB_GET_HDMI_DIP_INDEX, 0);
*packet_index = val >> 5;
*byte_index = val & 0x1f;
}
static void hdmi_set_dip_index(struct hda_codec *codec, hda_nid_t pin_nid,
int packet_index, int byte_index)
{
int val;
val = (packet_index << 5) | (byte_index & 0x1f);
snd_hda_codec_write(codec, pin_nid, 0, AC_VERB_SET_HDMI_DIP_INDEX, val);
}
static void hdmi_write_dip_byte(struct hda_codec *codec, hda_nid_t pin_nid,
unsigned char val)
{
snd_hda_codec_write(codec, pin_nid, 0, AC_VERB_SET_HDMI_DIP_DATA, val);
}
static void hdmi_init_pin(struct hda_codec *codec, hda_nid_t pin_nid)
{
struct hdmi_spec *spec = codec->spec;
int pin_out;
if (get_wcaps(codec, pin_nid) & AC_WCAP_OUT_AMP)
snd_hda_codec_write(codec, pin_nid, 0,
AC_VERB_SET_AMP_GAIN_MUTE, AMP_OUT_UNMUTE);
if (spec->dyn_pin_out)
pin_out = 0;
else
pin_out = PIN_OUT;
snd_hda_codec_write(codec, pin_nid, 0,
AC_VERB_SET_PIN_WIDGET_CONTROL, pin_out);
}
static int hdmi_get_channel_count(struct hda_codec *codec, hda_nid_t cvt_nid)
{
return 1 + snd_hda_codec_read(codec, cvt_nid, 0,
AC_VERB_GET_CVT_CHAN_COUNT, 0);
}
static void hdmi_set_channel_count(struct hda_codec *codec,
hda_nid_t cvt_nid, int chs)
{
if (chs != hdmi_get_channel_count(codec, cvt_nid))
snd_hda_codec_write(codec, cvt_nid, 0,
AC_VERB_SET_CVT_CHAN_COUNT, chs - 1);
}
static void print_eld_info(struct snd_info_entry *entry,
struct snd_info_buffer *buffer)
{
struct hdmi_spec_per_pin *per_pin = entry->private_data;
mutex_lock(&per_pin->lock);
snd_hdmi_print_eld_info(&per_pin->sink_eld, buffer);
mutex_unlock(&per_pin->lock);
}
static void write_eld_info(struct snd_info_entry *entry,
struct snd_info_buffer *buffer)
{
struct hdmi_spec_per_pin *per_pin = entry->private_data;
mutex_lock(&per_pin->lock);
snd_hdmi_write_eld_info(&per_pin->sink_eld, buffer);
mutex_unlock(&per_pin->lock);
}
static int eld_proc_new(struct hdmi_spec_per_pin *per_pin, int index)
{
char name[32];
struct hda_codec *codec = per_pin->codec;
struct snd_info_entry *entry;
int err;
snprintf(name, sizeof(name), "eld#%d.%d", codec->addr, index);
err = snd_card_proc_new(codec->bus->card, name, &entry);
if (err < 0)
return err;
snd_info_set_text_ops(entry, per_pin, print_eld_info);
entry->c.text.write = write_eld_info;
entry->mode |= S_IWUSR;
per_pin->proc_entry = entry;
return 0;
}
static void eld_proc_free(struct hdmi_spec_per_pin *per_pin)
{
if (!per_pin->codec->bus->shutdown && per_pin->proc_entry) {
snd_device_free(per_pin->codec->bus->card, per_pin->proc_entry);
per_pin->proc_entry = NULL;
}
}
static inline int eld_proc_new(struct hdmi_spec_per_pin *per_pin,
int index)
{
return 0;
}
static inline void eld_proc_free(struct hdmi_spec_per_pin *per_pin)
{
}
static void init_channel_allocations(void)
{
int i, j;
struct cea_channel_speaker_allocation *p;
for (i = 0; i < ARRAY_SIZE(channel_allocations); i++) {
p = channel_allocations + i;
p->channels = 0;
p->spk_mask = 0;
for (j = 0; j < ARRAY_SIZE(p->speakers); j++)
if (p->speakers[j]) {
p->channels++;
p->spk_mask |= p->speakers[j];
}
}
}
static int get_channel_allocation_order(int ca)
{
int i;
for (i = 0; i < ARRAY_SIZE(channel_allocations); i++) {
if (channel_allocations[i].ca_index == ca)
break;
}
return i;
}
static int hdmi_channel_allocation(struct hdmi_eld *eld, int channels)
{
int i;
int ca = 0;
int spk_mask = 0;
char buf[SND_PRINT_CHANNEL_ALLOCATION_ADVISED_BUFSIZE];
if (channels <= 2)
return 0;
for (i = 0; i < ARRAY_SIZE(eld_speaker_allocation_bits); i++) {
if (eld->info.spk_alloc & (1 << i))
spk_mask |= eld_speaker_allocation_bits[i];
}
for (i = 0; i < ARRAY_SIZE(channel_allocations); i++) {
if (channels == channel_allocations[i].channels &&
(spk_mask & channel_allocations[i].spk_mask) ==
channel_allocations[i].spk_mask) {
ca = channel_allocations[i].ca_index;
break;
}
}
if (!ca) {
for (i = 0; i < ARRAY_SIZE(channel_allocations); i++) {
if (channels == channel_allocations[i].channels) {
ca = channel_allocations[i].ca_index;
break;
}
}
}
snd_print_channel_allocation(eld->info.spk_alloc, buf, sizeof(buf));
snd_printdd("HDMI: select CA 0x%x for %d-channel allocation: %s\n",
ca, channels, buf);
return ca;
}
static void hdmi_debug_channel_mapping(struct hda_codec *codec,
hda_nid_t pin_nid)
{
#ifdef CONFIG_SND_DEBUG_VERBOSE
struct hdmi_spec *spec = codec->spec;
int i;
int channel;
for (i = 0; i < 8; i++) {
channel = spec->ops.pin_get_slot_channel(codec, pin_nid, i);
codec_dbg(codec, "HDMI: ASP channel %d => slot %d\n",
channel, i);
}
#endif
}
static void hdmi_std_setup_channel_mapping(struct hda_codec *codec,
hda_nid_t pin_nid,
bool non_pcm,
int ca)
{
struct hdmi_spec *spec = codec->spec;
struct cea_channel_speaker_allocation *ch_alloc;
int i;
int err;
int order;
int non_pcm_mapping[8];
order = get_channel_allocation_order(ca);
ch_alloc = &channel_allocations[order];
if (hdmi_channel_mapping[ca][1] == 0) {
int hdmi_slot = 0;
for (i = 0; i < ch_alloc->channels; i++) {
while (!ch_alloc->speakers[7 - hdmi_slot] && !WARN_ON(hdmi_slot >= 8))
hdmi_slot++;
hdmi_channel_mapping[ca][i] = (i << 4) | hdmi_slot++;
}
for (hdmi_slot = 0; hdmi_slot < 8; hdmi_slot++)
if (!ch_alloc->speakers[7 - hdmi_slot])
hdmi_channel_mapping[ca][i++] = (0xf << 4) | hdmi_slot;
}
if (non_pcm) {
for (i = 0; i < ch_alloc->channels; i++)
non_pcm_mapping[i] = (i << 4) | i;
for (; i < 8; i++)
non_pcm_mapping[i] = (0xf << 4) | i;
}
for (i = 0; i < 8; i++) {
int slotsetup = non_pcm ? non_pcm_mapping[i] : hdmi_channel_mapping[ca][i];
int hdmi_slot = slotsetup & 0x0f;
int channel = (slotsetup & 0xf0) >> 4;
err = spec->ops.pin_set_slot_channel(codec, pin_nid, hdmi_slot, channel);
if (err) {
codec_dbg(codec, "HDMI: channel mapping failed\n");
break;
}
}
}
static int to_spk_mask(unsigned char c)
{
struct channel_map_table *t = map_tables;
for (; t->map; t++) {
if (t->map == c)
return t->spk_mask;
}
return 0;
}
static int to_cea_slot(int ordered_ca, unsigned char pos)
{
int mask = to_spk_mask(pos);
int i;
if (mask) {
for (i = 0; i < 8; i++) {
if (channel_allocations[ordered_ca].speakers[7 - i] == mask)
return i;
}
}
return -1;
}
static int spk_to_chmap(int spk)
{
struct channel_map_table *t = map_tables;
for (; t->map; t++) {
if (t->spk_mask == spk)
return t->map;
}
return 0;
}
static int from_cea_slot(int ordered_ca, unsigned char slot)
{
int mask = channel_allocations[ordered_ca].speakers[7 - slot];
return spk_to_chmap(mask);
}
static int hdmi_manual_channel_allocation(int chs, unsigned char *map)
{
int i, spks = 0, spk_mask = 0;
for (i = 0; i < chs; i++) {
int mask = to_spk_mask(map[i]);
if (mask) {
spk_mask |= mask;
spks++;
}
}
for (i = 0; i < ARRAY_SIZE(channel_allocations); i++) {
if ((chs == channel_allocations[i].channels ||
spks == channel_allocations[i].channels) &&
(spk_mask & channel_allocations[i].spk_mask) ==
channel_allocations[i].spk_mask)
return channel_allocations[i].ca_index;
}
return -1;
}
static int hdmi_manual_setup_channel_mapping(struct hda_codec *codec,
hda_nid_t pin_nid,
int chs, unsigned char *map,
int ca)
{
struct hdmi_spec *spec = codec->spec;
int ordered_ca = get_channel_allocation_order(ca);
int alsa_pos, hdmi_slot;
int assignments[8] = {[0 ... 7] = 0xf};
for (alsa_pos = 0; alsa_pos < chs; alsa_pos++) {
hdmi_slot = to_cea_slot(ordered_ca, map[alsa_pos]);
if (hdmi_slot < 0)
continue;
assignments[hdmi_slot] = alsa_pos;
}
for (hdmi_slot = 0; hdmi_slot < 8; hdmi_slot++) {
int err;
err = spec->ops.pin_set_slot_channel(codec, pin_nid, hdmi_slot,
assignments[hdmi_slot]);
if (err)
return -EINVAL;
}
return 0;
}
static void hdmi_setup_fake_chmap(unsigned char *map, int ca)
{
int i;
int ordered_ca = get_channel_allocation_order(ca);
for (i = 0; i < 8; i++) {
if (i < channel_allocations[ordered_ca].channels)
map[i] = from_cea_slot(ordered_ca, hdmi_channel_mapping[ca][i] & 0x0f);
else
map[i] = 0;
}
}
static void hdmi_setup_channel_mapping(struct hda_codec *codec,
hda_nid_t pin_nid, bool non_pcm, int ca,
int channels, unsigned char *map,
bool chmap_set)
{
if (!non_pcm && chmap_set) {
hdmi_manual_setup_channel_mapping(codec, pin_nid,
channels, map, ca);
} else {
hdmi_std_setup_channel_mapping(codec, pin_nid, non_pcm, ca);
hdmi_setup_fake_chmap(map, ca);
}
hdmi_debug_channel_mapping(codec, pin_nid);
}
static int hdmi_pin_set_slot_channel(struct hda_codec *codec, hda_nid_t pin_nid,
int asp_slot, int channel)
{
return snd_hda_codec_write(codec, pin_nid, 0,
AC_VERB_SET_HDMI_CHAN_SLOT,
(channel << 4) | asp_slot);
}
static int hdmi_pin_get_slot_channel(struct hda_codec *codec, hda_nid_t pin_nid,
int asp_slot)
{
return (snd_hda_codec_read(codec, pin_nid, 0,
AC_VERB_GET_HDMI_CHAN_SLOT,
asp_slot) & 0xf0) >> 4;
}
static void hdmi_start_infoframe_trans(struct hda_codec *codec,
hda_nid_t pin_nid)
{
hdmi_set_dip_index(codec, pin_nid, 0x0, 0x0);
snd_hda_codec_write(codec, pin_nid, 0, AC_VERB_SET_HDMI_DIP_XMIT,
AC_DIPXMIT_BEST);
}
static void hdmi_stop_infoframe_trans(struct hda_codec *codec,
hda_nid_t pin_nid)
{
hdmi_set_dip_index(codec, pin_nid, 0x0, 0x0);
snd_hda_codec_write(codec, pin_nid, 0, AC_VERB_SET_HDMI_DIP_XMIT,
AC_DIPXMIT_DISABLE);
}
static void hdmi_debug_dip_size(struct hda_codec *codec, hda_nid_t pin_nid)
{
#ifdef CONFIG_SND_DEBUG_VERBOSE
int i;
int size;
size = snd_hdmi_get_eld_size(codec, pin_nid);
codec_dbg(codec, "HDMI: ELD buf size is %d\n", size);
for (i = 0; i < 8; i++) {
size = snd_hda_codec_read(codec, pin_nid, 0,
AC_VERB_GET_HDMI_DIP_SIZE, i);
codec_dbg(codec, "HDMI: DIP GP[%d] buf size is %d\n", i, size);
}
#endif
}
static void hdmi_clear_dip_buffers(struct hda_codec *codec, hda_nid_t pin_nid)
{
#ifdef BE_PARANOID
int i, j;
int size;
int pi, bi;
for (i = 0; i < 8; i++) {
size = snd_hda_codec_read(codec, pin_nid, 0,
AC_VERB_GET_HDMI_DIP_SIZE, i);
if (size == 0)
continue;
hdmi_set_dip_index(codec, pin_nid, i, 0x0);
for (j = 1; j < 1000; j++) {
hdmi_write_dip_byte(codec, pin_nid, 0x0);
hdmi_get_dip_index(codec, pin_nid, &pi, &bi);
if (pi != i)
codec_dbg(codec, "dip index %d: %d != %d\n",
bi, pi, i);
if (bi == 0)
break;
}
codec_dbg(codec,
"HDMI: DIP GP[%d] buf reported size=%d, written=%d\n",
i, size, j);
}
#endif
}
static void hdmi_checksum_audio_infoframe(struct hdmi_audio_infoframe *hdmi_ai)
{
u8 *bytes = (u8 *)hdmi_ai;
u8 sum = 0;
int i;
hdmi_ai->checksum = 0;
for (i = 0; i < sizeof(*hdmi_ai); i++)
sum += bytes[i];
hdmi_ai->checksum = -sum;
}
static void hdmi_fill_audio_infoframe(struct hda_codec *codec,
hda_nid_t pin_nid,
u8 *dip, int size)
{
int i;
hdmi_debug_dip_size(codec, pin_nid);
hdmi_clear_dip_buffers(codec, pin_nid);
hdmi_set_dip_index(codec, pin_nid, 0x0, 0x0);
for (i = 0; i < size; i++)
hdmi_write_dip_byte(codec, pin_nid, dip[i]);
}
static bool hdmi_infoframe_uptodate(struct hda_codec *codec, hda_nid_t pin_nid,
u8 *dip, int size)
{
u8 val;
int i;
if (snd_hda_codec_read(codec, pin_nid, 0, AC_VERB_GET_HDMI_DIP_XMIT, 0)
!= AC_DIPXMIT_BEST)
return false;
hdmi_set_dip_index(codec, pin_nid, 0x0, 0x0);
for (i = 0; i < size; i++) {
val = snd_hda_codec_read(codec, pin_nid, 0,
AC_VERB_GET_HDMI_DIP_DATA, 0);
if (val != dip[i])
return false;
}
return true;
}
static void hdmi_pin_setup_infoframe(struct hda_codec *codec,
hda_nid_t pin_nid,
int ca, int active_channels,
int conn_type)
{
union audio_infoframe ai;
memset(&ai, 0, sizeof(ai));
if (conn_type == 0) {
struct hdmi_audio_infoframe *hdmi_ai = &ai.hdmi;
hdmi_ai->type = 0x84;
hdmi_ai->ver = 0x01;
hdmi_ai->len = 0x0a;
hdmi_ai->CC02_CT47 = active_channels - 1;
hdmi_ai->CA = ca;
hdmi_checksum_audio_infoframe(hdmi_ai);
} else if (conn_type == 1) {
struct dp_audio_infoframe *dp_ai = &ai.dp;
dp_ai->type = 0x84;
dp_ai->len = 0x1b;
dp_ai->ver = 0x11 << 2;
dp_ai->CC02_CT47 = active_channels - 1;
dp_ai->CA = ca;
} else {
codec_dbg(codec, "HDMI: unknown connection type at pin %d\n",
pin_nid);
return;
}
if (!hdmi_infoframe_uptodate(codec, pin_nid, ai.bytes,
sizeof(ai))) {
codec_dbg(codec,
"hdmi_pin_setup_infoframe: pin=%d channels=%d ca=0x%02x\n",
pin_nid,
active_channels, ca);
hdmi_stop_infoframe_trans(codec, pin_nid);
hdmi_fill_audio_infoframe(codec, pin_nid,
ai.bytes, sizeof(ai));
hdmi_start_infoframe_trans(codec, pin_nid);
}
}
static void hdmi_setup_audio_infoframe(struct hda_codec *codec,
struct hdmi_spec_per_pin *per_pin,
bool non_pcm)
{
struct hdmi_spec *spec = codec->spec;
hda_nid_t pin_nid = per_pin->pin_nid;
int channels = per_pin->channels;
int active_channels;
struct hdmi_eld *eld;
int ca, ordered_ca;
if (!channels)
return;
if (is_haswell_plus(codec))
snd_hda_codec_write(codec, pin_nid, 0,
AC_VERB_SET_AMP_GAIN_MUTE,
AMP_OUT_UNMUTE);
eld = &per_pin->sink_eld;
if (!non_pcm && per_pin->chmap_set)
ca = hdmi_manual_channel_allocation(channels, per_pin->chmap);
else
ca = hdmi_channel_allocation(eld, channels);
if (ca < 0)
ca = 0;
ordered_ca = get_channel_allocation_order(ca);
active_channels = channel_allocations[ordered_ca].channels;
hdmi_set_channel_count(codec, per_pin->cvt_nid, active_channels);
hdmi_setup_channel_mapping(codec, pin_nid, non_pcm, ca,
channels, per_pin->chmap,
per_pin->chmap_set);
spec->ops.pin_setup_infoframe(codec, pin_nid, ca, active_channels,
eld->info.conn_type);
per_pin->non_pcm = non_pcm;
}
static void jack_callback(struct hda_codec *codec, struct hda_jack_tbl *jack)
{
struct hdmi_spec *spec = codec->spec;
int pin_idx = pin_nid_to_pin_index(codec, jack->nid);
if (pin_idx < 0)
return;
if (hdmi_present_sense(get_pin(spec, pin_idx), 1))
snd_hda_jack_report_sync(codec);
}
static void hdmi_intrinsic_event(struct hda_codec *codec, unsigned int res)
{
int tag = res >> AC_UNSOL_RES_TAG_SHIFT;
struct hda_jack_tbl *jack;
int dev_entry = (res & AC_UNSOL_RES_DE) >> AC_UNSOL_RES_DE_SHIFT;
jack = snd_hda_jack_tbl_get_from_tag(codec, tag);
if (!jack)
return;
jack->jack_dirty = 1;
codec_dbg(codec,
"HDMI hot plug event: Codec=%d Pin=%d Device=%d Inactive=%d Presence_Detect=%d ELD_Valid=%d\n",
codec->addr, jack->nid, dev_entry, !!(res & AC_UNSOL_RES_IA),
!!(res & AC_UNSOL_RES_PD), !!(res & AC_UNSOL_RES_ELDV));
jack_callback(codec, jack);
}
static void hdmi_non_intrinsic_event(struct hda_codec *codec, unsigned int res)
{
int tag = res >> AC_UNSOL_RES_TAG_SHIFT;
int subtag = (res & AC_UNSOL_RES_SUBTAG) >> AC_UNSOL_RES_SUBTAG_SHIFT;
int cp_state = !!(res & AC_UNSOL_RES_CP_STATE);
int cp_ready = !!(res & AC_UNSOL_RES_CP_READY);
codec_info(codec,
"HDMI CP event: CODEC=%d TAG=%d SUBTAG=0x%x CP_STATE=%d CP_READY=%d\n",
codec->addr,
tag,
subtag,
cp_state,
cp_ready);
if (cp_state)
;
if (cp_ready)
;
}
static void hdmi_unsol_event(struct hda_codec *codec, unsigned int res)
{
int tag = res >> AC_UNSOL_RES_TAG_SHIFT;
int subtag = (res & AC_UNSOL_RES_SUBTAG) >> AC_UNSOL_RES_SUBTAG_SHIFT;
if (!snd_hda_jack_tbl_get_from_tag(codec, tag)) {
codec_dbg(codec, "Unexpected HDMI event tag 0x%x\n", tag);
return;
}
if (subtag == 0)
hdmi_intrinsic_event(codec, res);
else
hdmi_non_intrinsic_event(codec, res);
}
static void haswell_verify_D0(struct hda_codec *codec,
hda_nid_t cvt_nid, hda_nid_t nid)
{
int pwr;
if (!snd_hda_check_power_state(codec, cvt_nid, AC_PWRST_D0))
snd_hda_codec_write(codec, cvt_nid, 0, AC_VERB_SET_POWER_STATE, AC_PWRST_D0);
if (!snd_hda_check_power_state(codec, nid, AC_PWRST_D0)) {
snd_hda_codec_write(codec, nid, 0, AC_VERB_SET_POWER_STATE,
AC_PWRST_D0);
msleep(40);
pwr = snd_hda_codec_read(codec, nid, 0, AC_VERB_GET_POWER_STATE, 0);
pwr = (pwr & AC_PWRST_ACTUAL) >> AC_PWRST_ACTUAL_SHIFT;
codec_dbg(codec, "Haswell HDMI audio: Power for pin 0x%x is now D%d\n", nid, pwr);
}
}
static int hdmi_pin_hbr_setup(struct hda_codec *codec, hda_nid_t pin_nid,
bool hbr)
{
int pinctl, new_pinctl;
if (snd_hda_query_pin_caps(codec, pin_nid) & AC_PINCAP_HBR) {
pinctl = snd_hda_codec_read(codec, pin_nid, 0,
AC_VERB_GET_PIN_WIDGET_CONTROL, 0);
if (pinctl < 0)
return hbr ? -EINVAL : 0;
new_pinctl = pinctl & ~AC_PINCTL_EPT;
if (hbr)
new_pinctl |= AC_PINCTL_EPT_HBR;
else
new_pinctl |= AC_PINCTL_EPT_NATIVE;
codec_dbg(codec,
"hdmi_pin_hbr_setup: NID=0x%x, %spinctl=0x%x\n",
pin_nid,
pinctl == new_pinctl ? "" : "new-",
new_pinctl);
if (pinctl != new_pinctl)
snd_hda_codec_write(codec, pin_nid, 0,
AC_VERB_SET_PIN_WIDGET_CONTROL,
new_pinctl);
} else if (hbr)
return -EINVAL;
return 0;
}
static int hdmi_setup_stream(struct hda_codec *codec, hda_nid_t cvt_nid,
hda_nid_t pin_nid, u32 stream_tag, int format)
{
struct hdmi_spec *spec = codec->spec;
int err;
if (is_haswell_plus(codec))
haswell_verify_D0(codec, cvt_nid, pin_nid);
err = spec->ops.pin_hbr_setup(codec, pin_nid, is_hbr_format(format));
if (err) {
codec_dbg(codec, "hdmi_setup_stream: HBR is not supported\n");
return err;
}
snd_hda_codec_setup_stream(codec, cvt_nid, stream_tag, 0, format);
return 0;
}
static int hdmi_choose_cvt(struct hda_codec *codec,
int pin_idx, int *cvt_id, int *mux_id)
{
struct hdmi_spec *spec = codec->spec;
struct hdmi_spec_per_pin *per_pin;
struct hdmi_spec_per_cvt *per_cvt = NULL;
int cvt_idx, mux_idx = 0;
per_pin = get_pin(spec, pin_idx);
for (cvt_idx = 0; cvt_idx < spec->num_cvts; cvt_idx++) {
per_cvt = get_cvt(spec, cvt_idx);
if (per_cvt->assigned)
continue;
for (mux_idx = 0; mux_idx < per_pin->num_mux_nids; mux_idx++)
if (per_pin->mux_nids[mux_idx] == per_cvt->cvt_nid)
break;
if (mux_idx == per_pin->num_mux_nids)
continue;
break;
}
if (cvt_idx == spec->num_cvts)
return -ENODEV;
per_pin->mux_idx = mux_idx;
if (cvt_id)
*cvt_id = cvt_idx;
if (mux_id)
*mux_id = mux_idx;
return 0;
}
static void intel_verify_pin_cvt_connect(struct hda_codec *codec,
struct hdmi_spec_per_pin *per_pin)
{
hda_nid_t pin_nid = per_pin->pin_nid;
int mux_idx, curr;
mux_idx = per_pin->mux_idx;
curr = snd_hda_codec_read(codec, pin_nid, 0,
AC_VERB_GET_CONNECT_SEL, 0);
if (curr != mux_idx)
snd_hda_codec_write_cache(codec, pin_nid, 0,
AC_VERB_SET_CONNECT_SEL,
mux_idx);
}
static void intel_not_share_assigned_cvt(struct hda_codec *codec,
hda_nid_t pin_nid, int mux_idx)
{
struct hdmi_spec *spec = codec->spec;
hda_nid_t nid, end_nid;
int cvt_idx, curr;
struct hdmi_spec_per_cvt *per_cvt;
end_nid = codec->start_nid + codec->num_nodes;
for (nid = codec->start_nid; nid < end_nid; nid++) {
unsigned int wid_caps = get_wcaps(codec, nid);
unsigned int wid_type = get_wcaps_type(wid_caps);
if (wid_type != AC_WID_PIN)
continue;
if (nid == pin_nid)
continue;
curr = snd_hda_codec_read(codec, nid, 0,
AC_VERB_GET_CONNECT_SEL, 0);
if (curr != mux_idx)
continue;
for (cvt_idx = 0; cvt_idx < spec->num_cvts; cvt_idx++) {
per_cvt = get_cvt(spec, cvt_idx);
if (!per_cvt->assigned) {
codec_dbg(codec,
"choose cvt %d for pin nid %d\n",
cvt_idx, nid);
snd_hda_codec_write_cache(codec, nid, 0,
AC_VERB_SET_CONNECT_SEL,
cvt_idx);
break;
}
}
}
}
static int hdmi_pcm_open(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
struct snd_pcm_substream *substream)
{
struct hdmi_spec *spec = codec->spec;
struct snd_pcm_runtime *runtime = substream->runtime;
int pin_idx, cvt_idx, mux_idx = 0;
struct hdmi_spec_per_pin *per_pin;
struct hdmi_eld *eld;
struct hdmi_spec_per_cvt *per_cvt = NULL;
int err;
pin_idx = hinfo_to_pin_index(codec, hinfo);
if (snd_BUG_ON(pin_idx < 0))
return -EINVAL;
per_pin = get_pin(spec, pin_idx);
eld = &per_pin->sink_eld;
err = hdmi_choose_cvt(codec, pin_idx, &cvt_idx, &mux_idx);
if (err < 0)
return err;
per_cvt = get_cvt(spec, cvt_idx);
per_cvt->assigned = 1;
per_pin->cvt_nid = per_cvt->cvt_nid;
hinfo->nid = per_cvt->cvt_nid;
snd_hda_codec_write_cache(codec, per_pin->pin_nid, 0,
AC_VERB_SET_CONNECT_SEL,
mux_idx);
if (is_haswell_plus(codec) || is_valleyview(codec))
intel_not_share_assigned_cvt(codec, per_pin->pin_nid, mux_idx);
snd_hda_spdif_ctls_assign(codec, pin_idx, per_cvt->cvt_nid);
hinfo->channels_min = per_cvt->channels_min;
hinfo->channels_max = per_cvt->channels_max;
hinfo->rates = per_cvt->rates;
hinfo->formats = per_cvt->formats;
hinfo->maxbps = per_cvt->maxbps;
if (!static_hdmi_pcm && eld->eld_valid) {
snd_hdmi_eld_update_pcm_info(&eld->info, hinfo);
if (hinfo->channels_min > hinfo->channels_max ||
!hinfo->rates || !hinfo->formats) {
per_cvt->assigned = 0;
hinfo->nid = 0;
snd_hda_spdif_ctls_unassign(codec, pin_idx);
return -ENODEV;
}
}
runtime->hw.channels_min = hinfo->channels_min;
runtime->hw.channels_max = hinfo->channels_max;
runtime->hw.formats = hinfo->formats;
runtime->hw.rates = hinfo->rates;
snd_pcm_hw_constraint_step(substream->runtime, 0,
SNDRV_PCM_HW_PARAM_CHANNELS, 2);
return 0;
}
static int hdmi_read_pin_conn(struct hda_codec *codec, int pin_idx)
{
struct hdmi_spec *spec = codec->spec;
struct hdmi_spec_per_pin *per_pin = get_pin(spec, pin_idx);
hda_nid_t pin_nid = per_pin->pin_nid;
if (!(get_wcaps(codec, pin_nid) & AC_WCAP_CONN_LIST)) {
codec_warn(codec,
"HDMI: pin %d wcaps %#x does not support connection list\n",
pin_nid, get_wcaps(codec, pin_nid));
return -EINVAL;
}
per_pin->num_mux_nids = snd_hda_get_connections(codec, pin_nid,
per_pin->mux_nids,
HDA_MAX_CONNECTIONS);
return 0;
}
static bool hdmi_present_sense(struct hdmi_spec_per_pin *per_pin, int repoll)
{
struct hda_jack_tbl *jack;
struct hda_codec *codec = per_pin->codec;
struct hdmi_spec *spec = codec->spec;
struct hdmi_eld *eld = &spec->temp_eld;
struct hdmi_eld *pin_eld = &per_pin->sink_eld;
hda_nid_t pin_nid = per_pin->pin_nid;
int present;
bool update_eld = false;
bool eld_changed = false;
bool ret;
snd_hda_power_up(codec);
present = snd_hda_pin_sense(codec, pin_nid);
mutex_lock(&per_pin->lock);
pin_eld->monitor_present = !!(present & AC_PINSENSE_PRESENCE);
if (pin_eld->monitor_present)
eld->eld_valid = !!(present & AC_PINSENSE_ELDV);
else
eld->eld_valid = false;
codec_dbg(codec,
"HDMI status: Codec=%d Pin=%d Presence_Detect=%d ELD_Valid=%d\n",
codec->addr, pin_nid, pin_eld->monitor_present, eld->eld_valid);
if (eld->eld_valid) {
if (spec->ops.pin_get_eld(codec, pin_nid, eld->eld_buffer,
&eld->eld_size) < 0)
eld->eld_valid = false;
else {
memset(&eld->info, 0, sizeof(struct parsed_hdmi_eld));
if (snd_hdmi_parse_eld(&eld->info, eld->eld_buffer,
eld->eld_size) < 0)
eld->eld_valid = false;
}
if (eld->eld_valid) {
snd_hdmi_show_eld(&eld->info);
update_eld = true;
}
else if (repoll) {
queue_delayed_work(codec->bus->workq,
&per_pin->work,
msecs_to_jiffies(300));
goto unlock;
}
}
if (pin_eld->eld_valid && !eld->eld_valid) {
update_eld = true;
eld_changed = true;
}
if (update_eld) {
bool old_eld_valid = pin_eld->eld_valid;
pin_eld->eld_valid = eld->eld_valid;
eld_changed = pin_eld->eld_size != eld->eld_size ||
memcmp(pin_eld->eld_buffer, eld->eld_buffer,
eld->eld_size) != 0;
if (eld_changed)
memcpy(pin_eld->eld_buffer, eld->eld_buffer,
eld->eld_size);
pin_eld->eld_size = eld->eld_size;
pin_eld->info = eld->info;
if (eld->eld_valid && !old_eld_valid && per_pin->setup) {
if (is_haswell_plus(codec) || is_valleyview(codec)) {
intel_verify_pin_cvt_connect(codec, per_pin);
intel_not_share_assigned_cvt(codec, pin_nid,
per_pin->mux_idx);
}
hdmi_setup_audio_infoframe(codec, per_pin,
per_pin->non_pcm);
}
}
if (eld_changed)
snd_ctl_notify(codec->bus->card,
SNDRV_CTL_EVENT_MASK_VALUE | SNDRV_CTL_EVENT_MASK_INFO,
&per_pin->eld_ctl->id);
unlock:
ret = !repoll || !pin_eld->monitor_present || pin_eld->eld_valid;
jack = snd_hda_jack_tbl_get(codec, pin_nid);
if (jack)
jack->block_report = !ret;
mutex_unlock(&per_pin->lock);
snd_hda_power_down(codec);
return ret;
}
static void hdmi_repoll_eld(struct work_struct *work)
{
struct hdmi_spec_per_pin *per_pin =
container_of(to_delayed_work(work), struct hdmi_spec_per_pin, work);
if (per_pin->repoll_count++ > 6)
per_pin->repoll_count = 0;
if (hdmi_present_sense(per_pin, per_pin->repoll_count))
snd_hda_jack_report_sync(per_pin->codec);
}
static int hdmi_add_pin(struct hda_codec *codec, hda_nid_t pin_nid)
{
struct hdmi_spec *spec = codec->spec;
unsigned int caps, config;
int pin_idx;
struct hdmi_spec_per_pin *per_pin;
int err;
caps = snd_hda_query_pin_caps(codec, pin_nid);
if (!(caps & (AC_PINCAP_HDMI | AC_PINCAP_DP)))
return 0;
config = snd_hda_codec_get_pincfg(codec, pin_nid);
if (get_defcfg_connect(config) == AC_JACK_PORT_NONE)
return 0;
if (is_haswell_plus(codec))
intel_haswell_fixup_connect_list(codec, pin_nid);
pin_idx = spec->num_pins;
per_pin = snd_array_new(&spec->pins);
if (!per_pin)
return -ENOMEM;
per_pin->pin_nid = pin_nid;
per_pin->non_pcm = false;
err = hdmi_read_pin_conn(codec, pin_idx);
if (err < 0)
return err;
spec->num_pins++;
return 0;
}
static int hdmi_add_cvt(struct hda_codec *codec, hda_nid_t cvt_nid)
{
struct hdmi_spec *spec = codec->spec;
struct hdmi_spec_per_cvt *per_cvt;
unsigned int chans;
int err;
chans = get_wcaps(codec, cvt_nid);
chans = get_wcaps_channels(chans);
per_cvt = snd_array_new(&spec->cvts);
if (!per_cvt)
return -ENOMEM;
per_cvt->cvt_nid = cvt_nid;
per_cvt->channels_min = 2;
if (chans <= 16) {
per_cvt->channels_max = chans;
if (chans > spec->channels_max)
spec->channels_max = chans;
}
err = snd_hda_query_supported_pcm(codec, cvt_nid,
&per_cvt->rates,
&per_cvt->formats,
&per_cvt->maxbps);
if (err < 0)
return err;
if (spec->num_cvts < ARRAY_SIZE(spec->cvt_nids))
spec->cvt_nids[spec->num_cvts] = cvt_nid;
spec->num_cvts++;
return 0;
}
static int hdmi_parse_codec(struct hda_codec *codec)
{
hda_nid_t nid;
int i, nodes;
nodes = snd_hda_get_sub_nodes(codec, codec->afg, &nid);
if (!nid || nodes < 0) {
codec_warn(codec, "HDMI: failed to get afg sub nodes\n");
return -EINVAL;
}
for (i = 0; i < nodes; i++, nid++) {
unsigned int caps;
unsigned int type;
caps = get_wcaps(codec, nid);
type = get_wcaps_type(caps);
if (!(caps & AC_WCAP_DIGITAL))
continue;
switch (type) {
case AC_WID_AUD_OUT:
hdmi_add_cvt(codec, nid);
break;
case AC_WID_PIN:
hdmi_add_pin(codec, nid);
break;
}
}
return 0;
}
static bool check_non_pcm_per_cvt(struct hda_codec *codec, hda_nid_t cvt_nid)
{
struct hda_spdif_out *spdif;
bool non_pcm;
mutex_lock(&codec->spdif_mutex);
spdif = snd_hda_spdif_out_of_nid(codec, cvt_nid);
non_pcm = !!(spdif->status & IEC958_AES0_NONAUDIO);
mutex_unlock(&codec->spdif_mutex);
return non_pcm;
}
static int generic_hdmi_playback_pcm_prepare(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
unsigned int stream_tag,
unsigned int format,
struct snd_pcm_substream *substream)
{
hda_nid_t cvt_nid = hinfo->nid;
struct hdmi_spec *spec = codec->spec;
int pin_idx = hinfo_to_pin_index(codec, hinfo);
struct hdmi_spec_per_pin *per_pin = get_pin(spec, pin_idx);
hda_nid_t pin_nid = per_pin->pin_nid;
bool non_pcm;
int pinctl;
if (is_haswell_plus(codec) || is_valleyview(codec)) {
intel_verify_pin_cvt_connect(codec, per_pin);
intel_not_share_assigned_cvt(codec, pin_nid, per_pin->mux_idx);
}
non_pcm = check_non_pcm_per_cvt(codec, cvt_nid);
mutex_lock(&per_pin->lock);
per_pin->channels = substream->runtime->channels;
per_pin->setup = true;
hdmi_setup_audio_infoframe(codec, per_pin, non_pcm);
mutex_unlock(&per_pin->lock);
if (spec->dyn_pin_out) {
pinctl = snd_hda_codec_read(codec, pin_nid, 0,
AC_VERB_GET_PIN_WIDGET_CONTROL, 0);
snd_hda_codec_write(codec, pin_nid, 0,
AC_VERB_SET_PIN_WIDGET_CONTROL,
pinctl | PIN_OUT);
}
return spec->ops.setup_stream(codec, cvt_nid, pin_nid, stream_tag, format);
}
static int generic_hdmi_playback_pcm_cleanup(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
struct snd_pcm_substream *substream)
{
snd_hda_codec_cleanup_stream(codec, hinfo->nid);
return 0;
}
static int hdmi_pcm_close(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
struct snd_pcm_substream *substream)
{
struct hdmi_spec *spec = codec->spec;
int cvt_idx, pin_idx;
struct hdmi_spec_per_cvt *per_cvt;
struct hdmi_spec_per_pin *per_pin;
int pinctl;
if (hinfo->nid) {
cvt_idx = cvt_nid_to_cvt_index(codec, hinfo->nid);
if (snd_BUG_ON(cvt_idx < 0))
return -EINVAL;
per_cvt = get_cvt(spec, cvt_idx);
snd_BUG_ON(!per_cvt->assigned);
per_cvt->assigned = 0;
hinfo->nid = 0;
pin_idx = hinfo_to_pin_index(codec, hinfo);
if (snd_BUG_ON(pin_idx < 0))
return -EINVAL;
per_pin = get_pin(spec, pin_idx);
if (spec->dyn_pin_out) {
pinctl = snd_hda_codec_read(codec, per_pin->pin_nid, 0,
AC_VERB_GET_PIN_WIDGET_CONTROL, 0);
snd_hda_codec_write(codec, per_pin->pin_nid, 0,
AC_VERB_SET_PIN_WIDGET_CONTROL,
pinctl & ~PIN_OUT);
}
snd_hda_spdif_ctls_unassign(codec, pin_idx);
mutex_lock(&per_pin->lock);
per_pin->chmap_set = false;
memset(per_pin->chmap, 0, sizeof(per_pin->chmap));
per_pin->setup = false;
per_pin->channels = 0;
mutex_unlock(&per_pin->lock);
}
return 0;
}
static int hdmi_chmap_ctl_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
struct snd_pcm_chmap *info = snd_kcontrol_chip(kcontrol);
struct hda_codec *codec = info->private_data;
struct hdmi_spec *spec = codec->spec;
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = spec->channels_max;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = SNDRV_CHMAP_LAST;
return 0;
}
static int hdmi_chmap_cea_alloc_validate_get_type(struct cea_channel_speaker_allocation *cap,
int channels)
{
if (cap->channels != channels)
return -1;
return SNDRV_CTL_TLVT_CHMAP_VAR;
}
static void hdmi_cea_alloc_to_tlv_chmap(struct cea_channel_speaker_allocation *cap,
unsigned int *chmap, int channels)
{
int count = 0;
int c;
for (c = 7; c >= 0; c--) {
int spk = cap->speakers[c];
if (!spk)
continue;
chmap[count++] = spk_to_chmap(spk);
}
WARN_ON(count != channels);
}
static int hdmi_chmap_ctl_tlv(struct snd_kcontrol *kcontrol, int op_flag,
unsigned int size, unsigned int __user *tlv)
{
struct snd_pcm_chmap *info = snd_kcontrol_chip(kcontrol);
struct hda_codec *codec = info->private_data;
struct hdmi_spec *spec = codec->spec;
unsigned int __user *dst;
int chs, count = 0;
if (size < 8)
return -ENOMEM;
if (put_user(SNDRV_CTL_TLVT_CONTAINER, tlv))
return -EFAULT;
size -= 8;
dst = tlv + 2;
for (chs = 2; chs <= spec->channels_max; chs++) {
int i;
struct cea_channel_speaker_allocation *cap;
cap = channel_allocations;
for (i = 0; i < ARRAY_SIZE(channel_allocations); i++, cap++) {
int chs_bytes = chs * 4;
int type = spec->ops.chmap_cea_alloc_validate_get_type(cap, chs);
unsigned int tlv_chmap[8];
if (type < 0)
continue;
if (size < 8)
return -ENOMEM;
if (put_user(type, dst) ||
put_user(chs_bytes, dst + 1))
return -EFAULT;
dst += 2;
size -= 8;
count += 8;
if (size < chs_bytes)
return -ENOMEM;
size -= chs_bytes;
count += chs_bytes;
spec->ops.cea_alloc_to_tlv_chmap(cap, tlv_chmap, chs);
if (copy_to_user(dst, tlv_chmap, chs_bytes))
return -EFAULT;
dst += chs;
}
}
if (put_user(count, tlv + 1))
return -EFAULT;
return 0;
}
static int hdmi_chmap_ctl_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_pcm_chmap *info = snd_kcontrol_chip(kcontrol);
struct hda_codec *codec = info->private_data;
struct hdmi_spec *spec = codec->spec;
int pin_idx = kcontrol->private_value;
struct hdmi_spec_per_pin *per_pin = get_pin(spec, pin_idx);
int i;
for (i = 0; i < ARRAY_SIZE(per_pin->chmap); i++)
ucontrol->value.integer.value[i] = per_pin->chmap[i];
return 0;
}
static int hdmi_chmap_ctl_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_pcm_chmap *info = snd_kcontrol_chip(kcontrol);
struct hda_codec *codec = info->private_data;
struct hdmi_spec *spec = codec->spec;
int pin_idx = kcontrol->private_value;
struct hdmi_spec_per_pin *per_pin = get_pin(spec, pin_idx);
unsigned int ctl_idx;
struct snd_pcm_substream *substream;
unsigned char chmap[8];
int i, err, ca, prepared = 0;
ctl_idx = snd_ctl_get_ioffidx(kcontrol, &ucontrol->id);
substream = snd_pcm_chmap_substream(info, ctl_idx);
if (!substream || !substream->runtime)
return 0;
switch (substream->runtime->status->state) {
case SNDRV_PCM_STATE_OPEN:
case SNDRV_PCM_STATE_SETUP:
break;
case SNDRV_PCM_STATE_PREPARED:
prepared = 1;
break;
default:
return -EBUSY;
}
memset(chmap, 0, sizeof(chmap));
for (i = 0; i < ARRAY_SIZE(chmap); i++)
chmap[i] = ucontrol->value.integer.value[i];
if (!memcmp(chmap, per_pin->chmap, sizeof(chmap)))
return 0;
ca = hdmi_manual_channel_allocation(ARRAY_SIZE(chmap), chmap);
if (ca < 0)
return -EINVAL;
if (spec->ops.chmap_validate) {
err = spec->ops.chmap_validate(ca, ARRAY_SIZE(chmap), chmap);
if (err)
return err;
}
mutex_lock(&per_pin->lock);
per_pin->chmap_set = true;
memcpy(per_pin->chmap, chmap, sizeof(chmap));
if (prepared)
hdmi_setup_audio_infoframe(codec, per_pin, per_pin->non_pcm);
mutex_unlock(&per_pin->lock);
return 0;
}
static int generic_hdmi_build_pcms(struct hda_codec *codec)
{
struct hdmi_spec *spec = codec->spec;
int pin_idx;
for (pin_idx = 0; pin_idx < spec->num_pins; pin_idx++) {
struct hda_pcm *info;
struct hda_pcm_stream *pstr;
struct hdmi_spec_per_pin *per_pin;
per_pin = get_pin(spec, pin_idx);
sprintf(per_pin->pcm_name, "HDMI %d", pin_idx);
info = snd_array_new(&spec->pcm_rec);
if (!info)
return -ENOMEM;
info->name = per_pin->pcm_name;
info->pcm_type = HDA_PCM_TYPE_HDMI;
info->own_chmap = true;
pstr = &info->stream[SNDRV_PCM_STREAM_PLAYBACK];
pstr->substreams = 1;
pstr->ops = generic_ops;
}
codec->num_pcms = spec->num_pins;
codec->pcm_info = spec->pcm_rec.list;
return 0;
}
static int generic_hdmi_build_jack(struct hda_codec *codec, int pin_idx)
{
char hdmi_str[32] = "HDMI/DP";
struct hdmi_spec *spec = codec->spec;
struct hdmi_spec_per_pin *per_pin = get_pin(spec, pin_idx);
int pcmdev = get_pcm_rec(spec, pin_idx)->device;
if (pcmdev > 0)
sprintf(hdmi_str + strlen(hdmi_str), ",pcm=%d", pcmdev);
if (!is_jack_detectable(codec, per_pin->pin_nid))
strncat(hdmi_str, " Phantom",
sizeof(hdmi_str) - strlen(hdmi_str) - 1);
return snd_hda_jack_add_kctl(codec, per_pin->pin_nid, hdmi_str, 0);
}
static int generic_hdmi_build_controls(struct hda_codec *codec)
{
struct hdmi_spec *spec = codec->spec;
int err;
int pin_idx;
for (pin_idx = 0; pin_idx < spec->num_pins; pin_idx++) {
struct hdmi_spec_per_pin *per_pin = get_pin(spec, pin_idx);
err = generic_hdmi_build_jack(codec, pin_idx);
if (err < 0)
return err;
err = snd_hda_create_dig_out_ctls(codec,
per_pin->pin_nid,
per_pin->mux_nids[0],
HDA_PCM_TYPE_HDMI);
if (err < 0)
return err;
snd_hda_spdif_ctls_unassign(codec, pin_idx);
err = hdmi_create_eld_ctl(codec, pin_idx,
get_pcm_rec(spec, pin_idx)->device);
if (err < 0)
return err;
hdmi_present_sense(per_pin, 0);
}
for (pin_idx = 0; pin_idx < spec->num_pins; pin_idx++) {
struct snd_pcm_chmap *chmap;
struct snd_kcontrol *kctl;
int i;
if (!codec->pcm_info[pin_idx].pcm)
break;
err = snd_pcm_add_chmap_ctls(codec->pcm_info[pin_idx].pcm,
SNDRV_PCM_STREAM_PLAYBACK,
NULL, 0, pin_idx, &chmap);
if (err < 0)
return err;
chmap->private_data = codec;
kctl = chmap->kctl;
for (i = 0; i < kctl->count; i++)
kctl->vd[i].access |= SNDRV_CTL_ELEM_ACCESS_WRITE;
kctl->info = hdmi_chmap_ctl_info;
kctl->get = hdmi_chmap_ctl_get;
kctl->put = hdmi_chmap_ctl_put;
kctl->tlv.c = hdmi_chmap_ctl_tlv;
}
return 0;
}
static int generic_hdmi_init_per_pins(struct hda_codec *codec)
{
struct hdmi_spec *spec = codec->spec;
int pin_idx;
for (pin_idx = 0; pin_idx < spec->num_pins; pin_idx++) {
struct hdmi_spec_per_pin *per_pin = get_pin(spec, pin_idx);
per_pin->codec = codec;
mutex_init(&per_pin->lock);
INIT_DELAYED_WORK(&per_pin->work, hdmi_repoll_eld);
eld_proc_new(per_pin, pin_idx);
}
return 0;
}
static int generic_hdmi_init(struct hda_codec *codec)
{
struct hdmi_spec *spec = codec->spec;
int pin_idx;
for (pin_idx = 0; pin_idx < spec->num_pins; pin_idx++) {
struct hdmi_spec_per_pin *per_pin = get_pin(spec, pin_idx);
hda_nid_t pin_nid = per_pin->pin_nid;
hdmi_init_pin(codec, pin_nid);
snd_hda_jack_detect_enable_callback(codec, pin_nid, pin_nid,
codec->jackpoll_interval > 0 ? jack_callback : NULL);
}
return 0;
}
static void hdmi_array_init(struct hdmi_spec *spec, int nums)
{
snd_array_init(&spec->pins, sizeof(struct hdmi_spec_per_pin), nums);
snd_array_init(&spec->cvts, sizeof(struct hdmi_spec_per_cvt), nums);
snd_array_init(&spec->pcm_rec, sizeof(struct hda_pcm), nums);
}
static void hdmi_array_free(struct hdmi_spec *spec)
{
snd_array_free(&spec->pins);
snd_array_free(&spec->cvts);
snd_array_free(&spec->pcm_rec);
}
static void generic_hdmi_free(struct hda_codec *codec)
{
struct hdmi_spec *spec = codec->spec;
int pin_idx;
for (pin_idx = 0; pin_idx < spec->num_pins; pin_idx++) {
struct hdmi_spec_per_pin *per_pin = get_pin(spec, pin_idx);
cancel_delayed_work(&per_pin->work);
eld_proc_free(per_pin);
}
flush_workqueue(codec->bus->workq);
hdmi_array_free(spec);
kfree(spec);
}
static int generic_hdmi_resume(struct hda_codec *codec)
{
struct hdmi_spec *spec = codec->spec;
int pin_idx;
codec->patch_ops.init(codec);
snd_hda_codec_resume_amp(codec);
snd_hda_codec_resume_cache(codec);
for (pin_idx = 0; pin_idx < spec->num_pins; pin_idx++) {
struct hdmi_spec_per_pin *per_pin = get_pin(spec, pin_idx);
hdmi_present_sense(per_pin, 1);
}
return 0;
}
static void intel_haswell_fixup_connect_list(struct hda_codec *codec,
hda_nid_t nid)
{
struct hdmi_spec *spec = codec->spec;
hda_nid_t conns[4];
int nconns;
nconns = snd_hda_get_connections(codec, nid, conns, ARRAY_SIZE(conns));
if (nconns == spec->num_cvts &&
!memcmp(conns, spec->cvt_nids, spec->num_cvts * sizeof(hda_nid_t)))
return;
codec_dbg(codec, "hdmi: haswell: override pin connection 0x%x\n", nid);
snd_hda_override_conn_list(codec, nid, spec->num_cvts, spec->cvt_nids);
}
static void intel_haswell_enable_all_pins(struct hda_codec *codec,
bool update_tree)
{
unsigned int vendor_param;
vendor_param = snd_hda_codec_read(codec, INTEL_VENDOR_NID, 0,
INTEL_GET_VENDOR_VERB, 0);
if (vendor_param == -1 || vendor_param & INTEL_EN_ALL_PIN_CVTS)
return;
vendor_param |= INTEL_EN_ALL_PIN_CVTS;
vendor_param = snd_hda_codec_read(codec, INTEL_VENDOR_NID, 0,
INTEL_SET_VENDOR_VERB, vendor_param);
if (vendor_param == -1)
return;
if (update_tree)
snd_hda_codec_update_widgets(codec);
}
static void intel_haswell_fixup_enable_dp12(struct hda_codec *codec)
{
unsigned int vendor_param;
vendor_param = snd_hda_codec_read(codec, INTEL_VENDOR_NID, 0,
INTEL_GET_VENDOR_VERB, 0);
if (vendor_param == -1 || vendor_param & INTEL_EN_DP12)
return;
vendor_param |= INTEL_EN_DP12;
snd_hda_codec_write_cache(codec, INTEL_VENDOR_NID, 0,
INTEL_SET_VENDOR_VERB, vendor_param);
}
static void haswell_set_power_state(struct hda_codec *codec, hda_nid_t fg,
unsigned int power_state)
{
if (power_state == AC_PWRST_D0) {
intel_haswell_enable_all_pins(codec, false);
intel_haswell_fixup_enable_dp12(codec);
}
snd_hda_codec_read(codec, fg, 0, AC_VERB_SET_POWER_STATE, power_state);
snd_hda_codec_set_power_to_all(codec, fg, power_state);
}
static int patch_generic_hdmi(struct hda_codec *codec)
{
struct hdmi_spec *spec;
spec = kzalloc(sizeof(*spec), GFP_KERNEL);
if (spec == NULL)
return -ENOMEM;
spec->ops = generic_standard_hdmi_ops;
codec->spec = spec;
hdmi_array_init(spec, 4);
if (is_haswell_plus(codec)) {
intel_haswell_enable_all_pins(codec, true);
intel_haswell_fixup_enable_dp12(codec);
}
if (is_haswell(codec) || is_valleyview(codec)) {
codec->depop_delay = 0;
}
if (hdmi_parse_codec(codec) < 0) {
codec->spec = NULL;
kfree(spec);
return -EINVAL;
}
codec->patch_ops = generic_hdmi_patch_ops;
if (is_haswell_plus(codec)) {
codec->patch_ops.set_power_state = haswell_set_power_state;
codec->dp_mst = true;
}
generic_hdmi_init_per_pins(codec);
init_channel_allocations();
return 0;
}
static int simple_playback_build_pcms(struct hda_codec *codec)
{
struct hdmi_spec *spec = codec->spec;
struct hda_pcm *info;
unsigned int chans;
struct hda_pcm_stream *pstr;
struct hdmi_spec_per_cvt *per_cvt;
per_cvt = get_cvt(spec, 0);
chans = get_wcaps(codec, per_cvt->cvt_nid);
chans = get_wcaps_channels(chans);
info = snd_array_new(&spec->pcm_rec);
if (!info)
return -ENOMEM;
info->name = get_pin(spec, 0)->pcm_name;
sprintf(info->name, "HDMI 0");
info->pcm_type = HDA_PCM_TYPE_HDMI;
pstr = &info->stream[SNDRV_PCM_STREAM_PLAYBACK];
*pstr = spec->pcm_playback;
pstr->nid = per_cvt->cvt_nid;
if (pstr->channels_max <= 2 && chans && chans <= 16)
pstr->channels_max = chans;
codec->num_pcms = 1;
codec->pcm_info = info;
return 0;
}
static void simple_hdmi_unsol_event(struct hda_codec *codec,
unsigned int res)
{
snd_hda_jack_set_dirty_all(codec);
snd_hda_jack_report_sync(codec);
}
static int simple_playback_build_controls(struct hda_codec *codec)
{
struct hdmi_spec *spec = codec->spec;
struct hdmi_spec_per_cvt *per_cvt;
int err;
per_cvt = get_cvt(spec, 0);
err = snd_hda_create_dig_out_ctls(codec, per_cvt->cvt_nid,
per_cvt->cvt_nid,
HDA_PCM_TYPE_HDMI);
if (err < 0)
return err;
return simple_hdmi_build_jack(codec, 0);
}
static int simple_playback_init(struct hda_codec *codec)
{
struct hdmi_spec *spec = codec->spec;
struct hdmi_spec_per_pin *per_pin = get_pin(spec, 0);
hda_nid_t pin = per_pin->pin_nid;
snd_hda_codec_write(codec, pin, 0,
AC_VERB_SET_PIN_WIDGET_CONTROL, PIN_OUT);
if (get_wcaps(codec, pin) & AC_WCAP_OUT_AMP)
snd_hda_codec_write(codec, pin, 0, AC_VERB_SET_AMP_GAIN_MUTE,
AMP_OUT_UNMUTE);
snd_hda_jack_detect_enable(codec, pin, pin);
return 0;
}
static void simple_playback_free(struct hda_codec *codec)
{
struct hdmi_spec *spec = codec->spec;
hdmi_array_free(spec);
kfree(spec);
}
static int nvhdmi_7x_init_2ch(struct hda_codec *codec)
{
snd_hda_sequence_write(codec, nvhdmi_basic_init_7x_2ch);
return 0;
}
static int nvhdmi_7x_init_8ch(struct hda_codec *codec)
{
snd_hda_sequence_write(codec, nvhdmi_basic_init_7x_8ch);
return 0;
}
static int simple_playback_pcm_open(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
struct snd_pcm_substream *substream)
{
struct hdmi_spec *spec = codec->spec;
struct snd_pcm_hw_constraint_list *hw_constraints_channels = NULL;
switch (codec->preset->id) {
case 0x10de0002:
case 0x10de0003:
case 0x10de0005:
case 0x10de0006:
hw_constraints_channels = &hw_constraints_2_8_channels;
break;
case 0x10de0007:
hw_constraints_channels = &hw_constraints_2_6_8_channels;
break;
default:
break;
}
if (hw_constraints_channels != NULL) {
snd_pcm_hw_constraint_list(substream->runtime, 0,
SNDRV_PCM_HW_PARAM_CHANNELS,
hw_constraints_channels);
} else {
snd_pcm_hw_constraint_step(substream->runtime, 0,
SNDRV_PCM_HW_PARAM_CHANNELS, 2);
}
return snd_hda_multi_out_dig_open(codec, &spec->multiout);
}
static int simple_playback_pcm_close(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
struct snd_pcm_substream *substream)
{
struct hdmi_spec *spec = codec->spec;
return snd_hda_multi_out_dig_close(codec, &spec->multiout);
}
static int simple_playback_pcm_prepare(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
unsigned int stream_tag,
unsigned int format,
struct snd_pcm_substream *substream)
{
struct hdmi_spec *spec = codec->spec;
return snd_hda_multi_out_dig_prepare(codec, &spec->multiout,
stream_tag, format, substream);
}
static int patch_simple_hdmi(struct hda_codec *codec,
hda_nid_t cvt_nid, hda_nid_t pin_nid)
{
struct hdmi_spec *spec;
struct hdmi_spec_per_cvt *per_cvt;
struct hdmi_spec_per_pin *per_pin;
spec = kzalloc(sizeof(*spec), GFP_KERNEL);
if (!spec)
return -ENOMEM;
codec->spec = spec;
hdmi_array_init(spec, 1);
spec->multiout.num_dacs = 0;
spec->multiout.max_channels = 2;
spec->multiout.dig_out_nid = cvt_nid;
spec->num_cvts = 1;
spec->num_pins = 1;
per_pin = snd_array_new(&spec->pins);
per_cvt = snd_array_new(&spec->cvts);
if (!per_pin || !per_cvt) {
simple_playback_free(codec);
return -ENOMEM;
}
per_cvt->cvt_nid = cvt_nid;
per_pin->pin_nid = pin_nid;
spec->pcm_playback = simple_pcm_playback;
codec->patch_ops = simple_hdmi_patch_ops;
return 0;
}
static void nvhdmi_8ch_7x_set_info_frame_parameters(struct hda_codec *codec,
int channels)
{
unsigned int chanmask;
int chan = channels ? (channels - 1) : 1;
switch (channels) {
default:
case 0:
case 2:
chanmask = 0x00;
break;
case 4:
chanmask = 0x08;
break;
case 6:
chanmask = 0x0b;
break;
case 8:
chanmask = 0x13;
break;
}
snd_hda_codec_write(codec, 0x1, 0,
Nv_VERB_SET_Channel_Allocation, chanmask);
snd_hda_codec_write(codec, 0x1, 0,
Nv_VERB_SET_Info_Frame_Checksum,
(0x71 - chan - chanmask));
}
static int nvhdmi_8ch_7x_pcm_close(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
struct snd_pcm_substream *substream)
{
struct hdmi_spec *spec = codec->spec;
int i;
snd_hda_codec_write(codec, nvhdmi_master_con_nid_7x,
0, AC_VERB_SET_CHANNEL_STREAMID, 0);
for (i = 0; i < 4; i++) {
snd_hda_codec_write(codec, nvhdmi_con_nids_7x[i], 0,
AC_VERB_SET_CHANNEL_STREAMID, 0);
snd_hda_codec_write(codec, nvhdmi_con_nids_7x[i], 0,
AC_VERB_SET_STREAM_FORMAT, 0);
}
nvhdmi_8ch_7x_set_info_frame_parameters(codec, 8);
return snd_hda_multi_out_dig_close(codec, &spec->multiout);
}
static int nvhdmi_8ch_7x_pcm_prepare(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
unsigned int stream_tag,
unsigned int format,
struct snd_pcm_substream *substream)
{
int chs;
unsigned int dataDCC2, channel_id;
int i;
struct hdmi_spec *spec = codec->spec;
struct hda_spdif_out *spdif;
struct hdmi_spec_per_cvt *per_cvt;
mutex_lock(&codec->spdif_mutex);
per_cvt = get_cvt(spec, 0);
spdif = snd_hda_spdif_out_of_nid(codec, per_cvt->cvt_nid);
chs = substream->runtime->channels;
dataDCC2 = 0x2;
if (codec->spdif_status_reset && (spdif->ctls & AC_DIG1_ENABLE))
snd_hda_codec_write(codec,
nvhdmi_master_con_nid_7x,
0,
AC_VERB_SET_DIGI_CONVERT_1,
spdif->ctls & ~AC_DIG1_ENABLE & 0xff);
snd_hda_codec_write(codec, nvhdmi_master_con_nid_7x, 0,
AC_VERB_SET_CHANNEL_STREAMID, (stream_tag << 4) | 0x0);
snd_hda_codec_write(codec, nvhdmi_master_con_nid_7x, 0,
AC_VERB_SET_STREAM_FORMAT, format);
if (codec->spdif_status_reset && (spdif->ctls & AC_DIG1_ENABLE)) {
snd_hda_codec_write(codec,
nvhdmi_master_con_nid_7x,
0,
AC_VERB_SET_DIGI_CONVERT_1,
spdif->ctls & 0xff);
snd_hda_codec_write(codec,
nvhdmi_master_con_nid_7x,
0,
AC_VERB_SET_DIGI_CONVERT_2, dataDCC2);
}
for (i = 0; i < 4; i++) {
if (chs == 2)
channel_id = 0;
else
channel_id = i * 2;
if (codec->spdif_status_reset &&
(spdif->ctls & AC_DIG1_ENABLE))
snd_hda_codec_write(codec,
nvhdmi_con_nids_7x[i],
0,
AC_VERB_SET_DIGI_CONVERT_1,
spdif->ctls & ~AC_DIG1_ENABLE & 0xff);
snd_hda_codec_write(codec,
nvhdmi_con_nids_7x[i],
0,
AC_VERB_SET_CHANNEL_STREAMID,
(stream_tag << 4) | channel_id);
snd_hda_codec_write(codec,
nvhdmi_con_nids_7x[i],
0,
AC_VERB_SET_STREAM_FORMAT,
format);
if (codec->spdif_status_reset &&
(spdif->ctls & AC_DIG1_ENABLE)) {
snd_hda_codec_write(codec,
nvhdmi_con_nids_7x[i],
0,
AC_VERB_SET_DIGI_CONVERT_1,
spdif->ctls & 0xff);
snd_hda_codec_write(codec,
nvhdmi_con_nids_7x[i],
0,
AC_VERB_SET_DIGI_CONVERT_2, dataDCC2);
}
}
nvhdmi_8ch_7x_set_info_frame_parameters(codec, chs);
mutex_unlock(&codec->spdif_mutex);
return 0;
}
static int patch_nvhdmi_2ch(struct hda_codec *codec)
{
struct hdmi_spec *spec;
int err = patch_simple_hdmi(codec, nvhdmi_master_con_nid_7x,
nvhdmi_master_pin_nid_7x);
if (err < 0)
return err;
codec->patch_ops.init = nvhdmi_7x_init_2ch;
spec = codec->spec;
spec->pcm_playback.rates = SUPPORTED_RATES;
spec->pcm_playback.maxbps = SUPPORTED_MAXBPS;
spec->pcm_playback.formats = SUPPORTED_FORMATS;
return 0;
}
static int nvhdmi_7x_8ch_build_pcms(struct hda_codec *codec)
{
struct hdmi_spec *spec = codec->spec;
int err = simple_playback_build_pcms(codec);
if (!err) {
struct hda_pcm *info = get_pcm_rec(spec, 0);
info->own_chmap = true;
}
return err;
}
static int nvhdmi_7x_8ch_build_controls(struct hda_codec *codec)
{
struct hdmi_spec *spec = codec->spec;
struct hda_pcm *info;
struct snd_pcm_chmap *chmap;
int err;
err = simple_playback_build_controls(codec);
if (err < 0)
return err;
info = get_pcm_rec(spec, 0);
err = snd_pcm_add_chmap_ctls(info->pcm,
SNDRV_PCM_STREAM_PLAYBACK,
snd_pcm_alt_chmaps, 8, 0, &chmap);
if (err < 0)
return err;
switch (codec->preset->id) {
case 0x10de0002:
case 0x10de0003:
case 0x10de0005:
case 0x10de0006:
chmap->channel_mask = (1U << 2) | (1U << 8);
break;
case 0x10de0007:
chmap->channel_mask = (1U << 2) | (1U << 6) | (1U << 8);
}
return 0;
}
static int patch_nvhdmi_8ch_7x(struct hda_codec *codec)
{
struct hdmi_spec *spec;
int err = patch_nvhdmi_2ch(codec);
if (err < 0)
return err;
spec = codec->spec;
spec->multiout.max_channels = 8;
spec->pcm_playback = nvhdmi_pcm_playback_8ch_7x;
codec->patch_ops.init = nvhdmi_7x_init_8ch;
codec->patch_ops.build_pcms = nvhdmi_7x_8ch_build_pcms;
codec->patch_ops.build_controls = nvhdmi_7x_8ch_build_controls;
nvhdmi_8ch_7x_set_info_frame_parameters(codec, 8);
return 0;
}
static int nvhdmi_chmap_cea_alloc_validate_get_type(struct cea_channel_speaker_allocation *cap,
int channels)
{
if (cap->ca_index == 0x00 && channels == 2)
return SNDRV_CTL_TLVT_CHMAP_FIXED;
return hdmi_chmap_cea_alloc_validate_get_type(cap, channels);
}
static int nvhdmi_chmap_validate(int ca, int chs, unsigned char *map)
{
if (ca == 0x00 && (map[0] != SNDRV_CHMAP_FL || map[1] != SNDRV_CHMAP_FR))
return -EINVAL;
return 0;
}
static int patch_nvhdmi(struct hda_codec *codec)
{
struct hdmi_spec *spec;
int err;
err = patch_generic_hdmi(codec);
if (err)
return err;
spec = codec->spec;
spec->dyn_pin_out = true;
spec->ops.chmap_cea_alloc_validate_get_type =
nvhdmi_chmap_cea_alloc_validate_get_type;
spec->ops.chmap_validate = nvhdmi_chmap_validate;
return 0;
}
static int atihdmi_pin_get_eld(struct hda_codec *codec, hda_nid_t nid,
unsigned char *buf, int *eld_size)
{
return snd_hdmi_get_eld_ati(codec, nid, buf, eld_size,
is_amdhdmi_rev3_or_later(codec));
}
static void atihdmi_pin_setup_infoframe(struct hda_codec *codec, hda_nid_t pin_nid, int ca,
int active_channels, int conn_type)
{
snd_hda_codec_write(codec, pin_nid, 0, ATI_VERB_SET_CHANNEL_ALLOCATION, ca);
}
static int atihdmi_paired_swap_fc_lfe(int pos)
{
switch (pos) {
case 2: return 3;
case 3: return 2;
default: break;
}
return pos;
}
static int atihdmi_paired_chmap_validate(int ca, int chs, unsigned char *map)
{
struct cea_channel_speaker_allocation *cap;
int i, j;
cap = &channel_allocations[get_channel_allocation_order(ca)];
for (i = 0; i < chs; ++i) {
int mask = to_spk_mask(map[i]);
bool ok = false;
bool companion_ok = false;
if (!mask)
continue;
for (j = 0 + i % 2; j < 8; j += 2) {
int chan_idx = 7 - atihdmi_paired_swap_fc_lfe(j);
if (cap->speakers[chan_idx] == mask) {
ok = true;
if (i % 2 == 0 && i + 1 < chs) {
int comp_chan_idx = 7 - atihdmi_paired_swap_fc_lfe(j + 1);
int comp_mask_req = to_spk_mask(map[i+1]);
int comp_mask_act = cap->speakers[comp_chan_idx];
if (comp_mask_req == comp_mask_act)
companion_ok = true;
else
return -EINVAL;
}
break;
}
}
if (!ok)
return -EINVAL;
if (companion_ok)
i++;
}
return 0;
}
static int atihdmi_pin_set_slot_channel(struct hda_codec *codec, hda_nid_t pin_nid,
int hdmi_slot, int stream_channel)
{
int verb;
int ati_channel_setup = 0;
if (hdmi_slot > 7)
return -EINVAL;
if (!has_amd_full_remap_support(codec)) {
hdmi_slot = atihdmi_paired_swap_fc_lfe(hdmi_slot);
if (hdmi_slot % 2 != 0 && stream_channel == 0xf)
return 0;
hdmi_slot -= hdmi_slot % 2;
if (stream_channel != 0xf)
stream_channel -= stream_channel % 2;
}
verb = ATI_VERB_SET_MULTICHANNEL_01 + hdmi_slot/2 + (hdmi_slot % 2) * 0x00e;
if (stream_channel != 0xf)
ati_channel_setup = (stream_channel << 4) | ATI_OUT_ENABLE;
return snd_hda_codec_write(codec, pin_nid, 0, verb, ati_channel_setup);
}
static int atihdmi_pin_get_slot_channel(struct hda_codec *codec, hda_nid_t pin_nid,
int asp_slot)
{
bool was_odd = false;
int ati_asp_slot = asp_slot;
int verb;
int ati_channel_setup;
if (asp_slot > 7)
return -EINVAL;
if (!has_amd_full_remap_support(codec)) {
ati_asp_slot = atihdmi_paired_swap_fc_lfe(asp_slot);
if (ati_asp_slot % 2 != 0) {
ati_asp_slot -= 1;
was_odd = true;
}
}
verb = ATI_VERB_GET_MULTICHANNEL_01 + ati_asp_slot/2 + (ati_asp_slot % 2) * 0x00e;
ati_channel_setup = snd_hda_codec_read(codec, pin_nid, 0, verb, 0);
if (!(ati_channel_setup & ATI_OUT_ENABLE))
return 0xf;
return ((ati_channel_setup & 0xf0) >> 4) + !!was_odd;
}
static int atihdmi_paired_chmap_cea_alloc_validate_get_type(struct cea_channel_speaker_allocation *cap,
int channels)
{
int c;
int chanpairs = 0;
if ((channels % 2) != 0)
return -1;
for (c = 0; c < 7; c += 2) {
if (cap->speakers[c] || cap->speakers[c+1])
chanpairs++;
}
if (chanpairs * 2 != channels)
return -1;
return SNDRV_CTL_TLVT_CHMAP_PAIRED;
}
static void atihdmi_paired_cea_alloc_to_tlv_chmap(struct cea_channel_speaker_allocation *cap,
unsigned int *chmap, int channels)
{
int count = 0;
int c;
for (c = 7; c >= 0; c--) {
int chan = 7 - atihdmi_paired_swap_fc_lfe(7 - c);
int spk = cap->speakers[chan];
if (!spk) {
if (cap->speakers[chan + (chan % 2 ? -1 : 1)])
chmap[count++] = SNDRV_CHMAP_NA;
continue;
}
chmap[count++] = spk_to_chmap(spk);
}
WARN_ON(count != channels);
}
static int atihdmi_pin_hbr_setup(struct hda_codec *codec, hda_nid_t pin_nid,
bool hbr)
{
int hbr_ctl, hbr_ctl_new;
hbr_ctl = snd_hda_codec_read(codec, pin_nid, 0, ATI_VERB_GET_HBR_CONTROL, 0);
if (hbr_ctl >= 0 && (hbr_ctl & ATI_HBR_CAPABLE)) {
if (hbr)
hbr_ctl_new = hbr_ctl | ATI_HBR_ENABLE;
else
hbr_ctl_new = hbr_ctl & ~ATI_HBR_ENABLE;
codec_dbg(codec,
"atihdmi_pin_hbr_setup: NID=0x%x, %shbr-ctl=0x%x\n",
pin_nid,
hbr_ctl == hbr_ctl_new ? "" : "new-",
hbr_ctl_new);
if (hbr_ctl != hbr_ctl_new)
snd_hda_codec_write(codec, pin_nid, 0,
ATI_VERB_SET_HBR_CONTROL,
hbr_ctl_new);
} else if (hbr)
return -EINVAL;
return 0;
}
static int atihdmi_setup_stream(struct hda_codec *codec, hda_nid_t cvt_nid,
hda_nid_t pin_nid, u32 stream_tag, int format)
{
if (is_amdhdmi_rev3_or_later(codec)) {
int ramp_rate = 180;
if (format & AC_FMT_TYPE_NON_PCM)
ramp_rate = 0;
snd_hda_codec_write(codec, cvt_nid, 0, ATI_VERB_SET_RAMP_RATE, ramp_rate);
}
return hdmi_setup_stream(codec, cvt_nid, pin_nid, stream_tag, format);
}
static int atihdmi_init(struct hda_codec *codec)
{
struct hdmi_spec *spec = codec->spec;
int pin_idx, err;
err = generic_hdmi_init(codec);
if (err)
return err;
for (pin_idx = 0; pin_idx < spec->num_pins; pin_idx++) {
struct hdmi_spec_per_pin *per_pin = get_pin(spec, pin_idx);
snd_hda_codec_write(codec, per_pin->pin_nid, 0, ATI_VERB_SET_DOWNMIX_INFO, 0);
if (has_amd_full_remap_support(codec))
snd_hda_codec_write(codec, per_pin->pin_nid, 0,
ATI_VERB_SET_MULTICHANNEL_MODE,
ATI_MULTICHANNEL_MODE_SINGLE);
}
return 0;
}
static int patch_atihdmi(struct hda_codec *codec)
{
struct hdmi_spec *spec;
struct hdmi_spec_per_cvt *per_cvt;
int err, cvt_idx;
err = patch_generic_hdmi(codec);
if (err)
return err;
codec->patch_ops.init = atihdmi_init;
spec = codec->spec;
spec->ops.pin_get_eld = atihdmi_pin_get_eld;
spec->ops.pin_get_slot_channel = atihdmi_pin_get_slot_channel;
spec->ops.pin_set_slot_channel = atihdmi_pin_set_slot_channel;
spec->ops.pin_setup_infoframe = atihdmi_pin_setup_infoframe;
spec->ops.pin_hbr_setup = atihdmi_pin_hbr_setup;
spec->ops.setup_stream = atihdmi_setup_stream;
if (!has_amd_full_remap_support(codec)) {
spec->ops.chmap_cea_alloc_validate_get_type =
atihdmi_paired_chmap_cea_alloc_validate_get_type;
spec->ops.cea_alloc_to_tlv_chmap = atihdmi_paired_cea_alloc_to_tlv_chmap;
spec->ops.chmap_validate = atihdmi_paired_chmap_validate;
}
for (cvt_idx = 0; cvt_idx < spec->num_cvts; cvt_idx++) {
per_cvt = get_cvt(spec, cvt_idx);
per_cvt->channels_max = max(per_cvt->channels_max, 8u);
per_cvt->rates |= SUPPORTED_RATES;
per_cvt->formats |= SUPPORTED_FORMATS;
per_cvt->maxbps = max(per_cvt->maxbps, 24u);
}
spec->channels_max = max(spec->channels_max, 8u);
return 0;
}
static int patch_via_hdmi(struct hda_codec *codec)
{
return patch_simple_hdmi(codec, VIAHDMI_CVT_NID, VIAHDMI_PIN_NID);
}
int snd_hda_parse_hdmi_codec(struct hda_codec *codec)
{
return patch_generic_hdmi(codec);
}
static int __init patch_hdmi_init(void)
{
return snd_hda_add_codec_preset(&intel_list);
}
static void __exit patch_hdmi_exit(void)
{
snd_hda_delete_codec_preset(&intel_list);
}
