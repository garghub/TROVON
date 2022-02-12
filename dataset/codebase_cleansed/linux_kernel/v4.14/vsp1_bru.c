static inline void vsp1_bru_write(struct vsp1_bru *bru, struct vsp1_dl_list *dl,
u32 reg, u32 data)
{
vsp1_dl_list_write(dl, bru->base + reg, data);
}
static int bru_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct vsp1_bru *bru =
container_of(ctrl->handler, struct vsp1_bru, ctrls);
switch (ctrl->id) {
case V4L2_CID_BG_COLOR:
bru->bgcolor = ctrl->val;
break;
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
return vsp1_subdev_enum_mbus_code(subdev, cfg, code, codes,
ARRAY_SIZE(codes));
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
unsigned int pad)
{
return v4l2_subdev_get_try_compose(&bru->entity.subdev, cfg, pad);
}
static void bru_try_format(struct vsp1_bru *bru,
struct v4l2_subdev_pad_config *config,
unsigned int pad, struct v4l2_mbus_framefmt *fmt)
{
struct v4l2_mbus_framefmt *format;
switch (pad) {
case BRU_PAD_SINK(0):
if (fmt->code != MEDIA_BUS_FMT_ARGB8888_1X32 &&
fmt->code != MEDIA_BUS_FMT_AYUV8_1X32)
fmt->code = MEDIA_BUS_FMT_AYUV8_1X32;
break;
default:
format = vsp1_entity_get_pad_format(&bru->entity, config,
BRU_PAD_SINK(0));
fmt->code = format->code;
break;
}
fmt->width = clamp(fmt->width, BRU_MIN_SIZE, BRU_MAX_SIZE);
fmt->height = clamp(fmt->height, BRU_MIN_SIZE, BRU_MAX_SIZE);
fmt->field = V4L2_FIELD_NONE;
fmt->colorspace = V4L2_COLORSPACE_SRGB;
}
static int bru_set_format(struct v4l2_subdev *subdev,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_format *fmt)
{
struct vsp1_bru *bru = to_bru(subdev);
struct v4l2_subdev_pad_config *config;
struct v4l2_mbus_framefmt *format;
int ret = 0;
mutex_lock(&bru->entity.lock);
config = vsp1_entity_get_pad_config(&bru->entity, cfg, fmt->which);
if (!config) {
ret = -EINVAL;
goto done;
}
bru_try_format(bru, config, fmt->pad, &fmt->format);
format = vsp1_entity_get_pad_format(&bru->entity, config, fmt->pad);
*format = fmt->format;
if (fmt->pad != bru->entity.source_pad) {
struct v4l2_rect *compose;
compose = bru_get_compose(bru, config, fmt->pad);
compose->left = 0;
compose->top = 0;
compose->width = format->width;
compose->height = format->height;
}
if (fmt->pad == BRU_PAD_SINK(0)) {
unsigned int i;
for (i = 0; i <= bru->entity.source_pad; ++i) {
format = vsp1_entity_get_pad_format(&bru->entity,
config, i);
format->code = fmt->format.code;
}
}
done:
mutex_unlock(&bru->entity.lock);
return ret;
}
static int bru_get_selection(struct v4l2_subdev *subdev,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_selection *sel)
{
struct vsp1_bru *bru = to_bru(subdev);
struct v4l2_subdev_pad_config *config;
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
config = vsp1_entity_get_pad_config(&bru->entity, cfg,
sel->which);
if (!config)
return -EINVAL;
mutex_lock(&bru->entity.lock);
sel->r = *bru_get_compose(bru, config, sel->pad);
mutex_unlock(&bru->entity.lock);
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
struct v4l2_subdev_pad_config *config;
struct v4l2_mbus_framefmt *format;
struct v4l2_rect *compose;
int ret = 0;
if (sel->pad == bru->entity.source_pad)
return -EINVAL;
if (sel->target != V4L2_SEL_TGT_COMPOSE)
return -EINVAL;
mutex_lock(&bru->entity.lock);
config = vsp1_entity_get_pad_config(&bru->entity, cfg, sel->which);
if (!config) {
ret = -EINVAL;
goto done;
}
format = vsp1_entity_get_pad_format(&bru->entity, config,
bru->entity.source_pad);
sel->r.left = clamp_t(unsigned int, sel->r.left, 0, format->width - 1);
sel->r.top = clamp_t(unsigned int, sel->r.top, 0, format->height - 1);
format = vsp1_entity_get_pad_format(&bru->entity, config, sel->pad);
sel->r.width = format->width;
sel->r.height = format->height;
compose = bru_get_compose(bru, config, sel->pad);
*compose = sel->r;
done:
mutex_unlock(&bru->entity.lock);
return ret;
}
static void bru_configure(struct vsp1_entity *entity,
struct vsp1_pipeline *pipe,
struct vsp1_dl_list *dl,
enum vsp1_entity_params params)
{
struct vsp1_bru *bru = to_bru(&entity->subdev);
struct v4l2_mbus_framefmt *format;
unsigned int flags;
unsigned int i;
if (params != VSP1_ENTITY_PARAMS_INIT)
return;
format = vsp1_entity_get_pad_format(&bru->entity, bru->entity.config,
bru->entity.source_pad);
flags = pipe->output ? pipe->output->format.flags : 0;
vsp1_bru_write(bru, dl, VI6_BRU_INCTRL,
flags & V4L2_PIX_FMT_FLAG_PREMUL_ALPHA ?
0 : VI6_BRU_INCTRL_NRM);
vsp1_bru_write(bru, dl, VI6_BRU_VIRRPF_SIZE,
(format->width << VI6_BRU_VIRRPF_SIZE_HSIZE_SHIFT) |
(format->height << VI6_BRU_VIRRPF_SIZE_VSIZE_SHIFT));
vsp1_bru_write(bru, dl, VI6_BRU_VIRRPF_LOC, 0);
vsp1_bru_write(bru, dl, VI6_BRU_VIRRPF_COL, bru->bgcolor |
(0xff << VI6_BRU_VIRRPF_COL_A_SHIFT));
if (entity->type == VSP1_ENTITY_BRU)
vsp1_bru_write(bru, dl, VI6_BRU_ROP,
VI6_BRU_ROP_DSTSEL_BRUIN(1) |
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
if (!(entity->type == VSP1_ENTITY_BRU && i == 1))
ctrl |= VI6_BRU_CTRL_SRCSEL_BRUIN(i);
vsp1_bru_write(bru, dl, VI6_BRU_CTRL(i), ctrl);
vsp1_bru_write(bru, dl, VI6_BRU_BLD(i),
VI6_BRU_BLD_CCMDX_255_SRC_A |
(premultiplied ? VI6_BRU_BLD_CCMDY_COEFY :
VI6_BRU_BLD_CCMDY_SRC_A) |
VI6_BRU_BLD_ACMDX_255_SRC_A |
VI6_BRU_BLD_ACMDY_COEFY |
(0xff << VI6_BRU_BLD_COEFY_SHIFT));
}
}
struct vsp1_bru *vsp1_bru_create(struct vsp1_device *vsp1,
enum vsp1_entity_type type)
{
struct vsp1_bru *bru;
unsigned int num_pads;
const char *name;
int ret;
bru = devm_kzalloc(vsp1->dev, sizeof(*bru), GFP_KERNEL);
if (bru == NULL)
return ERR_PTR(-ENOMEM);
bru->base = type == VSP1_ENTITY_BRU ? VI6_BRU_BASE : VI6_BRS_BASE;
bru->entity.ops = &bru_entity_ops;
bru->entity.type = type;
if (type == VSP1_ENTITY_BRU) {
num_pads = vsp1->info->num_bru_inputs + 1;
name = "bru";
} else {
num_pads = 3;
name = "brs";
}
ret = vsp1_entity_init(vsp1, &bru->entity, name, num_pads, &bru_ops,
MEDIA_ENT_F_PROC_VIDEO_COMPOSER);
if (ret < 0)
return ERR_PTR(ret);
v4l2_ctrl_handler_init(&bru->ctrls, 1);
v4l2_ctrl_new_std(&bru->ctrls, &bru_ctrl_ops, V4L2_CID_BG_COLOR,
0, 0xffffff, 1, 0);
bru->bgcolor = 0;
bru->entity.subdev.ctrl_handler = &bru->ctrls;
if (bru->ctrls.error) {
dev_err(vsp1->dev, "%s: failed to initialize controls\n", name);
ret = bru->ctrls.error;
vsp1_entity_destroy(&bru->entity);
return ERR_PTR(ret);
}
return bru;
}
