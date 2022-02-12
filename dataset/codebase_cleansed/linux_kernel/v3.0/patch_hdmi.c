static int hda_node_index(hda_nid_t *nids, hda_nid_t nid)
{
int i;
for (i = 0; nids[i]; i++)
if (nids[i] == nid)
return i;
snd_printk(KERN_WARNING "HDMI: nid %d not registered\n", nid);
return -EINVAL;
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
static void hdmi_enable_output(struct hda_codec *codec, hda_nid_t pin_nid)
{
if (get_wcaps(codec, pin_nid) & AC_WCAP_OUT_AMP)
snd_hda_codec_write(codec, pin_nid, 0,
AC_VERB_SET_AMP_GAIN_MUTE, AMP_OUT_UNMUTE);
snd_hda_codec_write(codec, pin_nid, 0,
AC_VERB_SET_PIN_WIDGET_CONTROL, PIN_OUT);
}
static int hdmi_get_channel_count(struct hda_codec *codec, hda_nid_t nid)
{
return 1 + snd_hda_codec_read(codec, nid, 0,
AC_VERB_GET_CVT_CHAN_COUNT, 0);
}
static void hdmi_set_channel_count(struct hda_codec *codec,
hda_nid_t nid, int chs)
{
if (chs != hdmi_get_channel_count(codec, nid))
snd_hda_codec_write(codec, nid, 0,
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
static int hdmi_channel_allocation(struct hda_codec *codec, hda_nid_t nid,
int channels)
{
struct hdmi_spec *spec = codec->spec;
struct hdmi_eld *eld;
int i;
int ca = 0;
int spk_mask = 0;
char buf[SND_PRINT_CHANNEL_ALLOCATION_ADVISED_BUFSIZE];
if (channels <= 2)
return 0;
i = hda_node_index(spec->pin_cvt, nid);
if (i < 0)
return 0;
eld = &spec->sink_eld[i];
if (!eld->spk_alloc)
eld->spk_alloc = 0xffff;
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
static void hdmi_setup_audio_infoframe(struct hda_codec *codec, hda_nid_t nid,
struct snd_pcm_substream *substream)
{
struct hdmi_spec *spec = codec->spec;
hda_nid_t pin_nid;
int channels = substream->runtime->channels;
int ca;
int i;
union audio_infoframe ai;
ca = hdmi_channel_allocation(codec, nid, channels);
for (i = 0; i < spec->num_pins; i++) {
if (spec->pin_cvt[i] != nid)
continue;
if (!spec->sink_eld[i].monitor_present)
continue;
pin_nid = spec->pin[i];
memset(&ai, 0, sizeof(ai));
if (spec->sink_eld[i].conn_type == 0) {
struct hdmi_audio_infoframe *hdmi_ai = &ai.hdmi;
hdmi_ai->type = 0x84;
hdmi_ai->ver = 0x01;
hdmi_ai->len = 0x0a;
hdmi_ai->CC02_CT47 = channels - 1;
hdmi_ai->CA = ca;
hdmi_checksum_audio_infoframe(hdmi_ai);
} else if (spec->sink_eld[i].conn_type == 1) {
struct dp_audio_infoframe *dp_ai = &ai.dp;
dp_ai->type = 0x84;
dp_ai->len = 0x1b;
dp_ai->ver = 0x11 << 2;
dp_ai->CC02_CT47 = channels - 1;
dp_ai->CA = ca;
} else {
snd_printd("HDMI: unknown connection type at pin %d\n",
pin_nid);
continue;
}
if (!hdmi_infoframe_uptodate(codec, pin_nid, ai.bytes,
sizeof(ai))) {
snd_printdd("hdmi_setup_audio_infoframe: "
"cvt=%d pin=%d channels=%d\n",
nid, pin_nid,
channels);
hdmi_setup_channel_mapping(codec, pin_nid, ca);
hdmi_stop_infoframe_trans(codec, pin_nid);
hdmi_fill_audio_infoframe(codec, pin_nid,
ai.bytes, sizeof(ai));
hdmi_start_infoframe_trans(codec, pin_nid);
}
}
}
static void hdmi_intrinsic_event(struct hda_codec *codec, unsigned int res)
{
struct hdmi_spec *spec = codec->spec;
int pin_nid = res >> AC_UNSOL_RES_TAG_SHIFT;
int pd = !!(res & AC_UNSOL_RES_PD);
int eldv = !!(res & AC_UNSOL_RES_ELDV);
int index;
printk(KERN_INFO
"HDMI hot plug event: Pin=%d Presence_Detect=%d ELD_Valid=%d\n",
pin_nid, pd, eldv);
index = hda_node_index(spec->pin, pin_nid);
if (index < 0)
return;
hdmi_present_sense(codec, pin_nid, &spec->sink_eld[index]);
}
static void hdmi_non_intrinsic_event(struct hda_codec *codec, unsigned int res)
{
int tag = res >> AC_UNSOL_RES_TAG_SHIFT;
int subtag = (res & AC_UNSOL_RES_SUBTAG) >> AC_UNSOL_RES_SUBTAG_SHIFT;
int cp_state = !!(res & AC_UNSOL_RES_CP_STATE);
int cp_ready = !!(res & AC_UNSOL_RES_CP_READY);
printk(KERN_INFO
"HDMI CP event: PIN=%d SUBTAG=0x%x CP_STATE=%d CP_READY=%d\n",
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
if (hda_node_index(spec->pin, tag) < 0) {
snd_printd(KERN_INFO "Unexpected HDMI event tag 0x%x\n", tag);
return;
}
if (subtag == 0)
hdmi_intrinsic_event(codec, res);
else
hdmi_non_intrinsic_event(codec, res);
}
static int hdmi_setup_stream(struct hda_codec *codec, hda_nid_t nid,
u32 stream_tag, int format)
{
struct hdmi_spec *spec = codec->spec;
int pinctl;
int new_pinctl = 0;
int i;
for (i = 0; i < spec->num_pins; i++) {
if (spec->pin_cvt[i] != nid)
continue;
if (!(snd_hda_query_pin_caps(codec, spec->pin[i]) & AC_PINCAP_HBR))
continue;
pinctl = snd_hda_codec_read(codec, spec->pin[i], 0,
AC_VERB_GET_PIN_WIDGET_CONTROL, 0);
new_pinctl = pinctl & ~AC_PINCTL_EPT;
if (is_hbr_format(format))
new_pinctl |= AC_PINCTL_EPT_HBR;
else
new_pinctl |= AC_PINCTL_EPT_NATIVE;
snd_printdd("hdmi_setup_stream: "
"NID=0x%x, %spinctl=0x%x\n",
spec->pin[i],
pinctl == new_pinctl ? "" : "new-",
new_pinctl);
if (pinctl != new_pinctl)
snd_hda_codec_write(codec, spec->pin[i], 0,
AC_VERB_SET_PIN_WIDGET_CONTROL,
new_pinctl);
}
if (is_hbr_format(format) && !new_pinctl) {
snd_printdd("hdmi_setup_stream: HBR is not supported\n");
return -EINVAL;
}
snd_hda_codec_setup_stream(codec, nid, stream_tag, 0, format);
return 0;
}
static int hdmi_pcm_open(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
struct snd_pcm_substream *substream)
{
struct hdmi_spec *spec = codec->spec;
struct hdmi_eld *eld;
struct hda_pcm_stream *codec_pars;
struct snd_pcm_runtime *runtime = substream->runtime;
unsigned int idx;
for (idx = 0; idx < spec->num_cvts; idx++)
if (hinfo->nid == spec->cvt[idx])
break;
if (snd_BUG_ON(idx >= spec->num_cvts) ||
snd_BUG_ON(idx >= spec->num_pins))
return -EINVAL;
codec_pars = &spec->codec_pcm_pars[idx];
if (!codec_pars->rates)
*codec_pars = *hinfo;
eld = &spec->sink_eld[idx];
if (!static_hdmi_pcm && eld->eld_valid && eld->sad_count > 0) {
hdmi_eld_update_pcm_info(eld, hinfo, codec_pars);
if (hinfo->channels_min > hinfo->channels_max ||
!hinfo->rates || !hinfo->formats)
return -ENODEV;
} else {
hinfo->channels_max = codec_pars->channels_max;
hinfo->rates = codec_pars->rates;
hinfo->formats = codec_pars->formats;
hinfo->maxbps = codec_pars->maxbps;
}
runtime->hw.channels_min = hinfo->channels_min;
runtime->hw.channels_max = hinfo->channels_max;
runtime->hw.formats = hinfo->formats;
runtime->hw.rates = hinfo->rates;
snd_pcm_hw_constraint_step(substream->runtime, 0,
SNDRV_PCM_HW_PARAM_CHANNELS, 2);
return 0;
}
static int hdmi_read_pin_conn(struct hda_codec *codec, hda_nid_t pin_nid)
{
struct hdmi_spec *spec = codec->spec;
hda_nid_t conn_list[HDA_MAX_CONNECTIONS];
int conn_len, curr;
int index;
if (!(get_wcaps(codec, pin_nid) & AC_WCAP_CONN_LIST)) {
snd_printk(KERN_WARNING
"HDMI: pin %d wcaps %#x "
"does not support connection list\n",
pin_nid, get_wcaps(codec, pin_nid));
return -EINVAL;
}
conn_len = snd_hda_get_connections(codec, pin_nid, conn_list,
HDA_MAX_CONNECTIONS);
if (conn_len > 1)
curr = snd_hda_codec_read(codec, pin_nid, 0,
AC_VERB_GET_CONNECT_SEL, 0);
else
curr = 0;
index = hda_node_index(spec->pin, pin_nid);
if (index < 0)
return -EINVAL;
spec->pin_cvt[index] = conn_list[curr];
return 0;
}
static void hdmi_present_sense(struct hda_codec *codec, hda_nid_t pin_nid,
struct hdmi_eld *eld)
{
int present = snd_hda_pin_sense(codec, pin_nid);
memset(eld, 0, sizeof(*eld));
eld->monitor_present = !!(present & AC_PINSENSE_PRESENCE);
if (eld->monitor_present)
eld->eld_valid = !!(present & AC_PINSENSE_ELDV);
else
eld->eld_valid = 0;
printk(KERN_INFO
"HDMI status: Pin=%d Presence_Detect=%d ELD_Valid=%d\n",
pin_nid, eld->monitor_present, eld->eld_valid);
if (eld->eld_valid)
if (!snd_hdmi_get_eld(eld, codec, pin_nid))
snd_hdmi_show_eld(eld);
snd_hda_input_jack_report(codec, pin_nid);
}
static int hdmi_add_pin(struct hda_codec *codec, hda_nid_t pin_nid)
{
struct hdmi_spec *spec = codec->spec;
int err;
if (spec->num_pins >= MAX_HDMI_PINS) {
snd_printk(KERN_WARNING
"HDMI: no space for pin %d\n", pin_nid);
return -E2BIG;
}
err = snd_hda_input_jack_add(codec, pin_nid,
SND_JACK_VIDEOOUT, NULL);
if (err < 0)
return err;
hdmi_present_sense(codec, pin_nid, &spec->sink_eld[spec->num_pins]);
spec->pin[spec->num_pins] = pin_nid;
spec->num_pins++;
return hdmi_read_pin_conn(codec, pin_nid);
}
static int hdmi_add_cvt(struct hda_codec *codec, hda_nid_t nid)
{
int i, found_pin = 0;
struct hdmi_spec *spec = codec->spec;
for (i = 0; i < spec->num_pins; i++)
if (nid == spec->pin_cvt[i]) {
found_pin = 1;
break;
}
if (!found_pin) {
snd_printdd("HDMI: Skipping node %d (no connection)\n", nid);
return -EINVAL;
}
if (snd_BUG_ON(spec->num_cvts >= MAX_HDMI_CVTS))
return -E2BIG;
spec->cvt[spec->num_cvts] = nid;
spec->num_cvts++;
return 0;
}
static int hdmi_parse_codec(struct hda_codec *codec)
{
hda_nid_t nid;
int i, nodes;
int num_tmp_cvts = 0;
hda_nid_t tmp_cvt[MAX_HDMI_CVTS];
nodes = snd_hda_get_sub_nodes(codec, codec->afg, &nid);
if (!nid || nodes < 0) {
snd_printk(KERN_WARNING "HDMI: failed to get afg sub nodes\n");
return -EINVAL;
}
for (i = 0; i < nodes; i++, nid++) {
unsigned int caps;
unsigned int type;
unsigned int config;
caps = snd_hda_param_read(codec, nid, AC_PAR_AUDIO_WIDGET_CAP);
type = get_wcaps_type(caps);
if (!(caps & AC_WCAP_DIGITAL))
continue;
switch (type) {
case AC_WID_AUD_OUT:
if (num_tmp_cvts >= MAX_HDMI_CVTS) {
snd_printk(KERN_WARNING
"HDMI: no space for converter %d\n", nid);
continue;
}
tmp_cvt[num_tmp_cvts] = nid;
num_tmp_cvts++;
break;
case AC_WID_PIN:
caps = snd_hda_param_read(codec, nid, AC_PAR_PIN_CAP);
if (!(caps & (AC_PINCAP_HDMI | AC_PINCAP_DP)))
continue;
config = snd_hda_codec_read(codec, nid, 0,
AC_VERB_GET_CONFIG_DEFAULT, 0);
if (get_defcfg_connect(config) == AC_JACK_PORT_NONE)
continue;
hdmi_add_pin(codec, nid);
break;
}
}
for (i = 0; i < num_tmp_cvts; i++)
hdmi_add_cvt(codec, tmp_cvt[i]);
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
hdmi_set_channel_count(codec, hinfo->nid,
substream->runtime->channels);
hdmi_setup_audio_infoframe(codec, hinfo->nid, substream);
return hdmi_setup_stream(codec, hinfo->nid, stream_tag, format);
}
static int generic_hdmi_build_pcms(struct hda_codec *codec)
{
struct hdmi_spec *spec = codec->spec;
struct hda_pcm *info = spec->pcm_rec;
int i;
codec->num_pcms = spec->num_cvts;
codec->pcm_info = info;
for (i = 0; i < codec->num_pcms; i++, info++) {
unsigned int chans;
struct hda_pcm_stream *pstr;
chans = get_wcaps(codec, spec->cvt[i]);
chans = get_wcaps_channels(chans);
info->name = generic_hdmi_pcm_names[i];
info->pcm_type = HDA_PCM_TYPE_HDMI;
pstr = &info->stream[SNDRV_PCM_STREAM_PLAYBACK];
if (spec->pcm_playback)
*pstr = *spec->pcm_playback;
else
*pstr = generic_hdmi_pcm_playback;
pstr->nid = spec->cvt[i];
if (pstr->channels_max <= 2 && chans && chans <= 16)
pstr->channels_max = chans;
}
return 0;
}
static int generic_hdmi_build_controls(struct hda_codec *codec)
{
struct hdmi_spec *spec = codec->spec;
int err;
int i;
for (i = 0; i < codec->num_pcms; i++) {
err = snd_hda_create_spdif_out_ctls(codec, spec->cvt[i]);
if (err < 0)
return err;
}
return 0;
}
static int generic_hdmi_init(struct hda_codec *codec)
{
struct hdmi_spec *spec = codec->spec;
int i;
for (i = 0; spec->pin[i]; i++) {
hdmi_enable_output(codec, spec->pin[i]);
snd_hda_codec_write(codec, spec->pin[i], 0,
AC_VERB_SET_UNSOLICITED_ENABLE,
AC_USRSP_EN | spec->pin[i]);
}
return 0;
}
static void generic_hdmi_free(struct hda_codec *codec)
{
struct hdmi_spec *spec = codec->spec;
int i;
for (i = 0; i < spec->num_pins; i++)
snd_hda_eld_proc_free(codec, &spec->sink_eld[i]);
snd_hda_input_jack_free(codec);
kfree(spec);
}
static int patch_generic_hdmi(struct hda_codec *codec)
{
struct hdmi_spec *spec;
int i;
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
for (i = 0; i < spec->num_pins; i++)
snd_hda_eld_proc_new(codec, &spec->sink_eld[i], i);
init_channel_allocations();
return 0;
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
unsigned int dataDCC1, dataDCC2, channel_id;
int i;
mutex_lock(&codec->spdif_mutex);
chs = substream->runtime->channels;
dataDCC1 = AC_DIG1_ENABLE | AC_DIG1_COPYRIGHT;
dataDCC2 = 0x2;
if (codec->spdif_status_reset && (codec->spdif_ctls & AC_DIG1_ENABLE))
snd_hda_codec_write(codec,
nvhdmi_master_con_nid_7x,
0,
AC_VERB_SET_DIGI_CONVERT_1,
codec->spdif_ctls & ~AC_DIG1_ENABLE & 0xff);
snd_hda_codec_write(codec, nvhdmi_master_con_nid_7x, 0,
AC_VERB_SET_CHANNEL_STREAMID, (stream_tag << 4) | 0x0);
snd_hda_codec_write(codec, nvhdmi_master_con_nid_7x, 0,
AC_VERB_SET_STREAM_FORMAT, format);
if (codec->spdif_status_reset && (codec->spdif_ctls & AC_DIG1_ENABLE)) {
snd_hda_codec_write(codec,
nvhdmi_master_con_nid_7x,
0,
AC_VERB_SET_DIGI_CONVERT_1,
codec->spdif_ctls & 0xff);
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
(codec->spdif_ctls & AC_DIG1_ENABLE))
snd_hda_codec_write(codec,
nvhdmi_con_nids_7x[i],
0,
AC_VERB_SET_DIGI_CONVERT_1,
codec->spdif_ctls & ~AC_DIG1_ENABLE & 0xff);
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
(codec->spdif_ctls & AC_DIG1_ENABLE)) {
snd_hda_codec_write(codec,
nvhdmi_con_nids_7x[i],
0,
AC_VERB_SET_DIGI_CONVERT_1,
codec->spdif_ctls & 0xff);
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
spec->cvt[0] = nvhdmi_master_con_nid_7x;
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
snd_hda_codec_write(codec, spec->cvt[0], 0, AC_VERB_SET_CVT_CHAN_COUNT,
chans - 1);
for (i = 0; i < chans; i++) {
snd_hda_codec_write(codec, spec->cvt[0], 0,
AC_VERB_SET_HDMI_CHAN_SLOT,
(i << 4) | i);
}
return 0;
}
static int atihdmi_init(struct hda_codec *codec)
{
struct hdmi_spec *spec = codec->spec;
snd_hda_sequence_write(codec, atihdmi_basic_init);
if (get_wcaps(codec, spec->pin[0]) & AC_WCAP_OUT_AMP)
snd_hda_codec_write(codec, spec->pin[0], 0,
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
spec->cvt[0] = ATIHDMI_CVT_NID;
spec->pin[0] = ATIHDMI_PIN_NID;
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
