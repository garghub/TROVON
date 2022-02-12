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
ret = reg_write(client, MT9V022_MAX_TOTAL_SHUTTER_WIDTH, 480);
if (!ret)
ret = reg_clear(client, MT9V022_BLACK_LEVEL_CALIB_CTRL, 1);
if (!ret)
ret = reg_write(client, MT9V022_DIGITAL_TEST_PATTERN, 0);
return ret;
}
static int mt9v022_s_stream(struct v4l2_subdev *sd, int enable)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct mt9v022 *mt9v022 = to_mt9v022(client);
if (enable)
mt9v022->chip_control &= ~0x10;
else
mt9v022->chip_control |= 0x10;
if (reg_write(client, MT9V022_CHIP_CONTROL, mt9v022->chip_control) < 0)
return -EIO;
return 0;
}
static int mt9v022_set_bus_param(struct soc_camera_device *icd,
unsigned long flags)
{
struct i2c_client *client = to_i2c_client(to_soc_camera_control(icd));
struct mt9v022 *mt9v022 = to_mt9v022(client);
struct soc_camera_link *icl = to_soc_camera_link(icd);
unsigned int width_flag = flags & SOCAM_DATAWIDTH_MASK;
int ret;
u16 pixclk = 0;
if (!is_power_of_2(width_flag))
return -EINVAL;
if (icl->set_bus_param) {
ret = icl->set_bus_param(icl, width_flag);
if (ret)
return ret;
} else {
if (width_flag != SOCAM_DATAWIDTH_10)
return -EINVAL;
}
flags = soc_camera_apply_sensor_flags(icl, flags);
if (flags & SOCAM_PCLK_SAMPLE_FALLING)
pixclk |= 0x10;
if (!(flags & SOCAM_HSYNC_ACTIVE_HIGH))
pixclk |= 0x1;
if (!(flags & SOCAM_VSYNC_ACTIVE_HIGH))
pixclk |= 0x2;
ret = reg_write(client, MT9V022_PIXCLK_FV_LV, pixclk);
if (ret < 0)
return ret;
if (!(flags & SOCAM_MASTER))
mt9v022->chip_control &= ~0x8;
ret = reg_write(client, MT9V022_CHIP_CONTROL, mt9v022->chip_control);
if (ret < 0)
return ret;
dev_dbg(&client->dev, "Calculated pixclk 0x%x, chip control 0x%x\n",
pixclk, mt9v022->chip_control);
return 0;
}
static unsigned long mt9v022_query_bus_param(struct soc_camera_device *icd)
{
struct soc_camera_link *icl = to_soc_camera_link(icd);
unsigned int flags = SOCAM_MASTER | SOCAM_SLAVE |
SOCAM_PCLK_SAMPLE_RISING | SOCAM_PCLK_SAMPLE_FALLING |
SOCAM_HSYNC_ACTIVE_HIGH | SOCAM_HSYNC_ACTIVE_LOW |
SOCAM_VSYNC_ACTIVE_HIGH | SOCAM_VSYNC_ACTIVE_LOW |
SOCAM_DATA_ACTIVE_HIGH;
if (icl->query_bus_param)
flags |= icl->query_bus_param(icl) & SOCAM_DATAWIDTH_MASK;
else
flags |= SOCAM_DATAWIDTH_10;
return soc_camera_apply_sensor_flags(icl, flags);
}
static int mt9v022_s_crop(struct v4l2_subdev *sd, struct v4l2_crop *a)
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
ret = reg_write(client, MT9V022_MAX_TOTAL_SHUTTER_WIDTH,
rect.height + mt9v022->y_skip_top + 43);
else
ret = reg_write(client, MT9V022_TOTAL_SHUTTER_WIDTH,
rect.height + mt9v022->y_skip_top + 43);
}
if (!ret)
ret = reg_write(client, MT9V022_COLUMN_START, rect.left);
if (!ret)
ret = reg_write(client, MT9V022_ROW_START, rect.top);
if (!ret)
ret = reg_write(client, MT9V022_HORIZONTAL_BLANKING,
rect.width > 660 - 43 ? 43 :
660 - rect.width);
if (!ret)
ret = reg_write(client, MT9V022_VERTICAL_BLANKING, 45);
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
static int mt9v022_g_ctrl(struct v4l2_subdev *sd, struct v4l2_control *ctrl)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
const struct v4l2_queryctrl *qctrl;
unsigned long range;
int data;
qctrl = soc_camera_find_qctrl(&mt9v022_ops, ctrl->id);
switch (ctrl->id) {
case V4L2_CID_VFLIP:
data = reg_read(client, MT9V022_READ_MODE);
if (data < 0)
return -EIO;
ctrl->value = !!(data & 0x10);
break;
case V4L2_CID_HFLIP:
data = reg_read(client, MT9V022_READ_MODE);
if (data < 0)
return -EIO;
ctrl->value = !!(data & 0x20);
break;
case V4L2_CID_EXPOSURE_AUTO:
data = reg_read(client, MT9V022_AEC_AGC_ENABLE);
if (data < 0)
return -EIO;
ctrl->value = !!(data & 0x1);
break;
case V4L2_CID_AUTOGAIN:
data = reg_read(client, MT9V022_AEC_AGC_ENABLE);
if (data < 0)
return -EIO;
ctrl->value = !!(data & 0x2);
break;
case V4L2_CID_GAIN:
data = reg_read(client, MT9V022_ANALOG_GAIN);
if (data < 0)
return -EIO;
range = qctrl->maximum - qctrl->minimum;
ctrl->value = ((data - 16) * range + 24) / 48 + qctrl->minimum;
break;
case V4L2_CID_EXPOSURE:
data = reg_read(client, MT9V022_TOTAL_SHUTTER_WIDTH);
if (data < 0)
return -EIO;
range = qctrl->maximum - qctrl->minimum;
ctrl->value = ((data - 1) * range + 239) / 479 + qctrl->minimum;
break;
}
return 0;
}
static int mt9v022_s_ctrl(struct v4l2_subdev *sd, struct v4l2_control *ctrl)
{
int data;
struct i2c_client *client = v4l2_get_subdevdata(sd);
const struct v4l2_queryctrl *qctrl;
qctrl = soc_camera_find_qctrl(&mt9v022_ops, ctrl->id);
if (!qctrl)
return -EINVAL;
switch (ctrl->id) {
case V4L2_CID_VFLIP:
if (ctrl->value)
data = reg_set(client, MT9V022_READ_MODE, 0x10);
else
data = reg_clear(client, MT9V022_READ_MODE, 0x10);
if (data < 0)
return -EIO;
break;
case V4L2_CID_HFLIP:
if (ctrl->value)
data = reg_set(client, MT9V022_READ_MODE, 0x20);
else
data = reg_clear(client, MT9V022_READ_MODE, 0x20);
if (data < 0)
return -EIO;
break;
case V4L2_CID_GAIN:
if (ctrl->value > qctrl->maximum || ctrl->value < qctrl->minimum)
return -EINVAL;
else {
unsigned long range = qctrl->maximum - qctrl->minimum;
unsigned long gain = ((ctrl->value - qctrl->minimum) *
48 + range / 2) / range + 16;
if (gain >= 32)
gain &= ~1;
if (reg_clear(client, MT9V022_AEC_AGC_ENABLE, 0x2) < 0)
return -EIO;
dev_dbg(&client->dev, "Setting gain from %d to %lu\n",
reg_read(client, MT9V022_ANALOG_GAIN), gain);
if (reg_write(client, MT9V022_ANALOG_GAIN, gain) < 0)
return -EIO;
}
break;
case V4L2_CID_EXPOSURE:
if (ctrl->value > qctrl->maximum || ctrl->value < qctrl->minimum)
return -EINVAL;
else {
unsigned long range = qctrl->maximum - qctrl->minimum;
unsigned long shutter = ((ctrl->value - qctrl->minimum) *
479 + range / 2) / range + 1;
if (reg_clear(client, MT9V022_AEC_AGC_ENABLE, 0x1) < 0)
return -EIO;
dev_dbg(&client->dev, "Shutter width from %d to %lu\n",
reg_read(client, MT9V022_TOTAL_SHUTTER_WIDTH),
shutter);
if (reg_write(client, MT9V022_TOTAL_SHUTTER_WIDTH,
shutter) < 0)
return -EIO;
}
break;
case V4L2_CID_AUTOGAIN:
if (ctrl->value)
data = reg_set(client, MT9V022_AEC_AGC_ENABLE, 0x2);
else
data = reg_clear(client, MT9V022_AEC_AGC_ENABLE, 0x2);
if (data < 0)
return -EIO;
break;
case V4L2_CID_EXPOSURE_AUTO:
if (ctrl->value)
data = reg_set(client, MT9V022_AEC_AGC_ENABLE, 0x1);
else
data = reg_clear(client, MT9V022_AEC_AGC_ENABLE, 0x1);
if (data < 0)
return -EIO;
break;
}
return 0;
}
static int mt9v022_video_probe(struct soc_camera_device *icd,
struct i2c_client *client)
{
struct mt9v022 *mt9v022 = to_mt9v022(client);
struct soc_camera_link *icl = to_soc_camera_link(icd);
s32 data;
int ret;
unsigned long flags;
BUG_ON(!icd->parent ||
to_soc_camera_host(icd->parent)->nr != icd->iface);
data = reg_read(client, MT9V022_CHIP_VERSION);
if (data != 0x1311 && data != 0x1313) {
ret = -ENODEV;
dev_info(&client->dev, "No MT9V022 found, ID register 0x%x\n",
data);
goto ei2c;
}
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
if (icl->query_bus_param)
flags = icl->query_bus_param(icl);
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
return ret;
}
static void mt9v022_video_remove(struct soc_camera_device *icd)
{
struct soc_camera_link *icl = to_soc_camera_link(icd);
dev_dbg(icd->pdev, "Video removed: %p, %p\n",
icd->parent, icd->vdev);
if (icl->free_bus)
icl->free_bus(icl);
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
static int mt9v022_probe(struct i2c_client *client,
const struct i2c_device_id *did)
{
struct mt9v022 *mt9v022;
struct soc_camera_device *icd = client->dev.platform_data;
struct i2c_adapter *adapter = to_i2c_adapter(client->dev.parent);
struct soc_camera_link *icl;
int ret;
if (!icd) {
dev_err(&client->dev, "MT9V022: missing soc-camera data!\n");
return -EINVAL;
}
icl = to_soc_camera_link(icd);
if (!icl) {
dev_err(&client->dev, "MT9V022 driver needs platform data\n");
return -EINVAL;
}
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_WORD_DATA)) {
dev_warn(&adapter->dev,
"I2C-Adapter doesn't support I2C_FUNC_SMBUS_WORD\n");
return -EIO;
}
mt9v022 = kzalloc(sizeof(struct mt9v022), GFP_KERNEL);
if (!mt9v022)
return -ENOMEM;
v4l2_i2c_subdev_init(&mt9v022->subdev, client, &mt9v022_subdev_ops);
mt9v022->chip_control = MT9V022_CHIP_CONTROL_DEFAULT;
icd->ops = &mt9v022_ops;
mt9v022->y_skip_top = 1;
mt9v022->rect.left = MT9V022_COLUMN_SKIP;
mt9v022->rect.top = MT9V022_ROW_SKIP;
mt9v022->rect.width = MT9V022_MAX_WIDTH;
mt9v022->rect.height = MT9V022_MAX_HEIGHT;
ret = mt9v022_video_probe(icd, client);
if (ret) {
icd->ops = NULL;
kfree(mt9v022);
}
return ret;
}
static int mt9v022_remove(struct i2c_client *client)
{
struct mt9v022 *mt9v022 = to_mt9v022(client);
struct soc_camera_device *icd = client->dev.platform_data;
icd->ops = NULL;
mt9v022_video_remove(icd);
kfree(mt9v022);
return 0;
}
static int __init mt9v022_mod_init(void)
{
return i2c_add_driver(&mt9v022_i2c_driver);
}
static void __exit mt9v022_mod_exit(void)
{
i2c_del_driver(&mt9v022_i2c_driver);
}
