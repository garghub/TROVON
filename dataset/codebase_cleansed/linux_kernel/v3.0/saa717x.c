static inline struct saa717x_state *to_state(struct v4l2_subdev *sd)
{
return container_of(sd, struct saa717x_state, sd);
}
static inline struct v4l2_subdev *to_sd(struct v4l2_ctrl *ctrl)
{
return &container_of(ctrl->handler, struct saa717x_state, hdl)->sd;
}
static int saa717x_write(struct v4l2_subdev *sd, u32 reg, u32 value)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct i2c_adapter *adap = client->adapter;
int fw_addr = reg == 0x454 || (reg >= 0x464 && reg <= 0x478) || reg == 0x480 || reg == 0x488;
unsigned char mm1[6];
struct i2c_msg msg;
msg.flags = 0;
msg.addr = client->addr;
mm1[0] = (reg >> 8) & 0xff;
mm1[1] = reg & 0xff;
if (fw_addr) {
mm1[4] = (value >> 16) & 0xff;
mm1[3] = (value >> 8) & 0xff;
mm1[2] = value & 0xff;
} else {
mm1[2] = value & 0xff;
}
msg.len = fw_addr ? 5 : 3;
msg.buf = mm1;
v4l2_dbg(2, debug, sd, "wrote: reg 0x%03x=%08x\n", reg, value);
return i2c_transfer(adap, &msg, 1) == 1;
}
static void saa717x_write_regs(struct v4l2_subdev *sd, u32 *data)
{
while (data[0] || data[1]) {
saa717x_write(sd, data[0], data[1]);
data += 2;
}
}
static u32 saa717x_read(struct v4l2_subdev *sd, u32 reg)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct i2c_adapter *adap = client->adapter;
int fw_addr = (reg >= 0x404 && reg <= 0x4b8) || reg == 0x528;
unsigned char mm1[2];
unsigned char mm2[4] = { 0, 0, 0, 0 };
struct i2c_msg msgs[2];
u32 value;
msgs[0].flags = 0;
msgs[1].flags = I2C_M_RD;
msgs[0].addr = msgs[1].addr = client->addr;
mm1[0] = (reg >> 8) & 0xff;
mm1[1] = reg & 0xff;
msgs[0].len = 2;
msgs[0].buf = mm1;
msgs[1].len = fw_addr ? 3 : 1;
msgs[1].buf = mm2;
i2c_transfer(adap, msgs, 2);
if (fw_addr)
value = (mm2[2] & 0xff) | ((mm2[1] & 0xff) >> 8) | ((mm2[0] & 0xff) >> 16);
else
value = mm2[0] & 0xff;
v4l2_dbg(2, debug, sd, "read: reg 0x%03x=0x%08x\n", reg, value);
return value;
}
static void get_inf_dev_status(struct v4l2_subdev *sd,
int *dual_flag, int *stereo_flag)
{
u32 reg_data3;
static char *stdres[0x20] = {
[0x00] = "no standard detected",
[0x01] = "B/G (in progress)",
[0x02] = "D/K (in progress)",
[0x03] = "M (in progress)",
[0x04] = "B/G A2",
[0x05] = "B/G NICAM",
[0x06] = "D/K A2 (1)",
[0x07] = "D/K A2 (2)",
[0x08] = "D/K A2 (3)",
[0x09] = "D/K NICAM",
[0x0a] = "L NICAM",
[0x0b] = "I NICAM",
[0x0c] = "M Korea",
[0x0d] = "M BTSC ",
[0x0e] = "M EIAJ",
[0x0f] = "FM radio / IF 10.7 / 50 deemp",
[0x10] = "FM radio / IF 10.7 / 75 deemp",
[0x11] = "FM radio / IF sel / 50 deemp",
[0x12] = "FM radio / IF sel / 75 deemp",
[0x13 ... 0x1e] = "unknown",
[0x1f] = "??? [in progress]",
};
*dual_flag = *stereo_flag = 0;
reg_data3 = saa717x_read(sd, 0x0528);
v4l2_dbg(1, debug, sd, "tvaudio thread status: 0x%x [%s%s%s]\n",
reg_data3, stdres[reg_data3 & 0x1f],
(reg_data3 & 0x000020) ? ",stereo" : "",
(reg_data3 & 0x000040) ? ",dual" : "");
v4l2_dbg(1, debug, sd, "detailed status: "
"%s#%s#%s#%s#%s#%s#%s#%s#%s#%s#%s#%s#%s#%s\n",
(reg_data3 & 0x000080) ? " A2/EIAJ pilot tone " : "",
(reg_data3 & 0x000100) ? " A2/EIAJ dual " : "",
(reg_data3 & 0x000200) ? " A2/EIAJ stereo " : "",
(reg_data3 & 0x000400) ? " A2/EIAJ noise mute " : "",
(reg_data3 & 0x000800) ? " BTSC/FM radio pilot " : "",
(reg_data3 & 0x001000) ? " SAP carrier " : "",
(reg_data3 & 0x002000) ? " BTSC stereo noise mute " : "",
(reg_data3 & 0x004000) ? " SAP noise mute " : "",
(reg_data3 & 0x008000) ? " VDSP " : "",
(reg_data3 & 0x010000) ? " NICST " : "",
(reg_data3 & 0x020000) ? " NICDU " : "",
(reg_data3 & 0x040000) ? " NICAM muted " : "",
(reg_data3 & 0x080000) ? " NICAM reserve sound " : "",
(reg_data3 & 0x100000) ? " init done " : "");
if (reg_data3 & 0x000220) {
v4l2_dbg(1, debug, sd, "ST!!!\n");
*stereo_flag = 1;
}
if (reg_data3 & 0x000140) {
v4l2_dbg(1, debug, sd, "DUAL!!!\n");
*dual_flag = 1;
}
}
static void set_audio_mode(struct v4l2_subdev *sd, int audio_mode)
{
v4l2_dbg(1, debug, sd, "writing registers to set audio mode by set %d\n",
audio_mode);
saa717x_write(sd, 0x46c, reg_set_audio_template[audio_mode][0]);
saa717x_write(sd, 0x470, reg_set_audio_template[audio_mode][1]);
}
static int set_audio_regs(struct v4l2_subdev *sd,
struct saa717x_state *decoder)
{
u8 mute = 0xac;
u32 val;
unsigned int work_l, work_r;
saa717x_write(sd, 0x0594, decoder->audio_input);
v4l2_dbg(1, debug, sd, "set audio input %d\n",
decoder->audio_input);
work_l = (min(65536 - decoder->audio_main_balance, 32768) * decoder->audio_main_volume) / 32768;
work_r = (min(decoder->audio_main_balance, (u16)32768) * decoder->audio_main_volume) / 32768;
decoder->audio_main_vol_l = (long)work_l * (24 - (-40)) / 65535 - 40;
decoder->audio_main_vol_r = (long)work_r * (24 - (-40)) / 65535 - 40;
if (decoder->audio_main_mute) {
val = mute | (mute << 8);
} else {
val = (u8)decoder->audio_main_vol_l |
((u8)decoder->audio_main_vol_r << 8);
}
saa717x_write(sd, 0x480, val);
val = decoder->audio_main_bass & 0x1f;
val |= (decoder->audio_main_treble & 0x1f) << 5;
saa717x_write(sd, 0x488, val);
return 0;
}
static void set_h_prescale(struct v4l2_subdev *sd,
int task, int prescale)
{
static const struct {
int xpsc;
int xacl;
int xc2_1;
int xdcg;
int vpfy;
} vals[] = {
{ 1, 0, 0, 0, 0 },
{ 2, 2, 1, 2, 2 },
{ 3, 4, 1, 3, 2 },
{ 4, 8, 1, 4, 2 },
{ 5, 8, 1, 4, 2 },
{ 6, 8, 1, 4, 3 },
{ 7, 8, 1, 4, 3 },
{ 8, 15, 0, 4, 3 },
{ 9, 15, 0, 4, 3 },
{ 10, 16, 1, 5, 3 },
};
static const int count = ARRAY_SIZE(vals);
int i, task_shift;
task_shift = task * 0x40;
for (i = 0; i < count; i++)
if (vals[i].xpsc == prescale)
break;
if (i == count)
return;
saa717x_write(sd, 0x60 + task_shift, vals[i].xpsc);
saa717x_write(sd, 0x61 + task_shift, vals[i].xacl);
saa717x_write(sd, 0x62 + task_shift,
(vals[i].xc2_1 << 3) | vals[i].xdcg);
saa717x_write(sd, 0x63 + task_shift,
(vals[i].vpfy << 2) | vals[i].vpfy);
}
static void set_v_scale(struct v4l2_subdev *sd, int task, int yscale)
{
int task_shift;
task_shift = task * 0x40;
saa717x_write(sd, 0x70 + task_shift, yscale & 0xff);
saa717x_write(sd, 0x71 + task_shift, yscale >> 8);
}
static int saa717x_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct v4l2_subdev *sd = to_sd(ctrl);
struct saa717x_state *state = to_state(sd);
switch (ctrl->id) {
case V4L2_CID_BRIGHTNESS:
saa717x_write(sd, 0x10a, ctrl->val);
return 0;
case V4L2_CID_CONTRAST:
saa717x_write(sd, 0x10b, ctrl->val);
return 0;
case V4L2_CID_SATURATION:
saa717x_write(sd, 0x10c, ctrl->val);
return 0;
case V4L2_CID_HUE:
saa717x_write(sd, 0x10d, ctrl->val);
return 0;
case V4L2_CID_AUDIO_MUTE:
state->audio_main_mute = ctrl->val;
break;
case V4L2_CID_AUDIO_VOLUME:
state->audio_main_volume = ctrl->val;
break;
case V4L2_CID_AUDIO_BALANCE:
state->audio_main_balance = ctrl->val;
break;
case V4L2_CID_AUDIO_TREBLE:
state->audio_main_treble = ctrl->val;
break;
case V4L2_CID_AUDIO_BASS:
state->audio_main_bass = ctrl->val;
break;
default:
return 0;
}
set_audio_regs(sd, state);
return 0;
}
static int saa717x_s_video_routing(struct v4l2_subdev *sd,
u32 input, u32 output, u32 config)
{
struct saa717x_state *decoder = to_state(sd);
int is_tuner = input & 0x80;
input &= 0x7f;
v4l2_dbg(1, debug, sd, "decoder set input (%d)\n", input);
if (input > 9 || input == 5)
return -EINVAL;
if (decoder->input != input) {
int input_line = input;
decoder->input = input_line;
v4l2_dbg(1, debug, sd, "now setting %s input %d\n",
input_line >= 6 ? "S-Video" : "Composite",
input_line);
saa717x_write(sd, 0x102,
(saa717x_read(sd, 0x102) & 0xf0) |
input_line);
saa717x_write(sd, 0x109,
(saa717x_read(sd, 0x109) & 0x7f) |
(input_line < 6 ? 0x0 : 0x80));
if (is_tuner) {
set_audio_mode(sd, decoder->tuner_audio_mode);
} else {
set_audio_mode(sd, TUNER_AUDIO_STEREO);
}
if (is_tuner)
saa717x_write_regs(sd, reg_init_tuner_input);
else if (input_line >= 6)
saa717x_write_regs(sd, reg_init_svideo_input);
else
saa717x_write_regs(sd, reg_init_composite_input);
}
return 0;
}
static int saa717x_g_register(struct v4l2_subdev *sd, struct v4l2_dbg_register *reg)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
if (!v4l2_chip_match_i2c_client(client, &reg->match))
return -EINVAL;
if (!capable(CAP_SYS_ADMIN))
return -EPERM;
reg->val = saa717x_read(sd, reg->reg);
reg->size = 1;
return 0;
}
static int saa717x_s_register(struct v4l2_subdev *sd, struct v4l2_dbg_register *reg)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
u16 addr = reg->reg & 0xffff;
u8 val = reg->val & 0xff;
if (!v4l2_chip_match_i2c_client(client, &reg->match))
return -EINVAL;
if (!capable(CAP_SYS_ADMIN))
return -EPERM;
saa717x_write(sd, addr, val);
return 0;
}
static int saa717x_s_mbus_fmt(struct v4l2_subdev *sd, struct v4l2_mbus_framefmt *fmt)
{
int prescale, h_scale, v_scale;
v4l2_dbg(1, debug, sd, "decoder set size\n");
if (fmt->code != V4L2_MBUS_FMT_FIXED)
return -EINVAL;
if (fmt->width < 1 || fmt->width > 1440)
return -EINVAL;
if (fmt->height < 1 || fmt->height > 960)
return -EINVAL;
fmt->field = V4L2_FIELD_INTERLACED;
fmt->colorspace = V4L2_COLORSPACE_SMPTE170M;
prescale = SAA717X_NTSC_WIDTH / fmt->width;
if (prescale == 0)
prescale = 1;
h_scale = 1024 * SAA717X_NTSC_WIDTH / prescale / fmt->width;
v_scale = 512 * 2 * SAA717X_NTSC_HEIGHT / fmt->height;
set_h_prescale(sd, 0, prescale);
set_h_prescale(sd, 1, prescale);
saa717x_write(sd, 0x6C, (u8)(h_scale & 0xFF));
saa717x_write(sd, 0x6D, (u8)((h_scale >> 8) & 0xFF));
saa717x_write(sd, 0xAC, (u8)(h_scale & 0xFF));
saa717x_write(sd, 0xAD, (u8)((h_scale >> 8) & 0xFF));
set_v_scale(sd, 0, v_scale);
set_v_scale(sd, 1, v_scale);
saa717x_write(sd, 0x5C, (u8)(fmt->width & 0xFF));
saa717x_write(sd, 0x5D, (u8)((fmt->width >> 8) & 0xFF));
saa717x_write(sd, 0x9C, (u8)(fmt->width & 0xFF));
saa717x_write(sd, 0x9D, (u8)((fmt->width >> 8) & 0xFF));
saa717x_write(sd, 0x5E, (u8)(fmt->height & 0xFF));
saa717x_write(sd, 0x5F, (u8)((fmt->height >> 8) & 0xFF));
saa717x_write(sd, 0x9E, (u8)(fmt->height & 0xFF));
saa717x_write(sd, 0x9F, (u8)((fmt->height >> 8) & 0xFF));
return 0;
}
static int saa717x_s_radio(struct v4l2_subdev *sd)
{
struct saa717x_state *decoder = to_state(sd);
decoder->radio = 1;
return 0;
}
static int saa717x_s_std(struct v4l2_subdev *sd, v4l2_std_id std)
{
struct saa717x_state *decoder = to_state(sd);
v4l2_dbg(1, debug, sd, "decoder set norm ");
v4l2_dbg(1, debug, sd, "(not yet implementd)\n");
decoder->radio = 0;
decoder->std = std;
return 0;
}
static int saa717x_s_audio_routing(struct v4l2_subdev *sd,
u32 input, u32 output, u32 config)
{
struct saa717x_state *decoder = to_state(sd);
if (input < 3) {
decoder->audio_input = input;
v4l2_dbg(1, debug, sd,
"set decoder audio input to %d\n",
decoder->audio_input);
set_audio_regs(sd, decoder);
return 0;
}
return -ERANGE;
}
static int saa717x_s_stream(struct v4l2_subdev *sd, int enable)
{
struct saa717x_state *decoder = to_state(sd);
v4l2_dbg(1, debug, sd, "decoder %s output\n",
enable ? "enable" : "disable");
decoder->enable = enable;
saa717x_write(sd, 0x193, enable ? 0xa6 : 0x26);
return 0;
}
static int saa717x_s_tuner(struct v4l2_subdev *sd, struct v4l2_tuner *vt)
{
struct saa717x_state *decoder = to_state(sd);
int audio_mode;
char *mes[4] = {
"MONO", "STEREO", "LANG1", "LANG2/SAP"
};
audio_mode = TUNER_AUDIO_STEREO;
switch (vt->audmode) {
case V4L2_TUNER_MODE_MONO:
audio_mode = TUNER_AUDIO_MONO;
break;
case V4L2_TUNER_MODE_STEREO:
audio_mode = TUNER_AUDIO_STEREO;
break;
case V4L2_TUNER_MODE_LANG2:
audio_mode = TUNER_AUDIO_LANG2;
break;
case V4L2_TUNER_MODE_LANG1:
audio_mode = TUNER_AUDIO_LANG1;
break;
}
v4l2_dbg(1, debug, sd, "change audio mode to %s\n",
mes[audio_mode]);
decoder->tuner_audio_mode = audio_mode;
set_audio_mode(sd, decoder->tuner_audio_mode);
return 0;
}
static int saa717x_g_tuner(struct v4l2_subdev *sd, struct v4l2_tuner *vt)
{
struct saa717x_state *decoder = to_state(sd);
int dual_f, stereo_f;
if (decoder->radio)
return 0;
get_inf_dev_status(sd, &dual_f, &stereo_f);
v4l2_dbg(1, debug, sd, "DETECT==st:%d dual:%d\n",
stereo_f, dual_f);
if ((dual_f == 0) && (stereo_f == 0)) {
vt->rxsubchans = V4L2_TUNER_SUB_MONO;
v4l2_dbg(1, debug, sd, "DETECT==MONO\n");
}
if (stereo_f == 1) {
if (vt->audmode == V4L2_TUNER_MODE_STEREO ||
vt->audmode == V4L2_TUNER_MODE_LANG1) {
vt->rxsubchans = V4L2_TUNER_SUB_STEREO;
v4l2_dbg(1, debug, sd, "DETECT==ST(ST)\n");
} else {
vt->rxsubchans = V4L2_TUNER_SUB_MONO;
v4l2_dbg(1, debug, sd, "DETECT==ST(MONO)\n");
}
}
if (dual_f == 1) {
if (vt->audmode == V4L2_TUNER_MODE_LANG2) {
vt->rxsubchans = V4L2_TUNER_SUB_LANG2 | V4L2_TUNER_SUB_MONO;
v4l2_dbg(1, debug, sd, "DETECT==DUAL1\n");
} else {
vt->rxsubchans = V4L2_TUNER_SUB_LANG1 | V4L2_TUNER_SUB_MONO;
v4l2_dbg(1, debug, sd, "DETECT==DUAL2\n");
}
}
return 0;
}
static int saa717x_log_status(struct v4l2_subdev *sd)
{
struct saa717x_state *state = to_state(sd);
v4l2_ctrl_handler_log_status(&state->hdl, sd->name);
return 0;
}
static int saa717x_probe(struct i2c_client *client,
const struct i2c_device_id *did)
{
struct saa717x_state *decoder;
struct v4l2_ctrl_handler *hdl;
struct v4l2_subdev *sd;
u8 id = 0;
char *p = "";
if (!i2c_check_functionality(client->adapter, I2C_FUNC_SMBUS_BYTE_DATA))
return -EIO;
decoder = kzalloc(sizeof(struct saa717x_state), GFP_KERNEL);
if (decoder == NULL)
return -ENOMEM;
sd = &decoder->sd;
v4l2_i2c_subdev_init(sd, client, &saa717x_ops);
if (saa717x_write(sd, 0x5a4, 0xfe) &&
saa717x_write(sd, 0x5a5, 0x0f) &&
saa717x_write(sd, 0x5a6, 0x00) &&
saa717x_write(sd, 0x5a7, 0x01))
id = saa717x_read(sd, 0x5a0);
if (id != 0xc2 && id != 0x32 && id != 0xf2 && id != 0x6c) {
v4l2_dbg(1, debug, sd, "saa717x not found (id=%02x)\n", id);
kfree(decoder);
return -ENODEV;
}
if (id == 0xc2)
p = "saa7173";
else if (id == 0x32)
p = "saa7174A";
else if (id == 0x6c)
p = "saa7174HL";
else
p = "saa7171";
v4l2_info(sd, "%s found @ 0x%x (%s)\n", p,
client->addr << 1, client->adapter->name);
hdl = &decoder->hdl;
v4l2_ctrl_handler_init(hdl, 9);
v4l2_ctrl_new_std(hdl, &saa717x_ctrl_ops,
V4L2_CID_BRIGHTNESS, 0, 255, 1, 128);
v4l2_ctrl_new_std(hdl, &saa717x_ctrl_ops,
V4L2_CID_CONTRAST, 0, 255, 1, 68);
v4l2_ctrl_new_std(hdl, &saa717x_ctrl_ops,
V4L2_CID_SATURATION, 0, 255, 1, 64);
v4l2_ctrl_new_std(hdl, &saa717x_ctrl_ops,
V4L2_CID_HUE, -128, 127, 1, 0);
v4l2_ctrl_new_std(hdl, &saa717x_ctrl_ops,
V4L2_CID_AUDIO_VOLUME, 0, 65535, 65535 / 100, 42000);
v4l2_ctrl_new_std(hdl, &saa717x_ctrl_ops,
V4L2_CID_AUDIO_BALANCE, 0, 65535, 65535 / 100, 32768);
v4l2_ctrl_new_std(hdl, &saa717x_ctrl_ops,
V4L2_CID_AUDIO_BASS, -16, 15, 1, 0);
v4l2_ctrl_new_std(hdl, &saa717x_ctrl_ops,
V4L2_CID_AUDIO_TREBLE, -16, 15, 1, 0);
v4l2_ctrl_new_std(hdl, &saa717x_ctrl_ops,
V4L2_CID_AUDIO_MUTE, 0, 1, 1, 0);
sd->ctrl_handler = hdl;
if (hdl->error) {
int err = hdl->error;
v4l2_ctrl_handler_free(hdl);
kfree(decoder);
return err;
}
decoder->std = V4L2_STD_NTSC;
decoder->input = -1;
decoder->enable = 1;
decoder->playback = 0;
decoder->audio = 1;
decoder->audio_input = 2;
decoder->tuner_audio_mode = TUNER_AUDIO_STEREO;
decoder->audio_main_vol_l = 6;
decoder->audio_main_vol_r = 6;
v4l2_dbg(1, debug, sd, "writing init values\n");
saa717x_write_regs(sd, reg_init_initialize);
v4l2_ctrl_handler_setup(hdl);
set_current_state(TASK_INTERRUPTIBLE);
schedule_timeout(2*HZ);
return 0;
}
static int saa717x_remove(struct i2c_client *client)
{
struct v4l2_subdev *sd = i2c_get_clientdata(client);
v4l2_device_unregister_subdev(sd);
v4l2_ctrl_handler_free(sd->ctrl_handler);
kfree(to_state(sd));
return 0;
}
static __init int init_saa717x(void)
{
return i2c_add_driver(&saa717x_driver);
}
static __exit void exit_saa717x(void)
{
i2c_del_driver(&saa717x_driver);
}
