static int adv7180_select_page(struct adv7180_state *state, unsigned int page)
{
if (state->register_page != page) {
i2c_smbus_write_byte_data(state->client, ADV7180_REG_CTRL,
page);
state->register_page = page;
}
return 0;
}
static int adv7180_write(struct adv7180_state *state, unsigned int reg,
unsigned int value)
{
lockdep_assert_held(&state->mutex);
adv7180_select_page(state, reg >> 8);
return i2c_smbus_write_byte_data(state->client, reg & 0xff, value);
}
static int adv7180_read(struct adv7180_state *state, unsigned int reg)
{
lockdep_assert_held(&state->mutex);
adv7180_select_page(state, reg >> 8);
return i2c_smbus_read_byte_data(state->client, reg & 0xff);
}
static int adv7180_csi_write(struct adv7180_state *state, unsigned int reg,
unsigned int value)
{
return i2c_smbus_write_byte_data(state->csi_client, reg, value);
}
static int adv7180_set_video_standard(struct adv7180_state *state,
unsigned int std)
{
return state->chip_info->set_std(state, std);
}
static int adv7180_vpp_write(struct adv7180_state *state, unsigned int reg,
unsigned int value)
{
return i2c_smbus_write_byte_data(state->vpp_client, reg, value);
}
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
return ADV7180_STD_PAL60;
if (std == V4L2_STD_NTSC_443)
return ADV7180_STD_NTSC_443;
if (std == V4L2_STD_PAL_N)
return ADV7180_STD_PAL_N;
if (std == V4L2_STD_PAL_M)
return ADV7180_STD_PAL_M;
if (std == V4L2_STD_PAL_Nc)
return ADV7180_STD_PAL_COMB_N;
if (std & V4L2_STD_PAL)
return ADV7180_STD_PAL_BG;
if (std & V4L2_STD_NTSC)
return ADV7180_STD_NTSC_M;
if (std & V4L2_STD_SECAM)
return ADV7180_STD_PAL_SECAM;
return -EINVAL;
}
static u32 adv7180_status_to_v4l2(u8 status1)
{
if (!(status1 & ADV7180_STATUS1_IN_LOCK))
return V4L2_IN_ST_NO_SIGNAL;
return 0;
}
static int __adv7180_status(struct adv7180_state *state, u32 *status,
v4l2_std_id *std)
{
int status1 = adv7180_read(state, ADV7180_REG_STATUS1);
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
err = __adv7180_status(state, NULL, std);
mutex_unlock(&state->mutex);
return err;
}
static int adv7180_s_routing(struct v4l2_subdev *sd, u32 input,
u32 output, u32 config)
{
struct adv7180_state *state = to_state(sd);
int ret = mutex_lock_interruptible(&state->mutex);
if (ret)
return ret;
if (input > 31 || !(BIT(input) & state->chip_info->valid_input_mask)) {
ret = -EINVAL;
goto out;
}
ret = state->chip_info->select_input(state, input);
if (ret == 0)
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
ret = __adv7180_status(state, status, NULL);
mutex_unlock(&state->mutex);
return ret;
}
static int adv7180_program_std(struct adv7180_state *state)
{
int ret;
if (state->autodetect) {
ret = adv7180_set_video_standard(state,
ADV7180_STD_AD_PAL_BG_NTSC_J_SECAM);
if (ret < 0)
return ret;
__adv7180_status(state, NULL, &state->curr_norm);
} else {
ret = v4l2_std_to_adv7180(state->curr_norm);
if (ret < 0)
return ret;
ret = adv7180_set_video_standard(state, ret);
if (ret < 0)
return ret;
}
return 0;
}
static int adv7180_s_std(struct v4l2_subdev *sd, v4l2_std_id std)
{
struct adv7180_state *state = to_state(sd);
int ret = mutex_lock_interruptible(&state->mutex);
if (ret)
return ret;
if (std == V4L2_STD_ALL) {
state->autodetect = true;
} else {
ret = v4l2_std_to_adv7180(std);
if (ret < 0)
goto out;
state->curr_norm = std;
state->autodetect = false;
}
ret = adv7180_program_std(state);
out:
mutex_unlock(&state->mutex);
return ret;
}
static int adv7180_set_power(struct adv7180_state *state, bool on)
{
u8 val;
int ret;
if (on)
val = ADV7180_PWR_MAN_ON;
else
val = ADV7180_PWR_MAN_OFF;
ret = adv7180_write(state, ADV7180_REG_PWR_MAN, val);
if (ret)
return ret;
if (state->chip_info->flags & ADV7180_FLAG_MIPI_CSI2) {
if (on) {
adv7180_csi_write(state, 0xDE, 0x02);
adv7180_csi_write(state, 0xD2, 0xF7);
adv7180_csi_write(state, 0xD8, 0x65);
adv7180_csi_write(state, 0xE0, 0x09);
adv7180_csi_write(state, 0x2C, 0x00);
if (state->field == V4L2_FIELD_NONE)
adv7180_csi_write(state, 0x1D, 0x80);
adv7180_csi_write(state, 0x00, 0x00);
} else {
adv7180_csi_write(state, 0x00, 0x80);
}
}
return 0;
}
static int adv7180_s_power(struct v4l2_subdev *sd, int on)
{
struct adv7180_state *state = to_state(sd);
int ret;
ret = mutex_lock_interruptible(&state->mutex);
if (ret)
return ret;
ret = adv7180_set_power(state, on);
if (ret == 0)
state->powered = on;
mutex_unlock(&state->mutex);
return ret;
}
static int adv7180_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct v4l2_subdev *sd = to_adv7180_sd(ctrl);
struct adv7180_state *state = to_state(sd);
int ret = mutex_lock_interruptible(&state->mutex);
int val;
if (ret)
return ret;
val = ctrl->val;
switch (ctrl->id) {
case V4L2_CID_BRIGHTNESS:
ret = adv7180_write(state, ADV7180_REG_BRI, val);
break;
case V4L2_CID_HUE:
ret = adv7180_write(state, ADV7180_REG_HUE, -val);
break;
case V4L2_CID_CONTRAST:
ret = adv7180_write(state, ADV7180_REG_CON, val);
break;
case V4L2_CID_SATURATION:
ret = adv7180_write(state, ADV7180_REG_SD_SAT_CB, val);
if (ret < 0)
break;
ret = adv7180_write(state, ADV7180_REG_SD_SAT_CR, val);
break;
case V4L2_CID_ADV_FAST_SWITCH:
if (ctrl->val) {
adv7180_write(state, 0x80d9, 0x44);
adv7180_write(state, ADV7180_REG_FLCONTROL,
ADV7180_FLCONTROL_FL_ENABLE);
} else {
adv7180_write(state, 0x80d9, 0xc4);
adv7180_write(state, ADV7180_REG_FLCONTROL, 0x00);
}
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
v4l2_ctrl_new_custom(&state->ctrl_hdl, &adv7180_ctrl_fast_switch, NULL);
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
static int adv7180_enum_mbus_code(struct v4l2_subdev *sd,
struct v4l2_subdev_fh *fh,
struct v4l2_subdev_mbus_code_enum *code)
{
if (code->index != 0)
return -EINVAL;
code->code = MEDIA_BUS_FMT_YUYV8_2X8;
return 0;
}
static int adv7180_mbus_fmt(struct v4l2_subdev *sd,
struct v4l2_mbus_framefmt *fmt)
{
struct adv7180_state *state = to_state(sd);
fmt->code = MEDIA_BUS_FMT_YUYV8_2X8;
fmt->colorspace = V4L2_COLORSPACE_SMPTE170M;
fmt->width = 720;
fmt->height = state->curr_norm & V4L2_STD_525_60 ? 480 : 576;
return 0;
}
static int adv7180_set_field_mode(struct adv7180_state *state)
{
if (!(state->chip_info->flags & ADV7180_FLAG_I2P))
return 0;
if (state->field == V4L2_FIELD_NONE) {
if (state->chip_info->flags & ADV7180_FLAG_MIPI_CSI2) {
adv7180_csi_write(state, 0x01, 0x20);
adv7180_csi_write(state, 0x02, 0x28);
adv7180_csi_write(state, 0x03, 0x38);
adv7180_csi_write(state, 0x04, 0x30);
adv7180_csi_write(state, 0x05, 0x30);
adv7180_csi_write(state, 0x06, 0x80);
adv7180_csi_write(state, 0x07, 0x70);
adv7180_csi_write(state, 0x08, 0x50);
}
adv7180_vpp_write(state, 0xa3, 0x00);
adv7180_vpp_write(state, 0x5b, 0x00);
adv7180_vpp_write(state, 0x55, 0x80);
} else {
if (state->chip_info->flags & ADV7180_FLAG_MIPI_CSI2) {
adv7180_csi_write(state, 0x01, 0x18);
adv7180_csi_write(state, 0x02, 0x18);
adv7180_csi_write(state, 0x03, 0x30);
adv7180_csi_write(state, 0x04, 0x20);
adv7180_csi_write(state, 0x05, 0x28);
adv7180_csi_write(state, 0x06, 0x40);
adv7180_csi_write(state, 0x07, 0x58);
adv7180_csi_write(state, 0x08, 0x30);
}
adv7180_vpp_write(state, 0xa3, 0x70);
adv7180_vpp_write(state, 0x5b, 0x80);
adv7180_vpp_write(state, 0x55, 0x00);
}
return 0;
}
static int adv7180_get_pad_format(struct v4l2_subdev *sd,
struct v4l2_subdev_fh *fh,
struct v4l2_subdev_format *format)
{
struct adv7180_state *state = to_state(sd);
if (format->which == V4L2_SUBDEV_FORMAT_TRY) {
format->format = *v4l2_subdev_get_try_format(fh, 0);
} else {
adv7180_mbus_fmt(sd, &format->format);
format->format.field = state->field;
}
return 0;
}
static int adv7180_set_pad_format(struct v4l2_subdev *sd,
struct v4l2_subdev_fh *fh,
struct v4l2_subdev_format *format)
{
struct adv7180_state *state = to_state(sd);
struct v4l2_mbus_framefmt *framefmt;
switch (format->format.field) {
case V4L2_FIELD_NONE:
if (!(state->chip_info->flags & ADV7180_FLAG_I2P))
format->format.field = V4L2_FIELD_INTERLACED;
break;
default:
format->format.field = V4L2_FIELD_INTERLACED;
break;
}
if (format->which == V4L2_SUBDEV_FORMAT_ACTIVE) {
framefmt = &format->format;
if (state->field != format->format.field) {
state->field = format->format.field;
adv7180_set_power(state, false);
adv7180_set_field_mode(state);
adv7180_set_power(state, true);
}
} else {
framefmt = v4l2_subdev_get_try_format(fh, 0);
*framefmt = format->format;
}
return adv7180_mbus_fmt(sd, framefmt);
}
static int adv7180_g_mbus_config(struct v4l2_subdev *sd,
struct v4l2_mbus_config *cfg)
{
struct adv7180_state *state = to_state(sd);
if (state->chip_info->flags & ADV7180_FLAG_MIPI_CSI2) {
cfg->type = V4L2_MBUS_CSI2;
cfg->flags = V4L2_MBUS_CSI2_1_LANE |
V4L2_MBUS_CSI2_CHANNEL_0 |
V4L2_MBUS_CSI2_CONTINUOUS_CLOCK;
} else {
cfg->flags = V4L2_MBUS_MASTER | V4L2_MBUS_PCLK_SAMPLE_RISING |
V4L2_MBUS_DATA_ACTIVE_HIGH;
cfg->type = V4L2_MBUS_BT656;
}
return 0;
}
static irqreturn_t adv7180_irq(int irq, void *devid)
{
struct adv7180_state *state = devid;
u8 isr3;
mutex_lock(&state->mutex);
isr3 = adv7180_read(state, ADV7180_REG_ISR3);
adv7180_write(state, ADV7180_REG_ICR3, isr3);
if (isr3 & ADV7180_IRQ3_AD_CHANGE && state->autodetect)
__adv7180_status(state, NULL, &state->curr_norm);
mutex_unlock(&state->mutex);
return IRQ_HANDLED;
}
static int adv7180_init(struct adv7180_state *state)
{
int ret;
ret = adv7180_write(state, ADV7180_REG_EXTENDED_OUTPUT_CONTROL,
ADV7180_EXTENDED_OUTPUT_CONTROL_NTSCDIS);
if (ret < 0)
return ret;
return adv7180_write(state, ADV7180_REG_NTSC_V_BIT_END,
ADV7180_NTSC_V_BIT_END_MANUAL_NVEND);
}
static int adv7180_set_std(struct adv7180_state *state, unsigned int std)
{
return adv7180_write(state, ADV7180_REG_INPUT_CONTROL,
(std << 4) | state->input);
}
static int adv7180_select_input(struct adv7180_state *state, unsigned int input)
{
int ret;
ret = adv7180_read(state, ADV7180_REG_INPUT_CONTROL);
if (ret < 0)
return ret;
ret &= ~ADV7180_INPUT_CONTROL_INSEL_MASK;
ret |= input;
return adv7180_write(state, ADV7180_REG_INPUT_CONTROL, ret);
}
static int adv7182_init(struct adv7180_state *state)
{
if (state->chip_info->flags & ADV7180_FLAG_MIPI_CSI2)
adv7180_write(state, ADV7180_REG_CSI_SLAVE_ADDR,
ADV7180_DEFAULT_CSI_I2C_ADDR << 1);
if (state->chip_info->flags & ADV7180_FLAG_I2P)
adv7180_write(state, ADV7180_REG_VPP_SLAVE_ADDR,
ADV7180_DEFAULT_VPP_I2C_ADDR << 1);
if (state->chip_info->flags & ADV7180_FLAG_V2) {
adv7180_write(state, 0x0080, 0x51);
adv7180_write(state, 0x0081, 0x51);
adv7180_write(state, 0x0082, 0x68);
}
if (state->chip_info->flags & ADV7180_FLAG_MIPI_CSI2) {
adv7180_write(state, 0x0003, 0x4e);
adv7180_write(state, 0x0004, 0x57);
adv7180_write(state, 0x001d, 0xc0);
} else {
if (state->chip_info->flags & ADV7180_FLAG_V2)
adv7180_write(state, 0x0004, 0x17);
else
adv7180_write(state, 0x0004, 0x07);
adv7180_write(state, 0x0003, 0x0c);
adv7180_write(state, 0x001d, 0x40);
}
adv7180_write(state, 0x0013, 0x00);
return 0;
}
static int adv7182_set_std(struct adv7180_state *state, unsigned int std)
{
return adv7180_write(state, ADV7182_REG_INPUT_VIDSEL, std << 4);
}
static enum adv7182_input_type adv7182_get_input_type(unsigned int input)
{
switch (input) {
case ADV7182_INPUT_CVBS_AIN1:
case ADV7182_INPUT_CVBS_AIN2:
case ADV7182_INPUT_CVBS_AIN3:
case ADV7182_INPUT_CVBS_AIN4:
case ADV7182_INPUT_CVBS_AIN5:
case ADV7182_INPUT_CVBS_AIN6:
case ADV7182_INPUT_CVBS_AIN7:
case ADV7182_INPUT_CVBS_AIN8:
return ADV7182_INPUT_TYPE_CVBS;
case ADV7182_INPUT_SVIDEO_AIN1_AIN2:
case ADV7182_INPUT_SVIDEO_AIN3_AIN4:
case ADV7182_INPUT_SVIDEO_AIN5_AIN6:
case ADV7182_INPUT_SVIDEO_AIN7_AIN8:
return ADV7182_INPUT_TYPE_SVIDEO;
case ADV7182_INPUT_YPRPB_AIN1_AIN2_AIN3:
case ADV7182_INPUT_YPRPB_AIN4_AIN5_AIN6:
return ADV7182_INPUT_TYPE_YPBPR;
case ADV7182_INPUT_DIFF_CVBS_AIN1_AIN2:
case ADV7182_INPUT_DIFF_CVBS_AIN3_AIN4:
case ADV7182_INPUT_DIFF_CVBS_AIN5_AIN6:
case ADV7182_INPUT_DIFF_CVBS_AIN7_AIN8:
return ADV7182_INPUT_TYPE_DIFF_CVBS;
default:
return 0;
}
}
static int adv7182_select_input(struct adv7180_state *state, unsigned int input)
{
enum adv7182_input_type input_type;
unsigned int *lbias;
unsigned int i;
int ret;
ret = adv7180_write(state, ADV7180_REG_INPUT_CONTROL, input);
if (ret)
return ret;
adv7180_write(state, 0x809c, 0x00);
adv7180_write(state, 0x809c, 0xff);
input_type = adv7182_get_input_type(input);
switch (input_type) {
case ADV7182_INPUT_TYPE_CVBS:
case ADV7182_INPUT_TYPE_DIFF_CVBS:
adv7180_write(state, 0x0017, 0x41);
break;
default:
adv7180_write(state, 0x0017, 0x01);
break;
}
if (state->chip_info->flags & ADV7180_FLAG_V2)
lbias = adv7280_lbias_settings[input_type];
else
lbias = adv7182_lbias_settings[input_type];
for (i = 0; i < ARRAY_SIZE(adv7182_lbias_settings[0]); i++)
adv7180_write(state, 0x0052 + i, lbias[i]);
if (input_type == ADV7182_INPUT_TYPE_DIFF_CVBS) {
adv7180_write(state, 0x005f, 0xa8);
adv7180_write(state, 0x005a, 0x90);
adv7180_write(state, 0x0060, 0xb0);
adv7180_write(state, 0x80b6, 0x08);
adv7180_write(state, 0x80c0, 0xa0);
} else {
adv7180_write(state, 0x005f, 0xf0);
adv7180_write(state, 0x005a, 0xd0);
adv7180_write(state, 0x0060, 0x10);
adv7180_write(state, 0x80b6, 0x9c);
adv7180_write(state, 0x80c0, 0x00);
}
return 0;
}
static int init_device(struct adv7180_state *state)
{
int ret;
mutex_lock(&state->mutex);
adv7180_write(state, ADV7180_REG_PWR_MAN, ADV7180_PWR_MAN_RES);
usleep_range(2000, 10000);
ret = state->chip_info->init(state);
if (ret)
goto out_unlock;
ret = adv7180_program_std(state);
if (ret)
goto out_unlock;
adv7180_set_field_mode(state);
if (state->irq > 0) {
ret = adv7180_write(state, ADV7180_REG_ICONF1,
ADV7180_ICONF1_ACTIVE_LOW |
ADV7180_ICONF1_PSYNC_ONLY);
if (ret < 0)
goto out_unlock;
ret = adv7180_write(state, ADV7180_REG_IMR1, 0);
if (ret < 0)
goto out_unlock;
ret = adv7180_write(state, ADV7180_REG_IMR2, 0);
if (ret < 0)
goto out_unlock;
ret = adv7180_write(state, ADV7180_REG_IMR3,
ADV7180_IRQ3_AD_CHANGE);
if (ret < 0)
goto out_unlock;
ret = adv7180_write(state, ADV7180_REG_IMR4, 0);
if (ret < 0)
goto out_unlock;
}
out_unlock:
mutex_unlock(&state->mutex);
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
if (state == NULL)
return -ENOMEM;
state->client = client;
state->field = V4L2_FIELD_INTERLACED;
state->chip_info = (struct adv7180_chip_info *)id->driver_data;
if (state->chip_info->flags & ADV7180_FLAG_MIPI_CSI2) {
state->csi_client = i2c_new_dummy(client->adapter,
ADV7180_DEFAULT_CSI_I2C_ADDR);
if (!state->csi_client)
return -ENOMEM;
}
if (state->chip_info->flags & ADV7180_FLAG_I2P) {
state->vpp_client = i2c_new_dummy(client->adapter,
ADV7180_DEFAULT_VPP_I2C_ADDR);
if (!state->vpp_client) {
ret = -ENOMEM;
goto err_unregister_csi_client;
}
}
state->irq = client->irq;
mutex_init(&state->mutex);
state->autodetect = true;
if (state->chip_info->flags & ADV7180_FLAG_RESET_POWERED)
state->powered = true;
else
state->powered = false;
state->input = 0;
sd = &state->sd;
v4l2_i2c_subdev_init(sd, client, &adv7180_ops);
sd->flags = V4L2_SUBDEV_FL_HAS_DEVNODE;
ret = adv7180_init_controls(state);
if (ret)
goto err_unregister_vpp_client;
state->pad.flags = MEDIA_PAD_FL_SOURCE;
sd->entity.flags |= MEDIA_ENT_T_V4L2_SUBDEV_DECODER;
ret = media_entity_init(&sd->entity, 1, &state->pad, 0);
if (ret)
goto err_free_ctrl;
ret = init_device(state);
if (ret)
goto err_media_entity_cleanup;
if (state->irq) {
ret = request_threaded_irq(client->irq, NULL, adv7180_irq,
IRQF_ONESHOT | IRQF_TRIGGER_FALLING,
KBUILD_MODNAME, state);
if (ret)
goto err_media_entity_cleanup;
}
ret = v4l2_async_register_subdev(sd);
if (ret)
goto err_free_irq;
return 0;
err_free_irq:
if (state->irq > 0)
free_irq(client->irq, state);
err_media_entity_cleanup:
media_entity_cleanup(&sd->entity);
err_free_ctrl:
adv7180_exit_controls(state);
err_unregister_vpp_client:
if (state->chip_info->flags & ADV7180_FLAG_I2P)
i2c_unregister_device(state->vpp_client);
err_unregister_csi_client:
if (state->chip_info->flags & ADV7180_FLAG_MIPI_CSI2)
i2c_unregister_device(state->csi_client);
mutex_destroy(&state->mutex);
return ret;
}
static int adv7180_remove(struct i2c_client *client)
{
struct v4l2_subdev *sd = i2c_get_clientdata(client);
struct adv7180_state *state = to_state(sd);
v4l2_async_unregister_subdev(sd);
if (state->irq > 0)
free_irq(client->irq, state);
media_entity_cleanup(&sd->entity);
adv7180_exit_controls(state);
if (state->chip_info->flags & ADV7180_FLAG_I2P)
i2c_unregister_device(state->vpp_client);
if (state->chip_info->flags & ADV7180_FLAG_MIPI_CSI2)
i2c_unregister_device(state->csi_client);
mutex_destroy(&state->mutex);
return 0;
}
static int adv7180_suspend(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct v4l2_subdev *sd = i2c_get_clientdata(client);
struct adv7180_state *state = to_state(sd);
return adv7180_set_power(state, false);
}
static int adv7180_resume(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct v4l2_subdev *sd = i2c_get_clientdata(client);
struct adv7180_state *state = to_state(sd);
int ret;
ret = init_device(state);
if (ret < 0)
return ret;
ret = adv7180_set_power(state, state->powered);
if (ret)
return ret;
return 0;
}
