static int ov5670_read_reg(struct ov5670 *ov5670, u16 reg, unsigned int len,
u32 *val)
{
struct i2c_client *client = v4l2_get_subdevdata(&ov5670->sd);
struct i2c_msg msgs[2];
u8 *data_be_p;
u32 data_be = 0;
u16 reg_addr_be = cpu_to_be16(reg);
int ret;
if (len > 4)
return -EINVAL;
data_be_p = (u8 *)&data_be;
msgs[0].addr = client->addr;
msgs[0].flags = 0;
msgs[0].len = 2;
msgs[0].buf = (u8 *)&reg_addr_be;
msgs[1].addr = client->addr;
msgs[1].flags = I2C_M_RD;
msgs[1].len = len;
msgs[1].buf = &data_be_p[4 - len];
ret = i2c_transfer(client->adapter, msgs, ARRAY_SIZE(msgs));
if (ret != ARRAY_SIZE(msgs))
return -EIO;
*val = be32_to_cpu(data_be);
return 0;
}
static int ov5670_write_reg(struct ov5670 *ov5670, u16 reg, unsigned int len,
u32 val)
{
struct i2c_client *client = v4l2_get_subdevdata(&ov5670->sd);
int buf_i;
int val_i;
u8 buf[6];
u8 *val_p;
if (len > 4)
return -EINVAL;
buf[0] = reg >> 8;
buf[1] = reg & 0xff;
val = cpu_to_be32(val);
val_p = (u8 *)&val;
buf_i = 2;
val_i = 4 - len;
while (val_i < 4)
buf[buf_i++] = val_p[val_i++];
if (i2c_master_send(client, buf, len + 2) != len + 2)
return -EIO;
return 0;
}
static int ov5670_write_regs(struct ov5670 *ov5670,
const struct ov5670_reg *regs, unsigned int len)
{
struct i2c_client *client = v4l2_get_subdevdata(&ov5670->sd);
unsigned int i;
int ret;
for (i = 0; i < len; i++) {
ret = ov5670_write_reg(ov5670, regs[i].address, 1, regs[i].val);
if (ret) {
dev_err_ratelimited(
&client->dev,
"Failed to write reg 0x%4.4x. error = %d\n",
regs[i].address, ret);
return ret;
}
}
return 0;
}
static int ov5670_write_reg_list(struct ov5670 *ov5670,
const struct ov5670_reg_list *r_list)
{
return ov5670_write_regs(ov5670, r_list->regs, r_list->num_of_regs);
}
static int ov5670_open(struct v4l2_subdev *sd, struct v4l2_subdev_fh *fh)
{
struct ov5670 *ov5670 = to_ov5670(sd);
struct v4l2_mbus_framefmt *try_fmt =
v4l2_subdev_get_try_format(sd, fh->pad, 0);
mutex_lock(&ov5670->mutex);
try_fmt->width = ov5670->cur_mode->width;
try_fmt->height = ov5670->cur_mode->height;
try_fmt->code = MEDIA_BUS_FMT_SGRBG10_1X10;
try_fmt->field = V4L2_FIELD_NONE;
mutex_unlock(&ov5670->mutex);
return 0;
}
static int ov5670_update_digital_gain(struct ov5670 *ov5670, u32 d_gain)
{
int ret;
ret = ov5670_write_reg(ov5670, OV5670_REG_R_DGTL_GAIN,
OV5670_REG_VALUE_16BIT, d_gain);
if (ret)
return ret;
ret = ov5670_write_reg(ov5670, OV5670_REG_G_DGTL_GAIN,
OV5670_REG_VALUE_16BIT, d_gain);
if (ret)
return ret;
return ov5670_write_reg(ov5670, OV5670_REG_B_DGTL_GAIN,
OV5670_REG_VALUE_16BIT, d_gain);
}
static int ov5670_enable_test_pattern(struct ov5670 *ov5670, u32 pattern)
{
u32 val;
int ret;
ret = ov5670_write_reg(ov5670, OV5670_REG_TEST_PATTERN_CTRL,
OV5670_REG_VALUE_08BIT, 0);
if (ret)
return ret;
ret = ov5670_read_reg(ov5670, OV5670_REG_TEST_PATTERN,
OV5670_REG_VALUE_08BIT, &val);
if (ret)
return ret;
if (pattern)
val |= OV5670_TEST_PATTERN_ENABLE;
else
val &= ~OV5670_TEST_PATTERN_ENABLE;
return ov5670_write_reg(ov5670, OV5670_REG_TEST_PATTERN,
OV5670_REG_VALUE_08BIT, val);
}
static int ov5670_set_ctrl(struct v4l2_ctrl *ctrl)
{
struct ov5670 *ov5670 = container_of(ctrl->handler,
struct ov5670, ctrl_handler);
struct i2c_client *client = v4l2_get_subdevdata(&ov5670->sd);
s64 max;
int ret = 0;
switch (ctrl->id) {
case V4L2_CID_VBLANK:
max = ov5670->cur_mode->height + ctrl->val - 8;
__v4l2_ctrl_modify_range(ov5670->exposure,
ov5670->exposure->minimum, max,
ov5670->exposure->step, max);
break;
}
if (pm_runtime_get_if_in_use(&client->dev) <= 0)
return 0;
switch (ctrl->id) {
case V4L2_CID_ANALOGUE_GAIN:
ret = ov5670_write_reg(ov5670, OV5670_REG_ANALOG_GAIN,
OV5670_REG_VALUE_16BIT, ctrl->val);
break;
case V4L2_CID_DIGITAL_GAIN:
ret = ov5670_update_digital_gain(ov5670, ctrl->val);
break;
case V4L2_CID_EXPOSURE:
ret = ov5670_write_reg(ov5670, OV5670_REG_EXPOSURE,
OV5670_REG_VALUE_24BIT, ctrl->val << 4);
break;
case V4L2_CID_VBLANK:
ret = ov5670_write_reg(ov5670, OV5670_REG_VTS,
OV5670_REG_VALUE_16BIT,
ov5670->cur_mode->height + ctrl->val);
break;
case V4L2_CID_TEST_PATTERN:
ret = ov5670_enable_test_pattern(ov5670, ctrl->val);
break;
default:
dev_info(&client->dev, "%s Unhandled id:0x%x, val:0x%x\n",
__func__, ctrl->id, ctrl->val);
break;
}
pm_runtime_put(&client->dev);
return ret;
}
static int ov5670_init_controls(struct ov5670 *ov5670)
{
struct v4l2_ctrl_handler *ctrl_hdlr;
s64 vblank_max;
s64 vblank_def;
s64 vblank_min;
s64 exposure_max;
int ret;
ctrl_hdlr = &ov5670->ctrl_handler;
ret = v4l2_ctrl_handler_init(ctrl_hdlr, 8);
if (ret)
return ret;
ctrl_hdlr->lock = &ov5670->mutex;
ov5670->link_freq = v4l2_ctrl_new_int_menu(ctrl_hdlr,
&ov5670_ctrl_ops,
V4L2_CID_LINK_FREQ,
0, 0, link_freq_menu_items);
if (ov5670->link_freq)
ov5670->link_freq->flags |= V4L2_CTRL_FLAG_READ_ONLY;
ov5670->pixel_rate = v4l2_ctrl_new_std(ctrl_hdlr, &ov5670_ctrl_ops,
V4L2_CID_PIXEL_RATE, 0,
link_freq_configs[0].pixel_rate,
1,
link_freq_configs[0].pixel_rate);
vblank_max = OV5670_VTS_MAX - ov5670->cur_mode->height;
vblank_def = ov5670->cur_mode->vts_def - ov5670->cur_mode->height;
vblank_min = ov5670->cur_mode->vts_min - ov5670->cur_mode->height;
ov5670->vblank = v4l2_ctrl_new_std(ctrl_hdlr, &ov5670_ctrl_ops,
V4L2_CID_VBLANK, vblank_min,
vblank_max, 1, vblank_def);
ov5670->hblank = v4l2_ctrl_new_std(
ctrl_hdlr, &ov5670_ctrl_ops, V4L2_CID_HBLANK,
OV5670_FIXED_PPL - ov5670->cur_mode->width,
OV5670_FIXED_PPL - ov5670->cur_mode->width, 1,
OV5670_FIXED_PPL - ov5670->cur_mode->width);
if (ov5670->hblank)
ov5670->hblank->flags |= V4L2_CTRL_FLAG_READ_ONLY;
v4l2_ctrl_new_std(ctrl_hdlr, &ov5670_ctrl_ops, V4L2_CID_ANALOGUE_GAIN,
ANALOG_GAIN_MIN, ANALOG_GAIN_MAX, ANALOG_GAIN_STEP,
ANALOG_GAIN_DEFAULT);
v4l2_ctrl_new_std(ctrl_hdlr, &ov5670_ctrl_ops, V4L2_CID_DIGITAL_GAIN,
OV5670_DGTL_GAIN_MIN, OV5670_DGTL_GAIN_MAX,
OV5670_DGTL_GAIN_STEP, OV5670_DGTL_GAIN_DEFAULT);
exposure_max = ov5670->cur_mode->vts_def - 8;
ov5670->exposure = v4l2_ctrl_new_std(ctrl_hdlr, &ov5670_ctrl_ops,
V4L2_CID_EXPOSURE,
OV5670_EXPOSURE_MIN,
exposure_max, OV5670_EXPOSURE_STEP,
exposure_max);
v4l2_ctrl_new_std_menu_items(ctrl_hdlr, &ov5670_ctrl_ops,
V4L2_CID_TEST_PATTERN,
ARRAY_SIZE(ov5670_test_pattern_menu) - 1,
0, 0, ov5670_test_pattern_menu);
if (ctrl_hdlr->error) {
ret = ctrl_hdlr->error;
goto error;
}
ov5670->sd.ctrl_handler = ctrl_hdlr;
return 0;
error:
v4l2_ctrl_handler_free(ctrl_hdlr);
return ret;
}
static int ov5670_enum_mbus_code(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_mbus_code_enum *code)
{
if (code->index > 0)
return -EINVAL;
code->code = MEDIA_BUS_FMT_SGRBG10_1X10;
return 0;
}
static int ov5670_enum_frame_size(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_frame_size_enum *fse)
{
if (fse->index >= ARRAY_SIZE(supported_modes))
return -EINVAL;
if (fse->code != MEDIA_BUS_FMT_SGRBG10_1X10)
return -EINVAL;
fse->min_width = supported_modes[fse->index].width;
fse->max_width = fse->min_width;
fse->min_height = supported_modes[fse->index].height;
fse->max_height = fse->min_height;
return 0;
}
static int ov5670_get_reso_dist(const struct ov5670_mode *mode,
struct v4l2_mbus_framefmt *framefmt)
{
return abs(mode->width - framefmt->width) +
abs(mode->height - framefmt->height);
}
static const struct ov5670_mode *ov5670_find_best_fit(
struct ov5670 *ov5670,
struct v4l2_subdev_format *fmt)
{
struct v4l2_mbus_framefmt *framefmt = &fmt->format;
int dist;
int cur_best_fit = 0;
int cur_best_fit_dist = -1;
int i;
for (i = 0; i < ARRAY_SIZE(supported_modes); i++) {
dist = ov5670_get_reso_dist(&supported_modes[i], framefmt);
if (cur_best_fit_dist == -1 || dist < cur_best_fit_dist) {
cur_best_fit_dist = dist;
cur_best_fit = i;
}
}
return &supported_modes[cur_best_fit];
}
static void ov5670_update_pad_format(const struct ov5670_mode *mode,
struct v4l2_subdev_format *fmt)
{
fmt->format.width = mode->width;
fmt->format.height = mode->height;
fmt->format.code = MEDIA_BUS_FMT_SGRBG10_1X10;
fmt->format.field = V4L2_FIELD_NONE;
}
static int ov5670_do_get_pad_format(struct ov5670 *ov5670,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_format *fmt)
{
if (fmt->which == V4L2_SUBDEV_FORMAT_TRY)
fmt->format = *v4l2_subdev_get_try_format(&ov5670->sd, cfg,
fmt->pad);
else
ov5670_update_pad_format(ov5670->cur_mode, fmt);
return 0;
}
static int ov5670_get_pad_format(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_format *fmt)
{
struct ov5670 *ov5670 = to_ov5670(sd);
int ret;
mutex_lock(&ov5670->mutex);
ret = ov5670_do_get_pad_format(ov5670, cfg, fmt);
mutex_unlock(&ov5670->mutex);
return ret;
}
static int ov5670_set_pad_format(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_format *fmt)
{
struct ov5670 *ov5670 = to_ov5670(sd);
const struct ov5670_mode *mode;
s32 vblank_def;
s32 h_blank;
mutex_lock(&ov5670->mutex);
fmt->format.code = MEDIA_BUS_FMT_SGRBG10_1X10;
mode = ov5670_find_best_fit(ov5670, fmt);
ov5670_update_pad_format(mode, fmt);
if (fmt->which == V4L2_SUBDEV_FORMAT_TRY) {
*v4l2_subdev_get_try_format(sd, cfg, fmt->pad) = fmt->format;
} else {
ov5670->cur_mode = mode;
__v4l2_ctrl_s_ctrl(ov5670->link_freq, mode->link_freq_index);
__v4l2_ctrl_s_ctrl_int64(
ov5670->pixel_rate,
link_freq_configs[mode->link_freq_index].pixel_rate);
vblank_def = ov5670->cur_mode->vts_def -
ov5670->cur_mode->height;
__v4l2_ctrl_modify_range(
ov5670->vblank,
ov5670->cur_mode->vts_min - ov5670->cur_mode->height,
OV5670_VTS_MAX - ov5670->cur_mode->height, 1,
vblank_def);
__v4l2_ctrl_s_ctrl(ov5670->vblank, vblank_def);
h_blank = OV5670_FIXED_PPL - ov5670->cur_mode->width;
__v4l2_ctrl_modify_range(ov5670->hblank, h_blank, h_blank, 1,
h_blank);
}
mutex_unlock(&ov5670->mutex);
return 0;
}
static int ov5670_get_skip_frames(struct v4l2_subdev *sd, u32 *frames)
{
*frames = OV5670_NUM_OF_SKIP_FRAMES;
return 0;
}
static int ov5670_start_streaming(struct ov5670 *ov5670)
{
struct i2c_client *client = v4l2_get_subdevdata(&ov5670->sd);
const struct ov5670_reg_list *reg_list;
int link_freq_index;
int ret;
ret = ov5670_write_reg(ov5670, OV5670_REG_SOFTWARE_RST,
OV5670_REG_VALUE_08BIT, OV5670_SOFTWARE_RST);
if (ret) {
dev_err(&client->dev, "%s failed to set powerup registers\n",
__func__);
return ret;
}
link_freq_index = ov5670->cur_mode->link_freq_index;
reg_list = &link_freq_configs[link_freq_index].reg_list;
ret = ov5670_write_reg_list(ov5670, reg_list);
if (ret) {
dev_err(&client->dev, "%s failed to set plls\n", __func__);
return ret;
}
reg_list = &ov5670->cur_mode->reg_list;
ret = ov5670_write_reg_list(ov5670, reg_list);
if (ret) {
dev_err(&client->dev, "%s failed to set mode\n", __func__);
return ret;
}
ret = __v4l2_ctrl_handler_setup(ov5670->sd.ctrl_handler);
if (ret)
return ret;
ret = ov5670_write_reg(ov5670, OV5670_REG_MODE_SELECT,
OV5670_REG_VALUE_08BIT, OV5670_MODE_STREAMING);
if (ret) {
dev_err(&client->dev, "%s failed to set stream\n", __func__);
return ret;
}
ov5670->streaming = true;
return 0;
}
static int ov5670_stop_streaming(struct ov5670 *ov5670)
{
struct i2c_client *client = v4l2_get_subdevdata(&ov5670->sd);
int ret;
ret = ov5670_write_reg(ov5670, OV5670_REG_MODE_SELECT,
OV5670_REG_VALUE_08BIT, OV5670_MODE_STANDBY);
if (ret)
dev_err(&client->dev, "%s failed to set stream\n", __func__);
ov5670->streaming = false;
return 0;
}
static int ov5670_set_stream(struct v4l2_subdev *sd, int enable)
{
struct ov5670 *ov5670 = to_ov5670(sd);
struct i2c_client *client = v4l2_get_subdevdata(sd);
int ret = 0;
mutex_lock(&ov5670->mutex);
if (ov5670->streaming == enable)
goto unlock_and_return;
if (enable) {
ret = pm_runtime_get_sync(&client->dev);
if (ret < 0) {
pm_runtime_put_noidle(&client->dev);
goto unlock_and_return;
}
ret = ov5670_start_streaming(ov5670);
if (ret)
goto error;
} else {
ret = ov5670_stop_streaming(ov5670);
pm_runtime_put(&client->dev);
}
goto unlock_and_return;
error:
pm_runtime_put(&client->dev);
unlock_and_return:
mutex_unlock(&ov5670->mutex);
return ret;
}
static int __maybe_unused ov5670_suspend(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct v4l2_subdev *sd = i2c_get_clientdata(client);
struct ov5670 *ov5670 = to_ov5670(sd);
if (ov5670->streaming)
ov5670_stop_streaming(ov5670);
return 0;
}
static int __maybe_unused ov5670_resume(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct v4l2_subdev *sd = i2c_get_clientdata(client);
struct ov5670 *ov5670 = to_ov5670(sd);
int ret;
if (ov5670->streaming) {
ret = ov5670_start_streaming(ov5670);
if (ret) {
ov5670_stop_streaming(ov5670);
return ret;
}
}
return 0;
}
static int ov5670_identify_module(struct ov5670 *ov5670)
{
struct i2c_client *client = v4l2_get_subdevdata(&ov5670->sd);
int ret;
u32 val;
ret = ov5670_read_reg(ov5670, OV5670_REG_CHIP_ID,
OV5670_REG_VALUE_24BIT, &val);
if (ret)
return ret;
if (val != OV5670_CHIP_ID) {
dev_err(&client->dev, "chip id mismatch: %x!=%x\n",
OV5670_CHIP_ID, val);
return -ENXIO;
}
return 0;
}
static int ov5670_probe(struct i2c_client *client)
{
struct ov5670 *ov5670;
const char *err_msg;
u32 input_clk = 0;
int ret;
device_property_read_u32(&client->dev, "clock-frequency", &input_clk);
if (input_clk != 19200000)
return -EINVAL;
ov5670 = devm_kzalloc(&client->dev, sizeof(*ov5670), GFP_KERNEL);
if (!ov5670) {
ret = -ENOMEM;
err_msg = "devm_kzalloc() error";
goto error_print;
}
v4l2_i2c_subdev_init(&ov5670->sd, client, &ov5670_subdev_ops);
ret = ov5670_identify_module(ov5670);
if (ret) {
err_msg = "ov5670_identify_module() error";
goto error_print;
}
mutex_init(&ov5670->mutex);
ov5670->cur_mode = &supported_modes[0];
ret = ov5670_init_controls(ov5670);
if (ret) {
err_msg = "ov5670_init_controls() error";
goto error_mutex_destroy;
}
ov5670->sd.internal_ops = &ov5670_internal_ops;
ov5670->sd.flags |= V4L2_SUBDEV_FL_HAS_DEVNODE;
ov5670->sd.entity.ops = &ov5670_subdev_entity_ops;
ov5670->sd.entity.function = MEDIA_ENT_F_CAM_SENSOR;
ov5670->pad.flags = MEDIA_PAD_FL_SOURCE;
ret = media_entity_pads_init(&ov5670->sd.entity, 1, &ov5670->pad);
if (ret) {
err_msg = "media_entity_pads_init() error";
goto error_handler_free;
}
ret = v4l2_async_register_subdev(&ov5670->sd);
if (ret < 0) {
err_msg = "v4l2_async_register_subdev() error";
goto error_entity_cleanup;
}
ov5670->streaming = false;
pm_runtime_get_noresume(&client->dev);
pm_runtime_set_active(&client->dev);
pm_runtime_enable(&client->dev);
pm_runtime_put(&client->dev);
return 0;
error_entity_cleanup:
media_entity_cleanup(&ov5670->sd.entity);
error_handler_free:
v4l2_ctrl_handler_free(ov5670->sd.ctrl_handler);
error_mutex_destroy:
mutex_destroy(&ov5670->mutex);
error_print:
dev_err(&client->dev, "%s: %s %d\n", __func__, err_msg, ret);
return ret;
}
static int ov5670_remove(struct i2c_client *client)
{
struct v4l2_subdev *sd = i2c_get_clientdata(client);
struct ov5670 *ov5670 = to_ov5670(sd);
v4l2_async_unregister_subdev(sd);
media_entity_cleanup(&sd->entity);
v4l2_ctrl_handler_free(sd->ctrl_handler);
mutex_destroy(&ov5670->mutex);
pm_runtime_get_sync(&client->dev);
pm_runtime_disable(&client->dev);
pm_runtime_set_suspended(&client->dev);
pm_runtime_put_noidle(&client->dev);
return 0;
}
