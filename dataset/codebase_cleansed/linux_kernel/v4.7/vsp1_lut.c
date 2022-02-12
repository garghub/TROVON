static inline void vsp1_lut_write(struct vsp1_lut *lut, struct vsp1_dl_list *dl,
u32 reg, u32 data)
{
vsp1_dl_list_write(dl, reg, data);
}
static int lut_set_table(struct vsp1_lut *lut, struct vsp1_lut_config *config)
{
struct vsp1_dl_body *dlb;
unsigned int i;
dlb = vsp1_dl_fragment_alloc(lut->entity.vsp1, ARRAY_SIZE(config->lut));
if (!dlb)
return -ENOMEM;
for (i = 0; i < ARRAY_SIZE(config->lut); ++i)
vsp1_dl_fragment_write(dlb, VI6_LUT_TABLE + 4 * i,
config->lut[i]);
mutex_lock(&lut->lock);
swap(lut->lut, dlb);
mutex_unlock(&lut->lock);
vsp1_dl_fragment_free(dlb);
return 0;
}
static long lut_ioctl(struct v4l2_subdev *subdev, unsigned int cmd, void *arg)
{
struct vsp1_lut *lut = to_lut(subdev);
switch (cmd) {
case VIDIOC_VSP1_LUT_CONFIG:
return lut_set_table(lut, arg);
default:
return -ENOIOCTLCMD;
}
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
struct vsp1_dl_list *dl)
{
struct vsp1_lut *lut = to_lut(&entity->subdev);
vsp1_lut_write(lut, dl, VI6_LUT_CTRL, VI6_LUT_CTRL_EN);
mutex_lock(&lut->lock);
if (lut->lut) {
vsp1_dl_list_add_fragment(dl, lut->lut);
lut->lut = NULL;
}
mutex_unlock(&lut->lock);
}
struct vsp1_lut *vsp1_lut_create(struct vsp1_device *vsp1)
{
struct vsp1_lut *lut;
int ret;
lut = devm_kzalloc(vsp1->dev, sizeof(*lut), GFP_KERNEL);
if (lut == NULL)
return ERR_PTR(-ENOMEM);
lut->entity.ops = &lut_entity_ops;
lut->entity.type = VSP1_ENTITY_LUT;
ret = vsp1_entity_init(vsp1, &lut->entity, "lut", 2, &lut_ops);
if (ret < 0)
return ERR_PTR(ret);
return lut;
}
