static int pin_nid_to_pin_index(struct hdmi_spec *spec, hda_nid_t pin_nid)
{
int pin_idx;
for (pin_idx = 0; pin_idx < spec->num_pins; pin_idx++)
if (spec->pins[pin_idx].pin_nid == pin_nid)
return pin_idx;
snd_printk(KERN_WARNING "HDMI: pin nid %d not registered\n", pin_nid);
return -EINVAL;
}
static int hinfo_to_pin_index(struct hdmi_spec *spec,
struct hda_pcm_stream *hinfo)
{
int pin_idx;
for (pin_idx = 0; pin_idx < spec->num_pins; pin_idx++)
if (&spec->pcm_rec[pin_idx].stream[0] == hinfo)
return pin_idx;
snd_printk(KERN_WARNING "HDMI: hinfo %p not registered\n", hinfo);
return -EINVAL;
}
static int cvt_nid_to_cvt_index(struct hdmi_spec *spec, hda_nid_t cvt_nid)
{
int cvt_idx;
for (cvt_idx = 0; cvt_idx < spec->num_cvts; cvt_idx++)
if (spec->cvts[cvt_idx].cvt_nid == cvt_nid)
return cvt_idx;
snd_printk(KERN_WARNING "HDMI: cvt nid %d not registered\n", cvt_nid);
return -EINVAL;
}
static int hdmi_eld_ctl_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct hdmi_spec *spec;
int pin_idx;
spec = codec->spec;
uinfo->type = SNDRV_CTL_ELEM_TYPE_BYTES;
pin_idx = kcontrol->private_value;
uinfo->count = spec->pins[pin_idx].sink_eld.eld_size;
return 0;
}
static int hdmi_eld_ctl_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct hdmi_spec *spec;
int pin_idx;
spec = codec->spec;
pin_idx = kcontrol->private_value;
memcpy(ucontrol->value.bytes.data,
spec->pins[pin_idx].sink_eld.eld_buffer, ELD_MAX_SIZE);
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
err = snd_hda_ctl_add(codec, spec->pins[pin_idx].pin_nid, kctl);
if (err < 0)
return err;
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
if (get_wcaps(codec, pin_nid) & AC_WCAP_OUT_AMP)
snd_hda_codec_write(codec, pin_nid, 0,
AC_VERB_SET_AMP_GAIN_MUTE, AMP_OUT_UNMUTE);
snd_hda_codec_write(codec, pin_nid, 0,
AC_VERB_SET_PIN_WIDGET_CONTROL, 0);
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
if (eld->spk_alloc & (1 << i))
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
snd_print_channel_allocation(eld->spk_alloc, buf, sizeof(buf));
snd_printdd("HDMI: select CA 0x%x for %d-channel allocation: %s\n",
ca, channels, buf);
return ca;
}
static void hdmi_debug_channel_mapping(struct hda_codec *codec,
hda_nid_t pin_nid)
{
#ifdef CONFIG_SND_DEBUG_VERBOSE
int i;
int slot;
for (i = 0; i < 8; i++) {
slot = snd_hda_codec_read(codec, pin_nid, 0,
AC_VERB_GET_HDMI_CHAN_SLOT, i);
printk(KERN_DEBUG "HDMI: ASP channel %d => slot %d\n",
slot >> 4, slot & 0xf);
}
#endif
}
static void hdmi_std_setup_channel_mapping(struct hda_codec *codec,
hda_nid_t pin_nid,
bool non_pcm,
int ca)
{
int i;
int err;
int order;
int non_pcm_mapping[8];
order = get_channel_allocation_order(ca);
if (hdmi_channel_mapping[ca][1] == 0) {
for (i = 0; i < channel_allocations[order].channels; i++)
hdmi_channel_mapping[ca][i] = i | (i << 4);
for (; i < 8; i++)
hdmi_channel_mapping[ca][i] = 0xf | (i << 4);
}
if (non_pcm) {
for (i = 0; i < channel_allocations[order].channels; i++)
non_pcm_mapping[i] = i | (i << 4);
for (; i < 8; i++)
non_pcm_mapping[i] = 0xf | (i << 4);
}
for (i = 0; i < 8; i++) {
err = snd_hda_codec_write(codec, pin_nid, 0,
AC_VERB_SET_HDMI_CHAN_SLOT,
non_pcm ? non_pcm_mapping[i] : hdmi_channel_mapping[ca][i]);
if (err) {
snd_printdd(KERN_NOTICE
"HDMI: channel mapping failed\n");
break;
}
}
hdmi_debug_channel_mapping(codec, pin_nid);
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
static int to_cea_slot(unsigned char c)
{
struct channel_map_table *t = map_tables;
for (; t->map; t++) {
if (t->map == c)
return t->cea_slot;
}
return 0x0f;
}
static int from_cea_slot(unsigned char c)
{
struct channel_map_table *t = map_tables;
for (; t->map; t++) {
if (t->cea_slot == c)
return t->map;
}
return 0;
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
int chs, unsigned char *map)
{
int i;
for (i = 0; i < 8; i++) {
int val, err;
if (i < chs)
val = to_cea_slot(map[i]);
else
val = 0xf;
val |= (i << 4);
err = snd_hda_codec_write(codec, pin_nid, 0,
AC_VERB_SET_HDMI_CHAN_SLOT, val);
if (err)
return -EINVAL;
}
return 0;
}
static void hdmi_setup_fake_chmap(unsigned char *map, int ca)
{
int i;
for (i = 0; i < 8; i++) {
if (i < channel_allocations[ca].channels)
map[i] = from_cea_slot((hdmi_channel_mapping[ca][i] >> 4) & 0x0f);
else
map[i] = 0;
}
}
static void hdmi_setup_channel_mapping(struct hda_codec *codec,
hda_nid_t pin_nid, bool non_pcm, int ca,
int channels, unsigned char *map)
{
if (!non_pcm && map) {
hdmi_manual_setup_channel_mapping(codec, pin_nid,
channels, map);
} else {
hdmi_std_setup_channel_mapping(codec, pin_nid, non_pcm, ca);
hdmi_setup_fake_chmap(map, ca);
}
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
printk(KERN_DEBUG "HDMI: ELD buf size is %d\n", size);
for (i = 0; i < 8; i++) {
size = snd_hda_codec_read(codec, pin_nid, 0,
AC_VERB_GET_HDMI_DIP_SIZE, i);
printk(KERN_DEBUG "HDMI: DIP GP[%d] buf size is %d\n", i, size);
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
snd_printd(KERN_INFO "dip index %d: %d != %d\n",
bi, pi, i);
if (bi == 0)
break;
}
snd_printd(KERN_INFO
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
static void hdmi_setup_audio_infoframe(struct hda_codec *codec, int pin_idx,
bool non_pcm,
struct snd_pcm_substream *substream)
{
struct hdmi_spec *spec = codec->spec;
struct hdmi_spec_per_pin *per_pin = &spec->pins[pin_idx];
hda_nid_t pin_nid = per_pin->pin_nid;
int channels = substream->runtime->channels;
struct hdmi_eld *eld;
int ca;
union audio_infoframe ai;
eld = &spec->pins[pin_idx].sink_eld;
if (!eld->monitor_present)
return;
if (!non_pcm && per_pin->chmap_set)
ca = hdmi_manual_channel_allocation(channels, per_pin->chmap);
else
ca = hdmi_channel_allocation(eld, channels);
if (ca < 0)
ca = 0;
memset(&ai, 0, sizeof(ai));
if (eld->conn_type == 0) {
struct hdmi_audio_infoframe *hdmi_ai = &ai.hdmi;
hdmi_ai->type = 0x84;
hdmi_ai->ver = 0x01;
hdmi_ai->len = 0x0a;
hdmi_ai->CC02_CT47 = channels - 1;
hdmi_ai->CA = ca;
hdmi_checksum_audio_infoframe(hdmi_ai);
} else if (eld->conn_type == 1) {
struct dp_audio_infoframe *dp_ai = &ai.dp;
dp_ai->type = 0x84;
dp_ai->len = 0x1b;
dp_ai->ver = 0x11 << 2;
dp_ai->CC02_CT47 = channels - 1;
dp_ai->CA = ca;
} else {
snd_printd("HDMI: unknown connection type at pin %d\n",
pin_nid);
return;
}
if (!hdmi_infoframe_uptodate(codec, pin_nid, ai.bytes,
sizeof(ai))) {
snd_printdd("hdmi_setup_audio_infoframe: "
"pin=%d channels=%d\n",
pin_nid,
channels);
hdmi_setup_channel_mapping(codec, pin_nid, non_pcm, ca,
channels, per_pin->chmap);
hdmi_stop_infoframe_trans(codec, pin_nid);
hdmi_fill_audio_infoframe(codec, pin_nid,
ai.bytes, sizeof(ai));
hdmi_start_infoframe_trans(codec, pin_nid);
} else {
if (per_pin->non_pcm != non_pcm)
hdmi_setup_channel_mapping(codec, pin_nid, non_pcm, ca,
channels, per_pin->chmap);
}
per_pin->non_pcm = non_pcm;
}
static void hdmi_intrinsic_event(struct hda_codec *codec, unsigned int res)
{
struct hdmi_spec *spec = codec->spec;
int tag = res >> AC_UNSOL_RES_TAG_SHIFT;
int pin_nid;
int pin_idx;
struct hda_jack_tbl *jack;
jack = snd_hda_jack_tbl_get_from_tag(codec, tag);
if (!jack)
return;
pin_nid = jack->nid;
jack->jack_dirty = 1;
_snd_printd(SND_PR_VERBOSE,
"HDMI hot plug event: Codec=%d Pin=%d Presence_Detect=%d ELD_Valid=%d\n",
codec->addr, pin_nid,
!!(res & AC_UNSOL_RES_PD), !!(res & AC_UNSOL_RES_ELDV));
pin_idx = pin_nid_to_pin_index(spec, pin_nid);
if (pin_idx < 0)
return;
hdmi_present_sense(&spec->pins[pin_idx], 1);
snd_hda_jack_report_sync(codec);
}
static void hdmi_non_intrinsic_event(struct hda_codec *codec, unsigned int res)
{
int tag = res >> AC_UNSOL_RES_TAG_SHIFT;
int subtag = (res & AC_UNSOL_RES_SUBTAG) >> AC_UNSOL_RES_SUBTAG_SHIFT;
int cp_state = !!(res & AC_UNSOL_RES_CP_STATE);
int cp_ready = !!(res & AC_UNSOL_RES_CP_READY);
printk(KERN_INFO
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
snd_printd(KERN_INFO "Unexpected HDMI event tag 0x%x\n", tag);
return;
}
if (subtag == 0)
hdmi_intrinsic_event(codec, res);
else
hdmi_non_intrinsic_event(codec, res);
}
static int hdmi_setup_stream(struct hda_codec *codec, hda_nid_t cvt_nid,
hda_nid_t pin_nid, u32 stream_tag, int format)
{
int pinctl;
int new_pinctl = 0;
if (snd_hda_query_pin_caps(codec, pin_nid) & AC_PINCAP_HBR) {
pinctl = snd_hda_codec_read(codec, pin_nid, 0,
AC_VERB_GET_PIN_WIDGET_CONTROL, 0);
new_pinctl = pinctl & ~AC_PINCTL_EPT;
if (is_hbr_format(format))
new_pinctl |= AC_PINCTL_EPT_HBR;
else
new_pinctl |= AC_PINCTL_EPT_NATIVE;
snd_printdd("hdmi_setup_stream: "
"NID=0x%x, %spinctl=0x%x\n",
pin_nid,
pinctl == new_pinctl ? "" : "new-",
new_pinctl);
if (pinctl != new_pinctl)
snd_hda_codec_write(codec, pin_nid, 0,
AC_VERB_SET_PIN_WIDGET_CONTROL,
new_pinctl);
}
if (is_hbr_format(format) && !new_pinctl) {
snd_printdd("hdmi_setup_stream: HBR is not supported\n");
return -EINVAL;
}
snd_hda_codec_setup_stream(codec, cvt_nid, stream_tag, 0, format);
return 0;
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
pin_idx = hinfo_to_pin_index(spec, hinfo);
if (snd_BUG_ON(pin_idx < 0))
return -EINVAL;
per_pin = &spec->pins[pin_idx];
eld = &per_pin->sink_eld;
for (cvt_idx = 0; cvt_idx < spec->num_cvts; cvt_idx++) {
per_cvt = &spec->cvts[cvt_idx];
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
per_cvt->assigned = 1;
hinfo->nid = per_cvt->cvt_nid;
snd_hda_codec_write(codec, per_pin->pin_nid, 0,
AC_VERB_SET_CONNECT_SEL,
mux_idx);
snd_hda_spdif_ctls_assign(codec, pin_idx, per_cvt->cvt_nid);
hinfo->channels_min = per_cvt->channels_min;
hinfo->channels_max = per_cvt->channels_max;
hinfo->rates = per_cvt->rates;
hinfo->formats = per_cvt->formats;
hinfo->maxbps = per_cvt->maxbps;
if (!static_hdmi_pcm && eld->eld_valid) {
snd_hdmi_eld_update_pcm_info(eld, hinfo);
if (hinfo->channels_min > hinfo->channels_max ||
!hinfo->rates || !hinfo->formats)
return -ENODEV;
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
struct hdmi_spec_per_pin *per_pin = &spec->pins[pin_idx];
hda_nid_t pin_nid = per_pin->pin_nid;
if (!(get_wcaps(codec, pin_nid) & AC_WCAP_CONN_LIST)) {
snd_printk(KERN_WARNING
"HDMI: pin %d wcaps %#x "
"does not support connection list\n",
pin_nid, get_wcaps(codec, pin_nid));
return -EINVAL;
}
per_pin->num_mux_nids = snd_hda_get_connections(codec, pin_nid,
per_pin->mux_nids,
HDA_MAX_CONNECTIONS);
return 0;
}
static void hdmi_present_sense(struct hdmi_spec_per_pin *per_pin, int repoll)
{
struct hda_codec *codec = per_pin->codec;
struct hdmi_eld *eld = &per_pin->sink_eld;
hda_nid_t pin_nid = per_pin->pin_nid;
int present = snd_hda_pin_sense(codec, pin_nid);
bool eld_valid = false;
memset(eld, 0, offsetof(struct hdmi_eld, eld_buffer));
eld->monitor_present = !!(present & AC_PINSENSE_PRESENCE);
if (eld->monitor_present)
eld_valid = !!(present & AC_PINSENSE_ELDV);
_snd_printd(SND_PR_VERBOSE,
"HDMI status: Codec=%d Pin=%d Presence_Detect=%d ELD_Valid=%d\n",
codec->addr, pin_nid, eld->monitor_present, eld_valid);
if (eld_valid) {
if (!snd_hdmi_get_eld(eld, codec, pin_nid))
snd_hdmi_show_eld(eld);
else if (repoll) {
queue_delayed_work(codec->bus->workq,
&per_pin->work,
msecs_to_jiffies(300));
}
}
}
static void hdmi_repoll_eld(struct work_struct *work)
{
struct hdmi_spec_per_pin *per_pin =
container_of(to_delayed_work(work), struct hdmi_spec_per_pin, work);
if (per_pin->repoll_count++ > 6)
per_pin->repoll_count = 0;
hdmi_present_sense(per_pin, per_pin->repoll_count);
}
static int hdmi_add_pin(struct hda_codec *codec, hda_nid_t pin_nid)
{
struct hdmi_spec *spec = codec->spec;
unsigned int caps, config;
int pin_idx;
struct hdmi_spec_per_pin *per_pin;
int err;
caps = snd_hda_param_read(codec, pin_nid, AC_PAR_PIN_CAP);
if (!(caps & (AC_PINCAP_HDMI | AC_PINCAP_DP)))
return 0;
config = snd_hda_codec_read(codec, pin_nid, 0,
AC_VERB_GET_CONFIG_DEFAULT, 0);
if (get_defcfg_connect(config) == AC_JACK_PORT_NONE)
return 0;
if (snd_BUG_ON(spec->num_pins >= MAX_HDMI_PINS))
return -E2BIG;
pin_idx = spec->num_pins;
per_pin = &spec->pins[pin_idx];
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
int cvt_idx;
struct hdmi_spec_per_cvt *per_cvt;
unsigned int chans;
int err;
if (snd_BUG_ON(spec->num_cvts >= MAX_HDMI_CVTS))
return -E2BIG;
chans = get_wcaps(codec, cvt_nid);
chans = get_wcaps_channels(chans);
cvt_idx = spec->num_cvts;
per_cvt = &spec->cvts[cvt_idx];
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
spec->num_cvts++;
return 0;
}
static int hdmi_parse_codec(struct hda_codec *codec)
{
hda_nid_t nid;
int i, nodes;
nodes = snd_hda_get_sub_nodes(codec, codec->afg, &nid);
if (!nid || nodes < 0) {
snd_printk(KERN_WARNING "HDMI: failed to get afg sub nodes\n");
return -EINVAL;
}
for (i = 0; i < nodes; i++, nid++) {
unsigned int caps;
unsigned int type;
caps = snd_hda_param_read(codec, nid, AC_PAR_AUDIO_WIDGET_CAP);
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
#ifdef CONFIG_PM
if (!(snd_hda_param_read(codec, codec->afg, AC_PAR_POWER_STATE) &
AC_PWRST_EPSS))
codec->bus->power_keep_link_on = 1;
#endif
return 0;
}
static char *get_hdmi_pcm_name(int idx)
{
static char names[MAX_HDMI_PINS][8];
sprintf(&names[idx][0], "HDMI %d", idx);
return &names[idx][0];
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
int pin_idx = hinfo_to_pin_index(spec, hinfo);
hda_nid_t pin_nid = spec->pins[pin_idx].pin_nid;
int pinctl;
bool non_pcm;
non_pcm = check_non_pcm_per_cvt(codec, cvt_nid);
hdmi_set_channel_count(codec, cvt_nid, substream->runtime->channels);
hdmi_setup_audio_infoframe(codec, pin_idx, non_pcm, substream);
pinctl = snd_hda_codec_read(codec, pin_nid, 0,
AC_VERB_GET_PIN_WIDGET_CONTROL, 0);
snd_hda_codec_write(codec, pin_nid, 0,
AC_VERB_SET_PIN_WIDGET_CONTROL, pinctl | PIN_OUT);
return hdmi_setup_stream(codec, cvt_nid, pin_nid, stream_tag, format);
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
cvt_idx = cvt_nid_to_cvt_index(spec, hinfo->nid);
if (snd_BUG_ON(cvt_idx < 0))
return -EINVAL;
per_cvt = &spec->cvts[cvt_idx];
snd_BUG_ON(!per_cvt->assigned);
per_cvt->assigned = 0;
hinfo->nid = 0;
pin_idx = hinfo_to_pin_index(spec, hinfo);
if (snd_BUG_ON(pin_idx < 0))
return -EINVAL;
per_pin = &spec->pins[pin_idx];
pinctl = snd_hda_codec_read(codec, per_pin->pin_nid, 0,
AC_VERB_GET_PIN_WIDGET_CONTROL, 0);
snd_hda_codec_write(codec, per_pin->pin_nid, 0,
AC_VERB_SET_PIN_WIDGET_CONTROL,
pinctl & ~PIN_OUT);
snd_hda_spdif_ctls_unassign(codec, pin_idx);
per_pin->chmap_set = false;
memset(per_pin->chmap, 0, sizeof(per_pin->chmap));
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
static int hdmi_chmap_ctl_tlv(struct snd_kcontrol *kcontrol, int op_flag,
unsigned int size, unsigned int __user *tlv)
{
struct snd_pcm_chmap *info = snd_kcontrol_chip(kcontrol);
struct hda_codec *codec = info->private_data;
struct hdmi_spec *spec = codec->spec;
const unsigned int valid_mask =
FL | FR | RL | RR | LFE | FC | RLC | RRC;
unsigned int __user *dst;
int chs, count = 0;
if (size < 8)
return -ENOMEM;
if (put_user(SNDRV_CTL_TLVT_CONTAINER, tlv))
return -EFAULT;
size -= 8;
dst = tlv + 2;
for (chs = 2; chs <= spec->channels_max; chs++) {
int i, c;
struct cea_channel_speaker_allocation *cap;
cap = channel_allocations;
for (i = 0; i < ARRAY_SIZE(channel_allocations); i++, cap++) {
int chs_bytes = chs * 4;
if (cap->channels != chs)
continue;
if (cap->spk_mask & ~valid_mask)
continue;
if (size < 8)
return -ENOMEM;
if (put_user(SNDRV_CTL_TLVT_CHMAP_VAR, dst) ||
put_user(chs_bytes, dst + 1))
return -EFAULT;
dst += 2;
size -= 8;
count += 8;
if (size < chs_bytes)
return -ENOMEM;
size -= chs_bytes;
count += chs_bytes;
for (c = 7; c >= 0; c--) {
int spk = cap->speakers[c];
if (!spk)
continue;
if (put_user(spk_to_chmap(spk), dst))
return -EFAULT;
dst++;
}
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
struct hdmi_spec_per_pin *per_pin = &spec->pins[pin_idx];
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
struct hdmi_spec_per_pin *per_pin = &spec->pins[pin_idx];
unsigned int ctl_idx;
struct snd_pcm_substream *substream;
unsigned char chmap[8];
int i, ca, prepared = 0;
ctl_idx = snd_ctl_get_ioffidx(kcontrol, &ucontrol->id);
substream = snd_pcm_chmap_substream(info, ctl_idx);
if (!substream || !substream->runtime)
return -EBADFD;
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
per_pin->chmap_set = true;
memcpy(per_pin->chmap, chmap, sizeof(chmap));
if (prepared)
hdmi_setup_audio_infoframe(codec, pin_idx, per_pin->non_pcm,
substream);
return 0;
}
static int generic_hdmi_build_pcms(struct hda_codec *codec)
{
struct hdmi_spec *spec = codec->spec;
int pin_idx;
for (pin_idx = 0; pin_idx < spec->num_pins; pin_idx++) {
struct hda_pcm *info;
struct hda_pcm_stream *pstr;
info = &spec->pcm_rec[pin_idx];
info->name = get_hdmi_pcm_name(pin_idx);
info->pcm_type = HDA_PCM_TYPE_HDMI;
info->own_chmap = true;
pstr = &info->stream[SNDRV_PCM_STREAM_PLAYBACK];
pstr->substreams = 1;
pstr->ops = generic_ops;
}
codec->num_pcms = spec->num_pins;
codec->pcm_info = spec->pcm_rec;
return 0;
}
static int generic_hdmi_build_jack(struct hda_codec *codec, int pin_idx)
{
char hdmi_str[32] = "HDMI/DP";
struct hdmi_spec *spec = codec->spec;
struct hdmi_spec_per_pin *per_pin = &spec->pins[pin_idx];
int pcmdev = spec->pcm_rec[pin_idx].device;
if (pcmdev > 0)
sprintf(hdmi_str + strlen(hdmi_str), ",pcm=%d", pcmdev);
return snd_hda_jack_add_kctl(codec, per_pin->pin_nid, hdmi_str, 0);
}
static int generic_hdmi_build_controls(struct hda_codec *codec)
{
struct hdmi_spec *spec = codec->spec;
int err;
int pin_idx;
for (pin_idx = 0; pin_idx < spec->num_pins; pin_idx++) {
struct hdmi_spec_per_pin *per_pin = &spec->pins[pin_idx];
err = generic_hdmi_build_jack(codec, pin_idx);
if (err < 0)
return err;
err = snd_hda_create_spdif_out_ctls(codec,
per_pin->pin_nid,
per_pin->mux_nids[0]);
if (err < 0)
return err;
snd_hda_spdif_ctls_unassign(codec, pin_idx);
err = hdmi_create_eld_ctl(codec,
pin_idx,
spec->pcm_rec[pin_idx].device);
if (err < 0)
return err;
hdmi_present_sense(per_pin, 0);
}
for (pin_idx = 0; pin_idx < spec->num_pins; pin_idx++) {
struct snd_pcm_chmap *chmap;
struct snd_kcontrol *kctl;
int i;
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
struct hdmi_spec_per_pin *per_pin = &spec->pins[pin_idx];
struct hdmi_eld *eld = &per_pin->sink_eld;
per_pin->codec = codec;
INIT_DELAYED_WORK(&per_pin->work, hdmi_repoll_eld);
snd_hda_eld_proc_new(codec, eld, pin_idx);
}
return 0;
}
static int generic_hdmi_init(struct hda_codec *codec)
{
struct hdmi_spec *spec = codec->spec;
int pin_idx;
for (pin_idx = 0; pin_idx < spec->num_pins; pin_idx++) {
struct hdmi_spec_per_pin *per_pin = &spec->pins[pin_idx];
hda_nid_t pin_nid = per_pin->pin_nid;
hdmi_init_pin(codec, pin_nid);
snd_hda_jack_detect_enable(codec, pin_nid, pin_nid);
}
return 0;
}
static void generic_hdmi_free(struct hda_codec *codec)
{
struct hdmi_spec *spec = codec->spec;
int pin_idx;
for (pin_idx = 0; pin_idx < spec->num_pins; pin_idx++) {
struct hdmi_spec_per_pin *per_pin = &spec->pins[pin_idx];
struct hdmi_eld *eld = &per_pin->sink_eld;
cancel_delayed_work(&per_pin->work);
snd_hda_eld_proc_free(codec, eld);
}
flush_workqueue(codec->bus->workq);
kfree(spec);
}
static int patch_generic_hdmi(struct hda_codec *codec)
{
struct hdmi_spec *spec;
spec = kzalloc(sizeof(*spec), GFP_KERNEL);
if (spec == NULL)
return -ENOMEM;
codec->spec = spec;
if (hdmi_parse_codec(codec) < 0) {
codec->spec = NULL;
kfree(spec);
return -EINVAL;
}
codec->patch_ops = generic_hdmi_patch_ops;
generic_hdmi_init_per_pins(codec);
init_channel_allocations();
return 0;
}
static int simple_playback_build_pcms(struct hda_codec *codec)
{
struct hdmi_spec *spec = codec->spec;
struct hda_pcm *info = spec->pcm_rec;
unsigned int chans;
struct hda_pcm_stream *pstr;
codec->num_pcms = 1;
codec->pcm_info = info;
chans = get_wcaps(codec, spec->cvts[0].cvt_nid);
chans = get_wcaps_channels(chans);
info->name = get_hdmi_pcm_name(0);
info->pcm_type = HDA_PCM_TYPE_HDMI;
pstr = &info->stream[SNDRV_PCM_STREAM_PLAYBACK];
*pstr = spec->pcm_playback;
pstr->nid = spec->cvts[0].cvt_nid;
if (pstr->channels_max <= 2 && chans && chans <= 16)
pstr->channels_max = chans;
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
int err;
err = snd_hda_create_spdif_out_ctls(codec,
spec->cvts[0].cvt_nid,
spec->cvts[0].cvt_nid);
if (err < 0)
return err;
return simple_hdmi_build_jack(codec, 0);
}
static int simple_playback_init(struct hda_codec *codec)
{
struct hdmi_spec *spec = codec->spec;
hda_nid_t pin = spec->pins[0].pin_nid;
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
spec = kzalloc(sizeof(*spec), GFP_KERNEL);
if (!spec)
return -ENOMEM;
codec->spec = spec;
spec->multiout.num_dacs = 0;
spec->multiout.max_channels = 2;
spec->multiout.dig_out_nid = cvt_nid;
spec->num_cvts = 1;
spec->num_pins = 1;
spec->cvts[0].cvt_nid = cvt_nid;
spec->pins[0].pin_nid = pin_nid;
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
mutex_lock(&codec->spdif_mutex);
spdif = snd_hda_spdif_out_of_nid(codec, spec->cvts[0].cvt_nid);
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
spec->pcm_rec[0].own_chmap = true;
return err;
}
static int nvhdmi_7x_8ch_build_controls(struct hda_codec *codec)
{
struct hdmi_spec *spec = codec->spec;
struct snd_pcm_chmap *chmap;
int err;
err = simple_playback_build_controls(codec);
if (err < 0)
return err;
err = snd_pcm_add_chmap_ctls(spec->pcm_rec[0].pcm,
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
static int atihdmi_playback_pcm_prepare(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
unsigned int stream_tag,
unsigned int format,
struct snd_pcm_substream *substream)
{
struct hdmi_spec *spec = codec->spec;
int chans = substream->runtime->channels;
int i, err;
err = simple_playback_pcm_prepare(hinfo, codec, stream_tag, format,
substream);
if (err < 0)
return err;
snd_hda_codec_write(codec, spec->cvts[0].cvt_nid, 0,
AC_VERB_SET_CVT_CHAN_COUNT, chans - 1);
for (i = 0; i < chans; i++) {
snd_hda_codec_write(codec, spec->cvts[0].cvt_nid, 0,
AC_VERB_SET_HDMI_CHAN_SLOT,
(i << 4) | i);
}
return 0;
}
static int patch_atihdmi(struct hda_codec *codec)
{
struct hdmi_spec *spec;
int err = patch_simple_hdmi(codec, ATIHDMI_CVT_NID, ATIHDMI_PIN_NID);
if (err < 0)
return err;
spec = codec->spec;
spec->pcm_playback.ops.prepare = atihdmi_playback_pcm_prepare;
return 0;
}
static int patch_via_hdmi(struct hda_codec *codec)
{
return patch_simple_hdmi(codec, VIAHDMI_CVT_NID, VIAHDMI_PIN_NID);
}
static int __init patch_hdmi_init(void)
{
return snd_hda_add_codec_preset(&intel_list);
}
static void __exit patch_hdmi_exit(void)
{
snd_hda_delete_codec_preset(&intel_list);
}
