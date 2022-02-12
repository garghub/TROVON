static struct v4l2_subdev *
vsp1_video_remote_subdev(struct media_pad *local, u32 *pad)
{
struct media_pad *remote;
remote = media_entity_remote_pad(local);
if (!remote || !is_media_entity_v4l2_subdev(remote->entity))
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
if (video->rwpf->fmtinfo->mbus != fmt.format.code ||
video->rwpf->format.height != fmt.format.height ||
video->rwpf->format.width != fmt.format.width)
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
info = vsp1_get_format_info(video->vsp1, pix->pixelformat);
if (info == NULL)
info = vsp1_get_format_info(video->vsp1, VSP1_VIDEO_DEF_FORMAT);
pix->pixelformat = info->fourcc;
pix->colorspace = V4L2_COLORSPACE_SRGB;
pix->field = V4L2_FIELD_NONE;
if (info->fourcc == V4L2_PIX_FMT_HSV24 ||
info->fourcc == V4L2_PIX_FMT_HSV32)
pix->hsv_enc = V4L2_HSV_ENC_256;
memset(pix->reserved, 0, sizeof(pix->reserved));
width = round_down(width, info->hsub);
height = round_down(height, info->vsub);
pix->width = clamp(width, VSP1_VIDEO_MIN_WIDTH, VSP1_VIDEO_MAX_WIDTH);
pix->height = clamp(height, VSP1_VIDEO_MIN_HEIGHT,
VSP1_VIDEO_MAX_HEIGHT);
for (i = 0; i < min(info->planes, 2U); ++i) {
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
static void vsp1_video_pipeline_setup_partitions(struct vsp1_pipeline *pipe)
{
struct vsp1_device *vsp1 = pipe->output->entity.vsp1;
const struct v4l2_mbus_framefmt *format;
struct vsp1_entity *entity;
unsigned int div_size;
format = vsp1_entity_get_pad_format(&pipe->output->entity,
pipe->output->entity.config,
RWPF_PAD_SINK);
div_size = format->width;
if (vsp1->info->gen == 2) {
pipe->div_size = div_size;
pipe->partitions = 1;
return;
}
list_for_each_entry(entity, &pipe->entities, list_pipe) {
unsigned int entity_max = VSP1_VIDEO_MAX_WIDTH;
if (entity->ops->max_width) {
entity_max = entity->ops->max_width(entity, pipe);
if (entity_max)
div_size = min(div_size, entity_max);
}
}
pipe->div_size = div_size;
pipe->partitions = DIV_ROUND_UP(format->width, div_size);
}
static struct v4l2_rect vsp1_video_partition(struct vsp1_pipeline *pipe,
unsigned int div_size,
unsigned int index)
{
const struct v4l2_mbus_framefmt *format;
struct v4l2_rect partition;
unsigned int modulus;
format = vsp1_entity_get_pad_format(&pipe->output->entity,
pipe->output->entity.config,
RWPF_PAD_SINK);
if (pipe->partitions <= 1) {
partition.left = 0;
partition.top = 0;
partition.width = format->width;
partition.height = format->height;
return partition;
}
partition.left = index * div_size;
partition.top = 0;
partition.width = div_size;
partition.height = format->height;
modulus = format->width % div_size;
if (modulus) {
unsigned int partitions = pipe->partitions - 1;
if (modulus < div_size / 2) {
if (index == partitions - 1) {
partition.width = div_size / 2;
} else if (index == partitions) {
partition.width = (div_size / 2) + modulus;
partition.left -= div_size / 2;
}
} else if (index == partitions) {
partition.width = modulus;
}
}
return partition;
}
static struct vsp1_vb2_buffer *
vsp1_video_complete_buffer(struct vsp1_video *video)
{
struct vsp1_pipeline *pipe = video->rwpf->pipe;
struct vsp1_vb2_buffer *next = NULL;
struct vsp1_vb2_buffer *done;
unsigned long flags;
unsigned int i;
spin_lock_irqsave(&video->irqlock, flags);
if (list_empty(&video->irqqueue)) {
spin_unlock_irqrestore(&video->irqlock, flags);
return NULL;
}
done = list_first_entry(&video->irqqueue,
struct vsp1_vb2_buffer, queue);
if (pipe->lif && list_is_singular(&video->irqqueue)) {
spin_unlock_irqrestore(&video->irqlock, flags);
return done;
}
list_del(&done->queue);
if (!list_empty(&video->irqqueue))
next = list_first_entry(&video->irqqueue,
struct vsp1_vb2_buffer, queue);
spin_unlock_irqrestore(&video->irqlock, flags);
done->buf.sequence = pipe->sequence;
done->buf.vb2_buf.timestamp = ktime_get_ns();
for (i = 0; i < done->buf.vb2_buf.num_planes; ++i)
vb2_set_plane_payload(&done->buf.vb2_buf, i,
vb2_plane_size(&done->buf.vb2_buf, i));
vb2_buffer_done(&done->buf.vb2_buf, VB2_BUF_STATE_DONE);
return next;
}
static void vsp1_video_frame_end(struct vsp1_pipeline *pipe,
struct vsp1_rwpf *rwpf)
{
struct vsp1_video *video = rwpf->video;
struct vsp1_vb2_buffer *buf;
buf = vsp1_video_complete_buffer(video);
if (buf == NULL)
return;
video->rwpf->mem = buf->mem;
pipe->buffers_ready |= 1 << video->pipe_index;
}
static void vsp1_video_pipeline_run_partition(struct vsp1_pipeline *pipe,
struct vsp1_dl_list *dl)
{
struct vsp1_entity *entity;
pipe->partition = vsp1_video_partition(pipe, pipe->div_size,
pipe->current_partition);
list_for_each_entry(entity, &pipe->entities, list_pipe) {
if (entity->ops->configure)
entity->ops->configure(entity, pipe, dl,
VSP1_ENTITY_PARAMS_PARTITION);
}
}
static void vsp1_video_pipeline_run(struct vsp1_pipeline *pipe)
{
struct vsp1_device *vsp1 = pipe->output->entity.vsp1;
struct vsp1_entity *entity;
if (!pipe->dl)
pipe->dl = vsp1_dl_list_get(pipe->output->dlm);
list_for_each_entry(entity, &pipe->entities, list_pipe) {
if (entity->ops->configure)
entity->ops->configure(entity, pipe, pipe->dl,
VSP1_ENTITY_PARAMS_RUNTIME);
}
pipe->current_partition = 0;
vsp1_video_pipeline_run_partition(pipe, pipe->dl);
for (pipe->current_partition = 1;
pipe->current_partition < pipe->partitions;
pipe->current_partition++) {
struct vsp1_dl_list *dl;
dl = vsp1_dl_list_get(pipe->output->dlm);
if (!dl) {
dev_err(vsp1->dev, "Failed to obtain a dl list. Frame will be incomplete\n");
break;
}
vsp1_video_pipeline_run_partition(pipe, dl);
vsp1_dl_list_add_chain(pipe->dl, dl);
}
vsp1_dl_list_commit(pipe->dl);
pipe->dl = NULL;
vsp1_pipeline_run(pipe);
}
static void vsp1_video_pipeline_frame_end(struct vsp1_pipeline *pipe)
{
struct vsp1_device *vsp1 = pipe->output->entity.vsp1;
enum vsp1_pipeline_state state;
unsigned long flags;
unsigned int i;
spin_lock_irqsave(&pipe->irqlock, flags);
for (i = 0; i < vsp1->info->rpf_count; ++i) {
if (!pipe->inputs[i])
continue;
vsp1_video_frame_end(pipe, pipe->inputs[i]);
}
vsp1_video_frame_end(pipe, pipe->output);
state = pipe->state;
pipe->state = VSP1_PIPELINE_STOPPED;
if (state == VSP1_PIPELINE_STOPPING)
wake_up(&pipe->wq);
else if (vsp1_pipeline_ready(pipe))
vsp1_video_pipeline_run(pipe);
spin_unlock_irqrestore(&pipe->irqlock, flags);
}
static int vsp1_video_pipeline_build_branch(struct vsp1_pipeline *pipe,
struct vsp1_rwpf *input,
struct vsp1_rwpf *output)
{
struct media_entity_enum ent_enum;
struct vsp1_entity *entity;
struct media_pad *pad;
bool bru_found = false;
int ret;
ret = media_entity_enum_init(&ent_enum, &input->entity.vsp1->media_dev);
if (ret < 0)
return ret;
pad = vsp1_entity_remote_pad(&input->entity.pads[RWPF_PAD_SOURCE]);
while (1) {
if (pad == NULL) {
ret = -EPIPE;
goto out;
}
if (!is_media_entity_v4l2_subdev(pad->entity)) {
ret = -EPIPE;
goto out;
}
entity = to_vsp1_entity(
media_entity_to_v4l2_subdev(pad->entity));
if (entity->type == VSP1_ENTITY_BRU) {
struct vsp1_bru *bru = to_bru(&entity->subdev);
bru->inputs[pad->index].rpf = input;
input->bru_input = pad->index;
bru_found = true;
}
if (entity->type == VSP1_ENTITY_WPF)
break;
if (media_entity_enum_test_and_set(&ent_enum,
&entity->subdev.entity)) {
ret = -EPIPE;
goto out;
}
if (entity->type == VSP1_ENTITY_UDS) {
if (pipe->uds) {
ret = -EPIPE;
goto out;
}
pipe->uds = entity;
pipe->uds_input = bru_found ? pipe->bru
: &input->entity;
}
pad = &entity->pads[entity->source_pad];
pad = vsp1_entity_remote_pad(pad);
}
if (entity != &output->entity)
ret = -EPIPE;
out:
media_entity_enum_cleanup(&ent_enum);
return ret;
}
static int vsp1_video_pipeline_build(struct vsp1_pipeline *pipe,
struct vsp1_video *video)
{
struct media_graph graph;
struct media_entity *entity = &video->video.entity;
struct media_device *mdev = entity->graph_obj.mdev;
unsigned int i;
int ret;
ret = media_graph_walk_init(&graph, mdev);
if (ret)
return ret;
media_graph_walk_start(&graph, entity);
while ((entity = media_graph_walk_next(&graph))) {
struct v4l2_subdev *subdev;
struct vsp1_rwpf *rwpf;
struct vsp1_entity *e;
if (!is_media_entity_v4l2_subdev(entity))
continue;
subdev = media_entity_to_v4l2_subdev(entity);
e = to_vsp1_entity(subdev);
list_add_tail(&e->list_pipe, &pipe->entities);
if (e->type == VSP1_ENTITY_RPF) {
rwpf = to_rwpf(subdev);
pipe->inputs[rwpf->entity.index] = rwpf;
rwpf->video->pipe_index = ++pipe->num_inputs;
rwpf->pipe = pipe;
} else if (e->type == VSP1_ENTITY_WPF) {
rwpf = to_rwpf(subdev);
pipe->output = rwpf;
rwpf->video->pipe_index = 0;
rwpf->pipe = pipe;
} else if (e->type == VSP1_ENTITY_LIF) {
pipe->lif = e;
} else if (e->type == VSP1_ENTITY_BRU) {
pipe->bru = e;
} else if (e->type == VSP1_ENTITY_HGO) {
struct vsp1_hgo *hgo = to_hgo(subdev);
pipe->hgo = e;
hgo->histo.pipe = pipe;
} else if (e->type == VSP1_ENTITY_HGT) {
struct vsp1_hgt *hgt = to_hgt(subdev);
pipe->hgt = e;
hgt->histo.pipe = pipe;
}
}
media_graph_walk_cleanup(&graph);
if (pipe->num_inputs == 0 || !pipe->output)
return -EPIPE;
for (i = 0; i < video->vsp1->info->rpf_count; ++i) {
if (!pipe->inputs[i])
continue;
ret = vsp1_video_pipeline_build_branch(pipe, pipe->inputs[i],
pipe->output);
if (ret < 0)
return ret;
}
return 0;
}
static int vsp1_video_pipeline_init(struct vsp1_pipeline *pipe,
struct vsp1_video *video)
{
vsp1_pipeline_init(pipe);
pipe->frame_end = vsp1_video_pipeline_frame_end;
return vsp1_video_pipeline_build(pipe, video);
}
static struct vsp1_pipeline *vsp1_video_pipeline_get(struct vsp1_video *video)
{
struct vsp1_pipeline *pipe;
int ret;
if (!video->rwpf->pipe) {
pipe = kzalloc(sizeof(*pipe), GFP_KERNEL);
if (!pipe)
return ERR_PTR(-ENOMEM);
ret = vsp1_video_pipeline_init(pipe, video);
if (ret < 0) {
vsp1_pipeline_reset(pipe);
kfree(pipe);
return ERR_PTR(ret);
}
} else {
pipe = video->rwpf->pipe;
kref_get(&pipe->kref);
}
return pipe;
}
static void vsp1_video_pipeline_release(struct kref *kref)
{
struct vsp1_pipeline *pipe = container_of(kref, typeof(*pipe), kref);
vsp1_pipeline_reset(pipe);
kfree(pipe);
}
static void vsp1_video_pipeline_put(struct vsp1_pipeline *pipe)
{
struct media_device *mdev = &pipe->output->entity.vsp1->media_dev;
mutex_lock(&mdev->graph_mutex);
kref_put(&pipe->kref, vsp1_video_pipeline_release);
mutex_unlock(&mdev->graph_mutex);
}
static int
vsp1_video_queue_setup(struct vb2_queue *vq,
unsigned int *nbuffers, unsigned int *nplanes,
unsigned int sizes[], struct device *alloc_devs[])
{
struct vsp1_video *video = vb2_get_drv_priv(vq);
const struct v4l2_pix_format_mplane *format = &video->rwpf->format;
unsigned int i;
if (*nplanes) {
if (*nplanes != format->num_planes)
return -EINVAL;
for (i = 0; i < *nplanes; i++)
if (sizes[i] < format->plane_fmt[i].sizeimage)
return -EINVAL;
return 0;
}
*nplanes = format->num_planes;
for (i = 0; i < format->num_planes; ++i)
sizes[i] = format->plane_fmt[i].sizeimage;
return 0;
}
static int vsp1_video_buffer_prepare(struct vb2_buffer *vb)
{
struct vb2_v4l2_buffer *vbuf = to_vb2_v4l2_buffer(vb);
struct vsp1_video *video = vb2_get_drv_priv(vb->vb2_queue);
struct vsp1_vb2_buffer *buf = to_vsp1_vb2_buffer(vbuf);
const struct v4l2_pix_format_mplane *format = &video->rwpf->format;
unsigned int i;
if (vb->num_planes < format->num_planes)
return -EINVAL;
for (i = 0; i < vb->num_planes; ++i) {
buf->mem.addr[i] = vb2_dma_contig_plane_dma_addr(vb, i);
if (vb2_plane_size(vb, i) < format->plane_fmt[i].sizeimage)
return -EINVAL;
}
for ( ; i < 3; ++i)
buf->mem.addr[i] = 0;
return 0;
}
static void vsp1_video_buffer_queue(struct vb2_buffer *vb)
{
struct vb2_v4l2_buffer *vbuf = to_vb2_v4l2_buffer(vb);
struct vsp1_video *video = vb2_get_drv_priv(vb->vb2_queue);
struct vsp1_pipeline *pipe = video->rwpf->pipe;
struct vsp1_vb2_buffer *buf = to_vsp1_vb2_buffer(vbuf);
unsigned long flags;
bool empty;
spin_lock_irqsave(&video->irqlock, flags);
empty = list_empty(&video->irqqueue);
list_add_tail(&buf->queue, &video->irqqueue);
spin_unlock_irqrestore(&video->irqlock, flags);
if (!empty)
return;
spin_lock_irqsave(&pipe->irqlock, flags);
video->rwpf->mem = buf->mem;
pipe->buffers_ready |= 1 << video->pipe_index;
if (vb2_is_streaming(&video->queue) &&
vsp1_pipeline_ready(pipe))
vsp1_video_pipeline_run(pipe);
spin_unlock_irqrestore(&pipe->irqlock, flags);
}
static int vsp1_video_setup_pipeline(struct vsp1_pipeline *pipe)
{
struct vsp1_entity *entity;
vsp1_video_pipeline_setup_partitions(pipe);
pipe->dl = vsp1_dl_list_get(pipe->output->dlm);
if (!pipe->dl)
return -ENOMEM;
if (pipe->uds) {
struct vsp1_uds *uds = to_uds(&pipe->uds->subdev);
if (pipe->uds_input->type == VSP1_ENTITY_BRU) {
uds->scale_alpha = false;
} else {
struct vsp1_rwpf *rpf =
to_rwpf(&pipe->uds_input->subdev);
uds->scale_alpha = rpf->fmtinfo->alpha;
}
}
list_for_each_entry(entity, &pipe->entities, list_pipe) {
vsp1_entity_route_setup(entity, pipe, pipe->dl);
if (entity->ops->configure)
entity->ops->configure(entity, pipe, pipe->dl,
VSP1_ENTITY_PARAMS_INIT);
}
return 0;
}
static int vsp1_video_start_streaming(struct vb2_queue *vq, unsigned int count)
{
struct vsp1_video *video = vb2_get_drv_priv(vq);
struct vsp1_pipeline *pipe = video->rwpf->pipe;
bool start_pipeline = false;
unsigned long flags;
int ret;
mutex_lock(&pipe->lock);
if (pipe->stream_count == pipe->num_inputs) {
ret = vsp1_video_setup_pipeline(pipe);
if (ret < 0) {
mutex_unlock(&pipe->lock);
return ret;
}
start_pipeline = true;
}
pipe->stream_count++;
mutex_unlock(&pipe->lock);
if (!start_pipeline)
return 0;
spin_lock_irqsave(&pipe->irqlock, flags);
if (vsp1_pipeline_ready(pipe))
vsp1_video_pipeline_run(pipe);
spin_unlock_irqrestore(&pipe->irqlock, flags);
return 0;
}
static void vsp1_video_stop_streaming(struct vb2_queue *vq)
{
struct vsp1_video *video = vb2_get_drv_priv(vq);
struct vsp1_pipeline *pipe = video->rwpf->pipe;
struct vsp1_vb2_buffer *buffer;
unsigned long flags;
int ret;
spin_lock_irqsave(&video->irqlock, flags);
pipe->buffers_ready &= ~(1 << video->pipe_index);
spin_unlock_irqrestore(&video->irqlock, flags);
mutex_lock(&pipe->lock);
if (--pipe->stream_count == pipe->num_inputs) {
ret = vsp1_pipeline_stop(pipe);
if (ret == -ETIMEDOUT)
dev_err(video->vsp1->dev, "pipeline stop timeout\n");
vsp1_dl_list_put(pipe->dl);
pipe->dl = NULL;
}
mutex_unlock(&pipe->lock);
media_pipeline_stop(&video->video.entity);
vsp1_video_pipeline_put(pipe);
spin_lock_irqsave(&video->irqlock, flags);
list_for_each_entry(buffer, &video->irqqueue, queue)
vb2_buffer_done(&buffer->buf.vb2_buf, VB2_BUF_STATE_ERROR);
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
format->fmt.pix_mp = video->rwpf->format;
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
video->rwpf->format = format->fmt.pix_mp;
video->rwpf->fmtinfo = info;
done:
mutex_unlock(&video->lock);
return ret;
}
static int
vsp1_video_streamon(struct file *file, void *fh, enum v4l2_buf_type type)
{
struct v4l2_fh *vfh = file->private_data;
struct vsp1_video *video = to_vsp1_video(vfh->vdev);
struct media_device *mdev = &video->vsp1->media_dev;
struct vsp1_pipeline *pipe;
int ret;
if (video->queue.owner && video->queue.owner != file->private_data)
return -EBUSY;
mutex_lock(&mdev->graph_mutex);
pipe = vsp1_video_pipeline_get(video);
if (IS_ERR(pipe)) {
mutex_unlock(&mdev->graph_mutex);
return PTR_ERR(pipe);
}
ret = __media_pipeline_start(&video->video.entity, &pipe->pipe);
if (ret < 0) {
mutex_unlock(&mdev->graph_mutex);
goto err_pipe;
}
mutex_unlock(&mdev->graph_mutex);
ret = vsp1_video_verify_format(video);
if (ret < 0)
goto err_stop;
ret = vb2_streamon(&video->queue, type);
if (ret < 0)
goto err_stop;
return 0;
err_stop:
media_pipeline_stop(&video->video.entity);
err_pipe:
vsp1_video_pipeline_put(pipe);
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
v4l2_fh_exit(vfh);
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
struct vsp1_video *vsp1_video_create(struct vsp1_device *vsp1,
struct vsp1_rwpf *rwpf)
{
struct vsp1_video *video;
const char *direction;
int ret;
video = devm_kzalloc(vsp1->dev, sizeof(*video), GFP_KERNEL);
if (!video)
return ERR_PTR(-ENOMEM);
rwpf->video = video;
video->vsp1 = vsp1;
video->rwpf = rwpf;
if (rwpf->entity.type == VSP1_ENTITY_RPF) {
direction = "input";
video->type = V4L2_BUF_TYPE_VIDEO_OUTPUT_MPLANE;
video->pad.flags = MEDIA_PAD_FL_SOURCE;
video->video.vfl_dir = VFL_DIR_TX;
} else {
direction = "output";
video->type = V4L2_BUF_TYPE_VIDEO_CAPTURE_MPLANE;
video->pad.flags = MEDIA_PAD_FL_SINK;
video->video.vfl_dir = VFL_DIR_RX;
}
mutex_init(&video->lock);
spin_lock_init(&video->irqlock);
INIT_LIST_HEAD(&video->irqqueue);
ret = media_entity_pads_init(&video->video.entity, 1, &video->pad);
if (ret < 0)
return ERR_PTR(ret);
rwpf->format.pixelformat = VSP1_VIDEO_DEF_FORMAT;
rwpf->format.width = VSP1_VIDEO_DEF_WIDTH;
rwpf->format.height = VSP1_VIDEO_DEF_HEIGHT;
__vsp1_video_try_format(video, &rwpf->format, &rwpf->fmtinfo);
video->video.v4l2_dev = &video->vsp1->v4l2_dev;
video->video.fops = &vsp1_video_fops;
snprintf(video->video.name, sizeof(video->video.name), "%s %s",
rwpf->entity.subdev.name, direction);
video->video.vfl_type = VFL_TYPE_GRABBER;
video->video.release = video_device_release_empty;
video->video.ioctl_ops = &vsp1_video_ioctl_ops;
video_set_drvdata(&video->video, video);
video->queue.type = video->type;
video->queue.io_modes = VB2_MMAP | VB2_USERPTR | VB2_DMABUF;
video->queue.lock = &video->lock;
video->queue.drv_priv = video;
video->queue.buf_struct_size = sizeof(struct vsp1_vb2_buffer);
video->queue.ops = &vsp1_video_queue_qops;
video->queue.mem_ops = &vb2_dma_contig_memops;
video->queue.timestamp_flags = V4L2_BUF_FLAG_TIMESTAMP_COPY;
video->queue.dev = video->vsp1->dev;
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
return video;
error:
vsp1_video_cleanup(video);
return ERR_PTR(ret);
}
void vsp1_video_cleanup(struct vsp1_video *video)
{
if (video_is_registered(&video->video))
video_unregister_device(&video->video);
media_entity_cleanup(&video->video.entity);
}
