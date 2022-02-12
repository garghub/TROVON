static int mt9m032_read(struct i2c_client *client, u8 reg)
{
return i2c_smbus_read_word_swapped(client, reg);
}
static int mt9m032_write(struct i2c_client *client, u8 reg, const u16 data)
{
return i2c_smbus_write_word_swapped(client, reg, data);
}
static u32 mt9m032_row_time(struct mt9m032 *sensor, unsigned int width)
{
unsigned int effective_width;
u32 ns;
effective_width = width + 716;
ns = div_u64(1000000000ULL * effective_width, sensor->pix_clock);
dev_dbg(to_dev(sensor), "MT9M032 line time: %u ns\n", ns);
return ns;
}
static int mt9m032_update_timing(struct mt9m032 *sensor,
struct v4l2_fract *interval)
{
struct i2c_client *client = v4l2_get_subdevdata(&sensor->subdev);
struct v4l2_rect *crop = &sensor->crop;
unsigned int min_vblank;
unsigned int vblank;
u32 row_time;
if (!interval)
interval = &sensor->frame_interval;
row_time = mt9m032_row_time(sensor, crop->width);
vblank = div_u64(1000000000ULL * interval->numerator,
(u64)row_time * interval->denominator)
- crop->height;
if (vblank > MT9M032_VBLANK_MAX) {
interval->denominator = 1000;
interval->numerator =
div_u64((crop->height + MT9M032_VBLANK_MAX) *
(u64)row_time * interval->denominator,
1000000000ULL);
vblank = div_u64(1000000000ULL * interval->numerator,
(u64)row_time * interval->denominator)
- crop->height;
}
min_vblank = 1600000 / row_time;
vblank = clamp_t(unsigned int, vblank, min_vblank, MT9M032_VBLANK_MAX);
return mt9m032_write(client, MT9M032_VBLANK, vblank);
}
static int mt9m032_update_geom_timing(struct mt9m032 *sensor)
{
struct i2c_client *client = v4l2_get_subdevdata(&sensor->subdev);
int ret;
ret = mt9m032_write(client, MT9M032_COLUMN_SIZE,
sensor->crop.width - 1);
if (!ret)
ret = mt9m032_write(client, MT9M032_ROW_SIZE,
sensor->crop.height - 1);
if (!ret)
ret = mt9m032_write(client, MT9M032_COLUMN_START,
sensor->crop.left);
if (!ret)
ret = mt9m032_write(client, MT9M032_ROW_START,
sensor->crop.top);
if (!ret)
ret = mt9m032_update_timing(sensor, NULL);
return ret;
}
static int update_formatter2(struct mt9m032 *sensor, bool streaming)
{
struct i2c_client *client = v4l2_get_subdevdata(&sensor->subdev);
u16 reg_val = MT9M032_FORMATTER2_DOUT_EN
| 0x0070;
if (streaming)
reg_val |= MT9M032_FORMATTER2_PIXCLK_EN;
return mt9m032_write(client, MT9M032_FORMATTER2, reg_val);
}
static int mt9m032_setup_pll(struct mt9m032 *sensor)
{
static const struct aptina_pll_limits limits = {
.ext_clock_min = 8000000,
.ext_clock_max = 16500000,
.int_clock_min = 2000000,
.int_clock_max = 24000000,
.out_clock_min = 322000000,
.out_clock_max = 693000000,
.pix_clock_max = 99000000,
.n_min = 1,
.n_max = 64,
.m_min = 16,
.m_max = 255,
.p1_min = 6,
.p1_max = 7,
};
struct i2c_client *client = v4l2_get_subdevdata(&sensor->subdev);
struct mt9m032_platform_data *pdata = sensor->pdata;
struct aptina_pll pll;
u16 reg_val;
int ret;
pll.ext_clock = pdata->ext_clock;
pll.pix_clock = pdata->pix_clock;
ret = aptina_pll_calculate(&client->dev, &limits, &pll);
if (ret < 0)
return ret;
sensor->pix_clock = pdata->pix_clock;
ret = mt9m032_write(client, MT9M032_PLL_CONFIG1,
(pll.m << MT9M032_PLL_CONFIG1_MUL_SHIFT) |
((pll.n - 1) & MT9M032_PLL_CONFIG1_PREDIV_MASK));
if (!ret)
ret = mt9m032_write(client, MT9P031_PLL_CONTROL,
MT9P031_PLL_CONTROL_PWRON |
MT9P031_PLL_CONTROL_USEPLL);
if (!ret)
ret = mt9m032_write(client, MT9M032_READ_MODE1, 0x8000 |
MT9M032_READ_MODE1_STROBE_START_EXP |
MT9M032_READ_MODE1_STROBE_END_SHUTTER);
if (!ret) {
reg_val = (pll.p1 == 6 ? MT9M032_FORMATTER1_PLL_P1_6 : 0)
| MT9M032_FORMATTER1_PARALLEL | 0x001e;
ret = mt9m032_write(client, MT9M032_FORMATTER1, reg_val);
}
return ret;
}
static int mt9m032_enum_mbus_code(struct v4l2_subdev *subdev,
struct v4l2_subdev_fh *fh,
struct v4l2_subdev_mbus_code_enum *code)
{
if (code->index != 0)
return -EINVAL;
code->code = MEDIA_BUS_FMT_Y8_1X8;
return 0;
}
static int mt9m032_enum_frame_size(struct v4l2_subdev *subdev,
struct v4l2_subdev_fh *fh,
struct v4l2_subdev_frame_size_enum *fse)
{
if (fse->index != 0 || fse->code != MEDIA_BUS_FMT_Y8_1X8)
return -EINVAL;
fse->min_width = MT9M032_COLUMN_SIZE_DEF;
fse->max_width = MT9M032_COLUMN_SIZE_DEF;
fse->min_height = MT9M032_ROW_SIZE_DEF;
fse->max_height = MT9M032_ROW_SIZE_DEF;
return 0;
}
static struct v4l2_rect *
__mt9m032_get_pad_crop(struct mt9m032 *sensor, struct v4l2_subdev_fh *fh,
enum v4l2_subdev_format_whence which)
{
switch (which) {
case V4L2_SUBDEV_FORMAT_TRY:
return v4l2_subdev_get_try_crop(fh, 0);
case V4L2_SUBDEV_FORMAT_ACTIVE:
return &sensor->crop;
default:
return NULL;
}
}
static struct v4l2_mbus_framefmt *
__mt9m032_get_pad_format(struct mt9m032 *sensor, struct v4l2_subdev_fh *fh,
enum v4l2_subdev_format_whence which)
{
switch (which) {
case V4L2_SUBDEV_FORMAT_TRY:
return v4l2_subdev_get_try_format(fh, 0);
case V4L2_SUBDEV_FORMAT_ACTIVE:
return &sensor->format;
default:
return NULL;
}
}
static int mt9m032_get_pad_format(struct v4l2_subdev *subdev,
struct v4l2_subdev_fh *fh,
struct v4l2_subdev_format *fmt)
{
struct mt9m032 *sensor = to_mt9m032(subdev);
mutex_lock(&sensor->lock);
fmt->format = *__mt9m032_get_pad_format(sensor, fh, fmt->which);
mutex_unlock(&sensor->lock);
return 0;
}
static int mt9m032_set_pad_format(struct v4l2_subdev *subdev,
struct v4l2_subdev_fh *fh,
struct v4l2_subdev_format *fmt)
{
struct mt9m032 *sensor = to_mt9m032(subdev);
int ret;
mutex_lock(&sensor->lock);
if (sensor->streaming && fmt->which == V4L2_SUBDEV_FORMAT_ACTIVE) {
ret = -EBUSY;
goto done;
}
fmt->format = *__mt9m032_get_pad_format(sensor, fh, fmt->which);
ret = 0;
done:
mutex_unlock(&sensor->lock);
return ret;
}
static int mt9m032_get_pad_selection(struct v4l2_subdev *subdev,
struct v4l2_subdev_fh *fh,
struct v4l2_subdev_selection *sel)
{
struct mt9m032 *sensor = to_mt9m032(subdev);
if (sel->target != V4L2_SEL_TGT_CROP)
return -EINVAL;
mutex_lock(&sensor->lock);
sel->r = *__mt9m032_get_pad_crop(sensor, fh, sel->which);
mutex_unlock(&sensor->lock);
return 0;
}
static int mt9m032_set_pad_selection(struct v4l2_subdev *subdev,
struct v4l2_subdev_fh *fh,
struct v4l2_subdev_selection *sel)
{
struct mt9m032 *sensor = to_mt9m032(subdev);
struct v4l2_mbus_framefmt *format;
struct v4l2_rect *__crop;
struct v4l2_rect rect;
int ret = 0;
if (sel->target != V4L2_SEL_TGT_CROP)
return -EINVAL;
mutex_lock(&sensor->lock);
if (sensor->streaming && sel->which == V4L2_SUBDEV_FORMAT_ACTIVE) {
ret = -EBUSY;
goto done;
}
rect.left = clamp(ALIGN(sel->r.left, 2), MT9M032_COLUMN_START_MIN,
MT9M032_COLUMN_START_MAX);
rect.top = clamp(ALIGN(sel->r.top, 2), MT9M032_ROW_START_MIN,
MT9M032_ROW_START_MAX);
rect.width = clamp_t(unsigned int, ALIGN(sel->r.width, 2),
MT9M032_COLUMN_SIZE_MIN, MT9M032_COLUMN_SIZE_MAX);
rect.height = clamp_t(unsigned int, ALIGN(sel->r.height, 2),
MT9M032_ROW_SIZE_MIN, MT9M032_ROW_SIZE_MAX);
rect.width = min_t(unsigned int, rect.width,
MT9M032_PIXEL_ARRAY_WIDTH - rect.left);
rect.height = min_t(unsigned int, rect.height,
MT9M032_PIXEL_ARRAY_HEIGHT - rect.top);
__crop = __mt9m032_get_pad_crop(sensor, fh, sel->which);
if (rect.width != __crop->width || rect.height != __crop->height) {
format = __mt9m032_get_pad_format(sensor, fh, sel->which);
format->width = rect.width;
format->height = rect.height;
}
*__crop = rect;
sel->r = rect;
if (sel->which == V4L2_SUBDEV_FORMAT_ACTIVE)
ret = mt9m032_update_geom_timing(sensor);
done:
mutex_unlock(&sensor->lock);
return ret;
}
static int mt9m032_get_frame_interval(struct v4l2_subdev *subdev,
struct v4l2_subdev_frame_interval *fi)
{
struct mt9m032 *sensor = to_mt9m032(subdev);
mutex_lock(&sensor->lock);
memset(fi, 0, sizeof(*fi));
fi->interval = sensor->frame_interval;
mutex_unlock(&sensor->lock);
return 0;
}
static int mt9m032_set_frame_interval(struct v4l2_subdev *subdev,
struct v4l2_subdev_frame_interval *fi)
{
struct mt9m032 *sensor = to_mt9m032(subdev);
int ret;
mutex_lock(&sensor->lock);
if (sensor->streaming) {
ret = -EBUSY;
goto done;
}
if (fi->interval.denominator == 0)
fi->interval.denominator = 1;
ret = mt9m032_update_timing(sensor, &fi->interval);
if (!ret)
sensor->frame_interval = fi->interval;
done:
mutex_unlock(&sensor->lock);
return ret;
}
static int mt9m032_s_stream(struct v4l2_subdev *subdev, int streaming)
{
struct mt9m032 *sensor = to_mt9m032(subdev);
int ret;
mutex_lock(&sensor->lock);
ret = update_formatter2(sensor, streaming);
if (!ret)
sensor->streaming = streaming;
mutex_unlock(&sensor->lock);
return ret;
}
static int mt9m032_g_register(struct v4l2_subdev *sd,
struct v4l2_dbg_register *reg)
{
struct mt9m032 *sensor = to_mt9m032(sd);
struct i2c_client *client = v4l2_get_subdevdata(&sensor->subdev);
int val;
if (reg->reg > 0xff)
return -EINVAL;
val = mt9m032_read(client, reg->reg);
if (val < 0)
return -EIO;
reg->size = 2;
reg->val = val;
return 0;
}
static int mt9m032_s_register(struct v4l2_subdev *sd,
const struct v4l2_dbg_register *reg)
{
struct mt9m032 *sensor = to_mt9m032(sd);
struct i2c_client *client = v4l2_get_subdevdata(&sensor->subdev);
if (reg->reg > 0xff)
return -EINVAL;
return mt9m032_write(client, reg->reg, reg->val);
}
static int update_read_mode2(struct mt9m032 *sensor, bool vflip, bool hflip)
{
struct i2c_client *client = v4l2_get_subdevdata(&sensor->subdev);
int reg_val = (vflip << MT9M032_READ_MODE2_VFLIP_SHIFT)
| (hflip << MT9M032_READ_MODE2_HFLIP_SHIFT)
| MT9M032_READ_MODE2_ROW_BLC
| 0x0007;
return mt9m032_write(client, MT9M032_READ_MODE2, reg_val);
}
static int mt9m032_set_gain(struct mt9m032 *sensor, s32 val)
{
struct i2c_client *client = v4l2_get_subdevdata(&sensor->subdev);
int digital_gain_val;
int analog_mul;
int analog_gain_val;
u16 reg_val;
digital_gain_val = 51;
if (val < 63) {
analog_mul = 0;
analog_gain_val = val;
} else {
analog_mul = 1;
analog_gain_val = val / 2;
}
reg_val = ((digital_gain_val & MT9M032_GAIN_DIGITAL_MASK)
<< MT9M032_GAIN_DIGITAL_SHIFT)
| ((analog_mul & 1) << MT9M032_GAIN_AMUL_SHIFT)
| (analog_gain_val & MT9M032_GAIN_ANALOG_MASK);
return mt9m032_write(client, MT9M032_GAIN_ALL, reg_val);
}
static int mt9m032_try_ctrl(struct v4l2_ctrl *ctrl)
{
if (ctrl->id == V4L2_CID_GAIN && ctrl->val >= 63) {
ctrl->val &= ~1;
}
return 0;
}
static int mt9m032_set_ctrl(struct v4l2_ctrl *ctrl)
{
struct mt9m032 *sensor =
container_of(ctrl->handler, struct mt9m032, ctrls);
struct i2c_client *client = v4l2_get_subdevdata(&sensor->subdev);
int ret;
switch (ctrl->id) {
case V4L2_CID_GAIN:
return mt9m032_set_gain(sensor, ctrl->val);
case V4L2_CID_HFLIP:
return update_read_mode2(sensor, sensor->vflip->val,
sensor->hflip->val);
case V4L2_CID_EXPOSURE:
ret = mt9m032_write(client, MT9M032_SHUTTER_WIDTH_HIGH,
(ctrl->val >> 16) & 0xffff);
if (ret < 0)
return ret;
return mt9m032_write(client, MT9M032_SHUTTER_WIDTH_LOW,
ctrl->val & 0xffff);
}
return 0;
}
static int mt9m032_probe(struct i2c_client *client,
const struct i2c_device_id *devid)
{
struct mt9m032_platform_data *pdata = client->dev.platform_data;
struct i2c_adapter *adapter = client->adapter;
struct mt9m032 *sensor;
int chip_version;
int ret;
if (pdata == NULL) {
dev_err(&client->dev, "No platform data\n");
return -EINVAL;
}
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_WORD_DATA)) {
dev_warn(&client->dev,
"I2C-Adapter doesn't support I2C_FUNC_SMBUS_WORD\n");
return -EIO;
}
if (!client->dev.platform_data)
return -ENODEV;
sensor = devm_kzalloc(&client->dev, sizeof(*sensor), GFP_KERNEL);
if (sensor == NULL)
return -ENOMEM;
mutex_init(&sensor->lock);
sensor->pdata = pdata;
v4l2_i2c_subdev_init(&sensor->subdev, client, &mt9m032_ops);
sensor->subdev.flags |= V4L2_SUBDEV_FL_HAS_DEVNODE;
chip_version = mt9m032_read(client, MT9M032_CHIP_VERSION);
if (chip_version != MT9M032_CHIP_VERSION_VALUE) {
dev_err(&client->dev, "MT9M032 not detected, wrong version "
"0x%04x\n", chip_version);
ret = -ENODEV;
goto error_sensor;
}
dev_info(&client->dev, "MT9M032 detected at address 0x%02x\n",
client->addr);
sensor->frame_interval.numerator = 1;
sensor->frame_interval.denominator = 30;
sensor->crop.left = MT9M032_COLUMN_START_DEF;
sensor->crop.top = MT9M032_ROW_START_DEF;
sensor->crop.width = MT9M032_COLUMN_SIZE_DEF;
sensor->crop.height = MT9M032_ROW_SIZE_DEF;
sensor->format.width = sensor->crop.width;
sensor->format.height = sensor->crop.height;
sensor->format.code = MEDIA_BUS_FMT_Y8_1X8;
sensor->format.field = V4L2_FIELD_NONE;
sensor->format.colorspace = V4L2_COLORSPACE_SRGB;
v4l2_ctrl_handler_init(&sensor->ctrls, 5);
v4l2_ctrl_new_std(&sensor->ctrls, &mt9m032_ctrl_ops,
V4L2_CID_GAIN, 0, 127, 1, 64);
sensor->hflip = v4l2_ctrl_new_std(&sensor->ctrls,
&mt9m032_ctrl_ops,
V4L2_CID_HFLIP, 0, 1, 1, 0);
sensor->vflip = v4l2_ctrl_new_std(&sensor->ctrls,
&mt9m032_ctrl_ops,
V4L2_CID_VFLIP, 0, 1, 1, 0);
v4l2_ctrl_new_std(&sensor->ctrls, &mt9m032_ctrl_ops,
V4L2_CID_EXPOSURE, MT9M032_SHUTTER_WIDTH_MIN,
MT9M032_SHUTTER_WIDTH_MAX, 1,
MT9M032_SHUTTER_WIDTH_DEF);
v4l2_ctrl_new_std(&sensor->ctrls, &mt9m032_ctrl_ops,
V4L2_CID_PIXEL_RATE, pdata->pix_clock,
pdata->pix_clock, 1, pdata->pix_clock);
if (sensor->ctrls.error) {
ret = sensor->ctrls.error;
dev_err(&client->dev, "control initialization error %d\n", ret);
goto error_ctrl;
}
v4l2_ctrl_cluster(2, &sensor->hflip);
sensor->subdev.ctrl_handler = &sensor->ctrls;
sensor->pad.flags = MEDIA_PAD_FL_SOURCE;
ret = media_entity_init(&sensor->subdev.entity, 1, &sensor->pad, 0);
if (ret < 0)
goto error_ctrl;
ret = mt9m032_write(client, MT9M032_RESET, 1);
if (ret < 0)
goto error_entity;
ret = mt9m032_write(client, MT9M032_RESET, 0);
if (ret < 0)
goto error_entity;
ret = mt9m032_setup_pll(sensor);
if (ret < 0)
goto error_entity;
usleep_range(10000, 11000);
ret = v4l2_ctrl_handler_setup(&sensor->ctrls);
if (ret < 0)
goto error_entity;
ret = mt9m032_update_geom_timing(sensor);
if (ret < 0)
goto error_entity;
ret = mt9m032_write(client, 0x41, 0x0000);
if (ret < 0)
goto error_entity;
ret = mt9m032_write(client, 0x42, 0x0003);
if (ret < 0)
goto error_entity;
ret = mt9m032_write(client, 0x43, 0x0003);
if (ret < 0)
goto error_entity;
ret = mt9m032_write(client, 0x7f, 0x0000);
if (ret < 0)
goto error_entity;
if (sensor->pdata->invert_pixclock) {
ret = mt9m032_write(client, MT9M032_PIX_CLK_CTRL,
MT9M032_PIX_CLK_CTRL_INV_PIXCLK);
if (ret < 0)
goto error_entity;
}
ret = mt9m032_write(client, MT9M032_RESTART, 1);
if (ret < 0)
goto error_entity;
msleep(100);
ret = mt9m032_write(client, MT9M032_RESTART, 0);
if (ret < 0)
goto error_entity;
msleep(100);
ret = update_formatter2(sensor, false);
if (ret < 0)
goto error_entity;
return ret;
error_entity:
media_entity_cleanup(&sensor->subdev.entity);
error_ctrl:
v4l2_ctrl_handler_free(&sensor->ctrls);
error_sensor:
mutex_destroy(&sensor->lock);
return ret;
}
static int mt9m032_remove(struct i2c_client *client)
{
struct v4l2_subdev *subdev = i2c_get_clientdata(client);
struct mt9m032 *sensor = to_mt9m032(subdev);
v4l2_device_unregister_subdev(subdev);
v4l2_ctrl_handler_free(&sensor->ctrls);
media_entity_cleanup(&subdev->entity);
mutex_destroy(&sensor->lock);
return 0;
}
