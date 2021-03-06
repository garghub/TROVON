static int gc0310_read_reg(struct i2c_client *client,
u16 data_length, u8 reg, u8 *val)
{
int err;
struct i2c_msg msg[2];
unsigned char data[1];
if (!client->adapter) {
dev_err(&client->dev, "%s error, no client->adapter\n",
__func__);
return -ENODEV;
}
if (data_length != GC0310_8BIT) {
dev_err(&client->dev, "%s error, invalid data length\n",
__func__);
return -EINVAL;
}
memset(msg, 0, sizeof(msg));
msg[0].addr = client->addr;
msg[0].flags = 0;
msg[0].len = I2C_MSG_LENGTH;
msg[0].buf = data;
data[0] = (u8)(reg & 0xff);
msg[1].addr = client->addr;
msg[1].len = data_length;
msg[1].flags = I2C_M_RD;
msg[1].buf = data;
err = i2c_transfer(client->adapter, msg, 2);
if (err != 2) {
if (err >= 0)
err = -EIO;
dev_err(&client->dev,
"read from offset 0x%x error %d", reg, err);
return err;
}
*val = 0;
if (data_length == GC0310_8BIT)
*val = (u8)data[0];
return 0;
}
static int gc0310_i2c_write(struct i2c_client *client, u16 len, u8 *data)
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
static int gc0310_write_reg(struct i2c_client *client, u16 data_length,
u8 reg, u8 val)
{
int ret;
unsigned char data[2] = {0};
u8 *wreg = (u8 *)data;
const u16 len = data_length + sizeof(u8);
if (data_length != GC0310_8BIT) {
dev_err(&client->dev,
"%s error, invalid data_length\n", __func__);
return -EINVAL;
}
*wreg = (u8)(reg & 0xff);
if (data_length == GC0310_8BIT)
data[1] = (u8)(val);
ret = gc0310_i2c_write(client, len, data);
if (ret)
dev_err(&client->dev,
"write error: wrote 0x%x to offset 0x%x error %d",
val, reg, ret);
return ret;
}
static int __gc0310_flush_reg_array(struct i2c_client *client,
struct gc0310_write_ctrl *ctrl)
{
u16 size;
if (ctrl->index == 0)
return 0;
size = sizeof(u8) + ctrl->index;
ctrl->buffer.addr = (u8)(ctrl->buffer.addr);
ctrl->index = 0;
return gc0310_i2c_write(client, size, (u8 *)&ctrl->buffer);
}
static int __gc0310_buf_reg_array(struct i2c_client *client,
struct gc0310_write_ctrl *ctrl,
const struct gc0310_reg *next)
{
int size;
switch (next->type) {
case GC0310_8BIT:
size = 1;
ctrl->buffer.data[ctrl->index] = (u8)next->val;
break;
default:
return -EINVAL;
}
if (ctrl->index == 0)
ctrl->buffer.addr = next->reg;
ctrl->index += size;
if (ctrl->index + sizeof(u8) >= GC0310_MAX_WRITE_BUF_SIZE)
return __gc0310_flush_reg_array(client, ctrl);
return 0;
}
static int __gc0310_write_reg_is_consecutive(struct i2c_client *client,
struct gc0310_write_ctrl *ctrl,
const struct gc0310_reg *next)
{
if (ctrl->index == 0)
return 1;
return ctrl->buffer.addr + ctrl->index == next->reg;
}
static int gc0310_write_reg_array(struct i2c_client *client,
const struct gc0310_reg *reglist)
{
const struct gc0310_reg *next = reglist;
struct gc0310_write_ctrl ctrl;
int err;
ctrl.index = 0;
for (; next->type != GC0310_TOK_TERM; next++) {
switch (next->type & GC0310_TOK_MASK) {
case GC0310_TOK_DELAY:
err = __gc0310_flush_reg_array(client, &ctrl);
if (err)
return err;
msleep(next->val);
break;
default:
if (!__gc0310_write_reg_is_consecutive(client, &ctrl,
next)) {
err = __gc0310_flush_reg_array(client, &ctrl);
if (err)
return err;
}
err = __gc0310_buf_reg_array(client, &ctrl, next);
if (err) {
dev_err(&client->dev, "%s: write error, aborted\n",
__func__);
return err;
}
break;
}
}
return __gc0310_flush_reg_array(client, &ctrl);
}
static int gc0310_g_focal(struct v4l2_subdev *sd, s32 *val)
{
*val = (GC0310_FOCAL_LENGTH_NUM << 16) | GC0310_FOCAL_LENGTH_DEM;
return 0;
}
static int gc0310_g_fnumber(struct v4l2_subdev *sd, s32 *val)
{
*val = (GC0310_F_NUMBER_DEFAULT_NUM << 16) | GC0310_F_NUMBER_DEM;
return 0;
}
static int gc0310_g_fnumber_range(struct v4l2_subdev *sd, s32 *val)
{
*val = (GC0310_F_NUMBER_DEFAULT_NUM << 24) |
(GC0310_F_NUMBER_DEM << 16) |
(GC0310_F_NUMBER_DEFAULT_NUM << 8) | GC0310_F_NUMBER_DEM;
return 0;
}
static int gc0310_g_bin_factor_x(struct v4l2_subdev *sd, s32 *val)
{
struct gc0310_device *dev = to_gc0310_sensor(sd);
*val = gc0310_res[dev->fmt_idx].bin_factor_x;
return 0;
}
static int gc0310_g_bin_factor_y(struct v4l2_subdev *sd, s32 *val)
{
struct gc0310_device *dev = to_gc0310_sensor(sd);
*val = gc0310_res[dev->fmt_idx].bin_factor_y;
return 0;
}
static int gc0310_get_intg_factor(struct i2c_client *client,
struct camera_mipi_info *info,
const struct gc0310_resolution *res)
{
struct v4l2_subdev *sd = i2c_get_clientdata(client);
struct gc0310_device *dev = to_gc0310_sensor(sd);
struct atomisp_sensor_mode_data *buf = &info->data;
u16 val;
u8 reg_val;
int ret;
unsigned int hori_blanking;
unsigned int vert_blanking;
unsigned int sh_delay;
if (!info)
return -EINVAL;
dev->vt_pix_clk_freq_mhz = 14400000;
buf->vt_pix_clk_freq_mhz = dev->vt_pix_clk_freq_mhz;
pr_info("vt_pix_clk_freq_mhz=%d\n", buf->vt_pix_clk_freq_mhz);
buf->coarse_integration_time_min = GC0310_COARSE_INTG_TIME_MIN;
buf->coarse_integration_time_max_margin =
GC0310_COARSE_INTG_TIME_MAX_MARGIN;
buf->fine_integration_time_min = GC0310_FINE_INTG_TIME_MIN;
buf->fine_integration_time_max_margin =
GC0310_FINE_INTG_TIME_MAX_MARGIN;
buf->fine_integration_time_def = GC0310_FINE_INTG_TIME_MIN;
buf->read_mode = res->bin_mode;
ret = gc0310_read_reg(client, GC0310_8BIT,
GC0310_H_CROP_START_H, &reg_val);
if (ret)
return ret;
val = (reg_val & 0xFF) << 8;
ret = gc0310_read_reg(client, GC0310_8BIT,
GC0310_H_CROP_START_L, &reg_val);
if (ret)
return ret;
buf->crop_horizontal_start = val | (reg_val & 0xFF);
pr_info("crop_horizontal_start=%d\n", buf->crop_horizontal_start);
ret = gc0310_read_reg(client, GC0310_8BIT,
GC0310_V_CROP_START_H, &reg_val);
if (ret)
return ret;
val = (reg_val & 0xFF) << 8;
ret = gc0310_read_reg(client, GC0310_8BIT,
GC0310_V_CROP_START_L, &reg_val);
if (ret)
return ret;
buf->crop_vertical_start = val | (reg_val & 0xFF);
pr_info("crop_vertical_start=%d\n", buf->crop_vertical_start);
ret = gc0310_read_reg(client, GC0310_8BIT,
GC0310_H_OUTSIZE_H, &reg_val);
if (ret)
return ret;
val = (reg_val & 0xFF) << 8;
ret = gc0310_read_reg(client, GC0310_8BIT,
GC0310_H_OUTSIZE_L, &reg_val);
if (ret)
return ret;
buf->output_width = val | (reg_val & 0xFF);
pr_info("output_width=%d\n", buf->output_width);
ret = gc0310_read_reg(client, GC0310_8BIT,
GC0310_V_OUTSIZE_H, &reg_val);
if (ret)
return ret;
val = (reg_val & 0xFF) << 8;
ret = gc0310_read_reg(client, GC0310_8BIT,
GC0310_V_OUTSIZE_L, &reg_val);
if (ret)
return ret;
buf->output_height = val | (reg_val & 0xFF);
pr_info("output_height=%d\n", buf->output_height);
buf->crop_horizontal_end = buf->crop_horizontal_start + buf->output_width - 1;
buf->crop_vertical_end = buf->crop_vertical_start + buf->output_height - 1;
pr_info("crop_horizontal_end=%d\n", buf->crop_horizontal_end);
pr_info("crop_vertical_end=%d\n", buf->crop_vertical_end);
ret = gc0310_read_reg(client, GC0310_8BIT,
GC0310_H_BLANKING_H, &reg_val);
if (ret)
return ret;
val = (reg_val & 0xFF) << 8;
ret = gc0310_read_reg(client, GC0310_8BIT,
GC0310_H_BLANKING_L, &reg_val);
if (ret)
return ret;
hori_blanking = val | (reg_val & 0xFF);
ret = gc0310_read_reg(client, GC0310_8BIT,
GC0310_SH_DELAY, &reg_val);
if (ret)
return ret;
sh_delay = reg_val;
buf->line_length_pck = buf->output_width + hori_blanking + sh_delay + 4;
pr_info("hori_blanking=%d sh_delay=%d line_length_pck=%d\n", hori_blanking, sh_delay, buf->line_length_pck);
ret = gc0310_read_reg(client, GC0310_8BIT,
GC0310_V_BLANKING_H, &reg_val);
if (ret)
return ret;
val = (reg_val & 0xFF) << 8;
ret = gc0310_read_reg(client, GC0310_8BIT,
GC0310_V_BLANKING_L, &reg_val);
if (ret)
return ret;
vert_blanking = val | (reg_val & 0xFF);
buf->frame_length_lines = buf->output_height + vert_blanking;
pr_info("vert_blanking=%d frame_length_lines=%d\n", vert_blanking, buf->frame_length_lines);
buf->binning_factor_x = res->bin_factor_x ?
res->bin_factor_x : 1;
buf->binning_factor_y = res->bin_factor_y ?
res->bin_factor_y : 1;
return 0;
}
static int gc0310_set_gain(struct v4l2_subdev *sd, int gain)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
int ret;
u8 again, dgain;
if (gain < 0x20)
gain = 0x20;
if (gain > 0x80)
gain = 0x80;
if (gain >= 0x20 && gain < 0x40) {
again = 0x0;
dgain = gain;
} else {
again = 0x2;
dgain = gain / 2;
}
pr_info("gain=0x%x again=0x%x dgain=0x%x\n", gain, again, dgain);
ret = gc0310_write_reg(client, GC0310_8BIT,
GC0310_AGC_ADJ, again);
if (ret)
return ret;
ret = gc0310_write_reg(client, GC0310_8BIT,
GC0310_DGC_ADJ, dgain);
if (ret)
return ret;
return 0;
}
static int __gc0310_set_exposure(struct v4l2_subdev *sd, int coarse_itg,
int gain, int digitgain)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
int ret;
pr_info("coarse_itg=%d gain=%d digitgain=%d\n", coarse_itg, gain, digitgain);
ret = gc0310_write_reg(client, GC0310_8BIT,
GC0310_AEC_PK_EXPO_L,
coarse_itg & 0xff);
if (ret)
return ret;
ret = gc0310_write_reg(client, GC0310_8BIT,
GC0310_AEC_PK_EXPO_H,
(coarse_itg >> 8) & 0x0f);
if (ret)
return ret;
ret = gc0310_set_gain(sd, gain);
if (ret)
return ret;
return ret;
}
static int gc0310_set_exposure(struct v4l2_subdev *sd, int exposure,
int gain, int digitgain)
{
struct gc0310_device *dev = to_gc0310_sensor(sd);
int ret;
mutex_lock(&dev->input_lock);
ret = __gc0310_set_exposure(sd, exposure, gain, digitgain);
mutex_unlock(&dev->input_lock);
return ret;
}
static long gc0310_s_exposure(struct v4l2_subdev *sd,
struct atomisp_exposure *exposure)
{
int exp = exposure->integration_time[0];
int gain = exposure->gain[0];
int digitgain = exposure->gain[1];
if (gain == 0) {
struct i2c_client *client = v4l2_get_subdevdata(sd);
v4l2_err(client, "%s: invalid value\n", __func__);
return -EINVAL;
}
return gc0310_set_exposure(sd, exp, gain, digitgain);
}
static int gc0310_v_flip(struct v4l2_subdev *sd, s32 value)
{
return 0;
}
static int gc0310_h_flip(struct v4l2_subdev *sd, s32 value)
{
return 0;
}
static long gc0310_ioctl(struct v4l2_subdev *sd, unsigned int cmd, void *arg)
{
switch (cmd) {
case ATOMISP_IOC_S_EXPOSURE:
return gc0310_s_exposure(sd, arg);
default:
return -EINVAL;
}
return 0;
}
static int gc0310_q_exposure(struct v4l2_subdev *sd, s32 *value)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
u8 reg_v;
int ret;
ret = gc0310_read_reg(client, GC0310_8BIT,
GC0310_AEC_PK_EXPO_L,
&reg_v);
if (ret)
goto err;
*value = reg_v;
ret = gc0310_read_reg(client, GC0310_8BIT,
GC0310_AEC_PK_EXPO_H,
&reg_v);
if (ret)
goto err;
*value = *value + (reg_v << 8);
err:
return ret;
}
static int gc0310_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct gc0310_device *dev =
container_of(ctrl->handler, struct gc0310_device, ctrl_handler);
struct i2c_client *client = v4l2_get_subdevdata(&dev->sd);
int ret = 0;
switch (ctrl->id) {
case V4L2_CID_VFLIP:
dev_dbg(&client->dev, "%s: CID_VFLIP:%d.\n",
__func__, ctrl->val);
ret = gc0310_v_flip(&dev->sd, ctrl->val);
break;
case V4L2_CID_HFLIP:
dev_dbg(&client->dev, "%s: CID_HFLIP:%d.\n",
__func__, ctrl->val);
ret = gc0310_h_flip(&dev->sd, ctrl->val);
break;
default:
ret = -EINVAL;
}
return ret;
}
static int gc0310_g_volatile_ctrl(struct v4l2_ctrl *ctrl)
{
struct gc0310_device *dev =
container_of(ctrl->handler, struct gc0310_device, ctrl_handler);
int ret = 0;
switch (ctrl->id) {
case V4L2_CID_EXPOSURE_ABSOLUTE:
ret = gc0310_q_exposure(&dev->sd, &ctrl->val);
break;
case V4L2_CID_FOCAL_ABSOLUTE:
ret = gc0310_g_focal(&dev->sd, &ctrl->val);
break;
case V4L2_CID_FNUMBER_ABSOLUTE:
ret = gc0310_g_fnumber(&dev->sd, &ctrl->val);
break;
case V4L2_CID_FNUMBER_RANGE:
ret = gc0310_g_fnumber_range(&dev->sd, &ctrl->val);
break;
case V4L2_CID_BIN_FACTOR_HORZ:
ret = gc0310_g_bin_factor_x(&dev->sd, &ctrl->val);
break;
case V4L2_CID_BIN_FACTOR_VERT:
ret = gc0310_g_bin_factor_y(&dev->sd, &ctrl->val);
break;
default:
ret = -EINVAL;
}
return ret;
}
static int gc0310_init(struct v4l2_subdev *sd)
{
int ret;
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct gc0310_device *dev = to_gc0310_sensor(sd);
pr_info("%s S\n", __func__);
mutex_lock(&dev->input_lock);
ret = gc0310_write_reg_array(client, gc0310_reset_register);
gc0310_res = gc0310_res_preview;
N_RES = N_RES_PREVIEW;
mutex_unlock(&dev->input_lock);
pr_info("%s E\n", __func__);
return 0;
}
static int power_ctrl(struct v4l2_subdev *sd, bool flag)
{
int ret = 0;
struct gc0310_device *dev = to_gc0310_sensor(sd);
if (!dev || !dev->platform_data)
return -ENODEV;
if (dev->platform_data->power_ctrl)
return dev->platform_data->power_ctrl(sd, flag);
if (flag) {
ret |= dev->platform_data->v1p8_ctrl(sd, 1);
ret |= dev->platform_data->v2p8_ctrl(sd, 1);
usleep_range(10000, 15000);
}
if (!flag || ret) {
ret |= dev->platform_data->v1p8_ctrl(sd, 0);
ret |= dev->platform_data->v2p8_ctrl(sd, 0);
}
return ret;
}
static int gpio_ctrl(struct v4l2_subdev *sd, bool flag)
{
int ret;
struct gc0310_device *dev = to_gc0310_sensor(sd);
if (!dev || !dev->platform_data)
return -ENODEV;
if (dev->platform_data->gpio_ctrl)
return dev->platform_data->gpio_ctrl(sd, flag);
if (flag) {
ret = dev->platform_data->gpio0_ctrl(sd, 0);
usleep_range(5000, 10000);
ret |= dev->platform_data->gpio0_ctrl(sd, 1);
usleep_range(10000, 15000);
ret |= dev->platform_data->gpio1_ctrl(sd, 0);
usleep_range(10000, 15000);
} else {
ret = dev->platform_data->gpio1_ctrl(sd, 1);
ret |= dev->platform_data->gpio0_ctrl(sd, 0);
}
return ret;
}
static int power_up(struct v4l2_subdev *sd)
{
struct gc0310_device *dev = to_gc0310_sensor(sd);
struct i2c_client *client = v4l2_get_subdevdata(sd);
int ret;
pr_info("%s S\n", __func__);
if (!dev->platform_data) {
dev_err(&client->dev,
"no camera_sensor_platform_data");
return -ENODEV;
}
ret = power_ctrl(sd, 1);
if (ret)
goto fail_power;
ret = dev->platform_data->flisclk_ctrl(sd, 1);
if (ret)
goto fail_clk;
ret = gpio_ctrl(sd, 1);
if (ret) {
ret = gpio_ctrl(sd, 1);
if (ret)
goto fail_gpio;
}
msleep(100);
pr_info("%s E\n", __func__);
return 0;
fail_gpio:
dev->platform_data->flisclk_ctrl(sd, 0);
fail_clk:
power_ctrl(sd, 0);
fail_power:
dev_err(&client->dev, "sensor power-up failed\n");
return ret;
}
static int power_down(struct v4l2_subdev *sd)
{
struct gc0310_device *dev = to_gc0310_sensor(sd);
struct i2c_client *client = v4l2_get_subdevdata(sd);
int ret = 0;
if (!dev->platform_data) {
dev_err(&client->dev,
"no camera_sensor_platform_data");
return -ENODEV;
}
ret = gpio_ctrl(sd, 0);
if (ret) {
ret = gpio_ctrl(sd, 0);
if (ret)
dev_err(&client->dev, "gpio failed 2\n");
}
ret = dev->platform_data->flisclk_ctrl(sd, 0);
if (ret)
dev_err(&client->dev, "flisclk failed\n");
ret = power_ctrl(sd, 0);
if (ret)
dev_err(&client->dev, "vprog failed.\n");
return ret;
}
static int gc0310_s_power(struct v4l2_subdev *sd, int on)
{
int ret;
if (on == 0)
return power_down(sd);
else {
ret = power_up(sd);
if (!ret)
return gc0310_init(sd);
}
return ret;
}
static int distance(struct gc0310_resolution *res, u32 w, u32 h)
{
unsigned int w_ratio = (res->width << 13) / w;
unsigned int h_ratio;
int match;
if (h == 0)
return -1;
h_ratio = (res->height << 13) / h;
if (h_ratio == 0)
return -1;
match = abs(((w_ratio << 13) / h_ratio) - ((int)8192));
if ((w_ratio < (int)8192) || (h_ratio < (int)8192) ||
(match > LARGEST_ALLOWED_RATIO_MISMATCH))
return -1;
return w_ratio + h_ratio;
}
static int nearest_resolution_index(int w, int h)
{
int i;
int idx = -1;
int dist;
int min_dist = INT_MAX;
struct gc0310_resolution *tmp_res = NULL;
for (i = 0; i < N_RES; i++) {
tmp_res = &gc0310_res[i];
dist = distance(tmp_res, w, h);
if (dist == -1)
continue;
if (dist < min_dist) {
min_dist = dist;
idx = i;
}
}
return idx;
}
static int get_resolution_index(int w, int h)
{
int i;
for (i = 0; i < N_RES; i++) {
if (w != gc0310_res[i].width)
continue;
if (h != gc0310_res[i].height)
continue;
return i;
}
return -1;
}
static int startup(struct v4l2_subdev *sd)
{
struct gc0310_device *dev = to_gc0310_sensor(sd);
struct i2c_client *client = v4l2_get_subdevdata(sd);
int ret = 0;
pr_info("%s S\n", __func__);
ret = gc0310_write_reg_array(client, gc0310_res[dev->fmt_idx].regs);
if (ret) {
dev_err(&client->dev, "gc0310 write register err.\n");
return ret;
}
pr_info("%s E\n", __func__);
return ret;
}
static int gc0310_set_fmt(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_format *format)
{
struct v4l2_mbus_framefmt *fmt = &format->format;
struct gc0310_device *dev = to_gc0310_sensor(sd);
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct camera_mipi_info *gc0310_info = NULL;
int ret = 0;
int idx = 0;
pr_info("%s S\n", __func__);
if (format->pad)
return -EINVAL;
if (!fmt)
return -EINVAL;
gc0310_info = v4l2_get_subdev_hostdata(sd);
if (!gc0310_info)
return -EINVAL;
mutex_lock(&dev->input_lock);
idx = nearest_resolution_index(fmt->width, fmt->height);
if (idx == -1) {
fmt->width = gc0310_res[N_RES - 1].width;
fmt->height = gc0310_res[N_RES - 1].height;
} else {
fmt->width = gc0310_res[idx].width;
fmt->height = gc0310_res[idx].height;
}
fmt->code = MEDIA_BUS_FMT_SGRBG8_1X8;
if (format->which == V4L2_SUBDEV_FORMAT_TRY) {
cfg->try_fmt = *fmt;
mutex_unlock(&dev->input_lock);
return 0;
}
dev->fmt_idx = get_resolution_index(fmt->width, fmt->height);
if (dev->fmt_idx == -1) {
dev_err(&client->dev, "get resolution fail\n");
mutex_unlock(&dev->input_lock);
return -EINVAL;
}
printk("%s: before gc0310_write_reg_array %s\n", __FUNCTION__,
gc0310_res[dev->fmt_idx].desc);
ret = startup(sd);
if (ret) {
dev_err(&client->dev, "gc0310 startup err\n");
goto err;
}
ret = gc0310_get_intg_factor(client, gc0310_info,
&gc0310_res[dev->fmt_idx]);
if (ret) {
dev_err(&client->dev, "failed to get integration_factor\n");
goto err;
}
pr_info("%s E\n", __func__);
err:
mutex_unlock(&dev->input_lock);
return ret;
}
static int gc0310_get_fmt(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_format *format)
{
struct v4l2_mbus_framefmt *fmt = &format->format;
struct gc0310_device *dev = to_gc0310_sensor(sd);
if (format->pad)
return -EINVAL;
if (!fmt)
return -EINVAL;
fmt->width = gc0310_res[dev->fmt_idx].width;
fmt->height = gc0310_res[dev->fmt_idx].height;
fmt->code = MEDIA_BUS_FMT_SGRBG8_1X8;
return 0;
}
static int gc0310_detect(struct i2c_client *client)
{
struct i2c_adapter *adapter = client->adapter;
u8 high, low;
int ret;
u16 id;
pr_info("%s S\n", __func__);
if (!i2c_check_functionality(adapter, I2C_FUNC_I2C))
return -ENODEV;
ret = gc0310_read_reg(client, GC0310_8BIT,
GC0310_SC_CMMN_CHIP_ID_H, &high);
if (ret) {
dev_err(&client->dev, "read sensor_id_high failed\n");
return -ENODEV;
}
ret = gc0310_read_reg(client, GC0310_8BIT,
GC0310_SC_CMMN_CHIP_ID_L, &low);
if (ret) {
dev_err(&client->dev, "read sensor_id_low failed\n");
return -ENODEV;
}
id = ((((u16) high) << 8) | (u16) low);
pr_info("sensor ID = 0x%x\n", id);
if (id != GC0310_ID) {
dev_err(&client->dev, "sensor ID error, read id = 0x%x, target id = 0x%x\n", id, GC0310_ID);
return -ENODEV;
}
dev_dbg(&client->dev, "detect gc0310 success\n");
pr_info("%s E\n", __func__);
return 0;
}
static int gc0310_s_stream(struct v4l2_subdev *sd, int enable)
{
struct gc0310_device *dev = to_gc0310_sensor(sd);
struct i2c_client *client = v4l2_get_subdevdata(sd);
int ret;
pr_info("%s S enable=%d\n", __func__, enable);
mutex_lock(&dev->input_lock);
if (enable) {
ret = gc0310_write_reg(client, GC0310_8BIT,
0xFE, 0x30);
if (ret) {
mutex_unlock(&dev->input_lock);
return ret;
}
}
ret = gc0310_write_reg(client, GC0310_8BIT,
GC0310_RESET_RELATED, GC0310_REGISTER_PAGE_3);
if (ret) {
mutex_unlock(&dev->input_lock);
return ret;
}
ret = gc0310_write_reg(client, GC0310_8BIT, GC0310_SW_STREAM,
enable ? GC0310_START_STREAMING :
GC0310_STOP_STREAMING);
if (ret) {
mutex_unlock(&dev->input_lock);
return ret;
}
ret = gc0310_write_reg(client, GC0310_8BIT,
GC0310_RESET_RELATED, GC0310_REGISTER_PAGE_0);
if (ret) {
mutex_unlock(&dev->input_lock);
return ret;
}
mutex_unlock(&dev->input_lock);
pr_info("%s E\n", __func__);
return ret;
}
static int gc0310_s_config(struct v4l2_subdev *sd,
int irq, void *platform_data)
{
struct gc0310_device *dev = to_gc0310_sensor(sd);
struct i2c_client *client = v4l2_get_subdevdata(sd);
int ret = 0;
pr_info("%s S\n", __func__);
if (!platform_data)
return -ENODEV;
dev->platform_data =
(struct camera_sensor_platform_data *)platform_data;
mutex_lock(&dev->input_lock);
if (dev->platform_data->platform_init) {
ret = dev->platform_data->platform_init(client);
if (ret) {
dev_err(&client->dev, "platform init err\n");
goto platform_init_failed;
}
}
ret = power_down(sd);
if (ret) {
dev_err(&client->dev, "gc0310 power-off err.\n");
goto fail_power_off;
}
ret = power_up(sd);
if (ret) {
dev_err(&client->dev, "gc0310 power-up err.\n");
goto fail_power_on;
}
ret = dev->platform_data->csi_cfg(sd, 1);
if (ret)
goto fail_csi_cfg;
ret = gc0310_detect(client);
if (ret) {
dev_err(&client->dev, "gc0310_detect err s_config.\n");
goto fail_csi_cfg;
}
ret = power_down(sd);
if (ret) {
dev_err(&client->dev, "gc0310 power-off err.\n");
goto fail_csi_cfg;
}
mutex_unlock(&dev->input_lock);
pr_info("%s E\n", __func__);
return 0;
fail_csi_cfg:
dev->platform_data->csi_cfg(sd, 0);
fail_power_on:
power_down(sd);
dev_err(&client->dev, "sensor power-gating failed\n");
fail_power_off:
if (dev->platform_data->platform_deinit)
dev->platform_data->platform_deinit();
platform_init_failed:
mutex_unlock(&dev->input_lock);
return ret;
}
static int gc0310_g_parm(struct v4l2_subdev *sd,
struct v4l2_streamparm *param)
{
struct gc0310_device *dev = to_gc0310_sensor(sd);
struct i2c_client *client = v4l2_get_subdevdata(sd);
if (!param)
return -EINVAL;
if (param->type != V4L2_BUF_TYPE_VIDEO_CAPTURE) {
dev_err(&client->dev, "unsupported buffer type.\n");
return -EINVAL;
}
memset(param, 0, sizeof(*param));
param->type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
if (dev->fmt_idx >= 0 && dev->fmt_idx < N_RES) {
param->parm.capture.capability = V4L2_CAP_TIMEPERFRAME;
param->parm.capture.timeperframe.numerator = 1;
param->parm.capture.capturemode = dev->run_mode;
param->parm.capture.timeperframe.denominator =
gc0310_res[dev->fmt_idx].fps;
}
return 0;
}
static int gc0310_s_parm(struct v4l2_subdev *sd,
struct v4l2_streamparm *param)
{
struct gc0310_device *dev = to_gc0310_sensor(sd);
dev->run_mode = param->parm.capture.capturemode;
mutex_lock(&dev->input_lock);
switch (dev->run_mode) {
case CI_MODE_VIDEO:
gc0310_res = gc0310_res_video;
N_RES = N_RES_VIDEO;
break;
case CI_MODE_STILL_CAPTURE:
gc0310_res = gc0310_res_still;
N_RES = N_RES_STILL;
break;
default:
gc0310_res = gc0310_res_preview;
N_RES = N_RES_PREVIEW;
}
mutex_unlock(&dev->input_lock);
return 0;
}
static int gc0310_g_frame_interval(struct v4l2_subdev *sd,
struct v4l2_subdev_frame_interval *interval)
{
struct gc0310_device *dev = to_gc0310_sensor(sd);
interval->interval.numerator = 1;
interval->interval.denominator = gc0310_res[dev->fmt_idx].fps;
return 0;
}
static int gc0310_enum_mbus_code(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_mbus_code_enum *code)
{
if (code->index >= MAX_FMTS)
return -EINVAL;
code->code = MEDIA_BUS_FMT_SGRBG8_1X8;
return 0;
}
static int gc0310_enum_frame_size(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_frame_size_enum *fse)
{
int index = fse->index;
if (index >= N_RES)
return -EINVAL;
fse->min_width = gc0310_res[index].width;
fse->min_height = gc0310_res[index].height;
fse->max_width = gc0310_res[index].width;
fse->max_height = gc0310_res[index].height;
return 0;
}
static int gc0310_g_skip_frames(struct v4l2_subdev *sd, u32 *frames)
{
struct gc0310_device *dev = to_gc0310_sensor(sd);
mutex_lock(&dev->input_lock);
*frames = gc0310_res[dev->fmt_idx].skip_frames;
mutex_unlock(&dev->input_lock);
return 0;
}
static int gc0310_remove(struct i2c_client *client)
{
struct v4l2_subdev *sd = i2c_get_clientdata(client);
struct gc0310_device *dev = to_gc0310_sensor(sd);
dev_dbg(&client->dev, "gc0310_remove...\n");
if (dev->platform_data->platform_deinit)
dev->platform_data->platform_deinit();
dev->platform_data->csi_cfg(sd, 0);
v4l2_device_unregister_subdev(sd);
media_entity_cleanup(&dev->sd.entity);
v4l2_ctrl_handler_free(&dev->ctrl_handler);
kfree(dev);
return 0;
}
static int gc0310_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct gc0310_device *dev;
int ret;
void *pdata;
unsigned int i;
pr_info("%s S\n", __func__);
dev = kzalloc(sizeof(*dev), GFP_KERNEL);
if (!dev) {
dev_err(&client->dev, "out of memory\n");
return -ENOMEM;
}
mutex_init(&dev->input_lock);
dev->fmt_idx = 0;
v4l2_i2c_subdev_init(&(dev->sd), client, &gc0310_ops);
if (ACPI_COMPANION(&client->dev))
pdata = gmin_camera_platform_data(&dev->sd,
ATOMISP_INPUT_FORMAT_RAW_8,
atomisp_bayer_order_grbg);
else
pdata = client->dev.platform_data;
if (!pdata) {
ret = -EINVAL;
goto out_free;
}
ret = gc0310_s_config(&dev->sd, client->irq, pdata);
if (ret)
goto out_free;
ret = atomisp_register_i2c_module(&dev->sd, pdata, RAW_CAMERA);
if (ret)
goto out_free;
dev->sd.flags |= V4L2_SUBDEV_FL_HAS_DEVNODE;
dev->pad.flags = MEDIA_PAD_FL_SOURCE;
dev->format.code = MEDIA_BUS_FMT_SGRBG8_1X8;
dev->sd.entity.function = MEDIA_ENT_F_CAM_SENSOR;
ret =
v4l2_ctrl_handler_init(&dev->ctrl_handler,
ARRAY_SIZE(gc0310_controls));
if (ret) {
gc0310_remove(client);
return ret;
}
for (i = 0; i < ARRAY_SIZE(gc0310_controls); i++)
v4l2_ctrl_new_custom(&dev->ctrl_handler, &gc0310_controls[i],
NULL);
if (dev->ctrl_handler.error) {
gc0310_remove(client);
return dev->ctrl_handler.error;
}
dev->ctrl_handler.lock = &dev->input_lock;
dev->sd.ctrl_handler = &dev->ctrl_handler;
ret = media_entity_pads_init(&dev->sd.entity, 1, &dev->pad);
if (ret)
gc0310_remove(client);
pr_info("%s E\n", __func__);
return ret;
out_free:
v4l2_device_unregister_subdev(&dev->sd);
kfree(dev);
return ret;
}
static int init_gc0310(void)
{
return i2c_add_driver(&gc0310_driver);
}
static void exit_gc0310(void)
{
i2c_del_driver(&gc0310_driver);
}
