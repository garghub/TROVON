static const struct vsp1_format_info *vsp1_get_format_info(u32 fourcc)
{
unsigned int i;
for (i = 0; i < ARRAY_SIZE(vsp1_video_formats); ++i) {
const struct vsp1_format_info *info = &vsp1_video_formats[i];
if (info->fourcc == fourcc)
return info;
}
return NULL;
}
static struct v4l2_subdev *
vsp1_video_remote_subdev(struct media_pad *local, u32 *pad)
{
struct media_pad *remote;
remote = media_entity_remote_pad(local);
if (remote == NULL ||
media_entity_type(remote->entity) != MEDIA_ENT_T_V4L2_SUBDEV)
return NULL;
if (pad)
*pad = remote->index;
return media_entity_to_v4l2_subdev(remote->entity);
}
static int vsp1_video_verify_format(struct vsp1_video *video)
{
struct v4l2_subdev_format fmt;
struct v4l2_subdev *subdev;
int ret;
subdev = vsp1_video_remote_subdev(&video->pad, &fmt.pad);
if (subdev == NULL)
return -EINVAL;
fmt.which = V4L2_SUBDEV_FORMAT_ACTIVE;
ret = v4l2_subdev_call(subdev, pad, get_fmt, NULL, &fmt);
if (ret < 0)
return ret == -ENOIOCTLCMD ? -EINVAL : ret;
if (video->fmtinfo->mbus != fmt.format.code ||
video->format.height != fmt.format.height ||
video->format.width != fmt.format.width)
return -EINVAL;
return 0;
}
static int __vsp1_video_try_format(struct vsp1_video *video,
struct v4l2_pix_format_mplane *pix,
const struct vsp1_format_info **fmtinfo)
{
static const u32 xrgb_formats[][2] = {
{ V4L2_PIX_FMT_RGB444, V4L2_PIX_FMT_XRGB444 },
{ V4L2_PIX_FMT_RGB555, V4L2_PIX_FMT_XRGB555 },
{ V4L2_PIX_FMT_BGR32, V4L2_PIX_FMT_XBGR32 },
{ V4L2_PIX_FMT_RGB32, V4L2_PIX_FMT_XRGB32 },
};
const struct vsp1_format_info *info;
unsigned int width = pix->width;
unsigned int height = pix->height;
unsigned int i;
for (i = 0; i < ARRAY_SIZE(xrgb_formats); ++i) {
if (xrgb_formats[i][0] == pix->pixelformat) {
pix->pixelformat = xrgb_formats[i][1];
break;
}
}
info = vsp1_get_format_info(pix->pixelformat);
if (info == NULL)
info = vsp1_get_format_info(VSP1_VIDEO_DEF_FORMAT);
pix->pixelformat = info->fourcc;
pix->colorspace = V4L2_COLORSPACE_SRGB;
pix->field = V4L2_FIELD_NONE;
memset(pix->reserved, 0, sizeof(pix->reserved));
width = round_down(width, info->hsub);
height = round_down(height, info->vsub);
pix->width = clamp(width, VSP1_VIDEO_MIN_WIDTH, VSP1_VIDEO_MAX_WIDTH);
pix->height = clamp(height, VSP1_VIDEO_MIN_HEIGHT,
VSP1_VIDEO_MAX_HEIGHT);
for (i = 0; i < max(info->planes, 2U); ++i) {
unsigned int hsub = i > 0 ? info->hsub : 1;
unsigned int vsub = i > 0 ? info->vsub : 1;
unsigned int align = 128;
unsigned int bpl;
bpl = clamp_t(unsigned int, pix->plane_fmt[i].bytesperline,
pix->width / hsub * info->bpp[i] / 8,
round_down(65535U, align));
pix->plane_fmt[i].bytesperline = round_up(bpl, align);
pix->plane_fmt[i].sizeimage = pix->plane_fmt[i].bytesperline
* pix->height / vsub;
}
if (info->planes == 3) {
pix->plane_fmt[2].bytesperline = pix->plane_fmt[1].bytesperline;
pix->plane_fmt[2].sizeimage = pix->plane_fmt[1].sizeimage;
}
pix->num_planes = info->planes;
if (fmtinfo)
*fmtinfo = info;
return 0;
}
static bool
vsp1_video_format_adjust(struct vsp1_video *video,
const struct v4l2_pix_format_mplane *format,
struct v4l2_pix_format_mplane *adjust)
{
unsigned int i;
*adjust = *format;
__vsp1_video_try_format(video, adjust, NULL);
if (format->width != adjust->width ||
format->height != adjust->height ||
format->pixelformat != adjust->pixelformat ||
format->num_planes != adjust->num_planes)
return false;
for (i = 0; i < format->num_planes; ++i) {
if (format->plane_fmt[i].bytesperline !=
adjust->plane_fmt[i].bytesperline)
return false;
adjust->plane_fmt[i].sizeimage =
max(adjust->plane_fmt[i].sizeimage,
format->plane_fmt[i].sizeimage);
}
return true;
}
static int vsp1_pipeline_validate_branch(struct vsp1_pipeline *pipe,
struct vsp1_rwpf *input,
struct vsp1_rwpf *output)
{
struct vsp1_entity *entity;
unsigned int entities = 0;
struct media_pad *pad;
bool bru_found = false;
input->location.left = 0;
input->location.top = 0;
pad = media_entity_remote_pad(&input->entity.pads[RWPF_PAD_SOURCE]);
while (1) {
if (pad == NULL)
return -EPIPE;
if (media_entity_type(pad->entity) != MEDIA_ENT_T_V4L2_SUBDEV)
return -EPIPE;
entity = to_vsp1_entity(media_entity_to_v4l2_subdev(pad->entity));
if (entity->type == VSP1_ENTITY_BRU) {
struct vsp1_bru *bru = to_bru(&entity->subdev);
struct v4l2_rect *rect =
&bru->inputs[pad->index].compose;
bru->inputs[pad->index].rpf = input;
input->location.left = rect->left;
input->location.top = rect->top;
bru_found = true;
}
if (entity->type == VSP1_ENTITY_WPF)
break;
if (entities & (1 << entity->subdev.entity.id))
return -EPIPE;
entities |= 1 << entity->subdev.entity.id;
if (entity->type == VSP1_ENTITY_UDS) {
if (pipe->uds)
return -EPIPE;
pipe->uds = entity;
pipe->uds_input = bru_found ? pipe->bru
: &input->entity;
}
pad = &entity->pads[entity->source_pad];
pad = media_entity_remote_pad(pad);
}
if (entity != &output->entity)
return -EPIPE;
return 0;
}
static void __vsp1_pipeline_cleanup(struct vsp1_pipeline *pipe)
{
if (pipe->bru) {
struct vsp1_bru *bru = to_bru(&pipe->bru->subdev);
unsigned int i;
for (i = 0; i < ARRAY_SIZE(bru->inputs); ++i)
bru->inputs[i].rpf = NULL;
}
INIT_LIST_HEAD(&pipe->entities);
pipe->state = VSP1_PIPELINE_STOPPED;
pipe->buffers_ready = 0;
pipe->num_video = 0;
pipe->num_inputs = 0;
pipe->output = NULL;
pipe->bru = NULL;
pipe->lif = NULL;
pipe->uds = NULL;
}
static int vsp1_pipeline_validate(struct vsp1_pipeline *pipe,
struct vsp1_video *video)
{
struct media_entity_graph graph;
struct media_entity *entity = &video->video.entity;
struct media_device *mdev = entity->parent;
unsigned int i;
int ret;
mutex_lock(&mdev->graph_mutex);
media_entity_graph_walk_start(&graph, entity);
while ((entity = media_entity_graph_walk_next(&graph))) {
struct v4l2_subdev *subdev;
struct vsp1_rwpf *rwpf;
struct vsp1_entity *e;
if (media_entity_type(entity) != MEDIA_ENT_T_V4L2_SUBDEV) {
pipe->num_video++;
continue;
}
subdev = media_entity_to_v4l2_subdev(entity);
e = to_vsp1_entity(subdev);
list_add_tail(&e->list_pipe, &pipe->entities);
if (e->type == VSP1_ENTITY_RPF) {
rwpf = to_rwpf(subdev);
pipe->inputs[pipe->num_inputs++] = rwpf;
rwpf->video.pipe_index = pipe->num_inputs;
} else if (e->type == VSP1_ENTITY_WPF) {
rwpf = to_rwpf(subdev);
pipe->output = to_rwpf(subdev);
rwpf->video.pipe_index = 0;
} else if (e->type == VSP1_ENTITY_LIF) {
pipe->lif = e;
} else if (e->type == VSP1_ENTITY_BRU) {
pipe->bru = e;
}
}
mutex_unlock(&mdev->graph_mutex);
if (pipe->num_inputs == 0 || !pipe->output) {
ret = -EPIPE;
goto error;
}
for (i = 0; i < pipe->num_inputs; ++i) {
ret = vsp1_pipeline_validate_branch(pipe, pipe->inputs[i],
pipe->output);
if (ret < 0)
goto error;
}
return 0;
error:
__vsp1_pipeline_cleanup(pipe);
return ret;
}
static int vsp1_pipeline_init(struct vsp1_pipeline *pipe,
struct vsp1_video *video)
{
int ret;
mutex_lock(&pipe->lock);
if (pipe->use_count == 0) {
ret = vsp1_pipeline_validate(pipe, video);
if (ret < 0)
goto done;
}
pipe->use_count++;
ret = 0;
done:
mutex_unlock(&pipe->lock);
return ret;
}
static void vsp1_pipeline_cleanup(struct vsp1_pipeline *pipe)
{
mutex_lock(&pipe->lock);
if (--pipe->use_count == 0)
__vsp1_pipeline_cleanup(pipe);
mutex_unlock(&pipe->lock);
}
static void vsp1_pipeline_run(struct vsp1_pipeline *pipe)
{
struct vsp1_device *vsp1 = pipe->output->entity.vsp1;
vsp1_write(vsp1, VI6_CMD(pipe->output->entity.index), VI6_CMD_STRCMD);
pipe->state = VSP1_PIPELINE_RUNNING;
pipe->buffers_ready = 0;
}
static int vsp1_pipeline_stop(struct vsp1_pipeline *pipe)
{
struct vsp1_entity *entity;
unsigned long flags;
int ret;
spin_lock_irqsave(&pipe->irqlock, flags);
if (pipe->state == VSP1_PIPELINE_RUNNING)
pipe->state = VSP1_PIPELINE_STOPPING;
spin_unlock_irqrestore(&pipe->irqlock, flags);
ret = wait_event_timeout(pipe->wq, pipe->state == VSP1_PIPELINE_STOPPED,
msecs_to_jiffies(500));
ret = ret == 0 ? -ETIMEDOUT : 0;
list_for_each_entry(entity, &pipe->entities, list_pipe) {
if (entity->route && entity->route->reg)
vsp1_write(entity->vsp1, entity->route->reg,
VI6_DPR_NODE_UNUSED);
v4l2_subdev_call(&entity->subdev, video, s_stream, 0);
}
return ret;
}
static bool vsp1_pipeline_ready(struct vsp1_pipeline *pipe)
{
unsigned int mask;
mask = ((1 << pipe->num_inputs) - 1) << 1;
if (!pipe->lif)
mask |= 1 << 0;
return pipe->buffers_ready == mask;
}
static struct vsp1_video_buffer *
vsp1_video_complete_buffer(struct vsp1_video *video)
{
struct vsp1_pipeline *pipe = to_vsp1_pipeline(&video->video.entity);
struct vsp1_video_buffer *next = NULL;
struct vsp1_video_buffer *done;
unsigned long flags;
unsigned int i;
spin_lock_irqsave(&video->irqlock, flags);
if (list_empty(&video->irqqueue)) {
spin_unlock_irqrestore(&video->irqlock, flags);
return NULL;
}
done = list_first_entry(&video->irqqueue,
struct vsp1_video_buffer, queue);
if (pipe->lif && list_is_singular(&video->irqqueue)) {
spin_unlock_irqrestore(&video->irqlock, flags);
return done;
}
list_del(&done->queue);
if (!list_empty(&video->irqqueue))
next = list_first_entry(&video->irqqueue,
struct vsp1_video_buffer, queue);
spin_unlock_irqrestore(&video->irqlock, flags);
done->buf.v4l2_buf.sequence = video->sequence++;
v4l2_get_timestamp(&done->buf.v4l2_buf.timestamp);
for (i = 0; i < done->buf.num_planes; ++i)
vb2_set_plane_payload(&done->buf, i, done->length[i]);
vb2_buffer_done(&done->buf, VB2_BUF_STATE_DONE);
return next;
}
static void vsp1_video_frame_end(struct vsp1_pipeline *pipe,
struct vsp1_video *video)
{
struct vsp1_video_buffer *buf;
unsigned long flags;
buf = vsp1_video_complete_buffer(video);
if (buf == NULL)
return;
spin_lock_irqsave(&pipe->irqlock, flags);
video->ops->queue(video, buf);
pipe->buffers_ready |= 1 << video->pipe_index;
spin_unlock_irqrestore(&pipe->irqlock, flags);
}
void vsp1_pipeline_frame_end(struct vsp1_pipeline *pipe)
{
enum vsp1_pipeline_state state;
unsigned long flags;
unsigned int i;
if (pipe == NULL)
return;
for (i = 0; i < pipe->num_inputs; ++i)
vsp1_video_frame_end(pipe, &pipe->inputs[i]->video);
if (!pipe->lif)
vsp1_video_frame_end(pipe, &pipe->output->video);
spin_lock_irqsave(&pipe->irqlock, flags);
state = pipe->state;
pipe->state = VSP1_PIPELINE_STOPPED;
if (state == VSP1_PIPELINE_STOPPING) {
wake_up(&pipe->wq);
goto done;
}
if (vsp1_pipeline_ready(pipe))
vsp1_pipeline_run(pipe);
done:
spin_unlock_irqrestore(&pipe->irqlock, flags);
}
void vsp1_pipeline_propagate_alpha(struct vsp1_pipeline *pipe,
struct vsp1_entity *input,
unsigned int alpha)
{
struct vsp1_entity *entity;
struct media_pad *pad;
pad = media_entity_remote_pad(&input->pads[RWPF_PAD_SOURCE]);
while (pad) {
if (media_entity_type(pad->entity) != MEDIA_ENT_T_V4L2_SUBDEV)
break;
entity = to_vsp1_entity(media_entity_to_v4l2_subdev(pad->entity));
if (entity->type == VSP1_ENTITY_BRU)
alpha = 255;
if (entity->type == VSP1_ENTITY_UDS) {
struct vsp1_uds *uds = to_uds(&entity->subdev);
vsp1_uds_set_alpha(uds, alpha);
break;
}
pad = &entity->pads[entity->source_pad];
pad = media_entity_remote_pad(pad);
}
}
static int
vsp1_video_queue_setup(struct vb2_queue *vq, const struct v4l2_format *fmt,
unsigned int *nbuffers, unsigned int *nplanes,
unsigned int sizes[], void *alloc_ctxs[])
{
struct vsp1_video *video = vb2_get_drv_priv(vq);
const struct v4l2_pix_format_mplane *format;
struct v4l2_pix_format_mplane pix_mp;
unsigned int i;
if (fmt) {
if (!vsp1_video_format_adjust(video, &fmt->fmt.pix_mp, &pix_mp))
return -EINVAL;
format = &pix_mp;
} else {
format = &video->format;
}
*nplanes = format->num_planes;
for (i = 0; i < format->num_planes; ++i) {
sizes[i] = format->plane_fmt[i].sizeimage;
alloc_ctxs[i] = video->alloc_ctx;
}
return 0;
}
static int vsp1_video_buffer_prepare(struct vb2_buffer *vb)
{
struct vsp1_video *video = vb2_get_drv_priv(vb->vb2_queue);
struct vsp1_video_buffer *buf = to_vsp1_video_buffer(vb);
const struct v4l2_pix_format_mplane *format = &video->format;
unsigned int i;
if (vb->num_planes < format->num_planes)
return -EINVAL;
for (i = 0; i < vb->num_planes; ++i) {
buf->addr[i] = vb2_dma_contig_plane_dma_addr(vb, i);
buf->length[i] = vb2_plane_size(vb, i);
if (buf->length[i] < format->plane_fmt[i].sizeimage)
return -EINVAL;
}
return 0;
}
static void vsp1_video_buffer_queue(struct vb2_buffer *vb)
{
struct vsp1_video *video = vb2_get_drv_priv(vb->vb2_queue);
struct vsp1_pipeline *pipe = to_vsp1_pipeline(&video->video.entity);
struct vsp1_video_buffer *buf = to_vsp1_video_buffer(vb);
unsigned long flags;
bool empty;
spin_lock_irqsave(&video->irqlock, flags);
empty = list_empty(&video->irqqueue);
list_add_tail(&buf->queue, &video->irqqueue);
spin_unlock_irqrestore(&video->irqlock, flags);
if (!empty)
return;
spin_lock_irqsave(&pipe->irqlock, flags);
video->ops->queue(video, buf);
pipe->buffers_ready |= 1 << video->pipe_index;
if (vb2_is_streaming(&video->queue) &&
vsp1_pipeline_ready(pipe))
vsp1_pipeline_run(pipe);
spin_unlock_irqrestore(&pipe->irqlock, flags);
}
static void vsp1_entity_route_setup(struct vsp1_entity *source)
{
struct vsp1_entity *sink;
if (source->route->reg == 0)
return;
sink = container_of(source->sink, struct vsp1_entity, subdev.entity);
vsp1_write(source->vsp1, source->route->reg,
sink->route->inputs[source->sink_pad]);
}
static int vsp1_video_start_streaming(struct vb2_queue *vq, unsigned int count)
{
struct vsp1_video *video = vb2_get_drv_priv(vq);
struct vsp1_pipeline *pipe = to_vsp1_pipeline(&video->video.entity);
struct vsp1_entity *entity;
unsigned long flags;
int ret;
mutex_lock(&pipe->lock);
if (pipe->stream_count == pipe->num_video - 1) {
if (pipe->uds) {
struct vsp1_uds *uds = to_uds(&pipe->uds->subdev);
if (pipe->uds_input->type == VSP1_ENTITY_BRU) {
uds->scale_alpha = false;
} else {
struct vsp1_rwpf *rpf =
to_rwpf(&pipe->uds_input->subdev);
uds->scale_alpha = rpf->video.fmtinfo->alpha;
}
}
list_for_each_entry(entity, &pipe->entities, list_pipe) {
vsp1_entity_route_setup(entity);
ret = v4l2_subdev_call(&entity->subdev, video,
s_stream, 1);
if (ret < 0) {
mutex_unlock(&pipe->lock);
return ret;
}
}
}
pipe->stream_count++;
mutex_unlock(&pipe->lock);
spin_lock_irqsave(&pipe->irqlock, flags);
if (vsp1_pipeline_ready(pipe))
vsp1_pipeline_run(pipe);
spin_unlock_irqrestore(&pipe->irqlock, flags);
return 0;
}
static void vsp1_video_stop_streaming(struct vb2_queue *vq)
{
struct vsp1_video *video = vb2_get_drv_priv(vq);
struct vsp1_pipeline *pipe = to_vsp1_pipeline(&video->video.entity);
struct vsp1_video_buffer *buffer;
unsigned long flags;
int ret;
mutex_lock(&pipe->lock);
if (--pipe->stream_count == 0) {
ret = vsp1_pipeline_stop(pipe);
if (ret == -ETIMEDOUT)
dev_err(video->vsp1->dev, "pipeline stop timeout\n");
}
mutex_unlock(&pipe->lock);
vsp1_pipeline_cleanup(pipe);
media_entity_pipeline_stop(&video->video.entity);
spin_lock_irqsave(&video->irqlock, flags);
list_for_each_entry(buffer, &video->irqqueue, queue)
vb2_buffer_done(&buffer->buf, VB2_BUF_STATE_ERROR);
INIT_LIST_HEAD(&video->irqqueue);
spin_unlock_irqrestore(&video->irqlock, flags);
}
static int
vsp1_video_querycap(struct file *file, void *fh, struct v4l2_capability *cap)
{
struct v4l2_fh *vfh = file->private_data;
struct vsp1_video *video = to_vsp1_video(vfh->vdev);
cap->capabilities = V4L2_CAP_DEVICE_CAPS | V4L2_CAP_STREAMING
| V4L2_CAP_VIDEO_CAPTURE_MPLANE
| V4L2_CAP_VIDEO_OUTPUT_MPLANE;
if (video->type == V4L2_BUF_TYPE_VIDEO_CAPTURE_MPLANE)
cap->device_caps = V4L2_CAP_VIDEO_CAPTURE_MPLANE
| V4L2_CAP_STREAMING;
else
cap->device_caps = V4L2_CAP_VIDEO_OUTPUT_MPLANE
| V4L2_CAP_STREAMING;
strlcpy(cap->driver, "vsp1", sizeof(cap->driver));
strlcpy(cap->card, video->video.name, sizeof(cap->card));
snprintf(cap->bus_info, sizeof(cap->bus_info), "platform:%s",
dev_name(video->vsp1->dev));
return 0;
}
static int
vsp1_video_get_format(struct file *file, void *fh, struct v4l2_format *format)
{
struct v4l2_fh *vfh = file->private_data;
struct vsp1_video *video = to_vsp1_video(vfh->vdev);
if (format->type != video->queue.type)
return -EINVAL;
mutex_lock(&video->lock);
format->fmt.pix_mp = video->format;
mutex_unlock(&video->lock);
return 0;
}
static int
vsp1_video_try_format(struct file *file, void *fh, struct v4l2_format *format)
{
struct v4l2_fh *vfh = file->private_data;
struct vsp1_video *video = to_vsp1_video(vfh->vdev);
if (format->type != video->queue.type)
return -EINVAL;
return __vsp1_video_try_format(video, &format->fmt.pix_mp, NULL);
}
static int
vsp1_video_set_format(struct file *file, void *fh, struct v4l2_format *format)
{
struct v4l2_fh *vfh = file->private_data;
struct vsp1_video *video = to_vsp1_video(vfh->vdev);
const struct vsp1_format_info *info;
int ret;
if (format->type != video->queue.type)
return -EINVAL;
ret = __vsp1_video_try_format(video, &format->fmt.pix_mp, &info);
if (ret < 0)
return ret;
mutex_lock(&video->lock);
if (vb2_is_busy(&video->queue)) {
ret = -EBUSY;
goto done;
}
video->format = format->fmt.pix_mp;
video->fmtinfo = info;
done:
mutex_unlock(&video->lock);
return ret;
}
static int
vsp1_video_streamon(struct file *file, void *fh, enum v4l2_buf_type type)
{
struct v4l2_fh *vfh = file->private_data;
struct vsp1_video *video = to_vsp1_video(vfh->vdev);
struct vsp1_pipeline *pipe;
int ret;
if (video->queue.owner && video->queue.owner != file->private_data)
return -EBUSY;
video->sequence = 0;
pipe = video->video.entity.pipe
? to_vsp1_pipeline(&video->video.entity) : &video->pipe;
ret = media_entity_pipeline_start(&video->video.entity, &pipe->pipe);
if (ret < 0)
return ret;
ret = vsp1_video_verify_format(video);
if (ret < 0)
goto err_stop;
ret = vsp1_pipeline_init(pipe, video);
if (ret < 0)
goto err_stop;
ret = vb2_streamon(&video->queue, type);
if (ret < 0)
goto err_cleanup;
return 0;
err_cleanup:
vsp1_pipeline_cleanup(pipe);
err_stop:
media_entity_pipeline_stop(&video->video.entity);
return ret;
}
static int vsp1_video_open(struct file *file)
{
struct vsp1_video *video = video_drvdata(file);
struct v4l2_fh *vfh;
int ret = 0;
vfh = kzalloc(sizeof(*vfh), GFP_KERNEL);
if (vfh == NULL)
return -ENOMEM;
v4l2_fh_init(vfh, &video->video);
v4l2_fh_add(vfh);
file->private_data = vfh;
ret = vsp1_device_get(video->vsp1);
if (ret < 0) {
v4l2_fh_del(vfh);
kfree(vfh);
}
return ret;
}
static int vsp1_video_release(struct file *file)
{
struct vsp1_video *video = video_drvdata(file);
struct v4l2_fh *vfh = file->private_data;
mutex_lock(&video->lock);
if (video->queue.owner == vfh) {
vb2_queue_release(&video->queue);
video->queue.owner = NULL;
}
mutex_unlock(&video->lock);
vsp1_device_put(video->vsp1);
v4l2_fh_release(file);
file->private_data = NULL;
return 0;
}
int vsp1_video_init(struct vsp1_video *video, struct vsp1_entity *rwpf)
{
const char *direction;
int ret;
switch (video->type) {
case V4L2_BUF_TYPE_VIDEO_CAPTURE_MPLANE:
direction = "output";
video->pad.flags = MEDIA_PAD_FL_SINK;
break;
case V4L2_BUF_TYPE_VIDEO_OUTPUT_MPLANE:
direction = "input";
video->pad.flags = MEDIA_PAD_FL_SOURCE;
video->video.vfl_dir = VFL_DIR_TX;
break;
default:
return -EINVAL;
}
video->rwpf = rwpf;
mutex_init(&video->lock);
spin_lock_init(&video->irqlock);
INIT_LIST_HEAD(&video->irqqueue);
mutex_init(&video->pipe.lock);
spin_lock_init(&video->pipe.irqlock);
INIT_LIST_HEAD(&video->pipe.entities);
init_waitqueue_head(&video->pipe.wq);
video->pipe.state = VSP1_PIPELINE_STOPPED;
ret = media_entity_init(&video->video.entity, 1, &video->pad, 0);
if (ret < 0)
return ret;
video->fmtinfo = vsp1_get_format_info(VSP1_VIDEO_DEF_FORMAT);
video->format.pixelformat = video->fmtinfo->fourcc;
video->format.colorspace = V4L2_COLORSPACE_SRGB;
video->format.field = V4L2_FIELD_NONE;
video->format.width = VSP1_VIDEO_DEF_WIDTH;
video->format.height = VSP1_VIDEO_DEF_HEIGHT;
video->format.num_planes = 1;
video->format.plane_fmt[0].bytesperline =
video->format.width * video->fmtinfo->bpp[0] / 8;
video->format.plane_fmt[0].sizeimage =
video->format.plane_fmt[0].bytesperline * video->format.height;
video->video.v4l2_dev = &video->vsp1->v4l2_dev;
video->video.fops = &vsp1_video_fops;
snprintf(video->video.name, sizeof(video->video.name), "%s %s",
rwpf->subdev.name, direction);
video->video.vfl_type = VFL_TYPE_GRABBER;
video->video.release = video_device_release_empty;
video->video.ioctl_ops = &vsp1_video_ioctl_ops;
video_set_drvdata(&video->video, video);
video->alloc_ctx = vb2_dma_contig_init_ctx(video->vsp1->dev);
if (IS_ERR(video->alloc_ctx)) {
ret = PTR_ERR(video->alloc_ctx);
goto error;
}
video->queue.type = video->type;
video->queue.io_modes = VB2_MMAP | VB2_USERPTR | VB2_DMABUF;
video->queue.lock = &video->lock;
video->queue.drv_priv = video;
video->queue.buf_struct_size = sizeof(struct vsp1_video_buffer);
video->queue.ops = &vsp1_video_queue_qops;
video->queue.mem_ops = &vb2_dma_contig_memops;
video->queue.timestamp_flags = V4L2_BUF_FLAG_TIMESTAMP_COPY;
ret = vb2_queue_init(&video->queue);
if (ret < 0) {
dev_err(video->vsp1->dev, "failed to initialize vb2 queue\n");
goto error;
}
video->video.queue = &video->queue;
ret = video_register_device(&video->video, VFL_TYPE_GRABBER, -1);
if (ret < 0) {
dev_err(video->vsp1->dev, "failed to register video device\n");
goto error;
}
return 0;
error:
vb2_dma_contig_cleanup_ctx(video->alloc_ctx);
vsp1_video_cleanup(video);
return ret;
}
void vsp1_video_cleanup(struct vsp1_video *video)
{
if (video_is_registered(&video->video))
video_unregister_device(&video->video);
vb2_dma_contig_cleanup_ctx(video->alloc_ctx);
media_entity_cleanup(&video->video.entity);
}
