static inline struct vp27smpx_state *to_state(struct v4l2_subdev *sd)
{
return container_of(sd, struct vp27smpx_state, sd);
}
static void vp27smpx_set_audmode(struct v4l2_subdev *sd, u32 audmode)
{
struct vp27smpx_state *state = to_state(sd);
struct i2c_client *client = v4l2_get_subdevdata(sd);
u8 data[3] = { 0x00, 0x00, 0x04 };
switch (audmode) {
case V4L2_TUNER_MODE_MONO:
case V4L2_TUNER_MODE_LANG1:
break;
case V4L2_TUNER_MODE_STEREO:
case V4L2_TUNER_MODE_LANG1_LANG2:
data[1] = 0x01;
break;
case V4L2_TUNER_MODE_LANG2:
data[1] = 0x02;
break;
}
if (i2c_master_send(client, data, sizeof(data)) != sizeof(data))
v4l2_err(sd, "I/O error setting audmode\n");
else
state->audmode = audmode;
}
static int vp27smpx_s_radio(struct v4l2_subdev *sd)
{
struct vp27smpx_state *state = to_state(sd);
state->radio = 1;
return 0;
}
static int vp27smpx_s_std(struct v4l2_subdev *sd, v4l2_std_id norm)
{
struct vp27smpx_state *state = to_state(sd);
state->radio = 0;
return 0;
}
static int vp27smpx_s_tuner(struct v4l2_subdev *sd, struct v4l2_tuner *vt)
{
struct vp27smpx_state *state = to_state(sd);
if (!state->radio)
vp27smpx_set_audmode(sd, vt->audmode);
return 0;
}
static int vp27smpx_g_tuner(struct v4l2_subdev *sd, struct v4l2_tuner *vt)
{
struct vp27smpx_state *state = to_state(sd);
if (state->radio)
return 0;
vt->audmode = state->audmode;
vt->capability = V4L2_TUNER_CAP_STEREO |
V4L2_TUNER_CAP_LANG1 | V4L2_TUNER_CAP_LANG2;
vt->rxsubchans = V4L2_TUNER_SUB_MONO;
return 0;
}
static int vp27smpx_g_chip_ident(struct v4l2_subdev *sd, struct v4l2_dbg_chip_ident *chip)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
return v4l2_chip_ident_i2c_client(client, chip, V4L2_IDENT_VP27SMPX, 0);
}
static int vp27smpx_log_status(struct v4l2_subdev *sd)
{
struct vp27smpx_state *state = to_state(sd);
v4l2_info(sd, "Audio Mode: %u%s\n", state->audmode,
state->radio ? " (Radio)" : "");
return 0;
}
static int vp27smpx_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct vp27smpx_state *state;
struct v4l2_subdev *sd;
if (!i2c_check_functionality(client->adapter, I2C_FUNC_SMBUS_BYTE_DATA))
return -EIO;
v4l_info(client, "chip found @ 0x%x (%s)\n",
client->addr << 1, client->adapter->name);
state = kzalloc(sizeof(struct vp27smpx_state), GFP_KERNEL);
if (state == NULL)
return -ENOMEM;
sd = &state->sd;
v4l2_i2c_subdev_init(sd, client, &vp27smpx_ops);
state->audmode = V4L2_TUNER_MODE_STEREO;
vp27smpx_set_audmode(sd, state->audmode);
return 0;
}
static int vp27smpx_remove(struct i2c_client *client)
{
struct v4l2_subdev *sd = i2c_get_clientdata(client);
v4l2_device_unregister_subdev(sd);
kfree(to_state(sd));
return 0;
}
static __init int init_vp27smpx(void)
{
return i2c_add_driver(&vp27smpx_driver);
}
static __exit void exit_vp27smpx(void)
{
i2c_del_driver(&vp27smpx_driver);
}
