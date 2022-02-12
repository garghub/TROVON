static inline u32 vsp1_uds_read(struct vsp1_uds *uds, u32 reg)
{
return vsp1_read(uds->entity.vsp1,
reg + uds->entity.index * VI6_UDS_OFFSET);
}
static inline void vsp1_uds_write(struct vsp1_uds *uds, u32 reg, u32 data)
{
vsp1_write(uds->entity.vsp1,
reg + uds->entity.index * VI6_UDS_OFFSET, data);
}
void vsp1_uds_set_alpha(struct vsp1_uds *uds, unsigned int alpha)
{
vsp1_uds_write(uds, VI6_UDS_ALPVAL, alpha << VI6_UDS_ALPVAL_VAL0_SHIFT);
}
static unsigned int uds_output_size(unsigned int input, unsigned int ratio)
{
if (ratio > 4096) {
unsigned int mp;
mp = ratio / 4096;
mp = mp < 4 ? 1 : (mp < 8 ? 2 : 4);
return (input - 1) / mp * mp * 4096 / ratio + 1;
} else {
return (input - 1) * 4096 / ratio + 1;
}
}
static void uds_output_limits(unsigned int input,
unsigned int *minimum, unsigned int *maximum)
{
*minimum = max(uds_output_size(input, UDS_MAX_FACTOR), UDS_MIN_SIZE);
*maximum = min(uds_output_size(input, UDS_MIN_FACTOR), UDS_MAX_SIZE);
}
static unsigned int uds_passband_width(unsigned int ratio)
{
if (ratio >= 4096) {
unsigned int mp;
mp = ratio / 4096;
mp = mp < 4 ? 1 : (mp < 8 ? 2 : 4);
return 64 * 4096 * mp / ratio;
} else {
return 64;
}
}
static unsigned int uds_compute_ratio(unsigned int input, unsigned int output)
{
return (input - 1) * 4096 / (output - 1);
}
static int uds_s_stream(struct v4l2_subdev *subdev, int enable)
{
struct vsp1_uds *uds = to_uds(subdev);
const struct v4l2_mbus_framefmt *output;
const struct v4l2_mbus_framefmt *input;
unsigned int hscale;
unsigned int vscale;
bool multitap;
if (!enable)
return 0;
input = &uds->entity.formats[UDS_PAD_SINK];
output = &uds->entity.formats[UDS_PAD_SOURCE];
hscale = uds_compute_ratio(input->width, output->width);
vscale = uds_compute_ratio(input->height, output->height);
dev_dbg(uds->entity.vsp1->dev, "hscale %u vscale %u\n", hscale, vscale);
if (uds->scale_alpha && (hscale >= 8192 || vscale >= 8192))
multitap = false;
else
multitap = true;
vsp1_uds_write(uds, VI6_UDS_CTRL,
(uds->scale_alpha ? VI6_UDS_CTRL_AON : 0) |
(multitap ? VI6_UDS_CTRL_BC : 0));
vsp1_uds_write(uds, VI6_UDS_PASS_BWIDTH,
(uds_passband_width(hscale)
<< VI6_UDS_PASS_BWIDTH_H_SHIFT) |
(uds_passband_width(vscale)
<< VI6_UDS_PASS_BWIDTH_V_SHIFT));
vsp1_uds_write(uds, VI6_UDS_SCALE,
(hscale << VI6_UDS_SCALE_HFRAC_SHIFT) |
(vscale << VI6_UDS_SCALE_VFRAC_SHIFT));
vsp1_uds_write(uds, VI6_UDS_CLIP_SIZE,
(output->width << VI6_UDS_CLIP_SIZE_HSIZE_SHIFT) |
(output->height << VI6_UDS_CLIP_SIZE_VSIZE_SHIFT));
return 0;
}
static int uds_enum_mbus_code(struct v4l2_subdev *subdev,
struct v4l2_subdev_fh *fh,
struct v4l2_subdev_mbus_code_enum *code)
{
static const unsigned int codes[] = {
MEDIA_BUS_FMT_ARGB8888_1X32,
MEDIA_BUS_FMT_AYUV8_1X32,
};
if (code->pad == UDS_PAD_SINK) {
if (code->index >= ARRAY_SIZE(codes))
return -EINVAL;
code->code = codes[code->index];
} else {
struct v4l2_mbus_framefmt *format;
if (code->index)
return -EINVAL;
format = v4l2_subdev_get_try_format(fh, UDS_PAD_SINK);
code->code = format->code;
}
return 0;
}
static int uds_enum_frame_size(struct v4l2_subdev *subdev,
struct v4l2_subdev_fh *fh,
struct v4l2_subdev_frame_size_enum *fse)
{
struct v4l2_mbus_framefmt *format;
format = v4l2_subdev_get_try_format(fh, UDS_PAD_SINK);
if (fse->index || fse->code != format->code)
return -EINVAL;
if (fse->pad == UDS_PAD_SINK) {
fse->min_width = UDS_MIN_SIZE;
fse->max_width = UDS_MAX_SIZE;
fse->min_height = UDS_MIN_SIZE;
fse->max_height = UDS_MAX_SIZE;
} else {
uds_output_limits(format->width, &fse->min_width,
&fse->max_width);
uds_output_limits(format->height, &fse->min_height,
&fse->max_height);
}
return 0;
}
static int uds_get_format(struct v4l2_subdev *subdev, struct v4l2_subdev_fh *fh,
struct v4l2_subdev_format *fmt)
{
struct vsp1_uds *uds = to_uds(subdev);
fmt->format = *vsp1_entity_get_pad_format(&uds->entity, fh, fmt->pad,
fmt->which);
return 0;
}
static void uds_try_format(struct vsp1_uds *uds, struct v4l2_subdev_fh *fh,
unsigned int pad, struct v4l2_mbus_framefmt *fmt,
enum v4l2_subdev_format_whence which)
{
struct v4l2_mbus_framefmt *format;
unsigned int minimum;
unsigned int maximum;
switch (pad) {
case UDS_PAD_SINK:
if (fmt->code != MEDIA_BUS_FMT_ARGB8888_1X32 &&
fmt->code != MEDIA_BUS_FMT_AYUV8_1X32)
fmt->code = MEDIA_BUS_FMT_AYUV8_1X32;
fmt->width = clamp(fmt->width, UDS_MIN_SIZE, UDS_MAX_SIZE);
fmt->height = clamp(fmt->height, UDS_MIN_SIZE, UDS_MAX_SIZE);
break;
case UDS_PAD_SOURCE:
format = vsp1_entity_get_pad_format(&uds->entity, fh,
UDS_PAD_SINK, which);
fmt->code = format->code;
uds_output_limits(format->width, &minimum, &maximum);
fmt->width = clamp(fmt->width, minimum, maximum);
uds_output_limits(format->height, &minimum, &maximum);
fmt->height = clamp(fmt->height, minimum, maximum);
break;
}
fmt->field = V4L2_FIELD_NONE;
fmt->colorspace = V4L2_COLORSPACE_SRGB;
}
static int uds_set_format(struct v4l2_subdev *subdev, struct v4l2_subdev_fh *fh,
struct v4l2_subdev_format *fmt)
{
struct vsp1_uds *uds = to_uds(subdev);
struct v4l2_mbus_framefmt *format;
uds_try_format(uds, fh, fmt->pad, &fmt->format, fmt->which);
format = vsp1_entity_get_pad_format(&uds->entity, fh, fmt->pad,
fmt->which);
*format = fmt->format;
if (fmt->pad == UDS_PAD_SINK) {
format = vsp1_entity_get_pad_format(&uds->entity, fh,
UDS_PAD_SOURCE, fmt->which);
*format = fmt->format;
uds_try_format(uds, fh, UDS_PAD_SOURCE, format, fmt->which);
}
return 0;
}
struct vsp1_uds *vsp1_uds_create(struct vsp1_device *vsp1, unsigned int index)
{
struct v4l2_subdev *subdev;
struct vsp1_uds *uds;
int ret;
uds = devm_kzalloc(vsp1->dev, sizeof(*uds), GFP_KERNEL);
if (uds == NULL)
return ERR_PTR(-ENOMEM);
uds->entity.type = VSP1_ENTITY_UDS;
uds->entity.index = index;
ret = vsp1_entity_init(vsp1, &uds->entity, 2);
if (ret < 0)
return ERR_PTR(ret);
subdev = &uds->entity.subdev;
v4l2_subdev_init(subdev, &uds_ops);
subdev->entity.ops = &vsp1_media_ops;
subdev->internal_ops = &vsp1_subdev_internal_ops;
snprintf(subdev->name, sizeof(subdev->name), "%s uds.%u",
dev_name(vsp1->dev), index);
v4l2_set_subdevdata(subdev, uds);
subdev->flags |= V4L2_SUBDEV_FL_HAS_DEVNODE;
vsp1_entity_init_formats(subdev, NULL);
return uds;
}
