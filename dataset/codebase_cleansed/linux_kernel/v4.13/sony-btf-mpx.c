static inline struct sony_btf_mpx *to_state(struct v4l2_subdev *sd)
{
return container_of(sd, struct sony_btf_mpx, sd);
}
static int mpx_write(struct i2c_client *client, int dev, int addr, int val)
{
u8 buffer[5];
struct i2c_msg msg;
buffer[0] = dev;
buffer[1] = addr >> 8;
buffer[2] = addr & 0xff;
buffer[3] = val >> 8;
buffer[4] = val & 0xff;
msg.addr = client->addr;
msg.flags = 0;
msg.len = 5;
msg.buf = buffer;
i2c_transfer(client->adapter, &msg, 1);
return 0;
}
static int mpx_setup(struct sony_btf_mpx *t)
{
struct i2c_client *client = v4l2_get_subdevdata(&t->sd);
u16 source = 0;
u8 buffer[3];
struct i2c_msg msg;
int mode = t->mpxmode;
buffer[0] = 0x00;
buffer[1] = 0x80;
buffer[2] = 0x00;
msg.addr = client->addr;
msg.flags = 0;
msg.len = 3;
msg.buf = buffer;
i2c_transfer(client->adapter, &msg, 1);
buffer[1] = 0x00;
i2c_transfer(client->adapter, &msg, 1);
if (t->audmode != V4L2_TUNER_MODE_MONO)
mode++;
if (mpx_audio_modes[mode].audio_mode != AUD_MONO) {
switch (t->audmode) {
case V4L2_TUNER_MODE_MONO:
switch (mpx_audio_modes[mode].audio_mode) {
case AUD_A2:
source = mpx_audio_modes[mode].source;
break;
case AUD_NICAM:
source = 0x0000;
break;
case AUD_NICAM_L:
source = 0x0200;
break;
default:
break;
}
break;
case V4L2_TUNER_MODE_STEREO:
source = mpx_audio_modes[mode].source;
break;
case V4L2_TUNER_MODE_LANG1:
source = 0x0300;
break;
case V4L2_TUNER_MODE_LANG2:
source = 0x0400;
break;
}
source |= mpx_audio_modes[mode].source & 0x00ff;
} else
source = mpx_audio_modes[mode].source;
mpx_write(client, 0x10, 0x0030, mpx_audio_modes[mode].modus);
mpx_write(client, 0x12, 0x0008, source);
mpx_write(client, 0x12, 0x0013, mpx_audio_modes[mode].acb);
mpx_write(client, 0x12, 0x000e,
mpx_audio_modes[mode].fm_prescale);
mpx_write(client, 0x12, 0x0010,
mpx_audio_modes[mode].nicam_prescale);
mpx_write(client, 0x12, 0x000d,
mpx_audio_modes[mode].scart_prescale);
mpx_write(client, 0x10, 0x0020, mpx_audio_modes[mode].system);
mpx_write(client, 0x12, 0x0000, mpx_audio_modes[mode].volume);
if (mpx_audio_modes[mode].audio_mode == AUD_A2)
mpx_write(client, 0x10, 0x0022,
t->audmode == V4L2_TUNER_MODE_MONO ? 0x07f0 : 0x0190);
#ifdef MPX_DEBUG
{
u8 buf1[3], buf2[2];
struct i2c_msg msgs[2];
v4l2_info(client,
"MPX registers: %04x %04x %04x %04x %04x %04x %04x %04x\n",
mpx_audio_modes[mode].modus,
source,
mpx_audio_modes[mode].acb,
mpx_audio_modes[mode].fm_prescale,
mpx_audio_modes[mode].nicam_prescale,
mpx_audio_modes[mode].scart_prescale,
mpx_audio_modes[mode].system,
mpx_audio_modes[mode].volume);
buf1[0] = 0x11;
buf1[1] = 0x00;
buf1[2] = 0x7e;
msgs[0].addr = client->addr;
msgs[0].flags = 0;
msgs[0].len = 3;
msgs[0].buf = buf1;
msgs[1].addr = client->addr;
msgs[1].flags = I2C_M_RD;
msgs[1].len = 2;
msgs[1].buf = buf2;
i2c_transfer(client->adapter, msgs, 2);
v4l2_info(client, "MPX system: %02x%02x\n",
buf2[0], buf2[1]);
buf1[0] = 0x11;
buf1[1] = 0x02;
buf1[2] = 0x00;
i2c_transfer(client->adapter, msgs, 2);
v4l2_info(client, "MPX status: %02x%02x\n",
buf2[0], buf2[1]);
}
#endif
return 0;
}
static int sony_btf_mpx_s_std(struct v4l2_subdev *sd, v4l2_std_id std)
{
struct sony_btf_mpx *t = to_state(sd);
int default_mpx_mode = 0;
if (std & V4L2_STD_PAL_BG)
default_mpx_mode = 1;
else if (std & V4L2_STD_PAL_I)
default_mpx_mode = 4;
else if (std & V4L2_STD_PAL_DK)
default_mpx_mode = 6;
else if (std & V4L2_STD_SECAM_L)
default_mpx_mode = 11;
if (default_mpx_mode != t->mpxmode) {
t->mpxmode = default_mpx_mode;
mpx_setup(t);
}
return 0;
}
static int sony_btf_mpx_g_tuner(struct v4l2_subdev *sd, struct v4l2_tuner *vt)
{
struct sony_btf_mpx *t = to_state(sd);
vt->capability = V4L2_TUNER_CAP_NORM |
V4L2_TUNER_CAP_STEREO | V4L2_TUNER_CAP_LANG1 |
V4L2_TUNER_CAP_LANG2;
vt->rxsubchans = V4L2_TUNER_SUB_MONO |
V4L2_TUNER_SUB_STEREO | V4L2_TUNER_SUB_LANG1 |
V4L2_TUNER_SUB_LANG2;
vt->audmode = t->audmode;
return 0;
}
static int sony_btf_mpx_s_tuner(struct v4l2_subdev *sd, const struct v4l2_tuner *vt)
{
struct sony_btf_mpx *t = to_state(sd);
if (vt->type != V4L2_TUNER_ANALOG_TV)
return -EINVAL;
if (vt->audmode != t->audmode) {
t->audmode = vt->audmode;
mpx_setup(t);
}
return 0;
}
static int sony_btf_mpx_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct sony_btf_mpx *t;
struct v4l2_subdev *sd;
if (!i2c_check_functionality(client->adapter, I2C_FUNC_SMBUS_I2C_BLOCK))
return -ENODEV;
v4l_info(client, "chip found @ 0x%x (%s)\n",
client->addr << 1, client->adapter->name);
t = devm_kzalloc(&client->dev, sizeof(*t), GFP_KERNEL);
if (t == NULL)
return -ENOMEM;
sd = &t->sd;
v4l2_i2c_subdev_init(sd, client, &sony_btf_mpx_ops);
t->mpxmode = 0;
t->audmode = V4L2_TUNER_MODE_STEREO;
return 0;
}
static int sony_btf_mpx_remove(struct i2c_client *client)
{
struct v4l2_subdev *sd = i2c_get_clientdata(client);
v4l2_device_unregister_subdev(sd);
return 0;
}
