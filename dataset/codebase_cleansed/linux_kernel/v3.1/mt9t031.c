static struct mt9t031 *to_mt9t031(const struct i2c_client *client)
{
return container_of(i2c_get_clientdata(client), struct mt9t031, subdev);
}
static int reg_read(struct i2c_client *client, const u8 reg)
{
s32 data = i2c_smbus_read_word_data(client, reg);
return data < 0 ? data : swab16(data);
}
static int reg_write(struct i2c_client *client, const u8 reg,
const u16 data)
{
return i2c_smbus_write_word_data(client, reg, swab16(data));
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
static int set_shutter(struct i2c_client *client, const u32 data)
{
int ret;
ret = reg_write(client, MT9T031_SHUTTER_WIDTH_UPPER, data >> 16);
if (ret >= 0)
ret = reg_write(client, MT9T031_SHUTTER_WIDTH, data & 0xffff);
return ret;
}
static int get_shutter(struct i2c_client *client, u32 *data)
{
int ret;
ret = reg_read(client, MT9T031_SHUTTER_WIDTH_UPPER);
*data = ret << 16;
if (ret >= 0)
ret = reg_read(client, MT9T031_SHUTTER_WIDTH);
*data |= ret & 0xffff;
return ret < 0 ? ret : 0;
}
static int mt9t031_idle(struct i2c_client *client)
{
int ret;
ret = reg_write(client, MT9T031_RESET, 1);
if (ret >= 0)
ret = reg_write(client, MT9T031_RESET, 0);
if (ret >= 0)
ret = reg_clear(client, MT9T031_OUTPUT_CONTROL, 2);
return ret >= 0 ? 0 : -EIO;
}
static int mt9t031_disable(struct i2c_client *client)
{
reg_clear(client, MT9T031_OUTPUT_CONTROL, 2);
return 0;
}
static int mt9t031_s_stream(struct v4l2_subdev *sd, int enable)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
int ret;
if (enable)
ret = reg_set(client, MT9T031_OUTPUT_CONTROL, 2);
else
ret = reg_clear(client, MT9T031_OUTPUT_CONTROL, 2);
if (ret < 0)
return -EIO;
return 0;
}
static int mt9t031_set_bus_param(struct soc_camera_device *icd,
unsigned long flags)
{
struct i2c_client *client = to_i2c_client(to_soc_camera_control(icd));
if (flags & ~MT9T031_BUS_PARAM)
return -EINVAL;
if (flags & SOCAM_PCLK_SAMPLE_FALLING)
reg_clear(client, MT9T031_PIXEL_CLOCK_CONTROL, 0x8000);
else
reg_set(client, MT9T031_PIXEL_CLOCK_CONTROL, 0x8000);
return 0;
}
static unsigned long mt9t031_query_bus_param(struct soc_camera_device *icd)
{
struct soc_camera_link *icl = to_soc_camera_link(icd);
return soc_camera_apply_sensor_flags(icl, MT9T031_BUS_PARAM);
}
static u16 mt9t031_skip(s32 *source, s32 target, s32 max)
{
unsigned int skip;
if (*source < target + target / 2) {
*source = target;
return 1;
}
skip = min(max, *source + target / 2) / target;
if (skip > 8)
skip = 8;
*source = target * skip;
return skip;
}
static int mt9t031_set_params(struct i2c_client *client,
struct v4l2_rect *rect, u16 xskip, u16 yskip)
{
struct mt9t031 *mt9t031 = to_mt9t031(client);
int ret;
u16 xbin, ybin;
const u16 hblank = MT9T031_HORIZONTAL_BLANK,
vblank = MT9T031_VERTICAL_BLANK;
xbin = min(xskip, (u16)3);
ybin = min(yskip, (u16)3);
switch (xbin) {
case 1:
rect->left &= ~1;
break;
case 2:
rect->left &= ~3;
break;
case 3:
rect->left = rect->left > roundup(MT9T031_COLUMN_SKIP, 6) ?
(rect->left / 6) * 6 : roundup(MT9T031_COLUMN_SKIP, 6);
}
rect->top &= ~1;
dev_dbg(&client->dev, "skip %u:%u, rect %ux%u@%u:%u\n",
xskip, yskip, rect->width, rect->height, rect->left, rect->top);
ret = reg_set(client, MT9T031_OUTPUT_CONTROL, 1);
if (ret < 0)
return ret;
ret = reg_write(client, MT9T031_HORIZONTAL_BLANKING, hblank);
if (ret >= 0)
ret = reg_write(client, MT9T031_VERTICAL_BLANKING, vblank);
if (yskip != mt9t031->yskip || xskip != mt9t031->xskip) {
if (ret >= 0)
ret = reg_write(client, MT9T031_COLUMN_ADDRESS_MODE,
((xbin - 1) << 4) | (xskip - 1));
if (ret >= 0)
ret = reg_write(client, MT9T031_ROW_ADDRESS_MODE,
((ybin - 1) << 4) | (yskip - 1));
}
dev_dbg(&client->dev, "new physical left %u, top %u\n",
rect->left, rect->top);
if (ret >= 0)
ret = reg_write(client, MT9T031_COLUMN_START, rect->left);
if (ret >= 0)
ret = reg_write(client, MT9T031_ROW_START, rect->top);
if (ret >= 0)
ret = reg_write(client, MT9T031_WINDOW_WIDTH, rect->width - 1);
if (ret >= 0)
ret = reg_write(client, MT9T031_WINDOW_HEIGHT,
rect->height + mt9t031->y_skip_top - 1);
if (ret >= 0 && mt9t031->autoexposure) {
unsigned int total_h = rect->height + mt9t031->y_skip_top + vblank;
ret = set_shutter(client, total_h);
if (ret >= 0) {
const u32 shutter_max = MT9T031_MAX_HEIGHT + vblank;
const struct v4l2_queryctrl *qctrl =
&mt9t031_controls[MT9T031_CTRL_EXPOSURE];
mt9t031->exposure = (shutter_max / 2 + (total_h - 1) *
(qctrl->maximum - qctrl->minimum)) /
shutter_max + qctrl->minimum;
}
}
if (ret >= 0)
ret = reg_clear(client, MT9T031_OUTPUT_CONTROL, 1);
if (ret >= 0) {
mt9t031->rect = *rect;
mt9t031->xskip = xskip;
mt9t031->yskip = yskip;
}
return ret < 0 ? ret : 0;
}
static int mt9t031_s_crop(struct v4l2_subdev *sd, struct v4l2_crop *a)
{
struct v4l2_rect rect = a->c;
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct mt9t031 *mt9t031 = to_mt9t031(client);
rect.width = ALIGN(rect.width, 2);
rect.height = ALIGN(rect.height, 2);
soc_camera_limit_side(&rect.left, &rect.width,
MT9T031_COLUMN_SKIP, MT9T031_MIN_WIDTH, MT9T031_MAX_WIDTH);
soc_camera_limit_side(&rect.top, &rect.height,
MT9T031_ROW_SKIP, MT9T031_MIN_HEIGHT, MT9T031_MAX_HEIGHT);
return mt9t031_set_params(client, &rect, mt9t031->xskip, mt9t031->yskip);
}
static int mt9t031_g_crop(struct v4l2_subdev *sd, struct v4l2_crop *a)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct mt9t031 *mt9t031 = to_mt9t031(client);
a->c = mt9t031->rect;
a->type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
return 0;
}
static int mt9t031_cropcap(struct v4l2_subdev *sd, struct v4l2_cropcap *a)
{
a->bounds.left = MT9T031_COLUMN_SKIP;
a->bounds.top = MT9T031_ROW_SKIP;
a->bounds.width = MT9T031_MAX_WIDTH;
a->bounds.height = MT9T031_MAX_HEIGHT;
a->defrect = a->bounds;
a->type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
a->pixelaspect.numerator = 1;
a->pixelaspect.denominator = 1;
return 0;
}
static int mt9t031_g_fmt(struct v4l2_subdev *sd,
struct v4l2_mbus_framefmt *mf)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct mt9t031 *mt9t031 = to_mt9t031(client);
mf->width = mt9t031->rect.width / mt9t031->xskip;
mf->height = mt9t031->rect.height / mt9t031->yskip;
mf->code = V4L2_MBUS_FMT_SBGGR10_1X10;
mf->colorspace = V4L2_COLORSPACE_SRGB;
mf->field = V4L2_FIELD_NONE;
return 0;
}
static int mt9t031_s_fmt(struct v4l2_subdev *sd,
struct v4l2_mbus_framefmt *mf)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct mt9t031 *mt9t031 = to_mt9t031(client);
u16 xskip, yskip;
struct v4l2_rect rect = mt9t031->rect;
xskip = mt9t031_skip(&rect.width, mf->width, MT9T031_MAX_WIDTH);
yskip = mt9t031_skip(&rect.height, mf->height, MT9T031_MAX_HEIGHT);
mf->code = V4L2_MBUS_FMT_SBGGR10_1X10;
mf->colorspace = V4L2_COLORSPACE_SRGB;
return mt9t031_set_params(client, &rect, xskip, yskip);
}
static int mt9t031_try_fmt(struct v4l2_subdev *sd,
struct v4l2_mbus_framefmt *mf)
{
v4l_bound_align_image(
&mf->width, MT9T031_MIN_WIDTH, MT9T031_MAX_WIDTH, 1,
&mf->height, MT9T031_MIN_HEIGHT, MT9T031_MAX_HEIGHT, 1, 0);
mf->code = V4L2_MBUS_FMT_SBGGR10_1X10;
mf->colorspace = V4L2_COLORSPACE_SRGB;
return 0;
}
static int mt9t031_g_chip_ident(struct v4l2_subdev *sd,
struct v4l2_dbg_chip_ident *id)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct mt9t031 *mt9t031 = to_mt9t031(client);
if (id->match.type != V4L2_CHIP_MATCH_I2C_ADDR)
return -EINVAL;
if (id->match.addr != client->addr)
return -ENODEV;
id->ident = mt9t031->model;
id->revision = 0;
return 0;
}
static int mt9t031_g_register(struct v4l2_subdev *sd,
struct v4l2_dbg_register *reg)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
if (reg->match.type != V4L2_CHIP_MATCH_I2C_ADDR || reg->reg > 0xff)
return -EINVAL;
if (reg->match.addr != client->addr)
return -ENODEV;
reg->val = reg_read(client, reg->reg);
if (reg->val > 0xffff)
return -EIO;
return 0;
}
static int mt9t031_s_register(struct v4l2_subdev *sd,
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
static int mt9t031_g_ctrl(struct v4l2_subdev *sd, struct v4l2_control *ctrl)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct mt9t031 *mt9t031 = to_mt9t031(client);
int data;
switch (ctrl->id) {
case V4L2_CID_VFLIP:
data = reg_read(client, MT9T031_READ_MODE_2);
if (data < 0)
return -EIO;
ctrl->value = !!(data & 0x8000);
break;
case V4L2_CID_HFLIP:
data = reg_read(client, MT9T031_READ_MODE_2);
if (data < 0)
return -EIO;
ctrl->value = !!(data & 0x4000);
break;
case V4L2_CID_EXPOSURE_AUTO:
ctrl->value = mt9t031->autoexposure;
break;
case V4L2_CID_GAIN:
ctrl->value = mt9t031->gain;
break;
case V4L2_CID_EXPOSURE:
ctrl->value = mt9t031->exposure;
break;
}
return 0;
}
static int mt9t031_s_ctrl(struct v4l2_subdev *sd, struct v4l2_control *ctrl)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct mt9t031 *mt9t031 = to_mt9t031(client);
const struct v4l2_queryctrl *qctrl;
int data;
switch (ctrl->id) {
case V4L2_CID_VFLIP:
if (ctrl->value)
data = reg_set(client, MT9T031_READ_MODE_2, 0x8000);
else
data = reg_clear(client, MT9T031_READ_MODE_2, 0x8000);
if (data < 0)
return -EIO;
break;
case V4L2_CID_HFLIP:
if (ctrl->value)
data = reg_set(client, MT9T031_READ_MODE_2, 0x4000);
else
data = reg_clear(client, MT9T031_READ_MODE_2, 0x4000);
if (data < 0)
return -EIO;
break;
case V4L2_CID_GAIN:
qctrl = &mt9t031_controls[MT9T031_CTRL_GAIN];
if (ctrl->value > qctrl->maximum || ctrl->value < qctrl->minimum)
return -EINVAL;
if (ctrl->value <= qctrl->default_value) {
unsigned long range = qctrl->default_value - qctrl->minimum;
data = ((ctrl->value - qctrl->minimum) * 8 + range / 2) / range;
dev_dbg(&client->dev, "Setting gain %d\n", data);
data = reg_write(client, MT9T031_GLOBAL_GAIN, data);
if (data < 0)
return -EIO;
} else {
unsigned long range = qctrl->maximum - qctrl->default_value - 1;
unsigned long gain = ((ctrl->value - qctrl->default_value - 1) *
1015 + range / 2) / range + 9;
if (gain <= 32)
data = gain;
else if (gain <= 64)
data = ((gain - 32) * 16 + 16) / 32 + 80;
else
data = (((gain - 64 + 7) * 32) & 0xff00) | 0x60;
dev_dbg(&client->dev, "Set gain from 0x%x to 0x%x\n",
reg_read(client, MT9T031_GLOBAL_GAIN), data);
data = reg_write(client, MT9T031_GLOBAL_GAIN, data);
if (data < 0)
return -EIO;
}
mt9t031->gain = ctrl->value;
break;
case V4L2_CID_EXPOSURE:
qctrl = &mt9t031_controls[MT9T031_CTRL_EXPOSURE];
if (ctrl->value > qctrl->maximum || ctrl->value < qctrl->minimum)
return -EINVAL;
else {
const unsigned long range = qctrl->maximum - qctrl->minimum;
const u32 shutter = ((ctrl->value - qctrl->minimum) * 1048 +
range / 2) / range + 1;
u32 old;
get_shutter(client, &old);
dev_dbg(&client->dev, "Set shutter from %u to %u\n",
old, shutter);
if (set_shutter(client, shutter) < 0)
return -EIO;
mt9t031->exposure = ctrl->value;
mt9t031->autoexposure = 0;
}
break;
case V4L2_CID_EXPOSURE_AUTO:
if (ctrl->value) {
const u16 vblank = MT9T031_VERTICAL_BLANK;
const u32 shutter_max = MT9T031_MAX_HEIGHT + vblank;
unsigned int total_h = mt9t031->rect.height +
mt9t031->y_skip_top + vblank;
if (set_shutter(client, total_h) < 0)
return -EIO;
qctrl = &mt9t031_controls[MT9T031_CTRL_EXPOSURE];
mt9t031->exposure = (shutter_max / 2 + (total_h - 1) *
(qctrl->maximum - qctrl->minimum)) /
shutter_max + qctrl->minimum;
mt9t031->autoexposure = 1;
} else
mt9t031->autoexposure = 0;
break;
default:
return -EINVAL;
}
return 0;
}
static int mt9t031_runtime_suspend(struct device *dev)
{
return 0;
}
static int mt9t031_runtime_resume(struct device *dev)
{
struct video_device *vdev = to_video_device(dev);
struct soc_camera_device *icd = dev_get_drvdata(vdev->parent);
struct v4l2_subdev *sd = soc_camera_to_subdev(icd);
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct mt9t031 *mt9t031 = to_mt9t031(client);
int ret;
u16 xbin, ybin;
xbin = min(mt9t031->xskip, (u16)3);
ybin = min(mt9t031->yskip, (u16)3);
ret = reg_write(client, MT9T031_COLUMN_ADDRESS_MODE,
((xbin - 1) << 4) | (mt9t031->xskip - 1));
if (ret < 0)
return ret;
ret = reg_write(client, MT9T031_ROW_ADDRESS_MODE,
((ybin - 1) << 4) | (mt9t031->yskip - 1));
if (ret < 0)
return ret;
return 0;
}
static int mt9t031_video_probe(struct i2c_client *client)
{
struct mt9t031 *mt9t031 = to_mt9t031(client);
struct video_device *vdev = soc_camera_i2c_to_vdev(client);
s32 data;
int ret;
data = reg_write(client, MT9T031_CHIP_ENABLE, 1);
dev_dbg(&client->dev, "write: %d\n", data);
data = reg_read(client, MT9T031_CHIP_VERSION);
switch (data) {
case 0x1621:
mt9t031->model = V4L2_IDENT_MT9T031;
break;
default:
dev_err(&client->dev,
"No MT9T031 chip detected, register read %x\n", data);
return -ENODEV;
}
dev_info(&client->dev, "Detected a MT9T031 chip ID %x\n", data);
ret = mt9t031_idle(client);
if (ret < 0)
dev_err(&client->dev, "Failed to initialise the camera\n");
else
vdev->dev.type = &mt9t031_dev_type;
mt9t031->exposure = 255;
mt9t031->gain = 64;
return ret;
}
static int mt9t031_g_skip_top_lines(struct v4l2_subdev *sd, u32 *lines)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct mt9t031 *mt9t031 = to_mt9t031(client);
*lines = mt9t031->y_skip_top;
return 0;
}
static int mt9t031_enum_fmt(struct v4l2_subdev *sd, unsigned int index,
enum v4l2_mbus_pixelcode *code)
{
if (index)
return -EINVAL;
*code = V4L2_MBUS_FMT_SBGGR10_1X10;
return 0;
}
static int mt9t031_probe(struct i2c_client *client,
const struct i2c_device_id *did)
{
struct mt9t031 *mt9t031;
struct soc_camera_device *icd = client->dev.platform_data;
struct i2c_adapter *adapter = to_i2c_adapter(client->dev.parent);
int ret;
if (icd) {
struct soc_camera_link *icl = to_soc_camera_link(icd);
if (!icl) {
dev_err(&client->dev, "MT9T031 driver needs platform data\n");
return -EINVAL;
}
icd->ops = &mt9t031_ops;
}
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_WORD_DATA)) {
dev_warn(&adapter->dev,
"I2C-Adapter doesn't support I2C_FUNC_SMBUS_WORD\n");
return -EIO;
}
mt9t031 = kzalloc(sizeof(struct mt9t031), GFP_KERNEL);
if (!mt9t031)
return -ENOMEM;
v4l2_i2c_subdev_init(&mt9t031->subdev, client, &mt9t031_subdev_ops);
mt9t031->y_skip_top = 0;
mt9t031->rect.left = MT9T031_COLUMN_SKIP;
mt9t031->rect.top = MT9T031_ROW_SKIP;
mt9t031->rect.width = MT9T031_MAX_WIDTH;
mt9t031->rect.height = MT9T031_MAX_HEIGHT;
mt9t031->autoexposure = 1;
mt9t031->xskip = 1;
mt9t031->yskip = 1;
mt9t031_idle(client);
ret = mt9t031_video_probe(client);
mt9t031_disable(client);
if (ret) {
if (icd)
icd->ops = NULL;
kfree(mt9t031);
}
return ret;
}
static int mt9t031_remove(struct i2c_client *client)
{
struct mt9t031 *mt9t031 = to_mt9t031(client);
struct soc_camera_device *icd = client->dev.platform_data;
if (icd)
icd->ops = NULL;
kfree(mt9t031);
return 0;
}
static int __init mt9t031_mod_init(void)
{
return i2c_add_driver(&mt9t031_i2c_driver);
}
static void __exit mt9t031_mod_exit(void)
{
i2c_del_driver(&mt9t031_i2c_driver);
}
