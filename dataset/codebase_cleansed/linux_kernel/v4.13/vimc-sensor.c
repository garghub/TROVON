static int vimc_sen_init_cfg(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg)
{
unsigned int i;
for (i = 0; i < sd->entity.num_pads; i++) {
struct v4l2_mbus_framefmt *mf;
mf = v4l2_subdev_get_try_format(sd, cfg, i);
*mf = fmt_default;
}
return 0;
}
static int vimc_sen_enum_mbus_code(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_mbus_code_enum *code)
{
const struct vimc_pix_map *vpix = vimc_pix_map_by_index(code->index);
if (!vpix)
return -EINVAL;
code->code = vpix->code;
return 0;
}
static int vimc_sen_enum_frame_size(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_frame_size_enum *fse)
{
const struct vimc_pix_map *vpix;
if (fse->index)
return -EINVAL;
vpix = vimc_pix_map_by_code(fse->code);
if (!vpix)
return -EINVAL;
fse->min_width = VIMC_FRAME_MIN_WIDTH;
fse->max_width = VIMC_FRAME_MAX_WIDTH;
fse->min_height = VIMC_FRAME_MIN_HEIGHT;
fse->max_height = VIMC_FRAME_MAX_HEIGHT;
return 0;
}
static int vimc_sen_get_fmt(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_format *fmt)
{
struct vimc_sen_device *vsen =
container_of(sd, struct vimc_sen_device, sd);
fmt->format = fmt->which == V4L2_SUBDEV_FORMAT_TRY ?
*v4l2_subdev_get_try_format(sd, cfg, fmt->pad) :
vsen->mbus_format;
return 0;
}
static void vimc_sen_tpg_s_format(struct vimc_sen_device *vsen)
{
const struct vimc_pix_map *vpix =
vimc_pix_map_by_code(vsen->mbus_format.code);
tpg_reset_source(&vsen->tpg, vsen->mbus_format.width,
vsen->mbus_format.height, vsen->mbus_format.field);
tpg_s_bytesperline(&vsen->tpg, 0, vsen->mbus_format.width * vpix->bpp);
tpg_s_buf_height(&vsen->tpg, vsen->mbus_format.height);
tpg_s_fourcc(&vsen->tpg, vpix->pixelformat);
tpg_s_field(&vsen->tpg, vsen->mbus_format.field, false);
tpg_s_colorspace(&vsen->tpg, vsen->mbus_format.colorspace);
tpg_s_ycbcr_enc(&vsen->tpg, vsen->mbus_format.ycbcr_enc);
tpg_s_quantization(&vsen->tpg, vsen->mbus_format.quantization);
tpg_s_xfer_func(&vsen->tpg, vsen->mbus_format.xfer_func);
}
static void vimc_sen_adjust_fmt(struct v4l2_mbus_framefmt *fmt)
{
const struct vimc_pix_map *vpix;
vpix = vimc_pix_map_by_code(fmt->code);
if (!vpix)
fmt->code = fmt_default.code;
fmt->width = clamp_t(u32, fmt->width, VIMC_FRAME_MIN_WIDTH,
VIMC_FRAME_MAX_WIDTH) & ~1;
fmt->height = clamp_t(u32, fmt->height, VIMC_FRAME_MIN_HEIGHT,
VIMC_FRAME_MAX_HEIGHT) & ~1;
if (fmt->field == V4L2_FIELD_ANY || fmt->field == V4L2_FIELD_ALTERNATE)
fmt->field = fmt_default.field;
vimc_colorimetry_clamp(fmt);
}
static int vimc_sen_set_fmt(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_format *fmt)
{
struct vimc_sen_device *vsen = v4l2_get_subdevdata(sd);
struct v4l2_mbus_framefmt *mf;
if (fmt->which == V4L2_SUBDEV_FORMAT_ACTIVE) {
if (vsen->frame)
return -EBUSY;
mf = &vsen->mbus_format;
} else {
mf = v4l2_subdev_get_try_format(sd, cfg, fmt->pad);
}
vimc_sen_adjust_fmt(&fmt->format);
dev_dbg(vsen->dev, "%s: format update: "
"old:%dx%d (0x%x, %d, %d, %d, %d) "
"new:%dx%d (0x%x, %d, %d, %d, %d)\n", vsen->sd.name,
mf->width, mf->height, mf->code,
mf->colorspace, mf->quantization,
mf->xfer_func, mf->ycbcr_enc,
fmt->format.width, fmt->format.height, fmt->format.code,
fmt->format.colorspace, fmt->format.quantization,
fmt->format.xfer_func, fmt->format.ycbcr_enc);
*mf = fmt->format;
return 0;
}
static int vimc_sen_tpg_thread(void *data)
{
struct vimc_sen_device *vsen = data;
unsigned int i;
set_freezable();
set_current_state(TASK_UNINTERRUPTIBLE);
for (;;) {
try_to_freeze();
if (kthread_should_stop())
break;
tpg_fill_plane_buffer(&vsen->tpg, 0, 0, vsen->frame);
for (i = 0; i < vsen->sd.entity.num_pads; i++)
vimc_propagate_frame(&vsen->sd.entity.pads[i],
vsen->frame);
schedule_timeout(HZ/60);
}
return 0;
}
static int vimc_sen_s_stream(struct v4l2_subdev *sd, int enable)
{
struct vimc_sen_device *vsen =
container_of(sd, struct vimc_sen_device, sd);
int ret;
if (enable) {
const struct vimc_pix_map *vpix;
unsigned int frame_size;
if (vsen->kthread_sen)
return 0;
vpix = vimc_pix_map_by_code(vsen->mbus_format.code);
frame_size = vsen->mbus_format.width * vpix->bpp *
vsen->mbus_format.height;
vsen->frame = vmalloc(frame_size);
if (!vsen->frame)
return -ENOMEM;
vimc_sen_tpg_s_format(vsen);
vsen->kthread_sen = kthread_run(vimc_sen_tpg_thread, vsen,
"%s-sen", vsen->sd.v4l2_dev->name);
if (IS_ERR(vsen->kthread_sen)) {
dev_err(vsen->dev, "%s: kernel_thread() failed\n",
vsen->sd.name);
vfree(vsen->frame);
vsen->frame = NULL;
return PTR_ERR(vsen->kthread_sen);
}
} else {
if (!vsen->kthread_sen)
return 0;
ret = kthread_stop(vsen->kthread_sen);
if (ret)
return ret;
vsen->kthread_sen = NULL;
vfree(vsen->frame);
vsen->frame = NULL;
return 0;
}
return 0;
}
static void vimc_sen_comp_unbind(struct device *comp, struct device *master,
void *master_data)
{
struct vimc_ent_device *ved = dev_get_drvdata(comp);
struct vimc_sen_device *vsen =
container_of(ved, struct vimc_sen_device, ved);
vimc_ent_sd_unregister(ved, &vsen->sd);
tpg_free(&vsen->tpg);
kfree(vsen);
}
static int vimc_sen_comp_bind(struct device *comp, struct device *master,
void *master_data)
{
struct v4l2_device *v4l2_dev = master_data;
struct vimc_platform_data *pdata = comp->platform_data;
struct vimc_sen_device *vsen;
int ret;
vsen = kzalloc(sizeof(*vsen), GFP_KERNEL);
if (!vsen)
return -ENOMEM;
ret = vimc_ent_sd_register(&vsen->ved, &vsen->sd, v4l2_dev,
pdata->entity_name,
MEDIA_ENT_F_ATV_DECODER, 1,
(const unsigned long[1]) {MEDIA_PAD_FL_SOURCE},
&vimc_sen_ops);
if (ret)
goto err_free_vsen;
dev_set_drvdata(comp, &vsen->ved);
vsen->dev = comp;
vsen->mbus_format = fmt_default;
tpg_init(&vsen->tpg, vsen->mbus_format.width,
vsen->mbus_format.height);
ret = tpg_alloc(&vsen->tpg, VIMC_FRAME_MAX_WIDTH);
if (ret)
goto err_unregister_ent_sd;
return 0;
err_unregister_ent_sd:
vimc_ent_sd_unregister(&vsen->ved, &vsen->sd);
err_free_vsen:
kfree(vsen);
return ret;
}
static int vimc_sen_probe(struct platform_device *pdev)
{
return component_add(&pdev->dev, &vimc_sen_comp_ops);
}
static int vimc_sen_remove(struct platform_device *pdev)
{
component_del(&pdev->dev, &vimc_sen_comp_ops);
return 0;
}
