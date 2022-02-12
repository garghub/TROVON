static inline void vsp1_bru_write(struct vsp1_bru *bru, u32 reg, u32 data)
{
vsp1_mod_write(&bru->entity, reg, data);
}
static int bru_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct vsp1_bru *bru =
container_of(ctrl->handler, struct vsp1_bru, ctrls);
if (!vsp1_entity_is_streaming(&bru->entity))
return 0;
switch (ctrl->id) {
case V4L2_CID_BG_COLOR:
vsp1_bru_write(bru, VI6_BRU_VIRRPF_COL, ctrl->val |
(0xff << VI6_BRU_VIRRPF_COL_A_SHIFT));
break;
}
return 0;
}
static int bru_s_stream(struct v4l2_subdev *subdev, int enable)
{
struct vsp1_pipeline *pipe = to_vsp1_pipeline(&subdev->entity);
struct vsp1_bru *bru = to_bru(subdev);
struct v4l2_mbus_framefmt *format;
unsigned int flags;
unsigned int i;
int ret;
ret = vsp1_entity_set_streaming(&bru->entity, enable);
if (ret < 0)
return ret;
if (!enable)
return 0;
format = &bru->entity.formats[bru->entity.source_pad];
flags = pipe->output ? pipe->output->format.flags : 0;
vsp1_bru_write(bru, VI6_BRU_INCTRL,
flags & V4L2_PIX_FMT_FLAG_PREMUL_ALPHA ?
0 : VI6_BRU_INCTRL_NRM);
vsp1_bru_write(bru, VI6_BRU_VIRRPF_SIZE,
(format->width << VI6_BRU_VIRRPF_SIZE_HSIZE_SHIFT) |
(format->height << VI6_BRU_VIRRPF_SIZE_VSIZE_SHIFT));
vsp1_bru_write(bru, VI6_BRU_VIRRPF_LOC, 0);
vsp1_bru_write(bru, VI6_BRU_ROP, VI6_BRU_ROP_DSTSEL_BRUIN(1) |
VI6_BRU_ROP_CROP(VI6_ROP_NOP) |
VI6_BRU_ROP_AROP(VI6_ROP_NOP));
for (i = 0; i < bru->entity.source_pad; ++i) {
bool premultiplied = false;
u32 ctrl = 0;
if (bru->inputs[i].rpf) {
ctrl |= VI6_BRU_CTRL_RBC;
premultiplied = bru->inputs[i].rpf->format.flags
& V4L2_PIX_FMT_FLAG_PREMUL_ALPHA;
} else {
ctrl |= VI6_BRU_CTRL_CROP(VI6_ROP_NOP)
| VI6_BRU_CTRL_AROP(VI6_ROP_NOP);
}
if (i == 0)
ctrl |= VI6_BRU_CTRL_DSTSEL_VRPF;
if (i != 1)
ctrl |= VI6_BRU_CTRL_SRCSEL_BRUIN(i);
vsp1_bru_write(bru, VI6_BRU_CTRL(i), ctrl);
vsp1_bru_write(bru, VI6_BRU_BLD(i),
VI6_BRU_BLD_CCMDX_255_SRC_A |
(premultiplied ? VI6_BRU_BLD_CCMDY_COEFY :
VI6_BRU_BLD_CCMDY_SRC_A) |
VI6_BRU_BLD_ACMDX_255_SRC_A |
VI6_BRU_BLD_ACMDY_COEFY |
(0xff << VI6_BRU_BLD_COEFY_SHIFT));
}
return 0;
}
static int bru_enum_mbus_code(struct v4l2_subdev *subdev,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_mbus_code_enum *code)
{
static const unsigned int codes[] = {
MEDIA_BUS_FMT_ARGB8888_1X32,
MEDIA_BUS_FMT_AYUV8_1X32,
};
struct vsp1_bru *bru = to_bru(subdev);
struct v4l2_mbus_framefmt *format;
if (code->pad == BRU_PAD_SINK(0)) {
if (code->index >= ARRAY_SIZE(codes))
return -EINVAL;
code->code = codes[code->index];
} else {
if (code->index)
return -EINVAL;
format = vsp1_entity_get_pad_format(&bru->entity, cfg,
BRU_PAD_SINK(0), code->which);
code->code = format->code;
}
return 0;
}
static int bru_enum_frame_size(struct v4l2_subdev *subdev,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_frame_size_enum *fse)
{
if (fse->index)
return -EINVAL;
if (fse->code != MEDIA_BUS_FMT_ARGB8888_1X32 &&
fse->code != MEDIA_BUS_FMT_AYUV8_1X32)
return -EINVAL;
fse->min_width = BRU_MIN_SIZE;
fse->max_width = BRU_MAX_SIZE;
fse->min_height = BRU_MIN_SIZE;
fse->max_height = BRU_MAX_SIZE;
return 0;
}
static struct v4l2_rect *bru_get_compose(struct vsp1_bru *bru,
struct v4l2_subdev_pad_config *cfg,
unsigned int pad, u32 which)
{
switch (which) {
case V4L2_SUBDEV_FORMAT_TRY:
return v4l2_subdev_get_try_crop(&bru->entity.subdev, cfg, pad);
case V4L2_SUBDEV_FORMAT_ACTIVE:
return &bru->inputs[pad].compose;
default:
return NULL;
}
}
static int bru_get_format(struct v4l2_subdev *subdev, struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_format *fmt)
{
struct vsp1_bru *bru = to_bru(subdev);
fmt->format = *vsp1_entity_get_pad_format(&bru->entity, cfg, fmt->pad,
fmt->which);
return 0;
}
static void bru_try_format(struct vsp1_bru *bru, struct v4l2_subdev_pad_config *cfg,
unsigned int pad, struct v4l2_mbus_framefmt *fmt,
enum v4l2_subdev_format_whence which)
{
struct v4l2_mbus_framefmt *format;
switch (pad) {
case BRU_PAD_SINK(0):
if (fmt->code != MEDIA_BUS_FMT_ARGB8888_1X32 &&
fmt->code != MEDIA_BUS_FMT_AYUV8_1X32)
fmt->code = MEDIA_BUS_FMT_AYUV8_1X32;
break;
default:
format = vsp1_entity_get_pad_format(&bru->entity, cfg,
BRU_PAD_SINK(0), which);
fmt->code = format->code;
break;
}
fmt->width = clamp(fmt->width, BRU_MIN_SIZE, BRU_MAX_SIZE);
fmt->height = clamp(fmt->height, BRU_MIN_SIZE, BRU_MAX_SIZE);
fmt->field = V4L2_FIELD_NONE;
fmt->colorspace = V4L2_COLORSPACE_SRGB;
}
static int bru_set_format(struct v4l2_subdev *subdev, struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_format *fmt)
{
struct vsp1_bru *bru = to_bru(subdev);
struct v4l2_mbus_framefmt *format;
bru_try_format(bru, cfg, fmt->pad, &fmt->format, fmt->which);
format = vsp1_entity_get_pad_format(&bru->entity, cfg, fmt->pad,
fmt->which);
*format = fmt->format;
if (fmt->pad != bru->entity.source_pad) {
struct v4l2_rect *compose;
compose = bru_get_compose(bru, cfg, fmt->pad, fmt->which);
compose->left = 0;
compose->top = 0;
compose->width = format->width;
compose->height = format->height;
}
if (fmt->pad == BRU_PAD_SINK(0)) {
unsigned int i;
for (i = 0; i <= bru->entity.source_pad; ++i) {
format = vsp1_entity_get_pad_format(&bru->entity, cfg,
i, fmt->which);
format->code = fmt->format.code;
}
}
return 0;
}
static int bru_get_selection(struct v4l2_subdev *subdev,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_selection *sel)
{
struct vsp1_bru *bru = to_bru(subdev);
if (sel->pad == bru->entity.source_pad)
return -EINVAL;
switch (sel->target) {
case V4L2_SEL_TGT_COMPOSE_BOUNDS:
sel->r.left = 0;
sel->r.top = 0;
sel->r.width = BRU_MAX_SIZE;
sel->r.height = BRU_MAX_SIZE;
return 0;
case V4L2_SEL_TGT_COMPOSE:
sel->r = *bru_get_compose(bru, cfg, sel->pad, sel->which);
return 0;
default:
return -EINVAL;
}
}
static int bru_set_selection(struct v4l2_subdev *subdev,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_selection *sel)
{
struct vsp1_bru *bru = to_bru(subdev);
struct v4l2_mbus_framefmt *format;
struct v4l2_rect *compose;
if (sel->pad == bru->entity.source_pad)
return -EINVAL;
if (sel->target != V4L2_SEL_TGT_COMPOSE)
return -EINVAL;
format = vsp1_entity_get_pad_format(&bru->entity, cfg,
bru->entity.source_pad, sel->which);
sel->r.left = clamp_t(unsigned int, sel->r.left, 0, format->width - 1);
sel->r.top = clamp_t(unsigned int, sel->r.top, 0, format->height - 1);
format = vsp1_entity_get_pad_format(&bru->entity, cfg, sel->pad,
sel->which);
sel->r.width = format->width;
sel->r.height = format->height;
compose = bru_get_compose(bru, cfg, sel->pad, sel->which);
*compose = sel->r;
return 0;
}
struct vsp1_bru *vsp1_bru_create(struct vsp1_device *vsp1)
{
struct v4l2_subdev *subdev;
struct vsp1_bru *bru;
int ret;
bru = devm_kzalloc(vsp1->dev, sizeof(*bru), GFP_KERNEL);
if (bru == NULL)
return ERR_PTR(-ENOMEM);
bru->entity.type = VSP1_ENTITY_BRU;
ret = vsp1_entity_init(vsp1, &bru->entity,
vsp1->info->num_bru_inputs + 1);
if (ret < 0)
return ERR_PTR(ret);
subdev = &bru->entity.subdev;
v4l2_subdev_init(subdev, &bru_ops);
subdev->entity.ops = &vsp1->media_ops;
subdev->internal_ops = &vsp1_subdev_internal_ops;
snprintf(subdev->name, sizeof(subdev->name), "%s bru",
dev_name(vsp1->dev));
v4l2_set_subdevdata(subdev, bru);
subdev->flags |= V4L2_SUBDEV_FL_HAS_DEVNODE;
vsp1_entity_init_formats(subdev, NULL);
v4l2_ctrl_handler_init(&bru->ctrls, 1);
v4l2_ctrl_new_std(&bru->ctrls, &bru_ctrl_ops, V4L2_CID_BG_COLOR,
0, 0xffffff, 1, 0);
bru->entity.subdev.ctrl_handler = &bru->ctrls;
if (bru->ctrls.error) {
dev_err(vsp1->dev, "bru: failed to initialize controls\n");
ret = bru->ctrls.error;
vsp1_entity_destroy(&bru->entity);
return ERR_PTR(ret);
}
return bru;
}
