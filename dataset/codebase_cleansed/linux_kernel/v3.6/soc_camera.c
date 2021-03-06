static int soc_camera_power_on(struct soc_camera_device *icd,
struct soc_camera_link *icl)
{
struct v4l2_subdev *sd = soc_camera_to_subdev(icd);
int ret = regulator_bulk_enable(icl->num_regulators,
icl->regulators);
if (ret < 0) {
dev_err(icd->pdev, "Cannot enable regulators\n");
return ret;
}
if (icl->power) {
ret = icl->power(icd->control, 1);
if (ret < 0) {
dev_err(icd->pdev,
"Platform failed to power-on the camera.\n");
goto elinkpwr;
}
}
ret = v4l2_subdev_call(sd, core, s_power, 1);
if (ret < 0 && ret != -ENOIOCTLCMD && ret != -ENODEV)
goto esdpwr;
return 0;
esdpwr:
if (icl->power)
icl->power(icd->control, 0);
elinkpwr:
regulator_bulk_disable(icl->num_regulators,
icl->regulators);
return ret;
}
static int soc_camera_power_off(struct soc_camera_device *icd,
struct soc_camera_link *icl)
{
struct v4l2_subdev *sd = soc_camera_to_subdev(icd);
int ret = v4l2_subdev_call(sd, core, s_power, 0);
if (ret < 0 && ret != -ENOIOCTLCMD && ret != -ENODEV)
return ret;
if (icl->power) {
ret = icl->power(icd->control, 0);
if (ret < 0) {
dev_err(icd->pdev,
"Platform failed to power-off the camera.\n");
return ret;
}
}
ret = regulator_bulk_disable(icl->num_regulators,
icl->regulators);
if (ret < 0)
dev_err(icd->pdev, "Cannot disable regulators\n");
return ret;
}
const struct soc_camera_format_xlate *soc_camera_xlate_by_fourcc(
struct soc_camera_device *icd, unsigned int fourcc)
{
unsigned int i;
for (i = 0; i < icd->num_user_formats; i++)
if (icd->user_formats[i].host_fmt->fourcc == fourcc)
return icd->user_formats + i;
return NULL;
}
unsigned long soc_camera_apply_board_flags(struct soc_camera_link *icl,
const struct v4l2_mbus_config *cfg)
{
unsigned long f, flags = cfg->flags;
if (icl->flags & SOCAM_SENSOR_INVERT_HSYNC) {
f = flags & (V4L2_MBUS_HSYNC_ACTIVE_HIGH | V4L2_MBUS_HSYNC_ACTIVE_LOW);
if (f == V4L2_MBUS_HSYNC_ACTIVE_HIGH || f == V4L2_MBUS_HSYNC_ACTIVE_LOW)
flags ^= V4L2_MBUS_HSYNC_ACTIVE_HIGH | V4L2_MBUS_HSYNC_ACTIVE_LOW;
}
if (icl->flags & SOCAM_SENSOR_INVERT_VSYNC) {
f = flags & (V4L2_MBUS_VSYNC_ACTIVE_HIGH | V4L2_MBUS_VSYNC_ACTIVE_LOW);
if (f == V4L2_MBUS_VSYNC_ACTIVE_HIGH || f == V4L2_MBUS_VSYNC_ACTIVE_LOW)
flags ^= V4L2_MBUS_VSYNC_ACTIVE_HIGH | V4L2_MBUS_VSYNC_ACTIVE_LOW;
}
if (icl->flags & SOCAM_SENSOR_INVERT_PCLK) {
f = flags & (V4L2_MBUS_PCLK_SAMPLE_RISING | V4L2_MBUS_PCLK_SAMPLE_FALLING);
if (f == V4L2_MBUS_PCLK_SAMPLE_RISING || f == V4L2_MBUS_PCLK_SAMPLE_FALLING)
flags ^= V4L2_MBUS_PCLK_SAMPLE_RISING | V4L2_MBUS_PCLK_SAMPLE_FALLING;
}
return flags;
}
static int soc_camera_try_fmt(struct soc_camera_device *icd,
struct v4l2_format *f)
{
struct soc_camera_host *ici = to_soc_camera_host(icd->parent);
const struct soc_camera_format_xlate *xlate;
struct v4l2_pix_format *pix = &f->fmt.pix;
int ret;
dev_dbg(icd->pdev, "TRY_FMT(%c%c%c%c, %ux%u)\n",
pixfmtstr(pix->pixelformat), pix->width, pix->height);
if (pix->pixelformat != V4L2_PIX_FMT_JPEG &&
!(ici->capabilities & SOCAM_HOST_CAP_STRIDE)) {
pix->bytesperline = 0;
pix->sizeimage = 0;
}
ret = ici->ops->try_fmt(icd, f);
if (ret < 0)
return ret;
xlate = soc_camera_xlate_by_fourcc(icd, pix->pixelformat);
if (!xlate)
return -EINVAL;
ret = soc_mbus_bytes_per_line(pix->width, xlate->host_fmt);
if (ret < 0)
return ret;
pix->bytesperline = max_t(u32, pix->bytesperline, ret);
ret = soc_mbus_image_size(xlate->host_fmt, pix->bytesperline,
pix->height);
if (ret < 0)
return ret;
pix->sizeimage = max_t(u32, pix->sizeimage, ret);
return 0;
}
static int soc_camera_try_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_format *f)
{
struct soc_camera_device *icd = file->private_data;
WARN_ON(priv != file->private_data);
if (f->type != V4L2_BUF_TYPE_VIDEO_CAPTURE)
return -EINVAL;
return soc_camera_try_fmt(icd, f);
}
static int soc_camera_enum_input(struct file *file, void *priv,
struct v4l2_input *inp)
{
if (inp->index != 0)
return -EINVAL;
inp->type = V4L2_INPUT_TYPE_CAMERA;
inp->std = V4L2_STD_UNKNOWN;
strcpy(inp->name, "Camera");
return 0;
}
static int soc_camera_g_input(struct file *file, void *priv, unsigned int *i)
{
*i = 0;
return 0;
}
static int soc_camera_s_input(struct file *file, void *priv, unsigned int i)
{
if (i > 0)
return -EINVAL;
return 0;
}
static int soc_camera_s_std(struct file *file, void *priv, v4l2_std_id *a)
{
struct soc_camera_device *icd = file->private_data;
struct v4l2_subdev *sd = soc_camera_to_subdev(icd);
return v4l2_subdev_call(sd, core, s_std, *a);
}
static int soc_camera_g_std(struct file *file, void *priv, v4l2_std_id *a)
{
struct soc_camera_device *icd = file->private_data;
struct v4l2_subdev *sd = soc_camera_to_subdev(icd);
return v4l2_subdev_call(sd, core, g_std, a);
}
static int soc_camera_enum_framesizes(struct file *file, void *fh,
struct v4l2_frmsizeenum *fsize)
{
struct soc_camera_device *icd = file->private_data;
struct soc_camera_host *ici = to_soc_camera_host(icd->parent);
return ici->ops->enum_framesizes(icd, fsize);
}
static int soc_camera_reqbufs(struct file *file, void *priv,
struct v4l2_requestbuffers *p)
{
int ret;
struct soc_camera_device *icd = file->private_data;
struct soc_camera_host *ici = to_soc_camera_host(icd->parent);
WARN_ON(priv != file->private_data);
if (icd->streamer && icd->streamer != file)
return -EBUSY;
if (ici->ops->init_videobuf) {
ret = videobuf_reqbufs(&icd->vb_vidq, p);
if (ret < 0)
return ret;
ret = ici->ops->reqbufs(icd, p);
} else {
ret = vb2_reqbufs(&icd->vb2_vidq, p);
}
if (!ret && !icd->streamer)
icd->streamer = file;
return ret;
}
static int soc_camera_querybuf(struct file *file, void *priv,
struct v4l2_buffer *p)
{
struct soc_camera_device *icd = file->private_data;
struct soc_camera_host *ici = to_soc_camera_host(icd->parent);
WARN_ON(priv != file->private_data);
if (ici->ops->init_videobuf)
return videobuf_querybuf(&icd->vb_vidq, p);
else
return vb2_querybuf(&icd->vb2_vidq, p);
}
static int soc_camera_qbuf(struct file *file, void *priv,
struct v4l2_buffer *p)
{
struct soc_camera_device *icd = file->private_data;
struct soc_camera_host *ici = to_soc_camera_host(icd->parent);
WARN_ON(priv != file->private_data);
if (icd->streamer != file)
return -EBUSY;
if (ici->ops->init_videobuf)
return videobuf_qbuf(&icd->vb_vidq, p);
else
return vb2_qbuf(&icd->vb2_vidq, p);
}
static int soc_camera_dqbuf(struct file *file, void *priv,
struct v4l2_buffer *p)
{
struct soc_camera_device *icd = file->private_data;
struct soc_camera_host *ici = to_soc_camera_host(icd->parent);
WARN_ON(priv != file->private_data);
if (icd->streamer != file)
return -EBUSY;
if (ici->ops->init_videobuf)
return videobuf_dqbuf(&icd->vb_vidq, p, file->f_flags & O_NONBLOCK);
else
return vb2_dqbuf(&icd->vb2_vidq, p, file->f_flags & O_NONBLOCK);
}
static int soc_camera_create_bufs(struct file *file, void *priv,
struct v4l2_create_buffers *create)
{
struct soc_camera_device *icd = file->private_data;
struct soc_camera_host *ici = to_soc_camera_host(icd->parent);
if (ici->ops->init_videobuf)
return -EINVAL;
else
return vb2_create_bufs(&icd->vb2_vidq, create);
}
static int soc_camera_prepare_buf(struct file *file, void *priv,
struct v4l2_buffer *b)
{
struct soc_camera_device *icd = file->private_data;
struct soc_camera_host *ici = to_soc_camera_host(icd->parent);
if (ici->ops->init_videobuf)
return -EINVAL;
else
return vb2_prepare_buf(&icd->vb2_vidq, b);
}
static int soc_camera_init_user_formats(struct soc_camera_device *icd)
{
struct v4l2_subdev *sd = soc_camera_to_subdev(icd);
struct soc_camera_host *ici = to_soc_camera_host(icd->parent);
unsigned int i, fmts = 0, raw_fmts = 0;
int ret;
enum v4l2_mbus_pixelcode code;
while (!v4l2_subdev_call(sd, video, enum_mbus_fmt, raw_fmts, &code))
raw_fmts++;
if (!ici->ops->get_formats)
fmts = raw_fmts;
else
for (i = 0; i < raw_fmts; i++) {
ret = ici->ops->get_formats(icd, i, NULL);
if (ret < 0)
return ret;
fmts += ret;
}
if (!fmts)
return -ENXIO;
icd->user_formats =
vmalloc(fmts * sizeof(struct soc_camera_format_xlate));
if (!icd->user_formats)
return -ENOMEM;
dev_dbg(icd->pdev, "Found %d supported formats.\n", fmts);
fmts = 0;
for (i = 0; i < raw_fmts; i++)
if (!ici->ops->get_formats) {
v4l2_subdev_call(sd, video, enum_mbus_fmt, i, &code);
icd->user_formats[fmts].host_fmt =
soc_mbus_get_fmtdesc(code);
if (icd->user_formats[fmts].host_fmt)
icd->user_formats[fmts++].code = code;
} else {
ret = ici->ops->get_formats(icd, i,
&icd->user_formats[fmts]);
if (ret < 0)
goto egfmt;
fmts += ret;
}
icd->num_user_formats = fmts;
icd->current_fmt = &icd->user_formats[0];
return 0;
egfmt:
vfree(icd->user_formats);
return ret;
}
static void soc_camera_free_user_formats(struct soc_camera_device *icd)
{
struct soc_camera_host *ici = to_soc_camera_host(icd->parent);
if (ici->ops->put_formats)
ici->ops->put_formats(icd);
icd->current_fmt = NULL;
icd->num_user_formats = 0;
vfree(icd->user_formats);
icd->user_formats = NULL;
}
static int soc_camera_set_fmt(struct soc_camera_device *icd,
struct v4l2_format *f)
{
struct soc_camera_host *ici = to_soc_camera_host(icd->parent);
struct v4l2_pix_format *pix = &f->fmt.pix;
int ret;
dev_dbg(icd->pdev, "S_FMT(%c%c%c%c, %ux%u)\n",
pixfmtstr(pix->pixelformat), pix->width, pix->height);
ret = soc_camera_try_fmt(icd, f);
if (ret < 0)
return ret;
ret = ici->ops->set_fmt(icd, f);
if (ret < 0) {
return ret;
} else if (!icd->current_fmt ||
icd->current_fmt->host_fmt->fourcc != pix->pixelformat) {
dev_err(icd->pdev,
"Host driver hasn't set up current format correctly!\n");
return -EINVAL;
}
icd->user_width = pix->width;
icd->user_height = pix->height;
icd->bytesperline = pix->bytesperline;
icd->sizeimage = pix->sizeimage;
icd->colorspace = pix->colorspace;
icd->field = pix->field;
if (ici->ops->init_videobuf)
icd->vb_vidq.field = pix->field;
dev_dbg(icd->pdev, "set width: %d height: %d\n",
icd->user_width, icd->user_height);
return ici->ops->set_bus_param(icd);
}
static int soc_camera_open(struct file *file)
{
struct video_device *vdev = video_devdata(file);
struct soc_camera_device *icd = dev_get_drvdata(vdev->parent);
struct soc_camera_link *icl = to_soc_camera_link(icd);
struct soc_camera_host *ici;
int ret;
if (!to_soc_camera_control(icd))
return -ENODEV;
ici = to_soc_camera_host(icd->parent);
if (!try_module_get(ici->ops->owner)) {
dev_err(icd->pdev, "Couldn't lock capture bus driver.\n");
return -EINVAL;
}
icd->use_count++;
if (icd->use_count == 1) {
struct v4l2_format f = {
.type = V4L2_BUF_TYPE_VIDEO_CAPTURE,
.fmt.pix = {
.width = icd->user_width,
.height = icd->user_height,
.field = icd->field,
.colorspace = icd->colorspace,
.pixelformat =
icd->current_fmt->host_fmt->fourcc,
},
};
if (icl->reset)
icl->reset(icd->pdev);
mutex_lock(&ici->host_lock);
ret = ici->ops->add(icd);
mutex_unlock(&ici->host_lock);
if (ret < 0) {
dev_err(icd->pdev, "Couldn't activate the camera: %d\n", ret);
goto eiciadd;
}
ret = soc_camera_power_on(icd, icl);
if (ret < 0)
goto epower;
pm_runtime_enable(&icd->vdev->dev);
ret = pm_runtime_resume(&icd->vdev->dev);
if (ret < 0 && ret != -ENOSYS)
goto eresume;
ret = soc_camera_set_fmt(icd, &f);
if (ret < 0)
goto esfmt;
if (ici->ops->init_videobuf) {
ici->ops->init_videobuf(&icd->vb_vidq, icd);
} else {
ret = ici->ops->init_videobuf2(&icd->vb2_vidq, icd);
if (ret < 0)
goto einitvb;
}
v4l2_ctrl_handler_setup(&icd->ctrl_handler);
}
file->private_data = icd;
dev_dbg(icd->pdev, "camera device open\n");
return 0;
einitvb:
esfmt:
pm_runtime_disable(&icd->vdev->dev);
eresume:
soc_camera_power_off(icd, icl);
epower:
ici->ops->remove(icd);
eiciadd:
icd->use_count--;
module_put(ici->ops->owner);
return ret;
}
static int soc_camera_close(struct file *file)
{
struct soc_camera_device *icd = file->private_data;
struct soc_camera_host *ici = to_soc_camera_host(icd->parent);
icd->use_count--;
if (!icd->use_count) {
struct soc_camera_link *icl = to_soc_camera_link(icd);
pm_runtime_suspend(&icd->vdev->dev);
pm_runtime_disable(&icd->vdev->dev);
if (ici->ops->init_videobuf2)
vb2_queue_release(&icd->vb2_vidq);
ici->ops->remove(icd);
soc_camera_power_off(icd, icl);
}
if (icd->streamer == file)
icd->streamer = NULL;
module_put(ici->ops->owner);
dev_dbg(icd->pdev, "camera device close\n");
return 0;
}
static ssize_t soc_camera_read(struct file *file, char __user *buf,
size_t count, loff_t *ppos)
{
struct soc_camera_device *icd = file->private_data;
int err = -EINVAL;
dev_err(icd->pdev, "camera device read not implemented\n");
return err;
}
static int soc_camera_mmap(struct file *file, struct vm_area_struct *vma)
{
struct soc_camera_device *icd = file->private_data;
struct soc_camera_host *ici = to_soc_camera_host(icd->parent);
int err;
dev_dbg(icd->pdev, "mmap called, vma=0x%08lx\n", (unsigned long)vma);
if (icd->streamer != file)
return -EBUSY;
if (ici->ops->init_videobuf)
err = videobuf_mmap_mapper(&icd->vb_vidq, vma);
else
err = vb2_mmap(&icd->vb2_vidq, vma);
dev_dbg(icd->pdev, "vma start=0x%08lx, size=%ld, ret=%d\n",
(unsigned long)vma->vm_start,
(unsigned long)vma->vm_end - (unsigned long)vma->vm_start,
err);
return err;
}
static unsigned int soc_camera_poll(struct file *file, poll_table *pt)
{
struct soc_camera_device *icd = file->private_data;
struct soc_camera_host *ici = to_soc_camera_host(icd->parent);
if (icd->streamer != file)
return -EBUSY;
if (ici->ops->init_videobuf && list_empty(&icd->vb_vidq.stream)) {
dev_err(icd->pdev, "Trying to poll with no queued buffers!\n");
return POLLERR;
}
return ici->ops->poll(file, pt);
}
void soc_camera_lock(struct vb2_queue *vq)
{
struct soc_camera_device *icd = vb2_get_drv_priv(vq);
mutex_lock(&icd->video_lock);
}
void soc_camera_unlock(struct vb2_queue *vq)
{
struct soc_camera_device *icd = vb2_get_drv_priv(vq);
mutex_unlock(&icd->video_lock);
}
static int soc_camera_s_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_format *f)
{
struct soc_camera_device *icd = file->private_data;
int ret;
WARN_ON(priv != file->private_data);
if (f->type != V4L2_BUF_TYPE_VIDEO_CAPTURE) {
dev_warn(icd->pdev, "Wrong buf-type %d\n", f->type);
return -EINVAL;
}
if (icd->streamer && icd->streamer != file)
return -EBUSY;
if (is_streaming(to_soc_camera_host(icd->parent), icd)) {
dev_err(icd->pdev, "S_FMT denied: queue initialised\n");
return -EBUSY;
}
ret = soc_camera_set_fmt(icd, f);
if (!ret && !icd->streamer)
icd->streamer = file;
return ret;
}
static int soc_camera_enum_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_fmtdesc *f)
{
struct soc_camera_device *icd = file->private_data;
const struct soc_mbus_pixelfmt *format;
WARN_ON(priv != file->private_data);
if (f->index >= icd->num_user_formats)
return -EINVAL;
format = icd->user_formats[f->index].host_fmt;
if (format->name)
strlcpy(f->description, format->name, sizeof(f->description));
f->pixelformat = format->fourcc;
return 0;
}
static int soc_camera_g_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_format *f)
{
struct soc_camera_device *icd = file->private_data;
struct v4l2_pix_format *pix = &f->fmt.pix;
WARN_ON(priv != file->private_data);
if (f->type != V4L2_BUF_TYPE_VIDEO_CAPTURE)
return -EINVAL;
pix->width = icd->user_width;
pix->height = icd->user_height;
pix->bytesperline = icd->bytesperline;
pix->sizeimage = icd->sizeimage;
pix->field = icd->field;
pix->pixelformat = icd->current_fmt->host_fmt->fourcc;
pix->colorspace = icd->colorspace;
dev_dbg(icd->pdev, "current_fmt->fourcc: 0x%08x\n",
icd->current_fmt->host_fmt->fourcc);
return 0;
}
static int soc_camera_querycap(struct file *file, void *priv,
struct v4l2_capability *cap)
{
struct soc_camera_device *icd = file->private_data;
struct soc_camera_host *ici = to_soc_camera_host(icd->parent);
WARN_ON(priv != file->private_data);
strlcpy(cap->driver, ici->drv_name, sizeof(cap->driver));
return ici->ops->querycap(ici, cap);
}
static int soc_camera_streamon(struct file *file, void *priv,
enum v4l2_buf_type i)
{
struct soc_camera_device *icd = file->private_data;
struct soc_camera_host *ici = to_soc_camera_host(icd->parent);
struct v4l2_subdev *sd = soc_camera_to_subdev(icd);
int ret;
WARN_ON(priv != file->private_data);
if (i != V4L2_BUF_TYPE_VIDEO_CAPTURE)
return -EINVAL;
if (icd->streamer != file)
return -EBUSY;
if (ici->ops->init_videobuf)
ret = videobuf_streamon(&icd->vb_vidq);
else
ret = vb2_streamon(&icd->vb2_vidq, i);
if (!ret)
v4l2_subdev_call(sd, video, s_stream, 1);
return ret;
}
static int soc_camera_streamoff(struct file *file, void *priv,
enum v4l2_buf_type i)
{
struct soc_camera_device *icd = file->private_data;
struct v4l2_subdev *sd = soc_camera_to_subdev(icd);
struct soc_camera_host *ici = to_soc_camera_host(icd->parent);
WARN_ON(priv != file->private_data);
if (i != V4L2_BUF_TYPE_VIDEO_CAPTURE)
return -EINVAL;
if (icd->streamer != file)
return -EBUSY;
if (ici->ops->init_videobuf)
videobuf_streamoff(&icd->vb_vidq);
else
vb2_streamoff(&icd->vb2_vidq, i);
v4l2_subdev_call(sd, video, s_stream, 0);
return 0;
}
static int soc_camera_cropcap(struct file *file, void *fh,
struct v4l2_cropcap *a)
{
struct soc_camera_device *icd = file->private_data;
struct soc_camera_host *ici = to_soc_camera_host(icd->parent);
return ici->ops->cropcap(icd, a);
}
static int soc_camera_g_crop(struct file *file, void *fh,
struct v4l2_crop *a)
{
struct soc_camera_device *icd = file->private_data;
struct soc_camera_host *ici = to_soc_camera_host(icd->parent);
int ret;
ret = ici->ops->get_crop(icd, a);
return ret;
}
static int soc_camera_s_crop(struct file *file, void *fh,
struct v4l2_crop *a)
{
struct soc_camera_device *icd = file->private_data;
struct soc_camera_host *ici = to_soc_camera_host(icd->parent);
struct v4l2_rect *rect = &a->c;
struct v4l2_crop current_crop;
int ret;
if (a->type != V4L2_BUF_TYPE_VIDEO_CAPTURE)
return -EINVAL;
dev_dbg(icd->pdev, "S_CROP(%ux%u@%u:%u)\n",
rect->width, rect->height, rect->left, rect->top);
ret = ici->ops->get_crop(icd, &current_crop);
if (ret < 0) {
dev_err(icd->pdev,
"S_CROP denied: getting current crop failed\n");
} else if ((a->c.width == current_crop.c.width &&
a->c.height == current_crop.c.height) ||
!is_streaming(ici, icd)) {
ret = ici->ops->set_crop(icd, a);
} else if (ici->ops->set_livecrop) {
ret = ici->ops->set_livecrop(icd, a);
} else {
dev_err(icd->pdev,
"S_CROP denied: queue initialised and sizes differ\n");
ret = -EBUSY;
}
return ret;
}
static int soc_camera_g_parm(struct file *file, void *fh,
struct v4l2_streamparm *a)
{
struct soc_camera_device *icd = file->private_data;
struct soc_camera_host *ici = to_soc_camera_host(icd->parent);
if (ici->ops->get_parm)
return ici->ops->get_parm(icd, a);
return -ENOIOCTLCMD;
}
static int soc_camera_s_parm(struct file *file, void *fh,
struct v4l2_streamparm *a)
{
struct soc_camera_device *icd = file->private_data;
struct soc_camera_host *ici = to_soc_camera_host(icd->parent);
if (ici->ops->set_parm)
return ici->ops->set_parm(icd, a);
return -ENOIOCTLCMD;
}
static int soc_camera_g_chip_ident(struct file *file, void *fh,
struct v4l2_dbg_chip_ident *id)
{
struct soc_camera_device *icd = file->private_data;
struct v4l2_subdev *sd = soc_camera_to_subdev(icd);
return v4l2_subdev_call(sd, core, g_chip_ident, id);
}
static int soc_camera_g_register(struct file *file, void *fh,
struct v4l2_dbg_register *reg)
{
struct soc_camera_device *icd = file->private_data;
struct v4l2_subdev *sd = soc_camera_to_subdev(icd);
return v4l2_subdev_call(sd, core, g_register, reg);
}
static int soc_camera_s_register(struct file *file, void *fh,
struct v4l2_dbg_register *reg)
{
struct soc_camera_device *icd = file->private_data;
struct v4l2_subdev *sd = soc_camera_to_subdev(icd);
return v4l2_subdev_call(sd, core, s_register, reg);
}
static void scan_add_host(struct soc_camera_host *ici)
{
struct soc_camera_device *icd;
mutex_lock(&ici->host_lock);
list_for_each_entry(icd, &devices, list) {
if (icd->iface == ici->nr) {
int ret;
icd->parent = ici->v4l2_dev.dev;
ret = soc_camera_probe(icd);
}
}
mutex_unlock(&ici->host_lock);
}
static int soc_camera_init_i2c(struct soc_camera_device *icd,
struct soc_camera_link *icl)
{
struct i2c_client *client;
struct soc_camera_host *ici = to_soc_camera_host(icd->parent);
struct i2c_adapter *adap = i2c_get_adapter(icl->i2c_adapter_id);
struct v4l2_subdev *subdev;
if (!adap) {
dev_err(icd->pdev, "Cannot get I2C adapter #%d. No driver?\n",
icl->i2c_adapter_id);
goto ei2cga;
}
icl->board_info->platform_data = icl;
subdev = v4l2_i2c_new_subdev_board(&ici->v4l2_dev, adap,
icl->board_info, NULL);
if (!subdev)
goto ei2cnd;
client = v4l2_get_subdevdata(subdev);
icd->control = &client->dev;
return 0;
ei2cnd:
i2c_put_adapter(adap);
ei2cga:
return -ENODEV;
}
static void soc_camera_free_i2c(struct soc_camera_device *icd)
{
struct i2c_client *client =
to_i2c_client(to_soc_camera_control(icd));
struct i2c_adapter *adap = client->adapter;
icd->control = NULL;
v4l2_device_unregister_subdev(i2c_get_clientdata(client));
i2c_unregister_device(client);
i2c_put_adapter(adap);
}
static int soc_camera_probe(struct soc_camera_device *icd)
{
struct soc_camera_host *ici = to_soc_camera_host(icd->parent);
struct soc_camera_link *icl = to_soc_camera_link(icd);
struct device *control = NULL;
struct v4l2_subdev *sd;
struct v4l2_mbus_framefmt mf;
int ret;
dev_info(icd->pdev, "Probing %s\n", dev_name(icd->pdev));
ret = v4l2_ctrl_handler_init(&icd->ctrl_handler, 16);
if (ret < 0)
return ret;
ret = regulator_bulk_get(icd->pdev, icl->num_regulators,
icl->regulators);
if (ret < 0)
goto ereg;
if (icl->reset)
icl->reset(icd->pdev);
ret = ici->ops->add(icd);
if (ret < 0)
goto eadd;
ret = soc_camera_power_on(icd, icl);
if (ret < 0)
goto epower;
ret = video_dev_create(icd);
if (ret < 0)
goto evdc;
if (icl->board_info) {
ret = soc_camera_init_i2c(icd, icl);
if (ret < 0)
goto eadddev;
} else if (!icl->add_device || !icl->del_device) {
ret = -EINVAL;
goto eadddev;
} else {
if (icl->module_name)
ret = request_module(icl->module_name);
ret = icl->add_device(icd);
if (ret < 0)
goto eadddev;
control = to_soc_camera_control(icd);
if (!control || !control->driver || !dev_get_drvdata(control) ||
!try_module_get(control->driver->owner)) {
icl->del_device(icd);
ret = -ENODEV;
goto enodrv;
}
}
sd = soc_camera_to_subdev(icd);
sd->grp_id = soc_camera_grp_id(icd);
v4l2_set_subdev_hostdata(sd, icd);
if (v4l2_ctrl_add_handler(&icd->ctrl_handler, sd->ctrl_handler))
goto ectrl;
ret = soc_camera_init_user_formats(icd);
if (ret < 0)
goto eiufmt;
icd->field = V4L2_FIELD_ANY;
mutex_lock(&icd->video_lock);
ret = soc_camera_video_start(icd);
if (ret < 0)
goto evidstart;
ret = v4l2_subdev_call(sd, core, s_power, 1);
if (ret < 0 && ret != -ENOIOCTLCMD)
goto esdpwr;
if (!v4l2_subdev_call(sd, video, g_mbus_fmt, &mf)) {
icd->user_width = mf.width;
icd->user_height = mf.height;
icd->colorspace = mf.colorspace;
icd->field = mf.field;
}
ici->ops->remove(icd);
soc_camera_power_off(icd, icl);
mutex_unlock(&icd->video_lock);
return 0;
esdpwr:
video_unregister_device(icd->vdev);
evidstart:
mutex_unlock(&icd->video_lock);
soc_camera_free_user_formats(icd);
eiufmt:
ectrl:
if (icl->board_info) {
soc_camera_free_i2c(icd);
} else {
icl->del_device(icd);
module_put(control->driver->owner);
}
enodrv:
eadddev:
video_device_release(icd->vdev);
icd->vdev = NULL;
evdc:
soc_camera_power_off(icd, icl);
epower:
ici->ops->remove(icd);
eadd:
regulator_bulk_free(icl->num_regulators, icl->regulators);
ereg:
v4l2_ctrl_handler_free(&icd->ctrl_handler);
return ret;
}
static int soc_camera_remove(struct soc_camera_device *icd)
{
struct soc_camera_link *icl = to_soc_camera_link(icd);
struct video_device *vdev = icd->vdev;
BUG_ON(!icd->parent);
v4l2_ctrl_handler_free(&icd->ctrl_handler);
if (vdev) {
video_unregister_device(vdev);
icd->vdev = NULL;
}
if (icl->board_info) {
soc_camera_free_i2c(icd);
} else {
struct device_driver *drv = to_soc_camera_control(icd)->driver;
if (drv) {
icl->del_device(icd);
module_put(drv->owner);
}
}
soc_camera_free_user_formats(icd);
regulator_bulk_free(icl->num_regulators, icl->regulators);
return 0;
}
static int default_cropcap(struct soc_camera_device *icd,
struct v4l2_cropcap *a)
{
struct v4l2_subdev *sd = soc_camera_to_subdev(icd);
return v4l2_subdev_call(sd, video, cropcap, a);
}
static int default_g_crop(struct soc_camera_device *icd, struct v4l2_crop *a)
{
struct v4l2_subdev *sd = soc_camera_to_subdev(icd);
return v4l2_subdev_call(sd, video, g_crop, a);
}
static int default_s_crop(struct soc_camera_device *icd, struct v4l2_crop *a)
{
struct v4l2_subdev *sd = soc_camera_to_subdev(icd);
return v4l2_subdev_call(sd, video, s_crop, a);
}
static int default_g_parm(struct soc_camera_device *icd,
struct v4l2_streamparm *parm)
{
struct v4l2_subdev *sd = soc_camera_to_subdev(icd);
return v4l2_subdev_call(sd, video, g_parm, parm);
}
static int default_s_parm(struct soc_camera_device *icd,
struct v4l2_streamparm *parm)
{
struct v4l2_subdev *sd = soc_camera_to_subdev(icd);
return v4l2_subdev_call(sd, video, s_parm, parm);
}
static int default_enum_framesizes(struct soc_camera_device *icd,
struct v4l2_frmsizeenum *fsize)
{
int ret;
struct v4l2_subdev *sd = soc_camera_to_subdev(icd);
const struct soc_camera_format_xlate *xlate;
__u32 pixfmt = fsize->pixel_format;
struct v4l2_frmsizeenum fsize_mbus = *fsize;
xlate = soc_camera_xlate_by_fourcc(icd, pixfmt);
if (!xlate)
return -EINVAL;
fsize_mbus.pixel_format = xlate->code;
ret = v4l2_subdev_call(sd, video, enum_framesizes, &fsize_mbus);
if (ret < 0)
return ret;
*fsize = fsize_mbus;
fsize->pixel_format = pixfmt;
return 0;
}
int soc_camera_host_register(struct soc_camera_host *ici)
{
struct soc_camera_host *ix;
int ret;
if (!ici || !ici->ops ||
!ici->ops->try_fmt ||
!ici->ops->set_fmt ||
!ici->ops->set_bus_param ||
!ici->ops->querycap ||
((!ici->ops->init_videobuf ||
!ici->ops->reqbufs) &&
!ici->ops->init_videobuf2) ||
!ici->ops->add ||
!ici->ops->remove ||
!ici->ops->poll ||
!ici->v4l2_dev.dev)
return -EINVAL;
if (!ici->ops->set_crop)
ici->ops->set_crop = default_s_crop;
if (!ici->ops->get_crop)
ici->ops->get_crop = default_g_crop;
if (!ici->ops->cropcap)
ici->ops->cropcap = default_cropcap;
if (!ici->ops->set_parm)
ici->ops->set_parm = default_s_parm;
if (!ici->ops->get_parm)
ici->ops->get_parm = default_g_parm;
if (!ici->ops->enum_framesizes)
ici->ops->enum_framesizes = default_enum_framesizes;
mutex_lock(&list_lock);
list_for_each_entry(ix, &hosts, list) {
if (ix->nr == ici->nr) {
ret = -EBUSY;
goto edevreg;
}
}
ret = v4l2_device_register(ici->v4l2_dev.dev, &ici->v4l2_dev);
if (ret < 0)
goto edevreg;
list_add_tail(&ici->list, &hosts);
mutex_unlock(&list_lock);
mutex_init(&ici->host_lock);
scan_add_host(ici);
return 0;
edevreg:
mutex_unlock(&list_lock);
return ret;
}
void soc_camera_host_unregister(struct soc_camera_host *ici)
{
struct soc_camera_device *icd;
mutex_lock(&list_lock);
list_del(&ici->list);
list_for_each_entry(icd, &devices, list)
if (icd->iface == ici->nr && to_soc_camera_control(icd))
soc_camera_remove(icd);
mutex_unlock(&list_lock);
v4l2_device_unregister(&ici->v4l2_dev);
}
static int soc_camera_device_register(struct soc_camera_device *icd)
{
struct soc_camera_device *ix;
int num = -1, i;
for (i = 0; i < 256 && num < 0; i++) {
num = i;
list_for_each_entry(ix, &devices, list) {
if (ix->iface == icd->iface && ix->devnum == i) {
num = -1;
break;
}
}
}
if (num < 0)
return -ENOMEM;
icd->devnum = num;
icd->use_count = 0;
icd->host_priv = NULL;
mutex_init(&icd->video_lock);
list_add_tail(&icd->list, &devices);
return 0;
}
static int video_dev_create(struct soc_camera_device *icd)
{
struct soc_camera_host *ici = to_soc_camera_host(icd->parent);
struct video_device *vdev = video_device_alloc();
if (!vdev)
return -ENOMEM;
strlcpy(vdev->name, ici->drv_name, sizeof(vdev->name));
vdev->parent = icd->pdev;
vdev->current_norm = V4L2_STD_UNKNOWN;
vdev->fops = &soc_camera_fops;
vdev->ioctl_ops = &soc_camera_ioctl_ops;
vdev->release = video_device_release;
vdev->tvnorms = V4L2_STD_UNKNOWN;
vdev->ctrl_handler = &icd->ctrl_handler;
vdev->lock = &icd->video_lock;
set_bit(V4L2_FL_LOCK_ALL_FOPS, &vdev->flags);
icd->vdev = vdev;
return 0;
}
static int soc_camera_video_start(struct soc_camera_device *icd)
{
const struct device_type *type = icd->vdev->dev.type;
int ret;
if (!icd->parent)
return -ENODEV;
ret = video_register_device(icd->vdev, VFL_TYPE_GRABBER, -1);
if (ret < 0) {
dev_err(icd->pdev, "video_register_device failed: %d\n", ret);
return ret;
}
icd->vdev->dev.type = type;
return 0;
}
static int __devinit soc_camera_pdrv_probe(struct platform_device *pdev)
{
struct soc_camera_link *icl = pdev->dev.platform_data;
struct soc_camera_device *icd;
int ret;
if (!icl)
return -EINVAL;
icd = kzalloc(sizeof(*icd), GFP_KERNEL);
if (!icd)
return -ENOMEM;
icd->iface = icl->bus_id;
icd->link = icl;
icd->pdev = &pdev->dev;
platform_set_drvdata(pdev, icd);
ret = soc_camera_device_register(icd);
if (ret < 0)
goto escdevreg;
icd->user_width = DEFAULT_WIDTH;
icd->user_height = DEFAULT_HEIGHT;
return 0;
escdevreg:
kfree(icd);
return ret;
}
static int __devexit soc_camera_pdrv_remove(struct platform_device *pdev)
{
struct soc_camera_device *icd = platform_get_drvdata(pdev);
if (!icd)
return -EINVAL;
list_del(&icd->list);
kfree(icd);
return 0;
}
static int __init soc_camera_init(void)
{
return platform_driver_register(&soc_camera_pdrv);
}
static void __exit soc_camera_exit(void)
{
platform_driver_unregister(&soc_camera_pdrv);
}
