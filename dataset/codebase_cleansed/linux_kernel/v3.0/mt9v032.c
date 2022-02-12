static struct mt9v032 *to_mt9v032(struct v4l2_subdev *sd)
{
return container_of(sd, struct mt9v032, subdev);
}
static int mt9v032_read(struct i2c_client *client, const u8 reg)
{
s32 data = i2c_smbus_read_word_data(client, reg);
dev_dbg(&client->dev, "%s: read 0x%04x from 0x%02x\n", __func__,
swab16(data), reg);
return data < 0 ? data : swab16(data);
}
static int mt9v032_write(struct i2c_client *client, const u8 reg,
const u16 data)
{
dev_dbg(&client->dev, "%s: writing 0x%04x to 0x%02x\n", __func__,
data, reg);
return i2c_smbus_write_word_data(client, reg, swab16(data));
}
static int mt9v032_set_chip_control(struct mt9v032 *mt9v032, u16 clear, u16 set)
{
struct i2c_client *client = v4l2_get_subdevdata(&mt9v032->subdev);
u16 value = (mt9v032->chip_control & ~clear) | set;
int ret;
ret = mt9v032_write(client, MT9V032_CHIP_CONTROL, value);
if (ret < 0)
return ret;
mt9v032->chip_control = value;
return 0;
}
static int
mt9v032_update_aec_agc(struct mt9v032 *mt9v032, u16 which, int enable)
{
struct i2c_client *client = v4l2_get_subdevdata(&mt9v032->subdev);
u16 value = mt9v032->aec_agc;
int ret;
if (enable)
value |= which;
else
value &= ~which;
ret = mt9v032_write(client, MT9V032_AEC_AGC_ENABLE, value);
if (ret < 0)
return ret;
mt9v032->aec_agc = value;
return 0;
}
static int mt9v032_power_on(struct mt9v032 *mt9v032)
{
struct i2c_client *client = v4l2_get_subdevdata(&mt9v032->subdev);
int ret;
if (mt9v032->pdata->set_clock) {
mt9v032->pdata->set_clock(&mt9v032->subdev, 25000000);
udelay(1);
}
ret = mt9v032_write(client, MT9V032_RESET, 1);
if (ret < 0)
return ret;
ret = mt9v032_write(client, MT9V032_RESET, 0);
if (ret < 0)
return ret;
return mt9v032_write(client, MT9V032_CHIP_CONTROL, 0);
}
static void mt9v032_power_off(struct mt9v032 *mt9v032)
{
if (mt9v032->pdata->set_clock)
mt9v032->pdata->set_clock(&mt9v032->subdev, 0);
}
static int __mt9v032_set_power(struct mt9v032 *mt9v032, bool on)
{
struct i2c_client *client = v4l2_get_subdevdata(&mt9v032->subdev);
int ret;
if (!on) {
mt9v032_power_off(mt9v032);
return 0;
}
ret = mt9v032_power_on(mt9v032);
if (ret < 0)
return ret;
if (mt9v032->pdata && mt9v032->pdata->clk_pol) {
ret = mt9v032_write(client, MT9V032_PIXEL_CLOCK,
MT9V032_PIXEL_CLOCK_INV_PXL_CLK);
if (ret < 0)
return ret;
}
ret = mt9v032_write(client, MT9V032_ROW_NOISE_CORR_CONTROL, 0);
if (ret < 0)
return ret;
return v4l2_ctrl_handler_setup(&mt9v032->ctrls);
}
static struct v4l2_mbus_framefmt *
__mt9v032_get_pad_format(struct mt9v032 *mt9v032, struct v4l2_subdev_fh *fh,
unsigned int pad, enum v4l2_subdev_format_whence which)
{
switch (which) {
case V4L2_SUBDEV_FORMAT_TRY:
return v4l2_subdev_get_try_format(fh, pad);
case V4L2_SUBDEV_FORMAT_ACTIVE:
return &mt9v032->format;
default:
return NULL;
}
}
static struct v4l2_rect *
__mt9v032_get_pad_crop(struct mt9v032 *mt9v032, struct v4l2_subdev_fh *fh,
unsigned int pad, enum v4l2_subdev_format_whence which)
{
switch (which) {
case V4L2_SUBDEV_FORMAT_TRY:
return v4l2_subdev_get_try_crop(fh, pad);
case V4L2_SUBDEV_FORMAT_ACTIVE:
return &mt9v032->crop;
default:
return NULL;
}
}
static int mt9v032_s_stream(struct v4l2_subdev *subdev, int enable)
{
const u16 mode = MT9V032_CHIP_CONTROL_MASTER_MODE
| MT9V032_CHIP_CONTROL_DOUT_ENABLE
| MT9V032_CHIP_CONTROL_SEQUENTIAL;
struct i2c_client *client = v4l2_get_subdevdata(subdev);
struct mt9v032 *mt9v032 = to_mt9v032(subdev);
struct v4l2_mbus_framefmt *format = &mt9v032->format;
struct v4l2_rect *crop = &mt9v032->crop;
unsigned int hratio;
unsigned int vratio;
int ret;
if (!enable)
return mt9v032_set_chip_control(mt9v032, mode, 0);
hratio = DIV_ROUND_CLOSEST(crop->width, format->width);
vratio = DIV_ROUND_CLOSEST(crop->height, format->height);
ret = mt9v032_write(client, MT9V032_READ_MODE,
(hratio - 1) << MT9V032_READ_MODE_ROW_BIN_SHIFT |
(vratio - 1) << MT9V032_READ_MODE_COLUMN_BIN_SHIFT);
if (ret < 0)
return ret;
ret = mt9v032_write(client, MT9V032_COLUMN_START, crop->left);
if (ret < 0)
return ret;
ret = mt9v032_write(client, MT9V032_ROW_START, crop->top);
if (ret < 0)
return ret;
ret = mt9v032_write(client, MT9V032_WINDOW_WIDTH, crop->width);
if (ret < 0)
return ret;
ret = mt9v032_write(client, MT9V032_WINDOW_HEIGHT, crop->height);
if (ret < 0)
return ret;
ret = mt9v032_write(client, MT9V032_HORIZONTAL_BLANKING,
max(43, 660 - crop->width));
if (ret < 0)
return ret;
return mt9v032_set_chip_control(mt9v032, 0, mode);
}
static int mt9v032_enum_mbus_code(struct v4l2_subdev *subdev,
struct v4l2_subdev_fh *fh,
struct v4l2_subdev_mbus_code_enum *code)
{
if (code->index > 0)
return -EINVAL;
code->code = V4L2_MBUS_FMT_SGRBG10_1X10;
return 0;
}
static int mt9v032_enum_frame_size(struct v4l2_subdev *subdev,
struct v4l2_subdev_fh *fh,
struct v4l2_subdev_frame_size_enum *fse)
{
if (fse->index >= 8 || fse->code != V4L2_MBUS_FMT_SGRBG10_1X10)
return -EINVAL;
fse->min_width = MT9V032_WINDOW_WIDTH_DEF / fse->index;
fse->max_width = fse->min_width;
fse->min_height = MT9V032_WINDOW_HEIGHT_DEF / fse->index;
fse->max_height = fse->min_height;
return 0;
}
static int mt9v032_get_format(struct v4l2_subdev *subdev,
struct v4l2_subdev_fh *fh,
struct v4l2_subdev_format *format)
{
struct mt9v032 *mt9v032 = to_mt9v032(subdev);
format->format = *__mt9v032_get_pad_format(mt9v032, fh, format->pad,
format->which);
return 0;
}
static int mt9v032_set_format(struct v4l2_subdev *subdev,
struct v4l2_subdev_fh *fh,
struct v4l2_subdev_format *format)
{
struct mt9v032 *mt9v032 = to_mt9v032(subdev);
struct v4l2_mbus_framefmt *__format;
struct v4l2_rect *__crop;
unsigned int width;
unsigned int height;
unsigned int hratio;
unsigned int vratio;
__crop = __mt9v032_get_pad_crop(mt9v032, fh, format->pad,
format->which);
width = clamp_t(unsigned int, ALIGN(format->format.width, 2),
max(__crop->width / 8, MT9V032_WINDOW_WIDTH_MIN),
__crop->width);
height = clamp_t(unsigned int, ALIGN(format->format.height, 2),
max(__crop->height / 8, MT9V032_WINDOW_HEIGHT_MIN),
__crop->height);
hratio = DIV_ROUND_CLOSEST(__crop->width, width);
vratio = DIV_ROUND_CLOSEST(__crop->height, height);
__format = __mt9v032_get_pad_format(mt9v032, fh, format->pad,
format->which);
__format->width = __crop->width / hratio;
__format->height = __crop->height / vratio;
format->format = *__format;
return 0;
}
static int mt9v032_get_crop(struct v4l2_subdev *subdev,
struct v4l2_subdev_fh *fh,
struct v4l2_subdev_crop *crop)
{
struct mt9v032 *mt9v032 = to_mt9v032(subdev);
crop->rect = *__mt9v032_get_pad_crop(mt9v032, fh, crop->pad,
crop->which);
return 0;
}
static int mt9v032_set_crop(struct v4l2_subdev *subdev,
struct v4l2_subdev_fh *fh,
struct v4l2_subdev_crop *crop)
{
struct mt9v032 *mt9v032 = to_mt9v032(subdev);
struct v4l2_mbus_framefmt *__format;
struct v4l2_rect *__crop;
struct v4l2_rect rect;
rect.left = clamp(ALIGN(crop->rect.left, 2),
MT9V032_COLUMN_START_MIN,
MT9V032_COLUMN_START_MAX);
rect.top = clamp(ALIGN(crop->rect.top, 2),
MT9V032_ROW_START_MIN,
MT9V032_ROW_START_MAX);
rect.width = clamp(ALIGN(crop->rect.width, 2),
MT9V032_WINDOW_WIDTH_MIN,
MT9V032_WINDOW_WIDTH_MAX);
rect.height = clamp(ALIGN(crop->rect.height, 2),
MT9V032_WINDOW_HEIGHT_MIN,
MT9V032_WINDOW_HEIGHT_MAX);
rect.width = min(rect.width, MT9V032_PIXEL_ARRAY_WIDTH - rect.left);
rect.height = min(rect.height, MT9V032_PIXEL_ARRAY_HEIGHT - rect.top);
__crop = __mt9v032_get_pad_crop(mt9v032, fh, crop->pad, crop->which);
if (rect.width != __crop->width || rect.height != __crop->height) {
__format = __mt9v032_get_pad_format(mt9v032, fh, crop->pad,
crop->which);
__format->width = rect.width;
__format->height = rect.height;
}
*__crop = rect;
crop->rect = rect;
return 0;
}
static int mt9v032_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct mt9v032 *mt9v032 =
container_of(ctrl->handler, struct mt9v032, ctrls);
struct i2c_client *client = v4l2_get_subdevdata(&mt9v032->subdev);
u16 data;
switch (ctrl->id) {
case V4L2_CID_AUTOGAIN:
return mt9v032_update_aec_agc(mt9v032, MT9V032_AGC_ENABLE,
ctrl->val);
case V4L2_CID_GAIN:
return mt9v032_write(client, MT9V032_ANALOG_GAIN, ctrl->val);
case V4L2_CID_EXPOSURE_AUTO:
return mt9v032_update_aec_agc(mt9v032, MT9V032_AEC_ENABLE,
ctrl->val);
case V4L2_CID_EXPOSURE:
return mt9v032_write(client, MT9V032_TOTAL_SHUTTER_WIDTH,
ctrl->val);
case V4L2_CID_TEST_PATTERN:
switch (ctrl->val) {
case 0:
data = 0;
break;
case 1:
data = MT9V032_TEST_PATTERN_GRAY_VERTICAL
| MT9V032_TEST_PATTERN_ENABLE;
break;
case 2:
data = MT9V032_TEST_PATTERN_GRAY_HORIZONTAL
| MT9V032_TEST_PATTERN_ENABLE;
break;
case 3:
data = MT9V032_TEST_PATTERN_GRAY_DIAGONAL
| MT9V032_TEST_PATTERN_ENABLE;
break;
default:
data = (ctrl->val << MT9V032_TEST_PATTERN_DATA_SHIFT)
| MT9V032_TEST_PATTERN_USE_DATA
| MT9V032_TEST_PATTERN_ENABLE
| MT9V032_TEST_PATTERN_FLIP;
break;
}
return mt9v032_write(client, MT9V032_TEST_PATTERN, data);
}
return 0;
}
static int mt9v032_set_power(struct v4l2_subdev *subdev, int on)
{
struct mt9v032 *mt9v032 = to_mt9v032(subdev);
int ret = 0;
mutex_lock(&mt9v032->power_lock);
if (mt9v032->power_count == !on) {
ret = __mt9v032_set_power(mt9v032, !!on);
if (ret < 0)
goto done;
}
mt9v032->power_count += on ? 1 : -1;
WARN_ON(mt9v032->power_count < 0);
done:
mutex_unlock(&mt9v032->power_lock);
return ret;
}
static int mt9v032_registered(struct v4l2_subdev *subdev)
{
struct i2c_client *client = v4l2_get_subdevdata(subdev);
struct mt9v032 *mt9v032 = to_mt9v032(subdev);
s32 data;
int ret;
dev_info(&client->dev, "Probing MT9V032 at address 0x%02x\n",
client->addr);
ret = mt9v032_power_on(mt9v032);
if (ret < 0) {
dev_err(&client->dev, "MT9V032 power up failed\n");
return ret;
}
data = mt9v032_read(client, MT9V032_CHIP_VERSION);
if (data != MT9V032_CHIP_ID_REV1 && data != MT9V032_CHIP_ID_REV3) {
dev_err(&client->dev, "MT9V032 not detected, wrong version "
"0x%04x\n", data);
return -ENODEV;
}
mt9v032_power_off(mt9v032);
dev_info(&client->dev, "MT9V032 detected at address 0x%02x\n",
client->addr);
return ret;
}
static int mt9v032_open(struct v4l2_subdev *subdev, struct v4l2_subdev_fh *fh)
{
struct v4l2_mbus_framefmt *format;
struct v4l2_rect *crop;
crop = v4l2_subdev_get_try_crop(fh, 0);
crop->left = MT9V032_COLUMN_START_DEF;
crop->top = MT9V032_ROW_START_DEF;
crop->width = MT9V032_WINDOW_WIDTH_DEF;
crop->height = MT9V032_WINDOW_HEIGHT_DEF;
format = v4l2_subdev_get_try_format(fh, 0);
format->code = V4L2_MBUS_FMT_SGRBG10_1X10;
format->width = MT9V032_WINDOW_WIDTH_DEF;
format->height = MT9V032_WINDOW_HEIGHT_DEF;
format->field = V4L2_FIELD_NONE;
format->colorspace = V4L2_COLORSPACE_SRGB;
return mt9v032_set_power(subdev, 1);
}
static int mt9v032_close(struct v4l2_subdev *subdev, struct v4l2_subdev_fh *fh)
{
return mt9v032_set_power(subdev, 0);
}
static int mt9v032_probe(struct i2c_client *client,
const struct i2c_device_id *did)
{
struct mt9v032 *mt9v032;
unsigned int i;
int ret;
if (!i2c_check_functionality(client->adapter,
I2C_FUNC_SMBUS_WORD_DATA)) {
dev_warn(&client->adapter->dev,
"I2C-Adapter doesn't support I2C_FUNC_SMBUS_WORD\n");
return -EIO;
}
mt9v032 = kzalloc(sizeof(*mt9v032), GFP_KERNEL);
if (!mt9v032)
return -ENOMEM;
mutex_init(&mt9v032->power_lock);
mt9v032->pdata = client->dev.platform_data;
v4l2_ctrl_handler_init(&mt9v032->ctrls, ARRAY_SIZE(mt9v032_ctrls) + 4);
v4l2_ctrl_new_std(&mt9v032->ctrls, &mt9v032_ctrl_ops,
V4L2_CID_AUTOGAIN, 0, 1, 1, 1);
v4l2_ctrl_new_std(&mt9v032->ctrls, &mt9v032_ctrl_ops,
V4L2_CID_GAIN, MT9V032_ANALOG_GAIN_MIN,
MT9V032_ANALOG_GAIN_MAX, 1, MT9V032_ANALOG_GAIN_DEF);
v4l2_ctrl_new_std_menu(&mt9v032->ctrls, &mt9v032_ctrl_ops,
V4L2_CID_EXPOSURE_AUTO, V4L2_EXPOSURE_MANUAL, 0,
V4L2_EXPOSURE_AUTO);
v4l2_ctrl_new_std(&mt9v032->ctrls, &mt9v032_ctrl_ops,
V4L2_CID_EXPOSURE, MT9V032_TOTAL_SHUTTER_WIDTH_MIN,
MT9V032_TOTAL_SHUTTER_WIDTH_MAX, 1,
MT9V032_TOTAL_SHUTTER_WIDTH_DEF);
for (i = 0; i < ARRAY_SIZE(mt9v032_ctrls); ++i)
v4l2_ctrl_new_custom(&mt9v032->ctrls, &mt9v032_ctrls[i], NULL);
mt9v032->subdev.ctrl_handler = &mt9v032->ctrls;
if (mt9v032->ctrls.error)
printk(KERN_INFO "%s: control initialization error %d\n",
__func__, mt9v032->ctrls.error);
mt9v032->crop.left = MT9V032_COLUMN_START_DEF;
mt9v032->crop.top = MT9V032_ROW_START_DEF;
mt9v032->crop.width = MT9V032_WINDOW_WIDTH_DEF;
mt9v032->crop.height = MT9V032_WINDOW_HEIGHT_DEF;
mt9v032->format.code = V4L2_MBUS_FMT_SGRBG10_1X10;
mt9v032->format.width = MT9V032_WINDOW_WIDTH_DEF;
mt9v032->format.height = MT9V032_WINDOW_HEIGHT_DEF;
mt9v032->format.field = V4L2_FIELD_NONE;
mt9v032->format.colorspace = V4L2_COLORSPACE_SRGB;
mt9v032->aec_agc = MT9V032_AEC_ENABLE | MT9V032_AGC_ENABLE;
v4l2_i2c_subdev_init(&mt9v032->subdev, client, &mt9v032_subdev_ops);
mt9v032->subdev.internal_ops = &mt9v032_subdev_internal_ops;
mt9v032->subdev.flags |= V4L2_SUBDEV_FL_HAS_DEVNODE;
mt9v032->pad.flags = MEDIA_PAD_FL_SOURCE;
ret = media_entity_init(&mt9v032->subdev.entity, 1, &mt9v032->pad, 0);
if (ret < 0)
kfree(mt9v032);
return ret;
}
static int mt9v032_remove(struct i2c_client *client)
{
struct v4l2_subdev *subdev = i2c_get_clientdata(client);
struct mt9v032 *mt9v032 = to_mt9v032(subdev);
v4l2_device_unregister_subdev(subdev);
media_entity_cleanup(&subdev->entity);
kfree(mt9v032);
return 0;
}
static int __init mt9v032_init(void)
{
return i2c_add_driver(&mt9v032_driver);
}
static void __exit mt9v032_exit(void)
{
i2c_del_driver(&mt9v032_driver);
}
