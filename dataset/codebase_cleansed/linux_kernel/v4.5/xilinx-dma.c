static struct v4l2_subdev *
xvip_dma_remote_subdev(struct media_pad *local, u32 *pad)
{
struct media_pad *remote;
remote = media_entity_remote_pad(local);
if (!remote || !is_media_entity_v4l2_subdev(remote->entity))
return NULL;
if (pad)
*pad = remote->index;
return media_entity_to_v4l2_subdev(remote->entity);
}
static int xvip_dma_verify_format(struct xvip_dma *dma)
{
struct v4l2_subdev_format fmt;
struct v4l2_subdev *subdev;
int ret;
subdev = xvip_dma_remote_subdev(&dma->pad, &fmt.pad);
if (subdev == NULL)
return -EPIPE;
fmt.which = V4L2_SUBDEV_FORMAT_ACTIVE;
ret = v4l2_subdev_call(subdev, pad, get_fmt, NULL, &fmt);
if (ret < 0)
return ret == -ENOIOCTLCMD ? -EINVAL : ret;
if (dma->fmtinfo->code != fmt.format.code ||
dma->format.height != fmt.format.height ||
dma->format.width != fmt.format.width ||
dma->format.colorspace != fmt.format.colorspace)
return -EINVAL;
return 0;
}
static int xvip_pipeline_start_stop(struct xvip_pipeline *pipe, bool start)
{
struct xvip_dma *dma = pipe->output;
struct media_entity *entity;
struct media_pad *pad;
struct v4l2_subdev *subdev;
int ret;
entity = &dma->video.entity;
while (1) {
pad = &entity->pads[0];
if (!(pad->flags & MEDIA_PAD_FL_SINK))
break;
pad = media_entity_remote_pad(pad);
if (!pad || !is_media_entity_v4l2_subdev(pad->entity))
break;
entity = pad->entity;
subdev = media_entity_to_v4l2_subdev(entity);
ret = v4l2_subdev_call(subdev, video, s_stream, start);
if (start && ret < 0 && ret != -ENOIOCTLCMD)
return ret;
}
return 0;
}
static int xvip_pipeline_set_stream(struct xvip_pipeline *pipe, bool on)
{
int ret = 0;
mutex_lock(&pipe->lock);
if (on) {
if (pipe->stream_count == pipe->num_dmas - 1) {
ret = xvip_pipeline_start_stop(pipe, true);
if (ret < 0)
goto done;
}
pipe->stream_count++;
} else {
if (--pipe->stream_count == 0)
xvip_pipeline_start_stop(pipe, false);
}
done:
mutex_unlock(&pipe->lock);
return ret;
}
static int xvip_pipeline_validate(struct xvip_pipeline *pipe,
struct xvip_dma *start)
{
struct media_entity_graph graph;
struct media_entity *entity = &start->video.entity;
struct media_device *mdev = entity->graph_obj.mdev;
unsigned int num_inputs = 0;
unsigned int num_outputs = 0;
int ret;
mutex_lock(&mdev->graph_mutex);
ret = media_entity_graph_walk_init(&graph, entity->graph_obj.mdev);
if (ret) {
mutex_unlock(&mdev->graph_mutex);
return ret;
}
media_entity_graph_walk_start(&graph, entity);
while ((entity = media_entity_graph_walk_next(&graph))) {
struct xvip_dma *dma;
if (entity->function != MEDIA_ENT_F_IO_V4L)
continue;
dma = to_xvip_dma(media_entity_to_video_device(entity));
if (dma->pad.flags & MEDIA_PAD_FL_SINK) {
pipe->output = dma;
num_outputs++;
} else {
num_inputs++;
}
}
mutex_unlock(&mdev->graph_mutex);
media_entity_graph_walk_cleanup(&graph);
if (num_outputs != 1 || num_inputs > 1)
return -EPIPE;
pipe->num_dmas = num_inputs + num_outputs;
return 0;
}
static void __xvip_pipeline_cleanup(struct xvip_pipeline *pipe)
{
pipe->num_dmas = 0;
pipe->output = NULL;
}
static void xvip_pipeline_cleanup(struct xvip_pipeline *pipe)
{
mutex_lock(&pipe->lock);
if (--pipe->use_count == 0)
__xvip_pipeline_cleanup(pipe);
mutex_unlock(&pipe->lock);
}
static int xvip_pipeline_prepare(struct xvip_pipeline *pipe,
struct xvip_dma *dma)
{
int ret;
mutex_lock(&pipe->lock);
if (pipe->use_count == 0) {
ret = xvip_pipeline_validate(pipe, dma);
if (ret < 0) {
__xvip_pipeline_cleanup(pipe);
goto done;
}
}
pipe->use_count++;
ret = 0;
done:
mutex_unlock(&pipe->lock);
return ret;
}
static void xvip_dma_complete(void *param)
{
struct xvip_dma_buffer *buf = param;
struct xvip_dma *dma = buf->dma;
spin_lock(&dma->queued_lock);
list_del(&buf->queue);
spin_unlock(&dma->queued_lock);
buf->buf.field = V4L2_FIELD_NONE;
buf->buf.sequence = dma->sequence++;
buf->buf.vb2_buf.timestamp = ktime_get_ns();
vb2_set_plane_payload(&buf->buf.vb2_buf, 0, dma->format.sizeimage);
vb2_buffer_done(&buf->buf.vb2_buf, VB2_BUF_STATE_DONE);
}
static int
xvip_dma_queue_setup(struct vb2_queue *vq,
unsigned int *nbuffers, unsigned int *nplanes,
unsigned int sizes[], void *alloc_ctxs[])
{
struct xvip_dma *dma = vb2_get_drv_priv(vq);
alloc_ctxs[0] = dma->alloc_ctx;
if (*nplanes)
return sizes[0] < dma->format.sizeimage ? -EINVAL : 0;
*nplanes = 1;
sizes[0] = dma->format.sizeimage;
return 0;
}
static int xvip_dma_buffer_prepare(struct vb2_buffer *vb)
{
struct vb2_v4l2_buffer *vbuf = to_vb2_v4l2_buffer(vb);
struct xvip_dma *dma = vb2_get_drv_priv(vb->vb2_queue);
struct xvip_dma_buffer *buf = to_xvip_dma_buffer(vbuf);
buf->dma = dma;
return 0;
}
static void xvip_dma_buffer_queue(struct vb2_buffer *vb)
{
struct vb2_v4l2_buffer *vbuf = to_vb2_v4l2_buffer(vb);
struct xvip_dma *dma = vb2_get_drv_priv(vb->vb2_queue);
struct xvip_dma_buffer *buf = to_xvip_dma_buffer(vbuf);
struct dma_async_tx_descriptor *desc;
dma_addr_t addr = vb2_dma_contig_plane_dma_addr(vb, 0);
u32 flags;
if (dma->queue.type == V4L2_BUF_TYPE_VIDEO_CAPTURE) {
flags = DMA_PREP_INTERRUPT | DMA_CTRL_ACK;
dma->xt.dir = DMA_DEV_TO_MEM;
dma->xt.src_sgl = false;
dma->xt.dst_sgl = true;
dma->xt.dst_start = addr;
} else {
flags = DMA_PREP_INTERRUPT | DMA_CTRL_ACK;
dma->xt.dir = DMA_MEM_TO_DEV;
dma->xt.src_sgl = true;
dma->xt.dst_sgl = false;
dma->xt.src_start = addr;
}
dma->xt.frame_size = 1;
dma->sgl[0].size = dma->format.width * dma->fmtinfo->bpp;
dma->sgl[0].icg = dma->format.bytesperline - dma->sgl[0].size;
dma->xt.numf = dma->format.height;
desc = dmaengine_prep_interleaved_dma(dma->dma, &dma->xt, flags);
if (!desc) {
dev_err(dma->xdev->dev, "Failed to prepare DMA transfer\n");
vb2_buffer_done(&buf->buf.vb2_buf, VB2_BUF_STATE_ERROR);
return;
}
desc->callback = xvip_dma_complete;
desc->callback_param = buf;
spin_lock_irq(&dma->queued_lock);
list_add_tail(&buf->queue, &dma->queued_bufs);
spin_unlock_irq(&dma->queued_lock);
dmaengine_submit(desc);
if (vb2_is_streaming(&dma->queue))
dma_async_issue_pending(dma->dma);
}
static int xvip_dma_start_streaming(struct vb2_queue *vq, unsigned int count)
{
struct xvip_dma *dma = vb2_get_drv_priv(vq);
struct xvip_dma_buffer *buf, *nbuf;
struct xvip_pipeline *pipe;
int ret;
dma->sequence = 0;
pipe = dma->video.entity.pipe
? to_xvip_pipeline(&dma->video.entity) : &dma->pipe;
ret = media_entity_pipeline_start(&dma->video.entity, &pipe->pipe);
if (ret < 0)
goto error;
ret = xvip_dma_verify_format(dma);
if (ret < 0)
goto error_stop;
ret = xvip_pipeline_prepare(pipe, dma);
if (ret < 0)
goto error_stop;
dma_async_issue_pending(dma->dma);
xvip_pipeline_set_stream(pipe, true);
return 0;
error_stop:
media_entity_pipeline_stop(&dma->video.entity);
error:
spin_lock_irq(&dma->queued_lock);
list_for_each_entry_safe(buf, nbuf, &dma->queued_bufs, queue) {
vb2_buffer_done(&buf->buf.vb2_buf, VB2_BUF_STATE_QUEUED);
list_del(&buf->queue);
}
spin_unlock_irq(&dma->queued_lock);
return ret;
}
static void xvip_dma_stop_streaming(struct vb2_queue *vq)
{
struct xvip_dma *dma = vb2_get_drv_priv(vq);
struct xvip_pipeline *pipe = to_xvip_pipeline(&dma->video.entity);
struct xvip_dma_buffer *buf, *nbuf;
xvip_pipeline_set_stream(pipe, false);
dmaengine_terminate_all(dma->dma);
xvip_pipeline_cleanup(pipe);
media_entity_pipeline_stop(&dma->video.entity);
spin_lock_irq(&dma->queued_lock);
list_for_each_entry_safe(buf, nbuf, &dma->queued_bufs, queue) {
vb2_buffer_done(&buf->buf.vb2_buf, VB2_BUF_STATE_ERROR);
list_del(&buf->queue);
}
spin_unlock_irq(&dma->queued_lock);
}
static int
xvip_dma_querycap(struct file *file, void *fh, struct v4l2_capability *cap)
{
struct v4l2_fh *vfh = file->private_data;
struct xvip_dma *dma = to_xvip_dma(vfh->vdev);
cap->capabilities = V4L2_CAP_DEVICE_CAPS | V4L2_CAP_STREAMING
| dma->xdev->v4l2_caps;
if (dma->queue.type == V4L2_BUF_TYPE_VIDEO_CAPTURE)
cap->device_caps = V4L2_CAP_VIDEO_CAPTURE | V4L2_CAP_STREAMING;
else
cap->device_caps = V4L2_CAP_VIDEO_OUTPUT | V4L2_CAP_STREAMING;
strlcpy(cap->driver, "xilinx-vipp", sizeof(cap->driver));
strlcpy(cap->card, dma->video.name, sizeof(cap->card));
snprintf(cap->bus_info, sizeof(cap->bus_info), "platform:%s:%u",
dma->xdev->dev->of_node->name, dma->port);
return 0;
}
static int
xvip_dma_enum_format(struct file *file, void *fh, struct v4l2_fmtdesc *f)
{
struct v4l2_fh *vfh = file->private_data;
struct xvip_dma *dma = to_xvip_dma(vfh->vdev);
if (f->index > 0)
return -EINVAL;
f->pixelformat = dma->format.pixelformat;
strlcpy(f->description, dma->fmtinfo->description,
sizeof(f->description));
return 0;
}
static int
xvip_dma_get_format(struct file *file, void *fh, struct v4l2_format *format)
{
struct v4l2_fh *vfh = file->private_data;
struct xvip_dma *dma = to_xvip_dma(vfh->vdev);
format->fmt.pix = dma->format;
return 0;
}
static void
__xvip_dma_try_format(struct xvip_dma *dma, struct v4l2_pix_format *pix,
const struct xvip_video_format **fmtinfo)
{
const struct xvip_video_format *info;
unsigned int min_width;
unsigned int max_width;
unsigned int min_bpl;
unsigned int max_bpl;
unsigned int width;
unsigned int align;
unsigned int bpl;
info = xvip_get_format_by_fourcc(pix->pixelformat);
if (IS_ERR(info))
info = xvip_get_format_by_fourcc(XVIP_DMA_DEF_FORMAT);
pix->pixelformat = info->fourcc;
pix->field = V4L2_FIELD_NONE;
align = lcm(dma->align, info->bpp);
min_width = roundup(XVIP_DMA_MIN_WIDTH, align);
max_width = rounddown(XVIP_DMA_MAX_WIDTH, align);
width = rounddown(pix->width * info->bpp, align);
pix->width = clamp(width, min_width, max_width) / info->bpp;
pix->height = clamp(pix->height, XVIP_DMA_MIN_HEIGHT,
XVIP_DMA_MAX_HEIGHT);
min_bpl = pix->width * info->bpp;
max_bpl = rounddown(XVIP_DMA_MAX_WIDTH, dma->align);
bpl = rounddown(pix->bytesperline, dma->align);
pix->bytesperline = clamp(bpl, min_bpl, max_bpl);
pix->sizeimage = pix->bytesperline * pix->height;
if (fmtinfo)
*fmtinfo = info;
}
static int
xvip_dma_try_format(struct file *file, void *fh, struct v4l2_format *format)
{
struct v4l2_fh *vfh = file->private_data;
struct xvip_dma *dma = to_xvip_dma(vfh->vdev);
__xvip_dma_try_format(dma, &format->fmt.pix, NULL);
return 0;
}
static int
xvip_dma_set_format(struct file *file, void *fh, struct v4l2_format *format)
{
struct v4l2_fh *vfh = file->private_data;
struct xvip_dma *dma = to_xvip_dma(vfh->vdev);
const struct xvip_video_format *info;
__xvip_dma_try_format(dma, &format->fmt.pix, &info);
if (vb2_is_busy(&dma->queue))
return -EBUSY;
dma->format = format->fmt.pix;
dma->fmtinfo = info;
return 0;
}
int xvip_dma_init(struct xvip_composite_device *xdev, struct xvip_dma *dma,
enum v4l2_buf_type type, unsigned int port)
{
char name[16];
int ret;
dma->xdev = xdev;
dma->port = port;
mutex_init(&dma->lock);
mutex_init(&dma->pipe.lock);
INIT_LIST_HEAD(&dma->queued_bufs);
spin_lock_init(&dma->queued_lock);
dma->fmtinfo = xvip_get_format_by_fourcc(XVIP_DMA_DEF_FORMAT);
dma->format.pixelformat = dma->fmtinfo->fourcc;
dma->format.colorspace = V4L2_COLORSPACE_SRGB;
dma->format.field = V4L2_FIELD_NONE;
dma->format.width = XVIP_DMA_DEF_WIDTH;
dma->format.height = XVIP_DMA_DEF_HEIGHT;
dma->format.bytesperline = dma->format.width * dma->fmtinfo->bpp;
dma->format.sizeimage = dma->format.bytesperline * dma->format.height;
dma->pad.flags = type == V4L2_BUF_TYPE_VIDEO_CAPTURE
? MEDIA_PAD_FL_SINK : MEDIA_PAD_FL_SOURCE;
ret = media_entity_pads_init(&dma->video.entity, 1, &dma->pad);
if (ret < 0)
goto error;
dma->video.fops = &xvip_dma_fops;
dma->video.v4l2_dev = &xdev->v4l2_dev;
dma->video.queue = &dma->queue;
snprintf(dma->video.name, sizeof(dma->video.name), "%s %s %u",
xdev->dev->of_node->name,
type == V4L2_BUF_TYPE_VIDEO_CAPTURE ? "output" : "input",
port);
dma->video.vfl_type = VFL_TYPE_GRABBER;
dma->video.vfl_dir = type == V4L2_BUF_TYPE_VIDEO_CAPTURE
? VFL_DIR_RX : VFL_DIR_TX;
dma->video.release = video_device_release_empty;
dma->video.ioctl_ops = &xvip_dma_ioctl_ops;
dma->video.lock = &dma->lock;
video_set_drvdata(&dma->video, dma);
dma->alloc_ctx = vb2_dma_contig_init_ctx(dma->xdev->dev);
if (IS_ERR(dma->alloc_ctx)) {
ret = PTR_ERR(dma->alloc_ctx);
goto error;
}
dma->queue.type = type;
dma->queue.io_modes = VB2_MMAP | VB2_USERPTR | VB2_DMABUF;
dma->queue.lock = &dma->lock;
dma->queue.drv_priv = dma;
dma->queue.buf_struct_size = sizeof(struct xvip_dma_buffer);
dma->queue.ops = &xvip_dma_queue_qops;
dma->queue.mem_ops = &vb2_dma_contig_memops;
dma->queue.timestamp_flags = V4L2_BUF_FLAG_TIMESTAMP_MONOTONIC
| V4L2_BUF_FLAG_TSTAMP_SRC_EOF;
ret = vb2_queue_init(&dma->queue);
if (ret < 0) {
dev_err(dma->xdev->dev, "failed to initialize VB2 queue\n");
goto error;
}
snprintf(name, sizeof(name), "port%u", port);
dma->dma = dma_request_slave_channel(dma->xdev->dev, name);
if (dma->dma == NULL) {
dev_err(dma->xdev->dev, "no VDMA channel found\n");
ret = -ENODEV;
goto error;
}
dma->align = 1 << dma->dma->device->copy_align;
ret = video_register_device(&dma->video, VFL_TYPE_GRABBER, -1);
if (ret < 0) {
dev_err(dma->xdev->dev, "failed to register video device\n");
goto error;
}
return 0;
error:
xvip_dma_cleanup(dma);
return ret;
}
void xvip_dma_cleanup(struct xvip_dma *dma)
{
if (video_is_registered(&dma->video))
video_unregister_device(&dma->video);
if (dma->dma)
dma_release_channel(dma->dma);
if (!IS_ERR_OR_NULL(dma->alloc_ctx))
vb2_dma_contig_cleanup_ctx(dma->alloc_ctx);
media_entity_cleanup(&dma->video.entity);
mutex_destroy(&dma->lock);
mutex_destroy(&dma->pipe.lock);
}
