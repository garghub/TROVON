int vsp1_rwpf_enum_mbus_code(struct v4l2_subdev *subdev,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_mbus_code_enum *code)
{
static const unsigned int codes[] = {
MEDIA_BUS_FMT_ARGB8888_1X32,
MEDIA_BUS_FMT_AYUV8_1X32,
};
if (code->index >= ARRAY_SIZE(codes))
return -EINVAL;
code->code = codes[code->index];
return 0;
}
int vsp1_rwpf_enum_frame_size(struct v4l2_subdev *subdev,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_frame_size_enum *fse)
{
struct vsp1_rwpf *rwpf = to_rwpf(subdev);
struct v4l2_mbus_framefmt *format;
format = vsp1_entity_get_pad_format(&rwpf->entity, cfg, fse->pad,
fse->which);
if (fse->index || fse->code != format->code)
return -EINVAL;
if (fse->pad == RWPF_PAD_SINK) {
fse->min_width = RWPF_MIN_WIDTH;
fse->max_width = rwpf->max_width;
fse->min_height = RWPF_MIN_HEIGHT;
fse->max_height = rwpf->max_height;
} else {
fse->min_width = format->width;
fse->max_width = format->width;
fse->min_height = format->height;
fse->max_height = format->height;
}
return 0;
}
static struct v4l2_rect *
vsp1_rwpf_get_crop(struct vsp1_rwpf *rwpf, struct v4l2_subdev_pad_config *cfg, u32 which)
{
switch (which) {
case V4L2_SUBDEV_FORMAT_TRY:
return v4l2_subdev_get_try_crop(&rwpf->entity.subdev, cfg, RWPF_PAD_SINK);
case V4L2_SUBDEV_FORMAT_ACTIVE:
return &rwpf->crop;
default:
return NULL;
}
}
int vsp1_rwpf_get_format(struct v4l2_subdev *subdev, struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_format *fmt)
{
struct vsp1_rwpf *rwpf = to_rwpf(subdev);
fmt->format = *vsp1_entity_get_pad_format(&rwpf->entity, cfg, fmt->pad,
fmt->which);
return 0;
}
int vsp1_rwpf_set_format(struct v4l2_subdev *subdev, struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_format *fmt)
{
struct vsp1_rwpf *rwpf = to_rwpf(subdev);
struct v4l2_mbus_framefmt *format;
struct v4l2_rect *crop;
if (fmt->format.code != MEDIA_BUS_FMT_ARGB8888_1X32 &&
fmt->format.code != MEDIA_BUS_FMT_AYUV8_1X32)
fmt->format.code = MEDIA_BUS_FMT_AYUV8_1X32;
format = vsp1_entity_get_pad_format(&rwpf->entity, cfg, fmt->pad,
fmt->which);
if (fmt->pad == RWPF_PAD_SOURCE) {
format->code = fmt->format.code;
fmt->format = *format;
return 0;
}
format->code = fmt->format.code;
format->width = clamp_t(unsigned int, fmt->format.width,
RWPF_MIN_WIDTH, rwpf->max_width);
format->height = clamp_t(unsigned int, fmt->format.height,
RWPF_MIN_HEIGHT, rwpf->max_height);
format->field = V4L2_FIELD_NONE;
format->colorspace = V4L2_COLORSPACE_SRGB;
fmt->format = *format;
crop = vsp1_rwpf_get_crop(rwpf, cfg, fmt->which);
crop->left = 0;
crop->top = 0;
crop->width = fmt->format.width;
crop->height = fmt->format.height;
format = vsp1_entity_get_pad_format(&rwpf->entity, cfg, RWPF_PAD_SOURCE,
fmt->which);
*format = fmt->format;
return 0;
}
int vsp1_rwpf_get_selection(struct v4l2_subdev *subdev,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_selection *sel)
{
struct vsp1_rwpf *rwpf = to_rwpf(subdev);
struct v4l2_mbus_framefmt *format;
if (sel->pad != RWPF_PAD_SINK)
return -EINVAL;
switch (sel->target) {
case V4L2_SEL_TGT_CROP:
sel->r = *vsp1_rwpf_get_crop(rwpf, cfg, sel->which);
break;
case V4L2_SEL_TGT_CROP_BOUNDS:
format = vsp1_entity_get_pad_format(&rwpf->entity, cfg,
RWPF_PAD_SINK, sel->which);
sel->r.left = 0;
sel->r.top = 0;
sel->r.width = format->width;
sel->r.height = format->height;
break;
default:
return -EINVAL;
}
return 0;
}
int vsp1_rwpf_set_selection(struct v4l2_subdev *subdev,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_selection *sel)
{
struct vsp1_rwpf *rwpf = to_rwpf(subdev);
struct v4l2_mbus_framefmt *format;
struct v4l2_rect *crop;
if (sel->pad != RWPF_PAD_SINK)
return -EINVAL;
if (sel->target != V4L2_SEL_TGT_CROP)
return -EINVAL;
format = vsp1_entity_get_pad_format(&rwpf->entity, cfg, RWPF_PAD_SINK,
sel->which);
if (format->code == MEDIA_BUS_FMT_AYUV8_1X32) {
sel->r.left = ALIGN(sel->r.left, 2);
sel->r.top = ALIGN(sel->r.top, 2);
sel->r.width = round_down(sel->r.width, 2);
sel->r.height = round_down(sel->r.height, 2);
}
sel->r.left = min_t(unsigned int, sel->r.left, format->width - 2);
sel->r.top = min_t(unsigned int, sel->r.top, format->height - 2);
if (rwpf->entity.type == VSP1_ENTITY_WPF) {
sel->r.left = min_t(unsigned int, sel->r.left, 255);
sel->r.top = min_t(unsigned int, sel->r.top, 255);
}
sel->r.width = min_t(unsigned int, sel->r.width,
format->width - sel->r.left);
sel->r.height = min_t(unsigned int, sel->r.height,
format->height - sel->r.top);
crop = vsp1_rwpf_get_crop(rwpf, cfg, sel->which);
*crop = sel->r;
format = vsp1_entity_get_pad_format(&rwpf->entity, cfg, RWPF_PAD_SOURCE,
sel->which);
format->width = crop->width;
format->height = crop->height;
return 0;
}
