static int video_find_format(u32 code, u32 pixelformat,
const struct camss_format_info *formats,
unsigned int nformats)
{
int i;
for (i = 0; i < nformats; i++) {
if (formats[i].code == code &&
formats[i].pixelformat == pixelformat)
return i;
}
for (i = 0; i < nformats; i++)
if (formats[i].code == code)
return i;
WARN_ON(1);
return -EINVAL;
}
static int video_mbus_to_pix_mp(const struct v4l2_mbus_framefmt *mbus,
struct v4l2_pix_format_mplane *pix,
const struct camss_format_info *f,
unsigned int alignment)
{
unsigned int i;
u32 bytesperline;
memset(pix, 0, sizeof(*pix));
v4l2_fill_pix_format_mplane(pix, mbus);
pix->pixelformat = f->pixelformat;
pix->num_planes = f->planes;
for (i = 0; i < pix->num_planes; i++) {
bytesperline = pix->width / f->hsub[i].numerator *
f->hsub[i].denominator * f->bpp[i] / 8;
bytesperline = ALIGN(bytesperline, alignment);
pix->plane_fmt[i].bytesperline = bytesperline;
pix->plane_fmt[i].sizeimage = pix->height /
f->vsub[i].numerator * f->vsub[i].denominator *
bytesperline;
}
return 0;
}
static struct v4l2_subdev *video_remote_subdev(struct camss_video *video,
u32 *pad)
{
struct media_pad *remote;
remote = media_entity_remote_pad(&video->pad);
if (!remote || !is_media_entity_v4l2_subdev(remote->entity))
return NULL;
if (pad)
*pad = remote->index;
return media_entity_to_v4l2_subdev(remote->entity);
}
static int video_get_subdev_format(struct camss_video *video,
struct v4l2_format *format)
{
struct v4l2_subdev_format fmt;
struct v4l2_subdev *subdev;
u32 pad;
int ret;
subdev = video_remote_subdev(video, &pad);
if (subdev == NULL)
return -EPIPE;
fmt.pad = pad;
fmt.which = V4L2_SUBDEV_FORMAT_ACTIVE;
ret = v4l2_subdev_call(subdev, pad, get_fmt, NULL, &fmt);
if (ret)
return ret;
ret = video_find_format(fmt.format.code,
format->fmt.pix_mp.pixelformat,
video->formats, video->nformats);
if (ret < 0)
return ret;
format->type = video->type;
return video_mbus_to_pix_mp(&fmt.format, &format->fmt.pix_mp,
&video->formats[ret], video->bpl_alignment);
}
static int video_queue_setup(struct vb2_queue *q,
unsigned int *num_buffers, unsigned int *num_planes,
unsigned int sizes[], struct device *alloc_devs[])
{
struct camss_video *video = vb2_get_drv_priv(q);
const struct v4l2_pix_format_mplane *format =
&video->active_fmt.fmt.pix_mp;
unsigned int i;
if (*num_planes) {
if (*num_planes != format->num_planes)
return -EINVAL;
for (i = 0; i < *num_planes; i++)
if (sizes[i] < format->plane_fmt[i].sizeimage)
return -EINVAL;
return 0;
}
*num_planes = format->num_planes;
for (i = 0; i < *num_planes; i++)
sizes[i] = format->plane_fmt[i].sizeimage;
return 0;
}
static int video_buf_init(struct vb2_buffer *vb)
{
struct vb2_v4l2_buffer *vbuf = to_vb2_v4l2_buffer(vb);
struct camss_video *video = vb2_get_drv_priv(vb->vb2_queue);
struct camss_buffer *buffer = container_of(vbuf, struct camss_buffer,
vb);
const struct v4l2_pix_format_mplane *format =
&video->active_fmt.fmt.pix_mp;
struct sg_table *sgt;
unsigned int i;
for (i = 0; i < format->num_planes; i++) {
sgt = vb2_dma_sg_plane_desc(vb, i);
if (!sgt)
return -EFAULT;
buffer->addr[i] = sg_dma_address(sgt->sgl);
}
if (format->pixelformat == V4L2_PIX_FMT_NV12 ||
format->pixelformat == V4L2_PIX_FMT_NV21 ||
format->pixelformat == V4L2_PIX_FMT_NV16 ||
format->pixelformat == V4L2_PIX_FMT_NV61)
buffer->addr[1] = buffer->addr[0] +
format->plane_fmt[0].bytesperline *
format->height;
return 0;
}
static int video_buf_prepare(struct vb2_buffer *vb)
{
struct vb2_v4l2_buffer *vbuf = to_vb2_v4l2_buffer(vb);
struct camss_video *video = vb2_get_drv_priv(vb->vb2_queue);
const struct v4l2_pix_format_mplane *format =
&video->active_fmt.fmt.pix_mp;
unsigned int i;
for (i = 0; i < format->num_planes; i++) {
if (format->plane_fmt[i].sizeimage > vb2_plane_size(vb, i))
return -EINVAL;
vb2_set_plane_payload(vb, i, format->plane_fmt[i].sizeimage);
}
vbuf->field = V4L2_FIELD_NONE;
return 0;
}
static void video_buf_queue(struct vb2_buffer *vb)
{
struct vb2_v4l2_buffer *vbuf = to_vb2_v4l2_buffer(vb);
struct camss_video *video = vb2_get_drv_priv(vb->vb2_queue);
struct camss_buffer *buffer = container_of(vbuf, struct camss_buffer,
vb);
video->ops->queue_buffer(video, buffer);
}
static int video_check_format(struct camss_video *video)
{
struct v4l2_pix_format_mplane *pix = &video->active_fmt.fmt.pix_mp;
struct v4l2_format format;
struct v4l2_pix_format_mplane *sd_pix = &format.fmt.pix_mp;
int ret;
sd_pix->pixelformat = pix->pixelformat;
ret = video_get_subdev_format(video, &format);
if (ret < 0)
return ret;
if (pix->pixelformat != sd_pix->pixelformat ||
pix->height != sd_pix->height ||
pix->width != sd_pix->width ||
pix->num_planes != sd_pix->num_planes ||
pix->field != format.fmt.pix_mp.field)
return -EPIPE;
return 0;
}
static int video_start_streaming(struct vb2_queue *q, unsigned int count)
{
struct camss_video *video = vb2_get_drv_priv(q);
struct video_device *vdev = &video->vdev;
struct media_entity *entity;
struct media_pad *pad;
struct v4l2_subdev *subdev;
int ret;
ret = media_pipeline_start(&vdev->entity, &video->pipe);
if (ret < 0)
return ret;
ret = video_check_format(video);
if (ret < 0)
goto error;
entity = &vdev->entity;
while (1) {
pad = &entity->pads[0];
if (!(pad->flags & MEDIA_PAD_FL_SINK))
break;
pad = media_entity_remote_pad(pad);
if (!pad || !is_media_entity_v4l2_subdev(pad->entity))
break;
entity = pad->entity;
subdev = media_entity_to_v4l2_subdev(entity);
ret = v4l2_subdev_call(subdev, video, s_stream, 1);
if (ret < 0 && ret != -ENOIOCTLCMD)
goto error;
}
return 0;
error:
media_pipeline_stop(&vdev->entity);
video->ops->flush_buffers(video, VB2_BUF_STATE_QUEUED);
return ret;
}
static void video_stop_streaming(struct vb2_queue *q)
{
struct camss_video *video = vb2_get_drv_priv(q);
struct video_device *vdev = &video->vdev;
struct media_entity *entity;
struct media_pad *pad;
struct v4l2_subdev *subdev;
entity = &vdev->entity;
while (1) {
pad = &entity->pads[0];
if (!(pad->flags & MEDIA_PAD_FL_SINK))
break;
pad = media_entity_remote_pad(pad);
if (!pad || !is_media_entity_v4l2_subdev(pad->entity))
break;
entity = pad->entity;
subdev = media_entity_to_v4l2_subdev(entity);
v4l2_subdev_call(subdev, video, s_stream, 0);
}
media_pipeline_stop(&vdev->entity);
video->ops->flush_buffers(video, VB2_BUF_STATE_ERROR);
}
static int video_querycap(struct file *file, void *fh,
struct v4l2_capability *cap)
{
struct camss_video *video = video_drvdata(file);
strlcpy(cap->driver, "qcom-camss", sizeof(cap->driver));
strlcpy(cap->card, "Qualcomm Camera Subsystem", sizeof(cap->card));
snprintf(cap->bus_info, sizeof(cap->bus_info), "platform:%s",
dev_name(video->camss->dev));
return 0;
}
static int video_enum_fmt(struct file *file, void *fh, struct v4l2_fmtdesc *f)
{
struct camss_video *video = video_drvdata(file);
int i, j, k;
if (f->type != video->type)
return -EINVAL;
if (f->index >= video->nformats)
return -EINVAL;
k = -1;
for (i = 0; i < video->nformats; i++) {
for (j = 0; j < i; j++) {
if (video->formats[i].pixelformat ==
video->formats[j].pixelformat)
break;
}
if (j == i)
k++;
if (k == f->index)
break;
}
if (k < f->index)
return -EINVAL;
f->pixelformat = video->formats[i].pixelformat;
return 0;
}
static int video_g_fmt(struct file *file, void *fh, struct v4l2_format *f)
{
struct camss_video *video = video_drvdata(file);
*f = video->active_fmt;
return 0;
}
static int __video_try_fmt(struct camss_video *video, struct v4l2_format *f)
{
struct v4l2_pix_format_mplane *pix_mp;
const struct camss_format_info *fi;
struct v4l2_plane_pix_format *p;
u32 bytesperline[3] = { 0 };
u32 sizeimage[3] = { 0 };
u32 width, height;
u32 bpl, lines;
int i, j;
pix_mp = &f->fmt.pix_mp;
if (video->line_based)
for (i = 0; i < pix_mp->num_planes && i < 3; i++) {
p = &pix_mp->plane_fmt[i];
bytesperline[i] = clamp_t(u32, p->bytesperline,
1, 65528);
sizeimage[i] = clamp_t(u32, p->sizeimage,
bytesperline[i],
bytesperline[i] * 4096);
}
for (j = 0; j < video->nformats; j++)
if (pix_mp->pixelformat == video->formats[j].pixelformat)
break;
if (j == video->nformats)
j = 0;
fi = &video->formats[j];
width = pix_mp->width;
height = pix_mp->height;
memset(pix_mp, 0, sizeof(*pix_mp));
pix_mp->pixelformat = fi->pixelformat;
pix_mp->width = clamp_t(u32, width, 1, 8191);
pix_mp->height = clamp_t(u32, height, 1, 8191);
pix_mp->num_planes = fi->planes;
for (i = 0; i < pix_mp->num_planes; i++) {
bpl = pix_mp->width / fi->hsub[i].numerator *
fi->hsub[i].denominator * fi->bpp[i] / 8;
bpl = ALIGN(bpl, video->bpl_alignment);
pix_mp->plane_fmt[i].bytesperline = bpl;
pix_mp->plane_fmt[i].sizeimage = pix_mp->height /
fi->vsub[i].numerator * fi->vsub[i].denominator * bpl;
}
pix_mp->field = V4L2_FIELD_NONE;
pix_mp->colorspace = V4L2_COLORSPACE_SRGB;
pix_mp->flags = 0;
pix_mp->ycbcr_enc = V4L2_MAP_YCBCR_ENC_DEFAULT(pix_mp->colorspace);
pix_mp->quantization = V4L2_MAP_QUANTIZATION_DEFAULT(true,
pix_mp->colorspace, pix_mp->ycbcr_enc);
pix_mp->xfer_func = V4L2_MAP_XFER_FUNC_DEFAULT(pix_mp->colorspace);
if (video->line_based)
for (i = 0; i < pix_mp->num_planes; i++) {
p = &pix_mp->plane_fmt[i];
p->bytesperline = clamp_t(u32, p->bytesperline,
1, 65528);
p->sizeimage = clamp_t(u32, p->sizeimage,
p->bytesperline,
p->bytesperline * 4096);
lines = p->sizeimage / p->bytesperline;
if (p->bytesperline < bytesperline[i])
p->bytesperline = ALIGN(bytesperline[i], 8);
if (p->sizeimage < p->bytesperline * lines)
p->sizeimage = p->bytesperline * lines;
if (p->sizeimage < sizeimage[i])
p->sizeimage = sizeimage[i];
}
return 0;
}
static int video_try_fmt(struct file *file, void *fh, struct v4l2_format *f)
{
struct camss_video *video = video_drvdata(file);
return __video_try_fmt(video, f);
}
static int video_s_fmt(struct file *file, void *fh, struct v4l2_format *f)
{
struct camss_video *video = video_drvdata(file);
int ret;
if (vb2_is_busy(&video->vb2_q))
return -EBUSY;
ret = __video_try_fmt(video, f);
if (ret < 0)
return ret;
video->active_fmt = *f;
return 0;
}
static int video_enum_input(struct file *file, void *fh,
struct v4l2_input *input)
{
if (input->index > 0)
return -EINVAL;
strlcpy(input->name, "camera", sizeof(input->name));
input->type = V4L2_INPUT_TYPE_CAMERA;
return 0;
}
static int video_g_input(struct file *file, void *fh, unsigned int *input)
{
*input = 0;
return 0;
}
static int video_s_input(struct file *file, void *fh, unsigned int input)
{
return input == 0 ? 0 : -EINVAL;
}
static int video_open(struct file *file)
{
struct video_device *vdev = video_devdata(file);
struct camss_video *video = video_drvdata(file);
struct v4l2_fh *vfh;
int ret;
mutex_lock(&video->lock);
vfh = kzalloc(sizeof(*vfh), GFP_KERNEL);
if (vfh == NULL) {
ret = -ENOMEM;
goto error_alloc;
}
v4l2_fh_init(vfh, vdev);
v4l2_fh_add(vfh);
file->private_data = vfh;
ret = v4l2_pipeline_pm_use(&vdev->entity, 1);
if (ret < 0) {
dev_err(video->camss->dev, "Failed to power up pipeline: %d\n",
ret);
goto error_pm_use;
}
mutex_unlock(&video->lock);
return 0;
error_pm_use:
v4l2_fh_release(file);
error_alloc:
mutex_unlock(&video->lock);
return ret;
}
static int video_release(struct file *file)
{
struct video_device *vdev = video_devdata(file);
vb2_fop_release(file);
v4l2_pipeline_pm_use(&vdev->entity, 0);
file->private_data = NULL;
return 0;
}
static void msm_video_release(struct video_device *vdev)
{
struct camss_video *video = video_get_drvdata(vdev);
media_entity_cleanup(&vdev->entity);
mutex_destroy(&video->q_lock);
mutex_destroy(&video->lock);
if (atomic_dec_and_test(&video->camss->ref_count))
camss_delete(video->camss);
}
static int msm_video_init_format(struct camss_video *video)
{
int ret;
struct v4l2_format format = {
.type = V4L2_BUF_TYPE_VIDEO_CAPTURE_MPLANE,
.fmt.pix_mp = {
.width = 1920,
.height = 1080,
.pixelformat = video->formats[0].pixelformat,
},
};
ret = __video_try_fmt(video, &format);
if (ret < 0)
return ret;
video->active_fmt = format;
return 0;
}
int msm_video_register(struct camss_video *video, struct v4l2_device *v4l2_dev,
const char *name, int is_pix)
{
struct media_pad *pad = &video->pad;
struct video_device *vdev;
struct vb2_queue *q;
int ret;
vdev = &video->vdev;
mutex_init(&video->q_lock);
q = &video->vb2_q;
q->drv_priv = video;
q->mem_ops = &vb2_dma_sg_memops;
q->ops = &msm_video_vb2_q_ops;
q->type = V4L2_BUF_TYPE_VIDEO_CAPTURE_MPLANE;
q->io_modes = VB2_DMABUF | VB2_MMAP | VB2_READ;
q->timestamp_flags = V4L2_BUF_FLAG_TIMESTAMP_MONOTONIC;
q->buf_struct_size = sizeof(struct camss_buffer);
q->dev = video->camss->dev;
q->lock = &video->q_lock;
ret = vb2_queue_init(q);
if (ret < 0) {
dev_err(v4l2_dev->dev, "Failed to init vb2 queue: %d\n", ret);
goto error_vb2_init;
}
pad->flags = MEDIA_PAD_FL_SINK;
ret = media_entity_pads_init(&vdev->entity, 1, pad);
if (ret < 0) {
dev_err(v4l2_dev->dev, "Failed to init video entity: %d\n",
ret);
goto error_media_init;
}
mutex_init(&video->lock);
video->formats = formats_rdi;
video->nformats = ARRAY_SIZE(formats_rdi);
if (is_pix) {
video->formats = formats_pix;
video->nformats = ARRAY_SIZE(formats_pix);
}
ret = msm_video_init_format(video);
if (ret < 0) {
dev_err(v4l2_dev->dev, "Failed to init format: %d\n", ret);
goto error_video_register;
}
vdev->fops = &msm_vid_fops;
vdev->device_caps = V4L2_CAP_VIDEO_CAPTURE_MPLANE | V4L2_CAP_STREAMING |
V4L2_CAP_READWRITE;
vdev->ioctl_ops = &msm_vid_ioctl_ops;
vdev->release = msm_video_release;
vdev->v4l2_dev = v4l2_dev;
vdev->vfl_dir = VFL_DIR_RX;
vdev->queue = &video->vb2_q;
vdev->lock = &video->lock;
strlcpy(vdev->name, name, sizeof(vdev->name));
ret = video_register_device(vdev, VFL_TYPE_GRABBER, -1);
if (ret < 0) {
dev_err(v4l2_dev->dev, "Failed to register video device: %d\n",
ret);
goto error_video_register;
}
video_set_drvdata(vdev, video);
atomic_inc(&video->camss->ref_count);
return 0;
error_video_register:
media_entity_cleanup(&vdev->entity);
mutex_destroy(&video->lock);
error_media_init:
vb2_queue_release(&video->vb2_q);
error_vb2_init:
mutex_destroy(&video->q_lock);
return ret;
}
void msm_video_stop_streaming(struct camss_video *video)
{
if (vb2_is_streaming(&video->vb2_q))
vb2_queue_release(&video->vb2_q);
}
void msm_video_unregister(struct camss_video *video)
{
atomic_inc(&video->camss->ref_count);
video_unregister_device(&video->vdev);
atomic_dec(&video->camss->ref_count);
}
