static u32 ps3av_cs_video2av(int cs)
{
unsigned int i;
for (i = 0; i < ARRAY_SIZE(ps3av_cs_video2av_table); i++)
if (ps3av_cs_video2av_table[i].cs == cs)
return ps3av_cs_video2av_table[i].av;
return PS3AV_CMD_AV_CS_RGB_8;
}
static u32 ps3av_cs_video2av_bitlen(int cs)
{
unsigned int i;
for (i = 0; i < ARRAY_SIZE(ps3av_cs_video2av_table); i++)
if (ps3av_cs_video2av_table[i].cs == cs)
return ps3av_cs_video2av_table[i].bl;
return PS3AV_CMD_AV_CS_8;
}
static u32 ps3av_vid_video2av(int vid)
{
unsigned int i;
for (i = 0; i < ARRAY_SIZE(ps3av_vid_video2av_table); i++)
if (ps3av_vid_video2av_table[i].vid == vid)
return ps3av_vid_video2av_table[i].av;
return PS3AV_CMD_AV_VID_480P;
}
static int ps3av_hdmi_range(void)
{
if (ps3_compare_firmware_version(1, 8, 0) < 0)
return 0;
else
return 1;
}
int ps3av_cmd_init(void)
{
int res;
struct ps3av_pkt_av_init av_init;
struct ps3av_pkt_video_init video_init;
struct ps3av_pkt_audio_init audio_init;
memset(&video_init, 0, sizeof(video_init));
res = ps3av_do_pkt(PS3AV_CID_VIDEO_INIT, sizeof(video_init.send_hdr),
sizeof(video_init), &video_init.send_hdr);
if (res < 0)
return res;
res = get_status(&video_init);
if (res) {
printk(KERN_ERR "PS3AV_CID_VIDEO_INIT: failed %x\n", res);
return res;
}
memset(&audio_init, 0, sizeof(audio_init));
res = ps3av_do_pkt(PS3AV_CID_AUDIO_INIT, sizeof(audio_init.send_hdr),
sizeof(audio_init), &audio_init.send_hdr);
if (res < 0)
return res;
res = get_status(&audio_init);
if (res) {
printk(KERN_ERR "PS3AV_CID_AUDIO_INIT: failed %x\n", res);
return res;
}
memset(&av_init, 0, sizeof(av_init));
av_init.event_bit = 0;
res = ps3av_do_pkt(PS3AV_CID_AV_INIT, sizeof(av_init), sizeof(av_init),
&av_init.send_hdr);
if (res < 0)
return res;
res = get_status(&av_init);
if (res)
printk(KERN_ERR "PS3AV_CID_AV_INIT: failed %x\n", res);
return res;
}
int ps3av_cmd_fin(void)
{
int res;
struct ps3av_pkt_av_fin av_fin;
memset(&av_fin, 0, sizeof(av_fin));
res = ps3av_do_pkt(PS3AV_CID_AV_FIN, sizeof(av_fin.send_hdr),
sizeof(av_fin), &av_fin.send_hdr);
if (res < 0)
return res;
res = get_status(&av_fin);
if (res)
printk(KERN_ERR "PS3AV_CID_AV_FIN: failed %x\n", res);
return res;
}
int ps3av_cmd_av_video_mute(int num_of_port, u32 *port, u32 mute)
{
int i, send_len, res;
struct ps3av_pkt_av_video_mute av_video_mute;
if (num_of_port > PS3AV_MUTE_PORT_MAX)
return -EINVAL;
memset(&av_video_mute, 0, sizeof(av_video_mute));
for (i = 0; i < num_of_port; i++) {
av_video_mute.mute[i].avport = port[i];
av_video_mute.mute[i].mute = mute;
}
send_len = sizeof(av_video_mute.send_hdr) +
sizeof(struct ps3av_av_mute) * num_of_port;
res = ps3av_do_pkt(PS3AV_CID_AV_VIDEO_MUTE, send_len,
sizeof(av_video_mute), &av_video_mute.send_hdr);
if (res < 0)
return res;
res = get_status(&av_video_mute);
if (res)
printk(KERN_ERR "PS3AV_CID_AV_VIDEO_MUTE: failed %x\n", res);
return res;
}
int ps3av_cmd_av_video_disable_sig(u32 port)
{
int res;
struct ps3av_pkt_av_video_disable_sig av_video_sig;
memset(&av_video_sig, 0, sizeof(av_video_sig));
av_video_sig.avport = port;
res = ps3av_do_pkt(PS3AV_CID_AV_VIDEO_DISABLE_SIG,
sizeof(av_video_sig), sizeof(av_video_sig),
&av_video_sig.send_hdr);
if (res < 0)
return res;
res = get_status(&av_video_sig);
if (res)
printk(KERN_ERR
"PS3AV_CID_AV_VIDEO_DISABLE_SIG: failed %x port:%x\n",
res, port);
return res;
}
int ps3av_cmd_av_tv_mute(u32 avport, u32 mute)
{
int res;
struct ps3av_pkt_av_tv_mute tv_mute;
memset(&tv_mute, 0, sizeof(tv_mute));
tv_mute.avport = avport;
tv_mute.mute = mute;
res = ps3av_do_pkt(PS3AV_CID_AV_TV_MUTE, sizeof(tv_mute),
sizeof(tv_mute), &tv_mute.send_hdr);
if (res < 0)
return res;
res = get_status(&tv_mute);
if (res)
printk(KERN_ERR "PS3AV_CID_AV_TV_MUTE: failed %x port:%x\n",
res, avport);
return res;
}
int ps3av_cmd_enable_event(void)
{
int res;
struct ps3av_pkt_av_event av_event;
memset(&av_event, 0, sizeof(av_event));
av_event.event_bit = PS3AV_CMD_EVENT_BIT_UNPLUGGED |
PS3AV_CMD_EVENT_BIT_PLUGGED | PS3AV_CMD_EVENT_BIT_HDCP_DONE;
res = ps3av_do_pkt(PS3AV_CID_AV_ENABLE_EVENT, sizeof(av_event),
sizeof(av_event), &av_event.send_hdr);
if (res < 0)
return res;
res = get_status(&av_event);
if (res)
printk(KERN_ERR "PS3AV_CID_AV_ENABLE_EVENT: failed %x\n", res);
return res;
}
int ps3av_cmd_av_hdmi_mode(u8 mode)
{
int res;
struct ps3av_pkt_av_hdmi_mode hdmi_mode;
memset(&hdmi_mode, 0, sizeof(hdmi_mode));
hdmi_mode.mode = mode;
res = ps3av_do_pkt(PS3AV_CID_AV_HDMI_MODE, sizeof(hdmi_mode),
sizeof(hdmi_mode), &hdmi_mode.send_hdr);
if (res < 0)
return res;
res = get_status(&hdmi_mode);
if (res && res != PS3AV_STATUS_UNSUPPORTED_HDMI_MODE)
printk(KERN_ERR "PS3AV_CID_AV_HDMI_MODE: failed %x\n", res);
return res;
}
u32 ps3av_cmd_set_av_video_cs(void *p, u32 avport, int video_vid, int cs_out,
int aspect, u32 id)
{
struct ps3av_pkt_av_video_cs *av_video_cs;
av_video_cs = (struct ps3av_pkt_av_video_cs *)p;
if (video_vid == -1)
video_vid = PS3AV_CMD_VIDEO_VID_720P_60HZ;
if (cs_out == -1)
cs_out = PS3AV_CMD_VIDEO_CS_YUV444_8;
if (aspect == -1)
aspect = 0;
memset(av_video_cs, 0, sizeof(*av_video_cs));
ps3av_set_hdr(PS3AV_CID_AV_VIDEO_CS, sizeof(*av_video_cs),
&av_video_cs->send_hdr);
av_video_cs->avport = avport;
av_video_cs->av_vid = ps3av_vid_video2av(video_vid);
av_video_cs->av_cs_out = ps3av_cs_video2av(cs_out);
av_video_cs->av_cs_in = ps3av_cs_video2av(PS3AV_CMD_VIDEO_CS_RGB_8);
av_video_cs->bitlen_out = ps3av_cs_video2av_bitlen(cs_out);
if ((id & PS3AV_MODE_WHITE) && ps3av_hdmi_range())
av_video_cs->super_white = PS3AV_CMD_AV_SUPER_WHITE_ON;
else
av_video_cs->super_white = PS3AV_CMD_AV_SUPER_WHITE_OFF;
av_video_cs->aspect = aspect;
if (id & PS3AV_MODE_DITHER) {
av_video_cs->dither = PS3AV_CMD_AV_DITHER_ON
| PS3AV_CMD_AV_DITHER_8BIT;
} else {
av_video_cs->dither = PS3AV_CMD_AV_DITHER_OFF;
}
return sizeof(*av_video_cs);
}
u32 ps3av_cmd_set_video_mode(void *p, u32 head, int video_vid, int video_fmt,
u32 id)
{
struct ps3av_pkt_video_mode *video_mode;
u32 x, y;
video_mode = (struct ps3av_pkt_video_mode *)p;
if (video_vid == -1)
video_vid = PS3AV_CMD_VIDEO_VID_720P_60HZ;
if (video_fmt == -1)
video_fmt = PS3AV_CMD_VIDEO_FMT_X8R8G8B8;
if (ps3av_video_mode2res(id, &x, &y))
return 0;
memset(video_mode, 0, sizeof(*video_mode));
ps3av_set_hdr(PS3AV_CID_VIDEO_MODE, sizeof(*video_mode),
&video_mode->send_hdr);
video_mode->video_head = head;
if (video_vid == PS3AV_CMD_VIDEO_VID_480I
&& head == PS3AV_CMD_VIDEO_HEAD_B)
video_mode->video_vid = PS3AV_CMD_VIDEO_VID_480I_A;
else
video_mode->video_vid = video_vid;
video_mode->width = (u16) x;
video_mode->height = (u16) y;
video_mode->pitch = video_mode->width * 4;
video_mode->video_out_format = PS3AV_CMD_VIDEO_OUT_FORMAT_RGB_12BIT;
video_mode->video_format = ps3av_video_fmt_table[video_fmt].format;
if ((id & PS3AV_MODE_COLOR) && ps3av_hdmi_range())
video_mode->video_cl_cnv = PS3AV_CMD_VIDEO_CL_CNV_DISABLE_LUT;
else
video_mode->video_cl_cnv = PS3AV_CMD_VIDEO_CL_CNV_ENABLE_LUT;
video_mode->video_order = ps3av_video_fmt_table[video_fmt].order;
pr_debug("%s: video_mode:vid:%x width:%d height:%d pitch:%d out_format:%d format:%x order:%x\n",
__func__, video_vid, video_mode->width, video_mode->height,
video_mode->pitch, video_mode->video_out_format,
video_mode->video_format, video_mode->video_order);
return sizeof(*video_mode);
}
int ps3av_cmd_video_format_black(u32 head, u32 video_fmt, u32 mute)
{
int res;
struct ps3av_pkt_video_format video_format;
memset(&video_format, 0, sizeof(video_format));
video_format.video_head = head;
if (mute != PS3AV_CMD_MUTE_OFF)
video_format.video_format = PS3AV_CMD_VIDEO_FORMAT_BLACK;
else
video_format.video_format =
ps3av_video_fmt_table[video_fmt].format;
video_format.video_order = ps3av_video_fmt_table[video_fmt].order;
res = ps3av_do_pkt(PS3AV_CID_VIDEO_FORMAT, sizeof(video_format),
sizeof(video_format), &video_format.send_hdr);
if (res < 0)
return res;
res = get_status(&video_format);
if (res)
printk(KERN_ERR "PS3AV_CID_VIDEO_FORMAT: failed %x\n", res);
return res;
}
int ps3av_cmd_av_audio_mute(int num_of_port, u32 *port, u32 mute)
{
int i, res;
struct ps3av_pkt_av_audio_mute av_audio_mute;
if (num_of_port > PS3AV_MUTE_PORT_MAX)
return -EINVAL;
memset(&av_audio_mute, 0, sizeof(av_audio_mute));
for (i = 0; i < num_of_port; i++) {
av_audio_mute.mute[i].avport = port[i];
av_audio_mute.mute[i].mute = mute;
}
res = ps3av_do_pkt(PS3AV_CID_AV_AUDIO_MUTE,
sizeof(av_audio_mute.send_hdr) +
sizeof(struct ps3av_av_mute) * num_of_port,
sizeof(av_audio_mute), &av_audio_mute.send_hdr);
if (res < 0)
return res;
res = get_status(&av_audio_mute);
if (res)
printk(KERN_ERR "PS3AV_CID_AV_AUDIO_MUTE: failed %x\n", res);
return res;
}
static u8 ps3av_cnv_mclk(u32 fs)
{
unsigned int i;
for (i = 0; i < ARRAY_SIZE(ps3av_cnv_mclk_table); i++)
if (ps3av_cnv_mclk_table[i].fs == fs)
return ps3av_cnv_mclk_table[i].mclk;
printk(KERN_ERR "%s failed, fs:%x\n", __func__, fs);
return 0;
}
static void ps3av_cnv_ns(u8 *ns, u32 fs, u32 video_vid)
{
u32 av_vid, ns_val;
int d;
d = ns_val = 0;
av_vid = ps3av_vid_video2av(video_vid);
switch (av_vid) {
case PS3AV_CMD_AV_VID_480I:
case PS3AV_CMD_AV_VID_576I:
d = 0;
break;
case PS3AV_CMD_AV_VID_480P:
case PS3AV_CMD_AV_VID_576P:
d = 1;
break;
case PS3AV_CMD_AV_VID_1080I_60HZ:
case PS3AV_CMD_AV_VID_1080I_50HZ:
d = 2;
break;
case PS3AV_CMD_AV_VID_720P_60HZ:
case PS3AV_CMD_AV_VID_720P_50HZ:
d = 3;
break;
case PS3AV_CMD_AV_VID_1080P_60HZ:
case PS3AV_CMD_AV_VID_1080P_50HZ:
case PS3AV_CMD_AV_VID_WXGA:
case PS3AV_CMD_AV_VID_SXGA:
case PS3AV_CMD_AV_VID_WUXGA:
d = 4;
break;
default:
printk(KERN_ERR "%s failed, vid:%x\n", __func__, video_vid);
break;
}
if (fs < PS3AV_CMD_AUDIO_FS_44K || fs > PS3AV_CMD_AUDIO_FS_192K)
printk(KERN_ERR "%s failed, fs:%x\n", __func__, fs);
else
ns_val = ps3av_ns_table[PS3AV_CMD_AUDIO_FS_44K-BASE][d];
*ns++ = ns_val & 0x000000FF;
*ns++ = (ns_val & 0x0000FF00) >> 8;
*ns = (ns_val & 0x00FF0000) >> 16;
}
static u8 ps3av_cnv_enable(u32 source, const u8 *enable)
{
u8 ret = 0;
if (source == PS3AV_CMD_AUDIO_SOURCE_SPDIF) {
ret = 0x03;
} else if (source == PS3AV_CMD_AUDIO_SOURCE_SERIAL) {
ret = ((enable[0] << 4) + (enable[1] << 5) + (enable[2] << 6) +
(enable[3] << 7)) | 0x01;
} else
printk(KERN_ERR "%s failed, source:%x\n", __func__, source);
return ret;
}
static u8 ps3av_cnv_fifomap(const u8 *map)
{
u8 ret = 0;
ret = map[0] + (map[1] << 2) + (map[2] << 4) + (map[3] << 6);
return ret;
}
static u8 ps3av_cnv_inputlen(u32 word_bits)
{
u8 ret = 0;
switch (word_bits) {
case PS3AV_CMD_AUDIO_WORD_BITS_16:
ret = PS3AV_CMD_AV_INPUTLEN_16;
break;
case PS3AV_CMD_AUDIO_WORD_BITS_20:
ret = PS3AV_CMD_AV_INPUTLEN_20;
break;
case PS3AV_CMD_AUDIO_WORD_BITS_24:
ret = PS3AV_CMD_AV_INPUTLEN_24;
break;
default:
printk(KERN_ERR "%s failed, word_bits:%x\n", __func__,
word_bits);
break;
}
return ret;
}
static u8 ps3av_cnv_layout(u32 num_of_ch)
{
if (num_of_ch > PS3AV_CMD_AUDIO_NUM_OF_CH_8) {
printk(KERN_ERR "%s failed, num_of_ch:%x\n", __func__,
num_of_ch);
return 0;
}
return num_of_ch == PS3AV_CMD_AUDIO_NUM_OF_CH_2 ? 0x0 : 0x1;
}
static void ps3av_cnv_info(struct ps3av_audio_info_frame *info,
const struct ps3av_pkt_audio_mode *mode)
{
info->pb1.cc = mode->audio_num_of_ch + 1;
info->pb1.ct = 0;
info->pb2.sf = 0;
info->pb2.ss = 0;
info->pb3 = 0;
info->pb4 = mode->audio_layout;
info->pb5.dm = mode->audio_downmix;
info->pb5.lsv = mode->audio_downmix_level;
}
static void ps3av_cnv_chstat(u8 *chstat, const u8 *cs_info)
{
memcpy(chstat, cs_info, 5);
}
u32 ps3av_cmd_set_av_audio_param(void *p, u32 port,
const struct ps3av_pkt_audio_mode *audio_mode,
u32 video_vid)
{
struct ps3av_pkt_av_audio_param *param;
param = (struct ps3av_pkt_av_audio_param *)p;
memset(param, 0, sizeof(*param));
ps3av_set_hdr(PS3AV_CID_AV_AUDIO_PARAM, sizeof(*param),
&param->send_hdr);
param->avport = port;
param->mclk = ps3av_cnv_mclk(audio_mode->audio_fs) | 0x80;
ps3av_cnv_ns(param->ns, audio_mode->audio_fs, video_vid);
param->enable = ps3av_cnv_enable(audio_mode->audio_source,
audio_mode->audio_enable);
param->swaplr = 0x09;
param->fifomap = ps3av_cnv_fifomap(audio_mode->audio_map);
param->inputctrl = 0x49;
param->inputlen = ps3av_cnv_inputlen(audio_mode->audio_word_bits);
param->layout = ps3av_cnv_layout(audio_mode->audio_num_of_ch);
ps3av_cnv_info(&param->info, audio_mode);
ps3av_cnv_chstat(param->chstat, audio_mode->audio_cs_info);
return sizeof(*param);
}
void ps3av_cmd_set_audio_mode(struct ps3av_pkt_audio_mode *audio, u32 avport,
u32 ch, u32 fs, u32 word_bits, u32 format,
u32 source)
{
int spdif_through;
int i;
if (!(ch | fs | format | word_bits | source)) {
ch = PS3AV_CMD_AUDIO_NUM_OF_CH_2;
fs = PS3AV_CMD_AUDIO_FS_48K;
word_bits = PS3AV_CMD_AUDIO_WORD_BITS_16;
format = PS3AV_CMD_AUDIO_FORMAT_PCM;
source = PS3AV_CMD_AUDIO_SOURCE_SERIAL;
}
memset(audio, 0, sizeof(*audio));
ps3av_set_hdr(PS3AV_CID_AUDIO_MODE, sizeof(*audio), &audio->send_hdr);
audio->avport = (u8) avport;
audio->mask = 0x0FFF;
audio->audio_num_of_ch = ch;
audio->audio_fs = fs;
audio->audio_word_bits = word_bits;
audio->audio_format = format;
audio->audio_source = source;
switch (ch) {
case PS3AV_CMD_AUDIO_NUM_OF_CH_8:
audio->audio_enable[3] = 1;
case PS3AV_CMD_AUDIO_NUM_OF_CH_6:
audio->audio_enable[2] = 1;
audio->audio_enable[1] = 1;
case PS3AV_CMD_AUDIO_NUM_OF_CH_2:
default:
audio->audio_enable[0] = 1;
}
for (i = 0; i < 4; i++)
audio->audio_swap[i] = PS3AV_CMD_AUDIO_SWAP_0;
audio->audio_map[0] = PS3AV_CMD_AUDIO_MAP_OUTPUT_0;
audio->audio_map[1] = PS3AV_CMD_AUDIO_MAP_OUTPUT_1;
audio->audio_map[2] = PS3AV_CMD_AUDIO_MAP_OUTPUT_2;
audio->audio_map[3] = PS3AV_CMD_AUDIO_MAP_OUTPUT_3;
if (avport == PS3AV_CMD_AVPORT_HDMI_0 ||
avport == PS3AV_CMD_AVPORT_HDMI_1) {
switch (ch) {
case PS3AV_CMD_AUDIO_NUM_OF_CH_8:
audio->audio_layout = PS3AV_CMD_AUDIO_LAYOUT_8CH;
break;
case PS3AV_CMD_AUDIO_NUM_OF_CH_6:
audio->audio_layout = PS3AV_CMD_AUDIO_LAYOUT_6CH;
break;
case PS3AV_CMD_AUDIO_NUM_OF_CH_2:
default:
audio->audio_layout = PS3AV_CMD_AUDIO_LAYOUT_2CH;
break;
}
} else {
audio->audio_layout = PS3AV_CMD_AUDIO_LAYOUT_2CH;
}
audio->audio_downmix = PS3AV_CMD_AUDIO_DOWNMIX_PERMITTED;
audio->audio_downmix_level = 0;
for (i = 0; i < 8; i++)
audio->audio_cs_info[i] = ps3av_mode_cs_info[i];
switch (fs) {
case PS3AV_CMD_AUDIO_FS_44K:
audio->audio_cs_info[3] &= ~CS_MASK;
audio->audio_cs_info[3] |= CS_44;
break;
case PS3AV_CMD_AUDIO_FS_88K:
audio->audio_cs_info[3] &= ~CS_MASK;
audio->audio_cs_info[3] |= CS_88;
break;
case PS3AV_CMD_AUDIO_FS_96K:
audio->audio_cs_info[3] &= ~CS_MASK;
audio->audio_cs_info[3] |= CS_96;
break;
case PS3AV_CMD_AUDIO_FS_176K:
audio->audio_cs_info[3] &= ~CS_MASK;
audio->audio_cs_info[3] |= CS_176;
break;
case PS3AV_CMD_AUDIO_FS_192K:
audio->audio_cs_info[3] &= ~CS_MASK;
audio->audio_cs_info[3] |= CS_192;
break;
default:
break;
}
spdif_through = audio->audio_cs_info[0] & 0x02;
if (spdif_through &&
(avport == PS3AV_CMD_AVPORT_SPDIF_0 ||
avport == PS3AV_CMD_AVPORT_SPDIF_1 ||
avport == PS3AV_CMD_AVPORT_HDMI_0 ||
avport == PS3AV_CMD_AVPORT_HDMI_1)) {
audio->audio_word_bits = PS3AV_CMD_AUDIO_WORD_BITS_16;
audio->audio_format = PS3AV_CMD_AUDIO_FORMAT_BITSTREAM;
}
}
int ps3av_cmd_audio_mode(struct ps3av_pkt_audio_mode *audio_mode)
{
int res;
res = ps3av_do_pkt(PS3AV_CID_AUDIO_MODE, sizeof(*audio_mode),
sizeof(*audio_mode), &audio_mode->send_hdr);
if (res < 0)
return res;
res = get_status(audio_mode);
if (res)
printk(KERN_ERR "PS3AV_CID_AUDIO_MODE: failed %x\n", res);
return res;
}
int ps3av_cmd_audio_mute(int num_of_port, u32 *port, u32 mute)
{
int i, res;
struct ps3av_pkt_audio_mute audio_mute;
if (num_of_port > PS3AV_OPT_PORT_MAX)
return -EINVAL;
memset(&audio_mute, 0, sizeof(audio_mute));
for (i = 0; i < num_of_port; i++) {
audio_mute.mute[i].avport = port[i];
audio_mute.mute[i].mute = mute;
}
res = ps3av_do_pkt(PS3AV_CID_AUDIO_MUTE,
sizeof(audio_mute.send_hdr) +
sizeof(struct ps3av_audio_mute) * num_of_port,
sizeof(audio_mute), &audio_mute.send_hdr);
if (res < 0)
return res;
res = get_status(&audio_mute);
if (res)
printk(KERN_ERR "PS3AV_CID_AUDIO_MUTE: failed %x\n", res);
return res;
}
int ps3av_cmd_audio_active(int active, u32 port)
{
int res;
struct ps3av_pkt_audio_active audio_active;
u32 cid;
memset(&audio_active, 0, sizeof(audio_active));
audio_active.audio_port = port;
cid = active ? PS3AV_CID_AUDIO_ACTIVE : PS3AV_CID_AUDIO_INACTIVE;
res = ps3av_do_pkt(cid, sizeof(audio_active), sizeof(audio_active),
&audio_active.send_hdr);
if (res < 0)
return res;
res = get_status(&audio_active);
if (res)
printk(KERN_ERR "PS3AV_CID_AUDIO_ACTIVE:%x failed %x\n", cid,
res);
return res;
}
int ps3av_cmd_avb_param(struct ps3av_pkt_avb_param *avb, u32 send_len)
{
int res;
mutex_lock(&ps3_gpu_mutex);
res = ps3av_do_pkt(PS3AV_CID_AVB_PARAM, send_len, sizeof(*avb),
&avb->send_hdr);
if (res < 0)
goto out;
res = get_status(avb);
if (res)
pr_debug("%s: PS3AV_CID_AVB_PARAM: failed %x\n", __func__,
res);
out:
mutex_unlock(&ps3_gpu_mutex);
return res;
}
int ps3av_cmd_av_get_hw_conf(struct ps3av_pkt_av_get_hw_conf *hw_conf)
{
int res;
memset(hw_conf, 0, sizeof(*hw_conf));
res = ps3av_do_pkt(PS3AV_CID_AV_GET_HW_CONF, sizeof(hw_conf->send_hdr),
sizeof(*hw_conf), &hw_conf->send_hdr);
if (res < 0)
return res;
res = get_status(hw_conf);
if (res)
printk(KERN_ERR "PS3AV_CID_AV_GET_HW_CONF: failed %x\n", res);
return res;
}
int ps3av_cmd_video_get_monitor_info(struct ps3av_pkt_av_get_monitor_info *info,
u32 avport)
{
int res;
memset(info, 0, sizeof(*info));
info->avport = avport;
res = ps3av_do_pkt(PS3AV_CID_AV_GET_MONITOR_INFO,
sizeof(info->send_hdr) + sizeof(info->avport) +
sizeof(info->reserved),
sizeof(*info), &info->send_hdr);
if (res < 0)
return res;
res = get_status(info);
if (res)
printk(KERN_ERR "PS3AV_CID_AV_GET_MONITOR_INFO: failed %x\n",
res);
return res;
}
