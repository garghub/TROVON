static v4l2_std_id adv7180_std_to_v4l2(u8 status1)
{
if (!(status1 & ADV7180_STATUS1_IN_LOCK))
return V4L2_STD_UNKNOWN;
switch (status1 & ADV7180_STATUS1_AUTOD_MASK) {
case ADV7180_STATUS1_AUTOD_NTSM_M_J:
return V4L2_STD_NTSC;
case ADV7180_STATUS1_AUTOD_NTSC_4_43:
return V4L2_STD_NTSC_443;
case ADV7180_STATUS1_AUTOD_PAL_M:
return V4L2_STD_PAL_M;
case ADV7180_STATUS1_AUTOD_PAL_60:
return V4L2_STD_PAL_60;
case ADV7180_STATUS1_AUTOD_PAL_B_G:
return V4L2_STD_PAL;
case ADV7180_STATUS1_AUTOD_SECAM:
return V4L2_STD_SECAM;
case ADV7180_STATUS1_AUTOD_PAL_COMB:
return V4L2_STD_PAL_Nc | V4L2_STD_PAL_N;
case ADV7180_STATUS1_AUTOD_SECAM_525:
return V4L2_STD_SECAM;
default:
return V4L2_STD_UNKNOWN;
}
}
static int v4l2_std_to_adv7180(v4l2_std_id std)
{
if (std == V4L2_STD_PAL_60)
return ADV7180_INPUT_CONTROL_PAL60;
if (std == V4L2_STD_NTSC_443)
return ADV7180_INPUT_CONTROL_NTSC_443;
if (std == V4L2_STD_PAL_N)
return ADV7180_INPUT_CONTROL_PAL_N;
if (std == V4L2_STD_PAL_M)
return ADV7180_INPUT_CONTROL_PAL_M;
if (std == V4L2_STD_PAL_Nc)
return ADV7180_INPUT_CONTROL_PAL_COMB_N;
if (std & V4L2_STD_PAL)
return ADV7180_INPUT_CONTROL_PAL_BG;
if (std & V4L2_STD_NTSC)
return ADV7180_INPUT_CONTROL_NTSC_M;
if (std & V4L2_STD_SECAM)
return ADV7180_INPUT_CONTROL_PAL_SECAM;
return -EINVAL;
}
static u32 adv7180_status_to_v4l2(u8 status1)
{
if (!(status1 & ADV7180_STATUS1_IN_LOCK))
return V4L2_IN_ST_NO_SIGNAL;
return 0;
}
static int __adv7180_status(struct i2c_client *client, u32 *status,
v4l2_std_id *std)
{
int status1 = i2c_smbus_read_byte_data(client, ADV7180_STATUS1_REG);
if (status1 < 0)
return status1;
if (status)
*status = adv7180_status_to_v4l2(status1);
if (std)
*std = adv7180_std_to_v4l2(status1);
return 0;
}
static inline struct adv7180_state *to_state(struct v4l2_subdev *sd)
{
return container_of(sd, struct adv7180_state, sd);
}
static int adv7180_querystd(struct v4l2_subdev *sd, v4l2_std_id *std)
{
struct adv7180_state *state = to_state(sd);
int err = mutex_lock_interruptible(&state->mutex);
if (err)
return err;
if (!state->autodetect || state->irq > 0)
*std = state->curr_norm;
else
err = __adv7180_status(v4l2_get_subdevdata(sd), NULL, std);
mutex_unlock(&state->mutex);
return err;
}
static int adv7180_s_routing(struct v4l2_subdev *sd, u32 input,
u32 output, u32 config)
{
struct adv7180_state *state = to_state(sd);
int ret = mutex_lock_interruptible(&state->mutex);
struct i2c_client *client = v4l2_get_subdevdata(sd);
if (ret)
return ret;
if ((input & ADV7180_INPUT_CONTROL_INSEL_MASK) != input)
goto out;
ret = i2c_smbus_read_byte_data(client, ADV7180_INPUT_CONTROL_REG);
if (ret < 0)
goto out;
ret &= ~ADV7180_INPUT_CONTROL_INSEL_MASK;
ret = i2c_smbus_write_byte_data(client,
ADV7180_INPUT_CONTROL_REG, ret | input);
state->input = input;
out:
mutex_unlock(&state->mutex);
return ret;
}
static int adv7180_g_input_status(struct v4l2_subdev *sd, u32 *status)
{
struct adv7180_state *state = to_state(sd);
int ret = mutex_lock_interruptible(&state->mutex);
if (ret)
return ret;
ret = __adv7180_status(v4l2_get_subdevdata(sd), status, NULL);
mutex_unlock(&state->mutex);
return ret;
}
static int adv7180_s_std(struct v4l2_subdev *sd, v4l2_std_id std)
{
struct adv7180_state *state = to_state(sd);
struct i2c_client *client = v4l2_get_subdevdata(sd);
int ret = mutex_lock_interruptible(&state->mutex);
if (ret)
return ret;
if (std == V4L2_STD_ALL) {
ret =
i2c_smbus_write_byte_data(client, ADV7180_INPUT_CONTROL_REG,
ADV7180_INPUT_CONTROL_AD_PAL_BG_NTSC_J_SECAM
| state->input);
if (ret < 0)
goto out;
__adv7180_status(client, NULL, &state->curr_norm);
state->autodetect = true;
} else {
ret = v4l2_std_to_adv7180(std);
if (ret < 0)
goto out;
ret = i2c_smbus_write_byte_data(client,
ADV7180_INPUT_CONTROL_REG,
ret | state->input);
if (ret < 0)
goto out;
state->curr_norm = std;
state->autodetect = false;
}
ret = 0;
out:
mutex_unlock(&state->mutex);
return ret;
}
static int adv7180_set_power(struct adv7180_state *state,
struct i2c_client *client, bool on)
{
u8 val;
if (on)
val = ADV7180_PWR_MAN_ON;
else
val = ADV7180_PWR_MAN_OFF;
return i2c_smbus_write_byte_data(client, ADV7180_PWR_MAN_REG, val);
}
static int adv7180_s_power(struct v4l2_subdev *sd, int on)
{
struct adv7180_state *state = to_state(sd);
struct i2c_client *client = v4l2_get_subdevdata(sd);
int ret;
ret = mutex_lock_interruptible(&state->mutex);
if (ret)
return ret;
ret = adv7180_set_power(state, client, on);
if (ret == 0)
state->powered = on;
mutex_unlock(&state->mutex);
return ret;
}
static int adv7180_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct v4l2_subdev *sd = to_adv7180_sd(ctrl);
struct adv7180_state *state = to_state(sd);
struct i2c_client *client = v4l2_get_subdevdata(sd);
int ret = mutex_lock_interruptible(&state->mutex);
int val;
if (ret)
return ret;
val = ctrl->val;
switch (ctrl->id) {
case V4L2_CID_BRIGHTNESS:
ret = i2c_smbus_write_byte_data(client, ADV7180_BRI_REG, val);
break;
case V4L2_CID_HUE:
ret = i2c_smbus_write_byte_data(client, ADV7180_HUE_REG, -val);
break;
case V4L2_CID_CONTRAST:
ret = i2c_smbus_write_byte_data(client, ADV7180_CON_REG, val);
break;
case V4L2_CID_SATURATION:
ret = i2c_smbus_write_byte_data(client, ADV7180_SD_SAT_CB_REG,
val);
if (ret < 0)
break;
ret = i2c_smbus_write_byte_data(client, ADV7180_SD_SAT_CR_REG,
val);
break;
default:
ret = -EINVAL;
}
mutex_unlock(&state->mutex);
return ret;
}
static int adv7180_init_controls(struct adv7180_state *state)
{
v4l2_ctrl_handler_init(&state->ctrl_hdl, 4);
v4l2_ctrl_new_std(&state->ctrl_hdl, &adv7180_ctrl_ops,
V4L2_CID_BRIGHTNESS, ADV7180_BRI_MIN,
ADV7180_BRI_MAX, 1, ADV7180_BRI_DEF);
v4l2_ctrl_new_std(&state->ctrl_hdl, &adv7180_ctrl_ops,
V4L2_CID_CONTRAST, ADV7180_CON_MIN,
ADV7180_CON_MAX, 1, ADV7180_CON_DEF);
v4l2_ctrl_new_std(&state->ctrl_hdl, &adv7180_ctrl_ops,
V4L2_CID_SATURATION, ADV7180_SAT_MIN,
ADV7180_SAT_MAX, 1, ADV7180_SAT_DEF);
v4l2_ctrl_new_std(&state->ctrl_hdl, &adv7180_ctrl_ops,
V4L2_CID_HUE, ADV7180_HUE_MIN,
ADV7180_HUE_MAX, 1, ADV7180_HUE_DEF);
state->sd.ctrl_handler = &state->ctrl_hdl;
if (state->ctrl_hdl.error) {
int err = state->ctrl_hdl.error;
v4l2_ctrl_handler_free(&state->ctrl_hdl);
return err;
}
v4l2_ctrl_handler_setup(&state->ctrl_hdl);
return 0;
}
static void adv7180_exit_controls(struct adv7180_state *state)
{
v4l2_ctrl_handler_free(&state->ctrl_hdl);
}
static int adv7180_enum_mbus_fmt(struct v4l2_subdev *sd, unsigned int index,
enum v4l2_mbus_pixelcode *code)
{
if (index > 0)
return -EINVAL;
*code = V4L2_MBUS_FMT_YUYV8_2X8;
return 0;
}
static int adv7180_mbus_fmt(struct v4l2_subdev *sd,
struct v4l2_mbus_framefmt *fmt)
{
struct adv7180_state *state = to_state(sd);
fmt->code = V4L2_MBUS_FMT_YUYV8_2X8;
fmt->colorspace = V4L2_COLORSPACE_SMPTE170M;
fmt->field = V4L2_FIELD_INTERLACED;
fmt->width = 720;
fmt->height = state->curr_norm & V4L2_STD_525_60 ? 480 : 576;
return 0;
}
static int adv7180_g_mbus_config(struct v4l2_subdev *sd,
struct v4l2_mbus_config *cfg)
{
cfg->flags = V4L2_MBUS_MASTER | V4L2_MBUS_PCLK_SAMPLE_RISING |
V4L2_MBUS_DATA_ACTIVE_HIGH;
cfg->type = V4L2_MBUS_BT656;
return 0;
}
static irqreturn_t adv7180_irq(int irq, void *devid)
{
struct adv7180_state *state = devid;
struct i2c_client *client = v4l2_get_subdevdata(&state->sd);
u8 isr3;
mutex_lock(&state->mutex);
i2c_smbus_write_byte_data(client, ADV7180_ADI_CTRL_REG,
ADV7180_ADI_CTRL_IRQ_SPACE);
isr3 = i2c_smbus_read_byte_data(client, ADV7180_ISR3_ADI);
i2c_smbus_write_byte_data(client, ADV7180_ICR3_ADI, isr3);
i2c_smbus_write_byte_data(client, ADV7180_ADI_CTRL_REG, 0);
if (isr3 & ADV7180_IRQ3_AD_CHANGE && state->autodetect)
__adv7180_status(client, NULL, &state->curr_norm);
mutex_unlock(&state->mutex);
return IRQ_HANDLED;
}
static int init_device(struct i2c_client *client, struct adv7180_state *state)
{
int ret;
if (state->autodetect) {
ret =
i2c_smbus_write_byte_data(client, ADV7180_INPUT_CONTROL_REG,
ADV7180_INPUT_CONTROL_AD_PAL_BG_NTSC_J_SECAM
| state->input);
if (ret < 0)
return ret;
ret =
i2c_smbus_write_byte_data(client,
ADV7180_AUTODETECT_ENABLE_REG,
ADV7180_AUTODETECT_DEFAULT);
if (ret < 0)
return ret;
} else {
ret = v4l2_std_to_adv7180(state->curr_norm);
if (ret < 0)
return ret;
ret =
i2c_smbus_write_byte_data(client, ADV7180_INPUT_CONTROL_REG,
ret | state->input);
if (ret < 0)
return ret;
}
ret = i2c_smbus_write_byte_data(client,
ADV7180_EXTENDED_OUTPUT_CONTROL_REG,
ADV7180_EXTENDED_OUTPUT_CONTROL_NTSCDIS);
if (ret < 0)
return ret;
ret = i2c_smbus_write_byte_data(client,
ADV7180_NTSC_V_BIT_END_REG,
ADV7180_NTSC_V_BIT_END_MANUAL_NVEND);
if (ret < 0)
return ret;
__adv7180_status(client, NULL, &state->curr_norm);
if (state->irq > 0) {
ret = request_threaded_irq(state->irq, NULL, adv7180_irq,
IRQF_ONESHOT, KBUILD_MODNAME, state);
if (ret)
return ret;
ret = i2c_smbus_write_byte_data(client, ADV7180_ADI_CTRL_REG,
ADV7180_ADI_CTRL_IRQ_SPACE);
if (ret < 0)
goto err;
ret = i2c_smbus_write_byte_data(client, ADV7180_ICONF1_ADI,
ADV7180_ICONF1_ACTIVE_LOW |
ADV7180_ICONF1_PSYNC_ONLY);
if (ret < 0)
goto err;
ret = i2c_smbus_write_byte_data(client, ADV7180_IMR1_ADI, 0);
if (ret < 0)
goto err;
ret = i2c_smbus_write_byte_data(client, ADV7180_IMR2_ADI, 0);
if (ret < 0)
goto err;
ret = i2c_smbus_write_byte_data(client, ADV7180_IMR3_ADI,
ADV7180_IRQ3_AD_CHANGE);
if (ret < 0)
goto err;
ret = i2c_smbus_write_byte_data(client, ADV7180_IMR4_ADI, 0);
if (ret < 0)
goto err;
ret = i2c_smbus_write_byte_data(client, ADV7180_ADI_CTRL_REG,
0);
if (ret < 0)
goto err;
}
return 0;
err:
free_irq(state->irq, state);
return ret;
}
static int adv7180_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct adv7180_state *state;
struct v4l2_subdev *sd;
int ret;
if (!i2c_check_functionality(client->adapter, I2C_FUNC_SMBUS_BYTE_DATA))
return -EIO;
v4l_info(client, "chip found @ 0x%02x (%s)\n",
client->addr, client->adapter->name);
state = devm_kzalloc(&client->dev, sizeof(*state), GFP_KERNEL);
if (state == NULL) {
ret = -ENOMEM;
goto err;
}
state->irq = client->irq;
mutex_init(&state->mutex);
state->autodetect = true;
state->powered = true;
state->input = 0;
sd = &state->sd;
v4l2_i2c_subdev_init(sd, client, &adv7180_ops);
ret = adv7180_init_controls(state);
if (ret)
goto err_unreg_subdev;
ret = init_device(client, state);
if (ret)
goto err_free_ctrl;
ret = v4l2_async_register_subdev(sd);
if (ret)
goto err_free_irq;
return 0;
err_free_irq:
if (state->irq > 0)
free_irq(client->irq, state);
err_free_ctrl:
adv7180_exit_controls(state);
err_unreg_subdev:
mutex_destroy(&state->mutex);
err:
return ret;
}
static int adv7180_remove(struct i2c_client *client)
{
struct v4l2_subdev *sd = i2c_get_clientdata(client);
struct adv7180_state *state = to_state(sd);
v4l2_async_unregister_subdev(sd);
if (state->irq > 0)
free_irq(client->irq, state);
adv7180_exit_controls(state);
mutex_destroy(&state->mutex);
return 0;
}
static int adv7180_suspend(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct v4l2_subdev *sd = i2c_get_clientdata(client);
struct adv7180_state *state = to_state(sd);
return adv7180_set_power(state, client, false);
}
static int adv7180_resume(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct v4l2_subdev *sd = i2c_get_clientdata(client);
struct adv7180_state *state = to_state(sd);
int ret;
if (state->powered) {
ret = adv7180_set_power(state, client, true);
if (ret)
return ret;
}
ret = init_device(client, state);
if (ret < 0)
return ret;
return 0;
}
