static const struct mt9m001_datafmt *mt9m001_find_datafmt(
enum v4l2_mbus_pixelcode code, const struct mt9m001_datafmt *fmt,
int n)
{
int i;
for (i = 0; i < n; i++)
if (fmt[i].code == code)
return fmt + i;
return NULL;
}
static struct mt9m001 *to_mt9m001(const struct i2c_client *client)
{
return container_of(i2c_get_clientdata(client), struct mt9m001, subdev);
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
static int mt9m001_init(struct i2c_client *client)
{
int ret;
dev_dbg(&client->dev, "%s\n", __func__);
ret = reg_write(client, MT9M001_RESET, 1);
if (!ret)
ret = reg_write(client, MT9M001_RESET, 0);
if (!ret)
ret = reg_write(client, MT9M001_OUTPUT_CONTROL, 0);
return ret;
}
static int mt9m001_s_stream(struct v4l2_subdev *sd, int enable)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
if (reg_write(client, MT9M001_OUTPUT_CONTROL, enable ? 2 : 0) < 0)
return -EIO;
return 0;
}
static int mt9m001_set_bus_param(struct soc_camera_device *icd,
unsigned long flags)
{
struct soc_camera_link *icl = to_soc_camera_link(icd);
unsigned long width_flag = flags & SOCAM_DATAWIDTH_MASK;
if (!is_power_of_2(width_flag))
return -EINVAL;
if (icl->set_bus_param)
return icl->set_bus_param(icl, width_flag);
if (width_flag == SOCAM_DATAWIDTH_10)
return 0;
return -EINVAL;
}
static unsigned long mt9m001_query_bus_param(struct soc_camera_device *icd)
{
struct soc_camera_link *icl = to_soc_camera_link(icd);
unsigned long flags = SOCAM_PCLK_SAMPLE_FALLING |
SOCAM_HSYNC_ACTIVE_HIGH | SOCAM_VSYNC_ACTIVE_HIGH |
SOCAM_DATA_ACTIVE_HIGH | SOCAM_MASTER;
if (icl->query_bus_param)
flags |= icl->query_bus_param(icl) & SOCAM_DATAWIDTH_MASK;
else
flags |= SOCAM_DATAWIDTH_10;
return soc_camera_apply_sensor_flags(icl, flags);
}
static int mt9m001_s_crop(struct v4l2_subdev *sd, struct v4l2_crop *a)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct mt9m001 *mt9m001 = to_mt9m001(client);
struct v4l2_rect rect = a->c;
struct soc_camera_device *icd = client->dev.platform_data;
int ret;
const u16 hblank = 9, vblank = 25;
unsigned int total_h;
if (mt9m001->fmts == mt9m001_colour_fmts)
rect.height = ALIGN(rect.height, 2);
rect.width = ALIGN(rect.width, 2);
rect.left = ALIGN(rect.left, 2);
soc_camera_limit_side(&rect.left, &rect.width,
MT9M001_COLUMN_SKIP, MT9M001_MIN_WIDTH, MT9M001_MAX_WIDTH);
soc_camera_limit_side(&rect.top, &rect.height,
MT9M001_ROW_SKIP, MT9M001_MIN_HEIGHT, MT9M001_MAX_HEIGHT);
total_h = rect.height + mt9m001->y_skip_top + vblank;
ret = reg_write(client, MT9M001_HORIZONTAL_BLANKING, hblank);
if (!ret)
ret = reg_write(client, MT9M001_VERTICAL_BLANKING, vblank);
if (!ret)
ret = reg_write(client, MT9M001_COLUMN_START, rect.left);
if (!ret)
ret = reg_write(client, MT9M001_ROW_START, rect.top);
if (!ret)
ret = reg_write(client, MT9M001_WINDOW_WIDTH, rect.width - 1);
if (!ret)
ret = reg_write(client, MT9M001_WINDOW_HEIGHT,
rect.height + mt9m001->y_skip_top - 1);
if (!ret && mt9m001->autoexposure) {
ret = reg_write(client, MT9M001_SHUTTER_WIDTH, total_h);
if (!ret) {
const struct v4l2_queryctrl *qctrl =
soc_camera_find_qctrl(icd->ops,
V4L2_CID_EXPOSURE);
mt9m001->exposure = (524 + (total_h - 1) *
(qctrl->maximum - qctrl->minimum)) /
1048 + qctrl->minimum;
}
}
if (!ret)
mt9m001->rect = rect;
return ret;
}
static int mt9m001_g_crop(struct v4l2_subdev *sd, struct v4l2_crop *a)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct mt9m001 *mt9m001 = to_mt9m001(client);
a->c = mt9m001->rect;
a->type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
return 0;
}
static int mt9m001_cropcap(struct v4l2_subdev *sd, struct v4l2_cropcap *a)
{
a->bounds.left = MT9M001_COLUMN_SKIP;
a->bounds.top = MT9M001_ROW_SKIP;
a->bounds.width = MT9M001_MAX_WIDTH;
a->bounds.height = MT9M001_MAX_HEIGHT;
a->defrect = a->bounds;
a->type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
a->pixelaspect.numerator = 1;
a->pixelaspect.denominator = 1;
return 0;
}
static int mt9m001_g_fmt(struct v4l2_subdev *sd,
struct v4l2_mbus_framefmt *mf)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct mt9m001 *mt9m001 = to_mt9m001(client);
mf->width = mt9m001->rect.width;
mf->height = mt9m001->rect.height;
mf->code = mt9m001->fmt->code;
mf->colorspace = mt9m001->fmt->colorspace;
mf->field = V4L2_FIELD_NONE;
return 0;
}
static int mt9m001_s_fmt(struct v4l2_subdev *sd,
struct v4l2_mbus_framefmt *mf)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct mt9m001 *mt9m001 = to_mt9m001(client);
struct v4l2_crop a = {
.c = {
.left = mt9m001->rect.left,
.top = mt9m001->rect.top,
.width = mf->width,
.height = mf->height,
},
};
int ret;
ret = mt9m001_s_crop(sd, &a);
if (!ret) {
mf->width = mt9m001->rect.width;
mf->height = mt9m001->rect.height;
mt9m001->fmt = mt9m001_find_datafmt(mf->code,
mt9m001->fmts, mt9m001->num_fmts);
mf->colorspace = mt9m001->fmt->colorspace;
}
return ret;
}
static int mt9m001_try_fmt(struct v4l2_subdev *sd,
struct v4l2_mbus_framefmt *mf)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct mt9m001 *mt9m001 = to_mt9m001(client);
const struct mt9m001_datafmt *fmt;
v4l_bound_align_image(&mf->width, MT9M001_MIN_WIDTH,
MT9M001_MAX_WIDTH, 1,
&mf->height, MT9M001_MIN_HEIGHT + mt9m001->y_skip_top,
MT9M001_MAX_HEIGHT + mt9m001->y_skip_top, 0, 0);
if (mt9m001->fmts == mt9m001_colour_fmts)
mf->height = ALIGN(mf->height - 1, 2);
fmt = mt9m001_find_datafmt(mf->code, mt9m001->fmts,
mt9m001->num_fmts);
if (!fmt) {
fmt = mt9m001->fmt;
mf->code = fmt->code;
}
mf->colorspace = fmt->colorspace;
return 0;
}
static int mt9m001_g_chip_ident(struct v4l2_subdev *sd,
struct v4l2_dbg_chip_ident *id)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct mt9m001 *mt9m001 = to_mt9m001(client);
if (id->match.type != V4L2_CHIP_MATCH_I2C_ADDR)
return -EINVAL;
if (id->match.addr != client->addr)
return -ENODEV;
id->ident = mt9m001->model;
id->revision = 0;
return 0;
}
static int mt9m001_g_register(struct v4l2_subdev *sd,
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
static int mt9m001_s_register(struct v4l2_subdev *sd,
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
static int mt9m001_g_ctrl(struct v4l2_subdev *sd, struct v4l2_control *ctrl)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct mt9m001 *mt9m001 = to_mt9m001(client);
int data;
switch (ctrl->id) {
case V4L2_CID_VFLIP:
data = reg_read(client, MT9M001_READ_OPTIONS2);
if (data < 0)
return -EIO;
ctrl->value = !!(data & 0x8000);
break;
case V4L2_CID_EXPOSURE_AUTO:
ctrl->value = mt9m001->autoexposure;
break;
case V4L2_CID_GAIN:
ctrl->value = mt9m001->gain;
break;
case V4L2_CID_EXPOSURE:
ctrl->value = mt9m001->exposure;
break;
}
return 0;
}
static int mt9m001_s_ctrl(struct v4l2_subdev *sd, struct v4l2_control *ctrl)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct mt9m001 *mt9m001 = to_mt9m001(client);
struct soc_camera_device *icd = client->dev.platform_data;
const struct v4l2_queryctrl *qctrl;
int data;
qctrl = soc_camera_find_qctrl(&mt9m001_ops, ctrl->id);
if (!qctrl)
return -EINVAL;
switch (ctrl->id) {
case V4L2_CID_VFLIP:
if (ctrl->value)
data = reg_set(client, MT9M001_READ_OPTIONS2, 0x8000);
else
data = reg_clear(client, MT9M001_READ_OPTIONS2, 0x8000);
if (data < 0)
return -EIO;
break;
case V4L2_CID_GAIN:
if (ctrl->value > qctrl->maximum || ctrl->value < qctrl->minimum)
return -EINVAL;
if (ctrl->value <= qctrl->default_value) {
unsigned long range = qctrl->default_value - qctrl->minimum;
data = ((ctrl->value - qctrl->minimum) * 8 + range / 2) / range;
dev_dbg(&client->dev, "Setting gain %d\n", data);
data = reg_write(client, MT9M001_GLOBAL_GAIN, data);
if (data < 0)
return -EIO;
} else {
unsigned long range = qctrl->maximum - qctrl->default_value - 1;
unsigned long gain = ((ctrl->value - qctrl->default_value - 1) *
111 + range / 2) / range + 9;
if (gain <= 32)
data = gain;
else if (gain <= 64)
data = ((gain - 32) * 16 + 16) / 32 + 80;
else
data = ((gain - 64) * 7 + 28) / 56 + 96;
dev_dbg(&client->dev, "Setting gain from %d to %d\n",
reg_read(client, MT9M001_GLOBAL_GAIN), data);
data = reg_write(client, MT9M001_GLOBAL_GAIN, data);
if (data < 0)
return -EIO;
}
mt9m001->gain = ctrl->value;
break;
case V4L2_CID_EXPOSURE:
if (ctrl->value > qctrl->maximum || ctrl->value < qctrl->minimum)
return -EINVAL;
else {
unsigned long range = qctrl->maximum - qctrl->minimum;
unsigned long shutter = ((ctrl->value - qctrl->minimum) * 1048 +
range / 2) / range + 1;
dev_dbg(&client->dev,
"Setting shutter width from %d to %lu\n",
reg_read(client, MT9M001_SHUTTER_WIDTH),
shutter);
if (reg_write(client, MT9M001_SHUTTER_WIDTH, shutter) < 0)
return -EIO;
mt9m001->exposure = ctrl->value;
mt9m001->autoexposure = 0;
}
break;
case V4L2_CID_EXPOSURE_AUTO:
if (ctrl->value) {
const u16 vblank = 25;
unsigned int total_h = mt9m001->rect.height +
mt9m001->y_skip_top + vblank;
if (reg_write(client, MT9M001_SHUTTER_WIDTH,
total_h) < 0)
return -EIO;
qctrl = soc_camera_find_qctrl(icd->ops, V4L2_CID_EXPOSURE);
mt9m001->exposure = (524 + (total_h - 1) *
(qctrl->maximum - qctrl->minimum)) /
1048 + qctrl->minimum;
mt9m001->autoexposure = 1;
} else
mt9m001->autoexposure = 0;
break;
}
return 0;
}
static int mt9m001_video_probe(struct soc_camera_device *icd,
struct i2c_client *client)
{
struct mt9m001 *mt9m001 = to_mt9m001(client);
struct soc_camera_link *icl = to_soc_camera_link(icd);
s32 data;
unsigned long flags;
int ret;
BUG_ON(!icd->parent ||
to_soc_camera_host(icd->parent)->nr != icd->iface);
data = reg_write(client, MT9M001_CHIP_ENABLE, 1);
dev_dbg(&client->dev, "write: %d\n", data);
data = reg_read(client, MT9M001_CHIP_VERSION);
switch (data) {
case 0x8411:
case 0x8421:
mt9m001->model = V4L2_IDENT_MT9M001C12ST;
mt9m001->fmts = mt9m001_colour_fmts;
break;
case 0x8431:
mt9m001->model = V4L2_IDENT_MT9M001C12STM;
mt9m001->fmts = mt9m001_monochrome_fmts;
break;
default:
dev_err(&client->dev,
"No MT9M001 chip detected, register read %x\n", data);
return -ENODEV;
}
mt9m001->num_fmts = 0;
if (icl->query_bus_param)
flags = icl->query_bus_param(icl);
else
flags = SOCAM_DATAWIDTH_10;
if (flags & SOCAM_DATAWIDTH_10)
mt9m001->num_fmts++;
else
mt9m001->fmts++;
if (flags & SOCAM_DATAWIDTH_8)
mt9m001->num_fmts++;
mt9m001->fmt = &mt9m001->fmts[0];
dev_info(&client->dev, "Detected a MT9M001 chip ID %x (%s)\n", data,
data == 0x8431 ? "C12STM" : "C12ST");
ret = mt9m001_init(client);
if (ret < 0)
dev_err(&client->dev, "Failed to initialise the camera\n");
mt9m001->gain = 64;
mt9m001->exposure = 255;
return ret;
}
static void mt9m001_video_remove(struct soc_camera_device *icd)
{
struct soc_camera_link *icl = to_soc_camera_link(icd);
dev_dbg(icd->pdev, "Video removed: %p, %p\n",
icd->parent, icd->vdev);
if (icl->free_bus)
icl->free_bus(icl);
}
static int mt9m001_g_skip_top_lines(struct v4l2_subdev *sd, u32 *lines)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct mt9m001 *mt9m001 = to_mt9m001(client);
*lines = mt9m001->y_skip_top;
return 0;
}
static int mt9m001_enum_fmt(struct v4l2_subdev *sd, unsigned int index,
enum v4l2_mbus_pixelcode *code)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct mt9m001 *mt9m001 = to_mt9m001(client);
if (index >= mt9m001->num_fmts)
return -EINVAL;
*code = mt9m001->fmts[index].code;
return 0;
}
static int mt9m001_probe(struct i2c_client *client,
const struct i2c_device_id *did)
{
struct mt9m001 *mt9m001;
struct soc_camera_device *icd = client->dev.platform_data;
struct i2c_adapter *adapter = to_i2c_adapter(client->dev.parent);
struct soc_camera_link *icl;
int ret;
if (!icd) {
dev_err(&client->dev, "MT9M001: missing soc-camera data!\n");
return -EINVAL;
}
icl = to_soc_camera_link(icd);
if (!icl) {
dev_err(&client->dev, "MT9M001 driver needs platform data\n");
return -EINVAL;
}
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_WORD_DATA)) {
dev_warn(&adapter->dev,
"I2C-Adapter doesn't support I2C_FUNC_SMBUS_WORD\n");
return -EIO;
}
mt9m001 = kzalloc(sizeof(struct mt9m001), GFP_KERNEL);
if (!mt9m001)
return -ENOMEM;
v4l2_i2c_subdev_init(&mt9m001->subdev, client, &mt9m001_subdev_ops);
icd->ops = &mt9m001_ops;
mt9m001->y_skip_top = 0;
mt9m001->rect.left = MT9M001_COLUMN_SKIP;
mt9m001->rect.top = MT9M001_ROW_SKIP;
mt9m001->rect.width = MT9M001_MAX_WIDTH;
mt9m001->rect.height = MT9M001_MAX_HEIGHT;
mt9m001->autoexposure = 1;
ret = mt9m001_video_probe(icd, client);
if (ret) {
icd->ops = NULL;
kfree(mt9m001);
}
return ret;
}
static int mt9m001_remove(struct i2c_client *client)
{
struct mt9m001 *mt9m001 = to_mt9m001(client);
struct soc_camera_device *icd = client->dev.platform_data;
icd->ops = NULL;
mt9m001_video_remove(icd);
kfree(mt9m001);
return 0;
}
static int __init mt9m001_mod_init(void)
{
return i2c_add_driver(&mt9m001_i2c_driver);
}
static void __exit mt9m001_mod_exit(void)
{
i2c_del_driver(&mt9m001_i2c_driver);
}
