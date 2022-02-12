static v4l2_std_id adv7180_std_to_v4l2(u8 status1)
{
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
static int adv7180_g_chip_ident(struct v4l2_subdev *sd,
struct v4l2_dbg_chip_ident *chip)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
return v4l2_chip_ident_i2c_client(client, chip, V4L2_IDENT_ADV7180, 0);
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
static int adv7180_queryctrl(struct v4l2_subdev *sd, struct v4l2_queryctrl *qc)
{
switch (qc->id) {
case V4L2_CID_BRIGHTNESS:
return v4l2_ctrl_query_fill(qc, BRI_REG_MIN, BRI_REG_MAX,
1, BRI_REG_DEF);
case V4L2_CID_HUE:
return v4l2_ctrl_query_fill(qc, HUE_REG_MIN, HUE_REG_MAX,
1, HUE_REG_DEF);
case V4L2_CID_CONTRAST:
return v4l2_ctrl_query_fill(qc, CON_REG_MIN, CON_REG_MAX,
1, CON_REG_DEF);
case V4L2_CID_SATURATION:
return v4l2_ctrl_query_fill(qc, SAT_REG_MIN, SAT_REG_MAX,
1, SAT_REG_DEF);
default:
break;
}
return -EINVAL;
}
static int adv7180_g_ctrl(struct v4l2_subdev *sd, struct v4l2_control *ctrl)
{
struct adv7180_state *state = to_state(sd);
int ret = mutex_lock_interruptible(&state->mutex);
if (ret)
return ret;
switch (ctrl->id) {
case V4L2_CID_BRIGHTNESS:
ctrl->value = state->brightness;
break;
case V4L2_CID_HUE:
ctrl->value = state->hue;
break;
case V4L2_CID_CONTRAST:
ctrl->value = state->contrast;
break;
case V4L2_CID_SATURATION:
ctrl->value = state->saturation;
break;
default:
ret = -EINVAL;
}
mutex_unlock(&state->mutex);
return ret;
}
static int adv7180_s_ctrl(struct v4l2_subdev *sd, struct v4l2_control *ctrl)
{
struct adv7180_state *state = to_state(sd);
struct i2c_client *client = v4l2_get_subdevdata(sd);
int ret = mutex_lock_interruptible(&state->mutex);
if (ret)
return ret;
switch (ctrl->id) {
case V4L2_CID_BRIGHTNESS:
if ((ctrl->value > BRI_REG_MAX)
|| (ctrl->value < BRI_REG_MIN)) {
ret = -ERANGE;
break;
}
state->brightness = ctrl->value;
ret = i2c_smbus_write_byte_data(client,
ADV7180_BRI_REG,
state->brightness);
break;
case V4L2_CID_HUE:
if ((ctrl->value > HUE_REG_MAX)
|| (ctrl->value < HUE_REG_MIN)) {
ret = -ERANGE;
break;
}
state->hue = ctrl->value;
ret = i2c_smbus_write_byte_data(client,
ADV7180_HUE_REG, -state->hue);
break;
case V4L2_CID_CONTRAST:
if ((ctrl->value > CON_REG_MAX)
|| (ctrl->value < CON_REG_MIN)) {
ret = -ERANGE;
break;
}
state->contrast = ctrl->value;
ret = i2c_smbus_write_byte_data(client,
ADV7180_CON_REG,
state->contrast);
break;
case V4L2_CID_SATURATION:
if ((ctrl->value > SAT_REG_MAX)
|| (ctrl->value < SAT_REG_MIN)) {
ret = -ERANGE;
break;
}
state->saturation = ctrl->value;
ret = i2c_smbus_write_byte_data(client,
ADV7180_SD_SAT_CB_REG,
state->saturation);
if (ret < 0)
break;
ret = i2c_smbus_write_byte_data(client,
ADV7180_SD_SAT_CR_REG,
state->saturation);
break;
default:
ret = -EINVAL;
}
mutex_unlock(&state->mutex);
return ret;
}
static void adv7180_work(struct work_struct *work)
{
struct adv7180_state *state = container_of(work, struct adv7180_state,
work);
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
enable_irq(state->irq);
}
static irqreturn_t adv7180_irq(int irq, void *devid)
{
struct adv7180_state *state = devid;
schedule_work(&state->work);
disable_irq_nosync(state->irq);
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
ret = request_irq(state->irq, adv7180_irq, 0, DRIVER_NAME,
state);
if (ret)
return ret;
ret = i2c_smbus_write_byte_data(client, ADV7180_ADI_CTRL_REG,
ADV7180_ADI_CTRL_IRQ_SPACE);
if (ret < 0)
return ret;
ret = i2c_smbus_write_byte_data(client, ADV7180_ICONF1_ADI,
ADV7180_ICONF1_ACTIVE_LOW |
ADV7180_ICONF1_PSYNC_ONLY);
if (ret < 0)
return ret;
ret = i2c_smbus_write_byte_data(client, ADV7180_IMR1_ADI, 0);
if (ret < 0)
return ret;
ret = i2c_smbus_write_byte_data(client, ADV7180_IMR2_ADI, 0);
if (ret < 0)
return ret;
ret = i2c_smbus_write_byte_data(client, ADV7180_IMR3_ADI,
ADV7180_IRQ3_AD_CHANGE);
if (ret < 0)
return ret;
ret = i2c_smbus_write_byte_data(client, ADV7180_IMR4_ADI, 0);
if (ret < 0)
return ret;
ret = i2c_smbus_write_byte_data(client, ADV7180_ADI_CTRL_REG,
0);
if (ret < 0)
return ret;
}
ret = i2c_smbus_write_byte_data(client, ADV7180_BRI_REG,
state->brightness);
if (ret < 0)
return ret;
ret = i2c_smbus_write_byte_data(client, ADV7180_HUE_REG, state->hue);
if (ret < 0)
return ret;
ret = i2c_smbus_write_byte_data(client, ADV7180_CON_REG,
state->contrast);
if (ret < 0)
return ret;
ret = i2c_smbus_write_byte_data(client, ADV7180_SD_SAT_CB_REG,
state->saturation);
if (ret < 0)
return ret;
ret = i2c_smbus_write_byte_data(client, ADV7180_SD_SAT_CR_REG,
state->saturation);
if (ret < 0)
return ret;
return 0;
}
static __devinit int adv7180_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct adv7180_state *state;
struct v4l2_subdev *sd;
int ret;
if (!i2c_check_functionality(client->adapter, I2C_FUNC_SMBUS_BYTE_DATA))
return -EIO;
v4l_info(client, "chip found @ 0x%02x (%s)\n",
client->addr, client->adapter->name);
state = kzalloc(sizeof(struct adv7180_state), GFP_KERNEL);
if (state == NULL) {
ret = -ENOMEM;
goto err;
}
state->irq = client->irq;
INIT_WORK(&state->work, adv7180_work);
mutex_init(&state->mutex);
state->autodetect = true;
state->brightness = BRI_REG_DEF;
state->hue = HUE_REG_DEF;
state->contrast = CON_REG_DEF;
state->saturation = SAT_REG_DEF;
state->input = 0;
sd = &state->sd;
v4l2_i2c_subdev_init(sd, client, &adv7180_ops);
ret = init_device(client, state);
if (0 != ret)
goto err_unreg_subdev;
return 0;
err_unreg_subdev:
mutex_destroy(&state->mutex);
v4l2_device_unregister_subdev(sd);
kfree(state);
err:
printk(KERN_ERR DRIVER_NAME ": Failed to probe: %d\n", ret);
return ret;
}
static __devexit int adv7180_remove(struct i2c_client *client)
{
struct v4l2_subdev *sd = i2c_get_clientdata(client);
struct adv7180_state *state = to_state(sd);
if (state->irq > 0) {
free_irq(client->irq, state);
if (cancel_work_sync(&state->work)) {
enable_irq(state->irq);
}
}
mutex_destroy(&state->mutex);
v4l2_device_unregister_subdev(sd);
kfree(to_state(sd));
return 0;
}
static int adv7180_suspend(struct i2c_client *client, pm_message_t state)
{
int ret;
ret = i2c_smbus_write_byte_data(client, ADV7180_PWR_MAN_REG,
ADV7180_PWR_MAN_OFF);
if (ret < 0)
return ret;
return 0;
}
static int adv7180_resume(struct i2c_client *client)
{
struct v4l2_subdev *sd = i2c_get_clientdata(client);
struct adv7180_state *state = to_state(sd);
int ret;
ret = i2c_smbus_write_byte_data(client, ADV7180_PWR_MAN_REG,
ADV7180_PWR_MAN_ON);
if (ret < 0)
return ret;
ret = init_device(client, state);
if (ret < 0)
return ret;
return 0;
}
