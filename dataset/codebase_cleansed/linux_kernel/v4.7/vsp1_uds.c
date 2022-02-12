static inline void vsp1_uds_write(struct vsp1_uds *uds, struct vsp1_dl_list *dl,
u32 reg, u32 data)
{
vsp1_dl_list_write(dl, reg + uds->entity.index * VI6_UDS_OFFSET, data);
}
void vsp1_uds_set_alpha(struct vsp1_uds *uds, struct vsp1_dl_list *dl,
unsigned int alpha)
{
vsp1_uds_write(uds, dl, VI6_UDS_ALPVAL,
alpha << VI6_UDS_ALPVAL_VAL0_SHIFT);
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
static int uds_enum_mbus_code(struct v4l2_subdev *subdev,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_mbus_code_enum *code)
{
static const unsigned int codes[] = {
MEDIA_BUS_FMT_ARGB8888_1X32,
MEDIA_BUS_FMT_AYUV8_1X32,
};
return vsp1_subdev_enum_mbus_code(subdev, cfg, code, codes,
ARRAY_SIZE(codes));
}
static int uds_enum_frame_size(struct v4l2_subdev *subdev,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_frame_size_enum *fse)
{
struct vsp1_uds *uds = to_uds(subdev);
struct v4l2_subdev_pad_config *config;
struct v4l2_mbus_framefmt *format;
config = vsp1_entity_get_pad_config(&uds->entity, cfg, fse->which);
if (!config)
return -EINVAL;
format = vsp1_entity_get_pad_format(&uds->entity, config,
UDS_PAD_SINK);
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
static void uds_try_format(struct vsp1_uds *uds,
struct v4l2_subdev_pad_config *config,
unsigned int pad, struct v4l2_mbus_framefmt *fmt)
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
format = vsp1_entity_get_pad_format(&uds->entity, config,
UDS_PAD_SINK);
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
static int uds_set_format(struct v4l2_subdev *subdev,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_format *fmt)
{
struct vsp1_uds *uds = to_uds(subdev);
struct v4l2_subdev_pad_config *config;
struct v4l2_mbus_framefmt *format;
config = vsp1_entity_get_pad_config(&uds->entity, cfg, fmt->which);
if (!config)
return -EINVAL;
uds_try_format(uds, config, fmt->pad, &fmt->format);
format = vsp1_entity_get_pad_format(&uds->entity, config, fmt->pad);
*format = fmt->format;
if (fmt->pad == UDS_PAD_SINK) {
format = vsp1_entity_get_pad_format(&uds->entity, config,
UDS_PAD_SOURCE);
*format = fmt->format;
uds_try_format(uds, config, UDS_PAD_SOURCE, format);
}
return 0;
}
static void uds_configure(struct vsp1_entity *entity,
struct vsp1_pipeline *pipe,
struct vsp1_dl_list *dl)
{
struct vsp1_uds *uds = to_uds(&entity->subdev);
const struct v4l2_mbus_framefmt *output;
const struct v4l2_mbus_framefmt *input;
unsigned int hscale;
unsigned int vscale;
bool multitap;
input = vsp1_entity_get_pad_format(&uds->entity, uds->entity.config,
UDS_PAD_SINK);
output = vsp1_entity_get_pad_format(&uds->entity, uds->entity.config,
UDS_PAD_SOURCE);
hscale = uds_compute_ratio(input->width, output->width);
vscale = uds_compute_ratio(input->height, output->height);
dev_dbg(uds->entity.vsp1->dev, "hscale %u vscale %u\n", hscale, vscale);
if (uds->scale_alpha && (hscale >= 8192 || vscale >= 8192))
multitap = false;
else
multitap = true;
vsp1_uds_write(uds, dl, VI6_UDS_CTRL,
(uds->scale_alpha ? VI6_UDS_CTRL_AON : 0) |
(multitap ? VI6_UDS_CTRL_BC : 0));
vsp1_uds_write(uds, dl, VI6_UDS_PASS_BWIDTH,
(uds_passband_width(hscale)
<< VI6_UDS_PASS_BWIDTH_H_SHIFT) |
(uds_passband_width(vscale)
<< VI6_UDS_PASS_BWIDTH_V_SHIFT));
vsp1_uds_write(uds, dl, VI6_UDS_SCALE,
(hscale << VI6_UDS_SCALE_HFRAC_SHIFT) |
(vscale << VI6_UDS_SCALE_VFRAC_SHIFT));
vsp1_uds_write(uds, dl, VI6_UDS_CLIP_SIZE,
(output->width << VI6_UDS_CLIP_SIZE_HSIZE_SHIFT) |
(output->height << VI6_UDS_CLIP_SIZE_VSIZE_SHIFT));
}
struct vsp1_uds *vsp1_uds_create(struct vsp1_device *vsp1, unsigned int index)
{
struct vsp1_uds *uds;
char name[6];
int ret;
uds = devm_kzalloc(vsp1->dev, sizeof(*uds), GFP_KERNEL);
if (uds == NULL)
return ERR_PTR(-ENOMEM);
uds->entity.ops = &uds_entity_ops;
uds->entity.type = VSP1_ENTITY_UDS;
uds->entity.index = index;
sprintf(name, "uds.%u", index);
ret = vsp1_entity_init(vsp1, &uds->entity, name, 2, &uds_ops);
if (ret < 0)
return ERR_PTR(ret);
return uds;
}
