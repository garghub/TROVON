static inline u32 vsp1_hsit_read(struct vsp1_hsit *hsit, u32 reg)
{
return vsp1_read(hsit->entity.vsp1, reg);
}
static inline void vsp1_hsit_write(struct vsp1_hsit *hsit, u32 reg, u32 data)
{
vsp1_write(hsit->entity.vsp1, reg, data);
}
static int hsit_s_stream(struct v4l2_subdev *subdev, int enable)
{
struct vsp1_hsit *hsit = to_hsit(subdev);
if (!enable)
return 0;
if (hsit->inverse)
vsp1_hsit_write(hsit, VI6_HSI_CTRL, VI6_HSI_CTRL_EN);
else
vsp1_hsit_write(hsit, VI6_HST_CTRL, VI6_HST_CTRL_EN);
return 0;
}
static int hsit_enum_mbus_code(struct v4l2_subdev *subdev,
struct v4l2_subdev_fh *fh,
struct v4l2_subdev_mbus_code_enum *code)
{
struct vsp1_hsit *hsit = to_hsit(subdev);
if (code->index > 0)
return -EINVAL;
if ((code->pad == HSIT_PAD_SINK && !hsit->inverse) |
(code->pad == HSIT_PAD_SOURCE && hsit->inverse))
code->code = V4L2_MBUS_FMT_ARGB8888_1X32;
else
code->code = V4L2_MBUS_FMT_AHSV8888_1X32;
return 0;
}
static int hsit_enum_frame_size(struct v4l2_subdev *subdev,
struct v4l2_subdev_fh *fh,
struct v4l2_subdev_frame_size_enum *fse)
{
struct v4l2_mbus_framefmt *format;
format = v4l2_subdev_get_try_format(fh, fse->pad);
if (fse->index || fse->code != format->code)
return -EINVAL;
if (fse->pad == HSIT_PAD_SINK) {
fse->min_width = HSIT_MIN_SIZE;
fse->max_width = HSIT_MAX_SIZE;
fse->min_height = HSIT_MIN_SIZE;
fse->max_height = HSIT_MAX_SIZE;
} else {
fse->min_width = format->width;
fse->max_width = format->width;
fse->min_height = format->height;
fse->max_height = format->height;
}
return 0;
}
static int hsit_get_format(struct v4l2_subdev *subdev,
struct v4l2_subdev_fh *fh,
struct v4l2_subdev_format *fmt)
{
struct vsp1_hsit *hsit = to_hsit(subdev);
fmt->format = *vsp1_entity_get_pad_format(&hsit->entity, fh, fmt->pad,
fmt->which);
return 0;
}
static int hsit_set_format(struct v4l2_subdev *subdev,
struct v4l2_subdev_fh *fh,
struct v4l2_subdev_format *fmt)
{
struct vsp1_hsit *hsit = to_hsit(subdev);
struct v4l2_mbus_framefmt *format;
format = vsp1_entity_get_pad_format(&hsit->entity, fh, fmt->pad,
fmt->which);
if (fmt->pad == HSIT_PAD_SOURCE) {
fmt->format = *format;
return 0;
}
format->code = hsit->inverse ? V4L2_MBUS_FMT_AHSV8888_1X32
: V4L2_MBUS_FMT_ARGB8888_1X32;
format->width = clamp_t(unsigned int, fmt->format.width,
HSIT_MIN_SIZE, HSIT_MAX_SIZE);
format->height = clamp_t(unsigned int, fmt->format.height,
HSIT_MIN_SIZE, HSIT_MAX_SIZE);
format->field = V4L2_FIELD_NONE;
format->colorspace = V4L2_COLORSPACE_SRGB;
fmt->format = *format;
format = vsp1_entity_get_pad_format(&hsit->entity, fh, HSIT_PAD_SOURCE,
fmt->which);
*format = fmt->format;
format->code = hsit->inverse ? V4L2_MBUS_FMT_ARGB8888_1X32
: V4L2_MBUS_FMT_AHSV8888_1X32;
return 0;
}
struct vsp1_hsit *vsp1_hsit_create(struct vsp1_device *vsp1, bool inverse)
{
struct v4l2_subdev *subdev;
struct vsp1_hsit *hsit;
int ret;
hsit = devm_kzalloc(vsp1->dev, sizeof(*hsit), GFP_KERNEL);
if (hsit == NULL)
return ERR_PTR(-ENOMEM);
hsit->inverse = inverse;
if (inverse)
hsit->entity.type = VSP1_ENTITY_HSI;
else
hsit->entity.type = VSP1_ENTITY_HST;
ret = vsp1_entity_init(vsp1, &hsit->entity, 2);
if (ret < 0)
return ERR_PTR(ret);
subdev = &hsit->entity.subdev;
v4l2_subdev_init(subdev, &hsit_ops);
subdev->entity.ops = &vsp1_media_ops;
subdev->internal_ops = &vsp1_subdev_internal_ops;
snprintf(subdev->name, sizeof(subdev->name), "%s %s",
dev_name(vsp1->dev), inverse ? "hsi" : "hst");
v4l2_set_subdevdata(subdev, hsit);
subdev->flags |= V4L2_SUBDEV_FL_HAS_DEVNODE;
vsp1_entity_init_formats(subdev, NULL);
return hsit;
}
