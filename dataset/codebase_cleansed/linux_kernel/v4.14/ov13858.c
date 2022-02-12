static int ov13858_read_reg(struct ov13858 *ov13858, u16 reg, u32 len, u32 *val)
{
struct i2c_client *client = v4l2_get_subdevdata(&ov13858->sd);
struct i2c_msg msgs[2];
u8 *data_be_p;
int ret;
u32 data_be = 0;
u16 reg_addr_be = cpu_to_be16(reg);
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
static int ov13858_write_reg(struct ov13858 *ov13858, u16 reg, u32 len, u32 val)
{
struct i2c_client *client = v4l2_get_subdevdata(&ov13858->sd);
int buf_i, val_i;
u8 buf[6], *val_p;
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
static int ov13858_write_regs(struct ov13858 *ov13858,
const struct ov13858_reg *regs, u32 len)
{
struct i2c_client *client = v4l2_get_subdevdata(&ov13858->sd);
int ret;
u32 i;
for (i = 0; i < len; i++) {
ret = ov13858_write_reg(ov13858, regs[i].address, 1,
regs[i].val);
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
static int ov13858_write_reg_list(struct ov13858 *ov13858,
const struct ov13858_reg_list *r_list)
{
return ov13858_write_regs(ov13858, r_list->regs, r_list->num_of_regs);
}
static int ov13858_open(struct v4l2_subdev *sd, struct v4l2_subdev_fh *fh)
{
struct ov13858 *ov13858 = to_ov13858(sd);
struct v4l2_mbus_framefmt *try_fmt = v4l2_subdev_get_try_format(sd,
fh->pad,
0);
mutex_lock(&ov13858->mutex);
try_fmt->width = ov13858->cur_mode->width;
try_fmt->height = ov13858->cur_mode->height;
try_fmt->code = MEDIA_BUS_FMT_SGRBG10_1X10;
try_fmt->field = V4L2_FIELD_NONE;
mutex_unlock(&ov13858->mutex);
return 0;
}
static int ov13858_update_digital_gain(struct ov13858 *ov13858, u32 d_gain)
{
int ret;
ret = ov13858_write_reg(ov13858, OV13858_REG_B_MWB_GAIN,
OV13858_REG_VALUE_16BIT, d_gain);
if (ret)
return ret;
ret = ov13858_write_reg(ov13858, OV13858_REG_G_MWB_GAIN,
OV13858_REG_VALUE_16BIT, d_gain);
if (ret)
return ret;
ret = ov13858_write_reg(ov13858, OV13858_REG_R_MWB_GAIN,
OV13858_REG_VALUE_16BIT, d_gain);
return ret;
}
static int ov13858_enable_test_pattern(struct ov13858 *ov13858, u32 pattern)
{
int ret;
u32 val;
ret = ov13858_read_reg(ov13858, OV13858_REG_TEST_PATTERN,
OV13858_REG_VALUE_08BIT, &val);
if (ret)
return ret;
if (pattern) {
val &= OV13858_TEST_PATTERN_MASK;
val |= (pattern - 1) | OV13858_TEST_PATTERN_ENABLE;
} else {
val &= ~OV13858_TEST_PATTERN_ENABLE;
}
return ov13858_write_reg(ov13858, OV13858_REG_TEST_PATTERN,
OV13858_REG_VALUE_08BIT, val);
}
static int ov13858_set_ctrl(struct v4l2_ctrl *ctrl)
{
struct ov13858 *ov13858 = container_of(ctrl->handler,
struct ov13858, ctrl_handler);
struct i2c_client *client = v4l2_get_subdevdata(&ov13858->sd);
s64 max;
int ret;
switch (ctrl->id) {
case V4L2_CID_VBLANK:
max = ov13858->cur_mode->height + ctrl->val - 8;
__v4l2_ctrl_modify_range(ov13858->exposure,
ov13858->exposure->minimum,
max, ov13858->exposure->step, max);
break;
};
if (pm_runtime_get_if_in_use(&client->dev) <= 0)
return 0;
ret = 0;
switch (ctrl->id) {
case V4L2_CID_ANALOGUE_GAIN:
ret = ov13858_write_reg(ov13858, OV13858_REG_ANALOG_GAIN,
OV13858_REG_VALUE_16BIT, ctrl->val);
break;
case V4L2_CID_DIGITAL_GAIN:
ret = ov13858_update_digital_gain(ov13858, ctrl->val);
break;
case V4L2_CID_EXPOSURE:
ret = ov13858_write_reg(ov13858, OV13858_REG_EXPOSURE,
OV13858_REG_VALUE_24BIT,
ctrl->val << 4);
break;
case V4L2_CID_VBLANK:
ret = ov13858_write_reg(ov13858, OV13858_REG_VTS,
OV13858_REG_VALUE_16BIT,
ov13858->cur_mode->height
+ ctrl->val);
break;
case V4L2_CID_TEST_PATTERN:
ret = ov13858_enable_test_pattern(ov13858, ctrl->val);
break;
default:
dev_info(&client->dev,
"ctrl(id:0x%x,val:0x%x) is not handled\n",
ctrl->id, ctrl->val);
break;
};
pm_runtime_put(&client->dev);
return ret;
}
static int ov13858_enum_mbus_code(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_mbus_code_enum *code)
{
if (code->index > 0)
return -EINVAL;
code->code = MEDIA_BUS_FMT_SGRBG10_1X10;
return 0;
}
static int ov13858_enum_frame_size(struct v4l2_subdev *sd,
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
static void ov13858_update_pad_format(const struct ov13858_mode *mode,
struct v4l2_subdev_format *fmt)
{
fmt->format.width = mode->width;
fmt->format.height = mode->height;
fmt->format.code = MEDIA_BUS_FMT_SGRBG10_1X10;
fmt->format.field = V4L2_FIELD_NONE;
}
static int ov13858_do_get_pad_format(struct ov13858 *ov13858,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_format *fmt)
{
struct v4l2_mbus_framefmt *framefmt;
struct v4l2_subdev *sd = &ov13858->sd;
if (fmt->which == V4L2_SUBDEV_FORMAT_TRY) {
framefmt = v4l2_subdev_get_try_format(sd, cfg, fmt->pad);
fmt->format = *framefmt;
} else {
ov13858_update_pad_format(ov13858->cur_mode, fmt);
}
return 0;
}
static int ov13858_get_pad_format(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_format *fmt)
{
struct ov13858 *ov13858 = to_ov13858(sd);
int ret;
mutex_lock(&ov13858->mutex);
ret = ov13858_do_get_pad_format(ov13858, cfg, fmt);
mutex_unlock(&ov13858->mutex);
return ret;
}
static int
ov13858_get_resolution_dist(const struct ov13858_mode *mode,
struct v4l2_mbus_framefmt *framefmt)
{
return abs(mode->width - framefmt->width) +
abs(mode->height - framefmt->height);
}
static const struct ov13858_mode *
ov13858_find_best_fit(struct ov13858 *ov13858,
struct v4l2_subdev_format *fmt)
{
int i, dist, cur_best_fit = 0, cur_best_fit_dist = -1;
struct v4l2_mbus_framefmt *framefmt = &fmt->format;
for (i = 0; i < ARRAY_SIZE(supported_modes); i++) {
dist = ov13858_get_resolution_dist(&supported_modes[i],
framefmt);
if (cur_best_fit_dist == -1 || dist < cur_best_fit_dist) {
cur_best_fit_dist = dist;
cur_best_fit = i;
}
}
return &supported_modes[cur_best_fit];
}
static int
ov13858_set_pad_format(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_format *fmt)
{
struct ov13858 *ov13858 = to_ov13858(sd);
const struct ov13858_mode *mode;
struct v4l2_mbus_framefmt *framefmt;
s32 vblank_def;
s32 vblank_min;
s64 h_blank;
mutex_lock(&ov13858->mutex);
if (fmt->format.code != MEDIA_BUS_FMT_SGRBG10_1X10)
fmt->format.code = MEDIA_BUS_FMT_SGRBG10_1X10;
mode = ov13858_find_best_fit(ov13858, fmt);
ov13858_update_pad_format(mode, fmt);
if (fmt->which == V4L2_SUBDEV_FORMAT_TRY) {
framefmt = v4l2_subdev_get_try_format(sd, cfg, fmt->pad);
*framefmt = fmt->format;
} else {
ov13858->cur_mode = mode;
__v4l2_ctrl_s_ctrl(ov13858->link_freq, mode->link_freq_index);
__v4l2_ctrl_s_ctrl_int64(
ov13858->pixel_rate,
link_freq_configs[mode->link_freq_index].pixel_rate);
vblank_def = ov13858->cur_mode->vts_def -
ov13858->cur_mode->height;
vblank_min = ov13858->cur_mode->vts_min -
ov13858->cur_mode->height;
__v4l2_ctrl_modify_range(
ov13858->vblank, vblank_min,
OV13858_VTS_MAX - ov13858->cur_mode->height, 1,
vblank_def);
__v4l2_ctrl_s_ctrl(ov13858->vblank, vblank_def);
h_blank =
link_freq_configs[mode->link_freq_index].pixels_per_line
- ov13858->cur_mode->width;
__v4l2_ctrl_modify_range(ov13858->hblank, h_blank,
h_blank, 1, h_blank);
}
mutex_unlock(&ov13858->mutex);
return 0;
}
static int ov13858_get_skip_frames(struct v4l2_subdev *sd, u32 *frames)
{
*frames = OV13858_NUM_OF_SKIP_FRAMES;
return 0;
}
static int ov13858_start_streaming(struct ov13858 *ov13858)
{
struct i2c_client *client = v4l2_get_subdevdata(&ov13858->sd);
const struct ov13858_reg_list *reg_list;
int ret, link_freq_index;
ret = ov13858_write_reg(ov13858, OV13858_REG_SOFTWARE_RST,
OV13858_REG_VALUE_08BIT, OV13858_SOFTWARE_RST);
if (ret) {
dev_err(&client->dev, "%s failed to set powerup registers\n",
__func__);
return ret;
}
link_freq_index = ov13858->cur_mode->link_freq_index;
reg_list = &link_freq_configs[link_freq_index].reg_list;
ret = ov13858_write_reg_list(ov13858, reg_list);
if (ret) {
dev_err(&client->dev, "%s failed to set plls\n", __func__);
return ret;
}
reg_list = &ov13858->cur_mode->reg_list;
ret = ov13858_write_reg_list(ov13858, reg_list);
if (ret) {
dev_err(&client->dev, "%s failed to set mode\n", __func__);
return ret;
}
ret = __v4l2_ctrl_handler_setup(ov13858->sd.ctrl_handler);
if (ret)
return ret;
return ov13858_write_reg(ov13858, OV13858_REG_MODE_SELECT,
OV13858_REG_VALUE_08BIT,
OV13858_MODE_STREAMING);
}
static int ov13858_stop_streaming(struct ov13858 *ov13858)
{
return ov13858_write_reg(ov13858, OV13858_REG_MODE_SELECT,
OV13858_REG_VALUE_08BIT, OV13858_MODE_STANDBY);
}
static int ov13858_set_stream(struct v4l2_subdev *sd, int enable)
{
struct ov13858 *ov13858 = to_ov13858(sd);
struct i2c_client *client = v4l2_get_subdevdata(sd);
int ret = 0;
mutex_lock(&ov13858->mutex);
if (ov13858->streaming == enable) {
mutex_unlock(&ov13858->mutex);
return 0;
}
if (enable) {
ret = pm_runtime_get_sync(&client->dev);
if (ret < 0) {
pm_runtime_put_noidle(&client->dev);
goto err_unlock;
}
ret = ov13858_start_streaming(ov13858);
if (ret)
goto err_rpm_put;
} else {
ov13858_stop_streaming(ov13858);
pm_runtime_put(&client->dev);
}
ov13858->streaming = enable;
mutex_unlock(&ov13858->mutex);
return ret;
err_rpm_put:
pm_runtime_put(&client->dev);
err_unlock:
mutex_unlock(&ov13858->mutex);
return ret;
}
static int __maybe_unused ov13858_suspend(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct v4l2_subdev *sd = i2c_get_clientdata(client);
struct ov13858 *ov13858 = to_ov13858(sd);
if (ov13858->streaming)
ov13858_stop_streaming(ov13858);
return 0;
}
static int __maybe_unused ov13858_resume(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct v4l2_subdev *sd = i2c_get_clientdata(client);
struct ov13858 *ov13858 = to_ov13858(sd);
int ret;
if (ov13858->streaming) {
ret = ov13858_start_streaming(ov13858);
if (ret)
goto error;
}
return 0;
error:
ov13858_stop_streaming(ov13858);
ov13858->streaming = 0;
return ret;
}
static int ov13858_identify_module(struct ov13858 *ov13858)
{
struct i2c_client *client = v4l2_get_subdevdata(&ov13858->sd);
int ret;
u32 val;
ret = ov13858_read_reg(ov13858, OV13858_REG_CHIP_ID,
OV13858_REG_VALUE_24BIT, &val);
if (ret)
return ret;
if (val != OV13858_CHIP_ID) {
dev_err(&client->dev, "chip id mismatch: %x!=%x\n",
OV13858_CHIP_ID, val);
return -EIO;
}
return 0;
}
static int ov13858_init_controls(struct ov13858 *ov13858)
{
struct i2c_client *client = v4l2_get_subdevdata(&ov13858->sd);
struct v4l2_ctrl_handler *ctrl_hdlr;
s64 exposure_max;
s64 vblank_def;
s64 vblank_min;
int ret;
ctrl_hdlr = &ov13858->ctrl_handler;
ret = v4l2_ctrl_handler_init(ctrl_hdlr, 8);
if (ret)
return ret;
mutex_init(&ov13858->mutex);
ctrl_hdlr->lock = &ov13858->mutex;
ov13858->link_freq = v4l2_ctrl_new_int_menu(ctrl_hdlr,
&ov13858_ctrl_ops,
V4L2_CID_LINK_FREQ,
OV13858_NUM_OF_LINK_FREQS - 1,
0,
link_freq_menu_items);
ov13858->link_freq->flags |= V4L2_CTRL_FLAG_READ_ONLY;
ov13858->pixel_rate = v4l2_ctrl_new_std(ctrl_hdlr, &ov13858_ctrl_ops,
V4L2_CID_PIXEL_RATE, 0,
link_freq_configs[0].pixel_rate, 1,
link_freq_configs[0].pixel_rate);
vblank_def = ov13858->cur_mode->vts_def - ov13858->cur_mode->height;
vblank_min = ov13858->cur_mode->vts_min - ov13858->cur_mode->height;
ov13858->vblank = v4l2_ctrl_new_std(
ctrl_hdlr, &ov13858_ctrl_ops, V4L2_CID_VBLANK,
vblank_min,
OV13858_VTS_MAX - ov13858->cur_mode->height, 1,
vblank_def);
ov13858->hblank = v4l2_ctrl_new_std(
ctrl_hdlr, &ov13858_ctrl_ops, V4L2_CID_HBLANK,
OV13858_PPL_540MHZ - ov13858->cur_mode->width,
OV13858_PPL_540MHZ - ov13858->cur_mode->width,
1,
OV13858_PPL_540MHZ - ov13858->cur_mode->width);
ov13858->hblank->flags |= V4L2_CTRL_FLAG_READ_ONLY;
exposure_max = ov13858->cur_mode->vts_def - 8;
ov13858->exposure = v4l2_ctrl_new_std(
ctrl_hdlr, &ov13858_ctrl_ops,
V4L2_CID_EXPOSURE, OV13858_EXPOSURE_MIN,
exposure_max, OV13858_EXPOSURE_STEP,
OV13858_EXPOSURE_DEFAULT);
v4l2_ctrl_new_std(ctrl_hdlr, &ov13858_ctrl_ops, V4L2_CID_ANALOGUE_GAIN,
OV13858_ANA_GAIN_MIN, OV13858_ANA_GAIN_MAX,
OV13858_ANA_GAIN_STEP, OV13858_ANA_GAIN_DEFAULT);
v4l2_ctrl_new_std(ctrl_hdlr, &ov13858_ctrl_ops, V4L2_CID_DIGITAL_GAIN,
OV13858_DGTL_GAIN_MIN, OV13858_DGTL_GAIN_MAX,
OV13858_DGTL_GAIN_STEP, OV13858_DGTL_GAIN_DEFAULT);
v4l2_ctrl_new_std_menu_items(ctrl_hdlr, &ov13858_ctrl_ops,
V4L2_CID_TEST_PATTERN,
ARRAY_SIZE(ov13858_test_pattern_menu) - 1,
0, 0, ov13858_test_pattern_menu);
if (ctrl_hdlr->error) {
ret = ctrl_hdlr->error;
dev_err(&client->dev, "%s control init failed (%d)\n",
__func__, ret);
goto error;
}
ov13858->sd.ctrl_handler = ctrl_hdlr;
return 0;
error:
v4l2_ctrl_handler_free(ctrl_hdlr);
mutex_destroy(&ov13858->mutex);
return ret;
}
static void ov13858_free_controls(struct ov13858 *ov13858)
{
v4l2_ctrl_handler_free(ov13858->sd.ctrl_handler);
mutex_destroy(&ov13858->mutex);
}
static int ov13858_probe(struct i2c_client *client,
const struct i2c_device_id *devid)
{
struct ov13858 *ov13858;
int ret;
u32 val = 0;
device_property_read_u32(&client->dev, "clock-frequency", &val);
if (val != 19200000)
return -EINVAL;
ov13858 = devm_kzalloc(&client->dev, sizeof(*ov13858), GFP_KERNEL);
if (!ov13858)
return -ENOMEM;
v4l2_i2c_subdev_init(&ov13858->sd, client, &ov13858_subdev_ops);
ret = ov13858_identify_module(ov13858);
if (ret) {
dev_err(&client->dev, "failed to find sensor: %d\n", ret);
return ret;
}
ov13858->cur_mode = &supported_modes[0];
ret = ov13858_init_controls(ov13858);
if (ret)
return ret;
ov13858->sd.internal_ops = &ov13858_internal_ops;
ov13858->sd.flags |= V4L2_SUBDEV_FL_HAS_DEVNODE;
ov13858->sd.entity.ops = &ov13858_subdev_entity_ops;
ov13858->sd.entity.function = MEDIA_ENT_F_CAM_SENSOR;
ov13858->pad.flags = MEDIA_PAD_FL_SOURCE;
ret = media_entity_pads_init(&ov13858->sd.entity, 1, &ov13858->pad);
if (ret) {
dev_err(&client->dev, "%s failed:%d\n", __func__, ret);
goto error_handler_free;
}
ret = v4l2_async_register_subdev(&ov13858->sd);
if (ret < 0)
goto error_media_entity;
pm_runtime_get_noresume(&client->dev);
pm_runtime_set_active(&client->dev);
pm_runtime_enable(&client->dev);
pm_runtime_put(&client->dev);
return 0;
error_media_entity:
media_entity_cleanup(&ov13858->sd.entity);
error_handler_free:
ov13858_free_controls(ov13858);
dev_err(&client->dev, "%s failed:%d\n", __func__, ret);
return ret;
}
static int ov13858_remove(struct i2c_client *client)
{
struct v4l2_subdev *sd = i2c_get_clientdata(client);
struct ov13858 *ov13858 = to_ov13858(sd);
v4l2_async_unregister_subdev(sd);
media_entity_cleanup(&sd->entity);
ov13858_free_controls(ov13858);
pm_runtime_get_sync(&client->dev);
pm_runtime_disable(&client->dev);
pm_runtime_set_suspended(&client->dev);
pm_runtime_put_noidle(&client->dev);
return 0;
}
