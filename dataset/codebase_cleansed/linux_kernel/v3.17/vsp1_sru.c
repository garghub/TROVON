static inline u32 vsp1_sru_read(struct vsp1_sru *sru, u32 reg)
{
return vsp1_read(sru->entity.vsp1, reg);
}
static inline void vsp1_sru_write(struct vsp1_sru *sru, u32 reg, u32 data)
{
vsp1_write(sru->entity.vsp1, reg, data);
}
static int sru_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct vsp1_sru *sru =
container_of(ctrl->handler, struct vsp1_sru, ctrls);
const struct vsp1_sru_param *param;
u32 value;
switch (ctrl->id) {
case V4L2_CID_VSP1_SRU_INTENSITY:
param = &vsp1_sru_params[ctrl->val - 1];
value = vsp1_sru_read(sru, VI6_SRU_CTRL0);
value &= ~(VI6_SRU_CTRL0_PARAM0_MASK |
VI6_SRU_CTRL0_PARAM1_MASK);
value |= param->ctrl0;
vsp1_sru_write(sru, VI6_SRU_CTRL0, value);
vsp1_sru_write(sru, VI6_SRU_CTRL2, param->ctrl2);
break;
}
return 0;
}
static int sru_s_stream(struct v4l2_subdev *subdev, int enable)
{
struct vsp1_sru *sru = to_sru(subdev);
struct v4l2_mbus_framefmt *input;
struct v4l2_mbus_framefmt *output;
u32 ctrl0;
int ret;
ret = vsp1_entity_set_streaming(&sru->entity, enable);
if (ret < 0)
return ret;
if (!enable)
return 0;
input = &sru->entity.formats[SRU_PAD_SINK];
output = &sru->entity.formats[SRU_PAD_SOURCE];
if (input->code == V4L2_MBUS_FMT_ARGB8888_1X32)
ctrl0 = VI6_SRU_CTRL0_PARAM2 | VI6_SRU_CTRL0_PARAM3
| VI6_SRU_CTRL0_PARAM4;
else
ctrl0 = VI6_SRU_CTRL0_PARAM3;
if (input->width != output->width)
ctrl0 |= VI6_SRU_CTRL0_MODE_UPSCALE;
mutex_lock(sru->ctrls.lock);
ctrl0 |= vsp1_sru_read(sru, VI6_SRU_CTRL0)
& (VI6_SRU_CTRL0_PARAM0_MASK | VI6_SRU_CTRL0_PARAM1_MASK);
mutex_unlock(sru->ctrls.lock);
vsp1_sru_write(sru, VI6_SRU_CTRL1, VI6_SRU_CTRL1_PARAM5);
return 0;
}
static int sru_enum_mbus_code(struct v4l2_subdev *subdev,
struct v4l2_subdev_fh *fh,
struct v4l2_subdev_mbus_code_enum *code)
{
static const unsigned int codes[] = {
V4L2_MBUS_FMT_ARGB8888_1X32,
V4L2_MBUS_FMT_AYUV8_1X32,
};
struct v4l2_mbus_framefmt *format;
if (code->pad == SRU_PAD_SINK) {
if (code->index >= ARRAY_SIZE(codes))
return -EINVAL;
code->code = codes[code->index];
} else {
if (code->index)
return -EINVAL;
format = v4l2_subdev_get_try_format(fh, SRU_PAD_SINK);
code->code = format->code;
}
return 0;
}
static int sru_enum_frame_size(struct v4l2_subdev *subdev,
struct v4l2_subdev_fh *fh,
struct v4l2_subdev_frame_size_enum *fse)
{
struct v4l2_mbus_framefmt *format;
format = v4l2_subdev_get_try_format(fh, SRU_PAD_SINK);
if (fse->index || fse->code != format->code)
return -EINVAL;
if (fse->pad == SRU_PAD_SINK) {
fse->min_width = SRU_MIN_SIZE;
fse->max_width = SRU_MAX_SIZE;
fse->min_height = SRU_MIN_SIZE;
fse->max_height = SRU_MAX_SIZE;
} else {
fse->min_width = format->width;
fse->min_height = format->height;
if (format->width <= SRU_MAX_SIZE / 2 &&
format->height <= SRU_MAX_SIZE / 2) {
fse->max_width = format->width * 2;
fse->max_height = format->height * 2;
} else {
fse->max_width = format->width;
fse->max_height = format->height;
}
}
return 0;
}
static int sru_get_format(struct v4l2_subdev *subdev, struct v4l2_subdev_fh *fh,
struct v4l2_subdev_format *fmt)
{
struct vsp1_sru *sru = to_sru(subdev);
fmt->format = *vsp1_entity_get_pad_format(&sru->entity, fh, fmt->pad,
fmt->which);
return 0;
}
static void sru_try_format(struct vsp1_sru *sru, struct v4l2_subdev_fh *fh,
unsigned int pad, struct v4l2_mbus_framefmt *fmt,
enum v4l2_subdev_format_whence which)
{
struct v4l2_mbus_framefmt *format;
unsigned int input_area;
unsigned int output_area;
switch (pad) {
case SRU_PAD_SINK:
if (fmt->code != V4L2_MBUS_FMT_ARGB8888_1X32 &&
fmt->code != V4L2_MBUS_FMT_AYUV8_1X32)
fmt->code = V4L2_MBUS_FMT_AYUV8_1X32;
fmt->width = clamp(fmt->width, SRU_MIN_SIZE, SRU_MAX_SIZE);
fmt->height = clamp(fmt->height, SRU_MIN_SIZE, SRU_MAX_SIZE);
break;
case SRU_PAD_SOURCE:
format = vsp1_entity_get_pad_format(&sru->entity, fh,
SRU_PAD_SINK, which);
fmt->code = format->code;
input_area = format->width * format->height;
output_area = min(fmt->width, SRU_MAX_SIZE)
* min(fmt->height, SRU_MAX_SIZE);
if (fmt->width <= SRU_MAX_SIZE / 2 &&
fmt->height <= SRU_MAX_SIZE / 2 &&
output_area > input_area * 9 / 4) {
fmt->width = format->width * 2;
fmt->height = format->height * 2;
} else {
fmt->width = format->width;
fmt->height = format->height;
}
break;
}
fmt->field = V4L2_FIELD_NONE;
fmt->colorspace = V4L2_COLORSPACE_SRGB;
}
static int sru_set_format(struct v4l2_subdev *subdev, struct v4l2_subdev_fh *fh,
struct v4l2_subdev_format *fmt)
{
struct vsp1_sru *sru = to_sru(subdev);
struct v4l2_mbus_framefmt *format;
sru_try_format(sru, fh, fmt->pad, &fmt->format, fmt->which);
format = vsp1_entity_get_pad_format(&sru->entity, fh, fmt->pad,
fmt->which);
*format = fmt->format;
if (fmt->pad == SRU_PAD_SINK) {
format = vsp1_entity_get_pad_format(&sru->entity, fh,
SRU_PAD_SOURCE, fmt->which);
*format = fmt->format;
sru_try_format(sru, fh, SRU_PAD_SOURCE, format, fmt->which);
}
return 0;
}
struct vsp1_sru *vsp1_sru_create(struct vsp1_device *vsp1)
{
struct v4l2_subdev *subdev;
struct vsp1_sru *sru;
int ret;
sru = devm_kzalloc(vsp1->dev, sizeof(*sru), GFP_KERNEL);
if (sru == NULL)
return ERR_PTR(-ENOMEM);
sru->entity.type = VSP1_ENTITY_SRU;
ret = vsp1_entity_init(vsp1, &sru->entity, 2);
if (ret < 0)
return ERR_PTR(ret);
subdev = &sru->entity.subdev;
v4l2_subdev_init(subdev, &sru_ops);
subdev->entity.ops = &vsp1_media_ops;
subdev->internal_ops = &vsp1_subdev_internal_ops;
snprintf(subdev->name, sizeof(subdev->name), "%s sru",
dev_name(vsp1->dev));
v4l2_set_subdevdata(subdev, sru);
subdev->flags |= V4L2_SUBDEV_FL_HAS_DEVNODE;
vsp1_entity_init_formats(subdev, NULL);
v4l2_ctrl_handler_init(&sru->ctrls, 1);
v4l2_ctrl_new_custom(&sru->ctrls, &sru_intensity_control, NULL);
sru->entity.subdev.ctrl_handler = &sru->ctrls;
if (sru->ctrls.error) {
dev_err(vsp1->dev, "sru: failed to initialize controls\n");
ret = sru->ctrls.error;
vsp1_entity_destroy(&sru->entity);
return ERR_PTR(ret);
}
return sru;
}
