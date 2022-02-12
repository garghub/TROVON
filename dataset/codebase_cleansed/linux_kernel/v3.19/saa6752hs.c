static inline struct saa6752hs_state *to_state(struct v4l2_subdev *sd)
{
return container_of(sd, struct saa6752hs_state, sd);
}
static int saa6752hs_chip_command(struct i2c_client *client,
enum saa6752hs_command command)
{
unsigned char buf[3];
unsigned long timeout;
int status = 0;
switch(command) {
case SAA6752HS_COMMAND_RESET:
buf[0] = 0x00;
break;
case SAA6752HS_COMMAND_STOP:
buf[0] = 0x03;
break;
case SAA6752HS_COMMAND_START:
buf[0] = 0x02;
break;
case SAA6752HS_COMMAND_PAUSE:
buf[0] = 0x04;
break;
case SAA6752HS_COMMAND_RECONFIGURE:
buf[0] = 0x05;
break;
case SAA6752HS_COMMAND_SLEEP:
buf[0] = 0x06;
break;
case SAA6752HS_COMMAND_RECONFIGURE_FORCE:
buf[0] = 0x07;
break;
default:
return -EINVAL;
}
i2c_master_send(client, buf, 1);
timeout = jiffies + HZ * 3;
for (;;) {
buf[0] = 0x10;
i2c_master_send(client, buf, 1);
i2c_master_recv(client, buf, 1);
if (!(buf[0] & 0x20))
break;
if (time_after(jiffies,timeout)) {
status = -ETIMEDOUT;
break;
}
msleep(10);
}
msleep(50);
return status;
}
static inline void set_reg8(struct i2c_client *client, uint8_t reg, uint8_t val)
{
u8 buf[2];
buf[0] = reg;
buf[1] = val;
i2c_master_send(client, buf, 2);
}
static inline void set_reg16(struct i2c_client *client, uint8_t reg, uint16_t val)
{
u8 buf[3];
buf[0] = reg;
buf[1] = val >> 8;
buf[2] = val & 0xff;
i2c_master_send(client, buf, 3);
}
static int saa6752hs_set_bitrate(struct i2c_client *client,
struct saa6752hs_state *h)
{
struct saa6752hs_mpeg_params *params = &h->params;
int tot_bitrate;
int is_384k;
set_reg8(client, 0x71,
params->vi_bitrate_mode != V4L2_MPEG_VIDEO_BITRATE_MODE_VBR);
if (params->vi_bitrate_mode == V4L2_MPEG_VIDEO_BITRATE_MODE_VBR) {
set_reg16(client, 0x80, params->vi_bitrate);
set_reg16(client, 0x81, params->vi_bitrate_peak);
tot_bitrate = params->vi_bitrate_peak;
} else {
set_reg16(client, 0x81, params->vi_bitrate);
tot_bitrate = params->vi_bitrate;
}
set_reg8(client, 0x93,
params->au_encoding == V4L2_MPEG_AUDIO_ENCODING_AC3);
if (params->au_encoding == V4L2_MPEG_AUDIO_ENCODING_AC3)
is_384k = V4L2_MPEG_AUDIO_AC3_BITRATE_384K == params->au_ac3_bitrate;
else
is_384k = V4L2_MPEG_AUDIO_L2_BITRATE_384K == params->au_l2_bitrate;
set_reg8(client, 0x94, is_384k);
tot_bitrate += is_384k ? 384 : 256;
tot_bitrate += 768;
if (tot_bitrate > MPEG_TOTAL_TARGET_BITRATE_MAX)
tot_bitrate = MPEG_TOTAL_TARGET_BITRATE_MAX;
set_reg16(client, 0xb1, tot_bitrate);
return 0;
}
static int saa6752hs_try_ctrl(struct v4l2_ctrl *ctrl)
{
struct saa6752hs_state *h =
container_of(ctrl->handler, struct saa6752hs_state, hdl);
switch (ctrl->id) {
case V4L2_CID_MPEG_VIDEO_BITRATE_MODE:
if (ctrl->val == V4L2_MPEG_VIDEO_BITRATE_MODE_VBR &&
h->video_bitrate_peak->val < h->video_bitrate->val)
h->video_bitrate_peak->val = h->video_bitrate->val;
break;
}
return 0;
}
static int saa6752hs_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct saa6752hs_state *h =
container_of(ctrl->handler, struct saa6752hs_state, hdl);
struct saa6752hs_mpeg_params *params = &h->params;
switch (ctrl->id) {
case V4L2_CID_MPEG_STREAM_TYPE:
break;
case V4L2_CID_MPEG_STREAM_PID_PMT:
params->ts_pid_pmt = ctrl->val;
break;
case V4L2_CID_MPEG_STREAM_PID_AUDIO:
params->ts_pid_audio = ctrl->val;
break;
case V4L2_CID_MPEG_STREAM_PID_VIDEO:
params->ts_pid_video = ctrl->val;
break;
case V4L2_CID_MPEG_STREAM_PID_PCR:
params->ts_pid_pcr = ctrl->val;
break;
case V4L2_CID_MPEG_AUDIO_ENCODING:
params->au_encoding = ctrl->val;
break;
case V4L2_CID_MPEG_AUDIO_L2_BITRATE:
params->au_l2_bitrate = ctrl->val;
break;
case V4L2_CID_MPEG_AUDIO_AC3_BITRATE:
params->au_ac3_bitrate = ctrl->val;
break;
case V4L2_CID_MPEG_AUDIO_SAMPLING_FREQ:
break;
case V4L2_CID_MPEG_VIDEO_ENCODING:
break;
case V4L2_CID_MPEG_VIDEO_ASPECT:
params->vi_aspect = ctrl->val;
break;
case V4L2_CID_MPEG_VIDEO_BITRATE_MODE:
params->vi_bitrate_mode = ctrl->val;
params->vi_bitrate = h->video_bitrate->val / 1000;
params->vi_bitrate_peak = h->video_bitrate_peak->val / 1000;
v4l2_ctrl_activate(h->video_bitrate_peak,
ctrl->val == V4L2_MPEG_VIDEO_BITRATE_MODE_VBR);
break;
default:
return -EINVAL;
}
return 0;
}
static int saa6752hs_init(struct v4l2_subdev *sd, u32 leading_null_bytes)
{
unsigned char buf[9], buf2[4];
struct saa6752hs_state *h = to_state(sd);
struct i2c_client *client = v4l2_get_subdevdata(sd);
unsigned size;
u32 crc;
unsigned char localPAT[256];
unsigned char localPMT[256];
set_reg8(client, 0x41, h->video_format);
set_reg8(client, 0x40, (h->standard & V4L2_STD_525_60) ? 1 : 0);
saa6752hs_set_bitrate(client, h);
set_reg16(client, 0x72, 0x030d);
set_reg8(client, 0x82, 0x04);
set_reg8(client, 0x83, 0x0c);
set_reg8(client, 0xd0, 0x81);
set_reg8(client, 0xb0, 0x05);
set_reg16(client, 0xf6, leading_null_bytes);
memcpy(localPAT, PAT, sizeof(PAT));
localPAT[17] = 0xe0 | ((h->params.ts_pid_pmt >> 8) & 0x0f);
localPAT[18] = h->params.ts_pid_pmt & 0xff;
crc = crc32_be(~0, &localPAT[7], sizeof(PAT) - 7 - 4);
localPAT[sizeof(PAT) - 4] = (crc >> 24) & 0xFF;
localPAT[sizeof(PAT) - 3] = (crc >> 16) & 0xFF;
localPAT[sizeof(PAT) - 2] = (crc >> 8) & 0xFF;
localPAT[sizeof(PAT) - 1] = crc & 0xFF;
if (h->params.au_encoding == V4L2_MPEG_AUDIO_ENCODING_AC3) {
size = sizeof(PMT_AC3);
memcpy(localPMT, PMT_AC3, size);
} else {
size = sizeof(PMT);
memcpy(localPMT, PMT, size);
}
localPMT[3] = 0x40 | ((h->params.ts_pid_pmt >> 8) & 0x0f);
localPMT[4] = h->params.ts_pid_pmt & 0xff;
localPMT[15] = 0xE0 | ((h->params.ts_pid_pcr >> 8) & 0x0F);
localPMT[16] = h->params.ts_pid_pcr & 0xFF;
localPMT[20] = 0xE0 | ((h->params.ts_pid_video >> 8) & 0x0F);
localPMT[21] = h->params.ts_pid_video & 0xFF;
localPMT[25] = 0xE0 | ((h->params.ts_pid_audio >> 8) & 0x0F);
localPMT[26] = h->params.ts_pid_audio & 0xFF;
crc = crc32_be(~0, &localPMT[7], size - 7 - 4);
localPMT[size - 4] = (crc >> 24) & 0xFF;
localPMT[size - 3] = (crc >> 16) & 0xFF;
localPMT[size - 2] = (crc >> 8) & 0xFF;
localPMT[size - 1] = crc & 0xFF;
set_reg16(client, 0xc1, h->params.ts_pid_audio);
set_reg16(client, 0xc0, h->params.ts_pid_video);
set_reg16(client, 0xc4, h->params.ts_pid_pcr);
i2c_master_send(client, localPAT, sizeof(PAT));
i2c_master_send(client, localPMT, size);
set_reg8(client, 0xa4, 1);
set_reg8(client, 0xa4, 0);
saa6752hs_chip_command(client, SAA6752HS_COMMAND_START);
buf[0] = 0xE1;
buf[1] = 0xA7;
buf[2] = 0xFE;
buf[3] = 0x82;
buf[4] = 0xB0;
i2c_master_send(client, buf, 5);
i2c_master_recv(client, buf2, 4);
buf[0] = 0xE0;
buf[1] = 0xA7;
buf[2] = 0xFE;
buf[3] = 0x82;
buf[4] = 0xB0;
buf[5] = buf2[0];
switch (h->params.vi_aspect) {
case V4L2_MPEG_VIDEO_ASPECT_16x9:
buf[6] = buf2[1] | 0x40;
break;
case V4L2_MPEG_VIDEO_ASPECT_4x3:
default:
buf[6] = buf2[1] & 0xBF;
break;
}
buf[7] = buf2[2];
buf[8] = buf2[3];
i2c_master_send(client, buf, 9);
return 0;
}
static int saa6752hs_g_mbus_fmt(struct v4l2_subdev *sd, struct v4l2_mbus_framefmt *f)
{
struct saa6752hs_state *h = to_state(sd);
if (h->video_format == SAA6752HS_VF_UNKNOWN)
h->video_format = SAA6752HS_VF_D1;
f->width = v4l2_format_table[h->video_format].fmt.pix.width;
f->height = v4l2_format_table[h->video_format].fmt.pix.height;
f->code = MEDIA_BUS_FMT_FIXED;
f->field = V4L2_FIELD_INTERLACED;
f->colorspace = V4L2_COLORSPACE_SMPTE170M;
return 0;
}
static int saa6752hs_try_mbus_fmt(struct v4l2_subdev *sd, struct v4l2_mbus_framefmt *f)
{
int dist_352, dist_480, dist_720;
f->code = MEDIA_BUS_FMT_FIXED;
dist_352 = abs(f->width - 352);
dist_480 = abs(f->width - 480);
dist_720 = abs(f->width - 720);
if (dist_720 < dist_480) {
f->width = 720;
f->height = 576;
} else if (dist_480 < dist_352) {
f->width = 480;
f->height = 576;
} else {
f->width = 352;
if (abs(f->height - 576) < abs(f->height - 288))
f->height = 576;
else
f->height = 288;
}
f->field = V4L2_FIELD_INTERLACED;
f->colorspace = V4L2_COLORSPACE_SMPTE170M;
return 0;
}
static int saa6752hs_s_mbus_fmt(struct v4l2_subdev *sd, struct v4l2_mbus_framefmt *f)
{
struct saa6752hs_state *h = to_state(sd);
if (f->code != MEDIA_BUS_FMT_FIXED)
return -EINVAL;
saa6752hs_try_mbus_fmt(sd, f);
if (f->width == 720)
h->video_format = SAA6752HS_VF_D1;
else if (f->width == 480)
h->video_format = SAA6752HS_VF_2_3_D1;
else if (f->height == 576)
h->video_format = SAA6752HS_VF_1_2_D1;
else
h->video_format = SAA6752HS_VF_SIF;
return 0;
}
static int saa6752hs_s_std(struct v4l2_subdev *sd, v4l2_std_id std)
{
struct saa6752hs_state *h = to_state(sd);
h->standard = std;
return 0;
}
static int saa6752hs_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct saa6752hs_state *h;
struct v4l2_subdev *sd;
struct v4l2_ctrl_handler *hdl;
u8 addr = 0x13;
u8 data[12];
v4l_info(client, "chip found @ 0x%x (%s)\n",
client->addr << 1, client->adapter->name);
h = devm_kzalloc(&client->dev, sizeof(*h), GFP_KERNEL);
if (h == NULL)
return -ENOMEM;
sd = &h->sd;
v4l2_i2c_subdev_init(sd, client, &saa6752hs_ops);
i2c_master_send(client, &addr, 1);
i2c_master_recv(client, data, sizeof(data));
h->revision = (data[8] << 8) | data[9];
h->has_ac3 = 0;
if (h->revision == 0x0206) {
h->has_ac3 = 1;
v4l_info(client, "supports AC-3\n");
}
h->params = param_defaults;
hdl = &h->hdl;
v4l2_ctrl_handler_init(hdl, 14);
v4l2_ctrl_new_std_menu(hdl, &saa6752hs_ctrl_ops,
V4L2_CID_MPEG_AUDIO_ENCODING,
h->has_ac3 ? V4L2_MPEG_AUDIO_ENCODING_AC3 :
V4L2_MPEG_AUDIO_ENCODING_LAYER_2,
0x0d, V4L2_MPEG_AUDIO_ENCODING_LAYER_2);
v4l2_ctrl_new_std_menu(hdl, &saa6752hs_ctrl_ops,
V4L2_CID_MPEG_AUDIO_L2_BITRATE,
V4L2_MPEG_AUDIO_L2_BITRATE_384K,
~((1 << V4L2_MPEG_AUDIO_L2_BITRATE_256K) |
(1 << V4L2_MPEG_AUDIO_L2_BITRATE_384K)),
V4L2_MPEG_AUDIO_L2_BITRATE_256K);
if (h->has_ac3)
v4l2_ctrl_new_std_menu(hdl, &saa6752hs_ctrl_ops,
V4L2_CID_MPEG_AUDIO_AC3_BITRATE,
V4L2_MPEG_AUDIO_AC3_BITRATE_384K,
~((1 << V4L2_MPEG_AUDIO_AC3_BITRATE_256K) |
(1 << V4L2_MPEG_AUDIO_AC3_BITRATE_384K)),
V4L2_MPEG_AUDIO_AC3_BITRATE_256K);
v4l2_ctrl_new_std_menu(hdl, &saa6752hs_ctrl_ops,
V4L2_CID_MPEG_AUDIO_SAMPLING_FREQ,
V4L2_MPEG_AUDIO_SAMPLING_FREQ_48000,
~(1 << V4L2_MPEG_AUDIO_SAMPLING_FREQ_48000),
V4L2_MPEG_AUDIO_SAMPLING_FREQ_48000);
v4l2_ctrl_new_std_menu(hdl, &saa6752hs_ctrl_ops,
V4L2_CID_MPEG_VIDEO_ENCODING,
V4L2_MPEG_VIDEO_ENCODING_MPEG_2,
~(1 << V4L2_MPEG_VIDEO_ENCODING_MPEG_2),
V4L2_MPEG_VIDEO_ENCODING_MPEG_2);
v4l2_ctrl_new_std_menu(hdl, &saa6752hs_ctrl_ops,
V4L2_CID_MPEG_VIDEO_ASPECT,
V4L2_MPEG_VIDEO_ASPECT_16x9, 0x01,
V4L2_MPEG_VIDEO_ASPECT_4x3);
h->video_bitrate_peak = v4l2_ctrl_new_std(hdl, &saa6752hs_ctrl_ops,
V4L2_CID_MPEG_VIDEO_BITRATE_PEAK,
1000000, 27000000, 1000, 8000000);
v4l2_ctrl_new_std_menu(hdl, &saa6752hs_ctrl_ops,
V4L2_CID_MPEG_STREAM_TYPE,
V4L2_MPEG_STREAM_TYPE_MPEG2_TS,
~(1 << V4L2_MPEG_STREAM_TYPE_MPEG2_TS),
V4L2_MPEG_STREAM_TYPE_MPEG2_TS);
h->video_bitrate_mode = v4l2_ctrl_new_std_menu(hdl, &saa6752hs_ctrl_ops,
V4L2_CID_MPEG_VIDEO_BITRATE_MODE,
V4L2_MPEG_VIDEO_BITRATE_MODE_CBR, 0,
V4L2_MPEG_VIDEO_BITRATE_MODE_VBR);
h->video_bitrate = v4l2_ctrl_new_std(hdl, &saa6752hs_ctrl_ops,
V4L2_CID_MPEG_VIDEO_BITRATE, 1000000, 27000000, 1000, 6000000);
v4l2_ctrl_new_std(hdl, &saa6752hs_ctrl_ops,
V4L2_CID_MPEG_STREAM_PID_PMT, 0, (1 << 14) - 1, 1, 16);
v4l2_ctrl_new_std(hdl, &saa6752hs_ctrl_ops,
V4L2_CID_MPEG_STREAM_PID_AUDIO, 0, (1 << 14) - 1, 1, 260);
v4l2_ctrl_new_std(hdl, &saa6752hs_ctrl_ops,
V4L2_CID_MPEG_STREAM_PID_VIDEO, 0, (1 << 14) - 1, 1, 256);
v4l2_ctrl_new_std(hdl, &saa6752hs_ctrl_ops,
V4L2_CID_MPEG_STREAM_PID_PCR, 0, (1 << 14) - 1, 1, 259);
sd->ctrl_handler = hdl;
if (hdl->error) {
int err = hdl->error;
v4l2_ctrl_handler_free(hdl);
return err;
}
v4l2_ctrl_cluster(3, &h->video_bitrate_mode);
v4l2_ctrl_handler_setup(hdl);
h->standard = 0;
return 0;
}
static int saa6752hs_remove(struct i2c_client *client)
{
struct v4l2_subdev *sd = i2c_get_clientdata(client);
v4l2_device_unregister_subdev(sd);
v4l2_ctrl_handler_free(&to_state(sd)->hdl);
return 0;
}
