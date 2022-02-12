static int write_reg(struct i2c_client *client, u8 reg, u8 value, u8 channel)
{
return i2c_smbus_write_byte_data(client, reg | (channel << 6), value);
}
static int write_regs(struct i2c_client *client, const u8 *regs, u8 channel)
{
int ret;
int i;
for (i = 0; regs[i] != 0xff; i += 2) {
ret = i2c_smbus_write_byte_data(client,
regs[i] | (channel << 6), regs[i + 1]);
if (ret < 0)
return ret;
}
return 0;
}
static int read_reg(struct i2c_client *client, u8 reg, u8 channel)
{
return i2c_smbus_read_byte_data(client, (reg) | (channel << 6));
}
static inline struct tw2804 *to_state(struct v4l2_subdev *sd)
{
return container_of(sd, struct tw2804, sd);
}
static inline struct tw2804 *to_state_from_ctrl(struct v4l2_ctrl *ctrl)
{
return container_of(ctrl->handler, struct tw2804, hdl);
}
static int tw2804_log_status(struct v4l2_subdev *sd)
{
struct tw2804 *state = to_state(sd);
v4l2_info(sd, "Standard: %s\n",
state->norm & V4L2_STD_525_60 ? "60 Hz" : "50 Hz");
v4l2_info(sd, "Channel: %d\n", state->channel);
v4l2_info(sd, "Input: %d\n", state->input);
return v4l2_ctrl_subdev_log_status(sd);
}
static int tw2804_g_volatile_ctrl(struct v4l2_ctrl *ctrl)
{
struct tw2804 *state = to_state_from_ctrl(ctrl);
struct i2c_client *client = v4l2_get_subdevdata(&state->sd);
switch (ctrl->id) {
case V4L2_CID_GAIN:
ctrl->val = read_reg(client, TW2804_REG_GAIN, 0);
return 0;
case V4L2_CID_CHROMA_GAIN:
ctrl->val = read_reg(client, TW2804_REG_CHROMA_GAIN, 0);
return 0;
case V4L2_CID_BLUE_BALANCE:
ctrl->val = read_reg(client, TW2804_REG_BLUE_BALANCE, 0);
return 0;
case V4L2_CID_RED_BALANCE:
ctrl->val = read_reg(client, TW2804_REG_RED_BALANCE, 0);
return 0;
}
return 0;
}
static int tw2804_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct tw2804 *state = to_state_from_ctrl(ctrl);
struct i2c_client *client = v4l2_get_subdevdata(&state->sd);
int addr;
int reg;
switch (ctrl->id) {
case V4L2_CID_AUTOGAIN:
addr = TW2804_REG_AUTOGAIN;
reg = read_reg(client, addr, state->channel);
if (reg < 0)
return reg;
if (ctrl->val == 0)
reg &= ~(1 << 7);
else
reg |= 1 << 7;
return write_reg(client, addr, reg, state->channel);
case V4L2_CID_COLOR_KILLER:
addr = TW2804_REG_COLOR_KILLER;
reg = read_reg(client, addr, state->channel);
if (reg < 0)
return reg;
reg = (reg & ~(0x03)) | (ctrl->val == 0 ? 0x02 : 0x03);
return write_reg(client, addr, reg, state->channel);
case V4L2_CID_GAIN:
return write_reg(client, TW2804_REG_GAIN, ctrl->val, 0);
case V4L2_CID_CHROMA_GAIN:
return write_reg(client, TW2804_REG_CHROMA_GAIN, ctrl->val, 0);
case V4L2_CID_BLUE_BALANCE:
return write_reg(client, TW2804_REG_BLUE_BALANCE, ctrl->val, 0);
case V4L2_CID_RED_BALANCE:
return write_reg(client, TW2804_REG_RED_BALANCE, ctrl->val, 0);
case V4L2_CID_BRIGHTNESS:
return write_reg(client, TW2804_REG_BRIGHTNESS,
ctrl->val, state->channel);
case V4L2_CID_CONTRAST:
return write_reg(client, TW2804_REG_CONTRAST,
ctrl->val, state->channel);
case V4L2_CID_SATURATION:
return write_reg(client, TW2804_REG_SATURATION,
ctrl->val, state->channel);
case V4L2_CID_HUE:
return write_reg(client, TW2804_REG_HUE,
ctrl->val, state->channel);
default:
break;
}
return -EINVAL;
}
static int tw2804_s_std(struct v4l2_subdev *sd, v4l2_std_id norm)
{
struct tw2804 *dec = to_state(sd);
struct i2c_client *client = v4l2_get_subdevdata(sd);
bool is_60hz = norm & V4L2_STD_525_60;
u8 regs[] = {
0x01, is_60hz ? 0xc4 : 0x84,
0x09, is_60hz ? 0x07 : 0x04,
0x0a, is_60hz ? 0xf0 : 0x20,
0x0b, is_60hz ? 0x07 : 0x04,
0x0c, is_60hz ? 0xf0 : 0x20,
0x0d, is_60hz ? 0x40 : 0x4a,
0x16, is_60hz ? 0x00 : 0x40,
0x17, is_60hz ? 0x00 : 0x40,
0x20, is_60hz ? 0x07 : 0x0f,
0x21, is_60hz ? 0x07 : 0x0f,
0xff, 0xff,
};
write_regs(client, regs, dec->channel);
dec->norm = norm;
return 0;
}
static int tw2804_s_video_routing(struct v4l2_subdev *sd, u32 input, u32 output,
u32 config)
{
struct tw2804 *dec = to_state(sd);
struct i2c_client *client = v4l2_get_subdevdata(sd);
int reg;
if (config && config - 1 != dec->channel) {
if (config > 4) {
dev_err(&client->dev,
"channel %d is not between 1 and 4!\n", config);
return -EINVAL;
}
dec->channel = config - 1;
dev_dbg(&client->dev, "initializing TW2804 channel %d\n",
dec->channel);
if (dec->channel == 0 &&
write_regs(client, global_registers, 0) < 0) {
dev_err(&client->dev,
"error initializing TW2804 global registers\n");
return -EIO;
}
if (write_regs(client, channel_registers, dec->channel) < 0) {
dev_err(&client->dev,
"error initializing TW2804 channel %d\n",
dec->channel);
return -EIO;
}
}
if (input > 1)
return -EINVAL;
if (input == dec->input)
return 0;
reg = read_reg(client, 0x22, dec->channel);
if (reg >= 0) {
if (input == 0)
reg &= ~(1 << 2);
else
reg |= 1 << 2;
reg = write_reg(client, 0x22, reg, dec->channel);
}
if (reg >= 0)
dec->input = input;
else
return reg;
return 0;
}
static int tw2804_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct i2c_adapter *adapter = client->adapter;
struct tw2804 *state;
struct v4l2_subdev *sd;
struct v4l2_ctrl *ctrl;
int err;
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA))
return -ENODEV;
state = kzalloc(sizeof(struct tw2804), GFP_KERNEL);
if (state == NULL)
return -ENOMEM;
sd = &state->sd;
v4l2_i2c_subdev_init(sd, client, &tw2804_ops);
state->channel = -1;
state->norm = V4L2_STD_NTSC;
v4l2_ctrl_handler_init(&state->hdl, 10);
v4l2_ctrl_new_std(&state->hdl, &tw2804_ctrl_ops,
V4L2_CID_BRIGHTNESS, 0, 255, 1, 128);
v4l2_ctrl_new_std(&state->hdl, &tw2804_ctrl_ops,
V4L2_CID_CONTRAST, 0, 255, 1, 128);
v4l2_ctrl_new_std(&state->hdl, &tw2804_ctrl_ops,
V4L2_CID_SATURATION, 0, 255, 1, 128);
v4l2_ctrl_new_std(&state->hdl, &tw2804_ctrl_ops,
V4L2_CID_HUE, 0, 255, 1, 128);
v4l2_ctrl_new_std(&state->hdl, &tw2804_ctrl_ops,
V4L2_CID_COLOR_KILLER, 0, 1, 1, 0);
v4l2_ctrl_new_std(&state->hdl, &tw2804_ctrl_ops,
V4L2_CID_AUTOGAIN, 0, 1, 1, 0);
ctrl = v4l2_ctrl_new_std(&state->hdl, &tw2804_ctrl_ops,
V4L2_CID_GAIN, 0, 255, 1, 128);
if (ctrl)
ctrl->flags |= V4L2_CTRL_FLAG_VOLATILE;
ctrl = v4l2_ctrl_new_std(&state->hdl, &tw2804_ctrl_ops,
V4L2_CID_CHROMA_GAIN, 0, 255, 1, 128);
if (ctrl)
ctrl->flags |= V4L2_CTRL_FLAG_VOLATILE;
ctrl = v4l2_ctrl_new_std(&state->hdl, &tw2804_ctrl_ops,
V4L2_CID_BLUE_BALANCE, 0, 255, 1, 122);
if (ctrl)
ctrl->flags |= V4L2_CTRL_FLAG_VOLATILE;
ctrl = v4l2_ctrl_new_std(&state->hdl, &tw2804_ctrl_ops,
V4L2_CID_RED_BALANCE, 0, 255, 1, 122);
if (ctrl)
ctrl->flags |= V4L2_CTRL_FLAG_VOLATILE;
sd->ctrl_handler = &state->hdl;
err = state->hdl.error;
if (err) {
v4l2_ctrl_handler_free(&state->hdl);
kfree(state);
return err;
}
v4l_info(client, "chip found @ 0x%02x (%s)\n",
client->addr << 1, client->adapter->name);
return 0;
}
static int tw2804_remove(struct i2c_client *client)
{
struct v4l2_subdev *sd = i2c_get_clientdata(client);
struct tw2804 *state = to_state(sd);
v4l2_device_unregister_subdev(sd);
v4l2_ctrl_handler_free(&state->hdl);
kfree(state);
return 0;
}
