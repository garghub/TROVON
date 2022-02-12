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
static void hdmi_setup_channel_mapping(struct hda_codec *codec,
hda_nid_t pin_nid,
int ca)
{
int i;
int err;
if (hdmi_channel_mapping[ca][1] == 0) {
for (i = 0; i < channel_allocations[ca].channels; i++)
hdmi_channel_mapping[ca][i] = i | (i << 4);
for (; i < 8; i++)
hdmi_channel_mapping[ca][i] = 0xf | (i << 4);
}
for (i = 0; i < 8; i++) {
err = snd_hda_codec_write(codec, pin_nid, 0,
AC_VERB_SET_HDMI_CHAN_SLOT,
hdmi_channel_mapping[ca][i]);
if (err) {
snd_printdd(KERN_NOTICE
"HDMI: channel mapping failed\n");
break;
}
}
hdmi_debug_channel_mapping(codec, pin_nid);
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
ca = hdmi_channel_allocation(eld, channels);
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
hdmi_setup_channel_mapping(codec, pin_nid, ca);
hdmi_stop_infoframe_trans(codec, pin_nid);
hdmi_fill_audio_infoframe(codec, pin_nid,
ai.bytes, sizeof(ai));
hdmi_start_infoframe_trans(codec, pin_nid);
}
}
static void hdmi_intrinsic_event(struct hda_codec *codec, unsigned int res)
{
struct hdmi_spec *spec = codec->spec;
int pin_nid = res >> AC_UNSOL_RES_TAG_SHIFT;
int pd = !!(res & AC_UNSOL_RES_PD);
int eldv = !!(res & AC_UNSOL_RES_ELDV);
int pin_idx;
printk(KERN_INFO
"HDMI hot plug event: Codec=%d Pin=%d Presence_Detect=%d ELD_Valid=%d\n",
codec->addr, pin_nid, pd, eldv);
pin_idx = pin_nid_to_pin_index(spec, pin_nid);
if (pin_idx < 0)
return;
hdmi_present_sense(&spec->pins[pin_idx], 1);
}
static void hdmi_non_intrinsic_event(struct hda_codec *codec, unsigned int res)
{
int tag = res >> AC_UNSOL_RES_TAG_SHIFT;
int subtag = (res & AC_UNSOL_RES_SUBTAG) >> AC_UNSOL_RES_SUBTAG_SHIFT;
int cp_state = !!(res & AC_UNSOL_RES_CP_STATE);
int cp_ready = !!(res & AC_UNSOL_RES_CP_READY);
printk(KERN_INFO
"HDMI CP event: CODEC=%d PIN=%d SUBTAG=0x%x CP_STATE=%d CP_READY=%d\n",
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
struct hdmi_spec *spec = codec->spec;
int tag = res >> AC_UNSOL_RES_TAG_SHIFT;
int subtag = (res & AC_UNSOL_RES_SUBTAG) >> AC_UNSOL_RES_SUBTAG_SHIFT;
if (pin_nid_to_pin_index(spec, tag) < 0) {
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
int pinctl;
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
pinctl = snd_hda_codec_read(codec, per_pin->pin_nid, 0,
AC_VERB_GET_PIN_WIDGET_CONTROL, 0);
snd_hda_codec_write(codec, per_pin->pin_nid, 0,
AC_VERB_SET_PIN_WIDGET_CONTROL,
pinctl | PIN_OUT);
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
printk(KERN_INFO
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
snd_hda_input_jack_report(codec, pin_nid);
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
if (chans <= 16)
per_cvt->channels_max = chans;
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
#ifdef CONFIG_SND_HDA_POWER_SAVE
if (!(snd_hda_param_read(codec, codec->afg, AC_PAR_POWER_STATE) &
AC_PWRST_EPSS))
codec->bus->power_keep_link_on = 1;
#endif
return 0;
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
hdmi_set_channel_count(codec, cvt_nid, substream->runtime->channels);
hdmi_setup_audio_infoframe(codec, pin_idx, substream);
return hdmi_setup_stream(codec, cvt_nid, pin_nid, stream_tag, format);
}
static int generic_hdmi_playback_pcm_cleanup(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
struct snd_pcm_substream *substream)
{
struct hdmi_spec *spec = codec->spec;
int cvt_idx, pin_idx;
struct hdmi_spec_per_cvt *per_cvt;
struct hdmi_spec_per_pin *per_pin;
int pinctl;
snd_hda_codec_cleanup_stream(codec, hinfo->nid);
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
}
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
info->name = generic_hdmi_pcm_names[pin_idx];
info->pcm_type = HDA_PCM_TYPE_HDMI;
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
int err;
char hdmi_str[32];
struct hdmi_spec *spec = codec->spec;
struct hdmi_spec_per_pin *per_pin = &spec->pins[pin_idx];
int pcmdev = spec->pcm_rec[pin_idx].device;
snprintf(hdmi_str, sizeof(hdmi_str), "HDMI/DP,pcm=%d", pcmdev);
err = snd_hda_input_jack_add(codec, per_pin->pin_nid,
SND_JACK_VIDEOOUT, pcmdev > 0 ? hdmi_str : NULL);
if (err < 0)
return err;
hdmi_present_sense(per_pin, 0);
return 0;
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
struct hdmi_eld *eld = &per_pin->sink_eld;
hdmi_init_pin(codec, pin_nid);
snd_hda_codec_write(codec, pin_nid, 0,
AC_VERB_SET_UNSOLICITED_ENABLE,
AC_USRSP_EN | pin_nid);
per_pin->codec = codec;
INIT_DELAYED_WORK(&per_pin->work, hdmi_repoll_eld);
snd_hda_eld_proc_new(codec, eld, pin_idx);
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
snd_hda_input_jack_free(codec);
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
init_channel_allocations();
return 0;
}
static int simple_playback_build_pcms(struct hda_codec *codec)
{
struct hdmi_spec *spec = codec->spec;
struct hda_pcm *info = spec->pcm_rec;
int i;
codec->num_pcms = spec->num_cvts;
codec->pcm_info = info;
for (i = 0; i < codec->num_pcms; i++, info++) {
unsigned int chans;
struct hda_pcm_stream *pstr;
chans = get_wcaps(codec, spec->cvts[i].cvt_nid);
chans = get_wcaps_channels(chans);
info->name = generic_hdmi_pcm_names[i];
info->pcm_type = HDA_PCM_TYPE_HDMI;
pstr = &info->stream[SNDRV_PCM_STREAM_PLAYBACK];
snd_BUG_ON(!spec->pcm_playback);
*pstr = *spec->pcm_playback;
pstr->nid = spec->cvts[i].cvt_nid;
if (pstr->channels_max <= 2 && chans && chans <= 16)
pstr->channels_max = chans;
}
return 0;
}
static int simple_playback_build_controls(struct hda_codec *codec)
{
struct hdmi_spec *spec = codec->spec;
int err;
int i;
for (i = 0; i < codec->num_pcms; i++) {
err = snd_hda_create_spdif_out_ctls(codec,
spec->cvts[i].cvt_nid,
spec->cvts[i].cvt_nid);
if (err < 0)
return err;
}
return 0;
}
static void simple_playback_free(struct hda_codec *codec)
{
struct hdmi_spec *spec = codec->spec;
kfree(spec);
}
static int nvhdmi_7x_init(struct hda_codec *codec)
{
snd_hda_sequence_write(codec, nvhdmi_basic_init_7x);
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
struct hda_spdif_out *spdif =
snd_hda_spdif_out_of_nid(codec, spec->cvts[0].cvt_nid);
mutex_lock(&codec->spdif_mutex);
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
spec = kzalloc(sizeof(*spec), GFP_KERNEL);
if (spec == NULL)
return -ENOMEM;
codec->spec = spec;
spec->multiout.num_dacs = 0;
spec->multiout.max_channels = 2;
spec->multiout.dig_out_nid = nvhdmi_master_con_nid_7x;
spec->num_cvts = 1;
spec->cvts[0].cvt_nid = nvhdmi_master_con_nid_7x;
spec->pcm_playback = &nvhdmi_pcm_playback_2ch;
codec->patch_ops = nvhdmi_patch_ops_2ch;
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
spec->pcm_playback = &nvhdmi_pcm_playback_8ch_7x;
codec->patch_ops = nvhdmi_patch_ops_8ch_7x;
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
static int atihdmi_init(struct hda_codec *codec)
{
struct hdmi_spec *spec = codec->spec;
snd_hda_sequence_write(codec, atihdmi_basic_init);
if (get_wcaps(codec, spec->pins[0].pin_nid) & AC_WCAP_OUT_AMP)
snd_hda_codec_write(codec, spec->pins[0].pin_nid, 0,
AC_VERB_SET_AMP_GAIN_MUTE,
AMP_OUT_UNMUTE);
return 0;
}
static int patch_atihdmi(struct hda_codec *codec)
{
struct hdmi_spec *spec;
spec = kzalloc(sizeof(*spec), GFP_KERNEL);
if (spec == NULL)
return -ENOMEM;
codec->spec = spec;
spec->multiout.num_dacs = 0;
spec->multiout.max_channels = 2;
spec->multiout.dig_out_nid = ATIHDMI_CVT_NID;
spec->num_cvts = 1;
spec->cvts[0].cvt_nid = ATIHDMI_CVT_NID;
spec->pins[0].pin_nid = ATIHDMI_PIN_NID;
spec->pcm_playback = &atihdmi_pcm_digital_playback;
codec->patch_ops = atihdmi_patch_ops;
return 0;
}
static int __init patch_hdmi_init(void)
{
return snd_hda_add_codec_preset(&intel_list);
}
static void __exit patch_hdmi_exit(void)
{
snd_hda_delete_codec_preset(&intel_list);
}
