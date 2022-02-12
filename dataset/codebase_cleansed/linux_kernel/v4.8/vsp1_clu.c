static inline void vsp1_clu_write(struct vsp1_clu *clu, struct vsp1_dl_list *dl,
u32 reg, u32 data)
{
vsp1_dl_list_write(dl, reg, data);
}
static int clu_set_table(struct vsp1_clu *clu, struct v4l2_ctrl *ctrl)
{
struct vsp1_dl_body *dlb;
unsigned int i;
dlb = vsp1_dl_fragment_alloc(clu->entity.vsp1, 1 + 17 * 17 * 17);
if (!dlb)
return -ENOMEM;
vsp1_dl_fragment_write(dlb, VI6_CLU_ADDR, 0);
for (i = 0; i < 17 * 17 * 17; ++i)
vsp1_dl_fragment_write(dlb, VI6_CLU_DATA, ctrl->p_new.p_u32[i]);
spin_lock_irq(&clu->lock);
swap(clu->clu, dlb);
spin_unlock_irq(&clu->lock);
vsp1_dl_fragment_free(dlb);
return 0;
}
static int clu_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct vsp1_clu *clu =
container_of(ctrl->handler, struct vsp1_clu, ctrls);
switch (ctrl->id) {
case V4L2_CID_VSP1_CLU_TABLE:
clu_set_table(clu, ctrl);
break;
case V4L2_CID_VSP1_CLU_MODE:
clu->mode = ctrl->val;
break;
}
return 0;
}
static int clu_enum_mbus_code(struct v4l2_subdev *subdev,
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
static int clu_enum_frame_size(struct v4l2_subdev *subdev,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_frame_size_enum *fse)
{
return vsp1_subdev_enum_frame_size(subdev, cfg, fse, CLU_MIN_SIZE,
CLU_MIN_SIZE, CLU_MAX_SIZE,
CLU_MAX_SIZE);
}
static int clu_set_format(struct v4l2_subdev *subdev,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_format *fmt)
{
struct vsp1_clu *clu = to_clu(subdev);
struct v4l2_subdev_pad_config *config;
struct v4l2_mbus_framefmt *format;
config = vsp1_entity_get_pad_config(&clu->entity, cfg, fmt->which);
if (!config)
return -EINVAL;
if (fmt->format.code != MEDIA_BUS_FMT_ARGB8888_1X32 &&
fmt->format.code != MEDIA_BUS_FMT_AHSV8888_1X32 &&
fmt->format.code != MEDIA_BUS_FMT_AYUV8_1X32)
fmt->format.code = MEDIA_BUS_FMT_AYUV8_1X32;
format = vsp1_entity_get_pad_format(&clu->entity, config, fmt->pad);
if (fmt->pad == CLU_PAD_SOURCE) {
fmt->format = *format;
return 0;
}
format->code = fmt->format.code;
format->width = clamp_t(unsigned int, fmt->format.width,
CLU_MIN_SIZE, CLU_MAX_SIZE);
format->height = clamp_t(unsigned int, fmt->format.height,
CLU_MIN_SIZE, CLU_MAX_SIZE);
format->field = V4L2_FIELD_NONE;
format->colorspace = V4L2_COLORSPACE_SRGB;
fmt->format = *format;
format = vsp1_entity_get_pad_format(&clu->entity, config,
CLU_PAD_SOURCE);
*format = fmt->format;
return 0;
}
static void clu_configure(struct vsp1_entity *entity,
struct vsp1_pipeline *pipe,
struct vsp1_dl_list *dl, bool full)
{
struct vsp1_clu *clu = to_clu(&entity->subdev);
struct vsp1_dl_body *dlb;
unsigned long flags;
u32 ctrl = VI6_CLU_CTRL_AAI | VI6_CLU_CTRL_MVS | VI6_CLU_CTRL_EN;
if (full) {
struct v4l2_mbus_framefmt *format;
format = vsp1_entity_get_pad_format(&clu->entity,
clu->entity.config,
CLU_PAD_SINK);
clu->yuv_mode = format->code == MEDIA_BUS_FMT_AYUV8_1X32;
return;
}
if (clu->mode == V4L2_CID_VSP1_CLU_MODE_2D && clu->yuv_mode)
ctrl |= VI6_CLU_CTRL_AX1I_2D | VI6_CLU_CTRL_AX2I_2D
| VI6_CLU_CTRL_OS0_2D | VI6_CLU_CTRL_OS1_2D
| VI6_CLU_CTRL_OS2_2D | VI6_CLU_CTRL_M2D;
vsp1_clu_write(clu, dl, VI6_CLU_CTRL, ctrl);
spin_lock_irqsave(&clu->lock, flags);
dlb = clu->clu;
clu->clu = NULL;
spin_unlock_irqrestore(&clu->lock, flags);
if (dlb)
vsp1_dl_list_add_fragment(dl, dlb);
}
struct vsp1_clu *vsp1_clu_create(struct vsp1_device *vsp1)
{
struct vsp1_clu *clu;
int ret;
clu = devm_kzalloc(vsp1->dev, sizeof(*clu), GFP_KERNEL);
if (clu == NULL)
return ERR_PTR(-ENOMEM);
spin_lock_init(&clu->lock);
clu->entity.ops = &clu_entity_ops;
clu->entity.type = VSP1_ENTITY_CLU;
ret = vsp1_entity_init(vsp1, &clu->entity, "clu", 2, &clu_ops,
MEDIA_ENT_F_PROC_VIDEO_LUT);
if (ret < 0)
return ERR_PTR(ret);
v4l2_ctrl_handler_init(&clu->ctrls, 2);
v4l2_ctrl_new_custom(&clu->ctrls, &clu_table_control, NULL);
v4l2_ctrl_new_custom(&clu->ctrls, &clu_mode_control, NULL);
clu->entity.subdev.ctrl_handler = &clu->ctrls;
if (clu->ctrls.error) {
dev_err(vsp1->dev, "clu: failed to initialize controls\n");
ret = clu->ctrls.error;
vsp1_entity_destroy(&clu->entity);
return ERR_PTR(ret);
}
v4l2_ctrl_handler_setup(&clu->ctrls);
return clu;
}
