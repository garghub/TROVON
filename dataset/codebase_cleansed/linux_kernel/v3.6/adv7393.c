static inline struct adv7393_state *to_state(struct v4l2_subdev *sd)
{
return container_of(sd, struct adv7393_state, sd);
}
static inline struct v4l2_subdev *to_sd(struct v4l2_ctrl *ctrl)
{
return &container_of(ctrl->handler, struct adv7393_state, hdl)->sd;
}
static inline int adv7393_write(struct v4l2_subdev *sd, u8 reg, u8 value)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
return i2c_smbus_write_byte_data(client, reg, value);
}
static int adv7393_setstd(struct v4l2_subdev *sd, v4l2_std_id std)
{
struct adv7393_state *state = to_state(sd);
const struct adv7393_std_info *std_info;
int num_std;
u8 reg;
u32 val;
int err = 0;
int i;
num_std = ARRAY_SIZE(stdinfo);
for (i = 0; i < num_std; i++) {
if (stdinfo[i].stdid & std)
break;
}
if (i == num_std) {
v4l2_dbg(1, debug, sd,
"Invalid std or std is not supported: %llx\n",
(unsigned long long)std);
return -EINVAL;
}
std_info = &stdinfo[i];
val = state->reg80 & ~SD_STD_MASK;
val |= std_info->standard_val3;
err = adv7393_write(sd, ADV7393_SD_MODE_REG1, val);
if (err < 0)
goto setstd_exit;
state->reg80 = val;
val = state->reg01 & ~INPUT_MODE_MASK;
val |= SD_INPUT_MODE;
err = adv7393_write(sd, ADV7393_MODE_SELECT_REG, val);
if (err < 0)
goto setstd_exit;
state->reg01 = val;
val = std_info->fsc_val;
for (reg = ADV7393_FSC_REG0; reg <= ADV7393_FSC_REG3; reg++) {
err = adv7393_write(sd, reg, val);
if (err < 0)
goto setstd_exit;
val >>= 8;
}
val = state->reg82;
if (std & (V4L2_STD_NTSC | V4L2_STD_NTSC_443))
val |= SD_PEDESTAL_EN;
else
val &= SD_PEDESTAL_DI;
err = adv7393_write(sd, ADV7393_SD_MODE_REG2, val);
if (err < 0)
goto setstd_exit;
state->reg82 = val;
setstd_exit:
if (err != 0)
v4l2_err(sd, "Error setting std, write failed\n");
return err;
}
static int adv7393_setoutput(struct v4l2_subdev *sd, u32 output_type)
{
struct adv7393_state *state = to_state(sd);
u8 val;
int err = 0;
if (output_type > ADV7393_SVIDEO_ID) {
v4l2_dbg(1, debug, sd,
"Invalid output type or output type not supported:%d\n",
output_type);
return -EINVAL;
}
val = state->reg00 & 0x03;
if (output_type == ADV7393_COMPOSITE_ID)
val |= ADV7393_COMPOSITE_POWER_VALUE;
else if (output_type == ADV7393_COMPONENT_ID)
val |= ADV7393_COMPONENT_POWER_VALUE;
else
val |= ADV7393_SVIDEO_POWER_VALUE;
err = adv7393_write(sd, ADV7393_POWER_MODE_REG, val);
if (err < 0)
goto setoutput_exit;
state->reg00 = val;
val = state->reg02 | YUV_OUTPUT_SELECT;
err = adv7393_write(sd, ADV7393_MODE_REG0, val);
if (err < 0)
goto setoutput_exit;
state->reg02 = val;
val = state->reg82;
if (output_type == ADV7393_COMPONENT_ID)
val &= SD_DAC_OUT1_DI;
else
val |= SD_DAC_OUT1_EN;
err = adv7393_write(sd, ADV7393_SD_MODE_REG2, val);
if (err < 0)
goto setoutput_exit;
state->reg82 = val;
val = state->reg35 & HD_DAC_SWAP_DI;
err = adv7393_write(sd, ADV7393_HD_MODE_REG6, val);
if (err < 0)
goto setoutput_exit;
state->reg35 = val;
setoutput_exit:
if (err != 0)
v4l2_err(sd, "Error setting output, write failed\n");
return err;
}
static int adv7393_log_status(struct v4l2_subdev *sd)
{
struct adv7393_state *state = to_state(sd);
v4l2_info(sd, "Standard: %llx\n", (unsigned long long)state->std);
v4l2_info(sd, "Output: %s\n", (state->output == 0) ? "Composite" :
((state->output == 1) ? "Component" : "S-Video"));
return 0;
}
static int adv7393_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct v4l2_subdev *sd = to_sd(ctrl);
switch (ctrl->id) {
case V4L2_CID_BRIGHTNESS:
return adv7393_write(sd, ADV7393_SD_BRIGHTNESS_WSS,
ctrl->val & SD_BRIGHTNESS_VALUE_MASK);
case V4L2_CID_HUE:
return adv7393_write(sd, ADV7393_SD_HUE_ADJUST,
ctrl->val - ADV7393_HUE_MIN);
case V4L2_CID_GAIN:
return adv7393_write(sd, ADV7393_DAC123_OUTPUT_LEVEL,
ctrl->val);
}
return -EINVAL;
}
static int adv7393_g_chip_ident(struct v4l2_subdev *sd,
struct v4l2_dbg_chip_ident *chip)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
return v4l2_chip_ident_i2c_client(client, chip, V4L2_IDENT_ADV7393, 0);
}
static int adv7393_s_std_output(struct v4l2_subdev *sd, v4l2_std_id std)
{
struct adv7393_state *state = to_state(sd);
int err = 0;
if (state->std == std)
return 0;
err = adv7393_setstd(sd, std);
if (!err)
state->std = std;
return err;
}
static int adv7393_s_routing(struct v4l2_subdev *sd,
u32 input, u32 output, u32 config)
{
struct adv7393_state *state = to_state(sd);
int err = 0;
if (state->output == output)
return 0;
err = adv7393_setoutput(sd, output);
if (!err)
state->output = output;
return err;
}
static int adv7393_initialize(struct v4l2_subdev *sd)
{
struct adv7393_state *state = to_state(sd);
int err = 0;
int i;
for (i = 0; i < ARRAY_SIZE(adv7393_init_reg_val); i += 2) {
err = adv7393_write(sd, adv7393_init_reg_val[i],
adv7393_init_reg_val[i+1]);
if (err) {
v4l2_err(sd, "Error initializing\n");
return err;
}
}
err = adv7393_setoutput(sd, state->output);
if (err < 0) {
v4l2_err(sd, "Error setting output during init\n");
return -EINVAL;
}
err = adv7393_setstd(sd, state->std);
if (err < 0) {
v4l2_err(sd, "Error setting std during init\n");
return -EINVAL;
}
return err;
}
static int adv7393_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct adv7393_state *state;
int err;
if (!i2c_check_functionality(client->adapter, I2C_FUNC_SMBUS_BYTE_DATA))
return -ENODEV;
v4l_info(client, "chip found @ 0x%x (%s)\n",
client->addr << 1, client->adapter->name);
state = kzalloc(sizeof(struct adv7393_state), GFP_KERNEL);
if (state == NULL)
return -ENOMEM;
state->reg00 = ADV7393_POWER_MODE_REG_DEFAULT;
state->reg01 = 0x00;
state->reg02 = 0x20;
state->reg35 = ADV7393_HD_MODE_REG6_DEFAULT;
state->reg80 = ADV7393_SD_MODE_REG1_DEFAULT;
state->reg82 = ADV7393_SD_MODE_REG2_DEFAULT;
state->output = ADV7393_COMPOSITE_ID;
state->std = V4L2_STD_NTSC;
v4l2_i2c_subdev_init(&state->sd, client, &adv7393_ops);
v4l2_ctrl_handler_init(&state->hdl, 3);
v4l2_ctrl_new_std(&state->hdl, &adv7393_ctrl_ops,
V4L2_CID_BRIGHTNESS, ADV7393_BRIGHTNESS_MIN,
ADV7393_BRIGHTNESS_MAX, 1,
ADV7393_BRIGHTNESS_DEF);
v4l2_ctrl_new_std(&state->hdl, &adv7393_ctrl_ops,
V4L2_CID_HUE, ADV7393_HUE_MIN,
ADV7393_HUE_MAX, 1,
ADV7393_HUE_DEF);
v4l2_ctrl_new_std(&state->hdl, &adv7393_ctrl_ops,
V4L2_CID_GAIN, ADV7393_GAIN_MIN,
ADV7393_GAIN_MAX, 1,
ADV7393_GAIN_DEF);
state->sd.ctrl_handler = &state->hdl;
if (state->hdl.error) {
int err = state->hdl.error;
v4l2_ctrl_handler_free(&state->hdl);
kfree(state);
return err;
}
v4l2_ctrl_handler_setup(&state->hdl);
err = adv7393_initialize(&state->sd);
if (err) {
v4l2_ctrl_handler_free(&state->hdl);
kfree(state);
}
return err;
}
static int adv7393_remove(struct i2c_client *client)
{
struct v4l2_subdev *sd = i2c_get_clientdata(client);
struct adv7393_state *state = to_state(sd);
v4l2_device_unregister_subdev(sd);
v4l2_ctrl_handler_free(&state->hdl);
kfree(state);
return 0;
}
