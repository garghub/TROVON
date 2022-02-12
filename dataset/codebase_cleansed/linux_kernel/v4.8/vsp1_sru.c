static inline void vsp1_sru_write(struct vsp1_sru *sru, struct vsp1_dl_list *dl,
u32 reg, u32 data)
{
vsp1_dl_list_write(dl, reg, data);
}
static int sru_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct vsp1_sru *sru =
container_of(ctrl->handler, struct vsp1_sru, ctrls);
switch (ctrl->id) {
case V4L2_CID_VSP1_SRU_INTENSITY:
sru->intensity = ctrl->val;
break;
}
return 0;
}
static int sru_enum_mbus_code(struct v4l2_subdev *subdev,
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
static int sru_enum_frame_size(struct v4l2_subdev *subdev,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_frame_size_enum *fse)
{
struct vsp1_sru *sru = to_sru(subdev);
struct v4l2_subdev_pad_config *config;
struct v4l2_mbus_framefmt *format;
config = vsp1_entity_get_pad_config(&sru->entity, cfg, fse->which);
if (!config)
return -EINVAL;
format = vsp1_entity_get_pad_format(&sru->entity, config, SRU_PAD_SINK);
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
static void sru_try_format(struct vsp1_sru *sru,
struct v4l2_subdev_pad_config *config,
unsigned int pad, struct v4l2_mbus_framefmt *fmt)
{
struct v4l2_mbus_framefmt *format;
unsigned int input_area;
unsigned int output_area;
switch (pad) {
case SRU_PAD_SINK:
if (fmt->code != MEDIA_BUS_FMT_ARGB8888_1X32 &&
fmt->code != MEDIA_BUS_FMT_AYUV8_1X32)
fmt->code = MEDIA_BUS_FMT_AYUV8_1X32;
fmt->width = clamp(fmt->width, SRU_MIN_SIZE, SRU_MAX_SIZE);
fmt->height = clamp(fmt->height, SRU_MIN_SIZE, SRU_MAX_SIZE);
break;
case SRU_PAD_SOURCE:
format = vsp1_entity_get_pad_format(&sru->entity, config,
SRU_PAD_SINK);
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
static int sru_set_format(struct v4l2_subdev *subdev,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_format *fmt)
{
struct vsp1_sru *sru = to_sru(subdev);
struct v4l2_subdev_pad_config *config;
struct v4l2_mbus_framefmt *format;
config = vsp1_entity_get_pad_config(&sru->entity, cfg, fmt->which);
if (!config)
return -EINVAL;
sru_try_format(sru, config, fmt->pad, &fmt->format);
format = vsp1_entity_get_pad_format(&sru->entity, config, fmt->pad);
*format = fmt->format;
if (fmt->pad == SRU_PAD_SINK) {
format = vsp1_entity_get_pad_format(&sru->entity, config,
SRU_PAD_SOURCE);
*format = fmt->format;
sru_try_format(sru, config, SRU_PAD_SOURCE, format);
}
return 0;
}
static void sru_configure(struct vsp1_entity *entity,
struct vsp1_pipeline *pipe,
struct vsp1_dl_list *dl, bool full)
{
const struct vsp1_sru_param *param;
struct vsp1_sru *sru = to_sru(&entity->subdev);
struct v4l2_mbus_framefmt *input;
struct v4l2_mbus_framefmt *output;
u32 ctrl0;
if (!full)
return;
input = vsp1_entity_get_pad_format(&sru->entity, sru->entity.config,
SRU_PAD_SINK);
output = vsp1_entity_get_pad_format(&sru->entity, sru->entity.config,
SRU_PAD_SOURCE);
if (input->code == MEDIA_BUS_FMT_ARGB8888_1X32)
ctrl0 = VI6_SRU_CTRL0_PARAM2 | VI6_SRU_CTRL0_PARAM3
| VI6_SRU_CTRL0_PARAM4;
else
ctrl0 = VI6_SRU_CTRL0_PARAM3;
if (input->width != output->width)
ctrl0 |= VI6_SRU_CTRL0_MODE_UPSCALE;
param = &vsp1_sru_params[sru->intensity - 1];
ctrl0 |= param->ctrl0;
vsp1_sru_write(sru, dl, VI6_SRU_CTRL0, ctrl0);
vsp1_sru_write(sru, dl, VI6_SRU_CTRL1, VI6_SRU_CTRL1_PARAM5);
vsp1_sru_write(sru, dl, VI6_SRU_CTRL2, param->ctrl2);
}
struct vsp1_sru *vsp1_sru_create(struct vsp1_device *vsp1)
{
struct vsp1_sru *sru;
int ret;
sru = devm_kzalloc(vsp1->dev, sizeof(*sru), GFP_KERNEL);
if (sru == NULL)
return ERR_PTR(-ENOMEM);
sru->entity.ops = &sru_entity_ops;
sru->entity.type = VSP1_ENTITY_SRU;
ret = vsp1_entity_init(vsp1, &sru->entity, "sru", 2, &sru_ops,
MEDIA_ENT_F_PROC_VIDEO_SCALER);
if (ret < 0)
return ERR_PTR(ret);
v4l2_ctrl_handler_init(&sru->ctrls, 1);
v4l2_ctrl_new_custom(&sru->ctrls, &sru_intensity_control, NULL);
sru->intensity = 1;
sru->entity.subdev.ctrl_handler = &sru->ctrls;
if (sru->ctrls.error) {
dev_err(vsp1->dev, "sru: failed to initialize controls\n");
ret = sru->ctrls.error;
vsp1_entity_destroy(&sru->entity);
return ERR_PTR(ret);
}
return sru;
}
