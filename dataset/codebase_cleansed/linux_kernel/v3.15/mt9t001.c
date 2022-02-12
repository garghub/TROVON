static inline struct mt9t001 *to_mt9t001(struct v4l2_subdev *sd)
{
return container_of(sd, struct mt9t001, subdev);
}
static int mt9t001_read(struct i2c_client *client, u8 reg)
{
return i2c_smbus_read_word_swapped(client, reg);
}
static int mt9t001_write(struct i2c_client *client, u8 reg, u16 data)
{
return i2c_smbus_write_word_swapped(client, reg, data);
}
static int mt9t001_set_output_control(struct mt9t001 *mt9t001, u16 clear,
u16 set)
{
struct i2c_client *client = v4l2_get_subdevdata(&mt9t001->subdev);
u16 value = (mt9t001->output_control & ~clear) | set;
int ret;
if (value == mt9t001->output_control)
return 0;
ret = mt9t001_write(client, MT9T001_OUTPUT_CONTROL, value);
if (ret < 0)
return ret;
mt9t001->output_control = value;
return 0;
}
static int mt9t001_reset(struct mt9t001 *mt9t001)
{
struct i2c_client *client = v4l2_get_subdevdata(&mt9t001->subdev);
int ret;
ret = mt9t001_write(client, MT9T001_RESET, 1);
if (ret < 0)
return ret;
ret = mt9t001_write(client, MT9T001_RESET, 0);
if (ret < 0)
return ret;
mt9t001->output_control = MT9T001_OUTPUT_CONTROL_DEF;
return mt9t001_set_output_control(mt9t001,
MT9T001_OUTPUT_CONTROL_CHIP_ENABLE,
0);
}
static int mt9t001_power_on(struct mt9t001 *mt9t001)
{
int ret;
ret = regulator_bulk_enable(ARRAY_SIZE(mt9t001->regulators),
mt9t001->regulators);
if (ret < 0)
return ret;
ret = clk_prepare_enable(mt9t001->clk);
if (ret < 0)
regulator_bulk_disable(ARRAY_SIZE(mt9t001->regulators),
mt9t001->regulators);
return ret;
}
static void mt9t001_power_off(struct mt9t001 *mt9t001)
{
regulator_bulk_disable(ARRAY_SIZE(mt9t001->regulators),
mt9t001->regulators);
clk_disable_unprepare(mt9t001->clk);
}
static int __mt9t001_set_power(struct mt9t001 *mt9t001, bool on)
{
struct i2c_client *client = v4l2_get_subdevdata(&mt9t001->subdev);
int ret;
if (!on) {
mt9t001_power_off(mt9t001);
return 0;
}
ret = mt9t001_power_on(mt9t001);
if (ret < 0)
return ret;
ret = mt9t001_reset(mt9t001);
if (ret < 0) {
dev_err(&client->dev, "Failed to reset the camera\n");
return ret;
}
return v4l2_ctrl_handler_setup(&mt9t001->ctrls);
}
static struct v4l2_mbus_framefmt *
__mt9t001_get_pad_format(struct mt9t001 *mt9t001, struct v4l2_subdev_fh *fh,
unsigned int pad, enum v4l2_subdev_format_whence which)
{
switch (which) {
case V4L2_SUBDEV_FORMAT_TRY:
return v4l2_subdev_get_try_format(fh, pad);
case V4L2_SUBDEV_FORMAT_ACTIVE:
return &mt9t001->format;
default:
return NULL;
}
}
static struct v4l2_rect *
__mt9t001_get_pad_crop(struct mt9t001 *mt9t001, struct v4l2_subdev_fh *fh,
unsigned int pad, enum v4l2_subdev_format_whence which)
{
switch (which) {
case V4L2_SUBDEV_FORMAT_TRY:
return v4l2_subdev_get_try_crop(fh, pad);
case V4L2_SUBDEV_FORMAT_ACTIVE:
return &mt9t001->crop;
default:
return NULL;
}
}
static int mt9t001_s_stream(struct v4l2_subdev *subdev, int enable)
{
const u16 mode = MT9T001_OUTPUT_CONTROL_CHIP_ENABLE;
struct i2c_client *client = v4l2_get_subdevdata(subdev);
struct mt9t001_platform_data *pdata = client->dev.platform_data;
struct mt9t001 *mt9t001 = to_mt9t001(subdev);
struct v4l2_mbus_framefmt *format = &mt9t001->format;
struct v4l2_rect *crop = &mt9t001->crop;
unsigned int hratio;
unsigned int vratio;
int ret;
if (!enable)
return mt9t001_set_output_control(mt9t001, mode, 0);
if (pdata->clk_pol) {
ret = mt9t001_write(client, MT9T001_PIXEL_CLOCK,
MT9T001_PIXEL_CLOCK_INVERT);
if (ret < 0)
return ret;
}
hratio = DIV_ROUND_CLOSEST(crop->width, format->width);
vratio = DIV_ROUND_CLOSEST(crop->height, format->height);
ret = mt9t001_write(client, MT9T001_ROW_ADDRESS_MODE, hratio - 1);
if (ret < 0)
return ret;
ret = mt9t001_write(client, MT9T001_COLUMN_ADDRESS_MODE, vratio - 1);
if (ret < 0)
return ret;
ret = mt9t001_write(client, MT9T001_COLUMN_START, crop->left);
if (ret < 0)
return ret;
ret = mt9t001_write(client, MT9T001_ROW_START, crop->top);
if (ret < 0)
return ret;
ret = mt9t001_write(client, MT9T001_WINDOW_WIDTH, crop->width - 1);
if (ret < 0)
return ret;
ret = mt9t001_write(client, MT9T001_WINDOW_HEIGHT, crop->height - 1);
if (ret < 0)
return ret;
return mt9t001_set_output_control(mt9t001, 0, mode);
}
static int mt9t001_enum_mbus_code(struct v4l2_subdev *subdev,
struct v4l2_subdev_fh *fh,
struct v4l2_subdev_mbus_code_enum *code)
{
if (code->index > 0)
return -EINVAL;
code->code = V4L2_MBUS_FMT_SGRBG10_1X10;
return 0;
}
static int mt9t001_enum_frame_size(struct v4l2_subdev *subdev,
struct v4l2_subdev_fh *fh,
struct v4l2_subdev_frame_size_enum *fse)
{
if (fse->index >= 8 || fse->code != V4L2_MBUS_FMT_SGRBG10_1X10)
return -EINVAL;
fse->min_width = (MT9T001_WINDOW_WIDTH_DEF + 1) / fse->index;
fse->max_width = fse->min_width;
fse->min_height = (MT9T001_WINDOW_HEIGHT_DEF + 1) / fse->index;
fse->max_height = fse->min_height;
return 0;
}
static int mt9t001_get_format(struct v4l2_subdev *subdev,
struct v4l2_subdev_fh *fh,
struct v4l2_subdev_format *format)
{
struct mt9t001 *mt9t001 = to_mt9t001(subdev);
format->format = *__mt9t001_get_pad_format(mt9t001, fh, format->pad,
format->which);
return 0;
}
static int mt9t001_set_format(struct v4l2_subdev *subdev,
struct v4l2_subdev_fh *fh,
struct v4l2_subdev_format *format)
{
struct mt9t001 *mt9t001 = to_mt9t001(subdev);
struct v4l2_mbus_framefmt *__format;
struct v4l2_rect *__crop;
unsigned int width;
unsigned int height;
unsigned int hratio;
unsigned int vratio;
__crop = __mt9t001_get_pad_crop(mt9t001, fh, format->pad,
format->which);
width = clamp_t(unsigned int, ALIGN(format->format.width, 2),
max_t(unsigned int, __crop->width / 8,
MT9T001_WINDOW_HEIGHT_MIN + 1),
__crop->width);
height = clamp_t(unsigned int, ALIGN(format->format.height, 2),
max_t(unsigned int, __crop->height / 8,
MT9T001_WINDOW_HEIGHT_MIN + 1),
__crop->height);
hratio = DIV_ROUND_CLOSEST(__crop->width, width);
vratio = DIV_ROUND_CLOSEST(__crop->height, height);
__format = __mt9t001_get_pad_format(mt9t001, fh, format->pad,
format->which);
__format->width = __crop->width / hratio;
__format->height = __crop->height / vratio;
format->format = *__format;
return 0;
}
static int mt9t001_get_crop(struct v4l2_subdev *subdev,
struct v4l2_subdev_fh *fh,
struct v4l2_subdev_crop *crop)
{
struct mt9t001 *mt9t001 = to_mt9t001(subdev);
crop->rect = *__mt9t001_get_pad_crop(mt9t001, fh, crop->pad,
crop->which);
return 0;
}
static int mt9t001_set_crop(struct v4l2_subdev *subdev,
struct v4l2_subdev_fh *fh,
struct v4l2_subdev_crop *crop)
{
struct mt9t001 *mt9t001 = to_mt9t001(subdev);
struct v4l2_mbus_framefmt *__format;
struct v4l2_rect *__crop;
struct v4l2_rect rect;
rect.left = clamp(ALIGN(crop->rect.left, 2),
MT9T001_COLUMN_START_MIN,
MT9T001_COLUMN_START_MAX);
rect.top = clamp(ALIGN(crop->rect.top, 2),
MT9T001_ROW_START_MIN,
MT9T001_ROW_START_MAX);
rect.width = clamp_t(unsigned int, ALIGN(crop->rect.width, 2),
MT9T001_WINDOW_WIDTH_MIN + 1,
MT9T001_WINDOW_WIDTH_MAX + 1);
rect.height = clamp_t(unsigned int, ALIGN(crop->rect.height, 2),
MT9T001_WINDOW_HEIGHT_MIN + 1,
MT9T001_WINDOW_HEIGHT_MAX + 1);
rect.width = min_t(unsigned int, rect.width,
MT9T001_PIXEL_ARRAY_WIDTH - rect.left);
rect.height = min_t(unsigned int, rect.height,
MT9T001_PIXEL_ARRAY_HEIGHT - rect.top);
__crop = __mt9t001_get_pad_crop(mt9t001, fh, crop->pad, crop->which);
if (rect.width != __crop->width || rect.height != __crop->height) {
__format = __mt9t001_get_pad_format(mt9t001, fh, crop->pad,
crop->which);
__format->width = rect.width;
__format->height = rect.height;
}
*__crop = rect;
crop->rect = rect;
return 0;
}
static u16 mt9t001_gain_value(s32 *gain)
{
if (*gain <= 32)
return *gain;
if (*gain <= 64) {
*gain &= ~1;
return (1 << 6) | (*gain >> 1);
}
*gain &= ~7;
return ((*gain - 64) << 5) | (1 << 6) | 32;
}
static int mt9t001_ctrl_freeze(struct mt9t001 *mt9t001, bool freeze)
{
return mt9t001_set_output_control(mt9t001,
freeze ? 0 : MT9T001_OUTPUT_CONTROL_SYNC,
freeze ? MT9T001_OUTPUT_CONTROL_SYNC : 0);
}
static int mt9t001_s_ctrl(struct v4l2_ctrl *ctrl)
{
static const u8 gains[4] = {
MT9T001_RED_GAIN, MT9T001_GREEN1_GAIN,
MT9T001_GREEN2_GAIN, MT9T001_BLUE_GAIN
};
struct mt9t001 *mt9t001 =
container_of(ctrl->handler, struct mt9t001, ctrls);
struct i2c_client *client = v4l2_get_subdevdata(&mt9t001->subdev);
unsigned int count;
unsigned int i;
u16 value;
int ret;
switch (ctrl->id) {
case V4L2_CID_GAIN_RED:
case V4L2_CID_GAIN_GREEN_RED:
case V4L2_CID_GAIN_GREEN_BLUE:
case V4L2_CID_GAIN_BLUE:
for (i = 0, count = 0; i < 4; ++i) {
struct v4l2_ctrl *gain = mt9t001->gains[i];
if (gain->val != gain->cur.val)
count++;
}
if (count > 1) {
ret = mt9t001_ctrl_freeze(mt9t001, true);
if (ret < 0)
return ret;
}
for (i = 0; i < 4; ++i) {
struct v4l2_ctrl *gain = mt9t001->gains[i];
if (gain->val == gain->cur.val)
continue;
value = mt9t001_gain_value(&gain->val);
ret = mt9t001_write(client, gains[i], value);
if (ret < 0) {
mt9t001_ctrl_freeze(mt9t001, false);
return ret;
}
}
if (count > 1) {
ret = mt9t001_ctrl_freeze(mt9t001, false);
if (ret < 0)
return ret;
}
break;
case V4L2_CID_EXPOSURE:
ret = mt9t001_write(client, MT9T001_SHUTTER_WIDTH_LOW,
ctrl->val & 0xffff);
if (ret < 0)
return ret;
return mt9t001_write(client, MT9T001_SHUTTER_WIDTH_HIGH,
ctrl->val >> 16);
case V4L2_CID_TEST_PATTERN:
return mt9t001_set_output_control(mt9t001,
ctrl->val ? 0 : MT9T001_OUTPUT_CONTROL_TEST_DATA,
ctrl->val ? MT9T001_OUTPUT_CONTROL_TEST_DATA : 0);
case V4L2_CID_TEST_PATTERN_COLOR:
return mt9t001_write(client, MT9T001_TEST_DATA, ctrl->val << 2);
case V4L2_CID_BLACK_LEVEL_AUTO:
value = ctrl->val ? 0 : MT9T001_BLACK_LEVEL_OVERRIDE;
ret = mt9t001_write(client, MT9T001_BLACK_LEVEL_CALIBRATION,
value);
if (ret < 0)
return ret;
mt9t001->black_level = value;
break;
case V4L2_CID_BLACK_LEVEL_OFFSET:
ret = mt9t001_write(client, MT9T001_GREEN1_OFFSET, ctrl->val);
if (ret < 0)
return ret;
ret = mt9t001_write(client, MT9T001_GREEN2_OFFSET, ctrl->val);
if (ret < 0)
return ret;
ret = mt9t001_write(client, MT9T001_RED_OFFSET, ctrl->val);
if (ret < 0)
return ret;
return mt9t001_write(client, MT9T001_BLUE_OFFSET, ctrl->val);
case V4L2_CID_BLACK_LEVEL_CALIBRATE:
return mt9t001_write(client, MT9T001_BLACK_LEVEL_CALIBRATION,
MT9T001_BLACK_LEVEL_RECALCULATE |
mt9t001->black_level);
}
return 0;
}
static int mt9t001_set_power(struct v4l2_subdev *subdev, int on)
{
struct mt9t001 *mt9t001 = to_mt9t001(subdev);
int ret = 0;
mutex_lock(&mt9t001->power_lock);
if (mt9t001->power_count == !on) {
ret = __mt9t001_set_power(mt9t001, !!on);
if (ret < 0)
goto out;
}
mt9t001->power_count += on ? 1 : -1;
WARN_ON(mt9t001->power_count < 0);
out:
mutex_unlock(&mt9t001->power_lock);
return ret;
}
static int mt9t001_registered(struct v4l2_subdev *subdev)
{
struct i2c_client *client = v4l2_get_subdevdata(subdev);
struct mt9t001 *mt9t001 = to_mt9t001(subdev);
s32 data;
int ret;
ret = mt9t001_power_on(mt9t001);
if (ret < 0) {
dev_err(&client->dev, "MT9T001 power up failed\n");
return ret;
}
data = mt9t001_read(client, MT9T001_CHIP_VERSION);
mt9t001_power_off(mt9t001);
if (data != MT9T001_CHIP_ID) {
dev_err(&client->dev,
"MT9T001 not detected, wrong version 0x%04x\n", data);
return -ENODEV;
}
dev_info(&client->dev, "MT9T001 detected at address 0x%02x\n",
client->addr);
return 0;
}
static int mt9t001_open(struct v4l2_subdev *subdev, struct v4l2_subdev_fh *fh)
{
struct v4l2_mbus_framefmt *format;
struct v4l2_rect *crop;
crop = v4l2_subdev_get_try_crop(fh, 0);
crop->left = MT9T001_COLUMN_START_DEF;
crop->top = MT9T001_ROW_START_DEF;
crop->width = MT9T001_WINDOW_WIDTH_DEF + 1;
crop->height = MT9T001_WINDOW_HEIGHT_DEF + 1;
format = v4l2_subdev_get_try_format(fh, 0);
format->code = V4L2_MBUS_FMT_SGRBG10_1X10;
format->width = MT9T001_WINDOW_WIDTH_DEF + 1;
format->height = MT9T001_WINDOW_HEIGHT_DEF + 1;
format->field = V4L2_FIELD_NONE;
format->colorspace = V4L2_COLORSPACE_SRGB;
return mt9t001_set_power(subdev, 1);
}
static int mt9t001_close(struct v4l2_subdev *subdev, struct v4l2_subdev_fh *fh)
{
return mt9t001_set_power(subdev, 0);
}
static int mt9t001_probe(struct i2c_client *client,
const struct i2c_device_id *did)
{
struct mt9t001_platform_data *pdata = client->dev.platform_data;
struct mt9t001 *mt9t001;
unsigned int i;
int ret;
if (pdata == NULL) {
dev_err(&client->dev, "No platform data\n");
return -EINVAL;
}
if (!i2c_check_functionality(client->adapter,
I2C_FUNC_SMBUS_WORD_DATA)) {
dev_warn(&client->adapter->dev,
"I2C-Adapter doesn't support I2C_FUNC_SMBUS_WORD\n");
return -EIO;
}
mt9t001 = devm_kzalloc(&client->dev, sizeof(*mt9t001), GFP_KERNEL);
if (!mt9t001)
return -ENOMEM;
mutex_init(&mt9t001->power_lock);
mt9t001->output_control = MT9T001_OUTPUT_CONTROL_DEF;
mt9t001->regulators[0].supply = "vdd";
mt9t001->regulators[1].supply = "vaa";
ret = devm_regulator_bulk_get(&client->dev, 2, mt9t001->regulators);
if (ret < 0) {
dev_err(&client->dev, "Unable to get regulators\n");
return ret;
}
mt9t001->clk = devm_clk_get(&client->dev, NULL);
if (IS_ERR(mt9t001->clk)) {
dev_err(&client->dev, "Unable to get clock\n");
return PTR_ERR(mt9t001->clk);
}
v4l2_ctrl_handler_init(&mt9t001->ctrls, ARRAY_SIZE(mt9t001_ctrls) +
ARRAY_SIZE(mt9t001_gains) + 4);
v4l2_ctrl_new_std(&mt9t001->ctrls, &mt9t001_ctrl_ops,
V4L2_CID_EXPOSURE, MT9T001_SHUTTER_WIDTH_MIN,
MT9T001_SHUTTER_WIDTH_MAX, 1,
MT9T001_SHUTTER_WIDTH_DEF);
v4l2_ctrl_new_std(&mt9t001->ctrls, &mt9t001_ctrl_ops,
V4L2_CID_BLACK_LEVEL, 1, 1, 1, 1);
v4l2_ctrl_new_std(&mt9t001->ctrls, &mt9t001_ctrl_ops,
V4L2_CID_PIXEL_RATE, pdata->ext_clk, pdata->ext_clk,
1, pdata->ext_clk);
v4l2_ctrl_new_std_menu_items(&mt9t001->ctrls, &mt9t001_ctrl_ops,
V4L2_CID_TEST_PATTERN,
ARRAY_SIZE(mt9t001_test_pattern_menu) - 1, 0,
0, mt9t001_test_pattern_menu);
for (i = 0; i < ARRAY_SIZE(mt9t001_ctrls); ++i)
v4l2_ctrl_new_custom(&mt9t001->ctrls, &mt9t001_ctrls[i], NULL);
for (i = 0; i < ARRAY_SIZE(mt9t001_gains); ++i)
mt9t001->gains[i] = v4l2_ctrl_new_custom(&mt9t001->ctrls,
&mt9t001_gains[i], NULL);
v4l2_ctrl_cluster(ARRAY_SIZE(mt9t001_gains), mt9t001->gains);
mt9t001->subdev.ctrl_handler = &mt9t001->ctrls;
if (mt9t001->ctrls.error) {
printk(KERN_INFO "%s: control initialization error %d\n",
__func__, mt9t001->ctrls.error);
ret = -EINVAL;
goto done;
}
mt9t001->crop.left = MT9T001_COLUMN_START_DEF;
mt9t001->crop.top = MT9T001_ROW_START_DEF;
mt9t001->crop.width = MT9T001_WINDOW_WIDTH_DEF + 1;
mt9t001->crop.height = MT9T001_WINDOW_HEIGHT_DEF + 1;
mt9t001->format.code = V4L2_MBUS_FMT_SGRBG10_1X10;
mt9t001->format.width = MT9T001_WINDOW_WIDTH_DEF + 1;
mt9t001->format.height = MT9T001_WINDOW_HEIGHT_DEF + 1;
mt9t001->format.field = V4L2_FIELD_NONE;
mt9t001->format.colorspace = V4L2_COLORSPACE_SRGB;
v4l2_i2c_subdev_init(&mt9t001->subdev, client, &mt9t001_subdev_ops);
mt9t001->subdev.internal_ops = &mt9t001_subdev_internal_ops;
mt9t001->subdev.flags |= V4L2_SUBDEV_FL_HAS_DEVNODE;
mt9t001->pad.flags = MEDIA_PAD_FL_SOURCE;
ret = media_entity_init(&mt9t001->subdev.entity, 1, &mt9t001->pad, 0);
done:
if (ret < 0) {
v4l2_ctrl_handler_free(&mt9t001->ctrls);
media_entity_cleanup(&mt9t001->subdev.entity);
}
return ret;
}
static int mt9t001_remove(struct i2c_client *client)
{
struct v4l2_subdev *subdev = i2c_get_clientdata(client);
struct mt9t001 *mt9t001 = to_mt9t001(subdev);
v4l2_ctrl_handler_free(&mt9t001->ctrls);
v4l2_device_unregister_subdev(subdev);
media_entity_cleanup(&subdev->entity);
return 0;
}
