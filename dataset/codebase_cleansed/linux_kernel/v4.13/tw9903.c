static inline struct tw9903 *to_state(struct v4l2_subdev *sd)
{
return container_of(sd, struct tw9903, sd);
}
static int write_reg(struct v4l2_subdev *sd, u8 reg, u8 value)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
return i2c_smbus_write_byte_data(client, reg, value);
}
static int write_regs(struct v4l2_subdev *sd, const u8 *regs)
{
int i;
for (i = 0; regs[i] != 0x00; i += 2)
if (write_reg(sd, regs[i], regs[i + 1]) < 0)
return -1;
return 0;
}
static int tw9903_s_video_routing(struct v4l2_subdev *sd, u32 input,
u32 output, u32 config)
{
write_reg(sd, 0x02, 0x40 | (input << 1));
return 0;
}
static int tw9903_s_std(struct v4l2_subdev *sd, v4l2_std_id norm)
{
struct tw9903 *dec = to_state(sd);
bool is_60hz = norm & V4L2_STD_525_60;
static const u8 config_60hz[] = {
0x05, 0x80,
0x07, 0x02,
0x08, 0x14,
0x09, 0xf0,
0, 0,
};
static const u8 config_50hz[] = {
0x05, 0x00,
0x07, 0x12,
0x08, 0x18,
0x09, 0x20,
0, 0,
};
write_regs(sd, is_60hz ? config_60hz : config_50hz);
dec->norm = norm;
return 0;
}
static int tw9903_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct tw9903 *dec = container_of(ctrl->handler, struct tw9903, hdl);
struct v4l2_subdev *sd = &dec->sd;
switch (ctrl->id) {
case V4L2_CID_BRIGHTNESS:
write_reg(sd, 0x10, ctrl->val);
break;
case V4L2_CID_CONTRAST:
write_reg(sd, 0x11, ctrl->val);
break;
case V4L2_CID_HUE:
write_reg(sd, 0x15, ctrl->val);
break;
default:
return -EINVAL;
}
return 0;
}
static int tw9903_log_status(struct v4l2_subdev *sd)
{
struct tw9903 *dec = to_state(sd);
bool is_60hz = dec->norm & V4L2_STD_525_60;
v4l2_info(sd, "Standard: %d Hz\n", is_60hz ? 60 : 50);
v4l2_ctrl_subdev_log_status(sd);
return 0;
}
static int tw9903_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct tw9903 *dec;
struct v4l2_subdev *sd;
struct v4l2_ctrl_handler *hdl;
if (!i2c_check_functionality(client->adapter, I2C_FUNC_SMBUS_BYTE_DATA))
return -EIO;
v4l_info(client, "chip found @ 0x%02x (%s)\n",
client->addr << 1, client->adapter->name);
dec = devm_kzalloc(&client->dev, sizeof(*dec), GFP_KERNEL);
if (dec == NULL)
return -ENOMEM;
sd = &dec->sd;
v4l2_i2c_subdev_init(sd, client, &tw9903_ops);
hdl = &dec->hdl;
v4l2_ctrl_handler_init(hdl, 4);
v4l2_ctrl_new_std(hdl, &tw9903_ctrl_ops,
V4L2_CID_BRIGHTNESS, -128, 127, 1, 0);
v4l2_ctrl_new_std(hdl, &tw9903_ctrl_ops,
V4L2_CID_CONTRAST, 0, 255, 1, 0x60);
v4l2_ctrl_new_std(hdl, &tw9903_ctrl_ops,
V4L2_CID_HUE, -128, 127, 1, 0);
sd->ctrl_handler = hdl;
if (hdl->error) {
int err = hdl->error;
v4l2_ctrl_handler_free(hdl);
return err;
}
dec->norm = V4L2_STD_NTSC;
if (write_regs(sd, initial_registers) < 0) {
v4l2_err(client, "error initializing TW9903\n");
return -EINVAL;
}
return 0;
}
static int tw9903_remove(struct i2c_client *client)
{
struct v4l2_subdev *sd = i2c_get_clientdata(client);
v4l2_device_unregister_subdev(sd);
v4l2_ctrl_handler_free(&to_state(sd)->hdl);
return 0;
}
