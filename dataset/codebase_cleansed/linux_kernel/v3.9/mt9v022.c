static const struct mt9v022_datafmt *mt9v022_find_datafmt(
enum v4l2_mbus_pixelcode code, const struct mt9v022_datafmt *fmt,
int n)
{
int i;
for (i = 0; i < n; i++)
if (fmt[i].code == code)
return fmt + i;
return NULL;
}
static struct mt9v022 *to_mt9v022(const struct i2c_client *client)
{
return container_of(i2c_get_clientdata(client), struct mt9v022, subdev);
}
static int reg_read(struct i2c_client *client, const u8 reg)
{
return i2c_smbus_read_word_swapped(client, reg);
}
static int reg_write(struct i2c_client *client, const u8 reg,
const u16 data)
{
return i2c_smbus_write_word_swapped(client, reg, data);
}
static int reg_set(struct i2c_client *client, const u8 reg,
const u16 data)
{
int ret;
ret = reg_read(client, reg);
if (ret < 0)
return ret;
return reg_write(client, reg, ret | data);
}
static int reg_clear(struct i2c_client *client, const u8 reg,
const u16 data)
{
int ret;
ret = reg_read(client, reg);
if (ret < 0)
return ret;
return reg_write(client, reg, ret & ~data);
}
static int mt9v022_init(struct i2c_client *client)
{
struct mt9v022 *mt9v022 = to_mt9v022(client);
int ret;
mt9v022->chip_control |= 0x10;
ret = reg_write(client, MT9V022_CHIP_CONTROL, mt9v022->chip_control);
if (!ret)
ret = reg_write(client, MT9V022_READ_MODE, 0x300);
if (!ret)
ret = reg_set(client, MT9V022_AEC_AGC_ENABLE, 0x3);
if (!ret)
ret = reg_write(client, MT9V022_ANALOG_GAIN, 16);
if (!ret)
ret = reg_write(client, MT9V022_TOTAL_SHUTTER_WIDTH, 480);
if (!ret)
ret = reg_write(client, mt9v022->reg->max_total_shutter_width, 480);
if (!ret)
ret = reg_clear(client, MT9V022_BLACK_LEVEL_CALIB_CTRL, 1);
if (!ret)
ret = reg_write(client, MT9V022_DIGITAL_TEST_PATTERN, 0);
if (!ret)
return v4l2_ctrl_handler_setup(&mt9v022->hdl);
return ret;
}
static int mt9v022_s_stream(struct v4l2_subdev *sd, int enable)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct mt9v022 *mt9v022 = to_mt9v022(client);
if (enable) {
mt9v022->chip_control &= ~0x10;
if (is_mt9v022_rev3(mt9v022->chip_version) ||
is_mt9v024(mt9v022->chip_version)) {
if (reg_clear(client, MT9V022_REG32, 0x204))
return -EIO;
}
} else {
mt9v022->chip_control |= 0x10;
if (is_mt9v022_rev3(mt9v022->chip_version) ||
is_mt9v024(mt9v022->chip_version)) {
if (reg_set(client, MT9V022_REG32, 0x204))
return -EIO;
}
}
if (reg_write(client, MT9V022_CHIP_CONTROL, mt9v022->chip_control) < 0)
return -EIO;
return 0;
}
static int mt9v022_s_crop(struct v4l2_subdev *sd, const struct v4l2_crop *a)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct mt9v022 *mt9v022 = to_mt9v022(client);
struct v4l2_rect rect = a->c;
int ret;
if (mt9v022->fmts == mt9v022_colour_fmts) {
rect.width = ALIGN(rect.width, 2);
rect.height = ALIGN(rect.height, 2);
}
soc_camera_limit_side(&rect.left, &rect.width,
MT9V022_COLUMN_SKIP, MT9V022_MIN_WIDTH, MT9V022_MAX_WIDTH);
soc_camera_limit_side(&rect.top, &rect.height,
MT9V022_ROW_SKIP, MT9V022_MIN_HEIGHT, MT9V022_MAX_HEIGHT);
ret = reg_read(client, MT9V022_AEC_AGC_ENABLE);
if (ret >= 0) {
if (ret & 1)
ret = reg_write(client, mt9v022->reg->max_total_shutter_width,
rect.height + mt9v022->y_skip_top + 43);
}
if (!ret)
ret = reg_write(client, MT9V022_COLUMN_START, rect.left);
if (!ret)
ret = reg_write(client, MT9V022_ROW_START, rect.top);
if (!ret)
ret = v4l2_ctrl_s_ctrl(mt9v022->hblank,
rect.width > 660 - 43 ? 43 : 660 - rect.width);
if (!ret)
ret = v4l2_ctrl_s_ctrl(mt9v022->vblank, 45);
if (!ret)
ret = reg_write(client, MT9V022_WINDOW_WIDTH, rect.width);
if (!ret)
ret = reg_write(client, MT9V022_WINDOW_HEIGHT,
rect.height + mt9v022->y_skip_top);
if (ret < 0)
return ret;
dev_dbg(&client->dev, "Frame %dx%d pixel\n", rect.width, rect.height);
mt9v022->rect = rect;
return 0;
}
static int mt9v022_g_crop(struct v4l2_subdev *sd, struct v4l2_crop *a)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct mt9v022 *mt9v022 = to_mt9v022(client);
a->c = mt9v022->rect;
a->type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
return 0;
}
static int mt9v022_cropcap(struct v4l2_subdev *sd, struct v4l2_cropcap *a)
{
a->bounds.left = MT9V022_COLUMN_SKIP;
a->bounds.top = MT9V022_ROW_SKIP;
a->bounds.width = MT9V022_MAX_WIDTH;
a->bounds.height = MT9V022_MAX_HEIGHT;
a->defrect = a->bounds;
a->type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
a->pixelaspect.numerator = 1;
a->pixelaspect.denominator = 1;
return 0;
}
static int mt9v022_g_fmt(struct v4l2_subdev *sd,
struct v4l2_mbus_framefmt *mf)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct mt9v022 *mt9v022 = to_mt9v022(client);
mf->width = mt9v022->rect.width;
mf->height = mt9v022->rect.height;
mf->code = mt9v022->fmt->code;
mf->colorspace = mt9v022->fmt->colorspace;
mf->field = V4L2_FIELD_NONE;
return 0;
}
static int mt9v022_s_fmt(struct v4l2_subdev *sd,
struct v4l2_mbus_framefmt *mf)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct mt9v022 *mt9v022 = to_mt9v022(client);
struct v4l2_crop a = {
.c = {
.left = mt9v022->rect.left,
.top = mt9v022->rect.top,
.width = mf->width,
.height = mf->height,
},
};
int ret;
switch (mf->code) {
case V4L2_MBUS_FMT_Y8_1X8:
case V4L2_MBUS_FMT_Y10_1X10:
if (mt9v022->model != V4L2_IDENT_MT9V022IX7ATM)
return -EINVAL;
break;
case V4L2_MBUS_FMT_SBGGR8_1X8:
case V4L2_MBUS_FMT_SBGGR10_1X10:
if (mt9v022->model != V4L2_IDENT_MT9V022IX7ATC)
return -EINVAL;
break;
default:
return -EINVAL;
}
ret = mt9v022_s_crop(sd, &a);
if (!ret) {
mf->width = mt9v022->rect.width;
mf->height = mt9v022->rect.height;
mt9v022->fmt = mt9v022_find_datafmt(mf->code,
mt9v022->fmts, mt9v022->num_fmts);
mf->colorspace = mt9v022->fmt->colorspace;
}
return ret;
}
static int mt9v022_try_fmt(struct v4l2_subdev *sd,
struct v4l2_mbus_framefmt *mf)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct mt9v022 *mt9v022 = to_mt9v022(client);
const struct mt9v022_datafmt *fmt;
int align = mf->code == V4L2_MBUS_FMT_SBGGR8_1X8 ||
mf->code == V4L2_MBUS_FMT_SBGGR10_1X10;
v4l_bound_align_image(&mf->width, MT9V022_MIN_WIDTH,
MT9V022_MAX_WIDTH, align,
&mf->height, MT9V022_MIN_HEIGHT + mt9v022->y_skip_top,
MT9V022_MAX_HEIGHT + mt9v022->y_skip_top, align, 0);
fmt = mt9v022_find_datafmt(mf->code, mt9v022->fmts,
mt9v022->num_fmts);
if (!fmt) {
fmt = mt9v022->fmt;
mf->code = fmt->code;
}
mf->colorspace = fmt->colorspace;
return 0;
}
static int mt9v022_g_chip_ident(struct v4l2_subdev *sd,
struct v4l2_dbg_chip_ident *id)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct mt9v022 *mt9v022 = to_mt9v022(client);
if (id->match.type != V4L2_CHIP_MATCH_I2C_ADDR)
return -EINVAL;
if (id->match.addr != client->addr)
return -ENODEV;
id->ident = mt9v022->model;
id->revision = 0;
return 0;
}
static int mt9v022_g_register(struct v4l2_subdev *sd,
struct v4l2_dbg_register *reg)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
if (reg->match.type != V4L2_CHIP_MATCH_I2C_ADDR || reg->reg > 0xff)
return -EINVAL;
if (reg->match.addr != client->addr)
return -ENODEV;
reg->size = 2;
reg->val = reg_read(client, reg->reg);
if (reg->val > 0xffff)
return -EIO;
return 0;
}
static int mt9v022_s_register(struct v4l2_subdev *sd,
struct v4l2_dbg_register *reg)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
if (reg->match.type != V4L2_CHIP_MATCH_I2C_ADDR || reg->reg > 0xff)
return -EINVAL;
if (reg->match.addr != client->addr)
return -ENODEV;
if (reg_write(client, reg->reg, reg->val) < 0)
return -EIO;
return 0;
}
static int mt9v022_s_power(struct v4l2_subdev *sd, int on)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct soc_camera_subdev_desc *ssdd = soc_camera_i2c_to_desc(client);
return soc_camera_set_power(&client->dev, ssdd, on);
}
static int mt9v022_g_volatile_ctrl(struct v4l2_ctrl *ctrl)
{
struct mt9v022 *mt9v022 = container_of(ctrl->handler,
struct mt9v022, hdl);
struct v4l2_subdev *sd = &mt9v022->subdev;
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct v4l2_ctrl *gain = mt9v022->gain;
struct v4l2_ctrl *exp = mt9v022->exposure;
unsigned long range;
int data;
switch (ctrl->id) {
case V4L2_CID_AUTOGAIN:
data = reg_read(client, MT9V022_ANALOG_GAIN);
if (data < 0)
return -EIO;
range = gain->maximum - gain->minimum;
gain->val = ((data - 16) * range + 24) / 48 + gain->minimum;
return 0;
case V4L2_CID_EXPOSURE_AUTO:
data = reg_read(client, MT9V022_TOTAL_SHUTTER_WIDTH);
if (data < 0)
return -EIO;
range = exp->maximum - exp->minimum;
exp->val = ((data - 1) * range + 239) / 479 + exp->minimum;
return 0;
case V4L2_CID_HBLANK:
data = reg_read(client, MT9V022_HORIZONTAL_BLANKING);
if (data < 0)
return -EIO;
ctrl->val = data;
return 0;
case V4L2_CID_VBLANK:
data = reg_read(client, MT9V022_VERTICAL_BLANKING);
if (data < 0)
return -EIO;
ctrl->val = data;
return 0;
}
return -EINVAL;
}
static int mt9v022_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct mt9v022 *mt9v022 = container_of(ctrl->handler,
struct mt9v022, hdl);
struct v4l2_subdev *sd = &mt9v022->subdev;
struct i2c_client *client = v4l2_get_subdevdata(sd);
int data;
switch (ctrl->id) {
case V4L2_CID_VFLIP:
if (ctrl->val)
data = reg_set(client, MT9V022_READ_MODE, 0x10);
else
data = reg_clear(client, MT9V022_READ_MODE, 0x10);
if (data < 0)
return -EIO;
return 0;
case V4L2_CID_HFLIP:
if (ctrl->val)
data = reg_set(client, MT9V022_READ_MODE, 0x20);
else
data = reg_clear(client, MT9V022_READ_MODE, 0x20);
if (data < 0)
return -EIO;
return 0;
case V4L2_CID_AUTOGAIN:
if (ctrl->val) {
if (reg_set(client, MT9V022_AEC_AGC_ENABLE, 0x2) < 0)
return -EIO;
} else {
struct v4l2_ctrl *gain = mt9v022->gain;
unsigned long range = gain->maximum - gain->minimum;
unsigned long gain_val = ((gain->val - gain->minimum) *
48 + range / 2) / range + 16;
if (gain_val >= 32)
gain_val &= ~1;
if (reg_clear(client, MT9V022_AEC_AGC_ENABLE, 0x2) < 0)
return -EIO;
dev_dbg(&client->dev, "Setting gain from %d to %lu\n",
reg_read(client, MT9V022_ANALOG_GAIN), gain_val);
if (reg_write(client, MT9V022_ANALOG_GAIN, gain_val) < 0)
return -EIO;
}
return 0;
case V4L2_CID_EXPOSURE_AUTO:
if (ctrl->val == V4L2_EXPOSURE_AUTO) {
data = reg_set(client, MT9V022_AEC_AGC_ENABLE, 0x1);
} else {
struct v4l2_ctrl *exp = mt9v022->exposure;
unsigned long range = exp->maximum - exp->minimum;
unsigned long shutter = ((exp->val - exp->minimum) *
479 + range / 2) / range + 1;
data = reg_clear(client, MT9V022_AEC_AGC_ENABLE, 0x1);
if (data < 0)
return -EIO;
dev_dbg(&client->dev, "Shutter width from %d to %lu\n",
reg_read(client, MT9V022_TOTAL_SHUTTER_WIDTH),
shutter);
if (reg_write(client, MT9V022_TOTAL_SHUTTER_WIDTH,
shutter) < 0)
return -EIO;
}
return 0;
case V4L2_CID_HBLANK:
if (reg_write(client, MT9V022_HORIZONTAL_BLANKING,
ctrl->val) < 0)
return -EIO;
return 0;
case V4L2_CID_VBLANK:
if (reg_write(client, MT9V022_VERTICAL_BLANKING,
ctrl->val) < 0)
return -EIO;
return 0;
}
return -EINVAL;
}
static int mt9v022_video_probe(struct i2c_client *client)
{
struct mt9v022 *mt9v022 = to_mt9v022(client);
struct soc_camera_subdev_desc *ssdd = soc_camera_i2c_to_desc(client);
s32 data;
int ret;
unsigned long flags;
ret = mt9v022_s_power(&mt9v022->subdev, 1);
if (ret < 0)
return ret;
data = reg_read(client, MT9V022_CHIP_VERSION);
if (data != 0x1311 && data != 0x1313 && data != 0x1324) {
ret = -ENODEV;
dev_info(&client->dev, "No MT9V022 found, ID register 0x%x\n",
data);
goto ei2c;
}
mt9v022->chip_version = data;
mt9v022->reg = is_mt9v024(data) ? &mt9v024_register :
&mt9v022_register;
ret = reg_write(client, MT9V022_RESET, 1);
if (ret < 0)
goto ei2c;
udelay(200);
if (reg_read(client, MT9V022_RESET)) {
dev_err(&client->dev, "Resetting MT9V022 failed!\n");
if (ret > 0)
ret = -EIO;
goto ei2c;
}
if (sensor_type && (!strcmp("colour", sensor_type) ||
!strcmp("color", sensor_type))) {
ret = reg_write(client, MT9V022_PIXEL_OPERATION_MODE, 4 | 0x11);
mt9v022->model = V4L2_IDENT_MT9V022IX7ATC;
mt9v022->fmts = mt9v022_colour_fmts;
} else {
ret = reg_write(client, MT9V022_PIXEL_OPERATION_MODE, 0x11);
mt9v022->model = V4L2_IDENT_MT9V022IX7ATM;
mt9v022->fmts = mt9v022_monochrome_fmts;
}
if (ret < 0)
goto ei2c;
mt9v022->num_fmts = 0;
if (ssdd->query_bus_param)
flags = ssdd->query_bus_param(ssdd);
else
flags = SOCAM_DATAWIDTH_10;
if (flags & SOCAM_DATAWIDTH_10)
mt9v022->num_fmts++;
else
mt9v022->fmts++;
if (flags & SOCAM_DATAWIDTH_8)
mt9v022->num_fmts++;
mt9v022->fmt = &mt9v022->fmts[0];
dev_info(&client->dev, "Detected a MT9V022 chip ID %x, %s sensor\n",
data, mt9v022->model == V4L2_IDENT_MT9V022IX7ATM ?
"monochrome" : "colour");
ret = mt9v022_init(client);
if (ret < 0)
dev_err(&client->dev, "Failed to initialise the camera\n");
ei2c:
mt9v022_s_power(&mt9v022->subdev, 0);
return ret;
}
static int mt9v022_g_skip_top_lines(struct v4l2_subdev *sd, u32 *lines)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct mt9v022 *mt9v022 = to_mt9v022(client);
*lines = mt9v022->y_skip_top;
return 0;
}
static int mt9v022_enum_fmt(struct v4l2_subdev *sd, unsigned int index,
enum v4l2_mbus_pixelcode *code)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct mt9v022 *mt9v022 = to_mt9v022(client);
if (index >= mt9v022->num_fmts)
return -EINVAL;
*code = mt9v022->fmts[index].code;
return 0;
}
static int mt9v022_g_mbus_config(struct v4l2_subdev *sd,
struct v4l2_mbus_config *cfg)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct soc_camera_subdev_desc *ssdd = soc_camera_i2c_to_desc(client);
cfg->flags = V4L2_MBUS_MASTER | V4L2_MBUS_SLAVE |
V4L2_MBUS_PCLK_SAMPLE_RISING | V4L2_MBUS_PCLK_SAMPLE_FALLING |
V4L2_MBUS_HSYNC_ACTIVE_HIGH | V4L2_MBUS_HSYNC_ACTIVE_LOW |
V4L2_MBUS_VSYNC_ACTIVE_HIGH | V4L2_MBUS_VSYNC_ACTIVE_LOW |
V4L2_MBUS_DATA_ACTIVE_HIGH;
cfg->type = V4L2_MBUS_PARALLEL;
cfg->flags = soc_camera_apply_board_flags(ssdd, cfg);
return 0;
}
static int mt9v022_s_mbus_config(struct v4l2_subdev *sd,
const struct v4l2_mbus_config *cfg)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct soc_camera_subdev_desc *ssdd = soc_camera_i2c_to_desc(client);
struct mt9v022 *mt9v022 = to_mt9v022(client);
unsigned long flags = soc_camera_apply_board_flags(ssdd, cfg);
unsigned int bps = soc_mbus_get_fmtdesc(mt9v022->fmt->code)->bits_per_sample;
int ret;
u16 pixclk = 0;
if (ssdd->set_bus_param) {
ret = ssdd->set_bus_param(ssdd, 1 << (bps - 1));
if (ret)
return ret;
} else if (bps != 10) {
return -EINVAL;
}
if (flags & V4L2_MBUS_PCLK_SAMPLE_FALLING)
pixclk |= 0x10;
if (!(flags & V4L2_MBUS_HSYNC_ACTIVE_HIGH))
pixclk |= 0x1;
if (!(flags & V4L2_MBUS_VSYNC_ACTIVE_HIGH))
pixclk |= 0x2;
ret = reg_write(client, mt9v022->reg->pixclk_fv_lv, pixclk);
if (ret < 0)
return ret;
if (!(flags & V4L2_MBUS_MASTER))
mt9v022->chip_control &= ~0x8;
ret = reg_write(client, MT9V022_CHIP_CONTROL, mt9v022->chip_control);
if (ret < 0)
return ret;
dev_dbg(&client->dev, "Calculated pixclk 0x%x, chip control 0x%x\n",
pixclk, mt9v022->chip_control);
return 0;
}
static int mt9v022_probe(struct i2c_client *client,
const struct i2c_device_id *did)
{
struct mt9v022 *mt9v022;
struct soc_camera_subdev_desc *ssdd = soc_camera_i2c_to_desc(client);
struct i2c_adapter *adapter = to_i2c_adapter(client->dev.parent);
struct mt9v022_platform_data *pdata;
int ret;
if (!ssdd) {
dev_err(&client->dev, "MT9V022 driver needs platform data\n");
return -EINVAL;
}
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_WORD_DATA)) {
dev_warn(&adapter->dev,
"I2C-Adapter doesn't support I2C_FUNC_SMBUS_WORD\n");
return -EIO;
}
mt9v022 = devm_kzalloc(&client->dev, sizeof(struct mt9v022), GFP_KERNEL);
if (!mt9v022)
return -ENOMEM;
pdata = ssdd->drv_priv;
v4l2_i2c_subdev_init(&mt9v022->subdev, client, &mt9v022_subdev_ops);
v4l2_ctrl_handler_init(&mt9v022->hdl, 6);
v4l2_ctrl_new_std(&mt9v022->hdl, &mt9v022_ctrl_ops,
V4L2_CID_VFLIP, 0, 1, 1, 0);
v4l2_ctrl_new_std(&mt9v022->hdl, &mt9v022_ctrl_ops,
V4L2_CID_HFLIP, 0, 1, 1, 0);
mt9v022->autogain = v4l2_ctrl_new_std(&mt9v022->hdl, &mt9v022_ctrl_ops,
V4L2_CID_AUTOGAIN, 0, 1, 1, 1);
mt9v022->gain = v4l2_ctrl_new_std(&mt9v022->hdl, &mt9v022_ctrl_ops,
V4L2_CID_GAIN, 0, 127, 1, 64);
mt9v022->autoexposure = v4l2_ctrl_new_std_menu(&mt9v022->hdl,
&mt9v022_ctrl_ops, V4L2_CID_EXPOSURE_AUTO, 1, 0,
V4L2_EXPOSURE_AUTO);
mt9v022->exposure = v4l2_ctrl_new_std(&mt9v022->hdl, &mt9v022_ctrl_ops,
V4L2_CID_EXPOSURE, 1, 255, 1, 255);
mt9v022->hblank = v4l2_ctrl_new_std(&mt9v022->hdl, &mt9v022_ctrl_ops,
V4L2_CID_HBLANK, MT9V022_HORIZONTAL_BLANKING_MIN,
MT9V022_HORIZONTAL_BLANKING_MAX, 1,
MT9V022_HORIZONTAL_BLANKING_DEF);
mt9v022->vblank = v4l2_ctrl_new_std(&mt9v022->hdl, &mt9v022_ctrl_ops,
V4L2_CID_VBLANK, MT9V022_VERTICAL_BLANKING_MIN,
MT9V022_VERTICAL_BLANKING_MAX, 1,
MT9V022_VERTICAL_BLANKING_DEF);
mt9v022->subdev.ctrl_handler = &mt9v022->hdl;
if (mt9v022->hdl.error) {
int err = mt9v022->hdl.error;
dev_err(&client->dev, "control initialisation err %d\n", err);
return err;
}
v4l2_ctrl_auto_cluster(2, &mt9v022->autoexposure,
V4L2_EXPOSURE_MANUAL, true);
v4l2_ctrl_auto_cluster(2, &mt9v022->autogain, 0, true);
mt9v022->chip_control = MT9V022_CHIP_CONTROL_DEFAULT;
mt9v022->y_skip_top = pdata ? pdata->y_skip_top : 0;
mt9v022->rect.left = MT9V022_COLUMN_SKIP;
mt9v022->rect.top = MT9V022_ROW_SKIP;
mt9v022->rect.width = MT9V022_MAX_WIDTH;
mt9v022->rect.height = MT9V022_MAX_HEIGHT;
ret = mt9v022_video_probe(client);
if (ret)
v4l2_ctrl_handler_free(&mt9v022->hdl);
return ret;
}
static int mt9v022_remove(struct i2c_client *client)
{
struct mt9v022 *mt9v022 = to_mt9v022(client);
struct soc_camera_subdev_desc *ssdd = soc_camera_i2c_to_desc(client);
v4l2_device_unregister_subdev(&mt9v022->subdev);
if (ssdd->free_bus)
ssdd->free_bus(ssdd);
v4l2_ctrl_handler_free(&mt9v022->hdl);
return 0;
}
