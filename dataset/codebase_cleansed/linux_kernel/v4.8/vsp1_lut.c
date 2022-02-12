static inline void vsp1_lut_write(struct vsp1_lut *lut, struct vsp1_dl_list *dl,
u32 reg, u32 data)
{
vsp1_dl_list_write(dl, reg, data);
}
static int lut_set_table(struct vsp1_lut *lut, struct v4l2_ctrl *ctrl)
{
struct vsp1_dl_body *dlb;
unsigned int i;
dlb = vsp1_dl_fragment_alloc(lut->entity.vsp1, 256);
if (!dlb)
return -ENOMEM;
for (i = 0; i < 256; ++i)
vsp1_dl_fragment_write(dlb, VI6_LUT_TABLE + 4 * i,
ctrl->p_new.p_u32[i]);
spin_lock_irq(&lut->lock);
swap(lut->lut, dlb);
spin_unlock_irq(&lut->lock);
vsp1_dl_fragment_free(dlb);
return 0;
}
static int lut_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct vsp1_lut *lut =
container_of(ctrl->handler, struct vsp1_lut, ctrls);
switch (ctrl->id) {
case V4L2_CID_VSP1_LUT_TABLE:
lut_set_table(lut, ctrl);
break;
}
return 0;
}
static int lut_enum_mbus_code(struct v4l2_subdev *subdev,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_mbus_code_enum *code)
{
static const unsigned int codes[] = {
MEDIA_BUS_FMT_ARGB8888_1X32,
MEDIA_BUS_FMT_AHSV8888_1X32,
MEDIA_BUS_FMT_AYUV8_1X32,
};
return vsp1_subdev_enum_mbus_code(subdev, cfg, code, codes,
ARRAY_SIZE(codes));
}
static int lut_enum_frame_size(struct v4l2_subdev *subdev,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_frame_size_enum *fse)
{
return vsp1_subdev_enum_frame_size(subdev, cfg, fse, LUT_MIN_SIZE,
LUT_MIN_SIZE, LUT_MAX_SIZE,
LUT_MAX_SIZE);
}
static int lut_set_format(struct v4l2_subdev *subdev,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_format *fmt)
{
struct vsp1_lut *lut = to_lut(subdev);
struct v4l2_subdev_pad_config *config;
struct v4l2_mbus_framefmt *format;
config = vsp1_entity_get_pad_config(&lut->entity, cfg, fmt->which);
if (!config)
return -EINVAL;
if (fmt->format.code != MEDIA_BUS_FMT_ARGB8888_1X32 &&
fmt->format.code != MEDIA_BUS_FMT_AHSV8888_1X32 &&
fmt->format.code != MEDIA_BUS_FMT_AYUV8_1X32)
fmt->format.code = MEDIA_BUS_FMT_AYUV8_1X32;
format = vsp1_entity_get_pad_format(&lut->entity, config, fmt->pad);
if (fmt->pad == LUT_PAD_SOURCE) {
fmt->format = *format;
return 0;
}
format->code = fmt->format.code;
format->width = clamp_t(unsigned int, fmt->format.width,
LUT_MIN_SIZE, LUT_MAX_SIZE);
format->height = clamp_t(unsigned int, fmt->format.height,
LUT_MIN_SIZE, LUT_MAX_SIZE);
format->field = V4L2_FIELD_NONE;
format->colorspace = V4L2_COLORSPACE_SRGB;
fmt->format = *format;
format = vsp1_entity_get_pad_format(&lut->entity, config,
LUT_PAD_SOURCE);
*format = fmt->format;
return 0;
}
static void lut_configure(struct vsp1_entity *entity,
struct vsp1_pipeline *pipe,
struct vsp1_dl_list *dl, bool full)
{
struct vsp1_lut *lut = to_lut(&entity->subdev);
struct vsp1_dl_body *dlb;
unsigned long flags;
if (full) {
vsp1_lut_write(lut, dl, VI6_LUT_CTRL, VI6_LUT_CTRL_EN);
return;
}
spin_lock_irqsave(&lut->lock, flags);
dlb = lut->lut;
lut->lut = NULL;
spin_unlock_irqrestore(&lut->lock, flags);
if (dlb)
vsp1_dl_list_add_fragment(dl, dlb);
}
struct vsp1_lut *vsp1_lut_create(struct vsp1_device *vsp1)
{
struct vsp1_lut *lut;
int ret;
lut = devm_kzalloc(vsp1->dev, sizeof(*lut), GFP_KERNEL);
if (lut == NULL)
return ERR_PTR(-ENOMEM);
spin_lock_init(&lut->lock);
lut->entity.ops = &lut_entity_ops;
lut->entity.type = VSP1_ENTITY_LUT;
ret = vsp1_entity_init(vsp1, &lut->entity, "lut", 2, &lut_ops,
MEDIA_ENT_F_PROC_VIDEO_LUT);
if (ret < 0)
return ERR_PTR(ret);
v4l2_ctrl_handler_init(&lut->ctrls, 1);
v4l2_ctrl_new_custom(&lut->ctrls, &lut_table_control, NULL);
lut->entity.subdev.ctrl_handler = &lut->ctrls;
if (lut->ctrls.error) {
dev_err(vsp1->dev, "lut: failed to initialize controls\n");
ret = lut->ctrls.error;
vsp1_entity_destroy(&lut->entity);
return ERR_PTR(ret);
}
v4l2_ctrl_handler_setup(&lut->ctrls);
return lut;
}
