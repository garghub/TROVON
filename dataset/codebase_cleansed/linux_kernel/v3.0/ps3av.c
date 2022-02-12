static u32 *ps3av_search_cmd_table(u32 cid, u32 mask)
{
u32 *table;
int i;
table = cmd_table;
for (i = 0;; table++, i++) {
if ((*table & mask) == (cid & mask))
break;
if (*table == 0)
return NULL;
}
return table;
}
static int ps3av_parse_event_packet(const struct ps3av_reply_hdr *hdr)
{
u32 *table;
if (hdr->cid & PS3AV_EVENT_CMD_MASK) {
table = ps3av_search_cmd_table(hdr->cid, PS3AV_EVENT_CMD_MASK);
if (table)
dev_dbg(&ps3av->dev->core,
"recv event packet cid:%08x port:0x%x size:%d\n",
hdr->cid, ps3av_event_get_port_id(hdr->cid),
hdr->size);
else
printk(KERN_ERR
"%s: failed event packet, cid:%08x size:%d\n",
__func__, hdr->cid, hdr->size);
return 1;
}
return 0;
}
static int ps3av_vuart_write(struct ps3_system_bus_device *dev,
const void *buf, unsigned long size)
{
int error;
dev_dbg(&dev->core, " -> %s:%d\n", __func__, __LINE__);
error = ps3_vuart_write(dev, buf, size);
dev_dbg(&dev->core, " <- %s:%d\n", __func__, __LINE__);
return error ? error : size;
}
static int ps3av_vuart_read(struct ps3_system_bus_device *dev, void *buf,
unsigned long size, int timeout)
{
int error;
int loopcnt = 0;
dev_dbg(&dev->core, " -> %s:%d\n", __func__, __LINE__);
timeout = (timeout + POLLING_INTERVAL - 1) / POLLING_INTERVAL;
while (loopcnt++ <= timeout) {
error = ps3_vuart_read(dev, buf, size);
if (!error)
return size;
if (error != -EAGAIN) {
printk(KERN_ERR "%s: ps3_vuart_read failed %d\n",
__func__, error);
return error;
}
msleep(POLLING_INTERVAL);
}
return -EWOULDBLOCK;
}
static int ps3av_send_cmd_pkt(const struct ps3av_send_hdr *send_buf,
struct ps3av_reply_hdr *recv_buf, int write_len,
int read_len)
{
int res;
u32 cmd;
int event;
if (!ps3av)
return -ENODEV;
res = ps3av_vuart_write(ps3av->dev, send_buf, write_len);
if (res < 0) {
dev_dbg(&ps3av->dev->core,
"%s: ps3av_vuart_write() failed (result=%d)\n",
__func__, res);
return res;
}
cmd = send_buf->cid;
do {
res = ps3av_vuart_read(ps3av->dev, recv_buf, PS3AV_HDR_SIZE,
timeout);
if (res != PS3AV_HDR_SIZE) {
dev_dbg(&ps3av->dev->core,
"%s: ps3av_vuart_read() failed (result=%d)\n",
__func__, res);
return res;
}
res = ps3av_vuart_read(ps3av->dev, &recv_buf->cid,
recv_buf->size, timeout);
if (res < 0) {
dev_dbg(&ps3av->dev->core,
"%s: ps3av_vuart_read() failed (result=%d)\n",
__func__, res);
return res;
}
res += PS3AV_HDR_SIZE;
event = ps3av_parse_event_packet(recv_buf);
} while (event);
if ((cmd | PS3AV_REPLY_BIT) != recv_buf->cid) {
dev_dbg(&ps3av->dev->core, "%s: reply err (result=%x)\n",
__func__, recv_buf->cid);
return -EINVAL;
}
return 0;
}
static int ps3av_process_reply_packet(struct ps3av_send_hdr *cmd_buf,
const struct ps3av_reply_hdr *recv_buf,
int user_buf_size)
{
int return_len;
if (recv_buf->version != PS3AV_VERSION) {
dev_dbg(&ps3av->dev->core, "reply_packet invalid version:%x\n",
recv_buf->version);
return -EFAULT;
}
return_len = recv_buf->size + PS3AV_HDR_SIZE;
if (return_len > user_buf_size)
return_len = user_buf_size;
memcpy(cmd_buf, recv_buf, return_len);
return 0;
}
void ps3av_set_hdr(u32 cid, u16 size, struct ps3av_send_hdr *hdr)
{
hdr->version = PS3AV_VERSION;
hdr->size = size - PS3AV_HDR_SIZE;
hdr->cid = cid;
}
int ps3av_do_pkt(u32 cid, u16 send_len, size_t usr_buf_size,
struct ps3av_send_hdr *buf)
{
int res = 0;
u32 *table;
BUG_ON(!ps3av);
mutex_lock(&ps3av->mutex);
table = ps3av_search_cmd_table(cid, PS3AV_CID_MASK);
BUG_ON(!table);
BUG_ON(send_len < PS3AV_HDR_SIZE);
BUG_ON(usr_buf_size < send_len);
BUG_ON(usr_buf_size > PS3AV_BUF_SIZE);
ps3av_set_hdr(cid, send_len, buf);
res = ps3av_send_cmd_pkt(buf, &ps3av->recv_buf.reply_hdr, send_len,
usr_buf_size);
if (res < 0) {
printk(KERN_ERR
"%s: ps3av_send_cmd_pkt() failed (result=%d)\n",
__func__, res);
goto err;
}
res = ps3av_process_reply_packet(buf, &ps3av->recv_buf.reply_hdr,
usr_buf_size);
if (res < 0) {
printk(KERN_ERR "%s: put_return_status() failed (result=%d)\n",
__func__, res);
goto err;
}
mutex_unlock(&ps3av->mutex);
return 0;
err:
mutex_unlock(&ps3av->mutex);
printk(KERN_ERR "%s: failed cid:%x res:%d\n", __func__, cid, res);
return res;
}
static int ps3av_set_av_video_mute(u32 mute)
{
int i, num_of_av_port, res;
num_of_av_port = ps3av->av_hw_conf.num_of_hdmi +
ps3av->av_hw_conf.num_of_avmulti;
for (i = 0; i < num_of_av_port; i++) {
res = ps3av_cmd_av_video_mute(1, &ps3av->av_port[i], mute);
if (res < 0)
return -1;
}
return 0;
}
static int ps3av_set_video_disable_sig(void)
{
int i, num_of_hdmi_port, num_of_av_port, res;
num_of_hdmi_port = ps3av->av_hw_conf.num_of_hdmi;
num_of_av_port = ps3av->av_hw_conf.num_of_hdmi +
ps3av->av_hw_conf.num_of_avmulti;
for (i = 0; i < num_of_hdmi_port; i++) {
res = ps3av_cmd_av_tv_mute(ps3av->av_port[i],
PS3AV_CMD_MUTE_ON);
if (res < 0)
return -1;
}
msleep(100);
for (i = 0; i < num_of_av_port; i++) {
res = ps3av_cmd_av_video_disable_sig(ps3av->av_port[i]);
if (res < 0)
return -1;
if (i < num_of_hdmi_port) {
res = ps3av_cmd_av_tv_mute(ps3av->av_port[i],
PS3AV_CMD_MUTE_OFF);
if (res < 0)
return -1;
}
}
msleep(300);
return 0;
}
static int ps3av_set_audio_mute(u32 mute)
{
int i, num_of_av_port, num_of_opt_port, res;
num_of_av_port = ps3av->av_hw_conf.num_of_hdmi +
ps3av->av_hw_conf.num_of_avmulti;
num_of_opt_port = ps3av->av_hw_conf.num_of_spdif;
for (i = 0; i < num_of_av_port; i++) {
res = ps3av_cmd_av_audio_mute(1, &ps3av->av_port[i], mute);
if (res < 0)
return -1;
}
for (i = 0; i < num_of_opt_port; i++) {
res = ps3av_cmd_audio_mute(1, &ps3av->opt_port[i], mute);
if (res < 0)
return -1;
}
return 0;
}
int ps3av_set_audio_mode(u32 ch, u32 fs, u32 word_bits, u32 format, u32 source)
{
struct ps3av_pkt_avb_param avb_param;
int i, num_of_audio, vid, res;
struct ps3av_pkt_audio_mode audio_mode;
u32 len = 0;
num_of_audio = ps3av->av_hw_conf.num_of_hdmi +
ps3av->av_hw_conf.num_of_avmulti +
ps3av->av_hw_conf.num_of_spdif;
avb_param.num_of_video_pkt = 0;
avb_param.num_of_audio_pkt = PS3AV_AVB_NUM_AUDIO;
avb_param.num_of_av_video_pkt = 0;
avb_param.num_of_av_audio_pkt = ps3av->av_hw_conf.num_of_hdmi;
vid = video_mode_table[ps3av->ps3av_mode].vid;
ps3av_set_audio_mute(PS3AV_CMD_MUTE_ON);
res = ps3av_cmd_audio_active(0, ps3av->audio_port);
if (res < 0)
dev_dbg(&ps3av->dev->core,
"ps3av_cmd_audio_active OFF failed\n");
for (i = 0; i < num_of_audio; i++) {
ps3av_cmd_set_audio_mode(&audio_mode, ps3av->av_port[i], ch,
fs, word_bits, format, source);
if (i < ps3av->av_hw_conf.num_of_hdmi) {
len += ps3av_cmd_set_av_audio_param(&avb_param.buf[len],
ps3av->av_port[i],
&audio_mode, vid);
}
res = ps3av_cmd_audio_mode(&audio_mode);
if (res < 0)
dev_dbg(&ps3av->dev->core,
"ps3av_cmd_audio_mode failed, port:%x\n", i);
}
len += offsetof(struct ps3av_pkt_avb_param, buf);
res = ps3av_cmd_avb_param(&avb_param, len);
if (res < 0)
dev_dbg(&ps3av->dev->core, "ps3av_cmd_avb_param failed\n");
ps3av_set_audio_mute(PS3AV_CMD_MUTE_OFF);
res = ps3av_cmd_audio_active(1, ps3av->audio_port);
if (res < 0)
dev_dbg(&ps3av->dev->core,
"ps3av_cmd_audio_active ON failed\n");
return 0;
}
static int ps3av_set_videomode(void)
{
ps3av_set_av_video_mute(PS3AV_CMD_MUTE_ON);
queue_work(ps3av->wq, &ps3av->work);
return 0;
}
static void ps3av_set_videomode_packet(u32 id)
{
struct ps3av_pkt_avb_param avb_param;
unsigned int i;
u32 len = 0, av_video_cs;
const struct avset_video_mode *video_mode;
int res;
video_mode = &video_mode_table[id & PS3AV_MODE_MASK];
avb_param.num_of_video_pkt = PS3AV_AVB_NUM_VIDEO;
avb_param.num_of_audio_pkt = 0;
avb_param.num_of_av_video_pkt = ps3av->av_hw_conf.num_of_hdmi +
ps3av->av_hw_conf.num_of_avmulti;
avb_param.num_of_av_audio_pkt = 0;
for (i = 0; i < avb_param.num_of_video_pkt; i++)
len += ps3av_cmd_set_video_mode(&avb_param.buf[len],
ps3av->head[i], video_mode->vid,
video_mode->fmt, id);
for (i = 0; i < avb_param.num_of_av_video_pkt; i++) {
if (id & PS3AV_MODE_DVI || id & PS3AV_MODE_RGB)
av_video_cs = RGB8;
else
av_video_cs = video_mode->cs;
#ifndef PS3AV_HDMI_YUV
if (ps3av->av_port[i] == PS3AV_CMD_AVPORT_HDMI_0 ||
ps3av->av_port[i] == PS3AV_CMD_AVPORT_HDMI_1)
av_video_cs = RGB8;
#endif
len += ps3av_cmd_set_av_video_cs(&avb_param.buf[len],
ps3av->av_port[i],
video_mode->vid, av_video_cs,
video_mode->aspect, id);
}
len += offsetof(struct ps3av_pkt_avb_param, buf);
res = ps3av_cmd_avb_param(&avb_param, len);
if (res == PS3AV_STATUS_NO_SYNC_HEAD)
printk(KERN_WARNING
"%s: Command failed. Please try your request again.\n",
__func__);
else if (res)
dev_dbg(&ps3av->dev->core, "ps3av_cmd_avb_param failed\n");
}
static void ps3av_set_videomode_cont(u32 id, u32 old_id)
{
static int vesa;
int res;
ps3av_set_video_disable_sig();
if (vesa == 0 && (id & PS3AV_MODE_MASK) >= PS3AV_MODE_WXGA) {
ps3av_set_videomode_packet(PS3AV_MODE_480P);
}
vesa = 1;
if (id & PS3AV_MODE_HDCP_OFF) {
res = ps3av_cmd_av_hdmi_mode(PS3AV_CMD_AV_HDMI_HDCP_OFF);
if (res == PS3AV_STATUS_UNSUPPORTED_HDMI_MODE)
dev_dbg(&ps3av->dev->core, "Not supported\n");
else if (res)
dev_dbg(&ps3av->dev->core,
"ps3av_cmd_av_hdmi_mode failed\n");
} else if (old_id & PS3AV_MODE_HDCP_OFF) {
res = ps3av_cmd_av_hdmi_mode(PS3AV_CMD_AV_HDMI_MODE_NORMAL);
if (res < 0 && res != PS3AV_STATUS_UNSUPPORTED_HDMI_MODE)
dev_dbg(&ps3av->dev->core,
"ps3av_cmd_av_hdmi_mode failed\n");
}
ps3av_set_videomode_packet(id);
msleep(1500);
ps3av_set_av_video_mute(PS3AV_CMD_MUTE_OFF);
}
static void ps3avd(struct work_struct *work)
{
ps3av_set_videomode_cont(ps3av->ps3av_mode, ps3av->ps3av_mode_old);
complete(&ps3av->done);
}
static enum ps3av_mode_num ps3av_resbit2id(u32 res_50, u32 res_60,
u32 res_vesa)
{
unsigned int i;
u32 res_all;
BUILD_BUG_ON(PS3AV_RES_MASK_50 << SHIFT_50 &
PS3AV_RES_MASK_60 << SHIFT_60);
BUILD_BUG_ON(PS3AV_RES_MASK_50 << SHIFT_50 &
PS3AV_RES_MASK_VESA << SHIFT_VESA);
BUILD_BUG_ON(PS3AV_RES_MASK_60 << SHIFT_60 &
PS3AV_RES_MASK_VESA << SHIFT_VESA);
res_all = (res_50 & PS3AV_RES_MASK_50) << SHIFT_50 |
(res_60 & PS3AV_RES_MASK_60) << SHIFT_60 |
(res_vesa & PS3AV_RES_MASK_VESA) << SHIFT_VESA;
if (!res_all)
return 0;
for (i = 0; i < ARRAY_SIZE(ps3av_preferred_modes); i++)
if (res_all & ps3av_preferred_modes[i].mask)
return ps3av_preferred_modes[i].id;
return 0;
}
static enum ps3av_mode_num ps3av_hdmi_get_id(struct ps3av_info_monitor *info)
{
enum ps3av_mode_num id;
if (safe_mode)
return PS3AV_DEFAULT_HDMI_MODE_ID_REG_60;
id = ps3av_resbit2id(info->res_50.native, info->res_60.native,
info->res_vesa.native);
if (id) {
pr_debug("%s: Using native mode %d\n", __func__, id);
return id;
}
id = ps3av_resbit2id(info->res_50.res_bits, info->res_60.res_bits,
info->res_vesa.res_bits);
if (id) {
pr_debug("%s: Using supported mode %d\n", __func__, id);
return id;
}
if (ps3av->region & PS3AV_REGION_60)
id = PS3AV_DEFAULT_HDMI_MODE_ID_REG_60;
else
id = PS3AV_DEFAULT_HDMI_MODE_ID_REG_50;
pr_debug("%s: Using default mode %d\n", __func__, id);
return id;
}
static void ps3av_monitor_info_dump(const struct ps3av_pkt_av_get_monitor_info *monitor_info)
{
const struct ps3av_info_monitor *info = &monitor_info->info;
const struct ps3av_info_audio *audio = info->audio;
char id[sizeof(info->monitor_id)*3+1];
int i;
pr_debug("Monitor Info: size %u\n", monitor_info->send_hdr.size);
pr_debug("avport: %02x\n", info->avport);
for (i = 0; i < sizeof(info->monitor_id); i++)
sprintf(&id[i*3], " %02x", info->monitor_id[i]);
pr_debug("monitor_id: %s\n", id);
pr_debug("monitor_type: %02x\n", info->monitor_type);
pr_debug("monitor_name: %.*s\n", (int)sizeof(info->monitor_name),
info->monitor_name);
pr_debug("resolution_60: bits: %08x native: %08x\n",
info->res_60.res_bits, info->res_60.native);
pr_debug("resolution_50: bits: %08x native: %08x\n",
info->res_50.res_bits, info->res_50.native);
pr_debug("resolution_other: bits: %08x native: %08x\n",
info->res_other.res_bits, info->res_other.native);
pr_debug("resolution_vesa: bits: %08x native: %08x\n",
info->res_vesa.res_bits, info->res_vesa.native);
pr_debug("color space rgb: %02x\n", info->cs.rgb);
pr_debug("color space yuv444: %02x\n", info->cs.yuv444);
pr_debug("color space yuv422: %02x\n", info->cs.yuv422);
pr_debug("color info red: X %04x Y %04x\n", info->color.red_x,
info->color.red_y);
pr_debug("color info green: X %04x Y %04x\n", info->color.green_x,
info->color.green_y);
pr_debug("color info blue: X %04x Y %04x\n", info->color.blue_x,
info->color.blue_y);
pr_debug("color info white: X %04x Y %04x\n", info->color.white_x,
info->color.white_y);
pr_debug("color info gamma: %08x\n", info->color.gamma);
pr_debug("supported_AI: %02x\n", info->supported_ai);
pr_debug("speaker_info: %02x\n", info->speaker_info);
pr_debug("num of audio: %02x\n", info->num_of_audio_block);
for (i = 0; i < info->num_of_audio_block; i++) {
pr_debug("audio[%d] type: %02x max_ch: %02x fs: %02x sbit: "
"%02x\n",
i, audio->type, audio->max_num_of_ch, audio->fs,
audio->sbit);
audio++;
}
}
static void ps3av_fixup_monitor_info(struct ps3av_info_monitor *info)
{
unsigned int i;
const struct ps3av_monitor_quirk *quirk;
for (i = 0; i < ARRAY_SIZE(ps3av_monitor_quirks); i++) {
quirk = &ps3av_monitor_quirks[i];
if (!strncmp(info->monitor_name, quirk->monitor_name,
sizeof(info->monitor_name))) {
pr_info("%s: Applying quirk for %s\n", __func__,
quirk->monitor_name);
info->res_60.res_bits &= ~quirk->clear_60;
info->res_60.native &= ~quirk->clear_60;
break;
}
}
}
static int ps3av_auto_videomode(struct ps3av_pkt_av_get_hw_conf *av_hw_conf)
{
int i, res, id = 0, dvi = 0, rgb = 0;
struct ps3av_pkt_av_get_monitor_info monitor_info;
struct ps3av_info_monitor *info;
for (i = 0; i < av_hw_conf->num_of_hdmi && !id; i++) {
res = ps3av_cmd_video_get_monitor_info(&monitor_info,
PS3AV_CMD_AVPORT_HDMI_0 +
i);
if (res < 0)
return -1;
ps3av_monitor_info_dump(&monitor_info);
info = &monitor_info.info;
ps3av_fixup_monitor_info(info);
switch (info->monitor_type) {
case PS3AV_MONITOR_TYPE_DVI:
dvi = PS3AV_MODE_DVI;
case PS3AV_MONITOR_TYPE_HDMI:
id = ps3av_hdmi_get_id(info);
break;
}
}
if (!id) {
if (ps3av->region & PS3AV_REGION_60)
id = PS3AV_DEFAULT_AVMULTI_MODE_ID_REG_60;
else
id = PS3AV_DEFAULT_AVMULTI_MODE_ID_REG_50;
if (ps3av->region & PS3AV_REGION_RGB)
rgb = PS3AV_MODE_RGB;
pr_debug("%s: Using avmulti mode %d\n", __func__, id);
}
return id | dvi | rgb;
}
static int ps3av_get_hw_conf(struct ps3av *ps3av)
{
int i, j, k, res;
const struct ps3av_pkt_av_get_hw_conf *hw_conf;
res = ps3av_cmd_av_get_hw_conf(&ps3av->av_hw_conf);
if (res < 0)
return -1;
hw_conf = &ps3av->av_hw_conf;
pr_debug("av_h_conf: num of hdmi: %u\n", hw_conf->num_of_hdmi);
pr_debug("av_h_conf: num of avmulti: %u\n", hw_conf->num_of_avmulti);
pr_debug("av_h_conf: num of spdif: %u\n", hw_conf->num_of_spdif);
for (i = 0; i < PS3AV_HEAD_MAX; i++)
ps3av->head[i] = PS3AV_CMD_VIDEO_HEAD_A + i;
for (i = 0; i < PS3AV_OPT_PORT_MAX; i++)
ps3av->opt_port[i] = PS3AV_CMD_AVPORT_SPDIF_0 + i;
for (i = 0; i < hw_conf->num_of_hdmi; i++)
ps3av->av_port[i] = PS3AV_CMD_AVPORT_HDMI_0 + i;
for (j = 0; j < hw_conf->num_of_avmulti; j++)
ps3av->av_port[i + j] = PS3AV_CMD_AVPORT_AVMULTI_0 + j;
for (k = 0; k < hw_conf->num_of_spdif; k++)
ps3av->av_port[i + j + k] = PS3AV_CMD_AVPORT_SPDIF_0 + k;
ps3av->audio_port = PS3AV_CMD_AUDIO_PORT_HDMI_0
| PS3AV_CMD_AUDIO_PORT_HDMI_1
| PS3AV_CMD_AUDIO_PORT_AVMULTI_0
| PS3AV_CMD_AUDIO_PORT_SPDIF_0 | PS3AV_CMD_AUDIO_PORT_SPDIF_1;
return 0;
}
int ps3av_set_video_mode(int id)
{
int size;
u32 option;
size = ARRAY_SIZE(video_mode_table);
if ((id & PS3AV_MODE_MASK) > size - 1 || id < 0) {
dev_dbg(&ps3av->dev->core, "%s: error id :%d\n", __func__, id);
return -EINVAL;
}
option = id & ~PS3AV_MODE_MASK;
if ((id & PS3AV_MODE_MASK) == PS3AV_MODE_AUTO) {
id = ps3av_auto_videomode(&ps3av->av_hw_conf);
if (id < 1) {
printk(KERN_ERR "%s: invalid id :%d\n", __func__, id);
return -EINVAL;
}
id |= option;
}
wait_for_completion(&ps3av->done);
ps3av->ps3av_mode_old = ps3av->ps3av_mode;
ps3av->ps3av_mode = id;
if (ps3av_set_videomode())
ps3av->ps3av_mode = ps3av->ps3av_mode_old;
return 0;
}
int ps3av_get_auto_mode(void)
{
return ps3av_auto_videomode(&ps3av->av_hw_conf);
}
int ps3av_get_mode(void)
{
return ps3av ? ps3av->ps3av_mode : 0;
}
int ps3av_video_mode2res(u32 id, u32 *xres, u32 *yres)
{
int size;
id = id & PS3AV_MODE_MASK;
size = ARRAY_SIZE(video_mode_table);
if (id > size - 1 || id < 0) {
printk(KERN_ERR "%s: invalid mode %d\n", __func__, id);
return -EINVAL;
}
*xres = video_mode_table[id].x;
*yres = video_mode_table[id].y;
return 0;
}
int ps3av_video_mute(int mute)
{
return ps3av_set_av_video_mute(mute ? PS3AV_CMD_MUTE_ON
: PS3AV_CMD_MUTE_OFF);
}
int ps3av_audio_mute_analog(int mute)
{
int i, res;
for (i = 0; i < ps3av->av_hw_conf.num_of_avmulti; i++) {
res = ps3av_cmd_av_audio_mute(1,
&ps3av->av_port[i + ps3av->av_hw_conf.num_of_hdmi],
mute);
if (res < 0)
return -1;
}
return 0;
}
int ps3av_audio_mute(int mute)
{
return ps3av_set_audio_mute(mute ? PS3AV_CMD_MUTE_ON
: PS3AV_CMD_MUTE_OFF);
}
static int __devinit ps3av_probe(struct ps3_system_bus_device *dev)
{
int res;
int id;
dev_dbg(&dev->core, " -> %s:%d\n", __func__, __LINE__);
dev_dbg(&dev->core, " timeout=%d\n", timeout);
if (ps3av) {
dev_err(&dev->core, "Only one ps3av device is supported\n");
return -EBUSY;
}
ps3av = kzalloc(sizeof(*ps3av), GFP_KERNEL);
if (!ps3av)
return -ENOMEM;
mutex_init(&ps3av->mutex);
ps3av->ps3av_mode = PS3AV_MODE_AUTO;
ps3av->dev = dev;
INIT_WORK(&ps3av->work, ps3avd);
init_completion(&ps3av->done);
complete(&ps3av->done);
ps3av->wq = create_singlethread_workqueue("ps3avd");
if (!ps3av->wq) {
res = -ENOMEM;
goto fail;
}
switch (ps3_os_area_get_av_multi_out()) {
case PS3_PARAM_AV_MULTI_OUT_NTSC:
ps3av->region = PS3AV_REGION_60;
break;
case PS3_PARAM_AV_MULTI_OUT_PAL_YCBCR:
case PS3_PARAM_AV_MULTI_OUT_SECAM:
ps3av->region = PS3AV_REGION_50;
break;
case PS3_PARAM_AV_MULTI_OUT_PAL_RGB:
ps3av->region = PS3AV_REGION_50 | PS3AV_REGION_RGB;
break;
default:
ps3av->region = PS3AV_REGION_60;
break;
}
res = ps3av_cmd_init();
if (res < 0)
printk(KERN_ERR "%s: ps3av_cmd_init failed %d\n", __func__,
res);
ps3av_get_hw_conf(ps3av);
#ifdef CONFIG_FB
if (fb_mode_option && !strcmp(fb_mode_option, "safe"))
safe_mode = 1;
#endif
id = ps3av_auto_videomode(&ps3av->av_hw_conf);
if (id < 0) {
printk(KERN_ERR "%s: invalid id :%d\n", __func__, id);
res = -EINVAL;
goto fail;
}
safe_mode = 0;
mutex_lock(&ps3av->mutex);
ps3av->ps3av_mode = id;
mutex_unlock(&ps3av->mutex);
dev_dbg(&dev->core, " <- %s:%d\n", __func__, __LINE__);
return 0;
fail:
kfree(ps3av);
ps3av = NULL;
return res;
}
static int ps3av_remove(struct ps3_system_bus_device *dev)
{
dev_dbg(&dev->core, " -> %s:%d\n", __func__, __LINE__);
if (ps3av) {
ps3av_cmd_fin();
if (ps3av->wq)
destroy_workqueue(ps3av->wq);
kfree(ps3av);
ps3av = NULL;
}
dev_dbg(&dev->core, " <- %s:%d\n", __func__, __LINE__);
return 0;
}
static void ps3av_shutdown(struct ps3_system_bus_device *dev)
{
dev_dbg(&dev->core, " -> %s:%d\n", __func__, __LINE__);
ps3av_remove(dev);
dev_dbg(&dev->core, " <- %s:%d\n", __func__, __LINE__);
}
static int __init ps3av_module_init(void)
{
int error;
if (!firmware_has_feature(FW_FEATURE_PS3_LV1))
return -ENODEV;
pr_debug(" -> %s:%d\n", __func__, __LINE__);
error = ps3_vuart_port_driver_register(&ps3av_driver);
if (error) {
printk(KERN_ERR
"%s: ps3_vuart_port_driver_register failed %d\n",
__func__, error);
return error;
}
pr_debug(" <- %s:%d\n", __func__, __LINE__);
return error;
}
static void __exit ps3av_module_exit(void)
{
pr_debug(" -> %s:%d\n", __func__, __LINE__);
ps3_vuart_port_driver_unregister(&ps3av_driver);
pr_debug(" <- %s:%d\n", __func__, __LINE__);
}
