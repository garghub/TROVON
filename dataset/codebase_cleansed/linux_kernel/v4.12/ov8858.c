static int ov8858_i2c_read(struct i2c_client *client, u16 len, u16 addr,
u8 *buf)
{
struct i2c_msg msg[2];
u8 address[2];
int err;
if (!client->adapter) {
dev_err(&client->dev, "%s error, no adapter\n", __func__);
return -ENODEV;
}
dev_dbg(&client->dev, "%s: len = %d, addr = 0x%04x\n",
__func__, len, addr);
memset(msg, 0, sizeof(msg));
address[0] = (addr >> 8) & 0xff;
address[1] = addr & 0xff;
msg[0].addr = client->addr;
msg[0].flags = 0;
msg[0].len = I2C_MSG_LENGTH;
msg[0].buf = address;
msg[1].addr = client->addr;
msg[1].len = len;
msg[1].flags = I2C_M_RD;
msg[1].buf = buf;
err = i2c_transfer(client->adapter, msg, ARRAY_SIZE(msg));
if (err != 2) {
if (err >= 0)
err = -EIO;
goto error;
}
return 0;
error:
dev_err(&client->dev, "reading from address 0x%x error %d", addr, err);
return err;
}
static int ov8858_read_reg(struct i2c_client *client, u16 type, u16 reg,
u16 *val)
{
u8 data[OV8858_SHORT_MAX];
int err;
dev_dbg(&client->dev, "%s: type = %d, reg = 0x%04x\n",
__func__, type, reg);
if (type != OV8858_8BIT && type != OV8858_16BIT) {
dev_err(&client->dev, "%s error, invalid data length\n",
__func__);
return -EINVAL;
}
memset(data, 0, sizeof(data));
err = ov8858_i2c_read(client, type, reg, data);
if (err)
goto error;
if (type == OV8858_8BIT)
*val = (u8)data[0];
else
*val = data[0] << 8 | data[1];
dev_dbg(&client->dev, "%s: val = 0x%04x\n", __func__, *val);
return 0;
error:
dev_err(&client->dev, "read from offset 0x%x error %d", reg, err);
return err;
}
static int ov8858_i2c_write(struct i2c_client *client, u16 len, u8 *data)
{
struct i2c_msg msg;
const int num_msg = 1;
int ret;
msg.addr = client->addr;
msg.flags = 0;
msg.len = len;
msg.buf = data;
ret = i2c_transfer(client->adapter, &msg, 1);
return ret == num_msg ? 0 : -EIO;
}
static int
ov8858_write_reg(struct i2c_client *client, u16 data_length, u16 reg, u16 val)
{
int ret;
unsigned char data[4] = {0};
u16 *wreg;
const u16 len = data_length + sizeof(u16);
dev_dbg(&client->dev,
"%s: data_length = %d, reg = 0x%04x, val = 0x%04x\n",
__func__, data_length, reg, val);
if (!client->adapter) {
dev_err(&client->dev, "%s error, no adapter\n", __func__);
return -ENODEV;
}
if (data_length != OV8858_8BIT && data_length != OV8858_16BIT) {
dev_err(&client->dev, "%s error, invalid length\n", __func__);
return -EINVAL;
}
wreg = (u16 *)data;
*wreg = cpu_to_be16(reg);
if (data_length == OV8858_8BIT) {
data[2] = (u8)(val);
} else {
u16 *wdata = (u16 *)&data[2];
*wdata = be16_to_cpu(val);
}
ret = ov8858_i2c_write(client, len, data);
if (ret)
dev_err(&client->dev,
"write error: wrote 0x%x to offset 0x%x error %d",
val, reg, ret);
return ret;
}
static int __ov8858_flush_reg_array(struct i2c_client *client,
struct ov8858_write_ctrl *ctrl)
{
u16 size;
if (ctrl->index == 0)
return 0;
size = sizeof(u16) + ctrl->index;
ctrl->buffer.addr = cpu_to_be16(ctrl->buffer.addr);
ctrl->index = 0;
return ov8858_i2c_write(client, size, (u8 *)&ctrl->buffer);
}
static int __ov8858_buf_reg_array(struct i2c_client *client,
struct ov8858_write_ctrl *ctrl,
const struct ov8858_reg *next)
{
int size;
u16 *data16;
switch (next->type) {
case OV8858_8BIT:
size = 1;
ctrl->buffer.data[ctrl->index] = (u8)next->val;
break;
case OV8858_16BIT:
size = 2;
data16 = (u16 *)&ctrl->buffer.data[ctrl->index];
*data16 = cpu_to_be16((u16)next->val);
break;
default:
return -EINVAL;
}
if (ctrl->index == 0)
ctrl->buffer.addr = next->sreg;
ctrl->index += size;
if (ctrl->index + sizeof(u16) >= OV8858_MAX_WRITE_BUF_SIZE)
__ov8858_flush_reg_array(client, ctrl);
return 0;
}
static int
__ov8858_write_reg_is_consecutive(struct i2c_client *client,
struct ov8858_write_ctrl *ctrl,
const struct ov8858_reg *next)
{
if (ctrl->index == 0)
return 1;
return ctrl->buffer.addr + ctrl->index == next->sreg;
}
static int ov8858_write_reg_array(struct i2c_client *client,
const struct ov8858_reg *reglist)
{
const struct ov8858_reg *next = reglist;
struct ov8858_write_ctrl ctrl;
int err;
ctrl.index = 0;
for (; next->type != OV8858_TOK_TERM; next++) {
switch (next->type & OV8858_TOK_MASK) {
case OV8858_TOK_DELAY:
err = __ov8858_flush_reg_array(client, &ctrl);
if (err)
return err;
msleep(next->val);
break;
default:
if (!__ov8858_write_reg_is_consecutive(client,
&ctrl, next)) {
err = __ov8858_flush_reg_array(client, &ctrl);
if (err)
return err;
}
err = __ov8858_buf_reg_array(client, &ctrl, next);
if (err) {
dev_err(&client->dev, "%s: write error\n",
__func__);
return err;
}
break;
}
}
return __ov8858_flush_reg_array(client, &ctrl);
}
static int __ov8858_min_fps_diff(int fps,
const struct ov8858_fps_setting *fps_list)
{
int diff = INT_MAX;
int i;
if (fps == 0)
return 0;
for (i = 0; i < MAX_FPS_OPTIONS_SUPPORTED; i++) {
if (!fps_list[i].fps)
break;
if (abs(fps_list[i].fps - fps) < diff)
diff = abs(fps_list[i].fps - fps);
}
return diff;
}
static int __ov8858_nearest_fps_index(int fps,
const struct ov8858_fps_setting *fps_list)
{
int fps_index = 0;
int i;
for (i = 0; i < MAX_FPS_OPTIONS_SUPPORTED; i++) {
if (!fps_list[i].fps)
break;
if (abs(fps_list[i].fps - fps)
< abs(fps_list[fps_index].fps - fps))
fps_index = i;
}
return fps_index;
}
static int __ov8858_update_frame_timing(struct v4l2_subdev *sd,
u16 *hts, u16 *vts)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
int ret;
dev_dbg(&client->dev, "%s OV8858_TIMING_HTS=0x%04x\n",
__func__, *hts);
ret = ov8858_write_reg(client, OV8858_16BIT,
OV8858_TIMING_HTS, *hts >> 1);
if (ret)
return ret;
dev_dbg(&client->dev, "%s OV8858_TIMING_VTS=0x%04x\n",
__func__, *vts);
return ov8858_write_reg(client, OV8858_16BIT, OV8858_TIMING_VTS, *vts);
}
static int __ov8858_set_exposure(struct v4l2_subdev *sd, int exposure, int gain,
int dig_gain, u16 *hts, u16 *vts)
{
struct ov8858_device *dev = to_ov8858_sensor(sd);
struct i2c_client *client = v4l2_get_subdevdata(sd);
int exp_val, ret;
dev_dbg(&client->dev, "%s, exposure = %d, gain=%d, dig_gain=%d\n",
__func__, exposure, gain, dig_gain);
if (dev->limit_exposure_flag) {
if (exposure > *vts - OV8858_INTEGRATION_TIME_MARGIN)
exposure = *vts - OV8858_INTEGRATION_TIME_MARGIN;
} else {
if (*vts < exposure + OV8858_INTEGRATION_TIME_MARGIN)
*vts = (u16) exposure + OV8858_INTEGRATION_TIME_MARGIN;
}
ret = __ov8858_update_frame_timing(sd, hts, vts);
if (ret)
return ret;
exp_val = exposure << 4;
ret = ov8858_write_reg(client, OV8858_8BIT,
OV8858_LONG_EXPO+2, exp_val & 0xFF);
if (ret)
return ret;
ret = ov8858_write_reg(client, OV8858_8BIT,
OV8858_LONG_EXPO+1, (exp_val >> 8) & 0xFF);
if (ret)
return ret;
ret = ov8858_write_reg(client, OV8858_8BIT,
OV8858_LONG_EXPO, (exp_val >> 16) & 0x0F);
if (ret)
return ret;
if (dig_gain) {
ret = ov8858_write_reg(client, OV8858_16BIT,
OV8858_MWB_RED_GAIN_H, dig_gain);
if (ret)
return ret;
ret = ov8858_write_reg(client, OV8858_16BIT,
OV8858_MWB_GREEN_GAIN_H, dig_gain);
if (ret)
return ret;
ret = ov8858_write_reg(client, OV8858_16BIT,
OV8858_MWB_BLUE_GAIN_H, dig_gain);
if (ret)
return ret;
}
ret = ov8858_write_reg(client, OV8858_16BIT, OV8858_LONG_GAIN,
gain & 0x07ff);
if (ret)
return ret;
dev->gain = gain;
dev->exposure = exposure;
dev->digital_gain = dig_gain;
return 0;
}
static int ov8858_set_exposure(struct v4l2_subdev *sd, int exposure, int gain,
int dig_gain)
{
struct ov8858_device *dev = to_ov8858_sensor(sd);
const struct ov8858_resolution *res;
u16 hts, vts;
int ret;
mutex_lock(&dev->input_lock);
exposure = clamp_t(int, exposure, 0, OV8858_MAX_EXPOSURE_VALUE);
gain = clamp_t(int, gain, 0, OV8858_MAX_GAIN_VALUE);
dig_gain = clamp_t(int, dig_gain, 0, OV8858_MWB_GAIN_MAX);
res = &dev->curr_res_table[dev->fmt_idx];
hts = res->fps_options[dev->fps_index].pixels_per_line;
vts = res->fps_options[dev->fps_index].lines_per_frame;
ret = __ov8858_set_exposure(sd, exposure, gain, dig_gain, &hts, &vts);
mutex_unlock(&dev->input_lock);
return ret;
}
static int ov8858_g_update_exposure(struct v4l2_subdev *sd,
struct atomisp_update_exposure *exposure)
{
struct ov8858_device *dev = to_ov8858_sensor(sd);
struct i2c_client *client = v4l2_get_subdevdata(sd);
int gain = exposure->gain;
dev_dbg(&client->dev, "%s: gain: %d, digi_gain: %d\n", __func__,
exposure->gain, exposure->digi_gain);
exposure->update_digi_gain = dev->digital_gain;
exposure->update_gain = (((gain & 0x700) >> 8) + 1) * (gain & 0xFF);
return 0;
}
static int ov8858_s_exposure(struct v4l2_subdev *sd,
struct atomisp_exposure *exposure)
{
return ov8858_set_exposure(sd, exposure->integration_time[0],
exposure->gain[0], exposure->gain[1]);
}
static int ov8858_priv_int_data_init(struct v4l2_subdev *sd)
{
struct ov8858_device *dev = to_ov8858_sensor(sd);
struct i2c_client *client = v4l2_get_subdevdata(sd);
u32 size = OV8858_OTP_END_ADDR - OV8858_OTP_START_ADDR + 1;
int r;
u16 isp_ctrl2 = 0;
if (!dev->otp_data) {
dev->otp_data = devm_kzalloc(&client->dev, size, GFP_KERNEL);
if (!dev->otp_data) {
dev_err(&client->dev, "%s: can't allocate memory",
__func__);
r = -ENOMEM;
goto error3;
}
r = ov8858_write_reg(client, OV8858_8BIT, OV8858_STREAM_MODE,
0x01);
if (r)
goto error2;
r = ov8858_read_reg(client, OV8858_8BIT,
OV8858_OTP_ISP_CTRL2, &isp_ctrl2);
if (r)
goto error1;
r = ov8858_write_reg(client, OV8858_8BIT, OV8858_OTP_ISP_CTRL2,
isp_ctrl2 & ~OV8858_OTP_DPC_ENABLE);
if (r)
goto error1;
r = ov8858_write_reg(client, OV8858_8BIT, OV8858_OTP_MODE_CTRL,
OV8858_OTP_MODE_PROGRAM_DISABLE |
OV8858_OTP_MODE_MANUAL);
if (r)
goto error1;
r = ov8858_write_reg(client, OV8858_16BIT,
OV8858_OTP_START_ADDR_REG,
OV8858_OTP_START_ADDR);
if (r)
goto error1;
r = ov8858_write_reg(client, OV8858_16BIT,
OV8858_OTP_END_ADDR_REG,
OV8858_OTP_END_ADDR);
if (r)
goto error1;
r = ov8858_write_reg(client, OV8858_8BIT, OV8858_OTP_LOAD_CTRL,
OV8858_OTP_LOAD_ENABLE);
if (r)
goto error1;
usleep_range(5000, 5500);
r = ov8858_i2c_read(client, size, OV8858_OTP_START_ADDR,
dev->otp_data);
if (r)
goto error1;
r = ov8858_write_reg(client, OV8858_8BIT, OV8858_OTP_ISP_CTRL2,
isp_ctrl2 | OV8858_OTP_DPC_ENABLE);
if (r)
goto error1;
r = ov8858_write_reg(client, 1, OV8858_STREAM_MODE, 0x00);
if (r) {
dev_err(&client->dev, "%s: cannot turn off streaming\n",
__func__);
goto error1;
}
}
return 0;
error1:
ov8858_write_reg(client, OV8858_8BIT, OV8858_OTP_ISP_CTRL2,
isp_ctrl2 | OV8858_OTP_DPC_ENABLE);
ov8858_write_reg(client, 1, OV8858_STREAM_MODE, 0x00);
error2:
devm_kfree(&client->dev, dev->otp_data);
dev->otp_data = NULL;
error3:
dev_err(&client->dev, "%s: OTP reading failed\n", __func__);
return r;
}
static int ov8858_g_priv_int_data(struct v4l2_subdev *sd,
struct v4l2_private_int_data *priv)
{
struct ov8858_device *dev = to_ov8858_sensor(sd);
struct i2c_client *client = v4l2_get_subdevdata(sd);
u32 size = OV8858_OTP_END_ADDR - OV8858_OTP_START_ADDR + 1;
int r;
mutex_lock(&dev->input_lock);
if (!dev->otp_data) {
dev_err(&client->dev, "%s: otp data is NULL\n", __func__);
mutex_unlock(&dev->input_lock);
return -EFAULT;
}
if (copy_to_user(priv->data, dev->otp_data,
min_t(__u32, priv->size, size))) {
r = -EFAULT;
dev_err(&client->dev, "%s: OTP reading failed\n", __func__);
mutex_unlock(&dev->input_lock);
return r;
}
priv->size = size;
mutex_unlock(&dev->input_lock);
return 0;
}
static int __ov8858_init(struct v4l2_subdev *sd)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct ov8858_device *dev = to_ov8858_sensor(sd);
int ret;
dev_dbg(&client->dev, "%s\n", __func__);
dev->fps_index = 0;
dev->exposure = 256;
dev->gain = 16;
dev->digital_gain = 1024;
dev->limit_exposure_flag = false;
dev_dbg(&client->dev, "%s: Writing basic settings to ov8858\n",
__func__);
ret = ov8858_write_reg_array(client, ov8858_BasicSettings);
if (ret)
return ret;
return ov8858_priv_int_data_init(sd);
}
static int ov8858_init(struct v4l2_subdev *sd, u32 val)
{
struct ov8858_device *dev = to_ov8858_sensor(sd);
int ret;
mutex_lock(&dev->input_lock);
ret = __ov8858_init(sd);
mutex_unlock(&dev->input_lock);
return ret;
}
static void ov8858_uninit(struct v4l2_subdev *sd)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct ov8858_device *dev = to_ov8858_sensor(sd);
struct v4l2_ctrl *ctrl;
dev_dbg(&client->dev, "%s:\n", __func__);
dev->exposure = 0;
dev->gain = 0;
dev->digital_gain = 0;
dev->limit_exposure_flag = false;
mutex_unlock(&dev->input_lock);
ctrl = v4l2_ctrl_find(sd->ctrl_handler,
V4L2_CID_EXPOSURE_AUTO_PRIORITY);
if (ctrl)
v4l2_ctrl_s_ctrl(ctrl, V4L2_EXPOSURE_AUTO);
mutex_lock(&dev->input_lock);
}
static int ov8858_g_comp_delay(struct v4l2_subdev *sd, unsigned int *usec)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct ov8858_device *dev = to_ov8858_sensor(sd);
int ret = 0, exposure;
u16 vts, data;
if (dev->exposure == 0) {
ret = ov8858_read_reg(client, OV8858_16BIT,
OV8858_LONG_EXPO + 1, &data);
if (ret)
return ret;
exposure = data;
exposure >>= 4;
} else {
exposure = dev->exposure;
}
ret = ov8858_read_reg(client, OV8858_16BIT, OV8858_TIMING_VTS, &vts);
if (ret || vts == 0)
vts = OV8858_DEPTH_VTS_CONST;
*usec = (exposure * 33333 / vts);
if (*usec > OV8858_DEPTH_COMP_CONST)
*usec = *usec - OV8858_DEPTH_COMP_CONST;
else
*usec = OV8858_DEPTH_COMP_CONST;
return 0;
}
static long ov8858_ioctl(struct v4l2_subdev *sd, unsigned int cmd, void *arg)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
switch (cmd) {
case ATOMISP_IOC_S_EXPOSURE:
return ov8858_s_exposure(sd, (struct atomisp_exposure *)arg);
case ATOMISP_IOC_G_SENSOR_PRIV_INT_DATA:
return ov8858_g_priv_int_data(sd, arg);
case ATOMISP_IOC_G_DEPTH_SYNC_COMP:
return ov8858_g_comp_delay(sd, (unsigned int *)arg);
case ATOMISP_IOC_G_UPDATE_EXPOSURE:
return ov8858_g_update_exposure(sd,
(struct atomisp_update_exposure *)arg);
default:
dev_dbg(&client->dev, "Unhandled command 0x%X\n", cmd);
return -EINVAL;
}
}
static int __power_ctrl(struct v4l2_subdev *sd, bool flag)
{
int ret = 0;
struct ov8858_device *dev = to_ov8858_sensor(sd);
struct i2c_client *client = v4l2_get_subdevdata(sd);
if (!dev || !dev->platform_data)
return -ENODEV;
if (dev->platform_data->power_ctrl)
return dev->platform_data->power_ctrl(sd, flag);
if (dev->platform_data->v1p2_ctrl) {
ret = dev->platform_data->v1p2_ctrl(sd, flag);
if (ret) {
dev_err(&client->dev,
"failed to power %s 1.2v power rail\n",
flag ? "up" : "down");
return ret;
}
}
if (dev->platform_data->v2p8_ctrl) {
ret = dev->platform_data->v2p8_ctrl(sd, flag);
if (ret) {
dev_err(&client->dev,
"failed to power %s 2.8v power rail\n",
flag ? "up" : "down");
return ret;
}
}
if (dev->platform_data->v1p8_ctrl) {
ret = dev->platform_data->v1p8_ctrl(sd, flag);
if (ret) {
dev_err(&client->dev,
"failed to power %s 1.8v power rail\n",
flag ? "up" : "down");
if (dev->platform_data->v2p8_ctrl)
dev->platform_data->v2p8_ctrl(sd, 0);
return ret;
}
}
if (flag)
msleep(20);
return ret;
}
static int __gpio_ctrl(struct v4l2_subdev *sd, bool flag)
{
struct i2c_client *client;
struct ov8858_device *dev;
if (!sd)
return -EINVAL;
client = v4l2_get_subdevdata(sd);
dev = to_ov8858_sensor(sd);
if (!client || !dev || !dev->platform_data)
return -ENODEV;
if (dev->platform_data->gpio_ctrl)
return dev->platform_data->gpio_ctrl(sd, flag);
if (dev->platform_data->gpio0_ctrl)
return dev->platform_data->gpio0_ctrl(sd, flag);
dev_err(&client->dev, "failed to find platform gpio callback\n");
return -EINVAL;
}
static int power_up(struct v4l2_subdev *sd)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct ov8858_device *dev = to_ov8858_sensor(sd);
int ret;
dev_dbg(&client->dev, "%s\n", __func__);
ret = __power_ctrl(sd, 1);
if (ret) {
dev_err(&client->dev, "power rail on failed %d.\n", ret);
goto fail_power;
}
ret = dev->platform_data->flisclk_ctrl(sd, 1);
if (ret) {
dev_err(&client->dev, "flisclk on failed %d\n", ret);
goto fail_clk;
}
ret = __gpio_ctrl(sd, 1);
if (ret) {
dev_err(&client->dev, "gpio on failed %d\n", ret);
goto fail_gpio;
}
usleep_range(2000, 2500);
return 0;
fail_gpio:
dev->platform_data->flisclk_ctrl(sd, 0);
fail_clk:
__power_ctrl(sd, 0);
fail_power:
dev_err(&client->dev, "Sensor power-up failed\n");
return ret;
}
static int power_down(struct v4l2_subdev *sd)
{
struct ov8858_device *dev = to_ov8858_sensor(sd);
struct i2c_client *client = v4l2_get_subdevdata(sd);
int ret;
dev_dbg(&client->dev, "%s\n", __func__);
ret = dev->platform_data->flisclk_ctrl(sd, 0);
if (ret)
dev_err(&client->dev, "flisclk off failed\n");
ret = __gpio_ctrl(sd, 0);
if (ret)
dev_err(&client->dev, "gpio off failed\n");
ret = __power_ctrl(sd, 0);
if (ret)
dev_err(&client->dev, "power rail off failed.\n");
return ret;
}
static int __ov8858_s_power(struct v4l2_subdev *sd, int on)
{
struct ov8858_device *dev = to_ov8858_sensor(sd);
int ret, r = 0;
if (on == 0) {
ov8858_uninit(sd);
if (dev->vcm_driver && dev->vcm_driver->power_down)
r = dev->vcm_driver->power_down(sd);
ret = power_down(sd);
if (r != 0 && ret == 0)
ret = r;
} else {
ret = power_up(sd);
if (ret)
power_down(sd);
if (dev->vcm_driver && dev->vcm_driver->power_up) {
ret = dev->vcm_driver->power_up(sd);
if (ret) {
power_down(sd);
return ret;
}
}
return __ov8858_init(sd);
}
return ret;
}
static int ov8858_s_power(struct v4l2_subdev *sd, int on)
{
int ret;
struct ov8858_device *dev = to_ov8858_sensor(sd);
mutex_lock(&dev->input_lock);
ret = __ov8858_s_power(sd, on);
mutex_unlock(&dev->input_lock);
if (!ret && on)
v4l2_ctrl_s_ctrl(dev->run_mode, ATOMISP_RUN_MODE_PREVIEW);
return ret;
}
static int ov8858_get_register(struct v4l2_subdev *sd, int reg, int type,
const struct ov8858_reg *reglist)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
const struct ov8858_reg *next;
u16 val;
for (next = reglist; next->type != OV8858_TOK_TERM; next++) {
if (next->sreg == reg) {
if (type == OV8858_8BIT)
return next->val;
if (type == OV8858_16BIT &&
next[1].type != OV8858_TOK_TERM)
return next[0].val << 8 | next[1].val;
}
}
if (ov8858_read_reg(client, type, reg, &val)) {
dev_err(&client->dev, "failed to read register 0x%08x\n", reg);
return -EIO;
}
return val;
}
static inline int ov8858_get_register_16bit(struct v4l2_subdev *sd, int reg,
const struct ov8858_reg *reglist)
{
return ov8858_get_register(sd, reg, OV8858_16BIT, reglist);
}
static inline int ov8858_get_register_8bit(struct v4l2_subdev *sd, int reg,
const struct ov8858_reg *reglist)
{
return ov8858_get_register(sd, reg, OV8858_8BIT, reglist);
}
static int __ov8858_get_pll1_values(struct v4l2_subdev *sd,
int *value,
const struct ov8858_reg *reglist)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
unsigned int prediv_idx;
unsigned int multiplier;
unsigned int sys_prediv;
unsigned int prediv_coef[] = {2, 3, 4, 5, 6, 8, 12, 16};
int ret;
ret = ov8858_get_register_8bit(sd, OV8858_PLL1_PREDIV0, reglist);
if (ret < 0)
return ret;
if (ret & OV8858_PLL1_PREDIV0_MASK)
*value /= 2;
ret = ov8858_get_register_8bit(sd, OV8858_PLL1_PREDIV, reglist);
if (ret < 0)
return ret;
prediv_idx = ret & OV8858_PLL1_PREDIV_MASK;
*value = *value * 2 / prediv_coef[prediv_idx];
ret = ov8858_get_register_16bit(sd, OV8858_PLL1_MULTIPLIER, reglist);
if (ret < 0)
return ret;
multiplier = ret;
*value *= multiplier & OV8858_PLL1_MULTIPLIER_MASK;
ret = ov8858_get_register_8bit(sd, OV8858_PLL1_SYS_PRE_DIV, reglist);
if (ret < 0)
return ret;
sys_prediv = ret & OV8858_PLL1_SYS_PRE_DIV_MASK;
*value /= (sys_prediv + 3);
ret = ov8858_get_register_8bit(sd, OV8858_PLL1_SYS_DIVIDER, reglist);
if (ret < 0)
return ret;
if (ret & OV8858_PLL1_SYS_DIVIDER_MASK)
*value /= 2;
dev_dbg(&client->dev, "%s: *value: %d\n", __func__, *value);
return 0;
}
static int __ov8858_get_pll2a_values(struct v4l2_subdev *sd, int *value,
const struct ov8858_reg *reglist)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
unsigned int prediv_idx;
unsigned int multiplier;
unsigned int prediv_coef[] = {2, 3, 4, 5, 6, 8, 12, 16};
int ret;
ret = ov8858_get_register_8bit(sd, OV8858_PLL2_PREDIV0, reglist);
if (ret < 0)
return ret;
if (ret & OV8858_PLL2_PREDIV0_MASK)
*value /= 2;
ret = ov8858_get_register_8bit(sd, OV8858_PLL2_PREDIV, reglist);
if (ret < 0)
return ret;
prediv_idx = (ret & OV8858_PLL2_PREDIV_MASK);
*value = *value * 2 / prediv_coef[prediv_idx];
ret = ov8858_get_register_16bit(sd, OV8858_PLL2_MULTIPLIER, reglist);
if (ret < 0)
return ret;
multiplier = ret;
*value *= multiplier & OV8858_PLL2_MULTIPLIER_MASK;
dev_dbg(&client->dev, "%s: *value: %d\n", __func__, *value);
return 0;
}
static int __ov8858_get_pll2b_values(struct v4l2_subdev *sd, int *value,
const struct ov8858_reg *reglist)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
unsigned int dac_divider;
int ret;
ret = ov8858_get_register_8bit(sd, OV8858_PLL2_DAC_DIVIDER, reglist);
if (ret < 0)
return ret;
dac_divider = (ret & OV8858_PLL2_DAC_DIVIDER_MASK) + 1;
*value /= dac_divider;
dev_dbg(&client->dev, "%s: *value: %d\n", __func__, *value);
return 0;
}
static int __ov8858_get_pll2c_values(struct v4l2_subdev *sd, int *value,
const struct ov8858_reg *reglist)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
unsigned int sys_pre_div;
unsigned int sys_divider_idx;
unsigned int sys_divider_coef[] = {2, 3, 4, 5, 6, 7, 8, 10};
int ret;
ret = ov8858_get_register_8bit(sd, OV8858_PLL2_SYS_PRE_DIV, reglist);
if (ret < 0)
return ret;
sys_pre_div = (ret & OV8858_PLL2_SYS_PRE_DIV_MASK) + 1;
*value /= sys_pre_div;
ret = ov8858_get_register_8bit(sd, OV8858_PLL2_SYS_DIVIDER, reglist);
if (ret < 0)
return ret;
sys_divider_idx = ret & OV8858_PLL2_SYS_DIVIDER_MASK;
*value *= 2 / sys_divider_coef[sys_divider_idx];
dev_dbg(&client->dev, "%s: *value: %d\n", __func__, *value);
return 0;
}
static int ov8858_get_intg_factor(struct v4l2_subdev *sd,
struct camera_mipi_info *info,
const struct ov8858_reg *reglist)
{
const unsigned int ext_clk = 19200000;
struct atomisp_sensor_mode_data *m = &info->data;
struct ov8858_device *dev = to_ov8858_sensor(sd);
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct device *d = &client->dev;
const struct ov8858_resolution *res =
&dev->curr_res_table[dev->fmt_idx];
unsigned int pll_sclksel1;
unsigned int pll_sclksel2;
unsigned int sys_pre_div;
unsigned int sclk_pdiv;
unsigned int sclk = ext_clk;
u16 hts;
int ret;
memset(&info->data, 0, sizeof(info->data));
ret = ov8858_get_register_8bit(sd, OV8858_PLL_SCLKSEL1, reglist);
if (ret < 0)
return ret;
dev_dbg(d, "%s: OV8858_PLL_SCLKSEL1: 0x%02x\n", __func__, ret);
pll_sclksel1 = ret & OV8858_PLL_SCLKSEL1_MASK;
ret = ov8858_get_register_8bit(sd, OV8858_PLL_SCLKSEL2, reglist);
if (ret < 0)
return ret;
dev_dbg(d, "%s: OV8858_PLL_SCLKSEL2: 0x%02x\n", __func__, ret);
pll_sclksel2 = ret & OV8858_PLL_SCLKSEL2_MASK;
if (pll_sclksel2) {
ret = __ov8858_get_pll2a_values(sd, &sclk, reglist);
if (ret < 0)
return ret;
ret = __ov8858_get_pll2b_values(sd, &sclk, reglist);
if (ret < 0)
return ret;
} else if (pll_sclksel1) {
ret = __ov8858_get_pll2a_values(sd, &sclk, reglist);
if (ret < 0)
return ret;
ret = __ov8858_get_pll2c_values(sd, &sclk, reglist);
if (ret < 0)
return ret;
} else {
ret = __ov8858_get_pll1_values(sd, &sclk, reglist);
if (ret < 0)
return ret;
}
ret = ov8858_get_register_8bit(sd, OV8858_SRB_HOST_INPUT_DIS, reglist);
if (ret < 0)
return ret;
dev_dbg(d, "%s: OV8858_SRB_HOST_INPUT_DIS: 0x%02x\n", __func__, ret);
sys_pre_div = ret & OV8858_SYS_PRE_DIV_MASK;
sys_pre_div >>= OV8858_SYS_PRE_DIV_OFFSET;
if (sys_pre_div == 1)
sclk /= 2;
else if (sys_pre_div == 2)
sclk /= 4;
sclk_pdiv = ret & OV8858_SCLK_PDIV_MASK;
sclk_pdiv >>= OV8858_SCLK_PDIV_OFFSET;
if (sclk_pdiv > 1)
sclk /= sclk_pdiv;
dev_dbg(d, "%s: sclk: %d\n", __func__, sclk);
dev->vt_pix_clk_freq_mhz = sclk;
m->vt_pix_clk_freq_mhz = sclk;
m->frame_length_lines =
res->fps_options[dev->fps_index].lines_per_frame;
m->line_length_pck = res->fps_options[dev->fps_index].pixels_per_line;
m->coarse_integration_time_min = 0;
m->coarse_integration_time_max_margin = OV8858_INTEGRATION_TIME_MARGIN;
ret = ov8858_read_reg(client, OV8858_16BIT, OV8858_TIMING_HTS, &hts);
if (ret < 0)
return ret;
m->hts = hts;
dev_dbg(&client->dev, "%s: get HTS %d\n", __func__, hts);
m->fine_integration_time_min = 0;
m->fine_integration_time_max_margin = 0;
m->read_mode = res->bin_factor_x ?
OV8858_READ_MODE_BINNING_ON : OV8858_READ_MODE_BINNING_OFF;
ret = ov8858_get_register_8bit(sd, OV8858_H_INC_ODD, res->regs);
if (ret < 0)
return ret;
m->binning_factor_x = (ret + 1) / 2;
ret = ov8858_get_register_8bit(sd, OV8858_V_INC_ODD, res->regs);
if (ret < 0)
return ret;
m->binning_factor_y = (ret + 1) / 2;
ret = ov8858_get_register_16bit(sd, OV8858_HORIZONTAL_START_H,
res->regs);
if (ret < 0)
return ret;
m->crop_horizontal_start = ret;
ret = ov8858_get_register_16bit(sd, OV8858_VERTICAL_START_H, res->regs);
if (ret < 0)
return ret;
m->crop_vertical_start = ret;
ret = ov8858_get_register_16bit(sd, OV8858_HORIZONTAL_END_H, res->regs);
if (ret < 0)
return ret;
m->crop_horizontal_end = ret;
ret = ov8858_get_register_16bit(sd, OV8858_VERTICAL_END_H, res->regs);
if (ret < 0)
return ret;
m->crop_vertical_end = ret;
ret = ov8858_get_register_16bit(sd, OV8858_HORIZONTAL_OUTPUT_SIZE_H,
res->regs);
if (ret < 0)
return ret;
m->output_width = ret;
ret = ov8858_get_register_16bit(sd, OV8858_VERTICAL_OUTPUT_SIZE_H,
res->regs);
if (ret < 0)
return ret;
m->output_height = ret;
return 0;
}
static int distance(struct ov8858_resolution const *res, const u32 w,
const u32 h)
{
int ratio;
int distance;
if (w == 0 || h == 0 ||
res->width < w || res->height < h)
return -1;
ratio = res->width << 13;
ratio /= w;
ratio *= h;
ratio /= res->height;
distance = abs(ratio - 8192);
if (distance > LARGEST_ALLOWED_RATIO_MISMATCH)
return -1;
return distance;
}
static int nearest_resolution_index(struct v4l2_subdev *sd, int w, int h)
{
int i;
int idx = -1;
int dist;
int fps_diff;
int min_fps_diff = INT_MAX;
int min_dist = INT_MAX;
int min_res_w = INT_MAX;
const struct ov8858_resolution *tmp_res = NULL;
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct ov8858_device *dev = to_ov8858_sensor(sd);
dev_dbg(&client->dev, "%s: w=%d, h=%d\n", __func__, w, h);
for (i = 0; i < dev->entries_curr_table; i++) {
tmp_res = &dev->curr_res_table[i];
dist = distance(tmp_res, w, h);
dev_dbg(&client->dev,
"%s[%d]: %dx%d distance=%d\n", tmp_res->desc,
i, tmp_res->width, tmp_res->height, dist);
if (dist == -1)
continue;
if (dist < min_dist) {
min_dist = dist;
min_res_w = tmp_res->width;
min_fps_diff = __ov8858_min_fps_diff(dev->fps,
tmp_res->fps_options);
idx = i;
}
if (dist == min_dist) {
fps_diff = __ov8858_min_fps_diff(dev->fps,
tmp_res->fps_options);
if (fps_diff < min_fps_diff) {
min_fps_diff = fps_diff;
idx = i;
}
if (tmp_res->width < min_res_w) {
min_res_w = tmp_res->width;
idx = i;
}
}
}
return idx;
}
static int ov8858_set_fmt(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_format *format)
{
struct v4l2_mbus_framefmt *fmt = &format->format;
struct ov8858_device *dev = to_ov8858_sensor(sd);
struct camera_mipi_info *ov8858_info = NULL;
struct i2c_client *client = v4l2_get_subdevdata(sd);
const struct ov8858_resolution *res;
int ret;
int idx;
if (format->pad)
return -EINVAL;
if (!fmt)
return -EINVAL;
ov8858_info = v4l2_get_subdev_hostdata(sd);
if (ov8858_info == NULL)
return -EINVAL;
mutex_lock(&dev->input_lock);
if ((fmt->width > OV8858_RES_WIDTH_MAX) ||
(fmt->height > OV8858_RES_HEIGHT_MAX)) {
fmt->width = OV8858_RES_WIDTH_MAX;
fmt->height = OV8858_RES_HEIGHT_MAX;
} else {
idx = nearest_resolution_index(sd, fmt->width, fmt->height);
if (idx == -1)
idx = dev->entries_curr_table - 1;
fmt->width = dev->curr_res_table[idx].width;
fmt->height = dev->curr_res_table[idx].height;
}
fmt->code = MEDIA_BUS_FMT_SBGGR10_1X10;
if (format->which == V4L2_SUBDEV_FORMAT_TRY) {
cfg->try_fmt = *fmt;
mutex_unlock(&dev->input_lock);
return 0;
}
dev->fmt_idx = nearest_resolution_index(sd, fmt->width, fmt->height);
if (dev->fmt_idx == -1) {
ret = -EINVAL;
goto out;
}
res = &dev->curr_res_table[dev->fmt_idx];
dev_dbg(&client->dev, "%s: selected width = %d, height = %d\n",
__func__, res->width, res->height);
dev->fps_index = __ov8858_nearest_fps_index(dev->fps, res->fps_options);
dev->fps = res->fps_options[dev->fps_index].fps;
dev->regs = res->fps_options[dev->fps_index].regs;
if (!dev->regs)
dev->regs = res->regs;
ret = ov8858_write_reg_array(client, dev->regs);
if (ret)
goto out;
dev->pixels_per_line = res->fps_options[dev->fps_index].pixels_per_line;
dev->lines_per_frame = res->fps_options[dev->fps_index].lines_per_frame;
ov8858_info->metadata_width = res->width * 10 / 8;
ov8858_info->metadata_height = 2;
ov8858_info->metadata_format = ATOMISP_INPUT_FORMAT_EMBEDDED;
ret = __ov8858_set_exposure(sd, dev->exposure, dev->gain,
dev->digital_gain, &dev->pixels_per_line,
&dev->lines_per_frame);
if (ret)
goto out;
ret = ov8858_get_intg_factor(sd, ov8858_info, dev->regs);
out:
mutex_unlock(&dev->input_lock);
return ret;
}
static int ov8858_get_fmt(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_format *format)
{
struct v4l2_mbus_framefmt *fmt = &format->format;
struct ov8858_device *dev = to_ov8858_sensor(sd);
if (format->pad)
return -EINVAL;
if (!fmt)
return -EINVAL;
mutex_lock(&dev->input_lock);
fmt->width = dev->curr_res_table[dev->fmt_idx].width;
fmt->height = dev->curr_res_table[dev->fmt_idx].height;
fmt->code = MEDIA_BUS_FMT_SBGGR10_1X10;
mutex_unlock(&dev->input_lock);
return 0;
}
static int ov8858_detect(struct i2c_client *client, u16 *id)
{
struct i2c_adapter *adapter = client->adapter;
u16 id_hi = 0;
u16 id_low = 0;
int ret;
if (!i2c_check_functionality(adapter, I2C_FUNC_I2C))
return -ENODEV;
dev_dbg(&client->dev, "%s: I2C functionality ok\n", __func__);
ret = ov8858_read_reg(client, OV8858_8BIT, OV8858_CHIP_ID_HIGH, &id_hi);
if (ret)
return ret;
dev_dbg(&client->dev, "%s: id_high = 0x%04x\n", __func__, id_hi);
ret = ov8858_read_reg(client, OV8858_8BIT, OV8858_CHIP_ID_LOW, &id_low);
if (ret)
return ret;
dev_dbg(&client->dev, "%s: id_low = 0x%04x\n", __func__, id_low);
*id = (id_hi << 8) | id_low;
dev_dbg(&client->dev, "%s: chip_id = 0x%04x\n", __func__, *id);
dev_info(&client->dev, "%s: chip_id = 0x%04x\n", __func__, *id);
if (*id != OV8858_CHIP_ID)
return -ENODEV;
return ov8858_write_reg(client, OV8858_8BIT, OV8858_STREAM_MODE, 0);
}
static void __ov8858_print_timing(struct v4l2_subdev *sd)
{
struct ov8858_device *dev = to_ov8858_sensor(sd);
struct i2c_client *client = v4l2_get_subdevdata(sd);
u16 width = dev->curr_res_table[dev->fmt_idx].width;
u16 height = dev->curr_res_table[dev->fmt_idx].height;
dev_dbg(&client->dev, "Dump ov8858 timing in stream on:\n");
dev_dbg(&client->dev, "width: %d:\n", width);
dev_dbg(&client->dev, "height: %d:\n", height);
dev_dbg(&client->dev, "pixels_per_line: %d:\n", dev->pixels_per_line);
dev_dbg(&client->dev, "line per frame: %d:\n", dev->lines_per_frame);
dev_dbg(&client->dev, "pix freq: %d:\n", dev->vt_pix_clk_freq_mhz);
dev_dbg(&client->dev, "init fps: %d:\n", dev->vt_pix_clk_freq_mhz /
(dev->pixels_per_line / 2) / dev->lines_per_frame);
dev_dbg(&client->dev, "HBlank: %d nS:\n",
1000 * (dev->pixels_per_line - width) /
(dev->vt_pix_clk_freq_mhz / 1000000));
dev_dbg(&client->dev, "VBlank: %d uS:\n",
(dev->lines_per_frame - height) * dev->pixels_per_line /
(dev->vt_pix_clk_freq_mhz / 1000000));
}
static int ov8858_s_stream(struct v4l2_subdev *sd, int enable)
{
struct ov8858_device *dev = to_ov8858_sensor(sd);
struct i2c_client *client = v4l2_get_subdevdata(sd);
int ret;
u16 val;
dev_dbg(&client->dev, "%s: enable = %d\n", __func__, enable);
ret = ov8858_read_reg(client, OV8858_8BIT, OV8858_FORMAT2, &val);
if (ret)
return ret;
ret = ov8858_write_reg(client, OV8858_8BIT, OV8858_FORMAT2,
dev->hflip ? val | OV8858_FLIP_ENABLE :
val & ~OV8858_FLIP_ENABLE);
if (ret)
return ret;
ret = ov8858_read_reg(client, OV8858_8BIT, OV8858_FORMAT1, &val);
if (ret)
return ret;
ret = ov8858_write_reg(client, OV8858_8BIT, OV8858_FORMAT1,
dev->vflip ? val | OV8858_FLIP_ENABLE :
val & ~OV8858_FLIP_ENABLE);
if (ret)
return ret;
mutex_lock(&dev->input_lock);
if (enable) {
__ov8858_print_timing(sd);
ret = ov8858_write_reg_array(client, ov8858_streaming);
if (ret != 0) {
dev_err(&client->dev, "write_reg_array err\n");
goto out;
}
dev->streaming = 1;
} else {
ret = ov8858_write_reg_array(client, ov8858_soft_standby);
if (ret != 0) {
dev_err(&client->dev, "write_reg_array err\n");
goto out;
}
dev->streaming = 0;
dev->fps_index = 0;
dev->fps = 0;
}
out:
mutex_unlock(&dev->input_lock);
return ret;
}
static int __update_ov8858_device_settings(struct ov8858_device *dev,
u16 sensor_id)
{
if (sensor_id == OV8858_CHIP_ID)
#ifdef CONFIG_PLATFORM_BTNS
dev->vcm_driver = &ov8858_vcms[OV8858_ID_DEFAULT];
#else
dev->vcm_driver = &ov8858_vcms[OV8858_SUNNY];
#endif
else
return -ENODEV;
if (dev->vcm_driver && dev->vcm_driver->init)
return dev->vcm_driver->init(&dev->sd);
return 0;
}
static int ov8858_s_config(struct v4l2_subdev *sd,
int irq, void *pdata)
{
struct ov8858_device *dev = to_ov8858_sensor(sd);
struct i2c_client *client = v4l2_get_subdevdata(sd);
u16 sensor_id;
int ret;
if (pdata == NULL)
return -ENODEV;
dev->platform_data = pdata;
mutex_lock(&dev->input_lock);
if (dev->platform_data->platform_init) {
ret = dev->platform_data->platform_init(client);
if (ret) {
mutex_unlock(&dev->input_lock);
dev_err(&client->dev, "platform init error %d!\n", ret);
return ret;
}
}
ret = __ov8858_s_power(sd, 1);
if (ret) {
dev_err(&client->dev, "power-up error %d!\n", ret);
mutex_unlock(&dev->input_lock);
return ret;
}
ret = dev->platform_data->csi_cfg(sd, 1);
if (ret)
goto fail_csi_cfg;
ret = ov8858_detect(client, &sensor_id);
if (ret) {
dev_err(&client->dev, "detect error %d!\n", ret);
goto fail_detect;
}
dev->sensor_id = sensor_id;
ret = __ov8858_s_power(sd, 0);
if (ret) {
dev->platform_data->csi_cfg(sd, 0);
dev_err(&client->dev, "__ov8858_s_power-down error %d!\n", ret);
goto fail_update;
}
ret = __update_ov8858_device_settings(dev, dev->sensor_id);
if (ret) {
dev->platform_data->csi_cfg(sd, 0);
dev_err(&client->dev, "__update_ov8858_device_settings error %d!\n", ret);
goto fail_update;
}
mutex_unlock(&dev->input_lock);
return ret;
fail_detect:
dev->platform_data->csi_cfg(sd, 0);
fail_csi_cfg:
__ov8858_s_power(sd, 0);
fail_update:
if (dev->platform_data->platform_deinit)
dev->platform_data->platform_deinit();
mutex_unlock(&dev->input_lock);
dev_err(&client->dev, "sensor power-gating failed\n");
return ret;
}
static int
ov8858_enum_mbus_code(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_mbus_code_enum *code)
{
if (code->index)
return -EINVAL;
code->code = MEDIA_BUS_FMT_SBGGR10_1X10;
return 0;
}
static int
ov8858_enum_frame_size(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_frame_size_enum *fse)
{
int index = fse->index;
struct ov8858_device *dev = to_ov8858_sensor(sd);
mutex_lock(&dev->input_lock);
if (index >= dev->entries_curr_table) {
mutex_unlock(&dev->input_lock);
return -EINVAL;
}
fse->min_width = dev->curr_res_table[index].width;
fse->min_height = dev->curr_res_table[index].height;
fse->max_width = dev->curr_res_table[index].width;
fse->max_height = dev->curr_res_table[index].height;
mutex_unlock(&dev->input_lock);
return 0;
}
static int ov8858_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct ov8858_device *dev = container_of(
ctrl->handler, struct ov8858_device, ctrl_handler);
struct i2c_client *client = v4l2_get_subdevdata(&dev->sd);
switch (ctrl->id) {
case V4L2_CID_RUN_MODE:
switch (ctrl->val) {
case ATOMISP_RUN_MODE_VIDEO:
dev->curr_res_table = ov8858_res_video;
dev->entries_curr_table = ARRAY_SIZE(ov8858_res_video);
break;
case ATOMISP_RUN_MODE_STILL_CAPTURE:
dev->curr_res_table = ov8858_res_still;
dev->entries_curr_table = ARRAY_SIZE(ov8858_res_still);
break;
default:
dev->curr_res_table = ov8858_res_preview;
dev->entries_curr_table =
ARRAY_SIZE(ov8858_res_preview);
}
dev->fmt_idx = 0;
dev->fps_index = 0;
return 0;
case V4L2_CID_FOCUS_ABSOLUTE:
if (dev->vcm_driver && dev->vcm_driver->t_focus_abs)
return dev->vcm_driver->t_focus_abs(&dev->sd,
ctrl->val);
return 0;
case V4L2_CID_EXPOSURE_AUTO_PRIORITY:
if (ctrl->val == V4L2_EXPOSURE_AUTO)
dev->limit_exposure_flag = false;
else if (ctrl->val == V4L2_EXPOSURE_APERTURE_PRIORITY)
dev->limit_exposure_flag = true;
return 0;
case V4L2_CID_HFLIP:
dev->hflip = ctrl->val;
return 0;
case V4L2_CID_VFLIP:
dev->vflip = ctrl->val;
return 0;
default:
dev_err(&client->dev, "%s: Error: Invalid ctrl: 0x%X\n",
__func__, ctrl->id);
return -EINVAL;
}
}
static int ov8858_g_ctrl(struct v4l2_ctrl *ctrl)
{
struct ov8858_device *dev = container_of(
ctrl->handler, struct ov8858_device, ctrl_handler);
struct i2c_client *client = v4l2_get_subdevdata(&dev->sd);
int r_odd, r_even;
int i = dev->fmt_idx;
switch (ctrl->id) {
case V4L2_CID_FOCUS_STATUS:
if (dev->vcm_driver && dev->vcm_driver->q_focus_status)
return dev->vcm_driver->q_focus_status(&dev->sd,
&(ctrl->val));
return 0;
case V4L2_CID_BIN_FACTOR_HORZ:
r_odd = ov8858_get_register_8bit(&dev->sd, OV8858_H_INC_ODD,
dev->curr_res_table[i].regs);
if (r_odd < 0)
return r_odd;
r_even = ov8858_get_register_8bit(&dev->sd, OV8858_H_INC_EVEN,
dev->curr_res_table[i].regs);
if (r_even < 0)
return r_even;
ctrl->val = fls(r_odd + (r_even)) - 2;
return 0;
case V4L2_CID_BIN_FACTOR_VERT:
r_odd = ov8858_get_register_8bit(&dev->sd, OV8858_V_INC_ODD,
dev->curr_res_table[i].regs);
if (r_odd < 0)
return r_odd;
r_even = ov8858_get_register_8bit(&dev->sd, OV8858_V_INC_EVEN,
dev->curr_res_table[i].regs);
if (r_even < 0)
return r_even;
ctrl->val = fls(r_odd + (r_even)) - 2;
return 0;
case V4L2_CID_HFLIP:
ctrl->val = dev->hflip;
break;
case V4L2_CID_VFLIP:
ctrl->val = dev->vflip;
break;
case V4L2_CID_EXPOSURE_ABSOLUTE:
ctrl->val = dev->exposure;
break;
default:
dev_warn(&client->dev,
"%s: Error: Invalid ctrl: 0x%X\n", __func__, ctrl->id);
return -EINVAL;
}
return 0;
}
static int
ov8858_g_frame_interval(struct v4l2_subdev *sd,
struct v4l2_subdev_frame_interval *interval)
{
struct ov8858_device *dev = to_ov8858_sensor(sd);
const struct ov8858_resolution *res =
&dev->curr_res_table[dev->fmt_idx];
mutex_lock(&dev->input_lock);
interval->interval.denominator = res->fps_options[dev->fps_index].fps;
interval->interval.numerator = 1;
mutex_unlock(&dev->input_lock);
return 0;
}
static int __ov8858_s_frame_interval(struct v4l2_subdev *sd,
struct v4l2_subdev_frame_interval *interval)
{
struct ov8858_device *dev = to_ov8858_sensor(sd);
struct i2c_client *client = v4l2_get_subdevdata(sd);
const struct ov8858_resolution *res =
&dev->curr_res_table[dev->fmt_idx];
struct camera_mipi_info *info = NULL;
unsigned int fps_index;
int ret = 0;
int fps;
info = v4l2_get_subdev_hostdata(sd);
if (info == NULL)
return -EINVAL;
if (!interval->interval.numerator)
interval->interval.numerator = 1;
fps = interval->interval.denominator / interval->interval.numerator;
if (!dev->streaming) {
dev->fps = fps;
return 0;
}
if (fps == res->fps_options[dev->fps_index].fps)
return 0;
fps_index = __ov8858_nearest_fps_index(fps, res->fps_options);
if (res->fps_options[fps_index].regs &&
res->fps_options[fps_index].regs != dev->regs) {
dev_err(&client->dev,
"Sensor is streaming, can't apply new configuration\n");
return -EBUSY;
}
dev->fps_index = fps_index;
dev->fps = res->fps_options[dev->fps_index].fps;
dev->pixels_per_line =
res->fps_options[dev->fps_index].pixels_per_line;
dev->lines_per_frame =
res->fps_options[dev->fps_index].lines_per_frame;
ret = __ov8858_update_frame_timing(sd,
&dev->pixels_per_line, &dev->lines_per_frame);
if (ret)
return ret;
ret = ov8858_get_intg_factor(sd, info, dev->regs);
if (ret)
return ret;
interval->interval.denominator = res->fps_options[dev->fps_index].fps;
interval->interval.numerator = 1;
__ov8858_print_timing(sd);
return ret;
}
static int ov8858_s_frame_interval(struct v4l2_subdev *sd,
struct v4l2_subdev_frame_interval *interval)
{
struct ov8858_device *dev = to_ov8858_sensor(sd);
int ret;
mutex_lock(&dev->input_lock);
ret = __ov8858_s_frame_interval(sd, interval);
mutex_unlock(&dev->input_lock);
return ret;
}
static int ov8858_g_skip_frames(struct v4l2_subdev *sd, u32 *frames)
{
struct ov8858_device *dev = to_ov8858_sensor(sd);
mutex_lock(&dev->input_lock);
*frames = dev->curr_res_table[dev->fmt_idx].skip_frames;
mutex_unlock(&dev->input_lock);
return 0;
}
static int ov8858_remove(struct i2c_client *client)
{
struct v4l2_subdev *sd = i2c_get_clientdata(client);
struct ov8858_device *dev = to_ov8858_sensor(sd);
if (dev->platform_data->platform_deinit)
dev->platform_data->platform_deinit();
media_entity_cleanup(&dev->sd.entity);
v4l2_ctrl_handler_free(&dev->ctrl_handler);
dev->platform_data->csi_cfg(sd, 0);
v4l2_device_unregister_subdev(sd);
kfree(dev);
return 0;
}
static int ov8858_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct ov8858_device *dev;
unsigned int i;
int ret = 0;
struct camera_sensor_platform_data *pdata;
dev_dbg(&client->dev, "%s:\n", __func__);
dev = kzalloc(sizeof(*dev), GFP_KERNEL);
if (!dev) {
dev_err(&client->dev, "%s: out of memory\n", __func__);
return -ENOMEM;
}
mutex_init(&dev->input_lock);
if (id)
dev->i2c_id = id->driver_data;
dev->fmt_idx = 0;
dev->sensor_id = OV_ID_DEFAULT;
dev->vcm_driver = &ov8858_vcms[OV8858_ID_DEFAULT];
v4l2_i2c_subdev_init(&(dev->sd), client, &ov8858_ops);
if (ACPI_COMPANION(&client->dev)) {
pdata = gmin_camera_platform_data(&dev->sd,
ATOMISP_INPUT_FORMAT_RAW_10,
atomisp_bayer_order_bggr);
if (!pdata) {
dev_err(&client->dev,
"%s: failed to get acpi platform data\n",
__func__);
goto out_free;
}
ret = ov8858_s_config(&dev->sd, client->irq, pdata);
if (ret) {
dev_err(&client->dev,
"%s: failed to set config\n", __func__);
goto out_free;
}
ret = atomisp_register_i2c_module(&dev->sd, pdata, RAW_CAMERA);
if (ret) {
dev_err(&client->dev,
"%s: failed to register subdev\n", __func__);
goto out_free;
}
}
snprintf(dev->sd.name, sizeof(dev->sd.name), "%s%x %d-%04x",
OV_SUBDEV_PREFIX, dev->sensor_id,
i2c_adapter_id(client->adapter), client->addr);
dev->sd.flags |= V4L2_SUBDEV_FL_HAS_DEVNODE;
dev->pad.flags = MEDIA_PAD_FL_SOURCE;
dev->format.code = MEDIA_BUS_FMT_SBGGR10_1X10;
dev->sd.entity.ops = &ov_entity_ops;
dev->sd.entity.function = MEDIA_ENT_F_CAM_SENSOR;
ret = v4l2_ctrl_handler_init(&dev->ctrl_handler, ARRAY_SIZE(ctrls) + 1);
if (ret) {
ov8858_remove(client);
return ret;
}
dev->run_mode = v4l2_ctrl_new_custom(&dev->ctrl_handler,
&ctrl_run_mode, NULL);
for (i = 0; i < ARRAY_SIZE(ctrls); i++)
v4l2_ctrl_new_custom(&dev->ctrl_handler, &ctrls[i], NULL);
if (dev->ctrl_handler.error) {
ov8858_remove(client);
return dev->ctrl_handler.error;
}
dev->ctrl_handler.lock = &dev->input_lock;
dev->sd.ctrl_handler = &dev->ctrl_handler;
v4l2_ctrl_handler_setup(&dev->ctrl_handler);
ret = media_entity_pads_init(&dev->sd.entity, 1, &dev->pad);
if (ret) {
ov8858_remove(client);
return ret;
}
return 0;
out_free:
v4l2_device_unregister_subdev(&dev->sd);
kfree(dev);
return ret;
}
static __init int ov8858_init_mod(void)
{
return i2c_add_driver(&ov8858_driver);
}
static __exit void ov8858_exit_mod(void)
{
i2c_del_driver(&ov8858_driver);
}
