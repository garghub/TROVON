static inline struct wm8739_state *to_state(struct v4l2_subdev *sd)
{
return container_of(sd, struct wm8739_state, sd);
}
static inline struct v4l2_subdev *to_sd(struct v4l2_ctrl *ctrl)
{
return &container_of(ctrl->handler, struct wm8739_state, hdl)->sd;
}
static int wm8739_write(struct v4l2_subdev *sd, int reg, u16 val)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
int i;
if (reg < 0 || reg >= TOT_REGS) {
v4l2_err(sd, "Invalid register R%d\n", reg);
return -1;
}
v4l2_dbg(1, debug, sd, "write: %02x %02x\n", reg, val);
for (i = 0; i < 3; i++)
if (i2c_smbus_write_byte_data(client,
(reg << 1) | (val >> 8), val & 0xff) == 0)
return 0;
v4l2_err(sd, "I2C: cannot write %03x to register R%d\n", val, reg);
return -1;
}
static int wm8739_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct v4l2_subdev *sd = to_sd(ctrl);
struct wm8739_state *state = to_state(sd);
unsigned int work_l, work_r;
u8 vol_l;
u8 vol_r;
u16 mute;
switch (ctrl->id) {
case V4L2_CID_AUDIO_VOLUME:
break;
default:
return -EINVAL;
}
work_l = (min(65536 - state->balance->val, 32768) * state->volume->val) / 32768;
work_r = (min(state->balance->val, 32768) * state->volume->val) / 32768;
vol_l = (long)work_l * 31 / 65535;
vol_r = (long)work_r * 31 / 65535;
mute = state->mute->val ? 0x80 : 0;
wm8739_write(sd, R0, (vol_l & 0x1f) | mute);
wm8739_write(sd, R1, (vol_r & 0x1f) | mute);
return 0;
}
static int wm8739_s_clock_freq(struct v4l2_subdev *sd, u32 audiofreq)
{
struct wm8739_state *state = to_state(sd);
state->clock_freq = audiofreq;
wm8739_write(sd, R9, 0x000);
switch (audiofreq) {
case 44100:
wm8739_write(sd, R8, 0x020);
break;
case 48000:
wm8739_write(sd, R8, 0x000);
break;
case 32000:
wm8739_write(sd, R8, 0x018);
break;
default:
break;
}
wm8739_write(sd, R9, 0x001);
return 0;
}
static int wm8739_g_chip_ident(struct v4l2_subdev *sd, struct v4l2_dbg_chip_ident *chip)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
return v4l2_chip_ident_i2c_client(client, chip, V4L2_IDENT_WM8739, 0);
}
static int wm8739_log_status(struct v4l2_subdev *sd)
{
struct wm8739_state *state = to_state(sd);
v4l2_info(sd, "Frequency: %u Hz\n", state->clock_freq);
v4l2_ctrl_handler_log_status(&state->hdl, sd->name);
return 0;
}
static int wm8739_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct wm8739_state *state;
struct v4l2_subdev *sd;
if (!i2c_check_functionality(client->adapter, I2C_FUNC_SMBUS_BYTE_DATA))
return -EIO;
v4l_info(client, "chip found @ 0x%x (%s)\n",
client->addr << 1, client->adapter->name);
state = kzalloc(sizeof(struct wm8739_state), GFP_KERNEL);
if (state == NULL)
return -ENOMEM;
sd = &state->sd;
v4l2_i2c_subdev_init(sd, client, &wm8739_ops);
v4l2_ctrl_handler_init(&state->hdl, 2);
state->volume = v4l2_ctrl_new_std(&state->hdl, &wm8739_ctrl_ops,
V4L2_CID_AUDIO_VOLUME, 0, 65535, 65535 / 100, 50736);
state->mute = v4l2_ctrl_new_std(&state->hdl, &wm8739_ctrl_ops,
V4L2_CID_AUDIO_MUTE, 0, 1, 1, 0);
state->balance = v4l2_ctrl_new_std(&state->hdl, &wm8739_ctrl_ops,
V4L2_CID_AUDIO_BALANCE, 0, 65535, 65535 / 100, 32768);
sd->ctrl_handler = &state->hdl;
if (state->hdl.error) {
int err = state->hdl.error;
v4l2_ctrl_handler_free(&state->hdl);
kfree(state);
return err;
}
v4l2_ctrl_cluster(3, &state->volume);
state->clock_freq = 48000;
wm8739_write(sd, R15, 0x00);
wm8739_write(sd, R5, 0x000);
wm8739_write(sd, R6, 0x000);
wm8739_write(sd, R7, 0x049);
wm8739_write(sd, R8, 0x000);
wm8739_write(sd, R9, 0x001);
v4l2_ctrl_handler_setup(&state->hdl);
return 0;
}
static int wm8739_remove(struct i2c_client *client)
{
struct v4l2_subdev *sd = i2c_get_clientdata(client);
struct wm8739_state *state = to_state(sd);
v4l2_device_unregister_subdev(sd);
v4l2_ctrl_handler_free(&state->hdl);
kfree(to_state(sd));
return 0;
}
