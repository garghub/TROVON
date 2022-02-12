int vsp1_rwpf_enum_mbus_code(struct v4l2_subdev *subdev,
struct v4l2_subdev_fh *fh,
struct v4l2_subdev_mbus_code_enum *code)
{
static const unsigned int codes[] = {
V4L2_MBUS_FMT_ARGB8888_1X32,
V4L2_MBUS_FMT_AYUV8_1X32,
};
if (code->index >= ARRAY_SIZE(codes))
return -EINVAL;
code->code = codes[code->index];
return 0;
}
int vsp1_rwpf_enum_frame_size(struct v4l2_subdev *subdev,
struct v4l2_subdev_fh *fh,
struct v4l2_subdev_frame_size_enum *fse)
{
struct vsp1_rwpf *rwpf = to_rwpf(subdev);
struct v4l2_mbus_framefmt *format;
format = v4l2_subdev_get_try_format(fh, fse->pad);
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
int vsp1_rwpf_get_format(struct v4l2_subdev *subdev, struct v4l2_subdev_fh *fh,
struct v4l2_subdev_format *fmt)
{
struct vsp1_rwpf *rwpf = to_rwpf(subdev);
fmt->format = *vsp1_entity_get_pad_format(&rwpf->entity, fh, fmt->pad,
fmt->which);
return 0;
}
int vsp1_rwpf_set_format(struct v4l2_subdev *subdev, struct v4l2_subdev_fh *fh,
struct v4l2_subdev_format *fmt)
{
struct vsp1_rwpf *rwpf = to_rwpf(subdev);
struct v4l2_mbus_framefmt *format;
if (fmt->format.code != V4L2_MBUS_FMT_ARGB8888_1X32 &&
fmt->format.code != V4L2_MBUS_FMT_AYUV8_1X32)
fmt->format.code = V4L2_MBUS_FMT_AYUV8_1X32;
format = vsp1_entity_get_pad_format(&rwpf->entity, fh, fmt->pad,
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
format = vsp1_entity_get_pad_format(&rwpf->entity, fh, RWPF_PAD_SOURCE,
fmt->which);
*format = fmt->format;
return 0;
}
