static inline void vsp1_hsit_write(struct vsp1_hsit *hsit,
struct vsp1_dl_list *dl, u32 reg, u32 data)
{
vsp1_dl_list_write(dl, reg, data);
}
static int hsit_enum_mbus_code(struct v4l2_subdev *subdev,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_mbus_code_enum *code)
{
struct vsp1_hsit *hsit = to_hsit(subdev);
if (code->index > 0)
return -EINVAL;
if ((code->pad == HSIT_PAD_SINK && !hsit->inverse) |
(code->pad == HSIT_PAD_SOURCE && hsit->inverse))
code->code = MEDIA_BUS_FMT_ARGB8888_1X32;
else
code->code = MEDIA_BUS_FMT_AHSV8888_1X32;
return 0;
}
static int hsit_enum_frame_size(struct v4l2_subdev *subdev,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_frame_size_enum *fse)
{
return vsp1_subdev_enum_frame_size(subdev, cfg, fse, HSIT_MIN_SIZE,
HSIT_MIN_SIZE, HSIT_MAX_SIZE,
HSIT_MAX_SIZE);
}
static int hsit_set_format(struct v4l2_subdev *subdev,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_format *fmt)
{
struct vsp1_hsit *hsit = to_hsit(subdev);
struct v4l2_subdev_pad_config *config;
struct v4l2_mbus_framefmt *format;
config = vsp1_entity_get_pad_config(&hsit->entity, cfg, fmt->which);
if (!config)
return -EINVAL;
format = vsp1_entity_get_pad_format(&hsit->entity, config, fmt->pad);
if (fmt->pad == HSIT_PAD_SOURCE) {
fmt->format = *format;
return 0;
}
format->code = hsit->inverse ? MEDIA_BUS_FMT_AHSV8888_1X32
: MEDIA_BUS_FMT_ARGB8888_1X32;
format->width = clamp_t(unsigned int, fmt->format.width,
HSIT_MIN_SIZE, HSIT_MAX_SIZE);
format->height = clamp_t(unsigned int, fmt->format.height,
HSIT_MIN_SIZE, HSIT_MAX_SIZE);
format->field = V4L2_FIELD_NONE;
format->colorspace = V4L2_COLORSPACE_SRGB;
fmt->format = *format;
format = vsp1_entity_get_pad_format(&hsit->entity, config,
HSIT_PAD_SOURCE);
*format = fmt->format;
format->code = hsit->inverse ? MEDIA_BUS_FMT_ARGB8888_1X32
: MEDIA_BUS_FMT_AHSV8888_1X32;
return 0;
}
static void hsit_configure(struct vsp1_entity *entity,
struct vsp1_pipeline *pipe,
struct vsp1_dl_list *dl)
{
struct vsp1_hsit *hsit = to_hsit(&entity->subdev);
if (hsit->inverse)
vsp1_hsit_write(hsit, dl, VI6_HSI_CTRL, VI6_HSI_CTRL_EN);
else
vsp1_hsit_write(hsit, dl, VI6_HST_CTRL, VI6_HST_CTRL_EN);
}
struct vsp1_hsit *vsp1_hsit_create(struct vsp1_device *vsp1, bool inverse)
{
struct vsp1_hsit *hsit;
int ret;
hsit = devm_kzalloc(vsp1->dev, sizeof(*hsit), GFP_KERNEL);
if (hsit == NULL)
return ERR_PTR(-ENOMEM);
hsit->inverse = inverse;
hsit->entity.ops = &hsit_entity_ops;
if (inverse)
hsit->entity.type = VSP1_ENTITY_HSI;
else
hsit->entity.type = VSP1_ENTITY_HST;
ret = vsp1_entity_init(vsp1, &hsit->entity, inverse ? "hsi" : "hst", 2,
&hsit_ops);
if (ret < 0)
return ERR_PTR(ret);
return hsit;
}
