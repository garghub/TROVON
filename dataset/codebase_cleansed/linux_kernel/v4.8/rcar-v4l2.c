const struct rvin_video_format *rvin_format_from_pixel(u32 pixelformat)
{
int i;
for (i = 0; i < ARRAY_SIZE(rvin_formats); i++)
if (rvin_formats[i].fourcc == pixelformat)
return rvin_formats + i;
return NULL;
}
static u32 rvin_format_bytesperline(struct v4l2_pix_format *pix)
{
const struct rvin_video_format *fmt;
fmt = rvin_format_from_pixel(pix->pixelformat);
if (WARN_ON(!fmt))
return -EINVAL;
return pix->width * fmt->bpp;
}
static u32 rvin_format_sizeimage(struct v4l2_pix_format *pix)
{
if (pix->pixelformat == V4L2_PIX_FMT_NV16)
return pix->bytesperline * pix->height * 2;
return pix->bytesperline * pix->height;
}
static int __rvin_try_format_source(struct rvin_dev *vin,
u32 which,
struct v4l2_pix_format *pix,
struct rvin_source_fmt *source)
{
struct v4l2_subdev *sd;
struct v4l2_subdev_pad_config *pad_cfg;
struct v4l2_subdev_format format = {
.which = which,
};
int ret;
sd = vin_to_source(vin);
v4l2_fill_mbus_format(&format.format, pix, vin->source.code);
pad_cfg = v4l2_subdev_alloc_pad_config(sd);
if (pad_cfg == NULL)
return -ENOMEM;
format.pad = vin->src_pad_idx;
ret = v4l2_device_call_until_err(sd->v4l2_dev, 0, pad, set_fmt,
pad_cfg, &format);
if (ret < 0)
goto cleanup;
v4l2_fill_pix_format(pix, &format.format);
source->width = pix->width;
source->height = pix->height;
vin_dbg(vin, "Source resolution: %ux%u\n", source->width,
source->height);
cleanup:
v4l2_subdev_free_pad_config(pad_cfg);
return 0;
}
static int __rvin_try_format(struct rvin_dev *vin,
u32 which,
struct v4l2_pix_format *pix,
struct rvin_source_fmt *source)
{
const struct rvin_video_format *info;
u32 rwidth, rheight, walign;
rwidth = pix->width;
rheight = pix->height;
info = rvin_format_from_pixel(pix->pixelformat);
if (!info) {
vin_dbg(vin, "Format %x not found, keeping %x\n",
pix->pixelformat, vin->format.pixelformat);
*pix = vin->format;
pix->width = rwidth;
pix->height = rheight;
}
pix->bytesperline = 0;
pix->sizeimage = 0;
__rvin_try_format_source(vin, which, pix, source);
if (source->width != rwidth || source->height != rheight)
rvin_scale_try(vin, pix, rwidth, rheight);
walign = vin->format.pixelformat == V4L2_PIX_FMT_NV16 ? 5 : 1;
v4l_bound_align_image(&pix->width, 2, RVIN_MAX_WIDTH, walign,
&pix->height, 4, RVIN_MAX_HEIGHT, 2, 0);
switch (pix->field) {
case V4L2_FIELD_NONE:
case V4L2_FIELD_TOP:
case V4L2_FIELD_BOTTOM:
case V4L2_FIELD_INTERLACED_TB:
case V4L2_FIELD_INTERLACED_BT:
case V4L2_FIELD_INTERLACED:
break;
default:
pix->field = V4L2_FIELD_NONE;
break;
}
pix->bytesperline = max_t(u32, pix->bytesperline,
rvin_format_bytesperline(pix));
pix->sizeimage = max_t(u32, pix->sizeimage,
rvin_format_sizeimage(pix));
vin_dbg(vin, "Requested %ux%u Got %ux%u bpl: %d size: %d\n",
rwidth, rheight, pix->width, pix->height,
pix->bytesperline, pix->sizeimage);
return 0;
}
static int rvin_querycap(struct file *file, void *priv,
struct v4l2_capability *cap)
{
struct rvin_dev *vin = video_drvdata(file);
strlcpy(cap->driver, KBUILD_MODNAME, sizeof(cap->driver));
strlcpy(cap->card, "R_Car_VIN", sizeof(cap->card));
snprintf(cap->bus_info, sizeof(cap->bus_info), "platform:%s",
dev_name(vin->dev));
return 0;
}
static int rvin_try_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_format *f)
{
struct rvin_dev *vin = video_drvdata(file);
struct rvin_source_fmt source;
return __rvin_try_format(vin, V4L2_SUBDEV_FORMAT_TRY, &f->fmt.pix,
&source);
}
static int rvin_s_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_format *f)
{
struct rvin_dev *vin = video_drvdata(file);
struct rvin_source_fmt source;
int ret;
if (vb2_is_busy(&vin->queue))
return -EBUSY;
ret = __rvin_try_format(vin, V4L2_SUBDEV_FORMAT_ACTIVE, &f->fmt.pix,
&source);
if (ret)
return ret;
vin->source.width = source.width;
vin->source.height = source.height;
vin->format = f->fmt.pix;
return 0;
}
static int rvin_g_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_format *f)
{
struct rvin_dev *vin = video_drvdata(file);
f->fmt.pix = vin->format;
return 0;
}
static int rvin_enum_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_fmtdesc *f)
{
if (f->index >= ARRAY_SIZE(rvin_formats))
return -EINVAL;
f->pixelformat = rvin_formats[f->index].fourcc;
return 0;
}
static int rvin_g_selection(struct file *file, void *fh,
struct v4l2_selection *s)
{
struct rvin_dev *vin = video_drvdata(file);
if (s->type != V4L2_BUF_TYPE_VIDEO_CAPTURE)
return -EINVAL;
switch (s->target) {
case V4L2_SEL_TGT_CROP_BOUNDS:
case V4L2_SEL_TGT_CROP_DEFAULT:
s->r.left = s->r.top = 0;
s->r.width = vin->source.width;
s->r.height = vin->source.height;
break;
case V4L2_SEL_TGT_CROP:
s->r = vin->crop;
break;
case V4L2_SEL_TGT_COMPOSE_BOUNDS:
case V4L2_SEL_TGT_COMPOSE_DEFAULT:
s->r.left = s->r.top = 0;
s->r.width = vin->format.width;
s->r.height = vin->format.height;
break;
case V4L2_SEL_TGT_COMPOSE:
s->r = vin->compose;
break;
default:
return -EINVAL;
}
return 0;
}
static int rvin_s_selection(struct file *file, void *fh,
struct v4l2_selection *s)
{
struct rvin_dev *vin = video_drvdata(file);
const struct rvin_video_format *fmt;
struct v4l2_rect r = s->r;
struct v4l2_rect max_rect;
struct v4l2_rect min_rect = {
.width = 6,
.height = 2,
};
if (s->type != V4L2_BUF_TYPE_VIDEO_CAPTURE)
return -EINVAL;
v4l2_rect_set_min_size(&r, &min_rect);
switch (s->target) {
case V4L2_SEL_TGT_CROP:
max_rect.top = max_rect.left = 0;
max_rect.width = vin->source.width;
max_rect.height = vin->source.height;
v4l2_rect_map_inside(&r, &max_rect);
v4l_bound_align_image(&r.width, 2, vin->source.width, 1,
&r.height, 4, vin->source.height, 2, 0);
r.top = clamp_t(s32, r.top, 0, vin->source.height - r.height);
r.left = clamp_t(s32, r.left, 0, vin->source.width - r.width);
vin->crop = s->r = r;
vin_dbg(vin, "Cropped %dx%d@%d:%d of %dx%d\n",
r.width, r.height, r.left, r.top,
vin->source.width, vin->source.height);
break;
case V4L2_SEL_TGT_COMPOSE:
max_rect.top = max_rect.left = 0;
max_rect.width = vin->format.width;
max_rect.height = vin->format.height;
v4l2_rect_map_inside(&r, &max_rect);
while ((r.top * vin->format.bytesperline) & HW_BUFFER_MASK)
r.top--;
fmt = rvin_format_from_pixel(vin->format.pixelformat);
while ((r.left * fmt->bpp) & HW_BUFFER_MASK)
r.left--;
vin->compose = s->r = r;
vin_dbg(vin, "Compose %dx%d@%d:%d in %dx%d\n",
r.width, r.height, r.left, r.top,
vin->format.width, vin->format.height);
break;
default:
return -EINVAL;
}
rvin_crop_scale_comp(vin);
return 0;
}
static int rvin_cropcap(struct file *file, void *priv,
struct v4l2_cropcap *crop)
{
struct rvin_dev *vin = video_drvdata(file);
struct v4l2_subdev *sd = vin_to_source(vin);
if (crop->type != V4L2_BUF_TYPE_VIDEO_CAPTURE)
return -EINVAL;
return v4l2_subdev_call(sd, video, cropcap, crop);
}
static int rvin_enum_input(struct file *file, void *priv,
struct v4l2_input *i)
{
struct rvin_dev *vin = video_drvdata(file);
struct v4l2_subdev *sd = vin_to_source(vin);
int ret;
if (i->index != 0)
return -EINVAL;
ret = v4l2_subdev_call(sd, video, g_input_status, &i->status);
if (ret < 0 && ret != -ENOIOCTLCMD && ret != -ENODEV)
return ret;
i->type = V4L2_INPUT_TYPE_CAMERA;
i->std = vin->vdev.tvnorms;
if (v4l2_subdev_has_op(sd, pad, dv_timings_cap))
i->capabilities = V4L2_IN_CAP_DV_TIMINGS;
strlcpy(i->name, "Camera", sizeof(i->name));
return 0;
}
static int rvin_g_input(struct file *file, void *priv, unsigned int *i)
{
*i = 0;
return 0;
}
static int rvin_s_input(struct file *file, void *priv, unsigned int i)
{
if (i > 0)
return -EINVAL;
return 0;
}
static int rvin_querystd(struct file *file, void *priv, v4l2_std_id *a)
{
struct rvin_dev *vin = video_drvdata(file);
struct v4l2_subdev *sd = vin_to_source(vin);
return v4l2_subdev_call(sd, video, querystd, a);
}
static int rvin_s_std(struct file *file, void *priv, v4l2_std_id a)
{
struct rvin_dev *vin = video_drvdata(file);
struct v4l2_subdev *sd = vin_to_source(vin);
struct v4l2_subdev_format fmt = {
.which = V4L2_SUBDEV_FORMAT_ACTIVE,
};
struct v4l2_mbus_framefmt *mf = &fmt.format;
int ret = v4l2_subdev_call(sd, video, s_std, a);
if (ret < 0)
return ret;
ret = v4l2_subdev_call(sd, pad, get_fmt, NULL, &fmt);
if (ret) {
vin_err(vin, "Failed to get initial format\n");
return ret;
}
vin->format.width = mf->width;
vin->format.height = mf->height;
vin->crop.top = vin->crop.left = 0;
vin->crop.width = mf->width;
vin->crop.height = mf->height;
vin->compose.top = vin->compose.left = 0;
vin->compose.width = mf->width;
vin->compose.height = mf->height;
return 0;
}
static int rvin_g_std(struct file *file, void *priv, v4l2_std_id *a)
{
struct rvin_dev *vin = video_drvdata(file);
struct v4l2_subdev *sd = vin_to_source(vin);
return v4l2_subdev_call(sd, video, g_std, a);
}
static int rvin_subscribe_event(struct v4l2_fh *fh,
const struct v4l2_event_subscription *sub)
{
switch (sub->type) {
case V4L2_EVENT_SOURCE_CHANGE:
return v4l2_event_subscribe(fh, sub, 4, NULL);
}
return v4l2_ctrl_subscribe_event(fh, sub);
}
static int rvin_enum_dv_timings(struct file *file, void *priv_fh,
struct v4l2_enum_dv_timings *timings)
{
struct rvin_dev *vin = video_drvdata(file);
struct v4l2_subdev *sd = vin_to_source(vin);
int pad, ret;
pad = timings->pad;
timings->pad = vin->src_pad_idx;
ret = v4l2_subdev_call(sd, pad, enum_dv_timings, timings);
timings->pad = pad;
return ret;
}
static int rvin_s_dv_timings(struct file *file, void *priv_fh,
struct v4l2_dv_timings *timings)
{
struct rvin_dev *vin = video_drvdata(file);
struct v4l2_subdev *sd = vin_to_source(vin);
int err;
err = v4l2_subdev_call(sd,
video, s_dv_timings, timings);
if (!err) {
vin->source.width = timings->bt.width;
vin->source.height = timings->bt.height;
vin->format.width = timings->bt.width;
vin->format.height = timings->bt.height;
}
return err;
}
static int rvin_g_dv_timings(struct file *file, void *priv_fh,
struct v4l2_dv_timings *timings)
{
struct rvin_dev *vin = video_drvdata(file);
struct v4l2_subdev *sd = vin_to_source(vin);
return v4l2_subdev_call(sd,
video, g_dv_timings, timings);
}
static int rvin_query_dv_timings(struct file *file, void *priv_fh,
struct v4l2_dv_timings *timings)
{
struct rvin_dev *vin = video_drvdata(file);
struct v4l2_subdev *sd = vin_to_source(vin);
return v4l2_subdev_call(sd,
video, query_dv_timings, timings);
}
static int rvin_dv_timings_cap(struct file *file, void *priv_fh,
struct v4l2_dv_timings_cap *cap)
{
struct rvin_dev *vin = video_drvdata(file);
struct v4l2_subdev *sd = vin_to_source(vin);
int pad, ret;
pad = cap->pad;
cap->pad = vin->src_pad_idx;
ret = v4l2_subdev_call(sd, pad, dv_timings_cap, cap);
cap->pad = pad;
return ret;
}
static int rvin_power_on(struct rvin_dev *vin)
{
int ret;
struct v4l2_subdev *sd = vin_to_source(vin);
pm_runtime_get_sync(vin->v4l2_dev.dev);
ret = v4l2_subdev_call(sd, core, s_power, 1);
if (ret < 0 && ret != -ENOIOCTLCMD && ret != -ENODEV)
return ret;
return 0;
}
static int rvin_power_off(struct rvin_dev *vin)
{
int ret;
struct v4l2_subdev *sd = vin_to_source(vin);
ret = v4l2_subdev_call(sd, core, s_power, 0);
pm_runtime_put(vin->v4l2_dev.dev);
if (ret < 0 && ret != -ENOIOCTLCMD && ret != -ENODEV)
return ret;
return 0;
}
static int rvin_initialize_device(struct file *file)
{
struct rvin_dev *vin = video_drvdata(file);
int ret;
struct v4l2_format f = {
.type = V4L2_BUF_TYPE_VIDEO_CAPTURE,
.fmt.pix = {
.width = vin->format.width,
.height = vin->format.height,
.field = vin->format.field,
.colorspace = vin->format.colorspace,
.pixelformat = vin->format.pixelformat,
},
};
ret = rvin_power_on(vin);
if (ret < 0)
return ret;
pm_runtime_enable(&vin->vdev.dev);
ret = pm_runtime_resume(&vin->vdev.dev);
if (ret < 0 && ret != -ENOSYS)
goto eresume;
ret = rvin_s_fmt_vid_cap(file, NULL, &f);
if (ret < 0)
goto esfmt;
v4l2_ctrl_handler_setup(&vin->ctrl_handler);
return 0;
esfmt:
pm_runtime_disable(&vin->vdev.dev);
eresume:
rvin_power_off(vin);
return ret;
}
static int rvin_open(struct file *file)
{
struct rvin_dev *vin = video_drvdata(file);
int ret;
mutex_lock(&vin->lock);
file->private_data = vin;
ret = v4l2_fh_open(file);
if (ret)
goto unlock;
if (!v4l2_fh_is_singular_file(file))
goto unlock;
if (rvin_initialize_device(file)) {
v4l2_fh_release(file);
ret = -ENODEV;
}
unlock:
mutex_unlock(&vin->lock);
return ret;
}
static int rvin_release(struct file *file)
{
struct rvin_dev *vin = video_drvdata(file);
bool fh_singular;
int ret;
mutex_lock(&vin->lock);
fh_singular = v4l2_fh_is_singular_file(file);
ret = _vb2_fop_release(file, NULL);
if (fh_singular) {
pm_runtime_suspend(&vin->vdev.dev);
pm_runtime_disable(&vin->vdev.dev);
rvin_power_off(vin);
}
mutex_unlock(&vin->lock);
return ret;
}
void rvin_v4l2_remove(struct rvin_dev *vin)
{
v4l2_info(&vin->v4l2_dev, "Removing %s\n",
video_device_node_name(&vin->vdev));
v4l2_ctrl_handler_free(&vin->ctrl_handler);
video_unregister_device(&vin->vdev);
}
static void rvin_notify(struct v4l2_subdev *sd,
unsigned int notification, void *arg)
{
struct rvin_dev *vin =
container_of(sd->v4l2_dev, struct rvin_dev, v4l2_dev);
switch (notification) {
case V4L2_DEVICE_NOTIFY_EVENT:
v4l2_event_queue(&vin->vdev, arg);
break;
default:
break;
}
}
int rvin_v4l2_probe(struct rvin_dev *vin)
{
struct v4l2_subdev_format fmt = {
.which = V4L2_SUBDEV_FORMAT_ACTIVE,
};
struct v4l2_mbus_framefmt *mf = &fmt.format;
struct video_device *vdev = &vin->vdev;
struct v4l2_subdev *sd = vin_to_source(vin);
#if defined(CONFIG_MEDIA_CONTROLLER)
int pad_idx;
#endif
int ret;
v4l2_set_subdev_hostdata(sd, vin);
vin->v4l2_dev.notify = rvin_notify;
ret = v4l2_subdev_call(sd, video, g_tvnorms, &vin->vdev.tvnorms);
if (ret < 0 && ret != -ENOIOCTLCMD && ret != -ENODEV)
return ret;
if (vin->vdev.tvnorms == 0) {
v4l2_disable_ioctl(&vin->vdev, VIDIOC_G_STD);
v4l2_disable_ioctl(&vin->vdev, VIDIOC_S_STD);
v4l2_disable_ioctl(&vin->vdev, VIDIOC_QUERYSTD);
v4l2_disable_ioctl(&vin->vdev, VIDIOC_ENUMSTD);
}
ret = v4l2_ctrl_handler_init(&vin->ctrl_handler, 16);
if (ret < 0)
return ret;
ret = v4l2_ctrl_add_handler(&vin->ctrl_handler, sd->ctrl_handler, NULL);
if (ret < 0)
return ret;
vdev->fops = &rvin_fops;
vdev->v4l2_dev = &vin->v4l2_dev;
vdev->queue = &vin->queue;
strlcpy(vdev->name, KBUILD_MODNAME, sizeof(vdev->name));
vdev->release = video_device_release_empty;
vdev->ioctl_ops = &rvin_ioctl_ops;
vdev->lock = &vin->lock;
vdev->ctrl_handler = &vin->ctrl_handler;
vdev->device_caps = V4L2_CAP_VIDEO_CAPTURE | V4L2_CAP_STREAMING |
V4L2_CAP_READWRITE;
vin->src_pad_idx = 0;
#if defined(CONFIG_MEDIA_CONTROLLER)
for (pad_idx = 0; pad_idx < sd->entity.num_pads; pad_idx++)
if (sd->entity.pads[pad_idx].flags
== MEDIA_PAD_FL_SOURCE)
break;
if (pad_idx >= sd->entity.num_pads)
return -EINVAL;
vin->src_pad_idx = pad_idx;
#endif
fmt.pad = vin->src_pad_idx;
ret = v4l2_subdev_call(sd, pad, get_fmt, NULL, &fmt);
if (ret) {
vin_err(vin, "Failed to get initial format\n");
return ret;
}
vin->format.width = mf->width;
vin->format.height = mf->height;
vin->format.colorspace = mf->colorspace;
vin->format.field = mf->field;
vin->format.pixelformat = RVIN_DEFAULT_FORMAT;
vin->crop.top = vin->crop.left = 0;
vin->crop.width = mf->width;
vin->crop.height = mf->height;
vin->compose.top = vin->compose.left = 0;
vin->compose.width = mf->width;
vin->compose.height = mf->height;
ret = video_register_device(&vin->vdev, VFL_TYPE_GRABBER, -1);
if (ret) {
vin_err(vin, "Failed to register video device\n");
return ret;
}
video_set_drvdata(&vin->vdev, vin);
v4l2_info(&vin->v4l2_dev, "Device registered as %s\n",
video_device_node_name(&vin->vdev));
return ret;
}
