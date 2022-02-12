static int vimc_sen_enum_mbus_code(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_mbus_code_enum *code)
{
struct vimc_sen_device *vsen =
container_of(sd, struct vimc_sen_device, sd);
if (code->index)
return -EINVAL;
code->code = vsen->mbus_format.code;
return 0;
}
static int vimc_sen_enum_frame_size(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_frame_size_enum *fse)
{
struct vimc_sen_device *vsen =
container_of(sd, struct vimc_sen_device, sd);
if (fse->index)
return -EINVAL;
if (fse->code != vsen->mbus_format.code)
return -EINVAL;
fse->min_width = vsen->mbus_format.width;
fse->max_width = vsen->mbus_format.width;
fse->min_height = vsen->mbus_format.height;
fse->max_height = vsen->mbus_format.height;
return 0;
}
static int vimc_sen_get_fmt(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_format *format)
{
struct vimc_sen_device *vsen =
container_of(sd, struct vimc_sen_device, sd);
format->format = vsen->mbus_format;
return 0;
}
static int vimc_thread_sen(void *data)
{
struct vimc_sen_device *vsen = data;
unsigned int i;
set_freezable();
set_current_state(TASK_UNINTERRUPTIBLE);
for (;;) {
try_to_freeze();
if (kthread_should_stop())
break;
memset(vsen->frame, 100, vsen->frame_size);
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
if (vsen->kthread_sen)
return -EINVAL;
vpix = vimc_pix_map_by_code(vsen->mbus_format.code);
vsen->frame_size = vsen->mbus_format.width * vpix->bpp *
vsen->mbus_format.height;
vsen->frame = vmalloc(vsen->frame_size);
if (!vsen->frame)
return -ENOMEM;
vsen->kthread_sen = kthread_run(vimc_thread_sen, vsen, "%s-sen",
vsen->sd.v4l2_dev->name);
if (IS_ERR(vsen->kthread_sen)) {
dev_err(vsen->sd.v4l2_dev->dev,
"%s: kernel_thread() failed\n", vsen->sd.name);
vfree(vsen->frame);
vsen->frame = NULL;
return PTR_ERR(vsen->kthread_sen);
}
} else {
if (!vsen->kthread_sen)
return -EINVAL;
ret = kthread_stop(vsen->kthread_sen);
vsen->kthread_sen = NULL;
vfree(vsen->frame);
vsen->frame = NULL;
return ret;
}
return 0;
}
static void vimc_sen_destroy(struct vimc_ent_device *ved)
{
struct vimc_sen_device *vsen =
container_of(ved, struct vimc_sen_device, ved);
v4l2_device_unregister_subdev(&vsen->sd);
media_entity_cleanup(ved->ent);
kfree(vsen);
}
struct vimc_ent_device *vimc_sen_create(struct v4l2_device *v4l2_dev,
const char *const name,
u16 num_pads,
const unsigned long *pads_flag)
{
struct vimc_sen_device *vsen;
unsigned int i;
int ret;
if (!name || !num_pads || !pads_flag)
return ERR_PTR(-EINVAL);
for (i = 0; i < num_pads; i++)
if (!(pads_flag[i] & MEDIA_PAD_FL_SOURCE))
return ERR_PTR(-EINVAL);
vsen = kzalloc(sizeof(*vsen), GFP_KERNEL);
if (!vsen)
return ERR_PTR(-ENOMEM);
vsen->ved.pads = vimc_pads_init(num_pads, pads_flag);
if (IS_ERR(vsen->ved.pads)) {
ret = PTR_ERR(vsen->ved.pads);
goto err_free_vsen;
}
vsen->ved.destroy = vimc_sen_destroy;
vsen->ved.ent = &vsen->sd.entity;
v4l2_subdev_init(&vsen->sd, &vimc_sen_ops);
vsen->sd.entity.function = MEDIA_ENT_F_CAM_SENSOR;
vsen->sd.entity.ops = &vimc_sen_mops;
vsen->sd.owner = THIS_MODULE;
strlcpy(vsen->sd.name, name, sizeof(vsen->sd.name));
v4l2_set_subdevdata(&vsen->sd, &vsen->ved);
vsen->sd.flags = V4L2_SUBDEV_FL_HAS_DEVNODE;
ret = media_entity_pads_init(&vsen->sd.entity,
num_pads, vsen->ved.pads);
if (ret)
goto err_clean_pads;
vsen->mbus_format.width = 640;
vsen->mbus_format.height = 480;
vsen->mbus_format.code = MEDIA_BUS_FMT_RGB888_1X24;
vsen->mbus_format.field = V4L2_FIELD_NONE;
vsen->mbus_format.colorspace = V4L2_COLORSPACE_SRGB;
vsen->mbus_format.quantization = V4L2_QUANTIZATION_FULL_RANGE;
vsen->mbus_format.xfer_func = V4L2_XFER_FUNC_SRGB;
ret = v4l2_device_register_subdev(v4l2_dev, &vsen->sd);
if (ret) {
dev_err(vsen->sd.v4l2_dev->dev,
"%s: subdev register failed (err=%d)\n",
vsen->sd.name, ret);
goto err_clean_m_ent;
}
return &vsen->ved;
err_clean_m_ent:
media_entity_cleanup(&vsen->sd.entity);
err_clean_pads:
vimc_pads_cleanup(vsen->ved.pads);
err_free_vsen:
kfree(vsen);
return ERR_PTR(ret);
}
