static inline struct tlv320aic23b_state *to_state(struct v4l2_subdev *sd)
{
return container_of(sd, struct tlv320aic23b_state, sd);
}
static inline struct v4l2_subdev *to_sd(struct v4l2_ctrl *ctrl)
{
return &container_of(ctrl->handler, struct tlv320aic23b_state, hdl)->sd;
}
static int tlv320aic23b_write(struct v4l2_subdev *sd, int reg, u16 val)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
int i;
if ((reg < 0 || reg > 9) && (reg != 15)) {
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
static int tlv320aic23b_s_clock_freq(struct v4l2_subdev *sd, u32 freq)
{
switch (freq) {
case 32000:
tlv320aic23b_write(sd, 8, 0x018);
break;
case 44100:
tlv320aic23b_write(sd, 8, 0x022);
break;
case 48000:
tlv320aic23b_write(sd, 8, 0x000);
break;
default:
return -EINVAL;
}
return 0;
}
static int tlv320aic23b_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct v4l2_subdev *sd = to_sd(ctrl);
switch (ctrl->id) {
case V4L2_CID_AUDIO_MUTE:
tlv320aic23b_write(sd, 0, 0x180);
if (!ctrl->val)
tlv320aic23b_write(sd, 0, 0x119);
return 0;
}
return -EINVAL;
}
static int tlv320aic23b_log_status(struct v4l2_subdev *sd)
{
struct tlv320aic23b_state *state = to_state(sd);
v4l2_ctrl_handler_log_status(&state->hdl, sd->name);
return 0;
}
static int tlv320aic23b_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct tlv320aic23b_state *state;
struct v4l2_subdev *sd;
if (!i2c_check_functionality(client->adapter, I2C_FUNC_SMBUS_BYTE_DATA))
return -EIO;
v4l_info(client, "chip found @ 0x%x (%s)\n",
client->addr << 1, client->adapter->name);
state = kzalloc(sizeof(struct tlv320aic23b_state), GFP_KERNEL);
if (state == NULL)
return -ENOMEM;
sd = &state->sd;
v4l2_i2c_subdev_init(sd, client, &tlv320aic23b_ops);
tlv320aic23b_write(sd, 15, 0x000);
tlv320aic23b_write(sd, 6, 0x00A);
tlv320aic23b_write(sd, 7, 0x049);
tlv320aic23b_write(sd, 0, 0x119);
tlv320aic23b_write(sd, 8, 0x000);
tlv320aic23b_write(sd, 9, 0x001);
v4l2_ctrl_handler_init(&state->hdl, 1);
v4l2_ctrl_new_std(&state->hdl, &tlv320aic23b_ctrl_ops,
V4L2_CID_AUDIO_MUTE, 0, 1, 1, 0);
sd->ctrl_handler = &state->hdl;
if (state->hdl.error) {
int err = state->hdl.error;
v4l2_ctrl_handler_free(&state->hdl);
kfree(state);
return err;
}
v4l2_ctrl_handler_setup(&state->hdl);
return 0;
}
static int tlv320aic23b_remove(struct i2c_client *client)
{
struct v4l2_subdev *sd = i2c_get_clientdata(client);
struct tlv320aic23b_state *state = to_state(sd);
v4l2_device_unregister_subdev(sd);
v4l2_ctrl_handler_free(&state->hdl);
kfree(state);
return 0;
}
