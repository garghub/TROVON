static inline struct wm8775_state *to_state(struct v4l2_subdev *sd)
{
return container_of(sd, struct wm8775_state, sd);
}
static inline struct v4l2_subdev *to_sd(struct v4l2_ctrl *ctrl)
{
return &container_of(ctrl->handler, struct wm8775_state, hdl)->sd;
}
static int wm8775_write(struct v4l2_subdev *sd, int reg, u16 val)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
int i;
if (reg < 0 || reg >= TOT_REGS) {
v4l2_err(sd, "Invalid register R%d\n", reg);
return -1;
}
for (i = 0; i < 3; i++)
if (i2c_smbus_write_byte_data(client,
(reg << 1) | (val >> 8), val & 0xff) == 0)
return 0;
v4l2_err(sd, "I2C: cannot write %03x to register R%d\n", val, reg);
return -1;
}
static void wm8775_set_audio(struct v4l2_subdev *sd, int quietly)
{
struct wm8775_state *state = to_state(sd);
u8 vol_l, vol_r;
int muted = 0 != state->mute->val;
u16 volume = (u16)state->vol->val;
u16 balance = (u16)state->bal->val;
vol_l = (min(65536 - balance, 32768) * volume) >> 23;
vol_r = (min(balance, (u16)32768) * volume) >> 23;
if (muted || quietly)
wm8775_write(sd, R21, 0x0c0 | state->input);
wm8775_write(sd, R14, vol_l | 0x100);
wm8775_write(sd, R15, vol_r | 0x100);
if (!muted)
wm8775_write(sd, R21, state->input);
}
static int wm8775_s_routing(struct v4l2_subdev *sd,
u32 input, u32 output, u32 config)
{
struct wm8775_state *state = to_state(sd);
if (input > 15) {
v4l2_err(sd, "Invalid input %d.\n", input);
return -EINVAL;
}
state->input = input;
if (!v4l2_ctrl_g_ctrl(state->mute))
return 0;
if (!v4l2_ctrl_g_ctrl(state->vol))
return 0;
if (!v4l2_ctrl_g_ctrl(state->bal))
return 0;
wm8775_set_audio(sd, 1);
return 0;
}
static int wm8775_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct v4l2_subdev *sd = to_sd(ctrl);
switch (ctrl->id) {
case V4L2_CID_AUDIO_MUTE:
case V4L2_CID_AUDIO_VOLUME:
case V4L2_CID_AUDIO_BALANCE:
wm8775_set_audio(sd, 0);
return 0;
case V4L2_CID_AUDIO_LOUDNESS:
wm8775_write(sd, R17, (ctrl->val ? ALC_EN : 0) | ALC_HOLD);
return 0;
}
return -EINVAL;
}
static int wm8775_log_status(struct v4l2_subdev *sd)
{
struct wm8775_state *state = to_state(sd);
v4l2_info(sd, "Input: %d\n", state->input);
v4l2_ctrl_handler_log_status(&state->hdl, sd->name);
return 0;
}
static int wm8775_s_frequency(struct v4l2_subdev *sd, const struct v4l2_frequency *freq)
{
wm8775_set_audio(sd, 0);
return 0;
}
static int wm8775_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct wm8775_state *state;
struct v4l2_subdev *sd;
int err;
bool is_nova_s = false;
if (client->dev.platform_data) {
struct wm8775_platform_data *data = client->dev.platform_data;
is_nova_s = data->is_nova_s;
}
if (!i2c_check_functionality(client->adapter, I2C_FUNC_SMBUS_BYTE_DATA))
return -EIO;
v4l_info(client, "chip found @ 0x%02x (%s)\n",
client->addr << 1, client->adapter->name);
state = devm_kzalloc(&client->dev, sizeof(*state), GFP_KERNEL);
if (state == NULL)
return -ENOMEM;
sd = &state->sd;
v4l2_i2c_subdev_init(sd, client, &wm8775_ops);
state->input = 2;
v4l2_ctrl_handler_init(&state->hdl, 4);
state->mute = v4l2_ctrl_new_std(&state->hdl, &wm8775_ctrl_ops,
V4L2_CID_AUDIO_MUTE, 0, 1, 1, 0);
state->vol = v4l2_ctrl_new_std(&state->hdl, &wm8775_ctrl_ops,
V4L2_CID_AUDIO_VOLUME, 0, 65535, (65535+99)/100, 0xCF00);
state->bal = v4l2_ctrl_new_std(&state->hdl, &wm8775_ctrl_ops,
V4L2_CID_AUDIO_BALANCE, 0, 65535, (65535+99)/100, 32768);
state->loud = v4l2_ctrl_new_std(&state->hdl, &wm8775_ctrl_ops,
V4L2_CID_AUDIO_LOUDNESS, 0, 1, 1, 1);
sd->ctrl_handler = &state->hdl;
err = state->hdl.error;
if (err) {
v4l2_ctrl_handler_free(&state->hdl);
return err;
}
wm8775_write(sd, R23, 0x000);
wm8775_write(sd, R7, 0x000);
wm8775_write(sd, R11, 0x021);
wm8775_write(sd, R12, 0x102);
wm8775_write(sd, R13, 0x000);
if (!is_nova_s) {
wm8775_write(sd, R14, 0x1d4);
wm8775_write(sd, R15, 0x1d4);
wm8775_write(sd, R16, 0x1bf);
wm8775_write(sd, R17, 0x185);
} else {
wm8775_write(sd, R16, 0x1bb);
wm8775_write(sd, R17, (state->loud->val ? ALC_EN : 0) | ALC_HOLD);
}
wm8775_write(sd, R18, 0x0a2);
wm8775_write(sd, R19, 0x005);
if (!is_nova_s) {
wm8775_write(sd, R20, 0x07a);
wm8775_write(sd, R21, 0x102);
} else {
wm8775_write(sd, R20, 0x0fb);
wm8775_set_audio(sd, 1);
}
return 0;
}
static int wm8775_remove(struct i2c_client *client)
{
struct v4l2_subdev *sd = i2c_get_clientdata(client);
struct wm8775_state *state = to_state(sd);
v4l2_device_unregister_subdev(sd);
v4l2_ctrl_handler_free(&state->hdl);
return 0;
}
