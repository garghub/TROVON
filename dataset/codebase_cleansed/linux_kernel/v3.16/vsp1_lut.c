static inline u32 vsp1_lut_read(struct vsp1_lut *lut, u32 reg)
{
return vsp1_read(lut->entity.vsp1, reg);
}
static inline void vsp1_lut_write(struct vsp1_lut *lut, u32 reg, u32 data)
{
vsp1_write(lut->entity.vsp1, reg, data);
}
static void lut_configure(struct vsp1_lut *lut, struct vsp1_lut_config *config)
{
memcpy_toio(lut->entity.vsp1->mmio + VI6_LUT_TABLE, config->lut,
sizeof(config->lut));
}
static long lut_ioctl(struct v4l2_subdev *subdev, unsigned int cmd, void *arg)
{
struct vsp1_lut *lut = to_lut(subdev);
switch (cmd) {
case VIDIOC_VSP1_LUT_CONFIG:
lut_configure(lut, arg);
return 0;
default:
return -ENOIOCTLCMD;
}
}
static int lut_s_stream(struct v4l2_subdev *subdev, int enable)
{
struct vsp1_lut *lut = to_lut(subdev);
if (!enable)
return 0;
vsp1_lut_write(lut, VI6_LUT_CTRL, VI6_LUT_CTRL_EN);
return 0;
}
static int lut_enum_mbus_code(struct v4l2_subdev *subdev,
struct v4l2_subdev_fh *fh,
struct v4l2_subdev_mbus_code_enum *code)
{
static const unsigned int codes[] = {
V4L2_MBUS_FMT_ARGB8888_1X32,
V4L2_MBUS_FMT_AHSV8888_1X32,
V4L2_MBUS_FMT_AYUV8_1X32,
};
struct v4l2_mbus_framefmt *format;
if (code->pad == LUT_PAD_SINK) {
if (code->index >= ARRAY_SIZE(codes))
return -EINVAL;
code->code = codes[code->index];
} else {
if (code->index)
return -EINVAL;
format = v4l2_subdev_get_try_format(fh, LUT_PAD_SINK);
code->code = format->code;
}
return 0;
}
static int lut_enum_frame_size(struct v4l2_subdev *subdev,
struct v4l2_subdev_fh *fh,
struct v4l2_subdev_frame_size_enum *fse)
{
struct v4l2_mbus_framefmt *format;
format = v4l2_subdev_get_try_format(fh, fse->pad);
if (fse->index || fse->code != format->code)
return -EINVAL;
if (fse->pad == LUT_PAD_SINK) {
fse->min_width = LUT_MIN_SIZE;
fse->max_width = LUT_MAX_SIZE;
fse->min_height = LUT_MIN_SIZE;
fse->max_height = LUT_MAX_SIZE;
} else {
fse->min_width = format->width;
fse->max_width = format->width;
fse->min_height = format->height;
fse->max_height = format->height;
}
return 0;
}
static int lut_get_format(struct v4l2_subdev *subdev, struct v4l2_subdev_fh *fh,
struct v4l2_subdev_format *fmt)
{
struct vsp1_lut *lut = to_lut(subdev);
fmt->format = *vsp1_entity_get_pad_format(&lut->entity, fh, fmt->pad,
fmt->which);
return 0;
}
static int lut_set_format(struct v4l2_subdev *subdev, struct v4l2_subdev_fh *fh,
struct v4l2_subdev_format *fmt)
{
struct vsp1_lut *lut = to_lut(subdev);
struct v4l2_mbus_framefmt *format;
if (fmt->format.code != V4L2_MBUS_FMT_ARGB8888_1X32 &&
fmt->format.code != V4L2_MBUS_FMT_AHSV8888_1X32 &&
fmt->format.code != V4L2_MBUS_FMT_AYUV8_1X32)
fmt->format.code = V4L2_MBUS_FMT_AYUV8_1X32;
format = vsp1_entity_get_pad_format(&lut->entity, fh, fmt->pad,
fmt->which);
if (fmt->pad == LUT_PAD_SOURCE) {
fmt->format = *format;
return 0;
}
format->width = clamp_t(unsigned int, fmt->format.width,
LUT_MIN_SIZE, LUT_MAX_SIZE);
format->height = clamp_t(unsigned int, fmt->format.height,
LUT_MIN_SIZE, LUT_MAX_SIZE);
format->field = V4L2_FIELD_NONE;
format->colorspace = V4L2_COLORSPACE_SRGB;
fmt->format = *format;
format = vsp1_entity_get_pad_format(&lut->entity, fh, LUT_PAD_SOURCE,
fmt->which);
*format = fmt->format;
return 0;
}
struct vsp1_lut *vsp1_lut_create(struct vsp1_device *vsp1)
{
struct v4l2_subdev *subdev;
struct vsp1_lut *lut;
int ret;
lut = devm_kzalloc(vsp1->dev, sizeof(*lut), GFP_KERNEL);
if (lut == NULL)
return ERR_PTR(-ENOMEM);
lut->entity.type = VSP1_ENTITY_LUT;
ret = vsp1_entity_init(vsp1, &lut->entity, 2);
if (ret < 0)
return ERR_PTR(ret);
subdev = &lut->entity.subdev;
v4l2_subdev_init(subdev, &lut_ops);
subdev->entity.ops = &vsp1_media_ops;
subdev->internal_ops = &vsp1_subdev_internal_ops;
snprintf(subdev->name, sizeof(subdev->name), "%s lut",
dev_name(vsp1->dev));
v4l2_set_subdevdata(subdev, lut);
subdev->flags |= V4L2_SUBDEV_FL_HAS_DEVNODE;
vsp1_entity_init_formats(subdev, NULL);
return lut;
}
