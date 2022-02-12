static inline struct cs5345_state *to_state(struct v4l2_subdev *sd)
{
return container_of(sd, struct cs5345_state, sd);
}
static inline struct v4l2_subdev *to_sd(struct v4l2_ctrl *ctrl)
{
return &container_of(ctrl->handler, struct cs5345_state, hdl)->sd;
}
static inline int cs5345_write(struct v4l2_subdev *sd, u8 reg, u8 value)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
return i2c_smbus_write_byte_data(client, reg, value);
}
static inline int cs5345_read(struct v4l2_subdev *sd, u8 reg)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
return i2c_smbus_read_byte_data(client, reg);
}
static int cs5345_s_routing(struct v4l2_subdev *sd,
u32 input, u32 output, u32 config)
{
if ((input & 0xf) > 6) {
v4l2_err(sd, "Invalid input %d.\n", input);
return -EINVAL;
}
cs5345_write(sd, 0x09, input & 0xf);
cs5345_write(sd, 0x05, input & 0xf0);
return 0;
}
static int cs5345_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct v4l2_subdev *sd = to_sd(ctrl);
switch (ctrl->id) {
case V4L2_CID_AUDIO_MUTE:
cs5345_write(sd, 0x04, ctrl->val ? 0x80 : 0);
return 0;
case V4L2_CID_AUDIO_VOLUME:
cs5345_write(sd, 0x07, ((u8)ctrl->val) & 0x3f);
cs5345_write(sd, 0x08, ((u8)ctrl->val) & 0x3f);
return 0;
}
return -EINVAL;
}
static int cs5345_g_register(struct v4l2_subdev *sd, struct v4l2_dbg_register *reg)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
if (!v4l2_chip_match_i2c_client(client, &reg->match))
return -EINVAL;
if (!capable(CAP_SYS_ADMIN))
return -EPERM;
reg->size = 1;
reg->val = cs5345_read(sd, reg->reg & 0x1f);
return 0;
}
static int cs5345_s_register(struct v4l2_subdev *sd, struct v4l2_dbg_register *reg)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
if (!v4l2_chip_match_i2c_client(client, &reg->match))
return -EINVAL;
if (!capable(CAP_SYS_ADMIN))
return -EPERM;
cs5345_write(sd, reg->reg & 0x1f, reg->val & 0xff);
return 0;
}
static int cs5345_g_chip_ident(struct v4l2_subdev *sd, struct v4l2_dbg_chip_ident *chip)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
return v4l2_chip_ident_i2c_client(client, chip, V4L2_IDENT_CS5345, 0);
}
static int cs5345_log_status(struct v4l2_subdev *sd)
{
u8 v = cs5345_read(sd, 0x09) & 7;
u8 m = cs5345_read(sd, 0x04);
int vol = cs5345_read(sd, 0x08) & 0x3f;
v4l2_info(sd, "Input: %d%s\n", v,
(m & 0x80) ? " (muted)" : "");
if (vol >= 32)
vol = vol - 64;
v4l2_info(sd, "Volume: %d dB\n", vol);
return 0;
}
static int cs5345_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct cs5345_state *state;
struct v4l2_subdev *sd;
if (!i2c_check_functionality(client->adapter, I2C_FUNC_SMBUS_BYTE_DATA))
return -EIO;
v4l_info(client, "chip found @ 0x%x (%s)\n",
client->addr << 1, client->adapter->name);
state = kzalloc(sizeof(struct cs5345_state), GFP_KERNEL);
if (state == NULL)
return -ENOMEM;
sd = &state->sd;
v4l2_i2c_subdev_init(sd, client, &cs5345_ops);
v4l2_ctrl_handler_init(&state->hdl, 2);
v4l2_ctrl_new_std(&state->hdl, &cs5345_ctrl_ops,
V4L2_CID_AUDIO_MUTE, 0, 1, 1, 0);
v4l2_ctrl_new_std(&state->hdl, &cs5345_ctrl_ops,
V4L2_CID_AUDIO_VOLUME, -24, 24, 1, 0);
sd->ctrl_handler = &state->hdl;
if (state->hdl.error) {
int err = state->hdl.error;
v4l2_ctrl_handler_free(&state->hdl);
kfree(state);
return err;
}
v4l2_ctrl_handler_setup(&state->hdl);
cs5345_write(sd, 0x02, 0x00);
cs5345_write(sd, 0x04, 0x01);
cs5345_write(sd, 0x09, 0x01);
return 0;
}
static int cs5345_remove(struct i2c_client *client)
{
struct v4l2_subdev *sd = i2c_get_clientdata(client);
struct cs5345_state *state = to_state(sd);
v4l2_device_unregister_subdev(sd);
v4l2_ctrl_handler_free(&state->hdl);
kfree(state);
return 0;
}
static __init int init_cs5345(void)
{
return i2c_add_driver(&cs5345_driver);
}
static __exit void exit_cs5345(void)
{
i2c_del_driver(&cs5345_driver);
}
